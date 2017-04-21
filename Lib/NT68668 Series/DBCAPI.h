/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/

#ifndef __DBC_API_H__
#define __DBC_API_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "DBCType.h"

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
void DBCAPI_EnableDBC(void);
void DBCAPI_DisableDBC(void);
void DBCAPI_LoadTable(DBCTab *ptab);
void DBCAPI_ConfigPWM(USHRT freq, DBCDividor div);
void DBCAPI_EnableDBCPWM(UCHAR port, UCHAR pin);
void DBCAPI_DisableDBCPWM(UCHAR port, UCHAR pin);
void DBCAPI_SetSavingRatio(UCHAR ratio1, UCHAR ratio2)
void DBCAPI_SetPWMAdjustment(UCHAR rate, UCHAR step);
void DBCAPI_SetPWMInvert(BOOL inv);
void DBCAPI_EnableRGBCompensation(void);
void DBCAPI_DisableRGBCompensation(void);
void DBCAPI_SetDistortion(UCHAR distort);
void DBCAPI_EnableAbruptChange(UCHAR thd);
void DBCAPI_DisableAbruptChange(void);
UCHAR DBCAPI_GetPWMOffset(void);
UCHAR DBCAPI_GetActPWM(void);
#if ENABLE_DBC == ON && ENABLE_DBC_HW_DEBOUNCE == OFF
UCHAR DBCAPI_GetAverageY(void);
UCHAR DBCAPI_GetEffectiveColor(void);
#endif
void DBCAPI_SetDBCMinMax(UCHAR min, UCHAR max);
void DBCAPI_SetDebouncingMode(UCHAR Bounce1, UCHAR Bounce2);

#endif //__DBC_API_H__
