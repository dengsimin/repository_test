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
#include "stdio.h"
#include "math.h"
#include "ScalerReg.h"
#include "BFAPI.h"
#include "DCR.h"

//******************************************************************************
// M A C R O   D E F I N I T I O N S
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
// F U N C T I O N   B O D Y S
//******************************************************************************

/**************************************************************************//**
 * Get current max red video code on display.
 * @return Max video code of red channel.
 ******************************************************************************/
UCHAR DCR_GetRMax(void)
{
    return SC_GI_PHS_SDIFF_LO0;
}

/**************************************************************************//**
 * Get current max red video code on display.
 * @return Max video code of green channel.
 ******************************************************************************/
UCHAR DCR_GetGMax(void)
{
    return SC_GI_PHS_SDIFF_LO1;
}

/**************************************************************************//**
 * Get current max red video code on display.
 * @return Max video code of blue channel.
 ******************************************************************************/
UCHAR DCR_GetBMax(void)
{
    return SC_GI_PHS_SDIFF_HI0;
}

/**************************************************************************//**
 * Check the max video code of display is completed or not.
 * @return TRUE if it is ready else FASLE.
 ******************************************************************************/
BOOL DCR_IsReadyToGetMax(void)
{
    if ((SC_GI_AUTO_TUNE_CTRL & BIT1) != 0) {
        return FALSE;
    }

#if 1
    if ((SC_INPUT_SELECT & 0x03) < 2) {
    	SC_GI_AUTO_TUNE_CTRL = 0x6E;
    }
    else {
    	SC_GI_AUTO_TUNE_CTRL = 0x2E;
    }
#else
    interface = GetCurrInputInterface();
    if ((interface == DIGITAL_INPUT0) ||
        (interface == DIGITAL_INPUT1)) {
        SC_GI_AUTO_TUNE_CTRL = 0x2E;
    }
    else {
        SC_GI_AUTO_TUNE_CTRL = 0x6E;
    }
#endif

    return TRUE;
}
