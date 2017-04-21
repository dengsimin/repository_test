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


 UCHAR ucMainIconPos[14] = {
// X start position, Y start position
    3+OSD_POSITION_OFFSET, 5,   // Icon1
    3+OSD_POSITION_OFFSET, 8,   // Icon2
    3+OSD_POSITION_OFFSET,11,   // Icon3
    3+OSD_POSITION_OFFSET,14,   // Icon4
    3+OSD_POSITION_OFFSET,17,   // Icon5
    3+OSD_POSITION_OFFSET,20,   // Icon6
    3+OSD_POSITION_OFFSET,23,   // Icon7
};

// Select Page Bottom Icon Tab
#if 1
#define OSD_SP_ICON_POS_X           3
#define OSD_SP_ICON1_POS_Y          1
#define OSD_SP_ICON_POS_Y_OFFSET    4
#define OSD_SP_ICON2_POS_Y  (OSD_SP_ICON1_POS_Y+OSD_SP_ICON_POS_Y_OFFSET)//5
#define OSD_SP_ICON3_POS_Y  (OSD_SP_ICON2_POS_Y+OSD_SP_ICON_POS_Y_OFFSET)//9
#define OSD_SP_ICON4_POS_Y  (OSD_SP_ICON3_POS_Y+OSD_SP_ICON_POS_Y_OFFSET)//13
#define OSD_SP_ICON5_POS_Y  (OSD_SP_ICON4_POS_Y+OSD_SP_ICON_POS_Y_OFFSET)//17

UCHAR SPBotIcon1PosTab[8] = {
    // X Pos, Y Pos
    OSD_SP_ICON_POS_X,      OSD_SP_ICON1_POS_Y,
    OSD_SP_ICON_POS_X+1,    OSD_SP_ICON1_POS_Y,
    OSD_SP_ICON_POS_X,      OSD_SP_ICON1_POS_Y+1,
    OSD_SP_ICON_POS_X+1,    OSD_SP_ICON1_POS_Y+1,
};
UCHAR SPBotIcon2PosTab[8] = {
    // X Pos, Y Pos
    OSD_SP_ICON_POS_X,      OSD_SP_ICON2_POS_Y,
    OSD_SP_ICON_POS_X+1,    OSD_SP_ICON2_POS_Y,
    OSD_SP_ICON_POS_X,      OSD_SP_ICON2_POS_Y+1,
    OSD_SP_ICON_POS_X+1,    OSD_SP_ICON2_POS_Y+1,
};
UCHAR SPBotIcon3PosTab[12] = {
    // X Pos, Y Pos
    OSD_SP_ICON_POS_X,      OSD_SP_ICON3_POS_Y,
    OSD_SP_ICON_POS_X+1,    OSD_SP_ICON3_POS_Y,
    OSD_SP_ICON_POS_X+2,    OSD_SP_ICON3_POS_Y,
    OSD_SP_ICON_POS_X,      OSD_SP_ICON3_POS_Y+1,
    OSD_SP_ICON_POS_X+1,    OSD_SP_ICON3_POS_Y+1,
    OSD_SP_ICON_POS_X+2,    OSD_SP_ICON3_POS_Y+1,
};
UCHAR SPBotIcon4PosTab[6] = {
    // X Pos, Y Pos
    OSD_SP_ICON_POS_X+1,    OSD_SP_ICON4_POS_Y,
    OSD_SP_ICON_POS_X,      OSD_SP_ICON4_POS_Y+1,
    OSD_SP_ICON_POS_X+1,    OSD_SP_ICON4_POS_Y+1,
};
UCHAR SPBotIcon5PosTab[12] = {
    // X Pos, Y Pos
    OSD_SP_ICON_POS_X,      OSD_SP_ICON5_POS_Y,
    OSD_SP_ICON_POS_X+1,    OSD_SP_ICON5_POS_Y,
    OSD_SP_ICON_POS_X+2,    OSD_SP_ICON5_POS_Y,
    OSD_SP_ICON_POS_X,      OSD_SP_ICON5_POS_Y+1,
    OSD_SP_ICON_POS_X+1,    OSD_SP_ICON5_POS_Y+1,
    OSD_SP_ICON_POS_X+2,    OSD_SP_ICON5_POS_Y+1,
};
UCHAR SPBotIcon6PosTab[8] = {
    // X Pos, Y Pos
    //19, 1,
    OSD_SP_ICON_POS_X+1,    9,
    OSD_SP_ICON_POS_X+2,    9,
    OSD_SP_ICON_POS_X,      10,
    OSD_SP_ICON_POS_X+1,    10,
    //21, 2
};
#else
UCHAR SPBotIcon2PosTab[8] = {
    // X Pos, Y Pos
    3, 5,
    4, 5,
    3, 6,
    4, 6
};
UCHAR SPBotIcon3PosTab[12] = {
    // X Pos, Y Pos
    3, 9,
    4, 9,
    5, 9,
    3, 10,
    4, 10,
    5, 10
};
UCHAR SPBotIcon4PosTab[6] = {
    // X Pos, Y Pos
    4, 13,
    3, 14,
    4, 14
};
UCHAR SPBotIcon5PosTab[12] = {
    // X Pos, Y Pos
    3, 17,
    4, 17,
    5, 17,
    3, 18,
    4, 18,
    5, 18
};
UCHAR SPBotIcon6PosTab[8] = {
    // X Pos, Y Pos
    //19, 1,
    4, 9,
    5, 9,
    3, 10,
    4, 10,
    //21, 2
};
#endif

UCHAR *SPBotIconPosInfoTab[6] = {SPBotIcon1PosTab, SPBotIcon2PosTab, SPBotIcon3PosTab, SPBotIcon4PosTab, SPBotIcon5PosTab, SPBotIcon6PosTab};//ULEric140328
UCHAR SPBotIconItmNumTab[6] = {4, 4, 6, 3, 6, 4};

// Select Page Icon Tab
UCHAR SPIcon1PosTab[10] = {
    // X Pos, Y Pos
    2, 3,
    3, 3 ,
    2, 4,
    3, 4,
    4, 4
};
UCHAR SPIcon2PosTab[10] = {
    // X Pos, Y Pos
    2, 7,
    3, 7,
    4, 7,
    2, 8,
    3, 8
};
UCHAR SPIcon3PosTab[10] = {
    // X Pos, Y Pos
    2, 13,
    3, 13,
    4, 13,
    2, 14,
    3, 14
};
UCHAR SPIcon4PosTab[8] = {
    // X Pos, Y Pos
    2, 18,
    3, 18,
    2, 19,
    3, 19
};
UCHAR SPIcon5PosTab[12] = {
    // X Pos, Y Pos
    2, 24,
    3, 24,
    4, 24,
    2, 25,
    3, 25,
    4, 25
};

UCHAR *SPIconPosInfoTab[6] = {SPIcon1PosTab, SPIcon2PosTab, SPIcon3PosTab, SPIcon4PosTab, SPIcon5PosTab, SPIcon3PosTab};//ULEric140328
UCHAR SPIconItmNumTab[6] = {5, 5, 5, 4, 6, 5};

UCHAR ucLayer1StringInfoTb[2] = {
    // X start position, Y start position
   LAYER1_STR_POX, LAYER_STR_POSY,
};

UCHAR ucLayer2ItmNumTb[MAINMENU_ICON_NUM] = {
#if ENABLE_OSD_ANALOG_FUNCTION ==OFF
#if ENABLE_AUTO_POVIT_FUNC == ON
    2,
#else
    1,
#endif
#else
#if ENABLE_AUTO_POVIT_FUNC == ON
    7,
#else
    6,
#endif
#endif
    9,
    OSD_PICTURE_AD_NUM,
    OSD_AUDIO_NUM,
    OSD_SYS_NUM,
#if ENABLE_ERGONOMICS == ON    
    OSD_ERGONOMICS_NUM,
#endif
#if ENABLE_ECO_SENSOR == ON
    OSD_ECO_NUM,
#endif
    //5,
    //3,
    //0,
};

UCHAR ucLayer2ItemInfoTb[2] = {
    // X start position, Y start position
    LAYER2_POSX, LAYER_STR_POSY
};

#if ENABLE_OSD_ANALOG_FUNCTION == OFF
#if ENABLE_AUTO_POVIT_FUNC == ON
UCHAR ucLayer3MItem1NumTb[2] = {
    2,
    OSD_INPUT_NUMBER,//4,
};
#else
UCHAR ucLayer3MItem1NumTb[1] = {
    OSD_INPUT_NUMBER,//4,
};
#endif

#else
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
#endif
UCHAR ucLayer3MItem1InfoTb[2] = {
    // X start position, Y start position
    LAYER3_POSX, LAYER_STR_POSY,
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
    LAYER3_POSX, LAYER_STR_POSY,
};

UCHAR ucLayer3MItem3NumTb[OSD_PICTURE_AD_NUM] = {
    PICTURE_MODE_NUM,
    PICTURE_DUALMODE_NUM,
    0,
#if MD_ENABLE_OVERSCAN == ON         
    2,
#endif    
    DISPLAY_MODE_NUM,//3,
#if ENABLE_SMART_SCALING == ON    
    0,
#endif 
#if ENABLE_COLOR_FORMAT == ON
    COLOR_FORMAT_NUM,
#endif    
    3,
};

UCHAR ucLayer3MItem3InfoTb[2] = {
    // X start position, Y start position
    LAYER3_POSX, LAYER_STR_POSY,
};

UCHAR ucLayer3MItemAudioNumTb[3] = {
    0,
    2,
#if ENABLE_AUDIO_SELECT == ON    
    NUM_AUDIOSELECT,
#endif    
};

UCHAR ucLayer3MItemAudioInfoTb[2] = {
    // X start position, Y start position
    LAYER3_POSX, LAYER_STR_POSY,
};    
    
UCHAR ucLayer3MItem4NumTb[12] = {
    3,
    CUSTOMER_KEY_NUM,//CUS1
    CUSTOMER_KEY_NUM,//CUS2
    CUSTOMER_KEY_NUM,//CUS3
    2,
#if ENABLE_DPHDMI_AUTO_SWITCH == ON    
    2,
#endif    
    2, 
#if ENABLE_DPHDMI_AUTO_SWITCH == ON    
    2,
#endif    
    4,
    2,
    NUM_OSD_SYS_INFORMATION,
    2,
};

UCHAR ucLayer3MItem4InfoTb[2] = {
    // X start position, Y start position
    LAYER3_POSX, LAYER_STR_POSY,
};



UCHAR ucLayer4ItemInfoTb[9] = {
    // item count, X start position, Y start position
    17, LAYER4_POSX, LAYER_STR_POSY,
    6, LAYER4_POSX, LAYER_STR_POSY,
    PICTURE_DUALMODE_ITEM_NUM, LAYER4_POSX, LAYER_STR_POSY,//dual view    
};
UCHAR ucLBLItemInfoTb[3] = {
    4, LAYER4_POSX, LAYER_STR_POSY,
};

#if ENABLE_ERGONOMICS == ON
UCHAR ucLayer3MItemErgoNumTb[OSD_ERGONOMICS_NUM] = {
#if ENABLE_EYE_PROTECT == ON
    2,
    2,
#endif
    2,
    5,
    5,
};

UCHAR ucLayer3MItemErgoInfoTb[2] = {
    // X start position, Y start position
    LAYER3_POSX, LAYER_STR_POSY,
};
#endif

#if ENABLE_ECO_SENSOR == ON
UCHAR ucLayer3MItemECONumTb[OSD_ECO_NUM] = {
    2,
    2,
    3,
};
#endif

UCHAR ucLayer3MItemECOInfoTb[2] = {
    // X start position, Y start position
    LAYER3_POSX, LAYER_STR_POSY,
};

#if ENABLE_ERGONOMICS == ON && ENABLE_ECO_SENSOR == ON
UCHAR *ucLayer3ItmNumTab[MAINMENU_ICON_NUM] = {ucLayer3MItem1NumTb, ucLayer3MItem2NumTb, ucLayer3MItem3NumTb, ucLayer3MItemAudioNumTb, ucLayer3MItem4NumTb,ucLayer3MItemErgoNumTb,ucLayer3MItemECONumTb};
UCHAR *ucLayer3PosInfoTab[MAINMENU_ICON_NUM] = {ucLayer3MItem1InfoTb, ucLayer3MItem2InfoTb, ucLayer3MItem3InfoTb, ucLayer3MItemAudioInfoTb,ucLayer3MItem4InfoTb,ucLayer3MItemErgoInfoTb,ucLayer3MItemECOInfoTb};
#elif ENABLE_ERGONOMICS == ON && ENABLE_ECO_SENSOR == OFF
UCHAR *ucLayer3ItmNumTab[MAINMENU_ICON_NUM] = {ucLayer3MItem1NumTb, ucLayer3MItem2NumTb, ucLayer3MItem3NumTb, ucLayer3MItemAudioNumTb, ucLayer3MItem4NumTb,ucLayer3MItemErgoNumTb};
UCHAR *ucLayer3PosInfoTab[MAINMENU_ICON_NUM] = {ucLayer3MItem1InfoTb, ucLayer3MItem2InfoTb, ucLayer3MItem3InfoTb, ucLayer3MItemAudioInfoTb,ucLayer3MItem4InfoTb,ucLayer3MItemErgoInfoTb};
#else
UCHAR *ucLayer3ItmNumTab[MAINMENU_ICON_NUM] = {ucLayer3MItem1NumTb, ucLayer3MItem2NumTb, ucLayer3MItem3NumTb, ucLayer3MItemAudioNumTb, ucLayer3MItem4NumTb};
UCHAR *ucLayer3PosInfoTab[MAINMENU_ICON_NUM] = {ucLayer3MItem1InfoTb, ucLayer3MItem2InfoTb, ucLayer3MItem3InfoTb, ucLayer3MItemAudioInfoTb,ucLayer3MItem4InfoTb};
#endif

// TopPage Icon Info
// Menu
UCHAR ucMenu_PosTab[9] = {
    // X, Y, font num
    2, 13, 3,
    2, 14, 3,
    2, 15, 3,
};

