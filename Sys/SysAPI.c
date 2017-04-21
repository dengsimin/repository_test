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
// M A C R O   D E F I N I T I O N S
//******************************************************************************

//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************
static BOOL bIsACOnFlag = TRUE;
static UCHAR PreSetBrightnessPWMMax = FALSE;

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
 * Turn off system.
 ******************************************************************************/
void SYSAPI_SetPowerOff(void)
{
#if IS_NT68810_SERIES || IS_NT68870_SERIES
#if ENABLE_SCALER_AUDIO == ON
    ScalerAudioPreMute();
#endif
#endif
#if 1// 1 lrd add 
	NvramWriteSystemData(&SystemData);
	NvramWriteUserData(&UserData);
#if ((ENABLE_FE2P == ON) && (ENABLE_AUTO_CONTROL == OFF))
	FE2P_SaveToFlash();
#endif
#endif
    bShowInputNovitceFlag = TRUE;
    Custom_System.bPressKeyWakeUp = FALSE;

	ModeHandleSoftPowerOff();
    LedGreenOff();
    LedRedOff();
    AudioMuteOn();
    PanelPowerOffSequence();
    AudioPowerOff();
#if (ENABLE_DIGI3_HPD == ON) ||(ENABLE_DIGI2_HPD == ON) ||(ENABLE_DIGI1_HPD == ON) || (ENABLE_DIGI0_HPD == ON) || (ENABLE_DP_HPD == ON) || (ENABLE_DP1_HPD == ON) || (ENABLE_DP2_HPD == ON) || (ENABLE_DP3_HPD == ON)
    SYSAPI_PerformHPDOff(FALSE);
#endif
#if MD_ENABLE_AO_DETECT == OFF
    ScalerPowerDown();
#endif
#if (IS_NT68810_SERIES || IS_NT68870_SERIES) && MD_ENABLE_AO_DETECT == ON
    NvramWriteUserData(&UserData);
#if ((ENABLE_FE2P == ON) && (ENABLE_AUTO_CONTROL == OFF))
    FE2P_SaveToFlash();
#endif
    do {
        ResetWDTimer();
        SC_ZERO_PWR_CTRL_B69 |= BIT0;
        SC_ZERO_PWR_CTRL_B69 &= ~BIT0;
        Sleep(AO_KEY_DEBOUNCE_TIME); //wait HW debounce
    } while ((SC_ZERO_PWR_CTRL_B64 & BIT2) != 0);
    SetZPDetect(ZP_DC_OFF);
    ZPLatchData();
    ZPClearADC();
    ZPPowerOff();
#endif
}

/**************************************************************************//**
 * Turn on system.
 ******************************************************************************/
void SYSAPI_SetPowerOn(void)
{
    ModeHandleSoftPowerOn();
    LedRedOff();
    LedGreenOn();
    ScalerPowerUp();
    AudioPowerOn();
}

/**************************************************************************//**
 * Set system to power saving.
 ******************************************************************************/
void SYSAPI_PowerSaving(void)
{
    bShowInputNovitceFlag = TRUE;
#if IS_NT68810_SERIES || IS_NT68870_SERIES
#if ENABLE_SCALER_AUDIO == ON
    ScalerAudioPreMute();
#endif
#endif
    ModeHandlePowerSaving();
    LedGreenOff();
    LedRedOn();
    AudioMuteOn();
    PanelPowerOffSequence();
    AudioPowerOff();
#if ENABLE_USB_TYPE_C == ON
    if (IsUSBCCVBusAttach() == TRUE) {
        return;
    }
#endif

#if ENABLE_HDMI_PRETEST == OFF && ENABLE_AUTO_CONTROL == OFF
#if (IS_NT68810_SERIES || IS_NT68870_SERIES) && MD_ENABLE_AO_DETECT == ON
//    ScalerPowerDown();
    SetZPDetect(ZP_SYNC_DET);
//    ZPLatchData();
    ZPResetADC();
    ZPPowerOff();
#else
    ScalerPowerSaving();
#endif
#endif
}

/**************************************************************************//**
 * Force system to power saving state even video signal is present.
 ******************************************************************************/
void SYSAPI_ForcePowerSaving(void)
{
    SetForceToSleep();
    SYSAPI_PowerSaving();
}

/**************************************************************************//**
 * Wake system up.
 ******************************************************************************/
