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

//******************************************************************************
// E X T E R N A L   V A R I A B L E   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// S T A T I C   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
static void CheckInvalidParameter(void);

//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// F U N C T I O N   B O D Y S
//******************************************************************************

/**************************************************************************//**
 * Setup capture window and post display.
 * @return TRUE if system can show image normally. FASLE if OOR happens.
 ******************************************************************************/
BOOL ModeConfig(void)
{
    BOOL result;
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1) || (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
    UCHAR currentinterface = GetCurrInputInterface();
#endif

    if (GetInputSyncMode() == DIG_SYNC) { //Digital input
        PowerDownAnalogInput();
        SetDVIPLL();
    #if (DVI_MODE==DVI_HV_MODE) || (DVI_MODE==DVI_HVDE_MODE)
        DVIAutoPosition();
    #endif
    #if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1) || (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
        // power off DP or Digital sync?
    // Sequence : Run DPConfigFIFO() after DVIAutoPosition() 
        if ((currentinterface == DISPLAY_PORT_INPUT) || (currentinterface == DISPLAY_PORT_INPUT1)
         || (currentinterface == DISPLAY_PORT_INPUT2) || (currentinterface == DISPLAY_PORT_INPUT3)) {
            PowerDownDigitalInput();
            DP_AudioMNCheckerInit();
#if IS_NT68810_SERIES || IS_NT68870_SERIES
            SC_DP_AUDIO_FIFO_CTRL |= BIT6;  // 0x1050
            usAudioMuteDelay = DP_AUDIODELAY;
        }
        else {
            SC_HDMI_MUTE |= BIT1; // 0x737
            usAudioMuteDelay = HDMI_AUDIODELAY;
#endif
        }
        //DPConfigFIFO();
        DPConfigCRC(); // CTS for Cut2/3 Use Only
    #endif
    #if ENABLE_HDMI == ON
        ClearHDMIStatus();
    #endif
#if ENABLE_NR_BYTIMING == ON    
        SetNRByDigitalTiming();
#endif
    }
    else { //Analog Input
        PowerDownDigitalInput();
#if IS_NT68810_SERIES || IS_NT68870_SERIES
        AphyPowerOff(FALSE);
#endif
        CheckInvalidParameter();
        SetADCPLL(InputTiming.usHTotal);
        SetADCPhase(InputTiming.ucPhase);
        SetNRByAnalogTiming();
        SetMinMax();
        SetHP(InputTiming.usHStart);
        SetVP(InputTiming.usVStart);
    }

#if ENABLE_OVERSCAN == ON
    CheckOverScan();
#else
    SetCaptureSize(InputTiming.usCapHActive, InputTiming.usCapVActive);
#endif
    SetHmask();

#if 0//ENABLE_SR == ON
    UserSetSR();
#endif

//#if !IS_NT68770_SERIES && !IS_NT68850_SERIES && !IS_NT68655_SERIES && !IS_NT68790_SERIES && !IS_NT68658_SERIES
#if IS_NT68770_SERIES_EARLIER || IS_NT68661_SERIES
    SetColorSpace();
#endif

    result = SetupDisplayTiming(InputTiming.usHTotal50);

#if ENABLE_SR == ON
    UserSetSR();
#endif

#if ENABLE_SCALER_3D == ON
    SC3DAPI_Setup3DMode();
#endif
#if ENABLE_AUTO_CONTROL == ON
    DisableDclkSSC();
#endif
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1) || (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
    // 0x1046 = 0x17, DPConfigFIFO() after SetupDisplayTiming()???
    if ((currentinterface == DISPLAY_PORT_INPUT) || (currentinterface == DISPLAY_PORT_INPUT1)
     || (currentinterface == DISPLAY_PORT_INPUT2) || (currentinterface == DISPLAY_PORT_INPUT3)) {
        DPConfigFIFO();
    }
#endif

    return result;
}
#if OSDTYPE == OSD_BENQ_V1 || OSDTYPE == OSD_BENQ_V2
BOOL IsHDMIVideoTiming(void)
{
    UCHAR CurrInSrc;

    CurrInSrc = UserGetInputSource();


#if (INPUT_INTERFACE&INPUT_MHL_MASK)
         if ( (GetInputSyncMode() == DIG_SYNC) && MHL_IsMHLInput() ) {
               return TRUE;
        }
#endif   

#if ENABLE_HDMI == ON //20130715_1006_SYS#6
    if((CurrInSrc == INPUT_SC_HDMI)||(CurrInSrc == INPUT_SC_HDMI1)||(CurrInSrc == INPUT_SC_HDMI2)||(CurrInSrc == INPUT_SC_HDMI3)) {
    if(IsHDMIVideo() && IsVideoTiming()){
        return TRUE;
    }
    }
#endif

    return FALSE;
}
#endif
BOOL IsNativeTiming(void)
{
#if 1
#if !lrd_dis_benq
    BOOL result;
	xdata InputTimingFormat *pthisInputTiming;
	pthisInputTiming = pInputTiming;
	pInputTiming = GetModeHandleInputTiming(_MainChannel);
    if (GetScalerSyncMode(_MainChannel) != DIG_SYNC) {
		result = BEST_RESOLUTION_VGA;
		pInputTiming = pthisInputTiming;
        return result;
    }
    else {
		result = BEST_RESOLUTION_DIG;
		pInputTiming = pthisInputTiming;
        return result;
    }
#else
    BOOL result;
    if(GetInputSyncMode() != DIG_SYNC)
        result = BEST_RESOLUTION_VGA;
    else  
        result = BEST_RESOLUTION_DIG;
    return result;
#endif
#else
    if (pInputTiming->usModeIndex == _2560X1440_60HZ) {
        return TRUE;
    }
    return FALSE;
#endif    
}

