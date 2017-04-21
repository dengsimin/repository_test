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
#if defined(ENABLE_FPGA_MODE)
#include "FpgaIIC.h"
#endif
#include "ScalerProfile.h"

#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1) || (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************

//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************
static UCHAR ucSetDPLink = 0;

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
//******************************************************************************
// Prototype: 
//  void SetDPLink()
// Parameters:
//
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
#if !lrd_dis
void SetDPLink(void)
{
 ucSetDPLink = TRUE;
}
#endif
//******************************************************************************
// Prototype: 
//  void GetDPLink()
// Parameters:
//
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
UCHAR GetDPLink(void)
{
 return ucSetDPLink;
}


//******************************************************************************
// Prototype: 
//  void ClrDPLink()
// Parameters:
//
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
void ClrDPLink(void)
{
 ucSetDPLink = FALSE;
}


//******************************************************************************
// Prototype: 
//  void DP_InitDPCD()
// Parameters:
//
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
void DP_InitDPCD(void)// using 1
{
    SC_DP_DEBUG = 0x80;  // enable I2C write DPCD page  // 0x1030
#if  !lrd_change_scaler_code
    SC_DP_DPCD_00000 = 0x11;  // ver 1.1 // 0x1100
#else
#if DP_VerSion == DP_V1_2//DPRX540G == ON
    if (UserData.bDPVersion == TRUE) {
        SC_DP_DPCD_00000 = 0x12;  // ver 1.2
    }
    else {
        SC_DP_DPCD_00000 = 0x11;  // ver 1.1
    }
#else
#if ENABLE_FREESYNC_DEMO == ON// For FreeSync
    SC_DP_DPCD_00000 = 0x12;  // ver 1.2
#else
    SC_DP_DPCD_00000 = 0x11;  // ver 1.1
#endif
#endif
#endif
#if DP_LINKRATE == DP_162G
    SC_DP_DPCD_00001 = 0x06;  // 1.62G  // 0x1101
#elif DP_LINKRATE == DP_270G
     SC_DP_DPCD_00001 = 0x0A;  // 2.70G// 0x1101
#else
#if !lrd_change_scaler_code
     SC_DP_DPCD_00001 = 0x14;  // 5.40G// 0x1101
#else
    if (UserData.bDPVersion == TRUE) {
        SC_DP_DPCD_00001 = 0x14;  // 5.40G
    }
    else {
        SC_DP_DPCD_00001 = 0x0A;  // 2.70G
    }
#endif
#endif
    SC_DP_DPCD_00002 = 0x80|DP_LANECNT;  // bit7=1 Enhanced Framing symbol + lane count
#if !lrd_change_scaler_code
    SC_DP_DPCD_00003 = 0x01;  // DPCD 0x003 MAX_DOWNSPREAD = 0.5%
#else
#if DP_LINKRATE == DP_540G//DPRX540G == ON
    if (UserData.bDPVersion == TRUE) {
        SC_DP_DPCD_00003 = 0x00;  // DPCD 0x003 MAX_DOWNSPREAD = 0.5%
    }
    else {
        SC_DP_DPCD_00003 = 0x01;  // DPCD 0x003 MAX_DOWNSPREAD = 0.5%
    }
#else
    SC_DP_DPCD_00003 = 0x01;  // DPCD 0x003 MAX_DOWNSPREAD = 0.5%
#endif
#endif
    SC_DP_DPCD_00004 = 0x01;  // DPCD 0x004 Number of receiver ports
    SC_DP_DPCD_00006 = 0x01;  // DPCD 0x006 ANSI_8B10B  // 0x1106
    SC_DP_DPCD_00101 = 0x00;  // DPCD 0x101 LANE_COUNT_SET  // 0x111d
    SC_DP_DPCD_00200 = 0x41;  // DPCD 0x200 bit6 enable CP_Ready  // 0x1125
    SC_DP_DPCD_00201 = 0x00;  // DPCD 0x201 DEVICE_SERVICE_IRQ_VECTOR  // 0x1126
    SC_DP_DPCD_0000D = 0x00;  // DPCD 0x00D   // 0x1161

#if ENABLE_FREESYNC_DEMO == ON
    // 20150909 Yung Add for DP AMD free-sync use
    SC_DP_DPCD_00007 = 0x40; // bit6 ignore MSA timing  // 0x1107
#endif
    SC_DP_DEBUG = 0x00;  //disable I2C write DPCD page// 0x1030
    SC_DP_10C0 |= BIT4;
    SC_DP_10C1 &= ~BIT7;
    SC_DP_10C2 |= (BIT1|BIT0);
    SC_DP_10C8 |= BIT2;
}
#if TPV_DP_VERSION_SELECT == ON 

