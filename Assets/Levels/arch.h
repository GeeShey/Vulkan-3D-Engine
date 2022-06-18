// "arch.h" generated by "Obj2Header.exe" [Version 1.9d] Author: L.Norri Fullsail University.
// Data is converted to left-handed coordinate system and UV data is V flipped for Direct3D/Vulkan.
// The companion file "arch.h2b" is a binary dump of this format(-padding) for more flexibility.
// Loading *.h2b: read version, sizes, handle strings(max len 260) by reading until null-terminated.
/***********************/
/*  Generator version  */
/***********************/
#ifndef _arch_version_
const char arch_version[4] = { '0','1','9','d' };
#define _arch_version_
#endif
/************************************************/
/*  This section contains the model's size data */
/************************************************/
#ifndef _arch_vertexcount_
const unsigned arch_vertexcount = 134;
#define _arch_vertexcount_
#endif
#ifndef _arch_indexcount_
const unsigned arch_indexcount = 228;
#define _arch_indexcount_
#endif
#ifndef _arch_materialcount_
const unsigned arch_materialcount = 1; // can be used for batched draws
#define _arch_materialcount_
#endif
#ifndef _arch_meshcount_
const unsigned arch_meshcount = 1;
#define _arch_meshcount_
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
#ifndef _arch_vertices_
// Raw Vertex Data follows: Positions, Texture Coordinates and Normals.
const OBJ_VERT arch_vertices[134] =
{
	{	{ 0.995563f, 9.027871f, -2.913095f },	{ 0.571120f, 0.147660f, 0.000000f },	{ 1.000000f, 0.000000f, 0.000000f }	},
	{	{ 0.995563f, 9.027871f, -3.505670f },	{ 0.571120f, 0.088532f, 0.000000f },	{ 1.000000f, 0.000000f, 0.000000f }	},
	{	{ 0.995563f, 10.527871f, -3.505670f },	{ 0.630248f, 0.088532f, 0.000000f },	{ 1.000000f, 0.000000f, 0.000000f }	},
	{	{ 0.995563f, 10.527871f, -2.913095f },	{ 0.630248f, 0.147660f, 0.000000f },	{ 1.000000f, 0.000000f, 0.000000f }	},
	{	{ 0.548563f, 10.256143f, -2.913095f },	{ 0.515195f, 0.320408f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.548563f, 10.256143f, -3.505670f },	{ 0.515195f, 0.236013f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.360996f, 10.256143f, -3.759918f },	{ 0.541908f, 0.199802f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.360996f, 10.256143f, -3.257070f },	{ 0.541908f, 0.271418f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -1.398437f, 10.527871f, -2.913095f },	{ 0.571120f, 0.147660f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.398437f, 10.527871f, -3.505670f },	{ 0.571120f, 0.088532f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.398437f, 9.027871f, -3.505670f },	{ 0.630248f, 0.088532f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.398437f, 9.027871f, -2.913095f },	{ 0.630248f, 0.147660f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.360996f, 9.299600f, -3.759918f },	{ 0.541908f, 0.199802f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.548563f, 9.299600f, -3.505670f },	{ 0.515195f, 0.236013f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.548563f, 9.299600f, -2.913095f },	{ 0.515195f, 0.320408f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.360996f, 9.299600f, -3.257070f },	{ 0.541908f, 0.271418f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.548563f, 9.299600f, -3.505670f },	{ 0.502740f, 0.987565f, 0.000000f },	{ 0.804700f, 0.000000f, -0.593700f }	},
	{	{ 0.360996f, 9.299600f, -3.759918f },	{ 0.502740f, 0.926933f, 0.000000f },	{ 0.804700f, 0.000000f, -0.593700f }	},
	{	{ 0.360996f, 10.256143f, -3.759918f },	{ 0.811943f, 0.926933f, 0.000000f },	{ 0.804700f, 0.000000f, -0.593700f }	},
	{	{ 0.548563f, 10.256143f, -3.505670f },	{ 0.811943f, 0.987565f, 0.000000f },	{ 0.804700f, 0.000000f, -0.593700f }	},
	{	{ 0.034759f, 9.299600f, -3.437047f },	{ 0.568727f, 0.483773f, 0.000000f },	{ -0.483000f, 0.000000f, 0.875600f }	},
	{	{ 0.360996f, 9.299600f, -3.257070f },	{ 0.568727f, 0.377775f, 0.000000f },	{ -0.483000f, 0.000000f, 0.875600f }	},
	{	{ 0.360996f, 10.256143f, -3.257070f },	{ 0.674725f, 0.377775f, 0.000000f },	{ -0.483000f, 0.000000f, 0.875600f }	},
	{	{ 0.034759f, 10.256143f, -3.437047f },	{ 0.674725f, 0.483773f, 0.000000f },	{ -0.483000f, 0.000000f, 0.875600f }	},
	{	{ -0.763869f, 10.256143f, -3.257070f },	{ 0.702112f, 0.271418f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.437633f, 10.256143f, -3.437047f },	{ 0.655649f, 0.245786f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.437632f, 10.256143f, -3.929019f },	{ 0.655649f, 0.175719f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.763869f, 10.256143f, -3.759919f },	{ 0.702112f, 0.199802f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.034759f, 9.299600f, -3.437047f },	{ 0.588371f, 0.245786f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.034759f, 9.299600f, -3.929019f },	{ 0.588371f, 0.175719f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.360996f, 9.299600f, -3.257070f },	{ 0.568727f, 0.483773f, 0.000000f },	{ -0.878000f, 0.000000f, 0.478700f }	},
	{	{ 0.548563f, 9.299600f, -2.913095f },	{ 0.568727f, 0.377775f, 0.000000f },	{ -0.878000f, 0.000000f, 0.478700f }	},
	{	{ 0.548563f, 10.256143f, -2.913095f },	{ 0.674725f, 0.377775f, 0.000000f },	{ -0.878000f, 0.000000f, 0.478700f }	},
	{	{ 0.360996f, 10.256143f, -3.257070f },	{ 0.674725f, 0.483773f, 0.000000f },	{ -0.878000f, 0.000000f, 0.478700f }	},
	{	{ 0.034759f, 10.256143f, -3.437047f },	{ 0.568727f, 0.483773f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -0.437633f, 10.256143f, -3.437047f },	{ 0.568727f, 0.377775f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -0.437633f, 9.299600f, -3.437047f },	{ 0.674725f, 0.377775f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.034759f, 9.299600f, -3.437047f },	{ 0.674725f, 0.483773f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -0.437633f, 9.299600f, -3.437047f },	{ 0.655649f, 0.245786f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -0.437632f, 9.299600f, -3.929019f },	{ 0.655649f, 0.175719f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -0.763869f, 9.299600f, -3.257070f },	{ 0.702112f, 0.271418f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -0.951437f, 9.299600f, -2.913095f },	{ 0.728826f, 0.320408f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -0.951437f, 9.299600f, -3.505670f },	{ 0.728826f, 0.236013f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -0.763869f, 9.299600f, -3.759919f },	{ 0.702112f, 0.199802f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.034759f, 10.256143f, -3.929019f },	{ 0.588371f, 0.175719f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.034759f, 10.256143f, -3.437047f },	{ 0.588371f, 0.245786f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.763869f, 9.299600f, -3.759919f },	{ 0.501505f, 0.562440f, 0.000000f },	{ -0.804700f, 0.000000f, -0.593700f }	},
	{	{ -0.951437f, 9.299600f, -3.505670f },	{ 0.501505f, 0.501809f, 0.000000f },	{ -0.804700f, 0.000000f, -0.593700f }	},
	{	{ -0.951437f, 10.256143f, -3.505670f },	{ 0.810708f, 0.501809f, 0.000000f },	{ -0.804700f, 0.000000f, -0.593700f }	},
	{	{ -0.763869f, 10.256143f, -3.759919f },	{ 0.810708f, 0.562440f, 0.000000f },	{ -0.804700f, 0.000000f, -0.593700f }	},
	{	{ -0.437632f, 9.299600f, -3.929019f },	{ 0.501505f, 0.667896f, 0.000000f },	{ -0.460200f, 0.000000f, -0.887800f }	},
	{	{ -0.763869f, 9.299600f, -3.759919f },	{ 0.501505f, 0.562440f, 0.000000f },	{ -0.460200f, 0.000000f, -0.887800f }	},
	{	{ -0.763869f, 10.256143f, -3.759919f },	{ 0.810708f, 0.562440f, 0.000000f },	{ -0.460200f, 0.000000f, -0.887800f }	},
	{	{ -0.437632f, 10.256143f, -3.929019f },	{ 0.810708f, 0.667896f, 0.000000f },	{ -0.460200f, 0.000000f, -0.887800f }	},
	{	{ -0.951437f, 10.256143f, -3.505670f },	{ 0.728826f, 0.236013f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.951437f, 10.256143f, -2.913095f },	{ 0.728826f, 0.320408f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.360996f, 9.299600f, -3.759918f },	{ 0.502740f, 0.926933f, 0.000000f },	{ 0.460200f, 0.000000f, -0.887800f }	},
	{	{ 0.034759f, 9.299600f, -3.929019f },	{ 0.502740f, 0.821478f, 0.000000f },	{ 0.460200f, 0.000000f, -0.887800f }	},
	{	{ 0.034759f, 10.256143f, -3.929019f },	{ 0.811943f, 0.821478f, 0.000000f },	{ 0.460200f, 0.000000f, -0.887800f }	},
	{	{ 0.360996f, 10.256143f, -3.759918f },	{ 0.811943f, 0.926933f, 0.000000f },	{ 0.460200f, 0.000000f, -0.887800f }	},
	{	{ -0.437633f, 10.256143f, -3.437047f },	{ 0.568727f, 0.483773f, 0.000000f },	{ 0.483000f, 0.000000f, 0.875600f }	},
	{	{ -0.763869f, 10.256143f, -3.257070f },	{ 0.568727f, 0.377775f, 0.000000f },	{ 0.483000f, 0.000000f, 0.875600f }	},
	{	{ -0.763869f, 9.299600f, -3.257070f },	{ 0.674725f, 0.377775f, 0.000000f },	{ 0.483000f, 0.000000f, 0.875600f }	},
	{	{ -0.437633f, 9.299600f, -3.437047f },	{ 0.674725f, 0.483773f, 0.000000f },	{ 0.483000f, 0.000000f, 0.875600f }	},
	{	{ -0.437632f, 9.299600f, -3.929019f },	{ 0.501505f, 0.667896f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.437632f, 10.256143f, -3.929019f },	{ 0.810708f, 0.667896f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.034759f, 10.256143f, -3.929019f },	{ 0.810708f, 0.820597f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.034759f, 9.299600f, -3.929019f },	{ 0.501505f, 0.820597f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.763869f, 10.256143f, -3.257070f },	{ 0.568727f, 0.483773f, 0.000000f },	{ 0.878000f, 0.000000f, 0.478700f }	},
	{	{ -0.951437f, 10.256143f, -2.913095f },	{ 0.568727f, 0.377775f, 0.000000f },	{ 0.878000f, 0.000000f, 0.478700f }	},
	{	{ -0.951437f, 9.299600f, -2.913095f },	{ 0.674725f, 0.377775f, 0.000000f },	{ 0.878000f, 0.000000f, 0.478700f }	},
	{	{ -0.763869f, 9.299600f, -3.257070f },	{ 0.674725f, 0.483773f, 0.000000f },	{ 0.878000f, 0.000000f, 0.478700f }	},
	{	{ -0.951437f, 10.256143f, -3.505670f },	{ 0.700938f, 0.233772f, 0.000000f },	{ 1.000000f, 0.000000f, 0.000000f }	},
	{	{ -0.951437f, 10.527871f, -3.505670f },	{ 0.742663f, 0.233772f, 0.000000f },	{ 1.000000f, 0.000000f, 0.000000f }	},
	{	{ -0.951437f, 10.527871f, -2.913095f },	{ 0.742663f, 0.324765f, 0.000000f },	{ 1.000000f, 0.000000f, 0.000000f }	},
	{	{ -0.951437f, 10.256143f, -2.913095f },	{ 0.700938f, 0.324765f, 0.000000f },	{ 1.000000f, 0.000000f, 0.000000f }	},
	{	{ -1.398437f, 10.527871f, -2.913095f },	{ 0.674725f, 0.377775f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -0.951437f, 10.256143f, -2.913095f },	{ 0.568727f, 0.483773f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -0.951437f, 10.527871f, -2.913095f },	{ 0.568727f, 0.377775f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -0.951437f, 9.299600f, -2.913095f },	{ 1.000000f, 1.000000f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.398437f, 9.027871f, -2.913095f },	{ 1.000000f, 1.000000f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -0.951437f, 9.027871f, -2.913095f },	{ 1.000000f, 1.000000f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -0.951437f, 10.256143f, -3.505670f },	{ 0.754895f, 0.594024f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.398437f, 10.527871f, -3.505670f },	{ 0.810952f, 0.501809f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.951437f, 10.527871f, -3.505670f },	{ 0.810952f, 0.594024f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.548563f, 9.299600f, -2.913095f },	{ 0.568727f, 0.483773f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.995563f, 9.027871f, -2.913095f },	{ 0.568727f, 0.377775f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.995563f, 10.527871f, -2.913095f },	{ 0.674725f, 0.377775f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.548563f, 10.256143f, -2.913095f },	{ 0.674725f, 0.483773f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.548563f, 10.527871f, -2.913095f },	{ 0.626028f, 0.335145f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.995563f, 10.527871f, -2.913095f },	{ 0.584706f, 0.335145f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.995563f, 10.527871f, -3.505670f },	{ 0.584706f, 0.280365f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.548563f, 10.527871f, -3.505670f },	{ 0.626028f, 0.280365f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.548563f, 10.256143f, -3.505670f },	{ 0.754895f, 0.903471f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.995563f, 10.527871f, -3.505670f },	{ 0.810952f, 0.995686f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.995563f, 9.027871f, -3.505670f },	{ 0.501505f, 0.995686f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.548563f, 9.299600f, -3.505670f },	{ 0.557562f, 0.903471f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.548563f, 9.027871f, -3.505670f },	{ 0.626028f, 0.280365f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.995563f, 9.027871f, -3.505670f },	{ 0.584706f, 0.280365f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.995563f, 9.027871f, -2.913095f },	{ 0.584706f, 0.335145f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.548563f, 9.027871f, -2.913095f },	{ 0.626028f, 0.335145f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -1.398437f, 10.527871f, -2.913095f },	{ 0.568727f, 0.377775f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.398437f, 9.027871f, -2.913095f },	{ 0.674725f, 0.377775f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -0.951437f, 9.299600f, -2.913095f },	{ 0.674725f, 0.483773f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -0.951437f, 9.027871f, -2.913095f },	{ 0.638144f, 0.336708f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -1.398437f, 9.027871f, -2.913095f },	{ 0.679466f, 0.336708f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -1.398437f, 9.027871f, -3.505670f },	{ 0.679466f, 0.281928f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -0.951437f, 9.027871f, -3.505670f },	{ 0.638144f, 0.281928f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -0.951437f, 9.299600f, -3.505670f },	{ 0.557562f, 0.594024f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.398437f, 9.027871f, -3.505670f },	{ 0.501505f, 0.501809f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.951437f, 10.527871f, -3.505670f },	{ 0.638144f, 0.281928f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -1.398437f, 10.527871f, -3.505670f },	{ 0.679466f, 0.281928f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -1.398437f, 10.527871f, -2.913095f },	{ 0.679466f, 0.336708f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.951437f, 10.527871f, -2.913095f },	{ 0.638144f, 0.336708f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.548563f, 10.256143f, -2.913095f },	{ 0.700938f, 0.324765f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.548563f, 10.527871f, -2.913095f },	{ 0.742663f, 0.324765f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.548563f, 10.527871f, -3.505670f },	{ 0.742663f, 0.233772f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.548563f, 10.256143f, -3.505670f },	{ 0.700938f, 0.233772f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.548563f, 10.527871f, -3.505670f },	{ 0.810952f, 0.903471f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.951437f, 9.299600f, -2.913095f },	{ 0.554056f, 0.324765f, 0.000000f },	{ 1.000000f, 0.000000f, 0.000000f }	},
	{	{ -0.951437f, 9.027871f, -2.913095f },	{ 0.512330f, 0.324765f, 0.000000f },	{ 1.000000f, 0.000000f, 0.000000f }	},
	{	{ -0.951437f, 9.027871f, -3.505670f },	{ 0.512330f, 0.233772f, 0.000000f },	{ 1.000000f, 0.000000f, 0.000000f }	},
	{	{ -0.951437f, 9.299600f, -3.505670f },	{ 0.554056f, 0.233772f, 0.000000f },	{ 1.000000f, 0.000000f, 0.000000f }	},
	{	{ 0.548563f, 10.256143f, -2.913095f },	{ 0.674725f, 0.377775f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.995563f, 10.527871f, -2.913095f },	{ 0.568727f, 0.483773f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.548563f, 10.527871f, -2.913095f },	{ 0.568727f, 0.377775f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.548563f, 9.299600f, -3.505670f },	{ 0.554056f, 0.233772f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.548563f, 9.027871f, -3.505670f },	{ 0.512330f, 0.233772f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.548563f, 9.027871f, -2.913095f },	{ 0.512330f, 0.324765f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.548563f, 9.299600f, -2.913095f },	{ 0.554056f, 0.324765f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.995563f, 9.027871f, -2.913095f },	{ 0.674725f, 0.377775f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.548563f, 9.027871f, -2.913095f },	{ 0.568727f, 0.377775f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -0.951437f, 9.027871f, -3.505670f },	{ 0.501505f, 0.594024f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.548563f, 9.027871f, -3.505670f },	{ 0.501505f, 0.903471f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
};
#define _arch_vertices_
#endif
#ifndef _arch_indices_
// Index Data follows: Sequential by mesh, Every Three Indices == One Triangle.
const unsigned int arch_indices[228] =
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
	 24, 25, 26,
	 27, 24, 26,
	 15, 28, 29,
	 12, 15, 29,
	 30, 31, 32,
	 33, 30, 32,
	 34, 35, 36,
	 37, 34, 36,
	 28, 38, 39,
	 29, 28, 39,
	 40, 41, 42,
	 43, 40, 42,
	 6, 44, 45,
	 7, 6, 45,
	 46, 47, 48,
	 49, 46, 48,
	 50, 51, 52,
	 53, 50, 52,
	 27, 54, 55,
	 24, 27, 55,
	 56, 57, 58,
	 59, 56, 58,
	 60, 61, 62,
	 63, 60, 62,
	 38, 40, 43,
	 39, 38, 43,
	 44, 26, 25,
	 45, 44, 25,
	 64, 65, 66,
	 67, 64, 66,
	 68, 69, 70,
	 71, 68, 70,
	 72, 73, 74,
	 75, 72, 74,
	 76, 77, 78,
	 79, 80, 81,
	 82, 83, 84,
	 85, 86, 87,
	 88, 85, 87,
	 89, 90, 91,
	 92, 89, 91,
	 93, 94, 95,
	 96, 93, 95,
	 97, 98, 99,
	 100, 97, 99,
	 77, 101, 102,
	 103, 77, 102,
	 104, 105, 106,
	 107, 104, 106,
	 108, 109, 83,
	 82, 108, 83,
	 110, 111, 112,
	 113, 110, 112,
	 114, 115, 116,
	 117, 114, 116,
	 94, 93, 118,
	 119, 120, 121,
	 122, 119, 121,
	 123, 124, 125,
	 126, 127, 128,
	 129, 126, 128,
	 130, 85, 131,
	 109, 108, 132,
	 96, 95, 133,
};
#define _arch_indices_
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
#ifndef _arch_materials_
// Material Data follows: pulled from a .mtl file of the same name if present.
const OBJ_MATERIAL arch_materials[1] =
{
	{
		{{ 0.800000f, 0.800000f, 0.800000f },
		1.000000f,
		{ 0.800000f, 0.800000f, 0.800000f },
		500.000000f,
		{ 0.800000f, 0.800000f, 0.800000f },
		60.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		1.500000f,
		{ 0.000000f, 0.000000f, 0.000000f },
		2},
		"None",
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
#define _arch_materials_
#endif
/************************************************/
/*  This section contains the model's structure */
/************************************************/
#ifndef _arch_batches_
// Use this conveinence array to batch render all geometry by like material.
// Each entry corresponds to the same entry in the materials array above.
// The two numbers provided are the IndexCount and the IndexOffset into the indices array.
// If you need more fine grained control(ex: for transformations) use the OBJ_MESH data below.
const unsigned int arch_batches[1][2] =
{
	{ 228, 0 },
};
#define _arch_batches_
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
#ifndef _arch_meshes_
// Mesh Data follows: Meshes are .obj groups sorted & split by material.
// Meshes are provided in sequential order, sorted by material first and name second.
const OBJ_MESH arch_meshes[1] =
{
	{
		"default",
		228,
		0,
		0,
	},
};
#define _arch_meshes_
#endif
