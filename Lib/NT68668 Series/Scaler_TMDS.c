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
extern xdata ULONG ulHFreqCounter;

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
 * Initialize TMDS-related registers.
 ******************************************************************************/
void TMDSInit(void)
{
    SC_DVI_CTRL_303 |= BIT0;
    //SC_DVI_RB_SWAP = 0x00;
#if IS_NT68669_SERIES
    SC_DVI_CTRL_330 = 0x12;
    SC_DVI_CTRL_339 = 0x12;
    SC_DVI_CTRL_335 = 0x40;
    SC_DVI_CTRL_331 = 0x00;
#elif IS_NT68650_SERIES
    SC_DVI_CTRL_330 = 0x15;
    SC_DVI_CTRL_339 = 0x15;
    SC_DVI_CTRL_335 = 0x20;
    SC_DVI_CTRL_331 = 0x00;
    SC_DVI_CTRL_337 = 0xC0;
#elif IS_NT68660_SERIES
    SC_DVI_CTRL_330 = 0x15;
    SC_DVI_CTRL_339 = 0x15;
    SC_DVI_CTRL_335 = 0x20;
#elif IS_NT68668_SERIES
    SC_DVI_CTRL_330 = 0x00;
    SC_DVI_CTRL_339 = 0x10;
    SC_DVI_CTRL_335 = 0x00;
#endif
    DVI_PowerOn();

#if IS_NT68668_SERIES || IS_NT68669_SERIES
    SC_HDCP_CTRL |= BIT1;
#endif
    SC_DVI_CTRL_338 = 0xFC;
    SC_TMDS_LINK_CLK_SEL = SCREG_1E7 | BIT0;
}

/**************************************************************************//**
 * Detect current input signal quality and set proper impedance.
 ******************************************************************************/
