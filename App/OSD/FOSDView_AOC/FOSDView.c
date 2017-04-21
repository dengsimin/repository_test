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
#include "OSDFont.h"
#include "OSDView.h"

//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************
typedef struct _LIGHTBAR_ {
    UCHAR x;
    UCHAR y;
    UCHAR len;
} LightBar ;

//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************
//#define SCALER_UFG_TEXT ("NT68660UFG")
UCHAR ucFOSDType = FOSDOff;
static code UCHAR ucModelText[]={sizeof(Model_TEXT)-1,Model_TEXT};
static code UCHAR ucScalerlText[]={sizeof(SCALER_TEXT)-1,SCALER_TEXT};

#if ENABLE_IIYAMA_OSD_Version == ON
static code UCHAR ucVersionText[]={16,'V',VERSION+'0','.',(REVERSION/10)+'0',(REVERSION%10)+'0',' ',DATE};
#else
static code UCHAR ucVersionText[]={13,'V',VERSION+'0',(REVERSION/10)+'0',(REVERSION%10)+'0',' ',DATE};
#endif
static code UCHAR ucAutoLevelText[]={10,"Auto Level"};
static code UCHAR ucBrightnessText[]= {3,"BRI"};
static code UCHAR ucContrastText[]= {3,"CON"};
static code UCHAR ucGainText[]={4,"Gain"};
static code UCHAR ucOffsetText[]={6,"Offset"};
static code UCHAR ucSRGBText[]={4,"sRGB"};
static code UCHAR ucUSERText[]={4,"User"};
static code UCHAR ucNormalText[]={4,"6500"};
static code UCHAR ucColor5800Text[]={4,"5800"};
static code UCHAR ucColor9300Text[]={4,"9300"};
static code UCHAR ucReturnText[] = {6,"Return"};
//static code UCHAR ucH_Text[]={1,"H"};
static code UCHAR ucR_Text[]={1,"R"};
static code UCHAR ucG_Text[]={1,"G"};
static code UCHAR ucB_Text[]={1,"B"};
//static code UCHAR ucSymbol1[]={1,"="};
static code UCHAR ucYesText[]={3,"YES"};
static code UCHAR ucNoText[]={2,"NO"};
static code UCHAR ucOkText[]={2,"OK"};
static code UCHAR ucBurnInText[]={7,"Burn In"};
static code UCHAR ucIOTText[]={9,"BL Timer:"};
//static code UCHAR ucPOTText[]={6,"Timer:"};
static code UCHAR ucDFMText[]={4,"DFM:"};
static code UCHAR ucPanelText[]={sizeof(PANEL_NAME)-1,PANEL_NAME};
static code UCHAR ucON_Text[]={2,"ON"};
static code UCHAR ucOFF_Text[]={3,"OFF"};
#if VCOM_IIC == ON
static code UCHAR ucVCOM_Text[]={4,"VCOM"};
#endif
#if ENABLE_OD
static code UCHAR ucOD_Text[]={2,"OD"};
#endif
#if TPV_SET_SSC_CTRL == ON
static xdata UCHAR ucSSCSpan;
static xdata UCHAR ucSSCStep;
static code UCHAR ucSSC_Text[]={3,"SSC"};
#if ENABLE_SCALER_NEW_SSC == ON
static code UCHAR ucSSCRatio_Text[]={5,"Level"};
static code UCHAR ucSSCFreq_Text[]={6,"Target"};
#else
static code UCHAR ucSSCRatio_Text[]={5,"Ratio"};
static code UCHAR ucSSCFreq_Text[]={4,"Freq"};
#endif
static code UCHAR ucPercentText[]={1,0x7f};
static code UCHAR ucPlusMinusText[]={1,0x98};
static code UCHAR ucDotText[]={1,0x2e};
#endif
#if TPV_SET_LVDS_SWING == ON
static code UCHAR ucLVDSSwing_Text[]={10,"LVDS Swing"};
#endif
#if PANEL_CONTROL == ON
static code UCHAR ucPanel_SettingText[]={13, "PANEL SETTING"};
#endif
#if ENABLE_HDMI == ON
static code UCHAR ucHDMI_PRETEST_Text[]={13,"Manual Source"}; 
#endif
#if TPV_CLEAR_EE == ON
static code UCHAR ucClearEE_Text[]={8,"Clear EE"};
#endif
#if TPV_EDID_WP_ONOFF == ON
static code UCHAR ucEDIDWP_Text[]={7,"EDID WP"};
#endif
#if TPV_CLEAR_TIMER == ON
static code UCHAR ucClearTimer_Text[]={11,"Clear Timer"};
#endif
#if ENABLE_ECO_EYE_SENSOR == ON
static code UCHAR ucALS_Text[]={3,"ALS"};
static code UCHAR ucPXS_Text[]={3,"PXS"};
#endif
#if FOSD_ENE_RAW_CNT_DEBUG == ON    //20130715_1006_OSD#1
static code UCHAR ucMaxText[]= {3,"MAX"};
static code UCHAR ucSensiText[]= {5,"SENSI"};
static code UCHAR ucEnEDebugText[] = {8,"EnEDebug"};
extern USHRT usEnEMaxSignal[6];
extern USHRT usEnESignal[6];
extern USHRT usENEdelta[6];
#endif

code LightBar LBar[] = {

    {1, 2,8},//mfAUTO
    {8,3,1},{12,3,1},{16,3,1},//Gain RGB
    {8,4,1},{12,4,1},{16,4,1},//Offset RGB

    {8,6,1},{12,6,1},{16,6,1},//Warm

    {8,7,1},{12,7,1},{16,7,1},//Cool

    {8,8,1},{12,8,1},{16,8,1},//User

    {8,9,1},{12,9,1},{16,9,1},//sRGB

    {8,10,1},{12,10,1},{16,10,1},//Normal
    
    {6,11,3},        {14,11,3},//Bri/Con
    
#if PANEL_CONTROL == ON
    {1,12,11},
#endif
    {1,14,8},//DFM
    {1,15,8},//BurnIn
#if VCOM_IIC == ON
    {14,15,4},//mfVCOM
#endif
#if ENABLE_HDMI == ON
    {1,16,12},
#endif
#if ENABLE_OD
    {14,17,5},//mfOD//v31_110830_1420_OSD#5
#endif
#if TPV_SET_SSC_CTRL == ON
#if ENABLE_SCALER_NEW_SSC == ON //show target ratio
    {2,19,5},//mfSSC_FREQ
#else
    {2,19,4},//mfSSC_FREQ
#endif
    {2,20,4},//mfSSC_RATIO
#endif
#if TPV_SET_LVDS_SWING == ON
    {1,21,8},//mfLVDS_SETTING
#endif
#if TPV_CLEAR_EE == ON
    {1,22,12},//mfCLEAR_EE
#endif
#if TPV_EDID_WP_ONOFF == ON
    {1,23,12},//mfEDID_WP
#endif
#if TPV_CLEAR_TIMER == ON
    {1,24,11},//mfClear_TIMING
#endif
    {1,OSD_FACTORY_H-1,11},//mfRETURN
};

//static xdata UCHAR ucUpdateFlag;
xdata UCHAR ucFactoryIndex;
static xdata USHRT usRegAddr;
static xdata UCHAR ucRegValue;
#define FACTORY_FRAME_COLOR   (((I_WHITE-1)<<8)|(14<<4))
#define FACTORY_ITEM_COLOR    (((15-1)<<8)|(14<<4))

//******************************************************************************
// E X T E R N A L   V A R I A B L E   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// S T A T I C   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
static void FactorySelect(void);
static void FactoryUnSelect(void);
static void FactorySelectValue(void);
static void FactoryUnSelectValue(void);
static void FactoryShowValue(UCHAR index, USHRT value);
static void FactoryShowBurnin(void);
#if ENABLE_HDMI == ON
static void FactoryShowHDMI_PRETEST(void);
#endif
#if TPV_CLEAR_EE == ON
static void FactoryShowClaer_EE(void);
#endif
#if TPV_EDID_WP_ONOFF == ON
static void FactoryShowEDIDWP_ONOFF(void);
#endif
#if TPV_CLEAR_TIMER == ON
static void FactoryShowClaer_Timer(void);
#endif

static void FactoryShowAutoColor(UCHAR result);
static void FactoryValueUp(UCHAR *val);
static void FactoryValueDown(UCHAR *val);
static void FactorySetValue(void);
static USHRT GetDepthValue( void );
static void ShowDFM(void);
#if ENABLE_OD
static void FactoryShowOD(void);
#endif
#if TPV_SET_SSC_CTRL == ON
static void FactoryShowSSCSpan(void);
static void FactoryShowSSCStep(void);
static void FactoryShowSSCFreq(void);
static void FactoryShowSSCValue(void);
#endif
#if TPV_SET_LVDS_SWING == ON
static void FactoryShowLVDSSwing(void);
#endif
//static void FactoryShowPOT(void);
//static void FactoryShowIOT(void);

//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************


static void FOSDShowNum(UCHAR x, UCHAR y, USHRT value)
{
    UCHAR i;
    UCHAR buff[4];
    sprintf(buff,"%3d",(USHRT)value);
    for (i=0; i<3; i++) {
        if (buff[i] == 0x20)
            buff[i] = 0;
        else
            buff[i] = buff[i] - 0x2F;//0x28
    }
    OSDAPI_WriteXYString(FALSE, x, y, 3, buff);
      
}

#if TPV_SET_SSC_CTRL == ON
static void FOSDShow1bitNum(UCHAR x, UCHAR y, USHRT value)
{
    UCHAR i;
    UCHAR buff[4];
    sprintf(buff,"%3d",(USHRT)value);
    for (i=0; i<3; i++) {
        if (buff[i] == 0x20)
            buff[i] = 0;
        else
            buff[i] = buff[i] - 0x2F;//0x28
    }
    OSDAPI_WriteXYString(FALSE, x, y, 3, buff);
      
}
#endif

//******************************************************************************
// Prototype: 
//  void OSDShowNum(UCHAR x, UCHAR y, UCHAR value)
// Parameters:
//  x       : x position
//  y       : y position
//  value   : value to be show
// Return:
//  None
// Purpose:
//  Show number on the specific position x,y
// Notes:
//  None
//******************************************************************************
void FactoryOSDShowNum(UCHAR x, UCHAR y, USHRT value)
{
    UCHAR i;
    UCHAR buff[6];
    sprintf(buff,"%5ld",(ULONG)value);

    for (i=0; i<5; i++) {
        if (buff[i] == 0x20)
            buff[i] = 0; //Space
        else
            buff[i] = buff[i] - 0x2F; //ASCII -> 1Bit Table index
    }
    
    OSDAPI_WriteXYString(FALSE, x, y, 5, buff);
}


