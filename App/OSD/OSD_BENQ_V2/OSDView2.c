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
#define LAYER_WIN_POS_SY    18*3+9                              //63
#define LAYER_WIN_POS_EY    18*3+9+18*(OSD_MAIN_HEIGHT-6)+13    //

#define LAYER1_WIN_POS_SX   12*2+OSD_POSITION_OFFSET*12                                          //91
#define LAYER1_WIN_POS_EX   12*(LAYER1_LENGTH+3+OSD_POSITION_OFFSET+1)+OSD_WIN_BOARDER_SIZE   //355

#define LAYER2_WIN_POS_SX   LAYER1_WIN_POS_EX+OSD_WIN_BOARDER_SIZE//LAYER1_WIN_POS_EX+OSD_WIN_BOARDER_SIZE+8//+12+11                         //378
#define LAYER2_WIN_POS_EX   LAYER2_WIN_POS_SX+6+12*(LAYER2_LENGTH+1)+OSD_WIN_BOARDER_SIZE        //606

#define LAYER3_WIN_POS_SX   LAYER2_WIN_POS_EX+OSD_WIN_BOARDER_SIZE//+12+11                         //629
#define LAYER3_WIN_POS_EX   LAYER3_WIN_POS_SX+6+12*(LAYER3_LENGTH+1)+OSD_WIN_BOARDER_SIZE

#define LAYER4_WIN_POS_SX   LAYER3_WIN_POS_EX+OSD_WIN_BOARDER_SIZE//+12+11
#define LAYER4_WIN_POS_EX   LAYER4_WIN_POS_SX+12*(LAYER4_LENGTH+1)+OSD_WIN_BOARDER_SIZE

#define DIA_LAYER1_WIN_POS_SX   (DIALOG_POSITION_OFFSET+DIALOG_ICON_OFFSET_X+DIALOG_ICON_WIDTH+DIALOG_STR_OFFSET_FROM_ICON)*12+3+OSD_WIN_BOARDER_SIZE  //
#define DIA_LAYER1_WIN_POS_EX   DIA_LAYER1_WIN_POS_SX+6+(DIALOG_LAYER_WIN_WIDTH-1)*12
#define DIA_LAYER1_WIN_POS_SY   (OSD_CUSTOM_TOP_BAR_HEIGHT+1)*18
#define DIA_LAYER1_WIN_POS_EY   DIA_LAYER1_WIN_POS_SY+(DIALOG_LAYER_WIN_HEIGHT)*18

#define DIA_BG_WIN_POS_SX   DIALOG_POSITION_OFFSET*12
#define DIA_BG_WIN_POS_EX   DIA_BG_WIN_POS_SX+(OSD_CUSTOMERKEY_MENU1_WIDTH-1)*12
#define DIA_BG_WIN_POS_SY   OSD_CUSTOM_TOP_BAR_HEIGHT*18-5
#define DIA_BG_WIN_POS_EY   DIA_BG_WIN_POS_SY+DIALOG_LAYER_HEIGHT*18+5
//Dialog 2 (Slider menu)
#define DIA2_BG_WIN_POS_SX   DIALOG2_POSITION_OFFSET*12
#define DIA2_BG_WIN_POS_EX   DIA2_BG_WIN_POS_SX+(OSD_CUSTOMERKEY_MENU2_WIDTH-1)*12-1
#define DIA2_BG_WIN_POS_SY   OSD_CUSTOM_TOP_BAR_HEIGHT*18-5
#define DIA2_BG_WIN_POS_EY   DIA_BG_WIN_POS_SY+DIALOG_LAYER_HEIGHT*18+5

#define DIA2_LAYER_WIN_POS_SX   (DIALOG2_POSITION_OFFSET+DIALOG_ICON_OFFSET_X+DIALOG_ICON_WIDTH+DIALOG_STR_OFFSET_FROM_ICON)*12+3+OSD_WIN_BOARDER_SIZE  //
#define DIA2_LAYER_WIN_POS_EX   DIA2_LAYER_WIN_POS_SX+6+(DIA2_LAYER_WIN_WIDTH-1)*12
#define DIA2_LAYER_WIN_POS_SY   (OSD_CUSTOM_TOP_BAR_HEIGHT+1)*18
#define DIA2_LAYER_WIN_POS_EY   DIA_LAYER1_WIN_POS_SY+(DIA2_LAYER_WIN_HEIGHT)*18


// layer1~4 window position table
// pixel unit based
USHRT usLayer1WinPosTab[] = {
// start x, start y, end x, end y
    LAYER1_WIN_POS_SX, LAYER_WIN_POS_SY, LAYER1_WIN_POS_EX, LAYER_WIN_POS_EY
};

USHRT usLayer2WinPosTab[] = {
// start x, start y, end x, end y
    LAYER2_WIN_POS_SX, LAYER_WIN_POS_SY, LAYER2_WIN_POS_EX, LAYER_WIN_POS_EY
};

USHRT usLayer3WinPosTab[] = {
// start x, start y, end x, end y
    LAYER3_WIN_POS_SX, LAYER_WIN_POS_SY, LAYER3_WIN_POS_EX, LAYER_WIN_POS_EY
};

USHRT usLayer4WinPosTab[] = {
// start x, start y, end x, end y
    LAYER4_WIN_POS_SX, LAYER_WIN_POS_SY, LAYER4_WIN_POS_EX, LAYER_WIN_POS_EY
};

USHRT usDialogLayerWinPosTab[] = {
// start x, start y, end x, end y
    DIA_LAYER1_WIN_POS_SX, DIA_LAYER1_WIN_POS_SY, DIA_LAYER1_WIN_POS_EX, DIA_LAYER1_WIN_POS_EY
};

USHRT usDialog2LayerWinPosTab[] = {
// start x, start y, end x, end y
    DIA2_LAYER_WIN_POS_SX, DIA2_LAYER_WIN_POS_SY, DIA2_LAYER_WIN_POS_EX, DIA2_LAYER_WIN_POS_EY
};

USHRT usClrTempWinPosTab[] = {
// start x, start y, end x, end y
12*46+9, 18*3, 12*62+9, 18*19+17
};


UCHAR ucLayer4ItemLowBlueLightInfoTb[3] = {
    // item count, X start position, Y start position
    4, 47, 5,
};

UCHAR DialogSPBotIconHookPosTab[8] = {
    // X Pos, Y Pos
    //19, 1,
    4, 1,
    5, 1,
    3, 2,
    4, 2,
    //21, 2
};

UCHAR DialogSPBotIconExitPosTab[12] = {
    // X Pos, Y Pos
    //19, 1,
    3, 5,
    4, 5,
    5, 5,
    3, 6,
    4, 6,
    5, 6,
    //21, 2
};

//******************************************************************************
// G L O B A L  V A L I A B L E
//******************************************************************************
BOOL bSelNum2 =FALSE;
static UCHAR ucTemp_BFMode = 0;
static USHRT usTemp_ReShow = 0;//ULEric140331
static BOOL bIsRepeatKey = FALSE;//ULEric140409
static UCHAR ucKeyInfoStatus = 0xff;//ULEric140409
UCHAR OSD_Select_Temp;
BOOL bOSD_Select_Temp;
BOOL bShowInputNovitceFlag = TRUE;
BOOL bShortOOLTimer;

void ResetKeyInfoStatus(void)
{
    ucKeyInfoStatus = 0xff;
}

BOOL OSDCheckHookIcon(void)
{
    BOOL Result = FALSE;
    USHRT usOSDStateTemp = GetOSDState();
    if(usOSDStateTemp == OSD_MAIN_1_1_STATE)
        Result = TRUE;
    if(usOSDStateTemp >=  (OSD_ITEM_1_2_start_STATE+1) && usOSDStateTemp < OSD_ITEM_1_2_END)
        Result = TRUE;
    if(usOSDStateTemp >=  OSD_ITEM_2_4_1_STATE && usOSDStateTemp < OSD_ITEM_2_5_END)
        Result = TRUE;
    if(usOSDStateTemp >=  OSD_ITEM_2_8_1_STATE && usOSDStateTemp < OSD_ITEM_2_9_END)
        Result = TRUE;
    if(usOSDStateTemp >=  OSD_ITEM_3_1_1_STATE && usOSDStateTemp < OSD_ITEM_3_2_END)
        Result = TRUE;
#if MD_ENABLE_OVERSCAN == ON            
    if(usOSDStateTemp >=  OSD_ITEM_3_4_1_STATE && usOSDStateTemp < OSD_ITEM_3_7_END)
        Result = TRUE;
#endif    
    if(usOSDStateTemp >=  OSD_ITEM_Audio_2_1_STATE && usOSDStateTemp < OSD_ITEM_Audio_END)
        Result = TRUE;
#if ENABLE_ECO_SENSOR == OFF
#if ENABLE_ERGONOMICS == ON
    if(usOSDStateTemp >=  OSD_ITEM_4_2_1_STATE && usOSDStateTemp < OSD_ITEM_ERGO_END)//ULEric140407
#else
    if(usOSDStateTemp >=  OSD_ITEM_4_2_1_STATE && usOSDStateTemp < OSD_ITEM_4_12_END)//ULEric140407
#endif
#else
    if(usOSDStateTemp >=  OSD_ITEM_4_2_1_STATE && usOSDStateTemp < OSD_ITEM_ECO_END)//ULEric140407    
#endif    
        Result = TRUE;
    if(usOSDStateTemp >=  OSD_SUBITEM_3_1_2_STATE_BEG && usOSDStateTemp < OSD_SUBITEM_4_1_2_END)//ULEric140407
        Result = TRUE;
    return Result;
}

#if ENABLE_ERGONOMICS == ON 

UCHAR isOSDLastItem(USHRT CurrIndex, USHRT StartIndex, UCHAR ItemNum)
{

    if(ItemNum > OSD_MAX_LINES)
        ItemNum = OSD_MAX_LINES;

    if((CurrIndex - StartIndex) == (ItemNum-1)){
        //printtf("Last:Item#%bx\r\n",(CurrIndex - StartIndex));
        return TRUE;
    }
    else{
        return FALSE;
    }
}

UCHAR isOSDFirstItem(USHRT CurrIndex, USHRT StartIndex, UCHAR ItemNum)
{

    if(ItemNum > OSD_MAX_LINES)
        ItemNum = OSD_MAX_LINES-1;
    else
        ItemNum = 0;

    if((CurrIndex - StartIndex) == ItemNum){
        //printtf("First:Item#%bx\r\n",(CurrIndex - StartIndex));
        return TRUE;
    }
    else{
        return FALSE;
    }
}
#endif
UCHAR OSDCheckKeyInfo(UCHAR Layer,USHRT usOsdState)
{

    UCHAR KeyInfoType;
    switch(Layer){
        case LAYER_1: 
            KeyInfoType = OSDKEYINFO_TYPE_UDRLE;
            break;
        case LAYER_2:
            KeyInfoType = OSDKEYINFO_TYPE_UDRLE;
            break;
        case LAYER_3:
            KeyInfoType = OSDKEYINFO_TYPE_UDOLE;//Layer3 default
            if (usOsdState>=OSD_ITEM_2_1_STATE&&usOsdState<=OSD_ITEM_2_3_STATE)
                KeyInfoType = OSDKEYINFO_TYPE_UDLE;
            else if (usOsdState>=OSD_ITEM_2_6_STATE&&usOsdState<=OSD_ITEM_2_7_STATE)
                KeyInfoType = OSDKEYINFO_TYPE_UDLE;
            else if (usOsdState==OSD_ITEM_3_3_STATE||usOsdState==OSD_ITEM_Audio_1_1_STATE)
                KeyInfoType = OSDKEYINFO_TYPE_UDLE;
#if ENABLE_OSD_ANALOG_FUNCTION == ON  
            else if (usOsdState>=OSD_ITEM_1_3_STATE&&usOsdState<=OSD_ITEM_1_6_STATE)
                KeyInfoType = OSDKEYINFO_TYPE_UDLE;
#endif            
#if ENABLE_CUSTOMKEY_CAD == ON                
            else if (usOsdState==OSD_ITEM_4_2_2_STATE) { //customer key1
            #if ENABLE_CUSTOMKEY_LBL == ON            
                if ((UserData.ucCustomerKey2 == CUSTOMER_KEY_LOWBULELIGHTMODE) || (UserData.ucCustomerKey3 == CUSTOMER_KEY_LOWBULELIGHTMODE))
                    KeyInfoType = OSDKEYINFO_TYPE_DOLE;
            #endif                
            }
            else if (usOsdState==OSD_ITEM_4_3_2_STATE) { //customer key2
            #if ENABLE_CUSTOMKEY_LBL == ON            
                if ((UserData.ucCustomerKey1 == CUSTOMER_KEY_LOWBULELIGHTMODE) || (UserData.ucCustomerKey3 == CUSTOMER_KEY_LOWBULELIGHTMODE))
                    KeyInfoType = OSDKEYINFO_TYPE_DOLE;
            #endif        
            }
            else if (usOsdState==OSD_ITEM_4_4_2_STATE) { //customer key3
            #if ENABLE_CUSTOMKEY_LBL == ON            
                if ((UserData.ucCustomerKey1 == CUSTOMER_KEY_LOWBULELIGHTMODE) || (UserData.ucCustomerKey2 == CUSTOMER_KEY_LOWBULELIGHTMODE))
                    KeyInfoType = OSDKEYINFO_TYPE_DOLE;
            #endif                
            }
#endif
#if ENABLE_CUSTOMKEY_ANIMATION == ON
        else if (usOsdState==OSD_ITEM_4_2_3_STATE) { //customer key1
        #if ENABLE_CUSTOMKEY_LBL == ON                    
            if (((UserData.ucCustomerKey2 == CUSTOMER_KEY_LOWBULELIGHTMODE) && (UserData.ucCustomerKey3 == CUSTOMER_KEY_PICTUREMODE)) ||\
                ((UserData.ucCustomerKey3 == CUSTOMER_KEY_LOWBULELIGHTMODE) && (UserData.ucCustomerKey2 == CUSTOMER_KEY_PICTUREMODE)))
                KeyInfoType = OSDKEYINFO_TYPE_DOLE;
        #endif                
        }
        else if (usOsdState==OSD_ITEM_4_3_3_STATE) { //customer key2
        #if ENABLE_CUSTOMKEY_LBL == ON                    
            if (((UserData.ucCustomerKey1 == CUSTOMER_KEY_LOWBULELIGHTMODE) && (UserData.ucCustomerKey3 == CUSTOMER_KEY_PICTUREMODE)) ||\
                ((UserData.ucCustomerKey3 == CUSTOMER_KEY_LOWBULELIGHTMODE) && (UserData.ucCustomerKey1 == CUSTOMER_KEY_PICTUREMODE)))
                KeyInfoType = OSDKEYINFO_TYPE_DOLE;
        #endif                
        }
        else if (usOsdState==OSD_ITEM_4_4_3_STATE) { //customer key3
        #if ENABLE_CUSTOMKEY_LBL == ON                    
            if (((UserData.ucCustomerKey1 == CUSTOMER_KEY_LOWBULELIGHTMODE) && (UserData.ucCustomerKey2 == CUSTOMER_KEY_PICTUREMODE)) ||\
                ((UserData.ucCustomerKey2 == CUSTOMER_KEY_LOWBULELIGHTMODE) && (UserData.ucCustomerKey1 == CUSTOMER_KEY_PICTUREMODE)))
                KeyInfoType = OSDKEYINFO_TYPE_DOLE;
        #endif                
        }
#endif   
#if ENABLE_ERGONOMICS == ON 
//        else if (usOsdState==OSD_ITEM_4_2_8_STATE) { //customer key1
        else if (isOSDLastItem(usOsdState, OSD_ITEM_4_2_1_STATE, CUSTOMER_KEY_NUM)) { //customer key1        
            if (((UserData.ucCustomerKey2 == CUSTOMER_KEY_INPUT) && (UserData.ucCustomerKey3 == CUSTOMER_KEY_SMARTREMINDER)) ||\
                ((UserData.ucCustomerKey3 == CUSTOMER_KEY_INPUT) && (UserData.ucCustomerKey2 == CUSTOMER_KEY_SMARTREMINDER)))
                KeyInfoType = OSDKEYINFO_TYPE_UOLE;
        }
//        else if (usOsdState==OSD_ITEM_4_3_8_STATE) { //customer key2
        else if (isOSDLastItem(usOsdState, OSD_ITEM_4_3_1_STATE, CUSTOMER_KEY_NUM)) { //customer key2                
            if (((UserData.ucCustomerKey1 == CUSTOMER_KEY_INPUT) && (UserData.ucCustomerKey3 == CUSTOMER_KEY_SMARTREMINDER)) ||\
                ((UserData.ucCustomerKey3 == CUSTOMER_KEY_INPUT) && (UserData.ucCustomerKey1 == CUSTOMER_KEY_SMARTREMINDER)))
                KeyInfoType = OSDKEYINFO_TYPE_UOLE;
        }
        //else if (usOsdState==OSD_ITEM_4_4_8_STATE) { //customer key3
        else if (isOSDLastItem(usOsdState, OSD_ITEM_4_4_1_STATE, CUSTOMER_KEY_NUM)) { //customer key3                
            if (((UserData.ucCustomerKey1 == CUSTOMER_KEY_INPUT) && (UserData.ucCustomerKey2 == CUSTOMER_KEY_SMARTREMINDER)) ||\
                ((UserData.ucCustomerKey2 == CUSTOMER_KEY_INPUT) && (UserData.ucCustomerKey1 == CUSTOMER_KEY_SMARTREMINDER)))
                KeyInfoType = OSDKEYINFO_TYPE_UOLE;
        }
        //else if (usOsdState==OSD_ITEM_4_2_9_STATE) { //customer key1
        else if (isOSDFirstItem(usOsdState, OSD_ITEM_4_2_1_STATE, CUSTOMER_KEY_NUM)) { //customer key1                
            if ((UserData.ucCustomerKey2 == CUSTOMER_KEY_SMARTREMINDER) || (UserData.ucCustomerKey3 == CUSTOMER_KEY_SMARTREMINDER))
                KeyInfoType = OSDKEYINFO_TYPE_UOLE;
        }
//        else if (usOsdState==OSD_ITEM_4_3_9_STATE) { //customer key2
        else if (isOSDFirstItem(usOsdState, OSD_ITEM_4_3_1_STATE, CUSTOMER_KEY_NUM)) { //customer key2                
            if ((UserData.ucCustomerKey1 == CUSTOMER_KEY_SMARTREMINDER) || (UserData.ucCustomerKey3 == CUSTOMER_KEY_SMARTREMINDER))
                KeyInfoType = OSDKEYINFO_TYPE_UOLE;
        }
        //else if (usOsdState==OSD_ITEM_4_4_9_STATE) { //customer key3
        else if (isOSDFirstItem(usOsdState, OSD_ITEM_4_4_1_STATE, CUSTOMER_KEY_NUM)) { //customer key3                
            if ((UserData.ucCustomerKey1 == CUSTOMER_KEY_SMARTREMINDER) || (UserData.ucCustomerKey2 == CUSTOMER_KEY_SMARTREMINDER))
                KeyInfoType = OSDKEYINFO_TYPE_UOLE;
        }
#endif        
            break;
        case LAYER_4:
            KeyInfoType = OSDKEYINFO_TYPE_UDOLE;
            break;
        default: 
            KeyInfoType = OSDKEYINFO_TYPE_UDRLE;
            break;
    }

    return KeyInfoType;
}

UCHAR OSDUpdateKeyInfo(BOOL bUpdate,USHRT usOsdState)
{
    UCHAR ucLayer = 0;
    UCHAR ucKeyInfoType = 0;
    UCHAR ucOffset = 0;
    
    if (usOsdState>=OSD_MAIN_BEG&&usOsdState<OSD_MAIN_END)//LAYER_1 OSD
    {
        ucLayer = STRING_LAYER_1;
        ucKeyInfoType = OSDCheckKeyInfo(LAYER_1, usOsdState);
    }
    else if (usOsdState>=OSD_MAIN_1_1_STATE&&usOsdState<OSD_ITEM_1_1_STATE)//LAYER_2 OSD
    {
        ucLayer = STRING_LAYER_2;
        ucKeyInfoType = OSDCheckKeyInfo(LAYER_2, usOsdState);
        if (usOsdState == OSD_MAIN_1_1_STATE)
            ucKeyInfoType = OSDKEYINFO_TYPE_RLE;
        else if (usOsdState == OSD_MAIN_2_1_STATE||usOsdState == OSD_MAIN_4_1_STATE)//TOP
            ucKeyInfoType = OSDKEYINFO_TYPE_DRLE;
        else if (usOsdState == OSD_MAIN_4_10_STATE)
            ucKeyInfoType = OSDKEYINFO_TYPE_UDLE;
        else if (usOsdState == (OSD_MAIN_2_END-1)|| usOsdState == (OSD_MAIN_4_END-1))
            ucKeyInfoType = OSDKEYINFO_TYPE_URLE;
        else if ((usOsdState == OSD_MAIN_2_3_STATE) && (!OSDIsSubItemValid(OSD_PICTURE_BRIGHTNESS)))//ULEric140415
            ucKeyInfoType = OSDKEYINFO_TYPE_DRLE;
#if ENABLE_ERGONOMICS == ON
        else if ((usOsdState == OSD_MAIN_ERGO_1_STATE)&&(UserData.bSmartReminder == OFF)
#if ENABLE_EYE_PROTECT == ON            
                 &&(!(isOSDAllowEyeProtect()))&&(!(isOSDAllowEyeProtectMeter()))
#endif
                 )
            ucKeyInfoType = OSDKEYINFO_TYPE_RLE;
#endif
#if ENABLE_ECO_SENSOR == ON
        else if ((usOsdState == OSD_MAIN_ECO_SENSOR_STATE)&&(UserData.bECOSensor == OFF))
            ucKeyInfoType = OSDKEYINFO_TYPE_RLE;
#endif
        
    }
    else if (usOsdState>=OSD_ITEM_1_1_STATE&&usOsdState<OSD_SUBITEM_2_5_4_STATE_BEG)////LAYER_3 OSD
    {
        ucLayer = STRING_LAYER_3;
        ucKeyInfoType = OSDCheckKeyInfo(LAYER_3, usOsdState);

        if (usOsdState==OSD_ITEM_4_1_1_STATE||usOsdState==OSD_ITEM_4_1_2_STATE||usOsdState == OSD_ITEM_2_5_4_STATE)//ULEric140407
            ucKeyInfoType = OSDKEYINFO_TYPE_UDRLE;
        else if (usOsdState == OSD_ITEM_2_9_END) //display mode start
            ucKeyInfoType = OSDKEYINFO_TYPE_DOLE;
        else if (usOsdState == (OSD_ITEM_3_1_END-1)) //display mode end
            ucKeyInfoType = OSDKEYINFO_TYPE_UOLE;
        else if (usOsdState == OSD_ITEM_3_2_1_STATE&&UserData.bSensEyeDemo == PICTURE_DUALMODE_OFF)
            ucKeyInfoType = OSDKEYINFO_TYPE_RLE;        
        else if (usOsdState==OSD_ITEM_4_2_1_STATE||usOsdState==OSD_ITEM_4_3_1_STATE||usOsdState==OSD_ITEM_4_4_1_STATE)//ULEric140411
            ucKeyInfoType = OSDKEYINFO_TYPE_DOLE;
        else if ((usOsdState==(OSD_ITEM_4_1_END+1)||usOsdState==(OSD_ITEM_4_2_END+1)||usOsdState==(OSD_ITEM_4_3_END+1))\
            && ((OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_4_2_1_STATE, OSD_ITEM_4_2_1_STATE)) == FALSE)||(OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_4_3_1_STATE, OSD_ITEM_4_3_1_STATE)) == FALSE)||(OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_4_4_1_STATE, OSD_ITEM_4_4_1_STATE)) == FALSE))){
            ucKeyInfoType = OSDKEYINFO_TYPE_DOLE;
        }
        else if ((usOsdState==(OSD_ITEM_4_1_END+2)||usOsdState==(OSD_ITEM_4_2_END+2)||usOsdState==(OSD_ITEM_4_3_END+2))\
            && ((OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_4_2_1_STATE, OSD_ITEM_4_2_1_STATE+1)) == FALSE)||(OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_4_3_1_STATE, OSD_ITEM_4_3_1_STATE+1)) == FALSE)||(OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_4_4_1_STATE, OSD_ITEM_4_4_1_STATE+1)) == FALSE))){
            ucKeyInfoType = OSDKEYINFO_TYPE_DOLE;
        }        
        else if (usOsdState==(OSD_ITEM_4_2_END-1)||usOsdState==(OSD_ITEM_4_3_END-1)||usOsdState==(OSD_ITEM_4_4_END-1))//ULEric140411
            ucKeyInfoType = OSDKEYINFO_TYPE_UOLE;
        else if ((usOsdState==(OSD_ITEM_4_2_END-2)||usOsdState==(OSD_ITEM_4_3_END-2)||usOsdState==(OSD_ITEM_4_4_END-2))\
            && ((OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_4_2_1_STATE, (OSD_ITEM_4_2_END-1))) == FALSE)||(OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_4_3_1_STATE, (OSD_ITEM_4_3_END-1))) == FALSE)||(OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_4_4_1_STATE, (OSD_ITEM_4_4_END-1))) == FALSE))){
            ucKeyInfoType = OSDKEYINFO_TYPE_UOLE;
        }
        else if ((usOsdState==(OSD_ITEM_4_2_END-3)||usOsdState==(OSD_ITEM_4_3_END-3)||usOsdState==(OSD_ITEM_4_4_END-3))\
            && ((OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_4_2_1_STATE, (OSD_ITEM_4_2_END-2))) == FALSE)||(OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_4_3_1_STATE, (OSD_ITEM_4_3_END-2))) == FALSE)||(OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_4_4_1_STATE, (OSD_ITEM_4_4_END-2))) == FALSE))){
            ucKeyInfoType = OSDKEYINFO_TYPE_UOLE;
        }  
#if !lrd_dis_benq
        else if((usOsdState == OSD_ITEM_3_5_1_STATE || usOsdState == OSD_CUSTKEY_DISPLAYMODE_1_STATE) && ((MDState[_MainChannel].InputTiming.usModeVActive == PANEL_HEIGHT)&&(MDState[_MainChannel].InputTiming.usModeHActive == PANEL_WIDTH)))//(DetectAspectRatio() == DSP_SIZE_FULL)
#else     
        else if((usOsdState == OSD_ITEM_3_5_1_STATE || usOsdState == OSD_CUSTKEY_DISPLAYMODE_1_STATE) && ((InputTiming.usModeVActive == PANEL_HEIGHT)&&(InputTiming.usModeHActive == PANEL_WIDTH)))//(DetectAspectRatio() == DSP_SIZE_FULL)
#endif
            ucKeyInfoType = OSDKEYINFO_TYPE_LOK;
		
#if !lrd_dis_benq
		else if ((usOsdState == OSD_ITEM_3_5_2_STATE) && ((MDState[_MainChannel].InputTiming.usModeVActive == PANEL_HEIGHT)&&(MDState[_MainChannel].InputTiming.usModeHActive == PANEL_WIDTH)))
#else
        else if ((usOsdState == OSD_ITEM_3_5_2_STATE) && ((InputTiming.usModeVActive == PANEL_HEIGHT)&&(InputTiming.usModeHActive == PANEL_WIDTH)))
#endif
        {

            ucKeyInfoType = OSDKEYINFO_TYPE_LOK;
        }
		
        #if ENABLE_PICTURE_MODE_ANIMATION == ON        
        else if  (usOsdState == OSD_ITEM_3_1_5_STATE){
            ucKeyInfoType = OSDKEYINFO_TYPE_UDRLE;
        }
        #endif        
        else if  (usOsdState == OSD_ITEM_3_1_7_STATE){
            ucKeyInfoType = OSDKEYINFO_TYPE_UDRLE;
        }
    }
    else if (usOsdState>=OSD_SUBITEM_2_5_4_STATE_BEG&&usOsdState<OSD_SUBITEM_4_1_2_END){ //LAYER_4 OSD
        ucLayer = STRING_LAYER_4;
        ucKeyInfoType = OSDCheckKeyInfo(LAYER_4, usOsdState);

        if (usOsdState == OSD_SUBITEM_4_1_1_1_STATE)
            ucKeyInfoType = OSDKEYINFO_TYPE_DOLE;
        else if (usOsdState == (OSD_SUBITEM_4_1_1_END-1))
            ucKeyInfoType = OSDKEYINFO_TYPE_UOLE;
        else if (usOsdState==OSD_SUBITEM_2_5_4_1_STATE||usOsdState==OSD_SUBITEM_2_5_4_2_STATE)//ULEric140407
            ucKeyInfoType = OSDKEYINFO_TYPE_UDRLE;
        else if (usOsdState==OSD_SUBITEM_2_5_4_3_STATE||usOsdState==OSD_SUBITEM_3_1_3_1_STATE)//ULEric140407
            ucKeyInfoType = OSDKEYINFO_TYPE_UDLE;
    }
    else if ((usOsdState >= OSD_CUSTKEY_PICTUREMODE_1_STATE) && (usOsdState < OSD_CUSTKEY_PICTUREMODE_END)){//Customkey Menu Picture mode
        if (usOsdState == OSD_CUSTKEY_PICTUREMODE_1_STATE){
            ucKeyInfoType = OSDKEYINFO_TYPE_DOLE;
        }
        else if (usOsdState == (OSD_CUSTKEY_PICTUREMODE_END-1)){
            ucKeyInfoType = OSDKEYINFO_TYPE_UOLE;
        }
        else{
            ucKeyInfoType = OSDKEYINFO_TYPE_UDOLE;
        }
        ucOffset = FrameWidthType_CustomerMenu1;//1;
    }
    else if (usOsdState == OSD_INFO_RESETALL_NOTICE_STATE||usOsdState == OSD_INFO_RESETCOLOR_NOTICE_STATE
        ||usOsdState == OSD_INFO_DCR_NOTICE_STATE||usOsdState == OSD_DIRSRC_STATE){
        ucLayer = DIALOG_LAYER;
        //ucKeyInfoType = OSDKEYINFO_TYPE_DIALOG;
        if(usOsdState == OSD_DIRSRC_STATE){
            ucKeyInfoType=OSDKEYINFO_TYPE_UDRL;
    	}
        else{
        ucKeyInfoType=OSDKEYINFO_TYPE_UD;
        }
        ucOffset = 3;
    }
    else if ((usOsdState == OSD_FACT_STATE) || (usOsdState == OSD_SM_STATE)){
            ucKeyInfoType = OSDKEYINFO_TYPE_UDRLE;
    }
    else {
        ucLayer = 0xff;
    }
   
    if (bUpdate == FALSE){
        return ucKeyInfoType;
    }
    
    if ((ucLayer!=0xff) && (!bIsRepeatKey) && (bUpdate == TRUE)) {
        OSDUpdateSelectPageIcon(0,ucOffset,ucKeyInfoType,ucLayer,0);
    }
}

void SetReShowMenuIdx(USHRT usReShowIdx)
{
    
    usTemp_ReShow = usReShowIdx;
}
    
void OSDReShowMenu(void)
{    
    UCHAR i;
    OSDAPI_TurnOffOSD();
    OSDInitialize(TRUE);

    OSDInitFrame(OSD_MAIN_TOTAL_WIDTH, OSD_MAIN_TOTAL_HEIGHT, MAIN_FRAME_COLOR);

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
    
    OSDShowTitleString();   
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
            OSDUnselectLayer2Item(OSD_MAX_LINES-1, FALSE);            
            OSDSelectLayer2Item(OSD_MAX_LINES,FALSE);
            OSDUnselectLayer2Item(OSD_MAX_LINES,FALSE);
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
#if ENABLE_OSD_ROTATION == ON
    if(UserData.bOSDRotation == TRUE){
        OSDSetPosition(ROT_OSD_MAIN_MENU_H_POSITION, ROT_OSD_MAIN_MENU_V_POSITION);
    }
    else
#endif        
    {        
        OSDSetPosition(OSD_MAIN_MENU_H_POSITION, OSD_MAIN_MENU_V_POSITION);
    }    
    SetOSDState(usTemp_ReShow);
    OSDTurnOnOSD();
        
}

