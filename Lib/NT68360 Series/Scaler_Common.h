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
#define PWMA_PIN_C9         1
#define PWMA_PIN_C10        2
#define PWMB_PIN_D9         3
#define PWMB_PIN_D10        4
#define PWMC_PIN_H17        5
#define PWMC_PIN_K18        6
#define PWMD_PIN_J18        7
#define PWMD_PIN_K17        8
#define PWM_PIN_NULL        0xFF

//DBC Pin
#define DBC_PIN_PWM_A       PWM_A
#define DBC_PIN_PWM_B       PWM_B
#define DBC_PIN_PWM_C       PWM_C
#define DBC_PIN_PWM_D       PWM_D

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
