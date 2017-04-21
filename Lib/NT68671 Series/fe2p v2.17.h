/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/

#ifndef _FE2P_LIB_H
#define _FE2P_LIB_H

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************

//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************

//******************************************************************************
// D A T A   T Y P E   D E F I N E S
//******************************************************************************

//******************************************************************************
// V A R I A B L E S   P R O T O T Y P E
//******************************************************************************

//******************************************************************************
// F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
void Fe2p_WriteEnable(void);
void Fe2p_SectorErase(USHRT Sector, UCHAR ucProtectFlag);
void Fe2p_ByteWrite(USHRT Ptr, UCHAR Data, UCHAR ucProtectFlag);
void Fe2p_PageWrite(USHRT Faddr, USHRT Saddr, UCHAR Length, UCHAR ucProtectFlag);
void Fe2p_ByteRead(USHRT Ptr,UCHAR *Data);
void Fe2p_PageRead(USHRT Ptr,UCHAR *Data, USHRT Length);
UCHAR Fe2p_Init(UCHAR ucProtectFlag);
void Fe2p_SetProtect(UCHAR ucProtectFlag);

#endif
