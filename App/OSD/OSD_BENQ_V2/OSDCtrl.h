/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/
#ifndef __OSD_CTRL_H__
#define __OSD_CTRL_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "Typedef.h"
#include "Include.h"
//******************************************************************************
// G L O B A L   D E F I N I T I O N S
//******************************************************************************
#define OSD_ITEM_LBL_STATE          OSD_ITEM_3_1_7_STATE
#define OSD_ITEM_ANIMATION_STATE    OSD_ITEM_3_1_3_STATE

#define OSD_SUBITEM_LBL_STATE_BEG   OSD_SUBITEM_3_1_2_STATE_BEG

#define OSD_INPUT_NUMBER        ((OSD_ITEM_1_2_END-OSD_ITEM_1_2_start_STATE)-1)

enum _OSDAPPCEVENT_ {
    OSD_NO_SYNC_EVENT,
    OSD_NO_CABLE_EVENT,
    OSD_NML_EVENT,
    OSD_OOL_EVENT,
    OSD_OOR_EVENT,
    OSD_OFF_EVENT,
    OSD_NOP_EVENT,
    NUM_OSD_APP_EVENTS
} ;

enum _OSDKEYEVENT_ {
    OSD_MENUKEY_EVENT,
    OSD_AUTOKEY_EVENT,
    OSD_UPKEY_EVENT,
    OSD_DOWNKEY_EVENT,
    OSD_EXITKEY_EVENT,
    OSD_NONKEY_EVENT,
    NUM_OSD_KEY_EVENTS
} ;

enum _OSDLAY4LANG_ {
    OSD_LAY4_LANG_NONE,
    OSD_LAY4_LANG_UPDOWN,
} ;

