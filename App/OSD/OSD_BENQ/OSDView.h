/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/
#ifndef __OSD_VIEW_H__
#define __OSD_VIEW_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "Typedef.h"
#include "OSDFont.h"
#include "Include.h"

//******************************************************************************
// G L O B A L   D E F I N I T I O N S
//******************************************************************************

extern xdata  UCHAR ucMainIconPos[12];
extern xdata  UCHAR SPIcon1PosTab[10];
extern xdata  UCHAR SPIcon2PosTab[10];
extern xdata  UCHAR SPIcon3PosTab[10];
extern xdata  UCHAR SPIcon4PosTab[8];
extern xdata  UCHAR SPIcon5PosTab[12];
extern xdata  UCHAR *SPIconPosInfoTab[6];

extern xdata  UCHAR SPIconItmNumTab[6];
extern xdata  UCHAR ucLayer1StringInfoTb[2];
extern xdata  UCHAR ucLayer2ItmNumTb[6];
extern xdata  UCHAR ucLayer2ItemInfoTb[2];
#if ENABLE_AUTO_POVIT_FUNC == ON
extern xdata  UCHAR ucLayer3MItem1NumTb[7];
#else
extern xdata  UCHAR ucLayer3MItem1NumTb[6];
#endif
extern xdata  UCHAR ucLayer3MItem1InfoTb[2];
extern xdata  UCHAR ucLayer3MItem2NumTb[9];
extern xdata  UCHAR ucLayer3MItem2InfoTb[2];
extern xdata  UCHAR ucLayer3MItem3NumTb[7];
extern xdata  UCHAR ucLayer3MItem3InfoTb[2];
extern xdata  UCHAR ucLayer3MItemAudioNumTb[3];
extern xdata  UCHAR ucLayer3MItemAudioInfoTb[2];
extern xdata  UCHAR ucLayer3MItem4NumTb[12];
extern xdata  UCHAR ucLayer3MItem4InfoTb[2];
extern xdata  UCHAR ucLayer4ItemInfoTb[6];
extern xdata  UCHAR ucLBLItemInfoTb[3];
extern xdata  UCHAR ucLayer3MItemErgoNumTb[3];
extern xdata  UCHAR ucLayer3MItemErgoInfoTb[2];
extern xdata  UCHAR *ucLayer3ItmNumTab[6];
extern xdata  UCHAR *ucLayer3PosInfoTab[6];

extern xdata  UCHAR ucAuto_PosTab[6];
extern xdata  UCHAR ucDisplay_PosTab[6];

extern xdata  UCHAR ucContrast_PosTab[6];
extern xdata  UCHAR ucBrightness_PosTab[6];
extern xdata  UCHAR ucPicture_PosTab[6];
extern xdata  UCHAR ucInput_PosTab[6];
extern xdata  UCHAR ucMenu_PosTab[9];
extern xdata  UCHAR ucExit_PosTab[9];
//ULEric140402
extern xdata  UCHAR ucVolume_PosTab[6];
extern xdata  UCHAR ucMute_PosTab[6];
extern xdata  UCHAR ucLowBlueLight_PosTab[6];
extern xdata  UCHAR ucSmartReminder_PosTab[6];
extern xdata  UCHAR *ucTopPageIconInfoTab[10];


enum {
    OSD_SUBMENU_1,
    OSD_SUBMENU_2,
    OSD_SUBMENU_3,
    OSD_SUBMENU_4,
    OSD_MAIN_ITEMS,
    OSD_DLG_BRIGHTNESS,
    OSD_DLG_CONTRAST,
    OSD_DLG_VOLUME,
    OSD_DLG_AUTOTUNE,
    OSD_DLG_85Hz,
    OSD_DLG_OUTOFRANGE,
    OSD_DLG_NOSYNC,
    OSD_DLG_NOCABLE,
    OSD_DLG_OSDLOCK,
    OSD_DLG_OSDUNLOCKKEY,
    OSD_DLG_SLEEP,
    OSD_DLG_NOTICE,
    OSD_DLG_NONPRESET,    
    OSD_DLG_SAVENOTICE,//ULEric140331
    OSD_DLG_BURNIN,
    OSD_DLG_RESNOTE,
    OSD_SRC_MENU,
    OSD_DLG_REMINDER,    
    OSD_DLG_RESETNOTICE,//ULEric140410
    OSD_DLG_RESETCOLORNOTICE,//ULEric140410
    OSD_DLG_SENSEYE_DEMO,
    OSD_DLG_DCRNOTICE,//ULEric140414
    OSD_OFF
};

enum {
    OSD_FUNCITM_1,
    OSD_FUNCITM_2,
    OSD_FUNCITM_3,
    OSD_FUNCITM_4,
    OSD_FUNCITM_5,
    OSD_FUNCITM_6,
    OSD_FUNC_ITEMS
};

