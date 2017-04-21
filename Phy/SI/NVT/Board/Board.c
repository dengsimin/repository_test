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

//******************************************************************************
// G L O B A L   D E F I N I T I O N S
//******************************************************************************

//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************
#if PANEL_POWER_PORT == MCU_PORT_NULL
static bit bPanelPower = (~PANEL_POWER_ACTIVE & BIT0);
#endif
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
// Prototype: 
//  BOOL bIsCableConnect(void)
// Parameters:
//  None
// Return:
//  TRUE/FALSE
// Purpose:
//  Determine the cable connection
// Notes:
//  None
//******************************************************************************
BOOL bIsCableConnect(void)
{
#if defined(ENABLE_FPGA_MODE)
    return 1;
#else
    UCHAR i = 0;
#if INPUT_INTERFACE&INPUT_VGA0
    if (bIsVGAConnect() == TRUE) {
        i++;
    }
#endif
#if INPUT_INTERFACE&INPUT_DIG0
    if (IsDigital0Connect() == TRUE) {
        i++;
    }
#endif
#if INPUT_INTERFACE&INPUT_DIG1 //dvi 
    if (IsDigital1Connect() == TRUE) {
        i++;
    }
#endif
#if INPUT_INTERFACE&INPUT_DIG2 
    if (IsDigital2Connect() == TRUE) {
        i++;
    }
#endif
#if INPUT_INTERFACE&INPUT_DIG3 //hdmi
    if (IsDigital3Connect() == TRUE) {
        i++;
    }
#endif
#if INPUT_INTERFACE&INPUT_DP   // dp
    if (IsDPConnect() == TRUE) {
        i++;
    }
#endif
#if INPUT_INTERFACE&INPUT_DP1
    if (IsDP1Connect() == TRUE) {
        i++;
    }
#endif
#if INPUT_INTERFACE&INPUT_DP2
    if (IsDP2Connect() == TRUE) {
        i++;
    }
#endif
#if INPUT_INTERFACE&INPUT_DP3
    if (IsDP3Connect() == TRUE) {
        i++;
    }
#endif
//    return (bIsVGAConnect() | IsDigital1Connect() | IsDigital0Connect() | IsDPConnect() | IsDP1Connect());
    if (i != 0) {
        return TRUE;
    }
    else {
        return FALSE;
    }
#endif
}

//******************************************************************************
// Prototype: 
//  BOOL bIsVGAConnect(void)
// Parameters:
//  None
// Return:
//  TRUE/FALSE
// Purpose:
//  Determine the VGA cable connection
// Notes:
//  None
//******************************************************************************
#if !lrd_dis
BOOL bIsVGAConnect(void)
{
#if VGA_CABLE_PORT == MCU_PORT_NULL
#if IS_NT68150_SERIES
    UCHAR level;
    SetADC5VRange(VGA_DET_ADC);//5V ADC
    McuPowerUpADC();
    McuStartADC();
    McuWaitADCComplete();
    McuPowerDownADC();
    level = McuGetADC(VGA_DET_ADC);
    if (level > VGA_DET_LEVEL) {
        return FALSE;
    }
    else {
        return TRUE;
    }
#elif IS_NT68658_SERIES
    UCHAR level;
//    SetADC5VRange(VGA_DET_ADC);//5V ADC
    McuPowerUpADC();
    McuStartADC();
    McuWaitADCComplete();
    McuPowerDownADC();
    level = McuGetADC(VGA_DET_ADC);
    if (level > VGA_DET_LEVEL) {
        return FALSE;
    }
    else {
        return TRUE;
    }
#else
    return FALSE;
#endif
#else
    if (McuGetIOBit(VGA_CABLE_PORT, VGA_CABLE_BIT) == VGA_CABLE_ACTIVE) {
        return TRUE;
    }
    else {
        return FALSE;
    }
#endif
}
#endif
#if INPUT_INTERFACE&INPUT_DIG2
//******************************************************************************
// Prototype: 
//  BOOL IsDigital2Connect(void)
// Parameters:
//  None
// Return:
//  TRUE/FALSE
// Purpose:
//  Determine the digital interface 1 cable connection
// Notes:
//  None
//******************************************************************************
BOOL IsDigital2Connect(void)
{
	BOOL bConFlag;
	bConFlag = FALSE;
#if DIGI2_CABLE_PORT != MCU_PORT_NULL // ºê lrd add
    if (McuGetIOBit(DIGI2_CABLE_PORT, DIGI2_CABLE_BIT) == DIGI2_CABLE_ACTIVE) {
        bConFlag = TRUE;
    }
#if (INPUT_INTERFACE&INPUT_MHL2)
	if (MHL_Is_CDSense1_IO_HIGH())
	{
        if (IsMHL0Connect()) {
			bConFlag = TRUE;
        }
	}	
#endif
#endif
    return bConFlag;
}
#endif

