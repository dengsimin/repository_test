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
    OSD_RESET_WIN,
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
#if ENABLE_ERGONOMICS == ON
    OSD_MAIN_ERGONOMICS,
#endif
#if ENABLE_ECO_SENSOR == ON
    OSD_MAIN_ECO,
#endif   
    NUM_OSD_MAIN
};

enum {
#if ENABLE_OSD_ANALOG_FUNCTION == OFF
#if ENABLE_AUTO_POVIT_FUNC == ON  
    OSD_DISPLAY_PIVOT,
#endif
    OSD_DISPLAY_INPUT,

#else
    OSD_DISPLAY_ADJUST,
#if ENABLE_AUTO_POVIT_FUNC == ON  
    OSD_DISPLAY_PIVOT,
#endif
    OSD_DISPLAY_INPUT,
    OSD_DISPLAY_HPOS,
    OSD_DISPLAY_VPOS,
    OSD_DISPLAY_PIXELCLK,
    OSD_DISPLAY_PHASE,
#endif
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
#if MD_ENABLE_OVERSCAN == ON            
    OSD_PICTURE_AD_OVERSCAN,
#endif    
    OSD_PICTURE_AD_DISMODE,
#if ENABLE_SMART_SCALING == ON
    OSD_PICTURE_AD_SMARTSCALING,
#endif 
#if ENABLE_COLOR_FORMAT == ON
    OSD_PICTURE_AD_COLORFORMAT,
#endif    
    OSD_PICTURE_AD_PCRANGE,
    OSD_PICTURE_AD_NUM,
};

enum {
    OSD_AUDIO_VOLUME,
    OSD_AUDIO_MUTE,
#if ENABLE_AUDIO_SELECT == ON        
    OSD_AUDIO_SELECT,
#endif    
    OSD_AUDIO_NUM,    
};

enum {
    OSD_SYS_OSDSET,
    OSD_SYS_CTKEY1,
    OSD_SYS_CTKEY2,
    OSD_SYS_CTKEY3,
    OSD_SYS_DDCCI,
#if ENABLE_DPHDMI_AUTO_SWITCH == ON    
    OSD_SYS_DPASWITCH,
#endif    
    OSD_SYS_DISPLAYPORT, 
#if ENABLE_DPHDMI_AUTO_SWITCH == ON    
    OSD_SYS_HDASWITCH,
#endif    
    OSD_SYS_AUTO_POWEROFF,    
    OSD_SYS_RES,
    OSD_SYS_INFORMATION,
    OSD_SYS_RECALL,
    OSD_SYS_NUM,    
};

enum {
    OSD_SYS_OSDSET_LANG,
    OSD_SYS_OSDSET_TIMER,
    OSD_SYS_OSDSET_OSDLOCK,
};

enum {
    OSD_SYS_INFORMATION_INPUT,
    OSD_SYS_INFORMATION_CURR_RES,
    OSD_SYS_INFORMATION_OPT_RES,
#if ENABLE_OSD_SHOW_MODELNAME == ON
    OSD_SYS_INFORMATION_MODELNAME,
#endif    
    NUM_OSD_SYS_INFORMATION,
};

#if ENABLE_EYE_PROTECT == ON
enum {
#if ENABLE_EYE_PROTECT == ON
    OSD_ERGONOMICS_EYE_PROTECT,
    OSD_ERGONOMICS_EYE_PROTECT_METER,
#endif    
    OSD_ERGONOMICS_REMIDER,
    OSD_ERGONOMICS_TIME,
    OSD_ERGONOMICS_DURATION,
    OSD_ERGONOMICS_NUM,
};
#endif
#if ENABLE_ECO_SENSOR == ON
enum {
    OSD_ECO_SENSOR,
    OSD_ECO_SENSOR_METER,
    OSD_ECO_SENSOR_RANGE,
    OSD_ECO_NUM,
};
#endif

//ULEric140403
enum {
    TopArrowType,
    MiddleArrowType,    
    LastArrowType,
    ClearArrowType,
};

enum {
    MainIcon_Display,
    MainIcon_Picture,
    MainIcon_PictureAdvance,
    MainIcon_Audio,
    MainIcon_System,
    MainIcon_Ergonomics,
    MainIcon_ECO,
};

enum {
    PrePage_Arrow,  //Up
    PrePage_Arrow1,  //Up1
    NextPage_Arrow, //Down   
};

enum {
    LAYER3_PAGE_1,
    LAYER3_PAGE_2,
    CUSKEY_PAGE_1,
    CUSKEY_PAGE_2,
};
enum{
    LAYER4_LANGUAGE,
    LAYER4_TIMER,
    LAYER4_DUALVIEW,
};
#define SPACE_CHAR          0x00
#define OSD_SP_WIDTH   18//41
#define OSD_SP_HEIGHT  21 // 4
//ECO
#define OSD_ECO_METER_WIDTH         13
#define OSD_ECO_METER_HEIGHT        9
//EYE
#define OSD_EYE_PRO_METER_WIDTH         13
#define OSD_EYE_PRO_METER_HEIGHT        9