enum {
    OSD_LAYER1_WIN,
    OSD_LAYER2_WIN,
    OSD_LAYER3_WIN,
    OSD_LAYER4_WIN,
    OSD_DIALOG_LAYER_WIN,
    OSD_DIALOG2_LAYER_WIN,
    OSD_COLORTEMP_WIN,
    OSD_BG_WIN,
    OSD_INFO_WIN,
    OSD_OSDUNLOCKINFO_WIN,
};

enum {
    SLIDERBAR_RED_COLOR,
    SLIDERBAR_GREEN_COLOR,
    SLIDERBAR_BLUE_COLOR,
    SLIDERBAR_GRAY_COLOR
};

enum {
    SLIDERBAR_RANGE_5,//Dynamic Contrast
    SLIDERBAR_RANGE_10,
    SLIDERBAR_RANGE_64,//phase
    SLIDERBAR_RANGE_100,    
};

enum {
    OSD_MAIN_DISPLAY,
    OSD_MAIN_PICTURE,
    OSD_MAIN_PICTURE_ADVANCED,
    OSD_MAIN_AUDIO,
    OSD_MAIN_SYSTEM,
    OSD_MAIN_ERGONOMICS,
};

enum {
    OSD_DISPLAY_ADJUST,
#if ENABLE_AUTO_POVIT_FUNC == ON  
    OSD_DISPLAY_PIVOT,
#endif
    OSD_DISPLAY_INPUT,
    OSD_DISPLAY_HPOS,
    OSD_DISPLAY_VPOS,
    OSD_DISPLAY_PIXELCLK,
    OSD_DISPLAY_PHASE,
};

enum {
    OSD_PICTURE_BRIGHTNESS,
    OSD_PICTURE_CONTRAST,
    OSD_PICTURE_SHARPNESS,
    OSD_PICTURE_GAMMA,
    OSD_PICTURE_COLORTEMP,
    OSD_PICTURE_HUE,
    OSD_PICTURE_SATURATION,
    OSD_PICTURE_RESETCOLOR,
    OSD_PICTURE_AMA,
};

enum {
    OSD_PICTURE_AD_PIC,
    OSD_PICTURE_AD_SENSEYE,
    OSD_PICTURE_AD_DCR,
    OSD_PICTURE_AD_OVERSCAN,
    OSD_PICTURE_AD_DISMODE,
    OSD_PICTURE_AD_COLORFORMAT,
    OSD_PICTURE_AD_PCRANGE,
};

enum {
    OSD_AUDIO_VOLUME,
    OSD_AUDIO_MUTE,
    OSD_AUDIO_SELECT,
};

enum {
    OSD_SYS_OSDSET,
    OSD_SYS_CTKEY1,
    OSD_SYS_CTKEY2,
    OSD_SYS_CTKEY3,
    OSD_SYS_DDCCI,
    OSD_SYS_DPASWITCH,
    OSD_SYS_HDASWITCH,
    OSD_SYS_AUTO_POWEROFF,    
    OSD_SYS_RES,
    OSD_SYS_INFORMATION,
    OSD_SYS_DISPLAYPORT,
    OSD_SYS_RECALL,
};

enum {
    OSD_SYS_OSDSET_LANG,
    OSD_SYS_OSDSET_TIMER,
    OSD_SYS_OSDSET_OSDLOCK,
};

enum {
    OSD_ERGONOMICS_REMIDER,
    OSD_ERGONOMICS_TIME,
    OSD_ERGONOMICS_DURATION,
};

//ULEric140403
enum {
    TopArrowType,
    MiddleArrowType,    
    LastArrowType,
    ClearArrowType,
};


#define SPACE_CHAR          0x00
#define OSD_TOPPAGE_WIDTH    18
#define OSD_TOPPAGE_HEIGHT    21

#define OSD_CUSTOMERKEY_MENU1_WIDTH    31
#define OSD_CUSTOMERKEY_MENU1_HEIGHT    23

#define OSD_CUSTOMERKEY_MENU2_WIDTH    22
#define OSD_CUSTOMERKEY_MENU2_HEIGHT    23



#define OSD_MAIN_WIDTH      69
#define OSD_MAIN_HEIGHT     23
#define OSD_MAX_LINES         8
#define OSD_DIALOG_WIDTH    31
#define OSD_DIALOG_HEIGHT    7
#define OSD_INFO_WIDTH      25
#define OSD_INFO_HEIGHT     8
#define OSD_SRC_WIDTH       18
#define OSD_SRC_HEIGHT      12
#define OSD_BF_WIDTH        18
#define OSD_BF_HEIGHT       14
#define OSD_SUB_X           5
#define OSD_SUB_Y           6
#define OSD_SUB_WIDTH       (OSD_MAIN_WIDTH-7)
#define OSD_SUB_HEIGHT      (OSD_MAIN_HEIGHT-10)
#define OSD_FUNC_WIDTH      29
#define OSD_FUNC_HEIGHT     15
#define OSD_DIALOG_SELECTPAGE_WIDTH    39//ULEric140410
#define OSD_DIALOG_SELECTPAGE_HEIGHT   23//ULEric140410

#define OSD_SENSEYE_DEMO_WIDTH  46
#define OSD_SENSEYE_DEMO_HIGHT  1

