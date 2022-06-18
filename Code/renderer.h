// minimalistic code to draw a single triangle, this is not part of the API.
// TODO: Part 1b
#include "shaderc/shaderc.h" // needed for compiling shaders at runtime
#include "../Assets/FSLogo.h"
#include "Level_Data.h"
using namespace H2B;

//test


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
};



StructuredBuffer<SHADER_MODEL_DATA> SceneData;
[[vk::push_constant]]
cbuffer MESH_INDEX{
	uint mesh_ID;
	uint mat_ID;
};
struct VERT_IN{

	float3 pos : POSITION;
	float3 uvw : TEXCOORD;	
	float3 nrm : NORMAL;
	float3 sunAmbient;
	float3 camPos;
	

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

	transformedData = mul(float4(inputVertex.pos,1),SceneData[0].matricies[mesh_ID]);
	transformedData = mul(transformedData,SceneData[0].viewMatrix);
	transformedData = mul(transformedData,SceneData[0].projectionMatrix);

	//return transformedData;

	float4 nrm = float4(inputVertex.nrm,0);
	OUTPUT_TO_RASTERIZER output;

	//OUTPUT.

	output.posH = transformedData;
	output.uvw = inputVertex.uvw;
	output.nrmW = mul(nrm,SceneData[0].matricies[mesh_ID]);
	output.posW = mul(float4(inputVertex.pos,1),SceneData[0].matricies[mesh_ID]);
	//output.sunAmbient
	return output;

		// TODO: Part 4e
	// TODO: Part 4b
		// TODO: Part 4e
}
)";
// Simple Pixel Shader
const char* pixelShaderSource = R"(
// TODO: Part 2b
// TODO: Part 4g
// TODO: Part 2i
// TODO: Part 3e
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
};

struct OUTPUT_TO_RASTERIZER{
	float4 posH : SV_POSITION;
	float3 uvw   : TEXCOORD;	
	float3 nrmW : NORMAL;
	float3 posw : WORLD;

};

StructuredBuffer<SHADER_MODEL_DATA> SceneData;
[[vk::push_constant]]
cbuffer MESH_INDEX{
	uint mesh_ID;
	uint mat_ID;
};

// an ultra simple hlsl pixel shader

