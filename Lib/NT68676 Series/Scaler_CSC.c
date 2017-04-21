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
#if ENABLE_HDMI == ON
    UCHAR current_input_interface, repeat, ch, hd_flag;
    USHRT input_hactive, input_vactive;

    HDMIEnableAVC(FALSE);
    SC_DEI_CSC_CTRL = 0x00;

    current_input_interface = GetCurrInputInterface();
    if ((current_input_interface == DIGITAL_INPUT0) || (current_input_interface == DIGITAL_INPUT1)) {
        
        ucAVIClrSpace = (SC_HDMI_AVI[0] & 0x60); 

        if (ucCSCClrSpace == CSC_OFF) {
            SC_VI_AUTO_CTRL &= ~BIT5; // Set auto-detection data path before CSC
            SC_CSC_CTRL1 = 0x00;
            SC_CSC_CTRL2 = 0x00;
            // Set video mute data for AVMute
            SC_VIDEO_BLANK_BLUE = 0x00;
            SC_VIDEO_BLANK_GREEN = 0x00;
            SC_VIDEO_BLANK_RED = 0x00;
        }
        else if (ucCSCClrSpace == CSC_HDMI_AUTO_CLR_SPACE) {
            if (IsHDMIVideo()) { //HDMI & YCbCr color
                SC_VI_AUTO_CTRL |= BIT5; // Set auto-detection data path after CSC
                ch = SC_HDMI_AVI[1] & (BIT7|BIT6);

                // Sometimes, there is no 601/709 information in AVI info-frame. 
                // If no 601/709 information, we use resolution to identify the input
                // timing as HD or SD.
                // HD is 709.
                // SD is 601.
                hd_flag = FALSE;
                if ((abs(GetDigInputHActiveImmediate() - 1920) < 4) &&
                    (abs(GetDigInputVActiveImmediate() - 1080) < 2)) {
                    hd_flag = TRUE;
                }
                else if ((abs(GetDigInputHActiveImmediate() - 1280) < 4) &&
                    (abs(GetDigInputVActiveImmediate() - 720) < 2)) {
                    hd_flag = TRUE;
                }
                else if ((abs(GetDigInputHActiveImmediate() - 1920) < 4) &&
                    (abs(GetDigInputVActiveImmediate() - 540) < 2) &&
                    IsInterlaced()) {
                    hd_flag = TRUE;
                }
                
                if (ch == BIT7) {//ITU 709
                    SC_CSC_CTRL1 = 0x98;
                }
                else if (ch == BIT6) {//ITU 601
                    SC_CSC_CTRL1 = 0x80;
                }
                else if (ch == (BIT7|BIT6)) {//extended
                    ch = SC_HDMI_AVI[2] & (BIT6|BIT5|BIT4);
                    if (ch == 0x00) {//xvYCC601
                        SC_CSC_CTRL1 = 0xC0;
                    }
                    else if (ch == BIT4) {//xvYCC709
                        SC_CSC_CTRL1 = 0xD8;
                    }
                    else if (hd_flag) {
                        SC_CSC_CTRL1 = 0xD8;
                    }
                    else {
                        SC_CSC_CTRL1 = 0xC0;
                    }
                }
                else if (hd_flag) {
                    SC_CSC_CTRL1 = 0x98;
                }
                else {
                    SC_CSC_CTRL1 = 0x80;
                }

                // Limit Range
                if ((SC_HDMI_AVI[2] & 0x0C) == 0x04) {
                    SC_CSC_CTRL1 += 0x10;
                }
                //else if (((SC_HDMI_AVI[2] & 0x0C) == 0x00) &&
                //         ((SC_HDMI_AVI[3] & 0x7F) > 1)) {
                else if ((SC_HDMI_AVI[2] & 0x0C) == 0x00) {
                    SC_CSC_CTRL1 += 0x10;
                }

                SC_CSC_CTRL2 = 0x19;

                // Set video mute data for AVMute
                SC_VIDEO_BLANK_BLUE = 0x80;
                SC_VIDEO_BLANK_GREEN = 0x00;
                SC_VIDEO_BLANK_RED = 0x80;
            }
            else { //DVI | HDMI RGB color
                SC_VI_AUTO_CTRL &= ~BIT5; // Set auto-detection data path before CSC
                if ((SC_HDMI_DET & BIT1) != 0) {
                    if ((SC_HDMI_AVI[2] & 0x0C) == 0x04) { // Limit RGB to Full RGB
                        SC_CSC_CTRL1 = 0xB8;
                        SC_CSC_CTRL2 = 0x19;
                    }
                    else {
                        SC_CSC_CTRL1 = 0x00;
                        SC_CSC_CTRL2 = 0x00;
                    }
                }
                else {
                    SC_CSC_CTRL1 = 0x00;
                    SC_CSC_CTRL2 = 0x00;
                }

                // Set video mute data for AVMute
                SC_VIDEO_BLANK_BLUE = 0x00;
                SC_VIDEO_BLANK_GREEN = 0x00;
                SC_VIDEO_BLANK_RED = 0x00;
            }
        }
        else {
            SC_VI_AUTO_CTRL |= BIT5; // Set auto-detection data path after CSC
            SC_CSC_CTRL1 = BIT7 | ((ucCSCClrSpace & 0x0F) << 3);
            SC_CSC_CTRL2 = 0x19;

            // Set video mute data for AVMute
            switch(ucCSCClrSpace) {
                case CSC_YPbPr601_TO_RGB:
                case CSC_YPbPr601_TO_RGB_FULL:
                case CSC_YPbPr709_TO_RGB:
                case CSC_YPbPr709_TO_RGB_FULL:
                case CSC_YPbPr_TO_YPbPr_FULL:
                case CSC_xvYCC601_TO_RGB:
                case CSC_xvYCC601_TO_RGB_FULL:
                case CSC_xvYCC709_TO_RGB:
                case CSC_xvYCC709_TO_RGB_FULL:
                    SC_VIDEO_BLANK_BLUE = 0x80;
                    SC_VIDEO_BLANK_GREEN = 0x00;
                    SC_VIDEO_BLANK_RED = 0x80;
                    break;
                default :
                    SC_VIDEO_BLANK_BLUE = 0x00;
                    SC_VIDEO_BLANK_GREEN = 0x00;
                    SC_VIDEO_BLANK_RED = 0x00;
                    break;
            }
        }

        if ((SC_HDMI_DET & BIT1) != 0) {
            if (ucAVIClrSpace == BIT5) {//4:2:2
                SC_CSC_CTRL2 |= BIT5;
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
        else {
            SC_HDMI_CLK_INT &= 0x0F;
        }
    }
    else if ((current_input_interface == ANALOG_YPBPR_INPUT0) || (current_input_interface == ANALOG_YPBPR_INPUT1)) {
        input_hactive = ReadShortScaler(&SC_GI_CAP_HWID_LO);
        input_vactive = ReadShortScaler(&SC_GI_CAP_VLEN_LO);
    	if (((input_hactive == 1920) && (input_vactive == 1080)) || ((input_hactive == 1280) && (input_vactive == 720))){
    		SC_CLAMP_BEGIN = 0x24;
    	}
    	else{
    		SC_CLAMP_BEGIN = 0x01;
    	}
        Sleep(20);
        
        if (ucCSCClrSpace == CSC_OFF) {
            SC_VI_AUTO_CTRL &= ~BIT5; // Set auto-detection data path before CSC
            SC_CSC_CTRL1 = 0x00;
            SC_CSC_CTRL2 = 0x00;
        }
        else if (ucCSCClrSpace == CSC_HDMI_AUTO_CLR_SPACE) {
            SC_VI_AUTO_CTRL |= BIT5; // Set auto-detection data path after CSC
        	if (((input_hactive == 1920) && (input_vactive == 1080)) || ((input_hactive == 1280) && (input_vactive == 720))){ //ITU709
                SC_CSC_CTRL1 = 0xA8;
            }
            else { //ITU601
                SC_CSC_CTRL1 = 0x90;
            }
            SC_CSC_CTRL2 = 0x19;
        }
        else {
            SC_VI_AUTO_CTRL |= BIT5; // Set auto-detection data path after CSC
            SC_CSC_CTRL1 = BIT7 | ((ucCSCClrSpace & 0x0F) << 3);
            SC_CSC_CTRL2 = 0x19;
        }
    }
    else {
        SC_VI_AUTO_CTRL &= ~BIT5; // Set auto-detection data path before CSC
        SC_CSC_CTRL1 = 0x00;
        SC_CSC_CTRL2 = 0x00;
    }
#else
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
#endif

    //CSCDitherManualModeEn();
}
