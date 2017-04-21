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

UCHAR ucEcoMeter_PosTab[15] = {
    // X, Y, font num
    3, 2, 6,
    2, 3, 5,
    2, 4, 4,
    3, 5, 3,
    2, 6, 2
};

UCHAR ucEcoMeterCycle_PosTab[12] = {
    // X, Y, font num
    7, 3, 3,
    6, 4, 5,
    6, 5, 5,
    6, 6, 5    
};

//UCHAR *ucEcoMeterIconInfoTab[2] = {
    //ucEcoMeter_PosTab,
    //ucEcoMeterCycle_PosTab
//};


void OSDShowDialog(UCHAR dlg, UCHAR keyID)
{   
    //UCHAR i;
    OSDClosed();
    OSDAPI_SetHVZoom(0);
    OSDAPI_TurnOffOSD();
    OSDInitialize(TRUE);
    OSDLoadFont(ShowDialog_font); 
    if ((dlg == OSD_DLG_OSDUNLOCKKEY)||(dlg == OSD_DLG_REMINDER)) {
        OSDInitFrame(OSD_DIALOG_WIDTH+16, OSD_DIALOG_HEIGHT, DIALOG_MAIN_FRAME_COLOR);    
        OSDShowDialogFrame(0,0,OSD_DIALOG_WIDTH+16, OSD_DIALOG_HEIGHT);
        OSDShowBigWin(OSD_OSDUNLOCKINFO_WIN, OSD_WIN_BOARDER_SIZE);
#if ENABLE_OSD_ROTATION == ON
        if(UserData.bOSDRotation == TRUE){
		    OSDSetPosition(1955,789);    
        }
        else
#endif            
        {
            OSDSetPosition(1955,1241);
        }
    }
    else if (dlg == OSD_DLG_RESETNOTICE||dlg == OSD_DLG_RESETCOLORNOTICE||dlg == OSD_DLG_DCRNOTICE) {//ULEric140410
        OSDInitFrame(OSD_DIALOG_SELECTPAGE_TOTAL_WIDTH, OSD_DIALOG_SELECTPAGE_TOTAL_HEIGHT, DIALOG_MAIN_FRAME_COLOR);    
        OSDClearFrame(FrameWidthType_DialogMenu1);        
        OSDShowDialogFrame(OSD_DIALOG_SP_POSX,0,OSD_DIALOG_WIDTH, OSD_DIALOG_HEIGHT);
//        OSDClearDialogSpaceFrame(OSD_DIALOG_WIDTH,0,OSD_DIALOG_SELECTPAGE_WIDTH,OSD_DIALOG_SELECTPAGE_HEIGHT);   
//        OSDClearDialogSpaceFrame(0,OSD_DIALOG_HEIGHT,OSD_DIALOG_SELECTPAGE_WIDTH,OSD_DIALOG_SELECTPAGE_HEIGHT);    
#if ENABLE_OSD_ROTATION == ON
        if(UserData.bOSDRotation == TRUE){
		    OSDSetPosition(ROT_OSD_DIA_RESET_H_POSITION,ROT_OSD_DIA_RESET_V_POSITION);    
        }
        else
#endif            
        {
            OSDSetPosition(1894,1241);
        }

        OSDShowBigWin(OSD_RESET_WIN, OSD_WIN_BOARDER_SIZE);       
    }
    else if (dlg == OSD_DLG_SENSEYE_DEMO) {
        OSDInitFrame(OSD_SENSEYE_DEMO_WIDTH, OSD_SENSEYE_DEMO_HIGHT, SENSEYE_FRAME_COLOR);
        OSDSetPosition(452,0);
    }        
    else{
        OSDInitFrame(OSD_DIALOG_WIDTH, OSD_DIALOG_HEIGHT, DIALOG_MAIN_FRAME_COLOR);
        OSDShowDialogFrame(0,0,OSD_DIALOG_WIDTH, OSD_DIALOG_HEIGHT);    
        OSDShowBigWin(OSD_INFO_WIN, OSD_WIN_BOARDER_SIZE);
        if(UserData.bOSDRotation == TRUE){
            OSDSetPosition(2150,1000);//(2187,OSD_MAIN_MENU_V_POSITION);//input notice            
        }
        else{
            OSDSetPosition(2150,1250);//(2187,OSD_MAIN_MENU_V_POSITION);//input notice
        }
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
            OSDShowNoticeIcon(0);
            OSDAPI_SetIndentIndex(String_DialogString_Index);
            OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
            OSDAPI_SetFontAttr(NoticeStringColor);
            ShowIndentString(TRUE, 6, 3, 23, CustomKeyTab[keyID*NUM_OSDLANGS+UserData.ucLanguage]);
            break; 
        case OSD_DLG_OSDLOCK:
            OSDShowNoticeIcon(0);
            OSDAPI_SetIndentIndex(String_DialogString_Index);
            OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
            OSDAPI_SetFontAttr(NoticeStringColor);
            ShowIndentString(TRUE, 6, 3, 20, OSDLOckStrTab[UserData.bOSDLock*NUM_OSDLANGS+UserData.ucLanguage]);
            break;
        case OSD_DLG_OSDUNLOCKKEY:
            OSDShowNoticeIcon(0);
            OSDAPI_SetIndentIndex(String_DialogString_Index);
            OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
            OSDAPI_SetFontAttr(NoticeStringColor);
            ShowIndentString(TRUE, 6, 3, 39, OSDUnLockkeyStrTab[UserData.ucLanguage]);
            ShowIndentString(TRUE, 6, 4, 39, OSDUnLockkeyStrTab[NUM_OSDLANGS+UserData.ucLanguage]);
            break;        
        case OSD_DLG_NOSYNC:
            OSDShowNoticeIcon(0);
            OSDAPI_SetIndentIndex(String_DialogString_Index);
            OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
            OSDAPI_SetFontAttr(NoticeStringColor);
            ShowIndentString(TRUE, 6, 3, 20, DialogNosyncStrTab[UserData.ucLanguage]);
            break;
        case OSD_DLG_85Hz:
            OSDShowNoticeIcon(0);
            OSDAPI_SetIndentIndex(String_DialogString_Index);
            OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
            OSDAPI_SetFontAttr(NoticeStringColor);
            ShowIndentString(TRUE, 6, 3, 20, DialogOutOfRangStrTab[UserData.ucLanguage]);
            break;        
        case OSD_DLG_OUTOFRANGE:
            OSDShowNoticeIcon(0);
            OSDAPI_SetIndentIndex(String_DialogString_Index);
            OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
            OSDAPI_SetFontAttr(NoticeStringColor);
            ShowIndentString(TRUE, 6, 3, 20, DialogOutOfRangStrTab[UserData.ucLanguage]);
            break;
        case OSD_DLG_NOCABLE:
            OSDShowNoticeIcon(0);
            OSDAPI_SetIndentIndex(String_DialogString_Index);
            OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
            OSDAPI_SetFontAttr(NoticeStringColor);
            ShowIndentString(TRUE, 6, 3, 20, DialogNocableStrTab[UserData.ucLanguage]);
            break;        
        case OSD_DLG_REMINDER:
            OSDShowNoticeIcon(0);
            OSDAPI_SetIndentIndex(String_DialogString_Index);
            OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
            OSDAPI_SetFontAttr(NoticeStringColor);
            ShowIndentString(TRUE, 6, 3, 39, DialogReminderStrTab[UserData.ucLanguage]);
            break;        
        case OSD_DLG_NONPRESET:
            OSDShowNoticeIcon(0);
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
            if(UserData.ucInputSource == INPUT_SC_VGA){
                ShowIndentString(TRUE, 6, 4, 9, ResolutionVGAStr);                
            }
            else{
                ShowIndentString(TRUE, 6, 4, 9, ResolutionStr);
            }
            break;
        case OSD_DLG_RESETNOTICE://ULEric140410
            bSelectTable = OSDFontTble1;    
            OSDShowNoticeIcon(OSD_DIALOG_SP_POSX);
            OSDShowSelectPageMainFrame(FrameWidthType_DialogMenu1);
            OSDUpdateKeyInfo(TRUE,GetOSDState());
            OSDAPI_SetIndentIndex(String_DialogString_Index);
            OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
            OSDAPI_SetFontAttr(NoticeStringColor);
            ShowIndentString(TRUE, OSD_DIALOG_SP_POSX+6, 3, 20, ResetAllTab[UserData.ucLanguage]);    
            break;    
        case OSD_DLG_RESETCOLORNOTICE://ULEric140410
            bSelectTable = OSDFontTble1;
            OSDShowNoticeIcon(OSD_DIALOG_SP_POSX);
            OSDShowSelectPageMainFrame(FrameWidthType_DialogMenu1);
            OSDUpdateKeyInfo(TRUE,GetOSDState());
            OSDAPI_SetIndentIndex(String_DialogString_Index);
            OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
            OSDAPI_SetFontAttr(NoticeStringColor);
            ShowIndentString(TRUE, OSD_DIALOG_SP_POSX+6, 3, 20, ResetColorTab[UserData.ucLanguage]);
            break;   
        case OSD_DLG_DCRNOTICE:
            OSDShowNoticeIcon(OSD_DIALOG_SP_POSX);
            OSDShowSelectPageMainFrame(FrameWidthType_DialogMenu1);
            OSDUpdateKeyInfo(TRUE,GetOSDState());
            OSDAPI_SetIndentIndex(String_DialogString_Index);
            OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
            OSDAPI_SetFontAttr(NoticeStringColor);
            //ShowIndentString(TRUE, 6, 3, 20, PictureTab[(7*NUM_OSDLANGS)+UserData.ucLanguage]);
            //ShowIndentString(TRUE, 6, 3, 20, DialogDCRTab[UserData.ucLanguage]);    
            //UL Justin 140424
            ShowIndentString(TRUE, OSD_DIALOG_SP_POSX+6, 2,20, DialogDCRTab[0*NUM_OSDLANGS + UserData.ucLanguage]);
            ShowIndentString(TRUE, OSD_DIALOG_SP_POSX+6, 3,20, DialogDCRTab[1*NUM_OSDLANGS + UserData.ucLanguage]);
            ShowIndentString(TRUE, OSD_DIALOG_SP_POSX+6, 4,20, DialogDCRTab[2*NUM_OSDLANGS + UserData.ucLanguage]);
            break;
        case OSD_DLG_SENSEYE_DEMO:
            bSelectTable = OSDFontTble1;            
            OSDAPI_SetIndentIndex(String_DialogString_Index);
            OSDAPI_SetAlignType(OSD_ALIGN_CENTER);
            OSDAPI_SetFontAttr(NoticeStringColor);
            ShowIndentString(TRUE, 0, 0, 8, SenseyeOnOffTab[OFF]); 
            //ShowIndentString(TRUE, 20, 0, (PictureModeTab11[UserData.ucBFMode*NUM_OSDLANGS + UserData.ucLanguage][0]>5)?(PictureModeTab11[UserData.ucBFMode*NUM_OSDLANGS + UserData.ucLanguage][0]):5, PictureModeTab11[UserData.ucBFMode*NUM_OSDLANGS + UserData.ucLanguage]);
            ShowIndentString(TRUE, 19, 0, 8, PictureModeTab11[UserData.ucBFMode*NUM_OSDLANGS + UserData.ucLanguage]);
            ShowIndentString(TRUE, 38, 0, 8, SenseyeOnOffTab[ON]);
            OSDAPI_SetHVZoom(2);
            OSDAPI_SetAlignType(OSD_ALIGN_LEFT);
            break;        
        default:
            break;    
    }
    UserSetTransparent();
    OSDTurnOnOSD();
    bSelectTable = OSDFontTble1;
}