void TMDSImpedanceDetection(void)
{
#define GOOD_EYE_THRESHOLD 1 // 2 //every channel needs number of  '0x00' good eye.
#define BREAK_LOOP 0xEE

    code UCHAR ucClkIMPTable[] = {
        //0x330
        DEFAULT_CLKIMP1,
        DEFAULT_CLKIMP2,
        DEFAULT_CLKIMP3
    };
    code UCHAR ucDataIMPTable[][2] = {
        //0x339            0x33A
        {DEFAULT_DATAIMP1, 0xA0},
        {DEFAULT_DATAIMP1, 0x60},
        {DEFAULT_DATAIMP2, 0x60},
        {DEFAULT_DATAIMP3, 0x60}
    };
    code UCHAR ucEQBiasTable[][2] = {
        //0x332           0x337
        {DEFAULT_EQBIAS1, DEFAULT_EQRF1},
        {DEFAULT_EQBIAS2, DEFAULT_EQRF2},
        {DEFAULT_EQBIAS3, DEFAULT_EQRF3},
        {DEFAULT_EQBIAS4, DEFAULT_EQRF4},
        {DEFAULT_EQBIAS5, DEFAULT_EQRF5}
    };

    UCHAR i, j, k, l, ch, Reg0x306, Reg0x310, Reg0x311, Reg0x336;
    UCHAR *ptr;
    USHRT localtimer;
    EyeData tmp_eye;
    EyeData eye = {
        DEFAULT_CLKIMP1,
        DEFAULT_DATAIMP1,
        0xA0,
        DEFAULT_EQBIAS1,
        DEFAULT_EQRF1,
        0,
        0xffff,
        {0, 0, 0}
    };
    
    McuScalerIntDisable();//make sure sync processor interrupt disable.
#if IS_NT68669_SERIES
    SC_DVI_CTRL_335 = 0x40;
#elif IS_NT68660_SERIES || IS_NT68650_SERIES
    SC_DVI_CTRL_335 = 0x20;
#else
    SC_DVI_CTRL_335 = 0x00;
#endif
    Reg0x306 = SC_DVI_CTRL_306;
    Reg0x310 = SC_DVI_CTRL_310;
    Reg0x311 = SC_DVI_CTRL_311;
    Reg0x336 = SC_DVI_CTRL_336;
    SC_DVI_CTRL_336 &= ~BIT5; //disable CKDT to control channels impedance power down
    SC_DVI_CTRL_330 = DEFAULT_CLKIMP3; //for SCDT first
    SC_DVI_CTRL_339 = DEFAULT_DATAIMP3;
    SC_DVI_CTRL_33A = 0x60;
    Sleep(1);
    if (((SC_DVI_STATUS & BIT0) != 0) && ((SC_GI_SYNC_STATUS & 0xF8) == 0x18)) {
        SC_DVI_CTRL_311 = 0x22;//eye detection with Vs
        SC_DVI_CTRL_310 = 0x13;//detection start
        for (i = 0; i < sizeof(ucClkIMPTable); i++) {
            tmp_eye.ClkIMP = ucClkIMPTable[i];
            SC_DVI_CTRL_330 = tmp_eye.ClkIMP;//clock impedance       
            for (j = 0; j < sizeof(ucDataIMPTable) / 2; j++) {
                tmp_eye.DataIMP = ucDataIMPTable[j][0];
                tmp_eye.IMPMode = ucDataIMPTable[j][1];
                SC_DVI_CTRL_339 = tmp_eye.DataIMP;//data impedance
                SC_DVI_CTRL_33A = tmp_eye.IMPMode;
                for (k = 0; k < sizeof(ucEQBiasTable) / 2; k++) {
                    tmp_eye.EQBias = ucEQBiasTable[k][0];
                    tmp_eye.EQRF = ucEQBiasTable[k][1];
                    SC_DVI_CTRL_332 = tmp_eye.EQBias;//EQ bias
                    SC_DVI_CTRL_337 = tmp_eye.EQRF;//EQ resistor
                    tmp_eye.MaxGoodEye = 0;
                    tmp_eye.SumOfEye = 0xffff;
                    for (ch = 0; ch < 3; ch++) {
                        tmp_eye.RGBGoodEye[ch] = 0;
                        SC_DVI_CTRL_306 = ch;
                        SC_DVI_CTRL_309 |= BIT0;//clear error
                        SC_DVI_CTRL_310 = 0x13;//detection start
                        localtimer = GetTimerTick();
                        do {
                            Sleep(1);//detection period for 0x308 data error statistics 
                        } while (((SC_DVI_CTRL_310 & BIT3) != BIT3) && ((GetTimerTick() - localtimer) < 30));
                        if ((SC_DVI_STATUS & BIT0) == 0) {
                            //force change to next clock impedance
                            tmp_eye.SumOfEye = 0xffff;
                            tmp_eye.RGBGoodEye[ch] = 0;
                            tmp_eye.MaxGoodEye = 0;
                        #if IS_NT68668_SERIES
                            k = ch = BREAK_LOOP;
                        #else
                            j = k = ch = BREAK_LOOP;
                        #endif
                        }
                        else if ((SC_DVI_CTRL_308 & 0x07) == 0x00) {
                            ptr = &SC_DVI_CTRL_317;
                            for (l = 0; l < 5; l++) { //search 0x317~0x31B equals to 0x00
                                tmp_eye.SumOfEye += *ptr;
                                if (*ptr++ == 0x00) {
                                    tmp_eye.RGBGoodEye[ch]++;
                                    tmp_eye.MaxGoodEye++;
                                }
                            }
                        }
                        else {
                            //data error force break
                            tmp_eye.SumOfEye = 0xffff;
                            tmp_eye.RGBGoodEye[ch] = 0;
                            tmp_eye.MaxGoodEye = 0;
                            ch = BREAK_LOOP;
                        }
                    }
                    if (((tmp_eye.MaxGoodEye > eye.MaxGoodEye)
                            && (tmp_eye.RGBGoodEye[0] > 0
                                    && tmp_eye.RGBGoodEye[1] > 0
                                    && tmp_eye.RGBGoodEye[2] > 0))
                            || ((tmp_eye.SumOfEye < eye.SumOfEye)
                                    && (eye.RGBGoodEye[0] == 0
                                            || eye.RGBGoodEye[1] == 0
                                            || eye.RGBGoodEye[2] == 0))) {
                        //Maximum good-eye is prior to minimum sum of eye
                        eye = tmp_eye;

                    }
                    if ((tmp_eye.RGBGoodEye[0] >= GOOD_EYE_THRESHOLD)
                            && (tmp_eye.RGBGoodEye[1] >= GOOD_EYE_THRESHOLD)
                            && (tmp_eye.RGBGoodEye[2] >= GOOD_EYE_THRESHOLD)) {
                        eye = tmp_eye;
                        i = j = k = BREAK_LOOP;//for force to break
                    }
                }
            }
        }
    }

    SC_DVI_CTRL_339 = eye.DataIMP;
    SC_DVI_CTRL_33A = eye.IMPMode;
    SC_DVI_CTRL_330 = eye.ClkIMP;
    SC_DVI_CTRL_332 = eye.EQBias;
    SC_DVI_CTRL_337 = eye.EQRF;
    Sleep(1);
    SC_DVI_CTRL_306 = Reg0x306;
    SC_DVI_CTRL_310 = Reg0x310;
    SC_DVI_CTRL_311 = Reg0x311;
    SC_DVI_CTRL_336 = Reg0x336;

#undef GOOD_EYE_THRESHOLD
#undef BREAK_LOOP
}

