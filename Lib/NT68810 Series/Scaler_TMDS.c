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
#include "Scaler_TMDS_6502.h"

//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************
//#define TMDS4K2K_TEST
//#define FORCE_SCRAMBLE_ON
//#define ENABLE_HF_TMDS_AUTOEQ
#define TMDSEQ_CHECK_ERROR_CNT_DELAY  50
typedef struct _TMDS_EQ_Setting{
    ULONG ulBestErrCnt;
    UCHAR ucCurrentSearchLevel : 2;
    UCHAR ucBestLevel : 2;
    UCHAR bIsFinish : 1;
}TMDS_EQ_Setting;

//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************
#if ENABLE_EMBEDED_TMDS_CLOCK_TRAINING == OFF
static bit bTMDSClockTraining;
static USHRT usTMDSTrainingTimer;
#endif
//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************
static BOOL bIsDualLink = 0; /*!< Flag of dual-link present. */
static UCHAR ucTMDSInputMode;

static TMDS_EQ_Setting stEQSet;
static USHRT usTMDSCheckErrorCntTimer;
//******************************************************************************
// E X T E R N A L   V A R I A B L E   P R O T O T Y P E S
//******************************************************************************
extern xdata ULONG ulHFreqCounter;

//******************************************************************************
// S T A T I C   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
//static void TMDSInitPhy(UCHAR phyindex);
//static void TMDSInitIIC(void);
static UCHAR GetTMDSPHYDATA(UCHAR phylink, USHRT address);
static void TMDS_EQSet_FlowReset(void);
static void TMDS_EQSet_EQSetting(UCHAR linkidx, UCHAR level);
static void TMDS_EQSet_ErrCntInit(UCHAR phyindex);

//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// F U N C T I O N   B O D Y S
//******************************************************************************

/**************************************************************************//**
 * Initialize TMDS-related registers.
 ******************************************************************************/
void TMDSInit(UCHAR phyindex)
{
    TMDSInitPhy(phyindex);
    //TMDSInitIIC();
    DVI_PowerOn();
    SC_HDCP_CTRL = SCREG_643;
    SC_DVI_PLL_M = 0x20;// 0xb18
    
#if ENABLE_EMBEDED_TMDS_CLOCK_TRAINING == OFF
    ClearTMDSTraining();
#endif
}

void TMDS_EnableCKDT(UCHAR phyindex)
{
#ifdef TMDS4K2K_TEST
    SC_SetByteDPppPHY(phyindex, _DPPHY_FCTRL, 0x36);//Addr = 0x9C00; *Addr = 0x16;//0x1C00= 0x16
#else
    SC_SetByteDPppPHY(phyindex, _DPPHY_FCTRL, 0x06);//Addr = 0x9C00; *Addr = 0x06;//0x1C00= 0x06
#endif
	SC_SetByteDPppPHY(phyindex, _DPPHY_EQR_IMP_ENABLE, 0xFE);//Addr = 0x9C02; *Addr = 0xFE;//0x1C02= 0xFE
}

/**************************************************************************//**
 * Detect current input signal quality and set proper impedance.
 ******************************************************************************/
void TMDSInitPhy(UCHAR phyindex)
{
    SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG0, 0x2F);
    SC_SetByteDPppPHY(phyindex, _DPRM_LANE_POLARITY, 0x00);//WriteScaler(0x1AD5, 0x00);  // PN swap
#ifdef TMDS4K2K_TEST
    SC_SetByteDPppPHY(phyindex, _DPPHY_FCTRL, 0x36);//Addr = 0x9C00; *Addr = 0x16;//0x1C00= 0x16
#else
    SC_SetByteDPppPHY(phyindex, _DPPHY_FCTRL, 0x06);//Addr = 0x9C00; *Addr = 0x06;//0x1C00= 0x06
#endif
    SC_SetByteDPppPHY(phyindex, _DPPHY_ICTRL, 0x00);//Addr = 0x9C01; *Addr = 0x00;//0x1C01= 0x00
#if IS_NT68810_SERIES
    SC_SetByteDPppPHY(phyindex, _DPPHY_EQR_IMP_ENABLE, 0xFE);//Addr = 0x9C02; *Addr = 0xFE;//0x1C02= 0xFE
#else
	SC_SetByteDPppPHY(phyindex, _DPPHY_EQR_IMP_ENABLE, 0xFE);//Addr = 0x9C02; *Addr = 0xFE;//0x1C02= 0xFE
	SC_SetByteDPppPHY(phyindex, _TMDS_DPHY_MODE_SELECT, 0x04);   		
#endif
    SC_SetByteDPppPHY(phyindex, _DPPHY_EQR_RES_CTRL3, 0xF0);	
    SC_SetByteDPppPHY(phyindex, _DPPHY_IMPEDANCE_L0_L2_L3, 0x18);//Addr = 0x9C03; *Addr = 0x18;//0x1C03= 0x18
    SC_SetByteDPppPHY(phyindex, _DPPHY_IMPEDANCE_L1, 0x18);//Addr = 0x9C04; *Addr = 0x18;//0x1C04= 0x18
    SC_SetByteDPppPHY(phyindex, _DPPHY_BIAS_POWER, 0xA0);//Addr = 0x9C1C; *Addr = 0xA0;//0x1C1C= 0xA0
    SC_SetByteDPppPHY(phyindex, _DPPHY_BIAS_LDO, 0x02);//Addr = 0x9C1D; *Addr = 0x02;//0x1C1D= 0x02
#if IS_NT68810_SERIES  
    SC_SetByteDPppPHY(phyindex, _DPPHY_BIAS_R12K, 0x0F);//Addr = 0x9C1E; *Addr = 0x03;//0x06;//0x1C1E= 0x06
#else //NT68870
#if ENABLE_HDCP_TRIM_MODE == ON
    if (ucLEDTRIM_LO == 0) {
        SC_SetByteDPppPHY(phyindex, _DPPHY_BIAS_R12K, 0x10);//Addr = 0x9C1E; *Addr = 0x03;//0x06;//0x1C1E= 0x06
    }
    else {
        SC_SetByteDPppPHY(phyindex, _DPPHY_BIAS_R12K, ucLEDTRIM_LO);//Addr = 0x9C1E; *Addr = 0x03;//0x06;//0x1C1E= 0x06
    }
#else
    SC_SetByteDPppPHY(phyindex, _DPPHY_BIAS_R12K, 0x10);//Addr = 0x9C1E; *Addr = 0x03;//0x06;//0x1C1E= 0x06
#endif
#endif
    SC_SetByteDPppPHY(phyindex, _DPPHY_IBIAS_SEL, 0x0F);//Addr = 0x9C1F; *Addr = 0x0F;//0x1C1F= 0x0F
    SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG2, 0x11);//Addr = 0x9B42; *Addr = 0x11;//dp_rxanaif_aeq_cfg2
    SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG3, 0x0F);//Addr = 0x9B49; *Addr = 0x0F;//dp_rxanaif_aeq_cfg3
    SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG4, 0xFF);
    SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG5, 0x03);
//    SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x0F);//1AD2
//    SC_SetByteDPppPHY(phyindex, _DPRP_STATUS, 0x00);//CDR on, 6502

    SC_SetByteDPppPHY(phyindex, _DPPHY_LDO_CTRL, 0x62);

#if 1//!((INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1) || (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3))
    SC_SetBitDPppPHY(phyindex, _DPRP_REG_1FD, (BIT6|BIT5), FALSE);
#endif

#if ENABLE_TMDS_EQ_SEARCH_FLOW == ON
    stEQSet.bIsFinish = TRUE;
#endif
}

/*
static void TMDSInitIIC(void)
{
    UCHAR volatile xdata *Addr;
    UCHAR reg_value;

    Addr = 0x9BFD; reg_value = *Addr;
    Addr = 0x9BFD; *Addr = reg_value & ~(BIT6|BIT5);
}
*/
#if !lrd_dis
void MHLDPppPHYInit(UCHAR phyindex)
{
    UCHAR ucTmp;
	
    SC_SetByteDPppPHY(phyindex, _TMDS_DPHY_82C5, 0x33);   //SC_DPpp_CFG_TMDS_8100[0x1C5] = 0x41;
    SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG2, 0x13);   // SC_DPpp_CFG_TMDS_8100[0x142] = 0x13;
    SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG3, 0x07);     // SC_DPpp_CFG_TMDS_8100[0x149] = 0x07;
    SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG4, 0xFF);   // SC_DPpp_CFG_TMDS_8100[0x14A] = 0xFF;
    SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG5, 0xFF);   // SC_DPpp_CFG_TMDS_8100[0x14B] = 0xFF;
    SC_SetByteDPppPHY(phyindex, _DPPHY_FCTRL, 0x8E);          // SC_DPpp_CFG_TMDS_8100[0x200] = 0x8C;
    SC_SetByteDPppPHY(phyindex, _DPPHY_EQR_IMP_ENABLE, 0x22); // SC_DPpp_CFG_TMDS_8100[0x202] = 0x22;
    SC_SetByteDPppPHY(phyindex, _DPPHY_EQR_RES_CTRL3, 0x20);

    ucTmp = GetTMDSPHYDATA(phyindex, _DPHY_CBUS_LDO_CTRL);
    ucTmp &= 0x0F;
    ucTmp |= BIT5;
    SC_SetByteDPppPHY(phyindex,_DPHY_CBUS_LDO_CTRL, ucTmp);
}
#endif

/**************************************************************************//**
 * Detect the TMDS clock is stable or not.
 * @return TRUE if clock is stable else FALSE.
 ******************************************************************************/
BOOL TMDSClockStable(void)
{
    USHRT pre_clock, stable_timer, unstable_timer;

    pre_clock = TMDS_GetClock();
    stable_timer = GetTimerTick();
    unstable_timer = stable_timer;

    //Wait the TMDS clock to be stable for 150 ms or unstable for 300 ms
    while ((GetTimerTick()-unstable_timer) < 300) {
        if ((SC_HDMI_CKDT & 0x03) != 0x03) {  // 0x606
            return FALSE;
        }
        if (abs(pre_clock - TMDS_GetClock()) > 2) {
            pre_clock = TMDS_GetClock();
            stable_timer = GetTimerTick();
        }
        if ((GetTimerTick() - stable_timer) > 150) {
            return TRUE;
        }
        ResetWDTimer();
    }

    return FALSE;
}

/**************************************************************************//**
 * According to the TMDS clock, we set some specific registers to get more signal qualities.
 * We reset TMDS phase detection only when clock is stable.
 * @param reset TRUE to reset TMDS phase detection else FALSE.
 ******************************************************************************/
void TMDSBandwidthDetection(UCHAR reset)
{
    reset = 0;
}

/**************************************************************************//**
 * Get digital input HDE pixel count.
 * Before system invoke this function, the input VSync frequency must be determined.
 * This value is determined by the capture block not TMDS block.
 * @return Digital input HDE.
 ******************************************************************************/
USHRT GetDigInputHActive(void)
{
#if 0
    return ReadShortScaler(&SC_DVI_CAP_HWID_LO);
#else
    UCHAR i;
    USHRT hactive, htemp;

    htemp = 0;
    for (i=0; i<5; i++) { //Reg0x03C/Reg0x03D can not be read immediately after 0x6B5[2] was changed
#if (INPUT_INTERFACE & INPUT_DP)
        if ( GetCurrInputInterface() == DISPLAY_PORT_INPUT ) {
            hactive = GetDPInputHDEImmediate();
        }        
        else
#endif
        {
            hactive = ReadShortScaler(&SC_DVI_CAP_HWID_LO);  // 0x3c
        }
        if (htemp != hactive) {
            htemp = hactive;
            DelayVTime(1);
        }
        else {
            break;
        }
    }

    return hactive;
#endif
}

/**************************************************************************//**
 * Get digital input VDE line count.
 * Before system invoke this function, the input VSync frequency must be determined.
 * This value is determined by the capture block not TMDS block.
 * @return Digital input VDE.
 ******************************************************************************/
USHRT GetDigInputVActive(void)
{
#if 0
    if (IsInterlaced()) {
        return ReadShortScaler(&SC_DVI_CAP_VLEN_LO) * 2;
    }
    else {
        return ReadShortScaler(&SC_DVI_CAP_VLEN_LO);
    }
#else
    UCHAR i;
    USHRT vactive, vtemp;

    vtemp = 0;
    for (i=0; i<5; i++) {
        vactive = ReadShortScaler(&SC_DVI_CAP_VLEN_LO); // 0x3e
        if (vtemp != vactive) {
            vtemp = vactive;
            DelayVTime(4);
        }
        else {
            break;
        }
    }

        return vactive;
#endif
}

/**************************************************************************//**
 * Get digital input HDE without any delay.
 * This value is determined by the capture block not TMDS block.
 * @return Digital input HDE.
 ******************************************************************************/
USHRT GetDigInputHActiveImmediate(void)
{
#if ENABLE_HDMI == ON
	#if ENABLE_DVI_DUAL_LINK == ON
	if (TMDS_IsDualLink())
	{
		return ReadShortScalerHighLowFilter(&SC_DVI_CAP_HWID_LO);// 0x3c
	}		
	#endif	

// Because of inconsistent update issue of high/low bytes, we should read hde/vde with filter.
    return ReadShortScalerHighLowFilter(&SC_VIDEO_DE_WIDTH_LO);  // 0x64e
#else
    return ReadShortScalerHighLowFilter(&SC_DVI_CAP_HWID_LO);// 0x3c
#endif
}

/**************************************************************************//**
 * Get digital input VDE without any delay.
 * This value is determined by the capture block not TMDS block.
 * @return Digital input VDE.
 ******************************************************************************/
USHRT GetDigInputVActiveImmediate(void)
{
#if ENABLE_HDMI == ON
	#if ENABLE_DVI_DUAL_LINK == ON
	if (TMDS_IsDualLink())
	{
		return ReadShortScalerHighLowFilter(&SC_DVI_CAP_VLEN_LO);// 0x3e
	}		
	#endif		

    // Because of inconsistent update issue of high/low bytes, we should read hde/vde with filter.
    return ReadShortScalerHighLowFilter(&SC_VIDEO_DE_LINE_LO);  // 0x650
#else
    return ReadShortScalerHighLowFilter(&SC_DVI_CAP_VLEN_LO); // 0x3e
#endif
}

#if ENABLE_HDMI == ON
/**************************************************************************//**
 * Get digital input HTotal without any delay.
 * This value is determined by the TMDS block not capture block.
 * @return Digital input HTotal.
 ******************************************************************************/
