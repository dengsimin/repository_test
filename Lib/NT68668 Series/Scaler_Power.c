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
static UCHAR Reg0x8C80;
static UCHAR Reg0x8C81;
static UCHAR Reg0x8C82;
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
/**************************************************************************//**
 * Turn the scaler to power saving state.
 ******************************************************************************/
void ScalerPowerSaving(void)
{
    DisplayPostPattern(POSTPTN_WHITE);//discharge panel power
    DisableScalerPWM(PWM_ALL); //Turn off PWMA/PWMB
    DisableDPLL();
    DVI_PowerOff();
    VGA_PowerOff();
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
    else {
#if IS_NT68669_SERIES
        Reg0x8C80 = SC_MCU_IO_CTRL;
#elif IS_NT68660_SERIES || IS_NT68650_SERIES
        Reg0x8C81 = SC_MCU_IO_CTRL2;
        Reg0x8C82 = SC_MCU_IO_CTRL3;
#endif

    }
#endif
}

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
    DisplayPostPattern(POSTPTN_WHITE);//discharge panel power
    DisableScalerPWM(PWM_ALL); //Turn off PWMA/PWMB
    DisableDPLL();
    DVI_PowerOff();
    VGA_PowerOff();
    DisplayMuteImage();
#if ENABLE_MMU == ON
    MMUPowerOff();
#endif
    TurnOffScalerMainPower();
#if ENABLE_LOW_PWR_MODE == ON
    McuPowerDownAPLL();
    SetLowPowerMode(TRUE);
#endif
}

/**************************************************************************//**
 * Turn on scaler power.
 ******************************************************************************/
void ScalerPowerUp(void)
{
    ClearForceToSleep();
    if ((SC_POWER_CTRL1 & BIT3) != 0) {
        McuPowerUpAPLL();
        SetNormalPowerMode();
        TurnOnScalerMainPower();
    #if ENABLE_MMU == ON
        MMUPowerOn();
    #endif
        EnableScalerPWM(PWM_ALL);//Turn on PWMA/PWMB
        EnableDPLL();
        DVI_PowerOn();
        VGA_PowerOn();
    }
    SetModeChangeFlag();
}

/**************************************************************************//**
 * Turn the scaler to the normal power state.
 ******************************************************************************/
void SetNormalPowerMode(void)
{
#if IS_NT68650_SERIES || IS_NT68660_SERIES
    SC_ADC_ZERO_POWER_CTRL = 0x83;
    if (((CPU_CLK & 0xF0) == 0x00) || ((CPU_CLK & 0xF0) == 0x10)) {
        if (!(LDO_ADJ & BIT7)) {
            SC_MCU_PLL &= ~BIT1;    // APnote: When MCU CLK is 12Mhz,
                                    // we need to set 0xB04[0] as 0 before APLL power up.
        }
    }
#endif
#if IS_NT68168_SERIES
    LDO_ADJ |= (BIT7 | BIT4 | BIT0);   // Power Up APLL LDO
#else
    LDO_ADJ |= (BIT7 | BIT4);   // Power Up APLL LDO
#endif
    
#if (ENABLE_INTERNAL_LDO == ON) || (ENABLE_INTERNAL_ADC_LDO == ON)
    SC_ADC_ZERO_POWER_CTRL = SCREG_057_INT_LDO;
#else
    SC_ADC_ZERO_POWER_CTRL = SCREG_057_EXT_LDO;
#endif
    SC_ADC_BAND_GAP = SCREG_1ED;
    SC_MCU_CLK_DIVIDER = 0x00;

    SC_ZERO_POWER_LDO18 = SCREG_055_PU;
    SC_OSC_LDO18 = (SCREG_056_PU & (~BIT6));
    Sleep(2);
    SC_OSC_LDO18 = SCREG_056_PU;
    
#if ENABLE_INTERNAL_LDO == ON
    SC_APR_LDO_CTRL = SCREG_05A_INT_LDO;
#else
    SC_APR_LDO_CTRL = SCREG_05A_EXT_LDO;
#endif
    SC_ADC_MID_CH_SEL |= BIT7;
    SC_ADC_CLAMP_CTRL = SCREG_00F_PU;     //power up SOG bandgap
    SC_SOG_SLICER_CTRL = 0x7D;    //SOG slicer en

    SC_MPLL_DIV = 0x04;
    SC_MPLL_CTRL_B41 = SCREG_B41;
#if IS_NT68650_SERIES || IS_NT68660_SERIES
    SC_MPLL_CTRL_B42 = 0x08;
#endif
    SC_MPLL_LDO_VADJ = 0x2A;
    SC_MPLL_X2 = 0x03;

    SC_DVI_ZERO_POWER_CTRL = 0x00;

#if IS_NT68669_SERIES
    SC_BYPASS_CTRL = 0x00;
    SC_MCU_IO_CTRL = Reg0x8C80;//0xC0;
#elif IS_NT68650_SERIES || IS_NT68660_SERIES
    SC_BYPASS_CTRL = 0x00;
    SC_MCU_IO_CTRL2 = Reg0x8C81;////|= 0x04; //Pin 76 -> PWM A for Brihtness
    SC_MCU_IO_CTRL3 = Reg0x8C82;//0x00;
    HVFilterOn();
#endif

    SC_POWER_CTRL1 = 0x40;
    SC_POWER_CTRL2 = 0x6A;
#if ENABLE_MMU == ON
    SC_POWER_CTRL2 |= BIT2;
#endif

    SC_ADC_TEST2_CTRL &= ~BIT2;
    SC_ADC_POWER_UP |= 0x07;

    SchmittTriggerPowerOn();
    bLowPowerMode = FALSE;
}

