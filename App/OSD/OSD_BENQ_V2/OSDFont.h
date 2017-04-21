/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/
#ifndef __OSD_FONT_H__
#define __OSD_FONT_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "Typedef.h"
#include "OSDType.h"
#include "include.h"


//******************************************************************************
// G L O B A L   D E F I N I T I O N S
//******************************************************************************
#define ONEBITFONT0         0x0000
#define ONEBITFONT1         0x0004
#define TWOBITFONT          0x0008
#define THREEBITFONT        0x000C
#define FOURBITFONT         0x000C
#define TRANSLUCENT_EN      0x0002

#define BLACK       0x0000
#define RED         0xF800
#define GREEN       0x07E0
#define BLUE        0x001F
#define CYAN        (BLUE|GREEN)
#define MAGENTA     (RED|BLUE)
#define YELLOW      (RED|GREEN)
#define WHITE       (RED|GREEN|BLUE)
#define TBLACK      BLACK
#define TRED        0xD061
#define TGREEN      0x01E0
#define TBLUE       0x000F
#define TCYAN       (TBLUE|TGREEN)
#define TMAGENTA    (TRED|TBLUE)
#define TYELLOW     (TRED|TGREEN)
#define GRAY        (TRED|TGREEN|TBLUE)

#define BENQ_GREEN_0     0x05A0     // R0 G180 B0
#define BENQ_GRAY_0       0x0821    // R5 G5 B5
#define BENQ_GRAY_1       0x2104    // R30 G30 B30
#define BENQ_GRAY_2       0x2945    // R40 G40 B40
#define BENQ_GRAY_3       0x31A6    // R50 G50 B50
#define BENQ_GRAY_4       0x41E8    // R60 G60 B60
#define BENQ_GRAY_5       0x4A49    // R70 G70 B70
#define BENQ_GRAY_6       0x528A    // R80 G80 B80
#define BENQ_GRAY_7       0x6B2D    // R100 G100 B100
#define BENQ_GRAY_8       0x94B2    // R146 G146 B146
#define BENQ_GRAY_9       0xDEFB    // R200 G200 B200
#define BENQ_GRAY_10     0xE6FC    // R220 G220 B220
#define BENQ_BLUE_0        0x2D18   // R41 G161 B217
#define BENQ_BLUE_1        0x355C   // R48 G168 B224
#define BENQ_RED_0          0xF803   // R255 G0 B20

enum PaletteIndex_
{
    I_BLACK,
    I_GREEN,
    I_BENQ_GRAY_2,
    I_BENQ_GRAY_3,
    I_BENQ_GRAY_4,
    I_BENQ_GRAY_5,
    I_YELLOW,
    I_WHITE,
    I_TBLACK,
    I_TRED,
    //10
    I_BENQ_GREEN_0, //1
    I_BENQ_BLUE_1,
    I_BENQ_BLUE_0,
    I_BENQ_GRAY_8,
    I_TYELLOW,
    I_BENQ_RED_0,
    I_BENQ_GRAY_9,

    //16
    MAIN_BOARDER,
    MAIN_TITLE = MAIN_BOARDER+3,
    MAIN_ICON_2BIT_COLOR1 = MAIN_TITLE+2,
    MAIN_ICON_2BIT_COLOR2 = MAIN_ICON_2BIT_COLOR1+2,
    MAIN_ICON_2BIT_COLOR3 = MAIN_ICON_2BIT_COLOR2+2,
    MAIN_ICON_2BIT_COLOR4 = MAIN_ICON_2BIT_COLOR3+2,
    MAIN_ICON_2BIT_COLOR5 = MAIN_ICON_2BIT_COLOR4+2,
    MAIN_ICON_2BIT_END = MAIN_ICON_2BIT_COLOR5+2,


    TOP_PAGE_2BIT_COLOR1 = MAIN_ICON_2BIT_END,
    TOP_PAGE_2BIT_COLOR2 = TOP_PAGE_2BIT_COLOR1+3,
    TOP_PAGE_2BIT_COLOR3 = TOP_PAGE_2BIT_COLOR2+2,


    TOP_PAGE_2BIT_COLOR1_BLUE = TOP_PAGE_2BIT_COLOR3+3,
    TOP_PAGE_2BIT_COLOR2_BLUE = TOP_PAGE_2BIT_COLOR1_BLUE+3,
    TOP_PAGE_2BIT_COLOR3_BLUE = TOP_PAGE_2BIT_COLOR2_BLUE+3,

