/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                                 */
/******************************************************************************/

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "Include.h"
#include "Warning.h"

//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************
code UCHAR NoDuplicate[] = {0x55,0xAA,0x66,0x99,'N','O','C','O','P','Y'};
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
#if ENABLE_HDCP_TRIM_MODE == ON || ENABLE_EDID_TRIM_MODE == ON
static USHRT ReadScalerID(void);
#endif
#if ENABLE_ESD_PROTECT == ON
static void ESD_CHECK(void);
#endif
//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// F U N C T I O N   B O D Y S
//******************************************************************************

/**************************************************************************//**
 * The entry point of FALCON.
 * This function will be called by startup.a51.
 ******************************************************************************/

void main(void)
{
    // According to our MCU spec, we must set the type of bank allocation first.
    // Therefore, we set BankSet(0x22) first. (We MUST set it first!)
    BankSet(0x22);
    DisableInterrupt();
#if ENABLE_HDCP_TRIM_MODE == ON || ENABLE_EDID_TRIM_MODE == ON
    ucEFUSE_ID = (UCHAR)(ReadScalerID()>>8);
#endif
    McuInitialize();

#if IS_NT68790_SERIES || IS_NT68810_SERIES || IS_NT68870_SERIES
    ConfigHPD();
#endif
#if (ENABLE_DIGI3_HPD == ON) ||(ENABLE_DIGI2_HPD == ON) ||(ENABLE_DIGI1_HPD == ON) || (ENABLE_DIGI0_HPD == ON) || (ENABLE_DP_HPD == ON) || (ENABLE_DP1_HPD == ON) || (ENABLE_DP2_HPD == ON) || (ENABLE_DP3_HPD == ON)
    SYSAPI_PerformHPDOff(TRUE);// AC off/on set hot plug Pin off(Low)
#endif
    RamInitialize();
    EnableInterrupt();
    ScalerInitialize();
#if 0//ENABLE_USB_TYPE_C == ON
    USBTypeCInit(); // Yung add usb type C
#endif
    NvramLoadData();
    Custom_System_Init();
    APPInitSystem();
#if MCU_UART_OUTPUT != 0    
    printf("Start Program\r\n");
#endif
    //DBGPRN1(PRN_SYS_Flow, "Start Program\r\n");
    while (1) {
        ResetWDTimer();
        ModeHandler();
        EventHandler();
        SYSAPI_CheckSysPower();

{
	
	void Set6502Active(UCHAR phyindex);
		if(SC_ADC_CLAMP_CTRL) // feng-160908   dp-test
			{
			SC_ADC_CLAMP_CTRL =0;
				Set6502Active(_DPPP_PHY0);
			}
}
		
#if ENABLE_ESD_PROTECT == ON
        ESD_CHECK();
#endif
#if (((INPUT_INTERFACE&INPUT_DP)||(INPUT_INTERFACE&INPUT_DP1)||(INPUT_INTERFACE&INPUT_DP2)||(INPUT_INTERFACE&INPUT_DP3))  && ENABLE_DP_AUX_MONITOR==ON)   	
       DP_Aux_Channel_Monitor();    
#endif   
    }
}

