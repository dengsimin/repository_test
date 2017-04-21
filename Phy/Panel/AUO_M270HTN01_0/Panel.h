/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/
#ifndef __AUO_M270HTN01_0_H__
#define __AUO_M270HTN01_0_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************

//******************************************************************************
// G L O B A L   D E F I N I T I O N S
//******************************************************************************
#define PANEL_NAME              "AUO M270HTN01 0"
#define PANEL_TYPE              (AUO|RES_1920X1080)
#define PANEL_DUAL_PORT_LVDS    1
#define PANEL_COLOR_DEPTH       8
#define PANEL_DE_MODE           1
#define PANEL_PORT_SWAP         0
#define PANEL_BIT_SHIFT         0

#define PANEL_FOUR_PORT_LVDS    1
#define PANEL_TEN_BIT_SHIFT     1 //0: NS mode, 1: VESA mode , 2: JEIDA mode
#define PANEL_FOUR_PORT_SWAP    4//0 //Port A/B/C/D swap ( pixel swap )
                                  //000 = ABCD ( 0,1,2,3 ) 
                                  //001 = ACBD ( 0,2,1,3 ) 
                                  //010 = DCBA ( 3,2,1,0 ) 
                                  //011 = DBCA ( 3,1,2,0 ) 
                                  //100 = CDAB ( 2,3,0,1 ) 
                                  //101 = BDAC ( 1,3,0,2 ) 
                                  //110 = BADC ( 1,0,3,2 ) 
                                  //111 = CADB ( 2,0,3,1 ) 

#define PANEL_WIDTH             1920
#define PANEL_HEIGHT            1080

#define PANEL_MIN_LVDS_CLK      170000000 //Hz
#define PANEL_MAX_LVDS_CLK      380000000 //Hz
#define PANEL_FRC_MIN_LVDS_CLK  84000000 //Hz

#define PANEL_MIN_HTOTAL        2024
#define PANEL_TYP_HTOTAL        2240
#define PANEL_MAX_HTOTAL        4088

#define PANEL_MIN_VTOTAL        1096
#define PANEL_TYP_VTOTAL        1136
#define PANEL_MAX_VTOTAL        6408

#define PANEL_HSYNC_WIDTH       ((PANEL_MIN_HTOTAL - PANEL_WIDTH) / 3 / 8) * 8
#define PANEL_HSYNC_BACKPORCH   ((PANEL_MIN_HTOTAL - PANEL_WIDTH) / 3 / 8) * 8
#define PANEL_HACTIVE_BEG       PANEL_HSYNC_WIDTH + PANEL_HSYNC_BACKPORCH

#define PANEL_VSYNC_WIDTH       2
#define PANEL_VSYNC_BACKPORCH   1
#define PANEL_VACTIVE_BEG       PANEL_VSYNC_WIDTH + PANEL_VSYNC_BACKPORCH

#define PANEL_DISP_HSYNC_POL    0 //0:Active low, 1:Active high
#define PANEL_DISP_VSYNC_POL    0 //0:Active low, 1:Active high
#define PANEL_DISP_DE_POL       1 //0:Active low, 1:Active high

#define PANEL_FRC_OUTPUT_VSYNC  1200//600 //0.1Hz
#define PANEL_PAD_DRIVE         0x00

#define PANEL_LVDS_SWING        LVDS_SWING_450
#define PANEL_DCLK_SSC          0x2D

#define PANEL_DCLK_NEW_SSC      0x43
#define PANEL_DCLK_NEW_SSC_RANGE    30 //Unit +- 0.1%

#define DT16A                   0x00
#define DT158                   0x33
#define DT1D8                   0x00
#define DT1DA                   0x90
#define DT1DB                   0x00

#define PANEL_POWER_UP_TIME     25
#define PANEL_INVTER_UP_TIME    550
#define PANEL_POWER_DOWN_TIME   25
#define PANEL_INVTER_DOWN_TIME  150
#define PANEL_OFF_ON_TIME       1350


#define ADC_OFFSET_ADJ          4
#define ADC_GAIN_ADJ            0


#define VCOM_IIC                OFF //ON/OFF


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

#endif 