void OSDShowSelectPageButton_Bottom(UCHAR id, UCHAR act, BOOL Clr)
{

    UCHAR i;
    UCHAR Offset_x,Offset_y;

    if (act == FrameWidthType_MainMenu) {
	 Offset_x = OSD_SPOFFSET_BOTTOM;
        Offset_y = OSD_MAIN_HEIGHT;
    }
    else if (act == FrameWidthType_CustomerMenu1) {
	 Offset_x = OSD_CUSTOM_MENU1_SP_POSX;
        Offset_y = OSD_CUSTOM_MENU1_SP_POSY;
    }
    else if (act== FrameWidthType_CustomerMenu2) {
	 Offset_x = OSD_CUSTOM_MENU2_SP_POSX;        
        Offset_y = OSD_CUSTOM_MENU2_SP_POSY;
    }
    else if (act== FrameWidthType_DialogMenu1) {//ULEric140410
        Offset_x = 0;
        Offset_y = OSD_MAIN_HEIGHT;
    }    


    switch (id) {
        case 0:
            if (Clr) {        //Up	  
                for (i=0; i<4; i++){
                    OSDAPI_FillLineAttr(Offset_x, Offset_y+i, 1, MAINMENU_COLOR1);
                }
		        OSDAPI_FillLineAttr(Offset_x+1, Offset_y, BTN_Width-1, SELECTPAGE_2BIT_COLOR1);	
		        OSDAPI_FillLineAttr(Offset_x+BTN_Width, Offset_y, 1, SELECTPAGE_4BIT_COLOR1);
                for (i=1; i<4; i++) {
    		        OSDAPI_FillLineAttr(Offset_x+1, Offset_y+i, BTN_Width-1, SELECTPAGE_1BIT_COLOR1_WHITE_B1);
    		        OSDAPI_FillLineAttr(Offset_x+BTN_Width, Offset_y+i, 1, SELECTPAGE_2BIT_COLOR3);
                }
            }
            else {
                for (i=0; i<4; i++){
                    OSDAPI_FillLineAttr(Offset_x, Offset_y+i, 1, SELECTPAGE_2BIT_COLOR1_BLUE);
                }
        		OSDAPI_FillLineAttr(Offset_x+1, Offset_y, BTN_Width-1, SELECTPAGE_2BIT_COLOR1_BLUE);
        		OSDAPI_FillLineAttr(Offset_x+BTN_Width, Offset_y, 1, SELECTPAGE_4BIT_COLOR_BLUE_UPPER);
		        for (i=1; i<4; i++){ 
		      	    OSDAPI_FillLineAttr(Offset_x+1, Offset_y+i, BTN_Width, SELECTPAGE_1BIT_COLOR1_BLACK_B1);
			        OSDAPI_FillLineAttr(Offset_x+BTN_Width, Offset_y+i, 1, SELECTPAGE_2BIT_COLOR4);   
		        }
            }
            break;
        case 1:          //Down
            if(Clr) {
                OSDAPI_FillLineAttr(Offset_x+BTN_Width, Offset_y, 1, SELECTPAGE_4BIT_COLOR1);
        		OSDAPI_FillLineAttr(Offset_x+BTN_Width+1, Offset_y, BTN_Width-1, SELECTPAGE_2BIT_COLOR1);	
        		OSDAPI_FillLineAttr(Offset_x+BTN_Width*2, Offset_y, 1, SELECTPAGE_4BIT_COLOR1);
                for (i=1; i<4; i++) {
        		    OSDAPI_FillLineAttr(Offset_x+BTN_Width, Offset_y+i, 1, SELECTPAGE_2BIT_COLOR2);
        		    OSDAPI_FillLineAttr(Offset_x+BTN_Width+1, Offset_y+i, BTN_Width-1, SELECTPAGE_1BIT_COLOR1_WHITE_B1);
        		    OSDAPI_FillLineAttr(Offset_x+BTN_Width*2, Offset_y+i, 1, SELECTPAGE_2BIT_COLOR2);
                }
            }
            else {
                OSDAPI_FillLineAttr(Offset_x+BTN_Width, Offset_y, 1, SELECTPAGE_4BIT_COLOR_BLUE_LOWER);    
    		    OSDAPI_FillLineAttr(Offset_x+BTN_Width+1, Offset_y, BTN_Width-1, SELECTPAGE_2BIT_COLOR1_BLUE);
    		    OSDAPI_FillLineAttr(Offset_x+BTN_Width*2, Offset_y, 1, SELECTPAGE_4BIT_COLOR_BLUE_UPPER);
        	    for (i=1; i<4; i++){ 
            		OSDAPI_FillLineAttr(Offset_x+BTN_Width, Offset_y+i, 1, SELECTPAGE_2BIT_COLOR5);
            		OSDAPI_FillLineAttr(Offset_x+BTN_Width+1, Offset_y+i, BTN_Width-1, SELECTPAGE_1BIT_COLOR1_BLACK_B1); 
            		OSDAPI_FillLineAttr(Offset_x+BTN_Width*2, Offset_y+i, 1, SELECTPAGE_2BIT_COLOR4);
        		}
            }
            break;
        case 2:            //right

            if (Clr) {
                OSDAPI_FillLineAttr(Offset_x+id*BTN_Width, Offset_y, 1, SELECTPAGE_4BIT_COLOR1);
                OSDAPI_FillLineAttr(Offset_x+id*BTN_Width+1, Offset_y, BTN_Width-1, SELECTPAGE_2BIT_COLOR1);
		        OSDAPI_FillLineAttr(Offset_x+id*BTN_Width+BTN_Width, Offset_y, 1, SELECTPAGE_4BIT_COLOR1);	
                for (i=1; i<4; i++) {
                    if (i ==2 || i == 3) {
                        OSDAPI_FillLineAttr(Offset_x+id*BTN_Width, Offset_y+i, 1, SELECTPAGE_2BIT_COLOR2);
               	        if(OSDCheckHookIcon())//ULEric140327
                  	       OSDAPI_FillLineAttr(Offset_x+id*BTN_Width+1, Offset_y+i, BTN_Width,  TOPPAGEICON_1BIT_HOOK_COLOR_B1);
                        else
                            OSDAPI_FillLineAttr(Offset_x+id*BTN_Width+1, Offset_y+i, BTN_Width-1, SELECTPAGE_1BIT_COLOR1_WHITE_B1);
                    }
                    else {
                        OSDAPI_FillLineAttr(Offset_x+id*BTN_Width, Offset_y+i, 1, SELECTPAGE_2BIT_COLOR2);
                        OSDAPI_FillLineAttr(Offset_x+id*BTN_Width+1, Offset_y+i, BTN_Width-1, SELECTPAGE_1BIT_COLOR1_B1);
                    }
		            OSDAPI_FillLineAttr(Offset_x+id*BTN_Width+BTN_Width, Offset_y+i, 1, SELECTPAGE_2BIT_COLOR2);
                }
            }
            else {
		        OSDAPI_FillLineAttr(Offset_x+id*BTN_Width, Offset_y, 1, SELECTPAGE_4BIT_COLOR_BLUE_LOWER);
                OSDAPI_FillLineAttr(Offset_x+id*BTN_Width+1, Offset_y, BTN_Width-1, SELECTPAGE_2BIT_COLOR1_BLUE);
		        OSDAPI_FillLineAttr(Offset_x+id*BTN_Width+BTN_Width, Offset_y, 1, SELECTPAGE_4BIT_COLOR_BLUE_UPPER);
                for (i=1; i<4; i++) {
		            OSDAPI_FillLineAttr(Offset_x+id*BTN_Width, Offset_y+i, 1, SELECTPAGE_2BIT_COLOR5);
                    if (i ==2 || i == 3) {
                        OSDAPI_FillLineAttr(Offset_x+id*BTN_Width+1, Offset_y+i, BTN_Width-1, SELECTPAGE_1BIT_COLOR1_BLACK_B1);
                    }
                    else {
                        OSDAPI_FillLineAttr(Offset_x+id*BTN_Width+1, Offset_y+i, BTN_Width-1, SELECTPAGE_1BIT_COLOR1_BLUE_B1);
                    }
		            OSDAPI_FillLineAttr(Offset_x+(id+1)*BTN_Width, Offset_y+i, 1, SELECTPAGE_2BIT_COLOR4);
                }
            }
            break;
        case 3:        //Left        
            if (Clr) {
	            OSDAPI_FillLineAttr(Offset_x+id*BTN_Width, Offset_y, 1, SELECTPAGE_4BIT_COLOR1);
                OSDAPI_FillLineAttr(Offset_x+id*BTN_Width+1, Offset_y, BTN_Width-1, SELECTPAGE_2BIT_COLOR1);
		        OSDAPI_FillLineAttr(Offset_x+id*BTN_Width+BTN_Width, Offset_y, 1, SELECTPAGE_4BIT_COLOR1);				
                for (i=1; i<4; i++) {
                    if (i == 1 || i == 2) {
                        OSDAPI_FillLineAttr(Offset_x+id*BTN_Width, Offset_y+i, 1, SELECTPAGE_2BIT_COLOR2);
                        OSDAPI_FillLineAttr(Offset_x+id*BTN_Width+1, Offset_y+i, BTN_Width-1, SELECTPAGE_1BIT_COLOR1_WHITE_B1);
                    }
                    else {
                        OSDAPI_FillLineAttr(Offset_x+id*BTN_Width, Offset_y+i, 1, SELECTPAGE_2BIT_COLOR2);
                        OSDAPI_FillLineAttr(Offset_x+id*BTN_Width+1, Offset_y+i, BTN_Width-1, SELECTPAGE_1BIT_COLOR1_B1);
                    }
		            OSDAPI_FillLineAttr(Offset_x+id*BTN_Width+BTN_Width, Offset_y+i, 1, SELECTPAGE_2BIT_COLOR2);
                }
            }
            else  {
		        OSDAPI_FillLineAttr(Offset_x+id*BTN_Width, Offset_y, 1, SELECTPAGE_4BIT_COLOR_BLUE_LOWER);
                OSDAPI_FillLineAttr(Offset_x+id*BTN_Width+1, Offset_y, BTN_Width-1, SELECTPAGE_2BIT_COLOR1_BLUE);
		        OSDAPI_FillLineAttr(Offset_x+id*BTN_Width+BTN_Width, Offset_y, 1, SELECTPAGE_4BIT_COLOR_BLUE_UPPER);
                for (i=1; i<4; i++) {
                    if (i == 1 || i == 2) {
                        OSDAPI_FillLineAttr(Offset_x+id*BTN_Width, Offset_y+i, 1, SELECTPAGE_2BIT_COLOR5);
                        OSDAPI_FillLineAttr(Offset_x+id*BTN_Width+1, Offset_y+i, BTN_Width-1, SELECTPAGE_1BIT_COLOR1_BLACK_B1);
                    }
                    else {
                        OSDAPI_FillLineAttr(Offset_x+id*BTN_Width, Offset_y+i, 1, SELECTPAGE_2BIT_COLOR5);
                        OSDAPI_FillLineAttr(Offset_x+id*BTN_Width+1, Offset_y+i, BTN_Width-1, SELECTPAGE_1BIT_COLOR1_BLUE_B1);
                    }
		            OSDAPI_FillLineAttr(Offset_x+(id+1)*BTN_Width, Offset_y+i, 1, SELECTPAGE_2BIT_COLOR4);
                }
            }
            break;
        case 4:        //exit
        
            if (Clr) {
                OSDAPI_FillLineAttr(Offset_x+id*BTN_Width, Offset_y, 1, SELECTPAGE_4BIT_COLOR1);
                OSDAPI_FillLineAttr(Offset_x+id*BTN_Width+1, Offset_y, BTN_Width, SELECTPAGE_2BIT_COLOR1);
                OSDAPI_FillLineAttr(Offset_x+id*BTN_Width, Offset_y+1, 1, SELECTPAGE_2BIT_COLOR2);
                OSDAPI_FillLineAttr(Offset_x+id*BTN_Width+1, Offset_y+1, BTN_Width-1, SELECTPAGE_1BIT_COLOR1_B1);
            	for (i=1; i<4; i++) {
            		OSDAPI_FillLineAttr(Offset_x+id*BTN_Width+BTN_Width, Offset_y+i, 1, SELECTPAGE_2BIT_COLOR1);
            	}
                for (i=0; i<2; i++) {
                    OSDAPI_FillLineAttr(Offset_x+id*BTN_Width, Offset_y+2+i, 1, SELECTPAGE_2BIT_COLOR2);
                    OSDAPI_FillLineAttr(Offset_x+id*BTN_Width+1, Offset_y+2+i, BTN_Width-1, TOPPAGEICON_1BIT_EXIT_COLOR_B1);
                }
            }
            else  {
                OSDAPI_FillLineAttr(Offset_x+id*BTN_Width, Offset_y, 1, SELECTPAGE_4BIT_COLOR_BLUE_LOWER);
                OSDAPI_FillLineAttr(Offset_x+id*BTN_Width+1, Offset_y, BTN_Width, SELECTPAGE_2BIT_COLOR1_BLUE);
                OSDAPI_FillLineAttr(Offset_x+id*BTN_Width, Offset_y+1, 1, SELECTPAGE_2BIT_COLOR5);
                OSDAPI_FillLineAttr(Offset_x+id*BTN_Width+1, Offset_y+1, BTN_Width-1, SELECTPAGE_1BIT_COLOR1_BLUE_B1);
        		for (i=1; i<4; i++) {
        			OSDAPI_FillLineAttr(Offset_x+id*BTN_Width+BTN_Width, Offset_y+i, 1, SELECTPAGE_2BIT_COLOR1_BLUE);
        		}
                for (i=0; i<2; i++) {
                    OSDAPI_FillLineAttr(Offset_x+id*BTN_Width, Offset_y+2+i, 1, SELECTPAGE_2BIT_COLOR5);
                    OSDAPI_FillLineAttr(Offset_x+id*BTN_Width+1, Offset_y+2+i, BTN_Width-1, TOPPAGEICON_1BIT_EXIT_COLOR2_B1);
                }
            }
            break;
        }

}

