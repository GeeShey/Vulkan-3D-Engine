// "Chimney.h" generated by "Obj2Header.exe" [Version 1.9d] Author: L.Norri Fullsail University.
// Data is converted to left-handed coordinate system and UV data is V flipped for Direct3D/Vulkan.
// The companion file "Chimney.h2b" is a binary dump of this format(-padding) for more flexibility.
// Loading *.h2b: read version, sizes, handle strings(max len 260) by reading until null-terminated.
/***********************/
/*  Generator version  */
/***********************/
#ifndef _Chimney_version_
const char Chimney_version[4] = { '0','1','9','d' };
#define _Chimney_version_
#endif
/************************************************/
/*  This section contains the model's size data */
/************************************************/
#ifndef _Chimney_vertexcount_
const unsigned Chimney_vertexcount = 190;
#define _Chimney_vertexcount_
#endif
#ifndef _Chimney_indexcount_
const unsigned Chimney_indexcount = 198;
#define _Chimney_indexcount_
#endif
#ifndef _Chimney_materialcount_
const unsigned Chimney_materialcount = 1; // can be used for batched draws
#define _Chimney_materialcount_
#endif
#ifndef _Chimney_meshcount_
const unsigned Chimney_meshcount = 1;
#define _Chimney_meshcount_
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
#ifndef _Chimney_vertices_
// Raw Vertex Data follows: Positions, Texture Coordinates and Normals.
const OBJ_VERT Chimney_vertices[190] =
{
	{	{ 0.303482f, 0.383977f, -0.069235f },	{ 0.476338f, 0.426002f, 0.000000f },	{ 0.294600f, -0.955600f, -0.000000f }	},
	{	{ 0.299521f, 0.382756f, -0.065303f },	{ 0.500344f, 0.450438f, 0.000000f },	{ 0.294600f, -0.955600f, -0.000000f }	},
	{	{ 0.299521f, 0.382756f, -0.107991f },	{ 0.262830f, 0.450438f, 0.000000f },	{ 0.294600f, -0.955600f, -0.000000f }	},
	{	{ 0.342274f, 0.382756f, -0.069618f },	{ 0.403113f, 0.596151f, 0.000000f },	{ 1.000000f, 0.002500f, -0.002500f }	},
	{	{ 0.342360f, 0.347965f, -0.069550f },	{ 0.403113f, 0.697070f, 0.000000f },	{ 1.000000f, 0.002500f, -0.002500f }	},
	{	{ 0.342274f, 0.347883f, -0.103677f },	{ 0.213612f, 0.697070f, 0.000000f },	{ 1.000000f, 0.002500f, -0.002500f }	},
	{	{ 0.342274f, 0.347883f, -0.103677f },	{ 0.213612f, 0.697070f, 0.000000f },	{ 0.010100f, 0.020200f, -0.999700f }	},
	{	{ 0.303482f, 0.348319f, -0.104060f },	{ 0.000173f, 0.697070f, 0.000000f },	{ 0.010100f, 0.020200f, -0.999700f }	},
	{	{ 0.304260f, 0.381787f, -0.103377f },	{ 0.000173f, 0.596150f, 0.000000f },	{ 0.010100f, 0.020200f, -0.999700f }	},
	{	{ 0.304260f, 0.381787f, -0.103377f },	{ 0.806054f, 0.596151f, 0.000000f },	{ -0.999700f, 0.023300f, 0.000000f }	},
	{	{ 0.303482f, 0.348319f, -0.104060f },	{ 0.806054f, 0.697070f, 0.000000f },	{ -0.999700f, 0.023300f, 0.000000f }	},
	{	{ 0.303482f, 0.348319f, -0.069235f },	{ 0.616553f, 0.697070f, 0.000000f },	{ -0.999700f, 0.023300f, 0.000000f }	},
	{	{ 0.342360f, 0.242901f, -0.069550f },	{ 0.403113f, 0.999827f, 0.000000f },	{ 0.017400f, 0.010600f, 0.999800f }	},
	{	{ 0.341936f, 0.279034f, -0.069926f },	{ 0.403113f, 0.898908f, 0.000000f },	{ 0.017400f, 0.010600f, 0.999800f }	},
	{	{ 0.303482f, 0.277004f, -0.069235f },	{ 0.616553f, 0.898908f, 0.000000f },	{ 0.017400f, 0.010600f, 0.999800f }	},
	{	{ 0.299521f, 0.382756f, -0.107991f },	{ 0.833491f, 0.000174f, 0.000000f },	{ -0.993800f, 0.111000f, 0.000000f }	},
	{	{ 0.299521f, 0.382756f, -0.065303f },	{ 0.833480f, 0.237705f, 0.000000f },	{ -0.993800f, 0.111000f, 0.000000f }	},
	{	{ 0.299947f, 0.386566f, -0.065689f },	{ 0.806407f, 0.237703f, 0.000000f },	{ -0.993800f, 0.111000f, 0.000000f }	},
	{	{ 0.342360f, 0.382986f, -0.103753f },	{ 0.286837f, 0.212562f, 0.000000f },	{ 0.028300f, -0.972000f, -0.233200f }	},
	{	{ 0.304260f, 0.381787f, -0.103377f },	{ 0.286837f, 0.426002f, 0.000000f },	{ 0.028300f, -0.972000f, -0.233200f }	},
	{	{ 0.299521f, 0.382756f, -0.107991f },	{ 0.262830f, 0.450438f, 0.000000f },	{ 0.028300f, -0.972000f, -0.233200f }	},
	{	{ 0.342274f, 0.382756f, -0.069618f },	{ 0.476338f, 0.212562f, 0.000000f },	{ 0.004800f, -0.998900f, 0.047400f }	},
	{	{ 0.346771f, 0.382986f, -0.065217f },	{ 0.500344f, 0.188126f, 0.000000f },	{ 0.004800f, -0.998900f, 0.047400f }	},
	{	{ 0.299521f, 0.382756f, -0.065303f },	{ 0.500344f, 0.450438f, 0.000000f },	{ 0.004800f, -0.998900f, 0.047400f }	},
	{	{ 0.342360f, 0.382986f, -0.103753f },	{ 0.286837f, 0.212562f, 0.000000f },	{ 0.181200f, -0.983200f, -0.020700f }	},
	{	{ 0.347196f, 0.383977f, -0.108471f },	{ 0.262830f, 0.188126f, 0.000000f },	{ 0.181200f, -0.983200f, -0.020700f }	},
	{	{ 0.346771f, 0.382986f, -0.065217f },	{ 0.500344f, 0.188126f, 0.000000f },	{ 0.181200f, -0.983200f, -0.020700f }	},
	{	{ 0.299947f, 0.386566f, -0.065689f },	{ 0.000173f, 0.212924f, 0.000000f },	{ -0.164900f, 0.985600f, 0.037900f }	},
	{	{ 0.306287f, 0.387872f, -0.072072f },	{ 0.038188f, 0.250903f, 0.000000f },	{ -0.164900f, 0.985600f, 0.037900f }	},
	{	{ 0.305977f, 0.388952f, -0.101492f },	{ 0.038188f, 0.412459f, 0.000000f },	{ -0.164900f, 0.985600f, 0.037900f }	},
	{	{ 0.299521f, 0.382756f, -0.107991f },	{ 0.833491f, 0.999826f, 0.000000f },	{ 0.009600f, -0.018300f, -0.999800f }	},
	{	{ 0.299426f, 0.387872f, -0.108086f },	{ 0.806422f, 0.999827f, 0.000000f },	{ 0.009600f, -0.018300f, -0.999800f }	},
	{	{ 0.346250f, 0.386566f, -0.107615f },	{ 0.806406f, 0.737534f, 0.000000f },	{ 0.009600f, -0.018300f, -0.999800f }	},
	{	{ 0.346771f, 0.382986f, -0.065217f },	{ 0.833470f, 0.500028f, 0.000000f },	{ -0.010100f, 0.000000f, 0.999900f }	},
	{	{ 0.346771f, 0.387872f, -0.065217f },	{ 0.806399f, 0.500028f, 0.000000f },	{ -0.010100f, 0.000000f, 0.999900f }	},
	{	{ 0.299947f, 0.386566f, -0.065689f },	{ 0.806407f, 0.237703f, 0.000000f },	{ -0.010100f, 0.000000f, 0.999900f }	},
	{	{ 0.346771f, 0.382986f, -0.065217f },	{ 0.833470f, 0.500028f, 0.000000f },	{ 0.940900f, 0.338300f, 0.017000f }	},
	{	{ 0.347196f, 0.383977f, -0.108471f },	{ 0.833476f, 0.737533f, 0.000000f },	{ 0.940900f, 0.338300f, 0.017000f }	},
	{	{ 0.346250f, 0.386566f, -0.107615f },	{ 0.806406f, 0.737534f, 0.000000f },	{ 0.940900f, 0.338300f, 0.017000f }	},
	{	{ 0.306287f, 0.387872f, -0.072072f },	{ 0.161729f, 0.450783f, 0.000000f },	{ -0.999900f, 0.000000f, -0.012800f }	},
	{	{ 0.306287f, 0.414047f, -0.072072f },	{ 0.161729f, 0.595805f, 0.000000f },	{ -0.999900f, 0.000000f, -0.012800f }	},
	{	{ 0.306657f, 0.412165f, -0.100910f },	{ 0.000173f, 0.595805f, 0.000000f },	{ -0.999900f, 0.000000f, -0.012800f }	},
	{	{ 0.346250f, 0.386566f, -0.107615f },	{ 0.262485f, 0.450438f, 0.000000f },	{ 0.029300f, 0.981400f, -0.189800f }	},
	{	{ 0.299426f, 0.387872f, -0.108086f },	{ 0.000173f, 0.450438f, 0.000000f },	{ 0.029300f, 0.981400f, -0.189800f }	},
	{	{ 0.305977f, 0.388952f, -0.101492f },	{ 0.038188f, 0.412459f, 0.000000f },	{ 0.029300f, 0.981400f, -0.189800f }	},
	{	{ 0.299947f, 0.386566f, -0.065689f },	{ 0.000173f, 0.212924f, 0.000000f },	{ -0.027800f, 0.999600f, -0.008400f }	},
	{	{ 0.346771f, 0.387872f, -0.065217f },	{ 0.262485f, 0.212924f, 0.000000f },	{ -0.027800f, 0.999600f, -0.008400f }	},
	{	{ 0.339833f, 0.387621f, -0.072129f },	{ 0.224469f, 0.250903f, 0.000000f },	{ -0.027800f, 0.999600f, -0.008400f }	},
	{	{ 0.346250f, 0.386566f, -0.107615f },	{ 0.262485f, 0.450438f, 0.000000f },	{ 0.407500f, 0.912000f, 0.046500f }	},
	{	{ 0.340210f, 0.388952f, -0.101492f },	{ 0.224469f, 0.412459f, 0.000000f },	{ 0.407500f, 0.912000f, 0.046500f }	},
	{	{ 0.339833f, 0.387621f, -0.072129f },	{ 0.224469f, 0.250903f, 0.000000f },	{ 0.407500f, 0.912000f, 0.046500f }	},
	{	{ 0.306287f, 0.414047f, -0.072072f },	{ 0.500690f, 0.288882f, 0.000000f },	{ -0.045300f, 0.997600f, -0.052300f }	},
	{	{ 0.340210f, 0.415602f, -0.071803f },	{ 0.686971f, 0.288882f, 0.000000f },	{ -0.045300f, 0.997600f, -0.052300f }	},
	{	{ 0.339909f, 0.414047f, -0.101231f },	{ 0.686971f, 0.450438f, 0.000000f },	{ -0.045300f, 0.997600f, -0.052300f }	},
	{	{ 0.340210f, 0.388952f, -0.101492f },	{ 0.509566f, 0.450783f, 0.000000f },	{ -0.000000f, 0.025000f, -0.999700f }	},
	{	{ 0.305977f, 0.388952f, -0.101492f },	{ 0.695846f, 0.450783f, 0.000000f },	{ -0.000000f, 0.025000f, -0.999700f }	},
	{	{ 0.306657f, 0.412165f, -0.100910f },	{ 0.695846f, 0.595805f, 0.000000f },	{ -0.000000f, 0.025000f, -0.999700f }	},
	{	{ 0.339833f, 0.387621f, -0.072129f },	{ 0.348010f, 0.450783f, 0.000000f },	{ -0.007400f, -0.011600f, 0.999900f }	},
	{	{ 0.340210f, 0.415602f, -0.071803f },	{ 0.348010f, 0.595805f, 0.000000f },	{ -0.007400f, -0.011600f, 0.999900f }	},
	{	{ 0.306287f, 0.414047f, -0.072072f },	{ 0.161729f, 0.595805f, 0.000000f },	{ -0.007400f, -0.011600f, 0.999900f }	},
	{	{ 0.339833f, 0.387621f, -0.072129f },	{ 0.348010f, 0.450783f, 0.000000f },	{ 0.999800f, 0.011800f, 0.013400f }	},
	{	{ 0.340210f, 0.388952f, -0.101492f },	{ 0.509566f, 0.450783f, 0.000000f },	{ 0.999800f, 0.011800f, 0.013400f }	},
	{	{ 0.339909f, 0.414047f, -0.101231f },	{ 0.509566f, 0.595805f, 0.000000f },	{ 0.999800f, 0.011800f, 0.013400f }	},
	{	{ 0.341936f, 0.279034f, -0.069926f },	{ 0.403113f, 0.898908f, 0.000000f },	{ 0.999900f, 0.011600f, -0.011900f }	},
	{	{ 0.342360f, 0.242901f, -0.069550f },	{ 0.403113f, 0.999827f, 0.000000f },	{ 0.999900f, 0.011600f, -0.011900f }	},
	{	{ 0.341936f, 0.244783f, -0.103377f },	{ 0.213612f, 0.999827f, 0.000000f },	{ 0.999900f, 0.011600f, -0.011900f }	},
	{	{ 0.341936f, 0.279034f, -0.069926f },	{ 0.403113f, 0.898908f, 0.000000f },	{ 0.999600f, 0.020800f, 0.021300f }	},
	{	{ 0.342705f, 0.277004f, -0.104060f },	{ 0.213612f, 0.898908f, 0.000000f },	{ 0.999600f, 0.020800f, 0.021300f }	},
	{	{ 0.341936f, 0.313285f, -0.103377f },	{ 0.213612f, 0.797989f, 0.000000f },	{ 0.999600f, 0.020800f, 0.021300f }	},
	{	{ 0.342360f, 0.347965f, -0.069550f },	{ 0.403113f, 0.697070f, 0.000000f },	{ 0.999700f, 0.009600f, -0.022300f }	},
	{	{ 0.342705f, 0.312661f, -0.069235f },	{ 0.403113f, 0.797989f, 0.000000f },	{ 0.999700f, 0.009600f, -0.022300f }	},
	{	{ 0.341936f, 0.313285f, -0.103377f },	{ 0.213612f, 0.797989f, 0.000000f },	{ 0.999700f, 0.009600f, -0.022300f }	},
	{	{ 0.342705f, 0.277004f, -0.104060f },	{ 0.213612f, 0.898908f, 0.000000f },	{ -0.000000f, -0.021200f, -0.999800f }	},
	{	{ 0.341936f, 0.244783f, -0.103377f },	{ 0.213612f, 0.999827f, 0.000000f },	{ -0.000000f, -0.021200f, -0.999800f }	},
	{	{ 0.304260f, 0.244783f, -0.103377f },	{ 0.000173f, 0.999827f, 0.000000f },	{ -0.000000f, -0.021200f, -0.999800f }	},
	{	{ 0.342705f, 0.277004f, -0.104060f },	{ 0.213612f, 0.898908f, 0.000000f },	{ -0.000000f, 0.018800f, -0.999800f }	},
	{	{ 0.303482f, 0.277004f, -0.104060f },	{ 0.000173f, 0.898908f, 0.000000f },	{ -0.000000f, 0.018800f, -0.999800f }	},
	{	{ 0.304260f, 0.313285f, -0.103377f },	{ 0.000173f, 0.797989f, 0.000000f },	{ -0.000000f, 0.018800f, -0.999800f }	},
	{	{ 0.342274f, 0.347883f, -0.103677f },	{ 0.213612f, 0.697070f, 0.000000f },	{ -0.000000f, -0.008700f, -1.000000f }	},
	{	{ 0.341936f, 0.313285f, -0.103377f },	{ 0.213612f, 0.797989f, 0.000000f },	{ -0.000000f, -0.008700f, -1.000000f }	},
	{	{ 0.304260f, 0.313285f, -0.103377f },	{ 0.000173f, 0.797989f, 0.000000f },	{ -0.000000f, -0.008700f, -1.000000f }	},
	{	{ 0.304260f, 0.244783f, -0.103377f },	{ 0.806054f, 0.999827f, 0.000000f },	{ -0.999700f, 0.000000f, -0.022800f }	},
	{	{ 0.303482f, 0.241346f, -0.069235f },	{ 0.616553f, 0.999827f, 0.000000f },	{ -0.999700f, 0.000000f, -0.022800f }	},
	{	{ 0.303482f, 0.277004f, -0.069235f },	{ 0.616553f, 0.898908f, 0.000000f },	{ -0.999700f, 0.000000f, -0.022800f }	},
	{	{ 0.304260f, 0.313285f, -0.103377f },	{ 0.806054f, 0.797989f, 0.000000f },	{ -0.999800f, 0.021500f, 0.000000f }	},
	{	{ 0.303482f, 0.277004f, -0.104060f },	{ 0.806054f, 0.898908f, 0.000000f },	{ -0.999800f, 0.021500f, 0.000000f }	},
	{	{ 0.303482f, 0.277004f, -0.069235f },	{ 0.616553f, 0.898908f, 0.000000f },	{ -0.999800f, 0.021500f, 0.000000f }	},
	{	{ 0.304260f, 0.313285f, -0.103377f },	{ 0.806054f, 0.797989f, 0.000000f },	{ -0.999700f, 0.000000f, -0.022800f }	},
	{	{ 0.303482f, 0.312661f, -0.069235f },	{ 0.616553f, 0.797989f, 0.000000f },	{ -0.999700f, 0.000000f, -0.022800f }	},
	{	{ 0.303482f, 0.348319f, -0.069235f },	{ 0.616553f, 0.697070f, 0.000000f },	{ -0.999700f, 0.000000f, -0.022800f }	},
	{	{ 0.342274f, 0.382756f, -0.069618f },	{ 0.403113f, 0.596151f, 0.000000f },	{ 0.009900f, 0.000000f, 1.000000f }	},
	{	{ 0.303482f, 0.383977f, -0.069235f },	{ 0.616553f, 0.596151f, 0.000000f },	{ 0.009900f, 0.000000f, 1.000000f }	},
	{	{ 0.303482f, 0.348319f, -0.069235f },	{ 0.616553f, 0.697070f, 0.000000f },	{ 0.009900f, 0.000000f, 1.000000f }	},
	{	{ 0.342360f, 0.347965f, -0.069550f },	{ 0.403113f, 0.697070f, 0.000000f },	{ 0.008100f, 0.000000f, 1.000000f }	},
	{	{ 0.303482f, 0.348319f, -0.069235f },	{ 0.616553f, 0.697070f, 0.000000f },	{ 0.008100f, 0.000000f, 1.000000f }	},
	{	{ 0.303482f, 0.312661f, -0.069235f },	{ 0.616553f, 0.797989f, 0.000000f },	{ 0.008100f, 0.000000f, 1.000000f }	},
	{	{ 0.341936f, 0.279034f, -0.069926f },	{ 0.403113f, 0.898908f, 0.000000f },	{ 0.000000f, -0.020600f, 0.999800f }	},
	{	{ 0.342705f, 0.312661f, -0.069235f },	{ 0.403113f, 0.797989f, 0.000000f },	{ 0.000000f, -0.020600f, 0.999800f }	},
	{	{ 0.303482f, 0.312661f, -0.069235f },	{ 0.616553f, 0.797989f, 0.000000f },	{ 0.000000f, -0.020600f, 0.999800f }	},
	{	{ 0.303482f, 0.383977f, -0.069235f },	{ 0.476338f, 0.426002f, 0.000000f },	{ -0.252200f, -0.966000f, 0.056200f }	},
	{	{ 0.299521f, 0.382756f, -0.107991f },	{ 0.262830f, 0.450438f, 0.000000f },	{ -0.252200f, -0.966000f, 0.056200f }	},
	{	{ 0.304260f, 0.381787f, -0.103377f },	{ 0.286837f, 0.426002f, 0.000000f },	{ -0.252200f, -0.966000f, 0.056200f }	},
	{	{ 0.342274f, 0.382756f, -0.069618f },	{ 0.403113f, 0.596151f, 0.000000f },	{ 1.000000f, -0.002400f, 0.002500f }	},
	{	{ 0.342274f, 0.347883f, -0.103677f },	{ 0.213612f, 0.697070f, 0.000000f },	{ 1.000000f, -0.002400f, 0.002500f }	},
	{	{ 0.342360f, 0.382986f, -0.103753f },	{ 0.213612f, 0.596151f, 0.000000f },	{ 1.000000f, -0.002400f, 0.002500f }	},
	{	{ 0.342274f, 0.347883f, -0.103677f },	{ 0.213612f, 0.697070f, 0.000000f },	{ -0.009800f, -0.002200f, -0.999900f }	},
	{	{ 0.304260f, 0.381787f, -0.103377f },	{ 0.000173f, 0.596150f, 0.000000f },	{ -0.009800f, -0.002200f, -0.999900f }	},
	{	{ 0.342360f, 0.382986f, -0.103753f },	{ 0.213612f, 0.596151f, 0.000000f },	{ -0.009800f, -0.002200f, -0.999900f }	},
	{	{ 0.304260f, 0.381787f, -0.103377f },	{ 0.806054f, 0.596151f, 0.000000f },	{ -0.999700f, 0.000000f, -0.022800f }	},
	{	{ 0.303482f, 0.383977f, -0.069235f },	{ 0.616553f, 0.596151f, 0.000000f },	{ -0.999700f, 0.000000f, -0.022800f }	},
	{	{ 0.342360f, 0.242901f, -0.069550f },	{ 0.403113f, 0.999827f, 0.000000f },	{ 0.008100f, 0.000000f, 1.000000f }	},
	{	{ 0.303482f, 0.277004f, -0.069235f },	{ 0.616553f, 0.898908f, 0.000000f },	{ 0.008100f, 0.000000f, 1.000000f }	},
	{	{ 0.303482f, 0.241346f, -0.069235f },	{ 0.616553f, 0.999827f, 0.000000f },	{ 0.008100f, 0.000000f, 1.000000f }	},
	{	{ 0.299521f, 0.382756f, -0.107991f },	{ 0.833491f, 0.000174f, 0.000000f },	{ -0.999800f, -0.018400f, 0.011700f }	},
	{	{ 0.299947f, 0.386566f, -0.065689f },	{ 0.806407f, 0.237703f, 0.000000f },	{ -0.999800f, -0.018400f, 0.011700f }	},
	{	{ 0.299426f, 0.387872f, -0.108086f },	{ 0.806418f, 0.000172f, 0.000000f },	{ -0.999800f, -0.018400f, 0.011700f }	},
	{	{ 0.342360f, 0.382986f, -0.103753f },	{ 0.286837f, 0.212562f, 0.000000f },	{ 0.023300f, -0.982900f, -0.182500f }	},
	{	{ 0.299521f, 0.382756f, -0.107991f },	{ 0.262830f, 0.450438f, 0.000000f },	{ 0.023300f, -0.982900f, -0.182500f }	},
	{	{ 0.347196f, 0.383977f, -0.108471f },	{ 0.262830f, 0.188126f, 0.000000f },	{ 0.023300f, -0.982900f, -0.182500f }	},
	{	{ 0.342274f, 0.382756f, -0.069618f },	{ 0.476338f, 0.212562f, 0.000000f },	{ -0.033000f, -0.944600f, -0.326500f }	},
	{	{ 0.299521f, 0.382756f, -0.065303f },	{ 0.500344f, 0.450438f, 0.000000f },	{ -0.033000f, -0.944600f, -0.326500f }	},
	{	{ 0.303482f, 0.383977f, -0.069235f },	{ 0.476338f, 0.426002f, 0.000000f },	{ -0.033000f, -0.944600f, -0.326500f }	},
	{	{ 0.342360f, 0.382986f, -0.103753f },	{ 0.286837f, 0.212562f, 0.000000f },	{ 0.057600f, -0.998300f, -0.006600f }	},
	{	{ 0.346771f, 0.382986f, -0.065217f },	{ 0.500344f, 0.188126f, 0.000000f },	{ 0.057600f, -0.998300f, -0.006600f }	},
	{	{ 0.342274f, 0.382756f, -0.069618f },	{ 0.476338f, 0.212562f, 0.000000f },	{ 0.057600f, -0.998300f, -0.006600f }	},
	{	{ 0.299947f, 0.386566f, -0.065689f },	{ 0.000173f, 0.212924f, 0.000000f },	{ -0.194400f, 0.980400f, 0.032600f }	},
	{	{ 0.305977f, 0.388952f, -0.101492f },	{ 0.038188f, 0.412459f, 0.000000f },	{ -0.194400f, 0.980400f, 0.032600f }	},
	{	{ 0.299426f, 0.387872f, -0.108086f },	{ 0.000173f, 0.450438f, 0.000000f },	{ -0.194400f, 0.980400f, 0.032600f }	},
	{	{ 0.299521f, 0.382756f, -0.107991f },	{ 0.833491f, 0.999826f, 0.000000f },	{ -0.017500f, 0.308400f, -0.951100f }	},
	{	{ 0.346250f, 0.386566f, -0.107615f },	{ 0.806406f, 0.737534f, 0.000000f },	{ -0.017500f, 0.308400f, -0.951100f }	},
	{	{ 0.347196f, 0.383977f, -0.108471f },	{ 0.833476f, 0.737533f, 0.000000f },	{ -0.017500f, 0.308400f, -0.951100f }	},
	{	{ 0.346771f, 0.382986f, -0.065217f },	{ 0.833470f, 0.500028f, 0.000000f },	{ -0.002300f, 0.100900f, 0.994900f }	},
	{	{ 0.299947f, 0.386566f, -0.065689f },	{ 0.806407f, 0.237703f, 0.000000f },	{ -0.002300f, 0.100900f, 0.994900f }	},
	{	{ 0.299521f, 0.382756f, -0.065303f },	{ 0.833480f, 0.237705f, 0.000000f },	{ -0.002300f, 0.100900f, 0.994900f }	},
	{	{ 0.346771f, 0.382986f, -0.065217f },	{ 0.833470f, 0.500028f, 0.000000f },	{ 0.999900f, 0.000000f, -0.012300f }	},
	{	{ 0.346250f, 0.386566f, -0.107615f },	{ 0.806406f, 0.737534f, 0.000000f },	{ 0.999900f, 0.000000f, -0.012300f }	},
	{	{ 0.346771f, 0.387872f, -0.065217f },	{ 0.806399f, 0.500028f, 0.000000f },	{ 0.999900f, 0.000000f, -0.012300f }	},
	{	{ 0.306287f, 0.387872f, -0.072072f },	{ 0.161729f, 0.450783f, 0.000000f },	{ -0.999500f, 0.029000f, 0.011600f }	},
	{	{ 0.306657f, 0.412165f, -0.100910f },	{ 0.000173f, 0.595805f, 0.000000f },	{ -0.999500f, 0.029000f, 0.011600f }	},
	{	{ 0.305977f, 0.388952f, -0.101492f },	{ 0.000173f, 0.450783f, 0.000000f },	{ -0.999500f, 0.029000f, 0.011600f }	},
	{	{ 0.346250f, 0.386566f, -0.107615f },	{ 0.262485f, 0.450438f, 0.000000f },	{ -0.000000f, 0.931700f, -0.363100f }	},
	{	{ 0.305977f, 0.388952f, -0.101492f },	{ 0.038188f, 0.412459f, 0.000000f },	{ -0.000000f, 0.931700f, -0.363100f }	},
	{	{ 0.340210f, 0.388952f, -0.101492f },	{ 0.224469f, 0.412459f, 0.000000f },	{ -0.000000f, 0.931700f, -0.363100f }	},
	{	{ 0.299947f, 0.386566f, -0.065689f },	{ 0.000173f, 0.212924f, 0.000000f },	{ 0.007700f, 0.978100f, 0.207800f }	},
	{	{ 0.339833f, 0.387621f, -0.072129f },	{ 0.224469f, 0.250903f, 0.000000f },	{ 0.007700f, 0.978100f, 0.207800f }	},
	{	{ 0.306287f, 0.387872f, -0.072072f },	{ 0.038188f, 0.250903f, 0.000000f },	{ 0.007700f, 0.978100f, 0.207800f }	},
	{	{ 0.346250f, 0.386566f, -0.107615f },	{ 0.262485f, 0.450438f, 0.000000f },	{ -0.005500f, 0.999500f, -0.030700f }	},
	{	{ 0.339833f, 0.387621f, -0.072129f },	{ 0.224469f, 0.250903f, 0.000000f },	{ -0.005500f, 0.999500f, -0.030700f }	},
	{	{ 0.346771f, 0.387872f, -0.065217f },	{ 0.262485f, 0.212924f, 0.000000f },	{ -0.005500f, 0.999500f, -0.030700f }	},
	{	{ 0.306287f, 0.414047f, -0.072072f },	{ 0.500690f, 0.288882f, 0.000000f },	{ -0.057000f, 0.996200f, -0.065800f }	},
	{	{ 0.339909f, 0.414047f, -0.101231f },	{ 0.686971f, 0.450438f, 0.000000f },	{ -0.057000f, 0.996200f, -0.065800f }	},
	{	{ 0.306657f, 0.412165f, -0.100910f },	{ 0.500690f, 0.450438f, 0.000000f },	{ -0.057000f, 0.996200f, -0.065800f }	},
	{	{ 0.340210f, 0.388952f, -0.101492f },	{ 0.509566f, 0.450783f, 0.000000f },	{ -0.010200f, 0.010300f, -0.999900f }	},
	{	{ 0.306657f, 0.412165f, -0.100910f },	{ 0.695846f, 0.595805f, 0.000000f },	{ -0.010200f, 0.010300f, -0.999900f }	},
	{	{ 0.339909f, 0.414047f, -0.101231f },	{ 0.509566f, 0.595805f, 0.000000f },	{ -0.010200f, 0.010300f, -0.999900f }	},
	{	{ 0.339833f, 0.387621f, -0.072129f },	{ 0.348010f, 0.450783f, 0.000000f },	{ 0.001700f, 0.000000f, 1.000000f }	},
	{	{ 0.306287f, 0.414047f, -0.072072f },	{ 0.161729f, 0.595805f, 0.000000f },	{ 0.001700f, 0.000000f, 1.000000f }	},
	{	{ 0.306287f, 0.387872f, -0.072072f },	{ 0.161729f, 0.450783f, 0.000000f },	{ 0.001700f, 0.000000f, 1.000000f }	},
	{	{ 0.339833f, 0.387621f, -0.072129f },	{ 0.348010f, 0.450783f, 0.000000f },	{ 0.999900f, -0.013300f, -0.009500f }	},
	{	{ 0.339909f, 0.414047f, -0.101231f },	{ 0.509566f, 0.595805f, 0.000000f },	{ 0.999900f, -0.013300f, -0.009500f }	},
	{	{ 0.340210f, 0.415602f, -0.071803f },	{ 0.348010f, 0.595805f, 0.000000f },	{ 0.999900f, -0.013300f, -0.009500f }	},
	{	{ 0.341936f, 0.279034f, -0.069926f },	{ 0.403113f, 0.898908f, 0.000000f },	{ 0.999400f, -0.023300f, 0.023900f }	},
	{	{ 0.341936f, 0.244783f, -0.103377f },	{ 0.213612f, 0.999827f, 0.000000f },	{ 0.999400f, -0.023300f, 0.023900f }	},
	{	{ 0.342705f, 0.277004f, -0.104060f },	{ 0.213612f, 0.898908f, 0.000000f },	{ 0.999400f, -0.023300f, 0.023900f }	},
	{	{ 0.341936f, 0.279034f, -0.069926f },	{ 0.403113f, 0.898908f, 0.000000f },	{ 0.999500f, -0.022400f, -0.022900f }	},
	{	{ 0.341936f, 0.313285f, -0.103377f },	{ 0.213612f, 0.797989f, 0.000000f },	{ 0.999500f, -0.022400f, -0.022900f }	},
	{	{ 0.342705f, 0.312661f, -0.069235f },	{ 0.403113f, 0.797989f, 0.000000f },	{ 0.999500f, -0.022400f, -0.022900f }	},
	{	{ 0.342360f, 0.347965f, -0.069550f },	{ 0.403113f, 0.697070f, 0.000000f },	{ 0.999900f, -0.009800f, -0.002500f }	},
	{	{ 0.341936f, 0.313285f, -0.103377f },	{ 0.213612f, 0.797989f, 0.000000f },	{ 0.999900f, -0.009800f, -0.002500f }	},
	{	{ 0.342274f, 0.347883f, -0.103677f },	{ 0.213612f, 0.697070f, 0.000000f },	{ 0.999900f, -0.009800f, -0.002500f }	},
	{	{ 0.303482f, 0.277004f, -0.104060f },	{ 0.000173f, 0.898908f, 0.000000f },	{ -0.000000f, -0.021200f, -0.999800f }	},
	{	{ 0.341936f, 0.313285f, -0.103377f },	{ 0.213612f, 0.797989f, 0.000000f },	{ -0.000000f, 0.018800f, -0.999800f }	},
	{	{ 0.342274f, 0.347883f, -0.103677f },	{ 0.213612f, 0.697070f, 0.000000f },	{ 0.009700f, -0.019300f, -0.999800f }	},
	{	{ 0.304260f, 0.313285f, -0.103377f },	{ 0.000173f, 0.797989f, 0.000000f },	{ 0.009700f, -0.019300f, -0.999800f }	},
	{	{ 0.303482f, 0.348319f, -0.104060f },	{ 0.000173f, 0.697070f, 0.000000f },	{ 0.009700f, -0.019300f, -0.999800f }	},
	{	{ 0.304260f, 0.244783f, -0.103377f },	{ 0.806054f, 0.999827f, 0.000000f },	{ -0.999700f, -0.024200f, 0.000000f }	},
	{	{ 0.303482f, 0.277004f, -0.069235f },	{ 0.616553f, 0.898908f, 0.000000f },	{ -0.999700f, -0.024200f, 0.000000f }	},
	{	{ 0.303482f, 0.277004f, -0.104060f },	{ 0.806054f, 0.898908f, 0.000000f },	{ -0.999700f, -0.024200f, 0.000000f }	},
	{	{ 0.304260f, 0.313285f, -0.103377f },	{ 0.806054f, 0.797989f, 0.000000f },	{ -0.999800f, -0.022200f, 0.000000f }	},
	{	{ 0.303482f, 0.348319f, -0.069235f },	{ 0.616553f, 0.697070f, 0.000000f },	{ -0.999800f, -0.022200f, 0.000000f }	},
	{	{ 0.303482f, 0.348319f, -0.104060f },	{ 0.806054f, 0.697070f, 0.000000f },	{ -0.999800f, -0.022200f, 0.000000f }	},
	{	{ 0.342274f, 0.382756f, -0.069618f },	{ 0.403113f, 0.596151f, 0.000000f },	{ 0.008100f, 0.002000f, 1.000000f }	},
	{	{ 0.303482f, 0.348319f, -0.069235f },	{ 0.616553f, 0.697070f, 0.000000f },	{ 0.008100f, 0.002000f, 1.000000f }	},
	{	{ 0.342360f, 0.347965f, -0.069550f },	{ 0.403113f, 0.697070f, 0.000000f },	{ 0.008100f, 0.002000f, 1.000000f }	},
	{	{ 0.342360f, 0.347965f, -0.069550f },	{ 0.403113f, 0.697070f, 0.000000f },	{ 0.000000f, 0.008900f, 1.000000f }	},
	{	{ 0.303482f, 0.312661f, -0.069235f },	{ 0.616553f, 0.797989f, 0.000000f },	{ 0.000000f, 0.008900f, 1.000000f }	},
	{	{ 0.342705f, 0.312661f, -0.069235f },	{ 0.403113f, 0.797989f, 0.000000f },	{ 0.000000f, 0.008900f, 1.000000f }	},
	{	{ 0.341936f, 0.279034f, -0.069926f },	{ 0.403113f, 0.898908f, 0.000000f },	{ 0.018000f, 0.000000f, 0.999800f }	},
	{	{ 0.303482f, 0.312661f, -0.069235f },	{ 0.616553f, 0.797989f, 0.000000f },	{ 0.018000f, 0.000000f, 0.999800f }	},
	{	{ 0.303482f, 0.277004f, -0.069235f },	{ 0.616553f, 0.898908f, 0.000000f },	{ 0.018000f, 0.000000f, 0.999800f }	},
};
#define _Chimney_vertices_
#endif
#ifndef _Chimney_indices_
// Index Data follows: Sequential by mesh, Every Three Indices == One Triangle.
const unsigned int Chimney_indices[198] =
{
	 0, 1, 2,
	 3, 4, 5,
	 6, 7, 8,
	 9, 10, 11,
	 12, 13, 14,
	 15, 16, 17,
	 18, 19, 20,
	 21, 22, 23,
	 24, 25, 26,
	 27, 28, 29,
	 30, 31, 32,
	 33, 34, 35,
	 36, 37, 38,
	 39, 40, 41,
	 42, 43, 44,
	 45, 46, 47,
	 48, 49, 50,
	 51, 52, 53,
	 54, 55, 56,
	 57, 58, 59,
	 60, 61, 62,
	 63, 64, 65,
	 66, 67, 68,
	 69, 70, 71,
	 72, 73, 74,
	 75, 76, 77,
	 78, 79, 80,
	 81, 82, 83,
	 84, 85, 86,
	 87, 88, 89,
	 90, 91, 92,
	 93, 94, 95,
	 96, 97, 98,
	 99, 100, 101,
	 102, 103, 104,
	 105, 106, 107,
	 108, 89, 109,
	 110, 111, 112,
	 113, 114, 115,
	 116, 117, 118,
	 119, 120, 121,
	 122, 123, 124,
	 125, 126, 127,
	 128, 129, 130,
	 131, 132, 133,
	 134, 135, 136,
	 137, 138, 139,
	 140, 141, 142,
	 143, 144, 145,
	 146, 147, 148,
	 149, 150, 151,
	 152, 153, 154,
	 155, 156, 157,
	 158, 159, 160,
	 161, 162, 163,
	 164, 165, 166,
	 167, 168, 169,
	 72, 74, 170,
	 75, 77, 171,
	 172, 173, 174,
	 175, 176, 177,
	 87, 83, 88,
	 178, 179, 180,
	 181, 182, 183,
	 184, 185, 186,
	 187, 188, 189,
};
#define _Chimney_indices_
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
#ifndef _Chimney_materials_
// Material Data follows: pulled from a .mtl file of the same name if present.
const OBJ_MATERIAL Chimney_materials[1] =
{
	{
		{{ 0.800000f, 0.800000f, 0.800000f },
		1.000000f,
		{ 0.005263f, 0.005263f, 0.005263f },
		225.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		60.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		1.000000f,
		{ 0.000000f, 0.000000f, 0.000000f },
		2},
		"Brick",
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
#define _Chimney_materials_
#endif
/************************************************/
/*  This section contains the model's structure */
/************************************************/
#ifndef _Chimney_batches_
// Use this conveinence array to batch render all geometry by like material.
// Each entry corresponds to the same entry in the materials array above.
// The two numbers provided are the IndexCount and the IndexOffset into the indices array.
// If you need more fine grained control(ex: for transformations) use the OBJ_MESH data below.
const unsigned int Chimney_batches[1][2] =
{
	{ 198, 0 },
};
#define _Chimney_batches_
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
#ifndef _Chimney_meshes_
// Mesh Data follows: Meshes are .obj groups sorted & split by material.
// Meshes are provided in sequential order, sorted by material first and name second.
const OBJ_MESH Chimney_meshes[1] =
{
	{
		"default",
		198,
		0,
		0,
	},
};
#define _Chimney_meshes_
#endif
