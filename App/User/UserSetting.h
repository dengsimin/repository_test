/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/
#ifndef __USER_SETTING_H__
#define __USER_SETTING_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "Typedef.h"
extern xdata UCHAR bOSDAdjust;  

//******************************************************************************
// G L O B A L   D E F I N I T I O N S
//******************************************************************************

enum{
    PICTURE_DUALMODE_ONOFF,    
    PICTURE_DUALMODE_SRGB,                       //SRGB
#if	ENABLE_PICTURE_MODE_CAD == ON
    PICTURE_DUALMODE_CAD,                       //CAD
#endif        
#if	ENABLE_PICTURE_MODE_ANIMATION == ON
    PICTURE_DUALMODE_Animation,                       //Animation
#endif     
    PICTURE_DUALMODE_LBL,                       //LBL
#if	ENABLE_PICTURE_MODE_DARKROOM == ON
    PICTURE_DUALMODE_DARKROOM,                       //DARKROOM
#endif  
    PICTURE_DUALMODE_USER,                       //User
    PICTURE_DUALMODE_NUM,
};
enum {
    AUDIOSRC_PC,
 #if 1//OSDTYPE == OSD_BENQ_V1 || OSDTYPE == OSD_BENQ_V2
    AUDIOSRC_DP,
 #endif
    AUDIOSRC_HDMI,
    AUDIOSRC_AUTO,
    NUM_AUDIOSELECT,
};
enum {
        PICTURE_DUALMODE_ON,
        PICTURE_DUALMODE_OFF,
        PICTURE_DUALMODE_ITEM_NUM,    
};

#define CheckMaxRange(a,b) {if (a > b) a = b;}

//============================benq end=====================//
#define INPUT_SC_VGA    	    0
#define INPUT_SC_VGA1   	    1
#define INPUT_SC_DVI    	    2
#define INPUT_SC_DVI1   	    3
#define INPUT_SC_HDMI   	    4
#define INPUT_SC_HDMI1  	    5
#define INPUT_SC_HDMI2  	    6
#define INPUT_SC_HDMI3  	    7
#define INPUT_SC_HDMI4  	    8
#define INPUT_SC_YPbPr  	    9
#define INPUT_SC_YPbPr1 	   10
#define INPUT_SC_DP            11 
#define INPUT_SC_DP1           12
#define INPUT_SC_DP2           13
#define INPUT_SC_DP3           14
#define NUM_INPUT_SC    	   15
#define INPUT_SC_NULL   	   16
enum OD_Level{
    OD_OFF,
    OD_High,
    OD_Premium,
    OD_NUM
};

enum {
    COLOR_BEG,
    COLOR_AUTO = COLOR_BEG,
    COLOR_FULL ,    
    COLOR_LIMIT,
    COLOR_END = COLOR_LIMIT,
    COLOR_RANGE_NUM
};
#if 0
enum {
		OSDLANG_ENGLISH,  // 1
		OSDLANG_SPANISH, // 2
		OSDLANG_FRENCH,   // 3
		OSDLANG_GERMAN,  // 4
		OSDLANG_ITALIAN,   //5
		OSDLANG_PORTUGUESE,// 6
		OSDLANG_RUSSIAN, // 7
		OSDLANG_SCHINESE,// 8
		OSDLANG_TURKISH,// 9
		OSDLANG_DUTCH,// A
		OSDLANG_SWEDISH,// B
		OSDLANG_FINNISH,// C
		OSDLANG_POLISH,// D
		OSDLANG_CZECH,// E
		OSDLANG_KOREAN,// F
		OSDLANG_TSCHINESE,// G
		OSDLANG_JAPANESE,// H
		OSDLANG_HUNGARIAN,// I
		OSDLANG_GREEK,//J
		OSDLANG_UKRAINIAN,//K
		#if 0
		OSDLANG_BRAZIL,//L
		#else
		OSDLANG_ARAB,
		#endif
		NUM_OSDLANGS
};
#endif


enum {
    DSP_SIZE_FULL,
    DSP_SIZE_43,
    DSP_SIZE_1By1,    
    DSP_SIZE_SMART,
    DSP_SIZE_SMART_43,
    NUM_DSP_SIZE
};

enum {
    BKL_CTRL_OFF,
    BKL_CTRL_DCR,
    BKL_CTRL_DBC,    
	NUM_BKL_CTRL_SIZE,
};
/*
enum {
    INPUT_SC_VGA,
    INPUT_SC_DVI,
    INPUT_SC_HDMI,
    INPUT_SC_YPbPr,
    INPUT_SC_DISPLAYPORT,
    NUM_INPUT_SC
};
*/
enum {
    THR_D_CNV_OFF,
    THR_D_CNV_2D_TO_3D,
    THR_D_CNV_SIDEBYSIDE,
    THR_D_CNV_TOPBOT,
    THR_D_CNV_FRAME_SEQ,
    NUM_THR_D_CNV
};

