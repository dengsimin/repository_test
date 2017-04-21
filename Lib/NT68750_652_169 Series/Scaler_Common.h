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
#define PWM_LEDDRIVER       PWM_A

//PWM Pin
// 1~2 for NT6867x only.
// 3~10 for NT68360 only.
//23~30 for NT68661 only
#define PWMA_PIN_51         1
#define PWMB_PIN_105        2
#define PWMA_PIN_C9         3
#define PWMA_PIN_C10        4
#define PWMB_PIN_D9         5
#define PWMB_PIN_D10        6
#define PWMC_PIN_H17        7
#define PWMC_PIN_K18        8
#define PWMD_PIN_J18        9
#define PWMD_PIN_K17        10
#define PWMA_LEDDRIVER      11
#define PWMA_PIN_46         12
#define PWMA_PIN_69         13
#define PWMA_PIN_126        14
#define PWMB_PIN_50         15
#define PWMB_PIN_127        16
#define PWMC_PIN_3          17
#define PWMC_PIN_39         18
#define PWMD_PIN_2          19
#define PWMD_PIN_51         20
#define PWMA_PIN_54         21
#define PWMB_PIN_56         22
#define PWMC_PIN_33         23
#define PWMD_PIN_34         24
#define PWMB_PIN_41         25
#define PWMA_PIN_42         26
#define PWMA_PIN_76         27
#define PWMB_PIN_79         28
#define PWMC_PIN_81         29
#define PWMD_PIN_84         30
#define PWMA_PIN_29         31
#define PWMB_PIN_52         32

#define PWMA_PIN_57         33
#define PWMB_PIN_59         34
#define PWMC_PIN_19         35
#define PWMC_PIN_58         36
#define PWMD_PIN_20         37
#define PWMD_PIN_60         38

#define PWMA_PIN_24         39
#define PWMA_PIN_39         40
#define PWMA_PIN_61         41
#define PWMB_PIN_38         42
#define PWMB_PIN_63         43
#define PWMC_PIN_28         44
#define PWMC_PIN_64         45
#define PWMD_PIN_29         46
#define PWMD_PIN_67         47


#define PWM_PIN_NULL        0xFF

//DBC Pin
#define DBC_PIN_PWM_1       PWMA_PIN_57//PWM_A
#define DBC_PIN_PWM_2       PWMC_PIN_19//PWM_C
#define DBC_PIN_PWM_3       PWMA_PIN_39
#define DBC_PIN_PWM_4       PWMA_PIN_61
#define DBC_PIN_PWM_5       PWMD_PIN_29
#define DBC_PIN_PWM_6       PWMD_PIN_67

enum SCID {
    SCID_UNKNOWN=0x00,
    SCID_770=0x10,         
    SCID_770_E=SCID_770,    
    SCID_770_G,
    SCID_770_H,    
    SCID_770_I,    
    SCID_770_FINAL=SCID_770_I,
    SCID_850=0x20,
    SCID_850_C=SCID_850,
    SCID_850_D,
    SCID_850_E,
    SCID_850_FINAL=SCID_850_E,
    SCID_655=0x30,
    SCID_655_FINAL=SCID_655,
    SCID_661=0x40,
    SCID_661_B,
    SCID_661_C,
    SCID_661_FINAL=SCID_661_C,
    SCID_370=0x50,
    SCID_370_FINAL=SCID_370,
    SCID_790_A=0x60,
    SCID_790_B,
    SCID_790_C,
    SCID_790_D,
    SCID_790_E,
    SCID_790_FINAL=SCID_790_E,
    SCID_658_A=0x70,
    SCID_658_B,
    SCID_658_FINAL=SCID_658_B,
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
#if ENABLE_HDCP_TRIM_MODE == ON
USHRT GetEFUSE_SCID(void);
#endif
void ScalerInitialize(void);
void SetInputInterface(UCHAR interface);
UCHAR GetCurrInputInterface(void);
UCHAR GetSCID(void);

#if ENABLE_ESD_PROTECT == ON
UCHAR ReadOSDCheckSum(void);
void ReadESDCheckSum(void);
void ClearESDCKStatus(void);
#endif

#endif //__SCALER_COMMON_H__
