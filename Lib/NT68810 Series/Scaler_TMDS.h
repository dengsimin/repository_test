/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/

#ifndef __SCALER_TMDS_H__
#define __SCALER_TMDS_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "ScalerType.h"
#include "Typedef.h"

//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************
#define ENABLE_TMDS_EQ_SEARCH_FLOW ON

//******************************************************************************
// D A T A   T Y P E   D E F I N E S
//******************************************************************************
/*!
 *Data type for f/w-based impedance detection.
 */
typedef struct {
    UCHAR ClkIMP;
    UCHAR DataIMP;
    UCHAR IMPMode;
    UCHAR EQBias;
    UCHAR EQRF;
    UCHAR MaxGoodEye;
    USHRT SumOfEye;
    UCHAR RGBGoodEye[3];
} EyeData;

typedef enum _TMDSEQLevel{
    _TMDSEQ_S0 = 0,
    _TMDSEQ_S1,    
    _TMDSEQ_S2,    
    _TMDSEQ_S3,    
    _Num_TMDSEQ
}TMDSEQLevel;

#define HDMI_NRM 1// HDMI_NRM, <= 340MHz (HDMI1.4/HDMI2.0)
#define HDMI_HSP 2// HDMI_HSP, >340MHz   (HDMI2.0)
#define MHL2_NRM 4// MHL2_NRM, mhl2.0 24-bit mode 
#define MHL2_PPM 8// MHL2_PPM, mhl2.0 pp mode
#define MHL3_1P5G 10// MHL3_1P5G, mhl3.0 1.5G
#define MHL3_3P0G 20// MHL3_3P0G, mhl3.0 3.0G
#define MHL3_6P0G 40// MHL3_6P0G, mhl3.0 6.0G
//******************************************************************************
// V A R I A B L E S   P R O T O T Y P E
//******************************************************************************

//******************************************************************************
// F U N C T I O N    P R O T O T Y P E S
//******************************************************************************
void TMDSInit(UCHAR phyindex);
void TMDS_EnableCKDT(UCHAR phyindex);
void TMDSInitPhy(UCHAR phyindex);
void MHLDPppPHYInit(UCHAR phyindex);
void TMDSImpedanceDetection(void);
BOOL TMDSClockStable(void);
void TMDSBandwidthDetection(UCHAR reset);
USHRT GetDigInputHActive(void);
USHRT GetDigInputVActive(void);
USHRT GetDigInputHActiveImmediate(void);
USHRT GetDigInputVActiveImmediate(void);
#if ENABLE_HDMI == ON
USHRT GetDigInputHTotalImmediate(void);
USHRT GetDigInputVTotalImmediate(void);
#endif
void DVI_PowerOff(void);
void DVI_PowerOn(void);
void AphyPowerOff(bit pd);

void SetDVIPLL(void);
void TMDS_EnableSCDT(void);
USHRT TMDS_GetClock(void);

UCHAR GetTMDSPHYDATA(UCHAR phyindex, USHRT address);
void TMDSClockTraining(UCHAR phyindex, BOOL bForce);
void ClearTMDSTraining(void);
bit IsTMDSLBR(UCHAR phyindex);

void SC_SetByteDPppPHY(UCHAR phyindex, USHRT reg, UCHAR value);
void SC_SetBitDPppPHY(UCHAR phyindex, USHRT reg, UCHAR mask, UCHAR value);
BOOL CheckTMDSVCOValue(void);
BOOL CheckTMDSErrorCounter(void);
BOOL TMDS_IsDualLink(void);
void TMDS_DualLinkDetection(void);
void TMDS_EQSet_Flow(void);
void TMDSDataAlign(UCHAR phyindex);

#endif //__SCALER_TMDS_H__
