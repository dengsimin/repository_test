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
#define PCBA_SCALER             NT68364

//Combine 8 bits into 1 byte
#define BitsToByte(b7,b6,b5,b4,b3,b2,b1,b0) ((b7<<7)|(b6<<6)|(b5<<5)|(b4<<4)|(b3<<3)|(b2<<2)|(b1<<1)|b0)

//Mcu I/O port default output          bit:   7     6     5     4     3     2     1     0
#define PORT_A_DEFAULT_OUT      BitsToByte(HIGH,  LOW, HIGH, HIGH,  LOW, HIGH, HIGH, HIGH)
#define PORT_B_DEFAULT_OUT      BitsToByte(HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH)
#define PORT_C_DEFAULT_OUT      BitsToByte(HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH)
#define PORT_D_DEFAULT_OUT      BitsToByte(HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH)
#define PORT_E_DEFAULT_OUT      BitsToByte(HIGH, HIGH, HIGH, HIGH, HIGH, HIGH,  LOW, HIGH)
#define PORT_3_DEFAULT_OUT      BitsToByte(HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH)

//Mcu I/O port default direction       bit:   7     6     5     4     3     2     1     0
#define PORT_A_DEFAULT_DIR      BitsToByte(  IN,  OUT,   IN,   IN,  OUT,   IN,   IN,   IN)
#define PORT_B_DEFAULT_DIR      BitsToByte( OUT,  OUT,   IN,   IN,   IN,   IN,   IN,   IN)
#define PORT_C_DEFAULT_DIR      BitsToByte(  IN,  OUT,   IN,   IN,   IN,   IN,   IN,  OUT)
#define PORT_D_DEFAULT_DIR      BitsToByte(  IN,   IN,   IN,  OUT,   IN,   IN,   IN,   IN)
#define PORT_E_DEFAULT_DIR      BitsToByte(  IN,   IN,   IN,   IN,  OUT,   IN,   IN,   IN)

//Mcu I/O port Push-Pull Configuration bit:   7     6     5     4     3     2     1     0
#define PORT_A_DEFAULT_PP       BitsToByte( LOW, HIGH,  LOW,  LOW, HIGH,  LOW,  LOW,  LOW)
#define PORT_B_DEFAULT_PP       BitsToByte( LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW)
#define PORT_C_DEFAULT_PP       BitsToByte( LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW)
#define PORT_D_DEFAULT_PP       BitsToByte( LOW,  LOW,  LOW, HIGH,  LOW,  LOW,  LOW,  LOW)
#define PORT_E_DEFAULT_PP       BitsToByte( LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW)
#define PORT_3_DEFAULT_PP       BitsToByte( LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW)

//Mcu I/O port Pull-Up Configuration   bit:   7     6     5     4     3     2     1     0
#define PORT_A_DEFAULT_PU       BitsToByte( LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW)
#define PORT_B_DEFAULT_PU       BitsToByte( LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW)
#define PORT_C_DEFAULT_PU       BitsToByte( LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW)
#define PORT_D_DEFAULT_PU       BitsToByte( LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW)
#define PORT_E_DEFAULT_PU       BitsToByte( LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW)
#define PORT_3_DEFAULT_PU       BitsToByte( LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW)

//Each bit indicates one ADC channel,      ADC7  ADC6  ADC5  ADC4  ADC3  ADC2  ADC1  ADC0
#define MCU_ADC_CON_DEFAULT     BitsToByte( LOW,  LOW,  LOW,  LOW, HIGH, HIGH,  LOW, HIGH)
//AC 5V detection
#define POWER_DETEC_ADC         MCU_ADC_NULL
#define POWER_THRESHOLD         0x40
#define LPD_INPUT_PIN           0 //0/1
#define LPD_THRESHOLD           0xDB

//Each bit indicates one DDC channel,      NONE  NONE  NONE  NONE  DDC3  DDC2  DDC1  DDC0
#define MCU_DDC_CON_DEFAULT     BitsToByte( LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW, LOW)
//DDC I2C slave address
#define MCU_DDC0_ADDRESS        0xA0 //Same as 24C02
#define MCU_DDC0_EDIDLEN        0 //EDID Length: 0:128 bytes, 1:256 bytes
#define MCU_DDC1_ADDRESS        0xA0
#define MCU_DDC1_EDIDLEN        0
#define MCU_DDC2_ADDRESS        0xA0
#define MCU_DDC2_EDIDLEN        0
#define MCU_DDC3_ADDRESS        0xA0
#define MCU_DDC3_EDIDLEN        1