USHRT GetDigInputHTotalImmediate(void)
{
    // Because of inconsistent update issue of high/low bytes, we should read h/vtotal with filter.
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1) || (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
    if ((GetCurrInputInterface() == DISPLAY_PORT_INPUT) || (GetCurrInputInterface() == DISPLAY_PORT_INPUT1)
     || (GetCurrInputInterface() == DISPLAY_PORT_INPUT2) || (GetCurrInputInterface() == DISPLAY_PORT_INPUT3)) {
        return ReadShortScalerHighLowFilter(&SC_DP_HTOTAL_LO);  // 0x1090
    }
#endif
    return ReadShortScalerHighLowFilter(&SC_VIDEO_HTOTAL_LO);  // 0x63a
}

/**************************************************************************//**
 * Get digital input VTotal without any delay.
 * This value is determined by the TMDS block not capture block.
 * @return Digital input VTotal.
 ******************************************************************************/
USHRT GetDigInputVTotalImmediate(void)
{
    // Because of inconsistent update issue of high/low bytes, we should read h/vtotal with filter.
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1) || (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
    if ((GetCurrInputInterface() == DISPLAY_PORT_INPUT) || (GetCurrInputInterface() == DISPLAY_PORT_INPUT1)
     || (GetCurrInputInterface() == DISPLAY_PORT_INPUT2) || (GetCurrInputInterface() == DISPLAY_PORT_INPUT3)) {
        return ReadShortScalerHighLowFilter(&SC_DP_VTOTAL_LO);  // 0x1092
    }
#endif
    return ReadShortScalerHighLowFilter(&SC_VIDEO_VTOTAL_LO);  // 0x63c
}
#endif

/**************************************************************************//**
 * Get the count of HSync frequency (from sync processor) of digital timing.
 ******************************************************************************/
void SetDVIPLL(void)
{
    USHRT pixel_rate;

    SC_HPLL_FREQ_CTRL &= ~BIT6;  // 0xd1

#if ENABLE_HDMI == ON
    TMDSDeepColorDetection();
#endif

    SC_HPLL_LINE_CNT = 0x0B;//0x0C; //4096 line  0xdb

    pixel_rate = ReadShortScaler(&SC_GI_HCNT_LO) & 0x1FFF;//  0x19b
    if ((pixel_rate==0x1FFF) || (pixel_rate==0)) {
        ulHFreqCounter = 0xFFFFFFFF;
    }
    else {
        ulHFreqCounter = (ULONG)pixel_rate * 8192;
    }
}

/**************************************************************************//**
 * Turn off TMDS power.
 ******************************************************************************/
void DVI_PowerOff(void)
{
#if (INPUT_INTERFACE&INPUT_MHL_MASK)
    if (IsMHL0Connect() || IsMHL1Connect()) {
        return;
    }
#endif

    SC_POWER_CTRL2 &= ~BIT1; // 0x102
}

/**************************************************************************//**
 * Turn on TMDS power.
 ******************************************************************************/
void DVI_PowerOn(void)
{
    SC_POWER_CTRL2 |= (BIT5 | BIT1);// 0x102
}

void AphyPowerOff(bit pd)
{
    SC_SetByteDPppPHY(_DPPP_PHY0, _DPRM_LANE_HI_CFG, 0x0F);//1AD2
    if (pd == TRUE) {
//        SC_SetByteDPppPHY(_DPPP_PHY0, _DPRM_LANE_HI_CFG, 0x0F);
        SC_SetByteDPppPHY(_DPPP_PHY0, _DP_ANA_CDR_CFG0, 0x10);
        SC_SetByteDPppPHY(_DPPP_PHY0, _DP_ANA_CDR_CFG6, 0x00);
        SC_SetByteDPppPHY(_DPPP_PHY0, _DPRP_REG_1FD, 0x00);
    }
    SC_SetByteDPppPHY(_DPPP_PHY0, _DPPHY_FCTRL, 0x04);//WriteScaler(0x1C00, 0x04);
    SC_SetByteDPppPHY(_DPPP_PHY0, _DPPHY_EQR_IMP_ENABLE, 0x00);//WriteScaler(0x1C02, 0x00);
    SC_SetByteDPppPHY(_DPPP_PHY0, _DPPHY_EQR_RES_CTRL3, 0x00);
    SC_SetByteDPppPHY(_DPPP_PHY0, _DPPHY_EQR_POS_IOFFSET_L0, 0x00);//WriteScaler(0x1C05, 0x00);
    SC_SetByteDPppPHY(_DPPP_PHY0, _DPPHY_BIAS_POWER, 0x00);//WriteScaler(0x1C1C, 0x00);
    SC_SetByteDPppPHY(_DPPP_PHY0, _DPPHY_FA1_DIV, 0x00);//Addr = 0x9C20; *Addr = 0x00;
    SC_SetByteDPppPHY(_DPPP_PHY0, _DPRP_STATUS, 0x10);//CDR off
	SC_SetByteDPppPHY(_DPPP_PHY0, _DPPHY_LDO_CTRL, 0x00);//NT68810 power
#if IS_NT68870_SERIES
    SC_SetByteDPppPHY(_DPPP_PHY1, _DPRM_LANE_HI_CFG, 0x0F);//1AD2
    if (pd == TRUE) {
//        SC_SetByteDPppPHY(_DPPP_PHY1, _DPRM_LANE_HI_CFG, 0x0F);//1AD2
        SC_SetByteDPppPHY(_DPPP_PHY1, _DP_ANA_CDR_CFG0, 0x10);//1B06
        SC_SetByteDPppPHY(_DPPP_PHY1, _DP_ANA_CDR_CFG6, 0x00);//1B0D
        SC_SetByteDPppPHY(_DPPP_PHY1, _DPRP_REG_1FD, 0x00);
    }
    SC_SetByteDPppPHY(_DPPP_PHY1, _DPPHY_FCTRL, 0x04);//WriteScaler(0x1C00, 0x04);
    SC_SetByteDPppPHY(_DPPP_PHY1, _DPPHY_EQR_IMP_ENABLE, 0x00);//WriteScaler(0x1C02, 0x00);
    SC_SetByteDPppPHY(_DPPP_PHY1, _DPPHY_EQR_POS_IOFFSET_L0, 0x00);//WriteScaler(0x1C05, 0x00);
    SC_SetByteDPppPHY(_DPPP_PHY1, _DPPHY_BIAS_POWER, 0x00);//WriteScaler(0x1C1C, 0x00);
    SC_SetByteDPppPHY(_DPPP_PHY1, _DPPHY_FA1_DIV, 0x00);//Addr = 0x9C20; *Addr = 0x00;
    SC_SetByteDPppPHY(_DPPP_PHY1, _DPRP_STATUS, 0x10);//CDR off (with 6502)
	SC_SetByteDPppPHY(_DPPP_PHY1, _DPPHY_LDO_CTRL, 0x00);//NT68810 power
#endif
}
/**************************************************************************//**
 * Turn on the termination power of TMDS clock pair for TMDS clock detection.
 ******************************************************************************/
void TMDS_EnableSCDT(void)
{

}

#if ENABLE_DVI_DUAL_LINK == ON
/*
USHRT GetDualLinkInputHActive(void)
{
    USHRT hactive;
    hactive = GetTMDSPHYDATA(_DPPP_PHY0, _TMDS_DPHY_HACTIVE_HI);
    hactive <<= 8;
    hactive |= GetTMDSPHYDATA(_DPPP_PHY0, _TMDS_DPHY_HACTIVE_LO);	
    //printf("hactive=%d\r\n", hactive);
    return hactive;
}
USHRT GetDualLinkInputVActive(void)
{
    USHRT vactive;
    vactive = GetTMDSPHYDATA(_DPPP_PHY0, _TMDS_DPHY_VACTIVE_HI);
    vactive <<= 8;
    vactive |= GetTMDSPHYDATA(_DPPP_PHY0, _TMDS_DPHY_VACTIVE_LO);	
    //printf("vactive=%d\r\n", vactive);
    return vactive;
}
*/
/**************************************************************************//**
 * Dual link TMDS detection.
 * If the current input is dual link TMDS signal, the bIsDualLink will be TRUE,
 * else FALSE.
 ******************************************************************************/
void TMDS_DualLinkDetection(void)
{
    USHRT hactive, vactive;
	UCHAR ucTMDSLinkClkSel, ucTmpOfDviPllM; 
	BOOL bDualDetection, bSpecialTiming;

    bIsDualLink = FALSE;
	bDualDetection = FALSE;
//    if (GetTMDSPhyLinkSelect() == DIGITAL_INPUT1 && GetTMDSPHYDATA(_DPPP_PHY0, _HDMI_MHL_INFO)==HDMI_NRM && (SC_HDMI_MHL_MODE_DETECT&BIT7)==0) { //DVI Input
    if ((GetTMDSPhyLinkSelect() == DIGITAL_INPUT1) && (GetTMDSPHYDATA(_DPPP_PHY0, _HDMI_MHL_INFO) == HDMI_NRM)) { //not MHL Input
//        printf("Dual DVI detect 1\r\n");
		SC_SetBitDPppPHY(_DPPP_PHY1, _DPPHY_LDO_CTRL, BIT7, FALSE);
		SC_TMDS_PHY_LINK_CTRL_1DE0 &= ~BIT3;  // 0x1de0
		//Sleep(20);
		
		ucTMDSLinkClkSel = SC_TMDS_LINK_CLK_SEL;  // 0x1e7
		ucTmpOfDviPllM = SC_DVI_PLL_M;		// 0xb18
		
        hactive = GetDigInputHActive();//GetDualLinkInputHActive();//
        vactive = GetDigInputVActive();//GetDualLinkInputVActive();//

		bSpecialTiming = FALSE;
		if (hactive==1280 && vactive==1080){
			bSpecialTiming = TRUE;
		}	
        if (((SC_HDMI_MHL_MODE_DETECT & (BIT7|BIT4)) == 0x00)  // 0x630
          && (SC_HDMI_DET&BIT0)==0x00 && (SC_HDMI_CKDT&BIT0) // 0x734,0x606
          && ((vactive > hactive) || bSpecialTiming)) { //Dual Link DVI Input //special: 2560x1080p60
            //printf("Dual DVI detect 2\r\n");
//            TMDSInitPhy(_DPPP_PHY0);
#if ENABLE_EMBEDED_TMDS_CLOCK_TRAINING == OFF
            TMDSInitPhy(_DPPP_PHY1);		
			SC_SetBitDPppPHY(_DPPP_PHY1, _DPPHY_LDO_CTRL, BIT7, TRUE);
#endif			
			SC_TMDS_LINK_CLK_SEL = SCREG_1E7 | BIT0 | BIT7;// 0x1e7
			SC_DVI_PLL_M = 0x20;// 0xb18
            SC_TMDS_PHY_LINK_CTRL_1DE1 |= BIT1; // 0x1de1
			//Sleep(20);
									
            TMDSDataAlign(_DPPP_PHY0);
#if ENABLE_EMBEDED_TMDS_CLOCK_TRAINING == ON
            SC_SetByteDPppPHY(_DPPP_PHY0, _DPPHY_EQR_POS_IOFFSET_L2, BIT0);
#else
            ClearTMDSTraining();
            TMDSClockTraining(_DPPP_PHY0, TRUE);
#endif
            TMDSDataAlign(_DPPP_PHY1);
#if ENABLE_EMBEDED_TMDS_CLOCK_TRAINING == ON
            SetTMDS6502Active(_DPPP_PHY1);
//            Sleep(10);
            SC_SetBitDPppPHY(_DPPP_PHY1, _DPPHY_LDO_CTRL, BIT7, TRUE); //Roger add
            SC_SetByteDPppPHY(_DPPP_PHY1, _DPPHY_EQR_POS_IOFFSET_L2, BIT0);
            vactive = 100;
            while ((GetTMDSPHYDATA(_DPPP_PHY1, _DPPHY_EQR_POS_IOFFSET_L2) != 0x00) && (vactive != 0)) {
                Sleep(1);
                vactive--;
            }
#else
            ClearTMDSTraining();
            TMDSClockTraining(_DPPP_PHY1, TRUE);
#endif
            if (IsTMDSLBR(_DPPP_PHY0) == TRUE) {
                SC_SetByteDPppPHY(_DPPP_PHY0, _DPPHY_FA1_DIV, 0xC2);//Addr = 0x9C20; *Addr = 0xC2;
                SC_SetByteDPppPHY(_DPPP_PHY0, _DPPHY_FA1_FREQ_HI, 0x0A);//Addr = 0x9C21; *Addr = 0x19;
                SC_SetByteDPppPHY(_DPPP_PHY0, _DPPHY_FA1_FREQ_MI, 0x00);//Addr = 0x9C22; *Addr = 0x00;
                SC_SetByteDPppPHY(_DPPP_PHY0, _DPPHY_FA1_FREQ_LO, 0x00);//Addr = 0x9C23; *Addr = 0x00;
            }
            else {
                SC_SetByteDPppPHY(_DPPP_PHY0, _DPPHY_FA1_DIV, 0xC0);//Addr = 0x9C20; *Addr = 0xC0;
                SC_SetByteDPppPHY(_DPPP_PHY0, _DPPHY_FA1_FREQ_HI, 0x0A);//Addr = 0x9C21; *Addr = 0x19;
                SC_SetByteDPppPHY(_DPPP_PHY0, _DPPHY_FA1_FREQ_MI, 0x00);//Addr = 0x9C22; *Addr = 0x00;
                SC_SetByteDPppPHY(_DPPP_PHY0, _DPPHY_FA1_FREQ_LO, 0x00);//Addr = 0x9C23; *Addr = 0x00;
            }			

            SC_TMDS_PHY_LINK_CTRL_1DE0 |= BIT3; // 0x1de0
            bIsDualLink = TRUE;
			bDualDetection = TRUE;

            for (vactive=0; vactive<100; vactive++) {   //2011-07-15 wasy: To wait Hactive become 2*hactive after set SC_DVI_PLL_M=0x10 (from Mingyu)
                Sleep(20);
                if (hactive < GetDigInputHActive()) {
                    break;
                }
            }

			hactive = GetDigInputHActive()/2;//GetDualLinkInputHActive();//
			vactive = GetDigInputVActive();//GetDualLinkInputVActive();//
			if ((vactive < hactive) && (!bSpecialTiming)){
				bIsDualLink = FALSE;				
			}	
        }
        else{
            bIsDualLink = FALSE;
        }            

        if (bIsDualLink == FALSE && bDualDetection==TRUE) {
            SC_TMDS_LINK_CLK_SEL = ucTMDSLinkClkSel;// 0x1e7
			SC_DVI_PLL_M = ucTmpOfDviPllM;// 0xb18
            SC_TMDS_PHY_LINK_CTRL_1DE0 &= ~BIT3; // 0x1de0
			SC_SetBitDPppPHY(_DPPP_PHY1, _DPPHY_LDO_CTRL, BIT7, FALSE); // _DPPHY_DUAL_LINK

			SC_SetByteDPppPHY(_DPPP_PHY0, _DPPHY_FA1_DIV, 0x00);//Addr = 0x9C20; *Addr = 0xC2;
			SC_SetByteDPppPHY(_DPPP_PHY0, _DPPHY_FA1_FREQ_HI, 0x00);//Addr = 0x9C21; *Addr = 0x19;
			SC_SetByteDPppPHY(_DPPP_PHY0, _DPPHY_FA1_FREQ_MI, 0x00);//Addr = 0x9C22; *Addr = 0x00;
			SC_SetByteDPppPHY(_DPPP_PHY0, _DPPHY_FA1_FREQ_LO, 0x00);//Addr = 0x9C23; *Addr = 0x00;
        }		
        // XXX Why HDMI reset here?
        SC_HDMI_SOFTWARE_RESET &= ~BIT4;  // 0x605
        Sleep(20);
        SC_HDMI_SOFTWARE_RESET |= BIT4;
    }
}

