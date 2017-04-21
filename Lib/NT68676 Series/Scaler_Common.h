/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/

#ifndef __SCALER_COMMON_H__
#define __SCALER_COMMON_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "ScalerType.h"

//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************
//PWM Selection
#define PWM_ALL             0
#define PWM_A               1
#define PWM_B               2
#define PWM_C               3
#define PWM_D               4
#define PWM_MCU             5
#define PRE_AMP             6
#define PWM_NULL            7


//PWM Pin
#define PWMA_PIN_51         1
#define PWMB_PIN_105        2

//DBC Pin
#define DBC_PIN_PWM_A       PWM_A
#define DBC_PIN_PWM_B       PWM_B

enum SCID {
    SCID_UNKNOWN=0x00
};

//******************************************************************************
// D A T A   T Y P E   D E F I N E S
//******************************************************************************

//******************************************************************************
// V A R I A B L E S   P R O T O T Y P E
//******************************************************************************

//******************************************************************************
// F U N C T I O N    P R O T O T Y P E S
//******************************************************************************
void ScalerInitialize(void);
void SetInputInterface(UCHAR interface);
UCHAR GetCurrInputInterface(void);
UCHAR GetSCID(void);

#endif //__SCALER_COMMON_H__
