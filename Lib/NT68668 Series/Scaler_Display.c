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
static void CheckInOutClock(USHRT htotal50, USHRT *disp_htotal);
static void CheckInterlacedSignalField(void);
static void SetFixHR2(void);
static void CheckFIFO(void);

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
#if IS_NT68168_SERIES
    if (UserPanelData.bDualPortLVDS == TRUE) {
        SC_DISPLAY_POL_CTRL = (PANEL_DISP_DE_POL << 7) | (0x01 << 6)|(PANEL_DISP_HSYNC_POL << 5)|(PANEL_DISP_VSYNC_POL << 4);
    }
    else {
        SC_DISPLAY_POL_CTRL = (PANEL_DISP_DE_POL << 7) | (0x00 << 6)|(PANEL_DISP_HSYNC_POL << 5)|(PANEL_DISP_VSYNC_POL << 4);
    }
#else
    SC_DISPLAY_POL_CTRL = (PANEL_DISP_DE_POL << 7) | (0x00 << 6)|(PANEL_DISP_HSYNC_POL << 5)|(PANEL_DISP_VSYNC_POL << 4);
#endif
    SC_DISPLAY_CLK_CTRL = 0x40;

    SC_DISPLAY_CHANNEL = BIT6;//(BIT5|BIT6);
    SC_DISP_SWAP = DT16A;

    SC_GRAPHIC_DISP_WIN_CTRL = 0x07;

    SC_HR_CTRL = 0x00;
    SC_RESIDUAL_DISP_HOR_SYNC_CTRL = 0x00;

    SC_FIFO_CTRL1 &= ~BIT6;

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
    UCHAR ch;
    ch = 0x61;

    if (UserPanelData.bBitShift == TRUE) {
        ch |= BIT7;
    }
    else {
        ch &= ~BIT7;
    }
    if (UserPanelData.ucColorDepth == 8) { //If 8-bit LVDS output
        ch &= ~BIT3;
    }
    else {
        ch |= BIT3;
    }
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
    SC_DISPLAY_CTRL = ch;

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
    UCHAR tmpReg;

    tmpReg = SC_MPLL_DIV;
    temp = ((float)ulDisplayClk * 131072) / REF_CLK;
    SC_DDDS_RATIO_LO = (UCHAR) temp;
    SC_DDDS_RATIO_MI = (UCHAR) (temp >> 8);
    SC_DDDS_RATIO_HI = (UCHAR) (temp >> 16);
    SC_MPLL_DIV = tmpReg;
    SetLvdsP2SByDCLK();
}

#if IS_NT68650_SERIES || IS_NT68660_SERIES
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
    xdata float temp;
    BOOL interlace;

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

    if (ulDisplayClk > UserPanelData.ulMaxPClk) {
       disp.clock = UserPanelData.ulMaxPClk;
       DispClkCompress(&input,&disp);
    }

    WriteShortScaler(&SC_DV_BG_LEN_LO, disp.active_height); //Display Background Vertical Length
    WriteShortScaler(&SC_GRAPHIC_DISP_VER_ACT_LEN_LO, disp.active_height); //Display Active Vertical Length

    temp = ((float)disp.htotal-0.1) * disp.active_height * 4096 / ulHFreqCounter / input.active_height;
    ulDisplayClk = (ULONG) (temp * REF_CLK * 16);

    if (interlace == TRUE) {
        SC_VCR_CTRL = 0x10;
        ulDisplayClk <<= 1;
    }
    else {
        SC_VCR_CTRL = 0x00;
    }

    CheckInOutClock(htotal50, &disp.htotal);
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
        SetFixHR2();
    }
    else {
        LoadDefaultPanelData();
        SetFreeRunClk();
    }

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
}

/**************************************************************************//**
 * Check the display clock to avoid abnormal display when in/out clocks are too closed.
 * @param htotal50 Current input htotal.
 * @param[out] disp_htotal Target display htotal when DCLK changed.
 ******************************************************************************/
