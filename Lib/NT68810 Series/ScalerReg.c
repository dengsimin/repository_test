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
xdata UCHAR volatile SC_SOG_SLICER_EN _at_ 0x800A;
xdata UCHAR volatile SC_SOG_DIGITAL_GLITCH_FILTER_THREESHOLD _at_ 0x800B;
xdata UCHAR volatile SC_SOG_GLITCH_MASK_LO _at_ 0x800C;
xdata UCHAR volatile SC_SOG_DIGITAL_FILTER_CTRL _at_ 0x800D;
xdata UCHAR volatile SC_ADC_POWER_UP _at_ 0x800E;
xdata UCHAR volatile SC_ADC_CLAMP_CTRL _at_ 0x800F;
xdata UCHAR volatile SC_ADC_BW_CTRL _at_ 0x8010;
xdata UCHAR volatile SC_SOG_CLAMPING_CTRL _at_ 0x8011;
xdata UCHAR volatile SC_SOG_SLICER_CTRL _at_ 0x8012;
xdata UCHAR volatile SC_ADC_INPUT_CTRL _at_ 0x8013;
xdata UCHAR volatile SC_HS_TRIG_LEVEL _at_ 0x8014;
xdata UCHAR volatile SC_VS_TRIG_LEVEL _at_ 0x8015;
xdata UCHAR volatile SC_TMDS_CLOCK_DET _at_ 0x8016;
xdata UCHAR volatile SC_ADC_CTRL2 _at_ 0x801E;
xdata UCHAR volatile SC_PRE_PATTER_CTRL _at_ 0x801F;
xdata UCHAR volatile SC_GPORT_CTRL _at_ 0x8020;
xdata UCHAR volatile SC_CLAMP_BEGIN _at_ 0x8021;
xdata UCHAR volatile SC_CLAMP_WIDTH _at_ 0x8022;
xdata UCHAR volatile SC_DIGITAL_CTRL _at_ 0x8023;
xdata UCHAR volatile SC_INPUT_SELECT _at_ 0x8024;
xdata UCHAR volatile SC_ADC_CK_CTRL _at_ 0x8025;
xdata UCHAR volatile SC_CAP_SWAP _at_ 0x8026;
xdata UCHAR volatile SC_GI_V_DE_DLY _at_ 0x8027;
xdata UCHAR volatile SC_GI_MASK_MSB _at_ 0x8028;
xdata UCHAR volatile SC_GI_MASK_CTRL _at_ 0x8029; 
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
xdata UCHAR volatile SC_GI_CLK_MASK_WID _at_ 0x8039;
xdata UCHAR volatile SC_DVI_CAP_HWID_LO _at_ 0x803C;
xdata UCHAR volatile SC_DVI_CAP_HWID_HI _at_ 0x803D;
xdata UCHAR volatile SC_DVI_CAP_VLEN_LO _at_ 0x803E;
xdata UCHAR volatile SC_DVI_CAP_VLEN_HI _at_ 0x803F;
xdata UCHAR volatile SC_VI_PORT_CTRL _at_ 0x8040;
xdata UCHAR volatile SC_VI_PORT_SELECT _at_ 0x8041;
xdata UCHAR volatile SC_VI_POLARITY_CTRL _at_ 0x8042;
xdata UCHAR volatile SC_SOG_T1_POSITION _at_ 0x8043;
xdata UCHAR volatile SC_SOG_T2_POSITION _at_ 0x8044;
xdata UCHAR volatile SC_SOG_T4_POSITION _at_ 0x8045;
xdata UCHAR volatile SC_SOG_T1_T2_WIDTH _at_ 0x8046;
xdata UCHAR volatile SC_SOG_T4_WIDTH _at_ 0x8047;
xdata UCHAR volatile SC_SOG_MODE_SEL _at_ 0x8048;
xdata UCHAR volatile SC_DEI_COLOR_COFFE_LO _at_ 0x8049;
xdata UCHAR volatile SC_DEI_COLOR_COFFE_HI _at_ 0x804A;
xdata UCHAR volatile SC_DEI_COLOR_COFFA_LO _at_ 0x804B;
xdata UCHAR volatile SC_DEI_COLOR_COFFA_HI _at_ 0x804C;
xdata UCHAR volatile SC_DEI_COLOR_COFFB_LO _at_ 0x804D;
xdata UCHAR volatile SC_DEI_COLOR_COFFB_HI _at_ 0x804E;
xdata UCHAR volatile SC_DEI_COLOR_COFFC_LO _at_ 0x804F;
xdata UCHAR volatile SC_DEI_COLOR_COFFC_HI _at_ 0x8050;
xdata UCHAR volatile SC_DEI_COLOR_COFFD_LO _at_ 0x8051;
xdata UCHAR volatile SC_DEI_COLOR_COFFD_HI _at_ 0x8052;
xdata UCHAR volatile SC_DEI_CSC_CTRL _at_ 0x8053;
xdata UCHAR volatile SC_CSC_CTRL1 _at_ 0x8054;
xdata UCHAR volatile SC_CSC_CTRL2 _at_ 0x8055;
xdata UCHAR volatile SC_CSC_COLOR_COFFA_LO _at_ 0x8056;
xdata UCHAR volatile SC_CSC_COLOR_COFFA_HI _at_ 0x8057;
xdata UCHAR volatile SC_CSC_COLOR_COFFB_LO _at_ 0x8058;
xdata UCHAR volatile SC_CSC_COLOR_COFFB_HI _at_ 0x8059;
xdata UCHAR volatile SC_CSC_COLOR_COFFC_LO _at_ 0x805A;
xdata UCHAR volatile SC_CSC_COLOR_COFFC_HI _at_ 0x805B;
xdata UCHAR volatile SC_CSC_COLOR_COFFD_LO _at_ 0x805C;
xdata UCHAR volatile SC_CSC_COLOR_COFFD_HI _at_ 0x805D;
xdata UCHAR volatile SC_CSC_COLOR_COFFE_LO _at_ 0x805E;
xdata UCHAR volatile SC_CSC_COLOR_COFFE_HI _at_ 0x805F;
xdata UCHAR volatile SC_BK_H_SHAP_CTRL _at_ 0x8060;
xdata UCHAR volatile SC_BK_CTRL1 _at_ 0x8061;
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
xdata UCHAR volatile SC_BP_SYNC_CTRL _at_ 0x8072;
//xdata UCHAR volatile SC_PWMA_LCNT _at_ 0x8074;
//xdata UCHAR volatile SC_PWMA_HCNT _at_ 0x8075;
//xdata UCHAR volatile SC_PWMB_LCNT _at_ 0x8076;
xdata UCHAR volatile SC_DPPPAPHY_ADDR_HI _at_ 0x9DF0;
xdata UCHAR volatile SC_DPPPAPHY_ADDR_LO _at_ 0x9DF1;
xdata UCHAR volatile SC_DPPPAPHY_DATA    _at_ 0x9DF2;
//xdata UCHAR volatile SC_PWMB_HCNT _at_ 0x8077;
//xdata UCHAR volatile SC_PWMA_DUTY_LO _at_ 0x8078;
//xdata UCHAR volatile SC_PWMB_DUTY_LO _at_ 0x8079;
//xdata UCHAR volatile SC_PWM_COUNTER _at_ 0x807A;
//xdata UCHAR volatile SC_PWM_CTRL1 _at_ 0x807E;
//xdata UCHAR volatile SC_PWM_CTRL2 _at_ 0x807F;
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
xdata UCHAR volatile SC_INDEX_DATA2 _at_ 0x80E4;
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
xdata UCHAR volatile SC_REVISION_ID _at_ 0x8104;
xdata UCHAR volatile SC_CHIP_ID _at_ 0x8105;
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
xdata UCHAR volatile SC_AUTO_GAIN_CTRL1 _at_ 0x812B;
xdata UCHAR volatile SC_AUTO_GAIN_CTRL2 _at_ 0x812C;
xdata UCHAR volatile SC_AUTO_GAIN_CTRL3 _at_ 0x812D;
xdata UCHAR volatile SC_AUTO_GAIN_CTRL4 _at_ 0x812E;
xdata UCHAR volatile SC_AUTO_GAIN_CTRL5 _at_ 0x812F;
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
xdata UCHAR volatile SC_SCALER_DE_EXT_2DTO3D _at_ 0x817E;
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
#if IS_NT68870_SERIES
xdata UCHAR volatile SC_DP_LINK_CLK_SEL _at_ 0x81EA;
xdata UCHAR volatile SC_ADC_REG_1D _at_ 0x81EC;
#else
xdata UCHAR volatile SC_ADC_REG_1D _at_ 0x81EA;
#endif
xdata UCHAR volatile SC_ADC_COMP_CTRL _at_ 0x81EB;
xdata UCHAR volatile SC_ADC_BAND_GAP _at_ 0x81ED;
xdata UCHAR volatile SC_BYPASS_CTRL _at_ 0x81EE;
xdata UCHAR volatile SC_LVDS_RSDS_SWITCH _at_ 0x81EF;
xdata UCHAR volatile SC_LVDS_DIV _at_ 0x81F0;
xdata UCHAR volatile SC_ADC_OP_CURRENT _at_ 0x81F1;
xdata UCHAR volatile SC_LVDS_ISOLATION _at_ 0x81F2;
xdata UCHAR volatile SC_ADC_TEST2_CTRL _at_ 0x81F3;
xdata UCHAR volatile SC_LVDS_CHARGE_PUMP_CURRENT _at_ 0x81F4;
xdata UCHAR volatile SC_LVDS_MISC_CTRL1 _at_ 0x81F5;
xdata UCHAR volatile SC_LVDS_MISC_CTRL2 _at_ 0x81F6;
xdata UCHAR volatile SC_LVDS_MISC_CTRL3 _at_ 0x81F7;
xdata UCHAR volatile SC_LVDS_MISC_CTRL4 _at_ 0x81F8;
xdata UCHAR volatile SC_LVDS_MISC_CTRL5 _at_ 0x81F9;
xdata UCHAR volatile SC_LVDS_MISC_CTRL6 _at_ 0x81FA;
xdata UCHAR volatile SC_LVDS_DATA_DELAY _at_ 0x81FB;
xdata UCHAR volatile SC_LVDS_CLOCK_DELAY _at_ 0x81FC;
xdata UCHAR volatile SC_LVDS_PLL_CTRL _at_ 0x81FD;
xdata UCHAR volatile SC_LVDS_PAD_POWER _at_ 0x81FE;
xdata UCHAR volatile SC_DITHER_CTRL_38D _at_ 0x838D;