typedef enum _OSDSTATE_ {
    OSD_OFF_STATE,
    OSD_TOPPAGE_BEG,
    OSD_TOPPAGE_STATE = OSD_TOPPAGE_BEG,
    OSD_TOPPAGE_END,

    OSD_CUSTKEY_PICTUREMODE_1_STATE = OSD_TOPPAGE_END,  //sRGB
#if	ENABLE_PICTURE_MODE_CAD == ON
    OSD_CUSTKEY_PICTUREMODE_2_STATE,    //CAD
#endif
#if	ENABLE_PICTURE_MODE_ANIMATION == ON
    OSD_CUSTKEY_PICTUREMODE_3_STATE,    //Animation
#endif
#if	ENABLE_PRESENTATION_MODE == ON
    OSD_CUSTKEY_PICTUREMODE_4_STATE,    //Presentation
#endif
    OSD_CUSTKEY_PICTUREMODE_5_STATE,    //Standard
#if ENABLE_PICTURE_MODE_REC709 == ON               
    OSD_CUSTKEY_PICTUREMODE_6_STATE,    //Rec709
#endif    
    OSD_CUSTKEY_PICTUREMODE_7_STATE,    //LBL
#if ENABLE_PICTURE_MODE_MOVIE == ON           
    OSD_CUSTKEY_PICTUREMODE_8_STATE,    //Movie
#endif    
#if ENABLE_PICTURE_MODE_GAME == ON    
    OSD_CUSTKEY_PICTUREMODE_9_STATE,    //Game
#endif        
#if ENABLE_PICTURE_MODE_PHOTO== ON       
    OSD_CUSTKEY_PICTUREMODE_10_STATE,    //Photo
#endif   
#if ENABLE_PICTURE_MODE_DARKROOM== ON               
    OSD_CUSTKEY_PICTUREMODE_11_STATE,    //Darkroom
#endif
    OSD_CUSTKEY_PICTUREMODE_12_STATE,   //ECO
#if ENABLE_PICTURE_MODE_MBOOK == ON
    OSD_CUSTKEY_PICTUREMODE_13_STATE,   //Mbook
#endif
    OSD_CUSTKEY_PICTUREMODE_14_STATE,
    OSD_CUSTKEY_PICTUREMODE_END,
    OSD_CUSTKEY_INPUT_BEG = (OSD_CUSTKEY_PICTUREMODE_END-1),
#if MD_INPUT_INTERFACE&INPUT_VGA0    
    OSD_CUSTKEY_INPUT_1_STATE ,
#endif
#if MD_INPUT_INTERFACE&INPUT_DIG1//MD_INPUT_INTERFACE&INPUT_DIG0 
    OSD_CUSTKEY_INPUT_2_STATE,
#endif
#if MD_INPUT_INTERFACE&INPUT_DIG2 
    OSD_CUSTKEY_INPUT_3_STATE,
#endif
#if MD_INPUT_INTERFACE&INPUT_DIG3//MD_INPUT_INTERFACE&INPUT_DP
    OSD_CUSTKEY_INPUT_4_STATE,
#endif
#if MD_INPUT_INTERFACE&INPUT_DP1
    OSD_CUSTKEY_INPUT_5_STATE,
#endif
    OSD_CUSTKEY_INPUT_END,
    OSD_CUSTKEY_DISPLAYMODE_1_STATE = OSD_CUSTKEY_INPUT_END,
    OSD_CUSTKEY_DISPLAYMODE_2_STATE,
    OSD_CUSTKEY_DISPLAYMODE_3_STATE,
#if ENABLE_MORE_DISPLAY_MODE == ON    
    OSD_CUSTKEY_DISPLAYMODE_4_STATE,
    OSD_CUSTKEY_DISPLAYMODE_5_STATE,
    OSD_CUSTKEY_DISPLAYMODE_6_STATE,    
#endif    
    OSD_CUSTKEY_DISPLAYMODE_END,

    OSD_CUSTKEY_VOLUME_STATE = OSD_CUSTKEY_DISPLAYMODE_END,
    OSD_CUSTKEY_VOLUME_END,
    OSD_CUSTKEY_MUTE_1_STATE = OSD_CUSTKEY_VOLUME_END,
    OSD_CUSTKEY_MUTE_2_STATE,
    OSD_CUSTKEY_MUTE_END,
#if ENABLE_EYE_PROTECT == ON
    OSD_CUSTKEY_EYE_PROTECT_1_STATE = OSD_CUSTKEY_MUTE_END,
    OSD_CUSTKEY_EYE_PROTECT_2_STATE,
    OSD_CUSTKEY_EYE_PROTECT_END,
    OSD_CUSTKEY_EYE_PROTECT_METER_1_STATE = OSD_CUSTKEY_EYE_PROTECT_END,
    OSD_CUSTKEY_EYE_PROTECT_METER_2_STATE,
    OSD_CUSTKEY_EYE_PROTECT_METER_END,    
#endif
#if ENABLE_ECO_SENSOR== ON
    #if ENABLE_EYE_PROTECT == ON
    OSD_CUSTKEY_ECO_SENSOR_1_STATE = OSD_CUSTKEY_EYE_PROTECT_METER_END,
    #else
    OSD_CUSTKEY_ECO_SENSOR_1_STATE = OSD_CUSTKEY_MUTE_END,
    #endif
    OSD_CUSTKEY_ECO_SENSOR_2_STATE,
    OSD_CUSTKEY_ECO_SENSOR_END,
    OSD_CUSTKEY_ECO_SENSOR_METER_1_STATE = OSD_CUSTKEY_ECO_SENSOR_END,
    OSD_CUSTKEY_ECO_SENSOR_METER_2_STATE,
    OSD_CUSTKEY_ECO_SENSOR_METER_END,    
#endif
#if ENABLE_ERGONOMICS == ON
    #if (ENABLE_ECO_SENSOR== ON) && (ENABLE_EYE_PROTECT == ON)
    OSD_CUSTKEY_SMARTREMINDER_1_STATE = OSD_CUSTKEY_ECO_SENSOR_METER_END,
    #elif (ENABLE_ECO_SENSOR== OFF) && (ENABLE_EYE_PROTECT == OFF)
    OSD_CUSTKEY_SMARTREMINDER_1_STATE = OSD_CUSTKEY_MUTE_END,
    #else
    #warning "OSD_CUSTKEY_SMARTREMINDER_1_STATE error!"
    #endif    
    OSD_CUSTKEY_SMARTREMINDER_2_STATE,
    OSD_CUSTKEY_SMARTREMINDER_END,
#endif    
#if ENABLE_CUSTOMKEY_LBL == ON    
    #if ENABLE_ERGONOMICS == ON
    OSD_CUSTKEY_LOWBULELIGHTMODE_1_STATE = OSD_CUSTKEY_SMARTREMINDER_END,
    //#elif ENABLE_ERGONOMICS == OFF && ENABLE_ECO_SENSOR == ON
    //OSD_CUSTKEY_LOWBULELIGHTMODE_1_STATE = OSD_CUSTKEY_ECO_SENSOR_METER_END,
    //#elif ENABLE_ERGONOMICS == OFF && ENABLE_ECO_SENSOR == OFF && ENABLE_EYE_PROTECT == ON
    //OSD_CUSTKEY_LOWBULELIGHTMODE_1_STATE = OSD_CUSTKEY_EYE_PROTECT_METER_END,
    #elif ENABLE_ERGONOMICS == OFF && ENABLE_ECO_SENSOR == OFF && ENABLE_EYE_PROTECT == OFF
    OSD_CUSTKEY_LOWBULELIGHTMODE_1_STATE = OSD_CUSTKEY_MUTE_END,
    #else
    #warning "OSD_CUSTKEY_LOWBULELIGHTMODE_1_STATE error!"
    #endif
    OSD_CUSTKEY_LOWBULELIGHTMODE_2_STATE,
    OSD_CUSTKEY_LOWBULELIGHTMODE_3_STATE,
    OSD_CUSTKEY_LOWBULELIGHTMODE_4_STATE,
    OSD_CUSTKEY_LOWBULELIGHTMODE_END,    
#endif    
#if ENABLE_CUSTOMKEY_CAD == ON
    #if ENABLE_CUSTOMKEY_LBL == ON       
    OSD_CUSTKEY_CAD_STATE = OSD_CUSTKEY_LOWBULELIGHTMODE_END,
    //#elif (ENABLE_CUSTOMKEY_LBL == OFF) && (ENABLE_ERGONOMICS == ON)  
    //OSD_CUSTKEY_CAD_STATE = OSD_CUSTKEY_SMARTREMINDER_END,
    #elif (ENABLE_CUSTOMKEY_LBL == OFF) && (ENABLE_ERGONOMICS == OFF) && (ENABLE_ECO_SENSOR == OFF) && (ENABLE_EYE_PROTECT == OFF)  
    OSD_CUSTKEY_CAD_STATE = OSD_CUSTKEY_MUTE_END,
    #else
    #warning "OSD_CUSTKEY_CAD_STATE error!!"
    #endif
    OSD_CUSTKEY_CAD_END,
#endif
#if ENABLE_CUSTOMKEY_ANIMATION == ON
    #if ENABLE_CUSTOMKEY_CAD == ON
    OSD_CUSTKEY_ANIMATION_STATE = OSD_CUSTKEY_CAD_END,
    #elif (ENABLE_CUSTOMKEY_CAD == OFF) && (ENABLE_CUSTOMKEY_LBL == ON)
    OSD_CUSTKEY_ANIMATION_STATE = OSD_CUSTKEY_LOWBULELIGHTMODE_END,
    //#elif (ENABLE_CUSTOMKEY_CAD == OFF) && (ENABLE_CUSTOMKEY_LBL == OFF)
    //OSD_CUSTKEY_ANIMATION_STATE = OSD_CUSTKEY_SMARTREMINDER_END,
    #elif (ENABLE_CUSTOMKEY_CAD == OFF) && (ENABLE_CUSTOMKEY_LBL == OFF) && (ENABLE_ERGONOMICS == OFF) && ENABLE_ECO_SENSOR == OFF && ENABLE_EYE_PROTECT == OFF
    OSD_CUSTKEY_ANIMATION_STATE = OSD_CUSTKEY_MUTE_END,
    #else
    #warning "OSD_CUSTKEY_ANIMATION_STATE error!!"
    #endif
    OSD_CUSTKEY_ANIMATION_END,
#endif  

    #if (ENABLE_CUSTOMKEY_ANIMATION== OFF) && (ENABLE_CUSTOMKEY_CAD == OFF) && (ENABLE_CUSTOMKEY_LBL == OFF) && (ENABLE_ERGONOMICS == OFF) && ENABLE_ECO_SENSOR == OFF && ENABLE_EYE_PROTECT == OFF
    OSD_CUSTKEY_CONTRAST_STATE = OSD_CUSTKEY_MUTE_END,
    #else
    #warning "OSD_CUSTKEY_CONTRAST_STATE error!!"
    #endif
    OSD_CUSTKEY_CONTRAST_END,
    OSD_CUSTKEY_BRIGHTNESS_STATE = OSD_CUSTKEY_CONTRAST_END,
    OSD_CUSTKEY_BRIGHTNESS_END,


    OSD_MAIN_BEG = OSD_CUSTKEY_BRIGHTNESS_END,
    OSD_MAIN_1_STATE = OSD_MAIN_BEG,
    OSD_MAIN_2_STATE,
    OSD_MAIN_3_STATE,
    OSD_MAIN_Audio_STATE,
    OSD_MAIN_4_STATE,
#if ENABLE_ERGONOMICS == ON
    OSD_MAIN_ERGO_STATE,
#endif
#if ENABLE_ECO_SENSOR == ON    
    OSD_MAIN_ECO_STATE,
#endif    
    OSD_MAIN_END,

    OSD_MAIN_1_1_STATE = OSD_MAIN_END,
#if ENABLE_OSD_ANALOG_FUNCTION == OFF
    #if ENABLE_AUTO_POVIT_FUNC == ON    
    OSD_MAIN_1_POVIT_STATE = OSD_MAIN_1_1_STATE,
    OSD_MAIN_1_2_STATE,
    #else
    OSD_MAIN_1_2_STATE = OSD_MAIN_1_1_STATE,
    #endif  
#else
    #if ENABLE_AUTO_POVIT_FUNC == ON    
    OSD_MAIN_1_POVIT_STATE,
    #endif 
    OSD_MAIN_1_2_STATE,
    OSD_MAIN_1_3_STATE,
    OSD_MAIN_1_4_STATE,
    OSD_MAIN_1_5_STATE,
    OSD_MAIN_1_6_STATE,
#endif
    OSD_MAIN_1_END,

    OSD_MAIN_2_1_STATE = OSD_MAIN_1_END,
    OSD_MAIN_2_2_STATE,
    OSD_MAIN_2_3_STATE,
    OSD_MAIN_2_4_STATE,
    OSD_MAIN_2_5_STATE,
    OSD_MAIN_2_6_STATE,
    OSD_MAIN_2_7_STATE,
    OSD_MAIN_2_8_STATE,
    OSD_MAIN_2_9_STATE,
    OSD_MAIN_2_END,


    OSD_MAIN_3_1_STATE = OSD_MAIN_2_END,
    OSD_MAIN_3_2_STATE,
    OSD_MAIN_3_3_STATE,
#if MD_ENABLE_OVERSCAN == ON    
    OSD_MAIN_3_4_STATE,
#endif    
    OSD_MAIN_3_5_STATE,
#if ENABLE_SMART_SCALING == ON
    OSD_MAIN_3_SMART_SCALING_STATE,
#endif
#if ENABLE_COLOR_FORMAT == ON                                                
    OSD_MAIN_3_6_STATE,
#endif    
    OSD_MAIN_3_7_STATE,
    OSD_MAIN_3_END,

    OSD_MAIN_Audio_1_STATE = OSD_MAIN_3_END,
    OSD_MAIN_Audio_2_STATE,
#if ENABLE_AUDIO_SELECT == ON    
    OSD_MAIN_Audio_3_STATE,
#endif    
    OSD_MAIN_Audio_END,

    OSD_MAIN_4_1_STATE = OSD_MAIN_Audio_END,
    OSD_MAIN_4_2_STATE,
    OSD_MAIN_4_3_STATE,
    OSD_MAIN_4_4_STATE,
    OSD_MAIN_4_5_STATE,
#if ENABLE_DPHDMI_AUTO_SWITCH == ON
    OSD_MAIN_4_6_STATE,//DP auto switch
#endif    
    OSD_MAIN_4_11_STATE,//Display Port  
#if ENABLE_DPHDMI_AUTO_SWITCH == ON    
    OSD_MAIN_4_7_STATE,//HDMI auto switch
#endif    
    OSD_MAIN_4_8_STATE,
    OSD_MAIN_4_9_STATE,
    OSD_MAIN_4_10_STATE,
    OSD_MAIN_4_12_STATE,
    OSD_MAIN_4_END,
#if ENABLE_EYE_PROTECT == ON
    OSD_MAIN_EYE_PROTECT_STATE = OSD_MAIN_4_END,
    OSD_MAIN_EYE_PROTECT_METER_STATE,
#if ENABLE_ERGONOMICS == ON
    OSD_MAIN_ERGO_1_STATE,
#endif
#else    
#if ENABLE_ERGONOMICS == ON
    OSD_MAIN_ERGO_1_STATE = OSD_MAIN_4_END,
#endif
#endif   
#if ENABLE_ERGONOMICS == ON
    OSD_MAIN_ERGO_2_STATE,
    OSD_MAIN_ERGO_3_STATE,
    OSD_MAIN_ERGO_END,
#endif
#if ENABLE_ECO_SENSOR == ON
    OSD_MAIN_ECO_SENSOR_STATE = OSD_MAIN_ERGO_END,
    OSD_MAIN_ECO_SENSOR_METER_STATE,
    OSD_MAIN_ECO_SENSOR_RANGE_STATE,
    OSD_MAIN_ECO_END,
    OSD_ITEM_1_1_STATE = OSD_MAIN_ECO_END,    
#else
#if ENABLE_ERGONOMICS == ON
    OSD_ITEM_1_1_STATE = OSD_MAIN_ERGO_END,
#else
    OSD_ITEM_1_1_STATE = OSD_MAIN_4_END,
#endif
#endif    
    OSD_ITEM_1_1_END,
#if ENABLE_OSD_ANALOG_FUNCTION == OFF
#if ENABLE_AUTO_POVIT_FUNC == ON     
    OSD_ITEM_PIVOT_1_STATE = OSD_ITEM_1_1_STATE,
    OSD_ITEM_PIVOT_2_STATE,
    OSD_ITEM_PIVOT_END,
    OSD_ITEM_1_2_start_STATE = (OSD_ITEM_PIVOT_END-1),
#else
    OSD_ITEM_1_2_start_STATE = (OSD_ITEM_1_1_STATE-1),
#endif
#if MD_INPUT_INTERFACE&INPUT_VGA0
    OSD_ITEM_1_2_1_STATE,
#endif
#if MD_INPUT_INTERFACE&INPUT_DIG1//MD_INPUT_INTERFACE&INPUT_DIG0
    OSD_ITEM_1_2_2_STATE,
#endif
#if MD_INPUT_INTERFACE&INPUT_DIG2
    OSD_ITEM_1_2_3_STATE,
#endif
#if MD_INPUT_INTERFACE&INPUT_DIG3//MD_INPUT_INTERFACE&INPUT_DP
    OSD_ITEM_1_2_4_STATE,
#endif
#if MD_INPUT_INTERFACE&INPUT_DP1
    OSD_ITEM_1_2_5_STATE,
#endif
    OSD_ITEM_1_2_END,
    OSD_ITEM_2_1_STATE = OSD_ITEM_1_2_END,
#else
#if ENABLE_AUTO_POVIT_FUNC == ON     
    OSD_ITEM_PIVOT_1_STATE = OSD_ITEM_1_1_END,
    OSD_ITEM_PIVOT_2_STATE,
    OSD_ITEM_PIVOT_END,
    OSD_ITEM_1_2_start_STATE = (OSD_ITEM_PIVOT_END-1),
#else
    OSD_ITEM_1_2_start_STATE = (OSD_ITEM_1_1_END-1),
#endif
#if MD_INPUT_INTERFACE&INPUT_VGA0
    OSD_ITEM_1_2_1_STATE,
#endif
#if MD_INPUT_INTERFACE&INPUT_DIG1//MD_INPUT_INTERFACE&INPUT_DIG0
    OSD_ITEM_1_2_2_STATE,
#endif
#if MD_INPUT_INTERFACE&INPUT_DIG2
    OSD_ITEM_1_2_3_STATE,
#endif
#if MD_INPUT_INTERFACE&INPUT_DIG3//MD_INPUT_INTERFACE&INPUT_DP
    OSD_ITEM_1_2_4_STATE,
#endif
#if MD_INPUT_INTERFACE&INPUT_DP1
    OSD_ITEM_1_2_5_STATE,
#endif
    OSD_ITEM_1_2_END,
    OSD_ITEM_1_3_STATE = OSD_ITEM_1_2_END,
    OSD_ITEM_1_4_STATE,
    OSD_ITEM_1_5_STATE,
    OSD_ITEM_1_6_STATE,
    OSD_ITEM_2_1_STATE,
#endif

    OSD_ITEM_2_2_STATE,
    OSD_ITEM_2_3_STATE,
    OSD_ITEM_2_4_1_STATE,
    OSD_ITEM_2_4_2_STATE,
    OSD_ITEM_2_4_3_STATE,
    OSD_ITEM_2_4_4_STATE,
    OSD_ITEM_2_4_5_STATE,
    OSD_ITEM_2_4_END,
    OSD_ITEM_2_5_1_STATE = OSD_ITEM_2_4_END,
    OSD_ITEM_2_5_2_STATE,
    OSD_ITEM_2_5_3_STATE,
    OSD_ITEM_2_5_4_STATE,
    OSD_ITEM_2_5_END,
    OSD_ITEM_2_6_STATE = OSD_ITEM_2_5_END,
    OSD_ITEM_2_7_STATE,
    OSD_ITEM_2_8_1_STATE,
    OSD_ITEM_2_8_2_STATE,
    OSD_ITEM_2_8_END,
    OSD_ITEM_2_9_1_STATE = OSD_ITEM_2_8_END,
    OSD_ITEM_2_9_2_STATE,
    OSD_ITEM_2_9_3_STATE,
    OSD_ITEM_2_9_END,


    OSD_ITEM_3_1_1_STATE = OSD_ITEM_2_9_END,    //stand
#if	ENABLE_PICTURE_MODE_REC709== ON 
    OSD_ITEM_3_1_2_STATE,                       //rec//CAD
#endif
    OSD_ITEM_3_1_3_STATE,                       //SRGB
#if	ENABLE_PICTURE_MODE_CAD == ON
    OSD_ITEM_3_1_4_STATE,                       //CAD
#endif
#if ENABLE_PICTURE_MODE_ANIMATION == ON
    OSD_ITEM_3_1_5_STATE,                       //ANIMATION
#endif
#if	ENABLE_PRESENTATION_MODE== ON    
    OSD_ITEM_3_1_6_STATE,                       //PRESENTATION
#endif    
    OSD_ITEM_3_1_7_STATE,                       //LBL
#if ENABLE_PICTURE_MODE_MOVIE== ON    
    OSD_ITEM_3_1_8_STATE,                       //Movie
#endif    
#if ENABLE_PICTURE_MODE_GAME == ON       
    OSD_ITEM_3_1_9_STATE,                       //Game
#endif    
#if ENABLE_PICTURE_MODE_PHOTO== ON           
    OSD_ITEM_3_1_10_STATE,                       //Photo
#endif
    OSD_ITEM_3_1_11_STATE,                      //Darkroom
    OSD_ITEM_3_1_12_STATE,                      //ECO   
#if ENABLE_PICTURE_MODE_MBOOK == ON    
    OSD_ITEM_3_1_13_STATE,                      //Mbook
#endif    
    OSD_ITEM_3_1_14_STATE,                      //User
    OSD_ITEM_3_1_END,
    OSD_ITEM_3_2_1_STATE = OSD_ITEM_3_1_END,
    OSD_ITEM_3_2_3_STATE,                       //SRGB
#if	ENABLE_PICTURE_MODE_CAD == ON
    OSD_ITEM_3_2_4_STATE,                       //CAD
#endif
#if	ENABLE_PICTURE_MODE_ANIMATION == ON
    OSD_ITEM_3_2_5_STATE,                       //Animation
#endif
    OSD_ITEM_3_2_6_STATE,                       //LBL
#if	ENABLE_PICTURE_MODE_DARKROOM == ON
    OSD_ITEM_3_2_7_STATE,                       //DARKROOM
#endif
    OSD_ITEM_3_2_8_STATE,                       //User  
    OSD_ITEM_3_2_END,
    OSD_ITEM_3_3_STATE =OSD_ITEM_3_2_END,
    OSD_ITEM_3_3_END,
#if MD_ENABLE_OVERSCAN == ON        
    OSD_ITEM_3_4_1_STATE = OSD_ITEM_3_3_END,
    OSD_ITEM_3_4_2_STATE,
    OSD_ITEM_3_4_END,
    OSD_ITEM_3_5_1_STATE =OSD_ITEM_3_4_END,
#else
    OSD_ITEM_3_5_1_STATE = OSD_ITEM_3_3_END,
#endif    
    OSD_ITEM_3_5_2_STATE,
    OSD_ITEM_3_5_3_STATE,
#if ENABLE_MORE_DISPLAY_MODE == ON
    OSD_ITEM_3_5_4_STATE,
    OSD_ITEM_3_5_5_STATE,
    OSD_ITEM_3_5_6_STATE,
#endif
    OSD_ITEM_3_5_END,
#if ENABLE_SMART_SCALING == ON
    OSD_ITEM_3_SMART_SCALING_STATE = OSD_ITEM_3_5_END,
    OSD_ITEM_3_SMART_SCALING_END,
    OSD_ITEM_3_6_1_STATE = OSD_ITEM_3_SMART_SCALING_END,
#else
    #if ENABLE_COLOR_FORMAT == ON
    OSD_ITEM_3_6_1_STATE = OSD_ITEM_3_5_END,
    #endif
#endif
    #if ENABLE_COLOR_FORMAT == ON
    OSD_ITEM_3_6_2_STATE,
    OSD_ITEM_3_6_END,
    #else 
    OSD_ITEM_3_6_END = OSD_ITEM_3_5_END,    
    #endif
    OSD_ITEM_3_7_1_STATE = OSD_ITEM_3_6_END,
    OSD_ITEM_3_7_2_STATE,
    OSD_ITEM_3_7_3_STATE,
    OSD_ITEM_3_7_END,
    OSD_ITEM_3_END = OSD_ITEM_3_7_END,

    OSD_ITEM_Audio_1_1_STATE =OSD_ITEM_3_END,
    OSD_ITEM_Audio_2_1_STATE,
    OSD_ITEM_Audio_2_2_STATE,
    OSD_ITEM_Audio_2_END,
#if ENABLE_AUDIO_SELECT == ON        
    OSD_ITEM_Audio_3_1_STATE = OSD_ITEM_Audio_2_END,
    OSD_ITEM_Audio_3_2_STATE,
    OSD_ITEM_Audio_3_3_STATE, 
    OSD_ITEM_Audio_3_4_STATE, 
    OSD_ITEM_Audio_3_END,
    OSD_ITEM_Audio_END =OSD_ITEM_Audio_3_END,
#else
    OSD_ITEM_Audio_END =OSD_ITEM_Audio_2_END,
#endif

    OSD_ITEM_4_1_1_STATE = OSD_ITEM_Audio_END,
    OSD_ITEM_4_1_2_STATE,
    OSD_ITEM_4_1_3_STATE,
    OSD_ITEM_4_1_END,
    OSD_ITEM_4_2_1_STATE = OSD_ITEM_4_1_END,
#if ENABLE_CUSTOMKEY_CAD == ON           
    OSD_ITEM_4_2_2_STATE,
#endif    
#if ENABLE_CUSTOMKEY_ANIMATION== ON           
    OSD_ITEM_4_2_3_STATE,
#endif
#if ENABLE_CUSTOMKEY_LBL== ON           
    OSD_ITEM_4_2_4_STATE,
#endif    
    OSD_ITEM_4_2_5_STATE,       //Display Mode
    OSD_ITEM_4_2_6_STATE,       //Brightness
    OSD_ITEM_4_2_7_STATE,       //Contrast
#if ENABLE_CUSTOMKEY_AUTOADJ == ON    
    OSD_ITEM_4_2_8_STATE,       //AutoAdj
#endif    
    OSD_ITEM_4_2_9_STATE,       //Vol
    OSD_ITEM_4_2_10_STATE,      //Mute
    OSD_ITEM_4_2_11_STATE,      //Input
#if ENABLE_EYE_PROTECT == ON    
    OSD_ITEM_4_2_12_STATE,    
    OSD_ITEM_4_2_13_STATE,
#endif    
#if ENABLE_ECO_SENSOR == ON
    OSD_ITEM_4_2_14_STATE,    
    OSD_ITEM_4_2_15_STATE,
#endif    
#if ENABLE_ERGONOMICS == ON
    OSD_ITEM_4_2_16_STATE,      //Smart Reminder
#endif    
    OSD_ITEM_4_2_END,
    OSD_ITEM_4_3_1_STATE = OSD_ITEM_4_2_END,
#if ENABLE_CUSTOMKEY_CAD == ON        
    OSD_ITEM_4_3_2_STATE,
#endif    
#if ENABLE_CUSTOMKEY_ANIMATION== ON 
    OSD_ITEM_4_3_3_STATE,
#endif
#if ENABLE_CUSTOMKEY_LBL== ON
    OSD_ITEM_4_3_4_STATE,
#endif    
    OSD_ITEM_4_3_5_STATE,
    OSD_ITEM_4_3_6_STATE,
    OSD_ITEM_4_3_7_STATE,
#if ENABLE_CUSTOMKEY_AUTOADJ == ON        
    OSD_ITEM_4_3_8_STATE,
#endif    
    OSD_ITEM_4_3_9_STATE,
    OSD_ITEM_4_3_10_STATE,
    OSD_ITEM_4_3_11_STATE,    
#if ENABLE_EYE_PROTECT == ON
    OSD_ITEM_4_3_12_STATE,
    OSD_ITEM_4_3_13_STATE,    
#endif
#if ENABLE_ECO_SENSOR== ON
    OSD_ITEM_4_3_14_STATE,
    OSD_ITEM_4_3_15_STATE,    
#endif
#if ENABLE_ERGONOMICS == ON
    OSD_ITEM_4_3_16_STATE,
#endif    
    OSD_ITEM_4_3_END,
    OSD_ITEM_4_4_1_STATE = OSD_ITEM_4_3_END,
#if ENABLE_CUSTOMKEY_CAD == ON        
    OSD_ITEM_4_4_2_STATE,
#endif    
#if ENABLE_CUSTOMKEY_ANIMATION== ON 
    OSD_ITEM_4_4_3_STATE,
#endif
#if ENABLE_CUSTOMKEY_LBL== ON
    OSD_ITEM_4_4_4_STATE,
#endif    
    OSD_ITEM_4_4_5_STATE,
    OSD_ITEM_4_4_6_STATE,
    OSD_ITEM_4_4_7_STATE,//ULEric130331
#if ENABLE_CUSTOMKEY_AUTOADJ == ON        
    OSD_ITEM_4_4_8_STATE,//ULEric130331
#endif    
    OSD_ITEM_4_4_9_STATE,//ULEric130331
    OSD_ITEM_4_4_10_STATE,//ULEric130331
    OSD_ITEM_4_4_11_STATE,//ULEric130331    
#if ENABLE_EYE_PROTECT == ON
    OSD_ITEM_4_4_12_STATE,
    OSD_ITEM_4_4_13_STATE,    
#endif
#if ENABLE_ECO_SENSOR== ON
    OSD_ITEM_4_4_14_STATE,
    OSD_ITEM_4_4_15_STATE,    
#endif
#if ENABLE_ERGONOMICS == ON
    OSD_ITEM_4_4_16_STATE,
#endif    
    OSD_ITEM_4_4_END,
    OSD_ITEM_4_5_1_STATE = OSD_ITEM_4_4_END,
    OSD_ITEM_4_5_2_STATE,
    OSD_ITEM_4_5_END,
#if ENABLE_DPHDMI_AUTO_SWITCH == ON    
    OSD_ITEM_4_6_1_STATE =OSD_ITEM_4_5_END,
    OSD_ITEM_4_6_2_STATE,
    OSD_ITEM_4_6_END,
    OSD_ITEM_4_7_1_STATE =OSD_ITEM_4_6_END,
    OSD_ITEM_4_7_2_STATE,
    OSD_ITEM_4_7_END,
    OSD_ITEM_4_8_1_STATE = OSD_ITEM_4_7_END,
#else
    OSD_ITEM_4_8_1_STATE = OSD_ITEM_4_5_END,
#endif
    OSD_ITEM_4_8_2_STATE,
    OSD_ITEM_4_8_3_STATE,
    OSD_ITEM_4_8_4_STATE,
    OSD_ITEM_4_8_END,
    OSD_ITEM_4_9_1_STATE = OSD_ITEM_4_8_END,
    OSD_ITEM_4_9_2_STATE,
    OSD_ITEM_4_9_END,
    OSD_ITEM_4_10_STATE = OSD_ITEM_4_9_END,
    OSD_ITEM_4_11_1_STATE,
    OSD_ITEM_4_11_2_STATE,
    OSD_ITEM_4_11_END,
    OSD_ITEM_4_12_1_STATE =OSD_ITEM_4_11_END,
    OSD_ITEM_4_12_2_STATE,
    OSD_ITEM_4_12_END,

#if ENABLE_EYE_PROTECT == ON
    OSD_ITEM_EYE_PROTECT_1_STATE = OSD_ITEM_4_12_END,
    OSD_ITEM_EYE_PROTECT_2_STATE,
    OSD_ITEM_EYE_PROTECT_END,
    OSD_ITEM_EYE_PROTECT_METER_1_STATE = OSD_ITEM_EYE_PROTECT_END,
    OSD_ITEM_EYE_PROTECT_METER_2_STATE,
    OSD_ITEM_EYE_PROTECT_METER_END,
    OSD_ITEM_ERGO_1_1_STATE = OSD_ITEM_EYE_PROTECT_METER_END,
#else
#if ENABLE_ERGONOMICS == ON
    OSD_ITEM_ERGO_1_1_STATE =OSD_ITEM_4_12_END,    
    OSD_ITEM_ERGO_1_2_STATE,
    OSD_ITEM_ERGO_1_END,
    OSD_ITEM_ERGO_2_1_STATE = OSD_ITEM_ERGO_1_END,
    OSD_ITEM_ERGO_2_2_STATE,
    OSD_ITEM_ERGO_2_3_STATE,
    OSD_ITEM_ERGO_2_4_STATE,
    OSD_ITEM_ERGO_2_5_STATE,
    OSD_ITEM_ERGO_2_END,
    OSD_ITEM_ERGO_3_1_STATE = OSD_ITEM_ERGO_2_END,
    OSD_ITEM_ERGO_3_2_STATE,
    OSD_ITEM_ERGO_3_3_STATE,
    OSD_ITEM_ERGO_3_4_STATE,
    OSD_ITEM_ERGO_3_5_STATE,
    OSD_ITEM_ERGO_3_END,
    OSD_ITEM_ERGO_END =OSD_ITEM_ERGO_3_END,
#endif
#endif
#if ENABLE_ECO_SENSOR == ON
    OSD_ITEM_ECO_1_1_STATE =OSD_ITEM_ERGO_END,
    OSD_ITEM_ECO_1_2_STATE,
    OSD_ITEM_ECO_1_END,
    OSD_ITEM_ECO_2_1_STATE = OSD_ITEM_ECO_1_END,
    OSD_ITEM_ECO_2_2_STATE,
    OSD_ITEM_ECO_2_END,
    OSD_ITEM_ECO_3_1_STATE = OSD_ITEM_ECO_2_END,
    OSD_ITEM_ECO_3_2_STATE,
    OSD_ITEM_ECO_3_3_STATE,
    OSD_ITEM_ECO_3_END,
    OSD_ITEM_ECO_END =OSD_ITEM_ECO_3_END,
    // Color temperature
    OSD_SUBITEM_2_5_4_STATE_BEG = OSD_ITEM_ECO_END,
#else
    // Color temperature
    OSD_SUBITEM_2_5_4_STATE_BEG = OSD_ITEM_4_12_END,
#endif
    OSD_SUBITEM_2_5_4_1_STATE = OSD_SUBITEM_2_5_4_STATE_BEG,
    OSD_SUBITEM_2_5_4_2_STATE,
    OSD_SUBITEM_2_5_4_3_STATE,
    OSD_SUBITEM_2_5_4_END,
    //low blue light
    OSD_SUBITEM_3_1_2_STATE_BEG = OSD_SUBITEM_2_5_4_END,
    OSD_SUBITEM_3_1_2_1_STATE = OSD_SUBITEM_3_1_2_STATE_BEG,
    OSD_SUBITEM_3_1_2_2_STATE,
    OSD_SUBITEM_3_1_2_3_STATE,
    OSD_SUBITEM_3_1_2_4_STATE,
    OSD_SUBITEM_3_1_2_END,
#if ENABLE_PICTURE_MODE_ANIMATION == ON
    OSD_SUBITEM_3_1_3_STATE_BEG = OSD_SUBITEM_3_1_2_END,
    OSD_SUBITEM_3_1_3_1_STATE = OSD_SUBITEM_3_1_3_STATE_BEG,
    OSD_SUBITEM_3_1_3_END,
    OSD_SUBITEM_3_2_1_STATE_BEG = OSD_SUBITEM_3_1_3_END,
#else
    OSD_SUBITEM_3_2_1_STATE_BEG = OSD_SUBITEM_3_1_2_END,
#endif
    OSD_SUBITEM_3_2_1_1_STATE = OSD_SUBITEM_3_2_1_STATE_BEG,//SRGB
    OSD_SUBITEM_3_2_1_2_STATE,                       //LBL
    OSD_SUBITEM_3_2_1_END,    
    // Multi-Language
    OSD_SUBITEM_4_1_1_BEG = OSD_SUBITEM_3_2_1_END,
    OSD_SUBITEM_4_1_1_1_STATE = OSD_SUBITEM_4_1_1_BEG,
    OSD_SUBITEM_4_1_1_2_STATE,
    OSD_SUBITEM_4_1_1_3_STATE,
    OSD_SUBITEM_4_1_1_4_STATE,
    OSD_SUBITEM_4_1_1_5_STATE,
    OSD_SUBITEM_4_1_1_6_STATE,
    OSD_SUBITEM_4_1_1_7_STATE,
    OSD_SUBITEM_4_1_1_8_STATE,
    OSD_SUBITEM_4_1_1_9_STATE,
    OSD_SUBITEM_4_1_1_10_STATE,
    OSD_SUBITEM_4_1_1_11_STATE,
    OSD_SUBITEM_4_1_1_12_STATE,
    OSD_SUBITEM_4_1_1_13_STATE,
    OSD_SUBITEM_4_1_1_14_STATE,
    OSD_SUBITEM_4_1_1_15_STATE,
    OSD_SUBITEM_4_1_1_16_STATE,
    OSD_SUBITEM_4_1_1_17_STATE,
    OSD_SUBITEM_4_1_1_18_STATE,
    OSD_SUBITEM_4_1_1_END,


    // Display Time
    OSD_SUBITEM_4_1_2_BEG = OSD_SUBITEM_4_1_1_END,
    OSD_SUBITEM_4_1_2_1_STATE = OSD_SUBITEM_4_1_2_BEG,
    OSD_SUBITEM_4_1_2_2_STATE,
    OSD_SUBITEM_4_1_2_3_STATE,
    OSD_SUBITEM_4_1_2_4_STATE,
    OSD_SUBITEM_4_1_2_5_STATE,
    OSD_SUBITEM_4_1_2_6_STATE,
    OSD_SUBITEM_4_1_2_END,

    OSD_DIRECT_1_STATE = OSD_SUBITEM_4_1_2_END,
    OSD_DIRECT_2_STATE,
    OSD_DIRECT_3_STATE,
    OSD_AUTOTUNE_STATE,
    OSD_INFO_OUTOFLIMIT_STATE,
    OSD_INFO_OUTOFRANCE_STATE,
    OSD_INFO_NOSYNC_STATE,
    OSD_INFO_NOCABLE_STATE,
    OSD_INFO_NOTICE_STATE,
    OSD_INFO_SAVENOTICE_STATE,
    OSD_INFO_SOURCE_STATE,
    OSD_INFO_OSDLOCK_STATE,
    OSD_INFO_OSDUNLOCKKEY_STATE,
    OSD_INFO_NONPRESET_STATE,
    OSD_INFO_SMART_REMINDER_STATE,
    OSD_RES_NOTICE_STATE,
    OSD_INFO_RESETALL_NOTICE_STATE,//ULEric140410
    OSD_INFO_RESETCOLOR_NOTICE_STATE,//ULEric140410
    OSD_INFO_SENSEYE_DEMO_STATE,
    OSD_INFO_DCR_NOTICE_STATE,//ULEric140414
#if ENABLE_EYE_PROTECT == ON
    OSD_INFO_EYE_PROTECT_METER_STATE,
#endif
#if ENABLE_ECO_SENSOR == ON
    OSD_INFO_ECO_METER_STATE,
#endif    
    OSD_INFO_BURNING_STATE,
    OSD_OPT1_STATE,
    OSD_OPT2_STATE,
    OSD_FACT_STATE,
    OSD_FITM_STATE,
    OSD_SM_STATE,    //For BENQ Service Menu    
    OSD_DIRSRC_STATE,
    OSD_NON_STATE,
    NUM_OSD_STATUS
} OSDState;

