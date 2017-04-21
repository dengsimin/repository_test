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
#include "Scaler_DP_6502.h"

#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1) || (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************

//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************
static xdata UCHAR ucPowerState = 0;
static code UCHAR MCU_CLK[9] = CPU_CLK_TABLE;
static xdata USHRT usDPTimer = 0;
static BOOL bAudioMNChecking = FALSE;
#if EN_AUX_STROBE_FUNC == ON
xdata UCHAR bDP_AUX_DETECT = 0;
#endif

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************
#if DP_DDC_CHANNEL == 0x00 || DP1_DDC_CHANNEL == 0x00
//    xdata UCHAR volatile EDID_SRAM_DP[256] _at_ 0xF800;
    #define EDID_SRAM_DP EDID_SRAM_BUFF0
    #define DP_DDC_PORT    DDC_CTL0
    #define DP_IIC_MASK    0x0E
#elif DP_DDC_CHANNEL == 0x01 || DP1_DDC_CHANNEL == 0x01
//    xdata UCHAR volatile EDID_SRAM_DP[256] _at_ 0xF900;
    #define EDID_SRAM_DP EDID_SRAM_BUFF1
    #define DP_DDC_PORT    DDC_CTL1
    #define DP_IIC_MASK    0x0D
#elif DP_DDC_CHANNEL == 0x02 || DP1_DDC_CHANNEL == 0x02
//    xdata UCHAR volatile EDID_SRAM_DP[256] _at_ 0xFA00;
    #define EDID_SRAM_DP EDID_SRAM_BUFF2
    #define DP_DDC_PORT    DDC_CTL2
    #define DP_IIC_MASK    0x0B
#elif DP_DDC_CHANNEL == 0x03 || DP1_DDC_CHANNEL == 0x03
//    xdata UCHAR volatile EDID_SRAM_DP[256] _at_ 0xFB00;
    #define EDID_SRAM_DP EDID_SRAM_BUFF3
    #define DP_DDC_PORT    DDC_CTL3
    #define DP_IIC_MASK    0x07
#endif

#if ENABLE_DEMO_DP_EDID == ON
static code UCHAR EDID_Tbl[]={
#if ENABLE_FREESYNC_DEMO == ON
// Yung:20150909 copy form TPV EDID for freesync use 
// 0x18[0] set1  
// Monitor range at block#3 min V is 40 or 50Hz,max V is 76Hz  and Min Max H freq is 83K PCLK=170MHz modify domain pixel clk to 170MHz
0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x05,0xE3,0x77,0x27,0xB5,0x69,0x0F,0x00,// 0
0x22,0x17,0x01,0x04,0xA5,0x3C,0x22,0x78,0x3B,0x48,0x11,0xA7,0x56,0x52,0x9C,0x27,// 1
0x0F,0x50,0x54,0xBF,0xEF,0x00,0xD1,0xC0,0xB3,0x00,0x95,0x00,0x81,0x80,0x81,0x40,// 2
0x81,0xC0,0x01,0x01,0x01,0x01,0x68,0x42,0x80,0x18,0x71,0x38,0x2D,0x40,0x58,0x2C,// 3
0x45,0x00,0x56,0x50,0x21,0x00,0x00,0x1E,0x00,0x00,0x00,0xFD,0x00,0x28,0x4C,0x53,// 4 0x28/0x32 40Hz~76Hz  50Hz~76Hz
0x53,0x11,0x01,0x0A,0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x00,0x00,0xFC,0x00,0x32,// 5
0x37,0x37,0x37,0x4D,0x0A,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x00,0x00,0xFF,// 6
0x00,0x31,0x33,0x32,0x32,0x31,0x33,0x31,0x32,0x33,0x31,0x32,0x33,0x33,0x01,0x25,// 7
0x02,0x03,0x1E,0xF1,0x4B,0x90,0x1F,0x05,0x14,0x04,0x13,0x03,0x12,0x02,0x11,0x01,
0x23,0x09,0x07,0x07,0x83,0x01,0x00,0x00,0x65,0x03,0x0C,0x00,0x10,0x00,0x8C,0x0A,
0xD0,0x8A,0x20,0xE0,0x2D,0x10,0x10,0x3E,0x96,0x00,0x56,0x50,0x21,0x00,0x00,0x18,
0x01,0x1D,0x00,0x72,0x51,0xD0,0x1E,0x20,0x6E,0x28,0x55,0x00,0x56,0x50,0x21,0x00,
0x00,0x1E,0x8C,0x0A,0xD0,0x8A,0x20,0xE0,0x2D,0x10,0x10,0x3E,0x96,0x00,0x56,0x50,
0x21,0x00,0x00,0x18,0x8C,0x0A,0xD0,0x90,0x20,0x40,0x31,0x20,0x0C,0x40,0x55,0x00,
0x56,0x50,0x21,0x00,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x91,
#else
#if 0 //FHD
0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x3A, 0xD4, 0x9C, 0x07, 0x00, 0x00, 0x00, 0x00,
0x03, 0x15, 0x01, 0x04, 0xB5, 0x33, 0x1D, 0x78, 0xFA, 0x60, 0x85, 0xA6, 0x56, 0x4A, 0x9C, 0x25,
0x12, 0x50, 0x54, 0x21, 0x48, 0x00, 0x81, 0x00, 0x81, 0x40, 0x81, 0x80, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x3A, 0x80, 0x18, 0x71, 0x38, 0x2D, 0x40, 0x58, 0x2C,
0x45, 0x00, 0xDD, 0x0C, 0x11, 0x00, 0x00, 0x1A, 0x00, 0x00, 0x00, 0xFD, 0x00, 0x18, 0x78, 0x1A,
0x8C, 0x1E, 0x00, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0xF7, 0x00, 0x0A,
0x00, 0xCA, 0x84, 0x64, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC,
0x00, 0x4E, 0x4F, 0x56, 0x41, 0x54, 0x45, 0x4B, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x01, 0xF4,
0x02, 0x03, 0x13, 0xF0, 0x83, 0x01, 0x00, 0x00, 0x23, 0x09, 0x07, 0x07, 0x46, 0x90, 0x1F, 0x03,
0x12, 0x14, 0x05, 0x02, 0x3A, 0x80, 0x18, 0x71, 0x38, 0x2D, 0x40, 0x58, 0x2C, 0x45, 0x00, 0xDD,
0x0C, 0x11, 0x00, 0x00, 0x1A, 0x8C, 0x0A, 0xD0, 0x8A, 0x20, 0xE0, 0x2D, 0x10, 0x10, 0x3E, 0x96,
0x00, 0xDD, 0x0C, 0x11, 0x00, 0x00, 0x18, 0x8C, 0x0A, 0xD0, 0x90, 0x20, 0x40, 0x31, 0x20, 0x0C,
0x40, 0x55, 0x00, 0xDD, 0x0C, 0x11, 0x00, 0x00, 0x18, 0x02, 0x3A, 0x80, 0xD0, 0x72, 0x38, 0x2D,
0x40, 0x10, 0x2C, 0x45, 0x80, 0xDD, 0x0C, 0x11, 0x00, 0x00, 0x1A, 0x01, 0x1D, 0x80, 0xD0, 0x72,
0x1C, 0x16, 0x20, 0x2C, 0x10, 0x25, 0x20, 0xDD, 0x0C, 0x11, 0x00, 0x00, 0x9E, 0x01, 0x1D, 0x80,
0x18, 0x71, 0x1C, 0x16, 0x20, 0x58, 0x2C, 0x25, 0x00, 0xDD, 0x0C, 0x11, 0x00, 0x00, 0x9E, 0x16,
#endif
#if 1 
//BENQ 3206
0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,

0x09,0xD1,0x44,0x7B,0x01,0x00,0x00,0x00,

0x2A,0x1A,0x01,0x04,0xB5,0x46,0x27,0x78,

0x3A,0x1D,0xF5,0xAE,0x4F,0x35,0xB3,0x25,

0x0D,0x50,0x54,0xBF,0xEF,0x80,0x81,0x00,

0xB3,0x00,0xD1,0x00,0x71,0x4F,0xA9,0x40,

0x81,0x80,0xD1,0xC0,0x01,0x01,0x56,0x5E,

0x00,0xA0,0xA0,0xA0,0x29,0x50,0x30,0x20,

0x35,0x00,0x55,0x50,0x21,0x00,0x00,0x1E,

0x00,0x00,0x00,0xFF,0x00,0x43,0x36,0x46,

0x30,0x4B,0x33,0x43,0x4E,0x30,0x37,0x55,

0x4C,0x0A,0x00,0x00,0x00,0xFC,0x00,0x56,

0x57,0x33,0x32,0x30,0x36,0x51,0x0A,0x20,

0x20,0x20,0x20,0x20,0x00,0x00,0x00,0xFD,

0x00,0x31,0x4B,0x1D,0x71,0x04,0x00,0x0A,

0x20,0x20,0x20,0x20,0x20,0x20,0x01,0x48,

0x02,0x03,0x1D,0xF1,0x50,0x90,0x05,0x04,

0x03,0x02,0x07,0x16,0x01,0x06,0x11,0x12,

0x15,0x13,0x14,0x1F,0x20,0x23,0x09,0x1F,

0x07,0x83,0x01,0x00,0x00,0x02,0x3A,0x80,

0x18,0x71,0x38,0x2D,0x40,0x58,0x2C,0x45,

0x00,0x55,0x50,0x21,0x00,0x00,0x1E,0x01,

0x1D,0x80,0x18,0x71,0x1C,0x16,0x20,0x58,

0x2C,0x25,0x00,0x55,0x50,0x21,0x00,0x00,

0x9E,0x01,0x1D,0x00,0x72,0x51,0xD0,0x1E,

0x20,0x6E,0x28,0x55,0x00,0x55,0x50,0x21,

0x00,0x00,0x1E,0x8C,0x0A,0xD0,0x8A,0x20,

0xE0,0x2D,0x10,0x10,0x3E,0x96,0x00,0x55,

0x50,0x21,0x00,0x00,0x18,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x9D,






        
#endif
#endif
};
#endif

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
#if defined(ENABLE_FPGA_MODE)
void WriteScaler(USHRT waddr, UCHAR wdata)
{
    UCHAR volatile xdata *paddr;
    paddr = 0x8000+waddr;
    *paddr = wdata;
}

