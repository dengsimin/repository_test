/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "Include.h"

//******************************************************************************
// G L O B A L   D E F I N I T I O N S
//******************************************************************************

//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************

//******************************************************************************
// S T A T I C   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
code void (*OSDKeyRoutine[OSD_NON_STATE][OSD_NONKEY_EVENT])(void) = {
      //MENU_EVENT          AUTO_EVENT              UP_EVENT                DOWN_EVENT              EXIT_EVENT
      {OSDEnterMenuKeyMenu, OSDEnterTopPageMenu,    OSDEnterTopPageMenu,    OSDEnterTopPageMenu,    OSDEnterExitKeyMenu},       //OSD_OFF_STATE,
      //{OSDEnterServiceMenu, NULL,                   NULL,                   NULL,                   NULL},                    //For BENQ Service Menu Test
      {OSDEnterMainMenu,    OSDEnterCustomer3Menu,  OSDEnterCustomer1Menu,  OSDEnterCustomer2Menu,  OSDExitTopPageMenu},        //OSD_TOPPAGE_STATE,
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDItm31ExitTopPageMenu},   //OSD_CUSTKEY_PICTUREMODE_1_STATE
#if	ENABLE_CAD_MODE == ON
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDItm31ExitTopPageMenu},   //OSD_CUSTKEY_PICTUREMODE_2_STATE,
#endif
#if	ENABLE_ANIMATION_MODE == ON
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDItm31ExitTopPageMenu},   //OSD_CUSTKEY_PICTUREMODE_3_STATE,
#endif
#if	ENABLE_PRESENTATION_MODE == ON
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDItm31ExitTopPageMenu},   //OSD_CUSTKEY_PICTUREMODE_4_STATE,
#endif
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDItm31ExitTopPageMenu},   //OSD_CUSTKEY_PICTUREMODE_5_STATE
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDItm31ExitTopPageMenu},   //OSD_CUSTKEY_PICTUREMODE_6_STATE
#if ENABLE_PICTURE_MODE_GAME == ON      
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDItm31ExitTopPageMenu},   //OSD_CUSTKEY_PICTUREMODE_7_STATE
#endif      
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDItm31ExitTopPageMenu},   //OSD_CUSTKEY_PICTUREMODE_8_STATE
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDItm31ExitTopPageMenu},   //OSD_CUSTKEY_PICTUREMODE_9_STATE
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDItm31ExitTopPageMenu},   //OSD_CUSTKEY_PICTUREMODE_10_STATE
#if ENABLE_PICTURE_MODE_MBOOK == ON
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDItm31ExitTopPageMenu},   //OSD_CUSTKEY_PICTUREMODE_11_STATE
#endif
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDItm31ExitTopPageMenu},   //OSD_CUSTKEY_PICTUREMODE_12_STATE
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDExitTopPageMenu},        //OSD_CUSTKEY_INPUT_1_STATE
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDExitTopPageMenu},        //OSD_CUSTKEY_INPUT_2_STATE
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDExitTopPageMenu},        //OSD_CUSTKEY_INPUT_3_STATE
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDExitTopPageMenu},        //OSD_CUSTKEY_INPUT_4_STATE
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDItm35ExitTopPageMenu},   //OSD_CUSTKEY_DISPLAYMODE_1_STATE
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDItm35ExitTopPageMenu},   //OSD_CUSTKEY_DISPLAYMODE_2_STATE
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDItm35ExitTopPageMenu},   //OSD_CUSTKEY_DISPLAYMODE_3_STATE
#if ENABLE_MORE_DISPLAY_MODE == ON    
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDItm35ExitTopPageMenu},   //OSD_CUSTKEY_DISPLAYMODE_4_STATE,
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDItm35ExitTopPageMenu},   //OSD_CUSTKEY_DISPLAYMODE_5_STATE,
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDItm35ExitTopPageMenu},   //OSD_CUSTKEY_DISPLAYMODE_6_STATE,    
#endif         
      //ULEric140331
      {OSDExitCustomerMenu, NULL,                   OSDCustVolumeUp,        OSDCustVolumeDown,      OSDExitTopPageMenu},        //OSD_CUSTKEY_VOLUME_STATE   
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDExitTopPageMenu},        //OSD_CUSTKEY_MUTE_1_STATE
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDExitTopPageMenu},        //OSD_CUSTKEY_MUTE_2_STATE 
#if ENABLE_EYE_PROTECT == ON
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDExitTopPageMenu},        //OSD_CUSTKEY_EYE_PROTECT_1_STATE,
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDExitTopPageMenu},        //OSD_CUSTKEY_EYE_PROTECT_2_STATE,
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDExitTopPageMenu},        //OSD_CUSTKEY_EYE_PROTECT_METER_1_STATE,
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDExitTopPageMenu},        //OSD_CUSTKEY_EYE_PROTECT_METER_2_STATE,
#endif
#if ENABLE_ECO_SENSOR== ON
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDExitTopPageMenu},        //OSD_CUSTKEY_ECO_SENSOR_1_STATE,
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDExitTopPageMenu},        //OSD_CUSTKEY_ECO_SENSOR_2_STATE,
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDExitTopPageMenu},        //OSD_CUSTKEY_ECO_SENSOR_METER_1_STATE,
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDExitTopPageMenu},        //OSD_CUSTKEY_ECO_SENSOR_METER_2_STATE,
#endif
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDExitTopPageMenu},        //OSD_CUSTKEY_SMARTREMINDER_1_STATE
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDExitTopPageMenu},        //OSD_CUSTKEY_SMARTREMINDER_2_STATE
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDExitLBLTopPageMenu},     //OSD_CUSTKEY_LOWBULELIGHTMODE_1_STATE
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDExitLBLTopPageMenu},     //OSD_CUSTKEY_LOWBULELIGHTMODE_2_STATE
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDExitLBLTopPageMenu},     //OSD_CUSTKEY_LOWBULELIGHTMODE_3_STATE
      {OSDExitCustomerMenu, OSDConfirmCustomerMenu, OSDCustomerMenuUp,      OSDCustomerMenuDown,    OSDExitLBLTopPageMenu},     //OSD_CUSTKEY_LOWBULELIGHTMODE_4_STATE
#if ENABLE_CAD_MODE == ON
      {OSDExitCustomerMenu, OSDConfirmCADMode, NULL,      NULL,    OSDExitTopPageMenu},        //OSD_CUSTKEY_CAD_STATE
#endif
#if ENABLE_ANIMATION_MODE == ON
      {OSDExitCustomerMenu,                   NULL, OSDCusAnimationUp,      OSDCusAnimationDown,    OSDExitTopPageMenu},        //OSD_CUSTKEY_ANIMATION_STATE
#endif
      {OSDExitCustomerMenu, NULL,                   OSDCustContrastUp,      OSDCustContrastDown,    OSDExitTopPageMenu},        //OSD_CUSTKEY_CONTRAST_STATE
      {OSDExitCustomerMenu, NULL,                   OSDCustBrightnessUp,    OSDCustBrightnessDown,  OSDExitTopPageMenu},        //OSD_CUSTKEY_BRIGHTNESS_STATE
      {OSDExitMainMenu,     OSDEnterSubMenu1,       OSDMainMenuUp,          OSDMainMenuDown,        OSDExitTopPageMenu},        //OSD_MAIN_1_STATE,    //Justin 140321    
      {OSDExitMainMenu,     OSDEnterSubMenu2,       OSDMainMenuUp,          OSDMainMenuDown,        OSDExitTopPageMenu},        //OSD_MAIN_2_STATE,
      {OSDExitMainMenu,     OSDEnterSubMenu3,       OSDMainMenuUp,          OSDMainMenuDown,        OSDExitTopPageMenu},        //OSD_MAIN_3_STATE,
      {OSDExitMainMenu,     OSDEnterSubMenuAudio,   OSDMainMenuUp,          OSDMainMenuDown,        OSDExitTopPageMenu},        //OSD_MAIN_Audio_STATE,
      {OSDExitMainMenu,     OSDEnterSubMenu4,       OSDMainMenuUp,          OSDMainMenuDown,        OSDExitTopPageMenu},        //OSD_MAIN_4_STATE,
      {OSDExitMainMenu,     OSDEnterSubMenuErgo,    OSDMainMenuUp,          OSDMainMenuDown,        OSDExitTopPageMenu},        //OSD_MAIN_ERGO_STATE, 
