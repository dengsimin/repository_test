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
/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:
 *
 *----------------------------------------------------------------------------*/

#ifdef ENABLE_FPGA_MODE

void FPGA_USB_CC_Verify(void)
{
    USHRT test_item;
    // 20151001 Yung FPGA verify CC protocol use
    //DBGPRN1(PRN_USBCC, "FPGA USB CC verify \r\n");

    //test_item=0x43; //0x0A;
    test_item=0x01;
    
    switch(test_item)
    {
        case 0x00:
            FPGA_USB_Timer_Read();
            break;
        case 0x01:
            FPGA_USB_CMD_TEST();
            break;
        case 0x02:
            FPGA_USB_ControlMessage_Test();
            break;
        case 0x03:
            FPGA_USB_DataMessage_Test();
            break;
        case 0x04:
            FPGA_USB_MessageID_Test();  // for 
            break;
        case 0x05:
            FPGA_USB_Auto_MessageID_Test();  // function OK
            break;
        case 0x06:
            FPGA_USB_Auto_Reply_GoodCRC_Test();  // 
            break;
        case 0x07:
            FPGA_USB_Manual_Timer_Test();
            break;
        case 0x08:
            FPGA_USB_SendWrongCRC_Test();
            break;
         case 0x09:
            FPGA_USB_Retry_Counter_Test();
            break;
        case 0x10:
            FPGA_USB_DFPUFP_PDCommunication_Test();
            break;
        case 0x11:
            FPGA_USB_DFPUFP_VDOCommunication_Test();
            break;
        case 0x12:
            FPGA_USB_DFPUFP_VDM_Busy_Test();
            break;
        case 0x13:
            FPGA_USB_DFPUFP_VDOCommunication_Test_ByINT();
            break;
        case 0x20:
            FPGA_USB_UFP_BISTReceiverMode_Test();   // function OK
            break;
        case 0x21:
            FPGA_USB_UFP_BISTTransmitMode_Test();   // function OK
            break;
        case 0x22:
            FPGA_USB_UFP_BISTCarrierMode2_Test();   // function OK
            break;
        case 0x23:
            FPGA_USB_UFP_BISTestData_Test();
            break;
        case 0x30:
            FPGA_USB_UFP_DP_HPD_Message_Test();   // function OK
            break;
        case 0x40:
            FPGA_USB_1stSourceCap_TX_Check_mode_Test();   // 
            break;
        case 0x41:
            FPGA_USB_Iniator_Request_Respone_MSG_Test();   // 
            break;
        case 0x42:
            FPGA_USB_Iniator_Request_Respone_Timer_Test();   // 
            break;
        case 0x43:
            FPGA_USB_Iniator_Ping_MSG_Test();   // 
            break;

           
        case 0x88:
            FPGA_USB_PRBS_Test();
            break;
        default:
            break;

            
    }

    while (1) 
    {   // Yung test USB CC cpmmunication
        ResetWDTimer();
    }
	
}


/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:
 *
 *----------------------------------------------------------------------------*/
void FPGA_USB_CMD_TEST(void)
{
    DBGPRN1(PRN_USBCC, "FPGA CC TX1 DFP Send CMD test \r\n");
    //SC_DVI_CTRL_32F=0x02; // bit4=0 index of CCRTX0
    SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
    SC_USBC_CC_RX_CMD_GATE=0x00; // No command gate at test
    SC_USBC_CC_RESET_CTRL=0x00; // Disable auto hw_rst when thet hardware_rst cmd
    
    SC_DVI_CTRL_32F=0x12; // bit4=1 index of CCRTX1
    SC_USBC_CC_RX_CMD_GATE=0x00; // No command gate at test

#if 0
    // legal cmd only test
    USBCCSendCommand(CC_Link1,Hard_Reset);    // legal cmd only
    USBCCLink0Receiver();
    
    USBCCSendCommand(CC_Link1,Cable_Reset);   // legal cmd only
    USBCCLink0Receiver();
#else
    // illegal cmd only test , setting is at USBCCSendCommand() function
    USBCCSendCommand(CC_Link1,SOP);       // illegal cmd only, for test only ,check waveform
    USBCCLink0Receiver();
    
    USBCCSendCommand(CC_Link1,SOPP);      // illegal cmd only, for test only ,check waveform
    USBCCLink0Receiver();                 // For Cable_Plug,NT68870 no use

    USBCCSendCommand(CC_Link1,SOPPP);       // illegal cmd only, for test only ,check waveform
    USBCCLink0Receiver();
   
    USBCCSendCommand(CC_Link1,SOPP_Debug);       // illegal cmd only, for test only ,check waveform
    USBCCLink0Receiver();
    
    USBCCSendCommand(CC_Link1,SOPPP_Debug);       // illegal cmd only, for test only ,check waveform
    USBCCLink0Receiver();
#endif

}

/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:
 *
 *----------------------------------------------------------------------------*/
void FPGA_USB_Timer_Read(void)
{
    //UCHAR i;
    DBGPRN1(PRN_USBCC, "FPGA CC DFP Timer Read\r\n");

    USBCCTimerRead(CC_Link0,0x00);
    USBCCTimerRead(CC_Link0,0x10);
    USBCCTimerRead(CC_Link0,0x20);
    USBCCTimerRead(CC_Link0,0x30);
    USBCCTimerRead(CC_Link0,0x40);
    USBCCTimerRead(CC_Link0,0x50);
    USBCCTimerRead(CC_Link0,0x60);
    USBCCTimerRead(CC_Link0,0x70);
    USBCCTimerRead(CC_Link0,0x80);

    
}

/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description: This function is used to test Control Message only
 *
 *----------------------------------------------------------------------------*/
void FPGA_USB_ControlMessage_Test(void)
{
    DBGPRN1(PRN_USBCC, "FPGA CC TX1 DFP Send Control Message Test!\r\n");


/*
for test RX can get "valid" flag  and get correct Header value
result: if not disable RX drop same message ID,the valid flag just only 1st receive can valid, 
others after 2nd receive message all no valid
*/

//======= for no auto reply GoodCRC verify=========
    SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
    SC_USBC_CC_RX_CTRL2=0x34;   //0x34=b7 set0 disable RX drop same message ID

//======= for add auto reply GoodCRC verify=========
     // for auto replay GoodCRC timing test
    SC_USBC_CC_RX_AUTO_REPLY_ENABLE=0x0B;//  // 0xD7E[3]=1 RX check CRC, [1]=1 auto replay [0]:1 GoodCRC check MessagID correvtness
    // Adj timer08
    SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
    SC_USBC_CC_TIMER_CTRL&=0x0F;    //
    SC_USBC_CC_TIMER_CTRL|=(CRCTransmitTimer);

    SC_USBC_CC_TIMER_PERIODH=0x00;  // set 200us for test , default 0x0064 is 100us
    SC_USBC_CC_TIMER_PERIODL=0xc8;

    


    // Total 13 Control message
    USBCCSendControlMessage(CC_Link1,GoodCRC);  // Source, Sink or Cable Plug
    USBCCGetControlMessage();

#if 0

    USBCCSendControlMessage(CC_Link1,GotoMin);  // Source Only
    USBCCGetControlMessage();


    USBCCSendControlMessage(CC_Link1,Accept);  // Source, Sink or Cable Plug
    USBCCGetControlMessage();

    USBCCSendControlMessage(CC_Link1,Reject);
    USBCCGetControlMessage();


    USBCCSendControlMessage(CC_Link1,Ping);  // Source Only
    USBCCGetControlMessage();

    USBCCSendControlMessage(CC_Link1,PS_RDY);
    USBCCGetControlMessage();

    USBCCSendControlMessage(CC_Link1,Get_Source_Cap);
    USBCCGetControlMessage();

    USBCCSendControlMessage(CC_Link1,Get_Sink_Cap);
    USBCCGetControlMessage();

    USBCCSendControlMessage(CC_Link1,DR_SWAP);
    USBCCGetControlMessage();

    USBCCSendControlMessage(CC_Link1,PR_SWAP);
    USBCCGetControlMessage();

    USBCCSendControlMessage(CC_Link1,VCONN_SWAP);
    USBCCGetControlMessage();

    USBCCSendControlMessage(CC_Link1,Wait);
    USBCCGetControlMessage();

    USBCCSendControlMessage(CC_Link1,Soft_Reset);
    USBCCGetControlMessage();
   

    USBCCSendControlMessage(CC_Link1,0x00); // send not valid command for interrupt flag test
    USBCCGetControlMessage();
#endif
    
}

/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:
 *
 *----------------------------------------------------------------------------*/
void FPGA_USB_DataMessage_Test(void)
{
    SC_USBC_CC_TX_AUTO_MSGID=0x10;  // 0xD75[0]=0 disable auto MSG_ID

    //SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
    // RX at listen mode, no auto reply
    //SC_USBC_CC_RX_CTRL2=0xD4;   // in listen mode and FIFO full ban

    USBCCSendDataMessage(CC_Link1,1,0,Source_Capabilities);
    Sleep(1);
    USBCCGetDataMessage(CC_Link0);
    //USBCCGetCRCValue();

    USBCCSendDataMessage(CC_Link1,0,0,GoodCRC);
    Sleep(1);
    USBCCGetDataMessage(CC_Link0);
    //USBCCGetCRCValue();

#if 0
    USBCCSendDataMessage(CC_Link1,1,1,Vendor_Defined);// VDM
    USBCCGetDataMessage();
    USBCCGetCRCValue();

    USBCCSendDataMessage(CC_Link1,0,2,Soft_Reset);
    USBCCGetDataMessage();
    USBCCGetCRCValue();

#endif


}

/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:
 *
 *----------------------------------------------------------------------------*/
