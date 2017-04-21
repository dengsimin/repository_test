/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/
#ifndef __USBTYPECHANDLER_H__
#define __USBTYPECHANDLER_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "Typedef.h"

//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************

//******************************************************************************
// G L O B A L   D E F I N I T I O N S
//******************************************************************************
#define Cmd_Init    0
#define Cmd_ACK     1
#define Cmd_NAK     2
#define Cmd_BUSY    3

// USB TypeC CC Command type
#define SOP                     0x00    // 
#define SOPP                    0x01    // 
#define SOPPP                   0x02    // 
#define Hard_Reset              0x03    // 
#define Cable_Reset             0x04    // 
#define SOPP_Debug              0x05    // 
#define SOPPP_Debug             0x06    // 

// riche add
#define ControlMsg              0x00
#define DataMsg                 0x01

// USB Type C Control Message- Messge type
#define GoodCRC                 0x01    // 6.3.1
#define GotoMin                 0x02    // 6.3.2    Sink TX not support this ctrl msg
#define Accept                  0x03    // 6.3.3
#define Reject                  0x04    // 6.3.4
#define Ping                    0x05    // 6.3.5    Sink TX not support this ctrl msg
#define PS_RDY                  0x06    // 6.3.6    Sink TX not support this ctrl msg
#define Get_Source_Cap          0x07    // 6.3.7
#define Get_Sink_Cap            0x08    // 6.3.8    Sink TX option support this ctrl msg, NT68870?
#define DR_SWAP                 0x09    // 6.3.9    TypeC only    
#define PR_SWAP                 0x0A    // 6.3.10   Sink TX not support this ctrl msg
#define VCONN_SWAP              0x0B    // 6.3.11
#define Wait                    0x0C    // 6.3.12   Sink TX not support this ctrl msg
#define Soft_Reset              0x0D    // 6.3.13

// USB Type C Data Message- Messge type
#define Source_Capabilities     0x01    // 6.4.1.2
#define Request                 0x02    // 6.4.2
#define BIST                    0x03    // 6.4.3
#define Sink_Capabilities       0x04    // 6.4.1.3
#define Vendor_Defined          0x0F    // 6.4.4

// USB Type C Data Message- Vendor_Define Messge - Structured VDM Header
//  SVID, VDM_Header[31:16]
#define PD_SID                  0xFF00  // 6.4.4.2.1
#define DP_SID                  0xFF01
// VDM Type, VDM_Header[15]
#define UnstructuredVDM         0x00
#define StructuredVDM           0x80
// VDM Version, VDM_Header[14:13]
#define StructuredVDMVersion    0x00
// Reserved, VDM_Header[12:11]
// Object Position, VDM_Header[10:8]
//#define Enter_Mode      0x01
//#define Exit_Mode       0x07
//#define Attention      0x01
// Command Type, VDM_Header[7:6]
#define Initiator               0x00
#define Responder_ACK           0x40
#define Responder_NAK           0x80
#define Responder_BUSY          0xC0
// Command, VDM_Header[4:0]
#define Discover_Identity       0x01
#define Discover_SVIDS          0x02
#define Discover_Modes          0x03
#define Enter_Mode              0x04
#define Exit_Mode               0x05
#define Attention               0x06
#define DP_Status_Update        0x10
#define DP_Configure            0x11

#define Discover_Identity_Busy  0x20
#define Discover_Identity_Ack   0x21
#define Discover_SVID_Ack       0x22
#define DP_Discover_Mode_Ack    0x23
#define DP_Enter_Mode_Ack       0x24
#define DP_Exit_Mode_Ack        0x25
#define DP_Status_Update_Ack    0x26
#define DP_Configure_Ack        0x27
#define Attention_HPD_Low       0x28

#define Discover_Identity_Nack  0x31
#define Discover_SVID_Nack      0x32
#define DP_Discover_Mode_Nack   0x33
#define DP_Enter_Mode_Nack_SVID 0x34 //SVID is wrong
#define DP_Exit_Mode_Nack_SVID  0x35 //SVID is wrong
#define DP_Enter_Mode_Nack_OP   0x36 //Object position is wrong
#define DP_Exit_Mode_Nack_OP    0x37 //Object position is wrong
#define DP_Status_Update_Nack   0x38
#define DP_Configure_Nack       0x39