#ifdef MHLOnPHYB
xdata UCHAR volatile SC_CBUS_DEV_STATE _at_ 0x9500;//Reserved
xdata UCHAR volatile SC_CBUS_MHL_VER _at_ 0x9501;//define by CDF: MHL_VER_MAJOR=1, MHL_VER_MINOR=2
xdata UCHAR volatile SC_CBUS_DEV_CAT _at_ 0x9502;//define by CDF: DEV_TYPE[0..3]=1, POW = 900mA
xdata UCHAR volatile SC_CBUS_ADOPTER_ID_H _at_ 0x9503;//define by CDF
xdata UCHAR volatile SC_CBUS_ADOPTER_ID_L _at_ 0x9504;//define by CDF
xdata UCHAR volatile SC_CBUS_VID_LINK_MODE _at_ 0x9505;//define by CDF: SUPP_RGB444, SUPP_YCBCR444, SUPP_ YCBCR422, SUPP_PPIXEL, SUPP_ISLANDS, SUPP_VGA
xdata UCHAR volatile SC_CBUS_AUD_LINK_MODE _at_ 0x9506;//define by CDF: AUD_2CH, AUD_8CH
xdata UCHAR volatile SC_CBUS_VIDEO_TYPE _at_ 0x9507;//define by CDF: VT_GRAPHICS, VT_PHOTO, VT_CINEMA, VT_GAME, SUPP_VT
xdata UCHAR volatile SC_CBUS_LOG_DEV_MAP _at_ 0x9508;//define by CDF: LD_DISPLAY, LD_VIDEO, LD_AUDIO, LD_MEDIA, LD_TUNER, LD_RECORD, LD_SPEAKER, LD_GUI
xdata UCHAR volatile SC_CBUS_BANDWIDTH _at_ 0x9509;//define by CDF: 15x5 =75MHz
xdata UCHAR volatile SC_CBUS_FEATURE_FLAG _at_ 0x950A;//define by CDF: UCP_RECV_SUPPORT, UCP_SEND_SUPPORT, RCP_SUPPORT, RAP_SUPPORT, SP_SUPPORT
xdata UCHAR volatile SC_CBUS_DEVICE_ID_H _at_ 0x950B;//define by CDF
xdata UCHAR volatile SC_CBUS_DEVICE_ID_L _at_ 0x950C;//define by CDF
xdata UCHAR volatile SC_CBUS_SCRATCHPAD_SIZE _at_ 0x950D;//define by CDF (change to 16 for 6.3.11.19 CBM: DUT Receives (0x6C) WRITE_BURST - Too Much Data.)
xdata UCHAR volatile SC_CBUS_INT_STAT_SIZE _at_ 0x950E;//define by CDF
xdata UCHAR volatile RCP_TEST _at_ 0x950F;//Reserved
xdata UCHAR volatile SC_CBUS_TRANS_FLAG0 _at_ 0x9580;	//R
xdata UCHAR volatile SC_CBUS_RX_DATA _at_ 0x9581;	//R
xdata UCHAR volatile SC_CBUS_TRANS_FLAG1 _at_ 0x9582;	//R
xdata UCHAR volatile SC_CBUS_MSC_CMD _at_ 0x9583;	//W
xdata UCHAR volatile SC_CBUS_MSC_DATA _at_ 0x9584;	//W
xdata UCHAR volatile SC_CBUS_DDC_CMD _at_ 0x9585;	//W
xdata UCHAR volatile SC_CBUS_DDC_DATA _at_ 0x9586;	//W
xdata UCHAR volatile SC_CBUS_VDR_CMD _at_ 0x9587;	//W
xdata UCHAR volatile SC_CBUS_VDR_DATA _at_ 0x9588;	//W
xdata UCHAR volatile SC_CBUS_MSC_ERROR _at_ 0x9589;
xdata UCHAR volatile SC_CBUS_DDC_ERROR _at_ 0x958A;
xdata UCHAR volatile SC_CBUS_TRANS_INT_EN _at_ 0x958B;
xdata UCHAR volatile SC_CBUS_TRANS_RESET _at_ 0x958C;	// 1: Reset
xdata UCHAR volatile SC_CBUS_CONTROL _at_ 0x95A0;
xdata UCHAR volatile SC_VBUS_ENABLE_TIME  _at_ 0x95A1;
xdata UCHAR volatile SC_CBUS_DISCOVERY_TIME _at_ 0x95A2;
xdata UCHAR volatile SC_DISCOVERY2CONN _at_ 0x95A3;
xdata UCHAR volatile SC_RXSENSE_EN_TIME _at_ 0x95A6;
xdata UCHAR volatile SC_CBUS_SINK_CONN _at_ 0x95A8;
xdata UCHAR volatile SC_REJECT_CBUS_DISCOVERY_PULSE_MIN _at_ 0x95AA;
xdata UCHAR volatile SC_REJECT_CBUS_DISCOVERY_PULSE_MAX _at_ 0x95AB;
xdata UCHAR volatile SC_WAKE_MODE _at_ 0x95AC;
xdata UCHAR volatile SC_SINK_WAKE _at_ 0x95AE;
xdata UCHAR volatile SC_CBUS_LINK_INT_FLAG _at_ 0x95B0;  // RO
xdata UCHAR volatile SC_CBUS_LINK_INT_MASK _at_ 0x95B1;  
xdata UCHAR volatile SC_CBUS_DIS_INT_FLAG   _at_ 0x95B2;
xdata UCHAR volatile SC_CBUS_DIS_INT_FLAG_1 _at_ 0x95B3;
xdata UCHAR volatile SC_CBUS_DIS_INT_MASK _at_ 0x95B4;
xdata UCHAR volatile SC_CBUS_INT_FLAG _at_ 0x95B5;
xdata UCHAR volatile SC_CBUS_INT_EN _at_ 0x95B6;
xdata UCHAR volatile SC_LINK_CONTROL _at_ 0x95C0;
xdata UCHAR volatile SC_BIT_TIME_THD_LO _at_ 0x95C1;
xdata UCHAR volatile SC_BIT_TIME_THD_HI _at_ 0x95C2;
xdata UCHAR volatile SC_ACK_BIT_INIT_FALLING_EDGE _at_ 0x95C8;
xdata UCHAR volatile SC_CBUS_ACK_LENGTH _at_ 0x95C9;
xdata UCHAR volatile SC_CBUS_ARBIT_WIN_LENGTH _at_ 0x95CB;
xdata UCHAR volatile SC_CBUS_DRV _at_ 0x95CC;
xdata UCHAR volatile SC_ARBIT_WAIT_TIME1 _at_ 0x95CD;
xdata UCHAR volatile SC_ARBIT_WAIT_TIME2 _at_ 0x95CE;
xdata UCHAR volatile SC_CBUS_NACK_TRY_MAX _at_ 0x95CF;
xdata UCHAR volatile SC_CBUS_RESISTOR_CTRL _at_ 0x95D1;
xdata UCHAR volatile SC_CBUS_DEBUG_CTRL _at_ 0x95D2;
xdata UCHAR volatile SC_MHL_CDSENSE_CTRL _at_ 0x95D8;
#if defined(ENABLE_FPGA_MODE)
xdata UCHAR volatile SC_FPGA_CDSENSE _at_ 0x95DA;
#endif
xdata UCHAR volatile SC_MHL_CTRL_2E0 _at_ 0x95E0;
xdata UCHAR volatile SC_18V_LDO_CONTROL _at_ 0x95E1;
xdata UCHAR volatile SC_CBUS_CHANNEL_SEL _at_ 0x95F0;
xdata UCHAR volatile SC_CBUS_COUNT _at_ 0x95F1;	
#else
xdata UCHAR volatile SC_CBUS_DEV_STATE _at_ 0x8200;//Reserved
xdata UCHAR volatile SC_CBUS_MHL_VER _at_ 0x8201;//define by CDF: MHL_VER_MAJOR=1, MHL_VER_MINOR=2
xdata UCHAR volatile SC_CBUS_DEV_CAT _at_ 0x8202;//define by CDF: DEV_TYPE[0..3]=1, POW = 900mA
xdata UCHAR volatile SC_CBUS_ADOPTER_ID_H _at_ 0x8203;//define by CDF
xdata UCHAR volatile SC_CBUS_ADOPTER_ID_L _at_ 0x8204;//define by CDF
xdata UCHAR volatile SC_CBUS_VID_LINK_MODE _at_ 0x8205;//define by CDF: SUPP_RGB444, SUPP_YCBCR444, SUPP_ YCBCR422, SUPP_PPIXEL, SUPP_ISLANDS, SUPP_VGA
xdata UCHAR volatile SC_CBUS_AUD_LINK_MODE _at_ 0x8206;//define by CDF: AUD_2CH, AUD_8CH
xdata UCHAR volatile SC_CBUS_VIDEO_TYPE _at_ 0x8207;//define by CDF: VT_GRAPHICS, VT_PHOTO, VT_CINEMA, VT_GAME, SUPP_VT
xdata UCHAR volatile SC_CBUS_LOG_DEV_MAP _at_ 0x8208;//define by CDF: LD_DISPLAY, LD_VIDEO, LD_AUDIO, LD_MEDIA, LD_TUNER, LD_RECORD, LD_SPEAKER, LD_GUI
xdata UCHAR volatile SC_CBUS_BANDWIDTH _at_ 0x8209;//define by CDF: 15x5 =75MHz
xdata UCHAR volatile SC_CBUS_FEATURE_FLAG _at_ 0x820A;//define by CDF: UCP_RECV_SUPPORT, UCP_SEND_SUPPORT, RCP_SUPPORT, RAP_SUPPORT, SP_SUPPORT
xdata UCHAR volatile SC_CBUS_DEVICE_ID_H _at_ 0x820B;//define by CDF
xdata UCHAR volatile SC_CBUS_DEVICE_ID_L _at_ 0x820C;//define by CDF
xdata UCHAR volatile SC_CBUS_SCRATCHPAD_SIZE _at_ 0x820D;//define by CDF (change to 16 for 6.3.11.19 CBM: DUT Receives (0x6C) WRITE_BURST - Too Much Data.)
xdata UCHAR volatile SC_CBUS_INT_STAT_SIZE _at_ 0x820E;//define by CDF

xdata UCHAR volatile RCP_TEST _at_ 0x820F;//Reserved
xdata UCHAR volatile SC_CBUS_TRANS_FLAG0 _at_ 0x8280;	//R
xdata UCHAR volatile SC_CBUS_RX_DATA _at_ 0x8281;	//R
xdata UCHAR volatile SC_CBUS_TRANS_FLAG1 _at_ 0x8282;	//R
xdata UCHAR volatile SC_CBUS_MSC_CMD _at_ 0x8283;	//W
xdata UCHAR volatile SC_CBUS_MSC_DATA _at_ 0x8284;	//W
xdata UCHAR volatile SC_CBUS_DDC_CMD _at_ 0x8285;	//W
xdata UCHAR volatile SC_CBUS_DDC_DATA _at_ 0x8286;	//W
xdata UCHAR volatile SC_CBUS_VDR_CMD _at_ 0x8287;	//W
xdata UCHAR volatile SC_CBUS_VDR_DATA _at_ 0x8288;	//W
xdata UCHAR volatile SC_CBUS_MSC_ERROR _at_ 0x8289;
xdata UCHAR volatile SC_CBUS_DDC_ERROR _at_ 0x828A;
xdata UCHAR volatile SC_CBUS_TRANS_INT_EN _at_ 0x828B;
xdata UCHAR volatile SC_CBUS_TRANS_RESET _at_ 0x828C;	// 1: Reset

xdata UCHAR volatile SC_CBUS_CONTROL _at_ 0x82A0;
xdata UCHAR volatile SC_VBUS_ENABLE_TIME  _at_ 0x82A1;
xdata UCHAR volatile SC_CBUS_DISCOVERY_TIME _at_ 0x82A2;
xdata UCHAR volatile SC_DISCOVERY2CONN _at_ 0x82A3;
xdata UCHAR volatile SC_RXSENSE_EN_TIME _at_ 0x82A6;
xdata UCHAR volatile SC_CBUS_SINK_CONN _at_ 0x82A8;
xdata UCHAR volatile SC_REJECT_CBUS_DISCOVERY_PULSE_MIN _at_ 0x82AA;
xdata UCHAR volatile SC_REJECT_CBUS_DISCOVERY_PULSE_MAX _at_ 0x82AB;
xdata UCHAR volatile SC_WAKE_MODE _at_ 0x82AC;
xdata UCHAR volatile SC_SINK_WAKE _at_ 0x82AE;
xdata UCHAR volatile SC_CBUS_LINK_INT_FLAG _at_ 0x82B0;  // RO
xdata UCHAR volatile SC_CBUS_LINK_INT_MASK _at_ 0x82B1;  
xdata UCHAR volatile SC_CBUS_DIS_INT_FLAG   _at_ 0x82B2;
xdata UCHAR volatile SC_CBUS_DIS_INT_FLAG_1 _at_ 0x82B3;
xdata UCHAR volatile SC_CBUS_DIS_INT_MASK _at_ 0x82B4;
xdata UCHAR volatile SC_CBUS_INT_FLAG _at_ 0x82B5;
xdata UCHAR volatile SC_CBUS_INT_EN _at_ 0x82B6;
xdata UCHAR volatile SC_LINK_CONTROL _at_ 0x82C0;
xdata UCHAR volatile SC_BIT_TIME_THD_LO _at_ 0x82C1;
xdata UCHAR volatile SC_BIT_TIME_THD_HI _at_ 0x82C2;
xdata UCHAR volatile SC_ACK_BIT_INIT_FALLING_EDGE _at_ 0x82C8;
xdata UCHAR volatile SC_CBUS_ACK_LENGTH _at_ 0x82C9;
xdata UCHAR volatile SC_CBUS_ARBIT_WIN_LENGTH _at_ 0x82CB;
xdata UCHAR volatile SC_CBUS_DRV _at_ 0x82CC;
xdata UCHAR volatile SC_ARBIT_WAIT_TIME1 _at_ 0x82CD;
xdata UCHAR volatile SC_ARBIT_WAIT_TIME2 _at_ 0x82CE;
xdata UCHAR volatile SC_CBUS_NACK_TRY_MAX _at_ 0x82CF;
xdata UCHAR volatile SC_CBUS_RESISTOR_CTRL _at_ 0x82D1;
xdata UCHAR volatile SC_CBUS_DEBUG_CTRL _at_ 0x82D2;
xdata UCHAR volatile SC_MHL_CDSENSE_CTRL _at_ 0x82D8;
#if defined(ENABLE_FPGA_MODE)
xdata UCHAR volatile SC_FPGA_CDSENSE _at_ 0x82DA;
#endif
xdata UCHAR volatile SC_MHL_CTRL_2E0 _at_ 0x82E0;
xdata UCHAR volatile SC_18V_LDO_CONTROL _at_ 0x82E1;
xdata UCHAR volatile SC_CBUS_CHANNEL_SEL _at_ 0x82F0;
xdata UCHAR volatile SC_CBUS_COUNT _at_ 0x82F1;	
#endif