static void AOC_LoadFactoryOneBitFont()
{
code UCHAR ucFactoryOneBitFontData[] = {
    //[1-Bit:   0]
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

#if 0
    //[1-Bit:   1]
    0x03, 0x20, 0x00, 0x02, 0x20, 0x00, 0x02, 0x20, 0x00, 0x02, 0x20, 0x00, 0x02, 0x20, 0x00, 0x02, 0x20, 0x00, 0x02, 0x20, 0x00, 0x02, 0x20, 0x00, 0x02, 0x30, 0x00, 
    //[1-Bit:   2]
    0xFF, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF, 
    //[1-Bit:   3]
    0xFF, 0x0F, 0x00, 0x00, 0x0E, 0xE0, 0x00, 0x0E, 0xE0, 0x00, 0x0E, 0xE0, 0x00, 0x0E, 0xE0, 0x00, 0x0E, 0xE0, 0x00, 0x0E, 0xE0, 0x00, 0x0E, 0xE0, 0x00, 0xF0, 0xFF, 
    //[1-Bit:   4]
    0xFF, 0x0F, 0x00, 0xC0, 0x0F, 0xFC, 0xC0, 0x0F, 0xFC, 0xC0, 0x0F, 0xFC, 0xC0, 0x0F, 0xFC, 0xC0, 0x0F, 0xFC, 0xC0, 0x0F, 0xFC, 0xC0, 0x0F, 0xFC, 0x00, 0xF0, 0xFF, 
    //[1-Bit:   5]
    0xFF, 0x0F, 0x00, 0xF8, 0x8F, 0xFF, 0xF8, 0x8F, 0xFF, 0xF8, 0x8F, 0xFF, 0xF8, 0x8F, 0xFF, 0xF8, 0x8F, 0xFF, 0xF8, 0x8F, 0xFF, 0xF8, 0x8F, 0xFF, 0x00, 0xF0, 0xFF, 
    //[1-Bit:   6]
    0xFF, 0x0F, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xF0, 0xFF, 
    //[1-Bit:   7]
    0x00, 0x0C, 0x40, 0x00, 0x04, 0x40, 0x00, 0x04, 0x40, 0x00, 0x04, 0x40, 0x00, 0x04, 0x40, 0x00, 0x04, 0x40, 0x00, 0x04, 0x40, 0x00, 0x04, 0x40, 0x00, 0x04, 0xC0, 
#endif
 //0~9
0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x80,0x19,0x98,0x81,0x19,0x98,0x81,0x19,0x98,0x81,0x19,0x98,0x01,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x0E,0xE0,0x01,0x16,0x60,0x00,0x06,0x60,0x00,0x06,0x60,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x80,0x19,0x18,0x80,0x01,0x30,0x00,0x07,0x60,0x00,0x0C,0x80,0x81,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x80,0x19,0x18,0x80,0x01,0x70,0x80,0x01,0x18,0x80,0x01,0x98,0x01,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x07,0x70,0x00,0x0B,0xB0,0x00,0x0B,0x30,0x81,0x1F,0x30,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x00,0x0C,0x80,0x01,0x1F,0x98,0x81,0x01,0x18,0x80,0x01,0x98,0x01,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x80,0x09,0x80,0x01,0x18,0xF0,0x81,0x19,0x98,0x81,0x19,0x98,0x01,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x81,0x01,0x30,0x00,0x03,0x60,0x00,0x06,0x60,0x00,0x0C,0xC0,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x80,0x19,0x98,0x81,0x19,0xF0,0x80,0x19,0x98,0x81,0x19,0x98,0x01,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x80,0x19,0x98,0x81,0x19,0x98,0x81,0x0F,0x18,0x80,0x01,0x90,0x01,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,

};

code OSDFontTable ucFactoryOneBitFontTable = {
    sizeof(ucFactoryOneBitFontData),
    OSD_FONTBITS_1b,
    0x00,
    ucFactoryOneBitFontData
};


    WaitDisVSync();
    ResetWDTimer();
    OSDAPI_LoadFont(OSD_FONT_NORMAL, &ucFactoryOneBitFontTable);
    ResetWDTimer();
}

void FOSDInit(void)
{
    OSDAPI_TurnOffOSD();
    OSDAPI_SetFontSize(OSD_FONT_12X18);
    OSDAPI_SetOSDWinSizeUnit(12,18);
    OSDLoadFont(LoadFOSDPalette);
#if PANEL_CONTROL == ON
    OSDAPI_Set1BitFontAddr(OSDAPI_GetOSDFrameSize(OSD_PanelSetting_W, OSD_FACTORY_H));
    AOC_LoadFactoryOneBitFont();
    FOSDInitFrame(OSD_PanelSetting_W,OSD_FACTORY_H,FACTORY_FRAME_COLOR);
#else
    OSDAPI_Set1BitFontAddr(OSDAPI_GetOSDFrameSize(OSD_FACTORY_W, OSD_FACTORY_H));
    AOC_LoadFactoryOneBitFont();
    FOSDInitFrame(OSD_FACTORY_W,OSD_FACTORY_H,FACTORY_FRAME_COLOR);
#endif
    //AOC_H_Split(0,0,FALSE);
}

void FOSDInitFrame(UCHAR osdw, UCHAR osdh, USHRT clr)
{
    OSDAPI_TurnOffOSD();
    OSDAPI_OSDWinOff(OSD_WIN_OFF);
    OSDAPI_SetOSDWidth(osdw);
    OSDAPI_SetOSDHeight(osdh);
    OSDAPI_SetPosition(1,98);
    OSDAPI_SetFontAttr(clr);
    WaitDisVSync();//Sleep(20);  // For ensuring OSD W&H are taking effect before fast clear
            // Jude 2009/02/04
    OSDAPI_ClearOSD();
}

//******************************************************************************
// Prototype:
//  void OSDShowFactory(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Show Factory OSD
// Notes:
//  None
//******************************************************************************
#if FOSD_ENE_RAW_CNT_DEBUG == ON
void OSDShowFactory(void)
{
    UCHAR i;

    ucFOSDType = FOSDPage1;
    FOSDInit();
    Custom_System.bFOSDFM = GetProductModeFlag();
    SystemData.bClear_Timer = FALSE;
    OSDAPI_SetIndentIndex(12);//32 to 38 for ID2008
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);


        ShowIndentString(FALSE, 0,0,ucMaxText[0],ucMaxText);
        ShowIndentString(FALSE, 0,8,ucSensiText[0],ucSensiText);

    for (i=0;i<6;i++) {
        FactoryOSDShowNum(0,i+1,usEnEMaxSignal[i]);
    }
    for (i=0;i<6;i++) {
        FactoryOSDShowNum(0,i+9,usEnESignal[i]);
    }


    OSDTurnOnOSD();
}

#else
void OSDShowFactory(void)
{
    UCHAR i;

    ucFOSDType = FOSDPage1;
    FOSDInit();
    Custom_System.bFOSDFM = GetProductModeFlag();
	SystemData.bClear_Timer = FALSE;
    OSDAPI_SetIndentIndex(12);//32 to 38 for ID2008
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);

    ShowIndentString(FALSE, 1, 0,ucModelText[0],ucModelText);
    ShowIndentString(FALSE, 15, 0,ucScalerlText[0],ucScalerlText);
    ShowIndentString(FALSE, 1, 1,ucVersionText[0],ucVersionText);
    ShowIndentString(FALSE, LBar[mfAUTO].x, LBar[mfAUTO].y,1,ucAutoLevelText);
    ShowIndentString(FALSE, LBar[mfBURNING].x, LBar[mfBURNING].y,1,ucBurnInText);
    ShowIndentString(FALSE, 1, 3,ucGainText[0],ucGainText);
    ShowIndentString(FALSE, 1, 4,ucOffsetText[0],ucOffsetText);
    ShowIndentString(FALSE, 1, 6,ucColor5800Text[0],ucColor5800Text);
    ShowIndentString(FALSE, 1, 7,ucColor9300Text[0],ucColor9300Text);
    ShowIndentString(FALSE, 1, 8,ucUSERText[0],ucUSERText);
    ShowIndentString(FALSE, 1, 9,ucSRGBText[0],ucSRGBText);
    ShowIndentString(FALSE, 1, 10,ucNormalText[0],ucNormalText);
    ShowIndentString(FALSE, 6, 11,ucBrightnessText[0],ucBrightnessText);
    ShowIndentString(FALSE, 14, 11,ucContrastText[0],ucContrastText);
#if PANEL_CONTROL == ON 
    ShowIndentString(FALSE, LBar[mfPANEL_SETTING].x, LBar[mfPANEL_SETTING].y,1,ucPanel_SettingText);
#endif
    ShowIndentString(FALSE, 1, 13,ucPanelText[0],ucPanelText);
    ShowIndentString(FALSE, 1, 14,ucDFMText[0],ucDFMText);
    ShowIndentString(FALSE, LBar[mfBURNING].x, LBar[mfBURNING].y,1,ucBurnInText);
#if ENABLE_HDMI == ON
    ShowIndentString(FALSE, LBar[mfHDMI_PRETEST].x, LBar[mfHDMI_PRETEST].y,ucHDMI_PRETEST_Text[0],ucHDMI_PRETEST_Text);
#endif
    ShowIndentString(FALSE, LBar[mfRETURN].x, LBar[mfRETURN].y,1,ucReturnText);
    ShowIndentString(FALSE, 1, 17, ucIOTText[0], ucIOTText);
#if 0//ENABLE_OD
    ShowIndentString(FALSE, LBar[mfOD].x,LBar[mfOD].y,ucOD_Text[0],ucOD_Text);
#endif
#if TPV_SET_SSC_CTRL == ON
#if ENABLE_SCALER_NEW_SSC == ON
    ucSSCStep = (UserPanelData.ucSpreadSpectrumCtrl & 0x0F);
    ucSSCSpan = (UserPanelData.ucSpreadSpectrumCtrl & 0xF0) >> 4;
    if (ucSSCStep == 0) {
        ucSSCStep = 16;
    }
    if (ucSSCSpan == 0) {
        ucSSCSpan = 16;
    }

#else
    ucSSCStep = (UserPanelData.ucSpreadSpectrumCtrl >> 1)&0x0F;
    ucSSCSpan = (UserPanelData.ucSpreadSpectrumCtrl >> 5);