#if ENABLE_ECO_SENSOR == ON
      {OSDExitMainMenu,     OSDEnterSubMenuECO,    OSDMainMenuUp,          OSDMainMenuDown,        OSDExitTopPageMenu},        //OSD_MAIN_ECO_STATE,       
#endif      
      {OSDExitSubMenu1,     OSDEnterItm11,          OSDSubMenuUp1,          OSDSubMenuDown1,        OSDExitTopPageMenu},        //OSD_MAIN_1_1_STATE,         
#if ENABLE_AUTO_POVIT_FUNC == ON      
      {OSDExitSubMenu1,     OSDEnterItm1Pivot,      OSDSubMenuUp1,          OSDSubMenuDown1,        OSDExitTopPageMenu},        //OSD_MAIN_1_1_STATE,
#endif
      {OSDExitSubMenu1,     OSDEnterItm12,          OSDSubMenuUp1,          OSDSubMenuDown1,        OSDExitTopPageMenu},        //OSD_MAIN_1_2_STATE,
      {OSDExitSubMenu1,     OSDEnterItm13,          OSDSubMenuUp1,          OSDSubMenuDown1,        OSDExitTopPageMenu},        //OSD_MAIN_1_3_STATE,
      {OSDExitSubMenu1,     OSDEnterItm14,          OSDSubMenuUp1,          OSDSubMenuDown1,        OSDExitTopPageMenu},        //OSD_MAIN_1_4_STATE,
      {OSDExitSubMenu1,     OSDEnterItm15,          OSDSubMenuUp1,          OSDSubMenuDown1,        OSDExitTopPageMenu},        //OSD_MAIN_1_5_STATE,        
      {OSDExitSubMenu1,     OSDEnterItm16,          OSDSubMenuUp1,          OSDSubMenuDown1,        OSDExitTopPageMenu},        //OSD_MAIN_1_6_STATE,      
      {OSDExitSubMenu2,     OSDEnterItm21,          OSDSubMenuUp2,          OSDSubMenuDown2,        OSDExitTopPageMenu},        //OSD_MAIN_2_1_STATE,
      {OSDExitSubMenu2,     OSDEnterItm22,          OSDSubMenuUp2,          OSDSubMenuDown2,        OSDExitTopPageMenu},        //OSD_MAIN_2_2_STATE,
      {OSDExitSubMenu2,     OSDEnterItm23,          OSDSubMenuUp2,          OSDSubMenuDown2,        OSDExitTopPageMenu},        //OSD_MAIN_2_3_STATE,
      {OSDExitSubMenu2,     OSDEnterItm24,          OSDSubMenuUp2,          OSDSubMenuDown2,        OSDExitTopPageMenu},        //OSD_MAIN_2_4_STATE,
      {OSDExitSubMenu2,     OSDEnterItm25,          OSDSubMenuUp2,          OSDSubMenuDown2,        OSDExitTopPageMenu},        //OSD_MAIN_2_5_STATE,
      {OSDExitSubMenu2,     OSDEnterItm26,          OSDSubMenuUp2,          OSDSubMenuDown2,        OSDExitTopPageMenu},        //OSD_MAIN_2_6_STATE,
      {OSDExitSubMenu2,     OSDEnterItm27,          OSDSubMenuUp2,          OSDSubMenuDown2,        OSDExitTopPageMenu},        //OSD_MAIN_2_7_STATE,
      {OSDExitSubMenu2,     OSDEnterItm28,          OSDSubMenuUp2,          OSDSubMenuDown2,        OSDExitTopPageMenu},        //OSD_MAIN_2_8_STATE,
      {OSDExitSubMenu2,     OSDEnterItm29,          OSDSubMenuUp2,          OSDSubMenuDown2,        OSDExitTopPageMenu},        //OSD_MAIN_2_9_STATE,    
      {OSDExitSubMenu3,     OSDEnterItm31,          OSDSubMenuUp3,          OSDSubMenuDown3,        OSDExitTopPageMenu},        //OSD_MAIN_3_1_STATE,    
      {OSDExitSubMenu3,     OSDEnterItm32,          OSDSubMenuUp3,          OSDSubMenuDown3,        OSDExitTopPageMenu},        //OSD_MAIN_3_2_STATE,
      {OSDExitSubMenu3,     OSDEnterItm33,          OSDSubMenuUp3,          OSDSubMenuDown3,        OSDExitTopPageMenu},        //OSD_MAIN_3_3_STATE,
      {OSDExitSubMenu3,     OSDEnterItm34,          OSDSubMenuUp3,          OSDSubMenuDown3,        OSDExitTopPageMenu},        //OSD_MAIN_3_4_STATE,
      {OSDExitSubMenu3,     OSDEnterItm35,          OSDSubMenuUp3,          OSDSubMenuDown3,        OSDExitTopPageMenu},        //OSD_MAIN_3_5_STATE,
#if ENABLE_SMART_SCALING == ON
      {OSDExitSubMenu3,     OSDEnterItmSmartScaling,    OSDSubMenuUp3,      OSDSubMenuDown3,        OSDExitTopPageMenu},        //OSD_MAIN_3_SMART_SCALING_STATE,
#endif
      {OSDExitSubMenu3,     OSDEnterItm36,          OSDSubMenuUp3,          OSDSubMenuDown3,        OSDExitTopPageMenu},        //OSD_MAIN_3_6_STATE,
      {OSDExitSubMenu3,     OSDEnterItm37,          OSDSubMenuUp3,          OSDSubMenuDown3,        OSDExitTopPageMenu},        //OSD_MAIN_3_7_STATE,
      {OSDExitSubMenuAudio, OSDEnterItmAudio1,      OSDSubMenuUpAudio,      OSDSubMenuDownAudio,    OSDExitTopPageMenu},        //OSD_MAIN_Audio_1_STATE
      {OSDExitSubMenuAudio, OSDEnterItmAudio2,      OSDSubMenuUpAudio,      OSDSubMenuDownAudio,    OSDExitTopPageMenu},        //OSD_MAIN_Audio_2_STATE
      {OSDExitSubMenuAudio, OSDEnterItmAudio3,      OSDSubMenuUpAudio,      OSDSubMenuDownAudio,    OSDExitTopPageMenu},        //OSD_MAIN_Audio_3_STATE
      {OSDExitSubMenu4,     OSDEnterItm41,          OSDSubMenuUp4,          OSDSubMenuDown4,        OSDExitTopPageMenu},        //OSD_MAIN_4_1_STATE,
      {OSDExitSubMenu4,     OSDEnterItm42,          OSDSubMenuUp4,          OSDSubMenuDown4,        OSDExitTopPageMenu},        //OSD_MAIN_4_2_STATE,
      {OSDExitSubMenu4,     OSDEnterItm43,          OSDSubMenuUp4,          OSDSubMenuDown4,        OSDExitTopPageMenu},        //OSD_MAIN_4_3_STATE,
      {OSDExitSubMenu4,     OSDEnterItm44,          OSDSubMenuUp4,          OSDSubMenuDown4,        OSDExitTopPageMenu},        //OSD_MAIN_4_4_STATE,
      {OSDExitSubMenu4,     OSDEnterItm45,          OSDSubMenuUp4,          OSDSubMenuDown4,        OSDExitTopPageMenu},        //OSD_MAIN_4_5_STATE,
      {OSDExitSubMenu4,     OSDEnterItm46,          OSDSubMenuUp4,          OSDSubMenuDown4,        OSDExitTopPageMenu},        //OSD_MAIN_4_6_STATE,
      {OSDExitSubMenu4,     OSDEnterItm47,          OSDSubMenuUp4,          OSDSubMenuDown4,        OSDExitTopPageMenu},        //OSD_MAIN_4_7_STATE,
      {OSDExitSubMenu4,     OSDEnterItm48,          OSDSubMenuUp4,          OSDSubMenuDown4,        OSDExitTopPageMenu},        //OSD_MAIN_4_8_STATE,
      {OSDExitSubMenu4,     OSDEnterItm49,          OSDSubMenuUp4,          OSDSubMenuDown4,        OSDExitTopPageMenu},        //OSD_MAIN_4_9_STATE,
      {OSDExitSubMenu4,     NULL,                   OSDSubMenuUp4,          OSDSubMenuDown4,        OSDExitTopPageMenu},        //OSD_MAIN_4_10_STATE,
      {OSDExitSubMenu4,     OSDEnterItm411,         OSDSubMenuUp4,          OSDSubMenuDown4,        OSDExitTopPageMenu},        //OSD_MAIN_4_11_STATE,
      {OSDExitSubMenu4,     OSDEnterItm412,         OSDSubMenuUp4,          OSDSubMenuDown4,        OSDExitTopPageMenu},        //OSD_MAIN_4_12_STATE,