//ULEric140401
void OSDUpdateArrowIcon(USHRT usAttr, UCHAR ucType,UCHAR ucLayer)
{
    UCHAR ucPosX;
    if(ucLayer == STRING_LAYER_3)
        ucPosX = LAYER3_PAGE_ARROW_POX;
    else if(ucLayer == STRING_LAYER_4)
        ucPosX = LAYER4_PAGE_ARROW_POX;
    else
        return;
        
    OSDAPI_SetFontAttr(usAttr);
    if(ucType == TopArrowType){    
        // show down arrow           
        OSDAPI_WriteXYChar(TRUE, ucPosX, (Next_PAGE_ARROW_POSY), DownArrow_1);
        OSDAPI_WriteXYChar(TRUE, ucPosX+1, (Next_PAGE_ARROW_POSY), DownArrow_2);
        //OSDAPI_WriteXYChar(TRUE, ucPosX+1, Next_PAGE_ARROW_POSY, DownArrow_3);
        // clear up arrow
        OSDAPI_WriteXYRepeatChar(TRUE, ucPosX, PRE_PAGE_ARROW_POSY, 2, _SPACE_);
    }
    else if(ucType == MiddleArrowType){
        OSDAPI_WriteXYChar(TRUE, ucPosX, PRE_PAGE_ARROW_POSY, UpArrow_1);
        OSDAPI_WriteXYChar(TRUE, ucPosX+1, PRE_PAGE_ARROW_POSY, UpArrow_2);
        // show down arrow
        OSDAPI_WriteXYChar(TRUE, ucPosX,    (Next_PAGE_ARROW_POSY), DownArrow_1);
        OSDAPI_WriteXYChar(TRUE, ucPosX+1,  (Next_PAGE_ARROW_POSY), DownArrow_2);
        //OSDAPI_WriteXYChar(TRUE, ucPosX+1, Next_PAGE_ARROW_POSY, DownArrow_3);
    }
    else if(ucType == LastArrowType){
        // show up arrow
        OSDAPI_WriteXYChar(TRUE, ucPosX, PRE_PAGE_ARROW_POSY, UpArrow_1);
        OSDAPI_WriteXYChar(TRUE, ucPosX+1, PRE_PAGE_ARROW_POSY, UpArrow_2);
        // clear down arrow
        OSDAPI_WriteXYRepeatChar(TRUE, ucPosX, (Next_PAGE_ARROW_POSY), 2, _SPACE_);
        //OSDAPI_WriteXYRepeatChar(TRUE, ucPosX, Next_PAGE_ARROW_POSY, 2, _SPACE_);
    }
    else{//Clear
        // clear up arrow
        OSDAPI_WriteXYRepeatChar(TRUE, ucPosX, PRE_PAGE_ARROW_POSY, 2, _SPACE_);
        // clear down arrow
        OSDAPI_WriteXYRepeatChar(TRUE, ucPosX, (Next_PAGE_ARROW_POSY), 2, _SPACE_);
        //OSDAPI_WriteXYRepeatChar(TRUE, ucPosX, Next_PAGE_ARROW_POSY, 2, _SPACE_);
    }
}

//ULEric140409
void OSDClearKeyColor(BOOL bIsRepratKey)
{    
    USHRT usTempOSDStatus = GetOSDState();
    //if(bIsRepeatKey!=bIsRepratKey)
    //{
        bIsRepeatKey = bIsRepratKey;        
        if(!bIsRepeatKey)
        {
            if(ucKeyInfoStatus!=0xff)
            {
                if (usTempOSDStatus > OSD_TOPPAGE_BEG && usTempOSDStatus <= OSD_DIRECT_3_STATE)
                {
                    //Sleep(60);
                    OSDBlinkSelectPageButton((ucKeyInfoStatus&0x0F), (ucKeyInfoStatus>>4), TRUE);
                    OSDUpdateKeyInfo(TRUE,usTempOSDStatus);
                }
                ucKeyInfoStatus = 0xff;                
            }
        }
        //else{
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
            else if (usStatus == OSD_ITEM_3_2_1_STATE&&UserData.bSensEyeDemo == PICTURE_DUALMODE_OFF && !Clr)
                Result = TRUE;
            else if((usStatus == OSD_SUBITEM_4_1_1_1_STATE) && !Clr)//Layer4
                Result = TRUE;
            else if((usStatus == OSD_MAIN_1_2_STATE) && ((UserData.ucInputSource != INPUT_SC_VGA)||IsComponentInput()) && !Clr)//ULEric140415
                Result = TRUE;
            else if((usStatus == OSD_MAIN_2_3_STATE) && (!OSDIsSubItemValid(OSD_PICTURE_BRIGHTNESS)) && !Clr)//ULEric140415
                Result = TRUE;       
			#if !lrd_dis_benq
            else if((usStatus == OSD_ITEM_3_5_2_STATE || usStatus == OSD_CUSTKEY_DISPLAYMODE_2_STATE) && ((MDState[_MainChannel].InputTiming.usModeVActive == PANEL_HEIGHT)&&(MDState[_MainChannel].InputTiming.usModeHActive == PANEL_WIDTH)) && !Clr)
            #else
            else if((usStatus == OSD_ITEM_3_5_2_STATE || usStatus == OSD_CUSTKEY_DISPLAYMODE_2_STATE) && ((InputTiming.usModeVActive == PANEL_HEIGHT)&&(InputTiming.usModeHActive == PANEL_WIDTH)) && !Clr)
            #endif
                Result = TRUE;
			else if((usStatus == OSD_ITEM_3_5_1_STATE || usStatus == OSD_CUSTKEY_DISPLAYMODE_1_STATE) && (DetectAspectRatio() == DSP_SIZE_FULL) && !Clr)
                Result = TRUE;
            else if( ((usStatus == OSD_ITEM_4_2_1_STATE)&&!Clr)||((usStatus == OSD_ITEM_4_3_1_STATE)&&!Clr)||((usStatus == OSD_ITEM_4_4_1_STATE)&&!Clr) )//Custom key page
                Result = TRUE;
            else if ((usStatus==(OSD_ITEM_4_1_END+1)||usStatus==(OSD_ITEM_4_2_END+1)||usStatus==(OSD_ITEM_4_3_END+1))\
                && !Clr\
                && ((OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_4_2_1_STATE, OSD_ITEM_4_2_1_STATE)) == FALSE)||(OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_4_3_1_STATE, OSD_ITEM_4_3_1_STATE)) == FALSE)||(OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_4_4_1_STATE, OSD_ITEM_4_4_1_STATE)) == FALSE))){
                Result = TRUE;
            }
            else if ((usStatus==(OSD_ITEM_4_1_END+2)||usStatus==(OSD_ITEM_4_2_END+2)||usStatus==(OSD_ITEM_4_3_END+2))\
                && !Clr\
                && ((OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_4_2_1_STATE, OSD_ITEM_4_2_1_STATE+1)) == FALSE)||(OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_4_3_1_STATE, OSD_ITEM_4_3_1_STATE+1)) == FALSE)||(OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_4_4_1_STATE, OSD_ITEM_4_4_1_STATE+1)) == FALSE))){
                Result = TRUE;
            }              
            else if((usStatus == OSD_CUSTKEY_PICTUREMODE_1_STATE)&&!Clr)
                Result = TRUE;        
            //--
#if ENABLE_CUSTOMKEY_CAD == ON                       
            else if((usStatus == OSD_ITEM_4_2_2_STATE)&&!Clr) { //customer key1
            #if ENABLE_CUSTOMKEY_LBL == ON            
                if ((UserData.ucCustomerKey2 == CUSTOMER_KEY_LOWBULELIGHTMODE) || (UserData.ucCustomerKey3 == CUSTOMER_KEY_LOWBULELIGHTMODE))
                    Result = TRUE;
            #endif                
            }
            else if((usStatus == OSD_ITEM_4_3_2_STATE)&&!Clr) { //customer key2
            #if ENABLE_CUSTOMKEY_LBL == ON                        
                if ((UserData.ucCustomerKey1 == CUSTOMER_KEY_LOWBULELIGHTMODE) || (UserData.ucCustomerKey3 == CUSTOMER_KEY_LOWBULELIGHTMODE))                    
                    Result = TRUE;
            #endif    
            }
            else if((usStatus == OSD_ITEM_4_4_2_STATE)&&!Clr) { //customer key3
            #if ENABLE_CUSTOMKEY_LBL == ON                        
                if ((UserData.ucCustomerKey1 == CUSTOMER_KEY_LOWBULELIGHTMODE) || (UserData.ucCustomerKey2 == CUSTOMER_KEY_LOWBULELIGHTMODE))
                    Result = TRUE;
            #endif                
            }
#endif            
            //--
#if ENABLE_CUSTOMKEY_ANIMATION== ON           
            else if((usStatus == OSD_ITEM_4_2_3_STATE)&&!Clr) { //customer key1
            #if ENABLE_CUSTOMKEY_LBL == ON                        
                if (((UserData.ucCustomerKey2 == CUSTOMER_KEY_LOWBULELIGHTMODE) && (UserData.ucCustomerKey3 == CUSTOMER_KEY_PICTUREMODE)) ||\
                    ((UserData.ucCustomerKey3 == CUSTOMER_KEY_LOWBULELIGHTMODE) && (UserData.ucCustomerKey2 == CUSTOMER_KEY_PICTUREMODE)))                
                    Result = TRUE;
            #endif                
            }
            else if((usStatus == OSD_ITEM_4_3_3_STATE)&&!Clr) { //customer key2
            #if ENABLE_CUSTOMKEY_LBL == ON                        
                if (((UserData.ucCustomerKey1 == CUSTOMER_KEY_LOWBULELIGHTMODE) && (UserData.ucCustomerKey3 == CUSTOMER_KEY_PICTUREMODE)) ||\
                    ((UserData.ucCustomerKey3 == CUSTOMER_KEY_LOWBULELIGHTMODE) && (UserData.ucCustomerKey1 == CUSTOMER_KEY_PICTUREMODE)))
                    Result = TRUE;
            #endif                
            }
            else if((usStatus == OSD_ITEM_4_4_3_STATE)&&!Clr) { //customer key3
            #if ENABLE_CUSTOMKEY_LBL == ON                        
                if (((UserData.ucCustomerKey1 == CUSTOMER_KEY_LOWBULELIGHTMODE) && (UserData.ucCustomerKey2 == CUSTOMER_KEY_PICTUREMODE)) ||\
                    ((UserData.ucCustomerKey2 == CUSTOMER_KEY_LOWBULELIGHTMODE) && (UserData.ucCustomerKey1 == CUSTOMER_KEY_PICTUREMODE)))
                    Result = TRUE;
            #endif                
            }
#endif            
#if ENABLE_ERGONOMICS == ON
            else if((usStatus == OSD_MAIN_ERGO_1_STATE)&&!Clr){
                if((UserData.bSmartReminder == OFF)
#if ENABLE_EYE_PROTECT == ON
                    &&(!(isOSDAllowEyeProtect()))&&(!(isOSDAllowEyeProtectMeter()))
#endif
                    ){
                    Result = TRUE;
                }
            }
#endif
#if ENABLE_ECO_SENSOR == ON
            else if((usStatus == OSD_MAIN_ECO_SENSOR_STATE)&&!Clr){
                if(UserData.bECOSensor == OFF){
                    Result = TRUE;
                }
            }
#endif
            //--
            break;

        case 1://Down
            if((usStatus == (OSD_MAIN_2_END-1)||usStatus == (OSD_MAIN_4_END-1))&&!Clr)//Layer2
                Result = TRUE;
            else if((usStatus == (OSD_ITEM_3_1_END-1)) && !Clr)//Layer3:Picture Mode End
                Result = TRUE;
            else if (usStatus == OSD_ITEM_3_2_1_STATE&&UserData.bSensEyeDemo == PICTURE_DUALMODE_OFF && !Clr)
                Result = TRUE;
            else if((usStatus == (OSD_SUBITEM_4_1_1_END-1)) && !Clr)//Layer4
                Result = TRUE;
            else if((usStatus == OSD_MAIN_1_2_STATE) && ((UserData.ucInputSource != INPUT_SC_VGA)||IsComponentInput()) && !Clr)//ULEric140415
                Result = TRUE;
			#if !lrd_dis_benq
            else if((usStatus == OSD_ITEM_3_5_2_STATE || usStatus == OSD_CUSTKEY_DISPLAYMODE_2_STATE) && ((MDState[_MainChannel].InputTiming.usModeVActive == PANEL_HEIGHT)&&(MDState[_MainChannel].InputTiming.usModeHActive == PANEL_WIDTH)) && !Clr)
            #else       
            else if((usStatus == OSD_ITEM_3_5_2_STATE || usStatus == OSD_CUSTKEY_DISPLAYMODE_2_STATE) && ((InputTiming.usModeVActive == PANEL_HEIGHT)&&(InputTiming.usModeHActive == PANEL_WIDTH)) && !Clr)
            #endif
                Result = TRUE;
            else if((usStatus == OSD_ITEM_3_5_1_STATE || usStatus == OSD_CUSTKEY_DISPLAYMODE_1_STATE) && (DetectAspectRatio() == DSP_SIZE_FULL) && !Clr)
                Result = TRUE;            
            else if((usStatus == (OSD_CUSTKEY_PICTUREMODE_END-1))&&!Clr)
                Result = TRUE;     
            else if(((usStatus == (OSD_ITEM_4_2_END-1))&&!Clr)||((usStatus == (OSD_ITEM_4_3_END-1))&&!Clr) ||((usStatus == (OSD_ITEM_4_4_END-1))&&!Clr))
                Result = TRUE;            
            else if ((usStatus==(OSD_ITEM_4_2_END-2)||usStatus==(OSD_ITEM_4_3_END-2)||usStatus==(OSD_ITEM_4_4_END-2))\
                && !Clr\
                && ((OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_4_2_1_STATE, (OSD_ITEM_4_2_END-1))) == FALSE)||(OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_4_3_1_STATE, (OSD_ITEM_4_3_END-1))) == FALSE)||(OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_4_4_1_STATE, (OSD_ITEM_4_4_END-1))) == FALSE))){
                Result = TRUE;
            } 
            else if ((usStatus==(OSD_ITEM_4_2_END-3)||usStatus==(OSD_ITEM_4_3_END-3)||usStatus==(OSD_ITEM_4_4_END-3))\
                && !Clr\
                && ((OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_4_2_1_STATE, (OSD_ITEM_4_2_END-2))) == FALSE)||(OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_4_3_1_STATE, (OSD_ITEM_4_3_END-2))) == FALSE)||(OSDIsLayer3ItemValid(CursorPos(OSD_ITEM_4_4_1_STATE, (OSD_ITEM_4_4_END-2))) == FALSE))){
                Result = TRUE;
            }            
            //--
#if ENABLE_ERGONOMICS == ON            
            //else if((usStatus == OSD_ITEM_4_2_8_STATE)&&!Clr) { //customer key1
            else if((isOSDLastItem(usStatus, OSD_ITEM_4_2_1_STATE, CUSTOMER_KEY_NUM))&&!Clr) { //customer key1            
                if (((UserData.ucCustomerKey2 == CUSTOMER_KEY_INPUT) && (UserData.ucCustomerKey3 == CUSTOMER_KEY_SMARTREMINDER)) ||\
                    ((UserData.ucCustomerKey3 == CUSTOMER_KEY_INPUT) && (UserData.ucCustomerKey2 == CUSTOMER_KEY_SMARTREMINDER)))
                    Result = TRUE;
            }
            //else if((usStatus == OSD_ITEM_4_3_8_STATE)&&!Clr) { //customer key2
            else if((isOSDLastItem(usStatus, OSD_ITEM_4_3_1_STATE, CUSTOMER_KEY_NUM))&&!Clr) { //customer key2                        
                if (((UserData.ucCustomerKey1 == CUSTOMER_KEY_INPUT) && (UserData.ucCustomerKey3 == CUSTOMER_KEY_SMARTREMINDER)) ||\
                    ((UserData.ucCustomerKey3 == CUSTOMER_KEY_INPUT) && (UserData.ucCustomerKey1 == CUSTOMER_KEY_SMARTREMINDER)))
                    Result = TRUE;
            }
//            else if((usStatus == OSD_ITEM_4_4_8_STATE)&&!Clr) { //customer key3
            else if((isOSDLastItem(usStatus, OSD_ITEM_4_4_1_STATE, CUSTOMER_KEY_NUM))&&!Clr) { //customer key3                        
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
                if((UserData.bSmartReminder == OFF)
#if ENABLE_EYE_PROTECT == ON
                    &&(!(isOSDAllowEyeProtect()))&&(!(isOSDAllowEyeProtectMeter()))
#endif
                    ){
                    Result = TRUE;
                }
            }
#endif
#if ENABLE_ECO_SENSOR == ON
            else if((usStatus == OSD_MAIN_ECO_SENSOR_STATE)&&!Clr){
                if(UserData.bECOSensor == OFF){
                    Result = TRUE;
                }
            }   
#endif
            //--
            break;

        case 2://Right or OK
            if((usStatus >= OSD_CUSTKEY_PICTUREMODE_1_STATE && usStatus < OSD_CUSTKEY_BRIGHTNESS_END)&&Clr)//Layer2
                Result = TRUE;
            else if(usStatus == (OSD_SUBITEM_3_1_3_1_STATE)&&!Clr)
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
        case OSD_FITM_STATE:
        case OSD_CUSTKEY_VOLUME_STATE:
        case OSD_CUSTKEY_CONTRAST_STATE:
        case OSD_CUSTKEY_BRIGHTNESS_STATE:
#if ENABLE_OSD_ANALOG_FUNCTION == ON  
        case OSD_ITEM_1_3_STATE:
        case OSD_ITEM_1_4_STATE:
        case OSD_ITEM_1_5_STATE:
        case OSD_ITEM_1_6_STATE:
#endif
        case OSD_ITEM_2_1_STATE:
        case OSD_ITEM_2_2_STATE:
        case OSD_ITEM_2_3_STATE:
        case OSD_ITEM_2_6_STATE:
        case OSD_ITEM_2_7_STATE:
        case OSD_ITEM_Audio_1_1_STATE:
        case OSD_SUBITEM_2_5_4_1_STATE:
        case OSD_SUBITEM_2_5_4_2_STATE:
        case OSD_SUBITEM_2_5_4_3_STATE:    
#if ENABLE_PICTURE_MODE_ANIMATION == ON
        case OSD_SUBITEM_3_1_3_1_STATE:
#endif            
            Result = TRUE;
        break;
    }
    return Result;
}
//ULEric140410
/*
void OSDClearDialogSpaceFrame(UCHAR sw, UCHAR sh, UCHAR ew, UCHAR eh)
{
    UCHAR i;    
    OSDAPI_SetFontAttr(0);
    for(i=0;i<(eh-sh);i++)    
        OSDAPI_WriteXYRepeatChar(TRUE, sw,sh+i, (ew-sw),_SPACE_);
    
}
*/
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
        ucPosX = DIALOG_STR_POSX;
        ucPosY = DIALOG_STR_POSY;
    }
        
    for (i=ucStart;i<8; i++)
        OSDAPI_WriteXYRepeatChar(FALSE, ucPosX, ucPosY+(i*DIALOG_STR_OFFSET_Y), INDENT_STRING_MAX_LEN, _SPACE_);
}

void OSDShowCusKeyHook(UCHAR id, UCHAR CustomerKey)
{    

    switch(CustomerKey)
    {    
#if ENABLE_EYE_PROTECT == ON
        case CUSTOMER_KEY_EYE_PROTECT:
        case CUSTOMER_KEY_EYE_PROTECT_METER:
#endif     
#if ENABLE_ECO_SENSOR == ON
        case CUSTOMER_KEY_ECO_SENSOR:
        case CUSTOMER_KEY_ECO_SENSOR_METER:
#endif
        case CUSTOMER_KEY_MUTE:
            if(id==((!Custom_System.ucOSD_preview_temp)&0x01))
                    OSDAPI_SetFontAttr(SelectedStringColor_256);
            else
                OSDAPI_SetFontAttr(UnSelectedStringColor1_256);
            OSDAPI_WriteXYChar(TRUE, DIALOG_HOOK_POSX, DIALOG_HOOK_POSY+(((!Custom_System.ucOSD_preview_temp)&0x01)*DIALOG_STR_OFFSET_Y), Hook_Icon);
            break;
        case CUSTOMER_KEY_INPUT:
            if(id==(GetInputPortIndex(Custom_System.ucOSD_preview_temp)))
                    OSDAPI_SetFontAttr(SelectedStringColor_256);
            else
                OSDAPI_SetFontAttr(UnSelectedStringColor1_256);
            OSDAPI_WriteXYChar(TRUE, DIALOG_HOOK_POSX, DIALOG_HOOK_POSY+((GetInputPortIndex(Custom_System.ucOSD_preview_temp))*DIALOG_STR_OFFSET_Y), Hook_Icon);
            break;
        case CUSTOMER_KEY_DISPLAYMODE:
            if(id==Custom_System.ucOSD_preview_temp)
                    OSDAPI_SetFontAttr(SelectedStringColor_256);
            else
                OSDAPI_SetFontAttr(UnSelectedStringColor1_256);
            OSDAPI_WriteXYChar(TRUE, DIALOG_HOOK_POSX, DIALOG_HOOK_POSY+(Custom_System.ucOSD_preview_temp*DIALOG_STR_OFFSET_Y), Hook_Icon);
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
                    OSDAPI_WriteXYChar(TRUE, DIALOG_HOOK_POSX, DIALOG_HOOK_POSY+((Custom_System.ucOSD_preview_temp-8)*DIALOG_STR_OFFSET_Y), Hook_Icon);
                }else
                    OSDAPI_WriteXYChar(TRUE, DIALOG_HOOK_POSX, DIALOG_HOOK_POSY+(Custom_System.ucOSD_preview_temp*DIALOG_STR_OFFSET_Y), Hook_Icon);
            }else{
                OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
                if(Custom_System.ucOSD_preview_temp>7)
                    OSDAPI_WriteXYChar(TRUE, DIALOG_HOOK_POSX, DIALOG_HOOK_POSY+((Custom_System.ucOSD_preview_temp-8)*DIALOG_STR_OFFSET_Y), _SPACE_);
                else{
                    OSDAPI_WriteXYChar(TRUE, DIALOG_HOOK_POSX, DIALOG_HOOK_POSY+(Custom_System.ucOSD_preview_temp*DIALOG_STR_OFFSET_Y), _SPACE_);
            }
            }
            break;
#if ENABLE_CUSTOMKEY_ANIMATION == ON ||  ENABLE_CUSTOMKEY_LBL == ON  
        case CUSTOMER_KEY_ANIMATION_MODE:
        case CUSTOMER_KEY_LOWBULELIGHTMODE://ULEric140407
            if(id==Custom_System.ucOSD_preview_temp)
                    OSDAPI_SetFontAttr(SelectedStringColor_256);
            else
                OSDAPI_SetFontAttr(UnSelectedStringColor1_256);
            OSDAPI_WriteXYChar(TRUE, DIALOG_HOOK_POSX, DIALOG_HOOK_POSY+(Custom_System.ucOSD_preview_temp*DIALOG_STR_OFFSET_Y), Hook_Icon);    
            break;
#endif                         
#if ENABLE_ERGONOMICS == ON                                             
        case CUSTOMER_KEY_SMARTREMINDER://ULEric140411
            if(id==((!Custom_System.ucOSD_preview_temp)&0x01))
                    OSDAPI_SetFontAttr(SelectedStringColor_256);
            else
                OSDAPI_SetFontAttr(UnSelectedStringColor1_256);
            OSDAPI_WriteXYChar(TRUE, DIALOG_HOOK_POSX, DIALOG_HOOK_POSY+(((!Custom_System.ucOSD_preview_temp)&0x01)*DIALOG_STR_OFFSET_Y), Hook_Icon);    
            break;
#endif            
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
        ucPosX = LAYER3_POSX+HOOK_LAYER3_OFFSET_X;
    else if(ucLayer == STRING_LAYER_4)
        ucPosX = LAYER4_POSX+HOOK_LAYER4_OFFSET_X;
    else
        return;
    
    OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
    for(i=0;i<8;i++)
        OSDAPI_WriteXYChar(TRUE, ucPosX, LAYER_STR_POSY+(i*HOOK_OFFSET_Y),_SPACE_);
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

    OSDAPI_DisableSplit();
    if (!IsOSDSysInit() || bForceInit) {
        SetOSDSysInitFlag();

        OSDAPI_SetFontSize(OSD_FONT_12X18);
        OSDAPI_SetOSDWinSizeUnit(1, 1);
        OSDLoadFont(LoadPalette);

        //frame size = w:95 h:35
        //one bit size = (?)x18/2 = 1692
        //two bit size = 60*18 = 144
        //four bit size= 12*18*2 = 792
#if ENABLE_OSD_ROTATION == ON
        OSDAPI_Set1BitFontAddr(OSDSRAM_ADDR_CEILING(OSDAPI_GetOSDFrameSize(OSD_MAIN_TOTAL_WIDTH, OSD_MAIN_TOTAL_HEIGHT)));
        OSDAPI_Set2BitsFontAddr(OSDSRAM_ADDR_FLOOR(OSD_ROT_RAM_SIZE - 36*50 - 18*60));
        OSDAPI_Set4BitsFontAddr(OSDSRAM_ADDR_FLOOR(OSD_ROT_RAM_SIZE - 36*50));
#else
        //frame size = w:69 h:23
        //one bit size = ?
        //two bit size = ?
        //four bit size= ?
        //OSDAPI_Set1BitFontAddr(OSDAPI_GetOSDFrameSize(69, 23));

        // temperary use large memory for two bit font.
        //OSDAPI_Set2BitsFontAddr(OSD_RAM_SIZE - 36*12 - 18*60);
        //OSDAPI_Set4BitsFontAddr(OSD_RAM_SIZE - 36*12);
        OSDAPI_Set1BitFontAddr(OSDSRAM_ADDR_CEILING(OSDAPI_GetOSDFrameSize(OSD_MAIN_TOTAL_WIDTH, OSD_MAIN_TOTAL_HEIGHT)));
        OSDAPI_Set2BitsFontAddr(OSDSRAM_ADDR_FLOOR(OSD_ROT_RAM_SIZE - 36*50 - 18*60));
        OSDAPI_Set4BitsFontAddr(OSDSRAM_ADDR_FLOOR(OSD_ROT_RAM_SIZE - 36*50));
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

    OSDInitFrame(OSD_MAIN_TOTAL_WIDTH, OSD_MAIN_TOTAL_HEIGHT, MAIN_FRAME_COLOR);

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

    OSDShowTitleString();
    OSDShowMainMenuStrings();
    
#if LAYER_INDENT_COUNT == ON
    // after showing layer1 string, the layer2 string start index is fixed and has been recorded by below function.
    fnResetLayerIndentCount(STRING_LAYER_2);
#endif

    OSDSelectLayer1Item(0);
    UserSetTransparent();

#if ENABLE_OSD_ROTATION == ON
    if(UserData.bOSDRotation == TRUE){
        OSDSetPosition(ROT_OSD_MAIN_MENU_H_POSITION, ROT_OSD_MAIN_MENU_V_POSITION);
    }
    else
#endif        
    {        
        OSDSetPosition(OSD_MAIN_MENU_H_POSITION, OSD_MAIN_MENU_V_POSITION);
    }

    OSDTurnOnOSD();
}

void OSDShowTitleString(void)
{
    UCHAR x = 0;
    OSDAPI_SetIndentIndex(String_Layer1_Index);
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    bSelectTable = OSDFontTble1;    
    if(UserData.ucLanguage == OSDLANG_ARAB){
        x = Araboffset3;            
    }

    OSDAPI_SetFontAttr(MAINMENU_TITLE);    
    ShowIndentString(TRUE, OSD_TITLESTR_OFFSET_X+OSD_POSITION_OFFSET+x, 1, 22, ModeTitleTab[UserData.ucBFMode*NUM_OSDLANGS + UserData.ucLanguage]);    
}


UCHAR OSDGetCustomKeyPage1Num(void)
{
    UCHAR cnt = 0;
    if(UserData.ucCustomerKey1<=CUSTOMER_KEY_VOLUME)
        cnt++;
    if(UserData.ucCustomerKey2<=CUSTOMER_KEY_VOLUME)
        cnt++;
    if(UserData.ucCustomerKey3<=CUSTOMER_KEY_VOLUME)
        cnt++;

    return cnt;
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
    UCHAR tmp;
 
    isUp = isUp;


    OSDAPI_OSDWinOff(OSD_WINDOW1);

    tmp = (id > 7)? (id-8):id;

    // string row
    OSDAPI_FillLineAttr(DIALOG_STR_POSX, DIALOG_STR_POSY+tmp*DIALOG_STR_OFFSET_Y, DIALOG_INDENT_STRING_MAX_LEN, UnSelectedStringColor_256);

    // redraw separater line to gray color
//    if (isUp && id != 7) {
    OSDAPI_FillLineAttr(DIALOG_STR_POSX, DIALOG_STR_POSY+tmp*DIALOG_STR_OFFSET_Y+1, INDENT_STRING_MAX_LEN, StringSeparaterLineColor1);
//    }
//    else {
    OSDAPI_FillLineAttr(DIALOG_STR_POSX, DIALOG_STR_POSY+tmp*DIALOG_STR_OFFSET_Y-1, INDENT_STRING_MAX_LEN, StringSeparaterLineColor1);
//    }

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
    OSDClearItemHookIcon(Layer);//add0823
    OSDAPI_SetFontAttr(Attr);
    //printf("jim show hook icon, id = %d, layer = %d\n", (USHRT)id, (USHRT)Layer);
    switch (Layer) {
        case STRING_LAYER_3:           
            switch (ucMenuType) {
                case OSD_MAIN_DISPLAY:
                    switch (id) {
#if ENABLE_AUTO_POVIT_FUNC == ON  
                        case OSD_DISPLAY_PIVOT:
                            //Auto Pivot
                                OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+(1-UserData.bAutoPivot)*HOOK_OFFSET_Y, font);
                        break;
#endif
#if ENABLE_OSD_ANALOG_FUNCTION == ON
                        case OSD_DISPLAY_ADJUST:
#endif
                        case OSD_DISPLAY_INPUT:
                            switch (UserData.ucInputSource) 
                            {
                            #if 0
                                case INPUT_SC_VGA:
                                    OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+0*HOOK_OFFSET_Y, font);
                                    break;
                                case INPUT_SC_DVI:
                                    OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+1*HOOK_OFFSET_Y, font);
                                    break;
                                case INPUT_SC_HDMI:
                                    OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+2*HOOK_OFFSET_Y, font);
                                    break;
                                case INPUT_SC_DP:
                                    OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+3*HOOK_OFFSET_Y, font);       
                                    break;
                            #else
                            case INPUT_SC_HDMI:
                                OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+2*HOOK_OFFSET_Y, font);
                                break;
                            case INPUT_SC_DP:
                                OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+1*HOOK_OFFSET_Y, font);       
                                    break;
                            case INPUT_SC_DVI:
                                OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+0*HOOK_OFFSET_Y, font);       
                                    break;                    
                            #endif
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
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+ GetGammaNum()*HOOK_OFFSET_Y, font);
                        break;
                        case OSD_PICTURE_COLORTEMP:
                        //printf("ucColorTemp = %02BX\r\n",UserData.ucColorTemp);
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+UserData.ucColorTemp*HOOK_OFFSET_Y, font);
                        break;
                        case OSD_PICTURE_RESETCOLOR:// usOSDState == OSD_ITEM_2_8_1_STATE
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+1*HOOK_OFFSET_Y, font);
                        break;
                        case OSD_PICTURE_AMA://usOSDState == OSD_ITEM_2_9_1_STATE
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+UserData.ucODMode*HOOK_OFFSET_Y, font);
                        break;
                        default:
                        break;
                    }
                break;
                case OSD_MAIN_PICTURE_ADVANCED:
                    switch (id) {
                        case OSD_PICTURE_AD_PIC:
                        //printf("ucBFMode = %02BX\r\n",UserData.ucBFMode);
                        #if 0
                            if(UserData.ucBFMode>(OSD_MAX_LINES-1))//ULEric140401                        
                                OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+(UserData.ucBFMode-OSD_MAX_LINES)*HOOK_OFFSET_Y, font);
                            else
                                OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+UserData.ucBFMode*HOOK_OFFSET_Y, font);
                            break;
                        #else
                        if(Custom_System.ucOSD_preview_temp>(OSD_MAX_LINES-1)){ 
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+(Custom_System.ucOSD_preview_temp-OSD_MAX_LINES)*HOOK_OFFSET_Y, font);
                        }
                        else{
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+Custom_System.ucOSD_preview_temp*HOOK_OFFSET_Y, font);
                        }
                        break;
                        #endif
                        case OSD_PICTURE_AD_SENSEYE:
                            /*
                            if(UserData.bSensEyeDemo == 0){
                                OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+(1-UserData.bSensEyeDemo)*HOOK_OFFSET_Y, font);
                            }else  {        
                                OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+(UserData.ucDualViewMode+1)*HOOK_OFFSET_Y, font);
                            }   
                            */   
                            if(UserData.bSensEyeDemo == PICTURE_DUALMODE_OFF){
                                OSDAPI_SetFontAttr(DisabledStringColor_256);
                            }
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+(UserData.ucDualViewMode)*HOOK_OFFSET_Y, font);
                            break;
                        case OSD_PICTURE_AD_DCR:                        
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+(1-UserData.bDCRMode)*HOOK_OFFSET_Y, font);
                            break;  
#if MD_ENABLE_OVERSCAN == ON                                    
                        case OSD_PICTURE_AD_OVERSCAN:
                        //printf("OverScan = %02BX\r\n",UserData.bOverScan);
                            if(IsComponentInput())
                                OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+(1-UserData.bSOGOverScan)*HOOK_OFFSET_Y, font);
                            else
                                OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+(1-UserData.bOverScan)*HOOK_OFFSET_Y, font);
                            break;
#endif
                        case OSD_PICTURE_AD_DISMODE:
                            //Color Format UserData.ucAspectRatio
                            //printf("ucAspectRatio = %02BX\r\n",UserData.ucAspectRatio);
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+UserData.ucAspectRatio*HOOK_OFFSET_Y, font);
                            break;
#if ENABLE_COLOR_FORMAT == ON                            
                        case OSD_PICTURE_AD_COLORFORMAT:                            
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+UserData.bColorFormat*HOOK_OFFSET_Y, font);
                            break;    
#endif                            
                        case OSD_PICTURE_AD_PCRANGE:
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+UserData.ucHDMIRGBRange*HOOK_OFFSET_Y, font);                            
                            break;                                
                        default:
                            break;
                    }
                break;
                case OSD_MAIN_AUDIO:
                     switch (id) {
                        case OSD_AUDIO_MUTE:
                            //printf("Mute = %02BX\r\n",UserData.bAudioMute);
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+(1-UserData.bAudioMute)*HOOK_OFFSET_Y, font);
                            break;
