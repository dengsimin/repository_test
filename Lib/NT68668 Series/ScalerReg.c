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
#include "ScalerReg.h"

//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************

//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************
xdata UCHAR volatile SC_ADC_CTRL _at_ 0x8000;
xdata UCHAR volatile SC_RGAIN_HI _at_ 0x8001;
xdata UCHAR volatile SC_ADC_TEST1 _at_ 0x8002;
xdata UCHAR volatile SC_ROFFSET _at_ 0x8003;
xdata UCHAR volatile SC_GGAIN_HI _at_ 0x8004;
xdata UCHAR volatile SC_ADC_TEST2 _at_ 0x8005;
xdata UCHAR volatile SC_GOFFSET _at_ 0x8006;
xdata UCHAR volatile SC_BGAIN_HI _at_ 0x8007;
xdata UCHAR volatile SC_ADC_MID_CH_SEL _at_ 0x8008;
xdata UCHAR volatile SC_BOFFSET _at_ 0x8009;
xdata UCHAR volatile SC_SOG_CURRENT_CTRL _at_ 0x800A;
xdata UCHAR volatile SC_SOG_DIGITAL_GLITCH_FILTER_THREESHOLD _at_ 0x800B;
xdata UCHAR volatile SC_SOG_GLITCH_MASK_LO _at_ 0x800C;
xdata UCHAR volatile SC_SOG_DIGITAL_FILTER_CTRL _at_ 0x800D;
xdata UCHAR volatile SC_ADC_POWER_UP _at_ 0x800E;
xdata UCHAR volatile SC_ADC_CLAMP_CTRL _at_ 0x800F;
xdata UCHAR volatile SC_ADC_BW_CTRL _at_ 0x8010;
xdata UCHAR volatile SC_SOG_SLICER_CTRL _at_ 0x8012;
xdata UCHAR volatile SC_ADC_INPUT_CTRL _at_ 0x8013;
xdata UCHAR volatile SC_HS_TRIG_LEVEL _at_ 0x8014;
xdata UCHAR volatile SC_VS_TRIG_LEVEL _at_ 0x8015;
xdata UCHAR volatile SC_PRE_PATTER_CTRL _at_ 0x801F;
xdata UCHAR volatile SC_GPORT_CTRL _at_ 0x8020;
xdata UCHAR volatile SC_CLAMP_BEGIN _at_ 0x8021;
xdata UCHAR volatile SC_CLAMP_WIDTH _at_ 0x8022;
xdata UCHAR volatile SC_DIGITAL_CTRL _at_ 0x8023;
xdata UCHAR volatile SC_INPUT_SELECT _at_ 0x8024;
xdata UCHAR volatile SC_ADC_CK_CTRL _at_ 0x8025;
xdata UCHAR volatile SC_CAP_SWAP _at_ 0x8026;
xdata UCHAR volatile SC_GI_V_DE_DLY _at_ 0x8027;
xdata UCHAR volatile SC_GI_HMASK_BEG _at_ 0x802A;
xdata UCHAR volatile SC_GI_HMASK_END _at_ 0x802B;
xdata UCHAR volatile SC_GI_VMASK_BEG _at_ 0x802C;
xdata UCHAR volatile SC_GI_VMASK_END _at_ 0x802D;
xdata UCHAR volatile SC_GI_CAP_VBEGO_LO _at_ 0x802E;
xdata UCHAR volatile SC_GI_CAP_VBEGO_HI _at_ 0x802F;
xdata UCHAR volatile SC_GI_CAP_VBEGE_LO _at_ 0x8030;
xdata UCHAR volatile SC_GI_CAP_VBEGE_HI _at_ 0x8031;
xdata UCHAR volatile SC_GI_CAP_VLEN_LO _at_ 0x8032;
xdata UCHAR volatile SC_GI_CAP_VLEN_HI _at_ 0x8033;
xdata UCHAR volatile SC_GI_CAP_HBEG_LO _at_ 0x8034;
xdata UCHAR volatile SC_GI_CAP_HBEG_HI _at_ 0x8035;
xdata UCHAR volatile SC_GI_CAP_HWID_LO _at_ 0x8036;
xdata UCHAR volatile SC_GI_CAP_HWID_HI _at_ 0x8037;
xdata UCHAR volatile SC_GI_ALT_CTRL _at_ 0x8038;
xdata UCHAR volatile SC_DVI_CAP_HWID_LO _at_ 0x803C;
xdata UCHAR volatile SC_DVI_CAP_HWID_HI _at_ 0x803D;
xdata UCHAR volatile SC_DVI_CAP_VLEN_LO _at_ 0x803E;
xdata UCHAR volatile SC_DVI_CAP_VLEN_HI _at_ 0x803F;
xdata UCHAR volatile SC_VI_PORT_CTRL _at_ 0x8040;
xdata UCHAR volatile SC_VI_PORT_SELECT _at_ 0x8041;
xdata UCHAR volatile SC_VI_POLARITY_CTRL _at_ 0x8042;
xdata UCHAR volatile SC_SOG_T1_POSITION _at_ 0x8043;
xdata UCHAR volatile SC_SOG_T2_POSITION _at_ 0x8044;
xdata UCHAR volatile SC_SOG_T1_T2_WIDTH _at_ 0x8046;
xdata UCHAR volatile SC_SOG_MODE_SEL _at_ 0x8048;
xdata UCHAR volatile SC_COLOR_COFFA_LO _at_ 0x804B;
xdata UCHAR volatile SC_COLOR_COFFA_HI _at_ 0x804C;
xdata UCHAR volatile SC_COLOR_COFFB_LO _at_ 0x804D;
xdata UCHAR volatile SC_COLOR_COFFB_HI _at_ 0x804E;
xdata UCHAR volatile SC_COLOR_COFFC_LO _at_ 0x804F;
xdata UCHAR volatile SC_COLOR_COFFC_HI _at_ 0x8050;
xdata UCHAR volatile SC_COLOR_COFFD_LO _at_ 0x8051;
xdata UCHAR volatile SC_COLOR_COFFD_HI _at_ 0x8052;
xdata UCHAR volatile SC_DEI_CSC_CTRL _at_ 0x8053;
#if IS_NT68168_SERIES || IS_NT68668_SERIES
xdata UCHAR volatile SC_MCU_CLK_DIVIDER _at_ 0x8054;
xdata UCHAR volatile SC_ZERO_POWER_LDO18 _at_ 0x8055;
xdata UCHAR volatile SC_OSC_LDO18 _at_ 0x8056;
xdata UCHAR volatile SC_ADC_ZERO_POWER_CTRL _at_ 0x8057;
xdata UCHAR volatile SC_DVI_ZERO_POWER_CTRL _at_ 0x8058;
xdata UCHAR volatile SC_DVI_ZERO_POWER_DETECT _at_ 0x8059;
xdata UCHAR volatile SC_APR_LDO_CTRL _at_ 0x805A;
#endif
xdata UCHAR volatile SC_BK_H_SHAP_CTRL _at_ 0x8060;
xdata UCHAR volatile SC_SRGB_DITHER _at_ 0x8061;
xdata UCHAR volatile SC_INTE_CTRL _at_ 0x8064;
xdata UCHAR volatile SC_GAMMA_CTRL _at_ 0x8065;
xdata UCHAR volatile SC_BK_V_SHAP_CTRL _at_ 0x8066;
xdata UCHAR volatile SC_INTERPOLATION_THRESHOLD _at_ 0x8067;
xdata UCHAR volatile SC_NR_CTRL _at_ 0x8068;
xdata UCHAR volatile SC_NR_THR_CTRL1 _at_ 0x8069;
xdata UCHAR volatile SC_JITTER_CTRL _at_ 0x806A;
xdata UCHAR volatile SC_NR_THR_CTRL2 _at_ 0x806B;
xdata UCHAR volatile SC_VER_INTERPOLATION_OFFSET _at_ 0x806C;
xdata UCHAR volatile SC_NR_RANDOM_GENERATOR_CTRL _at_ 0x806D;
xdata UCHAR volatile SC_NR3_CTRL1 _at_ 0x806E;
xdata UCHAR volatile SC_NR3_CTRL2 _at_ 0x806F;
xdata UCHAR volatile SC_GPIO_CTRL _at_ 0x8070;
#if IS_NT68650_SERIES || IS_NT68660_SERIES
xdata UCHAR volatile GAMMA_VALUE_INTER_CTRL_LO _at_ 0x8071;
#endif
xdata UCHAR volatile SC_BP_SYNC_CTRL _at_ 0x8072;
#if IS_NT68650_SERIES || IS_NT68660_SERIES
xdata UCHAR volatile GAMMA_VALUE_INTER_CTRL_HI _at_ 0x8073;
#endif
xdata UCHAR volatile SC_PWMA_LCNT _at_ 0x8074;
xdata UCHAR volatile SC_PWMA_HCNT _at_ 0x8075;
xdata UCHAR volatile SC_PWMB_LCNT _at_ 0x8076;
xdata UCHAR volatile SC_PWMB_HCNT _at_ 0x8077;
xdata UCHAR volatile SC_PWMA_DUTY_LO _at_ 0x8078;
xdata UCHAR volatile SC_PWMB_DUTY_LO _at_ 0x8079;
xdata UCHAR volatile SC_PWM_COUNTER _at_ 0x807A;
#if (IS_NT68168_SERIES)
xdata UCHAR volatile SC_PWMIO_CTRL _at_ 0x807B;
#endif
xdata UCHAR volatile SC_PWM_CTRL1 _at_ 0x807E;
xdata UCHAR volatile SC_PWM_CTRL2 _at_ 0x807F;
xdata UCHAR volatile SC_OSD_CTRL1 _at_ 0x8080;
xdata UCHAR volatile SC_OSD_HS_LO _at_ 0x8081;
xdata UCHAR volatile SC_OSD_HS_HI _at_ 0x8082;
xdata UCHAR volatile SC_OSD_HW _at_ 0x8083;
xdata UCHAR volatile SC_OSD_VS_LO _at_ 0x8084;
xdata UCHAR volatile SC_OSD_VS_HI _at_ 0x8085;
xdata UCHAR volatile SC_OSD_VH _at_ 0x8086;
xdata UCHAR volatile SC_OSD_SHIFT_ROW _at_ 0x8087;
xdata UCHAR volatile SC_OSD_FONT1B_ADDR_LO _at_ 0x8088;
xdata UCHAR volatile SC_OSD_FONT1B_ADDR_HI _at_ 0x8089;
xdata UCHAR volatile SC_OSD_FONT2B_ADDR_LO _at_ 0x808A;
xdata UCHAR volatile SC_OSD_FONT2B_ADDR_HI _at_ 0x808B;
xdata UCHAR volatile SC_OSD_FONT4B_ADDR_LO _at_ 0x808C;
xdata UCHAR volatile SC_OSD_FONT4B_ADDR_HI _at_ 0x808D;
xdata UCHAR volatile SC_OSD_FADE_STEP _at_ 0x808E;
xdata UCHAR volatile SC_OSD_FADE_FREQ _at_ 0x808F;
xdata UCHAR volatile SC_OSD_ZOOM_CTL _at_ 0x8090;
xdata UCHAR volatile SC_OSD_HZM_PATN_LO _at_ 0x8091;
xdata UCHAR volatile SC_OSD_HZM_PATN_HI _at_ 0x8092;
xdata UCHAR volatile SC_OSD_VZM_PATN_LO _at_ 0x8093;
xdata UCHAR volatile SC_OSD_VZM_PATN_MI _at_ 0x8094;
xdata UCHAR volatile SC_OSD_VHGLOB_ZMRNG _at_ 0x8095;
xdata UCHAR volatile SC_OSD_HOR_ROW_ZOOM_CTRL1 _at_ 0x8096;
xdata UCHAR volatile SC_OSD_HOR_ROW_ZOOM_CTRL2 _at_ 0x8097;
xdata UCHAR volatile SC_OSD_HOR_ROW_ZOOM_CTRL3 _at_ 0x8098;
xdata UCHAR volatile SC_OSD_HOR_ROW_ZOOM_CTRL4 _at_ 0x8099;
xdata UCHAR volatile SC_OSD_VER_ROW_ZOOM_CTRL1 _at_ 0x809A;
xdata UCHAR volatile SC_OSD_VER_ROW_ZOOM_CTRL2 _at_ 0x809B;
xdata UCHAR volatile SC_OSD_VER_ROW_ZOOM_CTRL3 _at_ 0x809C;
xdata UCHAR volatile SC_OSD_VER_ROW_ZOOM_CTRL4 _at_ 0x809D;
xdata UCHAR volatile SC_OSD_FONT_ROW_ZOOM_RANGE _at_ 0x809E;
xdata UCHAR volatile SC_OSD_SEPARATE_ROW_CTRL _at_ 0x809F;
xdata UCHAR volatile SC_OSD_BLINK_CTRL _at_ 0x80A0;
xdata UCHAR volatile SC_OSD_TRANSLUCENT_CTL _at_ 0x80A1;
xdata UCHAR volatile SC_OSD_SPACE_CTL _at_ 0x80A2;
xdata UCHAR volatile SC_OSD_WIN_GRADIENT_CTRL1 _at_ 0x80A3;
xdata UCHAR volatile SC_OSD_WIN_GRADIENT_CTRL2 _at_ 0x80A4;
xdata UCHAR volatile SC_OSD_WIN_SEL _at_ 0x80A5;
xdata UCHAR volatile SC_OSD_WIN_ATTRIBUTE _at_ 0x80AA;
xdata UCHAR volatile SC_OSD_WIN_COLOR _at_ 0x80AB;
xdata UCHAR volatile SC_OSD_WIN_BEVEL_WIDTH _at_ 0x80AD;
xdata UCHAR volatile SC_OSD_WIN_BEVEL_COLOR_R _at_ 0x80AE;
xdata UCHAR volatile SC_OSD_WIN_BEVEL_COLOR_L _at_ 0x80AF;
xdata UCHAR volatile SC_OSD_SHADOW_CTRL_BYTE0 _at_ 0x80B0;
xdata UCHAR volatile SC_OSD_SHADOW_CTRL_BYTE1 _at_ 0x80B1;
xdata UCHAR volatile SC_OSD_SHADOW_CTRL_BYTE2 _at_ 0x80B2;
xdata UCHAR volatile SC_OSD_SHADOW_CTRL_BYTE3 _at_ 0x80B3;
xdata UCHAR volatile SC_OSD_BORDER_CTRL_BYTE0 _at_ 0x80B4;
xdata UCHAR volatile SC_OSD_BORDER_CTRL_BYTE1 _at_ 0x80B5;
xdata UCHAR volatile SC_OSD_BORDER_CTRL_BYTE2 _at_ 0x80B6;
xdata UCHAR volatile SC_OSD_BORDER_CTRL_BYTE3 _at_ 0x80B7;
xdata UCHAR volatile SC_OSD_BOR_SHA_COLOR_01 _at_ 0x80B8;
xdata UCHAR volatile SC_OSD_BOR_SHA_COL_23 _at_ 0x80B9;
xdata UCHAR volatile SC_OSD_BOR_SHA_COL_45 _at_ 0x80BA;
xdata UCHAR volatile SC_OSD_BOR_SHA_COL_67 _at_ 0x80BB;
xdata UCHAR volatile SC_OSD_BOR_SHA_COL_89 _at_ 0x80BC;
xdata UCHAR volatile SC_OSD_BOR_SHA_COL_1011 _at_ 0x80BD;
xdata UCHAR volatile SC_OSD_BOR_SHA_COL_1213 _at_ 0x80BE;
xdata UCHAR volatile SC_OSD_BOR_SHA_COL_1415 _at_ 0x80BF;
xdata UCHAR volatile SC_OSD_BOR_SHA_COL_1617 _at_ 0x80C0;
xdata UCHAR volatile SC_OSD_BOR_SHA_COL_1819 _at_ 0x80C1;
xdata UCHAR volatile SC_OSD_BOR_SHA_COL_2021 _at_ 0x80C2;
xdata UCHAR volatile SC_OSD_BOR_SHA_COL_2223 _at_ 0x80C3;
xdata UCHAR volatile SC_OSD_BOR_SHA_COL_2425 _at_ 0x80C4;
xdata UCHAR volatile SC_OSD_BOR_SHA_COL_2627 _at_ 0x80C5;
xdata UCHAR volatile SC_OSD_BOR_SHA_COL_2829 _at_ 0x80C6;
xdata UCHAR volatile SC_OSD_BOR_SHA_COL_3031 _at_ 0x80C7;
xdata UCHAR volatile SC_OSD_HOR_SPLIT_START_LO _at_ 0x80C8;
xdata UCHAR volatile SC_OSD_HOR_SPLIT_WIDTH_LO _at_ 0x80C9;
xdata UCHAR volatile SC_OSD_VER_SPLIT_START_LO _at_ 0x80CA;
xdata UCHAR volatile SC_OSD_VER_SPLIT_WIDTH_LO _at_ 0x80CB;
xdata UCHAR volatile SC_OSD_ATTRIBUTE_LO _at_ 0x80CC;
xdata UCHAR volatile SC_OSD_ATTRIBUTE_MI _at_ 0x80CD;
xdata UCHAR volatile SC_OSD_CODE_FC _at_ 0x80CE;
xdata UCHAR volatile SC_OSD_CODE_FC_CTL _at_ 0x80CF;
xdata UCHAR volatile SC_HPLL_CTRL1 _at_ 0x80D0;
xdata UCHAR volatile SC_HPLL_FREQ_CTRL _at_ 0x80D1;
xdata UCHAR volatile SC_HSDDS_RATIO_LO _at_ 0x80D2;
xdata UCHAR volatile SC_HSDDS_RATIO_MI _at_ 0x80D3;
xdata UCHAR volatile SC_HSDDS_RATIO_HI _at_ 0x80D4;
xdata UCHAR volatile SC_HPLL_PHASE_CTRL _at_ 0x80D5;
xdata UCHAR volatile SC_HPLL_CTRL2 _at_ 0x80D6;
xdata UCHAR volatile SC_HSDDS_DIVIDER_LO _at_ 0x80D7;
xdata UCHAR volatile SC_HSDDS_DIVIDER_HI _at_ 0x80D8;
xdata UCHAR volatile SC_HPLL_PHASE_CTRL1 _at_ 0x80D9;
xdata UCHAR volatile SC_HPLL_PHASE_CTRL2 _at_ 0x80DA;
xdata UCHAR volatile SC_HPLL_LINE_CNT _at_ 0x80DB;
xdata UCHAR volatile SC_HPLL_CTRL3 _at_ 0x80DC;
xdata UCHAR volatile SC_HS_CNT_RESULT_LO _at_ 0x80DD;
xdata UCHAR volatile SC_HS_CNT_RESULT_MI _at_ 0x80DE;
xdata UCHAR volatile SC_HS_CNT_RESULT_HI _at_ 0x80DF;
xdata UCHAR volatile SC_INDEX_CTRL _at_ 0x80E0;
xdata UCHAR volatile SC_INDEX_ADDR_LO _at_ 0x80E1;
xdata UCHAR volatile SC_INDEX_ADDR_HI _at_ 0x80E2;
xdata UCHAR volatile SC_INDEX_DATA _at_ 0x80E3;
xdata UCHAR volatile SC_AUTO_GAIN_WIN_ODD_VER_BEG_LO _at_ 0x80E6;
xdata UCHAR volatile SC_AUTO_GAIN_WIN_ODD_VER_BEG_HI _at_ 0x80E7;
xdata UCHAR volatile SC_AUTO_GAIN_WIN_EVEN_VER_BEG_LO _at_ 0x80E8;
xdata UCHAR volatile SC_AUTO_GAIN_WIN_EVEN_VER_BEG_HI _at_ 0x80E9;
xdata UCHAR volatile SC_AUTO_GAIN_WIN_VER_LEN_LO _at_ 0x80EA;
xdata UCHAR volatile SC_AUTO_GAIN_WIN_VER_LEN_HI _at_ 0x80EB;
xdata UCHAR volatile SC_AUTO_GAIN_WIN_HOR_BEG_LO _at_ 0x80EC;
xdata UCHAR volatile SC_AUTO_GAIN_WIN_HOR_BEG_HI _at_ 0x80ED;
xdata UCHAR volatile SC_AUTO_GAIN_WIN_HOR_WIDTH_LO _at_ 0x80EE;
xdata UCHAR volatile SC_AUTO_GAIN_WIN_HOR_WIDTH_HI _at_ 0x80EF;
xdata UCHAR volatile SC_DPLL_CTRL1 _at_ 0x80F0;
xdata UCHAR volatile SC_DPLL_FREQ_CTRL _at_ 0x80F1;
xdata UCHAR volatile SC_DDDS_RATIO_LO _at_ 0x80F2;
xdata UCHAR volatile SC_DDDS_RATIO_MI _at_ 0x80F3;
xdata UCHAR volatile SC_DDDS_RATIO_HI _at_ 0x80F4;
xdata UCHAR volatile SC_SSC_CTRL _at_ 0x80F5;
xdata UCHAR volatile SC_GAUGE_CTRL1 _at_ 0x80F7;
xdata UCHAR volatile SC_GAUGE_CTRL2 _at_ 0x80F8;
xdata UCHAR volatile SC_GAUGE_AREA_SEL _at_ 0x80F9;
xdata UCHAR volatile SC_GAUGE_OFFSET _at_ 0x80FA;
xdata UCHAR volatile SC_GAUGE_RESULT_LO _at_ 0x80FB;
xdata UCHAR volatile SC_GAUGE_RESULT_MI _at_ 0x80FC;
xdata UCHAR volatile SC_GAUGE_RESULT_HI _at_ 0x80FD;
xdata UCHAR volatile SC_RegPage _at_ 0x80FF;
xdata UCHAR volatile SC_PRODUCT_ID _at_ 0x8100;
xdata UCHAR volatile SC_POWER_CTRL1 _at_ 0x8101;
xdata UCHAR volatile SC_POWER_CTRL2 _at_ 0x8102;
xdata UCHAR volatile SC_POWER_CTRL3 _at_ 0x8103;
xdata UCHAR volatile SC_GI_AUTO_TUNE_CTRL _at_ 0x8106;
xdata UCHAR volatile SC_GI_POS_THR _at_ 0x8107;
xdata UCHAR volatile SC_GI_POS_VBEGO_LO _at_ 0x8108;
xdata UCHAR volatile SC_GI_POS_VBEGO_HI _at_ 0x8109;
xdata UCHAR volatile SC_GI_POS_VBEGE_LO _at_ 0x810A;
xdata UCHAR volatile SC_GI_POS_VBEGE_HI _at_ 0x810B;
xdata UCHAR volatile SC_GI_POS_VLEN_LO _at_ 0x810C;
xdata UCHAR volatile SC_GI_POS_VLEN_HI _at_ 0x810D;
xdata UCHAR volatile SC_GI_POS_HBEG_LO _at_ 0x810E;
xdata UCHAR volatile SC_GI_POS_HBEG_HI _at_ 0x810F;
xdata UCHAR volatile SC_GI_POS_HWID_LO _at_ 0x8110;
xdata UCHAR volatile SC_GI_POS_HWID_HI _at_ 0x8111;
xdata UCHAR volatile SC_GI_PHS_MASK _at_ 0x8112;
xdata UCHAR volatile SC_GI_PHS_SDIFF_LO0 _at_ 0x8113;
xdata UCHAR volatile SC_GI_PHS_SDIFF_LO1 _at_ 0x8114;
xdata UCHAR volatile SC_GI_PHS_SDIFF_HI0 _at_ 0x8115;
xdata UCHAR volatile SC_GI_PHS_SDIFF_HI1 _at_ 0x8116;
xdata UCHAR volatile SC_GI_CLK_REF_LO _at_ 0x8117;
xdata UCHAR volatile SC_GI_CLK_REF_HI _at_ 0x8118;
xdata UCHAR volatile SC_GI_CLK_RESULT _at_ 0x8119;
xdata UCHAR volatile SC_VI_AUTO_CTRL _at_ 0x811B;
xdata UCHAR volatile SC_AUTO_OFFSET_ATART_LO _at_ 0x811E;
xdata UCHAR volatile SC_AUTO_OFFSET_ATART_HI _at_ 0x811F;
xdata UCHAR volatile SC_REDUCE_ADC_PWR_CTRL _at_ 0x8120;
xdata UCHAR volatile SC_CAPTURE_CLK_MASK_WIN_BEG_LO _at_ 0x8121;
xdata UCHAR volatile SC_CAPTURE_CLK_MASK_WIN_BEG_HI _at_ 0x8122;
xdata UCHAR volatile SC_CAPTURE_CLK_MASK_WIN_END_LO _at_ 0x8123;
xdata UCHAR volatile SC_CAPTURE_CLK_MASK_WIN_END_HI _at_ 0x8124;
xdata UCHAR volatile SC_ADC_BLANK_PWR_DOWN_BEG_LO _at_ 0x8125;
xdata UCHAR volatile SC_ADC_BLANK_PWR_DOWN_BEG_HI _at_ 0x8126;
xdata UCHAR volatile SC_ADC_BLANK_PWR_DOWN_END_LO _at_ 0x8127;
xdata UCHAR volatile SC_ADC_BLANK_PWR_DOWN_END_HI _at_ 0x8128;
xdata UCHAR volatile SC_BRIGHT_FRM_CTRL _at_ 0x8130;
xdata UCHAR volatile SC_BRIGHT_FRM_SEL _at_ 0x8131;
xdata UCHAR volatile SC_BRIGHT_FRM_HS_LO _at_ 0x8132;
xdata UCHAR volatile SC_BRIGHT_FRM_HS_HI _at_ 0x8133;
xdata UCHAR volatile SC_BRIGHT_FRM_HW_LO _at_ 0x8134;
xdata UCHAR volatile SC_BRIGHT_FRM_HW_HI _at_ 0x8135;
xdata UCHAR volatile SC_BRIGHT_FRM_VS_LO _at_ 0x8136;
xdata UCHAR volatile SC_BRIGHT_FRM_VS_HI _at_ 0x8137;
xdata UCHAR volatile SC_BRIGHT_FRM_VH_LO _at_ 0x8138;
xdata UCHAR volatile SC_BRIGHT_FRM_VH_HI _at_ 0x8139;
xdata UCHAR volatile SC_BRIGHT_FRM_GAIN _at_ 0x813A;
xdata UCHAR volatile SC_BRIGHT_FRM_OFFSET _at_ 0x813B;
xdata UCHAR volatile SC_POST_PATTERN_GRAY_LEVEL_HI _at_ 0x814A;
xdata UCHAR volatile SC_POST_PATTERN_GRAY_LEVEL_LO _at_ 0x814B;
xdata UCHAR volatile SC_CAP_HTOTAL_LENGTH_LO _at_ 0x814C;
xdata UCHAR volatile SC_CAP_HTOTAL_LENGTH_HI _at_ 0x814D;
xdata UCHAR volatile SC_LOCK_H_SHIFT_LO _at_ 0x814E;
xdata UCHAR volatile SC_LOCK_H_SHIFT_HI _at_ 0x814F;
xdata UCHAR volatile SC_DISPLAY_CTRL _at_ 0x8150;
xdata UCHAR volatile SC_DISPLAY_VLOCK _at_ 0x8151;
xdata UCHAR volatile SC_DISPLAY_HLOCK_LO _at_ 0x8152;
xdata UCHAR volatile SC_DISPLAY_HLOCK_HI _at_ 0x8153;
xdata UCHAR volatile SC_DISPLAY_MUTE_CTRL _at_ 0x8154;
xdata UCHAR volatile SC_DISP_DRIVE_CTRL _at_ 0x8155;
xdata UCHAR volatile SC_DISPLAY_POL_CTRL _at_ 0x8156;
xdata UCHAR volatile SC_DISPLAY_CLK_CTRL _at_ 0x8157;
xdata UCHAR volatile SC_DITH_CTRL _at_ 0x8158;
xdata UCHAR volatile SC_DISPLAY_CHANNEL _at_ 0x8159;
xdata UCHAR volatile SC_CBAR_FG _at_ 0x815A;
xdata UCHAR volatile SC_DV_TOTAL_LO _at_ 0x815B;
xdata UCHAR volatile SC_DV_TOTAL_HI _at_ 0x815C;
xdata UCHAR volatile SC_DV_VS_WID _at_ 0x815D;
xdata UCHAR volatile SC_DH_HTOTAL_LO _at_ 0x815E;
xdata UCHAR volatile SC_DH_HTOTAL_HI _at_ 0x815F;
xdata UCHAR volatile SC_DH_HS_WID _at_ 0x8160;
xdata UCHAR volatile SC_DISPLAY_BR_CTRL _at_ 0x8161;
xdata UCHAR volatile SC_DV_BG_BEG_LO _at_ 0x8162;
xdata UCHAR volatile SC_DV_BG_BEG_HI _at_ 0x8163;
xdata UCHAR volatile SC_DV_BG_LEN_LO _at_ 0x8164;
xdata UCHAR volatile SC_DV_BG_LEN_HI _at_ 0x8165;
xdata UCHAR volatile SC_DH_BG_BEG_LO _at_ 0x8166;
xdata UCHAR volatile SC_DH_BG_BEG_HI _at_ 0x8167;
xdata UCHAR volatile SC_DH_BG_WID_LO _at_ 0x8168;
xdata UCHAR volatile SC_DH_BG_WID_HI _at_ 0x8169;
xdata UCHAR volatile SC_DISP_SWAP _at_ 0x816A;
xdata UCHAR volatile SC_DISP_BACKGROUND_RED _at_ 0x816B;
xdata UCHAR volatile SC_DISP_BACKGROUND_GREEN _at_ 0x816C;
xdata UCHAR volatile SC_DISP_BACKGROUND_BLUE _at_ 0x816D;
xdata UCHAR volatile SC_GRAPHIC_DISP_WIN_CTRL _at_ 0x816E;
xdata UCHAR volatile SC_GRAPHIC_DISP_VER_ACT_BEG_LO _at_ 0x816F;
xdata UCHAR volatile SC_GRAPHIC_DISP_VER_ACT_BEG_HI _at_ 0x8170;
xdata UCHAR volatile SC_GRAPHIC_DISP_VER_ACT_LEN_LO _at_ 0x8171;
xdata UCHAR volatile SC_GRAPHIC_DISP_VER_ACT_LEN_HI _at_ 0x8172;
xdata UCHAR volatile SC_GRAPHIC_DISP_HOR_ACT_BEG_LO _at_ 0x8173;
xdata UCHAR volatile SC_GRAPHIC_DISP_HOR_ACT_BEG_HI _at_ 0x8174;
xdata UCHAR volatile SC_GRAPHIC_DISP_HOR_ACT_WID_LO _at_ 0x8175;
xdata UCHAR volatile SC_GRAPHIC_DISP_HOR_ACT_WID_HI _at_ 0x8176;
xdata UCHAR volatile SC_DISP_HLOCK_POS_R _at_ 0x8177;
xdata UCHAR volatile SC_DISP_VLOCK_POS_R _at_ 0x8178;
xdata UCHAR volatile SC_FREE_RUN_HTOTAL_LO _at_ 0x8179;
xdata UCHAR volatile SC_FREE_RUN_HTOTAL_HI _at_ 0x817A;
xdata UCHAR volatile SC_DSP_HTOTAL_LO _at_ 0x8182;
xdata UCHAR volatile SC_DSP_HTOTAL_HI _at_ 0x8183;
xdata UCHAR volatile SC_HR_VALUE_LO _at_ 0x8184;
xdata UCHAR volatile SC_HR_VALUE_HI _at_ 0x8185;
xdata UCHAR volatile SC_HR_CTRL _at_ 0x8186;
xdata UCHAR volatile SC_DISP_SYNC_STATUS _at_ 0x8187;
xdata UCHAR volatile SC_VCR_CTRL _at_ 0x8188;
xdata UCHAR volatile SC_VER_COUNTER_LO _at_ 0x8189;
xdata UCHAR volatile SC_VER_COUNTER_MI _at_ 0x818A;
xdata UCHAR volatile SC_VER_COUNTER_HI _at_ 0x818B;
xdata UCHAR volatile SC_RESIDUAL_DISP_HOR_SYNC_CTRL _at_ 0x818D;
xdata UCHAR volatile SC_FIFO_FLAG _at_ 0x818E;
xdata UCHAR volatile SC_FIFO_FLAG_EN _at_ 0x818F;
xdata UCHAR volatile SC_FIFO_CTRL1 _at_ 0x8190;
xdata UCHAR volatile SC_FIFO_CTRL2 _at_ 0x8191;
xdata UCHAR volatile SC_GI_SYNC_CTRL _at_ 0x8196;
xdata UCHAR volatile SC_GI_SYNC_CTRL2 _at_ 0x8197;
xdata UCHAR volatile SC_GI_FIELD_WIN _at_ 0x8198;
xdata UCHAR volatile SC_GI_SYNC_CTRL3 _at_ 0x8199;
xdata UCHAR volatile SC_GI_SYNC_STATUS _at_ 0x819A;
xdata UCHAR volatile SC_GI_HCNT_LO _at_ 0x819B;
xdata UCHAR volatile SC_GI_HCNT_HI _at_ 0x819C;
xdata UCHAR volatile SC_GI_VCNT_LO _at_ 0x819D;
xdata UCHAR volatile SC_GI_VCNT_HI _at_ 0x819E;
xdata UCHAR volatile SC_HREE_DIV_LO _at_ 0x819F;
xdata UCHAR volatile SC_HREE_DIV_HI _at_ 0x81A0;
xdata UCHAR volatile SC_VREE_DIV_LO _at_ 0x81A1;
xdata UCHAR volatile SC_VREE_DIV_HI _at_ 0x81A2;
xdata UCHAR volatile SC_HPRE_THR_LO _at_ 0x81A3;
xdata UCHAR volatile SC_HPRE_THR_HI _at_ 0x81A4;
xdata UCHAR volatile SC_VPRE_THR_LO _at_ 0x81A5;
xdata UCHAR volatile SC_VPRE_THR_HI _at_ 0x81A6;
xdata UCHAR volatile SC_HCNT_THR _at_ 0x81A7;
xdata UCHAR volatile SC_V_CHANG_CTRL _at_ 0x81A8;
xdata UCHAR volatile SC_SYNC_INT_EN1 _at_ 0x81A9;
xdata UCHAR volatile SC_SYNC_INT_EN2 _at_ 0x81AA;
xdata UCHAR volatile SC_SYNC_INT_FLAG1 _at_ 0x81AB;
xdata UCHAR volatile SC_SYNC_INT_FLAG2 _at_ 0x81AC;
xdata UCHAR volatile SC_DVI_STATUS _at_ 0x81AD;
xdata UCHAR volatile SC_MACROVISION_THRESHOLD _at_ 0x81AE;
xdata UCHAR volatile SC_FAST_MUTE_CTRL _at_ 0x81AF;
xdata UCHAR volatile SC_FIELD_POLARITY_CTRL _at_ 0x81B0;
xdata UCHAR volatile SC_GI_HS_WID _at_ 0x81B1;
xdata UCHAR volatile SC_GI_VS_WID _at_ 0x81B2;
xdata UCHAR volatile SC_PRE_COAST _at_ 0x81B3;
xdata UCHAR volatile SC_POS_COAST _at_ 0x81B4;
xdata UCHAR volatile SC_GRAPHIC_VTOTAL_COUNTER_LO _at_ 0x81B5;
xdata UCHAR volatile SC_GRAPHIC_VTOTAL_COUNTER_HI _at_ 0x81B6;
xdata UCHAR volatile SC_LVDS_CTRL _at_ 0x81B8;
xdata UCHAR volatile SC_DISP_INTERFACE_CTRL _at_ 0x81B9;
xdata UCHAR volatile SC_AUTO_OFFSET_CTRL1 _at_ 0x81BA;
xdata UCHAR volatile SC_AUTO_OFFSET_CTRL2 _at_ 0x81BB;
xdata UCHAR volatile SC_AUTO_OFFSET_CTRL3 _at_ 0x81BC;
xdata UCHAR volatile SC_AUTO_OFFSET_TARGET_RED _at_ 0x81BD;
xdata UCHAR volatile SC_AUTO_OFFSET_TARGET_GREEN _at_ 0x81BE;
xdata UCHAR volatile SC_AUTO_OFFSET_TARGET_BLUE _at_ 0x81BF;
xdata UCHAR volatile SC_AUTO_OFFSET_ADJUST_RED _at_ 0x81C0;
xdata UCHAR volatile SC_AUTO_OFFSET_ADJUST_GREEN _at_ 0x81C1;
xdata UCHAR volatile SC_AUTO_OFFSET_ADJUST_BLUE _at_ 0x81C2;
xdata UCHAR volatile SC_AUTO_OFFSET_MID_RED _at_ 0x81C3;
xdata UCHAR volatile SC_AUTO_OFFSET_MID_GREEN _at_ 0x81C4;
xdata UCHAR volatile SC_AUTO_OFFSET_MID_BLUE _at_ 0x81C5;
xdata UCHAR volatile SC_INSIDE_CTRL3 _at_ 0x81C6;
xdata UCHAR volatile SC_DATA_TRACK_CTRL _at_ 0x81C7;
xdata UCHAR volatile SC_DATA_TRACK_MASK1 _at_ 0x81C8;
xdata UCHAR volatile SC_DATA_TRACK_MASK2 _at_ 0x81C9;
xdata UCHAR volatile SC_DATA_TRACK_MASK3 _at_ 0x81CA;
xdata UCHAR volatile SC_DATA_TRACK_MASK4 _at_ 0x81CB;
xdata UCHAR volatile SC_ASYNC_RANDOM_DITHRER_CTRL _at_ 0x81CC;
xdata UCHAR volatile SC_AUTO_OFFSET_CTRL4 _at_ 0x81CD;
xdata UCHAR volatile SC_AUTO_OFFSET_HCNT_MODE01 _at_ 0x81CE;
xdata UCHAR volatile SC_AUTO_OFFSET_HCNT_MODE11 _at_ 0x81CF;
xdata UCHAR volatile SC_SRGB_CTRL _at_ 0x81D0;
xdata UCHAR volatile SC_SRGB_COEF_R_LO _at_ 0x81D1;
xdata UCHAR volatile SC_SRGB_COEF_R_HI _at_ 0x81D2;
xdata UCHAR volatile SC_SRGB_COEF_G_LO _at_ 0x81D3;
xdata UCHAR volatile SC_SRGB_COEF_G_HI _at_ 0x81D4;
xdata UCHAR volatile SC_SRGB_COEF_B_LO _at_ 0x81D5;
xdata UCHAR volatile SC_SRGB_COEF_B_HI _at_ 0x81D6;
xdata UCHAR volatile SC_SRGB_COEF_OFFSET _at_ 0x81D7;
xdata UCHAR volatile SC_SRGB_DITH_CTRL _at_ 0x81D8;
xdata UCHAR volatile SC_DISP_DITH_CTRL _at_ 0x81D9;
xdata UCHAR volatile SC_DISP_RANDOM_DITH_CTRL _at_ 0x81DA;
xdata UCHAR volatile SC_GAMMA_DITH_CTRL _at_ 0x81DB;
xdata UCHAR volatile SC_MISC_O_RD_LO _at_ 0x81DC;
xdata UCHAR volatile SC_MISC_O_RD_HI _at_ 0x81DD;
xdata UCHAR volatile SC_MISC_E_RD_LO _at_ 0x81DE;
xdata UCHAR volatile SC_MISC_E_RD_HI _at_ 0x81DF;
xdata UCHAR volatile SC_INV_GR _at_ 0x81E0;
xdata UCHAR volatile SC_INV_BR _at_ 0x81E1;
xdata UCHAR volatile SC_TEST_MODE1_LOCKER _at_ 0x81E2;
xdata UCHAR volatile SC_TEST_MODE1 _at_ 0x81E3;
xdata UCHAR volatile SC_TEST_MODE2 _at_ 0x81E4;
xdata UCHAR volatile SC_TEST_MODE3 _at_ 0x81E5;
xdata UCHAR volatile SC_ADC_TEST_MODE _at_ 0x81E6;
xdata UCHAR volatile SC_TMDS_LINK_CLK_SEL _at_ 0x81E7;
xdata UCHAR volatile SC_BIST_CTRL1 _at_ 0x81E8;
xdata UCHAR volatile SC_BIST_CTRL2 _at_ 0x81E9;
xdata UCHAR volatile SC_ADC_REG_1D _at_ 0x81EA;
xdata UCHAR volatile SC_ADC_COMP_CTRL _at_ 0x81EB;
xdata UCHAR volatile SC_ADC_BAND_GAP _at_ 0x81ED;
xdata UCHAR volatile SC_BYPASS_CTRL _at_ 0x81EE;
xdata UCHAR volatile SC_LVDS_RSDS_SWITCH _at_ 0x81EF;
xdata UCHAR volatile SC_ADC_OP_CURRENT _at_ 0x81F1;
xdata UCHAR volatile SC_ADC_TEST2_CTRL _at_ 0x81F3;
#if IS_NT68650_SERIES || IS_NT68660_SERIES
xdata UCHAR volatile SC_LVDS_PLL_LDO_CTRL _at_ 0x81F4;
#endif
xdata UCHAR volatile SC_LVDS_MISC_CTRL1 _at_ 0x81F5;
xdata UCHAR volatile SC_LVDS_MISC_CTRL2 _at_ 0x81F6;
xdata UCHAR volatile SC_LVDS_MISC_CTRL3 _at_ 0x81F7;
xdata UCHAR volatile SC_LVDS_MISC_CTRL4 _at_ 0x81F8;
xdata UCHAR volatile SC_LVDS_MISC_CTRL5 _at_ 0x81F9;
xdata UCHAR volatile SC_LVDS_MISC_CTRL6 _at_ 0x81FA;
xdata UCHAR volatile SC_LVDS_DATA_DELAY _at_ 0x81FB;
xdata UCHAR volatile SC_LVDS_CLOCK_DELAY _at_ 0x81FC;
xdata UCHAR volatile SC_LVDS_P2S_CTRL _at_ 0x81FD;