static void CheckInOutClock(USHRT htotal50, USHRT *disp_htotal)
{
    ULONG input_min_clock, input_max_clock;
    float temp;
    USHRT input_vactive, output_vactive;
    BOOL  bInOutIsClosed = FALSE;
 
    input_vactive = ReadShortScaler(&SC_GI_CAP_VLEN_LO);
    output_vactive = ReadShortScaler(&SC_GRAPHIC_DISP_VER_ACT_LEN_LO);

    if (input_vactive >= output_vactive) {
        //  CONDITION1 :V IS NOT SCALING UP 
        if ((SC_INPUT_SELECT & 0x03) < 2) {   //analog
            temp  = (float)(htotal50 - 50) * 4096 / ulHFreqCounter;
            input_min_clock = (ULONG)(temp * REF_CLK * 16);
            temp  = (float)(htotal50 + 50) * 4096 / ulHFreqCounter;
            input_max_clock = (ULONG)(temp * REF_CLK * 16); 
            temp = (ulDisplayClk+16) >> 5; // suppose SSC_ratio under 1/32

            if (((input_min_clock - temp) < ulDisplayClk) && (ulDisplayClk < (input_max_clock + temp))) {
                bInOutIsClosed = TRUE;
            }
        }
        else { //DVI
            #if ENABLE_HDMI == ON
            input_max_clock = ReadShortScaler(&SC_VIDEO_HTOTAL_LO) & 0x1FFF;
            input_max_clock = input_max_clock * usHSyncFreq * 100;
            #else
            input_max_clock = TMDS_GetClock();
            input_max_clock = input_max_clock * 1000000;
            #endif
            temp = (ulDisplayClk+16) >> 5; // suppose SSC_ratio under 1/32

            if (((input_max_clock - temp) < ulDisplayClk) && ((input_max_clock + temp) > ulDisplayClk)) {
                bInOutIsClosed = TRUE;
            }
        }
    
        if (bInOutIsClosed) {
            // CALCULATE NEW CLOCK
            ulDisplayClk = ((float)input_max_clock*1.0413);    // Single end - 1/32 + 1%
            if (ulDisplayClk > UserPanelData.ulMaxPClk) {
                // OVER MAX PANEL CLOCK, USE (MAX_CLOCK+MAX_CLOCK*1%)
                ulDisplayClk = UserPanelData.ulMaxPClk;
            }

            if (IsInterlaced()) { //If input is interlaced
                temp = (float)(ulDisplayClk >> 1);
            }
            else {
                temp = (float)ulDisplayClk;
            }
            *disp_htotal = temp * ulHFreqCounter * input_vactive / output_vactive / 4096 / REF_CLK / 16;
        }
    }
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
        ((SC_DPLL_CTRL1 & BIT0) == 0)  ||
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
    
        ssc_backup = SC_SSC_CTRL;
        DisableDclkSSC();
//        SC_DISPLAY_MUTE_CTRL = 0x00;
        if ((SC_INPUT_SELECT & 0x03) < 2) {   //analog
            SC_GRAPHIC_DISP_WIN_CTRL = 0x07;
            temp = GetInputVStart();
            SetEvenFieldOffset(0);
            SetVP(5);
            if ((SC_DISPLAY_CTRL & BIT6) == 0x00) {
                WriteShortScaler(&SC_LOCK_H_SHIFT_LO, ReadShortScalerHighLowFilter(&SC_CAP_HTOTAL_LENGTH_LO)/2);
            }
            else {
                WriteShortScaler(&SC_LOCK_H_SHIFT_LO, 0x00);
            }
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
        else {
            SC_GRAPHIC_DISP_WIN_CTRL = 0x07;
            if ((SC_DISPLAY_CTRL & BIT6) == 0x00) {
                if ((GetVCaptureSize() == 1080) && (GetInputVTotal() > 593)) {
                    // CEA timing 39: 1920x1080i/50Hz
                    WriteShortScaler(&SC_LOCK_H_SHIFT_LO, 0x00);
                }
                else {
                    WriteShortScaler(&SC_LOCK_H_SHIFT_LO, ReadShortScalerHighLowFilter(&SC_CAP_HTOTAL_LENGTH_LO)/2);
                }
            }
            else {
                WriteShortScaler(&SC_LOCK_H_SHIFT_LO, 0x00);
            }
            if (abs(ReadShortScalerHighLowFilter(&SC_GI_CAP_VBEGO_LO) - ReadShortScalerHighLowFilter(&SC_GI_CAP_VBEGE_LO)) > 0) {
                if ((SC_GI_SYNC_CTRL3 & BIT0) == 0x00) {
                    SC_GI_SYNC_CTRL3 |= BIT0;
                    temp = ReadShortScaler(&SC_GI_CAP_VBEGE_LO);
                    WriteShortScaler(&SC_GI_CAP_VBEGE_LO, ReadShortScaler(&SC_GI_CAP_VBEGO_LO));
                    WriteShortScaler(&SC_GI_CAP_VBEGO_LO, temp);
                }
            }
            else {
                SC_GI_SYNC_CTRL3 &= ~BIT0;
            }

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
    xdata ULONG vtcnt, vdecnt;
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
                vtcnt += GetVCounter();
            }
            else {
                vtcnt += Read3ByteScalerHighLowFilter(&SC_VER_COUNTER_LO);
//                printf("vtcnt x=%ld\r\n",vtcnt);
            }
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
}

/**************************************************************************//**
 * Setup aspect ratio and enable scaler fast mute function.
 ******************************************************************************/
void NormalDisplay(void)
{
//    SC_DITHER_TP_GRAY_LVL_LO = 0x00;
//    SC_DITHER_TP_GRAY_LVL_HI = 0x00;
    SC_DITHER_TOGGLE_CTRL |= BIT7;
    SC_DISPLAY_CHANNEL = 0xC0;
    SC_DISPLAY_MUTE_CTRL = 0x00;
    SetDisplayMode(ucAspRatioMode);
    SetPostBGColor(0x00, 0x00, 0x00); // Set black color to avoid unexpected color from user-level burn-in mode.
    Sleep(40);
    if ((SC_INPUT_SELECT & 0x03) < 2) { //analog
        WaitHPLLstable();
        HwAutoOffset();
        if ((SC_GI_SYNC_CTRL & 0x03) == 0x01) {
            SC_HPLL_FREQ_CTRL = 0x40; //Disable updating HS_CNT
        }
    }

    // Reduce time to detect overflow when input HSync is varied.
    SetupHSyncOverflowMask(TRUE);
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
    if (UserPanelData.bEnableSSC) {
        SC_SSC_CTRL |= BIT0;
    }
    else {
        SC_SSC_CTRL &= ~BIT0;
    }
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
    SC_SSC_CTRL = (SC_SSC_CTRL & 0xE1) | ratio;
}

/**************************************************************************//**
 * Set SSC frequency.
 * @param freq SSC frequency.
 ******************************************************************************/
void SetDclkSSCFreq(UCHAR freq)
{
    SC_SSC_CTRL = (SC_SSC_CTRL & 0x1F) | freq;
}

/**************************************************************************//**
 * Set both SSC ratio and frequency and turn SSC on.
 * @param value Combinational value of SSC ratio and frequency.
 ******************************************************************************/
void SetDclkSSC(UCHAR value)
{
    SetDclkSSCRatio(value);
    SetDclkSSCFreq(value);
    EnableDclkSSC();
}

/**************************************************************************//**
 * Set FIFO to manual lock mode if input timing is interlaced or vertical scaling down.
 ******************************************************************************/
void CheckFIFO(void)
{
    UCHAR backup, fifo_v;
    USHRT input_vactive, output_vactive, fifo_h, temp;

    input_vactive = ReadShortScaler(&SC_GI_CAP_VLEN_LO);
    if (IsInterlaced()) { //If input is interlaced
        input_vactive >>= 1;
    }
    output_vactive = ReadShortScaler(&SC_GRAPHIC_DISP_VER_ACT_LEN_LO);
    //printf("input_vactive=%d output_vactive=%d\r\n",input_vactive, output_vactive);
#if IS_NT68650_SERIES || IS_NT68660_SERIES
    if (input_vactive > output_vactive) {// new FIFO mode
        SC_FIFO_CTRL1 |= BIT5;
    }
    else {
        SC_FIFO_CTRL1 &= ~BIT5;
    }
#endif

    if ((input_vactive >= output_vactive) ||
        (IsInterlaced()) ||
        ((SC_DISPLAY_CTRL & BIT5) == 0)) {        // CONDITION1 :V IS NOT SCALING UP or input is interlaced
        backup = SC_SSC_CTRL;
        SC_SSC_CTRL &= ~BIT0;
        DelayVTime(4);
        temp = ReadShortScalerHighLowFilter(&SC_DISP_HLOCK_POS_R);
        fifo_v = temp >> 12;
        fifo_h = temp & 0x0FFF;
        temp = ReadShortScalerHighLowFilter(&SC_CAP_HTOTAL_LENGTH_LO);//capture htotal
        fifo_h += temp * fifo_v;
        fifo_h += 0x180;

        if (IsInterlaced()) { //If input is interlaced. FIFO -= half htotal
            if ((GetInputVTotal() > 593) && ((GetVCaptureSize() == 1080) || (GetDigInputVActiveImmediate() == 540))) {                 
                //CEA timing 39: 1920x1080i/50Hz
                fifo_h -= 0x180;
            }
            input_vactive = ReadShortScalerHighLowFilter(&SC_CAP_HTOTAL_LENGTH_LO) / 2;
            fifo_h -= input_vactive;
        }
        fifo_v = fifo_h / temp;
        fifo_h = fifo_h % temp;
#if IS_NT68168_SERIES || IS_NT68668_SERIES || IS_NT68669_SERIES
        // NT68168, NT68668/9, NT68671/2/3/4/5. input=1920x1200, output=1920x1080
        if ((input_vactive == 1200) && (output_vactive == 1080)) {
            input_vactive = ReadShortScaler(&SC_GI_CAP_HWID_LO);
            output_vactive = ReadShortScaler(&SC_GRAPHIC_DISP_HOR_ACT_WID_LO);
            if ((input_vactive == 1920) && (output_vactive == 1920)) {
                fifo_h = 0x100;
            }
        }
#endif
        SC_DISPLAY_VLOCK = fifo_v;
        WriteShortScaler(&SC_DISPLAY_HLOCK_LO, fifo_h);
        SC_SSC_CTRL = backup;
        SC_DISPLAY_CTRL &= ~BIT6;
    }
    else {
        SC_DISPLAY_CTRL |= BIT6;
    }
}
