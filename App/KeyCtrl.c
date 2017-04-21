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
typedef enum _KEY_STATE_ {
    KEY_NML_STATE,
    KEY_REPEAT_STATE,
    KEY_HOLD_STATE,
    KEY_MULTIFUNC_STATE,
    KEY_LOCK_STATE
} KeyState;

#define KeyGetRepeatStatus(idx) ((usKeyRepeatFlags >> idx) & BIT0)
#define KeySetRepeatStatus(idx) (usKeyRepeatFlags |= (BIT0 << idx))
#define KeyClrRepeatStatus(idx) (usKeyRepeatFlags &= ~((USHRT)BIT0 << idx))
#define KeySetAllRepeatStatus() (usKeyRepeatFlags = 0xFFFF)
#define KeyClrAllRepeatStatus() (usKeyRepeatFlags = 0x0000)
#define KeyGetHoldStatus(idx)   ((usKeyHoldFlags >> idx) & BIT0)
#define KeySetHoldStatus(idx)   (usKeyHoldFlags |= (BIT0 << idx))
#define KeyClrHoldStatus(idx)   (usKeyHoldFlags &= ~((USHRT)BIT0 << idx))
#define KeySetAllHoldStatus()   (usKeyHoldFlags = 0xFFFF)
#define KeyClrAllHoldStatus()   (usKeyHoldFlags = 0x0000)
#define KeyGetMFuncStatus(idx)   ((usKeyMFuncFlags >> idx) & BIT0)
#define KeySetMFuncStatus(idx)   (usKeyMFuncFlags |= (BIT0 << idx))
#define KeyClrMFuncStatus(idx)   (usKeyMFuncFlags &= ~((USHRT)BIT0 << idx))
#define KeySetAllMFuncStatus()   (usKeyMFuncFlags = 0xFFFF)
#define KeyClrAllMFuncStatus()   (usKeyMFuncFlags = 0x0000)
#define KeyGetLockStatus(idx)   ((usKeyLockFlags >> idx) & BIT0)
#define KeySetLockStatus(idx)   (usKeyLockFlags |= (BIT0 << idx))
#define KeyClrLockStatus(idx)   (usKeyLockFlags &= ~((USHRT)BIT0 << idx))
#define KeySetAllLockStatus()   (usKeyLockFlags = 0xFFFF)
#define KeyClrAllLockStatus()   (usKeyLockFlags = 0x0000)

//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************
static code UCHAR ucKeyEventMapTable[NUM_KEY_EVENTS][2] = {
        0x00, KEYEVT_NONE,
        KEYCODE_PWR, KEYEVT_PWR,
        KEYCODE_MENU, KEYEVT_MENU,
        KEYCODE_AUTO, KEYEVT_AUTO,
        KEYCODE_INPUT, KEYEVT_INPUT,
        KEYCODE_FUNC, KEYEVT_FUNC,
        KEYCODE_UP, KEYEVT_UP,
        KEYCODE_DOWN, KEYEVT_DOWN,
        KEYCODE_LEFT, KEYEVT_LEFT,
        KEYCODE_RIGHT, KEYEVT_RIGHT,
        KEYCODE_FACT, KEYEVT_FACT,
        KEYCODE_PWLOCK, KEYEVT_PWLOCK,
        KEYCODE_OSDLOCK, KEYEVT_OSDLOCK,
        KEYCODE_TMG_SW, KEYEVT_TIMING_SWITCH,
        KEYCODE_DEMO, KEYEVT_DEMO,
};

static xdata UCHAR ucMultiFuncKeyEvtTable[NUM_KEY_EVENTS] = {0x00};
static xdata USHRT usKeyRepeatFlags = 0x0000;
static xdata USHRT usKeyHoldFlags = 0x0000;
static xdata USHRT usKeyMFuncFlags = 0x0000;
static xdata USHRT usKeyLockFlags = 0x0000;
static xdata USHRT usKeyHoldTime = KEY_HOLD_TIME;
static xdata USHRT usKeyRepeatTime = KEY_REPEAT_TIME;
static xdata USHRT usKeyLongPressTime = KEY_LONG_PRESS_TIME;

//******************************************************************************
// S T A T I C   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
static UCHAR SearchKeyCodeIndex(UCHAR cd);
static UCHAR SearchKeyEventIndex(UCHAR evt);
static UCHAR KeyGetKeyEvent(void);

//******************************************************************************
// Prototype:
//  void KeyActionDispatcher(UCHAR event)
// Parameters:
//  event   : event from system
// Return:
//  None
// Purpose:
//  Perform key action by event id
// Notes:
//  None
//******************************************************************************
void KeyActionDispatcher(UCHAR event)
{
    switch (event) {
        default:
            break;
    }
}