// Exit
UCHAR ucExit_PosTab[9] = {
    // X, Y, font num
    2, 17, 3,
    2, 18, 3,
    2, 19, 3,
};

//Others
UCHAR ucOthers_PosTab[6] = {
    // Y, font num
    3, 3,
    3, 3,
    3, 3,
};

/*// Auto
UCHAR ucAuto_PosTab[6] = {
    // X, font num
    3, 3,
    3, 3,
    3, 3,
};
// Display
UCHAR ucDisplay_PosTab[6] = {
    // X, font num
    3, 3,
    3, 3,
    3, 3,
};
// Contrast
UCHAR ucContrast_PosTab[6] = {
    // X, font num
    4, 2,
    3, 3,
    4, 2,
};
// Brightness
UCHAR ucBrightness_PosTab[6] = {
    // X, font num
    4, 2,
    3, 3,
    4, 2,
};
// Picture
UCHAR ucPicture_PosTab[6] = {
    // X, font num
    4, 2,
    3, 3,
    3, 3,
};
// Input
UCHAR ucInput_PosTab[6] = {
    // X, font num
    3, 3,
    3, 3,
    3, 3,
};

//ULEric140402
//Volume
UCHAR ucVolume_PosTab[6] = {
    // X, font num
    3, 3,
    3, 3,
    3, 3,
};
//Mute
UCHAR ucMute_PosTab[6] = {
    // X, font num
    3, 3,
    3, 3,
    3, 3,
};
//Low Blue Light Mode
UCHAR ucLowBlueLight_PosTab[6] = {
    // X, font num
    3, 3,
    3, 3,
    3, 3,
};
//Smart Reminder
UCHAR ucSmartReminder_PosTab[6] = {
    // X, font num
    3, 3,
    3, 3,
    3, 3,
};

UCHAR ucAnimation_PosTab[6] = {
    // X, font num
    3, 3,
    3, 3,
    3, 3,
};

UCHAR ucEyeProtect_PosTab[6] = {
    // X, font num
    3, 3,
    3, 3,
    3, 3,
};

UCHAR ucEyeProtectMeter_PosTab[6] = {
    // X, font num
    3, 3,
    3, 3,
    3, 3,
};

UCHAR ucEcoSensor_PosTab[6] = {
    // X, font num
    3, 3,
    3, 3,
    3, 3,
};

UCHAR ucEcoSensorMeter_PosTab[6] = {
    // X, font num
    3, 3,
    3, 3,
    3, 3,
};

UCHAR *ucTopPageIconInfoTab[3] = {
    //ucPicture_PosTab, 
    //ucDisplay_PosTab, 
    //ucBrightness_PosTab, 
    //ucContrast_PosTab, 
    //ucAuto_PosTab , 
    //ucInput_PosTab,
    //ucVolume_PosTab,
    //ucMute_PosTab,
    //ucLowBlueLight_PosTab,
    //ucSmartReminder_PosTab,    
    //ucAnimation_PosTab,
    //ucEyeProtect_PosTab,
    //ucEyeProtectMeter_PosTab,
    //ucEcoSensor_PosTab,
    //ucEcoSensorMeter_PosTab,
//    ucSmartReminder_PosTab,
};*/



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
BOOL bPhaseSlider = FALSE;
UCHAR ucSliderMaxValue = 100;
//BOOL  ClrLayer4Flags  = FALSE;
//******************************************************************************
// E X T E R N A L   V A R I A B L E   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// S T A T I C   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
//ULEric140424
void OSDShowInputNoticeDialogString(void)
{
    UCHAR buff[25],i,j;
    UCHAR *p;
    code UCHAR JA_MessageInputStr1[] = {2, 129, 130, };
    code UCHAR CT_MessageInputStr1[] = {2, 22, 23, };
    code UCHAR CS_MessageInputStr1[] = {2, 22, 23, };
    code UCHAR AR_MessageInputStr1[] = {5,216,137,163,164,130};
    
    code UCHAR *MsgInputTab[] = {
        JA_MessageInputStr1,
        CT_MessageInputStr1,
        CS_MessageInputStr1,
        AR_MessageInputStr1,
    };    

    if(UserData.ucLanguage<OSDLANG_JAPANESE)
        p = DisplayTab[(OSD_DISPLAY_INPUT*NUM_OSDLANGS)+UserData.ucLanguage];
    else if(UserData.ucLanguage == OSDLANG_ARAB)        
        p = InputTab1[(GetInputPortIndex(UserData.ucInputSource)*NUM_OSDLANGS+UserData.ucLanguage)];
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
    if(UserData.ucLanguage == OSDLANG_ARAB)  
        p = MsgInputTab[(UserData.ucLanguage - OSDLANG_JAPANESE)];
    else           
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
   UCHAR x = 0;

   templang = UserData.ucLanguage;
   UserData.ucLanguage = Custom_System.ucLanguage;
//   bSelectTable = OSDFontTble1;   
//   OSDAPI_SetIndentIndex(String_Layer1_Index);
//    OSDAPI_SetAlignType(OSD_ALIGN_LEFT); 
   OSDAPI_WriteXYRepeatChar(FALSE,OSD_TITLESTR_OFFSET_X+OSD_POSITION_OFFSET, 1, OSD_MAIN_TOTAL_WIDTH-(OSD_TITLESTR_OFFSET_X+OSD_POSITION_OFFSET)-10, _SPACE_);

   OSDShowTitleString();
   
   OSDAPI_SetIndentIndex(String_Layer1_Index + 20);       
   
   if(UserData.ucLanguage == OSDLANG_ARAB){
       x = Araboffset2;
   }
   for (i=0; i<MAINMENU_ICON_NUM; i++) {
       if (MainMenuStrTab[i*NUM_OSDLANGS+UserData.ucLanguage] != NULL)
        if(i==OSD_MAIN_SYSTEM)//ULEric140401
            ShowIndentString(FALSE, ucLayer1StringInfoTb[0]-x, ucLayer1StringInfoTb[1]+i*LAYER_STR_OFFSET_Y, (INDENT_STRING_MAX_LEN-1), MainMenuStrTab[i*NUM_OSDLANGS+UserData.ucLanguage]);
        else
           ShowIndentString(FALSE, ucLayer1StringInfoTb[0]-x, ucLayer1StringInfoTb[1]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, MainMenuStrTab[i*NUM_OSDLANGS+UserData.ucLanguage]);
   }
   
   uslay1IndentFontIndex = usIndentFontIndex;
   
   //fnResetLayerIndentCount(STRING_LAYER_2);
   //OSDAPI_SetIndentIndex(fnGetLayerIndentCount(STRING_LAYER_2));
   //OSDAPI_SetIndentIndex(String_Layer2_Index); 
    for (i=0; i<(ucLayer2ItmNumTb[4]>OSD_MAX_LINES ? OSD_MAX_LINES:ucLayer2ItmNumTb[4]); i++) {
        if (Layer2StringTab[4][i*NUM_OSDLANGS+UserData.ucLanguage] != NULL) {
            if(i == OSD_SYS_OSDSET)//ULEric140401
                ShowIndentString(FALSE, ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, Layer2StringTab[4][i*NUM_OSDLANGS+UserData.ucLanguage]);
            else
                ShowIndentString(FALSE, ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, Layer2StringTab[4][i*NUM_OSDLANGS+UserData.ucLanguage]);
        }
    }

#if LAYER_INDENT_COUNT == ON
            OSDAPI_SetIndentIndex(OneBitFont_256_end);
            //OSDAPI_SetIndentIndex(fnGetLayerIndentCount(STRING_LAYER_3));
            //printf("Get layer (%d) Indent index = %d\n", (USHRT)STRING_LAYER_3, (USHRT)fnGetLayerIndentCount(STRING_LAYER_3));
#else
            OSDAPI_SetIndentIndex(String_Layer3_Index);
#endif
        for (i=0; i<(OSDCheckL3ItemNum(4, 0, 8)); i++) {
            if (TestTable2[4][0][i] != NULL) {
                if(i==0){
                    ShowIndentString(FALSE, *(ucLayer3PosInfoTab[4]+0), *(ucLayer3PosInfoTab[4]+1)+i*LAYER_STR_OFFSET_Y, (INDENT_STRING_MAX_LEN-2),
                          TestTable2[4][0][i*NUM_OSDLANGS+UserData.ucLanguage]);    
                }
                else{
                     ShowIndentString(FALSE, *(ucLayer3PosInfoTab[4]+0), *(ucLayer3PosInfoTab[4]+1)+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN-2,
                    TestTable2[4][0][i*NUM_OSDLANGS+UserData.ucLanguage]);
                }
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
    UCHAR index;
    if(GetOSDState() >= OSD_SUBITEM_3_2_1_STATE_BEG && GetOSDState() < OSD_SUBITEM_3_2_1_END){
        index = LAYER4_DUALVIEW;
    }
    else if(GetOSDState() >= OSD_SUBITEM_4_1_1_BEG && GetOSDState() < OSD_SUBITEM_4_1_1_END){
        index = LAYER4_LANGUAGE;
    }
    else if(GetOSDState() >= OSD_SUBITEM_4_1_2_BEG && GetOSDState() < OSD_SUBITEM_4_1_2_END){
    index = LAYER4_TIMER;
    }
    if (ucLayer4ItemInfoTb[index*3] > OSD_MAX_LINES) {
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
        if ((id >= 0 && id <= 7) /*&& isUp == FALSE*/) {
            for (i=0; i<(ucLayer4ItemInfoTb[index*3]>8? 8:ucLayer4ItemInfoTb[index*3]); i++) {
                ShowIndentString(TRUE, ucLayer4ItemInfoTb[index*3+1], ucLayer4ItemInfoTb[index*3+2]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN-2, LanguageTab[i*NUM_OSDLANGS+UserData.ucLanguage]);
            }
        }
        else if ((id >= 8 && id <= 15) /*&& isUp == FALSE*/) {
            for (i=8; i<16; i++) {
                #if 0 // 0 lrd add 
                if(i == LangItemToPoint(OSDLANG_ARAB)){
                    templang_arab = UserData.ucLanguage;
                    UserData.ucLanguage = OSDLANG_ARAB;
                    ShowIndentString(TRUE, ucLayer4ItemInfoTb[index*3+1], ucLayer4ItemInfoTb[index*3+2]+(i-8)*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN-2, LanguageTab[i*NUM_OSDLANGS+UserData.ucLanguage]);
                    UserData.ucLanguage = templang_arab;
                    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
                }
                else
                #endif
                {
                    ShowIndentString(TRUE, ucLayer4ItemInfoTb[index*3+1], ucLayer4ItemInfoTb[index*3+2]+(i-8)*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN-2, LanguageTab[i*NUM_OSDLANGS+UserData.ucLanguage]);
                }
            }
        }
        else if ((id >= 16 && id <= NUM_OSDLANGS) /*&& isUp == FALSE*/) {
            //i = 16 ;
            for (i=16; i<NUM_OSDLANGS; i++) {
                ShowIndentString(TRUE, ucLayer4ItemInfoTb[index*3+1], ucLayer4ItemInfoTb[index*3+2]+(i-16)*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN-2, LanguageTab[i*NUM_OSDLANGS+UserData.ucLanguage]);
            }
            for (i=(NUM_OSDLANGS-16); i<8; i++) {
                ShowIndentString(TRUE, ucLayer4ItemInfoTb[index*3+1], ucLayer4ItemInfoTb[index*3+2]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN-2, LanguageTab[NUM_OSDLANGS*NUM_OSDLANGS]);
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
        //HOOK ICON
        bSelectTable = OSDFontTble1;
        #if 0 // 0 lrd add 
        if (ucOSDLay4langState == OSD_LAY4_LANG_UPDOWN) {    
            if ((LangItemToPoint(templang)/8) == (id/8)) {
                OSDAPI_SetFontAttr(UnSelectedStringColor1_256);
                OSDAPI_WriteXYChar(TRUE, ucLayer4ItemInfoTb[1]+HOOK_LAYER4_OFFSET_X, ucLayer4ItemInfoTb[2]+(LangItemToPoint(templang)-((LangItemToPoint(templang)/8)*8))*LAYER_STR_OFFSET_Y, Hook_Icon);//ULEric140401   
            }
            else {
                OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
                OSDAPI_WriteXYChar(TRUE, ucLayer4ItemInfoTb[1]+HOOK_LAYER4_OFFSET_X, ucLayer4ItemInfoTb[2]+(LangItemToPoint(templang)-((LangItemToPoint(templang)/8)*8))*LAYER_STR_OFFSET_Y, _SPACE_);//ULEric140401   
            }
        }
        #else
        if (ucOSDLay4langState == OSD_LAY4_LANG_UPDOWN) {    
            if ((templang/8) == (id/8)) {
                OSDAPI_SetFontAttr(UnSelectedStringColor1_256);
                OSDAPI_WriteXYChar(TRUE, ucLayer4ItemInfoTb[1]+HOOK_LAYER4_OFFSET_X, ucLayer4ItemInfoTb[2]+(templang-((templang/8)*8))*LAYER_STR_OFFSET_Y, Hook_Icon);//ULEric140401   
            }
            else {
                OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
                OSDAPI_WriteXYChar(TRUE, ucLayer4ItemInfoTb[1]+HOOK_LAYER4_OFFSET_X, ucLayer4ItemInfoTb[2]+(templang-((templang/8)*8))*LAYER_STR_OFFSET_Y, _SPACE_);//ULEric140401   
            }
        }
        #endif
    }
    else {
        // redraw selected string color
        for(i=0;i<ucLayer4ItemInfoTb[index*3];i++)//ULEric140401
        OSDAPI_FillLineAttr(ucLayer4ItemInfoTb[index*3+1], ucLayer4ItemInfoTb[index*3+2]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, UnSelectedStringColor1_256);
    }
    
    if (id >= 16) {
        id -= 16;
    }
    else if(id >= 8) {
        id -= 8;
    }
    if (ucOSDLay4langState == OSD_LAY4_LANG_UPDOWN) {
        UserData.ucLanguage  = templang;
    }

    OSDShowBigWin(OSD_LAYER4_WIN, OSD_WIN_BOARDER_SIZE);      

    // redraw string separater to blue color
    OSDAPI_FillLineAttr(ucLayer4ItemInfoTb[index*3+1], ucLayer4ItemInfoTb[index*3+2]-1+id*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, StringSeparaterLineColor2);
    OSDShowSmallWin(id, OSD_LAYER4_WIN);    
    if(id!=7)//ULEric140401
    OSDAPI_FillLineAttr(ucLayer4ItemInfoTb[index*3+1], ucLayer4ItemInfoTb[index*3+2]+1+id*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, StringSeparaterLineColor2);

    // redraw selected string color
    OSDAPI_FillLineAttr(ucLayer4ItemInfoTb[index*3+1], ucLayer4ItemInfoTb[index*3+2]+id*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, SelectedStringColor_256);

   
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
        OSDAPI_FillLineAttr( ucLBLItemInfoTb[1], ucLBLItemInfoTb[2]+id*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, UnSelectedStringColor1_256);

        OSDAPI_FillLineAttr(ucLBLItemInfoTb[1], id*LAYER_STR_OFFSET_Y+ucLBLItemInfoTb[2]-1, INDENT_STRING_MAX_LEN, UnSelectedStringColor);
     if(id!=7)
            OSDAPI_FillLineAttr(ucLBLItemInfoTb[1], id*LAYER_STR_OFFSET_Y+ucLBLItemInfoTb[2] +1, INDENT_STRING_MAX_LEN, UnSelectedStringColor);
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
         OSDAPI_FillLineAttr(ucLBLItemInfoTb[1], ucLBLItemInfoTb[2]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, UnSelectedStringColor1_256);
     }

    OSDShowBigWin(OSD_LAYER4_WIN, OSD_WIN_BOARDER_SIZE);      

    // redraw string separater to blue color
    OSDAPI_FillLineAttr(ucLBLItemInfoTb[1], ucLBLItemInfoTb[2]-1+id*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, StringSeparaterLineColor2);
    OSDShowSmallWin(id, OSD_LAYER4_WIN);    
    if(id!=7)//ULEric140401
        OSDAPI_FillLineAttr(ucLBLItemInfoTb[1], ucLBLItemInfoTb[2]+1+id*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, StringSeparaterLineColor2);

    // redraw selected string color
    OSDAPI_FillLineAttr(ucLBLItemInfoTb[1], ucLBLItemInfoTb[2]+id*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, SelectedStringColor_256);
    
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
    UCHAR x = 0;

    OSDAPI_SetFontAttr(UnSelectedStringColor1);    
    OSDAPI_SetIndentIndex(String_Layer1_Index +  20);    

    for (i=0; i<MAINMENU_ICON_NUM; i++) {
#if 1
        if(isOSDMainIconAvailable(i)==FALSE){
            OSDAPI_SetFontAttr(DisabledStringColor);
        }
#else
        if(i == MainIcon_ECO){
            if(UserData.bOSDRotation == TRUE)
                OSDAPI_SetFontAttr(DisabledStringColor);
        }
#endif        
        if(UserData.ucLanguage == OSDLANG_ARAB){
            x = Araboffset2;            
        }
        if (MainMenuStrTab[i*NUM_OSDLANGS+UserData.ucLanguage] != NULL)
            ShowIndentString(TRUE, ucLayer1StringInfoTb[0]-x, ucLayer1StringInfoTb[1]+i*3, INDENT_STRING_MAX_LEN, MainMenuStrTab[i*NUM_OSDLANGS+UserData.ucLanguage]);
    }
    uslay1IndentFontIndex = usIndentFontIndex;
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
    //UCHAR i; 
	UCHAR tmp, CustomerKey;

    //isUp = isUp;
    CustomerKey = fnGetCustomerKeyItem();    
    OSDShowCustomMenuDialogString(id, CustomerKey);

    if (id == 8 && isUp == FALSE) {   
//        OSDAPI_SetIndentIndex(uslay1IndentFontIndex);
//        IsPage2 = TRUE;
        OSDAPI_SetFontAttr(ArrowColor1);
        OSDShowArrow(DIA_PRE_PAGE_ARROW_POSX, DIA_PRE_PAGE_ARROW_POSY, PrePage_Arrow1);
        OSDClearArrow(DIA_Next_PAGE_ARROW_POSX, DIA_Next_PAGE_ARROW_POSY, NextPage_Arrow);  
    }
    else if(id == 7 && isUp == TRUE) {
//        OSDAPI_SetIndentIndex(uslay1IndentFontIndex);
//        IsPage2 = FALSE;
        OSDAPI_SetFontAttr(ArrowColor1);
        OSDShowArrow(DIA_Next_PAGE_ARROW_POSX, DIA_Next_PAGE_ARROW_POSY, NextPage_Arrow);
        OSDClearArrow(DIA_PRE_PAGE_ARROW_POSX, DIA_PRE_PAGE_ARROW_POSY, PrePage_Arrow1);  
    }

    
    tmp = ((id > 7)? (id-8):id);
    // string row

    // redraw string separater to blue color
    if (tmp != 0)
        OSDAPI_FillLineAttr(DIALOG_STR_POSX, DIALOG_STR_POSY+tmp*DIALOG_STR_OFFSET_Y-1, INDENT_STRING_MAX_LEN, StringSeparaterLineColor2);

    if (tmp == 0) {
        OSDShowTrianIcon(TRIANGLE_METHOD2, 0, DIALOG_LAYER);
    }
    else {
        OSDShowTrianIcon(TRIANGLE_METHOD1, 0, DIALOG_LAYER);
    }
        OSDShowSmallWin(tmp, OSD_DIALOG_LAYER_WIN);
    
    if (tmp != 7)
        OSDAPI_FillLineAttr(DIALOG_STR_POSX, DIALOG_STR_POSY+tmp*DIALOG_STR_OFFSET_Y+1, INDENT_STRING_MAX_LEN, StringSeparaterLineColor2);

    OSDAPI_FillLineAttr(DIALOG_STR_POSX, DIALOG_STR_POSY+tmp*DIALOG_STR_OFFSET_Y, DIALOG_INDENT_STRING_MAX_LEN, SelectedStringColor_256);
    
    //ULEric140402
    OSDShowCusKeyHook(id, CustomerKey);

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
   // OSDAPI_SetIndentIndex(String_Layer2_Index);
    OSDAPI_SetIndentIndex(uslay1IndentFontIndex);
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
            if((UserData.ucLanguage == OSDLANG_JAPANESE)&&(id == 2)&&(i == 1)){
                bSelectTable = OSDFontTble2;
            }
            else{
                bSelectTable = OSDFontTble1;
            }
            ShowIndentString(TRUE, ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, Layer2StringTab[id][i*NUM_OSDLANGS+UserData.ucLanguage]);
        }
    }
    //while(1){ResetWDTimer();}
    //redraw separate line
    
    // Layer1 icon & string selected
    OSDSelectLayer1Icon(id);
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
    OSDAPI_FillLineAttr(PRE_PAGE_ARROW_POSX, PRE_PAGE_ARROW_POSY, 2, ArrowColor1);
    OSDAPI_FillLineAttr(Next_PAGE_ARROW_POSX+1, Next_PAGE_ARROW_POSY+1, 1, ArrowColor1);
    OSDAPI_FillLineAttr(Next_PAGE_ARROW_POSX, Next_PAGE_ARROW_POSY, 2, ArrowColor1);

    // show layer 2 second level string if necessary
#if LAYER_INDENT_COUNT == ON
    OSDAPI_SetIndentIndex(fnGetLayerIndentCount(STRING_LAYER_2));
    //printf("Get layer (%d) Indent index = %d\n", (USHRT)STRING_LAYER_2, (USHRT)fnGetLayerIndentCount(STRING_LAYER_2));
#else
    OSDAPI_SetIndentIndex(uslay1IndentFontIndex);
  //  OSDAPI_SetIndentIndex(String_Layer2_Index);
#endif
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    OSDAPI_SetFontAttr(UnSelectedStringColor1);

    bSelectTable = OSDFontTble1;

    if (id == 8 && isUp == FALSE) {   
        OSDAPI_SetIndentIndex(uslay1IndentFontIndex);
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
            ShowIndentString(TRUE, ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, Layer2StringTab[ucMenuType][(8+i)*NUM_OSDLANGS+UserData.ucLanguage]);
        }
        OSDAPI_SetFontAttr(ArrowColor1);
        OSDShowArrow(LAYER2_PAGE_ARROW_POX, PRE_PAGE_ARROW_POSY, PrePage_Arrow);
        OSDClearArrow(LAYER2_PAGE_ARROW_POX, Next_PAGE_ARROW_POSY, NextPage_Arrow);  
    }
    else if(id == 7 && isUp == TRUE) {
        OSDAPI_SetIndentIndex(uslay1IndentFontIndex);
        IsPage2 = FALSE;
        for (i=0; i< 8 ; i++) {
            if (OSDIsSubItemValid(i) == FALSE) {
                OSDAPI_SetFontAttr(DisabledStringColor);                        
            }
            else if (i == id) {               
                OSDAPI_SetFontAttr(SelectedStringColor);             
            }
            else {
                OSDAPI_SetFontAttr(UnSelectedStringColor1);
            }
            ShowIndentString(TRUE, ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, Layer2StringTab[ucMenuType][i*NUM_OSDLANGS+UserData.ucLanguage]);
        }
        OSDAPI_SetFontAttr(ArrowColor1);
        OSDShowArrow(LAYER2_PAGE_ARROW_POX, Next_PAGE_ARROW_POSY, NextPage_Arrow);
        OSDClearArrow(LAYER2_PAGE_ARROW_POX, PRE_PAGE_ARROW_POSY, PrePage_Arrow);  
    }
    else {
        for (i=0; i<(IsPage2? (ucLayer2ItmNumTb[ucMenuType]-8):(ucLayer2ItmNumTb[ucMenuType]>8?8: ucLayer2ItmNumTb[ucMenuType])) ; i++) {            
            if (OSDIsSubItemValid(i) == FALSE) {
                Attr = DisabledStringColor;           
            }
            else if(i == (IsPage2?(id-8):id)){//ULEric140516
                Attr = SelectedStringColor;
            }
            else{            
                Attr = UnSelectedStringColor1;    
            }            
            OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0], ucLayer2ItemInfoTb[1]+i*3, INDENT_STRING_MAX_LEN, Attr);
        }
    }    

    tmp = (IsPage2 == TRUE? (id-8):id);        
    // redraw string separater to blue color
    if (id != 7) {
        OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0]-1, ucLayer2ItemInfoTb[1]+tmp*3+1, LAYER2_LENGTH, StringSeparaterLineColor2);
    }
    if (id != 0) {
        OSDAPI_FillLineAttr(ucLayer2ItemInfoTb[0]-1, ucLayer2ItemInfoTb[1]+tmp*3-1, LAYER2_LENGTH, StringSeparaterLineColor2);
    }
    

    if (id == ucMenuType) {
        OSDShowTrianIcon(TRIANGLE_METHOD2, tmp, STRING_LAYER_2);
    }
    else {
        OSDShowTrianIcon(TRIANGLE_METHOD1, tmp, STRING_LAYER_2);
    }

    OSDShowBigWin(OSD_LAYER2_WIN, OSD_WIN_BOARDER_SIZE);
    OSDShowSmallWin(tmp, OSD_LAYER2_WIN);

    //////////////////////
    // show layer 3 string
    if (OSDGetLayer3ItemNum(ucMenuType, id)) {
#if LAYER_INDENT_COUNT == ON
        OSDAPI_SetIndentIndex(OneBitFont_256_end);
        //printf("Get layer (%d) Indent index = %d\n", (USHRT)STRING_LAYER_3, (USHRT)fnGetLayerIndentCount(STRING_LAYER_3));
#else
        OSDAPI_SetIndentIndex(String_Layer3_Index);
#endif
        OSDAPI_SetAlignType(OSD_ALIGN_LEFT);

        // show layer 3 string separater
        OSDShowStringSeparater(STRING_LAYER_3, FALSE);

        // show layer 3 string
        if ((OSDGetLayer3ItemNum(ucMenuType, id))>OSD_MAX_LINES) {//2 page case
            if (ucMenuType == OSD_MAIN_SYSTEM) {//CusKey1/2/3
                if (id == OSD_SYS_CTKEY1) {
                    tmp = UserData.ucCustomerKey1;
                    ucDisable1 = UserData.ucCustomerKey2;
                    ucDisable2 = UserData.ucCustomerKey3;
                }
                else if (id == OSD_SYS_CTKEY2) {
                    tmp = UserData.ucCustomerKey2;
                    ucDisable1 = UserData.ucCustomerKey1;
                    ucDisable2 = UserData.ucCustomerKey3;
                }
                else if (id == OSD_SYS_CTKEY3) {
                    tmp = UserData.ucCustomerKey3;
                    ucDisable1 = UserData.ucCustomerKey1;
                    ucDisable2 = UserData.ucCustomerKey2;
                }
            }
            if (ucMenuType == OSD_MAIN_PICTURE_ADVANCED) {
                if (id == OSD_PICTURE_AD_PIC) {
                    tmp = UserData.ucBFMode;
                    ucDisable1 = 0xFF;
                    ucDisable2 = 0xFF;
                }         
            }  
            //Show Page2 
            if (tmp>(OSD_MAX_LINES-1)) {
                tmp = (OSD_MAX_LINES*2);//ucLayer3ItmNumTab[ucMenuType][id];
                for (i = OSD_MAX_LINES;i<tmp; i++) {
                    if (i >= OSDGetLayer3ItemNum(ucMenuType, id)) {//Clear Empty Item Line
                        OSDAPI_SetFontAttr(ArrowColor1);
                        OSDAPI_WriteXYRepeatChar(TRUE, *(ucLayer3PosInfoTab[ucMenuType]+0),*(ucLayer3PosInfoTab[ucMenuType]+1)+(i-OSD_MAX_LINES)*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, _SPACE_);
                    }
                    else {
                        if(i==ucDisable1||i==ucDisable2){
                            OSDAPI_SetFontAttr(DisabledStringColor_256);
                        }
                        else{    
                            OSDAPI_SetFontAttr(UnSelectedStringColor_256);
                        }
                        #if 0
                        ShowIndentString(TRUE, *(ucLayer3PosInfoTab[ucMenuType]+0), *(ucLayer3PosInfoTab[ucMenuType]+1)+(i-OSD_MAX_LINES)*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN,
                            TestTable2[ucMenuType][id][OSDStringRemap(i)*NUM_OSDLANGS+UserData.ucLanguage]);
                        #else
                        ShowIndentString(TRUE, *(ucLayer3PosInfoTab[ucMenuType]+0), *(ucLayer3PosInfoTab[ucMenuType]+1)+(i-OSD_MAX_LINES)*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN-2,
                            TestTable2[ucMenuType][id][i*NUM_OSDLANGS+UserData.ucLanguage]);
                        #endif
                    }
                }
                OSDUpdateArrowIcon(ArrowColor2,LastArrowType,STRING_LAYER_3);//ULEric140403
            }
            else {//Show Page1            
                tmp = OSD_MAX_LINES;
                for (i = 0;i<tmp; i++) {
                    if (i==ucDisable1||i==ucDisable2) {
                        OSDAPI_SetFontAttr(DisabledStringColor_256);
                    }
                    else {
                        OSDAPI_SetFontAttr(UnSelectedStringColor_256);
                    }
                    #if 0
                    ShowIndentString(TRUE, *(ucLayer3PosInfoTab[ucMenuType]+0), *(ucLayer3PosInfoTab[ucMenuType]+1)+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN,
                        TestTable2[ucMenuType][id][OSDStringRemap(i)*NUM_OSDLANGS+UserData.ucLanguage]);
                    #else
                    ShowIndentString(TRUE, *(ucLayer3PosInfoTab[ucMenuType]+0), *(ucLayer3PosInfoTab[ucMenuType]+1)+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN-2,
                        TestTable2[ucMenuType][id][i*NUM_OSDLANGS+UserData.ucLanguage]);
                    #endif
                }
                OSDUpdateArrowIcon(ArrowColor2,TopArrowType,STRING_LAYER_3);//ULEric140403
            }
         }
         else {//1 page case
            if (ucMenuType == OSD_MAIN_SYSTEM && (id==(OSD_SYS_CTKEY1-1)||id==(OSD_SYS_CTKEY3+1))) {//ULEric140403
                OSDUpdateArrowIcon(CLEAR_1BIT_COLOR,ClearArrowType,STRING_LAYER_3);
            }
            if (ucMenuType == OSD_MAIN_PICTURE_ADVANCED && (id!=OSD_PICTURE_AD_PIC)) {//ULEric140403
                OSDUpdateArrowIcon(CLEAR_1BIT_COLOR,ClearArrowType,STRING_LAYER_3);
            }
                 
            for (i=0; i<OSDGetLayer3ItemNum(ucMenuType, id); i++) {
                if (TestTable2[ucMenuType][id][i] != NULL) {
                    ucSubMenuType = id;
                    if (OSDIsLayer3ItemValid(i)==FALSE) {
                        OSDAPI_SetFontAttr(DisabledStringColor_256);
                    }
                    else{
                        OSDAPI_SetFontAttr(UnSelectedStringColor_256);
                    }
                    #if 0
                    ShowIndentString(TRUE, *(ucLayer3PosInfoTab[ucMenuType]+0), *(ucLayer3PosInfoTab[ucMenuType]+1)+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN,
                    TestTable2[ucMenuType][id][OSDStringRemap(i)*NUM_OSDLANGS+UserData.ucLanguage]);
                    #else
                    ShowIndentString(TRUE, *(ucLayer3PosInfoTab[ucMenuType]+0), *(ucLayer3PosInfoTab[ucMenuType]+1)+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN-2,
                    TestTable2[ucMenuType][id][i*NUM_OSDLANGS+UserData.ucLanguage]);
                    #endif
                }
            }
            if ((ucMenuType == OSD_MAIN_SYSTEM) && (id == OSD_SYS_INFORMATION)) {//information
                OSDShowInfo();
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
    UCHAR i, tmp_submenu, tmp_id;

    tmp_submenu = (ucSubMenuType>7)? (ucSubMenuType-8): ucSubMenuType;
    tmp_id = (id > 7? (id-8):id);
    //printf("Sel L3 ID=%bx\r\n",tmp_id);
    bSelectTable = OSDFontTble1;
    if (OSDGetLayer3ItemNum(ucMenuType,ucSubMenuType)) {
        if (OSDGetLayer3ItemNum(ucMenuType,ucSubMenuType)>8) {  //2 page
            // redraw up down icon to white
#if LAYER_INDENT_COUNT == ON
            OSDAPI_SetIndentIndex(OneBitFont_256_end);
            //printf("Get layer (%d) Indent index = %d\n", (USHRT)STRING_LAYER_3, (USHRT)fnGetLayerIndentCount(STRING_LAYER_3));
#else
            OSDAPI_SetIndentIndex(String_Layer3_Index);
#endif
            OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
            if (id > 7) {//page 2
                OSDClearItemHookIcon(STRING_LAYER_3);//add

                if (ucMenuType == OSD_MAIN_SYSTEM || ucMenuType == OSD_MAIN_PICTURE_ADVANCED) {
                    OSDShowLayer3PageHookIcon(LAYER3_PAGE_2);
                }                
                // show layer 3 string
                OSDShowLayer3PageString(LAYER3_PAGE_2);
                OSDUpdateArrowIcon(ArrowColor1,LastArrowType,STRING_LAYER_3);
            }
            else {
                if (ucMenuType == OSD_MAIN_SYSTEM || ucMenuType == OSD_MAIN_PICTURE_ADVANCED) {   
                    OSDShowLayer3PageHookIcon(LAYER3_PAGE_1);
                }
                // show layer 3 string
                OSDShowLayer3PageString(LAYER3_PAGE_1);
                OSDUpdateArrowIcon(ArrowColor1,TopArrowType,STRING_LAYER_3);
            }
        }
        else { //Item < 8
#if LAYER_INDENT_COUNT == ON
            OSDAPI_SetIndentIndex(OneBitFont_256_end);
            //printf("Get layer (%d) Indent index = %d\n", (USHRT)STRING_LAYER_3, (USHRT)fnGetLayerIndentCount(STRING_LAYER_3));
#else
            OSDAPI_SetIndentIndex(String_Layer3_Index);
#endif
            OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
            OSDShowLayer3PageString(LAYER3_PAGE_1);
        }
        //printf("tmp_id=%d\r\n",(USHRT)tmp_id);


        if (tmp_id == tmp_submenu) {
            OSDShowTrianIcon(TRIANGLE_METHOD2, tmp_id, STRING_LAYER_3);
        }
        else {
            OSDShowTrianIcon(TRIANGLE_METHOD1, tmp_id, STRING_LAYER_3);
        }
        
        OSDShowSmallWin(tmp_id, OSD_LAYER3_WIN);        
        // redraw layer3 string to white color
        for (i=0; i<(OSDCheckL3ItemNum(ucMenuType,ucSubMenuType,8)); i++) {
            if (i == tmp_id) {
                // redraw layer3 selected string to Black color
                OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, SelectedStringColor_256);

                // redraw string separater to blue color
                if (tmp_id != 0)
                    OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]-1+tmp_id*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, StringSeparaterLineColor2);
                if (tmp_id != 7)
                    OSDAPI_FillLineAttr(ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+1+tmp_id*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, StringSeparaterLineColor2);
            }
            else {
            }
        }
        //printf("select layer 3 item triangle, tmp = %d, tmp2 = %d\n", (USHRT)tmp, (USHRT)tmp2);
    }
    else {
        // show layer3 triangle icon
        OSDShowTrianIcon(TRIANGLE_METHOD1, tmp_id, STRING_LAYER_3);
    }
    OSDShowBigWin(OSD_LAYER3_WIN, OSD_WIN_BOARDER_SIZE);

    OSDShowLayer4(id);
    
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
#define TP_RIGHT_CUSKEY_POSX        2//1
#define TP_RIGHT_CUSKEY_POSY        1
#define TP_RIGHT_CUSKEY_OFFSET_Y    4

    UCHAR i;
    UCHAR ucXPos_Line1, ucXPos_Line3, ucXPos_Line2;
    UCHAR ucCusYPos,ucCusXPos;
    UCHAR IconPos;
    BOOL benbleflag = TRUE;
    // a temperary buffer to hold the toppage icon font index
    UCHAR ucTopPageIconBuffer[12] = {0};

    if(UserData.bOSDRotation == TRUE){
        IconPos = OSD_TOPPAGE_POS_ROT;
    }
    else{
        IconPos = OSD_TOPPAGE_POS_NML;
    }
    
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
    if(UserData.ucLanguage == OSDLANG_ARAB){
        ucCusXPos = (OSD_SP_WIDTH-1)-3;
    }
    if (sel == 0) {
        OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1);
    }
    else if (sel == 2) {
        OSDAPI_SetFontAttr(MAINICON_1BIT_COLOR1);
    }
    else {
        OSDAPI_SetFontAttr(DialogIconColor1);
        //ucXOffset_Line2 = 0;
        if ((id == TP_BRIGHTNESS)||(id == TP_CONTRAST)){
            ucXPos_Line1 = DIALOG2_ICON_POSX+1;//3;
            ucXPos_Line2 = DIALOG2_ICON_POSX;
            ucXPos_Line3 = DIALOG2_ICON_POSX+1;//3;
            //ucXOffset_Line2 = (DIALOG2_POSITION_OFFSET-DIALOG_POSITION_OFFSET);
        }
        else if((id == TP_VOLUME)
#if ENABLE_CUSTOMKEY_ANIMATION == ON            
            ||(id == TP_ANIMATION)
#endif            
            ){
            ucXPos_Line1 = DIALOG2_ICON_POSX;//3;
            ucXPos_Line2 = DIALOG2_ICON_POSX;
            ucXPos_Line3 = DIALOG2_ICON_POSX;//3;
            //ucXOffset_Line2 = (DIALOG2_POSITION_OFFSET-DIALOG_POSITION_OFFSET);
        } 
        else if (id == TP_PICTUREMODE) {
            ucXPos_Line1 = DIALOG_ICON_POSX+1;//3;
            ucXPos_Line2 = DIALOG_ICON_POSX;
            ucXPos_Line3 = DIALOG_ICON_POSX;//2
        }
        else {
            ucXPos_Line1 = DIALOG_ICON_POSX;//2;
            ucXPos_Line2 = DIALOG_ICON_POSX;
            ucXPos_Line3 = DIALOG_ICON_POSX;//2;
        }
        //printf("%bx bx bx\r\n",ucXPos_Line1,ucXPos_Line2,ucXPos_Line3);
    }

    // font index copy to a buffer to save code memory.
    switch (id) {
        case TP_BRIGHTNESS:
            for (i=0; i<(TP_1Bit_Brightness_End-TP_1Bit_Brightness_Start); i++) {
                if (IconPos == OSD_TOPPAGE_POS_NML)
                    ucTopPageIconBuffer[i] = TP_1Bit_Brightness_Start+i;
                else		 
                    ucTopPageIconBuffer[i] = TP_1Bit_B1_Brightness_Start+i;
            }
            break;
#if ENABLE_CUSTOMKEY_AUTOADJ == ON                         
        case TP_AUTOADJUSTMENT:
            for (i=0; i<(TP_1Bit_Auto_End-TP_1Bit_Auto_Start); i++) {
                if (IconPos == OSD_TOPPAGE_POS_NML)
                    ucTopPageIconBuffer[i] = TP_1Bit_Auto_Start+i;
                else		 
                    ucTopPageIconBuffer[i] = TP_1Bit_B1_Auto_Start+i;
            }
            break;
#endif            
        case TP_CONTRAST:
            for (i=0; i<(TP_1Bit_Contrast_End-TP_1Bit_Contrast_Start); i++) {
                if (IconPos == OSD_TOPPAGE_POS_NML)
                    ucTopPageIconBuffer[i] = TP_1Bit_Contrast_Start+i;
                else		 
                    ucTopPageIconBuffer[i] = TP_1Bit_B1_Contrast_Start+i;
            }
            break;
        case TP_DISPLAYMODE:
            for (i=0; i<(TP_1Bit_DisplayMode_End-TP_1Bit_DisplayMode_Start); i++) {
                if (IconPos == OSD_TOPPAGE_POS_NML)
                    ucTopPageIconBuffer[i] = TP_1Bit_DisplayMode_Start+i;
                else		 
                    ucTopPageIconBuffer[i] = TP_1Bit_B1_DisplayMode_Start+i;
            }
            break;

        case TP_PICTUREMODE:
            for (i=0; i<(TP_1Bit_Picture_End-TP_1Bit_Picture_Start); i++) {
                if (IconPos == OSD_TOPPAGE_POS_NML)
                    ucTopPageIconBuffer[i] = TP_1Bit_Picture_Start+i;
                else		 
                    ucTopPageIconBuffer[i] = TP_1Bit_B1_Picture_Start+i;
            }
            break;
        case TP_EXIT:			
	        for (i=0; i<(TP_1Bit_Exit_End-TP_1Bit_Exit_Start); i++) {
	            if (IconPos == OSD_TOPPAGE_POS_NML)
                    ucTopPageIconBuffer[i] = TP_1Bit_Exit_Start+i;
                else		 
                    ucTopPageIconBuffer[i] = TP_1Bit_B1_Exit_Start+i;
            }
            break;
        case TP_INPUT:		
	        for (i=0; i<(TP_1Bit_Menu_End-TP_1Bit_Input_Start); i++) {
	            if (IconPos == OSD_TOPPAGE_POS_NML)
                    ucTopPageIconBuffer[i] = TP_1Bit_Input_Start+i;
		        else
                    ucTopPageIconBuffer[i] = TP_1Bit_B1_Input_Start+i;
            }
            break;
        case TP_MENU:		
	        for (i=0; i<(TP_1Bit_Menu_End-TP_1Bit_Menu_Start); i++) {
	            if (IconPos == OSD_TOPPAGE_POS_NML)
		            ucTopPageIconBuffer[i] = TP_1Bit_Menu_Start+i;
		        else
                    ucTopPageIconBuffer[i] = TP_1Bit_B1_Menu_Start+i;
            }
            break;
            
    //ULEric140402                    
     case TP_VOLUME:
            if((UserData.bAudioMute)&&(sel == 1)){         
                 for (i=0; i<(TP_1Bit_Mute_End-TP_1Bit_Mute_Start); i++) {
                     if (IconPos == OSD_TOPPAGE_POS_NML)
                    ucTopPageIconBuffer[i] = TP_1Bit_Mute_Start+i;
                else		 
                    ucTopPageIconBuffer[i] = TP_1Bit_B1_Mute_Start+i;
                 }                
             }
            else{		
		    	for (i=0; i<(TP_1Bit_Volume_End-TP_1Bit_Volume_Start); i++) {
		   			if (IconPos == OSD_TOPPAGE_POS_NML)
                         ucTopPageIconBuffer[i] = TP_1Bit_Volume_Start+i;    
					else
                         ucTopPageIconBuffer[i] = TP_1Bit_B1_Volume_Start+i;
		   		}    
            }
            break;
     case TP_MUTE:
            for (i=0; i<(TP_1Bit_Mute_End-TP_1Bit_Mute_Start); i++) {
                if (IconPos == OSD_TOPPAGE_POS_NML)
                    ucTopPageIconBuffer[i] = TP_1Bit_Mute_Start+i;
                else		 
                    ucTopPageIconBuffer[i] = TP_1Bit_B1_Mute_Start+i;
            }
            break;
#if ENABLE_CUSTOMKEY_LBL == ON            
    case TP_LOWBLUELIGHT:
            for (i=0; i<(TP_1Bit_LowBlueLight_End-TP_1Bit_LowBlueLight_Start); i++) {
                if (IconPos == OSD_TOPPAGE_POS_NML)	
		            ucTopPageIconBuffer[i] = TP_1Bit_LowBlueLight_Start+i;
                else
                    ucTopPageIconBuffer[i] = TP_1Bit_B1_LowBlueLight_Start+i;
            	}
            break;
#endif            
#if ENABLE_CUSTOMKEY_ANIMATION == ON                        
    case TP_ANIMATION:
            for (i=0; i<(TP_1Bit_Animation_End-TP_1Bit_Animation_Start); i++) {
                if (IconPos == OSD_TOPPAGE_POS_NML)
                    ucTopPageIconBuffer[i] = TP_1Bit_Animation_Start+i;
                else		 
                    ucTopPageIconBuffer[i] = TP_1Bit_B1_Animation_Start+i;
            }
            break;    
#endif            
#if ENABLE_CUSTOMKEY_CAD == ON            
    case TP_CAD:
            for (i=0; i<(TP_1Bit_CAD_End-TP_1Bit_CAD_Start); i++) {
                if (IconPos == OSD_TOPPAGE_POS_NML)
                    ucTopPageIconBuffer[i] = TP_1Bit_CAD_Start+i;
                else		 
                    ucTopPageIconBuffer[i] = TP_1Bit_B1_CAD_Start+i;
            }
            break;   
#endif            
#if ENABLE_EYE_PROTECT == ON
    case TP_EYE_PROTECT:
            for (i=0; i<(TP_1Bit_Eye_Protect_End-TP_1Bit_Eye_Protect_Start); i++) {
                if (IconPos == OSD_TOPPAGE_POS_NML)
                    ucTopPageIconBuffer[i] = TP_1Bit_Eye_Protect_Start+i;
                else		 
                    ucTopPageIconBuffer[i] = TP_1Bit_B1_Eye_Protect_Start+i;
            }
            break;     
    case TP_EYE_PROTECT_METER:
            for (i=0; i<(TP_1Bit_Eye_Protect_Meter_End-TP_1Bit_Eye_Protect_Meter_Start); i++) {
                if (IconPos == OSD_TOPPAGE_POS_NML)
                    ucTopPageIconBuffer[i] = TP_1Bit_Eye_Protect_Meter_Start+i;
                else		 
                    ucTopPageIconBuffer[i] = TP_1Bit_B1_Eye_Protect_Meter_Start+i;
            }
            break;     
#endif
#if ENABLE_ECO_SENSOR == ON
    case TP_ECO_SENSOR:
            for (i=0; i<(TP_1Bit_Eco_Sensor_End-TP_1Bit_Eco_Sensor_Start); i++) {
                if (IconPos == OSD_TOPPAGE_POS_NML)
                    ucTopPageIconBuffer[i] = TP_1Bit_Eco_Sensor_Start+i;
                else		 
                    ucTopPageIconBuffer[i] = TP_1Bit_B1_Eco_Sensor_Start+i;
            }
            break;     
    case TP_ECO_SENSOR_METER:
            for (i=0; i<(TP_1Bit_Eco_Sensor_Meter_End-TP_1Bit_Eco_Sensor_Meter_Start); i++) {
                if (IconPos == OSD_TOPPAGE_POS_NML)
                    ucTopPageIconBuffer[i] = TP_1Bit_Eco_Sensor_Meter_Start+i;
                else		 
                    ucTopPageIconBuffer[i] = TP_1Bit_B1_Eco_Sensor_Meter_Start+i;
            }
            break;   
#endif
#if ENABLE_ERGONOMICS == ON
    case TP_SMARTREMINDER:
            for (i=0; i<(TP_1Bit_SmartReminder_End-TP_1Bit_SmartReminder_Start); i++) {
                if (IconPos == OSD_TOPPAGE_POS_NML)
                    ucTopPageIconBuffer[i] = TP_1Bit_SmartReminder_Start+i;
                else		 
                    ucTopPageIconBuffer[i] = TP_1Bit_B1_SmartReminder_Start+i;
            }
            break;        
#endif            
    }
    
    bSelectTable = OSDFontTble1;
    if (id == TP_EXIT) {
        if (IconPos == OSD_TOPPAGE_POS_NML){
        	OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_EXIT_COLOR);
        }
        else{
        	OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_EXIT_COLOR_B1);        
        }		
        ucCusYPos = (TP_RIGHT_CUSKEY_POSY+TP_RIGHT_CUSKEY_OFFSET_Y*4);
        if(UserData.ucLanguage == OSDLANG_ARAB){
            //ucCusXPos = (OSD_SP_WIDTH-1)-3;
            OSDAPI_WriteXYString(TRUE, ucCusXPos, ucExit_PosTab[0*3+1], ucExit_PosTab[0*3+2] , &ucTopPageIconBuffer[0]);
            OSDAPI_WriteXYString(TRUE, ucCusXPos, ucExit_PosTab[1*3+1], ucExit_PosTab[1*3+2] , &ucTopPageIconBuffer[ucExit_PosTab[0*3+2]]);
            OSDAPI_WriteXYString(TRUE, ucCusXPos, ucExit_PosTab[2*3+1], ucExit_PosTab[2*3+2] , &ucTopPageIconBuffer[ucExit_PosTab[0*3+2] + ucExit_PosTab[1*3+2]]);
        }
        else{
   	    OSDAPI_WriteXYString(TRUE, ucExit_PosTab[0*3], ucExit_PosTab[0*3+1], ucExit_PosTab[0*3+2] , &ucTopPageIconBuffer[0]);
        OSDAPI_WriteXYString(TRUE, ucExit_PosTab[1*3], ucExit_PosTab[1*3+1], ucExit_PosTab[1*3+2] , &ucTopPageIconBuffer[ucExit_PosTab[0*3+2]]);
        OSDAPI_WriteXYString(TRUE, ucExit_PosTab[2*3], ucExit_PosTab[2*3+1], ucExit_PosTab[2*3+2] , &ucTopPageIconBuffer[ucExit_PosTab[0*3+2] + ucExit_PosTab[1*3+2]]);
    }
    }
    else if (id == TP_MENU) {
	    if (IconPos == OSD_TOPPAGE_POS_ROT)
	        OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1_B1);
        ucCusYPos = (TP_RIGHT_CUSKEY_POSY+TP_RIGHT_CUSKEY_OFFSET_Y*3);
        
        if(UserData.ucLanguage == OSDLANG_ARAB){
            //ucCusXPos = (OSD_SP_WIDTH-1)-3;
            OSDAPI_WriteXYString(TRUE, ucCusXPos, ucMenu_PosTab[0*3+1], ucMenu_PosTab[0*3+2] , &ucTopPageIconBuffer[0]);
            OSDAPI_WriteXYString(TRUE, ucCusXPos, ucMenu_PosTab[1*3+1], ucMenu_PosTab[1*3+2] , &ucTopPageIconBuffer[ucMenu_PosTab[0*3+2]]);
            OSDAPI_WriteXYString(TRUE, ucCusXPos, ucMenu_PosTab[2*3+1], ucMenu_PosTab[2*3+2] , &ucTopPageIconBuffer[ucMenu_PosTab[0*3+2] + ucMenu_PosTab[1*3+2]]);
        }
        else{
        OSDAPI_WriteXYString(TRUE, ucMenu_PosTab[0*3], ucMenu_PosTab[0*3+1], ucMenu_PosTab[0*3+2] , &ucTopPageIconBuffer[0]);
        OSDAPI_WriteXYString(TRUE, ucMenu_PosTab[1*3], ucMenu_PosTab[1*3+1], ucMenu_PosTab[1*3+2] , &ucTopPageIconBuffer[ucMenu_PosTab[0*3+2]]);
        OSDAPI_WriteXYString(TRUE, ucMenu_PosTab[2*3], ucMenu_PosTab[2*3+1], ucMenu_PosTab[2*3+2] , &ucTopPageIconBuffer[ucMenu_PosTab[0*3+2] + ucMenu_PosTab[1*3+2]]);
    }	
    }	
    else {
        if (sel == 0) {
            ///////////////////////////////////////////////////////////////
            if(CustomerKey == 0)
                    benbleflag = GetCustomeKeyState(UserData.ucCustomerKey1);
            else
            if(CustomerKey == 1)
                    benbleflag = GetCustomeKeyState(UserData.ucCustomerKey2);
            else
            if(CustomerKey == 2)
                    benbleflag = GetCustomeKeyState(UserData.ucCustomerKey3);
            ///////////////////////////////////////////////////////////////
            if (benbleflag == TRUE) {
                if (IconPos == OSD_TOPPAGE_POS_NML){
                    OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1);
                }
                else{
                    OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1_B1);
                }
            }
            else {
                if (IconPos == OSD_TOPPAGE_POS_NML){
                    OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1_UNSELECTED);
                }
                else{
                    OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1_UNSELECTED_B1);
                }                
            }
            OSDAPI_WriteXYString(TRUE, ucCusXPos, ucCusYPos,
                            ucOthers_PosTab[0*2+1] , &ucTopPageIconBuffer[0]);
            OSDAPI_WriteXYString(TRUE, ucCusXPos, ucCusYPos+1,
                            ucOthers_PosTab[1*2+1] , &ucTopPageIconBuffer[ucOthers_PosTab[0*2+1]]);
            OSDAPI_WriteXYString(TRUE, ucCusXPos, ucCusYPos+2,
                            ucOthers_PosTab[2*2+1] , &ucTopPageIconBuffer[ucOthers_PosTab[0*2+1] + ucOthers_PosTab[1*2+1]]);
        }
        else {  //dialog
            OSDAPI_WriteXYString(TRUE, ucXPos_Line1, DIALOG_ICON_POSY, ucOthers_PosTab[0*2+1] , &ucTopPageIconBuffer[0]);
            OSDAPI_WriteXYString(TRUE, ucXPos_Line2, DIALOG_ICON_POSY+1, ucOthers_PosTab[1*2+1] , &ucTopPageIconBuffer[ucOthers_PosTab[0*2+1]]);
            OSDAPI_WriteXYString(TRUE, ucXPos_Line3, DIALOG_ICON_POSY+2, ucOthers_PosTab[2*2+1] , &ucTopPageIconBuffer[ucOthers_PosTab[0*2+1] + ucOthers_PosTab[1*2+1]]);
#if 0 // ToppageIconOnly 
            // show dialog title string
          //  OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_STRING_COLOR1);
          //  ShowIndentString(TRUE, DIA_TITLE_STR_POSX, DIA_TITLE_STR_POSY, DIA_TITLE_STR_LENGTH, TopPageStrTab[id*NUM_OSDLANGS+UserData.ucLanguage]);
#endif
        }
    }
