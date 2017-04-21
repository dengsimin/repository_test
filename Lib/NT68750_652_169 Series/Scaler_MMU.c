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
    UCHAR i, k;
    USHRT start_addr, end_addr;

    SC_MCLK_RATIO_LO = 0xAA;
    SC_MCLK_RATIO_MI = 0xAA;
    SC_MCLK_RATIO_HI = 0x34;

    SC_MCLK_SSC_CTRL = 0x4D;

    SC_DRAM_MMU_MODE = 0x33;
    SC_DDR_PAD_CTRL1 = 0x00;
    SC_DDR_PAD_CTRL2 = 0x02;

    SC_MMU_DLL_CTRL = 0x88;
    SC_MMU_DLL_PHASE_CTRL0 = 0x0C;
    SC_MMU_DLL_PHASE_CTRL1 = 0xCC;
    SC_MMU_DLL_PHASE_CTRL2 = 0xC0;
    SC_MMU_DLL_PHASE_CTRL3 = 0x00;
    SC_MMU_DLL_INF = 0x00;

    SC_DRAM_CLOCK_CTRL[0] = 0x00;
    SC_DRAM_CLOCK_CTRL[1] = 0x00;
    SC_DRAM_CLOCK_CTRL[2] = 0x00;
    SC_DRAM_CLOCK_CTRL[3] = 0x00;
    SC_DRAM_CLOCK_CTRL[4] = 0xB3;
    SC_DRAM_CLOCK_CTRL[5] = 0x33;
    SC_DRAM_CLOCK_CTRL[6] = 0x00;
    SC_DRAM_CLOCK_CTRL[7] = 0x81;
    SC_MMU_DATA_PHASE_SEL = 0x01;
    SC_DRAM_INTERFACE_LO = 0x89;
    SC_DRAM_INTERFACE_HI = 0x13;
    SC_MMU_CFG2 = 0x01;

    //OD Write SRAM
    start_addr = 0;
    end_addr = 176 - 1;//(ULONG)PANEL_WIDTH * 24 / 128 -1;
    k = (start_addr >> 4) & 0xF0;
    i = (end_addr >> 8) & 0x0F;
    SC_OD_WRITE_FIFO_ADDR_HI = k | i;
    SC_OD_WRITE_FIFO_ADDR_START = (UCHAR)start_addr;
    SC_OD_WRITE_FIFO_ADDR_END = (UCHAR)end_addr;
    //OD Read SRAM
    start_addr = 0;
    end_addr = 176 -1;//(ULONG)PANEL_WIDTH * 24 / 128 -1;
    k = (start_addr >> 4) & 0xF0;
    i = (end_addr >> 8) & 0x0F;
    SC_OD_READ_FIFO_ADDR_HI = k | i;
    SC_OD_READ_FIFO_ADDR_START = (UCHAR)start_addr;
    SC_OD_READ_FIFO_ADDR_END = (UCHAR)end_addr;
    //DRAM
    Write3ByteScaler(&SC_FRAME_BUFFER_BASE_ADDR_OD_LO, 0x00000000);
}

/**************************************************************************//**
 * Turn on MMU power.
 ******************************************************************************/
void MMUPowerOn(void)
{
    SC_POWER_CTRL2 |= BIT2;
    SC_MMU_DLL_CTRL = 0x88;
    SC_DRAM_INTERFACE_LO = 0x89;
    SC_MMU_CFG2 = 0x01;
}

/**************************************************************************//**
 * Turn off MMU power.
 ******************************************************************************/
void MMUPowerOff(void)
{
    SC_MMU_CFG2 = 0x00;
    SC_DRAM_INTERFACE_LO = 0x88;
    SC_MMU_DLL_CTRL = 0x00;
    SC_POWER_CTRL2 &= ~BIT2;
}

#endif //ENABLE_MMU == ON