#if INPUT_INTERFACE&INPUT_DIG3
//******************************************************************************
// Prototype: 
//  BOOL IsDigital3Connect(void)
// Parameters:
//  None
// Return:
//  TRUE/FALSE
// Purpose:
//  Determine the digital interface 1 cable connection
// Notes:
//  None
//******************************************************************************
BOOL IsDigital3Connect(void)
{
	BOOL bConFlag;
	bConFlag = FALSE;
    if (McuGetIOBit(DIGI3_CABLE_PORT, DIGI3_CABLE_BIT) == DIGI3_CABLE_ACTIVE) {
        bConFlag = TRUE;
    }
#if (INPUT_INTERFACE&INPUT_MHL3)
	if (MHL_Is_CDSense2_IO_HIGH())
	{
        if (IsMHL1Connect()) {
			bConFlag = TRUE;
        }
	}	
#endif
    return bConFlag;
}
#endif
//******************************************************************************
// Prototype: 
//  BOOL IsDigital1Connect(void)
// Parameters:
//  None
// Return:
//  TRUE/FALSE
// Purpose:
//  Determine the digital interface 1 cable connection
// Notes:
//  None
//******************************************************************************
BOOL IsDigital1Connect(void)
{
#if DIGI1_CABLE_PORT == MCU_PORT_NULL
#ifdef CABLE_DET_PORT
    UCHAR level;
//    SetADC5VRange(VGA_DET_ADC);//5V ADC
    McuPowerUpADC();
    McuStartADC();
    McuWaitADCComplete();
    McuPowerDownADC();
    level = McuGetADC(CABLE_DET_PORT);
    if ((abs(HDMI_CABLE_LEVE-level) < 10) || (abs(BOTH_ON_LEVE-level) < 10)){
        return TRUE;
    }
    else {
        return FALSE;
    }
#else
    return FALSE;
#endif
#else
#if IS_NT68810_SERIES || IS_NT68870_SERIES
	BOOL bConFlag;
	bConFlag = FALSE;
    if (McuGetIOBit(DIGI1_CABLE_PORT, DIGI1_CABLE_BIT) == DIGI1_CABLE_ACTIVE) {
        bConFlag = TRUE;
    }
	#if (INPUT_INTERFACE&INPUT_MHL1)
	if (MHL_Is_CDSense2_IO_HIGH())
	{
        if (IsMHL1Connect()) {
			bConFlag = TRUE;
        }
	}	
	#endif
    return bConFlag;
#else
    if (McuGetIOBit(DIGI1_CABLE_PORT, DIGI1_CABLE_BIT) == DIGI1_CABLE_ACTIVE) {
#if (INPUT_INTERFACE&INPUT_MHL1)
        if ( MHLIsCBus2On() == ON && !IsMHL1Connect()) {
            return FALSE;
        }
#endif
        return TRUE;
    }
    else {
        return FALSE;
    }
#endif
#endif
}

//******************************************************************************
// Prototype: 
//  BOOL IsDigital0Connect(void)
// Parameters:
//  None
// Return:
//  TRUE/FALSE
// Purpose:
//  Determine the digital interface 0 cable connection
// Notes:
//  None
//******************************************************************************
#if !lrd_dis
BOOL IsDigital0Connect(void)
{
#if DIGI0_CABLE_PORT == MCU_PORT_NULL
#if IS_NT68658_SERIES||IS_NT68360_SERIES
    UCHAR level;
//    SetADC5VRange(DIGI0_DET_ADC);//5V ADC
    McuPowerUpADC();
    McuStartADC();
    McuWaitADCComplete();
    McuPowerDownADC();
    level = McuGetADC(DIGI0_DET_ADC);
    if (level > DIGI0_DET_LEVEL) {
        return FALSE;
    }
    else {
        return TRUE;
    }
#else
#ifdef CABLE_DET_PORT
    UCHAR level;
//    SetADC5VRange(VGA_DET_ADC);//5V ADC
    McuPowerUpADC();
    McuStartADC();
    McuWaitADCComplete();
    McuPowerDownADC();
    level = McuGetADC(CABLE_DET_PORT);
    if ((abs(HDMI_CABLE_LEVE-level) < 10) || (abs(BOTH_ON_LEVE-level) < 10)){
        return TRUE;
    }
    else {
        return FALSE;
    }
#else
    return FALSE;
#endif
#endif

#else
#if IS_NT68810_SERIES || IS_NT68870_SERIES
	BOOL bConFlag;
	bConFlag = FALSE;
    if (McuGetIOBit(DIGI0_CABLE_PORT, DIGI0_CABLE_BIT) == DIGI0_CABLE_ACTIVE) {
		bConFlag = TRUE;
    }
#if (INPUT_INTERFACE&INPUT_MHL0)
	if (MHL_Is_CDSense1_IO_HIGH())
	{
        if (IsMHL0Connect()) {
			bConFlag = TRUE;
        }
	}	
#endif
    return bConFlag;
#else
		if (McuGetIOBit(DIGI0_CABLE_PORT, DIGI0_CABLE_BIT) == DIGI0_CABLE_ACTIVE) {
#if (INPUT_INTERFACE&INPUT_MHL0)
			if ( MHLIsCBus1On() == ON && !IsMHL0Connect()) {
				return FALSE;
		}
#endif
				return TRUE;
		}
		else {
			return FALSE;
		}
#endif
#endif
}
#endif
//******************************************************************************
// Prototype: 
//  BOOL IsDPConnect(void)
// Parameters:
//  None
// Return:
//  TRUE/FALSE
// Purpose:
//  Determine the DP interface cable connection
// Notes:
//  None
//******************************************************************************
BOOL IsDPConnect(void)
{
#if (INPUT_INTERFACE&INPUT_DP)
#if DP_CABLE_PORT == MCU_PORT_NULL
#ifdef CABLE_DET_PORT
    UCHAR level;
//    SetADC5VRange(VGA_DET_ADC);//5V ADC
    McuPowerUpADC();
    McuStartADC();
    McuWaitADCComplete();
    McuPowerDownADC();
    level = McuGetADC(CABLE_DET_PORT);
    if ((abs(DP_CABLE_LEVE-level) < 10) || (abs(BOTH_ON_LEVE-level) < 10)){
        return TRUE;
    }
    else {
        return FALSE;
    }
#else
    return FALSE;
#endif
#else
    if (McuGetIOBit(DP_CABLE_PORT, DP_CABLE_BIT) == DP_CABLE_ACTIVE) {
        return TRUE;
    }
    else {
        return FALSE;
    }
#endif
#else
    return FALSE;
#endif
}
#if !lrd_dis

