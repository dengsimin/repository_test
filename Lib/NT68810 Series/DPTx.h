/***********************************************************************/
/*             Novatek MicroElectronics Corp.                          */
/*    2F, No. 3,Innovation Road 1, Science-Based Industrial Park,      */
/*    HsinChu 300,Taiwn, R.O.C.                                        */
/*    TEL:886-3-567-0889       FAX:886-3-577-0132                      */
/*    All Rights Reserved                                              */
/***********************************************************************/
/* DisplayPort Transmit function control										  */
/* Date : 2012/11/21 First version By David Luo / iHome-SC/SA1			  */
/*---------------------------------------------------------------------*/
#ifndef __DPTX_H
#define __DPTX_H

//******************************************************************************
// G L O B A L   D E F I N I T I O N S
//******************************************************************************
#define DPTX_CTS				1		// 0 --> No support DP TX CTS.
#define ENABLE_DPTX_LINK_CTS  OFF
#define ENABLE_DPTX_PHY_CTS OFF
// AUX Command define
#define	NATIVE_AUX_W		0x80		
#define	NATIVE_AUX_R		0x90
#define	I2C_AUX_MOT_W		0x40
#define	I2C_AUX_MOT_R		0x50
#define	I2C_AUX_W			0x00
#define	I2C_AUX_R			0x10
#define	HDCP_SEG				0x06		// Addr 0x68000 ~ 0x68FFF: Reserved for HDCP Specification
#define	DPCP_SEG				0x07		// Addr 0x70000 ~ 0x7FFFF: Reserved for DPCP Specification

#define AUX_ACK				0x00
#define AUX_NACK				0x40
#define AUX_DEFER			0x20

#define DAISY_CH_TRAINING       0x90
#define EDP_CH_TRAINING         0x91
#define DAISY_RESET_CH_TRAINING 0x92
#define CAP_CONFIG_MAIN_DAISY   0xA0
#define CAP_CONFIG_PIP_DAISY    0xA1
#define CAP_CONFIG_MAIN_EDP     0xA2
#define CAP_CONFIG_PIP_EDP      0xA3
#define CHECK_DPCD_DAISY        0xA4
#define CHECK_DPCD_EDP          0xA5
#define CAP_CONFIG_DPTX_DAISY   0xA6
#define CHECK_NEXT_DPCD_DAISY   0xA7
#define CONFIG_DAISY_LINK       0xA8
#define CONFIG_EDP_LINK         0xA9
#define DPRX_CONFIG_MST_MSG     0xB0
#define DPTX_ENABLE_DPTX_HDCP   0xD0
#define SINK_HPD_UNPLUG         0xE0
#define SEND_ID_NUMBER         0xF0
#if ENABLE_DPTX_LINK_CTS == ON
#define AUX_RETRY 5
#else
#define AUX_RETRY 10
#endif
/*
enum  ChannelSelction {
    _MainChannel,
    _PIPChannel,
    _P2Channel,
    _P3Channel,
    _DPTX0Channel,
    _DPTX1Channel,
    _HTX0Channel,
    _HTX1Channel,
};
*/

#define TRAINING_OK				    0x00
#define TRAINING_FAIL			    0x01
#define TRAINING_NORESPONSE			0x02

#define OFF                            0
#define ON                             1
#define DEBUG_DPTX                   OFF

extern void InitOutputMPLL(void);
extern void InitDPTxPHY(void);
extern void InitDPTxLINK(void);
extern void InitDPTxAUX(void);
extern UCHAR DPTxAUXReqWRByte(UCHAR cmd, ULONG Addr, UCHAR d);
extern UCHAR DPTxAUXReqRDByte(UCHAR cmd, ULONG Addr, UCHAR *d);
extern BOOL DPTxAUXReqWRStream(UCHAR cmd, ULONG Addr, char leng, UCHAR * str);
extern BOOL DPTxAUXReqRDStream(UCHAR cmd, ULONG Addr, char leng, UCHAR * str);
extern void DPRxTraining(void);
extern void eDPTraining(void);
extern void InitDPHPD(void);
extern void DPTxHPD(void);
extern void ResetDPTxLINK(void);
BOOL DPRxCheckDPCD() ;

#endif	