#if 0           
                OSDAPI_SetIndentIndex(String_TopPage_Index);
                OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
                OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_STRING_COLOR1);
                //OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1);
                printf("TP_1Bit_Start = %d\r\n",(USHRT)TP_1Bit_Start);
                printf("TP_1Bit_B1_Start = %d\r\n",(USHRT)TP_1Bit_B1_Start);
                //printf("index1 = %d\r\n",(USHRT)String_TopPage_Index);
                ShowIndentString(TRUE, ucCusXPos+5/*ucTopPageIconInfoTab[id][1*2]+5*/, ucCusYPos+1, 2, TopPageStrTab[id*NUM_OSDLANGS+UserData.ucLanguage]);
#endif
}

void OSDShowSourceIcon(UCHAR id, UCHAR Source)
{
      UCHAR font_index, h_position,v_position;
      UCHAR Page_Pos;

      //Page_Pos = SELECT_PAGE_POS;
      if(UserData.bOSDRotation == TRUE){
          Page_Pos = OSD_TOPPAGE_POS_ROT;
      }
      else{
          Page_Pos = OSD_TOPPAGE_POS_NML;
      }
      h_position =1;
      if(Page_Pos == 0)
          OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1);      
      else 
	      OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1_B1);    


      if(Source == HDMI_SOURCE){
          if(Page_Pos == 0)
              font_index = Input_HDMI_Start;
	   else
        font_index = Input_B1_HDMI_Start;
      }
      else if(Source == DP_SOURCE){
           if(Page_Pos == 0)
              font_index = Input_DP_Start;
	   else
        font_index = Input_B1_DP_Start;
      }
      else if(Source == MiniDP_SOURCE){
           if(Page_Pos == 0)
              font_index = Input_MINIDP_Start;
	   else
        font_index = Input_B1_MINIDP_Start;
      }
