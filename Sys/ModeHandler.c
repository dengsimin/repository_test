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
enum {
    MODE_HDLR_FLAG_HOLD_DISPLAY  = 0x01 /*!< Flag of holding mode handler. */
};

/*!
 * Check the flag of holding mode handler.
 */
#define IsModeHdlrHold() ((ucModeHdlrFlag&MODE_HDLR_FLAG_HOLD_DISPLAY) != 0)
/*!
 * Set the flag of holding mode handler.
 */
#define SetModeHdlrHoldFlag() {ucModeHdlrFlag |= MODE_HDLR_FLAG_HOLD_DISPLAY;}
/*!
 * Clear the flag of holding mode handler.
 */
#define ClearModeHdlrHoldFlag() {ucModeHdlrFlag &= ~MODE_HDLR_FLAG_HOLD_DISPLAY;}

//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************
static xdata UCHAR ucModeHdlrFlag = 0x00;
static xdata UCHAR ucModeHdlrState = WAIT_SYNC_STABLE;
static xdata USHRT usSyncStableTimer;
static xdata UCHAR pre_sync_mode = NO_SYNC;

//******************************************************************************
// E X T E R N A L   V A R I A B L E   P R O T O T Y P E S
//******************************************************************************
extern xdata UCHAR ucInputSyncMode;

//******************************************************************************
// S T A T I C   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
static void GetInputTiming(void);
static void ClearInputTiming(void);
static void ModeHandlePowerUp(void);

//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// F U N C T I O N   B O D Y S
//******************************************************************************

/**************************************************************************//**
 * Mode handler.
 ******************************************************************************/
void ModeHandler(void)
{
    if (ucModeHdlrState != SOFT_POWER_OFF) {
        SyncHandler(); //Update ucInputSyncMode
    }

    switch (ucModeHdlrState) {
        case WAIT_MODE_CHANGE:
            switch (ucInputSyncMode) {
                case NO_SYNC:
                case NO_CABLE:
                    ucModeHdlrState = WAIT_SYNC_STABLE;
                    pre_sync_mode = ucInputSyncMode;
                    usSyncStableTimer = GetTimerTick();
                    ClearInputTiming();
                    break;
                case OUT_SYNC:
            #if ENABLE_HDMI == ON
                case DIG_SYNC:
                    HdmiHandler();
                    // Attention! There must be "No break" here.
            #endif
                default:
            #if ENABLE_MMU_ERR_RCVY == ON
                    MMUErrCorrection();
            #endif
            #if ENABLE_OD_MOTION_CHK == ON
                    ODAPI_MotionCheck();
            #endif
            #if (ENABLE_SCALER_3D == ON) && (ENABLE_DVI_DUAL_LINK == ON)
                // Force mode changing when source switches the 120Hz 2D timing to 120Hz 3D timing
                // Jude 2011/08/25
                if (DetectAMD3DModeChange()) {
                    SetModeChangeFlag();
                }
            #endif
#if ENABLE_FREESYNC_DEMO == ON
                    if (bFreeSyncMode != IsFreeSyncMode()) {
                        ucModeHdlrState = WAIT_SYNC_STABLE;
                        pre_sync_mode = ucInputSyncMode;
                        usSyncStableTimer = GetTimerTick();
                    }
#endif
                    break;
            }
            break;

        case WAIT_SYNC_STABLE:
            if (pre_sync_mode != ucInputSyncMode) { //Mode changed
                pre_sync_mode = ucInputSyncMode;
                usSyncStableTimer = GetTimerTick();
            }
            else { //Mode does not change
                switch (ucInputSyncMode) {
                    case SEP_SYNC:
                    case COM_SYNC:
                    case SOG_SYNC:
                    case DIG_SYNC:
                    case OUT_SYNC:
                        if ((GetTimerTick()-usSyncStableTimer) > SYNC_STABLE_TIME) {
							ucModeHdlrState = SYNC_IS_STABLE;						
                        }
                        break;
    
                    default:
                        break;
                }
            }
            break;

        case SYNC_IS_STABLE:
            if (IsModeHdlrHold()) break;
            GetInputTiming();
            switch (ucInputSyncMode) {
                case SEP_SYNC:
                case COM_SYNC:
                case SOG_SYNC:
                case DIG_SYNC:
                    ModeSearch();
                    if (IsOutOfRange() == TRUE) {
                        ucInputSyncMode = OUT_SYNC;
                    }
                    else {
                        if (ModeConfig() == TRUE) {
                            NormalDisplay();
                        }
                        else {
                            ucInputSyncMode = OUT_SYNC;
                        }
                    }
                    ucModeHdlrState = WAIT_DISPLAY_READY;
                    break;

                case NO_SYNC:
                case NO_CABLE:
                    ucModeHdlrState = WAIT_SYNC_STABLE;
                    pre_sync_mode = ucInputSyncMode;
                    usSyncStableTimer = GetTimerTick();
                    break;

                case OUT_SYNC:
                    ucModeHdlrState = WAIT_DISPLAY_READY;
                    break;

                default:
                    break;
            }
            break;

        case WAIT_DISPLAY_READY:
            switch (ucInputSyncMode) {
                case NO_SYNC:
                case NO_CABLE:
                    ucModeHdlrState = WAIT_SYNC_STABLE;
                    pre_sync_mode = ucInputSyncMode;
                    usSyncStableTimer = GetTimerTick();
                    break;

                case SEP_SYNC:
                case COM_SYNC:
                case SOG_SYNC:
                    ucModeHdlrState = WAIT_MODE_CHANGE;
                    PanelPowerOnSequence(FALSE);
                    DisplayNormalImage();
                    break;

                case DIG_SYNC:
                #if ENABLE_HDMI == ON
                    HdmiHandler();
                    // Check HDMI is in mute/unexpect state or not
                    // If it is true, restart sync stable state
                    if (IsHDMIDataMute()) {
                        ucModeHdlrState = WAIT_SYNC_STABLE;
                        usSyncStableTimer = GetTimerTick();
                        break;
                    }
                    // If input is DVI, we turn off the preamble detection
                    // to avoid sync un-stable issue when input source is AMD 3D signal
                    HDMIEnablePreambleDetection(IsHDMI());
                    #if 0
                    // If input is HDMI, we turn on AVMute interrupt to avoid green screen issue
                    // over some specific DVD/PatternGen when HDMI timing changed.
                    //HDMIEnableAVMuteInt(IsHDMI());
                    #endif
                #endif
                    ucModeHdlrState = WAIT_MODE_CHANGE;
                    PanelPowerOnSequence(FALSE);
                    DisplayNormalImage();
                    break;

                case OUT_SYNC:
                #if ENABLE_HDMI == ON
                    HdmiHandler();
                #endif
                    ucModeHdlrState = WAIT_MODE_CHANGE;
                    break;
                default:
                    break;
            }
            break;

        case POWER_SAVING_MODE:
            if (pre_sync_mode != ucInputSyncMode) { //Mode changed
                SYSAPI_WakeUp();
            }
            break;

        case SOFT_POWER_ON:
            ModeHandlePowerUp();
            break;

        case SOFT_POWER_OFF:
            break;

        default:
            break;
    }

#if ENABLE_LOW_PWR_MODE == ON
    McuClkDivderCheck();
#endif
}

