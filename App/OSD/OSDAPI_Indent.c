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

//******************************************************************************
// G L O B A L   D E F I N I T I O N S
//******************************************************************************

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************
//static idata USHRT *pIndentFontBase;
//static idata UCHAR *pIndentWidthBase;
//static idata USHRT usIndentFontIndex = 0;
//static idata UCHAR ucIndentStringLen = 0;
//static idata UCHAR ucIndentStringLen = 0;
//static idata UCHAR ucIndentWidth = 0;
//static xdata USHRT usIndentFontBuffer[18];

idata USHRT *pIndentFontBase;
idata UCHAR *pIndentWidthBase;
xdata USHRT uslay1IndentFontIndex = 0;
idata USHRT usIndentFontIndex = 0;
idata UCHAR ucIndentStringLen = 0;
idata UCHAR ucIndentWidth = 0;
xdata USHRT usIndentFontBuffer[18];

//******************************************************************************
// S T A T I C   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
//static void OSDAPI_LoadIndentFont(void) small;
void OSDAPI_LoadIndentFont(void) small;

//******************************************************************************
// Prototype:
//  void OSDAPI_SetIndentIndex(USHRT index)
// Parameters:
//  index   : start font index of a indent string
// Return:
//  None
// Purpose:
//  Set start font index of a indent string
// Notes:
//  None
//******************************************************************************
void OSDAPI_SetIndentIndex(USHRT index)
{
    usIndentFontIndex = index;
}

//******************************************************************************
// Prototype:
//  void OSDAPI_SetIndentIndex(USHRT index)
// Parameters:
//  index   : start font index of a indent string
// Return:
//  None
// Purpose:
//  Set start font index of a indent string
// Notes:
//  None
//******************************************************************************
#if LAYER_INDENT_COUNT == ON
USHRT OSDAPI_GetIndentIndex(void)
{
    return usIndentFontIndex;
}
#endif

//******************************************************************************
// Prototype:
//  void OSDAPI_SetIndentIndex(USHRT index)
// Parameters:
//  index   : start font index of a indent string
// Return:
//  None
// Purpose:
//  Set start font index of a indent string
// Notes:
//  None
//******************************************************************************
/*
void OSDAPI_SetIndentStringLen(UCHAR len)
{
    ucIndentStringLen = len;
}
*/

//******************************************************************************
// Prototype:
//  void OSDAPI_SetIndentIndex(USHRT index)
// Parameters:
//  index   : start font index of a indent string
// Return:
//  None
// Purpose:
//  Set start font index of a indent string
// Notes:
//  None
//******************************************************************************
/*
UCHAR OSDAPI_GetIndentStringLen(void)
{
    return ucIndentStringLen;
}
*/

//******************************************************************************
// Prototype:
//  void OSDAPI_SetIndentWidth(UCHAR width)
// Parameters:
//  width   : indent string width
// Return:
//  None
// Purpose:
//  Set indent string width
// Notes:
//  None
//******************************************************************************
void OSDAPI_SetIndentWidth(UCHAR width)
{
    ucIndentWidth = width;
}

//******************************************************************************
// Prototype:
//  void OSDAPI_SetIndentWidth(UCHAR width)
// Parameters:
//  width   : indent string width
// Return:
//  None
// Purpose:
//  Set indent string width
// Notes:
//  None
//******************************************************************************
/*
UCHAR OSDAPI_GetIndentWidth(void)
{
    return ucIndentWidth;
}
*/

//******************************************************************************
// Prototype:
//  void OSDAPI_SetIndentFont(USHRT *pfont, UCHAR *pwidth)
// Parameters:
//  *pfont   : pointer to font table
//  *pwidth  : pointer to font width table
// Return:
//  None
// Purpose:
//  Set indent font table & width table
// Notes:
//  None
//******************************************************************************
void OSDAPI_SetIndentFont(USHRT *pfont, UCHAR *pwidth)
{
    pIndentFontBase = pfont;
    pIndentWidthBase = pwidth;
}

