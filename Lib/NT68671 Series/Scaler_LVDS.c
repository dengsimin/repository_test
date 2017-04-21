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
 * Initialize LVDS-related registers.
 ******************************************************************************/
void LVDSInit(void)
{
    SC_LVDS_MISC_CTRL1 = 0x75;
    SC_LVDS_MISC_CTRL4 = 0x06;
    SC_LVDS_MISC_CTRL5 = 0x00;
    SC_LVDS_MISC_CTRL6 = SCREG_1FA;
    SC_LVDS_PLL_CTRL = SCREG_1FD;

    SC_LVDS_RSDS_SWITCH = 0x04;
    SetLvdsClkDelay(LVDS_DELAY_OFF);
    SetLvdsDataDelay(LVDS_DELAY_OFF);
    SetLvdsSwing(UserPanelData.ucLVDS_Swing);
    SetLvdsChPolSwap();    
}

/**************************************************************************//**
 * Turn off LVDS output.
 ******************************************************************************/
void LvdsOff(void)
{
    SC_LVDS_MISC_CTRL1 = 0x55;  //LVDS output port: pull low
    SC_LVDS_MISC_CTRL3 = 0x00;  //LVDS output port: power down
    SC_POWER_CTRL1 &= ~BIT6;        //LVDS main power off
}

/**************************************************************************//**
 * Turn on LVDS output.
 ******************************************************************************/
void LvdsOn(void)
{
    SC_POWER_CTRL1 |= BIT6;     //LVDS main power on
    SC_LVDS_MISC_CTRL3 = 0xE0;  //LVDS output port: power on
    SC_LVDS_MISC_CTRL1 = 0x45;  //LVDS output port: Tri-state output
    SetLvdsSwing(UserPanelData.ucLVDS_Swing);
}

/**************************************************************************//**
 * Set LVDS swing value.
 * @param swing LVDS swing.
 ******************************************************************************/
void SetLvdsSwing(LVDSSwing swing)
{
    code UCHAR ucLVDS_Swing_Table[NUM_LVDS_SWING][2] = {
// 0x1F6[5:3], 0x1B8[5:3]
        {0, 0}, //LVDS_SWING_220
        {5, 0}, //LVDS_SWING_250
        {4, 1}, //LVDS_SWING_300
        {4, 2}, //LVDS_SWING_350
        {6, 2}, //LVDS_SWING_400
        {7, 2}, //LVDS_SWING_450
        {5, 3}, //LVDS_SWING_500
        {6, 3}, //LVDS_SWING_550
        {7, 3}, //LVDS_SWING_600
        {0, 4}, //LVDS_SWING_650
        {0, 5}, //LVDS_SWING_700
        {0, 6}, //LVDS_SWING_750
        {6, 4}, //LVDS_SWING_800
    };

    SC_LVDS_MISC_CTRL2 &= 0xC7;
    SC_LVDS_CTRL &= 0xC7;

    SC_LVDS_MISC_CTRL2 |= (ucLVDS_Swing_Table[swing][0] << 3);
    SC_LVDS_CTRL |= (ucLVDS_Swing_Table[swing][1] << 3);
}

/**************************************************************************//**
 * Set the stage of LVDS clock delay.
 * @param delay Clock delay.
 ******************************************************************************/
void SetLvdsClkDelay(LVDSDelay delay)
{
    if (delay > LVDS_DELAY_7_STAGE)
        delay = LVDS_DELAY_OFF;
    SC_LVDS_CLOCK_DELAY &= 0x8F;
    SC_LVDS_CLOCK_DELAY |= (delay << 4);
}

/**************************************************************************//**
 * Set the stage of LVDS data delay.
 * @param delay Data delay.
 ******************************************************************************/
void SetLvdsDataDelay(LVDSDelay delay)
{
    if (delay > LVDS_DELAY_7_STAGE)
        delay = LVDS_DELAY_OFF;
    SC_LVDS_CLOCK_DELAY &= 0xF8;
    SC_LVDS_CLOCK_DELAY |= delay;
    SC_LVDS_DATA_DELAY &= 0x88;
    SC_LVDS_DATA_DELAY |= (delay | (delay << 4));
}

/**************************************************************************//**
 * Set LVDS P2S-related registers.
 ******************************************************************************/
void SetLvdsP2SByDCLK(void)
{
}

/**************************************************************************//**
 * Set LVDS LVDS Channel Polarity Swap (Positive/Negative)
 ******************************************************************************/
void SetLvdsChPolSwap(void)
{
#if ENABLE_LVDS_POL_SWAP
    SC_LVDS_CTRL |= 0x80;
#endif
}