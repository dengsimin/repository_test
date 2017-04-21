/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/
#ifndef __MODELCONFIG_H__
#define __MODELCONFIG_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "ScalerCfg.h"

//******************************************************************************
// G L O B A L   D E F I N I T I O N S
//******************************************************************************

/*******************************************************************************
                              Define Board/Keypad
*******************************************************************************/
#define BOARD_TYPE                 NT68870_MODULE_BOARD
#define KEYPAD_TYPE                NT68870_MODULE_KEYPAD

/*******************************************************************************
                              Model Feature On/Off
*******************************************************************************/
// Scaler
#define MD_SCALER_TYPE             NT68870

//UART Output Selection
#define MD_MCU_UART_OUTPUT         0 //TX/RX

//MCU Configuration
#define MD_MCU_CLK_TIMES           6 //MCU CLOCK = MCU_CLK_TIMES * REF_CLK
#define MD_MCU_UART_BAUD_RATE      4800 //Bit per second

//Input source type multi-selection
// INPUT_VGA0, INPUT_VGA1, INPUT_DIG0, INPUT_DIG1, INPUT_YPbPr0, INPUT_YPbPr1

#define MD_INPUT_INTERFACE      (INPUT_DIG1|INPUT_DIG2|INPUT_DIG3|INPUT_DP)//|INPUT_MHL1)//|INPUT_MHL0|INPUT_DP)


#define MODEL_INPUT_VGA0        INPUT_SC_NULL//INPUT_SC_VGA
#define MODEL_INPUT_VGA1        INPUT_SC_NULL
#define MODEL_INPUT_DIG0        INPUT_SC_NULL
#define MODEL_INPUT_DIG1        INPUT_SC_DVI
#define MODEL_INPUT_DIG2        INPUT_SC_DP//INPUT_SC_NULL
#define MODEL_INPUT_DIG3        INPUT_SC_NULL
#define MODEL_INPUT_DIG4        INPUT_SC_NULL
#define MODEL_INPUT_DIG5        INPUT_SC_NULL
#define MODEL_INPUT_DIG6        INPUT_SC_NULL
#define MODEL_INPUT_DIG7        INPUT_SC_HDMI

#define MODEL_INPUT_YPbPr0      INPUT_SC_NULL//INPUT_SC_YPbPr
#define MODEL_INPUT_YPbPr1      INPUT_SC_NULL
						 
