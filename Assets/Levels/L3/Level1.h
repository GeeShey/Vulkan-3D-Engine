// "Level1.h" generated by "Obj2Header.exe" [Version 1.9d] Author: L.Norri Fullsail University.
// Data is converted to left-handed coordinate system and UV data is V flipped for Direct3D/Vulkan.
// The companion file "Level1.h2b" is a binary dump of this format(-padding) for more flexibility.
// Loading *.h2b: read version, sizes, handle strings(max len 260) by reading until null-terminated.
/***********************/
/*  Generator version  */
/***********************/
#ifndef _Level1_version_
const char Level1_version[4] = { '0','1','9','d' };
#define _Level1_version_
#endif
/************************************************/
/*  This section contains the model's size data */
/************************************************/
#ifndef _Level1_vertexcount_
const unsigned Level1_vertexcount = 76;
#define _Level1_vertexcount_
#endif
#ifndef _Level1_indexcount_
const unsigned Level1_indexcount = 204;
#define _Level1_indexcount_
#endif
#ifndef _Level1_materialcount_
const unsigned Level1_materialcount = 1; // can be used for batched draws
#define _Level1_materialcount_
#endif
#ifndef _Level1_meshcount_
const unsigned Level1_meshcount = 1;
#define _Level1_meshcount_
#endif
/************************************************/
/*  This section contains the raw data to load  */
/************************************************/
#ifndef __OBJ_VEC3__
typedef struct _OBJ_VEC3_
{
	float x,y,z; // 3D Coordinate.
}OBJ_VEC3;
#define __OBJ_VEC3__
#endif
#ifndef __OBJ_VERT__
typedef struct _OBJ_VERT_
{
	OBJ_VEC3 pos; // Left-handed +Z forward coordinate w not provided, assumed to be 1.
	OBJ_VEC3 uvw; // D3D/Vulkan style top left 0,0 coordinate.
	OBJ_VEC3 nrm; // Provided direct from obj file, may or may not be normalized.
}OBJ_VERT;
#define __OBJ_VERT__
#endif
#ifndef _Level1_vertices_
// Raw Vertex Data follows: Positions, Texture Coordinates and Normals.
const OBJ_VERT Level1_vertices[76] =
{
	{	{ 0.293285f, 0.070371f, -0.365676f },	{ 0.743588f, 0.440552f, 0.000000f },	{ -1.000000f, 0.000000f, 0.000000f }	},
	{	{ 0.293285f, 0.055873f, -0.365676f },	{ 0.743588f, 0.479368f, 0.000000f },	{ -1.000000f, 0.000000f, 0.000000f }	},
	{	{ 0.293286f, 0.055873f, -0.055264f },	{ -0.087502f, 0.479367f, 0.000000f },	{ -1.000000f, 0.000000f, 0.000000f }	},
	{	{ 0.469874f, 0.070371f, -0.055264f },	{ -0.087502f, 1.102399f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.469874f, 0.055873f, -0.055264f },	{ -0.087502f, 1.063583f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.469873f, 0.055873f, -0.365677f },	{ 0.743586f, 1.063584f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.381579f, -0.053171f, -0.365676f },	{ 0.148894f, 0.440241f, 0.000000f },	{ -0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.381579f, -0.022793f, -0.365676f },	{ 0.148894f, 0.358908f, 0.000000f },	{ -0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.469873f, -0.022793f, -0.365677f },	{ 0.385291f, 0.358908f, 0.000000f },	{ -0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.293285f, -0.022793f, -0.365676f },	{ 0.743588f, 0.689986f, 0.000000f },	{ -1.000000f, 0.000000f, 0.000000f }	},
	{	{ 0.293285f, -0.053171f, -0.365676f },	{ 0.743588f, 0.771320f, 0.000000f },	{ -1.000000f, 0.000000f, 0.000000f }	},
	{	{ 0.293286f, -0.053171f, -0.055264f },	{ -0.087502f, 0.771319f, 0.000000f },	{ -1.000000f, 0.000000f, 0.000000f }	},
	{	{ 0.469874f, -0.022793f, -0.055264f },	{ -0.087502f, 0.852965f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.469874f, -0.053171f, -0.055264f },	{ -0.087502f, 0.771631f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.469873f, -0.053171f, -0.365677f },	{ 0.743587f, 0.771632f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.381579f, 0.055873f, -0.365676f },	{ 0.148894f, 0.148289f, 0.000000f },	{ -0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.469873f, 0.055873f, -0.365677f },	{ 0.385291f, 0.148289f, 0.000000f },	{ -0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.293286f, -0.022793f, -0.055264f },	{ -0.087502f, 0.689985f, 0.000000f },	{ -1.000000f, 0.000000f, 0.000000f }	},
	{	{ 0.469873f, -0.022793f, -0.365677f },	{ 0.743587f, 0.852966f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.381579f, 0.149506f, -0.365676f },	{ 0.148894f, -0.102400f, 0.000000f },	{ -0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.469873f, 0.070371f, -0.365677f },	{ 0.385291f, 0.109473f, 0.000000f },	{ -0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.293285f, -0.053171f, -0.365676f },	{ -0.087502f, 0.440241f, 0.000000f },	{ -0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.293285f, -0.022793f, -0.365676f },	{ -0.087502f, 0.358908f, 0.000000f },	{ -0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.293285f, 0.055873f, -0.365676f },	{ -0.087502f, 0.148289f, 0.000000f },	{ -0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.293285f, 0.070371f, -0.365676f },	{ -0.087502f, 0.109474f, 0.000000f },	{ -0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.561455f, 0.109853f, 0.092450f },	{ 0.150390f, 0.299364f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.561455f, 0.101403f, 0.092450f },	{ 0.150390f, 0.320162f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.658078f, 0.101403f, 0.092450f },	{ -0.087441f, 0.320162f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.658078f, 0.109853f, -0.116624f },	{ -0.087441f, 1.102335f, 0.000000f },	{ -0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.658078f, 0.101403f, -0.116624f },	{ -0.087441f, 1.081537f, 0.000000f },	{ -0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.259163f, 0.101403f, -0.116624f },	{ 0.894451f, 1.081537f, 0.000000f },	{ -0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.259163f, -0.053171f, 0.092450f },	{ 0.427180f, -0.102338f, 0.000000f },	{ -1.000000f, 0.000000f, 0.000000f }	},
	{	{ 0.259163f, 0.011297f, 0.092450f },	{ 0.427179f, 0.056343f, 0.000000f },	{ -1.000000f, 0.000000f, 0.000000f }	},
	{	{ 0.259163f, 0.011297f, -0.116624f },	{ -0.087440f, 0.056342f, 0.000000f },	{ -1.000000f, 0.000000f, 0.000000f }	},
	{	{ 0.561455f, 0.011297f, 0.092450f },	{ 0.150390f, 0.541952f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.561455f, -0.053171f, 0.092450f },	{ 0.150390f, 0.700633f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.658078f, -0.053171f, 0.092450f },	{ -0.087441f, 0.700634f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.658078f, 0.011297f, -0.116624f },	{ -0.087441f, 0.859747f, 0.000000f },	{ -0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.658078f, -0.053171f, -0.116624f },	{ -0.087441f, 0.701067f, 0.000000f },	{ -0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.259163f, -0.053171f, -0.116624f },	{ 0.894451f, 0.701067f, 0.000000f },	{ -0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.259163f, 0.101403f, 0.092451f },	{ 0.427179f, 0.278133f, 0.000000f },	{ -1.000000f, 0.000000f, 0.000000f }	},
	{	{ 0.259163f, 0.101403f, -0.116624f },	{ -0.087441f, 0.278132f, 0.000000f },	{ -1.000000f, 0.000000f, 0.000000f }	},
	{	{ 0.658078f, 0.011297f, 0.092450f },	{ -0.087441f, 0.541952f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.658078f, 0.109853f, 0.092450f },	{ 0.942233f, -0.102338f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.658078f, 0.101403f, 0.092450f },	{ 0.942233f, -0.081540f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.658078f, 0.101403f, -0.116624f },	{ 0.427613f, -0.081540f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.259163f, 0.011297f, -0.116624f },	{ 0.894451f, 0.859747f, 0.000000f },	{ -0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.658078f, 0.011297f, 0.092450f },	{ 0.942233f, 0.140250f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.259163f, 0.109853f, 0.092451f },	{ 0.427179f, 0.298931f, 0.000000f },	{ -1.000000f, 0.000000f, 0.000000f }	},
	{	{ 0.259163f, 0.109853f, -0.116624f },	{ -0.087441f, 0.298931f, 0.000000f },	{ -1.000000f, 0.000000f, 0.000000f }	},
	{	{ 0.658078f, -0.053171f, 0.092450f },	{ 0.942233f, 0.298931f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.658078f, -0.053171f, -0.116624f },	{ 0.427613f, 0.298931f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.463728f, 0.109853f, 0.092450f },	{ 0.441945f, 0.299364f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.463728f, 0.101403f, 0.092450f },	{ 0.441945f, 0.320162f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.504285f, 0.101403f, 0.092450f },	{ 0.291109f, 0.320162f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.463728f, 0.011297f, 0.092450f },	{ 0.441946f, 0.541952f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.463728f, -0.053171f, 0.092450f },	{ 0.441946f, 0.700633f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.504285f, -0.053171f, 0.092450f },	{ 0.291110f, 0.700633f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.504285f, 0.011297f, 0.092450f },	{ 0.291109f, 0.541952f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.504285f, 0.109853f, 0.092450f },	{ 0.291109f, 0.299364f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.259163f, 0.109853f, 0.092451f },	{ 0.894454f, 0.299364f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.259163f, 0.101403f, 0.092451f },	{ 0.894454f, 0.320162f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.402315f, 0.101403f, 0.092450f },	{ 0.592782f, 0.320162f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.259163f, 0.011297f, 0.092450f },	{ 0.894454f, 0.541952f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.259163f, -0.053171f, 0.092450f },	{ 0.894454f, 0.700633f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.402315f, -0.053171f, 0.092450f },	{ 0.592782f, 0.700633f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.402315f, 0.011297f, 0.092450f },	{ 0.592782f, 0.541952f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.402315f, 0.109853f, 0.092450f },	{ 0.592782f, 0.299364f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.293286f, 0.070371f, -0.055264f },	{ -0.087502f, 0.440552f, 0.000000f },	{ -1.000000f, 0.000000f, 0.000000f }	},
	{	{ 0.469873f, 0.070371f, -0.365677f },	{ 0.743586f, 1.102400f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.469873f, -0.053171f, -0.365677f },	{ 0.385291f, 0.440241f, 0.000000f },	{ -0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.658078f, 0.109853f, 0.092450f },	{ -0.087441f, 0.299364f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.259163f, 0.109853f, -0.116624f },	{ 0.894451f, 1.102339f, 0.000000f },	{ -0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.259163f, -0.053171f, -0.116624f },	{ -0.087440f, -0.102339f, 0.000000f },	{ -1.000000f, 0.000000f, 0.000000f }	},
	{	{ 0.658078f, 0.109853f, -0.116624f },	{ 0.427613f, -0.102338f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.658078f, 0.011297f, -0.116624f },	{ 0.427613f, 0.140250f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
};
#define _Level1_vertices_
#endif
#ifndef _Level1_indices_
// Index Data follows: Sequential by mesh, Every Three Indices == One Triangle.
const unsigned int Level1_indices[204] =
{
	 0, 1, 2,
	 3, 4, 5,
	 6, 7, 8,
	 9, 10, 11,
	 12, 13, 14,
	 15, 16, 8,
	 1, 9, 17,
	 4, 12, 18,
	 15, 19, 20,
	 21, 22, 7,
	 22, 23, 15,
	 24, 19, 15,
	 25, 26, 27,
	 28, 29, 30,
	 31, 32, 33,
	 34, 35, 36,
	 37, 38, 39,
	 32, 40, 41,
	 26, 34, 42,
	 43, 44, 45,
	 29, 37, 46,
	 45, 44, 47,
	 40, 48, 49,
	 47, 50, 51,
	 52, 53, 54,
	 55, 56, 57,
	 53, 55, 58,
	 59, 54, 26,
	 58, 57, 35,
	 60, 61, 62,
	 63, 64, 65,
	 61, 63, 66,
	 67, 62, 53,
	 66, 65, 56,
	 0, 2, 68,
	 3, 5, 69,
	 6, 8, 70,
	 9, 11, 17,
	 12, 14, 18,
	 15, 8, 7,
	 1, 17, 2,
	 4, 18, 5,
	 15, 20, 16,
	 21, 7, 6,
	 22, 15, 7,
	 24, 15, 23,
	 25, 27, 71,
	 28, 30, 72,
	 31, 33, 73,
	 34, 36, 42,
	 37, 39, 46,
	 32, 41, 33,
	 26, 42, 27,
	 43, 45, 74,
	 29, 46, 30,
	 45, 47, 75,
	 40, 49, 41,
	 47, 51, 75,
	 52, 54, 59,
	 55, 57, 58,
	 53, 58, 54,
	 59, 26, 25,
	 58, 35, 34,
	 60, 62, 67,
	 63, 65, 66,
	 61, 66, 62,
	 67, 53, 52,
	 66, 56, 55,
};
#define _Level1_indices_
#endif
// Part of an OBJ_MATERIAL, the struct is 16 byte aligned so it is GPU register friendly.
#ifndef __OBJ_ATTRIBUTES__
typedef struct _OBJ_ATTRIBUTES_
{
	OBJ_VEC3    Kd; // diffuse reflectivity
	float	    d; // dissolve (transparency) 
	OBJ_VEC3    Ks; // specular reflectivity
	float       Ns; // specular exponent
	OBJ_VEC3    Ka; // ambient reflectivity
	float       sharpness; // local reflection map sharpness
	OBJ_VEC3    Tf; // transmission filter
	float       Ni; // optical density (index of refraction)
	OBJ_VEC3    Ke; // emissive reflectivity
	unsigned    illum; // illumination model
}OBJ_ATTRIBUTES;
#define __OBJ_ATTRIBUTES__
#endif
// This structure also has been made GPU register friendly so it can be transfered directly if desired.
// Note: Total struct size will vary depenedening on CPU processor architecture (string pointers).
#ifndef __OBJ_MATERIAL__
typedef struct _OBJ_MATERIAL_
{
	// The following items are typically used in a pixel/fragment shader, they are packed for GPU registers.
	OBJ_ATTRIBUTES attrib; // Surface shading characteristics & illumination model
	// All items below this line are not needed on the GPU and are generally only used during load time.
	const char* name; // the name of this material
	// If the model's materials contain any specific texture data it will be located below.
	const char* map_Kd; // diffuse texture
	const char* map_Ks; // specular texture
	const char* map_Ka; // ambient texture
	const char* map_Ke; // emissive texture
	const char* map_Ns; // specular exponent texture
	const char* map_d; // transparency texture
	const char* disp; // roughness map (displacement)
	const char* decal; // decal texture (lerps texture & material colors)
	const char* bump; // normal/bumpmap texture
	void* padding[2]; // 16 byte alignment on 32bit or 64bit
}OBJ_MATERIAL;
#define __OBJ_MATERIAL__
#endif
#ifndef _Level1_materials_
// Material Data follows: pulled from a .mtl file of the same name if present.
const OBJ_MATERIAL Level1_materials[1] =
{
	{
		{{ 0.800000f, 0.800000f, 0.800000f },
		1.000000f,
		{ 0.000000f, 0.000000f, 0.000000f },
		225.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		60.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		1.000000f,
		{ 0.000000f, 0.000000f, 0.000000f },
		1},
		"GreyBrick2",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
	},
};
#define _Level1_materials_
#endif
/************************************************/
/*  This section contains the model's structure */
/************************************************/
#ifndef _Level1_batches_
// Use this conveinence array to batch render all geometry by like material.
// Each entry corresponds to the same entry in the materials array above.
// The two numbers provided are the IndexCount and the IndexOffset into the indices array.
// If you need more fine grained control(ex: for transformations) use the OBJ_MESH data below.
const unsigned int Level1_batches[1][2] =
{
	{ 204, 0 },
};
#define _Level1_batches_
#endif
#ifndef __OBJ_MESH__
typedef struct _OBJ_MESH_
{
	const char* name;
	unsigned    indexCount;
	unsigned    indexOffset;
	unsigned    materialIndex;
}OBJ_MESH;
#define __OBJ_MESH__
#endif
#ifndef _Level1_meshes_
// Mesh Data follows: Meshes are .obj groups sorted & split by material.
// Meshes are provided in sequential order, sorted by material first and name second.
const OBJ_MESH Level1_meshes[1] =
{
	{
		"default",
		204,
		0,
		0,
	},
};
#define _Level1_meshes_
#endif
