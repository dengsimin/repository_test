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
BOOL bLowPowerMode = FALSE; /*!< The status of low power mode. */

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************
static BOOL bForceToSleep = FALSE; /*!< Flag of force power saving. */

//******************************************************************************
// E X T E R N A L   V A R I A B L E   P R O T O T Y P E S
//******************************************************************************
#if ENABLE_LOW_PWR_MODE == ON
extern idata USHRT usMCUCLKDIVIDERLoop;
#endif

//******************************************************************************
// S T A T I C   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// F U N C T I O N   B O D Y S
//******************************************************************************

#if ENABLE_HDMI_PRETEST == OFF
/**************************************************************************//**
 * Turn the scaler to power saving state.
 ******************************************************************************/
void ScalerPowerSaving(void)
{
    DisplayPostPattern(POSTPTN_WHITE);//discharge panel power
    DisableScalerPWM(PWM_ALL); //Turn off PWMA/PWMB
#if ENABLE_SCALER_AUDIO == ON
    ScalerAudioPowerOff(); //Samuel-2009-04-09: Turn off PWMA/B first and then turn off audio analog power
#endif
    DisableDPLL();
    DVI_PowerOff();
    VGA_PowerOff();
#if (INPUT_INTERFACE&INPUT_DP)
    DP_PowerOFF();
#endif
    DisplayMuteImage();
#if ENABLE_MMU == ON
    MMUPowerOff();
#endif
    TurnOffScalerMainPower();
#if ENABLE_LOW_PWR_MODE == ON
    McuPowerDownAPLL();
    if (bForceToSleep == FALSE) {
        SetLowPowerMode(FALSE);
    }
#if (INPUT_INTERFACE&INPUT_DP)
    DPConfigAUXDetect();
#endif
#endif
}
#endif

/**************************************************************************//**
 * Set force to sleep flag.
 ******************************************************************************/
void SetForceToSleep(void)
{
    bForceToSleep = TRUE;
}

/**************************************************************************//**
 * Clear force to sleep flag.
 ******************************************************************************/
void ClearForceToSleep(void)
{
    bForceToSleep = FALSE;
}

/**************************************************************************//**
 * Get the status of force to sleep flag.
 * @return Status of force to sleep.
 ******************************************************************************/
BOOL IsForceToSleep(void)
{
    return bForceToSleep;
}

/**************************************************************************//**
 * Turn off scaler power.
 ******************************************************************************/
void ScalerPowerDown(void)
{
#if ENABLE_SCALER_LEDDRV_IO_MODE
    LEDDRVIOPwrSav();
#endif
    DisplayPostPattern(POSTPTN_WHITE);//discharge panel power
    DisableScalerPWM(PWM_ALL); //Turn off PWMA/PWMB
#if ENABLE_SCALER_AUDIO == ON
    ScalerAudioPowerOff(); //Samuel-2009-04-09: Turn off PWMA/B first and then turn off audio analog power
#endif
    DisableDPLL();
    DVI_PowerOff();
    VGA_PowerOff();
#if (INPUT_INTERFACE&INPUT_DP)
    DP_PowerOFF();
#endif
    DisplayMuteImage();
#if ENABLE_MMU == ON
    MMUPowerOff();
#endif
    TurnOffScalerMainPower();
#if ENABLE_LOW_PWR_MODE == ON
    McuPowerDownAPLL();
    SetLowPowerMode(TRUE);
#if (INPUT_INTERFACE&INPUT_DP)
    DPConfigAUXDetect();
#endif
#endif
#if ENABLE_CUT_POWER_ARCH == ON
#if MD_ENABLE_AO_DETECT == ON
//save memory befor +5V power off.
    NvramWriteUserData(&UserData);
#if ((ENABLE_FE2P == ON) && (ENABLE_AUTO_CONTROL == OFF))
    FE2P_SaveToFlash();
#endif
//    SX8670PowerDown();
    PowerMOSOff();

    do {
        ResetWDTimer();
        AO_DETECT |= BIT2;
        Sleep(AO_KEY_DEBOUNCE_TIME); //wait HW debounce
    } while ((AO_DETECT & BIT2) != 0);

    AO_DETECT |= BIT1;//need add stby key.
    Sleep(1);
    AO_DETECT &= ~BIT1;//need add stby key.
#else
    PowerMOSOff();
#endif
#endif
}

/**************************************************************************//**
 * Turn on scaler power.
 ******************************************************************************/
