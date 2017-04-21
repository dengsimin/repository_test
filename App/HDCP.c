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

#if ENABLE_HDCP == ON

//******************************************************************************
// G L O B A L   D E F I N I T I O N S
//******************************************************************************
#define HDCP_KEY_OFFSET 5

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************
static xdata USHRT usNVRamAddr_HDCP;
static xdata USHRT usHDCPChkSum1, usHDCPChkSum2 = 0;
static xdata UCHAR xdata *pHDCPbuffer;

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
// Prototype: 
//  void InitHDCP(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Load HDCP key and enable HDCP.
// Notes:
//  None
//******************************************************************************
void InitHDCP(void)
{
    pHDCPbuffer = FE2P_SRAM_ADDR + NVRAM_HDCP_ADDR;
    NvramReadHDCPdata(pHDCPbuffer);
#if ENABLE_DEMO_HDCP_KEY == ON
    WriteHDCPKey(NULL, NULL);
#else
    WriteHDCPKey(pHDCPbuffer, pHDCPbuffer + HDCP_KEY_OFFSET);
#endif
#if IS_NT68770_SERIES || IS_NT68850_SERIES || IS_NT68790_SERIES || IS_NT68658_SERIES || IS_NT68810_SERIES || IS_NT68870_SERIES
    SC_HDCP_CTRL3 = 0x60; //CTS issue   0x646
#endif
    EnableHDCP();
}

#if ENABLE_NVT_HDCP_WRITER == ON
//******************************************************************************
// Prototype: 
//  void StartHDCPStoring(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Initiate HDCP-related parameters for storing HDCP.
// Notes:
//  None
//******************************************************************************
void StartHDCPStoring(void)
{
    pHDCPbuffer = (FE2P_SRAM_ADDR + NVRAM_HDCP_ADDR);
    usHDCPChkSum1 = 0;
    usHDCPChkSum2 = 0xFFFF;
    usNVRamAddr_HDCP = 0;
}

//******************************************************************************
// Prototype: 
//  void StoreHDCP(UCHAR *ptr, USHRT num)
// Parameters:
//  *ptr : pointer to data
//  num    : number of bytes to be stored
// Return:
//  None
// Purpose:
//  Store HDCP key.
// Notes:
//  None
//******************************************************************************
void StoreHDCP(UCHAR *ptr,  USHRT num)
{
    UCHAR i;

    for (i = 0; i < num; i++) {
        pHDCPbuffer[usNVRamAddr_HDCP] = *ptr;
        if (usNVRamAddr_HDCP < NUM_HDCP_TOTAL) {
            usHDCPChkSum1 += pHDCPbuffer[usNVRamAddr_HDCP];
        }
        usNVRamAddr_HDCP++;
        ptr++;
    }
}

//******************************************************************************
// Prototype: 
//  UCHAR CheckHDCPChkSum(void)
// Parameters:
//  None
// Return:
//  TRUR if checksum is correct. Otherwise, FALSE.
// Purpose:
//  Check HDCP checksum.
// Notes:
//  None
//******************************************************************************
UCHAR CheckHDCPChkSum(void)
{
    usHDCPChkSum2 = pHDCPbuffer[0x121];
    usHDCPChkSum2 = usHDCPChkSum2 << 8;
    usHDCPChkSum2 = usHDCPChkSum2 + pHDCPbuffer[0x122];

    if (usHDCPChkSum1 == usHDCPChkSum2) {
        NvramWriteHDCPdata(pHDCPbuffer);
		InitHDCP();
        return 1;
    }
    else {
        return 0;
    }
}
#endif //#if ENABLE_NVT_HDCP_WRITER == ON

#if ENABLE_HDCP_TRIM_MODE == ON

#if IS_NT68810_SERIES || IS_NT68870_SERIES
void LoadDefaultTrim(void)
{
    SC_HDCP_TRIM_CTRL = 0x08;  // 0xd50
    SC_HDCP_TRIM_TEST_MODE =0x00;// 0xd58
    SC_HDCP_TRIM_ADDR_A = 0x00;// 0xd5b
    SC_HDCP_TRIM_ADDR_B =0x40;// 0xd5c
    SC_HDCP_TRIM_PI = 0x00;// 0xd5f
}
#endif

//******************************************************************************
// Prototype: 
//  BOOL InitHDCPTrimKey(void)
// Parameters:
//  None
// Return:
//  return TRUE if load key successfully
// Purpose:
//  Load HDCP key and enable HDCP from E-fuse.
// Notes:
//  None
//******************************************************************************
BOOL InitHDCPTrimKey(void)
{
    UCHAR tmp_POWER_CTRL2, tmp_SC_HDCP_TRIM_CTRL2, tmp_SC_HDCP_TRIM_CTRL, tmp_LDO_ADJ, tmp_0x605, tmp_reg;
    UCHAR *p, i, tmp_0x81E7;//, tmp_0x8103, tmp_0x81FE;
    USHRT index;
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1)
    UCHAR *k;
#endif