#define MD_ENABLE_LOW_PWR_MODE     ON //ON/OFF
#define MD_ENABLE_CHECK_SYS5V      ON //ON/OFF
#define MD_ENABLE_LPD              ON //ON/OFF Only NT68650, NT68660 and newer scaler can define ON
#define MD_ENABLE_HDCP             ON //ON/OFF
#define MD_ENABLE_HDCP_KEY_DCRPT   ON //ON/OFF
#define MD_ENABLE_DEMO_HDCP_KEY    ON //ON/OFF
#define MD_ENABLE_NVT_HDCP_WRITER  ON //ON/OFF
#define MD_ENABLE_HDCP_TRIM_MODE   ON //ON/OFF
#define MD_ENABLE_GAMMA            ON //ON/OFF
#define MD_ENABLE_PRE_REV_GAMMA    ON //ON/OFF
#define MD_ENABLE_OD               ON//OFF //ON/OFF
#define MD_ENABLE_OD_TRANSFORM     OFF //ON/OFF
#define MD_ENABLE_MMU              ON//OFF //ON/OFF
#define MD_ENABLE_MMU_DDR          ON //ON/OFF
#define MD_ENABLE_FE2P             ON //ON/OFF
#define MD_ENABLE_DIRECT_FE2P      OFF //ON/OFF 
#define MD_ENABLE_HDMI             ON //ON/OFF
#define MD_ENABLE_HDMI_PRETEST     OFF //ON/OFF
#define MD_ENABLE_AUTO_CONTROL     OFF //ON/OFF
#define MD_ENABLE_HW_CEC           OFF//jtest ON //ON/OFF
#define MD_ENABLE_DBC              ON //ON/OFF
#define MD_ENABLE_DBC_HW_DEBOUNCE  ON //ON/OFF
#define MD_ENABLE_DIGI0_HPD        OFF// ON //ON/OFF
#define MD_ENABLE_DIGI1_HPD        ON//ON //ON/OFF
#define MD_ENABLE_DIGI2_HPD        ON //ON/OFF
#define MD_ENABLE_DIGI3_HPD        ON//ON//ON //ON/OFF
#define MD_ENABLE_DP_HPD           ON//OFF//ON //ON/OFF
#define MD_ENABLE_DP_ADV_HPD       ON//OFF//ON //ON/OFF
#define MD_ENABLE_DP1_HPD          OFF//ON //ON/OFF
#define MD_ENABLE_DP1_ADV_HPD      OFF//ON //ON/OFF
#define MD_ENABLE_DP2_HPD          OFF//ON //ON/OFF
#define MD_ENABLE_DP2_ADV_HPD      OFF//ON //ON/OFF
#define MD_ENABLE_DP3_HPD          OFF//ON //ON/OFF
#define MD_ENABLE_DP3_ADV_HPD      OFF//ON //ON/OFF
#define MD_ENABLE_SCALER_AUDIO     ON //ON/OFF
#define MD_ENABLE_INTERNAL_AUDIO_BUZZER OFF //ON/OFF Only HDMI can define it ON
#define MD_ENABLE_OSD_WINDOWS      ON //ON/OFF
#define MD_ENABLE_OSD_ROTATION     ON //ON/OFF
#define MD_ENABLE_OSD_MIRROR       OFF //ON/OFF
#define MD_ENABLE_OSD_FLIP         OFF //ON/OFF
#define MD_ENABLE_INTERNAL_LDO     OFF //ON/OFF
#define MD_ENABLE_INTERNAL_ADC_LDO OFF //ON/OFF
#define MD_ENABLE_EMBEDDED_CHECKSUM ON //ON/OFF
#define MD_ENABLE_OVERSCAN         ON //ON/OFF Only NT68676 can define ON
#define MD_ENABLE_PWM_SMOOTH       ON //ON/OFF Must be defined as OFF over NT68671~5
#define MD_ENABLE_FLASH_IDLE_MODE  ON //ON/OFF Only NT68660 & NT68650 can define ON
#define MD_ENABLE_NR_BYTIMING      ON //ON/OFF
#define MD_ENABLE_LD               OFF //ON/OFF Only NT68750 can define ON
#define MD_ENABLE_SR               ON //ON/OFF Only NT68750 can define ON
#define MD_ENABLE_SELF_AUTOCOLOR   OFF //ON/OFF
#define MD_ENABLE_HW_AUTOCOLOR     OFF //ON/OFF
#define MD_ENABLE_SCALER_3D        OFF //ON/OFF
#define MD_ENABLE_PREFRC	       OFF //ON/OFF
#define MD_ENABLE_DFR              OFF //ON/OFF
#define MD_ENABLE_DEMO_DP_EDID     ON //ON/OFF
#define MD_ENABLE_DEMO_MHL_EDID    ON //ON/OFF
#define MD_ENABLE_STRESS_TEST_KEY  OFF //ON/OFF
#define MD_ENABLE_STRESS_MCU_CLK   OFF
#define MD_ENABLE_AO_DETECT        OFF
#define MD_ENABLE_EDP              OFF //ON/OFF
#define MD_ENABLE_AUTOFRAMEDOWN    OFF//OFF
#define MD_ENABLE_POSTFRC          OFF //ON/OFF //for eDP panel
#define MD_ENABLE_DVI_DUAL_LINK    ON //ON/OFF
#define MD_ENABLE_USB_TYPE_C       OFF //ON/OFF
#define MD_ENABLE_FREESYNC_DEMO    OFF //ON/OFF
#define MD_ENABLE_FREESYNC_HDMI_FUNC  OFF
#define MD_ENABLE_CENTER_MODE      OFF //ON/OFF
#define MD_ENABLE_EMBEDED_TMDS_CLOCK_TRAINING   OFF //ON/OFF

