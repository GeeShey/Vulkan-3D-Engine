// "pillar01.h" generated by "Obj2Header.exe" [Version 1.9d] Author: L.Norri Fullsail University.
// Data is converted to left-handed coordinate system and UV data is V flipped for Direct3D/Vulkan.
// The companion file "pillar01.h2b" is a binary dump of this format(-padding) for more flexibility.
// Loading *.h2b: read version, sizes, handle strings(max len 260) by reading until null-terminated.
/***********************/
/*  Generator version  */
/***********************/
#ifndef _pillar01_version_
const char pillar01_version[4] = { '0','1','9','d' };
#define _pillar01_version_
#endif
/************************************************/
/*  This section contains the model's size data */
/************************************************/
#ifndef _pillar01_vertexcount_
const unsigned pillar01_vertexcount = 178;
#define _pillar01_vertexcount_
#endif
#ifndef _pillar01_indexcount_
const unsigned pillar01_indexcount = 276;
#define _pillar01_indexcount_
#endif
#ifndef _pillar01_materialcount_
const unsigned pillar01_materialcount = 1; // can be used for batched draws
#define _pillar01_materialcount_
#endif
#ifndef _pillar01_meshcount_
const unsigned pillar01_meshcount = 1;
#define _pillar01_meshcount_
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
#ifndef _pillar01_vertices_
// Raw Vertex Data follows: Positions, Texture Coordinates and Normals.
const OBJ_VERT pillar01_vertices[178] =
{
	{	{ 0.401876f, 0.375054f, -0.349757f },	{ 0.071193f, 0.423618f, 0.000000f },	{ 0.948100f, 0.000000f, -0.317900f }	},
	{	{ 0.401876f, 0.925075f, -0.349757f },	{ 0.071193f, 0.291640f, 0.000000f },	{ 0.948100f, 0.000000f, -0.317900f }	},
	{	{ 0.531485f, 0.925075f, 0.036854f },	{ 0.203171f, 0.291640f, 0.000000f },	{ 0.948100f, 0.000000f, -0.317900f }	},
	{	{ 0.531485f, 0.375054f, 0.036854f },	{ 0.203171f, 0.423618f, 0.000000f },	{ 0.948100f, 0.000000f, -0.317900f }	},
	{	{ -0.648507f, -0.000000f, -0.044968f },	{ 0.076384f, 0.691236f, 0.000000f },	{ -0.895200f, 0.000000f, -0.445700f }	},
	{	{ -0.648507f, 0.375054f, -0.044968f },	{ 0.076384f, 0.559258f, 0.000000f },	{ -0.895200f, 0.000000f, -0.445700f }	},
	{	{ -0.426767f, 0.375054f, -0.490361f },	{ 0.208362f, 0.559258f, 0.000000f },	{ -0.895200f, 0.000000f, -0.445700f }	},
	{	{ -0.426767f, 0.000000f, -0.490361f },	{ 0.208362f, 0.691236f, 0.000000f },	{ -0.895200f, 0.000000f, -0.445700f }	},
	{	{ 0.648507f, 0.000000f, 0.044968f },	{ 0.071193f, 0.427089f, 0.000000f },	{ 0.895200f, -0.000000f, 0.445700f }	},
	{	{ 0.648507f, 0.375054f, 0.044968f },	{ 0.071193f, 0.295112f, 0.000000f },	{ 0.895200f, -0.000000f, 0.445700f }	},
	{	{ 0.426767f, 0.375054f, 0.490361f },	{ 0.203171f, 0.295112f, 0.000000f },	{ 0.895200f, -0.000000f, 0.445700f }	},
	{	{ 0.426767f, -0.000000f, 0.490361f },	{ 0.203171f, 0.427089f, 0.000000f },	{ 0.895200f, -0.000000f, 0.445700f }	},
	{	{ 0.426767f, -0.000000f, 0.490361f },	{ 0.292896f, 0.202411f, 0.000000f },	{ 0.317900f, -0.000000f, 0.948100f }	},
	{	{ 0.426767f, 0.375054f, 0.490361f },	{ 0.292896f, 0.070434f, 0.000000f },	{ 0.317900f, -0.000000f, 0.948100f }	},
	{	{ -0.044968f, 0.375054f, 0.648507f },	{ 0.424873f, 0.070434f, 0.000000f },	{ 0.317900f, -0.000000f, 0.948100f }	},
	{	{ -0.044968f, -0.000000f, 0.648507f },	{ 0.424873f, 0.202411f, 0.000000f },	{ 0.317900f, -0.000000f, 0.948100f }	},
	{	{ -0.426767f, 0.000000f, -0.490361f },	{ 0.312984f, 0.702396f, 0.000000f },	{ -0.317900f, 0.000000f, -0.948100f }	},
	{	{ -0.426767f, 0.375054f, -0.490361f },	{ 0.312984f, 0.570419f, 0.000000f },	{ -0.317900f, 0.000000f, -0.948100f }	},
	{	{ 0.044968f, 0.375054f, -0.648507f },	{ 0.444962f, 0.570419f, 0.000000f },	{ -0.317900f, 0.000000f, -0.948100f }	},
	{	{ 0.044968f, 0.000000f, -0.648507f },	{ 0.444962f, 0.702396f, 0.000000f },	{ -0.317900f, 0.000000f, -0.948100f }	},
	{	{ -0.044968f, -0.000000f, 0.648507f },	{ 0.292896f, 0.202411f, 0.000000f },	{ -0.445700f, -0.000000f, 0.895200f }	},
	{	{ -0.044968f, 0.375054f, 0.648507f },	{ 0.292896f, 0.070434f, 0.000000f },	{ -0.445700f, -0.000000f, 0.895200f }	},
	{	{ -0.490361f, 0.375054f, 0.426767f },	{ 0.424873f, 0.070434f, 0.000000f },	{ -0.445700f, -0.000000f, 0.895200f }	},
	{	{ -0.490361f, -0.000000f, 0.426767f },	{ 0.424873f, 0.202411f, 0.000000f },	{ -0.445700f, -0.000000f, 0.895200f }	},
	{	{ -0.490361f, 0.925075f, 0.426767f },	{ 0.333318f, 0.437505f, 0.000000f },	{ -0.948100f, -0.000000f, 0.317900f }	},
	{	{ -0.490361f, 1.300129f, 0.426767f },	{ 0.333318f, 0.305527f, 0.000000f },	{ -0.948100f, -0.000000f, 0.317900f }	},
	{	{ -0.648507f, 1.300129f, -0.044968f },	{ 0.465296f, 0.305527f, 0.000000f },	{ -0.948100f, -0.000000f, 0.317900f }	},
	{	{ -0.648507f, 0.925075f, -0.044968f },	{ 0.465296f, 0.437505f, 0.000000f },	{ -0.948100f, -0.000000f, 0.317900f }	},
	{	{ 0.044968f, 0.000000f, -0.648507f },	{ 0.075162f, 0.947162f, 0.000000f },	{ 0.445700f, 0.000000f, -0.895200f }	},
	{	{ 0.044968f, 0.375054f, -0.648507f },	{ 0.075162f, 0.815184f, 0.000000f },	{ 0.445700f, 0.000000f, -0.895200f }	},
	{	{ 0.490361f, 0.375054f, -0.426767f },	{ 0.207140f, 0.815184f, 0.000000f },	{ 0.445700f, 0.000000f, -0.895200f }	},
	{	{ 0.490361f, 0.000000f, -0.426767f },	{ 0.207140f, 0.947162f, 0.000000f },	{ 0.445700f, 0.000000f, -0.895200f }	},
	{	{ -0.044968f, -0.000000f, 0.648507f },	{ 0.295128f, 0.197947f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -0.426767f, 0.000000f, -0.490361f },	{ 0.295128f, 0.065970f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.044968f, 0.000000f, -0.648507f },	{ 0.427105f, 0.065970f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.426767f, -0.000000f, 0.490361f },	{ 0.427105f, 0.197947f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -0.648507f, -0.000000f, -0.044968f },	{ 0.295128f, 0.197947f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -0.044968f, -0.000000f, 0.648507f },	{ 0.427105f, 0.065970f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -0.490361f, -0.000000f, 0.426767f },	{ 0.427105f, 0.197947f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.044968f, 0.000000f, -0.648507f },	{ 0.295128f, 0.197947f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.490361f, 0.000000f, -0.426767f },	{ 0.295128f, 0.065970f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.648507f, 0.000000f, 0.044968f },	{ 0.427105f, 0.065970f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.426767f, 1.300129f, 0.490361f },	{ 0.321797f, 1.003761f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.648507f, 1.300129f, 0.044968f },	{ 0.249777f, 0.931428f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.490361f, 1.300129f, -0.426766f },	{ 0.249999f, 0.829355f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.044968f, 1.300129f, -0.648507f },	{ 0.322332f, 0.757335f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.426767f, 1.300129f, -0.490361f },	{ 0.424405f, 0.757557f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.648507f, 1.300129f, -0.044968f },	{ 0.496424f, 0.829890f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.490361f, 1.300129f, 0.426767f },	{ 0.496203f, 0.931962f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.044968f, 1.300129f, 0.648507f },	{ 0.423870f, 1.003982f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.648507f, 0.375054f, 0.044968f },	{ 0.076384f, 0.691236f, 0.000000f },	{ 0.948100f, 0.000000f, -0.317900f }	},
	{	{ 0.648507f, 0.000000f, 0.044968f },	{ 0.076384f, 0.559258f, 0.000000f },	{ 0.948100f, 0.000000f, -0.317900f }	},
	{	{ 0.490361f, 0.000000f, -0.426767f },	{ 0.208362f, 0.559258f, 0.000000f },	{ 0.948100f, 0.000000f, -0.317900f }	},
	{	{ 0.490361f, 0.375054f, -0.426767f },	{ 0.208362f, 0.691236f, 0.000000f },	{ 0.948100f, 0.000000f, -0.317900f }	},
	{	{ -0.531485f, 0.375054f, -0.036854f },	{ 0.065985f, 0.435769f, 0.000000f },	{ -0.895200f, 0.000000f, -0.445700f }	},
	{	{ -0.531485f, 0.925075f, -0.036853f },	{ 0.065985f, 0.303792f, 0.000000f },	{ -0.895200f, 0.000000f, -0.445700f }	},
	{	{ -0.349757f, 0.925075f, -0.401876f },	{ 0.197963f, 0.303792f, 0.000000f },	{ -0.895200f, 0.000000f, -0.445700f }	},
	{	{ -0.349757f, 0.375054f, -0.401876f },	{ 0.197963f, 0.435769f, 0.000000f },	{ -0.895200f, 0.000000f, -0.445700f }	},
	{	{ 0.531485f, 0.375054f, 0.036854f },	{ 0.292904f, 0.007915f, 0.000000f },	{ 0.895200f, -0.000000f, 0.445700f }	},
	{	{ 0.531485f, 0.925075f, 0.036854f },	{ 0.384143f, 0.081971f, 0.000000f },	{ 0.895200f, -0.000000f, 0.445700f }	},
	{	{ 0.349757f, 0.925075f, 0.401876f },	{ 0.290821f, 0.175293f, 0.000000f },	{ 0.895200f, -0.000000f, 0.445700f }	},
	{	{ 0.349757f, 0.375054f, 0.401876f },	{ 0.199648f, 0.079992f, 0.000000f },	{ 0.895200f, -0.000000f, 0.445700f }	},
	{	{ 0.349757f, 0.375054f, 0.401876f },	{ 0.177077f, 0.027777f, 0.000000f },	{ 0.317900f, -0.000000f, 0.948100f }	},
	{	{ 0.349757f, 0.925075f, 0.401876f },	{ 0.309054f, 0.027777f, 0.000000f },	{ 0.317900f, -0.000000f, 0.948100f }	},
	{	{ -0.036854f, 0.925075f, 0.531485f },	{ 0.309054f, 0.159754f, 0.000000f },	{ 0.317900f, -0.000000f, 0.948100f }	},
	{	{ -0.036854f, 0.375054f, 0.531485f },	{ 0.177077f, 0.159754f, 0.000000f },	{ 0.317900f, -0.000000f, 0.948100f }	},
	{	{ -0.349757f, 0.375054f, -0.401876f },	{ 0.314223f, 0.428825f, 0.000000f },	{ -0.317900f, 0.000000f, -0.948100f }	},
	{	{ -0.349757f, 0.925075f, -0.401876f },	{ 0.314223f, 0.296848f, 0.000000f },	{ -0.317900f, 0.000000f, -0.948100f }	},
	{	{ 0.036854f, 0.925075f, -0.531485f },	{ 0.446200f, 0.296848f, 0.000000f },	{ -0.317900f, 0.000000f, -0.948100f }	},
	{	{ 0.036854f, 0.375054f, -0.531485f },	{ 0.446200f, 0.428825f, 0.000000f },	{ -0.317900f, 0.000000f, -0.948100f }	},
	{	{ -0.044968f, 0.925075f, 0.648507f },	{ 0.295128f, 0.197947f, 0.000000f },	{ -0.445700f, -0.000000f, 0.895200f }	},
	{	{ -0.044968f, 1.300129f, 0.648507f },	{ 0.295128f, 0.065970f, 0.000000f },	{ -0.445700f, -0.000000f, 0.895200f }	},
	{	{ -0.490361f, 1.300129f, 0.426767f },	{ 0.427105f, 0.065970f, 0.000000f },	{ -0.445700f, -0.000000f, 0.895200f }	},
	{	{ -0.490361f, 0.925075f, 0.426767f },	{ 0.427105f, 0.197947f, 0.000000f },	{ -0.445700f, -0.000000f, 0.895200f }	},
	{	{ -0.648507f, 0.375054f, -0.044968f },	{ 0.072929f, 0.442713f, 0.000000f },	{ -0.948100f, -0.000000f, 0.317900f }	},
	{	{ -0.648507f, -0.000000f, -0.044968f },	{ 0.072929f, 0.310735f, 0.000000f },	{ -0.948100f, -0.000000f, 0.317900f }	},
	{	{ -0.490361f, -0.000000f, 0.426767f },	{ 0.204907f, 0.310735f, 0.000000f },	{ -0.948100f, -0.000000f, 0.317900f }	},
	{	{ -0.490361f, 0.375054f, 0.426767f },	{ 0.204907f, 0.442713f, 0.000000f },	{ -0.948100f, -0.000000f, 0.317900f }	},
	{	{ 0.036854f, 0.375054f, -0.531485f },	{ 0.072929f, 0.704838f, 0.000000f },	{ 0.445700f, 0.000000f, -0.895200f }	},
	{	{ 0.036854f, 0.925075f, -0.531485f },	{ 0.072929f, 0.572860f, 0.000000f },	{ 0.445700f, 0.000000f, -0.895200f }	},
	{	{ 0.401876f, 0.925075f, -0.349757f },	{ 0.204907f, 0.572860f, 0.000000f },	{ 0.445700f, 0.000000f, -0.895200f }	},
	{	{ 0.401876f, 0.375054f, -0.349757f },	{ 0.204907f, 0.704838f, 0.000000f },	{ 0.445700f, 0.000000f, -0.895200f }	},
	{	{ 0.490361f, 0.925075f, -0.426767f },	{ 0.076384f, 0.691236f, 0.000000f },	{ 0.948100f, 0.000000f, -0.317900f }	},
	{	{ 0.490361f, 1.300129f, -0.426766f },	{ 0.076384f, 0.559258f, 0.000000f },	{ 0.948100f, 0.000000f, -0.317900f }	},
	{	{ 0.648507f, 1.300129f, 0.044968f },	{ 0.208362f, 0.559258f, 0.000000f },	{ 0.948100f, 0.000000f, -0.317900f }	},
	{	{ 0.648507f, 0.925075f, 0.044968f },	{ 0.208362f, 0.691236f, 0.000000f },	{ 0.948100f, 0.000000f, -0.317900f }	},
	{	{ -0.531485f, 0.925075f, -0.036853f },	{ 0.388204f, 0.081190f, 0.000000f },	{ -0.948100f, -0.000000f, 0.317900f }	},
	{	{ -0.531485f, 0.375054f, -0.036854f },	{ 0.294881f, 0.174512f, 0.000000f },	{ -0.948100f, -0.000000f, 0.317900f }	},
	{	{ -0.401876f, 0.375054f, 0.349757f },	{ 0.191684f, 0.090767f, 0.000000f },	{ -0.948100f, -0.000000f, 0.317900f }	},
	{	{ -0.401876f, 0.925075f, 0.349757f },	{ 0.296964f, 0.007134f, 0.000000f },	{ -0.948100f, -0.000000f, 0.317900f }	},
	{	{ -0.648507f, 0.925075f, -0.044968f },	{ 0.076384f, 0.691236f, 0.000000f },	{ -0.895200f, 0.000000f, -0.445700f }	},
	{	{ -0.648507f, 1.300129f, -0.044968f },	{ 0.076384f, 0.559258f, 0.000000f },	{ -0.895200f, 0.000000f, -0.445700f }	},
	{	{ -0.426767f, 1.300129f, -0.490361f },	{ 0.208362f, 0.559258f, 0.000000f },	{ -0.895200f, 0.000000f, -0.445700f }	},
	{	{ -0.426767f, 0.925075f, -0.490361f },	{ 0.208362f, 0.691236f, 0.000000f },	{ -0.895200f, 0.000000f, -0.445700f }	},
	{	{ 0.648507f, 0.925075f, 0.044968f },	{ 0.333318f, 0.437505f, 0.000000f },	{ 0.895200f, -0.000000f, 0.445700f }	},
	{	{ 0.648507f, 1.300129f, 0.044968f },	{ 0.333318f, 0.305527f, 0.000000f },	{ 0.895200f, -0.000000f, 0.445700f }	},
	{	{ 0.426767f, 1.300129f, 0.490361f },	{ 0.465296f, 0.305527f, 0.000000f },	{ 0.895200f, -0.000000f, 0.445700f }	},
	{	{ 0.426767f, 0.925075f, 0.490361f },	{ 0.465296f, 0.437505f, 0.000000f },	{ 0.895200f, -0.000000f, 0.445700f }	},
	{	{ 0.426767f, 0.925075f, 0.490361f },	{ 0.295128f, 0.197947f, 0.000000f },	{ 0.317900f, -0.000000f, 0.948100f }	},
	{	{ 0.426767f, 1.300129f, 0.490361f },	{ 0.295128f, 0.065970f, 0.000000f },	{ 0.317900f, -0.000000f, 0.948100f }	},
	{	{ -0.044968f, 1.300129f, 0.648507f },	{ 0.427105f, 0.065970f, 0.000000f },	{ 0.317900f, -0.000000f, 0.948100f }	},
	{	{ -0.044968f, 0.925075f, 0.648507f },	{ 0.427105f, 0.197947f, 0.000000f },	{ 0.317900f, -0.000000f, 0.948100f }	},
	{	{ -0.426767f, 0.925075f, -0.490361f },	{ 0.312984f, 0.702396f, 0.000000f },	{ -0.317900f, 0.000000f, -0.948100f }	},
	{	{ -0.426767f, 1.300129f, -0.490361f },	{ 0.312984f, 0.570419f, 0.000000f },	{ -0.317900f, 0.000000f, -0.948100f }	},
	{	{ 0.044968f, 1.300129f, -0.648507f },	{ 0.444962f, 0.570419f, 0.000000f },	{ -0.317900f, 0.000000f, -0.948100f }	},
	{	{ 0.044968f, 0.925075f, -0.648507f },	{ 0.444962f, 0.702396f, 0.000000f },	{ -0.317900f, 0.000000f, -0.948100f }	},
	{	{ -0.401876f, 0.925075f, 0.349757f },	{ 0.309054f, 0.159754f, 0.000000f },	{ -0.445700f, -0.000000f, 0.895200f }	},
	{	{ -0.401876f, 0.375054f, 0.349757f },	{ 0.177077f, 0.159754f, 0.000000f },	{ -0.445700f, -0.000000f, 0.895200f }	},
	{	{ -0.036854f, 0.375054f, 0.531485f },	{ 0.177077f, 0.027777f, 0.000000f },	{ -0.445700f, -0.000000f, 0.895200f }	},
	{	{ -0.036854f, 0.925075f, 0.531485f },	{ 0.309054f, 0.027777f, 0.000000f },	{ -0.445700f, -0.000000f, 0.895200f }	},
	{	{ 0.044968f, 0.925075f, -0.648507f },	{ 0.075162f, 0.947162f, 0.000000f },	{ 0.445700f, 0.000000f, -0.895200f }	},
	{	{ 0.044968f, 1.300129f, -0.648507f },	{ 0.075162f, 0.815184f, 0.000000f },	{ 0.445700f, 0.000000f, -0.895200f }	},
	{	{ 0.490361f, 1.300129f, -0.426766f },	{ 0.207140f, 0.815184f, 0.000000f },	{ 0.445700f, 0.000000f, -0.895200f }	},
	{	{ 0.490361f, 0.925075f, -0.426767f },	{ 0.207140f, 0.947162f, 0.000000f },	{ 0.445700f, 0.000000f, -0.895200f }	},
	{	{ -0.349757f, 0.375054f, -0.401876f },	{ 0.315960f, 0.434049f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.426767f, 0.375054f, -0.490361f },	{ 0.315960f, 0.302072f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.648507f, 0.375054f, -0.044968f },	{ 0.447938f, 0.302072f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.531485f, 0.375054f, -0.036854f },	{ 0.447938f, 0.434049f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.349757f, 0.375054f, 0.401876f },	{ 0.226977f, 0.125365f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.426767f, 0.375054f, 0.490361f },	{ 0.250227f, 0.096493f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.648507f, 0.375054f, 0.044968f },	{ 0.303148f, 0.140669f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.531485f, 0.375054f, 0.036854f },	{ 0.269903f, 0.133935f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.036854f, 0.375054f, 0.531485f },	{ 0.055553f, 0.204891f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.044968f, 0.375054f, 0.648507f },	{ 0.055553f, 0.072914f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.426767f, 0.375054f, 0.490361f },	{ 0.187531f, 0.072914f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.349757f, 0.375054f, 0.401876f },	{ 0.187531f, 0.204891f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.036854f, 0.375054f, -0.531485f },	{ 0.069442f, 0.430577f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.044968f, 0.375054f, -0.648507f },	{ 0.069442f, 0.298600f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.426767f, 0.375054f, -0.490361f },	{ 0.201419f, 0.298600f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.349757f, 0.375054f, -0.401876f },	{ 0.201419f, 0.430577f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.401876f, 0.375054f, 0.349757f },	{ 0.055553f, 0.204891f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.490361f, 0.375054f, 0.426767f },	{ 0.055553f, 0.072914f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.044968f, 0.375054f, 0.648507f },	{ 0.187531f, 0.072914f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.036854f, 0.375054f, 0.531485f },	{ 0.187531f, 0.204891f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.401876f, 0.375054f, -0.349757f },	{ 0.081593f, 0.949619f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.490361f, 0.375054f, -0.426767f },	{ 0.081593f, 0.817641f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.044968f, 0.375054f, -0.648507f },	{ 0.213571f, 0.817641f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.036854f, 0.375054f, -0.531485f },	{ 0.213571f, 0.949619f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.531485f, 0.375054f, 0.036854f },	{ 0.315960f, 0.434049f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.648507f, 0.375054f, 0.044968f },	{ 0.315960f, 0.302072f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.490361f, 0.375054f, -0.426767f },	{ 0.447938f, 0.302072f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ 0.401876f, 0.375054f, -0.349757f },	{ 0.447938f, 0.434049f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.531485f, 0.375054f, -0.036854f },	{ 0.290431f, 0.032388f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.648507f, 0.375054f, -0.044968f },	{ 0.383753f, 0.125710f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.490361f, 0.375054f, 0.426767f },	{ 0.250596f, 0.229186f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.401876f, 0.375054f, 0.349757f },	{ 0.201419f, 0.127740f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f }	},
	{	{ -0.401876f, 0.925075f, 0.349757f },	{ 0.069442f, 0.965279f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -0.490361f, 0.925075f, 0.426767f },	{ 0.069442f, 0.833302f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -0.648507f, 0.925075f, -0.044968f },	{ 0.201419f, 0.833302f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -0.531485f, 0.925075f, -0.036853f },	{ 0.201419f, 0.965279f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -0.036854f, 0.925075f, 0.531485f },	{ 0.069442f, 0.965279f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -0.044968f, 0.925075f, 0.648507f },	{ 0.069442f, 0.833302f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -0.490361f, 0.925075f, 0.426767f },	{ 0.201419f, 0.833302f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -0.401876f, 0.925075f, 0.349757f },	{ 0.201419f, 0.965279f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.401876f, 0.925075f, -0.349757f },	{ 0.069442f, 0.965279f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.490361f, 0.925075f, -0.426767f },	{ 0.069442f, 0.833302f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.648507f, 0.925075f, 0.044968f },	{ 0.201419f, 0.833302f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.531485f, 0.925075f, 0.036854f },	{ 0.201419f, 0.965279f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -0.531485f, 0.925075f, -0.036853f },	{ 0.069442f, 0.965279f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -0.648507f, 0.925075f, -0.044968f },	{ 0.069442f, 0.833302f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -0.426767f, 0.925075f, -0.490361f },	{ 0.201419f, 0.833302f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -0.349757f, 0.925075f, -0.401876f },	{ 0.201419f, 0.965279f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.531485f, 0.925075f, 0.036854f },	{ 0.069442f, 0.965279f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.648507f, 0.925075f, 0.044968f },	{ 0.069442f, 0.833302f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.426767f, 0.925075f, 0.490361f },	{ 0.201419f, 0.833302f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.349757f, 0.925075f, 0.401876f },	{ 0.201419f, 0.965279f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.349757f, 0.925075f, 0.401876f },	{ 0.069442f, 0.965279f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.426767f, 0.925075f, 0.490361f },	{ 0.069442f, 0.833302f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -0.044968f, 0.925075f, 0.648507f },	{ 0.201419f, 0.833302f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -0.036854f, 0.925075f, 0.531485f },	{ 0.201419f, 0.965279f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -0.349757f, 0.925075f, -0.401876f },	{ 0.069442f, 0.965279f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -0.426767f, 0.925075f, -0.490361f },	{ 0.069442f, 0.833302f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.044968f, 0.925075f, -0.648507f },	{ 0.201419f, 0.833302f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.036854f, 0.925075f, -0.531485f },	{ 0.201419f, 0.965279f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.036854f, 0.925075f, -0.531485f },	{ 0.069442f, 0.965279f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.044968f, 0.925075f, -0.648507f },	{ 0.069442f, 0.833302f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.490361f, 0.925075f, -0.426767f },	{ 0.201419f, 0.833302f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.401876f, 0.925075f, -0.349757f },	{ 0.201419f, 0.965279f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
};
#define _pillar01_vertices_
#endif
#ifndef _pillar01_indices_
// Index Data follows: Sequential by mesh, Every Three Indices == One Triangle.
const unsigned int pillar01_indices[276] =
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
	 36, 33, 37,
	 38, 36, 37,
	 39, 40, 41,
	 35, 39, 41,
	 42, 43, 44,
	 45, 42, 44,
	 46, 47, 48,
	 49, 46, 48,
	 49, 42, 45,
	 46, 49, 45,
	 50, 51, 52,
	 53, 50, 52,
	 54, 55, 56,
	 57, 54, 56,
	 58, 59, 60,
	 61, 58, 60,
	 62, 63, 64,
	 65, 62, 64,
	 66, 67, 68,
	 69, 66, 68,
	 70, 71, 72,
	 73, 70, 72,
	 74, 75, 76,
	 77, 74, 76,
	 78, 79, 80,
	 81, 78, 80,
	 82, 83, 84,
	 85, 82, 84,
	 86, 87, 88,
	 89, 86, 88,
	 90, 91, 92,
	 93, 90, 92,
	 94, 95, 96,
	 97, 94, 96,
	 98, 99, 100,
	 101, 98, 100,
	 102, 103, 104,
	 105, 102, 104,
	 106, 107, 108,
	 109, 106, 108,
	 110, 111, 112,
	 113, 110, 112,
	 114, 115, 116,
	 117, 114, 116,
	 118, 119, 120,
	 121, 118, 120,
	 122, 123, 124,
	 125, 122, 124,
	 126, 127, 128,
	 129, 126, 128,
	 130, 131, 132,
	 133, 130, 132,
	 134, 135, 136,
	 137, 134, 136,
	 138, 139, 140,
	 141, 138, 140,
	 142, 143, 144,
	 145, 142, 144,
	 146, 147, 148,
	 149, 146, 148,
	 150, 151, 152,
	 153, 150, 152,
	 154, 155, 156,
	 157, 154, 156,
	 158, 159, 160,
	 161, 158, 160,
	 162, 163, 164,
	 165, 162, 164,
	 166, 167, 168,
	 169, 166, 168,
	 170, 171, 172,
	 173, 170, 172,
	 174, 175, 176,
	 177, 174, 176,
};
#define _pillar01_indices_
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
#ifndef _pillar01_materials_
// Material Data follows: pulled from a .mtl file of the same name if present.
const OBJ_MATERIAL pillar01_materials[1] =
{
	{
		{{ 0.800000f, 0.800000f, 0.800000f },
		1.000000f,
		{ 0.500000f, 0.500000f, 0.500000f },
		324.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		60.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		1.000000f,
		{ 0.000000f, 0.000000f, 0.000000f },
		2},
		"Material.007",
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
#define _pillar01_materials_
#endif
/************************************************/
/*  This section contains the model's structure */
/************************************************/
#ifndef _pillar01_batches_
// Use this conveinence array to batch render all geometry by like material.
// Each entry corresponds to the same entry in the materials array above.
// The two numbers provided are the IndexCount and the IndexOffset into the indices array.
// If you need more fine grained control(ex: for transformations) use the OBJ_MESH data below.
const unsigned int pillar01_batches[1][2] =
{
	{ 276, 0 },
};
#define _pillar01_batches_
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
#ifndef _pillar01_meshes_
// Mesh Data follows: Meshes are .obj groups sorted & split by material.
// Meshes are provided in sequential order, sorted by material first and name second.
const OBJ_MESH pillar01_meshes[1] =
{
	{
		"default",
		276,
		0,
		0,
	},
};
#define _pillar01_meshes_
#endif