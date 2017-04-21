/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/
#ifndef __OSD_API_IDENT_H__
#define __OSD_API_IDENT_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "OSDType.h"
#include "Typedef.h"
#include "Scaler.h"

//******************************************************************************
// G L O B A L   D E F I N I T I O N S
//******************************************************************************
extern idata USHRT *pIndentFontBase;
extern idata UCHAR *pIndentWidthBase;
extern xdata USHRT uslay1IndentFontIndex ;
extern idata USHRT usIndentFontIndex ;
extern idata UCHAR ucIndentStringLen ;
extern idata UCHAR ucIndentStringLen ;
extern idata UCHAR ucIndentWidth ;
extern xdata USHRT usIndentFontBuffer[18];

#define OSDCOMMONEFONT   123
//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
void OSDAPI_SetIndentWidth(UCHAR width);
UCHAR OSDAPI_GetIndentWidth(void);
void OSDAPI_SetIndentIndex(USHRT index);
#if 1//OSDTYPE != OSD_ID2009 && OSDTYPE != OSD_ID2008&&OSDTYPE != OSD_ID2008_6KEY
USHRT OSDAPI_GetIndentIndex(void);
#endif
//void OSDAPI_SetIndentStringLen(UCHAR len);
void OSDAPI_SetIndentFont(USHRT *pfont, UCHAR *pwidth);
//void OSDAPI_SetIndentString(UCHAR *ptr) small;
void OSDAPI_ShowIndents(BOOL attr, UCHAR x, UCHAR y) small;
//void OSDAPI_ShowIndentString(BOOL attr, UCHAR x, UCHAR y, UCHAR length, UCHAR *ptr) small;
void ShowIndentString(BOOL attr, UCHAR x, UCHAR y, UCHAR len, UCHAR *p);
void InitFontTableByLang(USHRT k,tFontTable *RemoveFontTab);
void OSDAPI_LoadIndentFont(void) small;
#endif //__OSD_API_IDENT_H__