typedef enum _OSDACTION_ {
    OSDATN_ENT_MAIN,
    OSDATN_EXT_MAIN,
    OSDATN_UP_MAIN,
    OSDATN_DN_MAIN,
    OSDATN_ENT_SUB1,
    OSDATN_EXT_SUB1,
    OSDATN_UP_SUB1,
    OSDATN_DN_SUB1,
    OSDATN_ENT_SUB2,
    OSDATN_EXT_SUB2,
    OSDATN_UP_SUB2,
    OSDATN_DN_SUB2,
    OSDATN_ENT_SUB3,
    OSDATN_EXT_SUB3,
    OSDATN_UP_SUB3,
    OSDATN_DN_SUB3,
    OSDATN_ENT_SUB4,
    OSDATN_EXT_SUB4,
    OSDATN_UP_SUB4,
    OSDATN_DN_SUB4,
    OSDATN_ENT_SUB5,
    OSDATN_EXT_SUB5,
    OSDATN_UP_SUB5,
    OSDATN_DN_SUB5,
    OSDATN_ENT_ITM11,
    OSDATN_EXT_ITM11,
    OSDATN_ENT_ITM12,
    OSDATN_EXT_ITM12,
    OSDATN_ENT_ITM13,
    OSDATN_EXT_ITM13,
    OSDATN_ENT_ITM21,
    OSDATN_EXT_ITM21,
    OSDATN_ENT_ITM22,
    OSDATN_EXT_ITM22,
    OSDATN_ENT_ITM23,
    OSDATN_EXT_ITM23,
    OSDATN_ENT_ITM24,
    OSDATN_EXT_ITM24,
    OSDATN_ENT_ITM31,
    OSDATN_EXT_ITM31,
    OSDATN_ENT_ITM32,
    OSDATN_EXT_ITM32,
    OSDATN_ENT_ITM33,
    OSDATN_EXT_ITM33,
    OSDATN_ENT_ITM34,
    OSDATN_EXT_ITM34,
    OSDATN_ENT_ITM41,
    OSDATN_EXT_ITM41,
    OSDATN_ENT_ITM42,
    OSDATN_EXT_ITM42,
    OSDATN_ENT_ITM43,
    OSDATN_EXT_ITM43,
    OSDATN_ENT_ITM44,
    OSDATN_EXT_ITM44,
    OSDATN_ENT_ITM51,
    OSDATN_EXT_ITM51,
    OSDATN_ENT_ITM52,
    OSDATN_EXT_ITM52,
    OSDATN_ENT_ITM53,
    OSDATN_EXT_ITM53,
    OSDATN_ENT_ITM54,
    OSDATN_EXT_ITM54,
    OSDATN_ENT_ITM55,
    OSDATN_EXT_ITM55,
    OSDATN_ENT_ITM56,
    OSDATN_EXT_ITM56,
    OSDATN_ENT_ITM57,
    OSDATN_EXT_ITM57,
    OSDATN_UP_ITM11,
    OSDATN_DN_ITM11,
    OSDATN_UP_ITM12,
    OSDATN_DN_ITM12,
    OSDATN_UP_ITM13,
    OSDATN_DN_ITM13,
    OSDATN_UP_ITM21,
    OSDATN_DN_ITM21,
    OSDATN_UP_ITM22,
    OSDATN_DN_ITM22,
    OSDATN_UP_ITM23,
    OSDATN_DN_ITM23,
    OSDATN_UP_ITM24,
    OSDATN_DN_ITM24,
    OSDATN_UP_ITM31,
    OSDATN_DN_ITM31,
    OSDATN_UP_ITM32,
    OSDATN_DN_ITM32,
    OSDATN_UP_ITM33,
    OSDATN_DN_ITM33,
    OSDATN_UP_ITM34,
    OSDATN_DN_ITM34,
    OSDATN_UP_ITM41,
    OSDATN_DN_ITM41,
    OSDATN_UP_ITM42,
    OSDATN_DN_ITM42,
    OSDATN_UP_ITM43,
    OSDATN_DN_ITM43,
    OSDATN_UP_ITM44,
    OSDATN_DN_ITM44,
    OSDATN_UP_ITM51,
    OSDATN_DN_ITM51,
    OSDATN_UP_ITM52,
    OSDATN_DN_ITM52,
    OSDATN_UP_ITM53,
    OSDATN_DN_ITM53,
    OSDATN_UP_ITM54,
    OSDATN_DN_ITM54,
    OSDATN_UP_ITM55,
    OSDATN_DN_ITM55,
    OSDATN_UP_ITM56,
    OSDATN_DN_ITM56,
    OSDATN_UP_ITM57,
    OSDATN_DN_ITM57,
    OSDATN_ENT_AUTO,
    OSDATN_ENT_DIR1,
    OSDATN_EXT_DIR1,
    OSDATN_UP_DIR1,
    OSDATN_DN_DIR1,
    OSDATN_ENT_DIR2,
    OSDATN_EXT_DIR2,
    OSDATN_UP_DIR2,
    OSDATN_DN_DIR2,
    OSDATN_ENT_DIR3,
    OSDATN_EXT_DIR3,
    OSDATN_UP_DIR3,
    OSDATN_DN_DIR3,
    OSDATN_ENT_OPT1,
    OSDATN_EXT_OPT1,
    OSDATN_UP_OPT1,
    OSDATN_DN_OPT1,
    OSDATN_ENT_OPT2,
    OSDATN_EXT_OPT2,
    OSDATN_UP_OPT2,
    OSDATN_DN_OPT2,

    OSDATN_ENT_NOSYNC,
    OSDATN_ENT_NOCBL,
    OSDATN_ENT_NML,
    OSDATN_ENT_OOR,
    OSDATN_NO_OSD,

    OSDATN_ENT_FACT,
    OSDATN_EXT_FACT,
    OSDATN_UP_FACT,
    OSDATN_DN_FACT,
    OSDATN_ENT_FITM,
    OSDATN_EXT_FITM,
    OSDATN_UP_FITM,
    OSDATN_DN_FITM,

    OSD_NON_ACTION,
    NUM_OSD_ACTIONS
} OSDAction;
#define CursorPos(a,b)   (b-a)
#if FORCE_NON_CIRCLE_ACTION == ON
#define NonCircleNextState(a,b,c) ((USHRT)c >= (b-1)? c: c+1)
#define NonCirclePrevState(a,b,c) ((USHRT)c <= a? c: c-1)
#endif // FORCE_NON_CIRCLE_ACTION