#define OSD_MAIN_TOP_MENU_H_POSITION    2344//2368//ULEric140410
#define OSD_MAIN_TOP_MENU_V_POSITION    945//ULEric140410

#define OSD_MAIN_MENU_H_POSITION    1732//ULEric140410
#define OSD_MAIN_MENU_V_POSITION    945//ULEric140410

#define OSD_HOTKEY_MENU_H_POSITION    2188//ULEric140410
#define OSD_HOTKEY_MENU_V_POSITION    945//ULEric140410
#define OSD_HOTKEY_BAR_H_POSITION    2296//ULEric140410

#define OSD_WIN_BOARDER_SIZE    3

#define MAX_X               (PANEL_WIDTH - (12*OSD_INFO_WIDTH))
#define MAX_Y               (PANEL_HEIGHT - (18*OSD_INFO_HEIGHT))
#define OSD_MOVESTEP_X      6
#define OSD_MOVESTEP_Y      6
#define MAX_ROT_X           (PANEL_WIDTH - (18*OSD_INFO_HEIGHT))
#define MAX_ROT_Y           (PANEL_HEIGHT - (12*OSD_INFO_WIDTH))
#define OSD_MOVESTEP_ROT_X  OSD_MOVESTEP_Y
#define OSD_MOVESTEP_ROT_Y  OSD_MOVESTEP_X


#define MAIN_FRAME_COLOR    (((I_WHITE-1)<<8)|(I_TBLACK<<4)|0x0000)
#define DIALOG_MAIN_FRAME_COLOR    (((I_WHITE-1)<<8)|(I_TBLACK<<4)|0x0000)
#define TOPPAGE_FRAME_COLOR    (((I_WHITE-1)<<8)|(I_BENQ_GRAY_3<<4)|0x0000)
#define DIALOG_FRAME_COLOR    (((TOP_PAGE_2BIT_COLOR1-1)<<8)|(I_TBLACK<<4)|0x08|0x0002)
#define TITLE_COLOR         (((I_WHITE-1)<<8)|(I_TGREEN<<4)|0x0000)
#define SUB_FRAME_COLOR     (((I_TGREEN-1)<<8)|(I_WHITE<<4)|0x0000)
#define DISABLE_COLOR       (((I_GRAY-1)<<8)|(I_WHITE<<4)|0x0000)
#define SLIDER_COLOR        (((I_MAGENTA-1)<<8)|(I_TMAGENTA<<4)|0x0000)
#define INFO_DLG_COLOR      (((I_TGREEN-1)<<8)|(I_WHITE<<4)|0x0002)
#define SRC_MENU_COLOR      (((I_TGREEN-1)<<8)|(I_WHITE<<4)|0x0002)
#define BF_MENU_COLOR       (((I_TGREEN-1)<<8)|(I_WHITE<<4)|0x0002)
#define FUNC_FRAME_COLOR    (((I_TGREEN-1)<<8)|(I_WHITE<<4)|0x0002)
#define MainIcon16Color1    (((0x10)<<8)|(I_TCYAN<<4)|0x0c|0x0000)
#define MainIcon16Color2    (((0x20)<<8)|(I_TCYAN<<4)|0x0c|0x0000)
#define MainIcon4Color1     (((0x30)<<8)|(I_TCYAN<<4)|0x08|0x0000)
#define MainIcon4Color2     (((0x34)<<8)|(I_TCYAN<<4)|0x08|0x0000)
#define MainIcon4Color3     (((0x38)<<8)|(I_TCYAN<<4)|0x08|0x0000)
#define SENSEYE_FRAME_COLOR (((I_WHITE-1)<<8)|(0x0000<<4)|0x0002)

#if 1//OSDTYPE == OSD_BENQ 
#define CLEAR_1BIT_COLOR    (((MAIN_BOARDER-1)<<8)|(I_TBLACK<<4)|0x0000)
#define CLEAR_SELECTEDPAGE_BOTTOM_COLOR    (((I_BLACK-1)<<8)|(I_BLACK<<4)|0x0000)

#define MAINMENU_COLOR1    (((MAIN_BOARDER-1)<<8)|(I_BLACK<<4)|0x08|0x0000)
#define MAINMENU_COLOR2    (((MAIN_TITLE-1)<<8)|(I_BENQ_GRAY_3<<4)|0x0000)
#define MAINMENU_TITLE       (((I_WHITE-1)<<8)|(I_BENQ_GRAY_3<<4)|0x0000)
#define MAINMENU_COLOR3    (((MAIN_BOARDER-1)<<8)|(I_TBLACK<<4)|0x08|0x0000)
#define MAINMENU_AND_SELECTPAGE_SEPARATOR   (((MAIN_BOARDER-1)<<8)|(I_BLACK<<4)|0x0000)