//Each bit indicates one IIC channel,      NONE  NONE  NONE  NONE  IIC3  IIC2  IIC1  IIC0
#define MCU_IIC_CON_DEFAULT     BitsToByte( LOW,  LOW,  LOW,  LOW, LOW,  HIGH,  LOW, HIGH)
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
#define BACKLIGHT_PORT          MCU_PORT_A
#define BACKLIGHT_BIT           BIT6
#define BACKLIGHT_ACTIVE        HIGH
//LED green control
#define LED_GREEN_PORT          MCU_PORT_C
#define LED_GREEN_BIT           BIT0
#define LED_GREEN_ACTIVE        LOW
//LED red control
#define LED_RED_PORT            MCU_PORT_NULL
#define LED_RED_BIT             BIT5
#define LED_RED_ACTIVE          LOW
//Panel power control
#define PANEL_POWER_PORT        MCU_PORT_D
#define PANEL_POWER_BIT         BIT4
#define PANEL_POWER_ACTIVE      LOW
//VGA cable connection
#define VGA_CABLE_PORT          MCU_PORT_NULL
#define VGA_CABLE_BIT           BIT3
#define VGA_CABLE_ACTIVE        LOW
//Digital interface 0 cable connection
#define DIGI0_CABLE_PORT        MCU_PORT_NULL
#define DIGI0_CABLE_BIT         BIT6
#define DIGI0_CABLE_ACTIVE      LOW
#define DIGI0_CONNECT_LEVEL     0x52
#define DIGI0_DISCONNECT_LEVEL  0x7F
#define DIGI0_DET_LEVEL         (DIGI0_CONNECT_LEVEL + DIGI0_DISCONNECT_LEVEL) / 2
#define DIGI0_DET_ADC           MCU_ADC_1
//Digital interface 1 cable connection
#define DIGI1_CABLE_PORT        MCU_PORT_NULL
#define DIGI1_CABLE_BIT         BIT7
#define DIGI1_CABLE_ACTIVE      LOW
//NVRAM configuration
#define NVRAM_SDA_PORT          MCU_PORT_3
#define NVRAM_SDA_BIT           BIT5
#define NVRAM_SCL_PORT          MCU_PORT_3
#define NVRAM_SCL_BIT           BIT4
#define NVRAM_WP_PORT           MCU_PORT_NULL
#define NVRAM_WP_BIT            BIT5
#define NVRAM_WP_ACTIVE         HIGH
//FLASH
#define FLASH_WP_PORT           MCU_PORT_E
#define FLASH_WP_BIT            BIT3
#define FLASH_WP_ACTIVE         LOW
//EDID 24C02
#define EDID_WP_PORT            MCU_PORT_C
#define EDID_WP_BIT             BIT6
#define EDID_WP_ACTIVE          HIGH
//Audio configuration
#define AUDIO_LINE_IN           LINE_IN2 //(LINE_IN1/LINE_IN2)
#define AUDIO_OUT               LINE_OUT //(LINE_OUT/IIS_OUT)
//Volume control
#define VOLUME_PWM_PORT         PWM_NULL //(PWM_A,PWM_B,PWM_MCU,PRE_AMP)
#define VOLUME_PWM_POL          HIGH
#define VOLUME_PWM_OUTPUT_PIN   PWMD_PIN_K17
//Audio mute control
#define AMP_MUTE_PORT           MCU_PORT_A
#define AMP_MUTE_BIT            BIT3
#define AMP_MUTE_ACTIVE         LOW
//Audio power control
#define AMP_PWR_PORT            MCU_PORT_NULL
#define AMP_PWR_BIT             BIT1
#define AMP_PWR_ACTIVE          LOW
//DIM configuration
#define BKL_PWM_PORT            PWM_A
#define BKL_PWM_POL             HIGH
#define BKL_PWM_OUTPUT_PIN      PWMA_PIN_C10
//Hotplug configuration
#define DIG0_HPD_PORT           MCU_PORT_B
#define DIG0_HPD_BIT            BIT6
#define DIG0_HPD_ACTIVE         HIGH
#define DIG1_HPD_PORT           MCU_PORT_B
#define DIG1_HPD_BIT            BIT7
#define DIG1_HPD_ACTIVE         HIGH
//POWER MOS configuration
#define POWER_MOS_PORT          MCU_PORT_NULL
#define POWER_MOS_BIT           BIT5
#define POWER_MOS_ACTIVE        HIGH

//Panel power extra delay (This is an extra delay according to the PCB)
#define PANEL_POWER_DELAY       0

/*******************************************************************************
               HDCP-related and digital(HDMI) interface Setting
*******************************************************************************/
//HDCP MUX
#define DIGITAL_INPUT0_HDCP_MUX 2
#define DIGITAL_INPUT1_HDCP_MUX 0

//AUDIO INPUT
#define DIGITAL_INPUT0_HDMI_AUDIO 1
#define DIGITAL_INPUT1_HDMI_AUDIO 1

//DIGITAL RX0/RX2 SWAP (NT68674 series only)
#define DIGITAL0_CHANNEL_SWAP   0
#define DIGITAL1_CHANNEL_SWAP   0


//CEC Channel
#define HDMI_CEC_CHANNEL        1

//LVDS
#define ENABLE_LVDS_POL_SWAP    OFF

/*******************************************************************************
                           Keypad interface setting
*******************************************************************************/
// Specific AD port of AD key
#define KEY_GROUP1_ADC          MCU_ADC_2
#define KEY_GROUP2_ADC          MCU_ADC_3

// Specific IO port of IO key
#define IOBTN_1_PORT            MCU_PORT_NULL
#define IOBTN_1_BIT             BIT7
#define IOBTN_1_ACTIVE          LOW
#define IOBTN_2_PORT            MCU_PORT_NULL
#define IOBTN_2_BIT             BIT0
#define IOBTN_2_ACTIVE          LOW
#define IOBTN_3_PORT            MCU_PORT_NULL
#define IOBTN_3_BIT             BIT1
#define IOBTN_3_ACTIVE          LOW
#define IOBTN_4_PORT            MCU_PORT_NULL
#define IOBTN_4_BIT             BIT7
#define IOBTN_4_ACTIVE          LOW
#define IOBTN_5_PORT            MCU_PORT_NULL
#define IOBTN_5_BIT             BIT6
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
