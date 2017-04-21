/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/
#ifndef __INCLUDE_H__
#define __INCLUDE_H__

#define  lrd_dis     1
#define  lrd_change_scaler_code 1
#define  lrd_dis_benq     1
#define  lrd_test    1 //并没有从根源解决


#define DWE_FILTER_BLUE 1
#define USE_ASCII        1
#define PWR_AUTO_INTO_FAC 0
#define EN_FACTORYALIGNMENT 1
//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include <intrins.h>
#include <math.h>
#include <stdio.h>
#include "3D.h"
#include "APPCtrl.h"
#include "AutoAdj.h"
#include "AutoAdjConfig.h"
#include "Board.h"
#include "CEC.h"
#include "ColorConfig.h"
#include "ColorEngine.h"
#include "Component.h"
#include "Ddcci.h"
#include "DdcciCtrl.h"
#include "Event.h"
#include "EventHandle.h"
#include "FOSDView.h"
//#include "DemoOSDView.h"
#include "InputTiming.h"
#include "Int.h"
#include "KeyCtrl.h"
#include "KeyPad.h"
#include "Logo.h"
#include "Mcu.h"
#include "McuAPI.h"
#include "McuReg.h"
#include "Misc.h"
#include "ModeConfig.h"
#include "ModeHandler.h"
#include "ModeSearch.h"
#include "ModeTable.h"
#include "ModelCfg.h"
#include "NR.h"
#include "Nvram.h"
#include "NvramIIC.h"
#include "OSDAPI2.h"
#include "OSDConfig.h"

#include "OSDAPI.h"
#include "OSDAPI_Common.h"
#include "OSDAPI_Indent.h"


#include "OSDCtrl.h"
#include "OSDFont.h"
#include "OSDFunc.h"
#include "OSDIndex.h"
#include "OSDIndex2.h"
#include "OSDIndex3.h"

#include "OSDType.h"
#include "OSDView.h"
#include "OSDView2.h"
#include "OSDView3.h"

#include "Panel.h"
#include "Ram.h"
#include "Scaler.h"
#include "ScalerAccess.h"
#include "ScalerReg.h"
#include "SyncHandler.h"
#include "SysAPI.h"
#include "Typedef.h"
#include "UserDefault.h"
#include "UserSetting.h"
#include "Utilities.h"

#include "FOSDView_AOC\SMOSDView.h"
//Optional Header Files
#if ENABLE_DBC == ON
#include "DBCAPI.h"
#include "DBC.h"
#endif
#if ENABLE_EMBEDDED_CHECKSUM == ON
#include "EmbedCheckSum.h"
#endif
#if ENABLE_FE2P == ON
#include "FE2P_API.h"
#endif
#if ENABLE_GAMMA == ON
#include "GammaAPI.h"
#include "Gamma.h"
#endif
#if ENABLE_HDCP == ON
#include "HDCPAPI.h"
#include "HDCP.h"
#endif
#if ENABLE_LD == ON
#include "LDAPI.h"
#include "LD.h"
#endif
#if ENABLE_OD == ON
#include "ODAPI.h"
#include "OD.h"
#endif
#if ENABLE_SR == ON
#include "SRAPI.h"
#include "SR.h"
#endif
#if ENABLE_OD_TRANSFORM == ON
#include "ODTransform.h"
#endif
#if ENABLE_EDP == ON
#include "EDP.h"
#endif
#if IS_NT68870_SERIES//ENABLE_POSTFRC == ON || ENABLE_AUTOFRAMEDOWN == ON || ENABLE_CENTER_MODE == ON
#include "Scaler_FRC.h"
#endif
#if (INPUT_INTERFACE&INPUT_MHL_MASK) 
#include "MHL.h"
#endif
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1)
#include "Scaler_DP_Common.h"
#include "Scaler_DP.h"
#endif
#if defined(ENABLE_FPGA_MODE)
#include "AD9884.h"
#endif
#if ENABLE_USB_TYPE_C == ON
#include "USBTypeC.h"
#include "USBTypeCHandler.h"
#endif
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
// E X T E R N A L   V A R I A B L E   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// S T A T I C   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************

#endif //__INCLUDE_H__