#define OSD_EPM_WIN_H_START         40
#define OSD_EPM_WIN_H_END           47
#define OSD_EPM_WIN_V_START         112
#define OSD_EPM_WIN_V_END           125

//=============================//
//======== Custom Menu ========//
//=============================//
//Big
#define OSD_CUSTOMERKEY_MENU1_TOTAL_WIDTH   (OSD_CUSTOMERKEY_MENU1_WIDTH+DIALOG_POSITION_OFFSET*2)//53
#define OSD_CUSTOMERKEY_MENU1_TOTAL_HEIGHT  (OSD_CUSTOMERKEY_MENU1_HEIGHT)//35
#define OSD_CUSTOMERKEY_MENU1_WIDTH     44
#define OSD_CUSTOMERKEY_MENU1_HEIGHT    31
#define OSD_CUSTOM_TOP_BAR_HEIGHT       3
#define OSD_CUSTOM_TOP_BAR_STR_POSX     DIALOG_POSITION_OFFSET+3   //9

#define DIALOG_POSITION_OFFSET      8//6//OSD_POSITION_OFFSET//6


#define DIALOG_LAYER_POSX           8+DIALOG_POSITION_OFFSET
#define DIALOG_LAYER_POSY           6
#define DIALOG_LAYER_STR_LENGTH     25//17
#define DIALOG_LAYER_WIN_WIDTH      27//17
#define DIALOG_LAYER_WIN_HEIGHT     25//17
#define DIALOG_LAYER_WIDTH          41//40
#define DIALOG_LAYER_HEIGHT         27

#define DIALOG_STR_OFFSET_Y         LAYER_STR_OFFSET_Y
#define DIALOG_ICON_OFFSET_X        3
#define DIALOG_STR_OFFSET_FROM_ICON 3//4
#define DIALOG_ICON_WIDTH           3

#define DIALOG_ICON_POSX        DIALOG_POSITION_OFFSET+DIALOG_ICON_OFFSET_X   //9
#define DIALOG_ICON_POSY        OSD_CUSTOM_TOP_BAR_HEIGHT+2  //5
#define DIALOG_STR_POSX         DIALOG_ICON_POSX+DIALOG_ICON_WIDTH+DIALOG_STR_OFFSET_FROM_ICON+1   //17
#define DIALOG_STR_POSY         DIALOG_ICON_POSY+1       //
#define DIALOG_SEP_POSX         DIALOG_STR_POSX 
#define DIALOG_SEP_POSY         DIALOG_STR_POSY+1 
#define DIA_TITLE_STR_POSX      DIALOG_ICON_OFFSET_X+DIALOG_POSITION_OFFSET
#define DIA_TITLE_STR_POSY      1
#define DIA_TITLE_STR_LENGTH    17//DIALOG_LAYER_STR_LENGTH

#define DIA_TRIANICON_POSX_START    (DIALOG_POSITION_OFFSET+DIALOG_ICON_OFFSET_X+DIALOG_ICON_WIDTH+DIALOG_STR_OFFSET_FROM_ICON)//15
#define DIA_TRIANICON_POSY_START    5
#define DIA_TRIANICON_POSY_END      7

#define DIALOG_HOOK_POSX   DIALOG_STR_POSX+DIALOG_LAYER_STR_LENGTH-1 
#define DIALOG_HOOK_POSY   DIALOG_STR_POSY 

#define DIA_PRE_PAGE_ARROW_POSX     29
#define DIA_PRE_PAGE_ARROW_POSY     4
#define DIA_Next_PAGE_ARROW_POSX    29
#define DIA_Next_PAGE_ARROW_POSY    28//27

#define DIA_PRE_PAGE_ARROW_POSX1     26
#define DIA_PRE_PAGE_ARROW_POSY1     4
#define DIA_Next_PAGE_ARROW_POSX1    26
#define DIA_Next_PAGE_ARROW_POSY1    28//27

//Slider Menu
#define OSD_CUSTOMERKEY_MENU2_TOTAL_WIDTH   42//(OSD_CUSTOMERKEY_MENU2_WIDTH+OSD_POSITION_OFFSET*2)
#define OSD_CUSTOMERKEY_MENU2_TOTAL_HEIGHT  31//(OSD_CUSTOMERKEY_MENU2_HEIGHT+5)
#define OSD_CUSTOMERKEY_MENU2_WIDTH     26//25//22
#define OSD_CUSTOMERKEY_MENU2_HEIGHT    30//23