//******************************************************************************
// Prototype: 
//  void SetDPSpeed(bit speed)
// Parameters:
//speed:1=5.4G, 0=2.7G
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
void SetDPSpeed(bit speed)
{
#if DP_VerSion == DP_V1_2//DPRX540G == ON

    SC_DP_DEBUG |= BIT7;  // enable I2C write DPCD page
    if (speed == TRUE) {
        SC_DP_DPCD_00000 = 0x12;  // ver 1.2
    }
    else {
        SC_DP_DPCD_00000 = 0x11;  // ver 1.1
    }
    SC_DP_DEBUG &= ~BIT7;  //disable I2C write DPCD page    
#endif

#if DP_LINKRATE == DP_540G//DPRX540G == ON
    if (speed == TRUE) {
        SC_DP_DPCD_00001 = 0x14;  // 5.40G
    }
    else {
        SC_DP_DPCD_00001 = 0x0A;  // 2.70G
    }

    if (speed == TRUE) {
        SC_DP_DPCD_00003 = 0x00;  // DPCD 0x003 MAX_DOWNSPREAD = 0.5%
    }
    else {
        SC_DP_DPCD_00003 = 0x01;  // DPCD 0x003 MAX_DOWNSPREAD = 0.5%
    }
    SC_DP_DEBUG &= ~BIT7;  //disable I2C write DPCD page

   // NEED DP HPD??     
#else
    speed = 0;
#endif
}
#endif

