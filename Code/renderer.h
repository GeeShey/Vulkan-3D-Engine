#define GATEWARE_ENABLE_CORE // All libraries need this
#define GATEWARE_ENABLE_SYSTEM // Graphics libs require system level libraries
#define GATEWARE_ENABLE_GRAPHICS // Enables all Graphics Libraries
#define GATEWARE_ENABLE_MATH
#define GATEWARE_ENABLE_INPUT
#define KHRONOS_STATIC 

#include "shaderc/shaderc.h" // needed for compiling shaders at runtime
#include "../Assets/FSLogo.h"
#include "Level_Data.h"
#include "DialogHelper.h"

#include <ktxvulkan.h>

using namespace H2B;

#ifdef _WIN32 // must use MT platform DLL libraries on windows
	#pragma comment(lib, "shaderc_combined.lib") 
#endif
// Simple Vertex Shader

const char* vertexShaderSource = R"(
// TODO: 2i
#pragma pack_matrix(row_major)
// an ultra simple hlsl vertex shader
// TODO: Part 2b
struct OBJ_ATTRIBUTES
{
	float3    Kd; // diffuse reflectivity
	float	    d; // dissolve (transparency) 
	float3    Ks; // specular reflectivity
	float       Ns; // specular exponent
	float3    Ka; // ambient reflectivity
	float       sharpness; // local reflection map sharpness
	float3    Tf; // transmission filter
	float       Ni; // optical density (index of refraction)
	float3    Ke; // emissive reflectivity
	uint    illum; // illumination model
};

struct SHADER_MODEL_DATA
{
	float4 sunDirection, sunColor,sunAmbient,camGlobalPos;
	matrix viewMatrix, projectionMatrix;

	matrix matricies[1024];
	OBJ_ATTRIBUTES materials[1024];
	int filter_id;
};



StructuredBuffer<SHADER_MODEL_DATA> SceneData : register(b0);
[[vk::push_constant]]
cbuffer MESH_INDEX{
	uint mesh_ID;
	int mat_ID_uniform;
};
struct VERT_IN{

	float3 pos : POSITION;
	float3 uvw : TEXCOORD;	
	float3 nrm : NORMAL;
	float3 sunAmbient;
	float3 camPos;
	uint instance_id : SV_InstanceID;
	

};
//struct VERT_OUT{
//
//	float4 pos	: SV_POSITION;
//	float3 uv   : TEXCOORD;	
//	float3 nrm  : NORMAL;	
//	
//
//};

struct OUTPUT_TO_RASTERIZER{
	float4 posH : SV_POSITION;
	float3 uvw   : TEXCOORD;	
	float3 nrmW : NORMAL;
	float3 posW : WORLD;
	float3 sunAmbient;
	float3 camPos;
	

};
OUTPUT_TO_RASTERIZER main(VERT_IN inputVertex)
{
	//return float4(inputVertex.pos.x,inputVertex.pos.y-0.75f,inputVertex.pos.z +0.75f,1.0f);
	float4 transformedData;
	//inputVertex.pos.y-=0.75f;
	//inputVertex.pos.z +=0.75f;
	//transformedData.w = 1;

	transformedData = mul(float4(inputVertex.pos,1),SceneData[0].matricies[mesh_ID + inputVertex.instance_id]);
	transformedData = mul(transformedData,SceneData[0].viewMatrix);
	transformedData = mul(transformedData,SceneData[0].projectionMatrix);

	//return transformedData;

	float4 nrm = float4(inputVertex.nrm,0);
	OUTPUT_TO_RASTERIZER output;

	//OUTPUT.

	output.posH = transformedData;
	output.uvw = inputVertex.uvw;
	output.nrmW = mul(nrm,SceneData[0].matricies[mesh_ID  + inputVertex.instance_id]);
	output.posW = mul(float4(inputVertex.pos,1),SceneData[0].matricies[mesh_ID  + inputVertex.instance_id]);
	//output.sunAmbient
	return output;

}
)";
// Simple Pixel Shader
const char* pixelShaderSource = R"(
//[[vk::binding(1, 1)]]
Texture2D Map[] : register(t1);
//[[vk::binding(1, 1)]]
SamplerState qualityFilter : register(s1);
struct OBJ_ATTRIBUTES
{
    float3 Kd; // diffuse reflectivity
    float d; // dissolve (transparency) 
    float3 Ks; // specular reflectivity
    float Ns; // specular exponent
    float3 Ka; // ambient reflectivity
    float sharpness; // local reflection map sharpness
    float3 Tf; // transmission filter
    float Ni; // optical density (index of refraction)
    float3 Ke; // emissive reflectivity
    uint illum; // illumination model
};

struct SHADER_MODEL_DATA
{
    float4 sunDirection, sunColor, sunAmbient, camGlobalPos;
    matrix viewMatrix, projectionMatrix;

    matrix matricies[1024];
    OBJ_ATTRIBUTES materials[1024];
    int filter_id;

};

struct OUTPUT_TO_RASTERIZER
{
    float4 posH : SV_POSITION;
    float3 uvw : TEXCOORD;
    float3 nrmW : NORMAL;
    float3 posw : WORLD;

};

StructuredBuffer<SHADER_MODEL_DATA> SceneData : register(b0);
[[vk::push_constant]]
cbuffer MESH_INDEX
{
    uint mesh_ID;
    int mat_ID_uniform;
};

// an ultra simple hlsl pixel shader
float3x3 cotangent_frame(float3 N, float3 p, float2 uv)
{
	// get edge vec­tors of the pix­el tri­an­gle
    float3 dp1 = ddx(p);
    float3 dp2 = ddy(p);
    float2 duv1 = ddx(uv);
    float2 duv2 = ddy(uv);

	// solve the lin­ear sys­tem
    float3 dp2perp = cross(dp2, N);
    float3 dp1perp = cross(N, dp1);
    float3 T = dp2perp * duv1.x + dp1perp * duv2.x;
    float3 B = dp2perp * duv1.y + dp1perp * duv2.y;

	// con­struct a scale-invari­ant frame 

	 
    float invmax = rsqrt(max(dot(T, T), dot(B, B)));

    return float3x3(T * invmax, B * invmax, N);
};

float3 perturb_normal(float3 N, float3 V, float2 texcoord, float3 NRM_texColor)
{
    float3 map = NRM_texColor;
		map = map * 255.0f/127.0f - 128.0f/127.0f;
		//map.z = sqrt( 1.0f -  dot( map.xy, map.xy ) );
		map.y = -map.y;
    float3x3 TBN = cotangent_frame(N, -V, texcoord);
    return normalize(mul(map,TBN));
}



