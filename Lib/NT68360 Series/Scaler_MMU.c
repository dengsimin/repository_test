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

#if ENABLE_MMU == ON
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
 * Initialize MMU-related registers.
 ******************************************************************************/
void MMUInitialize(void)
{
    code UCHAR MMU_PHY_ADDR_TAB[] = {
        0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,
        0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,0x2E,0x2F,
        0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x3D,0x3E,0x3F,
        0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5A,0x5B,0x5C,0x5D,0x5E,0x5F,
        0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,
    };
    code UCHAR MMU_PHY_DATA_TAB[] = {
        0x10,0x10,0x10,0x10,0x1C,0x83,0x83,0x04,0xDC,0x23,0x81,
        0x21,0x00,0xC1,0x00,0x2C,0x6A,0x36,0x10,0x10,0x10,0x10,0x10,0x10,0x53,0x20,0x00,
        0x00,0x24,0x03,0x8F,0x44,0x20,0x06,0x1F,0x00,0x00,0xFA,0x46,0xCE,0xDF,0xAB,0x22,
        0x00,0xC0,0x0C,0xAA,0xE8,0x10,0x10,0x10,0x10,0x10,0x10,0x53,0x20,0x00,0x24,0x03,
        0x8F,0x44,0x20,0x00,0x45,0xCE,0xC5,0x11,0x76,
    };

    UCHAR i, k, *p;    
#if SCALER_TYPE == NT68364
    SC_DRAM_INTERFACE_LO = 0x08;//0x58;
    SC_MMU_CFG2 = 0x5D;
    SC_MCLK_RATIO_LO = 0xAA;
    SC_MCLK_RATIO_MI = 0xAA;
    SC_MCLK_RATIO_HI = 0x14;//0x40;
    SC_MCLK_SSC_CTRL = 0x4D;//0x0D;
#else
    SC_DRAM_INTERFACE_LO = 0x58;
    SC_MMU_CFG2 = 0x5D;

    SC_MCLK_RATIO_LO = 0xAA;
    SC_MCLK_RATIO_MI = 0xAA;
#if ENABLE_3D_CNV_120Hz == ON
    SC_MCLK_RATIO_HI = 0x41;
    SC_MCLK_SSC_CTRL = 0x4D;
#else
    SC_MCLK_RATIO_HI = 0x40;
    SC_MCLK_SSC_CTRL = 0x0D;
#endif
#endif
    Sleep(2);        

    SC_ISOLATION_CONTROL = 0x00;

    k = sizeof(MMU_PHY_DATA_TAB);
    for (i=0; i<k; i++) {
        p = &SC_DDR_CMD_PLEG;
        p += MMU_PHY_ADDR_TAB[i];
        *p = MMU_PHY_DATA_TAB[i];
    }

#if SCALER_TYPE == NT68364
    SC_ODT_MODE_CTRL_LO = 0x60;//0x00;
    SC_ODT_MODE_CTRL_HI = 0x00;

    SC_WR_DQ_PHASE_LO = 0x46;
    SC_WR_DQS_PHASE_LO = 0xCD;//0xCE;
    SC_WR_CMD_PHASE = 0xD0;//0xDF;
    SC_WR_CLK_PHASE = 0xAD;//0xAB;
    SC_RD_DQS_PHASE_LO = 0x55;//0x22;

    SC_WR_DQ_PHASE_HI = 0x45;
    SC_WR_DQS_PHASE_HI = 0xCE;
    SC_RD_DQS_PHASE_HI = 0x11;

    SC_RD_DQS_WND_ADJ = 0x07;//0x04;
    SC_DDR_PAD_CTRL_LO = 0x20;
    SC_DDR_PAD_CTRL_HI = 0x20;
    SC_DDR_CMD_PLEG = 0x10;
    SC_DDR_CMD_NLEG = 0x10;        

    SC_AUTO_REFLESH_CTRL = 0x01;

    SC_DDR_PHY_E20 = 0x00;
    SC_DDR_PHY_E22 = 0xC0;
    SC_ISOLATION_CONTROL = 0x02;
    Sleep(3);
    SC_ISOLATION_CONTROL = 0x00;
    Sleep(1);
    SC_DDR_PHY_E22 = 0xC1;

    SC_DRAM_MMU_MODE_2 = 0x02;//0x42;
    SC_DRAM_MMU_MODE = 0x32;//0x52;
    SC_DRAM_MMU_MODE_1 = 0x00;
    SC_DRAM_MMU_MODE_3 = 0x20;    
#else
    SC_ODT_MODE_CTRL_LO = 0x00;
    SC_ODT_MODE_CTRL_HI = 0x00;

    SC_WR_DQ_PHASE_LO = 0x46;
    SC_WR_DQS_PHASE_LO = 0xCE;
    SC_WR_CMD_PHASE = 0xDF;
    SC_WR_CLK_PHASE = 0xAB;
    SC_RD_DQS_PHASE_LO = 0x22;

    SC_WR_DQ_PHASE_HI = 0x45;
    SC_WR_DQS_PHASE_HI = 0xCE;
    SC_RD_DQS_PHASE_HI = 0x11;

    SC_RD_DQS_WND_ADJ = 0x04;
    SC_DDR_PAD_CTRL_LO = 0x20;
    SC_DDR_PAD_CTRL_HI = 0x20;
    SC_DDR_CMD_PLEG = 0x10;
    SC_DDR_CMD_NLEG = 0x10;        

    SC_AUTO_REFLESH_CTRL = 0x01;

    SC_DDR_PHY_E22 = 0xC0;
    SC_ISOLATION_CONTROL = 0x02;
    Sleep(3);
    SC_ISOLATION_CONTROL = 0x00;
    Sleep(1);
    SC_DDR_PHY_E22 = 0xC1;

    SC_DRAM_MMU_MODE_2 = 0x42;
    SC_DRAM_MMU_MODE = 0x52;
    SC_DRAM_MMU_MODE_1 = 0x00;
    SC_DRAM_MMU_MODE_3 = 0x20;    
#endif
    //MMU
#if ENABLE_SINGLE_DDR == ON
    SC_DRAM_INTERFACE_HI = 0x37;//0x37: 16 bit, 0x35: 32 bit
#else
    SC_DRAM_INTERFACE_HI = 0x35;//0x37: 16 bit, 0x35: 32 bit
#endif

    SC_DRAM_MMU_REQUEST_W = 0x18;
    SC_DRAM_MMU_REQUEST_R = 0xF8;

    SC_DDR_PAD_CTRL1 = 0xFF;
    SC_DDR_PAD_CTRL2 = 0x02;

    SC_MMU_TM_DQS_SEL_7_0 = 0xf0;
    SC_MMU_TM_DQS_SEL_15_8 = 0x0f;
    SC_MMU_TM_DQS_SEL_23_16 = 0xf0;
    SC_MMU_TM_DQS_SEL_31_24 = 0x0f;

    SC_DRAM_CLOCK_CTRL[0] = 0x00;
    SC_DRAM_CLOCK_CTRL[1] = 0x00;
    SC_DRAM_CLOCK_CTRL[2] = 0x00;
    SC_DRAM_CLOCK_CTRL[3] = 0x00;
    SC_DRAM_CLOCK_CTRL[4] = 0x00;
    SC_DRAM_CLOCK_CTRL[5] = 0x00;
    SC_DRAM_CLOCK_CTRL[6] = 0x00;
    SC_DRAM_CLOCK_CTRL[7] = 0x01;

#if SCALER_TYPE == NT68364
    SC_MMU_CFG2B = 0xA6;//0xA0;

    MMUConfigFIFO(MMU_FIFO_OD_POST);
    MMUConfigFrameBufAddr(MMU_FRAME_ADDR_OD_POST);

    Sleep(3);
    SC_DRAM_INTERFACE_LO = 0x09;//0x59;

    SC_MMU_CFG2 = 0x5D;//0x5F;
    SC_MMU_CFG3 |= BIT1;
#else
    SC_MMU_CFG2B = 0xA0;

    MMUConfigFIFO(MMU_FIFO_OD_POST);
    MMUConfigFrameBufAddr(MMU_FRAME_ADDR_OD_POST);

    Sleep(3);
    SC_DRAM_INTERFACE_LO = 0x59;

    SC_MMU_CFG2 = 0x5F;
    SC_MMU_CFG3 |= BIT1;
#endif
}