/**************************************************************************//**
 * Get the present status of dual link TMDS.
 * @return TRUE if input is dual link TMDS signal else FALSE.
 ******************************************************************************/
BOOL TMDS_IsDualLink(void)
{
    if (GetTMDSPhyLinkSelect() == DIGITAL_INPUT1) { //DVI Input
        //return bIsDualLink;
        if (SC_TMDS_PHY_LINK_CTRL_1DE0&BIT3) { // 0x1de0
			return TRUE;
        }
		else {
			return FALSE;
		}	
    }

    return FALSE;
}
#endif

/**************************************************************************//**
 * Get current TMDS clock.
 * @return TMDS clock frequency.
 ******************************************************************************/
USHRT TMDS_GetClock(void)
{
USHRT clk_tmp;
#if REF_CLK==12000000
    if ((SC_DVI_STATUS & BIT0) != 0) {
    #if (INPUT_INTERFACE&INPUT_MHL_MASK)
        if (MHL_IsPackedPixelMode(MHL_CBUS_CH1) || MHL_IsPackedPixelMode(MHL_CBUS_CH2)) { //get correct PHY clock 0x016 after set 0x159.6=0
            //printf("A:TMDS_GetClock_PP %d\r\n",(USHRT)SC_TMDS_CLOCK_DET);
            return SC_TMDS_CLOCK_DET;  // 0x16
        }
    #endif
        clk_tmp = ReadShortScaler(&SC_DVI_PIXELCLK_LO) & 0x0FFF; // 0x304
        return clk_tmp;
    }
#else
#define OSC_FREQ_RATIO ((float)REF_CLK/12000000)
    if ((SC_DVI_STATUS & BIT0) != 0) {  // 0x1ad
    #if (INPUT_INTERFACE&INPUT_MHL_MASK)
        if (MHL_IsPackedPixelMode(MHL_CBUS_CH1) || MHL_IsPackedPixelMode(MHL_CBUS_CH2)) { //get correct PHY clock 0x016 after set 0x159.6=0
            clk_tmp = (USHRT)SC_TMDS_CLOCK_DET * OSC_FREQ_RATIO;// 0x16
            return clk_tmp;
        }
    #endif
        clk_tmp = (USHRT)((ReadShortScaler(&SC_DVI_PIXELCLK_LO) & 0x0FFF) * OSC_FREQ_RATIO);// 0x304
        return clk_tmp;
    }
#undef OSC_FREQ_RATIO
#endif
    return 0;
}

UCHAR GetTMDSPHYDATA(UCHAR phyindex, USHRT address)
{
    UCHAR value;
    
#if IS_NT68810_SERIES
    phyindex = _DPPP_PHY0;
	if (address <= 0x17F) {
        if (phyindex == _DPPP_PHY0) {
            address += 0x1A00;
        }
        else {
            address += 0x1700;
        }
		SC_DPPPAPHY_ADDR_HI = (UCHAR)(address>>8);  // 0x1df0
		SC_DPPPAPHY_ADDR_LO = (UCHAR)address;// 0x1df1
		value = SC_DPPPAPHY_DATA;// 0x1df2
		value = SC_DPPPAPHY_DATA;// 0x1df2
	}
	else {
        if (phyindex == _DPPP_PHY0) {
            value = SC_DPpp_CFG_TMDS_1A00[address];
            value = SC_DPpp_CFG_TMDS_1A00[address];
        }
        else {
            value = SC_DPpp_CFG_TMDS_1700[address];
            value = SC_DPpp_CFG_TMDS_1700[address];
        }
	}	
#else
    if (phyindex == _DPPP_PHY0) {
        address += 0x1A00;
    }
    else {
        address += 0x1700;
    }
    SC_DPPPAPHY_ADDR_HI = (UCHAR)(address>>8);// 0x1df0
    SC_DPPPAPHY_ADDR_LO = (UCHAR)address;// 0x1df1
    value = SC_DPPPAPHY_DATA;// 0x1df2
    value = SC_DPPPAPHY_DATA;// 0x1df2
#endif
    return value;
}

void SC_SetByteDPppPHY(UCHAR phyindex, USHRT reg, UCHAR value)
{
#if IS_NT68810_SERIES
    phyindex = _DPPP_PHY0;
#endif
    if (phyindex == _DPPP_PHY0) {
        SC_DPpp_CFG_TMDS_1A00[reg] = value;
    }
    else {
        SC_DPpp_CFG_TMDS_1700[reg] = value;
    }
}

void SC_SetBitDPppPHY(UCHAR phyindex, USHRT reg, UCHAR mask, UCHAR value)
{
	UCHAR ucTmp;

#if IS_NT68810_SERIES
    phyindex = _DPPP_PHY0;
#endif
	ucTmp = GetTMDSPHYDATA(phyindex, reg);
	if (value == TRUE) { 
		ucTmp |= mask; 			
	}
	else {
		ucTmp &= ~mask; 
	}
    if (phyindex == _DPPP_PHY0) {
        SC_DPpp_CFG_TMDS_1A00[reg] = ucTmp;
    }
    else {
        SC_DPpp_CFG_TMDS_1700[reg] = ucTmp;
    }
}


#if ENABLE_EMBEDED_TMDS_CLOCK_TRAINING == OFF
void TMDSClockTraining(UCHAR phyindex, BOOL bForce)
{
#define BA_VALUE_TOO_LARGE 0x01
#define BA_VALUE_TOO_SMALL 0x02
//    UCHAR volatile xdata *Addr;
    UCHAR i, reg_value, vco_spd, cdr_enc, cdr_band, k, m, vcolockflag, n;
    USHRT ext_counter, int_counter;
    bit lbr_flag, error;

//	static UCHAR ucCount=0;
	// Check Mode
	// HDMI_NRM, <= 340MHz (HDMI1.4/HDMI2.0)
	// HDMI_HSP, >340MHz   (HDMI2.0)
	// MHL2_NRM, mhl2.0 24-bit mode 
	// MHL2_PPM, mhl2.0 pp mode
	// MHL3_1P5G, mhl3.0 1.5G
	// MHL3_3P0G, mhl3.0 3.0G
	// MHL3_6P0G, mhl3.0 6.0G

	if (!bForce) {
		//	  if ((SC_DVI_STATUS & BIT1) == 0) {
	    if ((SC_HDMI_CKDT & BIT1) == 0) { // 0x606
            ClearTMDSTraining();
	        return;
	    }

	    if (bTMDSClockTraining == FALSE) {
	        if ((GetTimerTick()-usTMDSTrainingTimer) < 500) {
	            return;
	        }
            if ((SC_HDMI_CKDT & 0x03) == 0x03) { // 0x606
                return;
            }
	    }
	}	
    vcolockflag = 0;
    SC_SetBitDPppPHY(phyindex, _TMDS_DPHY_CLOCK_ENABLE, BIT7, FALSE);//Addr = 0x9B90; *Addr &= ~BIT7;	  //disable TMDS channel phase lock

    SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG2, 0x06);//Addr = 0x9B08; *Addr = 0x06;		//dp_ana_cdr_cfg2
    SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG4, 0x20);//Addr = 0x9B0A; *Addr = 0x20;		//dp_ana_cdr_cfg4
    SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x0F);//Addr = 0x9AD2; *Addr = 0x0F;		  //dprm_lane_hi_cfg
    SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG1, 0x0C);//Addr = 0x9B07; *Addr = 0x0C;		 //dp_ana_cdr_cfg1
    SC_SetByteDPppPHY(phyindex, _DP_ANA_S2P_CFG, 0x30);//Addr = 0x9B0C; *Addr = 0x32;		//dp_ana_s2p_cfg
    SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_CFG, 0x00);//Addr = 0x9B20; *Addr = 0x00; 	   //dp_rxanaif_vbs_cfg
    SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG, 0x00);//Addr = 0x9B40; *Addr = 0x00; 	   //dp_rxanaif_aeq_cfg
    SC_SetByteDPppPHY(phyindex, _DP_RXANAIF_CFG0, 0x12);//auto EQ, and Reg0x8242=0x31
#if 0
    SC_SetByteDPppPHY(phyidex, _DPRM_LANE_HI_CFG, 0x0F);
    SC_SetByteDPppPHY(phyidex, _DP_ANA_CDR_CFG7, 0x02);//Addr = 0x9B0E; *Addr = vco_spd;
#else
//    SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x0F);
//    SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG7, 0x01);//Addr = 0x9B0E; *Addr = vco_spd;
//    SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_BASEL, 0x80);
#endif
    
    Sleep(1);
//		printf("TMDSClockTraining\r\n");
    for(k=0; k<3; k++) {
        i = ucTMDSInputMode;
        ucTMDSInputMode = GetTMDSPHYDATA(phyindex, _HDMI_MHL_INFO);//hdmi_mhl_info
#ifdef FORCE_SCRAMBLE_ON
        ucTMDSInputMode = HDMI_HSP;
#endif
        if (ucTMDSInputMode == HDMI_HSP) {//HDMI_HSP
            SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x0E);
///////////////////////////////////////////////////////////////////////////////
#ifdef ENABLE_HF_TMDS_AUTOEQ //auto EQ
            SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG3, 0x03);//0x0F);//Addr = 0x9B49; *Addr = 0x0F;//dp_rxanaif_aeq_cfg3		
            SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG4, 0x00);//Addr = 0x9B4A; *Addr = 0x03;//0x01;//dp_rxanaif_aeq_cfg4
            SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG5, 0x00);
            SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG2, 0x31);//Addr = 0x9B42; *Addr = 0x13;//dp_rxanaif_aeq_cfg2				
#else //Manual EQ
#if 1 // For ALLION
            SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG3, 0x03); // Pass IST & ALLION
            SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG4, 0x3F); // Pass ALLION
            SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG5, 0x00); // Pass IST	 & ALLION	
            SC_SetByteDPppPHY(phyindex, _DPPHY_IMPEDANCE_L0_L2_L3, 0x1F); // Pass ALLION
            SC_SetByteDPppPHY(phyindex, _DPPHY_IMPEDANCE_L1, 0x1F); // Pass ALLION
#else // For IST
            SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG3, 0x03); // Pass IST & ALLION 
            SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG4, 0x0F); // Pass IST	
            SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG5, 0x00); // Pass IST & ALLION 
            SC_SetByteDPppPHY(phyindex, _DPPHY_IMPEDANCE_L0_L2_L3, 0x1A); // Pass IST
            SC_SetByteDPppPHY(phyindex, _DPPHY_IMPEDANCE_L1, 0x1A); // Pass IST
#endif
            SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG2, 0x33);//Addr = 0x9B42; *Addr = 0x13;//dp_rxanaif_aeq_cfg2	
#endif
        }
        else {
            if ( 0
                 #if (INPUT_INTERFACE&INPUT_MHL0)            
                 || (phyindex==_DPPP_PHY0 && IsMHL0Connect() && GetCurrInputInterface()==DIGITAL_INPUT0) 
                 #endif
                 #if (INPUT_INTERFACE&INPUT_MHL1)
                 || (phyindex==_DPPP_PHY0 && IsMHL1Connect() && GetCurrInputInterface()==DIGITAL_INPUT1)
                 #endif
                 #if (INPUT_INTERFACE&INPUT_MHL2)            
                 || (phyindex==_DPPP_PHY1 && IsMHL0Connect() && GetCurrInputInterface()==DIGITAL_INPUT2) 
                 #endif
                 #if (INPUT_INTERFACE&INPUT_MHL3)
                 || (phyindex==_DPPP_PHY1 && IsMHL1Connect() && GetCurrInputInterface()==DIGITAL_INPUT3)
                 #endif				 
               )
            {
                     SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x0E);
                     SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG3, 0x0F);// 0x0F, PASS min/max & skew, // 0x07, PASS jitter no cable	//Addr = 0x9B49; *Addr = 0x0F;//dp_rxanaif_aeq_cfg3 	 
                     SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG4, 0xFF);// 0x0FF, PASS min/max & skew, // 0x1F, PASS jitter no cable
                     SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG5, 0x01); // 0x01, PASS min/max & skew // 0x00, PASS jitter no cable
                     SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG2, 0x06);			 
                 #if 1
                     SC_SetByteDPppPHY(phyindex, _DPPHY_IMPEDANCE_L0_L2_L3, 0x18);
                     SC_SetByteDPppPHY(phyindex, _DPPHY_IMPEDANCE_L1,	   0x18);			 
                 #endif			
                     SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG2, 0x33);//Addr = 0x9B42; *Addr = 0x11;//dp_rxanaif_aeq_cfg2
            }
            else
            {	
                SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x0E);
                SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG3, 0x07);//Addr = 0x9B49; *Addr = 0x0F;//dp_rxanaif_aeq_cfg3		
                SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG4, 0xFF);
                SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG5, 0xFF);
                SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG2, 0x06);
            #ifndef ENABLE_HF_TMDS_AUTOEQ
                SC_SetByteDPppPHY(phyindex, _DPPHY_IMPEDANCE_L0_L2_L3, 0x18);
                SC_SetByteDPppPHY(phyindex, _DPPHY_IMPEDANCE_L1, 0x18);			
            #endif
                SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG2, 0x31);//Addr = 0x9B42; *Addr = 0x11;//dp_rxanaif_aeq_cfg2
            }	 
        }
