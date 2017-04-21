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
enum _APPKEYEVENT_ {
    APPEVT_KEY_ONOFF,
    APPEVT_KEY_ON,
    APPEVT_KEY_OFF,
    APPEVT_KEY_SAVING,
    APPEVT_KEY_SOURCE,
    APPEVT_KEY_QUICK_ONOFF,
    APPEVT_KEY_FACTORY,
    APPEVT_KEY_WAKEUP,
    APPEVT_KEY_TIMING_SWITCH,
    APPEVT_KEY_DEMO,
    APPEVT_KEY_OSDLOCK,
    APPEVT_NONKEY,
    NUM_APP_KEY_EVENTS
} ;

enum _APPOSDEVENT_ {
    APPEVT_OSD_UPD_USR,
    APPEVT_OSD_UPD_SYS,
    APPEVT_OSD_UPD_TMG,
    APPEVT_OSD_UPD_CAL,
    APPEVT_NONOSD,
    NUM_APP_OSD_EVENTS
} ;

enum _APPDDCCIEVENT_ {
    APPEVT_DDCCI_UPD_USR,
    APPEVT_DDCCI_UPD_SYS,
    APPEVT_DDCCI_UPD_TMG,
    APPEVT_DDCCI_UPD_CAL,
    APPEVT_DDCCI_PWR_ON,
    APPEVT_DDCCI_PWR_OFF,
    APPEVT_DDCCI_PWR_SAVING,
    APPEVT_NONDDCCI,
    NUM_APP_DDCCI_EVENTS
} ;

enum {
    APPFLAG_UPD_TMG  = 0x0001,
    APPFLAG_UPD_USR  = 0x0002,
    APPFLAG_UPD_CAL  = 0x0004,
    APPFLAG_UPD_SYS  = 0x0008,
    APPFLAG_LOGO     = 0x0010,
    APPFLAG_NOSYNC   = 0x0020,
    APPFLAG_OUTRANGE = 0x0040,
    APPFLAG_SYSINIT  = 0x0080,
    APPFLAG_NOCABLE  = 0x0100
};

#define IsAPPUpdTmg()   ((usAPPFlags&APPFLAG_UPD_TMG) != 0)
#define IsAPPUpdUsr()   ((usAPPFlags&APPFLAG_UPD_USR) != 0)
#define IsAPPUpdCal()   ((usAPPFlags&APPFLAG_UPD_CAL) != 0)
#define IsAPPUpdSys()   ((usAPPFlags&APPFLAG_UPD_SYS) != 0)
#define IsAPPLogo()     ((usAPPFlags&APPFLAG_LOGO) != 0)
#define IsAPPNoSync()   ((usAPPFlags&APPFLAG_NOSYNC) != 0)
#define IsAPPOutRange() ((usAPPFlags&APPFLAG_OUTRANGE) != 0)
#define IsAPPSysInit()  ((usAPPFlags&APPFLAG_SYSINIT) != 0)
#define IsAPPNoCable()  ((usAPPFlags&APPFLAG_NOCABLE) != 0)

#define SetAPPUpdTmgFlag()   {usAPPFlags |= APPFLAG_UPD_TMG;}
#define SetAPPUpdUsrFlag()   {usAPPFlags |= APPFLAG_UPD_USR;}
#define SetAPPUpdCalFlag()   {usAPPFlags |= APPFLAG_UPD_CAL;}
#define SetAPPUpdSysFlag()   {usAPPFlags |= APPFLAG_UPD_SYS;}
#define SetAPPLogoFlag()     {usAPPFlags |= APPFLAG_LOGO;}
#define SetAPPNoSyncFlag()   {usAPPFlags |= APPFLAG_NOSYNC;}
#define SetAPPSysInitFlag()  {usAPPFlags |= APPFLAG_SYSINIT;}
#define SetAPPOutRangeFlag() {usAPPFlags |= APPFLAG_OUTRANGE;}
#define SetAPPNoCableFlag()  {usAPPFlags |= APPFLAG_NOCABLE;}

#define ClearAPPUpdTmgFlag() {usAPPFlags &= ~APPFLAG_UPD_TMG;}
#define ClearAPPUpdUsrFlag() {usAPPFlags &= ~APPFLAG_UPD_USR;}
#define ClearAPPUpdCalFlag() {usAPPFlags &= ~APPFLAG_UPD_CAL;}
#define ClearAPPUpdSysFlag() {usAPPFlags &= ~APPFLAG_UPD_SYS;}
#define ClearAPPLogoFlag()   {usAPPFlags &= ~APPFLAG_LOGO;}
#define ClearAPPNoSyncFlag() {usAPPFlags &= ~APPFLAG_NOSYNC;}
#define ClearAPPOutRangeFlag() {usAPPFlags &= ~APPFLAG_OUTRANGE;}
#define ClearAPPSysInitFlag() {usAPPFlags &= ~APPFLAG_SYSINIT;}
#define ClearAPPNoCableFlag() {usAPPFlags &= ~APPFLAG_NOCABLE;}

#define ClearAPPUpdFlag() { \
    usAPPFlags &= ~(APPFLAG_UPD_TMG|APPFLAG_UPD_USR|APPFLAG_UPD_CAL|APPFLAG_UPD_SYS); \
}
#define ClearAPPSyncFlag() { \
    usAPPFlags &= ~(APPFLAG_NOSYNC|APPFLAG_OUTRANGE|APPFLAG_NOCABLE); \
}
#define ClearAPPAllFlag() {usAPPFlags = 0x00;}

#if (USE_INTERNAL_EDID == 1)
    #define EDIDProtectOn() { \
        McuSetDDCWP(MCU_DDC_0,ON); \
        McuSetDDCWP(MCU_DDC_1,ON); \
        McuSetDDCWP(MCU_DDC_2,ON); \
        McuSetDDCWP(MCU_DDC_3,ON); \
        EdidWPOn(); \
    }
    #define EDIDProtectOff() { \
        McuSetDDCWP(MCU_DDC_0,OFF); \
        McuSetDDCWP(MCU_DDC_1,OFF); \
        McuSetDDCWP(MCU_DDC_2,OFF); \
        McuSetDDCWP(MCU_DDC_3,OFF); \
        EdidWPOff(); \
    }
#else
    #define EDIDProtectOn()  EdidWPOn()
    #define EDIDProtectOff() EdidWPOff()
#endif

USHRT Auto_Power_off_Timer;


//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************
static code UCHAR ucKey2APPEventTable[NUM_KEY_EVENTS] = {
    APPEVT_KEY_ONOFF,           //KEYEVT_PWR
    APPEVT_NONKEY,              //KEYEVT_MENU
    APPEVT_NONKEY,              //KEYEVT_AUTO
    APPEVT_KEY_SOURCE,          //KEYEVT_INPUT,
    APPEVT_KEY_QUICK_ONOFF,     //KEYEVT_FUNC,
    APPEVT_NONKEY,              //KEYEVT_UP
    APPEVT_KEY_WAKEUP,          //KEYEVT_DOWN
    APPEVT_NONKEY,              //KEYEVT_LEFT
    APPEVT_NONKEY,              //KEYEVT_RIGHT
    APPEVT_KEY_FACTORY,         //KEYEVT_FACT
    APPEVT_NONKEY,              //KEYEVT_PWLOCK
    APPEVT_KEY_OSDLOCK,         //KEYEVT_OSDLOCK
    APPEVT_KEY_TIMING_SWITCH,   //KEYEVT_TIMING_SWITCH
    APPEVT_KEY_DEMO,         //KEYEVT_DEMO
    APPEVT_NONKEY               //KEYEVT_NONE
};

static code APPAction ucAPPKeyActionTable[NUM_APP_KEY_EVENTS] = {
    APPATN_PWR_ONOFF,       //APPEVT_KEY_ONOFF
    APPATN_PWR_ON,          //APPEVT_KEY_ON
    APPATN_PWR_OFF,         //APPEVT_KEY_OFF
    APPATN_PWR_SAVING,      //APPEVT_KEY_SAVING
    APPATN_CH_SOURCE,       //APPEVT_KEY_SOURCE
    APPATN_QUICK_ONOFF,     //APPEVT_KEY_QUICK_ONOFF
    APPATN_SET_FACTORY,     //APPEVT_KEY_FACTORY
    APPATN_WAKEUP,          //APPEVT_KEY_WAKEUP
    APPATN_TIMING_SWITCH,   //APPEVT_KEY_TIMING_SWITCH
    APPATN_SET_DEMO,        //APPEVT_KEY_DEMO
    APPATN_SET_OSDLOCK,     //APPEVT_KEY_OSDLOCK
    APP_NON_ACTION          //APPEVT_NONKEY
};

static code UCHAR ucOSD2APPEventTable[NUM_OSD_EVENTS] = {
    APPEVT_OSD_UPD_USR, //OSDEVT_UPD_USR,
    APPEVT_OSD_UPD_SYS, //OSDEVT_UPD_SYS,
    APPEVT_OSD_UPD_TMG, //OSDEVT_UPD_TMG,
    APPEVT_OSD_UPD_CAL, //OSDEVT_UPD_CAL,
    APPEVT_NONOSD       //OSD_NON_EVENT,
};