#define NextState(a,b,c) (((USHRT)c-a+1)%(b-a)+a)
#define PrevState(a,b,c) (((USHRT)c+b-2*a-1)%(b-a)+a)

#define NUM_MAIN_ITEMS  (OSD_MAIN_END-OSD_MAIN_BEG)
#define NUM_SUB1_ITEMS  (OSD_MAIN_1_END-OSD_MAIN_END)
#define NUM_SUB2_ITEMS  (OSD_MAIN_2_END-OSD_MAIN_1_END)
#define NUM_SUB3_ITEMS  (OSD_MAIN_3_END-OSD_MAIN_2_END)
#define NUM_SUB4_ITEMS  (OSD_MAIN_4_END-OSD_MAIN_3_END)
#define NUM_SUB5_ITEMS  (OSD_MAIN_5_END-OSD_MAIN_4_END)

//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
void OSDActionDispatcher(UCHAR event);
UCHAR OSDActionDemander(void);
void OSDConfigTimeout(USHRT timer);
void OSDCloseAll(void);
void OSDUpdateAutoTune(UCHAR pnt);

extern OSDState GetOSDState(void);
extern void SetOSDState(OSDState state);


//******************************************************************************
// S T A T I C   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
UCHAR GetMinValidOSDState(UCHAR OSD_Start_State, UCHAR OSD_End_State);
UCHAR GetMaxValidOSDState(UCHAR OSD_Start_State, UCHAR OSD_End_State);
UCHAR GetMinLayer3ValidOSDState(UCHAR OSD_Start_State, UCHAR OSD_End_State);
UCHAR GetMaxLayer3ValidOSDState(UCHAR OSD_Start_State, UCHAR OSD_End_State);
void OSDTimerRoutine(void);
extern void OSDEnterOSDUnLock(void);
void OSDUNLOCKKeyMenu(void);
UCHAR fnGetCustomerKeyItem();
void OSDEnterTopPageMenu(void);
void OSDUPTopPageMenu(void);
void OSDExitTopPageMenu(void);
void OSDExitLBLTopPageMenu(void);
void OSDExitAnimationTopPageMenu(void);
void OSDItm24ExitTopPageMenu(void);
void OSDItm25ExitTopPageMenu(void);
void OSDItm29ExitTopPageMenu(void);
void OSDItm31ExitTopPageMenu(void);
void OSDItm32ExitTopPageMenu(void);
void OSDItm33ExitTopPageMenu(void);
void OSDItm34ExitTopPageMenu(void);
void OSDItm35ExitTopPageMenu(void);
void OSDItm36ExitTopPageMenu(void);
void OSDItm37ExitTopPageMenu(void);
void OSDAudio2ExitTopPageMenu(void);
void OSDAudio3ExitTopPageMenu(void);
void OSDItm45ExitTopPageMenu(void);
void OSDItm46ExitTopPageMenu(void);
void OSDItm47ExitTopPageMenu(void);
void OSDItm49ExitTopPageMenu(void);
void OSDSubItm321ExitTopPageMenu(void);