//******************************************************************************
// Prototype:
//  void OSDAPI_LoadIndentFont(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Load run-time-gererated OSD font to OSD SRam in scaler
// Notes:
//  None
//******************************************************************************
void OSDAPI_LoadIndentFont(void) small
{
    UCHAR i,ch,height;

    ResetWDTimer();
    SC_INDEX_CTRL = 0xA0;
    SC_INDEX_ADDR_LO = (UCHAR)usIndentFontIndex; //Index low
    SC_INDEX_ADDR_HI = (UCHAR)(usIndentFontIndex>>8); //Index high

#if ENABLE_OSD_ROTATION == ON
#if 0 // 0 lrd add 
    if ((SC_OSD_CTRL1&BIT7) != 0) {
        UCHAR buffer[27];
        OSDAPI_RotateIdentFont(buffer,usIndentFontBuffer);
        for (i=0; i<27; i++) {
            SC_INDEX_DATA = buffer[i];
        }        
    }
    else
#else
if ((SC_OSD_CTRL1&BIT7) != 0) {
	OSDAPI_RotateIdentFont(usIndentFontBuffer);    
}
else 
#endif
#endif //ENABLE_OSD_ROTATION == ON
    {
        height = OSDAPI_GetOSDFontHeight();
        for (i=0; i<height; i++) {
            usIndentFontBuffer[i] >>= 4;
            SC_INDEX_DATA = (UCHAR)usIndentFontBuffer[i]; //1'st byte
            ch = (UCHAR)(usIndentFontBuffer[i]>>8) & 0x0F;
            i++;
            ch |= ((UCHAR)usIndentFontBuffer[i] & 0xF0);
            SC_INDEX_DATA = ch; //2'nd byte
            ch = (UCHAR)((usIndentFontBuffer[i]>>8) & 0x00FF);
            SC_INDEX_DATA = ch; //3'th byte
        }
    }
    usIndentFontIndex++;
    ucIndentStringLen++;
    ResetWDTimer();
}

//******************************************************************************
// Prototype: 
// static void InitFontTableByLang(tFontTable *table)
// Parameters:
// Return:
// Purpose:
// Notes:
//  None
//******************************************************************************
void InitFontTableByLang(USHRT k,tFontTable *RemoveFontTab)
{
      if (UserData.ucLanguage == OSDLANG_CHINESE_T ) {
         if(bSelectTable == OSDFontTble1){
             InitFont_TC_Table1();
          }
          else{
             InitFont_TC_Table2();
          }
          RemoveFontTab->head = 0;
          RemoveFontTab->tail = 0;
     }
     else if (UserData.ucLanguage == OSDLANG_CHINESE_S) {
         if(bSelectTable == OSDFontTble1){
             InitFont_SC_Table1();
          }
          else{
              InitFont_SC_Table2();
          }
          RemoveFontTab->head = 0;
          RemoveFontTab->tail = 0;
     }
     else if (UserData.ucLanguage == OSDLANG_JAPANESE) {
         if(bSelectTable == OSDFontTble1){
             InitFont_Japan_Table1();
          }
          else{
              InitFont_Japan_Table2();
          }
          RemoveFontTab->head = 0;
          RemoveFontTab->tail = 0;
     }         
     else if(UserData.ucLanguage == OSDLANG_FRENCH && k >= OSDCOMMONEFONT){
         InitFont_Franais();
         RemoveFontTab->head = 0;
         RemoveFontTab->tail = 0;
     }
     else if(UserData.ucLanguage == OSDLANG_GERMAN && k >= OSDCOMMONEFONT){
         InitFont_Deutsch();
         RemoveFontTab->head = 0;
         RemoveFontTab->tail = 0;
     }
     else if(UserData.ucLanguage == OSDLANG_ITALIAN&& k >= OSDCOMMONEFONT){
         InitFont_Italiano();
         RemoveFontTab->head = 0;
         RemoveFontTab->tail = 0;
     }
     else if(UserData.ucLanguage == OSDLANG_SPANISH && k >= OSDCOMMONEFONT){
         InitFont_Espanol();
         RemoveFontTab->head = 0;
         RemoveFontTab->tail = 0;
     }
     
     else if(UserData.ucLanguage == OSDLANG_SPANISH && k >= OSDCOMMONEFONT){
         InitFont_Espanol();
         RemoveFontTab->head = 0;
         RemoveFontTab->tail = 0;
     }        
     else if(UserData.ucLanguage == OSDLANG_POLISH && k >= OSDCOMMONEFONT){
         InitFont_Polski();
         RemoveFontTab->head = 0;
         RemoveFontTab->tail = 0;
     }
     
     else if(UserData.ucLanguage == OSDLANG_CZECH && k >= OSDCOMMONEFONT){
         InitFont_Cesky();
         RemoveFontTab->head = 0;
         RemoveFontTab->tail = 0;
     }
     else if(UserData.ucLanguage == OSDLANG_HUNGARIAN && k >= OSDCOMMONEFONT){
         InitFont_Magyar();
         RemoveFontTab->head = 0;
         RemoveFontTab->tail = 0;
     }
     
     else if(UserData.ucLanguage == OSDLANG_SERBO&& k >= OSDCOMMONEFONT){
         InitFont_SiCG();
         RemoveFontTab->head = 0;
         RemoveFontTab->tail = 0;
     }
     else if(UserData.ucLanguage == OSDLANG_ROMANA && k >= OSDCOMMONEFONT){
         InitFont_Romana();
         RemoveFontTab->head = 0;
         RemoveFontTab->tail = 0;
     }
    else if(UserData.ucLanguage == OSDLANG_RUSSIAN && k >= OSDCOMMONEFONT){
         InitFont_Pyccknn();
         RemoveFontTab->head = 0;
         RemoveFontTab->tail = 0;
     }
     else if(UserData.ucLanguage == OSDLANG_SWEDISH && k >= OSDCOMMONEFONT){
         InitFont_Svenska();
         RemoveFontTab->head = 0;
         RemoveFontTab->tail = 0;
     }
     else if(UserData.ucLanguage == OSDLANG_PORTUGUESE && k >= OSDCOMMONEFONT){
         InitFont_Portugus();
         RemoveFontTab->head = 0;
         RemoveFontTab->tail = 0;
     }
#if OSDLANG_ARAB != OSDLANG_NONE
     else if(UserData.ucLanguage == OSDLANG_ARAB && k >= OSDCOMMONEFONT){
         InitFont_ARAB();
         RemoveFontTab->head = 0;
         RemoveFontTab->tail = 0;
     }
#endif
    else {
        InitFont_Europe();
        RemoveFontTab->head = 0;
        RemoveFontTab->tail = 0;
    }
    
    RemoveFontTab->height = OSDAPI_GetOSDFontHeight()-(RemoveFontTab->head+RemoveFontTab->tail);
}

