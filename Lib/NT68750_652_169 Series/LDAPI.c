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
#include "ScalerProfile.h"

#if ENABLE_LD == ON

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

//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// F U N C T I O N   B O D Y S
//******************************************************************************

/**************************************************************************//**
 * Initialize LD-related scalers.
 ******************************************************************************/
void LDAPI_Init(void)
{
    // Macro : Local dimming 8 area_750
    SC_LD_MODE_CTRL |= BIT6 | BIT7;
    SC_LD_AOS_THRESHOLD_HI = 0x02;//0x40;
    SC_LD_AOS_THRESHOLD_LO = 0x00;
    SC_LD_DYNAMIC_FRAME_THR = 0x12;
    SC_LD_DUTY_SPEED_CTRL = 0x22;
    SC_LD_ADPS_CTRL = 0x14;
    SC_LD_MIN_DUTY = 0x20;

    SC_LD_ZONE_PITCH = 0x19;

    SC_LD_BE_WIDTH = 0x2C;
    SC_LD_BE_HEIGHT = 0x2C;
    SC_LD_BE_HBOUND_LO = 0x28;
    SC_LD_BE_VBOUND_LO = 0x1C;
    SC_LD_BE_HVBOUND_HI = 0x00;
    SC_LD_BE_OFFSET_LO = 0x50;
    SC_LD_BE_PITCH_LO = 0x40;
    SC_LD_BE_OFFSET_PITCH_HI = 0x00;
}

/**************************************************************************//**
 * Set number of H/V samples.
 * @param num_h Number of horizontal samples.
 * @param num_v Number of veritcal samples.
 ******************************************************************************/
void LDAPI_SetHVSamples(UCHAR num_h, UCHAR num_v)
{
    WriteShortScaler(&SC_LD_BLOCK_WIDTH_LO, (UserPanelData.usWidth + (num_h / 2)) / num_h);
    WriteShortScaler(&SC_LD_BLOCK_HEIGHT_LO, (UserPanelData.usHeight + (num_v / 2)) / num_v);
}

/**************************************************************************//**
 * Set number of H/V zones.
 * @param num_h Number of horizontal zones.
 * @param num_v Number of veritcal zones.
 ******************************************************************************/
void LDAPI_SetHVZones(UCHAR num_h, UCHAR num_v)
{
    SC_LD_H_ZONE_NUM = num_h;
    SC_LD_V_ZONE_NUM = num_v;
    WriteShortScaler(&SC_LD_HBLK_WIDTH_LO, (UserPanelData.usWidth + (num_h / 2)) / num_h);
    WriteShortScaler(&SC_LD_VBLK_HEIGHT_LO, (UserPanelData.usHeight + (num_v / 2)) / num_v);
}

/**************************************************************************//**
 * Set number of pixels of H/V boundary.
 * @param h Number of pixels of horizontal boundary.
 * @param v Number of pixels of vertical boundary.
 ******************************************************************************/
void LDAPI_SetHVBound(UCHAR h, UCHAR v)
{
    WriteShortScaler(&SC_LD_LEFT_BOUND_LO, h);
    WriteShortScaler(&SC_LD_RIGHT_BOUND_LO, UserPanelData.usWidth - h);
    WriteShortScaler(&SC_LD_TOP_BOUND_LO, v);
    WriteShortScaler(&SC_LD_BOTTOM_BOUND_LO, UserPanelData.usHeight - v);
}

/**************************************************************************//**
 * Set PWM sources of each string.
 * @param dim01 Select the PWM sources of LED string7/6.
 * @param dim23 Select the PWM sources of LED string5/4.
 * @param dim45 Select the PWM sources of LED string3/2.
 * @param dim67 Select the PWM sources of LED string1/0.
 ******************************************************************************/
void LDAPI_SetDimDef(UCHAR dim01, UCHAR dim23, UCHAR dim45, UCHAR dim67)
{
    SC_LD_DIM01_DEFINE_CTRL = dim01;
    SC_LD_DIM23_DEFINE_CTRL = dim23;
    SC_LD_DIM45_DEFINE_CTRL = dim45;
    SC_LD_DIM67_DEFINE_CTRL = dim67;
}