///////////////////////////////////////////////////////////////////////////////
        if (ucTMDSInputMode == HDMI_NRM) {//HDMI_NRM
            SC_SetByteDPppPHY(phyindex, _DPPHY_FCTRL, 0x06);//Addr = 0x9C00; *Addr = 0x06;//0x1C00= 0x06
//            SC_HDMI_DATA_ALIGN &= ~BIT0;
        }
        else if (ucTMDSInputMode == HDMI_HSP) {//HDMI_HSP
            SC_SetByteDPppPHY(phyindex, _DPPHY_FCTRL, 0x36);//Addr = 0x9C00; *Addr = 0x16;//0x1C00= 0x16
//            SC_HDMI_DATA_ALIGN |= BIT0;
            
        }
        else {//MHL
            SC_SetByteDPppPHY(phyindex, _DPPHY_FCTRL, 0x8E);//Addr = 0x9C00; *Addr = 0x8E;//0x1C00= 0x8E
//            if (ucTMDSInputMode == MHL2_PPM) {//PP mode
//               SC_HDMI_DATA_ALIGN |= BIT0;
//            }
//            else {
//                SC_HDMI_DATA_ALIGN &= ~BIT0;
//            }
        }
        Sleep(1);
        
    //printf("ucTMDSInputMode=0x%bx \r\n",ucTMDSInputMode);
/*
if (i != ucTMDSInputMode) {//???
    	// Disable CDR at first
    	// Lane0 Disable
        SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x01);//Addr = 0x9AD2; *Addr = 0x01;// ADDR_DPRM_LANE_HI_CFG
        reg_value = GetTMDSPHYDATA(phyindex, _DP_ANA_CDR_CFG0);// ADDR_DP_ANA_CDR_CFG0
    	reg_value &= 0xFE;// CDR_EN_CDR //reg_value = {reg_value[7:1], 1'h0};		// CDR_EN_CDR
        SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG0, reg_value);//Addr = 0x9B06; *Addr = reg_value;// ADDR_DP_ANA_CDR_CFG0
    
    	// Lane1 Disable
        SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x02);//Addr = 0x9AD2; *Addr = 0x02;// ADDR_DPRM_LANE_HI_CFG
        reg_value = GetTMDSPHYDATA(phyindex, _DP_ANA_CDR_CFG0);// ADDR_DP_ANA_CDR_CFG0
    	reg_value &= 0xFE;// CDR_EN_CDR //reg_value = {reg_value[7:1], 1'h0};		// CDR_EN_CDR
        SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG0, reg_value);//Addr = 0x9B06; *Addr = reg_value;// ADDR_DP_ANA_CDR_CFG0
    
        // Lane2 Disable
        SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x04);//Addr = 0x9AD2; *Addr = 0x04;// ADDR_DPRM_LANE_HI_CFG
        reg_value = GetTMDSPHYDATA(phyindex, _DP_ANA_CDR_CFG0);// ADDR_DP_ANA_CDR_CFG0
    	reg_value &= 0xFE;// CDR_EN_CDR //reg_value = {reg_value[7:1], 1'h0};		// CDR_EN_CDR
        SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG0, reg_value);//Addr = 0x9B06; *Addr = reg_value;// ADDR_DP_ANA_CDR_CFG0
    
    	// Lane3 Disable
        SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x08);//Addr = 0x9AD2; *Addr = 0x08;// ADDR_DPRM_LANE_HI_CFG
        reg_value = GetTMDSPHYDATA(phyindex, _DP_ANA_CDR_CFG0);// ADDR_DP_ANA_CDR_CFG0
    	reg_value &= 0xFE;// CDR_EN_CDR //reg_value = {reg_value[7:1], 1'h0};		// CDR_EN_CDR
        SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG0, reg_value);//Addr = 0x9B06; *Addr = reg_value;// ADDR_DP_ANA_CDR_CFG0
}
*/

#if 0	
		SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x0F);
		SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG7, 0x08);//Addr = 0x9B0E; *Addr = vco_spd;
		SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_BASEL, 0x80);
        reg_value = GetTMDSPHYDATA(phyindex, _DP_ANA_CDR_CFG0);// ADDR_DP_ANA_CDR_CFG0
        reg_value &= 0xF1;//reg_value = {reg_value[7:4], cdr_enc, reg_value[0]};	// CDR_ENC[2:0]
//        reg_value |= cdr_enc;
        SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG0, reg_value);//Addr = 0x9B06; *Addr = reg_value;// ADDR_DP_ANA_CDR_CFG0
#else
		vco_spd = 0x08;
		if ((vco_spd == 0x1) || (vco_spd == 0x2)) {
			cdr_enc = 0x0E;//3'b111;
		}
		if ((vco_spd == 0x3) || (vco_spd == 0x4)) {
			cdr_enc = 0x06;//3'b011;
		}
		if ((vco_spd == 0x5) || (vco_spd == 0x6)) {
			cdr_enc = 0x02;//3'b001;
		}
		if (vco_spd > 0x6) {
			cdr_enc = 0x00;//3'b000;
		}

		SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x0F);//Addr = 0x9AD2; *Addr = 0x02; 	// ADDR_DPRM_LANE_HI_CFG
		SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG7, vco_spd);//Addr = 0x9B0E; *Addr = vco_spd;
		SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_BASEL, 0x80);
		reg_value = GetTMDSPHYDATA(phyindex, _DP_ANA_CDR_CFG0);// ADDR_DP_ANA_CDR_CFG0
		reg_value &= 0xF1;//reg_value = {reg_value[7:4], cdr_enc, reg_value[0]};	// CDR_ENC[2:0]
		reg_value |= cdr_enc;
		SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG0, reg_value);//Addr = 0x9B06; *Addr = reg_value;// ADDR_DP_ANA_CDR_CFG0		
#endif  

		// DIV SEL (Settings)
    	if ((ucTMDSInputMode == HDMI_NRM) || (ucTMDSInputMode == HDMI_HSP)) { // HDMI_NRM / HDMI_HSP
            SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x0E);//Addr = 0x9AD2; *Addr = 0x0E;// ADDR_DPRM_LANE_HI_CFG
        }
        else {
            SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x02);//Addr = 0x9AD2; *Addr = 0x02;// ADDR_DPRM_LANE_HI_CFG
        }
    
        SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG6, 0x08);//Addr = 0x9B0D; *Addr = 0x08;// ADDR_DP_ANA_CDR_CFG6
        if (ucTMDSInputMode == HDMI_NRM) { // HDMI_NRM
            SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG8, 0x01);//Addr = 0x9B0F; *Addr = 0x01;		// ADDR_DP_ANA_CDR_CFG8
        }
        
        if (ucTMDSInputMode == HDMI_HSP) { // HDMI_HSP
            SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG8, 0x08);//Addr = 0x9B0F; *Addr = 0x08;		// ADDR_DP_ANA_CDR_CFG8
        }
        
        if (ucTMDSInputMode == MHL2_NRM) { // MHL2_NRM
            SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG8, 0x04);//Addr = 0x9B0F; *Addr = 0x04;		// ADDR_DP_ANA_CDR_CFG8
        }
        
        if (ucTMDSInputMode == MHL2_PPM) { // MHL2_PPM
            SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG8, 0x08);//Addr = 0x9B0F; *Addr = 0x08;		// ADDR_DP_ANA_CDR_CFG8
        }
        
        if (ucTMDSInputMode == MHL3_1P5G) { // MHL3_1P5G
            SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG8, 0x02);//Addr = 0x9B0F; *Addr = 0x02;		// ADDR_DP_ANA_CDR_CFG8
        }
        
        if (ucTMDSInputMode == MHL3_3P0G) { // MHL3_3P0G
            SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG8, 0x08);//Addr = 0x9B0F; *Addr = 0x08;		// ADDR_DP_ANA_CDR_CFG8
        }
        
        if (ucTMDSInputMode == MHL3_6P0G) { // MHL3_6P0G
            SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG8, 0x10);//Addr = 0x9B0F; *Addr = 0x10;		// ADDR_DP_ANA_CDR_CFG8
        }
        
    	// REF_CK SEL (Settings)
        if ((ucTMDSInputMode == HDMI_NRM) || (ucTMDSInputMode == HDMI_HSP)) { // HDMI_NRM / HDMI_HSP
            SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x0E);//Addr = 0x9AD2; *Addr = 0x0E;		// ADDR_DPRM_LANE_HI_CFG
        }
        else {
            SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x02);//Addr = 0x9AD2; *Addr = 0x02;		// ADDR_DPRM_LANE_HI_CFG
        }
        
        if ((ucTMDSInputMode == HDMI_NRM) || (ucTMDSInputMode == HDMI_HSP)) { // HDMI_NRM / HDMI_HSP
            SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_FCNT_CFG, 0x11);//Addr = 0x9B33; *Addr = 0x11;		// ADDR_DP_RXANAIF_VBS_FCNT_CFG
        }
        else if ((ucTMDSInputMode == MHL2_NRM) || (ucTMDSInputMode == MHL2_PPM)) { // MHL2_NRM / MHL2_PPM
            SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_FCNT_CFG, 0x11);//Addr = 0x9B33; *Addr = 0x11;		// ADDR_DP_RXANAIF_VBS_FCNT_CFG
        }
        else if ((ucTMDSInputMode == MHL3_1P5G) || (ucTMDSInputMode == MHL3_3P0G) || (ucTMDSInputMode == MHL3_6P0G)) { // MHL3_1P5G / MHL3_3P0G / MHL3_6P0G
            SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_FCNT_CFG, 0x21);//Addr = 0x9B33; *Addr = 0x21;		// ADDR_DP_RXANAIF_VBS_FCNT_CFG
        }
        
    	// LBR Flag (Settings)
    	lbr_flag = FALSE;
    	if ((ucTMDSInputMode == HDMI_NRM) || (ucTMDSInputMode == HDMI_HSP)) { // HDMI_NRM / HDMI_HSP
            SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x0E);//Addr = 0x9AD2; *Addr = 0x0E;		// ADDR_DPRM_LANE_HI_CFG
    	}
    	else {
            SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x02);//Addr = 0x9AD2; *Addr = 0x02;		// ADDR_DPRM_LANE_HI_CFG
    	}
    
        if ((ucTMDSInputMode == HDMI_NRM) || (ucTMDSInputMode == MHL2_NRM) || (ucTMDSInputMode == MHL2_PPM)) {
            // Use Counter to Check REF_CK
            SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_CFG, 0xB0);//Addr = 0x9B20; *Addr = 0xB0;//system.i_pbusm.write(0x20, 0xb0);		// ADDR_DP_RXANAIF_VBS_CFG, dp_rxanaif_vbs_done_md
            SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_PERIOD_L, 0xC0);//Addr = 0x9B24; *Addr = 0xC0;		// ADDR_DP_RXANAIF_VBS_PERIOD_L, 2us
            SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_PERIOD_H, 0x00);//Addr = 0x9B25; *Addr = 0x00;//system.i_pbusm.write(0x25, 0x00);		// ADDR_DP_RXANAIF_VBS_PERIOD_H
            SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_CFG1, 0x00);//Addr = 0x9B2E; *Addr = 0x00;		// ADDR_DP_RXANAIF_VBS_CFG1, dp_rxanaif_vbs_fcnt1_en
            if (ucTMDSInputMode == HDMI_NRM) {
                SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_FNUM_L, 0xF0);//Addr = 0x9B22; *Addr = 0xF0;//system.i_pbusm.write(0x22, 0xf0);		// ADDR_DP_RXANAIF_VBS_FNUM_L, Target 240 @ 2us
                SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_FNUM_H, 0x00);//Addr = 0x9B23; *Addr = 0x00;//system.i_pbusm.write(0x23, 0x00);		// ADDR_DP_RXANAIF_VBS_FNUM_H
            }
            if (ucTMDSInputMode == MHL2_NRM) {
                SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_FNUM_L, 0x50);//Addr = 0x9B22; *Addr = 0x50;//system.i_pbusm.write(0x22, 0x50);		// ADDR_DP_RXANAIF_VBS_FNUM_L, Target 80 @ 2us
                SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_FNUM_H, 0x00);//Addr = 0x9B23; *Addr = 0x00;//system.i_pbusm.write(0x23, 0x00);		// ADDR_DP_RXANAIF_VBS_FNUM_H
            }
            if (ucTMDSInputMode == MHL2_PPM) {
                SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_FNUM_L, 0x3C);//Addr = 0x9B22; *Addr = 0x3C;//system.i_pbusm.write(0x22, 0x3c);		// ADDR_DP_RXANAIF_VBS_FNUM_L, Target 60 @ 2us
                SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_FNUM_H, 0x00);// Addr = 0x9B23; *Addr = 0x00;//system.i_pbusm.write(0x23, 0x00);		// ADDR_DP_RXANAIF_VBS_FNUM_H
            }
            SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x02);//Addr = 0x9AD2; *Addr = 0x02;//system.i_pbusm.write(0xd2, 0x02);		// ADDR_DPRM_LANE_HI_CFG
            SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_CFG, 0xB1);//Addr = 0x9B20; *Addr = 0xB1;//system.i_pbusm.write(0x20, 0xb1);		// ADDR_DP_RXANAIF_VBS_CFG, dp_rxanaif_vbs_trig_pls
            reg_value = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_CFG);// ADDR_DP_ANA_CDR_CFG0
            i = 255;
            while (((reg_value & BIT0) != 0) && (i != 0)) {
//                Sleep(1);
                reg_value = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_CFG);// ADDR_DP_ANA_CDR_CFG0
                i--;
            }
    
            reg_value = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_STS);// ADDR_DP_RXANAIF_VBS_STS
            if(reg_value & BIT0 != 0x00) {
                lbr_flag = TRUE;
            }
        }
    //printf("test 1\r\n");
    //printf("Reg0x1B29=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT_L));
    //printf("Reg0x1B2A=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT_H));
    //printf("Reg0x1B34=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT1_L));
    //printf("Reg0x1B35=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT1_H));
    //printf("Reg0x1B0E=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DP_ANA_CDR_CFG7));
    //printf("Reg0x1B28=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_BASEL));
        	// LBR Flag for Lane1 ~ Lane3 or Lane1 Only
    	if ((ucTMDSInputMode == HDMI_NRM) || (ucTMDSInputMode == HDMI_HSP)) { // HDMI_NRM / HDMI_HSP
            SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x0E);//Addr = 0x9AD2; *Addr = 0x0E;		// ADDR_DPRM_LANE_HI_CFG
    	}
    	else {
            SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x02);//Addr = 0x9AD2; *Addr = 0x02;		// ADDR_DPRM_LANE_HI_CFG
    	}
    
        reg_value = GetTMDSPHYDATA(phyindex, _DP_ANA_CDR_CFG6);// ADDR_DP_ANA_CDR_CFG6
    	if (lbr_flag == TRUE) { //reg_value = {reg_value[7:2], lbr_flag, reg_value[0]};	// CDR_LBR_FLAG
            reg_value |= BIT1;
        }
        else {
            reg_value &= ~BIT1;
        }
    	SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG6, reg_value);//Addr = 0x9B0D; *Addr = reg_value;//system.i_pbusm.write(0x0d, reg_value);		// ADDR_DP_ANA_CDR_CFG6
    
    	// Lane Enable (Settings)
    	// Lane1 Enable
    	SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x02);//Addr = 0x9AD2; *Addr = 0x02;		// ADDR_DPRM_LANE_HI_CFG
        reg_value = GetTMDSPHYDATA(phyindex, _DP_ANA_CDR_CFG0);// ADDR_DP_ANA_CDR_CFG0
    	reg_value |= 0x01;// CDR_EN_CDR //reg_value = {reg_value[7:1], 1'h1};		// CDR_EN_CDR
        SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG0, reg_value);//Addr = 0x9B06; *Addr = reg_value;// ADDR_DP_ANA_CDR_CFG0
    //reset VCO////
