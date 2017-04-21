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
#define SYNC_CHANGE_CNT     10

//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************
xdata UCHAR ucInputSyncMode = SEP_SYNC;

code UCHAR SyncSrcTbl[] = {
#if (INPUT_INTERFACE&INPUT_VGA1)
    ANALOG_SEP_INPUT1,
    ANALOG_COM_INPUT1,
    ANALOG_SOG_INPUT1,
#endif
#if (INPUT_INTERFACE&INPUT_VGA0)
    ANALOG_SEP_INPUT0,
    ANALOG_COM_INPUT0,
    ANALOG_SOG_INPUT0,
#endif
#if (INPUT_INTERFACE&INPUT_DIG3)
    DIGITAL_INPUT3,
#endif
#if (INPUT_INTERFACE&INPUT_DIG2)
    DIGITAL_INPUT2,
#endif
#if (INPUT_INTERFACE&INPUT_DIG1)
    DIGITAL_INPUT1,
#endif
#if (INPUT_INTERFACE&INPUT_DIG0)
    DIGITAL_INPUT0,
#endif
#if (INPUT_INTERFACE&INPUT_YPbPr1)
    ANALOG_YPBPR_INPUT1,
#endif
#if (INPUT_INTERFACE&INPUT_YPbPr0)
    ANALOG_YPBPR_INPUT0,
#endif
#if (INPUT_INTERFACE&INPUT_DP)
    DISPLAY_PORT_INPUT,
#endif
#if (INPUT_INTERFACE&INPUT_DP1)
    DISPLAY_PORT_INPUT1,
#endif
#if (INPUT_INTERFACE&INPUT_DP2)
    DISPLAY_PORT_INPUT2,
#endif
#if (INPUT_INTERFACE&INPUT_DP3)
    DISPLAY_PORT_INPUT3,
#endif
};

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************
static xdata UCHAR ucSyncHdlrState = SEP_SYNC; //Sync handler state
static xdata UCHAR ucSyncSrcIdx = 0; //Sync source table index
static xdata UCHAR ucSyncChangeCnt = SYNC_CHANGE_CNT; //Mode change delay
static xdata USHRT usPortTimer_1ms = 0; //Port delay when changing input port
static BOOL bManualSyncSource = FALSE; //Make SyncSource searching input sync automatically or manually
static xdata USHRT usTimerTickTemp = 0;
static xdata USHRT usTMDSClock = 0;
static xdata USHRT usTMDSHrtlDE = 0;
static xdata USHRT usTMDSVrtlDE = 0;
#if ENABLE_HDMI == ON
static xdata USHRT usTMDSHtotal = 0;
static xdata USHRT usTMDSVtotal = 0;
#endif
static xdata UCHAR ucRecordSyncSrcIdx = 0xFF; //Sync source table index

//******************************************************************************
// E X T E R N A L   V A R I A B L E   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// S T A T I C   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
static UCHAR SyncSource(void);
static void SetModeChanged(void);
static UCHAR GetSameInput(void);
static UCHAR GetNextInput(void);
static void UpdateSyncSrcIdx(void);
static USHRT GetSyncSourceTimer(void);

//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// F U N C T I O N   B O D Y S
//******************************************************************************

//******************************************************************************
// Prototype: 
//  void SyncHandler(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Handle input sync
// Notes:
//  None
//******************************************************************************
void SyncHandler(void)
{
    switch (ucSyncHdlrState) {
        case NO_SYNC:
        case NO_CABLE:
        case UNKNOWN_SYNC:
            ucSyncHdlrState = SyncSource();
            ucInputSyncMode = ucSyncHdlrState;
            usTMDSClock = TMDS_GetClock();

            // The following "get DE" function must be after SyncSource!
            // Because of some TMDS setting in SyncSource may affect HDE/VDE value and will cause infinitely mode changed.
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1) || (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
            if ((GetCurrInputInterface() == DISPLAY_PORT_INPUT) || (GetCurrInputInterface() == DISPLAY_PORT_INPUT1)
             || (GetCurrInputInterface() == DISPLAY_PORT_INPUT2) || (GetCurrInputInterface() == DISPLAY_PORT_INPUT3)) {
                usTMDSHrtlDE = GetDPInputHDEImmediate();
                usTMDSVrtlDE = GetDPInputVDEImmediate();
            }
            else
#endif
            {
        #if ENABLE_HDMI == ON
                usTMDSHtotal = GetDigInputHTotalImmediate();
                usTMDSVtotal = GetDigInputVTotalImmediate();
        #endif
                usTMDSHrtlDE = GetDigInputHActiveImmediate();
                usTMDSVrtlDE = GetDigInputVActiveImmediate();
            }
            break;

        case SEP_SYNC:
        case COM_SYNC:
        case SOG_SYNC:
        case DIG_SYNC:
            if (CheckModeChange() == TRUE) { 
				McuScalerIntDisable();
    			AudioMuteOn();//lrd add 
                SetModeChanged();
            }
            break;

        default:
            break;
    }
}