/**************************************************************************//**
 * Set MMU fifo.
 * @param mode FIFO mode.
 ******************************************************************************/
void MMUConfigFIFO(MMUFIFOMode mode)
{
    code UCHAR ucFIFOAddr[] = {
        0x56, 0x57, 0x58, 0x59,
        0x94,
        0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9C, 0x9D, 0x9E,
        0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB,
        0xBC, 0xBD, 0xBE, 0xBF, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4
    };

    code UCHAR ucFIFOValue[][4] = {
#if ENABLE_3D_CNV_120Hz == ON
        {0xDF, 0xDF, 0xDF, 0xDF},   //0x8556
        {0x03, 0x03, 0x03, 0x03},   //0x8557
        {0xDF, 0xDF, 0xDF, 0xDF},   //0x8558
        {0x03, 0x03, 0x03, 0x03},   //0x8559
        {0x1F, 0x8F, 0x8F, 0x1F},   //0x8594
        {0x1F, 0x8F, 0x8F, 0x1F},   //0x8595
        {0x3F, 0x97, 0x97, 0x3F},   //0x8596
        {0x2F, 0x97, 0x97, 0x2F},   //0x8597
        {0x1D, 0x00, 0x00, 0x1D},   //0x8598
        {0x1F, 0x00, 0x00, 0x1F},   //0x8599
        {0x1D, 0x00, 0x00, 0x1D},   //0x859A
        {0x1F, 0x8F, 0x3F, 0x1F},   //0x859C
        {0x2F, 0x8F, 0x3F, 0x2F},   //0x859D
        {0x1F, 0x8F, 0x3F, 0x1F},   //0x859E
        {0x00, 0x01, 0x01, 0x00},   //0x85A3
        {0x00, 0x00, 0x00, 0x00},   //0x85A4
        {0xE0, 0x2F, 0x2F, 0xE0},   //0x85A5
        {0x12, 0x00, 0x00, 0x12},   //0x85A6
        {0xC1, 0x00, 0x00, 0xC1},   //0x85A7
        {0x32, 0x00, 0x00, 0x32},   //0x85A8
        {0x22, 0x23, 0x23, 0x22},   //0x85A9
        {0x33, 0x60, 0x60, 0x33},   //0x85AA
        {0xDE, 0x8F, 0x8F, 0xDE},   //0x85AB
        {0x00, 0x01, 0x01, 0x00},   //0x85BC
        {0x00, 0x00, 0x00, 0x00},   //0x85BD
        {0xE0, 0x5F, 0x5F, 0xE0},   //0x85BE
        {0x12, 0x00, 0x00, 0x12},   //0x85BF
        {0xC1, 0x00, 0x00, 0xC1},   //0x85C0
        {0x32, 0x00, 0x00, 0x32},   //0x85C1
        {0x22, 0x23, 0x23, 0x22},   //0x85C2
        {0x33, 0x60, 0x60, 0x33},   //0x85C3
        {0xDE, 0x8F, 0x8F, 0xDE}    //0x85C4
#else
        {0xDF, 0xDF, 0xDF, 0xDF},   //0x8556
        {0x03, 0x03, 0x03, 0x03},   //0x8557
        {0xDF, 0xDF, 0xDF, 0xDF},   //0x8558
        {0x03, 0x03, 0x03, 0x03},   //0x8559
        {0x1F, 0x1F, 0x1F, 0x1F},   //0x8594
        {0x1F, 0x1F, 0x1F, 0x1F},   //0x8595
        {0x3F, 0x3F, 0x3F, 0x3F},   //0x8596
        {0x2F, 0x2F, 0x2F, 0x2F},   //0x8597
        {0x1D, 0x00, 0x1D, 0x1D},   //0x8598
        {0x1F, 0x00, 0x1F, 0x1F},   //0x8599
        {0x1D, 0x00, 0x1D, 0x1D},   //0x859A
        {0x1F, 0x1F, 0x1F, 0x1F},   //0x859C
        {0x2F, 0x2F, 0x2F, 0x2F},   //0x859D
        {0x1F, 0x1F, 0x1F, 0x1F},   //0x859E
        {0x00, 0x00, 0x00, 0x00},   //0x85A3
        {0x00, 0x00, 0x00, 0x00},   //0x85A4
        {0xE0, 0xE0, 0xE0, 0xE0},   //0x85A5
        {0x12, 0x00, 0x12, 0x12},   //0x85A6
        {0xC1, 0x00, 0xC1, 0xC1},   //0x85A7
        {0x32, 0x00, 0x32, 0x32},   //0x85A8
        {0x22, 0x12, 0x22, 0x22},   //0x85A9
        {0x33, 0xC1, 0x33, 0x33},   //0x85AA
        {0xDE, 0xA1, 0xDE, 0xDE},   //0x85AB
        {0x00, 0x01, 0x00, 0x00},   //0x85BC
        {0x00, 0x00, 0x00, 0x00},   //0x85BD
        {0xE0, 0x5F, 0xE0, 0xE0},   //0x85BE
        {0x12, 0x00, 0x12, 0x12},   //0x85BF
        {0xC1, 0x00, 0xC1, 0xC1},   //0x85C0
        {0x32, 0x00, 0x32, 0x32},   //0x85C1
        {0x22, 0x23, 0x22, 0x22},   //0x85C2
        {0x33, 0x60, 0x33, 0x33},   //0x85C3
        {0xDE, 0x8F, 0xDE, 0xDE}    //0x85C4
#endif
    };

    UCHAR i;
    UCHAR xdata * ptr;

    if (mode >= NUM_MMU_FIFO_MODE) {
        mode = MMU_FIFO_OD_POST;
    }

    ptr = 0x8500;

    for (i = 0; i < sizeof(ucFIFOAddr); i++) {
        ptr = (UCHAR xdata *)(0x8500 + ucFIFOAddr[i]);
        *ptr = ucFIFOValue[i][mode];
    }
}

