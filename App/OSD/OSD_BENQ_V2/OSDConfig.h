/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
#ifndef __OSDCONFIG_H__
#define __OSDCONFIG_H__
//******************************************************************************
// G L O B A L   D E F I N I T I O N S
//******************************************************************************
//Language
#define OSDLANG_ENGLISH       0x00
#define OSDLANG_FRENCH        0x01
#define OSDLANG_GERMAN        0x02
#define OSDLANG_ITALIAN       0x03
#define OSDLANG_SPANISH       0x04
#define OSDLANG_POLISH        0x05
#define OSDLANG_CZECH         0x06
#define OSDLANG_HUNGARIAN     0x07
#define OSDLANG_SERBO         0x08
#define OSDLANG_ROMANA        0x09
#define OSDLANG_DUTCH         0x0a
#define OSDLANG_RUSSIAN       0x0b
#define OSDLANG_SWEDISH       0x0c
#define OSDLANG_PORTUGUESE    0x0d
#define OSDLANG_JAPANESE      0x0e
#define OSDLANG_CHINESE_T     0x0f 
#define OSDLANG_CHINESE_S     0x10
#define OSDLANG_ARAB          0x11
#define NUM_OSDLANGS          0x12
#define OSDLANG_NONE          0xFF

//#define OSDLANG_POLISH        0x21
#define OSDLANG_TURKISH       0x22
#define OSDLANG_KOREA         0x23
#define OSDLANG_FINNISH       0x24

enum {
  OSDFontTble1,
  OSDFontTble2,
};

enum {
    CLRTMP_6500K,
    CLRTMP_9300K,        
    CLRTMP_5800K,
    CLRTMP_USER,
    NUMBER_CLRTMP,   
    CLRTMP_sRGB,
    CLRTMP_5000K,  
    CLRTMP_7500K,    
    CLRTMP_8200K,  
    CLRTMP_11500K,  
    
} ;

#if 0//IS_BL_SERIES
enum {
    CUSTOMER_KEY_PICTUREMODE,
#if ENABLE_CUSTOMKEY_CAD == ON    
    CUSTOMER_KEY_CAD,
#endif    
#if ENABLE_CUSTOMKEY_ANIMATION == ON
    CUSTOMER_KEY_ANIMATION_MODE,
#endif
#if ENABLE_CUSTOMKEY_LBL == ON
    CUSTOMER_KEY_LOWBULELIGHTMODE,//ULEric140331    
#endif    
    CUSTOMER_KEY_DISPLAYMODE,
    CUSTOMER_KEY_BRIGHTNESS,
    CUSTOMER_KEY_CONTRAST,
#if ENABLE_CUSTOMKEY_AUTOADJ == ON
    CUSTOMER_KEY_AUTOADJUSTMENT,
#endif    
    CUSTOMER_KEY_VOLUME,//ULEric140331
    CUSTOMER_KEY_MUTE,//ULEric140331
    CUSTOMER_KEY_INPUT,
#if ENABLE_EYE_PROTECT == ON
    CUSTOMER_KEY_EYE_PROTECT,
    CUSTOMER_KEY_EYE_PROTECT_METER,
#endif
#if ENABLE_ECO_SENSOR== ON
    CUSTOMER_KEY_ECO_SENSOR,
    CUSTOMER_KEY_ECO_SENSOR_METER,
#endif
#if ENABLE_ERGONOMICS == ON
    CUSTOMER_KEY_SMARTREMINDER,//ULEric140331
#endif    
    CUSTOMER_KEY_NUM
};
#else//if IS_PD_SERIES
enum {
    CUSTOMER_KEY_BRIGHTNESS,
    CUSTOMER_KEY_CONTRAST,
    CUSTOMER_KEY_INPUT,
    CUSTOMER_KEY_PICTUREMODE,
#if ENABLE_CUSTOMKEY_CAD == ON    
    CUSTOMER_KEY_CAD,
#endif    
#if ENABLE_CUSTOMKEY_ANIMATION == ON
    CUSTOMER_KEY_ANIMATION_MODE,
#endif
#if ENABLE_CUSTOMKEY_LBL == ON
    CUSTOMER_KEY_LOWBULELIGHTMODE,//ULEric140331    
#endif    
    CUSTOMER_KEY_DISPLAYMODE,
#if ENABLE_CUSTOMKEY_AUTOADJ == ON
    CUSTOMER_KEY_AUTOADJUSTMENT,
#endif    
    CUSTOMER_KEY_VOLUME,//ULEric140331
    CUSTOMER_KEY_MUTE,//ULEric140331
#if ENABLE_EYE_PROTECT == ON
    CUSTOMER_KEY_EYE_PROTECT,
    CUSTOMER_KEY_EYE_PROTECT_METER,
#endif
#if ENABLE_ECO_SENSOR== ON
    CUSTOMER_KEY_ECO_SENSOR,
    CUSTOMER_KEY_ECO_SENSOR_METER,
#endif
#if ENABLE_ERGONOMICS == ON
    CUSTOMER_KEY_SMARTREMINDER,//ULEric140331
#endif    
    CUSTOMER_KEY_NUM
};

