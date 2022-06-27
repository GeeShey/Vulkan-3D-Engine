// "Floor.h" generated by "Obj2Header.exe" [Version 1.9d] Author: L.Norri Fullsail University.
// Data is converted to left-handed coordinate system and UV data is V flipped for Direct3D/Vulkan.
// The companion file "Floor.h2b" is a binary dump of this format(-padding) for more flexibility.
// Loading *.h2b: read version, sizes, handle strings(max len 260) by reading until null-terminated.
/***********************/
/*  Generator version  */
/***********************/
#ifndef _Floor_version_
const char Floor_version[4] = { '0','1','9','d' };
#define _Floor_version_
#endif
/************************************************/
/*  This section contains the model's size data */
/************************************************/
#ifndef _Floor_vertexcount_
const unsigned Floor_vertexcount = 80;
#define _Floor_vertexcount_
#endif
#ifndef _Floor_indexcount_
const unsigned Floor_indexcount = 192;
#define _Floor_indexcount_
#endif
#ifndef _Floor_materialcount_
const unsigned Floor_materialcount = 1; // can be used for batched draws
#define _Floor_materialcount_
#endif
#ifndef _Floor_meshcount_
const unsigned Floor_meshcount = 1;
#define _Floor_meshcount_
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
#ifndef _Floor_vertices_
// Raw Vertex Data follows: Positions, Texture Coordinates and Normals.
const OBJ_VERT Floor_vertices[80] =
{
	{	{ -1.454839f, 0.068814f, -0.187921f },	{ -0.487405f, -0.380678f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.230938f, 0.068814f, -0.187921f },	{ 0.015903f, -0.387972f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.230938f, 0.066814f, -0.187921f },	{ 0.015962f, -0.379176f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.454840f, 0.068814f, 0.336468f },	{ -1.675068f, -0.366166f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.454839f, 0.068814f, 0.013931f },	{ -1.168481f, -0.373430f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.454839f, 0.066814f, 0.013931f },	{ -1.168420f, -0.364592f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.122450f, 0.068814f, 0.336468f },	{ 1.685906f, -0.387223f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.217882f, 0.068814f, 0.336468f },	{ 2.109061f, -0.378963f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.217882f, 0.066814f, 0.336468f },	{ 2.108866f, -0.370095f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.122449f, 0.068814f, -0.187921f },	{ 0.494610f, -0.389465f, 0.000000f },	{ 1.000000f, 0.000000f, 0.000000f }	},
	{	{ -1.122449f, 0.068814f, -0.025907f },	{ 1.001502f, -0.391025f, 0.000000f },	{ 1.000000f, 0.000000f, 0.000000f }	},
	{	{ -1.122449f, 0.066814f, -0.025907f },	{ 1.001465f, -0.382173f, 0.000000f },	{ 1.000000f, 0.000000f, 0.000000f }	},
	{	{ -1.454839f, 0.066814f, 0.013931f },	{ -0.998867f, 0.756823f, 0.000000f },	{ 0.000000f, -1.000000f, 0.000000f }	},
	{	{ -1.230939f, 0.066814f, 0.013931f },	{ -0.998867f, 0.006759f, 0.000000f },	{ 0.000000f, -1.000000f, 0.000000f }	},
	{	{ -1.230939f, 0.066814f, 0.336468f },	{ 0.081629f, 0.006759f, 0.000000f },	{ 0.000000f, -1.000000f, 0.000000f }	},
	{	{ -1.454839f, 0.068814f, -0.025907f },	{ -1.132323f, 0.757470f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -1.230939f, 0.068814f, -0.025907f },	{ -1.132323f, 1.507533f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -1.230938f, 0.068814f, -0.187921f },	{ -1.675068f, 1.507533f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -1.454839f, 0.068814f, -0.025907f },	{ -0.992540f, -0.374666f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.454839f, 0.066814f, -0.025907f },	{ -0.992476f, -0.365841f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.122449f, 0.068814f, 0.013931f },	{ 1.177961f, -0.389810f, 0.000000f },	{ 1.000000f, 0.000000f, 0.000000f }	},
	{	{ -1.122450f, 0.068814f, 0.336468f },	{ 1.685906f, -0.387223f, 0.000000f },	{ 1.000000f, 0.000000f, 0.000000f }	},
	{	{ -1.122450f, 0.066814f, 0.336468f },	{ 1.685763f, -0.378357f, 0.000000f },	{ 1.000000f, 0.000000f, 0.000000f }	},
	{	{ -1.230939f, 0.066814f, -0.025907f },	{ -1.132323f, 0.006759f, 0.000000f },	{ 0.000000f, -1.000000f, 0.000000f }	},
	{	{ -1.230939f, 0.068814f, 0.336468f },	{ 0.081629f, 1.507533f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -1.230939f, 0.068814f, 0.013931f },	{ -0.998868f, 1.507533f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -1.454839f, 0.068814f, 0.013931f },	{ -0.998868f, 0.757470f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -1.122449f, 0.066814f, 0.013931f },	{ 1.177874f, -0.380949f, 0.000000f },	{ 1.000000f, 0.000000f, 0.000000f }	},
	{	{ -1.454839f, 0.068814f, -0.187921f },	{ -0.487405f, -0.380678f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.454839f, 0.066814f, -0.187921f },	{ -0.487337f, -0.371877f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.230938f, 0.066814f, -0.187921f },	{ -1.675067f, 0.006759f, 0.000000f },	{ 0.000000f, -1.000000f, 0.000000f }	},
	{	{ -1.454839f, 0.066814f, -0.025907f },	{ -1.132322f, 0.756823f, 0.000000f },	{ 0.000000f, -1.000000f, 0.000000f }	},
	{	{ -1.217882f, 0.068814f, -0.187921f },	{ 0.073414f, -0.388291f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.217882f, 0.066814f, -0.187921f },	{ 0.073450f, -0.379474f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.230939f, 0.068814f, 0.336468f },	{ 2.166973f, -0.377551f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.454840f, 0.068814f, 0.336468f },	{ 2.675068f, -0.366190f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.454840f, 0.066814f, 0.336468f },	{ 2.674813f, -0.357324f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.217882f, 0.066814f, 0.013931f },	{ -0.998867f, -0.036981f, 0.000000f },	{ 0.000000f, -1.000000f, 0.000000f }	},
	{	{ -1.217882f, 0.066814f, 0.336468f },	{ 0.081629f, -0.036981f, 0.000000f },	{ 0.000000f, -1.000000f, 0.000000f }	},
	{	{ -1.217882f, 0.068814f, -0.025907f },	{ -1.132323f, 1.551274f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -1.217882f, 0.068814f, -0.187921f },	{ -1.675068f, 1.551273f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -1.217882f, 0.068814f, -0.025907f },	{ 0.436654f, 1.864274f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.217882f, 0.066814f, -0.025907f },	{ 0.436654f, 1.870971f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.217882f, 0.066814f, 0.013931f },	{ 0.303264f, 1.870955f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.217882f, 0.068814f, 0.336468f },	{ 0.081629f, 1.551274f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -1.217882f, 0.068814f, 0.013931f },	{ -0.998868f, 1.551274f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -1.217882f, 0.068814f, -0.025907f },	{ 0.082275f, 1.864267f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.230939f, 0.068814f, -0.025907f },	{ 0.126042f, 1.864262f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.230939f, 0.066814f, -0.025907f },	{ 0.126042f, 1.870965f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.217882f, 0.066814f, -0.187921f },	{ -1.675067f, -0.036981f, 0.000000f },	{ 0.000000f, -1.000000f, 0.000000f }	},
	{	{ -1.217882f, 0.066814f, -0.025907f },	{ -1.132323f, -0.036981f, 0.000000f },	{ 0.000000f, -1.000000f, 0.000000f }	},
	{	{ -1.230939f, 0.066814f, 0.336468f },	{ 2.166738f, -0.368684f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.122449f, 0.068814f, -0.187921f },	{ 0.494610f, -0.389465f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.122449f, 0.066814f, -0.187921f },	{ 0.494617f, -0.380627f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.122449f, 0.066814f, 0.013931f },	{ -0.998867f, -0.356678f, 0.000000f },	{ 0.000000f, -1.000000f, 0.000000f }	},
	{	{ -1.122450f, 0.066814f, 0.336468f },	{ 0.081629f, -0.356677f, 0.000000f },	{ 0.000000f, -1.000000f, 0.000000f }	},
	{	{ -1.122449f, 0.068814f, -0.025907f },	{ -1.132323f, 1.870970f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -1.122449f, 0.068814f, -0.187921f },	{ -1.675067f, 1.870970f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -1.122449f, 0.066814f, -0.025907f },	{ -1.132322f, -0.356678f, 0.000000f },	{ 0.000000f, -1.000000f, 0.000000f }	},
	{	{ -1.122450f, 0.068814f, 0.336468f },	{ 0.081629f, 1.870971f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -1.122449f, 0.068814f, 0.013931f },	{ -0.998868f, 1.870970f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -1.122449f, 0.066814f, -0.187921f },	{ -1.675068f, -0.356678f, 0.000000f },	{ 0.000000f, -1.000000f, 0.000000f }	},
	{	{ -1.230939f, 0.066814f, 0.013931f },	{ 0.259517f, 1.870957f, 0.000000f },	{ 1.000000f, 0.000000f, 0.000000f }	},
	{	{ -1.230939f, 0.066814f, -0.025907f },	{ 0.126042f, 1.870965f, 0.000000f },	{ 1.000000f, 0.000000f, 0.000000f }	},
	{	{ -1.230939f, 0.068814f, -0.025907f },	{ 0.126042f, 1.864262f, 0.000000f },	{ 1.000000f, 0.000000f, 0.000000f }	},
	{	{ -1.217882f, 0.066814f, 0.013931f },	{ 0.303264f, 1.870955f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.230939f, 0.066814f, 0.013931f },	{ 0.259517f, 1.870957f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.230939f, 0.068814f, 0.013931f },	{ 0.259517f, 1.864256f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.454839f, 0.066814f, -0.187921f },	{ -0.487337f, -0.371877f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.454840f, 0.066814f, 0.336468f },	{ -1.675009f, -0.357324f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.122450f, 0.066814f, 0.336468f },	{ 1.685763f, -0.378357f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.122449f, 0.066814f, -0.187921f },	{ 0.494617f, -0.380627f, 0.000000f },	{ 1.000000f, 0.000000f, 0.000000f }	},
	{	{ -1.454840f, 0.066814f, 0.336468f },	{ 0.081629f, 0.756823f, 0.000000f },	{ 0.000000f, -1.000000f, 0.000000f }	},
	{	{ -1.454839f, 0.068814f, -0.187921f },	{ -1.675067f, 0.757470f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -1.454840f, 0.068814f, 0.336468f },	{ 0.081629f, 0.757469f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -1.454839f, 0.066814f, -0.187921f },	{ -1.675067f, 0.756823f, 0.000000f },	{ 0.000000f, -1.000000f, 0.000000f }	},
	{	{ -1.217882f, 0.068814f, 0.013931f },	{ 0.303264f, 1.864256f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.217882f, 0.066814f, -0.025907f },	{ 0.082276f, 1.870971f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.230939f, 0.068814f, 0.013931f },	{ 0.259517f, 1.864256f, 0.000000f },	{ 1.000000f, 0.000000f, 0.000000f }	},
	{	{ -1.217882f, 0.068814f, 0.013931f },	{ 0.303264f, 1.864256f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
};
#define _Floor_vertices_
#endif
#ifndef _Floor_indices_
// Index Data follows: Sequential by mesh, Every Three Indices == One Triangle.
const unsigned int Floor_indices[192] =
{
	 0, 1, 2,
	 3, 4, 5,
	 6, 7, 8,
	 9, 10, 11,
	 12, 13, 14,
	 15, 16, 17,
	 4, 18, 19,
	 20, 21, 22,
	 23, 13, 12,
	 24, 25, 26,
	 10, 20, 27,
	 26, 25, 16,
	 18, 28, 29,
	 30, 23, 31,
	 1, 32, 33,
	 34, 35, 36,
	 13, 37, 38,
	 16, 39, 40,
	 41, 42, 43,
	 24, 44, 45,
	 46, 47, 48,
	 30, 49, 50,
	 7, 34, 51,
	 32, 52, 53,
	 37, 54, 55,
	 39, 56, 57,
	 50, 58, 54,
	 59, 60, 45,
	 60, 56, 39,
	 61, 58, 50,
	 62, 63, 64,
	 65, 66, 67,
	 0, 2, 68,
	 3, 5, 69,
	 6, 8, 70,
	 9, 11, 71,
	 12, 14, 72,
	 15, 17, 73,
	 4, 19, 5,
	 20, 22, 27,
	 23, 12, 31,
	 24, 26, 74,
	 10, 27, 11,
	 26, 16, 15,
	 18, 29, 19,
	 30, 31, 75,
	 1, 33, 2,
	 34, 36, 51,
	 13, 38, 14,
	 16, 40, 17,
	 41, 43, 76,
	 24, 45, 25,
	 46, 48, 77,
	 30, 50, 23,
	 7, 51, 8,
	 32, 53, 33,
	 37, 55, 38,
	 39, 57, 40,
	 50, 54, 37,
	 59, 45, 44,
	 60, 39, 45,
	 61, 50, 49,
	 62, 64, 78,
	 65, 67, 79,
};
#define _Floor_indices_
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
#ifndef _Floor_materials_
// Material Data follows: pulled from a .mtl file of the same name if present.
const OBJ_MATERIAL Floor_materials[1] =
{
	{
		{{ 0.087140f, 0.044223f, 0.017671f },
		1.000000f,
		{ 0.500000f, 0.500000f, 0.500000f },
		225.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		60.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		1.450000f,
		{ 0.000000f, 0.000000f, 0.000000f },
		2},
		"Wood.005",
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
#define _Floor_materials_
#endif
/************************************************/
/*  This section contains the model's structure */
/************************************************/
#ifndef _Floor_batches_
// Use this conveinence array to batch render all geometry by like material.
// Each entry corresponds to the same entry in the materials array above.
// The two numbers provided are the IndexCount and the IndexOffset into the indices array.
// If you need more fine grained control(ex: for transformations) use the OBJ_MESH data below.
const unsigned int Floor_batches[1][2] =
{
	{ 192, 0 },
};
#define _Floor_batches_
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
#ifndef _Floor_meshes_
// Mesh Data follows: Meshes are .obj groups sorted & split by material.
// Meshes are provided in sequential order, sorted by material first and name second.
const OBJ_MESH Floor_meshes[1] =
{
	{
		"default",
		192,
		0,
		0,
	},
};
#define _Floor_meshes_
#endif
