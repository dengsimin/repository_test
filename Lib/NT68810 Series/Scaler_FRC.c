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

#if ENABLE_POSTFRC == ON || ENABLE_AUTOFRAMEDOWN == ON || ENABLE_DFR == ON || ENABLE_CENTER_MODE == ON
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
#if ENABLE_POSTFRC == ON
/**************************************************************************//**
 * Configure post-FRC setting
 ******************************************************************************/
void FRCConfigPostFRC(USHRT vfreq, bit postpattten)
{
    ULONG clock;
    USHRT fp_h, fp_v, htot, vtot, hact, vact, bp_h, bp_v;
    float ratio;
    
    htot = UserPanelData.usTypHTotal; //ReadShortScaler(&SC_DH_HTOTAL_LO);
    vtot = UserPanelData.usTypVTotal;//ReadShortScaler(&SC_DV_TOTAL_LO);
    hact = UserPanelData.usWidth;//ReadShortScaler(&SC_DH_BG_WID_LO);
    vact = UserPanelData.usHeight;//ReadShortScaler(&SC_DV_BG_LEN_LO);
    bp_h = UserPanelData.usMinHSyncBackPorch + UserPanelData.usMinHSyncWidth; //ReadShortScaler(&SC_DH_BG_BEG_LO);
    bp_v = UserPanelData.usMinVSyncBackPorch + UserPanelData.usMinVSyncWidth; //ReadShortScaler(&SC_DV_BG_BEG_LO);
//    hwid = SC_DH_HS_WID;
//    vwid = SC_DV_VS_WID;
    clock = (float) htot * vtot * vfreq / 10;

    if ((clock > UserPanelData.ulMaxPClk) || (clock < UserPanelData.ulMinPClk)) {
        htot = UserPanelData.usTypHTotal;
        vtot = UserPanelData.usTypVTotal;
        clock = (ULONG)UserPanelData.usTypHTotal * UserPanelData.usTypVTotal * PANEL_FRC_OUTPUT_VSYNC / 10;
    }

    clock = ((float)clock * 131072) / REF_CLK;
    SC_FRC_RATIO_LO = (UCHAR) clock;
    SC_FRC_RATIO_MI = (UCHAR) (clock >> 8);
    SC_FRC_RATIO_HI = (UCHAR) (clock >> 16);

    fp_h = (htot - hact - bp_h) & 0x0fff;//fp_h = ((htot-hact-bp_h-hwid)>>1) & 0x0fff;
    fp_v = (vtot - vact - bp_v) & 0x0fff;//fp_v = ((vtot-vact-bp_v-vwid)>>1) & 0x0fff;
    if (fp_v == 0) {
        fp_v = 1;
    }
    SC_FRC_V_FP = fp_v & 0xff;
    SC_FRC_H_FP = fp_h & 0xff;
    SC_FRC_VH_FP = ((fp_v & 0x0f00) >> 4) | (fp_h >> 8);

    WriteShortScaler(&SC_FRC_OUTPUT_H_ACTIVE_LO, hact);
    WriteShortScaler(&SC_FRC_OUTPUT_H_TOTAL_LO, htot);
    WriteShortScaler(&SC_FRC_OUTPUT_V_ACTIVE_LO, vact);
    WriteShortScaler(&SC_FRC_OUTPUT_V_TOTAL_LO, vtot);

    SC_FRC_POINT1_HI = 0x00;
    SC_FRC_V_POINT1_LO = 0x00;
    SC_FRC_H_POINT1_LO = 0x00;
    SC_FRC_POINT2_HI = 0x00;
    SC_FRC_V_POINT2_LO = 0x00;
    SC_FRC_H_POINT2_LO = 0x00;

    if (postpattten == TRUE) {
        vact = vtot - 5;
        SC_FRC_V_POINT1_LO = (UCHAR) vact;
        SC_FRC_POINT1_HI = (UCHAR)((vact >> 4)&0xF0);
        SC_FRC_V_POINT2_LO = 0x20;
        SC_FRC_CTRL = 0x03;
    }
    else {
        if (GetInputVFreq() < (vfreq - 5)) {//FRC up
            SC_FRC_POINT1_HI = 0xFF;
            SC_FRC_V_POINT1_LO = 0xFF;
            SC_FRC_H_POINT1_LO = 0xFF;
            SC_FRC_CTRL = 0x13;
        }
        else {//FRC down
            vact = vtot - 5;
            SC_FRC_V_POINT1_LO = (UCHAR) vact;
            SC_FRC_POINT1_HI = (UCHAR)((vact >> 4)&0xF0);

            ratio = (float)vfreq / GetInputVFreq();
            vact = (1 - ratio) * vtot + 20;
            SC_FRC_V_POINT2_LO = (UCHAR) vact;
            SC_FRC_POINT2_HI = (UCHAR)((vact >> 4)&0xF0);

            SC_FRC_CTRL = 0x03;//0x13;
        }
    }
}

