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
#define CSC_SIM_CTRL BIT7 //0x055

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
static void SetHDMISRCSC(void);
static void SetVGADVISRCSC(void);
#if ((INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1) || (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)) && ENABLE_SR == ON
static void SetDPSRCSC(void);
#endif

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

#if (OSDTYPE == OSD_BENQ_V2) || (OSDTYPE == OSD_BENQ_V1) || (OSDTYPE == OSD_BENQ) // lrd_change_scaler_code
static xdata UCHAR ucCSCInputFormat = CSCInput_Unknown;

/**************************************************************************//**
 * Configure Capture CSC.
 * Always convert color space to YCbCr
 ******************************************************************************/
static void CSC_SetCaptureCSC(void)
{
    if (ucCSCClrSpace == CSC_OFF) {
        SC_CSC_CTRL1 = 0x00;
        SC_CSC_CTRL2 = 0x00;
    }
    else if (ucCSCClrSpace == CSC_HDMI_AUTO_CLR_SPACE) {
        switch(ucCSCInputFormat) {
            case CSCInput_Unknown:
                SC_CSC_CTRL1 = 0x00;                //by pass
                SC_CSC_CTRL2 = ~BIT0;  
                SC_CSC_CTRL2 &= ~BIT5;                          
                break;
            case CSCInput_601_Full_444:
            case CSCInput_709_Full_444:
            case CSCInput_xvYCC709_Full_444:
            case CSCInput_xvYCC601_Full_444:
                SC_CSC_CTRL1 = 0x00;                //by pass
                SC_CSC_CTRL2 &= ~BIT0;
                SC_CSC_CTRL2 &= ~BIT5;                          
                break;
            case CSCInput_601_Full_422:
            case CSCInput_709_Full_422:
            case CSCInput_xvYCC709_Full_422:
            case CSCInput_xvYCC601_Full_422:
                SC_CSC_CTRL1 = 0x00;                //by pass
                SC_CSC_CTRL2 &= ~BIT0;        
            SC_CSC_CTRL2 |= BIT5;
                break;
            case CSCInput_601_Limit_444:
            case CSCInput_709_Limit_444:
            case CSCInput_xvYCC709_Limit_444:
            case CSCInput_xvYCC601_Limit_444:
                SC_CSC_CTRL1 = 0x00;                //by pass
                SC_CSC_CTRL2 &= ~BIT0;
                SC_CSC_CTRL2 &= ~BIT5;       
                /*
                SC_CSC_CTRL1 = 0xB0;                  //limit to full 
                SC_CSC_CTRL2 = 0x19;        
                SC_CSC_CTRL2 &= ~BIT5;                                              
                */
                break;
            case CSCInput_601_Limit_422:
            case CSCInput_709_Limit_422:
            case CSCInput_xvYCC709_Limit_422:
            case CSCInput_xvYCC601_Limit_422:
                SC_CSC_CTRL1 = 0x00;                //by pass
                SC_CSC_CTRL2 &= ~BIT0;
                SC_CSC_CTRL2 |= BIT5;    
                /*
                SC_CSC_CTRL1 = 0xB0;                 //limit to full
                SC_CSC_CTRL2 = 0x19|BIT5;        
                */
                break;            
            case CSCInput_RGB_Full:
                SC_CSC_CTRL1 = 0xF8;//full to limit 601
                SC_CSC_CTRL2 = 0x19;
                SC_CSC_CTRL2 &= ~BIT5;                                              
                break;            
            case CSCInput_RGB_Limit:
                SC_CSC_CTRL1 = 0x88;//RGB to 601
                SC_CSC_CTRL2 = 0x19;
                SC_CSC_CTRL2 &= ~BIT5;                                              
                break;
            default:
                SC_CSC_CTRL1 = 0x00;//by pass
                SC_CSC_CTRL2 &= ~BIT0;  
                SC_CSC_CTRL2 &= ~BIT5;                                              
                break;                
        }
    }
    else {
        SC_CSC_CTRL1 = BIT7 | ((ucCSCClrSpace & 0x0F) << 3);
        SC_CSC_CTRL2 = 0x19;          
    }
}

/**************************************************************************//**
 * Configure Scaler CSC.
 * Since 370 cannot use 0x600/0x601 for CSC settings 
 *            -> we need to use 0x049~0x053 to configure scaler CSC
 ******************************************************************************/