// Select Page color
#define SELECTPAGE_4BIT_COLOR1    (((MAIN_BOARDER-1)<<8)|(I_BLACK<<4)|0x0c|0x0000)
#define SELECTPAGE_4BIT_COLOR_BLUE_UPPER    (((SELECT_PAGE_4BIT_COLOR1_BLUE_UPPER-1)<<8)|(I_BLACK<<4)|0x0c|0x0000)
#define SELECTPAGE_4BIT_COLOR_BLUE_LOWER   (((SELECT_PAGE_4BIT_COLOR2_BLUE_LOWER-1)<<8)|(I_BLACK<<4)|0x0c|0x0000)
#define SELECTPAGE_2BIT_COLOR1    (((MAIN_BOARDER-1)<<8)|(I_BLACK<<4)|0x08|0x0000)
#define SELECTPAGE_2BIT_COLOR1_BLUE    (((TOP_PAGE_2BIT_COLOR1_BLUE-1)<<8)|(I_BLACK<<4)|0x08|0x0000)
#define SELECTPAGE_2BIT_COLOR2    (((MAIN_BOARDER-1)<<8)|(I_BENQ_GRAY_3<<4)|0x08|0x0000)
#define SELECTPAGE_2BIT_COLOR3    (((TOP_PAGE_2BIT_COLOR1-1)<<8)|(I_BENQ_GRAY_3<<4)|0x08|0x0000)
#define SELECTPAGE_2BIT_COLOR4    (((MAIN_BOARDER-1)<<8)|(I_BENQ_BLUE_1<<4)|0x08|0x0000)
#define SELECTPAGE_2BIT_COLOR5    (((TOP_PAGE_2BIT_COLOR1_BLUE-1)<<8)|(I_BENQ_GRAY_3<<4)|0x08|0x0000)
#define SELECTPAGE_1BIT_COLOR1    (((I_BLACK-1)<<8)|(I_BENQ_GRAY_3<<4)|0x0000)
#define SELECTPAGE_1BIT_COLOR1_BLUE    (((I_BENQ_GRAY_3-1)<<8)|(I_BENQ_BLUE_1<<4)|0x0000)
#define SELECTPAGE_1BIT_COLOR1_BLACK    (((I_BLACK-1)<<8)|(I_BENQ_BLUE_1<<4)|0x0000)
#define SELECTPAGE_1BIT_COLOR1_WHITE    (((I_WHITE-1)<<8)|(I_BENQ_GRAY_3<<4)|0x0000)


// string separater line
#define StringSeparaterLineColor1     (((I_BENQ_GRAY_8-1)<<8)|(I_TBLACK<<4)|0x0000)
#define StringSeparaterLineColor2     (((I_BENQ_BLUE_1-1)<<8)|(I_TBLACK<<4)|0x0000)
#define StringSeparaterLineColor3     (((I_WHITE-1)<<8)|(I_TBLACK<<4)|0x0000)

// string color
#define UnSelectedStringColor    (((I_BENQ_GRAY_8-1)<<8)|(I_TBLACK<<4)|0x0002)
#define UnSelectedStringColor1    (((I_WHITE-1)<<8)|(I_TBLACK<<4)|0x0000)
#define SelectedStringColor     (((I_TBLACK-1)<<8)|(I_TBLACK<<4)|0x0000)
#define SelectedStringColor1        (((I_BENQ_BLUE_1-1)<<8)|(I_TBLACK<<4)|0x0002)
#define DisabledStringColor    (((I_BENQ_GRAY_2-1)<<8)|(I_TBLACK<<4)|0x0000)

// MainIcon color
#define MAINICON_1BIT_COLOR1  (((I_WHITE-1)<<8)|(I_TBLACK<<4)|0x0000)
#define MAINICON_2BIT_COLOR1  (((MAIN_ICON_2BIT_COLOR1-1)<<8)|(I_TBLACK<<4)|0x08|0x0000)
#define MAINICON_2BIT_COLOR2  (((MAIN_ICON_2BIT_COLOR2-1)<<8)|(I_TBLACK<<4)|0x08|0x0000)
#define MAINICON_2BIT_COLOR3  (((MAIN_ICON_2BIT_COLOR3-1)<<8)|(I_TBLACK<<4)|0x08|0x0000)
#define MAINICON_2BIT_COLOR4  (((MAIN_ICON_2BIT_COLOR4-1)<<8)|(I_TBLACK<<4)|0x08|0x0000)
#define MAINICON_2BIT_COLOR5  (((MAIN_ICON_2BIT_COLOR5-1)<<8)|(I_TBLACK<<4)|0x08|0x0000)

// TopPageIcon color
#define TOPPAGEICON_1BIT_COLOR1  (((I_WHITE-1)<<8)|(I_BENQ_GRAY_3<<4)|0x0000)
#define TOPPAGEICON_1BIT_COLOR1_UnSelected  (((I_BENQ_GRAY_8-1)<<8)|(I_BENQ_GRAY_3<<4)|0x0000)
#define TOPPAGEICON_1BIT_HOOK_COLOR  (((I_BENQ_BLUE_1-1)<<8)|(I_BENQ_GRAY_3<<4)|0x0000)
#define TOPPAGEICON_1BIT_EXIT_COLOR  (((I_TRED-1)<<8)|(I_BENQ_GRAY_3<<4)|0x0000)
#define TOPPAGEICON_1BIT_EXIT_COLOR2  (((I_TRED-1)<<8)|(I_BENQ_BLUE_1<<4)|0x0000)

