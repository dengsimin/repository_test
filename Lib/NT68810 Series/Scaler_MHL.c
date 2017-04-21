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
#include "include.h"

#if (INPUT_INTERFACE&INPUT_MHL_MASK)

//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************

//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************
#if IS_NT68850_SERIES
static BOOL bVirtualCBus1 = 0; //Only for NT68850
#endif
#if (INPUT_INTERFACE&INPUT_MHL_MASK)
static UCHAR ucCdsenseFlag;// = 0x00;
#endif
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
void MHLCDSense1On(void)
{
#if IS_NT68770_SERIES && (INPUT_INTERFACE&INPUT_MHL0)
    UCHAR tmp_reg;
    tmp_reg = SC_MCU_IO_CTRL1 & ~(BIT7|BIT6);
    SC_MCU_IO_CTRL1 = tmp_reg | BIT6;
#elif IS_NT68790_SERIES  && (INPUT_INTERFACE&INPUT_MHL0)
    UCHAR tmp_reg;
    tmp_reg = SC_MCU_IO_CTRL1 & ~(BIT5|BIT4);
    SC_MCU_IO_CTRL1 = tmp_reg | BIT4;
	#if defined(MHL_CTS_DEBUG_TEST1)
    RDPA_REG |= BIT4;
	#endif
#elif IS_NT68810_SERIES && (INPUT_INTERFACE&INPUT_MHL0)
    UCHAR tmp_reg;
    tmp_reg = SC_MCU_IO_CTRL1 & ~(BIT5|BIT4);
    SC_MCU_IO_CTRL1 = tmp_reg | BIT4;
#elif IS_NT68870_SERIES && (INPUT_INTERFACE&INPUT_MHL0)
	UCHAR tmp_reg;
	tmp_reg = SC_MCU_IO_CTRL2 & ~(BIT5|BIT4);
	SC_MCU_IO_CTRL2 = tmp_reg | BIT4;	
#elif IS_NT68870_SERIES && (INPUT_INTERFACE&INPUT_MHL2)
	UCHAR tmp_reg;
	tmp_reg = SC_MCU_IO_CTRL0 & ~(BIT4|BIT3|BIT2);
	SC_MCU_IO_CTRL0 = tmp_reg | BIT4;	
#endif
}

void MHLCDSense1Off(void)
{
#if IS_NT68810_SERIES && (INPUT_INTERFACE&INPUT_MHL0)
    SC_MCU_IO_CTRL1 &= ~(BIT5|BIT4);
#elif IS_NT68870_SERIES && (INPUT_INTERFACE&INPUT_MHL0)
	SC_MCU_IO_CTRL2 &= ~(BIT5|BIT4);
#elif IS_NT68870_SERIES && (INPUT_INTERFACE&INPUT_MHL2)
	SC_MCU_IO_CTRL0 &= ~(BIT4|BIT3|BIT2);
#endif
}

void MHLCDSense2On(void)
{
#if IS_NT68770_SERIES && (INPUT_INTERFACE&INPUT_MHL1)
    UCHAR tmp_reg;
    tmp_reg = SC_MCU_IO_CTRL1 & ~(BIT5|BIT4);
    SC_MCU_IO_CTRL1 = tmp_reg | BIT4;
#elif IS_NT68790_SERIES && (INPUT_INTERFACE&INPUT_MHL1)
    UCHAR tmp_reg;
    tmp_reg = SC_MCU_IO_CTRL1 & ~(BIT7|BIT6);
    SC_MCU_IO_CTRL1 = tmp_reg | BIT6;
	#if defined(MHL_CTS_DEBUG_TEST1)
    RDPA_REG |= BIT5;
	#endif
#elif IS_NT68810_SERIES && (INPUT_INTERFACE&INPUT_MHL1)
    UCHAR tmp_reg;
    tmp_reg = SC_MCU_IO_CTRL1 & ~(BIT7|BIT6);
    SC_MCU_IO_CTRL1 = tmp_reg | BIT6;
#elif IS_NT68870_SERIES && (INPUT_INTERFACE&INPUT_MHL1)
	UCHAR tmp_reg;
	tmp_reg = SC_MCU_IO_CTRL2 & ~(BIT7|BIT6);
	SC_MCU_IO_CTRL2 = tmp_reg | BIT6;
#elif IS_NT68870_SERIES && (INPUT_INTERFACE&INPUT_MHL3)
	UCHAR tmp_reg;
	tmp_reg = SC_MCU_IO_CTRL8 & ~(BIT3|BIT2);
	SC_MCU_IO_CTRL8 = tmp_reg | BIT2;	
#endif
}

void MHLCDSense2Off(void)
{
#if IS_NT68810_SERIES && (INPUT_INTERFACE&INPUT_MHL1)
    SC_MCU_IO_CTRL1 &= ~(BIT7|BIT6);
#elif IS_NT68870_SERIES && (INPUT_INTERFACE&INPUT_MHL1)
	SC_MCU_IO_CTRL2 &= ~(BIT7|BIT6);
#elif IS_NT68870_SERIES && (INPUT_INTERFACE&INPUT_MHL3)
	SC_MCU_IO_CTRL8 &= ~(BIT3|BIT2);
#endif
}

BOOL MHL_Is_CDSense1_IO_HIGH()
{
#if INPUT_INTERFACE&INPUT_MHL0
    if (PortA & BIT1) {
        return TRUE;
    }
    else {
        return FALSE;
    }
#elif INPUT_INTERFACE&INPUT_MHL2
    if (PortC & BIT6) {
        return TRUE;
    }
    else {
        return FALSE;
    }	
#else
    return FALSE;
#endif
}