void OSDShowSelectPageButton_Left(UCHAR id, UCHAR act, BOOL Clr)
{
    
    UCHAR i;
    UCHAR Offset_x,Offset_y;
    
    if (act == FrameWidthType_MainMenu) {
        Offset_x = 0;
	 Offset_y = OSD_SPOFFSET_ROTATE;
    }
    else if (act == FrameWidthType_CustomerMenu1) {
        Offset_x = 0;
        Offset_y = 0;
    }
    else if (act== FrameWidthType_CustomerMenu2) {
        Offset_x = 0; 
        Offset_y = 0;
    }
    else if (act== FrameWidthType_DialogMenu1) {//ULEric140410
        Offset_x = 0;
        Offset_y = 0;
    }    

    switch (id) {
        case 0:
            if (Clr) {        //Up
                OSDAPI_FillLineAttr(Offset_x, Offset_y, 6, MAINMENU_COLOR1);
                for (i=0; i<4; i++) {
                    if (i == 2 || i == 3) {
			            OSDAPI_FillLineAttr(Offset_x, Offset_y+1+i, 5, SELECTPAGE_1BIT_COLOR1_WHITE);
                        OSDAPI_FillLineAttr(Offset_x+5, Offset_y+1+i, 1, SELECTPAGE_2BIT_COLOR1);
                    }
                    else {
        			   OSDAPI_FillLineAttr(Offset_x, Offset_y+1+i, 5, SELECTPAGE_1BIT_COLOR1);
                       OSDAPI_FillLineAttr(Offset_x+5, Offset_y+1+i, 1, SELECTPAGE_2BIT_COLOR1);
                    }
                }
		        OSDAPI_FillLineAttr(Offset_x, Offset_y+5, 5, SELECTPAGE_2BIT_COLOR3);
                OSDAPI_FillLineAttr(Offset_x+5, Offset_y+5, 1, SELECTPAGE_2BIT_COLOR3);
            }
            else {
                OSDAPI_FillLineAttr(Offset_x, Offset_y+0, 6, SELECTPAGE_2BIT_COLOR1_BLUE);
                for (i=0; i<4; i++) {
                    if (i == 2 || i == 3) {
			            OSDAPI_FillLineAttr(Offset_x, Offset_y+1+i, 5, SELECTPAGE_1BIT_COLOR1_BLACK);
                        OSDAPI_FillLineAttr(Offset_x+5, Offset_y+1+i, 1, SELECTPAGE_2BIT_COLOR1_BLUE);
                    }
                    else {
                        OSDAPI_FillLineAttr(Offset_x, Offset_y+1+i, 5, SELECTPAGE_1BIT_COLOR1_BLUE);
                        OSDAPI_FillLineAttr(Offset_x+5, Offset_y+1+i, 1, SELECTPAGE_2BIT_COLOR1_BLUE);
                    }
                }
		        OSDAPI_FillLineAttr(Offset_x, Offset_y+5, 5, SELECTPAGE_2BIT_COLOR4);
                OSDAPI_FillLineAttr(Offset_x+5, Offset_y+5, 1, SELECTPAGE_2BIT_COLOR1_BLUE);
            }
            break;

        case 1:            //Down
            if (Clr) {
              for (i=0; i<5; i++) {
                    if (i ==1 || i == 2) {
                        OSDAPI_FillLineAttr(Offset_x+5, Offset_y+6+i, 1, SELECTPAGE_2BIT_COLOR1);
                        OSDAPI_FillLineAttr(Offset_x, Offset_y+6+i, 5, SELECTPAGE_1BIT_COLOR1_WHITE);
                    }
                    else {
                        OSDAPI_FillLineAttr(Offset_x+5, Offset_y+6+i, 1, SELECTPAGE_2BIT_COLOR1);
                        OSDAPI_FillLineAttr(Offset_x, Offset_y+6+i, 5, SELECTPAGE_1BIT_COLOR1);
                    }
                }
                OSDAPI_FillLineAttr(Offset_x+5, Offset_y+11, 1, SELECTPAGE_4BIT_COLOR1);
                OSDAPI_FillLineAttr(Offset_x, Offset_y+11, 5, SELECTPAGE_2BIT_COLOR3);
            }
            else {
                for (i=0; i<5; i++) {
                    if (i ==1 || i == 2) {
                        OSDAPI_FillLineAttr(Offset_x+5, Offset_y+6+i, 1, SELECTPAGE_2BIT_COLOR1_BLUE);
                        OSDAPI_FillLineAttr(Offset_x, Offset_y+6+i, 5, SELECTPAGE_1BIT_COLOR1_BLACK);
                    }
                    else {
                        OSDAPI_FillLineAttr(Offset_x+5, Offset_y+6+i, 1, SELECTPAGE_2BIT_COLOR1_BLUE);
                        OSDAPI_FillLineAttr(Offset_x, Offset_y+6+i, 5, SELECTPAGE_1BIT_COLOR1_BLUE);
                    }
                }
                OSDAPI_FillLineAttr(Offset_x+5, Offset_y+11, 1, SELECTPAGE_4BIT_COLOR_BLUE_UPPER);
                OSDAPI_FillLineAttr(Offset_x, Offset_y+11, 5, SELECTPAGE_2BIT_COLOR4);
            }
            break;

        case 2:            //right
            if (Clr) {
                OSDAPI_FillLineAttr(Offset_x+5, Offset_y+id*5+1, 1, SELECTPAGE_4BIT_COLOR1);
                OSDAPI_FillLineAttr(Offset_x, Offset_y+id*5+1, 5, SELECTPAGE_2BIT_COLOR3);
                for (i=0; i<4; i++) {
                    if (i ==1 || i == 2) {
                        OSDAPI_FillLineAttr(Offset_x+5, Offset_y+id*5+2+i, 1, SELECTPAGE_2BIT_COLOR1);
                        if(OSDCheckHookIcon())//ULEric140327
                            OSDAPI_FillLineAttr(Offset_x, Offset_y+id*5+2+i, 5,  TOPPAGEICON_1BIT_HOOK_COLOR);
                        else
                        OSDAPI_FillLineAttr(Offset_x, Offset_y+id*5+2+i, 5, SELECTPAGE_1BIT_COLOR1_WHITE);
                    }
                    else {
                        OSDAPI_FillLineAttr(Offset_x+5, Offset_y+id*5+2+i, 1, SELECTPAGE_2BIT_COLOR1);
                        OSDAPI_FillLineAttr(Offset_x,Offset_y+ id*5+2+i, 5, SELECTPAGE_1BIT_COLOR1);
                    }
                }
                OSDAPI_FillLineAttr(Offset_x+5, Offset_y+(id)*5+2+i, 1, SELECTPAGE_4BIT_COLOR1);
                OSDAPI_FillLineAttr(Offset_x, Offset_y+(id)*5+2+i, 5, SELECTPAGE_2BIT_COLOR3);
            }
            else {
                OSDAPI_FillLineAttr(Offset_x+5, Offset_y+id*5+1, 1, SELECTPAGE_4BIT_COLOR_BLUE_LOWER);
                OSDAPI_FillLineAttr(Offset_x, Offset_y+id*5+1, 5, SELECTPAGE_2BIT_COLOR5);
                for (i=0; i<4; i++) {
                    if (i ==1 || i == 2) {
                        OSDAPI_FillLineAttr(Offset_x+5, Offset_y+id*5+2+i, 1, SELECTPAGE_2BIT_COLOR1_BLUE);
                        OSDAPI_FillLineAttr(Offset_x,Offset_y+ id*5+2+i, 5, SELECTPAGE_1BIT_COLOR1_BLACK);
                    }
                    else {
                        OSDAPI_FillLineAttr(Offset_x+5, Offset_y+id*5+2+i, 1, SELECTPAGE_2BIT_COLOR1_BLUE);
                        OSDAPI_FillLineAttr(Offset_x, Offset_y+id*5+2+i, 5, SELECTPAGE_1BIT_COLOR1_BLUE);
                    }
                }
                OSDAPI_FillLineAttr(Offset_x+5, (id)*5+2+i, 1, SELECTPAGE_4BIT_COLOR_BLUE_UPPER);
                OSDAPI_FillLineAttr(Offset_x, (id)*5+2+i, 5, SELECTPAGE_2BIT_COLOR4);
            }
            break;

        case 3:        //Left
            if (Clr) {
                OSDAPI_FillLineAttr(Offset_x+5, Offset_y+id*5+1, 1, SELECTPAGE_4BIT_COLOR1);
                OSDAPI_FillLineAttr(Offset_x, Offset_y+id*5+1, 5, SELECTPAGE_2BIT_COLOR3);
                for (i=0; i<4; i++) {
                    if (i == 1 || i == 2) {
                        OSDAPI_FillLineAttr(Offset_x+5, Offset_y+id*5+2+i, 1, MAINMENU_COLOR1);
                        OSDAPI_FillLineAttr(Offset_x, Offset_y+id*5+2+i, 5, SELECTPAGE_1BIT_COLOR1_WHITE);
                    }
                    else {
                        OSDAPI_FillLineAttr(Offset_x+5, Offset_y+id*5+2+i, 1, MAINMENU_COLOR1);
                        OSDAPI_FillLineAttr(Offset_x, Offset_y+id*5+2+i, 5, MAINMENU_COLOR2);
                    }
                }
                OSDAPI_FillLineAttr(Offset_x+5, Offset_y+(id)*5+2+i, 1, SELECTPAGE_2BIT_COLOR3);
                OSDAPI_FillLineAttr(Offset_x, Offset_y+(id)*5+2+i, 5, SELECTPAGE_2BIT_COLOR3);
            }
            else  {
                OSDAPI_FillLineAttr(Offset_x+5, Offset_y+id*5+1, 1, SELECTPAGE_4BIT_COLOR_BLUE_LOWER);
                OSDAPI_FillLineAttr(Offset_x, Offset_y+id*5+1, 5, SELECTPAGE_2BIT_COLOR5);
                for (i=0; i<4; i++) {
                    if (i == 1 || i == 2) {
                        OSDAPI_FillLineAttr(Offset_x+5, Offset_y+id*5+2+i, 1, SELECTPAGE_2BIT_COLOR1_BLUE);
                        OSDAPI_FillLineAttr(Offset_x, Offset_y+id*5+2+i, 5, SELECTPAGE_1BIT_COLOR1_BLACK);
                    }
                    else {
                        OSDAPI_FillLineAttr(Offset_x+5, Offset_y+id*5+2+i, 1, SELECTPAGE_2BIT_COLOR1_BLUE);
                        OSDAPI_FillLineAttr(Offset_x,Offset_y+ id*5+2+i, 5, SELECTPAGE_1BIT_COLOR1_BLUE);
                    }
                }
                OSDAPI_FillLineAttr(Offset_x+5, (id)*5+2+i, 1, SELECTPAGE_2BIT_COLOR1_BLUE);
                OSDAPI_FillLineAttr(Offset_x, (id)*5+2+i, 5, SELECTPAGE_2BIT_COLOR4);
            }
            break;

        case 4:        //exit
            if (Clr) {
                for (i=0; i<5; i++) {
        		    OSDAPI_FillLineAttr(Offset_x+5, Offset_y+id*5+2+i, 1, MAINMENU_COLOR1);
        		    if (i == 1 || i ==2){
                              OSDAPI_FillLineAttr(Offset_x, Offset_y+id*5+2+i, 5, TOPPAGEICON_1BIT_EXIT_COLOR);
        		    	}
        		    else {
                              OSDAPI_FillLineAttr(Offset_x, Offset_y+id*5+2+i, 5, SELECTPAGE_1BIT_COLOR1);
        		    }
                }
                OSDAPI_FillLineAttr(Offset_x, Offset_y+id*5+2+i, 6, SELECTPAGE_2BIT_COLOR1_BLUE);
            }
            else  {
                for (i=0; i<5; i++) {
		            OSDAPI_FillLineAttr(Offset_x+5, Offset_y+id*5+2+i, 1, SELECTPAGE_2BIT_COLOR1_BLUE);
        		    if (i == 1 || i ==2){
                        OSDAPI_FillLineAttr(Offset_x, Offset_y+id*5+2+i, 5, TOPPAGEICON_1BIT_EXIT_COLOR2);
        		    }
        		    else {
                        OSDAPI_FillLineAttr(Offset_x, Offset_y+id*5+2+i, 5, SELECTPAGE_1BIT_COLOR1_BLUE);
        		    }
                }
                OSDAPI_FillLineAttr(Offset_x, Offset_y+id*5+2+i, 6, SELECTPAGE_2BIT_COLOR1_BLUE);
            }
            break;
    }
}


