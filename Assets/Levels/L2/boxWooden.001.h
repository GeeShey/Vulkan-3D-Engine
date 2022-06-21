// "boxWooden.001.h" generated by "Obj2Header.exe" [Version 1.9d] Author: L.Norri Fullsail University.
// Data is converted to left-handed coordinate system and UV data is V flipped for Direct3D/Vulkan.
// The companion file "boxWooden.001.h2b" is a binary dump of this format(-padding) for more flexibility.
// Loading *.h2b: read version, sizes, handle strings(max len 260) by reading until null-terminated.
/***********************/
/*  Generator version  */
/***********************/
#ifndef _boxWooden_001_version_
const char boxWooden_001_version[4] = { '0','1','9','d' };
#define _boxWooden_001_version_
#endif
/************************************************/
/*  This section contains the model's size data */
/************************************************/
#ifndef _boxWooden_001_vertexcount_
const unsigned boxWooden_001_vertexcount = 96;
#define _boxWooden_001_vertexcount_
#endif
#ifndef _boxWooden_001_indexcount_
const unsigned boxWooden_001_indexcount = 132;
#define _boxWooden_001_indexcount_
#endif
#ifndef _boxWooden_001_materialcount_
const unsigned boxWooden_001_materialcount = 1; // can be used for batched draws
#define _boxWooden_001_materialcount_
#endif
#ifndef _boxWooden_001_meshcount_
const unsigned boxWooden_001_meshcount = 1;
#define _boxWooden_001_meshcount_
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
#ifndef _boxWooden_001_vertices_
// Raw Vertex Data follows: Positions, Texture Coordinates and Normals.
const OBJ_VERT boxWooden_001_vertices[96] =
{
	{	{ 0.202971f, 0.142456f, 0.165885f },	{ 0.250269f, 0.625514f, 0.000000f },	{ 0.224100f, 0.974600f, 0.000000f }	},
	{	{ 0.202971f, 0.142456f, -0.165885f },	{ 0.250269f, 0.375156f, 0.000000f },	{ 0.224100f, 0.974600f, 0.000000f }	},
	{	{ -0.120362f, 0.216803f, -0.165885f },	{ 0.500627f, 0.375156f, 0.000000f },	{ 0.224100f, 0.974600f, 0.000000f }	},
	{	{ -0.120362f, 0.216803f, 0.165885f },	{ 0.500627f, 0.625514f, 0.000000f },	{ 0.224100f, 0.974600f, 0.000000f }	},
	{	{ -0.142456f, 0.202971f, 0.165885f },	{ 0.500003f, 0.625201f, 0.000000f },	{ -0.974600f, 0.224100f, -0.000000f }	},
	{	{ -0.142456f, 0.202971f, -0.165885f },	{ 0.500003f, 0.374843f, 0.000000f },	{ -0.974600f, 0.224100f, -0.000000f }	},
	{	{ -0.216803f, -0.120362f, -0.165885f },	{ 0.750361f, 0.374843f, 0.000000f },	{ -0.974600f, 0.224100f, -0.000000f }	},
	{	{ -0.216803f, -0.120362f, 0.165885f },	{ 0.750361f, 0.625201f, 0.000000f },	{ -0.974600f, 0.224100f, -0.000000f }	},
	{	{ -0.202971f, -0.142456f, 0.165885f },	{ 0.750361f, 0.625201f, 0.000000f },	{ -0.224100f, -0.974600f, -0.000000f }	},
	{	{ -0.202971f, -0.142456f, -0.165885f },	{ 0.750361f, 0.375890f, 0.000000f },	{ -0.224100f, -0.974600f, -0.000000f }	},
	{	{ 0.120362f, -0.216803f, -0.165885f },	{ 0.999672f, 0.375890f, 0.000000f },	{ -0.224100f, -0.974600f, -0.000000f }	},
	{	{ 0.120362f, -0.216803f, 0.165885f },	{ 0.999672f, 0.625201f, 0.000000f },	{ -0.224100f, -0.974600f, -0.000000f }	},
	{	{ 0.142456f, -0.202971f, 0.165885f },	{ -0.000089f, 0.625514f, 0.000000f },	{ 0.974600f, -0.224100f, 0.000000f }	},
	{	{ 0.142456f, -0.202971f, -0.165885f },	{ -0.000089f, 0.375156f, 0.000000f },	{ 0.974600f, -0.224100f, 0.000000f }	},
	{	{ 0.216803f, 0.120362f, -0.165885f },	{ 0.250269f, 0.375156f, 0.000000f },	{ 0.974600f, -0.224100f, 0.000000f }	},
	{	{ 0.216803f, 0.120362f, 0.165885f },	{ 0.250269f, 0.625514f, 0.000000f },	{ 0.974600f, -0.224100f, 0.000000f }	},
	{	{ 0.198840f, 0.124493f, -0.184317f },	{ 0.250269f, 0.375156f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.124493f, -0.198840f, -0.184317f },	{ 0.250269f, 0.124798f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.198840f, -0.124493f, -0.184317f },	{ 0.500627f, 0.124798f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.124493f, 0.198840f, -0.184317f },	{ 0.500627f, 0.375156f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.124493f, -0.198840f, 0.184317f },	{ 0.250269f, 0.875872f, 0.000000f },	{ -0.000000f, -0.000000f, 1.000000f }	},
	{	{ 0.198840f, 0.124493f, 0.184317f },	{ 0.250269f, 0.625514f, 0.000000f },	{ -0.000000f, -0.000000f, 1.000000f }	},
	{	{ -0.124493f, 0.198840f, 0.184317f },	{ 0.500627f, 0.625514f, 0.000000f },	{ -0.000000f, -0.000000f, 1.000000f }	},
	{	{ -0.198840f, -0.124493f, 0.184317f },	{ 0.500627f, 0.875872f, 0.000000f },	{ -0.000000f, -0.000000f, 1.000000f }	},
	{	{ 0.202971f, 0.142456f, 0.165885f },	{ 0.545472f, 0.345756f, 0.000000f },	{ 0.847600f, 0.530700f, 0.000000f }	},
	{	{ 0.216803f, 0.120362f, 0.165885f },	{ 0.545472f, 0.170616f, 0.000000f },	{ 0.847600f, 0.530700f, 0.000000f }	},
	{	{ 0.216803f, 0.120362f, -0.165885f },	{ 0.720613f, 0.170616f, 0.000000f },	{ 0.847600f, 0.530700f, 0.000000f }	},
	{	{ 0.202971f, 0.142456f, -0.165885f },	{ 0.720613f, 0.345756f, 0.000000f },	{ 0.847600f, 0.530700f, 0.000000f }	},
	{	{ 0.202971f, 0.142456f, -0.165885f },	{ 0.545472f, 0.345756f, 0.000000f },	{ 0.158500f, 0.689100f, -0.707100f }	},
	{	{ 0.198840f, 0.124493f, -0.184317f },	{ 0.545472f, 0.170616f, 0.000000f },	{ 0.158500f, 0.689100f, -0.707100f }	},
	{	{ -0.124493f, 0.198840f, -0.184317f },	{ 0.720613f, 0.170616f, 0.000000f },	{ 0.158500f, 0.689100f, -0.707100f }	},
	{	{ -0.120362f, 0.216803f, -0.165885f },	{ 0.720613f, 0.345756f, 0.000000f },	{ 0.158500f, 0.689100f, -0.707100f }	},
	{	{ -0.142456f, 0.202971f, 0.165885f },	{ 0.545472f, 0.345756f, 0.000000f },	{ -0.530700f, 0.847600f, 0.000000f }	},
	{	{ -0.120362f, 0.216803f, 0.165885f },	{ 0.545472f, 0.170616f, 0.000000f },	{ -0.530700f, 0.847600f, 0.000000f }	},
	{	{ -0.120362f, 0.216803f, -0.165885f },	{ 0.720613f, 0.170616f, 0.000000f },	{ -0.530700f, 0.847600f, 0.000000f }	},
	{	{ -0.142456f, 0.202971f, -0.165885f },	{ 0.720613f, 0.345756f, 0.000000f },	{ -0.530700f, 0.847600f, 0.000000f }	},
	{	{ 0.198840f, 0.124493f, 0.184317f },	{ 0.545472f, 0.345756f, 0.000000f },	{ 0.158500f, 0.689100f, 0.707100f }	},
	{	{ 0.202971f, 0.142456f, 0.165885f },	{ 0.545472f, 0.170616f, 0.000000f },	{ 0.158500f, 0.689100f, 0.707100f }	},
	{	{ -0.120362f, 0.216803f, 0.165885f },	{ 0.720613f, 0.170616f, 0.000000f },	{ 0.158500f, 0.689100f, 0.707100f }	},
	{	{ -0.124493f, 0.198840f, 0.184317f },	{ 0.720613f, 0.345756f, 0.000000f },	{ 0.158500f, 0.689100f, 0.707100f }	},
	{	{ -0.142456f, 0.202971f, -0.165885f },	{ 0.545472f, 0.345756f, 0.000000f },	{ -0.689100f, 0.158500f, -0.707100f }	},
	{	{ -0.124493f, 0.198840f, -0.184317f },	{ 0.545472f, 0.170616f, 0.000000f },	{ -0.689100f, 0.158500f, -0.707100f }	},
	{	{ -0.198840f, -0.124493f, -0.184317f },	{ 0.720613f, 0.170616f, 0.000000f },	{ -0.689100f, 0.158500f, -0.707100f }	},
	{	{ -0.216803f, -0.120362f, -0.165885f },	{ 0.720613f, 0.345756f, 0.000000f },	{ -0.689100f, 0.158500f, -0.707100f }	},
	{	{ -0.202971f, -0.142456f, 0.165885f },	{ 0.545472f, 0.345756f, 0.000000f },	{ -0.847600f, -0.530700f, -0.000000f }	},
	{	{ -0.216803f, -0.120362f, 0.165885f },	{ 0.545472f, 0.170616f, 0.000000f },	{ -0.847600f, -0.530700f, -0.000000f }	},
	{	{ -0.216803f, -0.120362f, -0.165885f },	{ 0.720613f, 0.170616f, 0.000000f },	{ -0.847600f, -0.530700f, -0.000000f }	},
	{	{ -0.202971f, -0.142456f, -0.165885f },	{ 0.720613f, 0.345756f, 0.000000f },	{ -0.847600f, -0.530700f, -0.000000f }	},
	{	{ -0.124493f, 0.198840f, 0.184317f },	{ 0.545472f, 0.345756f, 0.000000f },	{ -0.689100f, 0.158500f, 0.707100f }	},
	{	{ -0.142456f, 0.202971f, 0.165885f },	{ 0.545472f, 0.170616f, 0.000000f },	{ -0.689100f, 0.158500f, 0.707100f }	},
	{	{ -0.216803f, -0.120362f, 0.165885f },	{ 0.720613f, 0.170616f, 0.000000f },	{ -0.689100f, 0.158500f, 0.707100f }	},
	{	{ -0.198840f, -0.124493f, 0.184317f },	{ 0.720613f, 0.345756f, 0.000000f },	{ -0.689100f, 0.158500f, 0.707100f }	},
	{	{ -0.202971f, -0.142456f, -0.165885f },	{ 0.545472f, 0.345756f, 0.000000f },	{ -0.158500f, -0.689100f, -0.707100f }	},
	{	{ -0.198840f, -0.124493f, -0.184317f },	{ 0.545472f, 0.170616f, 0.000000f },	{ -0.158500f, -0.689100f, -0.707100f }	},
	{	{ 0.124493f, -0.198840f, -0.184317f },	{ 0.720613f, 0.170616f, 0.000000f },	{ -0.158500f, -0.689100f, -0.707100f }	},
	{	{ 0.120362f, -0.216803f, -0.165885f },	{ 0.720613f, 0.345756f, 0.000000f },	{ -0.158500f, -0.689100f, -0.707100f }	},
	{	{ 0.142456f, -0.202971f, 0.165885f },	{ 0.545472f, 0.345756f, 0.000000f },	{ 0.530700f, -0.847600f, -0.000000f }	},
	{	{ 0.120362f, -0.216803f, 0.165885f },	{ 0.545472f, 0.170616f, 0.000000f },	{ 0.530700f, -0.847600f, -0.000000f }	},
	{	{ 0.120362f, -0.216803f, -0.165885f },	{ 0.720613f, 0.170616f, 0.000000f },	{ 0.530700f, -0.847600f, -0.000000f }	},
	{	{ 0.142456f, -0.202971f, -0.165885f },	{ 0.720613f, 0.345756f, 0.000000f },	{ 0.530700f, -0.847600f, -0.000000f }	},
	{	{ -0.198840f, -0.124493f, 0.184317f },	{ 0.545472f, 0.345756f, 0.000000f },	{ -0.158500f, -0.689100f, 0.707100f }	},
	{	{ -0.202971f, -0.142456f, 0.165885f },	{ 0.545472f, 0.170616f, 0.000000f },	{ -0.158500f, -0.689100f, 0.707100f }	},
	{	{ 0.120362f, -0.216803f, 0.165885f },	{ 0.720613f, 0.170616f, 0.000000f },	{ -0.158500f, -0.689100f, 0.707100f }	},
	{	{ 0.124493f, -0.198840f, 0.184317f },	{ 0.720613f, 0.345756f, 0.000000f },	{ -0.158500f, -0.689100f, 0.707100f }	},
	{	{ 0.198840f, 0.124493f, -0.184317f },	{ 0.545472f, 0.345756f, 0.000000f },	{ 0.689100f, -0.158500f, -0.707100f }	},
	{	{ 0.216803f, 0.120362f, -0.165885f },	{ 0.545472f, 0.170616f, 0.000000f },	{ 0.689100f, -0.158500f, -0.707100f }	},
	{	{ 0.142456f, -0.202971f, -0.165885f },	{ 0.720613f, 0.170616f, 0.000000f },	{ 0.689100f, -0.158500f, -0.707100f }	},
	{	{ 0.124493f, -0.198840f, -0.184317f },	{ 0.720613f, 0.345756f, 0.000000f },	{ 0.689100f, -0.158500f, -0.707100f }	},
	{	{ 0.216803f, 0.120362f, 0.165885f },	{ 0.545472f, 0.345756f, 0.000000f },	{ 0.689100f, -0.158500f, 0.707100f }	},
	{	{ 0.198840f, 0.124493f, 0.184317f },	{ 0.545472f, 0.170616f, 0.000000f },	{ 0.689100f, -0.158500f, 0.707100f }	},
	{	{ 0.124493f, -0.198840f, 0.184317f },	{ 0.720613f, 0.170616f, 0.000000f },	{ 0.689100f, -0.158500f, 0.707100f }	},
	{	{ 0.142456f, -0.202971f, 0.165885f },	{ 0.720613f, 0.345756f, 0.000000f },	{ 0.689100f, -0.158500f, 0.707100f }	},
	{	{ 0.142456f, -0.202971f, 0.165885f },	{ 0.720613f, 0.170616f, 0.000000f },	{ 0.433300f, -0.692000f, 0.577300f }	},
	{	{ 0.124493f, -0.198840f, 0.184317f },	{ 0.545472f, 0.345756f, 0.000000f },	{ 0.433300f, -0.692000f, 0.577300f }	},
	{	{ 0.120362f, -0.216803f, 0.165885f },	{ 0.545472f, 0.170616f, 0.000000f },	{ 0.433300f, -0.692000f, 0.577300f }	},
	{	{ 0.202971f, 0.142456f, 0.165885f },	{ 0.720613f, 0.170616f, 0.000000f },	{ 0.692000f, 0.433300f, 0.577400f }	},
	{	{ 0.198840f, 0.124493f, 0.184317f },	{ 0.545472f, 0.345756f, 0.000000f },	{ 0.692000f, 0.433300f, 0.577400f }	},
	{	{ 0.216803f, 0.120362f, 0.165885f },	{ 0.545472f, 0.170616f, 0.000000f },	{ 0.692000f, 0.433300f, 0.577400f }	},
	{	{ -0.142456f, 0.202971f, 0.165885f },	{ 0.720613f, 0.170616f, 0.000000f },	{ -0.433300f, 0.692000f, 0.577400f }	},
	{	{ -0.124493f, 0.198840f, 0.184317f },	{ 0.545472f, 0.345756f, 0.000000f },	{ -0.433300f, 0.692000f, 0.577400f }	},
	{	{ -0.120362f, 0.216803f, 0.165885f },	{ 0.545472f, 0.170616f, 0.000000f },	{ -0.433300f, 0.692000f, 0.577400f }	},
	{	{ -0.202971f, -0.142456f, 0.165885f },	{ 0.720613f, 0.170616f, 0.000000f },	{ -0.692000f, -0.433300f, 0.577300f }	},
	{	{ -0.198840f, -0.124493f, 0.184317f },	{ 0.545472f, 0.345756f, 0.000000f },	{ -0.692000f, -0.433300f, 0.577300f }	},
	{	{ -0.216803f, -0.120362f, 0.165885f },	{ 0.545472f, 0.170616f, 0.000000f },	{ -0.692000f, -0.433300f, 0.577300f }	},
	{	{ 0.124493f, -0.198840f, -0.184317f },	{ 0.720613f, 0.170616f, 0.000000f },	{ 0.433300f, -0.692000f, -0.577400f }	},
	{	{ 0.142456f, -0.202971f, -0.165885f },	{ 0.545472f, 0.345756f, 0.000000f },	{ 0.433300f, -0.692000f, -0.577400f }	},
	{	{ 0.120362f, -0.216803f, -0.165885f },	{ 0.545472f, 0.170616f, 0.000000f },	{ 0.433300f, -0.692000f, -0.577400f }	},
	{	{ 0.202971f, 0.142456f, -0.165885f },	{ 0.720613f, 0.170616f, 0.000000f },	{ 0.692000f, 0.433300f, -0.577400f }	},
	{	{ 0.216803f, 0.120362f, -0.165885f },	{ 0.545472f, 0.345756f, 0.000000f },	{ 0.692000f, 0.433300f, -0.577400f }	},
	{	{ 0.198840f, 0.124493f, -0.184317f },	{ 0.545472f, 0.170616f, 0.000000f },	{ 0.692000f, 0.433300f, -0.577400f }	},
	{	{ -0.142456f, 0.202971f, -0.165885f },	{ 0.720613f, 0.170616f, 0.000000f },	{ -0.433300f, 0.692000f, -0.577300f }	},
	{	{ -0.120362f, 0.216803f, -0.165885f },	{ 0.545472f, 0.345756f, 0.000000f },	{ -0.433300f, 0.692000f, -0.577300f }	},
	{	{ -0.124493f, 0.198840f, -0.184317f },	{ 0.545472f, 0.170616f, 0.000000f },	{ -0.433300f, 0.692000f, -0.577300f }	},
	{	{ -0.216803f, -0.120362f, -0.165885f },	{ 0.720613f, 0.170616f, 0.000000f },	{ -0.692000f, -0.433300f, -0.577400f }	},
	{	{ -0.198840f, -0.124493f, -0.184317f },	{ 0.545472f, 0.345756f, 0.000000f },	{ -0.692000f, -0.433300f, -0.577400f }	},
	{	{ -0.202971f, -0.142456f, -0.165885f },	{ 0.545472f, 0.170616f, 0.000000f },	{ -0.692000f, -0.433300f, -0.577400f }	},
};
#define _boxWooden_001_vertices_
#endif
#ifndef _boxWooden_001_indices_
// Index Data follows: Sequential by mesh, Every Three Indices == One Triangle.
const unsigned int boxWooden_001_indices[132] =
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
	 28, 29, 30,
	 31, 28, 30,
	 32, 33, 34,
	 35, 32, 34,
	 36, 37, 38,
	 39, 36, 38,
	 40, 41, 42,
	 43, 40, 42,
	 44, 45, 46,
	 47, 44, 46,
	 48, 49, 50,
	 51, 48, 50,
	 52, 53, 54,
	 55, 52, 54,
	 56, 57, 58,
	 59, 56, 58,
	 60, 61, 62,
	 63, 60, 62,
	 64, 65, 66,
	 67, 64, 66,
	 68, 69, 70,
	 71, 68, 70,
	 72, 73, 74,
	 75, 76, 77,
	 78, 79, 80,
	 81, 82, 83,
	 84, 85, 86,
	 87, 88, 89,
	 90, 91, 92,
	 93, 94, 95,
};
#define _boxWooden_001_indices_
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
#ifndef _boxWooden_001_materials_
// Material Data follows: pulled from a .mtl file of the same name if present.
const OBJ_MATERIAL boxWooden_001_materials[1] =
{
	{
		{{ 0.800000f, 0.198976f, 0.706667f },
		1.000000f,
		{ 0.500000f, 0.500000f, 0.500000f },
		225.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		60.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		1.450000f,
		{ 0.000000f, 0.000000f, 0.000000f },
		2},
		"Material.010",
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
#define _boxWooden_001_materials_
#endif
/************************************************/
/*  This section contains the model's structure */
/************************************************/
#ifndef _boxWooden_001_batches_
// Use this conveinence array to batch render all geometry by like material.
// Each entry corresponds to the same entry in the materials array above.
// The two numbers provided are the IndexCount and the IndexOffset into the indices array.
// If you need more fine grained control(ex: for transformations) use the OBJ_MESH data below.
const unsigned int boxWooden_001_batches[1][2] =
{
	{ 132, 0 },
};
#define _boxWooden_001_batches_
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
#ifndef _boxWooden_001_meshes_
// Mesh Data follows: Meshes are .obj groups sorted & split by material.
// Meshes are provided in sequential order, sorted by material first and name second.
const OBJ_MESH boxWooden_001_meshes[1] =
{
	{
		"default",
		132,
		0,
		0,
	},
};
#define _boxWooden_001_meshes_
#endif