static code APPAction ucAPPOSDActionTable[NUM_APP_OSD_EVENTS] = {
    APPATN_UPD_USR,     //APPEVT_OSD_UPD_USR,
    APPATN_UPD_SYS,     //APPEVT_OSD_UPD_SYS,
    APPATN_UPD_TMG,     //APPEVT_OSD_UPD_TMG,
    APPATN_UPD_CAL,     //APPEVT_OSD_UPD_CAL,
    APP_NON_ACTION      //APPEVT_NONOSD,
};

static code UCHAR ucDDCCi2APPEventTable[NUM_DDCCI_EVENTS] = {
    APPEVT_DDCCI_UPD_USR, //DDCCIEVT_UPD_USR,
    APPEVT_DDCCI_UPD_SYS, //DDCCIEVT_UPD_SYS,
    APPEVT_DDCCI_UPD_TMG, //DDCCIEVT_UPD_TMG,
    APPEVT_DDCCI_UPD_CAL, //DDCCIEVT_UPD_CAL,
    APPEVT_DDCCI_PWR_ON, //DDCCIEVT_PWR_ON,
    APPEVT_DDCCI_PWR_OFF, //DDCCIEVT_PWR_OFF,
    APPEVT_DDCCI_PWR_SAVING, //DDCCIEVT_PWR_SAVING,
    APPEVT_NONDDCCI       //DDCCIEVT_NON,
};

static code UCHAR ucAPPDDCCiActionTable[NUM_APP_DDCCI_EVENTS] = {
    APPATN_UPD_USR, //APPEVT_DDCCI_UPD_USR,
    APPATN_UPD_SYS, //APPEVT_DDCCI_UPD_SYS,
    APPATN_UPD_TMG, //APPEVT_DDCCI_UPD_TMG,
    APPATN_UPD_CAL, //APPEVT_DDCCI_UPD_CAL,
    APPATN_PWR_ON, //APPEVT_DDCCI_PWR_ON,
    APPATN_PWR_OFF, //APPEVT_DDCCI_PWR_OFF,
    APPATN_FORCE_PWR_SAVING, //APPEVT_DDCCI_PWR_SAVING,
    APP_NON_ACTION  //APPEVT_NONDDCCI,
};

static BOOL bIsAPPFirstCalled = TRUE;
static xdata USHRT usAPPFlags = 0x0000;
static xdata UCHAR ucCurSyncState  = 0xFF;
static xdata UCHAR ucPOTCnt_20s = 0;

#if ENABLE_INTERNAL_AUDIO_BUZZER
static BOOL bIsBuzzerEnable = FALSE;
#endif

//******************************************************************************
// E X T E R N A L   V A R I A B L E   P R O T O T Y P E S
//******************************************************************************
#if MD_ENABLE_AO_DETECT == ON
extern bit bWaitPowerKeyRelease;
extern xdata USHRT usAOTimer;
#endif
#if OSDTYPE == OSD_BENQ_V1 || OSDTYPE == OSD_BENQ_V2
extern BOOL bOSDShowAfterDisplay;
#endif

//******************************************************************************
// S T A T I C   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
static void APPTimerRoutine(void);
static void APPSetSystemPowerState(APPPwrState state);
static UCHAR APPSyncPublisher(void);
static void APPEnterPowerOnLogo(void);
static void APPEscapePowerOnLogo(void);
static void APPClosePowerOnLogo(void);
static void APPTasksBeforeDisplay(void);
static void APPTasksAfterDisplay(void);
static void APPTasksAfterMute(void);
static void APPToggleFactoryMode(void);
static void APPToggleDemoMode(void);
static void APPPerformBurnIn(void);
static void APPCountRedLed(BOOL rst);
static BOOL APPIsOutOfLimit(void);
#if ENABLE_HW_CEC == ON
static void APPPerformCECReq(void);
#endif
#if ENABLE_SELF_AUTOCOLOR == ON
static void APPIntAutoColor(void);
#endif

//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// Prototype:
//  void APPInitSystem(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Initial all system configuration
// Notes:
//  None
//******************************************************************************
void APPInitSystem(void)
{
   UCHAR ucSCID = GetSCID(); // for some scaler type KeilC compiler uncalled.
   
#if TPV_DP_VERSION_SELECT == ON
    SetDPSpeed(UserData.bDPVersion);
#endif
    // Initial PWM of backlight control
#if ENABLE_PWM_SMOOTH == ON
    SmoothScalerPWM(BKL_PWM_PORT, 0, 1);//NT68667, 673 and 675 no this function
#endif
    SetBLPwmByInputVSync(FALSE);
    SetVSyncResetPWM(BKL_PWM_PORT, ON);

    // Initial PWM of volume control
    ConfigScalerPWM(VOLUME_PWM_PORT, VOLUME_PWM_OUTPUT_PIN, VOLUME_PWM_FREQ);
    SetVSyncResetPWM(VOLUME_PWM_PORT, OFF);

    UserSetOSDH();
    UserSetOSDV();
    UserSetTransparent();
    UserSetTimeout();
    UserSetOSDRotation();
    UserSetBrightness();
    UserSetContrast();
    UserSetColorTemp();
    // We move the LOGO to the begin of APPInitSystem to reduce the power on time.
#if MD_ENABLE_AO_DETECT == ON
#if IS_NT68810_SERIES || IS_NT68870_SERIES
    SC_ZERO_PWR_CTRL_B69 |= BIT1;
    if ((SC_ZERO_PWR_CTRL_B64 & BIT2) != 0) {
        SC_ZERO_PWR_CTRL_B69 |= BIT0;
        SC_ZERO_PWR_CTRL_B69 &= ~BIT0;
        bWaitPowerKeyRelease = TRUE;
        usAOTimer = GetTimerTick();
        if (UserData.bPowerStatus == OFF) {
            UserData.bPowerStatus = ON;
            SetAPPUpdUsrFlag();
            if (CheckFactoryMode() == TRUE) {
                APPToggleFactoryMode();
                SetAPPUpdSysFlag();
            }
        }
        else {
            UserData.bPowerStatus = OFF;
            SetAPPUpdUsrFlag();
        }
    }
    else {
        bWaitPowerKeyRelease = FALSE;
    }
    
    if ((UserData.bPowerStatus == ON) && ((SC_ZERO_PWR_CTRL_B67 & 0x0E) != 0)) {//0x08
        bIsAPPFirstCalled = FALSE;
    }
    
    if (SystemData.bFactory == TRUE) {
        if ((SC_ZERO_PWR_CTRL_B67 & 0x70) != 0) {//BIT4/5/6
            do {
                ResetWDTimer();
                SC_ZERO_PWR_CTRL_B69 |= BIT0;
                SC_ZERO_PWR_CTRL_B69 &= ~BIT0;
                Sleep(AO_KEY_DEBOUNCE_TIME); //wait HW debounce
            } while ((SC_ZERO_PWR_CTRL_B67 & 0x70) != 0);
            if (UserData.bPowerStatus == OFF) {
                UserData.bPowerStatus = ON;
                SetAPPUpdUsrFlag();
                if (CheckFactoryMode() == TRUE) {
                    APPToggleFactoryMode();
                    SetAPPUpdSysFlag();
                }
            }
        }
    }

    SetZPDetect(ZP_CLEAR);
    ZPLatchData();
#else
    if ((AO_DETECT & BIT2) != 0) {
        AO_DETECT |= BIT2;
        bWaitPowerKeyRelease = TRUE;
        usAOTimer = GetTimerTick();
        if (UserData.bPowerStatus == OFF) {
            UserData.bPowerStatus = ON;
            SetAPPUpdUsrFlag();
            if (CheckFactoryMode() == TRUE) {
                APPToggleFactoryMode();
                SetAPPUpdSysFlag();
            }
        }
    }
    else {
        bWaitPowerKeyRelease = FALSE;
    }
    if (SystemData.bFactory == TRUE) {
        if (((AO_DETECT & 0x90) != 0) || ((AO_DETECT2 & BIT0) != 0)) {//BIT7 & BIT4
            do {
                ResetWDTimer();
                AO_DETECT |= 0x90;
                AO_DETECT2 |= BIT0;
                Sleep(AO_KEY_DEBOUNCE_TIME); //wait HW debounce
            } while (((AO_DETECT & 0x90) != 0) || ((AO_DETECT2 & BIT0) != 0));
            if (UserData.bPowerStatus == OFF) {
                UserData.bPowerStatus = ON;
                SetAPPUpdUsrFlag();
                if (CheckFactoryMode() == TRUE) {
                    APPToggleFactoryMode();
                    SetAPPUpdSysFlag();
                }
            }
        }
    }
    AO_DETECT |= 0x90;
    AO_DETECT2 |= BIT0;
#endif

#else
#if	!PWR_AUTO_INTO_FAC
	if(CheckFactoryMode()== TRUE)
		if(!SystemData.bFactory)
		APPToggleFactoryMode();
#endif
#endif

//new  20151021 before logo, due to 0xF050[7]=b0 when load trim key
#if ENABLE_HDCP == ON
#if ENABLE_HDCP_TRIM_MODE == ON
        ucEFUSETrimSucess = 0xFF;
        if ((GetSCID() == SCID_661_B) && (GetEFUSE_SCID() == SCID_661_B)) {//NT68661
            ucEFUSETrimSucess = InitHDCPTrimKey();
        }
        else if ((GetSCID() == SCID_655) && (GetEFUSE_SCID() == SCID_655)) {//NT68655
            ucEFUSETrimSucess = InitHDCPTrimKey();
        }
        else if (GetSCID() == SCID_770_G) {//NT6877x Version G/...
            ucEFUSETrimSucess = InitHDCPTrimKey();
        }
//        else if ((GetSCID() == SCID_850) && (GetEFUSE_SCID() == SCID_850)) {//NT68655
        else if (GetSCID() == GetEFUSE_SCID()) {//NT6885x
            ucEFUSETrimSucess = InitHDCPTrimKey();
        }
#if IS_NT68790_SERIES_LATER
        else if (GetSCID() == GetEFUSE_SCID()) {//NT68790, NT68658
            ucEFUSETrimSucess = InitHDCPTrimKey();
        }
#endif
#if IS_NT68810_SERIES || IS_NT68870_SERIES
        else if (1) {//NT68810
            ucEFUSETrimSucess = InitHDCPTrimKey();
        }
#endif

        else
#endif
        {
            InitHDCP();
        }
#endif

    if (UserData.bPowerStatus == ON) {
        LedGreenOn();
        if (bIsAPPFirstCalled) {
            APPEnterPowerOnLogo();
        }
        else {
            OSDInitialize(TRUE);
        }
    }

    // Enable Audio Power
    AudioPowerOn();


#if ENABLE_PRE_REV_GAMMA == ON
    LoadPreGamma();
    LoadRevGamma();
#endif
#if ENABLE_GAMMA == ON
    Standard_Gamma = 1;
    LoadGamma();
#endif

    InitColor();

#if ENABLE_DBC == ON
    InitDBC();
#endif

#if ENABLE_LD == ON
    InitLD();
#endif

#if ENABLE_SR == ON
    InitSR();
#endif

#if ENABLE_3D_CNV == ON
    InitScaler3D();
#endif

#if ENABLE_DYNAMIC_OD == ON
    ODAPI_SetDynamicOD();
#endif

    // Initial user data
    UserSetADCGainOffset();
//    UserSetBrightness();
//    UserSetContrast();
//    UserSetColorTemp();
//    UserSetOSDH();
//    UserSetOSDV();
//    UserSetTransparent();
//    UserSetTimeout();
//    UserSetOSDRotation();
    //UserSetAudioMute();
//    UserSetVolume();
    //UserSetAspectRatio();

#if ENABLE_AUTO_CONTROL == ON
#if (ENABLE_PREFRC == ON || ENABLE_DFR == ON)
    UserData.ucODMode = ON;
#elif (IS_NT68750_SERIES || IS_NT68770_SERIES || IS_NT68850_SERIES || IS_NT68790_SERIES || IS_NT68810_SERIES || IS_NT68870_SERIES)
    if (CheckDRAM() == 32) {//test
        UserData.ucODMode = ON;
    }
    else {
        UserData.ucODMode = OFF;
    }
#endif
#endif


    UserSetOD();
    //UserSetBF();    // Move UserSetBF to APPTasksBeforeDisplay to avoid wrong BF window setting
    //UserSetDCR();   // Move UserSetDCR to APPTasksBeforeDisplay to avoid DCR/DBC in showing logo period
    //UserSetGamma();
    UserSetInputSource();
    UserSetAudioChannel();
#if ENABLE_3D_CNV == ON
    UserSet2DTo3DMode();
    UserSet2DTo3DAdaptive();
    UserSet2DTo3DDepth();
    UserSet2DTo3DView();
    UserSet3DLRSwap();
    UserSet3DTo2D();
#endif    
    SetSyncSource(UserData.bAutoSyncSource);
    
    // Init key configuration
    KeySetRepeatEvent(0xFF, OFF);
    if(UserData.bOSDLock == ON){
        KeySetHoldEvent(0xFF, ON);
    }
    else{
        KeySetHoldEvent(0xFF, OFF);
        KeySetHoldEvent(KEYEVT_FUNC, ON);        
    }
    KeySetMFuncEvent(0xFF, 0x00);
    KeySetHoldTime(KEY_HOLD_TIME);
    KeySetRepeatTime(KEY_REPEAT_TIME);
    KeySetLongPressTime(KEY_LONG_PRESS_TIME);

#if ENABLE_HW_CEC == ON
    APPRequestCECAct(CECATN_SET_LANGUAGE);
#endif
    
    if (SystemData.bFactory) {
        EDIDProtectOff();
#if ENABLE_SELF_AUTOCOLOR == ON
        APPIntAutoColor();
#endif
    }
	else
	{
		EDIDProtectOn();
	}

    if (UserData.bPowerStatus != ON) {
        SYSAPI_SetPowerOff();
    }
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1)
#if !(IS_NT68810_SERIES || IS_NT68870_SERIES)
    else {
    #if ENABLE_DP_HPD == ON
        DPHPDOn();
    #endif
    #if ENABLE_DP1_HPD == ON
        DP1HPDOn();
    #endif
    }
