/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/

#ifndef __SCALERREG_H__
#define __SCALERREG_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "ScalerType.h"

//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************

//******************************************************************************
// D A T A   T Y P E   D E F I N E S
//******************************************************************************

//******************************************************************************
// V A R I A B L E S   P R O T O T Y P E
//******************************************************************************
extern xdata UCHAR volatile SC_ADC_CTRL;
extern xdata UCHAR volatile SC_RGAIN_HI;
extern xdata UCHAR volatile SC_ADC_TEST1;
extern xdata UCHAR volatile SC_ROFFSET;
extern xdata UCHAR volatile SC_GGAIN_HI;
extern xdata UCHAR volatile SC_ADC_TEST2;
extern xdata UCHAR volatile SC_GOFFSET;
extern xdata UCHAR volatile SC_BGAIN_HI;
extern xdata UCHAR volatile SC_ADC_MID_CH_SEL;
    #define YPBPR_CLAMP            0xA0
extern xdata UCHAR volatile SC_BOFFSET;
extern xdata UCHAR volatile SC_SOG_SLICER_EN;
extern xdata UCHAR volatile SC_SOG_DIGITAL_GLITCH_FILTER_THREESHOLD;
extern xdata UCHAR volatile SC_SOG_GLITCH_MASK_LO;
extern xdata UCHAR volatile SC_SOG_DIGITAL_FILTER_CTRL;
extern xdata UCHAR volatile SC_ADC_POWER_UP;
extern xdata UCHAR volatile SC_ADC_CLAMP_CTRL;
extern xdata UCHAR volatile SC_ADC_BW_CTRL;
extern xdata UCHAR volatile SC_SOG_CLAMPING_CTRL;
extern xdata UCHAR volatile SC_SOG_SLICER_CTRL;
extern xdata UCHAR volatile SC_ADC_INPUT_CTRL;
extern xdata UCHAR volatile SC_HS_TRIG_LEVEL;
extern xdata UCHAR volatile SC_VS_TRIG_LEVEL;
extern xdata UCHAR volatile SC_ADC_CTRL2;
extern xdata UCHAR volatile SC_TMDS_CLOCK_DET;
extern xdata UCHAR volatile SC_PRE_PATTER_CTRL;
extern xdata UCHAR volatile SC_GPORT_CTRL;
extern xdata UCHAR volatile SC_CLAMP_BEGIN;
extern xdata UCHAR volatile SC_CLAMP_WIDTH;
extern xdata UCHAR volatile SC_DIGITAL_CTRL;
    #define YPBPR_EN            BIT7

extern xdata UCHAR volatile SC_INPUT_SELECT;
    #define ADC_PORT_1          0
    #define ADC_PORT_2          1
    #define DVI_PORT_1          2
    #define DVI_PORT_2          3

extern xdata UCHAR volatile SC_ADC_CK_CTRL;
extern xdata UCHAR volatile SC_CAP_SWAP;
extern xdata UCHAR volatile SC_GI_V_DE_DLY;
extern xdata UCHAR volatile SC_GI_MASK_MSB;
extern xdata UCHAR volatile SC_GI_MASK_CTRL; 
extern xdata UCHAR volatile SC_GI_HMASK_BEG;
extern xdata UCHAR volatile SC_GI_HMASK_END;
extern xdata UCHAR volatile SC_GI_VMASK_BEG;
extern xdata UCHAR volatile SC_GI_VMASK_END;
extern xdata UCHAR volatile SC_GI_CAP_VBEGO_LO;
extern xdata UCHAR volatile SC_GI_CAP_VBEGO_HI;
extern xdata UCHAR volatile SC_GI_CAP_VBEGE_LO;
extern xdata UCHAR volatile SC_GI_CAP_VBEGE_HI;
extern xdata UCHAR volatile SC_GI_CAP_VLEN_LO;
extern xdata UCHAR volatile SC_GI_CAP_VLEN_HI;
extern xdata UCHAR volatile SC_GI_CAP_HBEG_LO;
extern xdata UCHAR volatile SC_GI_CAP_HBEG_HI;
extern xdata UCHAR volatile SC_GI_CAP_HWID_LO;
extern xdata UCHAR volatile SC_GI_CAP_HWID_HI;
extern xdata UCHAR volatile SC_GI_ALT_CTRL;
extern xdata UCHAR volatile SC_GI_CLK_MASK_WID;
extern xdata UCHAR volatile SC_DVI_CAP_HWID_LO;
extern xdata UCHAR volatile SC_DVI_CAP_HWID_HI;
extern xdata UCHAR volatile SC_DVI_CAP_VLEN_LO;
extern xdata UCHAR volatile SC_DVI_CAP_VLEN_HI;
extern xdata UCHAR volatile SC_VI_PORT_CTRL;
extern xdata UCHAR volatile SC_VI_PORT_SELECT;
extern xdata UCHAR volatile SC_VI_POLARITY_CTRL;
extern xdata UCHAR volatile SC_SOG_T1_POSITION;
extern xdata UCHAR volatile SC_SOG_T2_POSITION;
extern xdata UCHAR volatile SC_SOG_T4_POSITION;
extern xdata UCHAR volatile SC_SOG_T1_T2_WIDTH;
extern xdata UCHAR volatile SC_SOG_T4_WIDTH;
extern xdata UCHAR volatile SC_SOG_MODE_SEL;
extern xdata UCHAR volatile SC_DEI_COLOR_COFFE_LO;
extern xdata UCHAR volatile SC_DEI_COLOR_COFFE_HI;
extern xdata UCHAR volatile SC_DEI_COLOR_COFFA_LO;
extern xdata UCHAR volatile SC_DEI_COLOR_COFFA_HI;
extern xdata UCHAR volatile SC_DEI_COLOR_COFFB_LO;
extern xdata UCHAR volatile SC_DEI_COLOR_COFFB_HI;
extern xdata UCHAR volatile SC_DEI_COLOR_COFFC_LO;
extern xdata UCHAR volatile SC_DEI_COLOR_COFFC_HI;
extern xdata UCHAR volatile SC_DEI_COLOR_COFFD_LO;
extern xdata UCHAR volatile SC_DEI_COLOR_COFFD_HI;
extern xdata UCHAR volatile SC_DEI_CSC_CTRL;
extern xdata UCHAR volatile SC_CSC_CTRL1;
extern xdata UCHAR volatile SC_CSC_CTRL2;
extern xdata UCHAR volatile SC_CSC_COLOR_COFFA_LO;
extern xdata UCHAR volatile SC_CSC_COLOR_COFFA_HI;
extern xdata UCHAR volatile SC_CSC_COLOR_COFFB_LO;
extern xdata UCHAR volatile SC_CSC_COLOR_COFFB_HI;
extern xdata UCHAR volatile SC_CSC_COLOR_COFFC_LO;
extern xdata UCHAR volatile SC_CSC_COLOR_COFFC_HI;
extern xdata UCHAR volatile SC_CSC_COLOR_COFFD_LO;
extern xdata UCHAR volatile SC_CSC_COLOR_COFFD_HI;
extern xdata UCHAR volatile SC_CSC_COLOR_COFFE_LO;
extern xdata UCHAR volatile SC_CSC_COLOR_COFFE_HI;
extern xdata UCHAR volatile SC_BK_H_SHAP_CTRL;
    #define BK_H_ASRP           BIT6
    #define BK_H_SRPSMO         BIT4
    #define BK_H_SRP            0x0F
extern xdata UCHAR volatile SC_BK_CTRL1;
extern xdata UCHAR volatile SC_INTE_CTRL;
extern xdata UCHAR volatile SC_GAMMA_CTRL;
    #define GAMMA_EN            BIT7
    #define TBL_8_10B_SEL       BIT6
extern xdata UCHAR volatile SC_BK_V_SHAP_CTRL;
extern xdata UCHAR volatile SC_INTERPOLATION_THRESHOLD;
extern xdata UCHAR volatile SC_NR_CTRL;
extern xdata UCHAR volatile SC_NR_THR_CTRL1;
extern xdata UCHAR volatile SC_JITTER_CTRL;
extern xdata UCHAR volatile SC_NR_THR_CTRL2;
extern xdata UCHAR volatile SC_VER_INTERPOLATION_OFFSET;
extern xdata UCHAR volatile SC_NR_RANDOM_GENERATOR_CTRL;
extern xdata UCHAR volatile SC_NR3_CTRL1;
extern xdata UCHAR volatile SC_NR3_CTRL2;
extern xdata UCHAR volatile SC_GPIO_CTRL;
extern xdata UCHAR volatile SC_BP_SYNC_CTRL;
//extern xdata UCHAR volatile SC_PWMA_LCNT;
//extern xdata UCHAR volatile SC_PWMA_HCNT;
//extern xdata UCHAR volatile SC_PWMB_LCNT;
extern xdata UCHAR volatile SC_DPPPAPHY_ADDR_HI;
extern xdata UCHAR volatile SC_DPPPAPHY_ADDR_LO;
extern xdata UCHAR volatile SC_DPPPAPHY_DATA;
//extern xdata UCHAR volatile SC_PWMB_HCNT;
//extern xdata UCHAR volatile SC_PWMA_DUTY_LO;
//extern xdata UCHAR volatile SC_PWMB_DUTY_LO;
//extern xdata UCHAR volatile SC_PWM_COUNTER;
//extern xdata UCHAR volatile SC_PWM_CTRL1;
//extern xdata UCHAR volatile SC_PWM_CTRL2;
extern xdata UCHAR volatile SC_OSD_CTRL1;
extern xdata UCHAR volatile SC_OSD_HS_LO;
extern xdata UCHAR volatile SC_OSD_HS_HI;
extern xdata UCHAR volatile SC_OSD_HW;
extern xdata UCHAR volatile SC_OSD_VS_LO;
extern xdata UCHAR volatile SC_OSD_VS_HI;
extern xdata UCHAR volatile SC_OSD_VH;
extern xdata UCHAR volatile SC_OSD_SHIFT_ROW;
extern xdata UCHAR volatile SC_OSD_FONT1B_ADDR_LO;
extern xdata UCHAR volatile SC_OSD_FONT1B_ADDR_HI;
extern xdata UCHAR volatile SC_OSD_FONT2B_ADDR_LO;
extern xdata UCHAR volatile SC_OSD_FONT2B_ADDR_HI;
extern xdata UCHAR volatile SC_OSD_FONT4B_ADDR_LO;
extern xdata UCHAR volatile SC_OSD_FONT4B_ADDR_HI;
extern xdata UCHAR volatile SC_OSD_FADE_STEP;
extern xdata UCHAR volatile SC_OSD_FADE_FREQ;

extern xdata UCHAR volatile SC_OSD_ZOOM_CTL;
extern xdata UCHAR volatile SC_OSD_HZM_PATN_LO;
extern xdata UCHAR volatile SC_OSD_HZM_PATN_HI;
extern xdata UCHAR volatile SC_OSD_VZM_PATN_LO;
extern xdata UCHAR volatile SC_OSD_VZM_PATN_MI;
extern xdata UCHAR volatile SC_OSD_VHGLOB_ZMRNG;

extern xdata UCHAR volatile SC_OSD_HOR_ROW_ZOOM_CTRL1;
extern xdata UCHAR volatile SC_OSD_HOR_ROW_ZOOM_CTRL2;
extern xdata UCHAR volatile SC_OSD_HOR_ROW_ZOOM_CTRL3;
extern xdata UCHAR volatile SC_OSD_HOR_ROW_ZOOM_CTRL4;
extern xdata UCHAR volatile SC_OSD_VER_ROW_ZOOM_CTRL1;
extern xdata UCHAR volatile SC_OSD_VER_ROW_ZOOM_CTRL2;
extern xdata UCHAR volatile SC_OSD_VER_ROW_ZOOM_CTRL3;
extern xdata UCHAR volatile SC_OSD_VER_ROW_ZOOM_CTRL4;
extern xdata UCHAR volatile SC_OSD_FONT_ROW_ZOOM_RANGE;
extern xdata UCHAR volatile SC_OSD_SEPARATE_ROW_CTRL;
extern xdata UCHAR volatile SC_OSD_BLINK_CTRL;
extern xdata UCHAR volatile SC_OSD_TRANSLUCENT_CTL;
extern xdata UCHAR volatile SC_OSD_SPACE_CTL;

extern xdata UCHAR volatile SC_OSD_WIN_SEL;
extern xdata UCHAR volatile SC_OSD_WIN_ATTRIBUTE;
extern xdata UCHAR volatile SC_OSD_WIN_COLOR;
extern xdata UCHAR volatile SC_OSD_WIN_BEVEL_WIDTH;
extern xdata UCHAR volatile SC_OSD_WIN_BEVEL_COLOR_R;
extern xdata UCHAR volatile SC_OSD_WIN_BEVEL_COLOR_L;
extern xdata UCHAR volatile SC_OSD_SHADOW_CTRL_BYTE0;
extern xdata UCHAR volatile SC_OSD_SHADOW_CTRL_BYTE1;
extern xdata UCHAR volatile SC_OSD_SHADOW_CTRL_BYTE2;
extern xdata UCHAR volatile SC_OSD_SHADOW_CTRL_BYTE3;
extern xdata UCHAR volatile SC_OSD_BORDER_CTRL_BYTE0;
extern xdata UCHAR volatile SC_OSD_BORDER_CTRL_BYTE1;
extern xdata UCHAR volatile SC_OSD_BORDER_CTRL_BYTE2;
extern xdata UCHAR volatile SC_OSD_BORDER_CTRL_BYTE3;
extern xdata UCHAR volatile SC_OSD_BOR_SHA_COLOR_01;
extern xdata UCHAR volatile SC_OSD_BOR_SHA_COL_23;
extern xdata UCHAR volatile SC_OSD_BOR_SHA_COL_45;
extern xdata UCHAR volatile SC_OSD_BOR_SHA_COL_67;
extern xdata UCHAR volatile SC_OSD_BOR_SHA_COL_89;
extern xdata UCHAR volatile SC_OSD_BOR_SHA_COL_1011;
extern xdata UCHAR volatile SC_OSD_BOR_SHA_COL_1213;
extern xdata UCHAR volatile SC_OSD_BOR_SHA_COL_1415;
extern xdata UCHAR volatile SC_OSD_BOR_SHA_COL_1617;
extern xdata UCHAR volatile SC_OSD_BOR_SHA_COL_1819;
extern xdata UCHAR volatile SC_OSD_BOR_SHA_COL_2021;
extern xdata UCHAR volatile SC_OSD_BOR_SHA_COL_2223;
extern xdata UCHAR volatile SC_OSD_BOR_SHA_COL_2425;
extern xdata UCHAR volatile SC_OSD_BOR_SHA_COL_2627;
extern xdata UCHAR volatile SC_OSD_BOR_SHA_COL_2829;
extern xdata UCHAR volatile SC_OSD_BOR_SHA_COL_3031;
extern xdata UCHAR volatile SC_OSD_HOR_SPLIT_START_LO;
extern xdata UCHAR volatile SC_OSD_HOR_SPLIT_WIDTH_LO;
extern xdata UCHAR volatile SC_OSD_VER_SPLIT_START_LO;
extern xdata UCHAR volatile SC_OSD_VER_SPLIT_WIDTH_LO;
extern xdata UCHAR volatile SC_OSD_ATTRIBUTE_LO;
extern xdata UCHAR volatile SC_OSD_ATTRIBUTE_MI;
extern xdata UCHAR volatile SC_OSD_CODE_FC;
extern xdata UCHAR volatile SC_OSD_CODE_FC_CTL;
extern xdata UCHAR volatile SC_HPLL_CTRL1;
extern xdata UCHAR volatile SC_HPLL_FREQ_CTRL;
extern xdata UCHAR volatile SC_HSDDS_RATIO_LO;
extern xdata UCHAR volatile SC_HSDDS_RATIO_MI;
extern xdata UCHAR volatile SC_HSDDS_RATIO_HI;
extern xdata UCHAR volatile SC_HPLL_PHASE_CTRL;
extern xdata UCHAR volatile SC_HPLL_CTRL2;
extern xdata UCHAR volatile SC_HSDDS_DIVIDER_LO;
extern xdata UCHAR volatile SC_HSDDS_DIVIDER_HI;
extern xdata UCHAR volatile SC_HPLL_PHASE_CTRL1;
extern xdata UCHAR volatile SC_HPLL_PHASE_CTRL2;
extern xdata UCHAR volatile SC_HPLL_LINE_CNT;
extern xdata UCHAR volatile SC_HPLL_CTRL3;
extern xdata UCHAR volatile SC_HS_CNT_RESULT_LO;
extern xdata UCHAR volatile SC_HS_CNT_RESULT_MI;
extern xdata UCHAR volatile SC_HS_CNT_RESULT_HI;
extern xdata UCHAR volatile SC_INDEX_CTRL;
    #define GAMMA_TBL_RED       0x00
    #define GAMMA_TBL_GREEN     0x10
    #define GAMMA_TBL_BLUE      0x20
    #define GAMMA_TBL_RGB       0x30
    #define OSD_CODE            0x40
    #define OSD_ATTR_MSB        0x50
    #define OSD_ATTR_LSB        0x60
    #define OSD_ATTR            0x70
    #define OSD_CODE_ATTR       0x80
    #define OSD_HOST_CODE_ATTR  0x90
    #define OSD_FONT_1BIT       0xA0
    #define OSD_FONT_2BIT       0xB0
    #define OSD_FONT_4BIT       0xC0
    #define OSD_PALETTE         0xD0
    #define HDCP_TBL            0xE0
    #define OD_TBL              0xF0
    #define PORT_RW             BIT3
    #define PREGAMMA_TBL_RED    0x42
    #define PREGAMMA_TBL_GREEN  0x52
    #define PREGAMMA_TBL_BLUE   0x62
    #define PREGAMMA_TBL_RGB    0x72
    #define REVGAMMA_TBL_RED    0x82
    #define REVGAMMA_TBL_GREEN  0x92
    #define REVGAMMA_TBL_BLUE   0xA2
    #define REVGAMMA_TBL_RGB    0xB2

