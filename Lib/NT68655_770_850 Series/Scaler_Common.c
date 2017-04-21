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

/**************************************************************************//**
 * Initialize scaler registers, including Power/ADC/LVDS/TMDS/SyncProce etc...
 ******************************************************************************/
void ScalerInitialize(void)
{
    
    if ((SC_POWER_CTRL1&0x0F) != 0x0D) { // HW Reset in int.c
    #if ENABLE_CUT_POWER_ARCH == ON
        SC_POWER_CTRL1 |= BIT7;//power on 101[7]
        SC_CUT_POWER_CTRL |= BIT0;//power on b62[0]
    #endif
        SC_HW_RST = 0x10;
        SC_HW_RST = 0x11;
    }

    SetNormalPowerMode();

#if IS_NT68790_SERIES || IS_NT68658_SERIES
    SC_GI_CLK_REF_HI |= (BIT7|BIT6|BIT5);
#endif

    SC_DPLL_FREQ_CTRL = 0x0C;
    if ((SC_POWER_CTRL1&0x0F) != 0x0D) { // HW Reset in int.c
      SC_POWER_CTRL1 = 0x20;
      SC_POWER_CTRL1 = 0x00;
    }
    SC_VGA_ADC_BIST = 0;

    TurnOnScalerMainPower();
        
#if (INPUT_INTERFACE&INPUT_DP)
        DPInit();
#if (ENABLE_DP_AUX_MONITOR==ON)
        Init_DP_Strobe();   
#endif
#endif

    ADCInit();
    LVDSInit();
    DisplayInit();
    TMDSInit();
    CAPInit();
    SyncInit();
#if ENABLE_HDMI == ON
    HDMIInit();
#endif
    DithInit();
    NRInit();
    EnableScalerPWM(PWM_ALL);

#if (INPUT_INTERFACE&INPUT_MHL0) || (INPUT_INTERFACE&INPUT_MHL1)
    MHLInit();
#endif

#if ENABLE_MMU == ON
    MMUInitialize();
#endif

#if ENABLE_HW_CEC == ON
    InitialCEC(HDMI_CEC_CHANNEL);
#endif

#if ENABLE_SCALER_3D == ON
    SC3DAPI_Init();
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
#if IS_NT68850_SERIES || IS_NT68790_SERIES || IS_NT68658_SERIES
    SC_FPGA_HDMI_DELAY = 0x01;
#else
    SC_FPGA_HDMI_DELAY = 0x02;
#endif

    SC_FRC_CLOCK_SEL |= 0x80;
    SC_DISPLAY_POL_CTRL |= BIT6;
    
    AD9884_Init();
#endif
}

/**************************************************************************//**
 * Configure the scaler input to the specified interface
 * @param interface Input interface.
 ******************************************************************************/