#endif   
    ShowIndentString(FALSE, 1,18,ucSSC_Text[0],ucSSC_Text);
    ShowIndentString(FALSE, LBar[mfSSC_RATIO].x,LBar[mfSSC_RATIO].y,ucSSCRatio_Text[0],ucSSCRatio_Text);
    ShowIndentString(FALSE, LBar[mfSSC_FREQ].x,LBar[mfSSC_FREQ].y,ucSSCFreq_Text[0],ucSSCFreq_Text);
#endif
#if TPV_SET_LVDS_SWING == ON
    ShowIndentString(FALSE, LBar[mfLVDS_SETTING].x,LBar[mfLVDS_SETTING].y,ucLVDSSwing_Text[0],ucLVDSSwing_Text);
#endif
#if TPV_CLEAR_EE == ON
    ShowIndentString(FALSE, LBar[mfCLEAR_EE].x,LBar[mfCLEAR_EE].y,ucClearEE_Text[0],ucClearEE_Text);
#endif
#if TPV_EDID_WP_ONOFF == ON
    ShowIndentString(FALSE, LBar[mfEDID_WP].x,LBar[mfEDID_WP].y,ucEDIDWP_Text[0],ucEDIDWP_Text);
#endif
#if TPV_CLEAR_TIMER == ON
    ShowIndentString(FALSE, LBar[mfCLEAR_TIMER].x,LBar[mfCLEAR_TIMER].y,ucClearTimer_Text[0],ucClearTimer_Text);
#endif
#if ENABLE_ECO_EYE_SENSOR
        ShowIndentString(FALSE, LBar[mfCLEAR_TIMER].x, LBar[mfCLEAR_TIMER].y+1,ucALS_Text[0],ucALS_Text);
        ShowIndentString(FALSE, LBar[mfCLEAR_TIMER].x+12, LBar[mfCLEAR_TIMER].y+1,ucPXS_Text[0],ucPXS_Text);
#endif

    for (i=3; i<5; i++) {
        ShowIndentString(FALSE,8, i,1,ucR_Text);
        ShowIndentString(FALSE,12, i,1,ucG_Text);
        ShowIndentString(FALSE,16, i,1,ucB_Text);
    }

    for (i=6; i<11; i++) {
        ShowIndentString(FALSE,8, i,1,ucR_Text);
        ShowIndentString(FALSE,12, i,1,ucG_Text);
        ShowIndentString(FALSE,16, i,1,ucB_Text);
    }

#if VCOM_IIC == ON
    ShowIndentString(FALSE, LBar[mfVCOM].x,LBar[mfVCOM].y,ucVCOM_Text[0],ucVCOM_Text);
    FactoryShowValue(mfVCOM, (USHRT)(CalibData.ucVcomValue));
#endif
    FactoryShowBurnin();
    ShowDFM();
#if ENABLE_HDMI == ON
    FactoryShowHDMI_PRETEST();
#endif
    SystemData.bClear_EE = FALSE;
#if TPV_CLEAR_EE == ON
    FactoryShowClaer_EE();
#endif
#if TPV_EDID_WP_ONOFF == ON
    FactoryShowEDIDWP_ONOFF();
#endif
#if TPV_CLEAR_TIMER == ON
    FactoryShowClaer_Timer();
#endif
#if ENABLE_ECO_EYE_SENSOR
    FactoryShowALS_PXS();
#endif

    FactoryShowValue(mfADC_GAIN_R, (USHRT)(CalibData.ucADCRGain));
    FactoryShowValue(mfADC_GAIN_G, (USHRT)(CalibData.ucADCGGain));
    FactoryShowValue(mfADC_GAIN_B, (USHRT)(CalibData.ucADCBGain));
    FactoryShowValue(mfADC_OFFSET_R, (USHRT)(CalibData.ucADCROffset));
    FactoryShowValue(mfADC_OFFSET_G, (USHRT)(CalibData.ucADCGOffset));
    FactoryShowValue(mfADC_OFFSET_B, (USHRT)(CalibData.ucADCBOffset));
    FactoryShowValue(mf5800_GAIN_R, (USHRT)CalibData.uc5800KRGain);
    FactoryShowValue(mf5800_GAIN_G, (USHRT)CalibData.uc5800KGGain);
    FactoryShowValue(mf5800_GAIN_B, (USHRT)CalibData.uc5800KBGain);
    FactoryShowValue(mfCOOL_GAIN_R, (USHRT)CalibData.uc9300KRGain);
    FactoryShowValue(mfCOOL_GAIN_G, (USHRT)CalibData.uc9300KGGain);
    FactoryShowValue(mfCOOL_GAIN_B, (USHRT)CalibData.uc9300KBGain);
    FactoryShowValue(mfUSER_GAIN_R, (USHRT)Remap100To255(UserData.ucUserRGain));
    FactoryShowValue(mfUSER_GAIN_G, (USHRT)Remap100To255(UserData.ucUserGGain));
    FactoryShowValue(mfUSER_GAIN_B, (USHRT)Remap100To255(UserData.ucUserBGain));
    FactoryShowValue(mfSRGB_GAIN_R, (USHRT)CalibData.ucsRGBRGain);
    FactoryShowValue(mfSRGB_GAIN_G, (USHRT)CalibData.ucsRGBGGain);
    FactoryShowValue(mfSRGB_GAIN_B, (USHRT)CalibData.ucsRGBBGain);
    FactoryShowValue(mf6500_GAIN_R, (USHRT)CalibData.uc6500KRGain);
    FactoryShowValue(mf6500_GAIN_G, (USHRT)CalibData.uc6500KGGain);
    FactoryShowValue(mf6500_GAIN_B, (USHRT)CalibData.uc6500KBGain);
    FactoryShowValue(mfNORMAL_BR, (USHRT)UserData.ucBrightness);
    FactoryShowValue(mfNORMAL_CO, (USHRT)UserData.ucContrast);

    //FOSDShowNum(14,18,(UCHAR)(SystemData.usPowerOnTimerH>>8));
    //FOSDShowNum(16,18,(UCHAR)SystemData.usPowerOnTimerH);
    
    FactoryOSDShowNum(8, 17, SystemData.usPowerOnTimerH);
    //FactoryShowHoursRunning();
#if 0//ENABLE_OD
    FactoryShowOD();
    #endif
#if TPV_SET_SSC_CTRL == ON
    FactoryShowSSCSpan();
    FactoryShowSSCStep();
    //FactoryShowSSCPercent();
#endif
#if TPV_SET_LVDS_SWING == ON
    FactoryShowLVDSSwing();
#endif

    ucFactoryIndex = mfRETURN;
    FactorySelect();

    OSDTurnOnOSD();
}
#endif
//******************************************************************************
// Prototype:
//  void OSDFactoryUp(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
void OSDFactoryUp(void)
{
     switch(ucFOSDType)
    {
        default:
        case FOSDPage1:
            FactoryUnSelect();
            if (--ucFactoryIndex > mfRETURN)
                ucFactoryIndex = mfRETURN;
            FactorySelect();

            if (ucFactoryIndex == mfSRGB_GAIN_B) {
                UserData.ucColorTemp = CLRTMP_sRGB;
                SetColorTemperature(CLRTMP_sRGB);
            }
            //else if (ucFactoryIndex == mf5000B) {
            //    UserData.ucColorTemp = CLRTMP_5000K;
            //     UserSetColorTemp();
            //}
            else if (ucFactoryIndex == mf5800_GAIN_B) {
                UserData.ucColorTemp = CLRTMP_5800K;
                UserSetColorTemp();
            }
            else if (ucFactoryIndex == mfUSER_GAIN_B) {
                UserData.ucColorTemp = CLRTMP_USER;
                if(UserData.ucBFMode == PICTURE_MODE_LOW_BL){                    
                    SetLBLMode();
                    SetColorTemperature(UserData.ucColorTemp);
                }
                else{
                UserSetColorTemp();
            }        
            }        
            else if (ucFactoryIndex == mf6500_GAIN_B) {
                UserData.ucColorTemp = CLRTMP_6500K;
                UserSetColorTemp();
            }    
            //else if (ucFactoryIndex == mf7500B) {
            //    UserData.ucColorTemp = CLRTMP_7500K;
            //     UserSetColorTemp();
            // }
            //else if (ucFactoryIndex == mf8200B) {
            //     UserData.ucColorTemp = CLRTMP_8200K;
            //     UserSetColorTemp();
            // }
            else if (ucFactoryIndex == mfCOOL_GAIN_B) {
                UserData.ucColorTemp = CLRTMP_9300K;
                UserSetColorTemp();
            }
            // else if (ucFactoryIndex == mf11500B) {
            //      UserData.ucColorTemp = CLRTMP_11500K;
            //      UserSetColorTemp();
            //  }
            else if (ucFactoryIndex == mfADC_OFFSET_B) {
                UserData.ucColorTemp = CLRTMP_6500K;
                UserSetColorTemp();
            }
     break;
#if PANEL_CONTROL == ON        
     case FOSDPage2:
             OSDFactoryPanelSettingUp();
     break;
#endif     
     }
}

//******************************************************************************
// Prototype:
//  void OSDFactoryDown(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
void OSDFactoryDown(void)
{
    switch(ucFOSDType)
    {
        default:    
        case FOSDPage1:
            FactoryUnSelect();
            if (++ucFactoryIndex > mfRETURN)
                ucFactoryIndex = mfAUTO;
            FactorySelect();

            if (ucFactoryIndex == mfSRGB_GAIN_R) {
                UserData.ucColorTemp = CLRTMP_sRGB;
                SetColorTemperature(CLRTMP_sRGB);
            }
            //else if (ucFactoryIndex == mf5000R) {
            //     UserData.ucColorTemp = CLRTMP_5000K;
            //    UserSetColorTemp();
            // }
            else if (ucFactoryIndex == mf5800_GAIN_R) {
                UserData.ucColorTemp = CLRTMP_5800K;
                UserSetColorTemp();
            }
            else if (ucFactoryIndex == mfUSER_GAIN_R) {
                UserData.ucColorTemp = CLRTMP_USER;
                if(UserData.ucBFMode == PICTURE_MODE_LOW_BL){                    
                    SetLBLMode();
                    SetColorTemperature(UserData.ucColorTemp);
                }
                else{
                UserSetColorTemp();
            }            
            }            
            else if (ucFactoryIndex == mf6500_GAIN_R) {
                UserData.ucColorTemp = CLRTMP_6500K;
                UserSetColorTemp();
            }
            //else if (ucFactoryIndex == mf7500R) {
            //    UserData.ucColorTemp = CLRTMP_7500K;
            //    UserSetColorTemp();
            // }
            //else if (ucFactoryIndex == mf8200R) {
            //    UserData.ucColorTemp = CLRTMP_8200K;
            //    UserSetColorTemp();
            //}
            else if (ucFactoryIndex == mfCOOL_GAIN_R) {
                UserData.ucColorTemp = CLRTMP_9300K;
                UserSetColorTemp();
            }
            //else if (ucFactoryIndex == mf11500R) {
            //     UserData.ucColorTemp = CLRTMP_11500K;
            //    UserSetColorTemp();
             // }
             //else if (ucFactoryIndex == mfADDRESS) {
             //   UserData.ucColorTemp = CLRTMP_6500K;
             //    UserSetColorTemp();
             // }
        break;
#if PANEL_CONTROL == ON
        case FOSDPage2:
            OSDFactoryPanelSettingDn();
        break;
#endif        
    }
}