//******************************************************************************
// Prototype: 
//  static BOOL CheckModeChange(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Check input timing was changed or not
// Notes:
//  None
//******************************************************************************
BOOL CheckModeChange(void)
{
    if (ucSyncHdlrState == DIG_SYNC) {          
#if 0//ENABLE_HDMI_PRETEST == ON
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1) || (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)//CTS
        if ((GetCurrInputInterface() != DISPLAY_PORT_INPUT) && (GetCurrInputInterface() != DISPLAY_PORT_INPUT1)
         && (GetCurrInputInterface() != DISPLAY_PORT_INPUT2) && (GetCurrInputInterface() != DISPLAY_PORT_INPUT3))
#endif
        {
#if ((INPUT_INTERFACE&INPUT_MHL_MASK) // CTS
            if (!MHL_IsCDSenseFlagOn())
#endif
            {//not MHL
                if ((SC_DVI_CTRL_308 & 0x07) != 0x00) {
                    SC_DVI_CTRL_309 |= BIT0;//clear error
                    return TRUE;
                }
            }
        }
#endif
        if (IsForceToSleep() == TRUE) {
            ClearModeChangeFlag();
            TMDS_EnableSCDT();
            McuScalerIntEnable();
            // Monitor the variation of TMDS clock under power saving mode
            if (abs(TMDS_GetClock() - usTMDSClock) > 2) {
                return TRUE;
            }
        }
#if (INPUT_INTERFACE&INPUT_DP)
        else if (GetCurrInputInterface() == DISPLAY_PORT_INPUT) {
            if (abs(GetDPInputHDEImmediate() - usTMDSHrtlDE) > 2) {
                return TRUE;
            }
            if (abs(GetDPInputVDEImmediate() - usTMDSVrtlDE) > 1) {
                return TRUE;
            }
        }
#endif        
#if (INPUT_INTERFACE&INPUT_DP1)
        else if (GetCurrInputInterface() == DISPLAY_PORT_INPUT1) {
            if (abs(GetDPInputHDEImmediate() - usTMDSHrtlDE) > 2) {
                return TRUE;
            }
            if (abs(GetDPInputVDEImmediate() - usTMDSVrtlDE) > 1) {
                return TRUE;
            }
        }
#endif        
#if (INPUT_INTERFACE&INPUT_DP2)
        else if (GetCurrInputInterface() == DISPLAY_PORT_INPUT2) {
            if (abs(GetDPInputHDEImmediate() - usTMDSHrtlDE) > 2) {
                return TRUE;
            }
            if (abs(GetDPInputVDEImmediate() - usTMDSVrtlDE) > 1) {
                return TRUE;
            }
        }
#endif        
#if (INPUT_INTERFACE&INPUT_DP3)
        else if (GetCurrInputInterface() == DISPLAY_PORT_INPUT3) {
            if (abs(GetDPInputHDEImmediate() - usTMDSHrtlDE) > 2) {
                return TRUE;
            }
            if (abs(GetDPInputVDEImmediate() - usTMDSVrtlDE) > 1) {
                return TRUE;
            }
        }
#endif        
       else {
			#if ENABLE_DVI_DUAL_LINK == ON		
			if (!TMDS_IsDualLink())
			#endif	
			{
			
		        // The HDMISoftReset is used to recover the abnormal states of HDMI circuit. When HDMI circuit
		        // is under abnormal states, the H/V total are unstable. So, we monitor H/V total and reset HDMI
		        // circuit when H/V total is unstable.
	            // Monitor the variation of TMDS DE under normal display
	            if (abs(GetDigInputHActiveImmediate() - usTMDSHrtlDE) > 2) {
	                return TRUE;
	            }
	            if (abs(GetDigInputVActiveImmediate() - usTMDSVrtlDE) > 1) {
	                return TRUE;
	            }

		        #if ENABLE_HDMI == ON
	            // Monitor the variation of TMDS DE under normal display
	            #if ENABLE_SCALER_3D == ON
	            if (SC3DAPI_IsActiveSpaceChanged()) {
	                return TRUE;
	            }
	            #endif
	            // The HTotal is unstable when input is deepcolor(e.x. For NT68360 the diff range is 0~10).
	            // For fitting all scaler characteristic, we choose the value of HTotal tolerance as 16.
	            if (abs(GetDigInputHTotalImmediate() - usTMDSHtotal) > 16) {
	                HDMISoftReset();
	                return TRUE;
	            }
	            // The VTotal is unstable when input is interlace format.  we choose the value of VTotal
	            // tolerance as 4.
#if ENABLE_FREESYNC_HDMI_FUNC == ON
                //FreeSync Function do not support interlace timing.
                if (bFreeSyncMode == FALSE && (abs(GetDigInputVTotalImmediate() - usTMDSVtotal) > 4)) {
#else
	            if (abs(GetDigInputVTotalImmediate() - usTMDSVtotal) > 4) {
#endif
	                HDMISoftReset();
	                return TRUE;
	            }
		        #endif
            }
        }
    }


    if (IsInterlaceSyncPreset()) { //If input is interlaced
        if ((SC_GPORT_CTRL & BIT2) == 0x00) {
            SC_GPORT_CTRL |= BIT2;		
            return TRUE;
        }
    }
    else {
        if ((SC_GPORT_CTRL & BIT2) != 0x00) {
            SC_GPORT_CTRL &= ~BIT2;
            return TRUE;
        }
    }

    if (CheckModeChangeFlag() == TRUE) {		
        return TRUE;
    }

    return FALSE;
}

