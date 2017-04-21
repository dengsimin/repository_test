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

 UCHAR ucMainIconPos[12] = {
// X start position, Y start position
    2, 4,  // Icon1
    2, 6,  // Icon2
    2, 8,  // Icon3
    2,10, // Icon4
    2,12, // Icon4
    2,14, // Icon5
};

// Select Page Icon Tab
UCHAR SPIcon1PosTab[10] = {
    // X Pos, Y Pos
    0, 2,
    1, 2,
    0, 3,
    1, 3,
    2, 3
};
UCHAR SPIcon2PosTab[10] = {
    // X Pos, Y Pos
    0, 6,
    1, 6,
    2, 6,
    0, 7,
    1, 7
};
UCHAR SPIcon3PosTab[10] = {
    // X Pos, Y Pos
    0, 10,
    1, 10,
    2, 10,
    0, 11,
    1, 11
};
UCHAR SPIcon4PosTab[8] = {
    // X Pos, Y Pos
    0, 14,
    1, 14,
    0, 15,
    1, 15,
};
UCHAR SPIcon5PosTab[12] = {
    // X Pos, Y Pos
    0, 18,
    1, 18,
    2, 18,
    0, 19,
    1, 19,
    2, 19,
};

UCHAR *SPIconPosInfoTab[6] = {SPIcon1PosTab, SPIcon2PosTab, SPIcon3PosTab, SPIcon4PosTab, SPIcon5PosTab, SPIcon3PosTab};//ULEric140328
UCHAR SPIconItmNumTab[6] = {5, 5, 5, 4, 6, 5};

UCHAR ucLayer1StringInfoTb[2] = {
    // X start position, Y start position
   5, 5,
};

UCHAR ucLayer2ItmNumTb[6] = {
#if ENABLE_AUTO_POVIT_FUNC == ON
7,
#else
6,
#endif
9,
7,
3,
12,
3,
//11,
//5,
//3,
//0,
};

UCHAR ucLayer2ItemInfoTb[2] = {
    // X start position, Y start position
    19, 5,
};


#if ENABLE_AUTO_POVIT_FUNC == ON
UCHAR ucLayer3MItem1NumTb[7] = {
    0,
    2,
    4,
    0,
    0,
    0,
    0,
};
#else
UCHAR ucLayer3MItem1NumTb[6] = {
    0,
    4,
    0,
    0,
    0,
    0,
};
#endif

UCHAR ucLayer3MItem1InfoTb[2] = {
    // X start position, Y start position
    33, 5,
};

UCHAR ucLayer3MItem2NumTb[9] = {
    0,
    0,
    0,
    5,
    4,
    0,
    0,
    2,
    3,
};

UCHAR ucLayer3MItem2InfoTb[2] = {
    // X start position, Y start position
    33, 5,
};

UCHAR ucLayer3MItem3NumTb[7] = {
    PICTURE_MODE_NUM,
    2,
    0,
    2,
    3,
    2,
    2,
};

UCHAR ucLayer3MItem3InfoTb[2] = {
    // X start position, Y start position
    33, 5,
};

UCHAR ucLayer3MItemAudioNumTb[3] = {
    0,
    2,
    NUM_AUDIOSELECT,
};

UCHAR ucLayer3MItemAudioInfoTb[2] = {
    // X start position, Y start position
    33, 5,
};    
    
UCHAR ucLayer3MItem4NumTb[12] = {
    3,
    10,//ULEric140331 
    10,//ULEric140331
    10,//ULEric140331
    2,
    2,
    2,
    4,
    2,
    4,
    2,
    2,
};

UCHAR ucLayer3MItem4InfoTb[2] = {
    // X start position, Y start position
    33, 5,
};



UCHAR ucLayer4ItemInfoTb[6] = {
    // item count, X start position, Y start position
    17, 47, 5,
    6, 47, 5,
};
UCHAR ucLBLItemInfoTb[3] = {
    4, 47, 5,
};


UCHAR ucLayer3MItemErgoNumTb[3] = {
    2,
    5,
    5,
};

UCHAR ucLayer3MItemErgoInfoTb[2] = {
    // X start position, Y start position
    33, 5,
};

UCHAR *ucLayer3ItmNumTab[6] = {ucLayer3MItem1NumTb, ucLayer3MItem2NumTb, ucLayer3MItem3NumTb, ucLayer3MItemAudioNumTb, ucLayer3MItem4NumTb,ucLayer3MItemErgoNumTb};
UCHAR *ucLayer3PosInfoTab[6] = {ucLayer3MItem1InfoTb, ucLayer3MItem2InfoTb, ucLayer3MItem3InfoTb, ucLayer3MItemAudioInfoTb,ucLayer3MItem4InfoTb,ucLayer3MItemErgoInfoTb};


// TopPage Icon Info
// Auto
UCHAR ucAuto_PosTab[6] = {
    // X, font num
    1, 4,
    1, 4,
    1, 4,
};
// Display
UCHAR ucDisplay_PosTab[6] = {
    // X, font num
    1, 4,
    1, 4,
    1, 4,
};
// Contrast
UCHAR ucContrast_PosTab[6] = {
    // X, font num
    2, 2,
    1, 3,
    2, 2,
};
// Brightness
UCHAR ucBrightness_PosTab[6] = {
    // X, font num
    2, 2,
    1, 3,
    2, 2,
};
// Picture
UCHAR ucPicture_PosTab[6] = {
    // X, font num
    2, 2,
    1, 3,
    1, 3,
};
// Input
UCHAR ucInput_PosTab[6] = {
    // X, font num
    1, 4,
    1, 4,
    1, 4,
};

// Menu
UCHAR ucMenu_PosTab[9] = {
    // X, Y, font num
    1, 13, 4,
    1, 14, 4,
    1, 15, 4,
};

//ULEric140402
//Volume
UCHAR ucVolume_PosTab[6] = {
    // X, font num
    1, 3,
    1, 3,
    1, 3,
};
//Mute
UCHAR ucMute_PosTab[6] = {
    // X, font num
    1, 3,
    1, 3,
    1, 3,
};
//Low Blue Light Mode
UCHAR ucLowBlueLight_PosTab[6] = {
    // X, font num
    1, 4,
    1, 4,
    1, 4,
};
//Smart Reminder
UCHAR ucSmartReminder_PosTab[6] = {
    // X, font num
    1, 3,
    1, 3,
    1, 3,
};

// Exit
UCHAR ucExit_PosTab[9] = {
    // X, Y, font num
    1, 17, 3,
    2, 18, 2,
    1, 19, 3,
};

UCHAR *ucTopPageIconInfoTab[10] = {
    ucPicture_PosTab, 
    ucDisplay_PosTab, 
    ucBrightness_PosTab, 
    ucContrast_PosTab, 
    ucAuto_PosTab , 
    ucInput_PosTab,
    ucVolume_PosTab,
    ucMute_PosTab,
    ucLowBlueLight_PosTab,
    ucSmartReminder_PosTab
};



//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************
#if MD_ENABLE_FUNC_OSD == ON
static code UCHAR ucFuncITMPosTb[] = {
    0, 3,
    0, 5,
    0, 7,
    0, 9,
    0,11,
    0,13,
};
#endif

xdata UCHAR ucMenuType = OSD_SUBMENU_1;
xdata UCHAR ucSubMenuType = 0;
xdata UCHAR ucLayer3MenuType = 0;
xdata UCHAR ucCustomerKeyType = 0;
xdata USHRT usOSDMovingX,usOSDMovingY;
xdata UCHAR ucOSDFlags = 0x00;
BOOL IsPage2 = FALSE;
UCHAR ucMenuAction = 0;
BOOL bSelNum = FALSE;
//BOOL  ClrLayer4Flags  = FALSE;
//******************************************************************************
// E X T E R N A L   V A R I A B L E   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// S T A T I C   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
//ULEric140424
static void OSDShowInputNoticeDialogString(void)
{
    UCHAR buff[20],i,j;
    UCHAR *p;
    code UCHAR JA_MessageInputStr1[] = {2, 129, 130, };
    code UCHAR CT_MessageInputStr1[] = {2, 22, 23, };
    code UCHAR CS_MessageInputStr1[] = {2, 22, 23, };
    code UCHAR *MsgInputTab[] = {
        JA_MessageInputStr1,
        CT_MessageInputStr1,
        CS_MessageInputStr1,
    };    

    if(UserData.ucLanguage<OSDLANG_JAPANESE)
        p = DisplayTab[(OSD_DISPLAY_INPUT*NUM_OSDLANGS)+UserData.ucLanguage];
    else
        p = MsgInputTab[(UserData.ucLanguage - OSDLANG_JAPANESE)];
    
    buff[0] = (*p)+1;
    for(i = 0;i<*p;i++)
    {
        buff[i+1] = *(p+i+1);
    }
    i++;
    buff[i] = ':';
    i++;
    p = InputTab1[(GetInputPortIndex(UserData.ucInputSource)*NUM_OSDLANGS+UserData.ucLanguage)];
    buff[0] = buff[0] + (*p);
    for(j=0;j<*p;j++)
    {
        buff[j+i] = *(p+j+1);
    }    
    ShowIndentString(TRUE, 6, 3, 20, buff);
}
//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
// Prototype:
//  void OSDLangueSlecetReload(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Show main menu page
// Notes:
//  None
//******************************************************************************
void OSDLangueSlecetReload(void)
{
   
   UCHAR i;    
   UCHAR templang;

   templang = UserData.ucLanguage;
   UserData.ucLanguage = Custom_System.ucLanguage;
   bSelectTable = OSDFontTble1;   
   OSDAPI_SetIndentIndex(String_Layer1_Index);
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);   
   OSDShowTitleString();
   
   OSDAPI_SetIndentIndex(String_Layer1_Index + 20);       
   
   for (i=0; i<MAINMENU_ICON_NUM; i++) {
       if (MainMenuStrTab[i*NUM_OSDLANGS+UserData.ucLanguage] != NULL)
        if(i==OSD_MAIN_SYSTEM)//ULEric140401
            ShowIndentString(FALSE, ucLayer1StringInfoTb[0], ucLayer1StringInfoTb[1]+i*2, (INDENT_STRING_MAX_LEN-1), MainMenuStrTab[i*NUM_OSDLANGS+UserData.ucLanguage]);
        else
           ShowIndentString(FALSE, ucLayer1StringInfoTb[0], ucLayer1StringInfoTb[1]+i*2, INDENT_STRING_MAX_LEN, MainMenuStrTab[i*NUM_OSDLANGS+UserData.ucLanguage]);
   }
   
   //fnResetLayerIndentCount(STRING_LAYER_2);
   //OSDAPI_SetIndentIndex(fnGetLayerIndentCount(STRING_LAYER_2));
   OSDAPI_SetIndentIndex(String_Layer2_Index); 
    for (i=0; i<(ucLayer2ItmNumTb[4]>OSD_MAX_LINES ? OSD_MAX_LINES:ucLayer2ItmNumTb[4]); i++) {
        if (Layer2StringTab[4][i*NUM_OSDLANGS+UserData.ucLanguage] != NULL) {
         if(i == OSD_SYS_OSDSET)//ULEric140401
        ShowIndentString(FALSE, ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*2, (INDENT_STRING_MAX_LEN-1), Layer2StringTab[4][i*NUM_OSDLANGS+UserData.ucLanguage]);
         else
            ShowIndentString(FALSE, ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*2, INDENT_STRING_MAX_LEN, Layer2StringTab[4][i*NUM_OSDLANGS+UserData.ucLanguage]);
        }
    }