//******************************************************************************
// Prototype: 
//  void DP_InitDPConfigPage()
// Parameters:
//
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
void DP_InitDPConfigPage(void)// using 1
{
#if defined(ENABLE_FPGA_MODE)
    //Configure page 0x1000
    //DebugPage 0x0F00
    //DPCD Page 0x1100
    UCHAR d;
#endif
    // New register mapping (2012/02/20 David)

    //BIST
//    if ((GetSCID() == SCID_850_C) || (GetSCID() == SCID_790_A)) {
#if IS_NT68790_SERIES || IS_NT68810_SERIES || IS_NT68870_SERIES
    SC_DP_1000 = 0x1F;  // 0x1000
    SC_DP_DEBUG |= BIT4; // Bit4:Gate R0 interrupt// 0x1030
#else
    if (GetSCID() == SCID_850_C) {
        SC_DP_1000 = 0x27;  // Fixed VBID issue  // 0x1000
    }
    else {
        SC_DP_1000 = 0x07;  // Fixed VBID issue   // 0x1000
        SC_DP_FAST_MUTE_CTRL |= BIT6; // 0xb88
    }
#endif

#if defined(ENABLE_FPGA_MODE)
    // enable auto-train 0x40A[4]=1
    d = ReadScaler(0xF00+0x0a);
    WriteScaler(0xF00+0x0a,d | 0x10);
#endif
    // Init..
    SC_DP_ERR_DET_CTRL |= 0x87; // enable error detection 0x33[7]=1 // 0x1033

    // disable bit 6 (2012/02/07)
    SC_DP_ERR_DET_DISABLE |= 0x38; // 0x1037

    // Set HPD width
#if DP_NEW_HPD == ON
    SC_DP_HPD_IRQ_WIDTH = 0x80; // set HDP auto. // 0x103a
#else
    SC_DP_HPD_IRQ_WIDTH = 0x07; // set HDP low duty.// 0x103a
#endif
    // cerr_detect
    SC_DP_CERR_RANGE = 0x50; // cerr_range // 0x1034
    SC_DP_CERR_RST_APHY_RANGE = 0x20;// 0x1231
    SC_DP_CERR_CLR_PHY_RANGE = 0x30;// 0x1232
    SC_DP_CERR_NO_LINK_RANGE = 0x40;// 0x1233
    SC_DP_CERR_NO_LINK_BS_RANGE = 0x50;// 0x1234
    SC_DP_CERR_DET_THRESHOLD = 0x20;// 0x1237
    SC_DP_1001 &= 0xF0;// 0x1001
#if defined(ENABLE_FPGA_MODE)
    SC_DP_VIDEO_CONTROL = 0x17;  // DP DE original mode// 0x1046
#else
//    SC_DP_1001 &= 0xF0;
    SC_DP_MN_CTRL = 0x20;  // MN control new shift mode// 0x103f
    
    // 0x17 DE mode; 0x10 Sync mode
#if ENABLE_EDP == OFF
    SC_DP_VIDEO_CONTROL = 0x17;//0x13;//0x17;  // DP DE original mode// 0x1046
#else
    SC_DP_VIDEO_CONTROL = 0x17;//0x13;//0x17;  // DP DE original mode// 0x1046
#endif
#endif
#if defined(ENABLE_FPGA_MODE)
#if DP_LINKRATE == DP_162G
        // Adjust DP input FIFO start position
        SC_DP_DE_START_POS = 0x40;  // Yung ADD for 2 lane 1.62G// 0x1047
        // DP input clock invert
        //WriteScaler(0x0F0C,0x02);  // Yung ADD for 2 lane 1.62G
        // LS_CLK phase adjust
        WriteScaler(0x0F0C,0x00);
#elif DP_LINKRATE == DP_270G
         // Adjust DP input FIFO start position
         SC_DP_DE_START_POS = 0x80;  //// 0x1047
         // DP input clock invert
         WriteScaler(0x0F0C,0x00);  // 2 lane 2.7G //bit1: LS_clock inv
         // LS_CLK phase adjust
         //WriteScaler(0x0F0B,0x30);  //  FPGA code 20121008
         WriteScaler(0x0F0B,0x00);   // FPGA code 20121109
#else
         // 5.4 Gbps
#endif

#if DP_LANECNT == DP_4LANE
    d = ReadScaler(0x0F0C);
    WriteScaler(0x0F0C, d | 0x80);  // sel 4 lane
    SC_DP_DE_START_POS = 0x80;  //// 0x1047
#endif

    // FPGA code:20120329 (DP)   add
    // 0x1FE[4]: 0->DP use LS_clk ; 1->DP use OSC clk
    d = ReadScaler(0x0100+0xFE);
    d &= 0xEF; // set bit4=0
    WriteScaler(0x0100+0xFE,d);  // use LS_clk
#else
#if DP_LINKRATE == DP_162G
    // Adjust DP input FIFO start position
    SC_DP_DE_START_POS = 0x40;  // Yung ADD for 2 lane 1.62G// 0x1047
#elif DP_LINKRATE == DP_270G
    // Adjust DP input FIFO start position
    SC_DP_DE_START_POS = 0x80;  //    // 0x1047
#else
    // 5.4 Gbps
#endif
#endif //#if defined(ENABLE_FPGA_MODE)
    //Audio
    SC_ACR_CLK_OUT_SEL = 0x08;  //acr clk / 2  // 0xb50
    SC_DP_I2S_CTRL = 0x00;  // audio I2S en// 0x1055
    SC_DP_CLK_CYCLE_VALUE = 0x03;  // for digital audio  // 0x1057
    SC_DP_SPDIF_CTRL = 0x00;  // audio SPDIF en  // 0x1058
    SC_DP_DSD_CTRL = 0x00;  //audio DSD en  // 0x1059
    SC_DP_AUDIO_DAC_CTRL = 0x80;  //audio DAC en// 0x105A
    SC_DP_AUDIO_FIFO_CTRL = 0x80;  // audio FIFO enable// 0x1050
    SC_DP_AUDIO_ERROR_FLAG = 0xff;  // Audio error flag// 0x1054
    SC_DP_CRPLL = 0x15;  //clk path // 0x16d1
#if IS_NT68870_SERIES
    SC_DP_AUDIO_16D6 |= BIT2;
#endif
    //set default M/N value
    SC_DP_PLL_CTRL |= BIT6; //default manual   // 0x1081
    //WriteScaler(0x1000+0xd0, ReadScaler(0x1000+0xd0) | BIT3); //block
    SC_DP_MANUAL_MAUD_LO = 0xAD; // 0x1011
    SC_DP_MANUAL_MAUD_MI = 0x0B; // 0x1010
    SC_DP_MANUAL_MAUD_HI = 0x00; // 0x100f
    SC_DP_MANUAL_NAUD_LO = 0x00; // 0x1014
    SC_DP_MANUAL_NAUD_MI =0x80; // 0x1013
    SC_DP_MANUAL_NAUD_HI = 0x00; // 0x1012

    //NLT:NO LINK TRAINING
//    SC_DP_10B0 |= BIT7;
//    SC_DP_10B7 &= 0xD5; // 10b7[1] [3] [5] = 0
}