    SELECT_PAGE_4BIT_COLOR1_BLUE_UPPER = TOP_PAGE_2BIT_COLOR3_BLUE+3,
    SELECT_PAGE_4BIT_COLOR2_BLUE_LOWER = SELECT_PAGE_4BIT_COLOR1_BLUE_UPPER+4,


    SLIDERBAR_2BIT_BOARDER_COLOR = SELECT_PAGE_4BIT_COLOR2_BLUE_LOWER+4,
    SLIDERBAR_2BIT_BLANK_COLOR = SLIDERBAR_2BIT_BOARDER_COLOR+2,
    SLIDERBAR_2BIT_FULL_COLOR_BLUE = SLIDERBAR_2BIT_BLANK_COLOR+3,
    SLIDERBAR_2BIT_FULL_COLOR_RED = SLIDERBAR_2BIT_FULL_COLOR_BLUE+3,
    SLIDERBAR_2BIT_FULL_COLOR_GREEN = SLIDERBAR_2BIT_FULL_COLOR_RED+3,
    SLIDERBAR_2BIT_FULL_COLOR_GRAY = SLIDERBAR_2BIT_FULL_COLOR_GREEN+3,
    SLIDERBAR_4BIT_COLOR_BLUE = SLIDERBAR_2BIT_FULL_COLOR_GRAY+3,
    SLIDERBAR_4BIT_COLOR_RED = SLIDERBAR_4BIT_COLOR_BLUE+4,
    SLIDERBAR_4BIT_COLOR_GREEN = SLIDERBAR_4BIT_COLOR_RED+4,
    SLIDERBAR_4BIT_COLOR_GRAY = SLIDERBAR_4BIT_COLOR_GREEN+4,

    ECOMeter_4BIT_COLOR = SLIDERBAR_4BIT_COLOR_GRAY+4,
};

//======1 Bit Start==========================
enum CommonOneBit
{
    _SPACE_,
  //  Num_0,
  //  NumberEnd = Num_0+10,
  //  StringSeparater_1 = NumberEnd,
    StringSeparater_1,
    StringSeparater_2,

    DownArrow_1,
    DownArrow_2,
//    DownArrow_3,

    UpArrow_1,
    UpArrow_2,

    UpArrow1_1,
    UpArrow1_2,

    //Triangle icon2,
    Triangle_Icon2_1,
    Triangle_Icon2_2,
    Triangle_Icon2_3,
    Triangle_Icon2_4,

    //Triangle icon3
    Triangle_Icon3_1,
    Triangle_Icon3_2,
    Triangle_Icon3_3,
    Triangle_Icon3_4,

    // Layer separator
    Layer_Separator_Head,
    Layer_Separator_Mid,
    Layer_Separator_Tail,

    // Dialog Triangle icon1
    Dialog_Triangle_Icon1_1Bit_1,
    Dialog_Triangle_Icon1_1Bit_2,

    // Dialog Triangle icon2
    Dialog_Triangle_Icon2_1Bit_1,
    Dialog_Triangle_Icon2_1Bit_2,
    Dialog_Triangle_Icon2_1Bit_3,
    Dialog_Triangle_Icon2_1Bit_4,
    Dialog_Triangle_Icon2_1Bit_5,

    // Dialog Triangle icon3
    Dialog_Triangle_Icon3_1Bit_1,
    Dialog_Triangle_Icon3_1Bit_2,
    Dialog_Triangle_Icon3_1Bit_3,
    Dialog_Triangle_Icon3_1Bit_4,
    Dialog_Triangle_Icon3_1Bit_5,

    // Dialog String Separater
    Dialog_String_Separater_1,

    CommonOneBit_End,
};

enum SelectPageIcon_OneBit
{
    SP_ICON_1Bit_Start = CommonOneBit_End,//61
    SP_Icon1_1Bit_1 = SP_ICON_1Bit_Start,
    SP_Icon1_1Bit_2,
    SP_Icon1_1Bit_3,
    SP_Icon1_1Bit_4,
    SP_Icon1_1Bit_5,

    SP_Icon2_1Bit_1,
    SP_Icon2_1Bit_2,
    SP_Icon2_1Bit_3,
    SP_Icon2_1Bit_4,
    SP_Icon2_1Bit_5,

    SP_Icon3_1Bit_1,
    SP_Icon3_1Bit_2,
    SP_Icon3_1Bit_3,
    SP_Icon3_1Bit_4,
    SP_Icon3_1Bit_5,


    SP_Icon4_1Bit_1,
    SP_Icon4_1Bit_2,
    SP_Icon4_1Bit_3,
    SP_Icon4_1Bit_4,

