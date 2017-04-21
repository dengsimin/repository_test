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
#include "Typedef.h"

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
#define PWM_LEDDRIVER       PWM_A

//PWM Pin
// 1 for NT68668 only.
// 2~4 for NT68669 only.
// 5~8 for NT68168 only.
// 8~16 for NT68660 only
// 6 & 17~22 for NT68650 only
#define PWMAB_PIN_NO_SEL    1
#define PWMA_PIN_63         2
#define PWMA_PIN_117        3
#define PWMB_PIN_118        4
#define PWMB_PIN_28         5
#define PWMB_PIN_52         6
#define PWMA_PIN_53         7
#define PWMA_PIN_29         8
#define PWMC_PIN_33         9
#define PWMD_PIN_34         10
#define PWMB_PIN_41         11
#define PWMA_PIN_42         12
#define PWMA_PIN_76         13
#define PWMB_PIN_79         14
#define PWMC_PIN_81         15
#define PWMD_PIN_84         16
#define PWMA_LEDDRIVER      17
#define PWMB_PIN_1          18
#define PWMC_PIN_41         19
#define PWMC_PIN_127        20
#define PWMD_PIN_6          21
#define PWMD_PIN_53         22

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