extern xdata UCHAR volatile SC_INDEX_ADDR_LO;
extern xdata UCHAR volatile SC_INDEX_ADDR_HI;
extern xdata UCHAR volatile SC_INDEX_DATA;
extern xdata UCHAR volatile SC_INDEX_DATA2;
extern xdata UCHAR volatile SC_AUTO_GAIN_WIN_ODD_VER_BEG_LO;
extern xdata UCHAR volatile SC_AUTO_GAIN_WIN_ODD_VER_BEG_HI;
extern xdata UCHAR volatile SC_AUTO_GAIN_WIN_EVEN_VER_BEG_LO;
extern xdata UCHAR volatile SC_AUTO_GAIN_WIN_EVEN_VER_BEG_HI;
extern xdata UCHAR volatile SC_AUTO_GAIN_WIN_VER_LEN_LO;
extern xdata UCHAR volatile SC_AUTO_GAIN_WIN_VER_LEN_HI;
extern xdata UCHAR volatile SC_AUTO_GAIN_WIN_HOR_BEG_LO;
extern xdata UCHAR volatile SC_AUTO_GAIN_WIN_HOR_BEG_HI;
extern xdata UCHAR volatile SC_AUTO_GAIN_WIN_HOR_WIDTH_LO;
extern xdata UCHAR volatile SC_AUTO_GAIN_WIN_HOR_WIDTH_HI;
extern xdata UCHAR volatile SC_DPLL_CTRL1;
extern xdata UCHAR volatile SC_DPLL_FREQ_CTRL;
extern xdata UCHAR volatile SC_DDDS_RATIO_LO;
extern xdata UCHAR volatile SC_DDDS_RATIO_MI;
extern xdata UCHAR volatile SC_DDDS_RATIO_HI;
extern xdata UCHAR volatile SC_SSC_CTRL;
extern xdata UCHAR volatile SC_GAUGE_CTRL1;
extern xdata UCHAR volatile SC_GAUGE_CTRL2;
extern xdata UCHAR volatile SC_GAUGE_AREA_SEL;
extern xdata UCHAR volatile SC_GAUGE_OFFSET;
extern xdata UCHAR volatile SC_GAUGE_RESULT_LO;
extern xdata UCHAR volatile SC_GAUGE_RESULT_MI;
extern xdata UCHAR volatile SC_GAUGE_RESULT_HI;
extern xdata UCHAR volatile SC_RegPage;
extern xdata UCHAR volatile SC_PRODUCT_ID;
extern xdata UCHAR volatile SC_POWER_CTRL1;
extern xdata UCHAR volatile SC_POWER_CTRL2;
extern xdata UCHAR volatile SC_POWER_CTRL3;
extern xdata UCHAR volatile SC_REVISION_ID;
extern xdata UCHAR volatile SC_CHIP_ID;
extern xdata UCHAR volatile SC_GI_AUTO_TUNE_CTRL;
extern xdata UCHAR volatile SC_GI_POS_THR;
extern xdata UCHAR volatile SC_GI_POS_VBEGO_LO;
extern xdata UCHAR volatile SC_GI_POS_VBEGO_HI;
extern xdata UCHAR volatile SC_GI_POS_VBEGE_LO;
extern xdata UCHAR volatile SC_GI_POS_VBEGE_HI;
extern xdata UCHAR volatile SC_GI_POS_VLEN_LO;
extern xdata UCHAR volatile SC_GI_POS_VLEN_HI;
extern xdata UCHAR volatile SC_GI_POS_HBEG_LO;
extern xdata UCHAR volatile SC_GI_POS_HBEG_HI;
extern xdata UCHAR volatile SC_GI_POS_HWID_LO;
extern xdata UCHAR volatile SC_GI_POS_HWID_HI;
extern xdata UCHAR volatile SC_GI_PHS_MASK;
extern xdata UCHAR volatile SC_GI_PHS_SDIFF_LO0;
extern xdata UCHAR volatile SC_GI_PHS_SDIFF_LO1;
extern xdata UCHAR volatile SC_GI_PHS_SDIFF_HI0;
extern xdata UCHAR volatile SC_GI_PHS_SDIFF_HI1;
extern xdata UCHAR volatile SC_GI_CLK_REF_LO;
extern xdata UCHAR volatile SC_GI_CLK_REF_HI;
extern xdata UCHAR volatile SC_GI_CLK_RESULT;
extern xdata UCHAR volatile SC_VI_AUTO_CTRL;
extern xdata UCHAR volatile SC_AUTO_OFFSET_ATART_LO;
extern xdata UCHAR volatile SC_AUTO_OFFSET_ATART_HI;
extern xdata UCHAR volatile SC_REDUCE_ADC_PWR_CTRL;
extern xdata UCHAR volatile SC_CAPTURE_CLK_MASK_WIN_BEG_LO;
extern xdata UCHAR volatile SC_CAPTURE_CLK_MASK_WIN_BEG_HI;
extern xdata UCHAR volatile SC_CAPTURE_CLK_MASK_WIN_END_LO;
extern xdata UCHAR volatile SC_CAPTURE_CLK_MASK_WIN_END_HI;
extern xdata UCHAR volatile SC_ADC_BLANK_PWR_DOWN_BEG_LO;
extern xdata UCHAR volatile SC_ADC_BLANK_PWR_DOWN_BEG_HI;
extern xdata UCHAR volatile SC_ADC_BLANK_PWR_DOWN_END_LO;
extern xdata UCHAR volatile SC_ADC_BLANK_PWR_DOWN_END_HI;
extern xdata UCHAR volatile SC_AUTO_GAIN_CTRL1;
extern xdata UCHAR volatile SC_AUTO_GAIN_CTRL2;
extern xdata UCHAR volatile SC_AUTO_GAIN_CTRL3;
extern xdata UCHAR volatile SC_AUTO_GAIN_CTRL4;
extern xdata UCHAR volatile SC_AUTO_GAIN_CTRL5;
extern xdata UCHAR volatile SC_BRIGHT_FRM_CTRL;
    #define BRIGHT_FRM2_EN      BIT1
    #define BRIGHT_FRM1_EN      BIT0
extern xdata UCHAR volatile SC_BRIGHT_FRM_SEL;
extern xdata UCHAR volatile SC_BRIGHT_FRM_HS_LO;
extern xdata UCHAR volatile SC_BRIGHT_FRM_HS_HI;
extern xdata UCHAR volatile SC_BRIGHT_FRM_HW_LO;
extern xdata UCHAR volatile SC_BRIGHT_FRM_HW_HI;
extern xdata UCHAR volatile SC_BRIGHT_FRM_VS_LO;
extern xdata UCHAR volatile SC_BRIGHT_FRM_VS_HI;
extern xdata UCHAR volatile SC_BRIGHT_FRM_VH_LO;
extern xdata UCHAR volatile SC_BRIGHT_FRM_VH_HI;
extern xdata UCHAR volatile SC_BRIGHT_FRM_GAIN;
extern xdata UCHAR volatile SC_BRIGHT_FRM_OFFSET;
extern xdata UCHAR volatile SC_POST_PATTERN_GRAY_LEVEL_HI;
extern xdata UCHAR volatile SC_POST_PATTERN_GRAY_LEVEL_LO;
extern xdata UCHAR volatile SC_CAP_HTOTAL_LENGTH_LO;
extern xdata UCHAR volatile SC_CAP_HTOTAL_LENGTH_HI;
extern xdata UCHAR volatile SC_LOCK_H_SHIFT_LO;
extern xdata UCHAR volatile SC_LOCK_H_SHIFT_HI;

extern xdata UCHAR volatile SC_DISPLAY_CTRL;
extern xdata UCHAR volatile SC_DISPLAY_VLOCK;
extern xdata UCHAR volatile SC_DISPLAY_HLOCK_LO;
extern xdata UCHAR volatile SC_DISPLAY_HLOCK_HI;
extern xdata UCHAR volatile SC_DISPLAY_MUTE_CTRL;
    #define POSTPTN_GAMMA_CORRECTION    0x00 //0000 = Gamma Correction pattern
    #define POSTPTN_DOT_MOIRE           0x10 //0001 = Dot Moire
    #define POSTPTN_V1B1W               0x20 //0010 = Vertical Line Moire (1B1W)
    #define POSTPTN_V2B1W               0x30 //0011 = Vertical Line Moire (2B1W)
    #define POSTPTN_V2B2W               0x40 //0100 = Vertical Line Moire (2B2W)
    #define POSTPTN_V256_GRAY           0x50 //0101 = 256 V_Gray Bar
    #define POSTPTN_H256_GRAY           0x60 //0110 = 256 H_Gray Bar
    #define POSTPTN_H1B1W               0x70 //0111 = Horizontal Line Moire (1B1W)
    #define POSTPTN_H2B1W               0x80 //1000 = Horizontal Line Moire (2B1W)
    #define POSTPTN_H2B2W               0x90 //1001 = Horizontal Line Moire (2B2W)
    #define POSTPTN_CHAT                0xA0 //1010 = Chat Pattern
    #define POSTPTN_WHITE               0xB0 //1011 = White Pattern
    #define POSTPTN_RECT1               0xC0 //1100 = Rectangular pattern, outline width 1 pixel
    #define POSTPTN_RECT3               0xD0 //1101 = Rectangular pattern, outline width 3 pixels
    #define POSTPTN_RECT5               0xE0 //1110 = Rectangular pattern, outline width 5 pixels
    #define POSTPTN_RECT7               0xF0 //1111 = Rectangular pattern, outline width 7 pixels
    #define POSTPTN_BLACK               0x08 //0000 = Black pattern
    #define POSTPTN_GRAY                0x18 //0001 = Gray pattern
    #define POSTPTN_V64_GRAY            0x28 //0010 = 64 V_Gray Bar
    #define POSTPTN_H64_GRAY            0x38 //0011 = 64 H_Gray Bar
    #define POSTPTN_COLOR_DOT           0x48 //0100 = Color Dot Moire
    #define POSTPTN_COLOR_LINE          0x58 //0101 = Color Line Moire
    #define POSTPTN_V1024_GRAY          0xB8 //1101 = 1024 V_Gray
    #define POSTPTN_H1024_GRAY          0xE8 //1110 = 1024 H_Gray

extern xdata UCHAR volatile SC_DISP_DRIVE_CTRL;
extern xdata UCHAR volatile SC_DISPLAY_POL_CTRL;
extern xdata UCHAR volatile SC_DISPLAY_CLK_CTRL;
extern xdata UCHAR volatile SC_DITH_CTRL;
extern xdata UCHAR volatile SC_DISPLAY_CHANNEL;
extern xdata UCHAR volatile SC_CBAR_FG;
extern xdata UCHAR volatile SC_DV_TOTAL_LO;
extern xdata UCHAR volatile SC_DV_TOTAL_HI;
extern xdata UCHAR volatile SC_DV_VS_WID;
extern xdata UCHAR volatile SC_DH_HTOTAL_LO;
extern xdata UCHAR volatile SC_DH_HTOTAL_HI;
extern xdata UCHAR volatile SC_DH_HS_WID;
extern xdata UCHAR volatile SC_DISPLAY_BR_CTRL;
extern xdata UCHAR volatile SC_DV_BG_BEG_LO;
extern xdata UCHAR volatile SC_DV_BG_BEG_HI;
extern xdata UCHAR volatile SC_DV_BG_LEN_LO;
extern xdata UCHAR volatile SC_DV_BG_LEN_HI;
extern xdata UCHAR volatile SC_DH_BG_BEG_LO;
extern xdata UCHAR volatile SC_DH_BG_BEG_HI;
extern xdata UCHAR volatile SC_DH_BG_WID_LO;
extern xdata UCHAR volatile SC_DH_BG_WID_HI;
extern xdata UCHAR volatile SC_DISP_SWAP;
extern xdata UCHAR volatile SC_DISP_BACKGROUND_RED;
extern xdata UCHAR volatile SC_DISP_BACKGROUND_GREEN;
extern xdata UCHAR volatile SC_DISP_BACKGROUND_BLUE;
extern xdata UCHAR volatile SC_GRAPHIC_DISP_WIN_CTRL;
extern xdata UCHAR volatile SC_GRAPHIC_DISP_VER_ACT_BEG_LO;
extern xdata UCHAR volatile SC_GRAPHIC_DISP_VER_ACT_BEG_HI;
extern xdata UCHAR volatile SC_GRAPHIC_DISP_VER_ACT_LEN_LO;
extern xdata UCHAR volatile SC_GRAPHIC_DISP_VER_ACT_LEN_HI;
extern xdata UCHAR volatile SC_GRAPHIC_DISP_HOR_ACT_BEG_LO;
extern xdata UCHAR volatile SC_GRAPHIC_DISP_HOR_ACT_BEG_HI;
extern xdata UCHAR volatile SC_GRAPHIC_DISP_HOR_ACT_WID_LO;
extern xdata UCHAR volatile SC_GRAPHIC_DISP_HOR_ACT_WID_HI;
extern xdata UCHAR volatile SC_DISP_HLOCK_POS_R;
extern xdata UCHAR volatile SC_DISP_VLOCK_POS_R;
extern xdata UCHAR volatile SC_FREE_RUN_HTOTAL_LO;
extern xdata UCHAR volatile SC_FREE_RUN_HTOTAL_HI;
extern xdata UCHAR volatile SC_SCALER_DE_EXT_2DTO3D;
extern xdata UCHAR volatile SC_DSP_HTOTAL_LO;
extern xdata UCHAR volatile SC_DSP_HTOTAL_HI;
extern xdata UCHAR volatile SC_HR_VALUE_LO;
extern xdata UCHAR volatile SC_HR_VALUE_HI;
extern xdata UCHAR volatile SC_HR_CTRL;
extern xdata UCHAR volatile SC_DISP_SYNC_STATUS;
extern xdata UCHAR volatile SC_VCR_CTRL;
extern xdata UCHAR volatile SC_VER_COUNTER_LO;
extern xdata UCHAR volatile SC_VER_COUNTER_MI;
extern xdata UCHAR volatile SC_VER_COUNTER_HI;
extern xdata UCHAR volatile SC_RESIDUAL_DISP_HOR_SYNC_CTRL;
extern xdata UCHAR volatile SC_FIFO_FLAG;
extern xdata UCHAR volatile SC_FIFO_FLAG_EN;
extern xdata UCHAR volatile SC_FIFO_CTRL1;
extern xdata UCHAR volatile SC_FIFO_CTRL2;
extern xdata UCHAR volatile SC_GI_SYNC_CTRL;
extern xdata UCHAR volatile SC_GI_SYNC_CTRL2;
extern xdata UCHAR volatile SC_GI_FIELD_WIN;
extern xdata UCHAR volatile SC_GI_SYNC_CTRL3;
extern xdata UCHAR volatile SC_GI_SYNC_STATUS;
extern xdata UCHAR volatile SC_GI_HCNT_LO;
extern xdata UCHAR volatile SC_GI_HCNT_HI;
extern xdata UCHAR volatile SC_GI_VCNT_LO;
extern xdata UCHAR volatile SC_GI_VCNT_HI;
extern xdata UCHAR volatile SC_HREE_DIV_LO;
extern xdata UCHAR volatile SC_HREE_DIV_HI;
extern xdata UCHAR volatile SC_VREE_DIV_LO;
extern xdata UCHAR volatile SC_VREE_DIV_HI;
extern xdata UCHAR volatile SC_HPRE_THR_LO;
extern xdata UCHAR volatile SC_HPRE_THR_HI;
extern xdata UCHAR volatile SC_VPRE_THR_LO;
extern xdata UCHAR volatile SC_VPRE_THR_HI;
extern xdata UCHAR volatile SC_HCNT_THR;
extern xdata UCHAR volatile SC_V_CHANG_CTRL;
extern xdata UCHAR volatile SC_SYNC_INT_EN1;
extern xdata UCHAR volatile SC_SYNC_INT_EN2;
extern xdata UCHAR volatile SC_SYNC_INT_FLAG1;
extern xdata UCHAR volatile SC_SYNC_INT_FLAG2;
extern xdata UCHAR volatile SC_DVI_STATUS;
extern xdata UCHAR volatile SC_MACROVISION_THRESHOLD;
extern xdata UCHAR volatile SC_FAST_MUTE_CTRL;
extern xdata UCHAR volatile SC_FIELD_POLARITY_CTRL;
extern xdata UCHAR volatile SC_GI_HS_WID;
extern xdata UCHAR volatile SC_GI_VS_WID;
extern xdata UCHAR volatile SC_PRE_COAST;
extern xdata UCHAR volatile SC_POS_COAST;
extern xdata UCHAR volatile SC_GRAPHIC_VTOTAL_COUNTER_LO;
extern xdata UCHAR volatile SC_GRAPHIC_VTOTAL_COUNTER_HI;
extern xdata UCHAR volatile SC_LVDS_CTRL;
extern xdata UCHAR volatile SC_DISP_INTERFACE_CTRL;
extern xdata UCHAR volatile SC_AUTO_OFFSET_CTRL1;
extern xdata UCHAR volatile SC_AUTO_OFFSET_CTRL2;
extern xdata UCHAR volatile SC_AUTO_OFFSET_CTRL3;
extern xdata UCHAR volatile SC_AUTO_OFFSET_TARGET_RED;
extern xdata UCHAR volatile SC_AUTO_OFFSET_TARGET_GREEN;
extern xdata UCHAR volatile SC_AUTO_OFFSET_TARGET_BLUE;
extern xdata UCHAR volatile SC_AUTO_OFFSET_ADJUST_RED;
extern xdata UCHAR volatile SC_AUTO_OFFSET_ADJUST_GREEN;
extern xdata UCHAR volatile SC_AUTO_OFFSET_ADJUST_BLUE;
extern xdata UCHAR volatile SC_AUTO_OFFSET_MID_RED;
extern xdata UCHAR volatile SC_AUTO_OFFSET_MID_GREEN;
extern xdata UCHAR volatile SC_AUTO_OFFSET_MID_BLUE;
extern xdata UCHAR volatile SC_INSIDE_CTRL3;
extern xdata UCHAR volatile SC_DATA_TRACK_CTRL;
extern xdata UCHAR volatile SC_DATA_TRACK_MASK1;
extern xdata UCHAR volatile SC_DATA_TRACK_MASK2;
extern xdata UCHAR volatile SC_DATA_TRACK_MASK3;
extern xdata UCHAR volatile SC_DATA_TRACK_MASK4;
extern xdata UCHAR volatile SC_ASYNC_RANDOM_DITHRER_CTRL;
extern xdata UCHAR volatile SC_AUTO_OFFSET_CTRL4;
extern xdata UCHAR volatile SC_AUTO_OFFSET_HCNT_MODE01;
extern xdata UCHAR volatile SC_AUTO_OFFSET_HCNT_MODE11;
extern xdata UCHAR volatile SC_SRGB_CTRL;
extern xdata UCHAR volatile SC_SRGB_COEF_R_LO;
extern xdata UCHAR volatile SC_SRGB_COEF_R_HI;
extern xdata UCHAR volatile SC_SRGB_COEF_G_LO;
extern xdata UCHAR volatile SC_SRGB_COEF_G_HI;
extern xdata UCHAR volatile SC_SRGB_COEF_B_LO;
extern xdata UCHAR volatile SC_SRGB_COEF_B_HI;
extern xdata UCHAR volatile SC_SRGB_COEF_OFFSET;
extern xdata UCHAR volatile SC_SRGB_DITH_CTRL;
extern xdata UCHAR volatile SC_DISP_DITH_CTRL;
extern xdata UCHAR volatile SC_DISP_RANDOM_DITH_CTRL;
extern xdata UCHAR volatile SC_GAMMA_DITH_CTRL;
extern xdata UCHAR volatile SC_MISC_O_RD_LO;
extern xdata UCHAR volatile SC_MISC_O_RD_HI;
extern xdata UCHAR volatile SC_MISC_E_RD_LO;
extern xdata UCHAR volatile SC_MISC_E_RD_HI;
extern xdata UCHAR volatile SC_INV_GR;
extern xdata UCHAR volatile SC_INV_BR;
extern xdata UCHAR volatile SC_TEST_MODE1_LOCKER;
extern xdata UCHAR volatile SC_TEST_MODE1;
extern xdata UCHAR volatile SC_TEST_MODE2;
extern xdata UCHAR volatile SC_TEST_MODE3;
extern xdata UCHAR volatile SC_ADC_TEST_MODE;
extern xdata UCHAR volatile SC_TMDS_LINK_CLK_SEL;
extern xdata UCHAR volatile SC_BIST_CTRL1;
extern xdata UCHAR volatile SC_BIST_CTRL2;
#if IS_NT68870_SERIES
extern xdata UCHAR volatile SC_DP_LINK_CLK_SEL;
extern xdata UCHAR volatile SC_ADC_REG_1D;
#else
extern xdata UCHAR volatile SC_ADC_REG_1D;
#endif
extern xdata UCHAR volatile SC_ADC_COMP_CTRL;
extern xdata UCHAR volatile SC_ADC_BAND_GAP;
extern xdata UCHAR volatile SC_BYPASS_CTRL;
extern xdata UCHAR volatile SC_LVDS_RSDS_SWITCH;
extern xdata UCHAR volatile SC_LVDS_DIV;
extern xdata UCHAR volatile SC_ADC_OP_CURRENT;
extern xdata UCHAR volatile SC_LVDS_ISOLATION;
extern xdata UCHAR volatile SC_ADC_TEST2_CTRL;
extern xdata UCHAR volatile SC_LVDS_CHARGE_PUMP_CURRENT;
extern xdata UCHAR volatile SC_LVDS_MISC_CTRL1;
extern xdata UCHAR volatile SC_LVDS_MISC_CTRL2;
extern xdata UCHAR volatile SC_LVDS_MISC_CTRL3;
extern xdata UCHAR volatile SC_LVDS_MISC_CTRL4;
extern xdata UCHAR volatile SC_LVDS_MISC_CTRL5;
extern xdata UCHAR volatile SC_LVDS_MISC_CTRL6;
extern xdata UCHAR volatile SC_LVDS_DATA_DELAY;
extern xdata UCHAR volatile SC_LVDS_CLOCK_DELAY;
extern xdata UCHAR volatile SC_LVDS_PLL_CTRL;
extern xdata UCHAR volatile SC_LVDS_PAD_POWER;
extern xdata UCHAR volatile SC_DITHER_CTRL_38D;