void SetInputInterface(UCHAR interface)
{
    code UCHAR *interface_tab[] = {
        &SC_ADC_CTRL,
        &SC_ADC_MID_CH_SEL,
        &SC_SOG_SLICER_EN,
        &SC_ADC_CLAMP_CTRL,
        &SC_GPORT_CTRL,
        &SC_CLAMP_BEGIN,
        &SC_DIGITAL_CTRL,
        &SC_INPUT_SELECT,
        &SC_ADC_CK_CTRL,
        &SC_CAP_SWAP,
        &SC_GI_ALT_CTRL,
        &SC_GI_SYNC_CTRL,
        &SC_SOG_SLICER_CTRL,
        &SC_BP_SYNC_CTRL,
        &SC_ADC_TEST_MODE
    };
    
    code UCHAR interface_data[][sizeof(interface_tab)/sizeof(UCHAR *)] = {
      //0x000,0x008,0x00A,0x00F,0x020,0x021,0x023,0x024,       0x025,0x026,0x038,       0x196,0x012,0x072,0x1E6
        {0x10, 0x00, 0xF0, 0x00, 0x81, 0x81, 0x00, 0x80, SCREG_025_A, 0x00, SCREG_038_A, 0x20, 0x00, 0x01, 0x01}, //ANALOG_SEP_INPUT0
        {0x10, 0x00, 0xF0, 0x00, 0x81, 0x81, 0x00, 0x80, SCREG_025_A, 0x80, SCREG_038_A, 0x21, 0x00, 0x00, 0x01}, //ANALOG_COM_INPUT0
        {0x18, 0x00, 0xF8, 0x00, 0x81, 0x01, 0x40, 0x80, SCREG_025_A, 0x80, SCREG_038_A, 0x21, 0xC0, 0x10, 0x51}, //ANALOG_SOG_INPUT0
    #if DVI_MODE == DVI_HV_MODE
        {0x10, 0x00, 0xF0, 0x00, 0x83, 0x01, 0x00, 0x82, SCREG_025_D, 0x00, SCREG_038_D, 0x90, 0x00, 0x00, 0x01}, //DIGITAL_INPUT0
    #elif DVI_MODE == DVI_DE_MODE
        {0x10, 0x00, 0xF0, 0x00, 0x83, 0x01, 0x00, 0x82, SCREG_025_D, 0x00, SCREG_038_D, 0x20, 0x00, 0x00, 0x01}, //DIGITAL_INPUT0
    #elif DVI_MODE == DVI_HVDE_MODE 
        {0x10, 0x00, 0xF0, 0x00, 0x83, 0x01, 0x08, 0x82, SCREG_025_D, 0x00, SCREG_038_D, 0x90, 0x00, 0x00, 0x01}, //DIGITAL_INPUT0
    #endif
        {0x10, 0x00, 0xF0, 0x00, 0x81, 0x81, 0x00, 0x81, SCREG_025_A, 0x00, SCREG_038_A, 0x20, 0x00, 0x01, 0x01}, //ANALOG_SEP_INPUT1
        {0x10, 0x00, 0xF0, 0x00, 0x81, 0x81, 0x00, 0x81, SCREG_025_A, 0x80, SCREG_038_A, 0x21, 0x00, 0x00, 0x01}, //ANALOG_COM_INPUT1
        {0x18, 0x00, 0xF8, 0x00, 0x81, 0x01, 0x40, 0x81, SCREG_025_A, 0x80, SCREG_038_A, 0x21, 0xC0, 0x10, 0x51}, //ANALOG_SOG_INPUT1
    #if DVI_MODE == DVI_HV_MODE
        {0x10, 0x00, 0xF0, 0x00, 0x83, 0x01, 0x00, 0x86, SCREG_025_D, 0x00, SCREG_038_D, 0x90, 0x00, 0x00, 0x01}, //DIGITAL_INPUT1
    #elif DVI_MODE == DVI_DE_MODE
        {0x10, 0x00, 0xF0, 0x00, 0x83, 0x01, 0x00, 0x86, SCREG_025_D, 0x00, SCREG_038_D, 0x20, 0x00, 0x00, 0x01}, //DIGITAL_INPUT1
    #elif DVI_MODE == DVI_HVDE_MODE
        {0x10, 0x00, 0xF0, 0x00, 0x83, 0x01, 0x08, 0x86, SCREG_025_D, 0x00, SCREG_038_D, 0x90, 0x00, 0x00, 0x01}, //DIGITAL_INPUT1
    #endif
        {0x18, 0x03, 0xF8, 0x00, 0x81, 0x01, 0xC0, 0x80, SCREG_025_A, 0x80, SCREG_038_A, 0x21, 0xC0, 0x10, 0x51}, //ANALOG_YPBPR_INPUT0
        {0x18, 0x03, 0xF8, 0x00, 0x81, 0x01, 0xC0, 0x81, SCREG_025_A, 0x80, SCREG_038_A, 0x21, 0xC0, 0x10, 0x51}, //ANALOG_YPBPR_INPUT1
#if (INPUT_INTERFACE&INPUT_DP)      
    #if DVI_MODE == DVI_HV_MODE
        {0x10, 0x00, 0xF0, 0x00, 0x83, 0x01, 0x00, 0x87, SCREG_025_D, 0x00, SCREG_038_D, 0x90, 0x00, 0x00, 0x01}, //DISPLAY_PORT_INPUT
    #elif DVI_MODE == DVI_DE_MODE
        {0x10, 0x00, 0xF0, 0x00, 0x83, 0x01, 0x00, 0x87, SCREG_025_D, 0x00, SCREG_038_D, 0x20, 0x00, 0x00, 0x01}, //DISPLAY_PORT_INPUT
    #elif DVI_MODE == DVI_HVDE_MODE
        {0x10, 0x00, 0xF0, 0x00, 0x83, 0x01, 0x08, 0x87, SCREG_025_D, 0x00, SCREG_038_D, 0x90, 0x00, 0x00, 0x01}, //DISPLAY_PORT_INPUT
    #endif
#endif
    };
    
    UCHAR *p;
    UCHAR i, k, interface_index, tmp;

    ucZpInterface = interface;
    if (IsZpMode()) return;

#if ENABLE_OVERSCAN == ON
    DisableOverSample();
#endif
#if !IS_NT68790_SERIES//DC2DC
    PowerUpAllInput();
#else
#if (INPUT_INTERFACE&INPUT_DP)
    if (interface == DISPLAY_PORT_INPUT) {
        VGA_PowerOff();
        DVI_PowerOff();
        DP_PowerOn();
    }
    else {
        DP_PowerOFF();
        DVI_PowerOn();
        VGA_PowerOn();
    }
#else
    PowerUpAllInput();
#endif
#endif
    tmp = SC_HCNT_THR;
    SC_HCNT_THR = 0x00;
    Sleep(10);  // Delay 10ms to force mode change
    SC_HCNT_THR = tmp;

#if ENABLE_HDMI == ON
    // Always enable preamble detection during sync detection
    HDMIEnablePreambleDetection(TRUE);
    HDMISoftReset();
#endif

    SC_ADC_ZERO_POWER_CTRL &= 0xF3;

    switch (interface) {
        case ANALOG_SEP_INPUT0:
            SC_ADC_REG_1D &= ~BIT5;
            SC_GI_SYNC_CTRL3 = 0x42;
            SC_ADC_ZERO_POWER_CTRL |= BIT3;
#if IS_NT68770_SERIES || IS_NT68850_SERIES || IS_NT68790_SERIES || IS_NT68658_SERIES
            SC_HDMI_AUTO_CTRL &= ~BIT6;
            SC_HDMI_3D_INTERLACE_CTRL &= ~BIT7;
            SC_SCALER_3D_DEBUG1 = 0x00;
#endif
            interface_index = 0;
            break;

        case ANALOG_COM_INPUT0:
            SC_ADC_REG_1D &= ~BIT5;
            SC_GI_SYNC_CTRL3 = 0x42;
            SC_ADC_ZERO_POWER_CTRL |= BIT3;
#if IS_NT68770_SERIES || IS_NT68850_SERIES || IS_NT68790_SERIES || IS_NT68658_SERIES
            SC_HDMI_AUTO_CTRL &= ~BIT6;
            SC_HDMI_3D_INTERLACE_CTRL &= ~BIT7;
            SC_SCALER_3D_DEBUG1 = 0x00;
#endif
            interface_index = 1;
            break;

        case ANALOG_SOG_INPUT0:
            SC_ADC_REG_1D |= BIT5;
            SC_GI_SYNC_CTRL3 = 0x42;
            SC_ADC_ZERO_POWER_CTRL |= BIT3;
            SC_CLAMP_BEGIN |= BIT6;
            Sleep(2);
            SC_CLAMP_BEGIN &= ~BIT6;
#if IS_NT68770_SERIES || IS_NT68850_SERIES || IS_NT68790_SERIES || IS_NT68658_SERIES
            SC_HDMI_AUTO_CTRL &= ~BIT6;
            SC_HDMI_3D_INTERLACE_CTRL &= ~BIT7;
            SC_SCALER_3D_DEBUG1 = 0x00;
#endif
            interface_index = 2;
            break;

        case DIGITAL_INPUT0:
            SC_DVI_RB_SWAP = DIGITAL0_CHANNEL_SWAP << 1;
            
            SC_ADC_REG_1D &= ~BIT5;
        #if DVI_MODE == DVI_DE_MODE
            SC_GI_SYNC_CTRL3 = 0x46;
        #else
            SC_GI_SYNC_CTRL3 = 0x42;
        #endif
            HDCP_MUX = DIGITAL_INPUT0_HDCP_MUX;
            SC_HSDDS_DIVIDER_LO = 0x00;
            SC_HSDDS_DIVIDER_HI = 0x02;
            SC_HPLL_FREQ_CTRL &= ~BIT6; //Enable updating HS_CNT
            SC_HPLL_PHASE_CTRL1 = 0x00;
#if IS_NT68770_SERIES || IS_NT68850_SERIES || IS_NT68790_SERIES || IS_NT68658_SERIES
            SC_HDMI_AUTO_CTRL |= BIT6;
            SC_HDMI_3D_INTERLACE_CTRL |= BIT7;
            SC_SCALER_3D_DEBUG1 = 0x83;
#endif
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
                MHL_SetCbusCH1();//(MHL_CBUS_CH1); 
                MHLCBus1On();
            }
#endif
        #if IS_NT68790_SERIES || IS_NT68658_SERIES
            SC_AUDIO_AUTO_CTRL8 = 0x03;//Sigma Delta audio clock gated
        #endif
            break;

        case ANALOG_SEP_INPUT1:
            SC_ADC_REG_1D &= ~BIT5;
            SC_GI_SYNC_CTRL3 = 0x42;
            SC_ADC_ZERO_POWER_CTRL |= BIT3;
#if IS_NT68770_SERIES || IS_NT68850_SERIES || IS_NT68790_SERIES || IS_NT68658_SERIES
            SC_HDMI_AUTO_CTRL &= ~BIT6;
            SC_HDMI_3D_INTERLACE_CTRL &= ~BIT7;
            SC_SCALER_3D_DEBUG1 = 0x00;
#endif
            interface_index = 4;
            break;

        case ANALOG_COM_INPUT1:
            SC_ADC_REG_1D &= ~BIT5;
            SC_GI_SYNC_CTRL3 = 0x42;
            SC_ADC_ZERO_POWER_CTRL |= BIT3;
#if IS_NT68770_SERIES || IS_NT68850_SERIES || IS_NT68790_SERIES || IS_NT68658_SERIES
            SC_HDMI_AUTO_CTRL &= ~BIT6;
            SC_HDMI_3D_INTERLACE_CTRL &= ~BIT7;
            SC_SCALER_3D_DEBUG1 = 0x00;
#endif
            interface_index = 5;
            break;

        case ANALOG_SOG_INPUT1:
            SC_ADC_REG_1D |= BIT5;
            SC_GI_SYNC_CTRL3 = 0x42;
            SC_ADC_ZERO_POWER_CTRL |= BIT3;
            SC_CLAMP_BEGIN |= BIT6;
            Sleep(2);
            SC_CLAMP_BEGIN &= ~BIT6;
#if IS_NT68770_SERIES || IS_NT68850_SERIES || IS_NT68790_SERIES || IS_NT68658_SERIES
            SC_HDMI_AUTO_CTRL &= ~BIT6;
            SC_HDMI_3D_INTERLACE_CTRL &= ~BIT7;
            SC_SCALER_3D_DEBUG1 = 0x00;
#endif
            interface_index = 6;
            break;

        case DIGITAL_INPUT1:
            SC_DVI_RB_SWAP = DIGITAL1_CHANNEL_SWAP << 1;
            
            SC_ADC_REG_1D &= ~BIT5;
        #if DVI_MODE == DVI_DE_MODE
            SC_GI_SYNC_CTRL3 = 0x46;
        #else
            SC_GI_SYNC_CTRL3 = 0x42;
        #endif
            HDCP_MUX = DIGITAL_INPUT1_HDCP_MUX;
            SC_HSDDS_DIVIDER_LO = 0x00;
            SC_HSDDS_DIVIDER_HI = 0x02;
            SC_HPLL_FREQ_CTRL &= ~BIT6; //Enable updating HS_CNT
            SC_HPLL_PHASE_CTRL1 = 0x00;
#if IS_NT68770_SERIES || IS_NT68850_SERIES || IS_NT68790_SERIES || IS_NT68658_SERIES
            SC_HDMI_AUTO_CTRL |= BIT6;
            SC_HDMI_3D_INTERLACE_CTRL |= BIT7;
            SC_SCALER_3D_DEBUG1 = 0x83;
#endif
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
                MHL_SetCbusCH2();//(MHL_CBUS_CH2); 
                MHLCBus2On();
            }