//??        Sleep(1);
        reg_value |= BIT4;// CDR_EN_CDR //reg_value = {reg_value[7:1], 1'h1};          // CDR_EN_CDR
        SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG0, reg_value);//Addr = 0x9B06; *Addr = reg_value;// ADDR_DP_ANA_CDR_CFG0
//        Sleep(1);
        reg_value &= ~BIT4;// CDR_EN_CDR //reg_value = {reg_value[7:1], 1'h1};          // CDR_EN_CDR
        SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG0, reg_value);//Addr = 0x9B06; *Addr = reg_value;// ADDR_DP_ANA_CDR_CFG0  
    //////////////
    	if ((ucTMDSInputMode == HDMI_NRM) || (ucTMDSInputMode == HDMI_HSP)) { // HDMI_NRM / HDMI_HSP
    	  // Lane2 Enable
            SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x04);//Addr = 0x9AD2; *Addr = 0x04;		// ADDR_DPRM_LANE_HI_CFG
            reg_value = GetTMDSPHYDATA(phyindex, _DP_ANA_CDR_CFG0);// ADDR_DP_ANA_CDR_CFG0
            reg_value |= 0x01;// CDR_EN_CDR //reg_value = {reg_value[7:1], 1'h1};		// CDR_EN_CDR
            SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG0, reg_value);//Addr = 0x9B06; *Addr = reg_value;// ADDR_DP_ANA_CDR_CFG0
        //reset VCO////
            //??Sleep(1);
            reg_value |= BIT4;// CDR_EN_CDR //reg_value = {reg_value[7:1], 1'h1};          // CDR_EN_CDR
            SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG0, reg_value);//Addr = 0x9B06; *Addr = reg_value;// ADDR_DP_ANA_CDR_CFG0
//            Sleep(1);
            reg_value &= ~BIT4;// CDR_EN_CDR //reg_value = {reg_value[7:1], 1'h1};          // CDR_EN_CDR
            SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG0, reg_value);//Addr = 0x9B06; *Addr = reg_value;// ADDR_DP_ANA_CDR_CFG0  
        //////////////
    
    	  // Lane3 Enable
            SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x08);//Addr = 0x9AD2; *Addr = 0x08;		// ADDR_DPRM_LANE_HI_CFG
            reg_value = GetTMDSPHYDATA(phyindex, _DP_ANA_CDR_CFG0);// ADDR_DP_ANA_CDR_CFG0
            reg_value |= 0x01;// CDR_EN_CDR //reg_value = {reg_value[7:1], 1'h1};		// CDR_EN_CDR
            SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG0, reg_value);//Addr = 0x9B06; *Addr = reg_value;// ADDR_DP_ANA_CDR_CFG0
        //reset VCO////
            //??Sleep(1);
            reg_value |= BIT4;// CDR_EN_CDR //reg_value = {reg_value[7:1], 1'h1};          // CDR_EN_CDR
            SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG0, reg_value);//Addr = 0x9B06; *Addr = reg_value;// ADDR_DP_ANA_CDR_CFG0