extern xdata UCHAR volatile SC_CBUS_DEV_STATE;
extern xdata UCHAR volatile SC_CBUS_MHL_VER;
extern xdata UCHAR volatile SC_CBUS_DEV_CAT;
extern xdata UCHAR volatile SC_CBUS_ADOPTER_ID_H;
extern xdata UCHAR volatile SC_CBUS_ADOPTER_ID_L;
extern xdata UCHAR volatile SC_CBUS_VID_LINK_MODE;
extern xdata UCHAR volatile SC_CBUS_AUD_LINK_MODE;
extern xdata UCHAR volatile SC_CBUS_VIDEO_TYPE;
extern xdata UCHAR volatile SC_CBUS_LOG_DEV_MAP;
extern xdata UCHAR volatile SC_CBUS_BANDWIDTH;
extern xdata UCHAR volatile SC_CBUS_FEATURE_FLAG;
extern xdata UCHAR volatile SC_CBUS_DEVICE_ID_H;
extern xdata UCHAR volatile SC_CBUS_DEVICE_ID_L;
extern xdata UCHAR volatile SC_CBUS_SCRATCHPAD_SIZE;
extern xdata UCHAR volatile SC_CBUS_INT_STAT_SIZE;

extern xdata UCHAR volatile RCP_TEST;//Reserved
extern xdata UCHAR volatile SC_CBUS_TRANS_FLAG0;
	#define	MSC_CMD_READ_VALID	BIT7
	#define	MSC_DATA_READ_VALID	BIT6
	#define	DDC_CMD_READ_VALID	BIT5
	#define	DDC_DATA_READ_VALID	BIT4
	#define	VDR_CMD_READ_VALID	BIT3
	#define	VDR_DATA_READ_VALID	BIT2
extern xdata UCHAR volatile SC_CBUS_RX_DATA;
extern xdata UCHAR volatile SC_CBUS_TRANS_FLAG1;
	#define	WROUT_VALID				BIT7
extern xdata UCHAR volatile SC_CBUS_MSC_CMD;
extern xdata UCHAR volatile SC_CBUS_MSC_DATA;
extern xdata UCHAR volatile SC_CBUS_DDC_CMD;
extern xdata UCHAR volatile SC_CBUS_DDC_DATA;
extern xdata UCHAR volatile SC_CBUS_VDR_CMD;
extern xdata UCHAR volatile SC_CBUS_VDR_DATA;
extern xdata UCHAR volatile SC_CBUS_MSC_ERROR;
extern xdata UCHAR volatile SC_CBUS_DDC_ERROR;
extern xdata UCHAR volatile SC_CBUS_TRANS_INT_EN;
	#define	CTRANS_INT_EN			BIT7
	#define	I2C_NACK_INT_EN		BIT6
	#define	I2C_ERR_INT_EN			BIT5
	#define	I2C_AUTO_READ_FINISH_EN	BIT4
	#define	I2C_AUTO_READ_ERR_EN	BIT3
extern xdata UCHAR volatile SC_CBUS_TRANS_RESET;

extern xdata UCHAR volatile SC_CBUS_CONTROL;
extern xdata UCHAR volatile SC_VBUS_ENABLE_TIME;
extern xdata UCHAR volatile SC_CBUS_DISCOVERY_TIME;
extern xdata UCHAR volatile SC_DISCOVERY2CONN;
extern xdata UCHAR volatile SC_RXSENSE_EN_TIME;
extern xdata UCHAR volatile SC_CBUS_SINK_CONN;
extern xdata UCHAR volatile SC_REJECT_CBUS_DISCOVERY_PULSE_MIN;
extern xdata UCHAR volatile SC_REJECT_CBUS_DISCOVERY_PULSE_MAX;
extern xdata UCHAR volatile SC_WAKE_MODE;
extern xdata UCHAR volatile SC_SINK_WAKE;
extern xdata UCHAR volatile SC_CBUS_LINK_INT_FLAG;
	#define CBUS_ARB_SUCCESS  BIT3
    #define CBUS_ARB_FAIL     BIT4
extern xdata UCHAR volatile SC_CBUS_LINK_INT_MASK;
extern xdata UCHAR volatile SC_CBUS_DIS_INT_FLAG;
	#define CDSENSE_CHG_INT_FLG     BIT0
	#define CBUS_CONN_INT_FLG	    BIT1
	#define STUCKLOW_INT_FLG 	    BIT2
extern xdata UCHAR volatile SC_CBUS_DIS_INT_FLAG_1;
	#define CDSENSE_INT_FLG 	    BIT0
extern xdata UCHAR volatile SC_CBUS_DIS_INT_MASK;
	#define CDSENSE_CHG_INT_MASK    BIT0
	#define CBUS_CONN_INT_MASK	    BIT1
	#define STUCKLOW_INT_MASK	    BIT2
extern xdata UCHAR volatile SC_CBUS_INT_FLAG;
	#define	DIS_INT_FLG				BIT0
	#define	LINK_INT_FLG			BIT1
	#define	TRANS_INT_FLG			BIT2
	//#define	ECBUS_INTERRUPT			BIT3
	#define CBUS_INTERRUPT          BIT4
	//#define ecbus_bist_done         BIT5
extern xdata UCHAR volatile SC_CBUS_INT_EN;
    #define	DIS_INT_MASK	    	BIT0
	#define	LINK_INT_MASK			BIT1
	#define	TRANS_INT_MASK			BIT2
	//#define	ECBUS_INT_MASK			BIT3
	//#define	ecbus_bist_dont_int_MASK    BIT4

extern xdata UCHAR volatile SC_LINK_CONTROL;
extern xdata UCHAR volatile SC_BIT_TIME_THD_LO;
extern xdata UCHAR volatile SC_BIT_TIME_THD_HI;
extern xdata UCHAR volatile SC_ACK_BIT_INIT_FALLING_EDGE;
extern xdata UCHAR volatile SC_CBUS_ACK_LENGTH;
extern xdata UCHAR volatile SC_CBUS_ARBIT_WIN_LENGTH;
extern xdata UCHAR volatile SC_CBUS_DRV;
extern xdata UCHAR volatile SC_ARBIT_WAIT_TIME1;
extern xdata UCHAR volatile SC_ARBIT_WAIT_TIME2;
extern xdata UCHAR volatile SC_CBUS_NACK_TRY_MAX;
extern xdata UCHAR volatile SC_CBUS_RESISTOR_CTRL;
extern xdata UCHAR volatile SC_CBUS_DEBUG_CTRL;
extern xdata UCHAR volatile SC_MHL_CDSENSE_CTRL;
#if defined(ENABLE_FPGA_MODE)
extern xdata UCHAR volatile SC_FPGA_CDSENSE;
#endif
extern xdata UCHAR volatile SC_MHL_CTRL_2E0;
extern xdata UCHAR volatile SC_18V_LDO_CONTROL;
extern xdata UCHAR volatile SC_CBUS_CHANNEL_SEL;
extern xdata UCHAR volatile SC_CBUS_COUNT;

extern xdata UCHAR volatile SC_DVI_PIXELCLK_LO;
extern xdata UCHAR volatile SC_DVI_PIXELCLK_HI;

extern xdata UCHAR volatile SC_DVI_CTRL_32F; // Yung FPGA need use

extern xdata UCHAR volatile SC_DITHER_TOGGLE_CTRL;
extern xdata UCHAR volatile SC_DITHER_TP_GRAY_LVL_LO;
extern xdata UCHAR volatile SC_DITHER_TP_GRAY_LVL_HI;
extern xdata UCHAR volatile SC_NEW_HSYNC_CTRL1;
extern xdata UCHAR volatile SC_DISPLAY_DITHER_RANDOM;

extern xdata UCHAR volatile SC_BF_WIN_BORDER_CTRL;
extern xdata UCHAR volatile SC_BF_WIN_BORDER_RED;
extern xdata UCHAR volatile SC_BF_WIN_BORDER_GREEN;
extern xdata UCHAR volatile SC_BF_WIN_BORDER_BLUE;
extern xdata UCHAR volatile SC_BF_WIN_BORDER_EN;

extern xdata UCHAR volatile SC_YC_PEAKING_CTRL;
extern xdata UCHAR volatile SC_LUMA_PEAKING_CTRL;
extern xdata UCHAR volatile SC_CHROMA_PEAKING_CTRL;
extern xdata UCHAR volatile SC_LUMA_NOISE_THRESHOLD;
extern xdata UCHAR volatile SC_TEXT_PEAKING_CTRL;
extern xdata UCHAR volatile SC_UNDER_SHOOT_CLAMP_EN;

extern xdata UCHAR volatile SC_ACE_FUNC_CTRL1;
extern xdata UCHAR volatile SC_ACE_FUNC_CTRL2;
extern xdata UCHAR volatile SC_ACE_DATA_PORT;

extern xdata UCHAR volatile SC_CM_COLOR_CTRL;
extern xdata UCHAR volatile SC_CM_BRIGHTNESS_RED;
extern xdata UCHAR volatile SC_CM_BRIGHTNESS_GREEN;
extern xdata UCHAR volatile SC_CM_BRIGHTNESS_BLUE;
extern xdata UCHAR volatile SC_CM_CONTRAST_RED;
extern xdata UCHAR volatile SC_CM_CONTRAST_GREEN;
extern xdata UCHAR volatile SC_CM_CONTRAST_BLUE;
extern xdata UCHAR volatile SC_CM_HUE;
extern xdata UCHAR volatile SC_CM_SATURATION;
extern xdata UCHAR volatile SC_CM_INTENSITY;
extern xdata UCHAR volatile SC_CM_COLOR_ENHANCEMENT_CTRL;
extern xdata UCHAR volatile SC_CM_INDEX_ACCESS_CTRL;
extern xdata UCHAR volatile SC_CM_INDEX_ACCESS_ADDR;
extern xdata UCHAR volatile SC_CM_INDEX_ACCESS_PORT;
extern xdata UCHAR volatile SC_PREPATTERN_CTRL1;
extern xdata UCHAR volatile SC_NEW_OVS_VBEG_LO;
extern xdata UCHAR volatile SC_NEW_OVS_VBEG_HI;
extern xdata UCHAR volatile SC_OVERSCAN_MODE;
extern xdata UCHAR volatile SC_DBC_CTRL;
extern xdata UCHAR volatile SC_DBC_ADJ;
extern xdata UCHAR volatile SC_DBC_PWM_MIN;
extern xdata UCHAR volatile SC_DBC_PWM_DIV1;
extern xdata UCHAR volatile SC_DBC_PWM_DIV2;
extern xdata UCHAR volatile SC_DBC_PWM_DUTY;
extern xdata UCHAR volatile SC_DBC_PWM_CTRL;
extern xdata UCHAR volatile SC_DBC_PWM_OFFSET;
extern xdata UCHAR volatile SC_DBC_AVG_Y;
extern xdata UCHAR volatile SC_EFFECTIVE_COLOR_VALUE;
extern xdata UCHAR volatile SC_DBC_PWM_ACT;
extern xdata UCHAR volatile SC_DBC_POSITION;
extern xdata UCHAR volatile SC_DBC_INDEX_PORT;
extern xdata UCHAR volatile SC_DBC_INDEX_DATA;
extern xdata UCHAR volatile SC_DBC_AVERAGE_MODE;
extern xdata UCHAR volatile SC_DBC_DEBOUNCINT_MODE;
extern xdata UCHAR volatile SC_DBC_NON_LINEAR_GAIN_CTRL;
extern xdata UCHAR volatile SC_DBC_PWM_LUT_LIM;
extern xdata UCHAR volatile SC_DBC_GRAY_LUT_LIM;
extern xdata UCHAR volatile SC_DBC_EXT_CTRL;
extern xdata UCHAR volatile SC_PWMA_CTRL1;
extern xdata UCHAR volatile SC_PWMA_CTRL2;
extern xdata UCHAR volatile SC_PWMA_CTRL3;
extern xdata UCHAR volatile SC_PWMA_CTRL4;
extern xdata UCHAR volatile SC_PWMA_CTRL5;
extern xdata UCHAR volatile SC_PWMA_CTRL6;
extern xdata UCHAR volatile SC_PWMB_CTRL1;
extern xdata UCHAR volatile SC_PWMB_CTRL2;
extern xdata UCHAR volatile SC_PWMB_CTRL3;
extern xdata UCHAR volatile SC_PWMB_CTRL4;
extern xdata UCHAR volatile SC_PWMB_CTRL5;
extern xdata UCHAR volatile SC_PWMB_CTRL6;
extern xdata UCHAR volatile SC_PWMC_CTRL1;
extern xdata UCHAR volatile SC_PWMC_CTRL2;
extern xdata UCHAR volatile SC_PWMC_CTRL3;
extern xdata UCHAR volatile SC_PWMC_CTRL4;
extern xdata UCHAR volatile SC_PWMC_CTRL5;
extern xdata UCHAR volatile SC_PWMC_CTRL6;
extern xdata UCHAR volatile SC_PWMD_CTRL1;
extern xdata UCHAR volatile SC_PWMD_CTRL2;
extern xdata UCHAR volatile SC_PWMD_CTRL3;
extern xdata UCHAR volatile SC_PWMD_CTRL4;
extern xdata UCHAR volatile SC_PWMD_CTRL5;
extern xdata UCHAR volatile SC_PWMD_CTRL6;