/**************************************************************************//**
 * Detect the TMDS clock is stable or not.
 * @return TRUE if clock is stable else FALSE.
 ******************************************************************************/
BOOL TMDSClockStable(void)
{
    USHRT pre_clock, stable_timer, unstable_timer;

    pre_clock = TMDS_GetClock();
    stable_timer = GetTimerTick();
    unstable_timer = stable_timer;

    //Wait the TMDS clock to be stable for 150 ms or unstable for 300 ms
    while ((GetTimerTick()-unstable_timer) < 300) {
        if (abs(pre_clock - TMDS_GetClock()) > 2) {
            pre_clock = TMDS_GetClock();
            stable_timer = GetTimerTick();
        }
        if ((GetTimerTick() - stable_timer) > 150) {
            return TRUE;
        }
        ResetWDTimer();
    }

    return FALSE;
}

/**************************************************************************//**
 * According to the TMDS clock, we set some specific registers to get more signal qualities.
 * We reset TMDS phase detection only when clock is stable.
 * @param reset TRUE to reset TMDS phase detection else FALSE.
 ******************************************************************************/
void TMDSBandwidthDetection(UCHAR reset)
{
#define PIXEL_RATE_LOW    79
#define PIXEL_RATE_MID    81


#if IS_NT68669_SERIES
    if (TMDS_GetClock() < PIXEL_RATE_LOW) {
        SC_DVI_CTRL_335 = 0x20;
    }
    else if (TMDS_GetClock() > PIXEL_RATE_MID) {
        SC_DVI_CTRL_335 = 0x40;
    }
#elif IS_NT68660_SERIES || IS_NT68650_SERIES
    if (TMDS_GetClock() < PIXEL_RATE_LOW) {
        SC_DVI_CTRL_335 = 0x10;
    }
    else if (TMDS_GetClock() > PIXEL_RATE_MID) {
        SC_DVI_CTRL_335 = 0x20;
    }
#endif

    if (reset) {
        //Toogle 0x303 for digital input
        SC_DVI_CTRL_303 &= ~BIT0;
        SC_DVI_CTRL_303 |= BIT0;
    }

    
#undef PIXEL_RATE_LOW 
#undef PIXEL_RATE_MID
}

/**************************************************************************//**
 * Get digital input HDE pixel count.
 * Before system invoke this function, the input VSync frequency must be determined.
 * This value is determined by the capture block not TMDS block.
 * @return Digital input HDE.
 ******************************************************************************/
USHRT GetDigInputHActive(void)
{
#if 0
    return ReadShortScaler(&SC_DVI_CAP_HWID_LO);
#else
    UCHAR i;
    USHRT hactive, htemp;

    htemp = 0;
    for (i=0; i<5; i++) {
        hactive = ReadShortScaler(&SC_DVI_CAP_HWID_LO);
        if (htemp != hactive) {
            htemp = hactive;
            DelayVTime(1);
        }
        else {
            break;
        }
    }

    return hactive;
#endif
}