    SP_Icon5_1Bit_1,
    SP_Icon5_1Bit_2,
    SP_Icon5_1Bit_3,
    SP_Icon5_1Bit_4,
    SP_Icon5_1Bit_5,
    SP_Icon5_1Bit_6,

    SP_Icon6_1Bit_1,
    SP_Icon6_1Bit_2,
    SP_Icon6_1Bit_3,
    SP_Icon6_1Bit_4,
    SP_Icon6_1Bit_5,

    
    SP_ICON_End,
};

enum MainIcon_OneBit
{
/*
    MI_1Bit_Start = CommonOneBit_End,//34
    MI1_1Bit_Upper_1 = MI_1Bit_Start,
    MI1_1Bit_Lower_1,
    MI1_1Bit_Lower_2,
    MI1_1Bit_Lower_3,

    MI2_1Bit_Lower_1,
    MI2_1Bit_Lower_2,
    MI2_1Bit_Lower_3,

    MI3_1Bit_Lower_1,
    MI3_1Bit_Lower_2,
    MI3_1Bit_Lower_3,
    
    MIAudio_1Bit_Middle_1,
    MIAudio_1Bit_Middle_2,
    MIAudio_1Bit_Middle_3,

    MI4_1Bit_Middle_1,
    MI4_1Bit_Middle_2,
    MI4_1Bit_Middle_3,

    MIErgo_1Bit_Middle_1,
    MIErgo_1Bit_Middle_2,
    MIErgo_1Bit_Middle_3,//52
    MainIconOneBit_End,//53
*/
    MI_1Bit_Start = SP_ICON_End,//34
    Icon_display_1 = MI_1Bit_Start,
    Icon_display_2,
    Icon_display_3,
    Icon_display_4,
    Icon_display_5,
    Icon_display_6,

    Icon_Picture_1, //40
    Icon_Picture_2,
    Icon_Picture_3,
    Icon_Picture_4,
    Icon_Picture_5,
    Icon_Picture_6,
    
    Icon_PictureAd_1, //46
    Icon_PictureAd_2,
    Icon_PictureAd_3,
    Icon_PictureAd_4,
    Icon_PictureAd_5,
    Icon_PictureAd_6,

    Icon_Audio_1, //52
    Icon_Audio_2,
    Icon_Audio_3,
    Icon_Audio_4,
    Icon_Audio_5,
    Icon_Audio_6,

    Icon_System_1, //58
    Icon_System_2,
    Icon_System_3,
    Icon_System_4,
    Icon_System_5,
    Icon_System_6,

    Icon_Ergonomics_1, //64
    Icon_Ergonomics_2,
    Icon_Ergonomics_3,
    Icon_Ergonomics_4,
    Icon_Ergonomics_5,
    Icon_Ergonomics_6,

    Icon_ECO_1, //70
    Icon_ECO_2,
    Icon_ECO_3,
    Icon_ECO_4,
    Icon_ECO_5,
    Icon_ECO_6,

    MainIconOneBit_End,//76
};

enum TopPageIcon_OneBit
{
    TP_1Bit_Start = SP_ICON_End,//94

    // Input icon
    TP_1Bit_Input_Start = TP_1Bit_Start,
    TP_1Bit_Input_End = TP_1Bit_Input_Start+9,

    // Brightness icon
    TP_1Bit_Brightness_Start = TP_1Bit_Input_End,
    TP_1Bit_Brightness_End= TP_1Bit_Brightness_Start+9,

    // Auto Adjustment icon
    TP_1Bit_Auto_Start = TP_1Bit_Brightness_End,
    TP_1Bit_Auto_End = TP_1Bit_Auto_Start+9,

    // Menu icon
    TP_1Bit_Menu_Start = TP_1Bit_Auto_End,
    TP_1Bit_Menu_End = TP_1Bit_Menu_Start+9,

    // Exit icon
    TP_1Bit_Exit_Start = TP_1Bit_Menu_End,
    TP_1Bit_Exit_End = TP_1Bit_Exit_Start+9,

    // DisplayMode icon
    TP_1Bit_DisplayMode_Start = TP_1Bit_Exit_End,
    TP_1Bit_DisplayMode_End = TP_1Bit_DisplayMode_Start+9,

    // Contrast icon
    TP_1Bit_Contrast_Start = TP_1Bit_DisplayMode_End,
    TP_1Bit_Contrast_End = TP_1Bit_Contrast_Start+9,

    // Picture icon
    TP_1Bit_Picture_Start = TP_1Bit_Contrast_End,
    TP_1Bit_Picture_End = TP_1Bit_Picture_Start+9,
    
