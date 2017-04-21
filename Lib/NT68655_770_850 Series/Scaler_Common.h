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
// NT68770, NT68655
#define PWMA_LEDDRIVER 1
#define PWMA_PIN_69 2  //PE0/DBC
#define PWMB_PIN_65 3  //PC6
#define PWMB_PIN_66 4  //PC0
#define PWMC_PIN_121 5 //PC4
#define PWMC_PIN_124 6 //PE2
#define PWMD_PIN_43 7  //PC5
#define PWMD_PIN_50 8  //PA3
// NT68850
#define PWMA_PIN_67 9  //PE0
#define PWMA_PIN_109 10  //PC0/DBC
#define PWMA_PIN_127 11  //PE2/DBC
#define PWMB_PIN_27 12  //PA5
#define PWMB_PIN_42 13  //PE3
#define PWMC_PIN_6 14  //PA6
#define PWMC_PIN_104 15  //PA0
#define PWMD_PIN_66 16  //PA1/DBC
#define PWMD_PIN_125 17  //PA2/DBC
// NT68150
#define PWMA_PIN_22 18  //PA1/DBC
#define PWMB_PIN_64 19  //PB2
// NT68658
#define PWMA_PIN_36 20  //PC0
#define PWMB_PIN_33 21  //PC6
//#define PWMC_PIN_1  22  //PA4
//#define PWMD_PIN_30 23  //PC5
// NT68790
#define PWMA_PIN_66 24  //PC0
#define PWMA_PIN_103 25  //PE2
#define PWMB_PIN_56 26  //PC6
#define PWMB_PIN_71 27  //PE0
#define PWMC_PIN_115 28 //PA4
#define PWMD_PIN_52 29  //PC5


#define PWM_PIN_NULL        0xFF

//DBC Pin //Only for NT68850
#define DBC_PIN_PWM_1       PWMD_PIN_125
#define DBC_PIN_PWM_2       PWMC_PIN_104
#define DBC_PIN_PWM_3       PWMD_PIN_66
#define DBC_PIN_PWM_4       PWMA_PIN_67
#define DBC_PIN_PWM_5       PWMB_PIN_33

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

#endif //__SCALER_COMMON_H__