//            Sleep(1);
            reg_value &= ~BIT4;// CDR_EN_CDR //reg_value = {reg_value[7:1], 1'h1};          // CDR_EN_CDR
            SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG0, reg_value);//Addr = 0x9B06; *Addr = reg_value;// ADDR_DP_ANA_CDR_CFG0  
        //////////////
    	}
        
    	// VCO_SPD (Settings, 1st Step, Search)
    	//search_vco_speed
    	if ((ucTMDSInputMode == HDMI_NRM) || (ucTMDSInputMode == HDMI_HSP)) { // HDMI_NRM / HDMI_HSP
            SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x0E);//Addr = 0x9AD2; *Addr = 0x0E;		// ADDR_DPRM_LANE_HI_CFG
        }
        else {
            SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x02);//Addr = 0x9AD2; *Addr = 0x02;		// ADDR_DPRM_LANE_HI_CFG
        }
        
        SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_CFG, 0xB0);//Addr = 0x9B20; *Addr = 0xB0;		// ADDR_DP_RXANAIF_VBS_CFG, dp_rxanaif_vbs_done_md
        SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_PERIOD_L, 0xC0);//Addr = 0x9B24; *Addr = 0xC0;		// ADDR_DP_RXANAIF_VBS_PERIOD_L, 2us
        SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_PERIOD_H, 0x00);//Addr = 0x9B25; *Addr = 0x00;		// ADDR_DP_RXANAIF_VBS_PERIOD_H
        SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_BASEL, 0x80);//Addr = 0x9B28; *Addr = 0x80;		// ADDR_DP_RXANAIF_VBS_BASEL
        SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_CFG1, 0x40);//Addr = 0x9B2E; *Addr = 0x40;		// ADDR_DP_RXANAIF_VBS_CFG1, dp_rxanaif_vbs_fcnt1_en
    
        for (vco_spd=0x1; vco_spd<0x10; vco_spd++) {
            if ((vco_spd == 0x1) || (vco_spd == 0x2)) {
                cdr_enc = 0x0E;//3'b111;
            }
            if ((vco_spd == 0x3) || (vco_spd == 0x4)) {
                cdr_enc = 0x06;//3'b011;
            }
            if ((vco_spd == 0x5) || (vco_spd == 0x6)) {
                cdr_enc = 0x02;//3'b001;
            }
            if (vco_spd > 0x6) {
                cdr_enc = 0x00;//3'b000;
            }
    
    	    // Lane1 ENC & VCO_SPD & Band
            SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x02);//Addr = 0x9AD2; *Addr = 0x02;		// ADDR_DPRM_LANE_HI_CFG
            SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG7, vco_spd);//Addr = 0x9B0E; *Addr = vco_spd;
            reg_value = GetTMDSPHYDATA(phyindex, _DP_ANA_CDR_CFG0);// ADDR_DP_ANA_CDR_CFG0
            reg_value &= 0xF1;//reg_value = {reg_value[7:4], cdr_enc, reg_value[0]};	// CDR_ENC[2:0]
            reg_value |= cdr_enc;
            SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG0, reg_value);//Addr = 0x9B06; *Addr = reg_value;// ADDR_DP_ANA_CDR_CFG0
    
        	if ((ucTMDSInputMode == HDMI_NRM) || (ucTMDSInputMode == HDMI_HSP)) { // HDMI_NRM / HDMI_HSP
                // Lane2 ENC & VCO_SPD
                SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x04);//Addr = 0x9AD2; *Addr = 0x04;		// ADDR_DPRM_LANE_HI_CFG
                SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG7, vco_spd);//Addr = 0x9B0E; *Addr = vco_spd;
                reg_value = GetTMDSPHYDATA(phyindex, _DP_ANA_CDR_CFG0);// ADDR_DP_ANA_CDR_CFG0
                reg_value &= 0xF1;//reg_value = {reg_value[7:4], cdr_enc, reg_value[0]};	// CDR_ENC[2:0]
                reg_value |= cdr_enc;
                SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG0, reg_value);//Addr = 0x9B06; *Addr = reg_value;// ADDR_DP_ANA_CDR_CFG0
    
                // Lane3 ENC & VCO_SPD
                SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x08);//Addr = 0x9AD2; *Addr = 0x08;		// ADDR_DPRM_LANE_HI_CFG
                SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG7, vco_spd);//Addr = 0x9B0E; *Addr = vco_spd;
                reg_value = GetTMDSPHYDATA(phyindex, _DP_ANA_CDR_CFG0);// ADDR_DP_ANA_CDR_CFG0
                reg_value &= 0xF1;//reg_value = {reg_value[7:4], cdr_enc, reg_value[0]};	// CDR_ENC[2:0]
                reg_value |= cdr_enc;
                SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG0, reg_value);//Addr = 0x9B06; *Addr = reg_value;// ADDR_DP_ANA_CDR_CFG0
    	    }
    
    	    for (i=0; i<50; i++) {//Sleep(1);	// Delay for VCO_SPD Update 50us
                ResetWDTimer();
            }
            SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x02);//Addr = 0x9AD2; *Addr = 0x02;		// ADDR_DPRM_LANE_HI_CFG
            SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_CFG, 0xB1);//Addr = 0x9B20; *Addr = 0xB1;		// ADDR_DP_RXANAIF_VBS_CFG, dp_rxanaif_vbs_trig_pls
            reg_value = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_CFG);// Polling
            i = 255;
            while (((reg_value & BIT0) != 0) && (i != 0)) {
                //Sleep(1);
                reg_value = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_CFG);// ADDR_DP_ANA_CDR_CFG0
                i--;
            }
    
            reg_value = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_STS);// ADDR_DP_RXANAIF_VBS_STS
            if(reg_value & BIT0 != 0x00) {
                break;
            }
        }
    //printf("test 2\r\n");
    //printf("Reg0x1B29=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT_L));
    //printf("Reg0x1B2A=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT_H));
    //printf("Reg0x1B34=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT1_L));
    //printf("Reg0x1B35=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT1_H));
    //printf("Reg0x1B0E=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DP_ANA_CDR_CFG7));
    //printf("Reg0x1B28=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_BASEL));
    
    	// VCO_SPD (Settings, 2nd Step, Set Value)
    	SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x02);//Addr = 0x9AD2; *Addr = 0x02;		// ADDR_DPRM_LANE_HI_CFG
        reg_value = GetTMDSPHYDATA(phyindex, _DP_ANA_CDR_CFG7);// ADDR_DP_ANA_CDR_CFG0
    	vco_spd = reg_value;

    	if (vco_spd != 0x1) {
            reg_value = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_STS);// ADDR_DP_RXANAIF_VBS_STS
            if ((reg_value & BIT6) == 0x00) {
                vco_spd = vco_spd - 0x1;
            }
        }
        n = 3;
        do {
            if ((vcolockflag == BA_VALUE_TOO_LARGE) && (vco_spd < 15)){
                vco_spd += 1;
            }
            if ((vcolockflag == BA_VALUE_TOO_SMALL) && (vco_spd > 1)){
                vco_spd -= 1;
            }
            if ((vco_spd == 0x1) || (vco_spd == 0x2)) {
                cdr_enc = 0x0E;//3'b111;
            }
            if ((vco_spd == 0x3) || (vco_spd == 0x4)) {
                cdr_enc = 0x06;//3'b011;
            }
            if ((vco_spd == 0x5) || (vco_spd == 0x6)) {
                cdr_enc = 0x02;//3'b001;
            }
            if (vco_spd > 0x6) {
                cdr_enc = 0x00;//3'b000;
            }
        // Lane1 ENC & VCO_SPD & Band
            SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x02);//Addr = 0x9AD2; *Addr = 0x02;		// ADDR_DPRM_LANE_HI_CFG
            SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG7, vco_spd);//Addr = 0x9B0E; *Addr = vco_spd;
            reg_value = GetTMDSPHYDATA(phyindex, _DP_ANA_CDR_CFG0);// ADDR_DP_ANA_CDR_CFG0
            reg_value &= 0xF1;//reg_value = {reg_value[7:4], cdr_enc, reg_value[0]};	// CDR_ENC[2:0]
            reg_value |= cdr_enc;
            SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG0, reg_value);//Addr = 0x9B06; *Addr = reg_value;// ADDR_DP_ANA_CDR_CFG0

            if ((ucTMDSInputMode == HDMI_NRM) || (ucTMDSInputMode == HDMI_HSP)) { // HDMI_NRM / HDMI_HSP
              // Lane2 ENC & VCO_SPD
                SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x04);//Addr = 0x9AD2; *Addr = 0x04;		// ADDR_DPRM_LANE_HI_CFG
                SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG7, vco_spd);//Addr = 0x9B0E; *Addr = vco_spd;
                reg_value = GetTMDSPHYDATA(phyindex, _DP_ANA_CDR_CFG0);// ADDR_DP_ANA_CDR_CFG0
                reg_value &= 0xF1;//reg_value = {reg_value[7:4], cdr_enc, reg_value[0]};	// CDR_ENC[2:0]
                reg_value |= cdr_enc;
                SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG0, reg_value);//Addr = 0x9B06; *Addr = reg_value;// ADDR_DP_ANA_CDR_CFG0
    
              // Lane3 ENC & VCO_SPD
                SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x08);//Addr = 0x9AD2; *Addr = 0x08;		// ADDR_DPRM_LANE_HI_CFG
                SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG7, vco_spd);//Addr = 0x9B0E; *Addr = vco_spd;
                reg_value = GetTMDSPHYDATA(phyindex, _DP_ANA_CDR_CFG0);// ADDR_DP_ANA_CDR_CFG0
                reg_value &= 0xF1;//reg_value = {reg_value[7:4], cdr_enc, reg_value[0]};	// CDR_ENC[2:0]
                reg_value |= cdr_enc;
                SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG0, reg_value);//Addr = 0x9B06; *Addr = reg_value;// ADDR_DP_ANA_CDR_CFG0
            }

            // CDR_BA (Settings, 1st Step, Coarse Tune)
            if ((ucTMDSInputMode == HDMI_NRM) || (ucTMDSInputMode == HDMI_HSP)) { // HDMI_NRM / HDMI_HSP
                SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x0E);//Addr = 0x9AD2; *Addr = 0x0E;		// ADDR_DPRM_LANE_HI_CFG
            }
            else {
                SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x02);//Addr = 0x9AD2; *Addr = 0x02;		// ADDR_DPRM_LANE_HI_CFG
            }
        
            SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_BASEL, 0x00);//Addr = 0x9B28; *Addr = 0x00;		// ADDR_DP_RXANAIF_VBS_BASEL
            SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_CFG, 0x00);//Addr = 0x9B20; *Addr = 0x00;		// ADDR_DP_RXANAIF_VBS_CFG, dp_rxanaif_vbs_done_md
            SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_STEP_CFG, 0x08);//Addr = 0x9B21; *Addr = 0x08;		// ADDR_DP_RXANAIF_VBS_STEP_CFG
            if (lbr_flag) {
                SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_PERIOD_L, 0xC0);//Addr = 0x9B24; *Addr = 0xC0;		// ADDR_DP_RXANAIF_VBS_PERIOD_L, 10us
                SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_PERIOD_H, 0x03);//Addr = 0x9B25; *Addr = 0x03;		// ADDR_DP_RXANAIF_VBS_PERIOD_H
            }
            else {
                SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_PERIOD_L, 0x60);//Addr = 0x9B24; *Addr = 0x60;		// ADDR_DP_RXANAIF_VBS_PERIOD_L, 1us
                SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_PERIOD_H, 0x00);//Addr = 0x9B25; *Addr = 0x00;		// ADDR_DP_RXANAIF_VBS_PERIOD_H
            }
            SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_CFG1, 0x40);//Addr = 0x9B2E; *Addr = 0x40;		// ADDR_DP_RXANAIF_VBS_CFG1, dp_rxanaif_vbs_fcnt1_en
            reg_value = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT_CFG);// ADDR_DP_ANA_CDR_CFG0
            reg_value = ((reg_value & 0xF0) | 0x04);//reg_value = {reg_value[7:4], 4'h4};
            SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_FCNT_CFG, reg_value);//Addr = 0x9B33; *Addr = reg_value;
        
            SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_CFG, 0x01);//Addr = 0x9B20; *Addr = 0x01;		// ADDR_DP_RXANAIF_VBS_CFG, dp_rxanaif_vbs_trig_pls
        
            // Check Lane1
            SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x02);//Addr = 0x9AD2; *Addr = 0x02;		// ADDR_DPRM_LANE_HI_CFG
            reg_value = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_CFG);
            i = 255;//170us
            while (((reg_value & BIT0) != 0) && (i != 0)) {// Polling
                //Sleep(1);
                reg_value = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_CFG);
                i--;
            }
        
            reg_value = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_BASEL);// ADDR_DP_RXANAIF_VBS_BASEL
            if (reg_value < 9) {
                reg_value = 0;
            }
            else {
                reg_value = reg_value - 0x09;
            }
            SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_BASEL, reg_value);//Addr = 0x9B28; *Addr = reg_value;		// ADDR_DP_RXANAIF_VBS_BASEL
        //printf("test 3\r\n");
        //printf("Reg0x1B29=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT_L));
        //printf("Reg0x1B2A=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT_H));
        //printf("Reg0x1B34=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT1_L));
        //printf("Reg0x1B35=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT1_H));
        //printf("Reg0x1B0E=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DP_ANA_CDR_CFG7));
        //printf("Reg0x1B28=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_BASEL));
        
            if ((ucTMDSInputMode == HDMI_NRM) || (ucTMDSInputMode == HDMI_HSP)) { // HDMI_NRM / HDMI_HSP
        
              // Check Lane2
                SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x04);//Addr = 0x9AD2; *Addr = 0x04;		// ADDR_DPRM_LANE_HI_CFG
                reg_value = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_CFG);
                i = 255;//170us
                while (((reg_value & BIT0) != 0) && (i != 0)) {// Polling
                    //Sleep(1);
                    reg_value = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_CFG);
                    i--;
                }
                reg_value = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_BASEL);// ADDR_DP_RXANAIF_VBS_BASEL
                if (reg_value < 9) {
                    reg_value = 0;
                }
                else {
                    reg_value = reg_value - 0x09;
                }
                SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_BASEL, reg_value);//Addr = 0x9B28; *Addr = reg_value;		// ADDR_DP_RXANAIF_VBS_BASEL
        //printf("test 4\r\n");
        //printf("Reg0x1B29=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT_L));
        //printf("Reg0x1B2A=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT_H));
        //printf("Reg0x1B34=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT1_L));
        //printf("Reg0x1B35=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT1_H));
        //printf("Reg0x1B0E=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DP_ANA_CDR_CFG7));
        //printf("Reg0x1B28=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_BASEL));
        
              // Check Lane3
                SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x08);//Addr = 0x9AD2; *Addr = 0x08;		// ADDR_DPRM_LANE_HI_CFG
                reg_value = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_CFG);
                i = 255;//170us
                while (((reg_value & BIT0) != 0) && (i != 0)) {// Polling
                    //Sleep(1);
                    reg_value = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_CFG);
                    i--;
                }
                reg_value = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_BASEL);// ADDR_DP_RXANAIF_VBS_BASEL
                if (reg_value < 9) {
                    reg_value = 0;
                }
                else {
                    reg_value = reg_value - 0x09;
                }
                SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_BASEL, reg_value);//Addr = 0x9B28; *Addr = reg_value;		// ADDR_DP_RXANAIF_VBS_BASEL
        //printf("test 5\r\n");
        //printf("Reg0x1B29=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT_L));
        //printf("Reg0x1B2A=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT_H));
        //printf("Reg0x1B34=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT1_L));
        //printf("Reg0x1B35=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT1_H));
        //printf("Reg0x1B0E=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DP_ANA_CDR_CFG7));
        //printf("Reg0x1B28=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_BASEL));
            }
        
            // CDR_BA (Settings, 2nd Step, Fine Tune)
            if ((ucTMDSInputMode == HDMI_NRM) || (ucTMDSInputMode == HDMI_HSP)) { // HDMI_NRM / HDMI_HSP
                SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x0E);//Addr = 0x9AD2; *Addr = 0x0E;    // ADDR_DPRM_LANE_HI_CFG
            }
            else {
                SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x02);//Addr = 0x9AD2; *Addr = 0x02;    // ADDR_DPRM_LANE_HI_CFG
            }
        
            SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_CFG, 0x00);//Addr = 0x9B20; *Addr = 0x00;		// ADDR_DP_RXANAIF_VBS_CFG, dp_rxanaif_vbs_done_md
            SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_STEP_CFG, 0x01);//Addr = 0x9B21; *Addr = 0x01;		// ADDR_DP_RXANAIF_VBS_STEP_CFG
            if(lbr_flag) {
                SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_PERIOD_L, 0xC0);//Addr = 0x9B24; *Addr = 0xC0;		// ADDR_DP_RXANAIF_VBS_PERIOD_L, 50us
                SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_PERIOD_H, 0x12);//Addr = 0x9B25; *Addr = 0x12;		// ADDR_DP_RXANAIF_VBS_PERIOD_H
            }
            else {
                SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_PERIOD_L, 0xE0);//Addr = 0x9B24; *Addr = 0xE0;		// ADDR_DP_RXANAIF_VBS_PERIOD_L, 5us
                SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_PERIOD_H, 0x01);//Addr = 0x9B25; *Addr = 0x01;		// ADDR_DP_RXANAIF_VBS_PERIOD_H
            }
            SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_CFG1, 0x40);//Addr = 0x9B2E; *Addr = 0x40;		// ADDR_DP_RXANAIF_VBS_CFG1, dp_rxanaif_vbs_fcnt1_en
        
            reg_value = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT_CFG);
            reg_value = ((reg_value & 0xF0) | 0x04);//reg_value = {reg_value[7:4], 4'h4};
            SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_FCNT_CFG, reg_value);//Addr = 0x9B33; *Addr = reg_value;
        
            SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_CFG, 0x01);//Addr = 0x9B20; *Addr = 0x01;		// ADDR_DP_RXANAIF_VBS_CFG, dp_rxanaif_vbs_trig_pls
        
            // Check Lane1
            SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x02);//Addr = 0x9AD2; *Addr = 0x02;		// ADDR_DPRM_LANE_HI_CFG
            reg_value = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_CFG);
            i = 255;//450us
            while (((reg_value & BIT0) != 0x00) && (i != 0)) {
                //Sleep(1);
                reg_value = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_CFG);
                i--;
            }
        //printf("test 6\r\n");
        //printf("Reg0x1B29=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT_L));
        //printf("Reg0x1B2A=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT_H));
        //printf("Reg0x1B34=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT1_L));
        //printf("Reg0x1B35=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT1_H));
        //printf("Reg0x1B0E=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DP_ANA_CDR_CFG7));
        //printf("Reg0x1B28=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_BASEL));
        
            if ((ucTMDSInputMode == HDMI_NRM) || (ucTMDSInputMode == HDMI_HSP)) { // HDMI_NRM / HDMI_HSP
        
              // Check Lane2
                SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x04);//Addr = 0x9AD2; *Addr = 0x04;		// ADDR_DPRM_LANE_HI_CFG
                reg_value = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_CFG);
                i = 255;//450us
                while (((reg_value & BIT0) != 0x00) && (i != 0)) {
                    //Sleep(1);
                    reg_value = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_CFG);
                    i--;
                }
        //printf("test 7\r\n");
        //printf("Reg0x1B29=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT_L));
        //printf("Reg0x1B2A=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT_H));
        //printf("Reg0x1B34=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT1_L));
        //printf("Reg0x1B35=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT1_H));
        //printf("Reg0x1B0E=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DP_ANA_CDR_CFG7));
        //printf("Reg0x1B28=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_BASEL));
        
              // Check Lane3
                SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x08);//Addr = 0x9AD2; *Addr = 0x08;		// ADDR_DPRM_LANE_HI_CFG
                reg_value = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_CFG);
                i = 255;//450us
                while (((reg_value & BIT0) != 0x00) && (i != 0)) {
                    //Sleep(1);
                    reg_value = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_CFG);
                    i--;
                }
        //printf("test 8\r\n");
        //printf("Reg0x1B29=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT_L));
        //printf("Reg0x1B2A=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT_H));
        //printf("Reg0x1B34=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT1_L));
        //printf("Reg0x1B35=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT1_H));
        //printf("Reg0x1B0E=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DP_ANA_CDR_CFG7));
        //printf("Reg0x1B28=%x\r\n", (USHRT)GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_BASEL));
            }
        
            // CDR_BA (Settings, 3rd Step, Set Value)
            // Lane1 Band
            SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x02);//Addr = 0x9AD2; *Addr = 0x02;		// ADDR_DPRM_LANE_HI_CFG
            reg_value = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_BASEL);
            cdr_band = reg_value;
            if (cdr_band != 0x00) {
                reg_value = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_STS);// ADDR_DP_RXANAIF_VBS_STS
                if ((reg_value & BIT6) == 0x00) {
                    cdr_band = cdr_band - 0x1;
                    SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_BASEL, cdr_band);//Addr = 0x9B28; *Addr = cdr_band;
                }
            }
        
            if ((ucTMDSInputMode == HDMI_NRM) || (ucTMDSInputMode == HDMI_HSP)) { // HDMI_NRM / HDMI_HSP
              // Lane2 Band
                SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x04);//Addr = 0x9AD2; *Addr = 0x04;		// ADDR_DPRM_LANE_HI_CFG
                reg_value = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_BASEL);// ADDR_DP_ANA_CDR_CFG7
                cdr_band = reg_value;
                if (cdr_band != 0x00) {
                    reg_value = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_STS);// ADDR_DP_RXANAIF_VBS_STS
                    if ((reg_value & BIT6) == 0x00) {
                        cdr_band = cdr_band - 0x1;
                        SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_BASEL, cdr_band);//Addr = 0x9B28; *Addr = cdr_band;
                    }
                }
        
              // Lane3 Band
                SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x08);//Addr = 0x9AD2; *Addr = 0x08;		// ADDR_DPRM_LANE_HI_CFG
                reg_value = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_BASEL);// ADDR_DP_ANA_CDR_CFG7
                cdr_band = reg_value;
                if (cdr_band != 0x00) {
                    reg_value = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_STS);// ADDR_DP_RXANAIF_VBS_STS
                    if ((reg_value & BIT6) == 0x00) {
                        cdr_band = cdr_band - 0x1;
                        SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_BASEL, cdr_band);//Addr = 0x9B28; *Addr = cdr_band;
                    }
                }
            }
        
            error = 0;
            for (m=0; m<3; m++) {
                if (m == 0) {
                    SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x02);//Addr = 0x9AD2; *Addr = 0x02;
                }
                else if (m == 1) {
                    SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x04);//Addr = 0x9AD2; *Addr = 0x04;
                }
                else {
                    SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x08);//Addr = 0x9AD2; *Addr = 0x08;
                }
                ext_counter = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT1_H);
                ext_counter <<= 8;
                ext_counter |= GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT1_L);
                int_counter = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT_H);
                int_counter <<= 8;
                int_counter |= GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_FCNT_L);
    //            if (abs(int_counter-ext_counter) > (ULONG)ext_counter * 3 / 1000 + 1) {
                if (abs(int_counter-ext_counter) > (ULONG)ext_counter * 2 / 100 + 1) {
                    error = 1;
                }
                vcolockflag = 0;
                if (error == 0) {
                    reg_value = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_BASEL);
                    if (reg_value > 0xF0) {
                        vcolockflag = BA_VALUE_TOO_LARGE;
                        error = 1;
                    }
                    if (reg_value < 0x10) {
                        vcolockflag = BA_VALUE_TOO_SMALL;
                        error = 1;
                    }
                }
                if (ucTMDSInputMode > HDMI_HSP) { // MHL
                    break;
                }
                if (error == 1) {
                    break;
                }
            }
            n--;
        } while ((n != 0) && (vcolockflag != 0));
        if (error == 0) {
            break;
        }
    }
