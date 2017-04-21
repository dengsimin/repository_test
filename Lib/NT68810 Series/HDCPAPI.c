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
// M A C R O   D E F I N I T I O N S
//******************************************************************************

//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************
#if ENABLE_DEMO_HDCP_KEY == ON
/*!
 * Default HDCP KSV for development.
 */
static code UCHAR demo_keyKSV[] = {
    0x24, 0xC8, 0xEB, 0x3E, 0x9C,
};
/*!
 * Default HDCP key for development.
 */
static code UCHAR demo_key[] = {
    0xF1, 0x04, 0x43, 0x87, 0x2C, 0x22, 0x0D,
    0xDA, 0x6D, 0xF9, 0x4C, 0x25, 0xCA, 0x04,
    0x03, 0xA9, 0x63, 0x6D, 0x9F, 0xA3, 0x71,
    0x62, 0x0E, 0xB4, 0xFB, 0x29, 0xBA, 0xB4,
    0xFB, 0xD9, 0xDB, 0x0C, 0x9E, 0xD3, 0x5A,
    0x0A, 0xDD, 0x7C, 0x5A, 0x9E, 0x9F, 0x88,
    0x15, 0x0B, 0x34, 0x13, 0x20, 0xBB, 0xFC,
    0x2C, 0x36, 0x24, 0xC1, 0x60, 0xCF, 0xC2,
    0x56, 0x55, 0x80, 0x11, 0x5D, 0x2A, 0x61,
    0xD0, 0x8C, 0xEF, 0xF1, 0x20, 0xE7, 0xAC,
    0x5D, 0xD4, 0xC3, 0xD4, 0x11, 0x75, 0x8D,
    0x33, 0x3C, 0xA9, 0x95, 0x2C, 0x4D, 0x13,
    0x14, 0x51, 0xA5, 0x48, 0xEB, 0x5A, 0x68,
    0x99, 0xC6, 0xBE, 0xF0, 0x4A, 0xA7, 0x4D,
    0x64, 0x30, 0x77, 0x22, 0x52, 0xA4, 0x23,
    0xBD, 0x96, 0xAA, 0xAA, 0x3E, 0x44, 0xB8,
    0x8F, 0xEA, 0x23, 0x6F, 0xE7, 0xB4, 0xEF,
    0xE7, 0x66, 0x1B, 0x3C, 0xB0, 0x3E, 0x83,
    0x6D, 0x5C, 0xBE, 0xA4, 0x95, 0x88, 0x0D,
    0x0B, 0xA4, 0xFA, 0x96, 0x02, 0xB5, 0xC4,
    0xE5, 0xD8, 0x9A, 0xAB, 0x7F, 0xF7, 0x6E,
    0xAA, 0x90, 0x95, 0x73, 0xC5, 0x82, 0x02,
    0x87, 0x3F, 0xD0, 0xC4, 0xFA, 0xBF, 0x5D,
    0xFC, 0x5D, 0x55, 0x18, 0x24, 0xDE, 0x63,
    0xA7, 0x12, 0x72, 0x25, 0x66, 0x6E, 0xB4,
    0x6E, 0x9F, 0x18, 0x5D, 0xC1, 0x36, 0xC7,
    0xBA, 0xD0, 0x56, 0x34, 0xCE, 0x62, 0x90,
    0x6C, 0x72, 0x64, 0x31, 0x71, 0x18, 0x73,
    0x1E, 0x8D, 0xDF, 0x13, 0xFB, 0x66, 0xAC,
    0xB2, 0xA3, 0x1A, 0xE7, 0xB3, 0x59, 0xBD,
    0x97, 0xB1, 0x4C, 0xC9, 0x52, 0x93, 0x4F,
    0xAA, 0x63, 0x3F, 0xF0, 0x86, 0x35, 0x81,
    0xC1, 0x11, 0x49, 0x89, 0x60, 0x2A, 0xAB,
    0x96, 0xB7, 0xD2, 0x58, 0x68, 0xBA, 0x86,
    0x2F, 0xC9, 0x7E, 0xE8, 0x1D, 0x77, 0x0F,
    0x36, 0x20, 0xFC, 0xCC, 0x3E, 0xDB, 0x33,
    0x98, 0xEF, 0x82, 0xCC, 0x51, 0x74, 0xD5,
    0x3A, 0x08, 0xE4, 0xBB, 0xA3, 0x27, 0x6A,
    0xFF, 0x59, 0x6B, 0xBC, 0x09, 0x8A, 0xD4,
    0x5C, 0x00, 0x31, 0x87, 0x3E, 0x20, 0x38,
    0x68, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05
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

/**************************************************************************//**
 * Load HDCP KSV&key to scaler
 * @param pKSV pointer to HDCP KSV
 * @param pKey pointer to HDCP Key
 ******************************************************************************/
void WriteHDCPKey(UCHAR *pKSV, UCHAR *pKey)
{
    UCHAR tmp_reg, *p;
    USHRT i;
    
    ResetWDTimer();   
#if IS_NT68790_SERIES_EARLIER
    SC_HDCP_INPUT_CTRL = 0x80 | HDCP_CLK_INV;  // Set Refclk * clk inverted  // 0x641
#endif
#if ENABLE_HDCP_KEY_DCRPT == ON
    SC_HDCP_SYNC_SELECT = 0x08; // Set decryption key    // 0x640
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1) || (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
    SC_DP_HDCP_CTRL = 0x28; // Set decryption key   // 0x1032
#endif
#else
    SC_HDCP_SYNC_SELECT = 0x00; // Set non-decryption key     // 0x640
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1) || (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
    SC_DP_HDCP_CTRL = 0x20; // Set non-decryption key   // 0x1032
#endif
#endif
    
#if IS_NT68790_SERIES || IS_NT68810_SERIES || IS_NT68870_SERIES
    SC_HDCP_62E |= BIT3;
#endif
    
    //Write KSV
    p = &SC_HDCP_BKSV; // 0x61a
    for (i = 0; i < 5; i++) {
#if ENABLE_DEMO_HDCP_KEY == ON
        tmp_reg = demo_keyKSV[i];
#else
        tmp_reg = pKSV[i];
#endif
        *p = tmp_reg;
        p++;
    }

#if ENABLE_DVI_DUAL_LINK == ON
    p = &SC_HDCP_BKSV2;
    for (i = 0; i < 5; i++) {
		#if ENABLE_DEMO_HDCP_KEY == ON
        tmp_reg = demo_keyKSV[i];
		#else
        tmp_reg = pKSV[i];
		#endif
        *p = tmp_reg;
        p++;
    }    
#endif

#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1) || (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
    SC_DP_DEBUG |= BIT7;// 0x1030
    p = &SC_DP_HDCP_BKSV;// 0x1180
    for (i = 0; i < 5; i++) {
#if ENABLE_DEMO_HDCP_KEY == ON
        tmp_reg = demo_keyKSV[i];
#else
        tmp_reg = pKSV[i];
#endif
        *p = tmp_reg;
        p++;
    }
    SC_DP_DEBUG &= ~BIT7;// 0x1030
#endif

    //Write Key
    tmp_reg = SC_INDEX_CTRL & 0x04; // 0x0e0
    tmp_reg |= 0xE0;
    SC_INDEX_CTRL = tmp_reg; // 0x0e0

    for (i = 0; i < 282; i++) {
#if ENABLE_DEMO_HDCP_KEY == ON
        tmp_reg = demo_key[i];
#else
        tmp_reg = pKey[i];
#endif
        SC_INDEX_ADDR_LO = (UCHAR)(i & 0xFF);// 0xe1
        SC_INDEX_ADDR_HI = (UCHAR)(i >> 8);
        SC_INDEX_DATA = tmp_reg;// 0xe3
    }
    

#if IS_NT68790_SERIES || IS_NT68810_SERIES || IS_NT68870_SERIES
    SC_HDCP_62E &= ~BIT3;
#endif
    // For disable compile warning only under ENABLE_DEMO_HDCP_KEY == ON
    pKSV = 0;
    pKey = 0;
    ResetWDTimer();
}

/**************************************************************************//**
 * Enable HDCP function
 ******************************************************************************/
void EnableHDCP(void)
{
    SC_HDCP_INPUT_CTRL = 0x00 | HDCP_CLK_INV;  // 0x641
    SC_HDCP_SLAVE_ADDR = 0x74;  // 0x63f

#if ENABLE_DVI_DUAL_LINK == ON
    SC_HDCP_SLAVE_ADDR2 = 0x76; // 0xabf
#endif		
}

#endif //ENABLE_HDCP == ON

void ForDemoHDCPCompilerCodePass(void)
{
  code UCHAR temp[]={0x00};
  UCHAR i;
  i = temp[0];
}