void OSDShowECOMeterNotice(void)
{
	//UCHAR i;
    
    //OSDAPI_TurnOffOSD();
    OSDClosed();
    OSDDisableWinRotation();

    //OSDInitialize(TRUE);
    OSDAPI_SetFontSize(OSD_FONT_12X18);
    
    OSDAPI_Set2BitsFontAddr(OSDSRAM_ADDR_FLOOR(OSD_ROT_RAM_SIZE - 27*144 - 18*50));
    OSDAPI_Set3BitsFontAddr(OSDSRAM_ADDR_FLOOR(OSD_ROT_RAM_SIZE - 27*144));

    OSDInitFrame(OSD_ECO_METER_WIDTH, OSD_ECO_METER_HEIGHT, MAIN_FRAME_COLOR);
//    OSDSetPosition(1800,OSD_MAIN_MENU_V_POSITION);
    OSDAPI_SetHVZoom(0);
    OSDSetPosition(PANEL_WIDTH-220,PANEL_HEIGHT-220);

    OSDLoadFont(ECO_Meter_font);
    //ECOMeterBorder
    OSDAPI_SetFontAttr(MAINMENU_COLOR1);
    OSDShowECOMeterBorder();
    OSDAPI_SetFontAttr(ECO_METER_2BIT_COLOR);
    OSDShowECOMeterIcon();

    OSDShowECOMeterCycle(Custom_System.ucECOCycleStep);
    //OSDAPI_TurnOnOSD();
    OSDTurnOnOSD();
}

