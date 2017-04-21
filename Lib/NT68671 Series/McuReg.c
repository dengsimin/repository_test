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

//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************

//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************
//GPIO PORT CONTROL REGISTERS
xdata UCHAR volatile PortA _at_ 0xF000;
xdata UCHAR volatile PortB _at_ 0xF001;
xdata UCHAR volatile PortC _at_ 0xF002;
xdata UCHAR volatile PortD _at_ 0xF003;
xdata UCHAR volatile PortE _at_ 0xF004;
//GPIO PORT DIRECTION CONTROL REGISTERS
xdata UCHAR volatile RDPA_REG _at_ 0xF005;
xdata UCHAR volatile RDPB_REG _at_ 0xF006;
xdata UCHAR volatile RDPC_REG _at_ 0xF007;
xdata UCHAR volatile RDPD_REG _at_ 0xF008;
xdata UCHAR volatile RDPE_REG _at_ 0xF009;
//WATCH-DOG TIMER CONTROL REGISTER
xdata UCHAR volatile CLR_WDT _at_ 0xF00A;
//A/D CONVERTER CONTROL REGISTERS
xdata UCHAR volatile ADC_CON _at_ 0xF00B;
xdata UCHAR volatile ADC_CON2 _at_ 0xF080;
xdata UCHAR volatile ADC_REG0 _at_ 0xF00C;
xdata UCHAR volatile ADC_REG1 _at_ 0xF00D;
xdata UCHAR volatile ADC_REG2 _at_ 0xF00E;
xdata UCHAR volatile ADC_REG3 _at_ 0xF00F;
xdata UCHAR volatile ADC_REG4 _at_ 0xF081;
xdata UCHAR volatile ADC_REG5 _at_ 0xF082;
xdata UCHAR volatile ADC_REG6 _at_ 0xF083;
xdata UCHAR volatile ADC_REG7 _at_ 0xF084;
//PWM CHANNEL ENABLE CONTROL REGISTERS
xdata UCHAR volatile ENPWM_LB _at_ 0xF010;
xdata UCHAR volatile ENPWM_HB _at_ 0xF011;
xdata UCHAR volatile ENPWM_UB _at_ 0xF0A0;
//PWM CHANNEL CONTROL REGISTERS
xdata UCHAR volatile PWM_REG0 _at_ 0xF012;
xdata UCHAR volatile PWM_REG1 _at_ 0xF013;
xdata UCHAR volatile PWM_REG2 _at_ 0xF014;
xdata UCHAR volatile PWM_REG3 _at_ 0xF015;
xdata UCHAR volatile PWM_REG4 _at_ 0xF016;
xdata UCHAR volatile PWM_REG5 _at_ 0xF017;
xdata UCHAR volatile PWM_REG6 _at_ 0xF018;
xdata UCHAR volatile PWM_REG7 _at_ 0xF019;
xdata UCHAR volatile PWM_REG8 _at_ 0xF01A;
xdata UCHAR volatile PWM_REG9 _at_ 0xF01B;
xdata UCHAR volatile PWM_REG10 _at_ 0xF0A1;
xdata UCHAR volatile PWM_REG11 _at_ 0xF0A2;
//DDC PORT-0 CONTROL REGISTERS
xdata UCHAR volatile DDC_CTL0 _at_ 0xF01C;
xdata UCHAR volatile DDC_ADDR0 _at_ 0xF01D;
//DDC PORT-1 CONTROL REGISTERS
xdata UCHAR volatile DDC_CTL1 _at_ 0xF01E;
xdata UCHAR volatile DDC_ADDR1 _at_ 0xF01F;
//DDC PORT-2 CONTROL REGISTERS
xdata UCHAR volatile DDC_CTL2 _at_ 0xF085;
xdata UCHAR volatile DDC_ADDR2 _at_ 0xF086;
//DDC PORT-3 CONTROL REGISTERS
xdata UCHAR volatile DDC_CTL3 _at_ 0xF087;
xdata UCHAR volatile DDC_ADDR3 _at_ 0xF088;
//INTERRUPT SOURCE CONTROL REGISTER
xdata UCHAR volatile INT_SRC _at_ 0xF020;
//EXTERNAL INTERRUPT CONTROL REGISTERS
xdata UCHAR volatile INTEXT_FLG _at_ 0xF021;
xdata UCHAR volatile INTEXT_EN _at_ 0xF022;
//SCALER INTERRUPT CONTROL REGISTER
xdata UCHAR volatile INTSC_EN _at_ 0xF024;
//IIC PORT-0 CONTROL REGISTERS
xdata UCHAR volatile IIC0_CFG _at_ 0xF039;
xdata UCHAR volatile IIC0_STATUS _at_ 0xF03A;
xdata UCHAR volatile IIC0_INT_EN _at_ 0xF03B;
xdata UCHAR volatile IIC0_INT_FLG _at_ 0xF03C;
xdata UCHAR volatile IIC0_INT_CLR _at_ 0xF03D;
xdata UCHAR volatile IIC0_TXDATA _at_ 0xF03E;
xdata UCHAR volatile IIC0_RXDATA _at_ 0xF03F;
xdata UCHAR volatile IIC0_ADDR _at_ 0xF040;
//IIC PORT-1 CONTROL REGISTERS
xdata UCHAR volatile IIC1_CFG _at_ 0xF041;
xdata UCHAR volatile IIC1_STATUS _at_ 0xF042;
xdata UCHAR volatile IIC1_INT_EN _at_ 0xF043;
xdata UCHAR volatile IIC1_INT_FLG _at_ 0xF044;
xdata UCHAR volatile IIC1_INT_CLR _at_ 0xF045;
xdata UCHAR volatile IIC1_TXDATA _at_ 0xF046;
xdata UCHAR volatile IIC1_RXDATA _at_ 0xF047;
xdata UCHAR volatile IIC1_ADDR _at_ 0xF048;
//IIC PORT-2 CONTROL REGISTERS
xdata UCHAR volatile IIC2_CFG _at_ 0xF089;
xdata UCHAR volatile IIC2_STATUS _at_ 0xF08A;
xdata UCHAR volatile IIC2_INT_EN _at_ 0xF08B;
xdata UCHAR volatile IIC2_INT_FLG _at_ 0xF08C;
xdata UCHAR volatile IIC2_INT_CLR _at_ 0xF08D;
xdata UCHAR volatile IIC2_TXDATA _at_ 0xF08E;
xdata UCHAR volatile IIC2_RXDATA _at_ 0xF08F;
xdata UCHAR volatile IIC2_ADDR _at_ 0xF090;
//IIC PORT-3 CONTROL REGISTERS
xdata UCHAR volatile IIC3_CFG _at_ 0xF091;
xdata UCHAR volatile IIC3_STATUS _at_ 0xF092;
xdata UCHAR volatile IIC3_INT_EN _at_ 0xF093;
xdata UCHAR volatile IIC3_INT_FLG _at_ 0xF094;
xdata UCHAR volatile IIC3_INT_CLR _at_ 0xF095;
xdata UCHAR volatile IIC3_TXDATA _at_ 0xF096;
xdata UCHAR volatile IIC3_RXDATA _at_ 0xF097;
xdata UCHAR volatile IIC3_ADDR _at_ 0xF098;
//MISC CONTROL REGISTERS
xdata UCHAR volatile CPU_CLK _at_ 0xF04C;
xdata UCHAR volatile BANK_SET _at_ 0xF04D;
xdata UCHAR volatile DDC_THRES _at_ 0xF04E;
xdata UCHAR volatile SC_HW_RST _at_ 0xF04F;
xdata UCHAR volatile LDO_ADJ _at_ 0xF050;
xdata UCHAR volatile IIC_MASK _at_ 0xF053;
xdata UCHAR volatile UART_MUX _at_ 0xF054;
xdata UCHAR volatile SC_CR_MUX _at_ 0xF055;
xdata UCHAR volatile HDCP_MUX _at_ 0xF056;
xdata UCHAR volatile SPI_CURR _at_ 0xF05D;
xdata UCHAR volatile CURR_ADJ1 _at_ 0xF060;
xdata UCHAR volatile CURR_ADJ2 _at_ 0xF061;
xdata UCHAR volatile SLEW_CTL _at_ 0xF062;
// EDID SRAM
#if USE_INTERNAL_EDID == ON
xdata UCHAR volatile EDID_SRAM_BUFF0[256] _at_ 0xF800;
xdata UCHAR volatile EDID_SRAM_BUFF1[256] _at_ 0xF900;
xdata UCHAR volatile EDID_SRAM_BUFF2[256] _at_ 0xFA00;
xdata UCHAR volatile EDID_SRAM_BUFF3[256] _at_ 0xFB00;
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