#if ENABLE_EYE_PROTECT == ON
      {OSDExitSubMenuErgo,  OSDEnterItmEyeProtect,          OSDSubMenuUpErgo,       OSDSubMenuDownErgo,     OSDExitTopPageMenu},        //OSD_MAIN_EYE_PROTECT_STATE
      {OSDExitSubMenuErgo,  OSDEnterItmEyeProtectMeter,     OSDSubMenuUpErgo,       OSDSubMenuDownErgo,     OSDExitTopPageMenu},        //OSD_MAIN_EYE_PROTECT_METER_STATE
#endif
      {OSDExitSubMenuErgo,  OSDEnterItmErgo1,       OSDSubMenuUpErgo,       OSDSubMenuDownErgo,     OSDExitTopPageMenu},        //OSD_MAIN_ERGO_1_STATE
      {OSDExitSubMenuErgo,  OSDEnterItmErgo2,       OSDSubMenuUpErgo,       OSDSubMenuDownErgo,     OSDExitTopPageMenu},        //OSD_MAIN_ERGO_2_STATE
      {OSDExitSubMenuErgo,  OSDEnterItmErgo3,       OSDSubMenuUpErgo,       OSDSubMenuDownErgo,     OSDExitTopPageMenu},        //OSD_MAIN_ERGO_3_STATE
#if ENABLE_ECO_SENSOR == ON
      {OSDExitSubMenuECO,   OSDEnterItmECOSensor,           OSDSubMenuUpECO,       OSDSubMenuDownECO,     OSDExitTopPageMenu},        //OSD_MAIN_ECO_SENSOR_STATE
      {OSDExitSubMenuECO,   OSDEnterItmECOSensorMeter,      OSDSubMenuUpECO,       OSDSubMenuDownECO,     OSDExitTopPageMenu},        //OSD_MAIN_ECO_SENSOR_METER_STATE
      {OSDExitSubMenuECO,   OSDEnterItmSensorRange,         OSDSubMenuUpECO,       OSDSubMenuDownECO,     OSDExitTopPageMenu},        //OSD_MAIN_ECO_SENSOR_RANGE_STATE
#endif
      {OSDExitItm11,        OSDExitItm11,           NULL,                   NULL,                   OSDExitTopPageMenu},        //OSD_ITEM_1_1_STATE,
#if ENABLE_AUTO_POVIT_FUNC == ON      
      {OSDExitItm1Pivot,    OSDConfirmAutoPivot,       OSDItm1PivotUp,         OSDItm1PivotDown,       OSDExitTopPageMenu},        //OSD_ITEM_PIVOT_1_STATE,
      {OSDExitItm1Pivot,    OSDConfirmAutoPivot,       OSDItm1PivotUp,         OSDItm1PivotDown,       OSDExitTopPageMenu},        //OSD_ITEM_PIVOT_2_STATE,
#endif
      {OSDExitItm12,        OSDSelectInput,         OSDItm12Up,             OSDItm12Down,           OSDExitTopPageMenu},        //OSD_ITEM_1_2_1_STATE,
      {OSDExitItm12,        OSDSelectInput,         OSDItm12Up,             OSDItm12Down,           OSDExitTopPageMenu},        //OSD_ITEM_1_2_2_STATE,
      {OSDExitItm12,        OSDSelectInput,         OSDItm12Up,             OSDItm12Down,           OSDExitTopPageMenu},        //OSD_ITEM_1_2_3_STATE,
      {OSDExitItm12,        OSDSelectInput,         OSDItm12Up,             OSDItm12Down,           OSDExitTopPageMenu},        //OSD_ITEM_1_2_4_STATE,
      {OSDExitItm13,        NULL,                   OSDUpItm13,             OSDDnItm13,             OSDExitTopPageMenu},        //OSD_ITEM_1_3_STATE,
      {OSDExitItm14,        NULL,                   OSDUpItm14,             OSDDnItm14,             OSDExitTopPageMenu},        //OSD_ITEM_1_4_STATE,
      {OSDExitItm15,        NULL,                   OSDUpItm15,             OSDDnItm15,             OSDExitTopPageMenu},        //OSD_ITEM_1_5_STATE,
      {OSDExitItm16,        NULL,                   OSDUpItm16,             OSDDnItm16,             OSDExitTopPageMenu},        //OSD_ITEM_1_6_STATE,
      {OSDExitItm21,        NULL,                   OSDUpItm21,             OSDDnItm21,             OSDExitTopPageMenu},        //OSD_ITEM_2_1_STATE,
      {OSDExitItm22,        NULL,                   OSDUpItm22,             OSDDnItm22,             OSDExitTopPageMenu},        //OSD_ITEM_2_2_STATE,
      {OSDExitItm23,        NULL,                   OSDUpItm23,             OSDDnItm23,             OSDExitTopPageMenu},        //OSD_ITEM_2_3_STATE,
      {OSDExitItm24,        OSDConfirmItm24,        OSDItm24Up,             OSDItm24Down,           OSDItm24ExitTopPageMenu},   //OSD_ITEM_2_4_1_STATE,
      {OSDExitItm24,        OSDConfirmItm24,        OSDItm24Up,             OSDItm24Down,           OSDItm24ExitTopPageMenu},   //OSD_ITEM_2_4_2_STATE,
      {OSDExitItm24,        OSDConfirmItm24,        OSDItm24Up,             OSDItm24Down,           OSDItm24ExitTopPageMenu},   //OSD_ITEM_2_4_3_STATE,
      {OSDExitItm24,        OSDConfirmItm24,        OSDItm24Up,             OSDItm24Down,           OSDItm24ExitTopPageMenu},   //OSD_ITEM_2_4_4_STATE,
      {OSDExitItm24,        OSDConfirmItm24,        OSDItm24Up,             OSDItm24Down,           OSDItm24ExitTopPageMenu},   //OSD_ITEM_2_4_5_STATE,
      {OSDExitItm25,        OSDConfirmItm25,        OSDItm25Up,             OSDItm25Down,           OSDItm25ExitTopPageMenu},   //OSD_ITEM_2_5_1_STATE,
      {OSDExitItm25,        OSDConfirmItm25,        OSDItm25Up,             OSDItm25Down,           OSDItm25ExitTopPageMenu},   //OSD_ITEM_2_5_2_STATE,
      {OSDExitItm25,        OSDConfirmItm25,        OSDItm25Up,             OSDItm25Down,           OSDItm25ExitTopPageMenu},   //OSD_ITEM_2_5_3_STATE,
      {OSDExitItm25,        OSDEnterSubItm2541,     OSDItm25Up,             OSDItm25Down,           OSDItm25ExitTopPageMenu},   //OSD_ITEM_2_5_4_STATE,
      {OSDExitItm26,        NULL,                   OSDUpItm26,             OSDDnItm26,             OSDExitTopPageMenu},        //OSD_ITEM_2_6_STATE,
      {OSDExitItm27,        NULL,                   OSDUpItm27,             OSDDnItm27,             OSDExitTopPageMenu},        //OSD_ITEM_2_7_STATE,
      {OSDExitItm28,        OSDConfirmItm28,        OSDItm28Up,             OSDItm28Down,           OSDExitTopPageMenu},        //OSD_ITEM_2_8_1_STATE,
      {OSDExitItm28,        OSDExitItm28,           OSDItm28Up,             OSDItm28Down,           OSDExitTopPageMenu},        //OSD_ITEM_2_8_2_STATE,
      {OSDExitItm29,        OSDConfirmItm29,        OSDItm29Up,             OSDItm29Down,           OSDItm29ExitTopPageMenu},   //OSD_ITEM_2_9_1_STATE,
      {OSDExitItm29,        OSDConfirmItm29,        OSDItm29Up,             OSDItm29Down,           OSDItm29ExitTopPageMenu},   //OSD_ITEM_2_9_2_STATE,
      {OSDExitItm29,        OSDConfirmItm29,        OSDItm29Up,             OSDItm29Down,           OSDItm29ExitTopPageMenu},   //OSD_ITEM_2_9_3_STATE,
      
      {OSDExitItm31,        OSDCheckItm31,          OSDItm31Up,             OSDItm31Down,           OSDItm31ExitTopPageMenu},   //OSD_ITEM_3_1_1_STATE,