float4 main(OUTPUT_TO_RASTERIZER inputVertex) : SV_TARGET 
{	
	//return float4(0.25f ,0.25f, 0.75f, 0); // TODO: Part 1a

	float4 finalColor;

	//inputVertex.nrmW = normalize(inputVertex.nrmW);
	//SceneData[0].sunDirection = normalize(SceneData[0].sunDirection);

	float LIGHTRATIO = saturate(dot( - normalize(SceneData[0].sunDirection), normalize(inputVertex.nrmW)));
	
	float3 SUNSURFACECOLOR,INDIRECT,DIRECT;

	INDIRECT.x = SceneData[0].sunAmbient.x * SceneData[0].materials[mat_ID].Ka.x * SceneData[0].materials[mat_ID].Kd.x ;
	INDIRECT.y = SceneData[0].sunAmbient.y * SceneData[0].materials[mat_ID].Ka.y * SceneData[0].materials[mat_ID].Kd.y ;
	INDIRECT.z = SceneData[0].sunAmbient.z * SceneData[0].materials[mat_ID].Ka.z * SceneData[0].materials[mat_ID].Kd.z ;

	DIRECT.x = LIGHTRATIO * SceneData[0].sunColor.x;
	DIRECT.y = LIGHTRATIO * SceneData[0].sunColor.y;
	DIRECT.z = LIGHTRATIO * SceneData[0].sunColor.z;

	float3 RESULT;
	RESULT.x = saturate((DIRECT + INDIRECT) * SceneData[0].materials[mat_ID].Kd.x);
	RESULT.y = saturate((DIRECT + INDIRECT) * SceneData[0].materials[mat_ID].Kd.y);
	RESULT.z = saturate((DIRECT + INDIRECT) * SceneData[0].materials[mat_ID].Kd.z);

	//return float4(RESULT, 0);


	float3 VIEWDIR = normalize(SceneData[0].camGlobalPos.xyz - inputVertex.posw);
	float3 HALFVECTOR = normalize(-normalize(SceneData[0].sunDirection.xyz) + VIEWDIR);
	float INTENSITY = saturate(pow(dot(HALFVECTOR,normalize(inputVertex.nrmW)),SceneData[0].materials[mat_ID].Ns));
	
	float3 FINAL_RESULT;
	float worldDot = 0;
	worldDot = 1 - saturate(dot(normalize(inputVertex.nrmW),VIEWDIR));

	FINAL_RESULT.x = RESULT.x + INTENSITY * SceneData[0].materials[mat_ID].Ks.x ;
	FINAL_RESULT.y = RESULT.y + INTENSITY * SceneData[0].materials[mat_ID].Ks.y ;
	FINAL_RESULT.z = RESULT.z + INTENSITY * SceneData[0].materials[mat_ID].Ks.z ;
    return saturate(float4(FINAL_RESULT,0)); 

	//FINAL_RESULT.x = RESULT.x + INTENSITY * SceneData[0].materials[mesh_ID].Ks.x + worldDot;
	//FINAL_RESULT.y = RESULT.y + INTENSITY * SceneData[0].materials[mesh_ID].Ks.y + worldDot;
	//FINAL_RESULT.z = RESULT.z + INTENSITY * SceneData[0].materials[mesh_ID].Ks.z + worldDot;
	//return saturate(float4(worldDot,worldDot,worldDot,0)); 

	float3 dirColor;
	dirColor.x = saturate(inputVertex.nrmW.x) ;
	dirColor.y = saturate(inputVertex.nrmW.y) ;
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
	VkDevice device = nullptr;
	VkBuffer vertexHandle = nullptr;
	VkDeviceMemory vertexData = nullptr;
	// TODO: Part 1g
	VkBuffer indexBuffer = nullptr;
	VkDeviceMemory indexData = nullptr;
	// TODO: Part 2c
	VkShaderModule vertexShader = nullptr;
	VkShaderModule pixelShader = nullptr;

	//VkDeviceMemory storageData = nullptr;
	std::vector<VkBuffer> storageBufferVector;
	std::vector<VkDeviceMemory> storageBufferMemory;


	// pipeline settings for drawing (also required)
	VkPipeline pipeline = nullptr;
	VkPipelineLayout pipelineLayout = nullptr;
	// TODO: Part 2e
	VkDescriptorSetLayout descriptorLayout = nullptr; // describes order of connection to shaders
	VkDescriptorPool descriptorPool = nullptr; // used to allocate descriptorSets (required)

	std::vector<VkDescriptorSet> descriptorSet; // not-plural since we need multiple for one resource

	GW::MATH::GMatrix proxy;
	GW::MATH::GMATRIXF world = GW::MATH::GIdentityMatrixF;
	GW::MATH::GMATRIXF view = GW::MATH::GIdentityMatrixF;
	GW::MATH::GMATRIXF projection = GW::MATH::GIdentityMatrixF;
	GW::MATH::GVECTORF camGlabalPos = { .75f,.25f,-1.5f,1 };

	GW::MATH::GVECTORF lightDir = { -1.0f ,-1.0f, 2.0f };
	GW::MATH::GVECTORF lightColor = { 0.95f ,0.9f, 0.9f,1.0f };
	GW::MATH::GVECTORF sunAmbient = { 0.25f ,0.25f, 0.35f,1.0f };

	bool initDone = false;

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
	//Level_Data level;




	SHADER_MODEL_DATA smd = {0};
public:

	void updateCamera() {

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

	}

	Renderer(GW::SYSTEM::GWindow _win, GW::GRAPHICS::GVulkanSurface _vlk)
	{
		//init();

		ld1.Parse();
		//p = ld1.p;
		//objects = ld1.master_objects;

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
		
		proxy.LookAtLHF( camGlabalPos, GW::MATH::GVECTORF{ 0.0f,0.0f,0,1 }, GW::MATH::GVECTORF{ 0,1,0 }, view);

		//view_copy = view;
		proxy.ProjectionVulkanLHF(1.13, aspectRatio, 0.1f, 1000, projection);
		
		GW::I::GVectorInterface::NormalizeF(lightDir,lightDir);


		// TODO: Part 2b
		smd.sunDirection = lightDir;
		smd.sunColor = lightColor;
		smd.viewMatrix = view;
		smd.projectionMatrix = projection;
		//smd.matricies[0] = GW::MATH::GIdentityMatrixF;

		for (int i = 0; i < MAX_SUBMESH_PER_DRAW; i++) {
			smd.matricies[i] = GW::MATH::GIdentityMatrixF;
		}

		for (auto& iter : ld1.LevelDataMap)
		{
			for (int i = 0; i < iter.second.worldMatrices.size(); ++i)
			{
				smd.matricies[iter.second.meshId + i] = iter.second.worldMatrices[i];
			}
		}

		smd.sunAmbient = sunAmbient;
		smd.camGlobalPos = camGlabalPos;
		//smd.materials[0] = p.materials[0].attrib;

		
		for (int i =0; i<ld1.masterMaterials.size();i++)
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

		//smd.materials[0] = FSLogo_materials[0].attrib;
		//smd.materials[1] = FSLogo_materials[1].attrib;
		//smd.materials[2] = FSLogo_materials[0].attrib;
		//smd.materials[3] = FSLogo_materials[0].attrib;



		//smd.materials[0].d = ld1.master_materials[0].attrib.d;
		//smd.materials[0].illum = ld1.master_materials[0].attrib.illum;

		//smd.materials[0].Ka.x = ld1.master_materials[0].attrib.Ka.x;
		//smd.materials[0].Ka.y = ld1.master_materials[0].attrib.Ka.y;
		//smd.materials[0].Ka.z = ld1.master_materials[0].attrib.Ka.z;

		//smd.materials[0].Kd.x = ld1.master_materials[0].attrib.Kd.x;
		//smd.materials[0].Kd.y = ld1.master_materials[0].attrib.Kd.y;
		//smd.materials[0].Kd.z = ld1.master_materials[0].attrib.Kd.z;

		//smd.materials[0].Ke.x = ld1.master_materials[0].attrib.Ke.x;
		//smd.materials[0].Ke.y = ld1.master_materials[0].attrib.Ke.y;
		//smd.materials[0].Ke.z = ld1.master_materials[0].attrib.Ke.z;

		//smd.materials[0].Ks.x = ld1.master_materials[0].attrib.Ks.x;
		//smd.materials[0].Ks.y = ld1.master_materials[0].attrib.Ks.y;
		//smd.materials[0].Ks.z = ld1.master_materials[0].attrib.Ks.z;


		//smd.materials[0].Ni= ld1.master_materials[0].attrib.Ni;
		//smd.materials[0].Ns= ld1.master_materials[0].attrib.Ns;
		//smd.materials[0].sharpness = ld1.master_materials[0].attrib.sharpness;

		//smd.materials[0].Tf.x = ld1.master_materials[0].attrib.Tf.x;
		//smd.materials[0].Tf.y = ld1.master_materials[0].attrib.Tf.y;
		//smd.materials[0].Tf.z = ld1.master_materials[0].attrib.Tf.z;
		////}

		//smd.camGlobalPos = GW::MATH::GIdentityMatrixF;
		/*for (int i = 0; i < MAX_SUBMESH_PER_DRAW; i++) {
			smd.materials[i] = FSLogo_materials[i].attrib;
		}*/



		SHADER_MODEL_DATA smd_copy = smd;


		// TODO: Part 4g
		// TODO: part 3b

		/***************** GEOMETRY INTIALIZATION ******************/
		// Grab the device & physical device so we can allocate some stuff
		VkPhysicalDevice physicalDevice = nullptr;
		vlk.GetDevice((void**)&device);
		vlk.GetPhysicalDevice((void**)&physicalDevice);

		_vlk.GetAspectRatio(AspectRatio);


		
		// TODO: Part 1c
		// Create Vertex Buffer
		float verts[] = {
			   0,   0.5f,
			 0.5f, -0.5f,
			-0.5f, -0.5f
		};
		// Transfer triangle data to the vertex buffer. (staging would be prefered here)
		GvkHelper::create_buffer(physicalDevice, device, ld1.masterVertices.size() *3* sizeof(float) * 3,//VECTOR = 3 (FLOATS ) * 3 (POS , UVW, NRM) 
			VK_BUFFER_USAGE_VERTEX_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | 
			VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, &vertexHandle, &vertexData);
		GvkHelper::write_to_buffer(device, vertexData, &(ld1.masterVertices[0]), ld1.masterVertices.size() * 3 * sizeof(float) * 3);

 		GvkHelper::create_buffer(physicalDevice, device, ld1.masterIndices.size() * sizeof(int),
			VK_BUFFER_USAGE_INDEX_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
			VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, &indexBuffer, &indexData);
		GvkHelper::write_to_buffer(device, indexData, &ld1.masterIndices[0], ld1.masterIndices.size() * sizeof(int));

		unsigned int frameCount = 0;
		vlk.GetSwapchainImageCount(frameCount);
		storageBufferVector.resize(frameCount);
		storageBufferMemory.resize(frameCount);


		for (int i = 0; i < frameCount; i++) {
			GvkHelper::create_buffer(physicalDevice, device, sizeof(smd_copy),
				VK_BUFFER_USAGE_STORAGE_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
				VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, &storageBufferVector[i], &storageBufferMemory[i]);
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
		VkViewport viewport = {
            0, 0, static_cast<float>(width), static_cast<float>(height), 0, 1
        };
        VkRect2D scissor = { {0, 0}, {width, height} };
		VkPipelineViewportStateCreateInfo viewport_create_info = {};
		viewport_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
		viewport_create_info.viewportCount = 1;
		viewport_create_info.pViewports = &viewport;
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
		// TODO: Part 2e
		pipeline_layout_create_info.setLayoutCount = 1;




		VkDescriptorSetLayoutBinding vk_descriptor_set_layout_binding;
		vk_descriptor_set_layout_binding.descriptorCount = 1;
		vk_descriptor_set_layout_binding.descriptorType = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
		vk_descriptor_set_layout_binding.stageFlags = VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT;
		vk_descriptor_set_layout_binding.pImmutableSamplers = nullptr;
		vk_descriptor_set_layout_binding.binding= 0;

		VkDescriptorSetLayoutCreateInfo Vk_descriptor_set_layout_create_info;
		Vk_descriptor_set_layout_create_info.bindingCount = 1;
		Vk_descriptor_set_layout_create_info.pBindings = &vk_descriptor_set_layout_binding;
		Vk_descriptor_set_layout_create_info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
		Vk_descriptor_set_layout_create_info.pNext = nullptr;
		Vk_descriptor_set_layout_create_info.flags = 0;

		VkResult r = vkCreateDescriptorSetLayout(device, &Vk_descriptor_set_layout_create_info,
			nullptr, &descriptorLayout);

		pipeline_layout_create_info.pSetLayouts = &descriptorLayout;

		VkDescriptorPoolCreateInfo descriptorpool_create_info = {};
		VkDescriptorPoolSize descriptorpool_size = { VK_DESCRIPTOR_TYPE_STORAGE_BUFFER, frameCount };
		descriptorpool_create_info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
		descriptorpool_create_info.poolSizeCount = 1;
		descriptorpool_create_info.pPoolSizes = &descriptorpool_size;
		descriptorpool_create_info.maxSets = frameCount;
		descriptorpool_create_info.flags = 0;
		descriptorpool_create_info.pNext = nullptr;
		vkCreateDescriptorPool(device, &descriptorpool_create_info, nullptr, &descriptorPool);

		VkDescriptorSetAllocateInfo descriptorset_allocate_info = {};
		descriptorset_allocate_info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
		descriptorset_allocate_info.descriptorSetCount = 1;
		descriptorset_allocate_info.pSetLayouts = &descriptorLayout;
		descriptorset_allocate_info.descriptorPool = descriptorPool;
		descriptorset_allocate_info.pNext = nullptr;
		descriptorSet.resize(frameCount);
		for (int i = 0; i < frameCount; ++i) {
			vkAllocateDescriptorSets(device, &descriptorset_allocate_info, &descriptorSet[i]);
		}

		VkWriteDescriptorSet write_descriptorset = {};
		write_descriptorset.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
		write_descriptorset.descriptorCount = 1;
		write_descriptorset.dstArrayElement = 0;
		write_descriptorset.dstBinding = 0;
		write_descriptorset.descriptorType = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
		for (int i = 0; i < frameCount; ++i) {
			write_descriptorset.dstSet = descriptorSet[i];
			VkDescriptorBufferInfo dbinfo = { storageBufferVector[i], 0, VK_WHOLE_SIZE };
			write_descriptorset.pBufferInfo = &dbinfo;
			vkUpdateDescriptorSets(device, 1, &write_descriptorset, 0, nullptr);
		}

		// TODO: Part 3c
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
	void Render()
	{
		// TODO: Part 2a
		//proxy.RotateYGlobalF(world, 0.0174533f/10, world);
		//worldRot+=0.0001;
		// TODO: Part 4d
		// grab the current Vulkan commandBuffer
		unsigned int currentBuffer;
		vlk.GetSwapchainCurrentImage(currentBuffer);
		VkCommandBuffer commandBuffer;
		vlk.GetCommandBuffer(currentBuffer, (void**)&commandBuffer);
		// what is the current client area dimensions?
		unsigned int width, height;
		win.GetClientWidth(width);
		win.GetClientHeight(height);
		// setup the pipeline's dynamic settings
		VkViewport viewport = {
            0, 0, static_cast<float>(width), static_cast<float>(height), 0, 1
        };
        VkRect2D scissor = { {0, 0}, {width, height} };
		vkCmdSetViewport(commandBuffer, 0, 1, &viewport);
		vkCmdSetScissor(commandBuffer, 0, 1, &scissor);
		vkCmdBindPipeline(commandBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS, pipeline);
		
		// now we can draw
		VkDeviceSize offsets[] = { 0 };
		vkCmdBindVertexBuffers(commandBuffer, 0, 1, &vertexHandle, offsets);
		vkCmdBindIndexBuffer(commandBuffer, indexBuffer, 0, VK_INDEX_TYPE_UINT32);
		unsigned int frameCount = 0;
		vlk.GetSwapchainImageCount(frameCount);
		//smd.matricies[1] = world;
		SHADER_MODEL_DATA smd_copy = smd;
		
		for (int i = 0; i < frameCount; i++) {
			GvkHelper::write_to_buffer(device, storageBufferMemory[i], &smd_copy, sizeof(smd_copy));
		vkCmdBindDescriptorSets(commandBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS,
			pipelineLayout, 0, 1, &descriptorSet[i], 0, nullptr);
		}

		unsigned int meshIndex = 0;
		unsigned int InstanceCount = 0;
		GvkHelper::write_to_buffer(device, storageBufferMemory[currentBuffer], &smd, sizeof(SHADER_MODEL_DATA));
		for (auto iter : ld1.LevelDataMap)
		{
			for (auto submesh : iter.second.parser.meshes)
			{
				int pushValues[] = { iter.second.meshId ,iter.second.materialId };
 				vkCmdPushConstants(commandBuffer, pipelineLayout, VK_SHADER_STAGE_VERTEX_BIT|VK_SHADER_STAGE_FRAGMENT_BIT, 0, 8, pushValues);
				vkCmdDrawIndexed(commandBuffer, submesh.drawInfo.indexCount, iter.second.instanceCount, submesh.drawInfo.indexOffset, iter.second.vertexOffset, 0);
				InstanceCount += iter.second.instanceCount;
				
			}
		}
		
	}
	
private:
	void CleanUp()
	{
		// wait till everything has completed
		vkDeviceWaitIdle(device);
		// Release allocated buffers, shaders & pipeline
		// TODO: Part 1g
		// TODO: Part 2d
		vkDestroyBuffer(device, vertexHandle, nullptr);
		vkFreeMemory(device, vertexData, nullptr);
		vkDestroyBuffer(device, indexBuffer, nullptr);
		vkFreeMemory(device, indexData, nullptr);



		for (int i = 0; i < storageBufferVector.size(); i++) {
			vkDestroyBuffer(device, storageBufferVector[i], nullptr);
			vkFreeMemory(device, storageBufferMemory[i], nullptr);

		}


		vkDestroyShaderModule(device, vertexShader, nullptr);
		vkDestroyShaderModule(device, pixelShader, nullptr);
		// TODO: Part 2e
		vkDestroyDescriptorSetLayout(device, descriptorLayout, nullptr);

		// TODO: part 2f
		vkDestroyDescriptorPool(device, descriptorPool, nullptr);
		vkDestroyPipelineLayout(device, pipelineLayout, nullptr);
		vkDestroyPipeline(device, pipeline, nullptr);
	}
};