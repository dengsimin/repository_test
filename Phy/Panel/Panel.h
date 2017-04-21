/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/
#ifndef __PANEL_H__
#define __PANEL_H__

//******************************************************************************
// G L O B A L   D E F I N I T I O N S
//******************************************************************************
// Panel vendor list
#define AUO 0x10
#define CMO 0x20
#define CPT 0x30
#define INL 0x40
#define IVO 0x50
#define LPL 0x60
#define SEC 0x70
#define TPV 0x80
#define BOE 0x90
#define NVT 0xF0
// Pane resolution list
#define RES_1024X768  0x01
#define RES_1280X1024 0x02
#define RES_1366X768  0x03
#define RES_1400X1050 0x04
#define RES_1440X900  0x05
#define RES_1600X900  0x06
#define RES_1680X1050 0x07
#define RES_1920X1080 0x08
#define RES_1920X1200 0x09
#define RES_2560X1440 0x0A

#define PANEL_VENDOR  (PANEL_TYPE&0xF0)
#define IS_AUO_PANEL  ((PANEL_TYPE&0xF0) == AUO)
#define IS_CMO_PANEL  ((PANEL_TYPE&0xF0) == CMO)
#define IS_CPT_PANEL  ((PANEL_TYPE&0xF0) == CPT)
#define IS_INL_PANEL  ((PANEL_TYPE&0xF0) == INL)
#define IS_IVO_PANEL  ((PANEL_TYPE&0xF0) == IVO)
#define IS_LPL_PANEL  ((PANEL_TYPE&0xF0) == LPL)
#define IS_SEC_PANEL  ((PANEL_TYPE&0xF0) == SEC)
#define IS_TPV_PANEL  ((PANEL_TYPE&0xF0) == TPV)
#define IS_BOE_PANEL  ((PANEL_TYPE&0xF0) == BOE)
#define IS_NVT_PANEL  ((PANEL_TYPE&0xF0) == NVT)

#define PANEL_RESOLUTION   (PANEL_TYPE&0x0F)
#define IS_1024X768_PANEL  ((PANEL_TYPE&0x0F) == RES_1024X768 )
#define IS_1280X1024_PANEL ((PANEL_TYPE&0x0F) == RES_1280X1024)
#define IS_1366X768_PANEL  ((PANEL_TYPE&0x0F) == RES_1366X768 )
#define IS_1400X1050_PANEL ((PANEL_TYPE&0x0F) == RES_1400X1050)
#define IS_1440X900_PANEL  ((PANEL_TYPE&0x0F) == RES_1440X900 )
#define IS_1600X900_PANEL  ((PANEL_TYPE&0x0F) == RES_1600X900 )
#define IS_1680X1050_PANEL ((PANEL_TYPE&0x0F) == RES_1680X1050)
#define IS_1920X1080_PANEL ((PANEL_TYPE&0x0F) == RES_1920X1080)
#define IS_1920X1200_PANEL ((PANEL_TYPE&0x0F) == RES_1920X1200)
#define IS_2560X1440_PANEL ((PANEL_TYPE&0x0F) == RES_2560X1440)

#define PANEL_INSERT_BLACK          0x01
#define PANEL_INSERT_WHITE          0x02
#define PANEL_POWER_LVDS_SWAP       0x04
#define PANEL_PWR_SEQ_DEFAULT       0xFF


//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
// AUO Panel List
#if defined(AUO_M185XW01_V0)
#include "AUO_M185XW01_V0\Panel.h"
#elif defined(AUO_M190EG02_V4)
#include "AUO_M190EG02_V4\Panel.h"
#elif defined(AUO_M201EW02)
#include "AUO_M201EW02\Panel.h"
#elif defined(AUO_M215HW01_V0)
#include "AUO_M215HW01_V0\Panel.h"
#elif defined(AUO_M220EW01_V0)
#include "AUO_M220EW01_V0\Panel.h"
#elif defined(AUO_RDT271WLM)
#include "AUO_RDT271WLM\Panel.h"
#elif defined(AUO_M220EW01_V0)
#include "AUO_M220EW01_V0\Panel.h"
#elif defined(AUO_M215HW01_V6)
#include "AUO_M215HW01_V6\Panel.h"
#elif defined(AUO_M215HW01_VB)
#include "AUO_M215HW01_VB\Panel.h"
#elif defined(AUO_M240HW01_VB)
#include "AUO_M240HW01_VB\Panel.h"
#elif defined(AUO_M240HW02_V1)
#include "AUO_M240HW02_V1\Panel.h"
#elif defined(AUO_M240HW02_V7)
#include "AUO_M240HW02_V7\Panel.h"
#elif defined(AUO_M270HTN01_0)
#include "AUO_M270HTN01_0\Panel.h"
#endif

// CMO Panel List
#if defined(CMO_M185B3_LA1)
#include "CMO_M185B3_LA1\Panel.h"
#elif defined(CMO_M201P1_L03_C1)
#include "CMO_M201P1_L03_C1\Panel.h"
#elif defined(CMO_M215H1_L01)
#include "CMO_M215H1_L01\Panel.h"
#elif defined(CMO_M236H1_L01)
#include "CMO_M236H1_L01\Panel.h"
#elif defined(CMO_M260J3_L01)
#include "CMO_M260J3_L01\Panel.h"
#elif defined(CMO_M236HGJ_L11)
#include "CMO_M236HGJ_L11\Panel.h"
#elif defined(CMI_M220Z3_LA3)
#include "CMI_M220Z3_LA3\Panel.h"
#elif defined(CMI_M236H3_LA3)
#include "CMI_M236H3_LA3\Panel.h"
#endif

