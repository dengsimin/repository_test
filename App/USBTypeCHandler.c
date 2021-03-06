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
#if ENABLE_USB_TYPE_C == ON
//******************************************************************************
// G L O B A L   D E F I N I T I O N S
//******************************************************************************

//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************
idata UCHAR ucUSBTypeCConnState = 0x00;
idata UCHAR ucUSBCCState = CC_UNACTIVE;
idata UCHAR ucUSBMessageType = CCMsgType_UNKNOWN;
idata UCHAR ucUSBCCPEState = PE_SNK_Startup;

idata UCHAR ucUSBCPRLTxState;   // Protocol layer transmission state 
idata UCHAR ucUSBCPRLRxState;   // Protocol layer reception state
BOOL bUSBCCMsgUpdate = FALSE;
extern idata USHRT usTimerTickTypeC;

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************
static xdata BOOL bWaitSendAttention = FALSE;
static xdata BOOL bUSBCCHPDActive = FALSE;
static xdata UCHAR ucVDMDiscoverState = 0x00;
//struct    usbCCMessageHeader TX1MessageHeader;
static xdata BOOL bUSBCCAttach = FALSE;
static xdata BOOL bUSBCCChanged = FALSE;
static xdata UCHAR ucDataObjLen;
static xdata UCHAR ucUSBCCBuffer[USBCC_BUF_LEN];
static xdata UCHAR ucSinkHeader[2];
static xdata UCHAR ucRXMessageID;
static xdata UCHAR ucRXStoreMessageID;
static xdata UCHAR ucTXMessageID;
// Source Data Obj
static xdata UCHAR ucSourcePDO[4]={0x96,0x90,0x01,0x36};

static xdata UCHAR ucSinkPDO[4]={0xC8,0x90,0x01,0x26};
static xdata UCHAR ucSinkVDMHeader[4];
static xdata UCHAR ucSinkIDHeader[4];
static xdata UCHAR ucSinkCertVDO[4];
static xdata UCHAR ucSinkProductVDO[4];
static bit bTypeCDisplay;
static xdata USHRT usTypeCTimer;
static xdata UCHAR ucRetryCnt = 0;
code PDMsgHeader defaultTXPDMsgHeader = {
    0x04,//UCHAR MsgType : 4;
    0x00,//UCHAR Rsvd1 : 1;
    0x00,//UCHAR DR : 1;    // 0b: UFP  ; 1b: DFP
    0x01,//UCHAR SpecRev : 2;  //00b: Revision 1.0 ; 01b: Revision 2.0
    0x00,//UCHAR PR : 1;    // 0b: Sink  ; 1b: Source
    0x01,//UCHAR MsgID : 3;
    0x01,//UCHAR ObjCnt : 3;
    0x00,//UCHAR Rsvd2 : 1;
};

// 0x96, 0x90, 0x01, 0x26
code SinkCapabilitiesMsg defaultSinkCapMsg = {
    0x96,//USHRT usOpr_Cur : 10; //B9..0
    0x64,//USHRT usVol : 10; //B19..10
    0x00,//UCHAR usRsvd : 5; //B24..20
    0x01,//UCHAR bDR_Swap_Supp : 1; //B25
    0x01,//UCHAR bUSB_Com_Cap : 1; //B26
    0x00,//UCHAR bExt_Pow : 1; //B27
    0x00,//UCHAR bHigher_Cap : 1; //B28
    0x01,//UCHAR bDual_Role : 1; //B29
    0x00,//UCHAR ucSupplyType : 2; //B31..30
};

// 0x5A, 0x68, 0x01, 0x11
code RequestMsg defaultRequestMsg = {
    0x5A,//USHRT Max_Opr_Cur : 10; //B9..0
    0x5A,//USHRT Opr_Cur : 10; //B19..10
    0x00,//UCHAR Rsvd1 : 4; //B23..20
    0x01,//UCHAR No_USB_Suspend : 1; //B24
    0x00,//UCHAR USB_Com_cap : 1; //B25
    0x00,//UCHAR Cap_Mismatch : 1; //B26
    0x00,//UCHAR Give_Back : 1; //B27
    0x01,//UCHAR Obj_Pos : 3; //B30..B28
    0x00,//UCHAR Rsvd2 : 1; //B31
};

// 0x41,0x80,0x00,0xFF,
code StructuredVDMHeader defaultStructuredVDMHeader = {
    0x01,//UCHAR Cmd : 5; //B4..0
    0x00,//UCHAR Rsvd1 : 1; //B5
    0x01,//UCHAR Cmd_Type : 2; //B7..6
    0x00,//UCHAR Obj_Pos : 3; //B10..8
    0x00,//UCHAR Rsvd2 : 2; //B12..11
    0x00,//UCHAR VDM_Ver : 2; //B14..13
    0x01,//UCHAR Type : 1; //B15
    PD_SID,//USHRT Vendor_ID: 16; //B31..16  
};

//0x51,0x04,0x00,0xC4,
code IDHeaderVDO defaultIDHeaderVDO = {
    0x0451,//USHRT Vendor_ID : 16; //B15..0
    0x0000,//USHRT Rsvd : 10; //B25..16
    0x01,//UCHAR Modal_Opr : 1; //B26
    0x00,//UCHAR Prod_Type : 3; //B29..27
    0x01,//UCHAR Device_Cap : 1; //B30
    0x01,//UCHAR Host_Cap : 1; //B31
} ;

//0x51,0x04,0x00,0x00,
code CertStatVDO defaultCertStatVDO = {
    //0x00000451,//ULONG Test_ID : 20; //B19..0
    Novatek_VID,
    0x0000,//USHRT Rsvd : 12; //B31..20
} ;

//0x10,0x00,0x34,0x12
code ProductVDO defaultProductVDO = {
    0x0010,//USHRT bcd_Device : 16; //B15..0
    0x1234,//USHRT Product_ID : 16; //B31..16
} ;

//0x00,0x00,0x01,0xFF
code SVIDs defaultSVIDs = {
    0x0000,//USHRT SVID1; //B15..0
    DP_SID,//USHRT SVID2; //B31..16
};

//0x45,0x00,0x10,0x00
code Mode1 defaultmode1 = {
    0x00100045,//ULONG Mode; //B31..0
};

//0x1A,0x00,0x00,0x00
code StatusUpdate defaultStatus = {
    0x0000001A,//ULONG Status; //B31..0
};

//0x9A,0x00,0x00,0x00
code AttentionVDOs defaultAttentionVDOs = {
    0x0000009A,//ULONG VDOs; //B31..0
};
static PDMsgHeader TXPDMsg_Header;  
static PDMsg PDMsgTX_Packet;

#define SetTXPDMsgType(a) {TXPDMsg_Header.MsgType = a;}
#define SetTXPDMsgObjCnt(a) {TXPDMsg_Header.ObjCnt = a;}
#define GetTXPDMsgObjCnt() (TXPDMsg_Header.ObjCnt)
#define PacketTXPDMsgHeader() { PDMsgTX_Packet.Header = (USHRT)TXPDMsg_Header.MsgType | (TXPDMsg_Header.Rsvd1<<4) \
                             | (TXPDMsg_Header.DR<<5) | (TXPDMsg_Header.SpecRev<<6) \
                             | (TXPDMsg_Header.PR<<8) | (TXPDMsg_Header.MsgID<<9) \ 
                             | (TXPDMsg_Header.ObjCnt<<12) | (TXPDMsg_Header.Rsvd2<<15);}
//#define GetRXPDMsgType(m) (m&0x000F)
//#define GetRXPDMsgObjCnt(m) ((m&0x7000) >> 12)

//******************************************************************************
// E X T E R N A L   V A R I A B L E   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// S T A T I C   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
static BOOL IsUSBCCSVIDCorrect(void);
static UCHAR USBCCGetObjectPosition(void);
static USHRT USBCCGetSourceMaxCurrent(void);
static BOOL USBCCIsCRCTimeout(void);
static void USBCCSendSoftReset(void);
static void USBCCSendHardReset(void);
static UCHAR USBCCSendMessagewithRetryCnt(UCHAR cmdtype, UCHAR command);
static void USBCCPEStateHandler(void);
static void USBCCCheckSourceCapMsg(void);
static void USBCCClearCRCFlag(void);

//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
/*-----------------------------------------------------------------------------
 *
 * Module: IsUSBCCSVIDCorrect()
 * Description:
 *
 *----------------------------------------------------------------------------*/
static BOOL IsUSBCCSVIDCorrect(void)
{
    //printf("(%x,%x) %x\r\n",(USHRT)ucUSBCCBuffer[2],(USHRT)ucUSBCCBuffer[3],(USHRT)ucVDMDiscoverState);
    if (ucVDMDiscoverState >= VDM_Discover_SVIDS) {
        if (ucUSBCCBuffer[2] == 0x01 && ucUSBCCBuffer[3] == 0xFF) {
            return TRUE;
        }
    }
    else {
        if (ucUSBCCBuffer[2] == 0x00 && ucUSBCCBuffer[3] == 0xFF) {
            return TRUE;
        }
    }

    return FALSE;
}

/*-----------------------------------------------------------------------------
 *
 * Module: USBCCGetObjectPosition()
 * Description:
 *
 *----------------------------------------------------------------------------*/
static UCHAR USBCCGetObjectPosition(void)
{
    UCHAR temp;

    temp = (ucUSBCCBuffer[1]&0x07);
    return temp;
}

/*-----------------------------------------------------------------------------
 *
 * Module: USBCCGetSourceMaxCurrent()
 * Description:
 *
 *----------------------------------------------------------------------------*/
static USHRT USBCCGetSourceMaxCurrent(void)
{
    USHRT current;

    current = (ucUSBCCBuffer[0] | ((ucUSBCCBuffer[1]&0x03)<<8));
    return current;
}

/*-----------------------------------------------------------------------------
 *
 * Module: USBCCIsCRCTimeout()
 * Description:
 *
 *----------------------------------------------------------------------------*/