/**************************************************************************//**
 * Turn the scaler to the zero power state.
 * @param pwroff TRUE to indicate "power off", FALSE is "power saving"
 ******************************************************************************/
#if ENABLE_LOW_PWR_MODE == ON
void SetLowPowerMode(UCHAR pwroff)
{
    // Return immediately to avoid performing low power procedure twice or more
    if (bLowPowerMode && (pwroff == FALSE)) {
        return;
    }

    // To avoid wrong I/O setting during power saving mode
    if (bLowPowerMode == FALSE) {
        SC_ADC_TEST2_CTRL |= BIT2;
    #if IS_NT68669_SERIES
        SC_BYPASS_CTRL = 0xFF;
        Reg0x8C80 = SC_MCU_IO_CTRL;
        SC_MCU_IO_CTRL = 0x00;
    #elif IS_NT68660_SERIES || IS_NT68650_SERIES
        SC_BYPASS_CTRL = 0xFF;
        Reg0x8C81 = SC_MCU_IO_CTRL2;
        Reg0x8C82 = SC_MCU_IO_CTRL3;
        SC_MCU_IO_CTRL2 &= 0x01;
        SC_MCU_IO_CTRL3 = 0x00;
        HVFilterOff();
    #endif
    }

    SC_ADC_BAND_GAP &= ~BIT3; 
    SC_ADC_ZERO_POWER_CTRL = 0x83;
    SC_ADC_MID_CH_SEL &= ~BIT7;
    SC_ADC_CLAMP_CTRL = SCREG_00F_PD;    //power down SOG bandgap
    //SC_SOG_CLAMPING_CTRL = 0x52;    //SOG clamp dis
    SC_SOG_SLICER_CTRL = 0x78;    //SOG slicer dis
    SchmittTriggerPowerOff();

    DVI_PowerOff();

    // For improving the issue of unabling to wake up from DPSM mode over some specific TMDS source
    // Jude 2011/11/07
#if 1
    SC_DVI_ZERO_POWER_CTRL = 0x00;
#else
    if (pwroff) {
        SC_DVI_ZERO_POWER_CTRL = 0x00;
    }
    else {
        SC_DVI_ZERO_POWER_CTRL = 0x12;
    }
#endif

    SC_MPLL_X2 = 0x00;
    
    SC_APR_LDO_CTRL = SCREG_05A_PD; //exit ZP mode
    SC_OSC_LDO18 = (SC_OSC_LDO18 & (~BIT6));
    Sleep(2);
    SC_OSC_LDO18 = SCREG_056_PD;
    SC_ZERO_POWER_LDO18 = SCREG_055_PD;
    SC_MCU_CLK_DIVIDER = 0x22; // 3MHz
    SC_POWER_CTRL1 = 0x0f;
    SC_LVDS_MISC_CTRL3 = SCREG_1F7_PD;

    SC_LVDS_MISC_CTRL1 &= ~BIT6;
    

#if IS_NT68660_SERIES || IS_NT68650_SERIES
    if (((CPU_CLK & 0xF0) == 0x00) || ((CPU_CLK & 0xF0) == 0x10)) {
        if (LDO_ADJ & BIT7) {
            SC_MCU_PLL |= BIT1; // APnote: When MCU CLK is 12Mhz,
                                // we need to set 0xB04[0] as 1 before APLL power down.
        }
    }
#endif
    LDO_ADJ &= ~(BIT7); //Power down APLL for power consumption
    SC_ADC_ZERO_POWER_CTRL = 0x03;
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
#endif

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
    SC_POWER_CTRL1 = 0x40;
}

/**************************************************************************//**
 * Turn off scaler main power (scaler registers are 0x101, 0x102).
 ******************************************************************************/
void TurnOffScalerMainPower(void)
{
    SC_POWER_CTRL1 = 0x0F;
    SC_POWER_CTRL2 = 0x40;
}

/**************************************************************************//**
 * Turn off the power of TMDS input.
 ******************************************************************************/
void PowerDownDigitalInput(void)
{
#if IS_NT68660_SERIES || IS_NT68650_SERIES
    SC_DVI_CTRL_333 = 0x80;
#else
    SC_DVI_CTRL_333 = 0x87;
#endif
    SC_DVI_CTRL_334 = 0x01;
    SC_DVI_CTRL_336 = 0x00;
#if ENABLE_MMU == ON
    SC_POWER_CTRL2 = 0x6C;
#else
    SC_POWER_CTRL2 = 0x68;
#endif
}

/**************************************************************************//**
 * Turn off the power of analog input.
 ******************************************************************************/
void PowerDownAnalogInput(void)
{
#if ENABLE_MMU == ON
    SC_POWER_CTRL2 = 0x26;
#else
    SC_POWER_CTRL2 = 0x22;
#endif
}

/**************************************************************************//**
 * Turn on the power of all input.
 ******************************************************************************/
void PowerUpAllInput(void)
{
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

#if ENABLE_MMU == ON
    SC_POWER_CTRL2 = 0x6E;
#else
    SC_POWER_CTRL2 = 0x6A;
#endif
}

/**************************************************************************//**
 * Restore SC_MCU_CLK_DIVIDER to zero power setting.
 ******************************************************************************/
#if ENABLE_LOW_PWR_MODE == ON
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