void DisableFRCConfigPostFRC(void)
{
    SC_FRC_CTRL = 0x00;
    SC_FRC_CLOCK_SEL = 0x00;
}
#endif

#if ENABLE_AUTOFRAMEDOWN == ON
#define MAXSCALERCLOCK 297000000//160000000
/**************************************************************************//**
 * Configure pre-FRC to down convert input frame rate.
 * @param freq Target VSync frequency
 ******************************************************************************/
void FRC_AutoFrameDown(ULONG *Dclk)
{
    ULONG clock;
    USHRT htotal, vtotal, vsync, vlock;
    float ratio;

    vsync = GetInputVFreq();
    if ((vsync < 620) && (*Dclk < MAXSCALERCLOCK)) {
        SC_PREFRC_CONTROL = 0x00;//&= ~BIT0;
        return;
    }
    SC_PREFRC_CONTROL = 0x41;
    Sleep(40);
    WaitDisVSync();
    htotal = ReadShortScaler(&SC_PREFRC_OUTPUT_H_TOTAL_LO);
//    printf("htotal =%d\r\n",(USHRT)htotal);
    if (vsync > 600) {//vsunc > 60 Hz
        ratio = (float)vsync / 600;
    }
    else {// over MAXSCALERCLOCK
        ratio = (float)*Dclk / MAXSCALERCLOCK;
    }
//    printf("ratio =%f\r\n",ratio)	;
    htotal = (USHRT) ((float)htotal * ratio) ;
    vtotal = GetInputVTotal();

    WriteShortScaler(&SC_PREFRC_OUTPUT_H_TOTAL_LO, htotal);
    WriteShortScaler(&SC_PREFRC_OUTPUT_V_TOTAL_LO, vtotal);

    WriteShortScaler(&SC_PREFRC_OUTPUT_H_ACTIVE_LO, ReadShortScaler(&SC_GI_CAP_HWID_LO));
    WriteShortScaler(&SC_PREFRC_OUTPUT_V_ACTIVE_LO, ReadShortScaler(&SC_GI_CAP_VLEN_LO));

//    printf("rehtotal =%x\r\n",(USHRT)htotal);
//    printf("rehactive =%x\r\n",(USHRT)ReadShortScaler(&SC_PREFRC_OUTPUT_H_ACTIVE_LO));


    if (vsync > 600) {//vsunc > 60 Hz
        clock = *Dclk;
        *Dclk = (ULONG)(clock / ratio);
    }
    else {// over MAXSCALERCLOCK
        *Dclk = MAXSCALERCLOCK;
    }
    SC_PREFRC_CONTROL = 0x03;

    // H/V lower bound
    vlock = vtotal - 5;//2;
    SC_PREFRC_53A = ((vlock & 0x0F00) >> 4);
    SC_PREFRC_53B = vlock & 0xFF;
    SC_PREFRC_53C = 0x00;
//    printf("vtotal =%d\r\n",vtotal);
//    printf("vlock low =%d\r\n",vlock);

    ratio = (float)1 / ratio;
    ratio = (float)1 - ratio;

    // H/V upper bound
    vlock = (float)vtotal * ratio + 20;
    SC_PREFRC_53D = ((vlock & 0x0F00) >> 4);
    SC_PREFRC_53E = vlock & 0xFF;
    SC_PREFRC_53F = 0x00;
//    printf("vlock high =%d\r\n",vlock);

    Sleep(100);
    SC_DRAM_INTERFACE_LO &= ~BIT0;
    SC_DRAM_INTERFACE_LO |= BIT0;
    Sleep(100);
}