#endif
#endif
#if (INPUT_INTERFACE&INPUT_MHL_MASK)// && ENABLE_HDMI_PRETEST == ON
    ToggleRxSense();
#endif

    bIsAPPFirstCalled = FALSE;
#if ENABLE_AUTO_CONTROL == ON
    printf(SCALER_TEXT" V1.0\n");
#endif

#if ENABLE_ECO_EYE_SENSOR == ON
    ECOEYESensorECOStateInitail();
    ECOEYESensorEYEProtectStateInitail();
    ECOEYESensorOnOff();
#endif
#if OSDTYPE == OSD_BENQ_V1 || OSDTYPE == OSD_BENQ_V2
    bOSDShowAfterDisplay = FALSE;
#endif



}

//******************************************************************************
// Prototype:
//  void APPActionDispatcher(UCHAR event)
// Parameters:
//  event   : Perform system action by global event id
// Return:
//  None
// Purpose:
//  Dispatch action to system. ex: power saving, power off etc...
// Notes:
//  None
//******************************************************************************
void APPActionDispatcher(UCHAR event)
{
    APPAction act = APP_NON_ACTION;

    if (GetGlobalEvent(event) == KEY_RELATED_EVENT) {
        event = GetLocalEvent(event);
        event = ucKey2APPEventTable[event];
        if (event != APPEVT_NONKEY) {
            act = ucAPPKeyActionTable[event];
            //printf("APPActionDispatcher->KeyEvent(%bx) Action(%bx)\n\r", event, act);
        }
    }
    else if (GetGlobalEvent(event) == OSD_RELATED_EVENT) {
        event = GetLocalEvent(event);
        event = ucOSD2APPEventTable[event];
        if (event != APPEVT_NONOSD) {
            act = ucAPPOSDActionTable[event];
            //printf("APPActionDispatcher->OSDEvent(%bx) Action(%bx)\n\r", event, act);
        }
    }
    else if (GetGlobalEvent(event) == DDCCI_RELATED_EVENT) {
        event = GetLocalEvent(event);
        event = ucDDCCi2APPEventTable[event];
        if (event != APPEVT_NONDDCCI) {
            act = ucAPPDDCCiActionTable[event];
            //printf("APPActionDispatcher->DDCCiEvent(%bx) Action(%bx)\n\r", event, act);
        }
    }
    else {
    }

    switch(act) {
        
    case APPATN_SET_OSDLOCK:
            if(UserData.bOSDLock == OFF){
                UserData.bOSDLock = ON;
                OSDShowOSDLock();
                KeySetHoldEvent(0xFF, ON);
                SetOSDState(OSD_INFO_OSDLOCK_STATE);
                SetOSDUpdUsrFlag();             
                break;
            }    
            UserData.bOSDLock = OFF;
            KeySetHoldEvent(0xFF, OFF);    
            KeySetHoldEvent(KEYEVT_FUNC, ON);                    
            OSDEnterOSDUnLock();
            SetAPPUpdUsrFlag();
            break;
	 case APPATN_SET_DEMO:
            APPToggleDemoMode();
            APPSetSystemPowerState(APPSTATE_PWR_ON);
            SetGlobalTimer(GLOBAL_TMR_DATA_UPDATE, GBTM_DATA_UPDATE);
            SetAPPUpdSysFlag();
	     break;
        case APPATN_SET_FACTORY:
			#if PWR_AUTO_INTO_FAC
			if(!UserData.bPowerStatus)
			{
				if (!SystemData.bFactory)
	            APPToggleFactoryMode();
	            APPSetSystemPowerState(APPSTATE_PWR_ON);
	            SetGlobalTimer(GLOBAL_TMR_DATA_UPDATE, GBTM_DATA_UPDATE);
	            SetAPPUpdSysFlag();
	            SetAPPUpdUsrFlag();
			}
			#endif
			break;
        case APPATN_PWR_ONOFF:
        #if OSDTYPE == OSD_BENQ_V2
        if(Custom_System.bPowerKeyYNPowerONOFFFlag)
            Custom_System.bPowerKeyYNPowerONOFFFlag = 0;
        else
        #endif
            {
            #if ENABLE_HW_CEC == ON
                APPRequestCECAct(CECATN_STANDBY); // The standby command must be prior to system standby command!! // Jude 2009/03/08
            #endif
                APPSetSystemPowerState(APPSTATE_PWR_ONOFF);
                SetGlobalTimer(GLOBAL_TMR_DATA_UPDATE, GBTM_DATA_UPDATE);
                SetAPPUpdUsrFlag();
            }
            break;
        case APPATN_PWR_ON:
            APPSetSystemPowerState(APPSTATE_PWR_ON);
            SetGlobalTimer(GLOBAL_TMR_DATA_UPDATE, GBTM_DATA_UPDATE);
            SetAPPUpdUsrFlag();         
            break;
        case APPATN_PWR_OFF:
            APPSetSystemPowerState(APPSTATE_PWR_OFF);
            SetGlobalTimer(GLOBAL_TMR_DATA_UPDATE, GBTM_DATA_UPDATE);
            SetAPPUpdUsrFlag();            
            break;
        case APPATN_PWR_SAVING:
            APPSetSystemPowerState(APPSTATE_PWR_SAVING);
            break;
        case APPATN_FORCE_PWR_SAVING:
            APPSetSystemPowerState(APPSTATE_FORCE_PWR_SAVING);
            break;
        case APPATN_CH_SOURCE:
            UserData.ucInputSource = GetInputPortName((GetInputPortIndex(UserData.ucInputSource)+1)%NUM_INPUT_SC);
            UserSetInputSource();
            break;
        case APPATN_QUICK_ONOFF:
#if ENABLE_3D_CNV == ON
            if (UserData.uc2DTo3DMode != THR_D_CNV_2D_TO_3D) {
                UserData.uc2DTo3DMode = THR_D_CNV_2D_TO_3D;
            }
            else {
                UserData.uc2DTo3DMode = THR_D_CNV_OFF;
            }
            UserSet2DTo3DMode();
            SetModeChangeFlag();
            SetAPPUpdUsrFlag();
#endif
            break;
        case APPATN_UPD_USR:
            SetGlobalTimer(GLOBAL_TMR_DATA_UPDATE, GBTM_DATA_UPDATE);
            SetAPPUpdUsrFlag();
            break;
        case APPATN_WAKEUP:
            APPSetSystemPowerState(APPSTATE_WAKEUP);
            break;
        case APPATN_UPD_SYS:
            SetGlobalTimer(GLOBAL_TMR_DATA_UPDATE, GBTM_DATA_UPDATE);
            SetAPPUpdSysFlag();
            break;
        case APPATN_UPD_TMG:
            SetGlobalTimer(GLOBAL_TMR_DATA_UPDATE, GBTM_DATA_UPDATE);
            SetAPPUpdTmgFlag();
            break;
        case APPATN_UPD_CAL:
            SetGlobalTimer(GLOBAL_TMR_DATA_UPDATE, GBTM_DATA_UPDATE);
            SetAPPUpdCalFlag();
            break;
        case APPATN_TIMING_SWITCH:
            SimilarTimingSwitch();
            break;
        case APP_NON_ACTION:
        default :
            break;
    }
}