UCHAR ReadScaler(USHRT waddr)
{
    UCHAR volatile xdata *paddr;
    paddr = 0x8000+waddr;
    return *paddr;
}
#endif

//******************************************************************************
// Prototype: 
//  void DPInit(UCHAR phyindex)
// Parameters:
//
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
void DPInit(UCHAR phyindex)
{
//    DBGPRN1(PRN_DP_Flow, "DPInitial\r\n");

// DP reference clock select
#if IS_NT68810_SERIES
    SC_TMDS_LINK_CLK_SEL = SCREG_1E7 | BIT0;  // dp_refclk select
#else //NT68870
    SC_DP_LINK_CLK_SEL &= ~(BIT4|BIT3); // NT68870 0x1E7[4:3] move to 0x1EA[4:3]=00  // 0x1ea
#endif
    SC_DP_102F = REF_CLK*4/1000000;  // if 0x1E7[4:3] = 2'b00, dp_refclk = OSC clock*4

#if IS_NT68790_SERIES || IS_NT68810_SERIES || IS_NT68870_SERIES
    SC_CBUS_CHANNEL_SEL = 0x01;//DP2      0x15f0
    SC_18V_LDO_CONTROL = 0x41;  // 0x12e1
#endif

#if !IS_NT68790_SERIES//DC2DC
    DP_PowerOn();
#endif
    DPConfigAUXDetect();

#if ENABLE_DEMO_DP_EDID == ON
    {
        USHRT i;
        bit diff;
        // Init EDID data
        diff = FALSE;
        for (i=0; i<256; i++) {
            if ((EDID_SRAM_DP[i] != EDID_Tbl[i]) && (i < 8)) {//check head
                diff = TRUE;
                EDID_SRAM_DP[i] = EDID_Tbl[i];
            }
            else if ((i > 7) && (diff == TRUE)) {//copy
                EDID_SRAM_DP[i] = EDID_Tbl[i];
            }
        }
    }
#endif

#if EN_AUX_STROBE_FUNC == ON
	INTSC_EN |= BIT1;		// DP_EN	
	AUX_STROBE_CTL = (DP_AUX_STROBE_EN|DP_AUX_STROBE_RST|DP_AUX_STROBE_INT_EN);	// AUX strobe enable, interrupt enable
	AUX_STROBE_CTL = (DP_AUX_STROBE_EN|DP_AUX_STROBE_INT_EN|DP_AUX_STROBE_MASK_RX);//0x1d;	// clear AUX strobe interrupt
	AUX_I2C_MANUAL = (AUX_I2C_MODE);		// enable I2C-over-AUX to manual mode// 0x1024
	SC_DP_RESET_FUNCTION |= DP_AUX_RST;
	SC_DP_RESET_FUNCTION &= ~DP_AUX_RST;
	#if 1
	DP_SC_REG_1224 |= (MASK_NATIVE_AUX);
	SC_DP_AUX_CTRL2 |= (DP_AUX_INTR_SEL);
	#endif
    SC_DP_10F4 = 0xA0;
#else
#if (ENABLE_DP_AUX_MONITOR==OFF)
	INTSC_EN &= ~BIT1;  // 0xf024
	AUX_STROBE_CTL = 0x00;  // 0x10f7
#if (INPUT_INTERFACE&INPUT_DP) && ENABLE_USB_TYPE_C == OFF
#if (ENABLE_DEMO_DP_EDID == ON) || ((USE_INTERNAL_EDID == 1) && (DP_DDC_CHANNEL != 0xFF))
    DP_DDC_PORT |= BIT7;//DDC_CTL1 |= BIT7;
    IIC_MASK_CTRL = DP_IIC_MASK;//0x0D;   // 0xf06a
    DP_CTRL = (DP_DDC_CHANNEL << 2) | BIT1;// | BIT0;//0x06;    // 0xF0d2
#if IS_NT68790_SERIES || IS_NT68810_SERIES
    DP_I2C_PADS_EN = BIT4 | (BIT0 << DP_DDC_CHANNEL);  // 0xf0Ce
#else //IS_NT68870_SERIES
    DP_I2C_PADS_EN = BIT5 | (BIT0 << DP_DDC_CHANNEL);// 0xf0Ce
#endif
#else
    IIC_MASK_CTRL = DP_IIC_MASK;//0x0D; // 0xf06a
    DP_CTRL = (DP_DDC_CHANNEL << 2) | BIT1 | BIT0;//0x06;// 0xF0d2
#endif
#endif

#if (INPUT_INTERFACE&INPUT_DP1) && (!(INPUT_INTERFACE&INPUT_DP) || ENABLE_USB_TYPE_C == ON)
#if (ENABLE_DEMO_DP_EDID == ON) || ((USE_INTERNAL_EDID == 1) && (DP1_DDC_CHANNEL != 0xFF))
    DP_DDC_PORT |= BIT7;//DDC_CTL1 |= BIT7;
    IIC_MASK_CTRL = DP_IIC_MASK;//0x0D; // 0xf06a
    DP_CTRL = (DP1_DDC_CHANNEL << 2) | BIT1;// | BIT0;//0x06;// 0xF0d2
#if IS_NT68790_SERIES || IS_NT68810_SERIES
    DP_I2C_PADS_EN = BIT4 | (BIT0 << DP1_DDC_CHANNEL);// 0xf0Ce
#else //IS_NT68870_SERIES
    DP_I2C_PADS_EN = BIT5 | (BIT0 << DP1_DDC_CHANNEL);// 0xf0Ce
#endif
#else
    IIC_MASK_CTRL = DP_IIC_MASK;//0x0D;// 0xf06a
    DP_CTRL = (DP1_DDC_CHANNEL << 2) | BIT1 | BIT0;//0x06;;// 0xF0d2
#endif
#endif


#endif    
#endif

#if ENABLE_FREESYNC_DEMO == ON
    // 20160202 Yung Add for DP AMD free-sync use
    SC_DP_HV_MISC_CTRL &= 0x7F; // bit7 Disable mask HSync   // 0x104d
#endif


    DP_ConfigAUX2IICSpeed();

    SC_DP_M_LSB_CROSS_TH = 0xF0; // Fix Mvid byte0 0x00/0xFF issue   // 0x10bc
    SC_DP_1039 |= BIT3;	// improve image broken when timing change
    SC_DP_VIDEO_FIFO_MODE4_ADAPTIVE_CTRL &= ~BIT5;   // 0x1003
#if ENABLE_EDP == ON
    SC_DP_1043 |= BIT4;
#endif
    if(IsDPTrainingDone() == FALSE){
        Load6502ROM(phyindex);
        DP_InitPHY(phyindex);
        DP_InitDPCD();//DP TrainingDone don't do it

        SC_DP_AUX_CTRL = 0x31; // AUX    // 0x10b8

        DP_InitDPConfigPage();
#if defined(ENABLE_FPGA_MODE)
        DP_InitDPPHYTC151(); // FPGA DP APHY daught board		
#endif
    }
}