xdata UCHAR volatile SC_DVI_CTRL_300 _at_ 0x8300;
xdata UCHAR volatile SC_DVI_CTRL_301 _at_ 0x8301;
xdata UCHAR volatile SC_DVI_RB_SWAP _at_ 0x8302;
xdata UCHAR volatile SC_DVI_CTRL_303 _at_ 0x8303;
xdata UCHAR volatile SC_DVI_PIXELCLK_LO _at_ 0x8304;
xdata UCHAR volatile SC_DVI_PIXELCLK_HI _at_ 0x8305;
xdata UCHAR volatile SC_DVI_CTRL_306 _at_ 0x8306;
xdata UCHAR volatile SC_DVI_CTRL_308 _at_ 0x8308;
xdata UCHAR volatile SC_DVI_CTRL_309 _at_ 0x8309;
xdata UCHAR volatile SC_DVI_CTRL_310 _at_ 0x8310;
xdata UCHAR volatile SC_DVI_CTRL_311 _at_ 0x8311;
xdata UCHAR volatile SC_DVI_CTRL_317 _at_ 0x8317;
xdata UCHAR volatile SC_DVI_CTRL_330 _at_ 0x8330;
xdata UCHAR volatile SC_DVI_CTRL_331 _at_ 0x8331;
xdata UCHAR volatile SC_DVI_CTRL_332 _at_ 0x8332;
xdata UCHAR volatile SC_DVI_CTRL_333 _at_ 0x8333;
xdata UCHAR volatile SC_DVI_CTRL_334 _at_ 0x8334;
xdata UCHAR volatile SC_DVI_CTRL_335 _at_ 0x8335;
xdata UCHAR volatile SC_DVI_CTRL_336 _at_ 0x8336;
xdata UCHAR volatile SC_DVI_CTRL_337 _at_ 0x8337;
xdata UCHAR volatile SC_DVI_CTRL_338 _at_ 0x8338;
xdata UCHAR volatile SC_DVI_CTRL_339 _at_ 0x8339;
xdata UCHAR volatile SC_DVI_CTRL_33A _at_ 0x833A;
xdata UCHAR volatile SC_DITHER_TOGGLE_CTRL _at_ 0x8371;
xdata UCHAR volatile SC_DITHER_TP_GRAY_LVL_LO _at_ 0x8378;
xdata UCHAR volatile SC_DITHER_TP_GRAY_LVL_HI _at_ 0x8379;
xdata UCHAR volatile SC_NEW_HSYNC_CTRL1 _at_ 0x837A;
xdata UCHAR volatile SC_BF_WIN_BORDER_CTRL _at_ 0x8390;
xdata UCHAR volatile SC_BF_WIN_BORDER_RED _at_ 0x8391;
xdata UCHAR volatile SC_BF_WIN_BORDER_GREEN _at_ 0x8392;
xdata UCHAR volatile SC_BF_WIN_BORDER_BLUE _at_ 0x8393;
xdata UCHAR volatile SC_BF_WIN_BORDER_EN _at_ 0x8394;
xdata UCHAR volatile SC_YC_PEAKING_CTRL _at_ 0x83A0;
xdata UCHAR volatile SC_LUMA_PEAKING_CTRL _at_ 0x83A1;
xdata UCHAR volatile SC_CHROMA_PEAKING_CTRL _at_ 0x83A2;
xdata UCHAR volatile SC_LUMA_NOISE_THRESHOLD _at_ 0x83A3;
xdata UCHAR volatile SC_TEXT_PEAKING_CTRL _at_ 0x83A4;
xdata UCHAR volatile SC_UNDER_SHOOT_CLAMP_EN _at_ 0x83A5;
xdata UCHAR volatile SC_ACE_FUNC_CTRL1 _at_ 0x83B0;
xdata UCHAR volatile SC_ACE_FUNC_CTRL2 _at_ 0x83B1;
xdata UCHAR volatile SC_ACE_DATA_PORT _at_ 0x83B2;
xdata UCHAR volatile SC_CM_COLOR_CTRL _at_ 0x83C0;
xdata UCHAR volatile SC_CM_BRIGHTNESS_RED _at_ 0x83C1;
xdata UCHAR volatile SC_CM_BRIGHTNESS_GREEN _at_ 0x83C2;
xdata UCHAR volatile SC_CM_BRIGHTNESS_BLUE _at_ 0x83C3;
xdata UCHAR volatile SC_CM_CONTRAST_RED _at_ 0x83C4;
xdata UCHAR volatile SC_CM_CONTRAST_GREEN _at_ 0x83C5;
xdata UCHAR volatile SC_CM_CONTRAST_BLUE _at_ 0x83C6;
xdata UCHAR volatile SC_CM_HUE _at_ 0x83C7;
xdata UCHAR volatile SC_CM_SATURATION _at_ 0x83C8;
xdata UCHAR volatile SC_CM_INTENSITY _at_ 0x83C9;
xdata UCHAR volatile SC_CM_COLOR_ENHANCEMENT_CTRL _at_ 0x83CC;
xdata UCHAR volatile SC_CM_INDEX_ACCESS_CTRL _at_ 0x83CD;
xdata UCHAR volatile SC_CM_INDEX_ACCESS_ADDR _at_ 0x83CE;
xdata UCHAR volatile SC_CM_INDEX_ACCESS_PORT _at_ 0x83CF;
/* Dymanic Backlight Control */
xdata UCHAR volatile SC_DBC_CTRL _at_ 0x8430;
xdata UCHAR volatile SC_DBC_ADJ _at_ 0x8431;
xdata UCHAR volatile SC_DBC_PWM_MIN _at_ 0x8432;
xdata UCHAR volatile SC_DBC_PWM_DIV1 _at_ 0x8433;
xdata UCHAR volatile SC_DBC_PWM_DIV2 _at_ 0x8434;
xdata UCHAR volatile SC_DBC_PWM_DUTY _at_ 0x8435;
xdata UCHAR volatile SC_DBC_PWM_CTRL _at_ 0x8436;
xdata UCHAR volatile SC_DBC_PWM_OFFSET _at_ 0x8437;
xdata UCHAR volatile SC_DBC_AVG_Y _at_ 0x8438;
xdata UCHAR volatile SC_EFFECTIVE_COLOR_VALUE _at_ 0x8439;
xdata UCHAR volatile SC_DBC_PWM_ACT _at_ 0x843B;
xdata UCHAR volatile SC_DBC_POSITION _at_ 0x843D;
xdata UCHAR volatile SC_DBC_INDEX_PORT _at_ 0x843E;
xdata UCHAR volatile SC_DBC_INDEX_DATA _at_ 0x843F;