BOOL IsDP1Connect(void)
{
#if (INPUT_INTERFACE&INPUT_DP1)
#if DP1_CABLE_PORT == MCU_PORT_NULL
#ifdef CABLE_DET_PORT
    UCHAR level;
//    SetADC5VRange(VGA_DET_ADC);//5V ADC
    McuPowerUpADC();
    McuStartADC();
    McuWaitADCComplete();
    McuPowerDownADC();
    level = McuGetADC(CABLE_DET_PORT);
    if ((abs(DP_CABLE_LEVE-level) < 10) || (abs(BOTH_ON_LEVE-level) < 10)){
        return TRUE;
    }
    else {
        return FALSE;
    }
#else
    return FALSE;
#endif
#else
    if (McuGetIOBit(DP1_CABLE_PORT, DP1_CABLE_BIT) == DP1_CABLE_ACTIVE) {
        return TRUE;
    }
    else {
        return FALSE;
    }
#endif
#else
    return FALSE;
#endif
}

BOOL IsDP2Connect(void)
{
#if (INPUT_INTERFACE&INPUT_DP2)
    if (McuGetIOBit(DP2_CABLE_PORT, DP2_CABLE_BIT) == DP2_CABLE_ACTIVE) {
        return TRUE;
    }
    else {
        return FALSE;
    }
#else
    return FALSE;
#endif
}

BOOL IsDP3Connect(void)
{
#if (INPUT_INTERFACE&INPUT_DP2)
    if (McuGetIOBit(DP3_CABLE_PORT, DP3_CABLE_BIT) == DP3_CABLE_ACTIVE) {
        return TRUE;
    }
    else {
        return FALSE;
    }
#else
    return FALSE;
#endif
}
#endif
//******************************************************************************
// Prototype: 
//  BOOL IsPanelPowerOn(void)
// Parameters:
//  None
// Return:
//  TRUE/FALSE
// Purpose:
//  Check panel power.
// Notes:
//  None
//******************************************************************************
BOOL IsPanelPowerOn(void)
{
#if PANEL_POWER_PORT == MCU_PORT_NULL
    return bPanelPower;
#else
    if (McuGetIOBit(PANEL_POWER_PORT, PANEL_POWER_BIT) == PANEL_POWER_ACTIVE) {
        return TRUE;
    }
    else {
        return FALSE;
    }
#endif
}

//******************************************************************************
// Prototype: 
//  void LedGreenOn(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Turn on the green LED.
// Notes:
//  None
//******************************************************************************
void LedGreenOn(void)
{
#if (!defined(ENABLE_FPGA_MODE))
    McuSetIOBit(LED_GREEN_PORT, LED_GREEN_BIT, LED_GREEN_ACTIVE);
#endif
}

//******************************************************************************
// Prototype: 
//  void LedGreenOn(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Turn off the green LED.
// Notes:
//  None
//******************************************************************************
void LedGreenOff(void)
{
#if (!defined(ENABLE_FPGA_MODE))
    McuSetIOBit(LED_GREEN_PORT, LED_GREEN_BIT, ~LED_GREEN_ACTIVE);
#endif
}

//******************************************************************************
// Prototype: 
//  void LedRedOn(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Turn on the red LED.
// Notes:
//  None
//******************************************************************************
void LedRedOn(void)
{
#if (!defined(ENABLE_FPGA_MODE))
    McuSetIOBit(LED_RED_PORT, LED_RED_BIT, LED_RED_ACTIVE);
#endif
}