extern xdata UCHAR volatile SC_OD_CONFIGURATION;
extern xdata UCHAR volatile SC_OD_MULTI_ZONE_LOW_BOUNDARY_LO;
extern xdata UCHAR volatile SC_OD_MULTI_ZONE_LOW_BOUNDARY_HI;
extern xdata UCHAR volatile SC_OD_MULTI_ZONE_HIGH_BOUNDARY_LO;
extern xdata UCHAR volatile SC_OD_MULTI_ZONE_HIGH_BOUNDARY_HI;
extern xdata UCHAR volatile SC_OD_BTC_CONFIGURATION;
extern xdata UCHAR volatile SC_OD_BTC_CONFIGURATION2;
extern xdata UCHAR volatile SC_OD_STILL_CONFIGURATION;
extern xdata UCHAR volatile SC_OD_STILL_THRESHOLD;
extern xdata UCHAR volatile SC_OD_DCC_THRESHOLD;
extern xdata UCHAR volatile SC_OD_MOTION_CHECK_CFGCONFIGURATION;
extern xdata UCHAR volatile SC_OD_MOTION_AVG_THRESHOLD;
extern xdata UCHAR volatile SC_OD_MOTION_VALUE_THRESHOLD;
extern xdata UCHAR volatile SC_OD_DDC_CONFIGURATION;
extern xdata UCHAR volatile SC_OD_TEST_CONFIGURATION;
extern xdata UCHAR volatile SC_OD_TEST_TP_H_MT_STEP;
extern xdata UCHAR volatile SC_OD_TEST_TP_V_MT_STEP;

extern xdata UCHAR volatile SC_OD_MOTION_LOW_THRESHOLD_LO;
extern xdata UCHAR volatile SC_OD_MOTION_LOW_THRESHOLD_MI;
extern xdata UCHAR volatile SC_OD_MOTION_LOW_THRESHOLD_HI;
extern xdata UCHAR volatile SC_OD_MOTION_HIGH_THRESHOLD_LO;
extern xdata UCHAR volatile SC_OD_MOTION_HIGH_THRESHOLD_MI;
extern xdata UCHAR volatile SC_OD_MOTION_HIGH_THRESHOLD_HI;
extern xdata UCHAR volatile SC_OD_MOTION_CHECK_BOUNCE_MONITOR;
extern xdata UCHAR volatile SC_OD_MOTION_CHECK_THRESHOLD;
extern xdata UCHAR volatile SC_OD_MOTION_CHECK_DEBOUNCE;
extern xdata UCHAR volatile SC_OD_MOTION_CHECK_STATUS;

extern xdata UCHAR volatile SC_D_OD_CTRL;
extern xdata UCHAR volatile SC_D_OD_CTRL2;

extern xdata UCHAR volatile SC_AUTO_INTERLACED_CTRL1;
extern xdata UCHAR volatile SC_AUTO_INTERLACED_CTRL2;
extern xdata UCHAR volatile SC_AUTO_INTERLACED_CTRL3;

extern xdata UCHAR volatile SC_D_OD_FRAMERATE_CLASSIFY_CTRL;
extern xdata UCHAR volatile SC_D_OD_FRAMERATE_BOUNDARY1;
extern xdata UCHAR volatile SC_D_OD_FRAMERATE_BOUNDARY2;
extern xdata UCHAR volatile SC_D_OD_PART0_OVERSHOOT_GAIN;
extern xdata UCHAR volatile SC_D_OD_PART0_UNDERSHOOT_GAIN;
extern xdata UCHAR volatile SC_D_OD_PART1_OVERSHOOT_GAIN;
extern xdata UCHAR volatile SC_D_OD_PART1_UNDERSHOOT_GAIN;
extern xdata UCHAR volatile SC_D_OD_PART2_OVERSHOOT_GAIN;
extern xdata UCHAR volatile SC_D_OD_PART2_UNDERSHOOT_GAIN;
extern xdata UCHAR volatile SC_D_OD_PART3_OVERSHOOT_GAIN;
extern xdata UCHAR volatile SC_D_OD_PART3_UNDERSHOOT_GAIN;

extern xdata UCHAR volatile SC_FRAME_BUFFER1_BASE_ADDR_POSTFRC_LO;
extern xdata UCHAR volatile SC_FRAME_BUFFER1_BASE_ADDR_POSTFRC_MI;
extern xdata UCHAR volatile SC_FRAME_BUFFER1_BASE_ADDR_POSTFRC_HI;
extern xdata UCHAR volatile SC_FRAME_BUFFER1_BASE_ADDR_PREFRC_LO;
extern xdata UCHAR volatile SC_FRAME_BUFFER1_BASE_ADDR_PREFRC_MI;
extern xdata UCHAR volatile SC_FRAME_BUFFER1_BASE_ADDR_PREFRC_HI;

extern xdata UCHAR volatile SC_FRAME_BUFFER2_BASE_ADDR_POSTFRC_LO;
extern xdata UCHAR volatile SC_FRAME_BUFFER2_BASE_ADDR_POSTFRC_MI;
extern xdata UCHAR volatile SC_FRAME_BUFFER2_BASE_ADDR_POSTFRC_HI;
extern xdata UCHAR volatile SC_FRAME_BUFFER2_BASE_ADDR_PREFRC_LO;
extern xdata UCHAR volatile SC_FRAME_BUFFER2_BASE_ADDR_PREFRC_MI;
extern xdata UCHAR volatile SC_FRAME_BUFFER2_BASE_ADDR_PREFRC_HI;

extern xdata UCHAR volatile SC_FRAME_BUFFER_BASE_ADDR_OD_LO;
extern xdata UCHAR volatile SC_FRAME_BUFFER_BASE_ADDR_OD_MI;
extern xdata UCHAR volatile SC_FRAME_BUFFER_BASE_ADDR_OD_HI;

extern xdata UCHAR volatile SC_FRC_V_FP;
extern xdata UCHAR volatile SC_FRC_H_FP;
extern xdata UCHAR volatile SC_FRC_VH_FP;
extern xdata UCHAR volatile SC_FRC_CENTER_H_START_LO;
extern xdata UCHAR volatile SC_FRC_CENTER_H_START_HI;
extern xdata UCHAR volatile SC_FRC_CENTER_V_START_LO;
extern xdata UCHAR volatile SC_FRC_CENTER_V_START_HI;
extern xdata UCHAR volatile SC_FRC_CENTER_MODE;

extern xdata UCHAR volatile SC_PREFRC_OUTPUT_H_ACTIVE_LO;
extern xdata UCHAR volatile SC_PREFRC_OUTPUT_H_ACTIVE_HI;
extern xdata UCHAR volatile SC_PREFRC_OUTPUT_H_TOTAL_LO;
extern xdata UCHAR volatile SC_PREFRC_OUTPUT_H_TOTAL_HI;
extern xdata UCHAR volatile SC_PREFRC_OUTPUT_V_ACTIVE_LO;
extern xdata UCHAR volatile SC_PREFRC_OUTPUT_V_ACTIVE_HI;
extern xdata UCHAR volatile SC_PREFRC_OUTPUT_V_TOTAL_LO;
extern xdata UCHAR volatile SC_PREFRC_OUTPUT_V_TOTAL_HI;
extern xdata UCHAR volatile SC_PREFRC_CONTROL;
extern xdata UCHAR volatile SC_PREFRC_RESET;
extern xdata UCHAR volatile SC_PREFRC_53A;
extern xdata UCHAR volatile SC_PREFRC_53B;
extern xdata UCHAR volatile SC_PREFRC_53C;
extern xdata UCHAR volatile SC_PREFRC_53D;
extern xdata UCHAR volatile SC_PREFRC_53E;
extern xdata UCHAR volatile SC_PREFRC_53F;

extern xdata UCHAR volatile SC_FRC_OUTPUT_H_ACTIVE_LO;
extern xdata UCHAR volatile SC_FRC_OUTPUT_H_ACTIVE_HI;
extern xdata UCHAR volatile SC_FRC_OUTPUT_H_TOTAL_LO;
extern xdata UCHAR volatile SC_FRC_OUTPUT_H_TOTAL_HI;
extern xdata UCHAR volatile SC_FRC_OUTPUT_V_ACTIVE_LO;
extern xdata UCHAR volatile SC_FRC_OUTPUT_V_ACTIVE_HI;
extern xdata UCHAR volatile SC_FRC_OUTPUT_V_TOTAL_LO;
extern xdata UCHAR volatile SC_FRC_OUTPUT_V_TOTAL_HI;
extern xdata UCHAR volatile SC_FRC_CTRL;
extern xdata UCHAR volatile SC_FRC_RESET;
extern xdata UCHAR volatile SC_FRC_POINT1_HI;
extern xdata UCHAR volatile SC_FRC_V_POINT1_LO;
extern xdata UCHAR volatile SC_FRC_H_POINT1_LO;
extern xdata UCHAR volatile SC_FRC_POINT2_HI;
extern xdata UCHAR volatile SC_FRC_V_POINT2_LO;
extern xdata UCHAR volatile SC_FRC_H_POINT2_LO;

extern xdata UCHAR volatile SC_DRAM_LINE_BUFFER_DATA_PORT;
extern xdata UCHAR volatile SC_DRAM_LINE_BUFFER_CTRL;
extern xdata UCHAR volatile SC_LINE_BUFFER_BASE_ADDR_LO;
extern xdata UCHAR volatile SC_LINE_BUFFER_BASE_ADDR_MI;
extern xdata UCHAR volatile SC_LINE_BUFFER_BASE_ADDR_HI;
extern xdata UCHAR volatile SC_DRAM_LINE_BUFFER_BASE_QUANTITY;
extern xdata UCHAR volatile SC_LINE_WRITE_SRAM_CTRL_LO;
extern xdata UCHAR volatile SC_LINE_WRITE_SRAM_CTRL_HI;
extern xdata UCHAR volatile SC_LINE_READ_SRAM_CTRL_LO;
extern xdata UCHAR volatile SC_LINE_READ_SRAM_CTRL_HI;
extern xdata UCHAR volatile SC_AUTO_REFLESH_CTRL;
extern xdata UCHAR volatile SC_DRAM_INTERFACE_LO;
extern xdata UCHAR volatile SC_DRAM_INTERFACE_HI;
extern xdata UCHAR volatile SC_DRAM_MMU_MODE;
extern xdata UCHAR volatile SC_DRAM_MMU_MODE_1;
extern xdata UCHAR volatile SC_DRAM_MMU_MODE_2;
extern xdata UCHAR volatile SC_DRAM_MMU_MODE_3;
extern xdata UCHAR volatile SC_DRAM_MMU_REQUEST_W;
extern xdata UCHAR volatile SC_DRAM_MMU_REQUEST_R;
extern xdata UCHAR volatile SC_DDR_PAD_CTRL1;
extern xdata UCHAR volatile SC_DDR_PAD_CTRL2;
extern xdata UCHAR volatile SC_MMU_CFG2;
extern xdata UCHAR volatile SC_MMU_CFG2B;
extern xdata UCHAR volatile SC_MMU_CFG3;

extern xdata UCHAR volatile SC_FRC_FIFO_CTRL0;
extern xdata UCHAR volatile SC_FRC_FIFO_CTRL1;
extern xdata UCHAR volatile SC_FRC_FIFO_CTRL2;
extern xdata UCHAR volatile SC_FRC_FIFO_CTRL3;
extern xdata UCHAR volatile SC_OD_FIFO_CTRL1;
extern xdata UCHAR volatile SC_OD_FIFO_CTRL2;
extern xdata UCHAR volatile SC_OD_FIFO_CTRL3;
extern xdata UCHAR volatile SC_PREFRC_FIFO_CTRL1;
extern xdata UCHAR volatile SC_PREFRC_FIFO_CTRL2;
extern xdata UCHAR volatile SC_PREFRC_FIFO_CTRL3;

extern xdata UCHAR volatile SC_INPUT_PROCESSOR_WRITE_FIFO_ADDR_HI;
extern xdata UCHAR volatile SC_INPUT_PROCESSOR_WRITE_FIFO_ADDR_START;
extern xdata UCHAR volatile SC_INPUT_PROCESSOR_WRITE_FIFO_ADDR_END;
extern xdata UCHAR volatile SC_FRC_WRITE_FIFO_ADDR_HI;
extern xdata UCHAR volatile SC_FRC_WRITE_FIFO_ADDR_START;
extern xdata UCHAR volatile SC_FRC_WRITE_FIFO_ADDR_END;
extern xdata UCHAR volatile SC_OD_WRITE_FIFO_ADDR_HI;
extern xdata UCHAR volatile SC_OD_WRITE_FIFO_ADDR_START;
extern xdata UCHAR volatile SC_OD_WRITE_FIFO_ADDR_END;
extern xdata UCHAR volatile SC_PREFRC_WRITE_FIFO_ADDR_CONTROL1;
extern xdata UCHAR volatile SC_PREFRC_WRITE_FIFO_ADDR_CONTROL2;
extern xdata UCHAR volatile SC_PREFRC_WRITE_FIFO_ADDR_CONTROL3;
    
extern xdata UCHAR volatile SC_DEI_READ_FIFO_F0_ADDR_HI;
extern xdata UCHAR volatile SC_DEI_READ_FIFO_F0_ADDR_START;
extern xdata UCHAR volatile SC_DEI_READ_FIFO_F0_ADDR_END;
extern xdata UCHAR volatile SC_DEI_READ_FIFO_F1_ADDR_HI;
extern xdata UCHAR volatile SC_DEI_READ_FIFO_F1_ADDR_START;
extern xdata UCHAR volatile SC_DEI_READ_FIFO_F1_ADDR_END;
extern xdata UCHAR volatile SC_DEI_READ_FIFO_F2_ADDR_HI;
extern xdata UCHAR volatile SC_DEI_READ_FIFO_F2_ADDR_START;
extern xdata UCHAR volatile SC_DEI_READ_FIFO_F2_ADDR_END;
extern xdata UCHAR volatile SC_DEI_READ_FIFO_F3_ADDR_HI;
extern xdata UCHAR volatile SC_DEI_READ_FIFO_F3_ADDR_START;
extern xdata UCHAR volatile SC_DEI_READ_FIFO_F3_ADDR_END;
extern xdata UCHAR volatile SC_FRC_READ_FIFO_ADDR_HI;
extern xdata UCHAR volatile SC_FRC_READ_FIFO_ADDR_START;
extern xdata UCHAR volatile SC_FRC_READ_FIFO_ADDR_END;
extern xdata UCHAR volatile SC_OD_READ_FIFO_ADDR_HI;
extern xdata UCHAR volatile SC_OD_READ_FIFO_ADDR_START;
extern xdata UCHAR volatile SC_OD_READ_FIFO_ADDR_END;
extern xdata UCHAR volatile SC_PREFRC_READ_FIFO_ADDR1;
extern xdata UCHAR volatile SC_PREFRC_READ_FIFO_ADDR2;
extern xdata UCHAR volatile SC_PREFRC_READ_FIFO_ADDR3;

extern xdata UCHAR volatile SC_MMU_TM_DQS_SEL_7_0;
extern xdata UCHAR volatile SC_MMU_TM_DQS_SEL_15_8;
extern xdata UCHAR volatile SC_MMU_TM_DQS_SEL_23_16;
extern xdata UCHAR volatile SC_MMU_TM_DQS_SEL_31_24;
    
extern xdata UCHAR volatile SC_DRAM_CLOCK_CTRL[];
extern xdata UCHAR volatile SC_DEI_CLK_CTRL;
extern xdata UCHAR volatile SC_3D_CNV_2D;
extern xdata UCHAR volatile SC_MMU_DATA_PHASE_SEL;

extern xdata UCHAR volatile SC_MCU_CLK_INV_APR2;

extern xdata UCHAR volatile SC_TMDS_AUTO_CSC;
extern xdata UCHAR volatile SC_SR_AUTO_CSC_CTRL;
extern xdata UCHAR volatile SC_HDMI_SOFTWARE_RESET;
extern xdata UCHAR volatile SC_HDMI_CKDT;
extern xdata UCHAR volatile SC_HDMI_CLK_INT;

extern xdata UCHAR volatile SC_HDCP_BKSV;
extern xdata UCHAR volatile SC_HDCP_BKSV_B2;
extern xdata UCHAR volatile SC_HDCP_BKSV_B3;
extern xdata UCHAR volatile SC_HDCP_BKSV_B4;
extern xdata UCHAR volatile SC_HDCP_BKSV_B5;
extern xdata UCHAR volatile SC_HDCP_62E;
extern xdata UCHAR volatile SC_HDMI_MHL_MODE_DETECT;
extern xdata UCHAR volatile SC_HDCP_STATUS;
extern xdata UCHAR volatile SC_VIDEO_HTOTAL_LO;
extern xdata UCHAR volatile SC_VIDEO_HTOTAL_HI;
extern xdata UCHAR volatile SC_VIDEO_VTOTAL_LO;
extern xdata UCHAR volatile SC_VIDEO_VTOTAL_HI;
extern xdata UCHAR volatile SC_HDCP_SLAVE_ADDR;
extern xdata UCHAR volatile SC_HDCP_SYNC_SELECT;
extern xdata UCHAR volatile SC_HDCP_INPUT_CTRL;
extern xdata UCHAR volatile SC_FPGA1_FPGA2_DELAY;
extern xdata UCHAR volatile SC_HDCP_CTRL;
extern xdata UCHAR volatile SC_HDCP_PACKING;
extern xdata UCHAR volatile SC_HDCP_CTRL3;
extern xdata UCHAR volatile SC_ICPCSC_AUTOSTATUS;
extern xdata UCHAR volatile SC_VIDEO_BLANK_BLUE;
extern xdata UCHAR volatile SC_VIDEO_BLANK_GREEN;
extern xdata UCHAR volatile SC_VIDEO_BLANK_RED;
extern xdata UCHAR volatile SC_VIDEO_DE_WIDTH_LO;
extern xdata UCHAR volatile SC_VIDEO_DE_WIDTH_HI;
extern xdata UCHAR volatile SC_VIDEO_DE_LINE_LO;
extern xdata UCHAR volatile SC_VIDEO_DE_LINE_HI;
extern xdata UCHAR volatile SC_NEW_DE_MODE_EN;
extern xdata UCHAR volatile SC_HDMI_CLK;
extern xdata UCHAR volatile SC_HDMI_INT_STATE1[];
extern xdata UCHAR volatile SC_HDMI_INT_UNMASK1[];
extern xdata UCHAR volatile SC_HDMI_INT_STATE2[];
extern xdata UCHAR volatile SC_HDMI_INT_UNMASK2[];

extern xdata UCHAR volatile SC_HDMI_AUTO_CTRL;
extern xdata UCHAR volatile SC_AEC_EXE_EN[3];