#if LAYER_INDENT_COUNT == ON
            OSDAPI_SetIndentIndex(OneBitFont_256_end);
            //OSDAPI_SetIndentIndex(fnGetLayerIndentCount(STRING_LAYER_3));
            //printf("Get layer (%d) Indent index = %d\n", (USHRT)STRING_LAYER_3, (USHRT)fnGetLayerIndentCount(STRING_LAYER_3));
#else
            OSDAPI_SetIndentIndex(String_Layer3_Index);
#endif
        for (i=0; i<((ucLayer3ItmNumTab[4][0]>8)? 8:ucLayer3ItmNumTab[4][0]); i++) {
            if (TestTable2[4][0][i] != NULL) {
        if(i==0)
           ShowIndentString(FALSE, *(ucLayer3PosInfoTab[4]+0), *(ucLayer3PosInfoTab[4]+1)+i*2, (INDENT_STRING_MAX_LEN-1),
                 TestTable2[4][0][i*NUM_OSDLANGS+UserData.ucLanguage]);    
        else
                 ShowIndentString(FALSE, *(ucLayer3PosInfoTab[4]+0), *(ucLayer3PosInfoTab[4]+1)+i*2, INDENT_STRING_MAX_LEN,
                TestTable2[4][0][i*NUM_OSDLANGS+UserData.ucLanguage]);
           }
        }

    UserData.ucLanguage = templang;

}


//******************************************************************************
// Prototype:
//  void OSDSelectLayer4Item(UCHAR id ,BOOL isUp)
// Parameters:
//  id     : layer4 item id
// Return:
//  None
// Purpose:
//  Activate Layer4 item id
// Notes:
//  None
//******************************************************************************
void OSDSelectLayer4Item(UCHAR id ,/*BOOL isUp,*/UCHAR ucOSDLay4langState)
{
    UCHAR i;
    //printf("select Layer4Item, id = %d\n", (USHRT)id);
    //printf("ucLayer3MenuType=%d\r\n",(USHRT)ucLayer3MenuType);
       
       UCHAR templang;
    if (ucLayer4ItemInfoTb[ucLayer3MenuType*3] > OSD_MAX_LINES) {
     
             OSDUpdateArrowIcon(ArrowColor1,(id/8),STRING_LAYER_4);//ULEric140401


      if (ucOSDLay4langState == OSD_LAY4_LANG_UPDOWN) {
       templang = UserData.ucLanguage;
          UserData.ucLanguage =  Custom_System.ucLanguage;
      }
#if LAYER_INDENT_COUNT == ON
       fnResetLayerIndentCount(STRING_LAYER_4);
       OSDAPI_SetIndentIndex(fnGetLayerIndentCount(STRING_LAYER_4));
#else
        OSDAPI_SetIndentIndex(String_Layer4_Index);
#endif
        OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
        OSDAPI_SetFontAttr(UnSelectedStringColor1_256);
        bSelectTable = OSDFontTble2;
        //if(id == 0 && isUp == FALSE){
        if((id >= 0 && id <= 7) /*&& isUp == FALSE*/){
            for (i=0; i<(ucLayer4ItemInfoTb[ucLayer3MenuType*3]>8? 8:ucLayer4ItemInfoTb[ucLayer3MenuType*3]); i++) {
              ShowIndentString(TRUE, ucLayer4ItemInfoTb[ucLayer3MenuType*3+1], ucLayer4ItemInfoTb[ucLayer3MenuType*3+2]+i*2, INDENT_STRING_MAX_LEN-2, LanguageTab[i*NUM_OSDLANGS+UserData.ucLanguage]);
            }
        }
        else if((id >= 8 && id <= 15) /*&& isUp == FALSE*/){
            for (i=8; i<16; i++) {
              ShowIndentString(TRUE, ucLayer4ItemInfoTb[ucLayer3MenuType*3+1], ucLayer4ItemInfoTb[ucLayer3MenuType*3+2]+(i-8)*2, INDENT_STRING_MAX_LEN-2, LanguageTab[i*NUM_OSDLANGS+UserData.ucLanguage]);
            }
        }
        else if((id == 16 || id == 17) /*&& isUp == FALSE*/){
              i = 16 ;
              ShowIndentString(TRUE, ucLayer4ItemInfoTb[ucLayer3MenuType*3+1], ucLayer4ItemInfoTb[ucLayer3MenuType*3+2]+(i-16)*2, INDENT_STRING_MAX_LEN-2, LanguageTab[i*NUM_OSDLANGS+UserData.ucLanguage]);
              for (i=1; i<8; i++) {
                  ShowIndentString(TRUE, ucLayer4ItemInfoTb[ucLayer3MenuType*3+1], ucLayer4ItemInfoTb[ucLayer3MenuType*3+2]+i*2, INDENT_STRING_MAX_LEN-2, LanguageTab[17*NUM_OSDLANGS]);
               }        
        }

        /*if(id == 7 && isUp == TRUE){
            for (i=0; i<(ucLayer4ItemInfoTb[ucLayer3MenuType*3]>8? 8:ucLayer4ItemInfoTb[ucLayer3MenuType*3]); i++) {
              ShowIndentString(TRUE, ucLayer4ItemInfoTb[ucLayer3MenuType*3+1], ucLayer4ItemInfoTb[ucLayer3MenuType*3+2]+i*2, INDENT_STRING_MAX_LEN-2, LanguageTab[i*NUM_OSDLANGS+UserData.ucLanguage]);
            }
        }
        else if(id == 15 && isUp == TRUE){
            for (i=8; i<16; i++) {
              ShowIndentString(TRUE, ucLayer4ItemInfoTb[ucLayer3MenuType*3+1], ucLayer4ItemInfoTb[ucLayer3MenuType*3+2]+(i-8)*2, INDENT_STRING_MAX_LEN-2, LanguageTab[i*NUM_OSDLANGS+UserData.ucLanguage]);
            }
        }*/
        bSelectTable = OSDFontTble1;
    if (ucOSDLay4langState == OSD_LAY4_LANG_UPDOWN){    
        if((templang/8) == (id/8))
        {
            OSDAPI_SetFontAttr(UnSelectedStringColor1_256);
            OSDAPI_WriteXYChar(TRUE, ucLayer4ItemInfoTb[1]+11, ucLayer4ItemInfoTb[2]+(templang-((templang/8)*8))*2, Hook_Icon);//ULEric140401   
        }else{
            OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
            OSDAPI_WriteXYChar(TRUE, ucLayer4ItemInfoTb[1]+11, ucLayer4ItemInfoTb[2]+(templang-((templang/8)*8))*2, _SPACE_);//ULEric140401   
        }
    }
    }else{
        // redraw selected string color
        for(i=0;i<ucLayer4ItemInfoTb[ucLayer3MenuType*3];i++)//ULEric140401
            OSDAPI_FillLineAttr(ucLayer4ItemInfoTb[ucLayer3MenuType*3+1], ucLayer4ItemInfoTb[ucLayer3MenuType*3+2]+i*2, INDENT_STRING_MAX_LEN, UnSelectedStringColor1_256);
        
    }
     if(id >= 16){
        id -= 16;
     }
     else if(id >= 8){
        id -= 8;
    }
      if (ucOSDLay4langState == OSD_LAY4_LANG_UPDOWN) {
      UserData.ucLanguage  = templang;
      }

    OSDShowBigWin(OSD_LAYER4_WIN, OSD_WIN_BOARDER_SIZE);      

    // redraw string separater to blue color
    OSDAPI_FillLineAttr(ucLayer4ItemInfoTb[ucLayer3MenuType*3+1], ucLayer4ItemInfoTb[ucLayer3MenuType*3+2]-1+id*2, INDENT_STRING_MAX_LEN, StringSeparaterLineColor2);
    OSDShowSmallWin(id, OSD_LAYER4_WIN);    
    if(id!=7)//ULEric140401
    OSDAPI_FillLineAttr(ucLayer4ItemInfoTb[ucLayer3MenuType*3+1], ucLayer4ItemInfoTb[ucLayer3MenuType*3+2]+1+id*2, INDENT_STRING_MAX_LEN, StringSeparaterLineColor2);

    // redraw selected string color
    OSDAPI_FillLineAttr(ucLayer4ItemInfoTb[ucLayer3MenuType*3+1], ucLayer4ItemInfoTb[ucLayer3MenuType*3+2]+id*2, INDENT_STRING_MAX_LEN, SelectedStringColor_256);
    
    // show selected triangle font
    if (id == ucLayer3MenuType) {
        OSDShowTrianIcon(TRIANGLE_METHOD2, id, STRING_LAYER_4);
    }
    else {
       OSDShowTrianIcon(TRIANGLE_METHOD1, id, STRING_LAYER_4);
    }


}

//******************************************************************************
// Prototype:
//  void OSDUnSelectLayer4Item(UCHAR id, BOOL IsUp)
// Parameters:
//  id     : layer4 item id
//  IsUp : is going up or down
// Return:
//  None
// Purpose:
//  Activate Layer4 item id
// Notes:
//  None
//******************************************************************************
void OSDUnSelectLBLLayer4Item(UCHAR id)
{
    // redraw string to white color
        OSDAPI_FillLineAttr( ucLBLItemInfoTb[1], ucLBLItemInfoTb[2]+id*2, INDENT_STRING_MAX_LEN, UnSelectedStringColor1_256);

        OSDAPI_FillLineAttr(ucLBLItemInfoTb[1], id*2+ucLBLItemInfoTb[2]-1, INDENT_STRING_MAX_LEN, UnSelectedStringColor);
     if(id!=7)
            OSDAPI_FillLineAttr(ucLBLItemInfoTb[1], id*2+ucLBLItemInfoTb[2] +1, INDENT_STRING_MAX_LEN, UnSelectedStringColor);
    // clear window
    OSDAPI_OSDWinOff(OSD_WINDOW1);
}