static void CSC_SetScalerCSC(void)
{
    CSC_COEFE csc_coefe_set;

#if !lrd_dis_benq
    code CSC_COEFE color709toRGBcolor_coefe = {
        //0x629, 0x1D6, 0x0BB, 0x744, 0x400, 0
        0x18A4, 0x0758, 0x02EE, 0x1D0E, 0x1000, 0
    };

    code CSC_COEFE colorlimit709toRGBcolor_coefe = {
        //0x72C, 0x1223, 0x10DA, 0x876, 0x4A8, 1
        0x1CB0, 0x088B, 0x0368, 0x21D7, 0x12A0, 1 
    };
    
    code CSC_COEFE color601toRGBcolor_coefe = {
        //0x57C, 0x2CB, 0x158, 0x6EE, 0x400, 0
		0x15F0, 0x0B2B, 0x0560, 0x1BB6, 0x1000, 0
    };

    code CSC_COEFE colorlimit601toRGBcolor_coefe = {
        //0x662, 0x341, 0x190, 0x812, 0x4A8, 1
		0x1989, 0x0D02, 0x0642, 0x204A, 0x12A0, 1
    };

    code CSC_COEFE xvYCC709toRGBcolor_coefe = {
        //0x64D, 0x1DF, 0x0C0, 0x76C, 0x400, 0
		0x1932, 0x077D, 0x02FF, 0x1DB1, 0x1000, 0
    };

    code CSC_COEFE xvYCC709limittoRGBcolor_coefe = {
		0x1D57, 0x08B9, 0x037D, 0x2292, 0x12A0, 1
    };

    code CSC_COEFE xvYCC601toRGBcolor_coefe = {
        //0x59C, 0x2DB, 0x160, 0x717, 0x400, 0
        0x166F, 0x0B6D, 0x0581, 0x1C5A, 0x1000, 0
    };

    code CSC_COEFE xvYCC601limittoRGBcolor_coefe = {
		0x1A1F, 0x0D4E, 0x0669, 0x2104, 0x12A0, 1
    };

    //if ((((SC_HDMI_DET & BIT1) != 0) && ((SC_HDMI_INT_STATE1[3] & BIT0) != 0)) ||
        //(SC_DISPLAY_MUTE_CTRL & 0x03) != 0) { //when mute
#else

code CSC_COEFE color709toRGBcolor_coefe = {
    0x629, 0x1D6, 0x0BB, 0x744, 0x400, 0
};

code CSC_COEFE color601toRGBcolor_coefe = {
    0x57C, 0x2CB, 0x158, 0x6EE, 0x400, 0
};

code CSC_COEFE colorlimit601toRGBcolor_coefe = {
    0x662, 0x341, 0x190, 0x812, 0x4A8, 1
};

code CSC_COEFE xvYCC709toRGBcolor_coefe = {
    0x64D, 0x1DF, 0x0C0, 0x76C, 0x400, 0
};
code CSC_COEFE xvYCC601toRGBcolor_coefe = {
    0x59C, 0x2DB, 0x160, 0x717, 0x400, 0
};

#endif
#if !lrd_dis_benq
    switch(ucCSCInputFormat) {
        case CSCInput_709_Limit_444:
        case CSCInput_709_Limit_422:
            csc_coefe_set = colorlimit709toRGBcolor_coefe;
            break;

        case CSCInput_709_Full_444:
        case CSCInput_709_Full_422:
            csc_coefe_set = color709toRGBcolor_coefe;            
            break;            
            
        case CSCInput_xvYCC601_Limit_444:
        case CSCInput_xvYCC601_Limit_422:
            csc_coefe_set = xvYCC601limittoRGBcolor_coefe;  
            break;

        case CSCInput_xvYCC601_Full_444:
        case CSCInput_xvYCC601_Full_422:
            csc_coefe_set = xvYCC601toRGBcolor_coefe;              
            break;            
            
        case CSCInput_xvYCC709_Limit_444:
        case CSCInput_xvYCC709_Limit_422:
            csc_coefe_set = xvYCC709limittoRGBcolor_coefe;                     
            break;

        case CSCInput_xvYCC709_Full_444:
        case CSCInput_xvYCC709_Full_422:
            csc_coefe_set = xvYCC709toRGBcolor_coefe;     
            break;
            
        case CSCInput_RGB_Limit: //601 limit range
        case CSCInput_RGB_Full:            
            csc_coefe_set = colorlimit601toRGBcolor_coefe;
            break;

        case CSCInput_601_Limit_444:
        case CSCInput_601_Limit_422:
            csc_coefe_set = colorlimit601toRGBcolor_coefe;            
            break;
            
        case CSCInput_601_Full_444:
        case CSCInput_601_Full_422:              
        default:     //601
            csc_coefe_set = color601toRGBcolor_coefe;
            break;
    }
#else
    switch(ucCSCInputFormat) {
        case CSCInput_709_Limit_444:
        case CSCInput_709_Full_444:
        case CSCInput_709_Limit_422:
        case CSCInput_709_Full_422:
            csc_coefe_set = color709toRGBcolor_coefe;
            break;
            
        case CSCInput_xvYCC601_Limit_444:
        case CSCInput_xvYCC601_Full_444:
        case CSCInput_xvYCC601_Limit_422:
        case CSCInput_xvYCC601_Full_422:
            csc_coefe_set = xvYCC601toRGBcolor_coefe;  
            break;
            
        case CSCInput_xvYCC709_Limit_444:
        case CSCInput_xvYCC709_Full_444:
        case CSCInput_xvYCC709_Limit_422:
        case CSCInput_xvYCC709_Full_422:
            csc_coefe_set = xvYCC709toRGBcolor_coefe;                     
            break;

        case CSCInput_RGB_Limit: //601 limit range
        case CSCInput_RGB_Full:            
            csc_coefe_set = colorlimit601toRGBcolor_coefe;
            break;

        case CSCInput_601_Limit_444:
        case CSCInput_601_Full_444:
        case CSCInput_601_Limit_422:
        case CSCInput_601_Full_422:              
        default:     //601
            csc_coefe_set = color601toRGBcolor_coefe;
            break;
    }
#endif    
    //printf("SetScalerCSC_Coef    GetChannelIndex() = %bx %bx \r\n", ch, GetChannelIndex());

    WriteShortScaler(&SC_DEI_COLOR_COFFA_LO, csc_coefe_set.COEFE_A);
    WriteShortScaler(&SC_DEI_COLOR_COFFB_LO, csc_coefe_set.COEFE_B);
    WriteShortScaler(&SC_DEI_COLOR_COFFC_LO, csc_coefe_set.COEFE_C);
    WriteShortScaler(&SC_DEI_COLOR_COFFD_LO, csc_coefe_set.COEFE_D);       
    WriteShortScaler(&SC_DEI_COLOR_COFFE_LO, csc_coefe_set.COEFE_E);

    if (csc_coefe_set.COEFE_OFFSET == 1) {
        SC_DEI_COLOR_COFFE_HI |= BIT6;
    }
    else {
        SC_DEI_COLOR_COFFE_HI &= ~BIT6;
    }

    if (ucCSCInputFormat == CSCInput_Unknown) {
        SC_DEI_CSC_CTRL &= ~BIT0;
    }
    else {
         SC_DEI_CSC_CTRL = 0x09;//diasble CSC dither //0x19;
    }
}