extern xdata UCHAR volatile SC_ACR_CTRL;
extern xdata UCHAR volatile SC_ACR_N_VALUE_LO;
extern xdata UCHAR volatile SC_ACR_N_VALUE_MI;
extern xdata UCHAR volatile SC_ACR_N_VALUE_HI;
extern xdata UCHAR volatile SC_ACR_N_HVAL[3];
extern xdata UCHAR volatile SC_ACR_CTS_VALUE_LO;
extern xdata UCHAR volatile SC_ACR_CTS_VALUE_MI;
extern xdata UCHAR volatile SC_ACR_CTS_VALUE_HI;
extern xdata UCHAR volatile SC_ACR_CTS_HVAL[3];
extern xdata UCHAR volatile SC_HDMI_RESET_CTRL;
extern xdata UCHAR volatile SC_VIDEO_HDCP_CTRL;
extern xdata UCHAR volatile SC_AUDIO_HDCP_CTRL;
	#define SC_AUDIO_EXT_CAP_CTRL SC_VIDEO_HDCP_CTRL
extern xdata UCHAR volatile SC_AUDIO_HW_EXT_FS;
extern xdata UCHAR volatile SC_AUDIO_DAC_DRIV_CTRL;
extern xdata UCHAR volatile SC_AUDIO_SELECT;
    #define LINE_IN_1           0x00
    #define LINE_IN_2           0x10
    #define PCM                 0x20

extern xdata UCHAR volatile SC_AUDIO_DELTA_SIGMA_GAIN_CTRL;
extern xdata UCHAR volatile SC_AUDIO_OUTPUT_CTRL;
extern xdata UCHAR volatile SC_AUDIO_DELTA_SIGMA_CTRL;
extern xdata UCHAR volatile SC_AUDIO_TEST1;
extern xdata UCHAR volatile SC_AUDIO_OUT_CTRL;
extern xdata UCHAR volatile SC_AUDIO_VOLUME_R;
extern xdata UCHAR volatile SC_AUDIO_VOLUME_L;
extern xdata UCHAR volatile SC_AUDIO_ANALOG_OUT_CTRL;
extern xdata UCHAR volatile SC_AUDIO_SMOOTH;
extern xdata UCHAR volatile SC_AUDIO_OUT_IIS_CTRL1;
extern xdata UCHAR volatile SC_AUDIO_OUT_IIS_CTRL2;
extern xdata UCHAR volatile SC_AUDIO_OUT_IIS_MAP;
extern xdata UCHAR volatile SC_AUDIO_OUT_IIS_CTRL3;
extern xdata UCHAR volatile SC_AUDIO_IN_SPDIF_STATE4;
extern xdata UCHAR volatile SC_AUDIO_CHANNEL_STATUS1;

extern xdata UCHAR volatile SC_HDMI_DET;
extern xdata UCHAR volatile SC_HDMI_PREAMBLE_CYCLE;
extern xdata UCHAR volatile SC_HDMI_DATA_ALIGN;
extern xdata UCHAR volatile SC_HDMI_MUTE;
extern xdata UCHAR volatile SC_HDMI_BYPASS;
extern xdata UCHAR volatile SC_PD_PMCLK;
extern xdata UCHAR volatile SC_HDMI_AVI_TYPE;
extern xdata UCHAR volatile SC_HDMI_AVI_VER;
extern xdata UCHAR volatile SC_HDMI_AVI_LEM;
extern xdata UCHAR volatile SC_HDMI_AVI_CKSM;
extern xdata UCHAR volatile SC_HDMI_AVI[];
extern xdata UCHAR volatile SC_AUDIO_INFO_FRAME_DB[];

extern xdata UCHAR volatile SC_FPGA_HDMI_DELAY;
extern xdata UCHAR volatile SC_VSI_PACKET[];
extern xdata UCHAR volatile SC_CTRL_PACKET[];
extern xdata UCHAR volatile SC_CP_PACKET_TYPE;
extern xdata UCHAR volatile SC_DIG_AUDIO_GAIN_L_LO;
extern xdata UCHAR volatile SC_DIG_AUDIO_GAIN_L_HI;
extern xdata UCHAR volatile SC_DIG_AUDIO_GAIN_R_LO;
extern xdata UCHAR volatile SC_DIG_AUDIO_GAIN_R_HI;
extern xdata UCHAR volatile SC_DIG_L_OFFSET;
extern xdata UCHAR volatile SC_DIG_R_OFFSET;
extern xdata UCHAR volatile SC_AUDIO_AUTO_OFFSET_CTRL;
extern xdata UCHAR volatile SC_AUDIO_AUTO_CTRL1;
extern xdata UCHAR volatile SC_AUDIO_AUTO_CTRL2;
extern xdata UCHAR volatile SC_AUDIO_AUTO_CTRL3;
extern xdata UCHAR volatile SC_AUDIO_AUTO_CTRL4;
extern xdata UCHAR volatile SC_AUDIO_AUTO_CTRL8;
extern xdata UCHAR volatile SC_AUDIO_AUTO_CTRL_8B0;
extern xdata UCHAR volatile SC_AUDIO_AUTO_CTRL_8B3;
extern xdata UCHAR volatile SC_AUDIO_AUTO_CTRL_8B5;
extern xdata UCHAR volatile SC_FPGA_AUDIO_PLL;
extern xdata UCHAR volatile SC_HDCP_BKSV2;
extern xdata UCHAR volatile SC_HDCP_SLAVE_ADDR2;
extern xdata UCHAR volatile SC_SCALER_3D_DEBUG1;
extern xdata UCHAR volatile SC_EDP_PLL_LO;
extern xdata UCHAR volatile SC_EDP_PLL_MI;
extern xdata UCHAR volatile SC_EDP_PLL_HI;
extern xdata UCHAR volatile SC_EDP_PLL_CTRL;
extern xdata UCHAR volatile SC_MCU_PLL;
extern xdata UCHAR volatile SC_MCU_CLK_DIVIDER;
extern xdata UCHAR volatile SC_ZERO_POWER_LDO18;
extern xdata UCHAR volatile SC_OSC_LDO18;
extern xdata UCHAR volatile SC_ADC_ZERO_POWER_CTRL;
extern xdata UCHAR volatile SC_DVI_ZERO_POWER_CTRL;
extern xdata UCHAR volatile SC_DVI_ZERO_POWER_DETECT;
extern xdata UCHAR volatile SC_APR_LDO_CTRL;
extern xdata UCHAR volatile SC_DVI1_ZERO_POWER_CTRL;
extern xdata UCHAR volatile SC_DVI1_ZERO_POWER_DETECT;
extern xdata UCHAR volatile SC_DVI2_ZERO_POWER_CTRL;
extern xdata UCHAR volatile SC_DVI2_ZERO_POWER_DETECT;
extern xdata UCHAR volatile SC_APR_ISOLATION;

extern xdata UCHAR volatile SC_MMU_DLL_CTRL;
extern xdata UCHAR volatile SC_MMU_DLL_INF;
extern xdata UCHAR volatile SC_MMU_B82;
extern xdata UCHAR volatile SC_MMU_B83;
extern xdata UCHAR volatile SC_MMU_B84;
extern xdata UCHAR volatile SC_MMU_B85;
extern xdata UCHAR volatile SC_MMU_DLL_PHASE_CTRL0;
#if IS_NT68850_SERIES
extern xdata UCHAR volatile SC_DP_MASK_AUX_I2C_RW_SEL;
extern xdata UCHAR volatile SC_DP_FAST_MUTE_CTRL;
extern xdata UCHAR volatile SC_DP_VS_BLANK_CNT_LO;
extern xdata UCHAR volatile SC_DP_AUX_CTRL2;
	#define DP_AUX_INTR_SEL			BIT7		// 0: strobe_fifo_not_empty, 1: command end.
#else
extern xdata UCHAR volatile SC_MMU_DLL_PHASE_CTRL1;
extern xdata UCHAR volatile SC_MMU_DLL_PHASE_CTRL2;
extern xdata UCHAR volatile SC_MMU_DLL_PHASE_CTRL3;
extern xdata UCHAR volatile SC_MMU_PLL_SPLL7;
#endif

extern xdata UCHAR volatile SC_MMU_PLL_SKEW0;
extern xdata UCHAR volatile SC_MMU_PLL_SKEW1;
extern xdata UCHAR volatile SC_MMU_PLL_SKEW2;
extern xdata UCHAR volatile SC_MMU_PLL_SKEW3;
extern xdata UCHAR volatile SC_MMU_PLL_SKEW4;
extern xdata UCHAR volatile SC_MMU_PLL_SKEW5;
extern xdata UCHAR volatile SC_MMU_PLL_SKEW6;
extern xdata UCHAR volatile SC_MMU_PLL_SKEW7;
extern xdata UCHAR volatile SC_PREFRC_CLOCK_DIV;
extern xdata UCHAR volatile SC_FRC_CLOCK_SEL;
extern xdata UCHAR volatile SC_LDO_2V5_CTRL_BD2;

extern xdata UCHAR volatile SC_DVI_PLL_M;
extern xdata UCHAR volatile SC_VPLL_CTRL;
extern xdata UCHAR volatile SC_VPLL_CTRL1;

extern xdata UCHAR volatile SC_VCLK_RATIO_LO;
extern xdata UCHAR volatile SC_VCLK_RATIO_MI;
extern xdata UCHAR volatile SC_VCLK_RATIO_HI;

extern xdata UCHAR volatile SC_MPLL_B2C;

extern xdata UCHAR volatile SC_MCLK_RATIO_LO;
extern xdata UCHAR volatile SC_MCLK_RATIO_MI;
extern xdata UCHAR volatile SC_MCLK_RATIO_HI;
extern xdata UCHAR volatile SC_MCLK_SSC_CTRL;

extern xdata UCHAR volatile SC_FRC_RATIO_LO;
extern xdata UCHAR volatile SC_FRC_RATIO_MI;
extern xdata UCHAR volatile SC_FRC_RATIO_HI;

extern xdata UCHAR volatile SC_MPLL_B3E;
extern xdata UCHAR volatile SC_MPLL_B3F;
extern xdata UCHAR volatile SC_MPLL_DIV;
extern xdata UCHAR volatile SC_MPLL_CTRL_B41;
extern xdata UCHAR volatile SC_MPLL_CTRL_B42;
extern xdata UCHAR volatile SC_MPLL_LDO_VADJ;
extern xdata UCHAR volatile SC_MPLL_B45;
extern xdata UCHAR volatile SC_MPLL_X2;
extern xdata UCHAR volatile SC_SSC_FDEV;
extern xdata UCHAR volatile SC_SSC_FMOD;
extern xdata UCHAR volatile SC_MCU_CLK_SSC;
extern xdata UCHAR volatile SC_EDP_CLK_SSC;
extern xdata UCHAR volatile SC_EDP_MAN_CLK_SSC;
extern xdata UCHAR volatile SC_EDP_MAN_CLK_SSC_RATIO;
extern xdata UCHAR volatile SC_PLL_SYZ_PU;
extern xdata UCHAR volatile SC_MMU_B4E;
extern xdata UCHAR volatile SC_ACR_CLK_OUT_SEL;
extern xdata UCHAR volatile SC_APR_LDO_V_CTRL;
extern xdata UCHAR volatile SC_CEC_CTRL;
extern xdata UCHAR volatile SC_CEC_CLK_BASE;
extern xdata UCHAR volatile SC_CEC_FREE_CNT1;
extern xdata UCHAR volatile SC_CEC_RETRY;
extern xdata UCHAR volatile SC_CEC_TXR_OFFSET;
extern xdata UCHAR volatile SC_CEC_TXF_OFFSET;
extern xdata UCHAR volatile SC_CEC_SBIT_RANGE;
extern xdata UCHAR volatile SC_CEC_RXD_RANGE;
extern xdata UCHAR volatile SC_CEC_RX_SMP;
extern xdata UCHAR volatile SC_CEC_DEGLITCH;
extern xdata UCHAR volatile SC_CEC_RXL_ERROR;
extern xdata UCHAR volatile SC_CEC_RXH_ERROR;
extern xdata UCHAR volatile SC_CEC_INT_EN;
extern xdata UCHAR volatile SC_CEC_INT_FLAG;
extern xdata UCHAR volatile SC_CEC_DEBUG;
extern xdata UCHAR volatile SC_CEC_RX_LENGTH;
extern xdata UCHAR volatile SC_CEC_TX_LENGTH;
extern xdata UCHAR volatile SC_CEC_FILTER;
extern xdata UCHAR volatile SC_CEC_TX_HEAD;
extern xdata UCHAR volatile SC_CEC_TX_DATA[16];
extern xdata UCHAR volatile SC_CEC_RX_HEAD;
extern xdata UCHAR volatile SC_CEC_RX_DATA[16];
extern xdata UCHAR volatile SC_3D_SHUTTER_GLASS_CTRL[32];
extern xdata UCHAR volatile SC_VGA_ADC_BIST;
extern xdata UCHAR volatile SC_ISOLATION_CONTROL;
extern xdata UCHAR volatile SC_CUT_POWER_CTRL;
extern xdata UCHAR volatile SC_ADC_LDO;
extern xdata UCHAR volatile SC_ZERO_PWR_CTRL_B64;
extern xdata UCHAR volatile SC_ZERO_PWR_CTRL_B65;
extern xdata UCHAR volatile SC_ZERO_PWR_CTRL_B66;
extern xdata UCHAR volatile SC_ZERO_PWR_CTRL_B67;
extern xdata UCHAR volatile SC_ZERO_PWR_CTRL_B68;
extern xdata UCHAR volatile SC_ZERO_PWR_CTRL_B69;
extern xdata UCHAR volatile SC_ADC_TRIM_CTRL;
extern xdata UCHAR volatile SC_ADC_CTRL_OPTION1;
extern xdata UCHAR volatile SC_ADC_CTRL_OPTION2;
extern xdata UCHAR volatile SC_ADC_CTRL_OPTION3;
extern xdata UCHAR volatile SC_MCU_IO_CTRL0;
extern xdata UCHAR volatile SC_MCU_IO_CTRL1;
extern xdata UCHAR volatile SC_MCU_IO_CTRL2;
extern xdata UCHAR volatile SC_MCU_IO_CTRL3;
extern xdata UCHAR volatile SC_MCU_IO_CTRL4;    // 0xC83
extern xdata UCHAR volatile SC_MCU_IO_CTRL5;
extern xdata UCHAR volatile SC_MCU_IO_CTRL6;
extern xdata UCHAR volatile SC_MCU_IO_CTRL7;
extern xdata UCHAR volatile SC_MCU_IO_CTRL8;
extern xdata UCHAR volatile SC_MCU_IO_CTRL9;    // 0xC88
/*OSD 2 *//////////////////////////////////////////////
extern xdata UCHAR volatile SC_OSD_FRAME2_FUNC_CTRL;
extern xdata UCHAR volatile SC_OSD_FRAME2_ADDR_LO;
extern xdata UCHAR volatile SC_OSD_FRAME2_ADDR_HI;
extern xdata UCHAR volatile SC_OSD_WIN_HOR_START_LO;
extern xdata UCHAR volatile SC_OSD_WIN_HOR_END_LO;
extern xdata UCHAR volatile SC_OSD_WIN_HOR_HI;
extern xdata UCHAR volatile SC_OSD_WIN_VER_START_LO;
extern xdata UCHAR volatile SC_OSD_WIN_VER_END_LO;
extern xdata UCHAR volatile SC_OSD_WIN_VER_HI;
/*GRADIENT*/
extern xdata UCHAR volatile SC_OSD_WIN_GRADIENT_CTRL;
extern xdata UCHAR volatile SC_OSD_WIN_GRADIENT_RED_COLOR;
extern xdata UCHAR volatile SC_OSD_WIN_GRADIENT_GREEN_COLOR;
extern xdata UCHAR volatile SC_OSD_WIN_GRADIENT_BLUE_COLOR;
extern xdata UCHAR volatile SC_OSD_WIN_GRADIENT_RED_STEP;
extern xdata UCHAR volatile SC_OSD_WIN_GRADIENT_GREEN_STEP;
extern xdata UCHAR volatile SC_OSD_WIN_GRADIENT_BLUE_STEP;
extern xdata UCHAR volatile SC_OSD_WIN_GRADIENT_COLOR_FRONTGROUND;
    
extern xdata UCHAR volatile SC_HDCP_TRIM_CTRL;
extern xdata UCHAR volatile SC_HDCP_TRIM_ADDR;
extern xdata UCHAR volatile SC_HDCP_TRIM_DATA_LO;
extern xdata UCHAR volatile SC_HDCP_TRIM_DATA_HI;
extern xdata UCHAR volatile SC_HDCP_TRIM_CTRL2;
extern xdata UCHAR volatile SC_HDCP_TRIM_TEST_MODE;
extern xdata UCHAR volatile SC_HDCP_TRIM_ADDR_A;
extern xdata UCHAR volatile SC_HDCP_TRIM_ADDR_B;
extern xdata UCHAR volatile SC_HDCP_TRIM_PI;


extern xdata UCHAR volatile SC_LEDDRIVER_ENABLE;
extern xdata UCHAR volatile SC_LED_PROTECT_CTRL1;
extern xdata UCHAR volatile SC_LED_PROTECT_CTRL2;
extern xdata UCHAR volatile SC_LED_SHORT_CTRL;
extern xdata UCHAR volatile SC_ADC_LDO_TRIM;
extern xdata UCHAR volatile SC_LEDDIMMING_CTRL;
extern xdata UCHAR volatile SC_LED_OPEN_STATUS;
extern xdata UCHAR volatile SC_LED_SHORT_STATUS;
extern xdata UCHAR volatile SC_LEDSTATUS;
extern xdata UCHAR volatile SC_LEDPROTECT_ENABLE;
extern xdata UCHAR volatile SC_TRIMMING_CONTROL;
extern xdata UCHAR volatile SC_VREF_VOLTAGE_MODE1;
extern xdata UCHAR volatile SC_VREF_VOLTAGE_MODE2;
extern xdata UCHAR volatile SC_VREF_VOLTAGE_MODE3;
extern xdata UCHAR volatile SC_DC2DC_E30;
extern xdata UCHAR volatile SC_DC2DC_E33;
extern xdata UCHAR volatile SC_LED_TRIM_E36;
extern xdata UCHAR volatile SC_LED_TRIM_E37;

