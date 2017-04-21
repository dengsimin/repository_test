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

#if LAYER_INDENT_COUNT == ON
LayerIndentInfo LayerIndentInfoTab[4];
#endif

// layer1~4 window position table
// pixel unit based
USHRT usLayer1WinPosTab[] = {
// start x, start y, end x, end y
12+7, 18*3+9, 12+7+12*16+7, 18*3+9+18*17+13
};

USHRT usLayer2WinPosTab[] = {
// start x, start y, end x, end y
12*18+6, 18*3+9, 12*18+5+12*13+9, 18*3+9+18*17+13
};

USHRT usLayer3WinPosTab[] = {
// start x, start y, end x, end y
12*32+6, 18*3+9, 12*32+5+12*13+9, 18*3+9+18*17+13
};

USHRT usLayer4WinPosTab[] = {
// start x, start y, end x, end y
12*46+6, 18*3+9, 12*46+5+12*13+9, 18*3+9+18*17+13
};

USHRT usDialogLayerWinPosTab[] = {
// start x, start y, end x, end y
90, 63, 262, 382
};

USHRT usDialog2LayerWinPosTab[] = {
// start x, start y, end x, end y
90, 63, 160, 382
};

USHRT usClrTempWinPosTab[] = {
// start x, start y, end x, end y
12*46+9, 18*3, 12*62+9, 18*19+17
};


UCHAR ucLayer4ItemLowBlueLightInfoTb[3] = {
    // item count, X start position, Y start position
    4, 47, 5,
};

static UCHAR ucTemp_BFMode = 0;
static USHRT usTemp_ReShow = 0;//ULEric140331
static BOOL bIsRepeatKey = FALSE;//ULEric140409
static UCHAR ucKeyInfoStatus = 0xff;//ULEric140409
UCHAR OSD_Select_Temp;
BOOL bOSD_Select_Temp;
BOOL bShowInputNovitceFlag = TRUE;
BOOL bShortOOLTimer;
//ULEric140327
static BOOL OSDCheckHookIcon(void)
{
    BOOL Result = FALSE;
    USHRT usOSDStateTemp = GetOSDState();
    if(usOSDStateTemp == OSD_MAIN_1_1_STATE)
        Result = TRUE;
    if(usOSDStateTemp >=  OSD_ITEM_1_2_1_STATE && usOSDStateTemp < OSD_ITEM_1_2_END)
        Result = TRUE;
    if(usOSDStateTemp >=  OSD_ITEM_2_4_1_STATE && usOSDStateTemp < OSD_ITEM_2_5_END)
        Result = TRUE;
    if(usOSDStateTemp >=  OSD_ITEM_2_8_1_STATE && usOSDStateTemp < OSD_ITEM_2_9_END)
        Result = TRUE;
    if(usOSDStateTemp >=  OSD_ITEM_3_1_1_STATE && usOSDStateTemp < OSD_ITEM_3_2_END)
        Result = TRUE;
    if(usOSDStateTemp >=  OSD_ITEM_3_4_1_STATE && usOSDStateTemp < OSD_ITEM_3_7_END)
        Result = TRUE;
    if(usOSDStateTemp >=  OSD_ITEM_Audio_2_1_STATE && usOSDStateTemp < OSD_ITEM_Audio_3_END)
        Result = TRUE;
    if(usOSDStateTemp >=  OSD_ITEM_4_2_1_STATE && usOSDStateTemp < OSD_ITEM_ERGO_END)//ULEric140407
        Result = TRUE;
    if(usOSDStateTemp >=  OSD_SUBITEM_3_1_2_STATE_BEG && usOSDStateTemp < OSD_SUBITEM_4_1_2_END)//ULEric140407
        Result = TRUE;
    return Result;
}

//ULEric140328
#define OSDKEYINFO_UP BIT0
#define OSDKEYINFO_DN BIT1
#define OSDKEYINFO_RT BIT2
#define OSDKEYINFO_LT BIT3
#define OSDKEYINFO_EXIT BIT4
#define OSDKEYINFO_OK BIT5
#define OSDKEYINFO_TYPE_UDRLE (OSDKEYINFO_UP|OSDKEYINFO_DN|OSDKEYINFO_RT|OSDKEYINFO_LT)
#define OSDKEYINFO_TYPE_UDOLE (OSDKEYINFO_UP|OSDKEYINFO_DN|OSDKEYINFO_OK|OSDKEYINFO_LT)
#define OSDKEYINFO_TYPE_DRLE (OSDKEYINFO_DN|OSDKEYINFO_RT|OSDKEYINFO_LT)
#define OSDKEYINFO_TYPE_URLE (OSDKEYINFO_UP|OSDKEYINFO_RT|OSDKEYINFO_LT)
#define OSDKEYINFO_TYPE_UDLE (OSDKEYINFO_UP|OSDKEYINFO_DN|OSDKEYINFO_LT)
#define OSDKEYINFO_TYPE_DOLE (OSDKEYINFO_DN|OSDKEYINFO_OK|OSDKEYINFO_LT)
#define OSDKEYINFO_TYPE_UOLE (OSDKEYINFO_UP|OSDKEYINFO_OK|OSDKEYINFO_LT)
#define OSDKEYINFO_TYPE_DIALOG (OSDKEYINFO_OK|OSDKEYINFO_EXIT)//ULEric140410
#define OSDKEYINFO_TYPE_RLE (OSDKEYINFO_RT|OSDKEYINFO_LT)//ULEric140415
#define OSDKEYINFO_TYPE_LOK (OSDKEYINFO_LT|OSDKEYINFO_OK)

void OSDUpdateKeyInfo(USHRT usOsdState)
{
    UCHAR ucLayer = 0;
    UCHAR ucKeyInfoType = 0;
    UCHAR ucOffset = 0;
    if(usOsdState>=OSD_MAIN_BEG&&usOsdState<OSD_MAIN_END)//LAYER_1 OSD
    {
        ucLayer = STRING_LAYER_1;
        ucKeyInfoType = OSDKEYINFO_TYPE_UDRLE; 
    }
    else if(usOsdState>=OSD_MAIN_1_1_STATE&&usOsdState<OSD_MAIN_ERGO_END)//LAYER_2 OSD
    {
        ucLayer = STRING_LAYER_2;
        if(usOsdState == OSD_MAIN_1_1_STATE)
            ucKeyInfoType = OSDKEYINFO_TYPE_UDOLE;
        else if(usOsdState == OSD_MAIN_2_1_STATE||usOsdState == OSD_MAIN_4_1_STATE)//TOP
            ucKeyInfoType = OSDKEYINFO_TYPE_DRLE;
        else if(usOsdState == OSD_MAIN_2_9_STATE||usOsdState == OSD_MAIN_4_12_STATE)//BUTTOM
            ucKeyInfoType = OSDKEYINFO_TYPE_URLE;
        else if(usOsdState == OSD_MAIN_4_10_STATE)
            ucKeyInfoType = OSDKEYINFO_TYPE_UDLE;
        else if((usOsdState == OSD_MAIN_1_2_STATE) && ((UserData.ucInputSource != INPUT_SC_VGA)||IsComponentInput()))//ULEric140415
            ucKeyInfoType = OSDKEYINFO_TYPE_RLE;
        else if((usOsdState == OSD_MAIN_2_3_STATE) && (!OSDIsSubItemValid(OSD_PICTURE_BRIGHTNESS)))//ULEric140415
            ucKeyInfoType = OSDKEYINFO_TYPE_DRLE;
        else if((usOsdState == OSD_MAIN_ERGO_1_STATE)&&(UserData.bSmartReminder == OFF)){
            ucKeyInfoType = OSDKEYINFO_TYPE_RLE;
        }            
        else    
            ucKeyInfoType = OSDKEYINFO_TYPE_UDRLE;
        
    }
    else if(usOsdState>=OSD_ITEM_1_1_STATE&&usOsdState<OSD_ITEM_ERGO_END)////LAYER_3 OSD
    {
        ucLayer = STRING_LAYER_3;
        if(usOsdState>=OSD_ITEM_1_3_STATE&&usOsdState<=OSD_ITEM_1_6_STATE)
            ucKeyInfoType = OSDKEYINFO_TYPE_UDLE;
        else if(usOsdState>=OSD_ITEM_2_1_STATE&&usOsdState<=OSD_ITEM_2_3_STATE)
            ucKeyInfoType = OSDKEYINFO_TYPE_UDLE;
        else if(usOsdState>=OSD_ITEM_2_6_STATE&&usOsdState<=OSD_ITEM_2_7_STATE)
            ucKeyInfoType = OSDKEYINFO_TYPE_UDLE;
        else if(usOsdState==OSD_ITEM_3_3_STATE||usOsdState==OSD_ITEM_Audio_1_1_STATE)
            ucKeyInfoType = OSDKEYINFO_TYPE_UDLE;
        else if(usOsdState==OSD_ITEM_4_1_1_STATE||usOsdState==OSD_ITEM_4_1_2_STATE||usOsdState==OSD_ITEM_3_1_2_STATE||usOsdState == OSD_ITEM_2_5_4_STATE)//ULEric140407
            ucKeyInfoType = OSDKEYINFO_TYPE_UDRLE;
        else if(usOsdState==OSD_ITEM_4_2_2_STATE) { //customer key1
            if ((UserData.ucCustomerKey2 == CUSTOMER_KEY_LOWBULELIGHTMODE) || (UserData.ucCustomerKey3 == CUSTOMER_KEY_LOWBULELIGHTMODE))
                ucKeyInfoType = OSDKEYINFO_TYPE_DOLE;
            else
                ucKeyInfoType = OSDKEYINFO_TYPE_UDOLE;
        }
        else if(usOsdState==OSD_ITEM_4_3_2_STATE) { //customer key2
            if ((UserData.ucCustomerKey1 == CUSTOMER_KEY_LOWBULELIGHTMODE) || (UserData.ucCustomerKey3 == CUSTOMER_KEY_LOWBULELIGHTMODE))
                ucKeyInfoType = OSDKEYINFO_TYPE_DOLE;
            else
                ucKeyInfoType = OSDKEYINFO_TYPE_UDOLE;
        }
        else if(usOsdState==OSD_ITEM_4_4_2_STATE) { //customer key3
            if ((UserData.ucCustomerKey1 == CUSTOMER_KEY_LOWBULELIGHTMODE) || (UserData.ucCustomerKey2 == CUSTOMER_KEY_LOWBULELIGHTMODE))
                ucKeyInfoType = OSDKEYINFO_TYPE_DOLE;
            else
                ucKeyInfoType = OSDKEYINFO_TYPE_UDOLE;
        }
        else if(usOsdState==OSD_ITEM_4_2_3_STATE) { //customer key1
            if (((UserData.ucCustomerKey2 == CUSTOMER_KEY_LOWBULELIGHTMODE) && (UserData.ucCustomerKey3 == CUSTOMER_KEY_PICTUREMODE)) ||\
                ((UserData.ucCustomerKey3 == CUSTOMER_KEY_LOWBULELIGHTMODE) && (UserData.ucCustomerKey2 == CUSTOMER_KEY_PICTUREMODE)))
                ucKeyInfoType = OSDKEYINFO_TYPE_DOLE;
            else
                ucKeyInfoType = OSDKEYINFO_TYPE_UDOLE;
        }
        else if(usOsdState==OSD_ITEM_4_3_3_STATE) { //customer key2
            if (((UserData.ucCustomerKey1 == CUSTOMER_KEY_LOWBULELIGHTMODE) && (UserData.ucCustomerKey3 == CUSTOMER_KEY_PICTUREMODE)) ||\
                ((UserData.ucCustomerKey3 == CUSTOMER_KEY_LOWBULELIGHTMODE) && (UserData.ucCustomerKey1 == CUSTOMER_KEY_PICTUREMODE)))
                ucKeyInfoType = OSDKEYINFO_TYPE_DOLE;
            else
                ucKeyInfoType = OSDKEYINFO_TYPE_UDOLE;
        }
        else if(usOsdState==OSD_ITEM_4_4_3_STATE) { //customer key3
            if (((UserData.ucCustomerKey1 == CUSTOMER_KEY_LOWBULELIGHTMODE) && (UserData.ucCustomerKey2 == CUSTOMER_KEY_PICTUREMODE)) ||\
                ((UserData.ucCustomerKey2 == CUSTOMER_KEY_LOWBULELIGHTMODE) && (UserData.ucCustomerKey1 == CUSTOMER_KEY_PICTUREMODE)))
                ucKeyInfoType = OSDKEYINFO_TYPE_DOLE;
            else
                ucKeyInfoType = OSDKEYINFO_TYPE_UDOLE;
        }
        else if(usOsdState==OSD_ITEM_4_2_8_STATE) { //customer key1
            if (((UserData.ucCustomerKey2 == CUSTOMER_KEY_INPUT) && (UserData.ucCustomerKey3 == CUSTOMER_KEY_SMARTREMINDER)) ||\
                ((UserData.ucCustomerKey3 == CUSTOMER_KEY_INPUT) && (UserData.ucCustomerKey2 == CUSTOMER_KEY_SMARTREMINDER)))
                ucKeyInfoType = OSDKEYINFO_TYPE_UOLE;
            else
                ucKeyInfoType = OSDKEYINFO_TYPE_UDOLE;
        }
        else if(usOsdState==OSD_ITEM_4_3_8_STATE) { //customer key2
            if (((UserData.ucCustomerKey1 == CUSTOMER_KEY_INPUT) && (UserData.ucCustomerKey3 == CUSTOMER_KEY_SMARTREMINDER)) ||\
                ((UserData.ucCustomerKey3 == CUSTOMER_KEY_INPUT) && (UserData.ucCustomerKey1 == CUSTOMER_KEY_SMARTREMINDER)))
                ucKeyInfoType = OSDKEYINFO_TYPE_UOLE;
            else
                ucKeyInfoType = OSDKEYINFO_TYPE_UDOLE;
        }
        else if(usOsdState==OSD_ITEM_4_4_8_STATE) { //customer key3
            if (((UserData.ucCustomerKey1 == CUSTOMER_KEY_INPUT) && (UserData.ucCustomerKey2 == CUSTOMER_KEY_SMARTREMINDER)) ||\
                ((UserData.ucCustomerKey2 == CUSTOMER_KEY_INPUT) && (UserData.ucCustomerKey1 == CUSTOMER_KEY_SMARTREMINDER)))
                ucKeyInfoType = OSDKEYINFO_TYPE_UOLE;
            else
                ucKeyInfoType = OSDKEYINFO_TYPE_UDOLE;
        }
        else if(usOsdState==OSD_ITEM_4_2_9_STATE) { //customer key1
            if ((UserData.ucCustomerKey2 == CUSTOMER_KEY_SMARTREMINDER) || (UserData.ucCustomerKey3 == CUSTOMER_KEY_SMARTREMINDER))
                ucKeyInfoType = OSDKEYINFO_TYPE_UOLE;
            else
                ucKeyInfoType = OSDKEYINFO_TYPE_UDOLE;
        }
        else if(usOsdState==OSD_ITEM_4_3_9_STATE) { //customer key2
            if ((UserData.ucCustomerKey1 == CUSTOMER_KEY_SMARTREMINDER) || (UserData.ucCustomerKey3 == CUSTOMER_KEY_SMARTREMINDER))
                ucKeyInfoType = OSDKEYINFO_TYPE_UOLE;
            else
                ucKeyInfoType = OSDKEYINFO_TYPE_UDOLE;
        }
        else if(usOsdState==OSD_ITEM_4_4_9_STATE) { //customer key3
            if ((UserData.ucCustomerKey1 == CUSTOMER_KEY_SMARTREMINDER) || (UserData.ucCustomerKey2 == CUSTOMER_KEY_SMARTREMINDER))
                ucKeyInfoType = OSDKEYINFO_TYPE_UOLE;
            else
                ucKeyInfoType = OSDKEYINFO_TYPE_UDOLE;
        }
        else if(usOsdState==OSD_ITEM_4_2_1_STATE||usOsdState==OSD_ITEM_4_3_1_STATE||usOsdState==OSD_ITEM_4_4_1_STATE/*||usOsdState==OSD_ITEM_3_1_1_STATE*/)//ULEric140411
            ucKeyInfoType = OSDKEYINFO_TYPE_DOLE;
        else if(usOsdState==OSD_ITEM_4_2_10_STATE||usOsdState==OSD_ITEM_4_3_10_STATE||usOsdState==OSD_ITEM_4_4_10_STATE/*||usOsdState==OSD_ITEM_3_1_9_STATE*/)//ULEric140411
            ucKeyInfoType = OSDKEYINFO_TYPE_UOLE;
		#if !lrd_dis_benq
        else if((usOsdState == OSD_ITEM_3_5_2_STATE) && ((MDState[_MainChannel].InputTiming.usModeVActive == PANEL_HEIGHT)&&(MDState[_MainChannel].InputTiming.usModeHActive == PANEL_WIDTH))){
            ucKeyInfoType = OSDKEYINFO_TYPE_LOK;
           } 
		#endif
        else{
            ucKeyInfoType = OSDKEYINFO_TYPE_UDOLE;
            }
    }
        else if(usOsdState>=OSD_SUBITEM_2_5_4_STATE_BEG&&usOsdState<OSD_SUBITEM_4_1_2_END){ //LAYER_4 OSD
            ucLayer = STRING_LAYER_4;
        if(usOsdState==OSD_SUBITEM_4_1_1_1_STATE)
            ucKeyInfoType = OSDKEYINFO_TYPE_DOLE;
        else if(usOsdState==OSD_SUBITEM_4_1_1_17_STATE)
            ucKeyInfoType = OSDKEYINFO_TYPE_UOLE;
        else if(usOsdState==OSD_SUBITEM_2_5_4_1_STATE||usOsdState==OSD_SUBITEM_2_5_4_2_STATE)//ULEric140407
            ucKeyInfoType = OSDKEYINFO_TYPE_UDRLE;
        else if(usOsdState==OSD_SUBITEM_2_5_4_3_STATE)//ULEric140407
            ucKeyInfoType = OSDKEYINFO_TYPE_UDLE;
        else //if(usOsdState>=OSD_SUBITEM_4_1_1_2_STATE&&usOsdState<=OSD_SUBITEM_4_1_1_16_STATE)
            ucKeyInfoType = OSDKEYINFO_TYPE_UDOLE;
    }
    /*
    else if ((usOsdState == OSD_CUSTKEY_DISPLAYMODE_2_STATE) && ((MDState[_MainChannel].InputTiming.usModeVActive == PANEL_HEIGHT)&&(MDState[_MainChannel].InputTiming.usModeHActive == PANEL_WIDTH))) {
        ucLayer = DIALOG_LAYER;
        ucKeyInfoType = OSDKEYINFO_TYPE_DIALOG;
        ucOffset = 3;
    }
    */
    else if(usOsdState == OSD_INFO_RESETALL_NOTICE_STATE||usOsdState == OSD_INFO_RESETCOLOR_NOTICE_STATE ||usOsdState == OSD_INFO_DCR_NOTICE_STATE){
        ucLayer = DIALOG_LAYER;
        ucKeyInfoType = OSDKEYINFO_TYPE_DIALOG;
        ucOffset = 3;
    }
    else{
        ucLayer = 0xff;
    }
    if(ucLayer!=0xff && !bIsRepeatKey) {
        OSDUpdateSelectPageIcon(0,ucOffset,ucKeyInfoType,ucLayer,0);
    }
}

#if 0
void OSDShowItemHookIcon(UCHAR id,UCHAR ucPosX,UCHAR ucPosY,UCHAR ucCheckValue)
{    
    UCHAR ucCheckHook;
 
    ucCheckHook = ucCheckValue;
            
    if((ucCheckHook/8) == (id/8))
        {
        if(id == ucCheckHook)//Selected
            OSDAPI_SetFontAttr(SelectedStringColor_256);
        else
            OSDAPI_SetFontAttr(UnSelectedStringColor1_256);
        OSDAPI_WriteXYChar(TRUE, ucPosX+11, ucPosY+(ucCheckHook-((ucCheckHook/8)*8))*2, Hook_Icon);
    }else{
        OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);//ULEric140401
        OSDAPI_WriteXYChar(TRUE, ucPosX+11, ucPosY+(ucCheckHook-((ucCheckHook/8)*8))*2, _SPACE_);
    }    
}
#endif
void SetReShowMenuIdx(USHRT usReShowIdx)
{
    
    usTemp_ReShow = usReShowIdx;
}
    
void OSDReShowMenu(void)
{    
    UCHAR i;
    OSDAPI_TurnOffOSD();
    OSDInitialize(TRUE);

    OSDInitFrame(OSD_MAIN_WIDTH, OSD_MAIN_HEIGHT, MAIN_FRAME_COLOR);

    OSDShowBenQMainFrame(FrameWidthType_MainMenu);
    OSDShowSelectPageMainFrame(FrameWidthType_MainMenu);
    for (i=0; i<5; i++){
        OSDShowSelectPageIcon(i, 0);
    }
    OSDShowBigWin(OSD_BG_WIN, OSD_WIN_BOARDER_SIZE);
    OSDShowStringSeparater(STRING_LAYER_1, FALSE);
    OSDShowStringSeparater(STRING_LAYER_2, FALSE);
    
    for (i=0; i<MAINMENU_ICON_NUM; i++) {
        OSDShowMainMenuIcon(i);
    }
    
    OSDShowBigWin(OSD_LAYER1_WIN, OSD_WIN_BOARDER_SIZE);
    
    OSDAPI_SetIndentIndex(String_Layer1_Index);
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    bSelectTable = OSDFontTble1;
    OSDShowTitleString();   
    OSDAPI_SetIndentIndex(String_Layer1_Index + 20);       
    OSDAPI_SetFontAttr(UnSelectedStringColor1);    
    OSDShowMainMenuStrings();

#if LAYER_INDENT_COUNT == ON
    // after showing layer1 string, the layer2 string start index is fixed and has been recorded by below function.
    fnResetLayerIndentCount(STRING_LAYER_2);
#endif

    switch(usTemp_ReShow)
    {
        case OSD_MAIN_4_2_STATE:
            OSDSelectLayer1Item(OSD_MAIN_SYSTEM);
            OSDClrLayer1Menu(OSD_MAIN_SYSTEM);
            OSDSelectLayer2Item(OSD_SYS_CTKEY1, FALSE);
            ucSubMenuType = OSD_SYS_CTKEY1;     
        break;
        case OSD_MAIN_4_3_STATE:
            OSDSelectLayer1Item(OSD_MAIN_SYSTEM);
            OSDClrLayer1Menu(OSD_MAIN_SYSTEM);
            OSDSelectLayer2Item(OSD_SYS_CTKEY2, FALSE);
            ucSubMenuType = OSD_SYS_CTKEY2;     
        break;
        case OSD_MAIN_4_4_STATE:
            OSDSelectLayer1Item(OSD_MAIN_SYSTEM);
            OSDClrLayer1Menu(OSD_MAIN_SYSTEM);
            OSDSelectLayer2Item(OSD_SYS_CTKEY3, FALSE);
            ucSubMenuType = OSD_SYS_CTKEY3;     
        break;
        case OSD_MAIN_4_12_STATE:
            OSDSelectLayer1Item(OSD_MAIN_SYSTEM);
            OSDClrLayer1Menu(OSD_MAIN_SYSTEM);
            OSDUnselectLayer2Item(OSD_SYS_AUTO_POWEROFF, FALSE);
            OSDSelectLayer2Item(OSD_SYS_RES,FALSE);
            OSDUnselectLayer2Item(OSD_SYS_RES, FALSE);
            OSDSelectLayer2Item(OSD_SYS_RECALL, FALSE);
            ucSubMenuType = OSD_SYS_RECALL;          
        break;
        case OSD_MAIN_2_8_STATE:
            OSDSelectLayer1Item(OSD_MAIN_PICTURE);
            OSDClrLayer1Menu(OSD_MAIN_PICTURE);
            OSDSelectLayer2Item(OSD_PICTURE_RESETCOLOR, FALSE);
            ucSubMenuType = OSD_PICTURE_RESETCOLOR; 
        break;    
        case OSD_ITEM_3_3_STATE://ULEric140414
            OSDSelectLayer1Item(OSD_MAIN_PICTURE_ADVANCED);
            OSDClrLayer1Menu(OSD_MAIN_PICTURE_ADVANCED);
            OSDSelectLayer2Item(OSD_PICTURE_AD_DCR, FALSE);
            OSDClrLayer2Menu(OSD_PICTURE_AD_DCR);    
            ucSubMenuType = OSD_PICTURE_AD_DCR;    
            OSDSelectLayer3Item(0);
            OSDFocusItm33();
        break;            
        default:
        break;
    };
    
    UserSetTransparent();
    OSDSetPosition(OSD_MAIN_MENU_H_POSITION,OSD_MAIN_MENU_V_POSITION);//zoe test    
    
    SetOSDState(usTemp_ReShow);

    OSDAPI_TurnOnOSD();
        
}

//ULEric140401
void OSDUpdateArrowIcon(USHRT usAttr, UCHAR ucType,UCHAR ucLayer)
{
    UCHAR ucPosX;
    if(ucLayer == STRING_LAYER_3)
        ucPosX = 38;
    else if(ucLayer == STRING_LAYER_4)
        ucPosX = 52;
    else
        return;
        
    OSDAPI_SetFontAttr(usAttr);
    if(ucType == TopArrowType){    
        // show down arrow           
        OSDAPI_WriteXYChar(TRUE, ucPosX, 20, DownArrow_1);
        OSDAPI_WriteXYChar(TRUE, ucPosX+1, 20, DownArrow_2);
        OSDAPI_WriteXYChar(TRUE, ucPosX+1, 21, DownArrow_3);
        // clear up arrow
        OSDAPI_WriteXYRepeatChar(TRUE, ucPosX, 3, 2, _SPACE_);
    }else if(ucType == MiddleArrowType){
        OSDAPI_WriteXYChar(TRUE, ucPosX, 3, UpArrow_1);
        OSDAPI_WriteXYChar(TRUE, ucPosX+1, 3, UpArrow_2);
        // show down arrow
        OSDAPI_WriteXYChar(TRUE, ucPosX, 20, DownArrow_1);
        OSDAPI_WriteXYChar(TRUE, ucPosX+1, 20, DownArrow_2);
        OSDAPI_WriteXYChar(TRUE, ucPosX+1, 21, DownArrow_3);
    }else if(ucType == LastArrowType){
        // show up arrow
        OSDAPI_WriteXYChar(TRUE, ucPosX, 3, UpArrow_1);
        OSDAPI_WriteXYChar(TRUE, ucPosX+1, 3, UpArrow_2);
        // clear down arrow
        OSDAPI_WriteXYRepeatChar(TRUE, ucPosX, 20, 2, _SPACE_);
        OSDAPI_WriteXYRepeatChar(TRUE, ucPosX, 21, 2, _SPACE_);
    }else{//Clear
        // clear up arrow
        OSDAPI_WriteXYRepeatChar(TRUE, ucPosX, 3, 2, _SPACE_);
        // clear down arrow
        OSDAPI_WriteXYRepeatChar(TRUE, ucPosX, 20, 2, _SPACE_);
        OSDAPI_WriteXYRepeatChar(TRUE, ucPosX, 21, 2, _SPACE_);
    }
}
//ULEric140402
void OSDShowCusLowBlueLightStrings(void)
{
    UCHAR i;
    for (i=0; i<4; i++) {
        ShowIndentString(TRUE, 8, 5+(i*2), INDENT_STRING_MAX_LEN-2, LowBlueLightTab[i*NUM_OSDLANGS+UserData.ucLanguage]);
    }
}

//ULEric140409
void OSDClearKeyColor(BOOL bIsRepratKey)
{    
    UCHAR ucTempOSDStatus = GetOSDState();
    //if(bIsRepeatKey!=bIsRepratKey)
    //{
        bIsRepeatKey = bIsRepratKey;        
        if(!bIsRepeatKey)
        {
            //printf("Set RepeatKey OFF\r\n");
            if(ucKeyInfoStatus!=0xff)
            {
                //printf("OSDBlinkSelectPageButton(%BX,%BX);\r\n",(ucKeyInfoStatus&0x0F),(ucKeyInfoStatus>>4));
                if (ucTempOSDStatus > OSD_TOPPAGE_BEG && ucTempOSDStatus <= OSD_DIRECT_3_STATE)
                {
                    //Sleep(60);
                    OSDBlinkSelectPageButton((ucKeyInfoStatus&0x0F), (ucKeyInfoStatus>>4), TRUE);
                    OSDUpdateKeyInfo(ucTempOSDStatus);
                }
                ucKeyInfoStatus = 0xff;                
            }
        }
        //else{
            //printf("Set RepeatKey On\r\n");
        //}
    //}    
}

//ULEric140409
static BOOL OSDCheckNonBlinkItem(UCHAR id,BOOL Clr)
{
    BOOL Result = FALSE;
    USHRT usStatus = GetOSDState();
    switch(id)
    {
        case 0://Up
        if((usStatus == OSD_MAIN_2_1_STATE||usStatus == OSD_MAIN_4_1_STATE)&&!Clr)//Layer2
            Result = TRUE;
        else if((usStatus == OSD_ITEM_3_1_1_STATE) && !Clr)//Layer3 //ULEric140411
            Result = TRUE;
        else if((usStatus == OSD_SUBITEM_4_1_1_1_STATE) && !Clr)//Layer4
            Result = TRUE;
        else if((usStatus == OSD_MAIN_1_2_STATE) && ((UserData.ucInputSource != INPUT_SC_VGA)||IsComponentInput()) && !Clr)//ULEric140415
            Result = TRUE;
        else if((usStatus == OSD_MAIN_2_3_STATE) && (!OSDIsSubItemValid(OSD_PICTURE_BRIGHTNESS)) && !Clr)//ULEric140415
            Result = TRUE;    
		#if !lrd_dis_benq
        else if((usStatus == OSD_ITEM_3_5_2_STATE || usStatus == OSD_CUSTKEY_DISPLAYMODE_2_STATE) && ((MDState[_MainChannel].InputTiming.usModeVActive == PANEL_HEIGHT)&&(MDState[_MainChannel].InputTiming.usModeHActive == PANEL_WIDTH)) && !Clr)
            Result = TRUE;
		#endif
        else if((usStatus == OSD_ITEM_4_2_1_STATE)&&!Clr)
            Result = TRUE;
        else if((usStatus == OSD_ITEM_4_3_1_STATE)&&!Clr)
            Result = TRUE;
        else if((usStatus == OSD_ITEM_4_4_1_STATE)&&!Clr)
            Result = TRUE;        
        //--
        else if((usStatus == OSD_ITEM_4_2_2_STATE)&&!Clr) { //customer key1
            if ((UserData.ucCustomerKey2 == CUSTOMER_KEY_LOWBULELIGHTMODE) || (UserData.ucCustomerKey3 == CUSTOMER_KEY_LOWBULELIGHTMODE))
                Result = TRUE;
        }
        else if((usStatus == OSD_ITEM_4_3_2_STATE)&&!Clr) { //customer key2
            if ((UserData.ucCustomerKey1 == CUSTOMER_KEY_LOWBULELIGHTMODE) || (UserData.ucCustomerKey3 == CUSTOMER_KEY_LOWBULELIGHTMODE))
                Result = TRUE;
        }
        else if((usStatus == OSD_ITEM_4_4_2_STATE)&&!Clr) { //customer key3
            if ((UserData.ucCustomerKey1 == CUSTOMER_KEY_LOWBULELIGHTMODE) || (UserData.ucCustomerKey2 == CUSTOMER_KEY_LOWBULELIGHTMODE))
                Result = TRUE;
        }
        //--
        else if((usStatus == OSD_ITEM_4_2_3_STATE)&&!Clr) { //customer key1
            if (((UserData.ucCustomerKey2 == CUSTOMER_KEY_LOWBULELIGHTMODE) && (UserData.ucCustomerKey3 == CUSTOMER_KEY_PICTUREMODE)) ||\
                ((UserData.ucCustomerKey3 == CUSTOMER_KEY_LOWBULELIGHTMODE) && (UserData.ucCustomerKey2 == CUSTOMER_KEY_PICTUREMODE)))                
                Result = TRUE;
        }
        else if((usStatus == OSD_ITEM_4_3_3_STATE)&&!Clr) { //customer key2
            if (((UserData.ucCustomerKey1 == CUSTOMER_KEY_LOWBULELIGHTMODE) && (UserData.ucCustomerKey3 == CUSTOMER_KEY_PICTUREMODE)) ||\
                ((UserData.ucCustomerKey3 == CUSTOMER_KEY_LOWBULELIGHTMODE) && (UserData.ucCustomerKey1 == CUSTOMER_KEY_PICTUREMODE)))
                Result = TRUE;
        }
        else if((usStatus == OSD_ITEM_4_4_3_STATE)&&!Clr) { //customer key3
            if (((UserData.ucCustomerKey1 == CUSTOMER_KEY_LOWBULELIGHTMODE) && (UserData.ucCustomerKey2 == CUSTOMER_KEY_PICTUREMODE)) ||\
                ((UserData.ucCustomerKey2 == CUSTOMER_KEY_LOWBULELIGHTMODE) && (UserData.ucCustomerKey1 == CUSTOMER_KEY_PICTUREMODE)))
                Result = TRUE;
        }
            else if((usStatus == OSD_MAIN_ERGO_1_STATE)&&!Clr){
                if(UserData.bSmartReminder == OFF){
                    Result = TRUE;
                }
            }
        //--
        break;

        case 1://Down
        if((usStatus == OSD_MAIN_2_9_STATE||usStatus == OSD_MAIN_4_12_STATE)&&!Clr)//Layer2
            Result = TRUE;
        else if((usStatus == OSD_ITEM_3_1_9_STATE) && !Clr)//Layer3 //ULEric140411
            Result = TRUE;
        else if((usStatus == OSD_SUBITEM_4_1_1_17_STATE) && !Clr)//Layer4
            Result = TRUE;
        else if((usStatus == OSD_MAIN_1_2_STATE) && ((UserData.ucInputSource != INPUT_SC_VGA)||IsComponentInput()) && !Clr)//ULEric140415
            Result = TRUE;
		
#if !lrd_dis_benq
        else if((usStatus == OSD_ITEM_3_5_2_STATE || usStatus == OSD_CUSTKEY_DISPLAYMODE_2_STATE) && ((MDState[_MainChannel].InputTiming.usModeVActive == PANEL_HEIGHT)&&(MDState[_MainChannel].InputTiming.usModeHActive == PANEL_WIDTH)) && !Clr)
            Result = TRUE;
#endif
        //--
        else if((usStatus == OSD_ITEM_4_2_8_STATE)&&!Clr) { //customer key1
            if (((UserData.ucCustomerKey2 == CUSTOMER_KEY_INPUT) && (UserData.ucCustomerKey3 == CUSTOMER_KEY_SMARTREMINDER)) ||\
                ((UserData.ucCustomerKey3 == CUSTOMER_KEY_INPUT) && (UserData.ucCustomerKey2 == CUSTOMER_KEY_SMARTREMINDER)))
                Result = TRUE;
        }
        else if((usStatus == OSD_ITEM_4_3_8_STATE)&&!Clr) { //customer key2
            if (((UserData.ucCustomerKey1 == CUSTOMER_KEY_INPUT) && (UserData.ucCustomerKey3 == CUSTOMER_KEY_SMARTREMINDER)) ||\
                ((UserData.ucCustomerKey3 == CUSTOMER_KEY_INPUT) && (UserData.ucCustomerKey1 == CUSTOMER_KEY_SMARTREMINDER)))
                Result = TRUE;
        }
        else if((usStatus == OSD_ITEM_4_4_8_STATE)&&!Clr) { //customer key3
            if (((UserData.ucCustomerKey1 == CUSTOMER_KEY_INPUT) && (UserData.ucCustomerKey2 == CUSTOMER_KEY_SMARTREMINDER)) ||\
                ((UserData.ucCustomerKey2 == CUSTOMER_KEY_INPUT) && (UserData.ucCustomerKey1 == CUSTOMER_KEY_SMARTREMINDER)))
                Result = TRUE;
        }
        //--
        else if((usStatus == OSD_ITEM_4_2_9_STATE)&&!Clr) { //customer key1
            if ((UserData.ucCustomerKey2 == CUSTOMER_KEY_SMARTREMINDER) || (UserData.ucCustomerKey3 == CUSTOMER_KEY_SMARTREMINDER))
                Result = TRUE;
        }
        else if((usStatus == OSD_ITEM_4_3_9_STATE)&&!Clr) { //customer key2
            if ((UserData.ucCustomerKey1 == CUSTOMER_KEY_SMARTREMINDER) || (UserData.ucCustomerKey3 == CUSTOMER_KEY_SMARTREMINDER))
                Result = TRUE;
        }
        else if((usStatus == OSD_ITEM_4_4_9_STATE)&&!Clr) { //customer key3
            if ((UserData.ucCustomerKey1 == CUSTOMER_KEY_SMARTREMINDER) || (UserData.ucCustomerKey2 == CUSTOMER_KEY_SMARTREMINDER))
                Result = TRUE;
        }
            else if((usStatus == OSD_MAIN_ERGO_1_STATE)&&!Clr){
                if(UserData.bSmartReminder == OFF){
                    Result = TRUE;
                }
            }            
        //--
        else if((usStatus == OSD_ITEM_4_2_10_STATE)&&!Clr)
            Result = TRUE;
        else if((usStatus == OSD_ITEM_4_3_10_STATE)&&!Clr)
            Result = TRUE;
        else if((usStatus == OSD_ITEM_4_4_10_STATE)&&!Clr)
            Result = TRUE;        
        break;

        case 2://Right
        if((usStatus >= OSD_CUSTKEY_PICTUREMODE_1_STATE && usStatus < OSD_CUSTKEY_BRIGHTNESS_END)&&Clr)//Layer2
            Result = TRUE;
        break;
    }
    return Result;
}

//ULEric140409
BOOL OSDCheckBarAdjItem(void)
{
    BOOL Result = FALSE;
    USHRT usStatus = GetOSDState();
    switch(usStatus)
    {
        case OSD_CUSTKEY_VOLUME_STATE:
        case OSD_CUSTKEY_CONTRAST_STATE:
        case OSD_CUSTKEY_BRIGHTNESS_STATE:
        case OSD_ITEM_1_3_STATE:
        case OSD_ITEM_1_4_STATE:
        case OSD_ITEM_1_5_STATE:
        case OSD_ITEM_1_6_STATE:
        case OSD_ITEM_2_1_STATE:
        case OSD_ITEM_2_2_STATE:
        case OSD_ITEM_2_3_STATE:
        case OSD_ITEM_2_6_STATE:
        case OSD_ITEM_2_7_STATE:
        case OSD_ITEM_Audio_1_1_STATE:
        case OSD_SUBITEM_2_5_4_1_STATE:
        case OSD_SUBITEM_2_5_4_2_STATE:
        case OSD_SUBITEM_2_5_4_3_STATE:    
            Result = TRUE;
        break;
    }
    return Result;
}

//ULEric140410
void OSDClearDialogSpaceFrame(UCHAR sw, UCHAR sh, UCHAR ew, UCHAR eh)
{
    UCHAR i;    
    OSDAPI_SetFontAttr(0);
    for(i=0;i<(eh-sh);i++)    
        OSDAPI_WriteXYRepeatChar(TRUE, sw,sh+i, (ew-sw),_SPACE_);
    
}

void OSDDialogBlinkSelectIcon(UCHAR ucIcon)
{
    UCHAR i,Offset;
    Offset = OSD_DIALOG_SELECTPAGE_WIDTH-7+1;
    if(ucIcon == 0)
    {
        OSDAPI_FillLineAttr(Offset, 0, 6, SELECTPAGE_2BIT_COLOR1_BLUE);
        for (i=0; i<3; i++) {
            if (i == 1 || i == 2) {
                OSDAPI_FillLineAttr(Offset, 1+i, 1, SELECTPAGE_2BIT_COLOR1_BLUE);
                OSDAPI_FillLineAttr(Offset+1, 1+i, 5, SELECTPAGE_1BIT_COLOR1_BLACK);
            }
            else {
                OSDAPI_FillLineAttr(Offset, 1+i, 1, SELECTPAGE_2BIT_COLOR1_BLUE);
                OSDAPI_FillLineAttr(Offset+1, 1+i, 5, SELECTPAGE_1BIT_COLOR1_BLUE);
            }
        }
        OSDAPI_FillLineAttr(Offset, 4, 1, SELECTPAGE_4BIT_COLOR_BLUE_UPPER);
        OSDAPI_FillLineAttr(Offset+1, 4, 5, SELECTPAGE_2BIT_COLOR4);
    }            
    else if(ucIcon == 1){
        OSDAPI_FillLineAttr(Offset, 4, 1, SELECTPAGE_4BIT_COLOR_BLUE_LOWER);
        OSDAPI_FillLineAttr(Offset+1, 4, 5, SELECTPAGE_2BIT_COLOR5);
        for (i=0; i<3; i++) {
            if (i ==1 || i == 2) {
                OSDAPI_FillLineAttr(Offset, 4+1+i, 1, SELECTPAGE_2BIT_COLOR1_BLUE);
                OSDAPI_FillLineAttr(Offset+1, 4+1+i, 5, SELECTPAGE_1BIT_COLOR1_BLACK);
            }
            else {
                OSDAPI_FillLineAttr(Offset, 4+1+i, 1, SELECTPAGE_2BIT_COLOR1_BLUE);
                OSDAPI_FillLineAttr(Offset+1, 4+1+i, 5, SELECTPAGE_1BIT_COLOR1_BLUE);
            }
        }
        OSDAPI_FillLineAttr(Offset, 8, 1, SELECTPAGE_4BIT_COLOR_BLUE_UPPER);
        OSDAPI_FillLineAttr(Offset+1, 8, 5, SELECTPAGE_2BIT_COLOR4);
    }    
        
    Sleep(50);    
    
}
#if 0
UCHAR OSDGetTempPicMode(void)
{
    return OSD_Select_Temp;
}
#endif
void OSDClearItemString(UCHAR ucLayerNo,UCHAR ucStart)
{
    UCHAR i,ucPosX,ucPosY;
    OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
    if(ucLayerNo == 0)
    {
        ucPosX = 8;
        ucPosY = 5;
    }
        
    for (i=ucStart;i<8; i++)
        OSDAPI_WriteXYRepeatChar(FALSE, ucPosX, ucPosY+(i*2), INDENT_STRING_MAX_LEN, _SPACE_);
}

void OSDShowHook(UCHAR id, UCHAR CustomerKey)
{    

    switch(CustomerKey)
    {    
    case CUSTOMER_KEY_MUTE:
    if(id==(!Custom_System.ucOSD_preview_temp))
            OSDAPI_SetFontAttr(SelectedStringColor_256);
    else
        OSDAPI_SetFontAttr(UnSelectedStringColor1_256);
    OSDAPI_WriteXYChar(TRUE, 8+11, 5+((!Custom_System.ucOSD_preview_temp)*2), Hook_Icon);
    break;

    case CUSTOMER_KEY_INPUT:
    if(id==(GetInputPortIndex(Custom_System.ucOSD_preview_temp)))
            OSDAPI_SetFontAttr(SelectedStringColor_256);
    else
        OSDAPI_SetFontAttr(UnSelectedStringColor1_256);
    OSDAPI_WriteXYChar(TRUE, 8+11, 5+((GetInputPortIndex(Custom_System.ucOSD_preview_temp))*2), Hook_Icon);
    break;

    case CUSTOMER_KEY_DISPLAYMODE:
    if(id==Custom_System.ucOSD_preview_temp)
            OSDAPI_SetFontAttr(SelectedStringColor_256);
    else
        OSDAPI_SetFontAttr(UnSelectedStringColor1_256);
    OSDAPI_WriteXYChar(TRUE, 8+11, 5+(Custom_System.ucOSD_preview_temp*2), Hook_Icon);
    break;

    case CUSTOMER_KEY_PICTUREMODE:
        if((id/8) == (Custom_System.ucOSD_preview_temp/8))//ULEric140411
        {
            if(id==Custom_System.ucOSD_preview_temp)
                    OSDAPI_SetFontAttr(SelectedStringColor_256);
            else
                OSDAPI_SetFontAttr(UnSelectedStringColor1_256);
            if(Custom_System.ucOSD_preview_temp>7)
            {
                OSDAPI_WriteXYChar(TRUE, 8+11, 5+((Custom_System.ucOSD_preview_temp-8)*2), Hook_Icon);
            }else
                OSDAPI_WriteXYChar(TRUE, 8+11, 5+(Custom_System.ucOSD_preview_temp*2), Hook_Icon);
        }else{
            OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
            if(Custom_System.ucOSD_preview_temp>7)
                OSDAPI_WriteXYChar(TRUE, 8+11, 5+((Custom_System.ucOSD_preview_temp-8)*2), _SPACE_);
            else
                OSDAPI_WriteXYChar(TRUE, 8+11, 5+(Custom_System.ucOSD_preview_temp*2), _SPACE_);
        }
        break;

    case CUSTOMER_KEY_LOWBULELIGHTMODE://ULEric140407
    if(id==Custom_System.ucOSD_preview_temp)
            OSDAPI_SetFontAttr(SelectedStringColor_256);
    else
        OSDAPI_SetFontAttr(UnSelectedStringColor1_256);
    OSDAPI_WriteXYChar(TRUE, 8+11, 5+(Custom_System.ucOSD_preview_temp*2), Hook_Icon);    
    break;

    case CUSTOMER_KEY_SMARTREMINDER://ULEric140411
    if(id==(!Custom_System.ucOSD_preview_temp))
            OSDAPI_SetFontAttr(SelectedStringColor_256);
    else
        OSDAPI_SetFontAttr(UnSelectedStringColor1_256);
    OSDAPI_WriteXYChar(TRUE, 8+11, 5+((!Custom_System.ucOSD_preview_temp)*2), Hook_Icon);    
    break;
    };
}

void OSDSetAspectRatio(UCHAR ucAspectRatioType)
{
    UserData.ucAspectRatio = ucAspectRatioType;
    
    SetAspRatioSetting();
#if ENABLE_PIP == ON    
    UserSetPictureMode();
#else
    UserSetAspectRatio();    
#endif
}

void OSDSetBFMenuITM(UCHAR ucPictMode)
{
    UCHAR ucTemp=0,ucTemp1 = 0;
    
    UserData.ucBFMode = ucPictMode;
    UserSetBF();
}

void OSDClearItemHookIcon(UCHAR ucLayer)
{
    UCHAR i,ucPosX;
    if(ucLayer == STRING_LAYER_3)
        ucPosX = 44;
    else if(ucLayer == STRING_LAYER_4)
        ucPosX = 58;
    else
        return;
    
    OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
    for(i=0;i<8;i++)
        OSDAPI_WriteXYChar(TRUE, ucPosX, 5+(i*2),_SPACE_);
}

//******************************************************************************
// Prototype:
//  void OSDInitialize(BOOL bForceInit)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Initial OSD Font & Palette
// Notes:
//  None
//******************************************************************************
void OSDInitialize(BOOL bForceInit)
{
    SC_OSD_HOR_SPLIT_START_LO = 0;
    SC_OSD_HOR_SPLIT_WIDTH_LO = 0;
    SC_OSD_VER_SPLIT_START_LO = 0;
    SC_OSD_VER_SPLIT_WIDTH_LO = 0;
    if (!IsOSDSysInit() || bForceInit) {
        SetOSDSysInitFlag();

        OSDAPI_SetFontSize(OSD_FONT_12X18);
        OSDAPI_SetOSDWinSizeUnit(1, 1);
        OSDLoadFont(LoadPalette);

        //frame size = w:32 h:17
        //one bit size = (188)x18/2 = 1692
        //two bit size = 8*18 = 144
        //four bit size= 22*18*2=792
    #if ENABLE_OSD_ROTATION == ON
        OSDAPI_Set1BitFontAddr(OSDSRAM_ADDR_CEILING(OSDAPI_GetOSDFrameSize(32, 17)));
        OSDAPI_Set2BitsFontAddr(OSDSRAM_ADDR_FLOOR(OSD_ROT_RAM_SIZE - 792 - 144));
        OSDAPI_Set4BitsFontAddr(OSDSRAM_ADDR_FLOOR(OSD_ROT_RAM_SIZE - 792));
    #else
        //frame size = w:69 h:23
        //one bit size = ?
        //two bit size = ?
        //four bit size= ?
        OSDAPI_Set1BitFontAddr(OSDAPI_GetOSDFrameSize(69, 23));

        // temperary use large memory for two bit font.
        OSDAPI_Set2BitsFontAddr(OSD_RAM_SIZE - 36*12 - 18*60);
        OSDAPI_Set4BitsFontAddr(OSD_RAM_SIZE - 36*12);
    #endif
        OSDLoadFont(OSDInitialize_font);
#if LAYER_INDENT_COUNT == ON
        {
            UCHAR i;

            for (i=0; i<4; i++) {
                LayerIndentInfoTab[i].usCount = 0;
                LayerIndentInfoTab[i].Done = 0;
            }
        }
#endif
    }
}

#if LAYER_INDENT_COUNT == ON
USHRT fnGetLayerIndentCount(UCHAR Layer)
{
    return LayerIndentInfoTab[Layer].usCount;
}

void fnResetLayerIndentCount(UCHAR Layer)
{
    LayerIndentInfoTab[Layer].usCount = OSDAPI_GetIndentIndex();
    //printf("Reset Layer %d Indent index\n", (USHRT)(Layer+1));
}
#endif

//******************************************************************************
// Prototype:
//  void OSDShowMainMenu(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Show main menu page
// Notes:
//  None
//******************************************************************************

void OSDShowMainMenu(void)
{
    UCHAR i;
    OSDAPI_TurnOffOSD();
    OSDInitialize(TRUE);

    OSDInitFrame(OSD_MAIN_WIDTH, OSD_MAIN_HEIGHT, MAIN_FRAME_COLOR);

    OSDShowBenQMainFrame(FrameWidthType_MainMenu);
    OSDShowSelectPageMainFrame(FrameWidthType_MainMenu);
    for (i=0; i<5; i++){
        OSDShowSelectPageIcon(i, 0);
    }
    OSDShowBigWin(OSD_BG_WIN, OSD_WIN_BOARDER_SIZE);
    OSDShowStringSeparater(STRING_LAYER_1, FALSE);
    OSDShowStringSeparater(STRING_LAYER_2, FALSE);
    
    for (i=0; i<MAINMENU_ICON_NUM; i++) {
        OSDShowMainMenuIcon(i);
    }
    
    OSDShowBigWin(OSD_LAYER1_WIN, OSD_WIN_BOARDER_SIZE);

    OSDAPI_SetIndentIndex(String_Layer1_Index);
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    bSelectTable = OSDFontTble1;
    OSDShowTitleString();
    
    OSDAPI_SetFontAttr(UnSelectedStringColor1);    
    OSDAPI_SetIndentIndex(String_Layer1_Index +  20);    
    OSDShowMainMenuStrings();

#if LAYER_INDENT_COUNT == ON
    // after showing layer1 string, the layer2 string start index is fixed and has been recorded by below function.
    fnResetLayerIndentCount(STRING_LAYER_2);
#endif

    OSDSelectLayer1Item(0);

    UserSetTransparent();
    OSDSetPosition(OSD_MAIN_MENU_H_POSITION,OSD_MAIN_MENU_V_POSITION);//zoe test

    OSDTurnOnOSD();
}

void OSDShowTitleString(void)
{
    OSDAPI_SetFontAttr(MAINMENU_TITLE);    
    ShowIndentString(TRUE, 2, 1, 22, ModeTitleTab[UserData.ucBFMode*NUM_OSDLANGS + UserData.ucLanguage]);    
}

//******************************************************************************
// Prototype:
//  void OSDUnSelectDialogItem(UCHAR id, BOOL isUp);
// Parameters:
//  id  : current cursor position
// isUp: indicated that Up or down action
// Return:
//  None
// Purpose:
//  unactivate the selected dialog item
// Notes:
//  None
//******************************************************************************
void OSDUnSelectDialogItem(UCHAR id, BOOL isUp)
{
    UCHAR tmp, CustomerKey;

    isUp = isUp;

    CustomerKey = fnGetCustomerKeyItem();

    OSDAPI_OSDWinOff(OSD_WINDOW1);

    tmp = (id > 7)? (id-8):id;

    // string row
    OSDAPI_FillLineAttr(8, 5+tmp*2, DIALOG_INDENT_STRING_MAX_LEN, UnSelectedStringColor_256);

    // redraw separater line to gray color
//    if (isUp && id != 7) {
    OSDAPI_FillLineAttr(8, 5+tmp*2+1, INDENT_STRING_MAX_LEN, StringSeparaterLineColor1);
//    }
//    else {
    OSDAPI_FillLineAttr(8, 5+tmp*2-1, INDENT_STRING_MAX_LEN, StringSeparaterLineColor1);
//    }

    // clear second layer string if necessary
    /*
    if (CustomerKey == CUSTOMER_KEY_PICTUREMODE || CustomerKey == CUSTOMER_KEY_DISPLAYMODE || CustomerKey == CUSTOMER_KEY_INPUT) {
        if (id == 7 && isUp == FALSE) {
            for (i=0; i< 8 ; i++) {
                OSDAPI_WriteXYRepeatChar(FALSE, 8, 5+i*2, INDENT_STRING_MAX_LEN, _SPACE_);
            }
        }
        else if(id == 8 && isUp == TRUE) {
            for (i=0; i< ucLayer3ItmNumTab[2][0]-8 ; i++) {
                OSDAPI_WriteXYRepeatChar(FALSE, 8, 5+i*2, INDENT_STRING_MAX_LEN, _SPACE_);
            }
        }
    }
    */
}

//******************************************************************************
// Prototype:
// void OSDShowHookIcon(USHRT Attr, UCHAR id, UCHAR Layer, UCHAR font)
// Parameters:
// Attr     : indicate which attribute to use for different OSD action.
//  id    : indicate current selected item id at previous layer.
//  Layer : indicate which layer should the hook icon be displayed.
// Return:
//  None
// Purpose:
// Show hook icon when items selected at layer 2 or layer3.
// Notes:
//  None
//******************************************************************************
void OSDShowHookIcon(USHRT Attr, UCHAR id, UCHAR Layer, UCHAR font)
{
    OSDAPI_SetFontAttr(Attr);
    //printf("jim show hook icon, id = %d, layer = %d\n", (USHRT)id, (USHRT)Layer);
    switch (Layer) {
        case STRING_LAYER_3:
            switch (ucMenuType) {
                case OSD_MAIN_DISPLAY:
                    switch (id) {
#if ENABLE_AUTO_POVIT_FUNC == ON  
                        case 1:
                            //Auto Pivot
                                OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+0*2, font);
                        break;
#endif
                        case OSD_DISPLAY_ADJUST:
                        case OSD_DISPLAY_INPUT:
                            switch (UserData.ucInputSource) 
                            {
                                case INPUT_SC_VGA:
                                    OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+0*2, font);
                                break;
                                case INPUT_SC_DVI:
                                    OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+1*2, font);
                                break;
                                case INPUT_SC_HDMI:
                                    OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+2*2, font);
                                break;
                                case INPUT_SC_DP:
                                    OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+3*2, font);       
                                break;
                                case INPUT_SC_YPbPr:
                                default:
                                break;
                            }                            
                        break;
                        default:
                        break;
                    }
                break;
                case OSD_MAIN_PICTURE:
                    switch (id) {
                        case OSD_PICTURE_GAMMA:
                        //printf("ucGammaNum = %02BX\r\n",UserData.ucGammaNum);
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+GetGammaNum()*2, font);
                        break;
                        case OSD_PICTURE_COLORTEMP:
                        //printf("ucColorTemp = %02BX\r\n",UserData.ucColorTemp);
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+UserData.ucColorTemp*2, font);
                        break;
                        case OSD_PICTURE_RESETCOLOR:// usOSDState == OSD_ITEM_2_8_1_STATE
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+1*2, font);
                        break;
                        case OSD_PICTURE_AMA://usOSDState == OSD_ITEM_2_9_1_STATE
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+UserData.ucODMode*2, font);
                        break;
                        default:
                        break;
                    }
                break;
                case OSD_MAIN_PICTURE_ADVANCED:
                    switch (id) {
                        case OSD_PICTURE_AD_PIC:
                        //printf("ucBFMode = %02BX\r\n",UserData.ucBFMode);
                            if(UserData.ucBFMode>(OSD_MAX_LINES-1))//ULEric140401                        
                                OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+(UserData.ucBFMode-OSD_MAX_LINES)*2, font);
                            else
                                OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+UserData.ucBFMode*2, font);
                            break;
                        case OSD_PICTURE_AD_SENSEYE:
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+(1-UserData.bSensEyeDemo)*2, font);
                            break;
                        case OSD_PICTURE_AD_DCR:                        
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+(1-UserData.bDCRMode)*2, font);
                            break;                            
                        case OSD_PICTURE_AD_OVERSCAN:
                        //printf("OverScan = %02BX\r\n",UserData.bOverScan);
                            if(IsComponentInput())
                                OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+(1-UserData.bSOGOverScan)*2, font);
                            else
                                OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+(1-UserData.bOverScan)*2, font);
                            break;

                        case OSD_PICTURE_AD_DISMODE:
                            //Color Format UserData.ucAspectRatio
                            //printf("ucAspectRatio = %02BX\r\n",UserData.ucAspectRatio);
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+UserData.ucAspectRatio*2, font);
                            break;
                        case OSD_PICTURE_AD_COLORFORMAT:                            
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+UserData.bColorFormat*2, font);
                            break;    
                        case OSD_PICTURE_AD_PCRANGE:
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+UserData.ucHDMIRGBRange*2, font);                            
                            break;                                
                        default:
                            break;
                    }
                break;
                case OSD_MAIN_AUDIO:
                     switch (id) {
                        case OSD_AUDIO_MUTE:
                            //printf("Mute = %02BX\r\n",UserData.bAudioMute);
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+(1-UserData.bAudioMute)*2, font);
                            break;
                        case OSD_AUDIO_SELECT:
                            if(UserData.ucInputSource == INPUT_SC_HDMI){
                                OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+UserData.ucHDMIAudioSelect*2, font);
                            }
                            else{
                                OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+UserData.ucAudioSelect*2, font);
                            }                            
                            break;
                        case OSD_AUDIO_VOLUME:
                        default:
                            break;
                    }
                break;
                break;
                case OSD_MAIN_SYSTEM:
                    switch (id) {
                        case OSD_SYS_CTKEY1:
                        //printf("CusKey1=%bx\r\n",UserData.ucCustomerKey1);
                            if(UserData.ucCustomerKey1>(OSD_MAX_LINES-1)){//ULEric140401
                                OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+(UserData.ucCustomerKey1-OSD_MAX_LINES)*2, font);
                            }
                            else{                
                               OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+UserData.ucCustomerKey1*2, font);
                            }
                            break;

                        case OSD_SYS_CTKEY2:
                        //CustomerKey2
                        //printf("ucCustomerKey2 = %02BX\r\n",UserData.ucCustomerKey2);
                            if(UserData.ucCustomerKey2>(OSD_MAX_LINES-1))//ULEric140401
                                OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+(UserData.ucCustomerKey2-OSD_MAX_LINES)*2, font);
                            else
                                OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+UserData.ucCustomerKey2*2, font);
                            break;

                        case OSD_SYS_CTKEY3:
                        //CustomerKey3
                        //printf("ucCustomerKey3 = %02BX\r\n",UserData.ucCustomerKey3);
                            if(UserData.ucCustomerKey3>(OSD_MAX_LINES-1))//ULEric140401
                                OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+(UserData.ucCustomerKey3-OSD_MAX_LINES)*2, font);
                            else
                                OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+UserData.ucCustomerKey3*2, font);
                            break;

                        case OSD_SYS_DDCCI:
                        //DDC/CI UserData.bDDCCI
                        //printf("bDDCCI = %02BX\r\n",UserData.bDDCCI);
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+(1-UserData.bDDCCI)*2, font);
                            break;
                        case OSD_SYS_DPASWITCH:                     
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+(1-UserData.bDPAutoSwitch)*2, font);
                            break;
                        case OSD_SYS_HDASWITCH:                       
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+(1-UserData.bHDMIAutoSwitch)*2, font);
                            break;
                        case OSD_SYS_AUTO_POWEROFF:
                        //Auto Power Off UserData.ucAutoPowerOffTime
                        //printf("ucAutoPowerOffTime = %02BX\r\n",UserData.ucAutoPowerOffTime);                         
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+UserData.ucAutoPowerOffTime*2, font);
/*                        
                            if(UserData.ucAutoPowerOffTime == 2)
                                OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+0*2, Hook_Icon);
                            if(UserData.ucAutoPowerOffTime == 1)
                                OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+1*2, Hook_Icon);
                            if(UserData.ucAutoPowerOffTime == 0)
                                OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+2*2, Hook_Icon);    
                            if(UserData.ucAutoPowerOffTime == 3)
                                OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+3*2, Hook_Icon);                                                                
*/                                
                            break;
                        case OSD_SYS_RES:
                            //UserData.ucResNotice            
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+(1-UserData.bResNotice)*2, font);
                            break;
                        case OSD_SYS_INFORMATION:
                            //OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+0*2, Hook_Icon);//ULeric140401
                            break;
                        case OSD_SYS_DISPLAYPORT:
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+UserData.bDPVersion*2, font);
                            break;                            
                        case OSD_SYS_RECALL:
                        //Reset All
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+1*2, font);
                            break;

                        case OSD_SYS_OSDSET:
                        //case 7:
                        default:
                            break;
                    }
                break;
                case OSD_MAIN_ERGONOMICS:
                    switch (id) {
                        case OSD_ERGONOMICS_REMIDER:
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+(1-UserData.bSmartReminder)*2, font);
                            break;
                        case OSD_ERGONOMICS_TIME:
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+UserData.ucErgoTime*2, font);
                            break;
                        case OSD_ERGONOMICS_DURATION:
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+UserData.ucErgoDuration*2, font);
                            break;                        
                        default:
                            break;
                    }
                break;
                
            }
        break;
        case STRING_LAYER_4:
            if (ucMenuType == OSD_MAIN_SYSTEM && ucSubMenuType == OSD_SYS_OSDSET) {//ULEric140401
                if (id == OSD_SYS_OSDSET_LANG) {
                    // Language
                    OSDAPI_WriteXYChar(TRUE, ucLayer4ItemInfoTb[1]+11, ucLayer4ItemInfoTb[2]+(UserData.ucLanguage-((UserData.ucLanguage/8)*8))*2, font);//ULEric140401   
                }
                else if (id == OSD_SYS_OSDSET_TIMER) {
                    // DisplayTime
                    OSDAPI_WriteXYChar(TRUE, ucLayer4ItemInfoTb[4]+11, ucLayer4ItemInfoTb[5]+((UserData.ucOSDTimer/5)-1)*2, font);//ULEric140401
                }
            }else if(ucMenuType == OSD_MAIN_PICTURE_ADVANCED && ucSubMenuType == OSD_PICTURE_AD_PIC){//ULEric140402
                if(id == PICTURE_MODE_LOW_BL){
            // LBL Mode
                    OSDAPI_WriteXYChar(TRUE, 47+11, 5+(UserData.ucLBLMode)*2, font);//ULEric140402
                }
            }
        break;
    }
}

//******************************************************************************
// Prototype:
//  void OSDClrLayer1Menu(UCHAR id)
// Parameters:
//  id      : current item id of Layer1.
// Return:
//  None
// Purpose:
//  clear Layer1 then enter Layer2.
// Notes:
//  None
//******************************************************************************
void OSDClrLayer1Menu(UCHAR id)
{
    UCHAR i;

    // clear layer1 windows
    OSDAPI_OSDWinOff(OSD_WINDOW1);
    OSDAPI_OSDWinOff(OSD_WINDOW3);
    OSDAPI_OSDWinOff(OSD_WINDOW4);

    // redraw string separater color except icon part
    OSDAPI_FillLineAttr(ucLayer1StringInfoTb[0], ucLayer1StringInfoTb[1]+id*2-1, INDENT_STRING_MAX_LEN, UnSelectedStringColor);
    OSDAPI_FillLineAttr(ucLayer1StringInfoTb[0], ucLayer1StringInfoTb[1]+id*2+1, INDENT_STRING_MAX_LEN, UnSelectedStringColor);

    // redraw layer1 string color
    for (i=0; i<MAINMENU_ICON_NUM; i++) {
        if(i == id){
            OSDAPI_FillLineAttr(ucLayer1StringInfoTb[0], ucLayer1StringInfoTb[1]+i*2, INDENT_STRING_MAX_LEN, SelectedStringColor1);    
        }
        else{
            OSDAPI_FillLineAttr(ucLayer1StringInfoTb[0], ucLayer1StringInfoTb[1]+i*2, INDENT_STRING_MAX_LEN, UnSelectedStringColor);
        }
    }

    // redarw layer1 string to Blue color

           
    // redraw icon color
    switch (id) {
        case 0:
            // icon1
           OSDAPI_FillLineAttr(ucMainIconPos[0*2]+1, ucMainIconPos[0*2+1], 1, SelectedStringColor1);
           OSDAPI_FillLineAttr(ucMainIconPos[0*2], ucMainIconPos[0*2+1]+1, 3, SelectedStringColor1);

           // icon2
           for(i = 1; i < 5; i++) {
           OSDAPI_FillLineAttr(ucMainIconPos[i*2], ucMainIconPos[i*2+1], 3, MAINICON_2BIT_COLOR4);
           OSDAPI_FillLineAttr(ucMainIconPos[i*2], ucMainIconPos[i*2+1]+1, 3, UnSelectedStringColor);
           OSDAPI_FillLineAttr(ucMainIconPos[i*2], ucMainIconPos[i*2+1]+2, 3, MAINICON_2BIT_COLOR4);
           }
            //icon 6
           OSDAPI_FillLineAttr(ucMainIconPos[5*2], ucMainIconPos[5*2+1], 3, MAINICON_2BIT_COLOR4);
           OSDAPI_FillLineAttr(ucMainIconPos[5*2], ucMainIconPos[5*2+1]+1, 3, UnSelectedStringColor);

           break;
       case 1:
            // icon1
           OSDAPI_FillLineAttr(ucMainIconPos[0*2]+1, ucMainIconPos[0*2+1], 1, UnSelectedStringColor);
           OSDAPI_FillLineAttr(ucMainIconPos[0*2], ucMainIconPos[0*2+1]+1, 3, UnSelectedStringColor);

           // icon2
           OSDAPI_FillLineAttr(ucMainIconPos[1*2], ucMainIconPos[1*2+1], 3, MAINICON_2BIT_COLOR5);
           OSDAPI_FillLineAttr(ucMainIconPos[1*2], ucMainIconPos[1*2+1]+1, 3, SelectedStringColor1);
           OSDAPI_FillLineAttr(ucMainIconPos[1*2], ucMainIconPos[1*2+1]+2, 3, MAINICON_2BIT_COLOR5);
           // icon3
           for(i = 2; i < 5; i++) {
           OSDAPI_FillLineAttr(ucMainIconPos[i*2], ucMainIconPos[i*2+1], 3, MAINICON_2BIT_COLOR4);
           OSDAPI_FillLineAttr(ucMainIconPos[i*2], ucMainIconPos[i*2+1]+1, 3, UnSelectedStringColor);
           OSDAPI_FillLineAttr(ucMainIconPos[i*2], ucMainIconPos[i*2+1]+2, 3, MAINICON_2BIT_COLOR4);
           }
            //icon 6
           OSDAPI_FillLineAttr(ucMainIconPos[5*2], ucMainIconPos[5*2+1], 3, MAINICON_2BIT_COLOR4);
           OSDAPI_FillLineAttr(ucMainIconPos[5*2], ucMainIconPos[5*2+1]+1, 3, UnSelectedStringColor);

           break;
        case 2:
            // icon1
           OSDAPI_FillLineAttr(ucMainIconPos[0*2]+1, ucMainIconPos[0*2+1], 1, UnSelectedStringColor);
           OSDAPI_FillLineAttr(ucMainIconPos[0*2], ucMainIconPos[0*2+1]+1, 3, UnSelectedStringColor);

           // icon2
           OSDAPI_FillLineAttr(ucMainIconPos[1*2], ucMainIconPos[1*2+1], 3, MAINICON_2BIT_COLOR4);
           OSDAPI_FillLineAttr(ucMainIconPos[1*2], ucMainIconPos[1*2+1]+1, 3, UnSelectedStringColor);
           OSDAPI_FillLineAttr(ucMainIconPos[1*2], ucMainIconPos[1*2+1]+2, 3, MAINICON_2BIT_COLOR4);

           // icon3
           OSDAPI_FillLineAttr(ucMainIconPos[2*2], ucMainIconPos[2*2+1], 3, MAINICON_2BIT_COLOR5);
           OSDAPI_FillLineAttr(ucMainIconPos[2*2], ucMainIconPos[2*2+1]+1, 3, SelectedStringColor1);
           OSDAPI_FillLineAttr(ucMainIconPos[2*2], ucMainIconPos[2*2+1]+2, 3, MAINICON_2BIT_COLOR5);

           for(i = 3; i < 5; i++) {
           OSDAPI_FillLineAttr(ucMainIconPos[i*2], ucMainIconPos[i*2+1], 3, MAINICON_2BIT_COLOR4);
           OSDAPI_FillLineAttr(ucMainIconPos[i*2], ucMainIconPos[i*2+1]+1, 3, UnSelectedStringColor);
           OSDAPI_FillLineAttr(ucMainIconPos[i*2], ucMainIconPos[i*2+1]+2, 3, MAINICON_2BIT_COLOR4);
           }
           //icon 6
           OSDAPI_FillLineAttr(ucMainIconPos[5*2], ucMainIconPos[5*2+1], 3, MAINICON_2BIT_COLOR4);
           OSDAPI_FillLineAttr(ucMainIconPos[5*2], ucMainIconPos[5*2+1]+1, 3, UnSelectedStringColor);
           break;
        case 3:
            // icon1
           OSDAPI_FillLineAttr(ucMainIconPos[0*2]+1, ucMainIconPos[0*2+1], 1, UnSelectedStringColor);
           OSDAPI_FillLineAttr(ucMainIconPos[0*2], ucMainIconPos[0*2+1]+1, 3, UnSelectedStringColor);

           // icon2 ~icon3
           for (i = 1;i <= 2;i++) {
           OSDAPI_FillLineAttr(ucMainIconPos[1*2], ucMainIconPos[i*2+1], 3, MAINICON_2BIT_COLOR4);
           OSDAPI_FillLineAttr(ucMainIconPos[1*2], ucMainIconPos[i*2+1]+1, 3, UnSelectedStringColor);
           OSDAPI_FillLineAttr(ucMainIconPos[1*2], ucMainIconPos[i*2+1]+2, 3, MAINICON_2BIT_COLOR4);
           }  

           // icon4
           OSDAPI_FillLineAttr(ucMainIconPos[3*2], ucMainIconPos[3*2+1], 3, MAINICON_2BIT_COLOR5);
           OSDAPI_FillLineAttr(ucMainIconPos[3*2], ucMainIconPos[3*2+1]+1, 3, SelectedStringColor1);
           OSDAPI_FillLineAttr(ucMainIconPos[3*2], ucMainIconPos[3*2+1]+2, 3, MAINICON_2BIT_COLOR5);
           // icon5
           for(i = 4; i < 5; i++) {
           OSDAPI_FillLineAttr(ucMainIconPos[i*2], ucMainIconPos[i*2+1], 3, MAINICON_2BIT_COLOR4);
           OSDAPI_FillLineAttr(ucMainIconPos[i*2], ucMainIconPos[i*2+1]+1, 3, UnSelectedStringColor);
           OSDAPI_FillLineAttr(ucMainIconPos[i*2], ucMainIconPos[i*2+1]+2, 3, MAINICON_2BIT_COLOR4);
           }
           //icon 6
           OSDAPI_FillLineAttr(ucMainIconPos[5*2], ucMainIconPos[5*2+1], 3, MAINICON_2BIT_COLOR4);
           OSDAPI_FillLineAttr(ucMainIconPos[5*2], ucMainIconPos[5*2+1]+1, 3, UnSelectedStringColor);
            break;
        case 4:
            // icon1
           OSDAPI_FillLineAttr(ucMainIconPos[0*2]+1, ucMainIconPos[0*2+1], 1, UnSelectedStringColor);
           OSDAPI_FillLineAttr(ucMainIconPos[0*2], ucMainIconPos[0*2+1]+1, 3, UnSelectedStringColor);
  
           // icon2 ~icon4
           for (i=1;i<=3;i++) {
           OSDAPI_FillLineAttr(ucMainIconPos[i*2], ucMainIconPos[i*2+1], 3, MAINICON_2BIT_COLOR4);
           OSDAPI_FillLineAttr(ucMainIconPos[i*2], ucMainIconPos[i*2+1]+1, 3, UnSelectedStringColor);
           OSDAPI_FillLineAttr(ucMainIconPos[i*2], ucMainIconPos[i*2+1]+2, 3, MAINICON_2BIT_COLOR4);
           }   
           
        //icon 5
           OSDAPI_FillLineAttr(ucMainIconPos[4*2], ucMainIconPos[4*2+1], 3, MAINICON_2BIT_COLOR5);
           OSDAPI_FillLineAttr(ucMainIconPos[4*2], ucMainIconPos[4*2+1]+1, 3, SelectedStringColor1);
           OSDAPI_FillLineAttr(ucMainIconPos[4*2], ucMainIconPos[4*2+1]+2, 3, MAINICON_2BIT_COLOR5);
           
        //icon 6
           OSDAPI_FillLineAttr(ucMainIconPos[5*2], ucMainIconPos[5*2+1], 3, MAINICON_2BIT_COLOR4);
           OSDAPI_FillLineAttr(ucMainIconPos[5*2], ucMainIconPos[5*2+1]+1, 3, UnSelectedStringColor);
            break;
        case 5:
            // icon1
           OSDAPI_FillLineAttr(ucMainIconPos[0*2]+1, ucMainIconPos[0*2+1], 1, UnSelectedStringColor);
           OSDAPI_FillLineAttr(ucMainIconPos[0*2], ucMainIconPos[0*2+1]+1, 3, UnSelectedStringColor);

           // icon2~icon5
           for (i = 1;i<5;i++) {
           OSDAPI_FillLineAttr(ucMainIconPos[i*2], ucMainIconPos[i*2+1], 3, MAINICON_2BIT_COLOR4);
           OSDAPI_FillLineAttr(ucMainIconPos[i*2], ucMainIconPos[i*2+1]+1, 3, UnSelectedStringColor);
           OSDAPI_FillLineAttr(ucMainIconPos[i*2], ucMainIconPos[i*2+1]+2, 3, MAINICON_2BIT_COLOR4);
           }   
        //icon 6
           OSDAPI_FillLineAttr(ucMainIconPos[5*2], ucMainIconPos[5*2+1], 3, MAINICON_2BIT_COLOR4);
           OSDAPI_FillLineAttr(ucMainIconPos[5*2], ucMainIconPos[5*2+1]+1, 3, SelectedStringColor1);
           OSDAPI_FillLineAttr(ucMainIconPos[5*2], ucMainIconPos[5*2+1]+2, 3, StringSeparaterLineColor1);
            break;

       }

    // redraw layer2 first separater line
    //OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+1, INDENT_STRING_MAX_LEN, LayerSeparaterColor3);
}

//******************************************************************************
// Prototype:
//  void OSDClrLayer2Menu(UCHAR id)
// Parameters:
//  id      : current item id of Layer2.
// Return:
//  None
// Purpose:
//  clear Layer2 then enter Layer3.
// Notes:
//  None
//******************************************************************************
void OSDClrLayer2Menu(UCHAR id)
{
    UCHAR i;

    // clear layer2 windows
    OSDAPI_OSDWinOff(OSD_WINDOW1);
    OSDAPI_OSDWinOff(OSD_WINDOW3);
    OSDAPI_OSDWinOff(OSD_WINDOW4);

   // redraw up down icon to white
    if (IsPage2)
        OSDAPI_FillLineAttr(24, 3, 2, ArrowColor2);
    else {
        OSDAPI_FillLineAttr(25, 21, 1, ArrowColor2);
        OSDAPI_FillLineAttr(24, 20, 2, ArrowColor2);
    }

    // redraw layer2 string color
     if (ucLayer2ItmNumTb[ucMenuType] >8) {
        //printf("jim 1: id = %d, ucMenuType = %d, value = %d\n", (USHRT)id, (USHRT)ucMenuType, (USHRT)(ucLayer2ItmNumTb[ucMenuType]-8));

        if (IsPage2) {
            for (i=0; i<(ucLayer2ItmNumTb[ucMenuType]-8); i++) {
                if (OSDIsSubItemValid(i) == FALSE) {
                    OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*2, INDENT_STRING_MAX_LEN, DisabledStringColor);
                }
                else{             
                    OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*2, INDENT_STRING_MAX_LEN, UnSelectedStringColor);
                }                
            }
        }
        else {
            for (i=0; i<8; i++) {
                if (OSDIsSubItemValid(i) == FALSE) {
                    OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*2, INDENT_STRING_MAX_LEN, DisabledStringColor);
                }
                else{             
                    OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*2, INDENT_STRING_MAX_LEN, UnSelectedStringColor);
                }                
            }
        }
    }
    else {
        //printf("jim 2: id = %d, ucMenuType = %d, value = %d\n", (USHRT)id, (USHRT)ucMenuType, (USHRT)(ucLayer2ItmNumTb[ucMenuType]));
        for (i=0; i<ucLayer2ItmNumTb[ucMenuType]; i++) {
            if (OSDIsSubItemValid(i) == FALSE) {
                OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*2, INDENT_STRING_MAX_LEN, DisabledStringColor);
            }
            else{                         
                OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*2, INDENT_STRING_MAX_LEN, UnSelectedStringColor);
            }
        }
    }
    // redarw layer2 selected string to Blue color
    if (IsPage2) {
        id = id-8;
    }
    OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+id*2, INDENT_STRING_MAX_LEN, StringColor1);

    // redraw string separater color
    OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]-1+id*2, INDENT_STRING_MAX_LEN, UnSelectedStringColor);
    OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+1+id*2, INDENT_STRING_MAX_LEN, UnSelectedStringColor);

    // redraw layer2 triangle icon and layer separater
    WaitDisVSync();
    OSDShowLayerSeparater(STRING_LAYER_2, ucMenuType, FALSE);
}

//******************************************************************************
// Prototype:
//  void OSDClrLayer3Menu(UCHAR id)

// Parameters:
//  id      : current item id of Layer3.
// Return:
//  None
// Purpose:
//  clear Layer3 then enter Layer4.
// Notes:
//  None
//******************************************************************************
void OSDClrLayer3Menu(UCHAR id)
{
    UCHAR i;

    // clear layer3 windows
    OSDAPI_OSDWinOff(OSD_WINDOW1);
    OSDAPI_OSDWinOff(OSD_WINDOW3);
    OSDAPI_OSDWinOff(OSD_WINDOW4);

    // redraw previous focus item string separater to gray color
    //printf("id = %d, ucLayer3PosInfoTab[ucMenuType][0] = %d,  ucLayer3PosInfoTab[ucMenuType][1] = %d", (USHRT)id, (USHRT)ucLayer3PosInfoTab[ucMenuType][0], (USHRT)ucLayer3PosInfoTab[ucMenuType][1]);
    OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]-1+id*2, INDENT_STRING_MAX_LEN, UnSelectedStringColor);
    OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+1+id*2, INDENT_STRING_MAX_LEN, UnSelectedStringColor);


    // redraw layer3 string color
    for (i=0; i<ucLayer3ItmNumTab[ucMenuType][ucSubMenuType]; i++) {
        if (i == id) {
            OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*2, INDENT_STRING_MAX_LEN, StringColor1_256);
        }
        else {
            OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*2, INDENT_STRING_MAX_LEN, UnSelectedStringColor_256);
        }
    }
    WaitDisVSync();
    // redraw layer3 triangle icon and layer separater
    OSDShowLayerSeparater(STRING_LAYER_3, ucSubMenuType, FALSE);
}


void OSDShowLayer4Menu(UCHAR id)
{
    UCHAR i;

    // show layer4 triangle icon
    if (id == ucLayer3MenuType) {
        OSDShowTrianIcon(TRIANGLE_METHOD2, id, STRING_LAYER_4);
    }
    else {
        OSDShowTrianIcon(TRIANGLE_METHOD1, id, STRING_LAYER_4);
    }
    OSDShowBigWin(OSD_LAYER4_WIN, OSD_WIN_BOARDER_SIZE);

    if (ucMenuType == 1 && ucSubMenuType == 4 && id == 3) {
        OSDShowGGain(FALSE, FALSE);
        OSDShowBGain(FALSE, FALSE);
        OSDShowRGain(TRUE, FALSE);
    }
    else if (ucMenuType == 3 && ucSubMenuType == 0) {
        // redraw layer4 string to white color
        for (i=0; i<(ucLayer4ItemInfoTb[ucLayer3MenuType*3]>OSD_MAX_LINES? OSD_MAX_LINES:ucLayer4ItemInfoTb[ucLayer3MenuType*3]); i++) {
            if (i == id) {
                // redraw layer4 selected string to Black color
                OSDAPI_FillLineAttr(ucLayer4ItemInfoTb[ucLayer3MenuType*3+1], ucLayer4ItemInfoTb[ucLayer3MenuType*3+2]+id*2, 13, SelectedStringColor_256);

                // redraw string separater to blue color
                OSDAPI_FillLineAttr(ucLayer4ItemInfoTb[ucLayer3MenuType*3+1], ucLayer4ItemInfoTb[ucLayer3MenuType*3+2]-1+id*2, 13, StringSeparaterLineColor2);
                OSDAPI_FillLineAttr(ucLayer4ItemInfoTb[ucLayer3MenuType*3+1], ucLayer4ItemInfoTb[ucLayer3MenuType*3+2]+1+id*2, 13, StringSeparaterLineColor2);
            }
            else {
                OSDAPI_FillLineAttr(ucLayer4ItemInfoTb[ucLayer3MenuType*3+1], ucLayer4ItemInfoTb[ucLayer3MenuType*3+2]+i*2, 13, UnSelectedStringColor1_256);
            }
        }

        // show Layer 4 down arrow
        /*//ULEric140401
        if (id == 0) {
            // show down arrow
            OSDAPI_SetFontAttr(ArrowColor1);
            OSDAPI_WriteXYChar(TRUE, ucLayer4ItemInfoTb[ucLayer3MenuType*3+1]+6, 20, DownArrow_1);
            OSDAPI_WriteXYChar(TRUE, ucLayer4ItemInfoTb[ucLayer3MenuType*3+1]+6+1, 20, DownArrow_2);
            OSDAPI_WriteXYChar(TRUE, ucLayer4ItemInfoTb[ucLayer3MenuType*3+1]+6+1, 21, DownArrow_3);
        }
        */

        OSDShowSmallWin(id, OSD_LAYER4_WIN);
    }
}


//******************************************************************************
// Prototype:
//  void OSDShowMainMenuIcon(UCHAR id)
// Parameters:
// id       : incicate which main menu icon to draw
// Return:
//  None
// Purpose:
//  Draw main menu icon
// Notes:
//  None
//******************************************************************************
void OSDShowMainMenuIcon(UCHAR id)
{
    code UCHAR ucIcon2_2Bit_IndexTab[] = {
        MI2_2Bit_Upper_1, MI2_2Bit_Upper_2, MI2_2Bit_Upper_3,
    };
    code UCHAR ucIcon3_2Bit_IndexTab[] = {
        MI3_2Bit_Upper_1, MI3_2Bit_Upper_2, MI3_2Bit_Upper_3,
    };
    code UCHAR ucIconAudio_2Bit_IndexTab[] = {
        MIAudio_2Bit_Upper_1, MIAudio_2Bit_Upper_2, MIAudio_2Bit_Upper_3,
    };
    code UCHAR ucIconBlank_2Bit_IndexTab[] = {
        MIAudio_2Bit_Upper_1, MIAudio_2Bit_Upper_1, MIAudio_2Bit_Upper_1,
    };
    code UCHAR ucIcon1_1Bit_IndexTab[] = {
        MI1_1Bit_Lower_1, MI1_1Bit_Lower_2, MI1_1Bit_Lower_3,
    };
    code UCHAR ucIcon2_1Bit_IndexTab[] = {
        MI2_1Bit_Lower_1, MI2_1Bit_Lower_2, MI2_1Bit_Lower_3,
    };
    code UCHAR ucIcon3_1Bit_IndexTab[] = {
        MI3_1Bit_Lower_1, MI3_1Bit_Lower_2, MI3_1Bit_Lower_3,
    };
    code UCHAR ucIconAudio_1Bit_IndexTab[] = {
        MIAudio_1Bit_Middle_1, MIAudio_1Bit_Middle_2, MIAudio_1Bit_Middle_3,
    };
    code UCHAR ucIcon4_1Bit_IndexTab[] = {
        MI4_1Bit_Middle_1, MI4_1Bit_Middle_2, MI4_1Bit_Middle_3,
    };
    code UCHAR ucIconErgo_1Bit_IndexTab[] = {
        MIErgo_1Bit_Middle_1, MIErgo_1Bit_Middle_2, MIErgo_1Bit_Middle_3,
    };

    switch (id) {
        case 0: // Icon1 display
            OSDAPI_SetFontAttr(MAINICON_1BIT_COLOR1);
            OSDAPI_WriteXYChar(TRUE, ucMainIconPos[id*2]+1, ucMainIconPos[id*2+1], MI1_1Bit_Upper_1);
            OSDAPI_WriteXYString(TRUE, ucMainIconPos[id*2], ucMainIconPos[id*2+1]+1,3 , ucIcon1_1Bit_IndexTab);
        break;
        case 1: // Icon2 picture
            OSDAPI_SetFontAttr(MAINICON_2BIT_COLOR1);
            OSDAPI_WriteXYString(TRUE, ucMainIconPos[id*2], ucMainIconPos[id*2+1],3 , ucIcon2_2Bit_IndexTab);

            OSDAPI_SetFontAttr(MAINICON_1BIT_COLOR1);
            OSDAPI_WriteXYString(TRUE, ucMainIconPos[id*2], ucMainIconPos[id*2+1]+1,3 , ucIcon2_1Bit_IndexTab);
        break;
        case 2: // Icon3 picture advanced
            OSDAPI_SetFontAttr(MAINICON_2BIT_COLOR1);
            OSDAPI_WriteXYString(TRUE, ucMainIconPos[id*2], ucMainIconPos[id*2+1],3 , ucIcon3_2Bit_IndexTab);

            OSDAPI_SetFontAttr(MAINICON_1BIT_COLOR1);
            OSDAPI_WriteXYString(TRUE, ucMainIconPos[id*2], ucMainIconPos[id*2+1]+1,3 , ucIcon3_1Bit_IndexTab);
        break;
        case 3: // Icon4 audio
            OSDAPI_SetFontAttr(MAINICON_2BIT_COLOR1);
            OSDAPI_WriteXYString(TRUE, ucMainIconPos[id*2], ucMainIconPos[id*2+1],3 , ucIconAudio_2Bit_IndexTab);

            OSDAPI_SetFontAttr(MAINICON_1BIT_COLOR1);
            OSDAPI_WriteXYString(TRUE, ucMainIconPos[id*2], ucMainIconPos[id*2+1]+1,3 , ucIconAudio_1Bit_IndexTab);
        break;
        case 4: // Icon5 systerm
            OSDAPI_SetFontAttr(MAINICON_2BIT_COLOR1);
            OSDAPI_WriteXYString(TRUE, ucMainIconPos[id*2], ucMainIconPos[id*2+1],3 , ucIconBlank_2Bit_IndexTab);

            OSDAPI_SetFontAttr(MAINICON_2BIT_COLOR1);
            OSDAPI_WriteXYChar(TRUE, ucMainIconPos[id*2]+1, ucMainIconPos[id*2+1], MI4_2Bit_Upper_1);
            OSDAPI_WriteXYChar(TRUE, ucMainIconPos[id*2], ucMainIconPos[id*2+1]+2, MI4_2Bit_Lower_1);

            OSDAPI_SetFontAttr(MAINICON_1BIT_COLOR1);
            OSDAPI_WriteXYString(TRUE, ucMainIconPos[id*2], ucMainIconPos[id*2+1]+1,3 , ucIcon4_1Bit_IndexTab);
        break;
        case 5: // Icon5 ergonomics
            OSDAPI_SetFontAttr(MAINICON_2BIT_COLOR1);
            OSDAPI_WriteXYString(TRUE, ucMainIconPos[id*2], ucMainIconPos[id*2+1],3 , ucIconBlank_2Bit_IndexTab);

            OSDAPI_SetFontAttr(MAINICON_1BIT_COLOR1);
            OSDAPI_WriteXYString(TRUE, ucMainIconPos[id*2], ucMainIconPos[id*2+1]+1,3 , ucIconErgo_1Bit_IndexTab);
        break;
    }
}

//******************************************************************************
// Prototype:
//  void OSDFocusMain(UCHAR id)
// Parameters:
//  id      :Layer item id
// Return:
//  None
// Purpose:
//  Focus back to Layer1
// Notes:
//  None
//******************************************************************************
void OSDFocusMain(UCHAR id)
{
    UCHAR i, tmp;

    //Clear Layer4 Information 
    if(ucMenuType == OSD_MAIN_SYSTEM && id == OSD_SYS_INFORMATION) //ULEric140415   
        ClrLayer4();
    
    // clear layer3 all
    OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
    for (i=0; i<17; i++) {
        OSDAPI_WriteXYRepeatChar(TRUE, ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i, INDENT_STRING_MAX_LEN, _SPACE_);
    }

    //Clear Layer3 Arrow //ULEric140403
    OSDUpdateArrowIcon(CLEAR_1BIT_COLOR,ClearArrowType,STRING_LAYER_3);

    // clear layer2 second level up arrow if necessary.
    if (id >= OSD_MAX_LINES) {
        // clear up arrow
        OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
        OSDAPI_WriteXYRepeatChar(TRUE, 24, 3, 2, _SPACE_);
    }

    // clear triangle font
    OSDShowTrianIcon(TRIANGLE_CLEAR, id, STRING_LAYER_2);

    // clear all windows
    OSDAPI_OSDWinOff(OSD_WINDOW3);
    OSDAPI_OSDWinOff(OSD_WINDOW4);
    OSDAPI_OSDWinOff(OSD_WINDOW1);

    // redraw layer2 string separater color to gray
    tmp = (id >= OSD_MAX_LINES? (id-OSD_MAX_LINES):id);
    OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]-1+2*tmp, INDENT_STRING_MAX_LEN, UnSelectedStringColor);
    OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+1+2*tmp, INDENT_STRING_MAX_LEN, UnSelectedStringColor);

    // redraw layer2 string color
    for (i=0; i<(ucLayer2ItmNumTb[ucMenuType]>OSD_MAX_LINES? OSD_MAX_LINES:ucLayer2ItmNumTb[ucMenuType]); i++) {
        if (OSDIsSubItemValid(i) == FALSE) {
            OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*2, INDENT_STRING_MAX_LEN, DisabledStringColor);
        }
        else{             
            OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*2, INDENT_STRING_MAX_LEN, UnSelectedStringColor);
        }        
        //OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*2, INDENT_STRING_MAX_LEN, UnSelectedStringColor);
    }

    // redraw layer1 string color
    for (i=0; i<MAINMENU_ICON_NUM; i++) {
        OSDAPI_FillLineAttr(ucLayer1StringInfoTb[0], ucLayer1StringInfoTb[1]+i*2, INDENT_STRING_MAX_LEN, UnSelectedStringColor1);
    }

    // redraw layer 1
    for (i=0; i<MAINMENU_ICON_NUM; i++) {
        OSDShowMainMenuIcon(i);
    }

    // redraw 4 windows
    OSDShowBigWin(OSD_LAYER1_WIN, OSD_WIN_BOARDER_SIZE);

    OSDSelectLayer1Item(ucMenuType);

    // clear Layer2 separater
    OSDShowLayerSeparater(STRING_LAYER_2, ucMenuType, TRUE);

    IsPage2 = FALSE;
}

//******************************************************************************
// Prototype:
//  void OSDUnselectLayer1Item(UCHAR id, BOOL isUp);
// Parameters:
//  id  : current cursor position
// isUp: indicated that Up or down action
// Return:
//  None
// Purpose:
//  unactivate the selected Layer1 item
// Notes:
//  None
//******************************************************************************
void OSDUnselectLayer1Item(UCHAR id, BOOL isUp)
{
    UCHAR i;

    // clear layer2 string if exist
    OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
    for (i=0; i<(ucLayer2ItmNumTb[id]>OSD_MAX_LINES ? OSD_MAX_LINES:ucLayer2ItmNumTb[id]); i++) {
        OSDAPI_WriteXYRepeatChar(TRUE, ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*2, INDENT_STRING_MAX_LEN, _SPACE_);
    }

    OSDAPI_OSDWinOff(OSD_WINDOW1);

    // string row
    OSDAPI_FillLineAttr(ucLayer1StringInfoTb[0], ucLayer1StringInfoTb[1]+id*2, INDENT_STRING_MAX_LEN, UnSelectedStringColor1);

    // redraw separater line to gray color
    if (isUp) { // draw the item's bellow string separater line to gray
        OSDAPI_FillLineAttr(ucLayer1StringInfoTb[0], ucLayer1StringInfoTb[1]+id*2+1, INDENT_STRING_MAX_LEN, StringSeparaterLineColor1);
    }
    else { // draw the item's above string separater line to gray
        OSDAPI_FillLineAttr(ucLayer1StringInfoTb[0], ucLayer1StringInfoTb[1]+id*2-1, INDENT_STRING_MAX_LEN, StringSeparaterLineColor1);

        if (id == 5) {
            OSDAPI_FillLineAttr(ucLayer1StringInfoTb[0], ucLayer1StringInfoTb[1]+id*2+1, INDENT_STRING_MAX_LEN, StringSeparaterLineColor1);
        }
    }
    // icon part
    switch (id) {
        case 0:
            OSDAPI_FillLineAttr(ucMainIconPos[id*2]+1, ucMainIconPos[id*2+1], 1, MAINICON_1BIT_COLOR1);
            OSDAPI_FillLineAttr(ucMainIconPos[id*2], ucMainIconPos[id*2+1]+1, 3, MAINICON_1BIT_COLOR1);
            if (isUp) {
                OSDAPI_FillLineAttr(ucMainIconPos[1*2], ucMainIconPos[1*2+1], 3, MAINICON_2BIT_COLOR1);
            }
            else {
                //DO NOTHING
            }
        break;
        case 1:
        case 2:
        case 3:
        case 4:
            OSDAPI_FillLineAttr(ucMainIconPos[id*2], ucMainIconPos[id*2+1]+1, 3, MAINICON_1BIT_COLOR1);
            if (isUp) {
                OSDAPI_FillLineAttr(ucMainIconPos[id*2], ucMainIconPos[id*2+1], 3, MAINICON_2BIT_COLOR2);
                OSDAPI_FillLineAttr(ucMainIconPos[(id+1)*2], ucMainIconPos[(id+1)*2+1], 3, MAINICON_2BIT_COLOR1);
            }
            else {
                OSDAPI_FillLineAttr(ucMainIconPos[id*2], ucMainIconPos[id*2+1], 3, MAINICON_2BIT_COLOR1);
            }
           break;
        case 5:
            OSDAPI_FillLineAttr(ucMainIconPos[id*2], ucMainIconPos[id*2+1]+1, 3, MAINICON_1BIT_COLOR1);
            if (isUp) {
                OSDAPI_FillLineAttr(ucMainIconPos[id*2], ucMainIconPos[id*2+1], 3, MAINICON_2BIT_COLOR2);
                //OSDAPI_FillLineAttr(ucMainIconPos[(id+1)*2], ucMainIconPos[(id+1)*2+1], 3, MAINICON_2BIT_COLOR1);
            }
            else {
                OSDAPI_FillLineAttr(ucMainIconPos[id*2], ucMainIconPos[id*2+1], 3, MAINICON_2BIT_COLOR1);
            }
        OSDAPI_FillLineAttr(ucMainIconPos[id*2], ucMainIconPos[id*2+1]+2, 3, StringSeparaterLineColor1);
           break;
       // case 2:
    
          /*
            OSDAPI_FillLineAttr(ucMainIconPos[id*2], ucMainIconPos[id*2+1]+1, 3, MAINICON_1BIT_COLOR1);
            if (isUp) {
                OSDAPI_FillLineAttr(ucMainIconPos[id*2], ucMainIconPos[id*2+1], 3, MAINICON_2BIT_COLOR2);
                OSDAPI_FillLineAttr(ucMainIconPos[3*2], ucMainIconPos[3*2+1], 1, StringSeparaterLineColor1);
                OSDAPI_FillLineAttr(ucMainIconPos[3*2]+2, ucMainIconPos[3*2+1], 1, StringSeparaterLineColor1);
                OSDAPI_FillLineAttr(ucMainIconPos[3*2]+1, ucMainIconPos[3*2+1], 1, MAINICON_2BIT_COLOR1);
            }
           else {
                OSDAPI_FillLineAttr(ucMainIconPos[id*2], ucMainIconPos[id*2+1], 3, MAINICON_2BIT_COLOR1);
           }*/
          // break;
        //case 3:
            /*
            OSDAPI_FillLineAttr(ucMainIconPos[id*2], ucMainIconPos[id*2+1]+1, 3, MAINICON_1BIT_COLOR1);
            if (isUp) {
                OSDAPI_FillLineAttr(ucMainIconPos[id*2]+1, ucMainIconPos[id*2+1], 1, MAINICON_2BIT_COLOR2);
                OSDAPI_FillLineAttr(ucMainIconPos[3*2], ucMainIconPos[3*2+1], 1, StringSeparaterLineColor2);
                OSDAPI_FillLineAttr(ucMainIconPos[3*2]+2, ucMainIconPos[3*2+1], 1, StringSeparaterLineColor2);
            }
            else {
                OSDAPI_FillLineAttr(ucMainIconPos[id*2]+1, ucMainIconPos[id*2+1], 1, MAINICON_2BIT_COLOR1);
                OSDAPI_FillLineAttr(ucMainIconPos[3*2], ucMainIconPos[3*2+1], 1, StringSeparaterLineColor1);
                OSDAPI_FillLineAttr(ucMainIconPos[3*2]+2, ucMainIconPos[3*2+1], 1, StringSeparaterLineColor1);
                OSDAPI_FillLineAttr(ucMainIconPos[3*2], ucMainIconPos[3*2+1]+2, 1, MAINICON_2BIT_COLOR1);
            }
            OSDAPI_FillLineAttr(ucMainIconPos[3*2], ucMainIconPos[3*2+1]+2, 1, MAINICON_2BIT_COLOR1);
            OSDAPI_FillLineAttr(ucMainIconPos[3*2]+1, ucMainIconPos[3*2+1]+2, 2, StringSeparaterLineColor1);*/
            //break;
    }
}



//******************************************************************************
// Prototype:
//  void OSDUnselectLayer2Item(UCHAR id, BOOL isUp)
// Parameters:
//  id      : current Layer2 item id
// Return:
//  None
// Purpose:
//  Unselect Layer2 item
// Notes:
//  None
//******************************************************************************
void OSDUnselectLayer2Item(UCHAR id, BOOL isUp)
{
    UCHAR i;

    //ULEric140416        
    //Clear Layer 4 When Information Page    
    if(ucMenuType == OSD_MAIN_SYSTEM && id == OSD_SYS_INFORMATION)
        ClrLayer4();
    // clear layer 3 string separater
    OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
    if (ucLayer3ItmNumTab[ucMenuType][id]) {
        //OSDShowStringSeparater(STRING_LAYER_3, TRUE);     
        // clear layer 3 string
        for (i=0; i<(ucLayer3ItmNumTab[ucMenuType][id]>8?8:ucLayer3ItmNumTab[ucMenuType][id]); i++) {
            //if (TestTable2[ucMenuType][id][i] != NULL) {
                OSDAPI_WriteXYRepeatChar(TRUE, *(ucLayer3PosInfoTab[ucMenuType]+0), (*(ucLayer3PosInfoTab[ucMenuType]+1))+i*2, INDENT_STRING_MAX_LEN, _SPACE_);    
            //}
        }
    }
    else {
        // clear layer3 item
        //OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
        for (i=0; i<15; i++) {
            OSDAPI_WriteXYRepeatChar(TRUE, ucLayer3MItem1InfoTb[0], ucLayer3MItem1InfoTb[1]+i, INDENT_STRING_MAX_LEN, _SPACE_);
        }
    }

    // clear second layer string if necessary
    if (id == 7 && isUp == FALSE) {
        for (i=0; i< 8 ; i++) {
            OSDAPI_WriteXYRepeatChar(FALSE, ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*2, INDENT_STRING_MAX_LEN, _SPACE_);
        }
    }
    else if(id == 8 && isUp == TRUE) {
        for (i=0; i< ucLayer2ItmNumTb[ucMenuType]-8 ; i++) {
            OSDAPI_WriteXYRepeatChar(FALSE, ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*2, INDENT_STRING_MAX_LEN, _SPACE_);
        }
    }

    OSDAPI_OSDWinOff(OSD_WINDOW1);//ULEric140416
    
    if (IsPage2) {
        // string row
        OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], (id-8)*2+ucLayer2ItemInfoTb[1], INDENT_STRING_MAX_LEN, UnSelectedStringColor1);

        // redraw separater line to gray color
        OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], (id-8)*2+ucLayer2ItemInfoTb[1]-1, INDENT_STRING_MAX_LEN, StringSeparaterLineColor1);
        OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], (id-8)*2+ucLayer2ItemInfoTb[1]+1, INDENT_STRING_MAX_LEN, StringSeparaterLineColor1);
    }
    else {
         // string row
        OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], id*2+ucLayer2ItemInfoTb[1], INDENT_STRING_MAX_LEN, UnSelectedStringColor1);

        // redraw separater line to gray color
        OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], id*2+ucLayer2ItemInfoTb[1]-1, INDENT_STRING_MAX_LEN, StringSeparaterLineColor1);
        OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], id*2+ucLayer2ItemInfoTb[1] +1, INDENT_STRING_MAX_LEN, StringSeparaterLineColor1);
    }
}
//******************************************************************************
// Prototype:
//  void OSDUnSelectLayer3Item(UCHAR id, BOOL IsUp)
// Parameters:
//  id      : current Layer3 item id
//  IsUp  : is going up or down
// Return:
//  None
// Purpose:
//  Unselect Layer3 item
// Notes:
//  None
//******************************************************************************
void OSDUnSelectLayer3Item(UCHAR id, BOOL IsUp)
{
    UCHAR i, tmp;

    // clear layer4 strings
    OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
    if (ucMenuType == OSD_MAIN_SYSTEM && ucSubMenuType == OSD_SYS_OSDSET) {//ULEric140415
        if((id == OSD_SYS_OSDSET_LANG&& IsUp)||(id==OSD_SYS_OSDSET_TIMER && !IsUp))//All Clear
        {
           //ClrLayer4Flags = TRUE;
           ClrLayer4();
        }
        else{//Clear String Only 
            if(id == OSD_SYS_OSDSET_LANG){
                OSDUpdateArrowIcon(CLEAR_1BIT_COLOR,ClearArrowType,STRING_LAYER_4);//Clear Arrow //ULEric140415
            }
            if((id == OSD_SYS_OSDSET_LANG)||(id == OSD_SYS_OSDSET_TIMER)){        
                for (i=0; i<(ucLayer4ItemInfoTb[id*3]>OSD_MAX_LINES? OSD_MAX_LINES:ucLayer4ItemInfoTb[id*3]); i++) {
                    OSDAPI_WriteXYRepeatChar(TRUE, ucLayer4ItemInfoTb[id*3+1], ucLayer4ItemInfoTb[id*3+2]+i*2, INDENT_STRING_MAX_LEN, _SPACE_);
                }
            }
        }        
    }
    else if (ucMenuType == OSD_MAIN_PICTURE && ucSubMenuType == OSD_PICTURE_COLORTEMP && id == CLRTMP_USER) {
        // clear color temperature color bar
        //for (i=0; i<17; i++) {
            //OSDAPI_WriteXYRepeatChar(TRUE, 48, 3+i, INDENT_STRING_MAX_LEN, _SPACE_);
        //}
        ClrLayer4();
    }else if (ucMenuType == OSD_MAIN_PICTURE_ADVANCED && ucSubMenuType == OSD_PICTURE_AD_PIC && id == PICTURE_MODE_LOW_BL) {//ULEric140415        
        ClrLayer4();
    }

    

    // clear second layer string if necessary
    OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
    
    if (ucMenuType == OSD_MAIN_SYSTEM && (ucSubMenuType == OSD_SYS_CTKEY1||ucSubMenuType == OSD_SYS_CTKEY2||ucSubMenuType == OSD_SYS_CTKEY3)) { //Customkey page
        if (id == 6 && IsUp == FALSE &&(UserData.ucCustomerKey1 == CUSTOMER_KEY_MUTE ||UserData.ucCustomerKey2 == CUSTOMER_KEY_MUTE || UserData.ucCustomerKey3 == CUSTOMER_KEY_MUTE)) {
            for (i=0; i< 8 ; i++) {
                OSDAPI_WriteXYRepeatChar(TRUE, ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*2, INDENT_STRING_MAX_LEN-2, _SPACE_);
            }
        }
        else if (id == 5 && IsUp == FALSE &&(UserData.ucCustomerKey1 == CUSTOMER_KEY_MUTE ||UserData.ucCustomerKey2 == CUSTOMER_KEY_MUTE || UserData.ucCustomerKey3 == CUSTOMER_KEY_MUTE)
            &&(UserData.ucCustomerKey1 == CUSTOMER_KEY_VOLUME||UserData.ucCustomerKey2 == CUSTOMER_KEY_VOLUME || UserData.ucCustomerKey3 == CUSTOMER_KEY_VOLUME)) {
            for (i=0; i< 8 ; i++) {
                OSDAPI_WriteXYRepeatChar(TRUE, ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*2, INDENT_STRING_MAX_LEN-2, _SPACE_);
            }
        }
        else if(id == 7 && IsUp == FALSE) {
            for (i=0; i< 8 ; i++) {
                OSDAPI_WriteXYRepeatChar(TRUE, ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*2, INDENT_STRING_MAX_LEN-2, _SPACE_);
                
            }
        }
        else if(id == 8 && IsUp == TRUE) {
            for (i=0; i< ucLayer3ItmNumTab[ucMenuType][ucSubMenuType]-8 ; i++) {
                OSDAPI_WriteXYRepeatChar(TRUE, ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*2, INDENT_STRING_MAX_LEN-2, _SPACE_);

            }
        }
    }
    else{
        if (id == 7 && IsUp == FALSE) {
            for (i=0; i< 8 ; i++) {
                OSDAPI_WriteXYRepeatChar(TRUE, ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*2, INDENT_STRING_MAX_LEN-2, _SPACE_);
            }
        }
        else if(id == 8 && IsUp == TRUE) {
            for (i=0; i< ucLayer3ItmNumTab[ucMenuType][ucSubMenuType]-8 ; i++) {
                OSDAPI_WriteXYRepeatChar(TRUE, ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*2, INDENT_STRING_MAX_LEN-2, _SPACE_);
            }
        }
    }

    tmp = (id > 7? (id-8):id);
    // redraw string to white color
    OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+tmp*2, INDENT_STRING_MAX_LEN, UnSelectedStringColor1_256);

    // redraw string separater to gray color
    OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], tmp*2+ucLayer3PosInfoTab[ucMenuType][1]-1, INDENT_STRING_MAX_LEN, StringSeparaterLineColor1);
    OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], tmp*2+ucLayer3PosInfoTab[ucMenuType][1]+1, INDENT_STRING_MAX_LEN, StringSeparaterLineColor1);

    // clear window
    OSDAPI_OSDWinOff(OSD_WINDOW1);
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
void OSDUnSelectLayer4Item(UCHAR id, BOOL IsUp)
{

    IsUp = IsUp;
     if(id >= 16){
        id -= 16;
     }
     else if(id >= 8){
        id -= 8;
    }

    // redraw string to white color
        OSDAPI_FillLineAttr( ucLayer4ItemInfoTb[ucLayer3MenuType*3+1], ucLayer4ItemInfoTb[ucLayer3MenuType*3+2]+id*2, INDENT_STRING_MAX_LEN, UnSelectedStringColor1_256);

    //ULEric140401
    // redraw string separater to gray color
    //if (IsUp)
        //OSDAPI_FillLineAttr(ucLayer4ItemInfoTb[ucLayer3MenuType*3+1], ucLayer4ItemInfoTb[ucLayer3MenuType*3+2]+1+id*2, INDENT_STRING_MAX_LEN, UnSelectedStringColor);
    //else
        //OSDAPI_FillLineAttr(ucLayer4ItemInfoTb[ucLayer3MenuType*3+1], ucLayer4ItemInfoTb[ucLayer3MenuType*3+2]-1+id*2, INDENT_STRING_MAX_LEN, UnSelectedStringColor);
    //redraw separater line to gray color
    OSDAPI_FillLineAttr(ucLayer4ItemInfoTb[ucLayer3MenuType*3+1], id*2+ucLayer4ItemInfoTb[ucLayer3MenuType*3+2]-1, INDENT_STRING_MAX_LEN, UnSelectedStringColor);
    if(id!=7)
        OSDAPI_FillLineAttr(ucLayer4ItemInfoTb[ucLayer3MenuType*3+1], id*2+ucLayer4ItemInfoTb[ucLayer3MenuType*3+2] +1, INDENT_STRING_MAX_LEN, UnSelectedStringColor);
    // clear window
    OSDAPI_OSDWinOff(OSD_WINDOW1);
}
//******************************************************************************
// Prototype:
//  void OSDExitSubItms(UCHAR itm)
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

void OSDExitSubItms(UCHAR itm)
{
    UCHAR i;
    UCHAR id;    
    itm = itm;
    id = itm;
    
    //printf("ExitSubItms: id  = %d\n", (USHRT)itm);
    // clear layer4 triangle font
    OSDShowTrianIcon(TRIANGLE_CLEAR, ucLayer3MenuType, STRING_LAYER_4);

    // clear layer4 all windows
    OSDAPI_OSDWinOff(OSD_WINDOW1);
    OSDAPI_OSDWinOff(OSD_WINDOW2);
    OSDAPI_OSDWinOff(OSD_WINDOW3);
    OSDAPI_OSDWinOff(OSD_WINDOW4);
    // clear layer4 string
    if (ucMenuType == 4) {
        OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
        for (i=0; i<(ucLayer4ItemInfoTb[ucLayer3MenuType*3]>OSD_MAX_LINES? OSD_MAX_LINES:ucLayer4ItemInfoTb[ucLayer3MenuType*3]); i++) {
            OSDAPI_WriteXYRepeatChar(TRUE, ucLayer4ItemInfoTb[ucLayer3MenuType*3+1], ucLayer4ItemInfoTb[ucLayer3MenuType*3+2]+i*2, INDENT_STRING_MAX_LEN, _SPACE_);
        }
    }
    /* //ULEric140415    
    else {
        // clear color temperature
        OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
        for (i=0; i<16; i++) {
            OSDAPI_WriteXYRepeatChar(TRUE, 47, 3+i, INDENT_STRING_MAX_LEN, _SPACE_);
        }
    }
    */
    //UL Justin 140430
/*    bug
    if((itm == CursorPos(OSD_SUBITEM_3_1_2_STATE_BEG,GetOSDState()))||(itm == CursorPos(OSD_SUBITEM_4_1_1_BEG,GetOSDState()))||(itm == CursorPos(OSD_SUBITEM_2_5_4_1_STATE,GetOSDState()))||(itm == CursorPos(OSD_SUBITEM_4_1_2_BEG,GetOSDState())))
    {
         if(id >= 16){
            id -= 16;
         }
         else if(id >= 8){
            id -= 8;
        }        
               OSDAPI_FillLineAttr(ucLayer4ItemInfoTb[ucLayer3MenuType*3+1], id*2+ucLayer4ItemInfoTb[ucLayer3MenuType*3+2]-1, INDENT_STRING_MAX_LEN, UnSelectedStringColor);
     if(id!=7)
            OSDAPI_FillLineAttr(ucLayer4ItemInfoTb[ucLayer3MenuType*3+1], id*2+ucLayer4ItemInfoTb[ucLayer3MenuType*3+2] +1, INDENT_STRING_MAX_LEN, UnSelectedStringColor);
            
    }
*/    
}
//******************************************************************************
// Prototype:
//  void OSDShowUpDownArrowIcon(UCHAR id)
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

void OSDShowUpDownArrowIcon(UCHAR id)
{
    if (ucLayer2ItmNumTb[id] > OSD_MAX_LINES) {
        OSDAPI_SetFontAttr(ArrowColor2);
        // down arrow
        OSDAPI_WriteXYChar(TRUE, 24, 20, DownArrow_1);
        OSDAPI_WriteXYChar(TRUE, 25, 20, DownArrow_2);
        OSDAPI_WriteXYChar(TRUE, 25, 21, DownArrow_3);
    }
    else {
        OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);

        // clear up arrow
        OSDAPI_WriteXYRepeatChar(TRUE, 24, 3, 2, _SPACE_);

        // clear down arrow
        OSDAPI_WriteXYRepeatChar(TRUE, 24, 20, 2, _SPACE_);
        OSDAPI_WriteXYRepeatChar(TRUE, 24, 21, 2, _SPACE_);
    }

   // string row

   OSDAPI_FillLineAttr(5, id*2+4, INDENT_STRING_MAX_LEN, StringSeparaterLineColor2);
   // separater line row
    OSDShowSmallWin(id, OSD_LAYER1_WIN);
   
   OSDAPI_FillLineAttr(5, id*2+6, INDENT_STRING_MAX_LEN, StringSeparaterLineColor2);


   OSDAPI_FillLineAttr(5, id*2+5, INDENT_STRING_MAX_LEN, SelectedStringColor);

   // icon part
   switch (id) {
       case 0:
           OSDAPI_FillLineAttr(ucMainIconPos[id*2]+1, ucMainIconPos[id*2+1], 1, SelectedStringColor);
           OSDAPI_FillLineAttr(ucMainIconPos[id*2], ucMainIconPos[id*2+1]+1, 3, SelectedStringColor);
           OSDAPI_FillLineAttr(ucMainIconPos[1*2], ucMainIconPos[1*2+1], 3, MAINICON_2BIT_COLOR2);
           break;
       case 1:
           OSDAPI_FillLineAttr(ucMainIconPos[id*2], ucMainIconPos[id*2+1], 3, MAINICON_2BIT_COLOR3);
           OSDAPI_FillLineAttr(ucMainIconPos[id*2], ucMainIconPos[id*2+1]+1, 3, SelectedStringColor);
           OSDAPI_FillLineAttr(ucMainIconPos[2*2], ucMainIconPos[2*2+1], 3, MAINICON_2BIT_COLOR2);
           break;
        case 2:
        case 3:
        case 4:
        //case 5:
           OSDAPI_FillLineAttr(ucMainIconPos[id*2], ucMainIconPos[id*2+1], 3, MAINICON_2BIT_COLOR3);
           OSDAPI_FillLineAttr(ucMainIconPos[id*2], ucMainIconPos[id*2+1]+1, 3, SelectedStringColor);
           OSDAPI_FillLineAttr(ucMainIconPos[(id+1)*2], ucMainIconPos[(id+1)*2+1], 3, MAINICON_2BIT_COLOR2);
           break;
        case 5:
           OSDAPI_FillLineAttr(ucMainIconPos[id*2], ucMainIconPos[id*2+1], 3, MAINICON_2BIT_COLOR3);
           OSDAPI_FillLineAttr(ucMainIconPos[id*2], ucMainIconPos[id*2+1]+1, 3, SelectedStringColor);
           OSDAPI_FillLineAttr(ucMainIconPos[id*2], ucMainIconPos[id*2+1]+2, 3, SelectedStringColor1);
           break;
 /*       case 3:
           OSDAPI_FillLineAttr(ucMainIconPos[id*2]+1, ucMainIconPos[id*2+1], 1, MAINICON_2BIT_COLOR3);
           OSDAPI_FillLineAttr(ucMainIconPos[id*2], ucMainIconPos[id*2+1], 1, StringSeparaterLineColor2);
           OSDAPI_FillLineAttr(ucMainIconPos[id*2]+2, ucMainIconPos[id*2+1], 1, StringSeparaterLineColor2);
           OSDAPI_FillLineAttr(ucMainIconPos[id*2], ucMainIconPos[id*2+1]+1, 3, SelectedStringColor);
           OSDAPI_FillLineAttr(ucMainIconPos[id*2], ucMainIconPos[id*2+1]+2, 1, MAINICON_2BIT_COLOR3);
           OSDAPI_FillLineAttr(ucMainIconPos[id*2]+1, ucMainIconPos[id*2+1]+2, 2, StringSeparaterLineColor2);
        case 4:
           OSDAPI_FillLineAttr(ucMainIconPos[id*2]+1, ucMainIconPos[id*2+1], 1, MAINICON_2BIT_COLOR3);
           OSDAPI_FillLineAttr(ucMainIconPos[id*2], ucMainIconPos[id*2+1], 1, StringSeparaterLineColor2);
           OSDAPI_FillLineAttr(ucMainIconPos[id*2]+2, ucMainIconPos[id*2+1], 1, StringSeparaterLineColor2);
           OSDAPI_FillLineAttr(ucMainIconPos[id*2], ucMainIconPos[id*2+1]+1, 3, SelectedStringColor);
           OSDAPI_FillLineAttr(ucMainIconPos[id*2], ucMainIconPos[id*2+1]+2, 1, MAINICON_2BIT_COLOR3);
           OSDAPI_FillLineAttr(ucMainIconPos[id*2]+1, ucMainIconPos[id*2+1]+2, 2, StringSeparaterLineColor2);
            break;*/
        }
}

//******************************************************************************
// Prototype:
//  void OSDUpdateSelectPageIcon(void)
// Parameters:
//  id      : the id of SelectPage Icon
// act     : Use to indicate the offset from frame start.
// current we have 3 kinds of frame width.
// Return:
//  None
// Purpose:
//  Draw SelectPage icon right of Main menu.
// Notes:
//  None
//******************************************************************************
void OSDUpdateSelectPageIcon(UCHAR id, UCHAR IconOffset, UCHAR ButtonAction, UCHAR Layer, BOOL ENABLE1)
{
#if 1//ULEric140328
    UCHAR i,j,k,m;
    UCHAR Offset; 
    
    WaitDisVSync();
    id = id;
    ENABLE1= ENABLE1;
    if (IconOffset == 0) {
        Offset = OSD_MAIN_WIDTH-7+3; // 7 is selected page width
    }
    else if (IconOffset == 1) {
        Offset = OSD_CUSTOMERKEY_MENU1_WIDTH-7+3; // 7 is selected page width
    }
    else if (IconOffset== 2) {
        Offset = OSD_CUSTOMERKEY_MENU2_WIDTH-7+3; // 7 is selected page width
    }
    else if (IconOffset== 3) {//ULEric140410
        Offset = OSD_DIALOG_SELECTPAGE_WIDTH-7+3; // 7 is selected page width
    }

    if(Layer == DIALOG_LAYER)//ULEric140410
    {
            OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_HOOK_COLOR);
        for (i=0; i<SPIconItmNumTab[5]; i++) {
            OSDAPI_WriteXYChar(TRUE, Offset+SPIconPosInfoTab[5][i*2], SPIconPosInfoTab[5][i*2+1]-8, SP_Icon6_1Bit_1+i);
        }
        OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_EXIT_COLOR);
        for (i=0; i<SPIconItmNumTab[4]; i++) {
            OSDAPI_WriteXYChar(TRUE, Offset+SPIconPosInfoTab[4][i*2], SPIconPosInfoTab[4][i*2+1]-12, SP_Icon5_1Bit_1+i);
        }        
    }
    else{        
    if(ButtonAction & OSDKEYINFO_OK)
        m = 6;
    else
    m = 5;
    k = 0;
    for(j=0;j<m;j++)
    {    
        if((ButtonAction& (OSDKEYINFO_UP<<j)))
        {
            if(j==5)
                OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_HOOK_COLOR);
            else    
                OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1);
            for (i=0; i<SPIconItmNumTab[j]; i++) {
                OSDAPI_WriteXYChar(TRUE, Offset+SPIconPosInfoTab[j][i*2], SPIconPosInfoTab[j][i*2+1], SP_Icon1_1Bit_1+i+k);
            }
        }
        else{//SPACE
            if(j!=4)
            {
                OSDAPI_SetFontAttr(SELECTPAGE_1BIT_COLOR1);
                for (i=0; i<SPIconItmNumTab[j]; i++) {
                    OSDAPI_WriteXYChar(TRUE, Offset+SPIconPosInfoTab[j][i*2], SPIconPosInfoTab[j][i*2+1], _SPACE_);
                }
            }
        }
        k+= SPIconItmNumTab[j];
           
        }
    }
    WaitDisVSync();
#else
    UCHAR i;
    UCHAR Offset;

    ButtonAction = ButtonAction;    
    if (IconOffset == 0) {
        Offset = OSD_MAIN_WIDTH-7+3; // 7 is selected page width
    }
    else if (IconOffset == 1) {
        Offset = OSD_CUSTOMERKEY_MENU1_WIDTH-7+3; // 7 is selected page width
    }
    else if (IconOffset== 2) {
        Offset = OSD_CUSTOMERKEY_MENU2_WIDTH-7+3; // 7 is selected page width
    }
    //printf("OSDUpdateSelectPageIcon %x\r\n",(USHRT)id);
    switch (Layer) {
        case STRING_LAYER_2:
        // in this case, when layer2 item number exceed 8, clear the bottom and top icon when reach it.

        // update up down icon
        if (ucLayer2ItmNumTb[ucMenuType] > OSD_MAX_LINES) {
            if (id == 0) {
                if (ENABLE1) {
                    OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1);
                    for (i=0; i<SPIconItmNumTab[0]; i++) {
                        OSDAPI_WriteXYChar(TRUE, Offset+SPIconPosInfoTab[0][i*2], SPIconPosInfoTab[0][i*2+1], SP_Icon1_1Bit_1+i);
                    }
                    //printf("id0_L2_EN0\r\n");
                }
                else {
                    OSDAPI_SetFontAttr(SELECTPAGE_1BIT_COLOR1);
                    for (i=0; i<SPIconItmNumTab[0]; i++) {
                        OSDAPI_WriteXYChar(TRUE, Offset+SPIconPosInfoTab[0][i*2], SPIconPosInfoTab[0][i*2+1], _SPACE_);
                    }
                    //printf("id0_L2_DEN0\r\n");
                }
            }
            else if (id == (ucLayer2ItmNumTb[ucMenuType]-1)) {
                if (ENABLE1) {
                    OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1);
                    for (i=0; i<SPIconItmNumTab[1]; i++) {
                        OSDAPI_WriteXYChar(TRUE, Offset+SPIconPosInfoTab[1][i*2], SPIconPosInfoTab[1][i*2+1], SP_Icon2_1Bit_1+i);
                    }
                    //printf("id1_L2_EN1_\r\n");
                }
                else {
                    OSDAPI_SetFontAttr(SELECTPAGE_1BIT_COLOR1);
                    for (i=0; i<SPIconItmNumTab[1]; i++) {
                        OSDAPI_WriteXYChar(TRUE, Offset+SPIconPosInfoTab[1][i*2], SPIconPosInfoTab[1][i*2+1], _SPACE_);
                    }
                    //printf("id1_L2_DEN1_\r\n");
                }
            }
            else {
                OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1);
                for (i=0; i<SPIconItmNumTab[0]; i++) {
                    OSDAPI_WriteXYChar(TRUE, Offset+SPIconPosInfoTab[0][i*2], SPIconPosInfoTab[0][i*2+1], SP_Icon1_1Bit_1+i);
                }
                for (i=0; i<SPIconItmNumTab[1]; i++) {
                    OSDAPI_WriteXYChar(TRUE, Offset+SPIconPosInfoTab[1][i*2], SPIconPosInfoTab[1][i*2+1], SP_Icon2_1Bit_1+i);
                }
          
          if(GetOSDState()>=OSD_MAIN_4_1_STATE && GetOSDState()<OSD_MAIN_4_END)//ULEric140327
          {
              if(GetOSDState() == OSD_MAIN_4_10_STATE)
              {
                  OSDAPI_SetFontAttr(SELECTPAGE_1BIT_COLOR1);
                            for (i=0; i<SPIconItmNumTab[2]; i++) {
                                OSDAPI_WriteXYChar(TRUE, Offset+SPIconPosInfoTab[2][i*2], SPIconPosInfoTab[2][i*2+1], _SPACE_);
                            }
              }
            else{            
                OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1);
                        for (i=0; i<SPIconItmNumTab[2]; i++) {
                                OSDAPI_WriteXYChar(TRUE, Offset+SPIconPosInfoTab[2][i*2], SPIconPosInfoTab[2][i*2+1], SP_Icon3_1Bit_1+i);
                        }       
              }
          }
                //printf("L2_01\r\n");
            }
        }
     else{//ULEric140327
        if(ENABLE1){
            OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1);
                   for (i=0; i<SPIconItmNumTab[2]; i++) {
                            OSDAPI_WriteXYChar(TRUE, Offset+SPIconPosInfoTab[2][i*2], SPIconPosInfoTab[2][i*2+1], SP_Icon3_1Bit_1+i);
                    }     
        }
        else{
            if(OSDCheckHookIcon())
            {
                OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_HOOK_COLOR);
                            for (i=0; i<SPIconItmNumTab[2]; i++) {
                                OSDAPI_WriteXYChar(TRUE, Offset+SPIconPosInfoTab[2][i*2], SPIconPosInfoTab[2][i*2+1], SP_Icon6_1Bit_1+i);
                            }
            }else{
                OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1);
                        for (i=0; i<SPIconItmNumTab[2]; i++) {
                                OSDAPI_WriteXYChar(TRUE, Offset+SPIconPosInfoTab[2][i*2], SPIconPosInfoTab[2][i*2+1], SP_Icon3_1Bit_1+i);
                        }     
            }
        }        
        }
        break;
    case STRING_LAYER_3:
        // in this case, when layer3 item number exceed 8, clear the bottom and top icon when reach it.
        // and if this item don't have l

        // update up down icon
        //printf("ucMenuType = %02BX\r\n",ucMenuType);
        //printf("ucSubMenuType = %02BX\r\n",ucSubMenuType);
        //printf("id - %02BX\r\n",id);
        if (ucLayer3ItmNumTab[ucMenuType][ucSubMenuType] > OSD_MAX_LINES) {        
            if (id == 0) {
                if (ENABLE1) {
                    OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1);
                    for (i=0; i<SPIconItmNumTab[0]; i++) {
                        OSDAPI_WriteXYChar(TRUE, Offset+SPIconPosInfoTab[0][i*2], SPIconPosInfoTab[0][i*2+1], SP_Icon1_1Bit_1+i);
                    }
                    //printf("id0_L3_EN0\r\n");    
                }
                else {
                    OSDAPI_SetFontAttr(SELECTPAGE_1BIT_COLOR1);
                    for (i=0; i<SPIconItmNumTab[0]; i++) {
                        OSDAPI_WriteXYChar(TRUE, Offset+SPIconPosInfoTab[0][i*2], SPIconPosInfoTab[0][i*2+1], _SPACE_);
                    }
                    //printf("id0_L3_DEN0\r\n");
                }
            }
            else if (id == ucLayer3ItmNumTab[ucMenuType][ucSubMenuType]-1) {
                if (ENABLE1) {
                    OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1);
                    for (i=0; i<SPIconItmNumTab[1]; i++) {
                        OSDAPI_WriteXYChar(TRUE, Offset+SPIconPosInfoTab[1][i*2], SPIconPosInfoTab[1][i*2+1], SP_Icon2_1Bit_1+i);
                    }
                    //printf("id1_L3_EN1_\r\n");
                }
                else {
                    OSDAPI_SetFontAttr(SELECTPAGE_1BIT_COLOR1);
                    for (i=0; i<SPIconItmNumTab[1]; i++) {
                        OSDAPI_WriteXYChar(TRUE, Offset+SPIconPosInfoTab[1][i*2], SPIconPosInfoTab[1][i*2+1], _SPACE_);
                    }
                    //printf("id1_L3_DEN1_\r\n");
                }
            }
            else {
                    OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1);
                    for (i=0; i<SPIconItmNumTab[0]; i++) {
                        OSDAPI_WriteXYChar(TRUE, Offset+SPIconPosInfoTab[0][i*2], SPIconPosInfoTab[0][i*2+1], SP_Icon1_1Bit_1+i);
                         }
                    for (i=0; i<SPIconItmNumTab[1]; i++) {
                        OSDAPI_WriteXYChar(TRUE, Offset+SPIconPosInfoTab[1][i*2], SPIconPosInfoTab[1][i*2+1], SP_Icon2_1Bit_1+i);
                    }
                    //printf("L3_01\r\n");
            }
                    
            // update hook icon
            if (ENABLE1) {
                OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1);
                for (i=0; i<SPIconItmNumTab[0]; i++) {
                    OSDAPI_WriteXYChar(TRUE, Offset+SPIconPosInfoTab[0][i*2], SPIconPosInfoTab[0][i*2+1], SP_Icon1_1Bit_1+i);
                }
                //printf("EN_Update0\r\n");
            }
            else {
                OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_HOOK_COLOR);
                for (i=0; i<SPIconItmNumTab[0]; i++) {
                    OSDAPI_WriteXYChar(TRUE, Offset+SPIconPosInfoTab[0][i*2], SPIconPosInfoTab[0][i*2+1], SP_Icon1_1Bit_1+i);
                }
                //printf("DN_Update0\r\n");
            }
        }
        else {
            if (ENABLE1) {
                if(id == 0) {
                    if((ucMenuType == 1)||(ucMenuType == 4))
                    {
                        OSDAPI_SetFontAttr(SELECTPAGE_1BIT_COLOR1);
                        for (i=0; i<SPIconItmNumTab[0]; i++) {
                            OSDAPI_WriteXYChar(TRUE, Offset+SPIconPosInfoTab[0][i*2], SPIconPosInfoTab[0][i*2+1], _SPACE_);
                        }
                        //printf("id=0else EN3\r\n");
                    }
                }

                OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1);
                for (i=0; i<SPIconItmNumTab[2]; i++) {
                    OSDAPI_WriteXYChar(TRUE, Offset+SPIconPosInfoTab[2][i*2], SPIconPosInfoTab[2][i*2+1], SP_Icon3_1Bit_1+i);
                }                                                
                //printf("else EN3 %02BX\r\n",Offset);
                if(GetOSDState() == OSD_MAIN_2_9_STATE ||GetOSDState() == OSD_MAIN_4_12_STATE )//ULEric140327
                {
                    OSDAPI_SetFontAttr(SELECTPAGE_1BIT_COLOR1);
                    for (i=0; i<SPIconItmNumTab[1]; i++) {
                            OSDAPI_WriteXYChar(TRUE, Offset+SPIconPosInfoTab[1][i*2], SPIconPosInfoTab[1][i*2+1], _SPACE_);
                    }
                }
            }
            else {                    
                //if(ucMenuType != 4) {
              if(OSDCheckHookIcon())//ULEric140327              
              {
                            OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_HOOK_COLOR);
                            for (i=0; i<SPIconItmNumTab[2]; i++) {
                                OSDAPI_WriteXYChar(TRUE, Offset+SPIconPosInfoTab[2][i*2], SPIconPosInfoTab[2][i*2+1], SP_Icon6_1Bit_1+i);
                            }
              }else{
                    OSDAPI_SetFontAttr(SELECTPAGE_1BIT_COLOR1);
                    for (i=0; i<SPIconItmNumTab[2]; i++) {
                        OSDAPI_WriteXYChar(TRUE, Offset+SPIconPosInfoTab[2][i*2], SPIconPosInfoTab[2][i*2+1], _SPACE_);
                    }
                }
                              
                OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1);
                for (i=0; i<SPIconItmNumTab[0]; i++) {
                    OSDAPI_WriteXYChar(TRUE, Offset+SPIconPosInfoTab[0][i*2], SPIconPosInfoTab[0][i*2+1], SP_Icon1_1Bit_1+i);
                }                     

         OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1);//ULEric140327
                for (i=0; i<SPIconItmNumTab[1]; i++) {
                    OSDAPI_WriteXYChar(TRUE, Offset+SPIconPosInfoTab[1][i*2], SPIconPosInfoTab[1][i*2+1], SP_Icon2_1Bit_1+i);
                }
            }            
        }
        break;
    case STRING_LAYER_4:
        // to do...

    break;
    }
#endif
}

//******************************************************************************
// Prototype:
//  void OSDShowSelectPageIcon(UCHAR id, UCHAR act)
// Parameters:
//  id      : the id of SelectPage Icon
// act     : Use to indicate the offset from frame start.
// current we have 3 kinds of frame width.
// Return:
//  None
// Purpose:
//  Draw SelectPage icon right of Main menu.
// Notes:
//  None
//******************************************************************************
void OSDShowSelectPageIcon(UCHAR id, UCHAR act)
{
    UCHAR i;
    UCHAR Offset;
    USHRT FontIndex;

    if (act == 0) {
        Offset = OSD_MAIN_WIDTH-7+3; // 7 is selected page width
    }
    else if (act == 1) {
        Offset = OSD_CUSTOMERKEY_MENU1_WIDTH-7+3; // 7 is selected page width
    }
    else if (act== 2) {
        Offset = OSD_CUSTOMERKEY_MENU2_WIDTH-7+3; // 7 is selected page width
    }
     else if (act== 3) {
        Offset = OSD_DIALOG_SELECTPAGE_WIDTH-7+3; // 7 is selected page width
    }

    OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1);
    switch (id) {
        case 0:
            FontIndex = SP_Icon1_1Bit_1;
        break;
        case 1:
            FontIndex = SP_Icon2_1Bit_1;
        break;
        case 2:
            if (act == 1) {            
                OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_HOOK_COLOR);                
                FontIndex = SP_Icon6_1Bit_1;
                id = 5;
            }
            else if (act== 2) {            
                return;            
            }
         else{            
                FontIndex = SP_Icon3_1Bit_1;
         }            
        break;
        case 3:
                FontIndex = SP_Icon4_1Bit_1;
        break;
        case 4:
            OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_EXIT_COLOR);
            FontIndex = SP_Icon5_1Bit_1;
        break;
    }

    for (i=0; i<SPIconItmNumTab[id]; i++) {
        OSDAPI_WriteXYChar(TRUE, Offset+SPIconPosInfoTab[id][i*2], SPIconPosInfoTab[id][i*2+1], FontIndex+i);        
    }
}

//******************************************************************************
// Prototype:
//  void OSDExitItms(UCHAR itm)
// Parameters:
//  itm     : Layer3 item id
// Return:
//  None
// Purpose:
//  Exit Layer3 state and go back to Layer2 state
// Notes:
//  None
//******************************************************************************
void OSDExitItms(UCHAR itm)
{
    UCHAR i;
    UCHAR tmp;

    // clear layer3 second level up arrow if necessary.
    if (itm > 7) {
        // clear up arrow
        OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
        OSDAPI_WriteXYRepeatChar(TRUE, 38, 3, 2, _SPACE_);
    }
    //ULEric140415
    // clear layer4 string and string separater
    if(ucMenuType == OSD_MAIN_SYSTEM && ucSubMenuType == OSD_SYS_OSDSET&&itm<2)//for Language/OSD Timer
        ClrLayer4();
    else if(ucMenuType == OSD_MAIN_PICTURE && ucSubMenuType == OSD_PICTURE_COLORTEMP && itm == 3)//for UserColor Menu
        ClrLayer4();
    else if(ucMenuType == OSD_MAIN_PICTURE_ADVANCED && ucSubMenuType == OSD_PICTURE_AD_PIC && itm == PICTURE_MODE_LOW_BL)//for LBL Menu
        ClrLayer4();                
    /*
    if ((ucMenuType == OSD_MAIN_SYSTEM && ucSubMenuType == OSD_SYS_OSDSET) || (ucMenuType == OSD_MAIN_PICTURE_ADVANCED && ucSubMenuType == OSD_PICTURE_AD_PIC)) {
        if (ucLayer3MenuType == 0 || ucLayer3MenuType == 1) {
            OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
            for (i=0; i<(ucLayer4ItemInfoTb[itm*3]>OSD_MAX_LINES? OSD_MAX_LINES:ucLayer4ItemInfoTb[itm*3]); i++) {
                OSDAPI_WriteXYRepeatChar(TRUE, ucLayer4ItemInfoTb[ucLayer3MenuType*3+1], ucLayer4ItemInfoTb[ucLayer3MenuType*3+2]+i*2, INDENT_STRING_MAX_LEN, _SPACE_);
            }
        }
        OSDShowStringSeparater(STRING_LAYER_4, TRUE);
    }
    else if (ucMenuType == OSD_MAIN_PICTURE && ucSubMenuType == OSD_PICTURE_COLORTEMP && ucLayer3MenuType == 3) {
        // clear color temperature color bar
        OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
        for (i=0; i<17; i++) {
            OSDAPI_WriteXYRepeatChar(TRUE, 48, 3+i, 14, _SPACE_);
        }
    }
    */

    if (ucLayer3ItmNumTab[ucMenuType][ucSubMenuType]) {
        // clear layer3 all windows if has string to show
        OSDAPI_OSDWinOff(OSD_WINDOW1);
        OSDAPI_OSDWinOff(OSD_WINDOW3);
        OSDAPI_OSDWinOff(OSD_WINDOW4);

/*
        // redraw string color
        for (i=0; i<(ucLayer3ItmNumTab[ucMenuType][ucSubMenuType]>8? 8:ucLayer3ItmNumTab[ucMenuType][ucSubMenuType]); i++) {
            if (ucMenuType == (OSD_MAIN_4_STATE - OSD_MAIN_BEG)
                && (ucSubMenuType == (OSD_MAIN_4_2_STATE-OSD_MAIN_3_END) || ucSubMenuType == (OSD_MAIN_4_3_STATE-OSD_MAIN_3_END) || ucSubMenuType == (OSD_MAIN_4_4_STATE-OSD_MAIN_3_END))) {
                switch (ucSubMenuType) {
                    case (OSD_MAIN_4_2_STATE-OSD_MAIN_3_END): // Customer Key 1
                        if (i == UserData.ucCustomerKey2 || i == UserData.ucCustomerKey3) {
                            OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*2, INDENT_STRING_MAX_LEN, DisabledStringColor_256);
                        }
                        else {
                            OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*2, INDENT_STRING_MAX_LEN, UnSelectedStringColor1_256);
                        }
                    break;

                    case (OSD_MAIN_4_3_STATE-OSD_MAIN_3_END): // Customer Key 2
                        if (i == UserData.ucCustomerKey1 || i == UserData.ucCustomerKey3) {
                            OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*2, INDENT_STRING_MAX_LEN, DisabledStringColor_256);
                        }
                        else {
                            OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*2, INDENT_STRING_MAX_LEN, UnSelectedStringColor1_256);
                        }
                    break;

                    case (OSD_MAIN_4_4_STATE-OSD_MAIN_3_END): // Customer Key 3
                        if (i == UserData.ucCustomerKey1 || i == UserData.ucCustomerKey2) {
                            OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*2, INDENT_STRING_MAX_LEN, DisabledStringColor_256);
                        }
                        else {
                            OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*2, INDENT_STRING_MAX_LEN, UnSelectedStringColor1_256);
                        }
                    break;
                }
            }
            else {
                OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*2, INDENT_STRING_MAX_LEN, UnSelectedStringColor1_256);
            }

            OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*2, INDENT_STRING_MAX_LEN, UnSelectedStringColor1_256);
        }
*/

        // redraw string separater color
        for (i=0; i<7; i++) {
            OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]-1+i*2, INDENT_STRING_MAX_LEN, UnSelectedStringColor);
            OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+1+i*2, INDENT_STRING_MAX_LEN, UnSelectedStringColor);
        }
    }
    else {
        // clear only big windows cuz no string to show
        OSDAPI_OSDWinOff(OSD_WINDOW1);
        OSDAPI_OSDWinOff(OSD_WINDOW3);
        OSDAPI_OSDWinOff(OSD_WINDOW4);
    }
    tmp = (ucSubMenuType>7)? (ucSubMenuType-8): ucSubMenuType;

    // clear layer3 triangle font
    OSDShowTrianIcon(TRIANGLE_CLEAR, tmp, STRING_LAYER_3);

    // clear Layer3 separater
    OSDShowLayerSeparater(STRING_LAYER_3, ucSubMenuType, TRUE);
}

void OSDCustomerMenuUp(void)
{
    UCHAR Item;
    UCHAR start_state, end_state;

    Item = fnGetCustomerKeyItem();

    if((Item == CUSTOMER_KEY_DISPLAYMODE) && (isOnlyFullAspectRatio())){ // native mode no need to execute
        return;
    }
    
    switch (Item) {
        case CUSTOMER_KEY_INPUT:
            start_state = OSD_CUSTKEY_INPUT_1_STATE;
            end_state = OSD_CUSTKEY_INPUT_END;
            break;
        case CUSTOMER_KEY_DISPLAYMODE:
            start_state = OSD_CUSTKEY_DISPLAYMODE_1_STATE;
            end_state = OSD_CUSTKEY_DISPLAYMODE_END;
            break;
        case CUSTOMER_KEY_PICTUREMODE:
            start_state = OSD_CUSTKEY_PICTUREMODE_1_STATE;
            end_state = OSD_CUSTKEY_PICTUREMODE_END;
//#if PICTURE_MODE_NUM > 8
//            if (GetOSDState()<= start_state)
///                return;
//#endif // FORCE_NON_CIRCLE_ACTION
            break;
        //ULEric140331
        case CUSTOMER_KEY_MUTE:
            start_state = OSD_CUSTKEY_MUTE_1_STATE;
            end_state = OSD_CUSTKEY_MUTE_END;
            break;
        case CUSTOMER_KEY_SMARTREMINDER:
            start_state = OSD_CUSTKEY_SMARTREMINDER_1_STATE;
            end_state = OSD_CUSTKEY_SMARTREMINDER_END;
            break;
        case CUSTOMER_KEY_LOWBULELIGHTMODE:
            start_state = OSD_CUSTKEY_LOWBULELIGHTMODE_1_STATE;
            end_state = OSD_CUSTKEY_LOWBULELIGHTMODE_END;
            break;
        default:
            break;
    }
    
    OSDUnSelectDialogItem(CursorPos(start_state,GetOSDState()), TRUE);
    
    while (1) {
#if FORCE_NON_CIRCLE_ACTION == ON
        //if (Item == CUSTOMER_KEY_PICTUREMODE){
            //SetOSDState(NonCirclePrevState(start_state,end_state,GetOSDState()));            
        //}
        //else {
            SetOSDState(PrevState(start_state,end_state,GetOSDState()));
        //}
#else
        SetOSDState(PrevState(start_state,end_state,GetOSDState()));
#endif
        if (OSDIsCustomkeyItemValid(CursorPos(start_state,GetOSDState())) == TRUE)
            break;
    }
    OSDSelectDialogItem(CursorPos(start_state,GetOSDState()), TRUE);
    
    //printf("Up:usOSDState %x\r\n",(USHRT)GetOSDState());
    if (Item == CUSTOMER_KEY_PICTUREMODE) {
        OSDSetBFMenuITM(CursorPos(start_state,GetOSDState()));
    }
    else if (Item == CUSTOMER_KEY_DISPLAYMODE) {
        
     if (!(pInputTiming->usModeHActive == PANEL_WIDTH && pInputTiming->usModeVActive == PANEL_HEIGHT)) {
        OSDSetAspectRatio(CursorPos(start_state,GetOSDState()));   
     }
    }
    else if (Item == CUSTOMER_KEY_LOWBULELIGHTMODE) {
        UserData.ucLBLMode = CursorPos(start_state,GetOSDState());   
        SetLBLMode();
    }  
    else if (Item == CUSTOMER_KEY_MUTE) {
        UserData.bAudioMute = !UserData.bAudioMute;
        UserSetVolumeAndMute();   
    }  
    else { //CUSTOMER_KEY_INPUT

    }
}

void OSDCustomerMenuDown(void)
{
    UCHAR Item;
    UCHAR start_state, end_state;

    Item = fnGetCustomerKeyItem();

    if(Item == CUSTOMER_KEY_DISPLAYMODE && (isOnlyFullAspectRatio())){ // native mode no need to execute
        return;
    }
    
    switch (Item) {
        case CUSTOMER_KEY_INPUT:
            start_state = OSD_CUSTKEY_INPUT_1_STATE;
            end_state = OSD_CUSTKEY_INPUT_END;
            break;
        case CUSTOMER_KEY_DISPLAYMODE:
            start_state = OSD_CUSTKEY_DISPLAYMODE_1_STATE;
            end_state = OSD_CUSTKEY_DISPLAYMODE_END;
        break;
        case CUSTOMER_KEY_PICTUREMODE:
            start_state = OSD_CUSTKEY_PICTUREMODE_1_STATE;
            end_state = OSD_CUSTKEY_PICTUREMODE_END;
#if FORCE_NON_CIRCLE_ACTION == ON
            if ((GetOSDState()>= end_state-1)&&(Item != CUSTOMER_KEY_PICTUREMODE))
                return;
#endif // FORCE_NON_CIRCLE_ACTION
        break;
    //ULEric140331
        case CUSTOMER_KEY_MUTE:
            start_state = OSD_CUSTKEY_MUTE_1_STATE;
            end_state = OSD_CUSTKEY_MUTE_END;
            break;
        case CUSTOMER_KEY_SMARTREMINDER:
            start_state = OSD_CUSTKEY_SMARTREMINDER_1_STATE;
            end_state = OSD_CUSTKEY_SMARTREMINDER_END;
            break;
        case CUSTOMER_KEY_LOWBULELIGHTMODE:
            start_state = OSD_CUSTKEY_LOWBULELIGHTMODE_1_STATE;
            end_state = OSD_CUSTKEY_LOWBULELIGHTMODE_END;
            break;
        default:
            break;
    }

    OSDUnSelectDialogItem(CursorPos(start_state,GetOSDState()), FALSE);
    while (1) {
#if FORCE_NON_CIRCLE_ACTION == ON
        //if (Item == CUSTOMER_KEY_PICTUREMODE) {
            //SetOSDState(NonCircleNextState(start_state,end_state,GetOSDState()));
        //}
        //else {
            SetOSDState(NextState(start_state,end_state,GetOSDState()));
        //}
#else
        SetOSDState(NextState(start_state,end_state,GetOSDState()));
#endif
        if (OSDIsCustomkeyItemValid(CursorPos(start_state,GetOSDState())) == TRUE)
            break;
    }
    OSDSelectDialogItem(CursorPos(start_state,GetOSDState()), FALSE);

    if (Item == CUSTOMER_KEY_PICTUREMODE) {
        //OSDBFMenuITMDn();
        if(UserData.ucBFMode == (PICTURE_MODE_NUM -1)){
            OSDSetBFMenuITM(0);
        }
        else{
        OSDSetBFMenuITM(CursorPos(start_state,GetOSDState()));
    }
    }
    else if (Item == CUSTOMER_KEY_DISPLAYMODE) {
        //OSDAspectRatioDown();
        if (!(pInputTiming->usModeHActive == PANEL_WIDTH && pInputTiming->usModeVActive == PANEL_HEIGHT)) {
            OSDSetAspectRatio(CursorPos(start_state,GetOSDState())); 
        }
    }
    else if (Item == CUSTOMER_KEY_LOWBULELIGHTMODE) {
        UserData.ucLBLMode = CursorPos(start_state,GetOSDState());            
       SetLBLMode();
    }        
    else if (Item == CUSTOMER_KEY_MUTE) {
        UserData.bAudioMute = !UserData.bAudioMute;
        UserSetVolumeAndMute();    
    }      
    else { //CUSTOMER_KEY_INPUT

    }
}

//******************************************************************************
// Prototype:
//  void OSDTurnOnOSD(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Turn on OSD
// Notes:
//  None
//******************************************************************************
void OSDTurnOnOSD(void)
{
#if ENABLE_OSD_ROTATION == ON
    if (UserData.bOSDRotation) {
        OSDAPI_RotateOSDWin(OSD_WINDOW1, OSD_POS_ROT_270);
        OSDAPI_RotateOSDWin(OSD_WINDOW2, OSD_POS_ROT_270);
        OSDAPI_RotateOSDWin(OSD_WINDOW3, OSD_POS_ROT_270);
        OSDAPI_RotateOSDWin(OSD_WINDOW4, OSD_POS_ROT_270);
        OSDAPI_RotateOSDWin(OSD_WINDOW5, OSD_POS_ROT_270);
        OSDAPI_RotateOSDWin(OSD_WINDOW6, OSD_POS_ROT_270);
        OSDAPI_RotateOSDWin(OSD_WINDOW7, OSD_POS_ROT_270);
        OSDAPI_RotateOSDWin(OSD_WINDOW8, OSD_POS_ROT_270);
        OSDAPI_Rotated_270_OSD();
        Sleep(80);
    }
    else {
        OSDAPI_RotateOSDWin(OSD_WINDOW1, OSD_POS_ROT_OFF);
        OSDAPI_RotateOSDWin(OSD_WINDOW2, OSD_POS_ROT_OFF);
        OSDAPI_RotateOSDWin(OSD_WINDOW3, OSD_POS_ROT_OFF);
        OSDAPI_RotateOSDWin(OSD_WINDOW4, OSD_POS_ROT_OFF);
        OSDAPI_RotateOSDWin(OSD_WINDOW5, OSD_POS_ROT_OFF);
        OSDAPI_RotateOSDWin(OSD_WINDOW6, OSD_POS_ROT_OFF);
        OSDAPI_RotateOSDWin(OSD_WINDOW7, OSD_POS_ROT_OFF);
        OSDAPI_RotateOSDWin(OSD_WINDOW8, OSD_POS_ROT_OFF);
        Sleep(80);
    }
#endif //ENABLE_OSD_ROTATION == ON
#if ENABLE_DBC == ON
#if ENABLE_DBC_HW_DEBOUNCE == OFF
    ClearDBCCounter();
#endif
#endif
    OSDAPI_TurnOnOSD();
}

//******************************************************************************
// Prototype:
//  void OSDShowInputMenu(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Show input dialog when press input button on TopPage menu.
// Notes:
//  None
//******************************************************************************
void OSDShowInputMenu(void)
{
    UCHAR i,OSDindex;

    OSDLoadFont(ShowInputMenu_font);
    OSDInitFrame(OSD_CUSTOMERKEY_MENU1_WIDTH, OSD_CUSTOMERKEY_MENU1_HEIGHT, MAIN_FRAME_COLOR);

    OSDAPI_SetIndentIndex(String_TopPage_Index);

    OSDShowBenQMainFrame(FrameWidthType_CustomerMenu1);
    OSDShowSelectPageMainFrame(FrameWidthType_CustomerMenu1);
    for (i=0; i<5; i++){
        OSDShowSelectPageIcon(i, 1);
    }
    OSDShowTopPageIcon(TP_INPUT, 1, 0);
    OSDShowBigWin(OSD_DIALOG_LAYER_WIN, OSD_WIN_BOARDER_SIZE);
    OSDShowStringSeparater(DIALOG_LAYER, FALSE);
    
    OSDindex = GetOSDState()-OSD_CUSTKEY_INPUT_1_STATE;
    OSDSelectDialogItem(OSDindex, 0);

    UserSetTransparent();
    OSDSetPosition(OSD_HOTKEY_MENU_H_POSITION,OSD_HOTKEY_MENU_V_POSITION);//zoe test
    OSDTurnOnOSD();
}
#if 0
//******************************************************************************
// Prototype:
//  void OSDShowAutoAdjustmentMenu(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Show AutoAdjustment dialog when press AutoAdjustment button on TopPage menu.
// Notes:There's no menu need to show at this point, only need to show the auto adjustment
// dialog.
//******************************************************************************
void OSDShowAutoAdjustmentMenu(void)
{
    // todo...
    if (GetInputSyncMode() == DIG_SYNC) {
     OSDCloseAll();
        return;
    }
    UserSetTransparent();
    OSDTurnOnOSD();
}
#endif
//******************************************************************************
// Prototype:
//  void OSDShowDisplayModeMenu(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Show DisplayMode dialog when press DisplayMode button on TopPage menu.
// Notes:None
//******************************************************************************
void OSDShowDisplayModeMenu(void)
{
    UCHAR i;
 
    OSDLoadFont(DisplayModeMenu_font);
    OSDInitFrame(OSD_CUSTOMERKEY_MENU1_WIDTH, OSD_CUSTOMERKEY_MENU1_HEIGHT, MAIN_FRAME_COLOR);

    OSDAPI_SetIndentIndex(String_TopPage_Index);

    OSDShowBenQMainFrame(FrameWidthType_CustomerMenu1);
    OSDShowSelectPageMainFrame(FrameWidthType_CustomerMenu1);
    if ((pInputTiming->usModeHActive == PANEL_WIDTH && pInputTiming->usModeVActive == PANEL_HEIGHT)) {
        for (i=2; i<5; i++) {
            OSDShowSelectPageIcon(i, 1);
        }
    }
    else{
        for (i=0; i<5; i++) {
            OSDShowSelectPageIcon(i, 1);
        }
    }
    OSDShowTopPageIcon(TP_DISPLAYMODE, 1, 0);
    OSDShowBigWin(OSD_DIALOG_LAYER_WIN, OSD_WIN_BOARDER_SIZE);
    OSDShowStringSeparater(DIALOG_LAYER, FALSE);

    OSDSelectDialogItem(UserData.ucAspectRatio, 0);

    UserSetTransparent();
    OSDSetPosition(OSD_HOTKEY_MENU_H_POSITION,OSD_HOTKEY_MENU_V_POSITION);
    
    OSDUpdateKeyInfo(GetOSDState());
    OSDTurnOnOSD();
}

//******************************************************************************
// Prototype:
//  void OSDShowPictureModeMenu(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Show PictureMode dialog when press PictureMode button on TopPage menu.
// Notes:None
//******************************************************************************
void OSDShowPictureModeMenu(void)
{
    UCHAR i;

    OSDLoadFont(PictureModeMenu_font);
    OSDInitFrame(OSD_CUSTOMERKEY_MENU1_WIDTH, OSD_CUSTOMERKEY_MENU1_HEIGHT, MAIN_FRAME_COLOR);

    OSDAPI_SetIndentIndex(String_TopPage_Index);

    OSDShowBenQMainFrame(FrameWidthType_CustomerMenu1);
    OSDShowSelectPageMainFrame(FrameWidthType_CustomerMenu1);
    for (i=0; i<5; i++) {
        OSDShowSelectPageIcon(i, 1);
    }

    OSDShowTopPageIcon(TP_PICTUREMODE, 1, 0);
    OSDShowBigWin(OSD_DIALOG_LAYER_WIN, OSD_WIN_BOARDER_SIZE);
    OSDShowStringSeparater(DIALOG_LAYER, FALSE);

    // show down arrow icon
    //OSDAPI_SetFontAttr(ArrowColor1);
    //OSDAPI_WriteXYChar(TRUE, 13, 20, DownArrow_1);
    //OSDAPI_WriteXYChar(TRUE, 14, 20, DownArrow_2);
    //OSDAPI_WriteXYChar(TRUE, 14, 21, DownArrow_3);

    OSDSelectDialogItem(UserData.ucBFMode, 0);

    UserSetTransparent();
    OSDSetPosition(OSD_HOTKEY_MENU_H_POSITION,OSD_HOTKEY_MENU_V_POSITION);
    OSDTurnOnOSD();
}

//******************************************************************************
// Prototype:
//  void OSDShowVolumeMenu(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Show Volume dialog when press Volume button on TopPage menu.
// Notes:None
//******************************************************************************
void OSDShowVolumeMenu(void)
{
    UCHAR i;
    OSDLoadFont(ShowVolumeMenu_font);
    OSDInitFrame(OSD_CUSTOMERKEY_MENU2_WIDTH, OSD_CUSTOMERKEY_MENU2_HEIGHT, MAIN_FRAME_COLOR);
    OSDAPI_SetIndentIndex(String_TopPage_Index);

    OSDShowBenQMainFrame(FrameWidthType_CustomerMenu2);
    OSDShowSelectPageMainFrame(FrameWidthType_CustomerMenu2);
    for (i=0; i<5; i++){
        OSDShowSelectPageIcon(i, 2);
    }
    OSDShowTopPageIcon(TP_VOLUME, 1, 0);
    OSDShowTrianIcon(TRIANGLE_METHOD1, 0, DIALOG_LAYER);
    OSDShowBigWin(OSD_DIALOG2_LAYER_WIN, OSD_WIN_BOARDER_SIZE);

    OSDShowVolume(TRUE, TRUE);

    UserSetTransparent();
    OSDSetPosition(OSD_HOTKEY_BAR_H_POSITION,OSD_HOTKEY_MENU_V_POSITION);
    OSDTurnOnOSD();
}

void OSDShowMuteMenu(void)
{
    UCHAR i;

    OSDLoadFont(ShowMute_font);
    OSDInitFrame(OSD_CUSTOMERKEY_MENU1_WIDTH, OSD_CUSTOMERKEY_MENU1_HEIGHT, MAIN_FRAME_COLOR);

    OSDAPI_SetIndentIndex(String_TopPage_Index);

    OSDShowBenQMainFrame(FrameWidthType_CustomerMenu1);
    OSDShowSelectPageMainFrame(FrameWidthType_CustomerMenu1);
    for (i=0; i<5; i++) {
        OSDShowSelectPageIcon(i, 1);
    }

    OSDShowTopPageIcon(TP_MUTE, 1, 0);
    OSDShowBigWin(OSD_DIALOG_LAYER_WIN, OSD_WIN_BOARDER_SIZE);
    OSDShowStringSeparater(DIALOG_LAYER, FALSE);
    
    OSDSelectDialogItem((!UserData.bAudioMute), 0);
    UserSetTransparent();
    OSDSetPosition(OSD_HOTKEY_MENU_H_POSITION,OSD_HOTKEY_MENU_V_POSITION);    
    OSDTurnOnOSD();
}

void OSDShowLBLMenu(void)
{
    UCHAR i;

    OSDLoadFont(ShowLowBlueLight_font);
    OSDInitFrame(OSD_CUSTOMERKEY_MENU1_WIDTH, OSD_CUSTOMERKEY_MENU1_HEIGHT, MAIN_FRAME_COLOR);

    OSDAPI_SetIndentIndex(String_TopPage_Index);

    OSDShowBenQMainFrame(FrameWidthType_CustomerMenu1);
    OSDShowSelectPageMainFrame(FrameWidthType_CustomerMenu1);
    for (i=0; i<5; i++) {
        OSDShowSelectPageIcon(i, 1);
    }

    OSDShowTopPageIcon(TP_LOWBLUELIGHT, 1, 0);
    OSDShowBigWin(OSD_DIALOG_LAYER_WIN, OSD_WIN_BOARDER_SIZE);
    OSDShowStringSeparater(DIALOG_LAYER, FALSE);

    OSDSelectDialogItem(UserData.ucLBLMode, 0);

    UserSetTransparent();
    OSDSetPosition(OSD_HOTKEY_MENU_H_POSITION,OSD_HOTKEY_MENU_V_POSITION);    
    OSDTurnOnOSD();
}

void OSDShowSmartReminderMenu(void)
{
    UCHAR i;

    OSDLoadFont(ShowSmartReminder_font);
    OSDInitFrame(OSD_CUSTOMERKEY_MENU1_WIDTH, OSD_CUSTOMERKEY_MENU1_HEIGHT, MAIN_FRAME_COLOR);

    OSDAPI_SetIndentIndex(String_TopPage_Index);

    OSDShowBenQMainFrame(FrameWidthType_CustomerMenu1);
    OSDShowSelectPageMainFrame(FrameWidthType_CustomerMenu1);
    for (i=0; i<5; i++) {
        OSDShowSelectPageIcon(i, 1);
    }

    OSDShowTopPageIcon(TP_SMARTREMINDER, 1, 0);
    OSDShowBigWin(OSD_DIALOG_LAYER_WIN, OSD_WIN_BOARDER_SIZE);
    OSDShowStringSeparater(DIALOG_LAYER, FALSE);

    OSDSelectDialogItem((!UserData.bSmartReminder), 0);

    UserSetTransparent();
    OSDSetPosition(OSD_HOTKEY_MENU_H_POSITION,OSD_HOTKEY_MENU_V_POSITION);    
    OSDTurnOnOSD();
}

//******************************************************************************
// Prototype:
//  void OSDShowBrightnessMenu(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Show Brightness dialog when press Brightness button on TopPage menu.
// Notes:None
//******************************************************************************
void OSDShowBrightnessMenu(void)
{
    UCHAR i;
    OSDLoadFont(ShowBrightnessMenu_font);
    OSDInitFrame(OSD_CUSTOMERKEY_MENU2_WIDTH, OSD_CUSTOMERKEY_MENU2_HEIGHT, MAIN_FRAME_COLOR);
    OSDAPI_SetIndentIndex(String_TopPage_Index);

    OSDShowBenQMainFrame(FrameWidthType_CustomerMenu2);
    OSDShowSelectPageMainFrame(FrameWidthType_CustomerMenu2);
    for (i=0; i<5; i++){
        OSDShowSelectPageIcon(i, 2);
    }
    OSDShowTopPageIcon(TP_BRIGHTNESS, 1, 0);
    OSDShowTrianIcon(TRIANGLE_METHOD1, 0, DIALOG_LAYER);
    OSDShowBigWin(OSD_DIALOG2_LAYER_WIN, OSD_WIN_BOARDER_SIZE);

    OSDShowBrightness(TRUE, TRUE);

    UserSetTransparent();
    OSDSetPosition(OSD_HOTKEY_BAR_H_POSITION,OSD_HOTKEY_MENU_V_POSITION);    
    OSDTurnOnOSD();
}

//******************************************************************************
// Prototype:
//  void OSDShowContrastMenu(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Show Contrast dialog when press Contrast button on TopPage menu.
// Notes:None
//******************************************************************************
void OSDShowContrastMenu(void)
{
    UCHAR i;
    OSDLoadFont(ShowContrastMenu_font);
    OSDInitFrame(OSD_CUSTOMERKEY_MENU2_WIDTH, OSD_CUSTOMERKEY_MENU2_HEIGHT, MAIN_FRAME_COLOR);
    OSDAPI_SetIndentIndex(String_TopPage_Index);

    OSDShowBenQMainFrame(FrameWidthType_CustomerMenu2);
    OSDShowSelectPageMainFrame(FrameWidthType_CustomerMenu2);
    for (i=0; i<5; i++){
        OSDShowSelectPageIcon(i, 2);
    }
    OSDShowTopPageIcon(TP_CONTRAST, 1, 0);
    OSDShowTrianIcon(TRIANGLE_METHOD1, 0, DIALOG_LAYER);
    OSDShowBigWin(OSD_DIALOG2_LAYER_WIN, OSD_WIN_BOARDER_SIZE);

    OSDShowContrast(TRUE, TRUE);

    UserSetTransparent();
    OSDSetPosition(OSD_HOTKEY_BAR_H_POSITION,OSD_HOTKEY_MENU_V_POSITION);
    OSDTurnOnOSD();
}

void OSDShowSourceMenu(void)
{
//    usOSDLocalTimer = GetTimerTick();
    if(!OSDAPI_IsOSDOn()){
        if (IsNoCableState()){                  
            OSDEnterNoCable();
        }
        else if (IsNoSyncState()) {                   
            OSDEnterNoSync();
        }            
        else if (APPIsOutOfLimit()) {// no modechange but out of range
            bShortOOLTimer = TRUE;
            OSDEnterOOL();
        }                  
        else  if (IsOutOfRange()) {// no modechange but out of range
            OSDEnterOOR();
        }                  
    }
     else{
        OSDAPI_TurnOffOSD();
        WaitDisVSync();     
        OSDInitialize(TRUE);
        OSDLoadFont(ShowSourcePageMenu_font);
        OSDInitFrame(OSD_TOPPAGE_WIDTH, OSD_TOPPAGE_HEIGHT, TOPPAGE_FRAME_COLOR);
        OSDAPI_SetIndentIndex(String_TopPage_Index);
        SetOSDState(OSD_DIRSRC_STATE);//Source State
        OSDShowTopPageMainFrame();
        OSDAPI_SetIndentIndex(Input_DP_End);
        OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
        OSDShowSourceIcon(0, VGA_SOURCE);
        OSDShowSourceIcon(1, DVI_SOURCE);
        OSDShowSourceIcon(2, HDMI_SOURCE);
        OSDShowSourceIcon(3, DP_SOURCE);
        OSDSetPosition(OSD_MAIN_TOP_MENU_H_POSITION,OSD_MAIN_TOP_MENU_V_POSITION);//zoe test
        OSDTurnOnOSD();
     }
}
//******************************************************************************
// Prototype:
//  void OSDShowTopPageMenu(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Show TopPage menu for BenQ OSD.
// Notes:
//  None
//******************************************************************************
void OSDShowTopPageMenu(void)
{
    OSDInitialize(TRUE);
    OSDLoadFont(ShowTopPageMenu_font);
    OSDInitFrame(OSD_TOPPAGE_WIDTH, OSD_TOPPAGE_HEIGHT, TOPPAGE_FRAME_COLOR);

    OSDShowTopPageMainFrame();

    OSDAPI_SetIndentIndex(String_TopPage_Index);
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);

    switch (UserData.ucCustomerKey1) {
        case CUSTOMER_KEY_AUTOADJUSTMENT:
            OSDShowTopPageIcon(TP_AUTOADJUSTMENT, 0, 0);
        break;
        case CUSTOMER_KEY_DISPLAYMODE:
            OSDShowTopPageIcon(TP_DISPLAYMODE, 0, 0);
        break;
        case CUSTOMER_KEY_PICTUREMODE:
            OSDShowTopPageIcon(TP_PICTUREMODE, 0, 0);
        break;
        case CUSTOMER_KEY_INPUT:
            OSDShowTopPageIcon(TP_INPUT, 0, 0);
        break;
        case CUSTOMER_KEY_BRIGHTNESS:
            OSDShowTopPageIcon(TP_BRIGHTNESS, 0, 0);
        break;
        case CUSTOMER_KEY_CONTRAST:
            OSDShowTopPageIcon(TP_CONTRAST, 0, 0);
        break;
        case CUSTOMER_KEY_VOLUME:
            OSDShowTopPageIcon(TP_VOLUME, 0, 0);
        break;
        case CUSTOMER_KEY_MUTE:
            OSDShowTopPageIcon(TP_MUTE, 0, 0);
        break;
        case CUSTOMER_KEY_SMARTREMINDER:
            OSDShowTopPageIcon(TP_SMARTREMINDER, 0, 0);
        break;
        case CUSTOMER_KEY_LOWBULELIGHTMODE:
            OSDShowTopPageIcon(TP_LOWBLUELIGHT, 0, 0);
        break;
    }

    switch (UserData.ucCustomerKey2) {
        case CUSTOMER_KEY_AUTOADJUSTMENT:
            OSDShowTopPageIcon(TP_AUTOADJUSTMENT, 0, 1);
        break;
        case CUSTOMER_KEY_DISPLAYMODE:
            OSDShowTopPageIcon(TP_DISPLAYMODE, 0, 1);
        break;
        case CUSTOMER_KEY_PICTUREMODE:
            OSDShowTopPageIcon(TP_PICTUREMODE, 0, 1);
        break;
        case CUSTOMER_KEY_INPUT:
            OSDShowTopPageIcon(TP_INPUT, 0, 1);
        break;
        case CUSTOMER_KEY_BRIGHTNESS:
            OSDShowTopPageIcon(TP_BRIGHTNESS, 0, 1);
        break;
        case CUSTOMER_KEY_CONTRAST:
            OSDShowTopPageIcon(TP_CONTRAST, 0, 1);
        break;
        case CUSTOMER_KEY_VOLUME:
            OSDShowTopPageIcon(TP_VOLUME, 0, 1);
        break;
        case CUSTOMER_KEY_MUTE:
            OSDShowTopPageIcon(TP_MUTE, 0, 1);
        break;
        case CUSTOMER_KEY_SMARTREMINDER:
            OSDShowTopPageIcon(TP_SMARTREMINDER, 0, 1);
        break;
        case CUSTOMER_KEY_LOWBULELIGHTMODE:
            OSDShowTopPageIcon(TP_LOWBLUELIGHT, 0, 1);
        break;
    }

    switch (UserData.ucCustomerKey3) {
        case CUSTOMER_KEY_AUTOADJUSTMENT:
            OSDShowTopPageIcon(TP_AUTOADJUSTMENT, 0, 2);
        break;
        case CUSTOMER_KEY_DISPLAYMODE:
            OSDShowTopPageIcon(TP_DISPLAYMODE, 0, 2);
        break;
        case CUSTOMER_KEY_PICTUREMODE:
            OSDShowTopPageIcon(TP_PICTUREMODE, 0, 2);
        break;
        case CUSTOMER_KEY_INPUT:
            OSDShowTopPageIcon(TP_INPUT, 0, 2);
        break;
        case CUSTOMER_KEY_BRIGHTNESS:
            OSDShowTopPageIcon(TP_BRIGHTNESS, 0, 2);
        break;
        case CUSTOMER_KEY_CONTRAST:
            OSDShowTopPageIcon(TP_CONTRAST, 0, 2);
        break;
        case CUSTOMER_KEY_VOLUME:
            OSDShowTopPageIcon(TP_VOLUME, 0, 2);
        break;
        case CUSTOMER_KEY_MUTE:
            OSDShowTopPageIcon(TP_MUTE, 0, 2);
        break;
        case CUSTOMER_KEY_SMARTREMINDER:
            OSDShowTopPageIcon(TP_SMARTREMINDER, 0, 2);
        break;
        case CUSTOMER_KEY_LOWBULELIGHTMODE:
            OSDShowTopPageIcon(TP_LOWBLUELIGHT, 0, 2);
        break;
    }

    OSDShowTopPageIcon(TP_MENU, 0, 0);
    OSDShowTopPageIcon(TP_EXIT, 0, 0);

    OSDSetPosition(OSD_MAIN_TOP_MENU_H_POSITION,OSD_MAIN_TOP_MENU_V_POSITION);//zoe test

    OSDTurnOnOSD();
}
#if 0
//******************************************************************************
// Prototype:
//  void OSDCloseTopPageMenu(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Close all OSD no matther what state.
// Notes:
//  None
//******************************************************************************
void OSDCloseTopPageMenu(void)
{
    OSDClosed();
}
#endif
//******************************************************************************
// Prototype:
//  BOOL OSDIsMainItemValid(UCHAR id)
// Parameters:
//  id      : OSD cursor position on man page
// Return:
//  Check current position is valid or not
// Purpose:
//  Check OSD cursor can move to "id" or not
// Notes:
//  None
//******************************************************************************
BOOL OSDIsMainItemValid(UCHAR id)
{
    id = id;
    return TRUE;
}

BOOL OSDIsCustomkeyItemValid(UCHAR id)
{
    UCHAR Item;
    Item = fnGetCustomerKeyItem();
    switch (Item) {
        case CUSTOMER_KEY_DISPLAYMODE:
            switch (id) {
                case DSP_SIZE_1By1:
                    if (pInputTiming->usModeHActive == PANEL_WIDTH && pInputTiming->usModeVActive == PANEL_HEIGHT) {
                        return FALSE;
                    }
                    break;
                case DSP_SIZE_FULL:
                    break;
                case DSP_SIZE_43:                    
                    if (DetectAspectRatio() == DSP_SIZE_FULL) { //aspect disable
                        return FALSE;    
                    }                    
                    break;
                default:
                    break;
            }            
            break;            
        default:
            break;
    }
    return TRUE;    
}


//******************************************************************************
// Prototype:
//  BOOL OSDIsSubItemValid(UCHAR id)
// Parameters:
//  id      : OSD cursor position on sub page
// Return:
//  Check current position is valid or not
// Purpose:
//  Check OSD cursor can move to "id" or not
// Notes:
//  None
//******************************************************************************
BOOL OSDIsSubItemValid(UCHAR id)
{    
    switch (ucMenuType) {
        case OSD_MAIN_DISPLAY:
            switch (id) {
#if ENABLE_AUTO_POVIT_FUNC == ON                      
                case OSD_DISPLAY_PIVOT:
                    break;
#endif
                case OSD_DISPLAY_INPUT:
                    break;
                    
                case OSD_DISPLAY_ADJUST:                    
                case OSD_DISPLAY_HPOS:
                case OSD_DISPLAY_VPOS:
                case OSD_DISPLAY_PIXELCLK:
                case OSD_DISPLAY_PHASE:
                    if(UserData.ucInputSource != INPUT_SC_VGA){
                        return FALSE;    
                    }
                    else{  // VGA
                        if(IsComponentInput()){
                            return FALSE;                                    
                        }
                    }
                    break;
                default:
                    break;
            }
        break;
        case OSD_MAIN_PICTURE:
            switch (id) {
                case OSD_PICTURE_BRIGHTNESS:
                case OSD_PICTURE_CONTRAST:                    
                    if(UserData.ucBFMode == PICTURE_MODE_ECO){
                        return FALSE;    
                    }
                    if((UserData.ucBFMode == PICTURE_MODE_MOVIE)||(UserData.ucBFMode == PICTURE_MODE_PHOTO)||(UserData.ucBFMode == PICTURE_MODE_GAME)){
                        if(UserData.ucDynamicContrast != 0){
                            return FALSE;    
                        }
                    }
                    break;
                case OSD_PICTURE_SHARPNESS:
                    break;
                case OSD_PICTURE_GAMMA:
                case OSD_PICTURE_COLORTEMP:
                    if((UserData.ucBFMode != PICTURE_MODE_USER)&&(UserData.ucBFMode != PICTURE_MODE_STANDARD)){
                        return FALSE;
                    }
                    break;                    
                case OSD_PICTURE_HUE:
                case OSD_PICTURE_SATURATION:
                    if(UserData.ucBFMode != PICTURE_MODE_USER){
                        return FALSE;
                    }                    
                    break;
                default:
                    break;
            }
        break;
     case OSD_MAIN_PICTURE_ADVANCED:
            switch (id) {
                case OSD_PICTURE_AD_SENSEYE:
                    if((UserData.ucBFMode != PICTURE_MODE_MOVIE)
                        &&(UserData.ucBFMode != PICTURE_MODE_PHOTO)
                        &&(UserData.ucBFMode != PICTURE_MODE_GAME)
#if ENABLE_PICTURE_MODE_MBOOK == ON
                        &&(UserData.ucBFMode != PICTURE_MODE_MBOOK)
#endif
                        ){
                        return FALSE;    
                    }        
                    break;                        
                case OSD_PICTURE_AD_DCR:
                    if((UserData.ucBFMode != PICTURE_MODE_MOVIE)&&(UserData.ucBFMode != PICTURE_MODE_PHOTO)&&(UserData.ucBFMode != PICTURE_MODE_GAME)){
                        return FALSE;    
                    }                    
                    break;                    
                case OSD_PICTURE_AD_COLORFORMAT:                    
                    if(IsComponentInput()){
                        return TRUE;                                         
                    }
                    else{
                        return FALSE;    
                    }                    
                    break;            
                case OSD_PICTURE_AD_PCRANGE:
                    if(UserData.ucInputSource != INPUT_SC_HDMI){
                        return FALSE;    
                    }
                    else{
                        if (IsHDMIVideo()) {
                            return FALSE;
                        }
                    }
                    break;
                case OSD_PICTURE_AD_OVERSCAN:
                    if((UserData.ucInputSource == INPUT_SC_DP1)||(UserData.ucInputSource == INPUT_SC_DP2)){
                        return FALSE;
                    }
                    if((UserData.ucInputSource == INPUT_SC_VGA)||(UserData.ucInputSource == INPUT_SC_DVI)){
                        if(IsComponentInput()){
                            return TRUE;                                         
                        }
                        return FALSE;    
                    }                
                    break;                    
                default:
                    break;
            }
          break;
     case OSD_MAIN_AUDIO:
            switch (id) {
                case OSD_AUDIO_VOLUME:
                    break;
                default:
                    break;
         }
         break;
     case OSD_MAIN_SYSTEM:
          break;
     case OSD_MAIN_ERGONOMICS:
        switch (id) {
            case OSD_ERGONOMICS_REMIDER:
                break;
            case OSD_ERGONOMICS_TIME:
                    if(UserData.bSmartReminder == OFF){
                        return FALSE;                 
                    }                                    
                break;
            case OSD_ERGONOMICS_DURATION:
                    if(UserData.bSmartReminder == OFF){
                        return FALSE;                 
                    }                                    
                break;                
            default:
                break;
        }
          break; 
     default:
          break;
    }

    return TRUE;    
}
//******************************************************************************
// Prototype:
//  BOOL OSDIsItemValid(UCHAR id)
// Parameters:
//  id      : OSD cursor position on sub page
// Return:
//  Check current position is valid or not
// Purpose:
//  Check OSD cursor can move to "id" or not
// Notes:
//  None
//******************************************************************************
BOOL OSDIsLayer3ItemValid(UCHAR id)//Layer3 Item
{    
    switch (ucMenuType) {
        case OSD_MAIN_DISPLAY:
            break;
        case OSD_MAIN_PICTURE:
            switch (ucSubMenuType) {
                case OSD_PICTURE_COLORTEMP:
                    switch (id) {
                        case CLRTMP_USER:
                            if (UserData.ucBFMode == PICTURE_MODE_STANDARD) {
                                return FALSE;
                            }
                            break;
                    }
                    break;
                default:
                    break;
            }
          break;         
        break;            
     case OSD_MAIN_PICTURE_ADVANCED:
            switch (ucSubMenuType) {
                case OSD_PICTURE_AD_DISMODE:
                    switch (id) {
                        case DSP_SIZE_1By1:
                            if (pInputTiming->usModeHActive == PANEL_WIDTH && pInputTiming->usModeVActive == PANEL_HEIGHT) {
                                return FALSE;
                            }
                            else {
                                return TRUE;
                            }
                            break;
                        case DSP_SIZE_FULL:
                            return TRUE;
                            break;
                        case DSP_SIZE_43:
                            if (DetectAspectRatio() == DSP_SIZE_FULL) {
                                return FALSE;
                            }
                            else {
                                return TRUE;
                            }
                            break;
                    }
                    break;
                default:
                    break;
            }
          break;
     case OSD_MAIN_AUDIO:
            switch (ucSubMenuType) {
                case OSD_AUDIO_SELECT:        
                    switch (id) {
                        case AUDIOSRC_PC:
                        break;    
                        case AUDIOSRC_HDMI:
                            if(UserData.ucInputSource != INPUT_SC_HDMI){
                                return FALSE;                 
                            }
                        break;    
                        case AUDIOSRC_AUTO:
                        break;                                        
                    }
                    break;                            
                default:
                    break;
            }         
         break;
     case OSD_MAIN_SYSTEM:
            switch (ucSubMenuType) {
                case OSD_SYS_CTKEY1:
                    if(id == UserData.ucCustomerKey2){
                        return FALSE;
                    }
                    if(id == UserData.ucCustomerKey3){
                        return FALSE;
                    }                             
                    break;                        
                case OSD_SYS_CTKEY2:
                    if(id == UserData.ucCustomerKey1){
                        return FALSE;
                    }
                    if(id == UserData.ucCustomerKey3){
                        return FALSE;
                    }                    
                    break;                    
                case OSD_SYS_CTKEY3:                    
                    if(id == UserData.ucCustomerKey1){
                        return FALSE;
                    }
                    if(id == UserData.ucCustomerKey2){
                        return FALSE;
                    }                    
              break;                        
                default:
                    break;
            }         
          break;
     case OSD_MAIN_ERGONOMICS:
          break; 
     default:
          break;
    }
    return TRUE;    
}


#if MD_ENABLE_FUNC_OSD == ON
void OSDShowFuncMenu(void)
{
    OSDWinAttr attr;

    OSDInitialize(FALSE);
    OSDInitFrame(OSD_FUNC_WIDTH,OSD_FUNC_HEIGHT, FUNC_FRAME_COLOR);

    RST_WINATTR_ALL(attr);

    OSDAPI_SelOSDWin(OSD_WINDOW8);
    attr.ucWinClr = I_TGREEN;
    OSDAPI_SetOSDWinAttr(attr);
    OSDAPI_SetOSDWinSize(0, 0, OSD_FUNC_WIDTH, 4);
    OSDAPI_SetOSDWinGrad(0x00, 0x00, 0x02, 0x01);

    OSDAPI_SelOSDWin(OSD_WINDOW7);
    attr.ucWinClr = I_WHITE;
    OSDAPI_SetOSDWinAttr(attr);
    OSDAPI_SetOSDWinSize(0, 3, OSD_FUNC_WIDTH, OSD_FUNC_HEIGHT);
    OSDAPI_SetOSDWinGrad(0x00, 0x01, 0x01, 0x01);

    OSDAPI_OSDWinOn(OSD_WINDOW8);
    OSDAPI_OSDWinOn(OSD_WINDOW7);

#if OSDTYPE == OSD_BENQ 
    OSDAPI_SetIndentIndex(100);
#else
    OSDAPI_SetIndentIndex(32);
#endif  
    OSDAPI_SetAlignType(OSD_ALIGN_CENTER);
    OSDAPI_FillLineAttr(0, 1, OSD_FUNC_WIDTH, TITLE_COLOR);
    OSDAPI_WriteXYRepeatChar(FALSE, 0, 1, OSD_FUNC_WIDTH, SPACE_CHAR);

    OSDShowFuncItems();
    UserSetTransparent();

    OSDTurnOnOSD();
}

void OSDCloseFuncMenu(void)
{
    OSDClosed();
}

void OSDClearFuncMenu(void)
{
    UCHAR i;
    OSDAPI_OSDWinOff(OSD_WINDOW2);
    for (i = 3; i < OSD_FUNC_HEIGHT; i++) {
        OSDAPI_WriteXYRepeatChar(FALSE, 0, i, OSD_FUNC_WIDTH, SPACE_CHAR);
        OSDAPI_FillLineAttr(0, i, OSD_FUNC_WIDTH, FUNC_FRAME_COLOR);
    }
}

void OSDFocusFuncMenu(UCHAR id)
{
    OSDClearFuncMenu();
    OSDShowFuncItems();
    OSDSelectFuncItem(id);
}

void OSDUnselectFuncItem(UCHAR id)
{
    id = 0;
    OSDAPI_OSDWinOff(OSD_WINDOW2);
}

BOOL OSDIsFuncItemValid(UCHAR id)
{
#if (ENABLE_SCALER_3D == ON) && (ENABLE_3D_CNV == ON)
    if (SC3DAPI_IsHDMI3D() || SC3DAPI_IsAMD3D()) {
        if ((id != OSD_FUNCITM_5) && (id != OSD_FUNCITM_6)) {
            return FALSE;
        }
    }
    else if (SC3DAPI_Is2DTo3D()) {
        return TRUE;
    }
    else if (SC3DAPI_IsDisplay3D()) {
        if ((id == OSD_FUNCITM_2) || (id == OSD_FUNCITM_3) || (id == OSD_FUNCITM_4)) {
            return FALSE;
        }
    }
    else {
        if (id != OSD_FUNCITM_1) {
            return FALSE;
        }
    }
#else
    id = 0;
#endif
    return TRUE;
}
#endif

//******************************************************************************
// Prototype:
//  BOOL OSDUserUpdate(void)
// Parameters:
//  None
// Return:
//  return TRUE or FALSE to indicate data should be updated or not
// Purpose:
//  Check user data need to be updated or not
// Notes:
//  None
//******************************************************************************
BOOL OSDUserUpdate(void)
{
    BOOL tmp = IsOSDUpdUsr();
    ClearOSDUpdUsrFlag();
    return tmp;
}

//******************************************************************************
// Prototype:
//  BOOL OSDTmgUpdate(void)
// Parameters:
//  None
// Return:
//  return TRUE or FALSE to indicate data should be updated or not
// Purpose:
//  Check timing data need to be updated or not
// Notes:
//  None
//******************************************************************************
BOOL OSDTmgUpdate(void)
{
    BOOL tmp = IsOSDUpdTmg();
    ClearOSDUpdTmgFlag();
    return tmp;
}

//******************************************************************************
// Prototype:
//  BOOL OSDSysUpdate(void)
// Parameters:
//  None
// Return:
//  return TRUE or FALSE to indicate data should be updated or not
// Purpose:
//  Check system data need to be updated or not
// Notes:
//  None
//******************************************************************************
BOOL OSDSysUpdate(void)
{
    BOOL tmp = IsOSDUpdSys();
    ClearOSDUpdSysFlag();
    return tmp;
}

//******************************************************************************
// Prototype:
//  BOOL OSDCalUpdate(void)
// Parameters:
//  None
// Return:
//  return TRUE or FALSE to indicate data should be updated or not
// Purpose:
//  Check cal data need to be updated or not
// Notes:
//  None
//******************************************************************************
BOOL OSDCalUpdate(void)
{
    BOOL tmp = IsOSDUpdCal();
    ClearOSDUpdCalFlag();
    return tmp;
}

//******************************************************************************
// Prototype:
//  void OSDClosed(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Close OSD & do something necessary
// Notes:
//  None
//******************************************************************************
void OSDClosed(void)
{
#if ENABLE_DBC == ON
#if ENABLE_DBC_HW_DEBOUNCE == OFF
    ClearDBCCounter();
#endif
#endif
    OSDAPI_TurnOffOSD();
    OSDAPI_OSDWinOff(OSD_WIN_OFF);
    WaitDisVSync();
    ucMenuType = OSD_OFF;
    IsPage2 = FALSE;
}
//******************************************************************************
// Prototype:
//  void OSDSetPosition(USHRT x,USHRT y)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Show key button
// Notes:
//  None
//******************************************************************************
void OSDSetPosition(USHRT x,USHRT y) 
{
    USHRT xx, yy;
    xx = x;//UserPanelData.usWidth - x*12 - 70;
    yy = y;//UserPanelData.usHeight - y*18 - 70;

    //printf("xx,yy = (%d,%d)\r\n",xx,yy);

    SC_OSD_HS_LO = (xx & 0x00FF);
    SC_OSD_HS_HI = (xx & 0xFF00) >> 8;

    SC_OSD_VS_LO = (yy & 0x00FF);
    SC_OSD_VS_HI = (yy & 0xFF00) >> 8;
}

//******************************************************************************
// Prototype:
//  void OSDInitFrame(UCHAR osdw, UCHAR osdh, USHRT clr)
// Parameters:
//  osdw    : OSD width
//  osdh    : OSD height
//  clr     : OSD color
// Return:
//  None
// Purpose:
//  Initial OSD width, height andf color
// Notes:
//  None
//******************************************************************************
void OSDInitFrame(UCHAR osdw, UCHAR osdh, USHRT clr)
{
    OSDAPI_TurnOffOSD();
    OSDAPI_OSDWinOff(OSD_WIN_OFF);
    OSDAPI_SetOSDWidth(osdw);
    OSDAPI_SetOSDHeight(osdh);
    OSDAPI_SetPosition(UserData.ucOSDX,UserData.ucOSDY);
    OSDAPI_SetFontAttr(clr);
    OSDAPI_ClearOSD();
}

//******************************************************************************
// Prototype:
//  void OSDShowNum(UCHAR x, UCHAR y, UCHAR value)
// Parameters:
//  x       : x position
//  y       : y position
//  value   : value to be show
// Return:
//  None
// Purpose:
//  Show number on the specific position x,y
// Notes:
//  None
//******************************************************************************
void OSDShowNum(UCHAR x, UCHAR y, UCHAR value)
{
    UCHAR buff[4];
    OSDWinAttr attr;
    sprintf(buff,"%4d",(USHRT)value);//ULEric140331
    buff[0] = 3;//ULEric140331
    
    OSDAPI_SetIndentIndex(String_Layer3_Index);
    OSDAPI_SetAlignType(OSD_ALIGN_CENTER);    
    if (bSelNum) {
        // use a window to show number background.
        OSDAPI_SelOSDWin(OSD_WINDOW2);
        RST_WINATTR_ALL(attr);
        attr.ucWinClr = I_BENQ_BLUE_1;
        OSDAPI_SetOSDWinAttr(attr);
        OSDAPI_SetOSDWinSize(12*x, 18*y, 12*x+12*3, 18*y+18);
        OSDAPI_OSDWinOn(OSD_WINDOW2);

        OSDAPI_SetFontAttr(NumberColor2);
        ShowIndentString(TRUE, x, y, 3, buff);
    }
    else {
        OSDAPI_OSDWinOff(OSD_WINDOW2);
        OSDAPI_SetFontAttr(NumberColor3);
        ShowIndentString(TRUE, x, y, 3, buff);
    }
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);        
}
BOOL bSelNum2 =FALSE;
void OSDShowNum2(UCHAR x, UCHAR y, UCHAR value,UCHAR index)
{
    UCHAR buff[4];
    OSDWinAttr attr;
    sprintf(buff,"%4d",(USHRT)value);//ULEric140331
    buff[0] = 3;//ULEric140331
    
    OSDAPI_SetIndentIndex(String_Layer4_Index+index);
    OSDAPI_SetAlignType(OSD_ALIGN_CENTER);    
    if (bSelNum2) {
        // use a window to show number background.
        OSDAPI_SelOSDWin(OSD_WINDOW2);
        RST_WINATTR_ALL(attr);
        attr.ucWinClr = I_BENQ_BLUE_1;
        OSDAPI_SetOSDWinAttr(attr);
            OSDAPI_SetOSDWinSize(12*x, 18*y, 12*x+12*3, 18*y+18);
        OSDAPI_OSDWinOn(OSD_WINDOW2);

        OSDAPI_SetFontAttr(NumberColor2);
        ShowIndentString(TRUE, x, y, 3, buff);
    }
    else {
        OSDAPI_OSDWinOff(OSD_WINDOW2);
        OSDAPI_SetFontAttr(NumberColor3);
        ShowIndentString(TRUE, x, y, 3, buff);
    }
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);        
}

//******************************************************************************
// Prototype:
//  void OSDShowSliderBar(UCHAR x, UCHAR y, UCHAR value, BOOL Sel, UCHAR Color)
// Parameters:
//  x       : x position
//  y       : y position
//  value   : value to be show
// Sel    : If TRUE, use select Color, else use unselect color(Gray)
// Return:
//  None
// Purpose:
//  Show slider bar on the specific position x,y
// Notes:
//  None
//******************************************************************************
void OSDShowSliderBar(UCHAR x, UCHAR y, UCHAR value, BOOL Sel, UCHAR Color)
{
    #define SLIDE_BAR_HEIGHT     10
    #define SLIDE_VALUE_RANGE   100
    #define SLIDE_REMAINDER     (SLIDE_VALUE_RANGE/5)

    UCHAR i, k;
    USHRT m, Color1, Color2;
/*
    if (range == SLIDERBAR_RANGE_10) {
        value = value *100 / 10;
    }
    else if(range == SLIDERBAR_RANGE_5) {
        value = value *100 / 5;
    }
    else if(range == SLIDERBAR_RANGE_64) {
        value = value *100 / 63;
    }
    else {
    }
    // Avoid input value is over SLIDE_VALUE_RANGE
    if (value >= SLIDE_VALUE_RANGE) {
        value = SLIDE_VALUE_RANGE;
    }
*/
    // Left side bottom font
    OSDAPI_SetFontAttr(SLIDER_BAR_2BIT_BOARDER_COLOR);
    OSDAPI_WriteXYChar(TRUE, x, y, SB_BottomLeft);
    // Bottom font
    OSDAPI_WriteXYChar(TRUE, x+1, y, SB_Bottom);

    // left side font
    for (i = 0; i < SLIDE_BAR_HEIGHT; i++) {
        OSDAPI_WriteXYChar(TRUE, x, y-i-1, SB_LeftSide);
    }

    // Top left font
    OSDAPI_WriteXYChar(TRUE, x, y-i-1, SB_TopLeft);
    // Top font
    OSDAPI_WriteXYChar(TRUE, x+1, y-i-1, SB_Top);

    if (Sel) {
        switch (Color) {
            case SLIDERBAR_RED_COLOR:
                Color1 = SLIDER_BAR_2BIT_FULL_COLOR_RED;
                Color2 = SLIDER_BAR_4BIT_COLOR_RED;
            break;
            case SLIDERBAR_GREEN_COLOR:
                Color1 = SLIDER_BAR_2BIT_FULL_COLOR_GREEN;
                Color2 = SLIDER_BAR_4BIT_COLOR_GREEN;
            break;
            case SLIDERBAR_BLUE_COLOR:
                Color1 = SLIDER_BAR_2BIT_FULL_COLOR_BLUE;
                Color2 = SLIDER_BAR_4BIT_COLOR_BLUE;
            break;
            default:
            case SLIDERBAR_GRAY_COLOR:
                Color1 = SLIDER_BAR_2BIT_FULL_COLOR_BLUE;
                Color2 = SLIDER_BAR_4BIT_COLOR_BLUE;                
            break;
        }
    }
    else {
        Color1 = SLIDER_BAR_2BIT_FULL_COLOR_GRAY;
        Color2 = SLIDER_BAR_4BIT_COLOR_GRAY;
    }

    OSDAPI_SetFontAttr(Color1);

    m = (USHRT)value * SLIDE_BAR_HEIGHT;
    k = m / SLIDE_VALUE_RANGE; // complete font
    for (i = 0; i < k; i++) {
        if (i == 0)
            OSDAPI_WriteXYChar(TRUE, x+1, y-i-1, SB_Bottom_Font1);
        else
            OSDAPI_WriteXYChar(TRUE, x+1, y-i-1, SB_Blank_Font);
    }
    if (i < SLIDE_BAR_HEIGHT) {
        k = (m % SLIDE_VALUE_RANGE) / SLIDE_REMAINDER;
        switch (k) {
            case 0:
                if (i == 0) {
                    OSDAPI_SetFontAttr(SLIDER_BAR_2BIT_BLANK_COLOR);
                    OSDAPI_WriteXYChar(TRUE, x+1, y-i-1, SB_Bottom_Font1);
                }
                else {
                    OSDAPI_SetFontAttr(SLIDER_BAR_2BIT_BLANK_COLOR);
                    OSDAPI_WriteXYChar(TRUE, x+1, y-i-1, SB_Blank_Font);
                }
                break;
            case 1:
                OSDAPI_SetFontAttr(Color2);
                if (i == 0) {
                    OSDAPI_WriteXYChar(TRUE, x+1, y-i-1, SB_4Bit_BottomFont_1);
                }
                else {
                    OSDAPI_WriteXYChar(TRUE, x+1, y-i-1, SB_4Bit_Font_1);
                }
                break;
            case 2:
                OSDAPI_SetFontAttr(Color2);
                if (i == 0) {
                    OSDAPI_WriteXYChar(TRUE, x+1, y-i-1, SB_4Bit_BottomFont_2);
                }
                else {
                    OSDAPI_WriteXYChar(TRUE, x+1, y-i-1, SB_4Bit_Font_2);
                }
                break;
            case 3:
                OSDAPI_SetFontAttr(Color2);
                if (i == 0) {
                    OSDAPI_WriteXYChar(TRUE, x+1, y-i-1, SB_4Bit_BottomFont_3);
                }
                else {
                    OSDAPI_WriteXYChar(TRUE, x+1, y-i-1, SB_4Bit_Font_3);
                }
                break;
            case 4:
                OSDAPI_SetFontAttr(Color2);
                if (i == 0) {
                    OSDAPI_WriteXYChar(TRUE, x+1, y-i-1, SB_4Bit_BottomFont_4);
                }
                else {
                    OSDAPI_WriteXYChar(TRUE, x+1, y-i-1, SB_4Bit_Font_4);
                }
                break;
        }
        i++;
        OSDAPI_SetFontAttr(SLIDER_BAR_2BIT_BLANK_COLOR);
        for (i; i < SLIDE_BAR_HEIGHT; i++) {
            OSDAPI_WriteXYChar(TRUE, x+1, y-i-1, SB_Blank_Font);
        }
    }
}
#if 0
//******************************************************************************
// Prototype:
//  void OSDMovePosition(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
void OSDMovePosition(void)
{
    USHRT lmt_x, lmt_y, stp_x, stp_y;
#if ENABLE_OSD_ROTATION == ON
    if (UserData.bOSDRotation) {
        lmt_x = MAX_ROT_X;
        lmt_y = MAX_ROT_Y;
        stp_x = OSD_MOVESTEP_ROT_X;
        stp_y = OSD_MOVESTEP_ROT_Y;
    }
    else {
        lmt_x = MAX_X;
        lmt_y = MAX_Y;
        stp_x = OSD_MOVESTEP_X;
        stp_y = OSD_MOVESTEP_Y;
    }
#else
    lmt_x = MAX_X;
    lmt_y = MAX_Y;
    stp_x = OSD_MOVESTEP_X;
    stp_y = OSD_MOVESTEP_Y;
#endif

    if(usOSDMovingX < 0x8000){
        usOSDMovingX += stp_x;
        if(usOSDMovingX >= lmt_x){
            usOSDMovingX = 0x8000+lmt_x;
        }
    }
    else{
        usOSDMovingX -= stp_x;
        if(usOSDMovingX < 0x8000){
            usOSDMovingX = 1;
        }
    }
    if(usOSDMovingY < 0x8000){
        usOSDMovingY += stp_y;
        if(usOSDMovingY >= lmt_y){
            usOSDMovingY = 0x8000+lmt_y;
        }
    }
    else{
        usOSDMovingY -= stp_y;
        if(usOSDMovingY <0x8000){
            usOSDMovingY = 1;
        }
    }

    OSDAPI_SetRowPosition(usOSDMovingX&0x7fff, usOSDMovingY&0x7fff);
}
#endif

void OSDFocusInput(void)
{
    switch (UserData.ucInputSource) {
        case INPUT_SC_VGA:
        SetOSDState(OSD_ITEM_1_2_1_STATE);
        break;
        case INPUT_SC_DVI:
        SetOSDState(OSD_ITEM_1_2_2_STATE);
        break;
        case INPUT_SC_HDMI:
        SetOSDState(OSD_ITEM_1_2_3_STATE);
        break;
        case INPUT_SC_DP:
        SetOSDState(OSD_ITEM_1_2_4_STATE);
        break;
        case INPUT_SC_YPbPr:
        default:
        break;
    }
    //printf("OSDFocusInput: UserData.ucInputSource = %d\n", (USHRT)UserData.ucInputSource);
}

void OSDFocusHPos(void)
{
    OSDShowHPos(TRUE, FALSE);
}

void OSDFocusVPos(void)
{
    OSDShowVPos(TRUE, FALSE);
}

void OSDFocusClock(void)
{
    OSDShowClock(TRUE, FALSE);
}

void OSDFocusPhase(void)
{
    OSDShowPhase(TRUE, FALSE);
}

void OSDFocusBr(void)
{
    OSDShowBrightness(TRUE, FALSE);
}

void OSDFocusCn(void)
{
    OSDShowContrast(TRUE, FALSE);
}

void OSDFocusGamma(void)
{
    //printf("OSDFocusGamma: UserData.ucGamma = %d\n", (USHRT)UserData.ucGamma);
    SetOSDState(OSD_ITEM_2_4_1_STATE+GetGammaNum());
    Custom_System.ucOSD_preview_temp = GetGammaNum();
}

void OSDFocusClrTmp(void)
{
    //printf("OSDFocusClrTmp: UserData.ucColorTemp = %d\n", (USHRT)UserData.ucColorTemp);

    SetOSDState(OSD_ITEM_2_5_1_STATE+UserData.ucColorTemp);
    Custom_System.ucOSD_preview_temp = UserData.ucColorTemp;
}

void OSDFocusVolume(void)
{
    OSDShowVolume(TRUE, FALSE);
}

void OSDFocusReset(void)
{
    //printf("OSDFocusReset\n");

    SetOSDState(OSD_ITEM_4_12_2_STATE);
}

void OSDShowBrightness(UCHAR redraw, BOOL Dlg)
{
    if (Dlg) {
        OSDShowSliderBar(9, 18, UserData.ucBrightness, TRUE, SLIDERBAR_BLUE_COLOR);
        bSelNum = TRUE;
        OSDShowNum(9, 5, UserData.ucBrightness);
    }
    else {
        if (redraw) {
            OSDShowSliderBar(38, 18, UserData.ucBrightness, TRUE, SLIDERBAR_BLUE_COLOR);
            bSelNum = TRUE;
            OSDShowNum(38, 5, UserData.ucBrightness);
        }
        else {
            OSDShowSliderBar(38, 18, UserData.ucBrightness, FALSE, SLIDERBAR_GRAY_COLOR);
            bSelNum = FALSE;
            OSDShowNum(38, 5, UserData.ucBrightness);
        }
    }
}

void OSDShowContrast(UCHAR redraw, BOOL Dlg)
{
    if (Dlg) {
        OSDShowSliderBar(9, 18, UserData.ucContrast, TRUE, SLIDERBAR_BLUE_COLOR);
        bSelNum = TRUE;
        OSDShowNum(9, 5, UserData.ucContrast);
    }
    else {
        if (redraw) {
            OSDShowSliderBar(38, 18, UserData.ucContrast, TRUE, SLIDERBAR_BLUE_COLOR);
            bSelNum = TRUE;
            OSDShowNum(38, 5, UserData.ucContrast);
        }
        else {
            OSDShowSliderBar(38, 18, UserData.ucContrast, FALSE, SLIDERBAR_GRAY_COLOR);
            bSelNum = FALSE;
            OSDShowNum(38, 5, UserData.ucContrast);
        }
    }
}

void OSDShowSharpness(UCHAR redraw, BOOL Dlg)
{
    if (Dlg) {
        OSDShowSliderBar(9, 18, Remap10To100(UserData.ucSharpness), TRUE, SLIDERBAR_BLUE_COLOR);
        bSelNum = TRUE;
        OSDShowNum(9, 5, UserData.ucSharpness);
    }
    else {
        if (redraw) {
            OSDShowSliderBar(38, 18, Remap10To100(UserData.ucSharpness), TRUE, SLIDERBAR_BLUE_COLOR);
            bSelNum = TRUE;
            OSDShowNum(38, 5, UserData.ucSharpness);
        }
        else {
            OSDShowSliderBar(38, 18, Remap10To100(UserData.ucSharpness), FALSE, SLIDERBAR_GRAY_COLOR);
            bSelNum = FALSE;
            OSDShowNum(38, 5, UserData.ucSharpness);
        }
    }
}

void OSDShowHue(UCHAR redraw, BOOL Dlg)
{
    if (Dlg) {
        OSDShowSliderBar(9, 18, UserData.ucHue, TRUE, SLIDERBAR_BLUE_COLOR);
        bSelNum = TRUE;
        OSDShowNum(9, 5, UserData.ucHue);
    }
    else {
        if (redraw) {
            OSDShowSliderBar(38, 18, UserData.ucHue, TRUE, SLIDERBAR_BLUE_COLOR);
            bSelNum = TRUE;
            OSDShowNum(38, 5, UserData.ucHue);
        }
        else {
            OSDShowSliderBar(38, 18, UserData.ucHue, FALSE, SLIDERBAR_GRAY_COLOR);
            bSelNum = FALSE;
            OSDShowNum(38, 5, UserData.ucHue);
        }
    }
}

void OSDShowSaturation(UCHAR redraw, BOOL Dlg)
{
    if (Dlg) {
        OSDShowSliderBar(9, 18, UserData.ucSaturation, TRUE, SLIDERBAR_BLUE_COLOR);
        bSelNum = TRUE;
        OSDShowNum(9, 5, UserData.ucSaturation);
    }
    else {
        if (redraw) {
            OSDShowSliderBar(38, 18, UserData.ucSaturation, TRUE, SLIDERBAR_BLUE_COLOR);
            bSelNum = TRUE;
            OSDShowNum(38, 5, UserData.ucSaturation);
        }
        else {
            OSDShowSliderBar(38, 18, UserData.ucSaturation, FALSE, SLIDERBAR_GRAY_COLOR);
            bSelNum = FALSE;
            OSDShowNum(38, 5, UserData.ucSaturation);
        }
    }
}

void OSDShowPhase(UCHAR redraw, BOOL Dlg)
{
    UCHAR phase;
    phase = UserGetNormalPhase();

    phase = pInputTiming->ucPhase;
    if (Dlg) {
        OSDShowSliderBar(9, 18, Remap63To100(phase), TRUE, SLIDERBAR_BLUE_COLOR);
        bSelNum = TRUE;
        OSDShowNum(9, 5, phase);
    }
    else {
        if (redraw) {
            OSDShowSliderBar(38, 18, Remap63To100(phase), TRUE, SLIDERBAR_BLUE_COLOR);
            bSelNum = TRUE;
            OSDShowNum(38, 5, phase);
        }
        else {
            OSDShowSliderBar(38, 18, Remap63To100(phase), FALSE, SLIDERBAR_GRAY_COLOR);
            bSelNum = FALSE;
            OSDShowNum(38, 5, phase);
        }
    }
}

void OSDShowClock(UCHAR redraw, BOOL Dlg)
{
    UCHAR clock;

    clock = UserGetNormalClock();

    if (Dlg) {
        OSDShowSliderBar(9, 18, clock, TRUE, SLIDERBAR_BLUE_COLOR);
        bSelNum = TRUE;
        OSDShowNum(9, 5, clock);
    }
    else {
        if (redraw) {
            OSDShowSliderBar(38, 18, clock, TRUE, SLIDERBAR_BLUE_COLOR);
            bSelNum = TRUE;
            OSDShowNum(38, 5, clock);
        }
        else {
            OSDShowSliderBar(38, 18, clock, FALSE, SLIDERBAR_GRAY_COLOR);
            bSelNum = FALSE;
            OSDShowNum(38, 5, clock);
        }
    }
}

void OSDShowHPos(UCHAR redraw, BOOL Dlg)
{
    UCHAR pos;

    pos = UserGetNormalHPosn();

    if (Dlg) {
        OSDShowSliderBar(9, 18, pos, TRUE, SLIDERBAR_BLUE_COLOR);
        bSelNum = TRUE;
        OSDShowNum(9, 5, pos);
    }
    else {
        if (redraw) {
            OSDShowSliderBar(38, 18, pos, TRUE, SLIDERBAR_BLUE_COLOR);
            bSelNum = TRUE;
            OSDShowNum(38, 5, pos);
        }
        else {
            OSDShowSliderBar(38, 18, pos, FALSE, SLIDERBAR_GRAY_COLOR);
            bSelNum = FALSE;
            OSDShowNum(38, 5, pos);
        }
    }
}

void OSDShowVPos(UCHAR redraw, BOOL Dlg)
{
    UCHAR pos;

    pos = UserGetNormalVPosn();

    if (Dlg) {
        OSDShowSliderBar(9, 18, pos, TRUE, SLIDERBAR_BLUE_COLOR);
        bSelNum = TRUE;
        OSDShowNum(9, 5, pos);
    }
    else {
        if (redraw) {
            OSDShowSliderBar(38, 18, pos, TRUE, SLIDERBAR_BLUE_COLOR);
            bSelNum = TRUE;
            OSDShowNum(38, 5, pos);
        }
        else {
            OSDShowSliderBar(38, 18, pos, FALSE, SLIDERBAR_GRAY_COLOR);
            bSelNum = FALSE;
            OSDShowNum(38, 5, pos);
        }
    }
}




void OSDShowRGain(UCHAR redraw, BOOL Dlg)
{
    if (Dlg) {
        OSDShowSliderBar(9, 18, UserData.ucUserRGain, TRUE, SLIDERBAR_BLUE_COLOR);
        bSelNum2 = TRUE;
        OSDShowNum2(9, 5, UserData.ucUserRGain,0);
    }
    else {
        if (redraw) {
            OSDShowSliderBar(48, 18, UserData.ucUserRGain, TRUE, SLIDERBAR_RED_COLOR);
            bSelNum2 = TRUE;
            OSDShowNum2(48, 6, UserData.ucUserRGain,0);
        }
        else {
            OSDShowSliderBar(48, 18, UserData.ucUserRGain, FALSE, SLIDERBAR_GRAY_COLOR );
            bSelNum2 = FALSE;
            OSDShowNum2(48, 6, UserData.ucUserRGain,0);
        }
    }
    OSDAPI_SetFontAttr(NumberColor3);
    OSDAPI_SetIndentIndex(String_Layer4_Index+3);
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    ShowIndentString(TRUE, 49,4, 2, RGB_Slider_BAR_Tab[UserData.ucLanguage]);
}

void OSDShowGGain(UCHAR redraw, BOOL Dlg)
{
    if (Dlg) {
        OSDShowSliderBar(9, 18, UserData.ucUserGGain, TRUE, SLIDERBAR_BLUE_COLOR);
        bSelNum2 = TRUE;
        OSDShowNum2(9, 5, UserData.ucUserGGain,5);
    }
    else {
        if (redraw) {
            OSDShowSliderBar(52, 18, UserData.ucUserGGain, TRUE, SLIDERBAR_GREEN_COLOR);
            bSelNum2 = TRUE;        
            OSDShowNum2(52, 6, UserData.ucUserGGain,5);
        }
        else {
            OSDShowSliderBar(52, 18, UserData.ucUserGGain, FALSE, SLIDERBAR_GRAY_COLOR);
            bSelNum2 = FALSE;
            OSDShowNum2(52, 6, UserData.ucUserGGain,5);
        }
    }
    
    OSDAPI_SetFontAttr(NumberColor3);
    OSDAPI_SetIndentIndex(String_Layer4_Index+8);
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    ShowIndentString(TRUE, 53,4, 2, RGB_Slider_BAR_Tab[NUM_OSDLANGS+UserData.ucLanguage]);
}

void OSDShowBGain(UCHAR redraw, BOOL Dlg)
{

    if (Dlg) {
        OSDShowSliderBar(9, 18, UserData.ucUserBGain, TRUE, SLIDERBAR_BLUE_COLOR);
        bSelNum2 = TRUE;
        OSDShowNum2(9, 5, UserData.ucUserBGain,10);
    }
    else {
        if (redraw) {
            OSDShowSliderBar(56, 18, UserData.ucUserBGain, TRUE, SLIDERBAR_BLUE_COLOR);
            bSelNum2 = TRUE;
            OSDShowNum2(56, 6, UserData.ucUserBGain,10);
        }
        else {
            OSDShowSliderBar(56, 18, UserData.ucUserBGain, FALSE, SLIDERBAR_GRAY_COLOR);
            bSelNum2 = FALSE;
            OSDShowNum2(56, 6, UserData.ucUserBGain,10);
        }
    }
    OSDAPI_SetFontAttr(NumberColor3);
    OSDAPI_SetIndentIndex(String_Layer4_Index+13);
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    ShowIndentString(TRUE, 57,4, 2, RGB_Slider_BAR_Tab[2*NUM_OSDLANGS+UserData.ucLanguage]);
}
void OSDShowVolume(UCHAR redraw, BOOL Dlg)
{
      UCHAR temp;
      temp = UserData.ucVolume;
      if(UserData.bAudioMute){
          UserData.ucVolume = 0;
      }
    
    if (Dlg) {
        OSDShowSliderBar(9, 18, UserData.ucVolume, TRUE, SLIDERBAR_BLUE_COLOR);
        bSelNum = TRUE;
        OSDShowNum(9, 5, UserData.ucVolume);
    }
    else {
        if (redraw) {
            OSDShowSliderBar(38, 18, UserData.ucVolume, TRUE, SLIDERBAR_BLUE_COLOR);
            bSelNum = TRUE;
           OSDShowNum(38, 5, UserData.ucVolume);

          }
        else {
            OSDShowSliderBar(38, 18, UserData.ucVolume, FALSE, SLIDERBAR_GRAY_COLOR);
            bSelNum = FALSE;          
            OSDShowNum(38, 5, UserData.ucVolume);
        }
    }
    if(UserData.bAudioMute){
      UserData.ucVolume = temp;
   }
}

void OSDShowDynamicContrast(UCHAR redraw)
{
    if (redraw) {
        OSDShowSliderBar(38, 18, Remap5To100(UserData.ucDynamicContrast), TRUE, SLIDERBAR_BLUE_COLOR);
        bSelNum = TRUE;
        OSDShowNum(38, 5, UserData.ucDynamicContrast);
    }
    else {
        OSDShowSliderBar(38, 18, Remap5To100(UserData.ucDynamicContrast), FALSE, SLIDERBAR_GRAY_COLOR);
        bSelNum = FALSE;
        OSDShowNum(38, 5, UserData.ucDynamicContrast);
    }
}

void OSDShowOD(UCHAR redraw)
{
    redraw = redraw;

/*
    if (redraw)
    {
#if OSDTYPE == OSD_BENQ 
    OSDAPI_SetIndentIndex(100);
#else
    OSDAPI_SetIndentIndex(48);
#endif  
        OSDAPI_SetAlignType(OSD_ALIGN_LEFT);

    }

    OSDAPI_SetAlignType(OSD_ALIGN_CENTER);
#if OSDTYPE == OSD_BENQ 
    OSDAPI_SetIndentIndex(116);
#else
    OSDAPI_SetIndentIndex(64);
#endif  



    //OSDAPI_SelOSDWin(OSD_WINDOW2);
    //OSDAPI_SetOSDWinSize( 5, 8+2*UserData.ucODMode,
    //                     29, 8+2*UserData.ucODMode);
    //OSDAPI_OSDWinOn(OSD_WINDOW2);
*/
}


/*
void OSDShowBFMenu(void)
{
#ifndef DISABLE_FALCON_STRING
    UCHAR i;
#endif // DISABLE_FALCON_STRING
    OSDWinAttr attr;

    ucMenuType = OSD_BF_MENU;

    OSDInitialize(FALSE);
    OSDInitFrame(OSD_BF_WIDTH, OSD_BF_HEIGHT, BF_MENU_COLOR);
    OSDAPI_SetPosition(50, 2);

    OSDAPI_FillLineAttr(0,0,OSD_BF_WIDTH, TITLE_COLOR);
    OSDAPI_FillLineAttr(0,1,OSD_BF_WIDTH, TITLE_COLOR);
    OSDAPI_FillLineAttr(0,2,OSD_BF_WIDTH, TITLE_COLOR);

    OSDAPI_SelOSDWin(OSD_WINDOW7);
    RST_WINATTR_ALL(attr);
    attr.ucWinClr = I_TGREEN;
    OSDAPI_SetOSDWinAttr(attr);
    OSDAPI_SetOSDWinSize(0, 0, OSD_BF_WIDTH-1, 2);
    OSDAPI_SetOSDWinGrad(0x00, 0x00, 0x02, 0x01);

    OSDAPI_SelOSDWin(OSD_WINDOW6);
    attr.ucWinClr = I_WHITE;
    OSDAPI_SetOSDWinAttr(attr);
    OSDAPI_SetOSDWinSize(0, 3, OSD_BF_WIDTH-1, OSD_BF_HEIGHT);
    OSDAPI_SetOSDWinGrad(0x00, 0x01, 0x01, 0x01);

    OSDAPI_OSDWinOn(OSD_WINDOW7);
    OSDAPI_OSDWinOn(OSD_WINDOW6);

#if OSDTYPE == OSD_BENQ 
    OSDAPI_SetIndentIndex(100);
#else
    OSDAPI_SetIndentIndex(32);
#endif  
    OSDAPI_SetAlignType(OSD_ALIGN_CENTER);
    OSDAPI_SelOSDWin(OSD_WINDOW2);
    RST_WINATTR_ALL(attr);
    attr.ucWinClr = I_WHITE;
    SET_WINATTR_BEVEL(attr);
    SET_BEVEL_TYPE(attr,0);
    SET_BEVEL_WIDTH(attr,1);
    attr.ucRBorderClr = I_MAGENTA;
    attr.ucLBorderClr = I_MAGENTA;
    OSDAPI_SetOSDWinAttr(attr);
    OSDAPI_SetOSDWinSize(0, UserData.ucBFMode * 2 + 4, OSD_BF_WIDTH - 1, UserData.ucBFMode * 2 + 4);
    OSDAPI_OSDWinOn(OSD_WINDOW2);

    OSDTurnOnOSD();
}
*/
void OSDUpdateAutoTuneBar(UCHAR percentage)
{
     percentage = percentage;
    //if (ucMenuType == OSD_DLG_AUTOTUNE) {
    //    OSDShowSliderBar(4, 4, percentage);
    //}
}

//******************************************************************************
// Prototype:
//  void OSDPerformAuto(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Perform auto tune
// Notes:
//  None
//******************************************************************************
void OSDPerformAuto(void)
{

    UCHAR interface ;

    UCHAR idxbk = ucSCIdx;
    SetScalerIndex(_MainChannel);   
    interface = GetCurrInputInterface();
    pInputTiming = GetModeHandleInputTiming(_MainChannel);
    if (GetScalerSyncMode(_MainChannel) != DIG_SYNC &&
        interface != ANALOG_YPBPR_INPUT0 &&
        interface != ANALOG_YPBPR_INPUT1 &&
        GetProductModeFlag()== FALSE) {
        Custom_System.bAutoTuneFinish = FALSE;

        OSDShowDialog(OSD_DLG_AUTOTUNE,0);
        OSDUpdateAutoTuneBar(0);
        UserPerformAutoTune();
        UserData.bSensEyeDemo = OFF;
        SetDemo();            
     SetOSDUpdUsrFlag();
        Sleep(100);            //  timer too short, the 100 message can not display.
        Custom_System.bAutoTuneFinish = TRUE;

        if (pInputTiming->ucAutoTune != 0) {
            NvramWriteTimingData(pInputTiming);
        }
        OSDCloseAll();      
    }
    SetScalerIndex(idxbk);  
  
}

void OSDPerformAutoTune(void)
{
    pInputTiming = GetModeHandleInputTiming(_MainChannel);
    if ((GetInputSyncMode() != DIG_SYNC) && (pInputTiming->ucAutoTune == 0) && GetProductModeFlag() == FALSE )
    {
        OSDShowDialog(OSD_DLG_AUTOTUNE,0);
        UserPerformAutoTune();
        UserData.bSensEyeDemo = OFF;
        SetDemo();            
     SetOSDUpdUsrFlag();        
        OSDClosed();
        if (pInputTiming->ucAutoTune != 0) {
            // Save timing data immediately for fitting some customer requirements.
            //SetOSDUpdTmgFlag();
            NvramWriteTimingData(pInputTiming);
        }
    }

}

//******************************************************************************
// Prototype:
//
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
void OSDPerformNormal(void)
{

    pInputTiming = GetModeHandleInputTiming(_MainChannel);

    if (UserData.ucInputSource != UserGetInputSource()) {
        UserData.ucInputSource = UserGetInputSource();
        SetOSDUpdUsrFlag();
        SetOSDState(OSD_INFO_NOTICE_STATE);
        OSDShowDialog(OSD_DLG_NOTICE,0);
        bShowInputNovitceFlag = FALSE;        
    }
    else if(bShowInputNovitceFlag){
        SetOSDState(OSD_INFO_NOTICE_STATE);
        OSDShowDialog(OSD_DLG_NOTICE,0);    
        bShowInputNovitceFlag = FALSE;
    }
    else{
        OSDPerformAutoTune();
         // printf("OSD_INFO_NOTICE_STATE %d  %d\r\n", (USHRT)IsNativeTiming(), (USHRT)UserData.bResNotice);
             if((!IsNativeTiming())&&(IsShowResolutionNotice())&&(!IsVideoTiming())){
                 SetOSDState(OSD_RES_NOTICE_STATE);
                 OSDShowDialog(OSD_DLG_RESNOTE,0);
          }
          else{
             if(IsPreSetModeTiming()){
                     OSDCloseAll();
             } 
             else{            
                     if(!IsVideoTiming()){
                     SetOSDState(OSD_INFO_NONPRESET_STATE);
                     OSDShowDialog(OSD_DLG_NONPRESET,0);
             }
         }    
    }
    }


   if(IsTimingChanged()){
       CurrentTimingSaved();
       SetOSDUpdUsrFlag();
   }

    ResetWDTimer();
    OSDResetSmartRemiderTimer(TRUE);
}

void OSDShowOSDLock(void)
{
    OSDShowDialog(OSD_DLG_OSDLOCK,0);
}

BOOL NeedBackgroundToBlue(void)
{
    BOOL  Flag_BLUE = FALSE;
    UCHAR curr_interface;
    curr_interface = GetCurrInputInterface();

    if(bIsHDMIManualSyncSource(curr_interface)||bIsDPManualSyncSource(curr_interface)){
        Flag_BLUE = TRUE;
    }

    if(((UserData.ucInputSource == INPUT_SC_HDMI)|(UserData.ucInputSource == INPUT_SC_HDMI1)
        |(UserData.ucInputSource == INPUT_SC_HDMI2)|(UserData.ucInputSource == INPUT_SC_HDMI3)|(UserData.ucInputSource == INPUT_SC_HDMI4))){
        Flag_BLUE = TRUE;
    }
    if (((UserData.ucInputSource == INPUT_SC_DP)|(UserData.ucInputSource == INPUT_SC_DP2))) {
        Flag_BLUE = TRUE;
    }
    return Flag_BLUE;
}


void OSDShowNoSync(void)
{
    // Turn on LVDS first to avoid dead lock in clear OSD
    OSDAPI_TurnOffOSD();
    PanelPowerOnSequence(FALSE);

#if ENABLE_OSD_ROTATION == ON
    if (UserData.bOSDRotation) {
        usOSDMovingX = MAX_ROT_X / 2;
        usOSDMovingY = 0x8000 + MAX_ROT_Y / 2;
    }
    else {
        usOSDMovingX = MAX_X / 2;
        usOSDMovingY = MAX_Y / 2;
    }
#else
    usOSDMovingX = MAX_X / 2;
    usOSDMovingY = MAX_Y / 2;
#endif
    if((SC_FRC_CENTER_MODE & BIT7) == BIT7){
        SC_FRC_CENTER_MODE &= ~BIT7;
    }

    if (NeedBackgroundToBlue()== TRUE) {
        ODAPI_ODTestPatternDisable();
        SetPostBGColor(0x00, 0x00, 0xFF);
    }
    else {
        SetPostBGColor(0x00, 0x00, 0x00);
    }
    
    OSDShowDialog(OSD_DLG_NOSYNC,0);
}

void OSDShowNoCable(void)
{
    // Turn on LVDS first to avoid dead lock in clear OSD
    OSDAPI_TurnOffOSD();    
    PanelPowerOnSequence(FALSE);

#if ENABLE_OSD_ROTATION == ON
    if (UserData.bOSDRotation) {
        usOSDMovingX = MAX_ROT_X / 2;
        usOSDMovingY = 0x8000 + MAX_ROT_Y / 2;
    }
    else {
        usOSDMovingX = MAX_X / 2;
        usOSDMovingY = MAX_Y / 2;
    }
#else
    usOSDMovingX = MAX_X / 2;
    usOSDMovingY = MAX_Y / 2;
#endif
    if((SC_FRC_CENTER_MODE & BIT7) == BIT7){
         SC_FRC_CENTER_MODE &= ~BIT7;
     }

    if (NeedBackgroundToBlue()== TRUE) {
        ODAPI_ODTestPatternDisable();
        SetPostBGColor(0x00, 0x00, 0xFF);
    }
    else {
        SetPostBGColor(0x00, 0x00, 0x00);
    }
    
    if (Custom_System.bFactory) {
        //OSDShowDialog(OSD_DLG_BURNIN,0);
    }
    else {
        OSDShowDialog(OSD_DLG_NOCABLE,0);
    }
}

void OSDShowOOL(void)
{
    if (UserData.ucInputSource != UserGetInputSource()) {
        UserData.ucInputSource = UserGetInputSource();
        SetOSDUpdUsrFlag();
    }
    pInputTiming = GetModeHandleInputTiming(_MainChannel);

    if ((GetInputSyncMode() != DIG_SYNC) && (pInputTiming->ucAutoTune == 0) && GetProductModeFlag() == FALSE)
    {
        OSDShowDialog(OSD_DLG_AUTOTUNE,0);
        UserPerformAutoTune();
        UserData.bSensEyeDemo = OFF;
        SetDemo();            
        SetOSDUpdUsrFlag();        
        OSDClosed();
        if (pInputTiming->ucAutoTune != 0) {
            SetOSDUpdTmgFlag();
        }
    }

    OSDShowDialog(OSD_DLG_85Hz,0);
}

void OSDShowOOR(void)
{
    // Turn on LVDS first to avoid dead lock in clear OSD
    PanelPowerOnSequence(FALSE);

#if ENABLE_OSD_ROTATION == ON
    if (UserData.bOSDRotation) {
        usOSDMovingX = MAX_ROT_X / 2;
        usOSDMovingY = 0x8000 + MAX_ROT_Y / 2;
    }
    else {
        usOSDMovingX = MAX_X / 2;
        usOSDMovingY = MAX_Y / 2;
    }
#else
    usOSDMovingX = MAX_X / 2;
    usOSDMovingY = MAX_Y / 2;
#endif
    if((SC_FRC_CENTER_MODE & BIT7) == BIT7){
        SC_FRC_CENTER_MODE &= ~BIT7;
    }

    OSDShowDialog(OSD_DLG_OUTOFRANGE,0);
}

//******************************************************************************
// Prototype:
//  Please refer to the following
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  The following are for OSD up/down operations
// Notes:
//  None
//******************************************************************************
void OSDBrightnessUp(void)
{
    //printf("Br up\n");
    UserData.ucBrightness++;
    if (UserData.ucBrightness > MAXIMUM_BRIGHTNESS)
        UserData.ucBrightness  = MAXIMUM_BRIGHTNESS;
    else {
        OSDShowBrightness(TRUE, FALSE);

        UserSetBrightness();
    }
    SetOSDUpdUsrFlag();
}

void OSDBrightnessDown(void)
{
    //printf("Br down\n");
    UserData.ucBrightness--;
    if ((UserData.ucBrightness > MAXIMUM_BRIGHTNESS) ||
        (UserData.ucBrightness < MINIMUM_BRIGHTNESS))
        UserData.ucBrightness  = MINIMUM_BRIGHTNESS;
    else {
        OSDShowBrightness(TRUE, FALSE);
        UserSetBrightness();
    }
    SetOSDUpdUsrFlag();
}

void OSDContrastUp(void)
{
    UserData.ucContrast++;
    if (UserData.ucContrast > MAXIMUM_CONTRAST)
        UserData.ucContrast  = MAXIMUM_CONTRAST;
    else {
        OSDShowContrast(TRUE, FALSE);
        UserSetContrast();
    }
    SetOSDUpdUsrFlag();
}

void OSDContrastDown(void)
{
    UserData.ucContrast--;
    if ((UserData.ucContrast > MAXIMUM_CONTRAST) ||
        (UserData.ucContrast < MINIMUM_CONTRAST))
        UserData.ucContrast  = MINIMUM_CONTRAST;
    else {
        OSDShowContrast(TRUE, FALSE);
        UserSetContrast();
    }
    SetOSDUpdUsrFlag();
}

void OSDCustVolumeDown(void)
{
    if(UserData.bAudioMute){
        return;
    }    
    UserData.ucVolume--;
    if (UserData.ucVolume > MAXIMUM_VOLUME || UserData.ucVolume < MINIMUM_VOLUME) {
        UserData.ucVolume = MINIMUM_VOLUME;
    }
    else {
    OSDShowVolume(TRUE, TRUE);
    UserSetVolume();
    SetOSDUpdUsrFlag();
    }
}

void OSDCustVolumeUp(void)
{
    UserData.ucVolume++;
    
   // if(bIsAudioMute() == TRUE){
   if (UserData.bAudioMute == ON){
        UserData.ucVolume = 1;
        UserData.bAudioMute = OFF;
        UserSetVolume();    
        Sleep(800);//wait  pwm  stable
        UserSetAudioMute();   
       OSDAPI_SetIndentIndex(String_TopPage_Index);
       OSDShowTopPageIcon(TP_VOLUME, 1, 0);
    }
    if (UserData.ucVolume > MAXIMUM_VOLUME)
        UserData.ucVolume  = MAXIMUM_VOLUME;
    else{
       OSDShowVolume(TRUE, TRUE);
       UserSetVolumeAndMute();
       SetOSDUpdUsrFlag();
    }
}

void OSDCustBrightnessUp(void)
{
    UserData.ucBrightness++;
    if (UserData.ucBrightness > MAXIMUM_BRIGHTNESS)
        UserData.ucBrightness  = MAXIMUM_BRIGHTNESS;
    else {
        OSDShowBrightness(TRUE, TRUE);

        UserSetBrightness();
    }
    SetOSDUpdUsrFlag();
}

void OSDCustBrightnessDown(void)
{
    UserData.ucBrightness--;
    if ((UserData.ucBrightness > MAXIMUM_BRIGHTNESS) ||
        (UserData.ucBrightness < MINIMUM_BRIGHTNESS))
        UserData.ucBrightness  = MINIMUM_BRIGHTNESS;
    else {
        OSDShowBrightness(TRUE, TRUE);
        UserSetBrightness();
    }
    SetOSDUpdUsrFlag();
}

void OSDCustContrastUp(void)
{
    UserData.ucContrast++;
    if (UserData.ucContrast > MAXIMUM_CONTRAST)
        UserData.ucContrast  = MAXIMUM_CONTRAST;
    else {
        OSDShowContrast(TRUE, TRUE);
        UserSetContrast();
    }
    SetOSDUpdUsrFlag();
}

void OSDCustContrastDown(void)
{
    UserData.ucContrast--;
    if ((UserData.ucContrast > MAXIMUM_CONTRAST) ||
        (UserData.ucContrast < MINIMUM_CONTRAST))
        UserData.ucContrast  = MINIMUM_CONTRAST;
    else {
        OSDShowContrast(TRUE, TRUE);
        UserSetContrast();
    }
    SetOSDUpdUsrFlag();
}

void OSDSharpnessUp(void)
{
    UserData.ucSharpness++;
    if (UserData.ucSharpness > MAXIMUM_SHARPNESS)
        UserData.ucSharpness  = MAXIMUM_SHARPNESS;
    else {
        OSDShowSharpness(TRUE, FALSE);
        UserSetSharpness();
    }
    SetOSDUpdUsrFlag();
}

void OSDSharpnessDown(void)
{
    UserData.ucSharpness--;
    if ((UserData.ucSharpness > MAXIMUM_SHARPNESS) ||
        (UserData.ucSharpness < MINIMUM_SHARPNESS))
        UserData.ucSharpness  = MINIMUM_SHARPNESS;
    else {
        OSDShowSharpness(TRUE, FALSE);
        UserSetSharpness();
    }
    SetOSDUpdUsrFlag();
}

void OSDGammaUp(void)
{

    UCHAR GammaTemp;
    GammaTemp = GetGammaNum();
    GammaTemp--;
    if (GammaTemp > MAXIMUM_GAMMA_NUM || GammaTemp < MINIMUM_GAMMA_NUM) {
        GammaTemp = MAXIMUM_GAMMA_NUM;
    }
    SetGammaNum(GammaTemp);
     //printf("OSDGammaUp %d\n", (USHRT)GetGammaNum());

    //UserData.bGammaOnOff = ~UserData.bGammaOnOff;
    UserSetGamma();
//    SetOSDUpdUsrFlag();

}

void OSDGammaDown(void)
{
    UCHAR GammaTemp;
    GammaTemp = GetGammaNum();

    if (++GammaTemp > MAXIMUM_GAMMA_NUM) {
        GammaTemp  = MINIMUM_GAMMA_NUM;
    }
    SetGammaNum(GammaTemp);
    //printf("OSDGammaDown %d\n", (USHRT)GetGammaNum());
    //UserData.bGammaOnOff = ~UserData.bGammaOnOff;
    UserSetGamma();
//    SetOSDUpdUsrFlag();

}

void OSDPhaseUp(void)
{
    pInputTiming = GetModeHandleInputTiming(_MainChannel);

    pInputTiming->ucPhase++;
    if (pInputTiming->ucPhase > MAXIMUM_PHASE) {
        pInputTiming->ucPhase  = MAXIMUM_PHASE;
    }
    else {
        UserSetPhase();
        OSDShowPhase(TRUE, FALSE);

    }
    SetOSDUpdTmgFlag();
}

void OSDPhaseDown(void)
{
    pInputTiming = GetModeHandleInputTiming(_MainChannel);
    pInputTiming->ucPhase--;
    if ((pInputTiming->ucPhase > MAXIMUM_PHASE) ||
        (pInputTiming->ucPhase < MINIMUM_PHASE))
        pInputTiming->ucPhase  = MINIMUM_PHASE;
    else {
        UserSetPhase();
        OSDShowPhase(TRUE, FALSE);
    }
    SetOSDUpdTmgFlag();
}

void OSDClockUp(void)
{
    pInputTiming = GetModeHandleInputTiming(_MainChannel);
    pInputTiming->usHTotal++;
    if ( pInputTiming->usHTotal >  pInputTiming->usHTotalMax)
         pInputTiming->usHTotal  =  pInputTiming->usHTotalMax;
    else {
        UserSetClock();
        OSDShowClock(TRUE, FALSE);        
    }
    SetOSDUpdTmgFlag();
}

void OSDClockDown(void)
{
    pInputTiming = GetModeHandleInputTiming(_MainChannel);
    pInputTiming->usHTotal--;
    if (pInputTiming->usHTotal < pInputTiming->usHTotalMin)
        pInputTiming->usHTotal  = pInputTiming->usHTotalMin;
    else {
        UserSetClock();
        OSDShowClock(TRUE, FALSE);        
    }
    SetOSDUpdTmgFlag();
}

void OSDHPositionUp(void)
{
    pInputTiming = GetModeHandleInputTiming(_MainChannel);
    pInputTiming->usHStart++;
    if (pInputTiming->usHStart > pInputTiming->usHStartMax) {
        pInputTiming->usHStart  = pInputTiming->usHStartMax;
    }
    else {
        UserSetHPosition();
        OSDShowHPos(TRUE, FALSE);        
    }
    SetOSDUpdTmgFlag();
}

void OSDHPositionDown(void)
{
    pInputTiming = GetModeHandleInputTiming(_MainChannel);
    pInputTiming->usHStart--;
    if ((pInputTiming->usHStart > pInputTiming->usHStartMax) ||
        (pInputTiming->usHStart < pInputTiming->usHStartMin)) {
         pInputTiming->usHStart  = pInputTiming->usHStartMin;
    }
    else {
        UserSetHPosition();
        OSDShowHPos(TRUE, FALSE);        
    }
    SetOSDUpdTmgFlag();
}

void OSDVPositionUp(void)
{
    pInputTiming = GetModeHandleInputTiming(_MainChannel);
    pInputTiming->usVStart++;
    if (pInputTiming->usVStart > pInputTiming->usVStartMax)
        pInputTiming->usVStart  = pInputTiming->usVStartMax;
    else {
        UserSetVPosition();
        OSDShowVPos(TRUE, FALSE);        
    }
    SetOSDUpdTmgFlag();
}

void OSDVPositionDown(void)
{
    pInputTiming = GetModeHandleInputTiming(_MainChannel);
    pInputTiming->usVStart--;
    if ((pInputTiming->usVStart > pInputTiming->usVStartMax) ||
        (pInputTiming->usVStart < pInputTiming->usVStartMin))
        pInputTiming->usVStart  = pInputTiming->usVStartMin;
    else {
        UserSetVPosition();
        OSDShowVPos(TRUE, FALSE);        
    }
    SetOSDUpdTmgFlag();
}

void OSDVolumeUp(void)
{
    UserData.ucVolume++;
//    if (bIsAudioMute() == TRUE){
    if (UserData.bAudioMute == ON){
        UserData.ucVolume = 1;
        UserData.bAudioMute = OFF;
        UserSetVolume();    
        Sleep(800);//wait  pwm  stable
        UserSetAudioMute();        
    }
    if (UserData.ucVolume > MAXIMUM_VOLUME) {
        UserData.ucVolume  = MAXIMUM_VOLUME;
    }
    else {
        OSDShowVolume(TRUE, FALSE);
        UserSetVolumeAndMute();
        SetOSDUpdUsrFlag();
    }
}

void OSDVolumeDown(void)
{
    if (UserData.bAudioMute){
        return;
    }    
    UserData.ucVolume--;
    if (UserData.ucVolume > MAXIMUM_VOLUME || UserData.ucVolume < MINIMUM_VOLUME) {
        UserData.ucVolume = MINIMUM_VOLUME;
    }
    else {
        OSDShowVolume(TRUE, FALSE);
        UserSetVolume();
        SetOSDUpdUsrFlag();
    }
}

void OSDColorTempUp(void)
{
//       if (--UserData.ucColorTemp > CLRTMP_USER) {
//        UserData.ucColorTemp = CLRTMP_USER;
//    }
    UserData.ucColorTemp = GetOSDState() - OSD_ITEM_2_5_1_STATE;
    UserSetColorTemp();
}


void OSDColorTempDown(void)
{
//    if (++UserData.ucColorTemp > CLRTMP_USER) {
//        UserData.ucColorTemp = CLRTMP_6500K;
//    }
    UserData.ucColorTemp = GetOSDState() - OSD_ITEM_2_5_1_STATE;
    UserSetColorTemp();
}

void OSDRGainUp(void)
{
    UserData.ucUserRGain++;
    if (UserData.ucUserRGain > MAXIMUM_USER_RGAIN)
        UserData.ucUserRGain  = MAXIMUM_USER_RGAIN;
    else {
        OSDShowRGain(TRUE, FALSE);
        UserSetRGain();
    }
    SetOSDUpdUsrFlag();
}

void OSDRGainDown(void)
{
    UserData.ucUserRGain--;
    if ((UserData.ucUserRGain > MAXIMUM_USER_RGAIN) ||
        (UserData.ucUserRGain < MINIMUM_USER_RGAIN))
        UserData.ucUserRGain  = MINIMUM_USER_RGAIN;
    else {
        OSDShowRGain(TRUE, FALSE);
        UserSetRGain();
    }
    SetOSDUpdUsrFlag();
}

void OSDGGainUp(void)
{
    UserData.ucUserGGain++;
    if (UserData.ucUserGGain > MAXIMUM_USER_GGAIN)
        UserData.ucUserGGain  = MAXIMUM_USER_GGAIN;
    else {
        OSDShowGGain(TRUE, FALSE);
        UserSetGGain();
    }
    SetOSDUpdUsrFlag();
}

void OSDGGainDown(void)
{
    UserData.ucUserGGain--;
    if ((UserData.ucUserGGain > MAXIMUM_USER_GGAIN) ||
        (UserData.ucUserGGain < MINIMUM_USER_GGAIN))
        UserData.ucUserGGain  = MINIMUM_USER_GGAIN;
    else {
        OSDShowGGain(TRUE, FALSE);
        UserSetGGain();
    }
    SetOSDUpdUsrFlag();
}

void OSDBGainUp(void)
{
    UserData.ucUserBGain++;
    if (UserData.ucUserBGain > MAXIMUM_USER_BGAIN)
        UserData.ucUserBGain  = MAXIMUM_USER_BGAIN;
    else {
        OSDShowBGain(TRUE, FALSE);
        UserSetBGain();
    }
    SetOSDUpdUsrFlag();
}

void OSDBGainDown(void)
{
    UserData.ucUserBGain--;
    if ((UserData.ucUserBGain > MAXIMUM_USER_BGAIN) ||
        (UserData.ucUserBGain < MINIMUM_USER_BGAIN))
        UserData.ucUserBGain  = MINIMUM_USER_BGAIN;
    else {
        OSDShowBGain(TRUE, FALSE);
        UserSetBGain();
    }
    SetOSDUpdUsrFlag();
}
#if 0
void OSDInputSourceUp(void)
{

    UCHAR Index;
    UCHAR len = CheckTotalPortNum();
#if ENABLE_PIP == ON
    UCHAR pip_index = GetInputPortIndex(UserData.ucPIPInputSrc);    
#endif
    Index = GetInputPortIndex(UserData.ucInputSource);
    if ( UserData.ucPIPMode == USER_PIPTYPE_OFF ) {
        if (GetInputPortName(++Index) >=  NUM_INPUT_SC) {
            Index = 0;//VGA
        }
    }
#if ENABLE_PIP == ON    
    else {
        do {
            Index = (Index+1)%len;
        }while( Index==pip_index );
    }
#endif
    AOC_SourceBuffer.ucInputSource = GetInputPortName(Index);
    //OSDShowInput(FALSE);
    //UserSetInputSource();
}
void OSDInputSourceDown(void)
{
    UCHAR Index;
#if ENABLE_PIP == ON    
    UCHAR pip_index = GetInputPortIndex(UserData.ucPIPInputSrc);
#endif
    UCHAR len = CheckTotalPortNum();

    Index = GetInputPortIndex(UserData.ucInputSource);
    if ( UserData.ucPIPMode == USER_PIPTYPE_OFF ) {
        if (GetInputPortName(--Index) >= NUM_INPUT_SC) {
            Index = CheckTotalPortNum()-1;
        }
    }
#if ENABLE_PIP == ON        
    else {
        do {
            Index--;
            if ( Index > len ) Index = len-1;
        }while( Index==pip_index );
    }
#endif
    UserData.ucInputSource = GetInputPortName(Index);
    //OSDShowInput(FALSE);
    //UserSetInputSource();}
}

void OSDDCRUp(void)
{
    UserData.bDCRMode = ~UserData.bDCRMode;
    //OSDShowDCR(FALSE);
    UserSetDCR();
    SetOSDUpdUsrFlag();
}

void OSDDCRDown(void)
{
    UserData.bDCRMode = ~UserData.bDCRMode;
   // OSDShowDCR(FALSE);
    UserSetDCR();
    SetOSDUpdUsrFlag();
}
#endif

void OSDAspectRatioUp(void)
{
    //1:1 <- full <- 4:3 <- ...
    if (UserData.ucAspectRatio == DSP_SIZE_1By1) {
        if (DetectAspectRatio() == DSP_SIZE_FULL) {
            UserData.ucAspectRatio = DSP_SIZE_FULL;
        }
        else {
            UserData.ucAspectRatio = DSP_SIZE_43;
        }
    }
    else if (UserData.ucAspectRatio == DSP_SIZE_FULL) {
        if (pInputTiming->usModeHActive == PANEL_WIDTH && pInputTiming->usModeVActive == PANEL_HEIGHT) {
            UserData.ucAspectRatio = DSP_SIZE_FULL;
            return;
        }
        else {
            UserData.ucAspectRatio = DSP_SIZE_1By1;
        }
    }
    else { //DSP_SIZE_43
        UserData.ucAspectRatio = DSP_SIZE_FULL;
    }
    
    SetAspRatioSetting();
#if ENABLE_PIP == ON    
    UserSetPictureMode();
#else
    UserSetAspectRatio();    
#endif
    //SetOSDUpdUsrFlag();
}

void OSDAspectRatioDown(void)
{
    //1:1 -> full -> 4:3 -> ...
    if (UserData.ucAspectRatio == DSP_SIZE_1By1) {
        UserData.ucAspectRatio = DSP_SIZE_FULL;
    }
    else if (UserData.ucAspectRatio == DSP_SIZE_FULL) {
        if (pInputTiming->usModeHActive == PANEL_WIDTH && pInputTiming->usModeVActive == PANEL_HEIGHT) {
            UserData.ucAspectRatio = DSP_SIZE_FULL;
            return;
        }
        else {
            if (DetectAspectRatio() == DSP_SIZE_FULL) {
                UserData.ucAspectRatio = DSP_SIZE_1By1;
            }
            else {
                UserData.ucAspectRatio = DSP_SIZE_43;
            }
        }
    }
    else { //DSP_SIZE_43
        UserData.ucAspectRatio = DSP_SIZE_1By1;
    }
    
    SetAspRatioSetting();
#if ENABLE_PIP == ON    
    UserSetPictureMode();
#else
    UserSetAspectRatio();    
#endif
    //SetOSDUpdUsrFlag();
}

void OSDSenseyeDemoUp(void)
{
    UserData.bSensEyeDemo = ~UserData.bSensEyeDemo;
    if(UserData.bSensEyeDemo == TRUE){
         SetSenseEyeLeftMode(PICTURE_MODE_STANDARD);
    }
    BFAPI_SetActiveWindow(BF_WINDOW_1);    
    SetDemo();
}

void OSDSenseyeDemoDown(void)
{
    UserData.bSensEyeDemo = ~UserData.bSensEyeDemo;
    if(UserData.bSensEyeDemo == TRUE){
         SetSenseEyeLeftMode(PICTURE_MODE_STANDARD);
    }
    BFAPI_SetActiveWindow(BF_WINDOW_1);    
    SetDemo();
}

void OSDODUp(void)
{
    UserData.ucODMode = (UserData.ucODMode + OD_NUM - 1)%OD_NUM;
    OSDShowOD(FALSE);
    UserSetOD();
    //SetOSDUpdUsrFlag();
}

void OSDODDown(void)
{
    UserData.ucODMode = (UserData.ucODMode+1)%OD_NUM;
    OSDShowOD(FALSE);
    UserSetOD();
    //SetOSDUpdUsrFlag();
}
#if 0
void OSDSourceMenuITMUp(void)
{
    UserData.ucInputSource =
        (UserData.ucInputSource+1)%NUM_INPUT_SC;

    OSDAPI_SelOSDWin(OSD_WINDOW2);
    OSDAPI_SetOSDWinSize(0, UserData.ucInputSource * 2 + 4, OSD_SRC_WIDTH - 1, UserData.ucInputSource * 2 + 4);
    OSDAPI_OSDWinOn(OSD_WINDOW2);

    //UserSetInputSource();
}

void OSDSourceMenuITMDn(void)
{
    UserData.ucInputSource =
        (UserData.ucInputSource+NUM_INPUT_SC-1)%NUM_INPUT_SC;


    OSDAPI_SelOSDWin(OSD_WINDOW2);
    OSDAPI_SetOSDWinSize(0, UserData.ucInputSource * 2 + 4, OSD_SRC_WIDTH - 1, UserData.ucInputSource * 2 + 4);
    OSDAPI_OSDWinOn(OSD_WINDOW2);

    //UserSetInputSource();
}
#endif
void OSDBFMenuITMUp(void)
{
    //UserData.ucBFMode =
    //    (UserData.ucBFMode+1)%NUMBER_CE_MODES;     

    if (GetOSDState() > OSD_CUSTKEY_PICTUREMODE_END){
        UserData.ucBFMode = GetOSDState() - OSD_ITEM_3_1_1_STATE;
    }
    else{
        UserData.ucBFMode = GetOSDState() - OSD_CUSTKEY_PICTUREMODE_1_STATE;
    }    
    UserSetBF();
    //SetOSDUpdUsrFlag();
}

void OSDBFMenuITMDn(void)
{
    //UserData.ucBFMode =
    //    (UserData.ucBFMode+NUMBER_CE_MODES-1)%NUMBER_CE_MODES;
    if (GetOSDState() > OSD_CUSTKEY_PICTUREMODE_END){
        UserData.ucBFMode = GetOSDState() - OSD_ITEM_3_1_1_STATE;
    }
    else{
        UserData.ucBFMode = GetOSDState() - OSD_CUSTKEY_PICTUREMODE_1_STATE;
    }
    UserSetBF();
    //SetOSDUpdUsrFlag();
}
#if 0
void OSDBFMenuITMConfirm(BOOL bconfirm)
{
//    if (bconfirm == FALSE) {
        UserData.ucBFMode = OSD_Select_Temp;
//        UserSetBF();
//    }
//    else{
//        OSD_Select_Temp = UserData.ucBFMode;
//    }
//    SetOSDUpdUsrFlag();
}

void OSDConfirmOSDRotation(void)
{
    OSDAPI_TurnOffOSD();
    UserSetOSDRotation();
    UserSetOSDH();
    UserSetOSDV();
    SetOSDUpdUsrFlag();
}

void OSDConfirmLanguage(void)
{
    UserSetLanguage();
    SetOSDUpdUsrFlag();
}
#endif

void OSDConfirmInputVGA(void)
{
        OSDBlinkTopPageButton(0);
        UserData.ucInputSource = INPUT_SC_VGA;
        OSDConfirmInput();
        OSDAPI_TurnOffOSD();                
        SetOSDUpdUsrFlag();
}

void OSDConfirmInputDVI(void)
{
        OSDBlinkTopPageButton(1);
        UserData.ucInputSource = INPUT_SC_DVI;
        OSDConfirmInput();
        OSDAPI_TurnOffOSD();                
        SetOSDUpdUsrFlag();    
}

void OSDConfirmInputHDMI(void)
{
        OSDBlinkTopPageButton(2);
        UserData.ucInputSource = INPUT_SC_HDMI;
        OSDConfirmInput();
        OSDAPI_TurnOffOSD();                
        SetOSDUpdUsrFlag();    
}

void OSDConfirmInputDP(void)
{
        OSDBlinkTopPageButton(3);
        UserData.ucInputSource = INPUT_SC_DP;
        OSDConfirmInput();
        OSDAPI_TurnOffOSD();                
        SetOSDUpdUsrFlag();
}

void OSDConfirmInput(void)
{
//    UCHAR Index;
    UCHAR tmp = SC_CHANNEL_INDEX;     
    bShowInputNovitceFlag = TRUE;
    SetSyncSource(&MDState[0].SyncState, UserData.bAutoSyncSource); 
    if (UserData.ucInputSource != UserGetInputSource()) {
        UCHAR ucSCIndex;    
        // Do not change the sequence of the following statements.
        ucSCIndex= ucSCIdx;
        SetScalerIndex(_MainChannel);
        RecordCurrentSource(FALSE);
        ucSCIdx = ucSCIndex;    
        ResetWDTimer();    
        {
            ODAPI_SetSeparateODTestPatternEnable(_MainChannel);    
        }    

#if (INPUT_INTERFACE&INPUT_DP0)
#if ENABLE_DP0_HPD == ON
        if (UserData.ucInputSource == INPUT_SC_DP) {    
            SYSAPI_PerformHPDOff(HPD_DP);
            //SetDPManualSourceHPDFlag();
        }
#endif
#endif     
#if (INPUT_INTERFACE&INPUT_DP1)
#if ENABLE_DP1_HPD == ON
        if (UserData.ucInputSource == INPUT_SC_DP) {    
            SYSAPI_PerformHPDOff(HPD_DP);
            //SetDPManualSourceHPDFlag();
        }
#endif
#endif   
        UserSetInputSource();
        SC_CHANNEL_INDEX &= 0x00; 
        SetModeChangeFlag();    
        SC_CHANNEL_INDEX =     tmp;    
        APPResendAppSync();
        SetOSDUpdUsrFlag();   
        Custom_System.bPreShowMsgSource = TRUE;
        PanelPowerOffSequence();        
    }
/*    
    else {
        if (GetOSDState() == OSD_DIRSRC_STATE) {
              if (APPIsOutOfLimit()) {// no modechange but out of range
                   OSDEnterOOL();
              }                
              else if (IsOutRangeState()) {// no modechange but out of range
                   OSDEnterOOR();
              }
              else if (IsNoCableState()){
                   OSDEnterNoCable();
              }
           else if (IsNoSyncState()) {                   
                   OSDEnterNoSync();
              }
        else{
                  OSDCloseAll();              
            }
        }
    }
*/
}


void OSDConfirmRecall(void)
{
#if !lrd_dis_benq
    pInputTiming = GetModeHandleInputTiming(_MainChannel);
#endif
	UserRecallConfiguration();
    SetOSDUpdUsrFlag();
#if !lrd_dis_benq
    if ((GetInputSyncMode() != DIG_SYNC) && (pInputTiming->ucAutoTune != 0)) {
#else
	if ((GetInputSyncMode() != DIG_SYNC) && (InputTiming.ucAutoTune != 0)) {
#endif
		SetOSDUpdTmgFlag();
    }
}

#if MD_ENABLE_FUNC_OSD == ON
void OSDConfirm3DCnvMode(void)
{
#if ENABLE_3D_CNV == ON
    UserSet2DTo3DMode();
#endif
    SetOSDUpdUsrFlag();
    SetModeChangeFlag();
}
#endif

//******************************************************************************
// Prototype:
//  void OSDShowSelectPageMainFrame(UCHAR Type)
// Parameters:
//  Type : indicate the Frame width type to set select page icon X position.
// Return:
//  None
// Purpose:
//  Draw select page all icons
// Notes:
//  None
//******************************************************************************
void OSDShowSelectPageMainFrame(UCHAR Type)
{
    UCHAR i, j;
    UCHAR Offset;

    ucMenuAction = Type;

    if (Type == FrameWidthType_MainMenu) {
        Offset = OSD_MAIN_WIDTH-7+1; // 7 is selected page width
    }
    else if (Type == FrameWidthType_CustomerMenu1) {
        Offset = OSD_CUSTOMERKEY_MENU1_WIDTH-7+1; // 7 is selected page width
    }
    else if (Type== FrameWidthType_CustomerMenu2) {
        Offset = OSD_CUSTOMERKEY_MENU2_WIDTH-7+1; // 7 is selected page width
    }
    else if (Type== FrameWidthType_DialogMenu1) {//ULEric140410
        Offset = OSD_DIALOG_SELECTPAGE_WIDTH-7+1; // 7 is selected page width
    }

    // Top
    OSDAPI_SetFontAttr(MAINMENU_COLOR1);
    OSDAPI_WriteXYChar(TRUE, Offset, 0, SP_LeftTopCorner);
    OSDAPI_WriteXYRepeatChar(TRUE, Offset+1, 0, 5, SP_TopRepeat);

    // Bottom
    OSDAPI_WriteXYChar(TRUE, Offset, 20, SP_LeftBottomCorner_1);
    OSDAPI_WriteXYChar(TRUE, Offset, 21, SP_LeftBottomCorner_2);
    OSDAPI_WriteXYRepeatChar(TRUE, Offset+1, 21, 5, SP_BottomRepeat);

    // LeftSide Repeat
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            OSDAPI_WriteXYChar(TRUE, Offset, 1+i*4+j, SP_LeftSideRepeat);
        }
    }
    for (i=0; i<4; i++)
        OSDAPI_WriteXYChar(TRUE, Offset, 13+i, SP_LeftSideRepeat);
    for (i=0; i<2; i++)
        OSDAPI_WriteXYChar(TRUE, Offset, 18+i, SP_LeftSideRepeat);

    // 1thIcon cross
    OSDAPI_SetFontAttr(SELECTPAGE_4BIT_COLOR1);
    OSDAPI_WriteXYChar(TRUE, Offset, 4, SP_FirstIcon_LeftSideCross);
    OSDAPI_SetFontAttr(SELECTPAGE_2BIT_COLOR2);
    OSDAPI_WriteXYRepeatChar(TRUE, Offset+1, 4, 5, SP_FirstIcon_CrossRepeat);

    // 2thIcon cross
    OSDAPI_SetFontAttr(SELECTPAGE_4BIT_COLOR1);
    OSDAPI_WriteXYChar(TRUE, Offset, 8, SP_SecondIcon_LeftSideCross);
    OSDAPI_SetFontAttr(SELECTPAGE_2BIT_COLOR2);
    OSDAPI_WriteXYRepeatChar(TRUE, Offset+1, 8, 5, SP_SecondIcon_CrossRepeat);

    // 3thIcon cross
    OSDAPI_SetFontAttr(SELECTPAGE_2BIT_COLOR1);
    OSDAPI_WriteXYChar(TRUE, Offset, 12, SP_3thIcon_LeftSideCross);
    OSDAPI_SetFontAttr(SELECTPAGE_2BIT_COLOR2);
    OSDAPI_WriteXYRepeatChar(TRUE, Offset+1, 12, 5, SP_3thIcon_CrossRepeat);

    // 4thIcon cross
    OSDAPI_SetFontAttr(SELECTPAGE_2BIT_COLOR1);
    OSDAPI_WriteXYChar(TRUE, Offset, 17, SP_4thIcon_LeftSideCross);
    OSDAPI_SetFontAttr(SELECTPAGE_2BIT_COLOR2);
    OSDAPI_WriteXYRepeatChar(TRUE, Offset+1, 17, 5, SP_4thIcon_CrossRepeat);

    // inside icon 1bit part
    OSDAPI_SetFontAttr(MAINMENU_COLOR2);
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            OSDAPI_WriteXYRepeatChar(TRUE, Offset+1, 1+i*4+j, 5, _SPACE_);
        }
    }
    for (j=0; j<4; j++) {
            OSDAPI_WriteXYRepeatChar(TRUE, Offset+1, 13+j, 5, _SPACE_);
    }
    for (j=0; j<3; j++) {
            OSDAPI_WriteXYRepeatChar(TRUE, Offset+1, 18+j, 5, _SPACE_);
    }

    // clear bottom
    OSDAPI_SetFontAttr(CLEAR_SELECTEDPAGE_BOTTOM_COLOR);
    OSDAPI_WriteXYRepeatChar(TRUE, Offset, 22, 6, _SPACE_);
}

//******************************************************************************
// Prototype:
//  void OSDBlinkSelectPageButton(UCHAR id, UCHAR act, BOOL Clr)
// Parameters:
//  Type :
// Return:
//  None
// Purpose:
//  Blinnk the pressed button of selectPage.
// Notes:
//  None
//******************************************************************************
void OSDBlinkSelectPageButton(UCHAR id, UCHAR act, BOOL Clr)
{
    UCHAR i;
    UCHAR Offset;

    Clr = Clr;

     if(!Clr)//ULEric140409
    {
            if(ucKeyInfoStatus!= 0xff)
                return;
            ucKeyInfoStatus = (act<<4|id);
        //printf("ucKeyInfoStatus = %BX\r\n",ucKeyInfoStatus);
        //return;
    }    

    if (act == FrameWidthType_MainMenu) {
        Offset = OSD_MAIN_WIDTH-7+1; // 7 is selected page width
    }
    else if (act == FrameWidthType_CustomerMenu1) {
        Offset = OSD_CUSTOMERKEY_MENU1_WIDTH-7+1; // 7 is selected page width
    }
    else if (act== FrameWidthType_CustomerMenu2) {
        Offset = OSD_CUSTOMERKEY_MENU2_WIDTH-7+1; // 7 is selected page width
    }
    else if (act== FrameWidthType_DialogMenu1) {//ULEric140410
        Offset = OSD_DIALOG_SELECTPAGE_WIDTH-7+1; // 7 is selected page width
    }    
    
    if(id == 0)
        id = 3;        
    else if(id == 1)
        id = 2;        
    else if(id == 2)
        id = 0;        
    else if(id == 3)     
        id = 1;        

    if(OSDCheckNonBlinkItem(id,Clr))//ULEric140409
    return;        
    Sleep(10);
    WaitDisVSync();
    switch (id) {
        case 0:
            if (Clr) {        //Up
                OSDAPI_FillLineAttr(Offset, 0, 6, MAINMENU_COLOR1);
                for (i=0; i<3; i++) {
                    if (i == 1 || i == 2) {
                        OSDAPI_FillLineAttr(Offset, 1+i, 1, SELECTPAGE_2BIT_COLOR1);
                        OSDAPI_FillLineAttr(Offset+1, 1+i, 5, SELECTPAGE_1BIT_COLOR1_WHITE);
                    }
                    else {
                        OSDAPI_FillLineAttr(Offset, 1+i, 1, SELECTPAGE_2BIT_COLOR1);
                        OSDAPI_FillLineAttr(Offset+1, 1+i, 5, SELECTPAGE_1BIT_COLOR1);
                    }
                }
                OSDAPI_FillLineAttr(Offset, 4, 1, SELECTPAGE_4BIT_COLOR1);
                OSDAPI_FillLineAttr(Offset+1, 4, 5, SELECTPAGE_2BIT_COLOR3);
            }
            else {
                OSDAPI_FillLineAttr(Offset, 0, 6, SELECTPAGE_2BIT_COLOR1_BLUE);
                for (i=0; i<3; i++) {
                    if (i == 1 || i == 2) {
                        OSDAPI_FillLineAttr(Offset, 1+i, 1, SELECTPAGE_2BIT_COLOR1_BLUE);
                        OSDAPI_FillLineAttr(Offset+1, 1+i, 5, SELECTPAGE_1BIT_COLOR1_BLACK);
                    }
                    else {
                        OSDAPI_FillLineAttr(Offset, 1+i, 1, SELECTPAGE_2BIT_COLOR1_BLUE);
                        OSDAPI_FillLineAttr(Offset+1, 1+i, 5, SELECTPAGE_1BIT_COLOR1_BLUE);
                    }
                }
                OSDAPI_FillLineAttr(Offset, 4, 1, SELECTPAGE_4BIT_COLOR_BLUE_UPPER);
                OSDAPI_FillLineAttr(Offset+1, 4, 5, SELECTPAGE_2BIT_COLOR4);
            }
        break;
        
        
        case 1:            //Down

            if (Clr) {
                OSDAPI_FillLineAttr(Offset, 4, 1, SELECTPAGE_4BIT_COLOR1);
                OSDAPI_FillLineAttr(Offset+1, 4, 5, SELECTPAGE_2BIT_COLOR3);
                for (i=0; i<3; i++) {
                    if (i ==1 || i == 2) {
                        OSDAPI_FillLineAttr(Offset, 5+i, 1, SELECTPAGE_2BIT_COLOR1);
                        OSDAPI_FillLineAttr(Offset+1, 5+i, 5, SELECTPAGE_1BIT_COLOR1_WHITE);
                    }
                    else {
                        OSDAPI_FillLineAttr(Offset, 5+i, 1, SELECTPAGE_2BIT_COLOR1);
                        OSDAPI_FillLineAttr(Offset+1, 5+i, 5, SELECTPAGE_1BIT_COLOR1);
                    }
                }
                OSDAPI_FillLineAttr(Offset, 8, 1, SELECTPAGE_4BIT_COLOR1);
                OSDAPI_FillLineAttr(Offset+1, 8, 5, SELECTPAGE_2BIT_COLOR3);
            }
            else {
                OSDAPI_FillLineAttr(Offset, 4, 1, SELECTPAGE_4BIT_COLOR_BLUE_LOWER);
                OSDAPI_FillLineAttr(Offset+1, 4, 5, SELECTPAGE_2BIT_COLOR5);
                for (i=0; i<3; i++) {
                    if (i ==1 || i == 2) {
                        OSDAPI_FillLineAttr(Offset, 5+i, 1, SELECTPAGE_2BIT_COLOR1_BLUE);
                        OSDAPI_FillLineAttr(Offset+1, 5+i, 5, SELECTPAGE_1BIT_COLOR1_BLACK);
                    }
                    else {
                        OSDAPI_FillLineAttr(Offset, 5+i, 1, SELECTPAGE_2BIT_COLOR1_BLUE);
                        OSDAPI_FillLineAttr(Offset+1, 5+i, 5, SELECTPAGE_1BIT_COLOR1_BLUE);
                    }
                }
                OSDAPI_FillLineAttr(Offset, 8, 1, SELECTPAGE_4BIT_COLOR_BLUE_UPPER);
                OSDAPI_FillLineAttr(Offset+1, 8, 5, SELECTPAGE_2BIT_COLOR4);
            }
        break;
        
        
        case 2:            //right

            if (Clr) {
                OSDAPI_FillLineAttr(Offset, id*4, 1, SELECTPAGE_4BIT_COLOR1);
                OSDAPI_FillLineAttr(Offset+1, id*4, 5, SELECTPAGE_2BIT_COLOR3);
                for (i=0; i<3; i++) {
                    if (i ==1 || i == 2) {
                        OSDAPI_FillLineAttr(Offset, id*4+1+i, 1, SELECTPAGE_2BIT_COLOR1);
               if(OSDCheckHookIcon())//ULEric140327
                   OSDAPI_FillLineAttr(Offset+1, id*4+1+i, 5,  TOPPAGEICON_1BIT_HOOK_COLOR);
               else
                        OSDAPI_FillLineAttr(Offset+1, id*4+1+i, 5, SELECTPAGE_1BIT_COLOR1_WHITE);
                    }
                    else {
                        OSDAPI_FillLineAttr(Offset, id*4+1+i, 1, SELECTPAGE_2BIT_COLOR1);
                        OSDAPI_FillLineAttr(Offset+1, id*4+1+i, 5, SELECTPAGE_1BIT_COLOR1);
                    }
                }
                OSDAPI_FillLineAttr(Offset, (id+1)*4, 1, SELECTPAGE_2BIT_COLOR1);
                OSDAPI_FillLineAttr(Offset+1, (id+1)*4, 5, SELECTPAGE_2BIT_COLOR3);
            }
            else {
                OSDAPI_FillLineAttr(Offset, id*4, 1, SELECTPAGE_4BIT_COLOR_BLUE_LOWER);
                OSDAPI_FillLineAttr(Offset+1, id*4, 5, SELECTPAGE_2BIT_COLOR5);
                for (i=0; i<3; i++) {
                    if (i ==1 || i == 2) {
                        OSDAPI_FillLineAttr(Offset, id*4+1+i, 1, SELECTPAGE_2BIT_COLOR1_BLUE);
                        OSDAPI_FillLineAttr(Offset+1, id*4+1+i, 5, SELECTPAGE_1BIT_COLOR1_BLACK);
                    }
                    else {
                        OSDAPI_FillLineAttr(Offset, id*4+1+i, 1, SELECTPAGE_2BIT_COLOR1_BLUE);
                        OSDAPI_FillLineAttr(Offset+1, id*4+1+i, 5, SELECTPAGE_1BIT_COLOR1_BLUE);
                    }
                }
                OSDAPI_FillLineAttr(Offset, (id+1)*4, 1, SELECTPAGE_2BIT_COLOR1_BLUE);
                OSDAPI_FillLineAttr(Offset+1, (id+1)*4, 5, SELECTPAGE_2BIT_COLOR5);
            }
        break;
            
            
        case 3:        //Left
            if (Clr) {
                for (i=0; i<4; i++) {
                    if (i == 1 || i == 2) {
                        OSDAPI_FillLineAttr(Offset, id*4+1+i, 1, MAINMENU_COLOR1);
                        OSDAPI_FillLineAttr(Offset+1, id*4+1+i, 5, SELECTPAGE_1BIT_COLOR1_WHITE);
                    }
                    else {
                        OSDAPI_FillLineAttr(Offset, id*4+1+i, 1, MAINMENU_COLOR1);
                        OSDAPI_FillLineAttr(Offset+1, id*4+1+i, 5, MAINMENU_COLOR2);
                    }
                }
            }
            else  {
                for (i=0; i<4; i++) {
                    if (i == 1 || i == 2) {
                        OSDAPI_FillLineAttr(Offset, id*4+1+i, 1, SELECTPAGE_2BIT_COLOR1_BLUE);
                        OSDAPI_FillLineAttr(Offset+1, id*4+1+i, 5, SELECTPAGE_1BIT_COLOR1_BLACK);
                    }
                    else {
                        OSDAPI_FillLineAttr(Offset, id*4+1+i, 1, SELECTPAGE_2BIT_COLOR1_BLUE);
                        OSDAPI_FillLineAttr(Offset+1, id*4+1+i, 5, SELECTPAGE_1BIT_COLOR1_BLUE);
                    }
                }
            }
        break;
        
           
        case 4:        //exit
            if (Clr) {
                OSDAPI_FillLineAttr(Offset, id*4+1, 1, MAINMENU_COLOR1);
                OSDAPI_FillLineAttr(Offset+1, id*4+1, 5, SELECTPAGE_2BIT_COLOR4);

                for (i=0; i<2; i++) {
                    OSDAPI_FillLineAttr(Offset, id*4+2+i, 1, MAINMENU_COLOR1);
                    OSDAPI_FillLineAttr(Offset+1, id*4+2+i, 5, TOPPAGEICON_1BIT_EXIT_COLOR);
                }
                OSDAPI_FillLineAttr(Offset, id*4+4, 1, MAINMENU_COLOR1);
                OSDAPI_FillLineAttr(Offset+1, id*4+4, 5, SELECTPAGE_1BIT_COLOR1);

                OSDAPI_FillLineAttr(Offset, id*4+5, 6, SELECTPAGE_2BIT_COLOR1_BLUE);
            }
            else  {
                OSDAPI_FillLineAttr(Offset, id*4+1, 1, SELECTPAGE_2BIT_COLOR1_BLUE);
                OSDAPI_FillLineAttr(Offset+1, id*4+1, 5, SELECTPAGE_2BIT_COLOR5);

                for (i=0; i<2; i++) {
                    OSDAPI_FillLineAttr(Offset, id*4+2+i, 1, SELECTPAGE_2BIT_COLOR1_BLUE);
                    OSDAPI_FillLineAttr(Offset+1, id*4+2+i, 5, TOPPAGEICON_1BIT_EXIT_COLOR2);
                }
                OSDAPI_FillLineAttr(Offset, id*4+4, 1, SELECTPAGE_2BIT_COLOR1_BLUE);
                OSDAPI_FillLineAttr(Offset+1, id*4+4, 5, SELECTPAGE_1BIT_COLOR1_BLUE);

                OSDAPI_FillLineAttr(Offset, id*4+5, 6, SELECTPAGE_2BIT_COLOR1_BLUE);
            }
        break;
    }
}

//******************************************************************************
// Prototype:
//  void OSDBlinkTopPageButton(UCHAR id)
// Parameters:
//  id       : indicate which toppage menu button to blink
// Return:
//  None
// Purpose:
//  Blinnk the pressed button of TopPage.
// Notes:
//  None
//******************************************************************************
void OSDBlinkTopPageButton(UCHAR id)
{
    UCHAR i;

    switch (id) {
        case 0:
            OSDAPI_FillLineAttr(0, id*4, OSD_TOPPAGE_WIDTH, TOPPAGE_2BIT_COLOR1_BLUE);
            for (i=0; i<3; i++) {
                OSDAPI_FillLineAttr(0, id*4+1, 1, TOPPAGE_2BIT_COLOR3_BLUE); OSDAPI_FillLineAttr(1, id*4+1, OSD_TOPPAGE_WIDTH-1, TOPPAGE_1BIT_COLOR1_BLUE);
                OSDAPI_FillLineAttr(0, id*4+2, 1, TOPPAGE_2BIT_COLOR3_BLUE); OSDAPI_FillLineAttr(1, id*4+2, OSD_TOPPAGE_WIDTH-1, TOPPAGE_1BIT_COLOR1_BLUE);
                OSDAPI_FillLineAttr(0, id*4+3, 1, TOPPAGE_2BIT_COLOR3_BLUE); OSDAPI_FillLineAttr(1, id*4+3, OSD_TOPPAGE_WIDTH-1, TOPPAGE_1BIT_COLOR1_BLUE);
            }
            OSDAPI_FillLineAttr(0, id*4+4, OSD_TOPPAGE_WIDTH, TOPPAGE_2BIT_CROSS_COLOR1_BLUE);
        break;

        case 1:
        case 2:
        case 3:
            OSDAPI_FillLineAttr(0, id*4, OSD_TOPPAGE_WIDTH, TOPPAGE_2BIT_CROSS_COLOR2_BLUE);
            for (i=0; i<3; i++) {
                OSDAPI_FillLineAttr(0, id*4+1, 1, TOPPAGE_2BIT_COLOR3_BLUE); OSDAPI_FillLineAttr(1, id*4+1, OSD_TOPPAGE_WIDTH-1, TOPPAGE_1BIT_COLOR1_BLUE);
                OSDAPI_FillLineAttr(0, id*4+2, 1, TOPPAGE_2BIT_COLOR3_BLUE); OSDAPI_FillLineAttr(1, id*4+2, OSD_TOPPAGE_WIDTH-1, TOPPAGE_1BIT_COLOR1_BLUE);
                OSDAPI_FillLineAttr(0, id*4+3, 1, TOPPAGE_2BIT_COLOR3_BLUE); OSDAPI_FillLineAttr(1, id*4+3, OSD_TOPPAGE_WIDTH-1, TOPPAGE_1BIT_COLOR1_BLUE);
            }
            OSDAPI_FillLineAttr(0, id*4+4, OSD_TOPPAGE_WIDTH, TOPPAGE_2BIT_CROSS_COLOR1_BLUE);
        break;

        case 4:
            OSDAPI_FillLineAttr(0, id*4, OSD_TOPPAGE_WIDTH, TOPPAGE_2BIT_CROSS_COLOR2_BLUE);
            for (i=0; i<3; i++) {
                OSDAPI_FillLineAttr(0, id*4+1, 1, TOPPAGE_2BIT_COLOR3_BLUE); OSDAPI_FillLineAttr(1, id*4+1, OSD_TOPPAGE_WIDTH-1, TOPPAGE_1BIT_COLOR1_BLUE);
                OSDAPI_FillLineAttr(0, id*4+2, 1, TOPPAGE_2BIT_COLOR3_BLUE); OSDAPI_FillLineAttr(1, id*4+2, OSD_TOPPAGE_WIDTH-1, TOPPAGE_1BIT_COLOR1_BLUE);
                OSDAPI_FillLineAttr(0, id*4+3, 1, TOPPAGE_2BIT_COLOR3_BLUE); OSDAPI_FillLineAttr(1, id*4+3, OSD_TOPPAGE_WIDTH-1, TOPPAGE_1BIT_COLOR1_BLUE);
            }
            OSDAPI_FillLineAttr(0, id*4+4, OSD_TOPPAGE_WIDTH, TOPPAGE_2BIT_COLOR1_BLUE);
        break;
    }
    Sleep(100);
}

void OSDShowNoticeIcon()
{
    UCHAR i;

    code UCHAR PosInfo[] = {
    2,2,
    3,2,
    4,2,

    2,3,
    3,3,
    4,3,
    5,3,

    2,4,
    3,4,
    4,4
    };

    OSDAPI_SetFontAttr(NoticeIconColor);
    for (i=0; i<10; i++)
        OSDAPI_WriteXYChar(TRUE, PosInfo[i*2], PosInfo[i*2+1], Notice_Icon_1Bit_start+i);
}

void OSDShowInputIcon()
{
    UCHAR i,j;
    OSDAPI_SetFontAttr(NoticeIconColor);
    for (i=0; i<3; i++){
        for (j=0; j<4; j++){
        OSDAPI_WriteXYChar(TRUE, 2+j, 2+i, TP_1Bit_Start+i*4+j);
        }
    }    
}

void OSDShowAutoIcon(void)
{
    UCHAR i,j;
    OSDAPI_SetFontAttr(NoticeIconColor);    
    for (i=0; i<3; i++){
        for (j=0; j<4; j++){
        OSDAPI_WriteXYChar(TRUE, 2+j, 2+i, TP_1Bit_Auto_Start+i*4+j);
        }
    }
}
//******************************************************************************
// Prototype:
//  void OSDShowBenQMainFrame(UCHAR Type)
// Parameters:
//  Type : indicate the Frame width type to set X end position of main frame.
// Return:
//  None
// Purpose:
//  Show main menu frame
// Notes:
//  None
//******************************************************************************
void OSDShowBenQMainFrame(UCHAR Type)
{
    UCHAR i;
    UCHAR XPos;

    if (Type == FrameWidthType_MainMenu) {
        XPos = OSD_MAIN_WIDTH-7-1;
    }
    else if (Type == FrameWidthType_CustomerMenu1) {
        XPos = OSD_CUSTOMERKEY_MENU1_WIDTH-7-1;
    }
    else {
        XPos = OSD_CUSTOMERKEY_MENU2_WIDTH-7-1;
    }

    // LINE 0
    OSDAPI_SetFontAttr(MAINMENU_COLOR1);
    OSDAPI_WriteXYChar(TRUE, 0, 0, MB_LeftTopCorner);
    OSDAPI_WriteXYRepeatChar(TRUE, 1, 0, XPos-1, MB_TopRepeat);
    OSDAPI_WriteXYChar(TRUE, XPos, 0, MB_RightTopCorner);

    // LINE1
    OSDAPI_WriteXYChar(TRUE, 0, 1, MB_LeftSide_1);
    OSDAPI_WriteXYChar(TRUE, XPos, 1, MB_RightSide_1);
    OSDAPI_SetFontAttr(MAINMENU_COLOR2);
    OSDAPI_WriteXYRepeatChar(TRUE, 1, 1, XPos-1, _SPACE_);

    // LINE2
    OSDAPI_SetFontAttr(MAINMENU_COLOR3);
    OSDAPI_WriteXYChar(TRUE, 0, 2, MB_TitleCrossLeft_1);
    OSDAPI_WriteXYRepeatChar(TRUE, 1, 2, XPos-1, MB_TitleCrossRepeat_1);
    OSDAPI_WriteXYChar(TRUE, XPos, 2, MB_TitleCrossRight_1);

    // Left side and Right side
    for (i=0; i<18; i++) {
        OSDAPI_WriteXYChar(TRUE, 0, 3+i, MB_LeftSide_2);
        OSDAPI_WriteXYChar(TRUE, XPos, 3+i, MB_RightSide_2);
    }

    // Bottom
    OSDAPI_SetFontAttr(MAINMENU_COLOR3);
    OSDAPI_WriteXYChar(TRUE, 0, 21, MB_LeftBottomCorner_1);
    OSDAPI_WriteXYChar(TRUE, XPos, 21, MB_RightBottomCorner_1);
    OSDAPI_SetFontAttr(MAINMENU_COLOR1);
    OSDAPI_WriteXYChar(TRUE, 0, 22, MB_LeftBottomCorner_2);
    OSDAPI_WriteXYRepeatChar(TRUE, 1, 22, XPos-1, MB_BottomRepeat);
    OSDAPI_WriteXYChar(TRUE, XPos, 22, MB_RightBottomCorner_2);

    // select page and main menu separator
    OSDAPI_SetFontAttr(MAINMENU_AND_SELECTPAGE_SEPARATOR);
    for (i=0; i<23; i++) {
        OSDAPI_WriteXYChar(TRUE, XPos+1, i, _SPACE_);
    }
}

//******************************************************************************
// Prototype:
//  void OSDShowTopPageMainFrame()
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Show toppage menu frame
// Notes:
//  None
//******************************************************************************
void OSDShowTopPageMainFrame()
{
    UCHAR i, j;

    // Left Upper corner and Left Lower corner
    OSDAPI_SetFontAttr(TOPPAGE_2BIT_COLOR1);
    OSDAPI_WriteXYChar(TRUE, 0, 0, TP_UpperLeft_Corner);
    OSDAPI_WriteXYChar(TRUE, 0, 20, TP_LowerLeft_Corner);

    // Upper and Lower repeat
    OSDAPI_WriteXYRepeatChar(TRUE, 1, 0, (OSD_TOPPAGE_WIDTH-1), TP_UpperRepeat);
    OSDAPI_WriteXYRepeatChar(TRUE, 1, 20, (OSD_TOPPAGE_WIDTH-1), TP_LowerRepeat);

    // Left Repeat
    OSDAPI_SetFontAttr(TOPPAGE_2BIT_COLOR2);
    for (i=0; i<5; i++) {
        for (j=0; j<3; j++) {
            OSDAPI_WriteXYChar(TRUE, 0, 1+i*4+j, TP_LeftRepeat);
        }
    }

    OSDAPI_SetFontAttr(TOPPAGE_2BIT_COLOR3);
    for (j=0; j<4; j++) {
        // Left Cross
        OSDAPI_WriteXYChar(TRUE, 0, 4+4*j, TP_LeftCross);

        // Cross Repeat
        OSDAPI_WriteXYRepeatChar(TRUE, 1, 4+4*j, (OSD_TOPPAGE_WIDTH-1), TP_CrossRepeat);
    }
}

//******************************************************************************
// Prototype:
//  void OSDShowDialogFrame()
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Show dialog frame
// Notes:
//  None
//******************************************************************************
void OSDShowDialogFrame(UCHAR osdw, UCHAR osdh)
{
    UCHAR i, xe, ye;
    xe = osdw -1;
    ye = osdh -1;    
    // Four corner
    OSDAPI_SetFontAttr(TOPPAGE_2BIT_COLOR1);
    OSDAPI_WriteXYChar(TRUE, 0, 0, DI_2Bit_LeftTopCorner);
    OSDAPI_WriteXYChar(TRUE, xe, 0, DI_2Bit_RightTopCorner);
    OSDAPI_WriteXYChar(TRUE, 0, ye, DI_2Bit_LeftBottomCorner);
    OSDAPI_WriteXYChar(TRUE, xe, ye, DI_2Bit_RightBottomCorner);

    OSDAPI_WriteXYRepeatChar(TRUE, 1, 0, (xe -1), DI_2Bit_TopRepeat);
    OSDAPI_WriteXYRepeatChar(TRUE, 1, ye, (xe -1), DI_2Bit_BottomRepeat);

    OSDAPI_SetFontAttr(DIALOG_FRAME_COLOR);
    // Four corner 2
    OSDAPI_WriteXYChar(TRUE, 0, 1, DI_2Bit_LeftSideUp);
    OSDAPI_WriteXYChar(TRUE, xe, 1, DI_2Bit_RightSideUp);
    OSDAPI_WriteXYChar(TRUE, 0, (ye -1), DI_2Bit_LeftSideDown);
    OSDAPI_WriteXYChar(TRUE, xe, (ye -1), DI_2Bit_RightSideDown);

    // Left and Right Repeat
    for (i=0; i<(ye -3); i++) {
        OSDAPI_WriteXYChar(TRUE, 0, 2+i, DI_2Bit_LeftSideRepeat);
        OSDAPI_WriteXYChar(TRUE, xe, 2+i, DI_2Bit_RightSideRepeat);
    }
}

//******************************************************************************
// Prototype:
//  void OSDShowTrianIcon(UCHAR ucMethod, UCHAR id, UCHAR SeparaterLine)
// Parameters:
//  ucMethod  : Choose the triangle font u want to show correctly.
//  id :  Choose the current selected item id.
// SeparaterLine: Choose the separater line u want to show the icon.
// Return:
//  None
// Purpose:
//  Draw the BenQ triangle icon on separater line at correct position with correct fonts.
// Notes:
//  None
//******************************************************************************
void OSDShowTrianIcon(UCHAR ucMethod, UCHAR id, UCHAR Layer)
{
        UCHAR i, TmpID;

        UCHAR scTriangleIconPosTab[] = {
        // First triangle icon x start position of each layer.
        18, 4,
        17, 5,
        18, 5,
        18, 6
        };

        UCHAR scTriangleIcon_DialogPosTab[] = {
        // First triangle icon x start position of dialog layer.
        7, 4,
        6, 5,
        7, 5,
        7, 6
        };

        USHRT DialogTriangleIcon1_AttrTab[] = {
            DialogTriangleColor1, DialogTriangleColor1, DialogTriangleColor2, DialogTriangleColor3, DialogTriangleColor1
        };

        UCHAR DialogTriangleIcon1_IndexTab[] = {
            Dialog_Triangle_Icon1_2Bit_1, Dialog_Triangle_Icon1_2Bit_2, Dialog_Triangle_Icon1_1Bit_1,
            Dialog_Triangle_Icon1_1Bit_2, Dialog_Triangle_Icon1_2Bit_3
        };

        #define Line0_Offset    0
        #define Line1_Offset    14
        #define Line2_Offset    28

        switch (Layer) {
            case STRING_LAYER_3:
                TmpID = (IsPage2 == TRUE? (ucSubMenuType-8):ucSubMenuType);
            break;

            case STRING_LAYER_4:
                TmpID = (ucLayer3MenuType > 7? (ucLayer3MenuType-8):ucLayer3MenuType);
            break;

            case DIALOG_LAYER:
                TmpID = id;
            break;
        }

        switch (ucMethod) {
            case TRIANGLE_METHOD1:
            // triangle method 1
                OSDAPI_SetFontAttr(TRIANLE_ICON1_COLOR);
                if (Layer == STRING_LAYER_2) {
                    for (i=0; i<4; i++)
                        OSDAPI_WriteXYChar(TRUE, scTriangleIconPosTab[i*2]+Line0_Offset, scTriangleIconPosTab[i*2+1]+ucMenuType*2, Triangle_Icon1_1+i);
                }
                else if (Layer == STRING_LAYER_3) {
                    for (i=0; i<4; i++)
                        OSDAPI_WriteXYChar(TRUE, scTriangleIconPosTab[i*2]+Line1_Offset, scTriangleIconPosTab[i*2+1]+TmpID*2, Triangle_Icon1_1+i);
                }
                else if (Layer == STRING_LAYER_4)  {
                    for (i=0; i<4; i++)
                        OSDAPI_WriteXYChar(TRUE, scTriangleIconPosTab[i*2]+Line2_Offset, scTriangleIconPosTab[i*2+1]+TmpID*2, Triangle_Icon1_1+i);
                }
                else {
                    for (i=0; i<4; i++) {
                        //OSDAPI_SetFontAttr(DialogTriangleIcon1_AttrTab[i]);
                        OSDAPI_WriteXYChar(TRUE, scTriangleIcon_DialogPosTab[i*2], scTriangleIcon_DialogPosTab[i*2+1]+TmpID*2, Triangle_Icon1_1+i);
                    }
                }
            break;

            case TRIANGLE_METHOD2: // method 2
            // triangle method 2
                OSDAPI_SetFontAttr(TRIANLE_ICON2_COLOR);
                if (Layer == STRING_LAYER_2) {
                    for (i=0; i<4; i++)
                        OSDAPI_WriteXYChar(TRUE, scTriangleIconPosTab[i*2]+Line0_Offset, scTriangleIconPosTab[i*2+1]+ucMenuType*2, Triangle_Icon2_1+i);
                }
                else if (Layer == STRING_LAYER_3) {
                    for (i=0; i<4; i++)
                        OSDAPI_WriteXYChar(TRUE, scTriangleIconPosTab[i*2]+Line1_Offset, scTriangleIconPosTab[i*2+1]+TmpID*2, Triangle_Icon2_1+i);
                }
                else if (Layer == STRING_LAYER_4) {
                    for (i=0; i<4; i++)
                        OSDAPI_WriteXYChar(TRUE, scTriangleIconPosTab[i*2]+Line2_Offset, scTriangleIconPosTab[i*2+1]+TmpID*2, Triangle_Icon2_1+i);
                }
                else {
                    for (i=0; i<4; i++)
                        OSDAPI_WriteXYChar(TRUE, scTriangleIcon_DialogPosTab[i*2], scTriangleIcon_DialogPosTab[i*2+1]+TmpID*2, Triangle_Icon2_1+i);
                }
            break;
            case TRIANGLE_METHOD3: // method 3
            // triangle method 3
                OSDAPI_SetFontAttr(TRIANLE_ICON3_COLOR);
                if (Layer == STRING_LAYER_2) {
                    for (i=0; i<4; i++)
                        OSDAPI_WriteXYChar(TRUE, scTriangleIconPosTab[i*2]+Line0_Offset, scTriangleIconPosTab[i*2+1]+ucMenuType*2, Triangle_Icon3_1+i);
                }
                else if (Layer == STRING_LAYER_3) {
                    for (i=0; i<4; i++)
                        OSDAPI_WriteXYChar(TRUE, scTriangleIconPosTab[i*2]+Line1_Offset, scTriangleIconPosTab[i*2+1]+TmpID*2, Triangle_Icon3_1+i);
                }
                else if (Layer == STRING_LAYER_4) {
                    for (i=0; i<4; i++)
                        OSDAPI_WriteXYChar(TRUE, scTriangleIconPosTab[i*2]+Line2_Offset, scTriangleIconPosTab[i*2+1]+TmpID*2, Triangle_Icon3_1+i);
                }
                else  {
                    for (i=0; i<5; i++)
                        OSDAPI_WriteXYChar(TRUE, scTriangleIcon_DialogPosTab[i*2], scTriangleIcon_DialogPosTab[i*2+1]+TmpID*2, Dialog_Triangle_Icon3_1Bit_1+i);
                }
            break;

            case TRIANGLE_CLEAR: // clear triangle font
                OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
                if (Layer == STRING_LAYER_2) {
                    for (i=0; i<4; i++)
                        OSDAPI_WriteXYChar(TRUE, scTriangleIconPosTab[i*2]+Line0_Offset, scTriangleIconPosTab[i*2+1]+ucMenuType*2, _SPACE_);
                }
                else if (Layer == STRING_LAYER_3) {
                    for (i=0; i<4; i++)
                        OSDAPI_WriteXYChar(TRUE, scTriangleIconPosTab[i*2]+Line1_Offset, scTriangleIconPosTab[i*2+1]+TmpID*2, _SPACE_);
                }
                else if (Layer == STRING_LAYER_4) {
                    for (i=0; i<4; i++)
                        OSDAPI_WriteXYChar(TRUE, scTriangleIconPosTab[i*2]+Line2_Offset, scTriangleIconPosTab[i*2+1]+TmpID*2, _SPACE_);
                }
                else  {
                    for (i=0; i<5; i++)
                        OSDAPI_WriteXYChar(TRUE, scTriangleIcon_DialogPosTab[i*2], scTriangleIcon_DialogPosTab[i*2+1]+TmpID*2, _SPACE_);
                }
                break;
        }
}

//******************************************************************************
// Prototype:
//  void OSDShowStringSeparater(UCHAR LayerNum, BOOL clr)
// Parameters:
//  LayerNum  : Indicate which Layer to show the string separaters.
//  clr :  If TRUE, clear the corresponding layer string separater, else draw it.
// Return:
//  None
// Purpose:
//  Show or clear corresponding layer string separaters.
// Notes:
//  None
//******************************************************************************
void OSDShowStringSeparater(UCHAR LayerNum, BOOL clr)
{
    UCHAR i;

    switch (LayerNum) {
        case STRING_LAYER_1:
            OSDAPI_SetFontAttr(StringSeparaterLineColor1);
            for (i=0; i<7; i++) {
                if (i == 2) {
                    OSDAPI_WriteXYChar(TRUE, 2, 6+i*2, StringSeparater_1);
                    OSDAPI_WriteXYRepeatChar(TRUE, 4, 6+i*2, 13, StringSeparater_1);
                }
                else if (i == 3) {
                    OSDAPI_WriteXYRepeatChar(TRUE, 3, 6+i*2, 14, StringSeparater_1);
                }
                else if (i >= 4) {
                    OSDAPI_WriteXYRepeatChar(TRUE, 2, 6+i*2, 15, StringSeparater_1);
                }
                else {
                    OSDAPI_WriteXYRepeatChar(TRUE, 5, 6+i*2, 12, StringSeparater_1);
                }
                OSDAPI_WriteXYChar(TRUE, 17, 6+i*2, StringSeparater_2);
            }
        break;

        case STRING_LAYER_2:
            OSDAPI_SetFontAttr(StringSeparaterLineColor1);
            for (i=0; i<7; i++) {
                OSDAPI_WriteXYRepeatChar(TRUE, 19, 6+i*2, 12, StringSeparater_1);
                OSDAPI_WriteXYChar(TRUE, 31, 6+i*2, StringSeparater_2);
            }
        break;

        case STRING_LAYER_3:
            if (clr) {
                OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
                for (i=0; i<7; i++) {
                    OSDAPI_WriteXYRepeatChar(TRUE, 33, 6+i*2, 13, _SPACE_);
                }
            }
            else {
                OSDAPI_SetFontAttr(StringSeparaterLineColor1);
                for (i=0; i<7; i++) {
                    OSDAPI_WriteXYRepeatChar(TRUE, 33, 6+i*2, 12, StringSeparater_1);
                    OSDAPI_WriteXYChar(TRUE, 45, 6+i*2, StringSeparater_2);
                }
            }
        break;
        case STRING_LAYER_4:
            if (clr) {
                OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
                for (i=0; i<7; i++) {
                    OSDAPI_WriteXYRepeatChar(TRUE, 47, 6+i*2, 13, _SPACE_);
                }
            }
            else {
                OSDAPI_SetFontAttr(StringSeparaterLineColor1);
                for (i=0; i<7; i++) {
                    OSDAPI_WriteXYRepeatChar(TRUE, 47, 6+i*2, 12, StringSeparater_1);
                    OSDAPI_WriteXYChar(TRUE, 59, 6+i*2, StringSeparater_2);
                }
            }
        break;
        case DIALOG_LAYER:
            if (clr) {
                OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
                for (i=0; i<7; i++) {
                    OSDAPI_WriteXYRepeatChar(TRUE, 8, 6+i*2, 13, _SPACE_);
                }
            }
            else {
                OSDAPI_SetFontAttr(StringSeparaterLineColor1);
                for (i=0; i<7; i++) {
                    OSDAPI_WriteXYRepeatChar(TRUE, 8, 6+i*2, 13, StringSeparater_1);
                }
            }
        break;
        }
}

//******************************************************************************
// Prototype:
//  void OSDShowLayerSeparater(UCHAR SeparaterNum, UCHAR TrianglePos, BOOL Clr)
// Parameters:
//  SeparaterNum  : Indicate which Layer to show the Layer separaters.
//  TrianglePos :  current position of triangle font to show on layer separater.
//  Clr               : If TRUE, clear the Layer separater, else draw one.
// Return:
//  None
// Purpose:
//  Show layer separater and corresponding triangle font.
// Notes:
//  None
//******************************************************************************
void OSDShowLayerSeparater(UCHAR SeparaterNum, UCHAR TrianglePos, BOOL Clr)
{
    UCHAR i;

    OSDAPI_SetFontAttr(LayerSeparatorColor);
    switch (SeparaterNum) {
        case STRING_LAYER_2:
            if (Clr) {
                OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
                for (i=0; i<19; i++)
                    OSDAPI_WriteXYChar(TRUE, 18, 3+i, _SPACE_);

                OSDShowTrianIcon(TRIANGLE_CLEAR, TrianglePos, STRING_LAYER_2);
            }
            else {
                // draw head
                OSDAPI_WriteXYChar(TRUE, 18, 3, Layer_Separator_Head);

                // draw tail
                OSDAPI_WriteXYChar(TRUE, 18, 21, Layer_Separator_Tail);

                 for (i=0; i<TrianglePos*2; i++) {
                    OSDAPI_WriteXYChar(TRUE, 18, 4+i, Layer_Separator_Mid);
                 }

                 for (i=0; i<2*(8-(TrianglePos+1)); i++) {
                    OSDAPI_WriteXYChar(TRUE, 18, 7+TrianglePos*2+i, Layer_Separator_Mid);
                 }

                OSDShowTrianIcon(TRIANGLE_METHOD3, TrianglePos, STRING_LAYER_2);
            }
        break;

        case STRING_LAYER_3:
            if (Clr) {
                OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
                for (i=0; i<19; i++)
                    OSDAPI_WriteXYChar(TRUE, 32, 3+i, _SPACE_);

                OSDShowTrianIcon(TRIANGLE_CLEAR, TrianglePos, STRING_LAYER_3);
            }
            else {
                // draw head
                OSDAPI_WriteXYChar(TRUE, 32, 3, Layer_Separator_Head);

                // draw tail
                OSDAPI_WriteXYChar(TRUE, 32, 21, Layer_Separator_Tail);

                 for (i=0; i<TrianglePos*2; i++) {
                    OSDAPI_WriteXYChar(TRUE, 32, 4+i, Layer_Separator_Mid);
                 }

                 for (i=0; i<2*(8-(TrianglePos+1)); i++) {
                    OSDAPI_WriteXYChar(TRUE, 32, 7+TrianglePos*2+i, Layer_Separator_Mid);
                 }
                OSDShowTrianIcon(TRIANGLE_METHOD3, TrianglePos, STRING_LAYER_3);
            }
        break;
    }
}



void OSDShowLayer3Item(UCHAR id)
{
    switch (ucMenuType) {
        case OSD_MAIN_DISPLAY:
            switch (id) {
                case OSD_DISPLAY_ADJUST:
                    break;
#if ENABLE_AUTO_POVIT_FUNC == ON                      
                case OSD_DISPLAY_PIVOT:
                    break;
#endif
                case OSD_DISPLAY_INPUT:
                    break;

                case OSD_DISPLAY_HPOS:
                    OSDShowHPos(FALSE, FALSE);
                    break;
                case OSD_DISPLAY_VPOS:
                    OSDShowVPos(FALSE, FALSE);
                    break;
                case OSD_DISPLAY_PIXELCLK:
                    OSDShowClock(FALSE, FALSE);
                    break;
                case OSD_DISPLAY_PHASE:
                    OSDShowPhase(FALSE, FALSE);
                    break;
                default:
                    break;
            }
        break;
        case OSD_MAIN_PICTURE:
            switch (id) {
                case OSD_PICTURE_BRIGHTNESS:
                    OSDShowBrightness(FALSE, FALSE);
                break;

                case OSD_PICTURE_CONTRAST:
                    OSDShowContrast(FALSE, FALSE);
                    break;

                case OSD_PICTURE_SHARPNESS:
                    OSDShowSharpness(FALSE, FALSE);
                    break;

                case OSD_PICTURE_HUE:
                    OSDShowHue(FALSE, FALSE);
                    break;

                case OSD_PICTURE_SATURATION:
                    OSDShowSaturation(FALSE, FALSE);
                    break;

                default:
                    break;
            }
        break;
     case OSD_MAIN_PICTURE_ADVANCED:
            switch (id) {
                case OSD_PICTURE_AD_DCR:
                    OSDShowDynamicContrast(FALSE);
                    break;

                default:
                    break;
            }
          break;
     case OSD_MAIN_AUDIO:
            switch (id) {
                case OSD_AUDIO_VOLUME:
                    OSDShowVolume(FALSE, FALSE);
              break;
                default:
                    break;
         }
         break;
     case OSD_MAIN_SYSTEM:
          break;
     case OSD_MAIN_ERGONOMICS:
          break; 
     default:
          break;
    }
}
//******************************************************************************
// Prototype:
//  void OSDShowBigWin(UCHAR ucLayer, UCHAR ucBoarder)
// Parameters:
//  ucLayer    : indicate which layer to show the big window.
//  ucBoarder : indicate the thickness of big window boarder.
// Return:
//  None
// Purpose:
// Show the big window on corresponding layer with specific boarder.
// Notes:
//  None
//******************************************************************************
void OSDShowBigWin(UCHAR ucLayer, UCHAR ucBoarder)
{
    OSDWinAttr attr;

    switch (ucLayer) {
        case OSD_LAYER1_WIN:
            // inner window
            OSDAPI_SelOSDWin(OSD_WINDOW3);
            RST_WINATTR_ALL(attr);
            attr.ucWinClr = I_TBLACK;
            OSDAPI_SetOSDWinAttr(attr);

            OSDAPI_SetOSDWinSize(usLayer1WinPosTab[0], usLayer1WinPosTab[1], usLayer1WinPosTab[2], usLayer1WinPosTab[3]);
            OSDAPI_OSDWinOn(OSD_WINDOW3);

            // outer window
            OSDAPI_SelOSDWin(OSD_WINDOW4);
            RST_WINATTR_ALL(attr);
            attr.ucWinClr = I_BENQ_BLUE_1;
            OSDAPI_SetOSDWinAttr(attr);

            OSDAPI_SetOSDWinSize(usLayer1WinPosTab[0]-ucBoarder, usLayer1WinPosTab[1]-ucBoarder, usLayer1WinPosTab[2]+ucBoarder, usLayer1WinPosTab[3]+ucBoarder);
            OSDAPI_OSDWinOn(OSD_WINDOW4);
        break;

        case OSD_LAYER2_WIN:
            // inner window
            OSDAPI_SelOSDWin(OSD_WINDOW3);
            RST_WINATTR_ALL(attr);
            attr.ucWinClr = I_TBLACK;
            OSDAPI_SetOSDWinAttr(attr);

            OSDAPI_SetOSDWinSize(usLayer2WinPosTab[0], usLayer2WinPosTab[1], usLayer2WinPosTab[2], usLayer2WinPosTab[3]);
            OSDAPI_OSDWinOn(OSD_WINDOW3);

            // outer window
            OSDAPI_SelOSDWin(OSD_WINDOW4);
            RST_WINATTR_ALL(attr);
            attr.ucWinClr = I_BENQ_BLUE_1;
            OSDAPI_SetOSDWinAttr(attr);

            OSDAPI_SetOSDWinSize(usLayer2WinPosTab[0]-ucBoarder, usLayer2WinPosTab[1]-ucBoarder, usLayer2WinPosTab[2]+ucBoarder, usLayer2WinPosTab[3]+ucBoarder);
            OSDAPI_OSDWinOn(OSD_WINDOW4);
        break;

        case OSD_LAYER3_WIN:
            // inner window
            OSDAPI_SelOSDWin(OSD_WINDOW3);
            RST_WINATTR_ALL(attr);
            attr.ucWinClr = I_TBLACK;
            OSDAPI_SetOSDWinAttr(attr);

            OSDAPI_SetOSDWinSize(usLayer3WinPosTab[0], usLayer3WinPosTab[1], usLayer3WinPosTab[2], usLayer3WinPosTab[3]);
            OSDAPI_OSDWinOn(OSD_WINDOW3);

            // outer window
            OSDAPI_SelOSDWin(OSD_WINDOW4);
            RST_WINATTR_ALL(attr);
            attr.ucWinClr = I_BENQ_BLUE_1;
            OSDAPI_SetOSDWinAttr(attr);

            OSDAPI_SetOSDWinSize(usLayer3WinPosTab[0]-ucBoarder, usLayer3WinPosTab[1]-ucBoarder, usLayer3WinPosTab[2]+ucBoarder, usLayer3WinPosTab[3]+ucBoarder);
            OSDAPI_OSDWinOn(OSD_WINDOW4);
        break;

        case OSD_LAYER4_WIN:
            // inner window
            OSDAPI_SelOSDWin(OSD_WINDOW3);
            RST_WINATTR_ALL(attr);
            attr.ucWinClr = I_TBLACK;
            OSDAPI_SetOSDWinAttr(attr);

            OSDAPI_SetOSDWinSize(usLayer4WinPosTab[0], usLayer4WinPosTab[1], usLayer4WinPosTab[2], usLayer4WinPosTab[3]);
            OSDAPI_OSDWinOn(OSD_WINDOW3);

            // outer window
            OSDAPI_SelOSDWin(OSD_WINDOW4);
            RST_WINATTR_ALL(attr);
            attr.ucWinClr = I_BENQ_BLUE_1;
            OSDAPI_SetOSDWinAttr(attr);

            OSDAPI_SetOSDWinSize(usLayer4WinPosTab[0]-ucBoarder, usLayer4WinPosTab[1]-ucBoarder, usLayer4WinPosTab[2]+ucBoarder, usLayer4WinPosTab[3]+ucBoarder);
            OSDAPI_OSDWinOn(OSD_WINDOW4);
        break;

        case OSD_DIALOG_LAYER_WIN:
            // inner window
            OSDAPI_SelOSDWin(OSD_WINDOW3);
            RST_WINATTR_ALL(attr);
            attr.ucWinClr = I_TBLACK;
            OSDAPI_SetOSDWinAttr(attr);

            OSDAPI_SetOSDWinSize(usDialogLayerWinPosTab[0], usDialogLayerWinPosTab[1], usDialogLayerWinPosTab[2], usDialogLayerWinPosTab[3]);
            OSDAPI_OSDWinOn(OSD_WINDOW3);

            // outer window
            OSDAPI_SelOSDWin(OSD_WINDOW4);
            RST_WINATTR_ALL(attr);
            attr.ucWinClr = I_BENQ_BLUE_1;
            OSDAPI_SetOSDWinAttr(attr);

            OSDAPI_SetOSDWinSize(usDialogLayerWinPosTab[0]-ucBoarder, usDialogLayerWinPosTab[1]-ucBoarder, usDialogLayerWinPosTab[2]+ucBoarder, usDialogLayerWinPosTab[3]+ucBoarder);
            OSDAPI_OSDWinOn(OSD_WINDOW4);

            // inner window
            OSDAPI_SelOSDWin(OSD_WINDOW5);
            RST_WINATTR_ALL(attr);
            attr.ucWinClr = I_BLACK;
            OSDAPI_SetOSDWinAttr(attr);
            OSDAPI_SetOSDWinSize(3, 49, 284, 398);
            OSDAPI_OSDWinOn(OSD_WINDOW5);
            
        break;

        case OSD_DIALOG2_LAYER_WIN:
            // inner window
            OSDAPI_SelOSDWin(OSD_WINDOW3);
            RST_WINATTR_ALL(attr);
            attr.ucWinClr = I_TBLACK;
            OSDAPI_SetOSDWinAttr(attr);

            OSDAPI_SetOSDWinSize(usDialog2LayerWinPosTab[0], usDialog2LayerWinPosTab[1], usDialog2LayerWinPosTab[2], usDialog2LayerWinPosTab[3]);
            OSDAPI_OSDWinOn(OSD_WINDOW3);

            // outer window
            OSDAPI_SelOSDWin(OSD_WINDOW4);
            RST_WINATTR_ALL(attr);
            attr.ucWinClr = I_BENQ_BLUE_1;
            OSDAPI_SetOSDWinAttr(attr);

            OSDAPI_SetOSDWinSize(usDialog2LayerWinPosTab[0]-ucBoarder, usDialog2LayerWinPosTab[1]-ucBoarder, usDialog2LayerWinPosTab[2]+ucBoarder, usDialog2LayerWinPosTab[3]+ucBoarder);
            OSDAPI_OSDWinOn(OSD_WINDOW4);

            // inner window
            OSDAPI_SelOSDWin(OSD_WINDOW5);
            RST_WINATTR_ALL(attr);
            attr.ucWinClr = I_BLACK;
            OSDAPI_SetOSDWinAttr(attr);
            OSDAPI_SetOSDWinSize(3, 49, 176, 398);
            OSDAPI_OSDWinOn(OSD_WINDOW5);
            
        break;

        case OSD_COLORTEMP_WIN:
            // inner window
            OSDAPI_SelOSDWin(OSD_WINDOW3);
            RST_WINATTR_ALL(attr);
            attr.ucWinClr = I_TBLACK;
            OSDAPI_SetOSDWinAttr(attr);

            OSDAPI_SetOSDWinSize(usClrTempWinPosTab[0], usClrTempWinPosTab[1], usClrTempWinPosTab[2], usClrTempWinPosTab[3]);
            OSDAPI_OSDWinOn(OSD_WINDOW3);

            // outer window
            OSDAPI_SelOSDWin(OSD_WINDOW4);
            RST_WINATTR_ALL(attr);
            attr.ucWinClr = I_BENQ_BLUE_1;
            OSDAPI_SetOSDWinAttr(attr);

            OSDAPI_SetOSDWinSize(usClrTempWinPosTab[0]-ucBoarder, usClrTempWinPosTab[1]-ucBoarder, usClrTempWinPosTab[2]+ucBoarder, usClrTempWinPosTab[3]+ucBoarder);
            OSDAPI_OSDWinOn(OSD_WINDOW4);
        break;
        case OSD_BG_WIN:
            // inner window
            OSDAPI_SelOSDWin(OSD_WINDOW5);
            RST_WINATTR_ALL(attr);
            attr.ucWinClr = I_BLACK;
            OSDAPI_SetOSDWinAttr(attr);
            OSDAPI_SetOSDWinSize(3, 49, 740, 398);
            OSDAPI_OSDWinOn(OSD_WINDOW5);
        break;
        case OSD_INFO_WIN:
            // inner window
            OSDAPI_SelOSDWin(OSD_WINDOW5);
            RST_WINATTR_ALL(attr);
            attr.ucWinClr = I_BLACK;
            OSDAPI_SetOSDWinAttr(attr);
            OSDAPI_SetOSDWinSize(3, 18, 360, 110);
            OSDAPI_OSDWinOn(OSD_WINDOW5);
        break;
        case OSD_OSDUNLOCKINFO_WIN:
            // inner window
            OSDAPI_SelOSDWin(OSD_WINDOW5);
            RST_WINATTR_ALL(attr);
            attr.ucWinClr = I_BLACK;
            OSDAPI_SetOSDWinAttr(attr);
            OSDAPI_SetOSDWinSize(3, 18, 555, 110);
            OSDAPI_OSDWinOn(OSD_WINDOW5);
        break;        
        default:
            // no such window index, error!!
        break;
    }
}
//******************************************************************************
// Prototype:
//  void OSDShowSmallWin(UCHAR id, UCHAR ucLayer)
// Parameters:
//  id        : current selected item id to show the small window.
// ucLayer: indicate which layer to show the small window.
// Return:
//  None
// Purpose:
// Show the small window on corresponding id.
// Notes:
//  None
//******************************************************************************
void OSDShowSmallWin(UCHAR id, UCHAR ucLayer)
{
    OSDWinAttr attr;

    switch (ucLayer) {
        case OSD_LAYER1_WIN:
            OSDAPI_SelOSDWin(OSD_WINDOW1);
            RST_WINATTR_ALL(attr);
            attr.ucWinClr = I_BENQ_BLUE_1;
            OSDAPI_SetOSDWinAttr(attr);

            OSDAPI_SetOSDWinSize(usLayer1WinPosTab[0], usLayer1WinPosTab[1]+15+id*37-id, usLayer1WinPosTab[2], usLayer1WinPosTab[1]+15+id*37-id+36);
            OSDAPI_OSDWinOn(OSD_WINDOW1);
        break;

        case OSD_LAYER2_WIN:
            OSDAPI_SelOSDWin(OSD_WINDOW1);
            RST_WINATTR_ALL(attr);
            attr.ucWinClr = I_BENQ_BLUE_1;
            OSDAPI_SetOSDWinAttr(attr);

            OSDAPI_SetOSDWinSize(usLayer2WinPosTab[0], usLayer2WinPosTab[1]+15+id*37-id, usLayer2WinPosTab[2], usLayer2WinPosTab[1]+15+id*37-id+36);
            OSDAPI_OSDWinOn(OSD_WINDOW1);
        break;

        case OSD_LAYER3_WIN:
            OSDAPI_SelOSDWin(OSD_WINDOW1);
            RST_WINATTR_ALL(attr);
            attr.ucWinClr = I_BENQ_BLUE_1;
            OSDAPI_SetOSDWinAttr(attr);

            OSDAPI_SetOSDWinSize(usLayer3WinPosTab[0], usLayer3WinPosTab[1]+15+id*37-id, usLayer3WinPosTab[2], usLayer3WinPosTab[1]+15+id*37-id+36);
            OSDAPI_OSDWinOn(OSD_WINDOW1);
        break;

        case OSD_LAYER4_WIN:
            OSDAPI_SelOSDWin(OSD_WINDOW1);
            RST_WINATTR_ALL(attr);
            attr.ucWinClr = I_BENQ_BLUE_1;
            OSDAPI_SetOSDWinAttr(attr);

            OSDAPI_SetOSDWinSize(usLayer4WinPosTab[0], usLayer4WinPosTab[1]+15+id*37-id, usLayer4WinPosTab[2], usLayer4WinPosTab[1]+15+id*37-id+36);
            OSDAPI_OSDWinOn(OSD_WINDOW1);
        break;
        case OSD_DIALOG_LAYER_WIN:
            OSDAPI_SelOSDWin(OSD_WINDOW1);
            RST_WINATTR_ALL(attr);
            attr.ucWinClr = I_BENQ_BLUE_1;
            OSDAPI_SetOSDWinAttr(attr);

            OSDAPI_SetOSDWinSize(usDialogLayerWinPosTab[0], usDialogLayerWinPosTab[1]+15+id*37-id, usDialogLayerWinPosTab[2], usDialogLayerWinPosTab[1]+15+id*37-id+36);
            OSDAPI_OSDWinOn(OSD_WINDOW1);
        break;
        default:
            // no such window index, error!!
        break;
    }
}


void OSDFocusSharpness(void)
{
    //OSDShowSliderBar(39, 18, 50);
    //OSDShowNum(39, 5, 50);
    OSDShowSharpness(TRUE, FALSE);    
}

void OSDFocusHue(void)
{
    OSDShowHue(TRUE, FALSE);
}

void OSDFocusSaturation(void)
{
    OSDShowSaturation(TRUE, FALSE);
}

void OSDFocusResetColor(void)
{
    SetOSDState(OSD_ITEM_2_8_1_STATE+1);
}

void OSDFocusAMA(void)
{
    //printf("focus AMA 0\n");

    SetOSDState(OSD_ITEM_2_9_1_STATE+ UserData.ucODMode);
}

void OSDFocusPicMode(void)
{
    //printf("OSDFocusPicMode: UserData.ucColorTemp = %d\n", (USHRT)UserData.ucBFMode);
    Custom_System.ucOSD_preview_temp = UserData.ucBFMode;
    SetOSDState(OSD_ITEM_3_1_1_STATE+UserData.ucBFMode);
}

void OSDFocusSenseye(void)
{
    Custom_System.ucOSD_preview_temp = UserData.bSensEyeDemo;
//    SetDemo();
}

void OSDFocusDynamicCn(void)
{
    OSDShowDynamicContrast(TRUE);
}

void OSDFocusDisplayMode(void)
{
    //printf("OSDFocusDisplayMode: UserData.ucAspectRatio = %d\n", (USHRT)UserData.ucAspectRatio);
    Custom_System.ucOSD_preview_temp = UserData.ucAspectRatio;
    //SetOSDState(OSD_ITEM_3_5_1_STATE+UserData.ucAspectRatio);
}

void OSDFocusOverScan(void)
{
    if(IsComponentInput()){
        Custom_System.ucOSD_preview_temp = UserData.bSOGOverScan;
    }
    else{
        Custom_System.ucOSD_preview_temp = UserData.bOverScan;
    }
}

void OSDFocusColorFormat(void)
{
    //printf("OSDFocusColorFormat 0\n");
    Custom_System.ucOSD_preview_temp = UserData.bColorFormat;
}

void OSDFocusHDMIRGBPCRange(void)
{
    //printf("OSDFocusColorFormat 0\n");
    Custom_System.ucOSD_preview_temp = UserData.ucHDMIRGBRange;
}



void OSDFocusCustKey1(void)
{
    //printf("OSDFocusCustKey1: UserData.ucCustomerKey1 = %d\n", (USHRT)UserData.ucCustomerKey1);

    SetOSDState(OSD_ITEM_4_2_1_STATE+UserData.ucCustomerKey1);
}

void OSDFocusCustKey2(void)
{
    //printf("OSDFocusCustKey2: UserData.ucCustomerKey2 = %d\n", (USHRT)UserData.ucCustomerKey2);

    SetOSDState(OSD_ITEM_4_3_1_STATE+UserData.ucCustomerKey2);
}

void OSDFocusCustKey3(void)
{
    //printf("OSDFocusCustKey3: UserData.ucCustomerKey3 = %d\n", (USHRT)UserData.ucCustomerKey3);
    SetOSDState(OSD_ITEM_4_4_1_STATE+UserData.ucCustomerKey3);
}

void OSDFocusDDCCi(void)
{
    Custom_System.ucOSD_preview_temp = UserData.bDDCCI;
    //printf("OSDFocusDDCCi: UserData.bDDCCI = %d\n", (USHRT)UserData.bDDCCI);
    SetOSDState(OSD_ITEM_4_5_1_STATE+(1-UserData.bDDCCI));
}
#if 0
void OSDFocusHdmiAutoSwitch(void)
{
    SetOSDState(OSD_ITEM_4_6_1_STATE+(1-UserData.bHDMIAutoSwitch));
}
#endif
void OSDFocusAutoPwrOff(void)
{
    //printf("OSDFocusAutoPwrOff: UserData.ucAutoPowerOffTime = %d\n", (USHRT)UserData.ucAutoPowerOffTime);

    SetOSDState(OSD_ITEM_4_8_1_STATE+UserData.ucAutoPowerOffTime);
}

void OSDFocusResNotice(void)
{
    //printf("OSDFocusResNotice: UserData.ucResNotice = %d\n", (USHRT)UserData.ucResNotice);

    SetOSDState(OSD_ITEM_4_9_1_STATE+(1-UserData.bResNotice));
}


void OSDColorHueUp(void)
{
    UserData.ucHue++;
    if (UserData.ucHue > MAXIMUM_HUE)
        UserData.ucHue  = MAXIMUM_HUE;
    else {
        OSDShowHue(TRUE, FALSE);
        UserSetHue();
    }
    SetOSDUpdUsrFlag();
}

void OSDColorHueDown(void)
{
    UserData.ucHue--;
    if ((UserData.ucHue > MAXIMUM_HUE) ||
        (UserData.ucHue < MINIMUM_HUE))
        UserData.ucHue  = MINIMUM_HUE;
    else {
        OSDShowHue(TRUE, FALSE);
        UserSetHue();
    }
    SetOSDUpdUsrFlag();
}

void OSDColorSaturationUp()
{
    UserData.ucSaturation++;
    if (UserData.ucSaturation > MAXIMUM_SATURATION)
        UserData.ucSaturation  = MAXIMUM_SATURATION;
    else {
        OSDShowSaturation(TRUE, FALSE);
        UserSetSaturation();
    }
    SetOSDUpdUsrFlag();
}

void OSDColorSaturationDown()
{
    UserData.ucSaturation--;
    if ((UserData.ucSaturation > MAXIMUM_SATURATION) ||
        (UserData.ucSaturation < MINIMUM_SATURATION))
        UserData.ucSaturation  = MINIMUM_SATURATION;
    else {
        OSDShowSaturation(TRUE, FALSE);
        UserSetSaturation();
    }
    SetOSDUpdUsrFlag();
}
/*
void OSDColorResetColorUp()
{

}
void OSDColorResetColorDown()
{

}

void OSDColorAMAUp()
{

}
void OSDColorAMADown()
{

}
*/
//void OSDSensEye(void)
//{
    
//}

void OSDDynamicCnUp()
{
    if(UserData.ucDynamicContrast == 0)//ULEric140414
    {
        SetOSDState(OSD_INFO_DCR_NOTICE_STATE);
    OSDShowDialog(OSD_DLG_DCRNOTICE, 0);
    OSDUpdateKeyInfo(OSD_INFO_DCR_NOTICE_STATE);     
    }
    else{

        if (++UserData.ucDynamicContrast > MAXIMUM_DYNCONTRAST) {
            UserData.ucDynamicContrast  = MAXIMUM_DYNCONTRAST;
        }
    
        OSDShowDynamicContrast(TRUE);
        UserSetDCR();
        SetOSDUpdUsrFlag();
    }
}

void OSDDynamicCnDown()
{
    UserData.ucDynamicContrast--;
    if (UserData.ucDynamicContrast > MAXIMUM_DYNCONTRAST || UserData.ucDynamicContrast < MINIMUM_DYNCONTRAST) {
        UserData.ucDynamicContrast = MINIMUM_DYNCONTRAST;
    }

    OSDShowDynamicContrast(TRUE);
    UserSetDCR();    
    SetOSDUpdUsrFlag();
}

void OSDSetOverScan()
{
    UserSetAspectRatio();  
    //UserSetOverScan();    
    //SetOSDUpdUsrFlag();
}
void OSDBColorFormatUp()
{
    if (UserData.bColorFormat == COLOR_RGB) {
        UserData.bColorFormat = COLOR_YUV;
    }
    else {
        UserData.bColorFormat = COLOR_RGB;          
        Custom_System.bisColorFormatRGB = TRUE;
    }
    ODAPI_ODTestPatternEnable();
    SetColorSpace();
    Sleep(50);
    ODAPI_ODTestPatternDisable();
}
void OSDBColorFormatDown()
{
    if (UserData.bColorFormat == COLOR_RGB) {
        UserData.bColorFormat = COLOR_YUV;
    }
    else {
        UserData.bColorFormat = COLOR_RGB;        
        Custom_System.bisColorFormatRGB = TRUE;         
    }
    ODAPI_ODTestPatternEnable();
    SetColorSpace();
    Sleep(50);
    ODAPI_ODTestPatternDisable();
}

void OSDHDMIRGBPCRangeUp()
{
    if (UserData.ucHDMIRGBRange == COLOR_FULL) {
        UserData.ucHDMIRGBRange = COLOR_LIMIT;
    }
    else {
        UserData.ucHDMIRGBRange = COLOR_FULL;
    }
    SetColorSpace();
}
void OSDHDMIRGBPCRangeDown()
{
    if (UserData.ucHDMIRGBRange == COLOR_FULL) {
        UserData.ucHDMIRGBRange = COLOR_LIMIT;
    }
    else {
        UserData.ucHDMIRGBRange = COLOR_FULL;
    }
    SetColorSpace();      
}

void OSDAudioMuteUp()
{
    UserData.bAudioMute = !UserData.bAudioMute;
    UserSetVolumeAndMute();    
}

void OSDAudioSelectUp()
{
    if (UserData.ucInputSource == INPUT_SC_HDMI) {
          UserData.ucHDMIAudioSelect = (UserData.ucHDMIAudioSelect+NUM_AUDIOSELECT-1)%NUM_AUDIOSELECT;
    }
    else {
        //UserData.ucAudioSelect = (UserData.ucAudioSelect+NUM_AUDIOSELECT-1)%NUM_AUDIOSELECT;
        if (UserData.ucAudioSelect == AUDIOSRC_PC) {
            UserData.ucAudioSelect = AUDIOSRC_AUTO;
        }
        else {
            UserData.ucAudioSelect = AUDIOSRC_PC;
        }
    }    
    OSDAudioSelect();
}
void OSDAudioSelectDown()
{
    if (UserData.ucInputSource == INPUT_SC_HDMI) {
        UserData.ucHDMIAudioSelect = (UserData.ucHDMIAudioSelect+1)%NUM_AUDIOSELECT;
    }
    else {
        if (UserData.ucAudioSelect == AUDIOSRC_PC) {
            UserData.ucAudioSelect = AUDIOSRC_AUTO;
        }
        else {
            UserData.ucAudioSelect = AUDIOSRC_PC;
        }
    }    
    OSDAudioSelect();
}
void OSDAudioSelect()
{    
    AudioMuteOn();
    SetVolume(0);
    UserSetAudioChannel();
    Sleep(100);    
    UserSetVolume();
    UserSetAudioMute();
}
/*
void OSDCustKey1Up()
{
    UserData.ucCustomerKey1 =
        (UserData.ucCustomerKey1+CUSTOMER_KEY_NUM-1)%CUSTOMER_KEY_NUM;
    SetOSDUpdUsrFlag();
}
void OSDCustKey1Down()
{
    UserData.ucCustomerKey1 =
        (UserData.ucCustomerKey1+1)%CUSTOMER_KEY_NUM;
    SetOSDUpdUsrFlag();
}
void OSDCustKey2Up()
{
    UserData.ucCustomerKey2 =
        (UserData.ucCustomerKey2+CUSTOMER_KEY_NUM-1)%CUSTOMER_KEY_NUM;
    SetOSDUpdUsrFlag();
}
void OSDCustKey2Down()
{
    UserData.ucCustomerKey2 =
        (UserData.ucCustomerKey2+1)%CUSTOMER_KEY_NUM;
    SetOSDUpdUsrFlag();
}
void OSDCustKey3Up()
{
    UserData.ucCustomerKey3 =
        (UserData.ucCustomerKey3+CUSTOMER_KEY_NUM-1)%CUSTOMER_KEY_NUM;
    SetOSDUpdUsrFlag();
}
void OSDCustKey3Down()
{
    UserData.ucCustomerKey3 =
        (UserData.ucCustomerKey3+1)%CUSTOMER_KEY_NUM;
    SetOSDUpdUsrFlag();
}
*/
void OSDDDCCiUp()
{
    UserData.bDDCCI= !UserData.bDDCCI;
    //UserSetDDCCI();
}
void OSDDDCCiDown()
{
    UserData.bDDCCI= !UserData.bDDCCI;
    //UserSetDDCCI();
}

void OSDDDCCIConfirm()
{
    UserSetDDCCI();
    SetOSDUpdUsrFlag();
}

void OSDDPAutoSwitchUp()
{
    UserData.bDPAutoSwitch= !UserData.bDPAutoSwitch;
}
void OSDDPAutoSwitchDown()
{
    UserData.bDPAutoSwitch= !UserData.bDPAutoSwitch;
}

void OSDHDMIAutoSwitchUp()
{
    UserData.bHDMIAutoSwitch= !UserData.bHDMIAutoSwitch;
}

void OSDHDMIAutoSwitchDown()
{
    UserData.bHDMIAutoSwitch= !UserData.bHDMIAutoSwitch;
}

void OSDAutoPowOffUp()
{
    OSD_Select_Temp = (OSD_Select_Temp+AUTO_POWER_NUM-1)%AUTO_POWER_NUM;
}
void OSDAutoPowOffDown()
{
    OSD_Select_Temp = (OSD_Select_Temp+1)%AUTO_POWER_NUM;
}
void OSDResNoticeUp()
{
    UserData.bResNotice= !UserData.bResNotice;
}
void OSDResNoticeDown()
{
    UserData.bResNotice= !UserData.bResNotice;
}

void OSDShowLowBlueLightStrings(UCHAR id)
{
    UCHAR i;
    id = id ;
    for (i=0; i<ucLBLItemInfoTb[0]; i++) {
        ShowIndentString(TRUE, ucLBLItemInfoTb[1], ucLBLItemInfoTb[2]+i*2, INDENT_STRING_MAX_LEN-2, LowBlueLightTab[i*NUM_OSDLANGS+UserData.ucLanguage]);
    }

}

void OSDShowCurrentResolution(UCHAR x, UCHAR y)
{
    UCHAR i, len, interface;
    USHRT usHactive, usVactive, usVsync;
    UCHAR buff[13];
    pInputTiming = GetModeHandleInputTiming(_MainChannel);
    interface = GetCurrInputInterface();
    usHactive = pInputTiming->usModeHActive;
    usVactive = pInputTiming->usModeVActive;
    usVsync = (pInputTiming->usVSyncFreq+5)/10;    
    memset(buff, 0, GLOB_FONTBUF_LEN);

    //if (IsHDMI() == TRUE && IsVideoResolution() == TRUE) {
   /* if (((UserData.ucInputSource == INPUT_SC_HDMI) || (UserData.ucInputSource == INPUT_SC_HDMI1) || (UserData.ucInputSource == INPUT_SC_HDMI2) ||
        (UserData.ucInputSource == INPUT_SC_HDMI3) || (UserData.ucInputSource == INPUT_SC_HDMI4))
        && IsVideoResolution() == TRUE) {

        if (IsInterlaced() == TRUE) {
            sprintf(buff,"n%di", usVactive);
        }
        else{
            sprintf(buff,"n%dp", usVactive);
        }
    }
    else {*/
        sprintf(buff,"n%dx%d@%d",usHactive, usVactive, usVsync);//130327_1345_OSD#2
    //}

    for (i=0; i<GLOB_FONTBUF_LEN; i++) {
        if (buff[i] == 0)
            break;
    }
    buff[0] = i - 1;
    len = buff[0];
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    
    if(IsComponentTiming()){
        if((interface == ANALOG_SOG_INPUT0)||(interface == ANALOG_SOG_INPUT1)){
            OSDShowComponentTimingResolution(x, y);
        }
        else if((interface == ANALOG_COM_INPUT0)||(interface == ANALOG_COM_INPUT1)){
            if((pInputTiming->usModeIndex == _720x480I_60HZ)||(pInputTiming->usModeIndex == _720x576I_50HZ)){
                OSDShowComponentTimingResolution(x, y);
            }
            else{
                ShowIndentString(TRUE, x, y, 10, buff);
            }
        }
        else if(UserData.ucInputSource == INPUT_SC_HDMI){
            OSDShowComponentTimingResolution(x, y);
        }
        else{
            ShowIndentString(TRUE, x, y, 10, buff);
        }
    }
    else{
        ShowIndentString(TRUE, x, y, 10, buff);
    }


}

void OSDShowComponentTimingResolution(UCHAR x, UCHAR y)
{
    UCHAR i, len;
    UCHAR buff[13];
    memset(buff, 0, GLOB_FONTBUF_LEN);
    switch (pInputTiming->usModeIndex){
        case _720x480I_60HZ:
            sprintf(buff,"n480i@60");//130327_1345_OSD#2
            break;
        case _720x576I_50HZ:
            sprintf(buff,"n576i@50");//130327_1345_OSD#2
            break;
        case _640x480_60HZ:
            sprintf(buff,"n640x480@60");//130327_1345_OSD#2
            break;
        case _720x480P_60HZ:
            sprintf(buff,"n480p@60");//130327_1345_OSD#2
            break;
        case _720x576P_50HZ:
            sprintf(buff,"n576p@60");//130327_1345_OSD#2
            break;
        case _1280x720P_50HZ:
            sprintf(buff,"n720p@50");//130327_1345_OSD#2
            break;
        case _1280x720P_60HZ:
            sprintf(buff,"n720p@60");//130327_1345_OSD#2
            break;
        case _1280x720_60HZ:
            sprintf(buff,"n720p@60");//130327_1345_OSD#2
            break;
        case _1920x1080I_50HZ:
            sprintf(buff,"n1080i@50");//130327_1345_OSD#2
            break;
        case _1920x1080I_60HZ:
            sprintf(buff,"n1080i@60");//130327_1345_OSD#2
            break;
        case _1920x1080I_50HZ125:
            sprintf(buff,"n1080i@50");//130327_1345_OSD#2
            break;    
        case _1920x1080P_50HZ:
            sprintf(buff,"n1080p@50");//130327_1345_OSD#2
            break;    
        case _1920x1080P_60HZ:
            sprintf(buff,"n1080p@60");//130327_1345_OSD#2
            break;        
        default:
            break;    
    }

    for (i=0; i<GLOB_FONTBUF_LEN; i++) {
        if (buff[i] == 0)
            break;
    }
    buff[0] = i - 1;
    len = buff[0];
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    ShowIndentString(TRUE, x, y, 10, buff);
}


void OSDShowOptimumResolution(UCHAR x, UCHAR y)
{
    UCHAR i, len;
    USHRT usHactive, usVactive;
    UCHAR buff[13];
    //pInputTiming = GetModeHandleInputTiming(_MainChannel);

    usHactive = UserPanelData.usWidth;
    usVactive = UserPanelData.usHeight;
    memset(buff, 0, GLOB_FONTBUF_LEN);

    //if (IsHDMI() == TRUE && IsVideoResolution() == TRUE) {
   /* if (((UserData.ucInputSource == INPUT_SC_HDMI) || (UserData.ucInputSource == INPUT_SC_HDMI1) || (UserData.ucInputSource == INPUT_SC_HDMI2) ||
        (UserData.ucInputSource == INPUT_SC_HDMI3) || (UserData.ucInputSource == INPUT_SC_HDMI4))
        && IsVideoResolution() == TRUE) {

        if (IsInterlaced() == TRUE) {
            sprintf(buff,"n%di", usVactive);
        }
        else{
            sprintf(buff,"n%dp", usVactive);
        }
    }
    else {*/
        sprintf(buff,"n%dx%d@60",usHactive, usVactive);//130327_1345_OSD#2
    //}

    for (i=0; i<GLOB_FONTBUF_LEN; i++) {
        if (buff[i] == 0)
            break;
    }
    buff[0] = i - 1;
    len = buff[0];
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    ShowIndentString(TRUE, x, y, 10, buff);


}


void OSDShowSmarReminder(void)
{
    OSDCloseAll();
    SetOSDState(OSD_INFO_SMART_REMINDER_STATE);
    OSDShowDialog(OSD_DLG_REMINDER,0);
}

void OSDShowSensEyeDemo(void)
{
    OSDCloseAll();
    SetOSDState(OSD_INFO_SENSEYE_DEMO_STATE);
    OSDShowDialog(OSD_DLG_SENSEYE_DEMO,0);
}


