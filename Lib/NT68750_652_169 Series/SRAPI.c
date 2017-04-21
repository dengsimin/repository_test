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

#if ENABLE_SR == ON
//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************

//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************
/*!
 * Default setting of SR.
 */
static code UCHAR ucSuperResolutionTable[12] = {
#if IS_NT68661_SERIES
    0x00, 0x01, 0x00, 0x04, 0x06, 0x00, 0x11, 0x1C, 0x00, 0x1C, 0x2E, 0x00 //Defualt
#else
    0x00, 0x00, 0x00, 0x01, 0x03, 0x06, 0x03, 0x0F, 0x19, 0x06, 0x19, 0x2C //Defualt
#endif    
};

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
 * Initialize SR-related registers.
 ******************************************************************************/
void SRAPI_InitSR(void)
{
    UCHAR i, *p;

    p = &FLT3_COEFFICENT;
    for (i = 0; i < sizeof(ucSuperResolutionTable); i++) {
        *p = ucSuperResolutionTable[i];
        p++;
    }

    SC_SR_CTRL = SCREG_EA0; //SR off
    FLT3_ADD_SUB_SOURCE = 0x11;
    FLT3_BRIGHT_DARK_SOURCE = 0x01;
    FLT3_BRIGHT_DARK_SLOP = 0x47; // For pattern 1 white line
    FLT3_CORING_SLOP = 0x07; // value : 6 ~ 8 is better
}

/**************************************************************************//**
 * Turn on/off SR.
 * @param on ON to turn on SR else OFF.
 ******************************************************************************/
void SRAPI_TurnOnOff(UCHAR on)
{
    if (on) {
#if IS_NT68661_SERIES
        SC_VCR_CTRL |= BIT4;
        SC_DIGITAL_CTRL |= BIT7;
#endif
        SC_SR_CTRL |= BIT0;

    }
    else {
#if IS_NT68661_SERIES
        if (IsInterlaced()) {    
            SC_VCR_CTRL &= ~BIT4;
    }
    else {
            SC_VCR_CTRL |= BIT4;
        }
       
        if ((SC_ADC_MID_CH_SEL & 0x07) == YPBPR_CLAMP) {
            SC_DIGITAL_CTRL |= BIT7;  
    }
    else {
            SC_DIGITAL_CTRL &= ~BIT7;  
        }
#endif
       SC_SR_CTRL &= ~BIT0;
    }
}

/**************************************************************************//**
 * Set median filter.
 * @param ptr Pointer to the median filter block.
 ******************************************************************************/
void SRAPI_SetMDNFilter(MDNBlock *ptr)
{
    USHRT tmp;

    FLT1_TH = ptr->ucCutOffTH;
    FLT1_CUT_SLOP = ptr->ucCutOffSlop;

    tmp = (((ptr->ucHiVarGain & 0x0F) << 4) | (ptr->ucLoVarGain & 0x0F));
    FLT1_SLOP_TH = tmp;

    tmp = ((ptr->usVarTH & 0x0FFF) | (4 << 12));
    WriteShortScaler(&FLT1_VAR_TH_LO, tmp);
}

/**************************************************************************//**
 * Set USM filter.
 * @param ptr_rgn Pointer to the USM region block.
 * @param ptr_gain Pointer to the USM gain block.
 ******************************************************************************/
void SRAPI_SetUSMFilter(USMRegionBlock *ptr_rgn, USMGainBlock *ptr_gain)
{
    USHRT tmp;

    FLT3_CORING_TH = ptr_rgn->ucCutOffTH;

    tmp = (((ptr_rgn->ucHiVarGain & 0x0F) << 4) | (ptr_rgn->ucLoVarGain & 0x0F));
    FLT3_CORING_UP_LOW_TH = tmp;

    tmp = ((ptr_rgn->usVarTH & 0x0FFF) | (4 << 12));
    WriteShortScaler(&FLT3_COR_VAR_TH_LO, tmp);

    FLT3_GAIN = ptr_gain->ucGain & 0x3F;

    tmp = (((ptr_gain->ucHiVarGain & 0x0F) << 4) | (ptr_gain->ucLoVarGain & 0x0F));
    FLT3_GAIN_UP_LOW_TH = tmp;

    tmp = ((ptr_gain->usVarTH & 0x0FFF) | (7 << 12));
    WriteShortScaler(&FLT3_GAIN_VAR_TH_LO, tmp);
}

/**************************************************************************//**
 * Set threshold of USM low pass filter.
 * @param threshold Threshold of USM low poass filter.
 ******************************************************************************/
void SRAPI_SetUSMLPThreshold(USHRT threshold)
{
    WriteShortScaler(&FLT3_LP_VAR_TH_LO, ((threshold & 0x0FFF) | (3 << 12)));
}

/**************************************************************************//**
 * Set demo area of SR.
 * @param on ON to turn on demo mode else OFF.
 * @param region Left side or right side.
 * @param value Width of demo area.
 ******************************************************************************/
void SRAPI_SetDemoRegion(UCHAR on, SRDemoRegion region ,USHRT value)
{
    USM_DEMO_MODE = (on & 0xFE) | (region << 1);
    WriteShortScaler(&USM_DEMO_WIDTH_LO, (value & 0x0FFF));
}

#if IS_NT68661_SERIES
/**************************************************************************//**
 * Set Htotal (HPLL divider) pixel of SR.
 * @param htotal Horizontal pixel count of input timing.
 ******************************************************************************/
void SRAPI_SetHtotal(USHRT htotal)
{
    WriteShortScaler(&SC_SR_HTOTAL_LO, (htotal & 0x0FFF));
}

/**************************************************************************//**
 * Set input timing width and input timing height area of SR.
 * @param width Capture width.
 * @param height Capture height.
 ******************************************************************************/
void SRAPI_SetCaptureSize(USHRT width, USHRT height)
{
    WriteShortScaler(&SC_SR_HACT_LO, (width& 0x0FFF));
    WriteShortScaler(&SC_SR_VACT_LO, (height& 0x0FFF));
}

/**************************************************************************//**
 * Enable SR Block
 ******************************************************************************/
void SRAPI_SRBlockEnable(void)
{
    if(GetHCaptureSize() > 1920){// SR limitation
        SC_ADC_BAND_GAP |= BIT0;
    }
    else{
        SC_ADC_BAND_GAP &= ~BIT0;
    }
}

/**************************************************************************//**
 * Disable SR Block
 ******************************************************************************/
void SRAPI_SRBlockDisable(void)
{
     SC_ADC_BAND_GAP |= BIT0;
}
#endif

#endif //ENABLE_SR == ON