void FPGA_USB_MessageID_Test(void)
{
    DBGPRN1(PRN_USBCC, "CC DFP UFP Manual MesgID test!\r\n");
    // Manual MessageID test
    SC_USBC_CC_TX_AUTO_MSGID=0x10;  // 0xD75[0]=0 disable auto MSG_ID
    USBCCSendDataMessage(CC_Link1,0,0,GoodCRC);  // Source, Sink or Cable Plug
    USBCCGetControlMessage();
    USBCCGetCRCValue();

    USBCCSendDataMessage(CC_Link1,0,1,GoodCRC);  // Source, Sink or Cable Plug
    USBCCGetControlMessage();
    USBCCGetCRCValue();

    USBCCSendDataMessage(CC_Link1,0,2,GoodCRC);  // Source, Sink or Cable Plug
    USBCCGetControlMessage();
    USBCCGetCRCValue();

    USBCCSendDataMessage(CC_Link1,0,3,GoodCRC);  // Source, Sink or Cable Plug
    USBCCGetControlMessage();
    USBCCGetCRCValue();

#if 0
    USBCCSendDataMessage(CC_Link1,1,0,Source_Capabilities);
    USBCCGetDataMessage();
    //USBCCGetCRCValue();

    USBCCSendDataMessage(CC_Link1,1,4,Source_Capabilities);
    USBCCGetDataMessage();
    USBCCGetCRCValue();
#endif

}

/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:
 *
 *----------------------------------------------------------------------------*/
void FPGA_USB_Auto_MessageID_Test(void)
{
    UCHAR i;
    DBGPRN1(PRN_USBCC, "CC DFP UFP Auto MesgID test!\r\n");

    //SC_USBC_CC_TX_AUTO_MSGID=0x10;  // 0xD75[0]=1 enable auto MSG_ID
    for(i=0;i<2;i++)
    {
        //=================>>>>> DFP MsgID=0
        USBCCSendDataMessage(CC_Link1,1,0,Source_Capabilities); // Souce D-->
        Sleep(1);   // TX send 
        USBCCCounterRead(DFP,MessageIDCounter);//===============================
        //USBCCSoftwareReset(); // for FPGA issue inout
        USBCCGetDataMessage(UFP);  // UFP
        SramDump(2);

        
        USBCCSendDataMessage(CC_Link0,0,0,GoodCRC); //  <--Sink C
        Sleep(1);
        //USBCCCounterRead(UFP,MessageIDCounter);//===============================
        //USBCCSoftwareReset();
        USBCCGetDataMessage(CC_Link1);  // DFP
        SramDump(2);

        
        // ================<<<<<<< UFP MsgID=0
        USBCCSendDataMessage(CC_Link0,1,0,Request); //  <--Sink D
        Sleep(1);
        USBCCCounterRead(UFP,MessageIDCounter);//===============================
        //USBCCSoftwareReset();
        USBCCGetDataMessage(CC_Link1);  // DFP
        SramDump(2);


        USBCCSendDataMessage(CC_Link1,0,0,GoodCRC); //  Souce C-->
        Sleep(1);
        //USBCCCounterRead(DFP,MessageIDCounter);//===============================
        //USBCCSoftwareReset();
        USBCCGetDataMessage(CC_Link0);  // UFP
        SramDump(2);


        //=================>>>>> DFP MsgID=1
        USBCCSendDataMessage(CC_Link1,0,0,Accept); // Souce C --> 
        Sleep(1);   // TX send 
        USBCCCounterRead(DFP,MessageIDCounter);//===============================
        //USBCCSoftwareReset();
        USBCCGetDataMessage(CC_Link0);  // UFP
        SramDump(2);
        
        USBCCSendDataMessage(CC_Link0,0,0,GoodCRC); //  <--Sink C
        Sleep(1);
        //USBCCCounterRead(UFP,MessageIDCounter);//===============================
        //USBCCSoftwareReset();
        USBCCGetDataMessage(CC_Link1);  // DFP
        SramDump(2);


        //==================>>>>> DFP MsgID=2
        USBCCSendDataMessage(CC_Link1,0,0,PS_RDY); // Souce C --> 
        Sleep(1);   // TX send 
        USBCCCounterRead(DFP,MessageIDCounter);//===============================
        //USBCCSoftwareReset();
        USBCCGetDataMessage(CC_Link0);  // UFP
        SramDump(2);

        USBCCSendDataMessage(CC_Link0,0,0,GoodCRC); //  <--Sink C
        Sleep(1);
        //USBCCCounterRead(UFP,MessageIDCounter);//===============================
        //USBCCSoftwareReset();
        USBCCGetDataMessage(CC_Link1);  // DFP
        SramDump(2);

        //=================>>>>> DFP MsgID=3
        USBCCSendDataMessage(CC_Link1,0,0,Get_Sink_Cap); // Souce C --> 
        Sleep(1);   // TX send 
        USBCCCounterRead(DFP,MessageIDCounter);//===============================
        //USBCCSoftwareReset();
        USBCCGetDataMessage(CC_Link0);  // UFP
        SramDump(2);

        USBCCSendDataMessage(CC_Link0,0,0,GoodCRC); //  <--Sink C
        Sleep(1);
        //USBCCCounterRead(UFP,MessageIDCounter);//===============================
        //USBCCSoftwareReset();
        USBCCGetDataMessage(CC_Link1);  // DFP
        SramDump(2);
        
        // ================<<<<<<< UFP MsgID=1
        USBCCSendDataMessage(CC_Link0,1,0,Sink_Capabilities); //  <--Sink D
        Sleep(1);
        USBCCCounterRead(UFP,MessageIDCounter);//===============================
        //USBCCSoftwareReset();
        USBCCGetDataMessage(CC_Link1);  // DFP
        SramDump(2);

        USBCCSendDataMessage(CC_Link1,0,0,GoodCRC); //  Souce C-->
        Sleep(1);
        //USBCCCounterRead(DFP,MessageIDCounter);//===============================
        //USBCCSoftwareReset();
        USBCCGetDataMessage(CC_Link0);  // UFP
        SramDump(2);


    }
/**/

    
}


/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:Verify auto reply GoodCRC check
 *
 *----------------------------------------------------------------------------*/
void FPGA_USB_Auto_Reply_GoodCRC_Test(void)
{
     
     // for auto replay GoodCRC timing test
    SC_USBC_CC_RX_AUTO_REPLY_ENABLE=0x0B;//  // 0xD7E[3]=1 RX check CRC, [1]=1 auto replay [0]:1 GoodCRC check MessagID correvtness
    // Adj timer08
    SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
    SC_USBC_CC_TIMER_CTRL&=0x0F;    //
    SC_USBC_CC_TIMER_CTRL|=(CRCTransmitTimer);

    SC_USBC_CC_TIMER_PERIODH=0x00;  // set 200us for test , default is 100us
    SC_USBC_CC_TIMER_PERIODL=0xc8;
    //SC_USBC_CC_CFG=0x90;

    // no interrupt
    DBGPRN1(PRN_USBCC, "CC TX1 DFP Send Test!\r\n");
    //=================>>>>> Discover Identity
    USBCCSendDataMessage(DFP,1,0,Vendor_Defined); // Souce D-->
    Sleep(1);   // TX send 
    //USBCCSoftwareReset();
    USBCCGetDataMessage(UFP);  // UFP
    SramDump(6);
    DBGPRN1(PRN_USBCC, "CC RX0 UFP Get Test!\r\n");

    USBCCGetDataMessage(DFP);  // DFP
    SramDump(6);
    DBGPRN1(PRN_USBCC, "DFP Get GoodCRC Data!\r\n");


/*
    USBCCSendDataMessage(UFP,0,0,GoodCRC); //  <--Sink C
    Sleep(1);
    //USBCCSoftwareReset();
    //USBCCGetDataMessage(DFP);  // DFP
    DBGPRN1(PRN_USBCC, "CC RX1 DFP Get GoodCRC!\r\n");

    // ================<<<<<<< Discover Identity Ack
    USBCCSendDataMessage(UFP,1,0,Vendor_Defined); //  <--Sink D
    Sleep(1);
    USBCCSoftwareReset();
    USBCCGetDataMessage(DFP);  // DFP

    USBCCSendDataMessage(DFP,0,0,GoodCRC); //  Souce C-->
    Sleep(1);
    USBCCSoftwareReset();
    USBCCGetDataMessage(UFP);  // UFP
 */   

}

/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:Verify auto reply GoodCRC check
 *
 *----------------------------------------------------------------------------*/
void FPGA_USB_Manual_Timer_Test(void)
{

    DBGPRN1(PRN_USBCC, "CC manual Timer Test!\r\n");
     // for auto replay GoodCRC timing test
    SC_USBC_CC_RX_AUTO_REPLY_ENABLE=0x0B;//  // 0xD7E[3]=1 RX check CRC, [1]=1 auto replay [0]:1 GoodCRC check MessagID correvtness
    // Adj timer08
    SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
    SC_USBC_CC_TIMER_CTRL&=0x0F;    // clear b[7:4]
    SC_USBC_CC_TIMER_CTRL|=(CRCTransmitTimer);

    SC_USBC_CC_TIMER_PERIODH=0x00;  // set 200us for test , default is 100us
    SC_USBC_CC_TIMER_PERIODL=0xc8;

    // Adj manual timer0
    SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
    SC_USBC_CC_TIMER_CTRL&=0x0F;    // clear b[7:4]
    SC_USBC_CC_TIMER_CTRL|=(Manu0);

    SC_USBC_CC_TIMER_PERIODH=0x00;  // set 200us for test , default is 100us
    SC_USBC_CC_TIMER_PERIODL=0xc8;


    // Adj manual timer1
    SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
    SC_USBC_CC_TIMER_CTRL&=0x0F;    // clear b[7:4]
    SC_USBC_CC_TIMER_CTRL|=(Manu1);

    SC_USBC_CC_TIMER_PERIODH=0x00;  // set 200us for test , default is 100us
    SC_USBC_CC_TIMER_PERIODL=0xc8;

    SC_USBC_CC_TIMER_CTRL|=(CC_Manu_Timer0_START);
    SC_USBC_CC_TIMER_CTRL|=(CC_Manu_Timer1_START);

    // no interrupt
    DBGPRN1(PRN_USBCC, "CC TX1 DFP Send Test!\r\n");
    //=================>>>>> Discover Identity
    USBCCSendDataMessage(DFP,1,0,Vendor_Defined); // Souce D-->
    Sleep(1);   // TX send 
    //USBCCSoftwareReset();
    USBCCGetDataMessage(UFP);  // UFP
    SramDump(6);


}


/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:
 *
 *----------------------------------------------------------------------------*/