#define DIALOG2_POSITION_OFFSET      8//6//OSD_POSITION_OFFSET//6
#define DIALOG2_ICON_POSX           DIALOG2_POSITION_OFFSET+DIALOG_ICON_OFFSET_X
#define DIALOG2_ICON_POSY           DIALOG_ICON_POSY  //5

#define DIA2_TRIANICON_POSX_START    (DIALOG2_POSITION_OFFSET+DIALOG_ICON_OFFSET_X+DIALOG_ICON_WIDTH+DIALOG_STR_OFFSET_FROM_ICON)
#define DIA2_TRIANICON_POSY_START    5
#define DIA2_TRIANICON_POSY_END      7

#define DIA2_SLIDER_BAR_POSX        DIA2_TRIANICON_POSX_START+5    
#define DIA2_SLIDER_BAR_POSY        23//18
#define DIA2_SLIDER_BAR_NUM_POSX    DIA2_SLIDER_BAR_POSX
#define DIA2_SLIDER_BAR_NUM_POSY    DIA2_TRIANICON_POSY_START+1//6

#define DIA2_LAYER_WIN_WIDTH      11//17
#define DIA2_LAYER_WIN_HEIGHT     25//17
//=============================//
//======= Pop-Up Dialog =======//
//=============================//
#define OSD_DIALOG_SELECTPAGE_WIDTH    38//ULEric140410
#define OSD_DIALOG_SELECTPAGE_HEIGHT   23//ULEric140410
#define OSD_DIALOG_SELECTPAGE_TOTAL_WIDTH    (OSD_DIALOG_SELECTPAGE_WIDTH+OSD_POSITION_OFFSET*2)//51
#define OSD_DIALOG_SELECTPAGE_TOTAL_HEIGHT   44//23
#define OSD_DIALOG_WIDTH    33//31
#define OSD_DIALOG_HEIGHT   7

//=============================//
//========= Select Page =======
//=============================//
#define OSD_CUSTOM_MENU1_SP_POSX    52//6//1
#define OSD_CUSTOM_MENU1_SP_POSY    10//31
#define OSD_CUSTOM_MENU2_SP_POSX    34//0
#define OSD_CUSTOM_MENU2_SP_POSY    10//31
#define OSD_CUSTOM_MENU3_SP_POSX    89//0
#define OSD_CUSTOM_MENU3_SP_POSY    (OSD_MAIN_TOTAL_HEIGHT/3)//31
#define OSD_DIALOG_SP_POSX           4
#define OSD_DIALOG_SP_POSY           0
#define OSD_DIALOG1_SP_POSX         38
#define OSD_DIALOG1_SP_POSY          0

//=============================//
//========= Main Menu =========//
//=============================//
#define OSD_SPICON_WIDTH  18//8
#define OSD_SPICON1_WIDTH 8

#define OSD_SPOFFSET_BOTTOM    49
#define OSD_SPOFFSET_ROTATE    0
#define OSD_MAIN_TOTAL_WIDTH    97
#define OSD_MAIN_TOTAL_HEIGHT   31//35
#define OSD_MAIN_WIDTH      85//95//69
#define OSD_MAIN_HEIGHT     31//35//23
#define OSD_POSITION_OFFSET 4//6
#define OSD_MAX_LINES       8
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
#define OSD_MAIN_TOP_BAR_HEIGHT         3
#define OSD_MAIN_BOTTOM_BORDER_HEIGHT   1
#define OSD_TITLESTR_OFFSET_X   3
//Page Arrow
#define PRE_PAGE_ARROW_POSX     38//37 39
#define PRE_PAGE_ARROW_POSY     3
#define Next_PAGE_ARROW_POSX    PRE_PAGE_ARROW_POSX//37
#define Next_PAGE_ARROW_POSY    28//27
#define LAYER2_PAGE_ARROW_POX   PRE_PAGE_ARROW_POSX
#define LAYER3_PAGE_ARROW_POX   (LAYER2_PAGE_ARROW_POX+LAYER2_LENGTH+OFFSET_BETWEEN_LAYER)//59
#define LAYER4_PAGE_ARROW_POX   (LAYER3_PAGE_ARROW_POX+LAYER3_LENGTH+OFFSET_BETWEEN_LAYER)//79

