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
#if ENABLE_EDP == ON
#include "DPTX.h"
//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************

//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************
#if ENABLE_EDP == ON
static bit bEDPHPDstatus;// = FALSE;//wait HPD
static USHRT usEDPHPDTimer;
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
void InitEDP(void)
{
    EDP_PowerOn();
#if EDP_PN_SWAP == ON
    SC_EDP_TX_DPHY_1F00[0x60] &= ~BIT7;
    SC_EDP_TX_DPHY_1F00[0x09] |= BIT3;//SC_DPTX_FSM01 |= BIT3;
    //SC_EDP_TX_DPHY_1F00[0x60] |= BIT7;
    //SC_EDP_TX_DPHY_1F00[0x09] |= BIT3;//SC_DPTX_FSM01 |= BIT3;
#else
    SC_EDP_TX_DPHY_1F00[0x60] &= ~BIT7;
    SC_EDP_TX_DPHY_1F00[0x09] &= ~BIT3;//SC_DPTX_FSM01 &= ~BIT3;
    //SC_EDP_TX_DPHY_1F00[0x60] |= BIT7;
    //SC_EDP_TX_DPHY_1F00[0x09] &= ~BIT3;//SC_DPTX_FSM01 &= ~BIT3;
#endif

#if EDP_LANE_SWAP == 0xC0
    SC_EDP_TX_DPHY_1F00[0x60] &= ~BIT7;
    SC_EDP_TX_DPHY_1F00[0x08] |= (BIT7|BIT6);//SC_DPTX_FSM01 |= BIT3;
    //SC_EDP_TX_DPHY_1F00[0x60] |= BIT7;
    //SC_EDP_TX_DPHY_1F00[0x08] |= (BIT7|BIT6);//SC_DPTX_FSM01 |= BIT3;
#elif EDP_LANE_SWAP == 0x80
    SC_EDP_TX_DPHY_1F00[0x60] &= ~BIT7;
    SC_EDP_TX_DPHY_1F00[0x08] |= BIT7;//SC_DPTX_FSM01 |= BIT3;
    //SC_EDP_TX_DPHY_1F00[0x60] |= BIT7;
    //SC_EDP_TX_DPHY_1F00[0x08] |= BIT7;//SC_DPTX_FSM01 |= BIT3;
#elif EDP_LANE_SWAP == 0x40
    SC_EDP_TX_DPHY_1F00[0x60] &= ~BIT7;
    SC_EDP_TX_DPHY_1F00[0x08] |= BIT6;//SC_DPTX_FSM01 |= BIT3;
    //SC_EDP_TX_DPHY_1F00[0x60] |= BIT7;
    //SC_EDP_TX_DPHY_1F00[0x08] |= BIT6;//SC_DPTX_FSM01 |= BIT3;
#else
    SC_EDP_TX_DPHY_1F00[0x60] &= ~BIT7;
    SC_EDP_TX_DPHY_1F00[0x08] &= ~(BIT7|BIT6);//SC_DPTX_FSM01 &= ~BIT3;
    //SC_EDP_TX_DPHY_1F00[0x60] |= BIT7;
    //SC_EDP_TX_DPHY_1F00[0x08] &= ~(BIT7|BIT6);//SC_DPTX_FSM01 &= ~BIT3;
#endif

    InitOutputMPLL();
    if (SC_COMBO_TX_1E00[0x00] == 0x86) {//edp out
        InitDPTxPHY();
        InitDPTxLINK();
        InitDPTxAUX();
        InitDPHPD();
    }

    ClearHPDStatus();
}
#if ENABLE_EDP == ON
void EDP_ForceTraining(void)
{
//    UCHAR idle_en = 1;
    UCHAR regbak; 

    // Speed Up HPD detection
    regbak = SC_EDP_LINK_1300[_DPTX_HPD_ACT_TH];
    SC_EDP_LINK_1300[_DPTX_HPD_ACT_TH] = 2; // high 1ms
    Sleep(5);
    SC_EDP_LINK_1300[_DPTX_HPD_ACT_TH] = regbak;

    if ((SC_EDP_LINK_1300[_DPTX_HPD_CTL] & DPTX_HPD_PLUG_INT_FLG) != 0x00) {//plug
        SC_EDP_LINK_1300[_DPTX_HPD_CTL] |= DPTX_HPD_PLUG_INT_FLG;

//        idle_en = Get_Idle_Pattern_Status(_eDPChannel);
        DPRxTraining();
//        if (idle_en == 0) {
//            Idle_Pattern_Ctrl( _eDPChannel, OFF);
//        }
        bEDPHPDstatus = FALSE;//wait HPD
    }    
}
#endif