//******************************************************************************
// Prototype: 
//  void DP_InitPHY(UCHAR phyindex)
// Parameters:
//
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
void DP_InitPHY(UCHAR phyindex)// using 1
{
   //SC_DP_AUX_CTRL = 0x31; // AUX
   DPPHY_PowerOn(phyindex);
}

//******************************************************************************
// Prototype: 
//  void DPPHY_PowerOn(UCHAR phyindex)
// Parameters:
//
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
void DPPHY_PowerOn(UCHAR phyindex)// using 1
{
    SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG0, 0x2F);  // 0x1b06
    
#if DP_LINKRATE == DP_540G
    SC_SetByteDPppPHY(phyindex, _DPPHY_FCTRL, 0x74);//WriteScaler(0x1C00, 0x44); // bit6:DP mode enable bit2:Leak0back block enable
#else
    SC_SetByteDPppPHY(phyindex, _DPPHY_FCTRL, 0x44);//WriteScaler(0x1C00, 0x44); // bit6:DP mode enable bit2:Leak0back block enable
#endif
#if 0//6502 control (new lib)
    SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG2, 0x13);//WriteScaler(0x1B42, 0x13);
    SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG3, 0x07);//WriteScaler(0x1B49, 0x0F);
    SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG4, 0xFF);//WriteScaler(0x1B4A, 0x01);
    SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG5, 0xFF);//WriteScaler(0x1B4B, 0x00);
#endif
#if DPRX_PN_SWAP == ON
    SC_SetByteDPppPHY(phyindex, _DPRM_LANE_POLARITY, 0x0F);//WriteScaler(0x1AD5, 0x0F);  // PN swap
#else
    SC_SetByteDPppPHY(phyindex, _DPRM_LANE_POLARITY, 0x00);//WriteScaler(0x1AD5, 0x00);  // PN swap
#endif
    SC_SetByteDPppPHY(phyindex, _DPPHY_ICTRL, 0x00);//WriteScaler(0x1C01, 0x00);  // 
    SC_SetByteDPppPHY(phyindex, _DPPHY_EQR_IMP_ENABLE, 0xFF);//WriteScaler(0x1C02, 0xFF);  // Lane0~3 EQR & Impedance enableif 
    SC_SetByteDPppPHY(phyindex, _DPPHY_EQR_RES_CTRL3, 0xF0);
#if IS_NT68810_SERIES
    SC_SetByteDPppPHY(phyindex, _DPPHY_IMPEDANCE_L0_L2_L3, 0x18);//WriteScaler(0x1C03, 0x18);  // Lane0&2&3 Impedance control
    SC_SetByteDPppPHY(phyindex, _DPPHY_IMPEDANCE_L1, 0x18);//WriteScaler(0x1C04, 0x18);  // Lane1  Impedance control
#else //NT68870
    SC_SetByteDPppPHY(phyindex, _DPPHY_IMPEDANCE_L0_L2_L3, 0x1A);//WriteScaler(0x1C03, 0x18);  // Lane0&2&3 Impedance control
    SC_SetByteDPppPHY(phyindex, _DPPHY_IMPEDANCE_L1, 0x1A);//WriteScaler(0x1C04, 0x18);  // Lane1  Impedance control
