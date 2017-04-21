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

#if ENABLE_OD == ON

#include "ODData.c"

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
//  void SetODMode(UCHAR mode)
// Parameters:
//  mode    : OD mode
// Return:
//  None
// Purpose:
//  Set OD mode
// Notes:
//  None
//******************************************************************************
void SetODMode(UCHAR mode)
{
    static UCHAR od_mode = 0xFF;

    if ((od_mode != mode) || ODAPI_IsODReset()) {
        ODAPI_LoadOD(ODTable[mode]);
        od_mode = mode;
    }
    ODAPI_EnableOD();
}


#endif //#if ENABLE_OD == ON

void ForODCompilerCodePass(void)
{
  code UCHAR temp[]={0x00};
  UCHAR i;
  i = temp[0];
}


void ODAPI_SetSeparateODTestPatternEnable(UCHAR tmp)
{
    tmp = 0;
    SC_OD_TEST_CONFIGURATION |= BIT0; 

}
void ODAPI_ODTestPatternEnable(void)
{

    SC_OD_TEST_CONFIGURATION |= BIT0; 

}

void ODAPI_ODTestPatternDisable(void)
{
    SC_OD_TEST_CONFIGURATION &= ~BIT0; 

}

