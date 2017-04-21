/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/
/* DisplayPort Transmit function control										  			*/
/* Date : 2012/11/21 First version By David Luo / iHome-SC/SA1			 			*/
/******************************************************************************/
//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "Include.h"
#if ENABLE_EDP == ON
#include "DPTX.h"
//******************************************************************************
// G L O B A L   D E F I N I T I O N S
//******************************************************************************
#define EDP_RCK_12MHz   1//A version: 1, 
#define DPTX_AUX_BURST_MODE 1
#define DP_SPEC_TRAINING
#define DPTX_INT_DISABLE    1
#define STROBE_MAX_LENGTH	17
#define RBR					162			// 1.62G
#define HBR					270			// 2.7G
#define HBR2				540			// 5.4G

// eDP setting
#define BANDWIDTH_EDP			HBR//RBR
#define LANECOUNT_EDP			4				// 1, 2, 4 (only 3 items can be defined)
#define ENHANCE_FRAME_EDP		1				// 1: enhance frame mode = 1,  0: enhance frame mode = 0
#if (BANDWIDTH_EDP == RBR)
#define LINK_BW_SET_EDP		0x06
#elif (BANDWIDTH_EDP == HBR)
#define LINK_BW_SET_EDP		0x0a
#elif (BANDWIDTH_EDP == HBR2)
#define LINK_BW_SET_EDP		0x14
#else
#define LINK_BW_SET_EDP		0x06
#endif
#define LANE_COUNT_SET_EDP		(ENHANCE_FRAME_EDP<<7|LANECOUNT_EDP)



// Only for test "TCON eDP Panel" (David)
#define LV_SWING0		0x05
#define LV_SWING1		0x08
#define LV_SWING2		0x0E   //0x0D -> 0x0E Austin
#define LV_MAIN0		0x04
#define LV_MAIN1		0x05
#define LV_MAIN2		0x06
#define LV_PRE0		0x00
#define LV_PRE1		0x10
#define LV_PRE2		0x20

//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************
UCHAR dpcd_buf[16];// change from 6 to 16. (David.2013/10/25)
UCHAR ucEDPBandLane[2];
    #define band 0
    #define lane 1
UCHAR ucDpTxAuxStrobeIndex = 0;
UCHAR ucDpTxAuxStrobeBuf[STROBE_MAX_LENGTH];
BOOL bDPTXAuxStrobeReady = FALSE;
BOOL bDPTXHPD_IRQ = FALSE;
xdata UCHAR ucDPCDTx[6];
UCHAR ucDPTXBW = 0;
#if ENABLE_DPTX_LINK_CTS == ON
UCHAR bBitRateReduce = FALSE;
#endif
extern bit bReTraning ;
//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************

//******************************************************************************
// E X T E R N A L   V A R I A B L E   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// S T A T I C   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
void DPTxAUXReqRoutine(UCHAR cmd, ULONG Addr, char leng, UCHAR *d);
#if ENABLE_DPTX_LINK_CTS == ON
void ReadEDID(void);
#endif
//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
extern void delay250us(void);

// DP TX PHY Initial
void InitOutputMPLL(void)
{
    // Set DP eDP TX MPLL
    if (SC_COMBO_TX_1E00[0x00] == 0x86) {//edp out
    #if (BANDWIDTH_EDP == RBR)
        SC_EDP_PLL_LO = 0x00;
        SC_EDP_PLL_MI = 0x80;
        SC_EDP_PLL_HI = 0x0D;
    #elif (BANDWIDTH_EDP == HBR)
        SC_EDP_PLL_LO = 0x00;
        SC_EDP_PLL_MI = 0x80;//0x00;
        SC_EDP_PLL_HI = 0x16;//0x2D;
    #elif (BANDWIDTH_EDP == HBR2)
        SC_EDP_PLL_LO = 0x00;
        SC_EDP_PLL_MI = 0x00;
        SC_EDP_PLL_HI = 0x2D;
    #endif
//eDP SSC
//        SC_EDP_MAN_CLK_SSC= 0xB0;//Addr = 0x8B4B; *Addr = 0xB0;
//        SC_EDP_MAN_CLK_SSC_RATIO= 0x01;//Addr = 0x8B4C; *Addr = 0x01;
//        SC_EDP_CLK_SSC = 0x0B;//Addr = 0x8B4A; *Addr = 0x0B;
//        SC_EDP_PLL_CTRL &= 0xF0;// fine ssc ctrl
        //
        if ((SC_EDP_TX_DPHY_1F00[0x20] & 0x03) == 0x03) {
           	Sleep(20);
            //printf("DP TX eDP MPLL ready!\r\n");
        }
    }
}

// DP TX PHY Initial
void InitDPTxPHY(void)
{
//eDP
#if (BANDWIDTH_EDP == HBR2)
    SC_COMBO_TX_1E00[0x34] = 0x4D;//WRITE	B0	6834	4D
#else
    SC_COMBO_TX_1E00[0x34] = 0x43;
#endif

    SC_EDP_TX_DPHY_1F00[0x60] = 0x00;//WRITE	B0	6960	00
    SC_EDP_TX_DPHY_1F00[0x09] = (SC_EDP_TX_DPHY_1F00[0x09] & BIT3) | 0x80;//WRITE	B0	6909	80
    SC_EDP_TX_DPHY_1F00[0x0C] = 0x10;//WRITE	B0	690C	10
    SC_EDP_TX_DPHY_1F00[0x0D] = 0x08;//WRITE	B0	690D	08
    //SC_EDP_TX_DPHY_1F00[0x60] = 0x80;//WRITE	B0	6960	80
    //SC_EDP_TX_DPHY_1F00[0x09] = (SC_EDP_TX_DPHY_1F00[0x09] & BIT3) | 0x80;//WRITE	B0	6909	80
    //SC_EDP_TX_DPHY_1F00[0x0C] = 0x10;//WRITE	B0	690C	10
    //SC_EDP_TX_DPHY_1F00[0x0D] = 0x08;//WRITE	B0	690D	08
    Sleep(1);//Sleep			1
    SC_EDP_TX_DPHY_1F00[0x64] = 0x07;//WRITE	B0	6964	07
    SC_EDP_TX_DPHY_1F00[0x62] |= BIT3;
    SC_EDP_TX_DPHY_1F00[0x63] = 0x95;//(Leon)0x94;//WRITE	B0	6963	94
}

// DP TX LINK Initial
void InitDPTxLINK(void)
{
    SC_EDP_LINK_1300[_DPTX_MODE_CTRL_75] |= BIT7;
    
    SC_EDP_LINK_1300[_DPTX_LINK_BW_SET] = LINK_BW_SET_EDP;
    SC_EDP_LINK_1300[_DPTX_LANE_COUNT_SET] = ((SC_EDP_LINK_1300[_DPTX_LANE_COUNT_SET] & BIT6) | LANE_COUNT_SET_EDP);
    ucEDPBandLane[band] = LINK_BW_SET_EDP;
    ucEDPBandLane[lane] = LANE_COUNT_SET_EDP;
    
    SC_EDP_LINK_1300[_DPTX_CAL_TH] = 0xFE;		// V, H timing calculator variation threshold
    //SC_EDP_LINK_1300[_DPTX_MISC1_CTRL] |= BIT7;
    SC_EDP_LINK_1300[_DPTX_MODE_CTRL_76] |= BIT2;
    SC_EDP_LINK_1300[_DPTX_6218] |= (BIT4 | BIT0); //1366x768
}

// DP TX AUX channel initial
void InitDPTxAUX(void)
{
    SC_EDP_LINK_1300[0xB0] = 0xC7;
    SC_EDP_LINK_1300[0xB1] = 0x41;
    SC_EDP_LINK_1300[0xB2] = 0x04;
    SC_EDP_LINK_1300[0xB3] = 0x00;

    SC_EDP_LINK_1300[_EDP_AUX_PHY_CTRL_B0] &= ~BIT4;
    SC_EDP_LINK_1300[_EDP_AUX_PHY_CTRL_B0] |= BIT2;
    SC_EDP_LINK_1300[_EDP_AUX_PHY_CTRL_B3] &= 0xE0;

    SC_EDP_LINK_1300[_DPTX_AUX_RETRY_NUM] = 0;		// disable retry
    SC_EDP_LINK_1300[_DPTX_AUX_CTRL] = (DPTX_AUX_MANUAL_EN | DPTX_AUX_BUF_AUTO_RST | DPTX_AUX_W_PTR_RST | DPTX_AUX_R_PTR_RST);
    SC_EDP_LINK_1300[_DPTX_AUX_STROBE_CTL] = (DPTX_AUX_STROBE_EN | DPTX_AUX_STROBE_RST | DPTX_AUX_STROBE_WRITE);
    SC_EDP_LINK_1300[_DPTX_AUX_STROBE_CTL] = (DPTX_AUX_STROBE_EN | DPTX_AUX_STROBE_WRITE | BIT7);
    SC_EDP_LINK_1300[_DPTX_AUX_INT_EN] = (DPTX_AUX_INT_STROBE_EN);
    
    bDPTXAuxStrobeReady = FALSE;
}

