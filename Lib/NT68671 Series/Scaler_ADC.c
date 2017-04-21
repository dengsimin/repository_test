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
/*!
 * Values for the counter of HSync frequency.
 * This value is from the HSync counter, of sync processor, multiplying by 8192.
 * Not from HPLL directly.
 */
xdata ULONG ulHFreqCounter;

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
 * Initialize ADC-related registers.
 ******************************************************************************/
void ADCInit(void)
{
    SC_ADC_TEST1 = SCREG_002_210M;
    SC_ADC_TEST2 = SCREG_005_210M;
    SC_ADC_OP_CURRENT = SCREG_1F1_210M;
    SC_ADC_REG_1D = 0x6E;
    SC_ADC_BAND_GAP = 0x08;

    VGA_PowerOn();

    SC_ADC_BW_CTRL = 0x07;
    SC_CLAMP_BEGIN = 0x0C;
    SC_CLAMP_WIDTH = 0x81;

    SC_SOG_CLAMPING_CTRL = 0x00;
    SC_SOG_GLITCH_MASK_LO = 0x55;
    SC_SOG_DIGITAL_FILTER_CTRL = 0x00;
    SC_SOG_SLICER_CTRL = 0x00;

    SC_HPLL_CTRL1 = 0x41;
    SC_HPLL_CTRL2 = 0xC0;
    SC_HPLL_CTRL3 = 0x00;
    SC_HPLL_PHASE_CTRL = 0x38;
    SC_HPLL_PHASE_CTRL1 = 0x00;
    SC_HPLL_PHASE_CTRL2 = 0x00;
    SC_HPLL_PHASE_CTRL1 = 0x40;
    SC_HPLL_PHASE_CTRL2 = 0x00;
    SC_HPLL_PHASE_CTRL1 = 0x80;
    SC_HPLL_PHASE_CTRL2 = 0x00;

    SchmittTriggerPowerOn();
}

/**************************************************************************//**
 * Get the input htotal of analog input.
 * @return Input htotal of analog input.
 ******************************************************************************/
USHRT GetAngInputHTotal(void)
{
    return ReadShortScaler(&SC_HSDDS_DIVIDER_LO);
}

/**************************************************************************//**
 * Get the ADCPLL phase setting.
 * @return ADCPLL phase setting.
 ******************************************************************************/
UCHAR GetAngInputPhase(void)
{
    return SC_HPLL_PHASE_CTRL1;
}

/**************************************************************************//**
 * Set ADC bandwidth.
 * @param bw ADC bandwidth. If bw is ADC_BW_AUTO, the bandwidth is auto-configured.
 ******************************************************************************/
void SetADCBandWidth(ADCBandW bw)
{
    ULONG pix_clk;

    if (bw == ADC_BW_AUTO) {
        /*
        Analog bandwidth select ( RGB input capacitor select )
        111 : 500 MHz
        110 : 450 MHz
        101 : 400 MHz
        100 : 350 MHz
        011 : 300 MHz
        010 : 250 MHz
        001 : 150 MHz
        000 : 75  MHz
        */
        pix_clk = ReadShortScaler(&SC_HSDDS_DIVIDER_LO);
        pix_clk = pix_clk * usHSyncFreq;
    
        if (pix_clk < 370000) {// < 800x600/60Hz
            bw = ADC_BW_75MHz;
        }
        else if (pix_clk < 550000) { // < 1024x760/60Hz
            bw = ADC_BW_150MHz;
        }
        else if (pix_clk < 800000) {// < 1152x8
            bw = ADC_BW_250MHz;
        }
        else if (pix_clk < 900000) {
            bw = ADC_BW_300MHz;
        }
        else if (pix_clk < 1100000) {
            bw = ADC_BW_350MHz;
        }
        else if (pix_clk < 1400000) {
            bw = ADC_BW_400MHz;
        }
        else if (pix_clk < 1800000) {
            bw = ADC_BW_450MHz;
        }
        else {
            bw = ADC_BW_500MHz;
        }
    }
    
    SC_ADC_BW_CTRL &= 0xF8;
    SC_ADC_BW_CTRL |= (bw & 0x07);
}

/**************************************************************************//**
 * Configure ADCPLL (capture clock).
 * @param htotal Htotal of analog input.
 ******************************************************************************/
void SetADCPLL(USHRT htotal)
{
#define HSYNC_BAND_LOW  ((float)REF_CLK/12000000*250)
#define HSYNC_BAND_MID  ((float)REF_CLK/12000000*500)

    ULONG pixel_rate;

    if (usHSyncFreq < HSYNC_BAND_LOW) {
        SC_HPLL_LINE_CNT = 0x0A; //1024 Lines
    }
    else if (usHSyncFreq < HSYNC_BAND_MID) {
        SC_HPLL_LINE_CNT = 0x0B; //2048 Lines
    }
    else {
        SC_HPLL_LINE_CNT = 0x0C; //4096 Lines
    }
    SC_HPLL_FREQ_CTRL = 0x00; //Enable updating HS_CNT
    pixel_rate = ReadShortScaler(&SC_GI_HCNT_LO) & 0x1FFF;
    if ((pixel_rate == 0x1FFF) || (pixel_rate == 0)) {
        ulHFreqCounter = 0xFFFFFFFF;
    }
    else {
        ulHFreqCounter = (ULONG)pixel_rate * 8192;
    }
    WriteShortScaler(&SC_HSDDS_DIVIDER_LO, htotal);

#undef HSYNC_BAND_LOW
#undef HSYNC_BAND_MID
}

/**************************************************************************//**
 * Set ADCPLL phase.
 * @param phase ADCPLL phase.
 ******************************************************************************/