#endif
    SC_SetByteDPppPHY(phyindex, _DPPHY_EQR_POS_IOFFSET_L0, 0x00);//WriteScaler(0x1C05, 0x00);  // L0 EQR positive current offset control 
    SC_SetByteDPppPHY(phyindex, _DPPHY_EQR_POS_IOFFSET_L1, 0x00);//WriteScaler(0x1C06, 0x00);  // L1 EQR positive current offset control
    SC_SetByteDPppPHY(phyindex, _DPPHY_EQR_POS_IOFFSET_L2, 0x00);//WriteScaler(0x1C07, 0x00);  // L2 EQR positive current offset control
    SC_SetByteDPppPHY(phyindex, _DPPHY_EQR_POS_IOFFSET_L3, 0x00);//WriteScaler(0x1C08, 0x00);  // L3 EQR positive current offset control
    SC_SetByteDPppPHY(phyindex, _DPPHY_EQR_NEG_IOFFSET_L0, 0x00);//WriteScaler(0x1C09, 0x00);  // L0 EQR negative current offset control
    SC_SetByteDPppPHY(phyindex, _DPPHY_EQR_NEG_IOFFSET_L1, 0x00);//WriteScaler(0x1C0A, 0x00);  // L1 EQR negative current offset control
    SC_SetByteDPppPHY(phyindex, _DPPHY_EQR_NEG_IOFFSET_L2, 0x00);//WriteScaler(0x1C0B, 0x00);  // L2 EQR negative current offset control
    SC_SetByteDPppPHY(phyindex, _DPPHY_EQR_NEG_IOFFSET_L3, 0x00);//WriteScaler(0x1C0C, 0x00);  // L3 EQR negative current offset control
    SC_SetByteDPppPHY(phyindex, _DPPHY_BIAS_POWER, 0xA0);//WriteScaler(0x1C1C, 0xA0);  // bit7:Bias Power up  bit5:Bias ref sel bandgap
#if IS_NT68810_SERIES
    SC_SetByteDPppPHY(phyindex, _DPPHY_BIAS_LDO, 0x02);//WriteScaler(0x1C1D, 0x02);  // VCO LDO voltage control
#else //NT68870
    SC_SetByteDPppPHY(phyindex, _DPPHY_BIAS_LDO, 0x04);//WriteScaler(0x1C1D, 0x02);  // VCO LDO voltage control
#endif
    SC_SetByteDPppPHY(phyindex, _DPPHY_BIAS_R12K, 0x0F);//WriteScaler(0x1C1E, 0x09);//0x06);  // R12K resistance tuning
    SC_SetByteDPppPHY(phyindex, _DPPHY_IBIAS_SEL, 0x0F);//WriteScaler(0x1C1F, 0x0F);  // Current bias fine tune
#if IS_NT68810_SERIES
    SC_SetByteDPppPHY(phyindex, _DPPHY_LDO_CTRL, 0x62);  // 0x1228
#else //NT68870
    SC_SetByteDPppPHY(phyindex, _DPPHY_LDO_CTRL, 0x64);
#endif
    SC_SetByteDPppPHY(phyindex, 0x092, 0x07); // 0x1a92

    SC_SetByteDPppPHY(phyindex, 0x1FC, 0x64);  // 0x1bfc
    SC_SetByteDPppPHY(phyindex, _DPRP_REG_1FD, 0x64);  // 0x1bfd

    if (phyindex == _DPPP_PHY0) {
        SC_SetByteDPppPHY(_DPPP_PHY0, 0x240, 0x31);  // 0x1c40
        SC_SetByteDPppPHY(_DPPP_PHY0, 0x241, 0x46);// 0x1c41
        SC_SetByteDPppPHY(_DPPP_PHY0, 0x242, 0x44);// 0x1c42
    }
    else {
        SC_SetByteDPppPHY(_DPPP_PHY0, 0x250, 0x31);
        SC_SetByteDPppPHY(_DPPP_PHY0, 0x251, 0x46);
        SC_SetByteDPppPHY(_DPPP_PHY0, 0x252, 0x44);
    }
/*
#if IS_NT68810_SERIES
    SC_SetByteDPppPHY(phyindex, 0x244, 0x05);
#else
    SC_SetByteDPppPHY(phyindex, 0x244, 0x07);//0x05);
#endif
*/
#if (INPUT_INTERFACE&INPUT_DP)
    DPAUX_Select(_AUX_CH0);
#endif
#if (INPUT_INTERFACE&INPUT_DP1)
    DPAUX_Select(_AUX_CH1);
#endif
#if (INPUT_INTERFACE&INPUT_DP2)
    DPAUX_Select(_AUX_CH2);
#endif
#if (INPUT_INTERFACE&INPUT_DP3)
    DPAUX_Select(_AUX_CH3);
#endif

    SC_SetByteDPppPHY(phyindex, 0x1FE, 0x00);  // 0x1bfe
} 

