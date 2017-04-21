/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/

#ifndef __INT_H__
#define __INT_H__

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
USHRT GetTimerTick(void);
BOOL CheckModeChangeFlag(void);
void ClearModeChangeFlag(void);
void SetModeChangeFlag(void);
#if ENABLE_AUTO_CONTROL == ON
void UART_Handler(void);
#endif
#if (INPUT_INTERFACE&INPUT_MHL_MASK)
void SetMHLTimerTick();
#endif
USHRT GetTimerTickInt();
#if (((INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1)) && (ENABLE_DP_AUX_MONITOR==ON))
extern void  move_aux_packet(void);  
#endif
BOOL CheckUSBCCHWResetFlag(void);
void ClearUSBCCHWResetFlag(void);
UCHAR CheckUSBCCErrorFlag(void);
void ClearUSBCCErrorFlag(void);

#endif //__INT_H__
