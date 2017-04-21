/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/

#ifndef __NVRAM_H__
#define __NVRAM_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "InputTiming.h"
#include "Typedef.h"

//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************
#define NVRAM_ADDR              0xA0  /*!< The slave address of NVRam (24C16). */
#define NVRAM_TIMING_ADDR       0x000 /*!< The start address of timing data in NVRam. */
//#define NVRAM_TIMING_AREA       (NVRAM_USER_ADDR-NVRAM_TIMING_ADDR) /*!< The size of timing data in NVRam. */
//#define NVRAM_USER_ADDR         0x270 /*!< The start address of user data in NVRam. */
//#define NVRAM_CALIB_ADDR        0x290 /*!< The start address of calibration data in NVRam. */
//#define NVRAM_SYSTEM_ADDR       0x2B0 /*!< The start address of system data in NVRam. */
//#define NVRAM_HDCP_ADDR         0x2D0 /*!< The start address of HDCP keys in NVRam. */
#define NVRAM_TIMING_AREA        (NVRAM_CALIB_ADDR-NVRAM_TIMING_ADDR)
#define NVRAM_CALIB_ADDR        0x270 /*!< The start address of calibration data in NVRam. */ // 28byte  max:64 byte
#define NVRAM_SYSTEM_ADDR       0x2B0 /*!< The start address of system data in NVRam. */      // 4byte + 9x2 byte =22byte  max:64 byte 0x2B0
#define NVRAM_USER_ADDR         0x2F0 /*!< The start address of user data in NVRam. */        // 66 byte max: 144 byte                       
#define NVRAM_HDCP_ADDR         0x6A0//0x2D0 /*!< The start address of HDCP keys in NVRam. */


#define NVRAM_VGA_EDID_ADDR     0x400 /*!< The start address of VGA edid in NVRam. */
#define NVRAM_VGA_EDID_AREA     0x80  /*!< The size of VGA edid in NVRam.*/
#define NVRAM_DVI_EDID_ADDR     0x480 /*!< The start address of DVI edid in NVRam. */
#define NVRAM_DVI_EDID_AREA     0x80  /*!< The size of DVI edid in NVRam. */
#define NVRAM_HDMI_EDID_ADDR    0x500 /*!< The start address of HDMI edid in NVRam. */
#define NVRAM_HDMI_EDID_AREA    0x100 /*!< The size of HDMI edid in NVRam.*/
#define NVRAM_END               0x7FF /*!< The end address of NVRam.*/

//#define NVRAM_USER_SIZE         (NVRAM_CALIB_ADDR - NVRAM_USER_ADDR)   /*!< The size of user data in NVRam. */
//#define NVRAM_CALIB_SIZE        (NVRAM_SYSTEM_ADDR - NVRAM_CALIB_ADDR) /*!< The size of calibration data in NVRam. */
//#define NVRAM_SYSTEM_SIZE       (NVRAM_HDCP_ADDR - NVRAM_SYSTEM_ADDR)  /*!< The size of system data in NVRam. */

#if VGA_DDC_CHANNEL != 0xFF
#define NVRAM_USER_SIZE         (NVRAM_VGA_EDID_ADDR - NVRAM_USER_ADDR) /*!< The size of user data in NVRam. */
#else
#define NVRAM_USER_SIZE         (NVRAM_DVI_EDID_ADDR - NVRAM_USER_ADDR) /*!< The size of user data in NVRam. */
#endif
#define NVRAM_CALIB_SIZE        (NVRAM_SYSTEM_ADDR - NVRAM_CALIB_ADDR)  /*!< The size of calibration data in NVRam. */
#define NVRAM_SYSTEM_SIZE       (NVRAM_USER_ADDR - NVRAM_SYSTEM_ADDR)   /*!< The size of system data in NVRam. */


#define NVRAM_FIELD_END_FLAG    0xA5A5 /*!< The flag of the end of NvramUserData/NvramCalibData/NvramSystemData fields. */

