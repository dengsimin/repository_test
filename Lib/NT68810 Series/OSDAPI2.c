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
// G L O B A L   V A R I A B L E S
//******************************************************************************


//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************



//******************************************************************************
// E X T E R N A L   V A R I A B L E   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// S T A T I C   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************


/**************************************************************************//**
 * Set OSD position on screen.
 * @param x x position of OSD on screen. Step unit is font width.
 * @param y y position of OSD on screen. Step unit is font height.
 ******************************************************************************/
#if !lrd_dis_benq
void OSDAPI_SetPosition(USHRT x, USHRT y)
{
#define OSDPOS_BOUNDRY(a,b,c) ((a < (b * c)) ? 0 : (a - b * c))

    USHRT fw, fh, ow, oh;
    USHRT xy; 
    //printf("OSD position =%x,%x,%x\r\n",(USHRT)x,(USHRT)y,(USHRT)bOSDAdjust);
    if(!bOSDAdjust){ 
        OSDAPI_OSDPowerOn(); 
    }
    
    fw = OSDAPI_GetOSDFontWidth();
    fh = OSDAPI_GetOSDFontHeight();
    ow = OSDAPI_GetOSDWidth();
    oh = OSDAPI_GetOSDHeight();
    x = x/2*2;   
    
    switch(GetOSDPosRot()) {
        //case OSD_POS_ROT_90: // 90
        //    break;
        //case OSD_POS_ROT_180: //180
        //    break;
        case OSD_POS_ROT_270: //270
            xy = UserPanelData.usWidth - OSD_YPOS_TOP_OFFSET - OSD_YPOS_BOTTOM_OFFSET;
            xy = (ULONG) OSDPOS_BOUNDRY(xy, fh, oh) * (OSD_POS_STEPS - y) / OSD_POS_STEPS;
            xy += OSD_YPOS_TOP_OFFSET;
            SC_OSD_HS_LO = (xy & 0x00FF);
            SC_OSD_HS_HI = (xy & 0xFF00) >> 8;
            SC_OSD_HW = ow - 1;

            xy = UserPanelData.usHeight - OSD_XPOS_LEFT_OFFSET - OSD_XPOS_RIGHT_OFFSET;
            xy = (ULONG) OSDPOS_BOUNDRY(xy, fw, ow) * x / OSD_POS_STEPS;
            xy += OSD_XPOS_RIGHT_OFFSET;
            SC_OSD_VS_LO = (xy & 0x00FF);
            SC_OSD_VS_HI = (xy & 0xFF00) >> 8;
            SC_OSD_VH = oh - 1;
            break;
        default:
            xy = UserPanelData.usWidth - OSD_XPOS_LEFT_OFFSET - OSD_XPOS_RIGHT_OFFSET;
            xy = (ULONG) OSDPOS_BOUNDRY(xy, fw, ow) * x / OSD_POS_STEPS;
            xy += OSD_XPOS_LEFT_OFFSET;
            SC_OSD_HS_LO = (xy & 0x00FF);
            SC_OSD_HS_HI = (xy & 0xFF00) >> 8;
            SC_OSD_HW = ow - 1;

            xy = UserPanelData.usHeight - OSD_YPOS_TOP_OFFSET - OSD_YPOS_BOTTOM_OFFSET;
            xy = (ULONG) OSDPOS_BOUNDRY(xy, fh, (oh*(OSDtimes+1))) * (OSD_POS_STEPS - y) / OSD_POS_STEPS;
            xy += OSD_YPOS_TOP_OFFSET;
            SC_OSD_VS_LO = (xy & 0x00FF);
            SC_OSD_VS_HI = (xy & 0xFF00) >> 8;
            SC_OSD_VH = oh - 1;
            break;
    }
    
#if ENABLE_POSTFRC == ON //2012/1/22 v=15hz
    WaitDisVSync();
    WaitDisVSync();
#endif
    WaitDisVSync();  // Always waiting display VSync to insure OSD H/V has been
                     // loaded into scaler.
                     // Jude 2010/10/08
    bOSDAdjust = FALSE;                 
#undef OSDPOS_BOUNDRY
}
#endif
#if 0 //  lrd :“∆∂ØµΩ¡Àcommom
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
#endif

#if ENABLE_OSD_ROTATION == ON
#if !lrd_dis_benq
/**************************************************************************//**
 * Rotate selected OSD window.
 * @param id Window ID.
 * @param rot Rotation degree.
 ******************************************************************************/