//printf("k = %x\r\n", (USHRT)k);

	// Band Selection Done (Settings)
	if ((ucTMDSInputMode == HDMI_NRM) || (ucTMDSInputMode == HDMI_HSP)) { // HDMI_NRM / HDMI_HSP
        SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x0E);//Addr = 0x9AD2; *Addr = 0x0E;		// ADDR_DPRM_LANE_HI_CFG
	}
	else {
        SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x02);//Addr = 0x9AD2; *Addr = 0x02;		// ADDR_DPRM_LANE_HI_CFG
	}
	// ABJ
	SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_CFG, 0x40);//Addr = 0x9B20; *Addr = 0x40;		// ADDR_DP_RXANAIF_VBS_CFG, dp_rxanaif_vbs_done_md
	SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_STEP_CFG, 0x01);//Addr = 0x9B21; *Addr = 0x01;		// ADDR_DP_RXANAIF_VBS_STEP_CFG
	SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_PERIOD_L, 0x60);//Addr = 0x9B24; *Addr = 0x60;		// ADDR_DP_RXANAIF_VBS_PERIOD_L, 1us
	SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_PERIOD_H, 0x00);//Addr = 0x9B25; *Addr = 0x00;		// ADDR_DP_RXANAIF_VBS_PERIOD_H
	SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_CFG1, 0x02);//Addr = 0x9B2E; *Addr = 0x02;		// ADDR_DP_RXANAIF_VBS_CFG1, dp_rxanaif_vbs_step_mode
	SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG1, 0x05);//Addr = 0x9B07; *Addr = 0x04;//0x07;		// ADDR_DP_ANA_CDR_CFG1
    Sleep(1);
	SC_SetByteDPppPHY(phyindex, _DP_ANA_S2P_CFG, 0x31);//Addr = 0x9B0C; *Addr = 0x33;		// ADDR_DP_ANA_S2P_CFG
	SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG4, 0x21);//Addr = 0x9B0A; *Addr = 0x21;		// 
	SC_SetByteDPppPHY(phyindex, _DP_ANA_CDR_CFG5, 0x14);//Addr = 0x9B0B; *Addr = 0x14;		// 
	SC_SetByteDPppPHY(phyindex, _DPRXANAIF_VBS_CFG, 0x41);//Addr = 0x9B20; *Addr = 0x41;		// ADDR_DP_RXANAIF_VBS_CFG, dp_rxanaif_vbs_done_md

	// AEQ
	SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG, 0x01);//Addr = 0x9B40; *Addr = 0x01;		// ADDR_DP_RXANAIF_AEQ_CFG
//	Sleep(20);
////////////////////////////////////////////////////////
    if (ucTMDSInputMode == HDMI_NRM) { // HDMI_NRM
        SC_SetByteDPppPHY(phyindex, _TMDS_DPHY_MHL2p0_MISC, 0x20);//Addr = 0x9B9A; *Addr = 0x20;
        SC_SetByteDPppPHY(phyindex, _TMDS_DPHY_CLOCK_ENABLE, 0xF8);//Addr = 0x9B90; *Addr = 0xF8;
        SC_SetByteDPppPHY(phyindex, _TMDS_DPHY_CLOCK_INVERT, 0xE0);//Addr = 0x9B91; *Addr = 0x00;
    }
    else if (ucTMDSInputMode == HDMI_HSP) { // HDMI_HSP
        SC_SetByteDPppPHY(phyindex, _TMDS_DPHY_MHL2p0_MISC, 0x20);//Addr = 0x9B9A; *Addr = 0x20;
#ifdef FORCE_SCRAMBLE_ON//force scramble
        SC_SetByteHDMIRX(linkidx, _TMDS_SCRAMBLE_CTRL, 0x03);// Addr = 0x88E1; *Addr = 0x03;
#endif
#ifdef TMDS4K2K_TEST
        SC_SetByteDPppPHY(phyindex, _TMDS_DPHY_CLOCK_ENABLE, 0xF8);//Addr = 0x9B90; *Addr = 0xF8;
        SC_SetByteDPppPHY(phyindex, _TMDS_DPHY_CLOCK_INVERT, 0x00);//Addr = 0x9B91; *Addr = 0x00;
#else
        SC_SetByteDPppPHY(phyindex, _TMDS_DPHY_CLOCK_ENABLE, 0xFC);//Addr = 0x9B90; *Addr = 0xFC;
#endif
    }
    else {//MHL
        SC_SetByteDPppPHY(phyindex, _TMDS_DPHY_MHL2p0_MISC, 0x20);//Addr = 0x9B9A; *Addr = 0x20;
        SC_SetByteDPppPHY(phyindex, _TMDS_DPHY_CLOCK_ENABLE, 0xF8);//Addr = 0x9B90; *Addr = 0xF8;
        SC_SetByteDPppPHY(phyindex, _TMDS_DPHY_CLOCK_INVERT, 0x00);//Addr = 0x9B91; *Addr = 0x00;
    }

#ifdef ENABLE_HF_TMDS_AUTOEQ
	if ( 0 )
	{
	}
    else if (GetTMDSPHYDATA(phyindex, _DPRXANAIF_AEQ_CFG2) != 0x33) {
		USHRT usTmpD0, usTmpD1, usTmpD2;
		// Sleep(100);
    	//printf("linkidx=%x\r\n", (USHRT)linkidx);
        Sleep(2);;//Sleep(20);
		SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x02);
		usTmpD0 = (USHRT) GetTMDSPHYDATA(phyindex, _DPRXANAIF_AEQ_CFG5);
		usTmpD0 = usTmpD0<<8;
		usTmpD0 |= GetTMDSPHYDATA(phyindex, _DPRXANAIF_AEQ_CFG4);
		usTmpD0 = (usTmpD0<<1) | BIT0;

		SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x04);
		usTmpD1 = (USHRT) GetTMDSPHYDATA(phyindex, _DPRXANAIF_AEQ_CFG5);
		usTmpD1 = usTmpD1<<8;
		usTmpD1 |= GetTMDSPHYDATA(phyindex, _DPRXANAIF_AEQ_CFG4);
		usTmpD1 = (usTmpD1<<1) | BIT0;
		
		SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x08);
		usTmpD2 = (USHRT) GetTMDSPHYDATA(phyindex, _DPRXANAIF_AEQ_CFG5);
		usTmpD2 = usTmpD2<<8;
		usTmpD2 |= GetTMDSPHYDATA(phyindex, _DPRXANAIF_AEQ_CFG4);
		usTmpD2 = (usTmpD2<<1) | BIT0;

//        SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x0E);		
//        SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG2, 0x33);
		
        SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x02);
        SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG4, (UCHAR) (usTmpD0&0x00FF) );
        SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG5, (UCHAR) (usTmpD0>>8) );
		
        SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x04);
        SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG4, (UCHAR) (usTmpD1&0x00FF) );
        SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG5, (UCHAR) (usTmpD1>>8) );


        SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x08);
        SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG4, (UCHAR) (usTmpD2&0x00FF) );
        SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG5, (UCHAR) (usTmpD2>>8) );

        SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x0E);		
        SC_SetByteDPppPHY(phyindex, _DPRXANAIF_AEQ_CFG2, 0x33);
	}
#endif
    
    bTMDSClockTraining = FALSE;
    usTMDSTrainingTimer = GetTimerTick();
    
    TMDS_EQSet_FlowReset();
    
#if ENABLE_TMDS_EQ_SEARCH_FLOW == ON    
    //EQ setting flow, no need to do when use manual mode
    if (GetTMDSPHYDATA(phyindex, _DPRXANAIF_AEQ_CFG2) != 0x33) {    
        TMDS_EQSet_EQSetting(phyindex, stEQSet.ucCurrentSearchLevel);
        TMDS_EQSet_ErrCntInit(phyindex);
    }
    
#else    
    //EQ setting flow, no need to do when use manual mode
    if (GetTMDSPHYDATA(phyindex, _DPRXANAIF_AEQ_CFG2) != 0x33) {    
       TMDS_EQSet_EQSetting(phyindex, _TMDSEQ_S0);
    }
#endif
}

void ClearTMDSTraining(void)
{
    bTMDSClockTraining = TRUE;
    usTMDSTrainingTimer = GetTimerTick();
}
#endif
bit IsTMDSLBR(UCHAR phyindex)
{
    if (GetTMDSPHYDATA(phyindex, _DP_ANA_CDR_CFG6) & BIT1) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

//******************************************************************************
// Prototype:
//  BOOL CheckTMDSVCOValue(void)
// Parameters:
// Return:
//  BOOL (FALSE : Fail value)
// Purpose:
//  Check TMDS VCO Value is in correct range or not 
// Notes:
//  designer suggest VCO Range ( 0x10 < VCO < 0xF0)
//******************************************************************************
BOOL CheckTMDSVCOValue(void)
{
#if ENABLE_EMBEDED_TMDS_CLOCK_TRAINING == ON
    return TRUE;
#else
    UCHAR i, value;
	UCHAR phyindex = 0;

#ifdef ENABLE_FPGA_MODE
    return TRUE;
#endif

#if IS_NT68870_SERIES
    phyindex = GetCurrInputInterface();
	if ((phyindex == DIGITAL_INPUT0) || (phyindex == DIGITAL_INPUT1)) {
		phyindex = _DPPP_PHY0;
	}
	else {
		phyindex = _DPPP_PHY1;
	}
#endif

    i = 0;
    SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x02);//check lane1
    value = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_BASEL);
    //printf("check_lane1=%x\r\n",(int)value);
    if (value > 0xF0 || value < 0x10) {
        i++;
    }
    
    SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x04);//check lane2
    value = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_BASEL);
    //printf("check_lane2=%x\r\n",(int)value);

    if (value > 0xF0 || value < 0x10) {
        i++;
    }
    
    SC_SetByteDPppPHY(phyindex, _DPRM_LANE_HI_CFG, 0x08);//check lane3
    value = GetTMDSPHYDATA(phyindex, _DPRXANAIF_VBS_BASEL);
    //printf("check_lane3=%x\r\n",(int)value);
    if (value > 0xF0 || value < 0x10) {
        i++;
    }

    if (i > 0) {
        return FALSE;
    }
    else {
        return TRUE;
    }
#endif
}


BOOL CheckTMDSErrorCounter(void)
{
#if ENABLE_EMBEDED_TMDS_CLOCK_TRAINING == ON
    return TRUE;
#else
#if IS_NT68870_SERIES
    UCHAR i=0;
    USHRT value;

    UCHAR phyindex = 0;
    BOOL bIsDualDviIn = FALSE;

    phyindex = GetCurrInputInterface();
    if ((phyindex == DIGITAL_INPUT0) || (phyindex == DIGITAL_INPUT1)) {
#if ENABLE_DVI_DUAL_LINK == ON
        if (phyindex == DIGITAL_INPUT1 && TMDS_IsDualLink()) {
            bIsDualDviIn = TRUE;
        }
#endif
        phyindex = _DPPP_PHY0;
    }
    else {
        phyindex = _DPPP_PHY1;
    }

    i = 0;
    SC_SetByteDPppPHY(phyindex, _TMDS_DPHY_ERROR_DET, 0xC0);
    SC_SetByteDPppPHY(phyindex, _TMDS_DPHY_ERROR_DET, 0x80);
    Sleep(20);

    value = (USHRT)GetTMDSPHYDATA(phyindex, _TMDS_DPHY_ERRORCNT_CH0_HI);
    value &= 0x7F;
    value <<= 8; 
    value += (USHRT)GetTMDSPHYDATA(phyindex, _TMDS_DPHY_ERRORCNT_CH0_LO);
    if (value>0x10) {
        i++;
    }		

    value = (USHRT)GetTMDSPHYDATA(phyindex, _TMDS_DPHY_ERRORCNT_CH1_HI);
    value &= 0x7F;
    value <<= 8; 
    value += (USHRT)GetTMDSPHYDATA(phyindex, _TMDS_DPHY_ERRORCNT_CH1_LO);
    if (value>0x10) {
        i++;
    }		

    value = (USHRT)GetTMDSPHYDATA(phyindex, _TMDS_DPHY_ERRORCNT_CH2_HI);
    value &= 0x7F;
    value <<= 8; 
    value += (USHRT)GetTMDSPHYDATA(phyindex, _TMDS_DPHY_ERRORCNT_CH2_LO);
    if (value>0x10) {
        i++;
    }	

#if ENABLE_DVI_DUAL_LINK == ON
    if (bIsDualDviIn) {
        SC_SetByteDPppPHY(_DPPP_PHY1, _TMDS_DPHY_ERROR_DET, 0xC0);
        SC_SetByteDPppPHY(_DPPP_PHY1, _TMDS_DPHY_ERROR_DET, 0x80);
        Sleep(20);

        value = (USHRT)GetTMDSPHYDATA(_DPPP_PHY1, _TMDS_DPHY_ERRORCNT_CH0_HI);
        value &= 0x7F;
        value <<= 8; 
        value += (USHRT)GetTMDSPHYDATA(_DPPP_PHY1, _TMDS_DPHY_ERRORCNT_CH0_LO);
        if (value>0x10) {
            i++;
        }		

        value = (USHRT)GetTMDSPHYDATA(_DPPP_PHY1, _TMDS_DPHY_ERRORCNT_CH1_HI);
        value &= 0x7F;
        value <<= 8; 
        value += (USHRT)GetTMDSPHYDATA(_DPPP_PHY1, _TMDS_DPHY_ERRORCNT_CH1_LO);
        if (value>0x10) {
            i++;
        }		

        value = (USHRT)GetTMDSPHYDATA(_DPPP_PHY1, _TMDS_DPHY_ERRORCNT_CH2_HI);
        value &= 0x7F;
        value <<= 8; 
        value += (USHRT)GetTMDSPHYDATA(_DPPP_PHY1, _TMDS_DPHY_ERRORCNT_CH2_LO);
        if (value>0x10) {
            i++;
        }	
    }	
#endif
    if (i > 0) {
        return FALSE;		
    }
    else {
        return TRUE;
    }	
#else
    return TRUE;
#endif
#endif
}

#if ENABLE_EMBEDED_TMDS_CLOCK_TRAINING == OFF
/**************************************************************************//**
 * EQ setting by table
 * @Param : 
 *        linkidx : TMDS link index
 *        level : EQ level 
 ******************************************************************************/
