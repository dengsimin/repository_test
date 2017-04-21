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
#include "Include.h"
#include "ScalerProfile.h"

//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************
#define IIC_MASK_VALUE 0x83 /*!< IIC mask. */

//******************************************************************************
// G L O B A L   D E F I N I T I O N S
//******************************************************************************

//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************
BOOL bIsAPLLPowerDown = FALSE; /*! < Status of APLL power down. */
UCHAR ucTL0_Normal_Power=0,ucTH0_Normal_Power=0;
UCHAR ucTL0_LOW_POWER=0,ucTH0_LOW_POWER=0,ucTL0_LOW_POWER_3M=0,ucTH0_LOW_POWER_3M=0;

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************
static code UCHAR MCU_CLK[9] = CPU_CLK_TABLE;

//******************************************************************************
// E X T E R N A L   V A R I A B L E   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// S T A T I C   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
static void McuInitIO(void);
static void McuInitADC(void);
static void McuInitPWM(void);
static void McuInitDDC(void);
static void McuInitIIC(void);
static void McuInitMisc(void);
static void McuInitCore(void);
static BOOL McuCheckPwrStable(void);

//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// F U N C T I O N   B O D Y S
//******************************************************************************

/**************************************************************************//**
 * MCU to Speed.
 ******************************************************************************/
ULONG GetMCUTimer0Speed(void)
{
 return (ULONG)(((float)MCU_CLK[MCU_CLK_TIMES] / 12 * ((float)REF_CLK / 12000000)) * 1000);
}

/**************************************************************************//**
 * Get CPU Clock.
 ******************************************************************************/
ULONG GetCPUClcok(void)
{
 return (ULONG)(MCU_CLK[MCU_CLK_TIMES] * 1000000 * ((float)REF_CLK/12000000));
}

/**************************************************************************//**
 * Get UART Time.
 ******************************************************************************/
UCHAR GetUARTTimer(ULONG speed)
{
    return (UCHAR)((float)speed * 2 / 384 / MCU_UART_BAUD_RATE + 0.5);
}

/**************************************************************************//**
 * MCU Initialization. MCU TIMER, SPEED, UART, I/O, ADC, PWM, ... etc. will be initialized.
 ******************************************************************************/
void McuInitialize(void)
{
#if IS_NT68810_SERIES || IS_NT68870_SERIES
    USHRT j;
    SC_MPLL_B3E = 0xFE;//0xF2;//WRITE     B0    B3E  F2   
    SC_MPLL_B3F = 0xA1;//0x51;//WRITE     B0    B3F  51
    SC_MPLL_B45 = 0x71;//0x60;//WRITE     B0    B45  60
#if 1//PSON = 1
    SC_ZERO_PWR_CTRL_B66 |= BIT4;
    SC_ZERO_PWR_CTRL_B66 |= BIT7;
    for(j=0; j<10000; j++) ResetWDTimer();//delay 20ms
#endif
#endif
    McuInitIO();
    ResetWDTimer();
    McuInitADC();
    McuInitMisc();
#if ENABLE_LPD == ON
    McuInitLPD();
#endif
#if IS_NT68810_SERIES || IS_NT68870_SERIES
#if MD_ENABLE_AO_DETECT == ON
#if ENABLE_FE2P == ON && USE_INTERNAL_EDID == 1
    FE2P_LoadDDC();
#endif
    McuInitDDC();
    CPU_CLK = 0x10;//MCU_CLK_TIMES << 4; // Restore CPU clock
    SC_HW_RST = 0x90; //Scaler will always stay in reset status
    while (McuCheckPwrStable() == FALSE) {
//        McuSetIOBit(MCU_PORT_C, BIT6, HIGH);
        ResetWDTimer();
//        McuSetIOBit(MCU_PORT_C, BIT6, LOW);
    }
#endif
#endif

#if ENABLE_FE2P == ON
    FE2P_RamInitialize();
#endif
#if USE_INTERNAL_EDID == 1
#if ENABLE_EDID_TRIM_MODE == ON
    if (InitEDIDTrim() == FALSE) {
        NvramLoadEDID();
    }
#else
    NvramLoadEDID();
#endif
#endif
    McuInitDDC();
    
    while (McuCheckPwrStable() == FALSE) {
//        McuSetIOBit(MCU_PORT_C, BIT6, HIGH);
        ResetWDTimer();
//        McuSetIOBit(MCU_PORT_C, BIT6, LOW);
    }
    McuInitIIC();

#if IS_NT68168_SERIES
    McuInitPWM();
#endif
    McuInitCore();
}

/**************************************************************************//**
 * Initialize MCU I/O port A ~ E.
 ******************************************************************************/
 
