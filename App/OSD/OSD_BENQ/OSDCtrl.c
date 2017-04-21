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
// E X T E R N A L   V A R I A B L E   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************
static code UCHAR ucKey2OSDEventTable[NUM_KEY_EVENTS] = {
    OSD_NONKEY_EVENT,   //KEYEVT_PWR
    OSD_MENUKEY_EVENT,  //KEYEVT_MENU
    OSD_AUTOKEY_EVENT,  //KEYEVT_AUTO
    OSD_NONKEY_EVENT,   //KEYEVT_INPUT,
    OSD_EXITKEY_EVENT,//OSD_NONKEY_EVENT,   //KEYEVT_FUNC,
    OSD_UPKEY_EVENT,    //KEYEVT_UP
    OSD_DOWNKEY_EVENT,  //KEYEVT_DOWN
    OSD_NONKEY_EVENT,   //KEYEVT_LEFT
    OSD_NONKEY_EVENT,   //KEYEVT_RIGHT
    OSD_NONKEY_EVENT,   //KEYEVT_FACT
    OSD_NONKEY_EVENT,   //KEYEVT_PWLOCK
    OSD_NONKEY_EVENT,   //KEYEVT_OSDLOCK
    OSD_NONKEY_EVENT,   //KEYEVT_TIMING_SWITCH
    OSD_EXITKEY_EVENT,  //KEYEVT_EXIT
    OSD_NONKEY_EVENT    //KEYEVT_NONE
};

static code UCHAR ucApp2OSDEventTable[NUM_APP_EVENTS] = {
    OSD_OFF_EVENT,      //APPEVT_PW_ON
    OSD_OFF_EVENT,      //APPEVT_PW_OFF
    OSD_OFF_EVENT,      //APPEVT_PW_SAVING
    OSD_NO_SYNC_EVENT,  //APPEVT_NO_SYNC
    OSD_NO_CABLE_EVENT, //APPEVT_NO_CABLE
    OSD_OFF_EVENT,      //APPEVT_UNSTABLE
    OSD_NOP_EVENT,      //APPEVT_PRE
    OSD_NML_EVENT,      //APPEVT_NML
    OSD_OOL_EVENT,      //APPEVT_OOL
    OSD_OOR_EVENT,      //APPEVT_OOR
    OSD_NOP_EVENT       //APPEVT_NON
};

static xdata OSDState usOSDState = OSD_OFF_STATE;
static xdata USHRT usOSDLocalTimer;
static xdata USHRT usOSDTimer;
static xdata USHRT usOSDSRIntervalTimerL = 0;
static xdata USHRT usOSDSRIntervalTimerH = 0;

static code UCHAR ucUnsupportItemTab[] = {
OSD_MAIN_2_4_STATE,
OSD_MAIN_2_5_STATE,
OSD_MAIN_2_6_STATE,
OSD_MAIN_2_7_STATE,

OSD_MAIN_3_4_STATE

};

//******************************************************************************
// S T A T I C   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
static void OSDConfigKeyBehavior(void);

OSDState GetOSDState(void)
{
    return usOSDState;
}

void SetOSDState(OSDState state)
{
    usOSDState = state;
}

//******************************************************************************
// Prototype:
//  void OSDActionDispatcher(OSDEvent event)
// Parameters:
//  event   : event to OSD action
// Return:
//  None
// Purpose:
//  Perform OSD action by input event id
// Notes:
//  None
//******************************************************************************
void OSDActionDispatcher(UCHAR event)
{
    if ((GetModeHandleState() == SOFT_POWER_OFF) ||
        (GetModeHandleState() == POWER_SAVING_MODE)) {
        return;
    }

    if (GetGlobalEvent(event) == KEY_RELATED_EVENT) {
        event = GetLocalEvent(event);
        event = ucKey2OSDEventTable[event];

        if (event != OSD_NONKEY_EVENT) {
            //printf("KEYKEY =%d,%d\r\n",(USHRT)event,(USHRT)usOSDState);
            if (OSDKeyRoutine[usOSDState][event] != NULL) {
            #if ENABLE_INTERNAL_AUDIO_BUZZER == ON
                APPSetAudioBuzzer(100);
            #endif

                if (usOSDState > OSD_TOPPAGE_BEG && usOSDState <= OSD_DIRECT_3_STATE){//ULEric140327N         
                    OSDBlinkSelectPageButton(event, ucMenuAction, 0);
                }
               
                (*OSDKeyRoutine[usOSDState][event])();
             //OSDUpdateKeyInfo(usOSDState);//ULEric140328
                usOSDLocalTimer = GetTimerTick();
                UserSetTimeout();
                OSDConfigKeyBehavior();

                //if (usOSDState > OSD_TOPPAGE_BEG && usOSDState <= OSD_DIRECT_3_STATE)//ULEric140327N
                    //OSDBlinkSelectPageButton(event, ucMenuAction, 1);

                //OSDConfigKeyBehavior();
            }
        }
    }
    else if (GetGlobalEvent(event) == APP_RELATED_EVENT) {
        event = GetLocalEvent(event);
        event = ucApp2OSDEventTable[event];

        if (event != OSD_NOP_EVENT) {
            if (OSDAppRoutine[event] != NULL) {
                (*OSDAppRoutine[event])();
                usOSDLocalTimer = GetTimerTick();
                OSDConfigKeyBehavior();
            }
        }
    }
}

//******************************************************************************
// Prototype:
//  UCHAR OSDActionDemander(void)
// Parameters:
//  None
// Return:
//  Return OSD event
// Purpose:
//  Acquire system action by OSD state
// Notes:
//  None
//******************************************************************************
UCHAR OSDActionDemander(void)
{
    UCHAR evt;

    OSDTimerRoutine();

    evt = OSDEVT_NONE;

    if (OSDUserUpdate()) {
        evt = OSDEVT_UPD_USR;
    }
    else if (OSDTmgUpdate()) {
        evt = OSDEVT_UPD_TMG;
    }
    else if (OSDSysUpdate()) {
        evt = OSDEVT_UPD_SYS;
    }
    else if (OSDCalUpdate()) {
        evt = OSDEVT_UPD_CAL;
    }
  //  else if (OSDFactoryUpdate()) {
  //      evt = OSDEVT_UPD_CAL;
   // }

    return evt;
}

//
void OSDCancelPreview (UCHAR OSDstate)
{
    Custom_System.ucBFMode = UserData.ucBFMode;
    Custom_System.bOverScan= UserData.bOverScan;
    Custom_System.bSOGOverScan = UserData.bSOGOverScan;
    NvramReadUserData(&UserData);      
    if(OSDstate>=OSD_ITEM_2_4_1_STATE && OSDstate < OSD_ITEM_2_4_END){
        UserSetGamma();
    }
    
    if(OSDstate>=OSD_ITEM_2_5_1_STATE && OSDstate < OSD_ITEM_2_5_END){
        UserSetColorTemp();
    }

    if(OSDstate>=OSD_ITEM_2_9_1_STATE && OSDstate < OSD_ITEM_2_9_END){
        UserSetOD();
    }
    //Picture mode
    if((OSDstate>=OSD_ITEM_3_1_1_STATE && OSDstate < OSD_ITEM_3_1_END)||(OSDstate>=OSD_CUSTKEY_PICTUREMODE_1_STATE && OSDstate < OSD_CUSTKEY_PICTUREMODE_END)){
        if(Custom_System.ucBFMode!=UserData.ucBFMode){
            UserSetBF();        
        }
    }

    if(OSDstate>=OSD_ITEM_3_2_1_STATE && OSDstate < OSD_ITEM_3_2_END){
        SetDemo();
    }

    if(OSDstate>=OSD_ITEM_3_4_1_STATE && OSDstate < OSD_ITEM_3_4_END){
        if(IsComponentInput()){
          if(UserData.bSOGOverScan != Custom_System.bSOGOverScan){
               OSDSetOverScan();
          }
       }
       else{
          if(UserData.bOverScan != Custom_System.bOverScan){
               OSDSetOverScan();
          }
       }
    }
    //Display mode
    if((OSDstate>=OSD_ITEM_3_5_1_STATE && OSDstate < OSD_ITEM_3_5_END)||(OSDstate>=OSD_CUSTKEY_DISPLAYMODE_1_STATE && OSDstate < OSD_CUSTKEY_DISPLAYMODE_END)){
        //if( UserData.ucAspectRatio != Custom_System.ucOSD_preview_temp)
        {
            SetAspRatioSetting();
            UserSetAspectRatio();
        }        
    }

    //HDMI Range & Color format
    if((OSDstate>=OSD_ITEM_3_7_1_STATE && OSDstate < OSD_ITEM_3_7_END)||(OSDstate>=OSD_ITEM_3_6_1_STATE && OSDstate < OSD_ITEM_3_6_END)){
        SetColorSpace();            
    }
    //Mute
    if((OSDstate>=OSD_ITEM_Audio_2_1_STATE && OSDstate < OSD_ITEM_Audio_2_END)||(OSDstate>=OSD_CUSTKEY_MUTE_1_STATE && OSDstate < OSD_CUSTKEY_MUTE_END)){
        UserSetVolumeAndMute();  
    }
    //Audio select
    if(OSDstate>=OSD_ITEM_Audio_3_1_STATE && OSDstate < OSD_ITEM_Audio_3_END){
        OSDAudioSelect();
    }
    //Custom key LBL
    if((OSDstate>=OSD_CUSTKEY_LOWBULELIGHTMODE_1_STATE && OSDstate < OSD_CUSTKEY_LOWBULELIGHTMODE_END)||(OSDstate>=OSD_SUBITEM_3_1_2_STATE_BEG && OSDstate < OSD_SUBITEM_3_1_2_END)){
        SetLBLMode();
    }
    
}

//******************************************************************************
// Prototype:
//  void OSDTimerRoutine(void)
// Parameters:
//  None
// Return:
//  Return OSD event
// Purpose:
//
// Notes:
//  None
//******************************************************************************
void OSDTimerRoutine(void)
{
    if ((UserData.bSmartReminder == ON)&&(GetModeHandleState() == WAIT_MODE_CHANGE)) {
        if ((GetTimerTick()-usOSDSRIntervalTimerL) > 6000) {
            usOSDSRIntervalTimerL = GetTimerTick();
            usOSDSRIntervalTimerH ++;
            if (usOSDSRIntervalTimerH == Custom_System.usErgoTime) {
                usOSDSRIntervalTimerH = 0;
                OSDShowSmarReminder();
            }
        }    
    }

//    if ((usOSDState == OSD_OFF_STATE) && (UserData.bSensEyeDemo == TRUE) && (bOSDShowSenseyeDemo == TRUE)) {
    if ((usOSDState == OSD_OFF_STATE) && (UserData.bSensEyeDemo == TRUE)) {        
        if (UserData.ucBFMode == PICTURE_MODE_MOVIE || 
            UserData.ucBFMode == PICTURE_MODE_PHOTO || 
            UserData.ucBFMode == PICTURE_MODE_GAME 
#if ENABLE_PICTURE_MODE_MBOOK == ON
           ||  UserData.ucBFMode == PICTURE_MODE_MBOOK 
#endif
           ) {
            if(GetModeHandleState()==WAIT_MODE_CHANGE){
                OSDShowSensEyeDemo();
            }
        }
    }

    if (((usOSDState == OSD_OFF_STATE) ) ||
        (usOSDState == OSD_FACT_STATE) ||
        (usOSDState == OSD_SM_STATE) ||        
        (usOSDState == OSD_FITM_STATE)) {
        usOSDLocalTimer = GetTimerTick();
        return;
    }


    if (usOSDState == OSD_INFO_NOCABLE_STATE) {
       //if ((GetTimerTick()-usOSDLocalTimer) > 100) {
        //    OSDMovePosition();
        //    usOSDLocalTimer = GetTimerTick();
        //}
    }
    else if (usOSDState == OSD_INFO_NOSYNC_STATE) {
        // Remove the following for keeping "NO Sync" OSD in center
        // Jude 2009/02/16
        //if ((GetTimerTick()-usOSDLocalTimer) > 100) {
        //    OSDMovePosition();
        //    usOSDLocalTimer = GetTimerTick();
        //}
    }
    else if (usOSDState == OSD_INFO_OUTOFRANCE_STATE) {
        //if ((GetTimerTick()-usOSDLocalTimer) > 3000) {
        //     OSDCloseAll();            
            //OSDMovePosition();
            //usOSDLocalTimer = GetTimerTick();
        //}
    }
    else if (usOSDState == OSD_INFO_OUTOFLIMIT_STATE) {
        if (((bShortOOLTimer == TRUE) && ((GetTimerTick()-usOSDLocalTimer) > 10000)) || ((GetTimerTick()-usOSDLocalTimer) > 60000)) {
        //if ((GetTimerTick()-usOSDLocalTimer) > 60000) {
            bShortOOLTimer = FALSE;
                   OSDAPI_TurnOffOSD();
                   WaitDisVSync();
        }
    }

    else if (usOSDState == OSD_INFO_OSDLOCK_STATE) {
        if ((GetTimerTick()-usOSDLocalTimer) > 3000) {
            OSDCloseAll();
        }
    }

    else if (usOSDState == OSD_INFO_OSDUNLOCKKEY_STATE) {
        if ((GetTimerTick()-usOSDLocalTimer) > 3000) {
            OSDCloseAll();
        }
    }    
    else if (usOSDState == OSD_DIRSRC_STATE) {
          if ((GetTimerTick()-usOSDLocalTimer) > 3000) {
              if (IsNoCableState()){                  
                   OSDEnterNoCable();
              }
           else if (IsNoSyncState()) {                   
                   OSDEnterNoSync();
              }            
              else if (APPIsOutOfLimit()) {// no modechange but out of range
                   OSDEnterOOL();
              }                  
              else  if (IsOutOfRange()) {// no modechange but out of range
                   OSDEnterOOR();
              }    
        else{        
                  OSDCloseAll();              
        }
          }
    }
    else if (usOSDState == OSD_INFO_NOTICE_STATE) {
        if ((GetTimerTick()-usOSDLocalTimer) > 3000) {
                OSDPerformAutoTune();
         // printf("OSD_INFO_NOTICE_STATE %d  %d\r\n", (USHRT)IsNativeTiming(), (USHRT)UserData.bResNotice);
             if((!IsNativeTiming())&&(IsShowResolutionNotice())&&(!IsVideoTiming())){
                     OSDClosed();            
                     usOSDState = OSD_RES_NOTICE_STATE;
                     OSDShowDialog(OSD_DLG_RESNOTE,0);
                     usOSDLocalTimer = GetTimerTick();              
             }
             else{
                   if(IsPreSetModeTiming()||IsVideoTiming()){
                         OSDCloseAll();                
                   } 
                   else{
                         OSDClosed();
                         usOSDState = OSD_INFO_NONPRESET_STATE;
                         OSDShowDialog(OSD_DLG_NONPRESET,0);
                         usOSDLocalTimer = GetTimerTick();
                   }                     
            }
        }
    }
    else if (usOSDState == OSD_INFO_SAVENOTICE_STATE) {//ULEric140331
        if ((GetTimerTick()-usOSDLocalTimer) > 3000) {
            OSDReShowMenu();
        }
    }
    else if (usOSDState == OSD_INFO_SMART_REMINDER_STATE) {
         if ((GetTimerTick()-usOSDLocalTimer) > 990) {
             usOSDLocalTimer = GetTimerTick();
             if (Custom_System.ucErgoDuration != 0) {
                 Custom_System.ucErgoDuration --;
             }
             if (Custom_System.ucErgoDuration == 0) {
                 OSDCloseAll();
           UserGetSmartReminderTimer();
             }
        }        
    }
    else if (usOSDState == OSD_INFO_NONPRESET_STATE) {
         // printf("OSD_INFO_NONPRESET_STATE\r\n");
        if ((GetTimerTick()-usOSDLocalTimer) > 3000) {
                  OSDCloseAll();
        }
    }    
    else if (usOSDState == OSD_RES_NOTICE_STATE) {
          //printf("OSD_RES_NOTICE_STATE\r\n");
        if ((GetTimerTick()-usOSDLocalTimer) > 3000) {
               if(IsPreSetModeTiming()||IsVideoTiming()){
                    OSDCloseAll();                
               } 
               else{
                    OSDClosed(); 
                    usOSDState = OSD_INFO_NONPRESET_STATE;
                    OSDShowDialog(OSD_DLG_NONPRESET,0);
                    usOSDLocalTimer = GetTimerTick();
               }
        }    
    }    

    else if (usOSDState == OSD_INFO_SAVENOTICE_STATE) {//ULEric140331
        if ((GetTimerTick()-usOSDLocalTimer) > 3000) {
            OSDReShowMenu();
        }
    }
    else if (usOSDState == OSD_INFO_SENSEYE_DEMO_STATE) {
        //null
    }
    else {
         if ((GetTimerTick()-usOSDLocalTimer) > 990) {
             usOSDLocalTimer = GetTimerTick();
             if (usOSDTimer != 0) {
                 usOSDTimer --;
             }
             if (usOSDTimer == 0) {
                 OSDCancelPreview(GetOSDState());
                 OSDCloseAll();
             }
             if (IsOutRangeState()) {// no modechange but out of range         
                  OSDEnterOOR();
             }
             if (IsNoSyncState()) {
                  APPResendAppSync();
             }
        }
        if ((GetTimerTick()-usOSDLocalTimer) > usOSDTimer) {
            OSDConfigKeyBehavior(); // Reset key behavior after OSD time out.
        }
    }
}

//******************************************************************************
// Prototype:
//  void OSDConfigTimeout(USHRT timer)
// Parameters:
//  timer   : OSD time out counter
// Return:
//  None
// Purpose:
//  Set OSD time out counter
// Notes:
//  None
//******************************************************************************
void OSDConfigTimeout(USHRT timer)
{
    usOSDTimer = timer;
}

//******************************************************************************
// Prototype:
//  void OSDCloseAll(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Close all OSE
// Notes:
//  None
//******************************************************************************
void OSDCloseAll(void)
{
    usOSDState = OSD_OFF_STATE;
    OSDClosed();
    OSDAPI_SetHVZoom(0);    
}