#define TI_VID                  0x00000451
#define Novatek_VID             0x00000603

// DP Capability (VDO in Responder Discover Modes VDM)

// DP Status

// DP Configurations


//USB Typec Timer type
#define Manu0                   0x00
#define Manu1                   0x10
#define CRCReceiverTimer        0x20
#define SenderResponseTimer     0x30
#define SinkActivityTimer       0x40
#define SinkWaitCapTimer        0x50
#define SinkRequestTimer        0x60
#define BISTContModeTimer       0x70
#define CRCTransmitTimer        0x80

//USB Typec Counter type
#define MessageIDCounter        0x00
#define RetryCounter            0x40
#define BISTCounter             0x80
#define VDMBusyCounter          0xC0


// USB Type C BIST Data Obj Mode type
#define BISTReceiverMode        0x00    // 6.4.3
#define BISTTransmitMode        0x10    // 6.4.3
#define ReturnedBISTCounters    0x20    // 6.4.3
#define BISTCarrierMode2        0x50    // 6.4.3.6
#define BISTEyePattern          0x70    // 6.4.3.6
#define BISTTestData            0x80    // 6.4.3.6

#define USBCC_BUF_LEN           30

// USB Type C CC1&CC2 voltage threshold for Default 500mA, 1.5A@5V, 3A@5V
#define USBCC_Voltage_TH0       0x0D    // 0.3046V  under this no CC attach
#define USBCC_Voltage_TH1       0x1D    // 0.679V
#define USBCC_Voltage_TH2       0x38    // 1.314V

//******************************************************************************
// D A T A   T Y P E   D E F I N E S
//******************************************************************************
/*--------------------------------------------------------------------------*/
/* Variables for USB CC Message                                                */
/*--------------------------------------------------------------------------*/
/*
struct    usbCCMessage{
    UCHAR   numDataObject;  // number of Data Objects
    UCHAR   MessageID;  // number of Data Objects
    BOOL    PortPowerRole;  //
    UCHAR   SpecRev;  // number of Data Objects
    BOOL    PortDataRole;  // 
    UCHAR   MessageType;  // number of Data Objects
};
*/
/*
struct    usbCCMessage{
    usbCCMessageHeader  headerT;
    usbCCDataObj        DataObj0;
    usbCCDataObj        DataObj1;
};
*/

struct usbCCMessageHeader{
    UCHAR Header_HByet;
    UCHAR Header_LByte;
};

struct usbCCDataObj{
    UCHAR Header_HByet;
    UCHAR Header_LByte;
};

//typedef enum _USBCC_CONNECT_STATUS_ {
    //CC_UNKNOWN = 0xFF,
    //CC_UNACTIVE = 0x00,
    //CC_GET_MESSAGE = 0x01,
    //CC_GET_CMD_ONLY =0x02

//}USBCCSTATUS;

typedef enum _USBCCBUS_STATUS_ {
    CC_UNKNOWN = 0xFF,
    CC_UNACTIVE = 0x00,
    CC_GET_MESSAGE = 0x01,
    CC_GET_CMD_ONLY =0x02
    /*
    CBUS_SETHPD = 0x02,
    CBUS_MSG_RCPK = 0x06,
    CBUS_CLRHPD = 0x0E,
    CBUS_ACTIVE = 0x0F,
    CONNECTED_RDY = 0x30,
    LINK_MODE = 0x31,
    RCHANGE_INT = 0x20,
    RDEV_VER = 0x10,
    RDEV_CAT = 0x11,
    RDEV_LOG = 0x12,
    RDEV_VID_LINK = 0x13,
    RDEV_VIDEO_TYPE = 0x14,
    RDEV_BANDWIDTH = 0x15,
    RDEV_AUDIO = 0x16
    */
}USBCCSTATUS;

typedef enum _USBCCMSG_TYPE_ {
    CCMsgType_UNKNOWN,
    CCMsgType_Control,
    CCMsgType_Data,
}USBCCMSGTYPE;