static void McuInitIO(void)
{
#if ENABLE_NEW_MCU_IO == 1
    McuCfgIOType(MCU_PORT_A, PORT_A_DEFAULT_PP, PORT_A_DEFAULT_PU);
    McuCfgIOType(MCU_PORT_B, PORT_B_DEFAULT_PP, PORT_B_DEFAULT_PU);
    McuCfgIOType(MCU_PORT_C, PORT_C_DEFAULT_PP, PORT_C_DEFAULT_PU);
    McuCfgIOType(MCU_PORT_D, PORT_D_DEFAULT_PP, PORT_D_DEFAULT_PU);
#ifdef PORT_E_DEFAULT_PP
    McuCfgIOType(MCU_PORT_E, PORT_E_DEFAULT_PP, PORT_E_DEFAULT_PU);
#endif
#ifdef PORT_3_DEFAULT_PP
    McuCfgIOType(MCU_PORT_3, PORT_3_DEFAULT_PP, PORT_3_DEFAULT_PU);
#endif
#endif
    McuSetIOByte(MCU_PORT_A, PORT_A_DEFAULT_OUT);
    McuSetIOByte(MCU_PORT_B, PORT_B_DEFAULT_OUT);
    McuSetIOByte(MCU_PORT_C, PORT_C_DEFAULT_OUT);
    McuSetIOByte(MCU_PORT_D, PORT_D_DEFAULT_OUT);
    McuSetIOByte(MCU_PORT_E, PORT_E_DEFAULT_OUT);
#ifdef PORT_3_DEFAULT_OUT	
    McuSetIOByte(MCU_PORT_3, PORT_3_DEFAULT_OUT);
#endif    
    McuSetIODirByte(MCU_PORT_A, PORT_A_DEFAULT_DIR);
    McuSetIODirByte(MCU_PORT_B, PORT_B_DEFAULT_DIR);
    McuSetIODirByte(MCU_PORT_C, PORT_C_DEFAULT_DIR);
    McuSetIODirByte(MCU_PORT_D, PORT_D_DEFAULT_DIR);
    McuSetIODirByte(MCU_PORT_E, PORT_E_DEFAULT_DIR);
}

/**************************************************************************//**
 * Initialize all MCU ADC channels.
 ******************************************************************************/
static void McuInitADC(void)
{
    McuDisableADC(~MCU_ADC_CON_DEFAULT);
    McuEnableADC(MCU_ADC_CON_DEFAULT);
}

/**************************************************************************//**
 * Initialize all MCU PWM channels.
 ******************************************************************************/
#if IS_NT68168_SERIES
static void McuInitPWM(void)
{
    McuDisablePWM(~MCU_PWM_CON_DEFAULT);
    McuSetPWM(MCU_PWM_0, MCU_PWM_0_DEFAULT);
    McuSetPWM(MCU_PWM_1, MCU_PWM_1_DEFAULT);
    McuSetPWM(MCU_PWM_2, MCU_PWM_2_DEFAULT);
    McuSetPWM(MCU_PWM_3, MCU_PWM_3_DEFAULT);
    McuSetPWM(MCU_PWM_4, MCU_PWM_4_DEFAULT);
    McuSetPWM(MCU_PWM_5, MCU_PWM_5_DEFAULT);
    McuSetPWM(MCU_PWM_6, MCU_PWM_6_DEFAULT);
    McuSetPWM(MCU_PWM_7, MCU_PWM_7_DEFAULT);
    McuSetPWM(MCU_PWM_8, MCU_PWM_8_DEFAULT);
    McuSetPWM(MCU_PWM_9, MCU_PWM_9_DEFAULT);
    McuSetPWM(MCU_PWM_10, MCU_PWM_10_DEFAULT);
    McuSetPWM(MCU_PWM_11, MCU_PWM_11_DEFAULT);
    McuEnablePWM(MCU_PWM_CON_DEFAULT);
}
#endif
/**************************************************************************//**
 * Initialize all MCU DDC channels.
 ******************************************************************************/
static void McuInitDDC(void)
{
    McuDisableDDC(~MCU_DDC_CON_DEFAULT);
    McuSetDDC(MCU_DDC_0, MCU_DDC0_ADDRESS, MCU_DDC0_EDIDLEN);
    McuSetDDC(MCU_DDC_1, MCU_DDC1_ADDRESS, MCU_DDC1_EDIDLEN);
    McuSetDDC(MCU_DDC_2, MCU_DDC2_ADDRESS, MCU_DDC2_EDIDLEN);
    McuSetDDC(MCU_DDC_3, MCU_DDC3_ADDRESS, MCU_DDC3_EDIDLEN);
#if IS_NT68870_SERIES
    McuSetDDC(MCU_DDC_4, MCU_DDC4_ADDRESS, MCU_DDC4_EDIDLEN);
#endif
    McuEnableDDC(MCU_DDC_CON_DEFAULT);
}