BOOL MHL_Is_CDSense2_IO_HIGH()
{
#if INPUT_INTERFACE&INPUT_MHL1
    if (PortA & BIT0) {
        return TRUE;
    }
    else {
        return FALSE;
    }
#elif INPUT_INTERFACE&INPUT_MHL3
    if (PortE & BIT2) {
        return TRUE;
    }
    else {
        return FALSE;
    }	
#else
    return FALSE;
#endif
}

void MHLCBus1On(void)
{
#if IS_NT68770_SERIES && (INPUT_INTERFACE&INPUT_MHL0)
    UCHAR tmp_reg;
    tmp_reg = SC_MCU_IO_CTRL2 & ~(BIT7|BIT6);
    SC_MCU_IO_CTRL2 = tmp_reg | BIT6;
#elif IS_NT68850_SERIES && (INPUT_INTERFACE&INPUT_MHL0)
    bVirtualCBus1 = ON;
#elif IS_NT68790_SERIES && (INPUT_INTERFACE&INPUT_MHL0)
    UCHAR tmp_reg;
    tmp_reg = SC_MCU_IO_CTRL2 & ~(BIT1|BIT0);
    SC_MCU_IO_CTRL2 = tmp_reg | BIT0;
    if (GetSCID() == SCID_790_A) {
        HPD_CTRL &= ~(BIT0|BIT1);//MHL: HPD off
    }
    else {
        if ((DIG0_HPD_PORT == MCU_PORT_E) && (DIG0_HPD_BIT == BIT6)) { // PE6/HPD1/CBUS1
            HPD_CTRL &= ~(BIT0|BIT1);//MHL: HPD off
        }
        if ((DIG0_HPD_PORT == MCU_PORT_E) && (DIG0_HPD_BIT == BIT7)) { // PE7/HPD2/CBUS2
            HPD_CTRL &= ~(BIT2|BIT3);//MHL: HPD off
        }
    }
#elif IS_NT68810_SERIES && (INPUT_INTERFACE&INPUT_MHL0)
    UCHAR tmp_reg;
    tmp_reg = SC_MCU_IO_CTRL2 & ~(BIT3|BIT2);
    SC_MCU_IO_CTRL2 = tmp_reg | BIT2;
    SC_SetBitDPppPHY(_DPPP_PHY0, _TMDS_HPD_IO_CTRL, BIT5, FALSE);
#elif IS_NT68870_SERIES && (INPUT_INTERFACE&INPUT_MHL0)
	UCHAR tmp_reg;
	tmp_reg = SC_MCU_IO_CTRL9 & ~(BIT3|BIT2);
	SC_MCU_IO_CTRL9 = tmp_reg | BIT2;	
	#if !defined(ENABLE_FPGA_MODE)	
	SC_SetBitDPppPHY(_DPPP_PHY0, _TMDS_HPD_IO_CTRL, BIT6, FALSE);	
	#endif
#elif IS_NT68870_SERIES && (INPUT_INTERFACE&INPUT_MHL2)
	UCHAR tmp_reg;
	tmp_reg = SC_MCU_IO_CTRL7 & ~(BIT7|BIT6);
	SC_MCU_IO_CTRL7 = tmp_reg | BIT6;	
	#if !defined(ENABLE_FPGA_MODE)	
	SC_SetBitDPppPHY(_DPPP_PHY1, _TMDS_HPD_IO_CTRL, BIT6, FALSE);	
	#endif	
#endif
}

void MHLCBus1Off(void)
{
#if IS_NT68770_SERIES
    SC_MCU_IO_CTRL2 &= ~(BIT7|BIT6);
#elif IS_NT68850_SERIES
    bVirtualCBus1 = OFF;
#elif IS_NT68790_SERIES && (INPUT_INTERFACE&INPUT_MHL0)
    SC_MCU_IO_CTRL2 &= ~(BIT1|BIT0);
    if (GetSCID() == SCID_790_A) {
        HPD_CTRL |= BIT1;//HDMI: HPD on
    }
    else {
        if ((DIG0_HPD_PORT == MCU_PORT_E) && (DIG0_HPD_BIT == BIT6)) { // PE6/HPD1/CBUS1
            HPD_CTRL |= BIT1;//HDMI: HPD on
        }
        if ((DIG0_HPD_PORT == MCU_PORT_E) && (DIG0_HPD_BIT == BIT7)) { // PE7/HPD2/CBUS2
            HPD_CTRL |= BIT3;//HDMI: HPD on
        }
    }
#elif IS_NT68810_SERIES && (INPUT_INTERFACE&INPUT_MHL0)
    SC_MCU_IO_CTRL2 &= ~(BIT3|BIT2);
    SC_SetBitDPppPHY(_DPPP_PHY0, _TMDS_HPD_IO_CTRL, BIT5, TRUE);
#elif IS_NT68870_SERIES && (INPUT_INTERFACE&INPUT_MHL0)
	SC_MCU_IO_CTRL9 &= ~(BIT3|BIT2);
	#if !defined(ENABLE_FPGA_MODE)	
	SC_SetBitDPppPHY(_DPPP_PHY0, _TMDS_HPD_IO_CTRL, BIT6, TRUE);
	#endif	
#elif IS_NT68870_SERIES && (INPUT_INTERFACE&INPUT_MHL2)
	SC_MCU_IO_CTRL7 &= ~(BIT7|BIT6);
	#if !defined(ENABLE_FPGA_MODE)	
	SC_SetBitDPppPHY(_DPPP_PHY1, _TMDS_HPD_IO_CTRL, BIT6, TRUE);	
	#endif	
#endif
    ucIsMHLSrcConnected[0] = 0;
}

