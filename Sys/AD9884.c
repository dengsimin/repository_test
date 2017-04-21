/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/
/******************************************************************************/
/*       AD9884.c                                                           */
/*       Release Date:2010/10/15       Last Maintenance:2010/10/15           */
/*       Original Version:2.2.00       Last Version:2.2.00                    */
/*       Coding By: Samuel Su          Maintenance By: Samuel Su              */
/******************************************************************************/

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "Include.h"
#include "FpgaIIC.h"

#if defined(ENABLE_FPGA_MODE)
//******************************************************************************
// G L O B A L   D E F I N I T I O N S
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
// Prototype: 
//  void AD9884_Init(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Make a delay
// Notes:
//  None
//******************************************************************************
void AD9884_Init(void)
{
    code UCHAR ad9884_init_table[] = {
        0x00, 0x69, 0x80, 0xC8, 0x80, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40,
        0x00, 0x20, 0x18, 0x20, 0x18, 0x0A, 0x00, 0x00, 0xA0, 0x08, 0x14, 0x5B, 0xFF, 0x78, 0x30, 0x95, //94->95  non SOG
//        0x00, 0x20, 0x58, 0x20, 0x18, 0x0A, 0x00, 0x00, 0xA0, 0x08, 0x14, 0x5B, 0xFF, 0x78, 0x30, 0x95, //94->95  SOG
//        0x00, 0x20, 0x58, 0x20, 0x18, 0x0A, 0x00, 0x00, 0xAA, 0x08, 0x14, 0x5B, 0xFF, 0x78, 0x30, 0x95, //94->95  YPbPr
        0x0A, 0x20, 0x32, 0x0A, 0xA3, 0xFD, 0x31, 0xB0, 0xBF, 0x0A, 0x00, 0x00, 0x00, 0xF0, 0x30, 0x00,
        0xFF, 0x96, 0x0D, 0x95, 0xB0, 0xF0, 0x00, 0x80, 0x80, 0x00, 0xC0, 0x0A
    };

    FpgaWriteIICSeq(0x98, 0x00, sizeof(ad9884_init_table), ad9884_init_table);
}

//******************************************************************************
// Prototype: 
//  void AD9884_SetHTotal(USHRT HTotal)
// Parameters:
//  HTotal : Input HTotal
// Return:
//  None
// Purpose:
//  Setup AD9884 PLL
// Notes:
//  None
//******************************************************************************
void AD9884_SetHTotal(USHRT HTotal)
{
    ULONG pix_clk;
    UCHAR buff[2];

    buff[0] = (UCHAR) (HTotal>>4);
    buff[1] = (UCHAR) (HTotal<<4);

    FpgaWriteIICSeq(0x98, 0x01, 2, buff);

    pix_clk = (ULONG) HTotal * InputTiming.usHSyncFreq;

    if (pix_clk < 320000) {
        buff[0] = 0x08;
    }
    else if (pix_clk < 640000) {
        buff[0] = 0x48;
    }
    else if (pix_clk < 1280000) {
        buff[0] = 0x88;
    }
    else {
        buff[0] = 0xC8;
    }
    FpgaWriteIICSeq(0x98, 0x03, 1, buff);
}

//******************************************************************************
// Prototype: 
//  USHRT AD9884_GetHTotal(void)
// Parameters:
//  None
// Return:
//  HTotal
// Purpose:
//  Get AD9884 HTotal
// Notes:
//  None
//******************************************************************************
USHRT AD9884_GetHTotal(void)
{
    USHRT htotal;
    UCHAR buff[2];

    FpgaReadIICSeq(0x98, 0x01, 2, buff);

    htotal = buff[0];
    htotal <<= 4;
    htotal += (buff[1] >> 4);

    return htotal;
}

//******************************************************************************
// Prototype: 
//  void AD9884_SetPhase(UCHAR phase)
// Parameters:
//  phase: ADCPLL phase
// Return:
//  None
// Purpose:
//  Set the ADC phase
// Notes:
//  None
//******************************************************************************
void AD9884_SetPhase(UCHAR phase)
{
    UCHAR buff[1];

    buff[0] = (phase << 2);

    FpgaWriteIICSeq(0x98, 0x04, 1, buff);
}

