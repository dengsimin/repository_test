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
#if BACKLIGHT_ACTIVE == HIGH
    #define BLOffMacro(port) { UCHAR _temp_; \
                               _temp_ = Port##port; \
                               _temp_ |= RDP##port##_REG; \
                               _temp_ &= ~BACKLIGHT_BIT; \
                               Port##port = _temp_; }
#else
    #define BLOffMacro(port) { UCHAR _temp_; \
                               _temp_ = Port##port; \
                               _temp_ |= RDP##port##_REG; \
                               _temp_ |= BACKLIGHT_BIT; \
                               Port##port = _temp_; }
#endif
#if BACKLIGHT_PORT == MCU_PORT_A
    #define FastBLOff() BLOffMacro(A)
#elif BACKLIGHT_PORT == MCU_PORT_B
    #define FastBLOff() BLOffMacro(B)
#elif BACKLIGHT_PORT == MCU_PORT_C
    #define FastBLOff() BLOffMacro(C)
#elif BACKLIGHT_PORT == MCU_PORT_D
    #define FastBLOff() BLOffMacro(D)
#elif BACKLIGHT_PORT == MCU_PORT_E
    #define FastBLOff() BLOffMacro(E)
#elif BACKLIGHT_PORT == MCU_PORT_3
    #define FastBLOff() BLOffMacro(3)
#endif

#if ENABLE_SCALER_LEDDRV == ON
#undef FastBLOff
#define FastBLOff() {SC_LEDDRIVER_ENABLE = 0x00;}
#endif

//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************
idata USHRT usMCUCLKDIVIDERLoop;

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************
static BOOL bModeChanged = TRUE;
static idata USHRT volatile usTimerTick_1ms;
#if ENABLE_SERIAL_INT == ON
static idata UCHAR ucUARTTxOut;
static idata UCHAR ucUARTTxIn;
static idata UCHAR ucUARTRxOut;
static idata UCHAR ucUARTRxIn;
static xdata UCHAR ucUARTTxBuffer[UART_TX_BUFFER_SIZE];
static xdata UCHAR ucUARTRxBuffer[UART_RX_BUFFER_SIZE];
static xdata UCHAR ucIsTransDisabled;
#endif
#if ENABLE_AUTO_CONTROL == ON
#define UART_COMMAND_SIZE 8
static UCHAR ucCommandPointer;
static UCHAR ucCommandBuffer[UART_COMMAND_SIZE];
static UCHAR ucCommandStatus;
#endif
#if ENABLE_USB_TYPE_C == ON
static BOOL bUSBCCHWReset = FALSE;
static UCHAR ucErrorFlag = 0x00;
#endif
//******************************************************************************
// E X T E R N A L   V A R I A B L E   P R O T O T Y P E S
//******************************************************************************
extern BOOL bLowPowerMode;
extern BOOL bIsAPLLPowerDown;
extern idata UCHAR ucDdcciChannel;
extern BOOL bDDCCmdUpdate;
extern idata UCHAR ucDDCCiTxOut;
extern idata UCHAR ucDDCCiTxIn;
extern idata UCHAR ucDDCCiRxIn;
extern idata UCHAR ucDDCCiRxOut;
extern xdata UCHAR ucDDCCiTxBuffer[DDCCI_BUFFER_SIZE];
extern xdata UCHAR ucDDCCiRxBuffer[DDCCI_BUFFER_SIZE];

#if (INPUT_INTERFACE&INPUT_MHL_MASK)
idata USHRT usTimerTickMHL = 0;
extern idata USHRT usCBUSTimeoutDAT;
extern idata UCHAR ucMHLConnState;
extern idata UCHAR ucCBusState;
extern xdata UCHAR ucCbusBuffer[40];
extern BOOL bStartOfFrame;
extern BOOL bDDCWriteFlag;		// David, HTC debug.
extern BOOL bPackPixelModeIntFlag;
extern BOOL bWaitACK;
extern idata USHRT usCBUSTimeoutACK;
#endif

#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1)
#if EN_AUX_STROBE_FUNC == ON // AUX strobe function 
#define AUXBUFLEN 20
idata UCHAR ucAuxStrobeIndex;
xdata UCHAR ucAuxStrobeBuf[AUXBUFLEN];
idata UCHAR ucDPEDIDPtr;
extern xdata UCHAR volatile EDID_SRAM_DP[];
extern xdata UCHAR bDP_AUX_DETECT;
#endif
#endif

#if ENABLE_USB_TYPE_C == ON
extern BOOL bUSBCCMsgUpdate;
idata USHRT usTimerTickTypeC = 0;
#endif
//******************************************************************************
// S T A T I C   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
static char UART_Putchar(UCHAR c);

//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// F U N C T I O N   B O D Y S
//******************************************************************************

/**************************************************************************//**
 * Mcu external interrupt 0 service routine.
 ******************************************************************************/