//******************************************************************************
// Prototype:
//  UCHAR APPActionDemander(void)
// Parameters:
//  None
// Return:
//  system event
// Purpose:
//  Return system event to other handlers.
// Notes:
//  None
//******************************************************************************
UCHAR APPActionDemander(void)
{
    UCHAR evt;

    // acquire System status
    evt = APPSyncPublisher();

    // APPSyncPublisher must be prior to APPTimerRoutine!
    // Otherwise, system may go to power saving state while sync present!
    APPTimerRoutine();

    return evt;
}

//******************************************************************************
// Prototype:
//  void APPTimerRoutine(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Periodic routine.
// Notes:
//  None
//******************************************************************************

void APPTimerRoutine(void)
{
#if ENABLE_SET_PWM_MAX_BUFFER == ON
    SetBrightnessPWMMax();
#endif

#if IS_NT68810_SERIES || IS_NT68870_SERIES
    HDMIDelayAudioInit();
#endif
    
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1)
    DPHandler();
#endif

#if ENABLE_USB_TYPE_C == ON
    USBTypeCHandler();
#endif

#if (INPUT_INTERFACE&INPUT_MHL_MASK)
    MHLHandler();
#endif

#if ENABLE_EDP == ON
    if (IsZpMode() == FALSE) {//130822#1
        CheckDPTXHPD();
    }
#endif

    // Check EDID update and write it to nvram immediately
#if (USE_INTERNAL_EDID) 
    if (SystemData.bFactory && (McuCheckDDCUpdate() != 0)) {
        NvramSaveEDID();
    }
#endif

#if ENABLE_AUTO_CONTROL == ON
    UART_Handler();
#endif

#if ENABLE_HW_CEC == ON
    APPPerformCECReq();
#endif

#if ENABLE_INTERNAL_AUDIO_BUZZER == ON
    APPCountAudioBuzzer();
#endif
    
#if IS_NT68810_SERIES || IS_NT68870_SERIES
#if (INPUT_INTERFACE&INPUT_DIG0) || (INPUT_INTERFACE&INPUT_DIG1) || (INPUT_INTERFACE&INPUT_DIG2) || (INPUT_INTERFACE&INPUT_DIG3)
#if ENABLE_TMDS_EQ_SEARCH_FLOW == ON
#if ENABLE_EMBEDED_TMDS_CLOCK_TRAINING == OFF
    TMDS_EQSet_Flow();