//******************************************************************************
// Prototype: 
//  static UCHAR SyncSource(void)
// Parameters:
//  None
// Return:
//  Sync status(NO_SYNC/NO_CABLE/SEP_SYNC/COM_SYNC/SOG_SYNC/DIG_SYNC)
// Purpose:
//  Check and search input sync in SyncSrcTbl
// Notes:
//  None
//******************************************************************************
static UCHAR SyncSource(void)
{
    UCHAR sync, next_sync_idx;

    //CheckInputSync will return NO_SYNC/SEP_SYNC/COM_SYNC/SOG_SYNC/DIG_SYNC
    sync = CheckInputSync();

    if (sync == NO_SYNC) {
        if (bIsCableConnect() == FALSE) {
            sync = NO_CABLE;
        }
        if (ucSyncChangeCnt > 0) {
            ucSyncChangeCnt--;
        }
        else {
            UpdateSyncSrcIdx();
            usPortTimer_1ms = GetSyncSourceTimer();
            if (((GetTimerTick()-usTimerTickTemp)<usPortTimer_1ms) || (bManualSyncSource==TRUE)) {
                next_sync_idx = GetSameInput();
                //RecordCurrentSource(FALSE);
                if (ucSyncSrcIdx != next_sync_idx) {
                    ucSyncSrcIdx = next_sync_idx;
                    SetInputInterface(SyncSrcTbl[ucSyncSrcIdx]);
                }
            }
            else {
                if (ucRecordSyncSrcIdx < sizeof(SyncSrcTbl)) {
                    // Do not change the sequence of the following statements.
                    // Return back to Record source index.
                    next_sync_idx = ucRecordSyncSrcIdx;
                    RecordCurrentSource(FALSE);
                }
                else {
                next_sync_idx = GetNextInput();
                }
                if (ucSyncSrcIdx != next_sync_idx) {
                    ucSyncSrcIdx = next_sync_idx;
                    SetInputInterface(SyncSrcTbl[ucSyncSrcIdx]);
#if (ENABLE_DIGI3_HPD == ON) ||(ENABLE_DIGI2_HPD == ON) ||(ENABLE_DIGI1_HPD == ON) || (ENABLE_DIGI0_HPD == ON) || (ENABLE_DP_HPD == ON) || (ENABLE_DP1_HPD == ON) || (ENABLE_DP2_HPD == ON) || (ENABLE_DP3_HPD == ON)
                    SYSAPI_PerformHPDOff(FALSE);
#endif
                }
                usTimerTickTemp = GetTimerTick();
            }
#if (INPUT_INTERFACE&INPUT_MHL_MASK)
            if ( ((SyncSrcTbl[ucSyncSrcIdx]==DIGITAL_INPUT0) && MHLIsCBus1On() ) || ((SyncSrcTbl[ucSyncSrcIdx]==DIGITAL_INPUT1) &&  MHLIsCBus2On() ) ||
  				 ((SyncSrcTbl[ucSyncSrcIdx]==DIGITAL_INPUT2) && MHLIsCBus1On() ) || ((SyncSrcTbl[ucSyncSrcIdx]==DIGITAL_INPUT3) &&  MHLIsCBus2On() )    ) {
                if ( GetCbusConnectStatus() == MHL_PATH_EN ) {					
                    ResetCurTimerTick();
                }
            }
#endif
        }
    }

#if (ENABLE_DIGI3_HPD == ON) ||(ENABLE_DIGI2_HPD == ON) ||(ENABLE_DIGI1_HPD == ON) || (ENABLE_DIGI0_HPD == ON) || (ENABLE_DP_HPD == ON) || (ENABLE_DP1_HPD == ON) || (ENABLE_DP2_HPD == ON) || (ENABLE_DP3_HPD == ON) || (ENABLE_USB_TYPE_C == ON)
    if ( sync == UNKNOWN_SYNC) { //need to discuss with Nick&James
        SYSAPI_PerformHPDOn();
    }
    else {
        if (bIsHPDActive() == FALSE) {
            if (GetGlobalTimer(GLOBAL_TMR_HPD) > 0) {
                sync = NO_SYNC;
                if (bIsCableConnect() == FALSE) {
                    sync = NO_CABLE;
                }
            }
            else {
                SYSAPI_PerformHPDOn();
            }
        }
    }
#endif

    return sync;
}