//******************************************************************************
// Prototype:
//  void OSDSelectLayer4Item(UCHAR id ,BOOL isUp)
// Parameters:
//  id     : layer4 item id
// Return:
//  None
// Purpose:
//  Activate Layer4 item id
// Notes:
//  None
//******************************************************************************
void OSDSelectLBLLayer4Item(UCHAR id)
{
    UCHAR i;
    //printf("select Layer4Item, id = %d\n", (USHRT)id);
    //printf("ucLayer3MenuType=%d\r\n",(USHRT)ucLayer3MenuType);
       
     //  UCHAR templang;

        // redraw selected string color
     for(i=0;i<ucLBLItemInfoTb[0];i++){//ULEric140401
         OSDAPI_FillLineAttr(ucLBLItemInfoTb[1], ucLBLItemInfoTb[2]+i*2, INDENT_STRING_MAX_LEN, UnSelectedStringColor1_256);
     }

    OSDShowBigWin(OSD_LAYER4_WIN, OSD_WIN_BOARDER_SIZE);      

    // redraw string separater to blue color
    OSDAPI_FillLineAttr(ucLBLItemInfoTb[1], ucLBLItemInfoTb[2]-1+id*2, INDENT_STRING_MAX_LEN, StringSeparaterLineColor2);
    OSDShowSmallWin(id, OSD_LAYER4_WIN);    
    if(id!=7)//ULEric140401
    OSDAPI_FillLineAttr(ucLBLItemInfoTb[1], ucLBLItemInfoTb[2]+1+id*2, INDENT_STRING_MAX_LEN, StringSeparaterLineColor2);

    // redraw selected string color
    OSDAPI_FillLineAttr(ucLBLItemInfoTb[1], ucLBLItemInfoTb[2]+id*2, INDENT_STRING_MAX_LEN, SelectedStringColor_256);
    
    // show selected triangle font
    if (id == ucLayer3MenuType) {
        OSDShowTrianIcon(TRIANGLE_METHOD2, id, STRING_LAYER_4);
    }
    else {
       OSDShowTrianIcon(TRIANGLE_METHOD1, id, STRING_LAYER_4);
    }

}



//******************************************************************************
// Prototype:
//  void OSDShowMainMenuStrings(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Show main menu page
// Notes:
//  None
//******************************************************************************
void OSDShowMainMenuStrings(void) 
{
    UCHAR i;
    for (i=0; i<MAINMENU_ICON_NUM; i++) {
        if (MainMenuStrTab[i*NUM_OSDLANGS+UserData.ucLanguage] != NULL)
            ShowIndentString(TRUE, ucLayer1StringInfoTb[0], ucLayer1StringInfoTb[1]+i*2, INDENT_STRING_MAX_LEN, MainMenuStrTab[i*NUM_OSDLANGS+UserData.ucLanguage]);
    }

}


#if 0
//******************************************************************************
// Prototype:
//  void OSDCloseMainMenu(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Close Main Menu
// Notes:
//  None
//******************************************************************************
void OSDCloseMainMenu(void)
{
    OSDClosed();
}
#endif
//******************************************************************************
// Prototype:
//  void OSDSelectDialogItem(UCHAR id, UCHAR isUp)
// Parameters:
//  id  : current cursor position
// Return:
//  None
// Purpose:
//  Activate the selected dialog item
// Notes:
//  None
//******************************************************************************
void OSDSelectDialogItem(UCHAR id, UCHAR isUp)
{
    UCHAR i, tmp, CustomerKey;

    isUp = isUp;
    CustomerKey = fnGetCustomerKeyItem();
    // show layer 2 second level string if necessary
#if LAYER_INDENT_COUNT == ON
    OSDAPI_SetIndentIndex(String_DialogString_Index);
    //printf("Get layer (%d) Indent index = %d\n", (USHRT)DIALOG_LAYER, (USHRT)String_TopPage_Index);
#else
    if((GetOSDState()>= OSD_TOPPAGE_END)&&(GetOSDState() < OSD_MAIN_BEG)){
    OSDAPI_SetIndentIndex(String_DialogString_Index);
    }
    else{
    OSDAPI_SetIndentIndex(String_Layer2_Index);
    }
#endif

    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    OSDAPI_SetFontAttr(UnSelectedStringColor1_256);
    bSelectTable = OSDFontTble1;
  //  printf("id,isup %x,%x\r\n",(USHRT)id,(USHRT)isUp);
    if (CustomerKey == CUSTOMER_KEY_PICTUREMODE || CustomerKey == CUSTOMER_KEY_DISPLAYMODE || CustomerKey == CUSTOMER_KEY_INPUT) {
            if (CustomerKey == CUSTOMER_KEY_PICTUREMODE) {
                for (i=0; i<((id>7)? (ucLayer3ItmNumTab[OSD_MAIN_PICTURE_ADVANCED][OSD_PICTURE_AD_PIC]-8):(ucLayer3ItmNumTab[OSD_MAIN_PICTURE_ADVANCED][OSD_PICTURE_AD_PIC]>8?8: ucLayer3ItmNumTab[OSD_MAIN_PICTURE_ADVANCED][OSD_PICTURE_AD_PIC])) ; i++)
                    ShowIndentString(TRUE, 8, 5+i*2, DIALOG_INDENT_STRING_MAX_LEN, ((id > 7)?TestTable2[OSD_MAIN_PICTURE_ADVANCED][OSD_PICTURE_AD_PIC][(8+i)*NUM_OSDLANGS+UserData.ucLanguage]:TestTable2[OSD_MAIN_PICTURE_ADVANCED][OSD_PICTURE_AD_PIC][i*NUM_OSDLANGS+UserData.ucLanguage]));
          if(id>7){
              OSDClearItemString(0,1);
              //OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
              //for (i=1;i<7; i++)
                //OSDAPI_WriteXYRepeatChar(FALSE, 8, 5+(i*2), INDENT_STRING_MAX_LEN, _SPACE_);
          }                  
            }
            else if (CustomerKey == CUSTOMER_KEY_DISPLAYMODE) {
                for (i=0; i<((id>7)? (ucLayer3ItmNumTab[OSD_MAIN_PICTURE_ADVANCED][OSD_PICTURE_AD_DISMODE]-8):(ucLayer3ItmNumTab[OSD_MAIN_PICTURE_ADVANCED][OSD_PICTURE_AD_DISMODE]>8?8: ucLayer3ItmNumTab[OSD_MAIN_PICTURE_ADVANCED][OSD_PICTURE_AD_DISMODE])) ; i++)

                if (OSDIsCustomkeyItemValid(i)==FALSE){
                    OSDAPI_SetFontAttr(DisabledStringColor_256);                    
                    ShowIndentString(TRUE, 8, 5+i*2, DIALOG_INDENT_STRING_MAX_LEN, ((id > 7)?TestTable2[OSD_MAIN_PICTURE_ADVANCED][OSD_PICTURE_AD_DISMODE][(8+i)*NUM_OSDLANGS+UserData.ucLanguage]:TestTable2[OSD_MAIN_PICTURE_ADVANCED][OSD_PICTURE_AD_DISMODE][i*NUM_OSDLANGS+UserData.ucLanguage]));                    
                }
          else{
                    OSDAPI_SetFontAttr(UnSelectedStringColor1_256);              
                    ShowIndentString(TRUE, 8, 5+i*2, DIALOG_INDENT_STRING_MAX_LEN, ((id > 7)?TestTable2[OSD_MAIN_PICTURE_ADVANCED][OSD_PICTURE_AD_DISMODE][(8+i)*NUM_OSDLANGS+UserData.ucLanguage]:TestTable2[OSD_MAIN_PICTURE_ADVANCED][OSD_PICTURE_AD_DISMODE][i*NUM_OSDLANGS+UserData.ucLanguage]));                
          }
            }
            else if (CustomerKey == CUSTOMER_KEY_INPUT) {
                for (i=0; i<((id>7)? (ucLayer3ItmNumTab[OSD_MAIN_DISPLAY][OSD_DISPLAY_INPUT]-8):(ucLayer3ItmNumTab[OSD_MAIN_DISPLAY][OSD_DISPLAY_INPUT]>8?8: ucLayer3ItmNumTab[OSD_MAIN_DISPLAY][OSD_DISPLAY_INPUT])) ; i++)
                    ShowIndentString(TRUE, 8, 5+i*2, DIALOG_INDENT_STRING_MAX_LEN, ((id > 7)?TestTable2[OSD_MAIN_DISPLAY][OSD_DISPLAY_INPUT][(8+i)*NUM_OSDLANGS+UserData.ucLanguage]:TestTable2[OSD_MAIN_DISPLAY][OSD_DISPLAY_INPUT][i*NUM_OSDLANGS+UserData.ucLanguage]));
            }
    }
    else if(CustomerKey == CUSTOMER_KEY_MUTE){//ULEric140402
        for (i=0; i<2; i++)
                  ShowIndentString(TRUE, 8, 5+i*2, DIALOG_INDENT_STRING_MAX_LEN, TestTable2[OSD_MAIN_AUDIO][OSD_AUDIO_MUTE][i*NUM_OSDLANGS+UserData.ucLanguage]);
    }
    else if(CustomerKey == CUSTOMER_KEY_LOWBULELIGHTMODE){//ULEric140402
            OSDShowCusLowBlueLightStrings();
    }
    else if(CustomerKey == CUSTOMER_KEY_SMARTREMINDER){//ULEric140402
        for (i=0; i<2; i++)
                  ShowIndentString(TRUE, 8, 5+i*2, DIALOG_INDENT_STRING_MAX_LEN, TestTable2[OSD_MAIN_ERGONOMICS][OSD_ERGONOMICS_REMIDER][i*NUM_OSDLANGS+UserData.ucLanguage]);            
    }    

    tmp = ((id > 7)? (id-8):id);
    // string row

    // redraw string separater to blue color
    if (tmp != 0)
        OSDAPI_FillLineAttr(8, 5+tmp*2-1, INDENT_STRING_MAX_LEN, StringSeparaterLineColor2);

    OSDShowSmallWin(tmp, OSD_DIALOG_LAYER_WIN);
    
    if (tmp == 0) {
        OSDShowTrianIcon(TRIANGLE_METHOD2, 0, DIALOG_LAYER);
    }
    else {
        OSDShowTrianIcon(TRIANGLE_METHOD1, 0, DIALOG_LAYER);
    }

    if (tmp != 7)
        OSDAPI_FillLineAttr(8, 5+tmp*2+1, INDENT_STRING_MAX_LEN, StringSeparaterLineColor2);

    OSDAPI_FillLineAttr(8, 5+tmp*2, DIALOG_INDENT_STRING_MAX_LEN, SelectedStringColor_256);
    
    //ULEric140402
    OSDShowHook(id, CustomerKey);

}

//******************************************************************************
// Prototype:
//  void OSDSelectLayer1Item(UCHAR id)
// Parameters:
//  id  : current cursor position
// Return:
//  None
// Purpose:
//  Activate the selected Layer1 item
// Notes:
//  None
//******************************************************************************
void OSDSelectLayer1Item(UCHAR id)
{
    UCHAR i;
    ucMenuType = id;
    // show layer2 string
#if LAYER_INDENT_COUNT == ON
    OSDAPI_SetIndentIndex(fnGetLayerIndentCount(STRING_LAYER_2));
    //printf("Get layer (%d) Indent index = %d\n", (USHRT)STRING_LAYER_2, (USHRT)fnGetLayerIndentCount(STRING_LAYER_2));
#else
    OSDAPI_SetIndentIndex(String_Layer2_Index);
#endif
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    OSDAPI_SetFontAttr(UnSelectedStringColor);
    bSelectTable = OSDFontTble1;
    for (i=0; i<(ucLayer2ItmNumTb[id]>OSD_MAX_LINES ? OSD_MAX_LINES:ucLayer2ItmNumTb[id]); i++) {
               if (OSDIsSubItemValid(i) == FALSE) {
                   OSDAPI_SetFontAttr(DisabledStringColor);
               }
            else{             
                   OSDAPI_SetFontAttr(UnSelectedStringColor);
            }
        if (Layer2StringTab[id][i*NUM_OSDLANGS+UserData.ucLanguage] != NULL) {
            ShowIndentString(TRUE, ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*2, INDENT_STRING_MAX_LEN, Layer2StringTab[id][i*NUM_OSDLANGS+UserData.ucLanguage]);
        }
    }
    // show up down arrow icon
    OSDShowUpDownArrowIcon(id); 

}