/**************************************************************************//**
 * Initialize all MCU IIC channels.
 ******************************************************************************/
static void McuInitIIC(void)
{
    McuDisableIIC(~MCU_IIC_CON_DEFAULT);
    McuSetIIC(MCU_IIC_0, MCU_IIC0_ADDRESS);
    McuSetIIC(MCU_IIC_1, MCU_IIC1_ADDRESS);
    McuSetIIC(MCU_IIC_2, MCU_IIC2_ADDRESS);
    McuSetIIC(MCU_IIC_3, MCU_IIC3_ADDRESS);
#if IS_NT68870_SERIES
    McuSetIIC(MCU_IIC_4, MCU_IIC4_ADDRESS);
#endif
    McuEnableIIC(MCU_IIC_CON_DEFAULT);
    McuIICPreSendACK(MCU_IIC_CON_DEFAULT);
}

/**************************************************************************//**
 * Initialize other necessary MCU registers.
 ******************************************************************************/
static void McuInitMisc(void)
{
    INT_SRC = 0x00; //Clear interrupt source flags
    INTEXT_FLG = 0xFF; //Clear all external interrupt flags
    INTEXT_EN = 0x00; //Disable all external interrupts
#if IS_NT68810_SERIES || IS_NT68870_SERIES
    LDO_ADJ = (LDO_ADJ&0x0F) | 0x90;//0x10; //Power down APLL, but Power up MCU ADC for 5V detection
#else
    SC_HW_RST = 0x90; //Scaler will always stay in reset status
    LDO_ADJ = (LDO_ADJ&0x0F) | 0x10; //Power down APLL, but Power up MCU ADC for 5V detection
#endif
    UART_MUX = MCU_UART_OUTPUT; //Uart output: IIC channel
    INTSC_EN = 0x01; //MCU allow scaler interrupt
    HDCP_MUX = DIGITAL_INPUT0_HDCP_MUX; //Set default HDCP channel
    IIC_MASK = IIC_MASK_VALUE; // Set I2C Mask for I2C/DDCCi Compatibilities
#if ENABLE_LOW_PWR_MODE == ON
    SC_ADC_ZERO_POWER_CTRL |= 0x83; // Enable scaler register read/write// 0xb57
#endif

#if ENABLE_FLASH_IDLE_MODE == ON
    SPI_OPTION |= BIT6;
    SPI_IDLE_CNT = 0x80;
#endif

#if IS_NT68770_SERIES_LATER || IS_NT68169_SERIES
#if MD_ENABLE_AO_DETECT == OFF
    AO_DETECT |= BIT3;
#endif
#endif
SC_CR_MUX = HDMI_DDC_CHANNEL;
}

/**************************************************************************//**
 * Initialize MCU core (basic 8051 SFR).
 ******************************************************************************/
static void McuInitCore(void)
{
    CPU_CLK = MCU_CLK_TIMES << 4;
    ucTL0_Normal_Power = (UCHAR)((65536-GetMCUTimer0Speed())%256);
    ucTH0_Normal_Power = (UCHAR)((65536-GetMCUTimer0Speed())/256);  
    ucTL0_LOW_POWER = (UCHAR)((65536-(USHRT)((float)REF_CLK/12000000*1000+0.5))%256);
    ucTH0_LOW_POWER = (UCHAR)((65536-(USHRT)((float)REF_CLK/12000000*1000+0.5))/256);
    ucTL0_LOW_POWER_3M = (UCHAR)((65536-(USHRT)((float)REF_CLK/12000000*250+0.5))%256);
    ucTH0_LOW_POWER_3M = (UCHAR)((65536-(USHRT)((float)REF_CLK/12000000*250+0.5))/256);

 
    McuPowerUpAPLL(); //Power up APLL after CPU clock was changed by NT68674 MCU APN.

    SCON = 0x52; //9-bit UART
    TMOD = 0x21; //Timer0: 16-bit timer, Timer1: 8-bit auto load 
    PCON = 0x80; //UART baud rate double
    TR0 = 1; //Start timer 0
    TR1 = 1; //Start timer 1

    //Set interrupt
    EX0 = 1; //Enable External Interrupt 0
    EX1 = 1; //Enable External Interrupt 1
    ET0 = 1; //Enable Timer 0 Interrupt
#if ENABLE_SERIAL_INT == ON
    ES = 1;  //Enable Serial Port Interrupt    
#endif
}

/**************************************************************************//**
 * Check the system power (5V) stable or not.
 * @return TRUE if system power is stable else FALSE.
 ******************************************************************************/
static BOOL McuCheckPwrStable(void)
{
    UCHAR i;

    for (i=0; i<=10; i++) {
        if (McuCheck5V() == FALSE) {
            return FALSE;
        }
    }
    
    return TRUE;
}

