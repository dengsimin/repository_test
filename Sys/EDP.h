/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/
#ifndef __EDP_H__
#define __EDP_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "Typedef.h"

//******************************************************************************
// G L O B A L   D E F I N I T I O N S
//******************************************************************************
#define DPTX_HPD_DELAY 50//500//ms

//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
extern void InitEDP(void);
extern void CopDoFunction(UCHAR cm);
extern void EDP_ForceTraining(void);
extern void CheckDPTXHPD(void);
extern BOOL IsDPTXTrainingDone(void);
extern void ClearHPDStatus(void);
extern void EDP_PowerOn(void);

#endif //__COP_H__