void DisableFRC_AutoFrameDown(void)
{
    SC_PREFRC_CONTROL = 0x00;
}
#endif

#if ENABLE_DFR == ON
void FRCConfigDFR(void)
{
//    ULONG clock;
    USHRT fp_h, fp_v, htot, vtot, hact, vact, bp_h, bp_v;
    UCHAR Reg0x154;
    
    vtot = GetInputVFreq();
    if ((vtot > 450) || (vtot < 200)) {
        return;
    }

    htot = ReadShortScaler(&SC_DH_HTOTAL_LO)+1;//UserPanelData.usTypHTotal; //ReadShortScaler(&SC_DH_HTOTAL_LO);
    vtot = ReadShortScaler(&SC_DV_TOTAL_LO);//UserPanelData.usTypVTotal;//ReadShortScaler(&SC_DV_TOTAL_LO);
    hact = UserPanelData.usWidth;//ReadShortScaler(&SC_DH_BG_WID_LO);
    vact = UserPanelData.usHeight;//ReadShortScaler(&SC_DV_BG_LEN_LO);
    bp_h = UserPanelData.usMinHSyncBackPorch + UserPanelData.usMinHSyncWidth; //ReadShortScaler(&SC_DH_BG_BEG_LO);
    bp_v = UserPanelData.usMinVSyncBackPorch + UserPanelData.usMinVSyncWidth; //ReadShortScaler(&SC_DV_BG_BEG_LO);
/*
    clock = ((float)*Dclk * 131072) / REF_CLK;
    SC_DDDS_RATIO_LO = (UCHAR) clock;
    SC_DDDS_RATIO_MI = (UCHAR) (clock >> 8);
    SC_DDDS_RATIO_HI = (UCHAR) (clock >> 16);
    */
/*
    fp_h = (htot - hact - bp_h) & 0x0fff;//fp_h = ((htot-hact-bp_h-hwid)>>1) & 0x0fff;
    fp_v = (vtot - vact - bp_v) & 0x0fff;//fp_v = ((vtot-vact-bp_v-vwid)>>1) & 0x0fff;
    if (fp_v == 0) {
        fp_v = 1;
    }
    SC_FRC_V_FP = fp_v & 0xff;
    SC_FRC_H_FP = fp_h & 0xff;
    SC_FRC_VH_FP = ((fp_v & 0x0f00) >> 4) | (fp_h >> 8);
*/
    WriteShortScaler(&SC_FRC_OUTPUT_H_ACTIVE_LO, UserPanelData.usWidth);
    WriteShortScaler(&SC_FRC_OUTPUT_H_TOTAL_LO, ReadShortScaler(&SC_DH_HTOTAL_LO));
    WriteShortScaler(&SC_FRC_OUTPUT_V_ACTIVE_LO, UserPanelData.usHeight);
    WriteShortScaler(&SC_FRC_OUTPUT_V_TOTAL_LO, ReadShortScaler(&SC_DV_TOTAL_LO));

    SC_FRC_CLOCK_SEL = 0x01;
    
    SC_FRC_POINT1_HI = 0x00;
    SC_FRC_H_POINT1_LO = 0x00;
    SC_FRC_POINT2_HI = 0x00;
    SC_FRC_H_POINT2_LO = 0x00;

    vtot = UserPanelData.usHeight / 2 + 16;
    SC_FRC_V_POINT1_LO = (UCHAR) vtot;
    SC_FRC_POINT1_HI = (UCHAR)((vtot >> 4)&0xF0);
    
    Reg0x154 = SC_DISPLAY_MUTE_CTRL;
    SC_DISPLAY_MUTE_CTRL = 0x00;
    SC_FRC_CTRL = 0x41;
    Sleep(120);
    vtot = ReadShortScaler(&SC_FRC_OUTPUT_V_TOTAL_LO);
    SC_FRC_CTRL = 0x43;
    WriteShortScaler(&SC_FRC_OUTPUT_V_TOTAL_LO, vtot);
    
    fp_h = (htot - hact - bp_h) & 0x0fff;//fp_h = ((htot-hact-bp_h-hwid)>>1) & 0x0fff;
    fp_v = (vtot - vact - bp_v) & 0x0fff;//fp_v = ((vtot-vact-bp_v-vwid)>>1) & 0x0fff;
    if (fp_v == 0) {
        fp_v = 1;
    }
    SC_FRC_V_FP = fp_v & 0xff;
    SC_FRC_H_FP = fp_h & 0xff;
    SC_FRC_VH_FP = ((fp_v & 0x0f00) >> 4) | (fp_h >> 8);

    SC_DISPLAY_MUTE_CTRL = Reg0x154;
}
void DisableFRCConfigDFR(void)
{
    SC_FRC_CTRL = 0x00;
    SC_FRC_CLOCK_SEL = 0x00;
}
#endif


