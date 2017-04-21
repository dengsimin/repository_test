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
#if ENABLE_CUT_POWER_ARCH == ON
    SC_POWER_CTRL1 |= BIT7;//power on 101[7]
    SC_CUT_POWER_CTRL |= BIT0;//power on b62[0]
#endif
    SC_HW_RST = 0x10;
    SC_HW_RST = 0x11;

    SetNormalPowerMode();

    SC_DPLL_FREQ_CTRL = 0x0C;
    SC_POWER_CTRL1 = 0x20;
    SC_POWER_CTRL1 = 0x00;
    SC_VGA_ADC_BIST = 0;
#if ENABLE_MMU == ON
    SC_POWER_CTRL2 = 0x6E;
#else
    SC_POWER_CTRL2 = 0x6A;
#endif
#if ENABLE_SCALER_AUDIO
    SC_POWER_CTRL2 |= BIT7;
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

#if ENABLE_MMU == ON
    MMUInitialize();
#endif

#if ENABLE_HW_CEC == ON
    InitialCEC(HDMI_CEC_CHANNEL);
#endif

#if ENABLE_SCALER_LEDDRV == ON
    InitLEDDriver();
#endif
#if defined(ENABLE_FPGA_MODE)
// Only for special case in FPGA stage
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
      //0x000,0x008,0x00A,0x00F,0x020,0x021,0x023,0x024,       0x025,0x026,0x038,0x196,0x012,0x072,0x1E6
        {0x10, 0x00, 0xF0, 0x00, 0xA1, 0x81, 0x00, 0x80, SCREG_025_A, 0x00, 0x00, 0x20, 0x00, 0x01, 0x01}, //ANALOG_SEP_INPUT0
        {0x10, 0x00, 0xF0, 0x00, 0xA1, 0x81, 0x00, 0x80, SCREG_025_A, 0x80, 0x00, 0x21, 0x00, 0x00, 0x01}, //ANALOG_COM_INPUT0
        {0x18, 0x00, 0xF8, 0x00, 0xA1, 0x01, 0x40, 0x80, SCREG_025_A, 0x80, 0x00, 0x21, 0xE0, 0x10, 0x51}, //ANALOG_SOG_INPUT0
    #if DVI_MODE == DVI_HV_MODE
        {0x10, 0x00, 0xF0, 0x00, 0x83, 0x01, 0x00, 0x82, SCREG_025_D, 0x00, 0x00, 0x90, 0x00, 0x00, 0x01}, //DIGITAL_INPUT0
    #elif DVI_MODE == DVI_DE_MODE
        {0x10, 0x00, 0xF0, 0x00, 0x83, 0x01, 0x00, 0x82, SCREG_025_D, 0x00, 0x00, 0x20, 0x00, 0x00, 0x01}, //DIGITAL_INPUT0
    #elif DVI_MODE == DVI_HVDE_MODE 
        {0x10, 0x00, 0xF0, 0x00, 0x83, 0x01, 0x08, 0x82, SCREG_025_D, 0x00, 0x00, 0x90, 0x00, 0x00, 0x01}, //DIGITAL_INPUT0
    #endif
        {0x10, 0x00, 0xF0, 0x00, 0xA1, 0x81, 0x00, 0x81, SCREG_025_A, 0x00, 0x00, 0x20, 0x00, 0x01, 0x01}, //ANALOG_SEP_INPUT1
        {0x10, 0x00, 0xF0, 0x00, 0xA1, 0x81, 0x00, 0x81, SCREG_025_A, 0x80, 0x00, 0x21, 0x00, 0x00, 0x01}, //ANALOG_COM_INPUT1
        {0x18, 0x00, 0xF8, 0x00, 0xA1, 0x01, 0x40, 0x81, SCREG_025_A, 0x80, 0x00, 0x21, 0xE0, 0x10, 0x51}, //ANALOG_SOG_INPUT1
    #if DVI_MODE == DVI_HV_MODE
        {0x10, 0x00, 0xF0, 0x00, 0x83, 0x01, 0x00, 0x87, SCREG_025_D, 0x00, 0x00, 0x90, 0x00, 0x00, 0x01}, //DIGITAL_INPUT1
    #elif DVI_MODE == DVI_DE_MODE
        {0x10, 0x00, 0xF0, 0x00, 0x83, 0x01, 0x00, 0x87, SCREG_025_D, 0x00, 0x00, 0x20, 0x00, 0x00, 0x01}, //DIGITAL_INPUT1
    #elif DVI_MODE == DVI_HVDE_MODE
        {0x10, 0x00, 0xF0, 0x00, 0x83, 0x01, 0x08, 0x87, SCREG_025_D, 0x00, 0x00, 0x90, 0x00, 0x00, 0x01}, //DIGITAL_INPUT1
    #endif
        {0x18, 0x03, 0xF8, 0x00, 0xA1, 0x01, 0xC0, 0x80, SCREG_025_A, 0x80, 0x00, 0x21, 0xE0, 0x10, 0x51}, //ANALOG_YPBPR_INPUT0
        {0x18, 0x03, 0xF8, 0x00, 0xA1, 0x01, 0xC0, 0x81, SCREG_025_A, 0x80, 0x00, 0x21, 0xE0, 0x10, 0x51}, //ANALOG_YPBPR_INPUT1
    };
    
    UCHAR *p;
    UCHAR i, k, interface_index, tmp;

    ucZpInterface = interface;
    if (IsZpMode()) return;

    PowerUpAllInput();

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
            interface_index = 0;
            break;

        case ANALOG_COM_INPUT0:
            SC_ADC_REG_1D &= ~BIT5;
            SC_GI_SYNC_CTRL3 = 0x42;
            SC_ADC_ZERO_POWER_CTRL |= BIT3;
            interface_index = 1;
            break;

        case ANALOG_SOG_INPUT0:
            SC_ADC_REG_1D |= BIT5;
            SC_GI_SYNC_CTRL3 = 0x42;
            SC_ADC_ZERO_POWER_CTRL |= BIT3;
            SC_CLAMP_BEGIN |= BIT6;
            Sleep(2);
            SC_CLAMP_BEGIN &= ~BIT6;
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
            interface_index = 3;
            break;

        case ANALOG_SEP_INPUT1:
            SC_ADC_REG_1D &= ~BIT5;
            SC_GI_SYNC_CTRL3 = 0x42;
            SC_ADC_ZERO_POWER_CTRL |= BIT3;
            interface_index = 4;
            break;

        case ANALOG_COM_INPUT1:
            SC_ADC_REG_1D &= ~BIT5;
            SC_GI_SYNC_CTRL3 = 0x42;
            SC_ADC_ZERO_POWER_CTRL |= BIT3;
            interface_index = 5;
            break;

        case ANALOG_SOG_INPUT1:
            SC_ADC_REG_1D |= BIT5;
            SC_GI_SYNC_CTRL3 = 0x42;
            SC_ADC_ZERO_POWER_CTRL |= BIT3;
            SC_CLAMP_BEGIN |= BIT6;
            Sleep(2);
            SC_CLAMP_BEGIN &= ~BIT6;
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
            interface_index = 7;
            break;

        case ANALOG_YPBPR_INPUT0:
            SC_ADC_REG_1D |= BIT5;
            SC_GI_SYNC_CTRL3 = 0x42;
            SC_ADC_ZERO_POWER_CTRL |= BIT3;
            SC_CLAMP_BEGIN |= BIT6;
            Sleep(2);
            SC_CLAMP_BEGIN &= ~BIT6;
            interface_index = 8;
            break;

        case ANALOG_YPBPR_INPUT1:
            SC_ADC_REG_1D |= BIT5;
            SC_GI_SYNC_CTRL3 = 0x42;
            SC_ADC_ZERO_POWER_CTRL |= BIT3;
            SC_CLAMP_BEGIN |= BIT6;
            Sleep(2);
            SC_CLAMP_BEGIN &= ~BIT6;
            interface_index = 9;
            break;
    }

    k = (sizeof(interface_tab)/3); //Address is 3 bytes
    for (i=0; i<k; i++) {
        p = interface_tab[i];
        *p = interface_data[interface_index][i];
    }

    Sleep(80);
