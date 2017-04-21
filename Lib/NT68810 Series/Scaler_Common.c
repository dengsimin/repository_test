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
#include "Scaler_DP_6502.h"
#include "Scaler_TMDS_6502.h"

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
extern xdata UCHAR ucZpInterface; /*!< Input interface when system is under low power mode. */

//******************************************************************************
// S T A T I C   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// F U N C T I O N   B O D Y S
//******************************************************************************
#if IS_NT68810_SERIES || IS_NT68870_SERIES  
#if ENABLE_HDCP_TRIM_MODE == ON || ENABLE_EDID_TRIM_MODE == ON
void EFUSE_MAPPING(void);
#endif
#endif

/**************************************************************************//**
 * Initialize scaler registers, including Power/ADC/LVDS/TMDS/SyncProce etc...
 ******************************************************************************/
void ScalerInitialize(void)
{
    if ((SC_POWER_CTRL1&0x0F) != 0x0D) { // HW Reset in int.c        0x101
    #if 0//ENABLE_CUT_POWER_ARCH == ON
        SC_POWER_CTRL1 |= BIT7;//power on 101[7]
        SC_CUT_POWER_CTRL |= BIT0;//power on b62[0]
    #endif
        SC_HW_RST = 0x10;  // 0xf04f
        SC_HW_RST = 0x11;
    }

    SetNormalPowerMode();

#if IS_NT68790_SERIES || IS_NT68658_SERIES || IS_NT68810_SERIES || IS_NT68870_SERIES
    SC_GI_CLK_REF_HI |= (BIT7|BIT6|BIT5);  // 0x118
#endif

    SC_DPLL_FREQ_CTRL = 0x0C;  // 0x0f1
    if ((SC_POWER_CTRL1&0x0F) != 0x0D) { // HW Reset in int.c
      SC_POWER_CTRL1 = 0x20;  // 0x101
      SC_POWER_CTRL1 = 0x00;
    }
    SC_VGA_ADC_BIST = 0;  // 0xb60

    TurnOnScalerMainPower();

#if MD_ENABLE_AO_DETECT == OFF
#if IS_NT68810_SERIES
    SC_ZERO_PWR_CTRL_B64 |= BIT4;
    SC_ZERO_PWR_CTRL_B66 &= ~(BIT1|BIT0);
    SC_ZERO_PWR_CTRL_B66 |= BIT2;
    SC_ZERO_PWR_CTRL_B65 |= (BIT2 | BIT1);
#else
    SC_ZERO_PWR_CTRL_B64 = 0x14;//|= BIT4;
    SC_ZERO_PWR_CTRL_B66 = 0x00;//&= ~(BIT1|BIT0);
//    SC_ZERO_PWR_CTRL_B66 |= BIT2;
    SC_ZERO_PWR_CTRL_B65 = 0x18;//|= (BIT4|BIT3|BIT2 | BIT1);
    SC_ZERO_PWR_CTRL_B66 = 0x80;
    SC_ZERO_PWR_CTRL_B66 = 0x00; 
#endif
    ZPLatchData();
#endif  
#if 0//phy impedance
    SC_ZERO_PWR_CTRL_B66 |= BIT2;
    SC_ZERO_PWR_CTRL_B65 |= (BIT2 | BIT1);
    ZPLatchData();
#endif  

#if IS_NT68810_SERIES || IS_NT68870_SERIES
    ConfigHPD();
#endif
#if IS_NT68810_SERIES
    SC_ZERO_PWR_CTRL_B66 |= BIT2;
    Sleep(1);
    SC_ZERO_PWR_CTRL_B69 |= BIT2;
    SC_ZERO_PWR_CTRL_B69 &= ~BIT2;
#endif

#if IS_NT68870_SERIES    
    SC_ZERO_PWR_CTRL_B67 = 0x00;//|= (BIT5|BIT4);
    SC_ZERO_PWR_CTRL_B67 = 0x30;//|= (BIT5|BIT4);
    Sleep(1);
    SC_ZERO_PWR_CTRL_B69 = 0x20;//|= BIT2;
    SC_ZERO_PWR_CTRL_B69 = 0x24;//|= BIT2;
    SC_ZERO_PWR_CTRL_B69 = 0x20;//&= ~BIT2;
    SC_SetByteDPppPHY(_DPPP_PHY0, _DPPHY_READ_MODE, 0x01);
#endif

    ADCInit();
#if ENABLE_EDP == OFF
    LVDSInit();
#endif
    DisplayInit();
#if 1//IS_NT68810_SERIES
#if (INPUT_INTERFACE&INPUT_DIG0) || (INPUT_INTERFACE&INPUT_DIG1)
    TMDSInit(_DPPP_PHY0);
#endif
#endif
#if IS_NT68870_SERIES
#if (INPUT_INTERFACE&INPUT_DIG2) || (INPUT_INTERFACE&INPUT_DIG3)
    TMDSInit(_DPPP_PHY1);
#endif
#endif

#if 1//IS_NT68810_SERIES
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1)
    DPInit(_DPPP_PHY0);
#if (ENABLE_DP_AUX_MONITOR==ON)
    Init_DP_Strobe();   
#endif
#endif
#endif
#if IS_NT68870_SERIES
#if (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
    DPInit(_DPPP_PHY1);
#if (ENABLE_DP_AUX_MONITOR==ON)
    Init_DP_Strobe();   
#endif
#endif
#endif

//while(1)  ResetWDTimer();

    CAPInit();
    SyncInit();
#if ENABLE_HDMI == ON
    HDMIInit();
#endif
    DithInit();
    NRInit();
    EnableScalerPWM(PWM_ALL);

#if (INPUT_INTERFACE&INPUT_MHL_MASK)
    MHLInit();
#endif

#if ENABLE_USB_TYPE_C == ON
    USBTypeCInit();
#endif

#if ENABLE_MMU == ON
    MMUInitialize();
#endif

#if ENABLE_HW_CEC == ON
    InitialCEC(HDMI_CEC_CHANNEL);
#endif

//new add 20151021
#if IS_NT68810_SERIES || IS_NT68870_SERIES  
#if ENABLE_HDCP_TRIM_MODE == ON || ENABLE_EDID_TRIM_MODE == ON
    EFUSE_MAPPING();
#endif
#endif

#if ENABLE_SCALER_LEDDRV == ON
    InitLEDDriver();
#else
#if ENABLE_SCALER_LEDDRV_IO_MODE   
    InitLEDDriverIOCtrl();
#endif
#endif

#if 0//IS_NT68850_SERIES || IS_NT68790_SERIES || IS_NT68658_SERIES
    SC_APR_LDO_V_CTRL |= BIT0;//NT68850 沒有 LDO, 所以 b53 的 control register 後來都被拿去當 apr2 的 clock gen control 使用
#endif

#if defined(ENABLE_FPGA_MODE)
// Only for special case in FPGA stage
    SC_FPGA1_FPGA2_DELAY = 0x12;