#if IS_NT68650_SERIES || IS_NT68660_SERIES
xdata UCHAR volatile SC_DBC_AVERAGE_MODE _at_ 0x8441;
xdata UCHAR volatile SC_DBC_DEBOUNCINT_MODE _at_ 0x8442;
xdata UCHAR volatile SC_PWMA_CTRL1 _at_ 0x8448;
xdata UCHAR volatile SC_PWMA_CTRL2 _at_ 0x8449;
xdata UCHAR volatile SC_PWMA_CTRL3 _at_ 0x844A;
xdata UCHAR volatile SC_PWMA_CTRL4 _at_ 0x844B;
xdata UCHAR volatile SC_PWMA_CTRL5 _at_ 0x844C;
xdata UCHAR volatile SC_PWMA_CTRL6 _at_ 0x844D;
xdata UCHAR volatile SC_PWMB_CTRL1 _at_ 0x844E;
xdata UCHAR volatile SC_PWMB_CTRL2 _at_ 0x844F;
xdata UCHAR volatile SC_PWMB_CTRL3 _at_ 0x8450;
xdata UCHAR volatile SC_PWMB_CTRL4 _at_ 0x8451;
xdata UCHAR volatile SC_PWMB_CTRL5 _at_ 0x8452;
xdata UCHAR volatile SC_PWMB_CTRL6 _at_ 0x8453;
xdata UCHAR volatile SC_PWMC_CTRL1 _at_ 0x8454;
xdata UCHAR volatile SC_PWMC_CTRL2 _at_ 0x8455;
xdata UCHAR volatile SC_PWMC_CTRL3 _at_ 0x8456;
xdata UCHAR volatile SC_PWMC_CTRL4 _at_ 0x8457;
xdata UCHAR volatile SC_PWMC_CTRL5 _at_ 0x8458;
xdata UCHAR volatile SC_PWMC_CTRL6 _at_ 0x8459;
xdata UCHAR volatile SC_PWMD_CTRL1 _at_ 0x845A;
xdata UCHAR volatile SC_PWMD_CTRL2 _at_ 0x845B;
xdata UCHAR volatile SC_PWMD_CTRL3 _at_ 0x845C;
xdata UCHAR volatile SC_PWMD_CTRL4 _at_ 0x845D;
xdata UCHAR volatile SC_PWMD_CTRL5 _at_ 0x845E;
xdata UCHAR volatile SC_PWMD_CTRL6 _at_ 0x845F;
#endif