float4 main(OUTPUT_TO_RASTERIZER inputVertex) : SV_TARGET
{
	int mat_ID = 0;
	int isTextured = 0;
	if(mat_ID_uniform < 0){
		isTextured = 0;
		mat_ID =-1 * mat_ID_uniform;
	}
	else{
		mat_ID = mat_ID_uniform;	
		isTextured = 1;
		//return float4(1,1,1,1);
	}
	int textureIndex = mat_ID * 3;

	float3 diff =  SceneData[0].materials[mat_ID].Kd;
    float3 spec =  SceneData[0].materials[mat_ID].Ks;
    float3 nrm  =  inputVertex.nrmW;

	if(isTextured == 1){

		diff = Map[ textureIndex    ].Sample(qualityFilter, inputVertex.uvw.xy);
		nrm  = Map[ textureIndex + 1].Sample(qualityFilter, inputVertex.uvw.xy);
		spec = Map[ textureIndex + 2].Sample(qualityFilter, inputVertex.uvw.xy);
		//return float4(spec,0);
	}

	//return nrm;
    float4 finalColor;

	//inputVertex.nrmW = normalize(inputVertex.nrmW);
	//SceneData[0].sunDirection = normalize(SceneData[0].sunDirection);
    float3 VIEWDIR = normalize(SceneData[0].camGlobalPos.xyz - inputVertex.posw);

    float3 N = normalize(inputVertex.nrmW);
    N = perturb_normal(N, VIEWDIR, inputVertex.uvw.xy, nrm.xyz);

	if(isTextured==0)
	{
		N = nrm;
	}

    float LIGHTRATIO = saturate(dot(-normalize(SceneData[0].sunDirection), normalize(N)));
	
    float3 SUNSURFACECOLOR, INDIRECT, DIRECT;

    INDIRECT.y = SceneData[0].sunAmbient.y * diff.x;
    INDIRECT.z = SceneData[0].sunAmbient.z * diff.y;
    INDIRECT.x = SceneData[0].sunAmbient.x * diff.z;

    DIRECT.x = LIGHTRATIO * SceneData[0].sunColor.x;
    DIRECT.y = LIGHTRATIO * SceneData[0].sunColor.y;
    DIRECT.z = LIGHTRATIO * SceneData[0].sunColor.z;

    float3 RESULT = saturate((DIRECT + INDIRECT) * diff.xyz);
	//if(isTextured==0)
	//{
	//	return float4(RESULT,0);
	//}

	//return float4(RESULT, diff.a);

    float3 FINAL_RESULT;
    float3 HALFVECTOR = normalize(-normalize(SceneData[0].sunDirection.xyz) + VIEWDIR);
    //float INTENSITY = saturate(pow(dot(HALFVECTOR, normalize(N)), spec));
    float INTENSITY = saturate(pow(dot(HALFVECTOR, normalize(N)), SceneData[0].materials[mat_ID].Ns));


    FINAL_RESULT = RESULT + INTENSITY * spec.x;
    return saturate(float4(FINAL_RESULT, 0));

	

	//float4 normal = normalize( normalTex.rgb * 2.0 - 1.0 );

	
    float worldDot = 0;
    worldDot = 1 - saturate(dot(normalize(inputVertex.nrmW), VIEWDIR));

	//FINAL_RESULT.x = RESULT.x + INTENSITY * SceneData[0].materials[mesh_ID].Ks.x + worldDot;
	//FINAL_RESULT.y = RESULT.y + INTENSITY * SceneData[0].materials[mesh_ID].Ks.y + worldDot;
	//FINAL_RESULT.z = RESULT.z + INTENSITY * SceneData[0].materials[mesh_ID].Ks.z + worldDot;
	//return saturate(float4(worldDot,worldDot,worldDot,0)); 

    float3 dirColor;
    dirColor.x = saturate(inputVertex.nrmW.x);
    dirColor.y = saturate(inputVertex.nrmW.y);
    dirColor.z = saturate(-inputVertex.nrmW.z);

	//float vignette = saturate(dot(normalize(inputVertex.posw),VIEWDIR)) * 10;
	//float3 vignetteColor = {0.5f * vignette,0.8f * vignette,0.5f * vignette};
	//
    //return saturate(float4(vignetteColor,0)); 

}
)";

// Creation, Rendering & Cleanup
#define MAX_SUBMESH_PER_DRAW 1024

class Renderer
{


	struct OBJ_VERT
	{
		OBJ_VEC3 pos; // Left-handed +Z forward coordinate w not provided, assumed to be 1.
		OBJ_VEC3 uvw; // D3D/Vulkan style top left 0,0 coordinate.
		OBJ_VEC3 nrm; // Provided direct from obj file, may or may not be normalized.
	};
	// TODO: Part 2b
	struct SHADER_MODEL_DATA
	{
		GW::MATH::GVECTORF sunDirection, sunColor,sunAmbient, camGlobalPos;
		GW::MATH::GMATRIXF viewMatrix, projectionMatrix;

		GW::MATH::GMATRIXF matricies[MAX_SUBMESH_PER_DRAW];
		OBJ_ATTRIBUTES materials[MAX_SUBMESH_PER_DRAW];
		unsigned int filter_id = 0;
	};

	struct Model {
		
		std::string name;
		GW::MATH::GMATRIXF worldMatrix;

	};

	// proxy handles
	GW::SYSTEM::GWindow win;
	GW::GRAPHICS::GVulkanSurface vlk;
	GW::CORE::GEventReceiver shutdown;
	
	// what we need at a minimum to draw a triangle
 // not-plural since we need multiple for one resource

	// pipeline settings for drawing (also required)
	VkPipeline pipeline = nullptr;
	VkPipelineLayout pipelineLayout = nullptr;
	// TODO: Part 2e
	VkDescriptorSetLayout vertexDescriptorLayout = nullptr; // describes order of connection to shaders

	GW::MATH::GMatrix proxy;
	GW::MATH::GMATRIXF world = GW::MATH::GIdentityMatrixF;
	GW::MATH::GMATRIXF view = GW::MATH::GIdentityMatrixF;
	GW::MATH::GMATRIXF projection = GW::MATH::GIdentityMatrixF;
	GW::MATH::GVECTORF camGlabalPos = { .75f,.25f,-1.5f,1 };

	//GW::MATH::GVECTORF lightDir = { -1.0f ,-1.0f, 2.0f };
	//GW::MATH::GVECTORF lightDir = {0.0f ,-1.0f,- 1.0f };
	// EARTH PREVIEW
	//GW::MATH::GVECTORF lightDir = { 1.0f ,-1.0f, 1.0f };
	//CHURCH PREVIEW
	GW::MATH::GVECTORF lightDir = { -0.1f ,-0.1f, -1.0f };



	GW::MATH::GVECTORF lightColor = { 0.95f ,0.9f, 0.9f,1.0f };
	GW::MATH::GVECTORF sunAmbient = { 0.25f ,0.25f, 0.35f,1.0f };

	//bool initDone = false;

	float worldRot = 0,aspectRatio = 0;


	GW::MATH::GMATRIXF  world2, world3, world4, world5, world6;
	std::chrono::steady_clock::time_point lastCall;
	GW::MATH::GMATRIXF regularCamera = GW::MATH::GIdentityMatrixF;
	GW::MATH::GMATRIXF view_copy = GW::MATH::GIdentityMatrixF;

	float AspectRatio = 0;//defined later
	int Height = 0, Width = 0;

	GW::INPUT::GController controllerProxy;
	GW::INPUT::GInput inputProxy;

	int FOV = 100;

	std::string GameLevel_filepath = "GameLevel.txt";
	
	Parser p;
	Level_Data ld1;
	unsigned int levelSelected = 1;
	bool BufferUpdateNeeded = false;
	bool init = false;

	float N,M,Num1,Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9;

	GW::SYSTEM::GWindow win_main;
	GW::GRAPHICS::GVulkanSurface vlk_main;

	std::vector<std::string> gamelevels;
	float f1;
	SHADER_MODEL_DATA smd = {0};
	std::vector < std::string> textureFiles;

	int multiplier = 1;
	bool debug = false;

	bool viewPortEnabled = false;

	/***************** KTX+VULKAN TEXTURING VARIABLES ******************/

// what we need at minimum to load/apply one texture
	//ktxVulkanTexture texture; // one per texture
	//VkImageView textureView = nullptr; // one per texture
	VkSampler textureSampler = nullptr; // can be shared, effects quality & addressing mode
	// note that unlike uniform buffers, we don't need one for each "in-flight" frame