#if ENABLE_ESD_PROTECT == ON
    ReadESDCheckSum();
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

        case 0x02: //DIGITAL INPUT0
            curr_interface = DIGITAL_INPUT0;
            break;

        case 0x03: //DIGITAL INPUT1
            curr_interface = DIGITAL_INPUT1;
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
        switch(SC_REVISION_ID){
        case 0x01:
            ret = SCID_661;
            break;
        case 0x02:
            ret = SCID_661_B;
            break;
        case 0x03:
            ret = SCID_661_C;
            break;
        default:
            ret = SCID_661_FINAL;
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
        switch(SC_REVISION_ID){
        case 0x01:
            ret = SCID_661;
            break;
        case 0x02:
            ret = SCID_661_B;
            break;
        case 0x03:
            ret = SCID_661_C;
            break;
        default:
            ret = SCID_661_FINAL;
            break;
        }
        break;
    }
    
    return ret;
}
#endif

#if ENABLE_ESD_PROTECT == ON
static bit esdckstatus = 0;
/**************************************************************************//**
 * Get the value of OSD SRAM check sum.
 * @return Value of OSD SRAM check sum.
 ******************************************************************************/
UCHAR ReadOSDCheckSum(void)
{
    SC_ESD_ERROR_CHECKSUM = BIT2;//0x00;//BIT2;
    SC_ESD_CHECKSUM = 0x0F;
    SC_INDEX_CTRL = 0x8C;//for OSD
    while ((SC_ESD_CHECKSUM & 0x0F) != 0) {};
    if ((SC_ESD_CHECKSUM & 0xE0) != 0xE0) {
//        printf("ESD flag %x\r\n", (USHRT)SC_ESD_CHECKSUM);
        while(1){};
    }
    return SC_OSD_CHECKSUM;
}


void ReadESDCheckSum(void)
{
UCHAR checksum[4];
    SC_ESD_ERROR_CHECKSUM = 0x00|BIT2;//0x04;
    SC_ESD_CHECKSUM = 0x0F;//0x0B;//0x0F;//LVDS, DPLL, DISP, OSD
    while ((SC_ESD_CHECKSUM & 0x0F) != 0) {};
    checksum[0] = SC_OSD_CHECKSUM;
    checksum[1] = SC_DISPLAY_CHECKSUM;
    checksum[2] = SC_DPLL_CHECKSUM;
    checksum[3] = SC_LVDS_CHECKSUM;
    SC_ESD_ERROR_CHECKSUM = 0x02|BIT2;
    SC_OSD_CHECKSUM = checksum[0];
    SC_DISPLAY_CHECKSUM = checksum[1];
    SC_DPLL_CHECKSUM = checksum[2];
    SC_LVDS_CHECKSUM = checksum[3];
    SC_ESD_ERROR_CHECKSUM = 0x00|BIT2;//0x04;
}

void ClearESDCKStatus(void)
{
    esdckstatus = 0;
}

#endif