void ScalerPowerUp(void)
{
    ClearForceToSleep();
#if 1//ENABLE_AUTO_CONTROL == OFF
    if ((SC_POWER_CTRL1 & BIT3) != 0) {
    #if ENABLE_CUT_POWER_ARCH == ON
        PowerMOSOn();
        McuPowerUpAPLL();
        ScalerInitialize();
        APPInitSystem();
    #else
        McuPowerUpAPLL();
        SetNormalPowerMode();
        TurnOnScalerMainPower();
    #if ENABLE_SCALER_AUDIO == ON
        ScalerAudioPowerOn();
    #endif
    #endif
    #if ENABLE_MMU == ON
        MMUPowerOn();
    #endif
        EnableScalerPWM(PWM_ALL);//Turn on PWMA/PWMB
        EnableDPLL();
        DVI_PowerOn();
        VGA_PowerOn();
    }
#endif
    SetModeChangeFlag();
}

/**************************************************************************//**
 * Turn the scaler to the normal power state.
 ******************************************************************************/
void SetNormalPowerMode(void)
{
#if IS_NT68790_SERIES || IS_NT68658_SERIES
#if MD_ENABLE_DC2DC == ON
    SC_ADC_ZERO_POWER_CTRL = 0x81;
    SC_DVI2_ZERO_POWER_CTRL |= BIT3;
    SC_DC2DC_E39 = 0x06;//en=0x06, disenable=0x00. RA==>disable
    #if IS_NT68658_SERIES
        SC_DC2DC_E3A = 0x00;
    #else
        SC_DC2DC_E3A = 0x01;
    #endif
    SC_APR_ISOLATION = 0x00;
#else
    SC_ADC_ZERO_POWER_CTRL = 0x81;
    SC_DVI2_ZERO_POWER_CTRL = 0x00;
    SC_APR_ISOLATION = 0x03;
    SC_DC2DC_E39 = 0x00;
    SC_DC2DC_E3A = 0x00;
#endif
    SC_DC2DC_E30 = 0x00;
//    SC_DC2DC_E39 = 0x00;
    SC_DC2DC_E3B = 0x00;
    SC_DC2DC_E3C = 0x00;
    SC_DC2DC_E3D = 0x00;
    SC_DC2DC_E3E = 0x00;
    SC_DC2DC_E3F = 0x00;
    Sleep(10);
#endif
    LDO_ADJ |= (BIT7 | BIT4);
    LDO_ADJ &= ~BIT0;

#if ENABLE_CUT_POWER_ARCH == ON
if ((SC_POWER_CTRL1&0x0F) != 0x0D) { // APR2 Reset in int.c
    SC_POWER_CTRL1 |= BIT7;
    SC_CUT_POWER_CTRL |= BIT2;
    SC_CUT_POWER_CTRL |= BIT0;
    SC_ISOLATION_CONTROL = SCREB_B61_PU;
    SC_CUT_POWER_CTRL &= 0x07;
    SC_CUT_POWER_CTRL &= ~BIT1;
    SC_POWER_CTRL1 &= ~BIT7;
}
#endif
#if IS_NT68790_SERIES || IS_NT68658_SERIES
#if MD_ENABLE_DC2DC == ON
    SC_ADC_ZERO_POWER_CTRL = 0x81;
    SC_DVI2_ZERO_POWER_CTRL |= BIT3;
    SC_DC2DC_E39 = 0x06;//en=0x06, disenable=0x00. RA==>disable
    #if IS_NT68658_SERIES
        SC_DC2DC_E3A = 0x00;
    #else
        SC_DC2DC_E3A = 0x01;
    #endif
    SC_APR_ISOLATION = 0x00;
#else
    SC_ADC_ZERO_POWER_CTRL = 0x81;
    SC_DVI2_ZERO_POWER_CTRL = 0x00;
    SC_APR_ISOLATION = 0x03;
    SC_DC2DC_E39 = 0x00;
    SC_DC2DC_E3A = 0x00;
#endif
    SC_DC2DC_E30 = 0x00;
//    SC_DC2DC_E39 = 0x00;
    SC_DC2DC_E3B = 0x00;
    SC_DC2DC_E3C = 0x00;
    SC_DC2DC_E3D = 0x00;
    SC_DC2DC_E3E = 0x00;
    SC_DC2DC_E3F = 0x00;
    Sleep(10);
#endif

#if (ENABLE_INTERNAL_LDO == ON) || (ENABLE_INTERNAL_ADC_LDO == ON)
    SC_ADC_ZERO_POWER_CTRL = SCREG_057_INT_LDO;
#else
    SC_ADC_ZERO_POWER_CTRL = SCREG_057_EXT_LDO;
#endif

    SC_MCU_CLK_DIVIDER = 0x00;
    SC_ZERO_POWER_LDO18 = SCREG_055_PU;
    SC_OSC_LDO18 = SCREG_056_PU;

#if ENABLE_INTERNAL_LDO == ON
    SC_APR_LDO_CTRL = 0x00;
#if IS_NT68150_SERIES
    SC_APR_LDO_V_CTRL = 0x02;//需調0xB53=0x02  LDO輸出電壓=1.25V
#endif
#else
#if IS_NT68850_SERIES || IS_NT68790_SERIES || IS_NT68658_SERIES
    SC_APR_LDO_V_CTRL |= BIT0;//NT68850 沒有 LDO, 所以 b53 的 control register 後來都被拿去當 apr2 的 clock gen control 使用
#if SCALER_TYPE == NT68799   
    SC_APR_LDO_CTRL = 0xE0;
#endif
#else
    SC_APR_LDO_CTRL = 0x3F;
#endif
#endif
    
    SC_SOG_SLICER_CTRL = 0x00;
    SC_SOG_SLICER_EN = 0x80;

    SC_MPLL_DIV = SCREG_B40;
    SC_MPLL_CTRL_B41 = SCREG_B41;
    SC_MPLL_CTRL_B42 = SCREG_B42;
    SC_MPLL_LDO_VADJ = SCREG_B43;
    SC_MPLL_X2 = 0x03;
    
    SC_DVI_ZERO_POWER_CTRL = 0x00;
    SC_DVI1_ZERO_POWER_CTRL = 0x00;

    SC_ADC_REG_1D |= BIT6;
    SchmittTriggerPowerOn();
#if ENABLE_HW_CEC == ON
    CECUpdateRefClock();
#endif
    bLowPowerMode = FALSE;
}