#if IS_NT68850_SERIES || IS_NT68790_SERIES || IS_NT68658_SERIES || IS_NT68810_SERIES || IS_NT68870_SERIES
    SC_FPGA_HDMI_DELAY = 0x01;
#else
    SC_FPGA_HDMI_DELAY = 0x02;
#endif

    SC_PREFRC_CLOCK_DIV |= 0x80;
    SC_DISPLAY_POL_CTRL |= (BIT3|BIT6);
    
    AD9884_Init();
#endif

#if IS_NT68870_SERIES
#if ENABLE_EDP == ON
    InitEDP();
    EDP_ForceTraining();
#else
    EDP_PowerOff();
#endif
#endif

#if ENABLE_POSTFRC == ON
    FRCConfigPostFRC(PANEL_FRC_OUTPUT_VSYNC, TRUE);
#endif
}

void EDP_PowerOff(void)
{
    SC_PLL_SYZ_PU &= ~BIT4;  // 0xb4d
}

void PhyLinkSelect(UCHAR interface)
{
    SC_SetBitDPppPHY(_DPPP_PHY1, _DPPHY_LDO_CTRL, BIT7, FALSE); // _DPPHY_DUAL_LINK
    SC_TMDS_PHY_LINK_CTRL_1DE0 &= ~BIT3; // 0x1de0
    switch (interface) {
        case DIGITAL_INPUT0:
            SC_TMDS_PHY_LINK_CTRL_1DE0 &= ~BIT0; // set PHY A; 0 is PHY A,  1 is PHYB // 0x1de0
            SC_TMDS_PHY_LINK_CTRL_1DE1 |= BIT0; // RX0
            SC_SetByteDPppPHY(_DPPP_PHY0, _TMDS_DPHY_MS_CLK_SEL, 0x00);                         
            break;
        case DIGITAL_INPUT1:
            SC_TMDS_PHY_LINK_CTRL_1DE0 &= ~BIT0; // 0x1de0
            SC_TMDS_PHY_LINK_CTRL_1DE1 &= ~BIT0; // RX1
            SC_SetByteDPppPHY(_DPPP_PHY0, _TMDS_DPHY_MS_CLK_SEL, 0x00);                         
            break;
        case DIGITAL_INPUT2:
            SC_TMDS_PHY_LINK_CTRL_1DE0 |= BIT0; // 0x1de0
            SC_TMDS_PHY_LINK_CTRL_1DE1 |= BIT1;
            SC_SetByteDPppPHY(_DPPP_PHY0, _TMDS_DPHY_MS_CLK_SEL, 0x01);                         
            break;
        case DIGITAL_INPUT3:
            SC_TMDS_PHY_LINK_CTRL_1DE0 |= BIT0; // 0x1de0
            SC_TMDS_PHY_LINK_CTRL_1DE1 &= ~BIT1;
            SC_SetByteDPppPHY(_DPPP_PHY0, _TMDS_DPHY_MS_CLK_SEL, 0x01);                         
            break;
        case DISPLAY_PORT_INPUT:
            SC_SetBitDPppPHY(_DPPP_PHY0, _DPPHY_LINK_CTRL, BIT0, FALSE);//SC_DPpp_CFG_TMDS_1A00[_DPPHY_LINK_CTRL] &= ~BIT0;
            SC_TMDS_PHY_LINK_CTRL_1DE1 |= BIT0;
            break;
        case DISPLAY_PORT_INPUT1:
            SC_SetBitDPppPHY(_DPPP_PHY0, _DPPHY_LINK_CTRL, BIT0, FALSE);//SC_DPpp_CFG_TMDS_1A00[_DPPHY_LINK_CTRL] &= ~BIT0;
            SC_TMDS_PHY_LINK_CTRL_1DE1 &= ~BIT0;
            break;
        case DISPLAY_PORT_INPUT2:
            SC_SetBitDPppPHY(_DPPP_PHY0, _DPPHY_LINK_CTRL, BIT0, TRUE);//SC_DPpp_CFG_TMDS_1A00[_DPPHY_LINK_CTRL] |= BIT0;
            SC_TMDS_PHY_LINK_CTRL_1DE1 |= BIT1;
            break;
        case DISPLAY_PORT_INPUT3:
            SC_SetBitDPppPHY(_DPPP_PHY0, _DPPHY_LINK_CTRL, BIT0, TRUE);//SC_DPpp_CFG_TMDS_1A00[_DPPHY_LINK_CTRL] |= BIT0;
            SC_TMDS_PHY_LINK_CTRL_1DE1 &= ~BIT1;
            break;
    }
}

UCHAR GetTMDSPhyLinkSelect(void)
{
    if ((SC_TMDS_PHY_LINK_CTRL_1DE0 & BIT0) == 0) {//Rx0, Rx1 // 0x1de0
        if ((SC_TMDS_PHY_LINK_CTRL_1DE1 & BIT0) == 0) {
            return DIGITAL_INPUT1;
        }
        else {
            return DIGITAL_INPUT0;
        }
    }
    else {//Rx2, Rx3
        if ((SC_TMDS_PHY_LINK_CTRL_1DE1 & BIT1) == 0) {
            return DIGITAL_INPUT3;
        }
        else {
            return DIGITAL_INPUT2;
        }
    }
}

UCHAR GetDPPhyLinkSelect(void)
{
    if ((GetTMDSPHYDATA(_DPPP_PHY0, _DPPHY_LINK_CTRL) & BIT0) == 0) {//Rx0, Rx1
        if ((SC_TMDS_PHY_LINK_CTRL_1DE1 & BIT0) == 0) {
            return DISPLAY_PORT_INPUT1;
        }
        else {
            return DISPLAY_PORT_INPUT;
        }
    }
    else {//Rx2, Rx3
        if ((SC_TMDS_PHY_LINK_CTRL_1DE1 & BIT1) == 0) {
            return DISPLAY_PORT_INPUT3;
        }
        else {
            return DISPLAY_PORT_INPUT2;
        }
    }
}

/**************************************************************************//**
 * Configure the scaler input to the specified interface
 * @param interface Input interface.
 ******************************************************************************/