#if	ENABLE_CAD_MODE == ON
      {OSDExitItm31,        OSDCheckItm31,          OSDItm31Up,             OSDItm31Down,           OSDItm31ExitTopPageMenu},   //OSD_ITEM_3_1_2_STATE,
#endif
#if	ENABLE_ANIMATION_MODE == ON
      {OSDExitItm31,       OSDEnterSubItmAnimation, OSDItm31Up,             OSDItm31Down,           OSDItm31ExitTopPageMenu},   //OSD_ITEM_3_1_3_STATE,
#endif
#if	ENABLE_PRESENTATION_MODE == ON
      {OSDExitItm31,        OSDCheckItm31,          OSDItm31Up,             OSDItm31Down,           OSDItm31ExitTopPageMenu},   //OSD_ITEM_3_1_4_STATE,
#endif
      {OSDExitItm31,        OSDCheckItm31,          OSDItm31Up,             OSDItm31Down,           OSDItm31ExitTopPageMenu},   //OSD_ITEM_3_1_5_STATE,
      {OSDExitItm31,        OSDEnterSubItmLBL,      OSDItm31Up,             OSDItm31Down,           OSDItm31ExitTopPageMenu},   //OSD_ITEM_3_1_6_STATE, //origin 313
      {OSDExitItm31,        OSDCheckItm31,          OSDItm31Up,             OSDItm31Down,           OSDItm31ExitTopPageMenu},   //OSD_ITEM_3_1_7_STATE,
#if ENABLE_PICTURE_MODE_GAME == ON      
      {OSDExitItm31,        OSDCheckItm31,          OSDItm31Up,             OSDItm31Down,           OSDItm31ExitTopPageMenu},   //OSD_ITEM_3_1_8_STATE,
#endif      
      {OSDExitItm31,        OSDCheckItm31,          OSDItm31Up,             OSDItm31Down,           OSDItm31ExitTopPageMenu},   //OSD_ITEM_3_1_9_STATE,
      {OSDExitItm31,        OSDCheckItm31,          OSDItm31Up,             OSDItm31Down,           OSDItm31ExitTopPageMenu},   //OSD_ITEM_3_1_10_STATE,
#if ENABLE_PICTURE_MODE_MBOOK == ON        
      {OSDExitItm31,        OSDCheckItm31,          OSDItm31Up,             OSDItm31Down,           OSDItm31ExitTopPageMenu},   //OSD_ITEM_3_1_11_STATE,
#endif      
      {OSDExitItm31,        OSDCheckItm31,          OSDItm31Up,             OSDItm31Down,           OSDItm31ExitTopPageMenu},   //OSD_ITEM_3_1_12_STATE,
      {OSDExitItm32,        OSDConfirmItm32,        OSDItm32Up,             OSDItm32Down,           OSDItm32ExitTopPageMenu},   //OSD_ITEM_3_2_1_STATE,
      {OSDExitItm32,        OSDConfirmItm32,        OSDItm32Up,             OSDItm32Down,           OSDItm32ExitTopPageMenu},   //OSD_ITEM_3_2_2_STATE,
      {OSDExitItm33,        NULL,                   OSDUpItmDynContrast,    OSDDnItmDynContrast,    OSDExitTopPageMenu},        //OSD_ITEM_3_3_STATE,
      {OSDExitItm34,        OSDConfirmItm34,        OSDItm34Up,             OSDItm34Down,           OSDItm34ExitTopPageMenu},   //OSD_ITEM_3_4_1_STATE,
      {OSDExitItm34,        OSDConfirmItm34,        OSDItm34Up,             OSDItm34Down,           OSDItm34ExitTopPageMenu},   //OSD_ITEM_3_4_2_STATE,
      {OSDExitItm35,        OSDConfirmItm35,        OSDItm35Up,             OSDItm35Down,           OSDItm35ExitTopPageMenu},   //OSD_ITEM_3_5_1_STATE,
      {OSDExitItm35,        OSDConfirmItm35,        OSDItm35Up,             OSDItm35Down,           OSDItm35ExitTopPageMenu},   //OSD_ITEM_3_5_2_STATE,
      {OSDExitItm35,        OSDConfirmItm35,        OSDItm35Up,             OSDItm35Down,           OSDItm35ExitTopPageMenu},   //OSD_ITEM_3_5_3_STATE,
#if ENABLE_MORE_DISPLAY_MODE == ON
      {OSDExitItm35,        OSDConfirmItm35,        OSDItm35Up,             OSDItm35Down,           OSDItm35ExitTopPageMenu},   ////OSD_ITEM_3_5_4_STATE,
      {OSDExitItm35,        OSDConfirmItm35,        OSDItm35Up,             OSDItm35Down,           OSDItm35ExitTopPageMenu},   ////OSD_ITEM_3_5_5_STATE,
      {OSDExitItm35,        OSDConfirmItm35,        OSDItm35Up,             OSDItm35Down,           OSDItm35ExitTopPageMenu},   ////OSD_ITEM_3_5_6_STATE,
#endif
#if ENABLE_SMART_SCALING == ON
      {OSDExitItmSmartScaling,         NULL,        OSDSmartScalingUp,      OSDSmartScalingDown,    OSDExitTopPageMenu},        //OSD_ITEM_3_SMART_SCALING_STATE
