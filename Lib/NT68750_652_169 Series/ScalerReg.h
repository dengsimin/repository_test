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
    #define YPBPR_CLAMP            0x03
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
extern xdata UCHAR volatile SC_DVI_CLK;
extern xdata UCHAR volatile SC_ADC_CTRL2;
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
extern xdata UCHAR volatile SC_PWMA_LCNT;
extern xdata UCHAR volatile SC_PWMA_HCNT;
extern xdata UCHAR volatile SC_PWMB_LCNT;
extern xdata UCHAR volatile SC_PWMB_HCNT;
extern xdata UCHAR volatile SC_PWMA_DUTY_LO;
extern xdata UCHAR volatile SC_PWMB_DUTY_LO;
extern xdata UCHAR volatile SC_PWM_COUNTER;
extern xdata UCHAR volatile SC_PWM_CTRL1;
extern xdata UCHAR volatile SC_PWM_CTRL2;
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
extern xdata UCHAR volatile SC_ADC_REG_1D;
extern xdata UCHAR volatile SC_ADC_COMP_CTRL;
extern xdata UCHAR volatile SC_ADC_BAND_GAP;
extern xdata UCHAR volatile SC_BYPASS_CTRL;
extern xdata UCHAR volatile SC_LVDS_RSDS_SWITCH;
extern xdata UCHAR volatile SC_ADC_OP_CURRENT;
extern xdata UCHAR volatile SC_LVDS_CONTROL;
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

extern xdata UCHAR volatile SC_DVI_CTRL_300;
extern xdata UCHAR volatile SC_DVI_CTRL_301;
extern xdata UCHAR volatile SC_DVI_RB_SWAP;
extern xdata UCHAR volatile SC_DVI_CTRL_303;
extern xdata UCHAR volatile SC_DVI_PIXELCLK_LO;
extern xdata UCHAR volatile SC_DVI_PIXELCLK_HI;
extern xdata UCHAR volatile SC_DVI_CTRL_306;
extern xdata UCHAR volatile SC_DVI_CTRL_308;
extern xdata UCHAR volatile SC_DVI_CTRL_309;
extern xdata UCHAR volatile SC_DVI_CTRL_310;
extern xdata UCHAR volatile SC_DVI_CTRL_311;
extern xdata UCHAR volatile SC_DVI_CTRL_317;
extern xdata UCHAR volatile SC_DVI_CTRL_330;
extern xdata UCHAR volatile SC_DVI_CTRL_331;
extern xdata UCHAR volatile SC_DVI_CTRL_332;
extern xdata UCHAR volatile SC_DVI_CTRL_333;
extern xdata UCHAR volatile SC_DVI_CTRL_334;
extern xdata UCHAR volatile SC_DVI_CTRL_335;
extern xdata UCHAR volatile SC_DVI_CTRL_336;
extern xdata UCHAR volatile SC_DVI_CTRL_337;
extern xdata UCHAR volatile SC_DVI_CTRL_338;
extern xdata UCHAR volatile SC_DVI_CTRL_339;
extern xdata UCHAR volatile SC_DVI_CTRL_33A;
extern xdata UCHAR volatile SC_DVI_CTRL_33B;
extern xdata UCHAR volatile SC_DVI_CTRL_33C;
extern xdata UCHAR volatile SC_DVI_CTRL_33D;
extern xdata UCHAR volatile SC_DVI0_PIXELCLK_LO;
extern xdata UCHAR volatile SC_DVI0_PIXELCLK_HI;

extern xdata UCHAR volatile SC_DVI_SLAVE_CTRL_340;
extern xdata UCHAR volatile SC_DVI_SLAVE_CTRL_341;
extern xdata UCHAR volatile SC_DVI_SLAVE_RB_SWAP;
extern xdata UCHAR volatile SC_DVI_SLAVE_CTRL_343;
extern xdata UCHAR volatile SC_DVI_SLAVE_PIXELCLK_LO;
extern xdata UCHAR volatile SC_DVI_SLAVE_PIXELCLK_HI;
extern xdata UCHAR volatile SC_DVI_SLAVE_CTRL_346;
extern xdata UCHAR volatile SC_DVI_SLAVE_CTRL_348;
extern xdata UCHAR volatile SC_DVI_SLAVE_CTRL_349;
extern xdata UCHAR volatile SC_DVI_SLAVE_CTRL_350;
extern xdata UCHAR volatile SC_DVI_SLAVE_CTRL_351;
extern xdata UCHAR volatile SC_DVI_SLAVE_CTRL_357;
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
//extern xdata UCHAR volatile SC_OVERSCAN_MODE;
extern xdata UCHAR volatile SC_ESD_CHECKSUM;
extern xdata UCHAR volatile SC_OSD_CHECKSUM;
extern xdata UCHAR volatile SC_DISPLAY_CHECKSUM;
extern xdata UCHAR volatile SC_DPLL_CHECKSUM;
extern xdata UCHAR volatile SC_LVDS_CHECKSUM;
extern xdata UCHAR volatile SC_ESD_ERROR_CHECKSUM;

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