void OSDAPI_RotateOSDWin(OSDWindow id, OSDPosRotation rot)
{
    USHRT sx, sy, ex, ey, tmp;
    UCHAR dir;
    OSDPosRotation prev_rot;
    OSDWinDegree degree;

    if (id > OSD_WINDOW8) {
        return;
    }

    OSDAPI_SelOSDWin(id);

    tmp = (USHRT)SC_OSD_WIN_HOR_HI;
    sx = ((tmp & 0x0F) << 8) + SC_OSD_WIN_HOR_START_LO;
    ex = ((tmp & 0xF0) << 4) + SC_OSD_WIN_HOR_END_LO;
    tmp = (USHRT)SC_OSD_WIN_VER_HI;
    sy = ((tmp & 0x0F) << 8) + SC_OSD_WIN_VER_START_LO;
    ey = ((tmp & 0xF0) << 4) + SC_OSD_WIN_VER_END_LO;

    prev_rot = GetOSDWinRotStatus(id);
    degree = (NUM_OSD_WIN_DEGREE + rot - prev_rot) % NUM_OSD_WIN_DEGREE;

    if ((prev_rot == OSD_POS_ROT_90) || (prev_rot == OSD_POS_ROT_270)) {
        dir = TRUE;
    }
    else {
        dir = FALSE;
    }
    OSDAPI_RotateOSDWinPosition(sx, sy, ex, ey, degree, dir);

    if ((degree == OSD_WIN_DEGREE_90) || (degree == OSD_WIN_DEGREE_270)) {
        dir = !(SC_OSD_WIN_GRADIENT_CTRL & BIT4);
        SC_OSD_WIN_GRADIENT_CTRL &= ~BIT4;
        SC_OSD_WIN_GRADIENT_CTRL |= (dir << 4);
    }

//    SC_OSD_WIN_GRADIENT_RED_COLOR = ((pixel&0x1F) | ((inc&BIT0) << 7));
//    SC_OSD_WIN_GRADIENT_GREEN_COLOR = ((pixel&0x1F) | ((inc&BIT0) << 7));
//    SC_OSD_WIN_GRADIENT_BLUE_COLOR = ((pixel&0x1F) | ((inc&BIT0) << 7));

    SetOSDWinRotStatus(id, rot);
}
#endif
/**************************************************************************//**
 * Set the position of OSD window with rotation.
 * @param sx Start position of x.
 * @param sy Start position of y.
 * @param ex End position of x.
 * @param ey End position of y.
 * @param degree Rotation degree.
 * @param rot TRUE if OSD has been rotated 90/270 degree. Otherwise FALSE.
 ******************************************************************************/
//static void OSDAPI_RotateOSDWinPosition(USHRT sx, USHRT sy, USHRT ex, USHRT ey, OSDWinDegree degree, UCHAR rot)
void OSDAPI_RotateOSDWinPosition(USHRT sx, USHRT sy, USHRT ex, USHRT ey, OSDWinDegree degree, UCHAR rot)
{
    USHRT fw, fh, ow, oh;
    USHRT tmp1, tmp2;
    UCHAR border;

    if (rot) {
        fh = OSDAPI_GetOSDFontWidth();
        fw = OSDAPI_GetOSDFontHeight();
        oh = OSDAPI_GetOSDWidth();
        ow = OSDAPI_GetOSDHeight();        
    }
    else {
        fw = OSDAPI_GetOSDFontWidth();
        fh = OSDAPI_GetOSDFontHeight();
        ow = OSDAPI_GetOSDWidth();
        oh = OSDAPI_GetOSDHeight();
     fh = fh*(OSDtimes+1);
     fw = fw*(OSDtimes+1);
     oh = oh*(OSDtimes+1);
     ow = ow*(OSDtimes+1);    
    }
    //printf("->OSDAPI_RotateOSDWinPosition\r\n");
    //printf("fw=%x,fh=%x,ow=%x,oh=%x,OSDtimes=%x\r\n",(USHRT)fw,(USHRT)fh,(USHRT)ow,(USHRT)oh,(USHRT)OSDtimes);
    
    border = 0;
    if (SC_OSD_WIN_ATTRIBUTE & BIT7) {
        border = (SC_OSD_WIN_BEVEL_WIDTH & 0x07) + 1;
    }

    switch (degree) {
        case OSD_WIN_DEGREE_90 :
            tmp1 = sx;
            tmp2 = ex;
            sx = fh * oh - ey;
            if (sx >= border) {
                sx -= border;
            }
            ex = fh * oh - sy - border;
            sy = tmp1;
            ey = tmp2;
            break;
        case OSD_WIN_DEGREE_180 :
            tmp1 = sx;
            tmp2 = ex;
            sx = fw * ow - tmp2;
            if (sx >= border) {
                sx -= border;
            }
            ex = fw * ow - tmp1 - border;
            tmp1 = sy;
            tmp2 = ey;
            sy = fh * oh - tmp2;
            if (sy >= border) {
                sy -= border;
            }
            ey = fh * oh - tmp1 - border;
            break;
        case OSD_WIN_DEGREE_270 :
            tmp1 = sx;
            tmp2 = ex;
            sx = sy;
            ex = ey;
         if((fw * ow) >tmp2)    
                sy = fw * ow - tmp2;
         else
        sy =tmp2 -fw * ow;       
    
            if (sy >= border) {
                sy -= border;
            }
            ey = fw * ow - tmp1 - border;
            break;
        default :
            break;
    }

    SC_OSD_WIN_HOR_START_LO = (UCHAR)sx;
    SC_OSD_WIN_HOR_END_LO = (UCHAR)ex;
    tmp1 = ((sx >> 8) & 0x000F) | ((ex >> 4) & 0x00F0);
    SC_OSD_WIN_HOR_HI = (UCHAR)tmp1;
    SC_OSD_WIN_VER_START_LO = (UCHAR)sy;
    SC_OSD_WIN_VER_END_LO = (UCHAR)ey;
    tmp1 = ((sy >> 8) & 0x000F) | ((ey >> 4) & 0x00F0);
    SC_OSD_WIN_VER_HI = (UCHAR)tmp1;
    
    //printf("->OSDAPI_RotateOSDWinPosition\r\n");
    //printf("->sx=%x,ex=%x,sy=%x,ey=%x\r\n",(USHRT)sx,(USHRT)ex,(USHRT)sy,(USHRT)ey);
    
    WaitDisVSync();
}
#endif //ENABLE_OSD_ROTATION == ON