xdata UCHAR volatile SC_DVI_PIXELCLK_LO _at_ 0x8304;
xdata UCHAR volatile SC_DVI_PIXELCLK_HI _at_ 0x8305;

xdata UCHAR volatile SC_DVI_CTRL_32F _at_ 0x832F; // Yung Fpga need use

xdata UCHAR volatile SC_DITHER_TOGGLE_CTRL _at_ 0x8371;
xdata UCHAR volatile SC_DITHER_TP_GRAY_LVL_LO _at_ 0x8378;
xdata UCHAR volatile SC_DITHER_TP_GRAY_LVL_HI _at_ 0x8379;
xdata UCHAR volatile SC_NEW_HSYNC_CTRL1 _at_ 0x837A;
xdata UCHAR volatile SC_DISPLAY_DITHER_RANDOM _at_ 0x838C;
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
xdata UCHAR volatile SC_PREPATTERN_CTRL1 _at_ 0x83F3;
xdata UCHAR volatile SC_NEW_OVS_VBEG_LO _at_ 0x83F8;
xdata UCHAR volatile SC_NEW_OVS_VBEG_HI _at_ 0x83F9;
xdata UCHAR volatile SC_OVERSCAN_MODE _at_ 0x83FB;
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
xdata UCHAR volatile SC_DBC_AVERAGE_MODE _at_ 0x8441;
xdata UCHAR volatile SC_DBC_DEBOUNCINT_MODE _at_ 0x8442;
xdata UCHAR volatile SC_DBC_NON_LINEAR_GAIN_CTRL _at_ 0x8443;
xdata UCHAR volatile SC_DBC_PWM_LUT_LIM _at_ 0x8444;
xdata UCHAR volatile SC_DBC_GRAY_LUT_LIM _at_ 0x8445;
xdata UCHAR volatile SC_DBC_EXT_CTRL _at_ 0x8446;
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
xdata UCHAR volatile SC_OD_CONFIGURATION _at_ 0x8480;
xdata UCHAR volatile SC_OD_MULTI_ZONE_LOW_BOUNDARY_LO _at_ 0x8489;
xdata UCHAR volatile SC_OD_MULTI_ZONE_LOW_BOUNDARY_HI _at_ 0x848A;
xdata UCHAR volatile SC_OD_MULTI_ZONE_HIGH_BOUNDARY_LO _at_ 0x848B;
xdata UCHAR volatile SC_OD_MULTI_ZONE_HIGH_BOUNDARY_HI _at_ 0x848C;
xdata UCHAR volatile SC_OD_BTC_CONFIGURATION _at_ 0x8490;
xdata UCHAR volatile SC_OD_BTC_CONFIGURATION2 _at_ 0x8491;
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
xdata UCHAR volatile SC_OD_MOTION_CHECK_BOUNCE_MONITOR _at_ 0x84C6;
xdata UCHAR volatile SC_OD_MOTION_CHECK_THRESHOLD _at_ 0x84C7;
xdata UCHAR volatile SC_OD_MOTION_CHECK_DEBOUNCE _at_ 0x84C8;
xdata UCHAR volatile SC_OD_MOTION_CHECK_STATUS _at_ 0x84C9;

xdata UCHAR volatile SC_D_OD_CTRL _at_ 0x84DB;
xdata UCHAR volatile SC_D_OD_CTRL2 _at_ 0x84DD;

xdata UCHAR volatile SC_AUTO_INTERLACED_CTRL1 _at_ 0x84F0;
xdata UCHAR volatile SC_AUTO_INTERLACED_CTRL2 _at_ 0x84F1;
xdata UCHAR volatile SC_AUTO_INTERLACED_CTRL3 _at_ 0x84F2;

xdata UCHAR volatile SC_D_OD_FRAMERATE_CLASSIFY_CTRL _at_ 0x84F4;
xdata UCHAR volatile SC_D_OD_FRAMERATE_BOUNDARY1 _at_ 0x84F5;
xdata UCHAR volatile SC_D_OD_FRAMERATE_BOUNDARY2 _at_ 0x84F6;
xdata UCHAR volatile SC_D_OD_PART0_OVERSHOOT_GAIN _at_ 0x84F7;
xdata UCHAR volatile SC_D_OD_PART0_UNDERSHOOT_GAIN _at_ 0x84F8;
xdata UCHAR volatile SC_D_OD_PART1_OVERSHOOT_GAIN _at_ 0x84F9;
xdata UCHAR volatile SC_D_OD_PART1_UNDERSHOOT_GAIN _at_ 0x84FA;
xdata UCHAR volatile SC_D_OD_PART2_OVERSHOOT_GAIN _at_ 0x84FB;
xdata UCHAR volatile SC_D_OD_PART2_UNDERSHOOT_GAIN _at_ 0x84FC;
xdata UCHAR volatile SC_D_OD_PART3_OVERSHOOT_GAIN _at_ 0x84FD;
xdata UCHAR volatile SC_D_OD_PART3_UNDERSHOOT_GAIN _at_ 0x84FE;

xdata UCHAR volatile SC_FRAME_BUFFER1_BASE_ADDR_POSTFRC_LO _at_ 0x8508;
xdata UCHAR volatile SC_FRAME_BUFFER1_BASE_ADDR_POSTFRC_MI _at_ 0x8509;
xdata UCHAR volatile SC_FRAME_BUFFER1_BASE_ADDR_POSTFRC_HI _at_ 0x850A;
xdata UCHAR volatile SC_FRAME_BUFFER1_BASE_ADDR_PREFRC_LO _at_ 0x850B;
xdata UCHAR volatile SC_FRAME_BUFFER1_BASE_ADDR_PREFRC_MI _at_ 0x850C;
xdata UCHAR volatile SC_FRAME_BUFFER1_BASE_ADDR_PREFRC_HI _at_ 0x850D;

xdata UCHAR volatile SC_FRAME_BUFFER2_BASE_ADDR_POSTFRC_LO _at_ 0x850E;
xdata UCHAR volatile SC_FRAME_BUFFER2_BASE_ADDR_POSTFRC_MI _at_ 0x850F;
xdata UCHAR volatile SC_FRAME_BUFFER2_BASE_ADDR_POSTFRC_HI _at_ 0x8510;
xdata UCHAR volatile SC_FRAME_BUFFER2_BASE_ADDR_PREFRC_LO _at_ 0x8511;
xdata UCHAR volatile SC_FRAME_BUFFER2_BASE_ADDR_PREFRC_MI _at_ 0x8512;
xdata UCHAR volatile SC_FRAME_BUFFER2_BASE_ADDR_PREFRC_HI _at_ 0x8513;

xdata UCHAR volatile SC_FRAME_BUFFER_BASE_ADDR_OD_LO _at_ 0x8514;
xdata UCHAR volatile SC_FRAME_BUFFER_BASE_ADDR_OD_MI _at_ 0x8515;
xdata UCHAR volatile SC_FRAME_BUFFER_BASE_ADDR_OD_HI _at_ 0x8516;

xdata UCHAR volatile SC_FRC_V_FP _at_ 0x851D;
xdata UCHAR volatile SC_FRC_H_FP _at_ 0x851E;
xdata UCHAR volatile SC_FRC_VH_FP _at_ 0x851F;
xdata UCHAR volatile SC_FRC_CENTER_H_START_LO _at_ 0x8521;
xdata UCHAR volatile SC_FRC_CENTER_H_START_HI _at_ 0x8522;
xdata UCHAR volatile SC_FRC_CENTER_V_START_LO _at_ 0x8523;
xdata UCHAR volatile SC_FRC_CENTER_V_START_HI _at_ 0x8524;
xdata UCHAR volatile SC_FRC_CENTER_MODE _at_ 0x8526;

xdata UCHAR volatile SC_PREFRC_OUTPUT_H_ACTIVE_LO _at_ 0x8530;
xdata UCHAR volatile SC_PREFRC_OUTPUT_H_ACTIVE_HI _at_ 0x8531;
xdata UCHAR volatile SC_PREFRC_OUTPUT_H_TOTAL_LO _at_ 0x8532;
xdata UCHAR volatile SC_PREFRC_OUTPUT_H_TOTAL_HI _at_ 0x8533;
xdata UCHAR volatile SC_PREFRC_OUTPUT_V_ACTIVE_LO _at_ 0x8534;
xdata UCHAR volatile SC_PREFRC_OUTPUT_V_ACTIVE_HI _at_ 0x8535;
xdata UCHAR volatile SC_PREFRC_OUTPUT_V_TOTAL_LO _at_ 0x8536;
xdata UCHAR volatile SC_PREFRC_OUTPUT_V_TOTAL_HI _at_ 0x8537;
xdata UCHAR volatile SC_PREFRC_CONTROL _at_ 0x8538;
xdata UCHAR volatile SC_PREFRC_RESET _at_ 0x8539;
xdata UCHAR volatile SC_PREFRC_53A _at_ 0x853A;
xdata UCHAR volatile SC_PREFRC_53B _at_ 0x853B;
xdata UCHAR volatile SC_PREFRC_53C _at_ 0x853C;
xdata UCHAR volatile SC_PREFRC_53D _at_ 0x853D;
xdata UCHAR volatile SC_PREFRC_53E _at_ 0x853E;
xdata UCHAR volatile SC_PREFRC_53F _at_ 0x853F;

xdata UCHAR volatile SC_FRC_OUTPUT_H_ACTIVE_LO _at_ 0x8540;
xdata UCHAR volatile SC_FRC_OUTPUT_H_ACTIVE_HI _at_ 0x8541;
xdata UCHAR volatile SC_FRC_OUTPUT_H_TOTAL_LO _at_ 0x8542;
xdata UCHAR volatile SC_FRC_OUTPUT_H_TOTAL_HI _at_ 0x8543;
xdata UCHAR volatile SC_FRC_OUTPUT_V_ACTIVE_LO _at_ 0x8544;
xdata UCHAR volatile SC_FRC_OUTPUT_V_ACTIVE_HI _at_ 0x8545;
xdata UCHAR volatile SC_FRC_OUTPUT_V_TOTAL_LO _at_ 0x8546;
xdata UCHAR volatile SC_FRC_OUTPUT_V_TOTAL_HI _at_ 0x8547;
xdata UCHAR volatile SC_FRC_CTRL _at_ 0x8548;
xdata UCHAR volatile SC_FRC_RESET _at_ 0x8549;
xdata UCHAR volatile SC_FRC_POINT1_HI _at_ 0x854A;
xdata UCHAR volatile SC_FRC_V_POINT1_LO _at_ 0x854B;
xdata UCHAR volatile SC_FRC_H_POINT1_LO _at_ 0x854C;
xdata UCHAR volatile SC_FRC_POINT2_HI _at_ 0x854D;
xdata UCHAR volatile SC_FRC_V_POINT2_LO _at_ 0x854E;
xdata UCHAR volatile SC_FRC_H_POINT2_LO _at_ 0x854F;

xdata UCHAR volatile SC_DRAM_LINE_BUFFER_DATA_PORT _at_ 0x8550;
xdata UCHAR volatile SC_DRAM_LINE_BUFFER_CTRL _at_ 0x8551;
xdata UCHAR volatile SC_LINE_BUFFER_BASE_ADDR_LO _at_ 0x8552;
xdata UCHAR volatile SC_LINE_BUFFER_BASE_ADDR_MI _at_ 0x8553;
xdata UCHAR volatile SC_LINE_BUFFER_BASE_ADDR_HI _at_ 0x8554;
xdata UCHAR volatile SC_DRAM_LINE_BUFFER_BASE_QUANTITY _at_ 0x8555;
xdata UCHAR volatile SC_LINE_WRITE_SRAM_CTRL_LO _at_ 0x8556;
xdata UCHAR volatile SC_LINE_WRITE_SRAM_CTRL_HI _at_ 0x8557;
xdata UCHAR volatile SC_LINE_READ_SRAM_CTRL_LO _at_ 0x8558;
xdata UCHAR volatile SC_LINE_READ_SRAM_CTRL_HI _at_ 0x8559;
xdata UCHAR volatile SC_AUTO_REFLESH_CTRL _at_ 0x855F;
xdata UCHAR volatile SC_DRAM_INTERFACE_LO _at_ 0x8580;
xdata UCHAR volatile SC_DRAM_INTERFACE_HI _at_ 0x8581;
xdata UCHAR volatile SC_DRAM_MMU_MODE _at_ 0x8582;
xdata UCHAR volatile SC_DRAM_MMU_MODE_1 _at_ 0x8583;
xdata UCHAR volatile SC_DRAM_MMU_MODE_2 _at_ 0x8584;
xdata UCHAR volatile SC_DRAM_MMU_MODE_3 _at_ 0x8585;
xdata UCHAR volatile SC_DRAM_MMU_REQUEST_W _at_ 0x8586;
xdata UCHAR volatile SC_DRAM_MMU_REQUEST_R _at_ 0x8587;
xdata UCHAR volatile SC_DDR_PAD_CTRL1 _at_ 0x8588;
xdata UCHAR volatile SC_DDR_PAD_CTRL2 _at_ 0x8589;
xdata UCHAR volatile SC_MMU_CFG2 _at_ 0x858A;
xdata UCHAR volatile SC_MMU_CFG2B _at_ 0x858B;
xdata UCHAR volatile SC_MMU_CFG3 _at_ 0x858F;
xdata UCHAR volatile SC_FRC_FIFO_CTRL0 _at_ 0x8594;
xdata UCHAR volatile SC_FRC_FIFO_CTRL1 _at_ 0x8595;
xdata UCHAR volatile SC_FRC_FIFO_CTRL2 _at_ 0x8596;
xdata UCHAR volatile SC_FRC_FIFO_CTRL3 _at_ 0x8597;
xdata UCHAR volatile SC_OD_FIFO_CTRL1 _at_ 0x8598;
xdata UCHAR volatile SC_OD_FIFO_CTRL2 _at_ 0x8599;
xdata UCHAR volatile SC_OD_FIFO_CTRL3 _at_ 0x859A;
xdata UCHAR volatile SC_PREFRC_FIFO_CTRL1 _at_ 0x859C;
xdata UCHAR volatile SC_PREFRC_FIFO_CTRL2 _at_ 0x859D;
xdata UCHAR volatile SC_PREFRC_FIFO_CTRL3 _at_ 0x859E;