void OSDEnterCustomer1Menu(void);
void OSDConfirmCustomerMenu(void);
void OSDExitCustomerMenu(void);
//void OSDExitCustomer1Menu(void);
void OSDEnterCustomer2Menu(void);
//void OSDExitCustomer2Menu(void);
void OSDEnterCustomer3Menu(void);
//void OSDExitCustomer3Menu(void);
void OSDEnterConfirInput(void);
void OSDEnterConfirAudioMute(void);//ULEric140402
void OSDEnterConfirDisplayMode(void);//ULEric140402
void OSDEnterConfirPictMode(void);//ULEric140402
void OSDConfirmCADMode(void);
void OSDEnterConfirmEyeProtect(void);
void OSDEnterConfirmEyeProtectMeter(void);
void OSDEnterConfirmECOSensor(void);
void OSDEnterConfirmECOSensorMeter(void);
void OSDEnterConfirSmartReminder(void);
void OSDShowCustomerMenu(UCHAR Key_Setting);
void OSDExitCustomerKeyMenu(UCHAR Key_Setting);
void OSDConfirmCustomerKeyMenu(UCHAR Key_Setting);
void OSDEnterConfirLBL(void);
void OSDEnterMainMenu(void);
void OSDExitMainMenu(void);
void OSDMainMenuUp(void);
void OSDMainMenuDown(void);
void OSDEnterSubMenu1(void);
void OSDExitSubMenu1(void);
void OSDSubMenuUp1(void);
void OSDSubMenuDown1(void);
void OSDEnterSubMenu2(void);
void OSDExitSubMenu2(void);
void OSDSubMenuUp2(void);
void OSDSubMenuDown2(void);
void OSDEnterSubMenu3(void);
void OSDExitSubMenu3(void);
void OSDSubMenuUp3(void);
void OSDSubMenuDown3(void);
void OSDEnterSubMenuAudio(void);
void OSDExitSubMenuAudio(void);
void OSDSubMenuUpAudio(void);
void OSDSubMenuDownAudio(void);
void OSDEnterSubMenu4(void);
void OSDExitSubMenu4(void);
void OSDSubMenuUp4(void);
void OSDSubMenuDown4(void);
void OSDEnterSubMenuErgo(void);
void OSDExitSubMenuErgo(void);
void OSDSubMenuUpErgo(void);
void OSDSubMenuDownErgo(void);