void SYSAPI_WakeUp(void)
{
UCHAR ZpIf = GetCurrInputInterface(); //need to discuss with Nick&James
    ModeHandleSoftPowerOn();
    LedRedOff();
    LedGreenOn();  
    ScalerPowerUp();
    
#if 0//(INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1) || (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
    ClrDPLink();
#endif
//    SetInputInterface(ZpIf);
#if (INPUT_INTERFACE&INPUT_MHL_MASK) 
    if ( MHL_IsCDSenseFlagOn() ) {
        if (( ZpIf==DIGITAL_INPUT0 && MHL_GetCbusCH() == MHL_CBUS_CH1 ) ||
             ( ZpIf==DIGITAL_INPUT1 && MHL_GetCbusCH() == MHL_CBUS_CH2 ) ||
			 ( ZpIf==DIGITAL_INPUT2 && MHL_GetCbusCH() == MHL_CBUS_CH1 ) ||
			 ( ZpIf==DIGITAL_INPUT3 && MHL_GetCbusCH() == MHL_CBUS_CH2 )    ) {
            ResetCurTimerTick();
        }
    }
#endif
}

/**************************************************************************//**
 * Check system 5V is present or not.
 * If 5V is absent, reset system in time.
 ******************************************************************************/
void SYSAPI_CheckSysPower(void)
{
    // Restart system if system 5V is absent
    if (McuCheck5V() == FALSE) {
        //((void (code*)(void))0)();
        while(1);   // Use WDT to reset instead of jump (void *) 0
                    // Because WDT is similar to HW reset. Whole HW system will
                    // be reset, but "Jump to zero" can not.
    }
}

#if ENABLE_SET_PWM_MAX_BUFFER == ON
/**************************************************************************//**
 * Set Brightness to 1023 Polling
 ******************************************************************************/
void SetBrightnessPWMMax()
{
   UCHAR port;
     if(GetSCID() == SCID_770_E){
       if(PreSetBrightnessPWMMax == TRUE){
          if (GetGlobalTimer(GLOBAL_TMR_PWM_MAX_UPDATE) == 0){ 
              PreSetBrightnessPWMMax = FALSE;
              if( GetScalerPWM(port) == 1020){
                  SetBrightness(1023);
              }
           }
       }
     }
}
#endif

/**************************************************************************//**
 * Set brightness.
 * @param br Brightness. The range is 0 ~ 1023.
 ******************************************************************************/
void SetBrightness(USHRT br)
{
#if ENABLE_SCALER_LEDDRV_ANA_MODE == ON
    SetLEDDRVCurrent(br);
#else    
#if ENABLE_SET_PWM_MAX_BUFFER == ON
    if(GetSCID() == SCID_770_E){
        if(GetScalerPWM(BKL_PWM_PORT) == 0 && br == 1023){
            br = 1020;
            PreSetBrightnessPWMMax = TRUE;
            SetGlobalTimer(GLOBAL_TMR_PWM_MAX_UPDATE,6000);    
        }else {
            if(br == 1023){
                if(GetGlobalTimer(GLOBAL_TMR_PWM_MAX_UPDATE) != 0){
                   br = 1020;;  
                }
            }else {
                PreSetBrightnessPWMMax = FALSE;
                SetGlobalTimer(GLOBAL_TMR_PWM_MAX_UPDATE,0);
            }
        }
     }
#endif

#if BKL_PWM_POL == HIGH
    SetScalerPWM(BKL_PWM_PORT, br);
#else
    SetScalerPWM(BKL_PWM_PORT, (1023 - br));
#endif
#endif//ENABLE_SCALER_LEDDRV_ANA_MODE == ON

#if ENABLE_LD == ON
    LDAPI_SetBrightness(br >> 2);
#endif
}

/**************************************************************************//**
 * Get brightness.
 * @return Value of brightness. The range is 0 ~ 1023.
 ******************************************************************************/
/*
USHRT GetBrightness(void)
{
#if BKL_PWM_POL == HIGH
    return GetScalerPWM(BKL_PWM_PORT);
#else
    return (1023-GetScalerPWM(BKL_PWM_PORT));
#endif
}
*/

/**************************************************************************//**
 * Set the PWM frequency.
 * @param enable TRUE to set frequency for normal display. FALSE to set frequency for free run.
 ******************************************************************************/