/**************************************************************************//**
 * Get current input timing from scaler and assign the timing to InputTiming.
 ******************************************************************************/
static void GetInputTiming(void)
{
    if ((ucInputSyncMode != NO_SYNC) && (ucInputSyncMode != NO_CABLE)) {
        InputTiming.usHSyncFreq = GetInputHFreq();
        InputTiming.usVSyncFreq = GetInputVFreq();
        InputTiming.ucHSyncWidth = GetInputHSyncWidth();
        InputTiming.ucVSyncWidth = GetInputVSyncWidth();
        InputTiming.ucHVPolarity = GetInputHVPolarity();
        InputTiming.usVTotal = GetInputVTotal();
    }
}

/**************************************************************************//**
 * Clear InputTiming.
 ******************************************************************************/
static void ClearInputTiming(void)
{
    InputTiming.usHSyncFreq = 0;
    InputTiming.usVSyncFreq = 0;
    InputTiming.ucHSyncWidth = 0;
    InputTiming.ucVSyncWidth = 0;
    InputTiming.ucHVPolarity = 0;
    InputTiming.usVTotal = 0;
}

/**************************************************************************//**
 * Change the state to POWER_SAVING_MODE.
 ******************************************************************************/
void ModeHandlePowerSaving(void)
{
    ucModeHdlrState = POWER_SAVING_MODE;
    pre_sync_mode = ucInputSyncMode;
}

/**************************************************************************//**
 * Change the state to WAIT_SYNC_STABLE.
 ******************************************************************************/
static void ModeHandlePowerUp(void)
{
    pre_sync_mode = ucInputSyncMode;
    ucModeHdlrState = WAIT_SYNC_STABLE;
    usSyncStableTimer = GetTimerTick();
}

/**************************************************************************//**
 * Change the state to SOFT_POWER_ON.
 ******************************************************************************/
void ModeHandleSoftPowerOn(void)
{
    ucModeHdlrState = SOFT_POWER_ON;
}

/**************************************************************************//**
 * Change the state to SOFT_POWER_OFF.
 ******************************************************************************/
void ModeHandleSoftPowerOff(void)
{
    ucModeHdlrState = SOFT_POWER_OFF;

    // Clear Mode Handler Configuration Flags
    ClearModeHdlrHoldFlag();
}

/**************************************************************************//**
 * Get the current state.
 ******************************************************************************/
UCHAR GetModeHandleState(void)
{
    return ucModeHdlrState;
}

/**************************************************************************//**
 * Hold the mode handler at SYNC_IS_STABLE state.
 ******************************************************************************/
void HoldModeDisplay(void)
{
    SetModeHdlrHoldFlag();
}

/**************************************************************************//**
 * Release the mode handler and continue the mode detection.
 ******************************************************************************/
void ContinueModeDisplay(void)
{
    ClearModeHdlrHoldFlag();
}
