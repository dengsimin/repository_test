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
#if ENABLE_LOW_PWR_MODE
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
    DisplayPostPattern(POSTPTN_WHITE);// Discharge panel power
    DisableScalerPWM(PWM_ALL);
#if ENABLE_SCALER_AUDIO == ON
    ScalerAudioPowerOff();
#endif
    DisableDPLL();
    DVI_PowerOff();
    VGA_PowerOff();
    DisplayMuteImage();
#if ENABLE_MMU == ON
    MMUPowerOff();
#endif
    TurnOffScalerMainPower();
    McuPowerDownAPLL();
    if (bForceToSleep == FALSE) {
        SetLowPowerMode(FALSE);
#if ENABLE_CUT_POWER_ARCH == ON
        PowerMOSOff();
#endif
    }
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
    DisplayPostPattern(POSTPTN_WHITE); // Discharge panel power
    DisableScalerPWM(PWM_ALL);
#if ENABLE_SCALER_AUDIO == ON
    ScalerAudioPowerOff();
#endif
    DisableDPLL();
    DVI_PowerOff();
    VGA_PowerOff();
    DisplayMuteImage();
#if ENABLE_MMU == ON
    MMUPowerOff();
#endif
    TurnOffScalerMainPower();
    McuPowerDownAPLL();
    SetLowPowerMode(TRUE);
#if ENABLE_CUT_POWER_ARCH == ON
    PowerMOSOff();
#endif
}

/**************************************************************************//**
 * Turn on scaler power.
 ******************************************************************************/
void ScalerPowerUp(void)
{
    ClearForceToSleep();
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
    #endif
    #if ENABLE_MMU == ON
        MMUPowerOn();
    #endif
        EnableScalerPWM(PWM_ALL);//Turn on PWMA/PWMB
        EnableDPLL();
        DVI_PowerOn();
        VGA_PowerOn();
    #if ENABLE_SCALER_AUDIO == ON
        ScalerAudioPowerOn();
    #endif
    }
    SetModeChangeFlag();
}

/**************************************************************************//**
 * Turn the scaler to the normal power state.
 ******************************************************************************/
void SetNormalPowerMode(void)
{
    LDO_ADJ |= (BIT7 | BIT4);
    LDO_ADJ &= ~BIT0;

#if ENABLE_CUT_POWER_ARCH == ON
    SC_ISOLATION_CONTROL = SCREB_B61_PU;
    SC_LVDS_ISOLATION &= ~(BIT7 | BIT6 | BIT3);
    SC_APR_ISOLATION = 0x00;
    Sleep(1);
    SC_DDR_PHY_E22 = 0xC1;
    SC_CUT_POWER_CTRL = SCREB_B62_PU | BIT1;
    Sleep(1);
    SC_CUT_POWER_CTRL = SCREB_B62_PU;
    SC_POWER_CTRL1 &= ~BIT7;
#endif

    SC_APR_LDO_V_CTRL = 0x00;

#if (ENABLE_INTERNAL_LDO == ON) || (ENABLE_INTERNAL_ADC_LDO == ON)
    SC_ADC_ZERO_POWER_CTRL = SCREG_057_INT_LDO;
#else
    SC_ADC_ZERO_POWER_CTRL = SCREG_057_EXT_LDO;
#endif

    SC_MCU_CLK_DIVIDER = 0x00;
    SC_ZERO_POWER_LDO18 = SCREG_055_PU;
    SC_OSC_LDO18 = SCREG_056_PU;

#if ENABLE_INTERNAL_LDO == ON
    SC_APR_LDO_CTRL = 0x04;
#else
    SC_APR_LDO_CTRL = 0x3F;
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

    SC_ADC_ZERO_POWER_CTRL = 0x83;
    SC_ADC_REG_1D &= ~BIT6;
    SC_SOG_SLICER_CTRL = SCREG_012_PD;
    SC_SOG_SLICER_EN = 0x01;
    SchmittTriggerPowerOff();

    DVI_PowerOff();

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
    SC_LVDS_MISC_CTRL2 &= 0xF8;
    SC_LVDS_PAD_POWER &= ~0x88;
    SC_DDR_PHY_APLL_CTRL = 0x00;
    SC_WR_DQ_PHASE_LO = 0x08;
    SC_WR_DQ_PHASE_HI = 0x08;
    //SC_APR_LDO_CTRL = 0x0A; //exit ZP mode
    SC_LVDS_ISOLATION |= (BIT7 | BIT6 | BIT3);
    SC_APR_LDO_CTRL = 0x04; //exit ZP mode
    SC_APR_ISOLATION = 0x43;
    SC_APR_LDO_V_CTRL = 0x05;

    SC_ZERO_POWER_LDO18 = SCREG_055_PD;
    SC_OSC_LDO18 = SCREG_056_PD;
    SC_MCU_CLK_DIVIDER = 0x22; // 3MHz
    SC_LVDS_MISC_CTRL3 = 0x00; //  2009-03-19
    SC_LVDS_MISC_CTRL1 &= ~BIT6;    //bit6=0
    
#if ENABLE_HW_CEC == ON
    CECUpdateRefClock();
#endif

    SC_ADC_ZERO_POWER_CTRL = 0x03;
#if ENABLE_CUT_POWER_ARCH == ON
    SC_DDR_PHY_E22 = 0xC0;
    SC_ISOLATION_CONTROL = SCREB_B61_PD;
    SC_CUT_POWER_CTRL = SCREB_B62_PD | BIT0;
    Sleep(1);
    SC_CUT_POWER_CTRL = SCREB_B62_PD;
    SC_POWER_CTRL1 |= BIT7;
#endif

    LDO_ADJ &= ~(BIT7|BIT4); //Power down APLL for power consumption
    LDO_ADJ |= BIT0;
    //Samuel-2010-02-09: For UART communication in low-power mode.
    TL1 = 256 - GetUARTTimer(REF_CLK/4);
    TH1 = 256 - GetUARTTimer(REF_CLK/4);
    bLowPowerMode = TRUE;
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

#if ENABLE_CUT_POWER_ARCH == OFF
/**************************************************************************//**
 * Turn on scaler main power (scaler registers are 0x101, 0x102).
 ******************************************************************************/
void TurnOnScalerMainPower(void)
{
#if ENABLE_MMU == ON
    SC_POWER_CTRL2 = 0xEE;
#else
    SC_POWER_CTRL2 = 0xEA;
#endif
    SC_POWER_CTRL1 = 0x40;
}
#endif

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
    VGA_PowerOn();
    DVI_PowerOn();
}

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