//******************************************************************************
// Prototype:
//  void OSDFactoryEnterItm(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
void OSDFactoryEnterItm(void)
{
    UCHAR auto_color;
    switch(ucFOSDType)
    {
        default:    
        case FOSDPage1:
            if (ucFactoryIndex == mfAUTO) {
                auto_color = AutoColor();
                            
                if (auto_color) {
                    CalibData.ucADCRGain = GetADCRGain();
                    CalibData.ucADCGGain = GetADCGGain();
                    CalibData.ucADCBGain = GetADCBGain();
                    CalibData.ucADCROffset = GetADCROffset();
                    CalibData.ucADCGOffset = GetADCGOffset();
                    CalibData.ucADCBOffset = GetADCBOffset();
                    SetOSDUpdCalFlag();
                }
                               
                FactoryShowAutoColor(auto_color);
                FactoryShowValue(mfADC_GAIN_R, (USHRT)(CalibData.ucADCRGain));
                FactoryShowValue(mfADC_GAIN_G, (USHRT)(CalibData.ucADCGGain));
                FactoryShowValue(mfADC_GAIN_B, (USHRT)(CalibData.ucADCBGain));
                FactoryShowValue(mfADC_OFFSET_R, (USHRT)(CalibData.ucADCROffset));
                FactoryShowValue(mfADC_OFFSET_G, (USHRT)(CalibData.ucADCGOffset));
                FactoryShowValue(mfADC_OFFSET_B, (USHRT)(CalibData.ucADCBOffset));
                SetOSDState(OSD_FACT_STATE);
                return;
            }
            /*
            else if (ucFactoryIndex == mfRESET) {
                OSDAPI_TurnOffOSD();
                UserRecallConfiguration();
                OSDShowFactory();
                SetOSDUpdCalFlag();
                return;
            }
            */
            else if (ucFactoryIndex == mfRETURN) {
                OSDCloseAll();
                OSDInitialize(TRUE);
                ucFOSDType = FOSDOff;
                return;
            }
#if TPV_CLEAR_TIMER == ON
            else if(ucFactoryIndex == mfCLEAR_TIMER){
                 if(SystemData.bClear_Timer){
                          SystemData.ucMonitorPowerOnTimerM = 0;
                          SystemData.usMonitorPowerOnTimerH = 0;
                          SystemData.ucPowerOnTimerM = 0;
                          SystemData.usPowerOnTimerH = 0;      
                          SetOSDUpdSysFlag();
                 }                    
                 FactoryUnSelect();
                 FactorySelectValue();
            }
#endif
            else {
                FactoryUnSelect();
                FactorySelectValue();
            }
        break;
#if PANEL_CONTROL == ON
        case FOSDPage2:
            OSDEnterFPanelSettingItm();
        break;
#endif        
    }
}

//******************************************************************************
// Prototype:
//  void OSDFactoryExitItm(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
void OSDFactoryExitItm(void)
{
    switch(ucFOSDType)
    {
        default:    
        case FOSDPage1:
            FactoryUnSelectValue();
            FactorySelect();
        break;
#if PANEL_CONTROL == ON
        case FOSDPage2:
            OSDExitFPanelSettingItm();
        break;
#endif        
    }
}

//******************************************************************************
// Prototype:
//  void OSDFactoryItmUp(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
void OSDFactoryItmUp(void)
{
    switch(ucFOSDType)
    {
        default:
        case FOSDPage1:
            switch(ucFactoryIndex) {
                case mfBURNING:
                    SystemData.bBurnIn ^= BIT0;
                    FactoryShowBurnin();
                    break;
                case mfDFM:
                       if(GetProductModeFlag()) {
                           ClrProductModeFlag();
                       }
                       else {
                           SetProductModeFlag();
                       }
                    ShowDFM();
                    break;
                case mfADC_GAIN_R:
                    FactoryValueUp(&CalibData.ucADCRGain);
                    FactoryShowValue(mfADC_GAIN_R, (USHRT)CalibData.ucADCRGain);
                    break;
                case mfADC_GAIN_G:
                    FactoryValueUp(&CalibData.ucADCGGain);
                    FactoryShowValue(mfADC_GAIN_G, (USHRT)CalibData.ucADCGGain);
                    break;
                case mfADC_GAIN_B:
                    FactoryValueUp(&CalibData.ucADCBGain);
                    FactoryShowValue(mfADC_GAIN_B, (USHRT)CalibData.ucADCBGain);
                    break;
                case mfADC_OFFSET_R:
                    FactoryValueUp(&CalibData.ucADCROffset);
                    FactoryShowValue(mfADC_OFFSET_R, (USHRT)CalibData.ucADCROffset);
                    break;
                case mfADC_OFFSET_G:
                    FactoryValueUp(&CalibData.ucADCGOffset);
                    FactoryShowValue(mfADC_OFFSET_G, (USHRT)CalibData.ucADCGOffset);
                    break;
                case mfADC_OFFSET_B:
                    FactoryValueUp(&CalibData.ucADCBOffset);
                    FactoryShowValue(mfADC_OFFSET_B, (USHRT)CalibData.ucADCBOffset);
                    break;
                case mfSRGB_GAIN_R:
                    FactoryValueUp(&CalibData.ucsRGBRGain);
                    FactoryShowValue(mfSRGB_GAIN_R, (USHRT)CalibData.ucsRGBRGain);
                    break;
                case mfSRGB_GAIN_G:
                    FactoryValueUp(&CalibData.ucsRGBGGain);
                    FactoryShowValue(mfSRGB_GAIN_G, (USHRT)CalibData.ucsRGBGGain);
                    break;
                case mfSRGB_GAIN_B:
                    FactoryValueUp(&CalibData.ucsRGBBGain);
                    FactoryShowValue(mfSRGB_GAIN_B, (USHRT)CalibData.ucsRGBBGain);
                break;
                //case mf5000R:
                //    FactoryValueUp(&CalibData.uc5000KRGain);
                //    FactoryShowValue(mf5000R, (USHRT)CalibData.uc5000KRGain);
                //   break;
                // case mf5000G:
                //     FactoryValueUp(&CalibData.uc5000KGGain);
                //     FactoryShowValue(mf5000G, (USHRT)CalibData.uc5000KGGain);
                //     break;
                // case mf5000B:
                //     FactoryValueUp(&CalibData.uc5000KBGain);
                //     FactoryShowValue(mf5000B, (USHRT)CalibData.uc5000KBGain);
                //    break;
                case mf5800_GAIN_R:
                    FactoryValueUp(&CalibData.uc5800KRGain);
                    FactoryShowValue(mf5800_GAIN_R, (USHRT)CalibData.uc5800KRGain);
                    break;
                case mf5800_GAIN_G:
                    FactoryValueUp(&CalibData.uc5800KGGain);
                    FactoryShowValue(mf5800_GAIN_G, (USHRT)CalibData.uc5800KGGain);
                    break;
                case mf5800_GAIN_B:
                    FactoryValueUp(&CalibData.uc5800KBGain);
                    FactoryShowValue(mf5800_GAIN_B, (USHRT)CalibData.uc5800KBGain);
                    break;

                case mfUSER_GAIN_R:
                    if (++UserData.ucUserRGain > 100)
                        UserData.ucUserRGain = 100;
                    else {
                        FactoryShowValue(mfUSER_GAIN_R, (USHRT)GetRGain255());
                     }
                    break;
                case mfUSER_GAIN_G:
                    if (++UserData.ucUserGGain > 100)
                        UserData.ucUserGGain = 100;
                    else {
                        FactoryShowValue(mfUSER_GAIN_G, (USHRT)GetGGain255());
                     }      
                    break;
                case mfUSER_GAIN_B:
                    if (++UserData.ucUserBGain > 100)
                        UserData.ucUserBGain = 100;
                    else {
                        FactoryShowValue(mfUSER_GAIN_B, (USHRT)GetBGain255());
                     }        
                    break;

                case mf6500_GAIN_R:
                    FactoryValueUp(&CalibData.uc6500KRGain);
                    FactoryShowValue(mf6500_GAIN_R, (USHRT)CalibData.uc6500KRGain);
                    break;
                case mf6500_GAIN_G:
                    FactoryValueUp(&CalibData.uc6500KGGain);
                    FactoryShowValue(mf6500_GAIN_G, (USHRT)CalibData.uc6500KGGain);
                    break;
                case mf6500_GAIN_B:
                    FactoryValueUp(&CalibData.uc6500KBGain);
                    FactoryShowValue(mf6500_GAIN_B, (USHRT)CalibData.uc6500KBGain);
                    break;
                //case mf7500R:
                //    FactoryValueUp(&CalibData.uc7500KRGain);
                //    FactoryShowValue(mf7500R, (USHRT)CalibData.uc7500KRGain);
                //     break;
                //case mf7500G:
                //    FactoryValueUp(&CalibData.uc7500KGGain);
                //    FactoryShowValue(mf7500G, (USHRT)CalibData.uc7500KGGain);
                //    break;
                //case mf7500B:
                //    FactoryValueUp(&CalibData.uc7500KBGain);
                //    FactoryShowValue(mf7500B, (USHRT)CalibData.uc7500KBGain);
                //    break;
                //case mf8200R:
                //    FactoryValueUp(&CalibData.uc8200KRGain);
                //     FactoryShowValue(mf8200R, (USHRT)CalibData.uc8200KRGain);
                //     break;
                // case mf8200G:
                //     FactoryValueUp(&CalibData.uc8200KGGain);
                //     FactoryShowValue(mf8200G, (USHRT)CalibData.uc8200KGGain);
                //     break;
                //  case mf8200B:
                //     FactoryValueUp(&CalibData.uc8200KBGain);
                //     FactoryShowValue(mf8200B, (USHRT)CalibData.uc8200KBGain);
                //     break;
                case mfCOOL_GAIN_R:
                    FactoryValueUp(&CalibData.uc9300KRGain);
                    FactoryShowValue(mfCOOL_GAIN_R, (USHRT)CalibData.uc9300KRGain);
                    break;
                case mfCOOL_GAIN_G:
                    FactoryValueUp(&CalibData.uc9300KGGain);
                    FactoryShowValue(mfCOOL_GAIN_G, (USHRT)CalibData.uc9300KGGain);
                    break;
                case mfCOOL_GAIN_B:
                    FactoryValueUp(&CalibData.uc9300KBGain);
                    FactoryShowValue(mfCOOL_GAIN_B, (USHRT)CalibData.uc9300KBGain);
                    break;
                case mfNORMAL_BR:
                    FactoryValueUp(&UserData.ucBrightness);
                    CheckMaxRange(UserData.ucBrightness,MAXIMUM_BRIGHTNESS);
                    FactoryShowValue(mfNORMAL_BR, (USHRT)UserData.ucBrightness);
                    UserSetBrightness();
                    break;
                case mfNORMAL_CO:
                    FactoryValueUp(&UserData.ucContrast);
                    CheckMaxRange(UserData.ucContrast,MAXIMUM_CONTRAST);
                    FactoryShowValue(mfNORMAL_CO, (USHRT)UserData.ucContrast);
                    UserSetContrast();
                    break;
                    //case mf11500R:
                    //    FactoryValueUp(&CalibData.uc11500KRGain);
                    //     FactoryShowValue(mf11500R, (USHRT)CalibData.uc11500KRGain);
                    //    break;
                    // case mf11500G:
                    //     FactoryValueUp(&CalibData.uc11500KGGain);
                    //     FactoryShowValue(mf11500G, (USHRT)CalibData.uc11500KGGain);
                    //     break;
                    //case mf11500B:
                    //     FactoryValueUp(&CalibData.uc11500KBGain);
                    //     FactoryShowValue(mf11500B, (USHRT)CalibData.uc11500KBGain);
                    //    break;
                    // case mfADDRESS:
                    //      FactoryShowValue(mfADDRESS, (USHRT)usRegAddr);
                    //      break;
                    //  case mfWR:
                    //      FactoryShowValue(mfWR, (USHRT)ucRegValue);
                    //      break;
#if VCOM_IIC == ON
                case mfVCOM:
                    if (++(CalibData.ucVcomValue) > 0x7F) {
                        (CalibData.ucVcomValue) = 0x7F;
                    }
                    else {
                        PanelVcomAdjust((CalibData.ucVcomValue));
                        FactoryShowValue(mfVCOM, (USHRT)(CalibData.ucVcomValue));
                    }
                    break;
#endif
#if ENABLE_HDMI == ON
                case mfHDMI_PRETEST:
                    SystemData.bHDMI_PRETEST = ~SystemData.bHDMI_PRETEST;
					#if !lrd_dis_benq
                    SetSyncSource(&MDState[0].SyncState, UserData.bAutoSyncSource);
					#endif
					FactoryShowHDMI_PRETEST();
                    SetOSDUpdSysFlag();
                    break;
#endif
#if TPV_CLEAR_EE == ON
                case mfCLEAR_EE:
                    SystemData.bClear_EE = ~SystemData.bClear_EE;
                    FactoryShowClaer_EE();
                    break;
#endif
#if TPV_EDID_WP_ONOFF == ON
                case mfEDID_WP:
                    SystemData.bEDID_WP = ~SystemData.bEDID_WP;
                    FactoryShowEDIDWP_ONOFF();
                    if (SystemData.bEDID_WP) {
                        EdidWPOn();
                    }
                    else {
                        EdidWPOff();
                    }
                    SetOSDUpdSysFlag();
                    break;
#endif
#if TPV_CLEAR_TIMER == ON
                case mfCLEAR_TIMER:
                    SystemData.bClear_Timer = ~SystemData.bClear_Timer;
                    FactoryShowClaer_Timer();
                    break;
#endif

#if 0//ENABLE_OD
                case mfOD:
                    if (UserData.ucODMode != OD_OFF) {
                        UserData.ucODMode = OD_OFF;
                    }
                    else{
                        UserData.ucODMode = OD_ON;
                    }
                    FactoryShowOD();
                    UserSetOD();
                break;
#endif

#if TPV_SET_SSC_CTRL == ON
                case mfSSC_FREQ:
#if ENABLE_SCALER_NEW_SSC == ON // target ratio
                    if (++ucSSCSpan > 16) {//1~16
                        ucSSCSpan = 16;
                    }
#else
                    if (++ucSSCSpan > 7) {// 0~7
                        ucSSCSpan = 7;
                    }
                    else {
                        FactoryShowSSCSpan();
                    }
#endif                  
                    break;
                case mfSSC_RATIO:
#if ENABLE_SCALER_NEW_SSC == ON
                    if (++ucSSCStep> 16) {// 1~16
                        ucSSCStep = 16;
                    }
#else
                    if (++ucSSCStep> 8) {// 0~8 
                        ucSSCStep = 8;
                    }
                    else {
                        FactoryShowSSCStep();
                    }
#endif
                   break;
#endif

#if TPV_SET_LVDS_SWING == ON
                case mfLVDS_SETTING:
                    if (++UserPanelData.ucLVDS_Swing > (NUM_LVDS_SWING - 1)) {
                        UserPanelData.ucLVDS_Swing = (NUM_LVDS_SWING - 1);
                    }
                    else {
                        FactoryShowLVDSSwing();
                    }
                    break;
#endif
            }
            FactorySetValue();
#if ( ENABLE_SCALER_NEW_SSC == ON) && (TPV_SET_SSC_CTRL == ON)
            if((ucFactoryIndex == mfSSC_FREQ)||(ucFactoryIndex == mfSSC_RATIO)){
                FactoryShowSSCSpan();
                FactoryShowSSCStep();
            }
#endif
        break;
#if PANEL_CONTROL == ON
        case FOSDPage2:
             PanelControl( UP_Action );
        break;
#endif        
    }
}