#if IS_NT68669_SERIES
/* OD *///////////////////////////////////////
xdata UCHAR volatile SC_OD_CONFIGURATION _at_ 0x8480;
xdata UCHAR volatile SC_OD_BTC_CONFIGURATION _at_ 0x8490;
xdata UCHAR volatile SC_OD_STILL_CONFIGURATION _at_ 0x8498;
xdata UCHAR volatile SC_OD_STILL_THRESHOLD _at_ 0x8499;
xdata UCHAR volatile SC_OD_DCC_THRESHOLD _at_ 0x849A;
xdata UCHAR volatile SC_OD_MOTION_CHECK_CFGCONFIGURATION _at_ 0x849B;
xdata UCHAR volatile SC_OD_MOTION_AVG_THRESHOLD _at_ 0x849C;
xdata UCHAR volatile SC_OD_MOTION_VALUE_THRESHOLD _at_ 0x89D;
xdata UCHAR volatile SC_OD_DDC_CONFIGURATION _at_ 0x84A0;
xdata UCHAR volatile SC_OD_TEST_CONFIGURATION _at_ 0x84B0;
xdata UCHAR volatile SC_OD_TEST_TP_H_MT_STEP _at_ 0x84B8;
xdata UCHAR volatile SC_OD_TEST_TP_V_MT_STEP _at_ 0x84B9;
xdata UCHAR volatile SC_OD_MOTION_LOW_THRESHOLD_LO _at_ 0x84C0;
xdata UCHAR volatile SC_OD_MOTION_LOW_THRESHOLD_MI _at_ 0x84C1;
xdata UCHAR volatile SC_OD_MOTION_LOW_THRESHOLD_HI _at_ 0x84C2;
xdata UCHAR volatile SC_OD_MOTION_HIGH_THRESHOLD_LO _at_ 0x84C3;
xdata UCHAR volatile SC_OD_MOTION_HIGH_THRESHOLD_MI _at_ 0x84C4;
xdata UCHAR volatile SC_OD_MOTION_HIGH_THRESHOLD_HI _at_ 0x84C5;

