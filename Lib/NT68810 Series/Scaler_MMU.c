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
#define MMUDRAMIF_NUM     11
#define MMUDQSDelay_NUM   11 
#define MMUPLL_NUM        16
#define MMUPLLSKEW_NUN    4
#define MMUPLLFREQ_NUM    4

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
static void MMUCalculateBW(USHRT frchtot);

//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
void MMUConfigFIFO();
//******************************************************************************
// F U N C T I O N   B O D Y S
//******************************************************************************

/**************************************************************************//**
 * Get MMU DRAM I/F Control Setting
 ******************************************************************************/
UCHAR GetMMUDRAMIF(UCHAR point)
{
//    UCHAR ucSCID = GetSCID();
    code UCHAR MMUDRAMIF[][MMUDRAMIF_NUM]={
       //=======[ 810 ]========     
       SCREG_580,
       SCREG_581,
       SCREG_582,
       SCREG_583,
       SCREG_584,
       SCREG_585,
       SCREG_586,
       SCREG_587,
       SCREG_588,
       SCREG_589,
       SCREG_58A, 
     }; 

     return MMUDRAMIF[0][point];   
}
        
/**************************************************************************//**
 * Get MMU DQS Delay Control Setting
 ******************************************************************************/
UCHAR GetMMUDQSDelay(UCHAR point)
{
 //   UCHAR ucSCID = GetSCID();
    code UCHAR MMUDQSDelay[][MMUDQSDelay_NUM]={
     //=======[ 810 ]========     
       SCREG_5F0,
       SCREG_5F1,
       SCREG_5F2,
       SCREG_5F3,
       SCREG_5F4,
       SCREG_5F5,
       SCREG_5F6,
       SCREG_5F7,
       SCREG_5F8,
       SCREG_5F9,
       SCREG_5FA, 
     }; 
        
         
     return MMUDQSDelay[0][point];   
}

/**************************************************************************//**
 * Get MMU PLL Control Setting
 ******************************************************************************/
UCHAR GetMMUPLL(UCHAR point)
{
//    UCHAR ucSCID = GetSCID();
    code UCHAR MMUPLL[][MMUPLL_NUM]={
     //=======[ 810 ]========     
       SCREG_B80,
       SCREG_B81,
       SCREG_B82,
       SCREG_B83,
       SCREG_B84,
       SCREG_B85,
       SCREG_B86,
       SCREG_B87,
       SCREG_B88,
       SCREG_B89,
       SCREG_B8A,
       SCREG_B8B,
       SCREG_B8C,
       SCREG_B8D,
       SCREG_B8E,
       SCREG_B8F, 
     };   

     return MMUPLL[0][point];   
}

/**************************************************************************//**
 * Get MMU PLL SKEW Setting
 ******************************************************************************/
UCHAR GetMMUPLLSKEW(UCHAR point)
{
//    UCHAR ucSCID = GetSCID();
    code UCHAR MMUPLLSKEW[][MMUPLLSKEW_NUN]={
     //=======[ 810 ]========     
       SCREG_B90,
       SCREG_B91,
       SCREG_B92,
       SCREG_B93,
     };   

    return MMUPLLSKEW[0][point];   
}

/**************************************************************************//**
 * Get Memory PLL Frequency Control Setting
 ******************************************************************************/
UCHAR GetMMUPLLFREQ(UCHAR point)
{
//    UCHAR ucSCID = GetSCID();
    code UCHAR MMUPLLFREQ[][MMUPLLFREQ_NUM]={
     //=======[ 810 ]========     
       SCREG_B31,
       SCREG_B32,
       SCREG_B33,
       SCREG_B34,
     };  

    return MMUPLLFREQ[0][point];   
}
        
/**************************************************************************//**
 * Initialize MMU-related registers.
 ******************************************************************************/