	// be aware that all pipeline shaders share the same bind points
	VkDescriptorSetLayout pixelDescriptorLayout = nullptr;
	// textures can optionally share descriptor sets/pools/layouts with uniform & storage buffers	
	VkDescriptorPool descriptorPool = nullptr;
	VkDevice device = nullptr;
	VkBuffer vertexHandle = nullptr;
	VkDeviceMemory vertexData = nullptr;
	// TODO: Part 1g
	VkBuffer indexBuffer = nullptr;
	VkDeviceMemory indexData = nullptr;
	// TODO: Part 2c
	VkShaderModule vertexShader = nullptr;
	VkShaderModule pixelShader = nullptr;

	std::vector<VkBuffer> matrixBuffer;
	std::vector<VkDeviceMemory> storageBufferMemory;
	std::vector<VkDescriptorSet> matrixDescriptorSet;
	std::vector < ktxVulkanTexture> tex;
	std::vector < VkImageView> tex_view;
	//std::vector < GW::MATH::GVECTORF> lightDirs = { 
	//	{ 1.0f ,-1.0f, 1.0f },
	//	{ 1.0f ,-1.0f, 1.0f },
	//	{ 1.0f ,-1.0f, 1.0f },
	//	{ 1.0f ,-1.0f, 1.0f },
	//	{ 1.0f ,-1.0f, 1.0f },
	//	{ 1.0f ,-1.0f, 1.0f },
	//	{ 1.0f ,-1.0f, 1.0f },
	//	{ 0.0f ,-1.0f, -1.0f },
	//	{ 1.0f ,-1.0f, 1.0f },
	//	{ 1.0f ,-1.0f, 1.0f },
	//	{ 1.0f ,-1.0f, 1.0f }
	//};

	
	std::string defaultLvlPath = "../../Assets/Levels/L";
	//3 church
	//4 demo
	//5 earth debug = true
	//6 materials
	//7 cartoon
	//8 normal test debug = true

	// pipeline settings for drawing (also required)
public:
	bool LoadTexture(std::string texturePath, ktxVulkanTexture& texture, VkImageView& textureView)
	{
		// Gateware, access to underlying Vulkan queue and command pool & physical device
		VkQueue graphicsQueue;
		VkCommandPool cmdPool;
		VkPhysicalDevice physicalDevice;
		vlk.GetGraphicsQueue((void**)&graphicsQueue);
		vlk.GetCommandPool((void**)&cmdPool);
		vlk.GetPhysicalDevice((void**)&physicalDevice);
		// libktx, temporary variables
		ktxTexture* kTexture;
		KTX_error_code ktxresult;
		ktxVulkanDeviceInfo vdi;
		// used to transfer texture CPU memory to GPU. just need one
		ktxresult = ktxVulkanDeviceInfo_Construct(&vdi, physicalDevice, device,
			graphicsQueue, cmdPool, nullptr);
		if (ktxresult != KTX_error_code::KTX_SUCCESS)
			return false;
		// load texture into CPU memory from file
		ktxresult = ktxTexture_CreateFromNamedFile(texturePath.c_str(),
			KTX_TEXTURE_CREATE_NO_FLAGS, &kTexture);
		if (ktxresult != KTX_error_code::KTX_SUCCESS)
			return false;
		// This gets mad if you don't encode/save the .ktx file in a format Vulkan likes
		ktxresult = ktxTexture_VkUploadEx(kTexture, &vdi, &texture,
			VK_IMAGE_TILING_OPTIMAL,
			VK_IMAGE_USAGE_SAMPLED_BIT,
			VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL);
		if (ktxresult != KTX_error_code::KTX_SUCCESS)
			return false;
		// after loading all textures you don't need these anymore
		ktxTexture_Destroy(kTexture);
		ktxVulkanDeviceInfo_Destruct(&vdi);

		// Create image view.
		// Textures are not directly accessed by the shaders and are abstracted
		// by image views containing additional information and sub resource ranges.
		VkImageViewCreateInfo viewInfo = {};
		// Set the non-default values.
		viewInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
		viewInfo.flags = 0;
		viewInfo.components = {
			VK_COMPONENT_SWIZZLE_R, VK_COMPONENT_SWIZZLE_G,//HEH? TODO
			VK_COMPONENT_SWIZZLE_B, VK_COMPONENT_SWIZZLE_A
		};
		viewInfo.image = texture.image;
		viewInfo.format = texture.imageFormat;
		viewInfo.viewType = texture.viewType;
		viewInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
		viewInfo.subresourceRange.layerCount = texture.layerCount;
		viewInfo.subresourceRange.levelCount = texture.levelCount;
		viewInfo.subresourceRange.baseMipLevel = 0;
		viewInfo.subresourceRange.baseArrayLayer = 0;
		viewInfo.pNext = nullptr;
		VkResult vr = vkCreateImageView(device, &viewInfo, nullptr, &textureView);


		if (vr != VkResult::VK_SUCCESS)
			return false;

		return true;
	}
	void f1_pressed() {
		DialogHelper dh;
		std::string temp_gamelevels = dh.displayOpenFileDialogue();
		size_t lastindex = temp_gamelevels.find_last_of("\\");
		temp_gamelevels = temp_gamelevels.substr(0, lastindex);
		temp_gamelevels = temp_gamelevels.append("\\");
		gamelevels.push_back(temp_gamelevels);
		int x = 2;

	}
	void updateCamera() {

		//lightDir = 
		std::chrono::steady_clock::time_point currCall = std::chrono::steady_clock::now();
		float elapse = std::chrono::duration_cast<std::chrono::microseconds>(currCall - lastCall).count() / 1000000.0f;

		float space = 0, shift = 0, LT = 0, RT = 0, W, A, S, D, L3_X = 0, L3_Y = 0, R3_X = 0, R3_Y = 0, MOUSE_X = 0, MOUSE_Y = 0;

		proxy.InverseF(view, regularCamera);
		GW::GReturn s;

		inputProxy.GetState(G_KEY_SPACE, space);
		inputProxy.GetState(G_KEY_LEFTSHIFT, shift);
		controllerProxy.GetState(0, G_LEFT_TRIGGER_AXIS, LT);
		controllerProxy.GetState(0, G_RIGHT_TRIGGER_AXIS, RT);
		s = inputProxy.GetState(G_KEY_W, W);

		inputProxy.GetState(G_KEY_A, A);
		inputProxy.GetState(G_KEY_S, S);
		inputProxy.GetState(G_KEY_D, D);
		inputProxy.GetState(G_KEY_N, N);
		inputProxy.GetState(G_KEY_M, M);


		inputProxy.GetState(G_KEY_1, Num1);
		inputProxy.GetState(G_KEY_2, Num2);
		inputProxy.GetState(G_KEY_3, Num3);
		inputProxy.GetState(G_KEY_4, Num4);
		inputProxy.GetState(G_KEY_5, Num5);
		inputProxy.GetState(G_KEY_6, Num6);
		inputProxy.GetState(G_KEY_7, Num7);
		inputProxy.GetState(G_KEY_8, Num8);
		inputProxy.GetState(G_KEY_9, Num9);

		inputProxy.GetState(G_KEY_F1, f1);
		if (f1 > 0.0f) {
			f1_pressed();
		}

		if (M > 0.0f) {
			viewPortEnabled = !viewPortEnabled;
		}


		controllerProxy.GetState(0, G_LX_AXIS, L3_X);
		controllerProxy.GetState(0, G_LY_AXIS, L3_Y);
		controllerProxy.GetState(0, G_RX_AXIS, R3_X);
		//inputProxy.GetState(G_RY_AXIS, R3_Y);
		controllerProxy.GetState(0, G_RY_AXIS, R3_Y);

		if (G_PASS(s) && W!= 0) {
			int debug = 0;
		}
		GW::GReturn result = inputProxy.GetMouseDelta(MOUSE_X, MOUSE_Y);


		bool movementEnabled = false;
		if (space || shift || LT || RT || W || A || S || D || L3_X || L3_Y || R3_X || R3_Y) {
			movementEnabled = true;
		}

		GW::MATH::GVECTORF schmovement;
		schmovement.x = 0;
		schmovement.y = (space - shift + RT - LT) * (elapse);
		schmovement.z = 0;
		schmovement.w = 1;

		//proxy.InverseF(regularCamera, regularCamera);

		proxy.TranslateGlobalF(regularCamera, schmovement, regularCamera);

		schmovement.x = (D - A + L3_X) * (elapse );
		schmovement.y = 0;
		schmovement.z = (W - S + L3_Y) * (elapse );
		schmovement.w = 1;

		proxy.TranslateLocalF(regularCamera, schmovement, regularCamera);


		GW::MATH::GMATRIXF projMatrix = GW::MATH::GIdentityMatrixF, temp = GW::MATH::GIdentityMatrixF, pitchMatrix = GW::MATH::GIdentityMatrixF, yawMatrix = GW::MATH::GIdentityMatrixF, rotMatrix = GW::MATH::GIdentityMatrixF;
		proxy.ProjectionVulkanLHF(1.0f, AspectRatio, 0.1f, FOV, projMatrix);

		float Thumb_Speed = 0;
		float Total_Pitch = 0;
		float Total_Yaw = 0;
		Thumb_Speed = 3.141 * elapse;


		if (result != GW::GReturn::REDUNDANT)
		{
			// do cool stuff
			Total_Pitch = FOV * MOUSE_Y * 0.025 / Height;
			Total_Yaw = FOV * AspectRatio * MOUSE_X * 0.025 / Width;
		}

		Total_Pitch += R3_Y * -Thumb_Speed;
		Total_Yaw += R3_X * Thumb_Speed;


		proxy.RotateXGlobalF(pitchMatrix, Total_Pitch, pitchMatrix);
		proxy.MultiplyMatrixF(pitchMatrix, regularCamera, regularCamera);


		proxy.RotateYGlobalF(yawMatrix, Total_Yaw, yawMatrix);

		GW::MATH::GVECTORF regularCamera_copy = regularCamera.row4;
		regularCamera.row4 = GW::MATH::GVECTORF{ 0,0,0,0 };

		proxy.MultiplyMatrixF(regularCamera, yawMatrix, regularCamera);

		regularCamera.row4 = regularCamera_copy;

		//proxy.MultiplyMatrixF(regularCamera, projMatrix, temp);

		proxy.InverseF(regularCamera, view);



		lastCall = std::chrono::steady_clock::now();
		smd.viewMatrix = view;
		smd.camGlobalPos = regularCamera_copy;

	}

