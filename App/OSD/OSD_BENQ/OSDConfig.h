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

#define ENABLE_PICTURE_MODE_MBOOK       OFF//OFF
#define ENABLE_PICTURE_MODE_GAME        OFF//ON
#define ENABLE_PICTURE_MODE_MOVIE       OFF//ON
#define ENABLE_PICTURE_MODE_PHOTO       OFF//ON


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
#define NUM_OSDLANGS          0x11
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
enum {
    CUSTOMER_KEY_LOWBULELIGHTMODE,//ULEric140331    
    CUSTOMER_KEY_PICTUREMODE,
    CUSTOMER_KEY_DISPLAYMODE,
    CUSTOMER_KEY_BRIGHTNESS,
    CUSTOMER_KEY_CONTRAST,
    CUSTOMER_KEY_AUTOADJUSTMENT,
    CUSTOMER_KEY_VOLUME,//ULEric140331
    CUSTOMER_KEY_MUTE,//ULEric140331
    CUSTOMER_KEY_INPUT,
    CUSTOMER_KEY_SMARTREMINDER,//ULEric140331
    CUSTOMER_KEY_NUM
};


enum {
    PICTURE_MODE_STANDARD,
    PICTURE_MODE_LOW_BL,
    PICTURE_MODE_MOVIE,
    PICTURE_MODE_GAME,    
    PICTURE_MODE_PHOTO,
    PICTURE_MODE_SRGB,    
    PICTURE_MODE_ECO,
#if ENABLE_PICTURE_MODE_MBOOK == ON
    PICTURE_MODE_MBOOK,
#endif
    PICTURE_MODE_USER,    
    PICTURE_MODE_NUM
};

enum {
    COLOR_RGB,    
    COLOR_YUV,
    COLOR_FORMAT_NUM
};

enum {
    VGA_SOURCE,    
    DVI_SOURCE,
    HDMI_SOURCE,
    DP_SOURCE,
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
    AUTO_POWER_OFF,
    AUTO_POWER_10MIN,
    AUTO_POWER_20MIN,
    AUTO_POWER_30MIN,
    AUTO_POWER_NUM
};

#define MAINMENU_ICON_NUM   6
#define DISABLE_FALCON_STRING    ON
#define FORCE_NON_CIRCLE_ACTION  ON

#define LAYER_INDENT_COUNT       OFF
#define OSD_XPOS_LEFT_OFFSET        0
#define OSD_XPOS_RIGHT_OFFSET       0
#define OSD_YPOS_TOP_OFFSET         0
#define OSD_YPOS_BOTTOM_OFFSET      0
#define OSD_POS_STEPS               100

#define DEF_CUSTOMKEY1              CUSTOMER_KEY_LOWBULELIGHTMODE
#define DEF_CUSTOMKEY2              CUSTOMER_KEY_INPUT
#define DEF_CUSTOMKEY3              CUSTOMER_KEY_VOLUME
#define DEF_OSDPosX                 0x32
#define DEF_OSDPosY                 0x32
#define DEF_OSDTimer                0x0F
#define DEF_SHOWLOGO                0x01
#define DEF_BRIGHTNESS_SRGB         0x64
#define DEF_OSDTRANSPARENT          0x01
#define DEF_Brightness              0x64
#define DEF_Brightness_6500         0x64
#define DEF_Brightness_9300         0x64
#define DEF_Brightness_7500         0x64
#define DEF_Brightness_User         0x64
#define DEF_ColorTemp               CLRTMP_6500K           
#define DEF_UserRGain               100  
#define DEF_UserGGain               100
#define DEF_UserBGain               100
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

#define KEY_LONG_PRESS_TIME         10000
#define ENABLE_BENQ_DCR               ON
#define ENABLE_DCR_IN_ECO           OFF
#define ENABLE_RECALL_PREVIEW       OFF
#define ENABLE_SRC_HOTKEY_WAKEUP    OFF
#define ENABLE_OFF_TIMER_FUNC       OFF
#define ENABLE_OFF_TIMER_NOTICE     OFF
#define ENABLE_SHARPNESS_FUNC       ON
#define ENABLE_OSD_FADE_IN_OUT      OFF
#define ENABLE_RESERVE_USERGAIN     OFF
#define ENABLE_IIYAMA_OSD_Version   OFF
#define ENABLE_IIYAMA_POWER_LOCKED  OFF
#define ENABLE_ASPECT_16_10_AS_4_3  OFF
#define ENABLE_OOR_ENTER_POWERSAVING    ON
#define ENABLE_6KEYBUTTON           OFF
#define ENABLE_HDMIManualMode OFF
#define ENABLE_HDMI_WAKE_UP_BY_CABLE OFF
#define ENABLE_SHOW_OSD_LOCK_MSG_FIRST_HOTKEY_ON     OFF
#define ENABLE_OSD_AUDIO_INPUT_SEL   OFF
#define ENABLE_BRIGHTNESS_HOTKEYFUNC OFF
#define ENABLE_BURNIN_AUDIOON

#define ENABLE_AUTO_POVIT_FUNC    OFF//ULEric140327
#define ENABLE_SHOW_INDENTNUM    ON//ULEric140331

#endif //__OSDCONFIG_H__
/******************************************************************************/