void MMUInitialize(void)
{
UCHAR volatile xdata *ptr;
UCHAR i;
    ptr = 0x8B31;
    for (i=0; i<MMUPLLFREQ_NUM; i++) {
        *ptr = GetMMUPLLFREQ(i);
        ptr++;
    }

    ptr = &SC_DRAM_INTERFACE_LO;//0x8580;
    for (i=0; i<MMUDRAMIF_NUM; i++) {
        *ptr = GetMMUDRAMIF(i);
        ptr++;
    }
        
        
    ptr = &SC_MMU_DLL_CTRL;//0x8B80;
    for (i=0; i<MMUPLL_NUM; i++) {
        *ptr = GetMMUPLL(i);
        ptr++;
    }
        
    ptr = &SC_DRAM_CLOCK_CTRL; //0x85F0;
    for (i=0; i<MMUDQSDelay_NUM; i++) {
        *ptr = GetMMUDQSDelay(i);
        ptr++;
    }

    ptr = &SC_MMU_PLL_SKEW5;//0x8B90;
    for (i=0; i<MMUPLLSKEW_NUN; i++) {
        *ptr = GetMMUPLLSKEW(i);
        ptr++;
    }
    


#if IS_NT68870_SERIES
    SC_MMU_B85 |= BIT7;
    SC_MMU_B85 &= ~BIT7;
    SC_MMU_B4E = 0x80;
#endif

    SC_DVI2_ZERO_POWER_DETECT = SCREG_B5E;
//    SC_DRAM_INTERFACE_LO &= BIT0;
//    SC_DRAM_INTERFACE_LO |= BIT0;

    
    MMUPowerOn();
    
    MMUConfigFIFO();
#if IS_NT68810_SERIES
    Write3ByteScaler(&SC_FRAME_BUFFER1_BASE_ADDR_POSTFRC_LO, 0x00000000);
    Write3ByteScaler(&SC_FRAME_BUFFER2_BASE_ADDR_POSTFRC_LO, 0x00040000);
    Write3ByteScaler(&SC_FRAME_BUFFER_BASE_ADDR_OD_LO, 0x00060000);
#else
    Write3ByteScaler(&SC_FRAME_BUFFER1_BASE_ADDR_POSTFRC_LO, 0x00020000);
    Write3ByteScaler(&SC_FRAME_BUFFER1_BASE_ADDR_PREFRC_LO, 0x00020000);
    Write3ByteScaler(&SC_FRAME_BUFFER2_BASE_ADDR_POSTFRC_LO, 0x00080000);
    Write3ByteScaler(&SC_FRAME_BUFFER2_BASE_ADDR_PREFRC_LO, 0x00080000);
    Write3ByteScaler(&SC_FRAME_BUFFER_BASE_ADDR_OD_LO, 0x00000000);
#endif
}

/**************************************************************************//**
 * Set MMU FIFO.
 ******************************************************************************/
void MMUConfigFIFO()
{
    code UCHAR ucFIFOAddr[] = {
        0x56, 0x57, 0x58, 0x59,

        0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9C, 0x9D, 0x9E,
        0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB,
        0xBC, 0xBD, 0xBE, 0xBF, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4,
    };
#if IS_NT68810_SERIES
    code UCHAR ucFIFOValue[] = {
        0xDF,    //0x8556
        0x03,    //0x8557
        0xDF,    //0x8558
        0x03,    //0x8559

        0x3F,    //0x8595
        0xEF,    //0x8596
        0xAF,    //0x8597
        0x17,    //0x8598
        0x9F,    //0x8599
        0x17,    //0x859A
        0x00,    //0x859C
        0x00,    //0x859D
        0x00,    //0x859E

        0x00,    //0x85A3
        0x00,    //0x85A4
        0xD0,    //0x85A5
        0x00,    //0x85A6
        0x00,    //0x85A7
        0xAF,    //0x85A8
        0x00,    //0x85A9
        0x00,    //0x85AA
        0x00,    //0x85AB

        0x01,    //0x85BC
        0x00,    //0x85BD
        0xD0,    //0x85BE
        0x00,    //0x85BF
        0x00,    //0x85C0
        0xAF,    //0x85C1
        0x00,    //0x85C2
        0x00,    //0x85C3
        0x00,    //0x85C4
    };
#else
    code UCHAR ucFIFOValue[] = {
        0xDF,    //0x8556
        0x03,    //0x8557
        0xDF,    //0x8558
        0x03,    //0x8559

        0x4F,    //0x8595
        0xBF,    //0x8596
        0x9F,    //0x8597
        0x3F,    //0x8598
        0xBF,    //0x8599
        0x47,    //0x859A
        0x4F,    //0x859C
        0xBF,    //0x859D
        0x9F,    //0x859E

        0x13,    //0x85A3
        0x40,    //0x85A4
        0xBF,    //0x85A5
        0x01,    //0x85A6
        0x00,    //0x85A7
        0x3F,    //0x85A8
        0x13,    //0x85A9
        0x40,    //0x85AA
        0xBF,    //0x85AB

        0x13,    //0x85BC
        0x40,    //0x85BD
        0xBF,    //0x85BE
        0x01,    //0x85BF
        0x00,    //0x85C0
        0x3F,    //0x85C1
        0x13,    //0x85C2
        0x40,    //0x85C3
        0xBF,    //0x85C4
    };
#endif
    UCHAR i;
    UCHAR xdata * ptr;

    ptr = 0x8500;

    for (i = 0; i < sizeof(ucFIFOAddr); i++) {
        ptr = (UCHAR xdata *)(0x8500 + ucFIFOAddr[i]);
        *ptr = ucFIFOValue[i];
    }
}