void DPAUX_Select(UCHAR ch)
{
#if IS_NT68810_SERIES
    if (ch == _AUX_CH1) {  
        SC_SetByteDPppPHY(_DPPP_PHY0, 0x244, 0x07); // 0x1c44
    }
    else {
        SC_SetByteDPppPHY(_DPPP_PHY0, 0x244, 0x05);
    }
#else
    switch (ch) {
        case _AUX_CH0:
            SC_SetByteDPppPHY(_DPPP_PHY0, 0x244, 0x07);
            AUX_I2C_MANUAL &= ~BIT7;// 0x1024
            break;
        case _AUX_CH1:
            SC_SetByteDPppPHY(_DPPP_PHY0, 0x244, 0x05);
            AUX_I2C_MANUAL &= ~BIT7;// 0x1024
            break;
        case _AUX_CH2:
            SC_SetByteDPppPHY(_DPPP_PHY0, 0x254, 0x07);
            AUX_I2C_MANUAL |= BIT7;// 0x1024
            break;
        case _AUX_CH3:
            SC_SetByteDPppPHY(_DPPP_PHY0, 0x254, 0x05);
            AUX_I2C_MANUAL |= BIT7;// 0x1024
            break;
    }
#endif
}

//******************************************************************************
// Prototype: 
//  void DPPHY_PowerOff()
// Parameters:
//
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
void DPPHY_PowerOff(void)// using 1
{
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1)
    SC_SetByteDPppPHY(_DPPP_PHY0, _DPPHY_FCTRL, 0x04);//WriteScaler(0x1C00, 0x04);
    SC_SetByteDPppPHY(_DPPP_PHY0, _DPPHY_EQR_IMP_ENABLE, 0x00);//WriteScaler(0x1C02, 0x00);
    SC_SetByteDPppPHY(_DPPP_PHY0, _DPPHY_EQR_RES_CTRL3, 0x00);
    SC_SetByteDPppPHY(_DPPP_PHY0, _DPPHY_EQR_POS_IOFFSET_L0, 0x00);//WriteScaler(0x1C05, 0x00);
    SC_SetByteDPppPHY(_DPPP_PHY0, _DPPHY_BIAS_POWER, 0x00);//WriteScaler(0x1C1C, 0x00);
    SC_SetByteDPppPHY(_DPPP_PHY0, _DPRM_LANE_HI_CFG, 0x0F);//1AD2
    SC_SetByteDPppPHY(_DPPP_PHY0, _DPRP_STATUS, 0x10);//CDR off
#endif
#if IS_NT68870_SERIES
#if (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
    SC_SetByteDPppPHY(_DPPP_PHY1, _DPPHY_FCTRL, 0x04);//WriteScaler(0x1C00, 0x04);
    SC_SetByteDPppPHY(_DPPP_PHY1, _DPPHY_EQR_IMP_ENABLE, 0x00);//WriteScaler(0x1C02, 0x00);
    SC_SetByteDPppPHY(_DPPP_PHY0, _DPPHY_EQR_RES_CTRL3, 0x00);  // feng-160902  
    SC_SetByteDPppPHY(_DPPP_PHY1, _DPPHY_EQR_POS_IOFFSET_L0, 0x00);//WriteScaler(0x1C05, 0x00);
    SC_SetByteDPppPHY(_DPPP_PHY1, _DPPHY_BIAS_POWER, 0x00);//WriteScaler(0x1C1C, 0x00);
    SC_SetByteDPppPHY(_DPPP_PHY1, _DPRM_LANE_HI_CFG, 0x0F);//1AD2
    SC_SetByteDPppPHY(_DPPP_PHY1, _DPRP_STATUS, 0x10);//CDR off
#endif
#endif
}

