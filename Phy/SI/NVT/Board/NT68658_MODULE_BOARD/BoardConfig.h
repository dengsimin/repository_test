/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/
#ifndef __BOARD_CONFIG_H__
#define __BOARD_CONFIG_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "McuAPI.h"
#include "Scaler.h"
#include "Typedef.h"

//******************************************************************************
// G L O B A L   D E F I N I T I O N S
//******************************************************************************
//Crystal Clock
#define REF_CLK                 12000000

//Scaler
#define PCBA_SCALER             NT68658

//Combine 8 bits into 1 byte
#define BitsToByte(b7,b6,b5,b4,b3,b2,b1,b0) ((b7<<7)|(b6<<6)|(b5<<5)|(b4<<4)|(b3<<3)|(b2<<2)|(b1<<1)|b0)

//Mcu I/O port default output          bit:   7     6     5     4     3     2     1     0
#define PORT_A_DEFAULT_OUT      BitsToByte(HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH)
#define PORT_B_DEFAULT_OUT      BitsToByte(HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH)
#define PORT_C_DEFAULT_OUT      BitsToByte( LOW, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH,  LOW)
#define PORT_D_DEFAULT_OUT      BitsToByte(HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH)
#define PORT_E_DEFAULT_OUT      BitsToByte(HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH)

//Mcu I/O port default direction       bit:   7     6     5     4     3     2     1     0
#define PORT_A_DEFAULT_DIR      BitsToByte(  IN,   IN,   IN,   IN,   IN,  OUT,   IN,   IN)
#define PORT_B_DEFAULT_DIR      BitsToByte(  IN,   IN,   IN,   IN,   IN,   IN,   IN,   IN)
#define PORT_C_DEFAULT_DIR      BitsToByte( OUT,  OUT,   IN,   IN,   IN,   IN,   IN,  OUT)
#define PORT_D_DEFAULT_DIR      BitsToByte(  IN,   IN,   IN,   IN,   IN,   IN,   IN,   IN)
#define PORT_E_DEFAULT_DIR      BitsToByte(  IN,   IN,  OUT,  OUT,   IN,   IN,   IN,   IN)

//Mcu I/O port Push-Pull Configuration bit:   7     6     5     4     3     2     1     0
#define PORT_A_DEFAULT_PP       BitsToByte( LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW)
#define PORT_B_DEFAULT_PP       BitsToByte( LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW)
#define PORT_C_DEFAULT_PP       BitsToByte(HIGH, HIGH,  LOW,  LOW,  LOW,  LOW,  LOW, HIGH)
#define PORT_D_DEFAULT_PP       BitsToByte( LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW)
#define PORT_E_DEFAULT_PP       BitsToByte( LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW)
#define PORT_3_DEFAULT_PP       BitsToByte( LOW,  LOW, HIGH, HIGH,  LOW,  LOW, HIGH, HIGH)

//Mcu I/O port Pull-Up Configuration   bit:   7     6     5     4     3     2     1     0
#define PORT_A_DEFAULT_PU       BitsToByte( LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW)
#define PORT_B_DEFAULT_PU       BitsToByte( LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW)
#define PORT_C_DEFAULT_PU       BitsToByte(HIGH, HIGH,  LOW,  LOW,  LOW,  LOW,  LOW, HIGH)
#define PORT_D_DEFAULT_PU       BitsToByte( LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW)
#define PORT_E_DEFAULT_PU       BitsToByte( LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW)
#define PORT_3_DEFAULT_PU       BitsToByte( LOW,  LOW, HIGH, HIGH,  LOW,  LOW, HIGH, HIGH)

//Each bit indicates one ADC channel,      ADC7  ADC6  ADC5  ADC4  ADC3  ADC2  ADC1  ADC0
#define MCU_ADC_CON_DEFAULT     BitsToByte( LOW, LOW,  LOW,  LOW,  HIGH, HIGH, HIGH,  LOW)

