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
#if ENABLE_EDP == OFF
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
#if IS_NT68870_SERIES
    SC_COMBO_TX_1E00[0x20] = 0x88;//Enable internal 12K resistor
    SC_COMBO_TX_1E00[0x00] = 0x80;//Bias power on
#if PANEL_FOUR_PORT_LVDS == ON
    SC_COMBO_TX_1E00[0x33] = 0xDE;//Power on LDO (TX and PLL)
#else
#if LVDS_AB_CD_SWAP == 0
    SC_COMBO_TX_1E00[0x33] = 0xD6;//Power on LDO (TX and PLL)
#else
    SC_COMBO_TX_1E00[0x33] = 0xDA;//Power on LDO (TX and PLL)
#endif
#endif
    SC_COMBO_TX_1E00[0x00] = 0x01;//Set APLL clock source to DP_CLK_CD
    SC_COMBO_TX_1E00[0x34] = 0x52;//0xD2;//0x92;//0x52;//Set loop filter bandwidth and VCO CTP control
    SC_COMBO_TX_1E00[0x46] = 0x01;//Enable PLL
    ResetWDTimer();//Wait for 1us
    SC_COMBO_TX_1E00[0x46] = 0x03;//Reset PLL
    SC_COMBO_TX_1E00[0x3D] = 0x8F;//Set APLL post-divider
    SC_COMBO_TX_1E00[0x55] = 0x0F;
#if PANEL_FOUR_PORT_LVDS == ON
    SC_COMBO_TX_1E00[0x35] = 0x33;//Enable LVDS P2S
#else
#if LVDS_AB_CD_SWAP == 0
    SC_COMBO_TX_1E00[0x35] = 0x32;//0x11;//Enable LVDS P2S
#else
    SC_COMBO_TX_1E00[0x35] = 0x31;//0x11;//Enable LVDS P2S
#endif
#endif
    SC_COMBO_TX_1E00[0x64] = 0x08;//Select TXMODE to LVDS
    SC_COMBO_TX_1E00[0x47] = 0x00;//Disable output pull-low (port A) 
    SC_COMBO_TX_1E00[0x48] = 0x00;//Disable output pull-low (port B)
    SC_COMBO_TX_1E00[0x49] = 0x00;//Disable output pull-low (port C)
    SC_COMBO_TX_1E00[0x4A] = 0x00;//Disable output pull-low (port D)
#if PANEL_FOUR_PORT_LVDS == ON
    SC_COMBO_TX_1E00[0x01] = 0x3F;//Enable buffer power (port A) 
    SC_COMBO_TX_1E00[0x02] = 0x3F;//Enable buffer power (port B) 
    SC_COMBO_TX_1E00[0x03] = 0x3F;//Enable buffer power (port C)
    SC_COMBO_TX_1E00[0x04] = 0x3F;//Enable buffer power (port D)
#else
#if LVDS_AB_CD_SWAP == 0
    SC_COMBO_TX_1E00[0x01] = 0x3F;//Enable buffer power (port A) 
    SC_COMBO_TX_1E00[0x02] = 0x3F;//Enable buffer power (port B) 
    SC_COMBO_TX_1E00[0x03] = 0x00;//Enable buffer power (port C)
    SC_COMBO_TX_1E00[0x04] = 0x00;//Enable buffer power (port D)
#else
    SC_COMBO_TX_1E00[0x01] = 0x00;//Enable buffer power (port A) 
    SC_COMBO_TX_1E00[0x02] = 0x00;//Enable buffer power (port B) 
    SC_COMBO_TX_1E00[0x03] = 0x3F;//Enable buffer power (port C)
    SC_COMBO_TX_1E00[0x04] = 0x3F;//Enable buffer power (port D)
#endif
#endif
    SC_COMBO_TX_1E00[0x22] = 0x3F;//Enable TX output (port A) 
    SC_COMBO_TX_1E00[0x23] = 0x3F;//Enable TX output (port B)
    SC_COMBO_TX_1E00[0x24] = 0x3F;//Enable TX output (port C)
    SC_COMBO_TX_1E00[0x25] = 0x3F;//Enable TX output (port D)
#else
    SC_LVDS_1D00[0x00] = 0x00;//WRITE     B0    1D00        01
    SC_LVDS_1D00[0x0F] = 0x1D;//WRITE     B0    1D0F        1D
    SC_LVDS_1D00[0x12] = 0x03;//WRITE     B0    1D12        03
    SC_LVDS_1D00[0x12] = 0x07;//WRITE     B0    1D12        07
    SC_LVDS_1D00[0x0F] = 0x3D;//WRITE     B0    1D0F        3D
    SC_LVDS_1D00[0x15] = 0x01;//WRITE     B0    1D15        01
    SC_LVDS_1D00[0x13] = 0x00;//WRITE     B0    1D13        00
    SC_LVDS_1D00[0x14] = 0x00;//WRITE     B0    1D14        00
    SC_LVDS_1D00[0x01] = 0x1F;//WRITE     B0    1D01        1F
    SC_LVDS_1D00[0x02] = 0x1F;//WRITE     B0    1D02        1F
    SC_LVDS_1D00[0x09] = 0x1F;//WRITE     B0    1D09        1F
    SC_LVDS_1D00[0x0A] = 0x1F;//WRITE     B0    1D0A       1F
#endif
    SetLvdsChPolSwap();
}

/**************************************************************************//**
 * Turn off LVDS output.
 ******************************************************************************/
void LvdsOff(void)
{
#if IS_NT68870_SERIES
    SC_COMBO_TX_1E00[0x00] = 0x01;
#else
    SC_LVDS_1D00[0x00] = 0x00;
#endif
}