//******************************************************************************
// Prototype:
//  void OSDFactoryItmDown(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
void OSDFactoryItmDown(void)
{
     switch(ucFOSDType) {
        default:
        case FOSDPage1:
            switch(ucFactoryIndex) {
                case mfBURNING:
                    SystemData.bBurnIn ^= BIT0;
                    FactoryShowBurnin();
                    break;
                case mfDFM:
                       if(GetProductModeFlag()) {
                             ClrProductModeFlag();
                       }
                        else {
                             SetProductModeFlag();
                        }
                    ShowDFM();
                    break;
                case mfADC_GAIN_R:
                    FactoryValueDown(&CalibData.ucADCRGain);
                    FactoryShowValue(mfADC_GAIN_R, (USHRT)CalibData.ucADCRGain);
                    break;
                case mfADC_GAIN_G:
                    FactoryValueDown(&CalibData.ucADCGGain);
                    FactoryShowValue(mfADC_GAIN_G, (USHRT)CalibData.ucADCGGain);
                    break;
                case mfADC_GAIN_B:
                    FactoryValueDown(&CalibData.ucADCBGain);
                    FactoryShowValue(mfADC_GAIN_B, (USHRT)CalibData.ucADCBGain);
                    break;
                case mfADC_OFFSET_R:
                    FactoryValueDown(&CalibData.ucADCROffset);
                    FactoryShowValue(mfADC_OFFSET_R, (USHRT)CalibData.ucADCROffset);
                    break;
                case mfADC_OFFSET_G:
                    FactoryValueDown(&CalibData.ucADCGOffset);
                    FactoryShowValue(mfADC_OFFSET_G, (USHRT)CalibData.ucADCGOffset);
                    break;
                case mfADC_OFFSET_B:
                    FactoryValueDown(&CalibData.ucADCBOffset);
                    FactoryShowValue(mfADC_OFFSET_B, (USHRT)CalibData.ucADCBOffset);
                    break;
                case mfSRGB_GAIN_R:
                    FactoryValueDown(&CalibData.ucsRGBRGain);
                    FactoryShowValue(mfSRGB_GAIN_R, (USHRT)CalibData.ucsRGBRGain);
                    break;
                case mfSRGB_GAIN_G:
                    FactoryValueDown(&CalibData.ucsRGBGGain);
                    FactoryShowValue(mfSRGB_GAIN_G, (USHRT)CalibData.ucsRGBGGain);
                    break;
                case mfSRGB_GAIN_B:
                    FactoryValueDown(&CalibData.ucsRGBBGain);
                    FactoryShowValue(mfSRGB_GAIN_B, (USHRT)CalibData.ucsRGBBGain);
                    break;
                //case mf5000R:
                //    FactoryValueDown(&CalibData.uc5000KRGain);
                //    FactoryShowValue(mf5000R, (USHRT)CalibData.uc5000KRGain);
                //    break;
                //case mf5000G:
                //     FactoryValueDown(&CalibData.uc5000KGGain);
                //     FactoryShowValue(mf5000G, (USHRT)CalibData.uc5000KGGain);
                //     break;
                // case mf5000B:
                //     FactoryValueDown(&CalibData.uc5000KBGain);
                //     FactoryShowValue(mf5000B, (USHRT)CalibData.uc5000KBGain);
                //     break;
                case mf5800_GAIN_R:
                    FactoryValueDown(&CalibData.uc5800KRGain);
                    FactoryShowValue(mf5800_GAIN_R, (USHRT)CalibData.uc5800KRGain);
                    break;
                case mf5800_GAIN_G:
                    FactoryValueDown(&CalibData.uc5800KGGain);
                    FactoryShowValue(mf5800_GAIN_G, (USHRT)CalibData.uc5800KGGain);
                    break;
                case mf5800_GAIN_B:
                    FactoryValueDown(&CalibData.uc5800KBGain);
                    FactoryShowValue(mf5800_GAIN_B, (USHRT)CalibData.uc5800KBGain);
                    break;

                case mfUSER_GAIN_R:
                    if (--UserData.ucUserRGain == 0xff)
                        UserData.ucUserRGain = 0;
                    else {
                        FactoryShowValue(mfUSER_GAIN_R, (USHRT)GetRGain255());
                     } 
                    break;
                case mfUSER_GAIN_G:
                    if (--UserData.ucUserGGain == 0xff)
                        UserData.ucUserGGain = 0;
                    else {
                        FactoryShowValue(mfUSER_GAIN_G, (USHRT)GetGGain255());
                     }  
                    break;
                case mfUSER_GAIN_B:
                    if (--UserData.ucUserBGain == 0xff)
                        UserData.ucUserBGain = 0;
                    else {
                        FactoryShowValue(mfUSER_GAIN_B, (USHRT)GetBGain255());
                     }  
                    break;

                case mf6500_GAIN_R:
                    FactoryValueDown(&CalibData.uc6500KRGain);
                    FactoryShowValue(mf6500_GAIN_R, (USHRT)CalibData.uc6500KRGain);
                    break;
                case mf6500_GAIN_G:
                    FactoryValueDown(&CalibData.uc6500KGGain);
                    FactoryShowValue(mf6500_GAIN_G, (USHRT)CalibData.uc6500KGGain);
                    break;
                case mf6500_GAIN_B:
                    FactoryValueDown(&CalibData.uc6500KBGain);
                    FactoryShowValue(mf6500_GAIN_B, (USHRT)CalibData.uc6500KBGain);
                    break;

                //case mf7500R:
                //    FactoryValueDown(&CalibData.uc7500KRGain);
                //    FactoryShowValue(mf7500R, (USHRT)CalibData.uc7500KRGain);
                //    break;
                //case mf7500G:
                //    FactoryValueDown(&CalibData.uc7500KGGain);
                //    FactoryShowValue(mf7500G, (USHRT)CalibData.uc7500KGGain);
                //    break;
                //case mf7500B:
                //     FactoryValueDown(&CalibData.uc7500KBGain);
                //     FactoryShowValue(mf7500B, (USHRT)CalibData.uc7500KBGain);
                //      break;
                //case mf8200R:
                //    FactoryValueDown(&CalibData.uc8200KRGain);
                //    FactoryShowValue(mf8200R, (USHRT)CalibData.uc8200KRGain);
                //    break;
                //case mf8200G:
                //     FactoryValueDown(&CalibData.uc8200KGGain);
                //     FactoryShowValue(mf8200G, (USHRT)CalibData.uc8200KGGain);
                //     break;
                // case mf8200B:
                //     FactoryValueDown(&CalibData.uc8200KBGain);
                //     FactoryShowValue(mf8200B, (USHRT)CalibData.uc8200KBGain);
                //     break;
                case mfCOOL_GAIN_R:
                    FactoryValueDown(&CalibData.uc9300KRGain);
                    FactoryShowValue(mfCOOL_GAIN_R, (USHRT)CalibData.uc9300KRGain);
                    break;
                case mfCOOL_GAIN_G:
                    FactoryValueDown(&CalibData.uc9300KGGain);
                    FactoryShowValue(mfCOOL_GAIN_G, (USHRT)CalibData.uc9300KGGain);
                    break;
                case mfCOOL_GAIN_B:
                    FactoryValueDown(&CalibData.uc9300KBGain);
                    FactoryShowValue(mfCOOL_GAIN_B, (USHRT)CalibData.uc9300KBGain);
                    break;
                case mfNORMAL_BR:
                    FactoryValueDown(&UserData.ucBrightness);
                    FactoryShowValue(mfNORMAL_BR, (USHRT)UserData.ucBrightness);
                    UserSetBrightness();
                    break;
                case mfNORMAL_CO:
                    FactoryValueDown(&UserData.ucContrast);
                    FactoryShowValue(mfNORMAL_CO, (USHRT)UserData.ucContrast);
                    UserSetContrast();
                    break;

                //case mf11500R:
                //    FactoryValueDown(&CalibData.uc11500KRGain);
                //    FactoryShowValue(mf11500R, (USHRT)CalibData.uc11500KRGain);
                //    break;
                //case mf11500G:
                //    FactoryValueDown(&CalibData.uc11500KGGain);
                //    FactoryShowValue(mf11500G, (USHRT)CalibData.uc11500KGGain);
                //     break;
                // case mf11500B:
                 //   FactoryValueDown(&CalibData.uc11500KBGain);
                 //   FactoryShowValue(mf11500B, (USHRT)CalibData.uc11500KBGain);
                //    break;
                //case mfADDRESS:
                //    FactoryShowValue(mfADDRESS, (USHRT)usRegAddr);
                //    break;
                //case mfWR:
                //    FactoryShowValue(mfWR, (USHRT)ucRegValue);
                //    break;
#if VCOM_IIC == ON
                case mfVCOM:
                    if (--(CalibData.ucVcomValue) > 0x7F) {
                        (CalibData.ucVcomValue) = 0x00;
                    }
                    else {
                        PanelVcomAdjust((CalibData.ucVcomValue));
                        FactoryShowValue(mfVCOM, (USHRT)(CalibData.ucVcomValue));
                    }
                    break;
#endif
#if ENABLE_HDMI ==ON
                case mfHDMI_PRETEST:
                    SystemData.bHDMI_PRETEST = ~SystemData.bHDMI_PRETEST;
					#if !lrd_dis_benq
                    SetSyncSource(&MDState[0].SyncState, UserData.bAutoSyncSource);
					#endif
					FactoryShowHDMI_PRETEST();
                    SetSyncSource(UserData.bAutoSyncSource);
                    SetOSDUpdSysFlag();
                    break;
#endif
#if TPV_CLEAR_EE == ON
                case mfCLEAR_EE:
                    SystemData.bClear_EE = ~SystemData.bClear_EE;
                    FactoryShowClaer_EE();
                    break;
#endif
#if TPV_EDID_WP_ONOFF == ON
                case mfEDID_WP:
                    SystemData.bEDID_WP = ~SystemData.bEDID_WP;
                    FactoryShowEDIDWP_ONOFF();
                    if (SystemData.bEDID_WP) {
                        EdidWPOn();
                    }
                    else {
                        EdidWPOff();
                    }
                    SetOSDUpdSysFlag();
                    break;
#endif
#if TPV_CLEAR_TIMER == ON
                case mfCLEAR_TIMER:
                    SystemData.bClear_Timer = ~SystemData.bClear_Timer;
                    FactoryShowClaer_Timer();
                    break;
#endif
#if 0//ENABLE_OD
                case mfOD:
                    if (UserData.ucODMode != OD_OFF) {
                        UserData.ucODMode = OD_OFF;
                    }
                    else{
                        UserData.ucODMode = OD_ON;
                    }
                    FactoryShowOD();
                    UserSetOD();
                    break;
#endif
#if TPV_SET_SSC_CTRL == ON
                case mfSSC_FREQ:
#if ENABLE_SCALER_NEW_SSC == ON
                    if (--ucSSCSpan < 1) {// 1~16 //target
                        ucSSCSpan = 1;
                    }
#else
                    if (--ucSSCSpan > 7) {// 0~7
                        ucSSCSpan = 0;
                    }
                    else {
                        FactoryShowSSCSpan();
                    }
#endif
                    break;
                case mfSSC_RATIO:
#if ENABLE_SCALER_NEW_SSC == ON
                    if (--ucSSCStep < 1) {// 1~16
                        ucSSCStep = 1;
                    }
#else
                    if (--ucSSCStep> 8) {// 0~8 
                        ucSSCStep = 0;
                    }
                    else {
                        FactoryShowSSCStep();
                    }
#endif
                    break;
#endif

#if TPV_SET_LVDS_SWING == ON
                case mfLVDS_SETTING:
                    if (--UserPanelData.ucLVDS_Swing > (NUM_LVDS_SWING - 1)) {
                        UserPanelData.ucLVDS_Swing = 0;
                    }
                    else {
                        FactoryShowLVDSSwing();
                    }
                    break;
#endif
                }
            FactorySetValue();
#if ( ENABLE_SCALER_NEW_SSC == ON) && (TPV_SET_SSC_CTRL == ON)
            if((ucFactoryIndex == mfSSC_FREQ)||(ucFactoryIndex == mfSSC_RATIO)){
                FactoryShowSSCSpan();
                FactoryShowSSCStep();
            }
#endif

            break;
#if PANEL_CONTROL == ON
        case FOSDPage2:
            PanelControl( Down_Action );
            break;
#endif        
     }
}

