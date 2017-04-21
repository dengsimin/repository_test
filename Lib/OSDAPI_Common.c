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
// M A C R O   D E F I N I T I O N S
//******************************************************************************

//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************

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


/**************************************************************************//**
 * Show string at (x,y) on OSD.
 * @param attr Set OSD attributes at font(x,y).
 * @param x x position of string on OSD.
 * @param y y position of string on OSD.
 * @param len Number of characters of the string.
 * @param pstr Point to a list of font index.
 ******************************************************************************/
void OSDAPI_WriteXYString(BOOL attr, UCHAR x, UCHAR y, UCHAR len, UCHAR *pstr)
{
    UCHAR i;
    USHRT m;

    ResetWDTimer();
    m = (USHRT) y * (OSDAPI_GetOSDWidth()) + x;

    if (attr == TRUE) {
        SC_INDEX_CTRL = 0x90;
    }
    else {
        SC_INDEX_CTRL = 0x40;
    }
    SC_INDEX_ADDR_LO = (UCHAR) m;
    SC_INDEX_ADDR_HI = (UCHAR)(m >> 8);

    for (i = 0; i < len; i++) {
        SC_INDEX_DATA = pstr[i];//0xe3,
    }
    ResetWDTimer();
}


//******************************************************************************
// Prototype: 
//  void OSDAPI_SetIndentString(UCHAR *ptr) small
// Parameters:
//  *ptr  : pointer to font index of indent string
// Return:
//  None
// Purpose:
//  Pre-load font data of indent string in scaler.
// Notes:
//  None
//******************************************************************************
void OSDAPI_SetIndentString(UCHAR *ptr) small
{
    UCHAR i, l, w, Row, wd_point, height;
    USHRT tmp_state;
    USHRT m,k;//k type AOC ID2009
    tFontTable LoadFontTable;
    ResetWDTimer();
    tmp_state=GetOSDState();

    ucIndentStringLen = 0;
    //string width
    m = 0;
    l = ptr[0] + 1;
    for (i=1; i<l; i++) {
        k = ptr[i];// - 0x20; offset

    //== ======== AOC ID2009 ====================================
        if (Custom_System.bForceLanguage == TRUE) {
            InitFont_Europe();
        }
        else {
            InitFontTableByLang(k,&LoadFontTable);
            if(UserData.ucLanguage == OSDLANG_JAPANESE) {
            }
            else if(UserData.ucLanguage == OSDLANG_CHINESE_T) {
            }
            else if(UserData.ucLanguage == OSDLANG_CHINESE_S) {
            }
            else{
                if( k >= OSDCOMMONEFONT ) {
                    k -= OSDCOMMONEFONT;
                }
            }
            }

        m += pIndentWidthBase[k];
    }
    //Alignment
    if (OSDAPI_GetAlignType() == 0) { //Left
        wd_point = 0;
    }
    else if (OSDAPI_GetAlignType() == 1) { //Right
        m = (USHRT)ucIndentWidth * 12 - m;
        wd_point = m % 12;
    }
    else if (OSDAPI_GetAlignType() == 2) { //Center
        m = (USHRT)ucIndentWidth * 12 - m;
        k = m / 12;
        wd_point = m % 12;
        if ((k & BIT0) != 0) {
            wd_point += 12;
        }
        wd_point >>= 1;
    }

    height = OSDAPI_GetOSDFontHeight();
    for (Row=0; Row<height; Row++) {
        usIndentFontBuffer[Row] = 0;
    }
    //write font
    for (i=1; i<l; i++) {
        k = ptr[i];// - 0x20;        //get font and font width

//== ======== AOC ID2009 ====================================
        if (Custom_System.bForceLanguage == FALSE)
        {
            InitFontTableByLang(k,&LoadFontTable);
                    
             if (UserData.ucLanguage == OSDLANG_CHINESE_T ) {
                if(bSelectTable == OSDFontTble1){
                    InitFont_TC_Table1();
                 }
                 else{
                    InitFont_TC_Table2();
                 }
            }
            else if (UserData.ucLanguage == OSDLANG_CHINESE_S) {
                if(bSelectTable == OSDFontTble1){
                    InitFont_SC_Table1();
                 }
                 else{
                     InitFont_SC_Table2();
                 }
            }
            else if (UserData.ucLanguage == OSDLANG_JAPANESE) {
                if(bSelectTable == OSDFontTble1){
                    InitFont_Japan_Table1();
                 }
                 else{
                     InitFont_Japan_Table2();
                 }
            }
            else if(UserData.ucLanguage == OSDLANG_FRENCH && k >= OSDCOMMONEFONT){
                InitFont_Franais();
            }
            else if(UserData.ucLanguage == OSDLANG_GERMAN && k >= OSDCOMMONEFONT){
                InitFont_Deutsch();
            }
            else if(UserData.ucLanguage == OSDLANG_ITALIAN&& k >= OSDCOMMONEFONT){
                InitFont_Italiano();
            }
            else if(UserData.ucLanguage == OSDLANG_SPANISH && k >= OSDCOMMONEFONT){
                InitFont_Espanol();
            }
            
            else if(UserData.ucLanguage == OSDLANG_SPANISH && k >= OSDCOMMONEFONT){
                InitFont_Espanol();
            }        
            else if(UserData.ucLanguage == OSDLANG_POLISH && k >= OSDCOMMONEFONT){
                InitFont_Polski();
            }
            
            else if(UserData.ucLanguage == OSDLANG_CZECH && k >= OSDCOMMONEFONT){
                InitFont_Cesky();
            }
            else if(UserData.ucLanguage == OSDLANG_HUNGARIAN && k >= OSDCOMMONEFONT){
                InitFont_Magyar();
            }
            
            else if(UserData.ucLanguage == OSDLANG_SERBO&& k >= OSDCOMMONEFONT){
                InitFont_SiCG();
            }
            else if(UserData.ucLanguage == OSDLANG_ROMANA && k >= OSDCOMMONEFONT){
                InitFont_Romana();
            }
           else if(UserData.ucLanguage == OSDLANG_RUSSIAN && k >= OSDCOMMONEFONT){
                InitFont_Pyccknn();
            }
            else if(UserData.ucLanguage == OSDLANG_SWEDISH && k >= OSDCOMMONEFONT){
                InitFont_Svenska();
            }
            else if(UserData.ucLanguage == OSDLANG_PORTUGUESE && k >= OSDCOMMONEFONT){
                InitFont_Portugus();
            }
#if OSDLANG_ARAB != OSDLANG_NONE
            else if(UserData.ucLanguage == OSDLANG_ARAB&& k >= OSDCOMMONEFONT){
                InitFont_ARAB();
            }    
#endif        
            else {    
                InitFont_Europe();
            }
            
            if(UserData.ucLanguage == OSDLANG_JAPANESE) {
            }
            else if(UserData.ucLanguage == OSDLANG_CHINESE_T) {
            }
            else if(UserData.ucLanguage == OSDLANG_CHINESE_S) {
            }
            else{
              if( k >= OSDCOMMONEFONT ) {
                  k -= OSDCOMMONEFONT;
              }
            }            
        }
        else{
              InitFontTableByLang(k,&LoadFontTable);
        }
//=======================================================
    
        w = pIndentWidthBase[k]; //get font font width

        m = k * (LoadFontTable.height);

        if (wd_point == 0) {
            for (Row=0; Row<LoadFontTable.height; Row++) {
                  usIndentFontBuffer[Row+LoadFontTable.head] = pIndentFontBase[m+Row];
            }
        }
        else {
            for (Row=0; Row<LoadFontTable.height; Row++) {
                  usIndentFontBuffer[Row+LoadFontTable.head] |= (pIndentFontBase[m+Row] >> wd_point);
            }
        }
        wd_point += w;
        do {

            if (wd_point == 12) { //buffer full?
                OSDAPI_LoadIndentFont();
                wd_point = 0;
            }
            else if (wd_point> 12) {
                OSDAPI_LoadIndentFont();
                wd_point -= 12;
                for (Row=0; Row<LoadFontTable.height; Row++) {
                        usIndentFontBuffer[Row+LoadFontTable.head] =
                        (pIndentFontBase[m+Row] << (w - wd_point));
                }
            }
        }while(wd_point>11);
    }
    ResetWDTimer();
    //write back space
    if (wd_point != 0) {
        OSDAPI_LoadIndentFont();
        wd_point = 0;
    }
}