xdata UCHAR volatile SC_FRAME_BUFFER_BASE_ADDR_OD_LO _at_ 0x8514;
xdata UCHAR volatile SC_FRAME_BUFFER_BASE_ADDR_OD_MI _at_ 0x8515;
xdata UCHAR volatile SC_FRAME_BUFFER_BASE_ADDR_OD_HI _at_ 0x8516;

xdata UCHAR volatile SC_DRAM_INTERFACE_LO _at_ 0x8580;
xdata UCHAR volatile SC_DRAM_INTERFACE_HI _at_ 0x8581;
xdata UCHAR volatile SC_DRAM_MMU_MODE _at_ 0x8582;
xdata UCHAR volatile SC_DRAM_MMU_REQUEST_W _at_ 0x8586;
xdata UCHAR volatile SC_DRAM_MMU_REQUEST_R _at_ 0x8587;
xdata UCHAR volatile SC_DDR_PAD_CTRL1 _at_ 0x8588;
xdata UCHAR volatile SC_DDR_PAD_CTRL2 _at_ 0x8589;
xdata UCHAR volatile SC_MMU_CFG2 _at_ 0x858A;

xdata UCHAR volatile SC_OD_WRITE_FIFO_ADDR_HI _at_ 0x85A6;
xdata UCHAR volatile SC_OD_WRITE_FIFO_ADDR_START _at_ 0x85A7;
xdata UCHAR volatile SC_OD_WRITE_FIFO_ADDR_END _at_ 0x85A8;
xdata UCHAR volatile SC_OD_READ_FIFO_ADDR_HI _at_ 0x85BF;
xdata UCHAR volatile SC_OD_READ_FIFO_ADDR_START _at_ 0x85C0;
xdata UCHAR volatile SC_OD_READ_FIFO_ADDR_END _at_ 0x85C1;