//******************************************************************************
// Prototype:
//  void OSDUpdateAutoTune(UCHAR pnt)
// Parameters:
//  pnt : percentage of AutoTune
// Return:
//  None
// Purpose:
//  Update AutoTune Progress
// Notes:
//  None
//******************************************************************************
void OSDUpdateAutoTune(UCHAR pnt)
{
    OSDUpdateAutoTuneBar(pnt);
}

//******************************************************************************
// Prototype:
//  static void OSDConfigKeyBehavior(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Set repeat key by OSD status
// Notes:
//  None
//*****************************************************************************
static void OSDConfigKeyBehavior(void)
{
    if ((usOSDState == OSD_OFF_STATE) ||
        (usOSDState == OSD_INFO_OUTOFLIMIT_STATE) ||
        (usOSDState == OSD_INFO_OUTOFRANCE_STATE) ||
        (usOSDState == OSD_INFO_NOSYNC_STATE) ||
        (usOSDState == OSD_INFO_NOCABLE_STATE) ||
        (usOSDState == OSD_INFO_NOTICE_STATE) ||
        (usOSDState == OSD_INFO_SOURCE_STATE)) {
        KeySetRepeatEvent(0xFF, OFF);
        //KeySetMFuncEvent(KEYEVT_AUTO, KEYEVT_INPUT);
    }
    else {
    if(OSDCheckBarAdjItem())//ULEric140409
    {
        KeySetRepeatEvent(KEYEVT_UP, ON);
        KeySetRepeatEvent(KEYEVT_DOWN, ON);
    }else{
        KeySetRepeatEvent(0xFF, OFF);
    }
}

}

//******************************************************************************
// The following are OSD actions
//******************************************************************************

#define MP1CursorPos()   (CursorPos(OSD_MAIN_BEG,OSD_MAIN_1_STATE))
#define MP2CursorPos()   (CursorPos(OSD_MAIN_BEG,OSD_MAIN_2_STATE))
#define MP3CursorPos()   (CursorPos(OSD_MAIN_BEG,OSD_MAIN_3_STATE))
#define MP4CursorPos()   (CursorPos(OSD_MAIN_BEG,OSD_MAIN_4_STATE))

//******************************************************************************
// TopPage menu operation
//******************************************************************************
void OSDEnterTopPageMenu(void)
{
    OSDCloseAll();
    if (UserData.bOSDLock == ON) {
        usOSDState = OSD_INFO_OSDUNLOCKKEY_STATE;
    //show 10 sec menu
       OSDShowDialog(OSD_DLG_OSDUNLOCKKEY, 0);
    }    
    else{
        usOSDState = OSD_TOPPAGE_STATE;
        OSDShowTopPageMenu();
    }
}

void OSDEnterExitKeyMenu(void)
{
    if (Custom_System.bFactory == TRUE) {
        OSDCloseAll();        
        usOSDState = OSD_FACT_STATE;
        //printf("FFF=%d\r\n",(USHRT)OSD_FACT_STATE);
        OSDShowFactory();
    }
    else{
        OSDEnterTopPageMenu();
    }
}

void OSDEnterMenuKeyMenu(void)
{
    if (UserData.bSeviceMenu == TRUE) {//ULEric140331
       OSDCloseAll();    
        usOSDState = OSD_SM_STATE;
    OSDEnterServiceMenu();
    }
    else{
        OSDEnterTopPageMenu();
    }
}

void OSDEnterOSDUnLock(void)
{
    usOSDState = OSD_INFO_OSDLOCK_STATE;
    OSDShowDialog(OSD_DLG_OSDLOCK,0);
    usOSDLocalTimer = GetTimerTick();
}

void OSDUNLOCKKeyMenu(void)
{
     usOSDLocalTimer = GetTimerTick();
}
#if 0
//******************************************************************************
// TopPage UPmenu operation
//******************************************************************************
void OSDUPTopPageMenu(void)
{
    if (Custom_System.bFactory) {
        usOSDState = OSD_FACT_STATE;
        //printf("FFF=%d\r\n",(USHRT)OSD_FACT_STATE);
        OSDShowFactory();
    }
    else{
        usOSDState = OSD_TOPPAGE_STATE;
        OSDShowTopPageMenu();
    }
}
#endif
void OSDExitTopPageMenu(void)
{
    if (usOSDState == OSD_TOPPAGE_STATE){
        OSDBlinkTopPageButton(4);
    }

    //OSDCloseTopPageMenu();
    OSDCloseAll();
}

void OSDExitLBLTopPageMenu(void)
{
    if (usOSDState == OSD_TOPPAGE_STATE){
        OSDBlinkTopPageButton(4);
    }
    UserData.ucLBLMode = Custom_System.ucOSD_preview_temp;
    SetLBLMode();
    //Custom_System.ucOSD_preview_temp = UserData.ucBFMode;
    OSDCloseAll();
}

void OSDItm24ExitTopPageMenu(void)
{
    if (usOSDState == OSD_TOPPAGE_STATE){
        OSDBlinkTopPageButton(4);
    }
    //UserData.ucGammaNum= Custom_System.ucOSD_preview_temp; 
    SetGammaNum(Custom_System.ucOSD_preview_temp);
    UserSetGamma();        
    //OSDCloseTopPageMenu();
    OSDCloseAll();
}

void OSDItm25ExitTopPageMenu(void)
{
    if (usOSDState == OSD_TOPPAGE_STATE){
        OSDBlinkTopPageButton(4);
    }
    UserData.ucColorTemp = Custom_System.ucOSD_preview_temp;    
    UserSetColorTemp();        
    //OSDCloseTopPageMenu();
    OSDCloseAll();
}

void OSDItm29ExitTopPageMenu(void)
{
    if (usOSDState == OSD_TOPPAGE_STATE){
        OSDBlinkTopPageButton(4);
    }
    UserData.ucODMode = Custom_System.ucOSD_preview_temp;
    UserSetOD();        
    //OSDCloseTopPageMenu();
    OSDCloseAll();
}


void OSDItm31ExitTopPageMenu(void)
{

    if (usOSDState == OSD_TOPPAGE_STATE){
        OSDBlinkTopPageButton(4);
    }
    if(Custom_System.ucOSD_preview_temp!=UserData.ucBFMode){
        UserData.ucBFMode = Custom_System.ucOSD_preview_temp;    
        UserSetBF();        
    }
    //OSDCloseTopPageMenu();
    OSDCloseAll();
}

void OSDItm32ExitTopPageMenu(void)
{
    if (usOSDState == OSD_TOPPAGE_STATE){
        OSDBlinkTopPageButton(4);
    }
    UserData.bSensEyeDemo = Custom_System.ucOSD_preview_temp;
    SetDemo();
    OSDCloseAll();
}


void OSDItm34ExitTopPageMenu(void)
{
    if (usOSDState == OSD_TOPPAGE_STATE){
        OSDBlinkTopPageButton(4);
    }
    
    if(IsComponentInput()){
      if(UserData.bSOGOverScan != Custom_System.ucOSD_preview_temp){
           UserData.bSOGOverScan = Custom_System.ucOSD_preview_temp;
           OSDSetOverScan();
      }
   }
   else{
      if(UserData.bOverScan != Custom_System.ucOSD_preview_temp){
           UserData.bOverScan = Custom_System.ucOSD_preview_temp;
           OSDSetOverScan();
      }
   }
   OSDCloseAll();
}

void OSDItm35ExitTopPageMenu(void)
{
    if (usOSDState == OSD_TOPPAGE_STATE){
        OSDBlinkTopPageButton(4);
    }
    
    if( UserData.ucAspectRatio != Custom_System.ucOSD_preview_temp){
        UserData.ucAspectRatio = Custom_System.ucOSD_preview_temp;
        SetAspRatioSetting();
        UserSetAspectRatio();
    }        
    OSDCloseAll();
}

void OSDItm36ExitTopPageMenu(void)
{
    if (usOSDState == OSD_TOPPAGE_STATE){
        OSDBlinkTopPageButton(4);
    }
    UserData.bColorFormat = Custom_System.ucOSD_preview_temp;
    OSDCloseAll();
}

void OSDItm37ExitTopPageMenu(void)
{
    if (usOSDState == OSD_TOPPAGE_STATE){
        OSDBlinkTopPageButton(4);
    }
    UserData.ucHDMIRGBRange = Custom_System.ucOSD_preview_temp;    
    SetColorSpace();    
    OSDCloseAll();
}

void OSDAudio2ExitTopPageMenu(void)
{
    if (usOSDState == OSD_TOPPAGE_STATE){
        OSDBlinkTopPageButton(4);
    }
    UserData.bAudioMute = Custom_System.ucOSD_preview_temp;    
    UserSetVolumeAndMute();  
    OSDCloseAll();
}

void OSDAudio3ExitTopPageMenu(void)
{
    if (usOSDState == OSD_TOPPAGE_STATE){
        OSDBlinkTopPageButton(4);
    }
    
    if(UserData.ucInputSource == INPUT_SC_HDMI){
        UserData.ucHDMIAudioSelect = Custom_System.ucOSD_preview_temp;        
    }
    else{
        UserData.ucAudioSelect = Custom_System.ucOSD_preview_temp;
    }    
    OSDAudioSelect();    
    OSDCloseAll();
}

void OSDItm45ExitTopPageMenu(void)
{
    if (usOSDState == OSD_TOPPAGE_STATE){
        OSDBlinkTopPageButton(4);
    }
    UserData.bDDCCI = Custom_System.ucOSD_preview_temp;
    OSDCloseAll();
}

void OSDItm46ExitTopPageMenu(void)
{
    if (usOSDState == OSD_TOPPAGE_STATE){
        OSDBlinkTopPageButton(4);
    }
    UserData.bDPAutoSwitch = Custom_System.ucOSD_preview_temp;
    OSDCloseAll();
}

void OSDItm47ExitTopPageMenu(void)
{
    if (usOSDState == OSD_TOPPAGE_STATE){
        OSDBlinkTopPageButton(4);
    }
    UserData.bHDMIAutoSwitch = Custom_System.ucOSD_preview_temp;
    OSDCloseAll();
}

void OSDItm49ExitTopPageMenu(void)
{
    if (usOSDState == OSD_TOPPAGE_STATE){
        OSDBlinkTopPageButton(4);
    }
    UserData.bResNotice = Custom_System.ucOSD_preview_temp;
    OSDCloseAll();
}


void OSDEnterCustomer1Menu(void)
{
    ucCustomerKeyType = 0;
    if ((((UserData.ucBFMode == PICTURE_MODE_ECO) || ((UserData.ucDynamicContrast != 0)&&((UserData.ucBFMode == PICTURE_MODE_GAME)||(UserData.ucBFMode == PICTURE_MODE_MOVIE)||(UserData.ucBFMode == PICTURE_MODE_PHOTO)))) && 
        (UserData.ucCustomerKey1 == CUSTOMER_KEY_BRIGHTNESS || UserData.ucCustomerKey1 == CUSTOMER_KEY_CONTRAST)) ||
        (
        
		#if !lrd_dis_benq
        ((GetScalerSyncMode(_MainChannel) == DIG_SYNC) ||IsComponentInput()) &&
		#endif
		(UserData.ucCustomerKey1 == CUSTOMER_KEY_AUTOADJUSTMENT))) {
    }
    else {
          OSDBlinkTopPageButton(0);
    }
    OSDShowCustomerMenu(UserData.ucCustomerKey1);
}
/*
void OSDConfirmCustomer1Menu(void)
{
    OSDConfirmCustomerMenu(UserData.ucCustomerKey1);
}

void OSDExitCustomer1Menu(void)
{
    OSDExitCustomerMenu(UserData.ucCustomerKey1);
    usOSDState = OSD_TOPPAGE_STATE;
    OSDShowTopPageMenu();
}
*/
void OSDEnterCustomer2Menu(void)
{
    ucCustomerKeyType = 1;
    if ((((UserData.ucBFMode == PICTURE_MODE_ECO) || ((UserData.ucDynamicContrast != 0)&&((UserData.ucBFMode == PICTURE_MODE_GAME)||(UserData.ucBFMode == PICTURE_MODE_MOVIE)||(UserData.ucBFMode == PICTURE_MODE_PHOTO)))) && 
        (UserData.ucCustomerKey2 == CUSTOMER_KEY_BRIGHTNESS || UserData.ucCustomerKey2 == CUSTOMER_KEY_CONTRAST)) ||
        (
        #if !lrd_dis_benq
        ((GetScalerSyncMode(_MainChannel) == DIG_SYNC) ||IsComponentInput()) &&
		#endif
		 (UserData.ucCustomerKey2 == CUSTOMER_KEY_AUTOADJUSTMENT))) {
    }
    else {
         OSDBlinkTopPageButton(1);
    }
    OSDShowCustomerMenu(UserData.ucCustomerKey2);
}

void OSDConfirmCustomerMenu(void)
{

    if(ucCustomerKeyType == 0){
        OSDConfirmCustomerKeyMenu(UserData.ucCustomerKey1);
    }
    else if(ucCustomerKeyType == 1){
        OSDConfirmCustomerKeyMenu(UserData.ucCustomerKey2);        
    }
    else{// 2
        OSDConfirmCustomerKeyMenu(UserData.ucCustomerKey3);
    }
}


void OSDExitCustomerMenu(void)
{
    if(ucCustomerKeyType == 0){
        OSDExitCustomerKeyMenu(UserData.ucCustomerKey1);
    }
    else if(ucCustomerKeyType == 1){
        OSDExitCustomerKeyMenu(UserData.ucCustomerKey2);        
    }
    else{// 2
        OSDExitCustomerKeyMenu(UserData.ucCustomerKey3);
    }
    
    usOSDState = OSD_TOPPAGE_STATE;
    OSDShowTopPageMenu();
}

void OSDEnterCustomer3Menu(void)
{
    ucCustomerKeyType = 2;
    if ((((UserData.ucBFMode == PICTURE_MODE_ECO) || ((UserData.ucDynamicContrast != 0)&&((UserData.ucBFMode == PICTURE_MODE_GAME)||(UserData.ucBFMode == PICTURE_MODE_MOVIE)||(UserData.ucBFMode == PICTURE_MODE_PHOTO)))) && 
        (UserData.ucCustomerKey3 == CUSTOMER_KEY_BRIGHTNESS || UserData.ucCustomerKey3 == CUSTOMER_KEY_CONTRAST)) ||
        
        (
        #if !lrd_dis_benq
        ((GetScalerSyncMode(_MainChannel) == DIG_SYNC) ||IsComponentInput()) && 
		#endif
		(UserData.ucCustomerKey3 == CUSTOMER_KEY_AUTOADJUSTMENT))) {
    }
    else {
        OSDBlinkTopPageButton(2);
    }
    OSDShowCustomerMenu(UserData.ucCustomerKey3);
}
/*
void OSDExitCustomer3Menu(void)
{
    OSDExitCustomerMenu(UserData.ucCustomerKey3);
    usOSDState = OSD_TOPPAGE_STATE;
    OSDShowTopPageMenu();
}

void OSDConfirmCustomer3Menu(void)
{
    OSDConfirmCustomerMenu(UserData.ucCustomerKey3);
}
*/
void OSDShowCustomerMenu(UCHAR Key_Setting)
{
    switch (Key_Setting) {
        case CUSTOMER_KEY_AUTOADJUSTMENT:
			#if !lrd_dis_benq
            if ((GetScalerSyncMode(_MainChannel) == DIG_SYNC)||IsComponentInput()) {
                return;
            }
			#endif
         OSDClosed();
            OSDPerformAuto();
            //OSDShowAutoAdjustmentMenu();
            //usOSDState = OSD_OFF_STATE;
        break;
        case CUSTOMER_KEY_DISPLAYMODE:
            usOSDState = OSD_CUSTKEY_DISPLAYMODE_1_STATE + UserData.ucAspectRatio;
            Custom_System.ucOSD_preview_temp = UserData.ucAspectRatio;
            OSDShowDisplayModeMenu();
        break;
        case CUSTOMER_KEY_PICTUREMODE:
            usOSDState = OSD_CUSTKEY_PICTUREMODE_1_STATE + UserData.ucBFMode;
            Custom_System.ucOSD_preview_temp = UserData.ucBFMode;
            OSDShowPictureModeMenu();
        break;
        case CUSTOMER_KEY_INPUT:
            usOSDState = OSD_CUSTKEY_INPUT_1_STATE + GetInputPortIndex(UserGetInputSource());
            Custom_System.ucOSD_preview_temp = UserData.ucInputSource;            
            OSDShowInputMenu();
        break;
        case CUSTOMER_KEY_BRIGHTNESS:
            if (UserData.ucBFMode == PICTURE_MODE_ECO) {
                return;
            }
            if ((UserData.ucDynamicContrast != 0)&&((UserData.ucBFMode == PICTURE_MODE_GAME)||(UserData.ucBFMode == PICTURE_MODE_MOVIE)||(UserData.ucBFMode == PICTURE_MODE_PHOTO))) {
                return;
            }    
            usOSDState = OSD_CUSTKEY_BRIGHTNESS_STATE;
            OSDShowBrightnessMenu();
        break;
        case CUSTOMER_KEY_CONTRAST:
            if (UserData.ucBFMode == PICTURE_MODE_ECO) {
                return;
            }
            if ((UserData.ucDynamicContrast != 0)&&((UserData.ucBFMode == PICTURE_MODE_GAME)||(UserData.ucBFMode == PICTURE_MODE_MOVIE)||(UserData.ucBFMode == PICTURE_MODE_PHOTO))) {
                return;
            }
            usOSDState = OSD_CUSTKEY_CONTRAST_STATE;
            OSDShowContrastMenu();
        break;
     //ULEric140402
     case CUSTOMER_KEY_LOWBULELIGHTMODE:
            usOSDState = OSD_CUSTKEY_LOWBULELIGHTMODE_1_STATE + UserData.ucLBLMode;
            Custom_System.ucOSD_preview_temp = UserData.ucLBLMode;
            OSDShowLBLMenu();
            if(UserData.ucBFMode != PICTURE_MODE_LOW_BL){
            UserData.ucBFMode = PICTURE_MODE_LOW_BL;    
            UserSetBF();
            }
            SetOSDUpdUsrFlag();
        
     break;
     case CUSTOMER_KEY_VOLUME:
            usOSDState = OSD_CUSTKEY_VOLUME_STATE;
            OSDShowVolumeMenu();
     break;
     case CUSTOMER_KEY_MUTE:
        if(UserData.bAudioMute){
            usOSDState = OSD_CUSTKEY_MUTE_1_STATE;//ON
        }
        else{
            usOSDState = OSD_CUSTKEY_MUTE_2_STATE;//OFF
        }
        Custom_System.ucOSD_preview_temp = UserData.bAudioMute;
        OSDShowMuteMenu();
     break;
     case CUSTOMER_KEY_SMARTREMINDER://ULEric140411
        if(UserData.bSmartReminder)
             usOSDState = OSD_CUSTKEY_SMARTREMINDER_1_STATE;//ON
        else
            usOSDState = OSD_CUSTKEY_SMARTREMINDER_2_STATE;//OFF
        Custom_System.ucOSD_preview_temp = UserData.bSmartReminder;
        OSDShowSmartReminderMenu();
     break;     
    }
}