//******************************************************************************
// Prototype:
//  UCHAR KeyActionDemander(void)
// Parameters:
//  None
// Return:
//  key event
// Purpose:
//  Return key event to system event handler
// Notes:
//  None
//******************************************************************************
UCHAR KeyActionDemander(void)
{
    UCHAR evt;

    evt = KeyGetKeyEvent();

    return evt;
}

//******************************************************************************
// Prototype:
//  static UCHAR SearchKeyCodeIndex(UCHAR cd)
// Parameters:
//  code : Key code
// Return:
//  Index of key code
// Purpose:
//  Search index of key code
// Notes:
//  None
//******************************************************************************
static UCHAR SearchKeyCodeIndex(UCHAR cd)
{
    UCHAR i;
    for (i = 0; i < NUM_KEY_EVENTS; i++) {
        if (cd == ucKeyEventMapTable[i][0]) {
            break;
        }
    }

    // If no code is found, then zero the index.
    i = i % NUM_KEY_EVENTS;

    return i;
}

//******************************************************************************
// Prototype:
//  static UCHAR SearchKeyEventIndex(UCHAR evt)
// Parameters:
//  evt : Key event
// Return:
//  Index of key event
// Purpose:
//  Search index of key event
// Notes:
//  None
//******************************************************************************
static UCHAR SearchKeyEventIndex(UCHAR evt)
{
    UCHAR i;
    for (i = 0; i < NUM_KEY_EVENTS; i++) {
        if (evt == ucKeyEventMapTable[i][1]) {
            break;
        }
    }

    // If no evt is found, then zero the index.
    i = i % NUM_KEY_EVENTS;

    return i;
}

//******************************************************************************
// Prototype:
//  static UCHAR KeyGetKeyEvent(void)
// Parameters:
//  None
// Return:
//  key event
// Purpose:
//  Return key event to system event handler
// Notes:
//  None
//******************************************************************************
static UCHAR KeyGetKeyEvent(void)
{
    static USHRT localtimer, holdtime;
    static UCHAR prev_key_idx = 0x00;
    static KeyState key_state = KEY_NML_STATE;
    UCHAR cur_key_idx, evt;

    evt = ScanKeyPad();

    cur_key_idx = SearchKeyCodeIndex(evt);

    if (prev_key_idx != cur_key_idx) {
        if (cur_key_idx == 0x00) {
            if (key_state == KEY_MULTIFUNC_STATE)  {
                cur_key_idx = prev_key_idx;
                prev_key_idx = 0x00;
                key_state = KEY_NML_STATE;
            }
            else {
                prev_key_idx = cur_key_idx;
            }
        }
        else {
            prev_key_idx = cur_key_idx;
            key_state = KeyGetRepeatStatus(cur_key_idx) ? KEY_REPEAT_STATE : KEY_NML_STATE;
            key_state = KeyGetHoldStatus(cur_key_idx) ? KEY_HOLD_STATE : key_state;
            key_state = KeyGetMFuncStatus(cur_key_idx) ? KEY_MULTIFUNC_STATE : key_state;
            key_state = KeyGetLockStatus(cur_key_idx) ? KEY_LOCK_STATE : key_state;

            localtimer = GetTimerTick();
            if (key_state == KEY_REPEAT_STATE) {
                holdtime = usKeyHoldTime;
            }
            if (key_state == KEY_HOLD_STATE) {
                holdtime = usKeyLongPressTime;
                cur_key_idx = 0x00;
            }
            if (key_state == KEY_MULTIFUNC_STATE) {
                holdtime = usKeyLongPressTime;
                cur_key_idx = 0x00;
            }
            if (key_state == KEY_LOCK_STATE) {
                prev_key_idx = 0x00;
                cur_key_idx = 0x00;
            }
        }
    }
    else if ((cur_key_idx != 0x00) && (key_state == KEY_HOLD_STATE)) {
        if ((GetTimerTick() - localtimer) > holdtime) {
            key_state = KEY_NML_STATE;
            if(UserData.bOSDLock){
            cur_key_idx = 12;
            }
        }
        else {            
            if(!UserData.bOSDLock){
            cur_key_idx = 0x00;
            }
        }
    }
    else if ((cur_key_idx != 0x00) && (key_state == KEY_MULTIFUNC_STATE)) {
        if ((GetTimerTick() - localtimer) > holdtime) {
            key_state = KEY_NML_STATE;
            cur_key_idx = SearchKeyEventIndex(ucMultiFuncKeyEvtTable[cur_key_idx]);
        }
        else {
            cur_key_idx = 0x00;
        }
    }
    else if ((cur_key_idx != 0x00) && (key_state == KEY_REPEAT_STATE)) {   
        #if (OSDTYPE == OSD_BENQ_V2)
        OSDClearKeyColor(TRUE);
        #endif
        if ((GetTimerTick() - localtimer) > holdtime) {
            localtimer = GetTimerTick();
            holdtime = usKeyRepeatTime;
        }
        else {
            cur_key_idx = 0x00;
        }
    }
    else {
        #if (OSDTYPE == OSD_BENQ_V2)
        OSDClearKeyColor(FALSE);
        #endif
        localtimer = GetTimerTick();
        key_state = KEY_NML_STATE;
        cur_key_idx = 0x00;
    }

    evt = ucKeyEventMapTable[cur_key_idx][1];

    return evt;
}