/**************************************************************************//**
 * Load LD profile to scaler.
 * @param table Pointer to the LD profile.
 ******************************************************************************/
void LDAPI_LoadTable(LDTable * table)
{
    USHRT i;
    ULONG clk;

    // LD will be fail when DCLK is under 2 x CPU CLK. 
    // To avoid that issue, always force the DCLK greater than 100MHz
    clk = GetDisplayDCLK();
    if (clk < 100000000) {
        SetDisplayDCLK(100000000);
    }
    ResetWDTimer();

    // Local dimming RW Gray2Duty_EVEN
    SC_LD_PORT_INDEX = 0x08;
    SC_LD_INDEX_PORT_ADDRESS_LO = 0x00;
    SC_LD_INDEX_PORT_ADDRESS_HI = 0x00;
    for (i = 0; i < LD_GRAY2DUTY_TABLE_LEN; i++) {
        SC_LD_GRAY_TO_DUTY_TABLE = table->ucGary2DutyTable[0][i];
    }

    // Local dimming RW Gray2Duty_ODD
    SC_LD_PORT_INDEX = 0x09;
    SC_LD_INDEX_PORT_ADDRESS_LO = 0x00;
    SC_LD_INDEX_PORT_ADDRESS_HI = 0x00;
    for (i = 0; i < LD_GRAY2DUTY_TABLE_LEN; i++) {
        SC_LD_GRAY_TO_DUTY_TABLE = table->ucGary2DutyTable[1][i];
    }

    // Local dimming RW Lv2Gain_EVEN
    SC_LD_PORT_INDEX = 0x0A;
    SC_LD_INDEX_PORT_ADDRESS_LO = 0x00;
    SC_LD_INDEX_PORT_ADDRESS_HI = 0x00;
    for (i = 0; i < LD_LV2GAIN_TABLE_LEN; i++) {
        SC_LD_LV_TO_GAIN_TABLE = table->ucLv2GainTable[0][i];
    }

    // Local dimming RW Lv2Gain_ODD
    SC_LD_PORT_INDEX = 0x0B;
    SC_LD_INDEX_PORT_ADDRESS_LO = 0x00;
    SC_LD_INDEX_PORT_ADDRESS_HI = 0x00;
    for (i = 0; i < LD_LV2GAIN_TABLE_LEN; i++) {
        SC_LD_LV_TO_GAIN_TABLE = table->ucLv2GainTable[1][i];
    }

    ResetWDTimer();

    // Local dimming RW Profile Zone1
    SC_LD_PORT_INDEX = 0x00;
    SC_LD_INDEX_PORT_ADDRESS_LO = 0x00;
    SC_LD_INDEX_PORT_ADDRESS_HI = 0x00;
    for (i = 0; i < LD_PROFILE_LEN; i++) {
        SC_LD_LIGHT_PROFILE_TABLE = table->ucLightProfile[0][i];
    }

    ResetWDTimer();

    // Local dimming RW Profile Zone2
    SC_LD_PORT_INDEX = 0x01;
    SC_LD_INDEX_PORT_ADDRESS_LO = 0x00;
    SC_LD_INDEX_PORT_ADDRESS_HI = 0x00;
    for (i = 0; i < LD_PROFILE_LEN; i++) {
        SC_LD_LIGHT_PROFILE_TABLE = table->ucLightProfile[1][i];
    }

    ResetWDTimer();

    // Local dimming RW Profile Zone3
    SC_LD_PORT_INDEX = 0x02;
    SC_LD_INDEX_PORT_ADDRESS_LO = 0x00;
    SC_LD_INDEX_PORT_ADDRESS_HI = 0x00;
    for (i = 0; i < LD_PROFILE_LEN; i++) {
        SC_LD_LIGHT_PROFILE_TABLE = table->ucLightProfile[2][i];
    }

    ResetWDTimer();

    // Local dimming RW Profile Zone4
    SC_LD_PORT_INDEX = 0x03;
    SC_LD_INDEX_PORT_ADDRESS_LO = 0x00;
    SC_LD_INDEX_PORT_ADDRESS_HI = 0x00;
    for (i = 0; i < LD_PROFILE_LEN; i++) {
        SC_LD_LIGHT_PROFILE_TABLE = table->ucLightProfile[3][i];
    }

    ResetWDTimer();

    // Local dimming RW Profile Zone5
    SC_LD_PORT_INDEX = 0x04;
    SC_LD_INDEX_PORT_ADDRESS_LO = 0x00;
    SC_LD_INDEX_PORT_ADDRESS_HI = 0x00;
    for (i = 0; i < LD_PROFILE_LEN; i++) {
        SC_LD_LIGHT_PROFILE_TABLE = table->ucLightProfile[4][i];
    }

    ResetWDTimer();

    // Local dimming RW Profile Zone6
    SC_LD_PORT_INDEX = 0x05;
    SC_LD_INDEX_PORT_ADDRESS_LO = 0x00;
    SC_LD_INDEX_PORT_ADDRESS_HI = 0x00;
    for (i = 0; i < LD_PROFILE_LEN; i++) {
        SC_LD_LIGHT_PROFILE_TABLE = table->ucLightProfile[5][i];
    }

    ResetWDTimer();

    // Local dimming RW Profile Zone7
    SC_LD_PORT_INDEX = 0x06;
    SC_LD_INDEX_PORT_ADDRESS_LO = 0x00;
    SC_LD_INDEX_PORT_ADDRESS_HI = 0x00;
    for (i = 0; i < LD_PROFILE_LEN; i++) {
        SC_LD_LIGHT_PROFILE_TABLE = table->ucLightProfile[6][i];
    }

    ResetWDTimer();

    // Local dimming RW Profile Zone8
    SC_LD_PORT_INDEX = 0x07;
    SC_LD_INDEX_PORT_ADDRESS_LO = 0x00;
    SC_LD_INDEX_PORT_ADDRESS_HI = 0x00;
    for (i = 0; i < LD_PROFILE_LEN; i++) {
        SC_LD_LIGHT_PROFILE_TABLE = table->ucLightProfile[7][i];
    }

    ResetWDTimer();
    if (clk < 100000000) {
        SetDisplayDCLK(clk);
    }
}