void OSDEnterSubMenuECO(void);
void OSDExitSubMenuECO(void);
void OSDSubMenuUpECO(void);
void OSDSubMenuDownECO(void);

/*
void OSDEnterSubMenu5(void);
void OSDExitSubMenu5(void);
void OSDSubMenuUp5(void);
void OSDSubMenuDown5(void);

void OSDEnterSubMenu6(void);
void OSDExitSubMenu6(void);
void OSDSubMenuUp6(void);
void OSDSubMenuDown6(void);

void OSDEnterSubMenu7(void);
void OSDExitSubMenu7(void);
void OSDSubMenuUp7(void);
void OSDSubMenuDown7(void);
*/


#if ENABLE_AUTO_POVIT_FUNC == ON  
void OSDEnterItm1Pivot(void);
void OSDExitItm1Pivot(void);
void OSDItm1PivotUp(void);
void OSDItm1PivotDown(void);
void OSDConfirmAutoPivot(void);
#endif
void OSDEnterItm12(void);
void OSDExitItm12(void);
void OSDItm12Up(void);
void OSDItm12Down(void);
#if ENABLE_OSD_ANALOG_FUNCTION == ON  
void OSDEnterItm11(void);
void OSDExitItm11(void);
void OSDEnterItm13(void);
void OSDExitItm13(void);
void OSDEnterItm14(void);
void OSDExitItm14(void);
void OSDEnterItm15(void);
void OSDExitItm15(void);
void OSDEnterItm16(void);
void OSDExitItm16(void);
#endif
void OSDEnterItm21(void);
void OSDExitItm21(void);
void OSDEnterItm22(void);
void OSDExitItm22(void);
void OSDEnterItm23(void);
void OSDExitItm23(void);

