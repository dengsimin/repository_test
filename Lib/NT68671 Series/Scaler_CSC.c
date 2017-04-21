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
static xdata CSCColorSpace ucCSCClrSpace = CSC_HDMI_AUTO_CLR_SPACE; /*!< Variable of CSC mode. */

//******************************************************************************
// E X T E R N A L   V A R I A B L E   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// S T A T I C   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
static xdata UCHAR ucAVIClrSpace = 0xFF;

//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// F U N C T I O N   B O D Y S
//******************************************************************************

#if ENABLE_HDMI == ON
//******************************************************************************
// Prototype: 
//  void GetScalerColorSpace(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//******************************************************************************
UCHAR GetScalerColorSpace(void)
{
   return ucAVIClrSpace;
}

/**************************************************************************//**
 * Configure the CSC mode.
 * @param csc CSC mode.
 ******************************************************************************/
void SetCSCColorSpace(CSCColorSpace csc)
{
    ucCSCClrSpace = csc;
    SetColorSpace();
}

#endif

/**************************************************************************//**
 * According to ucCSCClrSpace, set color space automatically.
 * If CSC mode is auto:
 *  - If input interface is HDMI, the color space is configured automatically according to AVI packets.
 *  - If input interface is DVI, forcing the color space as RGB.
 *  - If input interface is YPbPr, the color space is configured automatically according to input resolution.
 *  - If input interface is DSub, forcing the color space as RGB.
 * If CSC mode is manual:
 *  - If input interface is HDMI, the color space is configured manually.
 *  - If input interface is DVI, the color space is configured manually.
 *  - If input interface is YPbPr, the color space is configured manually.
 *  - If input interface is DSub, forcing the color space as RGB.
 ******************************************************************************/
void SetColorSpace(void)
{
    code int SDTVcolorTab[] = {
        1.371*1024+0.5,0.698*1024+0.5,0.336*1024+0.5,1.732*1024+0.5,
    };

    code int HDTVcolorTab[] = {
        1.540*1024+0.5,0.459*1024+0.5,0.183*1024+0.5,1.816*1024+0.5,
    };

    UCHAR current_input_interface, repeat, ch;

    current_input_interface = GetCurrInputInterface();
    if ((current_input_interface == DIGITAL_INPUT0) || (current_input_interface == DIGITAL_INPUT1)) {

        ucAVIClrSpace = (SC_HDMI_AVI[0] & 0x60); 
        
        if ((SC_HDMI_DET & BIT1) != 0) {//HDMI
            if ((ucAVIClrSpace != 0) &&
                (ucCSCClrSpace == CSC_HDMI_AUTO_CLR_SPACE)) {//HDMI & YUV color
                SC_HDMI_AUTO_CTRL |= BIT2;
                SC_VI_AUTO_CTRL |= BIT5; // Set auto-detection data path after CSC
                if (IsInterlaced()) { //Interlaced
                    if ((SC_HDMI_AVI[1] & 0xC0) == 0x80) {//ITU 709
                        WriteShortScaler(&SC_DEI_COLOR_COFFA_LO,HDTVcolorTab[0]);
                        WriteShortScaler(&SC_DEI_COLOR_COFFB_LO,HDTVcolorTab[1]);
                        WriteShortScaler(&SC_DEI_COLOR_COFFC_LO,HDTVcolorTab[2]);
                        WriteShortScaler(&SC_DEI_COLOR_COFFD_LO,HDTVcolorTab[3]);
                    }
                    else {//ITU 601
                        WriteShortScaler(&SC_DEI_COLOR_COFFA_LO,SDTVcolorTab[0]);
                        WriteShortScaler(&SC_DEI_COLOR_COFFB_LO,SDTVcolorTab[1]);
                        WriteShortScaler(&SC_DEI_COLOR_COFFC_LO,SDTVcolorTab[2]);
                        WriteShortScaler(&SC_DEI_COLOR_COFFD_LO,SDTVcolorTab[3]);
                    }
                    SC_DEI_CSC_CTRL = 0x09;
                }
                else {
                    SC_DEI_CSC_CTRL = 0x00;
                }
            }
            else {//HDMI & RGB color
                SC_HDMI_AUTO_CTRL &= ~BIT2;
                SC_VI_AUTO_CTRL &= ~BIT5; // Set auto-detection data path before CSC
                SC_DEI_CSC_CTRL = 0x00;
            }

            //Set repeat for Manual CSC mode
            ch = SC_HDMI_AVI[4] & 0x0F;
            repeat = SC_HDMI_CLK_INT & 0x0F;//default: No Repetition
            if (ch == 0x01) {//pixel sent 2 times
                repeat |= 0x50;
            }
            else if (ch == 0x03) {//pixel sent 4 times
                repeat |= 0xF0;
            }
            SC_HDMI_CLK_INT = repeat;
        }
        else {//DVI
            SC_HDMI_AUTO_CTRL &= ~BIT2;
            SC_VI_AUTO_CTRL &= ~BIT5; // Set auto-detection data path before CSC
            SC_DEI_CSC_CTRL = 0x00;
            SC_HDMI_CLK_INT &= 0x0F;
        }
        SC_CSC_CTRL1 = 0x00;
        SC_CSC_CTRL2 = 0x00;
    }
    else if ((current_input_interface == ANALOG_YPBPR_INPUT0) || (current_input_interface == ANALOG_YPBPR_INPUT1)) {
        SC_HDMI_AUTO_CTRL &= ~BIT2;
        SC_VI_AUTO_CTRL |= BIT5; // Set auto-detection data path after CSC
        SC_DEI_CSC_CTRL = 0x09;
        SC_CSC_CTRL1 = 0x00;
        SC_CSC_CTRL2 = 0x00;

        if (ReadShortScaler(&SC_GI_CAP_HWID_LO) >= 1280) {//ITU 709
            WriteShortScaler(&SC_DEI_COLOR_COFFA_LO,HDTVcolorTab[0]);
            WriteShortScaler(&SC_DEI_COLOR_COFFB_LO,HDTVcolorTab[1]);
            WriteShortScaler(&SC_DEI_COLOR_COFFC_LO,HDTVcolorTab[2]);
            WriteShortScaler(&SC_DEI_COLOR_COFFD_LO,HDTVcolorTab[3]);
        }
        else {//ITU 601
            WriteShortScaler(&SC_DEI_COLOR_COFFA_LO,SDTVcolorTab[0]);
            WriteShortScaler(&SC_DEI_COLOR_COFFB_LO,SDTVcolorTab[1]);
            WriteShortScaler(&SC_DEI_COLOR_COFFC_LO,SDTVcolorTab[2]);
            WriteShortScaler(&SC_DEI_COLOR_COFFD_LO,SDTVcolorTab[3]);
        }
    }
    else {
        SC_HDMI_AUTO_CTRL &= ~BIT2;
        SC_VI_AUTO_CTRL &= ~BIT5; // Set auto-detection data path before CSC
        SC_DEI_CSC_CTRL = 0x00;
        SC_CSC_CTRL1 = 0x00;
        SC_CSC_CTRL2 = 0x00;
    }
}