    //ULEric140402    
    // Volume icon
    TP_1Bit_Volume_Start = TP_1Bit_Picture_End,
    TP_1Bit_Volume_End = TP_1Bit_Volume_Start+9,
    // Mute icon
    TP_1Bit_Mute_Start = TP_1Bit_Volume_End,
    TP_1Bit_Mute_End = TP_1Bit_Mute_Start+9,
    //ULEric140403
    //LBL icon
    TP_1Bit_LowBlueLight_Start = TP_1Bit_Mute_End,
    TP_1Bit_LowBlueLight_End = TP_1Bit_LowBlueLight_Start+9,
    //ULEric140410
    //SmartReminder icon
    TP_1Bit_SmartReminder_Start = TP_1Bit_LowBlueLight_End,
    TP_1Bit_SmartReminder_End = TP_1Bit_SmartReminder_Start+9,

    //Animation icon
    TP_1Bit_Animation_Start = TP_1Bit_SmartReminder_End,
    TP_1Bit_Animation_End = TP_1Bit_Animation_Start+9,

    //CAD icon
    TP_1Bit_CAD_Start = TP_1Bit_Animation_End,
    TP_1Bit_CAD_End = TP_1Bit_CAD_Start+9,

    //Eco_Sensor icon
//    TP_1Bit_Eco_Sensor_Start = TP_1Bit_Animation_End,
    TP_1Bit_Eco_Sensor_Start = TP_1Bit_CAD_End,
    TP_1Bit_Eco_Sensor_End = TP_1Bit_Eco_Sensor_Start+9,

    //Eco_Sensor_Meter icon
    TP_1Bit_Eco_Sensor_Meter_Start = TP_1Bit_Eco_Sensor_End,
    TP_1Bit_Eco_Sensor_Meter_End = TP_1Bit_Eco_Sensor_Meter_Start+9,

    //Eye_Protect icon
    TP_1Bit_Eye_Protect_Start = TP_1Bit_Eco_Sensor_Meter_End,
    TP_1Bit_Eye_Protect_End = TP_1Bit_Eye_Protect_Start+9,

    //Eye_Protect_Meter icon
    TP_1Bit_Eye_Protect_Meter_Start = TP_1Bit_Eye_Protect_End,
    TP_1Bit_Eye_Protect_Meter_End = TP_1Bit_Eye_Protect_Meter_Start+9,
	
    TP_1Bit_End = TP_1Bit_Eye_Protect_Meter_End,
};

enum NoticeIcon_OneBit
{
    Notice_Icon_1Bit_start = TP_1Bit_End,//90
    Notice_Icon_1Bit_end = Notice_Icon_1Bit_start+10,//94
};

enum SourceIcon_OneBit
{
    // Input icon
    Input_VGA_Start = SP_ICON_End,
    Input_VGA_End = TP_1Bit_Input_Start+3,

    Input_DVI_Start = Input_VGA_End,
    Input_DVI_End = Input_DVI_Start+3,

    Input_HDMI_Start = Input_DVI_End,
    Input_HDMI_End = Input_HDMI_Start+3,

    Input_DP_Start = Input_HDMI_End,
    Input_DP_End = Input_DP_Start+3,  
    Input_MINIDP_Start = Input_DP_End,
    Input_MINIDP_End = Input_MINIDP_Start+3, 
};

enum Eye_Protect_Meter_OneBit
{
     Eye_Protect_Meter_start,
     Eye_Protect_Meter_end = Eye_Protect_Meter_start+20,
};

//======2 Bit Start==========================
enum Common_TwoBit
{
    // MainBoarder
    MB_LeftTopCorner,
    MB_TopRepeat,
    MB_RightTopCorner,
    MB_LeftSide_1,
    MB_RightSide_1,
    MB_TitleCrossLeft_1,
    MB_TitleCrossRepeat_1,
    MB_TitleCrossRight_1,
    MB_LeftSide_2,
    MB_RightSide_2,
    MB_LeftBottomCorner_1,
    MB_RightBottomCorner_1,
    MB_LeftBottomCorner_2,
    MB_BottomRepeat,
    MB_RightBottomCorner_2,

    // Triangle icon
    Triangle_Icon1_1,
    Triangle_Icon1_2,
    Triangle_Icon1_3,
    Triangle_Icon1_4,

    // Dialog Triangle icon1
    Dialog_Triangle_Icon1_2Bit_1,
    Dialog_Triangle_Icon1_2Bit_2,
    Dialog_Triangle_Icon1_2Bit_3,