void DPTxAUXReqRoutine(UCHAR cmd, ULONG Addr, char leng, UCHAR *d)
{
    UCHAR i;

    if (leng == 0) {
        SC_EDP_LINK_1300[_DPTX_AUX_CTRL] = 0x71;//(DPTX_AUX_MANUAL_EN |/*DPTX_AUX_BUF_AUTO_RST |*/ DPTX_AUX_W_PTR_RST | DPTX_AUX_R_PTR_RST |DPTX_AUX_BUF_RST);
    }
    else {
        SC_EDP_LINK_1300[_DPTX_AUX_CTRL] = 0x71;//0xE9;//0x71;//(DPTX_AUX_MANUAL_EN |/*DPTX_AUX_BUF_AUTO_RST |*/ DPTX_AUX_W_PTR_RST | DPTX_AUX_R_PTR_RST |DPTX_AUX_BUF_RST);
    }
    SC_EDP_LINK_1300[_DPTX_AUX_DATA] = (cmd & 0xF0) | ((Addr >> 16) & 0x0F);
    SC_EDP_LINK_1300[_DPTX_AUX_DATA] = (Addr >> 8) & 0xFF;
    SC_EDP_LINK_1300[_DPTX_AUX_DATA] = (Addr & 0xFF);
    if (cmd == NATIVE_AUX_W || cmd == I2C_AUX_MOT_W || cmd == I2C_AUX_W) {
        SC_EDP_LINK_1300[_DPTX_AUX_DATA] = leng;//0;
        for (i = 0; i <= leng; i++) {
            SC_EDP_LINK_1300[_DPTX_AUX_DATA] = *(d + i);
        }
        SC_EDP_LINK_1300[_DPTX_AUX_CTRL] = 0x0B;//|= DPTX_AUX_MANUAL_START;
    }
    else { // NATIVE_AUX, I2C_AUX_MOT_R, I2C_AUX_R
        SC_EDP_LINK_1300[_DPTX_AUX_DATA] = leng;//0;
        if (leng == 0) {
            SC_EDP_LINK_1300[_DPTX_AUX_CTRL] = 0x03;//0x0B;//|= DPTX_AUX_MANUAL_START;
        }
        else {
            SC_EDP_LINK_1300[_DPTX_AUX_CTRL] = 0x0B;//|= DPTX_AUX_MANUAL_START;
        }
    }
#if ENABLE_DPTX_LINK_CTS == ON
    Sleep(2);		// wait for Rx reply //for CTS EDID defer
#else
    Sleep(1);		// wait for Rx reply
#endif
}

// AUX Write one Byte
UCHAR DPTxAUXReqWRByte(UCHAR cmd, ULONG Addr, UCHAR d)
{
#if EDP_RCK_12MHz == OFF
    UCHAR temp;
#endif
    UCHAR retry;

    for (retry = 0; retry < AUX_RETRY; retry++) {
        DPTxAUXReqRoutine(cmd, Addr, 0, &d);

#if EDP_RCK_12MHz == ON
        return AUX_ACK;
#else
        ucDpTxAuxStrobeIndex = 0;
        while (SC_EDP_LINK_1300[_DPTX_AUX_INT_FLG] & DPTX_AUX_INT_STROBE_FLG) {
            if (ucDpTxAuxStrobeIndex < STROBE_MAX_LENGTH) {
                ucDpTxAuxStrobeBuf[ucDpTxAuxStrobeIndex++] = SC_EDP_LINK_1300[_DPTX_AUX_STROBE_PORT];
            }
            else {	// out of data to read.
                temp = SC_EDP_LINK_1300[_DPTX_AUX_STROBE_PORT];
            }
            SC_EDP_LINK_1300[_DPTX_AUX_INT_FLG] |= DPTX_AUX_INT_STROBE_FLG;
        }
        if (ucDpTxAuxStrobeBuf[0] == AUX_ACK) {	// RX AUX ACK
            if (ucDpTxAuxStrobeIndex <= 1) {
                return AUX_ACK;					//
            }
            else {
                return 0xFF;					// Error
            }
        }
        else if (ucDpTxAuxStrobeBuf[0] == AUX_DEFER) {
            continue;
        }
        else {
            //return ucDpTxAuxStrobeBuf[0];	// Error.
            //printf("Rx Error W<%02bx>\r\n", ucDpTxAuxStrobeBuf[0]);
            continue;
        }
#endif
    }
    return 0xFF;		// Error code:retry over 10 times
}

// AUX Read one Byte
UCHAR DPTxAUXReqRDByte(UCHAR cmd, ULONG Addr, UCHAR *d)
{
#if EDP_RCK_12MHz == OFF
    UCHAR temp;
#endif
    UCHAR retry;


    for (retry = 0; retry < AUX_RETRY; retry++) {
        DPTxAUXReqRoutine(cmd, Addr, 0, d);

#if EDP_RCK_12MHz == ON
        *d = 0x00;
        return AUX_ACK;
#else
        if (1) { //if (SC_COP_INT_SRC & intbit) {
            ucDpTxAuxStrobeIndex = 0;
            while (SC_EDP_LINK_1300[_DPTX_AUX_INT_FLG] & DPTX_AUX_INT_STROBE_FLG) {
                if (ucDpTxAuxStrobeIndex < 2) {
                    ucDpTxAuxStrobeBuf[ucDpTxAuxStrobeIndex++] = SC_EDP_LINK_1300[_DPTX_AUX_STROBE_PORT];
                }
                else {	// out of data to read.
                    temp = SC_EDP_LINK_1300[_DPTX_AUX_STROBE_PORT];
                }
                SC_EDP_LINK_1300[_DPTX_AUX_INT_FLG] |= DPTX_AUX_INT_STROBE_FLG;
            }
            if (ucDpTxAuxStrobeBuf[0] == AUX_ACK) {	// RX AUX ACK
                if (ucDpTxAuxStrobeIndex <= 2) {
                    *d = ucDpTxAuxStrobeBuf[1];
                    return AUX_ACK;					//
                }
                else {
                    return 0xFF;					// Error
                }
            }
            else if (ucDpTxAuxStrobeBuf[0] == AUX_DEFER) {
                continue;
            }
            else {
                //return ucDpTxAuxStrobeBuf[0];	// Error.
                //printf("Rx Error R<%02bx>\r\n", ucDpTxAuxStrobeBuf[0]);
                continue;
            }
        }
        else {
            //return 0xFF;		// Error code: time out
            //printf("read time out\r\n");
            continue;
        }
#endif
    }
    return 0xFF;		// Error code:retry over 10 times
}

BOOL DPTxAUXReqWRStream(UCHAR cmd, ULONG Addr, char leng, UCHAR *str)
{
    UCHAR i;
#if EDP_RCK_12MHz == OFF
    UCHAR temp;
#endif
#if DPTX_AUX_BURST_MODE == 0
    for (i = 0; i <= leng; i++) {
        temp = DPTxAUXReqWRByte(dptx_ch, cmd, Addr++, *str);
        str++;
        if (temp != AUX_ACK) {
            //printf("Rx Error <%02bx>\r\n", temp);
            return FALSE;
        }
    }
    return TRUE;
#else
    UCHAR retry;

    i = 0;


    for (retry = 0; retry < AUX_RETRY; retry++) {
        DPTxAUXReqRoutine(cmd, Addr, leng, str);

#if EDP_RCK_12MHz == ON
        return TRUE;
#else
        if (1) { //if (SC_COP_INT_SRC & intbit) {
            ucDpTxAuxStrobeIndex = 0;
            while (SC_EDP_LINK_1300[_DPTX_AUX_INT_FLG] & DPTX_AUX_INT_STROBE_FLG) {
                if (ucDpTxAuxStrobeIndex < STROBE_MAX_LENGTH) {
                    ucDpTxAuxStrobeBuf[ucDpTxAuxStrobeIndex++] = SC_EDP_LINK_1300[_DPTX_AUX_STROBE_PORT];
                }
                else {	// out of data to read.
                    temp = SC_EDP_LINK_1300[_DPTX_AUX_STROBE_PORT];
                }
                SC_EDP_LINK_1300[_DPTX_AUX_INT_FLG] |= DPTX_AUX_INT_STROBE_FLG;
            }
            if (ucDpTxAuxStrobeBuf[0] == AUX_ACK) {	// RX AUX ACK
                if (ucDpTxAuxStrobeIndex <= 1) {
                    return TRUE;//AUX_ACK;					//
                }
                else {
                    return FALSE;//0xFF;					// Error
                }
            }
            else if (ucDpTxAuxStrobeBuf[0] == AUX_DEFER) {
                continue;
            }
            else {
                //return ucDpTxAuxStrobeBuf[0];	// Error.
                //printf("Rx Error W<%02bx>\r\n", ucDpTxAuxStrobeBuf[0]);
                continue;
            }
        }
        else {
            //return 0xFF;		// Error code: time out
            //printf("write time out\r\n");
            continue;
        }
#endif
    }
    return FALSE;//0xFF;		// Error code:retry over 10 times
#endif
}