void MHLCBus2On(void)
{
#if IS_NT68770_SERIES && (INPUT_INTERFACE&INPUT_MHL1)
    UCHAR tmp_reg;
    tmp_reg = SC_MCU_IO_CTRL2 & ~(BIT5|BIT4);
    SC_MCU_IO_CTRL2 = tmp_reg | BIT4;
#elif IS_NT68790_SERIES && (INPUT_INTERFACE&INPUT_MHL1)
    UCHAR tmp_reg;
    tmp_reg = SC_MCU_IO_CTRL2 & ~(BIT3|BIT2);
    SC_MCU_IO_CTRL2 = tmp_reg | BIT2;
    if ((DIG1_HPD_PORT == MCU_PORT_E) && (DIG1_HPD_BIT == BIT6)) { // PE6/HPD1/CBUS1
        HPD_CTRL &= ~(BIT0|BIT1);//MHL: HPD off
    }
    if ((DIG1_HPD_PORT == MCU_PORT_E) && (DIG1_HPD_BIT == BIT7)) { // PE7/HPD2/CBUS2
        HPD_CTRL &= ~(BIT2|BIT3);//MHL: HPD off
    }
#elif IS_NT68810_SERIES && (INPUT_INTERFACE&INPUT_MHL1)
    UCHAR tmp_reg;
    tmp_reg = SC_MCU_IO_CTRL2 & ~(BIT1|BIT0);
    SC_MCU_IO_CTRL2 = tmp_reg | BIT0;
    SC_SetBitDPppPHY(_DPPP_PHY0, _TMDS_HPD_IO_CTRL, BIT6, FALSE);
#elif IS_NT68870_SERIES && (INPUT_INTERFACE&INPUT_MHL1)
	UCHAR tmp_reg;
	tmp_reg = SC_MCU_IO_CTRL9 & ~(BIT1|BIT0);
	SC_MCU_IO_CTRL9 = tmp_reg | BIT0;	
	#if !defined(ENABLE_FPGA_MODE)	
	SC_SetBitDPppPHY(_DPPP_PHY0, _TMDS_HPD_IO_CTRL, BIT5, FALSE);	
	#endif	
#elif IS_NT68870_SERIES && (INPUT_INTERFACE&INPUT_MHL3)
	UCHAR tmp_reg;
	tmp_reg = SC_MCU_IO_CTRL7 & ~(BIT5|BIT4);
	SC_MCU_IO_CTRL7 = tmp_reg | BIT4;	
	#if !defined(ENABLE_FPGA_MODE)	
	SC_SetBitDPppPHY(_DPPP_PHY1, _TMDS_HPD_IO_CTRL, BIT5, FALSE);	
	#endif		
#endif
}

void MHLCBus2Off(void)
{
#if IS_NT68770_SERIES
    SC_MCU_IO_CTRL2 &= ~(BIT5|BIT4);
#elif IS_NT68790_SERIES
    SC_MCU_IO_CTRL2 &= ~(BIT3|BIT2);
    if ((DIG1_HPD_PORT == MCU_PORT_E) && (DIG1_HPD_BIT == BIT6)) { // PE6/HPD1/CBUS1
        HPD_CTRL |= BIT1;//HDMI: HPD on
    }
    if ((DIG1_HPD_PORT == MCU_PORT_E) && (DIG1_HPD_BIT == BIT7)) { // PE7/HPD2/CBUS2
        HPD_CTRL |= BIT3;//HDMI: HPD on
    }
#elif IS_NT68810_SERIES && (INPUT_INTERFACE&INPUT_MHL1)
    SC_MCU_IO_CTRL2 &= ~(BIT1|BIT0);
    SC_SetBitDPppPHY(_DPPP_PHY0, _TMDS_HPD_IO_CTRL, BIT6, TRUE);
#elif IS_NT68870_SERIES && (INPUT_INTERFACE&INPUT_MHL1)
	SC_MCU_IO_CTRL9 &= ~(BIT1|BIT0);
	#if !defined(ENABLE_FPGA_MODE)	
	SC_SetBitDPppPHY(_DPPP_PHY0, _TMDS_HPD_IO_CTRL, BIT5, TRUE);
	#endif
#elif IS_NT68870_SERIES && (INPUT_INTERFACE&INPUT_MHL3)
	SC_MCU_IO_CTRL7 &= ~(BIT5|BIT4);
	#if !defined(ENABLE_FPGA_MODE)	
	SC_SetBitDPppPHY(_DPPP_PHY1, _TMDS_HPD_IO_CTRL, BIT5, TRUE);	
	#endif		
#endif
    ucIsMHLSrcConnected[1] = 0;
}

BOOL MHLIsCBus1On(void)
{
#if IS_NT68770_SERIES
    return ((SC_MCU_IO_CTRL2 & (BIT7|BIT6))==BIT6);
#elif IS_NT68850_SERIES
    return bVirtualCBus1;
#elif IS_NT68790_SERIES
    return ((SC_MCU_IO_CTRL2 & (BIT1|BIT0))==BIT0);
#elif IS_NT68810_SERIES
    return ((SC_MCU_IO_CTRL2 & (BIT1|BIT0))==BIT0);  // with/without external-PULL circuit
    //return ((GetTMDSPHYDATA(_DPPP_PHY0, _TMDS_HPD_IO_CTRL) & (BIT5))==0x00);  // without external-PULL circuit only
#elif IS_NT68870_SERIES && (INPUT_INTERFACE&INPUT_MHL0)
	return ((SC_MCU_IO_CTRL9 & (BIT3|BIT2))==BIT2);
#elif IS_NT68870_SERIES && (INPUT_INTERFACE&INPUT_MHL2)
	return ((SC_MCU_IO_CTRL7 & (BIT7|BIT6))==BIT6);	 
#else
    return FALSE;
#endif
}

