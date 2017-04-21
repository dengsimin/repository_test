/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/
#ifndef __BOARD_H__
#define __BOARD_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "BoardList.h"
#include "ModelCfg.h"

#if (BOARD_TYPE == NT68168_DEMO_BOARD)
#include "NT68168_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68650_DEMO_BOARD)
#include "NT68650_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68660_DEMO_BOARD)
#include "NT68660_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68660_MODULE_BOARD)
#include "NT68660_MODULE_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68668_DEMO_BOARD)
#include "NT68668_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68669_DEMO_BOARD)
#include "NT68669_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68671_DEMO_BOARD)
#include "NT68671_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68672_DEMO_BOARD)
#include "NT68672_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68673_DEMO_BOARD)
#include "NT68673_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68674_DEMO_BOARD)
#include "NT68674_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68675_DEMO_BOARD)
#include "NT68675_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68676_DEMO_BOARD)
#include "NT68676_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68677_DEMO_BOARD)
#include "NT68677_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68750_DEMO_BOARD)
#include "NT68750_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68750_MODULE_BOARD)
#include "NT68750_MODULE_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68776_DEMO_BOARD)
#include "NT68776_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68777_DEMO_BOARD)
#include "NT68777_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68778_DEMO_BOARD)
#include "NT68778_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68779_DEMO_BOARD)
#include "NT68779_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68750_DEMO_BOARD)
#include "NT68750_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68751_DEMO_BOARD)
#include "NT68751_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68752_DEMO_BOARD)
#include "NT68752_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68753_DEMO_BOARD)
#include "NT68753_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68360_DEMO_BOARD)
#include "NT68360_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68360_MODULE_BOARD)
#include "NT68360_MODULE_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68364_MODULE_BOARD)
#include "NT68364_MODULE_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68652_DEMO_BOARD)
#include "NT68652_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68652_MODULE_BOARD)
#include "NT68652_MODULE_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68169_DEMO_BOARD)
#include "NT68169_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68169_MODULE_BOARD)
#include "NT68169_MODULE_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68169_FPGA_BOARD)
#include "NT68169_FPGA_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68169_RA_BOARD)
#include "NT68169_RA_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68661_DEMO_BOARD)
#include "NT68661_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68661_MODULE_BOARD)
#include "NT68661_MODULE_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68661_FPGA_BOARD)
#include "NT68661_FPGA_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68785_DEMO_BOARD)
#include "NT68785_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68770_DEMO_BOARD)
#include "NT68770_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68770_MODULE_BOARD)
#include "NT68770_MODULE_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68771_MODULE_BOARD)
#include "NT68771_MODULE_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68772_MODULE_BOARD)
#include "NT68772_MODULE_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68773_MODULE_BOARD)
#include "NT68773_MODULE_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68774_MODULE_BOARD)
#include "NT68774_MODULE_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68775_DEMO_BOARD)
#include "NT68775_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68775_MODULE_BOARD)
#include "NT68775_MODULE_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68662_MODULE_BOARD)
#include "NT68662_MODULE_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68785_DEMO_BOARD)
#include "NT68785_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68785_MODULE_BOARD)
#include "NT68785_MODULE_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68850_DEMO_BOARD)
#include "NT68850_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68850_MODULE_BOARD)
#include "NT68850_MODULE_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68857_DEMO_BOARD)
#include "NT68857_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68857_MODULE_BOARD)
#include "NT68857_MODULE_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68859_DEMO_BOARD)
#include "NT68859_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68859_MODULE_BOARD)
#include "NT68859_MODULE_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68655_DEMO_BOARD)
#include "NT68655_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68655_MODULE_BOARD)
#include "NT68655_MODULE_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68150_FPGA_BOARD)
#include "NT68150_FPGA_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68150_DEMO_BOARD)
#include "NT68150_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68150_MODULE_BOARD)
#include "NT68150_MODULE_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68150_RA_BOARD)
#include "NT68150_RA_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68790_FPGA_BOARD)
#include "NT68790_FPGA_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68658_FPGA_BOARD)
#include "NT68658_FPGA_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68790_MODULE_BOARD)
#include "NT68790_MODULE_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68795_MODULE_BOARD)
#include "NT68795_MODULE_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68799_MODULE_BOARD)
#include "NT68799_MODULE_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68790_DEMO_BOARD)
#include "NT68790_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68795_DEMO_BOARD)
#include "NT68795_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68799_DEMO_BOARD)
#include "NT68799_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68790_RA_BOARD)
#include "NT68790_RA_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68658_DEMO_BOARD)
#include "NT68658_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68658_MODULE_BOARD)
#include "NT68658_MODULE_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68658_RA_BOARD)
#include "NT68658_RA_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68810_FPGA_BOARD)
#include "NT68810_FPGA_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68810_MODULE_BOARD)
#include "NT68810_MODULE_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68810_MODULE_BOARD_2H)
#include "NT68810_MODULE_BOARD_2H\BoardConfig.h"
#elif (BOARD_TYPE == NT68810_MODULE_BOARD_2DP)
#include "NT68810_MODULE_BOARD_2DP\BoardConfig.h"
#elif (BOARD_TYPE == NT68810_MODULE_BOARD_80L)
#include "NT68810_MODULE_BOARD_80L\BoardConfig.h"
#elif (BOARD_TYPE == NT68810_MODULE_BOARD_80A)
#include "NT68810_MODULE_BOARD_80A\BoardConfig.h"
#elif (BOARD_TYPE == NT68810_DEMO_BOARD)
#include "NT68810_DEMO_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68810_DEMO_BOARD_2H)
#include "NT68810_DEMO_BOARD_2H\BoardConfig.h"
#elif (BOARD_TYPE == NT68870_FPGA_BOARD)
#include "NT68870_FPGA_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68870_MODULE_BOARD)
#include "NT68870_MODULE_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68860_MODULE_BOARD)
#include "NT68860_MODULE_BOARD\BoardConfig.h"
#elif (BOARD_TYPE == NT68890_DEMO_BOARD)
#include "NT68890_DEMO_BOARD\BoardConfig.h"
#else
#error "Unknown board type! Please define board type in model config file."
#endif