#if ENABLE_AUDIO_SELECT == ON                                
                        case OSD_AUDIO_SELECT:
                            if(UserData.ucInputSource == INPUT_SC_HDMI){
                                OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+UserData.ucHDMIAudioSelect*HOOK_OFFSET_Y, font);
                            }
                            else if(UserData.ucInputSource == INPUT_SC_DP){
                                OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+UserData.ucDPAudioSelect*HOOK_OFFSET_Y, font);
                            }
                            else{
                                OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+UserData.ucAudioSelect*HOOK_OFFSET_Y, font);
                            }                            
                            break;
#endif                            
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
                                OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+(UserData.ucCustomerKey1-OSD_MAX_LINES)*HOOK_OFFSET_Y, font);
                            }
                            else{                
                               OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+UserData.ucCustomerKey1*HOOK_OFFSET_Y, font);
                            }
                            break;

                        case OSD_SYS_CTKEY2:
                        //CustomerKey2
                        //printf("ucCustomerKey2 = %02BX\r\n",UserData.ucCustomerKey2);
                            if(UserData.ucCustomerKey2>(OSD_MAX_LINES-1))//ULEric140401
                                OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+(UserData.ucCustomerKey2-OSD_MAX_LINES)*HOOK_OFFSET_Y, font);
                            else
                                OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+UserData.ucCustomerKey2*HOOK_OFFSET_Y, font);
                            break;

                        case OSD_SYS_CTKEY3:
                        //CustomerKey3
                        //printf("ucCustomerKey3 = %02BX\r\n",UserData.ucCustomerKey3);
                            if(UserData.ucCustomerKey3>(OSD_MAX_LINES-1))//ULEric140401
                                OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+(UserData.ucCustomerKey3-OSD_MAX_LINES)*HOOK_OFFSET_Y, font);
                            else
                                OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+UserData.ucCustomerKey3*HOOK_OFFSET_Y, font);
                            break;

                        case OSD_SYS_DDCCI:
                        //DDC/CI UserData.bDDCCI
                        //printf("bDDCCI = %02BX\r\n",UserData.bDDCCI);
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+(1-UserData.bDDCCI)*HOOK_OFFSET_Y, font);
                            break;
                    #if ENABLE_DPHDMI_AUTO_SWITCH == ON    
                        case OSD_SYS_DPASWITCH:                     
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+(1-UserData.bDPAutoSwitch)*HOOK_OFFSET_Y, font);
                            break;
                        case OSD_SYS_HDASWITCH:                       
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+(1-UserData.bHDMIAutoSwitch)*HOOK_OFFSET_Y, font);
                            break;
                    #endif
                        case OSD_SYS_AUTO_POWEROFF:
                        //Auto Power Off UserData.ucAutoPowerOffTime
                        //printf("ucAutoPowerOffTime = %02BX\r\n",UserData.ucAutoPowerOffTime);                         
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+UserData.ucAutoPowerOffTime*HOOK_OFFSET_Y, font);
                            break;
                        case OSD_SYS_RES:
                            //UserData.ucResNotice            
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+(1-UserData.bResNotice)*HOOK_OFFSET_Y, font);
                            break;
                        case OSD_SYS_INFORMATION:
                            //OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+11, ucLayer3MItem1InfoTb[1]+0*2, Hook_Icon);//ULeric140401
                            break;
                        case OSD_SYS_DISPLAYPORT:
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+UserData.bDPVersion*HOOK_OFFSET_Y, font);
                            break;                            
                        case OSD_SYS_RECALL:
                        //Reset All
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+1*HOOK_OFFSET_Y, font);
                            break;

                        case OSD_SYS_OSDSET:
                        //case 7:
                        default:
                            break;
                    }
                break;
#if ENABLE_ERGONOMICS == ON
                case OSD_MAIN_ERGONOMICS:
                    switch (id) {
#if ENABLE_EYE_PROTECT == ON                        
                        case OSD_ERGONOMICS_EYE_PROTECT:
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+(1-UserData.bEyeProtect)*HOOK_OFFSET_Y, font);
                            break;
                        case OSD_ERGONOMICS_EYE_PROTECT_METER:
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+(1-UserData.bEyeProtectMeter)*HOOK_OFFSET_Y, font);                           
                            break;
#endif                            
                        case OSD_ERGONOMICS_REMIDER:
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+(1-UserData.bSmartReminder)*HOOK_OFFSET_Y, font);
                            break;
                        case OSD_ERGONOMICS_TIME:
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+UserData.ucErgoTime*HOOK_OFFSET_Y, font);
                            break;
                        case OSD_ERGONOMICS_DURATION:
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+UserData.ucErgoDuration*HOOK_OFFSET_Y, font);
                            break;                        
                        default:
                            break;
                    }
                break;
#endif
#if ENABLE_ECO_SENSOR == ON                                       
                case OSD_MAIN_ECO:
                    switch (id) {
                        case OSD_ECO_SENSOR:
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+(1-UserData.bECOSensor)*HOOK_OFFSET_Y, font);
                            break;
                        case OSD_ECO_SENSOR_METER:
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+(1-UserData.bECOSensorMeter)*HOOK_OFFSET_Y, font);
                            break;
                        case OSD_ECO_SENSOR_RANGE:
                            OSDAPI_WriteXYChar(TRUE, ucLayer3MItem1InfoTb[0]+HOOK_LAYER3_OFFSET_X, ucLayer3MItem1InfoTb[1]+UserData.ucSensorRange*HOOK_OFFSET_Y, font);
                            break;                        
                        default:
                            break;
                    }
                break;
#endif                
            }
        break;
        case STRING_LAYER_4:
            if (ucMenuType == OSD_MAIN_SYSTEM && ucSubMenuType == OSD_SYS_OSDSET) {//ULEric140401
                if (id == OSD_SYS_OSDSET_LANG) {
                    // Language
                    #if 0 //  0 lrd add 
                    OSDAPI_WriteXYChar(TRUE, ucLayer4ItemInfoTb[1]+HOOK_LAYER4_OFFSET_X, ucLayer4ItemInfoTb[2]+(LangItemToPoint(UserData.ucLanguage)-((LangItemToPoint(UserData.ucLanguage)/8)*8))*HOOK_OFFSET_Y, font);//ULEric140401   
                    #else                    
                    OSDAPI_WriteXYChar(TRUE, ucLayer4ItemInfoTb[1]+HOOK_LAYER4_OFFSET_X, ucLayer4ItemInfoTb[2]+((UserData.ucLanguage)-(((UserData.ucLanguage)/8)*8))*HOOK_OFFSET_Y, font);//ULEric140401   
                    #endif
                }
                else if (id == OSD_SYS_OSDSET_TIMER) {
                    // DisplayTime
                    #if 0 // 0 lrd add 
                    OSDAPI_WriteXYChar(TRUE, ucLayer4ItemInfoTb[4]+HOOK_LAYER4_OFFSET_X, ucLayer4ItemInfoTb[5]+((UserData.ucOSDTimer/5)-1)*HOOK_OFFSET_Y, font);//ULEric140401
                    #else 
                    OSDAPI_WriteXYChar(TRUE, ucLayer4ItemInfoTb[4]+HOOK_LAYER4_OFFSET_X, ucLayer4ItemInfoTb[5]+((UserData.ucOSDTimer/5)-1)*HOOK_OFFSET_Y, font);//ULEric140401
                    #endif
                }
            }else if(ucMenuType == OSD_MAIN_PICTURE_ADVANCED && ucSubMenuType == OSD_PICTURE_AD_PIC){//ULEric140402
                if(id == PICTURE_MODE_LOW_BL){
            // LBL Mode
                    OSDAPI_WriteXYChar(TRUE, LAYER4_POSX+HOOK_LAYER4_OFFSET_X, LAYER_STR_POSY+(UserData.ucLBLMode)*HOOK_OFFSET_Y, font);//ULEric140402
                }
            }else if(ucMenuType == OSD_MAIN_PICTURE_ADVANCED && ucSubMenuType == OSD_PICTURE_AD_SENSEYE){//ULEric140402
                if(id == PICTURE_DUALMODE_ON){
                    OSDAPI_WriteXYChar(TRUE, ucLayer4ItemInfoTb[7]+HOOK_LAYER4_OFFSET_X, ucLayer4ItemInfoTb[8]+UserData.bSensEyeDemo*HOOK_OFFSET_Y, font);//ULEric140401
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
    USHRT attr;
    UCHAR x = 0;

    // clear layer1 windows
    OSDAPI_OSDWinOff(OSD_WINDOW1);
    OSDAPI_OSDWinOff(OSD_WINDOW3);
    OSDAPI_OSDWinOff(OSD_WINDOW4);
    if(UserData.ucLanguage == OSDLANG_ARAB){
        x = 0;//Araboffset2;
    }

    // redraw string separater color except icon part
    OSDAPI_FillLineAttr(ucLayer1StringInfoTb[0]-4-x, ucLayer1StringInfoTb[1]+id*LAYER_STR_OFFSET_Y-1, LAYER1_LENGTH, UnSelectedStringColor);
    OSDAPI_FillLineAttr(ucLayer1StringInfoTb[0]-4-x, ucLayer1StringInfoTb[1]+id*LAYER_STR_OFFSET_Y+1, LAYER1_LENGTH, UnSelectedStringColor);

    // redraw layer1 string color
    for (i=0; i<MAINMENU_ICON_NUM; i++) {
        if (i == id) {
            OSDAPI_FillLineAttr(ucLayer1StringInfoTb[0]-x, ucLayer1StringInfoTb[1]+i*LAYER_STR_OFFSET_Y, LAYER1_LENGTH-4, SelectedStringColor1);    
        }
        else {
            if(i == MainIcon_ECO){
                if(UserData.bOSDRotation == TRUE)
                    attr = DisabledStringColor;
                else
                    attr = UnSelectedStringColor;
            }
            else{
                attr = UnSelectedStringColor;
            }
            
            if(UserData.ucLanguage == OSDLANG_ARAB){
                OSDAPI_FillLineAttr(ucLayer1StringInfoTb[0]-4-x, ucLayer1StringInfoTb[1]+i*LAYER_STR_OFFSET_Y, LAYER1_LENGTH-4, attr);
            }
            else{
                OSDAPI_FillLineAttr(ucLayer1StringInfoTb[0]-x, ucLayer1StringInfoTb[1]+i*LAYER_STR_OFFSET_Y, LAYER1_LENGTH-4, attr);
            }
        }
    }

    if(UserData.ucLanguage == OSDLANG_ARAB){
        x = Araboffset1 ;
    }

    // redraw icon color
    for (i=0; i<MAINMENU_ICON_NUM; i++) {
        if (i == id) {
            OSDAPI_FillLineAttr(ucMainIconPos[i*2]+x, ucMainIconPos[i*2+1], 3, SelectedStringColor1);
            OSDAPI_FillLineAttr(ucMainIconPos[i*2]+x, ucMainIconPos[i*2+1]+1, 3, SelectedStringColor1);
        }
        else {
            if(i == MainIcon_ECO){
                if(UserData.bOSDRotation == TRUE)
                    attr = DisabledStringColor;
                else
                    attr = UnSelectedStringColor;
            }
            else{
                attr = UnSelectedStringColor;
            }
            OSDAPI_FillLineAttr(ucMainIconPos[i*2]+x, ucMainIconPos[i*2+1], 3, attr);
            OSDAPI_FillLineAttr(ucMainIconPos[i*2]+x, ucMainIconPos[i*2+1]+1, 3, attr);
        }
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
    OSDDisableLayerWindow();
   // redraw up down icon to white
    if (IsPage2)
        OSDAPI_FillLineAttr(LAYER2_PAGE_ARROW_POX, 3, 2, ArrowColor2);
    else {
        OSDAPI_FillLineAttr(LAYER2_PAGE_ARROW_POX+1, 21, 1, ArrowColor2);
        OSDAPI_FillLineAttr(LAYER2_PAGE_ARROW_POX, 20, 2, ArrowColor2);
    } //!!need to check

    // redraw layer2 string color
     if (ucLayer2ItmNumTb[ucMenuType] >8) {
        //printf("jim 1: id = %d, ucMenuType = %d, value = %d\n", (USHRT)id, (USHRT)ucMenuType, (USHRT)(ucLayer2ItmNumTb[ucMenuType]-8));

        if (IsPage2) {
            for (i=0; i<(ucLayer2ItmNumTb[ucMenuType]-8); i++) {
                if (OSDIsSubItemValid(i) == FALSE) {
                    OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, DisabledStringColor);
                }
                else{             
                    OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, UnSelectedStringColor);
                }                
            }
        }
        else {
            for (i=0; i<8; i++) {
                if (OSDIsSubItemValid(i) == FALSE) {
                    OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, DisabledStringColor);
                }
                else{             
                    OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, UnSelectedStringColor);
                }                
            }
        }
    }
    else {
        //printf("jim 2: id = %d, ucMenuType = %d, value = %d\n", (USHRT)id, (USHRT)ucMenuType, (USHRT)(ucLayer2ItmNumTb[ucMenuType]));
        for (i=0; i<ucLayer2ItmNumTb[ucMenuType]; i++) {
            if (OSDIsSubItemValid(i) == FALSE) {
                OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, DisabledStringColor);
            }
            else{                         
                OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, UnSelectedStringColor);
            }
        }
    }
    // redarw layer2 selected string to Blue color
    if (IsPage2) {
        id = id-8;
    }
    OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+id*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, StringColor1);

    // redraw string separater color
    OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]-1+id*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, UnSelectedStringColor);
    OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+1+id*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, UnSelectedStringColor);

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
    OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]-1+id*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, UnSelectedStringColor);
    OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+1+id*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, UnSelectedStringColor);

    // redraw layer3 string color
//    for (i=0; i<OSDGetLayer3ItemNum(ucMenuType,ucSubMenuType); i++) {
    for (i=0; i<(OSDCheckL3ItemNum(ucMenuType,ucSubMenuType,8)); i++) {
        
        if (i == id) {
            OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, StringColor1_256);
        }
        else {
            if(GetOSDState() != OSD_ITEM_3_2_1_STATE){
                OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, UnSelectedStringColor_256);
            }
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

    if (ucMenuType == OSD_MAIN_PICTURE && ucSubMenuType == OSD_PICTURE_COLORTEMP && id == 3) {
        OSDShowGGain(FALSE, FALSE);
        OSDShowBGain(FALSE, FALSE);
        OSDShowRGain(TRUE, FALSE);
    }
    else if(ucMenuType == OSD_MAIN_PICTURE_ADVANCED && ucSubMenuType == OSD_PICTURE_AD_PIC && id == PICTURE_MODE_ANIMATION){
        OSDShowLayer4SliderBar(SLIBAR_ANIMATION_LAYER4, FALSE);
    }
    else if (ucMenuType == OSD_MAIN_AUDIO && ucSubMenuType == OSD_AUDIO_VOLUME) {
        // redraw layer4 string to white color
        for (i=0; i<(ucLayer4ItemInfoTb[ucLayer3MenuType*3]>OSD_MAX_LINES? OSD_MAX_LINES:ucLayer4ItemInfoTb[ucLayer3MenuType*3]); i++) {
            if (i == id) {
                // redraw layer4 selected string to Black color
                OSDAPI_FillLineAttr(ucLayer4ItemInfoTb[ucLayer3MenuType*3+1], ucLayer4ItemInfoTb[ucLayer3MenuType*3+2]+id*LAYER_STR_OFFSET_Y, 13, SelectedStringColor_256);

                // redraw string separater to blue color
                OSDAPI_FillLineAttr(ucLayer4ItemInfoTb[ucLayer3MenuType*3+1], ucLayer4ItemInfoTb[ucLayer3MenuType*3+2]-1+id*LAYER_STR_OFFSET_Y, 13, StringSeparaterLineColor2);
                OSDAPI_FillLineAttr(ucLayer4ItemInfoTb[ucLayer3MenuType*3+1], ucLayer4ItemInfoTb[ucLayer3MenuType*3+2]+1+id*LAYER_STR_OFFSET_Y, 13, StringSeparaterLineColor2);
            }
            else {
                OSDAPI_FillLineAttr(ucLayer4ItemInfoTb[ucLayer3MenuType*3+1], ucLayer4ItemInfoTb[ucLayer3MenuType*3+2]+i*LAYER_STR_OFFSET_Y, 13, UnSelectedStringColor1_256);
            }
        }

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

    code UCHAR ucIcon_Display_IndexTab1[] = {
        Icon_display_1, Icon_display_2, Icon_display_3,
    };
    code UCHAR ucIcon_Display_IndexTab2[] = {
        Icon_display_4, Icon_display_5, Icon_display_6,
    };
    code UCHAR ucIcon_Picture_IndexTab1[] = {
        Icon_Picture_1, Icon_Picture_2, Icon_Picture_3,
    };
    code UCHAR ucIcon_Picture_IndexTab2[] = {
        Icon_Picture_4, Icon_Picture_5, Icon_Picture_6,
    };
    code UCHAR ucIcon_PictureAd_IndexTab1[] = {
        Icon_PictureAd_1, Icon_PictureAd_2, Icon_PictureAd_3,
    };
    code UCHAR ucIcon_PictureAd_IndexTab2[] = {
        Icon_PictureAd_4, Icon_PictureAd_5, Icon_PictureAd_6,
    };
    code UCHAR ucIcon_Audio_IndexTab1[] = {
        Icon_Audio_1, Icon_Audio_2, Icon_Audio_3,
    };
    code UCHAR ucIcon_Audio_IndexTab2[] = {
        Icon_Audio_4, Icon_Audio_5, Icon_Audio_6,
    };
    code UCHAR ucIcon_System_IndexTab1[] = {
        Icon_System_1, Icon_System_2, Icon_System_3,
    };
    code UCHAR ucIcon_System_IndexTab2[] = {
        Icon_System_4, Icon_System_5, Icon_System_6,
    };
    code UCHAR ucIcon_Ergonomics_IndexTab1[] = {
        Icon_Ergonomics_1, Icon_Ergonomics_2, Icon_Ergonomics_3,
    };
    code UCHAR ucIcon_Ergonomics_IndexTab2[] = {
        Icon_Ergonomics_4, Icon_Ergonomics_5, Icon_Ergonomics_6,
    };
    code UCHAR ucIcon_ECO_IndexTab1[] = {
        Icon_ECO_1, Icon_ECO_2, Icon_ECO_3,
    };
    code UCHAR ucIcon_ECO_IndexTab2[] = {
        Icon_ECO_4, Icon_ECO_5, Icon_ECO_6,
    };
    
    UCHAR x = 0;

     if(UserData.ucLanguage == OSDLANG_ARAB){
       x = Araboffset1 ;
     }
    OSDAPI_SetFontAttr(MAINICON_1BIT_COLOR1);
    switch (id) {
        case MainIcon_Display:
            OSDAPI_WriteXYString(TRUE, ucMainIconPos[id*2]+x, ucMainIconPos[id*2+1], 3, ucIcon_Display_IndexTab1);
            OSDAPI_WriteXYString(TRUE, ucMainIconPos[id*2]+x, ucMainIconPos[id*2+1]+1, 3, ucIcon_Display_IndexTab2);
            break;
        case MainIcon_Picture:
            OSDAPI_WriteXYString(TRUE, ucMainIconPos[id*2]+x, ucMainIconPos[id*2+1], 3, ucIcon_Picture_IndexTab1);
            OSDAPI_WriteXYString(TRUE, ucMainIconPos[id*2]+x, ucMainIconPos[id*2+1]+1, 3, ucIcon_Picture_IndexTab2);
            break;
        case MainIcon_PictureAdvance:
            OSDAPI_WriteXYString(TRUE, ucMainIconPos[id*2]+x, ucMainIconPos[id*2+1], 3, ucIcon_PictureAd_IndexTab1);
            OSDAPI_WriteXYString(TRUE, ucMainIconPos[id*2]+x, ucMainIconPos[id*2+1]+1, 3, ucIcon_PictureAd_IndexTab2);
            break;
        case MainIcon_Audio:
            OSDAPI_WriteXYString(TRUE, ucMainIconPos[id*2]+x, ucMainIconPos[id*2+1], 3, ucIcon_Audio_IndexTab1);
            OSDAPI_WriteXYString(TRUE, ucMainIconPos[id*2]+x, ucMainIconPos[id*2+1]+1, 3, ucIcon_Audio_IndexTab2);
            break;
        case MainIcon_System:
            OSDAPI_WriteXYString(TRUE, ucMainIconPos[id*2]+x, ucMainIconPos[id*2+1], 3, ucIcon_System_IndexTab1);
            OSDAPI_WriteXYString(TRUE, ucMainIconPos[id*2]+x, ucMainIconPos[id*2+1]+1, 3, ucIcon_System_IndexTab2);
            break;
        case MainIcon_Ergonomics:
            OSDAPI_WriteXYString(TRUE, ucMainIconPos[id*2]+x, ucMainIconPos[id*2+1], 3, ucIcon_Ergonomics_IndexTab1);
            OSDAPI_WriteXYString(TRUE, ucMainIconPos[id*2]+x, ucMainIconPos[id*2+1]+1, 3, ucIcon_Ergonomics_IndexTab2);
            break;
        case MainIcon_ECO:
            #if 1
            if(isOSDMainIconAvailable(id)==FALSE)
            #else
            if(UserData.bOSDRotation == TRUE)
            #endif
                OSDAPI_SetFontAttr(DisabledStringColor);
            OSDAPI_WriteXYString(TRUE, ucMainIconPos[id*2]+x, ucMainIconPos[id*2+1], 3, ucIcon_ECO_IndexTab1);
            OSDAPI_WriteXYString(TRUE, ucMainIconPos[id*2]+x, ucMainIconPos[id*2+1]+1, 3, ucIcon_ECO_IndexTab2);
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
    USHRT attr;
    UCHAR x = 0;

    //Clear Layer4 Information 
    if (ucMenuType == OSD_MAIN_SYSTEM && id == OSD_SYS_INFORMATION) //ULEric140415   
        ClrLayer4();
    
    //clear layer3 all
    OSDClearLayer3();
    //Clear Layer3 Arrow //ULEric140403
    OSDUpdateArrowIcon(CLEAR_1BIT_COLOR,ClearArrowType,STRING_LAYER_3);

    // clear layer2 second level up arrow if necessary.
    if (id >= OSD_MAX_LINES) {
        // clear up arrow
        OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
        OSDClearArrow(LAYER2_PAGE_ARROW_POX, PRE_PAGE_ARROW_POSY, PrePage_Arrow);
        //OSDAPI_WriteXYRepeatChar(TRUE, LAYER2_PAGE_ARROW_POX, PRE_PAGE_ARROW_POSY, 2, _SPACE_);
    }

    // clear triangle font
    OSDShowTrianIcon(TRIANGLE_CLEAR, id, STRING_LAYER_2);

    // clear all windows
    OSDDisableLayerWindow();
    
    // redraw layer2 string separater color to gray
    tmp = (id >= OSD_MAX_LINES? (id-OSD_MAX_LINES):id);
    OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]-1+3*tmp, LAYER2_LENGTH, UnSelectedStringColor);
    OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+1+3*tmp, LAYER2_LENGTH, UnSelectedStringColor);

    // redraw layer2 string color
    for (i=0; i<(ucLayer2ItmNumTb[ucMenuType]>OSD_MAX_LINES? OSD_MAX_LINES:ucLayer2ItmNumTb[ucMenuType]); i++) {
        if (OSDIsSubItemValid(i) == FALSE) {
            OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*3, LAYER2_LENGTH, DisabledStringColor);
        }
        else{             
            OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*3, LAYER2_LENGTH, UnSelectedStringColor);
        }        
        //OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*2, INDENT_STRING_MAX_LEN, UnSelectedStringColor);
    }

    // redraw layer1 string color
    //attr = UnSelectedStringColor1;
    for (i=0; i<MAINMENU_ICON_NUM; i++) {
        if(i == MainIcon_ECO){
            if(UserData.bOSDRotation == TRUE)
                attr = DisabledStringColor;
            else
                attr = UnSelectedStringColor1;
        }
        else{
            attr = UnSelectedStringColor1;
        }
        if(UserData.ucLanguage == OSDLANG_ARAB){
            x = Araboffset2;
        }
            
        OSDAPI_FillLineAttr(ucLayer1StringInfoTb[0]-x, ucLayer1StringInfoTb[1]+i*3, LAYER1_LENGTH-4, attr);
    }

    // redraw layer 1
    for (i=0; i<MAINMENU_ICON_NUM; i++) {
        OSDShowMainMenuIcon(i);
    }
    // redraw 4 windows
    OSDShowBigWin(OSD_LAYER1_WIN, OSD_WIN_BOARDER_SIZE);
    // clear layer2 triangle font
    OSDShowTrianIcon(TRIANGLE_CLEAR, tmp, STRING_LAYER_2);
    // clear Layer2 separater
    OSDShowLayerSeparater(STRING_LAYER_2, ucSubMenuType, TRUE);
    OSDShowStringSeparater(STRING_LAYER_2, FALSE);
    
    OSDSelectLayer1Item(ucMenuType);
    // clear Layer2 separater
    //OSDShowLayerSeparater(STRING_LAYER_2, ucMenuType, TRUE); //no need bcuz use window

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
    UCHAR x = 0;

    // clear layer2 string if exist
    OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
    for (i=0; i<(ucLayer2ItmNumTb[id]>OSD_MAX_LINES ? OSD_MAX_LINES:ucLayer2ItmNumTb[id]); i++) {
        OSDAPI_WriteXYRepeatChar(TRUE, ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*LAYER_STR_OFFSET_Y, LAYER2_LENGTH, _SPACE_);
    }

    OSDAPI_OSDWinOff(OSD_WINDOW1);

    // string row
    if(UserData.ucLanguage == OSDLANG_ARAB){
        OSDAPI_FillLineAttr(ucLayer1StringInfoTb[0]-4, ucLayer1StringInfoTb[1]+id*LAYER_STR_OFFSET_Y, LAYER1_LENGTH-4, UnSelectedStringColor1);
    }
    else{
        OSDAPI_FillLineAttr(ucLayer1StringInfoTb[0], ucLayer1StringInfoTb[1]+id*LAYER_STR_OFFSET_Y, LAYER1_LENGTH-4, UnSelectedStringColor1);
    }

    // redraw separater line to gray color
    // draw the item's bellow string separater line to gray
    //printf("-->Gray id %bx\r\n",id);
    if (isUp) { 
        //printf("Up y %bd\r\n",( ucLayer1StringInfoTb[1]+id*LAYER_STR_OFFSET_Y+1));
        OSDAPI_FillLineAttr(ucLayer1StringInfoTb[0]-4, ucLayer1StringInfoTb[1]+id*LAYER_STR_OFFSET_Y+1, LAYER1_LENGTH, StringSeparaterLineColor1);
    }
    else { 
        //printf("Dn y %bd\r\n",(ucLayer1StringInfoTb[1]+id*LAYER_STR_OFFSET_Y-2));    
        OSDAPI_FillLineAttr(ucLayer1StringInfoTb[0]-4, ucLayer1StringInfoTb[1]+id*LAYER_STR_OFFSET_Y-2, LAYER1_LENGTH, StringSeparaterLineColor1);

        if (id == (NUM_OSD_MAIN-1)) {
            //printf("--> %bd\r\n",(ucLayer1StringInfoTb[1]+id*LAYER_STR_OFFSET_Y+1));
            OSDAPI_FillLineAttr(ucLayer1StringInfoTb[0]-4, ucLayer1StringInfoTb[1]+id*LAYER_STR_OFFSET_Y+1, LAYER1_LENGTH, StringSeparaterLineColor1);
        }
        if(id==(NUM_OSD_MAIN-2)&&(isOSDMainIconAvailable(id+1)==FALSE)){
            //printf("Last id=%bd\r\n",id);
            OSDAPI_FillLineAttr(ucLayer1StringInfoTb[0]-4, ucLayer1StringInfoTb[1]+id*LAYER_STR_OFFSET_Y+1, LAYER1_LENGTH, StringSeparaterLineColor1);
        }
    }
    // icon part
    if(UserData.ucLanguage == OSDLANG_ARAB){
        x = Araboffset1 ;
    }
    OSDAPI_FillLineAttr(ucMainIconPos[id*2]+x, ucMainIconPos[id*2+1], 3, MAINICON_1BIT_COLOR1);
    OSDAPI_FillLineAttr(ucMainIconPos[id*2]+x, ucMainIconPos[id*2+1]+1, 3, MAINICON_1BIT_COLOR1);
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
    if (OSDGetLayer3ItemNum(ucMenuType, id)) {
        //OSDShowStringSeparater(STRING_LAYER_3, TRUE);     
        // clear layer 3 string
        for (i=0; i<(OSDCheckL3ItemNum(ucMenuType, id, 8)); i++) {
            //if (TestTable2[ucMenuType][id][i] != NULL) {
                OSDAPI_WriteXYRepeatChar(TRUE, *(ucLayer3PosInfoTab[ucMenuType]+0), (*(ucLayer3PosInfoTab[ucMenuType]+1))+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, _SPACE_);    
            //}
        }
    }
    else {
        // clear layer3 item
        OSDClearLayer3();
        /*
        //OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
        for (i=0; i<LAYER_STR_HEIGHT; i++) {
            OSDAPI_WriteXYRepeatChar(TRUE, ucLayer3MItem1InfoTb[0], ucLayer3MItem1InfoTb[1]+i, INDENT_STRING_MAX_LEN, _SPACE_);
        }
        */
    }

    // clear second layer string if necessary
    if (id == 7 && isUp == FALSE) {
        for (i=0; i< 8 ; i++) {
            OSDAPI_WriteXYRepeatChar(FALSE, ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, _SPACE_);
        }
    }
    else if(id == 8 && isUp == TRUE) {
        for (i=0; i< ucLayer2ItmNumTb[ucMenuType]-8 ; i++) {
            OSDAPI_WriteXYRepeatChar(FALSE, ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, _SPACE_);
        }
    }

    OSDAPI_OSDWinOff(OSD_WINDOW1);//ULEric140416
    
    if (IsPage2) {
        // string row
        OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], (id-8)*LAYER_STR_OFFSET_Y+ucLayer2ItemInfoTb[1], INDENT_STRING_MAX_LEN, UnSelectedStringColor1);

        // redraw separater line to gray color
        OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], (id-8)*LAYER_STR_OFFSET_Y+ucLayer2ItemInfoTb[1]-1, INDENT_STRING_MAX_LEN, StringSeparaterLineColor1);
        OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], (id-8)*LAYER_STR_OFFSET_Y+ucLayer2ItemInfoTb[1]+1, INDENT_STRING_MAX_LEN, StringSeparaterLineColor1);
    }
    else {
         // string row
        OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], id*LAYER_STR_OFFSET_Y+ucLayer2ItemInfoTb[1], INDENT_STRING_MAX_LEN, UnSelectedStringColor1);

        // redraw separater line to gray color
        OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], id*LAYER_STR_OFFSET_Y+ucLayer2ItemInfoTb[1]-1, INDENT_STRING_MAX_LEN, StringSeparaterLineColor1);
        OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], id*LAYER_STR_OFFSET_Y+ucLayer2ItemInfoTb[1] +1, INDENT_STRING_MAX_LEN, StringSeparaterLineColor1);
    }
}


/*
UCHAR OSDGetCustomKeyPage2Num(void)
{
    UCHAR cnt = 0;
    if(UserData.ucCustomerKey1>CUSTOMER_KEY_VOLUME)
        cnt++;
    if(UserData.ucCustomerKey2>CUSTOMER_KEY_VOLUME)
        cnt++;
    if(UserData.ucCustomerKey3>CUSTOMER_KEY_VOLUME)
        cnt++;

    return cnt;
}
*/

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
    UCHAR i, tmp, cnt=0;

    OSDClearLayer4ByItem(id, IsUp);
    cnt = OSDGetCustomKeyPage1Num();
    cnt = cnt + id;
#if 1//0
    if (ucMenuType == OSD_MAIN_SYSTEM && (ucSubMenuType == OSD_SYS_CTKEY1||ucSubMenuType == OSD_SYS_CTKEY2||ucSubMenuType == OSD_SYS_CTKEY3)) { //Customkey page
//        printf("id %bx isUP %bx\r\n", id, IsUp);       
        if((id == 7 && IsUp == FALSE)||((cnt>=7)&&(cnt<=9))) {
            //printf("Page2 %bx\r\n\n",OSDGetCustomKeyPage1Num());
            for (i=0; i< OSD_MAX_LINES ; i++) {
                OSDAPI_WriteXYRepeatChar(TRUE, ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN-2, _SPACE_);
                
            }
        }
/*        
        else if(id == 8 && IsUp == TRUE) {
            printf("Page1 %bx\r\n\n",OSDGetCustomKeyPage2Num());
            
            for (i=0; i<(OSDGetLayer3ItemNum(ucMenuType, id)-8) ; i++) {
                OSDAPI_WriteXYRepeatChar(TRUE, ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN-2, _SPACE_);

            }
        }        
*/        
    }
    else{ 
        if (id == 7 && IsUp == FALSE) {
            for (i=0; i< OSD_MAX_LINES ; i++) {
                OSDAPI_WriteXYRepeatChar(TRUE, ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN-2, _SPACE_);
            }
        }
        else if(id == 8 && IsUp == TRUE) {
            for (i=0; i< OSD_MAX_LINES ; i++) {
                OSDAPI_WriteXYRepeatChar(TRUE, ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN-2, _SPACE_);
            }
        } 
    }