//******************************************************************************
// Prototype:
//  void OSDSelectLayer2Item(UCHAR id, BOOL isUp)
// Parameters:
//  id      : current Layer2 item id
// Return:
//  None
// Purpose:
//  Select Layer2 item
// Notes:
//  None
//******************************************************************************
void OSDSelectLayer2Item(UCHAR id, BOOL isUp)
{
    UCHAR i, tmp;
    UCHAR ucDisable1,ucDisable2;//ULEric140401
    USHRT Attr;

    // redraw up down icon to white
    OSDAPI_FillLineAttr(24, 3, 2, ArrowColor1);
    OSDAPI_FillLineAttr(25, 21, 1, ArrowColor1);
    OSDAPI_FillLineAttr(24, 20, 2, ArrowColor1);

    // show layer 2 second level string if necessary
#if LAYER_INDENT_COUNT == ON
    OSDAPI_SetIndentIndex(fnGetLayerIndentCount(STRING_LAYER_2));
    //printf("Get layer (%d) Indent index = %d\n", (USHRT)STRING_LAYER_2, (USHRT)fnGetLayerIndentCount(STRING_LAYER_2));
#else
    OSDAPI_SetIndentIndex(String_Layer2_Index);
#endif
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    OSDAPI_SetFontAttr(UnSelectedStringColor1);

    bSelectTable = OSDFontTble1;

    if (id == 8 && isUp == FALSE) {     
        IsPage2 = TRUE;
        for (i=0; i< ucLayer2ItmNumTb[ucMenuType]-8; i++) {
               if (OSDIsSubItemValid(i) == FALSE) {
                   OSDAPI_SetFontAttr(DisabledStringColor);                        
               }
            else if(i == (id-8)){//ULEric140516               
                   OSDAPI_SetFontAttr(SelectedStringColor);    
            }
            else{
             
                   OSDAPI_SetFontAttr(UnSelectedStringColor1);
            }
            ShowIndentString(TRUE, ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*2, INDENT_STRING_MAX_LEN, Layer2StringTab[ucMenuType][(8+i)*NUM_OSDLANGS+UserData.ucLanguage]);
        }

        // show up arrow
        OSDAPI_SetFontAttr(ArrowColor1);
        OSDAPI_WriteXYChar(TRUE, 24, 3, UpArrow_1);
        OSDAPI_WriteXYChar(TRUE, 25, 3, UpArrow_2);

        // clear down arrow
        OSDAPI_WriteXYRepeatChar(TRUE, 24, 20, 2, _SPACE_);
        OSDAPI_WriteXYRepeatChar(TRUE, 24, 21, 2, _SPACE_);
    }
    else if(id == 7 && isUp == TRUE) {

        IsPage2 = FALSE;

        for (i=0; i< 8 ; i++) {
               if (OSDIsSubItemValid(i) == FALSE) {
                   OSDAPI_SetFontAttr(DisabledStringColor);                        
               }
            else if(i == id){               
                   OSDAPI_SetFontAttr(SelectedStringColor);             
            }
            else{
             
                   OSDAPI_SetFontAttr(UnSelectedStringColor1);
            }
            ShowIndentString(TRUE, ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*2, INDENT_STRING_MAX_LEN, Layer2StringTab[ucMenuType][i*NUM_OSDLANGS+UserData.ucLanguage]);
        }

        // show down arrow
        OSDAPI_SetFontAttr(ArrowColor1);
        OSDAPI_WriteXYChar(TRUE, 24, 20, DownArrow_1);
        OSDAPI_WriteXYChar(TRUE, 25, 20, DownArrow_2);
        OSDAPI_WriteXYChar(TRUE, 25, 21, DownArrow_3);

        // clear up arrow
        OSDAPI_WriteXYRepeatChar(TRUE, 24, 3, 2, _SPACE_);
    }
    else {
             
        for (i=0; i<(IsPage2? (ucLayer2ItmNumTb[ucMenuType]-8):(ucLayer2ItmNumTb[ucMenuType]>8?8: ucLayer2ItmNumTb[ucMenuType])) ; i++) {            
               if (OSDIsSubItemValid(i) == FALSE) {
             Attr = DisabledStringColor;           
                   //OSDAPI_SetFontAttr(DisabledStringColor);
               }
            else if(i == (IsPage2?(id-8):id)){//ULEric140516
                Attr =  SelectedStringColor;
                   //OSDAPI_SetFontAttr(SelectedStringColor);
            }
            else{            
             Attr = UnSelectedStringColor1;    
                   //OSDAPI_SetFontAttr(UnSelectedStringColor1);
            }            
         //ShowIndentString(TRUE, ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*2, INDENT_STRING_MAX_LEN, (IsPage2?Layer2StringTab[ucMenuType][(i+8)*NUM_OSDLANGS+UserData.ucLanguage]:Layer2StringTab[ucMenuType][i*NUM_OSDLANGS+UserData.ucLanguage]));
         OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*2, INDENT_STRING_MAX_LEN, Attr);
        }
    }    
//    fnResetLayerIndentCount(STRING_LAYER_3);
    
    tmp = (IsPage2 == TRUE? (id-8):id);        
    // redraw string separater to blue color
    if (id != 7)
        OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+tmp*2+1, INDENT_STRING_MAX_LEN, StringSeparaterLineColor2);
    if (id != 0)
        OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+tmp*2-1, INDENT_STRING_MAX_LEN, StringSeparaterLineColor2);

    // string row
//    OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+tmp*2, INDENT_STRING_MAX_LEN, SelectedStringColor);

    // show big window


    // show triangle icon
   // if (IsPage2) {
   //     id = id -8;
  //  }



    if (id == ucMenuType) {
        OSDShowTrianIcon(TRIANGLE_METHOD2, tmp, STRING_LAYER_2);
    }
    else {
        OSDShowTrianIcon(TRIANGLE_METHOD1, tmp, STRING_LAYER_2);
    }

    OSDShowBigWin(OSD_LAYER2_WIN, OSD_WIN_BOARDER_SIZE);
    OSDShowSmallWin(tmp, OSD_LAYER2_WIN);

    // show layer 3 string
    if (ucLayer3ItmNumTab[ucMenuType][id]) {
#if LAYER_INDENT_COUNT == ON
        OSDAPI_SetIndentIndex(OneBitFont_256_end);
        //OSDAPI_SetIndentIndex(fnGetLayerIndentCount(STRING_LAYER_3));
        //printf("Get layer (%d) Indent index = %d\n", (USHRT)STRING_LAYER_3, (USHRT)fnGetLayerIndentCount(STRING_LAYER_3));
#else
        OSDAPI_SetIndentIndex(String_Layer3_Index);
#endif
        OSDAPI_SetAlignType(OSD_ALIGN_LEFT);

        // show layer 3 string separater
        OSDShowStringSeparater(STRING_LAYER_3, FALSE);

        // show layer 3 string
     if(ucLayer3ItmNumTab[ucMenuType][id]>OSD_MAX_LINES)
     {
         if(ucMenuType == OSD_MAIN_SYSTEM)//CusKey1/2/3
         {
             if(id == OSD_SYS_CTKEY1)
             {
                tmp = UserData.ucCustomerKey1;
                ucDisable1 = UserData.ucCustomerKey2;
                ucDisable2 = UserData.ucCustomerKey3;
             }
            else if(id == OSD_SYS_CTKEY2)
            {
                tmp = UserData.ucCustomerKey2;
                ucDisable1 = UserData.ucCustomerKey1;
                ucDisable2 = UserData.ucCustomerKey3;
            }
            else if(id == OSD_SYS_CTKEY3)
            {
                tmp = UserData.ucCustomerKey3;
                ucDisable1 = UserData.ucCustomerKey1;
                ucDisable2 = UserData.ucCustomerKey2;
            }    
         }
         if(ucMenuType == OSD_MAIN_PICTURE_ADVANCED)//CusKey1/2/3
         {        
             if(id == OSD_PICTURE_AD_PIC)
             {
                tmp = UserData.ucBFMode;
                ucDisable1 = 0xFF;
                ucDisable2 = 0xFF;
             }         
         }         
        
        if(tmp>(OSD_MAX_LINES-1))//Show Page2 
        {                        
            tmp = (OSD_MAX_LINES*2);//ucLayer3ItmNumTab[ucMenuType][id];
            for (i = OSD_MAX_LINES;i<tmp; i++)
            {        
                if(i>=ucLayer3ItmNumTab[ucMenuType][id])//Clear Empty Item Line
                {
                    OSDAPI_SetFontAttr(ArrowColor1);
                    OSDAPI_WriteXYRepeatChar(TRUE, *(ucLayer3PosInfoTab[ucMenuType]+0),*(ucLayer3PosInfoTab[ucMenuType]+1)+(i-OSD_MAX_LINES)*2, INDENT_STRING_MAX_LEN, _SPACE_);
                }else{
                    if(i==ucDisable1||i==ucDisable2)
                        OSDAPI_SetFontAttr(DisabledStringColor_256);
                    else    
                        OSDAPI_SetFontAttr(UnSelectedStringColor_256);
                             ShowIndentString(TRUE, *(ucLayer3PosInfoTab[ucMenuType]+0), *(ucLayer3PosInfoTab[ucMenuType]+1)+(i-OSD_MAX_LINES)*2, INDENT_STRING_MAX_LEN,
                             TestTable2[ucMenuType][id][i*NUM_OSDLANGS+UserData.ucLanguage]);
                }
            }
            OSDUpdateArrowIcon(ArrowColor2,LastArrowType,STRING_LAYER_3);//ULEric140403
        }else{//Show Page1            
            tmp = OSD_MAX_LINES;
            for (i = 0;i<tmp; i++)
            {    
                if(i==ucDisable1||i==ucDisable2)
                    OSDAPI_SetFontAttr(DisabledStringColor_256);
                else    
                    OSDAPI_SetFontAttr(UnSelectedStringColor_256);
                         ShowIndentString(TRUE, *(ucLayer3PosInfoTab[ucMenuType]+0), *(ucLayer3PosInfoTab[ucMenuType]+1)+i*2, INDENT_STRING_MAX_LEN,
                         TestTable2[ucMenuType][id][i*NUM_OSDLANGS+UserData.ucLanguage]);
            }
            OSDUpdateArrowIcon(ArrowColor2,TopArrowType,STRING_LAYER_3);//ULEric140403
        }
     }
     else{
         if(ucMenuType == OSD_MAIN_SYSTEM && (id==(OSD_SYS_CTKEY1-1)||id==(OSD_SYS_CTKEY3+1))){//ULEric140403
             OSDUpdateArrowIcon(CLEAR_1BIT_COLOR,ClearArrowType,STRING_LAYER_3);
         }
         if(ucMenuType == OSD_MAIN_PICTURE_ADVANCED && (id!=OSD_PICTURE_AD_PIC)){//ULEric140403
             OSDUpdateArrowIcon(CLEAR_1BIT_COLOR,ClearArrowType,STRING_LAYER_3);
         }         
             
         for (i=0; i<ucLayer3ItmNumTab[ucMenuType][id]; i++) {
                if (TestTable2[ucMenuType][id][i] != NULL) {
                        ucSubMenuType = id;
                        if(OSDIsLayer3ItemValid(i)==FALSE){
                OSDAPI_SetFontAttr(DisabledStringColor_256);
                        }
               else{
                        OSDAPI_SetFontAttr(UnSelectedStringColor_256);
               }
                    ShowIndentString(TRUE, *(ucLayer3PosInfoTab[ucMenuType]+0), *(ucLayer3PosInfoTab[ucMenuType]+1)+i*2, INDENT_STRING_MAX_LEN,
                    TestTable2[ucMenuType][id][i*NUM_OSDLANGS+UserData.ucLanguage]);


                }
            }
                if ((ucMenuType == OSD_MAIN_SYSTEM) && (id == OSD_SYS_INFORMATION)) {//information
                    OSDShowInfo();
                    //ClrLayer4Flags = TRUE;
                }         
     }
        // show layer 3 hook icon
        OSDShowHookIcon(SelectedStringColor1_256, id, STRING_LAYER_3, Hook_Icon);//ULEric040327 HookIconColor1_256
    }
    else {
     // Clear layer 3 string separater
        OSDShowStringSeparater(STRING_LAYER_3, TRUE);//ULEric140407
        OSDShowLayer3Item(id);
    }
    /* //ULEric140416    
    if ((ucMenuType == OSD_MAIN_SYSTEM) && (id == 8)) {//information
        for (i=0; i<14; i++) 
        {
            OSDAPI_WriteXYRepeatChar(FALSE, 47, 5+i, INDENT_STRING_MAX_LEN, _SPACE_);
            //ClrLayer4Flags = FALSE;
        }              
    }    
    if ((ucMenuType == OSD_MAIN_SYSTEM) && (id == 10)) {//information
        for (i=0; i<14; i++) 
        {
            OSDAPI_WriteXYRepeatChar(FALSE, 47, 5+i, INDENT_STRING_MAX_LEN, _SPACE_);
            //ClrLayer4Flags = FALSE;
        }              
    }    
    */
}