void OSDShowECOMeterBorder(void)
{
    UCHAR i;

    OSDAPI_WriteXYChar(TRUE, 0, 0, EcoMeterBorder1);
    OSDAPI_WriteXYRepeatChar(TRUE, 1, 0, 11, EcoMeterBorder2);
    OSDAPI_WriteXYChar(TRUE, OSD_ECO_METER_WIDTH-1, 0, EcoMeterBorder3);
    for (i=0; i<7; i++) {
        OSDAPI_WriteXYChar(TRUE, 0, i+1, EcoMeterBorder4);
        OSDAPI_WriteXYChar(TRUE, OSD_ECO_METER_WIDTH-1, i+1, EcoMeterBorder5);
    }
    OSDAPI_WriteXYChar(TRUE, 0, OSD_ECO_METER_HEIGHT-1, EcoMeterBorder6);
    OSDAPI_WriteXYRepeatChar(TRUE, 1, OSD_ECO_METER_HEIGHT-1, 11, EcoMeterBorder7);
    OSDAPI_WriteXYChar(TRUE, OSD_ECO_METER_WIDTH-1, OSD_ECO_METER_HEIGHT-1, EcoMeterBorder8);
}

void OSDShowECOMeterIcon(void)
{
    UCHAR i, index;
    UCHAR ucECOMeterIconBuffer[20] = {0};

    index = 0;
    
    OSDAPI_SetFontAttr(ECO_METER_2BIT_COLOR);

    // Load Fonts into the Buffer
    for (i=0; i<(EM_Icon_End-EM_Icon); i++) {
        ucECOMeterIconBuffer[i] = EM_Icon+i;
    }
    for (i=0; i<5; i++) {
        OSDAPI_WriteXYString(TRUE, ucEcoMeter_PosTab[i*3], ucEcoMeter_PosTab[i*3+1], ucEcoMeter_PosTab[i*3+2] , &ucECOMeterIconBuffer[index]);
        index += ucEcoMeter_PosTab[i*3+2];
    }
}

