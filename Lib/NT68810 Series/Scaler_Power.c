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
#include "Scaler_DP_6502.h"
#include "Scaler_TMDS_6502.h"

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
    AphyPowerOff(TRUE);
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1) || (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
    DP_PowerOFF();
    Set6502Reset();
#endif
#if 1//IS_NT68810_SERIES
#if (INPUT_INTERFACE&INPUT_DIG0) || (INPUT_INTERFACE&INPUT_DIG1)
    TMDS_EnableCKDT(_DPPP_PHY0);
#endif
#if (INPUT_INTERFACE&INPUT_DIG2) || (INPUT_INTERFACE&INPUT_DIG3)
    TMDS_EnableCKDT(_DPPP_PHY1);
#endif
#endif
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1)
    SC_DPpp_CFG_TMDS_1A00[_DPRP_REG_1FD] = 0x64;
#endif
#if (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
    SC_DPpp_CFG_TMDS_1700[_DPRP_REG_1FD] = 0x64;
#endif
#if IS_NT68870_SERIES
#if (INPUT_INTERFACE & INPUT_MHL_MASK) 
    MHL_PhyOff();
#endif
#endif

    DisplayMuteImage();
#if ENABLE_MMU == ON
    MMUPowerOff();
#endif
    TurnOffScalerMainPower();
    if(UserData.ucAutoPowerOffTime != AUTO_POWER_OFF){
        UserSetAutoPowerOffTimer();
    }
#if ENABLE_LOW_PWR_MODE == ON
    McuPowerDownAPLL();
    if (bForceToSleep == FALSE) {
        SetLowPowerMode(FALSE);
    }
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1)
//    SC_POWER_CTRL2 |= BIT1;
//    SC_DPpp_CFG_TMDS_1A00[_DPRP_REG_1FD] = 0x64;
    DPConfigAUXDetect();
#endif
#if (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
//    SC_POWER_CTRL2 |= BIT1;
//    SC_DPpp_CFG_TMDS_1700[_DPRP_REG_1FD] = 0x64;
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
    AphyPowerOff(TRUE);
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1) || (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
    DP_PowerOFF();
    Set6502Reset();
#endif
    DisplayMuteImage();
#if ENABLE_MMU == ON
    MMUPowerOff();
#endif
    TurnOffScalerMainPower();
#if ENABLE_LOW_PWR_MODE == ON
    McuPowerDownAPLL();
    SetLowPowerMode(TRUE);
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1) || (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
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
#if IS_NT68810_SERIES || IS_NT68870_SERIES
    do {
        ResetWDTimer();
        SC_ZERO_PWR_CTRL_B69 |= BIT0;
        SC_ZERO_PWR_CTRL_B69 &= ~BIT0;
        Sleep(AO_KEY_DEBOUNCE_TIME); //wait HW debounce
    } while ((SC_ZERO_PWR_CTRL_B64 & BIT2) != 0);

//    SC_ZERO_PWR_CTRL_B64 = 0xE0;//|= BIT1;//need add stby key.
//    ZPLatchData();
#else
    do {
        ResetWDTimer();
        AO_DETECT |= BIT2;
        Sleep(AO_KEY_DEBOUNCE_TIME); //wait HW debounce
    } while ((AO_DETECT & BIT2) != 0);

    AO_DETECT |= BIT1;//need add stby key.
    Sleep(1);
    AO_DETECT &= ~BIT1;//need add stby key.
#endif
#else
    PowerMOSOff();
#endif
#endif
}
#if (IS_NT68810_SERIES || IS_NT68870_SERIES)
void ZPLatchData(void)
{
    SC_ZERO_PWR_CTRL_B66 &= ~BIT7;
    SC_ZERO_PWR_CTRL_B66 |= BIT7;
    SC_ZERO_PWR_CTRL_B66 &= ~BIT7;
}
#if MD_ENABLE_AO_DETECT == ON
void SetZPDetect(UCHAR mode)
{
    switch (mode) {
    case ZP_CLEAR://clear
        SC_ZERO_PWR_CTRL_B64 = 0x00;
        SC_ZERO_PWR_CTRL_B65 = (BIT2 | BIT1);//0x02;
        SC_ZERO_PWR_CTRL_B66 = 0x57;
        break;
    case ZP_SYNC_DET://power saving
        SC_DPpp_CFG_TMDS_1A00[0x246] = 0x03;
        SC_DPpp_CFG_TMDS_1A00[0x246] = 0x01;
        SC_DPpp_CFG_TMDS_1A00[_DPRP_REG_1FD] = 0x64;
        SC_DPpp_CFG_TMDS_1A00[_DPPHY_EQR_IMP_ENABLE] = 0x00;
        SC_DPpp_CFG_TMDS_1A00[_DPPHY_EQR_RES_CTRL3] = 0x00;
        SC_DPpp_CFG_TMDS_1A00[0x240] = 0x00;
        SC_DPpp_CFG_TMDS_1A00[0x242] = 0x11;//0x11;//0x22;
        SC_ISOLATION_CONTROL |= BIT4;
        SC_ZERO_PWR_CTRL_B64 = 0xE0;
        SC_ZERO_PWR_CTRL_B65 = 0x0E;//0x08;
        SC_ZERO_PWR_CTRL_B66 = 0x3F;//0x3B;//0x3F;
        break;
    case ZP_DC_OFF://DC off
        SC_ZERO_PWR_CTRL_B64 = 0x00;
        SC_ZERO_PWR_CTRL_B65 = 0x00;
        SC_ZERO_PWR_CTRL_B66 = 0x01;
        break;
   }
}

