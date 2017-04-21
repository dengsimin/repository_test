/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/

#ifndef __SCALER_PROFILE_NT68364_H__
#define __SCALER_PROFILE_NT68364_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************

//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************
// ADC Related
#define SCREG_002_135M 0x04
#define SCREG_005_135M 0x09
#define SCREG_1F1_135M 0x3C
#define SCREG_002_165M 0x04
#define SCREG_005_165M 0x09
#define SCREG_1F1_165M 0x3C
#define SCREG_002_190M 0x04
#define SCREG_005_190M 0x09
#define SCREG_1F1_190M 0x3C
#define SCREG_002_210M 0x04
#define SCREG_005_210M 0x09
#define SCREG_1F1_210M 0x3C
#define SCREG_002_245M 0x04
#define SCREG_005_245M 0x09
#define SCREG_1F1_245M 0x3C

#define SCREG_00E_PU   (SC_ADC_POWER_UP | 0x47)
#define SCREG_00E_PD   (SC_ADC_POWER_UP & ~0x47)
#define SCREG_011      0x28
#define SCREG_012_PU   0x98
#define SCREG_012_PD   0x83
#define SCREG_012_LP   0x80

#define SCREG_1E7      SC_TMDS_LINK_CLK_SEL

#define SCREG_1EA      0x6E
#define SCREG_1EB      (SC_ADC_COMP_CTRL | 0x03)
#define SCREG_1ED      (SC_ADC_BAND_GAP | BIT3)

#define SCREG_055_PU 0x50
#define SCREG_055_PD 0x40
#define SCREG_056_PU 0x01
#define SCREG_056_PD 0x01
#define SCREG_057_INT_LDO 0xFF
#define SCREG_057_EXT_LDO 0xBF

#define SCREB_B61_PU 0x00
#define SCREB_B61_PD 0x02
#define SCREB_B62_PU 0x00
#define SCREB_B62_PD 0xE2
#define SCREB_B63_INT_LDO 0x02
#define SCREB_B63_EXT_LDO 0x02

#define SCREB_039_INT_LDO 0x55
#define SCREB_039_EXT_LDO 0x55

#define SCREG_0D0 0x41
#define SCREG_0D1 0x13

// LVDS Related
#define SCREG_1F3      0x10
#define SCREG_1F4      0x41
#define SCREG_1F5      0xD0
#define SCREG_1F8      0x03
#define SCREG_1F9      0x00|BIT4
#define SCREG_1FA      0x02
#define SCREG_1FD      (SC_LVDS_PLL_CTRL & 0x7F)

// TMDS Related
#define SCREG_331      0x03
#define SCREG_333_PU   0xBF
#define SCREG_333_PD   0x00
#define SCREG_333_LP0  0x07
#define SCREG_333_LP1  0x18
#define SCREG_334_PU   (SC_DVI_CTRL_334 | BIT0)
#define SCREG_334_PD   (SC_DVI_CTRL_334 & ~BIT0)
#define SCREG_334_LF   (SC_DVI_CTRL_334 | BIT2)
#define SCREG_334_HF   (SC_DVI_CTRL_334 & ~BIT2)
#define SCREG_335_PU   0x44
#define SCREG_335_PD   0x00
#define SET_SCREG_335_LF  {SC_DVI_CTRL_335 = 0x66; SC_DVI_CTRL_335 = 0x22;}
#define SET_SCREG_335_HF  {SC_DVI_CTRL_335 = 0x66; SC_DVI_CTRL_335 = 0x44;}
#define SCREG_336_PU   0xD8
#define SCREG_336_PD   0x00
#define SCREG_336_LP0  0x40
#define SCREG_336_LP1  0x18

#define TMDS_BANDWIDTH_SEGMENT 100

// LDO Related
#define SCREG_B40      0x05
#define SCREG_B41      0x07
#define SCREG_B42      (SC_MPLL_CTRL_B42 | BIT2)
#define SCREG_B43      0x00

// HDCP Related
#define SCREG_643      0x0A
#define HDCP_CLK_INV   0x12

#define DEFAULT_CLKIMP1     0x14
#define DEFAULT_CLKIMP2     0x11
#define DEFAULT_CLKIMP3     0x0C
#define DEFAULT_DATAIMP1    0x14
#define DEFAULT_DATAIMP2    0x11
#define DEFAULT_DATAIMP3    0x0C
#define DEFAULT_EQBIAS1     0xB8
#define DEFAULT_EQBIAS2     0xB8
#define DEFAULT_EQBIAS3     0xF8
#define DEFAULT_EQBIAS4     0xF8
#define DEFAULT_EQBIAS5     0xF8
#define DEFAULT_EQRF1       0x80
#define DEFAULT_EQRF2       0x88
#define DEFAULT_EQRF3       0x28
#define DEFAULT_EQRF4       0x0B
#define DEFAULT_EQRF5       0x0F

//******************************************************************************
// CPU Clock support 
//******************************************************************************
#define CPU_CLK_TABLE { \
            12,12,24,32,48,64,96,12,12 \
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

#endif //__SCALER_PROFILE_NT68360_H__