/**************************************************************************//**
 * Set LD mode.
 * @param mode One of LD_OFF, LD_ON and LD_DEMO.
 ******************************************************************************/
void LDAPI_SetLDMode(LDMode mode)
{
    SC_LD_PWMA_CTRL1 = SC_PWMA_CTRL1;
    WaitDisVSync();
    Sleep(5);
    switch(mode) {
        case LD_ON:
            SC_LD_CTRL |= BIT0;
            SC_LD_MODE_CTRL &= ~(BIT1 | BIT2);
            SC_OSD_FRAME2_FUNC_CTRL |= BIT2;
            SC_LED_SHORT_CTRL |= BIT1;
            break;
        case LD_DEMO:
            SC_LD_CTRL |= BIT0;
            SC_LD_MODE_CTRL |= (BIT1 | BIT2);
            SC_OSD_FRAME2_FUNC_CTRL |= BIT2;
            SC_LED_SHORT_CTRL |= BIT1;							
            break;
        case LD_OFF:
        default:
            SC_LD_CTRL &= ~BIT0;
            SC_LD_MODE_CTRL &= ~(BIT1 | BIT2);
            SC_OSD_FRAME2_FUNC_CTRL &= ~BIT2;
            SC_LED_SHORT_CTRL &= ~BIT1;			
            break;
    }
    Sleep(80);
    SC_LD_PWMA_CTRL2 = SC_PWMA_CTRL2;
    SC_LD_PWMA_CTRL3 = SC_PWMA_CTRL3;
}

/**************************************************************************//**
 * Set LD brightness.
 * @param duty Duty of brightness. The range is from 0 ~ 255.
 ******************************************************************************/
void LDAPI_SetBrightness(UCHAR duty)
{
    SC_LD_BRIGHTNESS = duty;
}

#endif //ENABLE_LD == ON
