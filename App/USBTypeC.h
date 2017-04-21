/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/
#ifndef __USBTYPEC_H__
#define __USBTYPEC_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "Typedef.h"

//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************
#define USBCC_GetData() (SC_USBC_CC_RX_CTRL & CC_RX_RD_VALID)

//******************************************************************************
// G L O B A L   D E F I N I T I O N S
//******************************************************************************
// USB TypeC CC link layer
#define CC_Link0    0x00    // act as UFP
#define CC_Link1    0x01    // act as DFP 
// USB TypeC Port Power Role
#define Source      0
#define Sink        1
// USB TypeC Port Data Role
#define UFP         0
#define DFP         1
// USB TypeC timer unit
#define Unit_us     0x00
#define Unit_ms     0x80
//******************************************************************************
// D A T A   T Y P E   D E F I N E S
//******************************************************************************

//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************

//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
UCHAR GetTypeCADC(UCHAR adc);
void USBTypeCADCLevel(void);
void USBCCHWAutoStatMachine(UCHAR enable);
void USBCCIOPadInitial(void);
void USBCCIOADCRead(UCHAR cc_input);
BOOL IsUSBCCVBusAttach(void);
void USBCCLink0Initial(void);
void USBCCLink1Initial(void);
void USBCCGetCRCValue(void);
void USBCCIntFlagClear(void);
void USBCCIntFlagRead(void);
void USBCCIntEnable(void);
void USBCCSoftwareResetInt(void);
void USBCCSoftwareReset(void);
void USBCCTimerInitial(void);
void USBCCTimerSetting(UCHAR layer, UCHAR timer_type, UCHAR timer_unit, USHRT timer_num);
void USBCCManualTimerStart(UCHAR timer_type);
void USBCCTimerRead(UCHAR layer,UCHAR timer_type);
void USBCCCounterRead(UCHAR layer,UCHAR counter_type);
BOOL USBCCCheckIntTimeoutFlag(UCHAR timer_type);
void USBCCClearIntTimeoutFlag(UCHAR timer_type);
BOOL USBCCCheckIntCRCflag(void);
void USBCCClearIntCRCflag(void);
void SramDump(USHRT len);

#if 0//defined(ENABLE_FPGA_MODE)
void FPGA_USB_CC_Verify(void);
void FPGA_USB_CMD_TEST(void);
void FPGA_USB_Timer_Read(void);
void FPGA_USB_ControlMessage_Test(void);
void FPGA_USB_DataMessage_Test(void);
void FPGA_USB_MessageID_Test(void);
void FPGA_USB_Auto_MessageID_Test(void);
void FPGA_USB_Auto_Reply_GoodCRC_Test(void);
void FPGA_USB_Manual_Timer_Test(void);
void FPGA_USB_SendWrongCRC_Test(void);
void FPGA_USB_Retry_Counter_Test(void);
void FPGA_USB_DFPUFP_PDCommunication_Test(void);
void FPGA_USB_DFPUFP_VDOCommunication_Test(void);
void FPGA_USB_DFPUFP_VDM_Busy_Test(void);
void FPGA_USB_DFPUFP_VDOCommunication_Test_ByINT(void);
void FPGA_USB_UFP_BISTReceiverMode_Test(void);
void FPGA_USB_UFP_BISTTransmitMode_Test(void);
void FPGA_USB_UFP_BISTCarrierMode2_Test(void);
void FPGA_USB_UFP_BISTestData_Test(void);
void FPGA_USB_UFP_DP_HPD_Message_Test(void);
void FPGA_USB_1stSourceCap_TX_Check_mode_Test(void);
void FPGA_USB_Iniator_Request_Respone_MSG_Test(void);
void FPGA_USB_Iniator_Request_Respone_Timer_Test(void);
void FPGA_USB_Iniator_Ping_MSG_Test(void);
void FPGA_USB_PRBS_Test(void);
#endif

#endif 