#if defined(ENABLE_FPGA_MODE)
//******************************************************************************
// Prototype:
//  void DP_InitDPPHYTC151()
// Parameters:
//
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
void DP_InitDPPHYTC151(void)
{
    UCHAR dd[3];
    UCHAR d;

    // DP_PHY_ADDR=0xB0

    // Reset audio mPLL  Yung: Must run audio mPLL reset first
    FpgaReadIICSeq(DP_PHY_ADDR, 0x25, 1, &d);
    d &= 0xbf; // 1011_1111
    FpgaWriteIICSeq(DP_PHY_ADDR, 0x25, 1, &d);

    // Power down H_POW_DP 0 1 2 3
    dd[0] = 0x77;
    dd[1] = 0x77;
    FpgaWriteIICSeq(DP_PHY_ADDR, 0xA6, 2, dd);

    // Power down FRCDR chanel 2&3
    dd[0] = 0x7c;
    dd[1] = 0x7c;
    FpgaWriteIICSeq(DP_PHY_ADDR, 0x9C, 2, dd);

    // Initial audio mPLL (it is must be write before video).
    FpgaReadIICSeq(DP_PHY_ADDR, 0x25, 1, &d);
    d |= 0x40;
    FpgaWriteIICSeq(DP_PHY_ADDR, 0x25, 1, &d);
    dd[0] = 0x1F;
    dd[1] = 0x11;
    dd[2] = 0x00;
    FpgaWriteIICSeq(DP_PHY_ADDR, 0x70, 3, dd);
    dd[0] = 0x00;
    dd[1] = 0x80;
    dd[2] = 0x00;
    FpgaWriteIICSeq(DP_PHY_ADDR, 0x73, 3, dd);

    // Initial video mPLL
    FpgaReadIICSeq(DP_PHY_ADDR, 0x21, 1, &d);
    d |= 0x40;
    FpgaWriteIICSeq(DP_PHY_ADDR, 0x21, 1, &d);
    dd[0] = 0x1F;
    dd[1] = 0x9B;
    dd[2] = 0x00;
    FpgaWriteIICSeq(DP_PHY_ADDR, 0x60, 3, dd);
    dd[0] = 0x00;
    dd[1] = 0x80;
    dd[2] = 0x00;
    FpgaWriteIICSeq(DP_PHY_ADDR, 0x63, 3, dd);

    // Enhance DP PHY clock driving ability
#if DP_LINKRATE == DP_162G// 1.62 Gbps
    d = 0x8A;  // 1.62G use
#elif DP_LINKRATE == DP_270G// 2.7 Gbps
    d = 0x82;  // 2.7G use
#else // 5.4 Gbps
    d = 0x82;  // 5.4G use
#endif
    FpgaWriteIICSeq(DP_PHY_ADDR, 0xB1, 1, &d);

    // Reset video mPLL
    FpgaReadIICSeq(DP_PHY_ADDR, 0x21, 1, &d);
    d &= 0xbf;
    FpgaWriteIICSeq(DP_PHY_ADDR, 0x21, 1, &d);

    // rst_cnt
    d = 0x04;
    FpgaWriteIICSeq(DP_PHY_ADDR, 0x00, 1, &d);
    d = 0x00;
    FpgaWriteIICSeq(DP_PHY_ADDR, 0x00, 1, &d);

    // Justin recommand
    d = 0xdc;
    FpgaWriteIICSeq(DP_PHY_ADDR, 0x9A, 1, &d);
    FpgaWriteIICSeq(DP_PHY_ADDR, 0x9B, 1, &d);

    d = 0x3F;
    FpgaWriteIICSeq(DP_PHY_ADDR, 0x3F, 1, &d);    //Yung+


    /////////////////////////////////////////////////////
    //
    //  Enable 2nd FPGA DP BLock for 4-lane
    //
    if ( DP_LANECNT == DP_4LANE ) {
        SetIICIndex(2);
        FpgaReadIICSeq(DP_PHY_ADDR, 0x25, 1, &d);
        d &= 0xbf; // 1011_1111
        FpgaWriteIICSeq(DP_PHY_ADDR, 0x25, 1, &d);

        // Power down H_POW_DP 0 1 2 3
        dd[0] = 0x77;
        dd[1] = 0x77;
        FpgaWriteIICSeq(DP_PHY_ADDR, 0xA6, 2, dd);

        // Power down FRCDR chanel 2&3
        dd[0] = 0x7c;
        dd[1] = 0x7c;
        FpgaWriteIICSeq(DP_PHY_ADDR, 0x9C, 2, dd);

        // Initial audio mPLL (it is must be write before video).
        FpgaReadIICSeq(DP_PHY_ADDR, 0x25, 1, &d);
        d |= 0x40;
        FpgaWriteIICSeq(DP_PHY_ADDR, 0x25, 1, &d);
        dd[0] = 0x1F;
        dd[1] = 0x11;
        dd[2] = 0x00;
        FpgaWriteIICSeq(DP_PHY_ADDR, 0x70, 3, dd);
        dd[0] = 0x00;
        dd[1] = 0x80;
        dd[2] = 0x00;
        FpgaWriteIICSeq(DP_PHY_ADDR, 0x73, 3, dd);

        // Initial video mPLL
        FpgaReadIICSeq(DP_PHY_ADDR, 0x21, 1, &d);
        d |= 0x40;
        FpgaWriteIICSeq(DP_PHY_ADDR, 0x21, 1, &d);
        dd[0] = 0x1F;
        dd[1] = 0x9B;
        dd[2] = 0x00;
        FpgaWriteIICSeq(DP_PHY_ADDR, 0x60, 3, dd);
        dd[0] = 0x00;
        dd[1] = 0x80;
        dd[2] = 0x00;
        FpgaWriteIICSeq(DP_PHY_ADDR, 0x63, 3, dd);

        // Enhance DP PHY clock driving ability
#if DP_LINKRATE == DP_162G// 1.62 Gbps
        d = 0x8A;  // 1.62G use
#elif DP_LINKRATE == DP_270G// 2.7 Gbps
        d = 0x82;  // 2.7G use
#else // 5.4 Gbps
        d = 0x82;  // 5.4G use
#endif
        FpgaWriteIICSeq(DP_PHY_ADDR, 0xB1, 1, &d);

        // Reset video mPLL
        FpgaReadIICSeq(DP_PHY_ADDR, 0x21, 1, &d);
        d &= 0xbf;
        FpgaWriteIICSeq(DP_PHY_ADDR, 0x21, 1, &d);

        // rst_cnt
        d = 0x04;
        FpgaWriteIICSeq(DP_PHY_ADDR, 0x00, 1, &d);
        d = 0x00;
        FpgaWriteIICSeq(DP_PHY_ADDR, 0x00, 1, &d);

        // Justin recommand
        d = 0xdc;
        FpgaWriteIICSeq(DP_PHY_ADDR, 0x9A, 1, &d);
        FpgaWriteIICSeq(DP_PHY_ADDR, 0x9B, 1, &d);
        SetIICIndex(1);
    }

#if 0
    {
        USHRT i;
        UCHAR rdtest[0xf0];

        FpgaReadIICSeq(DP_PHY_ADDR, 0x00, 0xf0, rdtest);
        for (i = 0; i < 0xf0; i++ ) {
            printf("%02X ", (USHRT)rdtest[i]);
            if ( (i & 0x0f) == 0x0f ) {
                printf("\r\n");
            }
        }
    }
#endif
}
#endif
//******************************************************************************
// Prototype: 
//  void DP_PowerOn(void)
// Parameters:
//
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
void DP_PowerOn(void)
{
    DP_CLKOn();
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1)
    DPPHY_PowerOn(_DPPP_PHY0);