#define NVRAM_UPDATE_FREE       0 /*!< NVRam update type: Update none. */
#define NVRAM_UPDATE_ALL        1 /*!< NVRam update type: Update all. */
#define NVRAM_UPDATE_USER       2 /*!< NVRam update type: Update user data. */

#define CheckDataRange(a,b,c,d)   {if ((a - c)>(b - c)) a = d;}
//******************************************************************************
// D A T A   T Y P E   D E F I N E S
//******************************************************************************
/*!
 * Data type of timing-related fields in NVRam.
 */
typedef struct _NVRAM_TIMING_FORMAT_ {
    USHRT usHTotal;
    USHRT usHStart;
    USHRT usVStart;
    USHRT usHTotal50;
    USHRT usHStart50;
    USHRT usVStart50;
    UCHAR ucPhase;
    UCHAR ucAutoTune;
    USHRT usModeIndex;
} NvramTimingFormat;

/*!
 * Data type of user-related fields in NVRam.
 */
typedef struct _NVRAM_USER_DATA_ {
    UCHAR bICare : 1;
    UCHAR bPowerStatus : 1;
    UCHAR bOSDLock : 1;
    UCHAR bDDCCI : 1;
    UCHAR bAudioMute : 1;
    UCHAR bGammaOnOff : 1;
    UCHAR bDCRMode : 1;
    UCHAR bDBCMode : 1;
    UCHAR bLDOnOff : 1;
    UCHAR bAutoSyncSource : 1;
    UCHAR bPIPAutoSyncSource : 1;
#if ENABLE_AUTO_POVIT_FUNC == ON      
    UCHAR bAutoPivot : 1;
#endif
    UCHAR bOSDRotation : 1;
    UCHAR bOverScan : 1;
    UCHAR bSOGOverScan : 1;
    UCHAR bDPSpeed : 1;
    UCHAR ucDCRMode;
    UCHAR bBrightFrame : 1;
    UCHAR bDemo : 1;
    UCHAR bAutoDetect : 1;
    UCHAR bFullEnhance : 1;
    UCHAR bNatureSkin : 1;
    UCHAR bGreenEnhance : 1;
    UCHAR bBlueEnhance : 1;
    UCHAR bAutoConfig : 1;
    UCHAR bClearVisionDemo : 1;
    UCHAR bPowerKeyLock : 1;
    UCHAR bHDMIAudioSelect : 1;
    UCHAR bSRS3D: 1;
#if ENABLE_DUAL_370 == ON
    UCHAR bPIPSWAP : 1;
#endif
#if TPV_DP_VERSION_SELECT == ON
    UCHAR bDPVersion :1; 
#endif
    UCHAR bSensEyeDemo : 1;
    UCHAR bColorFormat : 1;
    UCHAR bHDMIAutoSwitch : 1    ;
    UCHAR bDPAutoSwitch : 1;
    UCHAR bResNotice : 1;    
    UCHAR bSmartReminder : 1;    
    UCHAR bSeviceMenu : 1;
#if ENABLE_EYE_PROTECT == ON
    UCHAR bEyeProtect : 1;
    UCHAR bEyeProtectMeter : 1;
#endif
#if ENABLE_ECO_SENSOR == ON                                       
    UCHAR bECOSensor : 1;
    UCHAR bECOSensorMeter : 1;
    UCHAR ucSensorRange; 
#endif
    UCHAR ucHDMIRGBRange;
#if ENABLE_SMART_SCALING == ON
    UCHAR ucSmartScaling;
#endif
    UCHAR ucUserDefVideoSource;    
    UCHAR ucLanguage;
#if ENABLE_EYE_PROTECT == ON
    UCHAR ucEyeProtectBrightness;	
#endif    
    UCHAR ucBrightness;
    UCHAR ucBrightness_sRGB;    
    UCHAR ucBrightness_Standard;
    UCHAR ucBrightness_LBL_Mult;
    UCHAR ucBrightness_LBL_Web;    
    UCHAR ucBrightness_LBL_Office;
    UCHAR ucBrightness_LBL_Read;
#if ENABLE_PICTURE_MODE_MOVIE == ON                                   
    UCHAR ucBrightness_Movie;
#endif
#if ENABLE_PICTURE_MODE_GAME == ON                         
    UCHAR ucBrightness_Game;    
#endif
#if ENABLE_PICTURE_MODE_PHOTO== ON                               
    UCHAR ucBrightness_Photo;    
#endif
    UCHAR ucBrightness_USER;
    UCHAR ucBrightness_MBOOK;
#if	ENABLE_PICTURE_MODE_ANIMATION == ON        
    UCHAR ucBrightness_Animation;
#endif
#if	ENABLE_PICTURE_MODE_CAD == ON
    UCHAR ucBrightness_CAD;
#endif
#if	ENABLE_PRESENTATION_MODE == ON    
    UCHAR ucBrightness_Presentation;        
#endif
#if ENABLE_PICTURE_MODE_REC709 == ON                                   
    UCHAR ucBrightness_Rec709;
#endif  
#if ENABLE_PICTURE_MODE_DARKROOM == ON                                   
    UCHAR ucBrightness_DarkRoom;
#endif  
    UCHAR ucContrast;
    UCHAR ucContrast_sRGB;
    UCHAR ucContrast_Standard;
    UCHAR ucContrast_LBL_Mult;
    UCHAR ucContrast_LBL_Web;    
    UCHAR ucContrast_LBL_Office;
    UCHAR ucContrast_LBL_Read;
#if ENABLE_PICTURE_MODE_MOVIE == ON                                   
    UCHAR ucContrast_Movie;
#endif
#if ENABLE_PICTURE_MODE_GAME == ON                         
    UCHAR ucContrast_Game;
#endif
#if ENABLE_PICTURE_MODE_PHOTO== ON                               
    UCHAR ucContrast_Photo;
#endif
    UCHAR ucContrast_USER;
    UCHAR ucContrast_MBOOK;
#if	ENABLE_PICTURE_MODE_ANIMATION == ON            
    UCHAR ucContrast_Animation;
#endif
#if	ENABLE_PICTURE_MODE_CAD == ON
    UCHAR ucContrast_CAD;
#endif
#if	ENABLE_PRESENTATION_MODE == ON    
    UCHAR ucContrast_Presentation;   
#endif
    UCHAR ucDualViewMode;
#if ENABLE_PICTURE_MODE_REC709 == ON                                   
    UCHAR ucContrast_Rec709;
#endif  
#if ENABLE_PICTURE_MODE_DARKROOM == ON                                   
    UCHAR ucContrast_DarkRoom;
#endif
    UCHAR ucDynamicContrast;
    UCHAR ucOSDTimer;
    UCHAR ucOSDX;
    UCHAR ucOSDY;
    UCHAR ucOSDTransparent;
    UCHAR ucVolume;
    UCHAR ucColorTemp;
    UCHAR ucColorTemp_sRGB;    
    UCHAR ucColorTemp_Standard;
    UCHAR ucColorTemp_LBL_Mult;
    UCHAR ucColorTemp_LBL_Web;    
    UCHAR ucColorTemp_LBL_Office;
    UCHAR ucColorTemp_LBL_Read;
#if ENABLE_PICTURE_MODE_MOVIE == ON                                   
    UCHAR ucColorTemp_Movie;
#endif
#if ENABLE_PICTURE_MODE_GAME == ON                         
    UCHAR ucColorTemp_Game;    
#endif
#if ENABLE_PICTURE_MODE_PHOTO== ON                               
    UCHAR ucColorTemp_Photo;    
#endif
    UCHAR ucColorTemp_USER;
    UCHAR ucColorTemp_MBOOK;
#if	ENABLE_PICTURE_MODE_ANIMATION == ON        
    UCHAR ucColorTemp_Animation;
#endif
#if	ENABLE_PICTURE_MODE_CAD == ON
    UCHAR ucColorTemp_CAD;
#endif
#if	ENABLE_PRESENTATION_MODE == ON    
    UCHAR ucColorTemp_Presentation;        
#endif
#if ENABLE_PICTURE_MODE_REC709 == ON                                   
    UCHAR ucColorTemp_Rec709;
#endif  
#if ENABLE_PICTURE_MODE_DARKROOM == ON                                   
    UCHAR ucColorTemp_DarkRoom;
#endif 
    UCHAR ucUserRGain;
    UCHAR ucUserGGain;
    UCHAR ucUserBGain;
    UCHAR ucUserROffset;
    UCHAR ucUserGOffset;
    UCHAR ucUserBOffset;
    UCHAR ucAspectRatio;
    UCHAR ucAspectRatio_VGADVIDP;
    UCHAR ucAspectRatio_HDMI;
    UCHAR ucODMode;
    UCHAR ucODMode_sRGB;    
    UCHAR ucODMode_Standard;
    UCHAR ucODMode_LBL_Mult;
    UCHAR ucODMode_LBL_Web;    
    UCHAR ucODMode_LBL_Office;
    UCHAR ucODMode_LBL_Read;
#if ENABLE_PICTURE_MODE_MOVIE == ON                                   
    UCHAR ucODMode_Movie;
#endif
#if ENABLE_PICTURE_MODE_GAME == ON                         
    UCHAR ucODMode_Game;    
#endif
#if ENABLE_PICTURE_MODE_PHOTO== ON                               
    UCHAR ucODMode_Photo;    
#endif
    UCHAR ucODMode_USER;
    UCHAR ucODMode_MBOOK;
#if	ENABLE_PICTURE_MODE_ANIMATION == ON        
    UCHAR ucODMode_Animation;
#endif
#if	ENABLE_PICTURE_MODE_CAD == ON
    UCHAR ucODMode_CAD;
#endif
#if	ENABLE_PRESENTATION_MODE == ON    
    UCHAR ucODMode_Presentation;        
#endif
#if ENABLE_PICTURE_MODE_REC709 == ON                                   
    UCHAR ucODMode_Rec709;
#endif  
#if ENABLE_PICTURE_MODE_DARKROOM == ON                                   
    UCHAR ucODMode_DarkRoom;
#endif  
    
    UCHAR ucBFMode;
    UCHAR ucInputSource;
    UCHAR ucAOCPIPPosition;
    UCHAR ucPIPMode;
    UCHAR ucPIPInputSrc;
    UCHAR ucGammaNum;
    UCHAR ucGammaNum_sRGB;    
    UCHAR ucGammaNum_Standard;
    UCHAR ucGammaNum_LBL_Mult;
    UCHAR ucGammaNum_LBL_Web;    
    UCHAR ucGammaNum_LBL_Office;
    UCHAR ucGammaNum_LBL_Read;
#if ENABLE_PICTURE_MODE_MOVIE == ON                                   
    UCHAR ucGammaNum_Movie;
#endif
#if ENABLE_PICTURE_MODE_GAME == ON                         
    UCHAR ucGammaNum_Game;    
#endif
#if ENABLE_PICTURE_MODE_PHOTO== ON                               
    UCHAR ucGammaNum_Photo;    
#endif
    UCHAR ucGammaNum_USER;
    UCHAR ucGammaNum_MBOOK;
#if	ENABLE_PICTURE_MODE_ANIMATION == ON        
    UCHAR ucGammaNum_Animation;
#endif
#if	ENABLE_PICTURE_MODE_CAD == ON
    UCHAR ucGammaNum_CAD;
#endif
#if	ENABLE_PRESENTATION_MODE == ON    
    UCHAR ucGammaNum_Presentation;        
#endif
#if ENABLE_PICTURE_MODE_REC709 == ON                                   
    UCHAR ucGammaNum_Rec709;
#endif  
#if ENABLE_PICTURE_MODE_DARKROOM == ON                                   
    UCHAR ucGammaNum_DarkRoom;
#endif  
    UCHAR ucBF_HP;
    UCHAR ucBF_VP;
    UCHAR ucBF_Size;
    UCHAR ucBF_Brightness;
    UCHAR ucBF_Contrast;
    UCHAR ucECOMode;
    UCHAR ucOFFTime;
    UCHAR ucSharpness;
    UCHAR ucSharpness_sRGB;
    UCHAR ucSharpness_Standard;
    UCHAR ucSharpness_LBL_Mult;
    UCHAR ucSharpness_LBL_Web;    
    UCHAR ucSharpness_LBL_Office;
    UCHAR ucSharpness_LBL_Read;
#if ENABLE_PICTURE_MODE_MOVIE== ON                             
    UCHAR ucSharpness_Movie;
#endif
#if ENABLE_PICTURE_MODE_GAME == ON                         
    UCHAR ucSharpness_Game;
#endif
#if ENABLE_PICTURE_MODE_PHOTO== ON                             
    UCHAR ucSharpness_Photo;
#endif
    UCHAR ucSharpness_USER;
    UCHAR ucSharpness_MBOOK;    
#if	ENABLE_PICTURE_MODE_ANIMATION == ON    
    UCHAR ucSharpness_Animation;
#endif
#if	ENABLE_PICTURE_MODE_CAD == ON
    UCHAR ucSharpness_CAD;
#endif
#if	ENABLE_PRESENTATION_MODE == ON    
    UCHAR ucSharpness_Presentation;
#endif    
#if ENABLE_PICTURE_MODE_REC709 == ON                                   
    UCHAR ucSharpness_Rec709;
#endif  
#if ENABLE_PICTURE_MODE_DARKROOM == ON                                   
    UCHAR ucSharpness_DarkRoom;
#endif
    UCHAR ucEView;
    UCHAR ucDCBMode;
    UCHAR ucBrightAdj;
    UCHAR ucUserDefVideo;
    UCHAR ucUserDefAudio;
    UCHAR ucPIPSize;
    UCHAR ucPIPTrans;
#if ENABLE_3D_CNV == ON    
    UCHAR uc2DTo3DMode;
    UCHAR uc2Dto3DDepth;
    UCHAR uc2Dto3DView;
    UCHAR uc3DCfg;
#endif    

    UCHAR ucSRMode : 4;
#if ENABLE_PIP == ON
    UCHAR ucPIPSRMode : 4;
#endif
    UCHAR ucAudioSelect;
    UCHAR ucDPAudioSelect;
    UCHAR ucHDMIAudioSelect;
    UCHAR ucHue;
    UCHAR ucSaturation;
    UCHAR ucCustomerKey1;
    UCHAR ucCustomerKey2;
    UCHAR ucCustomerKey3;
    UCHAR ucAutoPowerOffTime;
    UCHAR ucLBLMode;
#if ENABLE_PICTURE_MODE_ANIMATION == ON
    UCHAR ucAnimationMode;
#endif
    UCHAR ucErgoTime;
    UCHAR ucErgoDuration;    
    USHRT usCurrModeHactive;
    USHRT usCurrModeVactive;
    USHRT usCurrModeVsync;
    USHRT usCurrModeIndex;
    USHRT usUsrEnd;
} NvramUserData;