void OSDExitCustomerKeyMenu(UCHAR Key_Setting)
{
    switch (Key_Setting) {
        case CUSTOMER_KEY_AUTOADJUSTMENT:
        break;
        case CUSTOMER_KEY_DISPLAYMODE:
            if( UserData.ucAspectRatio != Custom_System.ucOSD_preview_temp){
                UserData.ucAspectRatio = Custom_System.ucOSD_preview_temp;
                SetAspRatioSetting();
                UserSetAspectRatio();
            }        
            break;
        case CUSTOMER_KEY_PICTUREMODE:
            if(Custom_System.ucOSD_preview_temp!=UserData.ucBFMode){
                UserData.ucBFMode = Custom_System.ucOSD_preview_temp;
                UserSetBF();
            }
            break;
        case CUSTOMER_KEY_INPUT:
            UserData.ucInputSource = Custom_System.ucOSD_preview_temp;
            break;
        case CUSTOMER_KEY_BRIGHTNESS:
            break;
        case CUSTOMER_KEY_CONTRAST:
            break;
        case CUSTOMER_KEY_LOWBULELIGHTMODE:
            UserData.ucLBLMode = Custom_System.ucOSD_preview_temp;
            SetLBLMode();
            break;
         case CUSTOMER_KEY_VOLUME:
             break;
         case CUSTOMER_KEY_MUTE:
            UserData.bAudioMute = Custom_System.ucOSD_preview_temp;            
            UserSetVolumeAndMute();    
            break;
         case CUSTOMER_KEY_SMARTREMINDER:
            UserData.bSmartReminder = Custom_System.ucOSD_preview_temp;
         break;     
    }
}

void OSDConfirmCustomerKeyMenu(UCHAR Key_Setting)
{
    switch (Key_Setting) {
        case CUSTOMER_KEY_AUTOADJUSTMENT:
        case CUSTOMER_KEY_BRIGHTNESS:
        case CUSTOMER_KEY_CONTRAST:
        case CUSTOMER_KEY_VOLUME:
            break;
     
        case CUSTOMER_KEY_DISPLAYMODE:
             OSDEnterConfirDisplayMode();
             usOSDState = OSD_TOPPAGE_STATE;
             OSDShowTopPageMenu();                     
            break;                 
        case CUSTOMER_KEY_PICTUREMODE: 
             OSDEnterConfirPictMode();
             usOSDState = OSD_TOPPAGE_STATE;
             OSDShowTopPageMenu();             
            break;                 
        case CUSTOMER_KEY_INPUT:     
             OSDEnterConfirInput();
          if(usOSDState!=OSD_OFF_STATE)//ULEric140416
          {
             usOSDState = OSD_TOPPAGE_STATE;
             OSDShowTopPageMenu();         
              }            
            break;         
     case CUSTOMER_KEY_LOWBULELIGHTMODE: 
             OSDEnterConfirLBL();
             usOSDState = OSD_TOPPAGE_STATE;
             OSDShowTopPageMenu();              
     break;              
     case CUSTOMER_KEY_MUTE:
             OSDEnterConfirAudioMute();
             usOSDState = OSD_TOPPAGE_STATE;
             OSDShowTopPageMenu();         
     break;              
     case CUSTOMER_KEY_SMARTREMINDER:
         OSDEnterConfirSmartReminder();
        usOSDState = OSD_TOPPAGE_STATE;
              OSDShowTopPageMenu();         
     break;     
    }
    SetOSDUpdUsrFlag();
}


//******************************************************************************
// Main menu operation
//******************************************************************************
void OSDEnterMainMenu(void)
{
    if (UserData.bSeviceMenu == TRUE) {//ULEric140331
        OSDCloseAll();
        usOSDState = OSD_SM_STATE;
        OSDEnterServiceMenu();
    }
    else{
        usOSDState = OSD_MAIN_1_STATE;
        OSDBlinkTopPageButton(3);
        OSDShowMainMenu();
    }
}

void OSDEnterConfirInput(void)
{
    UCHAR SoucerIndex, OSDindex;
//    if (UserData.ucInputSource != UserGetInputSource()) {
//        UserData.ucInputSource = UserGetInputSource();
//     }
    OSDindex = GetOSDState() - OSD_CUSTKEY_INPUT_1_STATE;
    SoucerIndex = GetInputPortIndex(UserData.ucInputSource);
    if(OSDindex != SoucerIndex){
        UserData.ucInputSource = GetInputPortName(OSDindex);
        OSDConfirmInput();
        OSDCloseAll();        
    }
    else{
    }
}

//ULEric140402
void OSDEnterConfirAudioMute(void)
{    
    OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
    OSDAPI_WriteXYChar(TRUE, 8+11, 5+((!Custom_System.ucOSD_preview_temp)*2), _SPACE_);//Clear Hook icon
    if (GetOSDState() - OSD_CUSTKEY_MUTE_1_STATE) {
        UserData.bAudioMute = FALSE;
    }
    else {
        UserData.bAudioMute = TRUE;
        
    }
    OSDAPI_SetFontAttr(SelectedStringColor_256);
    OSDAPI_WriteXYChar(TRUE, 8+11, 5+((!UserData.bAudioMute)*2), Hook_Icon);//Update Hook icon
    UserSetVolumeAndMute();
    SetOSDUpdUsrFlag();
}

void OSDEnterConfirSmartReminder(void)
{    
    OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
    OSDAPI_WriteXYChar(TRUE, 8+11, 5+((!Custom_System.ucOSD_preview_temp)*2), _SPACE_);//Clear Hook icon
    if (GetOSDState() - OSD_CUSTKEY_SMARTREMINDER_1_STATE) {
        UserData.bSmartReminder = FALSE;
    }
    else {
        UserData.bSmartReminder = TRUE;
    }
    OSDAPI_SetFontAttr(SelectedStringColor_256);
    OSDAPI_WriteXYChar(TRUE, 8+11, 5+((!UserData.bSmartReminder)*2), Hook_Icon);//Update Hook icon
    SetOSDUpdUsrFlag();
}

void OSDEnterConfirLBL(void)
{    
    OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
    OSDAPI_WriteXYChar(TRUE, 8+11, 5+(Custom_System.ucOSD_preview_temp*2), _SPACE_);//Clear Hook icon

    UserData.ucLBLMode = (GetOSDState() - OSD_CUSTKEY_LOWBULELIGHTMODE_1_STATE);
    OSDAPI_SetFontAttr(SelectedStringColor_256);
    OSDAPI_WriteXYChar(TRUE, 8+11, 5+((UserData.ucLBLMode)*2), Hook_Icon);//Update Hook icon
       //UserData.ucBFMode = PICTURE_MODE_LOW_BL;    
    //UserSetBF();
        SetLBLMode();
    SetOSDUpdUsrFlag();
}

void OSDEnterConfirDisplayMode(void)
{    
    OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
    OSDAPI_WriteXYChar(TRUE, 8+11, 5+(Custom_System.ucOSD_preview_temp*2), _SPACE_);//Clear Hook icon
    UserData.ucAspectRatio = (GetOSDState() - OSD_CUSTKEY_DISPLAYMODE_1_STATE);
    OSDAPI_SetFontAttr(SelectedStringColor_256);
    OSDAPI_WriteXYChar(TRUE, 8+11, 5+(UserData.ucAspectRatio*2), Hook_Icon);//Update Hook icon
}

void OSDEnterConfirPictMode(void)
{    
    OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
    OSDAPI_WriteXYChar(TRUE, 8+11, 5+(Custom_System.ucOSD_preview_temp*2), _SPACE_);//Clear Hook icon
    UserData.ucBFMode = (GetOSDState() - OSD_CUSTKEY_PICTUREMODE_1_STATE);
    OSDAPI_SetFontAttr(SelectedStringColor_256);
    OSDAPI_WriteXYChar(TRUE, 8+11, 5+(UserData.ucBFMode*2), Hook_Icon);//Update Hook icon
}

void OSDExitMainMenu(void)
{
    OSDClosed();
    usOSDState = OSD_TOPPAGE_STATE;
    OSDShowTopPageMenu();
}

void OSDMainMenuUp(void)
{
    OSDUnselectLayer1Item(CursorPos(OSD_MAIN_BEG,usOSDState), TRUE);
    while (1) {
        usOSDState = PrevState(OSD_MAIN_BEG,OSD_MAIN_END,usOSDState);
        if (OSDIsMainItemValid(CursorPos(OSD_MAIN_BEG,usOSDState)) == TRUE)
            break;
    }
    OSDSelectLayer1Item(CursorPos(OSD_MAIN_BEG,usOSDState));
}

void OSDMainMenuDown(void)
{
    OSDUnselectLayer1Item(CursorPos(OSD_MAIN_BEG,usOSDState), FALSE);
    while (1) {
        usOSDState = NextState(OSD_MAIN_BEG,OSD_MAIN_END,usOSDState);
        if (OSDIsMainItemValid(CursorPos(OSD_MAIN_BEG,usOSDState)) == TRUE)
            break;
    }
    OSDSelectLayer1Item(CursorPos(OSD_MAIN_BEG,usOSDState));
}

//******************************************************************************
// Submenu 1 Operation
//******************************************************************************
void OSDEnterSubMenu1(void)
{
    OSDClrLayer1Menu(CursorPos(OSD_MAIN_BEG,usOSDState));
    usOSDState = OSD_MAIN_1_1_STATE;
    while (1) {
        if (OSDIsSubItemValid(CursorPos(OSD_MAIN_END,usOSDState)) == TRUE) {
            break;
        }

        if (usOSDState == OSD_MAIN_1_END-1) {
           SetOSDState(OSD_MAIN_1_1_STATE);
           return;
        }

        SetOSDState(NextState(OSD_MAIN_END,OSD_MAIN_1_END,usOSDState));
    }
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_END,usOSDState), FALSE);    
}

void OSDExitSubMenu1(void)
{
    OSDFocusMain(CursorPos(OSD_MAIN_1_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_1_STATE;
}

void OSDSubMenuUp1(void)//ULEric140415
{
    USHRT usTempStatus= usOSDState;
    //OSDUnselectLayer2Item(CursorPos(OSD_MAIN_END,usOSDState), TRUE);
    while (1) {
       usOSDState = PrevState(OSD_MAIN_END,OSD_MAIN_1_END,usOSDState);
        if (OSDIsSubItemValid(CursorPos(OSD_MAIN_END,usOSDState)) == TRUE)
            break;
    }
    if(usTempStatus == usOSDState)    
    return;
    OSDUnselectLayer2Item(CursorPos(OSD_MAIN_END,usTempStatus), TRUE);    
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_END,usOSDState), TRUE);
}

void OSDSubMenuDown1(void)//ULEric140415
{
    USHRT usTempStatus= usOSDState;    
    //OSDUnselectLayer2Item(CursorPos(OSD_MAIN_END,usOSDState), FALSE);
    while (1) {
        usOSDState = NextState(OSD_MAIN_END,OSD_MAIN_1_END,usOSDState);
        if (OSDIsSubItemValid(CursorPos(OSD_MAIN_END,usOSDState)) == TRUE)
            break;
    }
    if(usTempStatus == usOSDState)    
    return;    
    OSDUnselectLayer2Item(CursorPos(OSD_MAIN_END,usTempStatus), FALSE);
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_END,usOSDState), FALSE);
}

//******************************************************************************
// Submenu 2 Operation
//******************************************************************************
void OSDEnterSubMenu2(void)
{
    OSDClrLayer1Menu(CursorPos(OSD_MAIN_BEG,usOSDState));
    usOSDState = OSD_MAIN_2_1_STATE;
    while (1) {
        if (OSDIsSubItemValid(CursorPos(OSD_MAIN_2_1_STATE,usOSDState)) == TRUE) {
            break;
        }
        if (usOSDState == OSD_MAIN_2_END-1) {
           SetOSDState(OSD_MAIN_2_1_STATE);
           return;
        }
        SetOSDState(NextState(OSD_MAIN_2_1_STATE,OSD_MAIN_2_END,usOSDState));
    }
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_2_1_STATE,usOSDState), FALSE);    
}

void OSDExitSubMenu2(void)
{
    OSDFocusMain(CursorPos(OSD_MAIN_2_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_2_STATE;
}

void OSDSubMenuUp2(void)
{
#if FORCE_NON_CIRCLE_ACTION == ON
    if (usOSDState <= OSD_MAIN_1_END||((usOSDState <= OSD_MAIN_2_3_STATE)&&(!OSDIsSubItemValid(OSD_PICTURE_BRIGHTNESS)))){//ULEric140415
        return;
      }
#endif // FORCE_NON_CIRCLE_ACTION

    OSDUnselectLayer2Item(CursorPos(OSD_MAIN_1_END,usOSDState), TRUE);
    while (1) {
#if FORCE_NON_CIRCLE_ACTION == ON
        usOSDState = NonCirclePrevState(OSD_MAIN_1_END,OSD_MAIN_2_END,usOSDState);
#else
        usOSDState = PrevState(OSD_MAIN_1_END,OSD_MAIN_2_END,usOSDState);
#endif
        if (OSDIsSubItemValid(CursorPos(OSD_MAIN_1_END,usOSDState)) == TRUE)
            break;
    }
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_1_END,usOSDState), TRUE);
}

void OSDSubMenuDown2(void)
{
#if FORCE_NON_CIRCLE_ACTION == ON
    if (usOSDState >= OSD_MAIN_2_END-1)
        return;
#endif // FORCE_NON_CIRCLE_ACTION

    OSDUnselectLayer2Item(CursorPos(OSD_MAIN_1_END,usOSDState), FALSE);
    while (1) {
#if FORCE_NON_CIRCLE_ACTION == ON
        usOSDState = NonCircleNextState(OSD_MAIN_1_END,OSD_MAIN_2_END,usOSDState);
#else
        usOSDState = NextState(OSD_MAIN_1_END,OSD_MAIN_2_END,usOSDState);
#endif
        if (OSDIsSubItemValid(CursorPos(OSD_MAIN_1_END,usOSDState)) == TRUE)
            break;
    }
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_1_END,usOSDState), FALSE);
}

//******************************************************************************
// Submenu 3 Operation
//******************************************************************************
void OSDEnterSubMenu3(void)
{
    OSDClrLayer1Menu(CursorPos(OSD_MAIN_BEG,usOSDState));
    usOSDState = OSD_MAIN_3_1_STATE;
    while (1) {
        if (OSDIsSubItemValid(CursorPos(OSD_MAIN_3_1_STATE,usOSDState)) == TRUE) {
            break;
        }
        if (usOSDState == OSD_MAIN_3_END-1) {
           SetOSDState(OSD_MAIN_3_1_STATE);
           return;
        }
        SetOSDState(NextState(OSD_MAIN_3_1_STATE,OSD_MAIN_3_END,usOSDState));
    }
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_3_1_STATE,usOSDState), FALSE);    
}

void OSDExitSubMenu3(void)
{
    OSDFocusMain(CursorPos(OSD_MAIN_3_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_3_STATE;
    //ClrLayer4();//Justin 140326
}

void OSDSubMenuUp3(void)
{
    OSDUnselectLayer2Item(CursorPos(OSD_MAIN_2_END,usOSDState), TRUE);
    while (1) {
        usOSDState = PrevState(OSD_MAIN_2_END,OSD_MAIN_3_END,usOSDState);
        if (OSDIsSubItemValid(CursorPos(OSD_MAIN_2_END,usOSDState)) == TRUE)
            break;
    }
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_2_END,usOSDState), TRUE);
}

void OSDSubMenuDown3(void)
{
    OSDUnselectLayer2Item(CursorPos(OSD_MAIN_2_END,usOSDState), FALSE);
    while (1) {
        usOSDState = NextState(OSD_MAIN_2_END,OSD_MAIN_3_END,usOSDState);
        if (OSDIsSubItemValid(CursorPos(OSD_MAIN_2_END,usOSDState)) == TRUE)
            break;
    }
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_2_END,usOSDState), FALSE);
}

//******************************************************************************
// Submenu Audio Operation
//******************************************************************************
void OSDEnterSubMenuAudio(void)
{
    OSDClrLayer1Menu(CursorPos(OSD_MAIN_BEG,usOSDState));
    usOSDState = OSD_MAIN_Audio_1_STATE;
    while (1) {
        if (OSDIsSubItemValid(CursorPos(OSD_MAIN_Audio_1_STATE,usOSDState)) == TRUE) {
            break;
        }
        if (usOSDState == OSD_MAIN_Audio_END-1) {
           SetOSDState(OSD_MAIN_Audio_1_STATE);
           return;
        }
        SetOSDState(NextState(OSD_MAIN_Audio_1_STATE,OSD_MAIN_Audio_END,usOSDState));
    }
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_Audio_1_STATE,usOSDState), FALSE);    
}

void OSDExitSubMenuAudio(void)
{
    OSDFocusMain(CursorPos(OSD_MAIN_Audio_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_Audio_STATE;
}

void OSDSubMenuUpAudio(void)
{
#if 0//FORCE_NON_CIRCLE_ACTION == ON
    if (usOSDState <= OSD_MAIN_3_END)
        return;
#endif // FORCE_NON_CIRCLE_ACTION

    OSDUnselectLayer2Item(CursorPos(OSD_MAIN_3_END,usOSDState), TRUE);
    while (1) {
#if 0//FORCE_NON_CIRCLE_ACTION == ON
        usOSDState = NonCirclePrevState(OSD_MAIN_3_END,OSD_MAIN_Audio_END,usOSDState);
#else
        usOSDState = PrevState(OSD_MAIN_3_END,OSD_MAIN_Audio_END,usOSDState);
#endif
        if (OSDIsSubItemValid(CursorPos(OSD_MAIN_3_END,usOSDState)) == TRUE)
            break;
    }
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_3_END,usOSDState), TRUE);
}

