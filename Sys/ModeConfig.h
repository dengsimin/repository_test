/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/

#ifndef __MODECONFIG_H__
#define __MODECONFIG_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "Typedef.h"

//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************
#define BEST_RESOLUTION_VGA ( (InputTiming.usModeHActive==1920)&&(InputTiming.usModeVActive==1080)&&(abs(InputTiming.usVSyncFreq-600)<12) )
#define BEST_RESOLUTION_DIG ( (InputTiming.usModeHActive==PANEL_WIDTH)&&(InputTiming.usModeVActive==PANEL_HEIGHT)&&(abs(InputTiming.usVSyncFreq-600)<12) )

//******************************************************************************
// D A T A   T Y P E   D E F I N E S
//******************************************************************************

//******************************************************************************
// V A R I A B L E S   P R O T O T Y P E
//******************************************************************************

//******************************************************************************
// F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
BOOL ModeConfig(void);
BOOL IsComponentInput(void);
BOOL IsPreSetModeTiming(void);
BOOL IsVideoTiming(void);
BOOL IsOutOfRange(void);
void SetMinMax(void);
void SetOverScanRatio(UCHAR ratio);
void SetVGAOverScanRatio(UCHAR ratio);
void CheckOverScan(void);
void UpdateCaptureInfo(void);
BOOL isOnlyFullAspectRatio(void);
UCHAR DetectAspectRatio(void);
BOOL IsComponentTiming(void);
BOOL IsHDMIVideoTiming(void);
BOOL IsNativeTiming(void);
#endif //__MODECONFIG_H__