extern xdata UCHAR volatile SC_DC2DC_E39;
extern xdata UCHAR volatile SC_DC2DC_E3A;
extern xdata UCHAR volatile SC_DC2DC_E3B;
extern xdata UCHAR volatile SC_DC2DC_E3C;
extern xdata UCHAR volatile SC_DC2DC_E3D;
extern xdata UCHAR volatile SC_DC2DC_E3E;
extern xdata UCHAR volatile SC_DC2DC_E3F;

//Local Dimming
extern xdata UCHAR volatile SC_LD_CONTROL;
extern xdata UCHAR volatile SC_LD_POSTGAIN;
extern xdata UCHAR volatile SC_LD_POSTDUTY;
extern xdata UCHAR volatile SC_LD_CTRL;
extern xdata UCHAR volatile SC_LD_LEFT_BOUND_LO;
extern xdata UCHAR volatile SC_LD_LEFT_BOUND_HI;
extern xdata UCHAR volatile SC_LD_RIGHT_BOUND_LO;
extern xdata UCHAR volatile SC_LD_RIGHT_BOUND_HI;
extern xdata UCHAR volatile SC_LD_TOP_BOUND_LO;
extern xdata UCHAR volatile SC_LD_TOP_BOUND_HI;
extern xdata UCHAR volatile SC_LD_BOTTOM_BOUND_LO;
extern xdata UCHAR volatile SC_LD_BOTTOM_BOUND_HI;
extern xdata UCHAR volatile SC_LD_INC_SPEED;
extern xdata UCHAR volatile SC_LD_DEC_SPEED;
extern xdata UCHAR volatile SC_LD_BLOCK_WIDTH_LO;
extern xdata UCHAR volatile SC_LD_BLOCK_WIDTH_HI;
extern xdata UCHAR volatile SC_LD_BLOCK_HEIGHT_LO;
extern xdata UCHAR volatile SC_LD_BLOCK_HEIGHT_HI;
extern xdata UCHAR volatile SC_LD_ZONE_PITCH;
extern xdata UCHAR volatile SC_LD_ABRUPT_CHANGE_CRTL;

extern xdata UCHAR volatile SC_LD_BE_WIDTH;
extern xdata UCHAR volatile SC_LD_BE_HEIGHT;
extern xdata UCHAR volatile SC_LD_BE_HBOUND_LO;

extern xdata UCHAR volatile SC_LD_BE_VBOUND_LO;
extern xdata UCHAR volatile SC_LD_BE_HVBOUND_HI;
extern xdata UCHAR volatile SC_LD_BE_OFFSET_LO;
extern xdata UCHAR volatile SC_LD_BE_PITCH_LO;
extern xdata UCHAR volatile SC_LD_BE_OFFSET_PITCH_HI;

extern xdata UCHAR volatile SC_LD_PWMA_CTRL1;
extern xdata UCHAR volatile SC_LD_PWMA_CTRL2;
extern xdata UCHAR volatile SC_LD_PWMA_CTRL3;

extern xdata UCHAR volatile SC_LD_DUTY_CONTROL1;
extern xdata UCHAR volatile SC_LD_PORT_INDEX;
extern xdata UCHAR volatile SC_LD_GRAY_TO_DUTY_TABLE;
extern xdata UCHAR volatile SC_LD_LIGHT_PROFILE_TABLE;
extern xdata UCHAR volatile SC_LD_LV_TO_GAIN_TABLE;
extern xdata UCHAR volatile SC_LD_INDEX_PORT_ADDRESS_LO;
extern xdata UCHAR volatile SC_LD_INDEX_PORT_ADDRESS_HI;

extern xdata UCHAR volatile SC_LD_MODE_CTRL;
extern xdata UCHAR volatile SC_LD_ADPS_CTRL;
extern xdata UCHAR volatile SC_LD_DUTY_SPEED_CTRL;
extern xdata UCHAR volatile SC_LD_MIN_DUTY;
extern xdata UCHAR volatile SC_LD_BRIGHTNESS;
extern xdata UCHAR volatile SC_LD_DYNAMIC_FRAME_THR;
extern xdata UCHAR volatile SC_LD_AOS_THRESHOLD_HI;
extern xdata UCHAR volatile SC_LD_AOS_THRESHOLD_LO;

extern xdata UCHAR volatile SC_LD_DUTY_CONTROL3;
extern xdata UCHAR volatile SC_LD_HBLK_WIDTH_LO;
extern xdata UCHAR volatile SC_LD_HBLK_WIDTH_HI;
extern xdata UCHAR volatile SC_LD_VBLK_HEIGHT_LO;
extern xdata UCHAR volatile SC_LD_VBLK_HEIGHT_HI;
extern xdata UCHAR volatile SC_LD_H_ZONE_NUM;
extern xdata UCHAR volatile SC_LD_V_ZONE_NUM;
extern xdata UCHAR volatile SC_LD_DIM_DEFINE_CTRL;

extern xdata UCHAR volatile SC_SR_CTRL;
//FLT1 median Filter
extern xdata UCHAR volatile FLT1_TH;
extern xdata UCHAR volatile FLT1_CUT_SLOP;
extern xdata UCHAR volatile FLT1_SLOP_TH;
extern xdata UCHAR volatile FLT1_VAR_TH_LO;
extern xdata UCHAR volatile FLT1_SLOP_VAR_TH_HI;

extern xdata UCHAR volatile FLT3_MAX_VAR_LO;
extern xdata UCHAR volatile FLT3_MAX_VAR_HI;
extern xdata UCHAR volatile FLT3_MEAN_VAR_LO;
extern xdata UCHAR volatile FLT3_MEAN_VAR_HI;

//FLT3 USM
extern xdata UCHAR volatile FLT3_CORING_TH;
extern xdata UCHAR volatile FLT3_GAIN;
extern xdata UCHAR volatile FLT3_COEFFICENT[12];

//FLT3 Source Select
extern xdata UCHAR volatile FLT3_ADD_SUB_SOURCE;
extern xdata UCHAR volatile FLT3_BRIGHT_DARK_SOURCE;

extern xdata UCHAR volatile FLT3_BRIGHT_DARK_SLOP;
extern xdata UCHAR volatile FLT3_CORING_SLOP;
//FLT3 USM Demo
extern xdata UCHAR volatile USM_DEMO_MODE;
extern xdata UCHAR volatile USM_DEMO_WIDTH_LO;
extern xdata UCHAR volatile USM_DEMO_WIDTH_HI;

extern xdata UCHAR volatile FLT1_CONTROL1;
extern xdata UCHAR volatile FLT1_CONTROL2;

//FLT3 Coring curve
extern xdata UCHAR volatile FLT3_CORING_UP_LOW_TH;
extern xdata UCHAR volatile FLT3_COR_VAR_TH_LO;
extern xdata UCHAR volatile FLT3_COR_VAR_TH_HI_SLOP;
//FLT3 Gain curve
extern xdata UCHAR volatile FLT3_GAIN_UP_LOW_TH;
extern xdata UCHAR volatile FLT3_GAIN_VAR_TH_LO;
extern xdata UCHAR volatile FLT3_GAIN_VAR_TH_HI_SLOP;

//FLT3 Low Pass Control
extern xdata UCHAR volatile FLT3_LP_VAR_TH_LO;
extern xdata UCHAR volatile FLT3_LP_VAR_TH_HI_SLOP;

extern xdata UCHAR volatile FLT1_CONTROL_THR;

extern xdata UCHAR volatile SC_SR_HTOTAL_LO;
extern xdata UCHAR volatile SC_SR_HTOTAL_HI;
extern xdata UCHAR volatile SC_SR_HACT_LO;
extern xdata UCHAR volatile SC_SR_HACT_HI;
extern xdata UCHAR volatile SC_SR_VACT_LO;
extern xdata UCHAR volatile SC_SR_VACT_HI;
extern xdata UCHAR volatile SC_SR_HBACKPORCH;
extern xdata UCHAR volatile SC_SR_PIPEDELAY;

extern xdata UCHAR volatile SC_SR_CONTROL;
extern xdata UCHAR volatile SC_DP_FPGA_CTRL1;
extern xdata UCHAR volatile SC_DP_FPGA_CTRL2;

extern xdata UCHAR volatile SC_DP_1000;
extern xdata UCHAR volatile SC_DP_1001;
extern xdata UCHAR volatile SC_DP_VIDEO_FIFO_MODE4_ADAPTIVE_CTRL;
extern xdata UCHAR volatile SC_DP_MANUAL_MAUD_HI;
extern xdata UCHAR volatile SC_DP_MANUAL_MAUD_MI;
extern xdata UCHAR volatile SC_DP_MANUAL_MAUD_LO;
extern xdata UCHAR volatile SC_DP_MANUAL_NAUD_HI;
extern xdata UCHAR volatile SC_DP_MANUAL_NAUD_MI;
extern xdata UCHAR volatile SC_DP_MANUAL_NAUD_LO;
extern xdata UCHAR volatile SC_DP_AUX_DETECT;
extern xdata UCHAR volatile SC_DP_AUX_PULSEWIDTH_LO_THD;
extern xdata UCHAR volatile SC_DP_AUX_PULSEWIDTH_HI_THD;
extern xdata UCHAR volatile SC_DP_AUX_PRECHARGE_NUM;
extern xdata UCHAR volatile SC_DP_RESET_FUNCTION;
	#define	DP_AUX_RST		BIT0
extern xdata UCHAR volatile AUX_I2C_MANUAL;
	#define AUX_I2C_MODE	BIT0
	#define AUX_I2C_ACK		BIT1
	#define AUX_I2C_FINSH	BIT2
extern xdata UCHAR volatile AUX_I2C_DATA;	

extern xdata UCHAR volatile SC_DP_SCL_HI_HALF_WIDTH;
extern xdata UCHAR volatile SC_DP_SCL_HI_WIDTH;
extern xdata UCHAR volatile SC_DP_SDA_SETUP;
extern xdata UCHAR volatile SC_DP_SDA_HOLD;
extern xdata UCHAR volatile SC_DP_AUX_I2C_CTRL;
extern xdata UCHAR volatile SC_DP_TX_PRE_CHG_NUM;
extern xdata UCHAR volatile SC_DP_RX_PRE_CHG_NUM;
#if IS_NT68790_SERIES || IS_NT68810_SERIES || IS_NT68870_SERIES
extern xdata UCHAR volatile SC_DP_AUX_I2C_CTRL2;
#endif
extern xdata UCHAR volatile SC_DP_102F;
extern xdata UCHAR volatile SC_DP_DEBUG;
extern xdata UCHAR volatile SC_DP_HDCP_CTRL;
extern xdata UCHAR volatile SC_DP_ERR_DET_CTRL;
extern xdata UCHAR volatile SC_DP_CERR_RANGE;
extern xdata UCHAR volatile SC_DP_ERR_DET_DISABLE;
extern xdata UCHAR volatile SC_DP_1039;
extern xdata UCHAR volatile SC_DP_HPD_IRQ_WIDTH;
extern xdata UCHAR volatile SC_DP_MN_CTRL;
extern xdata UCHAR volatile SC_DP_CSC_AUTO_CONF;
extern xdata UCHAR volatile SC_DP_1043;
extern xdata UCHAR volatile SC_DP_VIDEO_FIFO_INT;
extern xdata UCHAR volatile SC_DP_TEST_FIFO_MAX_LENGTH;
extern xdata UCHAR volatile SC_DP_VIDEO_CONTROL;
extern xdata UCHAR volatile SC_DP_DE_START_POS;
extern xdata UCHAR volatile SC_DP_DE_IN_COUNT_POS_LO;
extern xdata UCHAR volatile SC_DP_DE_IN_COUNT_POS_HI;

extern xdata UCHAR volatile SC_DP_HV_MISC_CTRL; // _at_ 0x904D; // 20160202Yung add

extern xdata UCHAR volatile SC_DP_AUDIO_FIFO_CTRL;
extern xdata UCHAR volatile SC_DP_AUDIO_ERROR_FLAG;
extern xdata UCHAR volatile SC_DP_I2S_CTRL;
extern xdata UCHAR volatile SC_DP_CLK_CYCLE_VALUE;
extern xdata UCHAR volatile SC_DP_SPDIF_CTRL;
extern xdata UCHAR volatile SC_DP_DSD_CTRL;
extern xdata UCHAR volatile SC_DP_AUDIO_DAC_CTRL;
extern xdata UCHAR volatile SC_DP_INT_GROUP_0;
extern xdata UCHAR volatile SC_DP_INT_GROUP_1;
extern xdata UCHAR volatile SC_DP_INT_GROUP_2;
extern xdata UCHAR volatile SC_DP_INT_GROUP_3;
extern xdata UCHAR volatile SC_DP_INT_GROUP_4;
extern xdata UCHAR volatile SC_DP_MISC_CTRL;
extern xdata UCHAR volatile SC_DP_PLL_CTRL;
extern xdata UCHAR volatile SC_DP_PLL_M_VID_HI;
extern xdata UCHAR volatile SC_DP_PLL_M_VID_MI;
extern xdata UCHAR volatile SC_DP_PLL_M_VID_LO;
extern xdata UCHAR volatile SC_DP_PLL_N_VID_HI;
extern xdata UCHAR volatile SC_DP_PLL_N_VID_MI;
extern xdata UCHAR volatile SC_DP_PLL_N_VID_LO;
extern xdata UCHAR volatile SC_DP_1089;
extern xdata UCHAR volatile SC_DP_108A;
extern xdata UCHAR volatile SC_DP_108B;
extern xdata UCHAR volatile SC_DP_108C;
extern xdata UCHAR volatile SC_DP_MSA_MISC0;
extern xdata UCHAR volatile SC_DP_MSA_MISC1;
extern xdata UCHAR volatile SC_DP_MSA_VBID;
extern xdata UCHAR volatile SC_DP_HTOTAL_LO;
extern xdata UCHAR volatile SC_DP_HTOTAL_HI;
extern xdata UCHAR volatile SC_DP_VTOTAL_LO;
extern xdata UCHAR volatile SC_DP_VTOTAL_HI;
extern xdata UCHAR volatile SC_DP_109D;
extern xdata UCHAR volatile SC_DP_109E;
extern xdata UCHAR volatile SC_DP_AUX_CTRL;
extern xdata UCHAR volatile SC_DP_M_LSB_CROSS_TH;

extern xdata UCHAR volatile SC_DP_10C0;
extern xdata UCHAR volatile SC_DP_10C1;
extern xdata UCHAR volatile SC_DP_10C2;
extern xdata UCHAR volatile SC_DP_10C8;
extern xdata UCHAR volatile SC_DP_TEST_MODE_EN;
extern xdata UCHAR volatile SC_DP_CRPLL;

extern xdata UCHAR volatile SC_DP_PORT_SEL;
extern xdata UCHAR volatile SC_DP_ZP_DP;

extern xdata UCHAR volatile SC_DP_10F1;
extern xdata UCHAR volatile SC_DP_10F2;
extern xdata UCHAR volatile SC_DP_10F3;
extern xdata UCHAR volatile SC_DP_10F4;
extern xdata UCHAR volatile SC_DP_10F5;
extern xdata UCHAR volatile AUX_STROBE_CTL;
	#define DP_AUX_STROBE_EN		BIT0			// AUX strobe enable
	#define DP_AUX_STROBE_RST		BIT1			// AUX strobe resst
	#define DP_AUX_STROBE_INT_EN	BIT2			// AUX strobe interrupt enable
	#define DP_AUX_STORBE_INT_FLG	BIT3			// AUX strobe interrupt
	#define DP_AUX_STROBE_MASK_RX	BIT4			// AUX strobe mask read (from RX --> TX)
	#define DP_AUX_STROBE_MASK_TX	BIT5			// AUX strobe mask write (from TX --> RX)

extern xdata UCHAR volatile SC_DP_DPCD_00000;
extern xdata UCHAR volatile SC_DP_DPCD_00001;
extern xdata UCHAR volatile SC_DP_DPCD_00002;
extern xdata UCHAR volatile SC_DP_DPCD_00003;
extern xdata UCHAR volatile SC_DP_DPCD_00004;
extern xdata UCHAR volatile SC_DP_DPCD_00006;
extern xdata UCHAR volatile SC_DP_DPCD_00007;
extern xdata UCHAR volatile SC_DP_DPCD_00101;
extern xdata UCHAR volatile SC_DP_DPCD_00107;
extern xdata UCHAR volatile SC_DP_DPCD_00200;
extern xdata UCHAR volatile SC_DP_DPCD_00201;
extern xdata UCHAR volatile SC_DP_DPCD_00246;
extern xdata UCHAR volatile SC_DP_DPCD_00600;
extern xdata UCHAR volatile SC_DP_DPCD_0000D;
extern xdata UCHAR volatile SC_DP_HDCP_BKSV;
extern xdata UCHAR volatile AUX_STROBE_FUN;
extern xdata UCHAR volatile AUX_STROBE_CNT;
extern xdata UCHAR volatile AUX_STROBE_PORT;
extern xdata UCHAR volatile DP_SC_REG_1224;
	#define MASK_NATIVE_AUX			BIT7		// 0: enable NATIVE_AUX data to strobe, 1: Mask NATIVE_AUX data to strobe
extern xdata UCHAR volatile SC_DP_CERR_RST_APHY_RANGE;
extern xdata UCHAR volatile SC_DP_CERR_CLR_PHY_RANGE;
extern xdata UCHAR volatile SC_DP_CERR_NO_LINK_RANGE;
extern xdata UCHAR volatile SC_DP_CERR_NO_LINK_BS_RANGE;
extern xdata UCHAR volatile SC_DP_CERR_DET_THRESHOLD;