#define LAYER_STR_HEIGHT    (Next_PAGE_ARROW_POSY-PRE_PAGE_ARROW_POSY)//24
#define LAYER_ITEM_HEIGHT   (OSD_MAIN_HEIGHT-OSD_MAIN_TOP_BAR_HEIGHT-OSD_MAIN_BOTTOM_BORDER_HEIGHT)//27
#define LAYER_BOTTOM_POSY   (OSD_MAIN_HEIGHT-OSD_MAIN_BOTTOM_BORDER_HEIGHT) //
//Separater line position and length
//    L1     L2     L3     L4
// 3  21  2  17  2  17  2  17  3
#define OFFSET_BETWEEN_LAYER    2
#define LAYER_STR_OFFSET_X      1
#define LAYER_STR_OFFSET_Y      3
#define LAYER_POSY          3
#define LAYER1_POSX         3+OSD_POSITION_OFFSET //9
#define LAYER1_LENGTH       21
#define LAYER2_POSX         LAYER1_POSX+LAYER1_LENGTH+OFFSET_BETWEEN_LAYER //32
#define LAYER2_LENGTH       17
#define LAYER3_POSX         LAYER2_POSX+LAYER2_LENGTH+OFFSET_BETWEEN_LAYER //51
#define LAYER3_LENGTH       17
#define LAYER4_POSX         LAYER3_POSX+LAYER3_LENGTH+OFFSET_BETWEEN_LAYER //70
#define LAYER4_LENGTH       17

#define LAYER_STR_POSY  6
#define LAYER1_STR_POX  (LAYER1_POSX+3+LAYER_STR_OFFSET_X) //3+6+1
//#define LAYER2_STR_POX  (LAYER2_POSX+LAYER_STR_OFFSET_X) //9+21+2+1
//#define LAYER3_STR_POX  (LAYER3_POSX+LAYER_STR_OFFSET_X) //
//#define LAYER4_STR_POX  (LAYER4_POSX+LAYER_STR_OFFSET_X)
#define LAYER_SEP_POSY  LAYER_STR_POSY+1
//Hook
#define HOOK_LAYER3_OFFSET_X   (LAYER3_LENGTH-1)  
#define HOOK_LAYER4_OFFSET_X   (LAYER4_LENGTH-1)    
#define HOOK_OFFSET_Y           LAYER_STR_OFFSET_Y
//Trian Icon
#define TRIANICON_POSX_START    29//31
#define TRIANICON_POSY_START    5
#define TRIANICON_POSY_END      7
#define Line0_Offset            0
#define Line1_Offset            17//14
#define Line2_Offset            34//28
#define LAYER2_TRI_POX          TRIANICON_POSX_START                              //31
#define LAYER3_TRI_POX          (LAYER2_TRI_POX+Line1_Offset+OFFSET_BETWEEN_LAYER)//50
#define LAYER4_TRI_POX          (LAYER3_TRI_POX+Line2_Offset+OFFSET_BETWEEN_LAYER)//69
//Slider
#define OSD_SLIDER_BAR_POSX     LAYER3_POSX+8
#define OSD_SLIDER_BAR_POSY     23//18
#define OSD_SLIDER_BAR_NUM_POSX LAYER3_POSX+8
#define OSD_SLIDER_BAR_NUM_POSY 8//5
#define SLIDE_BAR_HEIGHT        12//10
#define OSD_LAYER4_SLIDER_BAR_POSX     LAYER4_POSX+8
#define OSD_LAYER4_SLIDER_BAR_POSY     23//18
#define OSD_LAYER4_SLIDER_BAR_NUM_POSX LAYER4_POSX+8
#define OSD_LAYER4_SLIDER_BAR_NUM_POSY 8//5


#define OSD_RGAIN_SLIDER_BAR_POSX     LAYER4_POSX+4
#define OSD_RGAIN_SLIDER_BAR_POSY     OSD_SLIDER_BAR_POSY
#define OSD_RGAIN_SLIDER_BAR_NUM_POSX OSD_RGAIN_SLIDER_BAR_POSX//LAYER4_POSX+4
#define OSD_RGAIN_SLIDER_BAR_NUM_POSY OSD_SLIDER_BAR_NUM_POSY
#define OSD_GGAIN_SLIDER_BAR_POSX     OSD_RGAIN_SLIDER_BAR_POSX+4
#define OSD_GGAIN_SLIDER_BAR_POSY     OSD_SLIDER_BAR_POSY
#define OSD_GGAIN_SLIDER_BAR_NUM_POSX OSD_GGAIN_SLIDER_BAR_POSX
#define OSD_GGAIN_SLIDER_BAR_NUM_POSY OSD_SLIDER_BAR_NUM_POSY
#define OSD_BGAIN_SLIDER_BAR_POSX     OSD_GGAIN_SLIDER_BAR_POSX+4
#define OSD_BGAIN_SLIDER_BAR_POSY     OSD_SLIDER_BAR_POSY
#define OSD_BGAIN_SLIDER_BAR_NUM_POSX OSD_BGAIN_SLIDER_BAR_POSX
#define OSD_BGAIN_SLIDER_BAR_NUM_POSY OSD_SLIDER_BAR_NUM_POSY