#else    
    // clear second layer string if necessary
    OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
    if (ucMenuType == OSD_MAIN_SYSTEM && (ucSubMenuType == OSD_SYS_CTKEY1||ucSubMenuType == OSD_SYS_CTKEY2||ucSubMenuType == OSD_SYS_CTKEY3)) { //Customkey page
        if (id == 6 && IsUp == FALSE &&(isAnyCustomKey(CUSTOMER_KEY_MUTE))) {
            for (i=0; i< 8 ; i++) {
                OSDAPI_WriteXYRepeatChar(TRUE, ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN-2, _SPACE_);
            }
        }
        else if (id == 5 && IsUp == FALSE &&(isAnyCustomKey(CUSTOMER_KEY_MUTE))&&(isAnyCustomKey(CUSTOMER_KEY_VOLUME))) {
            for (i=0; i< 8 ; i++) {
                OSDAPI_WriteXYRepeatChar(TRUE, ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN-2, _SPACE_);
            }
        }
        else if(id == 7 && IsUp == FALSE) {
            for (i=0; i< 8 ; i++) {
                OSDAPI_WriteXYRepeatChar(TRUE, ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN-2, _SPACE_);
                
            }
        }
        else if(id == 8 && IsUp == TRUE) {
            for (i=0; i<(OSDGetLayer3ItemNum(ucMenuType, id)-8) ; i++) {
                OSDAPI_WriteXYRepeatChar(TRUE, ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN-2, _SPACE_);

            }
        }        
    }
    else{
        if (id == 7 && IsUp == FALSE) {
            for (i=0; i< 8 ; i++) {
                OSDAPI_WriteXYRepeatChar(TRUE, ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN-2, _SPACE_);
            }
        }
        else if(id == 8 && IsUp == TRUE) {
            for (i=0; i< (OSDGetLayer3ItemNum(ucMenuType, id)-8) ; i++) {
                OSDAPI_WriteXYRepeatChar(TRUE, ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN-2, _SPACE_);
            }
        }
    }
#endif
    tmp = (id > 7? (id-8):id);
    // redraw string to white color
    OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+tmp*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, UnSelectedStringColor1_256);

    // redraw string separater to gray color
    OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], tmp*LAYER_STR_OFFSET_Y+ucLayer3PosInfoTab[ucMenuType][1]-1, INDENT_STRING_MAX_LEN, StringSeparaterLineColor1);
    OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], tmp*LAYER_STR_OFFSET_Y+ucLayer3PosInfoTab[ucMenuType][1]+1, INDENT_STRING_MAX_LEN, StringSeparaterLineColor1);

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
    OSDAPI_FillLineAttr( ucLayer4ItemInfoTb[ucLayer3MenuType*3+1], ucLayer4ItemInfoTb[ucLayer3MenuType*3+2]+id*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, UnSelectedStringColor1_256);

    //ULEric140401
    // redraw string separater to gray color
    //if (IsUp)
        //OSDAPI_FillLineAttr(ucLayer4ItemInfoTb[ucLayer3MenuType*3+1], ucLayer4ItemInfoTb[ucLayer3MenuType*3+2]+1+id*2, INDENT_STRING_MAX_LEN, UnSelectedStringColor);
    //else
        //OSDAPI_FillLineAttr(ucLayer4ItemInfoTb[ucLayer3MenuType*3+1], ucLayer4ItemInfoTb[ucLayer3MenuType*3+2]-1+id*2, INDENT_STRING_MAX_LEN, UnSelectedStringColor);
    //redraw separater line to gray color
    OSDAPI_FillLineAttr(ucLayer4ItemInfoTb[ucLayer3MenuType*3+1], id*LAYER_STR_OFFSET_Y+ucLayer4ItemInfoTb[ucLayer3MenuType*3+2]-1, INDENT_STRING_MAX_LEN, UnSelectedStringColor);
    if(id!=7)
        OSDAPI_FillLineAttr(ucLayer4ItemInfoTb[ucLayer3MenuType*3+1], id*LAYER_STR_OFFSET_Y+ucLayer4ItemInfoTb[ucLayer3MenuType*3+2] +1, INDENT_STRING_MAX_LEN, UnSelectedStringColor);
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
            OSDAPI_WriteXYRepeatChar(TRUE, ucLayer4ItemInfoTb[ucLayer3MenuType*3+1], ucLayer4ItemInfoTb[ucLayer3MenuType*3+2]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, _SPACE_);
        }
        OSDClearArrow(LAYER4_PAGE_ARROW_POX, Next_PAGE_ARROW_POSY, NextPage_Arrow);
        OSDClearArrow(LAYER4_PAGE_ARROW_POX, PRE_PAGE_ARROW_POSY, PrePage_Arrow);  
    }
    //UL Justin 140430
}

//******************************************************************************
// Prototype:
//  void OSDShowUpDownArrowIcon(UCHAR id)
// Parameters:
//  id     : layer1 item id
// Return:
//  None
// Purpose:
//  Activate Layer1 item id
// Notes:
//  None
//******************************************************************************
void OSDShowUpDownArrowIcon(UCHAR id)
{
    if (ucLayer2ItmNumTb[id] > OSD_MAX_LINES) {
        OSDAPI_SetFontAttr(ArrowColor2);
        // show down arrow
        OSDAPI_WriteXYChar(TRUE, Next_PAGE_ARROW_POSX, Next_PAGE_ARROW_POSY, DownArrow_1);
        OSDAPI_WriteXYChar(TRUE, Next_PAGE_ARROW_POSX+1, Next_PAGE_ARROW_POSY, DownArrow_2);
        //OSDAPI_WriteXYChar(TRUE, Next_PAGE_ARROW_POSX+1, Next_PAGE_ARROW_POSY+1, DownArrow_3);
    }
    else {
        OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
        // clear up arrow
        OSDAPI_WriteXYRepeatChar(TRUE, PRE_PAGE_ARROW_POSX, PRE_PAGE_ARROW_POSY, 2, _SPACE_);
        // clear down arrow
        OSDAPI_WriteXYRepeatChar(TRUE, Next_PAGE_ARROW_POSX, Next_PAGE_ARROW_POSY, 2, _SPACE_);
        //OSDAPI_WriteXYRepeatChar(TRUE, Next_PAGE_ARROW_POSX, Next_PAGE_ARROW_POSY+1, 2, _SPACE_);
    }
}

//******************************************************************************
// Prototype:
//  void OSDSelectLayer1Icon(UCHAR id)
// Parameters:
//  id     : layer1 item id
// Return:
//  None
// Purpose:
//  Layer1 icon and string select
// Notes:
//  None
//******************************************************************************
void OSDSelectLayer1Icon(UCHAR id)
{
    UCHAR x = 0;

    OSDShowSmallWin(id, OSD_LAYER1_WIN);
    //printf("-->Blue id %bd\r\n",(id));
    //printf("Y %bd\r\n\n",(id*LAYER_STR_OFFSET_Y+7));

    //Seprate line
    #if 0
    if(id!=0)
        OSDAPI_FillLineAttr(LAYER1_POSX, (id-1)*LAYER_STR_OFFSET_Y+7, LAYER1_LENGTH, StringSeparaterLineColor2);
    OSDAPI_FillLineAttr(LAYER1_POSX, id*LAYER_STR_OFFSET_Y+7, LAYER1_LENGTH, StringSeparaterLineColor2);
    #endif
    if(UserData.ucLanguage == OSDLANG_ARAB){
        OSDAPI_FillLineAttr(LAYER1_POSX, id*LAYER_STR_OFFSET_Y+6, LAYER1_LENGTH-4, SelectedStringColor);
    }
    else{
        OSDAPI_FillLineAttr(LAYER1_POSX+4, id*LAYER_STR_OFFSET_Y+6, LAYER1_LENGTH-4, SelectedStringColor);
    }

    if(UserData.ucLanguage == OSDLANG_ARAB){
        x = Araboffset1 ;
    }

    // icon part
    OSDAPI_FillLineAttr(ucMainIconPos[id*2]+x, ucMainIconPos[id*2+1], 3, SelectedStringColor);
    OSDAPI_FillLineAttr(ucMainIconPos[id*2]+x, ucMainIconPos[id*2+1]+1, 3, SelectedStringColor);
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
    //UCHAR i,j,k,m;
    //UCHAR Offset_x, Offset_y; 
    id = id;
    ENABLE1= ENABLE1;
    WaitDisVSync();
    if(UserData.bOSDRotation == FALSE){
        //OSDUpdateSelectPageIcon_Bottom(IconOffset, ButtonAction, Layer);       
        OSDUpdateSelectPageIcon_Right(IconOffset, ButtonAction, Layer);
    }
    else{
        OSDUpdateSelectPageIcon_Left(IconOffset, ButtonAction, Layer);
    }
    WaitDisVSync();

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
    UCHAR Offset_x, Offset_y;
    USHRT FontIndex;
   
	   
    if(UserData.bOSDRotation == FALSE){
        #if SELECT_PAGE_POS == 2
        //Set Offset_x, Offset_y by act
        
        #else
        if (act == 0) {
        	    Offset_x = OSD_CUSTOM_MENU3_SP_POSX;
                Offset_y = OSD_CUSTOM_MENU3_SP_POSY;
            }
            else if (act == 1) {
                Offset_x = OSD_CUSTOM_MENU1_SP_POSX; // 7 is selected page width
                Offset_y = OSD_CUSTOM_MENU1_SP_POSY;
            }
            else if (act== 2) {
                Offset_x = OSD_CUSTOM_MENU2_SP_POSX; // 7 is selected page width
                Offset_y = OSD_CUSTOM_MENU2_SP_POSY;
            }
            else if (act== 3) {
                Offset_x = OSD_DIALOG_SP_POSX;//0; // 7 is selected page width
                Offset_y = OSD_DIALOG_SP_POSY;//OSD_MAIN_HEIGHT;
            }
        #endif
        
        OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1_B1);
        switch (id) {
            case 0:
                FontIndex = SP_Bot_Icon1_1Bit_1;
            break;
            case 1:
                FontIndex = SP_Bot_Icon2_1Bit_1;
            break;
            case 2:
                if (act == 1) {            
                    OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_HOOK_COLOR_B1);                
                    FontIndex = SP_Bot_Icon6_1Bit_1;
                    id = 5;
                }
                else if (act== 2) {            
                    return;            
                }
             else{            
                    FontIndex = SP_Bot_Icon3_1Bit_1;
             }            
            break;
            case 3:
                    FontIndex = SP_Bot_Icon4_1Bit_1;
            break;
            case 4:
                OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_EXIT_COLOR_B1);
                FontIndex = SP_Bot_Icon5_1Bit_1;
            break;
        }

        for (i=0; i<SPBotIconItmNumTab[id]; i++) {
            OSDAPI_WriteXYChar(TRUE, Offset_x+SPBotIconPosInfoTab[id][i*2], Offset_y+SPBotIconPosInfoTab[id][i*2+1], FontIndex+i);        
        }
    }	
    else{//#else
        if (act == 0) {
    	 Offset_x = 0; 
    	 Offset_y = OSD_SPOFFSET_ROTATE;
        }
        else if (act == 1) {
            Offset_x = 0;
    	 Offset_y = OSD_SPOFFSET_ROTATE;
        }
        else if (act== 2) {
            Offset_x = 0;
    	 Offset_y = OSD_SPOFFSET_ROTATE;
        }
         else if (act== 3) {
            Offset_x = 0;
    	 Offset_y = OSD_SPOFFSET_ROTATE;
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
    	 OSDAPI_WriteXYChar(TRUE, Offset_y+SPIconPosInfoTab[id][i*2], Offset_y+SPIconPosInfoTab[id][i*2+1], FontIndex+i);
        }
    }//#endif
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
        OSDAPI_WriteXYRepeatChar(TRUE, LAYER3_PAGE_ARROW_POX, PRE_PAGE_ARROW_POSY, 2, _SPACE_);
    }
    //ULEric140415
    // clear layer4 string and string separater
#if 0    
    if(ucMenuType == OSD_MAIN_SYSTEM && ucSubMenuType == OSD_SYS_OSDSET&&itm<2)//for Language/OSD Timer
        ClrLayer4();
    else if(ucMenuType == OSD_MAIN_PICTURE && ucSubMenuType == OSD_PICTURE_COLORTEMP && itm == 3)//for UserColor Menu
        ClrLayer4();
    else if(ucMenuType == OSD_MAIN_PICTURE_ADVANCED && ucSubMenuType == OSD_PICTURE_AD_PIC && itm == PICTURE_MODE_LOW_BL)//for LBL Menu
        ClrLayer4();                
#else
    if(isOSDClearLayer4(itm)){
        ClrLayer4();          
        if(ucMenuType == OSD_MAIN_PICTURE_ADVANCED && ucSubMenuType == OSD_PICTURE_AD_PIC 
#if ENABLE_PICTURE_MODE_ANIMATION == ON            
            && itm == PICTURE_MODE_ANIMATION
#endif            
            ){
            OSDAPI_OSDWinOff(OSD_WINDOW2);
        }
    }
#endif
    if (ucLayer3ItmNumTab[ucMenuType][ucSubMenuType]) {
        // clear layer3 all windows if has string to show
        OSDDisableLayerWindow();

        // redraw string separater color
        for (i=0; i<7; i++) {
            OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]-1+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, UnSelectedStringColor);
            OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+1+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, UnSelectedStringColor);
        }
    }
    else {
        // clear only big windows cuz no string to show
        OSDDisableLayerWindow();
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
            start_state = (OSD_CUSTKEY_INPUT_BEG+1);
            end_state = OSD_CUSTKEY_INPUT_END;
            break;
        case CUSTOMER_KEY_DISPLAYMODE:
            start_state = OSD_CUSTKEY_DISPLAYMODE_1_STATE;
            end_state = OSD_CUSTKEY_DISPLAYMODE_END;
            break;
        case CUSTOMER_KEY_PICTUREMODE:
            start_state = OSD_CUSTKEY_PICTUREMODE_1_STATE;
            end_state = OSD_CUSTKEY_PICTUREMODE_END;
#if 1//FORCE_NON_CIRCLE_ACTION == ON && PICTURE_MODE_NUM > 8
            if (GetOSDState()<= start_state)
                return;
#endif // FORCE_NON_CIRCLE_ACTION
            break;
        //ULEric140331
        case CUSTOMER_KEY_MUTE:
            start_state = OSD_CUSTKEY_MUTE_1_STATE;
            end_state = OSD_CUSTKEY_MUTE_END;
            break;
#if ENABLE_ERGONOMICS == ON            
        case CUSTOMER_KEY_SMARTREMINDER:
            start_state = OSD_CUSTKEY_SMARTREMINDER_1_STATE;
            end_state = OSD_CUSTKEY_SMARTREMINDER_END;
            break;
#endif            
#if ENABLE_CUSTOMKEY_LBL == ON     
        case CUSTOMER_KEY_LOWBULELIGHTMODE:
            start_state = OSD_CUSTKEY_LOWBULELIGHTMODE_1_STATE;
            end_state = OSD_CUSTKEY_LOWBULELIGHTMODE_END;
            break;
#endif            
#if ENABLE_CUSTOMKEY_ANIMATION == ON     
         case CUSTOMER_KEY_ANIMATION_MODE:
            start_state = OSD_CUSTKEY_ANIMATION_STATE;
            end_state = OSD_CUSTKEY_ANIMATION_END;
    		break;
#endif 
#if ENABLE_EYE_PROTECT == ON
         case CUSTOMER_KEY_EYE_PROTECT:
            start_state = OSD_CUSTKEY_EYE_PROTECT_1_STATE;
            end_state = OSD_CUSTKEY_EYE_PROTECT_END;            
    		break;
         case CUSTOMER_KEY_EYE_PROTECT_METER:
            start_state = OSD_CUSTKEY_EYE_PROTECT_METER_1_STATE;
            end_state = OSD_CUSTKEY_EYE_PROTECT_METER_END;            
    		break;
#endif     
#if ENABLE_ECO_SENSOR == ON
         case CUSTOMER_KEY_ECO_SENSOR:
            start_state = OSD_CUSTKEY_ECO_SENSOR_1_STATE;
            end_state = OSD_CUSTKEY_ECO_SENSOR_END;            
    		break;
         case CUSTOMER_KEY_ECO_SENSOR_METER:
            start_state = OSD_CUSTKEY_ECO_SENSOR_METER_1_STATE;
            end_state = OSD_CUSTKEY_ECO_SENSOR_METER_END;            
    		break;
#endif            
        default:
            break;
    }
    
    OSDUnSelectDialogItem(CursorPos(start_state,GetOSDState()), TRUE);
    
    while (1) {
#if FORCE_NON_CIRCLE_ACTION == ON
        if (Item == CUSTOMER_KEY_PICTUREMODE){
            SetOSDState(NonCirclePrevState(start_state,end_state,GetOSDState()));            
        }
        else {
            SetOSDState(PrevState(start_state,end_state,GetOSDState()));
        }
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
	#if !lrd_dis_benq
        if (!(pInputTiming->usModeHActive == PANEL_WIDTH && pInputTiming->usModeVActive == PANEL_HEIGHT)) {
            OSDSetAspectRatio(CursorPos(start_state,GetOSDState()));   
        }
	#else
        if (!(InputTiming.usModeHActive == PANEL_WIDTH && InputTiming.usModeVActive == PANEL_HEIGHT)) {
            OSDSetAspectRatio(CursorPos(start_state,GetOSDState()));   
        }
	#endif
    }
#if ENABLE_CUSTOMKEY_LBL == ON         
    else if (Item == CUSTOMER_KEY_LOWBULELIGHTMODE) {
        UserData.ucLBLMode = CursorPos(start_state,GetOSDState());   
        SetLBLMode();
    }  
#endif    
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
            start_state = (OSD_CUSTKEY_INPUT_BEG+1);
            end_state = OSD_CUSTKEY_INPUT_END;
            break;
        case CUSTOMER_KEY_DISPLAYMODE:
            start_state = OSD_CUSTKEY_DISPLAYMODE_1_STATE;
            end_state = OSD_CUSTKEY_DISPLAYMODE_END;
        break;
        case CUSTOMER_KEY_PICTUREMODE:
            start_state = OSD_CUSTKEY_PICTUREMODE_1_STATE;
            end_state = OSD_CUSTKEY_PICTUREMODE_END;
#if 1//FORCE_NON_CIRCLE_ACTION == ON
            if ((GetOSDState()>= end_state-1)/*&&(Item != CUSTOMER_KEY_PICTUREMODE)*/)
                return;
#endif // FORCE_NON_CIRCLE_ACTION
        break;
    //ULEric140331
        case CUSTOMER_KEY_MUTE:
            start_state = OSD_CUSTKEY_MUTE_1_STATE;
            end_state = OSD_CUSTKEY_MUTE_END;
            break;
#if ENABLE_ERGONOMICS == ON            
        case CUSTOMER_KEY_SMARTREMINDER:
            start_state = OSD_CUSTKEY_SMARTREMINDER_1_STATE;
            end_state = OSD_CUSTKEY_SMARTREMINDER_END;
            break;
#endif            
#if ENABLE_CUSTOMKEY_LBL == ON                 
        case CUSTOMER_KEY_LOWBULELIGHTMODE:
            start_state = OSD_CUSTKEY_LOWBULELIGHTMODE_1_STATE;
            end_state = OSD_CUSTKEY_LOWBULELIGHTMODE_END;
            break;
#endif            
#if ENABLE_CUSTOMKEY_ANIMATION == ON     
         case CUSTOMER_KEY_ANIMATION_MODE:
            start_state = OSD_CUSTKEY_ANIMATION_STATE;
            end_state = OSD_CUSTKEY_ANIMATION_END;            
    		break;
#endif 
#if ENABLE_EYE_PROTECT == ON
         case CUSTOMER_KEY_EYE_PROTECT:
            start_state = OSD_CUSTKEY_EYE_PROTECT_1_STATE;
            end_state = OSD_CUSTKEY_EYE_PROTECT_END;            
    		break;
         case CUSTOMER_KEY_EYE_PROTECT_METER:
            start_state = OSD_CUSTKEY_EYE_PROTECT_METER_1_STATE;
            end_state = OSD_CUSTKEY_EYE_PROTECT_METER_END;            
    		break;
#endif     
#if ENABLE_ECO_SENSOR == ON
         case CUSTOMER_KEY_ECO_SENSOR:
            start_state = OSD_CUSTKEY_ECO_SENSOR_1_STATE;
            end_state = OSD_CUSTKEY_ECO_SENSOR_END;            
    		break;
         case CUSTOMER_KEY_ECO_SENSOR_METER:
            start_state = OSD_CUSTKEY_ECO_SENSOR_METER_1_STATE;
            end_state = OSD_CUSTKEY_ECO_SENSOR_METER_END;            
    		break;
#endif    
        default:
            break;
    }

    OSDUnSelectDialogItem(CursorPos(start_state,GetOSDState()), FALSE);
    while (1) {
#if FORCE_NON_CIRCLE_ACTION == ON
        if (Item == CUSTOMER_KEY_PICTUREMODE) {
            SetOSDState(NonCircleNextState(start_state,end_state,GetOSDState()));
        }
        else {
            SetOSDState(NextState(start_state,end_state,GetOSDState()));
        }
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
    #if !lrd_dis_benq
        if (!(pInputTiming->usModeHActive == PANEL_WIDTH && pInputTiming->usModeVActive == PANEL_HEIGHT)) {
            OSDSetAspectRatio(CursorPos(start_state,GetOSDState())); 
        }
	#else
        if (!(InputTiming.usModeHActive == PANEL_WIDTH && InputTiming.usModeVActive == PANEL_HEIGHT)) {
            OSDSetAspectRatio(CursorPos(start_state,GetOSDState())); 
        }	
	#endif
    }
#if ENABLE_CUSTOMKEY_LBL == ON                     
    else if (Item == CUSTOMER_KEY_LOWBULELIGHTMODE) {
        UserData.ucLBLMode = CursorPos(start_state,GetOSDState());            
       SetLBLMode();
    }        
#endif    
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
    if (UserData.bOSDRotation == TRUE && isOSDRotationAvailable()) {
        //printf("Rotate\r\n");
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
        //printf("Non-rotate\r\n");
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
    OSDDrawCustomMenuFrame(CUSTOM_MENU_TYPE_1);
    
    for (i=0; i<5; i++){
        OSDShowSelectPageIcon(i, 1);
    }
    //OSDShowTopPageIcon(TP_INPUT, 1, 0);
    OSDShowCusMenuIcon(TP_INPUT, 1);//test

    OSDShowBigWin(OSD_DIALOG_LAYER_WIN, OSD_WIN_BOARDER_SIZE);
    OSDShowStringSeparater(DIALOG_LAYER, FALSE);
    
    OSDindex = GetOSDState()-(OSD_CUSTKEY_INPUT_BEG+1);
    OSDSelectDialogItem(OSDindex, 0);

    UserSetTransparent();
    //OSDSetPosition(OSD_HOTKEY_MENU_H_POSITION,OSD_HOTKEY_MENU_V_POSITION);//zoe test
    OSDTurnOnOSD();
}

void OSDDrawCustomMenuFrame(UCHAR FrameType)
{

    OSDAPI_SetIndentIndex(String_Layer1_Index);
    if(FrameType == CUSTOM_MENU_TYPE_1){
        OSDInitFrame(OSD_CUSTOMERKEY_MENU1_TOTAL_WIDTH, OSD_CUSTOMERKEY_MENU1_TOTAL_HEIGHT, MAIN_FRAME_COLOR);
        OSDShowBenQMainFrame(FrameWidthType_CustomerMenu1);
        OSDShowSelectPageMainFrame(FrameWidthType_CustomerMenu1);
        ResetWDTimer();
#if ENABLE_OSD_ROTATION == ON
        if(UserData.bOSDRotation == TRUE){
            OSDSetPosition(ROT_OSD_HOTKEY_MENU_H_POSITION, ROT_OSD_HOTKEY_MENU_V_POSITION);//zoe test
        }
        else
#endif            
        {
            OSDSetPosition(OSD_HOTKEY_MENU_H_POSITION, OSD_HOTKEY_MENU_V_POSITION);//zoe test
        }
    }
    else if(FrameType == CUSTOM_MENU_TYPE_2){
        OSDInitFrame(OSD_CUSTOMERKEY_MENU2_TOTAL_WIDTH, OSD_CUSTOMERKEY_MENU2_TOTAL_HEIGHT, MAIN_FRAME_COLOR);
        OSDShowBenQMainFrame(FrameWidthType_CustomerMenu2);
        OSDShowSelectPageMainFrame(FrameWidthType_CustomerMenu2);  
#if ENABLE_OSD_ROTATION == ON
        if(UserData.bOSDRotation == TRUE){
            OSDSetPosition(ROT_OSD_HOTKEY_BAR_H_POSITION, ROT_OSD_HOTKEY_BAR_V_POSITION);//zoe test
        }
        else
#endif            
        {
            OSDSetPosition(OSD_HOTKEY_BAR_H_POSITION, OSD_HOTKEY_MENU_V_POSITION);//zoe test
        }
    }

    OSDShowCustomMenuTitle(FrameType);

}

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
    OSDDrawCustomMenuFrame(CUSTOM_MENU_TYPE_1);
	#if !lrd_dis_benq
    if ((pInputTiming->usModeHActive == PANEL_WIDTH && pInputTiming->usModeVActive == PANEL_HEIGHT)) {
        for (i=2; i<5; i++) {
            OSDShowSelectPageIcon(i, 1);
        }
    }
	#else
    if ((InputTiming.usModeHActive == PANEL_WIDTH && InputTiming.usModeVActive == PANEL_HEIGHT)) {
        for (i=2; i<5; i++) {
            OSDShowSelectPageIcon(i, 1);
        }
    }
	#endif
    else{
        for (i=0; i<5; i++) {
            OSDShowSelectPageIcon(i, 1);
        }
    }
//    OSDShowTopPageIcon(TP_DISPLAYMODE, 1, 0);
    OSDShowCusMenuIcon(TP_DISPLAYMODE, 1);//test

    OSDShowBigWin(OSD_DIALOG_LAYER_WIN, OSD_WIN_BOARDER_SIZE);
    OSDShowStringSeparater(DIALOG_LAYER, FALSE);

    OSDSelectDialogItem(UserData.ucAspectRatio, 0);

    UserSetTransparent();
    OSDSetPosition(OSD_HOTKEY_MENU_H_POSITION,OSD_HOTKEY_MENU_V_POSITION);
    
    OSDUpdateKeyInfo(TRUE,GetOSDState());
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
    OSDDrawCustomMenuFrame(CUSTOM_MENU_TYPE_1);
    for (i=0; i<5; i++) {
        OSDShowSelectPageIcon(i, 1);
    }

//    OSDShowTopPageIcon(TP_PICTUREMODE, 1, 0);
    OSDShowCusMenuIcon(TP_PICTUREMODE, 1);//test

    OSDShowBigWin(OSD_DIALOG_LAYER_WIN, OSD_WIN_BOARDER_SIZE);
    OSDShowStringSeparater(DIALOG_LAYER, FALSE);

    // show down arrow icon
    OSDAPI_SetFontAttr(ArrowColor1);
    OSDShowArrow(DIA_Next_PAGE_ARROW_POSX, DIA_Next_PAGE_ARROW_POSY, NextPage_Arrow);
    OSDClearArrow(DIA_PRE_PAGE_ARROW_POSX, DIA_PRE_PAGE_ARROW_POSY, PrePage_Arrow);  

    OSDSelectDialogItem(UserData.ucBFMode, 0);

    UserSetTransparent();
    //OSDSetPosition(OSD_HOTKEY_MENU_H_POSITION,OSD_HOTKEY_MENU_V_POSITION);
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
    OSDDrawCustomMenuFrame(CUSTOM_MENU_TYPE_2);
    for (i=0; i<5; i++){
        OSDShowSelectPageIcon(i, 2);//test
    }
//    OSDShowTopPageIcon(TP_VOLUME, 1, 0);
    OSDShowCusMenuIcon(TP_VOLUME, 1);//test

    OSDShowTrianIcon(TRIANGLE_METHOD1, 0, DIALOG_LAYER);
    OSDShowBigWin(OSD_DIALOG2_LAYER_WIN, OSD_WIN_BOARDER_SIZE);

    OSDShowVolume(TRUE, TRUE);

    UserSetTransparent();
    //OSDSetPosition(OSD_HOTKEY_BAR_H_POSITION,OSD_HOTKEY_MENU_V_POSITION);
    OSDTurnOnOSD();
}

void OSDShowMuteMenu(void)
{
    UCHAR i;

    OSDLoadFont(ShowMute_font);
    OSDDrawCustomMenuFrame(CUSTOM_MENU_TYPE_1);

    for (i=0; i<5; i++) {
        OSDShowSelectPageIcon(i, 1);
    }

//    OSDShowTopPageIcon(TP_MUTE, 1, 0);
    OSDShowCusMenuIcon(TP_MUTE, 1);//test
    
    OSDShowBigWin(OSD_DIALOG_LAYER_WIN, OSD_WIN_BOARDER_SIZE);
    OSDShowStringSeparater(DIALOG_LAYER, FALSE);
    
    OSDSelectDialogItem((!UserData.bAudioMute), 0);
    UserSetTransparent();
    //OSDSetPosition(OSD_HOTKEY_MENU_H_POSITION,OSD_HOTKEY_MENU_V_POSITION);    
    OSDTurnOnOSD();
}

#if 0//ENABLE_EYE_PROTECT == ON
void OSDShowEyeProtectMenu(UCHAR type)
{
    UCHAR i, value;
    
    OSDDrawCustomMenuFrame(CUSTOM_MENU_TYPE_1);
    
    if(type == TP_EYE_PROTECT){
        OSDLoadFont(ShowEyeProtect_font);
        OSDShowTopPageIcon(TP_EYE_PROTECT, 1, 0);   
        value = (!UserData.bEyeProtect);
    }
    else{
        OSDLoadFont(ShowEyeProtectMeter_font);
        OSDShowTopPageIcon(TP_EYE_PROTECT_METER, 1, 0);  
        value = (!UserData.bEyeProtectMeter);        
    }    
    for (i=0; i<5; i++) {
        OSDShowSelectPageIcon(i, 1);
    }

    //OSDShowTopPageIcon(TP_MUTE, 1, 0);
    OSDShowBigWin(OSD_DIALOG_LAYER_WIN, OSD_WIN_BOARDER_SIZE);
    OSDShowStringSeparater(DIALOG_LAYER, FALSE);
    
    OSDSelectDialogItem(value, 0);
    UserSetTransparent();
    OSDSetPosition(OSD_HOTKEY_MENU_H_POSITION,OSD_HOTKEY_MENU_V_POSITION);    
    OSDTurnOnOSD();
}
#endif     
#if 0//ENABLE_ECO_SENSOR == ON
void OSDShowECOMenu(UCHAR type)
{
    UCHAR i, value;
    
    OSDDrawCustomMenuFrame(CUSTOM_MENU_TYPE_1);
    
    if(type == TP_ECO_SENSOR){
        OSDLoadFont(ShowECOSensor_font);
        OSDShowTopPageIcon(TP_ECO_SENSOR, 1, 0);   
        value = (!UserData.bECOSensor);
    }
    else{
        OSDLoadFont(ShowECOSensorMeter_font);
        OSDShowTopPageIcon(TP_ECO_SENSOR_METER, 1, 0);  
        value = (!UserData.bECOSensorMeter);        
    }    
    for (i=0; i<5; i++) {
        OSDShowSelectPageIcon(i, 1);
    }

    //OSDShowTopPageIcon(TP_MUTE, 1, 0);
    OSDShowBigWin(OSD_DIALOG_LAYER_WIN, OSD_WIN_BOARDER_SIZE);
    OSDShowStringSeparater(DIALOG_LAYER, FALSE);
    
    OSDSelectDialogItem(value, 0);
    UserSetTransparent();
    OSDSetPosition(OSD_HOTKEY_MENU_H_POSITION,OSD_HOTKEY_MENU_V_POSITION);    
    OSDTurnOnOSD();
}
#endif

#if ENABLE_CUSTOMKEY_LBL == ON                
void OSDShowLBLMenu(void)
{
    UCHAR i;

    OSDLoadFont(ShowLowBlueLight_font);
    OSDDrawCustomMenuFrame(CUSTOM_MENU_TYPE_1);
    for (i=0; i<5; i++) {
        OSDShowSelectPageIcon(i, 1);
    }

//    OSDShowTopPageIcon(TP_LOWBLUELIGHT, 1, 0);
    OSDShowCusMenuIcon(TP_LOWBLUELIGHT, 1);//test
    
    OSDShowBigWin(OSD_DIALOG_LAYER_WIN, OSD_WIN_BOARDER_SIZE);
    OSDShowStringSeparater(DIALOG_LAYER, FALSE);

    OSDSelectDialogItem(UserData.ucLBLMode, 0);

    UserSetTransparent();
    //OSDSetPosition(OSD_HOTKEY_MENU_H_POSITION,OSD_HOTKEY_MENU_V_POSITION);    
    OSDTurnOnOSD();
}
#endif

#if ENABLE_ERGONOMICS == ON
void OSDShowSmartReminderMenu(void)
{
    UCHAR i;

    OSDLoadFont(ShowSmartReminder_font);
    OSDDrawCustomMenuFrame(CUSTOM_MENU_TYPE_1);
    for (i=0; i<5; i++) {
        OSDShowSelectPageIcon(i, 1);
    }

//    OSDShowTopPageIcon(TP_SMARTREMINDER, 1, 0);
    OSDShowCusMenuIcon(TP_SMARTREMINDER, 1);//test

    OSDShowBigWin(OSD_DIALOG_LAYER_WIN, OSD_WIN_BOARDER_SIZE);
    OSDShowStringSeparater(DIALOG_LAYER, FALSE);

    OSDSelectDialogItem((!UserData.bSmartReminder), 0);

    UserSetTransparent();
    //OSDSetPosition(OSD_HOTKEY_MENU_H_POSITION,OSD_HOTKEY_MENU_V_POSITION);    
    OSDTurnOnOSD();
}
#endif