	void checkInput() {

		//std::cout << "N value " << N << "\n";
		int oldLevel = levelSelected;


		if (Num1 > 0.0f) {
			if (levelSelected == 1) {
				BufferUpdateNeeded = false;
			}
			else {
				levelSelected = 1;
				BufferUpdateNeeded = true;
			}
		}
		else if (Num2 > 0.0f) {
			if (levelSelected == 2) {
				BufferUpdateNeeded = false;
			}
			else {
				levelSelected = 2;
				BufferUpdateNeeded = true;
			}
		}
		else if (Num3 > 0.0f) {
			if (levelSelected == 3) {
				BufferUpdateNeeded = false;
			}
			else {
				levelSelected = 3;
				BufferUpdateNeeded = true;
			}
		}
		else if (Num4 > 0.0f) {
			if (levelSelected == 4) {
				BufferUpdateNeeded = false;
			}
			else {
				levelSelected = 4;
				BufferUpdateNeeded = true;
			}
		}
		else if (Num5 > 0.0f) {
			if (levelSelected == 5) {
				BufferUpdateNeeded = false;
			}
			else {
				levelSelected = 5;
				BufferUpdateNeeded = true;
			}
		}
		else if (Num6 > 0.0f) {
			if (levelSelected == 6) {
				BufferUpdateNeeded = false;
			}
			else {
				levelSelected = 6;
				BufferUpdateNeeded = true;
			}
		}
		else if (Num7 > 0.0f) {
			if (levelSelected == 7) {
				BufferUpdateNeeded = false;
			}
			else {
				levelSelected = 7;
				BufferUpdateNeeded = true;
			}
		}
		else if (Num8 > 0.0f) {
			if (levelSelected == 8) {
				BufferUpdateNeeded = false;
			}
			else {
				levelSelected = 8;
				BufferUpdateNeeded = true;
			}
		}
		else if (Num9 > 0.0f) {
			if (levelSelected == 9) {
				BufferUpdateNeeded = false;
			}
			else {
				levelSelected = 9;
				BufferUpdateNeeded = true;
			}
		}

		if (levelSelected > gamelevels.size()) {
			std::cout << "\nNot enough levels stored\n";
			levelSelected = oldLevel;
			BufferUpdateNeeded = false;
			return;
		}

	}
	void initer(GW::SYSTEM::GWindow _win, GW::GRAPHICS::GVulkanSurface _vlk) {
		//init();	

		textureFiles.clear();
		if (!init) {
			gamelevels.push_back(defaultLvlPath);
			ld1.Parse(gamelevels[0]);

		}

		win = _win;
		vlk = _vlk;

		controllerProxy.Create();
		inputProxy.Create(win);

		unsigned int width, height;
		win.GetClientWidth(width);
		win.GetClientHeight(height);
		Height = height;
		Width = width;

		_vlk.GetAspectRatio(aspectRatio);
		proxy.Create();
		// TODO: Part 2a

		if(!init)
		proxy.LookAtLHF(camGlabalPos, GW::MATH::GVECTORF{ 0.0f,0.0f,0,1 }, GW::MATH::GVECTORF{ 0,1,0 }, view);

		//view_copy = view;
		proxy.ProjectionVulkanLHF(1.13, aspectRatio, 0.1f, 1000, projection);

		GW::I::GVectorInterface::NormalizeF(lightDir, lightDir);


		smd.sunDirection = lightDir;
		smd.sunColor = lightColor;
		smd.viewMatrix = view;
		smd.projectionMatrix = projection;
		//smd.matricies[0] = GW::MATH::GIdentityMatrixF;

		for (int i = 0; i < MAX_SUBMESH_PER_DRAW; i++) {
			smd.matricies[i] = GW::MATH::GIdentityMatrixF;
		}
		for (int i = 0; i < MAX_SUBMESH_PER_DRAW; i++) {
			smd.materials[i] = {0};
		}

		int temp_top = 0;
		for (auto& iter : ld1.LevelDataMap)
		{
			iter.second.meshId = temp_top;//NEED TO FIX BUG
			for (int k = 0; k < iter.second.worldMatrices.size(); ++k)
			{
				smd.matricies[k] = iter.second.worldMatrices[k];
				temp_top++;
			}
		}

		smd.sunAmbient = sunAmbient;
		smd.camGlobalPos = camGlabalPos;
		//smd.materials[0] = p.materials[0].attrib;


		for (int i = 0; i < ld1.masterMaterials.size(); i++)
		{

			smd.materials[i].d = ld1.masterMaterials[i].attrib.d;
			smd.materials[i].illum = ld1.masterMaterials[i].attrib.illum;
			smd.materials[i].Ka.x = ld1.masterMaterials[i].attrib.Ka.x;
			smd.materials[i].Ka.y = ld1.masterMaterials[i].attrib.Ka.y;
			smd.materials[i].Ka.z = ld1.masterMaterials[i].attrib.Ka.z;
			smd.materials[i].Kd.x = ld1.masterMaterials[i].attrib.Kd.x;
			smd.materials[i].Kd.y = ld1.masterMaterials[i].attrib.Kd.y;
			smd.materials[i].Kd.z = ld1.masterMaterials[i].attrib.Kd.z;
			smd.materials[i].Ke.x = ld1.masterMaterials[i].attrib.Ke.x;
			smd.materials[i].Ke.y = ld1.masterMaterials[i].attrib.Ke.y;
			smd.materials[i].Ke.z = ld1.masterMaterials[i].attrib.Ke.z;
			smd.materials[i].Ks.x = ld1.masterMaterials[i].attrib.Ks.x;
			smd.materials[i].Ks.y = ld1.masterMaterials[i].attrib.Ks.y;
			smd.materials[i].Ks.z = ld1.masterMaterials[i].attrib.Ks.z;
			smd.materials[i].Ni = ld1.masterMaterials[i].attrib.Ni;
			smd.materials[i].Ns = ld1.masterMaterials[i].attrib.Ns;
			smd.materials[i].sharpness = ld1.masterMaterials[i].attrib.sharpness;
			smd.materials[i].Tf.x = ld1.masterMaterials[i].attrib.Tf.x;
			smd.materials[i].Tf.y = ld1.masterMaterials[i].attrib.Tf.y;
			smd.materials[i].Tf.z = ld1.masterMaterials[i].attrib.Tf.z;


		}

		SHADER_MODEL_DATA smd_copy = smd;

		/***************** GEOMETRY INTIALIZATION ******************/
		// Grab the device & physical device so we can allocate some stuff
		VkPhysicalDevice physicalDevice = nullptr;
		vlk.GetDevice((void**)&device);
		vlk.GetPhysicalDevice((void**)&physicalDevice);

		_vlk.GetAspectRatio(AspectRatio);
		// Transfer triangle data to the vertex buffer. (staging would be prefered here)
		GvkHelper::create_buffer(physicalDevice, device, ld1.masterVertices.size() * 3 * sizeof(float) * 3,//VECTOR = 3 (FLOATS ) * 3 (POS , UVW, NRM) 
			VK_BUFFER_USAGE_VERTEX_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
			VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, &vertexHandle, &vertexData);
		GvkHelper::write_to_buffer(device, vertexData, &(ld1.masterVertices[0]), ld1.masterVertices.size() * 3 * sizeof(float) * 3);

		GvkHelper::create_buffer(physicalDevice, device, ld1.masterIndices.size() * sizeof(int),
			VK_BUFFER_USAGE_INDEX_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
			VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, &indexBuffer, &indexData);
		GvkHelper::write_to_buffer(device, indexData, &ld1.masterIndices[0], ld1.masterIndices.size() * sizeof(int));

		unsigned int frameCount = 0;
		vlk.GetSwapchainImageCount(frameCount);
		matrixBuffer.resize(frameCount);
		storageBufferMemory.resize(frameCount);


		for (int i = 0; i < frameCount; i++) {
			GvkHelper::create_buffer(physicalDevice, device, sizeof(smd_copy),
				VK_BUFFER_USAGE_STORAGE_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
				VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, &matrixBuffer[i], &storageBufferMemory[i]);
			GvkHelper::write_to_buffer(device, storageBufferMemory[i], &smd_copy, sizeof(smd_copy));
		}

		/***************** SHADER INTIALIZATION ******************/
		// Intialize runtime shader compiler HLSL -> SPIRV
		shaderc_compiler_t compiler = shaderc_compiler_initialize();
		shaderc_compile_options_t options = shaderc_compile_options_initialize();
		shaderc_compile_options_set_source_language(options, shaderc_source_language_hlsl);
		shaderc_compile_options_set_invert_y(options, false); // TODO: Part 2i
#ifndef NDEBUG
		shaderc_compile_options_set_generate_debug_info(options);
#endif
		// Create Vertex Shader
		shaderc_compilation_result_t result = shaderc_compile_into_spv( // compile
			compiler, vertexShaderSource, strlen(vertexShaderSource),
			shaderc_vertex_shader, "main.vert", "main", options);
		if (shaderc_result_get_compilation_status(result) != shaderc_compilation_status_success) // errors?
			std::cout << "Vertex Shader Errors: " << shaderc_result_get_error_message(result) << std::endl;
		GvkHelper::create_shader_module(device, shaderc_result_get_length(result), // load into Vulkan
			(char*)shaderc_result_get_bytes(result), &vertexShader);
		shaderc_result_release(result); // done
		// Create Pixel Shader
		result = shaderc_compile_into_spv( // compile
			compiler, pixelShaderSource, strlen(pixelShaderSource),
			shaderc_fragment_shader, "main.frag", "main", options);
		if (shaderc_result_get_compilation_status(result) != shaderc_compilation_status_success) // errors?
			std::cout << "Pixel Shader Errors: " << shaderc_result_get_error_message(result) << std::endl;
		GvkHelper::create_shader_module(device, shaderc_result_get_length(result), // load into Vulkan
			(char*)shaderc_result_get_bytes(result), &pixelShader);
		shaderc_result_release(result); // done
		// Free runtime shader compiler resources
		shaderc_compile_options_release(options);
		shaderc_compiler_release(compiler);

		/***************** PIPELINE INTIALIZATION ******************/
		// Create Pipeline & Layout (Thanks Tiny!)
		VkRenderPass renderPass;
		vlk.GetRenderPass((void**)&renderPass);
		VkPipelineShaderStageCreateInfo stage_create_info[2] = {};
		// Create Stage Info for Vertex Shader
		stage_create_info[0].sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
		stage_create_info[0].stage = VK_SHADER_STAGE_VERTEX_BIT;
		stage_create_info[0].module = vertexShader;
		stage_create_info[0].pName = "main";
		// Create Stage Info for Fragment Shader
		stage_create_info[1].sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
		stage_create_info[1].stage = VK_SHADER_STAGE_FRAGMENT_BIT;
		stage_create_info[1].module = pixelShader;
		stage_create_info[1].pName = "main";
		// Assembly State
		VkPipelineInputAssemblyStateCreateInfo assembly_create_info = {};
		assembly_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
		assembly_create_info.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
		assembly_create_info.primitiveRestartEnable = false;

		// Vertex Input State
		VkVertexInputBindingDescription vertex_binding_description = {};
		vertex_binding_description.binding = 0;
		vertex_binding_description.stride = sizeof(OBJ_VERT);
		vertex_binding_description.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;
		VkVertexInputAttributeDescription vertex_attribute_description[3] = {
			{ 0, 0, VK_FORMAT_R32G32B32_SFLOAT, offsetof(OBJ_VERT, pos) }, //uv, normal, etc....
			{ 1, 0, VK_FORMAT_R32G32B32_SFLOAT, offsetof(OBJ_VERT, uvw) }, //uv, normal, etc....
			{ 2, 0, VK_FORMAT_R32G32B32_SFLOAT, offsetof(OBJ_VERT, nrm) } //uv, normal, etc....

		};
		VkPipelineVertexInputStateCreateInfo input_vertex_info = {};
		input_vertex_info.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
		input_vertex_info.vertexBindingDescriptionCount = 1;
		input_vertex_info.pVertexBindingDescriptions = &vertex_binding_description;
		input_vertex_info.vertexAttributeDescriptionCount = 3;
		input_vertex_info.pVertexAttributeDescriptions = vertex_attribute_description;
		// Viewport State (we still need to set this up even though we will overwrite the values)

		float viewPortW = static_cast<float>(width);
		float viewPortH = static_cast<float>(height);

		if (viewPortEnabled) {
			viewPortH /= 2;
		}


		VkViewport viewport[2];
		viewport[0] = {
			0, viewPortH, viewPortW, static_cast<float>(height), 0, 1
		};

		viewport[1] = {
			0, 0, static_cast<float>(width), static_cast<float>(height), 0, 1
		};
		VkRect2D scissor = { {0, 0}, {width, height} };
		VkPipelineViewportStateCreateInfo viewport_create_info = {};
		viewport_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
		viewport_create_info.viewportCount = 1;
		viewport_create_info.pViewports = viewport;
		viewport_create_info.scissorCount = 1;
		viewport_create_info.pScissors = &scissor;
		// Rasterizer State
		VkPipelineRasterizationStateCreateInfo rasterization_create_info = {};
		rasterization_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
		rasterization_create_info.rasterizerDiscardEnable = VK_FALSE;
		rasterization_create_info.polygonMode = VK_POLYGON_MODE_FILL;
		rasterization_create_info.lineWidth = 1.0f;
		rasterization_create_info.cullMode = VK_CULL_MODE_BACK_BIT;
		rasterization_create_info.frontFace = VK_FRONT_FACE_CLOCKWISE;
		rasterization_create_info.depthClampEnable = VK_FALSE;
		rasterization_create_info.depthBiasEnable = VK_FALSE;
		rasterization_create_info.depthBiasClamp = 0.0f;
		rasterization_create_info.depthBiasConstantFactor = 0.0f;
		rasterization_create_info.depthBiasSlopeFactor = 0.0f;
		// Multisampling State
		VkPipelineMultisampleStateCreateInfo multisample_create_info = {};
		multisample_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
		multisample_create_info.sampleShadingEnable = VK_FALSE;
		multisample_create_info.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;
		multisample_create_info.minSampleShading = 1.0f;
		multisample_create_info.pSampleMask = VK_NULL_HANDLE;
		multisample_create_info.alphaToCoverageEnable = VK_FALSE;
		multisample_create_info.alphaToOneEnable = VK_FALSE;
		// Depth-Stencil State
		VkPipelineDepthStencilStateCreateInfo depth_stencil_create_info = {};
		depth_stencil_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
		depth_stencil_create_info.depthTestEnable = VK_TRUE;
		depth_stencil_create_info.depthWriteEnable = VK_TRUE;
		depth_stencil_create_info.depthCompareOp = VK_COMPARE_OP_LESS;
		depth_stencil_create_info.depthBoundsTestEnable = VK_FALSE;
		depth_stencil_create_info.minDepthBounds = 0.0f;
		depth_stencil_create_info.maxDepthBounds = 1.0f;
		depth_stencil_create_info.stencilTestEnable = VK_FALSE;
		// Color Blending Attachment & State
		VkPipelineColorBlendAttachmentState color_blend_attachment_state = {};
		color_blend_attachment_state.colorWriteMask = 0xF;
		color_blend_attachment_state.blendEnable = VK_FALSE;
		color_blend_attachment_state.srcColorBlendFactor = VK_BLEND_FACTOR_SRC_COLOR;
		color_blend_attachment_state.dstColorBlendFactor = VK_BLEND_FACTOR_DST_COLOR;
		color_blend_attachment_state.colorBlendOp = VK_BLEND_OP_ADD;
		color_blend_attachment_state.srcAlphaBlendFactor = VK_BLEND_FACTOR_SRC_ALPHA;
		color_blend_attachment_state.dstAlphaBlendFactor = VK_BLEND_FACTOR_DST_ALPHA;
		color_blend_attachment_state.alphaBlendOp = VK_BLEND_OP_ADD;
		VkPipelineColorBlendStateCreateInfo color_blend_create_info = {};
		color_blend_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
		color_blend_create_info.logicOpEnable = VK_FALSE;
		color_blend_create_info.logicOp = VK_LOGIC_OP_COPY;
		color_blend_create_info.attachmentCount = 1;
		color_blend_create_info.pAttachments = &color_blend_attachment_state;
		color_blend_create_info.blendConstants[0] = 0.0f;
		color_blend_create_info.blendConstants[1] = 0.0f;
		color_blend_create_info.blendConstants[2] = 0.0f;
		color_blend_create_info.blendConstants[3] = 0.0f;
		// Dynamic State 
		VkDynamicState dynamic_state[2] = {
			// By setting these we do not need to re-create the pipeline on Resize
			VK_DYNAMIC_STATE_VIEWPORT, VK_DYNAMIC_STATE_SCISSOR
		};
		VkPipelineDynamicStateCreateInfo dynamic_create_info = {};
		dynamic_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
		dynamic_create_info.dynamicStateCount = 2;
		dynamic_create_info.pDynamicStates = dynamic_state;


		// Descriptor pipeline layout
		VkPipelineLayoutCreateInfo pipeline_layout_create_info = {};
		pipeline_layout_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
		pipeline_layout_create_info.setLayoutCount = 1;
		VkDescriptorSetLayoutBinding vk_descriptor_set_layout_binding[2];
		vk_descriptor_set_layout_binding[0].descriptorCount = 1;
		vk_descriptor_set_layout_binding[0].descriptorType = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
		vk_descriptor_set_layout_binding[0].stageFlags = VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT;
		vk_descriptor_set_layout_binding[0].pImmutableSamplers = nullptr;
		vk_descriptor_set_layout_binding[0].binding = 0;

		vk_descriptor_set_layout_binding[1].descriptorCount = 500;
		vk_descriptor_set_layout_binding[1].descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
		vk_descriptor_set_layout_binding[1].stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT;
		vk_descriptor_set_layout_binding[1].pImmutableSamplers = nullptr;
		vk_descriptor_set_layout_binding[1].binding = 1;

		VkDescriptorSetLayoutCreateInfo Vk_descriptor_set_layout_create_info;
		Vk_descriptor_set_layout_create_info.bindingCount = ARRAYSIZE(vk_descriptor_set_layout_binding);
		Vk_descriptor_set_layout_create_info.pBindings = vk_descriptor_set_layout_binding;
		Vk_descriptor_set_layout_create_info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
		Vk_descriptor_set_layout_create_info.pNext = nullptr;
		Vk_descriptor_set_layout_create_info.flags = 0;

		VkResult r = vkCreateDescriptorSetLayout(device, &Vk_descriptor_set_layout_create_info,
			nullptr, &vertexDescriptorLayout);

		pipeline_layout_create_info.pSetLayouts = &vertexDescriptorLayout;
		

		VkDescriptorPoolCreateInfo descriptorpool_create_info = {};
		VkDescriptorPoolSize descriptorpool_size[] = {
			{VK_DESCRIPTOR_TYPE_STORAGE_BUFFER, frameCount},
			{VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, 500 * frameCount} };
		descriptorpool_create_info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
		descriptorpool_create_info.poolSizeCount = ARRAYSIZE(descriptorpool_size);
		descriptorpool_create_info.pPoolSizes = descriptorpool_size;
		descriptorpool_create_info.maxSets = 1002;
		descriptorpool_create_info.flags = 0;
		descriptorpool_create_info.pNext = nullptr;
		vkCreateDescriptorPool(device, &descriptorpool_create_info, nullptr, &descriptorPool);

		VkDescriptorSetAllocateInfo descriptorset_allocate_info = {};
		descriptorset_allocate_info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
		descriptorset_allocate_info.descriptorSetCount = 1;
		descriptorset_allocate_info.pSetLayouts = &vertexDescriptorLayout;
		descriptorset_allocate_info.descriptorPool = descriptorPool;
		descriptorset_allocate_info.pNext = nullptr;
		matrixDescriptorSet.resize(frameCount);

		VkSamplerCreateInfo samplerInfo = {};
		// Set the struct values
		samplerInfo.sType = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
		samplerInfo.flags = 0;
		samplerInfo.addressModeU = VK_SAMPLER_ADDRESS_MODE_REPEAT; // REPEAT IS COMMON
		samplerInfo.addressModeV = VK_SAMPLER_ADDRESS_MODE_REPEAT;
		samplerInfo.addressModeW = VK_SAMPLER_ADDRESS_MODE_REPEAT;
		samplerInfo.magFilter = VK_FILTER_LINEAR;
		samplerInfo.minFilter = VK_FILTER_LINEAR;
		samplerInfo.mipmapMode = VK_SAMPLER_MIPMAP_MODE_LINEAR;
		samplerInfo.mipLodBias = 0;
		samplerInfo.minLod = 0;
		samplerInfo.maxLod = 1;
		samplerInfo.anisotropyEnable = VK_FALSE;
		samplerInfo.maxAnisotropy = 1.0;
		samplerInfo.borderColor = VK_BORDER_COLOR_FLOAT_OPAQUE_WHITE;
		samplerInfo.compareEnable = VK_FALSE;
		samplerInfo.compareOp = VK_COMPARE_OP_LESS;
		samplerInfo.unnormalizedCoordinates = VK_FALSE;
		samplerInfo.pNext = nullptr;
		VkResult vr = vkCreateSampler(device, &samplerInfo, nullptr, &textureSampler);

		//ktxVulkanTexture tex[500];
		//VkImageView tex_view[500];

		for (int i = 0; i < frameCount; ++i) {
			vkAllocateDescriptorSets(device, &descriptorset_allocate_info, &matrixDescriptorSet[i]);
			VkWriteDescriptorSet write_descriptorset = {};
			write_descriptorset.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
			write_descriptorset.descriptorCount = 1;
			write_descriptorset.dstArrayElement = 0;
			write_descriptorset.dstBinding = 0;
			write_descriptorset.descriptorType = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
			write_descriptorset.dstSet = matrixDescriptorSet[i];
			VkDescriptorBufferInfo dbinfo = { matrixBuffer[i], 0, VK_WHOLE_SIZE };
			write_descriptorset.pBufferInfo = &dbinfo;
			vkUpdateDescriptorSets(device, 1, &write_descriptorset, 0, nullptr);

			VkWriteDescriptorSet write_descriptorset_tex[500] = {};
			


			for (int i = 0; i < ld1.masterMaterials.size(); i++) {

				H2B::MATERIAL mat = ld1.masterMaterials[i];
				std::vector < std::string> mat_textures;
				std::string nuul = "NULL";
				ld1.getTexturesFromMaterial(mat, mat_textures);
				for (int j = 0; j < 3; j++) {
					/*if (mat_textures[j] == "NULL") {
						mat_textures[j] = "../../Assets/Levels/default_diff.ktx";
					}
					else {
						int debug = 0;
					}*/
					textureFiles.push_back(mat_textures[j]);
				}
			}
			//for (auto iter : ld1.LevelDataMap)
			//{
			//	for (auto submesh : iter.second.parser.meshes)
			//	{
			//		extureFiles.push_back(iter.second.materialId
			//		/*textureFiles.push_back("../../Assets/Levels/L5/earthmap1k.ktx");
			//		textureFiles.push_back("../../Assets/Levels/L5/earthspec1k.ktx");
			//		textureFiles.push_back("../../Assets/Levels/L5/earthnrm1k.ktx");
			//	*/
			//	}
			//}

			

			VkDescriptorImageInfo vdii[500] = {};
			ktxVulkanTexture tempTex[500];
			VkImageView tempView[500];
			
			for (size_t j = 0; j < 500; j++)
			{
				bool texParseSuccessful = false;
				std::string textureToBeParsed;

				//DEBUG

				/*if (j == 4) {
					textureToBeParsed = "../../Assets/Levels/L8/TestNormalMap.ktx";
				}
				else {

					if (j < textureFiles.size()) {
						textureToBeParsed = textureFiles[j].c_str();

					}
					else {
						textureToBeParsed = textureFiles[0].c_str();
					}
				}*/

				if (j < textureFiles.size()) {
					textureToBeParsed = textureFiles[j].c_str();

				}
				else {
					textureToBeParsed = textureFiles[0].c_str();
				}


				texParseSuccessful = LoadTexture(textureToBeParsed, tempTex[j], tempView[j]);

				if (!texParseSuccessful) {
					std::cout << "unable to parse " << textureToBeParsed << "\n";

				}
				
				
				tex.push_back(tempTex[j]);
				tex_view.push_back(tempView[j]);

				vdii[j].imageLayout = tempTex[j].imageLayout;
				vdii[j].imageView = tempView[j];
				vdii[j].sampler = textureSampler;
				//write_descriptorset.dstSet = matrixDescriptorSet[i];
				write_descriptorset_tex[j].pBufferInfo = nullptr;
				write_descriptorset_tex[j].pImageInfo = &vdii[j];
				write_descriptorset_tex[j].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
				write_descriptorset_tex[j].descriptorCount = 1;
				write_descriptorset_tex[j].dstArrayElement = j;
				write_descriptorset_tex[j].dstBinding = 1;
				write_descriptorset_tex[j].descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
				write_descriptorset_tex[j].dstSet = matrixDescriptorSet[i];

				

			}
		
			vkUpdateDescriptorSets(device, 500, write_descriptorset_tex, 0, nullptr);
		}



		pipeline_layout_create_info.pushConstantRangeCount = 1;
		VkPushConstantRange push_constant_range_1;
		push_constant_range_1.stageFlags = VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT;
		push_constant_range_1.size = 8;//only passing mesh_id and mat_id
		push_constant_range_1.offset = 0;


		pipeline_layout_create_info.pPushConstantRanges = &push_constant_range_1;
		vkCreatePipelineLayout(device, &pipeline_layout_create_info,
			nullptr, &pipelineLayout);
		// Pipeline State... (FINALLY) 
		VkGraphicsPipelineCreateInfo pipeline_create_info = {};
		pipeline_create_info.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
		pipeline_create_info.stageCount = 2;
		pipeline_create_info.pStages = stage_create_info;
		pipeline_create_info.pInputAssemblyState = &assembly_create_info;
		pipeline_create_info.pVertexInputState = &input_vertex_info;
		pipeline_create_info.pViewportState = &viewport_create_info;
		pipeline_create_info.pRasterizationState = &rasterization_create_info;
		pipeline_create_info.pMultisampleState = &multisample_create_info;
		pipeline_create_info.pDepthStencilState = &depth_stencil_create_info;
		pipeline_create_info.pColorBlendState = &color_blend_create_info;
		pipeline_create_info.pDynamicState = &dynamic_create_info;
		pipeline_create_info.layout = pipelineLayout;
		pipeline_create_info.renderPass = renderPass;
		pipeline_create_info.subpass = 0;
		pipeline_create_info.basePipelineHandle = VK_NULL_HANDLE;
		vkCreateGraphicsPipelines(device, VK_NULL_HANDLE, 1,
			&pipeline_create_info, nullptr, &pipeline);

		

		/***************** CLEANUP / SHUTDOWN ******************/
		// GVulkanSurface will inform us when to release any allocated resources
		shutdown.Create(vlk, [&]() {
			if (+shutdown.Find(GW::GRAPHICS::GVulkanSurface::Events::RELEASE_RESOURCES, true)) {
				CleanUp(); // unlike D3D we must be careful about destroy timing
			}
			});
	}
	Renderer(GW::SYSTEM::GWindow _win, GW::GRAPHICS::GVulkanSurface _vlk)
	{
		
		//f1_pressed();
		win_main = _win;
		vlk_main = _vlk;

		std::cout << "Enter Scene Number to load: \n";
		std::cout << "\n3. church( diff + spec + nrm)";
		std::cout << "\n4. cartoon scene(flat shaded)";
		std::cout << "\n5. globe spinning( diff + spec + nrm)";
		std::cout << "\n6. materials flexibility( diff + spec + nrm)";
		std::cout << "\n7. cartoon scene(difff)";
		std::cout << "\n8. normal map test(nrm)\n";

		//4\n demo
		//5\n earth debug = true
		//6\n materials
		//7\n cartoon
		//8\n normal test debug = true
		int x;
		std::cin >> x;

		if (x == 5 || x == 8) {
			debug = true;

		}

		
		std::string temp = std::to_string(x).append("/");
		defaultLvlPath.append(temp);

		initer(win_main, vlk_main);
		init = true;
		
	}

	
	void Render()
	{

		checkInput();

		if (BufferUpdateNeeded) {

			CleanUp();
			Level_Data temp;
			debug = false;
			temp.Parse(gamelevels[levelSelected - 1]);
			ld1 = temp;
			initer(win_main, vlk_main);


			BufferUpdateNeeded = false;
		}

		unsigned int currentBuffer;
		vlk.GetSwapchainCurrentImage(currentBuffer);
		VkCommandBuffer commandBuffer;
		vlk.GetCommandBuffer(currentBuffer, (void**)&commandBuffer);
		// what is the current client area dimensions?
		unsigned int width, height;
		win.GetClientWidth(width);
		win.GetClientHeight(height);
		// setup the pipeline's dynamic settings
		VkViewport viewport[2];

		float viewPortW = static_cast<float>(width);
		float viewPortH = static_cast<float>(height);

		if (viewPortEnabled) {
			viewPortH /= 2;
		}

		viewport[0] = {
			0, 0, viewPortW, viewPortH, 0, 1
		};
		viewport[1] = {
			0, static_cast<float>(height / 2), static_cast<float>(width), static_cast<float>(height / 2), 0, 1
		};
		VkRect2D scissor = { {0, 0}, {width, height} };
		vkCmdSetViewport(commandBuffer, 0, 1, &viewport[0]);
		vkCmdSetScissor(commandBuffer, 0, 1, &scissor);
		vkCmdBindPipeline(commandBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS, pipeline);

		// now we can draw
		VkDeviceSize offsets[] = { 0 };
		vkCmdBindVertexBuffers(commandBuffer, 0, 1, &vertexHandle, offsets);
		vkCmdBindIndexBuffer(commandBuffer, indexBuffer, 0, VK_INDEX_TYPE_UINT32);
		unsigned int frameCount = 0;
		vlk.GetSwapchainImageCount(frameCount);
		//proxy.RotateXGlobalF(world, 0.0003f , world);

		if (debug)
			proxy.RotateYGlobalF(world, 0.0003f, world);
		//proxy.RotateYGlobalF(lightDir, 0.0003f, lightDir);

		/*float deltaForce = 0.001f;
		if (lightDir.x <= -1.0f) {
			multiplier = 1;

		}
		if (lightDir.x >= 1.0f) {
			multiplier = -1;

		}

		lightDir.x += deltaForce * multiplier;*/



		smd.matricies[0] = world;
		SHADER_MODEL_DATA smd_copy = smd;

		//for (int i = 0; i < frameCount; i++) {
		GvkHelper::write_to_buffer(device, storageBufferMemory[currentBuffer], &smd_copy, sizeof(smd_copy));
		vkCmdBindDescriptorSets(commandBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS,
			pipelineLayout, 0, 1, &matrixDescriptorSet[currentBuffer], 0, nullptr);
		//}

		/***************** BINDING OF TEXTURE DESCRIPTOR SET TO PIXEL SHADER ******************/

		//// *NEW* Set the matrixDescriptorSet that contains our texture
		//vkCmdBindDescriptorSets(commandBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS,
		//	pipelineLayout, 0, 1, &descriptorSet_tex, 0, nullptr);

		//GvkHelper::write_to_buffer(device, storageBufferMemory[currentBuffer], &smd, sizeof(SHADER_MODEL_DATA));
		for (auto iter : ld1.LevelDataMap)
		{
			for (auto submesh : iter.second.parser.meshes)
			{

				int pushValues[] = { iter.second.meshId ,iter.second.materialId };
				vkCmdPushConstants(commandBuffer, pipelineLayout, VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT, 0, 8, pushValues);
				vkCmdDrawIndexed(commandBuffer, submesh.drawInfo.indexCount, iter.second.instanceCount, submesh.drawInfo.indexOffset, iter.second.vertexOffset, 0);

			}
		}

		if (viewPortEnabled) {
		//VIEWPORT STUFF
			scissor = { {0, 0}, {width, height} };
			vkCmdSetViewport(commandBuffer, 0, 1, &viewport[1]);
			vkCmdSetScissor(commandBuffer, 0, 1, &scissor);
			vkCmdBindPipeline(commandBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS, pipeline);

			// now we can draw
			//offsets[] = { 0 };
			vkCmdBindVertexBuffers(commandBuffer, 0, 1, &vertexHandle, offsets);
			vkCmdBindIndexBuffer(commandBuffer, indexBuffer, 0, VK_INDEX_TYPE_UINT32);
			frameCount = 0;
			vlk.GetSwapchainImageCount(frameCount);
			for (auto iter : ld1.LevelDataMap)
			{
				for (auto submesh : iter.second.parser.meshes)
				{

					int pushValues[] = { iter.second.meshId ,iter.second.materialId };
					vkCmdPushConstants(commandBuffer, pipelineLayout, VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT, 0, 8, pushValues);
					vkCmdDrawIndexed(commandBuffer, submesh.drawInfo.indexCount, iter.second.instanceCount, submesh.drawInfo.indexOffset, iter.second.vertexOffset, 0);

				}
			}
		}
		
	}
	
private:
	void CleanUp()
	{

		vkDeviceWaitIdle(device);
		// When done using the image in Vulkan...
		//ktxVulkanTexture_Destruct(&texture, device, nullptr);
		//if (textureView) {
		//	vkDestroyImageView(device, textureView, nullptr);
		//	textureView = nullptr;
		//}
		if (textureSampler) {
			vkDestroySampler(device, textureSampler, nullptr);
			textureSampler = nullptr;
		}
		// don't need the descriptors anymore
		vkDestroyDescriptorSetLayout(device, vertexDescriptorLayout, nullptr);
		vkDestroyDescriptorSetLayout(device, pixelDescriptorLayout, nullptr);

		// wait till everything has completed
		vkDeviceWaitIdle(device);
		// Release allocated buffers, shaders & pipeline

		vkDestroyBuffer(device, vertexHandle, nullptr);
		vkFreeMemory(device, vertexData, nullptr);
		vkDestroyBuffer(device, indexBuffer, nullptr);
		vkFreeMemory(device, indexData, nullptr);
		for (int i = 0; i < tex.size(); i++) {
			ktxVulkanTexture_Destruct(&tex[i],device,nullptr);
		}
		for (int i = 0; i < tex_view.size(); i++) {
			if (tex_view[i]) {
				vkDestroyImageView(device, tex_view[i], nullptr);
			}
		}


		for (int i = 0; i < matrixBuffer.size(); i++) {
			vkDestroyBuffer(device, matrixBuffer[i], nullptr);
			vkFreeMemory(device, storageBufferMemory[i], nullptr);

		}
		vkDestroyShaderModule(device, vertexShader, nullptr);
		vkDestroyShaderModule(device, pixelShader, nullptr);
		vkDestroyDescriptorPool(device, descriptorPool, nullptr);
		vkDestroyPipelineLayout(device, pipelineLayout, nullptr);
		vkDestroyPipeline(device, pipeline, nullptr);
	}
};