/**************************************************************************//**
 * Get digital input VDE line count.
 * Before system invoke this function, the input VSync frequency must be determined.
 * This value is determined by the capture block not TMDS block.
 * @return Digital input VDE.
 ******************************************************************************/
USHRT GetDigInputVActive(void)
{
#if 0
    if (IsInterlaced()) {
        return ReadShortScaler(&SC_DVI_CAP_VLEN_LO) * 2;
    }
    else {
        return ReadShortScaler(&SC_DVI_CAP_VLEN_LO);
    }
#else
    UCHAR i;
    USHRT vactive, vtemp;

    vtemp = 0;
    for (i=0; i<5; i++) {
        vactive = ReadShortScaler(&SC_DVI_CAP_VLEN_LO);
        if (vtemp != vactive) {
            vtemp = vactive;
            DelayVTime(4);
        }
        else {
            break;
        }
    }

        return vactive;
#endif
}

/**************************************************************************//**
 * Get digital input HDE without any delay.
 * This value is determined by the capture block not TMDS block.
 * @return Digital input HDE.
 ******************************************************************************/
USHRT GetDigInputHActiveImmediate(void)
{
    return ReadShortScalerHighLowFilter(&SC_DVI_CAP_HWID_LO);
}

/**************************************************************************//**
 * Get digital input VDE without any delay.
 * This value is determined by the capture block not TMDS block.
 * @return Digital input VDE.
 ******************************************************************************/
USHRT GetDigInputVActiveImmediate(void)
{
    return ReadShortScalerHighLowFilter(&SC_DVI_CAP_VLEN_LO);
}

/**************************************************************************//**
 * Get the count of HSync frequency (from sync processor) of digital timing.
 ******************************************************************************/
void SetDVIPLL(void)
{
    USHRT pixel_rate;

    SC_HPLL_FREQ_CTRL = 0x00;

    SC_HPLL_LINE_CNT = 0x0C; //4096 line

    pixel_rate = ReadShortScaler(&SC_GI_HCNT_LO) & 0x1FFF;
    if ((pixel_rate==0x1FFF) || (pixel_rate==0)) {
        ulHFreqCounter = 0xFFFFFFFF;
    }
    else {
        ulHFreqCounter = (ULONG)pixel_rate * 8192;
    }
}

/**************************************************************************//**
 * Turn off TMDS power.
 ******************************************************************************/
void DVI_PowerOff(void)
{
#if IS_NT68660_SERIES || IS_NT68650_SERIES
    SC_DVI_CTRL_333 = 0x80;
#else
    SC_DVI_CTRL_333 = 0x87;
#endif
    SC_DVI_CTRL_334 = 0x01;
    SC_DVI_CTRL_336 = 0x00;
    SC_POWER_CTRL2 &= ~BIT1;
}

/**************************************************************************//**
 * Turn on TMDS power.
 ******************************************************************************/
void DVI_PowerOn(void)
{
    SC_POWER_CTRL2 |= BIT1;
#if IS_NT68660_SERIES || IS_NT68650_SERIES
    SC_DVI_CTRL_333 = 0x07;
#else
    SC_DVI_CTRL_333 = 0x00;
#endif
    SC_DVI_CTRL_334 = 0x00;
#if IS_NT68669_SERIES
    SC_DVI_CTRL_336 = 0xD0;
#elif IS_NT68660_SERIES || IS_NT68650_SERIES
    SC_DVI_CTRL_336 = 0xC0;
#else
    SC_DVI_CTRL_336 = 0xC0;
#endif
}

/**************************************************************************//**
 * Turn on the termination power of TMDS clock pair for TMDS clock detection.
 ******************************************************************************/
void TMDS_EnableSCDT(void)
{
    SC_DVI_CTRL_336 = 0xC0;
}

/**************************************************************************//**
 * Get current TMDS clock.
 * @return TMDS clock frequency.
 ******************************************************************************/
USHRT TMDS_GetClock(void)
{
#define OSC_FREQ_RATIO ((float)REF_CLK/12000000)

    if ((SC_DVI_STATUS & BIT0) != 0) {
        return (USHRT)(ReadShortScaler(&SC_DVI_PIXELCLK_LO)*OSC_FREQ_RATIO);
    }

    return 0;

#undef OSC_FREQ_RATIO    
}