void OSDSubMenuDownAudio(void)
{
#if 0//FORCE_NON_CIRCLE_ACTION == ON
    if (usOSDState >= OSD_MAIN_4_END-1)
        return;
#endif // FORCE_NON_CIRCLE_ACTION

    OSDUnselectLayer2Item(CursorPos(OSD_MAIN_3_END,usOSDState), FALSE);
    while (1) {
#if 0//FORCE_NON_CIRCLE_ACTION == ON
        usOSDState = NonCircleNextState(OSD_MAIN_3_END,OSD_MAIN_Audio_END,usOSDState);
#else
        usOSDState = NextState(OSD_MAIN_3_END,OSD_MAIN_Audio_END,usOSDState);
#endif
        if (OSDIsSubItemValid(CursorPos(OSD_MAIN_3_END,usOSDState)) == TRUE)
            break;
    }
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_3_END,usOSDState), FALSE);
}

//******************************************************************************
// Submenu 4 Operation
//******************************************************************************
void OSDEnterSubMenu4(void)
{
    OSDClrLayer1Menu(CursorPos(OSD_MAIN_BEG,usOSDState));
    usOSDState = OSD_MAIN_4_1_STATE;
    while (1) {
        if (OSDIsSubItemValid(CursorPos(OSD_MAIN_4_1_STATE,usOSDState)) == TRUE) {
            break;
        }
        if (usOSDState == OSD_MAIN_4_END-1) {
           SetOSDState(OSD_MAIN_4_1_STATE);
           return;
        }
        SetOSDState(NextState(OSD_MAIN_4_1_STATE,OSD_MAIN_4_END,usOSDState));
    }
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_4_1_STATE,usOSDState), FALSE);    
}

void OSDExitSubMenu4(void)
{
    OSDFocusMain(CursorPos(OSD_MAIN_4_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_4_STATE;
    //ClrLayer4();//Justin 140326
}

void OSDSubMenuUp4(void)
{
#if FORCE_NON_CIRCLE_ACTION == ON
    if (usOSDState <= OSD_MAIN_Audio_END)//ULEric140407
        return;
#endif // FORCE_NON_CIRCLE_ACTION

    OSDUnselectLayer2Item(CursorPos(OSD_MAIN_Audio_END,usOSDState), TRUE);
    while (1) {
#if FORCE_NON_CIRCLE_ACTION == ON
        usOSDState = NonCirclePrevState(OSD_MAIN_Audio_END,OSD_MAIN_4_END,usOSDState);
#else
        usOSDState = PrevState(OSD_MAIN_Audio_END,OSD_MAIN_4_END,usOSDState);
#endif
        if (OSDIsSubItemValid(CursorPos(OSD_MAIN_Audio_END,usOSDState)) == TRUE)
            break;
    }
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_Audio_END,usOSDState), TRUE);
}

void OSDSubMenuDown4(void)
{
#if FORCE_NON_CIRCLE_ACTION == ON
    if (usOSDState >= OSD_MAIN_4_END-1)
        return;
#endif // FORCE_NON_CIRCLE_ACTION

    OSDUnselectLayer2Item(CursorPos(OSD_MAIN_Audio_END,usOSDState), FALSE);
    while (1) {
#if FORCE_NON_CIRCLE_ACTION == ON
        usOSDState = NonCircleNextState(OSD_MAIN_Audio_END,OSD_MAIN_4_END,usOSDState);
#else
        usOSDState = NextState(OSD_MAIN_Audio_END,OSD_MAIN_4_END,usOSDState);
#endif
        if (OSDIsSubItemValid(CursorPos(OSD_MAIN_Audio_END,usOSDState)) == TRUE)
            break;
    }
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_Audio_END,usOSDState), FALSE);
}

//******************************************************************************
// Submenu Audio Operation
//******************************************************************************
void OSDEnterSubMenuErgo(void)
{
    OSDClrLayer1Menu(CursorPos(OSD_MAIN_BEG,usOSDState));
    usOSDState = OSD_MAIN_ERGO_1_STATE;
    while (1) {
        if (OSDIsSubItemValid(CursorPos(OSD_MAIN_ERGO_1_STATE,usOSDState)) == TRUE) {
            break;
        }
        if (usOSDState == OSD_MAIN_ERGO_END-1) {
           SetOSDState(OSD_MAIN_ERGO_1_STATE);
           return;
        }
        SetOSDState(NextState(OSD_MAIN_ERGO_1_STATE,OSD_MAIN_ERGO_END,usOSDState));
    }
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_ERGO_1_STATE,usOSDState), FALSE);    
}

void OSDExitSubMenuErgo(void)
{
    OSDFocusMain(CursorPos(OSD_MAIN_ERGO_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_ERGO_STATE;
}

void OSDSubMenuUpErgo(void)
{
    if(UserData.bSmartReminder == ON){
        OSDUnselectLayer2Item(CursorPos(OSD_MAIN_4_END,usOSDState), TRUE);
        while (1) {
            usOSDState = PrevState(OSD_MAIN_4_END,OSD_MAIN_ERGO_END,usOSDState);
            if (OSDIsSubItemValid(CursorPos(OSD_MAIN_4_END,usOSDState)) == TRUE)
                break;
        }
        OSDSelectLayer2Item(CursorPos(OSD_MAIN_4_END,usOSDState), TRUE);
    }
}

void OSDSubMenuDownErgo(void)
{
    if(UserData.bSmartReminder == ON){
        OSDUnselectLayer2Item(CursorPos(OSD_MAIN_4_END,usOSDState), FALSE);
        while (1) {
            usOSDState = NextState(OSD_MAIN_4_END,OSD_MAIN_ERGO_END,usOSDState);
            if (OSDIsSubItemValid(CursorPos(OSD_MAIN_4_END,usOSDState)) == TRUE)
                break;
        }
        OSDSelectLayer2Item(CursorPos(OSD_MAIN_4_END,usOSDState), FALSE);
    }
}


//******************************************************************************
// Operations of sub-items in submenu 1
//******************************************************************************
void OSDEnterItm11(void)
{
    OSDCloseAll();
    OSDEnterAuto();
}

void OSDExitItm11(void)
{
    OSDConfirmItm11();
    OSDExitItms(CursorPos(OSD_ITEM_1_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_1_1_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_END,usOSDState), FALSE);
}
#if ENABLE_AUTO_POVIT_FUNC == ON
void OSDEnterItm1Pivot(void)
{
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_END,usOSDState);
    usOSDState = OSD_ITEM_PIVOT_1_STATE;
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_PIVOT_1_STATE,usOSDState));
}

void OSDExitItm1Pivot(void)
{
    //OSDConfirmItm12();
    OSDExitItms(CursorPos(OSD_ITEM_PIVOT_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_1_POVIT_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_END,usOSDState), FALSE);
}

void OSDItm1PivotUp(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_PIVOT_1_STATE, usOSDState), TRUE);
//    while (1) {
        usOSDState = PrevState(OSD_ITEM_PIVOT_1_STATE, OSD_ITEM_PIVOT_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_PIVOT_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_PIVOT_1_STATE, usOSDState));
}

void OSDItm1PivotDown(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_PIVOT_1_STATE, usOSDState), FALSE);
//    while (1) {
        usOSDState = NextState(OSD_ITEM_PIVOT_1_STATE, OSD_ITEM_PIVOT_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_PIVOT_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_PIVOT_1_STATE, usOSDState));
}
#endif
void OSDEnterItm12(void)
{
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_END,usOSDState);
    OSDFocusItm12();
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_1_2_1_STATE,usOSDState));
}

void OSDExitItm12(void)
{
    //OSDConfirmItm12();
    OSDExitItms(CursorPos(OSD_ITEM_1_2_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_1_2_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_END,usOSDState), FALSE);
}

void OSDItm12Up(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_1_2_1_STATE, usOSDState), TRUE);
//    while (1) {
        usOSDState = PrevState(OSD_ITEM_1_2_1_STATE, OSD_ITEM_1_2_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_1_2_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_1_2_1_STATE, usOSDState));
//    OSDInputSourceUp();
}

void OSDItm12Down(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_1_2_1_STATE, usOSDState), FALSE);
//    while (1) {
        usOSDState = NextState(OSD_ITEM_1_2_1_STATE, OSD_ITEM_1_2_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_1_2_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_1_2_1_STATE, usOSDState));
//    OSDInputSourceDown();
}

void OSDSelectInput(void)
{
    UCHAR SoucerIndex, OSDindex;
    OSDindex = GetOSDState() - OSD_ITEM_1_2_1_STATE;
    SoucerIndex = GetInputPortIndex(UserData.ucInputSource);
    if(OSDindex != SoucerIndex){
        UserData.ucInputSource = GetInputPortName(OSDindex);
        OSDConfirmInput();
        OSDCloseAll();        
    }
    else{
        OSDExitItm12();
    }
}

void OSDEnterItm13(void)
{
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_END,usOSDState);
    usOSDState = OSD_ITEM_1_3_STATE;
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_1_3_STATE,usOSDState));
    OSDFocusItm13();
}

void OSDExitItm13(void)
{
    OSDConfirmItm13();
    OSDExitItms(CursorPos(OSD_ITEM_1_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_1_3_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_END,usOSDState), FALSE);
}

void OSDEnterItm14(void)
{
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_END,usOSDState);
    usOSDState = OSD_ITEM_1_4_STATE;
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_1_4_STATE,usOSDState));
    OSDFocusItm14();
}

void OSDExitItm14(void)
{
    OSDConfirmItm14();
    OSDExitItms(CursorPos(OSD_ITEM_1_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_1_4_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_END,usOSDState), FALSE);
}

void OSDEnterItm15(void)
{
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_END,usOSDState);
    usOSDState = OSD_ITEM_1_5_STATE;
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_1_5_STATE,usOSDState));
    OSDFocusItm15();
}

void OSDExitItm15(void)
{
    OSDConfirmItm15();
    OSDExitItms(CursorPos(OSD_ITEM_1_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_1_5_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_END,usOSDState), FALSE);
}

void OSDEnterItm16(void)
{
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_END,usOSDState);
    usOSDState = OSD_ITEM_1_6_STATE;
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_1_6_STATE,usOSDState));
    OSDFocusItm16();
}

void OSDExitItm16(void)
{
    OSDConfirmItm16();
    OSDExitItms(CursorPos(OSD_ITEM_1_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_1_6_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_END,usOSDState), FALSE);
}

//******************************************************************************
// Operations of sub-items in submenu 2
//******************************************************************************
void OSDEnterItm21(void)
{
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_1_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_1_END,usOSDState);
    usOSDState = OSD_ITEM_2_1_STATE;
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_2_1_STATE,usOSDState));
    OSDFocusItm21();
}

void OSDExitItm21(void)
{
    OSDConfirmItm21();
    OSDExitItms(CursorPos(OSD_ITEM_2_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_2_1_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_1_END,usOSDState), FALSE);
}

void OSDEnterItm22(void)
{
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_1_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_1_END,usOSDState);
    usOSDState = OSD_ITEM_2_2_STATE;
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_2_2_STATE,usOSDState));
    OSDFocusItm22();
    //Justin 140324
}

void OSDExitItm22(void)
{
    OSDConfirmItm22();
    OSDExitItms(CursorPos(OSD_ITEM_2_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_2_2_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_1_END,usOSDState), FALSE);
    //Justin 140324
}

void OSDEnterItm23(void)
{
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_1_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_1_END,usOSDState);
    usOSDState = OSD_ITEM_2_3_STATE;
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_2_3_STATE,usOSDState));
    OSDFocusItm23();
    //Justin 140324
}

void OSDExitItm23(void)
{
    OSDConfirmItm23();
    OSDExitItms(CursorPos(OSD_ITEM_2_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_2_3_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_1_END,usOSDState), FALSE);
    //Justin 140324
}

void OSDEnterItm24(void)
{
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_1_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_1_END,usOSDState);
    OSDFocusItm24();
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_2_4_1_STATE,usOSDState));
    //Justin 140324
}

void OSDExitItm24(void)
{
    //OSDConfirmItm24();
    OSDExitItms(CursorPos(OSD_ITEM_2_4_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_2_4_STATE;
   // UserData.ucGammaNum    = Custom_System.ucOSD_preview_temp;
    
    SetGammaNum(Custom_System.ucOSD_preview_temp);
    UserSetGamma();    
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_1_END,usOSDState), FALSE);
    //Justin 140324
}

void OSDConfirmItm24(void)
{
    //OSDConfirmItm24();
    OSDExitItms(CursorPos(OSD_ITEM_2_4_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_2_4_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_1_END,usOSDState), FALSE);
    SetOSDUpdUsrFlag();    
    //Justin 140324
}

void OSDItm24Up(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_2_4_1_STATE, usOSDState), TRUE);
//    while (1) {
        usOSDState = PrevState(OSD_ITEM_2_4_1_STATE, OSD_ITEM_2_4_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_2_4_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_2_4_1_STATE, usOSDState));
    OSDGammaUp();
}

void OSDItm24Down(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_2_4_1_STATE, usOSDState), FALSE);
//    while (1) {
        usOSDState = NextState(OSD_ITEM_2_4_1_STATE, OSD_ITEM_2_4_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_2_4_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_2_4_1_STATE, usOSDState));
    OSDGammaDown();
}

void OSDEnterItm25(void)
{
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_1_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_1_END,usOSDState);
    OSDFocusItm25();
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_2_5_1_STATE,usOSDState));
    //Justin 140324
}

void OSDExitItm25(void)
{
//    OSDConfirmItm25();
    OSDExitItms(CursorPos(OSD_ITEM_2_5_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_2_5_STATE;
    UserData.ucColorTemp = Custom_System.ucOSD_preview_temp;    
    UserSetColorTemp();
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_1_END,usOSDState), FALSE);
    //Justin 140324
}

void OSDConfirmItm25(void)
{
    OSDExitItms(CursorPos(OSD_ITEM_2_5_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_2_5_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_1_END,usOSDState), FALSE);
    SetOSDUpdUsrFlag();
}

void OSDItm25Up(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_2_5_1_STATE, usOSDState), TRUE);
    while (1) {
        usOSDState = PrevState(OSD_ITEM_2_5_1_STATE, OSD_ITEM_2_5_END, usOSDState);
        if (OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_2_5_1_STATE, usOSDState)) == TRUE)
            break;
    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_2_5_1_STATE, usOSDState));
    OSDColorTempUp();
}

void OSDItm25Down(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_2_5_1_STATE, usOSDState), FALSE);
    while (1) {
        usOSDState = NextState(OSD_ITEM_2_5_1_STATE, OSD_ITEM_2_5_END, usOSDState);
        if (OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_2_5_1_STATE, usOSDState)) == TRUE)
            break;
    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_2_5_1_STATE, usOSDState));
    OSDColorTempDown();
}

void OSDEnterItm26(void)
{
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_1_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_1_END,usOSDState);
    usOSDState = OSD_ITEM_2_6_STATE;
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_2_6_STATE,usOSDState));
    OSDFocusItm26();
    //Justin 140324
}

void OSDExitItm26(void)
{
    OSDConfirmItm26();
    OSDExitItms(CursorPos(OSD_ITEM_2_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_2_6_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_1_END,usOSDState), FALSE);
    //Justin 140324
}

void OSDEnterItm27(void)
{
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_1_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_1_END,usOSDState);
    usOSDState = OSD_ITEM_2_7_STATE;
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_2_7_STATE,usOSDState));
    OSDFocusItm27();
    //Justin 140324
}

void OSDExitItm27(void)
{
    OSDConfirmItm27();
    OSDExitItms(CursorPos(OSD_ITEM_2_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_2_7_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_1_END,usOSDState), FALSE);
    //Justin 140324
}

void OSDEnterItm28(void)
{
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_1_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_1_END,usOSDState);
    OSDFocusItm28();
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_2_8_1_STATE,usOSDState));
    //Justin 140324
}

void OSDExitItm28(void)
{
    OSDExitItms(CursorPos(OSD_ITEM_2_8_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_2_8_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_1_END,usOSDState), FALSE);
    //Justin 140324
}

void OSDConfirmItm28(void)//ULEric140410
{
    //UserSetColorReset();
    //OSDExitItms(CursorPos(OSD_ITEM_2_8_1_STATE,usOSDState));
    //usOSDState = OSD_MAIN_2_8_STATE;
    //OSDSelectLayer2Item(CursorPos(OSD_MAIN_1_END,usOSDState), FALSE);
    usOSDState = OSD_INFO_RESETCOLOR_NOTICE_STATE;
    OSDShowDialog(OSD_DLG_RESETCOLORNOTICE,0);
}

void OSDItm28Up(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_2_8_1_STATE, usOSDState), TRUE);
//    while (1) {
        usOSDState = PrevState(OSD_ITEM_2_8_1_STATE, OSD_ITEM_2_8_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_2_8_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_2_8_1_STATE, usOSDState));
}

void OSDItm28Down(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_2_8_1_STATE, usOSDState), FALSE);
//    while (1) {
        usOSDState = NextState(OSD_ITEM_2_8_1_STATE, OSD_ITEM_2_8_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_2_8_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_2_8_1_STATE, usOSDState));
}

void OSDEnterItm29(void)
{
    Custom_System.ucOSD_preview_temp = UserData.ucODMode;
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_1_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_1_END,usOSDState);
    OSDFocusItm29();
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_2_9_1_STATE,usOSDState));
    //Justin 140324
}

void OSDExitItm29(void)
{
    UserData.ucODMode = Custom_System.ucOSD_preview_temp;

    OSDExitItms(CursorPos(OSD_ITEM_2_9_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_2_9_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_1_END,usOSDState), FALSE);
    UserSetOD();    
    //Justin 140324
}