#if ENABLE_HDCP_TRIM_MODE == ON || ENABLE_EDID_TRIM_MODE == ON
//NT68850=0x0B
//NT68770=0x0C
//NT68655=0x0D
USHRT ReadScalerID(void)
{ 
USHRT scaler_id = 0x0000;
UCHAR tmp_0xF04C, tmp_0x8D55, tmp_0x8D50, tmp_0x8101, tmp_0x8102, tmp_0x8641;
//12MHz
    SC_ADC_ZERO_POWER_CTRL |= 0x81;// 0xb57
    tmp_0xF04C = CPU_CLK;
    CPU_CLK = 0x10;
    tmp_0x8101 = SC_POWER_CTRL1;
    SC_POWER_CTRL1 = 0x00;
    tmp_0x8102 = SC_POWER_CTRL2;// 0x102
    SC_POWER_CTRL2 |= BIT1;// 0x102
    tmp_0x8641 = SC_HDCP_INPUT_CTRL;// 0x641
#if IS_NT68790_SERIES_EARLIER
    SC_HDCP_INPUT_CTRL |= BIT7;// 0x641
#endif
//
    tmp_0x8D55 = SC_HDCP_TRIM_CTRL2; // 0xd55
#if defined(ENABLE_FPGA_MODE)
    SC_HDCP_TRIM_CTRL2 |= BIT6; // 0xd55
#else
    SC_HDCP_TRIM_CTRL2 &= ~BIT6; // 0xd55
#endif
// 
    tmp_0x8D50 = SC_HDCP_TRIM_CTRL;// 0xd50
    SC_HDCP_TRIM_CTRL |= BIT0;// 0xd50
    SC_HDCP_TRIM_CTRL &= ~BIT1;// 0xd50
#if IS_NT68810_SERIES || IS_NT68870_SERIES    
    SC_HDCP_TRIM_CTRL |= BIT2; // 0xd50
    SC_HDCP_TRIM_TEST_MODE |= BIT7;// 0xd58
    SC_HDCP_TRIM_PI |= BIT0;// 0xd5f
#endif

//read scaler id
#if IS_NT68810_SERIES || IS_NT68870_SERIES  
    SC_HDCP_TRIM_ADDR_B = 0x00;// 0xd5c
    SC_HDCP_TRIM_ADDR_A = 0x91;// 0xd5b
    SC_HDCP_TRIM_ADDR_B = 0x20; // read pulse// 0xd5c
    SC_HDCP_TRIM_ADDR_B = 0x00;// 0xd5c
#else
//address
    SC_HDCP_TRIM_ADDR = 0x91;// 0xd51
//read enable
    SC_HDCP_TRIM_CTRL |= BIT6;// 0xd50
#endif

#if IS_NT68810_SERIES || IS_NT68870_SERIES 
//read data hi
    scaler_id = SC_HDCP_TRIM_DATA_HI;  // 0xd53
    scaler_id <<= 8;
//read data lo
    scaler_id |= SC_HDCP_TRIM_DATA_LO;// 0xd52
#else
//read data hi
    scaler_id = SC_HDCP_TRIM_DATA_HI;// 0xd53
    scaler_id <<= 8;
//read data lo
    if((SC_HDCP_TRIM_DATA_LO & 0x0F) == 0x0F) {// 0xd52
        scaler_id |= (SC_HDCP_TRIM_DATA_LO>>4);// 0xd52
    }
    else {
        scaler_id |= SC_HDCP_TRIM_DATA_LO;// 0xd52
    }
#endif
    
#if IS_NT68810_SERIES || IS_NT68870_SERIES  
    //efuse mapping LED curr and OVP, need before LED drivier enable
    SC_HDCP_TRIM_ADDR_B = 0x00;// 0xd5c
    SC_HDCP_TRIM_ADDR_A = 0x90; // addr for LED_CURR and LED_OVP   // 0xd5b
    SC_HDCP_TRIM_ADDR_B = 0x20; // read pulse// 0xd5c
    SC_HDCP_TRIM_ADDR_B = 0x00;// 0xd5c
    ucLEDTRIM_HI = SC_HDCP_TRIM_DATA_HI;// 0xd53
    ucLEDTRIM_LO = SC_HDCP_TRIM_DATA_LO; // 0xd52

    //efuse mapping ADC07, need before internal 0.7V enable
    SC_HDCP_TRIM_ADDR_B = 0x00;// 0xd5c
    SC_HDCP_TRIM_ADDR_A = 0x92; // addr for ADC07   // 0xd5b
    SC_HDCP_TRIM_ADDR_B = 0x20; // read pulse// 0xd5c
    SC_HDCP_TRIM_ADDR_B = 0x00;// 0xd5c
    ucADCTRIM_SEL = SC_HDCP_TRIM_DATA_HI;// 0xd53
    ucADCTRIM = SC_HDCP_TRIM_DATA_LO; // 0xd52

    LoadDefaultTrim();
#endif  
    
    SC_HDCP_TRIM_CTRL = tmp_0x8D50;// 0xd50
    SC_HDCP_TRIM_CTRL2 = tmp_0x8D55; // 0xd55
    CPU_CLK = tmp_0xF04C;
    SC_HDCP_INPUT_CTRL = tmp_0x8641;// 0x641
    SC_POWER_CTRL1 = tmp_0x8101;
    SC_POWER_CTRL2 = tmp_0x8102;// 0x102
    return scaler_id; 
} 
#endif

#if ENABLE_ESD_PROTECT == ON
void ESD_CHECK(void)
{
    static UCHAR ucPreOSDRAMCheckSum;
    UCHAR ucNowOSDRAMCheckSum;
    if (IsBackLightOn() == TRUE) {
        if (SC_INDEX_CTRL != 0x8C) {// read OSD SRAM
            ucNowOSDRAMCheckSum = ReadOSDCheckSum();
            ucPreOSDRAMCheckSum = ucNowOSDRAMCheckSum;
//            printf("OSDRAMCheckSumN1=%x\r\n", (USHRT)ucNowOSDRAMCheckSum);
        }
        else {
            ucNowOSDRAMCheckSum = ReadOSDCheckSum();
//            printf("OSDRAMCheckSumN2=%x\r\n", (USHRT)ucNowOSDRAMCheckSum);
            if (ucPreOSDRAMCheckSum != ucNowOSDRAMCheckSum) {
//                printf("ucPreOSDRAMCheckSum=%x\r\n", (USHRT)ucPreOSDRAMCheckSum);
//                printf("ucNowOSDRAMCheckSum=%x\r\n", (USHRT)ucNowOSDRAMCheckSum);
                ucPreOSDRAMCheckSum = ucNowOSDRAMCheckSum;
                //Error////////////////////////////////////////////
                while(1){};
                ///////////////////////////////////////////////////
            }
        }

    }
    else {
        ClearESDCKStatus();
    }
#if 1
    CLR_WDT2 = 0x55;
    WDT2_SEL = WDT2SELECT;
#endif
}
#endif