void FPGA_USB_SendWrongCRC_Test(void)
{
    DBGPRN1(PRN_USBCC, "CC DFP Send wrong CRC Test!\r\n");
    
    SC_USBC_CC_TX_AUTO_MSGID=0x18;  // 0xD75[0]=0 disable auto MSG_ID and [3]=1 set manual CRC

    USBCCSendDataMessage(CC_Link1,1,0,Source_Capabilities);// DFP
    USBCCGetDataMessage(UFP);
    USBCCIntFlagRead();
    USBCCIntFlagClear();
    USBCCGetCRCValue();


    USBCCSendDataMessage(CC_Link1,0,1,GoodCRC);  // Source, Sink or Cable Plug
    USBCCGetControlMessage();
    USBCCGetCRCValue();
    
}

/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:
 *
 *----------------------------------------------------------------------------*/
void FPGA_USB_Retry_Counter_Test(void)
{
    UCHAR i;

    DBGPRN1(PRN_USBCC, "CC DFP Retry Counter Test!\r\n");
    

    // DFP initial Retry counter
    SC_DVI_CTRL_32F|=BIT4; // bit4=1 index of CCRTX1 
    SC_USBC_CC_COUNTER_SEL_CLEAR=0x4F;  // counter clear
    SC_USBC_CC_COUNTER_SEL_CLEAR=0x40;  // counter sel Retry counter
    //SC_USBC_CC_TX_AUTO_MSGID=0x13;  // 0xD75[0]=1 enableable auto MSG_ID and [1]=1 auto retry, [3]=0 set disable manual CRC
    // HW auto retry and need chk reply
    SC_USBC_CC_TX_AUTO_MSGID=0x17;  // 0xD75[0]=1 enableable auto MSG_ID and [1]=1 auto retry,[2]=1 TX_chk_reply, [3]=0 set disable manual CRC

    // The retry counter is not usage when FW control the retry message
    //SC_USBC_CC_TX_AUTO_MSGID=0x15;  // 0xD75[0]=1 enableable auto MSG_ID and [1]=1 auto retry, [3]=0 set disable manual CRC

    // UFP disable auto reply
    SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
    SC_USBC_CC_RX_AUTO_REPLY_ENABLE=0x08;//0x0A;//  // 0xD7E[1] enable auto replay, [3]:RX chk CRC
    SC_USBC_CC_TX_AUTO_MSGID=0x11;  // 0xD75[0]=0 disable auto MSG_ID and [3]=1 set manual CRC
    SC_USBC_CC_RX_CTRL2&=(~BIT5);
        
    for(i=0;i<3;i++)
    {
        DBGPRN2(PRN_USBCC,"DFP send Source Cap num is 0x%bx =========\n", i);

        USBCCSendDataMessage(CC_Link1,1,0,Source_Capabilities);// DFP
        Sleep(1);   // TX send 
        USBCCIntFlagRead();
        USBCCIntFlagClear();

        USBCCGetDataMessage(UFP);
        SramDump(2);

        SC_DVI_CTRL_32F|=BIT4; // bit4=1 index of CCRTX1 
        DBGPRN2(PRN_USBCC,"DFP Retry Counter is 0x%bx\n", SC_USBC_CC_COUNTER_READH);
        DBGPRN2(PRN_USBCC,"DFP Retry Counter is 0x%bx\n", SC_USBC_CC_COUNTER_READL);

    }

    //USBCCSendDataMessage(CC_Link1,0,1,GoodCRC);  // Source, Sink or Cable Plug
    //USBCCGetControlMessage();
    
}
/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:??MacBook <--> TPV TI CC chip PD communication
 *
 *----------------------------------------------------------------------------*/
void FPGA_USB_DFPUFP_PDCommunication_Test(void)
{
    // no interrupt
    DBGPRN1(PRN_USBCC, "CC TX1 DFP Send Test!\r\n");
    //=================>>>>>
    USBCCSendDataMessage(CC_Link1,1,0,Source_Capabilities); // Souce D-->
    Sleep(1);   // TX send 
    //USBCCSoftwareReset(); // for FPGA issue inout
    USBCCGetDataMessage(UFP);  // UFP
    SramDump(6);
    

    USBCCSendDataMessage(CC_Link0,0,0,GoodCRC); //  <--Sink C
    Sleep(1);
    //USBCCSoftwareReset();
    USBCCGetDataMessage(CC_Link1);  // DFP
    SramDump(6);

#if 1    
    // ================<<<<<<<
    USBCCSendDataMessage(CC_Link0,1,0,Request); //  <--Sink D
    Sleep(1);
    //USBCCSoftwareReset();
    USBCCGetDataMessage(CC_Link1);  // DFP

    USBCCSendDataMessage(CC_Link1,0,0,GoodCRC); //  Souce C-->
    Sleep(1);
    //USBCCSoftwareReset();
    USBCCGetDataMessage(CC_Link0);  // UFP

    //=================>>>>>
    USBCCSendDataMessage(CC_Link1,0,0,Accept); // Souce C --> 
    Sleep(1);   // TX send 
    //USBCCSoftwareReset();
    USBCCGetDataMessage(CC_Link0);  // UFP
    
    USBCCSendDataMessage(CC_Link0,0,0,GoodCRC); //  <--Sink C
    Sleep(1);
    USBCCSoftwareReset();
    USBCCGetDataMessage(CC_Link1);  // DFP

    //==================>>>>>
    USBCCSendDataMessage(CC_Link1,0,0,PS_RDY); // Souce C --> 
    Sleep(1);   // TX send 
    //USBCCSoftwareReset();
    USBCCGetDataMessage(CC_Link0);  // UFP
    
    USBCCSendDataMessage(CC_Link0,0,0,GoodCRC); //  <--Sink C
    Sleep(1);
    //USBCCSoftwareReset();
    USBCCGetDataMessage(CC_Link1);  // DFP


    //=================>>>>>
    USBCCSendDataMessage(CC_Link1,0,0,Get_Sink_Cap); // Souce C --> 
    Sleep(1);   // TX send 
    //USBCCSoftwareReset();
    USBCCGetDataMessage(CC_Link0);  // UFP
    
    USBCCSendDataMessage(CC_Link0,0,0,GoodCRC); //  <--Sink C
    Sleep(1);
    //USBCCSoftwareReset();
    USBCCGetDataMessage(CC_Link1);  // DFP

    
    // ================<<<<<<<
    USBCCSendDataMessage(CC_Link0,1,0,Sink_Capabilities); //  <--Sink D
    Sleep(1);
    //USBCCSoftwareReset();
    USBCCGetDataMessage(CC_Link1);  // DFP

    USBCCSendDataMessage(CC_Link1,0,0,GoodCRC); //  Souce C-->
    Sleep(1);
    //USBCCSoftwareReset();
    USBCCGetDataMessage(CC_Link0);  // UFP
#endif    
    
}

/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:??MacBook <--> TPV TI CC chip VDO communication
 *
 *----------------------------------------------------------------------------*/
void FPGA_USB_DFPUFP_VDOCommunication_Test(void)
{

     /*
    // for auto replay GoodCRC timing test
    SC_USBC_CC_RX_AUTO_REPLY_ENABLE=0x0B;//  // 0xD7E[3]=1 RX check CRC, [1]=1 auto replay [0]:1 GoodCRC check MessagID correvtness
    // Adj timer08
    SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
    SC_USBC_CC_TIMER_CTRL&=0x0F;    //
    SC_USBC_CC_TIMER_CTRL|=(CRCTransmitTimer);

    SC_USBC_CC_TIMER_PERIODH=0x00;  // set 200us for test , default is 100us
    SC_USBC_CC_TIMER_PERIODL=0xc8;
    */
    

    // no interrupt
    DBGPRN1(PRN_USBCC, "CC VDO communication Test!\r\n");
    //=================>>>>> Discover Identity
    USBCCSendVDOMessage(DFP,1,0,Discover_Identity); // Souce D-->
    Sleep(1);   // TX send 
    //USBCCSoftwareReset();
    USBCCGetDataMessage(UFP);  // UFP
    SramDump(6);
    //DBGPRN1(PRN_USBCC, "CC RX0 UFP Get Test!\r\n");
    //USBCCIntFlagRead();
    //USBCCIntFlagClear();

    USBCCSendDataMessage(UFP,0,0,GoodCRC); //  <--Sink C
    Sleep(1);
    //USBCCSoftwareReset();
    USBCCGetDataMessage(DFP);  // DFP
    SramDump(2);
    //DBGPRN1(PRN_USBCC, "CC RX1 DFP Get GoodCRC!\r\n");

    // ================<<<<<<< Discover Identity Busy
    USBCCSendVDOMessage(UFP,1,0,Discover_Identity_Busy); //  <--Sink D
    Sleep(1);
    //USBCCSoftwareReset();
    USBCCGetDataMessage(DFP);  // DFP
    SramDump(6);


    USBCCSendDataMessage(DFP,0,0,GoodCRC); //  Souce C-->
    Sleep(1);
    //USBCCSoftwareReset();
    USBCCGetDataMessage(UFP);  // UFP
    SramDump(2);

    // ================<<<<<<< Discover Identity Ack
    //=================>>>>> Discover Identity
    USBCCSendVDOMessage(DFP,2,0,DP_Status_Update); // Souce D-->
    Sleep(1);   // TX send 
    //USBCCSoftwareReset();
    USBCCGetDataMessage(UFP);  // UFP
    SramDump(10);
    //DBGPRN1(PRN_USBCC, "CC RX0 UFP Get Test!\r\n");

    USBCCSendDataMessage(UFP,0,0,GoodCRC); //  <--Sink C
    Sleep(1);
    //USBCCSoftwareReset();
    USBCCGetDataMessage(DFP);  // DFP
    SramDump(2);
    //DBGPRN1(PRN_USBCC, "CC RX1 DFP Get GoodCRC!\r\n");
   

}


/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:??MacBook <--> TPV TI CC chip VDO communication
 *
 *----------------------------------------------------------------------------*/
