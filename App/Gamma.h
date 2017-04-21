/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/
#ifndef __GAMMA_H__
#define __GAMMA_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "Typedef.h"

//******************************************************************************
// G L O B A L   D E F I N I T I O N S
//******************************************************************************
typedef struct ColorTempByGamma {
    char ROffset;
    char GOffset;
    char BOffset;
} CTGamma;

//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************

//******************************************************************************
// E X T E R N A L   V A R I A B L E   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// S T A T I C   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
extern void LoadGamma(void);
extern void LoadPreGamma(void);
extern void LoadRevGamma(void);
extern void LoadGama_bypass(void);
extern void LoadGama_1(void);
extern void LoadGama_2(void);
extern void LoadGama_3(void);
extern void LoadGama_4(void);

#define nGamma_18    0
#define nGamma_20    1
#define nGamma_22    2
#define nGamma_24    3
#define nGamma_26    4


#endif //__GAMMA_H__