extern xdata UCHAR volatile SC_EDP_LINK_1300[];
#define _DPTX_LINK_BW_SET 0x02
#define _DPTX_LANE_COUNT_SET 0x03
#define _DPTX_REF_CLK 0x07
#define _DPTX_6218 0x18
#define _DPTX_HPD_CTL 0x21
    #define DPTX_HPD_EN               BIT0
    #define DPTX_HPD_MANUAL           BIT1
    #define DPTX_HPD_MANUAL_STATE     BIT2
    #define DPTX_HDP_PULG_STATE       BIT3
    #define DPTX_HPD_PLUG_INT_MASK    BIT4
    #define DPTX_HPD_IRQ_INT_MASK     BIT5
    #define DPTX_HPD_PLUG_INT_FLG     BIT6
    #define DPTX_HPD_IRQ_INT_FLG      BIT7
#define _DPTX_HPD_ACT_TH 0x22
#define _DPTX_HPD_IRQ_LTH 0x23
#define _DPTX_HPD_IRQ_HTH 0x24
#define _DPTX_MISC_CTL 0x28

#define _DPTX_AUX_DATA 0x30
#define _DPTX_AUX_CTRL 0x31
	#define DPTX_AUX_MANUAL_EN         BIT0			// TX AUX enable
	#define DPTX_AUX_MANUAL_START      BIT1			// Command send
	#define DPTX_AUX_ADDR_ONLY_CMD     BIT2			// Following AUX command is address only
	#define DPTX_AUX_DIS_NACK_DEFER    BIT3			// Disable NACK/Defer retry condition
	#define DPTX_AUX_BUF_AUTO_RST      BIT4			// Buffer auto reset while all command finished
	#define DPTX_AUX_BUF_RST           BIT5			// Manually reset transmit buffer
	#define DPTX_AUX_W_PTR_RST         BIT6			// Reset buffer write pointer
	#define DPTX_AUX_R_PTR_RST         BIT7			// Reset buffer read pointer
#define _DPTX_AUX_RETRY_NUM 0x32
#define _DPTX_AUX_INT_EN 0x33
	#define DPTX_AUX_INT_ACK_EN        BIT0		// AUX TX interrupt enable (ACK)
	#define DPTX_AUX_INT_ABNOR_EN      BIT1		// AUX TX interrupt enbale (ABNORMAL = "NACK || DEFER")
	#define DPTX_AUX_INT_RETRY_OVF_EN  BIT2		// AUX TX interrupt enable (Retry overflow )
	#define DPTX_AUX_INT_STROBE_EN     BIT3		// AUX TX interrupt enable (strobe)
#define _DPTX_AUX_INT_FLG 0x34
	#define DPTX_AUX_INT_ACK_FLG       BIT0
	#define DPTX_AUX_INT_BNOR_FLG      BIT1
	#define DPTX_AUX_INT_RETRY_OVF_FLG BIT2
	#define DPTX_AUX_INT_STROBE_FLG    BIT3
#define _DPTX_AUX_STROBE_CTL 0x35
	#define DPTX_AUX_STROBE_EN         BIT0
	#define DPTX_AUX_STROBE_RST        BIT1
	#define DPTX_AUX_STROBE_WRITE      BIT4		// mask TX -> RX 
	#define DPTX_AUX_STROBE_READ       BIT5		// mask RX -> TX
#define _DPTX_AUX_STROBE_STATUS 0x36
#define _DPTX_AUX_STROBE_PORT 0x37
// DP TX Video M
#define _DPTX_MVID_H 0x50		// [23:16]
#define _DPTX_MVID_M 0x51		// [15:8]
#define _DPTX_MVID_L 0x52		// [7:0]
// DP TX Video N
#define _DPTX_NVID_H 0x53		// [23:16]
#define _DPTX_NVID_M 0x54		// [15:8]
#define _DPTX_NVID_L 0x55		// [7:0]
// DP TX Htotal
#define _DPTX_HTOTAL_HI 0x56
#define _DPTX_HTOTAL_LO 0x57
#define _DPTX_HSTART_HI 0x58
#define _DPTX_HSTART_LO 0x59
#define _DPTX_HWIDTH_HI 0x5A
#define _DPTX_HWIDTH_LO 0x5B
#define _DPTX_HSYNCWIDTH_HI 0x5C
#define _DPTX_HSYNCWIDTH_LO 0x5D
#define _DPTX_VTOTAL_HI 0x5E
#define _DPTX_VTOTAL_LO 0x5F
#define _DPTX_VSTART_HI 0x60
#define _DPTX_VSTART_LO 0x61
#define _DPTX_VHEIGHT_HI 0x62
#define _DPTX_VHEIGHT_LO 0x63
#define _DPTX_VSYNCWIDTH_HI 0x64
#define _DPTX_VSYNCWIDTH_LO 0x65
#define _DPTX_MISC0 0x66
#define _DPTX_MISC1 0x67
#define _DPTX_VBID 0x68		// Read only
#define _DPTX_MISC1_CTRL 0x6F
#define _DPTX_IDLE_PATTERN_CTRL 0x70
#define _DPTX_CAL_TH 0x71
#define _DPTX_MODE_CTRL_73 0x73
#define _DPTX_MODE_CTRL_75 0x75
#define _DPTX_MODE_CTRL_76 0x76
#define _DPTX_MODE_CTRL_78 0x78
#define _DPTX_MODE_CTRL_7B 0x7B
#define _DPTX_MODE_CTRL_7C 0x7C
#define _DPTX_MODE_CTRL_7D 0x7D

#define _EDP_AUX_PHY_CTRL_B0 0xB0
#define _EDP_AUX_PHY_CTRL_B1 0xB1
#define _EDP_AUX_PHY_CTRL_B2 0xB2
#define _EDP_AUX_PHY_CTRL_B3 0xB3

extern xdata UCHAR volatile SC_DPpp_CFG_TMDS_1700[];
extern xdata UCHAR volatile SC_DPpp_CFG_TMDS_1A00[];
#define _DPRM_CG_CFG                 0x0000
#define _DPRM_CG_CFG1                0x0001
#define _DPRM_CG_CFG2                0x0002
#define _DPRM_CG_CFG3                0x0003
#define _DPRM_RG_CFG                 0x0004
#define _DPRM_AB_CFG                 0x0008
#define _DPRM_AB_CFG1                0x0009
#define _DPRM_AB_CFG2                0x000A
#define _DPRM_CHIP_STATUS            0x000C
#define _DPRM_HI_INT                 0x000D
#define _DPRM_CC_STS                 0x000F
#define _DPRM_BIASGEN_CFG0           0x0010
#define _DPRM_BIASGEN_CFG1           0x0011
#define _DPRM_BIASGEN_CFG2           0x0012
#define _DPRM_BIASGEN_CFG3           0x0013
#define _DPRM_BIASGEN_CFG4           0x0014
#define _DPRM_BIASGEN_CFG5           0x0015
#define _DPRM_AUX_CFG                0x0016
#define _DPRM_AUX_CFG1               0x0017
#define _DPRM_HPD_CFG                0x001F
#define _DPRM_AT_CFG                 0x0020
#define _DPRM_AT_FLAG                0x0021
#define _DPRM_AT_INTEN               0x0022
#define _DPRM_AT_DATA                0x0023
#define _DPRM_AT_DMA_TXADDR_BEG      0x0024
#define _DPRM_AT_DMA_RXADDR_BEG      0x0025
#define _DPRM_AT_DMA_TXBYTE_NUM      0x0026
#define _DPRM_AT_DMA_RXBYTE_CNT      0x0027
#define _DP_MEM_DATA_PORT            0x0030
#define _DP_MEM_CTRL                 0x0031
#define _DP_MEM_ADDR_LO              0x0032
#define _DP_MEM_ADDR_HI              0x0033
#define _DPPHY_BIAS_R12K             0x003A
#define _DPRM_AU_CFG                 0x0070
#define _DPRM_AU_A_L                 0x0071
#define _DPRM_AU_A_M                 0x0072
#define _DPRM_AU_A_H                 0x0073
#define _DPRM_AU_B_L                 0x0074
#define _DPRM_AU_B_M                 0x0075
#define _DPRM_AU_B_H                 0x0076
#define _DPRM_AU_Q_L                 0x0077
#define _DPRM_AU_Q_M                 0x0078
#define _DPRM_AU_Q_H                 0x0079
#define _DPRM_AU_R_L                 0x007A
#define _DPRM_AU_R_M                 0x007B
#define _DPRM_AU_R_H                 0x007C
#define _DPRM_AU_D_L                 0x007D
#define _DPRM_AU_D_M                 0x007E
#define _DPRM_AU_D_H                 0x007F
#define _DPRM_LINKIF_FLAG_IN_CFG     0x0090
#define _DPRM_LINKIF_INTEN_IN_CFG    0x0091
#define _DPRM_LINKIF_IN              0x0092
#define _DPRM_LINKIF_IN1             0x0093
#define _DPRM_LINKIF_OUT             0x0094
#define _DPRM_LINKIF_OUT1            0x0095
#define _DPRM_LINKIF_LANE0_IN        0x0096
#define _DPRM_LINKIF_LANE0_OUT       0x0097
#define _DPRM_LINKIF_LANE1_IN        0x0098
#define _DPRM_LINKIF_LANE1_OUT       0x0099
#define _DPRM_LINKIF_LANE2_IN        0x009A
#define _DPRM_LINKIF_LANE2_OUT       0x009B
#define _DPRM_LINKIF_LANE3_IN        0x009C
#define _DPRM_LINKIF_LANE3_OUT       0x009D
#define _DPRM_LINKIF_HPD_CFG         0x009F
#define _DPRM_LINKIF_IN_SM           0x00A2
#define _DPRM_LINKIF_IN1_SM          0x00A3
#define _DPRM_LINKIF_OUT_SM          0x00A4
#define _DPRM_LINKIF_OUT1_SM         0x00A5
#define _DPRM_LINKIF_LANE0_IN_SM     0x00A6
#define _DPRM_LINKIF_LANE0_OUT_SM    0x00A7
#define _DPRM_LINKIF_LANE1_IN_SM     0x00A8
#define _DPRM_LINKIF_LANE1_OUT_SM    0x00A9
#define _DPRM_LINKIF_LANE2_IN_SM     0x00AA
#define _DPRM_LINKIF_LANE2_OUT_SM    0x00AB
#define _DPRM_LINKIF_LANE3_IN_SM     0x00AC
#define _DPRM_LINKIF_LANE3_OUT_SM    0x00AD
#define _DPRM_I2CM_CFG               0x00B0
#define _DPRM_I2CM_FREQDIV_CNTS_DIV4 0x00B1
#define _DPRM_I2CM_FLAG              0x00B2
#define _DPRM_I2CM_INTEN             0x00B3
#define _DPRM_I2CM_CMD_ENTRY         0x00B4
#define _DPRM_I2CM_DMA_TXADDR        0x00B5
#define _DPRM_I2CM_DMA_RXADDR        0x00B6
#define _DPRM_LANE_ALIGN_CFG         0x00D0
#define _DPRM_LANE_INT               0x00D1
#define _DPRM_LANE_HI_CFG            0x00D2
#define _DPRM_LANE_STS               0x00D3
#define _DPRM_LANE_FIFO_RST          0x00D4
#define _DPRM_LANE_POLARITY          0x00D5
#define _DPRM_TIMER_CFG              0x00E0
#define _DPRM_TIMER_FLAG             0x00E1
#define _DPRM_TIMER0_LIMIT_L         0x00E2
#define _DPRM_TIMER0_LIMIT_H         0x00E3
#define _DPRM_TIMER1_LIMIT_L         0x00E4
#define _DPRM_TIMER1_LIMIT_2         0x00E5
#define _DPRM_TIMER2_LIMIT_L         0x00E6
#define _DPRM_TIMER2_LIMIT_H         0x00E7
#define _DPRM_TIMER3_LIMIT_L         0x00E8
#define _DPRM_TIMER3_LIMIT_H         0x00E9
#define _DPRM_WDT_LIMIT_L            0x00EA
#define _DPRM_WDT_LIMIT_H            0x00EB
#define _DPRM_WDT_CFG                0x00EC
#define _DPRM_TIMER_CLKDIV           0x00EF
#define _DPRM_GPIO_L                 0x00F0
#define _DPRM_GPIO_H                 0x00F1
#define _DPRM_DBG_DO_SEL_CFG         0x00F2
#define _DPRM_TEST_CFG               0x00F3
#define _DPRM_MC_STS                 0x00F4
#define _DPRM_MC_ADDR_SYNC_L         0x00F5
#define _DPRM_MC_ADDR_SYNC_H         0x00F6
#define _DPRM_ADDRH_ZP               0x00FE
#define _DPRM_LANE0_STATE            0x00F8
#define _DPRM_LANE1_STATE            0x00F9
#define _DPRM_LANE2_STATE            0x00FA
#define _DPRM_LANE3_STATE            0x00FB
#define _HDMI_MHL_INFO               0x00FC

#define _DP_ANA_EQ_CFG0              0x0100
#define _DP_ANA_EQ_CFG1              0x0101
#define _DP_ANA_EQ_CFG2              0x0102
#define _DP_ANA_EQ_CFG3              0x0103
#define _DP_ANA_EQ_CFG4              0x0104
#define _DP_ANA_EQ_CFG5              0x0105
#define _DP_ANA_CDR_CFG0             0x0106
#define _DP_ANA_CDR_CFG1             0x0107
#define _DP_ANA_CDR_CFG2             0x0108
#define _DP_ANA_CDR_CFG3             0x0109
#define _DP_ANA_CDR_CFG4             0x010A
#define _DP_ANA_CDR_CFG5             0x010B
#define _DP_ANA_S2P_CFG              0x010C
#define _DP_ANA_CDR_CFG6             0x010D
#define _DP_ANA_CDR_CFG7             0x010E
#define _DP_ANA_CDR_CFG8             0x010F
#define _DP_RXANAIF_RSTB_CFG         0x0110
#define _DP_RXANAIF_CFG0             0x0111
#define _DP_RXANAIF_CFG1             0x0112
#define _DP_RXANAIF_RCAL_CFG         0x0113
#define _DP_RXANAIF_RCAL_STEP_PERIOD 0x0114
#define _DPRXANAIF_VBS_CFG           0x0120
#define _DPRXANAIF_VBS_STEP_CFG      0x0121
#define _DPRXANAIF_VBS_FNUM_L        0x0122
#define _DPRXANAIF_VBS_FNUM_H        0x0123
#define _DPRXANAIF_VBS_PERIOD_L      0x0124
#define _DPRXANAIF_VBS_PERIOD_H      0x0125
#define _DPRXANAIF_VBS_TH            0x0126
#define _DPRXANAIF_VBS_BADLY         0x0127
#define _DPRXANAIF_VBS_BASEL         0x0128
#define _DPRXANAIF_VBS_FCNT_L        0x0129
#define _DPRXANAIF_VBS_FCNT_H        0x012A
#define _DPRXANAIF_VBS_BASEL_INIT    0x012B
#define _DPRXANAIF_VBS_BASEL_LLMT    0x012C
#define _DPRXANAIF_VBS_BASEL_HLMT    0x012D
#define _DPRXANAIF_VBS_CFG1          0x012E
#define _DPRXANAIF_VBS_STS           0x012F
#define _DPRXANAIF_VBS_FNUM1_L       0x0130
#define _DPRXANAIF_VBS_FNUM1_H       0x0131
#define _DPRXANAIF_VBS_TH1           0x0132
#define _DPRXANAIF_VBS_FCNT_CFG      0x0133
#define _DPRXANAIF_VBS_FCNT1_L       0x0134
#define _DPRXANAIF_VBS_FCNT1_H       0x0135
#define _DPRXANAIF_AEQ_CFG           0x0140
#define _DPRXANAIF_AEQ_CFG1          0x0141
#define _DPRXANAIF_AEQ_CFG2          0x0142
#define _DPRXANAIF_AEQ_ACC_TH        0x0143
#define _DPRXANAIF_AEQ_PERIOD        0x0144
#define _DPRXANAIF_AEQ_CDRDLY        0x0145
#define _DPRXANAIF_AEQ_CLRDLY        0x0146
#define _DPRXANAIF_AEQ_ACC_DIV2_L    0x0147
#define _DPRXANAIF_AEQ_ACC_DIV2_H    0x0148
#define _DPRXANAIF_AEQ_CFG3          0x0149
#define _DPRXANAIF_AEQ_CFG4          0x014A
#define _DPRXANAIF_AEQ_CFG5          0x014B
#define _DPRP_SD_CFG                 0x0150
#define _DPRP_SD_SYNCPH_STS          0x0151
#define _DPRP_DD_CFG                 0x0152
#define _DPRP_DEC_CFG                0x0153
#define _DPRP_SF_CFG                 0x0154
#define _DPRP_EC_CFG                 0x0155
#define _DPRP_EC_PERIOD_NUM          0x0156
#define _DPRP_EC_TH                  0x0157
#define _DPRP_DES_CFG                0x0158
#define _DPRP_SEC_CFG                0x0159
#define _DPRP_SEC_GOLDEN_SYM_L       0x015A
#define _DPRP_SEC_GOLDEN_SYM_H       0x015B
#define _DPRP_SEC_ERRCNT_L           0x015C
#define _DPRP_SEC_ERRCNT_H           0x015D
#define _DPRP_SEC_CFG1               0x015E
#define _DPRP_CORE_FLAG              0x015F
#define _DPRP_DBG_CFG0               0x0160
#define _DPRP_DBG_DAT0               0x0161
#define _DPRP_DBG_DAT1               0x0162
#define _DPRP_DBG_DAT2               0x0163
#define _DPRP_DBG_DAT3               0x0164
#define _DPRP_DBG_DAT4               0x0165
#define _DPRP_SF2_CFG                0x0168
#define _DPRP_SF2_WND                0x0169
#define _DPRP_FLAG                   0x0170
#define _DPRP_INTEN                  0x0171
#define _DPRP_STATUS                 0x0172
#define _DPRP_STATE                  0x0173
#define _DPRP_OUT                    0x0174
#define _DPRP_TIMER_CFG              0x0175
#define _DPRP_TIMER_LIMIT            0x0176

#define _TMDS_DPHY_MHL2p0_CTRL       0x0180
#define _TMDS_DPHY_MS_CLK_SEL        0x0181
#define _TMDS_DPHY_CLOCK_ENABLE      0x0190
#define _TMDS_DPHY_CLOCK_INVERT      0x0191
#define _TMDS_DPHY_MODE_SELECT       0x0192