/**************************************************************************//**
 * Set frame buffer start address.
 * @param mode Frame mode.
 ******************************************************************************/
void MMUConfigFrameBufAddr(MMUFrameAddrMode mode)
{
#if ENABLE_SINGLE_DDR == ON
    Write3ByteScaler(&SC_FRAME_BUFFER1L_BASE_ADDR_FRC_LO, 0x000000);
    Write3ByteScaler(&SC_FRAME_BUFFER1R_BASE_ADDR_FRC_LO, 0x060000);
    Write3ByteScaler(&SC_FRAME_BUFFER2L_BASE_ADDR_FRC_LO, 0x0C0000);
    Write3ByteScaler(&SC_FRAME_BUFFER2R_BASE_ADDR_FRC_LO, 0x120000);

    switch (mode) {
        case MMU_FRAME_ADDR_OD_POST:
            Write3ByteScaler(&SC_FRAME_BUFFER_BASE_ADDR_OD_LO, 0x180000);
            break;
        case MMU_FRAME_ADDR_PRE_OD:
            Write3ByteScaler(&SC_FRAME_BUFFER_BASE_ADDR_OD_LO, 0x120000);
            break;
        case MMU_FRAME_ADDR_PRE_POST:
            Write3ByteScaler(&SC_FRAME_BUFFER_BASE_ADDR_OD_LO, 0x180000);
            break;
        default:
            Write3ByteScaler(&SC_FRAME_BUFFER_BASE_ADDR_OD_LO, 0x180000);
            break;
    }

    Write3ByteScaler(&SC_FRAME_BUFFER1L_BASE_ADDR_PREFRC_LO, 0x180000);
    Write3ByteScaler(&SC_FRAME_BUFFER1R_BASE_ADDR_PREFRC_LO, 0x1E0000);
#else
    mode = MMU_FRAME_ADDR_PRE_OD_POST;

    Write3ByteScaler(&SC_FRAME_BUFFER1L_BASE_ADDR_FRC_LO, 0x000000);
    Write3ByteScaler(&SC_FRAME_BUFFER1R_BASE_ADDR_FRC_LO, 0x040000);
    Write3ByteScaler(&SC_FRAME_BUFFER2L_BASE_ADDR_FRC_LO, 0x080000);
    Write3ByteScaler(&SC_FRAME_BUFFER2R_BASE_ADDR_FRC_LO, 0x0C0000);
    Write3ByteScaler(&SC_FRAME_BUFFER_BASE_ADDR_OD_LO, 0x100000);
    Write3ByteScaler(&SC_FRAME_BUFFER1L_BASE_ADDR_PREFRC_LO, 0x140000);
    Write3ByteScaler(&SC_FRAME_BUFFER1R_BASE_ADDR_PREFRC_LO, 0x180000);
#endif
}

