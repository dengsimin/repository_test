/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/

#ifndef __RAM_H__
#define __RAM_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "InputTiming.h"
#include "Typedef.h"

//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************
typedef struct{
    UCHAR ucInputPort;
    UCHAR ucPortName;
}tINPUTPORT;

enum  InputPortNum {
  _0_Port,
  _1_Port,
  _2_Port,
  _3_Port,
  _4_Port
};

enum  ChannelSelction {
    _MainChannel,
    _PIPChannel,
    _DPTXChannel,
    _AllChannel
};

typedef struct {
    UCHAR bForceLanguage:1;
    UCHAR bDDCCICmdIMenu : 1;
    UCHAR bYesNoTemp :1;
    UCHAR OSDUpUsr:1;
    UCHAR OSDUpTmg:1;
    UCHAR OTSFactoryHotKey:1;
    UCHAR bHotKeySource : 1;
    UCHAR bDDCCIPreSetClock : 1;
    UCHAR bDDCIcmdACK : 1;
    UCHAR bFactory : 1;
    UCHAR bPreShowSourceNoSync : 1;
    UCHAR bPreShowMsgSource : 1;
    UCHAR bPreShowMsgEnergystar : 1;
    UCHAR bPreShowOSDLockFirstOn : 1;    
    UCHAR bAutoTuneFinish : 1;
    UCHAR bDcrCutoffFlag : 1;
#if E_SAVE_FUNC        
    UCHAR bESave_Enable : 1;
#endif
    //UCHAR bCheckVcom : 1;
    UCHAR bDCRTemp : 1;
    UCHAR bisModechaged : 1;
    UCHAR bIsShowLogo : 1;
    UCHAR bZPUseCurrentModeDetect : 1;
    UCHAR bLogoONState : 1;
    UCHAR bDoReset : 1;
    UCHAR bIsManualEDIDWP:1;
    UCHAR bAutoColorFinish:1;
    UCHAR bPIPSwap:1;            
    UCHAR bEDIDFinish:1;    
    UCHAR bNormalStates:1;
    UCHAR bPIPSourceChange:1;
    UCHAR bSOUCESWITCH:1;
    UCHAR bPressKeyWakeUp:1;
    UCHAR bisColorFormatRGB:1;
    UCHAR bFOSDFM:1;
#if ENABLE_ECO_EYE_SENSOR == ON
    UCHAR bPressKeyECODetect:1;
#endif
    UCHAR bIsTimingChanged:1;
    UCHAR bSOGOverScan:1;
    UCHAR bOverScan:1;
    UCHAR bDualviewAdjust:1;
    UCHAR bShowSensEyeDemoTemp : 1;        
    UCHAR ucBFMode;
    UCHAR ucFactoryODMode_temp;
    //UCHAR ucNewDynBk;
    //UCHAR iCurDynBk;
    //UCHAR ucDCRStableCount;
    //UCHAR Last_Press_Buttons;
    UCHAR ucPerformReset;
    UCHAR ucBrightness;
    UCHAR ucContrast;
    UCHAR ucOSDColorIconID;
    USHRT usESave_Timer_1s;
    USHRT usCRC;
    USHRT usFontIndex_temp;
    //USHRT usDDCCIRECOVERLoop;
    UCHAR ucMainMenuCursor;
    UCHAR ucVs_wid;
    UCHAR ucVs_wid_diff_cnt;
    UCHAR ucFactoryHp;
    UCHAR ucFactoryVp;
    UCHAR ucCurrentInputSource;
    UCHAR ucLanguage;
    USHRT usErgoTime;
    UCHAR ucErgoDuration;
    USHRT usAuto_poweroff_Time;
#if ENABLE_ECO_SENSOR == ON
    USHRT usECOsensor_Auto_poweroff_Time;
#endif
    UCHAR uctmpPIPSrc;
    UCHAR ucOSD_preview_temp;
    UCHAR ucDualViewTemp;    
#if ENABLE_ECO_EYE_SENSOR
    UCHAR ucECO_Status;
    UCHAR ucEYE_Status;
    UCHAR ucEYE_Step;
    UCHAR ucEYE_Pre_Step;
    UCHAR ucEYE_Meter_Step;
    UCHAR ucECOCycleStep;
#endif
    UCHAR bPowerKeyYNPowerONOFFFlag:1;

} tCUSTOM_SYS;

//******************************************************************************
// D A T A   T Y P E   D E F I N E S
//******************************************************************************

//******************************************************************************
// V A R I A B L E S   P R O T O T Y P E
//******************************************************************************
extern xdata InputTimingFormat InputTiming;
extern xdata NvramUserData UserData;
extern xdata NvramCalibData CalibData;
extern xdata NvramSystemData SystemData;
extern xdata PanelData UserPanelData;
extern xdata UCHAR ucADCPhase100;
extern xdata UCHAR ucVstart100;
extern xdata tCUSTOM_SYS Custom_System;
#if ENABLE_HDCP_TRIM_MODE == ON || ENABLE_EDID_TRIM_MODE == ON
extern xdata UCHAR ucEFUSE_ID;
extern xdata UCHAR ucEFUSETrimSucess;
extern xdata UCHAR ucLEDTRIM_LO;
extern xdata UCHAR ucLEDTRIM_HI;
extern xdata UCHAR ucADCTRIM;
extern xdata UCHAR ucADCTRIM_SEL;
#endif
extern xdata USHRT usAudioMuteDelay;
extern xdata USHRT usTimerANAMute;
#if ENABLE_FREESYNC_DEMO == ON
extern bit bFreeSyncMode;
#endif
extern bit bSelectTable;
extern xdata UCHAR glob_FontBuff[];

//******************************************************************************
// F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
void RamInitialize(void);

#endif //__RAM_H__