//Over scan ratio
//  0 ~ 10 %
#define OVER_SCAN_RATIO         5
//#define FRC_V_FREQ				60
//#define FRC_NACT_MIN            480
//#define FRC_NACT_MAX            620//760

/*******************************************************************************
                               Define F/W Version
*******************************************************************************/
//Version and Date
#define VERSION                 0x02
#define REVERSION               0x20
#define FIRMWARE_VER            (VERSION<<8 | REVERSION)
#define DATE                    "2016-12-29"

/*******************************************************************************
                      Define Limitations for Out Of Range
*******************************************************************************/
//OOR: H/V frequency limitation, pixel clock limitation
#define MIN_H_FREQ              150 //0.1KHz
#define MAX_H_FREQ              947 //0.1KHz
#define MIN_V_FREQ              200 //0.1Hz
#define MAX_V_FREQ              860 //0.1Hz
#define MAX_ANALONG_PIXEL_CLOCK 205 //MHz

/*******************************************************************************
                      Define Limitations for Out Of Limit
*******************************************************************************/
#define MIN_V_FREQ_LMT          500 //0.1Hz
#define MAX_V_FREQ_LMT          840 //0.1Hz

/*******************************************************************************
                                Sync-Stable Time
                             Time To Change Source
                                 HPD Low Period
*******************************************************************************/
//Timer for waiting sync stable
#define SYNC_STABLE_TIME        200 //ms
//Changing PORT delay when searching input sync (VGA-->DVI-->HDMI-->...)
#define SYNCSRC_TIME_ANALOG0    1000
#define SYNCSRC_TIME_DIGITAL0   3000
#define SYNCSRC_TIME_ANALOG1    1000
#define SYNCSRC_TIME_DIGITAL1   3000 //HDMI=3000; DVI=1000
#define SYNCSRC_TIME_DIGITAL2   3000 //HDMI=3000; DVI=1000
#define SYNCSRC_TIME_DIGITAL3   3000 //HDMI=3000; DVI=1000
#define SYNCSRC_TIME_DP         3000
#define SYNCSRC_TIME_DP1        3000
#define SYNCSRC_TIME_DP2        3000
#define SYNCSRC_TIME_DP3        3000

//Low Period when performing HPD on/off/on
#define HPD_LOW_PERIOD          500
#define DP_HPD_LOW_PERIOD       100

#if (HPD_LOW_PERIOD > SYNCSRC_TIME_DIGITAL0)
#error "HPD_LOW_PERIOD is over SYNCSRC_TIME_DIGITAL0"
#endif
#if (HPD_LOW_PERIOD > SYNCSRC_TIME_DIGITAL1)
#error "HPD_LOW_PERIOD is over SYNCSRC_TIME_DIGITAL1"
#endif

/*******************************************************************************
                   Configurations of Scaler Audio
*******************************************************************************/
#define HDMI_AUDIO_VOLUME_RANGE 1023
#define DEF_HDMI_DIG_VOL        0x8000
#define DEF_HDMI_ANA_VOL        0x0A

/*******************************************************************************
                Configurations of Volume & Backlight
*******************************************************************************/
//Volume Control
#define MAX_VOLUME_VALUE        800//615//1023
#define MIN_VOLUME_VALUE        100//0
#define VOLUME_PWM_FREQ         40000

#define MAX_VOLUME_ANOGALE_VALUE (880+70)
#define MIN_VOLUME_ANOGALE_VALUE (265+70)


//Backlight Control
#define BRIGHTNESS_FR_PWM_FREQ  20000//((USHRT)PANEL_FRC_OUTPUT_VSYNC*4/10)
#define BRIGHTNESS_ND_PWM_FREQ  20000//((USHRT)InputTiming.usVSyncFreq*4/10)

