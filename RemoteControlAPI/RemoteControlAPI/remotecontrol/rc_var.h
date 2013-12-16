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

	enum DataTypes{
		RC_VOID,
		RC_INT,
		RC_BOOL,
		RC_FLOAT,
		RC_DOUBLE,
		RC_CHAR,
		RC_STRING,
		RC_TEXT,
		RC_SCALAR,
		RC_VECTOR,
		RC_MATRIX,
		RC_IMAGE,
		RC_LOGICAL,
		RC_FIELD
	};

	enum Comands{
		QUIT,
		EXIT,
		UP,
		DOWN,
		LEFT,
		RIGHT,
		STEP_BACKWARD,
		STEP_FORWARD,
		JUMP,
		SHOOT,
		SIDESTEP,
		SIDESTEP_LEFT,
		SIDESTEP_RIGHT,
		SPEED,
		SLOW_DOWN,
		SPEED_UP,
		TRANSLATION,
		ROTATION,
		SCALE,
		AXIS,
		AXIS_X,
		AXIS_Y,
		AXIS_Z,
		BEND,
		STAND_UP,
		STRAIGHTEN
	};

	enum Primitives{
		COLOR,
		BLACK,
		WHITE,
		RED,
		GREEN,
		BLUE,
		YELLOW,
		MAGENTA,
		CYAN,
		GREY,
		DARKEN,
		LIGHTER,
		VERTEX,
		EDGE,
		FACE,
		SCREEN,
		CUBE,
		CIRCLE,
		SPHERE,
		PRIMITIVE,
		RC_2D,
		RC_3D
	};

	const int DEFAULT_CONTEXT = 0;

	enum Modules{
		DEFAULT_MODULE,
		BUTTON,
		TOGGLE_BUTTON,
		RADIO_BUTTON,
		CHECKBOX,
		CHECKEDTEXTVIEW,
		SPINNER,
		PROGRESSBAR,
		SEEKBAR,
		QUICKCONTACTBADGE,
		RADIOGROUP,
		RATINGBAR,
		PLAINTEXT,
		PERSONNAME,
		PASSWORD,
		NUMPASSWORD,
		EMAIL,
		PHONE,
		ADDRESS,
		MULTILINE,
		TIME,
		DATE,
		NUMBER,
		NUMBER_SIGNED,
		NUMBER_DECIMAL,
		AUTOCOMPLETETEXTVIEW,
		MULTIAUTOCOMPLETETEXTVIEW,
		//layouts
		GRIDLAYOUT,
		LINEARLAYOUT_V,
		LINEARLAYOUT_H,
		RELATIVELAYOUT,
		FRAMELAYOUT,
		INCLUDEOTHERLAYOUT,
		FRAGMENT,
		TABLELAYOUT,
		TABLEROW,
		SPACE,
		// composite
		LISTVIEW,
		EXPANDABLELISTVIEW,
		GRIDVIEW,
		SCROLLVIEW,
		SCROLLVIEW_H,
		SEARCHVIEW,
		SLIDINGDRAWER,
		TABHOST,
		TABWIDGET,
		WEBVIEW,
		// images & media
		IMAGEVIEW,
		IMAGEBUTTON,
		GALLERY,
		MEDIACONTROLLER,
		VIDEOVIEW,
		// time & date
		TIMEPICKER,
		DATEPICKER,
		CALENDARVIEW,
		CHRONOMETR,
		ANALOGCLOCK,
		DIGITALCLOCK,
		// transitions
		IMAGESWITCHER,
		ADAPTERVIEWFLIPPER,
		STACKVIEW,
		TEXTSWITCHER,
		VIEWANIMATOR,
		VIEWFLIPPER,
		VIEWSWITCHER,
		// advanced
		REQUESTFOCUS,
		VIEW,
		VIEWSTUP,
		GESTUREOVERLAYVIEW,
		TEXTUREVIEW,
		SURFACEVIEW,
		NUMBERPICKER,
		ZOOMBUTTON,
		ZOOMCONTROLS,
		DIALERFILTER,
		TWOLINELISTITEM,
		ABSOLUTELAYOUT,
		// other
		TEXTCLOCK,

		// sensors
		ACCELEROMETER,
		MAGNETIC_SENSOR,
		DISTANCE_SENSOR,
		THERMOMETER,
		PRESSURE_SENSOR,
		GPS_SENSOR,
		LIGHT_SENSOR,
		POSITION_SENSOR,
		SOUND_SENSOR,
		CAMERA_SENSOR,

		// modules
		ARROWS,
		ARROW_UP,
		ARROW_DOWN,
		ARROW_RIGHT,
		ARROW_LEFT,
		KEYBOARD,
		JOYSTICK,
		JOYSTICK_UP,
		JOYSTICK_DOWN,
		JOYSTIXK_LEFT,
		JOYSTICK_RIGHT
	};


	// commands
	/*const int UP								= 0x900D;
	const int DOWN								= 0x900E;
	const int LEFT								= 0x900F;
	const int RIGHT								= 0x9010;
	const int STEP_FORWARD							= 0x9011;
	const int STEP_BACKWARD							= 0x9012;
	const int JUMP								= 0x9013;
	const int SHOOT								= 0x9014;
	const int SIDESTEP_LEFT						= 0x9015;
	const int SIDESTEP_RIGHT					= 0x9016;
	const int SIDESTEP							= 0x9017;
	const int SPEED								= 0x9018;
	const int SLOW_DOWN							= 0x9018;
	const int SPEED_UP							= 0x9018;
	const int STEP								= 0x9018;
	const int TRANSLATION						= 0x9018;
	const int ROTATION							= 0x9018;
	const int SCALE								= 0x9018;
	const int AXIS								= 0x9018;
	const int AXIS_X							= 0x9018;
	const int AXIS_Y							= 0x9018;
	const int AXIS_Z							= 0x9018;
	const int BEND								= 0x9019;
	const int STAND_UP							= 0x901A;
	const int STRAIGHTEN						= 0x901B;
	const int STOP								= 0x901C;
	const int QUIT								= 0x901D;
	const int EXIT								= 0x901E;
	const int COLOR								= 0x901F;
	const int BLACK								= 0x9020;
	const int WHITE								= 0x9021;
	const int BLUE								= 0x9022;
	const int RED								= 0x9023;
	const int GREEN								= 0x9024;
	const int YELLOW							= 0x9025;
	const int MAGENTA							= 0x9026;
	const int CYAN								= 0x9027;
	const int GREY								= 0x9028;
	const int DARKEN							= 0x9029;
	const int LIGHTEN							= 0x902A;
	const int VERTEX							= 0x902B;
	const int EDGE								= 0x902C;
	const int FACE								= 0x902D;
	const int SCREEN							= 0x902E;
	const int CUBE								= 0x902F;
	const int ROUND								= 0x9030;
	const int RC_2D								= 0x9031;
	const int RC_3D								= 0x9032;
	const int SPHERE							= 0x9033;
	const int PRIMITIVE							= 0x9034;*/
	
	// Android controllers
	/*const int DEFAULT_MODULE					= 0x9035;
	const int DEFAULT_CONTEXT					= 0;
	const int BUTTON							= 0x9035;
	const int TOGGLE_BUTTON						= 0x9036;
	const int RADIO_BUTTON						= 0x9037;
	const int CHECKBOX							= 0x9038;
	
	const int CHECKEDTEXTVIEW					= 0x9038;
	const int SPINNER							= 0x9038;
	const int PROGRESSBAR						= 43;
	const int SEEKBAR							= 43;
	const int QUICKCONTACTBADGE					= 43;
	const int RADIOGROUP						= 43;
	const int RATINGBAR							= 43;
	// text fields
	const int PLAINTEXT							= 43;
	const int PERSONNAME						= 43;
	const int PASSWORD							= 43;
	const int NUMPASSWORD						= 43;
	const int EMAIL								= 43;
	const int PHONE								= 43;
	const int ADDRESS							= 43;
	const int MULTILINE							= 43;
	const int TIME								= 43;
	const int DATE								= 43;
	const int NUMBER							= 43;
	const int NUMBER_SIGNED						= 43;
	const int NUMBER_DECIMAL					= 43;
	const int AUTOCOMPLETETEXTVIEW				= 43;
	const int MULTIAUTOCOMPLETETEXTVIEW			= 43;

	// layouts
	const int GRIDLAYOUT						= 43;
	const int LINEARLAYOUT_V					= 43;
	const int LINEARLAYOUT_H					= 43;
	const int RELATIVELAYOUT					= 43;
	const int FRAMELAYOUT						= 43;
	const int INCLUDEOTHERLAYOUT				= 43;
	const int FRAGMENT							= 43;
	const int TABLELAYOUT						= 43;
	const int TABLEROW							= 43;
	const int SPACE								= 43;
	// composite
	const int LISTVIEW							= 43;
	const int EXPANDABLELISTVIEW				= 43;
	const int GRIDVIEW							= 43;
	const int SCROLLVIEW						= 43;
	const int SCROLLVIEW_H						= 43;
	const int SEARCHVIEW						= 43;
	const int SLIDINGDRAWER						= 43;
	const int TABHOST							= 43;
	const int TABWIDGET							= 43;
	const int WEBVIEW							= 43;
	// images & media
	const int IMAGEVIEW							= 43;
	const int IMAGEBUTTON						= 43;
	const int GALLERY							= 43;
	const int MEDIACONTROLLER					= 43;
	const int VIDEOVIEW							= 43;
	// time & date
	const int TIMEPICKER						= 43;
	const int DATEPICKER						= 43;
	const int CALENDARVIEW						= 43;
	const int CHRONOMETR						= 43;
	const int ANALOGCLOCK						= 43;
	const int DIGITALCLOCK						= 43;
	// transitions
	const int IMAGESWITCHER						= 43;
	const int ADAPTERVIEWFLIPPER				= 43;
	const int STACKVIEW							= 43;
	const int TEXTSWITCHER						= 43;
	const int VIEWANIMATOR						= 43;
	const int VIEWFLIPPER						= 43;
	const int VIEWSWITCHER						= 43;
	// advanced
	const int REQUESTFOCUS						= 43;
	const int VIEW								= 43;
	const int VIEWSTUP							= 43;
	const int GESTUREOVERLAYVIEW				= 43;
	const int TEXTUREVIEW						= 43;
	const int SURFACEVIEW						= 43;
	const int NUMBERPICKER						= 43;
	const int ZOOMBUTTON						= 43;
	const int ZOOMCONTROLS						= 43;
	const int DIALERFILTER						= 43;
	const int TWOLINELISTITEM					= 43;
	const int ABSOLUTELAYOUT					= 43;
	// other
	const int TEXTCLOCK							= 43;

	// sensors
	const int ACCELEROMETER						= 43;
	const int MAGNETIC_SENSOR					= 43;
	const int DISTANCE_SENSOR					= 43;

	// modules
	const int ARROWS							= 43;*/


	// *********************************************************** //
	// taken from gl.h //

	// ClearBufferMask //
	const int RC_DEPTH_BUFFER_BIT               = 0x00000100;
	const int RC_STENCIL_BUFFER_BIT             = 0x00000400;
	const int RC_COLOR_BUFFER_BIT               = 0x00004000;

	// Boolean //
	const int RC_FALSE                          = 0;
	const int RC_TRUE                           = 1;

	// BeginMode //
	const int RC_POINTS                         = 0x0000;
	const int RC_LINES                          = 0x0001;
	const int RC_LINE_LOOP                      = 0x0002;
	const int RC_LINE_STRIP                     = 0x0003;
	const int RC_TRIANRCES                      = 0x0004;
	const int RC_TRIANRCE_STRIP                 = 0x0005;
	const int RC_TRIANRCE_FAN                   = 0x0006;

	// AlphaFunction //
	const int RC_NEVER                          = 0x0200;
	const int RC_LESS                           = 0x0201;
	const int RC_EQUAL                          = 0x0202;
	const int RC_LEQUAL                         = 0x0203;
	const int RC_GREATER                        = 0x0204;
	const int RC_NOTEQUAL                       = 0x0205;
	const int RC_GEQUAL                         = 0x0206;
	const int RC_ALWAYS                         = 0x0207;

	// BlendingFactorDest //
	const int RC_ZERO                           = 0;
	const int RC_ONE                            = 1;
	const int RC_SRC_COLOR                      = 0x0300;
	const int RC_ONE_MINUS_SRC_COLOR            = 0x0301;
	const int RC_SRC_ALPHA                      = 0x0302;
	const int RC_ONE_MINUS_SRC_ALPHA            = 0x0303;
	const int RC_DST_ALPHA                      = 0x0304;
	const int RC_ONE_MINUS_DST_ALPHA            = 0x0305;

	// BlendingFactorSrc //
	const int RC_DST_COLOR                      = 0x0306;
	const int RC_ONE_MINUS_DST_COLOR            = 0x0307;
	const int RC_SRC_ALPHA_SATURATE             = 0x0308;
	
	// ClipPlaneName //
	const int RC_CLIP_PLANE0                    = 0x3000;
	const int RC_CLIP_PLANE1                    = 0x3001;
	const int RC_CLIP_PLANE2                    = 0x3002;
	const int RC_CLIP_PLANE3                    = 0x3003;
	const int RC_CLIP_PLANE4                    = 0x3004;
	const int RC_CLIP_PLANE5                    = 0x3005;

	// CullFaceMode //
	const int RC_FRONT                          = 0x0404;
	const int RC_BACK                           = 0x0405;
	const int RC_FRONT_AND_BACK                 = 0x0408;

	// EnableCap //
	const int RC_FOG                            = 0x0B60;
	const int RC_LIGHTING                       = 0x0B50;
	const int RC_TEXTURE_2D                     = 0x0DE1;
	const int RC_CULL_FACE                      = 0x0B44;
	const int RC_ALPHA_TEST                     = 0x0BC0;
	const int RC_BLEND                          = 0x0BE2;
	const int RC_COLOR_LOGIC_OP                 = 0x0BF2;
	const int RC_DITHER                         = 0x0BD0;
	const int RC_STENCIL_TEST                   = 0x0B90;
	const int RC_DEPTH_TEST                     = 0x0B71;
	const int RC_POINT_SMOOTH                   = 0x0B10;
	const int RC_LINE_SMOOTH                    = 0x0B20;
	const int RC_COLOR_MATERIAL                 = 0x0B57;
	const int RC_NORMALIZE                      = 0x0BA1;
	const int RC_RESCALE_NORMAL                 = 0x803A;
	const int RC_VERTEX_ARRAY                   = 0x8074;
	const int RC_NORMAL_ARRAY                   = 0x8075;
	const int RC_COLOR_ARRAY                    = 0x8076;
	const int RC_TEXTURE_COORD_ARRAY            = 0x8078;
	const int RC_MULTISAMPLE                    = 0x809D;
	const int RC_SAMPLE_ALPHA_TO_COVERAGE       = 0x809E;
	const int RC_SAMPLE_ALPHA_TO_ONE            = 0x809F;
	const int RC_SAMPLE_COVERAGE                = 0x80A0;

	// ErrorCode //
	const int RC_NO_ERROR                       = 0;
	const int RC_INVALID_ENUM                   = 0x0500;
	const int RC_INVALID_VALUE                  = 0x0501;
	const int RC_INVALID_OPERATION              = 0x0502;
	const int RC_STACK_OVERFLOW                 = 0x0503;
	const int RC_STACK_UNDERFLOW                = 0x0504;
	const int RC_OUT_OF_MEMORY                  = 0x0505;
	
	// FogMode //
	const int RC_EXP                            = 0x0800;
	const int RC_EXP2                           = 0x0801;

	// FogParameter //
	const int RC_FOG_DENSITY                    = 0x0B62;
	const int RC_FOG_START                      = 0x0B63;
	const int RC_FOG_END                        = 0x0B64;
	const int RC_FOG_MODE                       = 0x0B65;
	const int RC_FOG_COLOR                      = 0x0B66;

	// FrontFaceDirection //
	const int RC_CW                             = 0x0900;
	const int RC_CCW                            = 0x0901;

	// GetPName //
	const int RC_CURRENT_COLOR                  = 0x0B00;
	const int RC_CURRENT_NORMAL                 = 0x0B02;
	const int RC_CURRENT_TEXTURE_COORDS         = 0x0B03;
	const int RC_POINT_SIZE                     = 0x0B11;
	const int RC_POINT_SIZE_MIN                 = 0x8126;
	const int RC_POINT_SIZE_MAX                 = 0x8127;
	const int RC_POINT_FADE_THRESHOLD_SIZE      = 0x8128;
	const int RC_POINT_DISTANCE_ATTENUATION     = 0x8129;
	const int RC_SMOOTH_POINT_SIZE_RANGE        = 0x0B12;
	const int RC_LINE_WIDTH                     = 0x0B21;
	const int RC_SMOOTH_LINE_WIDTH_RANGE        = 0x0B22;
	const int RC_ALIASED_POINT_SIZE_RANGE       = 0x846D;
	const int RC_ALIASED_LINE_WIDTH_RANGE       = 0x846E;
	const int RC_CULL_FACE_MODE                 = 0x0B45;
	const int RC_FRONT_FACE                     = 0x0B46;
	const int RC_SHADE_MODEL                    = 0x0B54;
	const int RC_DEPTH_RANGE                    = 0x0B70;
	const int RC_DEPTH_WRITEMASK                = 0x0B72;
	const int RC_DEPTH_CLEAR_VALUE              = 0x0B73;
	const int RC_DEPTH_FUNC                     = 0x0B74;
	const int RC_STENCIL_CLEAR_VALUE            = 0x0B91;
	const int RC_STENCIL_FUNC                   = 0x0B92;
	const int RC_STENCIL_VALUE_MASK             = 0x0B93;
	const int RC_STENCIL_FAIL                   = 0x0B94;
	const int RC_STENCIL_PASS_DEPTH_FAIL        = 0x0B95;
	const int RC_STENCIL_PASS_DEPTH_PASS        = 0x0B96;
	const int RC_STENCIL_REF                    = 0x0B97;
	const int RC_STENCIL_WRITEMASK              = 0x0B98;
	const int RC_MATRIX_MODE                    = 0x0BA0;
	const int RC_VIEWPORT                       = 0x0BA2;
	const int RC_MODELVIEW_STACK_DEPTH          = 0x0BA3;
	const int RC_PROJECTION_STACK_DEPTH         = 0x0BA4;
	const int RC_TEXTURE_STACK_DEPTH            = 0x0BA5;
	const int RC_MODELVIEW_MATRIX               = 0x0BA6;
	const int RC_PROJECTION_MATRIX              = 0x0BA7;
	const int RC_TEXTURE_MATRIX                 = 0x0BA8;
	const int RC_ALPHA_TEST_FUNC                = 0x0BC1;
	const int RC_ALPHA_TEST_REF                 = 0x0BC2;
	const int RC_BLEND_DST                      = 0x0BE0;
	const int RC_BLEND_SRC                      = 0x0BE1;
	const int RC_LOGIC_OP_MODE                  = 0x0BF0;
	const int RC_SCISSOR_BOX                    = 0x0C10;
	const int RC_SCISSOR_TEST                   = 0x0C11;
	const int RC_COLOR_CLEAR_VALUE              = 0x0C22;
	const int RC_COLOR_WRITEMASK                = 0x0C23;
	const int RC_MAX_LIGHTS                     = 0x0D31;
	const int RC_MAX_CLIP_PLANES                = 0x0D32;
	const int RC_MAX_TEXTURE_SIZE               = 0x0D33;
	const int RC_MAX_MODELVIEW_STACK_DEPTH      = 0x0D36;
	const int RC_MAX_PROJECTION_STACK_DEPTH     = 0x0D38;
	const int RC_MAX_TEXTURE_STACK_DEPTH        = 0x0D39;
	const int RC_MAX_VIEWPORT_DIMS              = 0x0D3A;
	const int RC_MAX_TEXTURE_UNITS              = 0x84E2;
	const int RC_SUBPIXEL_BITS                  = 0x0D50;
	const int RC_RED_BITS                       = 0x0D52;
	const int RC_GREEN_BITS                     = 0x0D53;
	const int RC_BLUE_BITS                      = 0x0D54;
	const int RC_ALPHA_BITS                     = 0x0D55;
	const int RC_DEPTH_BITS                     = 0x0D56;
	const int RC_STENCIL_BITS                   = 0x0D57;
	const int RC_POLYGON_OFFSET_UNITS           = 0x2A00;
	const int RC_POLYGON_OFFSET_FILL            = 0x8037;
	const int RC_POLYGON_OFFSET_FACTOR          = 0x8038;
	const int RC_TEXTURE_BINDING_2D             = 0x8069;
	const int RC_VERTEX_ARRAY_SIZE              = 0x807A;
	const int RC_VERTEX_ARRAY_TYPE              = 0x807B;
	const int RC_VERTEX_ARRAY_STRIDE            = 0x807C;
	const int RC_NORMAL_ARRAY_TYPE              = 0x807E;
	const int RC_NORMAL_ARRAY_STRIDE            = 0x807F;
	const int RC_COLOR_ARRAY_SIZE               = 0x8081;
	const int RC_COLOR_ARRAY_TYPE               = 0x8082;
	const int RC_COLOR_ARRAY_STRIDE             = 0x8083;
	const int RC_TEXTURE_COORD_ARRAY_SIZE       = 0x8088;
	const int RC_TEXTURE_COORD_ARRAY_TYPE       = 0x8089;
	const int RC_TEXTURE_COORD_ARRAY_STRIDE     = 0x808A;
	const int RC_VERTEX_ARRAY_POINTER           = 0x808E;
	const int RC_NORMAL_ARRAY_POINTER           = 0x808F;
	const int RC_COLOR_ARRAY_POINTER            = 0x8090;
	const int RC_TEXTURE_COORD_ARRAY_POINTER    = 0x8092;
	const int RC_SAMPLE_BUFFERS                 = 0x80A8;
	const int RC_SAMPLES                        = 0x80A9;
	const int RC_SAMPLE_COVERAGE_VALUE          = 0x80AA;
	const int RC_SAMPLE_COVERAGE_INVERT         = 0x80AB;

	// GetTextureParameter //
	const int RC_NUM_COMPRESSED_TEXTURE_FORMATS = 0x86A2;
	const int RC_COMPRESSED_TEXTURE_FORMATS     = 0x86A3;

	// HintMode //
	const int RC_DONT_CARE                      = 0x1100;
	const int RC_FASTEST                        = 0x1101;
	const int RC_NICEST                         = 0x1102;

	// HintTarget //
	const int RC_PERSPECTIVE_CORRECTION_HINT    = 0x0C50;
	const int RC_POINT_SMOOTH_HINT              = 0x0C51;
	const int RC_LINE_SMOOTH_HINT               = 0x0C52;
	const int RC_FOG_HINT                       = 0x0C54;
	const int RC_GENERATE_MIPMAP_HINT           = 0x8192;

	// LightModelParameter //
	const int RC_LIGHT_MODEL_AMBIENT            = 0x0B53;
	const int RC_LIGHT_MODEL_TWO_SIDE           = 0x0B52;

	// LightParameter //
	const int RC_AMBIENT                        = 0x1200;
	const int RC_DIFFUSE                        = 0x1201;
	const int RC_SPECULAR                       = 0x1202;
	const int RC_POSITION                       = 0x1203;
	const int RC_SPOT_DIRECTION                 = 0x1204;
	const int RC_SPOT_EXPONENT                  = 0x1205;
	const int RC_SPOT_CUTOFF                    = 0x1206;
	const int RC_CONSTANT_ATTENUATION           = 0x1207;
	const int RC_LINEAR_ATTENUATION             = 0x1208;
	const int RC_QUADRATIC_ATTENUATION          = 0x1209;

	// DataType //
	const int RC_BYTE                           = 0x1400;
	const int RC_UNSIGNED_BYTE                  = 0x1401;
	const int RC_SHORT                          = 0x1402;
	const int RC_UNSIGNED_SHORT                 = 0x1403;
	//const int RC_FLOAT                          = 0x1406;
	const int RC_FIXED                          = 0x140C;

	// LogicOp //
	const int RC_CLEAR                          = 0x1500;
	const int RC_AND                            = 0x1501;
	const int RC_AND_REVERSE                    = 0x1502;
	const int RC_COPY                           = 0x1503;
	const int RC_AND_INVERTED                   = 0x1504;
	const int RC_NOOP                           = 0x1505;
	const int RC_XOR                            = 0x1506;
	const int RC_OR                             = 0x1507;
	const int RC_NOR                            = 0x1508;
	const int RC_EQUIV                          = 0x1509;
	const int RC_INVERT                         = 0x150A;
	const int RC_OR_REVERSE                     = 0x150B;
	const int RC_COPY_INVERTED                  = 0x150C;
	const int RC_OR_INVERTED                    = 0x150D;
	const int RC_NAND                           = 0x150E;
	const int RC_SET                            = 0x150F;

	// MaterialParameter //
	const int RC_EMISSION                       = 0x1600;
	const int RC_SHININESS                      = 0x1601;
	const int RC_AMBIENT_AND_DIFFUSE            = 0x1602;
	
	// MatrixMode //
	const int RC_MODELVIEW                      = 0x1700;
	const int RC_PROJECTION                     = 0x1701;
	const int RC_TEXTURE                        = 0x1702;

	// PixelFormat //
	const int RC_ALPHA                          = 0x1906;
	const int RC_RGB                            = 0x1907;
	const int RC_RGBA                           = 0x1908;
	const int RC_LUMINANCE                      = 0x1909;
	const int RC_LUMINANCE_ALPHA                = 0x190A;
	
	// PixelStoreParameter //
	const int RC_UNPACK_ALIGNMENT               = 0x0CF5;
	const int RC_PACK_ALIGNMENT                 = 0x0D05;

	// PixelType //
	const int RC_UNSIGNED_SHORT_4_4_4_4         = 0x8033;
	const int RC_UNSIGNED_SHORT_5_5_5_1         = 0x8034;
	const int RC_UNSIGNED_SHORT_5_6_5           = 0x8363;

	// ShadingModel //
	const int RC_FLAT                           = 0x1D00;
	const int RC_SMOOTH                         = 0x1D01;

	// StencilOp //
	const int RC_KEEP                           = 0x1E00;
	const int RC_REPLACE                        = 0x1E01;
	const int RC_INCR                           = 0x1E02;
	const int RC_DECR                           = 0x1E03;
	
	// StringName //
	const int RC_VENDOR                         = 0x1F00;
	const int RC_RENDERER                       = 0x1F01;
	const int RC_VERSION                        = 0x1F02;
	const int RC_EXTENSIONS                     = 0x1F03;

	// TextureEnvMode //
	const int RC_MODULATE                       = 0x2100;
	const int RC_DECAL                          = 0x2101;
	const int RC_ADD                            = 0x0104;
	
	// TextureEnvParameter //
	const int RC_TEXTURE_ENV_MODE               = 0x2200;
	const int RC_TEXTURE_ENV_COLOR              = 0x2201;

	// TextureEnvTarget //
	const int RC_TEXTURE_ENV                    = 0x2300;

	// TextureMagFilter //
	const int RC_NEAREST                        = 0x2600;
	const int RC_LINEAR                         = 0x2601;

	// TextureMinFilter //
	const int RC_NEAREST_MIPMAP_NEAREST         = 0x2700;
	const int RC_LINEAR_MIPMAP_NEAREST          = 0x2701;
	const int RC_NEAREST_MIPMAP_LINEAR          = 0x2702;
	const int RC_LINEAR_MIPMAP_LINEAR           = 0x2703;

	// TextureParameterName //
	const int RC_TEXTURE_MAG_FILTER             = 0x2800;
	const int RC_TEXTURE_MIN_FILTER             = 0x2801;
	const int RC_TEXTURE_WRAP_S                 = 0x2802;
	const int RC_TEXTURE_WRAP_T                 = 0x2803;
	const int RC_GENERATE_MIPMAP                = 0x8191;

	// TextureUnit //
	const int RC_TEXTURE0                       = 0x84C0;
	const int RC_TEXTURE1                       = 0x84C1;
	const int RC_TEXTURE2                       = 0x84C2;
	const int RC_TEXTURE3                       = 0x84C3;
	const int RC_TEXTURE4                       = 0x84C4;
	const int RC_TEXTURE5                       = 0x84C5;
	const int RC_TEXTURE6                       = 0x84C6;
	const int RC_TEXTURE7                       = 0x84C7;
	const int RC_TEXTURE8                       = 0x84C8;
	const int RC_TEXTURE9                       = 0x84C9;
	const int RC_TEXTURE10                      = 0x84CA;
	const int RC_TEXTURE11                      = 0x84CB;
	const int RC_TEXTURE12                      = 0x84CC;
	const int RC_TEXTURE13                      = 0x84CD;
	const int RC_TEXTURE14                      = 0x84CE;
	const int RC_TEXTURE15                      = 0x84CF;
	const int RC_TEXTURE16                      = 0x84D0;
	const int RC_TEXTURE17                      = 0x84D1;
	const int RC_TEXTURE18                      = 0x84D2;
	const int RC_TEXTURE19                      = 0x84D3;
	const int RC_TEXTURE20                      = 0x84D4;
	const int RC_TEXTURE21                      = 0x84D5;
	const int RC_TEXTURE22                      = 0x84D6;
	const int RC_TEXTURE23                      = 0x84D7;
	const int RC_TEXTURE24                      = 0x84D8;
	const int RC_TEXTURE25                      = 0x84D9;
	const int RC_TEXTURE26                      = 0x84DA;
	const int RC_TEXTURE27                      = 0x84DB;
	const int RC_TEXTURE28                      = 0x84DC;
	const int RC_TEXTURE29                      = 0x84DD;
	const int RC_TEXTURE30                      = 0x84DE;
	const int RC_TEXTURE31                      = 0x84DF;
	const int RC_ACTIVE_TEXTURE                 = 0x84E0;
	const int RC_CLIENT_ACTIVE_TEXTURE          = 0x84E1;

	// TextureWrapMode //
	const int RC_REPEAT                         = 0x2901;
	const int RC_CLAMP_TO_EDGE                  = 0x812F;

	// LightName //
	const int RC_LIGHT0                         = 0x4000;
	const int RC_LIGHT1                         = 0x4001;
	const int RC_LIGHT2                         = 0x4002;
	const int RC_LIGHT3                         = 0x4003;
	const int RC_LIGHT4                         = 0x4004;
	const int RC_LIGHT5                         = 0x4005;
	const int RC_LIGHT6                         = 0x4006;
	const int RC_LIGHT7                         = 0x4007;

	// Buffer Objects //
	const int RC_ARRAY_BUFFER                   = 0x8892;
	const int RC_ELEMENT_ARRAY_BUFFER           = 0x8893;

	const int RC_ARRAY_BUFFER_BINDING               = 0x8894;
	const int RC_ELEMENT_ARRAY_BUFFER_BINDING       = 0x8895;
	const int RC_VERTEX_ARRAY_BUFFER_BINDING        = 0x8896;
	const int RC_NORMAL_ARRAY_BUFFER_BINDING        = 0x8897;
	const int RC_COLOR_ARRAY_BUFFER_BINDING         = 0x8898;
	const int RC_TEXTURE_COORD_ARRAY_BUFFER_BINDING = 0x889A;

	const int RC_STATIC_DRAW                    = 0x88E4;
	const int RC_DYNAMIC_DRAW                   = 0x88E8;
	
	const int RC_BUFFER_SIZE                    = 0x8764;
	const int RC_BUFFER_USAGE                   = 0x8765;

	// Texture combine + dot3 //
	const int RC_SUBTRACT                       = 0x84E7;
	const int RC_COMBINE                        = 0x8570;
	const int RC_COMBINE_RGB                    = 0x8571;
	const int RC_COMBINE_ALPHA                  = 0x8572;
	const int RC_RGB_SCALE                      = 0x8573;
	const int RC_ADD_SIGNED                     = 0x8574;
	const int RC_INTERPOLATE                    = 0x8575;
	const int RC_CONSTANT                       = 0x8576;
	const int RC_PRIMARY_COLOR                  = 0x8577;
	const int RC_PREVIOUS                       = 0x8578;
	const int RC_OPERAND0_RGB                   = 0x8590;
	const int RC_OPERAND1_RGB                   = 0x8591;
	const int RC_OPERAND2_RGB                   = 0x8592;
	const int RC_OPERAND0_ALPHA                 = 0x8598;
	const int RC_OPERAND1_ALPHA                 = 0x8599;
	const int RC_OPERAND2_ALPHA                 = 0x859A;

	const int RC_ALPHA_SCALE                    = 0x0D1C;

	const int RC_SRC0_RGB                       = 0x8580;
	const int RC_SRC1_RGB                       = 0x8581;
	const int RC_SRC2_RGB                       = 0x8582;
	const int RC_SRC0_ALPHA                     = 0x8588;
	const int RC_SRC1_ALPHA                     = 0x8589;
	const int RC_SRC2_ALPHA                     = 0x858A;

	const int RC_DOT3_RGB                       = 0x86AE;
	const int RC_DOT3_RGBA                      = 0x86AF;
}

#endif // RC_VARS_H //