#endif
        #if IS_NT68790_SERIES || IS_NT68658_SERIES
            SC_AUDIO_AUTO_CTRL8 = 0x03;//Sigma Delta audio clock gated
        #endif
            break;

        case ANALOG_YPBPR_INPUT0:
            SC_ADC_REG_1D |= BIT5;
            SC_GI_SYNC_CTRL3 = 0x42;
            SC_ADC_ZERO_POWER_CTRL |= BIT3;
            SC_CLAMP_BEGIN |= BIT6;
            Sleep(2);
            SC_CLAMP_BEGIN &= ~BIT6;
#if IS_NT68770_SERIES || IS_NT68850_SERIES || IS_NT68790_SERIES || IS_NT68658_SERIES
            SC_HDMI_AUTO_CTRL &= ~BIT6;
            SC_HDMI_3D_INTERLACE_CTRL &= ~BIT7;
            SC_SCALER_3D_DEBUG1 = 0x00;
#endif
            interface_index = 8;
            break;

        case ANALOG_YPBPR_INPUT1:
            SC_ADC_REG_1D |= BIT5;
            SC_GI_SYNC_CTRL3 = 0x42;
            SC_ADC_ZERO_POWER_CTRL |= BIT3;
            SC_CLAMP_BEGIN |= BIT6;
            Sleep(2);
            SC_CLAMP_BEGIN &= ~BIT6;