#endif

#define ENABLE_PICTURE_MODE_MBOOK       ON//OFF
#define ENABLE_PICTURE_MODE_GAME        ON//ON
#define ENABLE_PICTURE_MODE_MOVIE       ON//ON
#define ENABLE_PICTURE_MODE_PHOTO       ON//ON


enum {
    PICTURE_MODE_STANDARD,
#if	ENABLE_PICTURE_MODE_REC709== ON
    PICTURE_MODE_REC709,
#endif
    PICTURE_MODE_SRGB, 
#if	ENABLE_PICTURE_MODE_CAD == ON
    PICTURE_MODE_CAD,
#endif        
#if	ENABLE_PICTURE_MODE_ANIMATION == ON
    PICTURE_MODE_ANIMATION,
#endif
#if	ENABLE_PRESENTATION_MODE == ON
    PICTURE_MODE_PRESENTATION,
#endif        
    PICTURE_MODE_LOW_BL,
#if ENABLE_PICTURE_MODE_MOVIE == ON           
    PICTURE_MODE_MOVIE,
#endif    
#if ENABLE_PICTURE_MODE_GAME == ON    
    PICTURE_MODE_GAME,    
#endif    
#if ENABLE_PICTURE_MODE_PHOTO== ON       
    PICTURE_MODE_PHOTO,
#endif    
#if	ENABLE_PICTURE_MODE_DARKROOM == ON
    PICTURE_MODE_DARKROOM ,
#endif        
    PICTURE_MODE_ECO,
#if ENABLE_PICTURE_MODE_MBOOK == ON
    PICTURE_MODE_MBOOK,
#endif
    PICTURE_MODE_USER,    
    PICTURE_MODE_NUM
};

enum {
    DISPLAY_MODE_FULL,
    DISPLAY_MODE_ASPECT,
    DISPLAY_MODE_1BY1,
#if ENABLE_MORE_DISPLAY_MODE == ON
    DISPLAY_MODE_19_INCH,
    DISPLAY_MODE_16BY10,
    DISPLAY_MODE_23_INCH,
#endif    
    DISPLAY_MODE_NUM
};

enum {
    COLOR_RGB,    
    COLOR_YUV,
    COLOR_FORMAT_NUM
};

enum {
#if MD_INPUT_INTERFACE&INPUT_VGA0    
    VGA_SOURCE,    
#endif    
#if MD_INPUT_INTERFACE&INPUT_DIG1   
    DVI_SOURCE,
#endif    
    DP_SOURCE,
    HDMI_SOURCE,
  //  DP_SOURCE,
    MiniDP_SOURCE,
    SOURCE_NUM
};


enum {
    DP_1_1,        
    DP_1_2,    
    DP_MODE_NUM
};

enum {
    ERGO_TIME_20MIN,
    ERGO_TIME_40MIN,
    ERGO_TIME_60MIN,
    ERGO_TIME_80MIN,
    ERGO_TIME_100MIN,    
    ERGO_TIME_NUM
};

enum {
    ERGO_DURATION_5SEC,
    ERGO_DURATION_10SEC,
    ERGO_DURATION_15SEC,
    ERGO_DURATION_20SEC,
    ERGO_DURATION_25SEC,
    ERGO_DURATION_NUM
};

enum {
    ECO_SENSOR_RANGE_NEAR,
    ECO_SENSOR_RANGE_MIDDLE,
    ECO_SENSOR_RANGE_FAR,  
    ECO_SENSOR_RANGE_NUM    
};

enum {
    AUTO_POWER_OFF,
    AUTO_POWER_10MIN,
    AUTO_POWER_20MIN,
    AUTO_POWER_30MIN,
    AUTO_POWER_NUM
};

enum {
    SLIBAR_BRI,
    SLIBAR_CONS,
    SLIBAR_SHARP,
    SLIBAR_HUE,
    SLIBAR_SAT,
    SLIBAR_PHASE,
    SLIBAR_CLOCK,
    SLIBAR_HPOS,
    SLIBAR_VPOS,
    SLIBAR_RGAIN,
    SLIBAR_GGAIN,
    SLIBAR_BGAIN,
    SLIBAR_VOL, 
#if ENABLE_PICTURE_MODE_ANIMATION == ON
    SLIBAR_ANIMATION,
    SLIBAR_ANIMATION_LAYER4,
#endif
#if ENABLE_SMART_SCALING == ON    
    SLIBAR_SMRTSCALING,
#endif   
#if ENABLE_EYE_PROTECT == ON
    SLIBAR_EYEPROTECT_BRI,
#endif
};