BOOL IsComponentTiming(void)
{
#if !lrd_dis_benq
    if  ((pInputTiming->usModeIndex == _720x480I_60HZ)  ||
        (pInputTiming->usModeIndex == _720x576I_50HZ)   ||
        (pInputTiming->usModeIndex == _640x480_60HZ)    ||         
        (pInputTiming->usModeIndex == _720x480P_60HZ)   ||
        (pInputTiming->usModeIndex == _720x576P_50HZ)   ||
        (pInputTiming->usModeIndex == _1280x720P_50HZ)  ||
        (pInputTiming->usModeIndex == _1280x720P_60HZ)  || 
        (pInputTiming->usModeIndex == _1920x1080I_50HZ) ||
        (pInputTiming->usModeIndex == _1920x1080I_60HZ) ||           
        (pInputTiming->usModeIndex == _1920x1080I_50HZ125)||
        (pInputTiming->usModeIndex == _1920x1080P_50HZ) ||   
        (pInputTiming->usModeIndex == _1920x1080P_60HZ))
#else
    if  ((InputTiming.usModeIndex == _720x480I_60HZ)  ||
        (InputTiming.usModeIndex == _720x576I_50HZ)   ||
        (InputTiming.usModeIndex == _640x480_60HZ)    ||         
        (InputTiming.usModeIndex == _720x480P_60HZ)   ||
        (InputTiming.usModeIndex == _720x576P_50HZ)   ||
        (InputTiming.usModeIndex == _1280x720P_50HZ)  ||
        (InputTiming.usModeIndex == _1920x1080I_50HZ) ||
        (InputTiming.usModeIndex == _1920x1080I_60HZ) ||           
        (InputTiming.usModeIndex == _1920x1080I_50HZ125)||
        (InputTiming.usModeIndex == _1920x1080P_50HZ) ||   
        (InputTiming.usModeIndex == _1920x1080P_60HZ))
#endif
    {
        return TRUE;
    }

    return FALSE;
}
BOOL IsComponentInput(void)
{
    UCHAR interface;
    interface = GetCurrInputInterface();
    if (IsComponentTiming()&&((interface == ANALOG_SOG_INPUT0)||(interface == ANALOG_SOG_INPUT1))) {
        return TRUE;
    }
    return FALSE;    
}