extern xdata UCHAR volatile SC_AUTO_INTERLACED_CTRL1;
extern xdata UCHAR volatile SC_AUTO_INTERLACED_CTRL2;
extern xdata UCHAR volatile SC_AUTO_INTERLACED_CTRL3;
extern xdata UCHAR volatile SC_FRAME_BUFFER_BASE_ADDR_OD_LO;
extern xdata UCHAR volatile SC_FRAME_BUFFER_BASE_ADDR_OD_MI;
extern xdata UCHAR volatile SC_FRAME_BUFFER_BASE_ADDR_OD_HI;
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

extern xdata UCHAR volatile SC_HDCP_PROG_SEL;

extern xdata UCHAR volatile SC_HDMI_SOFTWARE_RESET;
extern xdata UCHAR volatile SC_HDMI_CLK_INT;

extern xdata UCHAR volatile SC_HDCP_BKSV;
extern xdata UCHAR volatile SC_HDCP_BKSV_B2;
extern xdata UCHAR volatile SC_HDCP_BKSV_B3;
extern xdata UCHAR volatile SC_HDCP_BKSV_B4;
extern xdata UCHAR volatile SC_HDCP_BKSV_B5;
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
extern xdata UCHAR volatile SC_VIDEO_BLANK_BLUE;
extern xdata UCHAR volatile SC_VIDEO_BLANK_GREEN;
extern xdata UCHAR volatile SC_VIDEO_BLANK_RED;
extern xdata UCHAR volatile SC_VIDEO_DE_WIDTH_LO;
extern xdata UCHAR volatile SC_VIDEO_DE_WIDTH_HI;
extern xdata UCHAR volatile SC_VIDEO_DE_LINE_LO;
extern xdata UCHAR volatile SC_VIDEO_DE_LINE_HI;
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
extern xdata UCHAR volatile SC_AUDIO_EXT_CAP_CTRL;
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
extern xdata UCHAR volatile SC_HDMI_MUTE;
extern xdata UCHAR volatile SC_HDMI_BYPASS;
extern xdata UCHAR volatile SC_HDMI_AVI_TYPE;
extern xdata UCHAR volatile SC_HDMI_AVI_VER;
extern xdata UCHAR volatile SC_HDMI_AVI_LEM;
extern xdata UCHAR volatile SC_HDMI_AVI_CKSM;
extern xdata UCHAR volatile SC_HDMI_AVI[];
extern xdata UCHAR volatile SC_AUDIO_INFO_FRAME_DB[];

extern xdata UCHAR volatile SC_FPGA_HDMI_DELAY;

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
extern xdata UCHAR volatile SC_FPGA_AUDIO_PLL;
extern xdata UCHAR volatile SC_HDCP_BKSV2;
extern xdata UCHAR volatile SC_HDCP_SLAVE_ADDR2;
extern xdata UCHAR volatile SC_SCALER_3D_DEBUG1;

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
extern xdata UCHAR volatile SC_MMU_DLL_PHASE_CTRL0;
extern xdata UCHAR volatile SC_MMU_DLL_PHASE_CTRL1;
extern xdata UCHAR volatile SC_MMU_DLL_PHASE_CTRL2;
extern xdata UCHAR volatile SC_MMU_DLL_PHASE_CTRL3;

extern xdata UCHAR volatile SC_DVI_PLL_M;
extern xdata UCHAR volatile SC_VPLL_CTRL;

extern xdata UCHAR volatile SC_VCLK_RATIO_LO;
extern xdata UCHAR volatile SC_VCLK_RATIO_MI;
extern xdata UCHAR volatile SC_VCLK_RATIO_HI;

extern xdata UCHAR volatile SC_MCLK_RATIO_LO;
extern xdata UCHAR volatile SC_MCLK_RATIO_MI;
extern xdata UCHAR volatile SC_MCLK_RATIO_HI;
extern xdata UCHAR volatile SC_MCLK_SSC_CTRL;

extern xdata UCHAR volatile SC_FRC_RATIO_LO;
extern xdata UCHAR volatile SC_FRC_RATIO_MI;
extern xdata UCHAR volatile SC_FRC_RATIO_HI;