#if MD_INPUT_INTERFACE&INPUT_VGA0    
      else if(Source == VGA_SOURCE){
           if(Page_Pos == 0)
              font_index = Input_VGA_Start;
	   else
        font_index = Input_B1_VGA_Start;
      }
#endif 
#if MD_INPUT_INTERFACE&INPUT_DIG1//MD_INPUT_INTERFACE&INPUT_DIG0    
      else if(Source == DVI_SOURCE){
           if(Page_Pos == 0)
              font_index = Input_DVI_Start;
       else
        font_index = Input_B1_DVI_Start;
      }
#endif
#if MD_INPUT_INTERFACE&INPUT_DIG2//MD_INPUT_INTERFACE&INPUT_DIG0    
        else if(Source == DP_SOURCE){
             if(Page_Pos == 0)
                font_index = Input_DP_Start;
         else
          font_index = Input_B1_DP_Start;
        }
#endif
#if MD_INPUT_INTERFACE&INPUT_DIG3//MD_INPUT_INTERFACE&INPUT_DIG0    
      else if(Source == HDMI_SOURCE){
           if(Page_Pos == 0)
              font_index = Input_HDMI_Start;
       else
        font_index = Input_B1_HDMI_Start;
      }
#endif

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

      if(Page_Pos == 0){
          OSDAPI_WriteXYChar(TRUE, h_position, v_position, font_index);
          OSDAPI_WriteXYChar(TRUE, h_position+1, v_position, font_index+1);
          OSDAPI_WriteXYChar(TRUE, h_position+2, v_position, font_index+2);
	}
      else{
       OSDAPI_WriteXYChar(TRUE, h_position, v_position, font_index);
          OSDAPI_WriteXYChar(TRUE, h_position+1, v_position, font_index+1);
          OSDAPI_WriteXYChar(TRUE, h_position, v_position+1, font_index+2);
       OSDAPI_WriteXYChar(TRUE, h_position+1, v_position+1, font_index+3);    
	}
      
      bSelectTable = OSDFontTble1;
      
      OSDAPI_SetFontAttr(TOPPAGEICON_1BIT_COLOR1_B1);    
      ShowIndentString(TRUE, 5, v_position, DIALOG_INDENT_STRING_MAX_LEN, InputTab1[Source*NUM_OSDLANGS+UserData.ucLanguage]);
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
    // Show Layer 4 hook icon
    //OSDShowHookIcon(HookIconColor1_256, id, STRING_LAYER_4, Hook_Icon);
    //InputTab1
    ShowIndentString(TRUE, ucLayer4ItemInfoTb[1], ucLayer4ItemInfoTb[2], INDENT_STRING_MAX_LEN-2, InputTab1[(GetInputPortIndex(UserData.ucInputSource)*NUM_OSDLANGS+UserData.ucLanguage)]);
    OSDShowCurrentResolution(ucLayer4ItemInfoTb[1],ucLayer4ItemInfoTb[2]+LAYER_STR_OFFSET_Y);
    OSDShowOptimumResolution(ucLayer4ItemInfoTb[1],ucLayer4ItemInfoTb[2]+LAYER_STR_OFFSET_Y*2);
    #if ENABLE_OSD_SHOW_MODELNAME == ON
    ShowIndentString(TRUE, ucLayer4ItemInfoTb[1], ucLayer4ItemInfoTb[2]+LAYER_STR_OFFSET_Y*3, INDENT_STRING_MAX_LEN-2, ModelWordStrTab[0]);
    #endif
}

