/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/

#ifndef __ODAPI_H__
#define __ODAPI_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
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
// F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
void ODAPI_DisableOD(void);
void ODAPI_EnableOD(void);
void ODAPI_LoadOD(UCHAR *ptr);
BOOL ODAPI_IsODReset(void);
void ODAPI_SetMCOnOff(UCHAR on_off);
void ODAPI_SetMCThreshold(ULONG low, ULONG high);
void ODAPI_MotionCheck(void);
void ODAPI_SetDynamicOD(void);
void ODAPI_EnableDynamicOD(void);
void ODAPI_DisableDynamicOD(void);

#endif //__ODAPI_H__