//******************************************************************************
// Prototype:
//  void OSDSelectLayer3Item(UCHAR id)
// Parameters:
//  id      : current Layer3 item id
// Return:
//  None
// Purpose:
//  Unselect Layer3 item
// Notes:
//  None
//******************************************************************************
void OSDSelectLayer3Item(UCHAR id)
{
    UCHAR i, tmp, tmp2;
    tmp = (ucSubMenuType>7)? (ucSubMenuType-8): ucSubMenuType;
    tmp2 = (id > 7? (id-8):id);
    bSelectTable = OSDFontTble1;
    if (ucLayer3ItmNumTab[ucMenuType][ucSubMenuType]) {
        if (ucLayer3ItmNumTab[ucMenuType][ucSubMenuType] > 8) {
            // redraw up down icon to white
            //OSDAPI_FillLineAttr(38, 3, 2, ArrowColor1);
            //OSDAPI_FillLineAttr(39, 21, 1, ArrowColor1);
            //OSDAPI_FillLineAttr(38, 20, 2, ArrowColor1);

#if LAYER_INDENT_COUNT == ON
            OSDAPI_SetIndentIndex(OneBitFont_256_end);
            //OSDAPI_SetIndentIndex(fnGetLayerIndentCount(STRING_LAYER_3));
            //printf("Get layer (%d) Indent index = %d\n", (USHRT)STRING_LAYER_3, (USHRT)fnGetLayerIndentCount(STRING_LAYER_3));
#else
            OSDAPI_SetIndentIndex(String_Layer3_Index);
#endif
            OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
            if (id > 7) {//page 2
                //
                if(ucMenuType == OSD_MAIN_SYSTEM){
                    if(ucSubMenuType ==OSD_SYS_CTKEY1 )//Justin 140428 CustomerKey1
                    {
                            if(UserData.ucCustomerKey1 < (OSD_MAX_LINES))
                            {
                                OSDShowHookIcon(CLEAR_1BIT_COLOR, ucSubMenuType, STRING_LAYER_3, _SPACE_);
                            }
                            else
                            {
                                 OSDShowHookIcon(UnSelectedStringColor1_256, ucSubMenuType, STRING_LAYER_3, Hook_Icon);
                            }
                    }
                    if(ucSubMenuType ==OSD_SYS_CTKEY2 )//Justin 140428 CustomerKey2
                    {
                            if(UserData.ucCustomerKey2 < (OSD_MAX_LINES))
                            {
                                 OSDShowHookIcon(CLEAR_1BIT_COLOR, ucSubMenuType, STRING_LAYER_3, _SPACE_);
                            }
                            else
                            {
                                 OSDShowHookIcon(UnSelectedStringColor1_256, ucSubMenuType, STRING_LAYER_3, Hook_Icon);

                            }
                    }
                    if(ucSubMenuType ==OSD_SYS_CTKEY3 )//Justin 140428 CustomerKey3
                    {
                            if(UserData.ucCustomerKey3 < (OSD_MAX_LINES))
                            {
                                 OSDShowHookIcon(CLEAR_1BIT_COLOR, ucSubMenuType, STRING_LAYER_3, _SPACE_);
                            }
                            else
                            {
                                 OSDShowHookIcon(UnSelectedStringColor1_256, ucSubMenuType, STRING_LAYER_3, Hook_Icon);

                            }
                    }//        
                }
                // show layer 3 string
                for (i=0; i<ucLayer3ItmNumTab[ucMenuType][ucSubMenuType]-8; i++) {
                    if (TestTable2[ucMenuType][ucSubMenuType][8+i] != NULL) {
                        if(OSDIsLayer3ItemValid(8+i)){//ULEric140416                        
                        OSDAPI_SetFontAttr(UnSelectedStringColor1_256);
                        }
                        else{
                            OSDAPI_SetFontAttr(DisabledStringColor_256);  
                        }
                        ShowIndentString(TRUE, ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*2, INDENT_STRING_MAX_LEN-2,
                        TestTable2[ucMenuType][ucSubMenuType][(8+i)*NUM_OSDLANGS+UserData.ucLanguage]);
                    }
                }

                // show up arrow
                //OSDAPI_SetFontAttr(ArrowColor1);
                //OSDAPI_WriteXYChar(TRUE, 38, 3, UpArrow_1);
                //OSDAPI_WriteXYChar(TRUE, 39, 3, UpArrow_2);

                // clear down arrow
                //OSDAPI_WriteXYRepeatChar(TRUE, 38, 20, 2, _SPACE_);
                //OSDAPI_WriteXYRepeatChar(TRUE, 38, 21, 2, _SPACE_);
                OSDUpdateArrowIcon(ArrowColor1,LastArrowType,STRING_LAYER_3);
            }
            else {
                   if(ucMenuType == OSD_MAIN_SYSTEM){                
                if(ucSubMenuType ==OSD_SYS_CTKEY1 )//Justin 140428 CustomerKey1
                {
                        if(UserData.ucCustomerKey1 > (OSD_MAX_LINES-1))
                        {
                             OSDShowHookIcon(CLEAR_1BIT_COLOR, ucSubMenuType, STRING_LAYER_3, _SPACE_);
                        }
                        else
                        {
                             OSDShowHookIcon(UnSelectedStringColor1_256, ucSubMenuType, STRING_LAYER_3, Hook_Icon);
                        }
                }
                if(ucSubMenuType ==OSD_SYS_CTKEY2 )//Justin 140428 CustomerKey1
                {
                        if(UserData.ucCustomerKey2 > (OSD_MAX_LINES-1))
                        {
                             OSDShowHookIcon(CLEAR_1BIT_COLOR, ucSubMenuType, STRING_LAYER_3, _SPACE_);
                        }
                        else
                        {
                             OSDShowHookIcon(UnSelectedStringColor1_256, ucSubMenuType, STRING_LAYER_3, Hook_Icon);
                        }
                }    
                if(ucSubMenuType ==OSD_SYS_CTKEY3 )//Justin 140428 CustomerKey1
                {
                        if(UserData.ucCustomerKey3 > (OSD_MAX_LINES-1))
                        {
                             OSDShowHookIcon(CLEAR_1BIT_COLOR, ucSubMenuType, STRING_LAYER_3, _SPACE_);
                        }
                        else
                        {
                             OSDShowHookIcon(UnSelectedStringColor1_256, ucSubMenuType, STRING_LAYER_3, Hook_Icon);
                        }
                }        
                       }
                // show layer 3 string
                for (i=0; i<((ucLayer3ItmNumTab[ucMenuType][ucSubMenuType]>8)? 8:ucLayer3ItmNumTab[ucMenuType][ucSubMenuType]); i++) {
                    if (TestTable2[ucMenuType][ucSubMenuType][i] != NULL) {        
                        if(OSDIsLayer3ItemValid(i)){                        
                            OSDAPI_SetFontAttr(UnSelectedStringColor1_256);
                        }
                        else{
                            OSDAPI_SetFontAttr(DisabledStringColor_256);
                        }
                        ShowIndentString(TRUE, ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*2, INDENT_STRING_MAX_LEN-2,
                        TestTable2[ucMenuType][ucSubMenuType][i*NUM_OSDLANGS+UserData.ucLanguage]);
                    }
                }

                // clear up arrow
                //OSDAPI_WriteXYRepeatChar(TRUE, 38, 3, 2, _SPACE_);
                // show down arrow
                //OSDAPI_SetFontAttr(ArrowColor1);
                //OSDAPI_WriteXYChar(TRUE, 38, 20, DownArrow_1);
                //OSDAPI_WriteXYChar(TRUE, 39, 20, DownArrow_2);
                //OSDAPI_WriteXYChar(TRUE, 39, 21, DownArrow_3);

                OSDUpdateArrowIcon(ArrowColor1,TopArrowType,STRING_LAYER_3);
            }
        }
        else {
#if LAYER_INDENT_COUNT == ON
            OSDAPI_SetIndentIndex(OneBitFont_256_end);
            //OSDAPI_SetIndentIndex(fnGetLayerIndentCount(STRING_LAYER_3));
            //printf("Get layer (%d) Indent index = %d\n", (USHRT)STRING_LAYER_3, (USHRT)fnGetLayerIndentCount(STRING_LAYER_3));
#else
            OSDAPI_SetIndentIndex(String_Layer3_Index);
#endif
            OSDAPI_SetAlignType(OSD_ALIGN_LEFT);

            for (i=0; i<((ucLayer3ItmNumTab[ucMenuType][ucSubMenuType]>8)? 8:ucLayer3ItmNumTab[ucMenuType][ucSubMenuType]); i++) {
                if (TestTable2[ucMenuType][ucSubMenuType][i] != NULL) {
                    if(OSDIsLayer3ItemValid(i)){                        
                        OSDAPI_SetFontAttr(UnSelectedStringColor1_256);
                    }
                    else{
                            OSDAPI_SetFontAttr(DisabledStringColor_256);
                    }
                    ShowIndentString(TRUE, ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*2, INDENT_STRING_MAX_LEN-2,
                    TestTable2[ucMenuType][ucSubMenuType][i*NUM_OSDLANGS+UserData.ucLanguage]);
                }
            }
        }

        if (tmp2 == tmp) {
            OSDShowTrianIcon(TRIANGLE_METHOD2, tmp2, STRING_LAYER_3);
        }
        else {
            OSDShowTrianIcon(TRIANGLE_METHOD1, tmp2, STRING_LAYER_3);
        }
        
        OSDShowSmallWin(tmp2, OSD_LAYER3_WIN);        
        // redraw layer3 string to white color
        for (i=0; i<(ucLayer3ItmNumTab[ucMenuType][ucSubMenuType] > 8? 8:ucLayer3ItmNumTab[ucMenuType][ucSubMenuType]); i++) {
            if (i == tmp2) {
                // redraw layer3 selected string to Black color
                OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*2, INDENT_STRING_MAX_LEN, SelectedStringColor_256);

                // redraw string separater to blue color
                if (tmp2 != 0)
                    OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]-1+tmp2*2, INDENT_STRING_MAX_LEN, StringSeparaterLineColor2);
                if (tmp2 != 7)
                    OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+1+tmp2*2, INDENT_STRING_MAX_LEN, StringSeparaterLineColor2);
            }
            else {
/*                
                 if(OSDIsLayer3ItemValid(i)){
                        OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*2, INDENT_STRING_MAX_LEN, UnSelectedStringColor1_256);                            
                 }
                 else{
                         OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*2, INDENT_STRING_MAX_LEN, DisabledStringColor_256);
               }
*/               
            }
        }


        //printf("select layer 3 item triangle, tmp = %d, tmp2 = %d\n", (USHRT)tmp, (USHRT)tmp2);

        // show layer3 triangle icon
        

    }
    else {
        // show layer3 triangle icon
        OSDShowTrianIcon(TRIANGLE_METHOD1, tmp2, STRING_LAYER_3);
    }

    OSDShowBigWin(OSD_LAYER3_WIN, OSD_WIN_BOARDER_SIZE);

    // show layer4 string
    //OSDShowLayer4String(id);
    
    // color temperature
    if (ucMenuType == OSD_MAIN_PICTURE && ucSubMenuType == OSD_PICTURE_COLORTEMP && id == CLRTMP_USER) {
        OSDShowRGain(FALSE, FALSE);
        OSDShowGGain(FALSE, FALSE);
        OSDShowBGain(FALSE, FALSE);
    }
    else if(ucMenuType == OSD_MAIN_PICTURE_ADVANCED && ucSubMenuType == OSD_PICTURE_AD_PIC && id == PICTURE_MODE_LOW_BL) {//low blue light
        OSDShowStringSeparater(STRING_LAYER_4, FALSE);
        //ClrLayer4Flags = TRUE; //Justin 140326
        // show layer 4 string
#if LAYER_INDENT_COUNT == ON
        OSDAPI_SetIndentIndex(fnGetLayerIndentCount(STRING_LAYER_4));
#else
        OSDAPI_SetIndentIndex(String_Layer4_Index);
#endif
        OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
        OSDAPI_SetFontAttr(UnSelectedStringColor_256);   
        OSDShowLowBlueLightStrings(id);
        // Show Layer 4 hook icon
        OSDShowHookIcon(SelectedStringColor1_256, id, STRING_LAYER_4, Hook_Icon);//ULEric140402

        //OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1);//ULEric140411
        //for (i=0; i<SPIconItmNumTab[2]; i++) {
            // OSDAPI_WriteXYChar(TRUE, 65+SPIconPosInfoTab[2][i*2], SPIconPosInfoTab[2][i*2+1], SP_Icon3_1Bit_1+i);
        //}
    }
    else if (ucMenuType == OSD_MAIN_SYSTEM && ucSubMenuType == OSD_SYS_OSDSET) {
        if(id < OSD_SYS_OSDSET_OSDLOCK)
        {
            OSDShowStringSeparater(STRING_LAYER_4, FALSE);

        // show layer 4 string
#if LAYER_INDENT_COUNT == ON
            OSDAPI_SetIndentIndex(fnGetLayerIndentCount(STRING_LAYER_4));
        //printf("Get layer (%d) Indent index = %d\n", (USHRT)STRING_LAYER_4, (USHRT)fnGetLayerIndentCount(STRING_LAYER_4));
#else
            OSDAPI_SetIndentIndex(String_Layer4_Index);
#endif
            OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
            OSDAPI_SetFontAttr(UnSelectedStringColor_256);
         }
        if (id == OSD_SYS_OSDSET_LANG) { // language
          bSelectTable = OSDFontTble2;
             if(UserData.ucLanguage < 8 ){
                 for (i=0; i<(ucLayer4ItemInfoTb[0]>8? 8:ucLayer4ItemInfoTb[0]); i++) {//ULEric140401
                     ShowIndentString(TRUE, ucLayer4ItemInfoTb[1], ucLayer4ItemInfoTb[2]+i*2, INDENT_STRING_MAX_LEN-2, LanguageTab[i*NUM_OSDLANGS+UserData.ucLanguage]);
                 }
             }
             else if(UserData.ucLanguage < 16 ){
                 for (i=8; i<16; i++) {
                     ShowIndentString(TRUE, ucLayer4ItemInfoTb[1], ucLayer4ItemInfoTb[2]+(i-8)*2, INDENT_STRING_MAX_LEN-2, LanguageTab[i*NUM_OSDLANGS+UserData.ucLanguage]);
                 }
             }
             else {
                 i = 16 ;
                 ShowIndentString(TRUE, ucLayer4ItemInfoTb[1], ucLayer4ItemInfoTb[2]+(i-16)*2, INDENT_STRING_MAX_LEN-2, LanguageTab[i*NUM_OSDLANGS+UserData.ucLanguage]);
                 for (i=1; i<8; i++) {
                     ShowIndentString(TRUE, ucLayer4ItemInfoTb[1], ucLayer4ItemInfoTb[2]+i*2, INDENT_STRING_MAX_LEN-2, LanguageTab[17*NUM_OSDLANGS]);
                 }  
             }
             
            bSelectTable = OSDFontTble1;
         OSDUpdateArrowIcon(ArrowColor2,(UserData.ucLanguage/8),STRING_LAYER_4);//Clear Arrow
        }
        else if (id == OSD_SYS_OSDSET_TIMER) { // display time
            for (i=0; i<ucLayer4ItemInfoTb[3*id]; i++) {
                ShowIndentString(TRUE, ucLayer4ItemInfoTb[id*3+1], ucLayer4ItemInfoTb[id*3+2]+i*2, INDENT_STRING_MAX_LEN-2, DisplayTimeTab[i*NUM_OSDLANGS+UserData.ucLanguage]);
            }
         //OSDUpdateArrowIcon(CLEAR_1BIT_COLOR,ClearArrowType,STRING_LAYER_4);//Clear Arrow //ULEric140415
        }//else if(id == 2){
            //OSDUpdateArrowIcon(CLEAR_1BIT_COLOR,ClearArrowType,STRING_LAYER_4);//Clear Arrow
        //}

            // Show Layer 4 hook icon
        OSDShowHookIcon(SelectedStringColor1_256, id, STRING_LAYER_4, Hook_Icon);//ULEric140401
    }
}