//Senseye Demo
#define OSD_SENSEYE_DEMO_WIDTH  46
#define OSD_SENSEYE_DEMO_HIGHT  1

//OSD position
#if ModelName == BENQ_BL2720PT_DEMO_FD //For debug
#define OSD_MAIN_TOP_MENU_H_POSITION    1970*0.5//1860//2368//ULEric140410
#define OSD_MAIN_TOP_MENU_V_POSITION    1368*0.5//1300//ULEric140410

#define OSD_MAIN_MENU_H_POSITION        1384*0.5
#define OSD_MAIN_MENU_V_POSITION        810*0.5
#define ROT_OSD_MAIN_MENU_H_POSITION    1964*0.5
#define ROT_OSD_MAIN_MENU_V_POSITION    276*0.5//810

#define OSD_HOTKEY_MENU_H_POSITION  1900*0.5
#define OSD_HOTKEY_MENU_V_POSITION  810*0.5
#define OSD_HOTKEY_BAR_H_POSITION   1966*0.5
//Rotate OSD position
#define ROT_OSD_HOTKEY_MENU_H_POSITION  1964*0.5//1900
#define ROT_OSD_HOTKEY_MENU_V_POSITION  810*0.5//810
#define ROT_OSD_HOTKEY_BAR_H_POSITION   1964*0.5//1966
#define ROT_OSD_HOTKEY_BAR_V_POSITION   948*0.5//1966
#define ROT_OSD_DIA_RESET_H_POSITION   1970*0.5//1966
#define ROT_OSD_DIA_RESET_V_POSITION   806*0.5
#define OSD_RESET_H_POSITION   2007
#define OSD_RESET_V_POSITION   953

#elif ModelName == BENQ_PD2700Q 
#define OSD_MAIN_TOP_MENU_H_POSITION    2344//1860//2368//ULEric140410
#define OSD_MAIN_TOP_MENU_V_POSITION    950//1300//ULEric140410

#define OSD_MAIN_MENU_H_POSITION        1396
#define OSD_MAIN_MENU_V_POSITION        772
#define ROT_OSD_MAIN_MENU_H_POSITION    1964
#define ROT_OSD_MAIN_MENU_V_POSITION    276//810

#define OSD_HOTKEY_MENU_H_POSITION  1840
#define OSD_HOTKEY_MENU_V_POSITION  772
#define OSD_HOTKEY_BAR_H_POSITION   2056
#define OSD_RESET_H_POSITION   2007
#define OSD_RESET_V_POSITION   953

//Rotate OSD position
#define ROT_OSD_HOTKEY_MENU_H_POSITION  1964//1900
#define ROT_OSD_HOTKEY_MENU_V_POSITION  810//810
#define ROT_OSD_HOTKEY_BAR_H_POSITION   1964//1966
#define ROT_OSD_HOTKEY_BAR_V_POSITION   948//1966
#define ROT_OSD_RESET_H_POSITION   1970//1966
#define ROT_OSD_RESET_V_POSITION   953
#define ROT_OSD_DIA_RESET_H_POSITION   1970//1966
#define ROT_OSD_DIA_RESET_V_POSITION   806
#else
#define OSD_MAIN_TOP_MENU_H_POSITION    2345//1860//2368//ULEric140410
#define OSD_MAIN_TOP_MENU_V_POSITION    948//1300//ULEric140410

#define OSD_MAIN_MENU_H_POSITION        1384
#define OSD_MAIN_MENU_V_POSITION        810
#define ROT_OSD_MAIN_MENU_H_POSITION    1964
#define ROT_OSD_MAIN_MENU_V_POSITION    276//810

#define OSD_HOTKEY_MENU_H_POSITION  1900
#define OSD_HOTKEY_MENU_V_POSITION  810
#define OSD_HOTKEY_BAR_H_POSITION   1966
#define OSD_RESET_H_POSITION   2007
#define OSD_RESET_V_POSITION   953

//Rotate OSD position
#define ROT_OSD_HOTKEY_MENU_H_POSITION  1964//1900
#define ROT_OSD_HOTKEY_MENU_V_POSITION  810//810
#define ROT_OSD_HOTKEY_BAR_H_POSITION   1964//1966
#define ROT_OSD_HOTKEY_BAR_V_POSITION   948//1966
#define ROT_OSD_DIA_RESET_H_POSITION   1970//1966
#define ROT_OSD_DIA_RESET_V_POSITION   806
#endif

#define OSD_WIN_BOARDER_SIZE    3