void ClrLayer4(void) //ULEric140415
{
    UCHAR i;
    OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
    for (i=0; i<LAYER_STR_HEIGHT; i++) {
        OSDAPI_WriteXYRepeatChar(TRUE, LAYER4_POSX, 3+i, INDENT_STRING_MAX_LEN, _SPACE_);
    }
}

void OSDShowLayer4(UCHAR id)
{
    UCHAR i;
    //printf("ShowLayer4 %bx %bx %bx\r\n",ucMenuType,ucSubMenuType,id);
    switch(ucMenuType){
    	case OSD_MAIN_PICTURE:
    		switch(ucSubMenuType){
    			case OSD_PICTURE_COLORTEMP:
    				if(id == CLRTMP_USER){
    					OSDShowRGain(FALSE, FALSE);
    					OSDShowGGain(FALSE, FALSE);
    					OSDShowBGain(FALSE, FALSE);
    				}
    				break;
    			default:
    				break;
    		}
    		break;
    	case OSD_MAIN_PICTURE_ADVANCED:
    		switch(ucSubMenuType){
    			case OSD_PICTURE_AD_PIC:
    				if(id == PICTURE_MODE_LOW_BL){
    					OSDShowStringSeparater(STRING_LAYER_4, FALSE);
    					// show layer 4 string
    				#if LAYER_INDENT_COUNT == ON
    					OSDAPI_SetIndentIndex(fnGetLayerIndentCount(STRING_LAYER_4));
    				#else
    					OSDAPI_SetIndentIndex(String_Layer4_Index);
    				#endif
    					OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    					OSDAPI_SetFontAttr(UnSelectedStringColor_256);   
    					OSDShowLowBlueLightStrings(ucLBLItemInfoTb[1], ucLBLItemInfoTb[2]);
    					// Show Layer 4 hook icon
    					OSDShowHookIcon(SelectedStringColor1_256, id, STRING_LAYER_4, Hook_Icon);//ULEric140402
    				}
                    #if ENABLE_PICTURE_MODE_ANIMATION == ON
                    else if(id == PICTURE_MODE_ANIMATION){
                        OSDFocusAnimation();
                    }
                    #endif
    				break;
                case OSD_PICTURE_AD_SENSEYE:
                    if(id == PICTURE_DUALMODE_ON){
    					OSDShowStringSeparater(STRING_LAYER_4, FALSE);
                        OSDAPI_SetIndentIndex(String_Layer4_Index);
                        OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
                        OSDAPI_SetFontAttr(UnSelectedStringColor_256);
                        for (i=0; i < PICTURE_DUALMODE_ITEM_NUM; i++) {//ULEric140401
                            ShowIndentString(TRUE, ucLayer4ItemInfoTb[1], ucLayer4ItemInfoTb[2]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN-2, OnOffTab1[i*NUM_OSDLANGS+UserData.ucLanguage]);
                        }
                    }
                    OSDShowHookIcon(SelectedStringColor1_256, id, STRING_LAYER_4, Hook_Icon);//ULEric140401                    
                    break;
    			default:
    				break;
    		}	
    		break;
    	case OSD_MAIN_SYSTEM:
    		switch(ucSubMenuType){
    			case OSD_SYS_OSDSET:
    				if (id < OSD_SYS_OSDSET_OSDLOCK) {
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
    				
#if 0 // 0 lrd add 
    					bSelectTable = OSDFontTble2;
                        tempLang = LangItemToPoint(UserData.ucLanguage);    	
                        
    					if (tempLang < 8 ) {
    						for (i=0; i<(ucLayer4ItemInfoTb[0]>8? 8:ucLayer4ItemInfoTb[0]); i++) {//ULEric140401
                                ShowIndentString(TRUE, ucLayer4ItemInfoTb[1], ucLayer4ItemInfoTb[2]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN-2, LanguageTab[i*NUM_OSDLANGS+UserData.ucLanguage]);
    						}
    					}
    					else if(tempLang < 16 ) {
    						for (i=8; i<16; i++) {
                                if(i == LangItemToPoint(OSDLANG_ARAB)){
                                    templang_arab = UserData.ucLanguage;
                                    UserData.ucLanguage = OSDLANG_ARAB;
                                    ShowIndentString(TRUE, ucLayer4ItemInfoTb[1], ucLayer4ItemInfoTb[2]+(i-8)*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN-2, LanguageTab[i*NUM_OSDLANGS+UserData.ucLanguage]);
                                    UserData.ucLanguage = templang_arab;
                                    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
                                }
                                else{
                                    ShowIndentString(TRUE, ucLayer4ItemInfoTb[1], ucLayer4ItemInfoTb[2]+(i-8)*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN-2, LanguageTab[i*NUM_OSDLANGS+UserData.ucLanguage]);
                                }                              
    						}
    					}
    					else {
    						//i = 16 ;
                            for (i=16; i<NUM_OSDLANGS; i++) {
    						    ShowIndentString(TRUE, ucLayer4ItemInfoTb[1], ucLayer4ItemInfoTb[2]+(i-16)*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN-2, LanguageTab[i*NUM_OSDLANGS+UserData.ucLanguage]);
                            }
                            for (i=(NUM_OSDLANGS-16); i<8; i++) {
    							ShowIndentString(TRUE, ucLayer4ItemInfoTb[1], ucLayer4ItemInfoTb[2]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN-2, LanguageTab[NUM_OSDLANGS*NUM_OSDLANGS]);
    						}
    					}    		
                        
#else
                            bSelectTable = OSDFontTble2;
                            if (UserData.ucLanguage < 8 ) {
                                for (i=0; i<(ucLayer4ItemInfoTb[0]>8? 8:ucLayer4ItemInfoTb[0]); i++) {//ULEric140401
                                    ShowIndentString(TRUE, ucLayer4ItemInfoTb[1], ucLayer4ItemInfoTb[2]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN-2, LanguageTab[i*NUM_OSDLANGS+UserData.ucLanguage]);
                                }
                            }
                            else if(UserData.ucLanguage < 16 ) {
                                for (i=8; i<16; i++) {
                                    ShowIndentString(TRUE, ucLayer4ItemInfoTb[1], ucLayer4ItemInfoTb[2]+(i-8)*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN-2, LanguageTab[i*NUM_OSDLANGS+UserData.ucLanguage]);
                                }
                            }
                            else {
                                //i = 16 ;
                                for (i=16; i<NUM_OSDLANGS; i++) {
                                    ShowIndentString(TRUE, ucLayer4ItemInfoTb[1], ucLayer4ItemInfoTb[2]+(i-16)*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN-2, LanguageTab[i*NUM_OSDLANGS+UserData.ucLanguage]);
                                }
                                for (i=(NUM_OSDLANGS-16); i<8; i++) {
                                    ShowIndentString(TRUE, ucLayer4ItemInfoTb[1], ucLayer4ItemInfoTb[2]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN-2, LanguageTab[NUM_OSDLANGS*NUM_OSDLANGS]);
                                }

                            }                        
                        
                        
#endif
    					//bSelectTable = OSDFontTble1;
    					//OSDUpdateArrowIcon(ArrowColor2,(UserData.ucLanguage/8),STRING_LAYER_4);//Clear Arrow
    				}
    				else if (id == OSD_SYS_OSDSET_TIMER) { // display time
    					for (i=0; i<ucLayer4ItemInfoTb[3*id]; i++) {
    						ShowIndentString(TRUE, ucLayer4ItemInfoTb[id*3+1], ucLayer4ItemInfoTb[id*3+2]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN-2, DisplayTimeTab[i*NUM_OSDLANGS+UserData.ucLanguage]);
    					}
    				}
    				// Show Layer 4 hook icon
    				OSDShowHookIcon(SelectedStringColor1_256, id, STRING_LAYER_4, Hook_Icon);//ULEric140401
    				break;
    			default:
    				break;
    		}	
    		break;
    	default:
    		break;		
    }
}