/*!
 * Data type of calibration-related fields in NVRam.
 */
typedef struct _NVRAM_CAL_DATA_ {
    UCHAR ucADCRGain;
    UCHAR ucADCGGain;
    UCHAR ucADCBGain;
    UCHAR ucADCROffset;
    UCHAR ucADCGOffset;
    UCHAR ucADCBOffset;
    UCHAR uc5000KRGain;
    UCHAR uc5000KGGain;
    UCHAR uc5000KBGain;
    UCHAR uc5800KRGain;
    UCHAR uc5800KGGain;
    UCHAR uc5800KBGain;        
    UCHAR uc6500KRGain;
    UCHAR uc6500KGGain;
    UCHAR uc6500KBGain;
    UCHAR uc7500KRGain;
    UCHAR uc7500KGGain;
    UCHAR uc7500KBGain;
    UCHAR uc8200KRGain;
    UCHAR uc8200KGGain;
    UCHAR uc8200KBGain;
    UCHAR uc9300KRGain;
    UCHAR uc9300KGGain;
    UCHAR uc9300KBGain;
    UCHAR uc11500KRGain;
    UCHAR uc11500KGGain;
    UCHAR uc11500KBGain;
    UCHAR ucsRGBRGain;
    UCHAR ucsRGBGGain;
    UCHAR ucsRGBBGain;
    UCHAR ucVcomValue;  
#if ENABLE_NVT_FGA == ON    
    UCHAR ucFGADone;
    UCHAR ucFGACkSumH;
    UCHAR ucFGACkSumL;
#endif    
    USHRT usCalEnd;
} NvramCalibData;