#endif
    
#if IS_NT68870_SERIES
#if (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
    DPPHY_PowerOn(_DPPP_PHY1);
#endif
#endif
}

//******************************************************************************
// Prototype: 
//  void DP_PowerOFF()
// Parameters:
//
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
void DP_PowerOFF(void)
{
    DP_CLKOff();
    DPPHY_PowerOff();
}

//******************************************************************************
// Prototype: 
//  void GetDPInputHDEImmediate()
// Parameters:
//
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
USHRT GetDPInputHDEImmediate(void)
{
    return (SC_DP_1089<<8)+(SC_DP_108A);
}

//******************************************************************************
// Prototype: 
//  void GetDPInputVDEImmediate()
// Parameters:
//
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
USHRT GetDPInputVDEImmediate(void)
{
    return (SC_DP_108B<<8)+(SC_DP_108C);
}

//******************************************************************************
// Prototype: 
//  void DP_GetClock()
// Parameters:
//
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
USHRT DP_GetClock(void)
{
#if 0
#if REF_CLK==12000000
    if ((SC_DP_10F2 & BIT6) != 0) {
        return SC_DP_10F5;
    }
#else
#define OSC_FREQ_RATIO ((float)REF_CLK/12000000)
    if ((SC_DP_10F2 & BIT6) != 0) {
        return (USHRT)(SC_DP_10F5*OSC_FREQ_RATIO);
    }
#undef OSC_FREQ_RATIO
#endif
    return 0;
#else
#define DP162M 162000000
#define DP270M 270000000
#define DP540M 540000000

    xdata ULONG M, N, ulDPClock;

    M = SC_DP_PLL_M_VID_HI; // 0x1082
    M <<= 8;
    M |= SC_DP_PLL_M_VID_MI; // 0x1083
    M <<= 8;
    M |= SC_DP_PLL_M_VID_LO; // 0x1084

    N = SC_DP_PLL_N_VID_HI; // 0x1085
    N <<= 8;
    N |= SC_DP_PLL_N_VID_MI; // 0x1086
    N <<= 8;
    N |= SC_DP_PLL_N_VID_LO; // 0x1087

    switch (SC_DP_MISC_CTRL&0x03) { // 0x1080
    case 0:
        ulDPClock = (double)DP162M*M/N;
        break;
    case 1:
        ulDPClock = (double)DP270M*M/N;
        break;
    case 2:
        ulDPClock = (double)DP540M*M/N;
        break;
    }
    //printf("M = %ld, N = %ld, DPCLK = %ld\r\n",M,N,ulDPClock);
    return (USHRT)(ulDPClock/1000000);
#endif
}

#if 0
//******************************************************************************
// Prototype: 
//  void DPSetPowerState()
// Parameters:
//
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
void DPSetPowerState(void)
{
    SC_DP_DEBUG = 0x80; //0x1030 enable I2C write DPCD page
    ucPowerState = SC_DP_DPCD_00600;
    SC_DP_DEBUG = 0x00; //0x1030 disable I2C write DPCD page
}

//******************************************************************************
// Prototype: 
//  void DPGetPowerState()
// Parameters:
//
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
UCHAR DPGetPowerState(void)
{
    return ucPowerState;
}
#endif
//******************************************************************************
// Prototype: 
//  void DPConfigAUXDetect()
// Parameters:
//
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
void DPConfigAUXDetect(void)
{
    BOOL bEnAUXInt=0;
    float fRatio;
    fRatio = (float)MCU_CLK[MCU_CLK_TIMES]/12;
    if (IsZpMode()) {
        SC_DP_AUX_PULSEWIDTH_LO_THD = 0x01; // 0x101b
        SC_DP_AUX_PULSEWIDTH_HI_THD = 0x05;// 0x101c
#if 1
        if ((UserData.bAutoSyncSource == TRUE)
         ||((UserData.bAutoSyncSource == FALSE) && ((GetCurrInputInterface()==DISPLAY_PORT_INPUT) || (GetCurrInputInterface()==DISPLAY_PORT_INPUT1)))
         ) {
            SC_DP_AUX_PRECHARGE_NUM = 0x06 | BIT7; // Enable DP AUX detect interrupt  // 0x101d
            bEnAUXInt = 1;
        }
        else
#endif
        {
            SC_DP_AUX_PRECHARGE_NUM = 0x06;// 0x101d
            bEnAUXInt = 0;
        }
    }
    else {
        SC_DP_AUX_PULSEWIDTH_LO_THD = 0x09 * fRatio;// 0x101b
        SC_DP_AUX_PULSEWIDTH_HI_THD = 0x0F * fRatio;// 0x101c
        SC_DP_AUX_PRECHARGE_NUM = 0x09;// 0x101d
        bEnAUXInt = 0;
    }
    if (IsDPAUXDetect()) {
        ClearDPAUXDetect();
    }
    
    if(bEnAUXInt){
        INTSC_EN |= BIT1; // 0xf024
    }
    else{
        INTSC_EN &= ~BIT1;// 0xf024
    }
    
    SC_DP_AUX_DETECT = 0x01; //DP_AUX_DET_EN & pre_charge_reach  // 0x101a
}

//******************************************************************************
// Prototype: 
//  void DPConfigFIFO()
// Parameters:
//
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
void DPConfigFIFO(void)
{
#if IS_NT68850_SERIES
    USHRT VBlankCNT;
#endif
#if 0
    SC_DP_DE_START_POS = GetDPInputHDEImmediate() / 16; //24;
#else
//    USHRT tmp;
    SC_DP_TEST_FIFO_MAX_LENGTH = 0x13;//SC_DP_TEST_FIFO_MAX_LENGTH &= ~BIT6; // DP FIFO pixel mode  // 0x1045
    SC_DP_DE_START_POS = GetDPInputHDEImmediate() / 16; //24; // 0x1047
    if ((SC_DP_VIDEO_CONTROL & BIT2) != 0) {
        Sleep(1);
        SC_DP_DE_START_POS = ReadShortScaler(&SC_DP_DE_IN_COUNT_POS_LO) / 8;// 0x1047
        SC_DP_TEST_FIFO_MAX_LENGTH = 0x53;//SC_DP_TEST_FIFO_MAX_LENGTH |= BIT6; // DP FIFO symbol mode // 0x1045
    }
#endif

#if IS_NT68850_SERIES
    VBlankCNT = GetDigInputVTotalImmediate() - GetDPInputVDEImmediate() + 2;
    SC_DP_VS_BLANK_CNT_LO = VBlankCNT&0xFF; // 0xb89
    SC_DP_AUX_CTRL2 &= 0xF0; // 0xb8a
    SC_DP_AUX_CTRL2 |= (VBlankCNT&0xF00) >> 8; // 0xb8a
#endif

    if ((SC_DP_MISC_CTRL & 0x03) != 0) { // 1280x720/25Hz// 0x1080   
        SC_DP_VIDEO_FIFO_MODE4_ADAPTIVE_CTRL |= BIT3; // 0x1003
    }
    else { // 1.62G
        SC_DP_VIDEO_FIFO_MODE4_ADAPTIVE_CTRL &= ~BIT3;// 0x1003
    }
    
    SC_DP_VIDEO_FIFO_INT = 0x03;// 0x1044
#if IS_NT68790_SERIES || IS_NT68810_SERIES || IS_NT68870_SERIES
    SC_DP_CSC_AUTO_CONF |= 0xC0; // 0x1040
#endif
}

