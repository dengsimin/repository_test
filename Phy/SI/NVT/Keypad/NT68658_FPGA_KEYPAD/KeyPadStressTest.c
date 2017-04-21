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
#include "KeyPadStressTest.h"

#if MD_ENABLE_STRESS_TEST_KEY == ON

//******************************************************************************
// G L O B A L   D E F I N I T I O N S
//******************************************************************************

//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************
static UCHAR ucTestMode;

//******************************************************************************
// E X T E R N A L   V A R I A B L E   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// S T A T I C   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
static void ChangeTestMode(void);
static void SetTestDPLL(ULONG dclk);

//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
BOOL CheckModuleTestKey(UCHAR key_buffer)
{
#if KEYCODE_FUNC != 0x00
    USHRT local_timer;
    
    //module test
    if (key_buffer == KEYCODE_FUNC) {
        local_timer = GetTimerTick();
        do {
            // Perform AD Key decode
            while (McuGetADC(KEY_GROUP1_ADC) < 0x78) {
                McuPowerUpADC();
                McuStartADC();
                McuWaitADCComplete();
                McuPowerDownADC();
                ResetWDTimer();
                local_timer = GetTimerTick();
            }
            while (McuGetADC(KEY_GROUP2_ADC) < 0x78) {
                McuPowerUpADC();
                McuStartADC();
                McuWaitADCComplete();
                McuPowerDownADC();
                ResetWDTimer();
                local_timer = GetTimerTick();
            }
        } while ((GetTimerTick()-local_timer) < 100);
        ChangeTestMode();
        return TRUE;
    }
    else if (key_buffer == KEYCODE_PWR) {
        ucTestMode = 0;        
    }
#endif
    return FALSE;
}

static void ChangeTestMode(void)
{
    if (++ucTestMode >= STRESSOVER) {
//    if (++ucTestMode >= DPLLTEST50) {
        ucTestMode = 0;
    }
//    Sleep(500);
    switch (ucTestMode) {
        case VGATEST:
            UserData.ucInputSource = INPUT_SC_VGA;
            UserSetInputSource();
            break;
        case DVITEST:
            UserData.ucInputSource = INPUT_SC_DVI;
            UserSetInputSource();
            break;
/*
        case HDMITEST:
            UserData.ucInputSource = INPUT_SC_HDMI;
            UserSetInputSource();
            break;
*/
        case DPLLTEST50:
            OSDCloseAll();
            OSDInitFrame(25, 5, (((I_WHITE-1)<<8)|(I_TBLACK<<4)));
            OSDAPI_SetPosition(99, 98);
            OSDShowNum(10, 2, 50);
            OSDTurnOnOSD();
            SC_DISPLAY_MUTE_CTRL = 0x61;
            SetTestDPLL(50000000);
            break;
        case DPLLTEST60:
            SC_DISPLAY_MUTE_CTRL = 0x61;
            OSDShowNum(10, 2, 60);
            SetTestDPLL(60000000);
            break;
        case DPLLTEST70:
            SC_DISPLAY_MUTE_CTRL = 0x61;
            OSDShowNum(10, 2, 70);
            SetTestDPLL(70000000);
            break;
        case DPLLTEST80:
            SC_DISPLAY_MUTE_CTRL = 0x61;
            OSDShowNum(10, 2, 80);
            SetTestDPLL(80000000);
            break;
        case DPLLTEST90:
            SC_DISPLAY_MUTE_CTRL = 0x61;
            OSDShowNum(10, 2, 90);
            SetTestDPLL(90000000);
            break;
        case DPLLTEST100:
            SC_DISPLAY_MUTE_CTRL = 0x61;
            OSDShowNum(10, 2, 100);
            SetTestDPLL(100000000);
            break;
        case DPLLTEST110:
            SC_DISPLAY_MUTE_CTRL = 0x61;
            OSDShowNum(10, 2, 110);
            SetTestDPLL(110000000);
            break;
        case DPLLTEST120:
            SC_DISPLAY_MUTE_CTRL = 0x61;
            OSDShowNum(10, 2, 120);
            SetTestDPLL(120000000);
            break;
        case DPLLTEST130:
            SC_DISPLAY_MUTE_CTRL = 0x61;
            OSDShowNum(10, 2, 130);
            SetTestDPLL(130000000);
            break;
        case DPLLTEST140:
            SC_DISPLAY_MUTE_CTRL = 0x61;
            OSDShowNum(10, 2, 140);
            SetTestDPLL(140000000);
            break;
        case DPLLTEST150:
            SC_DISPLAY_MUTE_CTRL = 0x61;
            OSDShowNum(10, 2, 150);
            SetTestDPLL(150000000);
            break;
        case DPLLTEST160:
            SC_DISPLAY_MUTE_CTRL = 0x61;
            OSDShowNum(10, 2, 160);
            SetTestDPLL(160000000);
            break;
        case DPLLTEST170:
            SC_DISPLAY_MUTE_CTRL = 0x61;
            OSDShowNum(10, 2, 170);
            SetTestDPLL(170000000);
            break;
        case DPLLTEST180:
            SC_DISPLAY_MUTE_CTRL = 0x61;
            OSDShowNum(10, 2, 180);
            SetTestDPLL(180000000);
            break;
        case DPLLTEST190:
            SC_DISPLAY_MUTE_CTRL = 0x61;
            OSDShowNum(10, 2, 190);
            SetTestDPLL(190000000);
            break;
        case DPLLTEST200:
            SC_DISPLAY_MUTE_CTRL = 0x61;
            OSDShowNum(10, 2, 200);
            SetTestDPLL(200000000);
            break;
/*
        case DPLLTEST210:
            SC_DISPLAY_MUTE_CTRL = 0x61;
            OSDShowNum(10, 2, 210);
            SetTestDPLL(210000000);
            break;
*/
    }
//    if (++ucTestMode >= STRESSOVER) {
/*    if (++ucTestMode >= DPLLTEST50) {
        ucTestMode = 0;
    }*/
}

static void SetTestDPLL(ULONG dclk)
{
    ULONG temp;

//    SC_VPLL_CTRL |= BIT3;//audio 頻率校正暫停
    temp = ((float)dclk * 131072) / REF_CLK;
    SC_DDDS_RATIO_LO = (UCHAR) temp;
    SC_DDDS_RATIO_MI = (UCHAR) (temp >> 8);
    WaitDisVSync();
    SC_DDDS_RATIO_HI = (UCHAR) (temp >> 16);
//    SC_VPLL_CTRL &= ~BIT3;//audio 頻率校正打開
}
#endif