void OSDEnterItm24(void);
void OSDExitItm24(void);
void OSDItm24Up(void);
void OSDItm24Down(void);
void OSDConfirmItm24(void);

void OSDEnterItm25(void);
void OSDExitItm25(void);
void OSDItm25Up(void);
void OSDItm25Down(void);

void OSDEnterItm26(void);
void OSDExitItm26(void);

void OSDEnterItm27(void);
void OSDExitItm27(void);

void OSDEnterItm28(void);
void OSDExitItm28(void);
void OSDItm28Up(void);
void OSDItm28Down(void);
void OSDConfirmItm28(void);

void OSDEnterItm29(void);
void OSDExitItm29(void);
void OSDItm29Up(void);
void OSDItm29Down(void);
void OSDConfirmItm29(void);



void OSDEnterItm31(void);
void OSDExitItm31(void);
void OSDCheckItm31(void);
void OSDItm31Up(void);
void OSDItm31Down(void);


void OSDEnterItm32(void);
void OSDExitItm32(void);
void OSDConfirmItm32(void);

void OSDItm32Up(void);
void OSDItm32Down(void);

void OSDEnterItm33(void);
void OSDExitItm33(void);
void OSDItm33Up(void);
void OSDItm33Down(void);

void OSDEnterItm34(void);
void OSDExitItm34(void);
void OSDItm34Up(void);
void OSDItm34Down(void);
void OSDConfirmItm34(void);

void OSDEnterItm35(void);
void OSDExitItm35(void);
void OSDItm35Up(void);
void OSDItm35Down(void);
void OSDConfirmItm35(void);

void OSDEnterItmSmartScaling(void);
void OSDExitItmSmartScaling(void);

void OSDEnterItm36(void);
void OSDExitItm36(void);
void OSDItm36Up(void);
void OSDItm36Down(void);
void OSDConfirmItm36(void);

void OSDEnterItm37(void);
void OSDExitItm37(void);
void OSDItm37Up(void);
void OSDItm37Down(void);
void OSDConfirmItm37(void);

void OSDEnterItmAudio1(void);
void OSDExitItmAudio1(void);
void OSDItmAudio1Up(void);
void OSDItmAudio1Down(void);

void OSDEnterItmAudio2(void);
void OSDExitItmAudio2(void);
void OSDConfirmAudio2(void);//ULEric140402
void OSDItmAudio2Up(void);
void OSDItmAudio2Down(void);
void OSDConfirmAudio2(void);