void OSDShowECOMeterCycle(UCHAR step)
{
    UCHAR i, index;
    UCHAR ucECOMeterIconBuffer[18] = {0};
#if 1
//    for (j=0; j<8; j++) {
        OSDAPI_SetFontAttr(ECO_METER_3BIT_COLOR);
        for (i=0; i<18; i++) {
            ucECOMeterIconBuffer[i] = EM_Icon_Cycle1+step*18+i; 
        	}
        index =0;

        for (i=0; i<4; i++) {
            OSDAPI_WriteXYString(TRUE, ucEcoMeterCycle_PosTab[i*3], ucEcoMeterCycle_PosTab[i*3+1], ucEcoMeterCycle_PosTab[i*3+2] , &ucECOMeterIconBuffer[index]);
            index += ucEcoMeterCycle_PosTab[i*3+2];
        }
        
//        Sleep(600);
//    }
#else
    for (j=0; j<8; j++) {
        OSDAPI_SetFontAttr(ECO_METER_3BIT_COLOR);
        for (i=0; i<18; i++) {
            ucECOMeterIconBuffer[i] = EM_Icon_Cycle1+j*18+i; 
        	}
        index =0;

        for (i=0; i<4; i++) {
            OSDAPI_WriteXYString(TRUE, ucEcoMeterCycle_PosTab[i*3], ucEcoMeterCycle_PosTab[i*3+1], ucEcoMeterCycle_PosTab[i*3+2] , &ucECOMeterIconBuffer[index]);
            index += ucEcoMeterCycle_PosTab[i*3+2];
        }
        
        Sleep(600);
    }
#endif    
}

void OSDEnterEyeProtectMeterNotice(void)
{
    SetOSDState(OSD_INFO_EYE_PROTECT_METER_STATE);
    OSDShowEyeProtectMeterIcon();
}

void OSDShowEyeProtectMeterIcon(void)
{
    UCHAR i;
    UCHAR ucEyeProMeterIconBuffer[20] = {0};

    //OSDAPI_TurnOffOSD();
    OSDDisableWinRotation();
    OSDClosed();
    //OSDInitialize(TRUE);
    OSDAPI_SetFontSize(OSD_FONT_12X18);

    OSDAPI_Set1BitFontAddr(OSDSRAM_ADDR_CEILING(OSDAPI_GetOSDFrameSize(OSD_ECO_METER_WIDTH, OSD_ECO_METER_HEIGHT)));
    OSDAPI_Set2BitsFontAddr(OSDSRAM_ADDR_FLOOR(OSD_ROT_RAM_SIZE - 18*30));
    
    OSDInitFrame(OSD_EYE_PRO_METER_WIDTH, OSD_EYE_PRO_METER_HEIGHT, MAIN_FRAME_COLOR);
    OSDAPI_SetHVZoom(0);
    OSDSetPosition(PANEL_WIDTH-220,PANEL_HEIGHT-220);

    //OSDAPI_SetFontAttr(ECO_METER_2BIT_COLOR);
    OSDAPI_SetFontAttr(MAINMENU_COLOR1);
    OSDLoadFont(Eye_Protect_Meter_font);
    OSDShowECOMeterBorder();

    for (i=0; i<(Eye_Protect_Meter_end-Eye_Protect_Meter_start); i++) {
        ucEyeProMeterIconBuffer[i] = Eye_Protect_Meter_start+i;
    }

    // Draw the Eye Icon
    OSDAPI_SetFontAttr(EyeProMeter_Color2);
    OSDAPI_WriteXYString(TRUE, 4, 3, 6 , &ucEyeProMeterIconBuffer[1]);
    OSDAPI_WriteXYString(TRUE, 4, 4, 6 , &ucEyeProMeterIconBuffer[7]);
    OSDAPI_WriteXYString(TRUE, 5, 5, 4 , &ucEyeProMeterIconBuffer[13]);

    // Draw the Slide Bar
    OSDAPI_SetFontAttr(EyeProMeter_Color1);
    OSDAPI_WriteXYChar(TRUE, 3, 6, ucEyeProMeterIconBuffer[17]);
    for (i=0 ;i<3; i++){
        OSDAPI_WriteXYString(TRUE, 4+2*i, 6, 2 , &ucEyeProMeterIconBuffer[18]);
    }

    OSDShowEyeProtectMeterWin();
    //OSDAPI_TurnOnOSD();
    OSDTurnOnOSD();

}