void SetInputInterface(UCHAR interface)
{
    code UCHAR *interface_tab[] = {
        &SC_ADC_CTRL, // 0x00
//        &SC_ADC_MID_CH_SEL,
        &SC_ADC_IP_CTRL_1D80[_ADC_CLAMP_VMID_SEL],  // 0x1da2
        &SC_SOG_SLICER_EN, // 0x00a
//        &SC_ADC_CLAMP_CTRL,
        &SC_ADC_IP_CTRL_1D80[_ADC_MISC_CTRL_33], // 0x1db3
        &SC_GPORT_CTRL,  // 0x20
        &SC_CLAMP_BEGIN,// 0x021
        &SC_DIGITAL_CTRL, // 0x23
        &SC_INPUT_SELECT, // 0x24
        &SC_ADC_CK_CTRL, // 0x25
        &SC_CAP_SWAP,  // 0x26
        &SC_GI_ALT_CTRL, // 0x38
        &SC_GI_SYNC_CTRL, // 0x196
        &SC_SOG_SLICER_CTRL, // 0x12
        &SC_BP_SYNC_CTRL, // 0x72
        &SC_ADC_TEST_MODE, // 0x1e6
        &SC_NEW_DE_MODE_EN // 0x66b
    };
    
    code UCHAR interface_data[][sizeof(interface_tab)/sizeof(UCHAR *)] = {
      //0x000,0xDA2,0x00A,0xDB3,0x020,0x021,0x023,0x024,       0x025,0x026,0x038,       0x196,0x012,0x072,0x1E6,0x66B
        {0x10, 0x00, 0xF0, 0x5E, 0x81, 0x81, 0x00, 0x80, SCREG_025_A, 0x00, SCREG_038_A, 0x20, 0x00, 0x01, 0x01, 0x00}, //ANALOG_SEP_INPUT0
        {0x10, 0x00, 0xF0, 0x5E, 0x81, 0x81, 0x00, 0x80, SCREG_025_A, 0x80, SCREG_038_A, 0x21, 0x00, 0x00, 0x01, 0x00}, //ANALOG_COM_INPUT0
        {0x18, 0x40, 0xF8, 0xDE, 0x81, 0x01, 0x40, 0x80, SCREG_025_A, 0x80, SCREG_038_A, 0x21, 0xC0, 0x10, 0x51, 0x00}, //ANALOG_SOG_INPUT0
    #if DVI_MODE == DVI_HV_MODE
        {0x10, 0x00, 0xF0, 0x5E, 0x03, 0x01, 0x00, 0x82, SCREG_025_D, 0x00, SCREG_038_D, 0x90, 0x00, 0x00, 0x01, 0x01}, //DIGITAL_INPUT0
    #elif DVI_MODE == DVI_DE_MODE
        {0x10, 0x00, 0xF0, 0x5E, 0x03, 0x01, 0x00, 0x82, SCREG_025_D, 0x00, SCREG_038_D, 0x20, 0x00, 0x00, 0x01, 0x01}, //DIGITAL_INPUT0
    #elif DVI_MODE == DVI_HVDE_MODE 
        {0x10, 0x00, 0xF0, 0x5E, 0x03, 0x01, 0x08, 0x82, SCREG_025_D, 0x00, SCREG_038_D, 0x90, 0x00, 0x00, 0x01, 0x01}, //DIGITAL_INPUT0
    #endif
        {0x10, 0x00, 0xF0, 0x5E, 0x81, 0x81, 0x00, 0x81, SCREG_025_A, 0x00, SCREG_038_A, 0x20, 0x00, 0x01, 0x01, 0x00}, //ANALOG_SEP_INPUT1
        {0x10, 0x00, 0xF0, 0x5E, 0x81, 0x81, 0x00, 0x81, SCREG_025_A, 0x80, SCREG_038_A, 0x21, 0x00, 0x00, 0x01, 0x00}, //ANALOG_COM_INPUT1
        {0x18, 0x40, 0xF8, 0xDE, 0x81, 0x01, 0x40, 0x81, SCREG_025_A, 0x80, SCREG_038_A, 0x21, 0xC0, 0x10, 0x51, 0x00}, //ANALOG_SOG_INPUT1
    #if DVI_MODE == DVI_HV_MODE
        {0x10, 0x00, 0xF0, 0x5E, 0x03, 0x01, 0x00, 0x86, SCREG_025_D, 0x00, SCREG_038_D, 0x90, 0x00, 0x00, 0x01, 0x01}, //DIGITAL_INPUT1
    #elif DVI_MODE == DVI_DE_MODE
        {0x10, 0x00, 0xF0, 0x5E, 0x03, 0x01, 0x00, 0x86, SCREG_025_D, 0x00, SCREG_038_D, 0x20, 0x00, 0x00, 0x01, 0x01}, //DIGITAL_INPUT1
    #elif DVI_MODE == DVI_HVDE_MODE
        {0x10, 0x00, 0xF0, 0x5E, 0x03, 0x01, 0x08, 0x86, SCREG_025_D, 0x00, SCREG_038_D, 0x90, 0x00, 0x00, 0x01, 0x01}, //DIGITAL_INPUT1
    #endif
        {0x18, 0xA0, 0xF8, 0xDE, 0x81, 0x01, 0xC0, 0x80, SCREG_025_A, 0x80, SCREG_038_A, 0x21, 0xC0, 0x10, 0x51, 0x00}, //ANALOG_YPBPR_INPUT0
        {0x18, 0xA0, 0xF8, 0xDE, 0x81, 0x01, 0xC0, 0x81, SCREG_025_A, 0x80, SCREG_038_A, 0x21, 0xC0, 0x10, 0x51, 0x00}, //ANALOG_YPBPR_INPUT1
#if 1//(INPUT_INTERFACE&INPUT_DP)      
    #if DVI_MODE == DVI_HV_MODE
        {0x10, 0x00, 0xF0, 0x5E, 0x03, 0x01, 0x00, 0x83, SCREG_025_D, 0x00, SCREG_038_D, 0x90, 0x00, 0x00, 0x01, 0x01}, //DISPLAY_PORT_INPUT
    #elif DVI_MODE == DVI_DE_MODE
        {0x10, 0x00, 0xF0, 0x5E, 0x03, 0x01, 0x00, 0x83, SCREG_025_D, 0x00, SCREG_038_D, 0x20, 0x00, 0x00, 0x01, 0x01}, //DISPLAY_PORT_INPUT
    #elif DVI_MODE == DVI_HVDE_MODE
        {0x10, 0x00, 0xF0, 0x5E, 0x03, 0x01, 0x08, 0x83, SCREG_025_D, 0x00, SCREG_038_D, 0x90, 0x00, 0x00, 0x01, 0x01}, //DISPLAY_PORT_INPUT
    #endif
#endif
#if 1//(INPUT_INTERFACE&INPUT_DP1)      
    #if DVI_MODE == DVI_HV_MODE
        {0x10, 0x00, 0xF0, 0x5E, 0x03, 0x01, 0x00, 0x87, SCREG_025_D, 0x00, SCREG_038_D, 0x90, 0x00, 0x00, 0x01, 0x01}, //DISPLAY_PORT_INPUT
    #elif DVI_MODE == DVI_DE_MODE
        {0x10, 0x00, 0xF0, 0x5E, 0x03, 0x01, 0x00, 0x87, SCREG_025_D, 0x00, SCREG_038_D, 0x20, 0x00, 0x00, 0x01, 0x01}, //DISPLAY_PORT_INPUT
    #elif DVI_MODE == DVI_HVDE_MODE
        {0x10, 0x00, 0xF0, 0x5E, 0x03, 0x01, 0x08, 0x87, SCREG_025_D, 0x00, SCREG_038_D, 0x90, 0x00, 0x00, 0x01, 0x01}, //DISPLAY_PORT_INPUT
    #endif
#endif
    };
    
    UCHAR *p;
    UCHAR i, k, interface_index, tmp;
#if 0//ENABLE_FREESYNC_HDMI_FUNC == ON
    UCHAR TempSource ;
#endif

    ucZpInterface = interface;
#if IS_NT68870_SERIES
    PhyLinkSelect(interface);
#if (INPUT_INTERFACE & INPUT_MHL_MASK) 
    MHL_PhyOff();
#endif
#endif
    if (IsZpMode()) return;

#if ENABLE_OVERSCAN == ON
    DisableOverSample();
#endif
    PowerUpAllInput();
    
    //printf("if=%x\r\n",(USHRT)interface);//jtest

#if ENABLE_EMBEDED_TMDS_CLOCK_TRAINING == ON
    
#if 1//IS_NT68810_SERIES
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1)
    if (((interface == DISPLAY_PORT_INPUT) || (interface == DISPLAY_PORT_INPUT1))) {
        Set6502Active(_DPPP_PHY0);
    #if (ENABLE_DP_AUX_MONITOR==ON)
        Init_DP_Strobe();   
    #endif
    }