void FactorySelect(void)
{
    OSDAPI_FillLineAttr(LBar[ucFactoryIndex].x, LBar[ucFactoryIndex].y,
        LBar[ucFactoryIndex].len,FACTORY_ITEM_COLOR);
}

void FactoryUnSelect(void)
{
    OSDAPI_FillLineAttr(LBar[ucFactoryIndex].x, LBar[ucFactoryIndex].y,
        LBar[ucFactoryIndex].len, FACTORY_FRAME_COLOR);
}

void FactorySelectValue(void)
{
    if ((ucFactoryIndex >= mfADC_GAIN_R) && (ucFactoryIndex <= mf6500_GAIN_B)) {
        OSDAPI_FillLineAttr(LBar[ucFactoryIndex].x+LBar[ucFactoryIndex].len,
            LBar[ucFactoryIndex].y,
            3, FACTORY_ITEM_COLOR);
    }
    else if (ucFactoryIndex == mfBURNING || ucFactoryIndex == mfDFM) {
        OSDAPI_FillLineAttr(LBar[ucFactoryIndex].x+LBar[ucFactoryIndex].len,
            LBar[ucFactoryIndex].y,
            5, FACTORY_ITEM_COLOR);
    }
    /*
    else if (ucFactoryIndex == mfWR ) {
        OSDAPI_FillLineAttr(LBar[ucFactoryIndex].x-5,
                            LBar[ucFactoryIndex].y,
                            4, FACTORY_ITEM_COLOR);
    }
    */
#if TPV_SET_SSC_CTRL == ON
    else if (ucFactoryIndex == mfSSC_RATIO) {
        OSDAPI_FillLineAttr(LBar[ucFactoryIndex].x+LBar[ucFactoryIndex].len,
            LBar[ucFactoryIndex].y,
            3, FACTORY_ITEM_COLOR);
    }
    else if ( ucFactoryIndex == mfSSC_FREQ) {
        OSDAPI_FillLineAttr(LBar[ucFactoryIndex].x+LBar[ucFactoryIndex].len,
            LBar[ucFactoryIndex].y,
            6, FACTORY_ITEM_COLOR);
    }
#endif
    else {
        OSDAPI_FillLineAttr(LBar[ucFactoryIndex].x+LBar[ucFactoryIndex].len,
            LBar[ucFactoryIndex].y,
            4, FACTORY_ITEM_COLOR);
    }
}

