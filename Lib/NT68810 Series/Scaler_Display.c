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
#if defined(ENABLE_FPGA_MODE)
#include "FpgaIIC.h"
#endif

//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************

//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************
static xdata ULONG ulDisplayClk; /*!< Variable of display clock. */
static xdata UCHAR ucAspRatioMode = ASP_RATIO_FULL; /*!< Variable of aspect ratio mode. */
static xdata USHRT usDisRatio = 0; /*!< Variable of the ratio of H/V. */

//******************************************************************************
// E X T E R N A L   V A R I A B L E   P R O T O T Y P E S
//******************************************************************************
extern xdata ULONG ulHFreqCounter;

//******************************************************************************
// S T A T I C   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
static void SetDPLL(void);
static void CheckInterlacedSignalField(void);
static void SetFixHR2(void);
static void CheckFIFO(void);
#if ENABLE_FREESYNC_DEMO == ON
static void VCRModeLockPosition(void);
#endif

//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// F U N C T I O N   B O D Y S
//******************************************************************************

/**************************************************************************//**
 * Initialize display-related registers.
 * Through this function, the scaler will be under free-run mode and output black screen.
 ******************************************************************************/
void DisplayInit(void)
{
    SC_FIFO_FLAG = 0x03;
    SC_FIFO_FLAG_EN = 0x00;
    EnableDPLL();

    SC_INTE_CTRL = 0x00;
    SC_BK_H_SHAP_CTRL |= BIT7;
    SC_DISP_DRIVE_CTRL = PANEL_PAD_DRIVE;
    SC_DISPLAY_POL_CTRL = (PANEL_DISP_DE_POL << 7) | (PANEL_DISP_HSYNC_POL << 5) | (PANEL_DISP_VSYNC_POL << 4);
#if PANEL_LVDS_OFFSET == 1
    SC_DISPLAY_POL_CTRL |= (BIT2 | BIT3);
#endif
    SC_DISPLAY_CLK_CTRL = 0x40;

    SC_DISPLAY_CHANNEL = BIT6;//(BIT5|BIT6);
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1) || (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
#if IS_NT68850_SERIES
    SC_DP_FAST_MUTE_CTRL = SCREG_B88;
#else
    SC_DP_VIDEO_FIFO_INT &= 0x0F;// 0x1044
#endif
#endif

    SC_DISP_SWAP = DT16A;

    SC_GRAPHIC_DISP_WIN_CTRL = 0x07;

#if ENABLE_FREESYNC_DEMO == ON
    SC_VCR_CTRL = 0x11;
    SC_HR_CTRL = 0x10; 
    //SC_SOG_DIGITAL_GLITCH_FILTER_THREESHOLD = 0x1F;// bit4:DP fast mute disable, bit3:   ,bit2:     ,bit1:Disable V change fast mute,
    SC_SOG_DIGITAL_GLITCH_FILTER_THREESHOLD = 0x12;// only need to disable V change fast mute when free-sync runing
#else
    SC_VCR_CTRL = 0x10;
    SC_HR_CTRL = 0x00;
#endif
    SC_RESIDUAL_DISP_HOR_SYNC_CTRL = 0x00;

    SC_FIFO_CTRL1 &= ~BIT6;
#if ENABLE_FREESYNC_DEMO == ON
    SC_FIFO_CTRL1 &= ~BIT5; // 0x190
#else
    SC_FIFO_CTRL1 |= BIT5;
#endif

    DisplayMuteImage();
    LoadDefaultPanelData();
    SetFreeRunClk();
    SetDclkSSC(UserPanelData.ucSpreadSpectrumCtrl);
    SC_DITHER_TP_GRAY_LVL_LO = 0x00;
    SC_DITHER_TP_GRAY_LVL_HI = 0x00;
}

/**************************************************************************//**
 * Turn off DPLL (display PLL).
 ******************************************************************************/
void DisableDPLL(void)
{
    UCHAR tmpReg0f0, tmpReg101, tmpReg065;
    
    tmpReg0f0 = SC_DPLL_CTRL1;
    tmpReg101 = SC_POWER_CTRL1;
    tmpReg065 = SC_GAMMA_CTRL;
    
    if ((tmpReg0f0 & BIT0) != 0) {
        // Do anything necessary here
        #if ENABLE_GAMMA
        SC_GAMMA_CTRL = 0x00;
        #endif    
        
        // Disable DPLL sequence
        SC_POWER_CTRL1 = tmpReg101 | BIT0;
        SC_DPLL_CTRL1 = tmpReg0f0 & ~BIT0;

        #if ENABLE_GAMMA
        SC_GAMMA_CTRL = tmpReg065;
        #endif    
    }
}

/**************************************************************************//**
 * Turn on DPLL (display PLL).
 ******************************************************************************/
void EnableDPLL(void)
{
    UCHAR tmpReg0f0, tmpReg101, tmpReg065;

    tmpReg0f0 = SC_DPLL_CTRL1;
    tmpReg101 = SC_POWER_CTRL1;
    tmpReg065 = SC_GAMMA_CTRL;

    if ((tmpReg0f0 & BIT0) == 0) {
        #if ENABLE_GAMMA
        SC_GAMMA_CTRL = 0x00;
        #endif    
        // Enable DPLL sequence
        SC_DPLL_CTRL1 = tmpReg0f0 | BIT0;
        SC_POWER_CTRL1 = tmpReg101 & ~BIT0;
        Sleep(5);

        // Do anything necessary here
        #if ENABLE_GAMMA
        SC_GAMMA_CTRL = tmpReg065;
        #endif    
    }    
}

/**************************************************************************//**
 * Turn on DCLK (display clock).
 ******************************************************************************/
void EnableDclk(void)
{
    SC_POWER_CTRL1 &= ~BIT0;
}

/**************************************************************************//**
 * Initialize display h/v parameters according to the panel spec.
 ******************************************************************************/