/**************************************************************************//**
 *configure HDMI repetition
 ******************************************************************************/
static void CSC_SetRepetition(void)
{
    UCHAR ch,  repeat;

    if ((SC_HDMI_DET & BIT1) != 0) {
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

/**************************************************************************//**
 *configure Post pattern color to prevent abnormal display when mode change
 ******************************************************************************/
static void CSC_SetPostPatternColor(void)
{
    if (ucCSCClrSpace == CSC_OFF) {
        // Set video mute data for AVMute
        SC_VIDEO_BLANK_BLUE = 0x00;
        SC_VIDEO_BLANK_GREEN = 0x00;
        SC_VIDEO_BLANK_RED = 0x00;
    }
    else if (ucCSCClrSpace == CSC_HDMI_AUTO_CLR_SPACE) {        
        if (IsHDMIVideo()) { //HDMI & YCbCr color
            // Set video mute data for AVMute
            SC_VIDEO_BLANK_BLUE = 0x80;
            SC_VIDEO_BLANK_GREEN = 0x00;
            SC_VIDEO_BLANK_RED = 0x80;
        }
                else {
            SC_VIDEO_BLANK_BLUE = 0x00;
            SC_VIDEO_BLANK_GREEN = 0x00;
            SC_VIDEO_BLANK_RED = 0x00;
        }
    }
    else {
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
}

/**************************************************************************//**
 * Check Input color format by each interface.
 ******************************************************************************/
static void CSC_CheckInputFormat(UCHAR input_interface)
{
    USHRT input_hactive, input_vactive;

    if ((input_interface == DIGITAL_INPUT0) || (input_interface == DIGITAL_INPUT1) ||
        (input_interface == DIGITAL_INPUT2) || (input_interface == DIGITAL_INPUT3)) {


        ucAVIClrSpace = (SC_HDMI_AVI[0] & 0x60); 
        
        if (IsHDMIVideo()) { //HDMI & YCbCr color 
            ucCSCInputFormat = CSCInput_601_Limit_444;
            if ((SC_HDMI_AVI[1] & 0xC0) == 0xC0) {//others => xvYCC709 or xvYCC601
                ucCSCInputFormat+=8;

                if ((SC_HDMI_AVI[2] & 0x70) == 0x10) { // xvYCC709
                    ucCSCInputFormat+=4;
                }
            }
            else if ((SC_HDMI_AVI[1] & 0xC0) == 0x80) {//709
                ucCSCInputFormat+=4;
            }

            if ((SC_HDMI_AVI[2] & 0x0C) != 0x04) { // not limit range
                if((SC_HDMI_AVI[2] & 0x0C) == 0x00) { //default => check VIC
                    if ((SC_HDMI_AVI[3] & 0x7F) == 0x01) { //not video timing => full range
                        ucCSCInputFormat+=1;                                    
                    }
                }
                else {//full range
                    ucCSCInputFormat+=1;
                }
            }

            if (ucAVIClrSpace == BIT5) {//4:2:2                    
                ucCSCInputFormat+=2;            
            }            
        }
        else { //DVI | HDMI RGB color
            if ((SC_HDMI_DET & BIT1) != 0) {
            //if (UserData.ucInputSource == INPUT_SC_HDMI){
                if (UserData.ucHDMIRGBRange == COLOR_LIMIT){//if ((SC_HDMI_AVI[2] & 0x0C) == 0x04) { // Limit RGB to Full RGB
                    ucCSCInputFormat = CSCInput_RGB_Limit;
                }
                else if(UserData.ucHDMIRGBRange == COLOR_FULL){                 
                    ucCSCInputFormat = CSCInput_RGB_Full;
                }
                else{
                    if ((SC_HDMI_AVI[2] & 0x0C) == 0x08) { // Limit RGB to Full RGB
                        ucCSCInputFormat =CSCInput_RGB_Full;
                    }
                    else {
                        ucCSCInputFormat = CSCInput_RGB_Limit;
                    }
                }
            }
            else {
                ucCSCInputFormat = CSCInput_RGB_Full;
            }   
        }
    }
    else if ((input_interface == ANALOG_YPBPR_INPUT0) || (input_interface == ANALOG_YPBPR_INPUT1)) {
        input_hactive = ReadShortScaler(&SC_GI_CAP_HWID_LO);
        input_vactive = ReadShortScaler(&SC_GI_CAP_VLEN_LO);
        
        if (((input_hactive == 1920) && (input_vactive == 1080)) || ((input_hactive == 1280) && (input_vactive == 720)))
        {
            SC_CLAMP_BEGIN = 0x24;
        }
        else{
            SC_CLAMP_BEGIN = 0x01;
        }
        Sleep(20);
        
        if (((input_hactive == 1920) && (input_vactive == 1080)) || ((input_hactive == 1280) && (input_vactive == 720)))
        { 
            ucCSCInputFormat = CSCInput_709_Full_444;
        }
        else { //ITU601
            ucCSCInputFormat = CSCInput_601_Full_444;
        }
    }
#if (INPUT_INTERFACE&INPUT_DP_MASK)
    else if ( input_interface == DISPLAY_PORT_INPUT || input_interface == DISPLAY_PORT_INPUT1 ) {
        if (SC_DP_MSA_MISC1&BIT7) { //Y only...
            ucCSCInputFormat = CSCInput_RGB_Full;
        }
        else if((SC_DP_MSA_MISC0 & 0x1E) == 0x0A) {
            ucCSCInputFormat = CSCInput_601_Limit_422;            
        }
        else if((SC_DP_MSA_MISC0 & 0x1E) == 0x1A) {
            ucCSCInputFormat = CSCInput_709_Limit_422;            
        }
        else if((SC_DP_MSA_MISC0 & 0x1E) == 0x0C) {
            ucCSCInputFormat = CSCInput_601_Limit_444;            
        }
        else if((SC_DP_MSA_MISC0 & 0x1E) == 0x1C) {
            ucCSCInputFormat = CSCInput_709_Limit_444;
        }
        else if((SC_DP_MSA_MISC0 & 0x1E) == 0x02) {
            ucCSCInputFormat = CSCInput_xvYCC601_Limit_422;
        }
        else if((SC_DP_MSA_MISC0 & 0x1E) == 0x12) {
            ucCSCInputFormat = CSCInput_xvYCC709_Limit_422;
        }
        else if((SC_DP_MSA_MISC0 & 0x1E) == 0x04) {
            ucCSCInputFormat = CSCInput_xvYCC601_Limit_444;
        }
        else if((SC_DP_MSA_MISC0 & 0x1E) == 0x14) {
            ucCSCInputFormat = CSCInput_xvYCC709_Limit_444;
        }
        else if((SC_DP_MSA_MISC0 & 0x1E) == 0x08) {
            ucCSCInputFormat = CSCInput_RGB_Limit;
        }        
        else {
            ucCSCInputFormat = CSCInput_RGB_Full;
        }
    }
#endif
    else { // VGA
        SC_CLAMP_BEGIN = 0x01;    
        if (IsComponentInput()) {
            if (Custom_System.bisColorFormatRGB == FALSE) {
                UserData.bColorFormat = COLOR_YUV;
            }
            else {
                Custom_System.bisColorFormatRGB = FALSE;
            }
                
            if (UserData.bColorFormat == COLOR_RGB) { // only work in OS function
                ucCSCInputFormat = CSCInput_RGB_Full;
                SC_ADC_MID_CH_SEL = 0x00;
            }
            else {
                SC_ADC_MID_CH_SEL = 0x03;
                #if !lrd_dis_benq
                input_hactive = pInputTiming->usModeHActive;
                input_vactive = pInputTiming->usModeVActive;
                #else 
                input_hactive = InputTiming.usModeHActive;
                input_vactive = InputTiming.usModeVActive;
                #endif
                if (((input_hactive == 1920) && (input_vactive == 1080)) || ((input_hactive == 1280) && (input_vactive == 720)))
                {
                    SC_CLAMP_BEGIN = 0x24;
                }
                else {                            
                    SC_CLAMP_BEGIN = 0x01;
                }
                Sleep(20);      
                if (((input_hactive == 1920) && (input_vactive == 1080)) || ((input_hactive == 1280) && (input_vactive == 720)))
                { 
                    ucCSCInputFormat = CSCInput_709_Full_444;
                }
                else { //ITU601
                    ucCSCInputFormat = CSCInput_601_Full_444;
                }
            }
        }
        else{
            ucCSCInputFormat = CSCInput_RGB_Full;
            SC_ADC_MID_CH_SEL = 0x00;
        }
    }
}

static void SetColorSpace_Osd_HDMI_RGB_PC_Range(void)
{
    UCHAR current_input_interface;
   // UCHAR reg029; //lrd dis
    
    current_input_interface = GetCurrInputInterface();

  //  reg029 = SC_CHANNEL_INDEX; //lrd dis
   //SC_CHANNEL_INDEX &= ~BIT7;//don't set link path in all channel. //lrd dis
   // SetTMDSLinkPath(current_input_interface); //lrd dis

    CSC_CheckInputFormat(current_input_interface);
    CSC_SetPostPatternColor();
    CSC_SetRepetition();
    
//#if ENABLE_SR == ON //input--->(Capture CSC)--->YCbCr--->(Scaler CSC)--->RGB
    if (ucCSCInputFormat != CSCInput_Unknown) {
        SC_HDMI_AUTO_CTRL &= ~BIT2; //disable auto csc
        SC_TMDS_AUTO_CSC &= ~BIT1; //use manual CSC
        SC_SR_AUTO_CSC_CTRL &= ~BIT0;
        SC_DP_CSC_AUTO_CONF &= ~BIT0;       
    }
    else {
        SC_HDMI_AUTO_CTRL |= BIT2; //enable auto csc
        SC_TMDS_AUTO_CSC = 0x0E; //use auto CSC
        SC_SR_AUTO_CSC_CTRL |= BIT0;
        SC_DP_CSC_AUTO_CONF |= BIT0;     
    }

    CSC_SetScalerCSC();
    CSC_SetCaptureCSC();
    
//#else //input--->(Scaler CSC)--->RGB
//#endif


   // SC_CHANNEL_INDEX = reg029;  //lrd dis

}

void SetColorSpace(void)
{
#if !IS_NT68150_SERIES

    
    SetColorSpace_Osd_HDMI_RGB_PC_Range();


#else
    code int SDTVcolorTab[] = {
        1.371*1024+0.5,0.698*1024+0.5,0.336*1024+0.5,1.732*1024+0.5,
    };

    code int HDTVcolorTab[] = {
        1.540*1024+0.5,0.459*1024+0.5,0.183*1024+0.5,1.816*1024+0.5,
    };

    UCHAR current_input_interface;
    USHRT input_hactive, input_vactive;

    current_input_interface = GetCurrInputInterface();
    if ((current_input_interface == ANALOG_YPBPR_INPUT0) || (current_input_interface == ANALOG_YPBPR_INPUT1)) {
        input_hactive = ReadShortScaler(&SC_GI_CAP_HWID_LO);// 0x36
        input_vactive = ReadShortScaler(&SC_GI_CAP_VLEN_LO);// 0x32
    	if (((input_hactive == 1920) && (input_vactive == 1080)) || ((input_hactive == 1280) && (input_vactive == 720))){
    		SC_CLAMP_BEGIN = 0x24;// 0x021
    	}
    	else{
    		SC_CLAMP_BEGIN = 0x01;// 0x021
    	}
        Sleep(20);
        
        if (ucCSCClrSpace == CSC_OFF) {
            SC_VI_AUTO_CTRL &= ~BIT5; // Set auto-detection data path before CSC// 0x11b
            SC_CSC_CTRL1 = 0x00; // 0x54
            SC_CSC_CTRL2 = 0x00; // 0x55
        }
        else if (ucCSCClrSpace == CSC_HDMI_AUTO_CLR_SPACE) {
            SC_VI_AUTO_CTRL &= ~BIT5; // Set auto-detection data path before CSC// 0x11b
            SC_DEI_CSC_CTRL = 0x09; // 0x53
            SC_CSC_CTRL1 = 0x00; // 0x54
            SC_CSC_CTRL2 = 0x00; // 0x55
            if (((input_hactive == 1920) && (input_vactive == 1080)) || ((input_hactive == 1280) && (input_vactive == 720))){ //ITU709
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
            SC_VI_AUTO_CTRL &= ~BIT5; // Set auto-detection data path before CSC// 0x11b
            SC_CSC_CTRL1 = BIT7 | ((ucCSCClrSpace & 0x0F) << 3); // 0x54
            SC_CSC_CTRL2 = 0x19; // 0x55
        }
    }
    else { // VGA
/*
        SC_VI_AUTO_CTRL &= ~BIT5; // Set auto-detection data path before CSC    // 0x11b
        SC_DEI_CSC_CTRL = 0x00; // 0x53
        SC_CSC_CTRL1 = 0x00; // 0x54
        SC_CSC_CTRL2 = 0x00;
*/
        SC_VI_AUTO_CTRL &= ~BIT5; // Set auto-detection data path before CSC    // 0x11b
#if ENABLE_SR == ON
        SetVGADVISRCSC();
#else
        SC_CSC_CTRL2 = 0x00|CSC_SIM_CTRL; // 0x55
        SC_DEI_CSC_CTRL = 0x00; // 0x53
        SC_CSC_CTRL1 = 0x00; // 0x54
        SC_TMDS_AUTO_CSC = 0x00;  // 0x600
        SC_SR_AUTO_CSC_CTRL |= BIT0; // 0x601
#endif
    }
#endif

    //CSCDitherManualModeEn();
}

#else
void SetColorSpace(void)
{
#if !IS_NT68150_SERIES
    UCHAR current_input_interface, ch, repeat;
    USHRT input_hactive, input_vactive;


    current_input_interface = GetCurrInputInterface();
    if ((current_input_interface == DIGITAL_INPUT0) || (current_input_interface == DIGITAL_INPUT1)
     || (current_input_interface == DIGITAL_INPUT2) || (current_input_interface == DIGITAL_INPUT3)) {
        
         ucAVIClrSpace = (SC_HDMI_AVI[0] & 0x60);  // 0x744
         
        if (ucCSCClrSpace == CSC_OFF) {
            SC_VI_AUTO_CTRL &= ~BIT5; // Set auto-detection data path before CSC   // 0x11b
            SC_CSC_CTRL1 = 0x00;  // 0x54
            SC_CSC_CTRL2 = 0x00; // 0x55
            // Set video mute data for AVMute
            SC_VIDEO_BLANK_BLUE = 0x00;  // 0x64b
            SC_VIDEO_BLANK_GREEN = 0x00;
            SC_VIDEO_BLANK_RED = 0x00;
        }
        else if (ucCSCClrSpace == CSC_HDMI_AUTO_CLR_SPACE) {
            if (IsHDMIVideo()) { //HDMI & YCbCr color
                // --------------------------
                // Auto IN_CSC with SR mode
#if ENABLE_SR == ON
                SetHDMISRCSC();
#else
                SC_HDMI_AUTO_CTRL |= BIT2; //set auto csc// 0x6b5
                SC_TMDS_AUTO_CSC = 0x0E;  // 0x600
#endif
                // Set video mute data for AVMute
                SC_VIDEO_BLANK_BLUE = 0x80; // 0x64b
                SC_VIDEO_BLANK_GREEN = 0x00;
                SC_VIDEO_BLANK_RED = 0x80;
            }
            else { //DVI | HDMI RGB color
                SC_VI_AUTO_CTRL &= ~BIT5; // Set auto-detection data path before CSC  // 0x11b
#if ENABLE_SR == ON
                if ((SC_HDMI_DET & BIT1) != 0) { //HDMI RGB color // 0x734
                    SetHDMISRCSC();
                }
                else { //dvi
                    SetVGADVISRCSC();
                }
#else
//                SC_HDMI_AUTO_CTRL |= BIT2; //set auto csc// 0x6b5
//                SC_TMDS_AUTO_CSC = 0x0E;  // 0x600
                SC_HDMI_AUTO_CTRL &= ~BIT2; //set auto csc// 0x6b5
                SC_TMDS_AUTO_CSC = 0x0E;  // 0x600
                if ((SC_HDMI_DET & BIT1) != 0) {// 0x734
                    if ((SC_HDMI_AVI[2] & 0x0C) == 0x04) { // Limit RGB to Full RGB// 0x746
                        SC_CSC_CTRL1 = 0xB8; // 0x54
                        SC_CSC_CTRL2 = 0x19; // 0x55
                    }
                    else {
                        SC_CSC_CTRL1 = 0x00; // 0x54
                        SC_CSC_CTRL2 = 0x00;
                    }
                }
                else {
                    SC_CSC_CTRL1 = 0x00; // 0x54
                    SC_CSC_CTRL2 = 0x00; // 0x55
                }
#endif
                // Set video mute data for AVMute
                SC_VIDEO_BLANK_BLUE = 0x00; // 0x64b
                SC_VIDEO_BLANK_GREEN = 0x00;
                SC_VIDEO_BLANK_RED = 0x00;
            }
        }
        else {
            SC_VI_AUTO_CTRL |= BIT5; // Set auto-detection data path after CSC// 0x11b
            SC_CSC_CTRL1 = BIT7 | ((ucCSCClrSpace & 0x0F) << 3); // 0x54
            SC_CSC_CTRL2 = 0x19; // 0x55

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
                    SC_VIDEO_BLANK_BLUE = 0x80; // 0x64b
                    SC_VIDEO_BLANK_GREEN = 0x00;
                    SC_VIDEO_BLANK_RED = 0x80;
                    break;
                default :
                    SC_VIDEO_BLANK_BLUE = 0x00; // 0x64b
                    SC_VIDEO_BLANK_GREEN = 0x00;
                    SC_VIDEO_BLANK_RED = 0x00;
                    break;
            }
        }
//////////////////////////////////////////////////////////////////////////
        if ((SC_HDMI_DET & BIT1) != 0) {// 0x734
            if (ucAVIClrSpace == BIT5) {//4:2:2
                SC_CSC_CTRL2 |= BIT5; // 0x55
            }
            //Set repeat for Manual CSC mode
            ch = SC_HDMI_AVI[4] & 0x0F;// 0x748
            repeat = SC_HDMI_CLK_INT & 0x0F;//default: No Repetition  // 0x608
            if (ch == 0x01) {//pixel sent 2 times
                repeat |= 0x50;
            }
            else if (ch == 0x03) {//pixel sent 4 times
                repeat |= 0xF0;
            }
            SC_HDMI_CLK_INT = repeat;// 0x608
        }
        else {
            SC_HDMI_CLK_INT &= 0x0F;// 0x608
        }
///////////////////////////////////////////////////////////////////////////
    }
    else if ((current_input_interface == ANALOG_YPBPR_INPUT0) || (current_input_interface == ANALOG_YPBPR_INPUT1)) {
        input_hactive = ReadShortScaler(&SC_GI_CAP_HWID_LO);// 0x36
        input_vactive = ReadShortScaler(&SC_GI_CAP_VLEN_LO);// 0x32
    	if (((input_hactive == 1920) && (input_vactive == 1080)) || ((input_hactive == 1280) && (input_vactive == 720))){
    		SC_CLAMP_BEGIN = 0x24;// 0x021
    	}
    	else{
    		SC_CLAMP_BEGIN = 0x01;// 0x021
    	}
        Sleep(20);
        
        if (ucCSCClrSpace == CSC_OFF) {
            SC_VI_AUTO_CTRL &= ~BIT5; // Set auto-detection data path before CSC// 0x11b
            SC_CSC_CTRL1 = 0x00; // 0x54
            SC_CSC_CTRL2 = 0x00; // 0x55
        }
        else if (ucCSCClrSpace == CSC_HDMI_AUTO_CLR_SPACE) {
            SC_VI_AUTO_CTRL &= ~BIT5; // Set auto-detection data path before CSC// 0x11b

            SC_DEI_CSC_CTRL = 0x19;  // 0x53
            SC_CSC_CTRL2 = 0x00;//|CSC_SIM_CTRL; // 0x55
            SC_CSC_CTRL1 = 0x00; // 0x54
            if (((input_hactive == 1920) && (input_vactive == 1080)) || ((input_hactive == 1280) && (input_vactive == 720))){ //ITU709
                SC_SR_AUTO_CSC_CTRL = 0x31;  // 0x601
            }
            else { //ITU601
                SC_SR_AUTO_CSC_CTRL = 0x01; // 0x601
            }
        }
        else {
            SC_VI_AUTO_CTRL &= ~BIT5; // Set auto-detection data path before CSC// 0x11b
            SC_CSC_CTRL1 = BIT7 | ((ucCSCClrSpace & 0x0F) << 3); // 0x54
            SC_CSC_CTRL2 = 0x19; // 0x55
        }
    }
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1) || (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
    else if (current_input_interface == DISPLAY_PORT_INPUT) {
#if ENABLE_SR == ON
        SetDPSRCSC();
#else
        SC_DP_CSC_AUTO_CONF |= BIT0;  // 0x1040
#endif
    }
#endif
    else { // VGA
        SC_VI_AUTO_CTRL &= ~BIT5; // Set auto-detection data path before CSC    // 0x11b
#if ENABLE_SR == ON
        SetVGADVISRCSC();
#else
        SC_CSC_CTRL2 = 0x00|CSC_SIM_CTRL; // 0x55
        SC_DEI_CSC_CTRL = 0x00; // 0x53
        SC_CSC_CTRL1 = 0x00; // 0x54
        SC_TMDS_AUTO_CSC = 0x00;  // 0x600
        SC_SR_AUTO_CSC_CTRL |= BIT0; // 0x601
#endif
    }
#else
    code int SDTVcolorTab[] = {
        1.371*1024+0.5,0.698*1024+0.5,0.336*1024+0.5,1.732*1024+0.5,
    };

    code int HDTVcolorTab[] = {
        1.540*1024+0.5,0.459*1024+0.5,0.183*1024+0.5,1.816*1024+0.5,
    };

    UCHAR current_input_interface;
    USHRT input_hactive, input_vactive;

    current_input_interface = GetCurrInputInterface();
    if ((current_input_interface == ANALOG_YPBPR_INPUT0) || (current_input_interface == ANALOG_YPBPR_INPUT1)) {
        input_hactive = ReadShortScaler(&SC_GI_CAP_HWID_LO);// 0x36
        input_vactive = ReadShortScaler(&SC_GI_CAP_VLEN_LO);// 0x32
    	if (((input_hactive == 1920) && (input_vactive == 1080)) || ((input_hactive == 1280) && (input_vactive == 720))){
    		SC_CLAMP_BEGIN = 0x24;// 0x021
    	}
    	else{
    		SC_CLAMP_BEGIN = 0x01;// 0x021
    	}
        Sleep(20);
        
        if (ucCSCClrSpace == CSC_OFF) {
            SC_VI_AUTO_CTRL &= ~BIT5; // Set auto-detection data path before CSC// 0x11b
            SC_CSC_CTRL1 = 0x00; // 0x54
            SC_CSC_CTRL2 = 0x00; // 0x55
        }
        else if (ucCSCClrSpace == CSC_HDMI_AUTO_CLR_SPACE) {
            SC_VI_AUTO_CTRL &= ~BIT5; // Set auto-detection data path before CSC// 0x11b
            SC_DEI_CSC_CTRL = 0x09; // 0x53
            SC_CSC_CTRL1 = 0x00; // 0x54
            SC_CSC_CTRL2 = 0x00; // 0x55
            if (((input_hactive == 1920) && (input_vactive == 1080)) || ((input_hactive == 1280) && (input_vactive == 720))){ //ITU709
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
            SC_VI_AUTO_CTRL &= ~BIT5; // Set auto-detection data path before CSC// 0x11b
            SC_CSC_CTRL1 = BIT7 | ((ucCSCClrSpace & 0x0F) << 3); // 0x54
            SC_CSC_CTRL2 = 0x19; // 0x55
        }
    }
    else { // VGA
/*
        SC_VI_AUTO_CTRL &= ~BIT5; // Set auto-detection data path before CSC    // 0x11b
        SC_DEI_CSC_CTRL = 0x00; // 0x53
        SC_CSC_CTRL1 = 0x00; // 0x54
        SC_CSC_CTRL2 = 0x00;
*/
        SC_VI_AUTO_CTRL &= ~BIT5; // Set auto-detection data path before CSC    // 0x11b
#if ENABLE_SR == ON
        SetVGADVISRCSC();
#else
        SC_CSC_CTRL2 = 0x00|CSC_SIM_CTRL; // 0x55
        SC_DEI_CSC_CTRL = 0x00; // 0x53
        SC_CSC_CTRL1 = 0x00; // 0x54
        SC_TMDS_AUTO_CSC = 0x00;  // 0x600
        SC_SR_AUTO_CSC_CTRL |= BIT0; // 0x601
#endif
    }
#endif

    //CSCDitherManualModeEn();
}
#endif

#if !((OSDTYPE == OSD_BENQ_V2) || (OSDTYPE == OSD_BENQ_V1) || (OSDTYPE == OSD_BENQ) )

#if ENABLE_HDMI == ON
/**************************************************************************//**
 * Set HDMI SR CSC
 ******************************************************************************/
 
void SetHDMISRCSC(void)
{
    UCHAR Reg0x1ED, ch, Reg0x600, Reg0x649;
//    if ((SC_DISPLAY_MUTE_CTRL & 0x03) != 0) { //when mute
    if (((SC_DISPLAY_MUTE_CTRL & 0x03) != 0) || ((SC_HDMI_INT_STATE1[3] & BIT0) != 0)) { //when mute 0x154,0x673
        ch = SC_SR_CTRL; //set SR on// 0xea0
        Reg0x1ED = SC_ADC_BAND_GAP;// 0x1ed
        SC_ADC_BAND_GAP &= ~BIT0;// 0x1ed
        SC_SR_CTRL = 0x51;// 0xea0
        SC_HDMI_AUTO_CTRL |= BIT2; //set auto csc// 0x6b5
        SC_TMDS_AUTO_CSC = 0x0E;  // 0x600
        SC_HDMI_RESET_CTRL &= ~BIT3;// 0x713
        Sleep(50); //wait one frame
        Reg0x649 = SC_ICPCSC_AUTOSTATUS; //read Reg0x600 & Reg0x649
        Reg0x600 = SC_TMDS_AUTO_CSC;  // 0x600
        SC_HDMI_AUTO_CTRL &= ~BIT2;//set manual csc// 0x6b5
        SC_TMDS_AUTO_CSC &= ~BIT1;  // 0x600
        SC_SR_CTRL = ch; //restore SR// 0xea0
        SC_ADC_BAND_GAP = Reg0x1ED;// 0x1ed
        ch = SC_CSC_CTRL1 & 0x87; //fill Reg0x054 // 0x54
        SC_CSC_CTRL1 = ch | ((Reg0x649 & 0xF0) >> 1) | BIT7; // 0x54
        ch = SC_SR_AUTO_CSC_CTRL & 0x0F; //fill Reg0x601 // 0x601
        SC_SR_AUTO_CSC_CTRL = ch | (Reg0x600 & 0xF0) | BIT0; // 0x601
        if ((Reg0x600 & BIT0) == 0) { //set Reg0x053[0]
            SC_DEI_CSC_CTRL = 0x19; // 0x53
        }
        else {
            SC_DEI_CSC_CTRL = 0x18; // 0x53
        }
        if ((Reg0x649 & BIT0) == 0) { //set Reg0x055[0]
            SC_CSC_CTRL2 = 0x19; // 0x55
        }
        else {
            SC_CSC_CTRL2 = 0x18; // 0x55
        }
///////////////////////////////////////////////////////////////////////////////
#if 1//TPV Limited RGB
        if (!IsHDMIVideo()) { //HDMI RGB color
            if ((SC_HDMI_AVI[2] & 0x0C) == 0x04) { // Limited RGB// 0x746
                if(GetSCID() == SCID_770_E){
                    SC_CSC_CTRL1 = 0xF0;//limited RGB to Ycbcr601 // 0x54
                }
                else {
                    SC_CSC_CTRL1 = 0x88;//RGB to Ycbcr601 // 0x54
                }
            }
            else {
                if(GetSCID() == SCID_770_E){
                    SC_CSC_CTRL1 = 0x88;//Full RGB to Ycbcr601 // 0x54
                }
                else {
                    SC_CSC_CTRL1 = 0xF8;//Full RGB to limited Ycbcr601 // 0x54
                }
            }      
 
            if(GetSCID() == SCID_770_E){
                SC_SR_AUTO_CSC_CTRL = 0x03; //Ycbcr601 to RGB            // 0x601
            }
            else {
                SC_SR_AUTO_CSC_CTRL = 0x23; //limited Ycbcr601 to RGB         // 0x601   
            }
        }
#endif
///////////////////////////////////////////////////////////////////////////////
    }
}
#endif

/**************************************************************************//**
 * Set VGA DVI SR CSC.
 ******************************************************************************/
void SetVGADVISRCSC(void)
{
    if ((SC_DISPLAY_MUTE_CTRL & 0x03) != 0) { //when mute
        SC_HDMI_AUTO_CTRL &= ~BIT2;//set manual csc// 0x6b5
        SC_TMDS_AUTO_CSC &= ~BIT1;  // 0x600
        SC_DEI_CSC_CTRL = 0x19; // 0x53
        SC_CSC_CTRL1 = 0x88; // 0x54
        SC_CSC_CTRL2 = 0x99; // 0x55
        SC_SR_AUTO_CSC_CTRL = 0x03; // 0x601
    }
}
#if ((INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1) || (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)) && ENABLE_SR == ON
/**************************************************************************//**
 * Set DP SR CSC.
 ******************************************************************************/
 
void SetDPSRCSC(void)
{
    UCHAR Reg0x1ED, ch, Reg0x109D, Reg0x109E;
    if ((SC_DISPLAY_MUTE_CTRL & 0x03) != 0) { //when mute   // 0x154
        ch = SC_SR_CTRL; //set SR on   // 0xea0
        Reg0x1ED = SC_ADC_BAND_GAP;  // 0x1ed
        SC_ADC_BAND_GAP &= ~BIT0;// 0x1ed
        SC_SR_CTRL = 0x51;// 0xea0
        SC_DP_CSC_AUTO_CONF |= BIT0; //DP CSC auto // 0x1040
        SC_HDMI_RESET_CTRL &= ~BIT3;  // 0x713
        Sleep(50); //wait one frame
        Reg0x109D = SC_DP_109D; //read Reg0x109D & Reg0x109E
        Reg0x109E = SC_DP_109E;
        SC_DP_CSC_AUTO_CONF &= ~BIT0; //DP CSC manual // 0x1040
        SC_SR_CTRL = ch; //restore SR// 0xea0
        SC_ADC_BAND_GAP = Reg0x1ED;// 0x1ed

        ch = SC_CSC_CTRL1 & 0x87; //fill Reg0x054 // 0x54
        SC_CSC_CTRL1 = ch | ((Reg0x109D & 0x0F) << 3) | BIT7; // 0x54
        ch = SC_SR_AUTO_CSC_CTRL & 0x0F; //fill Reg0x601 // 0x601
        SC_SR_AUTO_CSC_CTRL = ch | ((Reg0x109E & 0x0F) << 4) | BIT0; // 0x601
        if ((Reg0x109E & BIT6) == 0) { //set Reg0x053[0]
            SC_DEI_CSC_CTRL = 0x1A; // 0x53
        }
        else {
            SC_DEI_CSC_CTRL = 0x1B; // 0x53
        }
        if ((Reg0x109E & BIT4) == 0) { //set Reg0x055[0]
            SC_CSC_CTRL2 = 0x1A; // 0x55
        }
        else {
            SC_CSC_CTRL2 = 0x1B; // 0x55
        }
        if ((Reg0x109E & BIT7) != 0) {//4:2:2
            SC_CSC_CTRL2 |= BIT5; // 0x55
        }
    }
}
#endif
#endif