static void TMDS_EQSet_EQSetting(UCHAR linkidx, UCHAR level)
{
    static code UCHAR ucTMDS_EQTable[4][5] = {
        //142,  149,  14A,  14B,  204
        {0x33, 0x00, 0x00, 0x00, 0x1F}, // S0 , original S2
        {0x31, 0x03, 0xFF, 0xFF, 0x18}, // S1 , original S0
        {0x31, 0x01, 0xFF, 0xFF, 0x18}, // S2 , original S1
        {0x33, 0x00, 0x01, 0x00, 0x1F}, // S3
    };
//    printf("TMDS_EQSet_EQSetting level = %bx\r\n", level);

    SC_SetByteDPppPHY(linkidx, _DPRM_LANE_HI_CFG, 0x0E);

    SC_SetByteDPppPHY(linkidx, _DPRXANAIF_AEQ_CFG2, ucTMDS_EQTable[level][0]);
    SC_SetByteDPppPHY(linkidx, _DPRXANAIF_AEQ_CFG3, ucTMDS_EQTable[level][1]);
    SC_SetByteDPppPHY(linkidx, _DPRXANAIF_AEQ_CFG4, ucTMDS_EQTable[level][2]);
    SC_SetByteDPppPHY(linkidx, _DPRXANAIF_AEQ_CFG5, ucTMDS_EQTable[level][3]);
    SC_SetByteDPppPHY(linkidx, _DPPHY_IMPEDANCE_L1, ucTMDS_EQTable[level][4]);


//    if (level == _TMDSEQ_S0) {//original method
    if (level == _TMDSEQ_S1 || level == _TMDSEQ_S2) {//original method
        USHRT usTmpD0, usTmpD1, usTmpD2;

        SC_SetByteDPppPHY(linkidx, _DPPHY_IMPEDANCE_L1, 0x18);
        
        if (GetTMDSPHYDATA(linkidx, _DPRXANAIF_AEQ_CFG2) != 0x31) {
            SC_SetByteDPppPHY(linkidx, _DPRXANAIF_AEQ_CFG2, 0x31);        
        }
        Sleep(2);//Sleep(20);
        SC_SetByteDPppPHY(linkidx, _DPRM_LANE_HI_CFG, 0x02);
        usTmpD0 = (USHRT) GetTMDSPHYDATA(linkidx, _DPRXANAIF_AEQ_CFG5);
        usTmpD0 = usTmpD0<<8;
        usTmpD0 |= GetTMDSPHYDATA(linkidx, _DPRXANAIF_AEQ_CFG4);
        usTmpD0 = (usTmpD0<<1) | BIT0;

        SC_SetByteDPppPHY(linkidx, _DPRM_LANE_HI_CFG, 0x04);
        usTmpD1 = (USHRT) GetTMDSPHYDATA(linkidx, _DPRXANAIF_AEQ_CFG5);
        usTmpD1 = usTmpD1<<8;
        usTmpD1 |= GetTMDSPHYDATA(linkidx, _DPRXANAIF_AEQ_CFG4);
        usTmpD1 = (usTmpD1<<1) | BIT0;
        
        SC_SetByteDPppPHY(linkidx, _DPRM_LANE_HI_CFG, 0x08);
        usTmpD2 = (USHRT) GetTMDSPHYDATA(linkidx, _DPRXANAIF_AEQ_CFG5);
        usTmpD2 = usTmpD2<<8;
        usTmpD2 |= GetTMDSPHYDATA(linkidx, _DPRXANAIF_AEQ_CFG4);
        usTmpD2 = (usTmpD2<<1) | BIT0;

        SC_SetByteDPppPHY(linkidx, _DPRM_LANE_HI_CFG, 0x0E);        
        SC_SetByteDPppPHY(linkidx, _DPRXANAIF_AEQ_CFG2, 0x33);
        
        SC_SetByteDPppPHY(linkidx, _DPRM_LANE_HI_CFG, 0x02);
        SC_SetByteDPppPHY(linkidx, _DPRXANAIF_AEQ_CFG4, (UCHAR) (usTmpD0&0x00FF) );
        SC_SetByteDPppPHY(linkidx, _DPRXANAIF_AEQ_CFG5, (UCHAR) (usTmpD0>>8) );
        
        SC_SetByteDPppPHY(linkidx, _DPRM_LANE_HI_CFG, 0x04);
        SC_SetByteDPppPHY(linkidx, _DPRXANAIF_AEQ_CFG4, (UCHAR) (usTmpD1&0x00FF) );
        SC_SetByteDPppPHY(linkidx, _DPRXANAIF_AEQ_CFG5, (UCHAR) (usTmpD1>>8) );


        SC_SetByteDPppPHY(linkidx, _DPRM_LANE_HI_CFG, 0x08);
        SC_SetByteDPppPHY(linkidx, _DPRXANAIF_AEQ_CFG4, (UCHAR) (usTmpD2&0x00FF) );
        SC_SetByteDPppPHY(linkidx, _DPRXANAIF_AEQ_CFG5, (UCHAR) (usTmpD2>>8) );
    }

}

/**************************************************************************//**
 * Reset/Init the search flow
 * @Param : TMDS link index
 ******************************************************************************/
void TMDS_EQSet_FlowReset(void)
{
    stEQSet.ucCurrentSearchLevel = _TMDSEQ_S0;    
    stEQSet.ucBestLevel = _TMDSEQ_S0;
    stEQSet.ulBestErrCnt = 0xFFFFFF;   
    stEQSet.bIsFinish = TRUE;
}

/**************************************************************************//**
 * Check the EQ search flow is finish or not
 * @Param : TMDS link index
 * @Return : TRUE if the searching flow is finished
 ******************************************************************************/
#if !lrd_dis
BOOL TMDS_EQSet_IsFinish(void)
{
    return stEQSet.bIsFinish;
}

/**************************************************************************//**
 * Get the EQ level with lowest error count
 * @Param : TMDS link index
 * @Return : Best level
 ******************************************************************************/
UCHAR TMDS_EQSet_GetBestLevel(void)
{
    return stEQSet.ucBestLevel;
}
#endif
/**************************************************************************//**
 * Error count init, clear the HW error count 
 * @Param : TMDS link index
 ******************************************************************************/
static void TMDS_EQSet_ErrCntInit(UCHAR phyindex)
{
//    SC_SetByteDPppPHY(phyidx, _TMDS_DPHY_ERROR_DET, 0xC0);
//    SC_SetByteDPppPHY(phyidx, _TMDS_DPHY_ERROR_DET, 0x80);
    UCHAR temp;
    temp = GetTMDSPHYDATA(phyindex, _TMDS_DPHY_CH0_ERROR) | BIT5;
    SC_SetByteDPppPHY(phyindex, _TMDS_DPHY_CH0_ERROR, temp);
    temp = GetTMDSPHYDATA(phyindex, _TMDS_DPHY_CH1_ERROR) | BIT5;
    SC_SetByteDPppPHY(phyindex, _TMDS_DPHY_CH1_ERROR, temp);
    temp = GetTMDSPHYDATA(phyindex, _TMDS_DPHY_CH2_ERROR) | BIT5;
    SC_SetByteDPppPHY(phyindex, _TMDS_DPHY_CH2_ERROR, temp);
    
    temp = GetTMDSPHYDATA(phyindex, _TMDS_DPHY_ERROR_DET) | BIT7;
    SC_SetByteDPppPHY(phyindex, _TMDS_DPHY_ERROR_DET, temp);
    temp = GetTMDSPHYDATA(phyindex, _TMDS_DPHY_ERROR_DET) | BIT6;
    SC_SetByteDPppPHY(phyindex, _TMDS_DPHY_ERROR_DET, temp);
    temp = GetTMDSPHYDATA(phyindex, _TMDS_DPHY_ERROR_DET) & ~BIT6;
    SC_SetByteDPppPHY(phyindex, _TMDS_DPHY_ERROR_DET, temp);

    stEQSet.bIsFinish = FALSE;    
    usTMDSCheckErrorCntTimer = GetTimerTick();       

}

/**************************************************************************//**
 * Get Error count
 * @Param : TMDS link index
 * @Return : return the error count value by currently EQ settings
 ******************************************************************************/
ULONG TMDS_EQSet_GetErrCnt(UCHAR phyindex)
{
    UCHAR temp;
    USHRT error;
    ULONG errorsum;
/*
    temp = GetTMDSPHYDATA(phyindex, _TMDS_DPHY_CH0_ERROR) | BIT5;
    SC_SetByteDPppPHY(phyindex, _TMDS_DPHY_CH0_ERROR, temp);
    temp = GetTMDSPHYDATA(phyindex, _TMDS_DPHY_CH1_ERROR) | BIT5;
    SC_SetByteDPppPHY(phyindex, _TMDS_DPHY_CH1_ERROR, temp);
    temp = GetTMDSPHYDATA(phyindex, _TMDS_DPHY_CH2_ERROR) | BIT5;
    SC_SetByteDPppPHY(phyindex, _TMDS_DPHY_CH2_ERROR, temp);
    
    temp = GetTMDSPHYDATA(phyindex, _TMDS_DPHY_ERROR_DET) | BIT7;
    SC_SetByteDPppPHY(phyindex, _TMDS_DPHY_ERROR_DET, temp);
    temp = GetTMDSPHYDATA(phyindex, _TMDS_DPHY_ERROR_DET) | BIT6;
    SC_SetByteDPppPHY(phyindex, _TMDS_DPHY_ERROR_DET, temp);
    temp = GetTMDSPHYDATA(phyindex, _TMDS_DPHY_ERROR_DET) & ~BIT6;
    SC_SetByteDPppPHY(phyindex, _TMDS_DPHY_ERROR_DET, temp);
    Sleep(10);
*/
/*
    temp = GetTMDSPHYDATA(phyindex, _TMDS_DPHY_CH0_ERROR);
    //printf("_TMDS_DPHY_CH0_ERROR=%x\r\n", (USHRT)temp);
    temp = GetTMDSPHYDATA(phyindex, _TMDS_DPHY_CH1_ERROR);
    //printf("_TMDS_DPHY_CH1_ERROR=%x\r\n", (USHRT)temp);
    temp = GetTMDSPHYDATA(phyindex, _TMDS_DPHY_CH2_ERROR);
    //printf("_TMDS_DPHY_CH2_ERROR=%x\r\n", (USHRT)temp);
*/
    errorsum = 0x00;
    error = GetTMDSPHYDATA(phyindex, _TMDS_DPHY_ERRORCNT_CH0_HI) & 0x7F;
    error <<= 8;
    error += GetTMDSPHYDATA(phyindex, _TMDS_DPHY_ERRORCNT_CH0_LO);
    errorsum += error;
    //printf("_TMDS_DPHY_CH0_ERROR=%x\r\n", (USHRT)error);
    error = GetTMDSPHYDATA(phyindex, _TMDS_DPHY_ERRORCNT_CH1_HI) & 0x7F;
    error <<= 8;
    error += GetTMDSPHYDATA(phyindex, _TMDS_DPHY_ERRORCNT_CH1_LO);
    errorsum += error;
    //printf("_TMDS_DPHY_CH1_ERROR=%x\r\n", (USHRT)error);
    error = GetTMDSPHYDATA(phyindex, _TMDS_DPHY_ERRORCNT_CH2_HI) & 0x7F;
    error += GetTMDSPHYDATA(phyindex, _TMDS_DPHY_ERRORCNT_CH2_LO);
    errorsum += error;
    //printf("_TMDS_DPHY_CH2_ERROR=%x\r\n", (USHRT)error);
    if ((SC_HDMI_CKDT & 0x03) != 0x03) { // 0x606
        errorsum = 0x00FFFFFF;
    //printf("_SCDT fail\r\n");
    }
    
    temp = GetTMDSPHYDATA(phyindex, _TMDS_DPHY_ERROR_DET) & ~BIT7;
    SC_SetByteDPppPHY(phyindex, _TMDS_DPHY_ERROR_DET, temp);
    return errorsum;
}

/**************************************************************************//**
 * TMDS search best EQ settings flow
 * Search the best EQ with lowest error count
 * @Param : TMDS link index
 ******************************************************************************/
void TMDS_EQSet_Flow(void) 
{
    ULONG errcnt = 0;
    UCHAR phyindex;
    
    if ((SC_HDMI_CKDT & 0x03) != 0x03) { // 0x606
        return;
    }
    if ((stEQSet.bIsFinish == FALSE) && (IsZpMode() == FALSE)) {
        if (GetTimerTick() - usTMDSCheckErrorCntTimer > TMDSEQ_CHECK_ERROR_CNT_DELAY) {
            if ((GetCurrInputInterface() == DIGITAL_INPUT0) || (GetCurrInputInterface() == DIGITAL_INPUT1)) {
                phyindex = _DPPP_PHY0;
            }
            else {
                phyindex = _DPPP_PHY1;
            }
            errcnt = TMDS_EQSet_GetErrCnt(phyindex);
//            printf("stEQSet[%bx].ucCurrentSearchLevel go -> %bx , error = %4x\r\n",phyindex, stEQSet.ucCurrentSearchLevel, errcnt);

            if (errcnt == 0) {
//                printf("finish!\r\n");
                stEQSet.ulBestErrCnt = 0;            
                stEQSet.ucBestLevel = stEQSet.ucCurrentSearchLevel;
                stEQSet.bIsFinish = TRUE;
            }
            else {
                if (errcnt < stEQSet.ulBestErrCnt) {
//                    printf("stEQSet.ucBestLevel changed to %bx\r\n", stEQSet.ucCurrentSearchLevel);
                    stEQSet.ucBestLevel = stEQSet.ucCurrentSearchLevel;
                    stEQSet.ulBestErrCnt = errcnt;
                }

                if (stEQSet.ucCurrentSearchLevel == _Num_TMDSEQ-1) {//final level
                    if (stEQSet.ucBestLevel != _Num_TMDSEQ-1) {
                        TMDS_EQSet_EQSetting(phyindex, stEQSet.ucBestLevel);
                    }
//                    printf("finish!search over, all not good, ucBestLevel&ulBestErrCnt =[%bx]%x \r\n",stEQSet.ucBestLevel,stEQSet.ulBestErrCnt);
                    stEQSet.bIsFinish = TRUE;            
                }
                else {
                    stEQSet.ucCurrentSearchLevel++;
                    TMDS_EQSet_EQSetting(phyindex, stEQSet.ucCurrentSearchLevel);
                    TMDS_EQSet_ErrCntInit(phyindex);
                }
            }
        }
    }
}
#endif
void TMDSDataAlign(UCHAR phyindex)
{
    if ((SC_HDMI_CKDT & BIT1) != 0x00) {//CKDT   // 0x606
        ucTMDSInputMode = GetTMDSPHYDATA(phyindex, _HDMI_MHL_INFO);//hdmi_mhl_info
        if (ucTMDSInputMode == HDMI_NRM) {//HDMI_NRM
            SC_HDMI_DATA_ALIGN &= ~BIT0;  // 0x736
        }
        else if (ucTMDSInputMode == HDMI_HSP) {//HDMI_HSP
            SC_HDMI_DATA_ALIGN |= BIT0; // 0x736
        }
        else {//MHL
            if (ucTMDSInputMode == MHL2_PPM) {//PP mode
                SC_HDMI_DATA_ALIGN |= BIT0; // 0x736
            }
            else {
                SC_HDMI_DATA_ALIGN &= ~BIT0; // 0x736
            }
        }
    }
}