#endif
#if (INPUT_INTERFACE&INPUT_DIG0) || (INPUT_INTERFACE&INPUT_DIG1)
    if (((interface == DIGITAL_INPUT0) || (interface == DIGITAL_INPUT1))) {
        SetTMDS6502Active(_DPPP_PHY0); 
    }
#endif
#endif

#if IS_NT68870_SERIES
#if (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
    if (((interface == DISPLAY_PORT_INPUT2) || (interface == DISPLAY_PORT_INPUT3))) {
        Set6502Active(_DPPP_PHY1);
    #if (ENABLE_DP_AUX_MONITOR==ON)
        Init_DP_Strobe();   
    #endif
    }
#endif
#if (INPUT_INTERFACE&INPUT_DIG2) || (INPUT_INTERFACE&INPUT_DIG3)
    if (((interface == DIGITAL_INPUT2) || (interface == DIGITAL_INPUT3))) {
        SetTMDS6502Active(_DPPP_PHY1);
    }
#endif
#endif

#else//=================================================================
    
#if 1//IS_NT68810_SERIES
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1)
    if (((interface == DISPLAY_PORT_INPUT) || (interface == DISPLAY_PORT_INPUT1))) {
        Set6502Active(_DPPP_PHY0);
    #if (ENABLE_DP_AUX_MONITOR==ON)
        Init_DP_Strobe();   
    #endif
    }
#endif
    if (((interface == DIGITAL_INPUT0) || (interface == DIGITAL_INPUT1))) {
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1)
        Set6502Hold(_DPPP_PHY0);
#endif
        TMDSInit(_DPPP_PHY0);
    }
#endif
    
#if IS_NT68870_SERIES
#if (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
    if (((interface == DISPLAY_PORT_INPUT2) || (interface == DISPLAY_PORT_INPUT3))) {
        Set6502Active(_DPPP_PHY1);
    #if (ENABLE_DP_AUX_MONITOR==ON)
        Init_DP_Strobe();   
    #endif
    }
#endif
    if (((interface == DIGITAL_INPUT2) || (interface == DIGITAL_INPUT3))) {
#if (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
        Set6502Hold(_DPPP_PHY1);
#endif
        TMDSInit(_DPPP_PHY1);
    }
#endif

#endif    

#if ENABLE_USB_TYPE_C == ON
    USBCCIOADCRead(interface);
    //DPLane_Switch(interface);
#endif

    tmp = SC_HCNT_THR;  // 0x1a7
    SC_HCNT_THR = 0x00;// 0x1a7
    Sleep(10);  // Delay 10ms to force mode change
    SC_HCNT_THR = tmp;// 0x1a7

#if ENABLE_HDMI == ON
    // Always enable preamble detection during sync detection
    HDMIEnablePreambleDetection(TRUE);
    HDMISoftReset();