void FPGA_USB_DFPUFP_VDM_Busy_Test(void)
{
    UCHAR i;

    // ???????VDM Busy counter
    // DFP initial VDM Busy counter
    SC_DVI_CTRL_32F|=BIT4; // bit4=1 index of CCRTX1 
    SC_USBC_CC_COUNTER_SEL_CLEAR=0xCF;  // counter clear
    SC_USBC_CC_COUNTER_SEL_CLEAR=0xC0;  // counter sel VDM Busy counter

    
     /*
    // for auto replay GoodCRC timing test
    SC_USBC_CC_RX_AUTO_REPLY_ENABLE=0x0B;//  // 0xD7E[3]=1 RX check CRC, [1]=1 auto replay [0]:1 GoodCRC check MessagID correvtness
    // Adj timer08
    SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
    SC_USBC_CC_TIMER_CTRL&=0x0F;    //
    SC_USBC_CC_TIMER_CTRL|=(CRCTransmitTimer);

    SC_USBC_CC_TIMER_PERIODH=0x00;  // set 200us for test , default is 100us
    SC_USBC_CC_TIMER_PERIODL=0xc8;
    */
    

    // no interrupt
    DBGPRN1(PRN_USBCC, "CC VDM Busy and Busy counter Test!\r\n");
    //=================>>>>> Discover Identity
    USBCCSendVDOMessage(DFP,1,0,Discover_Identity); // Souce D-->
    Sleep(1);   // TX send 
    //USBCCSoftwareReset();
    //USBCCGetDataMessage(UFP);  // UFP
    //SramDump(6);
    //DBGPRN1(PRN_USBCC, "CC RX0 UFP Get Test!\r\n");
    //USBCCIntFlagRead();
    //USBCCIntFlagClear();

    USBCCSendDataMessage(UFP,0,0,GoodCRC); //  <--Sink C
    Sleep(1);
    //USBCCSoftwareReset();
    //USBCCGetDataMessage(DFP);  // DFP
    //SramDump(2);
    //DBGPRN1(PRN_USBCC, "CC RX1 DFP Get GoodCRC!\r\n");

    for(i=0;i<7;i++)
    {
        DBGPRN2(PRN_USBCC,"UFP VDM busy num is 0x%bx =========\n", i);

        // ================<<<<<<< Discover Identity Busy
        USBCCSendVDOMessage(UFP,1,0,Discover_Identity_Busy); //  <--Sink D
        Sleep(1);
        //USBCCSoftwareReset();
        USBCCGetDataMessage(DFP);  // DFP
        SramDump(6);


        USBCCSendDataMessage(DFP,0,0,GoodCRC); //  Souce C-->
        Sleep(1);
        //USBCCSoftwareReset();
        //USBCCGetDataMessage(UFP);  // UFP
        //SramDump(2);

        DBGPRN2(PRN_USBCC,"DFP VDM Busy Counter is 0x%bx\n", SC_USBC_CC_COUNTER_READH);
        DBGPRN2(PRN_USBCC,"DFP VDM Busy Counter is 0x%bx\n", SC_USBC_CC_COUNTER_READL);

    
    }

    
   

}


/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:??MacBook <--> TPV TI CC chip VDM communication
 *
 *----------------------------------------------------------------------------*/
void FPGA_USB_DFPUFP_VDOCommunication_Test_ByINT(void)
{
    DBGPRN1(PRN_USBCC, "CC TX1 DFP Send Test!\r\n");

    
    //=================>>>>> Discover Identity
    USBCCSendDataMessage(DFP,1,0,Vendor_Defined); // Souce D-->
    //Sleep(1);   // TX send 
    //USBCCSoftwareReset();
    //USBCCGetDataMessage(UFP);  // UFP
    DBGPRN1(PRN_USBCC, "CC RX0 UFP Get Test!\r\n");
    SramDump(6);

    USBCCSendDataMessage(UFP,0,0,GoodCRC); //  <--Sink C
    //Sleep(1);
    //USBCCSoftwareReset();
    //USBCCGetDataMessage(DFP);  // DFP
    DBGPRN1(PRN_USBCC, "CC RX1 DFP Get GoodCRC!\r\n");
    SramDump(6);

    // ================<<<<<<< Discover Identity Ack
    //USBCCSendDataMessage(UFP,1,0,Vendor_Defined); //  <--Sink D
    USBCCSendVDOMessage(UFP,4,0,Discover_Identity_Ack); //  <--Sink D
    //Sleep(1);
    //USBCCSoftwareReset();
    //USBCCGetDataMessage(DFP);  // DFP
    DBGPRN1(PRN_USBCC, "CC RX0 DFP Get VDM Id ack!\r\n");
    SramDump(6);

    USBCCSendDataMessage(DFP,0,0,GoodCRC); //  Souce C-->
    //Sleep(1);
    //USBCCSoftwareReset();
    //USBCCGetDataMessage(UFP);  // UFP
    DBGPRN1(PRN_USBCC, "CC RX0 UFP Get GoodCRC!\r\n");
    SramDump(6);

}


/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:
 *
 *----------------------------------------------------------------------------*/
void FPGA_USB_UFP_BISTReceiverMode_Test(void)
{
    UCHAR Status;
    UCHAR i;

    DBGPRN1(PRN_USBCC, "FPGA CC BIST Receivr Mode Test!\r\n");

    // UFP initial BIST counter
    SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
    SC_USBC_CC_COUNTER_SEL_CLEAR=0x8F;  // counter clear
    SC_USBC_CC_COUNTER_SEL_CLEAR=0x80;  // counter sel BIST counter
    SC_USBC_CC_BIST_CTRL=0x80;  // Shift PRBS8 1T

    //=================>>>>> BIST
    USBCCSendBISTMessage(DFP,1,0,BISTReceiverMode); // Souce D-->
    Sleep(1);   // TX send 
    USBCCSendDataMessage(UFP,0,0,GoodCRC); //  <--Sink C
    USBCCGetDataMessage(UFP);  // UFP
    SramDump(6);
    USBCCIntFlagRead();
    USBCCIntFlagClear();


    for(i=0;i<2;i++)
    {
        // DFP enter manual BIS TX mode
        SC_DVI_CTRL_32F|=BIT4; // bit4=1 index of CCRTX1 
        SC_USBC_CC_BIST_CTRL=0x04;  // manual TX enable
        SC_USBC_CC_TX_CTRL|=0x01;   // send PRBS-8 out

        SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
        DBGPRN2(PRN_USBCC,"DFP test frame num is 0x%bx =========\n", i);
        DBGPRN2(PRN_USBCC,"UFP BIST Counter is 0x%bx\n", SC_USBC_CC_COUNTER_READH);
        DBGPRN2(PRN_USBCC,"UFP BIST Counter is 0x%bx\n", SC_USBC_CC_COUNTER_READL);
        
    }
    Status=SC_USBC_CC_BIST_CTRL;
    DBGPRN2(PRN_USBCC,"UFP BIST Status before Hardreset is 0x%bx\n", Status);


    // Using Hard reset cmd to terminate BIST test
    SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
    SC_USBC_CC_RX_CMD_GATE=0x00; // No command gate at test
    //SC_USBC_CC_RESET_CTRL=0x00; // Disable auto hw_rst when get hardware_rst cmd
    SC_USBC_CC_RESET_CTRL=0x40; // Disable auto hw_rst when get hardware_rst cmd

    SC_DVI_CTRL_32F=0x12; // bit4=1 index of CCRTX1
    SC_USBC_CC_RX_CMD_GATE=0x00; // No command gate at test
    // legal cmd only test
    USBCCSendCommand(CC_Link1,Hard_Reset);    // legal cmd only
    USBCCLink0Receiver();

    // if receive Hardware reset,then need to do reset action, or use auto hardware reset 0xD61[6]=1
    DBGPRN2(PRN_USBCC,"UFP BIST Status After Hardreset is 0x%bx\n", SC_USBC_CC_BIST_CTRL);
    

/*
    SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
    Status=SC_USBC_CC_BIST_CTRL;
    DBGPRN2(PRN_USBCC,"UFP BIST Status is 0x%bx\n", Status);
    DBGPRN2(PRN_USBCC,"UFP BIST Counter is 0x%bx\n", SC_USBC_CC_COUNTER_READH);
    DBGPRN2(PRN_USBCC,"UFP BIST Counter is 0x%bx\n", SC_USBC_CC_COUNTER_READL);

    SC_DVI_CTRL_32F|=BIT4; // bit4=1 index of CCRTX1 
    Status=SC_USBC_CC_BIST_CTRL;
    DBGPRN2(PRN_USBCC,"DFP BIST Status is 0x%bx\n", Status);
    DBGPRN2(PRN_USBCC,"DFP BIST Counter is 0x%bx\n", SC_USBC_CC_COUNTER_READH);
    DBGPRN2(PRN_USBCC,"DFP BIST Counter is 0x%bx\n", SC_USBC_CC_COUNTER_READL);
    SC_USBC_CC_TX_CTRL|=0x01;   // send PRBS-8 out
*/


}

/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:
 *
 *----------------------------------------------------------------------------*/