#if ENABLE_HDCP_KEY_DCRPT == ON
    SC_HDCP_SYNC_SELECT = 0x08; // Set decryption key        // 0x640
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1)
    SC_DP_HDCP_CTRL = 0x28; // Set decryption key   // 0x1032
#endif
#else
    SC_HDCP_SYNC_SELECT = 0x00; // Set non-decryption key      // 0x640
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1)
    SC_DP_HDCP_CTRL = 0x20; // Set non-decryption key  // 0x1032
#endif
#endif

//    tmp_0x8103 = SC_POWER_CTRL3;
//    tmp_0x81FE = SC_LVDS_PAD_POWER;
    tmp_0x81E7 = SCREG_1E7;
    tmp_0x605 = SC_HDMI_SOFTWARE_RESET; // 0x605
    tmp_LDO_ADJ = LDO_ADJ;  // 0xf050
    tmp_POWER_CTRL2 = SC_POWER_CTRL2;  // 0x102
    tmp_SC_HDCP_TRIM_CTRL2= SC_HDCP_TRIM_CTRL2;  // 0xd55
    tmp_SC_HDCP_TRIM_CTRL= SC_HDCP_TRIM_CTRL;// 0xd50

    SC_HDMI_SOFTWARE_RESET &= ~(BIT7|BIT3);// 0x605
    LDO_ADJ &= ~BIT7;// 0xf050
#if defined(ENABLE_FPGA_MODE)
    CPU_CLK = 0x10;
#endif
    SC_POWER_CTRL2 |= BIT1;// 0x102
#if IS_NT68790_SERIES_EARLIER
    SC_HDCP_INPUT_CTRL |= BIT7; // 0x641
#endif
//    SC_POWER_CTRL3 |= BIT0;
//    SC_LVDS_PAD_POWER |= (BIT4 | BIT3);
    SC_TMDS_LINK_CLK_SEL = SCREG_1E7 | BIT4;
#if defined(ENABLE_FPGA_MODE)
    SC_HDCP_TRIM_CTRL2 |= BIT6; // 0xd55
#else
    SC_HDCP_TRIM_CTRL2 &= ~BIT6; // 0xd55
#endif
    SC_HDCP_TRIM_CTRL |= BIT0;// 0xd50
    SC_HDCP_TRIM_CTRL &= ~BIT1;// 0xd50
    
#if IS_NT68790_SERIES || IS_NT68810_SERIES || IS_NT68870_SERIES
    SC_HDCP_62E |= BIT3;
#endif

//new add 20151021
#if IS_NT68810_SERIES || IS_NT68870_SERIES    
    SC_HDCP_TRIM_CTRL |= BIT2; // 0xd50
    SC_HDCP_TRIM_TEST_MODE |= BIT7;// 0xd58
    SC_HDCP_TRIM_PI |= BIT0;// 0xd5f
#endif

    p = &SC_HDCP_BKSV; // 0x61a
    for (i=0; i<3; i++) {
//new add 20151021
#if IS_NT68810_SERIES || IS_NT68870_SERIES  
        SC_HDCP_TRIM_ADDR_B = 0x00;// 0xd5c
        SC_HDCP_TRIM_ADDR_A = i+140;// 0xd5b
        SC_HDCP_TRIM_ADDR_B = 0x20; // read pulse// 0xd5c
        SC_HDCP_TRIM_ADDR_B = 0x00;// 0xd5c
#else
        SC_HDCP_TRIM_ADDR = i + 140;  // 0xd51
        SC_HDCP_TRIM_CTRL |= BIT6;// 0xd50
#endif
        *p = SC_HDCP_TRIM_DATA_LO;// 0xd52
        p++;
        *p = SC_HDCP_TRIM_DATA_HI;// 0xd53
        p++;
        ResetWDTimer();
    }  

#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1)
    SC_DP_DEBUG |= BIT7;  // 0x1030
    p = &SC_DP_HDCP_BKSV; // 0x1180
    k = &SC_HDCP_BKSV; // 0x61a
    for (i = 0; i < 5; i++) {
        tmp_reg = *k;
        *p = tmp_reg;
        p++;
        k++;
    }
    SC_DP_DEBUG &= ~BIT7;// 0x1030
#endif

    //Write Key
    tmp_reg = SC_INDEX_CTRL & 0x04;  // 0x0e0
    tmp_reg |= 0xE0;
    SC_INDEX_CTRL = tmp_reg; // 0x0e0

    for (index=0; index<140; index++) {
//new add 20151021
#if IS_NT68810_SERIES || IS_NT68870_SERIES  
        SC_HDCP_TRIM_ADDR_B = 0x00;// 0xd5c
        SC_HDCP_TRIM_ADDR_A = index;// 0xd5b
        SC_HDCP_TRIM_ADDR_B = 0x20; // read pulse// 0xd5c
        SC_HDCP_TRIM_ADDR_B = 0x00;// 0xd5c
#else
        SC_HDCP_TRIM_ADDR = index;// 0xd51
        SC_HDCP_TRIM_CTRL |= BIT6;   // 0xd50
#endif
        SC_INDEX_ADDR_LO = (UCHAR)((2*index) & 0xFF);// 0xe1
        SC_INDEX_ADDR_HI = (UCHAR)((2*index) >> 8);
        SC_INDEX_DATA = SC_HDCP_TRIM_DATA_LO;  //// 0xe3,= 0xd52
        SC_INDEX_ADDR_LO = (UCHAR)((2*index+1) & 0xFF);// 0xe1
        SC_INDEX_ADDR_HI = (UCHAR)((2*index+1) >> 8);
        SC_INDEX_DATA = SC_HDCP_TRIM_DATA_HI;// 0xe3,0xd53
        ResetWDTimer();
    }
