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
    SC_ADC_IP_CTRL_1D80[_ADC_BW_SEL_BP] = 0x00;//Analog bandwidth select ( B+ input capacitor select ) 
    SC_ADC_IP_CTRL_1D80[_ADC_BW_SEL_BN] = 0x00;//Analog bandwidth select ( B- input capacitor select )
    SC_ADC_IP_CTRL_1D80[_ADC_BW_SEL_GP] = 0x00;//Analog bandwidth select ( G+ input capacitor select )
    SC_ADC_IP_CTRL_1D80[_ADC_BW_SEL_GN] = 0x00;//Analog bandwidth select ( G- input capacitor select )
    SC_ADC_IP_CTRL_1D80[_ADC_BW_SEL_RP] = 0x00;//Analog bandwidth select ( R+ input capacitor select )
    SC_ADC_IP_CTRL_1D80[_ADC_BW_SEL_RN] = 0x00;//Analog bandwidth select ( R- input capacitor select )
    SC_ADC_IP_CTRL_1D80[_ADC_P_CLAMP_EN] = 0xE0; // 0x1d8f
#if 1 //NT68810
#if IS_NT68810_SERIES
    SC_ADC_IP_CTRL_1D80[_ADC_VICM_BIAS] = 0xC0;//0x80;//ADC_VICM_BIAS  0x1d90
    SC_ADC_IP_CTRL_1D80[_ADC_VREF_BIAS] = 0x40;//0x80;//ADC_VREF_BIAS 0x1d92
    SC_ADC_IP_CTRL_1D80[_ADC_BIAS_CTRL2] = 0x6C;//0x88;//ADC_BIAS 0x1d95
#else //NT68870
    SC_ADC_IP_CTRL_1D80[_ADC_VICM_BIAS] = 0x70;//0x80;//ADC_VICM_BIAS
    SC_ADC_IP_CTRL_1D80[_ADC_VREF_BIAS] = 0x00;//0x80;//ADC_VREF_BIAS
    SC_ADC_IP_CTRL_1D80[_ADC_BIAS_CTRL2] = 0x64;//0x88;//ADC_BIAS
#endif
    SC_ADC_IP_CTRL_1D80[_ADC_CLAMP_SPEED] = 0x10;//CLAMP_SPEED 0x1d93
    SC_ADC_IP_CTRL_1D80[_ADC_BIAS_CTRL1] = 0x55;//0x53;//0x46;//0x88;//ADC_BIAS 0x1d94
    SC_ADC_IP_CTRL_1D80[_ADC_CDS] = 0x40;//0x30; 0x1d98
    SC_ADC_IP_CTRL_1D80[_ADC_COMP_BIAS] = 0x60;//0x88;//0x40;//0x80;//ADC_COMP_BIAS 0x1d99
#if IS_NT68810_SERIES
    SC_ADC_IP_CTRL_1D80[_ADC_SGND_BIAS] = 0x40;//0x80;//ADC_SGND_BIAS 0x1d9a
#else
    SC_ADC_IP_CTRL_1D80[_ADC_SGND_BIAS] = 0x20;//0x80;//ADC_SGND_BIAS 0x1d9a
    SC_ADC_IP_CTRL_1D80[_ADC_SRC_FOLLOWER_CURRENT] = 0x40;// 0x1d9e
#endif
    SC_ADC_IP_CTRL_1D80[_ADC_COMMON_MODE_SEL] = 0x20;    // 0x1da3
    SC_ADC_IP_CTRL_1D80[_ADC_SOG_DISCUR] = 0xC0;//SOG_DISCUR // 0x1db0
    SC_ADC_IP_CTRL_1D80[_ADC_SOG_THRESHOLD] = 0xE0;//0xC0;//0xE0;//SOGTH   // 0x1db1
    SC_ADC_IP_CTRL_1D80[_ADC_SOG_CLAMP_CURRENT] = 0x02;//0xA0;//SOG_CLP_SW // 0x1db2