BOOL IsPreSetModeTiming(void)
{
#if !lrd_dis_benq
    if ((pInputTiming->usModeIndex == _640x350_70HZ)    ||
        (pInputTiming->usModeIndex == _640x480_60HZ)    ||        
        (pInputTiming->usModeIndex == _640x480_75HZ)    ||
        (pInputTiming->usModeIndex == _720x400_70HZ)    ||
        (pInputTiming->usModeIndex == _832x624_75HZ)    ||
        (pInputTiming->usModeIndex == _800x600_60HZ)    ||
        (pInputTiming->usModeIndex == _800x600_75HZ)    ||
        (pInputTiming->usModeIndex == _1024x576_60HZ)   ||
        (pInputTiming->usModeIndex == _1024x600_60HZ)   ||        
        (pInputTiming->usModeIndex == _1024x768_60HZ)   ||
        (pInputTiming->usModeIndex == _1024x768_75HZ)   ||
        (pInputTiming->usModeIndex == _1152x720_60HZ)   ||
        (pInputTiming->usModeIndex == _1152x864_75HZ)   ||
        (pInputTiming->usModeIndex == _1152x870_75HZ)   ||
        (pInputTiming->usModeIndex == _1152x900_66HZ)   ||
        (pInputTiming->usModeIndex == _1280x720_60HZ)   ||        
        (pInputTiming->usModeIndex == _1280x720P_60HZ)  ||                
        (pInputTiming->usModeIndex == _1280x720_75HZ)   ||
        (pInputTiming->usModeIndex == _1280x768_60HZ_RB) ||                
        (pInputTiming->usModeIndex == _1280x800_60HZ)   ||                
        (pInputTiming->usModeIndex == _1280x800_75HZ)   ||
        (pInputTiming->usModeIndex == _1280x960_60HZ)   ||
        (pInputTiming->usModeIndex == _1280x1024_60HZ)  ||
        (pInputTiming->usModeIndex == _1280x1024_75HZ)  ||
        (pInputTiming->usModeIndex == _1366x768_60HZ)   ||
        (pInputTiming->usModeIndex == _1360x768_60HZ)   ||
        (pInputTiming->usModeIndex == _1440x900_60HZ_RB) ||
        (pInputTiming->usModeIndex == _1440x900_60HZ)   ||
        (pInputTiming->usModeIndex == _1440x900_75HZ)   ||
        (pInputTiming->usModeIndex == _1600x900_60HZ_RB)||
        (pInputTiming->usModeIndex == _1600x1000_60HZ_RB)||
        (pInputTiming->usModeIndex == _1600x1200_60HZ)  ||
        (pInputTiming->usModeIndex == _1680x1050_60HZ)  ||
        (pInputTiming->usModeIndex == _1680x1050_75HZ)  ||
        (pInputTiming->usModeIndex == _1920x1080_60HZ_RB)||
        (pInputTiming->usModeIndex == _1920x1080_60HZ)  ||
        (pInputTiming->usModeIndex == _1920x1080P_60HZ) ||
        (pInputTiming->usModeIndex == _1920x1200_50HZ_RB)||        
        (pInputTiming->usModeIndex == _1920x1200_60HZ)  ||
        (pInputTiming->usModeIndex == _1920x1200_60HZ_RB)||
        (pInputTiming->usModeIndex == _1920x1200_60HZ_2)||
        (pInputTiming->usModeIndex == _2048x1280_60HZ_RB)||
        (pInputTiming->usModeIndex == _2560X1440_60HZ)) {
        return TRUE;
    }
    if (pInputTiming->usModeHActive == 1024 && pInputTiming->usModeVActive == 600 && (pInputTiming->usVSyncFreq >590 && pInputTiming->usVSyncFreq <610)) {
        return TRUE;
    }
    if (pInputTiming->usModeHActive == 1152 && pInputTiming->usModeVActive == 720 && (pInputTiming->usVSyncFreq >590 && pInputTiming->usVSyncFreq <610)) {
        return TRUE;
    }
    if(pInputTiming->usCapHActive == 1024 && pInputTiming->usCapVActive == 768 && pInputTiming->usVSyncFreq > 740 && pInputTiming->usVSyncFreq <760){
        return TRUE;
    }
    if(pInputTiming->usCapHActive == 1280 && pInputTiming->usCapVActive == 960 && pInputTiming->usVSyncFreq > 590 && pInputTiming->usVSyncFreq <610){
        return TRUE;
    }
    if(pInputTiming->usCapHActive == 1440 && pInputTiming->usCapVActive == 900 && pInputTiming->usVSyncFreq > 590 && pInputTiming->usVSyncFreq <610){
        return TRUE;
    }
    
    if(pInputTiming->usCapHActive == 2560 && pInputTiming->usCapVActive ==1440 && pInputTiming->usVSyncFreq > 590 && pInputTiming->usVSyncFreq <610){
        return TRUE;
    }
    if (IsComponentInput() == TRUE) {  //Input Component timing doesn't show Resnotice & non preset mode
        return TRUE;
    }
#else
    if ((InputTiming.usModeIndex == _640x350_70HZ)    ||
        (InputTiming.usModeIndex == _640x480_60HZ)    ||        
        (InputTiming.usModeIndex == _640x480_75HZ)    ||
        (InputTiming.usModeIndex == _720x400_70HZ)    ||
        (InputTiming.usModeIndex == _832x624_75HZ)    ||
        (InputTiming.usModeIndex == _800x600_60HZ)    ||
        (InputTiming.usModeIndex == _800x600_75HZ)    ||
        (InputTiming.usModeIndex == _1024x600_60HZ)   ||        
        (InputTiming.usModeIndex == _1024x768_60HZ)   ||
        (InputTiming.usModeIndex == _1024x768_75HZ)   ||
        (InputTiming.usModeIndex == _1152x720_60HZ)   ||
        (InputTiming.usModeIndex == _1152x864_75HZ)   ||
        (InputTiming.usModeIndex == _1152x870_75HZ)   ||
        (InputTiming.usModeIndex == _1152x900_66HZ)   ||
        (InputTiming.usModeIndex == _1280x720_60HZ)   ||        
        (InputTiming.usModeIndex == _1280x720_75HZ)   ||
        (InputTiming.usModeIndex == _1280x768_60HZ_RB) ||                
        (InputTiming.usModeIndex == _1280x800_60HZ)   ||                
        (InputTiming.usModeIndex == _1280x800_75HZ)   ||
        (InputTiming.usModeIndex == _1280x960_60HZ)   ||
        (InputTiming.usModeIndex == _1280x1024_60HZ)  ||
        (InputTiming.usModeIndex == _1280x1024_75HZ)  ||
        (InputTiming.usModeIndex == _1366x768_60HZ)   ||
        (InputTiming.usModeIndex == _1360x768_60HZ)   ||
        (InputTiming.usModeIndex == _1440x900_60HZ_RB) ||
        (InputTiming.usModeIndex == _1440x900_60HZ)   ||
        (InputTiming.usModeIndex == _1440x900_75HZ)   ||
        (InputTiming.usModeIndex == _1600x1000_60HZ_RB)||
        (InputTiming.usModeIndex == _1600x1200_60HZ)  ||
        (InputTiming.usModeIndex == _1680x1050_60HZ)  ||
        (InputTiming.usModeIndex == _1680x1050_75HZ)  ||
        (InputTiming.usModeIndex == _1920x1080_60HZ_RB)||
        (InputTiming.usModeIndex == _1920x1080_60HZ)  ||
        (InputTiming.usModeIndex == _1920x1080P_60HZ) ||
        (InputTiming.usModeIndex == _1920x1200_50HZ_RB)||        
        (InputTiming.usModeIndex == _1920x1200_60HZ)  ||
        (InputTiming.usModeIndex == _1920x1200_60HZ_RB)
    )
	{
        return TRUE;
    }
    if (InputTiming.usModeHActive == 1024 && InputTiming.usModeVActive == 600 && (InputTiming.usVSyncFreq >590 && InputTiming.usVSyncFreq <610)) {
        return TRUE;
    }
    if (InputTiming.usModeHActive == 1152 && InputTiming.usModeVActive == 720 && (InputTiming.usVSyncFreq >590 && InputTiming.usVSyncFreq <610)) {
        return TRUE;
    }
    if(InputTiming.usCapHActive == 1024 && InputTiming.usCapVActive == 768 && InputTiming.usVSyncFreq > 740 && InputTiming.usVSyncFreq <760){
        return TRUE;
    }
    if(InputTiming.usCapHActive == 1280 && InputTiming.usCapVActive == 960 && InputTiming.usVSyncFreq > 590 && InputTiming.usVSyncFreq <610){
        return TRUE;
    }
    if(InputTiming.usCapHActive == 1440 && InputTiming.usCapVActive == 900 && InputTiming.usVSyncFreq > 590 && InputTiming.usVSyncFreq <610){
        return TRUE;
    }
    
    if(InputTiming.usCapHActive == 2560 && InputTiming.usCapVActive ==1440 && InputTiming.usVSyncFreq > 590 && InputTiming.usVSyncFreq <610){
        return TRUE;
    }
    if (IsComponentInput() == TRUE) {  //Input Component timing doesn't show Resnotice & non preset mode
        return TRUE;
    }
#endif
    return FALSE;
}
/**************************************************************************//**
 * Determine current input timing is video timing or not.
 * @return TRUE if input timing is video timing else FALSE.
 ******************************************************************************/