/*******************************************************************************
                Minimum Luminance-Related Setting
*******************************************************************************/
#define BACKLIGHT_OFF_PWM_DUTY  223
#define ULTRA_MIN_BACKLIGHT_VALUE BACKLIGHT_OFF_PWM_DUTY
#define MIN_BACKLIGHT_VALUE      (BACKLIGHT_OFF_PWM_DUTY + 50)
#define MIN_CONTRAST_VALUE      28
#define MIN_GAIN_VALUE          55
#define MIN_OFFSET_VALUE        28

/*******************************************************************************
                           Allocate TX/RX buffer size
*******************************************************************************/
#define UART_TX_BUFFER_SIZE 16
#define UART_RX_BUFFER_SIZE 56

/*******************************************************************************
                          FE2P direct mode area configure
*******************************************************************************/
#define FE2P_DIRECTMODE_OFFSET 0x3C000 //Start Address
#define FE2P_DIRECTMODE_LEN    16 //Unit: 1K

//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************

//******************************************************************************
// E X T E R N A L   V A R I A B L E   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// S T A T I C   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************

#define Model_TEXT              "BENQ VW3206Q"
#define Inform_Model_TEXT       "GW2765HT"

#define LOGOWITH_EYE_CARE       OFF


#define LOGOWITH_HDMI           OFF
#define OSDTYPE                 OSD_BENQ_V2//OSD_BENQ//OSD_BENQ_V1//OSD_ID2011
#define FOSDTYPE                AOC_FactoryOSD

#define MAXIMUM_BRIGHTNESS_PWM  1023//100%
#define MINIMUM_BRIGHTNESS_PWM  61// 61 == 6% //100//30%
#define MAXIMUM_BRIGHTNESS_PWM_ULTRA   MINIMUM_BRIGHTNESS_PWM
#define MINIMUM_BRIGHTNESS_PWM_ULTRA    0//3


 #define DEF_ADCRGain           155
 #define DEF_ADCGGain           150
 #define DEF_ADCBGain           155
 #define DEF_ADCROffset         134
 #define DEF_ADCGOffset         127
 #define DEF_ADCBOffset         130
 #define DEF_5000KRGain         0xFF
 #define DEF_5000KGGain         0xFF
 #define DEF_5000KBGain         0xF0
 #define DEF_5800KRGain         255//0xFE
 #define DEF_5800KGGain         244//0xFE
 #define DEF_5800KBGain         234//0xE9
 #define DEF_6500KRGain         253//248  //6500
 #define DEF_6500KGGain         248//254  //6500
 #define DEF_6500KBGain         255//249  //6500
 #define DEF_7500KRGain         254  //Normal
 #define DEF_7500KGGain         248  //Normal
 #define DEF_7500KBGain         255  //Normal
 #define DEF_8200KRGain         0xF8
 #define DEF_8200KGGain         0xF8
 #define DEF_8200KBGain         0xFF
 #define DEF_9300KRGain         203//0xC8  //Cool
 #define DEF_9300KGGain         218//0xDC  //Cool
 #define DEF_9300KBGain         255//0xFF  //Cool
 #define DEF_11500KRGain        0xF0
 #define DEF_11500KGGain        0xF0
 #define DEF_11500KBGain        0xFF
 #define DEF_sRGBRGain          253//248
 #define DEF_sRGBGGain          248//254
 #define DEF_sRGBBGain          255//249
 #define DEF_VcomValue          0x40
 