void OSDShowArrow(UCHAR x, UCHAR y, UCHAR arrowType)
{
	if(arrowType == PrePage_Arrow){
        OSDAPI_WriteXYChar(TRUE, x, y, UpArrow_1);
        OSDAPI_WriteXYChar(TRUE, x+1, y, UpArrow_2);
	}
    else if(arrowType == PrePage_Arrow1){
        OSDAPI_WriteXYChar(TRUE, x, y, UpArrow1_1);
        OSDAPI_WriteXYChar(TRUE, x+1, y, UpArrow1_2);
	}
	else if(arrowType == NextPage_Arrow){
        OSDAPI_WriteXYChar(TRUE, x, y, DownArrow_1);
        OSDAPI_WriteXYChar(TRUE, x+1, y, DownArrow_2);
        //OSDAPI_WriteXYChar(TRUE, x+1, y+1, DownArrow_3);
	}
}

void OSDClearArrow(UCHAR x, UCHAR y, UCHAR arrowType)
{
	if((arrowType == PrePage_Arrow)||(arrowType == PrePage_Arrow1)){
        OSDAPI_WriteXYRepeatChar(TRUE, x, y, 2, _SPACE_);
	}
	else if(arrowType == NextPage_Arrow){
        OSDAPI_WriteXYRepeatChar(TRUE, x, y,   2, _SPACE_);
        //OSDAPI_WriteXYRepeatChar(TRUE, x, y+1, 2, _SPACE_);
	}
}

UCHAR OSDGetLayer3ItemNum(UCHAR MenuType, UCHAR SubMenuType)
{
    return (ucLayer3ItmNumTab[MenuType][SubMenuType]);
}

UCHAR OSDCheckL3ItemNum(UCHAR MenuType, UCHAR SubMenuType, UCHAR Range)
{
    return (ucLayer3ItmNumTab[MenuType][SubMenuType]>Range ? Range:ucLayer3ItmNumTab[MenuType][SubMenuType]);
}