#endif
#endif
#endif
#endif

    if ((GetGlobalTimer(GLOBAL_TMR_POT_CNT) == 0)) {
        SetGlobalTimer(GLOBAL_TMR_POT_CNT, GBTM_POT_CNT);
        ucPOTCnt_20s++;

        if (ucPOTCnt_20s > 3) {
            ucPOTCnt_20s = 1;
            SystemData.ucMonitorPowerOnTimerM++;
            if(IsPanelPowerOn()){
            SystemData.ucPowerOnTimerM++;
            }
#if ENABLE_FE2P == ON
            RecordTimeScale();
#endif
            if (SystemData.ucPowerOnTimerM > 59) {
                SystemData.ucPowerOnTimerM = 0;
                if (SystemData.usPowerOnTimerH != 0xffff) {
                    SystemData.usPowerOnTimerH++;
#if ENABLE_FE2P == ON
                    if ((SystemData.usPowerOnTimerH % POT_SAVE_H) == 0) { // Save POT time every 5460 hour (4095*8/6)
                        SystemData.ucPOTimerM_FE2P = SystemData.ucPowerOnTimerM;
                        SystemData.usPOTimerH_FE2P = SystemData.usPowerOnTimerH;
                        NvramWriteSystemData(&SystemData);
                        FE2P_SaveToFlash();
                        EraseTimeScale();
                    }
#else
                    SetAPPUpdSysFlag(); // Save POT time every hours
#endif
                }
            }
            if (SystemData.ucMonitorPowerOnTimerM > 59) {
                SystemData.ucMonitorPowerOnTimerM = 0;
                if (SystemData.usMonitorPowerOnTimerH != 0xffff) {
                    SystemData.usMonitorPowerOnTimerH++;
                    SetAPPUpdSysFlag(); // Save BKL time every hours
                }
            }
        }
    }

    if (GetGlobalTimer(GLOBAL_TMR_DATA_UPDATE) == 0) {
        SetGlobalTimer(GLOBAL_TMR_DATA_UPDATE, GBTM_DATA_UPDATE);
        if (IsAPPUpdTmg() &&
            (GetInputSyncMode() != DIG_SYNC) &&
            ((GetModeHandleState() == WAIT_DISPLAY_READY) || (GetModeHandleState() == WAIT_MODE_CHANGE))) {
            NvramWriteTimingData(&InputTiming);
            //printf("APPTimerRoutine->Update Timing\n\r");
        }
        if (IsAPPUpdUsr()) {
            NvramWriteUserData(&UserData);
            //printf("APPTimerRoutine->Update UserData\n\r");
        }
        if (IsAPPUpdCal()) {
            NvramWriteCalibData(&CalibData);
            //printf("APPTimerRoutine->Update Cal\n\r");
        }
        if (IsAPPUpdSys()) {
            NvramWriteSystemData(&SystemData);
            //printf("APPTimerRoutine->Update System\n\r");
        }
        ClearAPPUpdFlag();

    #if ((ENABLE_FE2P == ON) && (ENABLE_AUTO_CONTROL == OFF))
        FE2P_SaveToFlash();
    #endif
    }

    if ((UserData.ucAutoPowerOffTime != AUTO_POWER_OFF) && ((UserData.bPowerStatus == ON)&&IsZpMode())) {//power saving
         if ((GetTimerTick()-Auto_Power_off_Timer) > 6000) {
             Auto_Power_off_Timer = GetTimerTick();
             if (Custom_System.usAuto_poweroff_Time != 0) {
                 Custom_System.usAuto_poweroff_Time--;
             }
             if (Custom_System.usAuto_poweroff_Time == 0) {             
                 APPSetSystemPowerState(APPSTATE_PWR_OFF);
                 SetAPPUpdUsrFlag();
             }
        }
    }

    if (IsAPPLogo()) {
        if (GetGlobalTimer(GLOBAL_TMR_LOGO_TIMEOUT) == 0) {
            APPClosePowerOnLogo();
        }
    }
    else if (IsAPPNoSync()) {
        if (GetOSDState()==OSD_DIRSRC_STATE) {
            SetGlobalTimer(GLOBAL_TMR_PWR_SAVING, GBTM_NOSYNC_PWR_SAVING);
        }       
#if ENABLE_HDMI_PRETEST == OFF && ENABLE_AUTO_CONTROL == OFF
#if (INPUT_INTERFACE&INPUT_MHL_MASK)
        if ( IsMHL0Connect() || IsMHL1Connect() ) {
           // do not enter power saving if MHL cable connected
        }
        else
#endif
		if(SystemData.bBurnIn)
		{
#if 0
		     if (GetGlobalTimer(GLOBAL_TMR_LED_FLASH) == 0) {
           		 SetGlobalTimer(GLOBAL_TMR_LED_FLASH, GBTM_LED_FLASH);
	            APPCountRedLed(FALSE);
       		 }
#endif
			if (GetGlobalTimer(GLOBAL_TMR_PWR_SAVING) == 0) {
				APPPerformBurnIn();
				SetGlobalTimer(GLOBAL_TMR_PWR_SAVING, GBTM_NOSYNC_PWR_SAVING);
			}
		}
		else
        if (GetGlobalTimer(GLOBAL_TMR_PWR_SAVING) == 0) {
            //printf("APPTimerRoutine->Enter Power Saving State\n\r");
            APPSetSystemPowerState(APPSTATE_PWR_SAVING);
            ClearAPPNoSyncFlag();
            SetGlobalTimer(GLOBAL_TMR_LED_FLASH, GBTM_LED_FLASH);
            APPCountRedLed(TRUE);
        }
#endif
    }
    else if (IsAPPNoCable()) {
        if (GetOSDState()==OSD_DIRSRC_STATE) {
            SetGlobalTimer(GLOBAL_TMR_PWR_SAVING, GBTM_NOSYNC_PWR_SAVING);
        }  
        if(SystemData.bBurnIn)
        {
#if 0
             if (GetGlobalTimer(GLOBAL_TMR_LED_FLASH) == 0) {
                 SetGlobalTimer(GLOBAL_TMR_LED_FLASH, GBTM_LED_FLASH);
                APPCountRedLed(FALSE);
             }
#endif
            if (GetGlobalTimer(GLOBAL_TMR_PWR_SAVING) == 0) {
                APPPerformBurnIn();
                SetGlobalTimer(GLOBAL_TMR_PWR_SAVING, GBTM_NOSYNC_PWR_SAVING);
            }
        }
        else
        if (GetGlobalTimer(GLOBAL_TMR_PWR_SAVING) == 0) {
            //printf("APPTimerRoutine->Enter Power Saving State\n\r");
            OSDCloseAll();//nick20100430+ fix press source select hot key show no signal msg osd in power saving mode
            APPSetSystemPowerState(APPSTATE_PWR_SAVING);
            ClearAPPNoCableFlag();
            SetGlobalTimer(GLOBAL_TMR_LED_FLASH, GBTM_LED_FLASH);
            APPCountRedLed(TRUE);
        }
    }
    else if (IsAPPOutRange()) {
        if (GetGlobalTimer(GLOBAL_TMR_PWR_SAVING) == 0) {
            //printf("APPTimerRoutine->Enter Power Saving State\n\r");
            OSDCloseAll();
            APPSetSystemPowerState(APPSTATE_FORCE_PWR_SAVING);
            ClearAPPOutRangeFlag();
            APPCountRedLed(TRUE);
        }
    }
    else if (GetModeHandleState() == POWER_SAVING_MODE) {
        if (GetGlobalTimer(GLOBAL_TMR_LED_FLASH) == 0) {
            SetGlobalTimer(GLOBAL_TMR_LED_FLASH, GBTM_LED_FLASH);
            APPCountRedLed(FALSE);
        }
    }
    else if (GetModeHandleState() == WAIT_MODE_CHANGE) {
    #if ENABLE_DBC == ON
    #if 0
        if ( UserData.ucDCRMode == BKL_CTRL_DBC ) {
            DBCBrightnessTracker();
        #if ENABLE_DBC_HW_DEBOUNCE == OFF
            AntiNoiseDBC();
        #endif
        }
        else {
            DisableDBCSmooth(FALSE);
            PerformDCR(0);
        }
    #else
        if ( UserData.bDBCMode == ON ) {
            DBCBrightnessTracker();
        #if ENABLE_DBC_HW_DEBOUNCE == OFF
            AntiNoiseDBC();
        #endif
        }
        else{
            if(isOSDAllowDCR()){
                if ( UserData.ucDynamicContrast != 0 ){
                   PerformDCR(0); 
                }
            }
            DisableDBCSmooth(FALSE);
        }
    #endif
    #else
        PerformDCR(0);
    #endif
    #if ENABLE_3D_CNV == ON
        PerformAdaptive2DTO3D();
    #endif

	#if (ENABLE_LD == ON)	 && (ENABLE_DYNAMIC_LD == ON) 
		if(UserData.ucBFMode != LD_OFF) {
			PerformDynamicLD();
		}
	#endif
    }
}

//******************************************************************************
// Prototype:
//  void APPSetSystemPowerState(APPPwrState state)
// Parameters:
//  state   : system power state
// Return:
//  None
// Purpose:
//  Set system power state
// Notes:
//  None
//******************************************************************************
void APPSetSystemPowerState(APPPwrState state)
{
    switch(state) {
        case APPSTATE_PWR_ONOFF:
            if (GetModeHandleState() != SOFT_POWER_OFF) {
                if (IsAPPLogo()) {
                    APPEscapePowerOnLogo();
                }
				if(SystemData.bBurnIn)
					SystemData.bBurnIn = ~SystemData.bBurnIn;	
				if (SystemData.bFactory)
	            APPToggleFactoryMode();
                UserData.bPowerStatus = OFF;
                if (GetProductModeFlag()) {   // DFM  : Recall need exit BurnIn and clear POT Timer  //v05_120608_1430_OSD#6
                    ClrProductModeFlag();
                    SystemData.ucPowerOnTimerM = 0x00;
                    SystemData.usPowerOnTimerH = 0x00;
                    SystemData.ucMonitorPowerOnTimerM = 0x00;
                    SystemData.usMonitorPowerOnTimerH = 0x0000;        
                    SystemData.usPOTimerH_FE2P = 0x00;
                    SystemData.ucPOTimerM_FE2P = 0x00;
#if ENABLE_FE2P == ON
                    EraseTimeScale();
#endif
                    NvramWriteSystemData(&SystemData);
                }
                SYSAPI_SetPowerOff();
            }
            else {
                UserData.bPowerStatus = ON;
                DCR_BenQ_Reset();
                SYSAPI_SetPowerOn();
                UserSetInputSource();
                APPEnterPowerOnLogo();
            }
            break;
        case APPSTATE_PWR_OFF:
            if (IsAPPLogo()) {
                APPEscapePowerOnLogo();
            }
            UserData.bPowerStatus = OFF;
            SYSAPI_SetPowerOff();
            break;
        case APPSTATE_PWR_ON:
            UserData.bPowerStatus = ON;
            SYSAPI_SetPowerOn();
            UserSetInputSource();
            APPEnterPowerOnLogo();
            break;
        case APPSTATE_PWR_SAVING:
            SYSAPI_PowerSaving();
            break;
        case APPSTATE_FORCE_PWR_SAVING:
            SYSAPI_ForcePowerSaving();
            break;
        case APPSTATE_WAKEUP:
            if (GetModeHandleState() == POWER_SAVING_MODE) {
                SYSAPI_SetPowerOn();
                UserSetInputSource();
            }
            break;
        default :
            break;
    }
}
//******************************************************************************
// Prototype:
//  void APPResendAppSync(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Re-send APP-level sync state.
// Notes:
//  This function is called externally by OSD
//******************************************************************************
void APPResendAppSync(void)
{
    ucCurSyncState  = 0xFF;
}

//******************************************************************************
// Prototype:
//  static void APPTasksBeforeDisplay(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Perform user-specific tasks before showing images.
// Notes:
//  This function is called externally by ModeHandler
//******************************************************************************
static void APPTasksBeforeDisplay(void)
{
    // Add any user specific function here.
    
    UserSetAudioChannel();
    SetBLPwmByInputVSync(TRUE);
    UserSetBF();
    UserSetDCR();         
//    UserSetVolume();
#if ENABLE_PICTURE_DUAL_MODE == ON
    if(UserData.bSensEyeDemo== PICTURE_DUALMODE_ON){
        UserSetDualView(UserData.bSensEyeDemo,UserData.ucDualViewMode);
    }
#endif

//#if IS_NT68661_SERIES || IS_NT68770_SERIES || IS_NT68850_SERIES || IS_NT68655_SERIES || IS_NT68790_SERIES || IS_NT68150_SERIES || IS_NT68658_SERIES
#if IS_NT68770_SERIES_LATER//SR function
#if ENABLE_SR == ON    
     SetSRBlockOnOff(ON);
#endif    
#endif
#if ENABLE_FREESYNC_HDMI_FUNC == ON
    if (IsHDMIFreesync() == TRUE && IsInterlaced() == TRUE) {
        //FreeSync Function do not support interlace timing.
        SetModeChangeFlag();
    }
#endif   
#if ENABLE_OD == ON
    UserSetOD();
#endif

}