void FPGA_USB_UFP_BISTTransmitMode_Test(void)
{
    UCHAR i,Status;

    DBGPRN1(PRN_USBCC, "FPGA CC BIST Transmit Mode Test!\r\n");

    // UFP initial BIST counter
    SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
    SC_USBC_CC_BIST_CTRL=0x80;// Shift PRBS8 1T
    //SC_USBC_CC_BIST_CTRL=0x00;// no Shift PRBS8 1T
    SC_USBC_CC_BIST_ENTER_HOLD_TIME=0xFF;
    //SC_USBC_CC_RX_AUTO_REPLY_ENABLE=0x0A;//  // 0xD7E enable auto replay

    // DFP initial BIST counter
    SC_DVI_CTRL_32F|=BIT4; // bit4=1 index of CCRTX1 
    SC_USBC_CC_COUNTER_SEL_CLEAR=0x8F;  // counter clear
    SC_USBC_CC_COUNTER_SEL_CLEAR=0x80;  // counter sel BIST counter
    //SC_USBC_CC_BIST_ENTER_HOLD_TIME=0x00;

    //=================>>>>> BIST
    USBCCSendBISTMessage(DFP,1,0,BISTTransmitMode); // Souce D-->
    Sleep(1);   // TX send 
    //USBCCGetDataMessage(UFP);  // UFP
    //SramDump(6);
    
    USBCCSendDataMessage(UFP,0,0,GoodCRC); //  <--Sink C
    Sleep(1);
    //USBCCGetDataMessage(DFP);  // DFP
    //SramDump(2);
    
    // DFP
    SC_DVI_CTRL_32F|=BIT4; // bit4=1 index of CCRTX1 
    SC_USBC_CC_BIST_CTRL=0x02; // b1:manual RX enable
    // 0xD68[6] carrier mode2, [5]transmit mode, [4]receiver mode
    DBGPRN2(PRN_USBCC,"DFP BIST Status is 0x%bx\n", SC_USBC_CC_BIST_CTRL);


    // check UFP is enter transmit mode or not?
    SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
    // 0xD68[6] carrier mode2, [5]transmit mode, [4]receiver mode
    DBGPRN2(PRN_USBCC,"UFP BIST Status is BIST TX mode? 0x%bx\n", SC_USBC_CC_BIST_CTRL);

    // UFP ?? Transmit Mode, then UFP should send test frame to DFP
    // So DFP need to enter BIST error count
    #if 1
    for(i=0;i<10;i++)
    {
        SC_DVI_CTRL_32F|=BIT4; // bit4=1 index of CCRTX1 
    //USBCCIntFlagRead();
    
        // UFP enter manual BIS TX mode
        SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
        //SC_DVI_CTRL_32F|=BIT4; // bit4=1 index of CCRTX1 
        SC_USBC_CC_BIST_CTRL|=BIT2;// Bist manual TX enable
        SC_USBC_CC_TX_CTRL|=0x01;   // send PRBS-8 out
        

        SC_DVI_CTRL_32F|=BIT4; // bit4=1 index of CCRTX1 
    //USBCCIntFlagRead();
        //SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
        DBGPRN2(PRN_USBCC,"UFP test frame num is 0x%bx =========\n", i);
        DBGPRN2(PRN_USBCC,"DFP BIST Counter is 0x%bx\n", SC_USBC_CC_COUNTER_READH);
        DBGPRN2(PRN_USBCC,"DFP BIST Counter is 0x%bx\n", SC_USBC_CC_COUNTER_READL);
        
    }
    #endif


}


/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:
 *
 *----------------------------------------------------------------------------*/
void FPGA_USB_UFP_BISTCarrierMode2_Test(void)
{
    UCHAR Status;


    DBGPRN1(PRN_USBCC, "FPGA CC BIST Carrier Mode2 Test!\r\n");

    SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
    SC_USBC_CC_COUNTER_SEL_CLEAR=0x80;  // counter sel BIST counter
    SC_USBC_CC_COUNTER_SEL_CLEAR=0x80;  // counter sel BIST counter
    SC_USBC_CC_BIST_CTRL=0x80;

    //=================>>>>> BIST
    USBCCSendBISTMessage(DFP,1,0,BISTCarrierMode2); // Souce D-->
    Sleep(1);   // TX send 
    //USBCCSendDataMessage(UFP,0,0,GoodCRC); //  <--Sink C  c2 mode no need GoodCRC
    USBCCGetDataMessage(UFP);  // UFP
    SramDump(6);
    
    // check UFP is enter C2 mode or not? if time too short the C2 Mode flag can't be read
    SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
    // 0xD68[6] carrier mode2, [5]transmit mode, [4]receiver mode
    DBGPRN2(PRN_USBCC,"UFP BIST Status is C2 mode? 0x%bx\n", SC_USBC_CC_BIST_CTRL);


    // After C2 mode, Check normal communication is ok or not?
    SC_DVI_CTRL_32F|=BIT4; // bit4=1 index of CCRTX1 
    USBCCIntFlagRead();
    USBCCIntFlagClear();
    USBCCSoftwareReset(); // DFP reset
    
/*
    FPGA_USB_DFPUFP_PDCommunication_Test();
    */
/*
    USBCCSendDataMessage(UFP,1,0,Source_Capabilities); // Souce D-->
    Sleep(1);   // TX send 
    USBCCGetDataMessage(DFP);  // UFP
    SramDump(6);
*/

/*
    // Using C2 mode no need Hard reset cmd to terminate BIST test
    SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
    SC_USBC_CC_RX_CMD_GATE=0x00; // No command gate at test
    SC_USBC_CC_RESET_CTRL=0x00; // Disable auto hw_rst when thet hardware_rst cmd
    
    SC_DVI_CTRL_32F=0x12; // bit4=1 index of CCRTX1
    SC_USBC_CC_RX_CMD_GATE=0x00; // No command gate at test
    // legal cmd only test
    USBCCSendCommand(CC_Link1,Hard_Reset);    // legal cmd only
    USBCCLink0Receiver();

    // 0xD68[6] carrier mode2, [5]transmit mode, [4]receiver mode
    DBGPRN2(PRN_USBCC,"UFP BIST Status After Hardreset is 0x%bx\n", SC_USBC_CC_BIST_CTRL);
*/



}

/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:
 *
 *----------------------------------------------------------------------------*/
void FPGA_USB_UFP_BISTestData_Test(void)
{
    UCHAR Status;

    DBGPRN1(PRN_USBCC, "FPGA CC BIST Test data Test!\r\n");

    SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
    SC_USBC_CC_COUNTER_SEL_CLEAR=0x80;  // counter sel BIST counter
    SC_USBC_CC_COUNTER_SEL_CLEAR=0x80;  // counter sel BIST counter
    SC_USBC_CC_BIST_CTRL=0x80;

    //=================>>>>> BIST
    USBCCSendBISTMessage(DFP,7,0,BISTTestData); // Souce D-->
    Sleep(1);   // TX send 
    USBCCSendDataMessage(UFP,0,0,GoodCRC); //  <--Sink C
    USBCCGetDataMessage(UFP);  // UFP  rember to modify receive data number
    SramDump(30);

    //=================>>>>> BIST
    USBCCSendBISTMessage(DFP,6,0,BISTTestData); // Souce D-->
    Sleep(1);   // TX send 
    USBCCSendDataMessage(UFP,0,0,GoodCRC); //  <--Sink C
    USBCCGetDataMessage(UFP);  // UFP  rember to modify receive data number
    SramDump(26);

    //=================>>>>> BIST
    USBCCSendBISTMessage(DFP,5,0,BISTTestData); // Souce D-->
    Sleep(1);   // TX send 
    USBCCSendDataMessage(UFP,0,0,GoodCRC); //  <--Sink C
    USBCCGetDataMessage(UFP);  // UFP  rember to modify receive data number
    SramDump(22);

    //=================>>>>> BIST
    USBCCSendBISTMessage(DFP,4,0,BISTTestData); // Souce D-->
    Sleep(1);   // TX send 
    USBCCSendDataMessage(UFP,0,0,GoodCRC); //  <--Sink C
    USBCCGetDataMessage(UFP);  // UFP  rember to modify receive data number
    SramDump(18);

    //=================>>>>> BIST
    USBCCSendBISTMessage(DFP,3,0,BISTTestData); // Souce D-->
    Sleep(1);   // TX send 
    USBCCSendDataMessage(UFP,0,0,GoodCRC); //  <--Sink C
    USBCCGetDataMessage(UFP);  // UFP  rember to modify receive data number
    SramDump(14);

    //=================>>>>> BIST
    USBCCSendBISTMessage(DFP,2,0,BISTTestData); // Souce D-->
    Sleep(1);   // TX send 
    USBCCSendDataMessage(UFP,0,0,GoodCRC); //  <--Sink C
    USBCCGetDataMessage(UFP);  // UFP  rember to modify receive data number
    SramDump(10);

    //=================>>>>> BIST
    USBCCSendBISTMessage(DFP,1,0,BISTTestData); // Souce D-->
    Sleep(1);   // TX send 
    USBCCSendDataMessage(UFP,0,0,GoodCRC); //  <--Sink C
    USBCCGetDataMessage(UFP);  // UFP  rember to modify receive data number
    SramDump(6);    
    
    //SramDump(6);

/*
    // DFP enter manual BIS TX mode
    SC_DVI_CTRL_32F|=BIT4; // bit4=1 index of CCRTX1 
    SC_USBC_CC_BIST_CTRL=0x04;
    SC_USBC_CC_TX_CTRL|=0x01;   // send PRBS-8 out


    USBCCSendBISTMessage(UFP,1,0,BISTTransmitMode);
    USBCCSendDataMessage(DFP,0,0,GoodCRC); //  <--Sink C
    Sleep(1);   // TX send 
    USBCCGetDataMessage(DFP);  // DFP
    SramDump(6);
    //USBCCSendCommand(DFP,Hard_Reset);
*/



}


/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:
 *
 *----------------------------------------------------------------------------*/
void FPGA_USB_UFP_DP_HPD_Message_Test(void)
{

    DBGPRN1(PRN_USBCC, "UFP DP_HPD message Test!\r\n");

    // UFP DP_HPD Auto reply setting
    SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
    SC_USBC_CC_HPDPD_CTRL1=0x23;    // b0:TX auto HPDPD, b[3:1]obj pos, b[5:4] 10-UFP 01-DFP 11-DFP&UFP, b6:HPDPD_Power low, b7:HPD_PD enable
    SC_USBC_CC_HPDPD_CTRL2=0x08;

    // triger Manual DP_HPD
    SC_DP_DEBUG|=BIT6;
    Sleep(1);   // TX send 
    //USBCCSendDataMessage(DFP,0,0,GoodCRC); //  <--Sink C
    USBCCGetDataMessage(DFP);  // UFP  rember to modify receive data number
    SramDump(10);


    // UFP DP_HPD Auto reply setting
    SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
    SC_USBC_CC_HPDPD_CTRL1=0x23;
    SC_USBC_CC_HPDPD_CTRL2=0x0F;    // change this value to check VDO data also change or not

    // triger Manual DP_HPD
    SC_DP_DEBUG|=BIT6;
    Sleep(1);   // TX send 
    //USBCCSendDataMessage(DFP,0,0,GoodCRC); //  <--Sink C
    USBCCGetDataMessage(DFP);  // UFP  rember to modify receive data number
    SramDump(10);


    // UFP DP_HPD Auto reply setting, change obj position
    SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
    SC_USBC_CC_HPDPD_CTRL1=0x57;
    SC_USBC_CC_HPDPD_CTRL2=0x05;    // change this value to check VDO data also change or not

    // triger Manual DP_HPD
    SC_DP_DEBUG|=BIT6;
    Sleep(1);   // TX send 
    //USBCCSendDataMessage(DFP,0,0,GoodCRC); //  <--Sink C
    USBCCGetDataMessage(DFP);  // UFP  rember to modify receive data number
    SramDump(14);

    
}