/**************************************************************************//**
 * Load OSD palette to scaler sram
 * @param pbuf Pointer to OSD palette data.
 ******************************************************************************/

void OSDAPI_LoadPalette(OSDPaletteTable *pbuf)
{
    idata USHRT i,l;

    ResetWDTimer();
//#if IS_NT68770_SERIES || IS_NT68850_SERIES || IS_NT68655_SERIES || IS_NT68150_SERIES || IS_NT68790_SERIES || IS_NT68658_SERIES
#if IS_NT68770_SERIES_LATER && !IS_NT68661_SERIES
    OSDAPI_OSDPowerOn();
#endif
    l = pbuf->usTableSize;
    SC_INDEX_CTRL = 0xD0;
    SC_INDEX_ADDR_LO = pbuf->usOffset & 0x00FF;
    SC_INDEX_ADDR_HI = (pbuf->usOffset & 0xFF00) >> 8;
    for (i = 0; i < l; i++) {
        SC_INDEX_DATA = pbuf->ucTable[i];
    }
    ResetWDTimer();
}

/**************************************************************************//**
 * Load OSD font to scaler sram
 * @param type OSD_FONT_COMPRESSED if font is compressed else OSD_FONT_NORMAL.
 * @param pbuf Pointer to OSD font data.
 ******************************************************************************/
void OSDAPI_LoadFont(OSDFontType type, OSDFontTable *pbuf)
{
    UCHAR temp, l;
    idata USHRT i,len;

    ResetWDTimer();
//#if IS_NT68770_SERIES || IS_NT68850_SERIES || IS_NT68655_SERIES || IS_NT68150_SERIES || IS_NT68790_SERIES || IS_NT68658_SERIES
#if IS_NT68770_SERIES_LATER && !IS_NT68661_SERIES
    OSDAPI_OSDPowerOn();
#endif
    len = pbuf->usTableSize;
    SC_INDEX_CTRL = pbuf->ucFontBits & 0xF0;
    SC_INDEX_ADDR_LO = pbuf->usOffset & 0x00FF;
    SC_INDEX_ADDR_HI = (pbuf->usOffset & 0xFF00) >> 8;

    if (type == OSD_FONT_NORMAL) {
        for (i = 0; i < len; i++) {
            SC_INDEX_DATA = pbuf->ucTable[i];
        }
    }
    else {
        for (i=0; i<len; i++) {
            temp = pbuf->ucTable[i];
            if ((temp == 0x00) || (temp == 0xFF)) {
                i++;
                l = pbuf->ucTable[i]; //length
                do {
                    SC_INDEX_DATA = temp;
                    l--;
                } while (l != 0);
            }
            else {
                SC_INDEX_DATA = temp;
            }
        }
    }
    ResetWDTimer();
}