/**************************************************************************//**
 * Turn on MMU power.
 ******************************************************************************/
void MMUPowerOn(void)
{
    SC_POWER_CTRL2 |= (BIT2 | BIT4);
}

/**************************************************************************//**
 * Turn off MMU power.
 ******************************************************************************/
void MMUPowerOff(void)
{
    SC_POWER_CTRL2 &= ~(BIT2 | BIT4);

    SC_MMU_CFG2 = 0x00;
#if SCALER_TYPE == NT68364
    SC_DRAM_INTERFACE_LO = 0x08;//0x58;
#else
    SC_DRAM_INTERFACE_LO = 0x58;
#endif
    SC_DDR_PHY_APLL_CTRL = 0x00;    
    SC_WR_DQ_PHASE_LO = 0x08;
    SC_WR_DQ_PHASE_HI = 0x08;

    SC_DDR_PHY_CTRL_LO = 0x00;    
    SC_ODT_MODE_CTRL_LO = 0x00;
    SC_ODT_MODE_CTRL_HI = 0x00;
    SC_DDR_PHY_CTRL_HI = 0x00;
    SC_DDR_PHY_MCK_WR_EN = 0x00;

    SC_ISOLATION_CONTROL = 0x02;
}

/**************************************************************************//**
 * Reset MMU interface.
 ******************************************************************************/