xdata UCHAR volatile SC_DRAM_CLOCK_CTRL[8] _at_ 0x85F0;
#endif

/* HDCP *///////////////////////////////////////
xdata UCHAR volatile SC_HDCP_BKSV _at_ 0x861A;
xdata UCHAR volatile SC_HDCP_STATUS _at_ 0x8632;
xdata UCHAR volatile SC_VIDEO_HTOTAL_LO _at_ 0x863A;
xdata UCHAR volatile SC_VIDEO_HTOTAL_HI _at_ 0x863B;
xdata UCHAR volatile SC_VIDEO_VTOTAL_LO _at_ 0x863C;
xdata UCHAR volatile SC_VIDEO_VTOTAL_HI _at_ 0x863D;
xdata UCHAR volatile SC_HDCP_SLAVE_ADDR _at_ 0x863F;
xdata UCHAR volatile SC_HDCP_SYNC_SELECT _at_ 0x8640;
xdata UCHAR volatile SC_HDCP_INPUT_CTRL _at_ 0x8641;
xdata UCHAR volatile SC_HDCP_PACKING _at_ 0x8645;
#if IS_NT68168_SERIES || IS_NT68668_SERIES
/*OSD 2 *//////////////////////////////////////////////
xdata UCHAR volatile SC_OSD_WIN_HOR_START_LO _at_ 0x8703;
xdata UCHAR volatile SC_OSD_WIN_HOR_END_LO _at_ 0x8704;
xdata UCHAR volatile SC_OSD_WIN_HOR_HI _at_ 0x8705;
xdata UCHAR volatile SC_OSD_WIN_VER_START_LO _at_ 0x8706;
xdata UCHAR volatile SC_OSD_WIN_VER_END_LO _at_ 0x8707;
xdata UCHAR volatile SC_OSD_WIN_VER_HI _at_ 0x8708;
#endif

