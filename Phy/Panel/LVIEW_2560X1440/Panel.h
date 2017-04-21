/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/
#ifndef __NVT_2560X1440_FP_H__
#define __NVT_2560X1440_FP_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************

//******************************************************************************
// G L O B A L   D E F I N I T I O N S
//******************************************************************************
#define PANEL_NAME              "NVT 2560X1440 FP"
#define PANEL_TYPE              (NVT|RES_2560X1440)
#define PANEL_DUAL_PORT_LVDS    1
#define PANEL_COLOR_DEPTH       10
#define PANEL_DE_MODE           0
#define PANEL_PORT_SWAP         0
#define PANEL_BIT_SHIFT         0

#define PANEL_FOUR_PORT_LVDS    1
#define PANEL_TEN_BIT_SHIFT     0 //0: NS mode, 1: VESA mode , 2: JEIDA mode
#define PANEL_FOUR_PORT_SWAP    4 //Port A/B/C/D swap ( pixel swap )
                                  //000 = ABCD ( 0,1,2,3 ) 
                                  //001 = ACBD ( 0,2,1,3 ) 
                                  //010 = DCBA ( 3,2,1,0 ) 
                                  //011 = DBCA ( 3,1,2,0 ) 
                                  //100 = CDAB ( 2,3,0,1 ) 
                                  //101 = BDAC ( 1,3,0,2 ) 
                                  //110 = BADC ( 1,0,3,2 ) 
                                  //111 = CADB ( 2,0,3,1 ) 
#define PANEL_WIDTH             2560
#define PANEL_HEIGHT            1440

#define PANEL_MIN_LVDS_CLK      248000000 //Hz
#define PANEL_MAX_LVDS_CLK      380000000 //Hz

#define PANEL_MIN_HTOTAL        2792
#define PANEL_TYP_HTOTAL        2816
#define PANEL_MAX_HTOTAL        3600

#define PANEL_MIN_VTOTAL        1468
#define PANEL_TYP_VTOTAL        1480
#define PANEL_MAX_VTOTAL        2047

#define PANEL_HSYNC_WIDTH       ((PANEL_MIN_HTOTAL - PANEL_WIDTH) / 3 / 8) * 8
#define PANEL_HSYNC_BACKPORCH   ((PANEL_MIN_HTOTAL - PANEL_WIDTH) / 3 / 8) * 8
#define PANEL_HACTIVE_BEG       PANEL_HSYNC_WIDTH + PANEL_HSYNC_BACKPORCH

#define PANEL_VSYNC_WIDTH       2
#define PANEL_VSYNC_BACKPORCH   3
#define PANEL_VACTIVE_BEG       PANEL_VSYNC_WIDTH + PANEL_VSYNC_BACKPORCH

#define PANEL_DISP_HSYNC_POL    0 //0:Active low, 1:Active high
#define PANEL_DISP_VSYNC_POL    0 //0:Active low, 1:Active high
#define PANEL_DISP_DE_POL       1 //0:Active low, 1:Active high

#define PANEL_FRC_OUTPUT_VSYNC  600 //0.1Hz
#define PANEL_PAD_DRIVE         0x00

#define PANEL_LVDS_SWING        LVDS_SWING_450
#define PANEL_DCLK_SSC          0x2D
#define PANEL_DCLK_NEW_SSC          0xE8
#define PANEL_DCLK_NEW_SSC_RANGE    30 //Unit +- 0.1%

#define DT16A                   0x00
#define DT158                   0x33
#define DT1D8                   0x00
#define DT1DA                   0x90
#define DT1DB                   0x00

#define PANEL_POWER_UP_TIME     25
#define PANEL_INVTER_UP_TIME    100
#define PANEL_POWER_DOWN_TIME   25
#define PANEL_INVTER_DOWN_TIME  100
#define PANEL_OFF_ON_TIME       1000

#define PANEL_LED_VOLTAGE_MAX   58
#define PANEL_LED_VOLTAGE_TYP   50
#define PANEL_LED_BINCURRENT    50

#define ADC_OFFSET_ADJ          4
#define ADC_GAIN_ADJ            0

#define PANEL_LVDS_OFFSET       0 
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

#endif //__NVT_2560X1440_FP_H__