#if 1
BOOL DPTxAUXReqRDStream(UCHAR cmd, ULONG Addr, char leng, UCHAR *str)
{
    UCHAR i;
#if EDP_RCK_12MHz == OFF
    UCHAR temp;
#endif
#if DPTX_AUX_BURST_MODE == 0

    for (i = 0; i <= leng; i++) {
        temp = DPTxAUXReqRDByte(cmd, Addr++, str++);
        if (temp != 0) {
            //printf("Rx Error <%02bx>\r\n", temp);
            return FALSE;
        }
    }
    return TRUE;
#else
    UCHAR retry;


    for (retry = 0; retry < AUX_RETRY; retry++) {
        DPTxAUXReqRoutine(cmd, Addr, leng, str);

#if EDP_RCK_12MHz == ON
        if (Addr == 0x000) {
            *(str + 0) = 0x12;
            *(str + 1) = LINK_BW_SET_EDP;
            *(str + 2) = LANE_COUNT_SET_EDP;
            *(str + 3) = 0x01;
            *(str + 4) = 0x01;
            *(str + 5) = 0x00;
            *(str + 6) = 0x01;
            *(str + 7) = 0x00;
            *(str + 8) = 0x02;
            *(str + 9) = 0x00;
            *(str + 10) = 0x02;
            *(str + 11) = 0x00;
        }
        else if (Addr == 0x00E) {
            *(str + 0) = 0x00;
        }
        else if (Addr == 0x200) {
            *(str + 0) = 0x41;
            *(str + 1) = 0x00;
            *(str + 2) = 0x77;
            *(str + 3) = 0x77;
            *(str + 4) = 0x01;
            *(str + 5) = 0x00;
            *(str + 6) = 0x00;
            *(str + 7) = 0x00;
        }
        else if (Addr == 0x202) {
            *(str + 0) = 0x77;
            *(str + 1) = 0x77;
            *(str + 2) = 0x01;
            *(str + 3) = 0x00;
            *(str + 4) = 0x00;
            *(str + 5) = 0x00;
        }
        else {
            for (i = 0; i <= leng; i++) {
                *(str + i) = 0x00;
            }
        }
        return TRUE;
#else
        if (1) { //if (SC_COP_INT_SRC & intbit) {
            ucDpTxAuxStrobeIndex = 0;
            while (SC_EDP_LINK_1300[_DPTX_AUX_INT_FLG] & DPTX_AUX_INT_STROBE_FLG) {
                if (ucDpTxAuxStrobeIndex < STROBE_MAX_LENGTH) {
                    ucDpTxAuxStrobeBuf[ucDpTxAuxStrobeIndex++] = SC_EDP_LINK_1300[_DPTX_AUX_STROBE_PORT];
                }
                else {	// out of data to read.
                    temp = SC_EDP_LINK_1300[_DPTX_AUX_STROBE_PORT];
                }
                SC_EDP_LINK_1300[_DPTX_AUX_INT_FLG] |= DPTX_AUX_INT_STROBE_FLG;
            }
            if (ucDpTxAuxStrobeBuf[0] == AUX_ACK) {	// RX AUX ACK
                if (ucDpTxAuxStrobeIndex <= (leng + 2)) {
                    for (i = 0; i <= leng; i++) {
                        *(str + i) = ucDpTxAuxStrobeBuf[i + 1];
                    }
                    return TRUE;//AUX_ACK;					//
                }
                else {
                    return FALSE;//0xFF;					// Error
                }
            }
            else if (ucDpTxAuxStrobeBuf[0] == AUX_DEFER) {
                continue;
            }
            else {
#if ENABLE_DPTX_LINK_CTS == ON
                retry--;
#endif
                //return ucDpTxAuxStrobeBuf[0];	// Error.
                //printf("Rx Error R<%02bx>\r\n", ucDpTxAuxStrobeBuf[0]);
                continue;
            }
        }
        else {
            //return 0xFF;		// Error code: time out
            //printf("read time out\r\n");
            continue;
        }
#endif
    }
    return FALSE;//0xFF;		// Error code:retry over 10 times
#endif
}
#endif