//******************************************************************************
// Prototype: 
//  static void SetModeChanged(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Set some flags to indicate that input timing was changed
// Notes:
//  None
//******************************************************************************
static void SetModeChanged(void)
{
#if IS_NT68810_SERIES || IS_NT68870_SERIES
#if ENABLE_SCALER_AUDIO == ON
    ScalerAudioPreMute();
#endif
#endif
#if IS_NT68810_SERIES || IS_NT68870_SERIES
//Chroma HDMI HDCP on, have snow noise when timing change.
#if (ENABLE_DIGI3_HPD == ON) ||(ENABLE_DIGI2_HPD == ON) ||(ENABLE_DIGI1_HPD == ON) || (ENABLE_DIGI0_HPD == ON)
{
    UCHAR curr_interface;
    if ((SC_DISPLAY_CHANNEL & BIT7) != 0) {  // 0x159
        curr_interface = GetCurrInputInterface();
        if ((curr_interface == DIGITAL_INPUT0) || (curr_interface == DIGITAL_INPUT1)
        || (curr_interface == DIGITAL_INPUT2) || (curr_interface == DIGITAL_INPUT3)) {
            SYSAPI_PerformHPDOff(FALSE);// mode change set hot plug Pin off(Low) one time.
            Sleep(500);
            SYSAPI_PerformHPDOn();
#if ENABLE_EMBEDED_TMDS_CLOCK_TRAINING == OFF
            ClearTMDSTraining();
#endif
        }
    }
}
#endif
#endif
    Force2Background(0, 0, 0); //Mute screen and display black pattern
    ucSyncHdlrState = NO_SYNC;
    ucInputSyncMode = NO_SYNC;
    ucSyncChangeCnt = SYNC_CHANGE_CNT;
    usPortTimer_1ms = GetSyncSourceTimer();
    usTimerTickTemp = GetTimerTick();
    ClearModeChangeFlag(); //Clear mode change flag
    ClearForceToSleep();
}

//******************************************************************************
// Prototype: 
//  static UCHAR GetSameInput(void)
// Parameters:
//  None
// Return:
//  The sync index in SyncSrcTbl
// Purpose:
//  Search next input sync belonged to the same input interface in SyncSrcTbl
// Notes:
//  None
//******************************************************************************
static UCHAR GetSameInput(void)
{
    UCHAR i, j;

    for (i=1; i<=sizeof(SyncSrcTbl); i++) {
        j = (ucSyncSrcIdx+i) % sizeof(SyncSrcTbl);
        if ((SyncSrcTbl[j]&PORT_MASK) == (SyncSrcTbl[ucSyncSrcIdx]&PORT_MASK)) {
            //SyncSrcTbl[j] is the next sync that we found in the same interface.
            //Ex. Seperate -> Composite -> SOG -> Seperate -> Composite -> ...
            return j;
        }
    }

    //Error handling, program should not run to here.
    return ucSyncSrcIdx;
}

