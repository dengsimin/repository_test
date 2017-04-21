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
#define FALIMG_ABRUPT_CHANGE_STEP     OFF
#define RAISIMG_ABRUPT_CHANGE_STEP    OFF
#define FALIMG_ABRUPT_CHANGE_DISABLE  OFF
#define RAISIMG_ABRUPT_CHANGE_DISABLE OFF
//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************
// Setting3
/*
static code UCHAR LDInitTable[82] = {
0x00, 0x40, 0xFF, 0xFF, 0xFF, 0x00, 0x3F, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  //0xE40
0x00, 0x00, 0x28, 0x00, 0x58, 0x07, 0x1C, 0x00, 0x1C, 0x04, 0x50, 0x00, 0x40, 0x00, 0x19, 0x18,  //0xE50
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA0, 0x0A, 0x30, 0x00, 0x48, 0x88,  //0xE60
0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  //0xE70
0x80, 0x0A, 0xFF, 0x00, 0x02, 0x10, 0xFF, 0x00, 0x00, 0x7F, 0x60, 0x00, 0x00, 0x00, 0x44, 0x00,  //0xE80
0xA0, 0x80
};
*/
// Setting4
static code UCHAR LDInitTable[82] = {
0x00, 0x40, 0xFF, 0xFF, 0xFF, 0x00, 0x3F, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  //0xE40
0x80, 0x00, 0x28, 0x00, 0x58, 0x07, 0x1C, 0x00, 0x1C, 0x04, 0x50, 0x00, 0x40, 0x00, 0x19, 0x18,  //0xE50
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA0, 0x0A, 0x30, 0x00, 0x48, 0x88,  //0xE60
0x00, 0x06, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  //0xE70
0x80, 0x0C, 0xFF, 0x00, 0x02, 0x10, 0xFF, 0x00, 0x00, 0x24, 0x80, 0x00, 0x00, 0x00, 0x44, 0x00,  //0xE80
0xA0, 0x80
};
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
    UCHAR i, *p;

    p = &SC_LD_CONTROL;
    for (i = 0; i < sizeof(LDInitTable); i++) {
        *p = LDInitTable[i];
        p++;
    }
    SC_ADC_LDO_TRIM &= ~BIT7; //sel current mode //770 
    
    //for Abrupt change cotrol 
    LDAPI_AbruptContorl(RAISIMG_ABRUPT_CHANGE_DISABLE,FALIMG_ABRUPT_CHANGE_DISABLE,RAISIMG_ABRUPT_CHANGE_STEP,FALIMG_ABRUPT_CHANGE_STEP);

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
    SC_LD_DIM_DEFINE_CTRL = ((dim23&0x0f)<<4)|(dim01&0x0f);
    dim45 = dim45;
    dim67 = dim67;
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


    SC_LD_PORT_INDEX = 0x01;
    SC_LD_INDEX_PORT_ADDRESS_LO = 0x00;
    SC_LD_INDEX_PORT_ADDRESS_HI = 0x00;
    for (i = 0; i < LD_DATA2LUM_TABLE_LEN; i++) {
        SC_LD_LIGHT_PROFILE_TABLE = table->ucData2LumTable[i];
    }
    ResetWDTimer();
    
    SC_LD_PORT_INDEX = 0x02;
    SC_LD_INDEX_PORT_ADDRESS_LO = 0x00;
    SC_LD_INDEX_PORT_ADDRESS_HI = 0x00;
    for (i = 0; i < LD_LV2GAIN_TABLE_LEN; i++) {
        SC_LD_LIGHT_PROFILE_TABLE = table->ucLv2GainTable[i];
    }
    ResetWDTimer();

    SC_LD_PORT_INDEX = 0x03;
    SC_LD_INDEX_PORT_ADDRESS_LO = 0x00;
    SC_LD_INDEX_PORT_ADDRESS_HI = 0x00;
    for (i = 0; i < LD_NONLINEAR_GAIN_TABLE_LEN; i++) {
        SC_LD_LIGHT_PROFILE_TABLE = table->ucNonlinearGainTable[i];
    }
    ResetWDTimer();

    SC_LD_PORT_INDEX = 0x00;
    SC_LD_INDEX_PORT_ADDRESS_LO = 0x00;
    SC_LD_INDEX_PORT_ADDRESS_HI = 0x00;
    for (i = 0; i < LD_PROFILE_LEN/2; i++) {
        SC_LD_LIGHT_PROFILE_TABLE = table->ucLightProfile[i];
    }
    ResetWDTimer();
    for (i = LD_PROFILE_LEN/2; i < LD_PROFILE_LEN; i++) {
        SC_LD_LIGHT_PROFILE_TABLE = table->ucLightProfile[i];
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
            SC_LD_MODE_CTRL &= ~(BIT1 | BIT2);
            SC_LED_SHORT_CTRL |= BIT1;
            WaitDisVSync();
            SC_OSD_FRAME2_FUNC_CTRL |= BIT2;
            SC_LD_CTRL |= BIT0;
            break;
        case LD_DEMO:
            SC_LD_CTRL |= BIT0;
            SC_LD_MODE_CTRL |= (BIT1 | BIT2);
            WaitDisVSync();
            SC_OSD_FRAME2_FUNC_CTRL |= BIT2;
            SC_LED_SHORT_CTRL |= BIT1;							
            break;
        case LD_OFF:
        default:
            SC_LD_CTRL &= ~BIT0;
            SC_LD_MODE_CTRL &= ~(BIT1 | BIT2);
            WaitDisVSync();
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

/**************************************************************************//**
 * Set LD Duty Weight.
 * @param Gen1/Gen2 weight. The Range is from 0~15
 * @param Gen1 Max/Avg weight. The Range is from 0~15
 * @param Gen2 Local/Avg weight. The Range is from 0~15
 ******************************************************************************/
 #if ENABLE_DYNAMIC_LD == ON 
void LDAPI_SetLDDutyWeight(UCHAR gen1_gen2 , UCHAR gen1 , UCHAR gen2)
{
	SC_LD_DUTY_CONTROL1 = ((SC_LD_DUTY_CONTROL1&0xF0)|(gen1_gen2));
	SC_LD_ADPS_CTRL = (SC_LD_ADPS_CTRL&0xF0)|gen1;
	SC_LD_DUTY_CONTROL3 = (SC_LD_DUTY_CONTROL3&0x0F)|(gen2<<4);
}
#endif

/**************************************************************************//**
 * Set LD Abrupt raising/falling control seperately.
 * @param BOOL abrupt_off_r, Abrupt change duty rising disable
 * @param BOOL abrupt_off_f, Abrupt change duty falling disable
 * @param BOOL abrupt_ignore_r, Abrupt change duty rising change to target immediate mode (Rising turbo mode) disable
 * @param BOOL abrupt_ignore_f, Abrupt change duty falling change to target immediate mode (Falling turbo mode) disable
 ******************************************************************************/
void LDAPI_AbruptContorl(UCHAR abrupt_off_r, UCHAR abrupt_off_f,UCHAR abrupt_ignore_r,UCHAR abrupt_ignore_f)
{
    SC_LD_ABRUPT_CHANGE_CRTL= (SC_LD_ABRUPT_CHANGE_CRTL & 0xF0)|((abrupt_off_r<<3)|(abrupt_off_f<<2)|(abrupt_ignore_r<<1)|(abrupt_ignore_f));
}


#endif //ENABLE_LD == ON