//******************************************************************************
// Prototype: 
//  void LedRedOff(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Turn off the red LED.
// Notes:
//  None
//******************************************************************************
void LedRedOff(void)
{
#if (!defined(ENABLE_FPGA_MODE))
    McuSetIOBit(LED_RED_PORT, LED_RED_BIT, ~LED_RED_ACTIVE);
#endif
}

//******************************************************************************
// Prototype: 
//  void PanelPowerOn(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Turn on the panel power.
// Notes:
//  None
//******************************************************************************
void PanelPowerOn(void)
{
#if PANEL_POWER_PORT == MCU_PORT_NULL
    bPanelPower = PANEL_POWER_ACTIVE & BIT0;
#else
    McuSetIOBit(PANEL_POWER_PORT, PANEL_POWER_BIT, PANEL_POWER_ACTIVE);
#endif
}

//******************************************************************************
// Prototype: 
//  void PanelPowerOff(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Turn off the panel power.
// Notes:
//  None
//******************************************************************************
void PanelPowerOff(void)
{
#if PANEL_POWER_PORT == MCU_PORT_NULL
    bPanelPower = ~PANEL_POWER_ACTIVE & BIT0;
#else
    McuSetIOBit(PANEL_POWER_PORT, PANEL_POWER_BIT, ~PANEL_POWER_ACTIVE);
#endif
}

//******************************************************************************
// Prototype: 
//  void BacklightOn(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Turn on the backlight.
// Notes:
//  None
//******************************************************************************
void BacklightOn(void)
{
#if ENABLE_SCALER_LEDDRV == ON
    LEDDriverOnOff(ON);
#else
    McuSetIOBit(BACKLIGHT_PORT, BACKLIGHT_BIT, BACKLIGHT_ACTIVE);
#endif
#if ENABLE_ESD_PROTECT == ON
    ReadESDCheckSum();
#endif
}

//******************************************************************************
// Prototype: 
//  void BacklightOff(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Turn off the backlight.
// Notes:
//  None
//******************************************************************************
void BacklightOff(void)
{
#if ENABLE_SCALER_LEDDRV == ON
    LEDDriverOnOff(OFF);
#else
    McuSetIOBit(BACKLIGHT_PORT, BACKLIGHT_BIT, ~BACKLIGHT_ACTIVE);
#endif
}

#if 1//ENABLE_ESD_PROTECT == ON
//******************************************************************************
// Prototype: 
//  BOOL IsBackLightOn(void)
// Parameters:
//  None
// Return:
//  TRUE/FALSE
// Purpose:
//  Check panel power.
// Notes:
//  None
//******************************************************************************
BOOL IsBackLightOn(void)
{
    if (McuGetIOBit(BACKLIGHT_PORT, BACKLIGHT_BIT) == BACKLIGHT_ACTIVE) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}
#endif

//******************************************************************************
// Prototype: 
//  void AudioPowerOn(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Turn on the Audio AMP power.
// Notes:
//  None
//******************************************************************************
void AudioPowerOn(void)
{
    McuSetIOBit(AMP_PWR_PORT, AMP_PWR_BIT, AMP_PWR_ACTIVE);
}

//******************************************************************************
// Prototype: 
//  void AudioPowerOff(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Turn off the Audio AMP power.
// Notes:
//  None
//******************************************************************************
void AudioPowerOff(void)
{
    McuSetIOBit(AMP_PWR_PORT, AMP_PWR_BIT, ~AMP_PWR_ACTIVE);
}

//******************************************************************************
// Prototype: 
//  void AudioAMP_Off(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Mute the Audio AMP.
// Notes:
//  None
//******************************************************************************
void AudioMuteOn(void)
{
#if ENABLE_SCALER_AUDIO == ON
#if (INPUT_INTERFACE&INPUT_MHL_MASK)
    UCHAR currentInterface = GetCurrInputInterface();
    if (((currentInterface == DIGITAL_INPUT0) && (MHL_Is_CDSense1_IO_HIGH() == TRUE))
     || ((currentInterface == DIGITAL_INPUT1) && (MHL_Is_CDSense2_IO_HIGH() == TRUE))
     || ((currentInterface == DIGITAL_INPUT2) && (MHL_Is_CDSense1_IO_HIGH() == TRUE))
     || ((currentInterface == DIGITAL_INPUT3) && (MHL_Is_CDSense2_IO_HIGH() == TRUE))) {
    }
    else
#endif        
    {
        while ((GetTimerTick()-usTimerANAMute) < 150) {
            ResetWDTimer();
        }
    }
#endif
    McuSetIOBit(AMP_MUTE_PORT, AMP_MUTE_BIT, AMP_MUTE_ACTIVE);

#if ENABLE_SCALER_AUDIO == ON
    Sleep(1);
    SC_AUDIO_OUT_CTRL |= BIT1; // 0x721
#endif
}

//******************************************************************************
// Prototype: 
//  void AudioAMP_On(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Turn on the Audio AMP.
// Notes:
//  None
//******************************************************************************
void AudioMuteOff(void)
{
#if ENABLE_SCALER_AUDIO == ON
    SC_AUDIO_OUT_CTRL &= ~BIT1; // 0x721
    Sleep(1);
#endif
    McuSetIOBit(AMP_MUTE_PORT, AMP_MUTE_BIT, ~AMP_MUTE_ACTIVE);
}