//******************************************************************************
// Prototype:
//  void KeySetRepeatEvent(UCHAR evt, UCHAR rpt)
// Parameters:
//  evt : Key event
//  rpt : On/Off key repeating
// Return:
//  None
// Purpose:
//  Set key repeating by key event
// Notes:
//  None
//******************************************************************************
void KeySetRepeatEvent(UCHAR evt, UCHAR rpt)
{
    UCHAR i;

    if (evt == 0xFF) {
        // repeat all event
        if (rpt == ON) {
            KeySetAllRepeatStatus();
        }
        else {
            KeyClrAllRepeatStatus();
        }
    }

    i = SearchKeyEventIndex(evt);
    if (i) {
        if (rpt == ON) {
            KeySetRepeatStatus(i);
        }
        else {
            KeyClrRepeatStatus(i);
        }
    }
}

//******************************************************************************
// Prototype:
//  void KeySetHoldEvent(UCHAR evt, UCHAR hold)
// Parameters:
//  evt : Key event
//  hold : On/off holding key
// Return:
//  None
// Purpose:
//  Enable / disable holding keys by key event
// Notes:
//  None
//******************************************************************************
void KeySetHoldEvent(UCHAR evt, UCHAR hold)
{
    UCHAR i;

    if (evt == 0xFF) {
        // hold all event
        if (hold == ON) {
            KeySetAllHoldStatus();
        }
        else {
            KeyClrAllHoldStatus();
        }
    }

    i = SearchKeyEventIndex(evt);
    if (i) {
        if (hold == ON) {
            KeySetHoldStatus(i);
        }
        else {
            KeyClrHoldStatus(i);
        }
    }
}

//******************************************************************************
// Prototype:
//  void KeySetMFuncEvent(UCHAR major, UCHAR minor)
// Parameters:
//  major : Major key event for short-term key press
//  minor : Minor key event for long-term key press
// Return:
//  None
// Purpose:
//  Set multi-function key events
// Notes:
//  None
//******************************************************************************
void KeySetMFuncEvent(UCHAR major, UCHAR minor)
{
    UCHAR i;

    if (major == 0xFF) {
        // lock all event
        if (minor == 0x00) {
            KeyClrAllMFuncStatus();
        }
    }

    i = SearchKeyEventIndex(major);
    if (i) {
        ucMultiFuncKeyEvtTable[i] = minor;
        if (minor != 0x00) {
            KeySetMFuncStatus(i);
        }
        else {
            KeyClrMFuncStatus(i);
        }
    }
}

//******************************************************************************
// Prototype:
//  void KeySetLockEvent(UCHAR evt, UCHAR lock)
// Parameters:
//  evt : Key event
//  lock : Lock / unlock key
// Return:
//  None
// Purpose:
//  Lock / unlock key by key event
// Notes:
//  None
//******************************************************************************
void KeySetLockEvent(UCHAR evt, UCHAR lock)
{
    UCHAR i;

    if (evt == 0xFF) {
        // lock all event
        if (lock == ON) {
            KeySetAllLockStatus();
        }
        else {
            KeyClrAllLockStatus();
        }
    }

    i = SearchKeyEventIndex(evt);
    if (i) {
        if (lock == ON) {
            KeySetLockStatus(i);
        }
        else {
            KeyClrLockStatus(i);
        }
    }
}

//******************************************************************************
// Prototype:
//  void KeySetHoldTime(USHRT time)
// Parameters:
//  time : Time to hold key
// Return:
//  None
// Purpose:
//  Set key hold time
// Notes:
//  None
//******************************************************************************
void KeySetHoldTime(USHRT time)
{
    usKeyHoldTime = time;
}

//******************************************************************************
// Prototype:
//  void KeySetRepeatTime(USHRT time)
// Parameters:
//  time : Time to repeat key
// Return:
//  None
// Purpose:
//  Set key repeat time
// Notes:
//  None
//******************************************************************************
void KeySetRepeatTime(USHRT time)
{
    usKeyRepeatTime = time;
}

//******************************************************************************
// Prototype:
//  void KeySetLongPressTime(USHRT time)
// Parameters:
//  time : Time to long press key
// Return:
//  None
// Purpose:
//  Set key long press time
// Notes:
//  None
//******************************************************************************
void KeySetLongPressTime(USHRT time)
{
    usKeyLongPressTime = time;
}