void SetBLPwmByInputVSync(UCHAR enable)
{
#if ENABLE_SCALER_LEDDRV == ON
    if (enable == TRUE) {
        SetLEDDriverFreq(BRIGHTNESS_ND_PWM_FREQ);
    }
    else {
        SetLEDDriverFreq(BRIGHTNESS_FR_PWM_FREQ);
    }
#else
    if (enable == TRUE) {
        ConfigScalerPWM(BKL_PWM_PORT, BKL_PWM_OUTPUT_PIN, BRIGHTNESS_ND_PWM_FREQ);
    }
    else {
        ConfigScalerPWM(BKL_PWM_PORT, BKL_PWM_OUTPUT_PIN, BRIGHTNESS_FR_PWM_FREQ);
    }
#endif
}

/**************************************************************************//**
 * Set audio volume.
 * @param value Value of audio volume. The range is 0 ~ 1023.
 ******************************************************************************/
void SetVolume(USHRT value)
#if 0
{
	USHRT scaler_vol;
#if 1
	if ((UserData.ucInputSource >= INPUT_SC_VGA)&&(UserData.ucInputSource <= INPUT_SC_DVI1))
	{
		scaler_vol = (ULONG) value * (MAX_VOLUME_ANOGALE_VALUE - MIN_VOLUME_ANOGALE_VALUE) / 1023
	            + MIN_VOLUME_ANOGALE_VALUE;
	}
	else//由于没有做数字信号下选用模拟通道输出，因此不用做判断。
	{
	    scaler_vol = (ULONG) value * (MAX_VOLUME_VALUE - MIN_VOLUME_VALUE) / 1023
	            + MIN_VOLUME_VALUE;

	}
#endif
#if 0
#if VOLUME_PWM_POL == HIGH
    SetScalerPWM(VOLUME_PWM_PORT, value);
#else
    SetScalerPWM(VOLUME_PWM_PORT, (1023-value));
#endif

#if ENABLE_SCALER_AUDIO == ON
    #if (VOLUME_PWM_PORT==PWM_A) || (VOLUME_PWM_PORT==PWM_B) || (VOLUME_PWM_PORT==PWM_C) || (VOLUME_PWM_PORT==PWM_D)
    ConfigScalerAudio(0xFFFF);  // Load default setting
	#else
    value = (ULONG) value * HDMI_AUDIO_VOLUME_RANGE / 1023;
    ConfigScalerAudio(value);
    #endif
#endif
#else

	if(value)
	{
#if VOLUME_PWM_POL == HIGH
				SetScalerPWM(VOLUME_PWM_PORT, 1023);
#else
				SetScalerPWM(VOLUME_PWM_PORT, 0);
#endif
//	AudioMuteOff();

	}
	else
	{
#if VOLUME_PWM_POL == HIGH
		SetScalerPWM(VOLUME_PWM_PORT, 0);
#else
		SetScalerPWM(VOLUME_PWM_PORT, 1023);
#endif
//	AudioMuteOn();

	}
    ConfigScalerAudio(scaler_vol);
#endif
}
#else
{
	USHRT scaler_vol;
#if 1
	    scaler_vol = (ULONG) value * (MAX_VOLUME_VALUE - MIN_VOLUME_VALUE) / 1023
	            + MIN_VOLUME_VALUE;
#endif
#if 0
#if VOLUME_PWM_POL == HIGH
    SetScalerPWM(VOLUME_PWM_PORT, value);
#else
    SetScalerPWM(VOLUME_PWM_PORT, (1023-value));
#endif

#if ENABLE_SCALER_AUDIO == ON
    #if (VOLUME_PWM_PORT==PWM_A) || (VOLUME_PWM_PORT==PWM_B) || (VOLUME_PWM_PORT==PWM_C) || (VOLUME_PWM_PORT==PWM_D)
    ConfigScalerAudio(0xFFFF);  // Load default setting
	#else
    value = (ULONG) value * HDMI_AUDIO_VOLUME_RANGE / 1023;
    ConfigScalerAudio(value);
    #endif
#endif
#else

	if(value)
	{
#if VOLUME_PWM_POL == HIGH
            if ((SC_AUDIO_SELECT & 0x20) != 0)//((UserData.ucInputSource >= INPUT_SC_VGA)&&(UserData.ucInputSource <= INPUT_SC_DVI1))
				SetScalerPWM(VOLUME_PWM_PORT, 700);
            else
				SetScalerPWM(VOLUME_PWM_PORT, 1023);
#else
				SetScalerPWM(VOLUME_PWM_PORT, 0);
#endif
//	AudioMuteOff();

	}
	else
	{
#if VOLUME_PWM_POL == HIGH
		SetScalerPWM(VOLUME_PWM_PORT, 0);
#else
		SetScalerPWM(VOLUME_PWM_PORT, 1023);
#endif
//	AudioMuteOn();

	}
    ConfigScalerAudio(scaler_vol);
#endif
}