void MMUReset(void)
{
    SC_DRAM_INTERFACE_LO &= ~BIT0;
    SC_DDR_PHY_E22 = 0xC0;
    Sleep(5);
    SC_DDR_PHY_E22 = 0xC1;
    Sleep(1);
    SC_DRAM_INTERFACE_LO |= BIT0;
}

/**************************************************************************//**
 * Detect MMU status and automatically recovery MMU if MMU is abnormal.
 * This function is performed periodically in system-level flow.
 ******************************************************************************/
void MMUErrCorrection(void)
{
    UCHAR i, readback;

    if (GetGlobalTimer(GLOBAL_TMR_MMU_ECC) == 0) {
        SC_DRAM_LINE_BUFFER_BASE_QUANTITY = 0x02;
        SC_DRAM_LINE_BUFFER_CTRL = 0x80;
        SC_DRAM_LINE_BUFFER_CTRL = 0x42;
        Sleep(2);
        for (i = 0; i < 64; i++) {
            readback = SC_DRAM_LINE_BUFFER_DATA_PORT;
        }
        Sleep(2);
        readback = SC_DRAM_LINE_BUFFER_CTRL;
        if ((readback & BIT1) != 0x00) {
            MMUReset();
        }
        SetGlobalTimer(GLOBAL_TMR_MMU_ECC, 1000);
    }
}

#endif //ENABLE_MMU == ON