// USB TypeC Protocol Layer transmittering state, all 10 state
typedef enum _USBCC_PRL_TX_STATUS_ {
    PRL_Tx_PHY_Layer_Reset = 0x00,      // 6.8.2.1.1
    PRL_Tx_Wait_for_Message_Request,    // 6.8.2.1.2
    PRL_Tx_Layer_Reset_for_Transmit,    // 6.8.2.1.3
    PRL_Tx_Construct_Message,           // 6.8.2.1.4
    PRL_Tx_Wait_for_PHY_Response,       // 6.8.2.1.5
    PRL_Tx_Match_MessageID,             // 6.8.2.1.6
    PRL_Tx_Message_Sent,                // 6.8.2.1.7
    PRL_Tx_Check_RetryCounter,          // 6.8.2.1.8
    PRL_Tx_Transmission_Error,          // 6.8.2.1.9
    PRL_Tx_Discard_Message,             // 6.8.2.1.10
}USBCCPRLTXState;

// USB TypeC Protocol Layer Reception state, all 5 state
typedef enum _USBCC_PRL_RX_STATUS_ {
    PRL_Rx_Wait_for_PHY_Message = 0x00,
    PRL_Rx_Layer_Reset_for_Receive,
    PRL_Rx_Send_GoodCRC,
    PRL_Rx_Check_MessageID,
    PRL_Rx_Store_MessageID,
}USBCCPRLRXState;

//USB TypeC Policy Engine State
typedef enum _USBCC_PE_SNK_STATUS_ {
    PE_SNK_Startup = 0x00,              //8.3.3.3.1
    PE_SNK_Discovery,                   //8.3.3.3.2
    PE_SNK_Wait_for_Capabilities,       //8.3.3.3.3
    PE_SNK_Evaluate_Capability,         //8.3.3.3.4
    PE_SNK_Select_Capability,           //8.3.3.3.5
    PE_SNK_Transition_Sink,             //8.3.3.3.6
    PE_SNK_Ready,                       //8.3.3.3.7
    PE_SNK_Hard_Reset,                  //8.3.3.3.8
    PE_SNK_Transition_to_default,       //8.3.3.3.9
    PE_SNK_Give_Sink_Cap,               //8.3.3.3.10
    PE_SNK_Get_Source_Cap,              //8.3.3.3.11

    PE_SNK_Send_Soft_Reset,             //8.3.3.4.2.1
    PE_SNK_Soft_Reset,                  //8.3.3.4.2.2
}USBCCPESNKState;


//USB TypeC VMD Discover state
typedef enum _USBCC_VDM_DISCOVER_STATUS_ {
    VDM_Discover_unknow = 0x00,
    VDM_Discover_Identity,
    VDM_Discover_SVIDS,
    VDM_Discover_Modes,
    VDM_Enter_Mode,
    VDM_DP_Status_Update,
    VDM_DP_Configure,
    VDM_Attention,
}USBCCDiscoverState;

//20151126: richie add
typedef struct _PD_MSG_HEADER_{
    UCHAR MsgType : 4;
    UCHAR Rsvd1 : 1;
    UCHAR DR : 1;    // 0b: UFP  ; 1b: DFP
    UCHAR SpecRev : 2; //00b: Revision 1.0 ; 01b: Revision 2.0
    UCHAR PR : 1;    // 0b: Sink  ; 1b: Source
    UCHAR MsgID : 3;
    UCHAR ObjCnt : 3;
    UCHAR Rsvd2 : 1;
} PDMsgHeader;

typedef struct _PD_MESSAGE_{
    USHRT Header;
    ULONG object[7];
} PDMsg;

typedef struct _SINK_CAPABILITIES_MSG_{
    USHRT Opr_Cur; //B9..0      //10mA units
    USHRT Vol; //B19..10         // 50mV units
    UCHAR Rsvd : 5; //B24..20
    UCHAR DR_Swap_Supp : 1; //B25
    UCHAR USB_Com_Cap : 1; //B26
    UCHAR Ext_Pow : 1; //B27
    UCHAR Higher_Cap : 1; //B28
    UCHAR Dual_Role : 1; //B29
    UCHAR SupplyType : 2; //B31..30
} SinkCapabilitiesMsg;

typedef struct _SOURCE_CAPABILITIES_MSG_{
    USHRT Max_Cur; //B9..0
    USHRT Vol; //B19..10
    UCHAR Peak_Curr : 2; //B21..20
    UCHAR Rsvd : 3; //B24..22
    UCHAR DR_Swap_Supp : 1; //B25
    UCHAR USB_Com_Cap : 1; //B26
    UCHAR Ext_Pow : 1; //B27
    UCHAR USB_Suspend : 1; //B28
    UCHAR Dual_Role : 1; //B29
    UCHAR SupplyType : 2; //B31..30
} SourceCapabilitiesMsg;