//******************************************************************************
// Prototype: 
//  void EdidWPOn(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  
// Notes:
//  None
//******************************************************************************
void EdidWPOn(void)
{
    McuSetIOBit(EDID_WP_PORT, EDID_WP_BIT, EDID_WP_ACTIVE);
}

//******************************************************************************
// Prototype: 
//  void EdidWPOff(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  
// Notes:
//  None
//******************************************************************************
void EdidWPOff(void)
{
    McuSetIOBit(EDID_WP_PORT, EDID_WP_BIT, ~EDID_WP_ACTIVE);
}

#if ENABLE_CUT_POWER_ARCH == ON
//******************************************************************************
// Prototype: 
//  void PowerMOSOn(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Turn on the power MOS
// Notes:
//  None
//******************************************************************************
void PowerMOSOn(void)
{
    McuSetIOBit(POWER_MOS_PORT, POWER_MOS_BIT, POWER_MOS_ACTIVE);
}

//******************************************************************************
// Prototype: 
//  void PowerMOSOff(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Turn off the power MOS
// Notes:
//  None
//******************************************************************************
void PowerMOSOff(void)
{
    McuSetIOBit(POWER_MOS_PORT, POWER_MOS_BIT, ~POWER_MOS_ACTIVE);
}
#endif

#if ENABLE_DIGI3_HPD == ON
//******************************************************************************
// Prototype: 
//  void Digi3HPDOn(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Set hot plug in active state (connected)
// Notes:
//  None
//******************************************************************************
void Digi3HPDOn(void)
{
    McuSetIOBit(DIG3_HPD_PORT, DIG3_HPD_BIT, DIG3_HPD_ACTIVE);
}

//******************************************************************************
// Prototype: 
//  void Digi3HPDOff(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Set hot plug in inactive state (disconnected)
// Notes:
//  None
//******************************************************************************
void Digi3HPDOff(void)
{
    McuSetIOBit(DIG3_HPD_PORT, DIG3_HPD_BIT, ~DIG3_HPD_ACTIVE);
}
#endif
#if ENABLE_DIGI2_HPD == ON
//******************************************************************************
// Prototype: 
//  void Digi2HPDOn(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Set hot plug in active state (connected)
// Notes:
//  None
//******************************************************************************
void Digi2HPDOn(void)
{
    McuSetIOBit(DIG2_HPD_PORT, DIG2_HPD_BIT, DIG2_HPD_ACTIVE);
}

//******************************************************************************
// Prototype: 
//  void Digi2HPDOff(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Set hot plug in inactive state (disconnected)
// Notes:
//  None
//******************************************************************************
void Digi2HPDOff(void)
{
    McuSetIOBit(DIG2_HPD_PORT, DIG2_HPD_BIT, ~DIG2_HPD_ACTIVE);
}
#endif
#if ENABLE_DIGI1_HPD == ON
//******************************************************************************
// Prototype: 
//  void Digi1HPDOn(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Set hot plug in active state (connected)
// Notes:
//  None
//******************************************************************************
void Digi1HPDOn(void)
{
    McuSetIOBit(DIG1_HPD_PORT, DIG1_HPD_BIT, DIG1_HPD_ACTIVE);
}

//******************************************************************************
// Prototype: 
//  void Digi1HPDOff(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Set hot plug in inactive state (disconnected)
// Notes:
//  None
//******************************************************************************
void Digi1HPDOff(void)
{
    McuSetIOBit(DIG1_HPD_PORT, DIG1_HPD_BIT, ~DIG1_HPD_ACTIVE);
}
#endif

#if ENABLE_DIGI0_HPD == ON
//******************************************************************************
// Prototype: 
//  void Digi0HPDOn(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Set hot plug in active state (connected)
// Notes:
//  None
//******************************************************************************
void Digi0HPDOn(void)
{
    McuSetIOBit(DIG0_HPD_PORT, DIG0_HPD_BIT, DIG0_HPD_ACTIVE);
}

//******************************************************************************
// Prototype: 
//  void Digi0HPDOff(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Set hot plug in inactive state (disconnected)
// Notes:
//  None
//******************************************************************************
void Digi0HPDOff(void)
{
    McuSetIOBit(DIG0_HPD_PORT, DIG0_HPD_BIT, ~DIG0_HPD_ACTIVE);
}
#endif

#if (INPUT_INTERFACE&INPUT_DP)
//******************************************************************************
// Prototype: 
//  void DPHPDOn(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Set hot plug in active state (connected)
// Notes:
//  None
//******************************************************************************
void DPHPDOn(void)
{
    McuSetIOBit(DP_HPD_PORT, DP_HPD_BIT, DP_HPD_ACTIVE);
    if (IsZpMode() == FALSE) {
        DPConfigHWHPD(TRUE);
    }
}