//******************************************************************************
// Prototype:
//  void OSDShowDialog(UCHAR dlg)
// Parameters:
//  dlg     : information type
// Return:
//  None
// Purpose:
//  Show information OSD
// Notes:
//  None
//******************************************************************************
void OSDShowDialog(UCHAR dlg, UCHAR keyID)
{   
    //UCHAR i;
    OSDAPI_SetHVZoom(0);
    OSDAPI_TurnOffOSD();
    OSDInitialize(TRUE);
    OSDLoadFont(ShowDialog_font); 
    if((dlg == OSD_DLG_OSDUNLOCKKEY)||(dlg == OSD_DLG_REMINDER)){
        OSDInitFrame(OSD_DIALOG_WIDTH+16, OSD_DIALOG_HEIGHT, DIALOG_MAIN_FRAME_COLOR);    
        OSDShowDialogFrame(OSD_DIALOG_WIDTH+16, OSD_DIALOG_HEIGHT);
        OSDShowBigWin(OSD_OSDUNLOCKINFO_WIN, OSD_WIN_BOARDER_SIZE);
        OSDSetPosition(1955,OSD_MAIN_MENU_V_POSITION);
    }
    else if(dlg == OSD_DLG_RESETNOTICE||dlg == OSD_DLG_RESETCOLORNOTICE||dlg == OSD_DLG_DCRNOTICE){//ULEric140410
    OSDInitFrame(OSD_DIALOG_SELECTPAGE_WIDTH, OSD_DIALOG_SELECTPAGE_HEIGHT, DIALOG_MAIN_FRAME_COLOR);    
       OSDShowDialogFrame(OSD_DIALOG_WIDTH, OSD_DIALOG_HEIGHT);
    OSDClearDialogSpaceFrame(OSD_DIALOG_WIDTH,0,OSD_DIALOG_SELECTPAGE_WIDTH,OSD_DIALOG_SELECTPAGE_HEIGHT);   
    OSDClearDialogSpaceFrame(0,OSD_DIALOG_HEIGHT,OSD_DIALOG_SELECTPAGE_WIDTH,OSD_DIALOG_SELECTPAGE_HEIGHT);    
       OSDSetPosition(OSD_MAIN_MENU_H_POSITION+((OSD_MAIN_WIDTH - OSD_DIALOG_SELECTPAGE_WIDTH)*12),OSD_MAIN_MENU_V_POSITION);    
        OSDShowBigWin(OSD_INFO_WIN, OSD_WIN_BOARDER_SIZE);       
    }
    else if (dlg == OSD_DLG_SENSEYE_DEMO) {
        OSDInitFrame(OSD_SENSEYE_DEMO_WIDTH, OSD_SENSEYE_DEMO_HIGHT, SENSEYE_FRAME_COLOR);
        OSDSetPosition(452,0);
    }        
    else{
        OSDInitFrame(OSD_DIALOG_WIDTH, OSD_DIALOG_HEIGHT, DIALOG_MAIN_FRAME_COLOR);
        OSDShowDialogFrame(OSD_DIALOG_WIDTH, OSD_DIALOG_HEIGHT);    
        OSDShowBigWin(OSD_INFO_WIN, OSD_WIN_BOARDER_SIZE);
        OSDSetPosition(2187,OSD_MAIN_MENU_V_POSITION);
    }

    bSelectTable = OSDFontTble2;
    OSDAPI_SetIndentIndex(String_TopPage_Index);
    switch (dlg) {
        case OSD_DLG_AUTOTUNE:
            OSDShowAutoIcon();            
            OSDAPI_SetIndentIndex(String_DialogString_Index);
            OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
            OSDAPI_SetFontAttr(NoticeStringColor);
            ShowIndentString(TRUE, 6, 3, 20, AutoStrTab[UserData.ucLanguage]);            
            //OSDShowTopPageIcon(TP_AUTOADJUSTMENT, 2, 0);
        break;
        case OSD_DLG_NOTICE:
            OSDShowInputIcon();
            OSDAPI_SetIndentIndex(String_DialogString_Index);
            OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
            OSDAPI_SetFontAttr(NoticeStringColor);
         //ULEric140424        
            //ShowIndentString(TRUE, 6, 3, 20, InputTab1[(GetInputPortIndex(UserData.ucInputSource)*NUM_OSDLANGS+UserData.ucLanguage)]);
         OSDShowInputNoticeDialogString();//ULEric140424
        break;
     case OSD_DLG_SAVENOTICE:
            bSelectTable = OSDFontTble1;     
         OSDShowNoticeIcon();
            OSDAPI_SetIndentIndex(String_DialogString_Index);
            OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
            OSDAPI_SetFontAttr(NoticeStringColor);
            ShowIndentString(TRUE, 6, 3, 23, CustomKeyTab[keyID*NUM_OSDLANGS+UserData.ucLanguage]);
     break; 
        case OSD_DLG_OSDLOCK:
            OSDShowNoticeIcon();
            OSDAPI_SetIndentIndex(String_DialogString_Index);
            OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
            OSDAPI_SetFontAttr(NoticeStringColor);
            ShowIndentString(TRUE, 6, 3, 20, OSDLOckStrTab[UserData.bOSDLock*NUM_OSDLANGS+UserData.ucLanguage]);
        break;
        case OSD_DLG_OSDUNLOCKKEY:
            OSDShowNoticeIcon();
            OSDAPI_SetIndentIndex(String_DialogString_Index);
            OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
            OSDAPI_SetFontAttr(NoticeStringColor);
            ShowIndentString(TRUE, 6, 3, 39, OSDUnLockkeyStrTab[UserData.ucLanguage]);
            ShowIndentString(TRUE, 6, 4, 39, OSDUnLockkeyStrTab[NUM_OSDLANGS+UserData.ucLanguage]);
        break;        
        case OSD_DLG_NOSYNC:
            OSDShowNoticeIcon();
            OSDAPI_SetIndentIndex(String_DialogString_Index);
            OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
            OSDAPI_SetFontAttr(NoticeStringColor);
            ShowIndentString(TRUE, 6, 3, 20, DialogNosyncStrTab[UserData.ucLanguage]);
        break;
        case OSD_DLG_85Hz:
            OSDShowNoticeIcon();
            OSDAPI_SetIndentIndex(String_DialogString_Index);
            OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
            OSDAPI_SetFontAttr(NoticeStringColor);
            ShowIndentString(TRUE, 6, 3, 20, DialogOutOfRangStrTab[UserData.ucLanguage]);
        break;        
        case OSD_DLG_OUTOFRANGE:
            OSDShowNoticeIcon();
            OSDAPI_SetIndentIndex(String_DialogString_Index);
            OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
            OSDAPI_SetFontAttr(NoticeStringColor);
            ShowIndentString(TRUE, 6, 3, 20, DialogOutOfRangStrTab[UserData.ucLanguage]);
        break;
        case OSD_DLG_NOCABLE:
            OSDShowNoticeIcon();
            OSDAPI_SetIndentIndex(String_DialogString_Index);
            OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
            OSDAPI_SetFontAttr(NoticeStringColor);
            ShowIndentString(TRUE, 6, 3, 20, DialogNocableStrTab[UserData.ucLanguage]);
        break;        
        case OSD_DLG_REMINDER:
            OSDShowNoticeIcon();
            OSDAPI_SetIndentIndex(String_DialogString_Index);
            OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
            OSDAPI_SetFontAttr(NoticeStringColor);
            ShowIndentString(TRUE, 6, 3, 39, DialogReminderStrTab[UserData.ucLanguage]);
        break;        
        case OSD_DLG_NONPRESET:
            OSDShowNoticeIcon();
            OSDAPI_SetIndentIndex(String_DialogString_Index);
            OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
            OSDAPI_SetFontAttr(NoticeStringColor);
            ShowIndentString(TRUE, 6, 3, 20, NonPreSentModeTab[UserData.ucLanguage]);
        break;        
        case OSD_DLG_RESNOTE:
              bSelectTable = OSDFontTble1;                
            OSDShowInputIcon();
            OSDAPI_SetIndentIndex(String_DialogString_Index);
            OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
            OSDAPI_SetFontAttr(NoticeStringColor);
            ShowIndentString(TRUE, 6, 3, 20, ResNoteStrTab[UserData.ucLanguage]);
            ShowIndentString(TRUE, 6, 4, 9, ResolutionStr);
        break;
    case OSD_DLG_RESETNOTICE://ULEric140410
              bSelectTable = OSDFontTble1;    
           OSDShowNoticeIcon();
               OSDShowSelectPageMainFrame(FrameWidthType_DialogMenu1);
           OSDUpdateKeyInfo(GetOSDState());
              OSDAPI_SetIndentIndex(String_DialogString_Index);
              OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
              OSDAPI_SetFontAttr(NoticeStringColor);
              ShowIndentString(TRUE, 6, 3, 20, ResetAllTab[UserData.ucLanguage]);    
    break;    

    case OSD_DLG_RESETCOLORNOTICE://ULEric140410
              bSelectTable = OSDFontTble1;
            OSDShowNoticeIcon();
                OSDShowSelectPageMainFrame(FrameWidthType_DialogMenu1);
            OSDUpdateKeyInfo(GetOSDState());
              OSDAPI_SetIndentIndex(String_DialogString_Index);
              OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
              OSDAPI_SetFontAttr(NoticeStringColor);
              ShowIndentString(TRUE, 6, 3, 20, ResetColorTab[UserData.ucLanguage]);
    break;    
        case OSD_DLG_SENSEYE_DEMO:
              bSelectTable = OSDFontTble1;            
            OSDAPI_SetIndentIndex(String_DialogString_Index);
            OSDAPI_SetAlignType(OSD_ALIGN_CENTER);
            OSDAPI_SetFontAttr(NoticeStringColor);
            ShowIndentString(TRUE, 0, 0, 8, SenseyeOnOffTab[OFF]); 
            ShowIndentString(TRUE, 21, 0, 5, PictureModeTab1[UserData.ucBFMode*NUM_OSDLANGS + UserData.ucLanguage]);            
            ShowIndentString(TRUE, 38, 0, 8, SenseyeOnOffTab[ON]);
            OSDAPI_SetHVZoom(2);
            OSDAPI_SetAlignType(OSD_ALIGN_LEFT);            
            break;        
    case OSD_DLG_DCRNOTICE:
              OSDShowNoticeIcon();
            OSDShowSelectPageMainFrame(FrameWidthType_DialogMenu1);
               OSDUpdateKeyInfo(GetOSDState());
            OSDAPI_SetIndentIndex(String_DialogString_Index);
            OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
            OSDAPI_SetFontAttr(NoticeStringColor);
            //ShowIndentString(TRUE, 6, 3, 20, PictureTab[(7*NUM_OSDLANGS)+UserData.ucLanguage]);
            //ShowIndentString(TRUE, 6, 3, 20, DialogDCRTab[UserData.ucLanguage]);    
//UL Justin 140424
            ShowIndentString(TRUE, 6, 2,20, DialogDCRTab[0*NUM_OSDLANGS + UserData.ucLanguage]);
            ShowIndentString(TRUE, 6, 3,20, DialogDCRTab[1*NUM_OSDLANGS + UserData.ucLanguage]);
            ShowIndentString(TRUE, 6, 4,20, DialogDCRTab[2*NUM_OSDLANGS + UserData.ucLanguage]);
    break;                
        default:
        break;    
    }
    UserSetTransparent();
    OSDTurnOnOSD();
    bSelectTable = OSDFontTble1;
}