#endif

    SC_ADC_ZERO_POWER_CTRL &= 0xF3; // 0xb57
    SC_GI_FIELD_WIN = 0xB7;//0xC5;  // 0x198

    switch (interface) {
        case ANALOG_SEP_INPUT0:
            SC_ADC_REG_1D &= ~BIT5;  //870=0x1ec   
            SC_GI_SYNC_CTRL3 = 0x42; // 0x199
            SC_ADC_ZERO_POWER_CTRL |= BIT3;  // 0xb57
            SC_HDMI_AUTO_CTRL &= ~BIT6;  // 0x6b5
            interface_index = 0;
            break;

        case ANALOG_COM_INPUT0:
            SC_ADC_REG_1D &= ~BIT5;//870=0x1ec   
            SC_GI_SYNC_CTRL3 = 0x42; // 0x199
            SC_ADC_ZERO_POWER_CTRL |= BIT3;// 0xb57
            SC_HDMI_AUTO_CTRL &= ~BIT6;// 0x6b5
            interface_index = 1;
            break;

        case ANALOG_SOG_INPUT0:
            SC_ADC_REG_1D |= BIT5;//870=0x1ec   
            SC_GI_SYNC_CTRL3 = 0x42; // 0x199
            SC_ADC_ZERO_POWER_CTRL |= BIT3;// 0xb57
            SC_CLAMP_BEGIN |= BIT6;  // 0x021
            Sleep(2);
            SC_CLAMP_BEGIN &= ~BIT6;// 0x021
            SC_HDMI_AUTO_CTRL &= ~BIT6;// 0x6b5
            interface_index = 2;
            break;

        case DIGITAL_INPUT0:
#if IS_NT68870_SERIES
        case DIGITAL_INPUT1:
        case DIGITAL_INPUT2:
        case DIGITAL_INPUT3:
#endif
            
            SC_ADC_REG_1D &= ~BIT5;//870=0x1ec   
        #if DVI_MODE == DVI_DE_MODE
            SC_GI_SYNC_CTRL3 = 0x46; // 0x199
        #else
            SC_GI_SYNC_CTRL3 = 0x42; // 0x199
        #endif
            if (interface==DIGITAL_INPUT0) {
                HDCP_MUX = DIGITAL_INPUT0_HDCP_MUX;
#if (IS_NT68810_SERIES || IS_NT68870_SERIES) 
                #if (INPUT_INTERFACE&INPUT_MHL0)
                if (MHL_Is_CDSense1_IO_HIGH()) {
                    MHLCBus1On();
                    MHLCDSense1On();
                }
                else {
                    MHLCBus1Off();
                    MHLCDSense1Off();
                }
                #endif
                #if (INPUT_INTERFACE&INPUT_MHL1)
                    MHLCBus2Off();
                    MHLCDSense2Off();
                #endif
                #if (INPUT_INTERFACE&INPUT_MHL2) || (INPUT_INTERFACE&INPUT_MHL3)
                    MHLCBus1Off();
                    MHLCDSense1Off();
                    MHLCBus2Off();
                    MHLCDSense2Off();
                #endif                
#endif                                
            }    
#if IS_NT68870_SERIES
            else if (interface==DIGITAL_INPUT1) {
                HDCP_MUX = DIGITAL_INPUT1_HDCP_MUX;
#if IS_NT68870_SERIES
                #if (INPUT_INTERFACE&INPUT_MHL1)
                if (MHL_Is_CDSense2_IO_HIGH()) {
                    MHLCBus2On();
                    MHLCDSense2On();
                }
                else {
                    MHLCBus2Off();
                    MHLCDSense2Off();
                }
                #endif
                #if (INPUT_INTERFACE&INPUT_MHL0)                    
                MHLCBus1Off();
                MHLCDSense1Off();
                #endif
                #if (INPUT_INTERFACE&INPUT_MHL2) || (INPUT_INTERFACE&INPUT_MHL3)
                    MHLCBus1Off();
                    MHLCDSense1Off();                
                    MHLCBus2Off();
                    MHLCDSense2Off();
                #endif                    
#endif                
            }
            else if (interface==DIGITAL_INPUT2) {
                HDCP_MUX = DIGITAL_INPUT2_HDCP_MUX;
#if IS_NT68870_SERIES 
                #if (INPUT_INTERFACE&INPUT_MHL2)
                if (MHL_Is_CDSense1_IO_HIGH()) {
                    MHLCBus1On();
                    MHLCDSense1On();
                }
                else {
                    MHLCBus1Off();
                    MHLCDSense1Off();
                }
                #endif
                #if (INPUT_INTERFACE&INPUT_MHL3)
                MHLCBus2Off();
                MHLCDSense2Off();
                #endif
                #if (INPUT_INTERFACE&INPUT_MHL0) || (INPUT_INTERFACE&INPUT_MHL1)
                MHLCBus1Off();
                MHLCDSense1Off();                
                MHLCBus2Off();
                MHLCDSense2Off();
                #endif                
#endif                                                
            }
            else if (interface==DIGITAL_INPUT3) {
                HDCP_MUX = DIGITAL_INPUT3_HDCP_MUX;
#if IS_NT68870_SERIES
                #if (INPUT_INTERFACE&INPUT_MHL3)
                if (MHL_Is_CDSense2_IO_HIGH()) {
                    MHLCBus2On();
                    MHLCDSense2On();
                }
                else {
                    MHLCBus2Off();
                    MHLCDSense2Off();
                }
                #endif
                #if (INPUT_INTERFACE&INPUT_MHL2)                    
                MHLCBus1Off();
                MHLCDSense1Off();
                #endif
                #if (INPUT_INTERFACE&INPUT_MHL0) || (INPUT_INTERFACE&INPUT_MHL1)
                MHLCBus1Off();
                MHLCDSense1Off();                
                MHLCBus2Off();
                MHLCDSense2Off();
                #endif                    
#endif                                
            }
#endif
            SC_HSDDS_DIVIDER_LO = 0x00;  // 0xd7
            SC_HSDDS_DIVIDER_HI = 0x02;
            SC_HPLL_FREQ_CTRL &= ~BIT6; //Enable updating HS_CNT// 0xd1
            SC_HPLL_PHASE_CTRL1 = 0x00; // 0xd9
            SC_HDMI_AUTO_CTRL |= BIT6;// 0x6b5
            interface_index = 3;
#if IS_NT68770_SERIES && (INPUT_INTERFACE&INPUT_MHL0) //Switch 2 path connected-MHL
            if ( MHL_Is_CDSense1_IO_HIGH() ) {
                SC_DVI_CTRL_339 = 0x16;
                SC_DVI_CTRL_33A = 0x60;
                if ( MHLIsCBus2On() && GetCbusConnectStatus() != MHL_NONE ) {
                    MHLCBus2Off();
                    SC_CBUS_CONTROL |= BIT3;
                    SC_CBUS_CONTROL &= ~BIT3;
                    SetCbusConnectStatus(MHL_NONE);
                }
                MHL_SetCbusCH1(); 
                MHLCBus1On();
            }
#endif
        #if IS_NT68790_SERIES || IS_NT68658_SERIES || IS_NT68810_SERIES || IS_NT68870_SERIES
            SC_AUDIO_AUTO_CTRL8 = 0x03;//Sigma Delta audio clock gated  // 0x8ae
        #endif
            break;

        case ANALOG_SEP_INPUT1:
            SC_ADC_REG_1D &= ~BIT5;//870=0x1ec   
            SC_GI_SYNC_CTRL3 = 0x42; // 0x199
            SC_ADC_ZERO_POWER_CTRL |= BIT3;// 0xb57
            SC_HDMI_AUTO_CTRL &= ~BIT6;// 0x6b5
            interface_index = 4;
            break;

        case ANALOG_COM_INPUT1:
            SC_ADC_REG_1D &= ~BIT5;//870=0x1ec   
            SC_GI_SYNC_CTRL3 = 0x42; // 0x199
            SC_ADC_ZERO_POWER_CTRL |= BIT3;// 0xb57
            SC_HDMI_AUTO_CTRL &= ~BIT6;// 0x6b5
            interface_index = 5;
            break;

        case ANALOG_SOG_INPUT1:
            SC_ADC_REG_1D |= BIT5;//870=0x1ec   
            SC_GI_SYNC_CTRL3 = 0x42; // 0x199
            SC_ADC_ZERO_POWER_CTRL |= BIT3;// 0xb57
            SC_CLAMP_BEGIN |= BIT6;// 0x021
            Sleep(2);
            SC_CLAMP_BEGIN &= ~BIT6;// 0x021
            SC_HDMI_AUTO_CTRL &= ~BIT6;// 0x6b5
            interface_index = 6;
            break;

#if IS_NT68810_SERIES
        case DIGITAL_INPUT1:
            SC_ADC_REG_1D &= ~BIT5;//870=0x1ec   
        #if DVI_MODE == DVI_DE_MODE
            SC_GI_SYNC_CTRL3 = 0x46; // 0x199
        #else
            SC_GI_SYNC_CTRL3 = 0x42; // 0x199
        #endif
            HDCP_MUX = DIGITAL_INPUT1_HDCP_MUX;
            SC_HSDDS_DIVIDER_LO = 0x00;
            SC_HSDDS_DIVIDER_HI = 0x02;
            SC_HPLL_FREQ_CTRL &= ~BIT6; //Enable updating HS_CNT// 0xd1
            SC_HPLL_PHASE_CTRL1 = 0x00;// 0xd9
            SC_HDMI_AUTO_CTRL |= BIT6;// 0x6b5
            interface_index = 7;
#if IS_NT68770_SERIES && (INPUT_INTERFACE&INPUT_MHL1) //Switch 2 path connected-MHL
            if ( MHL_Is_CDSense2_IO_HIGH() ) {
                SC_DVI_CTRL_339 = 0x16;
                SC_DVI_CTRL_33A = 0x60;
                if ( MHLIsCBus1On() && GetCbusConnectStatus() != MHL_NONE ) {
                    MHLCBus1Off();
                    SC_CBUS_CONTROL |= BIT3;
                    SC_CBUS_CONTROL &= ~BIT3;
                    SetCbusConnectStatus(MHL_NONE);
                }
                MHL_SetCbusCH2(); 
                MHLCBus2On();
            }
#elif IS_NT68810_SERIES 
            #if (INPUT_INTERFACE&INPUT_MHL1)
            if (MHL_Is_CDSense2_IO_HIGH()) {
                MHLCBus2On();
                MHLCDSense2On();
                //printf("DIGITAL_INPUT1 cd on\r\n");
            }
            else {
                MHLCBus2Off();
                MHLCDSense2Off();
                //printf("DIGITAL_INPUT1 cd off\r\n");
            }
            #endif
            #if (INPUT_INTERFACE&INPUT_MHL0)                                            
            MHLCBus1Off();
            MHLCDSense1Off();
            #endif
#endif
        #if IS_NT68790_SERIES || IS_NT68658_SERIES || IS_NT68810_SERIES || IS_NT68870_SERIES
            SC_AUDIO_AUTO_CTRL8 = 0x03;//Sigma Delta audio clock gated // 0x8ae
        #endif
            break;
#endif
        case ANALOG_YPBPR_INPUT0:
            SC_ADC_REG_1D |= BIT5;//870=0x1ec   
            SC_GI_SYNC_CTRL3 = 0x42; // 0x199
            SC_ADC_ZERO_POWER_CTRL |= BIT3;// 0xb57
            SC_CLAMP_BEGIN |= BIT6;// 0x021
            Sleep(2);
            SC_CLAMP_BEGIN &= ~BIT6;// 0x021
            SC_HDMI_AUTO_CTRL &= ~BIT6;// 0x6b5
            interface_index = 8;
            break;

        case ANALOG_YPBPR_INPUT1:
            SC_ADC_REG_1D |= BIT5;//870=0x1ec   
            SC_GI_SYNC_CTRL3 = 0x42; // 0x199
            SC_ADC_ZERO_POWER_CTRL |= BIT3;// 0xb57
            SC_CLAMP_BEGIN |= BIT6;// 0x021
            Sleep(2);
            SC_CLAMP_BEGIN &= ~BIT6;// 0x021
            SC_HDMI_AUTO_CTRL &= ~BIT6;// 0x6b5
            interface_index = 9;
            break;
#if (IS_NT68810_SERIES && (INPUT_INTERFACE&INPUT_DP)) || IS_NT68870_SERIES 
         case DISPLAY_PORT_INPUT:
#if IS_NT68870_SERIES
         case DISPLAY_PORT_INPUT1:
         case DISPLAY_PORT_INPUT2:
         case DISPLAY_PORT_INPUT3:
#endif
            SC_GI_FIELD_WIN = 0xB5;//0xC5;  // 0x198
            SC_ADC_REG_1D &= ~BIT5;//870=0x1ec   
        #if DVI_MODE == DVI_DE_MODE
            SC_GI_SYNC_CTRL3 = 0x46; // 0x199
        #else
            SC_GI_SYNC_CTRL3 = 0x42; // 0x199
        #endif
            HDCP_MUX = DIGITAL_INPUT1_HDCP_MUX;
            SC_HSDDS_DIVIDER_LO = 0x00;// 0xd7
            SC_HSDDS_DIVIDER_HI = 0x02;
            SC_HPLL_FREQ_CTRL &= ~BIT6; //Enable updating HS_CNT// 0xd1
            SC_HPLL_PHASE_CTRL1 = 0x00;// 0xd9
#if IS_NT68810_SERIES
            SC_TMDS_LINK_CLK_SEL = SCREG_1E7 | BIT0;//0x19;//0x51;
#else //NT68870
            SC_DP_LINK_CLK_SEL &= ~(BIT4|BIT3);// make sure it is correct,Yes OK
#endif
            SC_HDMI_AUTO_CTRL |= BIT6;// 0x6b5
        #if IS_NT68790_SERIES || IS_NT68658_SERIES || IS_NT68810_SERIES || IS_NT68870_SERIES
            SC_AUDIO_AUTO_CTRL8 = 0x07;//Sigma Delta audio clock gated // 0x8ae
        #endif
        #if IS_NT68810_SERIES
            DPAUX_Select(_AUX_CH0);
        #else
            if (interface == DISPLAY_PORT_INPUT) {
                DPAUX_Select(_AUX_CH0);
            }
            else if (interface == DISPLAY_PORT_INPUT1) {
                DPAUX_Select(_AUX_CH1);
            }
            else if (interface == DISPLAY_PORT_INPUT2) {
                DPAUX_Select(_AUX_CH2);
            }
            else if (interface == DISPLAY_PORT_INPUT3) {
                DPAUX_Select(_AUX_CH3);
            }
        #endif
            interface_index = 10;
            break;
#endif
#if IS_NT68810_SERIES
#if (INPUT_INTERFACE&INPUT_DP1)
         case DISPLAY_PORT_INPUT1:
            SC_GI_FIELD_WIN = 0xB5;//0xC5;
            SC_ADC_REG_1D &= ~BIT5;//870=0x1ec   
        #if DVI_MODE == DVI_DE_MODE
            SC_GI_SYNC_CTRL3 = 0x46; // 0x199
        #else
            SC_GI_SYNC_CTRL3 = 0x42; // 0x199
        #endif
            HDCP_MUX = DIGITAL_INPUT1_HDCP_MUX;
            SC_HSDDS_DIVIDER_LO = 0x00;// 0xd7
            SC_HSDDS_DIVIDER_HI = 0x02;
            SC_HPLL_FREQ_CTRL &= ~BIT6; //Enable updating HS_CNT// 0xd1
            SC_HPLL_PHASE_CTRL1 = 0x00;// 0xd9
            SC_TMDS_LINK_CLK_SEL = SCREG_1E7 | BIT0;//0x19;//0x51;
            SC_HDMI_AUTO_CTRL |= BIT6;// 0x6b5
        #if IS_NT68790_SERIES || IS_NT68658_SERIES || IS_NT68810_SERIES || IS_NT68870_SERIES
            SC_AUDIO_AUTO_CTRL8 = 0x07;//Sigma Delta audio clock gated // 0x8ae
        #endif
        #if IS_NT68810_SERIES
            DPAUX_Select(_AUX_CH1);
        #endif
            interface_index = 11;
            break;
#endif
#endif
    }

    k = (sizeof(interface_tab)/3); //Address is 3 bytes
    for (i=0; i<k; i++) {
        p = interface_tab[i];
        *p = interface_data[interface_index][i];
    }
    