xdata UCHAR volatile SC_INPUT_PROCESSOR_WRITE_FIFO_ADDR_HI _at_ 0x85A0;
xdata UCHAR volatile SC_INPUT_PROCESSOR_WRITE_FIFO_ADDR_START _at_ 0x85A1;
xdata UCHAR volatile SC_INPUT_PROCESSOR_WRITE_FIFO_ADDR_END _at_ 0x85A2;
xdata UCHAR volatile SC_FRC_WRITE_FIFO_ADDR_HI _at_ 0x85A3;
xdata UCHAR volatile SC_FRC_WRITE_FIFO_ADDR_START _at_ 0x85A4;
xdata UCHAR volatile SC_FRC_WRITE_FIFO_ADDR_END _at_ 0x85A5;
xdata UCHAR volatile SC_OD_WRITE_FIFO_ADDR_HI _at_ 0x85A6;
xdata UCHAR volatile SC_OD_WRITE_FIFO_ADDR_START _at_ 0x85A7;
xdata UCHAR volatile SC_OD_WRITE_FIFO_ADDR_END _at_ 0x85A8;
xdata UCHAR volatile SC_PREFRC_WRITE_FIFO_ADDR_CONTROL1 _at_ 0x85A9;
xdata UCHAR volatile SC_PREFRC_WRITE_FIFO_ADDR_CONTROL2 _at_ 0x85AA;
xdata UCHAR volatile SC_PREFRC_WRITE_FIFO_ADDR_CONTROL3 _at_ 0x85AB;

xdata UCHAR volatile SC_DEI_READ_FIFO_F0_ADDR_HI _at_ 0x85B0;
xdata UCHAR volatile SC_DEI_READ_FIFO_F0_ADDR_START _at_ 0x85B1;
xdata UCHAR volatile SC_DEI_READ_FIFO_F0_ADDR_END _at_ 0x85B2;
xdata UCHAR volatile SC_DEI_READ_FIFO_F1_ADDR_HI _at_ 0x85B3;
xdata UCHAR volatile SC_DEI_READ_FIFO_F1_ADDR_START _at_ 0x85B4;
xdata UCHAR volatile SC_DEI_READ_FIFO_F1_ADDR_END _at_ 0x85B5;
xdata UCHAR volatile SC_DEI_READ_FIFO_F2_ADDR_HI _at_ 0x85B6;
xdata UCHAR volatile SC_DEI_READ_FIFO_F2_ADDR_START _at_ 0x85B7;
xdata UCHAR volatile SC_DEI_READ_FIFO_F2_ADDR_END _at_ 0x85B8;
xdata UCHAR volatile SC_DEI_READ_FIFO_F3_ADDR_HI _at_ 0x85B9;
xdata UCHAR volatile SC_DEI_READ_FIFO_F3_ADDR_START _at_ 0x85BA;
xdata UCHAR volatile SC_DEI_READ_FIFO_F3_ADDR_END _at_ 0x85BB;
xdata UCHAR volatile SC_FRC_READ_FIFO_ADDR_HI _at_ 0x85BC;
xdata UCHAR volatile SC_FRC_READ_FIFO_ADDR_START _at_ 0x85BD;
xdata UCHAR volatile SC_FRC_READ_FIFO_ADDR_END _at_ 0x85BE;
xdata UCHAR volatile SC_OD_READ_FIFO_ADDR_HI _at_ 0x85BF;
xdata UCHAR volatile SC_OD_READ_FIFO_ADDR_START _at_ 0x85C0;
xdata UCHAR volatile SC_OD_READ_FIFO_ADDR_END _at_ 0x85C1;

xdata UCHAR volatile SC_PREFRC_READ_FIFO_ADDR1 _at_ 0x85C2;
xdata UCHAR volatile SC_PREFRC_READ_FIFO_ADDR2 _at_ 0x85C3;
xdata UCHAR volatile SC_PREFRC_READ_FIFO_ADDR3 _at_ 0x85C4;

xdata UCHAR volatile SC_MMU_TM_DQS_SEL_7_0 _at_ 0x85EC;
xdata UCHAR volatile SC_MMU_TM_DQS_SEL_15_8 _at_ 0x85ED;
xdata UCHAR volatile SC_MMU_TM_DQS_SEL_23_16 _at_ 0x85EE;
xdata UCHAR volatile SC_MMU_TM_DQS_SEL_31_24 _at_ 0x85EF;

xdata UCHAR volatile SC_DRAM_CLOCK_CTRL[8] _at_ 0x85F0;
xdata UCHAR volatile SC_DEI_CLK_CTRL _at_ 0x85F8;
xdata UCHAR volatile SC_3D_CNV_2D _at_ 0x85F9;
xdata UCHAR volatile SC_MMU_DATA_PHASE_SEL _at_ 0x85FA;
xdata UCHAR volatile SC_MCU_CLK_INV_APR2 _at_ 0x85FD;
xdata UCHAR volatile SC_TMDS_AUTO_CSC _at_ 0x8600;
xdata UCHAR volatile SC_SR_AUTO_CSC_CTRL _at_ 0x8601;
xdata UCHAR volatile SC_HDMI_SOFTWARE_RESET _at_ 0x8605;
xdata UCHAR volatile SC_HDMI_CKDT _at_ 0x8606;
xdata UCHAR volatile SC_HDMI_CLK_INT _at_ 0x8608;
xdata UCHAR volatile SC_HDCP_BKSV _at_ 0x861A;
xdata UCHAR volatile SC_HDCP_BKSV_B2 _at_ 0x861B;
xdata UCHAR volatile SC_HDCP_BKSV_B3 _at_ 0x861C;
xdata UCHAR volatile SC_HDCP_BKSV_B4 _at_ 0x861D;
xdata UCHAR volatile SC_HDCP_BKSV_B5 _at_ 0x861E;
xdata UCHAR volatile SC_HDCP_62E _at_ 0x862E;
xdata UCHAR volatile SC_HDMI_MHL_MODE_DETECT _at_ 0x8630;
xdata UCHAR volatile SC_HDCP_STATUS _at_ 0x8632;
xdata UCHAR volatile SC_VIDEO_HTOTAL_LO _at_ 0x863A;
xdata UCHAR volatile SC_VIDEO_HTOTAL_HI _at_ 0x863B;
xdata UCHAR volatile SC_VIDEO_VTOTAL_LO _at_ 0x863C;
xdata UCHAR volatile SC_VIDEO_VTOTAL_HI _at_ 0x863D;
xdata UCHAR volatile SC_HDCP_SLAVE_ADDR _at_ 0x863F;
xdata UCHAR volatile SC_HDCP_SYNC_SELECT _at_ 0x8640;
xdata UCHAR volatile SC_HDCP_INPUT_CTRL _at_ 0x8641;
xdata UCHAR volatile SC_FPGA1_FPGA2_DELAY _at_ 0x8642;
xdata UCHAR volatile SC_HDCP_CTRL _at_ 0x8643;
xdata UCHAR volatile SC_HDCP_PACKING _at_ 0x8645;
xdata UCHAR volatile SC_HDCP_CTRL3 _at_ 0x8646;
xdata UCHAR volatile SC_ICPCSC_AUTOSTATUS _at_ 0x8649;
xdata UCHAR volatile SC_VIDEO_BLANK_BLUE _at_ 0x864B;
xdata UCHAR volatile SC_VIDEO_BLANK_GREEN _at_ 0x864C;
xdata UCHAR volatile SC_VIDEO_BLANK_RED _at_ 0x864D;
xdata UCHAR volatile SC_VIDEO_DE_WIDTH_LO _at_ 0x864E;
xdata UCHAR volatile SC_VIDEO_DE_WIDTH_HI _at_ 0x864F;
xdata UCHAR volatile SC_VIDEO_DE_LINE_LO _at_ 0x8650;
xdata UCHAR volatile SC_VIDEO_DE_LINE_HI _at_ 0x8651;
xdata UCHAR volatile SC_NEW_DE_MODE_EN _at_ 0x866B;
xdata UCHAR volatile SC_HDMI_CLK _at_ 0x866F;
xdata UCHAR volatile SC_HDMI_INT_STATE1[5] _at_ 0x8670;
xdata UCHAR volatile SC_HDMI_INT_UNMASK1[4] _at_ 0x8675;
xdata UCHAR volatile SC_HDMI_INT_STATE2[2] _at_ 0x867B;
xdata UCHAR volatile SC_HDMI_INT_UNMASK2[3] _at_ 0x867D;

xdata UCHAR volatile SC_HDMI_AUTO_CTRL _at_ 0x86B5;
xdata UCHAR volatile SC_AEC_EXE_EN[3] _at_ 0x86B6;