//******************************************************************************
// Prototype: 
//  static UCHAR GetNextInput(void)
// Parameters:
//  None
// Return:
//  The sync index in SyncSrcTbl
// Purpose:
//  Search next input sync belonged to the different input interface in 
//  SyncSrcTbl
// Notes:
//  None
//******************************************************************************
static UCHAR GetNextInput(void)
{
    UCHAR i, j;

    for (i=1; i<=sizeof(SyncSrcTbl); i++) {
        j = (ucSyncSrcIdx+i) % sizeof(SyncSrcTbl);
        if ((SyncSrcTbl[j]&PORT_MASK) != (SyncSrcTbl[ucSyncSrcIdx]&PORT_MASK)) {
            //SyncSrcTbl[j] is the next input interface that we found.
            //Ex. DSub -> DVI -> HDMI -> DSub -> DVI -> ...
            return j;
        }
    }

    ucSyncSrcIdx = GetSameInput();
    //If we can not find next input in SyncSrcTbl, return current input.
    return ucSyncSrcIdx;
}

//******************************************************************************
// Prototype: 
//  void SetSyncSource(UCHAR Type)
// Parameters:
//  Type : AUTO_SYNC/MANUAL_SYNC
// Return:
//  None
// Purpose:
//  Make SyncSource searching input sync automatically or manually
// Notes:
//  None
//******************************************************************************
void SetSyncSource(UCHAR Type)
{
#if ENABLE_HDMI_PRETEST == ON || ENABLE_AUTO_CONTROL == ON
    Type = MANUAL_SYNC;
#endif
    if (SystemData.bHDMI_PRETEST == ON) { //工厂优先
        Type = MANUAL_SYNC;
    }
    if (Type == AUTO_SYNC) {
        bManualSyncSource = FALSE;
    }
    else {
        bManualSyncSource = TRUE;
    }
}

//******************************************************************************
// Prototype: 
//  static void UpdateSyncSrcIdx(void)
// Parameters:
//  void
// Return:
//  None
// Purpose:
//  Update the variable "ucSyncSrcIdx" if the input interface was changed 
//  outside of SyncSource.
// Notes:
//  None
//******************************************************************************
static void UpdateSyncSrcIdx(void)
{
    UCHAR i, curr_interface;

    curr_interface = GetCurrInputInterface();
    for (i=0; i<sizeof(SyncSrcTbl); i++) {
        if (SyncSrcTbl[i] == curr_interface) {
            ucSyncSrcIdx = i;
            return;
        }
    }
}

