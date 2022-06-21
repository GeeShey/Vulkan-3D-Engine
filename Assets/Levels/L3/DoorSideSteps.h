// "DoorSideSteps.h" generated by "Obj2Header.exe" [Version 1.9d] Author: L.Norri Fullsail University.
// Data is converted to left-handed coordinate system and UV data is V flipped for Direct3D/Vulkan.
// The companion file "DoorSideSteps.h2b" is a binary dump of this format(-padding) for more flexibility.
// Loading *.h2b: read version, sizes, handle strings(max len 260) by reading until null-terminated.
/***********************/
/*  Generator version  */
/***********************/
#ifndef _DoorSideSteps_version_
const char DoorSideSteps_version[4] = { '0','1','9','d' };
#define _DoorSideSteps_version_
#endif
/************************************************/
/*  This section contains the model's size data */
/************************************************/
#ifndef _DoorSideSteps_vertexcount_
const unsigned DoorSideSteps_vertexcount = 16;
#define _DoorSideSteps_vertexcount_
#endif
#ifndef _DoorSideSteps_indexcount_
const unsigned DoorSideSteps_indexcount = 24;
#define _DoorSideSteps_indexcount_
#endif
#ifndef _DoorSideSteps_materialcount_
const unsigned DoorSideSteps_materialcount = 1; // can be used for batched draws
#define _DoorSideSteps_materialcount_
#endif
#ifndef _DoorSideSteps_meshcount_
const unsigned DoorSideSteps_meshcount = 1;
#define _DoorSideSteps_meshcount_
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
#ifndef _DoorSideSteps_vertices_
// Raw Vertex Data follows: Positions, Texture Coordinates and Normals.
const OBJ_VERT DoorSideSteps_vertices[16] =
{
	{	{ -0.344027f, 0.387345f, 0.053050f },	{ -0.421324f, 0.815009f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.344027f, 0.387345f, 0.046974f },	{ -0.421324f, 0.665533f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.418925f, 0.387345f, 0.046974f },	{ 1.421313f, 0.665531f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.418925f, 0.387345f, 0.046974f },	{ 1.421313f, 0.665531f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.418926f, 0.353195f, 0.046974f },	{ 2.261466f, 0.665531f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.418926f, 0.353195f, 0.053050f },	{ 2.261467f, 0.815009f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.344027f, 0.387345f, 0.053050f },	{ -0.421324f, 0.815009f, 0.000000f },	{ 1.000000f, -0.000000f, -0.000000f }	},
	{	{ -0.344027f, 0.353195f, 0.053050f },	{ -1.261466f, 0.815010f, 0.000000f },	{ 1.000000f, -0.000000f, -0.000000f }	},
	{	{ -0.344027f, 0.353195f, 0.046974f },	{ -1.261467f, 0.665534f, 0.000000f },	{ 1.000000f, -0.000000f, -0.000000f }	},
	{	{ -0.344027f, 0.353195f, 0.046974f },	{ -0.421325f, -0.174616f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.418926f, 0.353195f, 0.046974f },	{ 1.421312f, -0.174616f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.418925f, 0.387345f, 0.046974f },	{ 1.421313f, 0.665531f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.418925f, 0.387345f, 0.053050f },	{ 1.421313f, 0.815009f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.418925f, 0.387345f, 0.053050f },	{ 1.421313f, 0.815009f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.344027f, 0.387345f, 0.046974f },	{ -0.421324f, 0.665533f, 0.000000f },	{ 1.000000f, -0.000000f, -0.000000f }	},
	{	{ -0.344027f, 0.387345f, 0.046974f },	{ -0.421324f, 0.665533f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
};
#define _DoorSideSteps_vertices_
#endif
#ifndef _DoorSideSteps_indices_
// Index Data follows: Sequential by mesh, Every Three Indices == One Triangle.
const unsigned int DoorSideSteps_indices[24] =
{
	 0, 1, 2,
	 3, 4, 5,
	 6, 7, 8,
	 9, 10, 11,
	 0, 2, 12,
	 3, 5, 13,
	 6, 8, 14,
	 9, 11, 15,
};
#define _DoorSideSteps_indices_
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
#ifndef _DoorSideSteps_materials_
// Material Data follows: pulled from a .mtl file of the same name if present.
const OBJ_MATERIAL DoorSideSteps_materials[1] =
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
		"Stone",
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
#define _DoorSideSteps_materials_
#endif
/************************************************/
/*  This section contains the model's structure */
/************************************************/
#ifndef _DoorSideSteps_batches_
// Use this conveinence array to batch render all geometry by like material.
// Each entry corresponds to the same entry in the materials array above.
// The two numbers provided are the IndexCount and the IndexOffset into the indices array.
// If you need more fine grained control(ex: for transformations) use the OBJ_MESH data below.
const unsigned int DoorSideSteps_batches[1][2] =
{
	{ 24, 0 },
};
#define _DoorSideSteps_batches_
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
#ifndef _DoorSideSteps_meshes_
// Mesh Data follows: Meshes are .obj groups sorted & split by material.
// Meshes are provided in sequential order, sorted by material first and name second.
const OBJ_MESH DoorSideSteps_meshes[1] =
{
	{
		"default",
		24,
		0,
		0,
	},
};
#define _DoorSideSteps_meshes_
#endif