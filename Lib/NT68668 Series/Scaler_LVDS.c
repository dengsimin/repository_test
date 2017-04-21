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
#if IS_NT68650_SERIES || IS_NT68660_SERIES
    SC_LVDS_PLL_LDO_CTRL = 0x44;
#endif
    SC_LVDS_MISC_CTRL1 = 0x55;
    SC_LVDS_MISC_CTRL3 = SCREG_1F7_PU;
    SC_LVDS_MISC_CTRL4 = SCREG_1F8;
    SC_LVDS_MISC_CTRL5 = 0x00;
    SC_LVDS_MISC_CTRL6 = SCREG_1FA;
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
#if IS_NT68650_SERIES || IS_NT68660_SERIES
    SC_LVDS_MISC_CTRL2 &= 0xF8;
#endif
    SC_LVDS_MISC_CTRL3 = SCREG_1F7_PD;  //LVDS output port: power down
    SC_POWER_CTRL1 &= ~BIT6;        //LVDS main power off
}

/**************************************************************************//**
 * Turn on LVDS output.
 ******************************************************************************/
void LvdsOn(void)
{
    SC_POWER_CTRL1 |= BIT6;     //LVDS main power on
    SC_LVDS_MISC_CTRL3 = SCREG_1F7_PU;  //LVDS output port: power on
#if IS_NT68650_SERIES || IS_NT68660_SERIES
    SC_LVDS_MISC_CTRL2 |= 0x07;
#endif
    SC_LVDS_MISC_CTRL1 = 0x45;  //LVDS output port: Tri-state output
    SetLvdsSwing(UserPanelData.ucLVDS_Swing);
}

/**************************************************************************//**
 * Set LVDS swing value.
 * @param swing LVDS swing.
 ******************************************************************************/
