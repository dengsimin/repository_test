/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/
#ifndef __UTILITIES_H__
#define __UTILITIES_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "Typedef.h"

//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
#define Remap100ToAny(a,b) (((ULONG)(a)*(b)+50)/100)
#define Remap100To1023(a)  Remap100ToAny(a,1023)
#define Remap100To800(a)   Remap100ToAny(a,800)
#define Remap100To255(a)   Remap100ToAny(a,255)
#define Remap100To225(a)   Remap100ToAny(a,225)
#define Remap100To200(a)   Remap100ToAny(a,200)
#define Remap100To63(a)    Remap100ToAny(a,63)

#define RemapAnyTo100(a,b) (((ULONG)(a)*100+(b/2))/b)
#define Remap255To100(a)   RemapAnyTo100(a,255)
#define Remap200To100(a)   RemapAnyTo100(a,200)
#define Remap63To100(a)    RemapAnyTo100(a,63)
#define Remap10To100(a)    RemapAnyTo100(a,10)
#define Remap5To100(a)    RemapAnyTo100(a,5)

#define SramDebug(x, y)    { UCHAR xdata *Ptr; \
                             Ptr = x; \
                             *Ptr = y; }



// 20151001 Yung Create for USB Type CC protocol DBG message
/*----------------------------*/
/*  Select Debug Print Level  */
/*----------------------------*/
#define PRN_USBCC               0        /* USB CC Debug Printing */
#define PRN_USBCC_INT           0        /* USB CC Debug Printing */
#define PRN_CCRX_State          0        /* USB CC Debug Printing */
#define PRN_CCTX_State          0        /* USB CC Debug Printing */
#define PRN_USBCC_Error         0        /* USB CC Debug Printing */
#define PRN_DP_Flow             0        /* USB CC Debug Printing */
#define PRN_SYS_Flow            0        /* Source detet Debug Printing */
#define PRN_PE_STATE            0

#define DBGPRN1(LEVEL, MSG)   { \
                                if (LEVEL == 1)\
                                { \
                                printf(MSG); \
                                } \
                             }
#define DBGPRN2(LEVEL, MSG, P1) { \
                                if (LEVEL == 1)\
                                { \
                                printf(MSG, P1); \
                                } \
                             }
#define DBGPRN3(LEVEL, MSG, P1, P2) { \
                                if (LEVEL == 1)\
                                { \
                                printf(MSG, P1, P2); \
                                } \
                             }  
#define DBGPRN4(LEVEL, MSG, P1, P2, P3) { \
                                if (LEVEL == 1)\
                                { \
                                printf(MSG, P1, P2, P3); \
                                } \
                             }  
/*----------------------------*/
/*  Select SRAM Print Level  */
/*----------------------------*/
#define SRD_USBCC_INT                1        /* USB CC SRAM dump data */

#define SDRAMDUMP(LEVEL,Addr,Data){ \
                                if (LEVEL == 1)\
                                { \
                                SramDebug(Addr, Data); \
                                } \



#endif //__UTILITIES_H__