#if IS_NT68668_SERIES || IS_NT68669_SERIES
xdata UCHAR volatile SC_HDCP_CTRL _at_ 0x8736;
#endif

#if IS_NT68669_SERIES
/*MPLL*////////////////////////////////////////
xdata UCHAR volatile SC_MCLK_RATIO_LO _at_ 0x8B31;
xdata UCHAR volatile SC_MCLK_RATIO_MI _at_ 0x8B32;
xdata UCHAR volatile SC_MCLK_RATIO_HI _at_ 0x8B33;
xdata UCHAR volatile SC_MCLK_SSC_CTRL _at_ 0x8B34;
#endif

xdata UCHAR volatile SC_MCU_PLL _at_ 0x8B04;
xdata UCHAR volatile SC_MPLL_OUT_CTRL _at_ 0x8B09;
xdata UCHAR volatile SC_MPLL_DIV _at_ 0x8B40;
xdata UCHAR volatile SC_MPLL_CTRL_B41 _at_ 0x8B41;
xdata UCHAR volatile SC_MPLL_CTRL_B42 _at_ 0x8B42;
xdata UCHAR volatile SC_MPLL_LDO_VADJ _at_ 0x8B43;
xdata UCHAR volatile SC_MPLL_X2 _at_ 0x8B46;
#if IS_NT68669_SERIES || IS_NT68660_SERIES || IS_NT68650_SERIES
xdata UCHAR volatile SC_MCU_CLK_DIVIDER _at_ 0x8B54;
xdata UCHAR volatile SC_ZERO_POWER_LDO18 _at_ 0x8B55;
xdata UCHAR volatile SC_OSC_LDO18 _at_ 0x8B56;
xdata UCHAR volatile SC_ADC_ZERO_POWER_CTRL _at_ 0x8B57;
xdata UCHAR volatile SC_DVI_ZERO_POWER_CTRL _at_ 0x8B58;
xdata UCHAR volatile SC_DVI_ZERO_POWER_DETECT _at_ 0x8B59;
xdata UCHAR volatile SC_APR_LDO_CTRL _at_ 0x8B5A;
#if IS_NT68650_SERIES || IS_NT68660_SERIES
xdata UCHAR volatile SC_ADC_LDO_CTRL _at_ 0x8B5D;
#endif
/*MMU DLL*////////////////////////////////////////
xdata UCHAR volatile SC_MMU_DLL_CTRL _at_ 0x8B80;
xdata UCHAR volatile SC_MMU_DLL_PHASE_CTRL0 _at_ 0x8B86;
xdata UCHAR volatile SC_MMU_DLL_PHASE_CTRL1 _at_ 0x8B87;
xdata UCHAR volatile SC_MMU_DLL_PHASE_CTRL2 _at_ 0x8B88;
xdata UCHAR volatile SC_MMU_DLL_PHASE_CTRL3 _at_ 0x8B89;