#endif
/**************************************************************************//**
 * Panel power up sequence.
 * @param force TRUE to turn on backlight without checking mode handle state else FALSE.
 ******************************************************************************/
void PanelPowerOnSequence(UCHAR force)
{
#if ENABLE_EDP == ON
    USHRT local_timer;
#endif

    if (IsPanelPowerOn() == FALSE) {
        while (GetGlobalTimer(GLOBAL_TMR_PANEL_ONOFF)) {
            ResetWDTimer();
        }
        PanelPowerOn();
        Sleep(UserPanelData.usPowerUpPanelTime+PANEL_POWER_DELAY);
#if ENABLE_EDP == ON
        local_timer = GetTimerTick();
        do {
            ResetWDTimer();
            CheckDPTXHPD();
        } while ((GetTimerTick()-local_timer) < DPTX_HPD_DELAY+50);
#else
        LvdsOn();
#endif
        Sleep(UserPanelData.usPowerUpInvTime);
    }
    // Check sync status before turn on backlight to avoid panel flashing
    if (force == FALSE) {
        if (CheckModeChangeFlag() && (GetModeHandleState() == WAIT_MODE_CHANGE)) {
            return;
        }
        if ((GetInputSyncMode() == NO_SYNC) && (bIsCableConnect() == FALSE)) {
            return;
        }
        if ((GetInputSyncMode() == NO_CABLE) && (bIsCableConnect() == TRUE)) {
            return;
        }
    }
    BacklightOn();
}

/**************************************************************************//**
 * Panel power down sequence.
 ******************************************************************************/
void PanelPowerOffSequence(void)
{
    BacklightOff();
    if (IsPanelPowerOn() == TRUE) {
        Force2Background(0, 0, 0);
        OSDAPI_TurnOffOSD();//2011-05-11:Turn off OSD before white pattern insertion

        switch(PANEL_PWR_OFF_SEQUENCE_MODE){
          default:
          case PANEL_INSERT_BLACK:  
            Sleep(UserPanelData.usPowerDownInvTime);
#if ENABLE_EDP == OFF
            LvdsOff();
#endif
            Sleep(UserPanelData.usPowerDownPanelTime);
            PanelPowerOff();
          break;           
          case PANEL_INSERT_WHITE:
            SetPostBGColor(0xFF, 0xFF, 0xFF);//PANEL_INSERT_WHITE_DISCHARGE_ELECTRICITY 
            Sleep(UserPanelData.usPowerDownInvTime);
#if ENABLE_EDP == OFF
            LvdsOff();
#endif
            SetPostBGColor(0x00, 0x00, 0x00);//PANEL_INSERT_WHITE_DISCHARGE_ELECTRICITY
            Sleep(UserPanelData.usPowerDownPanelTime);
            PanelPowerOff();
          break;
          case PANEL_INSERT_WHITE|PANEL_POWER_LVDS_SWAP:
            SetPostBGColor(0xFF, 0xFF, 0xFF);//PANEL_INSERT_WHITE_DISCHARGE_ELECTRICITY
            Sleep(UserPanelData.usPowerDownPanelTime);
            PanelPowerOff();
            SetPostBGColor(0x00, 0x00, 0x00);//PANEL_INSERT_WHITE_DISCHARGE_ELECTRICITY
            Sleep(UserPanelData.usPowerDownInvTime);
#if ENABLE_EDP == OFF
            LvdsOff();
#endif
          break; 
          case PANEL_INSERT_BLACK|PANEL_POWER_LVDS_SWAP:
            Sleep(UserPanelData.usPowerDownPanelTime);
            PanelPowerOff();
            Sleep(UserPanelData.usPowerDownInvTime);
#if ENABLE_EDP == OFF
            LvdsOff();
#endif
          break;  
       }

        SetGlobalTimer(GLOBAL_TMR_PANEL_ONOFF, GBTM_PANEL_ONOFF);
    }
}

#if (ENABLE_DIGI3_HPD == ON) ||(ENABLE_DIGI2_HPD == ON) ||(ENABLE_DIGI1_HPD == ON) || (ENABLE_DIGI0_HPD == ON) || (ENABLE_DP_HPD == ON) || (ENABLE_DP1_HPD == ON) || (ENABLE_DP2_HPD == ON) || (ENABLE_DP3_HPD == ON) || (ENABLE_USB_TYPE_C == ON)
/**************************************************************************//**
 * Pull up HDP pin.
 ******************************************************************************/