//******************************************************************************
// Prototype: 
//  void DPConfigHWHPD()
// Parameters:
//
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
void DPConfigHWHPD(BOOL enable)
{
/* NT68810 DP HPD pin assignment
DP_HPD_PAD_EN1 at PE6 0xF0D2[4]
*/
#if IS_NT68810_SERIES
    if (enable == TRUE) {
#if DPHPD1_CTRLPIN == 1 || DPHPD2_CTRLPIN == 1
        DP_CTRL |= BIT4; // DP HPD_PAD enable   // 0xf0d2
        SC_MCU_IO_CTRL2 &= 0xF3; // output PE6/HPD1  // 0xc81
#endif
#if DPHPD1_CTRLPIN == 2 || DPHPD2_CTRLPIN == 2
        DP_CTRL |= BIT5; // DP HPD_PAD enable// 0xf0d2
        SC_MCU_IO_CTRL2 &= 0xFC; // output PE7/HPD2   // 0xc81
#endif
    }
    else {
#if DPHPD1_CTRLPIN == 1 || DPHPD2_CTRLPIN == 1
        SC_MCU_IO_CTRL2 &= 0xF3; // output PE6/HPD1   // 0xc81
        DP_CTRL &= ~BIT4; // DP HPD_PAD disable// 0xf0d2
#endif
#if DPHPD1_CTRLPIN == 2 || DPHPD2_CTRLPIN == 2
        SC_MCU_IO_CTRL2 &= 0xFC; // output PE7/HPD2   // 0xc81
        DP_CTRL &= ~BIT5; // DP HPD_PAD disable// 0xf0d2
#endif
    }
#if DPHPD1_CTRLPIN == 1 || DPHPD2_CTRLPIN == 1
    PTE_PP_REG |= BIT6; // output PE6/HPD1
    PTE_PU_REG |= BIT6;
#endif
#if DPHPD1_CTRLPIN == 2 || DPHPD2_CTRLPIN == 2
    PTE_PP_REG |= BIT7; // output PE6/HPD1
    PTE_PU_REG |= BIT7;
#endif
#endif // end NT68810 use

#if IS_NT68870_SERIES
/* NT68870 DP HPD pin assignment
DP_HPD_PAD_EN1 at PE6 0xF0D2[5]
DP_HPD_PAD_EN2 at PE7 0xF0D2[6]
DP_HPD_PAD_EN3 at PD0 0xF0D3[5]
DP_HPD_PAD_EN4 at PD1 0xF0D3[6]
*/
    if (enable == TRUE) {
#if DPHPD1_CTRLPIN == 1 || DPHPD2_CTRLPIN == 1 || DPHPD3_CTRLPIN == 1 || DPHPD4_CTRLPIN == 1
        DP_CTRL |= BIT5; // DP HPD_PAD enable// 0xf0d2
        //SC_MCU_IO_CTRL2 &= 0xF3; // output PE6/HPD1, Yung 870 not at this register
#endif
#if DPHPD1_CTRLPIN == 2 || DPHPD2_CTRLPIN == 2 || DPHPD3_CTRLPIN == 2 || DPHPD4_CTRLPIN == 2
        DP_CTRL |= BIT6; // DP HPD_PAD enable// 0xf0d2
        //SC_MCU_IO_CTRL2 &= 0xFC; // output PE7/HPD2, Yung 870 not at this register
#endif
#if DPHPD1_CTRLPIN == 3 || DPHPD2_CTRLPIN == 3 || DPHPD3_CTRLPIN == 3 || DPHPD4_CTRLPIN == 3
        DP_CTRL2 |= BIT5; // DP HPD_PAD enable// 0xf0d3
        //SC_MCU_IO_CTRL2 &= 0xF3; // output PE6/HPD1, Yung 870 not at this register
#endif
#if DPHPD1_CTRLPIN == 4 || DPHPD2_CTRLPIN == 4 || DPHPD3_CTRLPIN == 4 || DPHPD4_CTRLPIN == 4
        DP_CTRL2 |= BIT6; // DP HPD_PAD enable// 0xf0d3
        //SC_MCU_IO_CTRL2 &= 0xFC; // output PE7/HPD2, Yung 870 not at this register
#endif
    }
    else {
#if DPHPD1_CTRLPIN == 1 || DPHPD2_CTRLPIN == 1 || DPHPD3_CTRLPIN == 1 || DPHPD4_CTRLPIN == 1
        //SC_MCU_IO_CTRL2 &= 0xF3; // output PE6/HPD1
        DP_CTRL &= ~BIT5; // DP HPD_PAD disable// 0xf0d2
#endif
#if DPHPD1_CTRLPIN == 2 || DPHPD2_CTRLPIN == 2 || DPHPD3_CTRLPIN == 2 || DPHPD4_CTRLPIN == 2
        //SC_MCU_IO_CTRL2 &= 0xFC; // output PE7/HPD2
        DP_CTRL &= ~BIT6; // DP HPD_PAD disable// 0xf0d2
#endif
#if DPHPD1_CTRLPIN == 3 || DPHPD2_CTRLPIN == 3 || DPHPD3_CTRLPIN == 3 || DPHPD4_CTRLPIN == 3
        DP_CTRL2 &= ~BIT5; // DP HPD_PAD enable // 0xf0d3
        //SC_MCU_IO_CTRL2 &= 0xF3; // output PE6/HPD1, Yung 870 not at this register
#endif
#if DPHPD1_CTRLPIN == 4 || DPHPD2_CTRLPIN == 4 || DPHPD3_CTRLPIN == 4 || DPHPD4_CTRLPIN == 4
        DP_CTRL2 &= ~BIT6; // DP HPD_PAD enable// 0xf0d3
        //SC_MCU_IO_CTRL2 &= 0xFC; // output PE7/HPD2, Yung 870 not at this register
#endif

    }

    
#if DPHPD1_CTRLPIN == 1 || DPHPD2_CTRLPIN == 1 || DPHPD3_CTRLPIN == 1 || DPHPD4_CTRLPIN == 1
    PTE_PP_REG |= BIT6; // output PE6/HPD1
    PTE_PU_REG |= BIT6;
#endif
#if DPHPD1_CTRLPIN == 2 || DPHPD2_CTRLPIN == 2 || DPHPD3_CTRLPIN == 2 || DPHPD4_CTRLPIN == 2
    PTE_PP_REG |= BIT7; // output PE7/HPD2
    PTE_PU_REG |= BIT7;
#endif
#if DPHPD1_CTRLPIN == 3 || DPHPD2_CTRLPIN == 3 || DPHPD3_CTRLPIN == 3 || DPHPD4_CTRLPIN == 3
    PTD_PP_REG |= BIT0; // output PD0/HPD3
    PTD_PU_REG |= BIT0;
#endif
#if DPHPD1_CTRLPIN == 4 || DPHPD2_CTRLPIN == 4 || DPHPD3_CTRLPIN == 4 || DPHPD4_CTRLPIN == 4
    PTD_PP_REG |= BIT1; // output PD1/HPD4
    PTD_PU_REG |= BIT1;
#endif
#endif
}

//******************************************************************************
// Prototype: 
//  BOOL IsDPTrainingDone()
// Parameters:
//
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
BOOL IsDPTrainingDone(void)
{
    UCHAR ucLaneCount, value;
    BOOL bTrainingStatus = TRUE;

    ucLaneCount = (SC_DP_MISC_CTRL&0x1C)>>2;// 0x1080
    if ((ucLaneCount == 0) || (ucLaneCount > 4)) {
        return FALSE;
    }
    if ((SC_INPUT_SELECT & BIT2) == 0x00) {  // 0x024
        value = GetTMDSPHYDATA(_DPPP_PHY0, _DPRM_LANE_STS);
    }
    else {
        value = GetTMDSPHYDATA(_DPPP_PHY1, _DPRM_LANE_STS);
    }
    do {
        if ((value & 0x11) != 0x11) {
            bTrainingStatus = FALSE;
            break;
        }
        value >>= 1;
    } while(--ucLaneCount != 0);

    return bTrainingStatus;
}

//******************************************************************************
// Prototype: 
//  BOOL IsDPAUXDetect(void)
// Parameters:
//
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
BOOL IsDPAUXDetect(void)
{
#if IS_NT68810_SERIES
    if ((SC_DP_AUX_DETECT & BIT7) != 0) {// 0x101a
        return TRUE;
    }
#else
    if ((SC_DP_AUX_DETECT & 0xC0) != 0) {// 0x101a
        return TRUE;
    }
#endif
#if EN_AUX_STROBE_FUNC == ON
    else if (bDP_AUX_DETECT == 1) {
        return TRUE;
    }
#endif
    else {
        return FALSE;
    }
}