//******************************************************************************
// Prototype:
//  static void APPTasksAfterDisplay(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Perform user-specific tasks before showing images.
// Notes:
//  This function is called externally by ModeHandler
//******************************************************************************
static void APPTasksAfterDisplay(void)
{
    // Add any user specific function here.
    //UserSetAudioMute();
    //UserSetVolume();
   
    UserSetVolumeAndMute();
    //UserSetDCR();
#if ENABLE_LD == ON
    UserSetLD();
#endif
#if ENABLE_SR == ON
    UserSetSR();
#endif
#if IS_NT68870_SERIES && ENABLE_OD == ON
///////////////////////check MMU BW
    if ((InputTiming.usModeHActive >= 1920) && (InputTiming.usModeVActive >= 1080) && (FRCIsFRCEnabled() == TRUE)) {
        ODAPI_DisableOD();
    }
///////////////////////////////
#endif
    RecordCurrentSource(FALSE);
#if OSDTYPE == OSD_BENQ_V1 || OSDTYPE == OSD_BENQ_V2  
    bOSDShowAfterDisplay = TRUE;
#endif
#if ENABLE_ECO_EYE_SENSOR ==ON
    ECOEYESensorECOStateInitail();
    ECOEYESensorEYEProtectStateInitail();
#endif


}

//******************************************************************************
// Prototype:
//  static void APPTasksAfterMute(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Perform user-specific tasks After muting images.
// Notes:
//  This function is called internally by APPSyncPublisher
//******************************************************************************
static void APPTasksAfterMute(void)
{
#if IS_NT68810_SERIES || IS_NT68870_SERIES
    SC_DP_AUDIO_FIFO_CTRL |= BIT6;  // 0x1050
    SC_HDMI_MUTE |= BIT1;  // 0x737
    usAudioMuteDelay = DP_AUDIODELAY;
#endif
#if IS_NT68870_SERIES
#if ENABLE_AUTOFRAMEDOWN == ON
    DisableFRC_AutoFrameDown();
#endif
#if ENABLE_DFR == ON
    DisableFRCConfigDFR();
#endif
#if ENABLE_POSTFRC == ON
    DisableFRCConfigPostFRC();
#endif
#if ENABLE_CENTER_MODE == ON
    DisableCenterMode();
#endif
#else
#if ENABLE_PREFRC == ON || ENABLE_DFR == ON
    SC_FRC_CTRL = 0x00; //FRC/DFR OFF
#endif
#endif
#if ENABLE_ECO_EYE_SENSOR == ON
    ECOEYESensorECOStateInitail();
    ECOEYESensorEYEProtectStateInitail();
#endif

#if ENABLE_LOW_PWR_MODE == ON
    if (IsZpMode()) {
        PowerUpRegisterAccess();
    }
#endif
#if ENABLE_LD == ON
    LDAPI_SetLDMode(LD_OFF);
#endif
#if ENABLE_SR == ON
    SetSRMode(SR_MODE_OFF);
//#if IS_NT68661_SERIES || IS_NT68770_SERIES || IS_NT68850_SERIES || IS_NT68655_SERIES || IS_NT68790_SERIES || IS_NT68150_SERIES || IS_NT68658_SERIES
#if IS_NT68770_SERIES_LATER//SR function
    SetSRBlockOnOff(OFF);
#endif
#endif
#if ENABLE_SCALER_3D == ON
    SC3DAPI_TurnOff3DMode();
#endif
    // Add any user specific function here.
    AudioMuteOn();
    SetBLPwmByInputVSync(FALSE);
    // Disable BF effect and DCR/DBC during no sync state
#if ENABLE_DBC == ON
    DisableDBC();
#else
    DisableDCR();
#endif
    BFAPI_DisableWindow(BF_WINDOW_1);
    BFAPI_DisableWindow(BF_WINDOW_2);



#if ENABLE_LOW_PWR_MODE == ON
    if (IsZpMode()) {
        PowerDownRegisterAccess();
    }
#endif
#if OSDTYPE == OSD_BENQ_V1 || OSDTYPE == OSD_BENQ_V2
    bOSDShowAfterDisplay = FALSE;
#endif

}

//******************************************************************************
// Prototype:
//  static APPEvent APPSyncPublisher(void)
// Parameters:
//  None
// Return:
//  Return sync event
// Purpose:
//  Periodically check sync state and publish event if any state changed.
// Notes:
//  None
//******************************************************************************
static UCHAR APPSyncPublisher(void)
{
    static UCHAR nosync_evt = APPEVT_NONE;
    UCHAR evt, state, mode;

    if (IsAPPLogo()) {
        return APPEVT_NONE;
    }
    
    evt = APPEVT_NONE;
    state = GetModeHandleState();
    mode = (state << 4) | GetInputSyncMode();

    if (ucCurSyncState != mode) {
        nosync_evt = APPEVT_NONE;
        ucCurSyncState = mode;
        mode = GetInputSyncMode();

        switch (state) {
            case WAIT_MODE_CHANGE:
                if (mode == NO_SYNC) {
                    evt = APPEVT_NO_SYNC;
                }
                else if (mode == NO_CABLE) {
                    evt = APPEVT_NO_CABLE;
                }
                else if (mode == OUT_SYNC) {
                    evt = APPEVT_OOR;
                }
                else {
                    evt = APPEVT_NML;
                }
                break;
            case WAIT_SYNC_STABLE:
                if (mode == NO_SYNC) {
                    evt = APPEVT_NO_SYNC;
                }
                else if (mode == NO_CABLE) {
                    evt = APPEVT_NO_CABLE;
                }
                else {
                    evt = APPEVT_UNSTABLE;
                }
                break;
            case WAIT_DISPLAY_READY:
                evt = APPEVT_PRE;
                break;
            case SYNC_IS_STABLE:
                //evt = APPEVT_NML;
                break;
            case POWER_SAVING_MODE:
                evt = APPEVT_PW_SAVING;
                break;
            case SOFT_POWER_ON:
                evt = APPEVT_PW_ON;
                break;
            case SOFT_POWER_OFF:
                evt = APPEVT_PW_OFF;
                break;
            default:
                break;
        }

        if (evt != APPEVT_NONE) {
            ClearAPPSyncFlag();

            if (evt == APPEVT_PRE) {
                // Perform routines before display
                APPTasksBeforeDisplay();
            }
//            else if (evt != APPEVT_NML) {
            else if ((evt != APPEVT_NML) && (evt != APPEVT_PW_OFF) && (evt != APPEVT_PW_SAVING)) {
                // Turn off panel power and perform routines when display is absent
#if ENABLE_AUTO_CONTROL == OFF                
                PanelPowerOffSequence();
#endif
                APPTasksAfterMute();
            }
            else if (evt == APPEVT_NML) {
                APPTasksAfterDisplay();
                if (APPIsOutOfLimit()){
                    evt = APPEVT_OOL;
                }
            }
        }
        //printf("APPSyncPublisher->SyncState(%bx) Event(%bx)\n\r", ucCurSyncState, evt);
    }

    // Publish nosync state after GBTM_APPSYNC_STABLE(ms)
    if ((evt == APPEVT_NO_SYNC) || (evt == APPEVT_NO_CABLE)) {
        nosync_evt = evt;
        SetGlobalTimer(GLOBAL_TMR_APPSYNC_STABLE, GBTM_APPSYNC_STABLE);
        evt = APPEVT_UNSTABLE;
    }

    // Publish nosync state after 2000ms
    if (nosync_evt != APPEVT_NONE) {
        if (GetGlobalTimer(GLOBAL_TMR_APPSYNC_STABLE) == 0) {
            evt = nosync_evt;
            nosync_evt = APPEVT_NONE;
            SetGlobalTimer(GLOBAL_TMR_PWR_SAVING, GBTM_NOSYNC_PWR_SAVING);
        }
    }

    if (evt == APPEVT_NO_SYNC) {
        SetAPPNoSyncFlag();
    }
    else if (evt == APPEVT_NO_CABLE) {
        SetAPPNoCableFlag();
    }
    else if (evt == APPEVT_OOR) {
        SetGlobalTimer(GLOBAL_TMR_PWR_SAVING, GBTM_OOR_PWR_SAVING);
        SetAPPOutRangeFlag();
    }   

    return evt;
}

//******************************************************************************
// Prototype: 
//  static void APPEnterPowerOnLogo(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Show power-on logo
// Notes:
//  None
//******************************************************************************
static void APPEnterPowerOnLogo(void)
{
#if ENABLE_AUTO_CONTROL == OFF     
    if (SystemData.bShowLogo) {
        ShowLogo();
        KeySetLockEvent(0xFF, ON);
        KeySetLockEvent(KEYEVT_PWR, OFF);
        SetAPPLogoFlag();
        HoldModeDisplay();
        SetGlobalTimer(GLOBAL_TMR_LOGO_TIMEOUT, GBTM_LOGO_TIMEOUT);
    }
#else
    PanelPowerOnSequence(TRUE);
#endif    
}

//******************************************************************************
// Prototype:
//  static void APPEscapePowerOnLogo(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Leave logo state
// Notes:
//  None
//******************************************************************************
static void APPEscapePowerOnLogo(void)
{
    KeySetLockEvent(0xFF, OFF);
    ClearAPPLogoFlag();
    ContinueModeDisplay();
}

//******************************************************************************
// Prototype: 
//  static void APPClosePowerOnLogo(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Leave logo state with OSD initialization
// Notes:
//  None
//******************************************************************************
static void APPClosePowerOnLogo(void)
{
    CloseLogo();
    APPEscapePowerOnLogo();
}