void OSDConfirmItm29(void)
{
    OSDExitItms(CursorPos(OSD_ITEM_2_9_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_2_9_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_1_END,usOSDState), FALSE);
    SetOSDUpdUsrFlag();
}

void OSDItm29Up(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_2_9_1_STATE, usOSDState), TRUE);
//    while (1) {
        usOSDState = PrevState(OSD_ITEM_2_9_1_STATE, OSD_ITEM_2_9_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_2_9_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_2_9_1_STATE, usOSDState));
    OSDODUp();
}

void OSDItm29Down(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_2_9_1_STATE, usOSDState), FALSE);
//    while (1) {
        usOSDState = NextState(OSD_ITEM_2_9_1_STATE, OSD_ITEM_2_9_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_2_9_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_2_9_1_STATE, usOSDState));
    OSDODDown();
}

//******************************************************************************
// Operations of sub-items in submenu 3
//******************************************************************************
void OSDEnterItm31(void)
{
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_2_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_2_END,usOSDState);
    OSDFocusItm31();
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_3_1_1_STATE,usOSDState));
    //Justin 140324
}

void OSDExitItm31(void)
{
    //OSDConfirmItm31();
    OSDExitItms(CursorPos(OSD_ITEM_3_1_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_3_1_STATE;
    if(Custom_System.ucOSD_preview_temp!=UserData.ucBFMode){
        UserData.ucBFMode = Custom_System.ucOSD_preview_temp;    
        UserSetBF();    
    }

    OSDSelectLayer2Item(CursorPos(OSD_MAIN_2_END,usOSDState), FALSE);
    OSDAPI_SetIndentIndex(String_Layer1_Index);
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    bSelectTable = OSDFontTble1;    
    OSDShowTitleString();          
}

void OSDCheckItm31(void)
{
    OSDExitItms(CursorPos(OSD_ITEM_3_1_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_3_1_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_2_END,usOSDState), FALSE);
    //Justin 140324

    //OSDBFMenuITMConfirm(TRUE);
    OSDAPI_SetIndentIndex(String_Layer1_Index);
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    bSelectTable = OSDFontTble1;    
    OSDShowTitleString();    
    SetOSDUpdUsrFlag();    
}

void OSDItm31Up(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_3_1_1_STATE, usOSDState), TRUE);
        usOSDState = PrevState(OSD_ITEM_3_1_1_STATE, OSD_ITEM_3_1_END, usOSDState);
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_3_1_1_STATE, usOSDState));
    OSDBFMenuITMUp();
    OSDAPI_SetIndentIndex(String_Layer1_Index);
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    bSelectTable = OSDFontTble1;    
    OSDShowTitleString();      
    
}

void OSDItm31Down(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_3_1_1_STATE, usOSDState), FALSE);
        usOSDState = NextState(OSD_ITEM_3_1_1_STATE, OSD_ITEM_3_1_END, usOSDState);
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_3_1_1_STATE, usOSDState));
    OSDBFMenuITMDn();
    OSDAPI_SetIndentIndex(String_Layer1_Index);
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    bSelectTable = OSDFontTble1;    
    OSDShowTitleString();      
    
}

void OSDEnterItm32(void)
{
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_2_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_2_END,usOSDState);
    usOSDState = OSD_ITEM_3_2_1_STATE + (1-UserData.bSensEyeDemo);
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_3_2_1_STATE,usOSDState));
    OSDFocusItm32();
    //Justin 140324
}

void OSDExitItm32(void)
{
    UserData.bSensEyeDemo = Custom_System.ucOSD_preview_temp;
    SetDemo();
    OSDExitItms(CursorPos(OSD_ITEM_3_2_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_3_2_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_2_END,usOSDState), FALSE);
}

void OSDConfirmItm32(void)
{
    OSDExitItms(CursorPos(OSD_ITEM_3_2_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_3_2_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_2_END,usOSDState), FALSE);
    SetOSDUpdUsrFlag();
}

void OSDItm32Up(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_3_2_1_STATE, usOSDState), TRUE);
//    while (1) {
        usOSDState = PrevState(OSD_ITEM_3_2_1_STATE, OSD_ITEM_3_2_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_3_2_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_3_2_1_STATE, usOSDState));
    OSDSenseyeDemoUp();
}

void OSDItm32Down(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_3_2_1_STATE, usOSDState), FALSE);
//    while (1) {
        usOSDState = NextState(OSD_ITEM_3_2_1_STATE, OSD_ITEM_3_2_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_3_2_1_STATE, usOSDState)) == TRUE)
//            break;
//   }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_3_2_1_STATE, usOSDState));
    OSDSenseyeDemoDown();
}


void OSDEnterItm33(void)
{
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_2_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_2_END,usOSDState);
    usOSDState = OSD_ITEM_3_3_STATE;
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_3_3_STATE,usOSDState));
    OSDFocusItm33();
    //Justin 140324
}

void OSDExitItm33(void)
{
    OSDConfirmItm33();
    OSDExitItms(CursorPos(OSD_ITEM_3_3_STATE,usOSDState));
    usOSDState = OSD_MAIN_3_3_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_2_END,usOSDState), FALSE);
    //Justin 140324
}

/*void OSDItm33Up(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_3_3_STATE, usOSDState), TRUE);
    while (1) {
        usOSDState = PrevState(OSD_ITEM_3_3_STATE, OSD_ITEM_3_3_END, usOSDState);
        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_3_3_STATE, usOSDState)) == TRUE)
            break;
    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_3_3_STATE, usOSDState));
    OSDAspectRatioUp();
}

void OSDItm33Down(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_3_3_STATE, usOSDState), FALSE);
    while (1) {
        usOSDState = NextState(OSD_ITEM_3_3_STATE, OSD_ITEM_3_3_END, usOSDState);
        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_3_3_STATE, usOSDState)) == TRUE)
            break;
    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_3_3_STATE, usOSDState));
    OSDAspectRatioUp();
}*/

void OSDEnterItm34(void)
{
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_2_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_2_END,usOSDState);
    
    if(IsComponentInput()){
        usOSDState = OSD_ITEM_3_4_1_STATE + (1-UserData.bSOGOverScan);    
    }
    else{
        usOSDState = OSD_ITEM_3_4_1_STATE + (1-UserData.bOverScan);
    }

    
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_3_4_1_STATE,usOSDState));
    OSDFocusItm34();
    //Justin 140324
}

void OSDExitItm34(void)
{
    if(IsComponentInput()){
      if(UserData.bSOGOverScan != Custom_System.ucOSD_preview_temp){
           UserData.bSOGOverScan = Custom_System.ucOSD_preview_temp;
           OSDSetOverScan();
      }
   }
   else{
      if(UserData.bOverScan != Custom_System.ucOSD_preview_temp){
           UserData.bOverScan = Custom_System.ucOSD_preview_temp;
           OSDSetOverScan();
      }
   }
    
    OSDExitItms(CursorPos(OSD_ITEM_3_4_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_3_4_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_2_END,usOSDState), FALSE);     
}

void OSDConfirmItm34(void)
{
    OSDExitItms(CursorPos(OSD_ITEM_3_4_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_3_4_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_2_END,usOSDState), FALSE);
    OSDFocusItm34();
    SetOSDUpdUsrFlag();    
}


void OSDItm34Up(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_3_4_1_STATE, usOSDState), TRUE);
//    while (1) {
        usOSDState = PrevState(OSD_ITEM_3_4_1_STATE, OSD_ITEM_3_4_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_3_4_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_3_4_1_STATE, usOSDState));
    if(IsComponentInput()){
        UserData.bSOGOverScan = 1 - CursorPos(OSD_ITEM_3_4_1_STATE, usOSDState);    
    }
    else{
        UserData.bOverScan = 1 - CursorPos(OSD_ITEM_3_4_1_STATE, usOSDState);
    }
    OSDSetOverScan();
}

void OSDItm34Down(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_3_4_1_STATE, usOSDState), FALSE);
//    while (1) {
        usOSDState = NextState(OSD_ITEM_3_4_1_STATE, OSD_ITEM_3_4_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_3_4_1_STATE, usOSDState)) == TRUE)
//            break;
//}
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_3_4_1_STATE, usOSDState));
    if(IsComponentInput()){
        UserData.bSOGOverScan = 1 - CursorPos(OSD_ITEM_3_4_1_STATE, usOSDState);
    }
    else{
        UserData.bOverScan = 1 - CursorPos(OSD_ITEM_3_4_1_STATE, usOSDState);
    }
    OSDSetOverScan();
}

void OSDEnterItm35(void)
{    
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_2_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_2_END,usOSDState);
    usOSDState = OSD_ITEM_3_5_1_STATE + UserData.ucAspectRatio;
    OSDFocusItm35();
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_3_5_1_STATE,usOSDState));
    //Justin 140324
}

void OSDExitItm35(void)
{

    OSDExitItms(CursorPos(OSD_ITEM_3_5_1_STATE,usOSDState));
    if( UserData.ucAspectRatio != Custom_System.ucOSD_preview_temp){
        UserData.ucAspectRatio = Custom_System.ucOSD_preview_temp;
        SetAspRatioSetting();
        UserSetAspectRatio();
    }        
    usOSDState = OSD_MAIN_3_5_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_2_END,usOSDState), FALSE);    
}

void OSDConfirmItm35(void)
{
    OSDExitItms(CursorPos(OSD_ITEM_3_5_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_3_5_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_2_END,usOSDState), FALSE);
    SetOSDUpdUsrFlag();    
}


void OSDItm35Up(void)
{
    if (!isOnlyFullAspectRatio()) {
        OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_3_5_1_STATE, usOSDState), TRUE);
        while (1) {
            usOSDState = PrevState(OSD_ITEM_3_5_1_STATE, OSD_ITEM_3_5_END, usOSDState);
            if (OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_3_5_1_STATE, usOSDState)) == TRUE)
                break;
        }
        OSDSelectLayer3Item(CursorPos(OSD_ITEM_3_5_1_STATE, usOSDState));
        OSDAspectRatioUp();
    }
}

void OSDItm35Down(void)
{
    if (!isOnlyFullAspectRatio()) {
        OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_3_5_1_STATE, usOSDState), FALSE);
        while (1) {
            usOSDState = NextState(OSD_ITEM_3_5_1_STATE, OSD_ITEM_3_5_END, usOSDState);
            if (OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_3_5_1_STATE, usOSDState)) == TRUE)
                break;
        }
        OSDSelectLayer3Item(CursorPos(OSD_ITEM_3_5_1_STATE, usOSDState));
        OSDAspectRatioDown();
    }
}

void OSDEnterItm36(void)
{
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_2_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_2_END,usOSDState);
    usOSDState = OSD_ITEM_3_6_1_STATE + UserData.bColorFormat;
    OSDFocusItm36();
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_3_6_1_STATE,usOSDState));
    //Justin 140324
}

void OSDExitItm36(void)
{
    UserData.bColorFormat = Custom_System.ucOSD_preview_temp;
    SC_DISPLAY_MUTE_CTRL = 0x02;
    SetColorSpace();
    SC_DISPLAY_MUTE_CTRL = 0x00;
    
    OSDExitItms(CursorPos(OSD_ITEM_3_6_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_3_6_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_2_END,usOSDState), FALSE);
    //Justin 140324
}

void OSDConfirmItm36(void)
{
    OSDExitItms(CursorPos(OSD_ITEM_3_6_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_3_6_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_2_END,usOSDState), FALSE);
    SetOSDUpdUsrFlag();    
}


void OSDItm36Up(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_3_6_1_STATE, usOSDState), TRUE);
//    while (1) {
        usOSDState = PrevState(OSD_ITEM_3_6_1_STATE, OSD_ITEM_3_6_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_3_6_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_3_6_1_STATE, usOSDState));
    OSDBColorFormatUp();
}

void OSDItm36Down(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_3_6_1_STATE, usOSDState), FALSE);
//    while (1) {
        usOSDState = NextState(OSD_ITEM_3_6_1_STATE, OSD_ITEM_3_6_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_3_6_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_3_6_1_STATE, usOSDState));
    OSDBColorFormatDown();
}


void OSDEnterItm37(void)
{
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_2_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_2_END,usOSDState);
    usOSDState = OSD_ITEM_3_7_1_STATE + UserData.ucHDMIRGBRange;
    OSDFocusItm37();
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_3_7_1_STATE,usOSDState));
    //Justin 140324
}

void OSDConfirmItm37(void)
{
    OSDExitItms(CursorPos(OSD_ITEM_3_7_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_3_7_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_2_END,usOSDState), FALSE);
    SetOSDUpdUsrFlag();        
    //Justin 140324
}

void OSDExitItm37(void)
{
    UserData.ucHDMIRGBRange = Custom_System.ucOSD_preview_temp;    

    OSDExitItms(CursorPos(OSD_ITEM_3_7_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_3_7_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_2_END,usOSDState), FALSE);
    
    SetColorSpace();    
    //printf("#Ex HDMIRGBPCRange %bx\r\n",UserData.ucHDMIRGBRange);
    
    //Justin 140324
}

void OSDItm37Up(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_3_7_1_STATE, usOSDState), TRUE);
//    while (1) {
        usOSDState = PrevState(OSD_ITEM_3_7_1_STATE, OSD_ITEM_3_7_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_3_7_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_3_7_1_STATE, usOSDState));
    OSDHDMIRGBPCRangeUp();
}

void OSDItm37Down(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_3_7_1_STATE, usOSDState), FALSE);
//    while (1) {
        usOSDState = NextState(OSD_ITEM_3_7_1_STATE, OSD_ITEM_3_7_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_3_7_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_3_7_1_STATE, usOSDState));
    OSDHDMIRGBPCRangeDown();
}
//******************************************************************************
// Operations of sub-items in submenu 4
//******************************************************************************
void OSDEnterItmAudio1(void)
{
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_3_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_3_END,usOSDState);
    usOSDState = OSD_ITEM_Audio_1_1_STATE;
    OSDFocusItmAudio1();
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_1_1_STATE,usOSDState));
    //OSDFocusItm41();

    //OSDClrLayer2Menu(CursorPos(OSD_MAIN_END,usOSDState));
    //ucSubMenuType = CursorPos(OSD_MAIN_END,usOSDState);
    //usOSDState = OSD_ITEM_1_3_STATE;
    //OSDSelectLayer3Item(CursorPos(OSD_ITEM_1_3_STATE,usOSDState));
    //OSDFocusItm13();
    //OSDUpdateSelectPageIcon(0, 0, 0, STRING_LAYER_3, FALSE);
    //Justin 140324
}

void OSDExitItmAudio1(void)
{
    OSDConfirmItmAudio1();
    OSDExitItms(CursorPos(OSD_ITEM_Audio_1_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_Audio_1_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_3_END,usOSDState), FALSE);
    //Justin 140324
}
#if 0
void OSDItmAudio1Up(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_4_1_1_STATE, usOSDState), TRUE);
//    while (1) {
        usOSDState = PrevState(OSD_ITEM_4_1_1_STATE, OSD_ITEM_4_1_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_4_1_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_1_1_STATE, usOSDState));
}
void OSDItmAudio1Down(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_4_1_1_STATE, usOSDState), FALSE);
//    while (1) {
        usOSDState = NextState(OSD_ITEM_4_1_1_STATE, OSD_ITEM_4_1_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_4_1_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_1_1_STATE, usOSDState));
}
#endif

void OSDEnterItmAudio2(void)
{
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_3_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_3_END,usOSDState);
    usOSDState = OSD_ITEM_Audio_2_1_STATE + (1-UserData.bAudioMute);
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_Audio_2_1_STATE,usOSDState));
    Custom_System.ucOSD_preview_temp = UserData.bAudioMute;
}

void OSDExitItmAudio2(void)
{
    UserData.bAudioMute = Custom_System.ucOSD_preview_temp;    

    OSDExitItms(CursorPos(OSD_ITEM_Audio_2_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_Audio_2_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_3_END,usOSDState), FALSE);
    UserSetVolumeAndMute();        
}

void OSDConfirmAudio2(void)
{
    OSDExitItms(CursorPos(OSD_ITEM_Audio_2_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_Audio_2_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_3_END,usOSDState), FALSE);
    SetOSDUpdUsrFlag();
}

void OSDItmAudio2Up(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_Audio_2_1_STATE, usOSDState), TRUE);
//    while (1) {
        usOSDState = PrevState(OSD_ITEM_Audio_2_1_STATE, OSD_ITEM_Audio_2_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_Audio_2_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_Audio_2_1_STATE, usOSDState));
    OSDAudioMuteUp();
}


void OSDItmAudio2Down(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_Audio_2_1_STATE, usOSDState), FALSE);
//    while (1) {
        usOSDState = NextState(OSD_ITEM_Audio_2_1_STATE, OSD_ITEM_Audio_2_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_Audio_2_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_Audio_2_1_STATE, usOSDState));
    OSDAudioMuteUp();
}

void OSDEnterItmAudio3(void)
{
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_3_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_3_END,usOSDState);
    if(UserData.ucInputSource == INPUT_SC_HDMI){
        usOSDState = OSD_ITEM_Audio_3_1_STATE + UserData.ucHDMIAudioSelect;
        Custom_System.ucOSD_preview_temp = UserData.ucHDMIAudioSelect;
    }
    else{
        usOSDState = OSD_ITEM_Audio_3_1_STATE + UserData.ucAudioSelect;
        Custom_System.ucOSD_preview_temp = UserData.ucAudioSelect;        
    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_Audio_3_1_STATE,usOSDState));

}

void OSDExitItmAudio3(void)
{
    if(UserData.ucInputSource == INPUT_SC_HDMI){
        UserData.ucHDMIAudioSelect = Custom_System.ucOSD_preview_temp;        
    }
    else{
        UserData.ucAudioSelect = Custom_System.ucOSD_preview_temp;
    }    
    OSDAudioSelect();
    OSDExitItms(CursorPos(OSD_ITEM_4_1_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_Audio_3_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_3_END,usOSDState), FALSE);
}

void OSDConfirmAudio3(void)
{
    OSDExitItms(CursorPos(OSD_ITEM_4_1_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_Audio_3_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_3_END,usOSDState), FALSE);
    SetOSDUpdUsrFlag();
}