//******************************************************************************
// Prototype:
//  void OSDShowTopPageIcon(UCHAR id, UCHAR sel, UCHAR CustomerKey)
// Parameters:
// id       : indicate which toppage menu icon to draw
// sel     : indicate where to show the toppage icon, 0 is shown on top of each menu, 1 is shown on top page, 2 is for dialog.
// CustomerKey: indicate which customerkey button pressed and draw the corresponding toppage icon.
// Return:
//  None
// Purpose:
//  Draw toppage menu icon
// Notes:
//  None
//******************************************************************************
void OSDShowTopPageIcon(UCHAR id, UCHAR sel, UCHAR CustomerKey)
{
    UCHAR i;
    UCHAR ucXPos_Line1, ucXPos_Line3;
    UCHAR ucCusYPos;
    BOOL benbleflag = TRUE;

    // a temperary buffer to hold the toppage icon font index
    UCHAR ucTopPageIconBuffer[12] = {0};

    if (CustomerKey == 0) {
        ucCusYPos = 1;
    }
    else if (CustomerKey == 1) {
        ucCusYPos = 5;
    }
    else if (CustomerKey == 2) {
        ucCusYPos = 9;
    }

    if (sel == 0) {
        OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1);
    }
    else if (sel == 2) {
        OSDAPI_SetFontAttr(MAINICON_1BIT_COLOR1);
    }
    else {
        OSDAPI_SetFontAttr(DialogIconColor1);

        if (id == TP_BRIGHTNESS) {
            ucXPos_Line1 = 3;
            ucXPos_Line3 = 3;
        }
        else if (id == TP_CONTRAST) {
            ucXPos_Line1 = 3;
            ucXPos_Line3 = 3;
        }
        else if (id == TP_PICTUREMODE) {
            ucXPos_Line1 = 3;
            ucXPos_Line3 = 2;
        }
        else {
            ucXPos_Line1 = 2;
            ucXPos_Line3 = 2;
        }
    }

    // font index copy to a buffer to save code memory.
    switch (id) {
        case TP_BRIGHTNESS:
            for (i=0; i<(TP_1Bit_Brightness_End-TP_1Bit_Brightness_Start); i++) {
                ucTopPageIconBuffer[i] = TP_1Bit_Brightness_Start+i;
            }
            if (UserData.ucBFMode == PICTURE_MODE_ECO) {
                benbleflag = FALSE;
            }
            if ((UserData.ucDynamicContrast != 0)&&((UserData.ucBFMode == PICTURE_MODE_GAME)||(UserData.ucBFMode == PICTURE_MODE_MOVIE)||(UserData.ucBFMode == PICTURE_MODE_PHOTO))) {
                benbleflag = FALSE;
            }
            break;
        case TP_AUTOADJUSTMENT:
            for (i=0; i<(TP_1Bit_Auto_End-TP_1Bit_Auto_Start); i++) {
                ucTopPageIconBuffer[i] = TP_1Bit_Auto_Start+i;
            }
			#if !lrd_dis_benq
            if ((GetScalerSyncMode(_MainChannel) == DIG_SYNC)||IsComponentInput()) {
                benbleflag = FALSE;
            }
			#endif
            break;
        case TP_CONTRAST:
            for (i=0; i<(TP_1Bit_Contrast_End-TP_1Bit_Contrast_Start); i++) {
                ucTopPageIconBuffer[i] = TP_1Bit_Contrast_Start+i;
            }
            if (UserData.ucBFMode == PICTURE_MODE_ECO) {
                benbleflag = FALSE;
            }
            if ((UserData.ucDynamicContrast != 0)&&((UserData.ucBFMode == PICTURE_MODE_GAME)||(UserData.ucBFMode == PICTURE_MODE_MOVIE)||(UserData.ucBFMode == PICTURE_MODE_PHOTO))) {
                benbleflag = FALSE;
            }
            break;
        case TP_DISPLAYMODE:
            for (i=0; i<(TP_1Bit_DisplayMode_End-TP_1Bit_DisplayMode_Start); i++) {
                ucTopPageIconBuffer[i] = TP_1Bit_DisplayMode_Start+i;
            }
            break;

        case TP_PICTUREMODE:
            for (i=0; i<(TP_1Bit_Picture_End-TP_1Bit_Picture_Start); i++) {
                ucTopPageIconBuffer[i] = TP_1Bit_Picture_Start+i;
            }
            break;
        case TP_EXIT:
            for (i=0; i<(TP_1Bit_Exit_End-TP_1Bit_Exit_Start); i++) {
                ucTopPageIconBuffer[i] = TP_1Bit_Exit_Start+i;
            }
            break;
        case TP_INPUT:
            for (i=0; i<(TP_1Bit_Menu_End-TP_1Bit_Input_Start); i++) {
                ucTopPageIconBuffer[i] = TP_1Bit_Input_Start+i;
            }
            break;
        case TP_MENU:
            for (i=0; i<(TP_1Bit_Menu_End-TP_1Bit_Menu_Start); i++) {
                ucTopPageIconBuffer[i] = TP_1Bit_Menu_Start+i;
            }
            break;
            
    //ULEric140402                    
     case TP_VOLUME:
            if((UserData.bAudioMute)&&(sel == 1)){         
                 for (i=0; i<(TP_1Bit_Mute_End-TP_1Bit_Mute_Start); i++) {
                     ucTopPageIconBuffer[i] = TP_1Bit_Mute_Start+i;
                 }                
             }
            else{
                 for (i=0; i<(TP_1Bit_Volume_End-TP_1Bit_Volume_Start); i++) {
                     ucTopPageIconBuffer[i] = TP_1Bit_Volume_Start+i;
                 }    
            }
            break;
     case TP_MUTE:
            for (i=0; i<(TP_1Bit_Mute_End-TP_1Bit_Mute_Start); i++) {
                ucTopPageIconBuffer[i] = TP_1Bit_Mute_Start+i;
            }
            break;
    case TP_LOWBLUELIGHT:
            for (i=0; i<(TP_1Bit_LowBlueLight_End-TP_1Bit_LowBlueLight_Start); i++) {
                ucTopPageIconBuffer[i] = TP_1Bit_LowBlueLight_Start+i;
            }
            break;
    case TP_SMARTREMINDER:
            for (i=0; i<(TP_1Bit_SmartReminder_End-TP_1Bit_SmartReminder_Start); i++) {
                ucTopPageIconBuffer[i] = TP_1Bit_SmartReminder_Start+i;
            }
            break;        
    }
    bSelectTable = OSDFontTble1;
    if (id == TP_EXIT) {
        OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_EXIT_COLOR);

        OSDAPI_WriteXYString(TRUE, ucExit_PosTab[0*3], ucExit_PosTab[0*3+1], ucExit_PosTab[0*3+2] , &ucTopPageIconBuffer[0]);
        OSDAPI_WriteXYString(TRUE, ucExit_PosTab[1*3], ucExit_PosTab[1*3+1], ucExit_PosTab[1*3+2] , &ucTopPageIconBuffer[ucExit_PosTab[0*3+2]]);
        OSDAPI_WriteXYString(TRUE, ucExit_PosTab[2*3], ucExit_PosTab[2*3+1], ucExit_PosTab[2*3+2] , &ucTopPageIconBuffer[ucExit_PosTab[0*3+2] + ucExit_PosTab[1*3+2]]);

        OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1);
        ShowIndentString(TRUE, ucExit_PosTab[1*3]+4, ucExit_PosTab[1*3+1], 10, TopPageStrTab[id*NUM_OSDLANGS+UserData.ucLanguage]);
    }
    else if (id == TP_MENU) {
            OSDAPI_WriteXYString(TRUE, ucMenu_PosTab[0*3], ucMenu_PosTab[0*3+1], ucMenu_PosTab[0*3+2] , &ucTopPageIconBuffer[0]);
            OSDAPI_WriteXYString(TRUE, ucMenu_PosTab[1*3], ucMenu_PosTab[1*3+1], ucMenu_PosTab[1*3+2] , &ucTopPageIconBuffer[ucMenu_PosTab[0*3+2]]);
            OSDAPI_WriteXYString(TRUE, ucMenu_PosTab[2*3], ucMenu_PosTab[2*3+1], ucMenu_PosTab[2*3+2] , &ucTopPageIconBuffer[ucMenu_PosTab[0*3+2] + ucMenu_PosTab[1*3+2]]);

            ShowIndentString(TRUE, ucMenu_PosTab[1*3]+5, ucMenu_PosTab[1*3+1], 10, TopPageStrTab[id*NUM_OSDLANGS+UserData.ucLanguage]);
    }
    else {
        if (sel == 0) {
            if (benbleflag == TRUE) {
                OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1);
            }
            else {
                OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1_UnSelected);
            }
            OSDAPI_WriteXYString(TRUE, ucTopPageIconInfoTab[id][0*2], ucCusYPos,
                            ucTopPageIconInfoTab[id][0*2+1] , &ucTopPageIconBuffer[0]);

            OSDAPI_WriteXYString(TRUE, ucTopPageIconInfoTab[id][1*2], ucCusYPos+1,
                            ucTopPageIconInfoTab[id][1*2+1] , &ucTopPageIconBuffer[ucTopPageIconInfoTab[id][0*2+1]]);

            OSDAPI_WriteXYString(TRUE, ucTopPageIconInfoTab[id][2*2], ucCusYPos+2,
                            ucTopPageIconInfoTab[id][2*2+1] , &ucTopPageIconBuffer[ucTopPageIconInfoTab[id][0*2+1] + ucTopPageIconInfoTab[id][1*2+1]]);

            ShowIndentString(TRUE, ucTopPageIconInfoTab[id][1*2]+5, ucCusYPos+1, 10, TopPageStrTab[id*NUM_OSDLANGS+UserData.ucLanguage]);
        }