void SYSAPI_PerformHPDOn(void)
{
    UCHAR curr_interface = GetCurrInputInterface();
#if ENABLE_DIGI0_HPD == ON
    if (curr_interface == DIGITAL_INPUT0) {
        Digi0HPDOn();
    }
#endif
#if ENABLE_DIGI1_HPD == ON
    if (curr_interface == DIGITAL_INPUT1) {
        Digi1HPDOn();
    }
#endif
#if ENABLE_DIGI2_HPD == ON
    if (curr_interface == DIGITAL_INPUT2) {
        Digi2HPDOn();
    }
#endif
#if ENABLE_DIGI3_HPD == ON
    if (curr_interface == DIGITAL_INPUT3) {
        Digi3HPDOn();
    }
#endif
#if ENABLE_DP_HPD == ON && ENABLE_USB_TYPE_C == OFF
    if (curr_interface == DISPLAY_PORT_INPUT) {
        DPHPDOn();
    }
#endif
#if ENABLE_DP1_HPD == ON
    if (curr_interface == DISPLAY_PORT_INPUT1) {
        DP1HPDOn();
    }
#endif
#if ENABLE_DP2_HPD == ON
    if (curr_interface == DISPLAY_PORT_INPUT2) {
        DP2HPDOn();
    }
#endif
#if ENABLE_DP3_HPD == ON
    if (curr_interface == DISPLAY_PORT_INPUT3) {
        DP3HPDOn();
    }
#endif
#if ENABLE_USB_TYPE_C == ON
    if ((GetCurrInputInterface() == USB_TYPE_C_INTERFACE) && IsUSBCCVBusAttach() && (SystemData.bPDdone == TRUE)) {
        USBCCConfigHPD(TRUE);
    }
#endif
}

/**************************************************************************//**
 * Pull low HDP pin.
 ******************************************************************************/