#else //TC68810
    SC_ADC_IP_CTRL_1D80[_ADC_VICM_BIAS] = 0x80;//0xC0;//0x80;//ADC_VICM_BIAS
    SC_ADC_IP_CTRL_1D80[_ADC_VMID_CTRL] = 0x00;
    SC_ADC_IP_CTRL_1D80[_ADC_VREF_BIAS] = 0x80;//ADC_VREF_BIAS
    SC_ADC_IP_CTRL_1D80[_ADC_CLAMP_SPEED] = 0xF0;//CLAMP_SPEED
    SC_ADC_IP_CTRL_1D80[_ADC_BIAS_CTRL1] = 0xE0;//ADC_BIAS
    SC_ADC_IP_CTRL_1D80[_ADC_BIAS_CTRL2] = 0x88 | BIT0;//ADC_BIAS
    SC_ADC_IP_CTRL_1D80[_ADC_SF_BIAS] = 0x80;
    SC_ADC_IP_CTRL_1D80[_ADC_COMP_BIAS] = 0x80;//ADC_COMP_BIAS
    SC_ADC_IP_CTRL_1D80[_ADC_SGND_BIAS] = 0x40;//0x20;//ADC_SGND_BIAS
    SC_ADC_IP_CTRL_1D80[_ADC_GAIN_OFFSET_BIAS] = 0x40;//0xC0;
    SC_ADC_IP_CTRL_1D80[_ADC_SRC_FOLLOWER_CURRENT] &= ~BIT7;//|= BIT7;
    SC_ADC_IP_CTRL_1D80[_ADC_SRC_FOLLOWER_CURRENT] |= BIT6;//&= ~BIT6;	
    SC_ADC_IP_CTRL_1D80[_ADC_BANDGAP_SET] |= BIT7;
    SC_ADC_IP_CTRL_1D80[_ADC_SOG_DISCUR] = 0xC0;//SOG_DISCUR
    SC_ADC_IP_CTRL_1D80[_ADC_SOG_THRESHOLD] = 0x10;//0x80;//SOGTH
    SC_ADC_IP_CTRL_1D80[_ADC_SOG_CLAMP_CURRENT] = 0x02;//0xA0;//SOG_CLP_SW
#endif
    SC_ADC_CTRL_OPTION1 = 0x30;// 0xb78
    SC_ADC_CTRL_OPTION2 = 0x04;
    SC_ADC_CTRL_OPTION3 = 0x90;

    VGA_PowerOn();

    SC_CLAMP_BEGIN = 0x81;//0x0C;// 0x021
    SC_CLAMP_WIDTH = 0x81;//  0x22

    WriteShortScaler(&SC_HSDDS_DIVIDER_LO, 0x800);//default value (ADC work)
    SC_HPLL_CTRL1 = SCREG_0D0;  // 0xd0
    SC_HPLL_CTRL2 = 0xC0; // 0xd6
    SC_HPLL_CTRL3 = 0x00; // 0xdc
    SC_HPLL_FREQ_CTRL = SCREG_0D1;// 0xd1
    SC_HPLL_PHASE_CTRL = 0x18;  /// 0xd5

    SchmittTriggerPowerOn();
    SetADCInput(ADC_INPUT_EXT_RGB);
}

/**************************************************************************//**
 * Get the input htotal of analog input.
 * @return Input htotal of analog input.
 ******************************************************************************/
USHRT GetAngInputHTotal(void)
{
#if defined(ENABLE_FPGA_MODE)
    return AD9884_GetHTotal();
#else
    return ReadShortScaler(&SC_HSDDS_DIVIDER_LO);
#endif
}

/**************************************************************************//**
 * Get the ADCPLL phase setting.
 * @return ADCPLL phase setting.
 ******************************************************************************/