#if (!defined(ENABLE_FPGA_MODE))
BOOL IsVideoTiming(void)
{

#if (INPUT_INTERFACE&INPUT_MHL_MASK) 
     if ( (GetInputSyncMode() == DIG_SYNC) && MHL_IsMHLInput() ) {
           return TRUE;
    }
#endif   
   
    if ((InputTiming.usModeIndex == _720x480I_60HZ)   ||
        (InputTiming.usModeIndex == _1440x480I_60HZ)  ||
        (InputTiming.usModeIndex == _2880x480I_60HZ)  ||
        (InputTiming.usModeIndex == _720x480P_60HZ)   ||
        (InputTiming.usModeIndex == _720x576I_50HZ)   ||
        (InputTiming.usModeIndex == _1440x576I_50HZ)  ||
        (InputTiming.usModeIndex == _2880x576I_50HZ)  ||
        (InputTiming.usModeIndex == _720x576P_50HZ)   ||
        (InputTiming.usModeIndex == _1280x720P_50HZ)  ||
        (InputTiming.usModeIndex == _1280x720_60HZ)   ||
        (InputTiming.usModeIndex == _1920x1080P_60HZ) ||
        (InputTiming.usModeIndex == _1920x1080P_50HZ) ||
        (InputTiming.usModeIndex == _1920x1080I_50HZ) ||
        (InputTiming.usModeIndex == _1920x1080I_50HZ_RB)) {
        return TRUE;
    }

    return FALSE;
}
#endif