    // SliderBar font
    SB_TopLeft,
    SB_Top,
    SB_LeftSide,
    SB_BottomLeft,
    SB_Bottom,
    SB_Bottom_Font1,
    SB_Blank_Font,
    Common_End
};

enum SelectPage_TwoBit
{
    SP_Start = Common_End,
    SP_LeftTopCorner = SP_Start,
    SP_TopRepeat,
    SP_LeftSideRepeat,
    //SP_FirstIcon_LeftSideCross,
    SP_FirstIcon_CrossRepeat,
    //SP_SecondIcon_LeftSideCross,
    SP_SecondIcon_CrossRepeat,
    SP_3thIcon_LeftSideCross,
    SP_3thIcon_CrossRepeat,
    SP_4thIcon_LeftSideCross,
    SP_4thIcon_CrossRepeat,
    SP_LeftBottomCorner_1,
    SP_LeftBottomCorner_2,
    SP_Bot_LeftSideRepeat,
    SP_BottomRepeat,
    //SP_Bot_TopIconCross,
    SP_Bot_RightTopCorner,
    SP_Bot_RightSideRepeat,
    SP_RightTopCorner,
    SP_LeftBottomCorner,
    SP_End
};

enum MainIcon_TwoBit
{
    MI_2Bit_Start = SP_End,
    MI2_2Bit_Upper_1 = MI_2Bit_Start,
    MI2_2Bit_Upper_2,
    MI2_2Bit_Upper_3,

    MI3_2Bit_Upper_1,
    MI3_2Bit_Upper_2,
    MI3_2Bit_Upper_3,
    
    MIAudio_2Bit_Upper_1,
    MIAudio_2Bit_Upper_2,
    MIAudio_2Bit_Upper_3,
    
    MI4_2Bit_Upper_1,
    MI4_2Bit_Lower_1,
    MI_End
};
#if 0
enum TopPage_TwoBit
{
    TP_2Bit_Start = MI_End,
    TP_UpperLeft_Corner = TP_2Bit_Start,
    TP_UpperRepeat,
    TP_LeftRepeat,
    TP_LeftCross,
    TP_CrossRepeat,
    TP_LowerLeft_Corner,
    TP_LowerRepeat,
    TP_2Bit_End
};
#endif

enum DialogIcon_TwoBit
{
    DI_2Bit_start,
    DI_2Bit_LeftTopCorner = DI_2Bit_start,
    DI_2Bit_TopRepeat,
    DI_2Bit_RightTopCorner,
    DI_2Bit_LeftSideUp,
    DI_2Bit_RightSideUp,
    DI_2Bit_LeftSideRepeat,
    DI_2Bit_RightSideRepeat,
    DI_2Bit_LeftSideDown,
    DI_2Bit_RightSideDown,
    DI_2Bit_LeftBottomCorner,
    DI_2Bit_BottomRepeat,
    DI_2Bit_RightBottomCorner
};

//================4 Bit start=====================================
enum SelectPage_4Bit
{
    SP_4Bit_Start,
    SP_FirstIcon_LeftSideCross = SP_4Bit_Start,
    SP_SecondIcon_LeftSideCross,
    SP_Bot_TopCross,
    SP_LeftEdge,
    SP_4Bit_End
};

enum SLiderBar_4Bit
{
    SB_4Bit_Start = SP_4Bit_End,
    SB_4Bit_Font_1 = SB_4Bit_Start,
    SB_4Bit_Font_2,
    SB_4Bit_Font_3,
    SB_4Bit_Font_4,
    SB_4Bit_Font_5,

    SB_4Bit_BottomFont_1,
    SB_4Bit_BottomFont_2,
    SB_4Bit_BottomFont_3,
    SB_4Bit_BottomFont_4,
    SB_4Bit_BottomFont_5,
    SB_4Bit_End
};


enum EcoMeter_2Bit
{
    EM_2Bit_Start,
    EM_SPACE = EM_2Bit_Start,

    EcoMeterBorder1,
    EcoMeterBorder2,
    EcoMeterBorder3,
    EcoMeterBorder4,
    EcoMeterBorder5,
    EcoMeterBorder6,
    EcoMeterBorder7,
    EcoMeterBorder8,

    EM_Icon,
    EM_Icon_End = EM_Icon+20,
};

enum Ecometer_3bit
{
    EM_3Bit_Start,
    EM_Icon_Cycle1 = EM_3Bit_Start,//29
    EM_Icon_Cycle1_End = EM_Icon_Cycle1+144,
};