void ZPClearADC(void)
{
    SC_ZERO_PWR_CTRL_B69 = 0x00;
    ZPLatchData();
    SC_ZERO_PWR_CTRL_B69 = 0x03;
    ZPLatchData();
    SC_ZERO_PWR_CTRL_B69 = 0x02;
    ZPLatchData();
}

void ZPResetADC(void)
{
    SC_ZERO_PWR_CTRL_B69 = 0x00;
    ZPLatchData();
    SC_ZERO_PWR_CTRL_B69 = 0x03;
    ZPLatchData();
    SC_ZERO_PWR_CTRL_B69 = 0x00;
    ZPLatchData();
}

void ZPPowerOff(void)
{
    SC_ZERO_PWR_CTRL_B64 &= ~BIT1;
    Sleep(1);
    SC_ZERO_PWR_CTRL_B64 |= BIT1;
    Sleep(1);
    SC_ZERO_PWR_CTRL_B64 &= ~BIT1;
    while(1){
        Sleep(10);
#if 1//debug
        if ((SC_ZERO_PWR_CTRL_B67 & 0x0E) != 0) {//Error
            break;
        }
#endif
    }
}
#endif
#endif
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
#if IS_NT68790_SERIES || IS_NT68658_SERIES// || IS_NT68810_SERIES || IS_NT68870_SERIES
#if MD_ENABLE_DC2DC == ON
    SC_ADC_ZERO_POWER_CTRL = 0x81;// 0xb57
    SC_DVI2_ZERO_POWER_CTRL |= BIT3;
    SC_DC2DC_E39 = 0x06;//en=0x06, disenable=0x00. RA==>disable
    #if IS_NT68658_SERIES
        SC_DC2DC_E3A = 0x00;
    #else
        SC_DC2DC_E3A = 0x01;
    #endif
    SC_APR_ISOLATION = 0x00;