#if 1
enum {
	OSD_TOPPAGE_POS_NML,
	OSD_TOPPAGE_POS_ROT,
};
#else
enum {
	KEYBTN_POS_BOTTOM,
	KEYBTN_POS_LEFT,
	KEYBTN_POS_RIGHT,
};
#endif

#if ENABLE_ERGONOMICS==ON &&  ENABLE_ECO_EYE_SENSOR==ON
#define MAINMENU_ICON_NUM           7
#elif ENABLE_ERGONOMICS==ON &&  ENABLE_ECO_EYE_SENSOR==OFF
#define MAINMENU_ICON_NUM           6
#else
#define MAINMENU_ICON_NUM           5
#endif
#define DISABLE_FALCON_STRING       ON
#define FORCE_NON_CIRCLE_ACTION     ON
#define SELECT_PAGE_POS   			0//BOTTOM 0 /LEFT 1 / RIGHT 2

#define BTN_Width				    18
#define BTN_Width1				    8

#define BTN_HEIGHT				    4

#define LAYER_INDENT_COUNT          OFF
#define OSD_XPOS_LEFT_OFFSET        0
#define OSD_XPOS_RIGHT_OFFSET       0
#define OSD_YPOS_TOP_OFFSET         0
#define OSD_YPOS_BOTTOM_OFFSET      0
#define OSD_POS_STEPS               100

#define DEF_CUSTOMKEY1              CUSTOMER_KEY_BRIGHTNESS
#define DEF_CUSTOMKEY2              CUSTOMER_KEY_INPUT
#define DEF_CUSTOMKEY3              CUSTOMER_KEY_PICTUREMODE
#define DEF_OSDPosX                 0x64
#define DEF_OSDPosY                 0x32
#define DEF_OSDTimer                0x0F
#define DEF_SHOWLOGO                0x01
#define DEF_OSDTRANSPARENT          0x01
#define DEF_Brightness_6500         0x64
#define DEF_Brightness_9300         0x64
#define DEF_Brightness_7500         0x64
#define DEF_Brightness_User         0x64
#define DEF_ColorTemp               CLRTMP_6500K           
#define DEF_UserRGain               100  
#define DEF_UserGGain               100
#define DEF_UserBGain               100
#if ENABLE_PICTURE_MODE_ANIMATION == ON

#endif    
#if ENABLE_OD_IN_OSD == ON//v31_110829_1220_OSD#1
#define DEF_ODMode                  OD_Advance//v31_110919_1730_OSD#3
#else
#define DEF_ODMode                  OD_ON
#endif
#define DEF_SHARPNESS               0x05
#if MD_ENABLE_DBC == ON
#define DEF_DBCMode          ON
#else
#define DEF_DBCMode          OFF
#endif

#define KEY_LONG_PRESS_TIME             10000
#define ENABLE_BENQ_DCR                 ON
#define ENABLE_DCR_IN_ECO               OFF
#define ENABLE_RECALL_PREVIEW           OFF
#define ENABLE_SRC_HOTKEY_WAKEUP        OFF
#define ENABLE_OFF_TIMER_FUNC           OFF
#define ENABLE_OFF_TIMER_NOTICE         OFF
#define ENABLE_SHARPNESS_FUNC           ON
#define ENABLE_OSD_FADE_IN_OUT          OFF
#define ENABLE_RESERVE_USERGAIN         OFF
#define ENABLE_IIYAMA_OSD_Version       OFF
#define ENABLE_ASPECT_16_10_AS_4_3      OFF
#define ENABLE_OOR_ENTER_POWERSAVING    ON
#define ENABLE_6KEYBUTTON               OFF
#define ENABLE_HDMIManualMode           OFF
#define ENABLE_SHOW_OSD_LOCK_MSG_FIRST_HOTKEY_ON     OFF
#define ENABLE_OSD_AUDIO_INPUT_SEL      OFF
#define ENABLE_BRIGHTNESS_HOTKEYFUNC    OFF
#define ENABLE_BURNIN_AUDIOON

#define ENABLE_AUTO_POVIT_FUNC      OFF//OFF//ULEric140327
#define ENABLE_SHOW_INDENTNUM       ON//ULEric140331

#endif //__OSDCONFIG_H__
/******************************************************************************/