void SetLvdsSwing(LVDSSwing swing)
{
#if IS_NT68669_SERIES
    code UCHAR ucLVDS_Swing_Table[NUM_LVDS_SWING][3] = {
      // 0x1F6[5:3], 0x1F7[2:0], 0x1B8[5:3]
        {0, 0, 0}, //LVDS_SWING_150
        {0, 1, 1}, //LVDS_SWING_200
        {0, 2, 2}, //LVDS_SWING_250
        {7, 1, 1}, //LVDS_SWING_300
        {6, 2, 2}, //LVDS_SWING_350
        {7, 2, 2}, //LVDS_SWING_400
        {5, 3, 3}, //LVDS_SWING_450
        {6, 3, 3}, //LVDS_SWING_500
        {7, 3, 3}, //LVDS_SWING_550
        {0, 4, 4}, //LVDS_SWING_600
        {4, 4, 4}, //LVDS_SWING_650
        {5, 4, 4}, //LVDS_SWING_700
        {0, 6, 6}, //LVDS_SWING_750
        {5, 5, 5}, //LVDS_SWING_800
        {0, 7, 7}, //LVDS_SWING_850
        {7, 4, 4}, //LVDS_SWING_900
        {4, 7, 7}  //LVDS_SWING_950
    };

    SC_LVDS_MISC_CTRL2 &= 0xC7;
    SC_LVDS_MISC_CTRL3 &= 0xF8;
    SC_LVDS_CTRL &= 0xC7;

    SC_LVDS_MISC_CTRL2 |= (ucLVDS_Swing_Table[swing][0] << 3);
    SC_LVDS_MISC_CTRL3 |= ucLVDS_Swing_Table[swing][1];
    SC_LVDS_CTRL |= (ucLVDS_Swing_Table[swing][2] << 3);
#elif IS_NT68650_SERIES || IS_NT68660_SERIES
    code UCHAR ucLVDS_Swing_Table[NUM_LVDS_SWING][3] = {
      // 0x1F6[5:3], 0x1F7[2:0], 0x1B8[5:3]
        {0, 0, 0}, //LVDS_SWING_150
        {6, 0, 0}, //LVDS_SWING_200
        {7, 0, 0}, //LVDS_SWING_250
        {6, 1, 1}, //LVDS_SWING_300
        {5, 2, 2}, //LVDS_SWING_350
        {6, 2, 2}, //LVDS_SWING_400
        {7, 2, 2}, //LVDS_SWING_450
        {5, 3, 3}, //LVDS_SWING_500
        {6, 3, 3}, //LVDS_SWING_550
        {7, 3, 3}, //LVDS_SWING_600
        {0, 4, 4}, //LVDS_SWING_650
        {4, 4, 4}, //LVDS_SWING_700
        {0, 5, 5}, //LVDS_SWING_750
        {5, 4, 4}, //LVDS_SWING_800
        {4, 6, 6}, //LVDS_SWING_850
        {6, 4, 4}, //LVDS_SWING_900
        {0, 7, 7}  //LVDS_SWING_950
    };

    SC_LVDS_MISC_CTRL2 &= 0xC7;
    SC_LVDS_MISC_CTRL3 &= 0xF8;
    SC_LVDS_CTRL &= 0xC7;

    SC_LVDS_MISC_CTRL2 |= (ucLVDS_Swing_Table[swing][0] << 3);
    SC_LVDS_MISC_CTRL3 |= ucLVDS_Swing_Table[swing][1];
    SC_LVDS_CTRL |= (ucLVDS_Swing_Table[swing][2] << 3);
#elif IS_NT68668_SERIES
    code UCHAR ucLVDS_Swing_Table[NUM_LVDS_SWING][2] = {
      // 0x1F6[5:3], 0x1B8[5:3]
        {0, 0}, //LVDS_SWING_150
        {0, 1}, //LVDS_SWING_200
        {4, 1}, //LVDS_SWING_250
        {0, 2}, //LVDS_SWING_300
        {5, 2}, //LVDS_SWING_350
        {6, 2}, //LVDS_SWING_400
        {7, 2}, //LVDS_SWING_450
        {4, 3}, //LVDS_SWING_500
        {6, 3}, //LVDS_SWING_550
        {7, 3}, //LVDS_SWING_600
        {4, 4}, //LVDS_SWING_650
        {5, 4}, //LVDS_SWING_700
        {6, 4}, //LVDS_SWING_750
        {7, 4}, //LVDS_SWING_800
        {4, 5}, //LVDS_SWING_850
        {5, 7}, //LVDS_SWING_900
        {7, 7}  //LVDS_SWING_950
    };

    SC_LVDS_MISC_CTRL2 &= 0xC7;
    SC_LVDS_CTRL &= 0xC7;

    SC_LVDS_MISC_CTRL2 |= (ucLVDS_Swing_Table[swing][0] << 3);
    SC_LVDS_CTRL |= (ucLVDS_Swing_Table[swing][1] << 3);
#else
    code UCHAR ucLVDS_Swing_Table1[NUM_LVDS_SWING][4] = {
      // 0x1F6[5:3], 0x1F7[4], 0x1F7[2:0], 0x1B8[5:3]
        {4, 0, 0, 0}, //LVDS_SWING_150
        {0, 0, 1, 1}, //LVDS_SWING_200
        {6, 0, 0, 1}, //LVDS_SWING_250
        {4, 0, 2, 2}, //LVDS_SWING_300
        {6, 0, 1, 2}, //LVDS_SWING_350
        {0, 0, 3, 3}, //LVDS_SWING_400
        {5, 0, 2, 3}, //LVDS_SWING_450
        {6, 1, 2, 3}, //LVDS_SWING_500
        {0, 0, 3, 4}, //LVDS_SWING_550
        {0, 0, 5, 5}, //LVDS_SWING_600
        {0, 0, 6, 6}, //LVDS_SWING_650
        {0, 0, 7, 7}, //LVDS_SWING_700
        {6, 1, 2, 6}, //LVDS_SWING_750
        {5, 0, 4, 7}, //LVDS_SWING_800
        {6, 1, 4, 7}, //LVDS_SWING_850
        {7, 0, 5, 7}, //LVDS_SWING_900
        {7, 1, 5, 7}  //LVDS_SWING_950
    };
    code UCHAR ucLVDS_Swing_Table2[NUM_LVDS_SWING][4] = {
      // 0x1F6[5:3], 0x1F7[4], 0x1F7[2:0], 0x1B8[5:3]
        {4, 0, 2, 0}, //LVDS_SWING_150
        {0, 0, 3, 1}, //LVDS_SWING_200
        {6, 1, 2, 1}, //LVDS_SWING_250
        {4, 0, 5, 2}, //LVDS_SWING_300
        {6, 0, 7, 2}, //LVDS_SWING_350
        {0, 0, 4, 3}, //LVDS_SWING_400
        {5, 0, 5, 3}, //LVDS_SWING_450
        {6, 1, 6, 3}, //LVDS_SWING_500
        {0, 1, 7, 4}, //LVDS_SWING_550
        {0, 1, 7, 5}, //LVDS_SWING_600
        {0, 1, 4, 6}, //LVDS_SWING_650
        {0, 1, 4, 7}, //LVDS_SWING_700
        {6, 1, 5, 6}, //LVDS_SWING_750
        {5, 1, 6, 7}, //LVDS_SWING_800
        {6, 1, 7, 7}, //LVDS_SWING_850
        {7, 1, 7, 7}, //LVDS_SWING_900
        {7, 1, 7, 7}  //LVDS_SWING_950
    };

    SC_LVDS_MISC_CTRL2 &= 0xC7;
    SC_LVDS_MISC_CTRL3 &= 0xE8;
    SC_LVDS_CTRL &= 0xC7;

    if (UserPanelData.bDualPortLVDS == TRUE) {
        SC_LVDS_MISC_CTRL2 |= (ucLVDS_Swing_Table2[swing][0] << 3);
        SC_LVDS_MISC_CTRL3 |= (ucLVDS_Swing_Table2[swing][1] << 4);
        SC_LVDS_MISC_CTRL3 |= ucLVDS_Swing_Table2[swing][2];
        SC_LVDS_CTRL |= (ucLVDS_Swing_Table2[swing][3] << 3);
    }
    else {
        SC_LVDS_MISC_CTRL2 |= (ucLVDS_Swing_Table1[swing][0] << 3);
        SC_LVDS_MISC_CTRL3 |= (ucLVDS_Swing_Table1[swing][1] << 4);
        SC_LVDS_MISC_CTRL3 |= ucLVDS_Swing_Table1[swing][2];
        SC_LVDS_CTRL |= (ucLVDS_Swing_Table1[swing][3] << 3);
    }
#endif
    
}