typedef struct _REQUEST_MSG_{
    USHRT Max_Opr_Cur; //B9..0
    USHRT Opr_Cur ; //B19..10
    UCHAR Rsvd1 : 4; //B23..20
    UCHAR No_USB_Suspend : 1; //B24
    UCHAR USB_Com_cap : 1; //B25
    UCHAR Cap_Mismatch : 1; //B26
    UCHAR Give_Back : 1; //B27
    UCHAR Obj_Pos : 3; //B30..28
    UCHAR Rsvd2 : 1; //B31
} RequestMsg;

typedef struct _STRUCTURE_VDM_HEADER_{
    UCHAR Cmd : 5; //B4..0
    UCHAR Rsvd1 : 1; //B5
    UCHAR Cmd_Type : 2; //B7..6     //00b: Initiator; 01b: ACK; 10b: NAK; 11b: BUSY
    UCHAR Obj_Pos : 3; //B10..8
    UCHAR Rsvd2 : 2; //B12..11
    UCHAR VDM_Ver : 2; //B14..13
    UCHAR Type : 1; //B15
    USHRT Vendor_ID; //B31..16  
} StructuredVDMHeader;


typedef struct _ID_HEADER_VDO_{
    USHRT Vendor_ID; //B15..0
    USHRT Rsvd; //B25..16
    UCHAR Modal_Opr : 1; //B26
    UCHAR Prod_Type : 3; //B29..27
    UCHAR Device_Cap : 1; //B30
    UCHAR Host_Cap : 1; //B31
} IDHeaderVDO;

typedef struct _CEERT_STAT_VDO_{
    ULONG Test_ID; //B19..0
    USHRT Rsvd; //B31..20
} CertStatVDO;

typedef struct _PRODUCT_VDO_{
    USHRT bcd_Device; //B15..0
    USHRT Product_ID; //B31..16
} ProductVDO;

typedef struct _SVIDs_{
    USHRT SVID0; //B15..0
    USHRT SVID1; //B31..16
} SVIDs;

typedef struct _Mode1_{
    ULONG Mode; //B31..0
} Mode1;

typedef struct _Status_Update_{
    ULONG Status; //B31..0
} StatusUpdate;

typedef struct _ATTENTION_VDOs_{
    ULONG VDOs; //B31..0
} AttentionVDOs;

//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************

//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
extern void USBTypeCInit(void);
extern void USBTypeCInitialState(void);
extern void USBTypeCHandler(void);
extern void ClearTypeCDisplay(void);
extern void USBCCGetMessageHandler();
extern void USBCCSendMessageHandler();
extern void USBCCRXStateHandler();
extern void USBCCTXStateHandler();
extern void USBCCErrorHandler();
extern void USBCCLink0Receiver(void);
extern void USBCCLink0Transiver(void);
extern void USBCCLink1Receiver(void);
extern void USBCCLink1Transiver(void);
extern void USBCCSendCommand(UCHAR layer,UCHAR cmd_type);
extern void USBCCSendControlMessage(UCHAR layer,UCHAR Message_type);
//extern void USBCCSendDataMessage(void);
//extern void USBCCSendDataMessage(UCHAR layer,UCHAR num_DataObj,UCHAR Message_type);
extern void USBCCSendDataMessage(UCHAR layer,UCHAR num_DataObj,UCHAR msg_ID,UCHAR Message_type);
extern void USBCCSendBISTMessage(UCHAR layer,UCHAR num_DataObj,UCHAR msg_ID,UCHAR BIST_Mode);
extern void USBCCSendVDOMessage(UCHAR layer,UCHAR num_DataObj,UCHAR msg_ID,UCHAR VDO_Type);
extern void USBCCGetCommand(UCHAR layer,UCHAR cmd_type);
extern void USBCCGetControlMessage(void);
//extern void USBCCGetDataMessage(void);
extern void USBCCGetDataMessage(UCHAR layer);
extern BOOL IsUSBCCAttach(void);
extern void USBCCConfigHPD(BOOL enable);
extern BOOL IsUSBCCHPDActive(void);
extern BOOL IsUSBCCConnect(void);
extern UCHAR USBCCGetVDMDiscoverState(void);

#endif 