#else
    SC_ADC_ZERO_POWER_CTRL = 0x81;// 0xb57
    SC_DVI2_ZERO_POWER_CTRL = 0x00;  // 0xb5d
    SC_APR_ISOLATION = 0x03;  // 0xb5f
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
//    SC_CUT_POWER_CTRL |= BIT2;
    SC_CUT_POWER_CTRL |= BIT0;  // 0xb62
    SC_ISOLATION_CONTROL = SCREB_B61_PU;
    SC_CUT_POWER_CTRL &= 0x07; // 0xb62
    SC_CUT_POWER_CTRL &= ~BIT1; // 0xb62
    SC_POWER_CTRL1 &= ~BIT7;
}
#endif
#if IS_NT68790_SERIES || IS_NT68658_SERIES// || IS_NT68810_SERIES || IS_NT68870_SERIES
#if MD_ENABLE_DC2DC == ON
    SC_ADC_ZERO_POWER_CTRL = 0x81;// 0xb57
    SC_DVI2_ZERO_POWER_CTRL |= BIT3;
    SC_DC2DC_E39 = 0x06;//en=0x06, disenable=0x00. RA==>disable
    #if IS_NT68658_SERIES
        SC_DC2DC_E3A = 0x00;
    #else
        SC_DC2DC_E3A = 0x01;
    #endif
    SC_APR_ISOLATION = 0x00;
#else
    SC_ADC_ZERO_POWER_CTRL = 0x81;// 0xb57
    SC_DVI2_ZERO_POWER_CTRL = 0x00; // 0xb5d
    SC_APR_ISOLATION = 0x03;  // 0xb5f
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
    SC_ADC_ZERO_POWER_CTRL = SCREG_057_INT_LDO;// 0xb57
#else
    SC_ADC_ZERO_POWER_CTRL = SCREG_057_EXT_LDO;// 0xb57
#endif
    SC_MPLL_B3E = 0xFE;//0xF2;//WRITE     B0    B3E  F2
    SC_MPLL_B3F = 0xA1;//0x51;//WRITE     B0    B3F  51
    SC_MPLL_B45 = 0x71;//0x60;//WRITE     B0    B45  60
    SC_MCU_CLK_DIVIDER = 0x00;
    SC_ZERO_POWER_LDO18 = SCREG_055_PU;
    SC_OSC_LDO18 = SCREG_056_PU;  // 0xb56

#if 0//ENABLE_INTERNAL_LDO == ON
    SC_APR_LDO_CTRL = 0x00;
#else
    SC_APR_LDO_V_CTRL |= BIT0;//NT68850 沒有 LDO, 所以 b53 的 control register 後來都被拿去當 apr2 的 clock gen control 使用
#if IS_NT68870_SERIES
    SC_APR_LDO_CTRL = 0x48;//0x40 is the original setting for 810  // 0xb5a
//    SC_LDO_2V5_CTRL_BD2 = 0x07;
#else
    SC_APR_LDO_CTRL = 0x40;//0x40 is the original setting for 810
#endif
#endif
    
//    SC_SOG_SLICER_CTRL = 0x00;
//    SC_SOG_SLICER_EN = 0x80;
    SC_ADC_IP_CTRL_1D80[_ADC_POWER_CTRL] |= BIT4;  // 0x1db5
    SC_ADC_IP_CTRL_1D80[_ADC_MISC_CTRL_33] = 0xDE;// 0x1db3
//    Sleep(1);

    SC_MPLL_DIV = SCREG_B40;
    SC_MPLL_CTRL_B41 = SCREG_B41;
    SC_MPLL_CTRL_B42 = SCREG_B42;
    SC_MPLL_LDO_VADJ = SCREG_B43;
