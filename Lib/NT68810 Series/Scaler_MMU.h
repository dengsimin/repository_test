/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/

#ifndef __SCALER_MMU_H__
#define __SCALER_MMU_H__

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
void MMUInitialize(void);
void MMUPowerOn(void);
void MMUPowerOff(void);
void MMUConfig(void);
#if ENABLE_PREFRC == ON
void MMUConfigPreFRC(void);
#endif
#if ENABLE_DFR == ON
void MMUConfigDFR(void);
#endif
#if ENABLE_AUTO_CONTROL == ON
UCHAR CheckDRAM(void);
#endif

#endif //__SCALER_MMU_H__