void OSDShowEyeProtectMeterWin(void)
{
    OSDWinAttr attr;
    
    OSDAPI_SelOSDWin(OSD_WINDOW1);
    RST_WINATTR_ALL(attr);
    attr.ucWinClr= I_BENQ_GRAY_9;
    OSDAPI_SetOSDWinAttr(attr);

    OSDAPI_SetOSDWinSize(OSD_EPM_WIN_H_START, OSD_EPM_WIN_V_START, OSD_EPM_WIN_H_END+8*Custom_System.ucEYE_Meter_Step, OSD_EPM_WIN_V_END);
    OSDAPI_OSDWinOn(OSD_WINDOW1);
}

void OSDPageMainFrame_Left(UCHAR Offset_x, UCHAR Offset_y, UCHAR Width)
{
    UCHAR i;
    Offset_y = 0;//no use
    // Top
    OSDAPI_SetFontAttr(MAINMENU_COLOR1);
    OSDAPI_WriteXYRepeatChar(TRUE, Offset_x, 0, Width, SP_TopRepeat); 
    OSDAPI_WriteXYChar(TRUE, Offset_x+5, 0, SP_RightTopCorner);    

    // Bottom
    OSDAPI_WriteXYRepeatChar(TRUE, Offset_x, 27, Width, SP_BottomRepeat);
    //OSDAPI_WriteXYChar(TRUE, Offset_x+5, 25, SP_LeftBottomCorner_1);
    OSDAPI_WriteXYChar(TRUE, Offset_x+5, 27, SP_LeftBottomCorner_2);  

    // RightSide Repeat
    for (i=0; i<4; i++) 
        OSDAPI_WriteXYChar(TRUE, Offset_x+5, 1+i, SP_LeftSideRepeat);
    for (i=0; i<5; i++)
        OSDAPI_WriteXYChar(TRUE, Offset_x+5, 6+i, SP_LeftSideRepeat);
    for (i=0; i<4; i++) 
        OSDAPI_WriteXYChar(TRUE, Offset_x+5, 12+i, SP_LeftSideRepeat);
    for (i=0; i<4; i++) 
        OSDAPI_WriteXYChar(TRUE, Offset_x+5, 17+i, SP_LeftSideRepeat);
    for (i=0; i<5; i++) 
        OSDAPI_WriteXYChar(TRUE, Offset_x+5, 22+i, SP_LeftSideRepeat);

    // 1thIcon cross
    OSDAPI_SetFontAttr(SELECTPAGE_2BIT_COLOR1);
    OSDAPI_WriteXYChar(TRUE, Offset_x+5, 5, SP_3thIcon_LeftSideCross);
    OSDAPI_SetFontAttr(SELECTPAGE_2BIT_COLOR2);
    OSDAPI_WriteXYRepeatChar(TRUE, Offset_x, 5, Width, SP_FirstIcon_CrossRepeat);

    // 2thIcon cross
    OSDAPI_SetFontAttr(SELECTPAGE_4BIT_COLOR1);
    OSDAPI_WriteXYChar(TRUE, Offset_x+5, 11, SP_SecondIcon_LeftSideCross);
    OSDAPI_SetFontAttr(SELECTPAGE_2BIT_COLOR2);
    OSDAPI_WriteXYRepeatChar(TRUE, Offset_x, 11, Width, SP_SecondIcon_CrossRepeat);

    // 3thIcon cross
    OSDAPI_SetFontAttr(SELECTPAGE_4BIT_COLOR1);
    OSDAPI_WriteXYChar(TRUE, Offset_x+5, 16, SP_FirstIcon_LeftSideCross);
    OSDAPI_SetFontAttr(SELECTPAGE_2BIT_COLOR2);
    OSDAPI_WriteXYRepeatChar(TRUE, Offset_x, 16, Width, SP_3thIcon_CrossRepeat);

    // 4thIcon cross
    OSDAPI_SetFontAttr(SELECTPAGE_2BIT_COLOR1);
    OSDAPI_WriteXYChar(TRUE, Offset_x+5, 21, SP_4thIcon_LeftSideCross);
    OSDAPI_SetFontAttr(SELECTPAGE_2BIT_COLOR2);
    OSDAPI_WriteXYRepeatChar(TRUE, Offset_x, 21, Width, SP_4thIcon_CrossRepeat);

    // inside icon 1bit part
    OSDAPI_SetFontAttr(MAINMENU_COLOR2);
    for (i=0; i<4; i++) 
        OSDAPI_WriteXYRepeatChar(TRUE, Offset_x, 1+i, Width, _SPACE_);
    for (i=0; i<5; i++)
        OSDAPI_WriteXYRepeatChar(TRUE, Offset_x, 6+i, Width, _SPACE_);
    for (i=0; i<4; i++) 
        OSDAPI_WriteXYRepeatChar(TRUE, Offset_x, 12+i, Width, _SPACE_);
    for (i=0; i<4; i++) 
        OSDAPI_WriteXYRepeatChar(TRUE, Offset_x, 17+i, Width, _SPACE_);
    for (i=0; i<5; i++) 
        OSDAPI_WriteXYRepeatChar(TRUE, Offset_x, 22+i, Width, _SPACE_);

    // clear bottom
    OSDAPI_SetFontAttr(CLEAR_SELECTEDPAGE_BOTTOM_COLOR);
    OSDAPI_WriteXYRepeatChar(TRUE, Offset_x, 28, (Width+1), _SPACE_);

}

void OSDDisableWinRotation(void)
{
    OSDAPI_RotateOSDWin(OSD_WINDOW1, OSD_POS_ROT_OFF);
    OSDAPI_RotateOSDWin(OSD_WINDOW2, OSD_POS_ROT_OFF);
    OSDAPI_RotateOSDWin(OSD_WINDOW3, OSD_POS_ROT_OFF);
    OSDAPI_RotateOSDWin(OSD_WINDOW4, OSD_POS_ROT_OFF);
    OSDAPI_RotateOSDWin(OSD_WINDOW5, OSD_POS_ROT_OFF);
    OSDAPI_RotateOSDWin(OSD_WINDOW6, OSD_POS_ROT_OFF);
    OSDAPI_RotateOSDWin(OSD_WINDOW7, OSD_POS_ROT_OFF);
    OSDAPI_RotateOSDWin(OSD_WINDOW8, OSD_POS_ROT_OFF);
    Sleep(80);
    OSDAPI_Rotated_OSD_Off();
}