/**************************************************************************//**
 * Check system power is present or not.
 * @return TRUE if system power is present else FALSE.
 ******************************************************************************/
BOOL McuCheck5V(void)
{
#if ENABLE_CHECK_SYS5V == ON
#if ENABLE_LPD == ON
    if ((INTEXT_FLG & INT_LPD) != 0) {
        INTEXT_FLG = INT_LPD;
        return FALSE;
    }
#else
    McuPowerUpADC();
    McuStartADC();
    McuWaitADCComplete();
    if (McuGetADC(POWER_DETEC_ADC) < POWER_THRESHOLD) {
        return FALSE;
    }
    McuPowerDownADC();
#endif
#endif
    return TRUE;
}

#if IS_NT68810_SERIES || IS_NT68870_SERIES
extern void set_b62(void);
void WaitLDOReady(void)
{
    UCHAR i;
    for(i=0; i<10; i++) {
        ResetWDTimer();//delay 1ms
    }
}
#endif
/**************************************************************************//**
 * Turn on APLL power.
 ******************************************************************************/
void McuPowerUpAPLL(void)
{
    bIsAPLLPowerDown = FALSE;

    //Setup timer 0
    TL0 = ucTL0_Normal_Power;
    TH0 = ucTH0_Normal_Power;

    //Setup timer 1
    TL1 = 256 - GetUARTTimer(GetCPUClcok());
    TH1 = 256 - GetUARTTimer(GetCPUClcok());
    
#if IS_NT68810_SERIES || IS_NT68870_SERIES
#if IS_NT68810_SERIES || IS_NT68870_SERIES
    SC_APR_LDO_CTRL = 0x60;
//    McuSetIOBit(MCU_PORT_C, BIT6, LOW);
    WaitLDOReady();
//    McuSetIOBit(MCU_PORT_C, BIT6, HIGH);
    EA = 0;
    SC_POWER_CTRL1 |= BIT7;//power on 101[7]
    set_b62();
    EA = 1;
    SC_POWER_CTRL1 &= ~BIT7;//power on 101[7]
    WaitLDOReady();
#endif
#endif
    CPU_CLK = MCU_CLK_TIMES << 4; // Restore CPU clock

#if (!IS_NT68168_SERIES) && (!IS_NT68668_SERIES) && (!IS_NT68669_SERIES) && (!IS_NT68671_SERIES) && (!IS_NT68674_SERIES) && (!IS_NT68676_SERIES)
    if (((CPU_CLK & 0xF0) == 0x00) || ((CPU_CLK & 0xF0) == 0x10)) {
        if (!(LDO_ADJ & BIT7)) {
            SC_ADC_ZERO_POWER_CTRL |= 0x83;// 0xb57
            SC_MCU_PLL &= ~BIT1;    // APnote: When MCU CLK is 12Mhz,
                                    // we need to set 0xB04[0] as 0 before APLL power up.
        }
    }
#endif
    LDO_ADJ |= BIT7; //Power up APLL

#if IS_NT68671_SERIES
    IIC_MASK = IIC_MASK_VALUE; // Set I2C Mask for I2C/DDCCi Compatibilities
#endif
}

/**************************************************************************//**
 * Turn off APLL power.
 ******************************************************************************/
void McuPowerDownAPLL(void)
{
    bIsAPLLPowerDown = TRUE;

    //Setup timer 0
    TL0 = ucTL0_LOW_POWER;
    TH0 = ucTH0_LOW_POWER;

    //Setup timer 1
    TL1 = 256 - GetUARTTimer(REF_CLK);
    TH1 = 256 - GetUARTTimer(REF_CLK);
#if (!IS_NT68168_SERIES) && (!IS_NT68668_SERIES) && (!IS_NT68669_SERIES) && (!IS_NT68671_SERIES) && (!IS_NT68674_SERIES) && (!IS_NT68676_SERIES)
    if (((CPU_CLK & 0xF0) == 0x00) || ((CPU_CLK & 0xF0) == 0x10)) {
        if (LDO_ADJ & BIT7) {
            SC_MCU_PLL |= BIT1; // APnote: When MCU CLK is 12Mhz,
                                // we need to set 0xB04[0] as 1 before APLL power down.
        }
    }
#endif
    LDO_ADJ &= ~BIT7; //Power down APLL for power consumption

    CPU_CLK = 0x01 << 4; // Force CPU clock as 12 MHz when APLL power down. This
                         // can solve the issue of low SPI clock frequency under
                         // low power mode.

#if IS_NT68671_SERIES
    IIC_MASK = 0x00;
#endif
    McuIICPreSendACK(MCU_IIC_CON_DEFAULT);
}