/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description: test 0x1681[7:6] TX RX response type
 *
 *----------------------------------------------------------------------------*/
void FPGA_USB_1stSourceCap_TX_Check_mode_Test(void)
{
    //UCHAR i;

    DBGPRN1(PRN_USBCC, "CC TX Check mode Test!\r\n");
    
#if 1
    // DFP initial Retry counter==============================
    SC_DVI_CTRL_32F|=BIT4; // bit4=1 index of CCRTX1 
    SC_USBC_CC_COUNTER_SEL_CLEAR=0x4F;  // counter clear
    SC_USBC_CC_COUNTER_SEL_CLEAR=0x40;  // counter sel Retry counter
    // HW auto retry and need chk reply
    //SC_USBC_CC_TX_AUTO_MSGID=0x17;  // 0xD75[0]=1 enableable auto MSG_ID and [1]=1 auto retry,[2]=1 TX_chk_reply, [3]=0 set disable manual CRC

    // The retry counter is not usage when FW control the retry message
    //SC_USBC_CC_TX_AUTO_MSGID=0x15;//0x15;  // 0xD75[0]=1 enableable auto MSG_ID and [1]=1 auto retry, [3]=0 set disable manual CRC
    // set 0x15 DFP can't get GoodCRC reply
    SC_USBC_CC_TX_AUTO_MSGID=0x17;
    
    SC_USBC_CC_TX_MANUAL_ADDR|=(CC_Req_Respons_Type_Data_MSG|CC_Get_Respons_Type_Data_MSG);
    SC_USBC_CC_RX_AUTO_REPLY_ENABLE=(CC_RX_GoodCRC_CHK_MSGID|CC_RX_Auto_Reply_GoodCRC|CC_RX_CHK_CRC);//0x0B;//DFP no auto reply GoodCRC 0x08;//0x0A;//  // 0xD7E[1] enable auto replay, [3]:RX chk CRC
    //SC_USBC_CC_RX_AUTO_REPLY_ENABLE=0x08;//DFP no auto reply GoodCRC 0x08;//0x0A;//  // 0xD7E[1] enable auto replay, [3]:RX chk CRC
    
    // UFP disable auto reply===============================
    SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
    //SC_USBC_CC_RX_AUTO_REPLY_ENABLE=0x08;//0x08;//0x0A;//0x0B;//  // 0xD7E[1]:enable auto replay, [0]: GoodCRC check MSGID disable, [3]:RX chk CRC
    SC_USBC_CC_RX_AUTO_REPLY_ENABLE=0x0B;
    SC_USBC_CC_TX_AUTO_MSGID=0x11;//0x11;  // 0xD75[0]=0 disable auto MSG_ID and [3]=1 set manual CRC
    SC_USBC_CC_TX_AUTO_MSGID=0x17;//0x11;  // 0xD75[0]=0 disable auto MSG_ID and [3]=1 set manual CRC
    
    //SC_USBC_CC_TX_AUTO_MSGID=0x10;//0x11;  // 0xD75[0]=0 disable auto MSG_ID and [3]=1 set manual CRC

    //SC_USBC_CC_RX_CTRL2&=(~BIT5);
    SC_USBC_CC_TX_MANUAL_ADDR|=(BIT6|BIT7); //0xC0; // 0x81[7:6]

    // Adj AutoReply GoodCRC Transmit timer
    SC_USBC_CC_TIMER_CTRL&=0x0F;    //
    //SC_USBC_CC_TIMER_CTRL|=(CRCReceiverTimer);
    SC_USBC_CC_TIMER_CTRL|=(CRCTransmitTimer);
    if(1){
        SC_USBC_CC_TIMER_PERIODH=0x00;  // set 200us=0x00C8 or 400us=0x190 for test , default is 100us
        SC_USBC_CC_TIMER_PERIODL=0xC8;  // CRCReceiver "in time"
    }
    else{
        SC_USBC_CC_TIMER_PERIODH=0x80;  // set > 1ms, CRCReceiver "time out"
        SC_USBC_CC_TIMER_PERIODL=0x01;
    }
// case 1 UFP auto reply
    DBGPRN1(PRN_USBCC, "DFP Check mode enable and UFP auto reply!\r\n");
    SC_DVI_CTRL_32F|=BIT4; // DFP bit4=1 index of CCRTX1 
    USBCCSendDataMessage(CC_Link1,1,0,Source_Capabilities);// DFP
    //USBCCSendDataMessage(CC_Link1,1,0,Request);// DFP
    
    DBGPRN1(PRN_USBCC, "UFP Get=========!\r\n");
    USBCCGetDataMessage(UFP);
    SramDump(6);
    USBCCIntFlagRead();
    
    DBGPRN1(PRN_USBCC, "DFP Get=========!\r\n");
    USBCCGetDataMessage(DFP);
    SramDump(2);
    USBCCIntFlagRead();

#else
// case 2 UFP manual reply
    DBGPRN1(PRN_USBCC, "DFP Check mode enable and UFP manual reply!\r\n");

    // DFP initial Retry counter
    SC_DVI_CTRL_32F|=BIT4; // bit4=1 index of CCRTX1 
    SC_USBC_CC_TX_AUTO_MSGID=0x17;
    SC_USBC_CC_TX_MANUAL_ADDR|=(CC_Req_Respons_Type_Data_MSG|CC_Get_Respons_Type_Data_MSG);
    SC_USBC_CC_RX_AUTO_REPLY_ENABLE=(CC_RX_GoodCRC_CHK_MSGID|CC_RX_Auto_Reply_GoodCRC|CC_RX_CHK_CRC);//0x0B;//DFP no auto reply GoodCRC 0x08;//0x0A;//  // 0xD7E[1] enable auto replay, [3]:RX chk CRC

    // UFP disable auto reply
    SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
    SC_USBC_CC_TX_AUTO_MSGID=0x17;  //0x17;//0x11;  // 0xD75[0]=0 disable auto MSG_ID and [3]=1 set manual CRC
    //SC_USBC_CC_TX_MANUAL_ADDR=(CC_Req_Respons_Type_Data_MSG|CC_Get_Respons_Type_Data_MSG);
    SC_USBC_CC_RX_AUTO_REPLY_ENABLE=(CC_RX_GoodCRC_CHK_MSGID|CC_RX_CHK_CRC);//UFP no auto reply GoodCRC 0x08;//0x0A;//  // 0xD7E[1] enable auto replay, [3]:RX chk CRC

    //SC_USBC_CC_TX_MANUAL_ADDR=(CC_Req_Respons_Type_Data_MSG);
    //SC_USBC_CC_TX_MANUAL_ADDR=(CC_Get_Respons_Type_Data_MSG);

    SC_DVI_CTRL_32F|=BIT4; // DFP bit4=1 index of CCRTX1 
    USBCCSendDataMessage(CC_Link1,1,0,Source_Capabilities);// DFP

    //Sleep(1);   // If no add this sleep time,the RX can't get the valid data 
    for(i=0;i<200;i++)  // 215us control manual reply goodCRC timing
    {
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();    
    }
    USBCCSendDataMessage(UFP,0,0,GoodCRC);// UFP reply GoodCRC
    Sleep(1);   // If no add this sleep time,the RX can't get the valid data 
    
    DBGPRN1(PRN_USBCC, "UFP Get=========!\r\n");
    USBCCGetDataMessage(UFP);
    SramDump(6);
    USBCCIntFlagRead();
    
    DBGPRN1(PRN_USBCC, "DFP Get=========!\r\n");
    USBCCGetDataMessage(DFP);
    SramDump(2);
    USBCCIntFlagRead();

#endif  


}


/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description: test 0x1681[7:6] TX RX response type
 *
 *----------------------------------------------------------------------------*/