// Arrow color
#define ArrowColor1        (((I_WHITE-1)<<8)|(I_TBLACK<<4)|0x0000)
#define ArrowColor2        (((I_BENQ_GRAY_8-1)<<8)|(I_TBLACK<<4)|0x0000)

// Triangle color
#define TRIANLE_ICON1_COLOR  (((MAIN_ICON_2BIT_COLOR3-1)<<8)|(I_TBLACK<<4)|0x08|0x0000)
#define TRIANLE_ICON2_COLOR  (((I_BENQ_BLUE_1-1)<<8)|(I_TBLACK<<4)|0x0000)
#define TRIANLE_ICON3_COLOR  (((I_BENQ_BLUE_1-1)<<8)|(I_TBLACK<<4)|0x0000)

// Layer Separator color
#define LayerSeparatorColor        (((I_BENQ_BLUE_1-1)<<8)|(I_TBLACK<<4)|0x0000)

// Top Page menu color
#define TOPPAGE_2BIT_COLOR1        (((TOP_PAGE_2BIT_COLOR1-1)<<8)|(I_BLACK<<4)|0x08|0x0000)
#define TOPPAGE_2BIT_COLOR2        (((TOP_PAGE_2BIT_COLOR2-1)<<8)|(I_BENQ_GRAY_3<<4)|0x08|0x0000)
#define TOPPAGE_2BIT_COLOR3        (((TOP_PAGE_2BIT_COLOR3-1)<<8)|(I_BENQ_GRAY_3<<4)|0x08|0x0000)

// Top Page menu Blue color
#define TOPPAGE_2BIT_COLOR1_BLUE        (((TOP_PAGE_2BIT_COLOR1_BLUE-1)<<8)|(I_BLACK<<4)|0x08|0x0000)
#define TOPPAGE_2BIT_CROSS_COLOR1_BLUE        (((TOP_PAGE_2BIT_COLOR2_BLUE-1)<<8)|(I_BENQ_GRAY_3<<4)|0x08|0x0000)
#define TOPPAGE_2BIT_CROSS_COLOR2_BLUE        (((TOP_PAGE_2BIT_COLOR3_BLUE-1)<<8)|(I_BENQ_BLUE_1<<4)|0x08|0x0000)
#define TOPPAGE_2BIT_COLOR3_BLUE        (((TOP_PAGE_2BIT_COLOR2-1)<<8)|(I_BENQ_BLUE_1<<4)|0x08|0x0000)
#define TOPPAGE_1BIT_COLOR1_BLUE        (((I_TBLACK-1)<<8)|(I_BENQ_BLUE_1<<4)|0x0000)

// Dialog icon color
#define DialogIconColor1     (((I_BENQ_BLUE_1-1)<<8)|(I_TBLACK<<4)|0x0002)

// Dialog Triangle icon color
#define DialogTriangleColor1     (((MAIN_ICON_2BIT_COLOR3-1)<<8)|(I_TBLACK<<4)|0x08|0x0002)
#define DialogTriangleColor2     (((I_TBLACK-1)<<8)|(I_BENQ_BLUE_1<<4)|0x0000)
#define DialogTriangleColor3     (((I_BENQ_BLUE_1-1)<<8)|(I_TBLACK<<4)|0x0002)


// For string color index 256
#define UnSelectedStringColor_256    (((I_BENQ_GRAY_8-1)<<8)|(I_TBLACK<<4)|0x04|0x0002)
#define DisabledStringColor_256    (((I_BENQ_GRAY_2-1)<<8)|(I_TBLACK<<4)|0x04|0x0002)
#define UnSelectedStringColor1_256    (((I_WHITE-1)<<8)|(I_TBLACK<<4)|0x04|0x0002)
#define SelectedStringColor_256     (((I_TBLACK-1)<<8)|(I_TBLACK<<4)|0x04|0x0002)
#define SelectedStringColor1_256        (((I_BENQ_BLUE_1-1)<<8)|(I_TBLACK<<4)|0x04|0x0002)

// Hook Icon color
#define HookIconColor1_256    (((I_BENQ_GRAY_8-1)<<8)|(I_TBLACK<<4)|0x04|0x0000)
#define HookIconColor2_256    (((I_WHITE-1)<<8)|(I_TBLACK<<4)|0x04|0x0000)
#define HookIconColor3_256    (((I_TBLACK-1)<<8)|(I_TBLACK<<4)|0x04|0x0000)

// Slider Bar color
#define SLIDER_BAR_4BIT_COLOR_BLUE    (((SLIDERBAR_4BIT_COLOR_BLUE-1)<<8)|(I_TBLACK<<4)|0x0c|0x0000)
#define SLIDER_BAR_4BIT_COLOR_RED    (((SLIDERBAR_4BIT_COLOR_RED-1)<<8)|(I_TBLACK<<4)|0x0c|0x0000)
#define SLIDER_BAR_4BIT_COLOR_GREEN    (((SLIDERBAR_4BIT_COLOR_GREEN-1)<<8)|(I_TBLACK<<4)|0x0c|0x0000)
#define SLIDER_BAR_4BIT_COLOR_GRAY    (((SLIDERBAR_4BIT_COLOR_GRAY-1)<<8)|(I_TBLACK<<4)|0x0c|0x0000)