/*!
 * Data type of system-related fields in NVRam.
 */
typedef struct _NVRAM_SYS_DATA_ {
	UCHAR bFactory:1;
    UCHAR bBurnIn : 1;
    UCHAR bShowLogo : 1;    
    UCHAR bEnableOnOffHPD : 1;
    UCHAR bHDMI_PRETEST : 1;    
    UCHAR bDemo: 1;
    UCHAR bDFR: 1;
    UCHAR bSR: 1;
    UCHAR bClear_EE : 1;
    UCHAR bEDID_WP : 1;
    UCHAR bClear_Timer :1;

    //For BENQ Service Menu
    UCHAR bHDMI_HPD : 1;
    UCHAR bDP_HPD : 1;
    UCHAR bDVI_HPD : 1;
    UCHAR bAutoPower : 1;
    UCHAR bCable : 1;    
    //For BENQ Service Menu    
    UCHAR SN_len;
    UCHAR ucSN[19];
    UCHAR ucPowerOnTimerM;
    USHRT usPowerOnTimerH;
    UCHAR ucMonitorPowerOnTimerM;
    USHRT usMonitorPowerOnTimerH;    
    UCHAR ucPOTimerM_FE2P;
    USHRT usPOTimerH_FE2P;
    UCHAR ucTimingWriteIdx;
    USHRT usFirmwareVer; //Firmware version.
    USHRT usNvramID; //NVRAM is empty or not. This flag should be placed at the end of SystemData.
    USHRT usProductMode;
    USHRT usChkSum;
    USHRT usNVUsrSize;
    USHRT usNVCalSize;
    USHRT usNVSysSize;
    USHRT usSysEnd;
} NvramSystemData;