/**************************************************************************//**
 * Determine current input timing is "Out Of Range" or not.
 * @return TRUE if input timing is OOR else FALSE.
 ******************************************************************************/
BOOL IsOutOfRange(void)
{
#if (!defined(ENABLE_FPGA_MODE))
#if ENABLE_SCALER_3D == ON
    if (SC3DAPI_IsHDMI3DMode()) {
        return FALSE;
    }
#endif
#if ENABLE_DVI_DUAL_LINK == ON
    if (TMDS_IsDualLink()) {
        return FALSE;
    }
#endif

    if (IsVideoTiming()) {
        return FALSE;
    }

    //Check HSync Frequency
    if (InputTiming.usHSyncFreq < MIN_H_FREQ) {
        return TRUE;
    }
    if (InputTiming.usHSyncFreq > MAX_H_FREQ) {
        return TRUE;
    }
    //Check VSync Frequency
    if (InputTiming.usVSyncFreq < MIN_V_FREQ) {
        return TRUE;
    }
    if (InputTiming.usVSyncFreq > MAX_V_FREQ) {
        return TRUE;
    }
    //Check ADC clock frequency
    if (GetInputSyncMode() != DIG_SYNC) {
        if (CheckADCPLLOutOfRange(InputTiming.usHTotal) == TRUE) {
            return TRUE;
        }
    }
#endif
    return FALSE;
}

/**************************************************************************//**
 * Define the minimum and maximum value of HTotal, HStart and VStart
 ******************************************************************************/
void SetMinMax(void)
{
    USHRT temp;

    temp = InputTiming.usHTotal50 > 50 ? 50 : InputTiming.usHTotal50;
    InputTiming.usHTotalMin = InputTiming.usHTotal50 - temp;
    InputTiming.usHTotalMax = InputTiming.usHTotal50 + temp;

    temp = InputTiming.usHStart50 > 50 ? 50 : InputTiming.usHStart50;
    InputTiming.usHStartMin = InputTiming.usHStart50 - temp;
    InputTiming.usHStartMax = InputTiming.usHStart50 + temp;

    temp = InputTiming.usVStart50 > 20 ? 20 : InputTiming.usVStart50-1;
    InputTiming.usVStartMin = InputTiming.usVStart50 - temp;
    InputTiming.usVStartMax = InputTiming.usVStart50 + temp;
}

/**************************************************************************//**
 * Verify the present HTotal, HStart and VStart.
 * The criteria is
 *   If HTotal > 2*HActive, HTotal is invalid and HTotal = HActive * 3 / 2.
 *   If HStart > 0.5*HTotal, HStart is invalid and HStart = (HTotal - HActive) / 2.
 *   If VStart > 0.5*VTotal, VStart is invalid and VStart = (VTotal - VActive) / 2.
 ******************************************************************************/
void CheckInvalidParameter(void)
{
    USHRT temp;
    temp = InputTiming.usCapHActive << 1;
    if (InputTiming.usHTotal > temp) {
        temp = InputTiming.usCapHActive >> 1;
        InputTiming.usHTotal = InputTiming.usCapHActive + temp;
    }
    temp = InputTiming.usHTotal >> 1;
    if (InputTiming.usHStart > temp) {
        InputTiming.usHStart = (InputTiming.usHTotal - InputTiming.usCapHActive) / 2;
    }
    temp = InputTiming.usVTotal >> 1;
    if (InputTiming.usVStart > temp) {
        InputTiming.usVStart = (InputTiming.usVTotal - InputTiming.usCapVActive) / 2;
    }
}