void IntExt0(void) interrupt 0 using 1
{
#if ENABLE_LOW_PWR_MODE == ON
    SC_MCU_CLK_DIVIDER = 0x00;
#endif

#if IS_NT68850_SERIES 
#if ((INPUT_INTERFACE&INPUT_DP) && ENABLE_DP_AUX_MONITOR==ON)
    if(AUX_STROBE_CTL&BIT0) 
    {  
    	move_aux_packet();
    	return;
    }
#endif
#endif
#if (IS_NT68810_SERIES || IS_NT68870_SERIES)
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1)
    // Power Up DP AUX
    if(bLowPowerMode == TRUE) {  
        if ((SC_DP_AUX_DETECT&0xC0) != 0) {  // 0x101a
            INTSC_EN &= ~BIT1;
#if (INPUT_INTERFACE&INPUT_DP) && ENABLE_USB_TYPE_C == OFF
            PortE = (PortE | RDPE_REG) & (~BIT6); // HPD Low   // 0xf004 ,0xf009
#endif
#if (INPUT_INTERFACE&INPUT_DP1)
            PortE = (PortE | RDPE_REG) & (~BIT7); // HPD Low
#endif
        }
    }
#endif
#else
#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1)
    // Power Up DP AUX
    if(bLowPowerMode == TRUE) {  
        if ((SC_DP_AUX_DETECT&0xC0) != 0) {// 0x101a
            INTSC_EN &= ~BIT1;// 0x0f24
            LDO_ADJ |= BIT7; //Power up APLL  //20130715_1006_SYS#3   0xf050// 0xf050
        #if ENABLE_CUT_POWER_ARCH == ON
            SC_POWER_CTRL1 |= BIT7;//power on 101[7]   0x101
            SC_CUT_POWER_CTRL |= BIT0;//power on b62[0]// 0xb62
        #endif
            SC_HW_RST = 0x10; // 0xf04f
            SC_HW_RST = 0x11;
            SC_ADC_ZERO_POWER_CTRL = 0x83;		// 0xb57	
			
        #if ENABLE_CUT_POWER_ARCH == ON
            SC_POWER_CTRL1 |= BIT7; // 0x101
            SC_CUT_POWER_CTRL |= BIT2;  // 0xb62
            SC_CUT_POWER_CTRL |= BIT0;// 0xb62
            SC_ISOLATION_CONTROL = SCREB_B61_PU;
            SC_CUT_POWER_CTRL &= 0x07;// 0xb62
            SC_CUT_POWER_CTRL &= ~BIT1;// 0xb62
            SC_POWER_CTRL1 &= ~BIT7; // 0x101
        #endif

            SC_POWER_CTRL1 |= BIT5; // 0x101
            SC_MCU_CLK_DIVIDER = 0x00;  // 0xb54
#if !(IS_NT68810_SERIES || IS_NT68870_SERIES)
            SC_MPLL_X2 &= ~(BIT4|BIT3); //SC_MPLL_X2 = 0x03;   // 0xb46
#endif
            SC_POWER_CTRL1 &= ~(BIT5|BIT1); // 0x101

#if IS_NT68810_SERIES || IS_NT68870_SERIES
    #if DPHPD1_CTRLPIN == 1 || DPHPD2_CTRLPIN == 1
            PortE = (PortE | RDPE_REG) & (~BIT6); // HPD Low
            SC_MCU_IO_CTRL2 &= 0xF3; // output PE6/HPD1   // 0xc81
            DP_CTRL &= ~BIT4; // DP HPD_PAD disable   // 0xf0d2
    #endif
    #if DPHPD1_CTRLPIN == 2 || DPHPD2_CTRLPIN == 2
            PortE = (PortE | RDPE_REG) & (~BIT7); // HPD Low
            SC_MCU_IO_CTRL2 &= 0xFC; // output PE7/HPD2 // 0xc81
            DP_CTRL &= ~BIT5; // DP HPD_PAD disable // 0xf0d2
    #endif
#else
            PortD = (PortD | RDPD_REG) & (~BIT4); // HPD Low  // v20_130823_1815_SYS#6
            DP_CTRL &= ~BIT4; // DP HPD_PAD disable // 0xf0d2
#endif
            SC_TMDS_LINK_CLK_SEL = SCREG_1E7 | BIT0;  // dp_refclk select
            SC_DP_102F = REF_CLK*4/1000000;  // if 0x1E7[4:3] = 2'b00, dp_refclk = OSC clock*4
            
            DP_CLKOn();  
            DP_ConfigAUX2IICSpeed();
            
#if !(IS_NT68810_SERIES || IS_NT68870_SERIES)
            DP_InitPHY();
#endif
#if IS_NT68810_SERIES
            DP_InitPHY(_DPPP_PHY0);
#endif
#if IS_NT68870_SERIES
#if (INPUT_INTERFACE&INPUT_DP)
            DP_InitPHY(_DPPP_PHY0);
#endif
#if (INPUT_INTERFACE&INPUT_DP1)
            DP_InitPHY(_DPPP_PHY1);
#endif
#endif
            DP_InitDPCD();

            SC_DP_AUX_CTRL = 0x31; // AUX En

            DP_InitDPConfigPage();

#if IS_NT68810_SERIES || IS_NT68870_SERIES
    #if DPHPD1_CTRLPIN == 1 || DPHPD2_CTRLPIN == 1
            PortE = (PortE | RDPE_REG) | BIT6; // HPD High
            DP_CTRL |= BIT4; // DP HPD_PAD enable// 0xf0d2
            SC_MCU_IO_CTRL2 &= 0xF3; // output PE6/HPD1// 0xc81
    #endif
    #if DPHPD1_CTRLPIN == 2 || DPHPD2_CTRLPIN == 2
            PortE = (PortE | RDPE_REG) | BIT7; // HPD High
            DP_CTRL |= BIT5; // DP HPD_PAD enable// 0xf0d2
            SC_MCU_IO_CTRL2 &= 0xFC; // output PE7/HPD2// 0xc81
    #endif
#else
            PortD = (PortD | RDPD_REG) | BIT4; // HPD High
            DP_CTRL |= BIT4; // DP HPD_PAD enable// 0xf0d2
#endif
            SetDPLink();
        }
    }