void FactoryUnSelectValue(void)
{
    if ((ucFactoryIndex >= mfADC_GAIN_R) && (ucFactoryIndex <= mf6500_GAIN_B)) {
        OSDAPI_FillLineAttr(LBar[ucFactoryIndex].x+LBar[ucFactoryIndex].len,
            LBar[ucFactoryIndex].y,
            3, FACTORY_FRAME_COLOR);
    }
    else if (ucFactoryIndex == mfBURNING || ucFactoryIndex == mfDFM) {
        OSDAPI_FillLineAttr(LBar[ucFactoryIndex].x+LBar[ucFactoryIndex].len,
            LBar[ucFactoryIndex].y,
            5, FACTORY_FRAME_COLOR);
    }
    /*
    else if (ucFactoryIndex == mfWR ) {
        OSDAPI_FillLineAttr(LBar[ucFactoryIndex].x-5,
                            LBar[ucFactoryIndex].y,
                            4, FACTORY_FRAME_COLOR);
    }
    */
    
#if TPV_SET_SSC_CTRL == ON
    else if (ucFactoryIndex == mfSSC_RATIO ) {
        OSDAPI_FillLineAttr(LBar[ucFactoryIndex].x+LBar[ucFactoryIndex].len,
            LBar[ucFactoryIndex].y,
            3, FACTORY_FRAME_COLOR);
    }
    else if ( ucFactoryIndex == mfSSC_FREQ) {
        OSDAPI_FillLineAttr(LBar[ucFactoryIndex].x+LBar[ucFactoryIndex].len,
            LBar[ucFactoryIndex].y,
            6, FACTORY_FRAME_COLOR);
    }
#endif
    else {
        OSDAPI_FillLineAttr(LBar[ucFactoryIndex].x+LBar[ucFactoryIndex].len,
            LBar[ucFactoryIndex].y,
            4, FACTORY_FRAME_COLOR);
    }
}

void FactoryShowValue(UCHAR index, USHRT value)
{
    if (index >= mfADC_GAIN_R &&  index <= mf6500_GAIN_B) {
        FOSDShowNum(LBar[index].x+1, LBar[index].y, value);
    }
#if TPV_SET_SSC_CTRL == ON
    else if (index == mfSSC_RATIO || index == mfSSC_FREQ) {
        FOSDShow1bitNum(LBar[index].x+LBar[index].len, LBar[index].y, value);
    }
#endif
    else {
        FOSDShowNum(LBar[index].x+LBar[index].len, LBar[index].y, value);
    }
}

void FactoryShowBurnin(void)
{
    OSDAPI_SetIndentIndex(0xF8);
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    if (SystemData.bBurnIn == TRUE)
        ShowIndentString(FALSE, LBar[mfBURNING].x+8, LBar[mfBURNING].y, 3, ucON_Text);
    else
        ShowIndentString(FALSE, LBar[mfBURNING].x+8, LBar[mfBURNING].y, 3, ucOFF_Text);
}

#if ENABLE_HDMI == ON
void FactoryShowHDMI_PRETEST(void)
{
    OSDAPI_SetIndentIndex(0xDF);
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    if (SystemData.bHDMI_PRETEST == TRUE)
        ShowIndentString(FALSE, LBar[mfHDMI_PRETEST].x+12, LBar[mfHDMI_PRETEST].y, 3, ucON_Text);
    else
        ShowIndentString(FALSE, LBar[mfHDMI_PRETEST].x+12, LBar[mfHDMI_PRETEST].y, 3, ucOFF_Text);
}
#endif

#if TPV_CLEAR_EE == ON
void FactoryShowClaer_EE(void)
{
    OSDAPI_SetIndentIndex(0xCB);
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    if (SystemData.bClear_EE == TRUE)
        ShowIndentString(FALSE, LBar[mfCLEAR_EE].x+12, LBar[mfCLEAR_EE].y, 3, ucYesText);
    else
        ShowIndentString(FALSE, LBar[mfCLEAR_EE].x+12, LBar[mfCLEAR_EE].y, 3, ucNoText);
}
#endif

#if TPV_EDID_WP_ONOFF == ON
void FactoryShowEDIDWP_ONOFF(void)
{
    OSDAPI_SetIndentIndex(0xC8);
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    if (SystemData.bEDID_WP == TRUE)
        ShowIndentString(FALSE, LBar[mfEDID_WP].x+12, LBar[mfEDID_WP].y, 3, ucON_Text);
    else
        ShowIndentString(FALSE, LBar[mfEDID_WP].x+12, LBar[mfEDID_WP].y, 3, ucOFF_Text);
}
#endif

#if TPV_CLEAR_TIMER == ON
void FactoryShowClaer_Timer(void)
{
    OSDAPI_SetIndentIndex(0xDB);
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    if (SystemData.bClear_Timer == TRUE)
        ShowIndentString(FALSE, LBar[mfCLEAR_TIMER].x+12, LBar[mfCLEAR_TIMER].y, 3, ucYesText);
    else
        ShowIndentString(FALSE, LBar[mfCLEAR_TIMER].x+12, LBar[mfCLEAR_TIMER].y, 3, ucNoText);
}
#endif

#if ENABLE_ECO_EYE_SENSOR == ON    
extern UCHAR g_ucIRPSValue;
extern USHRT g_usIRALSValue;
void FactoryShowALS_PXS(void)
{
    UCHAR ucALS[] = {5 ,"65535"};
    UCHAR ucPXS[] = {3 ,"255"};
    
    sprintf(ucALS,"n%5u",(USHRT)g_usIRALSValue);
    sprintf(ucPXS,"n%3u",(USHRT)g_ucIRPSValue);
    ucALS[0] = 5;
    ucPXS[0] = 3;
    //printf("ucALS =%d,%d\r\n",(USHRT)ucALS,(USHRT)ucPXS);
    #if 1
    OSDAPI_SetIndentIndex(0xBB);
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    ShowIndentString(FALSE, LBar[mfCLEAR_TIMER].x+3, LBar[mfCLEAR_TIMER].y+1, 5, ucALS);
    ShowIndentString(FALSE, LBar[mfCLEAR_TIMER].x+15, LBar[mfCLEAR_TIMER].y+1, 3, ucPXS);
#endif
}
#endif

void FactoryShowAutoColor(UCHAR result)
{
    OSDAPI_SetIndentIndex(0xF0);
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);

    if (result == 1)
        ShowIndentString(FALSE, LBar[mfAUTO].x+8, LBar[mfAUTO].y, 3, ucOkText);
    else
        ShowIndentString(FALSE, LBar[mfAUTO].x+8, LBar[mfAUTO].y, 3, ucNoText);
}

void FactoryValueUp(UCHAR *val)
{
    if (++(*val) == 0x00) {
        (*val) = 0xFF;
    }
}

void FactoryValueDown(UCHAR *val)
{
    if (--(*val) == 0xFF) {
        (*val) = 0;
    }
}

void FactorySetValue(void)
{
    switch(ucFactoryIndex) {
        case mfBURNING:
        case mfDFM:
            SetOSDUpdSysFlag();
            break;
        case mfADC_GAIN_R:
        case mfADC_GAIN_G:
        case mfADC_GAIN_B:
        case mfADC_OFFSET_R:
        case mfADC_OFFSET_G:
        case mfADC_OFFSET_B:
            //SetADCRGain(CalibData.ucADCRGain);
            //SetADCGGain(CalibData.ucADCGGain);
            //SetADCBGain(CalibData.ucADCBGain);
            //SetADCROffset(CalibData.ucADCROffset);
            //SetADCGOffset(CalibData.ucADCGOffset);
            //SetADCBOffset(CalibData.ucADCBOffset);
            UserSetADCGainOffset();
            SetOSDUpdCalFlag();
            break;
        case mfUSER_GAIN_R:    
        case mfUSER_GAIN_G:
        case mfUSER_GAIN_B:
            if(UserData.ucBFMode == PICTURE_MODE_LOW_BL){                
                MTXAPI_SetContrastValue(GetContrast255());
                MTXAPI_SelMatrix(MTX_LOCAL);
                BFAPI_SetActiveWindow(BF_WINDOW_1);     
                SetColorTemperature(CLRTMP_USER);
                MTXAPI_SelMatrix(MTX_GLOBAL);  
                MTXAPI_SetContrast(GetContrast255());
            }
            else{
            UserSetColorTemp();
            }
            SetOSDUpdCalFlag();
            SetOSDUpdUsrFlag();
            break;
        case mfSRGB_GAIN_R:
        case mfSRGB_GAIN_G:
        case mfSRGB_GAIN_B:
            SetColorTemperature(CLRTMP_sRGB);
            SetOSDUpdCalFlag();
            break;
        case mf5800_GAIN_R:
        case mf5800_GAIN_G:
        case mf5800_GAIN_B:
        case mfCOOL_GAIN_R:
        case mfCOOL_GAIN_G:
        case mfCOOL_GAIN_B:
        case mf6500_GAIN_R:
        case mf6500_GAIN_G:
        case mf6500_GAIN_B:
            UserSetColorTemp();
            SetOSDUpdCalFlag();
            break;
#if VCOM_IIC == ON
        case mfVCOM:
            SetOSDUpdCalFlag();
            break;
#endif
#if TPV_SET_SSC_CTRL == ON
        case mfSSC_FREQ:
        case mfSSC_RATIO:
#if ENABLE_SCALER_NEW_SSC == ON
            ConfigSSClevel(ucSSCStep);
            ConfigSSCRange(ucSSCSpan);
#else
            UserPanelData.ucSpreadSpectrumCtrl = (ucSSCSpan << 5) | (ucSSCStep << 1) | BIT0;
            SetDclkSSC(UserPanelData.ucSpreadSpectrumCtrl);
#endif  
           break;
#endif
#if TPV_SET_LVDS_SWING == ON
        case mfLVDS_SETTING:
            SetLvdsSwing(UserPanelData.ucLVDS_Swing);
            break;
#endif
    }
}

void ShowDFM(void)
{
    OSDAPI_SetIndentIndex(0xFC);

    if (GetProductModeFlag())
    {
        ShowIndentString(TRUE, 9, 14,ucON_Text[0],ucON_Text);
    }
    else {
        ShowIndentString(TRUE, 9, 14,ucON_Text[0],ucOFF_Text);
    }

}
#if 0//ENABLE_OD
void FactoryShowOD(void)
{
    OSDAPI_SetIndentIndex(0xF3);

    if (UserData.ucODMode) {
        ShowIndentString(FALSE, LBar[mfOD].x + 5, LBar[mfOD].y,3,ucON_Text);
    }
    else {
        ShowIndentString(FALSE, LBar[mfOD].x + 5, LBar[mfOD].y,3,ucOFF_Text);
    }
    
}
#endif

#if TPV_SET_SSC_CTRL == ON
void FactoryShowSSCSpan(void)
{
    FactoryShowSSCFreq();
    FactoryShowSSCValue();
}
void FactoryShowSSCStep(void)
{
    FactoryShowValue(mfSSC_RATIO, (USHRT)(ucSSCStep));
    FactoryShowSSCValue();
}