void LoadDefaultPanelData(void)
{
#if ENABLE_FOUR_PORT_LVDS == ON
#if PANEL_FOUR_PORT_LVDS == 1
code UCHAR panelfourportswaptab[] = {//Port A/B/C/D swap ( pixel swap )
    2,//000 = ABCD ( 0,1,2,3 ) 
    3,//001 = ACBD ( 0,2,1,3 ) 
    0,//010 = DCBA ( 3,2,1,0 ) 
    1,//011 = DBCA ( 3,1,2,0 ) 
    6,//100 = CDAB ( 2,3,0,1 ) 
    7,//101 = BDAC ( 1,3,0,2 ) 
    4,//110 = BADC ( 1,0,3,2 ) 
    5,//111 = CADB ( 2,0,3,1 ) 
};
#endif
#endif
    UCHAR ch;
    ch = 0x61;

    if (UserPanelData.bBitShift == TRUE) {
        ch |= BIT7;
    }
    else {
        ch &= ~BIT7;
    }
#if ENABLE_TEN_BIT_LVDS == ON
    if (UserPanelData.ucColorDepth == 8) { // 8-bit LVDS output
        ch &= ~(BIT4|BIT3);
    }
    else if (UserPanelData.ucColorDepth == 6) { // 6-bit LVDS output
        ch &= ~BIT4;
        ch |= BIT3;
    }
    else if (UserPanelData.ucColorDepth == 10) { // 10-bit LVDS output
        ch &= ~BIT3;
        ch |= BIT4;
    }
    else {
        ch |= (BIT4|BIT3);
    }
#else
    if (UserPanelData.ucColorDepth == 8) { // 8-bit LVDS output
        ch &= ~BIT3;
    }
    else {
        ch |= BIT3;
    }
#endif
    if (UserPanelData.bDualPortLVDS == TRUE) {
        ch &= ~BIT2;
    }
    else {
        ch |= BIT2;
    }
    if (UserPanelData.bDEMode == TRUE) {
        ch |= BIT1;
    }
    else {
        ch &= ~BIT1;
    }
#if ENABLE_FREESYNC_DEMO == ON
    ch &= ~BIT1;//sync mode
#endif
    SC_DISPLAY_CTRL = ch;

#if ENABLE_FOUR_PORT_LVDS == ON
#if PANEL_FOUR_PORT_LVDS == 1
    SC_LVDS_CTRL |= BIT1;  // 0x1b8
    SC_DISP_INTERFACE_CTRL = (PANEL_TEN_BIT_SHIFT << 6) | (panelfourportswaptab[PANEL_FOUR_PORT_SWAP] << 2);// 0x1b9
#else
    SC_DISP_SWAP |= BIT4;  // 0x16a
    SC_LVDS_CTRL &= ~BIT1;// 0x1b8
#if LVDS_AB_CD_SWAP == 0
    SC_DISP_INTERFACE_CTRL = 0x00;//AB port   // 0x1b9
#else
    SC_DISP_INTERFACE_CTRL = 0x20;// CD port// 0x1b9
#endif
#endif
#endif

    //Display VTotal
    WriteShortScaler(&SC_DV_TOTAL_LO, UserPanelData.usTypVTotal);
    //Display VSync Width
    SC_DV_VS_WID = (UCHAR) UserPanelData.usMinVSyncWidth;
    //Display Background Window Vertical Begin
    WriteShortScaler(&SC_DV_BG_BEG_LO, UserPanelData.usMinVSyncWidth + UserPanelData.usMinVSyncBackPorch);
    //Display Background Window Vertical Length
    WriteShortScaler(&SC_DV_BG_LEN_LO, UserPanelData.usHeight);
    //Display Active Window Vertical Begin
    WriteShortScaler(&SC_GRAPHIC_DISP_VER_ACT_BEG_LO, UserPanelData.usMinVSyncWidth + UserPanelData.usMinVSyncBackPorch);
    //Display Active Window Vertical Length
    WriteShortScaler(&SC_GRAPHIC_DISP_VER_ACT_LEN_LO, UserPanelData.usHeight);
    //Display HTotal
    WriteShortScaler(&SC_DH_HTOTAL_LO, UserPanelData.usTypHTotal);
    //Display HSync Width
    SC_DH_HS_WID = (UCHAR) UserPanelData.usMinHSyncWidth;
    //Display Background Window Horizontal Begin
    WriteShortScaler(&SC_DH_BG_BEG_LO, UserPanelData.usMinHSyncWidth + UserPanelData.usMinHSyncBackPorch);
    //Display Background Window Horizontal Width
    WriteShortScaler(&SC_DH_BG_WID_LO, UserPanelData.usWidth);
    //Display Active Window Horizontal Begin
    WriteShortScaler(&SC_GRAPHIC_DISP_HOR_ACT_BEG_LO, UserPanelData.usMinHSyncWidth + UserPanelData.usMinHSyncBackPorch);
    //Display Active Window Horizontal Width
    WriteShortScaler(&SC_GRAPHIC_DISP_HOR_ACT_WID_LO, UserPanelData.usWidth);
    //Free run htotal
    WriteShortScaler(&SC_FREE_RUN_HTOTAL_LO, PANEL_TYP_HTOTAL);
}

/**************************************************************************//**
 * Set free-run clock.
 * The clock is panel typical clock defined in panel spec.
 * This function set DCLK only and does not turn the scaler to free-run mode.
 ******************************************************************************/
void SetFreeRunClk(void)
{
    ulDisplayClk = (UserPanelData.ulFreeRunH_Freq * UserPanelData.usTypHTotal + 5) / 10;
    SetDPLL();
}

/**************************************************************************//**
 * Setup DPLL by ulDisplayClk.
 ******************************************************************************/
static void SetDPLL(void)
{
    ULONG temp;
#if 0//((MD_ENABLE_STRESS_TEST_KEY == ON) && (ENABLE_PREFRC == OFF) && (ENABLE_DFR == OFF)
#if ((MD_ENABLE_STRESS_TEST_KEY == ON) && (PANEL_WIDTH > 1680))
    if (ulDisplayClk < 200000000) {
        ulDisplayClk = 200000000;
    }
#else
    if (ulDisplayClk < 160000000) {
        ulDisplayClk = 160000000;
    }
#endif
#endif
//    SC_VPLL_CTRL |= BIT3;
#if ENABLE_FREESYNC_DEMO == ON
    if (bFreeSyncMode == TRUE) {
        ulDisplayClk = PANEL_MAX_LVDS_CLK;
    }
#endif
    temp = ((float)ulDisplayClk * 131072) / REF_CLK;
    SC_DDDS_RATIO_LO = (UCHAR) temp;   // 0x0f2
    SC_DDDS_RATIO_MI = (UCHAR) (temp >> 8);
    SC_DDDS_RATIO_HI = (UCHAR) (temp >> 16);
//    SC_VPLL_CTRL &= ~BIT3;
//    SetLvdsP2SByDCLK();
#if defined(ENABLE_FPGA_MODE)
    SetExtDPLL(ulDisplayClk);
#endif
}

#if ENABLE_LD == ON
/**************************************************************************//**
 * Setup DPLL to the specified clock.
 * @param clk Display clock. The unit is Hz.
 ******************************************************************************/
void SetDisplayDCLK(ULONG clk)
{
    ulDisplayClk = clk;
    SetDPLL();
}
#endif

#if ENABLE_LD == ON || ENABLE_PREFRC == ON
/**************************************************************************//**
 * Get display clock.
 * @return Display clock.
 ******************************************************************************/
ULONG GetDisplayDCLK(void)
{
    return ulDisplayClk;
}
#endif


/**************************************************************************//**
 * display clock Compress.
 * @param input and display timing
 ******************************************************************************/
void DispClkCompress(tTIMING *input,tTIMING *disp)
{
#if ENABLE_PREFRC == ON || ENABLE_DFR == ON
    if (!((GetInputSyncMode() == DIG_SYNC)
#if ENABLE_PREFRC == ON        
         && (usVSyncFreq < FRC_NACT_MIN || usVSyncFreq > FRC_NACT_MAX)
#elif ENABLE_DFR == ON   
         &&(usVSyncFreq < 310)
#endif
       ))
#endif
    { 
       disp->htotal = (UserPanelData.usMinHTotal / 8) * 8 + 8;
       disp->active_height = (USHRT) (((float)disp->clock / 100 / disp->htotal) * input->active_height / usHSyncFreq + 0.5);
       disp->vtotal = ((((ULONG)input->vtotal * disp->active_height) << 4) / input->active_height + 8) >> 4;
       
       if (disp->vtotal < UserPanelData.usMinVTotal) {
           disp->active_height = (ULONG) UserPanelData.usMinVTotal * input->active_height / input->vtotal;
       }
       
       if (IsInterlaced()) {
           disp->active_height >>= 1;
       }
      
       ulDisplayClk = disp->clock;
    }
}



/**************************************************************************//**
 * Setup the display timing.
 * The function includes:
 *  - Display clock calculation.
 *  - Panel timing limitation check.
 *  - In/out clock check.
 *  - Last line (fixed residue) calculation.
 * @param htotal50 Current input htotal value.
 ******************************************************************************/