#define SLIDER_BAR_2BIT_BLANK_COLOR   (((SLIDERBAR_2BIT_BLANK_COLOR-1)<<8)|(I_TBLACK<<4)|0x08|0x0000)
#define SLIDER_BAR_2BIT_FULL_COLOR_BLUE    (((SLIDERBAR_2BIT_FULL_COLOR_BLUE-1)<<8)|(I_TBLACK<<4)|0x08|0x0000)
#define SLIDER_BAR_2BIT_FULL_COLOR_RED    (((SLIDERBAR_2BIT_FULL_COLOR_RED-1)<<8)|(I_TBLACK<<4)|0x08|0x0000)
#define SLIDER_BAR_2BIT_FULL_COLOR_GREEN    (((SLIDERBAR_2BIT_FULL_COLOR_GREEN-1)<<8)|(I_TBLACK<<4)|0x08|0x0000)
#define SLIDER_BAR_2BIT_FULL_COLOR_GRAY    (((SLIDERBAR_2BIT_FULL_COLOR_GRAY-1)<<8)|(I_TBLACK<<4)|0x08|0x0000)

#define SLIDER_BAR_2BIT_BOARDER_COLOR    (((SLIDERBAR_2BIT_BOARDER_COLOR-1)<<8)|(I_TBLACK<<4)|0x08|0x0000)

// Number color
#define NumberColor1     (((I_WHITE-1)<<8)|(I_TBLACK<<4)|0x04|0x0000)
#define NumberColor2     (((I_TBLACK-1)<<8)|(I_BENQ_BLUE_1<<4)|0x04|0x0000)
#define NumberColor3     (((I_BENQ_GRAY_8-1)<<8)|(I_TBLACK<<4)|0x04|0x0000)

// Notice icon color
#define NoticeIconColor     (((I_WHITE-1)<<8)|(I_TBLACK<<4)|0x0000)

#define NoticeStringColor     (((I_WHITE-1)<<8)|(I_TBLACK<<4)|0x04|0x0000)





// string color
#define StringColor1        (((I_BENQ_BLUE_1-1)<<8)|(I_TBLACK<<4)|0x0002)
#define StringColor2        (((I_WHITE-1)<<8)|(I_TBLACK<<4)|0x0002)
#define StringColor3        (((I_TBLACK-1)<<8)|(I_TBLACK<<4)|0x0002)

#define StringColor1_256        (((I_BENQ_BLUE_1-1)<<8)|(I_TBLACK<<4)|0x04|0x0002)










#endif  


#define IsOSDUpdTmg() ((ucOSDFlags&OSDFLAG_UPD_TMG) != 0)
#define IsOSDUpdUsr() ((ucOSDFlags&OSDFLAG_UPD_USR) != 0)
#define IsOSDUpdCal() ((ucOSDFlags&OSDFLAG_UPD_CAL) != 0)
#define IsOSDUpdSys() ((ucOSDFlags&OSDFLAG_UPD_SYS) != 0)
#define IsOSDNoSync() ((ucOSDFlags&OSDFLAG_NOSYNC) != 0)
#define IsOSDSysInit() ((ucOSDFlags&OSDFLAG_SYSINIT) != 0)

#define SetOSDUpdTmgFlag() {ucOSDFlags |= OSDFLAG_UPD_TMG;}
#define SetOSDUpdUsrFlag() {ucOSDFlags |= OSDFLAG_UPD_USR;}
#define SetOSDUpdCalFlag() {ucOSDFlags |= OSDFLAG_UPD_CAL;}
#define SetOSDUpdSysFlag() {ucOSDFlags |= OSDFLAG_UPD_SYS;}
#define SetOSDNoSyncFlag() {ucOSDFlags |= OSDFLAG_NOSYNC;}
#define SetOSDSysInitFlag() {ucOSDFlags |= OSDFLAG_SYSINIT;}

#define ClearOSDUpdTmgFlag() {ucOSDFlags &= ~OSDFLAG_UPD_TMG;}
#define ClearOSDUpdUsrFlag() {ucOSDFlags &= ~OSDFLAG_UPD_USR;}
#define ClearOSDUpdCalFlag() {ucOSDFlags &= ~OSDFLAG_UPD_CAL;}
#define ClearOSDUpdSysFlag() {ucOSDFlags &= ~OSDFLAG_UPD_SYS;}
#define ClearOSDNoSyncFlag() {ucOSDFlags &= ~OSDFLAG_NOSYNC;}
#define ClearOSDSysInitFlag() {ucOSDFlags &= ~OSDFLAG_SYSINIT;}
#define ClearOSDUpdFlag() { \
    ucOSDFlags &= ~(OSDFLAG_UPD_TMG|OSDFLAG_UPD_USR|OSDFLAG_UPD_CAL|OSDFLAG_UPD_SYS); \
}
#define ClearOSDAllFlag() {ucOSDFlags = 0x00;}