#if NT68660_SERIES || NT68650_SERIES
xdata UCHAR volatile SC_MCU_CLK_SSC _at_ 0x8b49;
#endif

/*MCU IO*////////////////////////////////////////
xdata UCHAR volatile SC_MCU_IO_CTRL _at_ 0x8C80;
#if IS_NT68650_SERIES || IS_NT68660_SERIES
xdata UCHAR volatile SC_MCU_IO_CTRL2 _at_ 0x8C81;
xdata UCHAR volatile SC_MCU_IO_CTRL3 _at_ 0x8C82;
#endif
/*OSD 2 *//////////////////////////////////////////////
#if NT68660_SERIES || NT68669_SERIES || NT68650_SERIES
xdata UCHAR volatile SC_OSD_WIN_HOR_START_LO _at_ 0x8D03;
xdata UCHAR volatile SC_OSD_WIN_HOR_END_LO _at_ 0x8D04;
xdata UCHAR volatile SC_OSD_WIN_HOR_HI _at_ 0x8D05;
xdata UCHAR volatile SC_OSD_WIN_VER_START_LO _at_ 0x8D06;
xdata UCHAR volatile SC_OSD_WIN_VER_END_LO _at_ 0x8D07;
xdata UCHAR volatile SC_OSD_WIN_VER_HI _at_ 0x8D08;
#endif
// OSD Gradient
xdata UCHAR volatile SC_OSD_WIN_GRADIENT_CTRL _at_ 0x8D30;
xdata UCHAR volatile SC_OSD_WIN_GRADIENT_RED_COLOR _at_ 0x8D31;
xdata UCHAR volatile SC_OSD_WIN_GRADIENT_GREEN_COLOR _at_ 0x8D32;
xdata UCHAR volatile SC_OSD_WIN_GRADIENT_BLUE_COLOR _at_ 0x8D33;
xdata UCHAR volatile SC_OSD_WIN_GRADIENT_RED_STEP _at_ 0x8D34;
xdata UCHAR volatile SC_OSD_WIN_GRADIENT_GREEN_STEP _at_ 0x8D35;
xdata UCHAR volatile SC_OSD_WIN_GRADIENT_BLUE_STEP _at_ 0x8D36;
xdata UCHAR volatile SC_OSD_WIN_GRADIENT_COLOR_FRONTGROUND _at_ 0x8D37;
#endif

#if IS_NT68650_SERIES
xdata UCHAR volatile SC_LEDDRIVER_ENABLE _at_ 0x8E00;
xdata UCHAR volatile SC_LED_PROTECT_CTRL1 _at_ 0x8E02;
xdata UCHAR volatile SC_LED_PROTECT_CTRL2 _at_ 0x8E03;
xdata UCHAR volatile SC_LEDDIMMING_CTRL _at_ 0x8E12;
xdata UCHAR volatile SC_LED_OPEN_STATUS _at_ 0x8E13;
xdata UCHAR volatile SC_LED_SHORT_STATUS _at_ 0x8E14;
xdata UCHAR volatile SC_LEDSTATUS _at_ 0x8E15;
xdata UCHAR volatile SC_LEDPROTECT_ENABLE _at_ 0x8E1B;
xdata UCHAR volatile SC_VREF_VOLTAGE_MODE1 _at_ 0x8E22;
xdata UCHAR volatile SC_VREF_VOLTAGE_MODE2 _at_ 0x8E23;
#endif

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