/**************************************************************************//**
 * Turn on MMU power.
 ******************************************************************************/
void MMUPowerOn(void)
{
    SC_DRAM_MMU_REQUEST_W = 0x00;
    SC_DRAM_MMU_REQUEST_R = 0x00;
    SC_POWER_CTRL2 |= BIT2;
    SC_MCLK_RATIO_HI = GetMMUPLLFREQ(2);//SCREG_B33_G;
    SC_MMU_DLL_CTRL = GetMMUPLL(0);//SCREG_B80;
    SC_MMU_B84 = GetMMUPLL(4);//SCREG_B84;
    SC_DRAM_INTERFACE_LO = GetMMUDRAMIF(0);//SCREG_580;
    SC_DRAM_INTERFACE_HI = GetMMUDRAMIF(1);//SCREG_581;

    SC_MMU_CFG2 = 0x01;

}

/**************************************************************************//**
 * Turn off MMU power.
 ******************************************************************************/
void MMUPowerOff(void)
{
    UCHAR ucSCID=GetSCID();
    SC_OD_CONFIGURATION = 0x00;
    SC_FRC_CTRL = 0x00;
    SC_MMU_CFG2 = 0x00;
    SC_AUTO_REFLESH_CTRL = 0x00;
    SC_DRAM_MMU_REQUEST_W = 0xFF;
    SC_DRAM_MMU_REQUEST_R = 0xFF;
    SC_DRAM_MMU_MODE_2 = 0x01;
    if ((ucSCID >= SCID_850_D && ucSCID <= SCID_850_FINAL) || \
        (ucSCID >= SCID_770_H && ucSCID <= SCID_770_FINAL)) {
        SC_DRAM_INTERFACE_HI = 0x13 | BIT6;
    }
    else {
        SC_DRAM_INTERFACE_HI = 0x13;
    }
    SC_DRAM_INTERFACE_LO &= ~BIT0;//= (SCREG_580&~BIT0);
    SC_MMU_DLL_CTRL = 0x00;
    SC_MMU_B84 = 0x00;
    SC_POWER_CTRL2 &= ~BIT2;
    SC_MCLK_RATIO_HI = 0x00;
}


#if ENABLE_AUTO_CONTROL == ON
#if (IS_NT68770_SERIES || IS_NT68850_SERIES || IS_NT68790_SERIES || IS_NT68810_SERIES || IS_NT68870_SERIES)
//return 32 if CheckDRAM pass.
UCHAR CheckDRAM(void)
{
    UCHAR i, k;
    SC_OD_CONFIGURATION &= ~BIT0;//disable OD
    Write3ByteScaler(&SC_LINE_BUFFER_BASE_ADDR_LO, 0);
    WriteShortScaler(&SC_LINE_WRITE_SRAM_CTRL_LO, 0);
    WriteShortScaler(&SC_LINE_READ_SRAM_CTRL_LO, 0);

    SC_DRAM_LINE_BUFFER_BASE_QUANTITY = 0x03;//96 bit x 3 / 8 = 36 byte
    SC_DRAM_LINE_BUFFER_CTRL = 0x80;
//    while (SC_DRAM_LINE_BUFFER_CTRL != 0x00) {};//ready
    i = 100;
    while ((SC_DRAM_LINE_BUFFER_CTRL != 0x00) && (i != 0)) {//ready
        Sleep(1);
        i--;
    }
    SC_DRAM_LINE_BUFFER_CTRL = 0x01;//Line write mode use FIFO write
    for (i=0; i<36; i++) {
        SC_DRAM_LINE_BUFFER_DATA_PORT = i;
    }
//    while (SC_DRAM_LINE_BUFFER_CTRL != 0x00) {};//ready
    i = 100;
    while ((SC_DRAM_LINE_BUFFER_CTRL != 0x00) && (i != 0)) {//ready
        Sleep(1);
        i--;
    }
    SC_DRAM_LINE_BUFFER_CTRL = 0x42;//Line read mode use FIFO read
    k = 0;
    for (i=0; i<32; i++) {
        if (SC_DRAM_LINE_BUFFER_DATA_PORT == i) {
            k++;
        }
    }
    return k;
}
#endif
#endif

#endif //ENABLE_MMU == ON
