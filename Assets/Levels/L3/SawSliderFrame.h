// "SawSliderFrame.h" generated by "Obj2Header.exe" [Version 1.9d] Author: L.Norri Fullsail University.
// Data is converted to left-handed coordinate system and UV data is V flipped for Direct3D/Vulkan.
// The companion file "SawSliderFrame.h2b" is a binary dump of this format(-padding) for more flexibility.
// Loading *.h2b: read version, sizes, handle strings(max len 260) by reading until null-terminated.
/***********************/
/*  Generator version  */
/***********************/
#ifndef _SawSliderFrame_version_
const char SawSliderFrame_version[4] = { '0','1','9','d' };
#define _SawSliderFrame_version_
#endif
/************************************************/
/*  This section contains the model's size data */
/************************************************/
#ifndef _SawSliderFrame_vertexcount_
const unsigned SawSliderFrame_vertexcount = 120;
#define _SawSliderFrame_vertexcount_
#endif
#ifndef _SawSliderFrame_indexcount_
const unsigned SawSliderFrame_indexcount = 204;
#define _SawSliderFrame_indexcount_
#endif
#ifndef _SawSliderFrame_materialcount_
const unsigned SawSliderFrame_materialcount = 1; // can be used for batched draws
#define _SawSliderFrame_materialcount_
#endif
#ifndef _SawSliderFrame_meshcount_
const unsigned SawSliderFrame_meshcount = 1;
#define _SawSliderFrame_meshcount_
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
#ifndef _SawSliderFrame_vertices_
// Raw Vertex Data follows: Positions, Texture Coordinates and Normals.
const OBJ_VERT SawSliderFrame_vertices[120] =
{
	{	{ -1.259515f, 0.222577f, -0.014172f },	{ 0.112536f, 0.000332f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.252753f, 0.222577f, -0.014172f },	{ 0.157368f, 0.000332f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.252753f, 0.070517f, -0.014172f },	{ 0.157369f, 0.999677f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.259515f, 0.222577f, -0.003011f },	{ 0.374587f, 0.014579f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.259515f, 0.222577f, -0.005496f },	{ 0.391782f, 0.014563f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.259515f, 0.070517f, -0.005496f },	{ 0.391781f, 0.999660f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.248354f, 0.222577f, -0.003011f },	{ 0.074963f, 0.000332f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.252753f, 0.222577f, -0.003011f },	{ 0.104120f, 0.000332f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.252753f, 0.070517f, -0.003011f },	{ 0.104117f, 0.999677f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.248354f, 0.222577f, -0.014172f },	{ 0.706006f, 0.035006f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.248354f, 0.222577f, -0.011720f },	{ 0.722844f, 0.034986f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.248354f, 0.070517f, -0.011720f },	{ 0.722844f, 0.999657f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.259515f, 0.222577f, -0.011720f },	{ 0.432453f, 0.014563f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.259515f, 0.070517f, -0.011720f },	{ 0.432453f, 0.999660f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.248354f, 0.222577f, -0.005496f },	{ 0.670922f, 0.028412f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.248354f, 0.222577f, -0.003011f },	{ 0.687875f, 0.028396f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.248354f, 0.070517f, -0.003011f },	{ 0.687875f, 0.999660f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.252753f, 0.222577f, -0.005496f },	{ 0.593714f, 0.000323f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.248354f, 0.222577f, -0.005496f },	{ 0.622871f, 0.000323f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.248354f, 0.070517f, -0.005496f },	{ 0.622871f, 0.999677f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.259515f, 0.222577f, -0.014172f },	{ 0.449647f, 0.014543f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.259515f, 0.070517f, -0.014172f },	{ 0.449647f, 0.999640f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.248354f, 0.222577f, -0.014172f },	{ 0.186525f, 0.000332f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.248354f, 0.070517f, -0.014172f },	{ 0.186525f, 0.999677f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.259515f, 0.222577f, -0.003011f },	{ 0.148952f, 0.000332f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.259515f, 0.070517f, -0.003011f },	{ 0.148952f, 0.999677f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.252753f, 0.070517f, -0.005496f },	{ 0.533461f, 0.999677f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.252753f, 0.070517f, -0.011720f },	{ 0.492201f, 0.999677f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.252753f, 0.222577f, -0.011720f },	{ 0.492201f, 0.000330f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.252753f, 0.070517f, -0.011720f },	{ 0.652674f, 0.999677f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.248354f, 0.070517f, -0.011720f },	{ 0.623517f, 0.999677f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.248354f, 0.222577f, -0.011720f },	{ 0.623518f, 0.000323f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.260010f, 0.071234f, -0.014652f },	{ 0.627417f, 0.380597f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.247830f, 0.071234f, -0.014652f },	{ 0.704191f, 0.380597f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.247830f, 0.003469f, -0.014652f },	{ 0.704191f, 0.807754f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.260010f, 0.071234f, -0.002473f },	{ 0.395850f, 0.380597f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.260010f, 0.071234f, -0.014652f },	{ 0.472624f, 0.380597f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.260010f, 0.003469f, -0.014652f },	{ 0.472624f, 0.807754f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.247830f, 0.071234f, -0.002473f },	{ 0.704484f, 0.053324f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.260010f, 0.071234f, -0.002473f },	{ 0.781258f, 0.053324f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.260010f, 0.003469f, -0.002473f },	{ 0.781258f, 0.480481f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.247830f, 0.071234f, -0.014652f },	{ 0.473039f, 0.380597f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.247830f, 0.071234f, -0.002473f },	{ 0.549813f, 0.380597f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.247830f, 0.003469f, -0.002473f },	{ 0.549813f, 0.807754f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.260010f, 0.071234f, -0.002473f },	{ 0.472624f, 0.303408f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -1.247830f, 0.071234f, -0.002473f },	{ 0.472624f, 0.380182f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -1.247830f, 0.071234f, -0.014652f },	{ 0.395850f, 0.380182f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -1.196065f, 0.070517f, -0.014172f },	{ 0.178755f, 0.999677f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.196065f, 0.222577f, -0.014172f },	{ 0.178755f, 0.000332f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.189303f, 0.222577f, -0.014172f },	{ 0.223590f, 0.000332f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.189303f, 0.070517f, -0.005496f },	{ 0.356745f, 0.999661f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.189303f, 0.221259f, -0.005496f },	{ 0.356740f, 0.014564f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.189303f, 0.221259f, -0.003011f },	{ 0.373935f, 0.014580f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.196065f, 0.070517f, -0.003011f },	{ 0.045156f, 0.999677f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.196065f, 0.221259f, -0.003011f },	{ 0.045158f, 0.000332f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.200463f, 0.221259f, -0.003011f },	{ 0.074314f, 0.000332f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.200463f, 0.070517f, -0.011720f },	{ 0.688522f, 0.999657f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.200463f, 0.222577f, -0.011720f },	{ 0.688521f, 0.034987f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.200463f, 0.222577f, -0.014172f },	{ 0.705359f, 0.035007f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.189303f, 0.070517f, -0.011720f },	{ 0.316075f, 0.999661f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.189303f, 0.222577f, -0.011720f },	{ 0.316068f, 0.014564f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.200463f, 0.221259f, -0.003011f },	{ 0.653321f, 0.028397f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.200463f, 0.222577f, -0.005496f },	{ 0.670274f, 0.028413f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.200463f, 0.070517f, -0.005496f },	{ 0.670275f, 0.999677f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.200463f, 0.070517f, -0.005496f },	{ 0.534107f, 0.999677f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.200463f, 0.222577f, -0.005496f },	{ 0.534107f, 0.000323f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.196065f, 0.222577f, -0.005496f },	{ 0.563264f, 0.000324f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.189303f, 0.070517f, -0.014172f },	{ 0.298880f, 0.999641f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.189303f, 0.222577f, -0.014172f },	{ 0.298874f, 0.014545f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.200463f, 0.070517f, -0.014172f },	{ 0.149599f, 0.999677f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.200463f, 0.222577f, -0.014172f },	{ 0.149599f, 0.000332f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.189303f, 0.070517f, -0.003011f },	{ 0.000323f, 0.999677f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.189303f, 0.221259f, -0.003011f },	{ 0.000323f, 0.000332f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.196065f, 0.222577f, -0.011720f },	{ 0.764604f, 0.000330f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.196065f, 0.070517f, -0.011720f },	{ 0.764603f, 0.999677f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.196065f, 0.070517f, -0.005496f },	{ 0.723343f, 0.999677f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.200463f, 0.222577f, -0.011720f },	{ 0.593068f, 0.000324f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.200463f, 0.070517f, -0.011720f },	{ 0.593068f, 0.999677f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.196065f, 0.070517f, -0.011720f },	{ 0.563911f, 0.999677f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.200987f, 0.003469f, -0.014652f },	{ 0.777910f, 0.808899f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.200987f, 0.071234f, -0.014652f },	{ 0.777910f, 0.381742f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.188808f, 0.071234f, -0.014652f },	{ 0.701136f, 0.381742f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.188808f, 0.003469f, -0.014652f },	{ 0.546343f, 0.808899f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.188808f, 0.071234f, -0.014652f },	{ 0.546343f, 0.381742f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.188808f, 0.071234f, -0.002473f },	{ 0.469569f, 0.381742f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.188808f, 0.003469f, -0.002473f },	{ 0.700721f, 0.808899f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.188808f, 0.071234f, -0.002473f },	{ 0.700721f, 0.381742f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.200987f, 0.071234f, -0.002473f },	{ 0.623947f, 0.381742f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.200987f, 0.003469f, -0.002473f },	{ 0.623532f, 0.808899f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.200987f, 0.071234f, -0.002473f },	{ 0.623532f, 0.381742f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.200987f, 0.071234f, -0.014652f },	{ 0.546758f, 0.381742f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.200987f, 0.071234f, -0.002473f },	{ 0.546343f, 0.381327f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -1.188808f, 0.071234f, -0.002473f },	{ 0.546343f, 0.304553f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -1.188808f, 0.071234f, -0.014652f },	{ 0.469569f, 0.304553f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -1.259515f, 0.070517f, -0.014172f },	{ 0.112534f, 0.999677f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.259515f, 0.070517f, -0.003011f },	{ 0.374586f, 0.999677f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.248354f, 0.070517f, -0.003011f },	{ 0.074961f, 0.999677f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.248354f, 0.070517f, -0.014172f },	{ 0.706006f, 0.999677f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.248354f, 0.070517f, -0.005496f },	{ 0.670922f, 0.999677f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.252753f, 0.070517f, -0.005496f },	{ 0.593714f, 0.999677f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.252753f, 0.222577f, -0.005496f },	{ 0.533461f, 0.000330f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.252753f, 0.222577f, -0.011720f },	{ 0.652674f, 0.000323f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.260010f, 0.003469f, -0.014652f },	{ 0.627417f, 0.807754f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.260010f, 0.003469f, -0.002473f },	{ 0.395850f, 0.807754f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.247830f, 0.003469f, -0.002473f },	{ 0.704484f, 0.480481f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.247830f, 0.003469f, -0.014652f },	{ 0.473039f, 0.807754f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.260010f, 0.071234f, -0.014652f },	{ 0.395850f, 0.303408f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -1.189303f, 0.070517f, -0.014172f },	{ 0.223588f, 0.999677f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.189303f, 0.070517f, -0.003011f },	{ 0.373940f, 0.999677f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.200463f, 0.070517f, -0.003011f },	{ 0.074313f, 0.999677f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.200463f, 0.070517f, -0.014172f },	{ 0.705360f, 0.999677f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.200463f, 0.070517f, -0.003011f },	{ 0.653322f, 0.999661f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.196065f, 0.070517f, -0.005496f },	{ 0.563264f, 0.999677f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.196065f, 0.222577f, -0.005496f },	{ 0.723345f, 0.000330f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.196065f, 0.222577f, -0.011720f },	{ 0.563911f, 0.000324f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.188808f, 0.003469f, -0.014652f },	{ 0.701136f, 0.808899f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -1.188808f, 0.003469f, -0.002473f },	{ 0.469569f, 0.808899f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.200987f, 0.003469f, -0.002473f },	{ 0.623947f, 0.808899f, 0.000000f },	{ -0.000000f, 0.000000f, 1.000000f }	},
	{	{ -1.200987f, 0.003469f, -0.014652f },	{ 0.546758f, 0.808899f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -1.200987f, 0.071234f, -0.014652f },	{ 0.469569f, 0.381327f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
};
#define _SawSliderFrame_vertices_
#endif
#ifndef _SawSliderFrame_indices_
// Index Data follows: Sequential by mesh, Every Three Indices == One Triangle.
const unsigned int SawSliderFrame_indices[204] =
{
	 0, 1, 2,
	 3, 4, 5,
	 6, 7, 8,
	 9, 10, 11,
	 4, 12, 13,
	 14, 15, 16,
	 17, 18, 19,
	 12, 20, 21,
	 1, 22, 23,
	 7, 24, 25,
	 26, 27, 28,
	 29, 30, 31,
	 32, 33, 34,
	 35, 36, 37,
	 38, 39, 40,
	 41, 42, 43,
	 44, 45, 46,
	 47, 48, 49,
	 50, 51, 52,
	 53, 54, 55,
	 56, 57, 58,
	 59, 60, 51,
	 61, 62, 63,
	 64, 65, 66,
	 67, 68, 60,
	 69, 70, 48,
	 71, 72, 54,
	 73, 74, 75,
	 76, 77, 78,
	 79, 80, 81,
	 82, 83, 84,
	 85, 86, 87,
	 88, 89, 90,
	 91, 92, 93,
	 0, 2, 94,
	 3, 5, 95,
	 6, 8, 96,
	 9, 11, 97,
	 4, 13, 5,
	 14, 16, 98,
	 17, 19, 99,
	 12, 21, 13,
	 1, 23, 2,
	 7, 25, 8,
	 26, 28, 100,
	 29, 31, 101,
	 32, 34, 102,
	 35, 37, 103,
	 38, 40, 104,
	 41, 43, 105,
	 44, 46, 106,
	 47, 49, 107,
	 50, 52, 108,
	 53, 55, 109,
	 56, 58, 110,
	 59, 51, 50,
	 61, 63, 111,
	 64, 66, 112,
	 67, 60, 59,
	 69, 48, 47,
	 71, 54, 53,
	 73, 75, 113,
	 76, 78, 114,
	 79, 81, 115,
	 82, 84, 116,
	 85, 87, 117,
	 88, 90, 118,
	 91, 93, 119,
};
#define _SawSliderFrame_indices_
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
#ifndef _SawSliderFrame_materials_
// Material Data follows: pulled from a .mtl file of the same name if present.
const OBJ_MATERIAL SawSliderFrame_materials[1] =
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
#define _SawSliderFrame_materials_
#endif
/************************************************/
/*  This section contains the model's structure */
/************************************************/
#ifndef _SawSliderFrame_batches_
// Use this conveinence array to batch render all geometry by like material.
// Each entry corresponds to the same entry in the materials array above.
// The two numbers provided are the IndexCount and the IndexOffset into the indices array.
// If you need more fine grained control(ex: for transformations) use the OBJ_MESH data below.
const unsigned int SawSliderFrame_batches[1][2] =
{
	{ 204, 0 },
};
#define _SawSliderFrame_batches_
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
#ifndef _SawSliderFrame_meshes_
// Mesh Data follows: Meshes are .obj groups sorted & split by material.
// Meshes are provided in sequential order, sorted by material first and name second.
const OBJ_MESH SawSliderFrame_meshes[1] =
{
	{
		"default",
		204,
		0,
		0,
	},
};
#define _SawSliderFrame_meshes_
#endif