#if IS_NT68810_SERIES
    if ((SC_ADC_IP_CTRL_1D80[_ADC_CLAMP_VMID_SEL] & 0xE0) == YPBPR_CLAMP) {  //  22
        SC_ADC_IP_CTRL_1D80[_ADC_VMID_CTRL] |= BIT7; //  11
    }
    else {
        SC_ADC_IP_CTRL_1D80[_ADC_VMID_CTRL] &= ~BIT7; //  11
    }
#else
    if ((SC_ADC_IP_CTRL_1D80[_ADC_CLAMP_VMID_SEL] & 0xE0) == YPBPR_CLAMP) {  //  22
        SC_ADC_IP_CTRL_1D80[_ADC_VREF_BIAS] = 0xA0;//0x80;//ADC_VREF_BIAS   12
    }
    else {
        SC_ADC_IP_CTRL_1D80[_ADC_VREF_BIAS] = 0x00;//0x80;//ADC_VREF_BIAS  12
    }
    SC_ADC_IP_CTRL_1D80[_ADC_CLAMP_VMID_SEL] = 0xE0;  //  22
#endif
    if ((SC_ADC_IP_CTRL_1D80[_ADC_MISC_CTRL_33] & 0xC0) == 0xC0) {//SOG
        SC_ADC_IP_CTRL_1D80[_ADC_MISC_CTRL_34] |= BIT5;
    }
    else {
        SC_ADC_IP_CTRL_1D80[_ADC_MISC_CTRL_34] &= ~BIT5;
    }