BOOL MHLIsCBus2On(void)
{
#if IS_NT68770_SERIES
    return ((SC_MCU_IO_CTRL2 & (BIT5|BIT4))==BIT4);
#elif IS_NT68850_SERIES
    return FALSE;
#elif IS_NT68790_SERIES
    return ((SC_MCU_IO_CTRL2 & (BIT3|BIT2))==BIT2);
#elif IS_NT68810_SERIES
    return ((SC_MCU_IO_CTRL2 & (BIT3|BIT2))==BIT2);  
#elif IS_NT68870_SERIES && (INPUT_INTERFACE&INPUT_MHL1)
    return ((SC_MCU_IO_CTRL9 & (BIT1|BIT0))==BIT0); 
#elif IS_NT68870_SERIES && (INPUT_INTERFACE&INPUT_MHL3)
    return ((SC_MCU_IO_CTRL7 & (BIT5|BIT4))==BIT4); 
#else
    return FALSE;
#endif
}

BOOL MHL_IsMHLPathEnable(void)
{
#if IS_NT68870_SERIES && ((INPUT_INTERFACE&INPUT_MHL0) || (INPUT_INTERFACE&INPUT_MHL1))
    return (((GetTMDSPHYDATA(_DPPP_PHY0, _TMDS_DPHY_MHL2p0_CTRL))&BIT7)==BIT7);
#elif IS_NT68870_SERIES && ((INPUT_INTERFACE&INPUT_MHL2) || (INPUT_INTERFACE&INPUT_MHL3))
	return (((GetTMDSPHYDATA(_DPPP_PHY1, _TMDS_DPHY_MHL2p0_CTRL))&BIT7)==BIT7);
#else
	return (((GetTMDSPHYDATA(_DPPP_PHY0, _TMDS_DPHY_MHL2p0_CTRL))&BIT7)==BIT7);
#endif
}

#if ENABLE_VBUS_IO_CONTROL == OFF
void MHL_EnableVBus1(void)
{
#if IS_NT68770_SERIES && (INPUT_INTERFACE&INPUT_MHL0)
	UCHAR tmp_reg;
    tmp_reg = SC_MCU_IO_CTRL4 & ~(BIT5|BIT4);
    SC_MCU_IO_CTRL4 = tmp_reg | BIT4;
#elif IS_NT68850_SERIES && (INPUT_INTERFACE&INPUT_MHL0)
	UCHAR tmp_reg;
    tmp_reg = SC_MCU_IO_CTRL5 & ~(BIT5|BIT4);
    SC_MCU_IO_CTRL5 = tmp_reg | BIT5;
#elif IS_NT68790_SERIES && (INPUT_INTERFACE&INPUT_MHL0)
	UCHAR tmp_reg;
    tmp_reg = SC_MCU_IO_CTRL4 & ~(BIT5|BIT4);
    SC_MCU_IO_CTRL4 = tmp_reg | BIT4;
#elif IS_NT68810_SERIES && (INPUT_INTERFACE&INPUT_MHL0)
    UCHAR tmp_reg;
    tmp_reg = SC_MCU_IO_CTRL4 & ~(BIT3|BIT2);
    SC_MCU_IO_CTRL4 = tmp_reg | BIT2;
#elif IS_NT68870_SERIES && (INPUT_INTERFACE&INPUT_MHL0)
	UCHAR tmp_reg;
	tmp_reg = SC_MCU_IO_CTRL5 & ~(BIT3|BIT2);
	SC_MCU_IO_CTRL5 = tmp_reg | BIT2;
#elif IS_NT68870_SERIES && (INPUT_INTERFACE&INPUT_MHL2)
	UCHAR tmp_reg;
	tmp_reg = SC_MCU_IO_CTRL7 & ~(BIT3|BIT2);
	SC_MCU_IO_CTRL7 = tmp_reg | BIT2;	
#endif
}
#endif

#if 0
void MHL_DisableVBus1(void)
{
#if IS_NT68770_SERIES && (INPUT_INTERFACE&INPUT_MHL0)
    SC_MCU_IO_CTRL4 &= ~(BIT5|BIT4);
#elif IS_NT68850_SERIES && (INPUT_INTERFACE&INPUT_MHL0)
    SC_MCU_IO_CTRL5 &= ~(BIT5|BIT4);
#endif
}
#endif

#if ENABLE_VBUS_IO_CONTROL == ON
void MHL_Set_VBus1_IO_On(void)
{
#if IS_NT68770_SERIES && (INPUT_INTERFACE&INPUT_MHL0)
    #if SET_IO_VBUS_ACTIVE==HIGH
        PortC |= BIT2;
    #else
        PortC &= ~BIT2;
    #endif
#elif IS_NT68850_SERIES && (INPUT_INTERFACE&INPUT_MHL0)
    #if SET_IO_VBUS_ACTIVE==HIGH
        PortC |= BIT5;
    #else
        PortC &= ~BIT5;
    #endif
#elif IS_NT68870_SERIES && (INPUT_INTERFACE&INPUT_MHL0)
    #if SET_IO_VBUS_ACTIVE==HIGH
        PortC |= BIT1;
    #else
        PortC &= ~BIT1;
    #endif	
#elif IS_NT68870_SERIES && (INPUT_INTERFACE&INPUT_MHL2)
    #if SET_IO_VBUS_ACTIVE==HIGH
        PortD |= BIT2;
    #else
        PortD &= ~BIT2;
    #endif	
#endif
}
void MHL_Set_VBus1_IO_Off(void)
{
#if IS_NT68770_SERIES && (INPUT_INTERFACE&INPUT_MHL0)
    #if SET_IO_VBUS_ACTIVE==HIGH
        PortC &= ~BIT2;
    #else
        PortC |= BIT2;
    #endif
#elif IS_NT68850_SERIES && (INPUT_INTERFACE&INPUT_MHL0)
    #if SET_IO_VBUS_ACTIVE==HIGH
        PortC &= ~BIT5;
    #else
        PortC |= BIT5;
    #endif
#elif IS_NT68870_SERIES && (INPUT_INTERFACE&INPUT_MHL0)
    #if SET_IO_VBUS_ACTIVE==HIGH
        PortC &= ~BIT1;
    #else
        PortC |= BIT1;
    #endif
#elif IS_NT68870_SERIES && (INPUT_INTERFACE&INPUT_MHL2)
    #if SET_IO_VBUS_ACTIVE==HIGH
        PortD&= ~BIT2;
    #else
        PortD |= BIT2;
    #endif		
#endif
}
#endif