xdata UCHAR volatile SC_ACR_CTRL _at_ 0x8700;
xdata UCHAR volatile SC_ACR_N_VALUE_LO _at_ 0x8703;
xdata UCHAR volatile SC_ACR_N_VALUE_MI _at_ 0x8704;
xdata UCHAR volatile SC_ACR_N_VALUE_HI _at_ 0x8705;
xdata UCHAR volatile SC_ACR_N_HVAL[3] _at_ 0x8706;
xdata UCHAR volatile SC_ACR_CTS_VALUE_LO _at_ 0x8709;
xdata UCHAR volatile SC_ACR_CTS_VALUE_MI _at_ 0x870A;
xdata UCHAR volatile SC_ACR_CTS_VALUE_HI _at_ 0x870B;
xdata UCHAR volatile SC_ACR_CTS_HVAL[3] _at_ 0x870C;
xdata UCHAR volatile SC_HDMI_RESET_CTRL _at_ 0x8713;
#if IS_NT68790_SERIES_LATER
xdata UCHAR volatile SC_VIDEO_HDCP_CTRL _at_ 0x8715;
xdata UCHAR volatile SC_AUDIO_HDCP_CTRL _at_ 0x8716;
#else
xdata UCHAR volatile SC_AUDIO_EXT_CAP_CTRL _at_ 0x8715;
xdata UCHAR volatile SC_AUDIO_HDCP_CTRL _at_ 0x8716;
#endif
xdata UCHAR volatile SC_AUDIO_HW_EXT_FS _at_ 0x8717;
xdata UCHAR volatile SC_AUDIO_DAC_DRIV_CTRL _at_ 0x8719;
xdata UCHAR volatile SC_AUDIO_SELECT _at_ 0x871A;
xdata UCHAR volatile SC_AUDIO_DELTA_SIGMA_GAIN_CTRL _at_ 0x871B;
xdata UCHAR volatile SC_AUDIO_OUTPUT_CTRL _at_ 0x871C;
xdata UCHAR volatile SC_AUDIO_DELTA_SIGMA_CTRL _at_ 0x871D;
xdata UCHAR volatile SC_AUDIO_TEST1 _at_ 0x8720;
xdata UCHAR volatile SC_AUDIO_OUT_CTRL _at_ 0x8721;
xdata UCHAR volatile SC_AUDIO_VOLUME_R _at_ 0x8722;
xdata UCHAR volatile SC_AUDIO_VOLUME_L _at_ 0x8723;
xdata UCHAR volatile SC_AUDIO_ANALOG_OUT_CTRL _at_ 0x8724;
xdata UCHAR volatile SC_AUDIO_SMOOTH _at_ 0x8725;
xdata UCHAR volatile SC_AUDIO_OUT_IIS_CTRL1 _at_ 0x8726;
xdata UCHAR volatile SC_AUDIO_OUT_IIS_CTRL2 _at_ 0x8727;
xdata UCHAR volatile SC_AUDIO_OUT_IIS_MAP _at_ 0x8728;
xdata UCHAR volatile SC_AUDIO_OUT_IIS_CTRL3 _at_ 0x8729;
xdata UCHAR volatile SC_AUDIO_CHANNEL_STATUS1 _at_ 0x872A;
xdata UCHAR volatile SC_AUDIO_IN_SPDIF_STATE4 _at_ 0x8730;
xdata UCHAR volatile SC_HDMI_DET _at_ 0x8734;
xdata UCHAR volatile SC_HDMI_PREAMBLE_CYCLE _at_ 0x8735;
xdata UCHAR volatile SC_HDMI_DATA_ALIGN _at_ 0x8736;
xdata UCHAR volatile SC_HDMI_MUTE _at_ 0x8737;
xdata UCHAR volatile SC_HDMI_BYPASS _at_ 0x873A;
xdata UCHAR volatile SC_PD_PMCLK _at_ 0x873E;
xdata UCHAR volatile SC_HDMI_AVI_TYPE _at_ 0x8740;
xdata UCHAR volatile SC_HDMI_AVI_VER _at_ 0x8741;
xdata UCHAR volatile SC_HDMI_AVI_LEM _at_ 0x8742;
xdata UCHAR volatile SC_HDMI_AVI_CKSM _at_ 0x8743;
xdata UCHAR volatile SC_HDMI_AVI[15] _at_ 0x8744;
xdata UCHAR volatile SC_INFO_FRAME_DB[27] _at_ 0x8764;
xdata UCHAR volatile SC_AUDIO_INFO_FRAME_DB[10] _at_ 0x8784;
xdata UCHAR volatile SC_FPGA_HDMI_DELAY _at_ 0x87F6;
xdata UCHAR volatile SC_VSI_PACKET[31] _at_ 0x8860;
xdata UCHAR volatile SC_CTRL_PACKET[9] _at_ 0x8880;
xdata UCHAR volatile SC_CP_PACKET_TYPE _at_ 0x889F;
xdata UCHAR volatile SC_DIG_AUDIO_GAIN_L_LO _at_ 0x88A0;
xdata UCHAR volatile SC_DIG_AUDIO_GAIN_L_HI _at_ 0x88A1;
xdata UCHAR volatile SC_DIG_AUDIO_GAIN_R_LO _at_ 0x88A2;
xdata UCHAR volatile SC_DIG_AUDIO_GAIN_R_HI _at_ 0x88A3;
xdata UCHAR volatile SC_DIG_L_OFFSET _at_ 0x88A4;
xdata UCHAR volatile SC_DIG_R_OFFSET _at_ 0x88A5;
xdata UCHAR volatile SC_AUDIO_AUTO_OFFSET_CTRL _at_ 0x88A6;
xdata UCHAR volatile SC_AUDIO_AUTO_CTRL1 _at_ 0x88A7;
xdata UCHAR volatile SC_AUDIO_AUTO_CTRL2 _at_ 0x88A8;
xdata UCHAR volatile SC_AUDIO_AUTO_CTRL3 _at_ 0x88A9;
xdata UCHAR volatile SC_AUDIO_AUTO_CTRL4 _at_ 0x88AA;
xdata UCHAR volatile SC_AUDIO_AUTO_CTRL8 _at_ 0x88AE;
xdata UCHAR volatile SC_AUDIO_AUTO_CTRL_8B0 _at_ 0x88B0;
xdata UCHAR volatile SC_AUDIO_AUTO_CTRL_8B3 _at_ 0x88B3;
xdata UCHAR volatile SC_AUDIO_AUTO_CTRL_8B5 _at_ 0x88B5;
xdata UCHAR volatile SC_FPGA_AUDIO_PLL _at_ 0x88C4;
xdata UCHAR volatile SC_HDCP_BKSV2 _at_ 0x8A9A;
xdata UCHAR volatile SC_HDCP_SLAVE_ADDR2 _at_ 0x8ABF;
xdata UCHAR volatile SC_EDP_PLL_LO _at_ 0x8B00;
xdata UCHAR volatile SC_EDP_PLL_MI _at_ 0x8B01;
xdata UCHAR volatile SC_EDP_PLL_HI _at_ 0x8B02;
xdata UCHAR volatile SC_EDP_PLL_CTRL _at_ 0x8B03;
xdata UCHAR volatile SC_MCU_PLL _at_ 0x8B04;
xdata UCHAR volatile SC_DVI_PLL_M _at_ 0x8B18;
xdata UCHAR volatile SC_VPLL_CTRL _at_ 0x8B19;
xdata UCHAR volatile SC_VPLL_CTRL1 _at_ 0x8B20;
xdata UCHAR volatile SC_VCLK_RATIO_LO _at_ 0x8B21;
xdata UCHAR volatile SC_VCLK_RATIO_MI _at_ 0x8B22;
xdata UCHAR volatile SC_VCLK_RATIO_HI _at_ 0x8B23;
xdata UCHAR volatile SC_MPLL_B2C _at_ 0x8B2C;
xdata UCHAR volatile SC_MCLK_RATIO_LO _at_ 0x8B31;
xdata UCHAR volatile SC_MCLK_RATIO_MI _at_ 0x8B32;
xdata UCHAR volatile SC_MCLK_RATIO_HI _at_ 0x8B33;
xdata UCHAR volatile SC_MCLK_SSC_CTRL _at_ 0x8B34;
xdata UCHAR volatile SC_FRC_RATIO_LO _at_ 0x8B38;
xdata UCHAR volatile SC_FRC_RATIO_MI _at_ 0x8B39;
xdata UCHAR volatile SC_FRC_RATIO_HI _at_ 0x8B3A;
xdata UCHAR volatile SC_MPLL_B3E _at_ 0x8B3E;
xdata UCHAR volatile SC_MPLL_B3F _at_ 0x8B3F;
xdata UCHAR volatile SC_MPLL_DIV _at_ 0x8B40;
xdata UCHAR volatile SC_MPLL_CTRL_B41 _at_ 0x8B41;
xdata UCHAR volatile SC_MPLL_CTRL_B42 _at_ 0x8B42;
xdata UCHAR volatile SC_MPLL_LDO_VADJ _at_ 0x8B43;
xdata UCHAR volatile SC_MPLL_B45 _at_ 0x8B45;
xdata UCHAR volatile SC_MPLL_X2 _at_ 0x8B46;
xdata UCHAR volatile SC_SSC_FDEV _at_ 0x8B47;
xdata UCHAR volatile SC_SSC_FMOD _at_ 0x8B48;
xdata UCHAR volatile SC_MCU_CLK_SSC _at_ 0x8B49;
xdata UCHAR volatile SC_EDP_CLK_SSC _at_ 0x8B4A;
xdata UCHAR volatile SC_EDP_MAN_CLK_SSC _at_ 0x8B4B;
xdata UCHAR volatile SC_EDP_MAN_CLK_SSC_RATIO _at_ 0x8B4C;
xdata UCHAR volatile SC_PLL_SYZ_PU _at_ 0x8B4D;
xdata UCHAR volatile SC_MMU_B4E _at_ 0x8B4E;
xdata UCHAR volatile SC_ACR_CLK_OUT_SEL _at_ 0x8B50;
xdata UCHAR volatile SC_APR_LDO_V_CTRL _at_ 0x8B53;
xdata UCHAR volatile SC_MCU_CLK_DIVIDER _at_ 0x8B54;
xdata UCHAR volatile SC_ZERO_POWER_LDO18 _at_ 0x8B55;
xdata UCHAR volatile SC_OSC_LDO18 _at_ 0x8B56;
xdata UCHAR volatile SC_ADC_ZERO_POWER_CTRL _at_ 0x8B57;
xdata UCHAR volatile SC_DVI_ZERO_POWER_CTRL _at_ 0x8B58;
xdata UCHAR volatile SC_DVI_ZERO_POWER_DETECT _at_ 0x8B59;
xdata UCHAR volatile SC_APR_LDO_CTRL _at_ 0x8B5A;
xdata UCHAR volatile SC_DVI1_ZERO_POWER_CTRL _at_ 0x8B5B;
xdata UCHAR volatile SC_DVI1_ZERO_POWER_DETECT _at_ 0x8B5C;
xdata UCHAR volatile SC_DVI2_ZERO_POWER_CTRL _at_ 0x8B5D;
xdata UCHAR volatile SC_DVI2_ZERO_POWER_DETECT _at_ 0x8B5E;
xdata UCHAR volatile SC_APR_ISOLATION _at_ 0x8B5F;
xdata UCHAR volatile SC_VGA_ADC_BIST _at_ 0x8B60;
xdata UCHAR volatile SC_ISOLATION_CONTROL _at_ 0x8B61;
xdata UCHAR volatile SC_CUT_POWER_CTRL _at_ 0x8B62;
xdata UCHAR volatile SC_ADC_LDO _at_ 0x8B63;
xdata UCHAR volatile SC_ZERO_PWR_CTRL_B64 _at_ 0x8B64;
xdata UCHAR volatile SC_ZERO_PWR_CTRL_B65 _at_ 0x8B65;
xdata UCHAR volatile SC_ZERO_PWR_CTRL_B66 _at_ 0x8B66;
xdata UCHAR volatile SC_ZERO_PWR_CTRL_B67 _at_ 0x8B67;
xdata UCHAR volatile SC_ZERO_PWR_CTRL_B68 _at_ 0x8B68;
xdata UCHAR volatile SC_ZERO_PWR_CTRL_B69 _at_ 0x8B69;

xdata UCHAR volatile SC_ADC_TRIM_CTRL _at_ 0x8B70;
xdata UCHAR volatile SC_ADC_CTRL_OPTION1 _at_ 0x8B78;
xdata UCHAR volatile SC_ADC_CTRL_OPTION2 _at_ 0x8B79;
xdata UCHAR volatile SC_ADC_CTRL_OPTION3 _at_ 0x8B7A;
xdata UCHAR volatile SC_MMU_DLL_CTRL _at_ 0x8B80;
xdata UCHAR volatile SC_MMU_DLL_INF _at_ 0x8B81;
xdata UCHAR volatile SC_MMU_B82 _at_ 0x8B82;
xdata UCHAR volatile SC_MMU_B83 _at_ 0x8B83;
xdata UCHAR volatile SC_MMU_B84 _at_ 0x8B84;
xdata UCHAR volatile SC_MMU_B85 _at_ 0x8B85;

xdata UCHAR volatile SC_MMU_DLL_PHASE_CTRL0 _at_ 0x8B86;
#if IS_NT68850_SERIES
xdata UCHAR volatile SC_DP_MASK_AUX_I2C_RW_SEL _at_ 0x8B87;
xdata UCHAR volatile SC_DP_FAST_MUTE_CTRL _at_ 0x8B88;
xdata UCHAR volatile SC_DP_VS_BLANK_CNT_LO _at_ 0x8B89;
xdata UCHAR volatile SC_DP_AUX_CTRL2 _at_ 0x8B8A;
#else
xdata UCHAR volatile SC_MMU_DLL_PHASE_CTRL1 _at_ 0x8B87;
xdata UCHAR volatile SC_MMU_DLL_PHASE_CTRL2 _at_ 0x8B88;
xdata UCHAR volatile SC_MMU_DLL_PHASE_CTRL3 _at_ 0x8B89;
xdata UCHAR volatile SC_MMU_PLL_SPLL7 _at_ 0x8B8A;
#endif

xdata UCHAR volatile SC_MMU_PLL_SKEW0 _at_ 0x8B8B;
xdata UCHAR volatile SC_MMU_PLL_SKEW1 _at_ 0x8B8C;
xdata UCHAR volatile SC_MMU_PLL_SKEW2 _at_ 0x8B8D;
xdata UCHAR volatile SC_MMU_PLL_SKEW3 _at_ 0x8B8E;
xdata UCHAR volatile SC_MMU_PLL_SKEW4 _at_ 0x8B8F;
xdata UCHAR volatile SC_MMU_PLL_SKEW5 _at_ 0x8B90;
xdata UCHAR volatile SC_MMU_PLL_SKEW6 _at_ 0x8B91;
xdata UCHAR volatile SC_MMU_PLL_SKEW7 _at_ 0x8B92;
xdata UCHAR volatile SC_PREFRC_CLOCK_DIV _at_ 0x8BA0;
xdata UCHAR volatile SC_FRC_CLOCK_SEL _at_ 0x8BA2;
xdata UCHAR volatile SC_LDO_2V5_CTRL_BD2 _at_ 0x8BD2;