void DPRxTraining(void)
{
//    UCHAR volatile xdata *Addr;
    UCHAR ret, lane_count, link_bw, rd_interval,TPS3 = 0 ,IterationCnt =3 ,retraining = 0, dptx_link_bw = 0;
    UCHAR train_cnt, level, pre_emphasis;
    UCHAR band_lane[2];
    
    //printf("EDP port C\r\n");
    if ((SC_DISPLAY_CTRL & (BIT4|BIT3)) == BIT4) {//10bit
        SC_EDP_LINK_1300[_DPTX_MISC0] = 0x40;//default RGB 10 bit
    }
    else if ((SC_DISPLAY_CTRL & (BIT4|BIT3)) == BIT3) {//6bit
        SC_EDP_LINK_1300[_DPTX_MISC0] = 0x00;//default RGB 6 bit
    }
    else {
        SC_EDP_LINK_1300[_DPTX_MISC0] = 0x20;//default RGB 8 bit
    }

    if ((SC_EDP_LINK_1300[_DPTX_HPD_CTL] & DPTX_HDP_PULG_STATE) == 0x00) {//go low
        //printf("unplug\r\n");
        return;
    }

    //printf("eDP TX --> RX Training\r\n");
#if LANECOUNT_EDP == 4
    SC_LVDS_CTRL |= BIT1;//4 port
#endif
    SC_DISPLAY_CTRL &= ~BIT1;//sync mode
//    SC_DISPLAY_CTRL |= BIT4;
    SC_DISPLAY_POL_CTRL |= (BIT4 | BIT5);

    train_cnt = 0 ;
    while (DPTxAUXReqWRByte(NATIVE_AUX_W, 0x600, 0x01) != AUX_ACK  && train_cnt < 5) {
        train_cnt++;
    }

    if (train_cnt == 5) {
        //printf("set power error!\r\n");
        return;
    }

    if (DPTxAUXReqRDStream(NATIVE_AUX_R, 0x000, 11, dpcd_buf) == FALSE) {
        //printf("Read DPCD 0x000h --> FALSE!\r\n");
        return;
    }

    //check hpd here: 1. Low 2. low->high   

    if( dpcd_buf[1] >=0x15 && dpcd_buf[1]<=0x28){    //700.1.1.2  
        dpcd_buf[1] =0x14;
    }
    if(dpcd_buf[1]!=0x06  && dpcd_buf[1]!=0x0A && dpcd_buf[1]!=0x14){       
        return;   
    } 

    if ((dpcd_buf[2]&0x1F)!=0x01  && (dpcd_buf[2]&0x1F)!=0x02 && (dpcd_buf[2]&0x1F)!=0x04) {        
        return;   
    }	
    if((dpcd_buf[2]&BIT6) == BIT6){
        TPS3 = 1;
    }
    //printf("link_bw,lane_count, %02BX%02BX\r\n", dpcd_buf[1], dpcd_buf[2]);

    if (DPTxAUXReqRDStream(NATIVE_AUX_R, 0x00E, 0x00, &rd_interval) == TRUE) {	// TRAINING_AUX_RD_INTERVAL
        if (rd_interval >= 1  && rd_interval <= 4) {
            rd_interval = rd_interval * 4;
        }
        else {
            rd_interval = 1;
        }
    }
    else {
        rd_interval = 10;
        //printf("read training rd interval error!\r\n");
    }

    lane_count = dpcd_buf[2];// & 0x07;
    if ((lane_count & 0x8F) > ucEDPBandLane[lane]) {
        lane_count = ucEDPBandLane[lane];
    }
    link_bw = dpcd_buf[1];
    if (link_bw > ucEDPBandLane[band]) {
        link_bw = ucEDPBandLane[band];
    }
    band_lane[band] = ucEDPBandLane[band] = link_bw;
    band_lane[lane] = ucEDPBandLane[lane] = lane_count;

    //if ((lane_count & 0x0F) == 4) { //Ver. >= D must set 0x3B78[1]=1, others don't care. 
        SC_LVDS_CTRL |= BIT1;//4 port
    //}
    //else {
    //    SC_LVDS_CTRL &= ~BIT1;//2 port
    //}
    if (link_bw == 0x14) {
        SC_EDP_PLL_LO = 0x00;
        SC_EDP_PLL_MI = 0x00;
        SC_EDP_PLL_HI = 0x2D;
    }
    else if (link_bw == 0x0A) {
        SC_EDP_PLL_LO = 0x00;
        SC_EDP_PLL_MI = 0x80;
        SC_EDP_PLL_HI = 0x16;
    }
    else {
        SC_EDP_PLL_LO = 0x00;
        SC_EDP_PLL_MI = 0x80;
        SC_EDP_PLL_HI = 0x0D;
    }

    if (link_bw == 0x14) {
        SC_COMBO_TX_1E00[0x34] = 0x4D;//WRITE	B0	6834	4D
    }
    else {
        SC_COMBO_TX_1E00[0x34] = 0x43;
    }
#if 0//check 870
    if ((lane_count & 0x0F)== 1) { // eDP 1 Lane need single port input
        SC_FRC_OUT_SEL |= BIT1;
    }
    else {
        SC_FRC_OUT_SEL &= ~BIT1;
    }
#endif
    SC_EDP_LINK_1300[_DPTX_LINK_BW_SET] = link_bw;
    SC_EDP_LINK_1300[_DPTX_LANE_COUNT_SET] = ((SC_EDP_LINK_1300[_DPTX_LANE_COUNT_SET] & BIT6) | lane_count);
    //printf("X link_bw,lane_count, %02BX%02BX\r\n", SC_EDP_LINK_1300[_DPTX_LINK_BW_SET], SC_EDP_LINK_1300[_DPTX_LANE_COUNT_SET]);

    if (DPTxAUXReqWRStream(NATIVE_AUX_W, 0x100, 1, band_lane) == FALSE) {
        //printf("Write 0x100h --> FALSE!\r\n");
        return;
    }
#if ENABLE_DPTX_LINK_CTS == ON
    Sleep(2);
#endif
///////////////////////////////
//    ResetData();
///////////////////////////////
do{
    //Clork_Recovery
    /*Transmit Training Pattern 1 over Main Link (minimum voltage swing and no preemphasis
    unless optimal setting is already known) and write 01h to TRAINING_PATTERN _SET byte via AUX CH */
    //SC_EDP_TX_DPHY_1F00[0x60] |= BIT7;
    //SC_EDP_TX_DPHY_1F00[0x09] = (SC_EDP_TX_DPHY_1F00[0x09] & 0x7F) | BIT7;
    SC_EDP_TX_DPHY_1F00[0x60] &= ~BIT7;
    SC_EDP_TX_DPHY_1F00[0x09] = (SC_EDP_TX_DPHY_1F00[0x09] & 0x7F) | BIT7;
    SC_EDP_TX_DPHY_1F00[0x63] = (SC_EDP_TX_DPHY_1F00[0x63] & 0x8F) | 0x10;
    SC_COMBO_TX_1E00[0x21] = 0x00;
    SC_COMBO_TX_1E00[0x1C] = 0x00;
    SC_COMBO_TX_1E00[0x5B] = 0x04;

    ucDPCDTx[0] = 0x21;		// train_set 1
    ucDPCDTx[4] = ucDPCDTx[3] = ucDPCDTx[2] = ucDPCDTx[1] = 0x00;    // swing level = 0  pre-emphasis level 0
    if (DPTxAUXReqWRStream(NATIVE_AUX_W, 0x102, (lane_count & 0x0F), ucDPCDTx) == FALSE) {
        //printf("Write 0x102h --> FALSE!\r\n");
        return;
    }
    train_cnt = 0;
    do {
        // Wait for delay specified in TRAINING_AUX_RD_INTERVAL
        Sleep(rd_interval);
        //Read LANEx_CR_DONE bits and ADJUST_REQUESTLANEx. byte
        if (DPTxAUXReqRDStream(NATIVE_AUX_R, 0x200, 7, dpcd_buf) == FALSE) {
            ret = TRAINING_NORESPONSE;
            break;
        }

        if ((lane_count & 0x0F) == 0x04) {
            if ((dpcd_buf[2] & 0x11) == 0x11  &&   (dpcd_buf[3] & 0x11) == 0x11) {
                ret = TRAINING_OK;
                break;
            }
        }
        else if ((lane_count & 0x0F) == 0x02) {
            if ((dpcd_buf[2] & 0x11) == 0x11) {
                ret = TRAINING_OK;
                break;
            }
        }
        else {
            if ((dpcd_buf[2] & 0x01) == 0x01) {
                ret = TRAINING_OK;
                break;
            }
        }
        train_cnt++;
        if (train_cnt >= IterationCnt) { //Set Reduce Bit Rate
            if (link_bw == 0x14) {
                link_bw = 0x0A;
              //  printf("reduce bit rate to 2.7G!\r\n\r\n\r\n");
            }
            else if (link_bw == 0x0A) {
                link_bw = 0x06;
               // printf("reduce bit rate to 1.62G!\r\n\r\n\r\n");
            }
            else {
                ret = TRAINING_FAIL;
                break;
            }
            train_cnt = 0;
            SC_EDP_LINK_1300[_DPTX_LINK_BW_SET] = link_bw;
            SC_EDP_LINK_1300[_DPTX_LANE_COUNT_SET] = ((SC_EDP_LINK_1300[_DPTX_LANE_COUNT_SET] & BIT6) | lane_count);
            if (link_bw == 0x14) {
                SC_EDP_PLL_LO = 0x00;
                SC_EDP_PLL_MI = 0x00;
                SC_EDP_PLL_HI = 0x2D;
            }
            else if (link_bw == 0x0A) {
                SC_EDP_PLL_LO = 0x00;
                SC_EDP_PLL_MI = 0x80;
                SC_EDP_PLL_HI = 0x16;
            }
            else {
                SC_EDP_PLL_LO = 0x00;
                SC_EDP_PLL_MI = 0x80;
                SC_EDP_PLL_HI = 0x0D;
            }

            if (link_bw == 0x14) {
                SC_COMBO_TX_1E00[0x34] = 0x4D;//WRITE	B0	6834	4D
            }
            else {
                SC_COMBO_TX_1E00[0x34] = 0x43;
            }
            ucDPCDTx[0] = SC_EDP_LINK_1300[_DPTX_LINK_BW_SET];
            ucDPCDTx[1] = SC_EDP_LINK_1300[_DPTX_LANE_COUNT_SET];
            ucDPCDTx[2] = 0x21;
            if (DPTxAUXReqWRStream(NATIVE_AUX_W, 0x100, 2, ucDPCDTx) == FALSE) {
                ret = TRAINING_NORESPONSE;
                break;
            }
        }
#if 0
        else{           
            ret= TRAINING_FAIL;
            break;
        }
#endif
        // - Adjust the drive setting as requested by a Sink Device.
        level = (dpcd_buf[6] & 0x03);
        if (level < ((dpcd_buf[6] & 0x30) >> 4) && (lane_count & 0x0F) >= 0x02) {
            level = (dpcd_buf[6] & 0x30) >> 4;
        }
        if (level < (dpcd_buf[7] & 0x03) && (lane_count & 0x0F) == 0x04 ) {
            level = (dpcd_buf[7] & 0x03);
        }
        if (level < (dpcd_buf[7] & 0x30 >> 4) && (lane_count & 0x0F) == 0x04) {
            level = (dpcd_buf[7] & 0x30) >> 4;
        }
        if(level == 0) {               
            IterationCnt = 5;        
        }       
        else{                
            IterationCnt = 3;		// Add for CTS. 4.3.1.4, 4.3.1.5, 4.3.1.8, 4.3.1.9 (David)   
        }
        pre_emphasis = (dpcd_buf[6] & 0x0c) >> 2;
        if (pre_emphasis < ((dpcd_buf[6] & 0xc0) >> 6) && (lane_count & 0x0F) >= 0x02) {
            pre_emphasis = (dpcd_buf[6] & 0xc0) >> 6;
        }
        if (pre_emphasis < ((dpcd_buf[7] & 0x0c) >> 2) && (lane_count & 0x0F) == 0x04 ) {
            pre_emphasis = (dpcd_buf[7] & 0x0c) >> 2;
        }
        if (pre_emphasis < (dpcd_buf[7] & 0xc0 >> 6) && (lane_count & 0x0F) == 0x04 ) {
            pre_emphasis = (dpcd_buf[7] & 0xc0) >> 6;
        }
       // printf("level=%bd, pre-emphasis=%bd\r\n", level, pre_emphasis);
            if (pre_emphasis == 0) {
                SC_COMBO_TX_1E00[0x21] = 0x00;
                SC_COMBO_TX_1E00[0x1C] = 0x00;
                if (level == 0) {
                    SC_COMBO_TX_1E00[0x5B] = 0x04;
                }
                else if (level == 1) {
                    SC_COMBO_TX_1E00[0x5B] = 0x0E;
                }
                else {
                    SC_COMBO_TX_1E00[0x5B] = 0x19;
                }
            }
            else if (pre_emphasis == 1) {
                if (level == 0) {
                    SC_COMBO_TX_1E00[0x21] = 0x04;
                    SC_COMBO_TX_1E00[0x1C] = 0x02;
                    SC_COMBO_TX_1E00[0x5B] = 0x0A;
                }
                else if (level == 1) {
                    SC_COMBO_TX_1E00[0x21] = 0x04;
                    SC_COMBO_TX_1E00[0x1C] = 0x03;
                    SC_COMBO_TX_1E00[0x5B] = 0x15;
                }
                else {
                    SC_COMBO_TX_1E00[0x21] = 0x04;
                    SC_COMBO_TX_1E00[0x1C] = 0x03;
                    SC_COMBO_TX_1E00[0x5B] = 0x1E;
                }
            }
            else {
                if (level == 0) {
                    SC_COMBO_TX_1E00[0x21] = 0x04;
                    SC_COMBO_TX_1E00[0x1C] = 0x06;
                    SC_COMBO_TX_1E00[0x5B] = 0x10;
                }
                else {
                    SC_COMBO_TX_1E00[0x21] = 0x04;
                    SC_COMBO_TX_1E00[0x1C] = 0x07;
                    SC_COMBO_TX_1E00[0x5B] = 0x1C;
                }
            }
      //  printf("set level swing,pre-phasis, %02BX%02BX \r\n", SC_DPTX_IOCTL0, SC_DPTX_IOCTL1);

        //- Write an updated value to TRAINING_LANEx_SET byte.
       //ucDPCDTx[0] = 0x21;		// train_set 1
        ucDPCDTx[1] = level | (pre_emphasis << 3);	// lane0
        if (level >= 2) {
            ucDPCDTx[1] |= BIT2;    // MAX_SWING_REACHED
        }
        if (pre_emphasis >= 2) {
            ucDPCDTx[1] |= BIT5;    // MAX_PRE-EMPHASIS_REACHED
        }

        ucDPCDTx[2] = ucDPCDTx[1];		// lane1
        ucDPCDTx[3] = ucDPCDTx[1];		// lane2
        ucDPCDTx[4] = ucDPCDTx[1];		// lane3
        if (DPTxAUXReqWRStream(NATIVE_AUX_W, 0x103,( (lane_count & 0x0F)-1), &ucDPCDTx[1]) == FALSE) {
            ret = TRAINING_NORESPONSE;
            break;
        }
    }
    while (1);


    if ( ret == TRAINING_FAIL) {
        DPTxAUXReqWRByte(NATIVE_AUX_W, 0x102, 0x00);	
        //printf("Clork Recovery Training Fail!\r\n");
        return;
    }
    else if ( ret == TRAINING_NORESPONSE) {
        //printf("Aux No Response !\r\n");
        return;
    }
    else {
        //printf("CR done !! \r\n");
    }


    /*Tansmit Training Pattern 2 or 3 over Main Link and write 0x02 or 0x03 to TRAINING_PATTERN_SET byte
     and the current drive settng to TRAIING_LANEx_SET bytes via AUX CH*/
    //SC_EDP_TX_DPHY_1F00[0x60] |= BIT7;
    //SC_EDP_TX_DPHY_1F00[0x09] = (SC_EDP_TX_DPHY_1F00[0x09] & 0x7F) | BIT7;
    SC_EDP_TX_DPHY_1F00[0x60] &= ~BIT7;
    SC_EDP_TX_DPHY_1F00[0x09] = (SC_EDP_TX_DPHY_1F00[0x09] & 0x7F) | BIT7;
    SC_EDP_TX_DPHY_1F00[0x63] = (SC_EDP_TX_DPHY_1F00[0x63] & 0x8F) | 0x20;        
    if (TPS3 == 1){
        ucDPCDTx[0] = 0x23;
        IterationCnt =6;  //400.3.1.9
    }
    else{
        ucDPCDTx[0] = 0x22;
    }
    if (DPTxAUXReqWRStream(NATIVE_AUX_W, 0x102, (lane_count & 0x0F), ucDPCDTx) == FALSE) {
        //printf("Write 0x102h --> FALSE!\r\n");
        return;
    }
    train_cnt = 0;
    do {
        // Wait for delay specified in TRAINING_AUX_RD_INTERVAL
        Sleep(rd_interval);
        //Read LANEx_CR_DONE bits, LANEx_CHANNEL_EQ_DONE bits, LANEx_SYMBOL_LOCKED bits, and ADJUST_REQUEST_LANEx_x bytes
        if (DPTxAUXReqRDStream(NATIVE_AUX_R, 0x202, 5, dpcd_buf) == FALSE) {
            ret = TRAINING_NORESPONSE;
            retraining = 0;	
            break;
        }
        if ((lane_count & 0x0F) == 0x04) {
            if ((dpcd_buf[0] & 0x77) == 0x77  &&   (dpcd_buf[1] & 0x77) == 0x77) {
                retraining =0;
                ret = TRAINING_OK;
                break;
            }
            // only for test . CTS 4.3.1.7 (David.)
#if ENABLE_DPTX_LINK_CTS == ON
            if ((dpcd_buf[0] & 0x11) != 0x11 && (dpcd_buf[1] & 0x11) != 0x11) {
                bBitRateReduce = TRUE;
                // force to reduce bitrate
                return;
            }
#endif
        }
        else if ((lane_count & 0x0F) == 0x02) {
            if ((dpcd_buf[0] & 0x77) == 0x77) {
                retraining =0;
                ret = TRAINING_OK;
                break;
            }
        }
        else {
            if ((dpcd_buf[0] & 0x07) == 0x07) {
                retraining =0;
                ret = TRAINING_OK;
                break;
            }
        }
        train_cnt++;
        if (train_cnt >= IterationCnt) { //Set Reduce Bit Rate
            if (link_bw == 0x14) {
                link_bw = 0x0A;
                retraining = 1;
            }
            else if (link_bw == 0x0A) {
                link_bw = 0x06;
                retraining =1 ;
            }
            else {
                ret = TRAINING_FAIL;
                retraining = 0;
                break;
            }
            train_cnt = 0;
            SC_EDP_LINK_1300[_DPTX_LINK_BW_SET] = link_bw;
            SC_EDP_LINK_1300[_DPTX_LANE_COUNT_SET] = ((SC_EDP_LINK_1300[_DPTX_LANE_COUNT_SET] & BIT6) | lane_count);
            if (link_bw == 0x14) {
                SC_EDP_PLL_LO = 0x00;
                SC_EDP_PLL_MI = 0x00;
                SC_EDP_PLL_HI = 0x2D;
            }
            else if (link_bw == 0x0A) {
                SC_EDP_PLL_LO = 0x00;
                SC_EDP_PLL_MI = 0x80;
                SC_EDP_PLL_HI = 0x16;
            }
            else {
                SC_EDP_PLL_LO = 0x00;
                SC_EDP_PLL_MI = 0x80;
                SC_EDP_PLL_HI = 0x0D;
            }

            if (link_bw == 0x14) {
                SC_COMBO_TX_1E00[0x34] = 0x4D;//WRITE	B0	6834	4D
            }
            else {
                SC_COMBO_TX_1E00[0x34] = 0x43;
            }
            ucDPCDTx[0] = SC_EDP_LINK_1300[_DPTX_LINK_BW_SET];
            ucDPCDTx[1] = SC_EDP_LINK_1300[_DPTX_LANE_COUNT_SET];
            if (TPS3 == 1 ){
                ucDPCDTx[2] = 0x23;
            }
            else{
                ucDPCDTx[2] = 0x22;		// train_set 1
            }
            if (DPTxAUXReqWRStream(NATIVE_AUX_W, 0x100, 2, ucDPCDTx) == FALSE) {
                ret = TRAINING_NORESPONSE;
            }
            break;
        }
//        else{  //DP bypass mode
//             ret= TRAINING_FAIL;
//             break;
//        }
        // - Adjust the drive setting as requested by a Sink Device.
        level = (dpcd_buf[4] & 0x03);
        if (level < ((dpcd_buf[4] & 0x30) >> 4) && (lane_count & 0x0F) >= 0x02) {
            level = (dpcd_buf[4] & 0x30) >> 4;
        }
        if (level < (dpcd_buf[5] & 0x03) && (lane_count & 0x0F) == 0x04 ) {
            level = (dpcd_buf[5] & 0x03);
        }
        if (level < (dpcd_buf[5] & 0x30 >> 4) && (lane_count & 0x0F) == 0x04) {
            level = (dpcd_buf[5] & 0x30) >> 4;
        }
        pre_emphasis = (dpcd_buf[4] & 0x0c) >> 2;
        if (pre_emphasis < ((dpcd_buf[4] & 0xc0) >> 6) && (lane_count & 0x0F) >= 0x02) {
            pre_emphasis = (dpcd_buf[4] & 0xc0) >> 6;
        }
        if (pre_emphasis < ((dpcd_buf[5] & 0x0c) >> 2) && (lane_count & 0x0F) == 0x04 ) {
            pre_emphasis = (dpcd_buf[5] & 0x0c) >> 2;
        }
        if (pre_emphasis < (dpcd_buf[5] & 0xc0 >> 6) && (lane_count & 0x0F) == 0x04 ) {
            pre_emphasis = (dpcd_buf[5] & 0xc0) >> 6;
        }
        //printf("level=%bd, pre-emphasis=%bd\r\n", level, pre_emphasis);
        if (pre_emphasis == 0) {
            SC_COMBO_TX_1E00[0x21] = 0x00;
            SC_COMBO_TX_1E00[0x1C] = 0x00;
            if (level == 0) {
                SC_COMBO_TX_1E00[0x5B] = 0x04;
            }
            else if (level == 1) {
                SC_COMBO_TX_1E00[0x5B] = 0x0E;
            }
            else {
                SC_COMBO_TX_1E00[0x5B] = 0x19;
            }
        }
        else if (pre_emphasis == 1) {
            if (level == 0) {
                SC_COMBO_TX_1E00[0x21] = 0x04;
                SC_COMBO_TX_1E00[0x1C] = 0x02;
                SC_COMBO_TX_1E00[0x5B] = 0x0A;
            }
            else if (level == 1) {
                SC_COMBO_TX_1E00[0x21] = 0x04;
                SC_COMBO_TX_1E00[0x1C] = 0x03;
                SC_COMBO_TX_1E00[0x5B] = 0x15;
            }
            else {
                SC_COMBO_TX_1E00[0x21] = 0x04;
                SC_COMBO_TX_1E00[0x1C] = 0x03;
                SC_COMBO_TX_1E00[0x5B] = 0x1E;
            }
        }
        else {
            if (level == 0) {
                SC_COMBO_TX_1E00[0x21] = 0x04;
                SC_COMBO_TX_1E00[0x1C] = 0x06;
                SC_COMBO_TX_1E00[0x5B] = 0x10;
            }
            else {
                SC_COMBO_TX_1E00[0x21] = 0x04;
                SC_COMBO_TX_1E00[0x1C] = 0x07;
                SC_COMBO_TX_1E00[0x5B] = 0x1C;
            }
        }
//        printf("set level swing,pre-phasis, %02BX%02BX \r\n", SC_DPTX_IOCTL0, SC_DPTX_IOCTL1);

        //- Write an updated value to TRAINING_LANEx_SET byte.
        if (TPS3 == 1 ){
            ucDPCDTx[0] = 0x23;
        }
        else{
            ucDPCDTx[0] = 0x22;		// train_set 1
        }
        ucDPCDTx[1] = level | (pre_emphasis << 3);	// lane0
        if (level >= 2) {
            ucDPCDTx[1] |= BIT2;    // MAX_SWING_REACHED
        }
        if (pre_emphasis >= 2) {
            ucDPCDTx[1] |= BIT5;    // MAX_PRE-EMPHASIS_REACHED
        }

        ucDPCDTx[2] = ucDPCDTx[1];		// lane1
        ucDPCDTx[3] = ucDPCDTx[1];		// lane2
        ucDPCDTx[4] = ucDPCDTx[1];		// lane3
        if (DPTxAUXReqWRStream(NATIVE_AUX_W, 0x103, ((lane_count & 0x0F)-1), &ucDPCDTx[1]) == FALSE) {
            ret = TRAINING_NORESPONSE;
            retraining = 0;	
            break;
        }
    }
    while (1);
}while(retraining == 1);

    //  ret = Channel_Equalization(dptx_ch,lane_count, link_bw ,rd_interval,dpcd_buf);
    if ( ret == TRAINING_FAIL) {
        DPTxAUXReqWRByte(NATIVE_AUX_W, 0x102, 0x00);	
        //printf("Channel Equalization Training Fail!\r\n");
        return;
    }
    else if ( ret == TRAINING_NORESPONSE) {
        //printf("Aux No Response !\r\n");
        return;
    }
    else {
        //printf("Channel Equailization done!\r\n");
    }


    if (DPTxAUXReqWRByte(NATIVE_AUX_W, 0x102, 0x00) != AUX_ACK) {
        //printf("clear train set error!\r\n");
        return;
    }

    //SC_EDP_TX_DPHY_1F00[0x60] |= BIT7;
    //SC_EDP_TX_DPHY_1F00[0x09] = SC_EDP_TX_DPHY_1F00[0x09] & 0x7F;
    SC_EDP_TX_DPHY_1F00[0x60] &= ~BIT7;
    SC_EDP_TX_DPHY_1F00[0x09] = SC_EDP_TX_DPHY_1F00[0x09] & 0x7F;
    SC_EDP_TX_DPHY_1F00[0x63] = (SC_EDP_TX_DPHY_1F00[0x63] & 0x8F) | 0x40;        
    if (ret == TRAINING_OK) {
        //printf("Training done!!\r\n");
    }
    else {
        //printf("Training fail!!\r\n");
    }
}