BOOL SetupDisplayTiming(USHRT htotal50)
{
    USHRT i;
    xdata tTIMING input,disp;
    
    UCHAR Reg0x1ED;

    xdata float temp;
    BOOL interlace;
    
    Reg0x1ED = SC_ADC_BAND_GAP;// 0x1ed
    SC_ADC_BAND_GAP |= BIT0;
	htotal50 = 0; // Disable compiler error.
    SC_DISPLAY_CTRL |= BIT5; //fifo auto lock, auto usHTotal
    SC_GRAPHIC_DISP_WIN_CTRL = 0x07;

    input.active_width = ReadShortScaler(&SC_GI_CAP_HWID_LO);
    input.active_height = ReadShortScaler(&SC_GI_CAP_VLEN_LO);
    if ((input.active_height > 1024) && (input.active_width < 1280)) { //Dual link
        LoadDefaultPanelData();
        SetFreeRunClk();
        return FALSE;
    }

    input.vtotal = GetInputVTotal();

    if (IsInterlaced()) {
        interlace = TRUE;
    }
    else {
        interlace = FALSE;
    }

    disp.active_height = UserPanelData.usHeight; //Set the vertical active height to the Panel Height

#if ENABLE_FIT_ALL_PANEL_SPEC == ON
    disp.vtotal = ((((ULONG)input.vtotal * disp.active_height) << 4) / input.active_height + 8) >> 4;
    if (disp.vtotal > UserPanelData.usMaxVTotal) {
        disp.vtotal = UserPanelData.usMaxVTotal;
        disp.active_height = ((((ULONG)disp.vtotal * input.active_height) << 4) / input.vtotal + 8) >> 4;
    }
#endif

    for (disp.htotal = (UserPanelData.usMinHTotal / 8) * 8 + 8; disp.htotal < UserPanelData.usMaxHTotal; disp.htotal += 8) {
        temp = ((float)disp.htotal-0.1) * disp.active_height * 4096 / ulHFreqCounter / input.active_height;
        ulDisplayClk = (ULONG) (temp * REF_CLK * 16);
        if (interlace == TRUE) {
            ulDisplayClk <<= 1;
        }
        if (ulDisplayClk > UserPanelData.ulMinPClk) {
            break;
        }
    }

    if (disp.htotal > UserPanelData.usMaxHTotal) { //Htotal too large, dclk too small
        disp.htotal -= 8;
    }

#if ENABLE_FIT_ALL_PANEL_SPEC == ON
    if ((ulDisplayClk > UserPanelData.ulMaxPClk) || (ulDisplayClk < UserPanelData.ulMinPClk))  {
        LoadDefaultPanelData();
        SetFreeRunClk();
        return FALSE;
    }
#endif

#if ENABLE_AUTOFRAMEDOWN == OFF && ENABLE_DFR == OFF && ENABLE_POSTFRC == OFF && ENABLE_CENTER_MODE == OFF
    if (ulDisplayClk > UserPanelData.ulMaxPClk) {
        disp.clock = UserPanelData.ulMaxPClk;
        DispClkCompress(&input,&disp);
    }
#endif

    WriteShortScaler(&SC_DV_BG_LEN_LO, disp.active_height); //Display Background Vertical Length
    WriteShortScaler(&SC_GRAPHIC_DISP_VER_ACT_LEN_LO, disp.active_height); //Display Active Vertical Length

    temp = ((float)disp.htotal-0.1) * disp.active_height * 4096 / ulHFreqCounter / input.active_height;
    ulDisplayClk = (ULONG) (temp * REF_CLK * 16);
    
#if ENABLE_AUTOFRAMEDOWN == ON
    FRC_AutoFrameDown(&ulDisplayClk);
#endif
#if ENABLE_POSTFRC == ON
    FRCConfigPostFRC(PANEL_FRC_OUTPUT_VSYNC, FALSE);
#endif
    
    if (interlace == TRUE) {
        ulDisplayClk <<= 1;
    }

    SetDPLL();
    Sleep(80);

    if (CheckModeChangeFlag() == FALSE) {
        if (interlace == TRUE) { //1080i
            i = SC_DISPLAY_CTRL;
            SC_DISPLAY_CTRL = (i & ~BIT5); //Manual HTotal
        }
        else {
            i = ReadShortScalerHighLowFilter(&SC_DSP_HTOTAL_LO) & 0x0FFF;
            if (abs(i-disp.htotal) < 5) {
                disp.htotal = i;
            }
        }
        disp.vtotal = (float)ulDisplayClk * 10 / disp.htotal / usVSyncFreq + 0.5;
        
        WriteShortScaler(&SC_DV_TOTAL_LO, disp.vtotal); //Display Active Vtotal
        WriteShortScaler(&SC_DV_BG_BEG_LO, UserPanelData.usMinVSyncWidth + UserPanelData.usMinVSyncBackPorch); //Display Background VStart
        i = UserPanelData.usMinVSyncWidth + UserPanelData.usMinVSyncBackPorch + (UserPanelData.usHeight - disp.active_height) / 2;
        WriteShortScaler(&SC_GRAPHIC_DISP_VER_ACT_BEG_LO, i); //Display Active VStart
        WriteShortScaler(&SC_DH_HTOTAL_LO, disp.htotal); //Display Active Htotal

        if (disp.active_height != UserPanelData.usHeight) {
            i = SC_DISPLAY_CTRL;
            SC_DISPLAY_CTRL = (i & ~BIT5); //Manual HTotal
        }
    }

    WriteShortScaler(&SC_DV_BG_LEN_LO, UserPanelData.usHeight); //Display Background Vertical Length

    // CheckFIFO must be prior to SetFixHR2 because FIFO lock setting!
    CheckFIFO();
    
    CheckInterlacedSignalField();

    if (CheckModeChangeFlag() == FALSE) {
#if ENABLE_FREESYNC_DEMO == OFF && ENABLE_DFR == OFF && ENABLE_POSTFRC == OFF
        if ((disp.active_height == UserPanelData.usHeight)) {// && (UserPanelData.usHeight < 1440)) {
            SetFixHR2();
        }
#endif
#if ENABLE_DFR == ON
        FRCConfigDFR();
#endif
    }
    else {
        LoadDefaultPanelData();
        SetFreeRunClk();
    }

#if ENABLE_SR == ON
     SetSRInputTimingParameter();
#endif

    SC_ADC_BAND_GAP = Reg0x1ED;
    return TRUE;
}

/**************************************************************************//**
 * Set the background color of post-pattern.
 * @param r Gray level of red color.
 * @param g Gray level of green color.
 * @param b Gray level of blue color.
 ******************************************************************************/
void SetPostBGColor(UCHAR r, UCHAR g, UCHAR b)
{
    SC_DISP_BACKGROUND_RED = r;
    SC_DISP_BACKGROUND_GREEN = g;
    SC_DISP_BACKGROUND_BLUE = b;
}

/**************************************************************************//**
 * Set the background color of post pattern, turn the scaler to free-run mode and output post-pattern.
 * @param r Gray level of red color.
 * @param g Gray level of green color.
 * @param b Gray level of blue color.
 ******************************************************************************/
void Force2Background(UCHAR r, UCHAR g, UCHAR b)
{
    if ((SC_DISPLAY_MUTE_CTRL & 0x03) != 0x02) {
        SetPostBGColor(r, g, b);
        DisplayMuteImage();
        LoadDefaultPanelData();
        SetFreeRunClk();
    }
    SC_DISPLAY_CHANNEL = BIT6;//(BIT5|BIT6); //RGB
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1) || (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
#if IS_NT68850_SERIES
    SC_DP_FAST_MUTE_CTRL = SCREG_B88;
#else
    SC_DP_VIDEO_FIFO_INT &= 0x0F;// 0x1044
#endif
#endif
}

/**************************************************************************//**
 * Wait until next display VSync pulse.
 * The maximum waiting time is 100ms.
 * If the display-related power is off, the default delay time is 40ms.
 ******************************************************************************/