//******************************************************************************
// Prototype: 
//  void DP_ConfigAUX2IICSpeed()
// Parameters:
//
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
void DP_ConfigAUX2IICSpeed(void)// using 1
{
    // Init AUX to I2C clock speed.
#if AUX2IICSPEED > 500  //20130715_1006_SYS#3
    SC_DP_SCL_HI_HALF_WIDTH = 0x10;// 0x1026
    SC_DP_SCL_HI_WIDTH = 0x20;// 0x1027
    SC_DP_SDA_SETUP = 0x12;// 0x1028
    SC_DP_SDA_HOLD = 0x1F;// 0x1029
#elif AUX2IICSPEED == 500
    SC_DP_SCL_HI_HALF_WIDTH = 0x1F;
    SC_DP_SCL_HI_WIDTH = 0x2F;
    SC_DP_SDA_SETUP = 0x12;
    SC_DP_SDA_HOLD = 0x1F;
#elif AUX2IICSPEED == 400
    SC_DP_SCL_HI_HALF_WIDTH = 0x20;
    SC_DP_SCL_HI_WIDTH = 0x3C;
    SC_DP_SDA_SETUP = 0x1D;
    SC_DP_SDA_HOLD = 0x1F;
#elif AUX2IICSPEED == 300
    SC_DP_SCL_HI_HALF_WIDTH = 0x2E;
    SC_DP_SCL_HI_WIDTH = 0x50;
    SC_DP_SDA_SETUP = 0x31;
    SC_DP_SDA_HOLD = 0x1F;
#else
    SC_DP_SCL_HI_HALF_WIDTH = 0x58;//0x48;
    SC_DP_SCL_HI_WIDTH = 0xA0;//0x7D);
    SC_DP_SDA_SETUP = 0x81;//0x5E);
    SC_DP_SDA_HOLD = 0x1F;
#endif

    if(SC_CHIP_ID == 0x0B && SC_REVISION_ID == 0x02) {//850, C version
#if AUX2IICSPEED < 300
        SC_DP_AUX_I2C_CTRL = 0x34;  // BIT5:differ en  // 0x102a
#else
        SC_DP_AUX_I2C_CTRL = 0x34|BIT1|BIT0;// 0x102a
#endif
    }
    else {
        SC_DP_AUX_I2C_CTRL = 0x36;  // BIT5:differ en, cut4 BIT0=0// 0x102a
#if IS_NT68790_SERIES || IS_NT68810_SERIES || IS_NT68870_SERIES
        SC_DP_AUX_I2C_CTRL2 |= (BIT5 | BIT4 | BIT0); //// 0x102e
#else
        SC_DP_MASK_AUX_I2C_RW_SEL &= ~BIT0;// 0xb87
        SC_DP_AUX_CTRL2 |= BIT5;// 0xb8a
#endif
    }

    // Init Pre-charge pulse count
    SC_DP_TX_PRE_CHG_NUM = 0x19|BIT6|BIT7;// 0x102b
    SC_DP_RX_PRE_CHG_NUM = 0x0F;// 0x102c
}

//******************************************************************************
// Prototype: 
//  void DP_CLKOn()
// Parameters:
//
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
void DP_CLKOn(void)// using 1
{
    SC_POWER_CTRL3 &= ~(BIT2|BIT1|BIT0); //CLK   0x103
    SC_LVDS_PAD_POWER &= ~BIT7; //int-dp_rck_gated   0x1fe
}

//******************************************************************************
// Prototype: 
//  void DP_CLKOff()
// Parameters:
//
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
void DP_CLKOff(void)// using 1
{
    SC_POWER_CTRL3 |= (BIT2|BIT1|BIT0); //CLK   0x103
    SC_LVDS_PAD_POWER |= BIT7; //int-dp_rck_gated  0x1fe
}

#if ENABLE_USB_TYPE_C == ON
void DPLane_Switch(UCHAR interface)
{
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1)
    if (interface == USB_TYPE_C_INTERFACE) {
        if ((SC_USBC_CC_CFG & 0x0C) == 0x00) { //CC1   // 0x1660
            SC_SetByteDPppPHY(_DPPP_PHY0, _DPRM_CG_CFG3, 0x1B);// Yung add for USB typeC reverse plug Lane need swap
        }
        else { //CC2
            SC_SetByteDPppPHY(_DPPP_PHY0, _DPRM_CG_CFG3, 0xE4);// Yung add for USB typeC Normal plug Lane no swap
        }
    }
#endif
    
#if (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
    if (interface == USB_TYPE_C_INTERFACE) {
        if ((SC_USBC_CC_CFG & 0x0C) == 0x00) { //CC1   // 0x1660
            SC_SetByteDPppPHY(_DPPP_PHY1, _DPRM_CG_CFG3, 0x1B);// Yung add for USB typeC reverse plug Lane need swap
        }
        else { //CC2
            SC_SetByteDPppPHY(_DPPP_PHY1, _DPRM_CG_CFG3, 0xE4);// Yung add for USB typeC Normal plug Lane no swap
        }
    }
#endif
}
#endif

#else
void ForDPCompilerCodePass1(void)
{
  code UCHAR temp[]={0x00};
  UCHAR i;
  i = temp[0];
}
#endif