#if 1
//Customkey string index
enum {
    CUS_STR_IDX_PICTUREMODE,
#if ENABLE_CUSTOMKEY_CAD == ON    
    CUS_STR_IDX_CAD,
#endif    
#if ENABLE_CUSTOMKEY_ANIMATION == ON
    CUS_STR_IDX_ANIMATION_MODE,
#endif
#if ENABLE_CUSTOMKEY_LBL == ON
    CUS_STR_IDX_LOWBULELIGHTMODE,//ULEric140331    
#endif    
    CUS_STR_IDX_DISPLAYMODE,
    CUS_STR_IDX_BRIGHTNESS,
    CUS_STR_IDX_CONTRAST,
#if ENABLE_CUSTOMKEY_AUTOADJ == ON
    CUS_STR_IDX_AUTOADJUSTMENT,
#endif    
    CUS_STR_IDX_VOLUME,//ULEric140331
    CUS_STR_IDX_MUTE,//ULEric140331
    CUS_STR_IDX_INPUT,
#if ENABLE_EYE_PROTECT == ON
    CUS_STR_IDX_EYE_PROTECT,
    CUS_STR_IDX_EYE_PROTECT_METER,
#endif
#if ENABLE_ECO_SENSOR== ON
    CUS_STR_IDX_ECO_SENSOR,
    CUS_STR_IDX_ECO_SENSOR_METER,
#endif
#if ENABLE_ERGONOMICS == ON
    CUS_STR_IDX_SMARTREMINDER,//ULEric140331
#endif    
    CUS_STR_IDX_NUM
};
//Picture mode string index
enum {
    PIC_MODE_STR_IDX_SRGB, 
#if	ENABLE_PICTURE_MODE_CAD == ON
    PIC_MODE_STR_IDX_CAD,
#endif        
#if	ENABLE_PICTURE_MODE_ANIMATION == ON
    PIC_MODE_STR_IDX_ANIMATION,
#endif
#if	ENABLE_PRESENTATION_MODE == ON
    PIC_MODE_STR_IDX_PRESENTATION,
#endif        
    PIC_MODE_STR_IDX_STANDARD,
#if	ENABLE_PICTURE_MODE_REC709== ON
    PIC_MODE_STR_IDX_REC709,
#endif        
    PIC_MODE_STR_IDX_LBL,
#if ENABLE_PICTURE_MODE_MOVIE == ON           
    PIC_MODE_STR_IDX_MOVIE,
#endif    
#if ENABLE_PICTURE_MODE_GAME == ON    
    PIC_MODE_STR_IDX_GAME,    
#endif    
#if ENABLE_PICTURE_MODE_PHOTO== ON       
    PIC_MODE_STR_IDX_PHOTO,
#endif    
#if	ENABLE_PICTURE_MODE_DARKROOM == ON
    PIC_MODE_STR_IDX_DARKROOM ,
#endif        
    PIC_MODE_STR_IDX_ECO,
#if ENABLE_PICTURE_MODE_MBOOK == ON
    PIC_MODE_STR_IDX_MBOOK,
#endif
    PIC_MODE_STR_IDX_USER,    
    PIC_MODE_STR_IDX_NUM
};

#if 0
UCHAR OSDStringRemap(USHRT id)
{
    UCHAR CusKeyStringMap[CUS_STR_IDX_NUM]={CUS_STR_IDX_BRIGHTNESS,CUS_STR_IDX_CONTRAST,CUS_STR_IDX_INPUT,CUS_STR_IDX_PICTUREMODE,
                                            CUS_STR_IDX_DISPLAYMODE,CUS_STR_IDX_VOLUME,CUS_STR_IDX_MUTE};
#if	ENABLE_PICTURE_MODE_DARKROOM == ON && ENABLE_PICTURE_MODE_REC709== ON
    UCHAR PicModeStringMap[PIC_MODE_STR_IDX_NUM]={PIC_MODE_STR_IDX_STANDARD,PIC_MODE_STR_IDX_REC709,PIC_MODE_STR_IDX_SRGB,PIC_MODE_STR_IDX_CAD,PIC_MODE_STR_IDX_ANIMATION,
                                                PIC_MODE_STR_IDX_LBL,PIC_MODE_STR_IDX_DARKROOM,PIC_MODE_STR_IDX_ECO,PIC_MODE_STR_IDX_MBOOK,PIC_MODE_STR_IDX_USER};
#elif ENABLE_PICTURE_MODE_DARKROOM == OFF && ENABLE_PICTURE_MODE_REC709== OFF
    UCHAR PicModeStringMap[PIC_MODE_STR_IDX_NUM]={PIC_MODE_STR_IDX_STANDARD,PIC_MODE_STR_IDX_SRGB,PIC_MODE_STR_IDX_CAD,PIC_MODE_STR_IDX_ANIMATION,
                                                PIC_MODE_STR_IDX_LBL,PIC_MODE_STR_IDX_ECO,PIC_MODE_STR_IDX_MBOOK,PIC_MODE_STR_IDX_USER};
#endif

    switch(ucMenuType){
        case OSD_MAIN_DISPLAY:
        case OSD_MAIN_PICTURE:
        case OSD_MAIN_AUDIO:   
            return id;
            break; 
        case OSD_MAIN_PICTURE_ADVANCED:
            switch(ucSubMenuType){
                case OSD_PICTURE_AD_PIC:
                    return PicModeStringMap[id];
                    break;
                default:
                    return id;
                    break;                    
            }
            break; 
        case OSD_MAIN_SYSTEM:
            switch(ucSubMenuType){
                case OSD_SYS_CTKEY1:
                case OSD_SYS_CTKEY2:
                case OSD_SYS_CTKEY3:
                    return CusKeyStringMap[id];
                    break;
                default:
                    return id;
                    break;
            }
            break;          
        default:
            break;
    }
}
#endif

#endif


void OSDShowLayer3PageString(UCHAR pageNum)
{
	UCHAR i, MaxItemNum, offset;
	if(pageNum == LAYER3_PAGE_1){
		MaxItemNum = (OSDCheckL3ItemNum(ucMenuType,ucSubMenuType,8));
		offset = 0;
	}
	else if (pageNum == LAYER3_PAGE_2){
		MaxItemNum = (OSDGetLayer3ItemNum(ucMenuType,ucSubMenuType)-8);
		offset = 8;
	}

    
    for (i=0; i<MaxItemNum; i++) {
        if (TestTable2[ucMenuType][ucSubMenuType][i+offset] != NULL) {
            if (OSDIsLayer3ItemValid(i+offset)) {                        
                OSDAPI_SetFontAttr(UnSelectedStringColor1_256);
            }
            else{
                OSDAPI_SetFontAttr(DisabledStringColor_256);
            }
            #if 0 //add string mapping
            ShowIndentString(TRUE, ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN-2,
            TestTable2[ucMenuType][ucSubMenuType][(OSDStringRemap(i+offset))*NUM_OSDLANGS+UserData.ucLanguage]);
            #else
            ShowIndentString(TRUE, ucLayer3PosInfoTab[ucMenuType][0], ucLayer3PosInfoTab[ucMenuType][1]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN-2,
            TestTable2[ucMenuType][ucSubMenuType][(i+offset)*NUM_OSDLANGS+UserData.ucLanguage]);
            #endif
        }
    }
}