xdata UCHAR volatile SC_CEC_CTRL _at_ 0x8C00;
xdata UCHAR volatile SC_CEC_CLK_BASE _at_ 0x8C01;
xdata UCHAR volatile SC_CEC_FREE_CNT1 _at_ 0x8C02;
xdata UCHAR volatile SC_CEC_RETRY _at_ 0x8C03;
xdata UCHAR volatile SC_CEC_TXR_OFFSET _at_ 0x8C04;
xdata UCHAR volatile SC_CEC_TXF_OFFSET _at_ 0x8C05;
xdata UCHAR volatile SC_CEC_SBIT_RANGE _at_ 0x8C06;
xdata UCHAR volatile SC_CEC_RXD_RANGE _at_ 0x8C07;
xdata UCHAR volatile SC_CEC_RX_SMP _at_ 0x8C08;
xdata UCHAR volatile SC_CEC_DEGLITCH _at_ 0x8C09;
xdata UCHAR volatile SC_CEC_RXL_ERROR _at_ 0x8C0A;
xdata UCHAR volatile SC_CEC_RXH_ERROR _at_ 0x8C0B;
xdata UCHAR volatile SC_CEC_INT_EN _at_ 0x8C0C;
xdata UCHAR volatile SC_CEC_INT_FLAG _at_ 0x8C0D;
xdata UCHAR volatile SC_CEC_DEBUG _at_ 0x8C0E;
xdata UCHAR volatile SC_CEC_RX_LENGTH _at_ 0x8C0F;
xdata UCHAR volatile SC_CEC_TX_LENGTH _at_ 0x8C10;
xdata UCHAR volatile SC_CEC_FILTER _at_ 0x8C11;
xdata UCHAR volatile SC_CEC_TX_HEAD _at_ 0x8C20;
xdata UCHAR volatile SC_CEC_TX_DATA[16] _at_ 0x8C21;
xdata UCHAR volatile SC_CEC_RX_HEAD _at_ 0x8C31;
xdata UCHAR volatile SC_CEC_RX_DATA[16] _at_ 0x8C32;
xdata UCHAR volatile SC_3D_SHUTTER_GLASS_CTRL[32] _at_ 0x8C50;
xdata UCHAR volatile SC_MCU_IO_CTRL0 _at_ 0x8C7F;
xdata UCHAR volatile SC_MCU_IO_CTRL1 _at_ 0x8C80;
xdata UCHAR volatile SC_MCU_IO_CTRL2 _at_ 0x8C81;
xdata UCHAR volatile SC_MCU_IO_CTRL3 _at_ 0x8C82;
xdata UCHAR volatile SC_MCU_IO_CTRL4 _at_ 0x8C83;
xdata UCHAR volatile SC_MCU_IO_CTRL5 _at_ 0x8C84;
xdata UCHAR volatile SC_MCU_IO_CTRL6 _at_ 0x8C85;
xdata UCHAR volatile SC_MCU_IO_CTRL7 _at_ 0x8C86;
xdata UCHAR volatile SC_MCU_IO_CTRL8 _at_ 0x8C87;
xdata UCHAR volatile SC_MCU_IO_CTRL9 _at_ 0x8C88;

xdata UCHAR volatile SC_OSD_FRAME2_FUNC_CTRL _at_ 0x8D00;
xdata UCHAR volatile SC_OSD_FRAME2_ADDR_LO _at_ 0x8D01;
xdata UCHAR volatile SC_OSD_FRAME2_ADDR_HI _at_ 0x8D02;
xdata UCHAR volatile SC_OSD_WIN_HOR_START_LO _at_ 0x8D03;
xdata UCHAR volatile SC_OSD_WIN_HOR_END_LO _at_ 0x8D04;
xdata UCHAR volatile SC_OSD_WIN_HOR_HI _at_ 0x8D05;
xdata UCHAR volatile SC_OSD_WIN_VER_START_LO _at_ 0x8D06;
xdata UCHAR volatile SC_OSD_WIN_VER_END_LO _at_ 0x8D07;
xdata UCHAR volatile SC_OSD_WIN_VER_HI _at_ 0x8D08;
xdata UCHAR volatile SC_OSD_WIN_GRADIENT_CTRL _at_ 0x8D30;
xdata UCHAR volatile SC_OSD_WIN_GRADIENT_RED_COLOR _at_ 0x8D31;
xdata UCHAR volatile SC_OSD_WIN_GRADIENT_GREEN_COLOR _at_ 0x8D32;
xdata UCHAR volatile SC_OSD_WIN_GRADIENT_BLUE_COLOR _at_ 0x8D33;
xdata UCHAR volatile SC_OSD_WIN_GRADIENT_RED_STEP _at_ 0x8D34;
xdata UCHAR volatile SC_OSD_WIN_GRADIENT_GREEN_STEP _at_ 0x8D35;
xdata UCHAR volatile SC_OSD_WIN_GRADIENT_BLUE_STEP _at_ 0x8D36;
xdata UCHAR volatile SC_OSD_WIN_GRADIENT_COLOR_FRONTGROUND _at_ 0x8D37;

xdata UCHAR volatile SC_HDCP_TRIM_CTRL _at_ 0x8D50;
xdata UCHAR volatile SC_HDCP_TRIM_ADDR _at_ 0x8D51;
xdata UCHAR volatile SC_HDCP_TRIM_DATA_LO _at_ 0x8D52;
xdata UCHAR volatile SC_HDCP_TRIM_DATA_HI _at_ 0x8D53;
xdata UCHAR volatile SC_HDCP_TRIM_CTRL2 _at_ 0x8D55;
xdata UCHAR volatile SC_HDCP_TRIM_TEST_MODE _at_ 0x8D58;
xdata UCHAR volatile SC_HDCP_TRIM_ADDR_A _at_ 0x8D5B;
xdata UCHAR volatile SC_HDCP_TRIM_ADDR_B _at_ 0x8D5C;
xdata UCHAR volatile SC_HDCP_TRIM_PI _at_ 0x8D5F;




xdata UCHAR volatile SC_LEDDRIVER_ENABLE _at_ 0x8E00;
xdata UCHAR volatile SC_LED_PROTECT_CTRL1 _at_ 0x8E02;
xdata UCHAR volatile SC_LED_PROTECT_CTRL2 _at_ 0x8E07;
xdata UCHAR volatile SC_LED_SHORT_CTRL _at_ 0x8E06;
xdata UCHAR volatile SC_ADC_LDO_TRIM _at_ 0x8E0C;
xdata UCHAR volatile SC_LEDDIMMING_CTRL _at_ 0x8E12;
xdata UCHAR volatile SC_LED_OPEN_STATUS _at_ 0x8E13;
xdata UCHAR volatile SC_LED_SHORT_STATUS _at_ 0x8E14;
xdata UCHAR volatile SC_LEDSTATUS _at_ 0x8E15;
xdata UCHAR volatile SC_LEDPROTECT_ENABLE _at_ 0x8E1B;
xdata UCHAR volatile SC_TRIMMING_CONTROL _at_ 0x8E20;
xdata UCHAR volatile SC_VREF_VOLTAGE_MODE1 _at_ 0x8E22;
xdata UCHAR volatile SC_VREF_VOLTAGE_MODE2 _at_ 0x8E23;
xdata UCHAR volatile SC_VREF_VOLTAGE_MODE3 _at_ 0x8E24;
xdata UCHAR volatile SC_DC2DC_E30 _at_ 0x8E30;
xdata UCHAR volatile SC_DC2DC_E33 _at_ 0x8E33;
xdata UCHAR volatile SC_LED_TRIM_E36 _at_ 0x8E36;
xdata UCHAR volatile SC_LED_TRIM_E37 _at_ 0x8E37;
xdata UCHAR volatile SC_DC2DC_E39 _at_ 0x8E39;
xdata UCHAR volatile SC_DC2DC_E3A _at_ 0x8E3A;
xdata UCHAR volatile SC_DC2DC_E3B _at_ 0x8E3B;
xdata UCHAR volatile SC_DC2DC_E3C _at_ 0x8E3C;
xdata UCHAR volatile SC_DC2DC_E3D _at_ 0x8E3D;
xdata UCHAR volatile SC_DC2DC_E3E _at_ 0x8E3E;
xdata UCHAR volatile SC_DC2DC_E3F _at_ 0x8E3F;
//Local Dimming
xdata UCHAR volatile SC_LD_CONTROL _at_ 0x8E40;
xdata UCHAR volatile SC_LD_POSTGAIN _at_ 0x8E46;
xdata UCHAR volatile SC_LD_POSTDUTY _at_ 0x8E47;
xdata UCHAR volatile SC_LD_CTRL _at_ 0x8E50;
xdata UCHAR volatile SC_LD_LEFT_BOUND_LO _at_ 0x8E52;
xdata UCHAR volatile SC_LD_LEFT_BOUND_HI _at_ 0x8E53;
xdata UCHAR volatile SC_LD_RIGHT_BOUND_LO _at_ 0x8E54;
xdata UCHAR volatile SC_LD_RIGHT_BOUND_HI _at_ 0x8E55;
xdata UCHAR volatile SC_LD_TOP_BOUND_LO _at_ 0x8E56;
xdata UCHAR volatile SC_LD_TOP_BOUND_HI _at_ 0x8E57;
xdata UCHAR volatile SC_LD_BOTTOM_BOUND_LO _at_ 0x8E58;
xdata UCHAR volatile SC_LD_BOTTOM_BOUND_HI _at_ 0x8E59;
xdata UCHAR volatile SC_LD_INC_SPEED _at_ 0x8E6E;
xdata UCHAR volatile SC_LD_DEC_SPEED _at_ 0x8E6F;
xdata UCHAR volatile SC_LD_BLOCK_WIDTH_LO _at_ 0x8E5A;
xdata UCHAR volatile SC_LD_BLOCK_WIDTH_HI _at_ 0x8E5B;
xdata UCHAR volatile SC_LD_BLOCK_HEIGHT_LO _at_ 0x8E5C;
xdata UCHAR volatile SC_LD_BLOCK_HEIGHT_HI _at_ 0x8E5D;
xdata UCHAR volatile SC_LD_ZONE_PITCH _at_ 0x8E5E;
xdata UCHAR volatile SC_LD_ABRUPT_CHANGE_CRTL _at_ 0x8E5F;

xdata UCHAR volatile SC_LD_BE_WIDTH _at_ 0x8E61;
xdata UCHAR volatile SC_LD_BE_HEIGHT _at_ 0x8E62;
xdata UCHAR volatile SC_LD_BE_HBOUND_LO _at_ 0x8E63;
xdata UCHAR volatile SC_LD_BE_VBOUND_LO _at_ 0x8E64;
xdata UCHAR volatile SC_LD_BE_HVBOUND_HI _at_ 0x8E65;
xdata UCHAR volatile SC_LD_BE_OFFSET_LO _at_ 0x8E66;
xdata UCHAR volatile SC_LD_BE_PITCH_LO _at_ 0x8E67;
xdata UCHAR volatile SC_LD_BE_OFFSET_PITCH_HI _at_ 0x8E68;

xdata UCHAR volatile SC_LD_PWMA_CTRL1 _at_ 0x8E6A;
xdata UCHAR volatile SC_LD_PWMA_CTRL2 _at_ 0x8E6B;
xdata UCHAR volatile SC_LD_PWMA_CTRL3 _at_ 0x8E6C;

xdata UCHAR volatile SC_LD_DUTY_CONTROL1 _at_ 0x8E71;
xdata UCHAR volatile SC_LD_PORT_INDEX _at_ 0x8E74;
xdata UCHAR volatile SC_LD_GRAY_TO_DUTY_TABLE _at_ 0x8E75;
xdata UCHAR volatile SC_LD_LIGHT_PROFILE_TABLE _at_ 0x8E76;
xdata UCHAR volatile SC_LD_LV_TO_GAIN_TABLE _at_ 0x8E77;
xdata UCHAR volatile SC_LD_INDEX_PORT_ADDRESS_LO _at_ 0x8E7B;
xdata UCHAR volatile SC_LD_INDEX_PORT_ADDRESS_HI _at_ 0x8E7C;

xdata UCHAR volatile SC_LD_MODE_CTRL _at_ 0x8E80;
xdata UCHAR volatile SC_LD_ADPS_CTRL _at_ 0x8E81;
xdata UCHAR volatile SC_LD_DUTY_SPEED_CTRL _at_ 0x8E83;
xdata UCHAR volatile SC_LD_MIN_DUTY _at_ 0x8E85;
xdata UCHAR volatile SC_LD_BRIGHTNESS _at_ 0x8E86;
    
xdata UCHAR volatile SC_LD_DYNAMIC_FRAME_THR _at_ 0x8E88;