UCHAR GetAngInputPhase(void)
{
#if defined(ENABLE_FPGA_MODE)
    return AD9884_GetPhase();
#else
    return SC_HPLL_PHASE_CTRL1;
#endif
}

/**************************************************************************//**
 * Set ADC bandwidth.
 * @param bw ADC bandwidth. If bw is ADC_BW_AUTO, the bandwidth is auto-configured.
 ******************************************************************************/
void SetADCBandWidth(ADCBandW bw)
{
    ULONG pix_clk;
    UCHAR i;

    if (bw == ADC_BW_AUTO) {
        /*
        Analog bandwidth select ( RGB input capacitor select )
        111 :  MHz
        110 :  MHz
        101 :  MHz
        100 :  MHz
        011 :  MHz
        010 :  MHz
        001 :  MHz
        000 :  MHz
        */
#if defined(ENABLE_FPGA_MODE)
        pix_clk = AD9884_GetHTotal();
#else
        pix_clk = ReadShortScaler(&SC_HSDDS_DIVIDER_LO);// 0xd7
#endif
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
    i = bw << 4;
    SC_ADC_IP_CTRL_1D80[_ADC_BW_SEL_BP] = i;//Analog bandwidth select ( B+ input capacitor select )  // 0x1d89
    SC_ADC_IP_CTRL_1D80[_ADC_BW_SEL_GP] = i;//Analog bandwidth select ( G+ input capacitor select )// 0x1d8b
    SC_ADC_IP_CTRL_1D80[_ADC_BW_SEL_RP] = i;//Analog bandwidth select ( R+ input capacitor select )// 0x1d8d
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
    SC_HPLL_FREQ_CTRL &= ~BIT6; //Enable updating HS_CNT// 0xd1
    pixel_rate = ReadShortScaler(&SC_GI_HCNT_LO) & 0x1FFF;
    if ((pixel_rate == 0x1FFF) || (pixel_rate == 0)) {
        ulHFreqCounter = 0xFFFFFFFF;
    }
    else {
        ulHFreqCounter = (ULONG)pixel_rate * 8192;
    }
    WriteShortScaler(&SC_HSDDS_DIVIDER_LO, htotal);
#if defined(ENABLE_FPGA_MODE)
    AD9884_SetHTotal(htotal);
#endif

    pixel_rate = htotal;
    pixel_rate = pixel_rate * usHSyncFreq;

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

#if defined(ENABLE_FPGA_MODE)
    AD9884_SetPhase(phase);
#endif    
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
#if defined(ENABLE_FPGA_MODE)
    AD9884_SetGain(0, gain);
#else
    SC_ADC_IP_CTRL_1D80[_ADC_GAIN_R] = gain;
#endif
}

/**************************************************************************//**
 * Set the ADC gain of green channel.
 * @param gain Gain value.
 ******************************************************************************/
void SetADCGGain(UCHAR gain)
{
#if defined(ENABLE_FPGA_MODE)
    AD9884_SetGain(1, gain);
#else
    SC_ADC_IP_CTRL_1D80[_ADC_GAIN_G] = gain;
#endif
}

/**************************************************************************//**
 * Set the ADC gain of blue channel.
 * @param gain Gain value.
 ******************************************************************************/
void SetADCBGain(UCHAR gain)
{
#if defined(ENABLE_FPGA_MODE)
    AD9884_SetGain(2, gain);
#else
    SC_ADC_IP_CTRL_1D80[_ADC_GAIN_B] = gain;
#endif
}

/**************************************************************************//**
 * Set the ADC offset of red channel.
 * @param offset Offset value.
 ******************************************************************************/
void SetADCROffset(UCHAR offset)
{
#if defined(ENABLE_FPGA_MODE)
    AD9884_SetOffset(0, offset);
#else
    SC_ADC_IP_CTRL_1D80[_ADC_OFFSET_R] = offset;
#endif
}

/**************************************************************************//**
 * Set the ADC offset of green channel.
 * @param offset Offset value.
 ******************************************************************************/
void SetADCGOffset(UCHAR offset)
{
#if defined(ENABLE_FPGA_MODE)
    AD9884_SetOffset(1, offset);
#else
    SC_ADC_IP_CTRL_1D80[_ADC_OFFSET_G] = offset;
#endif
}

/**************************************************************************//**
 * Set the ADC offset of blue channel.
 * @param offset Offset value.
 ******************************************************************************/
void SetADCBOffset(UCHAR offset)
{
#if defined(ENABLE_FPGA_MODE)
    AD9884_SetOffset(2, offset);
#else
    SC_ADC_IP_CTRL_1D80[_ADC_OFFSET_B] = offset;
#endif
}

/**************************************************************************//**
 * Get the ADC gain of red channel.
 * @return Gain value.
 ******************************************************************************/
UCHAR GetADCRGain(void)
{
#if defined(ENABLE_FPGA_MODE)
    return AD9884_GetGain(0);
#else
    return SC_ADC_IP_CTRL_1D80[_ADC_GAIN_R];
#endif
}

/**************************************************************************//**
 * Get the ADC gain of green channel.
 * @return Gain value.
 ******************************************************************************/
UCHAR GetADCGGain(void)
{
#if defined(ENABLE_FPGA_MODE)
    return AD9884_GetGain(1);
#else
    return SC_ADC_IP_CTRL_1D80[_ADC_GAIN_G];
#endif
}

/**************************************************************************//**
 * Get the ADC gain of blue channel.
 * @return Gain value.
 ******************************************************************************/
UCHAR GetADCBGain(void)
{
#if defined(ENABLE_FPGA_MODE)
    return AD9884_GetGain(2);
#else
    return SC_ADC_IP_CTRL_1D80[_ADC_GAIN_B];
#endif
}

/**************************************************************************//**
 * Get the ADC offset of red channel.
 * @return Offset value.
 ******************************************************************************/
UCHAR GetADCROffset(void)
{
#if defined(ENABLE_FPGA_MODE)
    return AD9884_GetOffset(0);
#else
    return SC_ADC_IP_CTRL_1D80[_ADC_OFFSET_R];
#endif
}

/**************************************************************************//**
 * Get the ADC offset of green channel.
 * @return Offset value.
 ******************************************************************************/
UCHAR GetADCGOffset(void)
{
#if defined(ENABLE_FPGA_MODE)
    return AD9884_GetOffset(1);
#else
    return SC_ADC_IP_CTRL_1D80[_ADC_OFFSET_G];
#endif
}

/**************************************************************************//**
 * Get the ADC offset of blue channel.
 * @return Offset value.
 ******************************************************************************/
UCHAR GetADCBOffset(void)
{
#if defined(ENABLE_FPGA_MODE)
    return AD9884_GetOffset(2);
#else
    return SC_ADC_IP_CTRL_1D80[_ADC_OFFSET_B];
#endif
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
    SC_POWER_CTRL2 |= (BIT6 | BIT3);
    SC_ADC_IP_CTRL_1D80[_ADC_POWER_CTRL] = 0xF0;// 0x1db5
}

/**************************************************************************//**
 * Turn off ADCPLL and ADC power.
 ******************************************************************************/
void VGA_PowerOff(void)
{
    SC_POWER_CTRL2 &= ~(BIT6 | BIT3);
    SC_ADC_IP_CTRL_1D80[_ADC_POWER_CTRL] = 0x00;// 0x1db5
    SC_ADC_IP_CTRL_1D80[_ADC_MISC_CTRL_33] = 0x00;// 0x1db3
}

/**************************************************************************//**
 * Check the ADC power is on or not.
 * @return TRUE if ADC power is on else FALSE.
 ******************************************************************************/
/* 
BOOL IsADCPowerOn(void)
{
    return ((SC_ADC_IP_CTRL_1D80[_ADC_POWER_CTRL] & 0xE0) != 0x00);
}
*/

/**************************************************************************//**
 * Turn on HSync and VSync schmitt Trigger circuits.
 ******************************************************************************/
void SchmittTriggerPowerOn(void)
{
    SC_HS_TRIG_LEVEL = 0x37;
    SC_VS_TRIG_LEVEL = 0x37;
}

/**************************************************************************//**
 * Turn off HSync and VSync schmitt Trigger circuits.
 ******************************************************************************/
void SchmittTriggerPowerOff(void)
{
    SC_HS_TRIG_LEVEL = 0x88;
    SC_VS_TRIG_LEVEL = 0x88;
}

/**************************************************************************//**
 * Set ADC input source.
 * The input can be one of
 *     ADC_INPUT_INT_GND,
 *     ADC_INPUT_RST_RGB,
 *     ADC_INPUT_INT_WHITE and
 *     ADC_INPUT_EXT_RGB
 * @param input ADC input source.
 ******************************************************************************/
void SetADCInput(ADCInput input)
{
    if (input >= ADC_NUM_INPUT) {
        input = ADC_INPUT_EXT_RGB;
    }

    if (input == ADC_INPUT_INT_WHITE) {
        //SC_ADC_IP_CTRL_1D80[_ADC_TRIM_VALUE] = 0x80;
        SC_ADC_IP_CTRL_1D80[_ADC_MISC_CTRL_1B] &= ~(BIT7|BIT6|BIT5);// 0x1d93
        SC_ADC_LDO &= ~BIT3;  // 0xb63
        SC_ADC_IP_CTRL_1D80[_ADC_TRIMMING_SEL] |= BIT7;//0xC0;  0x1da0
//for hw auto gain
    #if IS_NT68810_SERIES || IS_NT68870_SERIES
        SC_ADC_IP_CTRL_1D80[_ADC_P_CLAMP_EN] = 0x00;//clamp off  0x1d8f
    #if IS_NT68870_SERIES
        SC_ADC_IP_CTRL_1D80[_ADC_VMID_CTRL] |= BIT7;  // 0x1d91
    #endif
    #endif
    }
    else if (input == ADC_INPUT_INT_GND) {
        //SC_ADC_IP_CTRL_1D80[_ADC_TRIM_VALUE] = 0x80;
        SC_ADC_IP_CTRL_1D80[_ADC_MISC_CTRL_1B] &= ~(BIT7|BIT6|BIT5);
        SC_ADC_IP_CTRL_1D80[_ADC_TRIMMING_SEL] &= ~BIT7;//0x40;
        SC_ADC_LDO |= BIT3;
//for hw auto offset
    #if IS_NT68810_SERIES || IS_NT68870_SERIES
        SC_ADC_IP_CTRL_1D80[_ADC_P_CLAMP_EN] = 0x00;//clamp off
    #if IS_NT68870_SERIES
        SC_ADC_IP_CTRL_1D80[_ADC_VMID_CTRL] |= BIT7;
    #endif
    #endif
    }
    else {//ADC_INPUT_EXT_RGB
        //SC_ADC_IP_CTRL_1D80[_ADC_TRIM_VALUE] = 0xFF;
        SC_ADC_IP_CTRL_1D80[_ADC_TRIMMING_SEL] &= ~BIT7;//0x40;
        SC_ADC_LDO &= ~BIT3;
        SC_ADC_IP_CTRL_1D80[_ADC_MISC_CTRL_1B] |= (BIT7|BIT6|BIT5);
//for normal
    #if IS_NT68810_SERIES || IS_NT68870_SERIES
        SC_ADC_IP_CTRL_1D80[_ADC_P_CLAMP_EN] = 0xE0;//clamp on
    #if IS_NT68870_SERIES
        SC_ADC_IP_CTRL_1D80[_ADC_VMID_CTRL] &= ~BIT7;
    #endif
    #endif
    }
}