//******************************************************************************
// Prototype: 
//  UCHAR AD9884_GetPhase(void)
// Parameters:
//  phase: ADCPLL phase
// Return:
//  None
// Purpose:
//  Get the ADC phase
// Notes:
//  None
//******************************************************************************
UCHAR AD9884_GetPhase(void)
{
    UCHAR buff[1];

    FpgaReadIICSeq(0x98, 0x04, 1, buff);

    return (buff[0] >> 2);
}

//******************************************************************************
// Prototype: 
//  void AD9884_SetGain(UCHAR rgb, UCHAR gain)
// Parameters:
//  phase: ADCPLL phase
// Return:
//  None
// Purpose:
//  Set the ADC phase
// Notes:
//  None
//******************************************************************************
void AD9884_SetGain(UCHAR rgb, UCHAR gain)
{
    UCHAR buff[2];

    buff[0] = ((gain&0xff)>>1);
    buff[1] = 0;//(gain&0x01)<<7;

    FpgaWriteIICSeq(0x98, 0x05+rgb*2, 2, buff);
}

UCHAR AD9884_GetGain(UCHAR rgb)
{
    UCHAR buff[2];
    
    FpgaReadIICSeq(0x98, 0x05+rgb*2, 2, buff);
    Sleep(40);
    return buff[0]<<1;
}

//******************************************************************************
// Prototype: 
//  void AD9884_SetOffset(UCHAR rgb, UCHAR offset)
// Parameters:
//  phase: ADCPLL phase
// Return:
//  None
// Purpose:
//  Set the ADC phase
// Notes:
//  None
//******************************************************************************
void AD9884_SetOffset(UCHAR rgb, UCHAR offset)
{
    UCHAR buff[2];

    buff[0] = offset;//(offset&0xff);
    buff[1] = 0x00;
    
    FpgaWriteIICSeq(0x98, 0x0B+rgb*2, 2, buff);
}

//******************************************************************************
// Prototype: 
//  UCHAR AD9884_GetOffset(UCHAR rgb)
// Parameters:
//  phase: ADCPLL phase
// Return:
//  None
// Purpose:
//  Set the ADC phase
// Notes:
//  None
//******************************************************************************
UCHAR AD9884_GetOffset(UCHAR rgb)
{
    UCHAR buff[2];
    
    FpgaReadIICSeq(0x98, 0x0B+rgb*2, 2, buff);
    Sleep(40);
    return buff[0];
}


void SetExtDPLL(ULONG clock)
{
/*
    UCHAR buff[5];
    ULONG temp;

	buff[0] = 0x00;//WriteIIC560(0x0f0,0x00);
    FpgaReadIICSeq(0xB2, 0xFF, 1, buff);

	buff[0] = 0x00;//WriteIIC560(0x0f0,0x00);
	buff[1] = 0x10;//WriteIIC560(0x0f1,0x10);
	temp = ((float)clock * 16384) / 1500000;
	buff[2] = (UCHAR)temp;//WriteIIC560(0x0f2,(unsigned char)temp);
	buff[3] = (UCHAR)(temp >> 8);//WriteIIC560(0x0f3,(unsigned char)(temp >> 8));
	buff[4] = (UCHAR)(temp >> 16);//WriteIIC560(0x0f4,(unsigned char)(temp >> 16));
    FpgaReadIICSeq(0xB2, 0xF0, 5, buff);
	buff[0] = 0x01;//WriteIIC560(0x0f0,0x01);
    FpgaReadIICSeq(0xB2, 0xF0, 1, buff);
*/
    ULONG temp;
    UCHAR buff[3];

    temp = ((float)clock * 131072) / REF_CLK;
    buff[0] = 0x00;
    FpgaWriteIICSeq(0xB2, 0xFF, 1, buff);
    Sleep(2);
    buff[0] = 0x00;
    FpgaWriteIICSeq(0xB2, 0xF0, 1, buff);
    Sleep(2);
    buff[0] = 0x10;
    FpgaWriteIICSeq(0xB2, 0xF1, 1, buff);
    Sleep(2);
    buff[0] = (UCHAR) temp;
    buff[1] = (UCHAR) (temp >> 8);
    buff[2] = (UCHAR) (temp >> 16);
    FpgaWriteIICSeq(0xB2, 0xF2, 3, buff);
    Sleep(2);
    buff[0] = 0x01;
    FpgaWriteIICSeq(0xB2, 0xF0, 1, buff);
    Sleep(2);
//    SetLvdsP2SByDCLK();
}

#endif