xdata UCHAR volatile SC_LD_AOS_THRESHOLD_HI _at_ 0x8E8B;
xdata UCHAR volatile SC_LD_AOS_THRESHOLD_LO _at_ 0x8E8C;

xdata UCHAR volatile SC_LD_DUTY_CONTROL3 _at_ 0x8E91;
xdata UCHAR volatile SC_LD_HBLK_WIDTH_LO _at_ 0x8E92;
xdata UCHAR volatile SC_LD_HBLK_WIDTH_HI _at_ 0x8E93;
xdata UCHAR volatile SC_LD_VBLK_HEIGHT_LO _at_ 0x8E94;
xdata UCHAR volatile SC_LD_VBLK_HEIGHT_HI _at_ 0x8E95;
xdata UCHAR volatile SC_LD_H_ZONE_NUM _at_ 0x8E96;
xdata UCHAR volatile SC_LD_V_ZONE_NUM _at_ 0x8E97;
xdata UCHAR volatile SC_LD_DIM_DEFINE_CTRL _at_ 0x8E98;


xdata UCHAR volatile SC_SR_CTRL _at_ 0x8EA0;
//FLT1 median Filter
xdata UCHAR volatile FLT1_TH _at_ 0x8EA4;
xdata UCHAR volatile FLT1_CUT_SLOP _at_ 0x8EA5;
xdata UCHAR volatile FLT1_SLOP_TH _at_ 0x8EA6;
xdata UCHAR volatile FLT1_VAR_TH_LO _at_ 0x8EA7;
xdata UCHAR volatile FLT1_SLOP_VAR_TH_HI _at_ 0x8EA8;

xdata UCHAR volatile FLT3_MAX_VAR_LO _at_ 0x8EAC;
xdata UCHAR volatile FLT3_MAX_VAR_HI _at_ 0x8EAD;
xdata UCHAR volatile FLT3_MEAN_VAR_LO _at_ 0x8EAE;
xdata UCHAR volatile FLT3_MEAN_VAR_HI _at_ 0x8EAF;

//FLT3 USM
xdata UCHAR volatile FLT3_CORING_TH _at_ 0x8EB0;
xdata UCHAR volatile FLT3_GAIN _at_ 0x8EB1;
xdata UCHAR volatile FLT3_COEFFICENT[12] _at_ 0x8EB2;

//FLT3 Source Select
xdata UCHAR volatile FLT3_ADD_SUB_SOURCE _at_ 0x8EC0;
xdata UCHAR volatile FLT3_BRIGHT_DARK_SOURCE _at_ 0x8EC1;

xdata UCHAR volatile FLT3_BRIGHT_DARK_SLOP _at_ 0x8EC2;
xdata UCHAR volatile FLT3_CORING_SLOP _at_ 0x8EC3;
//FLT3 USM Demo
xdata UCHAR volatile USM_DEMO_MODE _at_ 0x8EC4;
xdata UCHAR volatile USM_DEMO_WIDTH_LO _at_ 0x8EC5;
xdata UCHAR volatile USM_DEMO_WIDTH_HI _at_ 0x8EC6;

xdata UCHAR volatile FLT1_CONTROL1 _at_ 0x8ECC;
xdata UCHAR volatile FLT1_CONTROL2 _at_ 0x8ECD;

//FLT3 Coring curve
xdata UCHAR volatile FLT3_CORING_UP_LOW_TH _at_ 0x8ED0;
xdata UCHAR volatile FLT3_COR_VAR_TH_LO _at_ 0x8ED1;
xdata UCHAR volatile FLT3_COR_VAR_TH_HI_SLOP _at_ 0x8ED2;
//FLT3 Gain curve
xdata UCHAR volatile FLT3_GAIN_UP_LOW_TH _at_ 0x8ED3;
xdata UCHAR volatile FLT3_GAIN_VAR_TH_LO _at_ 0x8ED4;
xdata UCHAR volatile FLT3_GAIN_VAR_TH_HI_SLOP _at_ 0x8ED5;

//FLT3 Low Pass Control
xdata UCHAR volatile FLT3_LP_VAR_TH_LO _at_ 0x8ED6;
xdata UCHAR volatile FLT3_LP_VAR_TH_HI_SLOP _at_ 0x8ED7;

xdata UCHAR volatile FLT1_CONTROL_THR _at_ 0x8ED8;

xdata UCHAR volatile SC_SR_HTOTAL_LO _at_ 0x8EE0;
xdata UCHAR volatile SC_SR_HTOTAL_HI _at_ 0x8EE1;
xdata UCHAR volatile SC_SR_HACT_LO _at_ 0x8EE2;
xdata UCHAR volatile SC_SR_HACT_HI _at_ 0x8EE3;
xdata UCHAR volatile SC_SR_VACT_LO _at_ 0x8EE4;
xdata UCHAR volatile SC_SR_VACT_HI _at_ 0x8EE5;
xdata UCHAR volatile SC_SR_HBACKPORCH _at_ 0x8EE6;
xdata UCHAR volatile SC_SR_PIPEDELAY _at_ 0x8EE7;

xdata UCHAR volatile SC_SR_CONTROL _at_ 0x8EE8;
xdata UCHAR volatile SC_DP_FPGA_CTRL1 _at_ 0x8F0B;
xdata UCHAR volatile SC_DP_FPGA_CTRL2 _at_ 0x8F0C;

//DisplayPort
#define DPLinkLayer_Page      0x9000

xdata UCHAR volatile SC_DP_1000 _at_ 0x9000;
xdata UCHAR volatile SC_DP_1001 _at_ 0x9001;
xdata UCHAR volatile SC_DP_VIDEO_FIFO_MODE4_ADAPTIVE_CTRL _at_ 0x9003;
xdata UCHAR volatile SC_DP_MANUAL_MAUD_HI _at_ 0x900F;
xdata UCHAR volatile SC_DP_MANUAL_MAUD_MI _at_ 0x9010;
xdata UCHAR volatile SC_DP_MANUAL_MAUD_LO _at_ 0x9011;
xdata UCHAR volatile SC_DP_MANUAL_NAUD_HI _at_ 0x9012;
xdata UCHAR volatile SC_DP_MANUAL_NAUD_MI _at_ 0x9013;
xdata UCHAR volatile SC_DP_MANUAL_NAUD_LO _at_ 0x9014;
xdata UCHAR volatile SC_DP_AUX_DETECT _at_ 0x901A;
xdata UCHAR volatile SC_DP_AUX_PULSEWIDTH_LO_THD _at_ 0x901B;
xdata UCHAR volatile SC_DP_AUX_PULSEWIDTH_HI_THD _at_ 0x901C;
xdata UCHAR volatile SC_DP_AUX_PRECHARGE_NUM _at_ 0x901D;
xdata UCHAR volatile SC_DP_RESET_FUNCTION _at_ 0x9020;
xdata UCHAR volatile AUX_I2C_MANUAL	_at_ 0x9024;
xdata UCHAR volatile AUX_I2C_DATA _at_ 0x9025;	
xdata UCHAR volatile SC_DP_SCL_HI_HALF_WIDTH _at_ 0x9026;
xdata UCHAR volatile SC_DP_SCL_HI_WIDTH _at_ 0x9027;
xdata UCHAR volatile SC_DP_SDA_SETUP _at_ 0x9028;
xdata UCHAR volatile SC_DP_SDA_HOLD _at_ 0x9029;
xdata UCHAR volatile SC_DP_AUX_I2C_CTRL _at_ 0x902A;
xdata UCHAR volatile SC_DP_TX_PRE_CHG_NUM _at_ 0x902B;
xdata UCHAR volatile SC_DP_RX_PRE_CHG_NUM _at_ 0x902C;
#if IS_NT68790_SERIES || IS_NT68810_SERIES || IS_NT68870_SERIES
xdata UCHAR volatile SC_DP_AUX_I2C_CTRL2 _at_ 0x902E;
#endif
xdata UCHAR volatile SC_DP_102F _at_ 0x902F;
xdata UCHAR volatile SC_DP_DEBUG _at_ 0x9030;
xdata UCHAR volatile SC_DP_HDCP_CTRL _at_ 0x9032;
xdata UCHAR volatile SC_DP_ERR_DET_CTRL _at_ 0x9033;
xdata UCHAR volatile SC_DP_CERR_RANGE _at_ 0x9034;
xdata UCHAR volatile SC_DP_ERR_DET_DISABLE _at_ 0x9037;
xdata UCHAR volatile SC_DP_1039 _at_ 0x9039;
xdata UCHAR volatile SC_DP_HPD_IRQ_WIDTH _at_ 0x903A;
xdata UCHAR volatile SC_DP_MN_CTRL _at_ 0x903F;
xdata UCHAR volatile SC_DP_CSC_AUTO_CONF _at_ 0x9040;
xdata UCHAR volatile SC_DP_1043 _at_ 0x9043;
xdata UCHAR volatile SC_DP_VIDEO_FIFO_INT _at_ 0x9044;
xdata UCHAR volatile SC_DP_TEST_FIFO_MAX_LENGTH _at_ 0x9045;
xdata UCHAR volatile SC_DP_VIDEO_CONTROL _at_ 0x9046;
xdata UCHAR volatile SC_DP_DE_START_POS _at_ 0x9047;
xdata UCHAR volatile SC_DP_DE_IN_COUNT_POS_LO _at_ 0x9048;
xdata UCHAR volatile SC_DP_DE_IN_COUNT_POS_HI _at_ 0x9049;
xdata UCHAR volatile SC_DP_HV_MISC_CTRL _at_ 0x904D;    // 20160202 Yung Add

xdata UCHAR volatile SC_DP_AUDIO_FIFO_CTRL _at_ 0x9050;
xdata UCHAR volatile SC_DP_AUDIO_ERROR_FLAG _at_ 0x9054;
xdata UCHAR volatile SC_DP_I2S_CTRL _at_ 0x9055;
xdata UCHAR volatile SC_DP_CLK_CYCLE_VALUE _at_ 0x9057;
xdata UCHAR volatile SC_DP_SPDIF_CTRL _at_ 0x9058;
xdata UCHAR volatile SC_DP_DSD_CTRL _at_ 0x9059;
xdata UCHAR volatile SC_DP_AUDIO_DAC_CTRL _at_ 0x905A;
xdata UCHAR volatile SC_DP_INT_GROUP_0 _at_ 0x9073;
xdata UCHAR volatile SC_DP_INT_GROUP_1 _at_ 0x9074;
xdata UCHAR volatile SC_DP_INT_GROUP_2 _at_ 0x9075;
xdata UCHAR volatile SC_DP_INT_GROUP_3 _at_ 0x9076;
xdata UCHAR volatile SC_DP_INT_GROUP_4 _at_ 0x9077;
xdata UCHAR volatile SC_DP_MISC_CTRL _at_ 0x9080;
xdata UCHAR volatile SC_DP_PLL_CTRL _at_ 0x9081;
xdata UCHAR volatile SC_DP_PLL_M_VID_HI _at_ 0x9082;
xdata UCHAR volatile SC_DP_PLL_M_VID_MI  _at_ 0x9083;
xdata UCHAR volatile SC_DP_PLL_M_VID_LO  _at_ 0x9084;
xdata UCHAR volatile SC_DP_PLL_N_VID_HI _at_ 0x9085;
xdata UCHAR volatile SC_DP_PLL_N_VID_MI _at_ 0x9086;
xdata UCHAR volatile SC_DP_PLL_N_VID_LO _at_ 0x9087;
xdata UCHAR volatile SC_DP_1089 _at_ 0x9089;
xdata UCHAR volatile SC_DP_108A _at_ 0x908A;
xdata UCHAR volatile SC_DP_108B _at_ 0x908B;
xdata UCHAR volatile SC_DP_108C _at_ 0x908C;
xdata UCHAR volatile SC_DP_MSA_MISC0 _at_ 0x908D;
xdata UCHAR volatile SC_DP_MSA_MISC1 _at_ 0x908E;
xdata UCHAR volatile SC_DP_MSA_VBID _at_ 0x908F;

xdata UCHAR volatile SC_DP_HTOTAL_LO _at_ 0x9090;
xdata UCHAR volatile SC_DP_HTOTAL_HI _at_ 0x9091;
xdata UCHAR volatile SC_DP_VTOTAL_LO _at_ 0x9092;
xdata UCHAR volatile SC_DP_VTOTAL_HI _at_ 0x9093;
xdata UCHAR volatile SC_DP_109D _at_ 0x909D;
xdata UCHAR volatile SC_DP_109E _at_ 0x909E;
xdata UCHAR volatile SC_DP_AUX_CTRL _at_ 0x90B8;
xdata UCHAR volatile SC_DP_M_LSB_CROSS_TH _at_ 0x90BC;