#if IS_NT68770_SERIES || IS_NT68850_SERIES || IS_NT68790_SERIES || IS_NT68658_SERIES
            SC_HDMI_AUTO_CTRL &= ~BIT6;
            SC_HDMI_3D_INTERLACE_CTRL &= ~BIT7;
            SC_SCALER_3D_DEBUG1 = 0x00;
#endif
            interface_index = 9;
            break;
#if (INPUT_INTERFACE&INPUT_DP)
         case DISPLAY_PORT_INPUT:
            SC_ADC_REG_1D &= ~BIT5;
        #if DVI_MODE == DVI_DE_MODE
            SC_GI_SYNC_CTRL3 = 0x46;
        #else
            SC_GI_SYNC_CTRL3 = 0x42;
        #endif
            HDCP_MUX = DIGITAL_INPUT1_HDCP_MUX;
            SC_HSDDS_DIVIDER_LO = 0x00;
            SC_HSDDS_DIVIDER_HI = 0x02;
            SC_HPLL_FREQ_CTRL &= ~BIT6; //Enable updating HS_CNT
            SC_HPLL_PHASE_CTRL1 = 0x00;
            SC_TMDS_LINK_CLK_SEL = SCREG_1E7 | BIT0;//0x19;//0x51;
#if IS_NT68770_SERIES || IS_NT68850_SERIES || IS_NT68790_SERIES || IS_NT68658_SERIES
            SC_HDMI_AUTO_CTRL |= BIT6;
            SC_HDMI_3D_INTERLACE_CTRL |= BIT7;
            SC_SCALER_3D_DEBUG1 = 0x83;