#define MAX_X               (PANEL_WIDTH - (12*OSD_INFO_WIDTH))
#define MAX_Y               (PANEL_HEIGHT - (18*OSD_INFO_HEIGHT))
#define OSD_MOVESTEP_X      6
#define OSD_MOVESTEP_Y      6
#define MAX_ROT_X           (PANEL_WIDTH - (18*OSD_INFO_HEIGHT))
#define MAX_ROT_Y           (PANEL_HEIGHT - (12*OSD_INFO_WIDTH))
#define OSD_MOVESTEP_ROT_X  OSD_MOVESTEP_Y
#define OSD_MOVESTEP_ROT_Y  OSD_MOVESTEP_X

//Attr
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
#define CLEAR_FRAME_BORDER  (((MAIN_BOARDER-1)<<8)|(I_BLACK<<4)|0x0000)

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
#define SELECTPAGE_1BIT_COLOR1_B1    (((I_BLACK-1)<<8)|(I_BENQ_GRAY_3<<4)|ONEBITFONT1)
#define SELECTPAGE_1BIT_COLOR1_BLUE    (((I_BENQ_GRAY_3-1)<<8)|(I_BENQ_BLUE_1<<4)|0x0000)
#define SELECTPAGE_1BIT_COLOR1_BLUE_B1    (((I_BENQ_GRAY_3-1)<<8)|(I_BENQ_BLUE_1<<4)|ONEBITFONT1)
#define SELECTPAGE_1BIT_COLOR1_BLACK    (((I_BLACK-1)<<8)|(I_BENQ_BLUE_1<<4)|0x0000)
#define SELECTPAGE_1BIT_COLOR1_BLACK_B1    (((I_BLACK-1)<<8)|(I_BENQ_BLUE_1<<4)|ONEBITFONT1)
#define SELECTPAGE_1BIT_COLOR1_WHITE    (((I_WHITE-1)<<8)|(I_BENQ_GRAY_3<<4)|0x0000)
#define SELECTPAGE_1BIT_COLOR1_WHITE_B1    (((I_WHITE-1)<<8)|(I_BENQ_GRAY_3<<4)|ONEBITFONT1)

//Eye Protect Meter Icon
#define EyeProMeter_Color1      (((I_TBLACK-1)<<8)|(I_BENQ_GRAY_8<<4)|ONEBITFONT0)
#define EyeProMeter_Color2      (((I_BENQ_GRAY_9-1)<<8)|(I_TBLACK<<4)|ONEBITFONT0)

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
#define TOPPAGEICON_1BIT_COLOR1_B1  (((I_WHITE-1)<<8)|(I_BENQ_GRAY_3<<4)|ONEBITFONT1)
#define TOPPAGEICON_1BIT_STRING_COLOR1  (((I_WHITE-1)<<8)|(I_BENQ_GRAY_3<<4)|ONEBITFONT1)
#define TOPPAGEICON_1BIT_COLOR1_UNSELECTED  (((I_BENQ_GRAY_8-1)<<8)|(I_BENQ_GRAY_3<<4)|0x0000)
#define TOPPAGEICON_1BIT_COLOR1_UNSELECTED_B1  (((I_BENQ_GRAY_8-1)<<8)|(I_BENQ_GRAY_3<<4)|ONEBITFONT1)
#define TOPPAGEICON_1BIT_HOOK_COLOR  (((I_BENQ_BLUE_1-1)<<8)|(I_BENQ_GRAY_3<<4)|0x0000)
#define TOPPAGEICON_1BIT_HOOK_COLOR_B1  (((I_BENQ_BLUE_1-1)<<8)|(I_BENQ_GRAY_3<<4)|ONEBITFONT1)
#define TOPPAGEICON_1BIT_EXIT_COLOR  (((I_TRED-1)<<8)|(I_BENQ_GRAY_3<<4)|0x0000)
#define TOPPAGEICON_1BIT_EXIT_COLOR_B1  (((I_TRED-1)<<8)|(I_BENQ_GRAY_3<<4)|ONEBITFONT1)
#define TOPPAGEICON_1BIT_EXIT_COLOR2  (((I_TRED-1)<<8)|(I_BENQ_BLUE_1<<4)|0x0000)
#define TOPPAGEICON_1BIT_EXIT_COLOR2_B1  (((I_TRED-1)<<8)|(I_BENQ_BLUE_1<<4)|ONEBITFONT1)

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
#define TOPPAGE_2BIT_COLOR4        (((TOP_PAGE_2BIT_COLOR1-1)<<8)|(I_BENQ_GRAY_3<<4)|0x08|0x0000)