void OSDItmAudio3Up(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_Audio_3_1_STATE, usOSDState), TRUE);
    while (1) {
        usOSDState = PrevState(OSD_ITEM_Audio_3_1_STATE, OSD_ITEM_Audio_3_END, usOSDState);
        if (OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_Audio_3_1_STATE, usOSDState)) == TRUE)
            break;
    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_Audio_3_1_STATE, usOSDState));
    OSDAudioSelectUp();
}

void OSDItmAudio3Down(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_Audio_3_1_STATE, usOSDState), FALSE);
    while (1) {
        usOSDState = NextState(OSD_ITEM_Audio_3_1_STATE, OSD_ITEM_Audio_3_END, usOSDState);
        if (OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_Audio_3_1_STATE, usOSDState)) == TRUE)
            break;
    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_Audio_3_1_STATE, usOSDState));
    OSDAudioSelectDown();

}
//******************************************************************************
// Operations of sub-items in submenu 4
//******************************************************************************
void OSDEnterItm41(void)
{
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_Audio_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_Audio_END,usOSDState);
    usOSDState = OSD_ITEM_4_1_1_STATE;
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_1_1_STATE,usOSDState));
    //OSDFocusItm41();
    //Justin 140324
}

void OSDExitItm41(void)
{
    OSDConfirmItm41();
    OSDExitItms(CursorPos(OSD_ITEM_4_1_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_4_1_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_Audio_END,usOSDState), FALSE);
}

void OSDItm41Up(void)
{
    //OSDExitItms(CursorPos(OSD_ITEM_4_1_1_STATE,usOSDState));
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_4_1_1_STATE, usOSDState), TRUE);
//    while (1) {
        usOSDState = PrevState(OSD_ITEM_4_1_1_STATE, OSD_ITEM_4_1_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_4_1_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_1_1_STATE, usOSDState));
}

void OSDItm41Down(void)
{
    //OSDExitItms(CursorPos(OSD_ITEM_4_1_1_STATE,usOSDState));
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_4_1_1_STATE, usOSDState), FALSE);
//    while (1) {
        usOSDState = NextState(OSD_ITEM_4_1_1_STATE, OSD_ITEM_4_1_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_4_1_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_1_1_STATE, usOSDState));
}

void OSDEnterItm42(void)
{
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_Audio_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_Audio_END,usOSDState);
    OSDFocusItm42();
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_2_1_STATE,usOSDState));
    //Justin 140324
}

void OSDExitItm42(void)
{
    //OSDConfirmItm42();
    OSDExitItms(CursorPos(OSD_ITEM_4_2_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_4_2_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_Audio_END,usOSDState), FALSE);
}

void OSDConfirmCustomeKey1(void)//ULEric140331
{
    UserData.ucCustomerKey1 = CursorPos(OSD_ITEM_4_2_1_STATE,usOSDState);
    //OSDExitItms(CursorPos(OSD_ITEM_4_2_1_STATE,usOSDState));
    //usOSDState = OSD_MAIN_4_2_STATE;
    //OSDSelectLayer2Item(CursorPos(OSD_MAIN_Audio_END,usOSDState), FALSE);
    SetOSDUpdUsrFlag();
    OSDCloseAll();
    usOSDState = OSD_INFO_SAVENOTICE_STATE;
    OSDShowDialog(OSD_DLG_SAVENOTICE,0);        
    SetReShowMenuIdx(OSD_MAIN_4_2_STATE);   
}

void OSDItm42Up(void)
{

#if FORCE_NON_CIRCLE_ACTION == ON
    if (CursorPos(OSD_ITEM_4_2_1_STATE, usOSDState) <= GetMinLayer3ValidOSDState(OSD_ITEM_4_3_1_STATE, OSD_ITEM_4_3_END)){
        return;
    }
#endif // FORCE_NON_CIRCLE_ACTION

    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_4_2_1_STATE, usOSDState), TRUE);
    while (1) {
        usOSDState = PrevState(OSD_ITEM_4_2_1_STATE, OSD_ITEM_4_2_END, usOSDState);
        if (OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_4_2_1_STATE, usOSDState)) == TRUE)
            break;
    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_2_1_STATE, usOSDState));
}

void OSDItm42Down(void)
{
#if FORCE_NON_CIRCLE_ACTION == ON
    if (CursorPos(OSD_ITEM_4_2_1_STATE, usOSDState) >= GetMaxLayer3ValidOSDState(OSD_ITEM_4_3_1_STATE, OSD_ITEM_4_3_END))
        return;
#endif // FORCE_NON_CIRCLE_ACTION
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_4_2_1_STATE, usOSDState), FALSE);
    while (1) {
        usOSDState = NextState(OSD_ITEM_4_2_1_STATE, OSD_ITEM_4_2_END, usOSDState);    
        if (OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_4_2_1_STATE, usOSDState)) == TRUE)
            break;
    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_2_1_STATE, usOSDState));
}

void OSDEnterItm43(void)
{
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_Audio_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_Audio_END,usOSDState);
    OSDFocusItm43();
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_3_1_STATE,usOSDState));
    //Justin 140324
}

void OSDExitItm43(void)
{
    //OSDConfirmItm43();
    OSDExitItms(CursorPos(OSD_ITEM_4_3_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_4_3_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_Audio_END,usOSDState), FALSE);
}

void OSDConfirmCustomeKey2(void)//ULEric140331
{
    UserData.ucCustomerKey2 = CursorPos(OSD_ITEM_4_3_1_STATE,usOSDState);
    //OSDExitItms(CursorPos(OSD_ITEM_4_2_1_STATE,usOSDState));
    //usOSDState = OSD_MAIN_4_2_STATE;
    //OSDSelectLayer2Item(CursorPos(OSD_MAIN_Audio_END,usOSDState), FALSE);
    SetOSDUpdUsrFlag();
    OSDCloseAll();
    usOSDState = OSD_INFO_SAVENOTICE_STATE;
    OSDShowDialog(OSD_DLG_SAVENOTICE,1);    
    SetReShowMenuIdx(OSD_MAIN_4_3_STATE);   
}

void OSDItm43Up(void)
{
#if FORCE_NON_CIRCLE_ACTION == ON
    if (CursorPos(OSD_ITEM_4_3_1_STATE, usOSDState) <= GetMinLayer3ValidOSDState(OSD_ITEM_4_3_1_STATE, OSD_ITEM_4_3_END))
        return;
#endif // FORCE_NON_CIRCLE_ACTION
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_4_3_1_STATE, usOSDState), TRUE);
    while (1) {
        usOSDState = PrevState(OSD_ITEM_4_3_1_STATE, OSD_ITEM_4_3_END, usOSDState);
        if (OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_4_3_1_STATE, usOSDState)) == TRUE)
            break;
    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_3_1_STATE, usOSDState));
}

void OSDItm43Down(void)
{
#if FORCE_NON_CIRCLE_ACTION == ON
    if (CursorPos(OSD_ITEM_4_3_1_STATE, usOSDState) >= GetMaxLayer3ValidOSDState(OSD_ITEM_4_3_1_STATE, OSD_ITEM_4_3_END))
        return;
#endif // FORCE_NON_CIRCLE_ACTION
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_4_3_1_STATE, usOSDState), FALSE);
    while (1) {
        usOSDState = NextState(OSD_ITEM_4_3_1_STATE, OSD_ITEM_4_3_END, usOSDState);
        if (OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_4_3_1_STATE, usOSDState)) == TRUE)
            break;
    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_3_1_STATE, usOSDState));
}
#if 0
UCHAR GetMinValidOSDState(UCHAR OSD_Start_State, UCHAR OSD_End_State)
{
    UCHAR i;
    for(i = 0; i < (OSD_End_State - OSD_Start_State);i++){
          if(OSDIsSubItemValid(i) == TRUE){
          break;
       }          
    }
    return i;
}

UCHAR GetMaxValidOSDState(UCHAR OSD_Start_State, UCHAR OSD_End_State)
{
    UCHAR i;
    for(i = (OSD_End_State - OSD_Start_State- 1); i < (OSD_End_State - OSD_Start_State);i--){
          if(OSDIsSubItemValid(i) == TRUE){
          break;
       } 
    }
    return i;
}
#endif
UCHAR GetMinLayer3ValidOSDState(UCHAR OSD_Start_State, UCHAR OSD_End_State)
{
    UCHAR i;
    for(i = 0; i < (OSD_End_State - OSD_Start_State);i++){
          if(OSDIsLayer3ItemValid(i) == TRUE){
          break;
       }          
    }
    return i;
}

UCHAR GetMaxLayer3ValidOSDState(UCHAR OSD_Start_State, UCHAR OSD_End_State)
{
    UCHAR i;
    for(i = (OSD_End_State - OSD_Start_State- 1); i < (OSD_End_State - OSD_Start_State);i--){
          if(OSDIsLayer3ItemValid(i) == TRUE){
          break;
       } 
    }
    return i;
}


void OSDEnterItm44(void)
{
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_Audio_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_Audio_END,usOSDState);
    OSDFocusItm44();
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_4_1_STATE,usOSDState));
    //Justin 140324
}

void OSDExitItm44(void)
{
    //OSDConfirmItm44();
    OSDExitItms(CursorPos(OSD_ITEM_4_4_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_4_4_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_Audio_END,usOSDState), FALSE);
}

void OSDConfirmCustomeKey3(void)//ULEric140331
{
    UserData.ucCustomerKey3 = CursorPos(OSD_ITEM_4_4_1_STATE,usOSDState);
    //OSDExitItms(CursorPos(OSD_ITEM_4_2_1_STATE,usOSDState));
    //usOSDState = OSD_MAIN_4_2_STATE;
    //OSDSelectLayer2Item(CursorPos(OSD_MAIN_Audio_END,usOSDState), FALSE);
    SetOSDUpdUsrFlag();
    OSDCloseAll();
    usOSDState = OSD_INFO_SAVENOTICE_STATE;
    OSDShowDialog(OSD_DLG_SAVENOTICE, 2);    
    SetReShowMenuIdx(OSD_MAIN_4_4_STATE);   
}

void OSDItm44Up(void)
{
#if FORCE_NON_CIRCLE_ACTION == ON
    if (CursorPos(OSD_ITEM_4_4_1_STATE, usOSDState) <= GetMinLayer3ValidOSDState(OSD_ITEM_4_3_1_STATE, OSD_ITEM_4_3_END))
        return;
#endif // FORCE_NON_CIRCLE_ACTION
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_4_4_1_STATE, usOSDState), TRUE);
    while (1) {
        usOSDState = PrevState(OSD_ITEM_4_4_1_STATE, OSD_ITEM_4_4_END, usOSDState);
        if (OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_4_4_1_STATE, usOSDState)) == TRUE)
            break;
    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_4_1_STATE, usOSDState));
}

void OSDItm44Down(void)
{
#if FORCE_NON_CIRCLE_ACTION == ON
    if (CursorPos(OSD_ITEM_4_4_1_STATE, usOSDState) >= GetMaxLayer3ValidOSDState(OSD_ITEM_4_3_1_STATE, OSD_ITEM_4_3_END))
        return;
#endif // FORCE_NON_CIRCLE_ACTION
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_4_4_1_STATE, usOSDState), FALSE);
    while (1) {
        usOSDState = NextState(OSD_ITEM_4_4_1_STATE, OSD_ITEM_4_4_END, usOSDState);
        if (OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_4_4_1_STATE, usOSDState)) == TRUE)
            break;
    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_4_1_STATE, usOSDState));
}

void OSDEnterItm45(void)
{
    //OSD_Select_Temp = UserData.bDDCCI;
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_Audio_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_Audio_END,usOSDState);
    OSDFocusItm45();
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_5_1_STATE,usOSDState));
    //Justin 140324
}

void OSDExitItm45(void)
{
    UserData.bDDCCI = Custom_System.ucOSD_preview_temp;
    OSDExitItms(CursorPos(OSD_ITEM_4_5_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_4_5_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_Audio_END,usOSDState), FALSE);
}

void OSDCheckItm45(void)
{
    OSDDDCCIConfirm();
    OSDExitItms(CursorPos(OSD_ITEM_4_5_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_4_5_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_Audio_END,usOSDState), FALSE);
    //Justin 140324
}

void OSDItm45Up(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_4_5_1_STATE, usOSDState), TRUE);
//    while (1) {
        usOSDState = PrevState(OSD_ITEM_4_5_1_STATE, OSD_ITEM_4_5_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_4_5_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_5_1_STATE, usOSDState));
    OSDDDCCiUp();
}

void OSDItm45Down(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_4_5_1_STATE, usOSDState), FALSE);
//    while (1) {
        usOSDState = NextState(OSD_ITEM_4_5_1_STATE, OSD_ITEM_4_5_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_4_5_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_5_1_STATE, usOSDState));
    OSDDDCCiDown();
}

void OSDEnterItm46(void)
{
    Custom_System.ucOSD_preview_temp = UserData.bDPAutoSwitch;
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_Audio_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_Audio_END,usOSDState);
    usOSDState = OSD_ITEM_4_6_1_STATE + (1-UserData.bDPAutoSwitch);
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_6_1_STATE,usOSDState));
    //Justin 140324
}

void OSDExitItm46(void)
{
    UserData.bDPAutoSwitch = Custom_System.ucOSD_preview_temp;
    OSDExitItms(CursorPos(OSD_ITEM_4_6_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_4_6_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_Audio_END,usOSDState), FALSE);
}

void OSDConfirmItm46(void)
{
    OSDExitItms(CursorPos(OSD_ITEM_4_6_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_4_6_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_Audio_END,usOSDState), FALSE);
    SetOSDUpdUsrFlag();
}

void OSDItm46Up(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_4_6_1_STATE, usOSDState), TRUE);
//    while (1) {
        usOSDState = PrevState(OSD_ITEM_4_6_1_STATE, OSD_ITEM_4_6_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_4_6_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_6_1_STATE, usOSDState));
    OSDDPAutoSwitchUp();
}

void OSDItm46Down(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_4_6_1_STATE, usOSDState), FALSE);
//    while (1) {
        usOSDState = NextState(OSD_ITEM_4_6_1_STATE, OSD_ITEM_4_6_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_4_6_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_6_1_STATE, usOSDState));
    OSDDPAutoSwitchDown();
}

void OSDEnterItm47(void)
{
    Custom_System.ucOSD_preview_temp = UserData.bHDMIAutoSwitch;
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_Audio_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_Audio_END,usOSDState);
    usOSDState = OSD_ITEM_4_7_1_STATE + (1-UserData.bHDMIAutoSwitch);
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_7_1_STATE,usOSDState));
    //Justin 140324
}

void OSDExitItm47(void)
{
    UserData.bHDMIAutoSwitch = Custom_System.ucOSD_preview_temp;
    OSDExitItms(CursorPos(OSD_ITEM_4_7_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_4_7_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_Audio_END,usOSDState), FALSE);
    //Justin 140324
}

void OSDConfirmItm47(void)
{
    OSDExitItms(CursorPos(OSD_ITEM_4_7_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_4_7_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_Audio_END,usOSDState), FALSE);
    SetOSDUpdUsrFlag();
}

void OSDItm47Up(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_4_7_1_STATE, usOSDState), TRUE);
//    while (1) {
        usOSDState = PrevState(OSD_ITEM_4_7_1_STATE, OSD_ITEM_4_7_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_4_7_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_7_1_STATE, usOSDState));
    OSDHDMIAutoSwitchUp();
}

void OSDItm47Down(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_4_7_1_STATE, usOSDState), FALSE);
//    while (1) {
        usOSDState = NextState(OSD_ITEM_4_7_1_STATE, OSD_ITEM_4_7_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_4_7_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_7_1_STATE, usOSDState));
    OSDHDMIAutoSwitchDown();
}

void OSDEnterItm48(void)
{
    OSD_Select_Temp = UserData.ucAutoPowerOffTime;
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_Audio_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_Audio_END,usOSDState);
    OSDFocusItm48();
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_8_1_STATE,usOSDState));
    //Justin 140324
}

void OSDExitItm48(void)
{
    
    OSDExitItms(CursorPos(OSD_ITEM_4_8_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_4_8_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_Audio_END,usOSDState), FALSE);
    //Justin 140324
}

void OSDConfirmItm48()
{
    UserData.ucAutoPowerOffTime = OSD_Select_Temp;
    UserSetAutoPowerOffTimer();
    OSDExitItms(CursorPos(OSD_ITEM_4_8_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_4_8_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_Audio_END,usOSDState), FALSE);
    SetOSDUpdUsrFlag();
}

void OSDItm48Up(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_4_8_1_STATE, usOSDState), TRUE);
//    while (1) {
        usOSDState = PrevState(OSD_ITEM_4_8_1_STATE, OSD_ITEM_4_8_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_4_8_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_8_1_STATE, usOSDState));
    OSDAutoPowOffUp();
}

void OSDItm48Down(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_4_8_1_STATE, usOSDState), FALSE);
//    while (1) {
        usOSDState = NextState(OSD_ITEM_4_8_1_STATE, OSD_ITEM_4_8_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_4_8_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_8_1_STATE, usOSDState));
    OSDAutoPowOffDown();
}


void OSDEnterItm49(void)
{
    Custom_System.ucOSD_preview_temp = UserData.bResNotice;
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_Audio_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_Audio_END,usOSDState);
    OSDFocusItm49();
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_9_1_STATE,usOSDState));
    //Justin 140324
}

void OSDExitItm49(void)
{
    UserData.bResNotice = Custom_System.ucOSD_preview_temp;
    OSDExitItms(CursorPos(OSD_ITEM_4_9_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_4_9_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_Audio_END,usOSDState), FALSE);
    //Justin 140324
}

void OSDConfirmItm49()
{
    OSDExitItms(CursorPos(OSD_ITEM_4_9_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_4_9_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_Audio_END,usOSDState), FALSE);
    SetOSDUpdUsrFlag();
}

void OSDItm49Up(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_4_9_1_STATE, usOSDState), TRUE);
//    while (1) {
        usOSDState = PrevState(OSD_ITEM_4_9_1_STATE, OSD_ITEM_4_9_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_4_9_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_9_1_STATE, usOSDState));
    OSDResNoticeUp();
}

void OSDItm49Down(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_4_9_1_STATE, usOSDState), FALSE);
//    while (1) {
        usOSDState = NextState(OSD_ITEM_4_9_1_STATE, OSD_ITEM_4_9_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_4_9_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_9_1_STATE, usOSDState));
    OSDResNoticeDown();
}

