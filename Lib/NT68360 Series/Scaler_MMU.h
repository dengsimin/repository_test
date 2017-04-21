/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/

#ifndef __SCALER_MMU_H__
#define __SCALER_MMU_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "ScalerType.h"
#include "Typedef.h"

//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************

//******************************************************************************
// D A T A   T Y P E   D E F I N E S
//******************************************************************************
/*!
 * Data type for MMU fifo mode.
 */
typedef enum _MMU_FIFO_MODE_ {
    MMU_FIFO_OD_POST,
    MMU_FIFO_PRE_POST,
    MMU_FIFO_PRE_OD,
    MMU_FIFO_PRE_OD_POST,
    NUM_MMU_FIFO_MODE
} MMUFIFOMode;

/*!
 * Data type for MMU frame mode.
 */
typedef enum _MMU_FRAME_ADDR_MODE_ {
    MMU_FRAME_ADDR_OD_POST,
    MMU_FRAME_ADDR_PRE_POST,
    MMU_FRAME_ADDR_PRE_OD,
    MMU_FRAME_ADDR_PRE_OD_POST,
    NUM_MMU_FRAME_ADDR_MODE
} MMUFrameAddrMode;

//******************************************************************************
// V A R I A B L E S   P R O T O T Y P E
//******************************************************************************

//******************************************************************************
// F U N C T I O N    P R O T O T Y P E S
//******************************************************************************
void MMUInitialize(void);
void MMUConfigFIFO(MMUFIFOMode mode);
void MMUConfigFrameBufAddr(MMUFrameAddrMode mode);
void MMUPowerOn(void);
void MMUPowerOff(void);
void MMUReset(void);
void MMUErrCorrection(void);

#endif //__SCALER_MMU_H__