#if ENABLE_CENTER_MODE == ON
void SetCenterMode(void)
{
    ULONG clock;
    USHRT fp_h, fp_v, htot, vtot, hact, vact, bp_h, bp_v, i;
    float ratio;
    UCHAR Reg0x154;
    
    if ((SC_FRC_CTRL != 0x00) || (SC_PREFRC_CONTROL != 0x00)) {
        return;
    }
    htot = ReadShortScaler(&SC_DSP_HTOTAL_LO)+1;//UserPanelData.usTypHTotal; //ReadShortScaler(&SC_DH_HTOTAL_LO);
    vtot = ReadShortScaler(&SC_DV_TOTAL_LO);//UserPanelData.usTypVTotal;//ReadShortScaler(&SC_DV_TOTAL_LO);
    hact = UserPanelData.usWidth;//ReadShortScaler(&SC_DH_BG_WID_LO);
    vact = UserPanelData.usHeight;//ReadShortScaler(&SC_DV_BG_LEN_LO);
    bp_h = UserPanelData.usMinHSyncBackPorch + UserPanelData.usMinHSyncWidth; //ReadShortScaler(&SC_DH_BG_BEG_LO);
    bp_v = UserPanelData.usMinVSyncBackPorch + UserPanelData.usMinVSyncWidth; //ReadShortScaler(&SC_DV_BG_BEG_LO);
//    hwid = SC_DH_HS_WID;
//    vwid = SC_DV_VS_WID;
    
    fp_v = GetInputVFreq();
//    clock = (ULONG)UserPanelData.usTypHTotal * UserPanelData.usTypVTotal * fp_v / 10;
    clock = (ULONG)htot * vtot * fp_v / 10;

    clock = ((float)clock * 131072) / REF_CLK;
    SC_FRC_RATIO_LO = (UCHAR) clock;
    SC_FRC_RATIO_MI = (UCHAR) (clock >> 8);
    SC_FRC_RATIO_HI = (UCHAR) (clock >> 16);

    /*
    fp_h = 0x08;//(htot - hact) / 3;//(htot - hact - bp_h) & 0x0fff;//fp_h = ((htot-hact-bp_h-hwid)>>1) & 0x0fff;
    fp_v = (vtot - vact - bp_v) & 0x0fff;//fp_v = ((vtot-vact-bp_v-vwid)>>1) & 0x0fff;
    if (fp_v == 0) {
        fp_v = 1;
    }
    SC_FRC_V_FP = fp_v & 0xff;
    SC_FRC_H_FP = fp_h & 0xff;
    SC_FRC_VH_FP = ((fp_v & 0x0f00) >> 4) | (fp_h >> 8);
*/
    WriteShortScaler(&SC_FRC_OUTPUT_H_ACTIVE_LO, hact);
    WriteShortScaler(&SC_FRC_OUTPUT_H_TOTAL_LO, htot);
    WriteShortScaler(&SC_FRC_OUTPUT_V_ACTIVE_LO, vact);
    WriteShortScaler(&SC_FRC_OUTPUT_V_TOTAL_LO, vtot);

    SC_FRC_POINT1_HI = 0x00;
    SC_FRC_V_POINT1_LO = 0x00;
    SC_FRC_H_POINT1_LO = 0x00;
    SC_FRC_POINT2_HI = 0x00;
    SC_FRC_V_POINT2_LO = 0x00;
    SC_FRC_H_POINT2_LO = 0x00;

    Reg0x154 = SC_DISPLAY_MUTE_CTRL;
    SC_DISPLAY_MUTE_CTRL = 0x00;
    SC_FRC_CTRL = 0x41;
    Sleep(120);
    vtot = ReadShortScaler(&SC_FRC_OUTPUT_V_TOTAL_LO);
    SC_FRC_CTRL = 0x43;
    WriteShortScaler(&SC_FRC_OUTPUT_V_TOTAL_LO, vtot);
    
    fp_h = 0x08;//(htot - hact) / 3;//(htot - hact - bp_h) & 0x0fff;//fp_h = ((htot-hact-bp_h-hwid)>>1) & 0x0fff;
    fp_v = (vtot - vact - bp_v) & 0x0fff;//fp_v = ((vtot-vact-bp_v-vwid)>>1) & 0x0fff;
    if (fp_v == 0) {
        fp_v = 1;
    }
    SC_FRC_V_FP = fp_v & 0xff;
    SC_FRC_H_FP = fp_h & 0xff;
    SC_FRC_VH_FP = ((fp_v & 0x0f00) >> 4) | (fp_h >> 8);

    SC_DISPLAY_MUTE_CTRL = Reg0x154;

    SC_FRC_CTRL = 0x43;
    SC_FRC_CENTER_MODE = 0x80;
    
    WaitDisVSync();
    GraphicDisplayWindowDisable();
    hact = ReadShortScaler(&SC_GI_CAP_HWID_LO);
    vact = ReadShortScaler(&SC_GI_CAP_VLEN_LO);
    WriteShortScaler(&SC_DH_BG_WID_LO, hact);
    WriteShortScaler(&SC_GRAPHIC_DISP_HOR_ACT_WID_LO, hact);
    WriteShortScaler(&SC_DV_BG_LEN_LO, vact);
    WriteShortScaler(&SC_GRAPHIC_DISP_VER_ACT_LEN_LO, vact);
    fp_h = (UserPanelData.usWidth - hact) / 2;
    WriteShortScaler(&SC_FRC_CENTER_H_START_LO, fp_h);
    fp_v = (UserPanelData.usHeight - vact) / 2;
    WriteShortScaler(&SC_FRC_CENTER_V_START_LO, fp_v);
    
    ratio = ((float)fp_v / UserPanelData.usHeight) * (UserPanelData.usHeight / 4);
    ratio = (UserPanelData.usHeight / 4) - ratio + 2;
    i = (USHRT)ratio;
    SC_FRC_V_POINT1_LO = (UCHAR) i;
    SC_FRC_POINT1_HI = (UCHAR)((i >> 4)&0xF0);

    ratio = (float)vact / UserPanelData.usHeight;
    clock = clock * ratio;
    SC_DDDS_RATIO_LO = (UCHAR) clock;
    SC_DDDS_RATIO_MI = (UCHAR) (clock >> 8);
    SC_DDDS_RATIO_HI = (UCHAR) (clock >> 16);

    Sleep(80);
    WaitDisVSync();
    GraphicDisplayWindowEnable();
    
    
}

void DisableCenterMode(void)
{
    SC_FRC_CTRL = 0x00;
    SC_FRC_CENTER_MODE = 0x00;
}
#endif

#endif //ENABLE_PREFRC == ON || ENABLE_DFR == ON || ENABLE_POSTFRC == ON
#if IS_NT68870_SERIES 
/**************************************************************************//**
 * Determine FRC is enabled or not.
 * @return TRUE if FRC enabled else FALSE.
 ******************************************************************************/
BOOL FRCIsFRCEnabled(void)
{
    if ((SC_FRC_CTRL & BIT0) == BIT0) {
        return TRUE;
    }
    if ((SC_PREFRC_CONTROL & BIT0) == BIT0) {
        return TRUE;
    }
    return FALSE;
}
#endif