#if ENABLE_EYE_PROTECT == ON     
void OSDShowEyeProtectMenu(UCHAR type)
{
    UCHAR i;

    OSDLoadFont(ShowEyePortect_font);
    OSDDrawCustomMenuFrame(CUSTOM_MENU_TYPE_1);
    for (i=0; i<5; i++) {
        OSDShowSelectPageIcon(i, 1);
    }
    OSDShowBigWin(OSD_DIALOG_LAYER_WIN, OSD_WIN_BOARDER_SIZE);
    OSDShowStringSeparater(DIALOG_LAYER, FALSE);

    if(type == TP_EYE_PROTECT){
//        OSDShowTopPageIcon(TP_EYE_PROTECT, 1, 0);
        OSDShowCusMenuIcon(TP_EYE_PROTECT, 1);//test

        OSDSelectDialogItem((!UserData.bEyeProtect), 0);
    }
    else if(type == TP_EYE_PROTECT_METER){
//        OSDShowTopPageIcon(TP_EYE_PROTECT_METER, 1, 0);
        OSDShowCusMenuIcon(TP_EYE_PROTECT_METER, 1);//test

        OSDSelectDialogItem((!UserData.bEyeProtectMeter), 0);
    } 

    UserSetTransparent();
    //OSDSetPosition(OSD_HOTKEY_MENU_H_POSITION,OSD_HOTKEY_MENU_V_POSITION);    
    OSDTurnOnOSD();
}
#endif 
#if ENABLE_ECO_SENSOR== ON     
void OSDShowECOMenu(UCHAR type)
{
    UCHAR i;

    OSDLoadFont(ShowECOSensor_font);
    OSDDrawCustomMenuFrame(CUSTOM_MENU_TYPE_1);
    for (i=0; i<5; i++) {
        OSDShowSelectPageIcon(i, 1);
    }
    OSDShowBigWin(OSD_DIALOG_LAYER_WIN, OSD_WIN_BOARDER_SIZE);
    OSDShowStringSeparater(DIALOG_LAYER, FALSE);

    if(type == TP_ECO_SENSOR){
//        OSDShowTopPageIcon(TP_ECO_SENSOR, 1, 0);
        OSDShowCusMenuIcon(TP_ECO_SENSOR, 1);//test
        
        OSDSelectDialogItem((!UserData.bECOSensor), 0);
    }
    else if(type == TP_ECO_SENSOR_METER){
//        OSDShowTopPageIcon(TP_EYE_PROTECT_METER, 1, 0);
        OSDShowCusMenuIcon(TP_ECO_SENSOR_METER, 1);//test
        
        OSDSelectDialogItem((!UserData.bECOSensorMeter), 0);
    } 

    UserSetTransparent();
    //OSDSetPosition(OSD_HOTKEY_MENU_H_POSITION,OSD_HOTKEY_MENU_V_POSITION);    
    OSDTurnOnOSD();
}
#endif 

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
    OSDDrawCustomMenuFrame(CUSTOM_MENU_TYPE_2);
    
    for (i=0; i<5; i++){
        OSDShowSelectPageIcon(i, 2);
    }
//    OSDShowTopPageIcon(TP_BRIGHTNESS, 1, 0);
    OSDShowCusMenuIcon(TP_BRIGHTNESS, 1);//test
    
    OSDShowTrianIcon(TRIANGLE_METHOD1, 0, DIALOG_LAYER);
    OSDShowBigWin(OSD_DIALOG2_LAYER_WIN, OSD_WIN_BOARDER_SIZE);

#if ENABLE_EYE_PROTECT == ON
    if(UserData.bEyeProtect && isOSDAllowEyeProtect()){
        OSDShowLayer3SliderBar(SLIBAR_EYEPROTECT_BRI, TRUE, TRUE);
    }
    else
#endif
    {
        OSDShowLayer3SliderBar(SLIBAR_BRI, TRUE, TRUE);
    }

    UserSetTransparent();
    //OSDSetPosition(OSD_HOTKEY_BAR_H_POSITION,OSD_HOTKEY_MENU_V_POSITION);    
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
    OSDDrawCustomMenuFrame(CUSTOM_MENU_TYPE_2);
    for (i=0; i<5; i++){
        OSDShowSelectPageIcon(i, 2);
    }
//    OSDShowTopPageIcon(TP_CONTRAST, 1, 0);
    OSDShowCusMenuIcon(TP_CONTRAST, 1);//test
    
    OSDShowTrianIcon(TRIANGLE_METHOD1, 0, DIALOG_LAYER);
    OSDShowBigWin(OSD_DIALOG2_LAYER_WIN, OSD_WIN_BOARDER_SIZE);
//    OSDShowContrast(TRUE, TRUE);
    OSDShowLayer3SliderBar(SLIBAR_CONS, TRUE, TRUE);    

    UserSetTransparent();
    //OSDSetPosition(OSD_HOTKEY_BAR_H_POSITION,OSD_HOTKEY_MENU_V_POSITION);
    OSDTurnOnOSD();
}

#if ENABLE_CUSTOMKEY_ANIMATION == ON     
void OSDShowAnimationMenu(void)
{
    UCHAR i;
    OSDLoadFont(ShowAnimationMenu_font);
    OSDDrawCustomMenuFrame(CUSTOM_MENU_TYPE_2);
    for (i=0; i<5; i++){
        OSDShowSelectPageIcon(i, 2);
    }
//    OSDShowTopPageIcon(TP_ANIMATION, 1, 0);
    OSDShowCusMenuIcon(TP_ANIMATION, 1);//test

    OSDShowTrianIcon(TRIANGLE_METHOD1, 0, DIALOG_LAYER);
    OSDShowBigWin(OSD_DIALOG2_LAYER_WIN, OSD_WIN_BOARDER_SIZE);
    OSDShowLayer3SliderBar(SLIBAR_ANIMATION, TRUE, TRUE);    

    UserSetTransparent();
    //OSDSetPosition(OSD_HOTKEY_BAR_H_POSITION,OSD_HOTKEY_MENU_V_POSITION);
    OSDTurnOnOSD();
}
#endif

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
        OSDInitFrame(OSD_SP_WIDTH, OSD_SP_HEIGHT, TOPPAGE_FRAME_COLOR);
        OSDAPI_SetIndentIndex(String_TopPage_Index);
        SetOSDState(OSD_DIRSRC_STATE);//Source State
        OSDShowTopPageMainFrame();
        //OSDAPI_SetIndentIndex(Input_DP_End);
        //OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
        #if MD_INPUT_INTERFACE&INPUT_VGA0
        OSDShowSourceIcon(VGA_SOURCE, VGA_SOURCE);
        #endif
        #if MD_INPUT_INTERFACE&INPUT_DIG1//MD_INPUT_INTERFACE&INPUT_DIG0
        OSDShowSourceIcon(DVI_SOURCE, DVI_SOURCE);
        #endif
        #if MD_INPUT_INTERFACE&INPUT_DIG3//MD_INPUT_INTERFACE&INPUT_DIG2
        OSDShowSourceIcon(HDMI_SOURCE, HDMI_SOURCE);
        #endif
        
#if MD_INPUT_INTERFACE&INPUT_DP
        OSDShowSourceIcon(DP_SOURCE, DP_SOURCE);
#endif
#if MD_INPUT_INTERFACE&INPUT_DP1
        OSDShowSourceIcon(MiniDP_SOURCE, MiniDP_SOURCE);
#endif
        OSDSetPosition(OSD_MAIN_TOP_MENU_H_POSITION,OSD_MAIN_TOP_MENU_V_POSITION);//need check!!!
//        OSDTurnOnOSD();
        OSDAPI_TurnOnOSD();
        
#if ISENETOUCHKEY == ON
        ENELEDBehavior(ENEEVENT_NOSTABLE_OSD);
#endif
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
    UCHAR i, ucCustomKeyNum;
    OSDInitialize(TRUE);
    
    OSDLoadFont(ShowTopPageMenu_font);
    OSDInitFrame(OSD_SP_WIDTH, OSD_SP_HEIGHT, TOPPAGE_FRAME_COLOR);

    OSDShowTopPageMainFrame();

    for(i=0; i<3; i++){
        if(i==0)
            ucCustomKeyNum =UserData.ucCustomerKey1;
        else if(i==1)
            ucCustomKeyNum =UserData.ucCustomerKey2;
        else if(i==2)
            ucCustomKeyNum =UserData.ucCustomerKey3;
        
        switch (ucCustomKeyNum) {
#if ENABLE_CUSTOMKEY_AUTOADJ == ON
            case CUSTOMER_KEY_AUTOADJUSTMENT:
                OSDShowTopPageIcon(TP_AUTOADJUSTMENT, 0, i);
                OSDShowTopPageString(TP_AUTOADJUSTMENT, String_TopPage_Index, i);
                break;
#endif               
            case CUSTOMER_KEY_DISPLAYMODE:
                OSDShowTopPageIcon(TP_DISPLAYMODE, 0, i);
                OSDShowTopPageString(TP_DISPLAYMODE, String_TopPage_Index, i);
                break;
            case CUSTOMER_KEY_PICTUREMODE:
                OSDShowTopPageIcon(TP_PICTUREMODE, 0, i);
                OSDShowTopPageString(TP_PICTUREMODE, String_TopPage_Index, i);
                break;
            case CUSTOMER_KEY_INPUT:
                OSDShowTopPageIcon(TP_INPUT, 0, i);
                OSDShowTopPageString(TP_INPUT, String_TopPage_Index, i);
                break;
            case CUSTOMER_KEY_BRIGHTNESS:
                OSDShowTopPageIcon(TP_BRIGHTNESS, 0, i);
                OSDShowTopPageString(TP_BRIGHTNESS, String_TopPage_Index, i);
                break;
            case CUSTOMER_KEY_CONTRAST:
                OSDShowTopPageIcon(TP_CONTRAST, 0, i);
                OSDShowTopPageString(TP_CONTRAST, String_TopPage_Index, i);
            break;
            case CUSTOMER_KEY_VOLUME:
                    OSDShowTopPageIcon(TP_VOLUME, 0, i);
                OSDShowTopPageString(TP_VOLUME, String_TopPage_Index, i);
            break;
            case CUSTOMER_KEY_MUTE:
                OSDShowTopPageIcon(TP_MUTE, 0, i);
                OSDShowTopPageString(TP_MUTE, String_TopPage_Index, i);
            break;
#if ENABLE_ERGONOMICS == ON            
            case CUSTOMER_KEY_SMARTREMINDER:
                OSDShowTopPageIcon(TP_SMARTREMINDER, 0, i);
                OSDShowTopPageString(TP_SMARTREMINDER, String_TopPage_Index, i);
            break;
#endif            
#if ENABLE_CUSTOMKEY_LBL == ON                             
            case CUSTOMER_KEY_LOWBULELIGHTMODE:
                OSDShowTopPageIcon(TP_LOWBLUELIGHT, 0, i);
                OSDShowTopPageString(TP_LOWBLUELIGHT, String_TopPage_Index, i);
                break;
#endif                
#if ENABLE_CUSTOMKEY_ANIMATION == ON     
            case CUSTOMER_KEY_ANIMATION_MODE:
                OSDShowTopPageIcon(TP_ANIMATION, 0, i);
                OSDShowTopPageString(TP_ANIMATION, String_TopPage_Index, i);
                break;
#endif 
#if ENABLE_CUSTOMKEY_CAD == ON     
            case CUSTOMER_KEY_CAD:
                OSDShowTopPageIcon(TP_CAD, 0, i);
                OSDShowTopPageString(TP_CAD, String_TopPage_Index, i);
                break;
#endif
#if ENABLE_EYE_PROTECT == ON
             case CUSTOMER_KEY_EYE_PROTECT:
                OSDShowTopPageIcon(TP_EYE_PROTECT, 0, i);
                OSDShowTopPageString(TP_EYE_PROTECT, String_TopPage_Index, i);
                break;
             case CUSTOMER_KEY_EYE_PROTECT_METER:
                OSDShowTopPageIcon(TP_EYE_PROTECT_METER, 0, i);
                OSDShowTopPageString(TP_EYE_PROTECT_METER, String_TopPage_Index, i);
                break;
#endif     
#if ENABLE_ECO_SENSOR == ON
             case CUSTOMER_KEY_ECO_SENSOR:
                OSDShowTopPageIcon(TP_ECO_SENSOR, 0, i);
                OSDShowTopPageString(TP_ECO_SENSOR, String_TopPage_Index, i);
                break;
             case CUSTOMER_KEY_ECO_SENSOR_METER:
                OSDShowTopPageIcon(TP_ECO_SENSOR_METER, 0, i);
                OSDShowTopPageString(TP_ECO_SENSOR_METER, String_TopPage_Index, i);
                break;
#endif        
        }

    }    
    OSDShowTopPageIcon(TP_MENU, 0, 0);
    OSDShowTopPageString(TP_MENU, String_TopPage_Index, 3);
    OSDShowTopPageIcon(TP_EXIT, 0, 0);
    OSDShowTopPageString(TP_EXIT, String_TopPage_Index, 4);



#if ENABLE_OSD_ROTATION == ON
    OSDDisableWinRotation();
#endif
    OSDSetPosition(OSD_MAIN_TOP_MENU_H_POSITION,OSD_MAIN_TOP_MENU_V_POSITION);//need check!!!

    OSDAPI_TurnOnOSD();   

//    OSDTurnOnOSD();
#if ISENETOUCHKEY == ON
    ENETopMenuKeyStatu();
#endif
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
    switch (id) {
#if ENABLE_ECO_SENSOR == ON
        case OSD_MAIN_ECO:
            if(UserData.bOSDRotation == TRUE){
                return FALSE;
            }                
            break;
#endif
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
#if ENABLE_OSD_ANALOG_FUNCTION ==ON                    
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
#endif
                default:
                    break;
            }
        break;
        case OSD_MAIN_PICTURE:
            switch (id) {
                case OSD_PICTURE_BRIGHTNESS:
                    if(isOSDCusKeyBriConDisable()){
                        return FALSE;    
                    }
                    break;
                case OSD_PICTURE_CONTRAST:
                    if(isOSDCusKeyBriConDisable()|| UserData.ucBFMode == PICTURE_MODE_ANIMATION){
                        return FALSE;    
                    }
                    break;
                case OSD_PICTURE_SHARPNESS:
                    break;
                case OSD_PICTURE_GAMMA:
                case OSD_PICTURE_COLORTEMP:
                    #if 1
                    if((UserData.ucBFMode != PICTURE_MODE_USER)&&(UserData.ucBFMode != PICTURE_MODE_STANDARD)){
                        return FALSE;
                    }
                    #endif
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
                    if(!(isOSDAllowSenseyeDemo())){
                        return FALSE;    
                    }        
                    break;                        
                case OSD_PICTURE_AD_DCR:
                    if(!(isOSDAllowDCR())){
                        return FALSE;    
                    }                    
                    break;                    
#if ENABLE_COLOR_FORMAT == ON                                                
                case OSD_PICTURE_AD_COLORFORMAT:                    
                    if(IsComponentInput()){
                        return TRUE;                                         
                    }
                    else{
                        return FALSE;    
                    }                    
                    break;            
#endif                    
                case OSD_PICTURE_AD_PCRANGE:
                    if(UserData.ucInputSource != INPUT_SC_HDMI){
                        return FALSE;    
                    }
                    else{
                        if (IsHDMIVideo()) 
                            return FALSE;  
                    }
                    break;
#if MD_ENABLE_OVERSCAN == ON                            
                case OSD_PICTURE_AD_OVERSCAN:
                    if((UserData.ucInputSource == INPUT_SC_DP)||(UserData.ucInputSource == INPUT_SC_DP1)||(UserData.ucInputSource == INPUT_SC_DP2)){
                        return FALSE;
                    }
                    if((UserData.ucInputSource == INPUT_SC_VGA)||(UserData.ucInputSource == INPUT_SC_DVI)){
                        if(IsComponentInput()){
                            return TRUE;                                         
                        }
                        return FALSE;    
                    }                
                    break;  
#endif                    
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
#if ENABLE_ERGONOMICS == ON
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
#if ENABLE_EYE_PROTECT == ON
            case OSD_ERGONOMICS_EYE_PROTECT:
                    if(!(isOSDAllowEyeProtect())){
                        return FALSE;                 
                    }
                break;
            case OSD_ERGONOMICS_EYE_PROTECT_METER:
                    if(!(isOSDAllowEyeProtectMeter())){
                        return FALSE;                 
                    }
                break;
#endif
            default:
                break;
        }
          break; 
#endif
#if ENABLE_ECO_SENSOR == ON
     case OSD_MAIN_ECO:
        switch (id) {
            case OSD_ECO_SENSOR:
                    if(!(isOSDAllowECOSensor())){
                        return FALSE;                 
                    }
                break;
            case OSD_ECO_SENSOR_METER:
                    if(!(isOSDAllowECOMeterRange())){
                        return FALSE;                 
                    }
                break;
            case OSD_ECO_SENSOR_RANGE:
                    if(!(isOSDAllowECOMeterRange())){
                        return FALSE;                 
                    }                                    
                break;                
            default:
                break;
        }
          break; 