#endif
      {OSDExitItm36,        OSDConfirmItm36,        OSDItm36Up,             OSDItm36Down,           OSDItm36ExitTopPageMenu},   //OSD_ITEM_3_6_1_STATE,
      {OSDExitItm36,        OSDConfirmItm36,        OSDItm36Up,             OSDItm36Down,           OSDItm36ExitTopPageMenu},   //OSD_ITEM_3_6_2_STATE,
      {OSDExitItm37,        OSDConfirmItm37,        OSDItm37Up,             OSDItm37Down,           OSDItm37ExitTopPageMenu},   //OSD_ITEM_3_7_1_STATE
      {OSDExitItm37,        OSDConfirmItm37,        OSDItm37Up,             OSDItm37Down,           OSDItm37ExitTopPageMenu},   //OSD_ITEM_3_7_2_STATE
      {OSDExitItmAudio1,    NULL,                   OSDUpItmAudio1,         OSDDnItmAudio1,         OSDExitTopPageMenu},        //OSD_ITEM_Audio_1_1_STATE
      {OSDExitItmAudio2,    OSDConfirmAudio2,       OSDItmAudio2Up,         OSDItmAudio2Down,       OSDAudio2ExitTopPageMenu},  //OSD_ITEM_Audio_2_1_STATE
      {OSDExitItmAudio2,    OSDConfirmAudio2,       OSDItmAudio2Up,         OSDItmAudio2Down,       OSDAudio2ExitTopPageMenu},  //OSD_ITEM_Audio_2_2_STATE
      {OSDExitItmAudio3,    OSDConfirmAudio3,       OSDItmAudio3Up,         OSDItmAudio3Down,       OSDAudio3ExitTopPageMenu},  //OSD_ITEM_Audio_3_1_STATE
      {OSDExitItmAudio3,    OSDConfirmAudio3,       OSDItmAudio3Up,         OSDItmAudio3Down,       OSDAudio3ExitTopPageMenu},  //OSD_ITEM_Audio_3_2_STATE
      {OSDExitItmAudio3,    OSDConfirmAudio3,       OSDItmAudio3Up,         OSDItmAudio3Down,       OSDAudio3ExitTopPageMenu},  //OSD_ITEM_Audio_3_3_STATE      
      {OSDExitItmAudio3,    OSDConfirmAudio3,       OSDItmAudio3Up,         OSDItmAudio3Down,       OSDAudio3ExitTopPageMenu},  //OSD_ITEM_Audio_3_4_STATE      
      {OSDExitItm41,        OSDEnterSubItm411,      OSDItm41Up,             OSDItm41Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_1_1_STATE,
      {OSDExitItm41,        OSDEnterSubItm412,      OSDItm41Up,             OSDItm41Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_1_2_STATE,
      {OSDExitItm41,        OSDEnterSubItm413,      OSDItm41Up,             OSDItm41Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_1_3_STATE,
      {OSDExitItm42,        OSDConfirmItm42,        OSDItm42Up,             OSDItm42Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_2_1_STATE,
      {OSDExitItm42,        OSDConfirmItm42,        OSDItm42Up,             OSDItm42Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_2_2_STATE,
      {OSDExitItm42,        OSDConfirmItm42,        OSDItm42Up,             OSDItm42Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_2_3_STATE,
      {OSDExitItm42,        OSDConfirmItm42,        OSDItm42Up,             OSDItm42Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_2_4_STATE,
      {OSDExitItm42,        OSDConfirmItm42,        OSDItm42Up,             OSDItm42Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_2_5_STATE,
      {OSDExitItm42,        OSDConfirmItm42,        OSDItm42Up,             OSDItm42Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_2_6_STATE,
      {OSDExitItm42,        OSDConfirmItm42,        OSDItm42Up,             OSDItm42Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_2_7_STATE,
      {OSDExitItm42,        OSDConfirmItm42,        OSDItm42Up,             OSDItm42Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_2_8_STATE,
      {OSDExitItm42,        OSDConfirmItm42,        OSDItm42Up,             OSDItm42Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_2_9_STATE,
      {OSDExitItm42,        OSDConfirmItm42,        OSDItm42Up,             OSDItm42Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_2_10_STATE,
      {OSDExitItm42,        OSDConfirmItm42,        OSDItm42Up,             OSDItm42Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_2_11_STATE,
#if ENABLE_EYE_PROTECT == ON
      {OSDExitItm42,        OSDConfirmItm42,        OSDItm42Up,             OSDItm42Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_2_12_STATE,
      {OSDExitItm42,        OSDConfirmItm42,        OSDItm42Up,             OSDItm42Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_2_13_STATE,
#endif
#if ENABLE_ECO_SENSOR== ON
      {OSDExitItm42,        OSDConfirmItm42,        OSDItm42Up,             OSDItm42Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_2_14_STATE,
      {OSDExitItm42,        OSDConfirmItm42,        OSDItm42Up,             OSDItm42Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_2_15_STATE,
#endif
#if ENABLE_ANIMATION_MODE == ON      
      {OSDExitItm42,        OSDConfirmItm42,        OSDItm42Up,             OSDItm42Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_2_16_STATE,
#endif    
      {OSDExitItm43,        OSDConfirmItm43,        OSDItm43Up,             OSDItm43Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_3_1_STATE,
      {OSDExitItm43,        OSDConfirmItm43,        OSDItm43Up,             OSDItm43Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_3_2_STATE,
      {OSDExitItm43,        OSDConfirmItm43,        OSDItm43Up,             OSDItm43Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_3_3_STATE,
      {OSDExitItm43,        OSDConfirmItm43,        OSDItm43Up,             OSDItm43Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_3_4_STATE,
      {OSDExitItm43,        OSDConfirmItm43,        OSDItm43Up,             OSDItm43Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_3_5_STATE,
      {OSDExitItm43,        OSDConfirmItm43,        OSDItm43Up,             OSDItm43Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_3_6_STATE,
      {OSDExitItm43,        OSDConfirmItm43,        OSDItm43Up,             OSDItm43Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_3_7_STATE,
      {OSDExitItm43,        OSDConfirmItm43,        OSDItm43Up,             OSDItm43Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_3_8_STATE,
      {OSDExitItm43,        OSDConfirmItm43,        OSDItm43Up,             OSDItm43Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_3_9_STATE,
      {OSDExitItm43,        OSDConfirmItm43,        OSDItm43Up,             OSDItm43Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_3_10_STATE,
      {OSDExitItm43,        OSDConfirmItm43,        OSDItm43Up,             OSDItm43Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_3_11_STATE,      
#if ENABLE_EYE_PROTECT == ON
      {OSDExitItm43,        OSDConfirmItm43,        OSDItm43Up,             OSDItm43Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_3_12_STATE,
      {OSDExitItm43,        OSDConfirmItm43,        OSDItm43Up,             OSDItm43Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_3_13_STATE,
#endif
#if ENABLE_ECO_SENSOR== ON
      {OSDExitItm43,        OSDConfirmItm43,        OSDItm43Up,             OSDItm43Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_3_14_STATE,
      {OSDExitItm43,        OSDConfirmItm43,        OSDItm43Up,             OSDItm43Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_3_15_STATE,
#endif
#if ENABLE_ANIMATION_MODE == ON
      {OSDExitItm43,        OSDConfirmItm43,        OSDItm43Up,             OSDItm43Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_3_16_STATE,
#endif
      {OSDExitItm44,        OSDConfirmItm44,        OSDItm44Up,             OSDItm44Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_4_1_STATE,
      {OSDExitItm44,        OSDConfirmItm44,        OSDItm44Up,             OSDItm44Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_4_2_STATE,
      {OSDExitItm44,        OSDConfirmItm44,        OSDItm44Up,             OSDItm44Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_4_3_STATE,
      {OSDExitItm44,        OSDConfirmItm44,        OSDItm44Up,             OSDItm44Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_4_4_STATE,
      {OSDExitItm44,        OSDConfirmItm44,        OSDItm44Up,             OSDItm44Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_4_5_STATE,
      {OSDExitItm44,        OSDConfirmItm44,        OSDItm44Up,             OSDItm44Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_4_6_STATE,
      {OSDExitItm44,        OSDConfirmItm44,        OSDItm44Up,             OSDItm44Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_4_7_STATE,
      {OSDExitItm44,        OSDConfirmItm44,        OSDItm44Up,             OSDItm44Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_4_8_STATE,
      {OSDExitItm44,        OSDConfirmItm44,        OSDItm44Up,             OSDItm44Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_4_9_STATE,
      {OSDExitItm44,        OSDConfirmItm44,        OSDItm44Up,             OSDItm44Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_4_10_STATE,
      {OSDExitItm44,        OSDConfirmItm44,        OSDItm44Up,             OSDItm44Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_4_11_STATE,      
#if ENABLE_EYE_PROTECT == ON
      {OSDExitItm44,        OSDConfirmItm44,        OSDItm44Up,             OSDItm44Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_4_12_STATE,
      {OSDExitItm44,        OSDConfirmItm44,        OSDItm44Up,             OSDItm44Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_4_13_STATE,
#endif
#if ENABLE_ECO_SENSOR== ON
      {OSDExitItm44,        OSDConfirmItm44,        OSDItm44Up,             OSDItm44Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_4_14_STATE,
      {OSDExitItm44,        OSDConfirmItm44,        OSDItm44Up,             OSDItm44Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_4_15_STATE,
#endif
#if ENABLE_ANIMATION_MODE == ON
      {OSDExitItm44,        OSDConfirmItm44,        OSDItm44Up,             OSDItm44Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_4_16_STATE,
#endif
      {OSDExitItm45,        OSDCheckItm45,          OSDItm45Up,             OSDItm45Down,           OSDItm45ExitTopPageMenu},   //OSD_ITEM_4_5_1_STATE,
      {OSDExitItm45,        OSDCheckItm45,          OSDItm45Up,             OSDItm45Down,           OSDItm45ExitTopPageMenu},   //OSD_ITEM_4_5_2_STATE,
      {OSDExitItm46,        OSDConfirmItm46,        OSDItm46Up,             OSDItm46Down,           OSDItm46ExitTopPageMenu},   //OSD_ITEM_4_6_1_STATE,
      {OSDExitItm46,        OSDConfirmItm46,        OSDItm46Up,             OSDItm46Down,           OSDItm46ExitTopPageMenu},   //OSD_ITEM_4_6_2_STATE,
      {OSDExitItm47,        OSDConfirmItm47,        OSDItm47Up,             OSDItm47Down,           OSDItm47ExitTopPageMenu},   //OSD_ITEM_4_7_1_STATE,
      {OSDExitItm47,        OSDConfirmItm47,        OSDItm47Up,             OSDItm47Down,           OSDItm47ExitTopPageMenu},   //OSD_ITEM_4_7_2_STATE,
      {OSDExitItm48,        OSDConfirmItm48,        OSDItm48Up,             OSDItm48Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_6_1_STATE,
      {OSDExitItm48,        OSDConfirmItm48,        OSDItm48Up,             OSDItm48Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_8_2_STATE,
      {OSDExitItm48,        OSDConfirmItm48,        OSDItm48Up,             OSDItm48Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_8_3_STATE,
      {OSDExitItm48,        OSDConfirmItm48,        OSDItm48Up,             OSDItm48Down,           OSDExitTopPageMenu},        //OSD_ITEM_4_8_4_STATE,
      {OSDExitItm49,        OSDConfirmItm49,        OSDItm49Up,             OSDItm49Down,           OSDItm49ExitTopPageMenu},   //OSD_ITEM_4_9_1_STATE,
      {OSDExitItm49,        OSDConfirmItm49,        OSDItm49Up,             OSDItm49Down,           OSDItm49ExitTopPageMenu},   //OSD_ITEM_4_9_2_STATE,
      {NULL,                OSDExitItm410,          NULL,                   NULL,                   OSDExitTopPageMenu},        //OSD_ITEM_4_10_STATE,
      {OSDExitItm411,       OSDConfirmItm411,       OSDItm411Up,            OSDItm411Down,          OSDExitTopPageMenu},        //OSD_ITEM_4_11_1_STATE,
      {OSDExitItm411,       OSDConfirmItm411,       OSDItm411Up,            OSDItm411Down,          OSDExitTopPageMenu},        //OSD_ITEM_4_11_2_STATE,
      {OSDExitItm412,       OSDConfirmItm412,       OSDItm412Up,            OSDItm412Down,          OSDExitTopPageMenu},        //OSD_ITEM_4_12_1_STATE,
      {OSDExitItm412,       OSDExitItm412,          OSDItm412Up,            OSDItm412Down,          OSDExitTopPageMenu},        //OSD_ITEM_4_12_2_STATE,
#if ENABLE_EYE_PROTECT == ON
      {OSDExitItmEyeProtect,            OSDComfirmItmEyeProtect,     OSDItmEyeProtectUp,          OSDItmEyeProtectDown,        OSDExitTopPageMenu},        //OSD_ITEM_EYE_PROTECT_1_STATE,
      {OSDExitItmEyeProtect,            OSDComfirmItmEyeProtect,     OSDItmEyeProtectUp,          OSDItmEyeProtectDown,        OSDExitTopPageMenu},        //OSD_ITEM_EYE_PROTECT_2_STATE
      {OSDExitItmEyeProtectMeter,  OSDComfirmItmEyeProtectMeter,     OSDItmEyeProtectMeterUp,     OSDItmEyeProtectMeterDown,   OSDExitTopPageMenu},        //OSD_ITEM_EYE_PROTECT_METER_1_STATE,
      {OSDExitItmEyeProtectMeter,  OSDComfirmItmEyeProtectMeter,     OSDItmEyeProtectMeterUp,     OSDItmEyeProtectMeterDown,   OSDExitTopPageMenu},        //OSD_ITEM_EYE_PROTECT_METER_2_STATE
#endif      
      {OSDExitItmErgo1,     OSDComfirmItmErgo1,     OSDItmErgo1Up,          OSDItmErgo1Down,        OSDExitTopPageMenu},        //OSD_ITEM_ERGO_1_1_STATE,
      {OSDExitItmErgo1,     OSDComfirmItmErgo1,     OSDItmErgo1Up,          OSDItmErgo1Down,        OSDExitTopPageMenu},        //OSD_ITEM_ERGO_1_2_STATE
      {OSDExitItmErgo2,     OSDComfirmItmErgo2,     OSDItmErgo2Up,          OSDItmErgo2Down,        OSDExitTopPageMenu},        //OSD_ITEM_ERGO_2_1_STATE
      {OSDExitItmErgo2,     OSDComfirmItmErgo2,     OSDItmErgo2Up,          OSDItmErgo2Down,        OSDExitTopPageMenu},        //OSD_ITEM_ERGO_2_2_STATE
      {OSDExitItmErgo2,     OSDComfirmItmErgo2,     OSDItmErgo2Up,          OSDItmErgo2Down,        OSDExitTopPageMenu},        //OSD_ITEM_ERGO_2_3_STATE
      {OSDExitItmErgo2,     OSDComfirmItmErgo2,     OSDItmErgo2Up,          OSDItmErgo2Down,        OSDExitTopPageMenu},        //OSD_ITEM_ERGO_2_4_STATE
      {OSDExitItmErgo2,     OSDComfirmItmErgo2,     OSDItmErgo2Up,          OSDItmErgo2Down,        OSDExitTopPageMenu},        //OSD_ITEM_ERGO_2_5_STATE
      {OSDExitItmErgo3,     OSDComfirmItmErgo3,     OSDItmErgo3Up,          OSDItmErgo3Down,        OSDExitTopPageMenu},        //OSD_ITEM_ERGO_3_1_STATE
      {OSDExitItmErgo3,     OSDComfirmItmErgo3,     OSDItmErgo3Up,          OSDItmErgo3Down,        OSDExitTopPageMenu},        //OSD_ITEM_ERGO_3_2_STATE
      {OSDExitItmErgo3,     OSDComfirmItmErgo3,     OSDItmErgo3Up,          OSDItmErgo3Down,        OSDExitTopPageMenu},        //OSD_ITEM_ERGO_3_3_STATE
      {OSDExitItmErgo3,     OSDComfirmItmErgo3,     OSDItmErgo3Up,          OSDItmErgo3Down,        OSDExitTopPageMenu},        //OSD_ITEM_ERGO_3_4_STATE
      {OSDExitItmErgo3,     OSDComfirmItmErgo3,     OSDItmErgo3Up,          OSDItmErgo3Down,        OSDExitTopPageMenu},        //OSD_ITEM_ERGO_3_5_STATE
#if ENABLE_ECO_SENSOR == ON
      {OSDExitItmECOSensor,         OSDComfirmItmECOSensor,       OSDItmECOSensorUp,      OSDItmECOSensorDown,      OSDExitTopPageMenu},            //OSD_ITEM_ECO_1_1_STATE
      {OSDExitItmECOSensor,         OSDComfirmItmECOSensor,       OSDItmECOSensorUp,      OSDItmECOSensorDown,      OSDExitTopPageMenu},            //OSD_ITEM_ECO_1_2_STATE
      {OSDExitItmECOSensorMeter,    OSDComfirmItmECOSensorMeter,  OSDItmECOSensorMeterUp, OSDItmECOSensorMeterDown, OSDExitTopPageMenu},   //OSD_ITEM_ECO_2_1_STATE
      {OSDExitItmECOSensorMeter,    OSDComfirmItmECOSensorMeter,  OSDItmECOSensorMeterUp, OSDItmECOSensorMeterDown, OSDExitTopPageMenu},   //OSD_ITEM_ECO_2_2_STATE
      {OSDExitItmSensorRange,       OSDComfirmItmSensorRange,     OSDItmSensorRangeUp,    OSDItmSensorRangeDown,    OSDExitTopPageMenu},        //OSD_ITEM_ECO_3_1_STATE
      {OSDExitItmSensorRange,       OSDComfirmItmSensorRange,     OSDItmSensorRangeUp,    OSDItmSensorRangeDown,    OSDExitTopPageMenu},        //OSD_ITEM_ECO_3_2_STATE
      {OSDExitItmSensorRange,       OSDComfirmItmSensorRange,     OSDItmSensorRangeUp,    OSDItmSensorRangeDown,    OSDExitTopPageMenu},        //OSD_ITEM_ECO_3_3_STATE
#endif
      //ULEric140407
      //{OSDExitSubItm2541,   OSDEnterSubItm2542,     OSDSubItm2541Up,        OSDSubItm2541Down,      OSDExitTopPageMenu},      //OSD_SUBITEM_2_5_4_1_STATE,
      //{OSDExitSubItm2542,   OSDEnterSubItm2543,     OSDSubItm2542Up,        OSDSubItm2542Down,      OSDExitTopPageMenu},      //OSD_SUBITEM_2_5_4_2_STATE,
      //{OSDExitSubItm2543,   OSDEnterSubItm2543to1,  OSDSubItm2543Up,        OSDSubItm2543Down,      OSDExitTopPageMenu},      //OSD_SUBITEM_2_5_4_3_STATE,
      {OSDExitSubItm2541,   OSDEnterSubItm2542,     OSDSubItm2541Up,        OSDSubItm2541Down,      OSDExitTopPageMenu},        //OSD_SUBITEM_2_5_4_1_STATE,        
      {OSDEnterSubItm2543to1,OSDEnterSubItm2543,    OSDSubItm2542Up,        OSDSubItm2542Down,      OSDExitTopPageMenu},        //OSD_SUBITEM_2_5_4_2_STATE,
      {OSDEnterSubItm2542,  NULL,                   OSDSubItm2543Up,        OSDSubItm2543Down,      OSDExitTopPageMenu},        //OSD_SUBITEM_2_5_4_3_STATE,
      {OSDExitSubItmLBL,    OSDConfirmSubItmLBL,    OSDSubItmLBLUp,         OSDSubItmLBLDown,       OSDExitLBLTopPageMenu},     //OSD_SUBITEM_3_1_2_1_STATE LBL
      {OSDExitSubItmLBL,    OSDConfirmSubItmLBL,    OSDSubItmLBLUp,         OSDSubItmLBLDown,       OSDExitLBLTopPageMenu},     //OSD_SUBITEM_3_1_2_2_STATE LBL
      {OSDExitSubItmLBL,    OSDConfirmSubItmLBL,    OSDSubItmLBLUp,         OSDSubItmLBLDown,       OSDExitLBLTopPageMenu},     //OSD_SUBITEM_3_1_2_3_STATE LBL
      {OSDExitSubItmLBL,    OSDConfirmSubItmLBL,    OSDSubItmLBLUp,         OSDSubItmLBLDown,       OSDExitLBLTopPageMenu},     //OSD_SUBITEM_3_1_2_4_STATE LBL
#if ENABLE_ANIMATION_MODE == ON
      {OSDExitSubItmAnimation, NULL,         OSDSubItmAnimationUp,   OSDSubItmAnimationDown,       OSDExitAnimationTopPageMenu},        //OSD_SUBITEM_3_1_3_1_STATE,
#endif
      {OSDExitSubItm411,    OSDEnterSubItm411X,     OSDSubItm411Up,         OSDSubItm411Down,       OSDExitTopPageMenu},        //OSD_SUBITEM_4_1_1_1_STATE,
      {OSDExitSubItm411,    OSDEnterSubItm411X,     OSDSubItm411Up,         OSDSubItm411Down,       OSDExitTopPageMenu},        //OSD_SUBITEM_4_1_1_2_STATE,
      {OSDExitSubItm411,    OSDEnterSubItm411X,     OSDSubItm411Up,         OSDSubItm411Down,       OSDExitTopPageMenu},        //OSD_SUBITEM_4_1_1_3_STATE,
      {OSDExitSubItm411,    OSDEnterSubItm411X,     OSDSubItm411Up,         OSDSubItm411Down,       OSDExitTopPageMenu},        //OSD_SUBITEM_4_1_1_4_STATE,
      {OSDExitSubItm411,    OSDEnterSubItm411X,     OSDSubItm411Up,         OSDSubItm411Down,       OSDExitTopPageMenu},        //OSD_SUBITEM_4_1_1_5_STATE,
      {OSDExitSubItm411,    OSDEnterSubItm411X,     OSDSubItm411Up,         OSDSubItm411Down,       OSDExitTopPageMenu},        //OSD_SUBITEM_4_1_1_6_STATE,
      {OSDExitSubItm411,    OSDEnterSubItm411X,     OSDSubItm411Up,         OSDSubItm411Down,       OSDExitTopPageMenu},        //OSD_SUBITEM_4_1_1_7_STATE,
      {OSDExitSubItm411,    OSDEnterSubItm411X,     OSDSubItm411Up,         OSDSubItm411Down,       OSDExitTopPageMenu},        //OSD_SUBITEM_4_1_1_8_STATE,
      {OSDExitSubItm411,    OSDEnterSubItm411X,     OSDSubItm411Up,         OSDSubItm411Down,       OSDExitTopPageMenu},        //OSD_SUBITEM_4_1_1_9_STATE,
      {OSDExitSubItm411,    OSDEnterSubItm411X,     OSDSubItm411Up,         OSDSubItm411Down,       OSDExitTopPageMenu},        //OSD_SUBITEM_4_1_1_10_STATE,
      {OSDExitSubItm411,    OSDEnterSubItm411X,     OSDSubItm411Up,         OSDSubItm411Down,       OSDExitTopPageMenu},        //OSD_SUBITEM_4_1_1_11_STATE,
      {OSDExitSubItm411,    OSDEnterSubItm411X,     OSDSubItm411Up,         OSDSubItm411Down,       OSDExitTopPageMenu},        //OSD_SUBITEM_4_1_1_12_STATE,
      {OSDExitSubItm411,    OSDEnterSubItm411X,     OSDSubItm411Up,         OSDSubItm411Down,       OSDExitTopPageMenu},        //OSD_SUBITEM_4_1_1_13_STATE,
      {OSDExitSubItm411,    OSDEnterSubItm411X,     OSDSubItm411Up,         OSDSubItm411Down,       OSDExitTopPageMenu},        //OSD_SUBITEM_4_1_1_14_STATE,
      {OSDExitSubItm411,    OSDEnterSubItm411X,     OSDSubItm411Up,         OSDSubItm411Down,       OSDExitTopPageMenu},        //OSD_SUBITEM_4_1_1_15_STATE,
      {OSDExitSubItm411,    OSDEnterSubItm411X,     OSDSubItm411Up,         OSDSubItm411Down,       OSDExitTopPageMenu},        //OSD_SUBITEM_4_1_1_16_STATE,
      {OSDExitSubItm411,    OSDEnterSubItm411X,     OSDSubItm411Up,         OSDSubItm411Down,       OSDExitTopPageMenu},        //OSD_SUBITEM_4_1_1_17_STATE,
      {OSDExitSubItm412,    OSDConfirmSubItm412,    OSDSubItm412Up,         OSDSubItm412Down,       OSDExitTopPageMenu},        //OSD_SUBITEM_4_1_2_1_STATE,
      {OSDExitSubItm412,    OSDConfirmSubItm412,    OSDSubItm412Up,         OSDSubItm412Down,       OSDExitTopPageMenu},        //OSD_SUBITEM_4_1_2_2_STATE,
      {OSDExitSubItm412,    OSDConfirmSubItm412,    OSDSubItm412Up,         OSDSubItm412Down,       OSDExitTopPageMenu},        //OSD_SUBITEM_4_1_2_3_STATE,
      {OSDExitSubItm412,    OSDConfirmSubItm412,    OSDSubItm412Up,         OSDSubItm412Down,       OSDExitTopPageMenu},        //OSD_SUBITEM_4_1_2_4_STATE,
      {OSDExitSubItm412,    OSDConfirmSubItm412,    OSDSubItm412Up,         OSDSubItm412Down,       OSDExitTopPageMenu},        //OSD_SUBITEM_4_1_2_5_STATE,
      {OSDExitSubItm412,    OSDConfirmSubItm412,    OSDSubItm412Up,         OSDSubItm412Down,       OSDExitTopPageMenu},        //OSD_SUBITEM_4_1_2_6_STATE,
      {NULL,                NULL,                   NULL,                   NULL,                   NULL},                      //OSD_DIRECT_1_STATE,,
      {NULL,                NULL,                   NULL,                   NULL,                   NULL},                      //OSD_DIRECT_2_STATE,,
      {NULL,                NULL,                   NULL,                   NULL,                   NULL},                      //OSD_DIRECT_3_STATE,,
      {NULL,                NULL,                   NULL,                   NULL,                   NULL},                      //OSD_AUTOTUNE_STATE,
      {OSDShowSourceMenu,   OSDShowSourceMenu,      OSDShowSourceMenu,      OSDShowSourceMenu,      OSDShowSourceMenu},         //OSD_INFO_OUTOFLIMIT_STATE,
      {OSDShowSourceMenu,   OSDShowSourceMenu,      OSDShowSourceMenu,      OSDShowSourceMenu,      OSDShowSourceMenu},         //OSD_INFO_OUTOFRANCE_STATE,
      {OSDShowSourceMenu,   OSDShowSourceMenu,      OSDShowSourceMenu,      OSDShowSourceMenu,      OSDShowSourceMenu},         //OSD_INFO_NOSYNC_STATE,
      {OSDShowSourceMenu,   OSDShowSourceMenu,      OSDShowSourceMenu,      OSDShowSourceMenu,      OSDShowSourceMenu},         //OSD_INFO_NOCABLE_STATE,
      {NULL,                NULL,                   NULL,                   NULL,                   NULL},                      //OSD_INFO_NOTICE_STATE,
      {NULL,                NULL,                   NULL,                   NULL,                   NULL},                      //OSD_INFO_SAVENOTICE_STATE,
      {NULL,                NULL,                   NULL,                   NULL,                   NULL},                      //OSD_INFO_SOURCE_STATE,
      {NULL,                NULL,                   NULL,                   NULL,                   NULL},                      //OSD_INFO_OSDLOCK_STATE,
      {OSDUNLOCKKeyMenu,    OSDUNLOCKKeyMenu,       OSDUNLOCKKeyMenu,       OSDUNLOCKKeyMenu,       OSDUNLOCKKeyMenu},          //OSD_INFO_OSDUNLOCKKEY_STATE,      
      {NULL,                NULL,                   NULL,                   NULL,                   NULL},                      //OSD_INFO_NONPRESET_STATE
      {OSDExitSmartReminder,OSDExitSmartReminder,   OSDExitSmartReminder,   OSDExitSmartReminder,   OSDExitSmartReminder},      //OSD_INFO_SMART_REMINDER_STATE,
      {NULL,                NULL,                   NULL,                   NULL,                   NULL},                      //OSD_RES_NOTICE_STATE
      {NULL,                NULL,                   OSDConfirmResetInfor,   OSDExitResetInfor,      NULL},                      //OSD_INFO_RESETALL_NOTICE_STATE
      {NULL,                NULL,                   OSDConfirmResetColorInfor,  OSDExitResetColorInfor, NULL},                  //OSD_INFO_RESETCOLOR_NOTICE_STATE
      {OSDEnterMenuKeyMenu, OSDEnterTopPageMenu,    OSDEnterTopPageMenu,    OSDEnterTopPageMenu,    OSDEnterExitKeyMenu},       //OSD_INFO_SENSEYE_DEMO,
      {NULL,                NULL,                   OSDConfirmDCRInfor,     OSDExitDCRInfor,        NULL},                      //OSD_INFO_DCR_NOTICE_STATE
#if ENABLE_EYE_PROTECT == ON
      {OSDEnterMenuKeyMenu, OSDEnterTopPageMenu,    OSDEnterTopPageMenu,    OSDEnterTopPageMenu,    OSDEnterExitKeyMenu},       //OSD_INFO_EYE_PROTECT_METER_STATE
#endif
#if ENABLE_ECO_SENSOR == ON
      {OSDEnterMenuKeyMenu, OSDEnterTopPageMenu,    OSDEnterTopPageMenu,    OSDEnterTopPageMenu,    OSDEnterExitKeyMenu},       //OSD_INFO_ECO_METER_STATE
#endif
      {NULL,                NULL,                   NULL,                   NULL,                   NULL},                      //OSD_OPT1_STATE,,
      {NULL,                NULL,                   NULL,                   NULL,                   NULL},                      //OSD_OPT2_STATE,,
      {OSDCloseAll,         OSDEnterFItm,           OSDUpFactory,           OSDDnFactory,           OSDExitFItm},               //OSD_FACT_STATE,
      {OSDExitFItm,         OSDExitFItm2,           OSDUpFItm,              OSDDnFItm,              OSDExitFItm},               //OSD_FITM_STATE,
       //For BENQ Service Menu
      {OSDCloseAll,         OSDAdjSMItm,            OSDUpServiceMenu,       OSDDnServiceMenu,       NULL},                      //OSD_SM_STATE,
       //For BENQ Service Menu
      {OSDInputDir1,        OSDInputDir2,           OSDInputDir3,           OSDInputDir4,           NULL},                      //OSD_DIRSRC_STATE,
};

code void (*OSDAppRoutine[NUM_OSD_APP_EVENTS])(void) = {
    OSDEnterNoSync,     //OSD_NO_SYNC_EVENT
    OSDEnterNoCable,    //OSD_NO_CABLE_EVENT
    OSDEnterNormal,     //OSD_NML_EVENT
    OSDEnterOOL,        //OSD_OOL_EVENT
    OSDEnterOOR,        //OSD_OOR_EVENT
    OSDCloseAll,        //OSD_OFF_EVENT
    NULL                //OSD_NOP_EVENT
};

#if 0
code void (*OSDUnusedRoutine[])(void) = {
    OSDEnterDir1,
    OSDEnterDir2
};
#endif