static BOOL USBCCIsCRCTimeout(void)
{
    Sleep(2);
    if ((SC_USBC_CC_INT_GROUP_0_FLAG & BIT4) == 0x00) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

/*-----------------------------------------------------------------------------
 *
 * Module: USBCCClearCRCFlag()
 * Description:
 *
 *----------------------------------------------------------------------------*/
static void USBCCClearCRCFlag(void)
{
    USBCCClearIntCRCflag();
    USBCCClearIntTimeoutFlag(CRCReceiverTimer_Flag);
}

/*-----------------------------------------------------------------------------
 *
 * Module: USBCCSendSoftReset()
 * Description:
 *
 *----------------------------------------------------------------------------*/
static void USBCCSendSoftReset(void)
{
    UCHAR counter = 0;

    //printf("USBCCSendSoftReset <---\r\n");
    USBCCClearCRCFlag();
#if 1
    USBCCSendControlMessage(CC_Link0, Soft_Reset);

    //CTS TD.PD.LL.E4 Hard Reset Usage
    do {
        if (USBCCIsCRCTimeout() == TRUE) {
            USBCCClearCRCFlag();
            USBCCSendControlMessage(CC_Link0, Soft_Reset);
            //printf("==\r\n");
            counter++;
        }
        else {
            break;
        }

    } while(counter < 3);

    if (counter == 3) {
#else
    if (USBCCSendMessagewithRetryCnt(ControlMsg, Soft_Reset) == 3) {
#endif
        //hard reset
        //printf("hard reset <---\r\n");
        USBCCSendHardReset();
    }
    else {
        ucUSBCCPEState = PE_SNK_Send_Soft_Reset;
        DBGPRN1(PRN_PE_STATE, "===>PE_SNK_Send_Soft_Reset\r\n");
    }
}

/*-----------------------------------------------------------------------------
 *
 * Module: USBCCSendHardReset()
 * Description:
 *
 *----------------------------------------------------------------------------*/
static void USBCCSendHardReset(void)
{
    USBCCSendCommand(CC_Link0,Hard_Reset);
    Sleep(5);
    USBTypeCInit();
    ucRetryCnt++;
    DBGPRN1(PRN_PE_STATE, "===>PE_SNK_Startup\r\n");
}

/*-----------------------------------------------------------------------------
 *
 * Module: USBCCSendCommandwithRetry(UCHAR cmdtype, UCHAR command)
 * Description:
 *
 *----------------------------------------------------------------------------*/
static UCHAR USBCCSendMessagewithRetryCnt(UCHAR cmdtype, UCHAR command)
{
    UCHAR cnt;

    cnt = 0;    
    USBCCClearCRCFlag();

    if (cmdtype == ControlMsg) {
        USBCCSendControlMessage(CC_Link0, command);
        do {
            if (USBCCIsCRCTimeout() == TRUE) {
                USBCCClearCRCFlag();
                USBCCSendControlMessage(CC_Link0, command);
                Sleep(1);   //for CTS test. for request.                
                cnt++;
            }
            else {
                break;
            }
        } while(cnt < 3);
    }
    else { //DataMsg
        USBCCSendDataMessage(CC_Link0, 1, 0, command);
        do {
            if (USBCCIsCRCTimeout() == TRUE) {
                USBCCClearCRCFlag();
                USBCCSendDataMessage(CC_Link0, 1, 0, command);
                Sleep(1);   //for CTS test. for request.                
                cnt++;
            }
            else {
                break;
            }
        } while(cnt < 3);
    }

    return cnt;
}
/*-----------------------------------------------------------------------------
 *
 * Module: USBCCPEStateHandler()
 * Description:
 *
 *----------------------------------------------------------------------------*/
static void USBCCPEStateHandler(void)
{
    switch (ucUSBCCPEState)
    {
        case PE_SNK_Startup: //initial state
            break;
        case PE_SNK_Discovery: //check Vbus
            break;
        case PE_SNK_Wait_for_Capabilities: //get vbus
            if ((USBCCCheckIntTimeoutFlag(SinkWaitCapTimer_Flag) == TRUE) && (SystemData.bPDdone == FALSE) && (ucRetryCnt < 2)) {
                //CTS TD.PD.SNK.E2 timeout without sourec capabilities message
                //send hard reset
                USBCCSendHardReset();
                //printf("<-- CC Hard_Reset 1\r\n");
            }
            break;
        case PE_SNK_Evaluate_Capability: //get sourec capabilities message
            break;
        case PE_SNK_Select_Capability: //send request message
            if (USBCCCheckIntTimeoutFlag(SenderResponseTimer_Flag) == TRUE) {
                //CTS TD.PD.SNK.E6 timeout without accept meaage
                //send hard reset
                USBCCSendHardReset();
                //printf("<-- CC Hard_Reset 2\r\n");
            }
            break;
        case PE_SNK_Transition_Sink: //get accept meaage
            if (USBCCCheckIntTimeoutFlag(Manual_Timer0_Flag) == TRUE) {
                //CTS TD.PD.SNK.E8 timeout without PS_RDY meeasge
                //send hard reset
                USBCCSendHardReset();
                //printf("<-- CC Hard_Reset 3\r\n");
            }
            break;
        case PE_SNK_Ready: //get PS_RDY meeasge
            break;
        case PE_SNK_Hard_Reset:
            break;
        case PE_SNK_Transition_to_default:
            break;
        case PE_SNK_Give_Sink_Cap:
            break;
        case PE_SNK_Get_Source_Cap:
            break;
        case PE_SNK_Send_Soft_Reset:
            break;
        case PE_SNK_Soft_Reset:
            break;
    }
}

/*-----------------------------------------------------------------------------
 *
 * Module: USBCCCheckSourceCapMsg()
 * Description:
 *
 *----------------------------------------------------------------------------*/
static void USBCCCheckSourceCapMsg(void)
{
    if (ucUSBCCPEState == PE_SNK_Wait_for_Capabilities) {
        if ((USBCCCheckIntTimeoutFlag(SinkWaitCapTimer_Flag) == TRUE) && (SystemData.bPDdone == FALSE) && (ucRetryCnt < 2)) {
            //CTS TD.PD.SNK.E2 timeout without sourec capabilities message
            //send hard reset
            USBCCSendHardReset();
            printf("<-- CC Hard_Reset 1\r\n");
        }
    }
}

/*-----------------------------------------------------------------------------
 *
 * Module: USBTypeCInit()
 * Description:
 *
 *----------------------------------------------------------------------------*/
void USBTypeCInit(void)
{
//    UCHAR i;
    DBGPRN1(PRN_USBCC, "USB CC Initial \r\n");
    /* Interrupt Debug use
    DBGPRN2(PRN_USBCC, "EX1= 0x%bx\n ", EX1);
    DBGPRN2(PRN_USBCC, "EX0= 0x%bx\n ", EX0);
    */
    // Int Debgug use
    //for (i=0; i<0x7F; i++) {
    //    SramDebug(0xF800+i, 0x00);
    //}

    //SC_DVI_CTRL_32F=0x12; // bit4=1 index of CCRTX1  and Enable FPGA PH6 = PIN_AL9 : clk and PH7 = PIN_AP10 : data
    //SC_DVI_CTRL_32F=0x02; // bit4=0 index of CCRTX0

    //USBCCIOADCRead();
    
    USBCCIOPadInitial();    // UFP chip need to add this,FPGA no need

    //USBCCIOADCRead();

    // combo IO mux IO select CC1 and CC2
    SC_MCU_IO_CTRL4 = (SC_MCU_IO_CTRL4 & 0xFC) | 0x02;  // PB3 0xC83[1:0] set 10 is CC1
    SC_MCU_IO_CTRL9 = (SC_MCU_IO_CTRL9 & 0x3F) | 0x80;  // PE4 0xC88[7:6] set 10 is CC2    
    
    USBCCLink0Initial();    // UFP
    //SC_USBC_CC_TX_AUTO_MSGID=0x11;  // 0xD75 [0]=0 disable auto msgID, [4]=0 no chk grant
        
    //USBCCLink1Initial();    // DFP
    //SC_USBC_CC_TX_AUTO_MSGID=0x11;  // 0xD75 [0]=0 disable auto msgID, [4]=0 no chk grant

    USBTypeCInitialState();
    // using for MacBook communication    
    USBCCIntEnable();

    // Set timer value
    USBCCTimerInitial();

#ifdef ENABLE_FPGA_MODE
    FPGA_USB_CC_Verify();
#endif
    bTypeCDisplay = 0;
    SystemData.bPDdone = FALSE;
}

/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:IsUSBCCAttach()
 *
 *----------------------------------------------------------------------------*/
BOOL IsUSBCCAttach(void)
{
    if (IsUSBCCVBusAttach() == TRUE) {
        if ((SC_USBC_CC_CFG & BIT1) == 0x00) { //connected
            SC_USBC_CC_CFG |= BIT1;
            bUSBCCChanged = TRUE;
            //printf("USBCC Connected\r\n");

            ucVDMDiscoverState = VDM_Discover_unknow;
            ucUSBCCPEState = PE_SNK_Wait_for_Capabilities;
            DBGPRN1(PRN_PE_STATE, "===>PE_SNK_Wait_for_Capabilities\r\n");
            USBCCClearIntTimeoutFlag(SinkWaitCapTimer_Flag);
            ucRetryCnt = 0;
        }
        bUSBCCAttach = TRUE;        
    }
    else {
        if ((SC_USBC_CC_CFG & BIT1) == BIT1) { //disconnected
            SC_USBC_CC_CFG &= ~BIT1;
            bUSBCCChanged = TRUE;
            //printf("USBCC Disconnected\r\n");

            ucVDMDiscoverState = VDM_Discover_unknow;
            ucUSBCCPEState = PE_SNK_Discovery;
            DBGPRN1(PRN_PE_STATE, "===>PE_SNK_Discovery\r\n");
            if ((GetTypeCADC(TYPEC_CC1_ADC) < USBCC_Voltage_TH0) && (GetTypeCADC(TYPEC_CC2_ADC) < USBCC_Voltage_TH0)) { // disconnected
                bTypeCDisplay = 0;
            }
        }
        bUSBCCAttach = FALSE;
        SystemData.bPDdone = FALSE;
    }

    return bUSBCCAttach;
}

/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:
 *
 *----------------------------------------------------------------------------*/
void USBTypeCInitialState(void)
{
    ucTXMessageID = 0x00;
    ucRXMessageID = 0x00;
    ucRXStoreMessageID = 0x00;
    
    ucUSBCPRLTxState = PRL_Tx_PHY_Layer_Reset;
    ucUSBCPRLRxState = PRL_Rx_Wait_for_PHY_Message;
    ucUSBCCPEState = PE_SNK_Startup;
    DBGPRN1(PRN_PE_STATE, "===>PE_SNK_Startup\r\n");

    //richie add
    TXPDMsg_Header = defaultTXPDMsgHeader;
}

/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:
 *
 *----------------------------------------------------------------------------*/
void PDMSendMessage(UCHAR type,UCHAR message_type)
{
    UCHAR i=0;
    //UCHAR isValid = FALSE; //send or not?!

    if (type == DataMsg) {
        SetTXPDMsgType(message_type);
        switch(message_type){
            case Source_Capabilities:
                break;
            case Request:
                break;
            case BIST:
                break;
            case Sink_Capabilities:
                break;
            case Vendor_Defined:
                break;
            default:
                break;
        }
    }
    PacketTXPDMsgHeader();//make sure repacket header.
#if 1     
    SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
    SC_USBC_CC_TX_CTRL=BIT2;    // TX addres reset
    SC_USBC_CC_TX_CTRL=0x00;    // TX addres reset

    SC_USBC_CC_TX_WRITE_DATA = (UCHAR)(PDMsgTX_Packet.Header);
    SC_USBC_CC_TX_WRITE_DATA =(UCHAR)(PDMsgTX_Packet.Header>>8);

    for (i=0; i<GetTXPDMsgObjCnt(); i++) {
        SC_USBC_CC_TX_WRITE_DATA = (UCHAR)(PDMsgTX_Packet.object[i]);
        SC_USBC_CC_TX_WRITE_DATA = (UCHAR)(PDMsgTX_Packet.object[i] >>8);
        SC_USBC_CC_TX_WRITE_DATA = (UCHAR)(PDMsgTX_Packet.object[i] >>16);
        SC_USBC_CC_TX_WRITE_DATA = (UCHAR)(PDMsgTX_Packet.object[i] >>24);
    }
    SC_USBC_CC_TX_CTRL|=0x01;   // send control message out

    /*
    Need to check information after send message 
    step1:Start CRCReceiveTimer  
    step2:When get feedback GoodCRC, need to check MessageID and Stop GoodCRC
    */

#else
    printf("%bx ", (UCHAR)(PDMsgTX_Packet.Header));
    printf("%bx ,", (UCHAR)(PDMsgTX_Packet.Header>>8));

    for(i=0; i<GetTXPDMsgObjCnt(); i++) {
        printf("%bx ",(UCHAR)(PDMsgTX_Packet.object[i]));
        printf("%bx ", (UCHAR)(PDMsgTX_Packet.object[i] >>8));
        printf("%bx ", (UCHAR)(PDMsgTX_Packet.object[i] >>16));
        printf("%bx ,", (UCHAR)(PDMsgTX_Packet.object[i] >>24));
    }
    printf("\r\n");
#endif
}

/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:
 *
 *----------------------------------------------------------------------------*/
void USBTypeCHandler(void)
{
    USBTypeCADCLevel();

    if (IsZpMode() == TRUE) {
        return;
    }

    if (IsUSBCCAttach() == TRUE) {
        if (bUSBCCChanged == TRUE) {
            USBCCIOADCRead(GetCurrInputInterface());
            bUSBCCChanged = FALSE;
        }
    }
    else {
        return;
    }

    //USBCCRXStateHandler();
    //USBCCTXStateHandler();
    USBCCCheckSourceCapMsg(); //only get vbus but no message.
    if (bUSBCCMsgUpdate == TRUE) {
        bUSBCCMsgUpdate = FALSE;
        do {
            USBCCPEStateHandler();
            USBCCSendMessageHandler();
        } while((GetTimerTick()-usTimerTickTypeC) < 100);
    }

    if ((bWaitSendAttention == TRUE) && (GetCurrInputInterface() == USB_TYPE_C_INTERFACE)) {
        ucVDMDiscoverState = VDM_Attention;
        USBCCSendVDOMessage(UFP,2,0,Attention);
        //DBGPRN1(1, "2.-->UFP send Attention <--\r\n");
        bWaitSendAttention = FALSE;
        SystemData.bPDdone = TRUE;
        usTypeCTimer = GetTimerTick();
    }

#if 0
    if (CheckUSBCCHWResetFlag() == TRUE) {
        ClearUSBCCHWResetFlag();
        printf("--->Get CC HW reset\r\n");
    }
#endif
#if 1
    if (CheckUSBCCErrorFlag() != 0x00) {
        printf("--->Get CC ERROR %x\r\n",(USHRT)CheckUSBCCErrorFlag());
        ClearUSBCCErrorFlag();
    }
#endif
#if 1
    //Recover PD done but not receive display data.
    if (SystemData.bPDdone == TRUE) {
        if ((GetCurrInputInterface() == USB_TYPE_C_INTERFACE) && (bTypeCDisplay == 0)) {
            if (GetTimerTick()-usTypeCTimer > 2000) {//hard reset
                if (IsDPTrainingDone() == FALSE) {
                    printf("<--USBCCSendHardReset\r\n");
                    USBCCSendHardReset();
                }
                bTypeCDisplay = 1;
            }
        }
    }
#endif
}

/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:
 *
 *----------------------------------------------------------------------------*/
void USBCCGetMessageHandler()
{
    idata UCHAR temp,cmd_type,msg_type;
    idata UCHAR i;
    
    SC_DVI_CTRL_32F &= (~BIT4); // UFP bit4=0 index of CCRTX0  

    temp = SC_USBC_CC_RX_CTRL;
    if (temp & 0x80) {// command only, Only Hard_Reset is correct cmd
        cmd_type = SC_USBC_CC_RX_CTRL&CC_RX_RD_CMD_MASK;  // SOP* ...
        ucUSBCCState = CC_GET_CMD_ONLY;
        /* cmd_type must be Hard reset and need to do hard reset*/
        // Hard reset reset both the power supplies and protocol
        
    }
    else {// Control message or data message
        ucUSBCCState = CC_GET_MESSAGE;
        
        // Gate CC 測起來沒實際作用,so close it
        SC_USBC_CC_RX_CTRL |= BIT1;   // CC_RX read gate set 1, Gate CC if previous message not read out
        
        SC_USBC_CC_RX_CTRL |= BIT2;   // CC_RX manual address reset
        SC_USBC_CC_RX_CTRL &= ~BIT2;
        for (i=0; i<2; i++) {// Read Header First
            ucSinkHeader[i] = SC_USBC_CC_RX_READ_DATA;
        }

        ucDataObjLen = (ucSinkHeader[0] & 0x70)>>4; // Hi-Byte[6:4]
        ucRXMessageID = (ucSinkHeader[0] & 0x0E)>>1;// Hi-Byte[3:1]
        msg_type= ucSinkHeader[1]&0x0F;// Lo-Byte[3:0]
    }

    if (ucDataObjLen == 0) { // Get Control Message
        ucUSBMessageType = CCMsgType_Control;
        switch ( msg_type ) {
            case GoodCRC:
                break;
            case GotoMin:
                break;
            case Accept:
                if ((ucUSBCCPEState == PE_SNK_Select_Capability)||(ucUSBCCPEState == PE_SNK_Evaluate_Capability)) {//maybe DFP reply accept too fast
                    ucUSBCCPEState = PE_SNK_Transition_Sink;
                    USBCCClearIntTimeoutFlag(Manual_Timer0_Flag); //Use for PsTransitionTimer
                    USBCCManualTimerStart(Manu0);
                }
                if (ucUSBCCPEState == PE_SNK_Send_Soft_Reset) {
                    ucUSBCCPEState = PE_SNK_Wait_for_Capabilities;
                    USBCCClearIntTimeoutFlag(SinkWaitCapTimer_Flag);
                }
                break;
            case Reject:
                break;
            case Ping:
                break;
            case PS_RDY:
                //if (ucUSBCCPEState == PE_SNK_Transition_Sink) {
                    ucUSBCCPEState = PE_SNK_Ready;
                //}
                break;
            case Get_Source_Cap:
                break;
            case Get_Sink_Cap:
                break;
            case DR_SWAP:
                break;
            case PR_SWAP:
                break;
            case VCONN_SWAP:
                break;
            case Wait:
                break;
            case Soft_Reset:
                break;
                
            default:
                break;
        }
    }
    else {   // Get Data message
        ucUSBMessageType = CCMsgType_Data;
        for (i=0;i<ucDataObjLen*4;i++) {// Read Data OBJ,Only Data Obj no Header
            ucUSBCCBuffer[i]=SC_USBC_CC_RX_READ_DATA;
        }

        switch ( msg_type ) {
            case Source_Capabilities:
                if (ucUSBCCPEState == PE_SNK_Wait_for_Capabilities) {
                    ucUSBCCPEState = PE_SNK_Evaluate_Capability;
                }
                break;
            case Request:
                break;
            case BIST:
                break;
            case Sink_Capabilities:
                break;
            case Vendor_Defined:
                break;
            default:
                break;
        }
    }
}

/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:
 *
 *----------------------------------------------------------------------------*/
void USBCCSendMessageHandler()
{
    UCHAR msg_type1,VDM_command,BIST_command;
    //UCHAR i,CC_DATA_ARRAY[28];
    UCHAR flag = 0;
    //UCHAR retry;

    if (ucUSBCCState == CC_GET_MESSAGE) {
        ucUSBCCState = CC_UNACTIVE;
        //DBGPRN2(PRN_USBCC,"HeaderHB = %bx\n", ucSinkHeader[0]);
        //DBGPRN2(PRN_USBCC,"HeaderLB = %bx\n", ucSinkHeader[1]);
        //DBGPRN2(PRN_USBCC,"RXMSG_ID = %bx\n", ucRXMessageID);
        //DBGPRN2(PRN_USBCC,"DataObj = %bx\n", ucDataObjLen);

        msg_type1 = ucSinkHeader[1] & 0x0F;

        //printf("(%x,%x)\r\n",(USHRT)ucUSBMessageType,(USHRT)msg_type1);
        if (ucUSBMessageType == CCMsgType_Control) {
            switch ( msg_type1 ){
                case GoodCRC:
                    DBGPRN1(PRN_USBCC, "Get GoodCRC \r\n");
                    break;
                case GotoMin:
                    break;
                case Accept:
                    DBGPRN1(PRN_USBCC, "1.Get Accept--> \r\n");
                    break;
                case Reject:
                    break;
                case Ping:
                    break;
                case PS_RDY:
                    DBGPRN1(PRN_USBCC, "2.Get PS_RDY --> \r\n");
                    break;
                case Get_Source_Cap:
                    break;
                case Get_Sink_Cap:
                    //CTS TD.PD.SNK.E9 GetSinkCap in Place of Accept
                    if (ucUSBCCPEState == PE_SNK_Select_Capability) {
                        USBCCSendSoftReset();
                        break;
                    }

                    //CTS TD.PD.SNK.E10 GetSinkCap in Place of PS_RDY
                    if (ucUSBCCPEState == PE_SNK_Transition_Sink) {
                        USBCCSendHardReset();
                        break;
                    }

                    DBGPRN1(PRN_USBCC, "3.Get SINK CAP--> \r\n");
                    //Sleep(5);
                    if (USBCCSendMessagewithRetryCnt(DataMsg, Sink_Capabilities) == 3) {
                        USBCCSendSoftReset();
                    }
                    DBGPRN1(PRN_USBCC, "3.Send SINK CAP <-- \r\n");
                    break;
                case DR_SWAP:
                    //CTS  TD.PD.VDMU.E18 Data Role Swap Hard Reset
                    if (ucVDMDiscoverState == VDM_Enter_Mode) {
                        USBCCSendHardReset();
                    }
                    else {
                        if (USBCCSendMessagewithRetryCnt(ControlMsg, Reject) == 3) {
                            USBCCSendSoftReset();
                        }
                    }
                    break;
                case PR_SWAP:
                    break;
                case VCONN_SWAP:
                    break;
                case Wait:
                    break;
                case Soft_Reset:
                    //CTS TD.PD.LL.E5 Soft Reset
                    ucUSBCCPEState = PE_SNK_Soft_Reset;
                    if (USBCCSendMessagewithRetryCnt(ControlMsg, Accept) == 3) {
                        USBCCSendSoftReset();
                    }
                    DBGPRN1(PRN_USBCC, "Get SOFT RESET \r\n");
                    USBCCSoftwareReset();
                    ucUSBCCPEState = PE_SNK_Wait_for_Capabilities;
                    DBGPRN1(PRN_PE_STATE, "===>PE_SNK_Wait_for_Capabilities\r\n");
                    break;
                default:
                    break;
            }
        }
        else if (ucUSBMessageType == CCMsgType_Data) {
            //for (i=0;i<(ucDataObjLen*4);i++) {
            //    CC_DATA_ARRAY[i]=SC_USBC_CC_RX_READ_DATA;
                //DBGPRN3(PRN_USBCC,"CC_DATA[%d] = 0x%bx\n", (USHRT)i,CC_DATA_ARRAY[i]);
            //}

            switch ( msg_type1 ) {
                case Source_Capabilities:
                    DBGPRN1(PRN_USBCC, "0.Get Souce Cap--> \r\n");
                    if (ucUSBCCPEState == PE_SNK_Evaluate_Capability) {
                        ucUSBCCPEState = PE_SNK_Select_Capability;
                    }
                    DBGPRN1(PRN_USBCC, "0.Send Request <-- \r\n");
                    if (USBCCSendMessagewithRetryCnt(DataMsg, Request) == 3) {
                        USBCCSendSoftReset();
                    }
                    //USBCCClearCRCFlag();
                    //USBCCSendDataMessage(CC_Link0, 1, 0, Request);
#if 0
                    //CTS TD.PD.SNK.E3 CRC timeout re-send request again.
                    retry = 0;
                    do {
                        if (USBCCIsCRCTimeout() == TRUE) {
                            DBGPRN1(/*PRN_USBCC*/1, "0.Send Request.. <-- \r\n");
                            USBCCClearCRCFlag();
                            USBCCSendDataMessage(CC_Link0,1,0,Request);
                            retry++;
                        }
                        else {
                            break;
                        }
                    } while(retry < 3);

                    //CTS TD.PD.LL.E3 Soft Reset Usage
                    if (retry == 3) {
                        USBCCSendSoftReset();
                    }
#endif
                    else 
                    {
                        USBCCClearIntTimeoutFlag(SenderResponseTimer_Flag);
                    }
                    break;
                case Request:
                    break;
                case BIST:
                    BIST_command= ucUSBCCBuffer[3] & 0xF0;// BIST Mode, BIST_Mode[31:28] at Data Obj0
                    switch ( BIST_command ) {
                        case BISTReceiverMode : // UUT Get the BIST Receiver mode need to reset BIST error counter
                            // UFP initial BIST counter
                            SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
                            SC_USBC_CC_COUNTER_SEL_CLEAR=0x8F;  // counter clear
                            SC_USBC_CC_COUNTER_SEL_CLEAR=0x80;  // counter sel BIST counter
                            //SC_USBC_CC_BIST_CTRL=0x80;  // Shift PRBS8 1T
                            
                            // DFP enter manual BIS TX mode
                            //SC_DVI_CTRL_32F|=BIT4; // bit4=1 index of CCRTX1 
                            //SC_USBC_CC_BIST_CTRL=0x04;  // manual TX enable
                            //SC_USBC_CC_TX_CTRL|=0x01;   // send PRBS-8 out

                            SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
                            DBGPRN2(PRN_USBCC,"UFP BIST Counter is 0x%bx\n", SC_USBC_CC_COUNTER_READH);
                            DBGPRN2(PRN_USBCC,"UFP BIST Counter is 0x%bx\n", SC_USBC_CC_COUNTER_READL);
                            DBGPRN2(PRN_USBCC,"UFP BIST Status is Receiver mode?[4] 0x%bx\n", SC_USBC_CC_BIST_CTRL);
                            break;
                         case BISTTransmitMode :
                            DBGPRN2(PRN_USBCC,"UFP BIST Status is Transmit mode?[5] 0x%bx\n", SC_USBC_CC_BIST_CTRL);
                            break;
                         case ReturnedBISTCounters :
                            DBGPRN2(PRN_USBCC,"UFP return BIST Counter H is 0x%bx\n", SC_USBC_CC_COUNTER_READH);
                            DBGPRN2(PRN_USBCC,"UFP return BIST Counter L is 0x%bx\n", SC_USBC_CC_COUNTER_READL);
                            break;
                        case BISTCarrierMode2 :
                            SC_USBC_CC_BIST_CTRL = 0x08;
                            DBGPRN2(PRN_USBCC,"UFP BIST Status is C2 mode?[6] 0x%bx\n", SC_USBC_CC_BIST_CTRL);
                            break;
                        case BISTTestData :
                            break;
                                       
                        default :
                            break;
                    }
                    break;
                case Sink_Capabilities:
                    break;
                case Vendor_Defined:
                    VDM_command = ucUSBCCBuffer[0] & 0x1F;// Command, VDM_command[4:0] at Data Obj0
                    //printf("%x %x %x %x\r\n",(USHRT)ucUSBCCBuffer[0],(USHRT)ucUSBCCBuffer[1],(USHRT)ucUSBCCBuffer[2],(USHRT)ucUSBCCBuffer[3]);
                    switch ( VDM_command ) {
                        case Discover_Identity:
                            DBGPRN1(PRN_USBCC, "A.Get VDM_Identity -->\r\n");
                            //Sleep(8);
                            if (IsUSBCCSVIDCorrect()) {
                                USBCCSendVDOMessage(UFP,4,0,Discover_Identity_Ack);
                                DBGPRN1(PRN_USBCC, "A1.Send VDM_Ack<--\r\n");
                                ucVDMDiscoverState = VDM_Discover_Identity;
                            }
                            else {
                                USBCCSendVDOMessage(UFP,1,0,Discover_Identity_Nack);
                            }
                            break;
                        case Discover_SVIDS:
                            DBGPRN1(PRN_USBCC, "B.Get VDM_Disc_SVID -->\r\n");
                            //Sleep(8);
                            if (IsUSBCCSVIDCorrect()) {
                                USBCCSendVDOMessage(UFP,2,0,Discover_SVID_Ack);
                                DBGPRN1(PRN_USBCC, "B1.Send VDM_Disc_SVID<-- \r\n");
                                ucVDMDiscoverState = VDM_Discover_SVIDS;
                            }
                            else {
                                USBCCSendVDOMessage(UFP,1,0,Discover_SVID_Nack);
                            }
                            break;
                        case Discover_Modes:
                            DBGPRN1(PRN_USBCC, "C.Get VDM_Disc_Mode -->\r\n");
                            //Sleep(8);
                            if (IsUSBCCSVIDCorrect()) {
                                USBCCSendVDOMessage(UFP,2,0,DP_Discover_Mode_Ack);
                                DBGPRN1(PRN_USBCC, "C1.Get VDM_Disc_Mode<--\r\n");
                                ucVDMDiscoverState = VDM_Discover_Modes;
                            }
                            else {
                                USBCCSendVDOMessage(UFP,1,0,DP_Discover_Mode_Nack);
                            }
                            break;
                        case Enter_Mode:
                            DBGPRN1(PRN_USBCC, "D.Get VDM_Enter_Mode -->\r\n");
                            //Sleep(8);
                            if (IsUSBCCSVIDCorrect()) {
                                if ((USBCCGetObjectPosition() != 1) || (ucVDMDiscoverState != VDM_Discover_Modes)) { //Object Position must be 1 && need to send discover mode first.
                                    USBCCSendVDOMessage(UFP,1,0,DP_Enter_Mode_Nack_OP);
                                }
                                else {
                                    USBCCSendVDOMessage(UFP,1,0,DP_Enter_Mode_Ack);
                                    ucVDMDiscoverState = VDM_Enter_Mode;
                                }
                            }
                            else {
                                USBCCSendVDOMessage(UFP,1,0,DP_Enter_Mode_Nack_SVID);
                                DBGPRN1(PRN_USBCC, "D1.Get VDM_Enter_Mode<-- \r\n");
                            }
                            break;
                        case Exit_Mode:
                            DBGPRN1(PRN_USBCC, "X.Get VDM_Exit_Mode -->\r\n");
                            //Sleep(8);
                            if (IsUSBCCSVIDCorrect()) {
                                if ((USBCCGetObjectPosition() != 1) || (ucVDMDiscoverState != VDM_Discover_Modes)) { //Object Position must be 1 && need to send discover mode first.
                                    USBCCSendVDOMessage(UFP,1,0,DP_Exit_Mode_Nack_OP);
                                }
                                else {
                                    USBCCSendVDOMessage(UFP,1,0,DP_Exit_Mode_Ack);
                                    DBGPRN1(PRN_USBCC, "X1.Get VDM_Exit_Mode<-- \r\n");
                                }
                            }
                            else {
                                USBCCSendVDOMessage(UFP,1,0,DP_Exit_Mode_Nack_SVID);
                            }
                            break;
                        case Attention:
                            break;
                        case DP_Status_Update:
                            DBGPRN1(PRN_USBCC, "E.Get DP_Status_Update -->\r\n");
                            //Sleep(8);
                            if (IsUSBCCSVIDCorrect()) {
                                USBCCSendVDOMessage(UFP,2,0,DP_Status_Update_Ack);
                                DBGPRN1(PRN_USBCC, "E1.Get DP_Status_Update<-- \r\n");
                                ucVDMDiscoverState = VDM_DP_Status_Update;
                            }
                            else {
                                USBCCSendVDOMessage(UFP,1,0,DP_Status_Update_Nack);
                            }
                            break;
                        case DP_Configure:
                            DBGPRN1(PRN_USBCC, "F.Get DP_Config -->\r\n");
                            //Sleep(8);
                            if (IsUSBCCSVIDCorrect()) {
                                USBCCSendVDOMessage(UFP,1,0,DP_Configure_Ack);
                                ucVDMDiscoverState = VDM_DP_Configure;
                            }
                            else {
                                USBCCSendVDOMessage(UFP,1,0,DP_Configure_Nack);
                            }
                            if (GetCurrInputInterface() == USB_TYPE_C_INTERFACE) {                                
                                ucVDMDiscoverState = VDM_Attention;
                                Sleep(8);
                                USBCCSendVDOMessage(UFP,2,0,Attention);
                                //DBGPRN1(1, "1.-->UFP send Attention<--\r\n");
                                bWaitSendAttention = FALSE;
                                SystemData.bPDdone = TRUE;
                                usTypeCTimer = GetTimerTick();
                            }
                            else {
                                bWaitSendAttention = TRUE;
                            }
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }
        if (ucUSBCCState == CC_UNACTIVE) {
            ucUSBMessageType = CCMsgType_UNKNOWN;
        }
    }
}

/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:
 *
 *----------------------------------------------------------------------------*/
void USBCCRXStateHandler()
{
    switch (ucUSBCPRLRxState) {
        case PRL_Rx_Wait_for_PHY_Message:
            break;
        case PRL_Rx_Layer_Reset_for_Receive:
            break;
        case PRL_Rx_Send_GoodCRC:
            // if HW aoto reply GoodCRC enable
            ucUSBCPRLRxState=PRL_Rx_Check_MessageID;
            break;
        case PRL_Rx_Check_MessageID:
            break;
        case PRL_Rx_Store_MessageID:
            break;
        default:
            break;
    }
}

/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:
 *
 *----------------------------------------------------------------------------*/
void USBCCTXStateHandler()
{
    switch ( ucUSBCPRLTxState ){
        case PRL_Tx_PHY_Layer_Reset:
            break;
        case PRL_Tx_Wait_for_Message_Request:
            break;
        case PRL_Tx_Layer_Reset_for_Transmit:
            break;
        case PRL_Tx_Construct_Message:
            break;
        case PRL_Tx_Wait_for_PHY_Response:
            break;
        case PRL_Tx_Match_MessageID:
            break;
        case PRL_Tx_Message_Sent:
            break;
        case PRL_Tx_Check_RetryCounter:
            break;
        case PRL_Tx_Transmission_Error:
            break;
        case PRL_Tx_Discard_Message:
            break;

        default:
            break;
    }
}

/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:
 *
 *----------------------------------------------------------------------------*/
void USBCCCheckRXMessageID()
{
#if 0
    // Check RX Message ID
    if(ucRXStoreMessageID==ucRXMessageID)
    {
        ucUSBCPRLRxState = PRL_Rx_Wait_for_PHY_Message;
        
        if(ucRXStoreMessageID==7)
        {
            ucRXStoreMessageID=0;
        }
        else
        {
            ucRXStoreMessageID=ucRXStoreMessageID+1;
        }
    }
    else
    {
        /* drop this message */
        ucUSBCPRLRxState = PRL_Rx_Store_MessageID;
        
    }
#endif
}

/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:
 *
 *----------------------------------------------------------------------------*/
void USBCCLink0Receiver(void)
{
    //UCHAR CC_DATA_ARRAY[6];
    UCHAR temp,cmd_type;
    
    DBGPRN1(PRN_USBCC, "USB CC RX0 UFP Receive Message \r\n");
    // Switch to RTX0
    SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0

    /* to add Receiver handle */
    /* step1: Get cmd only handle */

    USBCCIntFlagRead();
    USBCCIntFlagClear();

    temp=SC_USBC_CC_RX_CTRL;
    DBGPRN2(PRN_USBCC,"0xD84 is 0x%bx\n", temp);

    // This place Hardware design issue,the cmd only flag is fail to rising
    if (temp & 0x80) {// command only
        cmd_type=SC_USBC_CC_RX_CTRL&CC_RX_RD_CMD_MASK;
        DBGPRN2(PRN_USBCC,"cmd only valid is 0x%bx\n", cmd_type);
    }
    else {// 
        cmd_type=SC_USBC_CC_RX_CTRL&CC_RX_RD_CMD_MASK;
        DBGPRN2(PRN_USBCC,"cmd only not valid is 0x%bx\n", cmd_type);
    }

    /* step2: Get Header handle */

    /* step3: Get Dtat Obj handle */
}
/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:
 *
 *----------------------------------------------------------------------------*/
void USBCCLink0Transiver(void)
{
    // Switch to RTX0
    SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  

    SC_USBC_CC_TX_CTRL=0x04; // 0xD80 CC TX port manual addr reset
    SC_USBC_CC_TX_CTRL=0x08; // 0xD80 CC TX port manual addr enable

    // send BIST Message 
    // 16 bit Header 
    // 32 bit Data Object- 0x  

/*
    // send Sink_Capability Message 
    // 16 bit Header 
    SC_USBC_CC_TX_MANUAL_ADDR=0x00; // 0xD81
    SC_USBC_CC_TX_WRITE_DATA=0x44;  // Header[7:0] Sink_Capability
    SC_USBC_CC_TX_MANUAL_ADDR=0x01; // 0xD81
    SC_USBC_CC_TX_WRITE_DATA=0x16;  // Header[15:8] bit14:12-No of Data Obj bit11:9-MessageID bit8-Power Role=1 is source   
    // 32 bit Data Object[0~7]- 0x04-01-90-C8  
    // Fixed Supply PDO (5V 2A), USB communication Capable : Yes, other all No
    SC_USBC_CC_TX_MANUAL_ADDR=0x02; // 0xD81
    SC_USBC_CC_TX_WRITE_DATA=0xC8;  // Data [7:0]   2A
    
    SC_USBC_CC_TX_MANUAL_ADDR=0x03; // 0xD81
    SC_USBC_CC_TX_WRITE_DATA=0x90;  // Data[15:8]    5V
    
    SC_USBC_CC_TX_MANUAL_ADDR=0x04; // 0xD81
    SC_USBC_CC_TX_WRITE_DATA=0x01;  // Data[23:16]  
    
    SC_USBC_CC_TX_MANUAL_ADDR=0x05; // 0xD81
    SC_USBC_CC_TX_WRITE_DATA=0x04;  // Data[31:24]  


    // send Request Message 
    // 16 bit Header 
    SC_USBC_CC_TX_MANUAL_ADDR=0x00; // 0xD81
    SC_USBC_CC_TX_WRITE_DATA=0x42;  // Header[7:0] Request
    SC_USBC_CC_TX_MANUAL_ADDR=0x01; // 0xD81
    SC_USBC_CC_TX_WRITE_DATA=0x10;  // Header[15:8] bit14:12-No of Data Obj bit11:9-MessageID bit8-Power Role=1 is source   
    // 32 bit Data Object[0~7]- 0x04-01-90-C8  
    // Fixed Supply PDO (5V 2A), USB communication Capable : Yes, other all No
    SC_USBC_CC_TX_MANUAL_ADDR=0x02; // 0xD81
    SC_USBC_CC_TX_WRITE_DATA=0xC8;  // Data [7:0]  Maxmun Current=2A 
    
    SC_USBC_CC_TX_MANUAL_ADDR=0x03; // 0xD81
    SC_USBC_CC_TX_WRITE_DATA=0x58;  // Data[15:8]    
    
    SC_USBC_CC_TX_MANUAL_ADDR=0x04; // 0xD81
    SC_USBC_CC_TX_WRITE_DATA=0x02;  // Data[23:16]  Operating Current=1.5A
    
    SC_USBC_CC_TX_MANUAL_ADDR=0x05; // 0xD81
    SC_USBC_CC_TX_WRITE_DATA=0x17;  // Data[31:24]  Obj_Pos=1 

    // send Vendor_Defined Message 
    // 16 bit Header 
    // 32 bit VDM Header
    // 32 bit Data Object[0~6] - 0x  

*/
    // send UFP GoodCRC Control Message 
    // 16 bit Header 
    SC_USBC_CC_TX_MANUAL_ADDR=0x00; // 0xD81
    SC_USBC_CC_TX_WRITE_DATA=0x41;  // Header[7:0] GoodCRC
    SC_USBC_CC_TX_MANUAL_ADDR=0x01; // 0xD81
    SC_USBC_CC_TX_WRITE_DATA=0x00;  // Header[15:8] bit14:12-No of Data Obj bit11:9-MessageID bit8-Power Role=1 is source  
    
    SC_USBC_CC_TX_CTRL=0x01; // Send Message    
    
    DBGPRN1(PRN_USBCC, "USB CC TX0 UFP Send GoodCRC \r\n");
}

/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:
 *
 *----------------------------------------------------------------------------*/
void USBCCLink1Receiver(void)
{
    //UCHAR CC_DATA_ARRAY[6];
    //UCHAR i;
    
    DBGPRN1(PRN_USBCC, "USB CC RX1 DFP Receive Message \r\n");
    // Switch to RTX1
    SC_DVI_CTRL_32F|=BIT4; // bit4=1 index of CCRTX1    
}

/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description: FPGA code CC1 RX and TX is at PB2
 *
 *----------------------------------------------------------------------------*/
void USBCCLink1Transiver(void)
{
    DBGPRN1(PRN_USBCC, "USB CC TX1 DFP Send Message \r\n");
    
    // Switch to RTX0
    SC_DVI_CTRL_32F|=BIT4; // bit4=1 index of CCRTX1 
    
    SC_USBC_CC_TX_CTRL=0x04; // 0xD80 CC TX port manual addr reset
    SC_USBC_CC_TX_CTRL=0x08; // 0xD80 CC TX port manual addr enable

    // send Data Message
    // 16 bit Header 
    SC_USBC_CC_TX_MANUAL_ADDR=0x00; // 0xD81
    SC_USBC_CC_TX_WRITE_DATA=0x61;  // Header[7:0]
    SC_USBC_CC_TX_MANUAL_ADDR=0x01; // 0xD81
    SC_USBC_CC_TX_WRITE_DATA=0x11;  // Header[15:8] bit14:12-No of Data Obj bit11:9-MessageID bit8-Power Role=1 is source   
    // 32 bit Data Object- 0x36019096
    SC_USBC_CC_TX_MANUAL_ADDR=0x02; // 0xD81
    SC_USBC_CC_TX_WRITE_DATA=0x96;  // Header[15:8] bit14:12-No of Data Obj bit11:9-MessageID bit8-Power Role=1 is source  
    
    SC_USBC_CC_TX_MANUAL_ADDR=0x03; // 0xD81
    SC_USBC_CC_TX_WRITE_DATA=0x90;  // Header[15:8] bit14:12-No of Data Obj bit11:9-MessageID bit8-Power Role=1 is source   
    
    SC_USBC_CC_TX_MANUAL_ADDR=0x04; // 0xD81
    SC_USBC_CC_TX_WRITE_DATA=0x01;  // Header[15:8] bit14:12-No of Data Obj bit11:9-MessageID bit8-Power Role=1 is source  
    
    SC_USBC_CC_TX_MANUAL_ADDR=0x05; // 0xD81
    SC_USBC_CC_TX_WRITE_DATA=0x36;  // Header[15:8] bit14:12-No of Data Obj bit11:9-MessageID bit8-Power Role=1 is source 
    
    //SC_USBC_CC_TX_WRITE_DATA=0x36;  // Header[15:8] bit14:12-No of Data Obj bit11:9-MessageID bit8-Power Role=1 is source 

    SC_USBC_CC_TX_CTRL=0x01; // Send Message    
    
    DBGPRN1(PRN_USBCC, "USB CC TX1 DFP Send Source_Capability \r\n");
}
/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:
 *
 *----------------------------------------------------------------------------*/
void USBCCSendCommand(UCHAR layer,UCHAR cmd_type)
{
    if (layer==CC_Link0) {
        SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
    }
    else {//(layer==CC_Link1)
        SC_DVI_CTRL_32F|=BIT4; // bit4=1 index of CCRTX1    
    }
    
    switch (cmd_type)
    {
        case SOP : // for test only
            SC_USBC_CC_TX_CTRL=(SOP<<4);    // SOP need send with Data obj
            SC_USBC_CC_TX_WRITE_DATA=0x61;  // write Header low byte
            SC_USBC_CC_TX_WRITE_DATA=0x01;  // write Header high byte
            break;
        case SOPP :
            SC_USBC_CC_TX_CTRL=(SOPP<<4);
            SC_USBC_CC_TX_WRITE_DATA=0x61;   // write Header low byte
            SC_USBC_CC_TX_WRITE_DATA=0x01;  // write Header high byte
            break;
        case SOPPP :
            SC_USBC_CC_TX_CTRL=(SOPPP<<4);
            SC_USBC_CC_TX_WRITE_DATA=0x61;   // write Header low byte
            SC_USBC_CC_TX_WRITE_DATA=0x01;  // write Header high byte
            break;
        case Hard_Reset :
            SC_USBC_CC_TX_CTRL=(Hard_Reset<<4);
            SC_USBC_CC_TX_CTRL|=0x80;
            break;
        case Cable_Reset :
            SC_USBC_CC_TX_CTRL=(Cable_Reset<<4);
            SC_USBC_CC_TX_CTRL|=0x80;
            break;
        case SOPP_Debug :
            SC_USBC_CC_TX_CTRL=(SOPP_Debug<<4);
            SC_USBC_CC_TX_WRITE_DATA=0x61;   // write Header low byte
            SC_USBC_CC_TX_WRITE_DATA=0x01;  // write Header high byte
            break;
        case SOPPP_Debug :
            SC_USBC_CC_TX_CTRL=(SOPPP_Debug<<4);
            SC_USBC_CC_TX_WRITE_DATA=0x61;   // write Header low byte
            SC_USBC_CC_TX_WRITE_DATA=0x01;  // write Header high byte
            break;
        default:
            break;
    }

    //SC_USBC_CC_TX_CTRL|=0x80;
    DBGPRN2(PRN_USBCC,"Send cmd only 0xD80 is 0x%bx\n", SC_USBC_CC_TX_CTRL);

    SC_USBC_CC_TX_CTRL|=0x01;   // send cmd out
}
/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:
 *
 *----------------------------------------------------------------------------*/
void USBCCSendControlMessage(UCHAR layer,UCHAR Message_type)
{
    UCHAR Header_H,Header_L;
    
    if (layer==CC_Link0) {
        SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
        //Header_H=0x00;  // as Sink
        Header_H=0x00|(ucRXMessageID<<1);  // as Sink
        Header_L=0x40;  // as UFP
    }
    else {//(layer==CC_Link1)
        SC_DVI_CTRL_32F|=BIT4; // bit4=1 index of CCRTX1 
        Header_H=0x01;  // as source
        Header_L=0x60;  // as DFP
    }
    
    SC_USBC_CC_TX_CTRL=BIT2;    // TX addres reset
    SC_USBC_CC_TX_CTRL=0x00;    // TX addres reset

    SC_USBC_CC_TX_WRITE_DATA=( Header_L | Message_type);   // write Header low byte
    //SC_USBC_CC_TX_WRITE_DATA=(Message_type);   
    SC_USBC_CC_TX_WRITE_DATA=Header_H;  // write Header low byte
    SC_USBC_CC_TX_CTRL|=0x01;   // send control message out
}

/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:
 *
 *----------------------------------------------------------------------------*/
void USBCCSendDataMessage(UCHAR layer,UCHAR num_DataObj,UCHAR msg_ID,UCHAR Message_type)
{
    UCHAR Header_H,Header_L,i;
    code UCHAR Source_Cap_ARRAY1[4]={0x96,0x90,0x01,0x36}; // LSB to MSB
    //code UCHAR Source_Cap_ARRAY2[4]={0x96,0x90,0x01,0x26};
   
    //UCHAR Sink_Request[4]={0xC8,0x58,0x02,0x17};// max 2A and operating 1.5A
    //UCHAR Sink_Request[4]={0x88,0x58,0x01,0x17};
    //UCHAR Sink_Request[4]={0x96,0x90,0x01,0x15};// max 1.5A and operating 1A, Capability mismatch
    //UCHAR Sink_Request[4]={0x2C,0x91,0x01,0x11};// max 3A and operating 1A
    //UCHAR Sink_Request[4]={0x64,0xC8,0x00,0x11};// max 1A and operating 0.5A
    //UCHAR Sink_Request[4]={0x5A,0xC8,0x00,0x11};// max 0.9A and operating 0.5A
    UCHAR Sink_Request[4]={0x5A,0x68,0x01,0x11};// chroma to ASUS max=0x5A=0.9A and operating=0x5A
    //UCHAR Sink_Request_Mismatch[4]={0x2C,0x29,0x00,0x15};//CTS max 3A and operarting 0.1A
    //UCHAR Sink_Request[4]={0x0A,0x28,0x00,0x11};// CTS test max=0x0A=0.1A and operating=0.1A
    //UCHAR Sink_Request[4]={0x2C,0xB1,0x04,0x11};//Dell DC at 1750mV, 3A
    //code UCHAR Sink_Capability[4]={0xC8,0x90,0x01,0x26};
    //UCHAR Sink_Capability[4]={0x96,0x90,0x01,0x26};// macBook
    UCHAR Sink_Capability[4]={0x5A,0x90,0x01,0x00};// Chroma

    
    code UCHAR BIST_BDO[]={0x00,0x00,0x00,0x00};    // Request receiver enter BIST Receiver Mode
    code UCHAR VDM_Header[4]={0x01,0x80,0x00,0xFF};
    //code UCHAR VDM_Header[4]={0x02,0x80,0x00,0xFF};

    if (ucTXMessageID==0x08) {
        ucTXMessageID=0;
    }
    
    if (layer==CC_Link0) {
        SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
        //SC_DVI_CTRL_32F=0x02; // bit4=0 index of CCRTX0 
        Header_H=0x00|(num_DataObj<<4)|(msg_ID<<1);  // as Sink
        //Header_H=0x00|(num_DataObj<<4)|(ucTXMessageID<<1);  // as Sink
        Header_L=0x40;  // as UFP
        //ucTXMessageID++;
    }
    else {//(layer==CC_Link1) // act as DFP
        //SC_DVI_CTRL_32F=0x12; // bit4=0 index of CCRTX0  
        SC_DVI_CTRL_32F|=BIT4; // bit4=1 index of CCRTX1 
        Header_H=0x01|(num_DataObj<<4)|(msg_ID<<1);  // as source
        Header_L=0x60;  // as DFP
    }
 
    SC_USBC_CC_TX_CTRL=BIT2;    // TX addres reset
    SC_USBC_CC_TX_CTRL=0x00;    // TX addres reset

    SC_USBC_CC_TX_WRITE_DATA=( Header_L | Message_type);   // write Header low byte
    //    SC_USBC_CC_TX_WRITE_DATA=(Message_type);   
    SC_USBC_CC_TX_WRITE_DATA=Header_H;  // write Header low byte
/*
    for(i=0;i<(num_DataObj*4);i++)
    {
    
        SC_USBC_CC_TX_WRITE_DATA = Source_Cap_ARRAY[i];
        //SC_USBC_CC_TX_WRITE_DATA = VDM_Header[i];
    }
*/

    switch(Message_type)
    {
        case Source_Capabilities :
            for (i=0;i<(num_DataObj*4);i++) {
                SC_USBC_CC_TX_WRITE_DATA = Source_Cap_ARRAY1[i];
            }
            break;
        case Request :
#if 1
            {
                //CTS TD.PD.SNK.E11 PDO Transition
                RequestMsg request;
                request = defaultRequestMsg;

                //printf("requset %x,%x\r\n",(USHRT)USBCCGetSourceMaxCurrent(),(USHRT)request.Opr_Cur);
                if (USBCCGetSourceMaxCurrent() < request.Opr_Cur) {
                    request.Opr_Cur = USBCCGetSourceMaxCurrent();
                    request.Cap_Mismatch = 1;
                }

                PDMsgTX_Packet.object[0] = (ULONG)request.Max_Opr_Cur | ((ULONG)request.Opr_Cur<<10) | ((ULONG)request.Rsvd1<<20) \
                | ((ULONG)request.No_USB_Suspend<<24) | ((ULONG)request.USB_Com_cap<<25) \
                | ((ULONG)request.Cap_Mismatch<<26) | ((ULONG)request.Give_Back<<27) \
                | ((ULONG)request.Obj_Pos<<28) | ((ULONG)request.Rsvd2<<31); 
            }

            for (i=0;i<(num_DataObj*4);i++) {
                SC_USBC_CC_TX_WRITE_DATA = (UCHAR)(PDMsgTX_Packet.object[i]);
                SC_USBC_CC_TX_WRITE_DATA = (UCHAR)(PDMsgTX_Packet.object[i] >>8);
                SC_USBC_CC_TX_WRITE_DATA = (UCHAR)(PDMsgTX_Packet.object[i] >>16);
                SC_USBC_CC_TX_WRITE_DATA = (UCHAR)(PDMsgTX_Packet.object[i] >>24);
            }
#else
            for (i=0;i<(num_DataObj*4);i++) {
                SC_USBC_CC_TX_WRITE_DATA = Sink_Request[i];
            }
#endif
            break;
        case BIST :
            for (i=0;i<(num_DataObj*4);i++) {
                SC_USBC_CC_TX_WRITE_DATA = BIST_BDO[i];
            }
            break;
            
        case Sink_Capabilities :
            for (i=0;i<(num_DataObj*4);i++) {
                SC_USBC_CC_TX_WRITE_DATA = Sink_Capability[i];
            }
            break;
        case Vendor_Defined :
            for (i=0;i<(num_DataObj*4);i++) {
                SC_USBC_CC_TX_WRITE_DATA = VDM_Header[i];
            }
            break;

        default :
            break;
    }

#if 0 // if need to test error CRC
    // For error CRC value test
    // Set manual CRC Value
    SC_USBC_CC_TX_CTRL|=BIT3;   // CC_TX write manu addr enable
    SC_USBC_CC_TX_MANUAL_ADDR=0x1E;
    SC_USBC_CC_TX_CTRL&= ~BIT3; // CC_TX write manu addr disable

    SC_USBC_CC_TX_WRITE_DATA = 0x01;
    SC_USBC_CC_TX_WRITE_DATA = 0x03;
    SC_USBC_CC_TX_WRITE_DATA = 0x55;
    SC_USBC_CC_TX_WRITE_DATA = 0xAA;
#endif
    
    SC_USBC_CC_TX_CTRL|=0x01;   // send control message out
    //USBCCIntFlagRead();
}
/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:
 *
 *----------------------------------------------------------------------------*/
void USBCCSendBISTMessage(UCHAR layer,UCHAR num_DataObj,UCHAR msg_ID,UCHAR BIST_Mode)
{
    UCHAR Header_H,Header_L,i;
    code UCHAR BIST_Receiver_Mode[]={0x00,0x00,0x00,0x00};    // Request receiver enter BIST Receiver Mode
    code UCHAR BIST_Transmit_Mode[]={0x00,0x00,0x00,0x10};    // Request receiver enter BIST Transmit Mode
    code UCHAR BIST_Carrier_Mode2[]={0x00,0x00,0x00,0x50};    // Request receiver enter BIST Carrier Mode2
    //code UCHAR BIST_Test_Data[]={0x00,0x00,0x00,0x80};        // Send a Test Data Frame
    code UCHAR BIST_Test_Data_6DataObj[]={
        0x00,0x00,0x00,0x80,
        0x00,0x01,0x02,0x03,
        0x04,0x05,0x06,0x07,
        0x08,0x09,0x0A,0x0B,
        0x0C,0x0D,0x0E,0x0F,
        0x10,0x11,0x12,0x13,
        0x14,0x15,0x16,0x17,
    };// Send a Test Data Frame
   
    if (layer==CC_Link0) {
        SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
        //SC_DVI_CTRL_32F=0x02; // bit4=0 index of CCRTX0 
        Header_H=0x00|(num_DataObj<<4)|(msg_ID<<1);  // as Sink
        //Header_H=0x00|(num_DataObj<<4)|(ucTXMessageID<<1);  // as Sink
        Header_L=0x40;  // as UFP
        //ucTXMessageID++;
    }
    else {//(layer==CC_Link1) // act as DFP
        //SC_DVI_CTRL_32F=0x12; // bit4=0 index of CCRTX0  
        SC_DVI_CTRL_32F|=BIT4; // bit4=1 index of CCRTX1 
        Header_H=0x01|(num_DataObj<<4)|(msg_ID<<1);  // as source
        Header_L=0x60;  // as DFP
    }
 
    SC_USBC_CC_TX_CTRL=BIT2;    // TX addres reset
    SC_USBC_CC_TX_CTRL=0x00;    // TX addres reset

    SC_USBC_CC_TX_WRITE_DATA=( Header_L | BIST);   // write Header low byte
    SC_USBC_CC_TX_WRITE_DATA=Header_H;  // write Header low byte

    switch(BIST_Mode)
    {
        case BISTReceiverMode :
            for (i=0;i<(num_DataObj*4);i++) {
                SC_USBC_CC_TX_WRITE_DATA = BIST_Receiver_Mode[i];
            }
            break;
         case BISTTransmitMode :
            for (i=0;i<(num_DataObj*4);i++) {
                SC_USBC_CC_TX_WRITE_DATA = BIST_Transmit_Mode[i];
            }
            break;
        case BISTCarrierMode2 :
            for (i=0;i<(num_DataObj*4);i++) {
                SC_USBC_CC_TX_WRITE_DATA = BIST_Carrier_Mode2[i];
            }
            break;
        case BISTTestData :
            //for(i=0;i<(num_DataObj*4);i++){
            //for(i=0;i<(1*4);i++){
            //SC_USBC_CC_TX_WRITE_DATA = BIST_Test_Data[i];
            //}
            for (i=0;i<(num_DataObj*4);i++) {
                SC_USBC_CC_TX_WRITE_DATA = BIST_Test_Data_6DataObj[i];
            }
            break;
                       
        default :
            break;
    }
   
    SC_USBC_CC_TX_CTRL|=0x01;   // send control message out
}

/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:
 *
 *----------------------------------------------------------------------------*/
void USBCCSendVDOMessage(UCHAR layer,UCHAR num_DataObj,UCHAR msg_ID,UCHAR VDO_Type)
{
    UCHAR Header_H,Header_L,i;

    code UCHAR VDM_Discover_Identity[4]={0x01,0x80,0x00,0xFF};
    code UCHAR VDM_Discover_SVID[4]={0x02,0x80,0x00,0xFF};
    code UCHAR VDM_DP_Discover_Mode[4]={0x03,0x80,0x01,0xFF};
    code UCHAR VDM_DP_Enter_Mode[4]={0x04,0x81,0x01,0xFF};
    code UCHAR VDM_DP_Exit_Mode[4]={0x05,0x81,0x01,0xFF};
    code UCHAR VDM_DP_Status_Update[8]={0x10,0x81,0x01,0xFF,0x01,0x00,0x00,0x00};
    code UCHAR VDM_DP_Configure[8]={0x11,0x81,0x01,0xFF,0x06,0x10,0x00,0x00};

#if 0 //MacBook
    code UCHAR VDM_Discover_Identity_Ack[16]={0x41,0x80,0x00,0xFF,0x51,0x04,0x00,0xC4,0x51,0x04,0x00,0x00,0x10,0x00,0x34,0x12};
    code UCHAR VDM_Discover_SVID_Ack[8]={0x42,0x80,0x00,0xFF,0x00,0x00,0x01,0xFF};
    code UCHAR VDM_DP_Discover_Mode_Ack[8]={0x43,0x80,0x01,0xFF,0x45,0x00,0x10,0x00};// Pin Assignment E
    //code UCHAR VDM_DP_Discover_Mode_Ack[8]={0x43,0x80,0x01,0xFF,0x45,0x00,0x04,0x00};// Pin Assignment C
    code UCHAR VDM_DP_Enter_Mode_Ack[4]={0x44,0x81,0x01,0xFF};
    code UCHAR VDM_DP_Status_Update_Ack[8]={0x50,0x81,0x01,0xFF,0x1A,0x00,0x00,0x00};
    code UCHAR VDM_DP_Configure_Ack[4]={0x51,0x81,0x01,0xFF};
    code UCHAR VDM_DP_Attention[8]={0x06,0x81,0x01,0xFF,0x9A,0x00,0x00,0x00};    // 4F 24
#endif
    code UCHAR VDM_Discover_Identity_Busy[4]={0xC1,0x80,0x00,0xFF};

#if 1
//  Chroma Book ==================================
    // Chroma
    //code UCHAR VDM_Discover_Identity_Ack[16]={0x41,0x80,0x00,0xFF,0x51,0x04,0x00,0xC4,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
    //code UCHAR VDM_Discover_Identity_Ack[16]={0x41,0x00,0x00,0xFF,0x00,0x00,0x00,0xC4,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00};
    code UCHAR VDM_Discover_Identity_Ack[16]={0x41,0x80,0x00,0xFF,0x03,0x06,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
    // VID modify to Novatek_0603, Data Capable as USB Host and Device all No
    code UCHAR VDM_Discover_SVID_Ack[8]={0x42,0x80,0x00,0xFF,0x00,0x00,0x01,0xFF};//same
    code UCHAR VDM_DP_Discover_Mode_Ack[8]={0x43,0x80,0x01,0xFF,0x45,0x00,0x04,0x00};// Pin Assignment 
    //code UCHAR VDM_DP_Discover_Mode_Ack[8]={0x43,0x80,0x01,0xFF,0x45,0x00,0x04,0x00};// Pin Assignment C
    code UCHAR VDM_DP_Enter_Mode_Ack[4]={0x44,0x81,0x01,0xFF};
    code UCHAR VDM_DP_Exit_Mode_Ack[4]={0x45,0x81,0x01,0xFF};
    code UCHAR VDM_DP_Status_Update_Ack[8]={0x50,0x81,0x01,0xFF,0x0A,0x00,0x00,0x00};// Chroma
    code UCHAR VDM_DP_Configure_Ack[4]={0x51,0x81,0x01,0xFF};
    code UCHAR VDM_DP_Attention[8]={0x06,0x81,0x01,0xFF,0x8A,0x00,0x00,0x00};    // 4F 24 chroma
    code UCHAR VDM_DP_Attention_HPD_Low[8]={0x06,0x81,0x01,0xFF,0x0A,0x00,0x00,0x00};    // 4F 24 chroma
//Nack command
    //wrong SVID
    code UCHAR VDM_Discover_Identity_Nack[16]={0x81,0x80,0xEE,0xEE};
    code UCHAR VDM_Discover_SVID_Nack[8]={0x82,0x80,0xEE,0xEE};
    code UCHAR VDM_DP_Discover_Mode_Nack[8]={0x83,0x80,0xEE,0xEE};
    code UCHAR VDM_DP_Enter_Mode_Nack_SVID[4]={0x84,0x81,0xEE,0xEE};
    code UCHAR VDM_DP_Exit_Mode_Nack_SVID[4]={0x85,0x81,0xEE,0xEE};
    code UCHAR VDM_DP_Status_Update_Nack[8]={0x90,0x81,0xEE,0xEE};
    code UCHAR VDM_DP_Configure_Nack[4]={0x91,0x81,0xEE,0xEE};
    //wrong Object Position
    code UCHAR VDM_DP_Enter_Mode_Nack_OP[4]={0x84,0x80,0x01,0xFF};
    code UCHAR VDM_DP_Exit_Mode_Nack_OP[4]={0x85,0x80,0x01,0xFF};
//================================================
#endif

    if (layer==CC_Link0) {
        SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
        //SC_DVI_CTRL_32F=0x02; // bit4=0 index of CCRTX0 
        Header_H=0x00|(num_DataObj<<4)|(msg_ID<<1);  // as Sink
        //Header_H=0x00|(num_DataObj<<4)|(ucTXMessageID<<1);  // as Sink
        Header_L=0x40;  // as UFP
        //ucTXMessageID++;
    }
    else {//(layer==CC_Link1) // act as DFP
        //SC_DVI_CTRL_32F=0x12; // bit4=0 index of CCRTX0  
        SC_DVI_CTRL_32F|=BIT4; // bit4=1 index of CCRTX1 
        Header_H=0x01|(num_DataObj<<4)|(msg_ID<<1);  // as source
        Header_L=0x60;  // as DFP
    }
 
    SC_USBC_CC_TX_CTRL=BIT2;    // TX addres reset
    SC_USBC_CC_TX_CTRL=0x00;    // TX addres reset

    SC_USBC_CC_TX_WRITE_DATA=( Header_L | Vendor_Defined);   // write Header low byte
    SC_USBC_CC_TX_WRITE_DATA=Header_H;  // write Header low byte


    switch(VDO_Type)    // basic 8 type
    {
        case Discover_Identity :
            for (i=0;i<(num_DataObj*4);i++) {
                SC_USBC_CC_TX_WRITE_DATA = VDM_Discover_Identity[i];
            }
            break;
         case Discover_SVIDS :
            for (i=0;i<(num_DataObj*4);i++) {
                SC_USBC_CC_TX_WRITE_DATA = VDM_Discover_SVID[i];
            }
            break;
        case Discover_Modes :
            for (i=0;i<(num_DataObj*4);i++) {
                SC_USBC_CC_TX_WRITE_DATA = VDM_DP_Discover_Mode[i];
            }
            break;
        case Enter_Mode :
            for (i=0;i<(num_DataObj*4);i++) {
                SC_USBC_CC_TX_WRITE_DATA = VDM_DP_Enter_Mode[i];
            }
            break;
        case Exit_Mode :
            for (i=0;i<(num_DataObj*4);i++) {
                SC_USBC_CC_TX_WRITE_DATA = VDM_DP_Exit_Mode[i];
            }
            break;
        case Attention :
            for (i=0;i<(num_DataObj*4);i++) {
                SC_USBC_CC_TX_WRITE_DATA = VDM_DP_Attention[i];
            }
            break;
           
        case DP_Status_Update :
            for (i=0;i<(num_DataObj*4);i++) {
                SC_USBC_CC_TX_WRITE_DATA = VDM_DP_Status_Update[i];
            }
            break;
        case DP_Configure :
            for (i=0;i<(num_DataObj*4);i++) {
                SC_USBC_CC_TX_WRITE_DATA = VDM_DP_Configure[i];
            }
            break;

//===================================================================//
            
        case Discover_Identity_Busy :
            for (i=0;i<(num_DataObj*4);i++) {
                SC_USBC_CC_TX_WRITE_DATA = VDM_Discover_Identity_Busy[i];
            }
            break;

//==============================ACK==================================//
        case Discover_Identity_Ack :
            for (i=0;i<(num_DataObj*4);i++) {
                SC_USBC_CC_TX_WRITE_DATA = VDM_Discover_Identity_Ack[i];
            }
            break;
         case Discover_SVID_Ack :
            for (i=0;i<(num_DataObj*4);i++) {
                SC_USBC_CC_TX_WRITE_DATA = VDM_Discover_SVID_Ack[i];
            }
            break;
        case DP_Discover_Mode_Ack :
            for (i=0;i<(num_DataObj*4);i++) {
                SC_USBC_CC_TX_WRITE_DATA = VDM_DP_Discover_Mode_Ack[i];
            }
            break;
        case DP_Enter_Mode_Ack :
            for (i=0;i<(num_DataObj*4);i++) {
                SC_USBC_CC_TX_WRITE_DATA = VDM_DP_Enter_Mode_Ack[i];
            }
            break;
        case DP_Exit_Mode_Ack :
            for (i=0;i<(num_DataObj*4);i++) {
                SC_USBC_CC_TX_WRITE_DATA = VDM_DP_Exit_Mode_Ack[i];
            }
            break;
        case DP_Status_Update_Ack :
            for (i=0;i<(num_DataObj*4);i++) {
                SC_USBC_CC_TX_WRITE_DATA = VDM_DP_Status_Update_Ack[i];
            }
            break;
        case DP_Configure_Ack :
            for (i=0;i<(num_DataObj*4);i++) {
                SC_USBC_CC_TX_WRITE_DATA = VDM_DP_Configure_Ack[i];
            }
            break;

//=============================HPD LOW==================================//
        case Attention_HPD_Low :
            for (i=0;i<(num_DataObj*4);i++) {
                SC_USBC_CC_TX_WRITE_DATA = VDM_DP_Attention_HPD_Low[i];
            }
            break;

//===============================NACK===================================//
        case Discover_Identity_Nack :
            for (i=0;i<(num_DataObj*4);i++) {
                SC_USBC_CC_TX_WRITE_DATA = VDM_Discover_Identity_Nack[i];
            }
            break;
         case Discover_SVID_Nack :
            for (i=0;i<(num_DataObj*4);i++) {
                SC_USBC_CC_TX_WRITE_DATA = VDM_Discover_SVID_Nack[i];
            }
            break;
        case DP_Discover_Mode_Nack :
            for (i=0;i<(num_DataObj*4);i++) {
                SC_USBC_CC_TX_WRITE_DATA = VDM_DP_Discover_Mode_Nack[i];
            }
            break;
        case DP_Enter_Mode_Nack_SVID :
            for (i=0;i<(num_DataObj*4);i++) {
                SC_USBC_CC_TX_WRITE_DATA = VDM_DP_Enter_Mode_Nack_SVID[i];
            }
            break;
        case DP_Exit_Mode_Nack_SVID :
            for (i=0;i<(num_DataObj*4);i++) {
                SC_USBC_CC_TX_WRITE_DATA = VDM_DP_Exit_Mode_Nack_SVID[i];
            }
            break;
        case DP_Enter_Mode_Nack_OP :
            for (i=0;i<(num_DataObj*4);i++) {
                if (i==1) {//return object position
                    SC_USBC_CC_TX_WRITE_DATA = (VDM_DP_Enter_Mode_Nack_OP[i]|USBCCGetObjectPosition());
                }
                else {
                    SC_USBC_CC_TX_WRITE_DATA = VDM_DP_Enter_Mode_Nack_OP[i];
                }
            }
            break;
        case DP_Exit_Mode_Nack_OP :
            for (i=0;i<(num_DataObj*4);i++) {
                if (i==1) {//return object position
                    SC_USBC_CC_TX_WRITE_DATA = (VDM_DP_Exit_Mode_Nack_OP[i]|USBCCGetObjectPosition());
                }
                else {
                    SC_USBC_CC_TX_WRITE_DATA = VDM_DP_Exit_Mode_Nack_OP[i];
                }
            }
            break;
        case DP_Status_Update_Nack :
            for (i=0;i<(num_DataObj*4);i++) {
                SC_USBC_CC_TX_WRITE_DATA = VDM_DP_Status_Update_Nack[i];
            }
            break;
        case DP_Configure_Nack :
            for (i=0;i<(num_DataObj*4);i++) {
                SC_USBC_CC_TX_WRITE_DATA = VDM_DP_Configure_Nack[i];
            }
            break;

        default :
            break;
    }

    SC_USBC_CC_TX_CTRL|=0x01;   // send control message out
}

/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:
 *
 *----------------------------------------------------------------------------*/
//void USBCCGetCommand(UCHAR layer,UCHAR cmd_type)
//{
//}

/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:
 *
 *----------------------------------------------------------------------------*/
void USBCCGetControlMessage(void)
{
    UCHAR CC_Header[2];
    UCHAR i,temp,cmd_type;
    
    DBGPRN1(PRN_USBCC, "USB CC RX0 UFP Get Control Message \r\n");
    // Switch to RTX0
    //SC_DVI_CTRL_32F=0x02; // bit4=0 index of CCRTX0
    SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
    
    USBCCIntFlagRead();
    USBCCIntFlagClear();

    temp=SC_USBC_CC_RX_CTRL;
    if (temp & 0x80) {// command only
        cmd_type=SC_USBC_CC_RX_CTRL&CC_RX_RD_CMD_MASK;
        DBGPRN2(PRN_USBCC,"command is 0x%bx\n", cmd_type);
    }
    else {// Control message or data message
        // Gate CC 測起來沒實際作用,so close it
        //SC_USBC_CC_RX_CTRL|=BIT1;   // CC_RX read gate set 1, Gate CC if previous message not read out
        if (USBCC_GetData()) {// 這裡判斷 0xD84[0] read data is valid or not?
            //DBGPRN1(PRN_USBCC, "USB CC RX0 UFP GetHeader valid\r\n");
            SC_USBC_CC_RX_CTRL|=BIT2;   // CC_RX manual address reset
            SC_USBC_CC_RX_CTRL&= ~BIT2; 
            for (i=0;i<2;i++) {
                CC_Header[i]=SC_USBC_CC_RX_READ_DATA;
                DBGPRN3(PRN_USBCC,"CC_Header[%d] = 0x%2bx\n", (USHRT)i,CC_Header[i]);
                //SramDebug(0xF900+i, SC_USBC_CC_RX_READ_DATA);
            }
            //DBGPRN2(PRN_USBCC,"CC_DATA_ARRAY[0x18] = %bx\n", CC_DATA_ARRAY[0x18]);
        }
        else {
            DBGPRN1(PRN_USBCC_Error, "USB CC RX0 UFP GetHeader no valid\r\n");
            SC_USBC_CC_RX_CTRL|=BIT2;   // CC_RX manual address reset
            SC_USBC_CC_RX_CTRL&= ~BIT2; 
            for (i=0;i<2;i++) {
                CC_Header[i]=SC_USBC_CC_RX_READ_DATA;
                DBGPRN3(PRN_USBCC,"CC_Header[%d] = 0x%2bx\n", (USHRT)i,CC_Header[i]);
            }
        }
    }
}

/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:
 *
 *----------------------------------------------------------------------------*/
void USBCCGetDataMessage(UCHAR layer)
//void USBCCGetDataMessage(void)
{
    UCHAR CC_DATA_ARRAY[6];
    //UCHAR CC_DATA_ARRAY[30];
    UCHAR i,temp,cmd_type;
    
#if 0    
    // Switch to RTX0
    //SC_DVI_CTRL_32F=0x02; // bit4=0 index of CCRTX0
    SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  

#else
    if (layer==CC_Link0) {
        //DBGPRN1(PRN_USBCC, "USB CC RX0 UFP Receive Message \r\n");
        SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
        //DBGPRN1(PRN_USBCC, "USB CC UFP\r\n");
        SramDebug(0xF840, UFP);
    }
    else {//(layer==CC_Link1)
        //DBGPRN1(PRN_USBCC, "USB CC RX0 DFP Receive Message \r\n");
        //SC_DVI_CTRL_32F=0x12; // bit4=0 index of CCRTX0  
        SC_DVI_CTRL_32F|=BIT4; // bit4=1 index of CCRTX1 
        //DBGPRN1(PRN_USBCC, "USB CC DFP\r\n");
        SramDebug(0xF840, DFP);
    }
#endif

    //USBCCIntFlagRead();
    //USBCCIntFlagClear();
    //Sleep(10);

    temp=SC_USBC_CC_RX_CTRL;
    if (temp & 0x80) {// command only
        cmd_type=SC_USBC_CC_RX_CTRL&CC_RX_RD_CMD_MASK;
        //DBGPRN2(PRN_USBCC,"command is 0x%bx\n", cmd_type);
    }
    else {// Control message or data message
        // Gate CC 測起來沒實際作用,so close it
        SC_USBC_CC_RX_CTRL|=BIT1;   // CC_RX read gate set 1, Gate CC if previous message not read out
        if (USBCC_GetData()) {
            //DBGPRN1(PRN_USBCC, "GetData valid\r\n");
            SC_USBC_CC_RX_CTRL|=BIT2;   // CC_RX manual address reset
            SC_USBC_CC_RX_CTRL&= ~BIT2;
            //for(i=0;i<6;i++)
            for(i=0;i<30;i++) {

                SramDebug(0xF830+i, SC_USBC_CC_RX_READ_DATA);
                //CC_DATA_ARRAY[i]=SC_USBC_CC_RX_READ_DATA;
                //DBGPRN3(PRN_USBCC,"CC_DATA[%d] = 0x%bx\n", (USHRT)i,CC_DATA_ARRAY[i]);
            }
        }
        else {
            DBGPRN1(PRN_USBCC_Error, "GetData no valid\r\n");
            SC_USBC_CC_RX_CTRL|=BIT2;   // CC_RX manual address reset
            SC_USBC_CC_RX_CTRL&= ~BIT2;
            for (i=0;i<6;i++) {
                CC_DATA_ARRAY[i]=SC_USBC_CC_RX_READ_DATA;
                //SramDebug(0xF900+i, SC_USBC_CC_RX_READ_DATA);
                //DBGPRN3(PRN_USBCC,"CC_DATA[%d] = 0x%bx\n", (USHRT)i,CC_DATA_ARRAY[i]);
            }
        }
    }
}

void USBCCConfigHPD(BOOL enable)
{
    //printf("USBCCConfigHPD %x,(%x,%x)\r\n",(USHRT)enable,(USHRT)ucUSBCCPEState,(USHRT)ucVDMDiscoverState);
    if (((ucUSBCCPEState == PE_SNK_Wait_for_Capabilities) && (ucVDMDiscoverState == VDM_Discover_unknow)) ||    // AC/DC on case
        ((ucUSBCCPEState == PE_SNK_Ready) && (ucVDMDiscoverState >= VDM_DP_Configure))) {                       // Normal case
        if (enable) {
            USBCCSendVDOMessage(UFP,2,0,Attention);
            bUSBCCHPDActive = FALSE;
        }
        else {
            USBCCSendVDOMessage(UFP,2,0,Attention_HPD_Low);
            bUSBCCHPDActive = TRUE;
        }
    }
}

BOOL IsUSBCCHPDActive(void)
{
    return bUSBCCHPDActive;
}

BOOL IsUSBCCConnect(void)
{
    if ((SC_USBC_CC_CFG & BIT1) == BIT1) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

UCHAR USBCCGetVDMDiscoverState(void)
{
    return ucVDMDiscoverState;
}
#else
void ForUSBTypeCCompilerCodePass2(void)
{
  code UCHAR temp[]={0x00};
  UCHAR i;
  i = temp[0];
}

#endif