/**************************************************************************//**
 * Turn on LVDS output.
 ******************************************************************************/
void LvdsOn(void)
{
#if IS_NT68870_SERIES
    SC_COMBO_TX_1E00[0x00] = 0x81;
#else
    SC_LVDS_1D00[0x00] = 0x01;
#endif    
    SetLvdsSwing(440);//440mVpp
}

/**************************************************************************//**
 * Set LVDS swing value.
 * @param swing LVDS swing.
 ******************************************************************************/
void SetLvdsSwing(USHRT swing)
{
    UCHAR level;
    level = (UCHAR)(((swing / 2) - 40) / 20);
#if IS_NT68870_SERIES
    SC_COMBO_TX_1E00[0x59] = level;//ucLVDS_Swing_Table[swing];
    SC_COMBO_TX_1E00[0x5A] = level;//ucLVDS_Swing_Table[swing];
#if PANEL_FOUR_PORT_LVDS == ON
    SC_COMBO_TX_1E00[0x5B] = level;//ucLVDS_Swing_Table[swing];
    SC_COMBO_TX_1E00[0x5C] = level;//ucLVDS_Swing_Table[swing];
#endif
#else
    SC_LVDS_1D00[0x17] = level;
    SC_LVDS_1D00[0x18] = level;
#endif
    
    
#ifdef NT68890_DEMO
    SC_COMBO_TX_1E00[0x5B] = 0x18;//ucLVDS_Swing_Table[swing];
#endif
}

/**************************************************************************//**
 * Set the stage of LVDS clock delay.
 * @param delay Clock delay.
 ******************************************************************************/
 
#if !lrd_dis
void SetLvdsClkDelay(LVDSDelay delay)
{
    if (delay > LVDS_DELAY_7_STAGE)
        delay = LVDS_DELAY_OFF;

#if IS_NT68870_SERIES
    SC_COMBO_TX_1E00[0x0B] = ((SC_COMBO_TX_1E00[0x0B] & 0xF0) | delay);
    SC_COMBO_TX_1E00[0x0D] = ((SC_COMBO_TX_1E00[0x0D] & 0xF0) | delay);
    SC_COMBO_TX_1E00[0x0F] = ((SC_COMBO_TX_1E00[0x0F] & 0xF0) | delay);
    SC_COMBO_TX_1E00[0x11] = ((SC_COMBO_TX_1E00[0x11] & 0xF0) | delay);
#if PANEL_FOUR_PORT_LVDS == ON
    SC_COMBO_TX_1E00[0x0B] = ((SC_COMBO_TX_1E00[0x0B] & 0x0F) | (delay<<4));
    SC_COMBO_TX_1E00[0x0D] = ((SC_COMBO_TX_1E00[0x0D] & 0x0F) | (delay<<4));
    SC_COMBO_TX_1E00[0x0F] = ((SC_COMBO_TX_1E00[0x0F] & 0x0F) | (delay<<4));
    SC_COMBO_TX_1E00[0x11] = ((SC_COMBO_TX_1E00[0x11] & 0x0F) | (delay<<4));
#endif
#else
    SC_LVDS_CLOCK_DELAY &= 0x88; // 0x1fc
    SC_LVDS_CLOCK_DELAY |= (delay | (delay << 4));
#endif
}
/**************************************************************************//**
 * Set the stage of LVDS data delay.
 * @param delay Data delay.
 ******************************************************************************/
void SetLvdsDataDelay(LVDSDelay delay)
{
    if (delay > LVDS_DELAY_7_STAGE)
        delay = LVDS_DELAY_OFF;
#if IS_NT68870_SERIES
    SC_COMBO_TX_1E00[0x13] = ((SC_COMBO_TX_1E00[0x13] & 0xF0) | delay);
    SC_COMBO_TX_1E00[0x15] = ((SC_COMBO_TX_1E00[0x15] & 0xF0) | delay);
    SC_COMBO_TX_1E00[0x17] = ((SC_COMBO_TX_1E00[0x17] & 0xF0) | delay);
    SC_COMBO_TX_1E00[0x19] = ((SC_COMBO_TX_1E00[0x19] & 0xF0) | delay);
#if PANEL_FOUR_PORT_LVDS == ON
    SC_COMBO_TX_1E00[0x13] = ((SC_COMBO_TX_1E00[0x13] & 0x0F) | (delay<<4));
    SC_COMBO_TX_1E00[0x15] = ((SC_COMBO_TX_1E00[0x15] & 0x0F) | (delay<<4));
    SC_COMBO_TX_1E00[0x17] = ((SC_COMBO_TX_1E00[0x17] & 0x0F) | (delay<<4));
    SC_COMBO_TX_1E00[0x19] = ((SC_COMBO_TX_1E00[0x19] & 0x0F) | (delay<<4));
#endif
#else
    SC_LVDS_DATA_DELAY &= 0x88;// 0x1fb
    SC_LVDS_DATA_DELAY |= (delay | (delay << 4));
    SC_LVDS_PAD_POWER &= 0xF8;// 0x1fe
    SC_LVDS_PAD_POWER |= delay;
#endif
}
#endif

#if 0
/**************************************************************************//**
 * Set LVDS P2S-related registers.
 ******************************************************************************/
void SetLvdsP2SByDCLK(void)
{
}
#endif
/**************************************************************************//**
 * Set LVDS LVDS Channel Polarity Swap (Positive/Negative)
 ******************************************************************************/
void SetLvdsChPolSwap(void)
{
#if ENABLE_LVDS_POL_SWAP
#if IS_NT68870_SERIES
    SC_COMBO_TX_1E00[0x36] |= 0x33;
#else
    SC_LVDS_1D00[0x0F] |= 0xC0;
#endif
#endif
}
#endif