//        else if (sel == 2) {
//            OSDAPI_WriteXYString(TRUE, 2, 2, ucTopPageIconInfoTab[id][0*2+1] , &ucTopPageIconBuffer[0]);
//            OSDAPI_WriteXYString(TRUE, 2, 3, ucTopPageIconInfoTab[id][1*2+1] , &ucTopPageIconBuffer[ucTopPageIconInfoTab[id][0*2+1]]);
//            OSDAPI_WriteXYString(TRUE, 2, 4, ucTopPageIconInfoTab[id][2*2+1] , &ucTopPageIconBuffer[ucTopPageIconInfoTab[id][0*2+1] + ucTopPageIconInfoTab[id][1*2+1]]);
//            ShowIndentString(TRUE, 6, 3, 20, DialogStrTab[id*NUM_OSDLANGS+UserData.ucLanguage]);
//        }
        else {
            OSDAPI_WriteXYString(TRUE, ucXPos_Line1, 4, ucTopPageIconInfoTab[id][0*2+1] , &ucTopPageIconBuffer[0]);
            OSDAPI_WriteXYString(TRUE, 2, 5, ucTopPageIconInfoTab[id][1*2+1] , &ucTopPageIconBuffer[ucTopPageIconInfoTab[id][0*2+1]]);
            OSDAPI_WriteXYString(TRUE, ucXPos_Line3, 6, ucTopPageIconInfoTab[id][2*2+1] , &ucTopPageIconBuffer[ucTopPageIconInfoTab[id][0*2+1] + ucTopPageIconInfoTab[id][1*2+1]]);

            // show dialog title string
            OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1);
            ShowIndentString(TRUE, 1, 1, 13, TopPageStrTab[id*NUM_OSDLANGS+UserData.ucLanguage]);
        }
    }
}

void OSDShowSourceIcon(UCHAR id, UCHAR Source)
{
    
      UCHAR font_index, v_position;
      OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1);      
      if(Source == VGA_SOURCE){
           font_index = Input_VGA_Start;
      }
      else if(Source == DVI_SOURCE){
           font_index = Input_DVI_Start;
      }
      else if(Source == HDMI_SOURCE){
           font_index = Input_HDMI_Start;
      }
      else{
           font_index = Input_DP_Start;
      }

      if(id == 0){
           v_position = 2;
      }
      else if(id == 1){
           v_position = 6;
      }
      else if(id == 2){
           v_position = 10;
      }
      else{
           v_position = 14;
      }
      bSelectTable = OSDFontTble1;
      
      OSDAPI_WriteXYChar(TRUE, 1, v_position, font_index);
      OSDAPI_WriteXYChar(TRUE, 2, v_position, font_index+1);
      OSDAPI_WriteXYChar(TRUE, 3, v_position, font_index+2);
//      OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1);
      ShowIndentString(TRUE, 5, v_position, 6, InputTab1[Source*NUM_OSDLANGS+UserData.ucLanguage]);
    //while(1){ResetWDTimer();}
}

void OSDShowInfo(void)
{
         OSDShowStringSeparater(STRING_LAYER_4, FALSE);
         
        // show layer 4 string
#if LAYER_INDENT_COUNT == ON
        fnResetLayerIndentCount(STRING_LAYER_4);
        OSDAPI_SetIndentIndex(fnGetLayerIndentCount(STRING_LAYER_4));
        //OSDAPI_SetIndentIndex(320);

#else
        OSDAPI_SetIndentIndex(String_Layer4_Index);
#endif
        OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
        OSDAPI_SetFontAttr(UnSelectedStringColor_256);   
        //OSDShowLowBlueLightStrings(id);
        // Show Layer 4 hook icon
        //OSDShowHookIcon(HookIconColor1_256, id, STRING_LAYER_4, Hook_Icon);
        //InputTab1
        ShowIndentString(TRUE, ucLayer4ItemInfoTb[1], ucLayer4ItemInfoTb[2], INDENT_STRING_MAX_LEN-2, InputTab1[(GetInputPortIndex(UserData.ucInputSource)*NUM_OSDLANGS+UserData.ucLanguage)]);
        OSDShowCurrentResolution(ucLayer4ItemInfoTb[1],ucLayer4ItemInfoTb[2]+2);
        OSDShowOptimumResolution(ucLayer4ItemInfoTb[1],ucLayer4ItemInfoTb[2]+4);
        ShowIndentString(TRUE, ucLayer4ItemInfoTb[1], ucLayer4ItemInfoTb[2]+6, INDENT_STRING_MAX_LEN-2, ModelWordStrTab[0]);
     
}

void ClrLayer4(void) //ULEric140415
{
    UCHAR i;
    //if (ClrLayer4Flags == TRUE) {
        //ClrLayer4Flags = FALSE;
        OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
        for (i=0; i<19; i++)
           OSDAPI_WriteXYRepeatChar(TRUE, 47, 3+i, INDENT_STRING_MAX_LEN, _SPACE_);            
           //printf("ClearLayer4\r\n");            
    //}
}