#if ENABLE_VBUS_IO_CONTROL == OFF
void MHL_EnableVBus2(void)
{
#if IS_NT68770_SERIES && (INPUT_INTERFACE&INPUT_MHL1)
UCHAR tmp_reg;
    tmp_reg = SC_MCU_IO_CTRL4 & ~(BIT3|BIT2);
    SC_MCU_IO_CTRL4 = tmp_reg | BIT2;
#elif IS_NT68790_SERIES && (INPUT_INTERFACE&INPUT_MHL1)
UCHAR tmp_reg;
    tmp_reg = SC_MCU_IO_CTRL4 & ~(BIT3|BIT2);
    SC_MCU_IO_CTRL4 = tmp_reg | BIT2;
#elif IS_NT68810_SERIES && (INPUT_INTERFACE&INPUT_MHL1)
UCHAR tmp_reg;
    tmp_reg = SC_MCU_IO_CTRL4 & ~(BIT5|BIT4);
    SC_MCU_IO_CTRL4 = tmp_reg | BIT4;
#elif IS_NT68870_SERIES && (INPUT_INTERFACE&INPUT_MHL1)
	UCHAR tmp_reg;
	tmp_reg = SC_MCU_IO_CTRL5 & ~(BIT5|BIT4);
	SC_MCU_IO_CTRL5 = tmp_reg | BIT4;
#elif IS_NT68870_SERIES && (INPUT_INTERFACE&INPUT_MHL3)
	UCHAR tmp_reg;
	tmp_reg = SC_MCU_IO_CTRL7 & ~(BIT1|BIT0);
	SC_MCU_IO_CTRL7 = tmp_reg | BIT0;		
#endif
}
#endif

#if 0
void MHL_DisableVBus2(void)
{
#if IS_NT68770_SERIES && (INPUT_INTERFACE&INPUT_MHL1)
    SC_MCU_IO_CTRL4 &= ~(BIT3|BIT2);
#endif
}
#endif

#if ENABLE_VBUS_IO_CONTROL == ON
void MHL_Set_VBus2_IO_On(void)
{
#if IS_NT68770_SERIES && (INPUT_INTERFACE&INPUT_MHL1)
    #if SET_IO_VBUS_ACTIVE==HIGH
        PortC |= BIT3;
    #else
        PortC &= ~BIT3;
    #endif
#endif
#if IS_NT68870_SERIES && (INPUT_INTERFACE&INPUT_MHL1)
    #if SET_IO_VBUS_ACTIVE==HIGH
        PortC |= BIT1;
    #else
        PortC &= ~BIT1;
    #endif
#endif
}
void MHL_Set_VBus2_IO_Off(void)
{
#if IS_NT68770_SERIES && (INPUT_INTERFACE&INPUT_MHL1)
    #if SET_IO_VBUS_ACTIVE==HIGH
        PortC &= ~BIT3;
    #else
        PortC |= BIT3;
    #endif
#endif
#if IS_NT68870_SERIES && (INPUT_INTERFACE&INPUT_MHL1)
    #if SET_IO_VBUS_ACTIVE==HIGH
        PortC &= ~BIT1;
    #else
        PortC |= BIT1;
    #endif
#endif
}
#endif