//================String Part=====================================
enum OneBitFont_256
{
    OneBitFont_256_start = 256,
    _SPACE256_ = OneBitFont_256_start,
    Hook_Icon,
    OneBitFont_256_end
};

enum SelectPageBotIcon_OneBit
{
    SP_BOT_ICON_1Bit_Start = OneBitFont_256_end,
    SP_Bot_Icon1_1Bit_1 = SP_BOT_ICON_1Bit_Start,
    SP_Bot_Icon1_1Bit_2,
    SP_Bot_Icon1_1Bit_3,
    SP_Bot_Icon1_1Bit_4,

    SP_Bot_Icon2_1Bit_1,
    SP_Bot_Icon2_1Bit_2,
    SP_Bot_Icon2_1Bit_3,
    SP_Bot_Icon2_1Bit_4,

    SP_Bot_Icon3_1Bit_1,
    SP_Bot_Icon3_1Bit_2,
    SP_Bot_Icon3_1Bit_3,
    SP_Bot_Icon3_1Bit_4,
    SP_Bot_Icon3_1Bit_5,
    SP_Bot_Icon3_1Bit_6,

    SP_Bot_Icon4_1Bit_1,
    SP_Bot_Icon4_1Bit_2,
    SP_Bot_Icon4_1Bit_3,

    SP_Bot_Icon5_1Bit_1,
    SP_Bot_Icon5_1Bit_2,
    SP_Bot_Icon5_1Bit_3,
    SP_Bot_Icon5_1Bit_4,
    SP_Bot_Icon5_1Bit_5,
    SP_Bot_Icon5_1Bit_6,

    SP_Bot_Icon6_1Bit_1,
    SP_Bot_Icon6_1Bit_2,
    SP_Bot_Icon6_1Bit_3,
    SP_Bot_Icon6_1Bit_4,
	
    SP_BOT_ICON_End,
};

//Toppage Icon Bank1
enum TopPageB1Icon_OneBit
{
    TP_1Bit_B1_Start = SP_BOT_ICON_End,

    // Input icon
    TP_1Bit_B1_Input_Start = TP_1Bit_B1_Start,
    TP_1Bit_B1_Input_End = TP_1Bit_B1_Input_Start+9,

    // Brightness icon
    TP_1Bit_B1_Brightness_Start = TP_1Bit_B1_Input_End,
    TP_1Bit_B1_Brightness_End= TP_1Bit_B1_Brightness_Start+9,

    // Auto Adjustment icon
    TP_1Bit_B1_Auto_Start = TP_1Bit_B1_Brightness_End,
    TP_1Bit_B1_Auto_End = TP_1Bit_B1_Auto_Start+9,

    // Menu icon
    TP_1Bit_B1_Menu_Start = TP_1Bit_B1_Auto_End,
    TP_1Bit_B1_Menu_End = TP_1Bit_B1_Menu_Start+9,

    // Exit icon
    TP_1Bit_B1_Exit_Start = TP_1Bit_B1_Menu_End,
    TP_1Bit_B1_Exit_End = TP_1Bit_B1_Exit_Start+9,

    // DisplayMode icon
    TP_1Bit_B1_DisplayMode_Start = TP_1Bit_B1_Exit_End,
    TP_1Bit_B1_DisplayMode_End = TP_1Bit_B1_DisplayMode_Start+9,

    // Contrast icon
    TP_1Bit_B1_Contrast_Start = TP_1Bit_B1_DisplayMode_End,
    TP_1Bit_B1_Contrast_End = TP_1Bit_B1_Contrast_Start+9,

    // Picture icon
    TP_1Bit_B1_Picture_Start = TP_1Bit_B1_Contrast_End,
    TP_1Bit_B1_Picture_End = TP_1Bit_B1_Picture_Start+9,
    
    //ULEric140402    
    // Volume icon
    TP_1Bit_B1_Volume_Start = TP_1Bit_B1_Picture_End,
    TP_1Bit_B1_Volume_End = TP_1Bit_B1_Volume_Start+9,
    // Mute icon
    TP_1Bit_B1_Mute_Start = TP_1Bit_B1_Volume_End,
    TP_1Bit_B1_Mute_End = TP_1Bit_B1_Mute_Start+9,
    //ULEric140403
    //LBL icon
    TP_1Bit_B1_LowBlueLight_Start = TP_1Bit_B1_Mute_End,
    TP_1Bit_B1_LowBlueLight_End = TP_1Bit_B1_LowBlueLight_Start+9,
    //ULEric140410
    //SmartReminder icon
    TP_1Bit_B1_SmartReminder_Start = TP_1Bit_B1_LowBlueLight_End,
    TP_1Bit_B1_SmartReminder_End = TP_1Bit_B1_SmartReminder_Start+9,