void FactoryShowSSCFreq(void)
{
#if ENABLE_SCALER_NEW_SSC == ON //show target ratio
    #define STR_LEN 9
    UCHAR i, temp[2], SSC_ratio_Str_Buff[STR_LEN];
    USHRT ustargetratio;
        
    ustargetratio = GetTargetSSCRange();
    temp[0] = (UCHAR)(ustargetratio / 10);
    temp[1] = (UCHAR)(ustargetratio % 10);
 
    for (i = 0; i < STR_LEN; i++) {
        SSC_ratio_Str_Buff[i] = 0;
    }
    temp[1] = temp[1] * 10;
    if (temp[1] >= 10) {
        sprintf(SSC_ratio_Str_Buff,"nS%d.%2dP",(USHRT)temp[0], (USHRT)temp[1]);
    }
    else {
        sprintf(SSC_ratio_Str_Buff,"nS%d.0%dP",(USHRT)temp[0], (USHRT)temp[1]);
    }

    for (i = 0; i < STR_LEN; i++) {
        if (SSC_ratio_Str_Buff[i] == 'S') {
            SSC_ratio_Str_Buff[i] = ' ';//0x98;
        }
        else if (SSC_ratio_Str_Buff[i] == 'P') {
            SSC_ratio_Str_Buff[i] = 37;//0x7f;
        }
        else if (SSC_ratio_Str_Buff[i] == '\0') {
            break;
        }
    }    
    SSC_ratio_Str_Buff[0] = i - 1;

    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    OSDAPI_SetIndentIndex(0xE6);
    ShowIndentString(FALSE,LBar[mfSSC_FREQ].x+LBar[mfSSC_FREQ].len+1,
        LBar[mfSSC_FREQ].y,SSC_ratio_Str_Buff[0],SSC_ratio_Str_Buff);
    
    #undef STR_LEN
#else
    #define STR_LEN 9
    UCHAR i, SSC_Freq_Str_Buff[STR_LEN];
    USHRT usSSCFreq;

   code USHRT SSC_Freq_Table[] = {234, 468, 937, 1875, 3750, 7500, 15000, 30000}; //unit: 0.1KHz
   usSSCFreq = SSC_Freq_Table[ucSSCSpan];

    for (i = 0; i < STR_LEN; i++) {
        SSC_Freq_Str_Buff[i] = 0;
    }
    if (usSSCFreq < 1000) {
        sprintf(SSC_Freq_Str_Buff,"n%2d.%dKHz",(usSSCFreq/10), (usSSCFreq%10));
    }
    else if (usSSCFreq > 10000) {
        sprintf(SSC_Freq_Str_Buff,"n%d.%dMHz",(usSSCFreq/10000), ((usSSCFreq%10000)/1000));
    }
    else {
        sprintf(SSC_Freq_Str_Buff,"n%3d.%dKHz",(usSSCFreq/10), (usSSCFreq%10));
    }

    for (i = 0; i < STR_LEN; i++) {
        if (SSC_Freq_Str_Buff[i] == '\0') {
            break;
        }
    }
    SSC_Freq_Str_Buff[0] = i - 1;

    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    OSDAPI_SetIndentIndex(0xE6);
    ShowIndentString(FALSE,LBar[mfSSC_FREQ].x+LBar[mfSSC_FREQ].len,
        LBar[mfSSC_FREQ].y,SSC_Freq_Str_Buff[0],SSC_Freq_Str_Buff);
#undef STR_LEN
#endif
}

USHRT FGetSSCRange(void)
{
    return (USHRT)(((ULONG)(SC_SSC_FDEV&0x3F))*SC_SSC_FMOD*10000/32768);//Unit 0.01%;
 }

void FactoryShowSSCValue(void)
{
    #define STR_LEN 11
    UCHAR i, temp[2], SSC_String_Buff[STR_LEN];
    USHRT usSSCRange;
        UCHAR ucLanuageTemp;

    usSSCRange = FGetSSCRange();
    temp[0] = (UCHAR)(usSSCRange / 100);
    temp[1] = (UCHAR)(usSSCRange % 100);
    
    
    for (i = 0; i < STR_LEN; i++) {
        SSC_String_Buff[i] = 0;
    }
    if (temp[0] > 10) {
        sprintf(SSC_String_Buff,"nS%2d.%2dP",(USHRT)temp[0], (USHRT)temp[1]);
    }
    else {
        if (temp[1] >= 10) {
            sprintf(SSC_String_Buff,"nS%d.%2dP",(USHRT)temp[0], (USHRT)temp[1]);
        }
        else {
            sprintf(SSC_String_Buff,"nS%d.0%dP",(USHRT)temp[0], (USHRT)temp[1]);
        }
    }
    for (i = 0; i < STR_LEN; i++) {
        if (SSC_String_Buff[i] == 'S') {
            SSC_String_Buff[i] = ' ';//0x98;
        }
        else if (SSC_String_Buff[i] == 'P') {
            SSC_String_Buff[i] = 37;//0x7f;
        }
        else if (SSC_String_Buff[i] == '\0') {
            break;
        }
    }
    SSC_String_Buff[0] = i - 1;

    ucLanuageTemp = UserData.ucLanguage;
    UserData.ucLanguage = OSDLANG_ENGLISH;
    
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    OSDAPI_SetIndentIndex(0xCF);//v06_120711_1450_OSD#1
    ShowIndentString(FALSE,16,LBar[mfSSC_RATIO].y,OSD_FACTORY_W - 15,SSC_String_Buff); //show SSC percentage

    UserData.ucLanguage = ucLanuageTemp;
#if ENABLE_SCALER_NEW_SSC == ON
    {
        UCHAR uctmp0, uctmp1;
        uctmp0 = ucSSCSpan;
        uctmp1 = ucSSCStep;
        if (uctmp0 == 16) {
            uctmp0 = 0;
        }
        if (uctmp1 == 16) {
            uctmp1 = 0;
        }        
    //usSSCRange= (USHRT)(SC_SSC_FMOD << 8 | SC_SSC_FDEV); //(ucSSCSpan << 5) | (ucSSCStep << 1) | BIT0;
    usSSCRange= (uctmp0 << 4) | (uctmp1);
    }
#else
    usSSCRange= (ucSSCSpan << 5) | (ucSSCStep << 1) | BIT0;
#endif
    
    for (i = 0; i < STR_LEN; i++) {
        SSC_String_Buff[i] = 0;
    }

#if ENABLE_SCALER_NEW_SSC == ON
    sprintf(SSC_String_Buff,"nReg 0x%2x",usSSCRange);
#else
    sprintf(SSC_String_Buff,"nReg 0x%4x",usSSCRange);
#endif
    for (i = 0; i < STR_LEN; i++) {
        if (SSC_String_Buff[i] == 'S') {
            SSC_String_Buff[i] = ' ';//0x98;
        }
        else if (SSC_String_Buff[i] == 'P') {
            SSC_String_Buff[i] = 37;//0x7f;
        }
        else if (SSC_String_Buff[i] == '\0') {
            break;
        }
    }
    SSC_String_Buff[0] = i - 1;
    ShowIndentString(FALSE,13,LBar[mfSSC_FREQ].y,SSC_String_Buff[0],SSC_String_Buff); //Show SSC register value
    
#undef STR_LEN
}

#endif

#if TPV_SET_LVDS_SWING == ON
void FactoryShowLVDSSwing(void)
{
#if IS_NT68669_SERIES || IS_NT68750_SERIES
    FactoryShowValue(mfLVDS_SETTING, (USHRT)(200+((USHRT)UserPanelData.ucLVDS_Swing*50)));

#elif IS_NT68168_SERIES || IS_NT68668_SERIES || IS_NT68650_SERIES || IS_NT68660_SERIES

    FactoryShowValue(mfLVDS_SETTING, (USHRT)(150+((USHRT)UserPanelData.ucLVDS_Swing*50)));
#else // 671 or 676 series
    if (UserPanelData.ucLVDS_Swing == LVDS_SWING_220) {
        FactoryShowValue(mfLVDS_SETTING, (USHRT)(220));
    }
    else {
        FactoryShowValue(mfLVDS_SETTING, (USHRT)(200+((USHRT)UserPanelData.ucLVDS_Swing*50)));
    }
#endif
}
#endif


/*
static void FactoryShowIOT(void)
{
    UCHAR Buff[15];
    UCHAR i;
    ULONG temp;
    OSDAPI_SetIndentIndex(0xD0);
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    
    sprintf(Buff,"nhhhhh H mm M");
    temp = SystemData.ulBackLightOnTimerH;
    Buff[1] = ((temp / 10000) & 0x0f) | 0x30;
    Buff[2] = (((temp%10000)/1000) & 0x0f) | 0x30;
    Buff[3] = ((((temp%10000)%1000)/100) & 0x0f) | 0x30;
    Buff[4] = (((((temp%10000)%1000)%100)/10) & 0x0f) | 0x30;
    Buff[5] = (((((temp%10000)%1000)%100)%10) & 0x0f) | 0x30;
    Buff[9] = ((SystemData.ucBackLightOnTimerM / 10) & 0x0f) | 0x30;
    Buff[10] = ((SystemData.ucBackLightOnTimerM % 10) & 0x0f) | 0x30;
    for (i=0; i<GLOB_FONTBUF_LEN; i++) {
        if (Buff[i] == 0)
            break;
    }
    
    Buff[0] = i - 1;
    ShowIndentString(FALSE, 8,18,Buff[0],Buff);
}
*/

/*
static void FactoryShowPOT(void)
{
    UCHAR Buff[15];
    UCHAR i;
    ULONG temp;
    OSDAPI_SetIndentIndex(0xE0);
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    
    sprintf(Buff,"nhhhhh H mm M");
    temp = SystemData.ulPowerOnTimerH;
    Buff[1] = ((temp / 10000) & 0x0f) | 0x30;
    Buff[2] = (((temp%10000)/1000) & 0x0f) | 0x30;
    Buff[3] = ((((temp%10000)%1000)/100) & 0x0f) | 0x30;
    Buff[4] = (((((temp%10000)%1000)%100)/10) & 0x0f) | 0x30;
    Buff[5] = (((((temp%10000)%1000)%100)%10) & 0x0f) | 0x30;
    Buff[9] = ((SystemData.ucPowerOnTimerM / 10) & 0x0f) | 0x30;
    Buff[10] = ((SystemData.ucPowerOnTimerM % 10) & 0x0f) | 0x30;

    for (i=0; i<GLOB_FONTBUF_LEN; i++) {
        if (Buff[i] == 0)
            break;
    }
    
      Buff[0] = i - 1;
      ShowIndentString(FALSE, 8,18,Buff[0],Buff);
}
*/

/*
void FactoryShowHoursRunning(void)
{
    if (Custom_System.bFactory && ucFOSDType == FOSDPage1)
    {
        FactoryShowPOT();
        FactoryShowIOT();
    }
}
*/


