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
#if MD_ENABLE_STRESS_TEST_KEY == ON
#include "KeyPadStressTest.h"
#endif

//******************************************************************************
// G L O B A L   D E F I N I T I O N S
//******************************************************************************
#define KEY_MIN_LEVEL0 ((KEY_TYP_LEVEL0+KEY_TYP_LEVEL1)/2)
#define KEY_MIN_LEVEL1 ((KEY_TYP_LEVEL1+KEY_TYP_LEVEL2)/2)
#define KEY_MIN_LEVEL2 ((KEY_TYP_LEVEL2+KEY_TYP_LEVEL3)/2)
#ifdef FOURKEY_IN_ONE_ADC
#define KEY_MIN_LEVEL3 ((KEY_TYP_LEVEL3+KEY_TYP_LEVEL4)/2)
#endif
//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************
#if MD_ENABLE_AO_DETECT == ON
bit bWaitPowerKeyRelease;
xdata USHRT usAOTimer;
#endif

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************

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
//  static UCHAR GetIOKeyCode(UCHAR btn)
// Parameters:
//  None
// Return:
//  Key Code
// Purpose:
//  Get key code
// Notes:
//  None
//******************************************************************************
static UCHAR GetIOKeyCode(UCHAR btn)
{
    static code UCHAR ucIOKeyMap[9][3] = 
		{
        {IOBTN_1_PORT,  IOBTN_1_BIT,  IOBTN_1_ACTIVE},
        {IOBTN_2_PORT,  IOBTN_2_BIT,  IOBTN_2_ACTIVE},
        {IOBTN_3_PORT,  IOBTN_3_BIT,  IOBTN_3_ACTIVE},
        {IOBTN_4_PORT,  IOBTN_4_BIT,  IOBTN_4_ACTIVE},
        {IOBTN_5_PORT,  IOBTN_5_BIT,  IOBTN_5_ACTIVE},
        {IOBTN_6_PORT,  IOBTN_6_BIT,  IOBTN_6_ACTIVE},
        {IOBTN_7_PORT,  IOBTN_7_BIT,  IOBTN_7_ACTIVE},
        {IOBTN_8_PORT,  IOBTN_8_BIT,  IOBTN_8_ACTIVE},
        {MCU_PORT_NULL, 0,            0             },
    };

    UCHAR port, pin, act, i;

    // Decode btn id to IOKeyMap order
    port = btn;
    for (i = 0; i < 8; i++) 
		{
	        if (port & BIT0) break;
	        port >>= 1;
    	}

    port = ucIOKeyMap[i][0];
    pin  = ucIOKeyMap[i][1];
    act  = ucIOKeyMap[i][2];

    if ((port != MCU_PORT_NULL) &&(McuGetIOBit(port, pin) == act))       return btn;
    else       return 0x00;
}

//******************************************************************************
// Prototype: 
//  UCHAR ScanKeyPad(void)
// Parameters:
//  None
// Return:
//  Key value
// Purpose:
//  Scan the keypad
// Notes:
//  None
//******************************************************************************
UCHAR ScanKeyPad(void)
{
    static UCHAR key_buffer;
    USHRT local_timer;
    UCHAR key_temp, key_stable_time;
    local_timer = GetTimerTick();
    key_stable_time = 0;
    do {    
        key_temp = GetKey();
        if (key_temp != key_buffer) {
            key_buffer = key_temp;
            local_timer = GetTimerTick();
            key_stable_time = KEY_STABLE_TIME;
        }
    } while ((key_stable_time!=0) && ((GetTimerTick()-local_timer) < key_stable_time));

	
//AO DETECT : Power key detect///////
#if MD_ENABLE_AO_DETECT == ON
#if IS_NT68810_SERIES || IS_NT68870_SERIES
    if (bWaitPowerKeyRelease == TRUE) {//wait release
        key_buffer &= ~KEYCODE_PWR;
        if ((GetTimerTick() - usAOTimer) > AO_KEY_DEBOUNCE_TIME) {//AO timeout
            if ((SC_ZERO_PWR_CTRL_B64 & BIT2) != 0) {
                SC_ZERO_PWR_CTRL_B69 |= BIT0;
                SC_ZERO_PWR_CTRL_B69 &= ~BIT0;
                usAOTimer = GetTimerTick();
            }
            else {
                bWaitPowerKeyRelease = FALSE;
            }
        }
    }
    else {
        if ((key_buffer & KEYCODE_PWR) != 0x00) {
            Sleep(AO_KEY_DEBOUNCE_TIME); //wait HW debounce
        }
        if ((SC_ZERO_PWR_CTRL_B64 & BIT2) != 0) {
            key_buffer |= KEYCODE_PWR;
//            printf("key\r\n");
        }
    }
#else    
    if (bWaitPowerKeyRelease == TRUE) {//wait release
        key_buffer &= ~KEYCODE_PWR;
        if ((GetTimerTick() - usAOTimer) > AO_KEY_DEBOUNCE_TIME) {//AO timeout
            if ((AO_DETECT & BIT2) != 0) {
                AO_DETECT |= BIT2;
                usAOTimer = GetTimerTick();
            }
            else {
                bWaitPowerKeyRelease = FALSE;
            }
        }
    }
    else {
        if ((key_buffer & KEYCODE_PWR) != 0x00) {
            Sleep(AO_KEY_DEBOUNCE_TIME); //wait HW debounce
        }
        if ((AO_DETECT & BIT2) != 0) {
            key_buffer |= KEYCODE_PWR;
//            printf("key\r\n");
        }
    }
#endif
#endif
/////////////////////////////////////
#if MD_ENABLE_STRESS_TEST_KEY == ON
    if(CheckModuleTestKey(key_buffer) == TRUE){
        key_buffer = 0x00;
    }
#endif

    return key_buffer;
}

