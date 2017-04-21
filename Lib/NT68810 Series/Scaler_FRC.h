/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/

#ifndef __SCALER_FRC_H__
#define __SCALER_FRC_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "ScalerType.h"
#include "Typedef.h"

//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************

//******************************************************************************
// D A T A   T Y P E   D E F I N E S
//******************************************************************************

//******************************************************************************
// V A R I A B L E S   P R O T O T Y P E
//******************************************************************************

//******************************************************************************
// F U N C T I O N    P R O T O T Y P E S
//******************************************************************************
void FRCConfigPostFRC(USHRT vfreq, bit postpattten);
BOOL FRCIsFRCEnabled(void);
void FRC_AutoFrameDown(ULONG *Dclk);
void DisableFRC_AutoFrameDown(void);
void FRCConfigDFR(void);
void DisableFRCConfigDFR(void);
void DisableFRCConfigPostFRC(void);
void SetCenterMode(void);
void DisableCenterMode(void);

#endif //__SCALER_FRC_H__