#if 0
void OSDEnterItm410(void)
{
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_Audio_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_Audio_END,usOSDState);
    usOSDState = OSD_ITEM_4_10_STATE;
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_10_STATE,usOSDState));
    //Justin 140324
    OSDFocusItm410();
}
#endif
void OSDExitItm410(void)
{
    OSDExitItms(CursorPos(OSD_ITEM_4_10_STATE,usOSDState));
    usOSDState = OSD_MAIN_4_10_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_Audio_END,usOSDState), FALSE);
    //Justin 140324
}

void OSDEnterItm411(void)
{
    OSD_Select_Temp = UserData.bDPVersion;
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_Audio_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_Audio_END,usOSDState);
    usOSDState = OSD_ITEM_4_11_1_STATE + UserData.bDPVersion;
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_11_1_STATE,usOSDState));
    //Justin 140324
}

void OSDExitItm411(void)
{
    OSDExitItms(CursorPos(OSD_ITEM_4_11_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_4_11_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_Audio_END,usOSDState), FALSE);
}

void OSDConfirmItm411(void)
{
    UserData.bDPVersion = CursorPos(OSD_ITEM_4_11_1_STATE,usOSDState);
    OSDExitItms(CursorPos(OSD_ITEM_4_11_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_4_11_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_Audio_END,usOSDState), FALSE);
    SetOSDUpdUsrFlag();    

    SetDPSpeed(UserData.bDPVersion);
	SYSAPI_PerformHPDOff(HPD_FORCE_DP);
}


void OSDItm411Up(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_4_11_1_STATE, usOSDState), TRUE);
        usOSDState = PrevState(OSD_ITEM_4_11_1_STATE, OSD_ITEM_4_11_END, usOSDState);
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_11_1_STATE, usOSDState));
}

void OSDItm411Down(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_4_11_1_STATE, usOSDState), FALSE);
        usOSDState = NextState(OSD_ITEM_4_11_1_STATE, OSD_ITEM_4_11_END, usOSDState);
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_11_1_STATE, usOSDState));
}

void OSDEnterItm412(void)
{
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_Audio_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_Audio_END,usOSDState);
    OSDFocusItm412();
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_12_1_STATE,usOSDState));
    //Justin 140324
}

void OSDExitItm412(void)
{
    OSDExitItms(CursorPos(OSD_ITEM_4_12_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_4_12_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_Audio_END,usOSDState), FALSE);
}
void OSDConfirmItm412(void)//ULEric140410
{
    //OSDConfirmRecall();
    //OSDExitItms(CursorPos(OSD_ITEM_4_12_1_STATE,usOSDState));
    usOSDState = OSD_INFO_RESETALL_NOTICE_STATE;
    OSDShowDialog(OSD_DLG_RESETNOTICE,0);
    //OSDSelectLayer2Item(CursorPos(OSD_MAIN_Audio_END,usOSDState), FALSE);
}

void OSDItm412Up(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_4_12_1_STATE, usOSDState), TRUE);
//    while (1) {
        usOSDState = PrevState(OSD_ITEM_4_12_1_STATE, OSD_ITEM_4_12_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_4_12_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_12_1_STATE, usOSDState));
}

void OSDItm412Down(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_4_12_1_STATE, usOSDState), FALSE);
//    while (1) {
        usOSDState = NextState(OSD_ITEM_4_12_1_STATE, OSD_ITEM_4_12_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_4_12_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_12_1_STATE, usOSDState));
}
//******************************************************************************
// Operations of sub-items in submenu 5
//******************************************************************************
void OSDEnterItmErgo1(void)
{
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_4_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_4_END,usOSDState);
    usOSDState = OSD_ITEM_ERGO_1_1_STATE + (1 - UserData.bSmartReminder);
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_ERGO_1_1_STATE,usOSDState));
    bOSD_Select_Temp = UserData.bSmartReminder;
    //OSD_SetSmartRemider();
}

void OSDExitItmErgo1(void)
{
    OSDExitItms(CursorPos(OSD_ITEM_ERGO_1_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_ERGO_1_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_4_END,usOSDState), FALSE);
    //OSD_SetSmartRemider();
}

void OSDComfirmItmErgo1(void)
{
    OSDExitItms(CursorPos(OSD_ITEM_ERGO_1_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_ERGO_1_STATE;
    OSDResetSmartRemiderTimer(FALSE);
    OSD_SetSmartRemider();    
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_4_END,usOSDState), FALSE);
    SetOSDUpdUsrFlag();
}

void OSDItmErgo1Up(void)
{
    bOSD_Select_Temp = ~bOSD_Select_Temp;

    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_ERGO_1_1_STATE, usOSDState), TRUE);
    usOSDState = PrevState(OSD_ITEM_ERGO_1_1_STATE, OSD_ITEM_ERGO_1_END, usOSDState);
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_ERGO_1_1_STATE, usOSDState));
    //UserData.bSmartReminder = !UserData.bSmartReminder;
    
}

void OSDItmErgo1Down(void)
{

    bOSD_Select_Temp = ~bOSD_Select_Temp;

    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_ERGO_1_1_STATE, usOSDState), FALSE);
    usOSDState = NextState(OSD_ITEM_ERGO_1_1_STATE, OSD_ITEM_ERGO_1_END, usOSDState);
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_ERGO_1_1_STATE, usOSDState));
}

void OSDEnterItmErgo2(void)
{
    OSD_Select_Temp = UserData.ucErgoTime;
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_4_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_4_END,usOSDState);
    usOSDState = OSD_ITEM_ERGO_2_1_STATE + OSD_Select_Temp;
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_ERGO_2_1_STATE,usOSDState));
    //OSDFocusItm41();
    //Justin 140324
}

void OSDExitItmErgo2(void)
{
    //UserData.ucErgoTime = OSD_Select_Temp;
    OSDExitItms(CursorPos(OSD_ITEM_ERGO_2_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_ERGO_2_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_4_END,usOSDState), FALSE);
    
}

void OSDComfirmItmErgo2(void)
{

    OSDExitItms(CursorPos(OSD_ITEM_ERGO_2_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_ERGO_2_STATE;
    OSD_SetErgoTime();
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_4_END,usOSDState), FALSE);
    SetOSDUpdUsrFlag();
}


void OSDItmErgo2Up(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_ERGO_2_1_STATE, usOSDState), TRUE);
//    while (1) {
        usOSDState = PrevState(OSD_ITEM_ERGO_2_1_STATE, OSD_ITEM_ERGO_2_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_ERGO_2_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_ERGO_2_1_STATE, usOSDState));
    OSDErgoTimeUp();

}


void OSDItmErgo2Down(void)
{

    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_ERGO_2_1_STATE, usOSDState), FALSE);
//    while (1) {
        usOSDState = NextState(OSD_ITEM_ERGO_2_1_STATE, OSD_ITEM_ERGO_2_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_ERGO_2_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_ERGO_2_1_STATE, usOSDState));
    OSDErgoTimeDown();

}

void OSDEnterItmErgo3(void)
{
    OSD_Select_Temp = UserData.ucErgoDuration;
    OSDClrLayer2Menu(CursorPos(OSD_MAIN_4_END,usOSDState));
    ucSubMenuType = CursorPos(OSD_MAIN_4_END,usOSDState);
    usOSDState = OSD_ITEM_ERGO_3_1_STATE + OSD_Select_Temp;
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_ERGO_3_1_STATE,usOSDState));
}

void OSDExitItmErgo3(void)
{
    //UserData.ucErgoDuration = OSD_Select_Temp;
    OSDExitItms(CursorPos(OSD_ITEM_4_1_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_ERGO_3_STATE;
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_4_END,usOSDState), FALSE);

}

void OSDComfirmItmErgo3(void)
{
    OSDExitItms(CursorPos(OSD_ITEM_4_1_1_STATE,usOSDState));
    usOSDState = OSD_MAIN_ERGO_3_STATE;
    OSD_SetErgoDuration();
    OSDSelectLayer2Item(CursorPos(OSD_MAIN_4_END,usOSDState), FALSE);
    SetOSDUpdUsrFlag();
}

void OSDItmErgo3Up(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_ERGO_3_1_STATE, usOSDState), TRUE);
//    while (1) {
        usOSDState = PrevState(OSD_ITEM_ERGO_3_1_STATE, OSD_ITEM_ERGO_3_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_ERGO_3_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_ERGO_3_1_STATE, usOSDState));
    OSDErgoDurationUp();
}

void OSDItmErgo3Down(void)
{
    OSDUnSelectLayer3Item(CursorPos(OSD_ITEM_ERGO_3_1_STATE, usOSDState), FALSE);
//    while (1) {
        usOSDState = NextState(OSD_ITEM_ERGO_3_1_STATE, OSD_ITEM_ERGO_3_END, usOSDState);
//        if (OSDIsSubItemValid(CursorPos(OSD_ITEM_ERGO_3_1_STATE, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_ERGO_3_1_STATE, usOSDState));
    OSDErgoDurationDown();
}

void OSDEnterSubItm2541(void)
{
    ucLayer3MenuType = CursorPos(OSD_ITEM_2_4_END,usOSDState);
    OSDAPI_SetFontAttr(UnSelectedStringColor1);    
    OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+CLRTMP_6500K*2, _SPACE_);
    OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+CLRTMP_9300K*2, _SPACE_);    
    OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+CLRTMP_5800K*2, _SPACE_);        
    OSDShowHookIcon(SelectedStringColor1_256, OSD_PICTURE_COLORTEMP, STRING_LAYER_3, Hook_Icon);    
    OSDClrLayer3Menu(CursorPos(OSD_ITEM_2_4_END,usOSDState));
    usOSDState = OSD_SUBITEM_2_5_4_1_STATE;
    OSDShowLayer4Menu(CursorPos(OSD_SUBITEM_2_5_4_STATE_BEG,usOSDState));
    //Justin 140324
    Custom_System.ucOSD_preview_temp = CLRTMP_USER;
    //printf("Enter 2541 Clrtmp %bx\r\n",UserData.ucColorTemp);
    SetOSDUpdUsrFlag();
    OSDShowGGain(FALSE, FALSE);
    OSDShowBGain(FALSE, FALSE);
    OSDShowRGain(TRUE, FALSE);
}

void OSDEnterSubItm2543to1(void)
{
    usOSDState = OSD_SUBITEM_2_5_4_1_STATE;
    OSDShowGGain(FALSE, FALSE);
    OSDShowBGain(FALSE, FALSE);
        OSDShowRGain(TRUE, FALSE);
}

void OSDExitSubItm2541(void)
{
    OSDExitSubItms(CursorPos(OSD_SUBITEM_2_5_4_1_STATE,usOSDState));
    usOSDState = OSD_ITEM_2_5_4_STATE;
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_2_4_END, usOSDState));
    //Justin 140324
}

void OSDSubItm2541Up(void)
{
    OSDRGainUp();
}

void OSDSubItm2541Down(void)
{
    OSDRGainDown();
}

void OSDEnterSubItm2542(void)
{
    usOSDState = OSD_SUBITEM_2_5_4_2_STATE;
    OSDShowRGain(FALSE, FALSE);
    OSDShowBGain(FALSE, FALSE);
    OSDShowGGain(TRUE, FALSE);
}
#if 0
void OSDExitSubItm2542(void)
{
    OSDExitSubItm2541();
}
void OSDExitSubItm2543(void)
{
    OSDExitSubItm2541();
}

#endif
void OSDSubItm2542Up(void)
{
    OSDGGainUp();
}

void OSDSubItm2542Down(void)
{
    OSDGGainDown();
}

void OSDEnterSubItm2543(void)
{
    usOSDState = OSD_SUBITEM_2_5_4_3_STATE;
    OSDShowRGain(FALSE, FALSE);
    OSDShowGGain(FALSE, FALSE);
    OSDShowBGain(TRUE, FALSE);
}


void OSDSubItm2543Up(void)
{
    OSDBGainUp();
}

void OSDSubItm2543Down(void)
{
    OSDBGainDown();
}


void OSDEnterSubItm313(void)
{
//UCHAR temp;
    //Custom_System.ucLanguage = UserData.ucLanguage;
    ucLayer3MenuType = CursorPos(OSD_ITEM_2_9_END,usOSDState);
    OSDClrLayer3Menu(CursorPos(OSD_ITEM_2_9_END,usOSDState));
    usOSDState = OSD_SUBITEM_3_1_2_1_STATE + UserData.ucLBLMode;//ULEric140402
    OSDAPI_SetFontAttr(UnSelectedStringColor1);    
    OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+Custom_System.ucOSD_preview_temp*2, _SPACE_);
    OSDShowHookIcon(SelectedStringColor1_256, OSD_PICTURE_AD_PIC , STRING_LAYER_3, Hook_Icon);
    OSDSelectLBLLayer4Item(CursorPos(OSD_SUBITEM_3_1_2_STATE_BEG, usOSDState));
    //Justin 140324
    OSDAPI_SetIndentIndex(String_Layer1_Index);
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    bSelectTable = OSDFontTble1;    
    OSDShowTitleString();  
    SetOSDUpdUsrFlag();
    Custom_System.ucOSD_preview_temp = UserData.ucLBLMode;    
}

void OSDExitSubItm313(void)
{
    OSDClearItemHookIcon(STRING_LAYER_4);//ULEric140415
    UserData.ucLBLMode = Custom_System.ucOSD_preview_temp;
    SetLBLMode();
    Custom_System.ucOSD_preview_temp = UserData.ucBFMode;
    OSDExitSubItms(CursorPos(OSD_SUBITEM_3_1_2_STATE_BEG,usOSDState));
    usOSDState = OSD_ITEM_3_1_2_STATE;
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_2_9_END, usOSDState));
    
}


void OSDConfirmSubItm313(void)//ULEric140402
{
    OSDClearItemHookIcon(STRING_LAYER_4);//ULEric140415
//    OSDClearItemHookIcon(STRING_LAYER_3);//ULEric140403
//    UserData.ucBFMode = PICTURE_MODE_LOW_BL;    
    //UserData.ucLBLMode = CursorPos(OSD_SUBITEM_3_1_3_STATE_BEG,usOSDState);        
    //UserSetBF();
    //SetLBLMode();
    OSDExitSubItms(CursorPos(OSD_SUBITEM_3_1_2_STATE_BEG,usOSDState));
    Custom_System.ucOSD_preview_temp = UserData.ucBFMode;
    usOSDState = OSD_ITEM_3_1_1_STATE + UserData.ucBFMode;
    //OSDFocusItm31();//ULEric140410
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_2_9_END, usOSDState));
    OSDShowHookIcon(SelectedStringColor_256, OSD_PICTURE_AD_PIC, STRING_LAYER_3, Hook_Icon);
    SetOSDUpdUsrFlag();    
}

void OSDSubItm313Up(void)
{
    OSDUnSelectLBLLayer4Item(CursorPos(OSD_SUBITEM_3_1_2_STATE_BEG,usOSDState));
        usOSDState = PrevState(OSD_SUBITEM_3_1_2_STATE_BEG,OSD_SUBITEM_3_1_2_END,usOSDState);
    UserData.ucLBLMode = CursorPos(OSD_SUBITEM_3_1_2_STATE_BEG,usOSDState);        
    SetLBLMode();
    OSDSelectLBLLayer4Item(CursorPos(OSD_SUBITEM_3_1_2_STATE_BEG, usOSDState));
}

void OSDSubItm313Down(void)
{
    OSDUnSelectLBLLayer4Item(CursorPos(OSD_SUBITEM_3_1_2_STATE_BEG, usOSDState));
        usOSDState = NextState(OSD_SUBITEM_3_1_2_STATE_BEG,OSD_SUBITEM_3_1_2_END,usOSDState);
    UserData.ucLBLMode = CursorPos(OSD_SUBITEM_3_1_2_STATE_BEG,usOSDState);        
    SetLBLMode();
    OSDSelectLBLLayer4Item(CursorPos(OSD_SUBITEM_3_1_2_STATE_BEG, usOSDState));
}



void OSDEnterSubItm411X(void)
{
    UserData.ucLanguage = Custom_System.ucLanguage;
    OSDExitSubItms(CursorPos(OSD_SUBITEM_4_1_1_BEG,usOSDState));
    usOSDState = OSD_ITEM_4_1_1_STATE;

    //OSDLangueSlecetReload();

    //OSDSelectLayer4Item(CursorPos(OSD_SUBITEM_4_1_1_BEG, usOSDState),OSD_LAY4_LANG_UPDOWN);
    SetOSDUpdUsrFlag();
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_1_1_STATE, usOSDState));
}

void OSDEnterSubItm411(void)
{
UCHAR temp;
    Custom_System.ucLanguage = UserData.ucLanguage;
    ucLayer3MenuType = CursorPos(OSD_ITEM_Audio_END,usOSDState);
    OSDClrLayer3Menu(CursorPos(OSD_ITEM_Audio_END,usOSDState));
    usOSDState = OSD_SUBITEM_4_1_1_BEG + UserData.ucLanguage;
    temp = CursorPos(OSD_SUBITEM_4_1_1_BEG,usOSDState);
     if(temp >= 16){
        temp -= 16;
     }
     else if(temp >= 8){
        temp -= 8;
    }
    OSDShowLayer4Menu(temp);
    OSDSelectLayer4Item(CursorPos(OSD_SUBITEM_4_1_1_BEG, usOSDState),OSD_LAY4_LANG_NONE);
    //Justin 140324
}

void OSDExitSubItm411(void)
{
    //UserData.ucLanguage = Custom_System.ucLanguage;
    //OSDLangueSlecetReload();
    Custom_System.ucLanguage = UserData.ucLanguage;
    OSDExitSubItms(CursorPos(OSD_SUBITEM_4_1_1_BEG,usOSDState));
    usOSDState = OSD_ITEM_4_1_1_STATE;

    OSDLangueSlecetReload();

    //OSDSelectLayer4Item(CursorPos(OSD_SUBITEM_4_1_1_BEG, usOSDState),OSD_LAY4_LANG_UPDOWN);

    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_1_1_STATE, usOSDState));

}