void SetADCPhase(UCHAR phase)
{
    SC_HPLL_PHASE_CTRL1 = phase;
    ucADCPhase100 = ((USHRT)phase * 100 + (MAXIMUM_PHASE>>1)) / MAXIMUM_PHASE;
}

/**************************************************************************//**
 * Wait until HPLL stable.
 * The maximum waiting time is 300ms.
 * The minimum waiting time is 30ms.
 * This function can not be performed prior to SetADCPLL.
 ******************************************************************************/
void WaitHPLLstable(void)
{
    ULONG hcounter;
    USHRT localtimer;

    localtimer = GetTimerTick();
    do {
        hcounter = Read3ByteScaler(&SC_HS_CNT_RESULT_LO);
        if (SC_HPLL_LINE_CNT == 0x0A) {//1024 line
            hcounter <<= 2;
        }
        else if (SC_HPLL_LINE_CNT == 0x0B) {//2048 line
            hcounter <<= 1;
        }
        if (labs(hcounter - ulHFreqCounter ) < 8192) {
            if ((GetTimerTick()-localtimer) > 30) {//minimum 30ms
                break;
            }
        }
    } while ((GetTimerTick()-localtimer) < 300);//maximum 300ms
}

/**************************************************************************//**
 * Set the ADC gain of red channel.
 * @param gain Gain value.
 ******************************************************************************/
void SetADCRGain(UCHAR gain)
{
    SC_RGAIN_HI = gain;
}

/**************************************************************************//**
 * Set the ADC gain of green channel.
 * @param gain Gain value.
 ******************************************************************************/
void SetADCGGain(UCHAR gain)
{
    SC_GGAIN_HI = gain;
}

/**************************************************************************//**
 * Set the ADC gain of blue channel.
 * @param gain Gain value.
 ******************************************************************************/
void SetADCBGain(UCHAR gain)
{
    SC_BGAIN_HI = gain;
}

/**************************************************************************//**
 * Set the ADC offset of red channel.
 * @param offset Offset value.
 ******************************************************************************/
void SetADCROffset(UCHAR offset)
{
    SC_ROFFSET = offset;
}

/**************************************************************************//**
 * Set the ADC offset of green channel.
 * @param offset Offset value.
 ******************************************************************************/
void SetADCGOffset(UCHAR offset)
{
    SC_GOFFSET = offset;
}

/**************************************************************************//**
 * Set the ADC offset of blue channel.
 * @param offset Offset value.
 ******************************************************************************/
void SetADCBOffset(UCHAR offset)
{
    SC_BOFFSET = offset;
}

/**************************************************************************//**
 * Get the ADC gain of red channel.
 * @return Gain value.
 ******************************************************************************/
UCHAR GetADCRGain(void)
{
    return SC_RGAIN_HI;
}

/**************************************************************************//**
 * Get the ADC gain of green channel.
 * @return Gain value.
 ******************************************************************************/
UCHAR GetADCGGain(void)
{
    return SC_GGAIN_HI;
}

/**************************************************************************//**
 * Get the ADC gain of blue channel.
 * @return Gain value.
 ******************************************************************************/
UCHAR GetADCBGain(void)
{
    return SC_BGAIN_HI;
}

/**************************************************************************//**
 * Get the ADC offset of red channel.
 * @return Offset value.
 ******************************************************************************/
UCHAR GetADCROffset(void)
{
    return SC_ROFFSET;
}

/**************************************************************************//**
 * Get the ADC offset of green channel.
 * @return Offset value.
 ******************************************************************************/
UCHAR GetADCGOffset(void)
{
    return SC_GOFFSET;
}

/**************************************************************************//**
 * Get the ADC offset of blue channel.
 * @return Offset value.
 ******************************************************************************/
UCHAR GetADCBOffset(void)
{
    return SC_BOFFSET;
}

/**************************************************************************//**
 * Enable or disable ADC ground sampling.
 * @param enable TRUE to enable ADC ground sampling else FALSE.
 ******************************************************************************/
void EnableADCGndSampling(UCHAR enable)
{
    if (enable) {
        SC_ADC_CTRL &= ~BIT0;
    }
    else {
        SC_ADC_CTRL |= BIT0;
    }
}

/**************************************************************************//**
 * Turn on ADCPLL and ADC power.
 ******************************************************************************/
void VGA_PowerOn(void)
{
    SC_POWER_CTRL2 = 0xEF;
    SC_ADC_POWER_UP |= 0x07;
}

/**************************************************************************//**
 * Turn off ADCPLL and ADC power.
 ******************************************************************************/
void VGA_PowerOff(void)
{
    SC_POWER_CTRL2 = 0x40;
    SC_ADC_POWER_UP &= ~0x07;
}

/**************************************************************************//**
 * Check the ADC power is on or not.
 * @return TRUE if ADC power is on else FALSE.
 ******************************************************************************/
/* 
BOOL IsADCPowerOn(void)
{
    return ((SC_ADC_POWER_UP & 0x07) != 0x00);
}
*/

//******************************************************************************
// Prototype: 
//  void SchmittTriggerPowerOn(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Hsync and Vsync schmitt Trigger circuit power up
// Notes:
//  None
//******************************************************************************
void SchmittTriggerPowerOn(void)
{
    SC_HS_TRIG_LEVEL = 0x37;
    SC_VS_TRIG_LEVEL = 0x37;
}

//******************************************************************************
// Prototype: 
//  void SchmittTriggerPowerOff(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Hsync and Vsync schmitt Trigger circuit power down
// Notes:
//  None
//******************************************************************************
/*
void SchmittTriggerPowerOff(void)
{
    SC_HS_TRIG_LEVEL = 0x88;
    SC_VS_TRIG_LEVEL = 0x88;
}
*/