//******************************************************************************
// Prototype: 
//  UCHAR GetKey(void)
// Parameters:
//  None
// Return:
//  Key value
// Purpose:
//  Scan the keypad
// Notes:
//  None
//******************************************************************************
UCHAR GetKey(void)
{
#define DEBUG_ADC_VALUE   0
    UCHAR key, adc_level;

    key = 0;

    // Perform AD Key decode
    McuPowerUpADC();
    McuStartADC();
    McuWaitADCComplete();
    McuPowerDownADC();
    adc_level = McuGetADC(KEY_GROUP1_ADC);
	#if DEBUG_ADC_VALUE
	OSDShowNum(10,11,adc_level);
	#endif
// 51 79 109  //p+a  ADGRP1_CODE_1 | ADGRP2_CODE_2
    if (adc_level < KEY_MIN_LEVEL0) {
        key |= ADGRP1_CODE_1;
    }
    else if (adc_level > KEY_MIN_LEVEL0 && adc_level < KEY_MIN_LEVEL1) {
        key |= ADGRP1_CODE_2;
    }
    else if (adc_level > KEY_MIN_LEVEL1 && adc_level < KEY_MIN_LEVEL2) {
        key |= ADGRP1_CODE_3;
    }
#ifdef FOURKEY_IN_ONE_ADC
    else if (adc_level > KEY_MIN_LEVEL2 && adc_level < KEY_MIN_LEVEL3) {
        key |= ADGRP1_CODE_4;
    }
#endif
    adc_level = McuGetADC(KEY_GROUP2_ADC);

	#if DEBUG_ADC_VALUE
	OSDShowNum(10,14,adc_level);
	OSDTurnOnOSD();
	#endif

    if (adc_level < KEY_MIN_LEVEL0) {
        key |= ADGRP2_CODE_1;
    }
    else if (adc_level > KEY_MIN_LEVEL0 && adc_level < KEY_MIN_LEVEL1) {
        key |= ADGRP2_CODE_2;
    }
    else if (adc_level > KEY_MIN_LEVEL1 && adc_level < KEY_MIN_LEVEL2) {
        key |= ADGRP2_CODE_3;
    }



    // Perform IO Key decode
    key |= GetIOKeyCode(IOBTN_CODE_1);
    key |= GetIOKeyCode(IOBTN_CODE_2);
    key |= GetIOKeyCode(IOBTN_CODE_3);
    key |= GetIOKeyCode(IOBTN_CODE_4);
    key |= GetIOKeyCode(IOBTN_CODE_5);
    key |= GetIOKeyCode(IOBTN_CODE_6);
    key |= GetIOKeyCode(IOBTN_CODE_7);
    key |= GetIOKeyCode(IOBTN_CODE_8);

    return key;
}

#if 1//MD_ENABLE_AO_DETECT == ON
bit CheckFactoryMode(void)
{
#if (!PWR_AUTO_INTO_FAC)
    #define into_fac_time (3000)
    USHRT press_time = 0;
	if (GetKey() == (KEYCODE_MENU)) { 
        for(press_time=0;press_time< into_fac_time;press_time++)
        {
            if(GetKey() == (KEYCODE_MENU))
                Sleep(1);
            else
                break;
                
        }
        if(press_time == into_fac_time)
        return TRUE;
    }
        return FALSE;   
#else
	if (GetKey() == (KEYCODE_FACT & ~KEYCODE_PWR)) {
        return TRUE;
    }
    return FALSE;   
#endif
}
#endif