void CheckDPTXHPD(void)
{

//    UCHAR idle_en = 1;

#if ENABLE_EDP == ON
    if (bEDPHPDstatus == FALSE) {//wait HPD
        if ((SC_EDP_LINK_1300[_DPTX_HPD_CTL] & DPTX_HPD_PLUG_INT_FLG) != 0x00) {//plug
            SC_EDP_LINK_1300[_DPTX_HPD_CTL] |= DPTX_HPD_PLUG_INT_FLG;
            usEDPHPDTimer = GetTimerTick();
            bEDPHPDstatus = TRUE;
        }
    }
    else {//wait HPD stable
        if ((GetTimerTick() - usEDPHPDTimer) > DPTX_HPD_DELAY) {
//            idle_en = Get_Idle_Pattern_Status(_eDPChannel);
            DPRxTraining();
//            if (idle_en == 0) {
//                Idle_Pattern_Ctrl( _eDPChannel, OFF);
//            }
            bEDPHPDstatus = FALSE;//wait HPD
        }
        else {
            if ((SC_EDP_LINK_1300[_DPTX_HPD_CTL] & DPTX_HDP_PULG_STATE) == 0x00) {//go low
                bEDPHPDstatus = FALSE;//wait HPD
            }
        }
    }

    if ((SC_EDP_LINK_1300[_DPTX_HPD_CTL] & DPTX_HPD_IRQ_INT_FLG) != 0x00) {//IRQ
        SC_EDP_LINK_1300[_DPTX_HPD_CTL] |= DPTX_HPD_IRQ_INT_FLG;
//        idle_en = Get_Idle_Pattern_Status(_eDPChannel);
        if (DPRxCheckDPCD()) {
            DPRxTraining();
        }
//        if ((idle_en == 0) && ((SC_DPTX_FSM23 == 0x33) || (SC_DPTX_FSM23 == 0x00))) {//0x00: training fail, 0x33: training done, other: PHY CTS test 
//            Idle_Pattern_Ctrl( _eDPChannel, OFF);
//        }
    }
#endif
}

BOOL IsDPTXTrainingDone(void)
{
    if (((SC_EDP_TX_DPHY_1F00[0x63] & 0x70) != 0x40) && ((SC_EDP_TX_DPHY_1F00[0x63] & 0x70) != 0x30)) {
        return 0;
    }
    else {
        return 1;
    }
}

void ClearHPDStatus(void)
{
#if ENABLE_EDP == ON
    bEDPHPDstatus = FALSE;//wait HPD
#endif
}

void EDP_PowerOn(void)
{
    SC_POWER_CTRL3 |= BIT3; // eDP PLL control to APR
    SC_PLL_SYZ_PU |= BIT4; // MPLL synther PU
    SC_COMBO_TX_1E00[0x64] &= ~BIT3; // eDP TX mode
    SC_COMBO_TX_1E00[0x00] = 0x86;//Bias power on and select DP clk/data
    SC_COMBO_TX_1E00[0x20] &= ~BIT7; // ref exter 12K
    SC_COMBO_TX_1E00[0x33] = 0xEA;//Power on LDO (TX and PLL)
    SC_COMBO_TX_1E00[0x46] = 0x01;//Enable PLL
    Sleep(1);//DELAY_1MS			1
    SC_COMBO_TX_1E00[0x46] = 0x03;//Reset PLL
    SC_COMBO_TX_1E00[0x3D] = 0x43;//Set APLL post-divider
//    SC_COMBO_TX_1E00[0x34] = 0x4D;//Enable PLL high speed mode
    SC_COMBO_TX_1E00[0x1F] = 0x08;//Enable TX R50 
    SC_COMBO_TX_1E00[0x41] = 0x1E;//Enable VX1 P2S power (port D) 
    SC_COMBO_TX_1E00[0x4A] = 0x00;//Disable output pull-low (port D) 
    SC_COMBO_TX_1E00[0x04] = 0x1E;//Enable buffer power (port D) 
    SC_COMBO_TX_1E00[0x25] = 0x1E;//Enable TX output (port D) 
}

#endif