void WaitDisVSync(void)
{
    USHRT temp;

    // Confirm the scaler has display VSync out or not!
    if (((SC_POWER_CTRL1 & BIT0) != 0) ||
#if (!defined(ENABLE_FPGA_MODE))
        ((SC_DPLL_CTRL1 & BIT0) == 0) ||
#endif
        ((SC_DISPLAY_CTRL & BIT0) == 0)) {
        Sleep(40);
        return;
    }

    ResetWDTimer();
    if ((SC_DISPLAY_POL_CTRL & BIT4) == 0x00) {
        temp = GetTimerTick();
        while ((GetTimerTick() - temp) < 50) {
            if ((SC_DISP_SYNC_STATUS & BIT7) == 0) {
                break;
            }
        }
        while ((GetTimerTick() - temp) < 100) {
            if ((SC_DISP_SYNC_STATUS & BIT7) != 0) {
                break;
            }
        }
    }
    else {
        temp = GetTimerTick();
        while ((GetTimerTick() - temp) < 50) {
            if ((SC_DISP_SYNC_STATUS & BIT7) != 0) {
                break;
            }
        }
        while ((GetTimerTick() - temp) < 100) {
            if ((SC_DISP_SYNC_STATUS & BIT7) == 0) {
                break;
            }
        }
    }
    ResetWDTimer();
}

/**************************************************************************//**
 * Disable display (mute R/G/B data).
 ******************************************************************************/
void GraphicDisplayWindowDisable(void)
{
    SC_DITHER_TOGGLE_CTRL |= BIT7;
}

/**************************************************************************//**
 * Enable display (un-mute R/G/B data).
 ******************************************************************************/
void GraphicDisplayWindowEnable(void)
{
    SC_DITHER_TOGGLE_CTRL &= ~BIT7;
}

/**************************************************************************//**
 * Check Interlaced Signal Odd/Even Field
 ******************************************************************************/
void CheckInterlacedSignalField(void)
{
//    xdata UCHAR i,j, *p, matrix[3][6], reg0x1D0;
    xdata UCHAR ssc_backup, reg0x150, reg0x154,reg0x188;
    xdata USHRT temp, tmp_ord, tmp_erd;

    if (IsInterlaced()) { //If input is interlaced
        reg0x154 = SC_DISPLAY_MUTE_CTRL;
        reg0x150 = SC_DISPLAY_CTRL;
        reg0x188 = SC_VCR_CTRL;

        SC_DITHER_TOGGLE_CTRL |= BIT7;
        //for get data to calculate   
        SC_DISPLAY_MUTE_CTRL = 0x00;
 
        ssc_backup = SC_SSC_CTRL;
        DisableDclkSSC();
//        SC_DISPLAY_MUTE_CTRL = 0x00;
        if ((SC_INPUT_SELECT & 0x03) < 2) {   //analog
            SC_GRAPHIC_DISP_WIN_CTRL = 0x07;
            temp = GetInputVStart();
            SetEvenFieldOffset(0);
            SetVP(5);
            DelayVTime(8);//50Hz: over 120ms, 60Hz: over 100ms. 6 times frame
            if (abs(ReadShortScalerHighLowFilter(&SC_MISC_O_RD_LO) - ReadShortScalerHighLowFilter(&SC_MISC_E_RD_LO)) > 1) {
                SetEvenFieldOffset(-1);
                SetVP(5);
                DelayVTime(8);//50Hz: over 120ms, 60Hz: over 100ms. 6 times frame
                if (abs(ReadShortScalerHighLowFilter(&SC_MISC_O_RD_LO) - ReadShortScalerHighLowFilter(&SC_MISC_E_RD_LO)) > 1) {
                    SetEvenFieldOffset(1);
                    SetVP(5);
                    DelayVTime(8);//50Hz: over 120ms, 60Hz: over 100ms. 6 times frame
                }
            }
            SetVP(temp);
            DelayVTime(8);//50Hz: over 120ms, 60Hz: over 100ms. 6 times frame
            if (abs(ReadShortScalerHighLowFilter(&SC_MISC_O_RD_LO) - ReadShortScalerHighLowFilter(&SC_MISC_E_RD_LO)) > 1) {
                SC_GRAPHIC_DISP_WIN_CTRL = 0x47;
            }
        }
    #if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1) || (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
        else if ((SC_INPUT_SELECT & 0x03) == 0x03) {   //displayport
            SC_GRAPHIC_DISP_WIN_CTRL = 0x07;
#if 1// CEA timing 39: 1920x1080i/50Hz temp solution
            if ((GetInputVTotal() > 593) && ((GetVCaptureSize() == 1080) || (GetDigInputVActiveImmediate() == 540))) {            
                // CEA timing 39: 1920x1080i/50Hz
                SC_GI_SYNC_CTRL3 |= BIT0; // 0x199
            }
            else {
                SC_GI_SYNC_CTRL3 &= ~BIT0; // 0x199
            }
#endif
        }
    #endif
        else {
            SC_GRAPHIC_DISP_WIN_CTRL = 0x07;
            if (abs(ReadShortScalerHighLowFilter(&SC_GI_CAP_VBEGO_LO) - ReadShortScalerHighLowFilter(&SC_GI_CAP_VBEGE_LO)) > 0) {
                if ((SC_GI_SYNC_CTRL3 & BIT0) == 0x00) { // 0x199
                    SC_GI_SYNC_CTRL3 |= BIT0; // 0x199
                    temp = ReadShortScaler(&SC_GI_CAP_VBEGE_LO);
                    WriteShortScaler(&SC_GI_CAP_VBEGE_LO, ReadShortScaler(&SC_GI_CAP_VBEGO_LO));
                    WriteShortScaler(&SC_GI_CAP_VBEGO_LO, temp);
                }
            }
#if 1// CEA timing 39: 1920x1080i/50Hz temp solution
            else if ((GetInputVTotal() > 593) && ((GetVCaptureSize() == 1080) || (GetDigInputVActiveImmediate() == 540))) {            
                // CEA timing 39: 1920x1080i/50Hz
                SC_GI_SYNC_CTRL3 |= BIT0; // 0x199
            }
            else {
                SC_GI_SYNC_CTRL3 &= ~BIT0; // 0x199
            }
#endif

            DelayVTime(8);//50Hz: over 120ms, 60Hz: over 100ms. 6 times frame
            tmp_ord = ReadShortScalerHighLowFilter(&SC_MISC_O_RD_LO);
            tmp_erd = ReadShortScalerHighLowFilter(&SC_MISC_E_RD_LO);

            if (abs(ReadShortScalerHighLowFilter(&SC_MISC_O_RD_LO) - ReadShortScalerHighLowFilter(&SC_MISC_E_RD_LO)) > 1) {
                SC_GRAPHIC_DISP_WIN_CTRL |= BIT6;
                DelayVTime(8);
                // If the blanking time of odd/even fields are not stable, we switch the settings of odd/even position
                // Jude 2011/10/18
                if ((abs(tmp_ord - ReadShortScalerHighLowFilter(&SC_MISC_O_RD_LO)) > 5) ||
                    (abs(tmp_erd - ReadShortScalerHighLowFilter(&SC_MISC_E_RD_LO)) > 5)) {
                    temp = ReadShortScaler(&SC_GI_CAP_VBEGE_LO);
                    WriteShortScaler(&SC_GI_CAP_VBEGE_LO, ReadShortScaler(&SC_GI_CAP_VBEGO_LO));
                    WriteShortScaler(&SC_GI_CAP_VBEGO_LO, temp);
                }
            }
        }
        SC_SSC_CTRL = ssc_backup;

        SC_DISPLAY_MUTE_CTRL = reg0x154;
        SC_DISPLAY_CTRL = reg0x150;
        SC_VCR_CTRL = reg0x188;
        SC_DITHER_TOGGLE_CTRL &= ~BIT7;
    }
}

