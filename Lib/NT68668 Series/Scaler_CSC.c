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
#include "ScalerProfile.h"

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
 * Set color space automatically.
 ******************************************************************************/
void SetColorSpace(void)
{
    UCHAR current_input_interface;

    current_input_interface = GetCurrInputInterface();
    if ((current_input_interface == ANALOG_YPBPR_INPUT0) || 
        (current_input_interface == ANALOG_YPBPR_INPUT1)) {
        SC_VI_AUTO_CTRL |= BIT5; // Set auto-detection data path after CSC
        SC_DEI_CSC_CTRL = 0x09;
    }
    else {
        SC_VI_AUTO_CTRL &= ~BIT5; // Set auto-detection data path before CSC
        SC_DEI_CSC_CTRL = 0x00;
    }
}