void OSDEnterItmAudio3(void);
void OSDExitItmAudio3(void);
void OSDItmAudio3Up(void);
void OSDItmAudio3Down(void);
void OSDConfirmAudio3(void);


void OSDEnterItm41(void);
void OSDExitItm41(void);
void OSDItm41Up(void);
void OSDItm41Down(void);

void OSDEnterItm42(void);
void OSDExitItm42(void);
void OSDConfirmCustomeKey1(void);//ULEric140331
void OSDItm42Up(void);
void OSDItm42Down(void);

void OSDEnterItm43(void);
void OSDExitItm43(void);
void OSDConfirmCustomeKey2(void);//ULEric140331
void OSDItm43Up(void);
void OSDItm43Down(void);

void OSDEnterItm44(void);
void OSDExitItm44(void);
void OSDConfirmCustomeKey3(void);//ULEric140331
void OSDItm44Up(void);
void OSDItm44Down(void);

void OSDEnterItm45(void);
void OSDExitItm45(void);
void OSDCheckItm45(void);
void OSDItm45Up(void);
void OSDItm45Down(void);

void OSDEnterItm46(void);
void OSDExitItm46(void);
void OSDItm46Up(void);
void OSDItm46Down(void);
void OSDConfirmItm46(void);

void OSDEnterItm47(void);
void OSDExitItm47(void);
void OSDItm47Up(void);
void OSDItm47Down(void);
void OSDConfirmItm47(void);

void OSDEnterItm48(void);
void OSDExitItm48(void);
void OSDItm48Up(void);
void OSDItm48Down(void);
void OSDConfirmItm48(void);

void OSDEnterItm49(void);
void OSDExitItm49(void);
void OSDItm49Up(void);
void OSDItm49Down(void);
void OSDConfirmItm49(void);

void OSDEnterItm410(void);
void OSDExitItm410(void);

void OSDEnterItm411(void);
void OSDExitItm411(void);
void OSDItm411Up(void);
void OSDItm411Down(void);
void OSDConfirmItm411(void);


void OSDEnterItm412(void);
void OSDExitItm412(void);
void OSDConfirmItm412(void);
void OSDItm412Up(void);
void OSDItm412Down(void);

void OSDEnterItmEyeProtect(void);
void OSDExitItmEyeProtect(void);
void OSDItmEyeProtectUp(void);
void OSDItmEyeProtectDown(void);
void OSDComfirmItmEyeProtect(void);

void OSDEnterItmEyeProtectMeter(void);
void OSDExitItmEyeProtectMeter(void);
void OSDItmEyeProtectMeterUp(void);
void OSDItmEyeProtectMeterDown(void);
void OSDComfirmItmEyeProtectMeter(void);

void OSDEnterItmErgo1(void);
void OSDExitItmErgo1(void);
void OSDItmErgo1Up(void);
void OSDItmErgo1Down(void);
void OSDComfirmItmErgo1(void);

void OSDEnterItmErgo2(void);
void OSDExitItmErgo2(void);
void OSDItmErgo2Up(void);
void OSDItmErgo2Down(void);
void OSDComfirmItmErgo2(void);

void OSDEnterItmErgo3(void);
void OSDExitItmErgo3(void);
void OSDItmErgo3Up(void);
void OSDItmErgo3Down(void);
void OSDComfirmItmErgo3(void);

void OSDEnterItmECOSensor(void);
void OSDExitItmECOSensor(void);
void OSDItmECOSensorUp(void);
void OSDItmECOSensorDown(void);
void OSDComfirmItmECOSensor(void);

void OSDEnterItmECOSensorMeter(void);
void OSDExitItmECOSensorMeter(void);
void OSDItmECOSensorMeterUp(void);
void OSDItmECOSensorMeterDown(void);
void OSDComfirmItmECOSensorMeter(void);

void OSDEnterItmSensorRange(void);
void OSDExitItmSensorRange(void);
void OSDItmSensorRangeUp(void);
void OSDItmSensorRangeDown(void);
void OSDComfirmItmSensorRange(void);

// Color Temperature
void OSDEnterSubItm2541(void);
void OSDEnterSubItm2543to1(void);
void OSDExitSubItm2541(void);
void OSDSubItm2541Up(void);
void OSDSubItm2541Down(void);
void OSDEnterSubItm2542(void);
void OSDExitSubItm2542(void);
void OSDSubItm2542Up(void);
void OSDSubItm2542Down(void);
void OSDEnterSubItm2543(void);
void OSDExitSubItm2543(void);
void OSDSubItm2543Up(void);
void OSDSubItm2543Down(void);

void OSDEnterSubItm313(void);
void OSDExitSubItm313(void);
void OSDConfirmSubItm313(void);//ULEric140402
void OSDSubItm313Up(void);
void OSDSubItm313Down(void);
void OSDConfirmItm321(void);
void OSDExitSubItm321(void);
void OSDSubItm321Up(void);
void OSDSubItm321Down(void);

//Animation
void OSDEnterSubItmAnimation(void);
void OSDExitSubItmAnimation(void);
void OSDSubItmAnimationUp(void);
void OSDSubItmAnimationDown(void);
//void OSDConfirmSubItmAnimation(void);

// Multi-Language
void OSDEnterSubItm411(void);
void OSDEnterSubItm411X(void);

void OSDExitSubItm411(void);
void OSDSubItm411Up(void);
void OSDSubItm411Down(void);


// DisplayTime
void OSDEnterSubItm412(void);
void OSDConfirmSubItm412(void);//ULEric140401
void OSDExitSubItm412(void);
void OSDSubItm412Up(void);
void OSDSubItm412Down(void);

// OSD Lock
void OSDEnterSubItm413(void);

void OSDEnterFuncMenu(void);
void OSDExitFuncMenu(void);
void OSDFuncMenuUp(void);
void OSDFuncMenuDown(void);
void OSDEnterFunc1(void);
void OSDExitFunc1(void);
void OSDEnterFunc2(void);
void OSDExitFunc2(void);
void OSDEnterFunc3(void);
void OSDExitFunc3(void);
void OSDEnterFunc4(void);
void OSDExitFunc4(void);
void OSDEnterFunc5(void);
void OSDExitFunc5(void);
void OSDEnterFunc6(void);
void OSDExitFunc6(void);
void OSDEnterAuto(void);
void OSDEnterNormal(void);
void OSDEnterNoSync(void);
void OSDEnterNoCable(void);
void OSDEnterOOL(void);
void OSDEnterOOR(void);
void OSDEnterFactory(void);
void OSDUpFactory(void);
void OSDDnFactory(void);
void OSDEnterFItm(void);
void OSDExitFac(void);
void OSDExitFItm(void);
void OSDExitFItm2(void);
void OSDUpFItm(void);
void OSDDnFItm(void);
//For BENQ Service Menu
void OSDEnterServiceMenu(void);
void OSDUpServiceMenu(void);
void OSDDnServiceMenu(void);
void OSDAdjSMItm(void);
//For BENQ Service Menu
void OSDDummyFunction(void);
void OSDSelectInput(void);

void OSDExitSmartReminder(void);
void OSDErgoDurationUp(void);
void OSDErgoDurationDown(void);
void OSDErgoTimeUp(void);
void OSDErgoTimeDown(void);
#if ENABLE_ECO_SENSOR == ON
void OSDSensorRangeUp(void);
void OSDSensorRangeDown(void);
#endif
void OSD_SetSmartRemider(void);
void OSD_SetEyeProtect(void);
void OSD_SetEyeProtectMeter(void);
void OSD_SetErgoTime(void);
void OSD_SetErgoDuration(void);
void OSD_SetECOSensor(void);
void OSD_SetECOSensorMeter(void);
void OSD_SetECOSensorRange(void);
void OSDConfirmResetInfor(void);//ULEric140410
void OSDExitResetInfor(void);//ULEric140410
void OSDConfirmResetColorInfor(void);//ULEric140410
void OSDExitResetColorInfor(void);//ULEric140410
void OSDConfirmDCRInfor(void);//ULEric140414
void OSDExitDCRInfor(void);//ULEric140414
void OSDEnterExitKeyMenu(void);
void OSDEnterMenuKeyMenu(void);
void OSDConfirmItm25(void);
void OSDResetSmartRemiderTimer(BOOL force);


#endif //__OSD_CTRL_H__