#endif          
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
                            if (UserData.ucBFMode != PICTURE_MODE_USER) {
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
                case OSD_PICTURE_AD_PIC:
                    break;
                case OSD_PICTURE_AD_SENSEYE:
                    if(id != PICTURE_DUALMODE_ONOFF&&UserData.bSensEyeDemo==PICTURE_DUALMODE_OFF){
                        return FALSE;
                    }
                    break;
                case OSD_PICTURE_AD_DISMODE:
                    switch (id) {
                        case DSP_SIZE_1By1:
						#if !lrd_dis_benq
                            if (pInputTiming->usModeHActive == PANEL_WIDTH && pInputTiming->usModeVActive == PANEL_HEIGHT) {
						#else	
							if (InputTiming.usModeHActive == PANEL_WIDTH && InputTiming.usModeVActive == PANEL_HEIGHT) {
						#endif
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
#if ENABLE_AUDIO_SELECT == ON                    
                case OSD_AUDIO_SELECT:        
                    switch (id) {
                        case AUDIOSRC_PC:
                        break;    
                        case AUDIOSRC_DP:
                            if(UserData.ucInputSource != INPUT_SC_DP){
                                return FALSE;                 
                            }
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
#endif                    
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
#if ENABLE_ERGONOMICS == ON
     case OSD_MAIN_ERGONOMICS:
          break; 
#endif
     default:
          break;
    }
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
					#if !lrd_dis_benq
                    if (pInputTiming->usModeHActive == PANEL_WIDTH && pInputTiming->usModeVActive == PANEL_HEIGHT) {
					#else
                    if (InputTiming.usModeHActive == PANEL_WIDTH && InputTiming.usModeVActive == PANEL_HEIGHT) {
					#endif
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

BOOL GetCustomeKeyState(UCHAR Customekeystate)
{
    BOOL benbleflag = TRUE;
  
    switch (Customekeystate) {
#if ENABLE_CUSTOMKEY_AUTOADJ == ON
        case CUSTOMER_KEY_AUTOADJUSTMENT:
            if ((GetScalerSyncMode(_MainChannel) == DIG_SYNC)||IsComponentInput()) {
                benbleflag = FALSE;
            }
            break;
 #endif           
        case CUSTOMER_KEY_DISPLAYMODE:
        case CUSTOMER_KEY_PICTUREMODE:
        case CUSTOMER_KEY_INPUT:
            break;
        case CUSTOMER_KEY_BRIGHTNESS:
            if(isOSDCusKeyBriConDisable()){
                benbleflag = FALSE;
            }
            break;
        case CUSTOMER_KEY_CONTRAST:
            if(isOSDCusKeyBriConDisable()
#if ENABLE_PICTURE_MODE_ANIMATION== ON 
            ||(UserData.ucBFMode == PICTURE_MODE_ANIMATION)
#endif
                ){
                benbleflag = FALSE;
            }
            break;
        case CUSTOMER_KEY_VOLUME:
        case CUSTOMER_KEY_MUTE:
#if ENABLE_ERGONOMICS == ON            
        case CUSTOMER_KEY_SMARTREMINDER:
#endif            
#if ENABLE_CUSTOMKEY_LBL == ON                                         
        case CUSTOMER_KEY_LOWBULELIGHTMODE:
#endif            
#if ENABLE_CUSTOMKEY_ANIMATION == ON     
        case CUSTOMER_KEY_ANIMATION_MODE:
#endif                 
            break;

#if ENABLE_CUSTOMKEY_CAD == ON     
        case CUSTOMER_KEY_CAD:
            break;
#endif
#if ENABLE_EYE_PROTECT == ON
         case CUSTOMER_KEY_EYE_PROTECT:            
            if (!(isOSDAllowEyeProtect())) {
                benbleflag = FALSE;
            }
            break;
         case CUSTOMER_KEY_EYE_PROTECT_METER:
             if (!(isOSDAllowEyeProtectMeter())) {
                 benbleflag = FALSE;
             }
            break;
#endif     
#if ENABLE_ECO_SENSOR == ON
         case CUSTOMER_KEY_ECO_SENSOR:
             if (!(isOSDAllowECOSensor())) {
                 benbleflag = FALSE;
             }
            break;
         case CUSTOMER_KEY_ECO_SENSOR_METER:
             if (!(isOSDAllowECOMeterRange())) {
                 benbleflag = FALSE;
             }
            break;
#endif        
    }
    return benbleflag;
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

#if 1//OSDTYPE == OSD_BENQ 
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
    ResetKeyInfoStatus();
#if ISENETOUCHKEY == ON
    if( Custom_System.bIsShowLogo == FALSE || GetProductModeFlag()== TRUE){
    ENE_GPIO_LED_KeyLed_ALLOff();
    }
#endif    
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
//    #define SLIDE_BAR_HEIGHT     10
    #define SLIDE_VALUE_RANGE   100
    #define SLIDE_REMAINDER     (SLIDE_VALUE_RANGE/5)

    UCHAR i, k, ucSliderReminder;
    USHRT m, Color1, Color2;
//    UCHAR ucSliderValueMax = 100;
//    if(bPhaseSlider == TRUE)
//        ucSliderValueMax = 63;
    ucSliderReminder = ucSliderMaxValue/5;
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
    k = m / ucSliderMaxValue; // complete font
    for (i = 0; i < k; i++) {
        if (i == 0)
            OSDAPI_WriteXYChar(TRUE, x+1, y-i-1, SB_Bottom_Font1);
        else
            OSDAPI_WriteXYChar(TRUE, x+1, y-i-1, SB_Blank_Font);
    }
    if (i < SLIDE_BAR_HEIGHT) {
        k = (m % ucSliderMaxValue) / ucSliderReminder;
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

void OSDFocusInput(void)
{
    switch (UserData.ucInputSource) {
#if MD_INPUT_INTERFACE&INPUT_VGA0
        case INPUT_SC_VGA:
        SetOSDState(OSD_ITEM_1_2_1_STATE);
        break;
#endif
#if MD_INPUT_INTERFACE&INPUT_DIG1//MD_INPUT_INTERFACE&INPUT_DIG0
        case INPUT_SC_DVI:
        SetOSDState(OSD_ITEM_1_2_2_STATE);
        break;
#endif
#if MD_INPUT_INTERFACE&INPUT_DIG3//MD_INPUT_INTERFACE&INPUT_DIG2
        case INPUT_SC_HDMI:
       // SetOSDState(OSD_ITEM_1_2_3_STATE);       
        SetOSDState(OSD_ITEM_1_2_4_STATE);
        break;
#endif
#if MD_INPUT_INTERFACE&INPUT_DP
        case INPUT_SC_DP:
        //SetOSDState(OSD_ITEM_1_2_4_STATE);
        SetOSDState(OSD_ITEM_1_2_3_STATE);
        break;
#endif
#if MD_INPUT_INTERFACE&INPUT_DP1
        case INPUT_SC_DP2:
        SetOSDState(OSD_ITEM_1_2_5_STATE);
        break;
#endif
        case INPUT_SC_YPbPr:
        default:
        break;
    }
    //printf("OSDFocusInput: UserData.ucInputSource = %d\n", (USHRT)UserData.ucInputSource);
}
#if ENABLE_OSD_ANALOG_FUNCTION == ON
void OSDFocusHPos(void)
{
//    OSDShowHPos(TRUE, FALSE);
    OSDShowLayer3SliderBar(SLIBAR_HPOS, TRUE, FALSE);        
}

void OSDFocusVPos(void)
{
//    OSDShowVPos(TRUE, FALSE);
    OSDShowLayer3SliderBar(SLIBAR_VPOS, TRUE, FALSE);        
}

void OSDFocusClock(void)
{
//    OSDShowClock(TRUE, FALSE);
    OSDShowLayer3SliderBar(SLIBAR_CLOCK, TRUE, FALSE);    
}

void OSDFocusPhase(void)
{
//    OSDShowPhase(TRUE, FALSE);
    OSDShowLayer3SliderBar(SLIBAR_PHASE, TRUE, FALSE);
}
#endif
void OSDFocusBr(void)
{
    //OSDShowBrightness(TRUE, FALSE);
#if ENABLE_EYE_PROTECT == ON
    if(UserData.bEyeProtect && isOSDAllowEyeProtect()){
        OSDShowLayer3SliderBar(SLIBAR_EYEPROTECT_BRI, TRUE, FALSE);
    }
    else
#endif
    {
        OSDShowLayer3SliderBar(SLIBAR_BRI, TRUE, FALSE);
    }
}

void OSDFocusCn(void)
{
//    OSDShowContrast(TRUE, FALSE);
    OSDShowLayer3SliderBar(SLIBAR_CONS, TRUE, FALSE);    
}

void OSDFocusAnimation(void)
{
    OSDShowLayer4SliderBar(SLIBAR_ANIMATION_LAYER4, TRUE);
}

void OSDFocusGamma(void)
{
    //printf("OSDFocusGamma: UserData.ucGamma = %d\n", (USHRT)UserData.ucGamma);
    SetOSDState(OSD_ITEM_2_4_1_STATE + GetGammaNum());
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

#if ENABLE_SMART_SCALING == ON
void OSDFocusSmartScaling(void)
{
    //printf("OSDFocusDisplayMode: UserData.ucAspectRatio = %d\n", (USHRT)UserData.ucAspectRatio);
    OSDShowLayer3SliderBar(SLIBAR_SMRTSCALING, TRUE, FALSE);
    //SetOSDState(OSD_ITEM_3_5_1_STATE+UserData.ucAspectRatio);
}
#endif

void OSDShowLayer3SliderBar(UCHAR type,UCHAR redraw, BOOL Dlg)
{
    UCHAR value,valueTemp;
    ucSliderMaxValue = 100;
    switch(type){
        case SLIBAR_BRI:
            value = UserData.ucBrightness;
            break;
        case SLIBAR_CONS:
            value = UserData.ucContrast;
            break;
        case SLIBAR_SHARP:
            value = (UserData.ucSharpness);
            ucSliderMaxValue = MAXIMUM_SHARPNESS;
            break;
        case SLIBAR_HUE:
            value = UserData.ucHue;
            break;
        case SLIBAR_SAT:
            value = UserData.ucSaturation;
            break;
        case SLIBAR_PHASE:
			#if !lrd_dis_benq
            value = (pInputTiming->ucPhase);
			#else
            value = (InputTiming.ucPhase);
			#endif
            ucSliderMaxValue = MAXIMUM_PHASE;
            break;
        case SLIBAR_CLOCK:
            value = UserGetNormalClock();
            break;
        case SLIBAR_HPOS:
            value = UserGetNormalHPosn();
            break;
        case SLIBAR_VPOS:
            value = UserGetNormalVPosn();
            break;
#if ENABLE_PICTURE_MODE_ANIMATION == ON                 
        case SLIBAR_ANIMATION:
            value = UserData.ucAnimationMode;
            ucSliderMaxValue = MAXIMUM_ANIMATION_MODE;
            break;
#endif            
#if ENABLE_SMART_SCALING == ON
        case SLIBAR_SMRTSCALING:
            value = UserData.ucSmartScaling;
            break;
#endif       
#if ENABLE_EYE_PROTECT == ON
        case SLIBAR_EYEPROTECT_BRI:
            value = UserData.ucEyeProtectBrightness;
            break;
#endif
        case SLIBAR_RGAIN:    
        case SLIBAR_GGAIN:    
        case SLIBAR_BGAIN:    
        case SLIBAR_VOL:    
            break;            
    }

    valueTemp = value;
    if(type == SLIBAR_PHASE && value== 47){
        value = 48;
    }

    if (Dlg) {        
        OSDShowSliderBar(DIA2_SLIDER_BAR_POSX, DIA2_SLIDER_BAR_POSY, value, TRUE, SLIDERBAR_BLUE_COLOR);
        value = valueTemp;
        bSelNum = TRUE;
        OSDShowNum(DIA2_SLIDER_BAR_NUM_POSX, DIA2_SLIDER_BAR_NUM_POSY, value);
    }
    else {
        if (redraw) {
            OSDShowSliderBar(OSD_SLIDER_BAR_POSX, OSD_SLIDER_BAR_POSY, value, TRUE, SLIDERBAR_BLUE_COLOR);
            value = valueTemp;
            bSelNum = TRUE;
            OSDShowNum(OSD_SLIDER_BAR_NUM_POSX, OSD_SLIDER_BAR_NUM_POSY, value);
        }
        else {
            OSDShowSliderBar(OSD_SLIDER_BAR_POSX, OSD_SLIDER_BAR_POSY, value, FALSE, SLIDERBAR_GRAY_COLOR);
            value = valueTemp;
            bSelNum = FALSE;
            OSDShowNum(OSD_SLIDER_BAR_NUM_POSX, OSD_SLIDER_BAR_NUM_POSY, value);
        }
    }
}


void OSDShowRGain(UCHAR redraw, BOOL Dlg)
{
    ucSliderMaxValue = 100;
    if (Dlg) {
        OSDShowSliderBar(9, 18, UserData.ucUserRGain, TRUE, SLIDERBAR_BLUE_COLOR);
        bSelNum2 = TRUE;
        OSDShowNum2(9, 5, UserData.ucUserRGain,0);
    }
    else {
        if (redraw) {
            OSDShowSliderBar(OSD_RGAIN_SLIDER_BAR_POSX, OSD_RGAIN_SLIDER_BAR_POSY, UserData.ucUserRGain, TRUE, SLIDERBAR_RED_COLOR);
            bSelNum2 = TRUE;
            OSDShowNum2(OSD_RGAIN_SLIDER_BAR_NUM_POSX, OSD_RGAIN_SLIDER_BAR_NUM_POSY, UserData.ucUserRGain,0);
        }
        else {
            OSDShowSliderBar(OSD_RGAIN_SLIDER_BAR_POSX, OSD_RGAIN_SLIDER_BAR_POSY, UserData.ucUserRGain, FALSE, SLIDERBAR_GRAY_COLOR );
            bSelNum2 = FALSE;
            OSDShowNum2(OSD_RGAIN_SLIDER_BAR_NUM_POSX, OSD_RGAIN_SLIDER_BAR_NUM_POSY, UserData.ucUserRGain,0);
        }
    }
    
    OSDAPI_SetFontAttr(NumberColor3);
    OSDAPI_SetIndentIndex(String_Layer4_Index+3);
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    ShowIndentString(TRUE, OSD_RGAIN_SLIDER_BAR_NUM_POSX+1,OSD_RGAIN_SLIDER_BAR_NUM_POSY-2, 2, RGB_Slider_BAR_Tab[UserData.ucLanguage]);
    
}

void OSDShowGGain(UCHAR redraw, BOOL Dlg)
{
    ucSliderMaxValue = 100;

    if (Dlg) {
        OSDShowSliderBar(9, 18, UserData.ucUserGGain, TRUE, SLIDERBAR_BLUE_COLOR);
        bSelNum2 = TRUE;
        OSDShowNum2(9, 5, UserData.ucUserGGain,5);
    }
    else {
        if (redraw) {
            OSDShowSliderBar(OSD_GGAIN_SLIDER_BAR_POSX, OSD_GGAIN_SLIDER_BAR_POSY, UserData.ucUserGGain, TRUE, SLIDERBAR_GREEN_COLOR);
            bSelNum2 = TRUE;        
            OSDShowNum2(OSD_GGAIN_SLIDER_BAR_NUM_POSX, OSD_GGAIN_SLIDER_BAR_NUM_POSY, UserData.ucUserGGain,5);
        }
        else {
            OSDShowSliderBar(OSD_GGAIN_SLIDER_BAR_POSX, OSD_GGAIN_SLIDER_BAR_POSY, UserData.ucUserGGain, FALSE, SLIDERBAR_GRAY_COLOR);
            bSelNum2 = FALSE;
            OSDShowNum2(OSD_GGAIN_SLIDER_BAR_NUM_POSX, OSD_GGAIN_SLIDER_BAR_NUM_POSY, UserData.ucUserGGain,5);
        }
    }
    
    OSDAPI_SetFontAttr(NumberColor3);
    OSDAPI_SetIndentIndex(String_Layer4_Index+8);
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    ShowIndentString(TRUE, OSD_GGAIN_SLIDER_BAR_NUM_POSX+1,OSD_GGAIN_SLIDER_BAR_NUM_POSY-2, 2, RGB_Slider_BAR_Tab[NUM_OSDLANGS+UserData.ucLanguage]);
}

void OSDShowBGain(UCHAR redraw, BOOL Dlg)
{
    ucSliderMaxValue = 100;

    if (Dlg) {
        OSDShowSliderBar(9, 18, UserData.ucUserBGain, TRUE, SLIDERBAR_BLUE_COLOR);
        bSelNum2 = TRUE;
        OSDShowNum2(9, 5, UserData.ucUserBGain,10);
    }
    else {
        if (redraw) {
            OSDShowSliderBar(OSD_BGAIN_SLIDER_BAR_POSX, OSD_BGAIN_SLIDER_BAR_POSY, UserData.ucUserBGain, TRUE, SLIDERBAR_BLUE_COLOR);
            bSelNum2 = TRUE;
            OSDShowNum2(OSD_BGAIN_SLIDER_BAR_NUM_POSX, OSD_BGAIN_SLIDER_BAR_NUM_POSY, UserData.ucUserBGain,10);
        }
        else {
            OSDShowSliderBar(OSD_BGAIN_SLIDER_BAR_POSX, OSD_BGAIN_SLIDER_BAR_POSY, UserData.ucUserBGain, FALSE, SLIDERBAR_GRAY_COLOR);
            bSelNum2 = FALSE;
            OSDShowNum2(OSD_BGAIN_SLIDER_BAR_NUM_POSX, OSD_BGAIN_SLIDER_BAR_NUM_POSY, UserData.ucUserBGain,10);
        }
    }
    OSDAPI_SetFontAttr(NumberColor3);
    OSDAPI_SetIndentIndex(String_Layer4_Index+13);
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    ShowIndentString(TRUE, OSD_BGAIN_SLIDER_BAR_NUM_POSX+1,OSD_BGAIN_SLIDER_BAR_NUM_POSY-2, 2, RGB_Slider_BAR_Tab[2*NUM_OSDLANGS+UserData.ucLanguage]);
}
void OSDShowVolume(UCHAR redraw, BOOL Dlg)
{
      UCHAR temp;
      temp = UserData.ucVolume;
      ucSliderMaxValue = 100;

      if(UserData.bAudioMute){
          UserData.ucVolume = 0;
      }
    
    if (Dlg) {
        OSDShowSliderBar(DIA2_SLIDER_BAR_POSX, DIA2_SLIDER_BAR_POSY, UserData.ucVolume, TRUE, SLIDERBAR_BLUE_COLOR);
        bSelNum = TRUE;
        OSDShowNum(DIA2_SLIDER_BAR_NUM_POSX, DIA2_SLIDER_BAR_NUM_POSY, UserData.ucVolume);
    }
    else {
        if (redraw) {
            OSDShowSliderBar(OSD_SLIDER_BAR_POSX, OSD_SLIDER_BAR_POSY, UserData.ucVolume, TRUE, SLIDERBAR_BLUE_COLOR);
            bSelNum = TRUE;
           OSDShowNum(OSD_SLIDER_BAR_NUM_POSX, OSD_SLIDER_BAR_NUM_POSY, UserData.ucVolume);

          }
        else {
            OSDShowSliderBar(OSD_SLIDER_BAR_POSX, OSD_SLIDER_BAR_POSY, UserData.ucVolume, FALSE, SLIDERBAR_GRAY_COLOR);
            bSelNum = FALSE;          
            OSDShowNum(OSD_SLIDER_BAR_NUM_POSX, OSD_SLIDER_BAR_NUM_POSY, UserData.ucVolume);
        }
    }
    if(UserData.bAudioMute){
      UserData.ucVolume = temp;
   }
}

void OSDShowDynamicContrast(UCHAR redraw)
{
    ucSliderMaxValue = 100;
    if (redraw) {
        OSDShowSliderBar(OSD_SLIDER_BAR_POSX, OSD_SLIDER_BAR_POSY, Remap5To100(UserData.ucDynamicContrast), TRUE, SLIDERBAR_BLUE_COLOR);
        bSelNum = TRUE;
        OSDShowNum(OSD_SLIDER_BAR_NUM_POSX, OSD_SLIDER_BAR_NUM_POSY, UserData.ucDynamicContrast);
    }
    else {
        OSDShowSliderBar(OSD_SLIDER_BAR_POSX, OSD_SLIDER_BAR_POSY, Remap5To100(UserData.ucDynamicContrast), FALSE, SLIDERBAR_GRAY_COLOR);
        bSelNum = FALSE;
        OSDShowNum(OSD_SLIDER_BAR_NUM_POSX, OSD_SLIDER_BAR_NUM_POSY, UserData.ucDynamicContrast);
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
#if (ENABLE_OSD_ANALOG_FUNCTION == ON) || (ENABLE_CUSTOMKEY_AUTOADJ == ON)

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
#if !lrd_dis_benq
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
        Sleep(100);            //  timer too short, the 100 message can not display.
        Custom_System.bAutoTuneFinish = TRUE;

        if (pInputTiming->ucAutoTune != 0) {
            NvramWriteTimingData(pInputTiming);
        }
        OSDCloseAll();      
    }
    SetScalerIndex(idxbk);  
#else
    UCHAR interface ;

 //   UCHAR idxbk = ucSCIdx;
 //   SetScalerIndex(_MainChannel);   
    interface = GetCurrInputInterface();
//    pInputTiming = GetModeHandleInputTiming(_MainChannel);
    if ((GetInputSyncMode() != DIG_SYNC) &&
        interface != ANALOG_YPBPR_INPUT0 &&
        interface != ANALOG_YPBPR_INPUT1 &&
        GetProductModeFlag()== FALSE) {
        Custom_System.bAutoTuneFinish = FALSE;

        OSDShowDialog(OSD_DLG_AUTOTUNE,0);
        OSDUpdateAutoTuneBar(0);
        UserPerformAutoTune();
        Sleep(100);            //  timer too short, the 100 message can not display.
        Custom_System.bAutoTuneFinish = TRUE;

        if (InputTiming.ucAutoTune != 0) {
            NvramWriteTimingData(&InputTiming);
        }
        OSDCloseAll();      
    }
  //  SetScalerIndex(idxbk);  

#endif
}
#endif
void OSDPerformAutoTune(void)
{
#if !lrd_dis_benq
    pInputTiming = GetModeHandleInputTiming(_MainChannel);
    if ((GetInputSyncMode() != DIG_SYNC) && (pInputTiming->ucAutoTune == 0) && GetProductModeFlag()== FALSE)
    {
        OSDShowDialog(OSD_DLG_AUTOTUNE,0);
        UserPerformAutoTune();
        OSDClosed();
        if (pInputTiming->ucAutoTune != 0) {
            // Save timing data immediately for fitting some customer requirements.
            //SetOSDUpdTmgFlag();
            NvramWriteTimingData(pInputTiming);
        }
    }
#else
 //   pInputTiming = GetModeHandleInputTiming(_MainChannel);
    if ((GetInputSyncMode() != DIG_SYNC) && (InputTiming.ucAutoTune == 0) && GetProductModeFlag()== FALSE)
    {
        OSDShowDialog(OSD_DLG_AUTOTUNE,0);
        UserPerformAutoTune();
        OSDClosed();
        if (InputTiming.ucAutoTune != 0) {
            // Save timing data immediately for fitting some customer requirements.
            //SetOSDUpdTmgFlag();
            NvramWriteTimingData(&InputTiming);
        }
    }
#endif
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

#if !lrd_dis_benq
    pInputTiming = GetModeHandleInputTiming(_MainChannel);

    if(IsTimingChanged()){
         Custom_System.bIsTimingChanged = TRUE;
         CurrentTimingSaved();
         SetOSDUpdUsrFlag();
     }
     else{
         Custom_System.bIsTimingChanged = FALSE;
     }

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
        if(!(IsPreSetModeTiming()||IsVideoTiming())){
            SetOSDState(OSD_INFO_NONPRESET_STATE);
            OSDShowDialog(OSD_DLG_NONPRESET,0);
        }
        else{
            if(isOSDAllowResNotice()){
                SetOSDState(OSD_RES_NOTICE_STATE);
                OSDShowDialog(OSD_DLG_RESNOTE,0);
            }
            else{
                OSDCloseAll();
            } 
        }
    }

    ResetWDTimer();
    OSDResetSmartRemiderTimer(TRUE);
#else
  //  pInputTiming = GetModeHandleInputTiming(_MainChannel);

    if(IsTimingChanged()){
         Custom_System.bIsTimingChanged = TRUE;
         CurrentTimingSaved();
         SetOSDUpdUsrFlag();
     }
     else{
         Custom_System.bIsTimingChanged = FALSE;
     }

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
        if(!(IsPreSetModeTiming()||IsVideoTiming())){
            SetOSDState(OSD_INFO_NONPRESET_STATE);
            OSDShowDialog(OSD_DLG_NONPRESET,0);
        }
        else{
            if(isOSDAllowResNotice()){
                SetOSDState(OSD_RES_NOTICE_STATE);
                OSDShowDialog(OSD_DLG_RESNOTE,0);
            }
            else{
                OSDCloseAll();
            } 
        }
    }

    ResetWDTimer();
    OSDResetSmartRemiderTimer(TRUE);

#if lrd_test
UserSetAudioChannel();
UserSetVolumeAndMute();

#endif

#endif
}

void OSDShowOSDLock(void)
{
    OSDShowDialog(OSD_DLG_OSDLOCK,0);
}
#if ENABLE_BACKGROUND_TO_BLUE == ON
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
    if(((UserData.ucInputSource == INPUT_SC_DP)|(UserData.ucInputSource == INPUT_SC_DP2))){
        Flag_BLUE = TRUE;
    }
    return Flag_BLUE;
}
#endif

void OSDShowBurning(void)
{
    // Turn on LVDS first to avoid dead lock in clear OSD
    if (UserData.bDBCMode == ON) {
        DisableDBC();        
    }
    OSDAPI_TurnOffOSD();    
    PanelPowerOnSequence(FALSE);

    SetBrightness(MAXIMUM_BRIGHTNESS_PWM);
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
#if ENABLE_BACKGROUND_TO_BLUE == ON
    if(NeedBackgroundToBlue()== TRUE){
        ODAPI_ODTestPatternDisable();
        SetPostBGColor(0x00, 0x00, 0xFF);
    }
    else{
        SetPostBGColor(0x00, 0x00, 0x00);
    }
#else    
    SetPostBGColor(0x00, 0x00, 0x00);
#endif
    OSDShowDialog(OSD_DLG_BURNIN,0);
}



void OSDShowNoSync(void)
{
    // Turn on LVDS first to avoid dead lock in clear OSD
    if (UserData.bDBCMode == ON) {
        DisableDBC();        
    }
    OSDAPI_TurnOffOSD();
    PanelPowerOnSequence(FALSE);

    SetBrightness(MAXIMUM_BRIGHTNESS_PWM);
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
#if ENABLE_BACKGROUND_TO_BLUE == ON
    if(NeedBackgroundToBlue()== TRUE){
        ODAPI_ODTestPatternDisable();
        SetPostBGColor(0x00, 0x00, 0xFF);
    }
    else{
        SetPostBGColor(0x00, 0x00, 0x00);
    }
#else  
    SetPostBGColor(0x00, 0x00, 0x00);
#endif
    OSDShowDialog(OSD_DLG_NOSYNC,0);
}

void OSDShowNoCable(void)
{
    // Turn on LVDS first to avoid dead lock in clear OSD
    if (UserData.bDBCMode == ON) {
        DisableDBC();        
    }
    OSDAPI_TurnOffOSD();    
    PanelPowerOnSequence(FALSE);

    SetBrightness(MAXIMUM_BRIGHTNESS_PWM);
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
#if ENABLE_BACKGROUND_TO_BLUE == ON
    if(NeedBackgroundToBlue()== TRUE){
        ODAPI_ODTestPatternDisable();
        SetPostBGColor(0x00, 0x00, 0xFF);
    }
    else{
        SetPostBGColor(0x00, 0x00, 0x00);
    }
#else    
    SetPostBGColor(0x00, 0x00, 0x00);
#endif
#if !lrd_dis_benq
    if (Custom_System.bFactory) {
        //OSDShowDialog(OSD_DLG_BURNIN,0);
    }
    else {
        OSDShowDialog(OSD_DLG_NOCABLE,0);
    }
#else
    OSDShowDialog(OSD_DLG_NOCABLE,0);
#endif
}

void OSDShowOOL(void)
{
#if !lrd_dis_benq
    if (UserData.ucInputSource != UserGetInputSource()) {
        UserData.ucInputSource = UserGetInputSource();
        SetOSDUpdUsrFlag();
    }
    pInputTiming = GetModeHandleInputTiming(_MainChannel);

    if ((GetInputSyncMode() != DIG_SYNC) && (pInputTiming->ucAutoTune == 0) && GetProductModeFlag()== FALSE)
    {
        //OSDShowDialog(OSD_DLG_AUTOTUNE,0);
        UserPerformAutoTune();
        OSDClosed();
        if (pInputTiming->ucAutoTune != 0) {
            SetOSDUpdTmgFlag();
        }
    }
#else
    if (UserData.ucInputSource != UserGetInputSource()) {
        UserData.ucInputSource = UserGetInputSource();
        SetOSDUpdUsrFlag();
    }
 //   pInputTiming = GetModeHandleInputTiming(_MainChannel);

    if ((GetInputSyncMode() != DIG_SYNC) && (InputTiming.ucAutoTune == 0) && GetProductModeFlag()== FALSE)
    {
        //OSDShowDialog(OSD_DLG_AUTOTUNE,0);
        UserPerformAutoTune();
        OSDClosed();
        if (InputTiming.ucAutoTune != 0) {
            SetOSDUpdTmgFlag();
        }
    }
#endif
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

#if ENABLE_EYE_PROTECT == ON
void OSDEyeProtectBrightnessUp(void)
{
    UserData.ucEyeProtectBrightness++;
    if (UserData.ucEyeProtectBrightness > MAXIMUM_BRIGHTNESS)
        UserData.ucEyeProtectBrightness  = MAXIMUM_BRIGHTNESS;
    else {
    	OSDShowLayer3SliderBar(SLIBAR_EYEPROTECT_BRI, TRUE, FALSE);
        UserSetEyeProtectBrightness();
    }
}

void OSDEyeProtectBrightnessDown(void)
{
    UserData.ucEyeProtectBrightness--;
    if ((UserData.ucEyeProtectBrightness > MAXIMUM_BRIGHTNESS) ||
        (UserData.ucEyeProtectBrightness < MINIMUM_BRIGHTNESS))
        UserData.ucEyeProtectBrightness  = MINIMUM_BRIGHTNESS;
    else {
    	OSDShowLayer3SliderBar(SLIBAR_EYEPROTECT_BRI, TRUE, FALSE);
        UserSetEyeProtectBrightness();        
    }
}
#endif

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

#if ENABLE_EYE_PROTECT == ON
    if(UserData.bEyeProtect && isOSDAllowEyeProtect()){
        OSDEyeProtectBrightnessUp();
    }
    else
#endif
    {
    //printf("Br up\n");
        UserData.ucBrightness++;
        if (UserData.ucBrightness > MAXIMUM_BRIGHTNESS)
            UserData.ucBrightness  = MAXIMUM_BRIGHTNESS;
        else {
            OSDShowLayer3SliderBar(SLIBAR_BRI, TRUE, FALSE);
            UserSetBrightness();
        }
    }
    SetOSDUpdUsrFlag();
}

void OSDBrightnessDown(void)
{

#if ENABLE_EYE_PROTECT == ON
    if(UserData.bEyeProtect && isOSDAllowEyeProtect()){
        OSDEyeProtectBrightnessDown();
    }
    else
#endif
    {
        //printf("Br down\n");
        UserData.ucBrightness--;
        if ((UserData.ucBrightness > MAXIMUM_BRIGHTNESS) ||
            (UserData.ucBrightness < MINIMUM_BRIGHTNESS))
            UserData.ucBrightness  = MINIMUM_BRIGHTNESS;
        else {
            OSDShowLayer3SliderBar(SLIBAR_BRI, TRUE, FALSE);
            UserSetBrightness();
        }
    }
    SetOSDUpdUsrFlag();
}

void OSDContrastUp(void)
{
    UserData.ucContrast++;
    if (UserData.ucContrast > MAXIMUM_CONTRAST)
        UserData.ucContrast  = MAXIMUM_CONTRAST;
    else {
//    OSDShowContrast(TRUE, FALSE);
        OSDShowLayer3SliderBar(SLIBAR_CONS, TRUE, FALSE);    
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
//    OSDShowContrast(TRUE, FALSE);
        OSDShowLayer3SliderBar(SLIBAR_CONS, TRUE, FALSE);    
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
//       OSDShowTopPageIcon(TP_VOLUME, 1, 0);
        OSDShowCusMenuIcon(TP_VOLUME, 1);//test       
    }
    if (UserData.ucVolume > MAXIMUM_VOLUME)
        UserData.ucVolume  = MAXIMUM_VOLUME;
    else{
       OSDShowVolume(TRUE, TRUE);
       UserSetVolumeAndMute();
       SetOSDUpdUsrFlag();
    }
}

#if ENABLE_EYE_PROTECT == ON
void OSDCustomEyeProtectBrightnessUp(void)
{
    UserData.ucEyeProtectBrightness++;
    if (UserData.ucEyeProtectBrightness > MAXIMUM_BRIGHTNESS)
        UserData.ucEyeProtectBrightness  = MAXIMUM_BRIGHTNESS;
    else {
    	OSDShowLayer3SliderBar(SLIBAR_EYEPROTECT_BRI, TRUE, TRUE);
        UserSetEyeProtectBrightness();
    }
}

void OSDCustomEyeProtectBrightnessDown(void)
{
    UserData.ucEyeProtectBrightness--;
    if ((UserData.ucEyeProtectBrightness > MAXIMUM_BRIGHTNESS) ||
        (UserData.ucEyeProtectBrightness < MINIMUM_BRIGHTNESS))
        UserData.ucEyeProtectBrightness  = MINIMUM_BRIGHTNESS;
    else {
    	OSDShowLayer3SliderBar(SLIBAR_EYEPROTECT_BRI, TRUE, TRUE);
        UserSetEyeProtectBrightness();        
    }
}
#endif

void OSDCustBrightnessUp(void)
{
#if ENABLE_EYE_PROTECT == ON
    if(UserData.bEyeProtect && isOSDAllowEyeProtect()){
        OSDCustomEyeProtectBrightnessUp();
    }
    else
#endif
    {
        UserData.ucBrightness++;
        if (UserData.ucBrightness > MAXIMUM_BRIGHTNESS)
            UserData.ucBrightness  = MAXIMUM_BRIGHTNESS;
        else {
    //        OSDShowBrightness(TRUE, TRUE);
            OSDShowLayer3SliderBar(SLIBAR_BRI, TRUE, TRUE);
            UserSetBrightness();
        }
    }
    SetOSDUpdUsrFlag();
}

void OSDCustBrightnessDown(void)
{
#if ENABLE_EYE_PROTECT == ON
    if(UserData.bEyeProtect && isOSDAllowEyeProtect()){
        OSDCustomEyeProtectBrightnessDown();
    }
    else
#endif
    {
        UserData.ucBrightness--;
        if ((UserData.ucBrightness > MAXIMUM_BRIGHTNESS) ||
            (UserData.ucBrightness < MINIMUM_BRIGHTNESS))
            UserData.ucBrightness  = MINIMUM_BRIGHTNESS;
        else {
            OSDShowLayer3SliderBar(SLIBAR_BRI, TRUE, TRUE);
            UserSetBrightness();
        }
    }
    SetOSDUpdUsrFlag();
}

void OSDCustContrastUp(void)
{
    UserData.ucContrast++;
    if (UserData.ucContrast > MAXIMUM_CONTRAST)
        UserData.ucContrast  = MAXIMUM_CONTRAST;
    else {
//    OSDShowContrast(TRUE, TRUE);
        OSDShowLayer3SliderBar(SLIBAR_CONS, TRUE, TRUE);    
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
//    OSDShowContrast(TRUE, TRUE);
        OSDShowLayer3SliderBar(SLIBAR_CONS, TRUE, TRUE);    
        UserSetContrast();
    }
    SetOSDUpdUsrFlag();
}

#if ENABLE_CUSTOMKEY_ANIMATION == ON
void OSDCusAnimationUp(void)
{
    UserData.ucAnimationMode++;
    if (UserData.ucAnimationMode > MAXIMUM_ANIMATION_MODE)
        UserData.ucAnimationMode  = MAXIMUM_ANIMATION_MODE;
    else {
        OSDShowLayer3SliderBar(SLIBAR_ANIMATION, TRUE, TRUE);    
        UserSetAnimation();
    }
    SetOSDUpdUsrFlag();
}

void OSDCusAnimationDown(void)
{
    UserData.ucAnimationMode--;
    if ((UserData.ucAnimationMode > MAXIMUM_ANIMATION_MODE) ||
        (UserData.ucAnimationMode < MINIMUM_ANIMATION_MODE))
        UserData.ucAnimationMode  = MINIMUM_ANIMATION_MODE;
    else {
        OSDShowLayer3SliderBar(SLIBAR_ANIMATION, TRUE, TRUE);    
        UserSetAnimation();
    }
    SetOSDUpdUsrFlag();
}

#endif

void OSDSharpnessUp(void)
{
    UserData.ucSharpness++;
    if (UserData.ucSharpness > MAXIMUM_SHARPNESS)
        UserData.ucSharpness  = MAXIMUM_SHARPNESS;
    else {
//        OSDShowSharpness(TRUE, FALSE);
        OSDShowLayer3SliderBar(SLIBAR_SHARP, TRUE, FALSE);
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
//        OSDShowSharpness(TRUE, FALSE);
        OSDShowLayer3SliderBar(SLIBAR_SHARP, TRUE, FALSE);
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
    UserSetGamma();
//    SetOSDUpdUsrFlag();

}
#if ENABLE_OSD_ANALOG_FUNCTION == ON

void OSDPhaseUp(void)
{
    pInputTiming = GetModeHandleInputTiming(_MainChannel);

    pInputTiming->ucPhase++;
    if (pInputTiming->ucPhase > MAXIMUM_PHASE) {
        pInputTiming->ucPhase  = MAXIMUM_PHASE;
    }
    else {
        UserSetPhase();
//    OSDShowPhase(TRUE, FALSE);
        OSDShowLayer3SliderBar(SLIBAR_PHASE, TRUE, FALSE);

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
//    OSDShowPhase(TRUE, FALSE);
        OSDShowLayer3SliderBar(SLIBAR_PHASE, TRUE, FALSE);
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
//    OSDShowClock(TRUE, FALSE);
        OSDShowLayer3SliderBar(SLIBAR_CLOCK, TRUE, FALSE);    
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
//    OSDShowClock(TRUE, FALSE);
        OSDShowLayer3SliderBar(SLIBAR_CLOCK, TRUE, FALSE);    
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
//    OSDShowHPos(TRUE, FALSE);
        OSDShowLayer3SliderBar(SLIBAR_HPOS, TRUE, FALSE);        
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
//    OSDShowHPos(TRUE, FALSE);
        OSDShowLayer3SliderBar(SLIBAR_HPOS, TRUE, FALSE);        
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
//        OSDShowVPos(TRUE, FALSE);        
        OSDShowLayer3SliderBar(SLIBAR_VPOS, TRUE, FALSE);        
        
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
//        OSDShowVPos(TRUE, FALSE);        
        OSDShowLayer3SliderBar(SLIBAR_VPOS, TRUE, FALSE);        
    }
    SetOSDUpdTmgFlag();
}
#endif
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
    UserData.ucColorTemp = GetOSDState() - OSD_ITEM_2_5_1_STATE;
    UserSetColorTemp();
}


void OSDColorTempDown(void)
{
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
	#if !lrd_dis_benq
        if (pInputTiming->usModeHActive == PANEL_WIDTH && pInputTiming->usModeVActive == PANEL_HEIGHT) {
	#else
		if (InputTiming.usModeHActive == PANEL_WIDTH && InputTiming.usModeVActive == PANEL_HEIGHT) {
	#endif
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
	#if !lrd_dis_benq
        if (pInputTiming->usModeHActive == PANEL_WIDTH && pInputTiming->usModeVActive == PANEL_HEIGHT) {
	#else
		if (InputTiming.usModeHActive == PANEL_WIDTH && InputTiming.usModeVActive == PANEL_HEIGHT) {
	#endif
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
    UCHAR i;
    UserData.bSensEyeDemo = ~UserData.bSensEyeDemo;
    for (i=1; i<(OSDCheckL3ItemNum(ucMenuType,ucSubMenuType,8)); i++) {
    
        if (UserData.bSensEyeDemo == PICTURE_DUALMODE_ON) {
            OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, UnSelectedStringColor_256);
        }
        else {
            OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, DisabledStringColor_256);
        }
    }
    UserData.ucDualViewMode = Custom_System.ucDualViewTemp;

    UserSetDualView(UserData.bSensEyeDemo,UserData.ucDualViewMode);
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
#if MD_INPUT_INTERFACE & INPUT_VGA0 
void OSDConfirmInputVGA(void)
{
    if ( OSDAPI_IsOSDOn() ) {
        OSDBlinkTopPageButton(0);
        UserData.ucInputSource = INPUT_SC_VGA;
        OSDConfirmInput();
        OSDAPI_TurnOffOSD();                
        SetOSDUpdUsrFlag();
	}
}
#endif
#if MD_INPUT_INTERFACE & INPUT_DIG1//MD_INPUT_INTERFACE & INPUT_DIG0
void OSDConfirmInputDVI(void)
{
    if ( OSDAPI_IsOSDOn() ) {
        //OSDBlinkTopPageButton(1);
        
        OSDBlinkTopPageButton(0);
        UserData.ucInputSource = INPUT_SC_DVI;
        OSDConfirmInput();
        OSDAPI_TurnOffOSD();                
        SetOSDUpdUsrFlag();    
	}
}
#endif
void OSDConfirmInputHDMI(void)
{
    if ( OSDAPI_IsOSDOn() ) {
       // OSDBlinkTopPageButton(0);
        OSDBlinkTopPageButton(2);
        UserData.ucInputSource = INPUT_SC_HDMI;
        OSDConfirmInput();
        OSDAPI_TurnOffOSD();                
        SetOSDUpdUsrFlag();    
	}
}

void OSDConfirmInputDP(void)
{
    if ( OSDAPI_IsOSDOn() ) {
        OSDBlinkTopPageButton(1);
        UserData.ucInputSource = INPUT_SC_DP;
        OSDConfirmInput();
        OSDAPI_TurnOffOSD();                
        SetOSDUpdUsrFlag();
	}
}
#if !lrd_dis
void OSDConfirmInputMiniDP(void)
{
    if ( OSDAPI_IsOSDOn() ) {
        OSDBlinkTopPageButton(2);
        UserData.ucInputSource = INPUT_SC_DP2;
        OSDConfirmInput();
        OSDAPI_TurnOffOSD();                
        SetOSDUpdUsrFlag();
	}
}
#endif
void OSDConfirmInput(void)
{
#if !lrd_dis_benq
//    UCHAR Index;
    UCHAR tmp = SC_CHANNEL_INDEX;  
    OSDClosed();                
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

#if (ENABLE_DP_HPD == ON)
            if((GetPortTabIntertface(UserData.ucInputSource)) == DISPLAY_PORT_INPUT0) {
               // if(CheckDPTrainingStatus() != DPTR_DONE){
                    DP0HPDOff();
                    SetGlobalTimer(GLOBAL_TMR_HPD, HPD_LOW_PERIOD);
               // }
            }
#endif
#if (ENABLE_DP1_HPD == ON)
            if((GetPortTabIntertface(UserData.ucInputSource)) == DISPLAY_PORT_INPUT1) {
               // if(CheckDPTrainingStatus() != DPTR_DONE){
                    DP1HPDOff();
                    SetGlobalTimer(GLOBAL_TMR_HPD, HPD_LOW_PERIOD);
               // }
            }     
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
#else
    OSDClosed();                
    bShowInputNovitceFlag = TRUE;
    if (UserData.ucInputSource != UserGetInputSource()) {

#if ENABLE_ESD_PROTECT == ON
    BacklightOff();
#endif
#if IS_NT68870_SERIES
#if INPUT_INTERFACE & INPUT_MHL_MASK
    SC_CBUS_RESISTOR_CTRL = 0x00;
#if (INPUT_INTERFACE & INPUT_MHL0) || (INPUT_INTERFACE & INPUT_MHL1)
    SC_SetByteDPppPHY(_DPPP_PHY0, _DPPHY_IMPEDANCE_L1, 0x00);//Addr = 0x9C04; *Addr = 0x18;//0x1C04= 0x18
#endif
#if (INPUT_INTERFACE & INPUT_MHL2) || (INPUT_INTERFACE & INPUT_MHL3)
    SC_SetByteDPppPHY(_DPPP_PHY1, _DPPHY_IMPEDANCE_L1, 0x00);//Addr = 0x9C04; *Addr = 0x18;//0x1C04= 0x18
#endif
    Sleep(500);
#endif
#endif

    // Do not change the sequence of the following statements.
    //RecordCurrentSource(TRUE);
    UserSetInputSource();
    // XXX
    // Hot-fix to solve the issue of incorrect OSD state after turning off source menu under nosync/nocable state.
    // We will improve OSD arch. to overcome this issue.
    APPResendAppSync();
    SetOSDUpdUsrFlag();

#if IS_NT68790_SERIES || IS_NT68810_SERIES || IS_NT68870_SERIES
#if (ENABLE_DIGI3_HPD == ON) ||(ENABLE_DIGI2_HPD == ON) ||(ENABLE_DIGI1_HPD == ON) || (ENABLE_DIGI0_HPD == ON) || (ENABLE_DP_HPD == ON) || (ENABLE_DP1_HPD == ON) || (ENABLE_DP2_HPD == ON) || (ENABLE_DP3_HPD == ON)
//    if ((GetCurrInputInterface() == DISPLAY_PORT_INPUT) || (GetCurrInputInterface() == DISPLAY_PORT_INPUT1)) {
        SYSAPI_PerformHPDOff(TRUE);
//    }
#endif
#endif

    
    Custom_System.bPreShowMsgSource = TRUE;
#endif
   }
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
//    UCHAR i, j;
    UCHAR Offset_x, Offset_y,Iconwidth;

    ucMenuAction = Type;
    Iconwidth = OSD_SPICON1_WIDTH;

    if(UserData.bOSDRotation == FALSE){//#if SELECT_PAGE_POS == 0

        if (Type == FrameWidthType_MainMenu) {
    	    Offset_x = OSD_CUSTOM_MENU3_SP_POSX;
            Offset_y = OSD_CUSTOM_MENU3_SP_POSY;
        }
        else if (Type == FrameWidthType_CustomerMenu1) {
      	    Offset_x = OSD_CUSTOM_MENU1_SP_POSX;
            Offset_y = OSD_CUSTOM_MENU1_SP_POSY;
        }
        else if (Type== FrameWidthType_CustomerMenu2) {
      	    Offset_x = OSD_CUSTOM_MENU2_SP_POSX;        
            Offset_y = OSD_CUSTOM_MENU2_SP_POSY;
        }
        else if (Type== FrameWidthType_DialogMenu1) {//ULEric140410
            Offset_x = OSD_DIALOG1_SP_POSX;//0;
            Offset_y = OSD_DIALOG1_SP_POSY;//OSD_MAIN_HEIGHT;
        }

        OSDPageMainFrame_Right(Offset_x, Offset_y, Iconwidth);
    }	
    else {
        if (Type == FrameWidthType_MainMenu) {
            Offset_x = 0;
        }
        else if (Type == FrameWidthType_CustomerMenu1) {
            Offset_x = 0; // 7 is selected page width
        }
        else if (Type== FrameWidthType_CustomerMenu2) {
            Offset_x = 0; // 7 is selected page width
        }
        else if (Type== FrameWidthType_DialogMenu1) {//ULEric140410
            Offset_x = 0; // 7 is selected page width
        }
        OSDPageMainFrame_Left(Offset_x, Offset_y, 5);
    }

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
//    UCHAR i;
//    UCHAR Offset_x,Offset_y;

     Clr = Clr;

    if(!Clr)//ULEric140409
    {
        if(ucKeyInfoStatus!= 0xff)
            return;
        ucKeyInfoStatus = (act<<4|id);
        //printf("ucKeyInfoStatus = %BX\r\n",ucKeyInfoStatus);
        //return;
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

    if(UserData.bOSDRotation == FALSE){
        //OSDShowSelectPageButton_Bottom(id, act, Clr);
        OSDShowSelectPageButton_Right(id, act, Clr);
    }
    else{
        OSDShowSelectPageButton_Left(id, act, Clr);
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
    UCHAR BTN_Pos;

    //BTN_Pos = SELECT_PAGE_POS;

      if(UserData.bOSDRotation == TRUE){
          BTN_Pos = OSD_TOPPAGE_POS_ROT;
      }
      else{
          BTN_Pos = OSD_TOPPAGE_POS_NML;
      }

    switch (id) {
        case 0:
            OSDAPI_FillLineAttr(0,id*BTN_HEIGHT,  BTN_Width, SELECTPAGE_2BIT_COLOR1_BLUE);    //BTN_width = 8  
            for (i=1; i<4; i++) {   
                OSDAPI_FillLineAttr(0, id*BTN_HEIGHT+i,  1, TOPPAGE_2BIT_COLOR2_BLUE); 
                
#if OSDLANG_ARAB != OSDLANG_NONE
                if(UserData.ucLanguage == OSDLANG_ARAB&&GetOSDState()!=OSD_DIRSRC_STATE){
                    OSDAPI_FillLineAttr(BTN_Width-4, id*BTN_HEIGHT+i,  4, TOPPAGE_1BIT_COLOR1_BLUE);   
                    OSDAPI_FillLineAttr(1, id*BTN_HEIGHT+i, BTN_Width-5, TOPPAGE_1BIT_COLOR1_BLUE_B1);     
                }
                else
#endif
                {
                    OSDAPI_FillLineAttr(1, id*BTN_HEIGHT+i,  4, TOPPAGE_1BIT_COLOR1_BLUE);   
                    OSDAPI_FillLineAttr(5, id*BTN_HEIGHT+i, BTN_Width-5, TOPPAGE_1BIT_COLOR1_BLUE_B1);     
                }
            }          
            OSDAPI_FillLineAttr(0,id*BTN_HEIGHT+i,  1, SELECTPAGE_4BIT_COLOR_BLUE_UPPER);    //BTN_width = 8    
            OSDAPI_FillLineAttr(1,id*BTN_HEIGHT+i, BTN_Width-1, TOPPAGE_2BIT_COLOR3_BLUE);    //BTN_width = 8
            break;
	    case 1:
        case 2:
        case 3:
    	    /*OSDAPI_FillLineAttr(id*BTN_Width, 0, 1, SELECTPAGE_4BIT_COLOR_BLUE_LOWER);    //BTN_width = 8	
    	    OSDAPI_FillLineAttr(id*BTN_Width+1, 0, BTN_Width-1, TOPPAGE_2BIT_COLOR1_BLUE);    //BTN_width = 8
    	    OSDAPI_FillLineAttr(id*BTN_Width+BTN_Width, 0, 1, SELECTPAGE_4BIT_COLOR_BLUE_UPPER);
            for (i=1; i<4; i++) {	
		        OSDAPI_FillLineAttr(id*BTN_Width, i, 1, SELECTPAGE_2BIT_COLOR5); 	
	            if (BTN_Pos == 0)
		            OSDAPI_FillLineAttr(id*BTN_Width+1, i, BTN_Width-1, TOPPAGE_1BIT_COLOR1_BLUE);
	            else
		            OSDAPI_FillLineAttr(id*BTN_Width+1, i, BTN_Width-1, TOPPAGE_1BIT_COLOR1_BLUE_B1);
		        OSDAPI_FillLineAttr(id*BTN_Width+BTN_Width, i, 1, SELECTPAGE_2BIT_COLOR4);
            }*/
            OSDAPI_FillLineAttr(0,id*BTN_HEIGHT,  1, SELECTPAGE_4BIT_COLOR_BLUE_LOWER);    //BTN_width = 8	
            OSDAPI_FillLineAttr(1,id*BTN_HEIGHT, BTN_Width-1, TOPPAGE_2BIT_COLOR1_BLUE);    //BTN_width = 8
            for (i=1; i<4; i++) {	
                OSDAPI_FillLineAttr(0, id*BTN_HEIGHT+i,  1, TOPPAGE_2BIT_COLOR2_BLUE); 
#if OSDLANG_ARAB != OSDLANG_NONE
                if(UserData.ucLanguage == OSDLANG_ARAB&&GetOSDState()!=OSD_DIRSRC_STATE){
                    OSDAPI_FillLineAttr(BTN_Width-4, id*BTN_HEIGHT+i,  4, TOPPAGE_1BIT_COLOR1_BLUE);   
                    OSDAPI_FillLineAttr(1, id*BTN_HEIGHT+i, BTN_Width-5, TOPPAGE_1BIT_COLOR1_BLUE_B1);     
                }
                else
#endif
                {
                    OSDAPI_FillLineAttr(1, id*BTN_HEIGHT+i,  4, TOPPAGE_1BIT_COLOR1_BLUE);   
                    OSDAPI_FillLineAttr(5, id*BTN_HEIGHT+i, BTN_Width-5, TOPPAGE_1BIT_COLOR1_BLUE_B1); 
                }
            }          
            OSDAPI_FillLineAttr(0,id*BTN_HEIGHT+i,  1, SELECTPAGE_4BIT_COLOR_BLUE_UPPER);    //BTN_width = 8	
            OSDAPI_FillLineAttr(1,id*BTN_HEIGHT+i, BTN_Width-1, TOPPAGE_2BIT_COLOR3_BLUE);    //BTN_width = 8
            break;
        case 4:
            OSDAPI_FillLineAttr(0,id*BTN_HEIGHT,  1, SELECTPAGE_4BIT_COLOR_BLUE_LOWER);    //BTN_width = 8	
            OSDAPI_FillLineAttr(1,id*BTN_HEIGHT, BTN_Width-1, TOPPAGE_2BIT_COLOR1_BLUE);    //BTN_width = 8
            for (i=1; i<4; i++) {   
                OSDAPI_FillLineAttr(0, id*BTN_HEIGHT+i,  1, TOPPAGE_2BIT_COLOR2_BLUE); 
#if OSDLANG_ARAB != OSDLANG_NONE
                if(UserData.ucLanguage == OSDLANG_ARAB&&GetOSDState()!=OSD_DIRSRC_STATE){
                    OSDAPI_FillLineAttr(BTN_Width-4, id*BTN_HEIGHT+i,  4, TOPPAGE_1BIT_COLOR1_BLUE);   
                    OSDAPI_FillLineAttr(1, id*BTN_HEIGHT+i, BTN_Width-5, TOPPAGE_1BIT_COLOR1_BLUE_B1);     
                }
                else
#endif
                {
                    OSDAPI_FillLineAttr(1, id*BTN_HEIGHT+i,  4, TOPPAGE_1BIT_COLOR1_BLUE);   
                    OSDAPI_FillLineAttr(5, id*BTN_HEIGHT+i, BTN_Width-5, TOPPAGE_1BIT_COLOR1_BLUE_B1);    
                }
            }               
            OSDAPI_FillLineAttr(0,id*BTN_HEIGHT+i,  BTN_Width, SELECTPAGE_2BIT_COLOR1_BLUE);    //BTN_width = 8  
            break;
    }
    Sleep(100);
}

void OSDShowNoticeIcon(UCHAR Xoffset)
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
        OSDAPI_WriteXYChar(TRUE, Xoffset+PosInfo[i*2], PosInfo[i*2+1], Notice_Icon_1Bit_start+i);
}

void OSDShowInputIcon()
{
    UCHAR i,j;
    OSDAPI_SetFontAttr(NoticeIconColor);
    for (i=0; i<3; i++){
        for (j=0; j<3; j++){
            OSDAPI_WriteXYChar(TRUE, 2+j, 2+i, TP_1Bit_Start+i*3+j);
        }
    }    
}

void OSDShowAutoIcon(void)
{
    UCHAR i,j;
    OSDAPI_SetFontAttr(NoticeIconColor);    
    for (i=0; i<3; i++){
        for (j=0; j<3; j++){
            OSDAPI_WriteXYChar(TRUE, 2+j, 2+i, TP_1Bit_Auto_Start+i*3+j);
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
    UCHAR XPos, width, Xoffset;
    //UCHAR SelectPage_Pos = SELECT_PAGE_POS;
    
//test
#if 1
    OSDClearFrame(Type);
#endif

    if (Type == FrameWidthType_MainMenu) {
        XPos = OSD_MAIN_WIDTH-2+OSD_POSITION_OFFSET;
        width = OSD_MAIN_WIDTH;
        Xoffset = OSD_POSITION_OFFSET;
    }
    else if (Type == FrameWidthType_CustomerMenu1) {
        XPos = OSD_CUSTOMERKEY_MENU1_WIDTH+DIALOG_POSITION_OFFSET-2;
        width = OSD_CUSTOMERKEY_MENU1_WIDTH;
        Xoffset = DIALOG_POSITION_OFFSET;
    }
    else if (Type == FrameWidthType_CustomerMenu2){
        XPos = OSD_CUSTOMERKEY_MENU2_WIDTH+DIALOG2_POSITION_OFFSET-2;
        width = OSD_CUSTOMERKEY_MENU2_WIDTH;
        Xoffset = DIALOG2_POSITION_OFFSET;
    }

    // LINE 0
    OSDAPI_SetFontAttr(MAINMENU_COLOR1);
    OSDAPI_WriteXYChar(TRUE, 0+Xoffset, 0, MB_LeftTopCorner);
    OSDAPI_WriteXYRepeatChar(TRUE, 1+Xoffset, 0, (width-2), MB_TopRepeat);
    OSDAPI_WriteXYChar(TRUE, XPos, 0, MB_RightTopCorner);

    // LINE1
    OSDAPI_WriteXYChar(TRUE, 0+Xoffset, 1, MB_LeftSide_1);
    OSDAPI_WriteXYChar(TRUE, XPos, 1, MB_RightSide_1);
    OSDAPI_SetFontAttr(MAINMENU_COLOR2);
    OSDAPI_WriteXYRepeatChar(TRUE, 1+Xoffset, 1, (width-3), _SPACE_);

    // LINE2
    OSDAPI_SetFontAttr(MAINMENU_COLOR3);
    OSDAPI_WriteXYChar(TRUE, 0+Xoffset, 2, MB_TitleCrossLeft_1);
    OSDAPI_WriteXYRepeatChar(TRUE, 1+Xoffset, 2, (width-2), MB_TitleCrossRepeat_1);
    OSDAPI_WriteXYChar(TRUE, XPos, 2, MB_TitleCrossRight_1);

    // Left side and Right side
    for (i=0; i<(OSD_MAIN_HEIGHT-5); i++) {
        OSDAPI_WriteXYChar(TRUE, 0+Xoffset, 3+i, MB_LeftSide_2);
        OSDAPI_WriteXYChar(TRUE, XPos, 3+i, MB_RightSide_2);
    }

    // Bottom
    OSDAPI_SetFontAttr(MAINMENU_COLOR3);
    OSDAPI_WriteXYChar(TRUE, 0+Xoffset, OSD_MAIN_HEIGHT-2, MB_LeftBottomCorner_1);
    OSDAPI_WriteXYChar(TRUE, XPos, OSD_MAIN_HEIGHT-2, MB_RightBottomCorner_1);
    OSDAPI_SetFontAttr(MAINMENU_COLOR1);
    OSDAPI_WriteXYChar(TRUE, 0+Xoffset, OSD_MAIN_HEIGHT-1, MB_LeftBottomCorner_2);
    OSDAPI_WriteXYRepeatChar(TRUE, 1+Xoffset, OSD_MAIN_HEIGHT-1, (width-2), MB_BottomRepeat);
    OSDAPI_WriteXYChar(TRUE, XPos, OSD_MAIN_HEIGHT-1, MB_RightBottomCorner_2);



    // select page and main menu separator
    OSDAPI_SetFontAttr(MAINMENU_AND_SELECTPAGE_SEPARATOR);
    for (i=0; i<OSD_MAIN_HEIGHT; i++) {
        OSDAPI_WriteXYRepeatChar(TRUE, XPos+1, i,7, _SPACE_);        
    }



}

void OSDClearFrameBorder(UCHAR x, UCHAR y, UCHAR length, UCHAR height)
{
    UCHAR i;
	
    OSDAPI_SetFontAttr(CLEAR_FRAME_BORDER);
    for (i=0; i<height; i++) 
        OSDAPI_WriteXYRepeatChar(TRUE, x, y+i, length, _SPACE_);
}

void OSDClearFrame(UCHAR Type)
{
    UCHAR width, height;

    if (Type == FrameWidthType_MainMenu) {
        width = OSD_MAIN_TOTAL_WIDTH;
        height = OSD_MAIN_TOTAL_HEIGHT;
    }
    else if (Type == FrameWidthType_CustomerMenu1) {
        width = OSD_CUSTOMERKEY_MENU1_TOTAL_WIDTH;
        height = OSD_CUSTOMERKEY_MENU1_TOTAL_HEIGHT;
    }
    else if (Type == FrameWidthType_CustomerMenu2){
        width = OSD_CUSTOMERKEY_MENU2_TOTAL_WIDTH;
        height = OSD_CUSTOMERKEY_MENU2_TOTAL_HEIGHT;
    }
    else if (Type == FrameWidthType_DialogMenu1){
        width = OSD_DIALOG_SELECTPAGE_TOTAL_WIDTH;
        height = OSD_DIALOG_SELECTPAGE_TOTAL_HEIGHT;
    }

    OSDClearFrameBorder(0, 0, width, height);
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
    UCHAR Offset_BotX, Offset, Iconwidth;
    Iconwidth = OSD_SPICON_WIDTH;
    Offset_BotX = 0;
    Offset = 0;
    OSDPageMainFrame(Offset_BotX, Offset, Iconwidth);
   }

//******************************************************************************
// Prototype:
//  void OSDPageMainFrame_Right()
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Show dialog frame
// Notes:
//  None
//******************************************************************************
void OSDPageMainFrame_Right(UCHAR Offsetx, UCHAR Offsety, UCHAR Width)
{
    UCHAR i,j;
    OSDAPI_SetFontAttr(MAINMENU_COLOR1);
    //Left Top Corner
    OSDAPI_WriteXYChar(TRUE, Offsetx+0, Offsety, SP_LeftTopCorner);
    //First Icon Top Repeat	
    OSDAPI_WriteXYRepeatChar(TRUE, Offsetx+1, Offsety, Width-1, SP_TopRepeat);
    


    // From Second to Ninth left Icon  Repeat
    for(i=1; i<20; i++){
		OSDAPI_WriteXYChar(TRUE, Offsetx, Offsety+i, SP_Bot_LeftSideRepeat);
    }


    OSDAPI_WriteXYChar(TRUE, Offsetx,Offsety+i, SP_LeftBottomCorner); 
   //Final Icon Bottom Repeat	
    OSDAPI_WriteXYRepeatChar(TRUE, Offsetx+1, Offsety+i, Width-1, SP_BottomRepeat);
    for(i=0; i<4; i++){
        for(j=1; j<5; j++){
            OSDAPI_SetFontAttr(TOPPAGE_FRAME_COLOR);
            OSDAPI_WriteXYRepeatChar(TRUE, Offsetx+1, (Offsety+j)+i*4,Width-1, _SPACE_);
        }
    }
    for(j=0; j<4; j++){
        OSDAPI_SetFontAttr(TOPPAGE_FRAME_COLOR);
        OSDAPI_WriteXYRepeatChar(TRUE, Offsetx+1, (Offsety+j)+4*4,Width-1, _SPACE_);
    }
    //Horizontal edge Repeat
    for(i=1; i<5; i++){
        OSDAPI_SetFontAttr(SELECTPAGE_4BIT_COLOR1);
        OSDAPI_WriteXYChar(TRUE, Offsetx, Offsety+4*i, SP_LeftEdge);
        OSDAPI_SetFontAttr(SELECTPAGE_2BIT_COLOR2);
        OSDAPI_WriteXYRepeatChar(TRUE, Offsetx+1, Offsety+4*i, Width-1, SP_TopRepeat);
    }

}

//******************************************************************************
// Prototype:
//  void OSDPageMainFrame()
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Show dialog frame
// Notes:
//  None
//******************************************************************************
void OSDPageMainFrame(UCHAR Offsetx, UCHAR Offsety, UCHAR Width)
{
    UCHAR i;
    OSDAPI_SetFontAttr(MAINMENU_COLOR1);
    //Left Top Corner
    OSDAPI_WriteXYChar(TRUE, Offsetx+0, Offsety, SP_LeftTopCorner);
    //First Icon Top Repeat	
    OSDAPI_WriteXYRepeatChar(TRUE, Offsetx+1, Offsety, Width-1, SP_TopRepeat);

    // From Second to Ninth left Icon  Repeat
    for(i=1; i<20; i++){
		OSDAPI_WriteXYChar(TRUE, Offsetx, Offsety+i, SP_Bot_LeftSideRepeat);
    }
    OSDAPI_WriteXYChar(TRUE, Offsetx,Offsety+i, SP_LeftBottomCorner); 
   //Final Icon Bottom Repeat	
    OSDAPI_WriteXYRepeatChar(TRUE, Offsetx+1, Offsety+i, Width-1, SP_BottomRepeat);

    //Horizontal edge Repeat
    for(i=1; i<5; i++){
        OSDAPI_SetFontAttr(SELECTPAGE_4BIT_COLOR1);
        OSDAPI_WriteXYChar(TRUE, Offsetx, Offsety+4*i, SP_LeftEdge);
        OSDAPI_SetFontAttr(SELECTPAGE_2BIT_COLOR2);
        OSDAPI_WriteXYRepeatChar(TRUE, Offsetx+1, Offsety+4*i, Width-1, SP_TopRepeat);
    }

    
 /*   //virticl edge Repeat
    for(i=2; i<5; i++){
	for(j=2; j<4; j++){
		if(i != 0)
		    OSDAPI_SetFontAttr(SELECTPAGE_2BIT_COLOR2);
		OSDAPI_WriteXYChar(TRUE, Offsetx+i*Width, Offsety+j, SP_Bot_LeftSideRepeat);	
	}
    }
    for(i=1; i<5; i++){
        OSDAPI_SetFontAttr(SELECTPAGE_4BIT_COLOR1);
            OSDAPI_WriteXYChar(TRUE, Offsetx+i*Width, Offsety, SP_Bot_TopCross);
    }
    // inside icon 1bit part
    OSDAPI_SetFontAttr(MAINMENU_COLOR2);
    for (i=2; i<5; i++) 
        for (j=2; j<4; j++) 
            OSDAPI_WriteXYRepeatChar(TRUE, Offsetx+i*Width+1, Offsety+j, Width-1, _SPACE_); */

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
#if 0
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
#else
void OSDShowDialogFrame(UCHAR x, UCHAR y, UCHAR osdw, UCHAR osdh)
{
    UCHAR i, xe, ye;
    xe = x+osdw -1;
    ye = y+osdh -1;    
    // Four corner
    OSDAPI_SetFontAttr(TOPPAGE_2BIT_COLOR1);
    OSDAPI_WriteXYChar(TRUE, x, y, DI_2Bit_LeftTopCorner);
    OSDAPI_WriteXYChar(TRUE, xe, y, DI_2Bit_RightTopCorner);
    OSDAPI_WriteXYChar(TRUE, x, ye, DI_2Bit_LeftBottomCorner);
    OSDAPI_WriteXYChar(TRUE, xe, ye, DI_2Bit_RightBottomCorner);

    OSDAPI_WriteXYRepeatChar(TRUE, x+1, y, (osdw-2), DI_2Bit_TopRepeat);
    OSDAPI_WriteXYRepeatChar(TRUE, x+1, ye, (osdw-2), DI_2Bit_BottomRepeat);

    OSDAPI_SetFontAttr(DIALOG_FRAME_COLOR);
    // Four corner 2
    OSDAPI_WriteXYChar(TRUE, x, y+1, DI_2Bit_LeftSideUp);
    OSDAPI_WriteXYChar(TRUE, xe, y+1, DI_2Bit_RightSideUp);
    OSDAPI_WriteXYChar(TRUE, x, (ye -1), DI_2Bit_LeftSideDown);
    OSDAPI_WriteXYChar(TRUE, xe, (ye -1), DI_2Bit_RightSideDown);

    // Left and Right Repeat
    for (i=0; i<(osdh-4); i++) {
        OSDAPI_WriteXYChar(TRUE, x, y+2+i, DI_2Bit_LeftSideRepeat);
        OSDAPI_WriteXYChar(TRUE, xe, y+2+i, DI_2Bit_RightSideRepeat);
    }
}
#endif
UCHAR isCustomMenuSlider(void)
{
    UCHAR CustomKeyType = fnGetCustomerKeyItem();
    
    if((CustomKeyType == CUSTOMER_KEY_VOLUME)||(CustomKeyType == CUSTOMER_KEY_BRIGHTNESS)||(CustomKeyType == CUSTOMER_KEY_CONTRAST)
    #if ENABLE_CUSTOMKEY_ANIMATION == ON    
        ||(CustomKeyType == CUSTOMER_KEY_ANIMATION_MODE)
    #endif        
        ){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

/*
UCHAR isAnyCustomKey(UCHAR type)
{
    if((UserData.ucCustomerKey1 == type||UserData.ucCustomerKey2 == type || UserData.ucCustomerKey3 == type))
        return TRUE;
    else
        return FALSE;
}
*/

void OSDDrawTrianIcon(UCHAR Layer, UCHAR TmpID, UCHAR iconIdx, USHRT attr)
{
    UCHAR i;
    UCHAR scTriangleIconPosTab[] = {
    // First triangle icon x start position of each layer.
        TRIANICON_POSX_START,       TRIANICON_POSY_START,
        (TRIANICON_POSX_START-1),   TRIANICON_POSY_START+1,
        TRIANICON_POSX_START,       TRIANICON_POSY_START+1,
        TRIANICON_POSX_START,       TRIANICON_POSY_END
    };
    
    UCHAR scTriangleIcon_DialogPosTab[] = {
    // First triangle icon x start position of dialog layer.
        DIA_TRIANICON_POSX_START,       DIA_TRIANICON_POSY_START,
        (DIA_TRIANICON_POSX_START-1),   DIA_TRIANICON_POSY_START+1,
        DIA_TRIANICON_POSX_START,       DIA_TRIANICON_POSY_START+1,
        DIA_TRIANICON_POSX_START,       DIA_TRIANICON_POSY_END
    };

    UCHAR scTriangleIcon_Dialog2PosTab[] = {
    // First triangle icon x start position of dialog layer.
        DIA2_TRIANICON_POSX_START,       DIA2_TRIANICON_POSY_START,
        (DIA2_TRIANICON_POSX_START-1),   DIA2_TRIANICON_POSY_START+1,
        DIA2_TRIANICON_POSX_START,       DIA2_TRIANICON_POSY_START+1,
        DIA2_TRIANICON_POSX_START,       DIA2_TRIANICON_POSY_END
    };

    UCHAR CustomKeyType = fnGetCustomerKeyItem();
    
    OSDAPI_SetFontAttr(attr);
    if((iconIdx == _SPACE_)&&(attr == CLEAR_1BIT_COLOR)){
        if (Layer == STRING_LAYER_2) {
            for (i=0; i<4; i++)
                OSDAPI_WriteXYChar(TRUE, scTriangleIconPosTab[i*2]+Line0_Offset, scTriangleIconPosTab[i*2+1]+ucMenuType*3, iconIdx);
        }
        else if (Layer == STRING_LAYER_3) {
            for (i=0; i<4; i++)
                OSDAPI_WriteXYChar(TRUE, scTriangleIconPosTab[i*2]+Line1_Offset+OFFSET_BETWEEN_LAYER, scTriangleIconPosTab[i*2+1]+TmpID*3, iconIdx);
        }
        else if (Layer == STRING_LAYER_4)  {
            for (i=0; i<4; i++)
                OSDAPI_WriteXYChar(TRUE, scTriangleIconPosTab[i*2]+Line2_Offset+OFFSET_BETWEEN_LAYER*2, scTriangleIconPosTab[i*2+1]+TmpID*3, iconIdx);
        }
        else if (Layer == DIALOG_LAYER){
            for (i=0; i<4; i++) {
                if(isCustomMenuSlider()==TRUE){
                    OSDAPI_WriteXYChar(TRUE, scTriangleIcon_Dialog2PosTab[i*2], scTriangleIcon_DialogPosTab[i*2+1]+TmpID*3, iconIdx);
                }
                else{
                    OSDAPI_WriteXYChar(TRUE, scTriangleIcon_DialogPosTab[i*2], scTriangleIcon_DialogPosTab[i*2+1]+TmpID*3, iconIdx);
                }
            }
        }
    }
    else {    
        if (Layer == STRING_LAYER_2) {
            for (i=0; i<4; i++)
                OSDAPI_WriteXYChar(TRUE, scTriangleIconPosTab[i*2]+Line0_Offset, scTriangleIconPosTab[i*2+1]+ucMenuType*3, iconIdx+i);
        }
        else if (Layer == STRING_LAYER_3) {
            for (i=0; i<4; i++)
                OSDAPI_WriteXYChar(TRUE, scTriangleIconPosTab[i*2]+Line1_Offset+OFFSET_BETWEEN_LAYER, scTriangleIconPosTab[i*2+1]+TmpID*3, iconIdx+i);
        }
        else if (Layer == STRING_LAYER_4)  {
            for (i=0; i<4; i++)
                OSDAPI_WriteXYChar(TRUE, scTriangleIconPosTab[i*2]+Line2_Offset+OFFSET_BETWEEN_LAYER*2, scTriangleIconPosTab[i*2+1]+TmpID*3, iconIdx+i);
        }
        else if (Layer == DIALOG_LAYER){
            for (i=0; i<4; i++) {
                if(isCustomMenuSlider()==TRUE){
                    OSDAPI_WriteXYChar(TRUE, scTriangleIcon_Dialog2PosTab[i*2], scTriangleIcon_DialogPosTab[i*2+1]+TmpID*3, iconIdx+i);
                }
                else{
                    OSDAPI_WriteXYChar(TRUE, scTriangleIcon_DialogPosTab[i*2], scTriangleIcon_DialogPosTab[i*2+1]+TmpID*3, iconIdx+i);
                }
            }
        }
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
    UCHAR TmpID;

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
        default:
            break;
    }

    //printf("Draw Tri mth %bx\r\n",ucMethod);
    switch (ucMethod) {
        case TRIANGLE_METHOD1:
        // triangle method 1
            OSDDrawTrianIcon(Layer, TmpID, Triangle_Icon1_1, TRIANLE_ICON1_COLOR);
            break;
        case TRIANGLE_METHOD2: // method 2
        // triangle method 2
            OSDDrawTrianIcon(Layer, TmpID, Triangle_Icon2_1, TRIANLE_ICON2_COLOR);
            break;
        case TRIANGLE_METHOD3: // method 3
        // triangle method 3
            OSDDrawTrianIcon(Layer, TmpID, Triangle_Icon3_1, TRIANLE_ICON3_COLOR);
            break;
        case TRIANGLE_CLEAR: // clear triangle font
            OSDDrawTrianIcon(Layer, TmpID, _SPACE_, CLEAR_1BIT_COLOR);
            break;
        default:
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
                OSDAPI_WriteXYRepeatChar(TRUE, LAYER1_POSX, LAYER_SEP_POSY+i*LAYER_STR_OFFSET_Y, LAYER1_LENGTH, StringSeparater_1);
                //OSDAPI_WriteXYChar(TRUE, LAYER1_POSXE, 6+i*2, StringSeparater_2);
            }
            break;

        case STRING_LAYER_2:
            OSDAPI_SetFontAttr(StringSeparaterLineColor1);
            for (i=0; i<7; i++) {
                OSDAPI_WriteXYRepeatChar(TRUE, LAYER2_POSX, LAYER_SEP_POSY+i*LAYER_STR_OFFSET_Y, LAYER2_LENGTH, StringSeparater_1);
                //OSDAPI_WriteXYChar(TRUE, LAYER2_POSXE, 6+i*2, StringSeparater_2);
            }
            break;

        case STRING_LAYER_3:
            if (clr) {
                OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
                for (i=0; i<7; i++) {
                    OSDAPI_WriteXYRepeatChar(TRUE, LAYER3_POSX, LAYER_SEP_POSY+i*LAYER_STR_OFFSET_Y, LAYER3_LENGTH, _SPACE_);
                }
            }
            else {
                OSDAPI_SetFontAttr(StringSeparaterLineColor1);
                for (i=0; i<7; i++) {
                    OSDAPI_WriteXYRepeatChar(TRUE, LAYER3_POSX, LAYER_SEP_POSY+i*LAYER_STR_OFFSET_Y, LAYER3_LENGTH, StringSeparater_1);
                    //OSDAPI_WriteXYChar(TRUE, LAYER3_POSXE, 6+i*2, StringSeparater_2);
                }
            }
            break;
        case STRING_LAYER_4:
            if (clr) {
                OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
                for (i=0; i<7; i++) {
                    OSDAPI_WriteXYRepeatChar(TRUE, LAYER4_POSX, LAYER_SEP_POSY+i*LAYER_STR_OFFSET_Y, LAYER4_LENGTH, _SPACE_);
                }
            }
            else {
                OSDAPI_SetFontAttr(StringSeparaterLineColor1);
                for (i=0; i<7; i++) {
                    OSDAPI_WriteXYRepeatChar(TRUE, LAYER4_POSX, LAYER_SEP_POSY+i*LAYER_STR_OFFSET_Y, LAYER4_LENGTH, StringSeparater_1);
                    //OSDAPI_WriteXYChar(TRUE, LAYER4_POSXE, 6+i*2, StringSeparater_2);
                }
            }
            break;
        case DIALOG_LAYER:
            if (clr) {
                OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
                for (i=0; i<7; i++) {
                    OSDAPI_WriteXYRepeatChar(TRUE, DIALOG_SEP_POSX, DIALOG_SEP_POSY+i*LAYER_STR_OFFSET_Y, DIALOG_LAYER_STR_LENGTH, _SPACE_);
                }
            }
            else {
                OSDAPI_SetFontAttr(StringSeparaterLineColor1);
                for (i=0; i<7; i++) {
                    OSDAPI_WriteXYRepeatChar(TRUE, DIALOG_SEP_POSX, DIALOG_SEP_POSY+i*LAYER_STR_OFFSET_Y, DIALOG_LAYER_STR_LENGTH, StringSeparater_1);
                }
            }
            break;
    }
}

void OSDClearLayer(UCHAR LayerNum)
{
    UCHAR i;
    OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
    switch(LayerNum){
        case LAYER_1:
            break;
        case LAYER_2:
            for (i=0; i<LAYER_ITEM_HEIGHT; i++){
                OSDAPI_WriteXYChar(TRUE, LAYER2_POSX, LAYER_POSY+i, _SPACE_);
            }
            break;
        case LAYER_3:
            for (i=0; i<LAYER_ITEM_HEIGHT; i++){
                OSDAPI_WriteXYChar(TRUE, LAYER3_POSX, LAYER_POSY+i, _SPACE_);
            }
            break;
        case LAYER_4:
            for (i=0; i<LAYER_ITEM_HEIGHT; i++){
                OSDAPI_WriteXYChar(TRUE, LAYER4_POSX, LAYER_POSY+i, _SPACE_);
            }            
            break;   
        default:
            break;
    }
}

void OSDDrawLayerSeparaterLine(UCHAR x ,UCHAR y, BOOL Clr)
{
    UCHAR i;
	y=0;
    if(Clr){
        OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
        // Clear head
        OSDAPI_WriteXYChar(TRUE, x, LAYER_POSY, _SPACE_);
        // Clear tail
        OSDAPI_WriteXYChar(TRUE, x, (LAYER_BOTTOM_POSY-1), _SPACE_);
        //Clear stright line
        for (i=0; i<((LAYER_BOTTOM_POSY-1)-LAYER_POSY-1); i++) {
            OSDAPI_WriteXYChar(TRUE, x, LAYER_POSY+1+i, _SPACE_);
        }
    }
    else{
        // draw head
        OSDAPI_WriteXYChar(TRUE, x, LAYER_POSY, Layer_Separator_Head);
        // draw tail
        OSDAPI_WriteXYChar(TRUE, x, (LAYER_BOTTOM_POSY-1), Layer_Separator_Tail);
        //draw stright line
        for (i=0; i<((LAYER_BOTTOM_POSY-1)-LAYER_POSY-1); i++) {
            OSDAPI_WriteXYChar(TRUE, x, LAYER_POSY+1+i, Layer_Separator_Mid);
        }
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
 //   UCHAR i;
    //printf("LayerSeparater %bx\r\n",SeparaterNum);
    OSDAPI_SetFontAttr(LayerSeparatorColor);
    switch (SeparaterNum) {
        case STRING_LAYER_2:
            if (Clr) {
                //printf("Clr sep\r\n");
/*                
                OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
                for (i=0; i<LAYER_ITEM_HEIGHT; i++)
                    OSDAPI_WriteXYChar(TRUE, LAYER2_POSX, LAYER_POSY+i, _SPACE_);
*/
                OSDClearLayer(LAYER_2);
                OSDDrawLayerSeparaterLine(LAYER2_TRI_POX, LAYER_POSY, TRUE);
                OSDShowTrianIcon(TRIANGLE_CLEAR, TrianglePos, STRING_LAYER_2);
            }
            else {
                OSDDrawLayerSeparaterLine(LAYER2_TRI_POX, LAYER_POSY, FALSE);
                OSDShowTrianIcon(TRIANGLE_METHOD3, TrianglePos, STRING_LAYER_2);
            }
            break;

        case STRING_LAYER_3:
            if (Clr) {
/*                
                OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
                for (i=0; i<LAYER_ITEM_HEIGHT; i++)
                    OSDAPI_WriteXYChar(TRUE, LAYER3_POSX, LAYER_POSY+i, _SPACE_);
*/
                OSDClearLayer(LAYER_3);
                OSDDrawLayerSeparaterLine(LAYER3_TRI_POX, LAYER_POSY, TRUE);
                OSDShowTrianIcon(TRIANGLE_CLEAR, TrianglePos, STRING_LAYER_3);
            }
            else {
                OSDDrawLayerSeparaterLine(LAYER3_TRI_POX, LAYER_POSY, FALSE);
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
#if ENABLE_AUTO_POVIT_FUNC == ON                      
                case OSD_DISPLAY_PIVOT:
                    break;
#endif
                case OSD_DISPLAY_INPUT:
                    break;
#if ENABLE_OSD_ANALOG_FUNCTION == ON                   
                case OSD_DISPLAY_ADJUST:
                    break;
                case OSD_DISPLAY_HPOS:
//                    OSDShowHPos(FALSE, FALSE);
                    OSDShowLayer3SliderBar(SLIBAR_HPOS, FALSE, FALSE);        
                    break;
                case OSD_DISPLAY_VPOS:
//                    OSDShowVPos(FALSE, FALSE);
                    OSDShowLayer3SliderBar(SLIBAR_VPOS, FALSE, FALSE);        
                    break;
                case OSD_DISPLAY_PIXELCLK:
//                    OSDShowClock(FALSE, FALSE);
                    OSDShowLayer3SliderBar(SLIBAR_CLOCK, FALSE, FALSE);                            
                    break;
                case OSD_DISPLAY_PHASE:
//                    OSDShowPhase(FALSE, FALSE);
                    OSDShowLayer3SliderBar(SLIBAR_PHASE, FALSE, FALSE);                            
                    break;
                    
#endif
                default:
                    break;
            }
            break;
        case OSD_MAIN_PICTURE:
            switch (id) {
                case OSD_PICTURE_BRIGHTNESS:
//                    OSDShowBrightness(FALSE, FALSE);
#if ENABLE_EYE_PROTECT == ON
                    if(UserData.bEyeProtect && isOSDAllowEyeProtect()){
                        OSDShowLayer3SliderBar(SLIBAR_EYEPROTECT_BRI, FALSE, FALSE);
                    }
                    else
#endif
                    {
                        OSDShowLayer3SliderBar(SLIBAR_BRI, FALSE, FALSE);
                    }
                break;

                case OSD_PICTURE_CONTRAST:
                    //OSDShowContrast(FALSE, FALSE);
                    OSDShowLayer3SliderBar(SLIBAR_CONS, FALSE, FALSE);
                    break;

                case OSD_PICTURE_SHARPNESS:
                    //OSDShowSharpness(FALSE, FALSE);
                    OSDShowLayer3SliderBar(SLIBAR_SHARP, FALSE, FALSE);
                    break;

                case OSD_PICTURE_HUE:
                    //OSDShowHue(FALSE, FALSE);
                    OSDShowLayer3SliderBar(SLIBAR_HUE, FALSE, FALSE);
                    break;

                case OSD_PICTURE_SATURATION:
                    //OSDShowSaturation(FALSE, FALSE);
                    OSDShowLayer3SliderBar(SLIBAR_SAT, FALSE, FALSE);
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
#if ENABLE_SMART_SCALING == ON                    
                case OSD_PICTURE_AD_SMARTSCALING:
                    OSDShowLayer3SliderBar(SLIBAR_SMRTSCALING, FALSE, FALSE);
                    break;
#endif                    
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
#if ENABLE_ERGONOMICS == ON
        case OSD_MAIN_ERGONOMICS:
            break; 
#endif
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
#define OSD_BG_WIN_SX   3+12*OSD_POSITION_OFFSET
#define OSD_BG_WIN_EX   (OSD_MAIN_WIDTH+OSD_POSITION_OFFSET-1)*12-3
#define OSD_BG_WIN_SY   3*18-5
#define OSD_BG_WIN_EY   (OSD_MAIN_HEIGHT-1)*18

#define OSD_INFO_WIN_SX 3
#define OSD_INFO_WIN_EX 384//360
#define OSD_INFO_WIN_SY 18
#define OSD_INFO_WIN_EY 110

#define OSD_RESET_WIN_SX 3+OSD_DIALOG_SP_POSX*12
#define OSD_RESET_WIN_EX OSD_RESET_WIN_SX+(OSD_DIALOG_WIDTH-1)*12
#define OSD_RESET_WIN_SY 18
#define OSD_RESET_WIN_EY 110

#define OSD_INFO_UL_WIN_SX  3
#define OSD_INFO_UL_WIN_EX  576//555
#define OSD_INFO_UL_WIN_SY  18
#define OSD_INFO_UL_WIN_EY  110


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
            OSDAPI_SetOSDWinSize(DIA_BG_WIN_POS_SX, DIA_BG_WIN_POS_SY, DIA_BG_WIN_POS_EX, DIA_BG_WIN_POS_EY);
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
            OSDAPI_SetOSDWinSize(DIA2_BG_WIN_POS_SX, DIA2_BG_WIN_POS_SY, DIA2_BG_WIN_POS_EX, DIA2_BG_WIN_POS_EY);
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
            OSDAPI_SetOSDWinSize(OSD_BG_WIN_SX, OSD_BG_WIN_SY, OSD_BG_WIN_EX, OSD_BG_WIN_EY);
            OSDAPI_OSDWinOn(OSD_WINDOW5);
            break;
        case OSD_INFO_WIN:
            // inner window
            OSDAPI_SelOSDWin(OSD_WINDOW5);
            RST_WINATTR_ALL(attr);
            attr.ucWinClr = I_BLACK;
            OSDAPI_SetOSDWinAttr(attr);
            OSDAPI_SetOSDWinSize(OSD_INFO_WIN_SX, OSD_INFO_WIN_SY, OSD_INFO_WIN_EX, OSD_INFO_WIN_EY);
            OSDAPI_OSDWinOn(OSD_WINDOW5);
            break;
        case OSD_RESET_WIN:
            OSDAPI_SelOSDWin(OSD_WINDOW5);
            RST_WINATTR_ALL(attr);
            attr.ucWinClr = I_BLACK;
            OSDAPI_SetOSDWinAttr(attr);
            OSDAPI_SetOSDWinSize(OSD_RESET_WIN_SX, OSD_RESET_WIN_SY, OSD_RESET_WIN_EX, OSD_RESET_WIN_EY);
            OSDAPI_OSDWinOn(OSD_WINDOW5);
            break;
        case OSD_OSDUNLOCKINFO_WIN:
            // inner window
            OSDAPI_SelOSDWin(OSD_WINDOW5);
            RST_WINATTR_ALL(attr);
            attr.ucWinClr = I_BLACK;
            OSDAPI_SetOSDWinAttr(attr);
            OSDAPI_SetOSDWinSize(OSD_INFO_UL_WIN_SX, OSD_INFO_UL_WIN_SY, OSD_INFO_UL_WIN_EX, OSD_INFO_UL_WIN_EY);
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

            OSDAPI_SetOSDWinSize(usLayer1WinPosTab[0], 78+id*54, usLayer1WinPosTab[2], 78+55+id*54);
            OSDAPI_OSDWinOn(OSD_WINDOW1);
            break;

        case OSD_LAYER2_WIN:
            OSDAPI_SelOSDWin(OSD_WINDOW1);
            RST_WINATTR_ALL(attr);
            attr.ucWinClr = I_BENQ_BLUE_1;
            OSDAPI_SetOSDWinAttr(attr);

            OSDAPI_SetOSDWinSize(usLayer2WinPosTab[0], 78+id*54, usLayer2WinPosTab[2], 78+55+id*54);
            OSDAPI_OSDWinOn(OSD_WINDOW1);
            break;

        case OSD_LAYER3_WIN:
            OSDAPI_SelOSDWin(OSD_WINDOW1);
            RST_WINATTR_ALL(attr);
            attr.ucWinClr = I_BENQ_BLUE_1;
            OSDAPI_SetOSDWinAttr(attr);

            OSDAPI_SetOSDWinSize(usLayer3WinPosTab[0], 78+id*54, usLayer3WinPosTab[2], 78+55+id*54);
            OSDAPI_OSDWinOn(OSD_WINDOW1);
            break;

        case OSD_LAYER4_WIN:
            OSDAPI_SelOSDWin(OSD_WINDOW1);
            RST_WINATTR_ALL(attr);
            attr.ucWinClr = I_BENQ_BLUE_1;
            OSDAPI_SetOSDWinAttr(attr);

            OSDAPI_SetOSDWinSize(usLayer4WinPosTab[0], 78+id*54, usLayer4WinPosTab[2], 78+55+id*54);
            OSDAPI_OSDWinOn(OSD_WINDOW1);
            break;
        case OSD_DIALOG_LAYER_WIN:
            OSDAPI_SelOSDWin(OSD_WINDOW1);
            RST_WINATTR_ALL(attr);
            attr.ucWinClr = I_BENQ_BLUE_1;
            OSDAPI_SetOSDWinAttr(attr);

            OSDAPI_SetOSDWinSize(usDialogLayerWinPosTab[0], usDialogLayerWinPosTab[1]+6+id*54, usDialogLayerWinPosTab[2], usDialogLayerWinPosTab[1]+6+id*54+55);
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
//    OSDShowSharpness(TRUE, FALSE);    
    OSDShowLayer3SliderBar(SLIBAR_SHARP, TRUE, FALSE);
}

void OSDFocusHue(void)
{
//    OSDShowHue(TRUE, FALSE);
    OSDShowLayer3SliderBar(SLIBAR_HUE, TRUE, FALSE);
}

void OSDFocusSaturation(void)
{
//    OSDShowSaturation(TRUE, FALSE);
    OSDShowLayer3SliderBar(SLIBAR_SAT, TRUE, FALSE);
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
//    Custom_System.ucOSD_preview_temp = UserData.bSensEyeDemo;
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

#if MD_ENABLE_OVERSCAN == ON        
void OSDFocusOverScan(void)
{
    if (IsComponentInput()) {
        Custom_System.ucOSD_preview_temp = UserData.bSOGOverScan;
    }
    else {
        Custom_System.ucOSD_preview_temp = UserData.bOverScan;
    }
}
#endif
#if ENABLE_COLOR_FORMAT == ON    
void OSDFocusColorFormat(void)
{
    //printf("OSDFocusColorFormat 0\n");
    Custom_System.ucOSD_preview_temp = UserData.bColorFormat;
}
#endif
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
//    OSDShowHue(TRUE, FALSE);
    OSDShowLayer3SliderBar(SLIBAR_HUE, TRUE, FALSE);
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
//    OSDShowHue(TRUE, FALSE);
    OSDShowLayer3SliderBar(SLIBAR_HUE, TRUE, FALSE);
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
//    OSDShowSaturation(TRUE, FALSE);
        OSDShowLayer3SliderBar(SLIBAR_SAT, TRUE, FALSE);
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
//    OSDShowSaturation(TRUE, FALSE);
        OSDShowLayer3SliderBar(SLIBAR_SAT, TRUE, FALSE);
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
        OSDUpdateKeyInfo(TRUE,OSD_INFO_DCR_NOTICE_STATE);     
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
#if MD_ENABLE_OVERSCAN == ON        
void OSDSetOverScan()
{
    UserSetAspectRatio();  
    //UserSetOverScan();    
    //SetOSDUpdUsrFlag();
}
#endif
#if ENABLE_COLOR_FORMAT == ON    
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
#endif
void OSDHDMIRGBPCRangeUp()
{
    if (UserData.ucHDMIRGBRange == COLOR_BEG) {
        UserData.ucHDMIRGBRange = COLOR_END;
    }
    else {
        UserData.ucHDMIRGBRange--;
    }
    SetColorSpace();
}
void OSDHDMIRGBPCRangeDown()
{
    UserData.ucHDMIRGBRange = (++UserData.ucHDMIRGBRange)%COLOR_RANGE_NUM;
/*
    if (UserData.ucHDMIRGBRange == COLOR_END) {
        UserData.ucHDMIRGBRange = COLOR_BEG;
    }
    else {
        UserData.ucHDMIRGBRange = COLOR_FULL;
    }*/
    SetColorSpace();      
}

void OSDAudioMuteUp()
{
    UserData.bAudioMute = !UserData.bAudioMute;
    UserSetVolumeAndMute();    
}
#if ENABLE_AUDIO_SELECT == ON    
void OSDAudioSelectUp()
{
    if (UserData.ucInputSource == INPUT_SC_HDMI) {
          UserData.ucHDMIAudioSelect = GetOSDState() - OSD_ITEM_Audio_3_1_STATE;
    }
    else if (UserData.ucInputSource == INPUT_SC_DP) {
          UserData.ucDPAudioSelect = GetOSDState() - OSD_ITEM_Audio_3_1_STATE;
    }
    else {
        
        UserData.ucAudioSelect = GetOSDState() - OSD_ITEM_Audio_3_1_STATE;
        //UserData.ucAudioSelect = (UserData.ucAudioSelect+NUM_AUDIOSELECT-1)%NUM_AUDIOSELECT;
    }    
    OSDAudioSelect();
}
void OSDAudioSelectDown()
{
    if (UserData.ucInputSource == INPUT_SC_HDMI) {
          UserData.ucHDMIAudioSelect = GetOSDState() - OSD_ITEM_Audio_3_1_STATE;
    }
    else if (UserData.ucInputSource == INPUT_SC_DP) {
          UserData.ucDPAudioSelect = GetOSDState() - OSD_ITEM_Audio_3_1_STATE;
    }
    else {
        
        UserData.ucAudioSelect = GetOSDState() - OSD_ITEM_Audio_3_1_STATE;
        //UserData.ucAudioSelect = (UserData.ucAudioSelect+NUM_AUDIOSELECT-1)%NUM_AUDIOSELECT;
    }    

    OSDAudioSelect();
}
#endif

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
#if ENABLE_DPHDMI_AUTO_SWITCH == ON    
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
#endif
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

void OSDShowLowBlueLightStrings(UCHAR x, UCHAR y)
{
    UCHAR i;
    for (i=0; i<ucLBLItemInfoTb[0]; i++) {
        ShowIndentString(TRUE, x, y+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN-2, LowBlueLightTab[i*NUM_OSDLANGS+UserData.ucLanguage]);
    }

}

void OSDShowCurrentResolution(UCHAR x, UCHAR y)
{
    UCHAR i, len, interface;
    USHRT usHactive, usVactive, usVsync;
    UCHAR buff[13],temp[13];
	#if !lrd_dis_benq
    pInputTiming = GetModeHandleInputTiming(_MainChannel);
	#endif
	interface = GetCurrInputInterface();
	#if !lrd_dis_benq
    usHactive = pInputTiming->usModeHActive;
    usVactive = pInputTiming->usModeVActive;
    usVsync = (pInputTiming->usVSyncFreq+5)/10;    
	#else
	usHactive = InputTiming.usModeHActive;
    usVactive = InputTiming.usModeVActive;
    usVsync = (InputTiming.usVSyncFreq+5)/10;   
	#endif
	
	#if 1
    //printf("-->H %d V %d\r\n",usHactive,usVactive);
    if(usVactive>480 && usVactive<484)
        usVactive = 480;
    #endif
	#if !lrd_dis_benq
    memset(buff, 0, GLOB_FONTBUF_LEN);
    memset(temp, 0x20, GLOB_FONTBUF_LEN);
	#else
	for(i=0;i<13;i++)
	{
		buff[i]=0;
	}
	for(i=0;i<13;i++)
	{
		temp[i]=0x20;
	}
	#endif
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
#if OSDLANG_ARAB != OSDLANG_NONE    
    if(UserData.ucLanguage == OSDLANG_ARAB){
        temp[0]=12;
        for(i=0;i<len;i++){
           temp[13-len+i] = buff[1+i];
        }
        for(i=0;i<13;i++){
            buff[i]=temp[i];
        }
    }
#endif    
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    
    if(IsComponentTiming()){
        if((interface == ANALOG_SOG_INPUT0)||(interface == ANALOG_SOG_INPUT1)){
            OSDShowComponentTimingResolution(x, y);
        }
        else if((interface == ANALOG_COM_INPUT0)||(interface == ANALOG_COM_INPUT1)){
			#if !lrd_dis_benq
            if((pInputTiming->usModeIndex == _720x480I_60HZ)||(pInputTiming->usModeIndex == _720x576I_50HZ)){
			#else			
            if((InputTiming.usModeIndex == _720x480I_60HZ)||(InputTiming.usModeIndex == _720x576I_50HZ)){
			#endif
				OSDShowComponentTimingResolution(x, y);
            }
            else{
                ShowIndentString(TRUE, x, y, INDENT_STRING_MAX_LEN-2, buff);
            }
        }
        else if(IsHDMIVideoTiming()){   //(UserData.ucInputSource == INPUT_SC_HDMI){
            OSDShowComponentTimingResolution(x, y);
        }
        else{
            ShowIndentString(TRUE, x, y, INDENT_STRING_MAX_LEN-2, buff);
        }
    }
    else{
        ShowIndentString(TRUE, x, y, INDENT_STRING_MAX_LEN-2, buff);
    }


}

void OSDShowComponentTimingResolution(UCHAR x, UCHAR y)
{
    UCHAR i, len;
    UCHAR buff[13],temp[13];
	#if !lrd_dis_benq
    memset(buff, 0, GLOB_FONTBUF_LEN);
    memset(temp, 0, GLOB_FONTBUF_LEN);
	#else
	for(i=0;i<13;i++)
	{
		buff[i]=0;
	}
	for(i=0;i<13;i++)
	{
		temp[i]=0;
	}
	#endif
	#if !lrd_dis_benq
	switch (pInputTiming->usModeIndex){
	#else
	switch (InputTiming.usModeIndex){
	#endif
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
		#if !lrd_dis_benq
        case _1280x720P_60HZ:
            sprintf(buff,"n720p@60");//130327_1345_OSD#2
            break;
		#endif
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
#if OSDLANG_ARAB != OSDLANG_NONE    
        if(UserData.ucLanguage == OSDLANG_ARAB){
            temp[0]=12;
            for(i=0;i<len;i++){
               temp[13-len+i] = buff[1+i];
            }
            for(i=0;i<13;i++){
                buff[i]=temp[i];
            }
        }
#endif        
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    ShowIndentString(TRUE, x, y, INDENT_STRING_MAX_LEN-2, buff);
}


void OSDShowOptimumResolution(UCHAR x, UCHAR y)
{
    UCHAR i, len;
    USHRT usHactive, usVactive;
    UCHAR buff[13],temp[13];
    //pInputTiming = GetModeHandleInputTiming(_MainChannel);

    usHactive = UserPanelData.usWidth;
    usVactive = UserPanelData.usHeight;
	#if !lrd_dis_benq
    memset(buff, 0, GLOB_FONTBUF_LEN);
    memset(buff, 0x20, GLOB_FONTBUF_LEN);
	#else
	for(i=0;i<13;i++)
	{
		buff[i]=0;
	}
	for(i=0;i<13;i++)
	{
		buff[i]=0x20;
	}
	#endif
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
        if(UserData.ucInputSource == INPUT_SC_VGA){
            sprintf(buff,"n%dx%d@60",1920, 1080);//130327_1345_OSD#2
        }
        else{
            sprintf(buff,"n%dx%d@60",usHactive, usVactive);//130327_1345_OSD#2
        }
    //}

    for (i=0; i<GLOB_FONTBUF_LEN; i++) {
        if (buff[i] == 0)
            break;
    }
    buff[0] = i - 1;
    len = buff[0];
#if OSDLANG_ARAB != OSDLANG_NONE    
        if(UserData.ucLanguage == OSDLANG_ARAB){
            temp[0]=12;
            for(i=0;i<len;i++){
               temp[13-len+i] = buff[1+i];
            }
            for(i=0;i<13;i++){
                buff[i]=temp[i];
            }
        }
#endif    
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    ShowIndentString(TRUE, x, y, INDENT_STRING_MAX_LEN-2, buff);


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

void OSDDisableLayerWindow(void)
{
    OSDAPI_OSDWinOff(OSD_WINDOW3);
    OSDAPI_OSDWinOff(OSD_WINDOW4);
    OSDAPI_OSDWinOff(OSD_WINDOW1);
}

void OSDClearLayer3(void)
{
    UCHAR i;
    OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
    for (i=0; i<LAYER_ITEM_HEIGHT; i++) {
        OSDAPI_WriteXYRepeatChar(TRUE, LAYER3_POSX, LAYER_POSY+i, INDENT_STRING_MAX_LEN, _SPACE_);
    }
}

#if ENABLE_SMART_SCALING == ON
void OSDSmartScalingUp(void)
{
    UserData.ucSmartScaling++;
    if (UserData.ucSmartScaling > MAXIMUM_SMARTSCALING)
        UserData.ucSmartScaling  = MAXIMUM_SMARTSCALING;
    else {
        OSDShowLayer3SliderBar(SLIBAR_SMRTSCALING, TRUE, FALSE);
        UserSetSmartScaling();
    }
    SetOSDUpdUsrFlag();
}

void OSDSmartScalingDown(void)
{
    UserData.ucSmartScaling--;
    if ((UserData.ucSmartScaling > MAXIMUM_SMARTSCALING) ||
        (UserData.ucSmartScaling < MINIMUM_SMARTSCALING))
        UserData.ucSmartScaling  = MINIMUM_SMARTSCALING;
    else {
        OSDShowLayer3SliderBar(SLIBAR_SMRTSCALING, TRUE, FALSE);
        UserSetSmartScaling();
    }
    SetOSDUpdUsrFlag();
}

#endif

void OSDDrawCustomHook (UCHAR x, UCHAR y, UCHAR value)
{
    UCHAR i=0;
    OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
    OSDAPI_WriteXYChar(TRUE, x, y+(Custom_System.ucOSD_preview_temp*HOOK_OFFSET_Y), _SPACE_);//Clear Hook icon
    OSDAPI_SetFontAttr(SelectedStringColor_256);
    OSDAPI_WriteXYChar(TRUE, x, y+(value*HOOK_OFFSET_Y), Hook_Icon);//Update Hook icon
}


void OSDUpdateCustomHook (UCHAR x, UCHAR y, UCHAR value)
{
    OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
    OSDAPI_WriteXYChar(TRUE, x, y+(((!Custom_System.ucOSD_preview_temp)&0x01)*HOOK_OFFSET_Y), _SPACE_);//Clear Hook icon
    OSDAPI_SetFontAttr(SelectedStringColor_256);
    OSDAPI_WriteXYChar(TRUE, x, y+(value*HOOK_OFFSET_Y), Hook_Icon);//Update Hook icon
}

#if 0
void OSDUpdateSelectPageIcon_Bottom(UCHAR IconOffset, UCHAR ButtonAction, UCHAR Layer)
{
    UCHAR i,j,k,m;
    UCHAR Offset_x, Offset_y; 
    
    if (IconOffset == 0) {
	    Offset_x = OSD_SPOFFSET_BOTTOM;
        Offset_y = OSD_MAIN_HEIGHT;
    }
    else if (IconOffset == 1) {
        Offset_x = OSD_CUSTOM_MENU1_SP_POSX; 
        Offset_y = OSD_CUSTOM_MENU1_SP_POSY; 
    }
    else if (IconOffset== 2) {
	    Offset_x = OSD_CUSTOM_MENU2_SP_POSX;
        Offset_y = OSD_CUSTOM_MENU2_SP_POSY; 
    }
    else if (IconOffset== 3) {//ULEric140410
        Offset_x = OSD_DIALOG_SP_POSX;//0;
        Offset_y = OSD_DIALOG_SP_POSY;//OSD_MAIN_HEIGHT;
    }

    if (Layer == DIALOG_LAYER) {//ULEric140410
        //Show Hook
        OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_HOOK_COLOR_B1);
        for (i=0; i<SPBotIconItmNumTab[5]; i++) {
            OSDAPI_WriteXYChar(TRUE, Offset_x+DialogSPBotIconHookPosTab[i*2], Offset_y+DialogSPBotIconHookPosTab[i*2+1], SP_Bot_Icon6_1Bit_1+i);
        }
        //Show Exit
        OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_EXIT_COLOR_B1);
        for (i=0; i<SPBotIconItmNumTab[4]; i++) {
            OSDAPI_WriteXYChar(TRUE, Offset_x+DialogSPBotIconExitPosTab[i*2], Offset_y+DialogSPBotIconExitPosTab[i*2+1], SP_Bot_Icon5_1Bit_1+i);
        }
    }
    else {        
        if (ButtonAction & OSDKEYINFO_OK) {
            m = 6;
        }
        else {
            m = 5;
        }
        k = 0;
        for(j=0;j<m;j++)
        {    
            if((ButtonAction& (OSDKEYINFO_UP<<j)))
            {
                if (j==5)
                    OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_HOOK_COLOR_B1);
                else    
                    OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1_B1);
                for (i=0; i<SPBotIconItmNumTab[j]; i++) {
                        OSDAPI_WriteXYChar(TRUE, Offset_x+SPBotIconPosInfoTab[j][i*2], Offset_y+SPBotIconPosInfoTab[j][i*2+1], SP_Bot_Icon1_1Bit_1+i+k);
                }
            }
            else{//SPACE
                if(j!=4)
                {
                    OSDAPI_SetFontAttr(SELECTPAGE_1BIT_COLOR1_B1);
                    for (i=0; i<SPBotIconItmNumTab[j]; i++) {
                        OSDAPI_WriteXYChar(TRUE, Offset_x+SPBotIconPosInfoTab[j][i*2], Offset_y+SPBotIconPosInfoTab[j][i*2+1], _SPACE_);
                    }
                }
            }
            k+= SPBotIconItmNumTab[j];
        }
    }
}
#endif

void OSDUpdateSelectPageIcon_Left(UCHAR IconOffset, UCHAR ButtonAction, UCHAR Layer)
{
    UCHAR i,j,k,m;
    UCHAR Offset_x, Offset_y; 

    if (IconOffset == 0) {
        Offset_x = 0;
	    Offset_y = OSD_SPOFFSET_ROTATE;
    }
    else if (IconOffset == 1) {
        Offset_x = 0; 
	    Offset_y = OSD_SPOFFSET_ROTATE;
    }
    else if (IconOffset== 2) {
        Offset_x = 0; 
	    Offset_y = OSD_SPOFFSET_ROTATE;
    }
    else if (IconOffset== 3) {//ULEric140410
        Offset_x = 0;
	    Offset_y = OSD_SPOFFSET_ROTATE;
    }

    if (Layer == DIALOG_LAYER) {//ULEric140410
        OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_HOOK_COLOR);
        for (i=0; i<SPIconItmNumTab[5]; i++) {
	     //OSDAPI_WriteXYChar(TRUE, SPIconPosInfoTab[5][i*2], Offset+SPIconPosInfoTab[5][i*2+1]-8, SP_Icon6_1Bit_1+i);
	     OSDAPI_WriteXYChar(TRUE, Offset_x+SPIconPosInfoTab[5][i*2], Offset_y+SPIconPosInfoTab[5][i*2+1]-10, SP_Icon6_1Bit_1+i);
        }
        OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_EXIT_COLOR);
        for (i=0; i<SPIconItmNumTab[4]; i++) {
	     OSDAPI_WriteXYChar(TRUE, Offset_x+SPIconPosInfoTab[4][i*2], Offset_y+SPIconPosInfoTab[4][i*2+1]-15, SP_Icon5_1Bit_1+i);
            //OSDAPI_WriteXYChar(TRUE, SPIconPosInfoTab[4][i*2],Offset+ SPIconPosInfoTab[4][i*2+1]-12, SP_Icon5_1Bit_1+i);
        }
    }
    else {        
        if (ButtonAction & OSDKEYINFO_OK) {
            m = 6;
        }
        else {
            m = 5;
        }
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
                    OSDAPI_WriteXYChar(TRUE, Offset_x+SPIconPosInfoTab[j][i*2], Offset_y+SPIconPosInfoTab[j][i*2+1], SP_Icon1_1Bit_1+i+k);
                }
            }
            else{//SPACE
                if(j!=4)
                {
                    OSDAPI_SetFontAttr(SELECTPAGE_1BIT_COLOR1);
                    for (i=0; i<SPIconItmNumTab[j]; i++) {
                        OSDAPI_WriteXYChar(TRUE, Offset_x+SPIconPosInfoTab[j][i*2], Offset_y+SPIconPosInfoTab[j][i*2+1], _SPACE_);
                    }
                }
            }
            k+= SPIconItmNumTab[j];
        }
    }
}

void OSDUpdateSelectPageIcon_Right(UCHAR IconOffset, UCHAR ButtonAction, UCHAR Layer)
{
    UCHAR i,j,k,m;
    UCHAR Offset_x, Offset_y; 

    if (IconOffset == 0) {
	    //Offset_x = OSD_SPOFFSET_BOTTOM;
        //Offset_y = OSD_MAIN_HEIGHT;
	    Offset_x = OSD_CUSTOM_MENU3_SP_POSX;
        Offset_y = OSD_CUSTOM_MENU3_SP_POSY;
    }
    else if (IconOffset == 1) {
        Offset_x = OSD_CUSTOM_MENU1_SP_POSX; 
        Offset_y = OSD_CUSTOM_MENU1_SP_POSY; 
    }
    else if (IconOffset== 2) {
	    Offset_x = OSD_CUSTOM_MENU2_SP_POSX;
        Offset_y = OSD_CUSTOM_MENU2_SP_POSY; 
    }
    else if (IconOffset== 3) {//ULEric140410
        Offset_x = OSD_DIALOG1_SP_POSX;//0;
        Offset_y = OSD_DIALOG1_SP_POSY;//OSD_MAIN_HEIGHT;
    }

    if (Layer == DIALOG_LAYER) {//ULEric140410
        //Show Hook
        OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_HOOK_COLOR_B1);
        for (i=0; i<SPBotIconItmNumTab[5]; i++) {
            OSDAPI_WriteXYChar(TRUE, Offset_x+DialogSPBotIconHookPosTab[i*2], Offset_y+DialogSPBotIconHookPosTab[i*2+1], SP_Bot_Icon6_1Bit_1+i);
        }
        //Show Exit
        OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_EXIT_COLOR_B1);
        for (i=0; i<SPBotIconItmNumTab[4]; i++) {
            OSDAPI_WriteXYChar(TRUE, Offset_x+DialogSPBotIconExitPosTab[i*2], Offset_y+DialogSPBotIconExitPosTab[i*2+1], SP_Bot_Icon5_1Bit_1+i);
        }
    }
    else {        
        if (ButtonAction & OSDKEYINFO_OK) {
            m = 6;
        }
        else {
            m = 5;
        }
        k = 0;
        for(j=0;j<m;j++)
        {    
            if((ButtonAction& (OSDKEYINFO_UP<<j)))
            {
                if (j==5)
                    OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_HOOK_COLOR_B1);
                else    
                    OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1_B1);
                for (i=0; i<SPBotIconItmNumTab[j]; i++) {
                        OSDAPI_WriteXYChar(TRUE, Offset_x+SPBotIconPosInfoTab[j][i*2], Offset_y+SPBotIconPosInfoTab[j][i*2+1], SP_Bot_Icon1_1Bit_1+i+k);
                }
            }
            else{//SPACE
                if(j!=4)
                {
                    OSDAPI_SetFontAttr(SELECTPAGE_1BIT_COLOR1_B1);
                    for (i=0; i<SPBotIconItmNumTab[j]; i++) {
                        OSDAPI_WriteXYChar(TRUE, Offset_x+SPBotIconPosInfoTab[j][i*2], Offset_y+SPBotIconPosInfoTab[j][i*2+1], _SPACE_);
                    }
                }
            }
            k+= SPBotIconItmNumTab[j];
        }
    }
}

//******************************************************************************
// Prototype:
//  void OSDShowTopPageString(UCHAR id, UCHAR sel, UCHAR CustomerKey)
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
void OSDShowTopPageString(UCHAR id, USHRT index, UCHAR CustomerKey)
{

#define TP_RIGHT_CUSKEY_POSX        2//1
#define TP_RIGHT_CUSKEY_POSY        2
#define TP_RIGHT_CUSKEY_OFFSET_Y    4
#define String_index_offset         11


    UCHAR ucCusYPos,ucCusXPos;
    BOOL benbleflag = TRUE;

    if (CustomerKey == 0) {
	        ucCusXPos = TP_RIGHT_CUSKEY_POSX;
            ucCusYPos = TP_RIGHT_CUSKEY_POSY;
    }
    else if (CustomerKey == 1) {
	        ucCusXPos = TP_RIGHT_CUSKEY_POSX;
            ucCusYPos = (TP_RIGHT_CUSKEY_POSY+TP_RIGHT_CUSKEY_OFFSET_Y);
    }
    else if (CustomerKey == 2) {
	        ucCusXPos = TP_RIGHT_CUSKEY_POSX;
            ucCusYPos = (TP_RIGHT_CUSKEY_POSY+TP_RIGHT_CUSKEY_OFFSET_Y*2);
    }

    if(id == TP_MENU){
            ucCusXPos = TP_RIGHT_CUSKEY_POSX;
            ucCusYPos = (TP_RIGHT_CUSKEY_POSY+TP_RIGHT_CUSKEY_OFFSET_Y*3);
    }else if(id == TP_EXIT){
            ucCusXPos = TP_RIGHT_CUSKEY_POSX;
            ucCusYPos = (TP_RIGHT_CUSKEY_POSY+TP_RIGHT_CUSKEY_OFFSET_Y*4);
    }

    OSDAPI_SetIndentIndex(index+(CustomerKey*String_index_offset));
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    if(CustomerKey == 0)
        benbleflag = GetCustomeKeyState(UserData.ucCustomerKey1);
    else
    if(CustomerKey == 1)
        benbleflag = GetCustomeKeyState(UserData.ucCustomerKey2);
    else
    if(CustomerKey == 2)
        benbleflag = GetCustomeKeyState(UserData.ucCustomerKey3);
    ///////////////////////////////////////////////////////////////
    if (benbleflag == TRUE) 
        OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1_B1);
    else 
        OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1_UNSELECTED_B1);

    

    if(UserData.ucLanguage == OSDLANG_ARAB){
        ShowIndentString(TRUE, TP_RIGHT_CUSKEY_POSX, ucCusYPos,  DIALOG_INDENT_STRING_MAX_LEN, TopPageStrTab1[(id*NUM_OSDLANGS)+UserData.ucLanguage]);   
    }
    else{
    ShowIndentString(TRUE, ucCusXPos+5, ucCusYPos,  DIALOG_INDENT_STRING_MAX_LEN, TopPageStrTab1[(id*NUM_OSDLANGS)+UserData.ucLanguage]);   
    }


}