void ClearCdsenseFlag(void)
{
    ucCdsenseFlag = 0x00;
}
BOOL MHLSetInterface(UCHAR interface)
{
#if 0//(INPUT_INTERFACE&INPUT_MHL_MASK)
    static UCHAR ucCdsenseFlag = 0x00;
#endif
#if (INPUT_INTERFACE&INPUT_MHL0)
    if (interface == DIGITAL_INPUT0) {
        //if (IsMHL0CableConnect()) {
        if (MHL_Is_CDSense1_IO_HIGH()) {			
            if ((ucCdsenseFlag&BIT0)==0) {            
                SC_SetBitDPppPHY(_DPPP_PHY0, _TMDS_DPHY_MHL2p0_CTRL, BIT7, TRUE); 
                ucCdsenseFlag |= BIT0;
                //SC_MHL_CTRL_2E0 |= BIT7;
                if ( MHL_IsPackedPixelMode(MHL_CBUS_CH1) ) {
                    SC_DISPLAY_CHANNEL &= ~BIT6; //get correct PHY clock 0x016 after set 0x159.6=0
                }
                return TRUE;                
            }
        }
        else {
            if (ucCdsenseFlag&BIT0) {
                SC_SetBitDPppPHY(_DPPP_PHY0, _TMDS_DPHY_MHL2p0_CTRL, BIT7, FALSE);
                ucCdsenseFlag &= ~BIT0;            
                //SC_MHL_CTRL_2E0 = 0x00;    
            }
            if (MHL_IsPackedPixelMode(MHL_CBUS_CH1)) {
                MHLPackedPixelMode(MHL_CBUS_CH1, FALSE);
            }
        }
    }
#endif
#if (INPUT_INTERFACE&INPUT_MHL2)
    if (interface == DIGITAL_INPUT2) {
        //if (IsMHL0CableConnect()) {
        if (MHL_Is_CDSense1_IO_HIGH()) {			
            if ((ucCdsenseFlag&BIT0)==0) {            
                SC_SetBitDPppPHY(_DPPP_PHY1, _TMDS_DPHY_MHL2p0_CTRL, BIT7, TRUE); 
                ucCdsenseFlag |= BIT0;
                //SC_MHL_CTRL_2E0 |= BIT7;
                if ( MHL_IsPackedPixelMode(MHL_CBUS_CH1) ) {
                    SC_DISPLAY_CHANNEL &= ~BIT6; //get correct PHY clock 0x016 after set 0x159.6=0
                }
                return TRUE;                
            }
        }
        else {
            if (ucCdsenseFlag&BIT0) {
                SC_SetBitDPppPHY(_DPPP_PHY1, _TMDS_DPHY_MHL2p0_CTRL, BIT7, FALSE);
                ucCdsenseFlag &= ~BIT0;            
                //SC_MHL_CTRL_2E0 = 0x00;   
            }
            if (MHL_IsPackedPixelMode(MHL_CBUS_CH1)) {
                MHLPackedPixelMode(MHL_CBUS_CH1, FALSE);
            }
        }
    }
#endif

#if (INPUT_INTERFACE&INPUT_MHL1)
    if (interface == DIGITAL_INPUT1) {
        //if (IsMHL1CableConnect()) {
        if (MHL_Is_CDSense2_IO_HIGH()) {			        
            if ((ucCdsenseFlag&BIT0)==0) {
                SC_SetBitDPppPHY(_DPPP_PHY0, _TMDS_DPHY_MHL2p0_CTRL, BIT7, TRUE);
                ucCdsenseFlag |= BIT0;    
                //SC_MHL_CTRL_2E0 |= BIT7;
                if ( MHL_IsPackedPixelMode(MHL_CBUS_CH2) ) {
                    SC_DISPLAY_CHANNEL &= ~BIT6; //get correct PHY clock 0x016 after set 0x159.6=0
                }
                return TRUE;            
            }
        }
        else {
            if (ucCdsenseFlag&BIT0) {
                SC_SetBitDPppPHY(_DPPP_PHY0, _TMDS_DPHY_MHL2p0_CTRL, BIT7, FALSE);
                ucCdsenseFlag &= ~BIT0;    
                //SC_MHL_CTRL_2E0 = 0x00;        
            }
            if (MHL_IsPackedPixelMode(MHL_CBUS_CH2)) {
                MHLPackedPixelMode(MHL_CBUS_CH2, FALSE);
            }
        }
    }
#endif
#if (INPUT_INTERFACE&INPUT_MHL3)
		if (interface == DIGITAL_INPUT3) {
			//if (IsMHL1CableConnect()) {
			if (MHL_Is_CDSense2_IO_HIGH()) {					
				if ((ucCdsenseFlag&BIT0)==0) {
					SC_SetBitDPppPHY(_DPPP_PHY1, _TMDS_DPHY_MHL2p0_CTRL, BIT7, TRUE);
					ucCdsenseFlag |= BIT0;	  
					//SC_MHL_CTRL_2E0 |= BIT7;
					if ( MHL_IsPackedPixelMode(MHL_CBUS_CH2) ) {
						SC_DISPLAY_CHANNEL &= ~BIT6; //get correct PHY clock 0x016 after set 0x159.6=0
					}
					return TRUE;			
				}
			}
			else {
				if (ucCdsenseFlag&BIT0) {
					SC_SetBitDPppPHY(_DPPP_PHY1, _TMDS_DPHY_MHL2p0_CTRL, BIT7, FALSE);
					ucCdsenseFlag &= ~BIT0;    
					//SC_MHL_CTRL_2E0 = 0x00;		 
				}
				if (MHL_IsPackedPixelMode(MHL_CBUS_CH2)) {
					MHLPackedPixelMode(MHL_CBUS_CH2, FALSE);
				}
			}
		}
#endif

    return FALSE;            
}

void MHLPackedPixelMode(UCHAR channel, BOOL On)
{
    if ( On ) {
        if (channel == MHL_CBUS_CH1 || channel == MHL_CBUS_CH2) {
		#if (INPUT_INTERFACE&INPUT_MHL0) || (INPUT_INTERFACE&INPUT_MHL1)            
            SC_SetBitDPppPHY(_DPPP_PHY0, _TMDS_DPHY_MHL2p0_CTRL, BIT6, TRUE);
		#elif (INPUT_INTERFACE&INPUT_MHL2) || (INPUT_INTERFACE&INPUT_MHL3)
            SC_SetBitDPppPHY(_DPPP_PHY1, _TMDS_DPHY_MHL2p0_CTRL, BIT6, TRUE);
		#endif
        }

        SC_VIDEO_HDCP_CTRL |= 0x05;//= 0x15;
        SC_AUDIO_HDCP_CTRL = 0x0A;
        SC_HDMI_DATA_ALIGN |= BIT0;
    }
    else {
        if (channel == MHL_CBUS_CH1 || channel == MHL_CBUS_CH2) {
		#if (INPUT_INTERFACE&INPUT_MHL0) || (INPUT_INTERFACE&INPUT_MHL1)						
            SC_SetBitDPppPHY(_DPPP_PHY0, _TMDS_DPHY_MHL2p0_CTRL, BIT6, FALSE);
		#elif (INPUT_INTERFACE&INPUT_MHL2) || (INPUT_INTERFACE&INPUT_MHL3)
            SC_SetBitDPppPHY(_DPPP_PHY1, _TMDS_DPHY_MHL2p0_CTRL, BIT6, FALSE);
		#endif
        }

        SC_VIDEO_HDCP_CTRL &= 0xF0;//= 0x00;
        SC_AUDIO_HDCP_CTRL = 0x00;
        SC_HDMI_DATA_ALIGN &= ~BIT0;
    }
}