#define GetBrightness1023() (Remap100ToAny(UserData.ucBrightness, 1023 - MIN_BACKLIGHT_VALUE) + MIN_BACKLIGHT_VALUE)
#define GetContrast255()   (Remap100To200(UserData.ucContrast) + MIN_CONTRAST_VALUE)
#define GetROffset255() (Remap100To200(UserData.ucUserROffset) + MIN_OFFSET_VALUE)
#define GetGOffset255() (Remap100To200(UserData.ucUserGOffset) + MIN_OFFSET_VALUE)
#define GetBOffset255() (Remap100To200(UserData.ucUserBOffset) + MIN_OFFSET_VALUE)
#define GetRGain255() (Remap100ToAny(UserData.ucUserRGain,(255-MIN_GAIN_VALUE)) + MIN_GAIN_VALUE)
#define GetGGain255() (Remap100ToAny(UserData.ucUserGGain,(255-MIN_GAIN_VALUE)) + MIN_GAIN_VALUE)
#define GetBGain255() (Remap100ToAny(UserData.ucUserBGain,(255-MIN_GAIN_VALUE)) + MIN_GAIN_VALUE)


//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
extern UCHAR LangPointToItem(UCHAR ucPoint);
extern UCHAR LangItemToPoint(UCHAR ucItem);
extern UCHAR GetLangTotalNum(void);
extern void UserSetBrightness(void);
extern void UserSetContrast(void);
extern void UserSetPhase(void);
extern void UserSetPhase100(UCHAR value);
extern void UserSetClock(void);
extern void UserSetClock100(UCHAR value);
extern void UserSetHPosition(void);
extern void UserSetHPosn100(UCHAR value);
extern void UserSetVPosition(void);
extern void UserSetVPosn100(UCHAR value);
extern void UserSetADCGainOffset(void);
extern void UserSetColorTemp(void);
extern void UserSetRGain(void);
extern void UserSetGGain(void);
extern void UserSetBGain(void);
extern void UserSetROffset(void);
extern void UserSetGOffset(void);
extern void UserSetBOffset(void);
extern void UserSetOSDH(void);
extern void UserSetOSDV(void);
extern void UserSetTransparent(void);
extern void UserSetTimeout(void);
extern void UserSetOSDRotation(void);
extern void UserSetLanguage(void);
extern void UserSetVolume(void);
extern void UserSetAudioMute(void);
extern void UserSetDCR(void);
extern void UserSetLD(void);
extern void UserSetAspectRatio(void);
extern void UserSetOverScan(void);
extern void UserSetGamma(void);
extern void UserSetOD(void);
extern void UserRecallConfiguration(void);
extern void UserRecallColor();
extern void UserRecallHVPosition(void);
extern void UserPerformAutoTune(void);
extern void UserSetBF(void);
extern void UserSetSR(void);
extern void UserSet2DTo3DMode(void);
extern void UserSet2DTo3DAdaptive(void);
extern void UserSet2DTo3DDepth(void);
extern void UserSet2DTo3DView(void);
extern void UserSet3DLRSwap(void);
extern void UserSet3DTo2D(void);
extern void UserSetInputSource(void);
extern void UserSetAudioChannel(void);
extern UCHAR UserGetInputSource(void);
extern UCHAR UserGetNormalPhase(void);
extern UCHAR UserGetNormalClock(void);
extern UCHAR UserGetNormalHPosn(void);
extern UCHAR UserGetNormalVPosn(void);
extern UCHAR UserGetNormal2DTo3DDpth(void);
extern UCHAR UserGetNormal2DTo3DView(void);
extern UCHAR GetInputPortName(UCHAR PortIdex);
extern UCHAR GetInputPortIndex(UCHAR PortName);
extern void UserSetDualView(BOOL DUALMODEONOFF, UCHAR SETDUALVIEW);
extern UCHAR DualViewPointoBFMode(UCHAR DUALVIEW);
extern void SetAspRatioSetting(void);
extern void GetAspRatioSetting(void);
extern void UserSetVolumeAndMute(void);
extern void UserGetSmartReminderTimer(void);
extern void UserSetAutoPowerOffTimer(void);
extern void UserSetSharpness(void);
extern void UserSetColorReset(void);
extern void UserSetDDCCI(void);
extern void UserSetDBC(void);
extern BOOL IsShowResolutionNotice(void);
extern void CurrentTimingSaved(void);
extern BOOL IsTimingChanged(void);


#endif //__USER_SETTING_H__