// Top Page menu Blue color
#define TOPPAGE_2BIT_COLOR1_BLUE        (((TOP_PAGE_2BIT_COLOR1_BLUE-1)<<8)|(I_BENQ_GRAY_3<<4)|0x08|0x0000)
#define TOPPAGE_2BIT_COLOR2_BLUE        (((TOP_PAGE_2BIT_COLOR1_BLUE-1)<<8)|(I_BLACK<<4)|0x08|0x0000)
#define TOPPAGE_2BIT_CROSS_COLOR1_BLUE        (((TOP_PAGE_2BIT_COLOR2_BLUE-1)<<8)|(I_BENQ_GRAY_3<<4)|0x08|0x0000)
#define TOPPAGE_2BIT_CROSS_COLOR2_BLUE        (((TOP_PAGE_2BIT_COLOR3_BLUE-1)<<8)|(I_BENQ_BLUE_1<<4)|0x08|0x0000)
#define TOPPAGE_2BIT_COLOR3_BLUE        (((TOP_PAGE_2BIT_COLOR1-1)<<8)|(I_BENQ_BLUE_1<<4)|0x08|0x0000)
#define TOPPAGE_1BIT_COLOR1_BLUE        (((I_TBLACK-1)<<8)|(I_BENQ_BLUE_1<<4)|0x0000)
#define TOPPAGE_1BIT_COLOR1_BLUE_B1        (((I_TBLACK-1)<<8)|(I_BENQ_BLUE_1<<4)|ONEBITFONT1)
#define TOPPAGE_STRING_1BIT_COLOR1_BLUE        (((I_TBLACK-1)<<8)|(I_BENQ_BLUE_1<<4)|ONEBITFONT1)

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

// ECO Meter Color
#define ECO_METER_3BIT_COLOR    (((ECOMeter_4BIT_COLOR-1)<<8)|(I_TBLACK<<4)|0x0c|0x0000)
#define ECO_METER_2BIT_COLOR    (((ECOMeter_4BIT_COLOR-1)<<8)|(I_TBLACK<<4)|0x08|0x0000)


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
#define SenseyeNoticeStringColor     (((I_WHITE-1)<<8)|(I_BLACK<<4)|0x04|0x0000|TRANSLUCENT_EN)
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