//******************************************************************************
// Prototype: 
//  void ClearDPAUXDetect()
// Parameters:
//
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
void ClearDPAUXDetect(void)
{
    SC_DP_AUX_DETECT |= BIT1;// 0x101a
    Sleep(1);
    SC_DP_AUX_DETECT &= ~BIT1; // 0x101a
#if EN_AUX_STROBE_FUNC == ON
    bDP_AUX_DETECT = 0;
#endif
}

//******************************************************************************
// Prototype: 
//  void DPHandler()
// Parameters:
//
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
void DPHandler(void)
{
    static BOOL bauxactived = FALSE;
    UCHAR currentinterface = GetCurrInputInterface();
    
    if ((IsZpMode() == FALSE)
#if 1//IS_NT68810_SERIES
    && ((currentinterface == DISPLAY_PORT_INPUT) || (currentinterface == DISPLAY_PORT_INPUT1))
#endif
	   ) {
        
         if (IsDPTrainingDone()) {
         }
         else {
            
             if ((currentinterface != DISPLAY_PORT_INPUT) && (currentinterface != DISPLAY_PORT_INPUT1)) {
                 if (((SC_POWER_CTRL3&0x07) != 0x00) && (IsDPAUXDetect() == TRUE)) {// 0x103
                   //  DP_PowerOn();
                 }
                 else if (((SC_POWER_CTRL3&0x07) != 0x07) && (IsDPAUXDetect() == FALSE)) {// 0x103
                     if ((GetTimerTick() - usDPTimer) > WAITDPTIME) {
                   //      DP_PowerOFF();
                     }
                 }
                 if (IsDPAUXDetect()) {
                     ClearDPAUXDetect();
                     usDPTimer = GetTimerTick();
                 }
             }
            
         }
     
           
         if (((currentinterface == DISPLAY_PORT_INPUT) || (currentinterface == DISPLAY_PORT_INPUT1))
           && (GetModeHandleState() == WAIT_MODE_CHANGE)) {
        #if 0//ENABLE_SCALER_AUDIO == ON//NT68810 power
            if ((SC_DP_INT_GROUP_3 & BIT6) == 0x00) { //no packet recieved
                ScalerAudioPowerOff();
            }
            else {
                ScalerAudioPowerOn();
            }
        #endif
             DP_AudioMNChecker();
             if (IsDPAUXDetect()) {
                 bauxactived = TRUE;
                 ClearDPAUXDetect();
                 SetGlobalTimer(GLOBAL_TMR_CHECK_AUX, 2000);
             }
             if (GetGlobalTimer(GLOBAL_TMR_CHECK_AUX) == 0) {
                 if (bauxactived == TRUE) {
                     SC_DP_RESET_FUNCTION |= BIT0; // // 0x1020
                     SC_DP_RESET_FUNCTION &= ~BIT0;  // 0x1020
                     bauxactived = FALSE;
                 }
             }
         }
     }
}

//******************************************************************************
// Prototype: 
//  void DPConfigCRC()
// Parameters:
//
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
void DPConfigCRC(void)
{
#ifdef ENABLE_DP_LINKER_LAYER_CTS
    if ((((SC_DP_MSA_MISC0&0x06) == 0x02) && ((SC_DP_MSA_MISC0&0xF0) != 0x50))
        || ((SC_DP_MSA_MISC0&0xFE) == 0x48)) { // YCbCr 4:2:2 & CEA RGB 10bits disable crc support
        SC_DP_DEBUG = 0x80; //0x1030 enable I2C write DPCD page
        SC_DP_DPCD_00246 = 0x00;//ReadScaler(0x1100+0x52)&(~BIT5));
        SC_DP_DEBUG = 0x00; //0x1030 disable I2C write DPCD page
    }
    else {
        SC_DP_DEBUG = 0x80; //0x1030 enable I2C write DPCD page
        SC_DP_DPCD_00246 = 0x20;//ReadScaler(0x1100+0x52)|BIT5);
        SC_DP_DEBUG = 0x00; //0x1030 disable I2C write DPCD page
    }
#endif
}
#if !lrd_dis
//******************************************************************************
// Prototype: 
//  void DP_AudioSetMNValue(UCHAR table_idx)
// Parameters:
//
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
void DP_AudioSetMNValue(UCHAR table_idx)
{
    code DP_audio_mn DP_Audio_MN_tbl[] = {
        //32K                   44.1K                48K              88.2K               96K            176K                196K
        {0x0C, 0xF3}, {0x11, 0xD7}, {0x13, 0x6B}, {0x23, 0xAE}, {0x26, 0xD6}, {0x47, 0x5C}, {0x4D, 0xAB},  //1.62G
        {0x07, 0xC5}, {0x0A, 0xB5}, {0x0B, 0xA7}, {0x15, 0x68}, {0x17, 0x4E}, {0x2A, 0xD1}, {0x2E, 0x9A},  //2.7G
    };

    //N value is always set to 32768
    SC_DP_MANUAL_NAUD_HI = 0x00;     // 0x1012
    SC_DP_MANUAL_NAUD_MI = 0x80; // 0x1013
    SC_DP_MANUAL_NAUD_LO = 0x00; // 0x1014

    //M value setting
    SC_DP_MANUAL_MAUD_HI = 0x00;         // 0x100f
    SC_DP_MANUAL_MAUD_MI = DP_Audio_MN_tbl[table_idx].DP_Audio_M_MSB; // 0x1010
    SC_DP_MANUAL_MAUD_LO = DP_Audio_MN_tbl[table_idx].DP_Audio_M_LSB; // 0x1011
}
#endif
#if !lrd_dis
//******************************************************************************
// Prototype: 
//  void DP_AudioSetDefault(void)
// Parameters:
//
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
void DP_AudioSetDefault(void)
{
    UCHAR ucspeed;

    ucspeed = SC_DP_MISC_CTRL & (BIT1|BIT0);// 0x1080
    
    switch (ucspeed) {
        case 0: // 1.62
            DP_AudioSetMNValue(DPAUD_M_48k_1_62G);
            break;
        case 1:// 2.7
        default:
            DP_AudioSetMNValue(DPAUD_M_48k_2_7G);
            break;
        case 2:// 5.4
            DP_AudioSetMNValue(DPAUD_M_48k_2_7G);//no use  
            break;
    }
}
#endif
//******************************************************************************
// Prototype: 
//  void DP_AudioSetAudioPath(UCHAR ucpath)
// Parameters:
//
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
void DP_AudioSetAudioPath(UCHAR ucpath)
{
    SC_DP_CRPLL = 0x15; //clk path    // 0x16d1

    if (ucpath == DPAUD_path_auto) {
        SC_DP_PLL_CTRL &= ~BIT6; //auto            // 0x1081
    }
    else {//manual
        SC_DP_PLL_CTRL |= BIT6; //manual      // 0x1081
    }
}

//******************************************************************************
// Prototype: 
//  void DP_AudioMNCheckerInit(void)
// Parameters:
//
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
void DP_AudioMNCheckerInit(void)
{
    //printf("DP_AudioMNCheckerInit\r\n"); 
    SC_DP_AUDIO_FIFO_CTRL |= BIT6; //audio fifo mute      // 0x1050
    usAudioMuteDelay = DP_AUDIODELAY;
    SC_DP_INT_GROUP_3 = 0xFF; //Clear interrupt group 2 status  // 0x1076

    DP_AudioSetAudioPath(DPAUD_path_auto);

    bAudioMNChecking = TRUE;   
}