    //Animation icon
    TP_1Bit_B1_Animation_Start = TP_1Bit_B1_SmartReminder_End,
    TP_1Bit_B1_Animation_End = TP_1Bit_B1_Animation_Start+9,

    //CAD icon
    TP_1Bit_B1_CAD_Start = TP_1Bit_B1_Animation_End,
    TP_1Bit_B1_CAD_End = TP_1Bit_B1_CAD_Start+9,

     //Eco_Sensor icon
//    TP_1Bit_B1_Eco_Sensor_Start = TP_1Bit_B1_Animation_End,
    TP_1Bit_B1_Eco_Sensor_Start = TP_1Bit_B1_CAD_End,
    TP_1Bit_B1_Eco_Sensor_End = TP_1Bit_B1_Eco_Sensor_Start+9,

     //Eco_Sensor_Meter icon
    TP_1Bit_B1_Eco_Sensor_Meter_Start = TP_1Bit_B1_Eco_Sensor_End,
    TP_1Bit_B1_Eco_Sensor_Meter_End = TP_1Bit_B1_Eco_Sensor_Meter_Start+9,

     //Eye_Protect icon
    TP_1Bit_B1_Eye_Protect_Start = TP_1Bit_B1_Eco_Sensor_Meter_End,
    TP_1Bit_B1_Eye_Protect_End = TP_1Bit_B1_Eye_Protect_Start+9,

     //Eye_Protect_Meter icon
    TP_1Bit_B1_Eye_Protect_Meter_Start = TP_1Bit_B1_Eye_Protect_End,
    TP_1Bit_B1_Eye_Protect_Meter_End = TP_1Bit_B1_Eye_Protect_Meter_Start+9,
	
    TP_1Bit_B1_End = TP_1Bit_B1_Eye_Protect_Meter_End,
};

enum SourceIconB1_OneBit
{
    // Input icon
    Input_B1_VGA_Start = SP_BOT_ICON_End,
    Input_B1_VGA_End = Input_B1_VGA_Start+4,

    Input_B1_DVI_Start = Input_B1_VGA_End,
    Input_B1_DVI_End = Input_B1_DVI_Start+4,

    Input_B1_HDMI_Start = Input_B1_DVI_End,
    Input_B1_HDMI_End = Input_B1_HDMI_Start+4,

    Input_B1_DP_Start = Input_B1_HDMI_End,
    Input_B1_DP_End = Input_B1_DP_Start+4, 
    
    Input_B1_MINIDP_Start = Input_B1_DP_End,
    Input_B1_MINIDP_End = Input_B1_DP_Start+4,  
};

enum Lontfont
{
    DisplayModeMenu_font,
    ShowInputMenu_font,
    PictureModeMenu_font,
    ShowBrightnessMenu_font,
    ShowContrastMenu_font,
    ShowVolumeMenu_font,
    ShowAnimationMenu_font,
    ShowMute_font,
    ShowLowBlueLight_font,
    ShowSmartReminder_font,
    ShowEyePortect_font,
    ShowECOSensor_font,    
    ShowTopPageMenu_font,
    OSDInitialize_font,
    ShowDialog_font,
    ECO_Meter_font,
    Eye_Protect_Meter_font,
    Service_font,
    LoadPalette,
    LoadFOSDPalette,
    ShowSourcePageMenu_font,
};

#define INDENT_STRING_MAX_LEN           (17)//(13)
#define DIALOG_INDENT_STRING_MAX_LEN    (11)
#define LAYER1_INDENT_STRING_LEN    (8*(MAINMENU_ICON_NUM)+20)
#define LAYER2_INDENT_STRING_LEN    (INDENT_STRING_MAX_LEN*8)
#define LAYER3_INDENT_STRING_LEN    (INDENT_STRING_MAX_LEN*8)
#define LAYER4_INDENT_STRING_LEN    (INDENT_STRING_MAX_LEN*8)

#if LAYER_INDENT_COUNT == ON
typedef struct {
    USHRT usCount;
    UCHAR Done;
}LayerIndentInfo;