void FPGA_USB_Iniator_Request_Respone_MSG_Test(void)
{
    UCHAR i,j;

    // This test for 0x1681[7:6] Get response and Request response type 
    // Need to Check 0x1693[1:0] 0x1694[3] int flag behavior 
    DBGPRN1(PRN_USBCC, "CC DFP TX 0x81[7:6] request response Test!\r\n");
    

    // DFP initial Retry counter ===========================================
    SC_DVI_CTRL_32F|=BIT4; // bit4=1 index of CCRTX1 
    // HW auto retry and need chk reply
    SC_USBC_CC_TX_AUTO_MSGID=0x17;  // 0xD75[0]=1 enableable auto MSG_ID and [1]=1 auto retry,[2]=1 TX_chk_reply,[3]=0 set disable manual CRC
    // The retry counter is not usage when FW control the retry message
    //SC_USBC_CC_TX_AUTO_MSGID=0x11;  // 0xD75[0]=1 enableable auto MSG_ID and [1]=1 auto retry,[2]=1 TX_chk_reply,[3]=0 set disable manual CRC

    SC_USBC_CC_RX_AUTO_REPLY_ENABLE=(CC_RX_GoodCRC_CHK_MSGID|CC_RX_Auto_Reply_GoodCRC|CC_RX_CHK_CRC);//0x0B;//DFP no auto reply GoodCRC 0x08;//0x0A;//  // 0xD7E[1] enable auto replay, [3]:RX chk CRC
    //SC_USBC_CC_RX_AUTO_REPLY_ENABLE=(CC_RX_GoodCRC_CHK_MSGID|CC_RX_CHK_CRC);//0x0B;//DFP no auto reply GoodCRC 0x08;//0x0A;//  // 0xD7E[1] enable auto replay, [3]:RX chk CRC

    // adj this factor to check int flag 0x1693 and 0x1694    
    SC_USBC_CC_TX_MANUAL_ADDR=(CC_Req_Respons_Type_Data_MSG|CC_Get_Respons_Type_Data_MSG);
    //SC_USBC_CC_TX_MANUAL_ADDR=(CC_Get_Respons_Type_Data_MSG);
    //SC_USBC_CC_TX_MANUAL_ADDR=(CC_Req_Respons_Type_Data_MSG); //
    
    // UFP disable auto reply===============================================
    SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
    // HW auto retry and need chk reply
    SC_USBC_CC_TX_AUTO_MSGID=0x17;  // 0xD75[0]=1 enableable auto MSG_ID and [1]=1 auto retry,[2]=1 TX_chk_reply,[3]=0 set disable manual CRC
    // The retry counter is not usage when FW control the retry message
    //SC_USBC_CC_TX_AUTO_MSGID=0x11;  // 0xD75[0]=1 enableable auto MSG_ID and [1]=1 auto retry,[2]=1 TX_chk_reply,[3]=0 set disable manual CRC

    
    //SC_USBC_CC_RX_AUTO_REPLY_ENABLE=0x0B;//0x08;//0x0A;//0x0B;//  // 0xD7E[1] enable auto replay, [3]:RX chk CRC
    //SC_USBC_CC_RX_AUTO_REPLY_ENABLE=0x08;
    SC_USBC_CC_RX_AUTO_REPLY_ENABLE=(CC_RX_GoodCRC_CHK_MSGID|CC_RX_Auto_Reply_GoodCRC|CC_RX_CHK_CRC);//0x0B;//DFP no auto reply GoodCRC 0x08;//0x0A;//  // 0xD7E[1] enable auto replay, [3]:RX chk CRC
    //SC_USBC_CC_RX_AUTO_REPLY_ENABLE=(CC_RX_GoodCRC_CHK_MSGID|CC_RX_CHK_CRC);//0x0B;//DFP no auto reply GoodCRC 0x08;//0x0A;//  // 0xD7E[1] enable auto replay, [3]:RX chk CRC
    //SC_USBC_CC_RX_CTRL2&=(~BIT5);
    //SC_USBC_CC_TX_MANUAL_ADDR=(BIT6|BIT7); //0xC0; // 0x81[7:6]
    //SC_USBC_CC_TX_MANUAL_ADDR=BIT6; //0xC0; // 0x81[7:6]
    //SC_USBC_CC_TX_MANUAL_ADDR=(BIT7); //0xC0; // 0x81[7:6]


        
    //for(i=0;i<3;i++)
    {
#if 0
// case 2: send Accept control message 
        DBGPRN1(PRN_USBCC, "DFP Check mode enable and UFP auto reply!\r\n");
        DBGPRN1(PRN_USBCC, "DFP send Accept and UFP auto reply!\r\n");

        SC_DVI_CTRL_32F|=BIT4; // DFP bit4=1 index of CCRTX1 
        USBCCSendDataMessage(CC_Link1,0,0,Accept);// DFP
        Sleep(1);   // If no add this sleep time,the RX can't get the valid data
   


        DBGPRN1(PRN_USBCC, "DFP Get GoodCRC=========!\r\n");
        USBCCGetDataMessage(DFP);
        SramDump(2);
        USBCCIntFlagRead();
        USBCCIntFlagClear();


        DBGPRN1(PRN_USBCC, "UFP Get Accept=========!\r\n");
        USBCCGetDataMessage(UFP);
        SramDump(6);
        USBCCIntFlagRead();
        USBCCIntFlagClear();
#endif

// case 1: send source capability Data message test       
        SC_DVI_CTRL_32F|=BIT4; // DFP bit4=1 index of CCRTX1 
        USBCCSendDataMessage(CC_Link1,1,0,Source_Capabilities);// DFP
        Sleep(1);   // If no add this sleep time,the RX can't get the valid data 



        DBGPRN1(PRN_USBCC, "DFP Get GoodCRC=========!\r\n");
        USBCCGetDataMessage(DFP);
        SramDump(2);
        USBCCIntFlagRead();
        USBCCIntFlagClear();


        DBGPRN1(PRN_USBCC, "UFP Get Source cap=========!\r\n");
        USBCCGetDataMessage(UFP);
        SramDump(6);
        USBCCIntFlagRead();
        USBCCIntFlagClear();

    }
}

/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description: test 0x1681[7:6] TX RX response type
 *
 *----------------------------------------------------------------------------*/
void FPGA_USB_Iniator_Request_Respone_Timer_Test(void)
{
    UCHAR i,j;

    // This test for 0x1681[7:6] Get response and Request response type 
    // Need to Check 0x1693[1:0] 0x1694[3] int flag behavior 
    DBGPRN1(PRN_USBCC, "CC DFP TX 0x81[7:6] request response Test!\r\n");
    

    // DFP initial Retry counter ===========================================
    SC_DVI_CTRL_32F|=BIT4; // bit4=1 index of CCRTX1 
    // HW auto retry and need chk reply
    SC_USBC_CC_TX_AUTO_MSGID=0x17;  // 0xD75[0]=1 enableable auto MSG_ID and [1]=1 auto retry,[2]=1 TX_chk_reply,[3]=0 set disable manual CRC
    // The retry counter is not usage when FW control the retry message
    //SC_USBC_CC_TX_AUTO_MSGID=0x11;  // 0xD75[0]=1 enableable auto MSG_ID and [1]=1 auto retry,[2]=1 TX_chk_reply,[3]=0 set disable manual CRC

    SC_USBC_CC_RX_AUTO_REPLY_ENABLE=(CC_RX_GoodCRC_CHK_MSGID|CC_RX_Auto_Reply_GoodCRC|CC_RX_CHK_CRC);//0x0B;//DFP no auto reply GoodCRC 0x08;//0x0A;//  // 0xD7E[1] enable auto replay, [3]:RX chk CRC
    //SC_USBC_CC_RX_AUTO_REPLY_ENABLE=(CC_RX_GoodCRC_CHK_MSGID|CC_RX_CHK_CRC);//0x0B;//DFP no auto reply GoodCRC 0x08;//0x0A;//  // 0xD7E[1] enable auto replay, [3]:RX chk CRC

    // adj this factor to check int flag 0x1693 and 0x1694    
    //SC_USBC_CC_TX_MANUAL_ADDR=(CC_Req_Respons_Type_Data_MSG|CC_Get_Respons_Type_Data_MSG);
    //SC_USBC_CC_TX_MANUAL_ADDR=(CC_Get_Respons_Type_Data_MSG);
    //SC_USBC_CC_TX_MANUAL_ADDR=(CC_Req_Respons_Type_Data_MSG);
    
    // UFP disable auto reply===============================================
    SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
    // HW auto retry and need chk reply
    SC_USBC_CC_TX_AUTO_MSGID=0x17;  // 0xD75[0]=1 enableable auto MSG_ID and [1]=1 auto retry,[2]=1 TX_chk_reply,[3]=0 set disable manual CRC
    // The retry counter is not usage when FW control the retry message
    //SC_USBC_CC_TX_AUTO_MSGID=0x11;  // 0xD75[0]=1 enableable auto MSG_ID and [1]=1 auto retry,[2]=1 TX_chk_reply,[3]=0 set disable manual CRC

    
    //SC_USBC_CC_RX_AUTO_REPLY_ENABLE=0x0B;//0x08;//0x0A;//0x0B;//  // 0xD7E[1] enable auto replay, [3]:RX chk CRC
    //SC_USBC_CC_RX_AUTO_REPLY_ENABLE=0x08;
    SC_USBC_CC_RX_AUTO_REPLY_ENABLE=(CC_RX_GoodCRC_CHK_MSGID|CC_RX_Auto_Reply_GoodCRC|CC_RX_CHK_CRC);//0x0B;//DFP no auto reply GoodCRC 0x08;//0x0A;//  // 0xD7E[1] enable auto replay, [3]:RX chk CRC
    //SC_USBC_CC_RX_AUTO_REPLY_ENABLE=(CC_RX_GoodCRC_CHK_MSGID|CC_RX_CHK_CRC);//0x0B;//DFP no auto reply GoodCRC 0x08;//0x0A;//  // 0xD7E[1] enable auto replay, [3]:RX chk CRC
    //SC_USBC_CC_RX_CTRL2&=(~BIT5);
    //SC_USBC_CC_TX_MANUAL_ADDR=(BIT6|BIT7); //0xC0; // 0x81[7:6]
    //SC_USBC_CC_TX_MANUAL_ADDR=BIT6; //0xC0; // 0x81[7:6]
    //SC_USBC_CC_TX_MANUAL_ADDR=(BIT7); //0xC0; // 0x81[7:6]


        
    //for(i=0;i<3;i++)
    {
        DBGPRN1(PRN_USBCC, "DFP Check mode enable and UFP auto reply!\r\n");

// case 1: send source capability        
        SC_DVI_CTRL_32F|=BIT4; // DFP bit4=1 index of CCRTX1 
        USBCCSendDataMessage(CC_Link1,1,0,Source_Capabilities);// DFP
        Sleep(1);   // If no add this sleep time,the RX can't get the valid data 

        Sleep(3); // total 4 is delay value about 25ms, adjust this for SenderResponseTimer time out
        for(j=0;j<5;j++){       // j<5 timer in time, j<6 timer out of time
            for(i=0;i<200;i++)  // 
            {
                _nop_();
                _nop_();
                _nop_();
                _nop_();
                _nop_();
                _nop_();
                _nop_();
                _nop_();
                _nop_();    
            }
        }  
        // If only test iniator Request & response flga, mark this part 
        // UFP <-- Request
        USBCCSendDataMessage(CC_Link0,1,0,Request); //  <--Sink D
        Sleep(1);

        /*    
        */
        DBGPRN1(PRN_USBCC, "DFP Get=========!\r\n");
        USBCCGetDataMessage(DFP);
        SramDump(2);
        USBCCIntFlagRead();
        USBCCIntFlagClear();


        DBGPRN1(PRN_USBCC, "UFP Get=========!\r\n");
        USBCCGetDataMessage(UFP);
        SramDump(6);
        USBCCIntFlagRead();
        USBCCIntFlagClear();
    

#if 0   // DFP --> Accept
        USBCCSendDataMessage(CC_Link1,0,0,Accept); //  <--Sink D
        Sleep(1);
        
        DBGPRN1(PRN_USBCC, "DFP Get=========!\r\n");
        USBCCGetDataMessage(DFP);
        SramDump(6);
        USBCCIntFlagRead();
        USBCCIntFlagClear();

        DBGPRN1(PRN_USBCC, "UFP Get=========!\r\n");
        USBCCGetDataMessage(UFP);
        SramDump(6);
        USBCCIntFlagRead();
        USBCCIntFlagClear();

#endif        
    }
    
}