extern xdata UCHAR volatile SC_MPLL_DIV;
extern xdata UCHAR volatile SC_MPLL_CTRL_B41;
extern xdata UCHAR volatile SC_MPLL_CTRL_B42;
extern xdata UCHAR volatile SC_MPLL_LDO_VADJ;
extern xdata UCHAR volatile SC_MPLL_X2;
extern xdata UCHAR volatile SC_SSC_FDEV;
extern xdata UCHAR volatile SC_SSC_FMOD;

extern xdata UCHAR volatile SC_MCU_CLK_SSC;
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
extern xdata UCHAR volatile SC_ADC_TRIM_CTRL;
extern xdata UCHAR volatile SC_ADC_CTRL_OPTION1;
extern xdata UCHAR volatile SC_ADC_CTRL_OPTION2;
extern xdata UCHAR volatile SC_ADC_CTRL_OPTION3;
extern xdata UCHAR volatile SC_ISOLATION_CONTROL;
extern xdata UCHAR volatile SC_CUT_POWER_CTRL;
extern xdata UCHAR volatile SC_ADC_LDO;
extern xdata UCHAR volatile SC_MCU_IO_CTRL1;
extern xdata UCHAR volatile SC_MCU_IO_CTRL2;
extern xdata UCHAR volatile SC_MCU_IO_CTRL3;
extern xdata UCHAR volatile SC_MCU_IO_CTRL4;
/*OSD 2 *//////////////////////////////////////////////
extern xdata UCHAR volatile SC_OSD_FRAME2_FUNC_CTRL;
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
extern xdata UCHAR volatile SC_VREF_VOLTAGE_MODE1;
extern xdata UCHAR volatile SC_VREF_VOLTAGE_MODE2;

//Local Dimming
extern xdata UCHAR volatile SC_LD_CTRL;
extern xdata UCHAR volatile SC_LD_LEFT_BOUND_LO;
extern xdata UCHAR volatile SC_LD_LEFT_BOUND_HI;
extern xdata UCHAR volatile SC_LD_RIGHT_BOUND_LO;
extern xdata UCHAR volatile SC_LD_RIGHT_BOUND_HI;
extern xdata UCHAR volatile SC_LD_TOP_BOUND_LO;
extern xdata UCHAR volatile SC_LD_TOP_BOUND_HI;
extern xdata UCHAR volatile SC_LD_BOTTOM_BOUND_LO;
extern xdata UCHAR volatile SC_LD_BOTTOM_BOUND_HI;
extern xdata UCHAR volatile SC_LD_BLOCK_WIDTH_LO;
extern xdata UCHAR volatile SC_LD_BLOCK_WIDTH_HI;
extern xdata UCHAR volatile SC_LD_BLOCK_HEIGHT_LO;
extern xdata UCHAR volatile SC_LD_BLOCK_HEIGHT_HI;
extern xdata UCHAR volatile SC_LD_ZONE_PITCH;

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

extern xdata UCHAR volatile SC_LD_HBLK_WIDTH_LO;
extern xdata UCHAR volatile SC_LD_HBLK_WIDTH_HI;
extern xdata UCHAR volatile SC_LD_VBLK_HEIGHT_LO;
extern xdata UCHAR volatile SC_LD_VBLK_HEIGHT_HI;
extern xdata UCHAR volatile SC_LD_H_ZONE_NUM;
extern xdata UCHAR volatile SC_LD_V_ZONE_NUM;
extern xdata UCHAR volatile SC_LD_DIM01_DEFINE_CTRL;
extern xdata UCHAR volatile SC_LD_DIM23_DEFINE_CTRL;
extern xdata UCHAR volatile SC_LD_DIM45_DEFINE_CTRL;
extern xdata UCHAR volatile SC_LD_DIM67_DEFINE_CTRL;

extern xdata UCHAR volatile SC_SR_CTRL;
//FLT1 median Filter
extern xdata UCHAR volatile FLT1_TH;
extern xdata UCHAR volatile FLT1_CUT_SLOP;
extern xdata UCHAR volatile FLT1_SLOP_TH;
extern xdata UCHAR volatile FLT1_VAR_TH_LO;
extern xdata UCHAR volatile FLT1_SLOP_VAR_TH_HI;


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

#if IS_NT68661_SERIES
//SR Htotal
extern xdata UCHAR volatile SC_SR_HTOTAL_LO;
extern xdata UCHAR volatile SC_SR_HTOTAL_HI;
//SR Hactive
extern xdata UCHAR volatile SC_SR_HACT_LO;
extern xdata UCHAR volatile SC_SR_HACT_HI;
//SR Vactive
extern xdata UCHAR volatile SC_SR_VACT_LO;
extern xdata UCHAR volatile SC_SR_VACT_HI;
#endif

//******************************************************************************
// F U N C T I O N    P R O T O T Y P E S
//******************************************************************************

#endif //__SCALERREG_H__