//AC 5V detection
#define POWER_DETEC_ADC         MCU_ADC_NULL
#define POWER_THRESHOLD         0x40
#define LPD_INPUT_PIN           0 //0/1
#define LPD_THRESHOLD           0xDB

//Each bit indicates one PWM channel,      NONE  NONE  NONE  NONE PWM11 PWM10  PWM9  PWM8
#define MCU_PWM_CON_DEFAULT     BitsToByte( LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW)<<8 | \
                                BitsToByte( LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW)
                                         //PWM7  PWM6  PWM5  PWM4  PWM3  PWM2  PWM1  PWM0

//Each bit indicates one DDC channel,      NONE  NONE  NONE  NONE  DDC3  DDC2  DDC1  DDC0
#define MCU_DDC_CON_DEFAULT     BitsToByte( LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW)
//DDC I2C slave address
#define MCU_DDC0_ADDRESS        0xA0 //Same as 24C02
#define MCU_DDC0_EDIDLEN        0 //EDID Length: 0:128 bytes, 1:256 bytes
#define MCU_DDC1_ADDRESS        0xA0
#define MCU_DDC1_EDIDLEN        0
#define MCU_DDC2_ADDRESS        0xA0
#define MCU_DDC2_EDIDLEN        1
#define MCU_DDC3_ADDRESS        0xA0
#define MCU_DDC3_EDIDLEN        0

//Each bit indicates one IIC channel,      NONE  NONE  NONE  NONE  IIC3  IIC2  IIC1  IIC0
#define MCU_IIC_CON_DEFAULT     BitsToByte( LOW,  LOW,  LOW,  LOW,  LOW,  LOW, HIGH, HIGH)
//I2C slave address, for DDCCI communication
#define MCU_IIC0_ADDRESS        0x6E
#define MCU_IIC1_ADDRESS        0x6E
#define MCU_IIC2_ADDRESS        0x6E
#define MCU_IIC3_ADDRESS        0x6E

//Use internal EDID
#define USE_INTERNAL_EDID       0
#define VGA_DDC_CHANNEL         0xFF // Channel from 0 ~ 3
#define DVI_DDC_CHANNEL         0xFF // 0xFF means no use
#define HDMI_DDC_CHANNEL        0xFF