#if 0
void OSDShowCustomKeyHookIcon(UCHAR pageNum)
{
	UCHAR CusKeyNum;

	if (ucSubMenuType ==OSD_SYS_CTKEY1 ) {//Justin 140428 CustomerKey1
		CusKeyNum = UserData.ucCustomerKey1;
	}
	else if(ucSubMenuType ==OSD_SYS_CTKEY2 ) {//Justin 140428 CustomerKey1
		CusKeyNum = UserData.ucCustomerKey2;
	}
	else if(ucSubMenuType ==OSD_SYS_CTKEY3 ) {//Justin 140428 CustomerKey1
		CusKeyNum = UserData.ucCustomerKey3;
	}

	if(pageNum == CUSKEY_PAGE_2){
		if (CusKeyNum < (OSD_MAX_LINES)) {
			OSDShowHookIcon(CLEAR_1BIT_COLOR, ucSubMenuType, STRING_LAYER_3, _SPACE_);
		}
		else {
			OSDShowHookIcon(UnSelectedStringColor1_256, ucSubMenuType, STRING_LAYER_3, Hook_Icon);
		}
	}
	else if(pageNum == CUSKEY_PAGE_1){
        if(CusKeyNum > (OSD_MAX_LINES-1)) {
            OSDShowHookIcon(CLEAR_1BIT_COLOR, ucSubMenuType, STRING_LAYER_3, _SPACE_);
        }
        else {
            OSDShowHookIcon(UnSelectedStringColor1_256, ucSubMenuType, STRING_LAYER_3, Hook_Icon);
        }
	}
}
#endif
void OSDClearLayer4ByItem(UCHAR id, BOOL IsUp)
{
    UCHAR i;
    OSDAPI_SetFontAttr(CLEAR_1BIT_COLOR);
    if (ucMenuType == OSD_MAIN_SYSTEM && ucSubMenuType == OSD_SYS_OSDSET) {//ULEric140415
        if((id == OSD_SYS_OSDSET_LANG&& IsUp)||(id==OSD_SYS_OSDSET_TIMER && !IsUp))//All Clear
        {
           ClrLayer4();
        }
        else{//Clear String Only 
            if(id == OSD_SYS_OSDSET_LANG){
                OSDUpdateArrowIcon(CLEAR_1BIT_COLOR,ClearArrowType,STRING_LAYER_4);//Clear Arrow //ULEric140415
            }
            if((id == OSD_SYS_OSDSET_LANG)||(id == OSD_SYS_OSDSET_TIMER)){        
                for (i=0; i<(ucLayer4ItemInfoTb[id*3]>OSD_MAX_LINES? OSD_MAX_LINES:ucLayer4ItemInfoTb[id*3]); i++) {
                    OSDAPI_WriteXYRepeatChar(TRUE, ucLayer4ItemInfoTb[id*3+1], ucLayer4ItemInfoTb[id*3+2]+i*LAYER_STR_OFFSET_Y, INDENT_STRING_MAX_LEN, _SPACE_);
                }
            }
        }        
    }
    else if (ucMenuType == OSD_MAIN_PICTURE && ucSubMenuType == OSD_PICTURE_COLORTEMP && id == CLRTMP_USER) {
        ClrLayer4();
    }
    else if (ucMenuType == OSD_MAIN_PICTURE_ADVANCED && ucSubMenuType == OSD_PICTURE_AD_PIC && (id == PICTURE_MODE_LOW_BL || id == PICTURE_MODE_ANIMATION)) {//ULEric140415        
        if(id == PICTURE_MODE_ANIMATION){
            OSDAPI_OSDWinOff(OSD_WINDOW2);
        }
        ClrLayer4();
    }

    switch(ucMenuType){
        case OSD_MAIN_PICTURE_ADVANCED:
            switch(ucSubMenuType){
                case OSD_PICTURE_AD_SENSEYE:
                    if(id == PICTURE_DUALMODE_ON){
                        ClrLayer4();
                    }
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}
/*
UCHAR *OSDGetItemString(UCHAR MainMenuIdex, UCHAR SubMenuIndex, UCHAR ItemIndex)
{
    return TestTable2[MainMenuIdex][SubMenuIndex][ItemIndex*NUM_OSDLANGS+UserData.ucLanguage];
}
void OSDShowCusSmartReminderString(UCHAR id)
{   UCHAR i;
    for (i=0; i<2; i++)
    	ShowIndentString(TRUE, DIALOG_STR_POSX, DIALOG_STR_POSY+i*DIALOG_STR_OFFSET_Y, DIALOG_INDENT_STRING_MAX_LEN, TestTable2[OSD_MAIN_ERGONOMICS][OSD_ERGONOMICS_REMIDER][(8+i)*NUM_OSDLANGS+UserData.ucLanguage]);            		
}
*/
void OSDShowCusPictureModeStrings(UCHAR id)
{
    UCHAR i;
    for (i=0; i<((id>7)? (ucLayer3ItmNumTab[OSD_MAIN_PICTURE_ADVANCED][OSD_PICTURE_AD_PIC]-8):(ucLayer3ItmNumTab[OSD_MAIN_PICTURE_ADVANCED][OSD_PICTURE_AD_PIC]>8?8: ucLayer3ItmNumTab[OSD_MAIN_PICTURE_ADVANCED][OSD_PICTURE_AD_PIC])) ; i++)
        ShowIndentString(TRUE, DIALOG_STR_POSX, DIALOG_STR_POSY+i*DIALOG_STR_OFFSET_Y, DIALOG_INDENT_STRING_MAX_LEN, ((id > 7)?TestTable2[OSD_MAIN_PICTURE_ADVANCED][OSD_PICTURE_AD_PIC][(8+i)*NUM_OSDLANGS+UserData.ucLanguage]:TestTable2[OSD_MAIN_PICTURE_ADVANCED][OSD_PICTURE_AD_PIC][i*NUM_OSDLANGS+UserData.ucLanguage]));
    if(id>7){
        OSDClearItemString(0,(PICTURE_MODE_NUM-8));
    }                  
}   

void OSDShowCusDisplayModeStrings(UCHAR id)
{
    UCHAR i;
    for (i=0; i<((id>7)? (ucLayer3ItmNumTab[OSD_MAIN_PICTURE_ADVANCED][OSD_PICTURE_AD_DISMODE]-8):(ucLayer3ItmNumTab[OSD_MAIN_PICTURE_ADVANCED][OSD_PICTURE_AD_DISMODE]>8?8: ucLayer3ItmNumTab[OSD_MAIN_PICTURE_ADVANCED][OSD_PICTURE_AD_DISMODE])) ; i++){
        if (OSDIsCustomkeyItemValid(i)==FALSE){
            OSDAPI_SetFontAttr(DisabledStringColor_256);                    
            ShowIndentString(TRUE, DIALOG_STR_POSX, DIALOG_STR_POSY+i*DIALOG_STR_OFFSET_Y, DIALOG_INDENT_STRING_MAX_LEN, ((id > 7)?TestTable2[OSD_MAIN_PICTURE_ADVANCED][OSD_PICTURE_AD_DISMODE][(8+i)*NUM_OSDLANGS+UserData.ucLanguage]:TestTable2[OSD_MAIN_PICTURE_ADVANCED][OSD_PICTURE_AD_DISMODE][i*NUM_OSDLANGS+UserData.ucLanguage]));                    
        }
        else{
            OSDAPI_SetFontAttr(UnSelectedStringColor1_256);              
            ShowIndentString(TRUE, DIALOG_STR_POSX, DIALOG_STR_POSY+i*DIALOG_STR_OFFSET_Y, DIALOG_INDENT_STRING_MAX_LEN, ((id > 7)?TestTable2[OSD_MAIN_PICTURE_ADVANCED][OSD_PICTURE_AD_DISMODE][(8+i)*NUM_OSDLANGS+UserData.ucLanguage]:TestTable2[OSD_MAIN_PICTURE_ADVANCED][OSD_PICTURE_AD_DISMODE][i*NUM_OSDLANGS+UserData.ucLanguage]));                
        }
    }
}      

void OSDShowCusInputStrings(UCHAR id)
{
    UCHAR i;
    for (i=0; i<((id>7)? (ucLayer3ItmNumTab[OSD_MAIN_DISPLAY][OSD_DISPLAY_INPUT]-8):(ucLayer3ItmNumTab[OSD_MAIN_DISPLAY][OSD_DISPLAY_INPUT]>8?8: ucLayer3ItmNumTab[OSD_MAIN_DISPLAY][OSD_DISPLAY_INPUT])) ; i++){
        ShowIndentString(TRUE, DIALOG_STR_POSX, DIALOG_STR_POSY+i*DIALOG_STR_OFFSET_Y, DIALOG_INDENT_STRING_MAX_LEN, ((id > 7)?TestTable2[OSD_MAIN_DISPLAY][OSD_DISPLAY_INPUT][(8+i)*NUM_OSDLANGS+UserData.ucLanguage]:TestTable2[OSD_MAIN_DISPLAY][OSD_DISPLAY_INPUT][i*NUM_OSDLANGS+UserData.ucLanguage]));
    }
}


void OSDShowCusMenuString(UCHAR MainMenuType, UCHAR SubMenuType)
{   
    UCHAR i;
    for (i=0; i<OSDGetLayer3ItemNum(MainMenuType, SubMenuType); i++)
        ShowIndentString(TRUE, DIALOG_STR_POSX, DIALOG_STR_POSY+i*DIALOG_STR_OFFSET_Y, DIALOG_INDENT_STRING_MAX_LEN, TestTable2[MainMenuType][SubMenuType][i*NUM_OSDLANGS+UserData.ucLanguage]);            
}

#if ENABLE_CUSTOMKEY_LBL == ON                        
void OSDShowCusLowBlueLightStrings(void)
{
    OSDShowLowBlueLightStrings(DIALOG_STR_POSX, DIALOG_STR_POSY);
}
#endif

void OSDShowCustomMenuDialogString(UCHAR id, UCHAR CustomerKey)
{
//    UCHAR i;

#if LAYER_INDENT_COUNT == ON
    OSDAPI_SetIndentIndex(String_DialogString_Index);
#else
    if((GetOSDState()>= OSD_TOPPAGE_END)&&(GetOSDState() < OSD_MAIN_BEG)){
    OSDAPI_SetIndentIndex(String_DialogString_Index);
    }
    else{
    OSDAPI_SetIndentIndex(String_Layer2_Index);
    //OSDAPI_SetIndentIndex(uslay1IndentFontIndex);
    }
#endif
        
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    OSDAPI_SetFontAttr(UnSelectedStringColor1_256);
    bSelectTable = OSDFontTble1;
	
	switch(CustomerKey){
		case CUSTOMER_KEY_PICTUREMODE:
            OSDShowCusPictureModeStrings(id);
			break;
		case CUSTOMER_KEY_DISPLAYMODE:
            OSDShowCusDisplayModeStrings(id);
			break;
		case CUSTOMER_KEY_INPUT:
            OSDShowCusInputStrings(id);
			break;
		case CUSTOMER_KEY_MUTE:
            OSDShowCusMenuString(OSD_MAIN_AUDIO, OSD_AUDIO_MUTE);			
            break;
#if ENABLE_CUSTOMKEY_LBL == ON                        
		case CUSTOMER_KEY_LOWBULELIGHTMODE:
			OSDShowCusLowBlueLightStrings();		
			break;
#endif            
#if ENABLE_ERGONOMICS ==ON
		case CUSTOMER_KEY_SMARTREMINDER:
            OSDShowCusMenuString(OSD_MAIN_ERGONOMICS, OSD_ERGONOMICS_REMIDER);			
			break;
#endif
#if ENABLE_EYE_PROTECT == ON
		case CUSTOMER_KEY_EYE_PROTECT:
            OSDShowCusMenuString(OSD_MAIN_ERGONOMICS, OSD_ERGONOMICS_EYE_PROTECT);			
			break;          
		case CUSTOMER_KEY_EYE_PROTECT_METER:          
            OSDShowCusMenuString(OSD_MAIN_ERGONOMICS, OSD_ERGONOMICS_EYE_PROTECT_METER);			
			break;
#endif
#if ENABLE_ECO_SENSOR== ON
		case CUSTOMER_KEY_ECO_SENSOR:
            OSDShowCusMenuString(OSD_MAIN_ECO, OSD_ECO_SENSOR);			
			break;          
		case CUSTOMER_KEY_ECO_SENSOR_METER:          
            OSDShowCusMenuString(OSD_MAIN_ECO, OSD_ECO_SENSOR_METER);			
			break;    
#endif
        default:
            break;
	}
}

void OSDShowCusMenuIcon(UCHAR id, UCHAR sel)
{
#define TP_BOT_CUSKEY_POSX        0
#define TP_BOT_CUSKEY_OFFSET_X    8

    UCHAR i;
    UCHAR ucXPos_Line1, ucXPos_Line3, ucXPos_Line2;
    //UCHAR ucCusYPos,ucCusXPos;
    UCHAR IconPos;
    // a temperary buffer to hold the toppage icon font index
    UCHAR ucTopPageIconBuffer[12] = {0};

    {
        IconPos = OSD_TOPPAGE_POS_NML;//0
    }
 
    {//sel=1
        OSDAPI_SetFontAttr(DialogIconColor1);
        if ((id == TP_BRIGHTNESS)||(id == TP_CONTRAST)){
            ucXPos_Line1 = DIALOG2_ICON_POSX;//3;
            ucXPos_Line2 = DIALOG2_ICON_POSX;
            ucXPos_Line3 = DIALOG2_ICON_POSX;//3;
        }
        else if((id == TP_VOLUME)
#if ENABLE_CUSTOMKEY_ANIMATION == ON                                    
            ||(id == TP_ANIMATION)
#endif            
            ){
            ucXPos_Line1 = DIALOG2_ICON_POSX;//3;
            ucXPos_Line2 = DIALOG2_ICON_POSX;
            ucXPos_Line3 = DIALOG2_ICON_POSX;//3;
        } 
        else if (id == TP_PICTUREMODE) {
            ucXPos_Line1 = DIALOG_ICON_POSX;//3;
            ucXPos_Line2 = DIALOG_ICON_POSX;
            ucXPos_Line3 = DIALOG_ICON_POSX;//2
        }
        else {
            ucXPos_Line1 = DIALOG_ICON_POSX;//2;
            ucXPos_Line2 = DIALOG_ICON_POSX;
            ucXPos_Line3 = DIALOG_ICON_POSX;//2;
        }
    }

    // font index copy to a buffer to save code memory.
    switch (id) {
        case TP_BRIGHTNESS:
            for (i=0; i<(TP_1Bit_Brightness_End-TP_1Bit_Brightness_Start); i++) {
                ucTopPageIconBuffer[i] = TP_1Bit_Start+i;
            }
            break;
#if ENABLE_CUSTOMKEY_AUTOADJ == ON                                             
        case TP_AUTOADJUSTMENT:
            for (i=0; i<(TP_1Bit_Auto_End-TP_1Bit_Auto_Start); i++) {
                ucTopPageIconBuffer[i] = TP_1Bit_Auto_Start+i;
            }
            break;
#endif            
        case TP_CONTRAST:
            for (i=0; i<(TP_1Bit_Contrast_End-TP_1Bit_Contrast_Start); i++) {
                ucTopPageIconBuffer[i] = TP_1Bit_Start+i;
            }
            break;
        case TP_DISPLAYMODE:
            for (i=0; i<(TP_1Bit_DisplayMode_End-TP_1Bit_DisplayMode_Start); i++) {
                ucTopPageIconBuffer[i] = TP_1Bit_Start+i;
            }
            break;

        case TP_PICTUREMODE:
            for (i=0; i<(TP_1Bit_Picture_End-TP_1Bit_Picture_Start); i++) {
                ucTopPageIconBuffer[i] = TP_1Bit_Start+i;
            }
            break;
        case TP_EXIT:			
	     for (i=0; i<(TP_1Bit_Exit_End-TP_1Bit_Exit_Start); i++) {
	         if (IconPos == 0)
                    ucTopPageIconBuffer[i] = TP_1Bit_Exit_Start+i;
                else		 
                    ucTopPageIconBuffer[i] = TP_1Bit_B1_Exit_Start+i;
            }
            break;
        case TP_INPUT:		
	     for (i=0; i<(TP_1Bit_Menu_End-TP_1Bit_Input_Start); i++) {
	         if (IconPos == 0)
                    ucTopPageIconBuffer[i] = TP_1Bit_Start+i;
		  else
                    ucTopPageIconBuffer[i] = TP_1Bit_B1_Input_Start+i;
            }
            break;
        case TP_MENU:		
	        for (i=0; i<(TP_1Bit_Menu_End-TP_1Bit_Menu_Start); i++) {
	            if (IconPos == 0)
		            ucTopPageIconBuffer[i] = TP_1Bit_Menu_Start+i;
		        else
                    ucTopPageIconBuffer[i] = TP_1Bit_B1_Menu_Start+i;
            }
            break;
            
    //ULEric140402                    
     case TP_VOLUME:
            if((UserData.bAudioMute)&&(sel == 1)){         
                 for (i=0; i<(TP_1Bit_Mute_End-TP_1Bit_Mute_Start); i++) {
                     ucTopPageIconBuffer[i] = TP_1Bit_Start+i+(TP_1Bit_Volume_End-TP_1Bit_Volume_Start);
                 }                
             }
            else{		
		    	for (i=0; i<(TP_1Bit_Volume_End-TP_1Bit_Volume_Start); i++) {
		   			if (IconPos == 0)
                         ucTopPageIconBuffer[i] = TP_1Bit_Start+i;    
					else
                         ucTopPageIconBuffer[i] = TP_1Bit_B1_Volume_Start+i;
		   		}    
            }
            break;
     case TP_MUTE:
            for (i=0; i<(TP_1Bit_Mute_End-TP_1Bit_Mute_Start); i++) {
                ucTopPageIconBuffer[i] = TP_1Bit_Start+i;
            }
            break;
#if ENABLE_CUSTOMKEY_LBL == ON                        
    case TP_LOWBLUELIGHT:
            for (i=0; i<(TP_1Bit_LowBlueLight_End-TP_1Bit_LowBlueLight_Start); i++) {
                if (IconPos == 0)	
		            ucTopPageIconBuffer[i] = TP_1Bit_Start+i;
                else
                    ucTopPageIconBuffer[i] = TP_1Bit_B1_LowBlueLight_Start+i;
            	}
            break;
#endif            
#if ENABLE_CUSTOMKEY_ANIMATION == ON                                    
    case TP_ANIMATION:
            for (i=0; i<(TP_1Bit_Animation_End-TP_1Bit_Animation_Start); i++) {
                ucTopPageIconBuffer[i] = TP_1Bit_Start+i;
            }
            break;     
#endif            
#if ENABLE_EYE_PROTECT == ON
    case TP_EYE_PROTECT:
            for (i=0; i<(TP_1Bit_Eye_Protect_End-TP_1Bit_Eye_Protect_Start); i++) {
                ucTopPageIconBuffer[i] = TP_1Bit_Start+i;
            }
            break;     
    case TP_EYE_PROTECT_METER:
            for (i=0; i<(TP_1Bit_Eye_Protect_Meter_End-TP_1Bit_Eye_Protect_Meter_Start); i++) {
                ucTopPageIconBuffer[i] = TP_1Bit_Start+i;
            }
            break;   
#endif
#if ENABLE_ECO_SENSOR == ON
    case TP_ECO_SENSOR:
            for (i=0; i<(TP_1Bit_Eco_Sensor_End-TP_1Bit_Eco_Sensor_Start); i++) {
                ucTopPageIconBuffer[i] = TP_1Bit_Start+i;
            }
            break;     
    case TP_ECO_SENSOR_METER:
            for (i=0; i<(TP_1Bit_Eco_Sensor_Meter_End-TP_1Bit_Eco_Sensor_Meter_Start); i++) {
                ucTopPageIconBuffer[i] = TP_1Bit_Start+i + (TP_1Bit_Eco_Sensor_End-TP_1Bit_Eco_Sensor_Start);
            }
            break;   
#endif
#if ENABLE_ERGONOMICS == ON
    case TP_SMARTREMINDER:
            for (i=0; i<(TP_1Bit_SmartReminder_End-TP_1Bit_SmartReminder_Start); i++) {
                ucTopPageIconBuffer[i] = TP_1Bit_Start+i;
            }
            break;        
#endif            
    }
    
    bSelectTable = OSDFontTble1;
    {
        {  //dialog
            OSDAPI_WriteXYString(TRUE, ucXPos_Line1, DIALOG_ICON_POSY, ucOthers_PosTab[0*2+1] , &ucTopPageIconBuffer[0]);
            OSDAPI_WriteXYString(TRUE, ucXPos_Line2, DIALOG_ICON_POSY+1, ucOthers_PosTab[1*2+1] , &ucTopPageIconBuffer[ucOthers_PosTab[0*2+1]]);
            OSDAPI_WriteXYString(TRUE, ucXPos_Line3, DIALOG_ICON_POSY+2, ucOthers_PosTab[2*2+1] , &ucTopPageIconBuffer[ucOthers_PosTab[0*2+1] + ucOthers_PosTab[1*2+1]]);
        }
    }
}

void OSDShowCustomMenuTitle(UCHAR MenuType)
{
    UCHAR posX, CusKeyNum;
    
    if(MenuType == CUSTOM_MENU_TYPE_1){
        posX = OSD_TITLESTR_OFFSET_X+DIALOG_POSITION_OFFSET;
    }
    else if(MenuType == CUSTOM_MENU_TYPE_2){
        posX = OSD_TITLESTR_OFFSET_X+DIALOG2_POSITION_OFFSET;
    }

    CusKeyNum = fnGetCustomerKeyItem();

    OSDAPI_SetIndentIndex(String_Layer2_Index);
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
    bSelectTable = OSDFontTble1;
    OSDAPI_SetFontAttr(MAINMENU_TITLE);    
    ShowIndentString(TRUE, posX, 1, INDENT_STRING_MAX_LEN, CustKeyTabStr1[CusKeyNum*NUM_OSDLANGS + UserData.ucLanguage]);    
}