/**************************************************************************//**
 * Set the stage of LVDS clock delay.
 * @param delay Clock delay.
 ******************************************************************************/
void SetLvdsClkDelay(LVDSDelay delay)
{
    if (delay > LVDS_DELAY_7_STAGE)
        delay = LVDS_DELAY_OFF;
    SC_LVDS_CLOCK_DELAY &= 0xF8;
    SC_LVDS_CLOCK_DELAY |= delay;
}

/**************************************************************************//**
 * Set the stage of LVDS data delay.
 * @param delay Data delay.
 ******************************************************************************/
void SetLvdsDataDelay(LVDSDelay delay)
{
    if (delay > LVDS_DELAY_7_STAGE)
        delay = LVDS_DELAY_OFF;
    SC_LVDS_CLOCK_DELAY &= 0x8F;
    SC_LVDS_CLOCK_DELAY |= (delay << 4);
    SC_LVDS_DATA_DELAY &= 0x88;
    SC_LVDS_DATA_DELAY |= (delay | (delay << 4));
}

/**************************************************************************//**
 * Set LVDS P2S-related registers.
 ******************************************************************************/
void SetLvdsP2SByDCLK(void)
{
#if IS_NT68650_SERIES || IS_NT68660_SERIES
    if ((UserPanelData.bDualPortLVDS == TRUE) &&
        (GetDisplayDCLK() >= 100000000L)) {
        SC_LVDS_P2S_CTRL = 0x00;
        SC_LVDS_MISC_CTRL4 = 0x17;
    }
    else {
        SC_LVDS_P2S_CTRL = 0x00;
        SC_LVDS_MISC_CTRL4 = 0x03;
    }
#endif
}

/**************************************************************************//**
 * Set LVDS LVDS Channel Polarity Swap (Positive/Negative)
 ******************************************************************************/
void SetLvdsChPolSwap(void)
{
#if ENABLE_LVDS_POL_SWAP == ON
    SC_LVDS_CTRL |= 0x80;
#endif
}

