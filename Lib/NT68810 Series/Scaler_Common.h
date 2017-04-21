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
//NT68810
#define PWMA_LEDDRIVER      1
#define PWMA_PIN_66         2  //PC0
#define PWMB_PIN_71         3  //PE0
#define PWMB_PIN_63         4  //PC6
#define PWMB_PIN_120        5  //PE1
#define PWMC_PIN_113        6 //PA3
#define PWMC_PIN_116        7 //PA4
#define PWMC_PIN_123        8 //PC3
#define PWMD_PIN_59         9  //PC5
#define PWMA_PIN_PC0       10
#define PWMA_PIN_PE0       11
#define PWMB_PIN_PC6       12
#define PWMB_PIN_PE1       13
#define PWMC_PIN_PA3       14
#define PWMC_PIN_PA4       15
#define PWMC_PIN_PC3       16
#define PWMD_PIN_PC5       17
#define PWM_PIN_NULL        0xFF

//DBC Pin
#define DBC_PIN_PWM_1       PWMB_PIN_71
//#define DBC_PIN_PWM_2       PWMC_PIN_104
//#define DBC_PIN_PWM_3       PWMD_PIN_66
//#define DBC_PIN_PWM_4       PWMA_PIN_67
//#define DBC_PIN_PWM_5       PWMB_PIN_33

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
    SCID_810_A=0x80,
    SCID_810_B,
    SCID_810_C,
    SCID_810_FINAL=SCID_810_C,
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
void EDP_PowerOff(void);
void PhyLinkSelect(UCHAR interface);
UCHAR GetTMDSPhyLinkSelect(void);
UCHAR GetDPPhyLinkSelect(void);

#endif //__SCALER_COMMON_H__