//******************************************************************************
// Prototype:
//  static void APPToggleFactoryMode(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Enter Factory Mode
// Notes:
//  None
//******************************************************************************
static void APPToggleFactoryMode(void)
{
    SystemData.bFactory = ~SystemData.bFactory;

    if (SystemData.bFactory) {
        EDIDProtectOff();
    }
    else {
        EDIDProtectOn();
    }
}
//******************************************************************************
// Prototype:
//  static void APPToggleDemoMode(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Enter Factory Mode
// Notes:
//  None
//******************************************************************************
static void APPToggleDemoMode(void)
{
    SystemData.bDemo = ~SystemData.bDemo;
}
//******************************************************************************
// Prototype:
//  static void APPPerformBurnIn(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Display Burn In Pattern
// Notes:
//  None
//******************************************************************************
static void APPPerformBurnIn(void)
{
    code UCHAR ucBurnInPatterns[] = {
        0xFF,0xFF,0xFF,
        0x00,0x00,0x00,
        0xFF,0x00,0x00,
        0x00,0xFF,0x00,
        0x00,0x00,0xFF,
        0xFF,0xFF,0x00,
        0xFF,0x00,0xFF,
        0x00,0xFF,0xFF,
    };
    static UCHAR ucBurnInPtnID = 0x00;

    SetPostBGColor(ucBurnInPatterns[ucBurnInPtnID*3],
                   ucBurnInPatterns[ucBurnInPtnID*3+1],
                   ucBurnInPatterns[ucBurnInPtnID*3+2]);

    ucBurnInPtnID = (ucBurnInPtnID+1) % (sizeof(ucBurnInPatterns)/sizeof(char)/3);
}

//******************************************************************************
// Prototype: 
//  static void APPCountRedLed(BOOL rst)
// Parameters:
//  rst : Reset internal counter
// Return:
//  None
// Purpose:
//  For flashing LED under power saving mode
// Notes:
//  None
//******************************************************************************
static void APPCountRedLed(BOOL rst)
{
    static UCHAR ucLedCnt = 0;

    if ((ucLedCnt>10) || rst) {
        if (LED_RED_PORT == MCU_PORT_NULL) {
            LedGreenOn();
        }
        else {
            LedRedOn();
        }
        ucLedCnt = 0;
    }
    else {
        if (LED_RED_PORT == MCU_PORT_NULL) {
            LedGreenOff();
        }
        else {
            LedRedOff();
        }
        ucLedCnt++;
    }
}

//******************************************************************************
// Prototype:
//  static BOOL APPIsOutOfLimit(void)
// Parameters:
//  None
// Return:
//  If input timing is OOL, return TRUE. Otherwise, FALSE.
// Purpose:
//  Check the input timing is out of limit or not.
// Notes:
//  None
//******************************************************************************
BOOL APPIsOutOfLimit(void)
{
#if ENABLE_SCALER_3D == ON
    if (SC3DAPI_IsHDMI3DMode()) {
        return FALSE;
    }
#endif
    //if (InputTiming.usVSyncFreq < MIN_V_FREQ_LMT) {
    //    return TRUE;
    //}
    if (InputTiming.usVSyncFreq > MAX_V_FREQ_LMT) {
        return TRUE;
    }
    return FALSE;
}

#if ENABLE_HW_CEC == ON
//******************************************************************************
// Prototype: 
//  static void APPPerformCECReq(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Perform CEC function
// Notes:
//  None
//******************************************************************************
static void APPPerformCECReq(void)
{
#if ENABLE_LOW_PWR_MODE == ON
    // Turn on scaler register R/W power before access CEC function
    if (IsZpMode()) {
        PowerUpRegisterAccess();
    }    
#endif

    switch(CECHandler()) {
        case CECREQ_POWERUP:
            APPSetSystemPowerState(APPSTATE_PWR_ON);
            break;
        case CECREQ_POWERDOWN:
            APPSetSystemPowerState(APPSTATE_PWR_OFF);
            break;
        case CECREQ_ACTIVATE_SC:
            APPSetSystemPowerState(APPSTATE_PWR_ON);
            // We only have one HDMI interface, so we do not have to 
            // decide which interface to be activated by ID
            // Jude 2009/03/04
            //if (CECGetActiveSC() == 0) 
            UserData.ucInputSource = INPUT_SC_HDMI;
            UserSetInputSource();
            break;
        case CECREQ_DEVCTRL:
            if (CECGetDeviceCtlCode() == CEC_USER_CTRL_POWER) {
                APPSetSystemPowerState(APPSTATE_PWR_ONOFF);
            }
            break;
        case CECREQ_NONE:
        default:
            break;
    }

#if ENABLE_LOW_PWR_MODE == ON
    // Turn off scaler register R/W power after access CEC function
    if (IsZpMode()) {
        PowerDownRegisterAccess();
    }    
#endif
}

//******************************************************************************
// Prototype: 
//  void APPRequestCECAct(UCHAR act)
// Parameters:
//  act : CEC action
// Return:
//  None
// Purpose:
//  Demand CEC action to other device
// Notes:
//  None
//******************************************************************************
void APPRequestCECAct(UCHAR act)
{
    code UCHAR ucCECLanguageMap[NUM_OSDLANGS]= {
        CECLANG_ENGLISH,    //OSDLANG_ENGLISH,
        CECLANG_SPANISH,    //OSDLANG_SPANISH,
        CECLANG_FRENCH,     //OSDLANG_FRENCH,
        CECLANG_GERMAN,     //OSDLANG_GERMAN,
        CECLANG_ITALIAN,    //OSDLANG_ITALIAN,
        CECLANG_PORTUGUESE, //OSDLANG_PORTUGUESE,
        CECLANG_RUSSIAN,    //OSDLANG_RUSSIAN,
        CECLANG_SCHINESE,   //OSDLANG_SCHINESE,
    };
    
#if ENABLE_LOW_PWR_MODE == ON
    // Turn on scaler register R/W power before access CEC function
    if (IsZpMode()) {
        PowerUpRegisterAccess();
    }    
#endif
    
    switch(act) {
        case CECATN_STANDBY:
            if (GetModeHandleState() != SOFT_POWER_OFF) {
                CECSetStandby();
            }
            break;
        case CECATN_SET_LANGUAGE:
            CECSetOSDLanguage(ucCECLanguageMap[UserData.ucLanguage]);
            break;
        case CECATN_NONE:
        default:
            break;
    }

#if ENABLE_LOW_PWR_MODE == ON
    // Turn off scaler register R/W power after access CEC function
    if (IsZpMode()) {
        PowerDownRegisterAccess();
    }    
#endif

}
#endif

#if ENABLE_INTERNAL_AUDIO_BUZZER == ON
//******************************************************************************
// Prototype:
//  void APPSetAudioBuzzer(USHRT time)
// Parameters:
//  time : time in ms
// Return:
//  None
// Purpose:
//  Audio buzzer in the period of time.
// Notes:
//  None
//******************************************************************************
void APPSetAudioBuzzer(USHRT time)
{
    EnableVCSAudioBuzzer(1000);
    bIsBuzzerEnable = TRUE;
    SetGlobalTimer(GLOBAL_TMR_BUZZER_TIME, time);
}

//******************************************************************************
// Prototype:
//  void APPCountAudioBuzzer(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Turn off audio buzzer if time out.
// Notes:
//  None
//******************************************************************************
void APPCountAudioBuzzer(void)
{
    if (bIsBuzzerEnable == TRUE) {
        if (GetGlobalTimer(GLOBAL_TMR_BUZZER_TIME) == 0) {
            bIsBuzzerEnable = FALSE;
            DisableVCSAudioBuzzer();
        }
    }
}
#endif

//******************************************************************************
// Prototype:
//  static void APPIntAutoColor(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Perform internal auto color when system startup
// Notes:
//  None
//******************************************************************************
#if ENABLE_SELF_AUTOCOLOR == ON
static void APPIntAutoColor(void)
{
    if (bIsAPPFirstCalled && InternalAutoColor()) {
        CalibData.ucADCRGain = GetADCRGain();
        CalibData.ucADCGGain = GetADCGGain();
        CalibData.ucADCBGain = GetADCBGain();
        CalibData.ucADCROffset = GetADCROffset();
        CalibData.ucADCGOffset = GetADCGOffset();
        CalibData.ucADCBOffset = GetADCBOffset();
        SetAPPUpdCalFlag();
    }
}
#endif