#include "BoardVerify.h"

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
extern BOOL bIsCableConnect(void);
extern BOOL bIsVGAConnect(void);
extern BOOL IsDigital3Connect(void);
extern BOOL IsDigital2Connect(void);
extern BOOL IsDigital1Connect(void);
extern BOOL IsDigital0Connect(void);
extern BOOL IsDPConnect(void);
extern BOOL IsDP1Connect(void);
extern BOOL IsDP2Connect(void);
extern BOOL IsDP3Connect(void);
extern BOOL IsPanelPowerOn(void);
extern void LedGreenOn(void);
extern void LedGreenOff(void);
extern void LedRedOn(void);
extern void LedRedOff(void);
extern void PanelPowerOn(void);
extern void PanelPowerOff(void);
extern void BacklightOn(void);
extern void BacklightOff(void);
#if ENABLE_ESD_PROTECT == ON
extern BOOL IsBackLightOn(void);
#endif
extern void AudioPowerOn(void);
extern void AudioPowerOff(void);
extern void AudioMuteOff(void);
extern void AudioMuteOn(void);
extern void EdidWPOn(void);
extern void EdidWPOff(void);
extern void PowerMOSOn(void);
extern void PowerMOSOff(void);
extern void Digi3HPDOn(void);
extern void Digi3HPDOff(void);
extern void Digi2HPDOn(void);
extern void Digi2HPDOff(void);
extern void Digi1HPDOn(void);
extern void Digi1HPDOff(void);
extern void Digi0HPDOn(void);
extern void Digi0HPDOff(void);
extern void DPHPDOn(void);
extern void DPHPDOff(void);
extern void DP1HPDOn(void);
extern void DP1HPDOff(void);
extern void DP2HPDOn(void);
extern void DP2HPDOff(void);
extern void DP3HPDOn(void);
extern void DP3HPDOff(void);
extern BOOL bIsHPDActive(void);
extern void ConfigHPD(void);
extern void AUXPNSwapOn(void);
extern void AUXPNSwapOff(void);
extern void BillBoardEnableOn(void);
extern void BillBoardEnableOff(void);
extern BOOL IsBackLightOn(void);

#endif //__BOARD_H__