enum _StringSeparatorLayer {
    STRING_LAYER_1,
    STRING_LAYER_2,
    STRING_LAYER_3,
    STRING_LAYER_4,
    DIALOG_LAYER,
};

enum _TriangleMethod {
    TRIANGLE_METHOD1,
    TRIANGLE_METHOD2,
    TRIANGLE_METHOD3,
    TRIANGLE_CLEAR,
};

enum _TopPageIcon {
    TP_PICTUREMODE,
    TP_DISPLAYMODE,
    TP_BRIGHTNESS,
    TP_CONTRAST,
    TP_AUTOADJUSTMENT,
    TP_INPUT,
    //ULEric140402
    TP_VOLUME,
    TP_MUTE,
    TP_LOWBLUELIGHT,
    TP_SMARTREMINDER,
    TP_MENU,
    TP_EXIT
};

enum _FrameWidthType {
    FrameWidthType_MainMenu,
    FrameWidthType_CustomerMenu1,
    FrameWidthType_CustomerMenu2,
    FrameWidthType_DialogMenu1,//ULEric140410
};

enum {
    OSDFLAG_UPD_TMG = 0x01,
    OSDFLAG_UPD_USR = 0x02,
    OSDFLAG_UPD_CAL = 0x04,
    OSDFLAG_UPD_SYS = 0x08,
    OSDFLAG_NOSYNC  = 0x10,
    OSDFLAG_SYSINIT = 0x80,
};

#define IsOSDUpdTmg() ((ucOSDFlags&OSDFLAG_UPD_TMG) != 0)
#define IsOSDUpdUsr() ((ucOSDFlags&OSDFLAG_UPD_USR) != 0)
#define IsOSDUpdCal() ((ucOSDFlags&OSDFLAG_UPD_CAL) != 0)
#define IsOSDUpdSys() ((ucOSDFlags&OSDFLAG_UPD_SYS) != 0)
#define IsOSDNoSync() ((ucOSDFlags&OSDFLAG_NOSYNC) != 0)
#define IsOSDSysInit() ((ucOSDFlags&OSDFLAG_SYSINIT) != 0)

#define SetOSDUpdTmgFlag() {ucOSDFlags |= OSDFLAG_UPD_TMG;}
#define SetOSDUpdUsrFlag() {ucOSDFlags |= OSDFLAG_UPD_USR;}
#define SetOSDUpdCalFlag() {ucOSDFlags |= OSDFLAG_UPD_CAL;}
#define SetOSDUpdSysFlag() {ucOSDFlags |= OSDFLAG_UPD_SYS;}
#define SetOSDNoSyncFlag() {ucOSDFlags |= OSDFLAG_NOSYNC;}
#define SetOSDSysInitFlag() {ucOSDFlags |= OSDFLAG_SYSINIT;}

#define ClearOSDUpdTmgFlag() {ucOSDFlags &= ~OSDFLAG_UPD_TMG;}
#define ClearOSDUpdUsrFlag() {ucOSDFlags &= ~OSDFLAG_UPD_USR;}
#define ClearOSDUpdCalFlag() {ucOSDFlags &= ~OSDFLAG_UPD_CAL;}
#define ClearOSDUpdSysFlag() {ucOSDFlags &= ~OSDFLAG_UPD_SYS;}
#define ClearOSDNoSyncFlag() {ucOSDFlags &= ~OSDFLAG_NOSYNC;}
#define ClearOSDSysInitFlag() {ucOSDFlags &= ~OSDFLAG_SYSINIT;}
#define ClearOSDUpdFlag() { \
    ucOSDFlags &= ~(OSDFLAG_UPD_TMG|OSDFLAG_UPD_USR|OSDFLAG_UPD_CAL|OSDFLAG_UPD_SYS); \
}
#define ClearOSDAllFlag() {ucOSDFlags = 0x00;}

typedef enum _AOCPIPTYPE_ {
    AOCPIP_TYPE_OFF ,
    AOCPIP_TYPE_PIP ,
    AOCPIP_TYPE_SBS,
    NUM_AOCPIPTYPE,
} AOCPIPType;

typedef enum _AOCPIPPOSITION_ {
    AOCPIP_RT,
    AOCPIP_RB,
    NUM_AOCPIPPOSITION,
} AOCPIPPOSITION;

typedef enum _AOCPIPSIZE_ {
    AOCPIP_SIZE_SMALL,
    AOCPIP_SIZE_MIDDLE,
    AOCPIP_SIZE_LARGE,
    NUM_AOCPIPSIZE,
} AOCPIPSIZE;

