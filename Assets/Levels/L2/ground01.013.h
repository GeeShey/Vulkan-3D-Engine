// "ground01.013.h" generated by "Obj2Header.exe" [Version 1.9d] Author: L.Norri Fullsail University.
// Data is converted to left-handed coordinate system and UV data is V flipped for Direct3D/Vulkan.
// The companion file "ground01.013.h2b" is a binary dump of this format(-padding) for more flexibility.
// Loading *.h2b: read version, sizes, handle strings(max len 260) by reading until null-terminated.
/***********************/
/*  Generator version  */
/***********************/
#ifndef _ground01_013_version_
const char ground01_013_version[4] = { '0','1','9','d' };
#define _ground01_013_version_
#endif
/************************************************/
/*  This section contains the model's size data */
/************************************************/
#ifndef _ground01_013_vertexcount_
const unsigned ground01_013_vertexcount = 24;
#define _ground01_013_vertexcount_
#endif
#ifndef _ground01_013_indexcount_
const unsigned ground01_013_indexcount = 36;
#define _ground01_013_indexcount_
#endif
#ifndef _ground01_013_materialcount_
const unsigned ground01_013_materialcount = 1; // can be used for batched draws
#define _ground01_013_materialcount_
#endif
#ifndef _ground01_013_meshcount_
const unsigned ground01_013_meshcount = 1;
#define _ground01_013_meshcount_
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
#ifndef _ground01_013_vertices_
// Raw Vertex Data follows: Positions, Texture Coordinates and Normals.
const OBJ_VERT ground01_013_vertices[24] =
{
	{	{ 0.368634f, -0.368634f, 0.092158f },	{ -0.000293f, 0.999414f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.368634f, -0.368634f, -0.092159f },	{ -0.000293f, 0.499414f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.368634f, 0.368634f, -0.092158f },	{ 0.499707f, 0.499414f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.368634f, 0.368634f, 0.092159f },	{ 0.499707f, 0.999414f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.368634f, 0.368634f, 0.092159f },	{ -0.000293f, 0.999414f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.368634f, 0.368634f, -0.092158f },	{ -0.000293f, 0.499414f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.368634f, 0.368634f, -0.092158f },	{ 0.499707f, 0.499414f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.368634f, 0.368634f, 0.092159f },	{ 0.499707f, 0.999414f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.368634f, -0.368634f, 0.092158f },	{ -0.000293f, 0.999414f, 0.000000f },	{ 0.000000f, -0.000000f, 1.000000f }	},
	{	{ 0.368634f, 0.368634f, 0.092159f },	{ -0.000293f, 0.499414f, 0.000000f },	{ 0.000000f, -0.000000f, 1.000000f }	},
	{	{ -0.368634f, 0.368634f, 0.092159f },	{ 0.499707f, 0.499414f, 0.000000f },	{ 0.000000f, -0.000000f, 1.000000f }	},
	{	{ -0.368634f, -0.368634f, 0.092158f },	{ 0.499707f, 0.999414f, 0.000000f },	{ 0.000000f, -0.000000f, 1.000000f }	},
	{	{ -0.368634f, -0.368634f, 0.092158f },	{ -0.000293f, 0.999414f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -0.368634f, -0.368634f, -0.092159f },	{ -0.000293f, 0.499414f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.368634f, -0.368634f, -0.092159f },	{ 0.499707f, 0.499414f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.368634f, -0.368634f, 0.092158f },	{ 0.499707f, 0.999414f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.368634f, 0.368634f, -0.092158f },	{ -0.000293f, 0.499414f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.368634f, -0.368634f, -0.092159f },	{ -0.000293f, -0.000586f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.368634f, -0.368634f, -0.092159f },	{ 0.499707f, -0.000586f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.368634f, 0.368634f, -0.092158f },	{ 0.499707f, 0.499414f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.368634f, 0.368634f, 0.092159f },	{ -0.000293f, 0.999414f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.368634f, 0.368634f, -0.092158f },	{ -0.000293f, 0.499414f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.368634f, -0.368634f, -0.092159f },	{ 0.499707f, 0.499414f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.368634f, -0.368634f, 0.092158f },	{ 0.499707f, 0.999414f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
};
#define _ground01_013_vertices_
#endif
#ifndef _ground01_013_indices_
// Index Data follows: Sequential by mesh, Every Three Indices == One Triangle.
const unsigned int ground01_013_indices[36] =
{
	 0, 1, 2,
	 3, 0, 2,
	 4, 5, 6,
	 7, 4, 6,
	 8, 9, 10,
	 11, 8, 10,
	 12, 13, 14,
	 15, 12, 14,
	 16, 17, 18,
	 19, 16, 18,
	 20, 21, 22,
	 23, 20, 22,
};
#define _ground01_013_indices_
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
#ifndef _ground01_013_materials_
// Material Data follows: pulled from a .mtl file of the same name if present.
const OBJ_MATERIAL ground01_013_materials[1] =
{
	{
		{{ 0.128450f, 0.668200f, 0.800000f },
		1.000000f,
		{ 0.500000f, 0.500000f, 0.500000f },
		225.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		60.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		1.450000f,
		{ 0.000000f, 0.000000f, 0.000000f },
		2},
		"Material.005",
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
#define _ground01_013_materials_
#endif
/************************************************/
/*  This section contains the model's structure */
/************************************************/
#ifndef _ground01_013_batches_
// Use this conveinence array to batch render all geometry by like material.
// Each entry corresponds to the same entry in the materials array above.
// The two numbers provided are the IndexCount and the IndexOffset into the indices array.
// If you need more fine grained control(ex: for transformations) use the OBJ_MESH data below.
const unsigned int ground01_013_batches[1][2] =
{
	{ 36, 0 },
};
#define _ground01_013_batches_
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
#ifndef _ground01_013_meshes_
// Mesh Data follows: Meshes are .obj groups sorted & split by material.
// Meshes are provided in sequential order, sorted by material first and name second.
const OBJ_MESH ground01_013_meshes[1] =
{
	{
		"default",
		36,
		0,
		0,
	},
};
#define _ground01_013_meshes_
#endif