// CPT Panel List

// INL Panel List
#if defined(INL_MT190AW01)
#include "INL_MT190AW01\Panel.h"
#elif defined(INL_MT215DW01_V1)
#include "INL_MT215DW01_V1\Panel.h"
#endif

// IVO Panel List

// LPL Panel List
#if defined(LPL_LM170E03)
#include "LPL_LM170E03\Panel.h"
#endif

// SEC Panel List
#if defined(SAM_LTM220M2_L01)
#include "SAM_LTM220M2_L01\Panel.h"
#elif defined(SAM_LTM230HT05_M01)
#include "SAM_LTM230HT05_M01\Panel.h"
#elif defined(SAM_LTM270HU01_V)
#include "SAM_LTM270HU01_V\Panel.h"
#elif defined(SAM_LTM270DL02)
#include "SAM_LTM270DL02\Panel.h"
#elif defined(SAM_M236HGE_L10)
#include "SAM_M236HGE_L10\Panel.h"
#elif defined(SAM_LTM270HGE_L20)
#include "SAM_LTM270HGE_L20\Panel.h"
#endif

// LG Panel List
#if defined(LM230WF5_TRA2_2)
#include "LM230WF5_TRA2_2\Panel.h"
#elif defined(LG_JV_LM215WF4)
#include "LG_JV_LM215WF4\Panel.h"
#elif defined(LGD_LM230WF5_TLD3)
#include "LGD_LM230WF5_TLD3\Panel.h"
#elif defined(LG_LM215WF4_TLE1)
#include "LG_LM215WF4_TLE1\Panel.h"
#endif

// NVT Demo Panel List
#if defined(NVT_1920X1200)
#include "NVT_1920X1200\Panel.h"
#elif defined(NVT_1920X1080)
#include "NVT_1920X1080\Panel.h"
#elif defined(NVT_1920X1080_eDP)
#include "NVT_1920X1080_eDP\Panel.h"
#elif defined(NVT_1680X1050)
#include "NVT_1680X1050\Panel.h"
#elif defined(NVT_1600X900)
#include "NVT_1600X900\Panel.h"
#elif defined(NVT_1440X900)
#include "NVT_1440X900\Panel.h"
#elif defined(NVT_1366X768)
#include "NVT_1366X768\Panel.h"
#elif defined(NVT_1920X1080_FP)
#include "NVT_1920X1080_FP\Panel.h"
#elif defined(NVT_2560X1440_FP)
#include "NVT_2560X1440_FP\Panel.h"
#elif defined(LVIEW_2560X1440)
#include "LVIEW_2560X1440\Panel.h"

#endif

#ifndef PANEL_TYPE
#error "Please choose one panel at least!"
#endif
#if (PANEL_MIN_VTOTAL <= (PANEL_HEIGHT + PANEL_VSYNC_WIDTH + PANEL_VSYNC_BACKPORCH))
#error "Wrong PanelVTotal setting! Please review it!"
#endif

#ifndef PANEL_FOUR_PORT_LVDS
#define PANEL_FOUR_PORT_LVDS 0
#endif
#ifndef PANEL_LVDS_OFFSET
#define PANEL_LVDS_OFFSET 0
#endif
#ifndef PANEL_TEN_BIT_SHIFT
#define PANEL_TEN_BIT_SHIFT 0
#endif
#ifndef PANEL_FOUR_PORT_SWAP
#define PANEL_FOUR_PORT_SWAP 0
#endif
#ifndef PANEL_PWR_OFF_SEQUENCE_MODE
#define PANEL_PWR_OFF_SEQUENCE_MODE   PANEL_INSERT_WHITE
#endif
#ifndef VCOM_IIC
#define VCOM_IIC                OFF //ON/OFF
#endif
#if ENABLE_SCALER_NEW_SSC == ON
#ifdef PANEL_DCLK_NEW_SSC
#undef PANEL_DCLK_SSC
#define PANEL_DCLK_SSC PANEL_DCLK_NEW_SSC
#endif
#endif

typedef struct {
    UCHAR ucLVDS_Swing : 5;
    UCHAR bDualPortLVDS : 1;
    UCHAR bEnableSSC : 1;
    UCHAR bDEMode : 1;
    UCHAR bPortSwap : 1;
    UCHAR bBitShift : 1;
    UCHAR ucColorDepth;
    USHRT usWidth;
    USHRT usHeight;
    ULONG ulMinPClk;
    ULONG ulMaxPClk;
    USHRT usMinHTotal;
    USHRT usTypHTotal;
    USHRT usMaxHTotal;
    USHRT usMinHSyncWidth;
    USHRT usMinHSyncBackPorch;
    USHRT usMinVTotal;
    USHRT usTypVTotal;
    USHRT usMaxVTotal;
    USHRT usMinVSyncWidth;
    USHRT usMinVSyncBackPorch;
    ULONG ulFreeRunH_Freq;
    USHRT usPowerUpPanelTime;
    USHRT usPowerUpInvTime;
    USHRT usPowerDownPanelTime;
    USHRT usPowerDownInvTime;
    USHRT usPowerOffOnPanelTime;
    UCHAR ucSpreadSpectrumCtrl;
} PanelData;

//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************
extern code PanelData PanelDataDefault;

#endif //__PANEL_H__