//******************************************************************************
// Prototype: 
//  void OSDAPI_ShowIndents(BOOL attr, UCHAR x, UCHAR y) small
// Parameters:
//  attr: set OSD attributes
//  x   : x position on OSD
//  y   : y position on OSD
// Return:
//  None
// Purpose:
//  Show pre-load indent string.
// Notes:
//  None
//******************************************************************************
void OSDAPI_ShowIndents(BOOL attr, UCHAR x, UCHAR y) small
{
    UCHAR i,l;

    UCHAR ch;
    USHRT m,temp;
    ResetWDTimer();

    temp = usIndentFontIndex - ucIndentStringLen;
  
    m = y * OSDAPI_GetOSDWidth() + x;
    
    OSDAPI_GetAttribute(m);//OSD bug
    if (attr == TRUE) {
        SC_INDEX_CTRL = 0x90;
    }
    else {
        SC_INDEX_CTRL = 0x40;
    }
    SC_INDEX_ADDR_LO = (UCHAR)m;
    SC_INDEX_ADDR_HI = (UCHAR)(m >> 8);

    //Alignment
    if (OSDAPI_GetAlignType() == 0) { //Left
        l = 0;
    }
    else if (OSDAPI_GetAlignType() == 1) { //Right
        l = ucIndentWidth - ucIndentStringLen;
    }
    else if (OSDAPI_GetAlignType() == 2) { //Center
        l = (ucIndentWidth - ucIndentStringLen) >> 1;
    }
    //write front space
    for (i=0; i<l; i++) {
        SC_INDEX_DATA = 0x00;
    }
    //write font index
    for (i=0; i<ucIndentStringLen; i++) {
        ch = (UCHAR)(temp + i);
        SC_INDEX_DATA = ch;
    }
    //write back space
    i = l + ucIndentStringLen;
    for (i; i<ucIndentWidth; i++) {
        SC_INDEX_DATA = 0x00;
    }
    ResetWDTimer();
}
#if 0 // 0 lrd add :ÒÆ¶¯µ½ÁËcommom
//******************************************************************************
// Prototype:
//  void OSDAPI_ShowIndentString(BOOL attr, UCHAR x, UCHAR y, UCHAR len, UCHAR *ptr)
// Parameters:
//  attr: set OSD attributes
//  x   : x position on OSD
//  y   : y position on OSD
//  len : length of indent string
//  *ptr  : pointer to font index of indent string
// Return:
//  None
// Purpose:
//  Show indent string
// Notes:
//  None
//******************************************************************************
void ShowIndentString(BOOL attr, UCHAR x, UCHAR y, UCHAR len, UCHAR *p)
{
    UCHAR i,l;
    l = p[0]+1;
    if (l > GLOB_FONTBUF_LEN)
        l = GLOB_FONTBUF_LEN;
    
 //   memset(glob_FontBuff, 0, GLOB_FONTBUF_LEN);
	for(i=0;i < GLOB_FONTBUF_LEN;i++)
	{
		glob_FontBuff[i]= 0;
	}
    for (i=0;i<l;i++){
        glob_FontBuff[i] = p[i];
    }
    
#if OSDLANG_ARAB != OSDLANG_NONE
    if(UserData.ucLanguage == OSDLANG_ARAB 
        && OSDAPI_GetAlignType() == OSD_ALIGN_LEFT
        &&isOSDArabAlignRight()==TRUE){
        OSDAPI_SetAlignType(OSD_ALIGN_RIGHT);
    }

#endif
    OSDAPI_SetIndentWidth(len);
    switch(UserData.ucLanguage)
    {
    default:
        FindTable_Europe(glob_FontBuff);
        break;
    case OSDLANG_CHINESE_T:
        FindTable_TC(glob_FontBuff);
        break;
    case OSDLANG_CHINESE_S:
        FindTable_SC(glob_FontBuff);
        break;
    case OSDLANG_JAPANESE:
        FindTable_Japan(glob_FontBuff);
        break;
    }
    OSDAPI_ShowIndents(attr, x, y);
}
#endif