//******************************************************************************
// V A R I A B L E S   P R O T O T Y P E
//******************************************************************************
extern code NvramUserData UserDataDefault;
extern code NvramCalibData CalibDataDefault;
extern code NvramSystemData SystemDataDefault;

//******************************************************************************
// F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
void NvramWrite(USHRT addr, USHRT len, UCHAR *ptr);
void NvramRead(USHRT addr, USHRT len, UCHAR *ptr);
void NvramLoadData(void);
void NvramInitialize(UCHAR type);
void NvramClearTiming(void);
BOOL NvramReadTimingData(InputTimingFormat *ptr);
void NvramWriteTimingData(InputTimingFormat *ptr);
void NvramReadUserData(NvramUserData *ptr);
void NvramWriteUserData(NvramUserData *ptr);
void NvramReadCalibData(NvramCalibData *ptr);
void NvramWriteCalibData(NvramCalibData *ptr);
void NvramReadSystemData(NvramSystemData *ptr);
void NvramWriteSystemData(NvramSystemData *ptr);
void NvramDumpToSram(void);
void NvramWriteHDCPdata(UCHAR *ptr);
void NvramReadHDCPdata(UCHAR *ptr);
#if USE_INTERNAL_EDID == 1
void NvramSaveEDID(void);
void NvramLoadEDID(void);
#endif

#endif //__NVRAM_H__