// DP TX HPD
void InitDPHPD(void)
{
#if 0// only for debug (bypass HPD)
    SC_EDP_LINK_1300[_DPTX_MISC_CTL] = 0x84;
    SC_EDP_LINK_1300[_DPTX_HPD_CTL] = 0x06;		// manual mode
#else
    SC_EDP_LINK_1300[_DPTX_MISC_CTL] &= ~BIT3;
    SC_EDP_LINK_1300[_DPTX_HPD_CTL] = (DPTX_HPD_EN | DPTX_HPD_IRQ_INT_MASK | DPTX_HPD_PLUG_INT_MASK);		// HDP enable, INT (Plug, IRQ) enable
#if EDP_RCK_12MHz == ON
    SC_EDP_LINK_1300[_DPTX_REF_CLK] = 12;                                         // 12 MHz (OSC clock)
    SC_EDP_LINK_1300[0x2C] = 0x8C;
#else
    SC_EDP_LINK_1300[_DPTX_REF_CLK] = 48;						// 48 MHz (MCU clock)
#endif
    SC_EDP_LINK_1300[_DPTX_HPD_IRQ_LTH] = 50;					// HPD IRQ Low threshold = 500 us
    SC_EDP_LINK_1300[_DPTX_HPD_IRQ_HTH] = 200;				// HPD IRQ High threshold = 2000 us = 2ms

    SC_MCU_IO_CTRL9 = (SC_MCU_IO_CTRL9 & 0xCF) | BIT4; // eDP HPD Pin enable
    bDPTXHPD_IRQ = FALSE;
#endif
}