/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description: test 0x1681[7:6] TX RX response type
 *
 *----------------------------------------------------------------------------*/
void FPGA_USB_Iniator_Ping_MSG_Test(void)
{
    UCHAR i,j;

    // This test for 0x1681[7:6] Get response and Request response type 
    // Need to Check 0x1693[1:0] 0x1694[3] int flag behavior 
    DBGPRN1(PRN_USBCC, "CC DFP Ping Message Test!\r\n");
    

    // DFP initial Retry counter ===========================================
    SC_DVI_CTRL_32F|=BIT4; // bit4=1 index of CCRTX1 
    // HW auto retry and need chk reply
    SC_USBC_CC_TX_AUTO_MSGID=0x17;  // 0xD75[0]=1 enableable auto MSG_ID and [1]=1 auto retry,[2]=1 TX_chk_reply,[3]=0 set disable manual CRC
    // The retry counter is not usage when FW control the retry message
    //SC_USBC_CC_TX_AUTO_MSGID=0x11;  // 0xD75[0]=1 enableable auto MSG_ID and [1]=1 auto retry,[2]=1 TX_chk_reply,[3]=0 set disable manual CRC

    SC_USBC_CC_RX_AUTO_REPLY_ENABLE=(CC_RX_GoodCRC_CHK_MSGID|CC_RX_Auto_Reply_GoodCRC|CC_RX_CHK_CRC);//0x0B;//DFP no auto reply GoodCRC 0x08;//0x0A;//  // 0xD7E[1] enable auto replay, [3]:RX chk CRC
    //SC_USBC_CC_RX_AUTO_REPLY_ENABLE=(CC_RX_GoodCRC_CHK_MSGID|CC_RX_CHK_CRC);//0x0B;//DFP no auto reply GoodCRC 0x08;//0x0A;//  // 0xD7E[1] enable auto replay, [3]:RX chk CRC

    // adj this factor to check int flag 0x1693 and 0x1694    
    SC_USBC_CC_TX_MANUAL_ADDR=(CC_Req_Respons_Type_Data_MSG|CC_Get_Respons_Type_Data_MSG);
    //SC_USBC_CC_TX_MANUAL_ADDR=(CC_Get_Respons_Type_Data_MSG);
    //SC_USBC_CC_TX_MANUAL_ADDR=(CC_Req_Respons_Type_Data_MSG); //
    
    // UFP disable auto reply===============================================
    SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
    // HW auto retry and need chk reply
    SC_USBC_CC_TX_AUTO_MSGID=0x17;  // 0xD75[0]=1 enableable auto MSG_ID and [1]=1 auto retry,[2]=1 TX_chk_reply,[3]=0 set disable manual CRC
    // The retry counter is not usage when FW control the retry message
    //SC_USBC_CC_TX_AUTO_MSGID=0x11;  // 0xD75[0]=1 enableable auto MSG_ID and [1]=1 auto retry,[2]=1 TX_chk_reply,[3]=0 set disable manual CRC

    
    //SC_USBC_CC_RX_AUTO_REPLY_ENABLE=0x0B;//0x08;//0x0A;//0x0B;//  // 0xD7E[1] enable auto replay, [3]:RX chk CRC
    //SC_USBC_CC_RX_AUTO_REPLY_ENABLE=0x08;
    SC_USBC_CC_RX_AUTO_REPLY_ENABLE=(CC_RX_GoodCRC_CHK_MSGID|CC_RX_Auto_Reply_GoodCRC|CC_RX_CHK_CRC);//0x0B;//DFP no auto reply GoodCRC 0x08;//0x0A;//  // 0xD7E[1] enable auto replay, [3]:RX chk CRC
    //SC_USBC_CC_RX_AUTO_REPLY_ENABLE=(CC_RX_GoodCRC_CHK_MSGID|CC_RX_CHK_CRC);//0x0B;//DFP no auto reply GoodCRC 0x08;//0x0A;//  // 0xD7E[1] enable auto replay, [3]:RX chk CRC
    //SC_USBC_CC_RX_CTRL2&=(~BIT5);
    //SC_USBC_CC_TX_MANUAL_ADDR=(BIT6|BIT7); //0xC0; // 0x81[7:6]
    //SC_USBC_CC_TX_MANUAL_ADDR=BIT6; //0xC0; // 0x81[7:6]
    //SC_USBC_CC_TX_MANUAL_ADDR=(BIT7); //0xC0; // 0x81[7:6]


        

// Step 1: send source capability Data message test       
        SC_DVI_CTRL_32F|=BIT4; // DFP bit4=1 index of CCRTX1 
        USBCCSendDataMessage(CC_Link1,1,0,Source_Capabilities);// DFP
        Sleep(1);   // If no add this sleep time,the RX can't get the valid data 

        USBCCGetDataMessage(DFP);  // UFP get Source      
        SramDump(2);

        USBCCGetDataMessage(UFP);
        SramDump(2);
        //USBCCIntFlagRead();

        // Read UFP int flag
        if(SC_USBC_CC_INT_GROUP_0_FLAG && 0x01)
        {
            SramDebug(0xF850, SC_USBC_CC_INT_GROUP_0_FLAG);
        }
        
        if(SC_USBC_CC_INT_GROUP_1_FLAG && 0x01)
        {
            SramDebug(0xF851, SC_USBC_CC_INT_GROUP_1_FLAG);
        }
        
        if(SC_USBC_CC_INT_GROUP_2_FLAG && 0x01)
        {
            SramDebug(0xF852, SC_USBC_CC_INT_GROUP_2_FLAG);
        }

        if(SC_USBC_CC_INT_GROUP_3_FLAG && 0x01)
        {
            SramDebug(0xF853, SC_USBC_CC_INT_GROUP_3_FLAG);
        }
        
        if(SC_USBC_CC_INT_GROUP_4_FLAG && 0x01)
        {
            SramDebug(0xF854, SC_USBC_CC_INT_GROUP_4_FLAG);
        }
        //USBCCIntFlagClear();
        Sleep(3);   // 2~3 will cahnge the SinkActiveTimer interrupt falg
        
// Step 2: send Ping CTRL message test       
        USBCCSendDataMessage(CC_Link1,0,0,Ping);// DFP
        Sleep(1); 

        SC_DVI_CTRL_32F&=(~BIT4); // bit4=0 index of CCRTX0  
        // Read UFP int flag
        if(SC_USBC_CC_INT_GROUP_0_FLAG && 0x01)
        {
            SramDebug(0xF860, SC_USBC_CC_INT_GROUP_0_FLAG);
        }
        
        if(SC_USBC_CC_INT_GROUP_1_FLAG && 0x01)
        {
            SramDebug(0xF861, SC_USBC_CC_INT_GROUP_1_FLAG);
        }
        
        if(SC_USBC_CC_INT_GROUP_2_FLAG && 0x01)
        {
            SramDebug(0xF862, SC_USBC_CC_INT_GROUP_2_FLAG);
        }

        if(SC_USBC_CC_INT_GROUP_3_FLAG && 0x01)
        {
            SramDebug(0xF863, SC_USBC_CC_INT_GROUP_3_FLAG);
        }
        
        if(SC_USBC_CC_INT_GROUP_4_FLAG && 0x01)
        {
            SramDebug(0xF864, SC_USBC_CC_INT_GROUP_4_FLAG);
        }
        
        USBCCGetDataMessage(DFP);
        SramDump(2);

        USBCCGetDataMessage(UFP);
        SramDump(2);
        
        // Read DFP int flag
        if(SC_USBC_CC_INT_GROUP_0_FLAG && 0x01)
        {
            SramDebug(0xF870, SC_USBC_CC_INT_GROUP_0_FLAG);
        }
        
        if(SC_USBC_CC_INT_GROUP_1_FLAG && 0x01)
        {
            SramDebug(0xF871, SC_USBC_CC_INT_GROUP_1_FLAG);
        }
        
        if(SC_USBC_CC_INT_GROUP_2_FLAG && 0x01)
        {
            SramDebug(0xF872, SC_USBC_CC_INT_GROUP_2_FLAG);
        }

        if(SC_USBC_CC_INT_GROUP_3_FLAG && 0x01)
        {
            SramDebug(0xF873, SC_USBC_CC_INT_GROUP_3_FLAG);
        }
        
        if(SC_USBC_CC_INT_GROUP_4_FLAG && 0x01)
        {
            SramDebug(0xF874, SC_USBC_CC_INT_GROUP_4_FLAG);
        }
        //USBCCIntFlagClear();
        
        USBCCIntFlagRead();


}

/*-----------------------------------------------------------------------------
 *
 * Module: ()
 * Description:
 *
 *----------------------------------------------------------------------------*/
void FPGA_USB_PRBS_Test(void)
{
//
#if 1  // PRBS8 = X^8 + X^6 + X^5 +x^4 +1
    // PRBS-8 repetion is 255
    UCHAR start = 0xFF;
    UCHAR a = start;
    int i;    
    for(i = 1;; i++) {
        UCHAR newbit = (((((a >> 7) ^ (a >> 5)) ^ (a >> 4))^ (a >> 3)) & 1);
        
        a = ((a << 1) | newbit) & 0xFF; // low bit as PRBS-8
        //printf("a=0x%bx\n", a);
        printf("a=0x%bx\n", newbit);
        if (a == start) {
            printf("repetition period is %d\n", i);
            break;
        }
    }
#endif

#if 0   // PRBS7 X^7+x^6+1
    UCHAR start = 0x02;
    UCHAR a = start;
    UCHAR b = 0x00;
    int i;    
    for(i = 1;; i++) {
        UCHAR newbit = (((a >> 6) ^ (a >> 5)) & 1);
        b=( a & 0x40)>>6;
        a = ((a << 1) | newbit) & 0x7f;
        //printf("a=0x%bx\n", a);
        printf("b=0x%bx\n", b);
        if (a == start) {
            printf("repetition period is %d\n", i);
            break;
        }
    }
#endif
}

#endif /* #if defined(ENABLE_FPGA_MODE)*/