//******************************************************************************
// Prototype: 
//  UCHAR DP_AudioGetFIFOStatus(BOOL bquickcheck) 
// Parameters:
//
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
UCHAR DP_AudioGetFIFOStatus(BOOL bquickcheck) 
{
    UCHAR ucfifo_readstatus;

    if (!bquickcheck) {
        SC_DP_AUDIO_FIFO_CTRL &= ~BIT7; //audio fifo off // 0x1050
        SC_DP_AUDIO_DAC_CTRL &= ~ BIT7; //audio DAC off    // 0x105A
        SC_DP_AUDIO_DAC_CTRL |= BIT7; //audio DAC on // 0x105A
        SC_DP_AUDIO_FIFO_CTRL |= BIT7; //audio fifo on    // 0x1050
        SC_DP_AUDIO_ERROR_FLAG = 0xFF;// 0x1054
        Sleep(40);
    }
    ucfifo_readstatus = SC_DP_AUDIO_ERROR_FLAG & (BIT6|BIT2);// 0x1054
    //printf("ucfifo_readstatus  = %bx\r\n", ucfifo_readstatus);

    if (ucfifo_readstatus == BIT6) {
        return DPAUD_fifo_overflow;
    }
    else if (ucfifo_readstatus == BIT2) {
        return DPAUD_fifo_underflow;
    }
    else if (ucfifo_readstatus == 0x00) {
        return DPAUD_fifo_balance;
    }
    else {
        return DPAUD_fifo_unknown;
    }
}

//******************************************************************************
// Prototype: 
//  UCHAR DP_AudioMNSearch(void)
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
UCHAR DP_AudioMNSearch(void)
{
#if 1 //search table method
    UCHAR ucsearch_idx, ucspeed, ucfifo_status, i;
    UCHAR ucsearch_result = FALSE;
    
    ucspeed = SC_DP_MISC_CTRL & (BIT1|BIT0);// 0x1080

    if (ucspeed == 0) {//1.62g
        ucsearch_idx = DPAUD_M_32k_1_62G;
    }
    else {//2.7g
        ucsearch_idx = DPAUD_M_32k_2_7G;
    }

    SC_VPLL_CTRL &= ~BIT2;    // 0xb19

    for (i = ucsearch_idx ; i < ucsearch_idx+DPAUD_M_num ; i++) {

        DP_AudioSetMNValue(i);       
        ucfifo_status = DP_AudioGetFIFOStatus(FALSE); 
        //printf("ucfifo_status = %bx %bx\r\n", ucfifo_status, i);

        if (ucfifo_status == DPAUD_fifo_balance) {
            ucsearch_result = TRUE;
            break;
        }
    }

    SC_VPLL_CTRL |= BIT2;// 0xb19

    if (ucsearch_result == FALSE) {
        DP_AudioSetDefault();
    }

    //printf("ucsearch_result = %bx\r\n", ucsearch_result);
    return ucsearch_result;
    
#else //binary search method
    UCHAR ucfifo_status;
    ULONG ulaudio_n_tune = 0x004000;
    ULONG ulaudio_n_tune_upper = 0x008000, ulaudio_n_tune_bottom = 1;
    UCHAR ucsearch_result = FALSE;
    
    SC_DP_MANUAL_MAUD_LO = ulaudio_n_tune; 
    SC_DP_MANUAL_MAUD_MI = ulaudio_n_tune>>8; 
    SC_DP_MANUAL_MAUD_HI = ulaudio_n_tune>>16;     
    ucfifo_status = DP_AudioGetFIFOStatus();
        
    while (ucfifo_status  != DPAUD_fifo_balance || (ulaudio_n_tune_upper-ulaudio_n_tune_bottom) < 3) {
        if (ucfifo_status == DPAUD_fifo_underflow) {
            ulaudio_n_tune_upper = ulaudio_n_tune;
        }
        else if (ucfifo_status == DPAUD_fifo_overflow) {
            ulaudio_n_tune_bottom = ulaudio_n_tune;
        }
        else {
            DP_AudioSetDefault();
            break;
        }
        ulaudio_n_tune = (ulaudio_n_tune_upper + ulaudio_n_tune_bottom)/2;

        SC_DP_MANUAL_MAUD_LO = ulaudio_n_tune; 
        SC_DP_MANUAL_MAUD_MI = ulaudio_n_tune>>8); 
        SC_DP_MANUAL_MAUD_HI = ulaudio_n_tune>>16);     
        //printf("0x10  = %bx\r\n", ReadScaler(0x1000+0x10));
        //printf("0x11  = %bx\r\n", ReadScaler(0x1000+0x11));
        ucfifo_status = DP_AudioGetFIFOStatus();
        //printf("ucfifo_status  = %bx\r\n", ucfifo_status);
    }

    if (ucfifo_status == DPAUD_fifo_balance) {
        ucsearch_result = TRUE;
    }

    return ucsearch_result;
#endif    
}
#endif
//******************************************************************************
// Prototype: 
//  void DP_AudioMNChecker(void)
// Parameters:
//
// Return:
//  None
// Purpose:
//
// Notes:
//  None
//******************************************************************************
void DP_AudioMNChecker(void)
{
    UCHAR mn_search_result = FALSE;
    UCHAR ucfifo_status = DPAUD_fifo_unknown;
    
    if (bAudioMNChecking) {    
        if (SC_DP_INT_GROUP_3 & BIT6) { //packet recieved  // 0x1076
#if 0
            if (!(SC_DP_INT_GROUP_3 & BIT4)){//without M/N upated but with packet, enter search process
                DP_AudioSetAudioPath(DPAUD_path_manual);
             
                if (!DP_AudioMNSearch()) { //if no found in table, swich back to auto mode
                    DP_AudioSetAudioPath(DPAUD_path_auto);      
                }
            }

            SC_DP_RESET_FUNCTION |= BIT3; //audio fifo sw reset
            SC_DP_RESET_FUNCTION &= ~BIT3; //audio fifo sw reset            
//            SC_DP_AUDIO_FIFO_CTRL &= ~BIT6; //audio fifo mute off        
#endif
            bAudioMNChecking = FALSE;
        }
    }
    else {
        if (SC_DP_PLL_CTRL & BIT6) {//manual mode       // 0x1081
            ucfifo_status = DP_AudioGetFIFOStatus(TRUE);
            if (ucfifo_status != DPAUD_fifo_balance) {
                DP_AudioMNCheckerInit();
            }
        }
        if (SC_DISPLAY_MUTE_CTRL == 0x00) {  // 0x154
            if ((SC_DP_INT_GROUP_2 & BIT0) != 0x00) {// 0x1075
                SC_DP_AUDIO_FIFO_CTRL |= BIT6;// 0x1050
                SC_DP_AUDIO_FIFO_CTRL &= ~BIT7; //audio fifo off// 0x1050
                SC_DP_AUDIO_DAC_CTRL &= ~ BIT7; //audio DAC off// 0x105A
                SC_DP_AUDIO_DAC_CTRL |= BIT7; //audio DAC on// 0x105A
                SC_DP_AUDIO_FIFO_CTRL |= BIT7; //audio fifo on// 0x1050
                SC_DP_INT_GROUP_2 = 0xFF;// 0x1075
                SC_DP_AUDIO_ERROR_FLAG = 0xFF;// 0x1054
                usAudioMuteDelay = DP_AUDIODELAY;
//                printf("test\r\n");
            }
            else {
                if (usAudioMuteDelay != 0) {
                    usAudioMuteDelay--;
                }
                else {
                    SC_DP_AUDIO_FIFO_CTRL &= ~BIT6;// 0x1050
                }
            }
        }
    }
}

#if (ENABLE_DP_AUX_MONITOR==ON) 
#define DP_MONITOR ON	   
#define DP_DEBUG_PORT 0   //0~ 4
#define DP_STROBE_BUFFER_NUM_2 18000//18432 //6144*24/8
#define DP_STROBE_BUFFER_SIZE 4     
//UCHAR volatile xdata  *EDID_SRAM_BUFF0=0xF800;//the address 0xF802~0xF803 is used for reading strobe packet len
#if (DP_DEBUG_PORT==1)
USHRT volatile xdata *strobe_count=0xF902;
#elif (DP_DEBUG_PORT==2)
USHRT volatile xdata *strobe_count=0xFA02;
#elif (DP_DEBUG_PORT==3)
USHRT volatile xdata *strobe_count=0xFB02;
#elif (DP_DEBUG_PORT==4)
USHRT volatile xdata *strobe_count=0xFC02;
#else
USHRT volatile xdata *strobe_count=0xF802;
#endif
   
