/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/
#ifndef __FOSDVIEW_H__
#define __FOSDVIEW_H__
//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "Typedef.h"
#include "OSDFont.h"
#include "Panel.h"

//******************************************************************************
// G L O B A L   D E F I N I T I O N S
//******************************************************************************
#define E_SAVE_FUNC                 OFF//ON
#define FOSD_ENE_RAW_CNT_DEBUG      OFF
#define TPV_SET_SSC_CTRL  OFF
#define TPV_SET_LVDS_SWING OFF
#define TPV_CLEAR_EE  OFF
#define TPV_EDID_WP_ONOFF  OFF
#define TPV_CLEAR_TIMER  OFF

#define ShowMsgEnergystarLogo       OFF
#define DDCCI_RETURNCMD             OFF



#define OSD_FACTORY_W 22
#if ENABLE_ECO_EYE_SENSOR == ON
#define OSD_FACTORY_H 27
#else
#define OSD_FACTORY_H 26
#endif

#define OSD_PanelSetting_W 26


//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************
enum FactoryOSDType {
FOSDOff,
FOSDPage1,    
FOSDPage2
};

enum OSD_FACTORY {
    mfAUTO,
    mfADC_GAIN_R,mfADC_GAIN_G,mfADC_GAIN_B,

    mfADC_OFFSET_R,mfADC_OFFSET_G,mfADC_OFFSET_B,
    
    mf5800_GAIN_R,mf5800_GAIN_G,mf5800_GAIN_B,
//    fmWARM_BR,fmWARM_CO,
    mfCOOL_GAIN_R,mfCOOL_GAIN_G,mfCOOL_GAIN_B,
//    fmCOOL_BR,fmCOOL_CO,
    mfUSER_GAIN_R,mfUSER_GAIN_G,mfUSER_GAIN_B,
//    fmUSER_BR,fmUSER_CO,
    mfSRGB_GAIN_R,mfSRGB_GAIN_G,mfSRGB_GAIN_B,
//    fmSRGB_BR,fmSRGB_CO,
    mf6500_GAIN_R, mf6500_GAIN_G, mf6500_GAIN_B,
    mfNORMAL_BR, mfNORMAL_CO,
#if PANEL_CONTROL == ON
    mfPANEL_SETTING,
#endif
    mfDFM,
    mfBURNING,
#if VCOM_IIC == ON
    mfVCOM,
#endif
#if ENABLE_HDMI == ON
    mfHDMI_PRETEST,
#endif
//    fmINFO,
//    fmEMI,   
#if 0//ENABLE_OD
    mfOD,
#endif
#if TPV_SET_SSC_CTRL == ON
    mfSSC_FREQ,
    mfSSC_RATIO,
#endif
#if TPV_SET_LVDS_SWING == ON
    mfLVDS_SETTING,
#endif
#if TPV_CLEAR_EE == ON
    mfCLEAR_EE,
#endif
#if TPV_EDID_WP_ONOFF == ON
    mfEDID_WP,
#endif
#if TPV_CLEAR_TIMER == ON
    mfCLEAR_TIMER,
#endif
    mfRETURN,
    mfPOT

};

#if PANEL_CONTROL == ON
#define UP_Action  0x00
#define Down_Action  0x01

enum FactoryOSD_Level_Panel 
{
    fmDepth,
    fmOn_T1,                               fmOn_T2,                    // 1
    fmOff_T1,                               fmOff_T2,                   // 2
    fmHSycn_Width,                    fmHSycn_Bporch,       
    fmVSycn_Width,                    fmVSycn_Bporch,
    fmWidth,                                fmHeight,
    fmTypHTotal,                         fmTypVTotal,
    fmMaxHTotal,                        fmMaxVTotal,
    fmMinHTotal,                         fmMinVTotal,
  //  fmLowHTotal,                        
  //  fmLowVTotal,
    fmMinDclk,                             fmMaxDclk,
    fmMinVFreq,                          fmMaxVFreq,
    fmMaxHFreq,                         fmFreeRunHFreq,
    fmTwoPixel,                           fmSyncDE,
    fmSSCEn,                                fmSSCCtrl,                   
    fmBrightnessMaxDuty,           fmBrightnessMinDuty,
    fmSwing,
    fmInitial,                                fmSave,
    fmReturnP,                                                                  // 19
    fmEnd,
};
#endif
//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************

//******************************************************************************
// E X T E R N A L   V A R I A B L E   P R O T O T Y P E S
//******************************************************************************
extern xdata UCHAR ucFactoryIndex;
extern UCHAR ucFOSDType;
//******************************************************************************
// S T A T I C   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
#if FOSD_ENE_RAW_CNT_DEBUG == ON    //20130715_1006_OSD#1
extern USHRT usEnEMaxSignal[6];
extern USHRT usEnESignal[6];
extern USHRT usENEdelta[6];
#endif

void FOSDInit(void);
void OSDShowFactory(void);
void OSDFactoryUp(void);
void OSDFactoryDown(void);
void OSDFactoryEnterItm(void);
void OSDFactoryExitItm(void);
void OSDFactoryItmUp(void);
void OSDFactoryItmDown(void);
void FOSDInitFrame(UCHAR osdw, UCHAR osdh, USHRT clr);
void OSDShowFactoryPanelSetting(void);
void FactoryShowALS_PXS(void);
extern void FactoryOSDShowNum(UCHAR x, UCHAR y, USHRT value);
#endif//__FOSDVIEW_H__