enum _ItemLayer {
    LAYER_1,
    LAYER_2,
    LAYER_3,
    LAYER_4,
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
#if ENABLE_CUSTOMKEY_AUTOADJ == ON                             
    TP_AUTOADJUSTMENT,
#endif    
    TP_INPUT,
    //ULEric140402
    TP_VOLUME,
    TP_MUTE,
#if ENABLE_CUSTOMKEY_LBL == ON                
    TP_LOWBLUELIGHT,
#endif    
#if ENABLE_ERGONOMICS == ON
    TP_SMARTREMINDER,
#endif    
#if ENABLE_CUSTOMKEY_ANIMATION == ON  
    TP_ANIMATION,
#endif 
#if ENABLE_CUSTOMKEY_CAD == ON  
    TP_CAD,
#endif 
#if ENABLE_EYE_PROTECT == ON
    TP_EYE_PROTECT,
    TP_EYE_PROTECT_METER,
#endif     
#if ENABLE_ECO_SENSOR == ON
    TP_ECO_SENSOR,
    TP_ECO_SENSOR_METER,
#endif   
    TP_MENU,
    TP_EXIT,
    //TP_ICON_NUM,
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
extern BOOL bPhaseSlider;
extern UCHAR ucSliderMaxValue;
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

extern xdata  UCHAR ucMainIconPos[14];
extern xdata  UCHAR SPIcon1PosTab[10];
extern xdata  UCHAR SPIcon2PosTab[10];
extern xdata  UCHAR SPIcon3PosTab[10];
extern xdata  UCHAR SPIcon4PosTab[8];
extern xdata  UCHAR SPIcon5PosTab[12];
extern xdata  UCHAR *SPIconPosInfoTab[6];
extern xdata  UCHAR SPIconItmNumTab[6];
extern xdata  UCHAR SPBotIcon1PosTab[8];
extern xdata  UCHAR SPBotIcon2PosTab[8];
extern xdata  UCHAR SPBotIcon3PosTab[12];
extern xdata  UCHAR SPBotIcon4PosTab[6];
extern xdata  UCHAR SPBotIcon5PosTab[12];
extern xdata  UCHAR SPBotIcon6PosTab[8];
extern xdata  UCHAR *SPBotIconPosInfoTab[6];
extern xdata  UCHAR SPBotIconItmNumTab[6];

extern xdata  UCHAR ucLayer1StringInfoTb[2];
extern xdata  UCHAR ucLayer2ItmNumTb[MAINMENU_ICON_NUM];
extern xdata  UCHAR ucLayer2ItemInfoTb[2];
#if ENABLE_OSD_ANALOG_FUNCTION == OFF
#if ENABLE_AUTO_POVIT_FUNC == ON
extern xdata  UCHAR ucLayer3MItem1NumTb[2];
#else
extern xdata  UCHAR ucLayer3MItem1NumTb[1];
#endif
#else
#if ENABLE_AUTO_POVIT_FUNC == ON
extern xdata  UCHAR ucLayer3MItem1NumTb[7];
#else
extern xdata  UCHAR ucLayer3MItem1NumTb[6];
#endif
#endif
extern xdata  UCHAR ucLayer3MItem1InfoTb[2];
extern xdata  UCHAR ucLayer3MItem2NumTb[9];
extern xdata  UCHAR ucLayer3MItem2InfoTb[2];
extern xdata  UCHAR ucLayer3MItem3NumTb[OSD_PICTURE_AD_NUM];
extern xdata  UCHAR ucLayer3MItem3InfoTb[2];
extern xdata  UCHAR ucLayer3MItemAudioNumTb[3];
extern xdata  UCHAR ucLayer3MItemAudioInfoTb[2];
extern xdata  UCHAR ucLayer3MItem4NumTb[12];
extern xdata  UCHAR ucLayer3MItem4InfoTb[2];
extern xdata  UCHAR ucLayer4ItemInfoTb[9];
extern xdata  UCHAR ucLBLItemInfoTb[3];
#if ENABLE_ERGONOMICS == ON
extern xdata  UCHAR ucLayer3MItemErgoNumTb[OSD_ERGONOMICS_NUM];
extern xdata  UCHAR ucLayer3MItemErgoInfoTb[2];
#endif
extern xdata  UCHAR *ucLayer3ItmNumTab[MAINMENU_ICON_NUM];
extern xdata  UCHAR *ucLayer3PosInfoTab[MAINMENU_ICON_NUM];

//extern xdata  UCHAR ucAuto_PosTab[6];
//extern xdata  UCHAR ucDisplay_PosTab[6];

//extern xdata  UCHAR ucContrast_PosTab[6];
//extern xdata  UCHAR ucBrightness_PosTab[6];
//extern xdata  UCHAR ucPicture_PosTab[6];
//extern xdata  UCHAR ucInput_PosTab[6];
extern xdata  UCHAR ucMenu_PosTab[9];
extern xdata  UCHAR ucExit_PosTab[9];
extern xdata  UCHAR ucOthers_PosTab[6];

//ULEric140402
//extern xdata  UCHAR ucVolume_PosTab[6];
//extern xdata  UCHAR ucMute_PosTab[6];
//extern xdata  UCHAR ucLowBlueLight_PosTab[6];
//extern xdata  UCHAR ucSmartReminder_PosTab[6];
//extern xdata  UCHAR *ucTopPageIconInfoTab[15];

extern void OSDShowInputNoticeDialogString(void);
extern void OSDShowCusKeyHook(UCHAR id, UCHAR CustomerKey);
void OSDShowTopPageIcon(UCHAR id, UCHAR sel, UCHAR CustomerKey);
void OSDShowClrTmpMenu(UCHAR id);
extern void OSDShowMainMenuStrings(void);
extern void OSDLangueSlecetReload(void);
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
extern void OSDShowLayer4(UCHAR id);
extern void OSDShowArrow(UCHAR x, UCHAR y, UCHAR arrowType);
extern void OSDClearArrow(UCHAR x, UCHAR y, UCHAR arrowType);
extern UCHAR OSDGetLayer3ItemNum(UCHAR MenuType, UCHAR SubMenuType);
extern UCHAR OSDCheckL3ItemNum(UCHAR MenuType, UCHAR SubMenuType, UCHAR Range);
extern void OSDShowLayer3PageString(UCHAR pageNum);
extern void OSDShowCustomKeyHookIcon(UCHAR pageNum);
extern void OSDClearLayer4ByItem(UCHAR id, BOOL IsUp);
extern UCHAR *OSDGetItemString(UCHAR MainMenuIdex, UCHAR SubMenuIndex, UCHAR ItemIndex);

extern void OSDShowCusPictureModeStrings(UCHAR id);
extern void OSDShowCusDisplayModeStrings(UCHAR id);
extern void OSDShowCusInputStrings(UCHAR id);
extern void OSDShowCusSmartReminderString(UCHAR id);

extern void OSDShowCustomMenuDialogString(UCHAR id, UCHAR CustomerKey);
extern void OSDShowCusLowBlueLightStrings(void);//ULEric140402
extern void OSDShowCusMenuString(UCHAR MainMenuType, UCHAR SubMenuType);
extern void OSDShowCustomMenuTitle(UCHAR MenuType);

extern void OSDShowCusMenuIcon(UCHAR id, UCHAR sel);
extern void OSDShowLayer4SliderBar(UCHAR type,UCHAR redraw);

extern UCHAR OSDStringRemap(USHRT id);

#endif //__OSD_VIEW_H__