#endif
#endif

#if (INPUT_INTERFACE&INPUT_MHL_MASK)
#if IS_NT68870_SERIES
	#if (INPUT_INTERFACE&INPUT_MHL0) || (INPUT_INTERFACE&INPUT_MHL1)	
    if ((MHL_SRC & BIT6) != 0) { // 0xF02D bit6	
    #elif (INPUT_INTERFACE&INPUT_MHL2) || (INPUT_INTERFACE&INPUT_MHL3)
    if ((MHL_SRC & BIT7) != 0) { // 0xF02D bit7	
	#endif
#else
    if ((MHL_SRC & INT_MHL) != 0) { // 0xF02D bit7
#endif
        idata UCHAR i;
        SC_ADC_ZERO_POWER_CTRL |= (BIT7|BIT1);// 0xb57
        i = SC_CBUS_INT_FLAG;
#if ENABLE_INT_DISCOVERY == ON
        if ( i & DIS_INT_FLG ) {			// Discovery int flag =1
            CbusDiscoveryHandler();
		#if IS_NT68810_SERIES || IS_NT68870_SERIES
			SC_CBUS_INT_FLAG = DIS_INT_FLG;
		#else
//            SC_CBUS_INT_EN |= DIS_INT_CLR;
        #endif
        }
#endif
        if ( i & TRANS_INT_FLG ) {      // Transaction interrupt
            if (MHL_GetMSCCmd()) {
                CbusMSCCmdHandler();
            }
            else if (MHL_GetDDCCmd()) {
                CbusDDCCmdHandler();
            }
#if IS_NT68810_SERIES || IS_NT68870_SERIES
			SC_CBUS_INT_FLAG = TRANS_INT_FLG;
#else
            SC_CBUS_INT_EN |= TRANS_INT_CLR;
#endif
        }
#if 1//def E_DEBUG
		if (i & LINK_INT_FLG) {     // Link layer interrupt
			if (SC_CBUS_LINK_INT_FLAG & CBUS_ARB_FAIL) {
				bCBusArbFailFlag = TRUE;
			}
#if IS_NT68810_SERIES || IS_NT68870_SERIES
			SC_CBUS_INT_FLAG = LINK_INT_FLG;
#else
    		SC_CBUS_INT_EN |= LINK_INT_CLR;
#endif
		}
#endif
    }
#endif

#if (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1)
#if EN_AUX_STROBE_FUNC == ON // AUX strobe function 
	if(DP_SRC & BIT7) {
        idata UCHAR i;
		// for INTS_SEL = command_end
//SC_DP_AUX_DETECT &= ~BIT0;//????????????????????????
		if (AUX_STROBE_CTL & BIT3) {
            ucAuxStrobeIndex = 0;
			while ((AUX_STROBE_FUN & BIT0) == 0) {
				if (ucAuxStrobeIndex < AUXBUFLEN) {
					ucAuxStrobeBuf[ucAuxStrobeIndex++] = AUX_STROBE_PORT;
					//*pDDCPtr1++ = ucAuxStrobeBuf[ucAuxStrobeIndex++];
				}
				else {// Read out data for empty
					i = AUX_STROBE_PORT;
				}				
			}
			AUX_STROBE_CTL |= BIT3;		// clear AUX_STROBE_INT
		}
		// decode AUX channel data.
		if ((ucAuxStrobeBuf[0] & BIT7) == 0) {		// I2C-over-AUX
			if ((ucAuxStrobeBuf[0] & (BIT5|BIT4)) == 0) {	// Write
				if ((ucAuxStrobeBuf[2] == 0x37) && (ucAuxStrobeIndex > 4))  {// DDC_CI Write
					// Reserved for DDC_CI Write decode....
                    ucDdcciChannel = 4;
//                    ucDDCCiRxIn = 0;
                    bDDCCmdUpdate = TRUE;
					i = ucAuxStrobeBuf[3] + 1;
					for (ucAuxStrobeIndex=0; ucAuxStrobeIndex<i; ucAuxStrobeIndex++) {
                        ucDDCCiRxBuffer[ucDDCCiRxIn++] = ucAuxStrobeBuf[4+ucAuxStrobeIndex];
                        if (ucDDCCiRxIn > DDCCI_BUFFER_SIZE-1) {
                            ucDDCCiRxIn = 2;
                        }
                    }
				}
				else if (ucAuxStrobeBuf[2] == 0x50) {	// EDID Write
					ucDPEDIDPtr = ucAuxStrobeBuf[4];
				}
				AUX_I2C_MANUAL = (AUX_I2C_MODE | AUX_I2C_FINSH);
			}
			else {		// Read
				if (ucAuxStrobeBuf[2] == 0x50) {	// EDID Read
					if (ucAuxStrobeIndex <= 3) {		// No length
						AUX_I2C_MANUAL = (AUX_I2C_MODE | AUX_I2C_FINSH);
					}
					else {
						i = ucAuxStrobeBuf[3] + 1;
						for (ucAuxStrobeIndex=0; ucAuxStrobeIndex<i; ucAuxStrobeIndex++) {
							AUX_I2C_MANUAL = (AUX_I2C_MODE);	// send ack
							AUX_I2C_DATA = EDID_SRAM_DP[ucDPEDIDPtr++];
						}
						AUX_I2C_MANUAL = (AUX_I2C_MODE | AUX_I2C_FINSH);
					}
				}
				else if (ucAuxStrobeBuf[2] == 0x37) {	// DDC_CI Read
//                    ucDdcciChannel = 4;
					if (ucAuxStrobeIndex <= 3) {		// No length
						AUX_I2C_MANUAL = (AUX_I2C_MODE | AUX_I2C_FINSH);
					}
					else {
						i = ucAuxStrobeBuf[3] + 1;
//                        ucDDCCiTxOut = 0;
						for (ucAuxStrobeIndex=0; ucAuxStrobeIndex<i; ucAuxStrobeIndex++) {
							AUX_I2C_MANUAL = (AUX_I2C_MODE);	// send ack
                            if (ucDDCCiTxOut != ucDDCCiTxIn) {
    							AUX_I2C_DATA = ucDDCCiTxBuffer[ucDDCCiTxOut++];
                            }
                            else {
                                AUX_I2C_DATA = ucDDCCiTxBuffer[ucDDCCiTxOut];
                                ucDDCCiTxOut = 0;
                            }
						}
						AUX_I2C_MANUAL = (AUX_I2C_MODE | AUX_I2C_FINSH);
					}
					
				}
			}
		}
		ucAuxStrobeIndex = 0;
	}
    else if (SC_DP_AUX_DETECT & BIT7) {// 0x101a
        SC_DP_AUX_DETECT |= BIT1;// 0x101a
        SC_DP_AUX_DETECT &= ~BIT1;// 0x101a
        bDP_AUX_DETECT = 1;// 0x101a
//	INTSC_EN &= ~BIT1;
//	AUX_STROBE_CTL = 0x00;
    }
#endif
#endif

// DDC0&2 ======================================================
    if ((INT_SRC & INT_IIC0) != 0) {
        ucDdcciChannel = 0;
        if (IIC0_INT_FLG & INTA) {
            IIC0_INT_CLR = INTA;
            if (IIC0_STATUS & DOWRITE) {  // Slave Addr || 0x01 ==> Read
                IIC0_INT_CLR = (INTTX | CLR_TX_FIFO);
                IIC0_TXDATA = ucDDCCiTxBuffer[0];
                IIC0_INT_EN = (INTA | INTTX);
                ucDDCCiTxOut = 1;
            }
            else {  // Slave Addr ==> Write
                IIC0_INT_EN = (INTA | INTRX);
                IIC0_CFG |= SEND_ACK;
                ucDDCCiRxIn = 0;
                bDDCCmdUpdate = TRUE;
            }
        }
        while (IIC0_INT_FLG & INTTX) {
            if (ucDDCCiTxOut != ucDDCCiTxIn) {
                IIC0_TXDATA = ucDDCCiTxBuffer[ucDDCCiTxOut++];
                IIC0_INT_CLR = INTTX;
            }
            else {
                IIC0_TXDATA = ucDDCCiTxBuffer[ucDDCCiTxOut];
                IIC0_INT_CLR = INTTX;
                ucDDCCiTxOut = 0;
            }
        }
        while (IIC0_INT_FLG & INTRX) {
            ucDDCCiRxBuffer[ucDDCCiRxIn++] = IIC0_RXDATA;
            IIC0_INT_CLR = INTRX;
            bDDCCmdUpdate = TRUE;
            if (ucDDCCiRxIn > DDCCI_BUFFER_SIZE-1) {
                ucDDCCiRxIn = 2;
            }
        } 
        if (IIC0_INT_FLG & INTNAK) {
            IIC0_INT_CLR = 0xFF;//INTNAK;
        }
        if (IIC0_INT_FLG & INTLOST) {
            IIC0_INT_CLR = 0xFF;//INTLOST;
        }
    }

    if ((INT_SRC & INT_IIC2) != 0) {
        ucDdcciChannel = 2;
        if (IIC2_INT_FLG & INTA) {
            IIC2_INT_CLR = INTA;
            if (IIC2_STATUS & DOWRITE) {  // Slave Addr || 0x01 ==> Read
                IIC2_INT_CLR = (INTTX | CLR_TX_FIFO);
                IIC2_TXDATA = ucDDCCiTxBuffer[0];
                IIC2_INT_EN = (INTA | INTTX);
                ucDDCCiTxOut = 1;
            }
            else {  // Slave Addr ==> Write
                IIC2_INT_EN = (INTA | INTRX);
                IIC2_CFG |= SEND_ACK;
                ucDDCCiRxIn = 0;
                bDDCCmdUpdate = TRUE;
            }
        }
        while (IIC2_INT_FLG & INTTX) {
            if (ucDDCCiTxOut != ucDDCCiTxIn) {
                IIC2_TXDATA = ucDDCCiTxBuffer[ucDDCCiTxOut++];
                IIC2_INT_CLR = INTTX;
            }
            else {
                IIC2_TXDATA = ucDDCCiTxBuffer[ucDDCCiTxOut];
                IIC2_INT_CLR = INTTX;
                ucDDCCiTxOut = 0;
            }
        }
        while (IIC2_INT_FLG & INTRX) {
            ucDDCCiRxBuffer[ucDDCCiRxIn++] = IIC2_RXDATA;
            IIC2_INT_CLR = INTRX;
            bDDCCmdUpdate = TRUE;
            if (ucDDCCiRxIn > DDCCI_BUFFER_SIZE-1) {
                ucDDCCiRxIn = 2;
            }
        } 
        if (IIC2_INT_FLG & INTNAK) {
            IIC2_INT_CLR = 0xFF;//INTNAK;
        }
        if (IIC2_INT_FLG & INTLOST) {
            IIC2_INT_CLR = 0xFF;//INTLOST;
        }
    }
    
#if IS_NT68870_SERIES
    if ((INT_SRC & INT_IIC4) != 0) {
        ucDdcciChannel = 5;
        if (IIC4_INT_FLG & INTA) {
            IIC4_INT_CLR = INTA;
            if (IIC4_STATUS & DOWRITE) {  // Slave Addr || 0x01 ==> Read
                IIC4_INT_CLR = (INTTX | CLR_TX_FIFO);
                IIC4_TXDATA = ucDDCCiTxBuffer[0];
                IIC4_INT_EN = (INTA | INTTX);
                ucDDCCiTxOut = 1;
            }
            else {  // Slave Addr ==> Write
                IIC4_INT_EN = (INTA | INTRX);
                IIC4_CFG |= SEND_ACK;
                ucDDCCiRxIn = 0;
                bDDCCmdUpdate = TRUE;
            }
        }
        while (IIC4_INT_FLG & INTTX) {
            if (ucDDCCiTxOut != ucDDCCiTxIn) {
                IIC4_TXDATA = ucDDCCiTxBuffer[ucDDCCiTxOut++];
                IIC4_INT_CLR = INTTX;
            }
            else {
                IIC4_TXDATA = ucDDCCiTxBuffer[ucDDCCiTxOut];
                IIC4_INT_CLR = INTTX;
                ucDDCCiTxOut = 0;
            }
        }
        while (IIC4_INT_FLG & INTRX) {
            ucDDCCiRxBuffer[ucDDCCiRxIn++] = IIC4_RXDATA;
            IIC4_INT_CLR = INTRX;
            bDDCCmdUpdate = TRUE;
            if (ucDDCCiRxIn > DDCCI_BUFFER_SIZE-1) {
                ucDDCCiRxIn = 2;
            }
        } 
        if (IIC4_INT_FLG & INTNAK) {
            IIC4_INT_CLR = 0xFF;//INTNAK;
        }
        if (IIC4_INT_FLG & INTLOST) {
            IIC4_INT_CLR = 0xFF;//INTLOST;
        }
    }
#endif
#if 0 //ENABLE_HDMI == ON
    if (((INT_SRC & INT_SC) != 0) || ((INT_SRC & INT_HDMI) != 0)) {
#else

// Scaler interrupt
    if ((INT_SRC & INT_SC) != 0) {
#endif
#if ENABLE_FAST_BK_OFF == ON
        FastBLOff();
#endif
        McuScalerIntDisable();
#if 0 //ENABLE_HDMI == ON
        McuScalerHDMIIntDisable();
#endif
        bModeChanged = TRUE;
    }
#if ENABLE_LOW_PWR_MODE == ON
    usMCUCLKDIVIDERLoop = 0;
#endif
}

/**************************************************************************//**
 * Mcu external interrupt 1 service routine.
 ******************************************************************************/
void IntExt1(void) interrupt 2 using 3
{
#if ENABLE_USB_TYPE_C == ON
    idata UCHAR flag;
   
    // UFP Port MCU Interrupt
    if ((INT_USB_CC & INT0_USBCC) != 0) { // MCU USB CC Interrupt at Link0 UFP port flag up
        SramDebug(0xF804, 0xBB);
#if 1
        // Judge the interrupt type
        flag = SC_USBC_CC_INT_GROUP_1_FLAG;   // Get SOP, Hard_reset, Soft_reset
        if (flag != 0) {   // cmd only
            /* To add cmd only here */
        }

        flag = SC_USBC_CC_INT_GROUP_2_FLAG;   // Get error flag for error handle
        if (flag !=0) {   // error handle
            /* To add error handle here */
            //USBCCErrorHandler();
            ucErrorFlag = flag;
        }

        flag = SC_USBC_CC_INT_GROUP_3_FLAG;
        if (flag & PROTOCOL_GET_PD_Msg) {   // Get PD message
            /* To add USB CC protocol handle here */
            //USBCCGetDataMessage(UFP);
            if (SC_USBC_CC_INT_GROUP_2_FLAG & Incrrect_CRC) {
                /* */
            }
            else {
                //ucUSBCPRLRxState=PRL_Rx_Send_GoodCRC;// Hw Auto reply GoodCRC
            }
#if 0
            if (USBCC_GetData()) { // UFP get control & Data message
                SramDebug(0xF806, 0x88);
                USBCCGetMessageHandle();
            }
            SC_USBC_CC_INT_GROUP_3_FLAG|=PROTOCOL_GET_PD_Msg;   // Clear get PD message
#else
            if (SC_USBC_CC_INT_GROUP_1_FLAG && PROTOCOL_GET_CMD_SOP) {
                if (USBCC_GetData()) { // UFP get control & Data message
                    SramDebug(0xF806, 0x88);
                    USBCCGetMessageHandler();
                }
                SC_USBC_CC_INT_GROUP_3_FLAG|=PROTOCOL_GET_PD_Msg;   // Clear get PD message
                usTimerTickTypeC = GetTimerTickInt();
                bUSBCCMsgUpdate = TRUE;
            }
            else if(SC_USBC_CC_INT_GROUP_1_FLAG && PROTOCOL_GET_CMD_SOPP) {
                USBCCSoftwareResetInt(); // UFP software reset
            }
            else {
                USBCCSoftwareResetInt(); // UFP software reset
            }
            if (SC_USBC_CC_INT_GROUP_1_FLAG && PROTOCOL_GET_CMD_HARD_RST) {//Get HW reset command
                bUSBCCHWReset = TRUE;
            }
#endif
        }
              
#endif
        // clear flag
        SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
        SC_USBC_CC_INT_GROUP_0_FLAG=0xEF;   // don't clear get good CRC flag
        SC_USBC_CC_INT_GROUP_1_FLAG=0xFF;   // Get cmd flag
        SC_USBC_CC_INT_GROUP_2_FLAG=0xFF;   // error flag for error handle
        SC_USBC_CC_INT_GROUP_3_FLAG=0xFF;   // get PD VDM .. message
        
    }
    SramDebug(0xF805, 0xCC);
//==========================================================================USB typeC
#endif
    
#if ENABLE_LOW_PWR_MODE == ON
    SC_MCU_CLK_DIVIDER = 0x00;
#endif

    if ((INT_SRC & INT_IIC1) != 0) {
        ucDdcciChannel = 1;
        if (IIC1_INT_FLG & INTA) {
            IIC1_INT_CLR = INTA;
            if (IIC1_STATUS & DOWRITE) {  // Slave Addr || 0x01 ==> Read
                IIC1_INT_CLR = (INTTX | CLR_TX_FIFO);
                IIC1_TXDATA = ucDDCCiTxBuffer[0];
                IIC1_INT_EN = (INTA | INTTX);
                ucDDCCiTxOut = 1;
            }
            else {  // Slave Addr ==> Write
                IIC1_INT_EN = (INTA | INTRX);
                IIC1_CFG |= SEND_ACK;
                ucDDCCiRxIn = 0;
                bDDCCmdUpdate = TRUE;
            }
        }
        while (IIC1_INT_FLG & INTTX) {
            if (ucDDCCiTxOut != ucDDCCiTxIn) {
                IIC1_TXDATA = ucDDCCiTxBuffer[ucDDCCiTxOut++];
                IIC1_INT_CLR = INTTX;
            }
            else {
                IIC1_TXDATA = ucDDCCiTxBuffer[ucDDCCiTxOut];
                IIC1_INT_CLR = INTTX;
                ucDDCCiTxOut = 0;
            }
        }
        while (IIC1_INT_FLG & INTRX) {
            ucDDCCiRxBuffer[ucDDCCiRxIn++] = IIC1_RXDATA;
            IIC1_INT_CLR = INTRX;
            bDDCCmdUpdate = TRUE;
            if (ucDDCCiRxIn > DDCCI_BUFFER_SIZE-1) {
                ucDDCCiRxIn = 2;
            }
        } 
        if (IIC1_INT_FLG & INTNAK) {
            IIC1_INT_CLR = 0xFF;//INTNAK;
        }
        if (IIC1_INT_FLG & INTLOST) {
            IIC1_INT_CLR = 0xFF;//INTLOST;
        }
    }

    if ((INT_SRC & INT_IIC3) != 0) {
        ucDdcciChannel = 3;
        if (IIC3_INT_FLG & INTA) {
            IIC3_INT_CLR = INTA;
            if (IIC3_STATUS & DOWRITE) {  // Slave Addr || 0x01 ==> Read
                IIC3_INT_CLR = (INTTX | CLR_TX_FIFO);
                IIC3_TXDATA = ucDDCCiTxBuffer[0];
                IIC3_INT_EN = (INTA | INTTX);
                ucDDCCiTxOut = 1;
            }
            else {  // Slave Addr ==> Write
                IIC3_INT_EN = (INTA | INTRX);
                IIC3_CFG |= SEND_ACK;
                ucDDCCiRxIn = 0;
                bDDCCmdUpdate = TRUE;
            }
        }
        while (IIC3_INT_FLG & INTTX) {
            if (ucDDCCiTxOut != ucDDCCiTxIn) {
                IIC3_TXDATA = ucDDCCiTxBuffer[ucDDCCiTxOut++];
                IIC3_INT_CLR = INTTX;
            }
            else {
                IIC3_TXDATA = ucDDCCiTxBuffer[ucDDCCiTxOut];
                IIC3_INT_CLR = INTTX;
                ucDDCCiTxOut = 0;
            }
        }
        while (IIC3_INT_FLG & INTRX) {
            ucDDCCiRxBuffer[ucDDCCiRxIn++] = IIC3_RXDATA;
            IIC3_INT_CLR = INTRX;
            bDDCCmdUpdate = TRUE;
            if (ucDDCCiRxIn > DDCCI_BUFFER_SIZE-1) {
                ucDDCCiRxIn = 2;
            }
        } 
        if (IIC3_INT_FLG & INTNAK) {
            IIC3_INT_CLR = 0xFF;//INTNAK;
        }
        if (IIC3_INT_FLG & INTLOST) {
            IIC3_INT_CLR = 0xFF;//INTLOST;
        }
    }
#if ENABLE_LOW_PWR_MODE == ON
    usMCUCLKDIVIDERLoop = 0;
#endif
}

/**************************************************************************//**
 * Mcu timer 0 interrupt service routine.
 ******************************************************************************/
void IntTimer0(void) interrupt 1 using 2
{
#if ENABLE_LOW_PWR_MODE == ON
//    if (bLowPowerMode == TRUE) {//3MHz
    if (SC_MCU_CLK_DIVIDER == 0x22) {//3MHz
        TL0 = ucTL0_LOW_POWER_3M;
        TH0 = ucTH0_LOW_POWER_3M;
    }
    else if (bIsAPLLPowerDown == TRUE) {
#else
    if (bIsAPLLPowerDown == TRUE) {
#endif    
        TL0 = ucTL0_LOW_POWER;
        TH0 = ucTH0_LOW_POWER;
    }
    else {
        TL0 = ucTL0_Normal_Power;
        TH0 = ucTH0_Normal_Power;
    }
    TR0 = 1; //Start Timer 0

    usTimerTick_1ms++;

#if (INPUT_INTERFACE&INPUT_MHL_MASK)
    if ((ucMHLConnState == MHL_DISCOVERY_RDY) && (bCBUSAbort == 0)) {
        if ((usTimerTick_1ms - usTimerTickMHL) > SET_HPD_TIMER) {//SET_HPD_TIMER
            if (!((MHL_GetMSCCmd() || MHL_GetDDCCmd()))) {
                SC_ADC_ZERO_POWER_CTRL |= (BIT7|BIT1);// 0xb57
    //            MHLCbusTx(TX_DDC_CMD, CBUS_SET_HPD); //this is using 1
                MHL_WaitCBusReady();
                bTranCMD = 0;
                ucCmdIndex = 0;//index to cMSCCmd
                bCheckTimeout = 0;
                SC_CBUS_MSC_CMD = CBUS_SET_HPD;
                ucCBusState = CBUS_SETHPD;
                ucMHLConnState = MHL_SET_HPD;
                bWaitACK = 1;
                usCBUSTimeoutACK = usTimerTick_1ms;
    #if 1//def E_DEBUG
                if (bCBusArbFailFlag == TRUE) {
                    bCBusArbFailFlag = FALSE;
                    SC_CBUS_MSC_CMD = CBUS_SET_HPD;
                }
    #endif
            }
        }
    }
#endif
}

#if ENABLE_SERIAL_INT == ON
/**************************************************************************//**
 * Mcu UART interrupt service routine.
 ******************************************************************************/
void IntUART(void) interrupt 4 using 1
{
    UCHAR i;
    
    if (RI == 1) {
        RI=0;
        i = SBUF;
        ucUARTRxBuffer[ucUARTRxIn] = i;
        if (++ucUARTRxIn > UART_RX_BUFFER_SIZE-1)
            ucUARTRxIn = 0;
    }

    if (TI == 1) {
        TI = 0;
        if (ucUARTTxIn != ucUARTTxOut) {
            SBUF = ucUARTTxBuffer[ucUARTTxOut];
            if (++ucUARTTxOut > UART_TX_BUFFER_SIZE-1)
                ucUARTTxOut = 0;
        }
        else {
            ucIsTransDisabled = 1;
        }
    }

}

/**************************************************************************//**
 * Put char into the TX buffer and enable UART transmission.
 ******************************************************************************/
static char UART_Putchar(UCHAR c)
{
    //If the buffer is full, return an error value.
    if (((ucUARTTxIn+1)%UART_TX_BUFFER_SIZE) == ucUARTTxOut) return -1;

    EA = 0;
    ucUARTTxBuffer[ucUARTTxIn] = c;
    if (++ucUARTTxIn > UART_TX_BUFFER_SIZE-1)
        ucUARTTxIn = 0;
    if (ucIsTransDisabled) {
        ucIsTransDisabled = 0;
        TI = 1;
    }
    EA = 1;
    
    return 0;
}

/**************************************************************************//**
 * The putchar function to replace the putchar in the standard library.
 * @param c Character.
 ******************************************************************************/
char putchar(char c)
{
    USHRT i;
    UCHAR k = 0;
    while (UART_Putchar(c) != 0) {
        for (i = 0; i < 1000; i++) {}
        if (++k > 10) {
            TI = 1;
        }
    }
    ResetWDTimer();
    
    return (c);
}
#endif

/**************************************************************************//**
 * Get the current value of timer tick.
 * @return Timer ticks.
 ******************************************************************************/
USHRT GetTimerTick(void)
{
    idata USHRT timer;

    do {
        timer = usTimerTick_1ms;
    } while (timer != usTimerTick_1ms);

    return timer;
}

/**************************************************************************//**
 * Check the status of mode changed flag.
 * @return TRUE if mode changed flag is TRUE else FALSE.
 ******************************************************************************/
BOOL CheckModeChangeFlag(void)
{
    return bModeChanged;
}

/**************************************************************************//**
 * Clear the mode changed flag.
 ******************************************************************************/
void ClearModeChangeFlag(void)
{
    bModeChanged = FALSE;
}

/**************************************************************************//**
 * Set mode changed flag.
 * We use this function to force the system to perform the mode changed processes.
 ******************************************************************************/
void SetModeChangeFlag(void)
{
    bModeChanged = TRUE;
}

#if ENABLE_AUTO_CONTROL == ON

extern void AT_Command(UCHAR cmd);

void UART_Handler(void)
{
#define CMD_NUM 5
#define CMD_LEN 7
code UCHAR CommandTab[CMD_NUM][CMD_LEN] = {
    {".VGA1  "},
    {".HDMI2 "},
    {".DP    "},
    {".HDMI1 "},
    {".CTOTAL"},
};
UCHAR n, l;
    if (ucCommandPointer != ucUARTRxIn) {
        ucCommandBuffer[ucCommandPointer] = ucUARTRxBuffer[ucCommandPointer];
//        printf("%x\r\n", (USHRT)ucCommandBuffer[ucCommandPointer]);
        UART_Putchar(ucCommandBuffer[ucCommandPointer]);
        if ((ucCommandBuffer[ucCommandPointer] == 0x0D) || (ucCommandBuffer[ucCommandPointer] == 0x0A)) {
            for (n=0; n<CMD_NUM; n++) {
                for (l = 0; l < CMD_LEN; l++) {
                    if (ucCommandPointer > l) {
//                        printf("%x\r\n", (USHRT)CommandTab[n][l]);
                        if (ucCommandBuffer[l] != CommandTab[n][l]) {
                            break;
                        }
                    }
                    else {
                        if (CommandTab[n][l] != 0x20) {
                            break;
                        }
                    }
                }
                if (l == CMD_LEN) {
                    AT_Command(n);
                    break;
                }
            }
            ucCommandPointer = 0;
            ucUARTRxIn = 0;
        }
        else {
            if (++ucCommandPointer > UART_COMMAND_SIZE - 1) {
                ucCommandPointer = 0;
                ucUARTRxIn = 0;
            }
        }
    }
}

#endif

#if (INPUT_INTERFACE&INPUT_MHL_MASK)
USHRT GetTimerTickInt() using 1
{
    return usTimerTick_1ms;
}
#endif

#if ENABLE_USB_TYPE_C == ON
BOOL CheckUSBCCHWResetFlag(void)
{
    return bUSBCCHWReset;
}

void ClearUSBCCHWResetFlag(void)
{
    bUSBCCHWReset = FALSE;
}

UCHAR CheckUSBCCErrorFlag(void)
{
    return ucErrorFlag;
}

void ClearUSBCCErrorFlag(void)
{
    ucErrorFlag = 0x00;
}
#endif