#if ENABLE_OVERSCAN == ON
/**************************************************************************//**
 * Perform over-scan with some conditions.
 ******************************************************************************/
#if !lrd_dis
void CheckOverScan(void)
{
#if ((ENABLE_HDMI == ON) && !((INPUT_INTERFACE&INPUT_DP)||(INPUT_INTERFACE&INPUT_DP)))
    if ((GetInputSyncMode() == DIG_SYNC) && IsHDMIVideo() && IsOverScan())
#else
    if ((GetInputSyncMode() == DIG_SYNC) && IsOverScan())
#endif
    {
        SetOverScanRatio(OVER_SCAN_RATIO);
    }
    else{
        SetOverScanRatio(0);
    }
}
#else
void SetHSVSOffset(USHRT modeIndex)
 {
        
    switch (modeIndex){
        case _1920x1080P_60HZ:
            (InputTiming.usHStart) = (InputTiming.usHStart)+47;;  //OK           
            break;
        case _1920x1080P_50HZ:
            (InputTiming.usHStart) = (InputTiming.usHStart)+45;;  //OK             

            break;            
        case _1920x1080I_60HZ:
            (InputTiming.usHStart) = (InputTiming.usHStart)+44;  //OK             
            //(InputTiming.usVStart) = (InputTiming.usVStart)-1;            
            break;            
        case _1920x1080I_50HZ:
            (InputTiming.usHStart) = (InputTiming.usHStart)+44;  //OK             
            //(InputTiming.usVStart) = (InputTiming.usVStart)-1;            
            break;
       // case _1280x720P_60HZ:
       //     (InputTiming.usHStart) = (InputTiming.usHStart)+40;  //OK           
            break;
        case _1280x720P_50HZ:
            (InputTiming.usHStart) = (InputTiming.usHStart)+40; //OK
            break;      
        case _720x576P_50HZ:
            (InputTiming.usHStart) = (InputTiming.usHStart)+1; //OK

            break;      
        case _720x576I_50HZ:         
            //(InputTiming.usVStart) = (InputTiming.usVStart)+2;   //OK

            break;                        
        case _720x480P_60HZ:
            (InputTiming.usHStart) = (InputTiming.usHStart)-1;      //V up  down  
            //(InputTiming.usVStart) = (InputTiming.usVStart)+1;
            break;
        case _720x480I_60HZ:
            (InputTiming.usHStart) = (InputTiming.usHStart)+2; //V up down
            (InputTiming.usVStart) = (InputTiming.usVStart)-1;  
            if ((SC_GI_SYNC_CTRL3 & BIT0) == 0x00) {
                SC_GI_SYNC_CTRL3 |= BIT0;
            }
            SC_GPORT_CTRL |= BIT6;
            break;
        default:
            break;
     }
    //printf("Offset HS %d VS %d\r\n",(InputTiming.usHStart),(InputTiming.usVStart));
 }

void SetVGAOverScanRatio(UCHAR ratio)
{
    USHRT hstart, vstart;

    if (ratio != 0) { //On
        hstart = InputTiming.usModeHActive * ratio / 100 / 2;
        InputTiming.usHStart = hstart + InputTiming.usHStart50;
        InputTiming.usCapHActive = InputTiming.usModeHActive - hstart * 2;
        InputTiming.usCapHActive &= 0xFFFE;

        vstart = InputTiming.usModeVActive * ratio / 100 / 2;
        InputTiming.usVStart = vstart + InputTiming.usVStart50;
        if (IsInterlaced() == TRUE) {
            InputTiming.usCapVActive = InputTiming.usModeVActive - vstart * 4;
        }
        else {
            InputTiming.usCapVActive = InputTiming.usModeVActive - vstart * 2;
        }
        
        //For YPbPr
        {
            SetHSVSOffset((InputTiming.usModeIndex));
        }
      
        SetCaptureSize(InputTiming.usCapHActive, InputTiming.usCapVActive);
        SetHP(InputTiming.usHStart);
        SetVP(InputTiming.usVStart);
        DelayVTime(2);
    }
    else { //Off
     InputTiming.usCapHActive = InputTiming.usModeHActive;
     InputTiming.usCapVActive = InputTiming.usModeVActive;
        InputTiming.usHStart = InputTiming.usHStart50;
        InputTiming.usVStart = InputTiming.usVStart50;

        //For YPbPr
        {
            //printf("Modeconfig HS %d VS %d\r\n",(InputTiming.usHStart),(InputTiming.usVStart));
            //printf("modeindex %x\r\n\n",(InputTiming.usModeIndex));  
            SetHSVSOffset((InputTiming.usModeIndex));
        }
        //
        
        SetCaptureSize(InputTiming.usCapHActive, InputTiming.usCapVActive);        
        SetHP(InputTiming.usHStart);
        SetVP(InputTiming.usVStart);
        DelayVTime(2);        
    }
}