BOOL MHL_IsPackedPixelMode(UCHAR channel)
{
    if (channel == MHL_CBUS_CH1 || channel == MHL_CBUS_CH2) {
		#if (INPUT_INTERFACE&INPUT_MHL0) || (INPUT_INTERFACE&INPUT_MHL1)			
        return ((GetTMDSPHYDATA(_DPPP_PHY0, _TMDS_DPHY_MHL2p0_CTRL) & (BIT6)) == BIT6);
		#elif (INPUT_INTERFACE&INPUT_MHL2) || (INPUT_INTERFACE&INPUT_MHL3)
		return ((GetTMDSPHYDATA(_DPPP_PHY1, _TMDS_DPHY_MHL2p0_CTRL) & (BIT6)) == BIT6);
		#endif
    }
	
    return FALSE;
}

UCHAR MHLCbusTx(UCHAR type, UCHAR d) using 1
{
    MHL_WaitCBusReady();
    
    bTranCMD = 0;

#if ENABLE_INT_TRANSLATION == ON && ENABLE_HDMI_PRETEST == ON
{
    UCHAR countlag;
    // Change loop-count to 20 (from 10) for 14.7456MHz crystal
    for (countlag = 0;countlag<20;countlag++); //CTS 6.3.6.5, need delay to let 0x280 response abort command send by source, the count value should be larger than 3, its around 60 micro sec.
    
    if ((MHL_GetMSCCmd() || MHL_GetDDCCmd()) && (type == TX_MSC_CMD || type == TX_MSC_DATA)) {//130415_2230_SYS#2
        return FALSE;
    }
}
#endif    

    switch(type) {
    case TX_MSC_CMD:
        SC_CBUS_MSC_CMD = d;
        ucCmdIndex = 0;//index to cMSCCmd
        bCheckTimeout = 0;
        ucCBUSCMDTxBuffer = d;
        break;
    case TX_MSC_DATA:
        SC_CBUS_MSC_DATA = d;
        ucCBUSCMDTxBuffer = 0;
        break;
    case TX_DDC_CMD:
        SC_CBUS_DDC_CMD = d;
        ucCBUSCMDTxBuffer = d;
        break;
    case TX_DDC_DATA:
        SC_CBUS_DDC_DATA = d;
        ucCBUSCMDTxBuffer = 0;
        break;
    }

    return TRUE;
}

BOOL CBUSTxData(UCHAR type, UCHAR d)
{
    UCHAR i = 10;
    BOOL bArbFail = FALSE;    
    do {
#if 0//ENABLE_INT_TRANSLATION == 0
    Sleep(10);
#endif
    MHL_WaitCBusReady();
    bTranCMD = 0;
    if (MHL_GetMSCCmd() || MHL_GetDDCCmd()) {
        return 0;
    }
    if (bCBUSAbort == 0) {//normal
        switch(type) {
        case TX_MSC_CMD:
            SC_CBUS_MSC_CMD = d;
            ucCmdIndex = 0;//index to cMSCCmd
            bCheckTimeout = 0;
            break;
        case TX_MSC_DATA:
            SC_CBUS_MSC_DATA = d;
            break;
        case TX_DDC_CMD:
            SC_CBUS_DDC_CMD = d;
            break;
        case TX_DDC_DATA:
            SC_CBUS_DDC_DATA = d;
            break;
        }
    }
    #if 1//def E_DEBUG
#if ENABLE_INT_TRANSLATION == 0
        Sleep(1);
#endif
        if (bCBusArbFailFlag == TRUE) {
            bCBusArbFailFlag = FALSE;
            i--;
            bArbFail = TRUE;            
        }
        else
    #endif
        {
            i = 0;
            bArbFail = FALSE;            
        }
#if ENABLE_INT_TRANSLATION == 0
    if (bArbFail == TRUE || i != 0) {
        Sleep(10);
        }
#endif    
    } while (i != 0);

    if (bArbFail == TRUE) {
        return FALSE;
    }
    
    return !bCBUSAbort;
}

void MHL_SetCBus1DrvCurrent(void)
{
#if IS_NT68770_SERIES && (INPUT_INTERFACE&INPUT_MHL0)
    PA47_CURR |= 0x03;
#elif IS_NT68850_SERIES && (INPUT_INTERFACE&INPUT_MHL0) 
    PD46_CURR |= 0x0C;
#endif
}

void MHL_SetCBus2DrvCurrent(void)
{
#if IS_NT68770_SERIES && (INPUT_INTERFACE&INPUT_MHL1)
    PA47_CURR |= 0x0C;
#endif
}

void MHL_SetCBus1K(void)
{
 UCHAR ucSCID = GetSCID();
#if IS_NT68770_SERIES
    UCHAR i;
    if (ucSCID >= SCID_770_G && ucSCID <= SCID_770_FINAL) {
        i = SC_CBUS_CONTROL & 0x0F;
        SC_CBUS_CONTROL = i | 0x50;
    }
#elif IS_NT68850_SERIES
    UCHAR i;
    if (ucSCID >= SCID_850_C && ucSCID <= SCID_850_FINAL) {
        i = SC_CBUS_CONTROL & 0x0F;
        SC_CBUS_CONTROL = i | 0x50;
    }
#elif IS_NT68790_SERIES || IS_NT68810_SERIES || IS_NT68870_SERIES
    UCHAR i;
//    if (ucSCID >= SCID_850_C && ucSCID <= SCID_850_FINAL) {
        i = SC_CBUS_CONTROL & 0x0F;
        SC_CBUS_CONTROL = i | 0x50;
//    }
#endif
}