/**************************************************************************//**
 * Turn the scaler to the zero power state.
 * @param pwroff TRUE to indicate "power off", FALSE is "power saving"
 ******************************************************************************/
void SetLowPowerMode(UCHAR pwroff)
{
    // Return immediately to avoid performing low power procedure twice or more
    if (bLowPowerMode && (pwroff == FALSE)) {
        return;
    }
//#if (INPUT_INTERFACE&INPUT_DP)
//    SC_DP_AUX_DETECT &= ~(BIT2|BIT3);
//    SC_DP_AUX_DETECT |= (BIT2|BIT0); //dp_det_start & dp_aux_det_en
//#endif
#if (INPUT_INTERFACE&INPUT_MHL0) || (INPUT_INTERFACE&INPUT_MHL1)
    if (GetCbusConnectStatus() == MHL_DATA_RDY) {
        MHLClearHPD();
    }
    if ( pwroff ) {
        //TPV requests VBus keeping on while DC off??
    }
    else if ( (IsMHL0Connect() || IsMHL1Connect()) ) {
        return;
    }
    if (MHL_IsPackedPixelMode()) {
        MHLPackedPixelMode(FALSE);
    }
    SC_MHL_CTRL_2E0 = 0x00; //detect SCDT in ZP
    SetCbusConnectStatus(MHL_NONE);
    SC_CBUS_INT_EN = 0xFF; //turn off interrupt
#endif
    SC_ADC_ZERO_POWER_CTRL = 0x83;
    SC_ADC_REG_1D &= ~BIT6;
    SC_SOG_SLICER_CTRL = SCREG_012_PD;
    SC_SOG_SLICER_EN = 0x01;
    SchmittTriggerPowerOff();

    DVI_PowerOff();
#if (INPUT_INTERFACE&INPUT_DP)
    DP_PowerOFF();
#endif
    // For improving the issue of unabling to wake up from DPSM mode over some specific TMDS source
    // Jude 2011/11/07
#if 1
    SC_DVI_ZERO_POWER_CTRL = 0x00;
    SC_DVI1_ZERO_POWER_CTRL = 0x00;
#else
    if (pwroff) {
        SC_DVI_ZERO_POWER_CTRL = 0x00;
        SC_DVI1_ZERO_POWER_CTRL = 0x00;
    }
    else {
        SC_DVI_ZERO_POWER_CTRL = 0x12;
        SC_DVI1_ZERO_POWER_CTRL = 0x12;
    }
#endif

    SC_MPLL_X2 = (BIT4|BIT3); // 3MHz
    SC_APR_LDO_CTRL = 0x04;
    SC_ZERO_POWER_LDO18 = SCREG_055_PD;
    SC_OSC_LDO18 = SCREG_056_PD;
    SC_MCU_CLK_DIVIDER = 0x22; // 3MHz
    SC_LVDS_MISC_CTRL1 &= ~BIT6;    //bit6=0
    SC_LVDS_MISC_CTRL2 &= 0xF8;
    SC_LVDS_MISC_CTRL3 = 0x00; //  2009-03-19
//  Used to control HPD    
//    if ( pwroff ) {
//        SC_18V_LDO_CONTROL &= ~BIT6;
//    }
    
#if ENABLE_HW_CEC == ON
    CECUpdateRefClock();
#endif

    SC_ADC_ZERO_POWER_CTRL = 0x03;
#if ENABLE_CUT_POWER_ARCH == ON
#if IS_NT68850_SERIES || IS_NT68790_SERIES// || IS_NT68658_SERIES
    #if (INPUT_INTERFACE&INPUT_DP)
    DPConfigHWHPD(FALSE);
    #endif
    SC_ISOLATION_CONTROL = SCREB_B61_PD|BIT4;
#else
    SC_ISOLATION_CONTROL = SCREB_B61_PD;
#endif
    SC_CUT_POWER_CTRL |= (SCREB_B62_PD & ~BIT1);//0xF8
#if 0//IS_NT68150_SERIES
//    SC_CUT_POWER_CTRL |= BIT1;
    SC_CUT_POWER_CTRL &= ~BIT2;
//    SC_CUT_POWER_CTRL &= ~BIT0;
#else
    SC_CUT_POWER_CTRL |= BIT1;
    SC_CUT_POWER_CTRL &= ~BIT2;
    SC_CUT_POWER_CTRL &= ~BIT0;
#endif
#endif

    LDO_ADJ &= ~(BIT7|BIT4); //Power down APLL for power consumption
//    LDO_ADJ |= BIT0;
    //Samuel-2010-02-09: For UART communication in low-power mode.
    TL1 = 256 - GetUARTTimer(REF_CLK/4);
    TH1 = 256 - GetUARTTimer(REF_CLK/4);
    bLowPowerMode = TRUE;
#if IS_NT68790_SERIES || IS_NT68658_SERIES
#if MD_ENABLE_DC2DC == ON
    SC_DVI2_ZERO_POWER_CTRL &= ~BIT3;
#endif
#endif
}