void OSDShowLayer3PageHookIcon(UCHAR pageNum)
{
	UCHAR ItemNum=0;

    if (ucMenuType == OSD_MAIN_SYSTEM) {
    	if (ucSubMenuType == OSD_SYS_CTKEY1 ) {//Justin 140428 CustomerKey1
    		ItemNum = UserData.ucCustomerKey1;
    	}
    	else if(ucSubMenuType == OSD_SYS_CTKEY2 ) {//Justin 140428 CustomerKey1
    		ItemNum = UserData.ucCustomerKey2;
    	}
    	else if(ucSubMenuType == OSD_SYS_CTKEY3 ) {//Justin 140428 CustomerKey1
    		ItemNum = UserData.ucCustomerKey3;
    	}
    }
	else if (ucMenuType == OSD_MAIN_PICTURE_ADVANCED) { 
        if(ucSubMenuType == OSD_PICTURE_AD_PIC ) {//Justin 140428 CustomerKey1
		    ItemNum = Custom_System.ucOSD_preview_temp;//UserData.ucBFMode;
        }
	}

	if(pageNum == LAYER3_PAGE_2){
		if (ItemNum < (OSD_MAX_LINES)) {
			OSDShowHookIcon(CLEAR_1BIT_COLOR, ucSubMenuType, STRING_LAYER_3, _SPACE_);
		}
		else {
			OSDShowHookIcon(UnSelectedStringColor1_256, ucSubMenuType, STRING_LAYER_3, Hook_Icon);
		}
	}
	else if(pageNum == LAYER3_PAGE_1){
        if(ItemNum > (OSD_MAX_LINES-1)) {
            OSDShowHookIcon(CLEAR_1BIT_COLOR, ucSubMenuType, STRING_LAYER_3, _SPACE_);
        }
        else {
            OSDShowHookIcon(UnSelectedStringColor1_256, ucSubMenuType, STRING_LAYER_3, Hook_Icon);
        }
	}
}

void OSDShowLayer4SliderBar(UCHAR type,UCHAR redraw)
{
    UCHAR value;
    switch(type){
#if ENABLE_ANIMATION_MODE == ON                 
        case SLIBAR_ANIMATION_LAYER4:
            value = UserData.ucAnimationMode;
            ucSliderMaxValue = 10;
            break;
#endif            
        default:
            break;
    }

    if (redraw) {
        OSDShowSliderBar(OSD_LAYER4_SLIDER_BAR_POSX, OSD_LAYER4_SLIDER_BAR_POSY, value, TRUE, SLIDERBAR_BLUE_COLOR);
        bSelNum2 = TRUE;
        OSDShowNum2(OSD_LAYER4_SLIDER_BAR_NUM_POSX, OSD_LAYER4_SLIDER_BAR_NUM_POSY, value, 0);
    }
    else {
        OSDShowSliderBar(OSD_LAYER4_SLIDER_BAR_POSX, OSD_LAYER4_SLIDER_BAR_POSY, value, FALSE, SLIDERBAR_GRAY_COLOR);
        bSelNum2 = FALSE;
        OSDShowNum2(OSD_LAYER4_SLIDER_BAR_NUM_POSX, OSD_LAYER4_SLIDER_BAR_NUM_POSY, value, 0);
    }

}


BOOL isOSDClearLayer4(UCHAR ItemID)
{

    if(ucMenuType == OSD_MAIN_SYSTEM && ucSubMenuType == OSD_SYS_OSDSET && ItemID<2)//for Language/OSD Timer
        return TRUE;
    else if(ucMenuType == OSD_MAIN_PICTURE && ucSubMenuType == OSD_PICTURE_COLORTEMP && ItemID == 3)//for UserColor Menu
        return TRUE;
    else if(ucMenuType == OSD_MAIN_PICTURE_ADVANCED && ucSubMenuType == OSD_PICTURE_AD_PIC && ItemID == PICTURE_MODE_LOW_BL)//for LBL Menu
        return TRUE;
    else if(ucMenuType == OSD_MAIN_PICTURE_ADVANCED && ucSubMenuType == OSD_PICTURE_AD_PIC && ItemID == PICTURE_MODE_ANIMATION)//for LBL Menu
        return TRUE;    

}

UCHAR isOSDAllowDCR (void)
{
    if ( (UserData.ucBFMode == PICTURE_MODE_MOVIE)
#if ENABLE_PICTURE_MODE_GAME == ON
        ||(UserData.ucBFMode == PICTURE_MODE_GAME)
#endif        
        ||(UserData.ucBFMode == PICTURE_MODE_PHOTO)){
        return TRUE;
    } 
    else{
        return FALSE;
    }
}
UCHAR isOSDAllowSenseyeDemo (void)
{
    if ( (UserData.ucBFMode == PICTURE_MODE_MOVIE)
#if ENABLE_PICTURE_MODE_GAME == ON
        ||(UserData.ucBFMode == PICTURE_MODE_GAME)
#endif
#if	ENABLE_CAD_MODE == ON
        ||(UserData.ucBFMode==PICTURE_MODE_CAD)
#endif        
#if	ENABLE_ANIMATION_MODE == ON
        ||(UserData.ucBFMode==PICTURE_MODE_ANIMATION)
#endif        
#if ENABLE_PICTURE_MODE_MBOOK == ON     
        ||(UserData.ucBFMode==PICTURE_MODE_MBOOK)
#endif
        ||(UserData.ucBFMode == PICTURE_MODE_PHOTO)){
        return TRUE;
    } 
    else{
        return FALSE;
    }
}

#if ENABLE_EYE_PROTECT == ON
BOOL isOSDAllowEyeProtect (void)
{
    if (UserData.ucBFMode == PICTURE_MODE_STANDARD){
        return TRUE;
    } 
    else{
        return FALSE;
    }
}

BOOL isOSDAllowEyeProtectMeter (void)
{
    if ((UserData.bEyeProtect == TRUE)
        && isOSDAllowEyeProtect()){
        return TRUE;
    } 
    else{
        return FALSE;
    }
}
#endif
#if ENABLE_ECO_SENSOR == ON
BOOL isOSDAllowECOSensor (void)
{
    if (UserData.bOSDRotation == FALSE){
        return TRUE;
    } 
    else{
        return FALSE;
    }
}

BOOL isOSDAllowECOMeterRange (void)
{
    if ((UserData.bECOSensor == TRUE)
        && isOSDAllowECOSensor()){
        return TRUE;
    } 
    else{
        return FALSE;
    }
}
#endif
BOOL IsDVIDPInPut(void)
{
   if(UserData.ucInputSource == INPUT_SC_DP||UserData.ucInputSource == INPUT_SC_DP2\
      || UserData.ucInputSource == INPUT_SC_DVI || UserData.ucInputSource == INPUT_SC_DVI1){
        return TRUE;   
   }
   return FALSE;
}

BOOL isOSDAllowResNotice(void)
{
    if((!IsNativeTiming())&&(IsShowResolutionNotice())&&(IsDVIDPInPut()||(!IsHDMIVideoTiming()))){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

BOOL isOSDCusKeyBriConDisable(void)
{
    if((UserData.ucBFMode == PICTURE_MODE_ECO) || ((UserData.ucDynamicContrast != 0)&&isOSDAllowDCR()))
        return TRUE;
    else
        return FALSE;
}

BOOL isOSDRotationAvailable(void)
{
    USHRT temp = GetOSDState();

    if(temp == OSD_INFO_SENSEYE_DEMO_STATE && UserData.bSensEyeDemo == TRUE){
        return FALSE;
    }
    if(temp == OSD_DIRSRC_STATE){
        return FALSE;
    }

    return TRUE;
}

BOOL isOSDMainIconAvailable(UCHAR MainIconID)
{
    if(MainIconID == MainIcon_ECO){
        if(UserData.bOSDRotation == TRUE){
            return FALSE;
        }
    }

    return TRUE;
}