//******************************************************************************
// Prototype:
// static void CheckTotalPortNum(void)
// Parameters:
//  None
// Return:
//  total source number
// Purpose:
//  check input source number
// Notes:
//  None
//******************************************************************************
UCHAR CheckTotalPortNum(void)
{
    UCHAR PortNum = 0;

#if 0 // 0 lrd add 
#if ((INPUT_INTERFACE & INPUT_VGA0) == INPUT_VGA0)  
           PortNum++;
#endif
#if ((INPUT_INTERFACE & INPUT_VGA1) == INPUT_VGA1)  
           PortNum++;
#endif
#if ((INPUT_INTERFACE & INPUT_DIG0) == INPUT_DIG0) 
           PortNum++;
#endif
#if ((INPUT_INTERFACE & INPUT_DIG1) == INPUT_DIG1) 
           PortNum++;
#endif
#if ((INPUT_INTERFACE & INPUT_DIG2) == INPUT_DIG2) 
           PortNum++;
#endif
#if ((INPUT_INTERFACE & INPUT_DIG3) == INPUT_DIG3) 
           PortNum++;
#endif
#if ((INPUT_INTERFACE & INPUT_DP) == INPUT_DP) 
           PortNum++;
#endif
#if ((INPUT_INTERFACE & INPUT_DP1) == INPUT_DP1) 
           PortNum++;
#endif
#if ((INPUT_INTERFACE & INPUT_DP2) == INPUT_DP2) 
           PortNum++;
#endif
#if ((INPUT_INTERFACE & INPUT_DP3) == INPUT_DP3) 
           PortNum++;
#endif
#if ((INPUT_INTERFACE & INPUT_YPbPr0) == INPUT_YPbPr0) 
           PortNum++;
#endif
#if ((INPUT_INTERFACE & INPUT_YPbPr1) == INPUT_YPbPr1) 
           PortNum++;
#endif
#else


#if (MODEL_INPUT_VGA0 !=  INPUT_SC_NULL)  
			PortNum++;
#endif
#if (MODEL_INPUT_VGA1 !=  INPUT_SC_NULL)  
			PortNum++;
#endif
#if (MODEL_INPUT_DIG0 !=  INPUT_SC_NULL)  
			PortNum++;
#endif
#if (MODEL_INPUT_DIG1 !=  INPUT_SC_NULL)  
			PortNum++;
#endif
#if (MODEL_INPUT_DIG2 !=  INPUT_SC_NULL)  
			PortNum++;
#endif
#if (MODEL_INPUT_DIG3 !=  INPUT_SC_NULL)  
			PortNum++;
#endif
#if (MODEL_INPUT_DIG4 !=  INPUT_SC_NULL)  
			PortNum++;
#endif
#if (MODEL_INPUT_DIG5 !=  INPUT_SC_NULL)  
			PortNum++;
#endif
#if (MODEL_INPUT_DIG6 !=  INPUT_SC_NULL)  
			PortNum++;
#endif
#if (MODEL_INPUT_DIG7 !=  INPUT_SC_NULL)  
			PortNum++;
#endif

#if (MODEL_INPUT_YPbPr0 !=  INPUT_SC_NULL)  
			PortNum++;
#endif
#if (MODEL_INPUT_YPbPr1 !=  INPUT_SC_NULL)  
			PortNum++;
#endif


#endif

    return PortNum;
}



BOOL IsNoSyncState(void)
{
    return IsAPPNoSync();
}

BOOL IsNoCableState(void)
{
    return IsAPPNoCable();
}
BOOL IsOutRangeState(void)
{
    return IsAPPOutRange();
}

void Custom_System_Init(void)
{
//== for ?CO?XXX or uncall lib compiler pass ==== 
        UCHAR temp = 0;
{
        UCHAR array[3],tmp = 1;
        if(tmp == 0){//fix uncalled warning  
          Write3ByteScaler(array, 0xFFFFFF);  
          WriteScalerIndexPort(0xFF, 0, 3, array);
     //     OSDEnterDir3();
        }
}

{
        extern void ForDemoHDCPCompilerCodePass(void);  
        ForDemoHDCPCompilerCodePass();
}

{
        extern void ForODCompilerCodePass(void);
        ForODCompilerCodePass();
}

#if ENABLE_FE2P == OFF
{
        extern void ForFE2PCompilerCodePass();
        ForFE2PCompilerCodePass();
}
#endif

#if ENABLE_DBC == OFF
{
        extern void ForDBCCompilerCodePass(void);
        ForDBCCompilerCodePass();
}
#endif

#if IS_NT68770_SERIES_LATER//SR function
#if ENABLE_LD == OFF
       { 
         extern void ForLDCompilerCodePass(void);
         ForLDCompilerCodePass();
       }
#endif
#if ENABLE_SR == OFF
       {
         extern void ForSRCompilerCodePass(void);  
         ForSRCompilerCodePass();
       }
#endif
//#if IS_NT68655_SERIES || IS_NT68850_SERIES || IS_NT68770_SERIES || IS_NT68790_SERIES || IS_NT68810_SERIES
#if IS_NT68655_SERIES || IS_NT68770_SERIES
#if (INPUT_INTERFACE&INPUT_DP) != INPUT_DP
      {
         extern void ForDPCompilerCodePass(void);
         ForDPCompilerCodePass();
      }
#endif
#endif//IS_NT68850_SERIES
#endif
    if(temp)
    {
        {
        extern void ForUSBTypeCCompilerCodePass2(void);
        ForUSBTypeCCompilerCodePass2();
        }
        {
        extern void ForUSBTypeCCompilerCodePass1(void);
        ForUSBTypeCCompilerCodePass1();
        }
        {
        extern void ForMHLCompilerCodePass(void);
        ForMHLCompilerCodePass();
        }
        {
        extern void ODAPI_SetSeparateODTestPatternEnable(UCHAR tmp);
        ODAPI_SetSeparateODTestPatternEnable(0xff);
        }
    }
//=========================

//Custom parameter
    Custom_System.bDualviewAdjust = FALSE;
    Custom_System.bForceLanguage = FALSE;
    Custom_System.bYesNoTemp = FALSE;
    Custom_System.OSDUpUsr = FALSE;
    Custom_System.OSDUpTmg = FALSE;
    Custom_System.OTSFactoryHotKey = TRUE;
    Custom_System.bDDCCICmdIMenu  = FALSE;
    Custom_System.bZPUseCurrentModeDetect = TRUE;
#if ENABLE_BRIGHTNESS_HOTKEYFUNC == ON //v03_120411_1646_OSD#1
    Custom_System.bHotKeySource = FALS E;
#else
    if (CheckTotalPortNum()==_1_Port) {
        Custom_System.bHotKeySource = FALSE;
    }
    else{
        Custom_System.bHotKeySource = TRUE;
    }
#endif
    Custom_System.bDDCCIPreSetClock = FALSE;
#if DDCCI_RETURNCMD == ON
    Custom_System.bDDCIcmdACK = FALSE;
#endif
    Custom_System.bFactory = FALSE;
    Custom_System.bPreShowSourceNoSync = FALSE;
    Custom_System.bPreShowMsgSource = TRUE;
#if ShowMsgEnergystarLogo        
    Custom_System.bPreShowMsgEnergystar  = TRUE;
#else
    Custom_System.bPreShowMsgEnergystar  = FALSE;
#endif
#if ENABLE_SHOW_OSD_LOCK_MSG_FIRST_HOTKEY_ON            
    Custom_System.bPreShowOSDLockFirstOn = FALSE;
#endif
    Custom_System.bAutoTuneFinish = FALSE;
    Custom_System.bDcrCutoffFlag = FALSE;
#if E_SAVE_FUNC    
    Custom_System.bESave_Enable = FALSE;
#endif
    //Custom_System.ucNewDynBk = 0;
    //Custom_System.iCurDynBk = 0;
    //Custom_System.ucDCRStableCount = 0;
    //Custom_System.Last_Press_Buttons = 0;
    Custom_System.ucPerformReset = 0;

    Custom_System.ucBrightness = 0;
    Custom_System.ucContrast = 0;
#if E_SAVE_FUNC    
    Custom_System.usESave_Timer_1s = 0;
#endif
    Custom_System.usCRC = 0;
    Custom_System.ucOSDColorIconID = 0;
    //Custom_System.usDDCCIRECOVERLoop = 0;
    Custom_System.bDCRTemp = 0;
    Custom_System.ucMainMenuCursor = 0;
    Custom_System.ucCurrentInputSource = UserData.ucInputSource;
    Custom_System.bPowerKeyYNPowerONOFFFlag = 0;

    Custom_System.bisModechaged = FALSE;
    Custom_System.bIsShowLogo = TRUE;
    Custom_System.ucVs_wid = 0;
    Custom_System.ucVs_wid_diff_cnt = 0;

    Custom_System.bLogoONState = 0;
    Custom_System.bDoReset = FALSE;

    Custom_System.ucFactoryHp = 50;
    Custom_System.ucFactoryVp = 50;
    Custom_System.bIsManualEDIDWP = FALSE;
    Custom_System.bAutoColorFinish = FALSE;
    Custom_System.bPIPSwap = 0;

    UserData.bSeviceMenu = FALSE;

    Custom_System.bEDIDFinish = FALSE;

    Custom_System.bNormalStates = FALSE;
    Custom_System.bPIPSourceChange = FALSE;
    Custom_System.bSOUCESWITCH = 0; 

    Custom_System.ucOSD_preview_temp = 0;
    Custom_System.bisColorFormatRGB = FALSE;

    Custom_System.bPressKeyWakeUp = FALSE;

    Custom_System.bIsTimingChanged = FALSE;

}


//******************************************************************************
// Prototype:
//  static BOOL APPIsOutOfLimit(void)
// Parameters:
//  None
// Return:
//  If input timing is OOL, return TRUE. Otherwise, FALSE.
// Purpose:
//  Check the input timing is out of limit or not.
// Notes:
//  None
//******************************************************************************
#if !lrd_dis_benq
BOOL APPIsOutOfLimit(void)
{
#if ENABLE_SCALER_3D == ON
    if (SC3DAPI_IsHDMI3DMode()) {
        return FALSE;
    }
#endif
   if ((pInputTiming->usVSyncFreq > MIN_V_FREQ_LMT) && (pInputTiming->usVSyncFreq <= MAX_V_FREQ_LMT)) {
        return TRUE;
   }
   if (pInputTiming->usModeIndex == _1024x768_43HZ_I) {
       return TRUE;
   }
    return FALSE;
}
#endif
