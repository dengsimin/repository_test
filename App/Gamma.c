/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "Include.h"

#if ENABLE_GAMMA == ON

#include "GammaData.c"

//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************

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

//******************************************************************************
// Prototype: 
//  void LoadGamma(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Load gamma tables
// Notes:
//  None
//******************************************************************************
void LoadGamma(void)
{
#if 0 // 0 lrd add 
    GMAPI_LoadGamma320(&GammaTable);
    GMAPI_EnableGamma();
#else
#if !lrd_dis_benq
    if(Standard_Gamma == 1){
        GMAPI_LoadGamma1536(&GammaTable2);
    }
    else{
    if (GetGammaNum()== nGamma_18) {
         GMAPI_LoadGamma1536(&GammaTable);
    }        
    else if (GetGammaNum() == nGamma_20) {
        GMAPI_LoadGamma1536(&GammaTable1);
    }
    else if (GetGammaNum() == nGamma_22) {
        GMAPI_LoadGamma1536(&GammaTableByPass);
    }
    else if (GetGammaNum() == nGamma_24) {
        GMAPI_LoadGamma1536(&GammaTable3);
    }
    else if (GetGammaNum() == nGamma_26) {
        GMAPI_LoadGamma1536(&GammaTable4);
    }
    }
    //GMAPI_LoadGamma320(&GammaTable22to20);
    WaitDisVSync();
    GMAPI_EnableGamma();
#else
    if(Standard_Gamma == 1){
       LoadGama_2();
    }
    else{
        if (GetGammaNum()== nGamma_18) {
             GMAPI_LoadGamma320(&GammaTable);
        }        
        else if (GetGammaNum() == nGamma_20) {
            LoadGama_1();
        }
        else if (GetGammaNum() == nGamma_22) {
            LoadGama_bypass();
        }
        else if (GetGammaNum() == nGamma_24) {
            LoadGama_3();
        }
        else if (GetGammaNum() == nGamma_26) {    
            LoadGama_4();
        }
    }
    WaitDisVSync();
    GMAPI_EnableGamma();
#endif
#endif
}

#endif //#if ENABLE_GAMMA == ON

#if ENABLE_PRE_REV_GAMMA == ON
void LoadPreGamma(void)
{
#if IS_NT68790_SERIES || IS_NT68810_SERIES// || IS_NT68870_SERIES // 16 entries, NT68770 and NT68850 are 32 entries
const UCHAR DefaultPreGammaRGBLUT[32]={
    0x00,0x00,0x8E,0x00,0x99,0x02,0x61,0x06,
    0x0C,0x0C,0xB8,0x13,0x7B,0x1D,0x6B,0x29,
    0x98,0x37,0x13,0x48,0xE9,0x5A,0x27,0x70,
    0xD9,0x87,0x0B,0xA2,0xC6,0xBE,0x14,0xDE,
};
    GMAPI_LoadPreGamma16bit(16, DefaultPreGammaRGBLUT);
    GMAPI_EnablePreGamma();
    GMAPI_EnableRevGamma();
#elif IS_NT68870_SERIES
const UCHAR DefaultPreGammaRGBLUT[64]={
    0x00,0x00,0x1E,0x00,0x8E,0x00,0x5F,0x01,0x99,0x02,0x43,0x04,0x61,0x06,0xF8,0x08,
    0x0C,0x0C,0xA0,0x0F,0xB8,0x13,0x55,0x18,0x7B,0x1D,0x2C,0x23,0x6B,0x29,0x39,0x30,
    0x98,0x37,0x8B,0x3F,0x13,0x48,0x32,0x51,0xE9,0x5A,0x3A,0x65,0x27,0x70,0xB1,0x7B,
    0xD9,0x87,0xA2,0x94,0x0B,0xA2,0x17,0xB0,0xC6,0xBE,0x1A,0xCE,0x14,0xDE,0xB6,0xEE,
};
    GMAPI_LoadPreGamma16bit(32, DefaultPreGammaRGBLUT);
    GMAPI_EnablePreGamma();
    GMAPI_EnableRevGamma();
#endif
}

void LoadRevGamma(void)
{
#if IS_NT68790_SERIES || IS_NT68810_SERIES || IS_NT68870_SERIES //32 entries
const UCHAR DefaultRevGammaRGBLUT[32]={
    0x00,0x0F,0x15,0x19,0x1C,0x22,0x27,0x2E,0x35,0x3F,0x48,0x50,0x57,0x5D,0x63,0x6E,
    0x77,0x80,0x88,0x8F,0x96,0x9D,0xA3,0xAF,0xBA,0xC4,0xCE,0xD7,0xE0,0xE8,0xF0,0xF8,
};
    GMAPI_LoadRevGamma16bit(16, DefaultRevGammaRGBLUT);
    GMAPI_EnablePreGamma();
    GMAPI_EnableRevGamma();
#endif
}
#endif