extern xdata UCHAR ucOSDFlags;
extern UCHAR ucLayer1StringInfoTb[];
extern UCHAR ucLayer2ItmNumTb[];
extern UCHAR ucLayer2ItemInfoTb[];
extern xdata UCHAR ucSubMenuType;
extern xdata UCHAR ucLayer3MenuType;
extern xdata UCHAR ucCustomerKeyType;
extern BOOL IsPage2;
extern UCHAR ucMenuAction;
extern BOOL bSelNum;
//extern BOOL  ClrLayer4Flags;
extern xdata UCHAR ucMenuType;
extern xdata USHRT usOSDMovingX,usOSDMovingY;

#define OSDFocusItm11 OSDFocusAuto
#define OSDFocusFunc1 OSDFocus3DCnv
#define OSDFuncDown1  OSD2Dto3DFmtDown
#define OSDFuncUp1    OSD2Dto3DFmtUp
#define OSDFocusFunc2 OSDFocus2Dto3DAdpt
#define OSDFuncDown2  OSD2Dto3DAdptDown
#define OSDFuncUp2    OSD2Dto3DAdptUp
#define OSDFocusFunc3 OSDFocus2Dto3DDepth
#define OSDFuncDown3  OSD2Dto3DDepthDown
#define OSDFuncUp3    OSD2Dto3DDepthUp
#define OSDFocusFunc4 OSDFocus2Dto3DView
#define OSDFuncDown4  OSD2Dto3DViewDown
#define OSDFuncUp4    OSD2Dto3DViewUp
#define OSDFocusFunc5 OSDFocus3DLRSwap
#define OSDFuncDown5  OSD3DLRSwapDown
#define OSDFuncUp5    OSD3DLRSwapUp
#define OSDFocusFunc6 OSDFocus3DTo2D
#define OSDFuncDown6  OSD3DTo2DDown
#define OSDFuncUp6    OSD3DTo2DUp
///////////////////////////////////////////////////
enum {
    CHINESE_TABLE = 0xf0,
    COMMON_TABLE = 0xf1
};


//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************

extern void OSDShowHook(UCHAR id, UCHAR CustomerKey);
void OSDShowTopPageIcon(UCHAR id, UCHAR sel, UCHAR CustomerKey);
void OSDShowClrTmpMenu(UCHAR id);
extern void OSDShowMainMenuStrings(void);
extern void OSDLangueSlecetReload(void);
extern void OSDShowDialog(UCHAR dlg, UCHAR keyID);
extern void OSDShowSourceIcon(UCHAR id, UCHAR Source);
extern void OSDCloseMainMenu(void);
extern void OSDSelectDialogItem(UCHAR id, UCHAR isUp);
extern void OSDSelectLayer1Item(UCHAR id);
extern void OSDSelectLayer2Item(UCHAR id, BOOL isUp);
extern void OSDSelectLayer3Item(UCHAR id);
extern void OSDShowFuncItems(void);
extern void OSDSelectFuncItem(UCHAR id);
extern void OSDFocusRGain(void);
extern void OSDFocusGGain(void);
extern void OSDFocusBBain(void);
extern void OSDFocusOSDHPos(void);
extern void OSDFocusOSDVPos(void);
extern void OSDFocusOSDTran(void);
extern void OSDFocusTimer(void);
extern void OSDFocusOSDRotation(void);
extern void OSDFocusLang(void);
extern void OSDFocusMute(void);
extern void OSDFocusDCR(void);
extern void OSDFocusAspRatio(void);
extern void OSDFocusOD(void);
extern void OSDShowResolution(UCHAR x, UCHAR y);
//extern void OSDShowOSDRotation(UCHAR redraw);
extern void OSDShowLang(UCHAR redraw);
extern void OSDShowMute(UCHAR redraw);
extern void OSDShowDCR(UCHAR redraw);
extern void OSDShowAspRatio(UCHAR redraw);
extern void OSDShowReset(UCHAR redraw);
extern void OSDTransparentUp(void);
extern void OSDTransparentDown(void);
extern void OSDTimeoutUp(void);
extern void OSDTimeoutDown(void);
extern void OSDRotationUp(void);
extern void OSDRotationDown(void);
extern void OSDLanguageUp(void);
extern void OSDLanguageDown(void);
extern void OSDAudioMuteUp(void);
extern void OSDAudioMuteDown(void);
extern void OSD2Dto3DFmtDown(void);
extern void OSD2Dto3DFmtUp(void);
extern void OSD2Dto3DAdptDown(void);
extern void OSD2Dto3DAdptUp(void);
extern void OSD2Dto3DDepthDown(void);
extern void OSD2Dto3DDepthUp(void);
extern void OSD2Dto3DViewDown(void);
extern void OSD2Dto3DViewUp(void);
extern void OSD3DLRSwapDown(void);
extern void OSD3DLRSwapUp(void);
extern void OSD3DTo2DDown(void);
extern void OSD3DTo2DUp(void);
extern void OSDShowSourceMenu(void);
extern void OSDSelectLayer4Item(UCHAR id ,UCHAR ucOSDLay4langState);
extern void OSDUnSelectLBLLayer4Item(UCHAR id);
extern void OSDSelectLBLLayer4Item(UCHAR id);
extern void OSDShowInfo(void);
extern void ClrLayer4(void);//Justin 140326
#endif //__OSD_VIEW_H__