// Set decryption key = 0x00, 0x00/////////////////////
        SC_INDEX_ADDR_LO = (UCHAR)((280) & 0xFF);// 0xe1
        SC_INDEX_ADDR_HI = (UCHAR)((280) >> 8);
#if 0
        SC_INDEX_DATA = 0x68;//0x00 //just test, don't apply
#else
        SC_INDEX_DATA = 0x00;//0xe3,
#endif
        SC_INDEX_ADDR_LO = (UCHAR)((281) & 0xFF);// 0xe1
        SC_INDEX_ADDR_HI = (UCHAR)((281) >> 8);
        SC_INDEX_DATA = 0x00;  //0xe3,
////////////////////////////////////////////////////////

#if IS_NT68790_SERIES || IS_NT68810_SERIES || IS_NT68870_SERIES
    SC_HDCP_62E &= ~BIT3;
#endif

    EnableHDCP();
    SC_HDCP_TRIM_CTRL = tmp_SC_HDCP_TRIM_CTRL;// 0xd50
    SC_HDCP_TRIM_CTRL2 = tmp_SC_HDCP_TRIM_CTRL2; // 0xd55
 //new add 20151021
#if IS_NT68810_SERIES || IS_NT68870_SERIES
    LoadDefaultTrim();
#endif
    SC_HDMI_SOFTWARE_RESET = tmp_0x605;// 0x605
//    SC_POWER_CTRL3 = tmp_0x8103;
//    SC_LVDS_PAD_POWER = tmp_0x81FE;
    SC_TMDS_LINK_CLK_SEL = tmp_0x81E7;
    LDO_ADJ = tmp_LDO_ADJ;// 0xf050
#if defined(ENABLE_FPGA_MODE)
    CPU_CLK = MCU_CLK_TIMES << 4;
#endif
    SC_POWER_CTRL2 = tmp_POWER_CTRL2;// 0x102
    Sleep(2);

    if ( SC_HDCP_BKSV == 0x00 && SC_HDCP_BKSV_B2 == 0x00 && SC_HDCP_BKSV_B3 == 0x00 ) { // 0x61a,0x61b,//0x61c
        SC_HDCP_TRIM_CTRL = 0x08;// 0xd50
        return FALSE;
    }

    return TRUE;
}
#endif

#if ENABLE_EDID_TRIM_MODE == ON
//NT68850=0x0B
//NT68770=0x0C
//NT68655=0x0D
BOOL InitEDIDTrim(void)
{
code EDID_Head_Tab[8]={0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00};
UCHAR tmp_0xF04C, tmp_0x8D55, tmp_0x8D50, tmp_0x8101, tmp_0x8102, tmp_0x8641, i;
UCHAR *p;
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


    p = &EDID_SRAM_BUFF0;
    for (i=0; i<64; i++) {
        SC_HDCP_TRIM_ADDR = i;// 0xd51
        SC_HDCP_TRIM_CTRL |= BIT6;// 0xd50
        *p = SC_HDCP_TRIM_DATA_LO;// 0xd52
        p++;
        *p = SC_HDCP_TRIM_DATA_HI;// 0xd53
        p++;
        ResetWDTimer();
    }
  
    p = &EDID_SRAM_BUFF1;
    for (i=0; i<64; i++) {
        SC_HDCP_TRIM_ADDR = i+64;// 0xd51
        SC_HDCP_TRIM_CTRL |= BIT6;// 0xd50
        *p = SC_HDCP_TRIM_DATA_LO;// 0xd52
        p++;
        *p = SC_HDCP_TRIM_DATA_HI;// 0xd53
        p++;
        ResetWDTimer();
    }  

    SC_HDCP_TRIM_CTRL = tmp_0x8D50;// 0xd50
    SC_HDCP_TRIM_CTRL2 = tmp_0x8D55; // 0xd55
    CPU_CLK = tmp_0xF04C;
    SC_HDCP_INPUT_CTRL = tmp_0x8641;// 0x641
    SC_POWER_CTRL1 = tmp_0x8101;
    SC_POWER_CTRL2 = tmp_0x8102;// 0x102

    for (i=0; i<8; i++) {
        if (EDID_SRAM_BUFF0[i] != EDID_Head_Tab[i]) {
            return FALSE;
        }
        if (EDID_SRAM_BUFF1[i] != EDID_Head_Tab[i]) {
            return FALSE;
        }
    }

    return TRUE;
} 
#endif

#endif //#if ENABLE_HDCP == ON