#endif
        #if IS_NT68790_SERIES || IS_NT68658_SERIES
            SC_AUDIO_AUTO_CTRL8 = 0x07;//Sigma Delta audio clock gated
        #endif
            interface_index = 10;
            break;
#endif
    }

    k = (sizeof(interface_tab)/3); //Address is 3 bytes
    for (i=0; i<k; i++) {
        p = interface_tab[i];
        *p = interface_data[interface_index][i];
    }

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

#if (INPUT_INTERFACE&INPUT_MHL0) || (INPUT_INTERFACE&INPUT_MHL1)
    if ( (interface==DIGITAL_INPUT0 && MHLIsCBus1On() ) || (interface==DIGITAL_INPUT1 &&  MHLIsCBus2On() )) {
        if ( MHLIsClearHPD() ) {
            Sleep(20); //at least 100ms
            MHLResetHPD();
        }
    }
#endif

#if (INPUT_INTERFACE&INPUT_DP)
    if (interface==DISPLAY_PORT_INPUT) {
        SC_V_CHANG_CTRL = 0x28; // DP 1080i
        SC_VPLL_CTRL |= BIT2; //audio fifo
        SC_DP_CRPLL |= BIT2;//audio path
        //SC_OVERSCAN_MODE |= BIT7;
    }
    else {
        SC_V_CHANG_CTRL = 0x24;
        SC_VPLL_CTRL &= ~BIT2; //audio 
        SC_DP_CRPLL &= ~BIT2;//audio path
        //SC_OVERSCAN_MODE &= ~BIT7;
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

    switch (SC_INPUT_SELECT & 0x03) {
        case 0x00: //ANALOG_INPUT0
            if ((SC_ADC_CTRL & BIT3) != 0) { //Input interface is SOG sync
                if ((SC_ADC_MID_CH_SEL & 0x07) == YPBPR_CLAMP) {
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

        case 0x03: //DIGITAL INPUT1
#if (INPUT_INTERFACE&INPUT_DP)
            curr_interface = DISPLAY_PORT_INPUT;
            break;
#endif
        case 0x02: //DIGITAL INPUT0
            if ( (SC_INPUT_SELECT & BIT2) == 0x00 ) {
                curr_interface = DIGITAL_INPUT0;
            }
            else {
                curr_interface = DIGITAL_INPUT1;
            }
            break;

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
    switch(SC_CHIP_ID){
    case 0x0A: //661
        ret = SCID_661;
        break;        
    case 0x0B: //850
        switch(SC_REVISION_ID){
        case 0x04:
            ret = SCID_850_E;
            break;
        case 0x03:
            ret = SCID_850_D;
            break;
        case 0x02:
            ret = SCID_850_C;
            break;
        default:
            ret = SCID_850_FINAL;
            break;
        }
        break;
    case 0x0C: //770
        switch(SC_REVISION_ID){
        case 0x06:
            ret = SCID_770_I;
            break;
        case 0x05:
            ret = SCID_770_H;
            break;
        case 0x04:
            ret = SCID_770_G;
            break;
        case 0x03:
            ret = SCID_770_E;
            break; 
        default:
            ret = SCID_770_FINAL;
            break;
        }  
        break;
    case 0x0D: //655
        ret = SCID_655;
        break;
    case 0x0E:
        ret = SCID_370;
        break;
    case 0x10:
        switch(SC_REVISION_ID){
        case 0x00:
            ret = SCID_790_A;
            break;
        case 0x01:
            ret = SCID_790_B;
            break;
        case 0x02:
            ret = SCID_790_C;
            break;
        case 0x03:
            ret = SCID_790_D;
            break;
        case 0x04:
            ret = SCID_790_E;
            break;
        default:
            ret = SCID_790_FINAL;
            break;
        }
        break;
    case 0x11:
        switch(SC_REVISION_ID){
        case 0x00:
            ret = SCID_658_A;
            break;
        case 0x01:
            ret = SCID_658_B;
            break;
        default:
            ret = SCID_658_FINAL;
            break;
        }
        break;
    }

    return ret;
}

/**************************************************************************//**
 * Get EFUSE Scaler type and version
 ******************************************************************************/
#if ENABLE_HDCP_TRIM_MODE == ON
USHRT GetEFUSE_SCID(void)
{
    UCHAR ret = SCID_UNKNOWN;
    switch(ucEFUSE_ID){
    case 0x0A: //661
        ret = SCID_661;
        break;        
    case 0x0B: //850
        switch(SC_REVISION_ID){
        case 0x04:
            ret = SCID_850_E;
            break;
        case 0x03:
            ret = SCID_850_D;
            break;
        case 0x02:
            ret = SCID_850_C;
            break;
        default:
            ret = SCID_850_FINAL;
            break;
        }
        break;
    case 0x0C: //770
        switch(SC_REVISION_ID){
        case 0x06:
            ret = SCID_770_I;
            break;
        case 0x05:
            ret = SCID_770_H;
            break;
        case 0x04:
            ret = SCID_770_G;
            break;
        case 0x03:
            ret = SCID_770_E;
            break; 
        default:
            ret = SCID_770_FINAL;
            break;
        }  
        break;
    case 0x0D: //655
        ret = SCID_655;
        break;
    case 0x0E:
        ret = SCID_370;
        break;
    case 0x10:
        switch(SC_REVISION_ID){
        case 0x00:
            ret = SCID_790_A;
            break;
        case 0x01:
            ret = SCID_790_B;
            break;
        case 0x02:
            ret = SCID_790_C;
            break;
        case 0x03:
            ret = SCID_790_D;
            break;
        case 0x04:
            ret = SCID_790_E;
            break;
        default:
            ret = SCID_790_FINAL;
            break;
        }
        break;
    case 0x11:
        switch(SC_REVISION_ID){
        case 0x00:
            ret = SCID_658_A;
            break;
        case 0x01:
            ret = SCID_658_B;
            break;
        default:
            ret = SCID_658_FINAL;
            break;
        }
        break;
    }
    
    return ret;
}
#endif