void SYSAPI_PerformHPDOff(UCHAR force)
{
    UCHAR curr_interface = GetCurrInputInterface();
    
    // We have to hide the SystemData variables in the future :)
        if (force == TRUE) {
#if ENABLE_DIGI0_HPD == ON
        #if (INPUT_INTERFACE&INPUT_MHL0)
            if ((MHL_Is_CDSense1_IO_HIGH()) == FALSE)
        #endif
            {
                Digi0HPDOff();
            }
#endif
#if ENABLE_DIGI1_HPD == ON
        #if (INPUT_INTERFACE&INPUT_MHL1)
            if ((MHL_Is_CDSense2_IO_HIGH()) == FALSE)
        #endif
            {
                Digi1HPDOff();
            }
#endif
#if ENABLE_DIGI2_HPD == ON
        #if (INPUT_INTERFACE&INPUT_MHL2)
            if ((MHL_Is_CDSense1_IO_HIGH()) == FALSE)
        #endif
            {
                Digi2HPDOff();
            }
#endif
#if ENABLE_DIGI3_HPD == ON
        #if (INPUT_INTERFACE&INPUT_MHL3)
            if ((MHL_Is_CDSense2_IO_HIGH()) == FALSE)
        #endif
            {
                Digi3HPDOff();
            }
#endif
#if ENABLE_DP_HPD == ON && ENABLE_USB_TYPE_C == OFF
            DPHPDOff();
#endif
#if ENABLE_DP1_HPD == ON
            DP1HPDOff();
#endif
#if ENABLE_DP2_HPD == ON
            DP2HPDOff();
#endif
#if ENABLE_DP3_HPD == ON
            DP3HPDOff();
#endif
#if ENABLE_USB_TYPE_C == ON
            if (IsUSBCCVBusAttach() && (SystemData.bPDdone == TRUE)) {
                USBCCConfigHPD(FALSE);
            }
#endif
            SetGlobalTimer(GLOBAL_TMR_HPD, HPD_LOW_PERIOD);
        }    
        else {
#if ENABLE_DIGI0_HPD == ON
            if ((curr_interface == DIGITAL_INPUT0) && IsDigital0Connect()) {
            #if (INPUT_INTERFACE&INPUT_MHL0)
                if ((MHL_Is_CDSense1_IO_HIGH()) == FALSE)
            #endif
                {
                    Digi0HPDOff();
                    SetGlobalTimer(GLOBAL_TMR_HPD, HPD_LOW_PERIOD);
                }
            }
#endif
#if ENABLE_DIGI1_HPD == ON
            if ((curr_interface == DIGITAL_INPUT1) && IsDigital1Connect()) {
            #if (INPUT_INTERFACE&INPUT_MHL1)
                if ((MHL_Is_CDSense2_IO_HIGH()) == FALSE)
            #endif
                {
                    Digi1HPDOff();            
                    SetGlobalTimer(GLOBAL_TMR_HPD, HPD_LOW_PERIOD);
                }
            }
#endif
#if ENABLE_DIGI2_HPD == ON
            if ((curr_interface == DIGITAL_INPUT2) && IsDigital2Connect()) {
            #if (INPUT_INTERFACE&INPUT_MHL2)
                if ((MHL_Is_CDSense1_IO_HIGH()) == FALSE)
            #endif
                {
                    Digi2HPDOff();
                    SetGlobalTimer(GLOBAL_TMR_HPD, HPD_LOW_PERIOD);
                }
            }
#endif
#if ENABLE_DIGI3_HPD == ON
            if ((curr_interface == DIGITAL_INPUT3) && IsDigital3Connect()) {
            #if (INPUT_INTERFACE&INPUT_MHL3)
                if ((MHL_Is_CDSense2_IO_HIGH()) == FALSE)
            #endif
                {
                    Digi3HPDOff();            
                    SetGlobalTimer(GLOBAL_TMR_HPD, HPD_LOW_PERIOD);
                }
            }
#endif
#if ENABLE_USB_TYPE_C == OFF
#if ENABLE_DP_HPD == ON
#if ENABLE_DP_ADV_HPD == ON
            if ((curr_interface == DISPLAY_PORT_INPUT) && IsDPConnect()) {
//                if ((IsDPTrainingDone() == FALSE) && (!IsZpMode())) {
                    DPHPDOff();
                    SetGlobalTimer(GLOBAL_TMR_HPD, DP_HPD_LOW_PERIOD);
//                }
            }
#endif
            if (UserData.bPowerStatus == OFF) {
                DPHPDOff();
                SetGlobalTimer(GLOBAL_TMR_HPD, DP_HPD_LOW_PERIOD);
            }
#endif
#endif
#if ENABLE_DP1_HPD == ON
#if ENABLE_DP1_ADV_HPD == ON
            if ((curr_interface == DISPLAY_PORT_INPUT1) && IsDP1Connect()) {
//                if ((IsDPTrainingDone() == FALSE) && (!IsZpMode())) {
                    DP1HPDOff();
                    SetGlobalTimer(GLOBAL_TMR_HPD, DP_HPD_LOW_PERIOD);
//                }
            }
#endif
            if (UserData.bPowerStatus == OFF) {
                DP1HPDOff();
                SetGlobalTimer(GLOBAL_TMR_HPD, DP_HPD_LOW_PERIOD);
            }
#endif
#if ENABLE_DP2_HPD == ON
#if ENABLE_DP2_ADV_HPD == ON
            if ((curr_interface == DISPLAY_PORT_INPUT2) && IsDP2Connect()) {
//                if ((IsDPTrainingDone() == FALSE) && (!IsZpMode())) {
                    DP2HPDOff();
                    SetGlobalTimer(GLOBAL_TMR_HPD, DP_HPD_LOW_PERIOD);
//                }
            }
#endif
            if (UserData.bPowerStatus == OFF) {
                DP2HPDOff();
                SetGlobalTimer(GLOBAL_TMR_HPD, DP_HPD_LOW_PERIOD);
            }
#endif
#if ENABLE_DP3_HPD == ON
#if ENABLE_DP3_ADV_HPD == ON
            if ((curr_interface == DISPLAY_PORT_INPUT3) && IsDP3Connect()) {
//                if ((IsDPTrainingDone() == FALSE) && (!IsZpMode())) {
                    DP3HPDOff();
                    SetGlobalTimer(GLOBAL_TMR_HPD, DP_HPD_LOW_PERIOD);
//                }
            }
#endif
            if (UserData.bPowerStatus == OFF) {
                DP3HPDOff();
                SetGlobalTimer(GLOBAL_TMR_HPD, DP_HPD_LOW_PERIOD);
            }
#endif
#if ENABLE_USB_TYPE_C == ON
            if ((GetCurrInputInterface() == USB_TYPE_C_INTERFACE) && IsUSBCCVBusAttach() && (SystemData.bPDdone == TRUE)) {
                USBCCConfigHPD(FALSE);
                SetGlobalTimer(GLOBAL_TMR_HPD, USBCC_HPD_LOW_PERIOD);
            }
#endif
       }
    }

#endif