//******************************************************************************
// Prototype: 
//  static USHRT GetSyncSourceTimer(void)
// Parameters:
//  void
// Return:
//  The time out timer of changing input port
// Purpose:
//  Set set timer to change input port
// Notes:
//  None
//******************************************************************************
static USHRT GetSyncSourceTimer(void)
{
    UCHAR curr_interface;
    USHRT time = 0;

    curr_interface = GetCurrInputInterface();

    switch (curr_interface) {
        case ANALOG_SEP_INPUT0:
        case ANALOG_COM_INPUT0:
        case ANALOG_SOG_INPUT0:
        case ANALOG_YPBPR_INPUT0:
            time = SYNCSRC_TIME_ANALOG0;
            break;

        case DIGITAL_INPUT0:
#if IS_NT68810_SERIES || IS_NT68870_SERIES
#if (INPUT_INTERFACE&INPUT_MHL0)
            if (MHL_Is_CDSense1_IO_HIGH()) {
                time = SYNCSRC_TIME_DIGITAL0 + 5000;
            }
            else
#endif
#endif
            time = SYNCSRC_TIME_DIGITAL0;
            break;

        case ANALOG_SEP_INPUT1:
        case ANALOG_COM_INPUT1:
        case ANALOG_SOG_INPUT1:
        case ANALOG_YPBPR_INPUT1:
            time = SYNCSRC_TIME_ANALOG1;
            break;

        case DIGITAL_INPUT1:
#if IS_NT68810_SERIES || IS_NT68870_SERIES
#if (INPUT_INTERFACE&INPUT_MHL1)
            if (MHL_Is_CDSense2_IO_HIGH()) {
                time = SYNCSRC_TIME_DIGITAL1 + 5000;
            }
            else
#endif
#endif
            time = SYNCSRC_TIME_DIGITAL1;
            break;
#if (INPUT_INTERFACE&INPUT_DIG2)
        case DIGITAL_INPUT2:
#if IS_NT68870_SERIES
#if (INPUT_INTERFACE&INPUT_MHL2)
			if (MHL_Is_CDSense1_IO_HIGH()) {
				time = SYNCSRC_TIME_DIGITAL2 + 5000;
			}
			else
#endif
#endif			
            time = SYNCSRC_TIME_DIGITAL2;
            break;
#endif
#if (INPUT_INTERFACE&INPUT_DIG3)
        case DIGITAL_INPUT3:
#if IS_NT68870_SERIES
#if (INPUT_INTERFACE&INPUT_MHL3)
			if (MHL_Is_CDSense2_IO_HIGH()) {
				time = SYNCSRC_TIME_DIGITAL3 + 5000;
			}
			else
#endif
#endif			
            time = SYNCSRC_TIME_DIGITAL3;
            break;
#endif
#if (INPUT_INTERFACE&INPUT_DP)
        case DISPLAY_PORT_INPUT:
#if ENABLE_USB_TYPE_C == ON
            if (IsUSBCCConnect()) {
                time = SYNCSRC_TIME_DP + 5000;
            }
            else
#endif        
            time = SYNCSRC_TIME_DP;
            break;
#endif
#if (INPUT_INTERFACE&INPUT_DP1)
        case DISPLAY_PORT_INPUT1:
            time = SYNCSRC_TIME_DP1;
            break;
#endif
#if (INPUT_INTERFACE&INPUT_DP2)
        case DISPLAY_PORT_INPUT2:
            time = SYNCSRC_TIME_DP2;
            break;
#endif
#if (INPUT_INTERFACE&INPUT_DP3)
        case DISPLAY_PORT_INPUT3:
            time = SYNCSRC_TIME_DP3;
            break;
#endif
        default:
            time = SYNCSRC_TIME_ANALOG0;
            break;
    }

    return time;
}

//******************************************************************************
// Prototype: 
//  UCHAR GetSyncMode(void)
// Parameters:
//  None
// Return:
//  NO_SYNC/NO_CABLE/SEP_SYNC/COM_SYNC/SOG_SYNC/DIG_SYNC/OUT_SYNC
// Purpose:
//  Return system sync state
// Notes:
//  None
//******************************************************************************
UCHAR GetInputSyncMode(void)
{
    return ucInputSyncMode;
}

#if (INPUT_INTERFACE&INPUT_MHL_MASK) || (ENABLE_DP_HPD == ON) || (ENABLE_DP1_HPD == ON)
#if !lrd_dis
//******************************************************************************
// Prototype: 
//  void ResetCurTimerTick(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Reset Change-port timer (used for MHL)
// Notes:
//  None
//******************************************************************************
void ResetCurTimerTick(void)
{
    ucSyncChangeCnt = SYNC_CHANGE_CNT;
    usPortTimer_1ms = GetSyncSourceTimer();
    usTimerTickTemp = GetTimerTick();
}
#endif
#endif

//******************************************************************************
// Prototype:
//  void RecordCurrentSource(UCHAR enable)
// Parameters:
//  enable : TRUE/FALSE
//  TRUE: Record current source index.
//  FALSE: clear Record source index.
// Return:
//  None
// Purpose:
//  Determine whether to record current sync source or not
// Notes:
//  @Param TRUE : only use to manual change input source
//******************************************************************************
void RecordCurrentSource(UCHAR enable)
{
    if (enable) {
        // We use UpdateSyncSrcIdx to make sure the range of ucSyncSrcIdx is valid or not.
        // P.S. When system AC on, ucSyncSrcIdx is 0. That is invalid for ucRecordSyncSrcIdx.
        UpdateSyncSrcIdx();
        ucRecordSyncSrcIdx = ucSyncSrcIdx;
    }
    else {
        ucRecordSyncSrcIdx = 0xFF;
    }
}