void MHL_EnhanceCompatibility(void)
{
    UCHAR ucSCID = GetSCID();
#if IS_NT68770_SERIES
    // Ignore wake_up criteria
    if (ucSCID >= SCID_770_H && ucSCID <= SCID_770_FINAL) {
        SC_CBUS_DISCOVERY_TIME |= BIT7;
        SC_DISCOVERY2CONN |= BIT7;
    }
#elif IS_NT68850_SERIES
// Ignore wake_up criteria
    if (ucSCID >= SCID_850_C && ucSCID <= SCID_850_FINAL) {
        SC_SINK_WAKE &= ~(BIT5|BIT6);
        SC_SINK_WAKE |= BIT5;
        SC_REJECT_CBUS_DISCOVERY_PULSE_MIN = 0x2A;
        SC_REJECT_CBUS_DISCOVERY_PULSE_MAX = 0x70;
        SC_SINK_WAKE &= ~(BIT5|BIT6);
        SC_SINK_WAKE |= BIT6;
        SC_REJECT_CBUS_DISCOVERY_PULSE_MIN = 0x78;
        SC_REJECT_CBUS_DISCOVERY_PULSE_MAX = 0xFF;
        SC_SINK_WAKE &= ~(BIT5|BIT6);
        SC_WAKE_MODE = 0xd5;    
    }
#elif IS_NT68790_SERIES || IS_NT68810_SERIES || IS_NT68870_SERIES
// Ignore wake_up criteria
//    if (ucSCID >= SCID_850_C && ucSCID <= SCID_850_FINAL) {
        SC_SINK_WAKE &= ~(BIT5|BIT6);
        SC_SINK_WAKE |= BIT5;
        SC_REJECT_CBUS_DISCOVERY_PULSE_MIN = 0x2A;
        SC_REJECT_CBUS_DISCOVERY_PULSE_MAX = 0x70;
        SC_SINK_WAKE &= ~(BIT5|BIT6);
        SC_SINK_WAKE |= BIT6;
        SC_REJECT_CBUS_DISCOVERY_PULSE_MIN = 0x78;
        SC_REJECT_CBUS_DISCOVERY_PULSE_MAX = 0xFF;
        SC_SINK_WAKE &= ~(BIT5|BIT6);
        SC_WAKE_MODE = 0xd5;    
//    }
#endif
}

void MHL_ResetCBus(void)
{
    SC_CBUS_CONTROL |= BIT3;
    SC_CBUS_CONTROL &= ~BIT3;
    SetCbusConnectStatus(MHL_NONE);   
}

void MHL_WaitCBusReady(void)
{
    USHRT uscount = 0;

    while ((SC_CBUS_TRANS_FLAG1 & 0x40) == 0) {//130319_1732_SYS#1
        ResetWDTimer();
        uscount ++;

        if (uscount == 0x8000) {//allion cts 4.3.20.1 CBT-sink Response to Ack with different timings (ucount = min 256 can pass,ucount = 255 fail)
            MHL_ResetCBus();
            break;
        }
    }

}

#if IS_NT68870_SERIES
UCHAR MHL_GetCbusCH()
{
#if (INPUT_INTERFACE & INPUT_MHL0) || (INPUT_INTERFACE & INPUT_MHL1) 
	if (SC_TMDS_PHY_LINK_CTRL_1DE1&BIT0) {
		return MHL_CBUS_CH1;
	}
	else {
		return MHL_CBUS_CH2;
	}	
#elif (INPUT_INTERFACE & INPUT_MHL2) || (INPUT_INTERFACE & INPUT_MHL3)	
	if (SC_TMDS_PHY_LINK_CTRL_1DE1&BIT1) {
		return MHL_CBUS_CH1;
	}
	else {
		return MHL_CBUS_CH2;
	}
#else
	return MHL_CBUS_CH1;
#endif
}	
void MHL_SetCbusCH1() 
{
#if (INPUT_INTERFACE & INPUT_MHL0) || (INPUT_INTERFACE & INPUT_MHL1) 
	SC_TMDS_PHY_LINK_CTRL_1DE1 |= BIT0;
	SC_CBUS_INT_EN = CBUS_INT_MASK;
#elif (INPUT_INTERFACE & INPUT_MHL2) || (INPUT_INTERFACE & INPUT_MHL3)	
	SC_TMDS_PHY_LINK_CTRL_1DE1 |= BIT1;
	SC_CBUS_INT_EN = CBUS_INT_MASK;
#endif	
}
void MHL_SetCbusCH2() 
{
#if (INPUT_INTERFACE & INPUT_MHL0) || (INPUT_INTERFACE & INPUT_MHL1) 
	SC_TMDS_PHY_LINK_CTRL_1DE1 &= ~BIT0; 
    SC_CBUS_INT_EN = CBUS_INT_MASK; 
#elif (INPUT_INTERFACE & INPUT_MHL2) || (INPUT_INTERFACE & INPUT_MHL3)	
	SC_TMDS_PHY_LINK_CTRL_1DE1 &= ~BIT1; 
	SC_CBUS_INT_EN = CBUS_INT_MASK; 
#endif	
}

void MHL_PhyOff(void)
{
    SC_SetBitDPppPHY(_DPPP_PHY0, _TMDS_DPHY_MHL2p0_CTRL, (BIT7|BIT6), FALSE);
    SC_SetBitDPppPHY(_DPPP_PHY1, _TMDS_DPHY_MHL2p0_CTRL, (BIT7|BIT6), FALSE);
}
#endif

#endif