#define _TMDS_DPHY_CH0_ERROR         0x0197
#define _TMDS_DPHY_CH1_ERROR         0x0198
#define _TMDS_DPHY_CH2_ERROR         0x0199

#define _TMDS_DPHY_MHL2p0_MISC       0x019A
#define _TMDS_DPHY_ERROR_DET         0x01A0
#define _TMDS_DPHY_ERRORCNT_CH0_HI   0x01A1
#define _TMDS_DPHY_ERRORCNT_CH0_LO   0x01A2
#define _TMDS_DPHY_ERRORCNT_CH1_HI   0x01A3
#define _TMDS_DPHY_ERRORCNT_CH1_LO   0x01A4
#define _TMDS_DPHY_ERRORCNT_CH2_HI   0x01A5
#define _TMDS_DPHY_ERRORCNT_CH2_LO   0x01A6
#define _TMDS_DPHY_HACTIVE_LO        0x01AB
#define _TMDS_DPHY_HACTIVE_HI        0x01AC
#define _TMDS_DPHY_VACTIVE_LO        0x01AD
#define _TMDS_DPHY_VACTIVE_HI        0x01AE
#define _TMDS_DPHY_82C5              0x01C5

#define _TMDS_HPD_IO_CTRL            0x01C9

#define _DPHY_CBUS_LDO_CTRL          0x01CA

#define _DPRP_REG_1FD                0x01FD

#define _DPPHY_FCTRL                 0x0200
#define _DPPHY_ICTRL                 0x0201
#define _DPPHY_EQR_IMP_ENABLE        0x0202
#define _DPPHY_IMPEDANCE_L0_L2_L3    0x0203
#define _DPPHY_IMPEDANCE_L1          0x0204
#define _DPPHY_EQR_POS_IOFFSET_L0    0x0205
#define _DPPHY_EQR_POS_IOFFSET_L1    0x0206
#define _DPPHY_EQR_POS_IOFFSET_L2    0x0207
#define _DPPHY_EQR_POS_IOFFSET_L3    0x0208
#define _DPPHY_EQR_NEG_IOFFSET_L0    0x0209
#define _DPPHY_EQR_NEG_IOFFSET_L1    0x020A
#define _DPPHY_EQR_NEG_IOFFSET_L2    0x020B
#define _DPPHY_EQR_NEG_IOFFSET_L3    0x020C
#define _DPPHY_STATUS                0x020D
#define _DPPHY_EQR_CAP_CTRL0_LO      0x0210
#define _DPPHY_EQR_CAP_CTRL0_HI      0x0211
#define _DPPHY_EQR_CAP_CTRL1_LO      0x0212
#define _DPPHY_EQR_CAP_CTRL1_HI      0x0213
#define _DPPHY_EQR_CAP_CTRL2_LO      0x0214
#define _DPPHY_EQR_CAP_CTRL2_HI      0x0215
#define _DPPHY_EQR_CAP_CTRL3_LO      0x0216
#define _DPPHY_EQR_CAP_CTRL3_HI      0x0217
#define _DPPHY_EQR_RES_CTRL0         0x0218
#define _DPPHY_EQR_RES_CTRL1         0x0219
#define _DPPHY_EQR_RES_CTRL2         0x021A
#define _DPPHY_EQR_RES_CTRL3         0x021B
#define _DPPHY_BIAS_POWER            0x021C
#define _DPPHY_BIAS_LDO              0x021D
#define _DPPHY_IBIAS_SEL             0x021F
#define _DPPHY_FA1_DIV               0x0220
#define _DPPHY_FA1_FREQ_HI           0x0221
#define _DPPHY_FA1_FREQ_MI           0x0222
#define _DPPHY_FA1_FREQ_LO           0x0223
#define _DPPHY_FA2_DIV               0x0224
#define _DPPHY_FA2_FREQ_HI           0x0225
#define _DPPHY_FA2_FREQ_MI           0x0226
#define _DPPHY_FA2_FREQ_LO           0x0227
#define _DPPHY_LDO_CTRL              0x0228
#define _DPPHY_LINK_CTRL             0x0229
#define _DPPHY_DUAL_LINK             0x022B
#define _DPPHY_READ_MODE             0x02F0

extern xdata UCHAR volatile SC_LVDS_1D00[];

extern xdata UCHAR volatile SC_ADC_IP_CTRL_1D80[];
#define _ADC_GAIN_B 0x00
#define _ADC_GAIN_G 0x01
#define _ADC_GAIN_R 0x02
#define _ADC_OFFSET_B 0x03
#define _ADC_OFFSET_G 0x04
#define _ADC_OFFSET_R 0x05
#define _ADC_DC_LEVEL_B 0x06
#define _ADC_DC_LEVEL_G 0x07
#define _ADC_DC_LEVEL_R 0x08
#define _ADC_BW_SEL_BP 0x09
#define _ADC_BW_SEL_BN 0x0A
#define _ADC_BW_SEL_GP 0x0B
#define _ADC_BW_SEL_GN 0x0C
#define _ADC_BW_SEL_RP 0x0D
#define _ADC_BW_SEL_RN 0x0E
#define _ADC_P_CLAMP_EN 0x0F
#define _ADC_VICM_BIAS 0x10
#define _ADC_VMID_CTRL 0x11
#define _ADC_VREF_BIAS 0x12
#define _ADC_CLAMP_SPEED 0x13
#define _ADC_BIAS_CTRL1 0x14
#define _ADC_BIAS_CTRL2 0x15
#define _ADC_N_CLAMP_EN 0x16
#define _ADC_SF_BIAS 0x17
#define _ADC_CDS 0x18
#define _ADC_COMP_BIAS 0x19
#define _ADC_SGND_BIAS 0x1A
#define _ADC_MISC_CTRL_1B 0x1B
#define _ADC_TRIM_VALUE 0x1C
#define _ADC_GAIN_OFFSET_BIAS 0x1D
#define _ADC_SRC_FOLLOWER_CURRENT 0x1E
#define _ADC_TRIMMING_SEL 0x20
#define _ADC_BANDGAP_SET  0x21
#define _ADC_CLAMP_VMID_SEL 0x22
#define _ADC_COMMON_MODE_SEL 0x23
#define _ADC_SOG_DISCUR 0x30
#define _ADC_SOG_THRESHOLD 0x31
#define _ADC_SOG_CLAMP_CURRENT 0x32
#define _ADC_MISC_CTRL_33 0x33
#define _ADC_MISC_CTRL_34 0x34
#define _ADC_POWER_CTRL 0x35
#define _ADC_GAIN_DITHER 0x40
#define _ADC_OFFSET_DITHER 0x41
#define _ADC_CHANNEL_SWAP 0x42

extern xdata UCHAR volatile SC_TMDS_PHY_LINK_CTRL_1DE0;
extern xdata UCHAR volatile SC_TMDS_PHY_LINK_CTRL_1DE1;

extern xdata UCHAR volatile SC_COMBO_TX_1E00[];//APHY
extern xdata UCHAR volatile SC_EDP_TX_DPHY_1F00[];//DPHY

extern xdata UCHAR volatile SC_DP_AUDIO_16D6;

// 20150925 Yung add for USB Type C 
extern xdata UCHAR volatile SC_USBC_CC_CFG;             // 0x8D60
extern xdata UCHAR volatile SC_USBC_CC_RESET_CTRL;      // 0xD61
extern xdata UCHAR volatile SC_USBC_CC_REF_CLK_SET;     // 0xD62
extern xdata UCHAR volatile SC_USBC_CC_FILTER_LENGTH;   // 0xD63
extern xdata UCHAR volatile SC_USBC_CC_IDLE_DET_CTRL;   // 0xD64
extern xdata UCHAR volatile SC_USBC_CC_IDLE_DET_WINDOW; // 0xD65
extern xdata UCHAR volatile SC_USBC_CC_INT_RTX_FSM_READ ;   // 0xD66
extern xdata UCHAR volatile SC_USBC_CC_BIST_CTRL;   // 0xD68

extern xdata UCHAR volatile SC_USBC_CC_BIST_ENTER_HOLD_TIME; // _at_ 0x8D69;

extern xdata UCHAR volatile SC_USBC_CC_HPDPD_CTRL1;	// _at_ 0x8D6A;
extern xdata UCHAR volatile SC_USBC_CC_HPDPD_CTRL2;	// _at_ 0x8D6B;
extern xdata UCHAR volatile SC_USBC_CC_TEST_MODE1;	// _at_ 0x8D6E;
extern xdata UCHAR volatile SC_USBC_CC_TEST_MODE2;	// _at_ 0x8D6F;
extern xdata UCHAR volatile SC_USBC_CC_TX_BIT_TIME;	// _at_ 0x8D70;
extern xdata UCHAR volatile SC_USBC_CC_TX_PREAMBLE_NUM;	// _at_ 0x8D71;
extern xdata UCHAR volatile SC_USBC_CC_TX_CTRL_CONFLICT; // _at_ 0x8D72;


extern xdata UCHAR volatile SC_USBC_CC_TX_HOLD_TIME;	// _at_ 0x8D73;
extern xdata UCHAR volatile SC_USBC_CC_RTX_INOUT_CONFLICT_MASK;	// _at_ 0x8D74;

// 
extern xdata UCHAR volatile SC_USBC_CC_TX_AUTO_MSGID;   // _at_ 0x8D75;
extern xdata UCHAR volatile SC_USBC_CC_TX_ITF_GAP_HBYTE;    // _at_ 0x8D76;
extern xdata UCHAR volatile SC_USBC_CC_TX_ITF_GAP_LBYTE;    // _at_ 0x8D77;

extern xdata UCHAR volatile SC_USBC_CC_RX_AUTO_BIT_TIME;    // _at_ 0x8D78;
extern xdata UCHAR volatile SC_USBC_CC_RX_AUTO_BIT_TIME_LENGTH; // _at_ 0x8D79;
extern xdata UCHAR volatile SC_USBC_CC_RX_BIT_TIME_LOW_TH;  // _at_ 0x8D7A;
extern xdata UCHAR volatile SC_USBC_CC_RX_BIT_TIME_HIGH_TH; // _at_ 0x8D7B;
extern xdata UCHAR volatile SC_USBC_CC_RX_CTRL2;    // _at_ 0x8D7C;
	#define CC_RX_4B5B_DEC_IN_INV       BIT0
	#define CC_RX_4B5B_DEC_OUT_INV      BIT1
	#define CC_RX_BIT_LATCH_MODE        BIT2
	#define CC_RX_CMD_CORRECT_DISABLE   BIT3
	#define CC_RX_CERR_BAN              BIT4
	#define CC_RX_FIFO_FULL_BAN         BIT5
	#define CC_RX_LISTEN_MODE_EN        BIT6
	#define CC_RX_DROP_ERR_MSGID_MSG    BIT7


extern xdata UCHAR volatile SC_USBC_CC_RX_CMD_GATE;
extern xdata UCHAR volatile SC_USBC_CC_RX_AUTO_REPLY_ENABLE;    // _at_ 0x8D7E;
	#define CC_RX_GoodCRC_CHK_MSGID     BIT0
	#define CC_RX_Auto_Reply_GoodCRC    BIT1
	#define CC_RX_CHK_CRC               BIT3
extern xdata UCHAR volatile SC_USBC_CC_RX_PREAMBLE_NUM;     // _at_ USBTypec_Page+0x7F;    

// TX send Command control register
extern xdata UCHAR volatile SC_USBC_CC_TX_CTRL; // _at_ 0x8D80;
extern xdata UCHAR volatile SC_USBC_CC_TX_MANUAL_ADDR;  // _at_ 0x8D81;
	#define CC_Req_Respons_Type_Data_MSG             BIT6
	#define CC_Get_Respons_Type_Data_MSG             BIT7
extern xdata UCHAR volatile SC_USBC_CC_TX_WRITE_DATA;   // _at_ 0x8D82;

// RX Get command and Data
extern xdata UCHAR volatile SC_USBC_CC_RX_CTRL;  // _at_ 0x8D84;
	#define CC_RX_RD_VALID              BIT0
	#define CC_RX_RD_CMD_MASK           0x70   
extern xdata UCHAR volatile SC_USBC_CC_RX_MANUAL_ADDR; // _at_ 0x8D85;
extern xdata UCHAR volatile SC_USBC_CC_RX_READ_DATA; // _at_ 0x8D86;

// Timer Register
extern xdata UCHAR volatile SC_USBC_CC_TIMER_CTRL;  // _at_ 0x8D88;
	#define CC_Manu_Timer0_START             BIT0
	#define CC_Manu_Timer1_START             BIT1
extern xdata UCHAR volatile SC_USBC_CC_TIMER_PERIODH;   // _at_ 0x8D89;
extern xdata UCHAR volatile SC_USBC_CC_TIMER_PERIODL;   // _at_ 0x8D8A;

// Counter register
extern xdata UCHAR volatile SC_USBC_CC_COUNTER_SEL_CLEAR;   // _at_ 0x8D8D;
extern xdata UCHAR volatile SC_USBC_CC_COUNTER_READH;   // _at_ 0x8D8E;
extern xdata UCHAR volatile SC_USBC_CC_COUNTER_READL;   // _at_ 0x8D8F;

// Interrupt register
extern xdata UCHAR volatile SC_USBC_CC_INT_GROUP_0_FLAG;    // _at_ 0x8D90;
	#define CC_ATTACH_TRIGER		    BIT0
	#define CC_IDLE_STATE_CHG		    BIT1			// 
	#define CC_TX_CMD_DONE      	    BIT2			// 
	#define PROTOCOL_RD_SUCCESS 	    BIT3			// 
	#define RX_GET_GOOD_CRC     	    BIT4			// 
extern xdata UCHAR volatile SC_USBC_CC_INT_GROUP_1_FLAG;    // _at_ 0x8D91;
	#define PROTOCOL_GET_CMD_SOP 	    BIT0			// 
	#define PROTOCOL_GET_CMD_SOPP 	    BIT1			// 
	#define PROTOCOL_GET_CMD_SOPPP 	    BIT2			// 
	#define PROTOCOL_GET_CMD_HARD_RST 	BIT3			// 
	#define PROTOCOL_GET_CMD_CABLE_RST 	BIT4			// 
	#define PROTOCOL_GET_CMD_SOPPD 	    BIT5			// 
	#define PROTOCOL_GET_CMD_SOPppD 	BIT6			// 
	#define PROTOCOL_GET_CMD_SOFT_RST 	BIT7			// 
extern xdata UCHAR volatile SC_USBC_CC_INT_GROUP_2_FLAG;    // _at_ 0x8D92; error handle interrupt
	#define IN_OUT_Conflict             BIT0			// 
	#define Invalid_Bit_Time 	        BIT1			// 
	#define Invalid_Preanble     	    BIT2			// 
	#define Code_Error_4B5B      	    BIT3			// 
	#define Incrrect_CRC             	BIT4			// 
	#define PROTOCOL_RD_FIFO_Full      	BIT5			// 
	#define PROTOCOL_Get_Error_CMD     	BIT6			// 
	#define VDM_Busy_Overflow          	BIT7			// 


extern xdata UCHAR volatile SC_USBC_CC_INT_GROUP_3_FLAG;    // _at_ 0x8D93;
	#define PROTOCOL_GET_PD_Msg 	    BIT2			// 
	//#define PROTOCOL_GET_Message 	    BIT2			// 
	#define PROTOCOL_GET_Capability 	BIT3			// 
	#define PROTOCOL_GET_Wait 	        BIT4			// 
	#define PROTOCOL_GET_VDM_Msg 	    BIT5			// 
	#define PROTOCOL_GET_VDM_busy 	    BIT6			// 
	#define PROTOCOL_GET_VDM_Sts_Upd 	BIT7			// 

extern xdata UCHAR volatile SC_USBC_CC_INT_GROUP_4_FLAG;    // _at_ 0x8D94;
	#define Manual_Timer0_Flag          BIT0			// 
	#define Manual_Timer1_Flag     	    BIT1			// 
	#define CRCReceiverTimer_Flag       BIT2			// 
	#define SenderResponseTimer_Flag    BIT3			// 
	#define SinkActivityTimer_Flag      BIT4			// 
	#define SinkWaitCapTimer_Flag       BIT5			// 
	#define SinkRequestTimer_Flag       BIT6			// 
	#define BISTContModeTimer_Flag      BIT7			// 
    

extern xdata UCHAR volatile SC_USBC_CC_INT_GROUP_0_EN;  // _at_ 0x8D98;
extern xdata UCHAR volatile SC_USBC_CC_INT_GROUP_1_EN;  // _at_ 0x8D99;
extern xdata UCHAR volatile SC_USBC_CC_INT_GROUP_2_EN;  // _at_ 0x8D9A;
extern xdata UCHAR volatile SC_USBC_CC_INT_GROUP_3_EN;  // _at_ 0x8D9B;
extern xdata UCHAR volatile SC_USBC_CC_INT_GROUP_4_EN;  // _at_ 0x8D9C;


// USB CC IO PHY Control
extern xdata UCHAR volatile SC_USBC_CC_IO_LDO_CTRL;    // _at_ USBTypec_Page+0xA0;
extern xdata UCHAR volatile SC_USBC_CC_IO_BANDGAP_CTRL;    // _at_ USBTypec_Page+0xA1;
extern xdata UCHAR volatile SC_USBC_CC_IO_BIAS_SEL; // _at_ USBTypec_Page+0xA2;
extern xdata UCHAR volatile SC_USBC_CC_IO_CC1_CTRL; // _at_ USBTypec_Page+0xA3;
extern xdata UCHAR volatile SC_USBC_CC_IO_CC2_CTRL; // _at_ USBTypec_Page+0xA4;
extern xdata UCHAR volatile SC_USBC_CC_IO_CC_DRIVER_CTRL;   // _at_ USBTypec_Page+0xA5;
extern xdata UCHAR volatile SC_USBC_CC_PHY_RESERVED;    // _at_ USBTypec_Page+0xA6;

//******************************************************************************
// F U N C T I O N    P R O T O T Y P E S
//******************************************************************************

#endif //__SCALERREG_H__