#define DEF_PhotoRGain         DEF_9300KRGain
#define DEF_PhotoGGain         DEF_9300KGGain
#define DEF_PhotoBGain         DEF_9300KBGain
 #define DEF_GameRGain          DEF_9300KRGain
 #define DEF_GameGGain          DEF_9300KGGain
 #define DEF_GameBGain          DEF_9300KBGain
 
 #define DEF_MovieRGain        DEF_9300KRGain
 #define DEF_MovieGGain        DEF_9300KGGain
 #define DEF_MovieBGain        DEF_9300KBGain

 #define DEF_MULTIMEDIA_RGain        251
 #define DEF_MULTIMEDIA_GGain        254
 #define DEF_MULTIMEDIA_BGain        238

 #define DEF_WEB_SURFING_RGain        245
 #define DEF_WEB_SURFING_GGain        241
 #define DEF_WEB_SURFING_BGain        215

 #define DEF_OFFICE_RGain        243
 #define DEF_OFFICE_GGain        229
 #define DEF_OFFICE_BGain        194

 #define DEF_READING_RGain        241
 #define DEF_READING_GGain        220
 #define DEF_READING_BGain        180

 #define MAXBRI_LBL_MULTIMEDIA 42
#define MAXBRI_LBL_WEB_SURFING 40
#define MAXBRI_LBL_OFFICE 36
#define MAXBRI_LBL_READING 31







#if (MD_INPUT_INTERFACE&INPUT_VGA_MASK)
#define ENABLE_CUSTOMKEY_AUTOADJ      ON
#define ENABLE_OSD_ANALOG_FUNCTION    ON
#else
#define ENABLE_CUSTOMKEY_AUTOADJ      OFF//ON
#define ENABLE_OSD_ANALOG_FUNCTION    OFF
#endif


#define DEFLANG OSDLANG_ENGLISH


#define PANEL_CONTROL               OFF//ON/OFF

//Customkey
#define ENABLE_CUSTOMKEY_ANIMATION  OFF//ON
#define ENABLE_CUSTOMKEY_CAD        OFF//ON
#define ENABLE_CUSTOMKEY_LBL        OFF


//ECO & Eye protect sensor
#define ENABLE_ECO_EYE_SENSOR       OFF
#define ENABLE_EYE_PROTECT          OFF
#define ENABLE_ECO_SENSOR           OFF
#define ENABLE_ERGONOMICS          OFF



#define ENABLE_PRESENTATION_MODE    OFF//ON
#define ENABLE_PICTURE_MODE_ANIMATION       ON
#define ENABLE_PICTURE_MODE_CAD             ON
//#define ENABLE_PICTURE_MODE_PRESENTATION    ON
#define ENABLE_PICTURE_MODE_REC709      ON//OFF//ON
#define ENABLE_PICTURE_MODE_DARKROOM    ON//OFF//ON

#define ENABLE_OSD_SHOW_MODELNAME       ON

#define TPV_DP_VERSION_SELECT      ON

//1:1 mode
#define PICTURE_FORMAT_ONE_BY_ONE   OFF
//19" 22" 23"
#define ENABLE_MORE_DISPLAY_MODE    OFF//ON
//Smart Scaling
#define ENABLE_SMART_SCALING        OFF//ON

#define ENABLE_OD_IN_OSD            OFF //ON/OFF


/*******************************
       Support Lauguage
*******************************/
#define LANG01 OSDLANG_ENGLISH  
#define LANG02 OSDLANG_SPANISH   
#define LANG03 OSDLANG_FRENCH  
#define LANG04 OSDLANG_GERMAN
#define LANG05 OSDLANG_ITALIAN   
#define LANG06 OSDLANG_PORTUGUESE  
#define LANG07 OSDLANG_RUSSIAN    
#define LANG08 OSDLANG_CHINESE_S  
#define LANG09 OSDLANG_NONE  
#define LANG10 OSDLANG_NONE   
#define LANG11 OSDLANG_NONE   
#define LANG12 OSDLANG_NONE 
#define LANG13 OSDLANG_NONE   
#define LANG14 OSDLANG_NONE
#define LANG15 OSDLANG_NONE
#define LANG16 OSDLANG_NONE
#define LANG17 OSDLANG_NONE
#define LANG18 OSDLANG_NONE
#define LANG19 OSDLANG_NONE
#define LANG20 OSDLANG_NONE


#define USE_LANG_NUM17


#endif //__MODELCONFIG_H__
