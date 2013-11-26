/*#ifndef RC_VARS_H
#define RC_VARS_H

namespace rc{
	
	typedef void             RCvoid;
	typedef char             RCchar;
	typedef unsigned int     RCenum;
	typedef unsigned char    RCboolean;
	typedef unsigned int     RCbitfield;
	typedef short            RCshort;
	typedef int              RCint;
	typedef int              RCsizei;
	typedef unsigned short   RCushort;
	typedef unsigned int     RCuint;


	// *********************************************************** //
	// taken from gl.h //

	// ClearBufferMask //
	#define RC_DEPTH_BUFFER_BIT               0x00000100
	#define RC_STENCIL_BUFFER_BIT             0x00000400
	#define RC_COLOR_BUFFER_BIT               0x00004000

	// Boolean //
	#define RC_FALSE                          0
	#define RC_TRUE                           1

	// BeginMode //
	#define RC_POINTS                         0x0000
	#define RC_LINES                          0x0001
	#define RC_LINE_LOOP                      0x0002
	#define RC_LINE_STRIP                     0x0003
	#define RC_TRIANRCES                      0x0004
	#define RC_TRIANRCE_STRIP                 0x0005
	#define RC_TRIANRCE_FAN                   0x0006

	// AlphaFunction //
	#define RC_NEVER                          0x0200
	#define RC_LESS                           0x0201
	#define RC_EQUAL                          0x0202
	#define RC_LEQUAL                         0x0203
	#define RC_GREATER                        0x0204
	#define RC_NOTEQUAL                       0x0205
	#define RC_GEQUAL                         0x0206
	#define RC_ALWAYS                         0x0207

	// BlendingFactorDest //
	#define RC_ZERO                           0
	#define RC_ONE                            1
	#define RC_SRC_COLOR                      0x0300
	#define RC_ONE_MINUS_SRC_COLOR            0x0301
	#define RC_SRC_ALPHA                      0x0302
	#define RC_ONE_MINUS_SRC_ALPHA            0x0303
	#define RC_DST_ALPHA                      0x0304
	#define RC_ONE_MINUS_DST_ALPHA            0x0305

	// BlendingFactorSrc //
	#define RC_DST_COLOR                      0x0306
	#define RC_ONE_MINUS_DST_COLOR            0x0307
	#define RC_SRC_ALPHA_SATURATE             0x0308

	// ClipPlaneName //
	#define RC_CLIP_PLANE0                    0x3000
	#define RC_CLIP_PLANE1                    0x3001
	#define RC_CLIP_PLANE2                    0x3002
	#define RC_CLIP_PLANE3                    0x3003
	#define RC_CLIP_PLANE4                    0x3004
	#define RC_CLIP_PLANE5                    0x3005

	// CullFaceMode //
	#define RC_FRONT                          0x0404
	#define RC_BACK                           0x0405
	#define RC_FRONT_AND_BACK                 0x0408

	// EnableCap //
	#define RC_FOG                            0x0B60
	#define RC_LIGHTING                       0x0B50
	#define RC_TEXTURE_2D                     0x0DE1
	#define RC_CULL_FACE                      0x0B44
	#define RC_ALPHA_TEST                     0x0BC0
	#define RC_BLEND                          0x0BE2
	#define RC_COLOR_LOGIC_OP                 0x0BF2
	#define RC_DITHER                         0x0BD0
	#define RC_STENCIL_TEST                   0x0B90
	#define RC_DEPTH_TEST                     0x0B71
	#define RC_POINT_SMOOTH                   0x0B10
	#define RC_LINE_SMOOTH                    0x0B20
	#define RC_SCISSOR_TEST                   0x0C11
	#define RC_COLOR_MATERIAL                 0x0B57
	#define RC_NORMALIZE                      0x0BA1
	#define RC_RESCALE_NORMAL                 0x803A
	#define RC_POLYGON_OFFSET_FILL            0x8037
	#define RC_VERTEX_ARRAY                   0x8074
	#define RC_NORMAL_ARRAY                   0x8075
	#define RC_COLOR_ARRAY                    0x8076
	#define RC_TEXTURE_COORD_ARRAY            0x8078
	#define RC_MULTISAMPLE                    0x809D
	#define RC_SAMPLE_ALPHA_TO_COVERAGE       0x809E
	#define RC_SAMPLE_ALPHA_TO_ONE            0x809F
	#define RC_SAMPLE_COVERAGE                0x80A0

	// ErrorCode //
	#define RC_NO_ERROR                       0
	#define RC_INVALID_ENUM                   0x0500
	#define RC_INVALID_VALUE                  0x0501
	#define RC_INVALID_OPERATION              0x0502
	#define RC_STACK_OVERFLOW                 0x0503
	#define RC_STACK_UNDERFLOW                0x0504
	#define RC_OUT_OF_MEMORY                  0x0505

	// FogMode //
	#define RC_EXP                            0x0800
	#define RC_EXP2                           0x0801

	// FogParameter //
	#define RC_FOG_DENSITY                    0x0B62
	#define RC_FOG_START                      0x0B63
	#define RC_FOG_END                        0x0B64
	#define RC_FOG_MODE                       0x0B65
	#define RC_FOG_COLOR                      0x0B66

	// FrontFaceDirection //
	#define RC_CW                             0x0900
	#define RC_CCW                            0x0901

	// GetPName //
	#define RC_CURRENT_COLOR                  0x0B00
	#define RC_CURRENT_NORMAL                 0x0B02
	#define RC_CURRENT_TEXTURE_COORDS         0x0B03
	#define RC_POINT_SIZE                     0x0B11
	#define RC_POINT_SIZE_MIN                 0x8126
	#define RC_POINT_SIZE_MAX                 0x8127
	#define RC_POINT_FADE_THRESHOLD_SIZE      0x8128
	#define RC_POINT_DISTANCE_ATTENUATION     0x8129
	#define RC_SMOOTH_POINT_SIZE_RANGE        0x0B12
	#define RC_LINE_WIDTH                     0x0B21
	#define RC_SMOOTH_LINE_WIDTH_RANGE        0x0B22
	#define RC_ALIASED_POINT_SIZE_RANGE       0x846D
	#define RC_ALIASED_LINE_WIDTH_RANGE       0x846E
	#define RC_CULL_FACE_MODE                 0x0B45
	#define RC_FRONT_FACE                     0x0B46
	#define RC_SHADE_MODEL                    0x0B54
	#define RC_DEPTH_RANGE                    0x0B70
	#define RC_DEPTH_WRITEMASK                0x0B72
	#define RC_DEPTH_CLEAR_VALUE              0x0B73
	#define RC_DEPTH_FUNC                     0x0B74
	#define RC_STENCIL_CLEAR_VALUE            0x0B91
	#define RC_STENCIL_FUNC                   0x0B92
	#define RC_STENCIL_VALUE_MASK             0x0B93
	#define RC_STENCIL_FAIL                   0x0B94
	#define RC_STENCIL_PASS_DEPTH_FAIL        0x0B95
	#define RC_STENCIL_PASS_DEPTH_PASS        0x0B96
	#define RC_STENCIL_REF                    0x0B97
	#define RC_STENCIL_WRITEMASK              0x0B98
	#define RC_MATRIX_MODE                    0x0BA0
	#define RC_VIEWPORT                       0x0BA2
	#define RC_MODELVIEW_STACK_DEPTH          0x0BA3
	#define RC_PROJECTION_STACK_DEPTH         0x0BA4
	#define RC_TEXTURE_STACK_DEPTH            0x0BA5
	#define RC_MODELVIEW_MATRIX               0x0BA6
	#define RC_PROJECTION_MATRIX              0x0BA7
	#define RC_TEXTURE_MATRIX                 0x0BA8
	#define RC_ALPHA_TEST_FUNC                0x0BC1
	#define RC_ALPHA_TEST_REF                 0x0BC2
	#define RC_BLEND_DST                      0x0BE0
	#define RC_BLEND_SRC                      0x0BE1
	#define RC_LOGIC_OP_MODE                  0x0BF0
	#define RC_SCISSOR_BOX                    0x0C10
	#define RC_SCISSOR_TEST                   0x0C11
	#define RC_COLOR_CLEAR_VALUE              0x0C22
	#define RC_COLOR_WRITEMASK                0x0C23
	#define RC_UNPACK_ALIGNMENT               0x0CF5
	#define RC_PACK_ALIGNMENT                 0x0D05
	#define RC_MAX_LIGHTS                     0x0D31
	#define RC_MAX_CLIP_PLANES                0x0D32
	#define RC_MAX_TEXTURE_SIZE               0x0D33
	#define RC_MAX_MODELVIEW_STACK_DEPTH      0x0D36
	#define RC_MAX_PROJECTION_STACK_DEPTH     0x0D38
	#define RC_MAX_TEXTURE_STACK_DEPTH        0x0D39
	#define RC_MAX_VIEWPORT_DIMS              0x0D3A
	#define RC_MAX_TEXTURE_UNITS              0x84E2
	#define RC_SUBPIXEL_BITS                  0x0D50
	#define RC_RED_BITS                       0x0D52
	#define RC_GREEN_BITS                     0x0D53
	#define RC_BLUE_BITS                      0x0D54
	#define RC_ALPHA_BITS                     0x0D55
	#define RC_DEPTH_BITS                     0x0D56
	#define RC_STENCIL_BITS                   0x0D57
	#define RC_POLYGON_OFFSET_UNITS           0x2A00
	#define RC_POLYGON_OFFSET_FILL            0x8037
	#define RC_POLYGON_OFFSET_FACTOR          0x8038
	#define RC_TEXTURE_BINDING_2D             0x8069
	#define RC_VERTEX_ARRAY_SIZE              0x807A
	#define RC_VERTEX_ARRAY_TYPE              0x807B
	#define RC_VERTEX_ARRAY_STRIDE            0x807C
	#define RC_NORMAL_ARRAY_TYPE              0x807E
	#define RC_NORMAL_ARRAY_STRIDE            0x807F
	#define RC_COLOR_ARRAY_SIZE               0x8081
	#define RC_COLOR_ARRAY_TYPE               0x8082
	#define RC_COLOR_ARRAY_STRIDE             0x8083
	#define RC_TEXTURE_COORD_ARRAY_SIZE       0x8088
	#define RC_TEXTURE_COORD_ARRAY_TYPE       0x8089
	#define RC_TEXTURE_COORD_ARRAY_STRIDE     0x808A
	#define RC_VERTEX_ARRAY_POINTER           0x808E
	#define RC_NORMAL_ARRAY_POINTER           0x808F
	#define RC_COLOR_ARRAY_POINTER            0x8090
	#define RC_TEXTURE_COORD_ARRAY_POINTER    0x8092
	#define RC_SAMPLE_BUFFERS                 0x80A8
	#define RC_SAMPLES                        0x80A9
	#define RC_SAMPLE_COVERAGE_VALUE          0x80AA
	#define RC_SAMPLE_COVERAGE_INVERT         0x80AB

	// GetTextureParameter //
	#define RC_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
	#define RC_COMPRESSED_TEXTURE_FORMATS     0x86A3

	// HintMode //
	#define RC_DONT_CARE                      0x1100
	#define RC_FASTEST                        0x1101
	#define RC_NICEST                         0x1102

	// HintTarget //
	#define RC_PERSPECTIVE_CORRECTION_HINT    0x0C50
	#define RC_POINT_SMOOTH_HINT              0x0C51
	#define RC_LINE_SMOOTH_HINT               0x0C52
	#define RC_FOG_HINT                       0x0C54
	#define RC_GENERATE_MIPMAP_HINT           0x8192

	// LightModelParameter //
	#define RC_LIGHT_MODEL_AMBIENT            0x0B53
	#define RC_LIGHT_MODEL_TWO_SIDE           0x0B52

	// LightParameter //
	#define RC_AMBIENT                        0x1200
	#define RC_DIFFUSE                        0x1201
	#define RC_SPECULAR                       0x1202
	#define RC_POSITION                       0x1203
	#define RC_SPOT_DIRECTION                 0x1204
	#define RC_SPOT_EXPONENT                  0x1205
	#define RC_SPOT_CUTOFF                    0x1206
	#define RC_CONSTANT_ATTENUATION           0x1207
	#define RC_LINEAR_ATTENUATION             0x1208
	#define RC_QUADRATIC_ATTENUATION          0x1209

	// DataType //
	#define RC_BYTE                           0x1400
	#define RC_UNSIGNED_BYTE                  0x1401
	#define RC_SHORT                          0x1402
	#define RC_UNSIGNED_SHORT                 0x1403
	#define RC_FLOAT                          0x1406
	#define RC_FIXED                          0x140C

	// LogicOp //
	#define RC_CLEAR                          0x1500
	#define RC_AND                            0x1501
	#define RC_AND_REVERSE                    0x1502
	#define RC_COPY                           0x1503
	#define RC_AND_INVERTED                   0x1504
	#define RC_NOOP                           0x1505
	#define RC_XOR                            0x1506
	#define RC_OR                             0x1507
	#define RC_NOR                            0x1508
	#define RC_EQUIV                          0x1509
	#define RC_INVERT                         0x150A
	#define RC_OR_REVERSE                     0x150B
	#define RC_COPY_INVERTED                  0x150C
	#define RC_OR_INVERTED                    0x150D
	#define RC_NAND                           0x150E
	#define RC_SET                            0x150F

	// MaterialParameter //
	#define RC_EMISSION                       0x1600
	#define RC_SHININESS                      0x1601
	#define RC_AMBIENT_AND_DIFFUSE            0x1602
	
	// MatrixMode //
	#define RC_MODELVIEW                      0x1700
	#define RC_PROJECTION                     0x1701
	#define RC_TEXTURE                        0x1702

	// PixelFormat //
	#define RC_ALPHA                          0x1906
	#define RC_RGB                            0x1907
	#define RC_RGBA                           0x1908
	#define RC_LUMINANCE                      0x1909
	#define RC_LUMINANCE_ALPHA                0x190A

	// PixelStoreParameter //
	#define RC_UNPACK_ALIGNMENT               0x0CF5
	#define RC_PACK_ALIGNMENT                 0x0D05

	// PixelType //
	#define RC_UNSIGNED_SHORT_4_4_4_4         0x8033
	#define RC_UNSIGNED_SHORT_5_5_5_1         0x8034
	#define RC_UNSIGNED_SHORT_5_6_5           0x8363

	// ShadingModel //
	#define RC_FLAT                           0x1D00
	#define RC_SMOOTH                         0x1D01

	// StencilOp //
	#define RC_KEEP                           0x1E00
	#define RC_REPLACE                        0x1E01
	#define RC_INCR                           0x1E02
	#define RC_DECR                           0x1E03
	
	// StringName //
	#define RC_VENDOR                         0x1F00
	#define RC_RENDERER                       0x1F01
	#define RC_VERSION                        0x1F02
	#define RC_EXTENSIONS                     0x1F03

	// TextureEnvMode //
	#define RC_MODULATE                       0x2100
	#define RC_DECAL                          0x2101
	#define RC_ADD                            0x0104
	
	// TextureEnvParameter //
	#define RC_TEXTURE_ENV_MODE               0x2200
	#define RC_TEXTURE_ENV_COLOR              0x2201

	// TextureEnvTarget //
	#define RC_TEXTURE_ENV                    0x2300

	// TextureMagFilter //
	#define RC_NEAREST                        0x2600
	#define RC_LINEAR                         0x2601

	// TextureMinFilter //
	#define RC_NEAREST_MIPMAP_NEAREST         0x2700
	#define RC_LINEAR_MIPMAP_NEAREST          0x2701
	#define RC_NEAREST_MIPMAP_LINEAR          0x2702
	#define RC_LINEAR_MIPMAP_LINEAR           0x2703

	// TextureParameterName //
	#define RC_TEXTURE_MAG_FILTER             0x2800
	#define RC_TEXTURE_MIN_FILTER             0x2801
	#define RC_TEXTURE_WRAP_S                 0x2802
	#define RC_TEXTURE_WRAP_T                 0x2803
	#define RC_GENERATE_MIPMAP                0x8191

	// TextureUnit //
	#define RC_TEXTURE0                       0x84C0
	#define RC_TEXTURE1                       0x84C1
	#define RC_TEXTURE2                       0x84C2
	#define RC_TEXTURE3                       0x84C3
	#define RC_TEXTURE4                       0x84C4
	#define RC_TEXTURE5                       0x84C5
	#define RC_TEXTURE6                       0x84C6
	#define RC_TEXTURE7                       0x84C7
	#define RC_TEXTURE8                       0x84C8
	#define RC_TEXTURE9                       0x84C9
	#define RC_TEXTURE10                      0x84CA
	#define RC_TEXTURE11                      0x84CB
	#define RC_TEXTURE12                      0x84CC
	#define RC_TEXTURE13                      0x84CD
	#define RC_TEXTURE14                      0x84CE
	#define RC_TEXTURE15                      0x84CF
	#define RC_TEXTURE16                      0x84D0
	#define RC_TEXTURE17                      0x84D1
	#define RC_TEXTURE18                      0x84D2
	#define RC_TEXTURE19                      0x84D3
	#define RC_TEXTURE20                      0x84D4
	#define RC_TEXTURE21                      0x84D5
	#define RC_TEXTURE22                      0x84D6
	#define RC_TEXTURE23                      0x84D7
	#define RC_TEXTURE24                      0x84D8
	#define RC_TEXTURE25                      0x84D9
	#define RC_TEXTURE26                      0x84DA
	#define RC_TEXTURE27                      0x84DB
	#define RC_TEXTURE28                      0x84DC
	#define RC_TEXTURE29                      0x84DD
	#define RC_TEXTURE30                      0x84DE
	#define RC_TEXTURE31                      0x84DF
	#define RC_ACTIVE_TEXTURE                 0x84E0
	#define RC_CLIENT_ACTIVE_TEXTURE          0x84E1

	// TextureWrapMode //
	#define RC_REPEAT                         0x2901
	#define RC_CLAMP_TO_EDGE                  0x812F

	// LightName //
	#define RC_LIGHT0                         0x4000
	#define RC_LIGHT1                         0x4001
	#define RC_LIGHT2                         0x4002
	#define RC_LIGHT3                         0x4003
	#define RC_LIGHT4                         0x4004
	#define RC_LIGHT5                         0x4005
	#define RC_LIGHT6                         0x4006
	#define RC_LIGHT7                         0x4007

	// Buffer Objects //
	#define RC_ARRAY_BUFFER                   0x8892
	#define RC_ELEMENT_ARRAY_BUFFER           0x8893

	#define RC_ARRAY_BUFFER_BINDING               0x8894
	#define RC_ELEMENT_ARRAY_BUFFER_BINDING       0x8895
	#define RC_VERTEX_ARRAY_BUFFER_BINDING        0x8896
	#define RC_NORMAL_ARRAY_BUFFER_BINDING        0x8897
	#define RC_COLOR_ARRAY_BUFFER_BINDING         0x8898
	#define RC_TEXTURE_COORD_ARRAY_BUFFER_BINDING 0x889A

	#define RC_STATIC_DRAW                    0x88E4
	#define RC_DYNAMIC_DRAW                   0x88E8

	#define RC_BUFFER_SIZE                    0x8764
	#define RC_BUFFER_USAGE                   0x8765

	// Texture combine + dot3 //
	#define RC_SUBTRACT                       0x84E7
	#define RC_COMBINE                        0x8570
	#define RC_COMBINE_RGB                    0x8571
	#define RC_COMBINE_ALPHA                  0x8572
	#define RC_RGB_SCALE                      0x8573
	#define RC_ADD_SIGNED                     0x8574
	#define RC_INTERPOLATE                    0x8575
	#define RC_CONSTANT                       0x8576
	#define RC_PRIMARY_COLOR                  0x8577
	#define RC_PREVIOUS                       0x8578
	#define RC_OPERAND0_RGB                   0x8590
	#define RC_OPERAND1_RGB                   0x8591
	#define RC_OPERAND2_RGB                   0x8592
	#define RC_OPERAND0_ALPHA                 0x8598
	#define RC_OPERAND1_ALPHA                 0x8599
	#define RC_OPERAND2_ALPHA                 0x859A

	#define RC_ALPHA_SCALE                    0x0D1C

	#define RC_SRC0_RGB                       0x8580
	#define RC_SRC1_RGB                       0x8581
	#define RC_SRC2_RGB                       0x8582
	#define RC_SRC0_ALPHA                     0x8588
	#define RC_SRC1_ALPHA                     0x8589
	#define RC_SRC2_ALPHA                     0x858A

	#define RC_DOT3_RGB                       0x86AE
	#define RC_DOT3_RGBA                      0x86AF

	// Remote control definitions //
	// data types
	const int RC_INT =				0x9002;
	#define BOOL			0x9003;
	#define FLOAT			0x9004;
	#define STRING			0x9005;
	#define DOUBLE			0x9006;
	#define CHAR			0x900C;
	
	// abstract data types
	#define SCALAR			0x9007;
	#define VECTOR			0x9008;
	#define TEXT			0x9009;
	#define MATRIX			0x900A;
	#define IMAGE			0x900B;

	// commands
	#define UP				0x900D;
	#define DOWN			0x900E;
	#define LEFT			0x900F;
	#define RIGHT			0x9010;
	#define FORWARD			0x9011;
	#define BACKWARD		0x9012;
	#define JUMP			0x9013;
	#define SHOOT			0x9014;
	#define SIDESTEP_LEFT   0x9015;
	#define SIDESTEP_RIGHT  0x9016;
	#define SIDESTEP		0x9017;
	#define SPEED			0x9018;
	#define SLOW_DOWN		0x9018;
	#define SPEED_UP		0x9018;
	#define STEP			0x9018;
	#define TRANSLATION		0x9018;
	#define ROTATION		0x9018;
	#define SCALE			0x9018;
	#define AXIS			0x9018;
	#define AXIS_X			0x9018;
	#define AXIS_Y			0x9018;
	#define AXIS_Z			0x9018;
	#define BEND			0x9019;
	#define STAND_UP		0x901A;
	#define STRAIGHTEN		0x901B;
	#define STOP			0x901C;
	#define QUIT			0x901D;
	#define EXIT			0x901E;
	#define COLOR			0x901F;
	#define BLACK			0x9020;
	#define WHITE			0x9021;
	#define BLUE			0x9022;
	#define RED				0x9023;
	#define GREEN			0x9024;
	#define YELLOW			0x9025;
	#define MAGENTA			0x9026;
	#define CYAN			0x9027;
	#define GREY			0x9028;
	#define DARKEN			0x9029;
	#define LIGHTEN			0x902A;
	#define VERTEX			0x902B;
	#define EDGE			0x902C;
	#define FACE			0x902D;
	#define SCREEN			0x902E;
	#define CUBE			0x902F;
	#define ROUND			0x9030;
	#define RC_2D			0x9031;
	#define RC_3D			0x9032;
	#define SPHERE			0x9033;
	#define PRIMITIVE		0x9034;
	
	// Android controllers
	#define BUTTON			0x9035;
	#define TOGGLE_BUTTON   0x9036;
	#define RADIO_BUTTON	0x9037;
	#define CHECKBOX		0x9038;
	
	#define CHECKEDTEXTVIEW		0x9038;
	#define SPINNER		0x9038;
	#define PROGRESSBAR			43;
	#define SEEKBAR			43;
	#define QUICKCONTACTBADGE			43;
	#define RADIOGROUP			43;
	#define RATINGBAR			43;
	// text fields
	#define PLAINTEXT			43;
	#define PERSONNAME			43;
	#define PASSWORD			43;
	#define NUMPASSWORD			43;
	#define EMAIL			43;
	#define PHONE			43;
	#define ADDRESS			43;
	#define MULTILINE			43;
	#define TIME			43;
	#define DATE			43;
	#define NUMBER			43;
	#define NUMBER_SIGNED			43;
	#define NUMBER_DECIMAL			43;
	#define AUTOCOMPLETETEXTVIEW			43;
	#define MULTIAUTOCOMPLETETEXTVIEW			43;

	// layouts
	#define GRIDLAYOUT			43;
	#define LINEARLAYOUT_V			43;
	#define LINEARLAYOUT_H			43;
	#define RELATIVELAYOUT			43;
	#define FRAMELAYOUT			43;
	#define INCLUDEOTHERLAYOUT			43;
	#define FRAGMENT			43;
	#define TABLELAYOUT			43;
	#define TABLEROW			43;
	#define SPACE			43;
	// composite
	#define LISTVIEW			43;
	#define EXPANDABLELISTVIEW			43;
	#define GRIDVIEW			43;
	#define SCROLLVIEW			43;
	#define SCROLLVIEW_H			43;
	#define SEARCHVIEW			43;
	#define SLIDINGDRAWER			43;
	#define TABHOST			43;
	#define TABWIDGET			43;
	#define WEBVIEW			43;
	// images & media
	#define IMAGEVIEW			43;
	#define IMAGEBUTTON			43;
	#define GALLERY			43;
	#define MEDIACONTROLLER			43;
	#define VIDEOVIEW			43;
	// time & date
	#define TIMEPICKER			43;
	#define DATEPICKER			43;
	#define CALENDARVIEW			43;
	#define CHRONOMETR			43;
	#define ANALOGCLOCK			43;
	#define DIGITALCLOCK			43;
	// transitions
	#define IMAGESWITCHER			43;
	#define ADAPTERVIEWFLIPPER			43;
	#define STACKVIEW			43;
	#define TEXTSWITCHER			43;
	#define VIEWANIMATOR			43;
	#define VIEWFLIPPER			43;
	#define VIEWSWITCHER			43;
	// advanced
	#define REQUESTFOCUS			43;
	#define VIEW			43;
	#define VIEWSTUP			43;
	#define GESTUREOVERLAYVIEW			43;
	#define TEXTUREVIEW			43;
	#define SURFACEVIEW			43;
	#define NUMBERPICKER			43;
	#define ZOOMBUTTON			43;
	#define ZOOMCONTROLS			43;
	#define DIALERFILTER			43;
	#define TWOLINELISTITEM			43;
	#define ABSOLUTELAYOUT			43;
	// other
	#define TEXTCLOCK			43;
	#define TEXTSWITCHER			43;
	#define VIEWANIMATOR			43;

	// sensors
	const int ACCELEROMETER =			43;
}

#endif // RC_VARS_H //
*/
/*
#ifndef RC_VARS_H
#define RC_VARS_H

namespace rc{
	
	typedef void             RCvoid;
	typedef char             RCchar;
	typedef unsigned int     RCenum;
	typedef unsigned char    RCboolean;
	typedef unsigned int     RCbitfield;
	typedef short            RCshort;
	typedef int              RCint;
	typedef int              RCsizei;
	typedef unsigned short   RCushort;
	typedef unsigned int     RCuint;


	// *********************************************************** //
	// taken from gl.h 

	// ClearBufferMask 
	#define RC_DEPTH_BUFFER_BIT               0x00000100
	#define RC_STENCIL_BUFFER_BIT             0x00000400
	#define RC_COLOR_BUFFER_BIT               0x00004000

	// Boolean 
	const int RC_FALSE                          0
	const int RC_TRUE                           1

	// BeginMode 
	const int RC_POINTS                         0x0000
	const int RC_LINES                          0x0001
	const int RC_LINE_LOOP                      0x0002
	const int RC_LINE_STRIP                     0x0003
	const int RC_TRIANRCES                      0x0004
	const int RC_TRIANRCE_STRIP                 0x0005
	const int RC_TRIANRCE_FAN                   0x0006

	// AlphaFunction 
	const int RC_NEVER                          0x0200
	const int RC_LESS                           0x0201
	const int RC_EQUAL                          0x0202
	const int RC_LEQUAL                         0x0203
	const int RC_GREATER                        0x0204
	const int RC_NOTEQUAL                       0x0205
	const int RC_GEQUAL                         0x0206
	const int RC_ALWAYS                         0x0207

	// BlendingFactorDest 
	const int RC_ZERO                           0
	const int RC_ONE                            1
	const int RC_SRC_COLOR                      0x0300
	const int RC_ONE_MINUS_SRC_COLOR            0x0301
	const int RC_SRC_ALPHA                      0x0302
	const int RC_ONE_MINUS_SRC_ALPHA            0x0303
	const int RC_DST_ALPHA                      0x0304
	const int RC_ONE_MINUS_DST_ALPHA            0x0305

	// BlendingFactorSrc 
	const int RC_DST_COLOR                      0x0306
	const int RC_ONE_MINUS_DST_COLOR            0x0307
	const int RC_SRC_ALPHA_SATURATE             0x0308

	// ClipPlaneName 
	const int RC_CLIP_PLANE0                    0x3000
	const int RC_CLIP_PLANE1                    0x3001
	const int RC_CLIP_PLANE2                    0x3002
	const int RC_CLIP_PLANE3                    0x3003
	const int RC_CLIP_PLANE4                    0x3004
	const int RC_CLIP_PLANE5                    0x3005

	// CullFaceMode 
	const int RC_FRONT                          0x0404
	const int RC_BACK                           0x0405
	const int RC_FRONT_AND_BACK                 0x0408

	// EnableCap 
	const int RC_FOG                            0x0B60
	const int RC_LIGHTING                       0x0B50
	const int RC_TEXTURE_2D                     0x0DE1
	const int RC_CULL_FACE                      0x0B44
	const int RC_ALPHA_TEST                     0x0BC0
	const int RC_BLEND                          0x0BE2
	const int RC_COLOR_LOGIC_OP                 0x0BF2
	const int RC_DITHER                         0x0BD0
	const int RC_STENCIL_TEST                   0x0B90
	const int RC_DEPTH_TEST                     0x0B71
	const int RC_POINT_SMOOTH                   0x0B10
	const int RC_LINE_SMOOTH                    0x0B20
	const int RC_SCISSOR_TEST                   0x0C11
	const int RC_COLOR_MATERIAL                 0x0B57
	const int RC_NORMALIZE                      0x0BA1
	const int RC_RESCALE_NORMAL                 0x803A
	const int RC_POLYGON_OFFSET_FILL            0x8037
	const int RC_VERTEX_ARRAY                   0x8074
	const int RC_NORMAL_ARRAY                   0x8075
	const int RC_COLOR_ARRAY                    0x8076
	const int RC_TEXTURE_COORD_ARRAY            0x8078
	const int RC_MULTISAMPLE                    0x809D
	const int RC_SAMPLE_ALPHA_TO_COVERAGE       0x809E
	const int RC_SAMPLE_ALPHA_TO_ONE            0x809F
	const int RC_SAMPLE_COVERAGE                0x80A0

	// ErrorCode 
	const int RC_NO_ERROR                       0
	const int RC_INVALID_ENUM                   0x0500
	const int RC_INVALID_VALUE                  0x0501
	const int RC_INVALID_OPERATION              0x0502
	const int RC_STACK_OVERFLOW                 0x0503
	const int RC_STACK_UNDERFLOW                0x0504
	const int RC_OUT_OF_MEMORY                  0x0505

	// FogMode 
	const int RC_EXP                            0x0800
	const int RC_EXP2                           0x0801

	// FogParameter 
	const int RC_FOG_DENSITY                    0x0B62
	const int RC_FOG_START                      0x0B63
	const int RC_FOG_END                        0x0B64
	const int RC_FOG_MODE                       0x0B65
	const int RC_FOG_COLOR                      0x0B66

	// FrontFaceDirection 
	const int RC_CW                             0x0900
	const int RC_CCW                            0x0901

	// GetPName 
	const int RC_CURRENT_COLOR                  0x0B00;
	const int RC_CURRENT_NORMAL                 0x0B02;
	const int RC_CURRENT_TEXTURE_COORDS         0x0B03;
	const int RC_POINT_SIZE                     0x0B11;
	const int RC_POINT_SIZE_MIN                 0x8126;
	const int RC_POINT_SIZE_MAX                 0x8127;
	const int RC_POINT_FADE_THRESHOLD_SIZE      0x8128;
	const int RC_POINT_DISTANCE_ATTENUATION     0x8129;
	const int RC_SMOOTH_POINT_SIZE_RANGE        0x0B12;
	const int RC_LINE_WIDTH                     0x0B21;
	const int RC_SMOOTH_LINE_WIDTH_RANGE        0x0B22;
	const int RC_ALIASED_POINT_SIZE_RANGE       0x846D;
	const int RC_ALIASED_LINE_WIDTH_RANGE       0x846E;
	const int RC_CULL_FACE_MODE                 0x0B45;
	const int RC_FRONT_FACE                     0x0B46;
	const int RC_SHADE_MODEL                    0x0B54;
	const int RC_DEPTH_RANGE                    0x0B70;
	const int RC_DEPTH_WRITEMASK                0x0B72;
	const int RC_DEPTH_CLEAR_VALUE              0x0B73;
	const int RC_DEPTH_FUNC                     0x0B74;
	const int RC_STENCIL_CLEAR_VALUE            0x0B91;
	const int RC_STENCIL_FUNC                   0x0B92;
	const int RC_STENCIL_VALUE_MASK             0x0B93;
	const int RC_STENCIL_FAIL                   0x0B94;
	const int RC_STENCIL_PASS_DEPTH_FAIL        0x0B95;
	const int RC_STENCIL_PASS_DEPTH_PASS        0x0B96;
	const int RC_STENCIL_REF                    0x0B97;
	const int RC_STENCIL_WRITEMASK              0x0B98;
	const int RC_MATRIX_MODE                    0x0BA0;
	const int RC_VIEWPORT                       0x0BA2;
	const int RC_MODELVIEW_STACK_DEPTH          0x0BA3;
	const int RC_PROJECTION_STACK_DEPTH         0x0BA4;
	const int RC_TEXTURE_STACK_DEPTH            0x0BA5;
	const int RC_MODELVIEW_MATRIX               0x0BA6;
	const int RC_PROJECTION_MATRIX              0x0BA7;
	const int RC_TEXTURE_MATRIX                 0x0BA8;
	const int RC_ALPHA_TEST_FUNC                0x0BC1;
	const int RC_ALPHA_TEST_REF                 0x0BC2;
	const int RC_BLEND_DST                      0x0BE0;
	const int RC_BLEND_SRC                      0x0BE1;
	const int RC_LOGIC_OP_MODE                  0x0BF0;
	const int RC_SCISSOR_BOX                    0x0C10;
	const int RC_SCISSOR_TEST                   0x0C11;
	const int RC_COLOR_CLEAR_VALUE              0x0C22;
	const int RC_COLOR_WRITEMASK                0x0C23;
	const int RC_UNPACK_ALIGNMENT               0x0CF5;
	const int RC_PACK_ALIGNMENT                 0x0D05;
	const int RC_MAX_LIGHTS                     0x0D31;
	const int RC_MAX_CLIP_PLANES                0x0D32;
	const int RC_MAX_TEXTURE_SIZE               0x0D33;
	const int RC_MAX_MODELVIEW_STACK_DEPTH      0x0D36;
	const int RC_MAX_PROJECTION_STACK_DEPTH     0x0D38;
	const int RC_MAX_TEXTURE_STACK_DEPTH        0x0D39;
	const int RC_MAX_VIEWPORT_DIMS              0x0D3A;
	const int RC_MAX_TEXTURE_UNITS              0x84E2;
	const int RC_SUBPIXEL_BITS                  0x0D50;
	const int RC_RED_BITS                       0x0D52;
	const int RC_GREEN_BITS                     0x0D53;
	const int RC_BLUE_BITS                      0x0D54;
	const int RC_ALPHA_BITS                     0x0D55;
	const int RC_DEPTH_BITS                     0x0D56;
	const int RC_STENCIL_BITS                   0x0D57;
	const int RC_POLYGON_OFFSET_UNITS           0x2A00;
	const int RC_POLYGON_OFFSET_FILL            0x8037;
	const int RC_POLYGON_OFFSET_FACTOR          0x8038;
	const int RC_TEXTURE_BINDING_2D             0x8069;
	const int RC_VERTEX_ARRAY_SIZE              0x807A;
	const int RC_VERTEX_ARRAY_TYPE              0x807B;
	const int RC_VERTEX_ARRAY_STRIDE            0x807C;
	const int RC_NORMAL_ARRAY_TYPE              0x807E;
	const int RC_NORMAL_ARRAY_STRIDE            0x807F;
	const int RC_COLOR_ARRAY_SIZE               0x8081;
	const int RC_COLOR_ARRAY_TYPE               0x8082;
	const int RC_COLOR_ARRAY_STRIDE             0x8083;
	const int RC_TEXTURE_COORD_ARRAY_SIZE       0x8088;
	const int RC_TEXTURE_COORD_ARRAY_TYPE       0x8089;
	const int RC_TEXTURE_COORD_ARRAY_STRIDE     0x808A;
	const int RC_VERTEX_ARRAY_POINTER           0x808E;
	const int RC_NORMAL_ARRAY_POINTER           0x808F;
	const int RC_COLOR_ARRAY_POINTER            0x8090;
	const int RC_TEXTURE_COORD_ARRAY_POINTER    0x8092;
	const int RC_SAMPLE_BUFFERS                 0x80A8;
	const int RC_SAMPLES                        0x80A9;
	const int RC_SAMPLE_COVERAGE_VALUE          0x80AA;
	const int RC_SAMPLE_COVERAGE_INVERT         0x80AB;

	// GetTextureParameter 
	const int RC_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2;
	const int RC_COMPRESSED_TEXTURE_FORMATS     0x86A3;

	// HintMode 
	const int RC_DONT_CARE                      0x1100;
	const int RC_FASTEST                        0x1101;
	const int RC_NICEST                         0x1102;

	// HintTarget 
	const int RC_PERSPECTIVE_CORRECTION_HINT    0x0C50;
	const int RC_POINT_SMOOTH_HINT              0x0C51;
	const int RC_LINE_SMOOTH_HINT               0x0C52;
	const int RC_FOG_HINT                       0x0C54;
	const int RC_GENERATE_MIPMAP_HINT           0x8192;

	// LightModelParameter 
	const int RC_LIGHT_MODEL_AMBIENT            0x0B53;
	const int RC_LIGHT_MODEL_TWO_SIDE           0x0B52;

	// LightParameter 
	const int RC_AMBIENT                        0x1200;
	const int RC_DIFFUSE                        0x1201;
	const int RC_SPECULAR                       0x1202;
	const int RC_POSITION                       0x1203;
	const int RC_SPOT_DIRECTION                 0x1204;
	const int RC_SPOT_EXPONENT                  0x1205;
	const int RC_SPOT_CUTOFF                    0x1206;
	const int RC_CONSTANT_ATTENUATION           0x1207;
	const int RC_LINEAR_ATTENUATION             0x1208;
	const int RC_QUADRATIC_ATTENUATION          0x1209;

	// DataType 
	const int RC_BYTE                           0x1400;
	const int RC_UNSIGNED_BYTE                  0x1401;
	const int RC_SHORT                          0x1402;
	const int RC_UNSIGNED_SHORT                 0x1403;
	const int RC_FLOAT                          0x1406;
	const int RC_FIXED                          0x140C;

	// LogicOp 
	const int RC_CLEAR                          0x1500;
	const int RC_AND                            0x1501;
	const int RC_AND_REVERSE                    0x1502;
	const int RC_COPY                           0x1503;
	const int RC_AND_INVERTED                   0x1504;
	const int RC_NOOP                           0x1505;
	const int RC_XOR                            0x1506;
	const int RC_OR                             0x1507;
	const int RC_NOR                            0x1508;
	const int RC_EQUIV                          0x1509;
	const int RC_INVERT                         0x150A;
	const int RC_OR_REVERSE                     0x150B;
	const int RC_COPY_INVERTED                  0x150C;
	const int RC_OR_INVERTED                    0x150D;
	const int RC_NAND                           0x150E;
	const int RC_SET                            0x150F;

	// MaterialParameter 
	const int RC_EMISSION                       0x1600;
	const int RC_SHININESS                      0x1601;
	const int RC_AMBIENT_AND_DIFFUSE            0x1602;
	
	// MatrixMode 
	const int RC_MODELVIEW                      0x1700;
	const int RC_PROJECTION                     0x1701;
	const int RC_TEXTURE                        0x1702;

	// PixelFormat 
	const int RC_ALPHA                          0x1906;
	const int RC_RGB                            0x1907;
	const int RC_RGBA                           0x1908;
	const int RC_LUMINANCE                      0x1909;
	const int RC_LUMINANCE_ALPHA                0x190A;

	// PixelStoreParameter 
	const int RC_UNPACK_ALIGNMENT               0x0CF5;
	const int RC_PACK_ALIGNMENT                 0x0D05;

	// PixelType 
	const int RC_UNSIGNED_SHORT_4_4_4_4         0x8033;
	const int RC_UNSIGNED_SHORT_5_5_5_1         0x8034;
	const int RC_UNSIGNED_SHORT_5_6_5           0x8363;

	// ShadingModel 
	const int RC_FLAT                           0x1D00;
	const int RC_SMOOTH                         0x1D01;

	// StencilOp 
	const int RC_KEEP                           0x1E00;
	const int RC_REPLACE                        0x1E01;
	const int RC_INCR                           0x1E02;
	const int RC_DECR                           0x1E03;
	
	// StringName
	const int RC_VENDOR                         0x1F00;
	const int RC_RENDERER                       0x1F01;
	const int RC_VERSION                        0x1F02;
	const int RC_EXTENSIONS                     0x1F03;

	// TextureEnvMode
	const int RC_MODULATE                       0x2100;
	const int RC_DECAL                          0x2101;
	const int RC_ADD                            0x0104;
	
	// TextureEnvParameter
	const int RC_TEXTURE_ENV_MODE               0x2200;
	const int RC_TEXTURE_ENV_COLOR              0x2201;

	// TextureEnvTarget
	const int RC_TEXTURE_ENV                    0x2300;

	// TextureMagFilter
	const int RC_NEAREST                        0x2600;
	const int RC_LINEAR                         0x2601;

	// TextureMinFilter
	const int RC_NEAREST_MIPMAP_NEAREST         0x2700;
	const int RC_LINEAR_MIPMAP_NEAREST          0x2701;
	const int RC_NEAREST_MIPMAP_LINEAR          0x2702;
	const int RC_LINEAR_MIPMAP_LINEAR           0x2703;

	// TextureParameterName
	const int RC_TEXTURE_MAG_FILTER             0x2800;
	const int RC_TEXTURE_MIN_FILTER             0x2801;
	const int RC_TEXTURE_WRAP_S                 0x2802;
	const int RC_TEXTURE_WRAP_T                 0x2803;
	const int RC_GENERATE_MIPMAP                0x8191;

	// TextureUnit
	const int RC_TEXTURE0                       0x84C0;
	const int RC_TEXTURE1                       0x84C1;
	const int RC_TEXTURE2                       0x84C2;
	const int RC_TEXTURE3                       0x84C3;
	const int RC_TEXTURE4                       0x84C4;
	const int RC_TEXTURE5                       0x84C5;
	const int RC_TEXTURE6                       0x84C6;
	const int RC_TEXTURE7                       0x84C7;
	const int RC_TEXTURE8                       0x84C8;
	const int RC_TEXTURE9                       0x84C9;
	const int RC_TEXTURE10                      0x84CA;
	const int RC_TEXTURE11                      0x84CB;
	const int RC_TEXTURE12                      0x84CC;
	const int RC_TEXTURE13                      0x84CD;
	const int RC_TEXTURE14                      0x84CE;
	const int RC_TEXTURE15                      0x84CF;
	const int RC_TEXTURE16                      0x84D0;
	const int RC_TEXTURE17                      0x84D1;
	const int RC_TEXTURE18                      0x84D2;
	const int RC_TEXTURE19                      0x84D3;
	const int RC_TEXTURE20                      0x84D4;
	const int RC_TEXTURE21                      0x84D5;
	const int RC_TEXTURE22                      0x84D6;
	const int RC_TEXTURE23                      0x84D7;
	const int RC_TEXTURE24                      0x84D8;
	const int RC_TEXTURE25                      0x84D9;
	const int RC_TEXTURE26                      0x84DA;
	const int RC_TEXTURE27                      0x84DB;
	const int RC_TEXTURE28                      0x84DC;
	const int RC_TEXTURE29                      0x84DD;
	const int RC_TEXTURE30                      0x84DE;
	const int RC_TEXTURE31                      0x84DF;
	const int RC_ACTIVE_TEXTURE                 0x84E0;
	const int RC_CLIENT_ACTIVE_TEXTURE          0x84E1;

	// TextureWrapMode //
	const int RC_REPEAT                         0x2901
	const int RC_CLAMP_TO_EDGE                  0x812F

	// LightName //
	const int RC_LIGHT0                         0x4000;
	const int RC_LIGHT1                         0x4001;
	const int RC_LIGHT2                         0x4002;
	const int RC_LIGHT3                         0x4003;
	const int RC_LIGHT4                         0x4004;
	const int RC_LIGHT5                         0x4005;
	const int RC_LIGHT6                         0x4006;
	const int RC_LIGHT7                         0x4007;

	// Buffer Objects //
	const int RC_ARRAY_BUFFER                   0x8892;
	const int RC_ELEMENT_ARRAY_BUFFER           0x8893;

	const int RC_ARRAY_BUFFER_BINDING               0x8894;
	const int RC_ELEMENT_ARRAY_BUFFER_BINDING       0x8895;
	const int RC_VERTEX_ARRAY_BUFFER_BINDING        0x8896;
	const int RC_NORMAL_ARRAY_BUFFER_BINDING        0x8897;
	const int RC_COLOR_ARRAY_BUFFER_BINDING         0x8898;
	const int RC_TEXTURE_COORD_ARRAY_BUFFER_BINDING 0x889A;

	const int RC_STATIC_DRAW                    0x88E4;
	const int RC_DYNAMIC_DRAW                   0x88E8;

	const int RC_BUFFER_SIZE                    0x8764;
	const int RC_BUFFER_USAGE                   0x8765;

	// Texture combine + dot3 //
	const int RC_SUBTRACT                       0x84E7;
	const int RC_COMBINE                        0x8570;
	const int RC_COMBINE_RGB                    0x8571;
	const int RC_COMBINE_ALPHA                  0x8572;
	const int RC_RGB_SCALE                      0x8573;
	const int RC_ADD_SIGNED                     0x8574;
	const int RC_INTERPOLATE                    0x8575;
	const int RC_CONSTANT                       0x8576;
	const int RC_PRIMARY_COLOR                  0x8577;
	const int RC_PREVIOUS                       0x8578;
	const int RC_OPERAND0_RGB                   0x8590;
	const int RC_OPERAND1_RGB                   0x8591;
	const int RC_OPERAND2_RGB                   0x8592;
	const int RC_OPERAND0_ALPHA                 0x8598;
	const int RC_OPERAND1_ALPHA                 0x8599;
	const int RC_OPERAND2_ALPHA                 0x859A;

	const int RC_ALPHA_SCALE                    0x0D1C;

	const int RC_SRC0_RGB                       0x8580;
	const int RC_SRC1_RGB                       0x8581;
	const int RC_SRC2_RGB                       0x8582;
	const int RC_SRC0_ALPHA                     0x8588;
	const int RC_SRC1_ALPHA                     0x8589;
	const int RC_SRC2_ALPHA                     0x858A;

	const int RC_DOT3_RGB=                       0x86AE;
	const int RC_DOT3_RGBA=                      0x86AF;

	// Remote control definitions //
	const int INT=				0x9002;
	const int BOOL=			0x9003;
	const int FLOAT=			0x9004;
	const int STRING=			0x9005;
	const int DOUBLE=			0x9006;
	const int SCALAR=			0x9007;
	const int VECTOR=			0x9008;
	const int TEXT			0x9009;
	const int MATRIX			0x900A;
	const int IMAGE			0x900B;
	const int CHAR			0x900C;
	const int UP				0x900D;
	const int DOWN			0x900E;
	const int LEFT			0x900F;
	const int RIGHT			0x9010;
	const int FORWARD			0x9011;
	const int BACKWARD		0x9012;
	const int JUMP			0x9013;
	const int SHOOT			0x9014;
	const int SIDESTEP_LEFT   0x9015;
	const int SIDESTEP_RIGHT  0x9016;
	const int SIDESTEP		0x9017;
	const int SPEED			0x9018;
	const int BEND			0x9019;
	const int STAND_UP		0x901A;
	const int STRAIGHTEN		0x901B;
	const int STOP			0x901C;
	const int QUIT			0x901D;
	const int EXIT			0x901E;
	const int COLOR			0x901F;
	const int BLACK			0x9020;
	const int WHITE			0x9021;
	const int BLUE			0x9022;
	const int RED				0x9023;
	const int GREEN			0x9024;
	const int YELLOW			0x9025;
	const int MAGENTA			0x9026;
	const int CYAN			0x9027;
	const int GREY			0x9028;
	const int DARKEN			0x9029;
	const int LIGHTEN			0x902A;
	const int VERTEX			0x902B;
	const int EDGE			0x902C;
	const int FACE			0x902D;
	const int SCREEN			0x902E;
	const int CUBE			0x902F;
	const int ROUND			0x9030;
	const int RC_2D			0x9031;
	const int RC_3D			0x9032;
	const int SPHERE			0x9033;
	const int PRIMITIVE		0x9034;
	const int BUTTON			0x9035;
	const int TOGGLE_BUTTON   0x9036;
	const int RADIO_BUTTON	0x9037;
	const int VERTEX			0x9038;
}

#endif*/