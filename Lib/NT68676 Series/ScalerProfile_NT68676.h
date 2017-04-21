/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/

#ifndef __SCALER_PROFILE_NT68676_H__
#define __SCALER_PROFILE_NT68676_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************

//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************
// ADC Related
#define SCREG_002_135M 0x01
#define SCREG_005_135M 0x09
#define SCREG_1F1_135M 0x3C
#define SCREG_002_165M 0x01
#define SCREG_005_165M 0x09
#define SCREG_1F1_165M 0x3C
#define SCREG_002_190M 0x01
#define SCREG_005_190M 0x09
#define SCREG_1F1_190M 0x3C
#define SCREG_002_210M 0x01
#define SCREG_005_210M 0x09 
#define SCREG_1F1_210M 0x3C
#define SCREG_002_245M 0x01
#define SCREG_005_245M 0x09
#define SCREG_1F1_245M 0x3C

#define SCREG_00E_PU   (SC_ADC_POWER_UP | 0x07)
#define SCREG_00E_PD   (SC_ADC_POWER_UP & ~0x07)
#define SCREG_011 0x28

#define SCREG_1E7      SC_TMDS_LINK_CLK_SEL

#define SCREG_1EA      0x6E
#define SCREG_1ED      0x08

#define SCREG_055_PU 0x94
#define SCREG_055_PD 0x50
#define SCREG_056_PU 0x00
#define SCREG_056_PD 0x04
#define SCREG_057_INT_LDO 0xFF
#define SCREG_057_EXT_LDO 0xBF

#define SCREG_0D0 0x41

// LVDS Related
#define SCREG_1F5      0x50
#define SCREG_1F8      0x06
#define SCREG_1F9      0x00
#define SCREG_1FA      0x00

// LDO Related
#define SCREG_B40      0x04
#define SCREG_B41      0x07
#define SCREG_B43      0x2A

// HDMI Pin Order Configuration
#define HDMI_PIN_ORDR  0x00

// HDCP Related
#define SCREG_643      SC_HDCP_CTRL
#define HDCP_CLK_INV   0x00

#define DEFAULT_CLKIMP1     0x14
#define DEFAULT_CLKIMP2     0x11
#define DEFAULT_CLKIMP3     0x0C
#define DEFAULT_DATAIMP1    0x14
#define DEFAULT_DATAIMP2    0x11
#define DEFAULT_DATAIMP3    0x0C
#define DEFAULT_EQBIAS1     0x08
#define DEFAULT_EQBIAS2     0xB8
#define DEFAULT_EQBIAS3     0x38
#define DEFAULT_EQBIAS4     0x78
#define DEFAULT_EQBIAS5     0xE8
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

#endif //__SCALER_PROFILE_NT68676_H__