#if ENABLE_DP_HPD == ON
//******************************************************************************
// Prototype: 
//  void DPHPDOff(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Set hot plug in inactive state (disconnected)
// Notes:
//  None
//******************************************************************************
void DPHPDOff(void)
{
    McuSetIOBit(DP_HPD_PORT, DP_HPD_BIT, ~DP_HPD_ACTIVE);
    DPConfigHWHPD(FALSE);
}
#endif
#endif
#if (INPUT_INTERFACE&INPUT_DP1)
void DP1HPDOn(void)
{
    McuSetIOBit(DP1_HPD_PORT, DP1_HPD_BIT, DP1_HPD_ACTIVE);
    if (IsZpMode() == FALSE) {
        DPConfigHWHPD(TRUE);
    }
}
#if ENABLE_DP1_HPD == ON
void DP1HPDOff(void)
{
    McuSetIOBit(DP1_HPD_PORT, DP1_HPD_BIT, ~DP1_HPD_ACTIVE);
    DPConfigHWHPD(FALSE);
}
#endif
#endif

#if (INPUT_INTERFACE&INPUT_DP2)
void DP2HPDOn(void)
{
    McuSetIOBit(DP2_HPD_PORT, DP2_HPD_BIT, DP2_HPD_ACTIVE);
    if (IsZpMode() == FALSE) {
        DPConfigHWHPD(TRUE);
    }
}
#if ENABLE_DP2_HPD == ON
void DP2HPDOff(void)
{
    McuSetIOBit(DP2_HPD_PORT, DP2_HPD_BIT, ~DP2_HPD_ACTIVE);
    DPConfigHWHPD(FALSE);
}
#endif
#endif

#if (INPUT_INTERFACE&INPUT_DP3)
void DP3HPDOn(void)
{
    McuSetIOBit(DP3_HPD_PORT, DP3_HPD_BIT, DP3_HPD_ACTIVE);
    if (IsZpMode() == FALSE) {
        DPConfigHWHPD(TRUE);
    }
}
#if ENABLE_DP3_HPD == ON
void DP3HPDOff(void)
{
    McuSetIOBit(DP3_HPD_PORT, DP3_HPD_BIT, ~DP3_HPD_ACTIVE);
    DPConfigHWHPD(FALSE);
}
#endif
#endif

#if (ENABLE_DIGI3_HPD == ON) ||(ENABLE_DIGI2_HPD == ON) ||(ENABLE_DIGI1_HPD == ON) || (ENABLE_DIGI0_HPD == ON) || (ENABLE_DP_HPD == ON) || (ENABLE_DP1_HPD == ON) || (ENABLE_DP2_HPD == ON) || (ENABLE_DP3_HPD == ON)
//******************************************************************************
// Prototype: 
//  BOOL bIsHPDActive(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
BOOL bIsHPDActive(void)
{
   UCHAR curr_interface = GetCurrInputInterface();

#if IS_NT68810_SERIES || IS_NT68870_SERIES
    #if (INPUT_INTERFACE&INPUT_MHL0)
    if ( curr_interface == DIGITAL_INPUT0 && MHL_Is_CDSense1_IO_HIGH() ) {
        return TRUE;
    }
    #endif
    #if (INPUT_INTERFACE&INPUT_MHL1)
    if ( curr_interface == DIGITAL_INPUT1 && MHL_Is_CDSense2_IO_HIGH() ) {
        return TRUE;
    }
    #endif 
    #if (INPUT_INTERFACE&INPUT_MHL2)
    if ( curr_interface == DIGITAL_INPUT2 && MHL_Is_CDSense1_IO_HIGH() ) {
        return TRUE;
    }
    #endif
    #if (INPUT_INTERFACE&INPUT_MHL3)
    if ( curr_interface == DIGITAL_INPUT3 && MHL_Is_CDSense2_IO_HIGH() ) {
        return TRUE;
    }
    #endif	
#else    
	#if (INPUT_INTERFACE&INPUT_MHL0)
    if ( curr_interface == DIGITAL_INPUT0 && IsMHL0CableConnect() ) {
        return TRUE;
    }
	#endif
	#if (INPUT_INTERFACE&INPUT_MHL1)
    if ( curr_interface == DIGITAL_INPUT1 && IsMHL1CableConnect() ) {
        return TRUE;
    }
	#endif
#endif

#if ENABLE_DIGI0_HPD == ON && DIG0_HPD_PORT != MCU_PORT_NULL
   if (McuGetIOBit(DIG0_HPD_PORT, DIG0_HPD_BIT) != DIG0_HPD_ACTIVE && curr_interface == DIGITAL_INPUT0) {
        return FALSE;
    }
#endif
#if ENABLE_DIGI1_HPD == ON && DIG1_HPD_PORT != MCU_PORT_NULL
   if (McuGetIOBit(DIG1_HPD_PORT, DIG1_HPD_BIT) != DIG1_HPD_ACTIVE && curr_interface == DIGITAL_INPUT1) {
        return FALSE;
    }
#endif
#if (INPUT_INTERFACE&INPUT_DIG2)
#if ENABLE_DIGI2_HPD == ON && DIG2_HPD_PORT != MCU_PORT_NULL
   if (McuGetIOBit(DIG2_HPD_PORT, DIG2_HPD_BIT) != DIG2_HPD_ACTIVE && curr_interface == DIGITAL_INPUT2) {
        return FALSE;
    }
#endif
#endif
#if (INPUT_INTERFACE&INPUT_DIG3)
#if ENABLE_DIGI3_HPD == ON && DIG3_HPD_PORT != MCU_PORT_NULL
   if (McuGetIOBit(DIG3_HPD_PORT, DIG3_HPD_BIT) != DIG3_HPD_ACTIVE && curr_interface == DIGITAL_INPUT3) {
        return FALSE;
    }
#endif
#endif
#if (INPUT_INTERFACE&INPUT_DP)
#if ENABLE_DP_HPD == ON && DP_HPD_PORT != MCU_PORT_NULL
   if (McuGetIOBit(DP_HPD_PORT, DP_HPD_BIT) != DP_HPD_ACTIVE && curr_interface == DISPLAY_PORT_INPUT) {
        return FALSE;
    }
#endif
#endif
#if (INPUT_INTERFACE&INPUT_DP1)
#if ENABLE_DP1_HPD == ON && DP1_HPD_PORT != MCU_PORT_NULL
   if (McuGetIOBit(DP1_HPD_PORT, DP1_HPD_BIT) != DP1_HPD_ACTIVE && curr_interface == DISPLAY_PORT_INPUT1) {
        return FALSE;
    }
#endif
#endif
#if (INPUT_INTERFACE&INPUT_DP2)
#if ENABLE_DP2_HPD == ON && DP2_HPD_PORT != MCU_PORT_NULL
   if (McuGetIOBit(DP2_HPD_PORT, DP2_HPD_BIT) != DP2_HPD_ACTIVE && curr_interface == DISPLAY_PORT_INPUT2) {
        return FALSE;
    }
#endif
#endif
#if (INPUT_INTERFACE&INPUT_DP3)
#if ENABLE_DP3_HPD == ON && DP3_HPD_PORT != MCU_PORT_NULL
   if (McuGetIOBit(DP3_HPD_PORT, DP3_HPD_BIT) != DP3_HPD_ACTIVE && curr_interface == DISPLAY_PORT_INPUT3) {
        return FALSE;
    }
#endif
#endif

#if ENABLE_USB_TYPE_C == ON
    if (curr_interface == USB_TYPE_C_INTERFACE && IsUSBCCHPDActive() == TRUE) { //need add cc status.
        return FALSE;
    }
#endif
    return TRUE;
}
#endif