xdata UCHAR volatile SC_DP_10C0 _at_ 0x90C0;
xdata UCHAR volatile SC_DP_10C1 _at_ 0x90C1;
xdata UCHAR volatile SC_DP_10C2 _at_ 0x90C2;
xdata UCHAR volatile SC_DP_10C8 _at_ 0x90C8;
xdata UCHAR volatile SC_DP_TEST_MODE_EN _at_ 0x90CE;
#if IS_NT68810_SERIES
xdata UCHAR volatile SC_DP_CRPLL _at_ 0x90D1;
#else
xdata UCHAR volatile SC_DP_CRPLL _at_ 0x96D1;
#endif
xdata UCHAR volatile SC_DP_PORT_SEL _at_ 0x90E7;
xdata UCHAR volatile SC_DP_ZP_DP _at_ 0x90E8;

xdata UCHAR volatile SC_DP_10F1 _at_ 0x90F1;
xdata UCHAR volatile SC_DP_10F2 _at_ 0x90F2;
xdata UCHAR volatile SC_DP_10F3 _at_ 0x90F3;
xdata UCHAR volatile SC_DP_10F4 _at_ 0x90F4;
xdata UCHAR volatile SC_DP_10F5 _at_ 0x90F5;
xdata UCHAR volatile AUX_STROBE_CTL	_at_ 0x90F7;
xdata UCHAR volatile SC_DP_DPCD_00000 _at_ 0x9100;
xdata UCHAR volatile SC_DP_DPCD_00001 _at_ 0x9101;
xdata UCHAR volatile SC_DP_DPCD_00002 _at_ 0x9102;
xdata UCHAR volatile SC_DP_DPCD_00003 _at_ 0x9103;
xdata UCHAR volatile SC_DP_DPCD_00004 _at_ 0x9104;
xdata UCHAR volatile SC_DP_DPCD_00006 _at_ 0x9106;
xdata UCHAR volatile SC_DP_DPCD_00007 _at_ 0x9107;
xdata UCHAR volatile SC_DP_DPCD_00101 _at_ 0x911D;
xdata UCHAR volatile SC_DP_DPCD_00107 _at_ 0x9123;
xdata UCHAR volatile SC_DP_DPCD_00200 _at_ 0x9125;
xdata UCHAR volatile SC_DP_DPCD_00201 _at_ 0x9126;
xdata UCHAR volatile SC_DP_DPCD_00246 _at_ 0x9152;
xdata UCHAR volatile SC_DP_DPCD_00600 _at_ 0x9160;
xdata UCHAR volatile SC_DP_DPCD_0000D _at_ 0x9161;
xdata UCHAR volatile SC_DP_HDCP_BKSV _at_ 0x9180;
xdata UCHAR volatile AUX_STROBE_FUN _at_ 0x9200;
xdata UCHAR volatile AUX_STROBE_CNT _at_ 0x9201;
xdata UCHAR volatile AUX_STROBE_PORT _at_ 0x9202;
xdata UCHAR volatile DP_SC_REG_1224 _at_ 0x9224;
	#define MASK_NATIVE_AUX			BIT7		// 0: enable NATIVE_AUX data to strobe, 1: Mask NATIVE_AUX data to strobe
xdata UCHAR volatile SC_DP_CERR_RST_APHY_RANGE _at_ 0x9231;
xdata UCHAR volatile SC_DP_CERR_CLR_PHY_RANGE _at_ 0x9232;
xdata UCHAR volatile SC_DP_CERR_NO_LINK_RANGE _at_ 0x9233;
xdata UCHAR volatile SC_DP_CERR_NO_LINK_BS_RANGE _at_ 0x9234;
xdata UCHAR volatile SC_DP_CERR_DET_THRESHOLD _at_ 0x9237;
xdata UCHAR volatile SC_EDP_LINK_1300[256] _at_ 0x9300;

// Yung:DP APHY and DPHY control register
xdata UCHAR volatile SC_DPpp_CFG_TMDS_1700[768] _at_ 0x9700;//0x1700 ~ 0x19FF
xdata UCHAR volatile SC_DPpp_CFG_TMDS_1A00[768] _at_ 0x9A00;//0x1A00 ~ 0x1CFF
xdata UCHAR volatile SC_LVDS_1D00[128] _at_ 0x9D00;//0x9D00 ~ 0x9D7F
xdata UCHAR volatile SC_ADC_IP_CTRL_1D80[80] _at_ 0x9D80;//0x8000 ~ 0x8023
xdata UCHAR volatile SC_TMDS_PHY_LINK_CTRL_1DE0 _at_ 0x9DE0;
xdata UCHAR volatile SC_TMDS_PHY_LINK_CTRL_1DE1 _at_ 0x9DE1;
xdata UCHAR volatile SC_COMBO_TX_1E00[128] _at_ 0x9E00;//0x9E00 ~ 0x9E78 APHY
xdata UCHAR volatile SC_EDP_TX_DPHY_1F00[128] _at_ 0x9F00;//0x9F00 ~ 0x9E78 DPHY

xdata UCHAR volatile SC_DP_AUDIO_16D6 _at_ 0x96D6;


// 20150925 Yung add for USB Type C control register 
//#define USBTypec_Page      0x8D00
// 20151123 FPGA code change USB TypeC Register page to 0x16
// and NT68870 Chip also use Page 0x16 as PD control register
#define USBTypec_Page      0x9600

xdata UCHAR volatile SC_USBC_CC_CFG _at_ USBTypec_Page+0x60;
xdata UCHAR volatile SC_USBC_CC_RESET_CTRL _at_ USBTypec_Page+0x61;
xdata UCHAR volatile SC_USBC_CC_REF_CLK_SET _at_ USBTypec_Page+0x62;
xdata UCHAR volatile SC_USBC_CC_FILTER_LENGTH _at_ USBTypec_Page+0x63;
xdata UCHAR volatile SC_USBC_CC_IDLE_DET_CTRL _at_ USBTypec_Page+0x64;
xdata UCHAR volatile SC_USBC_CC_IDLE_DET_WINDOW _at_ USBTypec_Page+0x65;
xdata UCHAR volatile SC_USBC_CC_INT_RTX_FSM_READ _at_ USBTypec_Page+0x66;

xdata UCHAR volatile SC_USBC_CC_BIST_CTRL _at_ USBTypec_Page+0x68;
xdata UCHAR volatile SC_USBC_CC_BIST_ENTER_HOLD_TIME _at_ USBTypec_Page+0x69;

xdata UCHAR volatile SC_USBC_CC_HPDPD_CTRL1 _at_ USBTypec_Page+0x6A;
xdata UCHAR volatile SC_USBC_CC_HPDPD_CTRL2 _at_ USBTypec_Page+0x6B;
xdata UCHAR volatile SC_USBC_CC_TEST_MODE1 _at_ USBTypec_Page+0x6E;
xdata UCHAR volatile SC_USBC_CC_TEST_MODE2 _at_ USBTypec_Page+0x6F;
xdata UCHAR volatile SC_USBC_CC_TX_BIT_TIME _at_ USBTypec_Page+0x70;
xdata UCHAR volatile SC_USBC_CC_TX_PREAMBLE_NUM _at_ USBTypec_Page+0x71;
xdata UCHAR volatile SC_USBC_CC_TX_CTRL_CONFLICT _at_ USBTypec_Page+0x72;



xdata UCHAR volatile SC_USBC_CC_TX_HOLD_TIME _at_ USBTypec_Page+0x73;
xdata UCHAR volatile SC_USBC_CC_RTX_INOUT_CONFLICT_MASK _at_ USBTypec_Page+0x74;

// 
xdata UCHAR volatile SC_USBC_CC_TX_AUTO_MSGID _at_ USBTypec_Page+0x75;
xdata UCHAR volatile SC_USBC_CC_TX_ITF_GAP_HBYTE _at_ USBTypec_Page+0x76;
xdata UCHAR volatile SC_USBC_CC_TX_ITF_GAP_LBYTE _at_ USBTypec_Page+0x77;

xdata UCHAR volatile SC_USBC_CC_RX_AUTO_BIT_TIME _at_ USBTypec_Page+0x78;
xdata UCHAR volatile SC_USBC_CC_RX_AUTO_BIT_TIME_LENGTH _at_ USBTypec_Page+0x79;
xdata UCHAR volatile SC_USBC_CC_RX_BIT_TIME_LOW_TH _at_ USBTypec_Page+0x7A;
xdata UCHAR volatile SC_USBC_CC_RX_BIT_TIME_HIGH_TH _at_ USBTypec_Page+0x7B;
xdata UCHAR volatile SC_USBC_CC_RX_CTRL2 _at_ USBTypec_Page+0x7C;

xdata UCHAR volatile SC_USBC_CC_RX_CMD_GATE _at_ USBTypec_Page+0x7D;
xdata UCHAR volatile SC_USBC_CC_RX_AUTO_REPLY_ENABLE _at_ USBTypec_Page+0x7E;
xdata UCHAR volatile SC_USBC_CC_RX_PREAMBLE_NUM _at_ USBTypec_Page+0x7F;

// TX send Command control register
xdata UCHAR volatile SC_USBC_CC_TX_CTRL _at_ USBTypec_Page+0x80;
xdata UCHAR volatile SC_USBC_CC_TX_MANUAL_ADDR _at_ USBTypec_Page+0x81;
xdata UCHAR volatile SC_USBC_CC_TX_WRITE_DATA _at_ USBTypec_Page+0x82;

// RX Get command and Data
xdata UCHAR volatile SC_USBC_CC_RX_CTRL _at_ USBTypec_Page+0x84;
xdata UCHAR volatile SC_USBC_CC_RX_MANUAL_ADDR _at_ USBTypec_Page+0x85;
xdata UCHAR volatile SC_USBC_CC_RX_READ_DATA _at_ USBTypec_Page+0x86;

// Timer Register
xdata UCHAR volatile SC_USBC_CC_TIMER_CTRL _at_ USBTypec_Page+0x88;
xdata UCHAR volatile SC_USBC_CC_TIMER_PERIODH _at_ USBTypec_Page+0x89;
xdata UCHAR volatile SC_USBC_CC_TIMER_PERIODL _at_ USBTypec_Page+0x8A;

// Counter register
xdata UCHAR volatile SC_USBC_CC_COUNTER_SEL_CLEAR _at_ USBTypec_Page+0x8D;
xdata UCHAR volatile SC_USBC_CC_COUNTER_READH _at_ USBTypec_Page+0x8E;
xdata UCHAR volatile SC_USBC_CC_COUNTER_READL _at_ USBTypec_Page+0x8F;


// Interrupt flag register
xdata UCHAR volatile SC_USBC_CC_INT_GROUP_0_FLAG _at_ USBTypec_Page+0x90;
xdata UCHAR volatile SC_USBC_CC_INT_GROUP_1_FLAG _at_ USBTypec_Page+0x91;
xdata UCHAR volatile SC_USBC_CC_INT_GROUP_2_FLAG _at_ USBTypec_Page+0x92;
xdata UCHAR volatile SC_USBC_CC_INT_GROUP_3_FLAG _at_ USBTypec_Page+0x93;
xdata UCHAR volatile SC_USBC_CC_INT_GROUP_4_FLAG _at_ USBTypec_Page+0x94;
// Interrupt enable register
xdata UCHAR volatile SC_USBC_CC_INT_GROUP_0_EN _at_ USBTypec_Page+0x98;
xdata UCHAR volatile SC_USBC_CC_INT_GROUP_1_EN _at_ USBTypec_Page+0x99;
xdata UCHAR volatile SC_USBC_CC_INT_GROUP_2_EN _at_ USBTypec_Page+0x9A;
xdata UCHAR volatile SC_USBC_CC_INT_GROUP_3_EN _at_ USBTypec_Page+0x9B;
xdata UCHAR volatile SC_USBC_CC_INT_GROUP_4_EN _at_ USBTypec_Page+0x9C;


// USB CC IO PHY Control
xdata UCHAR volatile SC_USBC_CC_IO_LDO_CTRL _at_ USBTypec_Page+0xA0;
xdata UCHAR volatile SC_USBC_CC_IO_BANDGAP_CTRL _at_ USBTypec_Page+0xA1;
xdata UCHAR volatile SC_USBC_CC_IO_BIAS_SEL _at_ USBTypec_Page+0xA2;
xdata UCHAR volatile SC_USBC_CC_IO_CC1_CTRL _at_ USBTypec_Page+0xA3;
xdata UCHAR volatile SC_USBC_CC_IO_CC2_CTRL _at_ USBTypec_Page+0xA4;
xdata UCHAR volatile SC_USBC_CC_IO_CC_DRIVER_CTRL _at_ USBTypec_Page+0xA5;
xdata UCHAR volatile SC_USBC_CC_PHY_RESERVED _at_ USBTypec_Page+0xA6;


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