/**************************************************************************//**
 * Get display vertical DE time.
 * @return Number of counts of display clock.
 ******************************************************************************/
ULONG GetVCounter(void)
{
    xdata ULONG vtotalcounter, vtotalcounter2;
    UCHAR i;

    vtotalcounter = Read3ByteScalerHighLowFilter(&SC_VER_COUNTER_LO);
    DelayVTime(1);
    vtotalcounter2 = Read3ByteScalerHighLowFilter(&SC_VER_COUNTER_LO);
    i=0;

    while((labs(vtotalcounter - vtotalcounter2) < 0x10) && (i < 3)) {
        i++;
        vtotalcounter = Read3ByteScalerHighLowFilter(&SC_VER_COUNTER_LO);
        DelayVTime(1);
        vtotalcounter2 = Read3ByteScalerHighLowFilter(&SC_VER_COUNTER_LO);
    }
    
    vtotalcounter = (vtotalcounter + vtotalcounter2) >> 1;

    return vtotalcounter;
}

/**************************************************************************//**
 * Force the display clock to the one with desired HR2 (count of latest line).
 * We use this function to force the display residue to the value we expect.
 ******************************************************************************/
void SetFixHR2(void)
{
//    xdata UCHAR matrix[3][6], reg0x1D0;
//    xdata UCHAR j, *p;
    xdata UCHAR reg0x150, reg0x154, i,reg0x188;
    xdata USHRT gdv_act_len, vtotal, cal_hr1, cal_hr2, temp;
    xdata ULONG vtcnt, vdecnt, tempvtcnt;
    xdata signed short delta0p9hr1, deltahr2of0p9hr1, hr2of0p9hr1, delta_hr2, dsthtotal, wanted_hr2;
    xdata signed long delta_clk;

    reg0x154 = SC_DISPLAY_MUTE_CTRL;
    reg0x150 = SC_DISPLAY_CTRL;
    reg0x188 = SC_VCR_CTRL;
/*
    reg0x1D0 = SC_SRGB_CTRL;
    for (i=0; i<3; i++) {
        SC_SRGB_CTRL = ((i * 2) + 0x01);
        p = &SC_SRGB_COEF_R_LO;
        for (j=0; j<6; j++) {
            matrix[i][j] = *p;
            *p = 0;
            p++;
        }
    }
    SC_SRGB_CTRL = 0x0D;
*/
    SC_DITHER_TOGGLE_CTRL |= BIT7;
    //for get data to calculate   
    SC_DISPLAY_MUTE_CTRL = 0x00;
    
    gdv_act_len = ReadShortScaler(&SC_GRAPHIC_DISP_VER_ACT_LEN_LO);
    WriteShortScaler(&SC_DV_BG_LEN_LO, gdv_act_len);
    SC_DISPLAY_CTRL = (reg0x150 | BIT5);

    // Before HR2 calculation, force HR1 being closed to 0.9 V-active length.
    temp = ReadShortScalerHighLowFilter(&SC_HR_VALUE_LO);
    if (temp > (gdv_act_len * 0.9)) {
        delta0p9hr1 = temp - (gdv_act_len * 0.9);
    }
    else {
        delta0p9hr1 = temp + (gdv_act_len * 0.1);
    }
    dsthtotal = ReadShortScalerHighLowFilter(&SC_DSP_HTOTAL_LO) & 0x0FFF;
    if( (dsthtotal >= UserPanelData.usMinHTotal) && (dsthtotal <= UserPanelData.usMaxHTotal) ){
      delta_clk = (float) ulDisplayClk * delta0p9hr1 / gdv_act_len / dsthtotal;
      ulDisplayClk -= delta_clk;
      SetDPLL();
    }
    SC_HR_CTRL = 0x01;
    SC_VCR_CTRL = 0x06;
    Sleep(80);
    if (CheckModeChangeFlag() == FALSE) {
        dsthtotal = 0;
        vtcnt = 0;
        vdecnt = 0;
        for (i=0; i<4; i++) {
            SC_VCR_CTRL = 0x06;
            DelayVTime(1);
            dsthtotal += ReadShortScalerHighLowFilter(&SC_DSP_HTOTAL_LO);
            if (IsInterlaced()) { //If input is interlaced
                tempvtcnt = GetVCounter();
            }
            else {
                tempvtcnt = Read3ByteScalerHighLowFilter(&SC_VER_COUNTER_LO);
//                printf("tempvtcnt x=%ld\r\n",tempvtcnt);
            }
            if ((UserPanelData.usWidth == 2560) && (UserPanelData.usHeight == 1440)) {//QHD
                if (tempvtcnt < (ULONG)UserPanelData.usWidth * UserPanelData.usHeight) {//0xFFFFF
                    tempvtcnt += 0x400000;
                }
            }
            vtcnt += tempvtcnt;
            SC_VCR_CTRL = 0x02;
            vdecnt += Read3ByteScalerHighLowFilter(&SC_VER_COUNTER_LO);
//                printf("vdecnt x=%ld\r\n",vdecnt);
        }    
        dsthtotal = (dsthtotal + 2) / 4;
        vtcnt = (vtcnt + 2) / 4;
//        printf("vtcnt x=%ld\r\n",vtcnt);
        vdecnt = (vdecnt + 2) / 4;
//        printf("vdecnt x=%ld\r\n",vdecnt);
        cal_hr1 = vdecnt % gdv_act_len;
        cal_hr2 = vtcnt % dsthtotal;
        vtotal = vtcnt / dsthtotal;
//        printf("cal_hr1=%d\r\n",cal_hr1);
//        printf("cal_hr2=%d\r\n",cal_hr2);
//        printf("vtotal=%d\r\n",vtotal);
//        printf("dsthtotalx=%d\r\n",dsthtotal);

        delta0p9hr1 = (gdv_act_len * 0.9) - cal_hr1;
        deltahr2of0p9hr1 = (float)delta0p9hr1 * vtotal / gdv_act_len;
        hr2of0p9hr1 = cal_hr2 + deltahr2of0p9hr1;

//        printf("delta0p9hr1=%d\r\n",delta0p9hr1);
//        printf("deltahr2of0p9hr1=%d\r\n",deltahr2of0p9hr1);
//        printf("hr2of0p9hr1=%d\r\n",hr2of0p9hr1);

        if (hr2of0p9hr1 > (dsthtotal*9/6)) {
            wanted_hr2 = dsthtotal*9/6;
        }
        else if (hr2of0p9hr1 > (dsthtotal*7/6)) {
            wanted_hr2 = dsthtotal*7/6;
        }
        else if (hr2of0p9hr1 > (dsthtotal*5/6)) {
            wanted_hr2 = dsthtotal*5/6;
        }
        else if (hr2of0p9hr1 > (dsthtotal*3/6)) {
            wanted_hr2 = dsthtotal*3/6;
        }
        else if (hr2of0p9hr1 > (dsthtotal*1/6)) {
            wanted_hr2 = dsthtotal*1/6;
        }
        else if (hr2of0p9hr1 > -(dsthtotal*1/6)) {
            wanted_hr2 = -(dsthtotal*1/6);
        }
        else if (hr2of0p9hr1 > -(dsthtotal*3/6)) {
            wanted_hr2 = -(dsthtotal*3/6);
        }
        else {
            wanted_hr2 = dsthtotal*1/6;
        }
        delta_hr2 = wanted_hr2 - cal_hr2;

//        printf("wanted_hr2=%d\r\n",wanted_hr2);
//        printf("delta_hr2=%d\r\n",delta_hr2);

//        printf("ulDisplayClk w=%ld\r\n",ulDisplayClk);
        delta_clk = (float)ulDisplayClk * delta_hr2 / vtotal /dsthtotal;
//        printf("delta_clk=%ld\r\n",delta_clk);
        ulDisplayClk +=delta_clk;   //here is for hr2
//        printf("ulDisplayClk=%ld\r\n",ulDisplayClk);

        if (dsthtotal%2) {        //for hr1
            ulDisplayClk = (float)ulDisplayClk / dsthtotal * (dsthtotal-1);
//            printf("ulDisplayClk x=%ld\r\n",ulDisplayClk);
            WriteShortScaler(&SC_DH_HTOTAL_LO, dsthtotal-1); //Display Active Htotal
        }
        else {
            WriteShortScaler(&SC_DH_HTOTAL_LO, dsthtotal); //Display Active Htotal
        }
        SetDPLL();
////////check/////////////////////////////////
#if 0
        SC_DISPLAY_CTRL = (reg0x150 & ~BIT5);
        SC_HR_CTRL = 0x01;
        Sleep(80);
        cal_hr1 = ReadShortScalerHighLowFilter(&SC_HR_VALUE_LO);
        printf("cal_hr1=%d\r\n", cal_hr1);
        SC_HR_CTRL = 0x12;
        Sleep(80);
        cal_hr2 = ReadShortScalerHighLowFilter(&SC_HR_VALUE_LO);
        SC_HR_CTRL = 0x00;
        printf("cal_hr2=%d\r\n", cal_hr2);
        dsthtotal = ReadShortScalerHighLowFilter(&SC_DSP_HTOTAL_LO);
        printf("dsthtotaly=%d\r\n",dsthtotal);
#endif
///////////////////////////////////////////
    }
    SC_DISPLAY_MUTE_CTRL = reg0x154;
    SC_HR_CTRL = 0x00;
    SC_DISPLAY_CTRL = reg0x150;
#if 0
    if (CheckModeChangeFlag() == FALSE) {
        Sleep(80);
        dsthtotal = ReadShortScalerHighLowFilter(&SC_DSP_HTOTAL_LO);
        WriteShortScaler(&SC_DH_HTOTAL_LO, dsthtotal); //Display Active Htotal
        printf("dsthtotalz=%d\r\n",dsthtotal);
    }
#endif
    WriteShortScaler(&SC_DV_BG_LEN_LO, UserPanelData.usHeight);
    SC_VCR_CTRL = reg0x188;
/*
    for (i=0; i<3; i++) {
        SC_SRGB_CTRL = ((i * 2) + 0x01);
        p = &SC_SRGB_COEF_R_LO;
        for (j=0; j<6; j++) {
            *p = matrix[i][j];
            p++;
        }
    }
    SC_SRGB_CTRL |= BIT3;
    SC_SRGB_CTRL = reg0x1D0;
*/
    SC_DITHER_TOGGLE_CTRL &= ~BIT7;
}