#if ICP_NEW_DE_MODE == OFF
    SC_NEW_DE_MODE_EN = 0x00;  // 0x66b
#endif

#if defined(ENABLE_FPGA_MODE)
// only for special case in FPGA stage
    if ( interface == DISPLAY_PORT_INPUT ) {
        SC_GI_SYNC_CTRL = 0x20;
    }
    else {
        if ((SC_GI_SYNC_CTRL & 0x30)==0x20) {
            SC_GI_SYNC_CTRL &= 0xcf;
            SC_GI_SYNC_CTRL |= 0x10;
        }
        SC_DIGITAL_CTRL &= ~BIT3;
    }
#endif

    Sleep(80);

#if (INPUT_INTERFACE&INPUT_MHL_MASK) 
    if ( (interface==DIGITAL_INPUT0 && MHLIsCBus1On()) || (interface==DIGITAL_INPUT1 && MHLIsCBus2On()) ||
          (interface==DIGITAL_INPUT2 && MHLIsCBus1On())|| (interface==DIGITAL_INPUT3 && MHLIsCBus2On())     ) {
        if ( MHLIsClearHPD() ) {
            Sleep(20); //at least 100ms
            MHLResetHPD();
        }
    }
#endif

#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1) || (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
    if ((interface==DISPLAY_PORT_INPUT) || (interface==DISPLAY_PORT_INPUT1) || (interface==DISPLAY_PORT_INPUT2) || (interface==DISPLAY_PORT_INPUT3)) {
        SC_V_CHANG_CTRL = 0x28; // DP 1080i   // 0x1a8
        SC_VPLL_CTRL |= BIT2; //audio fifo  // 0xb19
        SC_DP_CRPLL |= BIT2;//audio path// 0x16d1
        //SC_OVERSCAN_MODE |= BIT7;  // 0x3fb
    }
    else {
        SC_V_CHANG_CTRL = 0x24;  // 0x1a8
        SC_VPLL_CTRL &= ~BIT2; //audio  // 0xb19
        SC_DP_CRPLL &= ~BIT2;//audio path// 0x16d1
    }
#endif
#if 0//ENABLE_FREESYNC_HDMI_FUNC == ON
    TempSource = UserGetInputSource();
    if (TempSource == INPUT_SC_HDMI || TempSource == INPUT_SC_HDMI1|| TempSource == INPUT_SC_HDMI2|| TempSource == INPUT_SC_HDMI3|| TempSource == INPUT_SC_HDMI4) {
        SC_SYNC_INT_EN1 = 0x1C;
        SC_SYNC_INT_FLAG1 = 0x3F;
    }
#endif

}

/**************************************************************************//**
 * Get current input interface.
 * @return Current input interface.
 ******************************************************************************/
UCHAR GetCurrInputInterface(void)
{
    UCHAR curr_interface;

    if (IsZpMode()) {
        return ucZpInterface;
    }

    switch (SC_INPUT_SELECT & 0x03) {  // 0x024
        case 0x00: //ANALOG_INPUT0
            if ((SC_ADC_CTRL & BIT3) != 0) { //Input interface is SOG sync
#if IS_NT68810_SERIES
                if ((SC_ADC_IP_CTRL_1D80[_ADC_CLAMP_VMID_SEL] & 0xE0) == YPBPR_CLAMP) {
#else
                if ((SC_ADC_IP_CTRL_1D80[_ADC_VREF_BIAS] & 0xE0) == YPBPR_CLAMP) {
#endif
                    curr_interface = ANALOG_YPBPR_INPUT0;
                }
                else {
                    curr_interface = ANALOG_SOG_INPUT0;
                }
            }
            else {
                if ((SC_GI_SYNC_CTRL & BIT0) != 0) { //Input interface is composite sync
                    curr_interface = ANALOG_COM_INPUT0;
                }
                else { //Input interface is seperate sync
                    curr_interface = ANALOG_SEP_INPUT0;
                }
            }
            break;

        case 0x01: //ANALOG_INPUT1
            if ((SC_ADC_CTRL & BIT3) != 0) { //Input interface is SOG sync
                if ((SC_ADC_MID_CH_SEL & 0x07) == YPBPR_CLAMP) {
                    curr_interface = ANALOG_YPBPR_INPUT1;
                }
                else {
                    curr_interface = ANALOG_SOG_INPUT1;
                }
            }
            else {
                if ((SC_GI_SYNC_CTRL & BIT0) != 0) { //Input interface is composite sync
                    curr_interface = ANALOG_COM_INPUT1;
                }
                else { //Input interface is seperate sync
                    curr_interface = ANALOG_SEP_INPUT1;
                }
            }
            break;
#if IS_NT68810_SERIES
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1)
        case 0x03: //DIGITAL INPUT1
            if ((SC_INPUT_SELECT & BIT2) == 0x00) {
                curr_interface = DISPLAY_PORT_INPUT;
            }
            else {
                curr_interface = DISPLAY_PORT_INPUT1;
            }
            break;
#endif
        case 0x02: //DIGITAL INPUT0
            if ((SC_INPUT_SELECT & BIT2) == 0x00) {
                curr_interface = DIGITAL_INPUT0;
            }
            else {
                curr_interface = DIGITAL_INPUT1;
            }
            break;
#else
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1) || (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
        case 0x03: //DIGITAL INPUT1
            curr_interface = GetDPPhyLinkSelect();
            break;
#endif
        case 0x02: //DIGITAL INPUT0
            curr_interface = GetTMDSPhyLinkSelect();
            break;
#endif
        default:
            curr_interface = INTERFACE_ERROR;
            break;
    }

    return curr_interface;
}