//Backlight control
#define BACKLIGHT_PORT          MCU_PORT_NULL
#define BACKLIGHT_BIT           BIT5
#define BACKLIGHT_ACTIVE        HIGH
//LED green control
#define LED_GREEN_PORT          MCU_PORT_E
#define LED_GREEN_BIT           BIT4
#define LED_GREEN_ACTIVE        LOW
//LED red control
#define LED_RED_PORT            MCU_PORT_E
#define LED_RED_BIT             BIT4
#define LED_RED_ACTIVE          LOW
//Panel power control
#define PANEL_POWER_PORT        MCU_PORT_C
#define PANEL_POWER_BIT         BIT7
#define PANEL_POWER_ACTIVE      HIGH
//LightBar control
#define LIGHT_BAR_PORT          MCU_PORT_NULL
#define LIGHT_BAR_BIT           BIT5
#define LIGHT_BAR_ACTIVE        HIGH
//VGA cable connection
#define VGA_CABLE_PORT          MCU_PORT_NULL
#define VGA_CABLE_BIT           BIT5
#define VGA_CABLE_ACTIVE        LOW
#define VGA_CONNECT_LEVEL       0x46
#define VGA_DISCONNECT_LEVEL    0x7F
#define VGA_DET_LEVEL           (VGA_CONNECT_LEVEL + VGA_DISCONNECT_LEVEL) / 2
#define VGA_DET_ADC             MCU_ADC_1
//Digital interface 0 cable connection
#define DIGI0_CABLE_PORT        MCU_PORT_NULL
#define DIGI0_CABLE_BIT         BIT4
#define DIGI0_CABLE_ACTIVE      LOW
#define DIGI0_CONNECT_LEVEL     0x52
#define DIGI0_DISCONNECT_LEVEL  0x7F
#define DIGI0_DET_LEVEL         (DIGI0_CONNECT_LEVEL + DIGI0_DISCONNECT_LEVEL) / 2
#define DIGI0_DET_ADC           MCU_ADC_1
//Digital interface 1 cable connection
#define DIGI1_CABLE_PORT        MCU_PORT_NULL
#define DIGI1_CABLE_BIT         BIT4
#define DIGI1_CABLE_ACTIVE      LOW
//MHL interface 0 cable connection
#define MHL0_CABLE_PORT         MCU_PORT_NULL
#define MHL0_CABLE_BIT          BIT0
#define MHL0_CABLE_ACTIVE       HIGH
//MHL interface 1 cable connection
#define MHL1_CABLE_PORT         MCU_PORT_NULL
#define MHL1_CABLE_BIT          BIT1
#define MHL1_CABLE_ACTIVE       HIGH
//NVRAM configuration
#define NVRAM_SDA_PORT          MCU_PORT_3
#define NVRAM_SDA_BIT           BIT5
#define NVRAM_SCL_PORT          MCU_PORT_3
#define NVRAM_SCL_BIT           BIT4
#define NVRAM_WP_PORT           MCU_PORT_C
#define NVRAM_WP_BIT            BIT6
#define NVRAM_WP_ACTIVE         HIGH
//FLASH
#define FLASH_WP_PORT           MCU_PORT_C
#define FLASH_WP_BIT            BIT0
#define FLASH_WP_ACTIVE         LOW
//EDID 24C02
#define EDID_WP_PORT            MCU_PORT_A
#define EDID_WP_BIT             BIT2
#define EDID_WP_ACTIVE          HIGH

#define DDC0_SDA_PORT           MCU_PORT_B
#define DDC0_SDA_BIT            BIT5
#define DDC0_SCL_PORT           MCU_PORT_B
#define DDC0_SCL_BIT            BIT4

#define DDC1_SDA_PORT           MCU_PORT_B
#define DDC1_SDA_BIT            BIT7
#define DDC1_SCL_PORT           MCU_PORT_B
#define DDC1_SCL_BIT            BIT6

#define DDC2_SDA_PORT           MCU_PORT_A
#define DDC2_SDA_BIT            BIT5
#define DDC2_SCL_PORT           MCU_PORT_A
#define DDC2_SCL_BIT            BIT4

#define DDC3_SDA_PORT           MCU_PORT_A
#define DDC3_SDA_BIT            BIT7
#define DDC3_SCL_PORT           MCU_PORT_A
#define DDC3_SCL_BIT            BIT6
//Audio configuration
#define AUDIO_LINE_IN           LINE_IN1 //(LINE_IN1/LINE_IN2)
#define AUDIO_OUT               LINE_OUT //(LINE_OUT/IIS_OUT)
//Volume control
#define VOLUME_PWM_PORT         PWM_NULL //(PWM_A,PWM_B,PWM_MCU,PRE_AMP)
#define VOLUME_PWM_POL          HIGH
#define VOLUME_PWM_OUTPUT_PIN   PWMB_PIN_66
//Audio mute control
#define AMP_MUTE_PORT           MCU_PORT_NULL
#define AMP_MUTE_BIT            BIT6
#define AMP_MUTE_ACTIVE         HIGH
//Audio power control
#define AMP_PWR_PORT            MCU_PORT_NULL
#define AMP_PWR_BIT             BIT1
#define AMP_PWR_ACTIVE          LOW
//DIM configuration
#define BKL_PWM_PORT            PWM_LEDDRIVER //PWM_A
#define BKL_PWM_POL             HIGH
#define BKL_PWM_OUTPUT_PIN      PWMA_LEDDRIVER //PWMA_PIN_69
//Hotplug configuration
#define DIG0_HPD_PORT           MCU_PORT_E
#define DIG0_HPD_BIT            BIT5
#define DIG0_HPD_ACTIVE         HIGH
#define DIG1_HPD_PORT           MCU_PORT_NULL
#define DIG1_HPD_BIT            BIT5
#define DIG1_HPD_ACTIVE         HIGH
//POWER MOS configuration
#define POWER_MOS_PORT          MCU_PORT_NULL
#define POWER_MOS_BIT           BIT1
#define POWER_MOS_ACTIVE        HIGH
//FPGA configuration
#define FPGA_SDA_PORT           MCU_PORT_3
#define FPGA_SDA_BIT            BIT4
#define FPGA_SCL_PORT           MCU_PORT_3
#define FPGA_SCL_BIT            BIT5