void OSDSubItm411Up(void)
{
#if FORCE_NON_CIRCLE_ACTION == ON
    if (usOSDState <= OSD_SUBITEM_4_1_1_BEG)
        return;
#endif // FORCE_NON_CIRCLE_ACTION

    OSDUnSelectLayer4Item(CursorPos(OSD_SUBITEM_4_1_1_BEG, usOSDState), TRUE);
    OSDShowTrianIcon(TRIANGLE_METHOD1, 0, STRING_LAYER_4);//ULEric140401
//    while (1) {
#if FORCE_NON_CIRCLE_ACTION == ON
        usOSDState = NonCirclePrevState(OSD_SUBITEM_4_1_1_BEG,OSD_SUBITEM_4_1_1_END,usOSDState);
#else
        usOSDState = PrevState(OSD_SUBITEM_4_1_1_BEG,OSD_SUBITEM_4_1_1_END,usOSDState);
#endif
//        if (OSDIsSubItemValid(CursorPos(OSD_SUBITEM_4_1_1_BEG, usOSDState)) == TRUE)
//            break;
//    }
   
    Custom_System.ucLanguage =  CursorPos(OSD_SUBITEM_4_1_1_BEG, usOSDState);
    OSDLangueSlecetReload();
    OSDSelectLayer4Item(CursorPos(OSD_SUBITEM_4_1_1_BEG, usOSDState),OSD_LAY4_LANG_UPDOWN);

}

void OSDSubItm411Down(void)
{
#if FORCE_NON_CIRCLE_ACTION == ON
    if (usOSDState >= OSD_SUBITEM_4_1_1_END-1)
        return;
#endif // FORCE_NON_CIRCLE_ACTION

    OSDUnSelectLayer4Item(CursorPos(OSD_SUBITEM_4_1_1_BEG, usOSDState), FALSE);
    OSDShowTrianIcon(TRIANGLE_METHOD1, 0, STRING_LAYER_4);//ULEric140401
//    while (1) {
#if FORCE_NON_CIRCLE_ACTION == ON
        usOSDState = NonCircleNextState(OSD_SUBITEM_4_1_1_BEG,OSD_SUBITEM_4_1_1_END,usOSDState);
#else
        usOSDState = NextState(OSD_SUBITEM_4_1_1_BEG,OSD_SUBITEM_4_1_1_END,usOSDState);
#endif
//        if (OSDIsSubItemValid(CursorPos(OSD_SUBITEM_4_1_1_BEG, usOSDState)) == TRUE)
//            break;
//    }
    
    Custom_System.ucLanguage =  CursorPos(OSD_SUBITEM_4_1_1_BEG, usOSDState);
    OSDLangueSlecetReload();

    OSDSelectLayer4Item(CursorPos(OSD_SUBITEM_4_1_1_BEG, usOSDState),OSD_LAY4_LANG_UPDOWN);
}

void OSDEnterSubItm412(void)
{
    ucLayer3MenuType = CursorPos(OSD_ITEM_Audio_END,usOSDState);
    OSDClrLayer3Menu(CursorPos(OSD_ITEM_Audio_END,usOSDState));
    usOSDState = OSD_SUBITEM_4_1_2_BEG + (UserData.ucOSDTimer/5)-1;//ULEric140401
    OSDShowLayer4Menu(CursorPos(OSD_SUBITEM_4_1_2_BEG,usOSDState));
    OSDSelectLayer4Item(CursorPos(OSD_SUBITEM_4_1_2_BEG, usOSDState),OSD_LAY4_LANG_NONE);//ULEric140401
}

void OSDConfirmSubItm412(void)//ULEric140401
{
    UserData.ucOSDTimer = (CursorPos(OSD_SUBITEM_4_1_2_BEG, usOSDState)+1)*5;
    OSDConfigTimeout(UserData.ucOSDTimer);        
    OSDExitSubItms(CursorPos(OSD_SUBITEM_4_1_2_BEG,usOSDState));
    usOSDState = OSD_ITEM_4_1_2_STATE;
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_1_1_STATE, usOSDState));
    SetOSDUpdUsrFlag();
}

void OSDExitSubItm412(void)
{
    OSDExitSubItms(CursorPos(OSD_SUBITEM_4_1_2_BEG,usOSDState));
    usOSDState = OSD_ITEM_4_1_2_STATE;
    OSDSelectLayer3Item(CursorPos(OSD_ITEM_4_1_1_STATE, usOSDState));
}

void OSDSubItm412Up(void)
{
    OSDUnSelectLayer4Item(CursorPos(OSD_SUBITEM_4_1_2_BEG, usOSDState), TRUE);
//    while (1) {
//#if FORCE_NON_CIRCLE_ACTION == ON
        //usOSDState = NonCirclePrevState(OSD_SUBITEM_4_1_2_BEG,OSD_SUBITEM_4_1_2_END,usOSDState);
//#else
        usOSDState = PrevState(OSD_SUBITEM_4_1_2_BEG,OSD_SUBITEM_4_1_2_END,usOSDState);
//#endif
//        if (OSDIsSubItemValid(CursorPos(OSD_SUBITEM_4_1_2_BEG, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer4Item(CursorPos(OSD_SUBITEM_4_1_2_BEG, usOSDState),OSD_LAY4_LANG_NONE);
    //UserData.ucOSDTimer = (CursorPos(OSD_SUBITEM_4_1_2_BEG, usOSDState)+1)*5;//ULEric140401
    //OSDConfigTimeout(UserData.ucOSDTimer);    
    //SetOSDUpdUsrFlag();
}

void OSDSubItm412Down(void)
{
    OSDUnSelectLayer4Item(CursorPos(OSD_SUBITEM_4_1_2_BEG, usOSDState), FALSE);
//    while (1) {
//#if FORCE_NON_CIRCLE_ACTION == ON //ULEric140401
        //usOSDState = NonCircleNextState(OSD_SUBITEM_4_1_2_BEG,OSD_SUBITEM_4_1_2_END,usOSDState);
//#else
        usOSDState = NextState(OSD_SUBITEM_4_1_2_BEG,OSD_SUBITEM_4_1_2_END,usOSDState);
//#endif
//        if (OSDIsSubItemValid(CursorPos(OSD_SUBITEM_4_1_2_BEG, usOSDState)) == TRUE)
//            break;
//    }
    OSDSelectLayer4Item(CursorPos(OSD_SUBITEM_4_1_2_BEG, usOSDState),OSD_LAY4_LANG_NONE);
    //UserData.ucOSDTimer = (CursorPos(OSD_SUBITEM_4_1_2_BEG, usOSDState)+1)*5;//ULEric140401
    //OSDConfigTimeout(UserData.ucOSDTimer);
    //SetOSDUpdUsrFlag();
}

void OSDEnterSubItm413(void)
{
    UserData.bOSDLock = ON;
    OSDShowOSDLock();
    KeySetHoldEvent(0xFF, ON);
    usOSDState = OSD_INFO_OSDLOCK_STATE;
    SetOSDUpdUsrFlag();
}

#if MD_ENABLE_FUNC_OSD == ON
//******************************************************************************
// Function Menu Operations
//******************************************************************************
void OSDEnterFuncMenu(void)
{
    usOSDState = OSD_FUNC_1_STATE;
    while (1) {
        if (OSDIsFuncItemValid(CursorPos(OSD_FUNC_BEG,usOSDState)) == TRUE)
            break;
        usOSDState = NextState(OSD_FUNC_BEG,OSD_FUNC_END,usOSDState);
    }
    OSDShowFuncMenu();
    OSDSelectFuncItem(CursorPos(OSD_FUNC_BEG,usOSDState));
}

void OSDExitFuncMenu(void)
{
    usOSDState = OSD_OFF_STATE;
    OSDCloseFuncMenu();
}

void OSDFuncMenuUp(void)
{
    OSDUnselectFuncItem(CursorPos(OSD_FUNC_BEG,usOSDState));
    while (1) {
        usOSDState = NextState(OSD_FUNC_BEG,OSD_FUNC_END,usOSDState);
        if (OSDIsFuncItemValid(CursorPos(OSD_FUNC_BEG,usOSDState)) == TRUE)
            break;
    }
    OSDSelectFuncItem(CursorPos(OSD_FUNC_BEG,usOSDState));
}

void OSDFuncMenuDown(void)
{
    OSDUnselectFuncItem(CursorPos(OSD_FUNC_BEG,usOSDState));
    while (1) {
        usOSDState = PrevState(OSD_FUNC_BEG,OSD_FUNC_END,usOSDState);
        if (OSDIsFuncItemValid(CursorPos(OSD_FUNC_BEG,usOSDState)) == TRUE)
            break;
    }
    OSDSelectFuncItem(CursorPos(OSD_FUNC_BEG,usOSDState));
}

void OSDEnterFunc1(void)
{
    usOSDState = OSD_FNITM_1_STATE;
    OSDFocusFunc1();
}

void OSDExitFunc1(void)
{
    OSDConfirmFunc1();
    usOSDState = OSD_FUNC_1_STATE;
    OSDFocusFuncMenu(CursorPos(OSD_FUNC_BEG,usOSDState));
}

void OSDEnterFunc2(void)
{
    usOSDState = OSD_FNITM_2_STATE;
    OSDFocusFunc2();
}

void OSDExitFunc2(void)
{
    OSDConfirmFunc2();
    usOSDState = OSD_FUNC_2_STATE;
    OSDFocusFuncMenu(CursorPos(OSD_FUNC_BEG,usOSDState));
}

void OSDEnterFunc3(void)
{
    usOSDState = OSD_FNITM_3_STATE;
    OSDFocusFunc3();
}

void OSDExitFunc3(void)
{
    OSDConfirmFunc3();
    usOSDState = OSD_FUNC_3_STATE;
    OSDFocusFuncMenu(CursorPos(OSD_FUNC_BEG,usOSDState));
}

void OSDEnterFunc4(void)
{
    usOSDState = OSD_FNITM_4_STATE;
    OSDFocusFunc4();
}

void OSDExitFunc4(void)
{
    usOSDState = OSD_FUNC_4_STATE;
    OSDFocusFuncMenu(CursorPos(OSD_FUNC_BEG,usOSDState));
}

void OSDEnterFunc5(void)
{
    usOSDState = OSD_FNITM_5_STATE;
    OSDFocusFunc5();
}

void OSDExitFunc5(void)
{
    usOSDState = OSD_FUNC_5_STATE;
    OSDFocusFuncMenu(CursorPos(OSD_FUNC_BEG,usOSDState));
}

void OSDEnterFunc6(void)
{
    usOSDState = OSD_FNITM_6_STATE;
    OSDFocusFunc6();
}

void OSDExitFunc6(void)
{
    usOSDState = OSD_FUNC_6_STATE;
    OSDFocusFuncMenu(CursorPos(OSD_FUNC_BEG,usOSDState));
}
#endif

void OSDEnterAuto(void)
{
#if !lrd_dis_benq
    if (GetScalerSyncMode(_MainChannel) != DIG_SYNC ) {
        usOSDState = OSD_AUTOTUNE_STATE;
        OSDPerformAuto();
        OSDCloseAll();
    }
#endif
}

void OSDEnterNormal(void)
{
    if (GetProductModeFlag() == FALSE) {
        usOSDState = OSD_INFO_NOTICE_STATE;
    }
    OSDPerformNormal();
}

void OSDEnterNoSync(void)
{
    usOSDState = OSD_INFO_NOSYNC_STATE;
    OSDShowNoSync();
}

void OSDEnterNoCable(void)
{
    usOSDState = OSD_INFO_NOCABLE_STATE;
    if(SystemData.bBurnIn == FALSE){
        OSDShowNoCable();
    }
}

void OSDEnterOOL(void)
{
    usOSDState = OSD_INFO_OUTOFLIMIT_STATE;
    OSDShowOOL();
}

void OSDEnterOOR(void)
{
    usOSDState = OSD_INFO_OUTOFRANCE_STATE;
    OSDShowOOR();
}

void OSDEnterFactory(void)
{
    usOSDState = OSD_FACT_STATE;
    OSDShowFactory();
}

void OSDUpFactory(void)
{
    usOSDState = OSD_FACT_STATE;
    OSDFactoryUp();
}

void OSDDnFactory(void)
{
    usOSDState = OSD_FACT_STATE;
    OSDFactoryDown();
}

void OSDEnterFItm(void)
{
    usOSDState = OSD_FITM_STATE;
    OSDFactoryEnterItm();
}

void OSDExitFItm(void)
{
    usOSDState = OSD_FACT_STATE;
    OSDFactoryExitItm();
}

void OSDExitFItm2(void)
{
#if TPV_CLEAR_EE == ON
    if(ucFactoryIndex == mfCLEAR_EE){
     if(SystemData.bClear_EE){
            NvramInitialize(NVRAM_UPDATE_ALL);
            EA = 0;
            while(1) {};
     }
    }
#endif
#if TPV_CLEAR_TIMER == ON
     if(SystemData.bClear_Timer){
              SystemData.ucMonitorPowerOnTimerM = 0;
              SystemData.usMonitorPowerOnTimerH = 0;
              SystemData.ucPowerOnTimerM = 0;
              SystemData.usPowerOnTimerH = 0;      
              SetOSDUpdSysFlag();
     }                    
#endif
    
    usOSDState = OSD_FACT_STATE;
    OSDFactoryExitItm();
}

void OSDUpFItm(void)
{
    usOSDState = OSD_FITM_STATE;
    OSDFactoryItmUp();
}

void OSDDnFItm(void)
{
    usOSDState = OSD_FITM_STATE;
    OSDFactoryItmDown();
}
//For BENQ Service Menu
void OSDEnterServiceMenu(void)
{
    usOSDState = OSD_SM_STATE;
    OSDShowServiceMenu();
}

void OSDUpServiceMenu(void)
{
    usOSDState = OSD_SM_STATE;
    OSDServiceMenuUp();
}

void OSDDnServiceMenu(void)
{
    usOSDState = OSD_SM_STATE;
    OSDServiceMenuDown();
}

void OSDExitSmartReminder(void)
{
    OSDCloseAll();
    UserGetSmartReminderTimer();
    OSDResetSmartRemiderTimer(FALSE);
}
void OSDAdjSMItm(void)
{
    usOSDState = OSD_SM_STATE;
    OSDServiceMenuAdjItm();
}
//For BENQ Service Menu
void OSDDummyFunction(void)
{
}

UCHAR fnGetCustomerKeyItem()
{
    switch (ucCustomerKeyType) {
        case 0:
            return UserData.ucCustomerKey1;

        case 1:
            return UserData.ucCustomerKey2;

        case 2:
            return UserData.ucCustomerKey3;

        default:
            return 0;
    }
}

void OSDErgoTimeUp(void){
    OSD_Select_Temp = ((OSD_Select_Temp - 1 + ERGO_TIME_NUM) % ERGO_TIME_NUM);
}

void OSDErgoTimeDown(void){
    OSD_Select_Temp = ((OSD_Select_Temp + 1) % ERGO_TIME_NUM);
}
void OSDErgoDurationUp(void){
    OSD_Select_Temp = ((OSD_Select_Temp- 1 + ERGO_DURATION_NUM) % ERGO_DURATION_NUM);
}

void OSDErgoDurationDown(void){
    OSD_Select_Temp = ((OSD_Select_Temp + 1) % ERGO_DURATION_NUM);
}
void OSD_SetSmartRemider(void){
    UserData.bSmartReminder = bOSD_Select_Temp;
    
}

void OSD_SetErgoTime(void){
    UserData.ucErgoTime = OSD_Select_Temp;
    UserGetSmartReminderTimer();
    OSDResetSmartRemiderTimer(FALSE);    
}


void OSD_SetErgoDuration(void){
    UserData.ucErgoDuration = OSD_Select_Temp;
    UserGetSmartReminderTimer();    
}

//ULEric140410
void OSDConfirmResetInfor(void)
{
    OSDDialogBlinkSelectIcon(0);
    OSDCloseAll();
    OSDConfirmRecall();
    SetReShowMenuIdx(OSD_MAIN_4_12_STATE);
    OSDReShowMenu();
    OSDUpdateKeyInfo(OSD_MAIN_4_12_STATE);
}

void OSDExitResetInfor(void)
{
    OSDDialogBlinkSelectIcon(1);
    OSDCloseAll();
    SetReShowMenuIdx(OSD_MAIN_4_12_STATE);
    OSDReShowMenu();
    OSDUpdateKeyInfo(OSD_MAIN_4_12_STATE);
}

void OSDConfirmResetColorInfor(void)
{
    OSDDialogBlinkSelectIcon(0);
    OSDCloseAll();
    UserSetColorReset();
    SetReShowMenuIdx(OSD_MAIN_2_8_STATE);
    OSDReShowMenu();
    OSDUpdateKeyInfo(OSD_MAIN_2_8_STATE);
}

void OSDExitResetColorInfor(void)
{
    OSDDialogBlinkSelectIcon(1);
    OSDCloseAll();
    SetReShowMenuIdx(OSD_MAIN_2_8_STATE);
    OSDReShowMenu();
    OSDUpdateKeyInfo(OSD_MAIN_2_8_STATE);
}

void OSDConfirmDCRInfor(void)
{
    OSDDialogBlinkSelectIcon(0);
    OSDCloseAll();        
    SetReShowMenuIdx(OSD_ITEM_3_3_STATE);
    if (++UserData.ucDynamicContrast > MAXIMUM_DYNCONTRAST) {
    UserData.ucDynamicContrast  = MAXIMUM_DYNCONTRAST;
    }
    UserSetDCR();    
    OSDReShowMenu();
    OSDUpdateKeyInfo(OSD_ITEM_3_3_STATE);
    SetOSDUpdUsrFlag();    
}

void OSDExitDCRInfor(void)
{
    OSDDialogBlinkSelectIcon(1);
    OSDCloseAll();
    SetReShowMenuIdx(OSD_ITEM_3_3_STATE);
    OSDReShowMenu();
    OSDUpdateKeyInfo(OSD_ITEM_3_3_STATE);
}

void OSDResetSmartRemiderTimer(BOOL force)
{
    if((UserData.bSmartReminder != bOSD_Select_Temp)||(force)){
        usOSDSRIntervalTimerL = GetTimerTick();
        usOSDSRIntervalTimerH = 0;
    }
}