#if IS_NT68790_SERIES
void ConfigHPD(void)
{
UCHAR hpd;
    hpd = 0x00;

    if (GetSCID() == SCID_790_A) {
        if ((DP_HPD_PORT == MCU_PORT_E) && (DP_HPD_BIT == BIT6)) { // PE6/HPD1/CBUS1
            hpd |= BIT2;//pull up +3.3V
        }
        if ((DP_HPD_PORT == MCU_PORT_E) && (DP_HPD_BIT == BIT7)) { // PE7/HPD2/CBUS2
            hpd |= BIT0;//pull up +3.3V
        }
        if ((DIG0_HPD_PORT == MCU_PORT_E) && (DIG0_HPD_BIT == BIT6)) { // PE6/HPD1/CBUS1
            hpd |= BIT3;//pull up +5V
        }
        if ((DIG0_HPD_PORT == MCU_PORT_E) && (DIG0_HPD_BIT == BIT7)) { // PE7/HPD2/CBUS2
            hpd |= BIT1;//pull up +5V
        }
        if ((DIG1_HPD_PORT == MCU_PORT_E) && (DIG1_HPD_BIT == BIT6)) { // PE6/HPD1/CBUS1
            hpd |= BIT3;//pull up +5V
        }
        if ((DIG1_HPD_PORT == MCU_PORT_E) && (DIG1_HPD_BIT == BIT7)) { // PE7/HPD2/CBUS2
            hpd |= BIT1;//pull up +5V
        }
    }
    else {//b version
        if ((DP_HPD_PORT == MCU_PORT_E) && (DP_HPD_BIT == BIT6)) { // PE6/HPD1/CBUS1
            hpd |= BIT0;//pull up +3.3V
        }
        if ((DP_HPD_PORT == MCU_PORT_E) && (DP_HPD_BIT == BIT7)) { // PE7/HPD2/CBUS2
            hpd |= BIT2;//pull up +3.3V
        }
        if ((DIG0_HPD_PORT == MCU_PORT_E) && (DIG0_HPD_BIT == BIT6)) { // PE6/HPD1/CBUS1
            hpd |= BIT1;//pull up +5V
        }
        if ((DIG0_HPD_PORT == MCU_PORT_E) && (DIG0_HPD_BIT == BIT7)) { // PE7/HPD2/CBUS2
            hpd |= BIT3;//pull up +5V
        }
        if ((DIG1_HPD_PORT == MCU_PORT_E) && (DIG1_HPD_BIT == BIT6)) { // PE6/HPD1/CBUS1
            hpd |= BIT1;//pull up +5V
        }
        if ((DIG1_HPD_PORT == MCU_PORT_E) && (DIG1_HPD_BIT == BIT7)) { // PE7/HPD2/CBUS2
            hpd |= BIT3;//pull up +5V
        }
    }
    HPD_CTRL = hpd;//0x06;
}
#endif
#if IS_NT68810_SERIES || IS_NT68870_SERIES
void ConfigHPD(void)
{
    if ((DP_HPD_PORT == MCU_PORT_E) && (DP_HPD_BIT == BIT6)) { // PE6/HPD1/CBUS1
        SC_SetBitDPppPHY(_DPPP_PHY0, _TMDS_HPD_IO_CTRL, BIT5, FALSE);//pull up +3.3V
    }
    if ((DP_HPD_PORT == MCU_PORT_E) && (DP_HPD_BIT == BIT7)) { // PE7/HPD2/CBUS2
#if IS_NT68810_SERIES
        SC_SetBitDPppPHY(_DPPP_PHY0, _TMDS_HPD_IO_CTRL, BIT6, FALSE);//pull up +3.3V
#else
        SC_SetBitDPppPHY(_DPPP_PHY1, _TMDS_HPD_IO_CTRL, BIT6, FALSE);//pull up +3.3V
#endif
    }
    if ((DP1_HPD_PORT == MCU_PORT_E) && (DP1_HPD_BIT == BIT6)) { // PE6/HPD1/CBUS1
        SC_SetBitDPppPHY(_DPPP_PHY0, _TMDS_HPD_IO_CTRL, BIT5, FALSE);//pull up +3.3V
    }
    if ((DP1_HPD_PORT == MCU_PORT_E) && (DP1_HPD_BIT == BIT7)) { // PE7/HPD2/CBUS2
#if IS_NT68810_SERIES
        SC_SetBitDPppPHY(_DPPP_PHY0, _TMDS_HPD_IO_CTRL, BIT6, FALSE);//pull up +3.3V
#else
        SC_SetBitDPppPHY(_DPPP_PHY1, _TMDS_HPD_IO_CTRL, BIT6, FALSE);//pull up +3.3V
#endif
    }
    
    if ((DIG0_HPD_PORT == MCU_PORT_E) && (DIG0_HPD_BIT == BIT6)) { // PE6/HPD1/CBUS1
        SC_SetBitDPppPHY(_DPPP_PHY0, _TMDS_HPD_IO_CTRL, BIT5, TRUE);//pull up +5V
    }
    if ((DIG0_HPD_PORT == MCU_PORT_E) && (DIG0_HPD_BIT == BIT7)) { // PE7/HPD2/CBUS2
#if IS_NT68810_SERIES
        SC_SetBitDPppPHY(_DPPP_PHY0, _TMDS_HPD_IO_CTRL, BIT6, TRUE);//pull up +5V
#else
        SC_SetBitDPppPHY(_DPPP_PHY1, _TMDS_HPD_IO_CTRL, BIT6, TRUE);//pull up +5V
#endif
    }
    if ((DIG1_HPD_PORT == MCU_PORT_E) && (DIG1_HPD_BIT == BIT6)) { // PE6/HPD1/CBUS1
        SC_SetBitDPppPHY(_DPPP_PHY0, _TMDS_HPD_IO_CTRL, BIT5, TRUE);//pull up +5V
    }
    if ((DIG1_HPD_PORT == MCU_PORT_E) && (DIG1_HPD_BIT == BIT7)) { // PE7/HPD2/CBUS2
#if IS_NT68810_SERIES
        SC_SetBitDPppPHY(_DPPP_PHY0, _TMDS_HPD_IO_CTRL, BIT6, TRUE);//pull up +5V
#else
        SC_SetBitDPppPHY(_DPPP_PHY1, _TMDS_HPD_IO_CTRL, BIT6, TRUE);//pull up +5V
#endif
    }
}
#endif

#if ENABLE_USB_TYPE_C == ON
void AUXPNSwapOn(void)
{
    McuSetIOBit(AUXPN_SWAP_PORT, AUXPN_SWAP_BIT, AUXPN_SWAP_ACTIVE);
}

void AUXPNSwapOff(void)
{
    McuSetIOBit(AUXPN_SWAP_PORT, AUXPN_SWAP_BIT, ~AUXPN_SWAP_ACTIVE);
}

void BillBoardEnableOn(void)
{
    McuSetIOBit(BILLBOARD_ENABLE_PORT, BILLBOARD_ENABLE_BIT, BILLBOARD_ENABLE_ACTIVE);
}

void BillBoardEnableOff(void)
{
    McuSetIOBit(BILLBOARD_ENABLE_PORT, BILLBOARD_ENABLE_BIT, ~BILLBOARD_ENABLE_ACTIVE);
}
#endif