enum StringIndex
{
String_Layer1_Index = MainIconOneBit_End,
String_TopPage_Index = TP_1Bit_End,
String_DialogString_Index = String_TopPage_Index+13
};
#else
enum StringIndex
{
String_Layer1_Index = MainIconOneBit_End,
String_Layer2_Index = String_Layer1_Index + LAYER1_INDENT_STRING_LEN,
String_Layer3_Index = SP_BOT_ICON_End,
String_Layer4_Index = String_Layer3_Index + LAYER3_INDENT_STRING_LEN,
String_TopPage_Index = SP_BOT_ICON_End,
String_DialogString_Index = SP_BOT_ICON_End,

};
#endif





// NEED TO BE REMOVE
#define I_BLACK     0
#define I_GREEN     1
#define I_RED       2
#define I_BLUE      3
#define I_CYAN      4
#define I_MAGENTA   5
#define I_YELLOW    6
#define I_WHITE     7
#define I_TBLACK    8
#define I_TRED      9
#define I_TGREEN    10
#define I_TBLUE     11
#define I_TCYAN     12
#define I_TMAGENTA  13
#define I_TYELLOW   14
#define I_GRAY      15


//******************************************************************************
// E X T E R N A L   V A R I A B L E   P R O T O T Y P E S
//******************************************************************************
extern code OSDPaletteTable ucOSDPalette;
extern code OSDPaletteTable ucFOSDPalette;
extern code OSDFontTable ucOneBitFontTable;
extern code OSDFontTable ucTwoBitsFontTable;
extern code OSDFontTable ucFourBitsFontTable;
extern code OSDFontTable ucOneBitFont256Table;
extern code UCHAR ucArialWidthTable[];
extern code USHRT usArialFontTable[];
extern code USHRT usArialFontChineseTable[];
extern code OSDFontTable ucNoticeIconOneBitTab;
extern code OSDFontTable ucServiceIconOneBitTab;
extern code OSDFontTable ucMainIconOneBitTab;
extern code OSDFontTable ucSelectPageIconOneBitTab;
extern code OSDFontTable ucSelectPageTwoBitTab;
extern code OSDFontTable ucMainIconTwoBitTab;
extern code OSDFontTable ucTopPageTwoBitTab;
extern code OSDFontTable ucTopPageIconOneBitTab;
extern code OSDFontTable ucInputPageIconOneBitTab;
extern code OSDFontTable ucBrightnessPageIconOneBitTab;
//extern code ucAutoPageIconOneBitTab;
extern code OSDFontTable ucDisplayModePageIconOneBitTab;
extern code OSDFontTable ucContrastPageIconOneBitTab;
extern code OSDFontTable ucPicturePageIconOneBitTab;
extern code OSDFontTable ucVolumePageIconOneBitTab;
extern code OSDFontTable ucMutePageIconOneBitTab;
extern code OSDFontTable ucLBLPageIconOneBitTab;
extern code OSDFontTable ucSmartReminderPageIconOneBitTab;
extern code OSDFontTable ucAnimationPageIconOneBitTab;
extern code OSDFontTable ucCADPageIconOneBitTab;
extern code OSDFontTable ucEco_SensorPageIconOneBitTab;
extern code OSDFontTable ucEye_ProtectPageIconOneBitTab;
extern code OSDFontTable uc_Eye_Protect_MeterPageIconOneBitTab;

extern code OSDFontTable ucSourceIconOneBitTab;
extern code OSDFontTable ucSliderBarFourBitFontTable;
extern code OSDFontTable ucDialogTwoBitTab;
extern void OSDLoadFont(UCHAR ID);
extern void InitFont_Europe(void);
extern void InitFont_ARAB(void);
extern void InitFont_Portugus(void);
extern void InitFont_Svenska(void);
extern void InitFont_Pyccknn(void);
extern void InitFont_Romana(void);
extern void InitFont_SiCG(void);
extern void InitFont_Magyar(void);
extern void InitFont_Cesky(void);
extern void InitFont_Polski(void);
extern void InitFont_Espanol(void);
extern void InitFont_Italiano(void);
extern void InitFont_Deutsch(void);
extern void InitFont_Franais(void);
extern void InitFont_SC_Table1(void);
extern void InitFont_SC_Table2(void);
extern void InitFont_TC_Table1(void);
extern void InitFont_TC_Table2(void);
extern void InitFont_Japan_Table1(void);
extern void InitFont_Japan_Table2(void);


extern void FindTable_Europe(UCHAR *ptr);
extern void FindTable_Korea(UCHAR *ptr);
extern void FindTable_TC(UCHAR *ptr);
extern void FindTable_SC(UCHAR *ptr);
extern void FindTable_Japan(UCHAR *ptr);
extern void FindTable_Turkish(UCHAR *ptr);

#endif //__OSD_FONT_H__