/**************************************************************************//**
 * Get Scaler type and version
 ******************************************************************************/
UCHAR GetSCID(void)
{
UCHAR ret = SCID_UNKNOWN;
    switch(SC_CHIP_ID){  // 0x105
    case 0x14:
        switch(SC_REVISION_ID){ //0x104
        case 0x00:
            ret = SCID_810_A;
            break;
        case 0x01:
            ret = SCID_810_B;
            break;
        case 0x02:
            ret = SCID_810_C;
            break;
        default:
            ret = SCID_810_FINAL;
            break;
        }
        break;
    }

    return ret;
}

/**************************************************************************//**
 * Get EFUSE Scaler type and version
 ID  Data    Trim address    Name
 Cust ID     0x91[15 :12]     Customer ID
                                         4b0000=NVT, 4b0001=Samsung
 ReVer ID   0x91[11 :8]       ReVer ID is same as 0x104
 Sub ID      0x91[7 :0]         Sub ID = part no 後兩碼
                                          Ex :NT68810=0x10
                                                Nt68843=0x43
 ******************************************************************************/
#if ENABLE_HDCP_TRIM_MODE == ON
USHRT GetEFUSE_SCID(void)
{//depend on application.....TBD
    UCHAR ret = SCID_UNKNOWN;
    switch(ucEFUSE_ID&0xF0){
    case 0x10://for Samsung efuse
        switch(SC_REVISION_ID){
        case 0x00:
            ret = SCID_810_A;
            break;
        case 0x01:
            ret = SCID_810_B;
            break;
        case 0x02:
            ret = SCID_810_C;
            break;
        default:
            ret = SCID_810_FINAL;
            break;
        }
        break;
    }
    
    return ret;
}
//new add 20151021
#if IS_NT68810_SERIES || IS_NT68870_SERIES  
#if ENABLE_HDCP_TRIM_MODE == ON || ENABLE_EDID_TRIM_MODE == ON
void EFUSE_MAPPING(void)
{
/*
     LED_Curr(288) -> Reg. 0xE37[7:0]
     LED_OVP(289)-> Reg.E36[7:0]
     ADC07(292)->Reg. 0x1D9C & set 0x1DA0=0x20
*/
#if 0
UCHAR tmp_0xF04C, tmp_0x8D55, tmp_0x8D50, tmp_0x8101, tmp_0x8102, tmp_0x8641, tmp_0x8D58;

//12MHz
    SC_ADC_ZERO_POWER_CTRL |= 0x81;
    tmp_0xF04C = CPU_CLK;
    CPU_CLK = 0x10;
    tmp_0x8101 = SC_POWER_CTRL1;
    SC_POWER_CTRL1 = 0x00;
    tmp_0x8102 = SC_POWER_CTRL2;
    SC_POWER_CTRL2 |= BIT1;
    tmp_0x8641 = SC_HDCP_INPUT_CTRL;
//
    tmp_0x8D58 = SC_HDCP_TRIM_TEST_MODE;
    tmp_0x8D55 = SC_HDCP_TRIM_CTRL2;
#if defined(ENABLE_FPGA_MODE)
    SC_HDCP_TRIM_CTRL2 |= BIT6;
#else
    SC_HDCP_TRIM_CTRL2 &= ~BIT6;
#endif
// 
    tmp_0x8D50 = SC_HDCP_TRIM_CTRL;
    SC_HDCP_TRIM_CTRL |= BIT0;
    SC_HDCP_TRIM_CTRL &= ~BIT1;
  
    SC_HDCP_TRIM_CTRL |= BIT2; 
    SC_HDCP_TRIM_TEST_MODE |= BIT7;
    SC_HDCP_TRIM_PI |= BIT0;

    //efuse mapping LED curr and OVP, need before LED drivier enable
    SC_HDCP_TRIM_ADDR_B = 0x00;
    SC_HDCP_TRIM_ADDR_A = 0x90; // addr for LED_CURR and LED_OVP
    SC_HDCP_TRIM_ADDR_B = 0x20; // read pulse
    SC_HDCP_TRIM_ADDR_B = 0x00;
    SC_LED_TRIM_E36 |= (SC_HDCP_TRIM_DATA_HI&0x0F);
    SC_LED_TRIM_E37 = SC_HDCP_TRIM_DATA_LO; 

    //efuse mapping ADC07, need before internal 0.7V enable
    SC_HDCP_TRIM_ADDR_B = 0x00;
    SC_HDCP_TRIM_ADDR_A = 0x92; // addr for ADC07
    SC_HDCP_TRIM_ADDR_B = 0x20; // read pulse
    SC_HDCP_TRIM_ADDR_B = 0x00;
    SC_ADC_IP_CTRL_1D80[_ADC_TRIM_VALUE] = SC_HDCP_TRIM_DATA_LO; 

    
    SC_HDCP_TRIM_CTRL = tmp_0x8D50;
    SC_HDCP_TRIM_TEST_MODE = tmp_0x8D58;
    SC_HDCP_TRIM_CTRL2 = tmp_0x8D55;
    
    CPU_CLK = tmp_0xF04C;
    SC_HDCP_INPUT_CTRL = tmp_0x8641;
    SC_POWER_CTRL1 = tmp_0x8101;
    SC_POWER_CTRL2 = tmp_0x8102;
#else

    SC_LED_TRIM_E36 = ucLEDTRIM_HI;
    SC_LED_TRIM_E37 = ucLEDTRIM_LO; 
    SC_ADC_IP_CTRL_1D80[_ADC_TRIM_VALUE] = ucADCTRIM;
#if IS_NT68810_SERIES  
    SC_ADC_IP_CTRL_1D80[_ADC_TRIMMING_SEL] = 0x40;
    if ((ucADCTRIM_SEL & 0x60) != 0x00) {
        SC_ADC_IP_CTRL_1D80[_ADC_TRIMMING_SEL] = (ucADCTRIM_SEL & 0x60);
    }
#else //NT68870
    SC_ADC_IP_CTRL_1D80[_ADC_TRIMMING_SEL] = 0x20;
    if ((ucADCTRIM_SEL & 0x60) != 0x00) {
        SC_ADC_IP_CTRL_1D80[_ADC_TRIMMING_SEL] = (ucADCTRIM_SEL & 0x60);
    }
#endif
#endif
} 
#endif
#endif

#endif

