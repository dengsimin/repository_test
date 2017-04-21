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
BOOL bLowPowerMode = FALSE;

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
    DisableScalerPWM(); //Turn off PWMA/PWMB
#if ENABLE_SCALER_AUDIO == ON
    ScalerAudioPowerOff(); //Samuel-2009-04-09: Turn off PWMA/B first and then turn off audio analog power
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
    DisplayPostPattern(POSTPTN_WHITE);//discharge panel power
    DisableScalerPWM(); //Turn off PWMA/PWMB
#if ENABLE_SCALER_AUDIO == ON
    ScalerAudioPowerOff(); //Samuel-2009-04-09: Turn off PWMA/B first and then turn off audio analog power
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
        EnableScalerPWM();//Turn on PWMA/PWMB
        EnableDPLL();
        DVI_PowerOn();
        VGA_PowerOn();
    #if ENABLE_SCALER_AUDIO == ON
        ScalerAudioPowerOn();
    #endif
    }
    SetModeChangeFlag();
}

//******************************************************************************
// Prototype: 
//  void SetNormalPowerMode(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Set zero power mode to normal
// Notes:
//  None
//******************************************************************************
void SetNormalPowerMode(void)
{
    LDO_ADJ |= (BIT7 | BIT4);
    LDO_ADJ &= ~BIT0;
/*
#if ENABLE_INTERNAL_LDO == ON
    SC_APR_LDO_CTRL = 0x00;
#else
    SC_APR_LDO_CTRL = 0x3F;
#endif
*/
   
    SC_MPLL_DIV = 0x05;
    //SC_MPLL_CTRL_B41 = 0x07;
    SC_MPLL_LDO_VADJ = 0x2A;
    //SC_MPLL_X2 = 0x03;
    
   // SC_DVI_ZERO_POWER_CTRL = 0x00;
   // SC_DVI1_ZERO_POWER_CTRL = 0x00;

   // SC_ADC_REG_1D |= BIT6;
    SchmittTriggerPowerOn();
#if ENABLE_HW_CEC == ON
    CECUpdateRefClock();
#endif
    bLowPowerMode = FALSE;
}

#if ENABLE_LOW_PWR_MODE == ON
//******************************************************************************
// Prototype: 
//  void PowerDownRegisterAccess(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
void PowerDownRegisterAccess(void)
{
    SC_ADC_ZERO_POWER_CTRL &= ~(BIT7);
}

//******************************************************************************
// Prototype: 
//  void PowerUpRegisterAccess(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
void PowerUpRegisterAccess(void)
{
    SC_ADC_ZERO_POWER_CTRL |= (BIT7|BIT1|BIT0);
}
#endif

/**************************************************************************//**
 * Turn on scaler main power (scaler registers are 0x101, 0x102).
 ******************************************************************************/
void TurnOnScalerMainPower(void)
{
#if ENABLE_MMU == ON
    SC_POWER_CTRL2 = 0x6F;
#else
    SC_POWER_CTRL2 = 0x6D;
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
    SC_DVI_CTRL_333 = 0x80;
    SC_DVI_CTRL_334 = 0x01;
#if IS_NT68674_SERIES
    SC_DVI_CTRL_335 = 0x20;
#endif
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
        SC_POWER_CTRL2 = 0xA6;
#else
        SC_POWER_CTRL2 = 0xA2;
#endif
}

/**************************************************************************//**
 * Turn on the power of all input.
 ******************************************************************************/
void PowerUpAllInput(void)
{
    SC_DVI_CTRL_333 = 0x07;
    SC_DVI_CTRL_334 = 0x00;
#if IS_NT68674_SERIES
    SC_DVI_CTRL_335 = 0x20;
#endif
    SC_DVI_CTRL_336 = 0xC0;
#if ENABLE_MMU == ON
    SC_POWER_CTRL2 = 0xEF;
#else
    SC_POWER_CTRL2 = 0xED;
#endif
}

//******************************************************************************
// Prototype: 
//  void McuClkDivderCheck(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  restore SC_MCU_CLK_DIVIDER 
// Notes:
//  None
//******************************************************************************
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
