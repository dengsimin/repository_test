/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/

#ifndef __SCALER_PROFILE_NT68669_H__
#define __SCALER_PROFILE_NT68669_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************

//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************
#define SCREG_002_135M 0x01
#define SCREG_005_135M 0x19
#define SCREG_1F1_135M 0x1D
#define SCREG_002_165M 0x01
#define SCREG_005_165M 0x19
#define SCREG_1F1_165M 0x1D
#define SCREG_002_190M 0x01
#define SCREG_005_190M 0x19
#define SCREG_1F1_190M 0x1D
#define SCREG_002_210M 0x01
#define SCREG_005_210M 0x19
#define SCREG_1F1_210M 0x1D
#define SCREG_002_245M 0x01
#define SCREG_005_245M 0x19
#define SCREG_1F1_245M 0x1D

#define SCREG_055_PU   0x94
#define SCREG_055_PD   0x00
#define SCREG_056_PU   0x49
#define SCREG_056_PD   0x04
#define SCREG_057_INT_LDO   0xEF
#define SCREG_057_EXT_LDO   0xAF
#define SCREG_05A_INT_LDO   0x00
#define SCREG_05A_EXT_LDO   0x0E
#define SCREG_05A_PD        0x05

#define SCREG_00F_PU   0x04
#define SCREG_00F_PD   0x03
#define SCREG_027      0x21
#define SCREG_0D0      0x41

#define SCREG_1E7      SC_TMDS_LINK_CLK_SEL

#define SCREG_1EA      (SC_ADC_REG_1D | BIT5)
#define SCREG_1EB      0x03
#define SCREG_1ED      0x08
#define SCREG_1F7_PU   (SC_LVDS_MISC_CTRL3|0xE0)
#define SCREG_1F7_PD   (SC_LVDS_MISC_CTRL3&0x1F)
#define SCREG_1F8      0x02
#define SCREG_1FA      0x02
#define SCREG_1FD      SC_LVDS_PLL_CTRL
#define SCREG_B41      0x07

#define DEFAULT_CLKIMP1     0x10
#define DEFAULT_CLKIMP2     0x0D
#define DEFAULT_CLKIMP3     0x08
#define DEFAULT_DATAIMP1    0x10
#define DEFAULT_DATAIMP2    0x0D
#define DEFAULT_DATAIMP3    0x08
#define DEFAULT_EQBIAS1     0xB8
#define DEFAULT_EQBIAS2     0xE8
#define DEFAULT_EQBIAS3     0x78
#define DEFAULT_EQBIAS4     0x38
#define DEFAULT_EQBIAS5     0x08
#define DEFAULT_EQRF1       0x00
#define DEFAULT_EQRF2       0x00
#define DEFAULT_EQRF3       0x00
#define DEFAULT_EQRF4       0x00
#define DEFAULT_EQRF5       0x00

//******************************************************************************
// CPU Clock support 
//******************************************************************************
#define CPU_CLK_TABLE { \
            12,12,24,36,48,60,72,84,96 \
        }

//******************************************************************************
// D A T A   T Y P E   D E F I N E S
//******************************************************************************

//******************************************************************************
// V A R I A B L E S   P R O T O T Y P E
//******************************************************************************

//******************************************************************************
// F U N C T I O N    P R O T O T Y P E S
//******************************************************************************

#endif //__SCALER_PROFILE_NT68669_H__