BOOL IsOverScan(void)
{
    if(IsComponentInput()){
        return UserData.bSOGOverScan;
    }
    else{
        return UserData.bOverScan;
    }
}

void CheckOverScan(void)
{
#if ((ENABLE_HDMI == ON) && !(INPUT_INTERFACE&INPUT_DP_MASK))
    if ((GetInputSyncMode() == DIG_SYNC) && IsHDMIVideo() && IsOverScan())
#else
    //    if (((GetInputSyncMode() == DIG_SYNC)||((GetInputSyncMode() == SOG_SYNC)&&IsComponentTiming()))&& IsOverScan())
    if ((GetInputSyncMode() == DIG_SYNC || IsComponentInput())&& IsOverScan())
#endif
    {
#if ENABLE_PIP == ON
        if (GetChannelIndex() == _PIPChannel) {
            SetOverScanRatio(0);
        }
        else
#endif
        {
            if ((GetCurrInputInterface() == DISPLAY_PORT_INPUT)||(GetCurrInputInterface() == DISPLAY_PORT_INPUT1)) {//DP
            //SetOverScanRatio(OVER_SCAN_RATIO);
                SetOverScanRatio(0);                        
            }
            else if (IsComponentInput()) {//Ypbpr
                SetVGAOverScanRatio(OVER_SCAN_RATIO);
            }            
            else {
                if (IsHDMI()) {//HDMI
                    SetOverScanRatio(OVER_SCAN_RATIO);             
                }
                else {//TMDS wihtout info frame
                    SetOverScanRatio(0);
                }
            }
        }
    }
    else {
        if (IsComponentInput()) {
            SetVGAOverScanRatio(0);
        }
        else {
            SetOverScanRatio(0);
        }
    }
}

#endif

/**************************************************************************//**
 * Update capture-related parameters.
 ******************************************************************************/
static void UpdateCaptureInfo(void)
{
    USHRT vactive = GetDigInputVActive();
    if (IsInterlaced()) {
        vactive = vactive * 2;
    }

    InputTiming.usModeHActive = GetDigInputHActive();
    InputTiming.usModeVActive = vactive;
    InputTiming.usCapHActive = InputTiming.usModeHActive;
    InputTiming.usCapVActive = InputTiming.usModeVActive;
    InputTiming.usHStart = GetInputHStart();
    InputTiming.usVStart = GetInputVStart();
    InputTiming.usHStart50 = InputTiming.usHStart;
    InputTiming.usVStart50 = InputTiming.usVStart;
}

/**************************************************************************//**
 * Perform over-scan.
 * Over-scan procedures must follow the following steps.
 *   1. Disable over-scan.
 *   2. Set capture window.
 *   3. Wait for a VSync duty (20ms).
 *   4. Enable over-scan.
 * @param ratio Over-scan ratio.
 ******************************************************************************/
void SetOverScanRatio(UCHAR ratio)
{
    USHRT hstart, vstart;

    if (ratio != 0) { //On
        DisableOverSample();
        DVIAutoPosition();
        UpdateCaptureInfo();
        hstart = InputTiming.usCapHActive * ratio / 100 / 2;
        vstart = InputTiming.usCapVActive * ratio / 100 / 2;
        InputTiming.usHStart = hstart;
        InputTiming.usCapHActive = InputTiming.usCapHActive - hstart * 2;
        InputTiming.usCapHActive &= 0xFFFE;
        InputTiming.usVStart = GetInputVStart();
#if NEW_OVS_MODE == ON
        WriteShortScaler(&SC_NEW_OVS_VBEG_LO, vstart);//new mode
        SC_OVERSCAN_MODE |= BIT7;
#else
        InputTiming.usVStart += vstart;
#endif
        if (IsInterlaced() == TRUE) {
            InputTiming.usCapVActive = InputTiming.usCapVActive - vstart * 4;
        }
        else {
            InputTiming.usCapVActive = InputTiming.usCapVActive - vstart * 2;
        }
        SetHP(InputTiming.usHStart);
        SetVP(InputTiming.usVStart);
        SetCaptureSize(InputTiming.usCapHActive, InputTiming.usCapVActive);
        DelayVTime(2);
        EnableOverSample();
    }
    else { //Off
#if NEW_OVS_MODE == ON
        SC_OVERSCAN_MODE &= ~BIT7;
#endif
        if (IsOverSample() == TRUE) {
            DisableOverSample();
            DVIAutoPosition();
            UpdateCaptureInfo();
        }
        SetCaptureSize(InputTiming.usCapHActive, InputTiming.usCapVActive);
    }
}