//    SC_MPLL_X2 = 0x03;
    
    SC_DVI_ZERO_POWER_CTRL = 0x00;  // 0xb58
    SC_DVI1_ZERO_POWER_CTRL = 0x00;// 0xb5B

    SC_ADC_REG_1D |= BIT6;//870=0x1ec     // 0x1ea
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
#if (INPUT_INTERFACE&INPUT_MHL_MASK)
    if (GetCbusConnectStatus() == MHL_DATA_RDY) {
        MHLClearHPD();
    }
    if ( pwroff ) {
        //TPV requests VBus keeping on while DC off??
        SC_CBUS_RESISTOR_CTRL = 0x00;//samsung S2: DC off/on issue
    }
    else if ( (IsMHL0Connect() || IsMHL1Connect()) ) {
        return;
    }
    if (MHL_IsPackedPixelMode(MHL_CBUS_CH1)) {
        MHLPackedPixelMode(MHL_CBUS_CH1, FALSE);        
    }
    if (MHL_IsPackedPixelMode(MHL_CBUS_CH2)) {
        MHLPackedPixelMode(MHL_CBUS_CH2, FALSE);        
    }
    //SC_MHL_CTRL_2E0 = 0x00; //detect SCDT in ZP
    SetCbusConnectStatus(MHL_NONE);
#if IS_NT68810_SERIES || IS_NT68870_SERIES
	SC_CBUS_INT_EN = 0x00;
#else
    SC_CBUS_INT_EN = 0xFF; //turn off interrupt
#endif
#endif
#if 0//ENABLE_USB_TYPE_C == ON
    if (IsUSBCCVBusAttach() == TRUE) {
        return;
    }
#endif

    SC_ADC_ZERO_POWER_CTRL = 0x83;// 0xb57
    SC_ADC_REG_1D &= ~BIT6;//870=0x1ec   
//    SC_SOG_SLICER_CTRL = SCREG_012_PD;
//    SC_SOG_SLICER_EN = 0x01;
    SC_ADC_IP_CTRL_1D80[_ADC_SOG_DISCUR] = 0x00;//SOG_DISCUR
    SC_ADC_IP_CTRL_1D80[_ADC_SOG_THRESHOLD] = 0x00;//SOGTH
    SC_ADC_IP_CTRL_1D80[_ADC_SOG_CLAMP_CURRENT] = 0x00;//SOG_CLP_SW
    SC_ADC_IP_CTRL_1D80[_ADC_MISC_CTRL_33] = 0x00;
    SchmittTriggerPowerOff();

    DVI_PowerOff();
#if 0//(INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1) || (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
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

//    SC_MPLL_X2 = (BIT4|BIT3); // 3MHz
//    SC_APR_LDO_CTRL = 0x00;//0x04;
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

    SC_ADC_ZERO_POWER_CTRL = 0x03;// 0xb57
#if ENABLE_CUT_POWER_ARCH == ON
    #if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1) || (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
    DPConfigHWHPD(FALSE);
    #endif
    SC_ISOLATION_CONTROL = SCREB_B61_PD;

    SC_CUT_POWER_CTRL |= (SCREB_B62_PD & ~BIT1);//0xF8
    SC_CUT_POWER_CTRL |= BIT1;
//    SC_CUT_POWER_CTRL &= ~BIT2;
    SC_CUT_POWER_CTRL &= ~BIT0;
#endif

    LDO_ADJ &= ~(BIT7|BIT4); //Power down APLL for power consumption
//    LDO_ADJ |= BIT0;
    //Samuel-2010-02-09: For UART communication in low-power mode.
    TL1 = 256 - GetUARTTimer(REF_CLK/4);
    TH1 = 256 - GetUARTTimer(REF_CLK/4);
    bLowPowerMode = TRUE;
#if IS_NT68790_SERIES || IS_NT68658_SERIES// || IS_NT68810_SERIES || IS_NT68870_SERIES
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
    SC_ADC_ZERO_POWER_CTRL &= ~(BIT7);// 0xb57
}

/**************************************************************************//**
 * Turn on scaler register read/write power.
 ******************************************************************************/
void PowerUpRegisterAccess(void)
{
    SC_ADC_ZERO_POWER_CTRL |= (BIT7|BIT1|BIT0);// 0xb57
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
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1) || (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
//    DP_PowerOn();
    DP_CLKOn();
#endif
#if ENABLE_SCALER_AUDIO == ON
    ScalerAudioPowerOn();
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