/**************************************************************************//**
 * Get display h/v ratio.
 * E.x. 0 means full screen.
 *      1333 means 4:3.
 *      1250 means 5:4.
 *      1600 means 16:10.
 * @return Display h/v ratio.
 ******************************************************************************/
/*
USHRT GetCustomDspRatio(void)
{
    return usDisRatio;
}
*/

/**************************************************************************//**
 * Set display h/v ratio.
 * ratio : Range is "less then 1000", or "1000 to 65535".
 *         E.x. If aspect ratio is full screen, ratio is "less then 1000". 0 is preferred.
 *              If aspect ratio is 16:10, ratio is 1600.
 *              If aspect ratio is 5:4, ratio is 1250.
 *              If aspect ratio is 4:3, ratio is 1333.
 * @param ratio Display h/v ratio.
 ******************************************************************************/
void SetCustomAspRatio(USHRT ratio)
{
    USHRT dh_bg_beg, width, begin;

    usDisRatio = ratio;
    dh_bg_beg = ReadShortScaler(&SC_DH_BG_BEG_LO);

    if (ratio < 1000) {
        width = UserPanelData.usWidth;
        begin = dh_bg_beg;
    }
    else {
        width = ((ULONG)UserPanelData.usHeight * ratio + 500) / 1000;
        width &= 0xFFFE; // Force active width being even
        if (width > UserPanelData.usWidth) width = UserPanelData.usWidth;
        begin = dh_bg_beg + (UserPanelData.usWidth - width) / 2;
    }

#if 1
    if ((begin != ReadShortScaler(&SC_GRAPHIC_DISP_HOR_ACT_BEG_LO)) ||
        (width != ReadShortScaler(&SC_GRAPHIC_DISP_HOR_ACT_WID_LO))) {
#else
    {
#endif
        WaitDisVSync();
        GraphicDisplayWindowDisable();
        WriteShortScaler(&SC_GRAPHIC_DISP_HOR_ACT_BEG_LO, begin);
        WriteShortScaler(&SC_GRAPHIC_DISP_HOR_ACT_WID_LO, width);
        Sleep(80);
        WaitDisVSync();
        GraphicDisplayWindowEnable();
    }
}

/**************************************************************************//**
 * Set display ratio by mode.
 * If the mode is
 *   ASP_RATIO_FULL  : Display full screen.
 *   ASP_RATIO_SCALE : Keep org. display ratio.
 *   ASP_RATIO_4_3   : Force display ratio to 4:3.
 *   ASP_RATIO_SMART_4_3 : Force display ratio to 4:3 if input ratio is small 16:10.
 *   ASP_RATIO_REAL  : pixel by pixel.
 * @param aspectmode Aspect ratio mode.
 ******************************************************************************/
void SetDisplayMode(AspectRatio aspectmode)
{
    USHRT input_vactive, input_hactive, ratio;

    ucAspRatioMode = aspectmode;
    if ((SC_INPUT_SELECT & 0x03) < 2) {   //analog
        input_vactive = InputTiming.usModeVActive; 
        input_hactive = InputTiming.usModeHActive; //for double sampling (ucSampling)
    }
    else {    
        input_vactive = ReadShortScaler(&SC_GI_CAP_VLEN_LO);
        input_hactive = ReadShortScaler(&SC_GI_CAP_HWID_LO);
    }


    if (aspectmode == ASP_RATIO_SMART_4_3) {
        ratio = input_hactive * 10 / input_vactive;
        if (ratio < 16)
            aspectmode = ASP_RATIO_4_3;
        else
            aspectmode = ASP_RATIO_FULL;
    }

    if (aspectmode == ASP_RATIO_4_3) {
        ratio = 1333;
    }
    else if (aspectmode == ASP_RATIO_SCALE) {
        ratio = ((ULONG) input_hactive * 1000 + input_vactive / 2)
                / input_vactive;
    }
    else if (aspectmode == ASP_RATIO_REAL) {
        ratio = 0;
    }
    else { //Full screen
        ratio = 0;
    }

    SetCustomAspRatio(ratio);
    
#if ENABLE_CENTER_MODE == ON
//    if ((aspectmode == ASP_RATIO_REAL) && (input_hactive <= 1920) && (input_vactive <= 1080)) {
    if ((InputTiming.usModeHActive <= 1920) && (InputTiming.usModeVActive <= 1080) && (InputTiming.usVSyncFreq > 450)) {
//    if ((input_hactive < 1920) && (input_vactive < 1080)) {
//        WaitDisVSync();
        GraphicDisplayWindowDisable();
        if (aspectmode == ASP_RATIO_REAL) {
            SetCenterMode();
        ///////////////////////check MMU BW
            if ((InputTiming.usModeHActive == 1920) && (InputTiming.usModeVActive == 1080)) {
                ODAPI_DisableOD();
            }
        ///////////////////////////////
        }
        else {
            DisableCenterMode();
            WriteShortScaler(&SC_DH_BG_WID_LO, UserPanelData.usWidth);
            WriteShortScaler(&SC_DV_BG_LEN_LO, UserPanelData.usHeight);
            WriteShortScaler(&SC_GRAPHIC_DISP_VER_ACT_LEN_LO, UserPanelData.usHeight);
            if (aspectmode == ASP_RATIO_FULL) {
                WriteShortScaler(&SC_GRAPHIC_DISP_HOR_ACT_WID_LO, UserPanelData.usWidth);
            }
            SetDPLL();
        }
        Sleep(80);
        WaitDisVSync();
        GraphicDisplayWindowEnable();
    }
#endif
}

/**************************************************************************//**
 * Setup aspect ratio and enable scaler fast mute function.
 ******************************************************************************/
void NormalDisplay(void)
{
    UCHAR currentinterface = GetCurrInputInterface();
//    SC_DITHER_TP_GRAY_LVL_LO = 0x00;
//    SC_DITHER_TP_GRAY_LVL_HI = 0x00;
    SC_DITHER_TOGGLE_CTRL |= BIT7;
#if (!defined(ENABLE_FPGA_MODE))
//#if ENABLE_FREESYNC_DEMO == OFF   // 20160202 Yung mask
    SC_DISPLAY_CHANNEL |= BIT7;
//#endif
#endif
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1) || (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
    if ((currentinterface == DISPLAY_PORT_INPUT) || (currentinterface == DISPLAY_PORT_INPUT1)
     || (currentinterface == DISPLAY_PORT_INPUT2) || (currentinterface == DISPLAY_PORT_INPUT3)) {
#if IS_NT68850_SERIES
        SC_DP_FAST_MUTE_CTRL |= 0x0B;
#else
        SC_DP_VIDEO_FIFO_INT |= 0x70;// 0x1044
#endif
    }
#endif
    SC_DISPLAY_MUTE_CTRL = 0x00;
    //SetDisplayMode(ucAspRatioMode);
    UserSetAspectRatio();
    SetPostBGColor(0x00, 0x00, 0x00); // Set black color to avoid unexpected color from user-level burn-in mode.
    Sleep(40);
    if ((SC_INPUT_SELECT & 0x03) < 2) { //analog
        WaitHPLLstable();
        HwAutoOffset();
        if ((SC_GI_SYNC_CTRL & 0x03) == 0x01) {
            SC_HPLL_FREQ_CTRL |= BIT6; //Disable updating HS_CNT// 0xd1
        }
    }

    // Reduce time to detect overflow when input HSync is varied.
    SetupHSyncOverflowMask(TRUE);
    
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1) || (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
    if ((currentinterface == DISPLAY_PORT_INPUT) || (currentinterface == DISPLAY_PORT_INPUT1)
     || (currentinterface == DISPLAY_PORT_INPUT2) || (currentinterface == DISPLAY_PORT_INPUT3)) {
        SC_DP_CSC_AUTO_CONF |= 0xC0; // 0x1040
        SC_DP_VIDEO_FIFO_INT |= 0x03;// 0x1044
    }
#endif
}

/**************************************************************************//**
 * Configure post-pattern and turn it on (display free-run).
 ******************************************************************************/
void DisplayPostPattern(UCHAR pattern)
{
    SC_DISPLAY_MUTE_CTRL = pattern | 0x01;
}

/**************************************************************************//**
 * Mute display with OSD enabled (display free-run).
 ******************************************************************************/
void DisplayMuteImage(void)
{
    SC_DISPLAY_MUTE_CTRL = 0x02;
}

/**************************************************************************//**
 * Turn the scaler to normal display.
 ******************************************************************************/
void DisplayNormalImage(void)
{
    WaitDisVSync();
    SC_DITHER_TOGGLE_CTRL &= ~BIT7;
}

/**************************************************************************//**
 * Enable SSC.
 ******************************************************************************/
void EnableDclkSSC(void)
{
#if ENABLE_EDP == OFF
    if (UserPanelData.bEnableSSC) {
        SC_SSC_CTRL |= BIT0;
    }
    else {
        SC_SSC_CTRL &= ~BIT0;
    }
#endif
}

/**************************************************************************//**
 * Disable SSC.
 ******************************************************************************/
void DisableDclkSSC(void)
{
    SC_SSC_CTRL &= ~BIT0;
}

/**************************************************************************//**
 * Set SSC ratio.
 * @param ratio SSC ratio.
 ******************************************************************************/
void SetDclkSSCRatio(UCHAR ratio)
{
#if ENABLE_SCALER_NEW_SSC == ON
    UCHAR tmpratio, tmplevel;

    tmpratio = ratio >>4;
    tmplevel = ratio & 0x0F;;

    if (tmpratio == 0) {
        tmpratio = 15;
    }
    else {
        tmpratio = tmpratio -1;
    }

    if (tmplevel == 0) {
        SC_SSC_FMOD = (USHRT)((32768UL*(PANEL_DCLK_NEW_SSC_RANGE - tmpratio)/1000/63));
    }else{
        SC_SSC_FMOD = (USHRT)((32768UL*(PANEL_DCLK_NEW_SSC_RANGE - tmpratio)/1000/(tmplevel*4))/4*4);
    }
#else
    SC_SSC_CTRL = (SC_SSC_CTRL & 0xE1) | ratio;
#endif
    SC_MPLL_B2C = 0x00;
}

/**************************************************************************//**
 * Set SSC frequency.
 * @param freq SSC frequency.
 ******************************************************************************/
void SetDclkSSCFreq(UCHAR freq)
{
#if ENABLE_SCALER_NEW_SSC == ON
    if ((freq&0x0F) == 0) {
       SC_SSC_FDEV = (SC_SSC_FDEV & ~0x3F) | (63);
    }
    else {
    SC_SSC_FDEV = (SC_SSC_FDEV & ~0x3F) | ((freq&0x0F)*4);
    }
#else
    SC_SSC_CTRL = (SC_SSC_CTRL & 0x1F) | freq;
#endif
    SC_MPLL_B2C = 0x00;
}

/**************************************************************************//**
 * Set both SSC ratio and frequency and turn SSC on.
 * @param value Combinational value of SSC ratio and frequency.
 ******************************************************************************/
void SetDclkSSC(UCHAR value)
{
    SetDclkSSCRatio(value);
    SetDclkSSCFreq(value);

#if ENABLE_SCALER_NEW_SSC == ON
    if (UserPanelData.bEnableSSC) {
        SC_SSC_FDEV |= BIT7;
    }
    else {
        SC_SSC_FDEV &= ~BIT7;
    }
#endif   

    EnableDclkSSC();
}

#if ENABLE_SCALER_NEW_SSC == ON
/**************************************************************************//**
 * Set SSC level for factory setting
 * @param value 16 step : 1~16       
 ******************************************************************************/
 
#if !lrd_dis
void ConfigSSClevel(UCHAR level)
{
    if (level == 16) {
      UserPanelData.ucSpreadSpectrumCtrl = (UserPanelData.ucSpreadSpectrumCtrl & 0xF0);         
    }
    else {
        UserPanelData.ucSpreadSpectrumCtrl = (UserPanelData.ucSpreadSpectrumCtrl & 0xF0) | level;
    }
    
    SetDclkSSC(UserPanelData.ucSpreadSpectrumCtrl);
}

/**************************************************************************//**
 * Set SSC Range for factory setting
 * @param value 16 step : 1~16 (unit 0.1%)
 * SSC Range = Target SSC - (0.1*step)       
 ******************************************************************************/
void ConfigSSCRange(UCHAR Range)
{
    if (Range == 16) {
        UserPanelData.ucSpreadSpectrumCtrl = (UserPanelData.ucSpreadSpectrumCtrl & 0x0F);      
    }
    else {
        UserPanelData.ucSpreadSpectrumCtrl = (UserPanelData.ucSpreadSpectrumCtrl & 0x0F) | Range << 4;
    }
    
    SetDclkSSC(UserPanelData.ucSpreadSpectrumCtrl);
} 
#endif
/**************************************************************************//**
 * Get Target SSC Range.
 * @param value unit 0.01%
 * Ex. 16 -> 1.6 %
 ******************************************************************************/

#if !lrd_dis
UCHAR GetTargetSSCRange(void)
{
    UCHAR ucsscrange = (UserPanelData.ucSpreadSpectrumCtrl >> 4);
    if (ucsscrange == 0) {
        return PANEL_DCLK_NEW_SSC_RANGE - 15;
    }
    else {
        return (PANEL_DCLK_NEW_SSC_RANGE - (ucsscrange-1));
    }
}
/**************************************************************************//**
 * Get New SSC value for definiton ENABLE_SCALER_NEW_SSC 
 ******************************************************************************/
UCHAR GetPanelDclkNewSSC(void)
{
    return UserPanelData.ucSpreadSpectrumCtrl;
}
#endif

/**************************************************************************//**
 * Get Current SSC frequency. 
 * @param value unit 0.1kHz
 * Ex. 468 -> 46.8k Hz
 ******************************************************************************/
#if !lrd_dis
USHRT GetSSCFreq(void)
{
    return (USHRT)(REF_CLK/200/(SC_SSC_FDEV&0x3F)/4); //Unit 0.1kHz;
} 

/**************************************************************************//**
 * Get Current SSC Range.
 * @param value unit 0.01%
 * Ex. 156 -> 1.56 %
 ******************************************************************************/
USHRT GetSSCRange(void)
{    
    return (USHRT)(((ULONG)(SC_SSC_FDEV&0x3F))*SC_SSC_FMOD*10000/32768);//Unit 0.01%;
}
#endif
#endif

/**************************************************************************//**
 * Set FIFO to manual lock mode if input timing is interlaced or vertical scaling down.
 ******************************************************************************/
void CheckFIFO(void)
{
//    UCHAR backup, fifo_v;
    USHRT fifo_h;//, temp, input_vactive;
#if IS_NT68850_SERIES || IS_NT68790_SERIES || IS_NT68658_SERIES || IS_NT68810_SERIES || IS_NT68870_SERIES
    SC_DISPLAY_HLOCK_HI &= 0x0F;
#endif

    if (IsInterlaced()) { //If input is interlaced. FIFO -= half htotal
        if ((GetInputVTotal() > 593) && ((GetVCaptureSize() == 1080) || (GetDigInputVActiveImmediate() == 540))) {            
            // CEA timing 39: 1920x1080i/50Hz
            SC_DISPLAY_VLOCK = 1;
            fifo_h = ReadShortScaler(&SC_DISPLAY_HLOCK_LO) & 0xF000;
            WriteShortScaler(&SC_DISPLAY_HLOCK_LO, fifo_h);
            SC_DISPLAY_CTRL &= ~BIT6;
            SC_DISP_DRIVE_CTRL &= ~BIT7;
        }
        else {
            SC_DISPLAY_CTRL |= BIT6;
            SC_DISP_DRIVE_CTRL |= BIT7;
        }
    }
    else {
#if IS_NT68850_SERIES || IS_NT68790_SERIES || IS_NT68658_SERIES || IS_NT68810_SERIES || IS_NT68870_SERIES
    #if PANEL_WIDTH == 2560 && PANEL_HEIGHT == 1440
        if ((GetHCaptureSize() >= 800) &&(GetVCaptureSize() >= 600)) {// >= 800x600
    #else
        if (!((GetHCaptureSize() == 720) &&(GetVCaptureSize() == 288) && (abs(GetInputVFreq() - 500) < 10))) {// !720x288_50Hz
    #endif
            SC_DISPLAY_HLOCK_HI |= BIT5;
        }
#endif
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1) || (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
        if (SC_FRC_CTRL != 0x00) { // DFR, FRC
            SC_DISPLAY_VLOCK = 1;
            fifo_h = ReadShortScaler(&SC_DISPLAY_HLOCK_LO) & 0xF000;
            WriteShortScaler(&SC_DISPLAY_HLOCK_LO, fifo_h);
            SC_DISPLAY_CTRL &= ~BIT6;
            SC_DISP_DRIVE_CTRL &= ~BIT7;
        }
        else
#endif
        {
            SC_DISPLAY_CTRL |= BIT6;
            SC_DISP_DRIVE_CTRL &= ~BIT7;
        }
    }
#if ENABLE_FREESYNC_DEMO == ON
//    if ((GetCurrInputInterface() == DISPLAY_PORT_INPUT) || (GetCurrInputInterface() == DISPLAY_PORT_INPUT1)) {
    if (bFreeSyncMode == TRUE) {
        VCRModeLockPosition();
    }
#endif
}

#if ENABLE_FREESYNC_DEMO == ON
/**************************************************************************//**
 * Set VCR mode lock position by display window vbeg.
 ******************************************************************************/
void VCRModeLockPosition(void)
{
    USHRT temp, lock_v, lock_h;
    USHRT input_htotal, input_clk;
    USHRT dis_htotal;

#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1) || (INPUT_INTERFACE&INPUT_DP2) || (INPUT_INTERFACE&INPUT_DP3)
    if ((GetCurrInputInterface() == DISPLAY_PORT_INPUT) || (GetCurrInputInterface() == DISPLAY_PORT_INPUT1) || (GetCurrInputInterface() == DISPLAY_PORT_INPUT2) || (GetCurrInputInterface() == DISPLAY_PORT_INPUT3)) {
        input_htotal = GetDigInputHTotalImmediate();
        input_clk = DP_GetClock();
    }
    else 
#endif
    {
        if (GetInputSyncMode() == DIG_SYNC){
            input_htotal = GetDigInputHTotalImmediate();
            input_clk = TMDS_GetClock();
        }
        else{
            input_htotal = InputTiming.usHTotal;
            input_clk = (ULONG)GetInputHFreq() * input_htotal/10000;
        }
    }
  
    dis_htotal = ReadShortScaler(&SC_DH_HTOTAL_LO);

    if ((SC_VCR_CTRL & BIT0) != 0x00) { //enable VCR mode   
        temp = ReadShortScalerHighLowFilter(&SC_DISP_HLOCK_POS_R);
        lock_v = temp >> 13;
        lock_h = temp & 0x1FFF;

        lock_h = (ULONG)(lock_h + lock_v * input_htotal) * (ulDisplayClk / 1000000) / input_clk;
        lock_v = lock_v + (lock_h / dis_htotal) + 1;
        if (lock_v == 1) {
            lock_v++;
        }
        WriteShortScaler(&SC_DV_BG_BEG_LO, lock_v);
        WriteShortScaler(&SC_GRAPHIC_DISP_VER_ACT_BEG_LO, lock_v);
        
        SC_DV_VS_WID = 1; //V begin force to 1
    }
}

void SetFreeSyncMode(void)
{
    bFreeSyncMode = IsFreeSyncMode();
    if (bFreeSyncMode == TRUE) {
        SC_VCR_CTRL = 0x11;
        SC_HR_CTRL = 0x10; 
        SC_SOG_DIGITAL_GLITCH_FILTER_THREESHOLD = 0x12;// only need to disable V change fast mute when free-sync runing
        SC_FIFO_CTRL1 &= ~BIT5; // 0x190
        SC_SYNC_INT_EN1 = 0x1C;
    }
    else {
        SC_VCR_CTRL = 0x10;
        SC_HR_CTRL = 0x00;
        SC_SOG_DIGITAL_GLITCH_FILTER_THREESHOLD = 0x00;
        SC_FIFO_CTRL1 |= BIT5;
        SC_SYNC_INT_EN1 = 0x3C;
    }
}
#endif