BOOL DPRxCheckDPCD(void)
{
#if ENABLE_DPTX_PHY_CTS == ON
    UCHAR volatile xdata *Addr;
    UCHAR l;
#endif

    //UCHAR dpcd_buf[6];
    UCHAR lane_count, retraining = 0;
    lane_count = ucEDPBandLane[lane];


//    ucDPTX_PN_Swap = SC_DPTX_FSM01 & BIT3;
    
    if ((SC_EDP_LINK_1300[_DPTX_HPD_CTL] & DPTX_HDP_PULG_STATE) == 0x00) {//go low
     //   printf("unplug\r\n");
        return 0;
    }
    if (DPTxAUXReqRDStream(NATIVE_AUX_R, 0x200, 5, dpcd_buf) == FALSE) {
        //printf("-----read error!!!\r\n");
        retraining = 1;
    }
    else {
        if ((lane_count & 0x1F) == 0x01) {//1 lane
            if ((dpcd_buf[2] & 0x0F) != 0x07) {
                retraining = 1;
            }
        }
        else if ((lane_count & 0x1F) == 0x02) {//2 lane
            if (dpcd_buf[2] != 0x77) {
                retraining = 1;
            }
        }
        else {
            if (dpcd_buf[2] != 0x77 || dpcd_buf[3] != 0x77) {//4 lane
                retraining = 1;
            }
        }
        if((dpcd_buf[4]&BIT0)!= BIT0){ //check  INTERLANE_ALIGN_DONE              
            retraining = 1;         
	} 
//#if 1//DPTX PHY CTS		// David. add (2013/12/11)
#if 1//ndef ENABLE_MST_MSG//DPTX PHY CTS: code size issue
        if (dpcd_buf[1] != 0) {
#if ENABLE_DPTX_LINK_CTS == ON

            DPTxAUXReqWRByte(NATIVE_AUX_W, 0x201, dpcd_buf[1]);
            if ((dpcd_buf[1] & BIT1) != 0) {	// AUTOMATED_TEST_REQUEST = 1
                DPTxAUXReqRDStream(NATIVE_AUX_R, 0x218, 0, dpcd_buf);
                if ((dpcd_buf[0] & BIT0) != 0) {	// TEST_LINK_TRAINING = 1
                    DPTxAUXReqWRByte(NATIVE_AUX_W, 0x260, 0x01);		// Write TEST_RESPONSE.TEST_ACK = 1
                    DPTxAUXReqRDByte(NATIVE_AUX_R, 0x219, dpcd_buf);//DPTxAUXReqRDStream(dptx_ch, NATIVE_AUX_R, 0x219, 0, dpcd_buf);
                    ucBandLane[band] = dpcd_buf[0];
                    //LANE_COUNT_SET = dpcd_buf[0];
                    DPTxAUXReqWRByte(NATIVE_AUX_W, 0x100, dpcd_buf[0]);
                    DPTxAUXReqRDByte(NATIVE_AUX_R, 0x220, dpcd_buf);//DPTxAUXReqRDStream(dptx_ch, NATIVE_AUX_R, 0x220, 0, dpcd_buf);
                    ucBandLane[lane] = dpcd_buf[0];
                    //LINK_BW_SET = dpcd_buf[0];
                    DPTxAUXReqWRByte(NATIVE_AUX_W, 0x101, dpcd_buf[0]);
                    retraining = 1;
                    return TRUE;
                }
                else if ((dpcd_buf[0] & BIT1) != 0) {
                    DPTxAUXReqRDByte(NATIVE_AUX_R, 0x221, dpcd_buf);
                    if ((dpcd_buf[0] & 0x0F) != 0) {
                        //Addr = 0xD5AF; *Addr |= BIT6;
                        SC_EDP_LINK_1300[0x78] |= BIT0;
                        SC_DPRX_BRANCH_4C00[0x00] |= BIT4;
                        //DPTxAUXReqWRByte(dptx_ch, NATIVE_AUX_W, 0x260, 0x01);		// Write TEST_RESPONSE.TEST_ACK = 1
                    }
                    else {
                        //Addr = 0xD5AF; *Addr &= ~BIT6;
                        SC_EDP_LINK_1300[0x78] &= ~BIT0;
                        SC_DPRX_BRANCH_4C00[0x00] &= ~BIT4;
                    }
                }
            }
#elif ENABLE_DPTX_PHY_CTS == ON
        // Add for CTS 4.2.2.1	(David, 2013/10/28)
#if 0        
            if ((SC_DPTX_PHY_6320 & BIT1) == 0x00) {
                SC_DPTX_PHY_631F = 0x72;//0x62;//WRITE	B0	151F	62
                SC_DPTX_PHY_6320 |= BIT1;		// CDR power up.
                delay250us();
                SC_DPTX_PHY_631F = 0x52;//0x42;//WRITE	B0	151F	42
            }
        // end add for CTS 4.2.2.1
#endif
            EDP_PowerOn();
            //printf("201h = %02bX\r\n", dpcd_buf[1]);
            DPTxAUXReqWRByte(NATIVE_AUX_W, 0x201, dpcd_buf[1]);
            //printf("lane_count = %02bX\r\n", lane_count);
            //printf("202h = %02bX\r\n", dpcd_buf[2]);
            DPTxAUXReqRDStream(NATIVE_AUX_R, 0x000, 5, dpcd_buf);
            printf("003h = %02bX\r\n", dpcd_buf[3]);
            if ((dpcd_buf[3] & BIT0) == 0x00) {//SSC off
                SC_EDP_CLK_SSC &= ~BIT0;//SC_SSC_CTRL &= ~BIT0;
            }
            else {//SSC on  //Austin modify SSC register
                SC_EDP_MAN_CLK_SSC= 0xB0;//Addr = 0x8B47; *Addr = 0xB0;
                    SC_EDP_MAN_CLK_SSC_RATIO= 0x01;//Addr = 0x8B48; *Addr = 0x01;
                    //SC_EDP_CLK_SSC |= BIT0;//SC_SSC_CTRL |= BIT0;
                    SC_EDP_CLK_SSC = 0x0B;
            }
            DPTxAUXReqRDStream(NATIVE_AUX_R, 0x206, 2, dpcd_buf);
            //printf("206h = %02bX\r\n", dpcd_buf[0]);
            //printf("207h = %02bX\r\n", dpcd_buf[1]);

            
                //pre-emphsis & swing level
            //printf("edp pre-emphasis and swing level\r\n");

                if((dpcd_buf[0] & 0x0C) == 0x00) {  // pre-emphasis level 0
                    // port C
                    SC_COMBO_TX_1E00[0x21] = 0x00;  // bit 2 port C, bit 3 port D 
                    SC_COMBO_TX_1E00[0x1C] = 0x00;  // [2:0] port C, [6:4] port D
                    if((dpcd_buf[0] & 0x03) == 0x00) {  // swing level 0                
                        SC_COMBO_TX_1E00[0x5B] = 0x04;  //port C
                        SC_COMBO_TX_1E00[0x5C] = 0x04;  //port D
                    }
                    else if((dpcd_buf[0] & 0x03) == 0x01) {  // swing level 1
                        SC_COMBO_TX_1E00[0x5B] = 0x0E;
                        SC_COMBO_TX_1E00[0x5C] = 0x0E;
                    }
                    else if((dpcd_buf[0] & 0x03) == 0x02) {  // swing level 2
                        SC_COMBO_TX_1E00[0x5B] = 0x19;
                        SC_COMBO_TX_1E00[0x5C] = 0x19;
                    }
                }
                else if((dpcd_buf[0] & 0x0C) == 0x04) {  // pre-emphasis level 1
                    SC_COMBO_TX_1E00[0x21] = 0x0C; // 0x04 port C
                    if((dpcd_buf[0] & 0x03) == 0x00) {  // swing level 0
                        SC_COMBO_TX_1E00[0x1C] = 0x22;  //0x01 port C
                        SC_COMBO_TX_1E00[0x5B] = 0x0a;
                        SC_COMBO_TX_1E00[0x5C] = 0x0a;
                    }
                    else if((dpcd_buf[0] & 0x03) == 0x01) {  // swing level 1
                        SC_COMBO_TX_1E00[0x1C] = 0x33;  //0x02 port C
                        SC_COMBO_TX_1E00[0x5B] = 0x15;
                        SC_COMBO_TX_1E00[0x5C] = 0x15;
                    }
                    else if((dpcd_buf[0] & 0x03) == 0x02) {  // swing level 2
                        SC_COMBO_TX_1E00[0x1C] = 0x33;
                        SC_COMBO_TX_1E00[0x5B] = 0x1E;
                        SC_COMBO_TX_1E00[0x5C] = 0x1E;
                    }
                }
                else if((dpcd_buf[0] & 0x0C) == 0x08) {  // pre-emphasis level 2
                    SC_COMBO_TX_1E00[0x21] = 0x0C; // 0x04 port C
                    if((dpcd_buf[0] & 0x03) == 0x00) {  // swing level 0
                        SC_COMBO_TX_1E00[0x1C] = 0x66;  //0x06 port C
                        SC_COMBO_TX_1E00[0x5B] = 0x10;
                        SC_COMBO_TX_1E00[0x5C] = 0x10;
                    }
                    else if((dpcd_buf[0] & 0x03) == 0x01) {  // swing level 1
                        SC_COMBO_TX_1E00[0x1C] = 0x77;
                        SC_COMBO_TX_1E00[0x5B] = 0x1C;
                        SC_COMBO_TX_1E00[0x5C] = 0x1C;
                    }          
                }
            
            DPTxAUXReqRDStream(NATIVE_AUX_R, 0x218, 2, dpcd_buf);
            //printf("218h = %02bX\r\n", dpcd_buf[0]);
            //printf("219h = %02bX\r\n", dpcd_buf[1]);

            // added by Austin

            SC_POWER_CTRL3 = 0xE8;
            SC_PLL_SYZ_PU = 0xF8;
            //MPLL
            if (dpcd_buf[1] == 0x14) {
                SC_EDP_PLL_LO = 0x00;
                SC_EDP_PLL_MI = 0x00;
                SC_EDP_PLL_HI = 0x2D;
            }
            else if (dpcd_buf[1] == 0x0A) {
                SC_EDP_PLL_LO = 0x00;
                SC_EDP_PLL_MI = 0x80;
                SC_EDP_PLL_HI = 0x16;
            }
            else {
                SC_EDP_PLL_LO = 0x00;
                SC_EDP_PLL_MI = 0x80;
                SC_EDP_PLL_HI = 0x0D;
            }
            SC_EDP_TX_DPHY_1F00[0x64] = 0x00; 
                SC_COMBO_TX_1E00[0x00] = 0x86; 
            SC_COMBO_TX_1E00[0x20] = 0x08; 
            //SC_COMBO_TX_1E00[0x33] = 0x2A;  //  current 1A < 2A < 3A
            SC_COMBO_TX_1E00[0x33] = 0xEA;  //  new current setting
                SC_COMBO_TX_1E00[0x46] = 0x01;
                Sleep(1);//Sleep
                SC_COMBO_TX_1E00[0x46] = 0x03;
            //SC_COMBO_TX_1E00[0x3D] = 0x4F;
            SC_COMBO_TX_1E00[0x3D] = 0x43;
                
                if (dpcd_buf[1] == 0x14) {//5.4G
                    ucEDPBandLane[band] = 0x14;
                    SC_COMBO_TX_1E00[0x34] = 0x4D;
                }
                else if (dpcd_buf[1] == 0x0A) {// 2.7G
                    ucEDPBandLane[band] = 0x0A;
                    SC_COMBO_TX_1E00[0x34] = 0x43;
                }
                else {//if (dpcd_buf[1] == 0x06) {//1.62G
                    ucEDPBandLane[band] = 0x06;
                    SC_COMBO_TX_1E00[0x34] = 0x43;
                }
#if 0            
                SC_COMBO_TX_1E00[0x1F] = 0x0C;
                SC_COMBO_TX_1E00[0x40] = 0x3C;
                SC_COMBO_TX_1E00[0x41] = 0x0F;
                SC_COMBO_TX_1E00[0x49] = 0x03;
                SC_COMBO_TX_1E00[0x4A] = 0x30;
                SC_COMBO_TX_1E00[0x03] = 0x3C;
                SC_COMBO_TX_1E00[0x04] = 0x0F;
                SC_COMBO_TX_1E00[0x24] = 0x3C;
                SC_COMBO_TX_1E00[0x25] = 0x0F;
                SC_EDP_TX_DPHY_1F00[0x60] = 0x00;//WRITE	B0	6960	00     
                SC_EDP_TX_DPHY_1F00[0x0C] = 0x10;//WRITE	B0	690C	10
                SC_EDP_TX_DPHY_1F00[0x0D] = 0x08;//WRITE	B0	690D	08
                //SC_EDP_TX_DPHY_1F00[0x60] = 0x80;//WRITE	B0	6960	80
                //SC_EDP_TX_DPHY_1F00[0x0C] = 0x10;//WRITE	B0	690C	10
                //SC_EDP_TX_DPHY_1F00[0x0D] = 0x08;//WRITE	B0	690D	08	
                SC_EDP_TX_DPHY_1F00[0x64] = 0x07;//WRITE	B0	6964	07
                SC_EDP_TX_DPHY_1F00[0x63] = 0x94;//WRITE	B0	6963	94
 #endif
            SC_COMBO_TX_1E00[0x1F] = 0x08;
            SC_COMBO_TX_1E00[0x41] = 0x1E;
            SC_COMBO_TX_1E00[0x4A] = 0x00;
            SC_COMBO_TX_1E00[0x04] = 0x1E;
            SC_COMBO_TX_1E00[0x25] = 0x1E;
            SC_EDP_TX_DPHY_1F00[0x60] = 0x00; 
            SC_EDP_TX_DPHY_1F00[0x0D] = 0x08; 
            SC_EDP_TX_DPHY_1F00[0x0C] = 0x10; 
            SC_EDP_TX_DPHY_1F00[0x64] = 0x07; 
            SC_EDP_TX_DPHY_1F00[0x63] = 0x95; 

            DPTxAUXReqRDStream(NATIVE_AUX_R, 0x220, 2, dpcd_buf);
            //printf("220h = %02bX\r\n", dpcd_buf[0]);
            //printf("221h = %02bX\r\n", dpcd_buf[1]);

                if (dpcd_buf[0] == 0x01) {//1 lane
                ucEDPBandLane[lane] = (ENHANCE_FRAME_EDP<<7|0x01);
                }
                else if (dpcd_buf[0] == 0x02) {// 2 lane    !!!!!!!!!!!!!!!!!!!   dpcd_buf[1] -> dpcd_buf[0]
                ucEDPBandLane[lane] = (ENHANCE_FRAME_EDP<<7|0x02);
                }
                else if (dpcd_buf[0] == 0x04) {// 4 lane    !!!!!!!!!!!!!!!!!!!   dpcd_buf[1] -> dpcd_buf[0]
                ucEDPBandLane[lane] = (ENHANCE_FRAME_EDP<<7|0x04);
            }
    
            DPTxAUXReqRDStream(NATIVE_AUX_R, 0x232, 2, dpcd_buf);
            //printf("232h = %02bX\r\n", dpcd_buf[0]);
            //printf("233h = %02bX\r\n", dpcd_buf[1]);
            DPTxAUXReqRDByte(NATIVE_AUX_R, 0x248, dpcd_buf);
            //printf("248h = %02bX\r\n", dpcd_buf[0]);


            Addr = 0x9F00;   
            Addr[0x2C] = 0x00;
            //printf("EDP channel\r\n");

            switch (dpcd_buf[0]) {
                case 0x01:  // D10.2
                    Addr[0x64] = 0x07; 
                    Addr[0x63] = 0x95;
                    SC_EDP_LINK_1300[_DPTX_LINK_BW_SET] = ucEDPBandLane[band];
                    SC_EDP_LINK_1300[_DPTX_LANE_COUNT_SET] = ((SC_EDP_LINK_1300[_DPTX_LANE_COUNT_SET] & BIT6) | ucEDPBandLane[lane]);
                    //Addr[0x09] = 0x11;//(BIT7 | 0x11 | ucDPTX_PN_Swap);
                    //Addr[0x0A] = 0x11;
                    Addr[0x63] = 0x95;
                    //printf("in case 1 SC_DPTX_FSM01=%x\r\n", (USHRT)Addr[0x09]);
                    retraining = 0;
                    break;
                case 0x03:  // PRBS7
                    Addr[0x64] = 0x07; 
                    Addr[0x63] = 0xd5;
                    SC_EDP_LINK_1300[_DPTX_LINK_BW_SET] = ucEDPBandLane[band];
                    SC_EDP_LINK_1300[_DPTX_LANE_COUNT_SET] = ((SC_EDP_LINK_1300[_DPTX_LANE_COUNT_SET] & BIT6) | ucEDPBandLane[lane]);
                    //Addr[0x09]  = (BIT7 | 0x55);  // (BIT7 | 0x55 | ucDPTX_PN_Swap);
                    //Addr[0x0A]  = 0x55;
                    Addr[0x63] = 0xd5;

                    //printf("in case 3 SC_DPTX_FSM01=%x\r\n", (USHRT)Addr[0x09] );
                    
                    retraining = 0;
                    break;
                case 0x04:  // PLTPAT
                    Sleep(1);
                        Addr[0x64] = 0x07;
                        //port C
                    Sleep(1);
                        Addr[0x60] = 0x04;
                    Sleep(1);           
                        Addr[0x2C] = 0x00;//Addr = 0x952C; *Addr = 0x00;//WRITE	B0	152C	00
                        Addr[0x2D] = 0x1F;//Addr = 0x952D; *Addr = 0x1F;//WRITE	B0	152D	1F
                        Addr[0x2C] = 0x01;//Addr = 0x952C; *Addr = 0x01;//WRITE	B0	152C	01
                        Addr[0x2D] = 0x7C;//Addr = 0x952D; *Addr = 0x7C;//WRITE	B0	152D	7C
                        Addr[0x2C] = 0x02;//Addr = 0x952C; *Addr = 0x02;//WRITE	B0	152C	02
                        Addr[0x2D] = 0xF0;//Addr = 0x952D; *Addr = 0xF0;//WRITE	B0	152D	F0
                        Addr[0x2C] = 0x03;//Addr = 0x952C; *Addr = 0x03;//WRITE	B0	152C	03
                        Addr[0x2D] = 0xC1;//Addr = 0x952D; *Addr = 0xC1;//WRITE	B0	152D	C1
                        Addr[0x2C] = 0x04;//Addr = 0x952C; *Addr = 0x04;//WRITE	B0	152C	04
                        Addr[0x2D] = 0x07;//Addr = 0x952D; *Addr = 0x07;//WRITE	B0	152D	07
                        Addr[0x2C] = 0x05;//Addr = 0x952C; *Addr = 0x05;//WRITE	B0	152C	05
                        Addr[0x2D] = 0x1F;//Addr = 0x952D; *Addr = 0x1F;//WRITE	B0	152D	1F
                        Addr[0x2C] = 0x06;//Addr = 0x952C; *Addr = 0x06;//WRITE	B0	152C	06
                        Addr[0x2D] = 0x7C;//Addr = 0x952D; *Addr = 0x7C;//WRITE	B0	152D	7C
                        Addr[0x2C] = 0x07;//Addr = 0x952C; *Addr = 0x07;//WRITE	B0	152C	07
                        Addr[0x2D] = 0xF0;//Addr = 0x952D; *Addr = 0xF0;//WRITE	B0	152D	F0
                        Addr[0x2C] = 0x08;//Addr = 0x952C; *Addr = 0x08;//WRITE	B0	152C	08
                        Addr[0x2D] = 0xC1;//Addr = 0x952D; *Addr = 0xC1;//WRITE	B0	152D	C1
                        Addr[0x2C] = 0x09;//Addr = 0x952C; *Addr = 0x09;//WRITE	B0	152C	09
                        Addr[0x2D] = 0x07;//Addr = 0x952D; *Addr = 0x07;//WRITE	B0	152D	07
                        Addr[0x2C] = 0x0E;//Addr = 0x952C; *Addr = 0x0E;//WRITE      B0	152C	0E
                        //
                        Addr[0x63] = 0xD5;
                        //
                    SC_EDP_LINK_1300[_DPTX_LINK_BW_SET] = ucEDPBandLane[band];
                    SC_EDP_LINK_1300[_DPTX_LANE_COUNT_SET] = ((SC_EDP_LINK_1300[_DPTX_LANE_COUNT_SET] & BIT6) | ucEDPBandLane[lane]);
                    Addr[0x09] = 0x85;//(BIT7 | 0x55 | ucDPTX_PN_Swap);//WRITE	B0	1509	85
                    Addr[0x0A] = 0x55;
                    //printf("in case 4 SC_DPTX_FSM01=%x\r\n", (USHRT)Addr[0x09]);
                    retraining = 0;
                    break;
                case 0x05:  //CP2520
                        Addr[0x60] = 0x04;  // port C upper EDP; port D lower EDP= 0x84
                    Addr[0x64] = 0x03;  

                        Addr[0x2C] = 0x0A;//Addr = 0x952C; *Addr = 0x0A;
                        Addr[0x2D] = 0xFC;//Addr = 0x952D; *Addr = 0xFC;//0x00;
                        Addr[0x2C] = 0x0B;//Addr = 0x952C; *Addr = 0x0B;
                        Addr[0x2D] = 0x00;//Addr = 0x952D; *Addr = 0x00;//0x01;
                        Addr[0x2C] = 0x0C;//Addr = 0x952C; *Addr = 0x0C;
                        Addr[0x2D] = 0x00;//Addr = 0x952D; *Addr = 0x00;
                        //
                        Addr[0x09] = 0x07;

                        //
                    //Addr[0x63] = 0xF5;
                
                    SC_EDP_LINK_1300[_DPTX_LINK_BW_SET] = ucEDPBandLane[band];
                    SC_EDP_LINK_1300[_DPTX_LANE_COUNT_SET] = ((SC_EDP_LINK_1300[_DPTX_LANE_COUNT_SET] & BIT6) | ucEDPBandLane[lane]);
                    //Addr[0x09] = 0x07;//0x77 | ucDPTX_PN_Swap;//(BIT7 | 0x11 | ucDPTX_PN_Swap);
                    //Addr[0x0A] = 0x11;//0x77;
                    //printf("in case 5 SC_DPTX_FSM01=%x\r\n", (USHRT)Addr[0x09]);
                    retraining = 0;
                    break;
            }
#endif
        }
#endif
#if ENABLE_DPTX_LINK_CTS == ON
        if ((dpcd_buf[4] & BIT6) != 0) {	// Add for CTS 4.2.2.8, Check "DOWNSTREAM_PORT_STATUS_CHANGED" = 1, then read EDID again.
            ReadEDID();
        }
#endif

    }
    if (retraining == 1) {
        return TRUE;
    }
    return FALSE;
}