//Panel power extra delay (This is an extra delay according to the PCB)
#define PANEL_POWER_DELAY       200

//R1 / R2 setting for OVP
#define OVP_RLOWER              1
#define OVP_RUPPER              30

/*******************************************************************************
               HDCP-related and digital(HDMI) interface Setting
*******************************************************************************/
//HDCP MUX
#define DIGITAL_INPUT0_HDCP_MUX 1
#define DIGITAL_INPUT1_HDCP_MUX 1

//AUDIO INPUT
#define DIGITAL_INPUT0_HDMI_AUDIO 1
#define DIGITAL_INPUT1_HDMI_AUDIO 1

//DIGITAL RX0/RX2 SWAP (NT68674 series only)
#define DIGITAL_CHANNEL_SWAP    0
#define DIGITAL0_CHANNEL_SWAP   0
#define DIGITAL1_CHANNEL_SWAP   0

//CEC Channel
#define HDMI_CEC_CHANNEL        0
//LVDS
#define ENABLE_LVDS_POL_SWAP    OFF//ON/OFF
/*******************************************************************************
                Cable detect by ADC level
*******************************************************************************/
/*******************************************************************************
                           Keypad interface setting
*******************************************************************************/
// Specific AD port of AD key
#define KEY_GROUP1_ADC          MCU_ADC_3
#define KEY_GROUP2_ADC          MCU_ADC_2


// Specific IO port of IO key
#define IOBTN_1_PORT            MCU_PORT_NULL
#define IOBTN_1_BIT             BIT2
#define IOBTN_1_ACTIVE          LOW
#define IOBTN_2_PORT            MCU_PORT_NULL
#define IOBTN_2_BIT             BIT4
#define IOBTN_2_ACTIVE          LOW
#define IOBTN_3_PORT            MCU_PORT_NULL
#define IOBTN_3_BIT             BIT5
#define IOBTN_3_ACTIVE          LOW
#define IOBTN_4_PORT            MCU_PORT_NULL
#define IOBTN_4_BIT             BIT6
#define IOBTN_4_ACTIVE          LOW
#define IOBTN_5_PORT            MCU_PORT_NULL
#define IOBTN_5_BIT             BIT7
#define IOBTN_5_ACTIVE          LOW
#define IOBTN_6_PORT            MCU_PORT_NULL
#define IOBTN_6_BIT             BIT1
#define IOBTN_6_ACTIVE          LOW
#define IOBTN_7_PORT            MCU_PORT_NULL
#define IOBTN_7_BIT             BIT1
#define IOBTN_7_ACTIVE          LOW
#define IOBTN_8_PORT            MCU_PORT_NULL
#define IOBTN_8_BIT             BIT1
#define IOBTN_8_ACTIVE          LOW

#define AO_KEY_DEBOUNCE_TIME    155
/*******************************************************************************
                               LED String Define
*******************************************************************************/
#define PCBA_LEDSTR_PARALLEL    1
#define PCBA_LEDSTR_EN          BitsToByte(LOW, LOW, LOW, LOW, HIGH, HIGH, HIGH, HIGH)

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

#endif //__BOARD_CONFIG_H__