void Init_DP_Strobe(void)
{
	  USHRT i;  
	  CORE_FIX=0x0F;   
    //DP_CTRL=0x1B; // 0xf0d2
	  for(i=0;i<DP_STROBE_BUFFER_SIZE;i++) 
#if (DP_DEBUG_PORT==1)
     *(EDID_SRAM_BUFF1+i)=0x00;
#elif (DP_DEBUG_PORT==2)
     *(EDID_SRAM_BUFF2+i)=0x00;
#elif (DP_DEBUG_PORT==3)
     *(EDID_SRAM_BUFF3+i)=0x00;
#elif (DP_DEBUG_PORT==4)
     *(EDID_SRAM_BUFF4+i)=0x00;
#else
	  	*(EDID_SRAM_BUFF0+i)=0x00;
#endif	  	
    SC_CR_MUX = DP_DEBUG_PORT;
    // enable internal EDID for strobe reading
#if (DP_DEBUG_PORT==1)
      DDC_CTL1 &= ~BIT7;
      McuSetDDC(MCU_DDC_1, 0xA8, 1);  // 0xA8 is special address for Strobe debug reading 
      DDC_CTL1 |= BIT7; 
#elif (DP_DEBUG_PORT==2)
      DDC_CTL2 &= ~BIT7;
      McuSetDDC(MCU_DDC_2, 0xA8, 1);  // 0xA8 is special address for Strobe debug reading 
      DDC_CTL2 |= BIT7; 
#elif (DP_DEBUG_PORT==3)
      DDC_CTL3 &= ~BIT7;
      McuSetDDC(MCU_DDC_3, 0xA8, 1);  // 0xA8 is special address for Strobe debug reading 
      DDC_CTL3 |= BIT7; 
#elif (DP_DEBUG_PORT==4)
      DDC_CTL4 &= ~BIT7;
      McuSetDDC(MCU_DDC_4, 0xA8, 1);  // 0xA8 is special address for Strobe debug reading 
      DDC_CTL4 |= BIT7; 
#else
    DDC_CTL0 &= ~BIT7;
    McuSetDDC(MCU_DDC_0, 0xA8, 1);  // 0xA8 is special address for Strobe debug reading 
    DDC_CTL0 |= BIT7;    
#endif
   #if (DP_MONITOR==ON)	 
    AUX_STROBE_CTL|=BIT0;  // 
   #endif
}

void reset_DP_Strobe(void)
{
	  USHRT i;
	  //clear buffer 
	  for(i=0;i<DP_STROBE_BUFFER_SIZE;i++) 
#if (DP_DEBUG_PORT==1)
     *(EDID_SRAM_BUFF1+i)=0x00;
#elif (DP_DEBUG_PORT==2)
     *(EDID_SRAM_BUFF2+i)=0x00;
#elif (DP_DEBUG_PORT==3)
     *(EDID_SRAM_BUFF3+i)=0x00;
#elif (DP_DEBUG_PORT==4)
     *(EDID_SRAM_BUFF4+i)=0x00;
#else
	  	*(EDID_SRAM_BUFF0+i)=0x00;  
#endif		  	
    //clear flag         
		(*strobe_count)=0;  
		SC_INDEX_CTRL = 0x80;
		SC_INDEX_ADDR_LO = 0; 
    SC_INDEX_ADDR_HI = 0;
    AUX_STROBE_CTL |= BIT3;   
}


// move AUX packets to OSD RAM
void  move_aux_packet(void)// using 1
{ 
#if (DP_MONITOR==OFF)		
	UCHAR i=0;
#endif 

	if((*strobe_count)>=DP_STROBE_BUFFER_NUM_2)  //buffer is full,  continue to read Aux packet ,but does not store them
		return;

//#if IS_NT68850_SERIES 		
//		if(DP_SRC & BIT7)
//#else
//    if(INT_SRC3 & BIT0) 
//#endif	
		{  
//			if(AUX_STROBE_CTL & BIT3) //bit3:  AUX Debug path interrupt flag
				{        
					while(AUX_STROBE_CTL & BIT3)
	 				{
#if (DP_MONITOR==OFF)				
						SC_INDEX_DATA=(AUX_STROBE_FUN&BIT3)?1:0;  // get data direction(RX or TX)
#endif
						SC_INDEX_DATA=AUX_STROBE_PORT; //read strobe data
#if (DP_MONITOR==OFF)							
      	    i++;
#else
            (*strobe_count)++;
#endif      	    
					  AUX_STROBE_CTL |= BIT3;  //clear interrupt flag
					  
					} 
					 CLR_WDT = 0x55;  
	      }
#if (DP_MONITOR==OFF)			      
	      (*strobe_count)+=i*2;   
#endif	      
	   } 
}



void DP_Strobe_Debug(void)
{   
	UCHAR i=0;
#if (DP_DEBUG_PORT==1)
  if((*EDID_SRAM_BUFF1)&BIT6)  //0xF900[6] is used for reset all flag and buffer
#elif (DP_DEBUG_PORT==2)
  if((*EDID_SRAM_BUFF2)&BIT6)  //0xFA00[6] is used for reset all flag and buffer
#elif (DP_DEBUG_PORT==3)
  if((*EDID_SRAM_BUFF3)&BIT6)  //0xFB00[6] is used for reset all flag and buffer
#elif (DP_DEBUG_PORT==4)
  if((*EDID_SRAM_BUFF4)&BIT6)  //0xFC00[6] is used for reset all flag and buffer
#else
	if((*EDID_SRAM_BUFF0)&BIT6)  //0xF800[6] is used for reset all flag and buffer
#endif		
		{
			reset_DP_Strobe();
		}	
		  CLR_WDT = 0x55;
#if (DP_DEBUG_PORT==1)
     DDC_CTL1=0xB0;
#elif (DP_DEBUG_PORT==2)
     DDC_CTL2=0xB0;
#elif (DP_DEBUG_PORT==3)
     DDC_CTL3=0xB0;
#elif (DP_DEBUG_PORT==4)
     DDC_CTL4=0xB0;
#else
		  DDC_CTL0=0xB0;     
#endif		  
		     
}



void DP_Aux_Channel_Monitor(void)
{
	  UCHAR cpu_speed,ip;        
	 
	  if(AUX_STROBE_CTL&BIT0)
		{
#if (DP_MONITOR==ON)         
			SC_DP_AUX_CTRL2&=~BIT4;   //aux strobe listen mode
#endif		
	cpu_speed=CPU_CLK; 
#if IS_NT68850_SERIES			
			CPU_CLK=0x58;  //64Mhz
#else
      CPU_CLK=0x50;
#endif			
			//use OSD RAM to store tmp AUX packets
			OSDAPI_OSDPowerOn();
		  SC_INDEX_CTRL = 0x80;
		  SC_INDEX_ADDR_LO = 0;
      SC_INDEX_ADDR_HI = 0;
#if IS_NT68850_SERIES      
      INTSC_EN|=BIT1;//DP interrrupt enable// 0xf024
#else  //TC68370
      INTSC_EN3|=BIT0;  
#endif      
			AUX_STROBE_CTL = 0x07;// DP AUX STROBE    
			AUX_STROBE_CTL = 0x05;
      ip=IP;
#if IS_NT68850_SERIES
		  IP = 0x01;   // DP interrupt(Ext1) has the highest priority .    
#else
      IP = 0x04; 
#endif		  
		    
		  while(AUX_STROBE_CTL&BIT0)
		  {
		  	DP_Strobe_Debug();  
      }
      //backup 
      
      	IP=ip;
        OSDAPI_OSDPowerOff();
#if IS_NT68850_SERIES      
      INTSC_EN&=~BIT1;//DP interrrupt enable// 0xf024
#else  //TC68370
      INTSC_EN3&=~BIT0;  
#endif         
       
       
        CPU_CLK=cpu_speed;
#if (DP_MONITOR==ON)
        SC_DP_AUX_CTRL2|=BIT4;
#endif
      }
}
#endif


#else
void ForDPCompilerCodePass(void)
{
  code UCHAR temp[]={0x00};
  UCHAR i;
  i = temp[0];
}
#endif