/**************************************************************************//**
 * Turn off scaler register read/write power.
 ******************************************************************************/
void PowerDownRegisterAccess(void)
{
    SC_ADC_ZERO_POWER_CTRL &= ~(BIT7);
}

/**************************************************************************//**
 * Turn on scaler register read/write power.
 ******************************************************************************/
void PowerUpRegisterAccess(void)
{
    SC_ADC_ZERO_POWER_CTRL |= (BIT7|BIT1|BIT0);
}

/**************************************************************************//**
 * Chech current power status
 ******************************************************************************/
BOOL IsZpMode(void)
{
    return bLowPowerMode;
}

/**************************************************************************//**
 * Turn on scaler main power (scaler registers are 0x101, 0x102).
 ******************************************************************************/
void TurnOnScalerMainPower(void)
{
#if ENABLE_MMU == ON
    SC_POWER_CTRL2 = 0x6E;
#else
    SC_POWER_CTRL2 = 0x6A;
#endif
#if ENABLE_SCALER_AUDIO
    SC_POWER_CTRL2 |= BIT7;
#endif
    SC_POWER_CTRL1 = 0x40;
}

/**************************************************************************//**
 * Turn off scaler main power (scaler registers are 0x101, 0x102).
 ******************************************************************************/
void TurnOffScalerMainPower(void)
{
    SC_POWER_CTRL1 = 0x0F;
    SC_POWER_CTRL2 = 0x00;
}

/**************************************************************************//**
 * Turn off the power of TMDS input.
 ******************************************************************************/
void PowerDownDigitalInput(void)
{
    DVI_PowerOff();
}

/**************************************************************************//**
 * Turn off the power of analog input.
 ******************************************************************************/
void PowerDownAnalogInput(void)
{
    VGA_PowerOff();
}

/**************************************************************************//**
 * Turn on the power of all input.
 ******************************************************************************/
void PowerUpAllInput(void)
{
    DVI_PowerOn();
    VGA_PowerOn();
#if (INPUT_INTERFACE&INPUT_DP)
    DP_PowerOn();
#endif
}

#if ENABLE_LOW_PWR_MODE == ON
/**************************************************************************//**
 * Restore SC_MCU_CLK_DIVIDER to zero power setting.
 ******************************************************************************/
void McuClkDivderCheck(void)
{
    if ((bLowPowerMode == TRUE) && (SC_MCU_CLK_DIVIDER == 0x00)) {
        if (++usMCUCLKDIVIDERLoop >= 500) {
            McuIICPreSendACK(MCU_IIC_CON_DEFAULT);
            SC_MCU_CLK_DIVIDER = 0x22;
        }
    }
}
#endif