#endif
//******************************************************************************
// Prototype:
//  BOOL CheckVSyncWidthChange(void)
// Parameters:
//  None
// Return:
//  TRUE/FALSE
// Purpose:
//  Check Vsync width change
// Notes:
//  v31_1106221_2200_SYS#2
//******************************************************************************
/*
BOOL CheckVSyncWidthChange(void)
{
#define VS_WID_DIFF_CNT 4

    UCHAR uctemp_Vs_wid;
    if (GetModeHandleState() == WAIT_MODE_CHANGE) {
        if (((InputTiming.usModeHActive == 1360) ||(InputTiming.usModeHActive == 1366)) && (InputTiming.usModeVActive == 768)) { //v31_110627_2225_SYS#7
            uctemp_Vs_wid = GetInputVSyncWidth();
            if (uctemp_Vs_wid != Custom_System.ucVs_wid) {
                Custom_System.ucVs_wid_diff_cnt ++;
            }
            else {
                Custom_System.ucVs_wid_diff_cnt = 0;
            }
            if ( Custom_System.ucVs_wid_diff_cnt > VS_WID_DIFF_CNT) {
                return TRUE;
            }
        }
    }
    return FALSE;
}
*/



BOOL isOnlyFullAspectRatio(void)
{
#if !lrd_dis_benq
    if (pInputTiming->usModeHActive == PANEL_WIDTH && pInputTiming->usModeVActive == PANEL_HEIGHT) {
#else
	if (InputTiming.usModeHActive == PANEL_WIDTH && InputTiming.usModeVActive == PANEL_HEIGHT) {
#endif
        if (DetectAspectRatio() == DSP_SIZE_FULL){
            return TRUE;
        }
        else{
            return FALSE;
        }
    }
    else{
        return FALSE;
    }
}

UCHAR DetectAspectRatio(void)
{
    enum DisplayRatio
    {
        _Aspect_5_4 = 125,
        _Aspect_4_3 = 133,
        _Aspect_3_2 = 150,
        _Aspect_16_10 = 160,
        _Aspect_16_9 = 177
    };

    UCHAR Ratio;
    if ((GetCurrInputInterface() == DISPLAY_PORT_INPUT)||(GetCurrInputInterface() == DISPLAY_PORT_INPUT1)) {
                 if (IsInterlaced() == TRUE) {
                Ratio =  (ULONG)GetDPInputHDEImmediate()*100 / (GetDPInputVDEImmediate()*2);     
                }
                else{
        Ratio =  (ULONG)GetDPInputHDEImmediate()*100 / GetDPInputVDEImmediate();     
                }
        //printf("(%d,%d)\r\n",(USHRT)GetDPInputHDEImmediate(),(USHRT) GetDPInputVDEImmediate());                    
    }
    else { 
		#if !lrd_dis_benq
        pInputTiming = GetModeHandleInputTiming(_MainChannel);
		#endif
		#if !lrd_dis_benq		
        Ratio = (ULONG)pInputTiming->usModeHActive*100/pInputTiming->usModeVActive;
		#else
        Ratio = (ULONG)InputTiming.usModeHActive*100/InputTiming.usModeVActive;
		#endif
        //printf("(%d,%d)\r\n",(USHRT)pInputTiming->usModeHActive,(USHRT)pInputTiming->usModeVActive);            
    }    
    switch(Ratio) {
        case _Aspect_5_4:
        case _Aspect_4_3:
        case _Aspect_3_2:
#if ENABLE_ASPECT_16_10_AS_4_3 == ON
        case _Aspect_16_10:
#endif
            Ratio = DSP_SIZE_43;
            break;
        default:
#if ENABLE_ASPECT_16_10_AS_4_3 == OFF
        case _Aspect_16_10:
#endif          
        case _Aspect_16_9:
            Ratio = DSP_SIZE_FULL;
            break;
    }
    //printf("DetectAspectRatio=%d\r\n",(USHRT)Ratio);
    return Ratio;
}