void ReadEDID(void)
{
#if (DPTX_CTS == 1)
    UCHAR i;
#if ENABLE_DPTX_LINK_CTS == ON
    UCHAR edidtest;
    UCHAR temp[2];
#endif
#if 1		// add for CTS test (David. 2013/11/07)
    if ((SC_EDP_LINK_1300[_DPTX_HPD_CTL] & DPTX_HDP_PULG_STATE) == 0x00) {//go low
        //printf("unplug EDID\r\n");
        return;
    }
#endif

#if ENABLE_DPTX_LINK_CTS == ON
  //Added for CTS 4.2.2.4 Austin
    
    edidtest=1;
    temp[0]=0x00;
    temp[1]=0x00;
    if(DPTxAUXReqRDStream(NATIVE_AUX_R, 0x200, 1, temp)) {
        if((temp[1] & BIT1) != 0x00) {
            DPTxAUXReqRDStream(NATIVE_AUX_R, 0x218, 0, temp);
            if((temp[0]&BIT2) != 0x00) {
                edidtest=0;
            }
        }
    }
    else {
        edidtest=0;
    }
#endif

    for (i = 0; i < 16; i++) {  //700.1.1.1
        dpcd_buf[0] = i * 16;
#if ENABLE_DPTX_LINK_CTS == OFF
        DPTxAUXReqWRStream(I2C_AUX_MOT_W, 0x50, 0, dpcd_buf);
        DPTxAUXReqRDStream(I2C_AUX_R, 0x50, 15, dpcd_buf);
#else
       if(edidtest==1) {
            while(!DPTxAUXReqRDStream(I2C_AUX_R, 0x50, 15, dpcd_buf)){   
            }
        }
        else {
            DPTxAUXReqRDStream(I2C_AUX_R, 0x50, 15, dpcd_buf);
        }
#endif
#if 1		// add for CTS test (David. 2013/11/07)
        if ((SC_EDP_LINK_1300[_DPTX_HPD_CTL] & DPTX_HDP_PULG_STATE) == 0x00) {//go low
            //printf("unplug @ EDID reading\r\n");
            return;
        }
        if ((SC_EDP_LINK_1300[_DPTX_HPD_CTL] & DPTX_HPD_IRQ_INT_FLG) != 0x00) {//IRQ
            //printf("HPD IRQ Event @ EDID reading!\r\n");
            return;
        }
#endif

    }
#else
    return;
#endif
}

void ResetDPTxLINK(void)
{
    SC_EDP_LINK_1300[_DPTX_LINK_BW_SET] = LINK_BW_SET_EDP;
    SC_EDP_LINK_1300[_DPTX_LANE_COUNT_SET] = ((SC_EDP_LINK_1300[_DPTX_LANE_COUNT_SET] & BIT6) | LANE_COUNT_SET_EDP);		
    ucEDPBandLane[band] = LINK_BW_SET_EDP;
    ucEDPBandLane[lane] = LANE_COUNT_SET_EDP;       	
}
#endif