/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/

#ifndef __SCALER_PROFILE_NT68674_H__
#define __SCALER_PROFILE_NT68674_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************


//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************
#define SCREG_002_135M 0x06
#define SCREG_005_135M 0x13
#define SCREG_1F1_135M 0x3C
#define SCREG_002_165M 0x06
#define SCREG_005_165M 0x13
#define SCREG_1F1_165M 0x3B
#define SCREG_002_190M 0x06
#define SCREG_005_190M 0x13
#define SCREG_1F1_190M 0x3A
#define SCREG_002_210M 0x06
#define SCREG_005_210M 0x13 
#define SCREG_1F1_210M 0x38
#define SCREG_002_245M 0x06
#define SCREG_005_245M 0x13
#define SCREG_1F1_245M 0x38

#define SCREG_1E7      SC_TMDS_LINK_CLK_SEL

#define SCREG_1FA      0x80
#define SCREG_1FD      0x37

#define DEFAULT_CLKIMP1     0x00
#define DEFAULT_CLKIMP2     0x00
#define DEFAULT_CLKIMP3     0x00
#define DEFAULT_DATAIMP1    0x10
#define DEFAULT_DATAIMP2    0x0D
#define DEFAULT_DATAIMP3    0x08
#define DEFAULT_EQBIAS1     0xB8
#define DEFAULT_EQBIAS2     0xF8
#define DEFAULT_EQBIAS3     0x78
#define DEFAULT_EQBIAS4     0x38
#define DEFAULT_EQBIAS5     0x08
#define DEFAULT_EQRF1       0x87
#define DEFAULT_EQRF2       0x87
#define DEFAULT_EQRF3       0x87
#define DEFAULT_EQRF4       0x87
#define DEFAULT_EQRF5       0x87

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

#endif //__SCALER_PROFILE_NT68674_H__
