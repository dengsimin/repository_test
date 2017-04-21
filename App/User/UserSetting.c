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
#include "ScalerProfile.h"

//******************************************************************************
// G L O B A L   D E F I N I T I O N S
//******************************************************************************
#define CheckMaxRange(a,b) {if (a > b) a = b;}

#define PHASE_SCOPE   (MAXIMUM_PHASE-MINIMUM_PHASE)
#define CLOCK_SCOPE   (InputTiming.usHTotalMax-InputTiming.usHTotalMin)
#define HPOSN_SCOPE   (InputTiming.usHStartMax-InputTiming.usHStartMin)
#define VPOSN_SCOPE   (InputTiming.usVStartMax-InputTiming.usVStartMin)
xdata UCHAR bOSDAdjust =FALSE;  

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************
static code tINPUTPORT ucInputPortTable[] = {
    //ucInputPort,            ucPortName;
#if (MODEL_INPUT_VGA0 != INPUT_SC_NULL)    //x
    ANALOG_SEP_INPUT0,    MODEL_INPUT_VGA0,
#endif
#if (MODEL_INPUT_VGA1 != INPUT_SC_NULL)     //x
    ANALOG_SEP_INPUT1,    MODEL_INPUT_VGA1,
#endif
#if (MODEL_INPUT_DIG0 != INPUT_SC_NULL)    //x
    DIGITAL_INPUT0,       MODEL_INPUT_DIG0,
#endif
#if (MODEL_INPUT_DIG1 != INPUT_SC_NULL)    //INPUT_SC_DVI 2
    DIGITAL_INPUT1,       MODEL_INPUT_DIG1,
#endif
#if (MODEL_INPUT_DIG2 != INPUT_SC_NULL)    //INPUT_SC_DP  11
    DISPLAY_PORT_INPUT,   MODEL_INPUT_DIG2,
#endif
#ifdef MODEL_INPUT_DIG3
#if (MODEL_INPUT_DIG3 != INPUT_SC_NULL)    //x
    DISPLAY_PORT_INPUT1,   MODEL_INPUT_DIG3,
#endif
#endif
#ifdef MODEL_INPUT_DIG4
#if (MODEL_INPUT_DIG4 != INPUT_SC_NULL)    
    DISPLAY_PORT_INPUT2,   MODEL_INPUT_DIG4,
#endif
#endif
#ifdef MODEL_INPUT_DIG5
#if (MODEL_INPUT_DIG5 != INPUT_SC_NULL)    
    DISPLAY_PORT_INPUT3,   MODEL_INPUT_DIG5,
#endif
#endif
#ifdef MODEL_INPUT_DIG6
#if (MODEL_INPUT_DIG6 != INPUT_SC_NULL)    
    DIGITAL_INPUT2,   MODEL_INPUT_DIG6,
#endif
#endif
#ifdef MODEL_INPUT_DIG7
#if (MODEL_INPUT_DIG7 != INPUT_SC_NULL)    //INPUT_SC_HDMI 4
    DIGITAL_INPUT3,   MODEL_INPUT_DIG7,
#endif
#endif

#if (MODEL_INPUT_YPbPr0 != INPUT_SC_NULL)    
    ANALOG_YPBPR_INPUT0,  MODEL_INPUT_YPbPr0,
#endif
#if (MODEL_INPUT_YPbPr1 != INPUT_SC_NULL)    
    ANALOG_YPBPR_INPUT1,  MODEL_INPUT_YPbPr1,
#endif
};
#if OSDTYPE == OSD_BENQ_V2
static code UCHAR Langtab[]={
#if LANG01 != OSDLANG_NONE
    LANG01,
#endif 
#if LANG02 != OSDLANG_NONE
    LANG02,
#endif 
#if LANG03 != OSDLANG_NONE
    LANG03,
#endif   
#if LANG04 != OSDLANG_NONE
    LANG04,
#endif  
#if LANG05 != OSDLANG_NONE
    LANG05,
#endif    
#if LANG06 != OSDLANG_NONE
    LANG06,
#endif
#if LANG07 != OSDLANG_NONE
    LANG07,
#endif   
#if LANG08 != OSDLANG_NONE
    LANG08,
#endif
#if LANG09 != OSDLANG_NONE
    LANG09,
#endif 
#if LANG10 != OSDLANG_NONE
    LANG10,
#endif
#if LANG11 != OSDLANG_NONE
    LANG11,
#endif   
#if LANG12 != OSDLANG_NONE
    LANG12,
#endif
#if LANG13 != OSDLANG_NONE
    LANG13,
#endif 
#if LANG14 != OSDLANG_NONE
    LANG14,
#endif
#if LANG15 != OSDLANG_NONE
    LANG15,
#endif
#if LANG16 != OSDLANG_NONE
    LANG16,
#endif   
#if LANG17 != OSDLANG_NONE
    LANG17,
#endif    
#if LANG18 != OSDLANG_NONE
    LANG18,
#endif    
#if LANG19 != OSDLANG_NONE
    LANG19,
#endif   
#if LANG20 != OSDLANG_NONE
    LANG20,
#endif
    OSDLANG_NONE
};
#endif

//******************************************************************************
// Prototype: 
//  UCHAR GetPortTabIntertface(UCHAR PortName)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
UCHAR GetPortTabIntertface(UCHAR PortName)
{
    UCHAR i;
    for (i = 0; i < (sizeof(ucInputPortTable) / sizeof(tINPUTPORT)); i++) {
       if (ucInputPortTable[i].ucPortName == PortName) {
          return ucInputPortTable[i].ucInputPort;
       }
    }
    
    UserData.ucInputSource = ucInputPortTable[0].ucPortName;
    return ucInputPortTable[0].ucInputPort;
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
void UserSetBrightness(void)
{
    CheckMaxRange(UserData.ucBrightness,MAXIMUM_BRIGHTNESS);
    SetCLRTMP_BriCon();
    SetBrightness(GetBrightness1023());
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
void UserSetContrast(void)
{
#if 0 // 0 lrd add 
    CheckMaxRange(UserData.ucContrast,MAXIMUM_CONTRAST);
    MTXAPI_SetContrast(GetContrast255());
#else
    SetCLRTMP_BriCon();
    CheckMaxRange(UserData.ucContrast,MAXIMUM_CONTRAST);
    if(UserData.ucBFMode == PICTURE_MODE_ECO){
        UserData.ucContrast = 50;
    }

    
    MTXAPI_SetContrastValue(GetContrast255());
    MTXAPI_SelMatrix(MTX_LOCAL);
    SetLocalMatrix();

    MTXAPI_SelMatrix(MTX_GLOBAL);  
    MTXAPI_SetContrast(GetContrast255());

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
void UserSetPhase(void)
{
    CheckMaxRange(InputTiming.ucPhase,MAXIMUM_PHASE);
    SetADCPhase(InputTiming.ucPhase);
#if ENABLE_ESD_PROTECT == ON
    ReadESDCheckSum();
#endif
}

//******************************************************************************
// Prototype: 
//  void UserSetPhase100(UCHAR value)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
void UserSetPhase100(UCHAR value)
{
    if (value > 100) value = 100;
    InputTiming.ucPhase = (USHRT)value*MAXIMUM_PHASE/100;
    UserSetPhase();    
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
void UserSetClock(void)
{
    //CheckMaxRange(InputTiming.usHTotal,InputTiming.usHTotalMax);
    SetADCPLL2(InputTiming.usHTotal);
#if ENABLE_ESD_PROTECT == ON
    ReadESDCheckSum();
#endif
}

//******************************************************************************
// Prototype: 
//  void UserSetClock100(UCHAR value)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
void UserSetClock100(UCHAR value)
{
    if (value > 100) value = 100;
    InputTiming.usHTotal = (USHRT)value*CLOCK_SCOPE/100+InputTiming.usHTotalMin;
    UserSetClock();
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
void UserSetHPosition(void)
{
    //CheckMaxRange(InputTiming.usHStart,InputTiming.usHStartMax);
    SetHP(InputTiming.usHStart);
}

//******************************************************************************
// Prototype: 
//  void UserSetHPosn100(UCHAR value)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
void UserSetHPosn100(UCHAR value)
{
    if (value > 100) value = 100;
    value = 100-value;
    InputTiming.usHStart = (USHRT)value*HPOSN_SCOPE/100+InputTiming.usHStartMin;
    UserSetHPosition();    
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
void UserSetVPosition(void)
{
    bOSDAdjust = TRUE;      
    //CheckMaxRange(InputTiming.usVStart,InputTiming.usVStartMax);
    SetVP(InputTiming.usVStart);
}

//******************************************************************************
// Prototype: 
//  void UserSetVPosn100(UCHAR value)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
void UserSetVPosn100(UCHAR value)
{
    if (value > 100) value = 100;
    InputTiming.usVStart = (USHRT)value*VPOSN_SCOPE/100+InputTiming.usVStartMin;
    UserSetVPosition();    
}

//******************************************************************************
// Prototype: 
//  void UserSetADCGainOffset(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Set ADC gain/offset
// Notes:
//  None
//******************************************************************************
void UserSetADCGainOffset(void)
{
    SetADCRGain(CalibData.ucADCRGain);
    SetADCGGain(CalibData.ucADCGGain);
    SetADCBGain(CalibData.ucADCBGain);
    SetADCROffset(CalibData.ucADCROffset);
    SetADCGOffset(CalibData.ucADCGOffset);
    SetADCBOffset(CalibData.ucADCBOffset);
}



//******************************************************************************
// Prototype: 
//  void UserSetColorTemp(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
#if OSDTYPE == OSD_BENQ_V2
void UserSetColorTemp(void)
{
    if(Custom_System.bDualviewAdjust == FALSE){
     CheckMaxRange(UserData.ucColorTemp,MAXIMUM_CLR_TEMP);
     switch(UserData.ucBFMode){
         case PICTURE_MODE_STANDARD:
             UserData.ucColorTemp_Standard = UserData.ucColorTemp;break;
#if	ENABLE_PICTURE_MODE_REC709== ON            
         case PICTURE_MODE_REC709:
             UserData.ucColorTemp_Rec709 = UserData.ucColorTemp;break;
#endif            
         case PICTURE_MODE_SRGB:
             UserData.ucColorTemp_sRGB = UserData.ucColorTemp;break;
#if	ENABLE_PICTURE_MODE_CAD == ON
         case PICTURE_MODE_CAD:
             UserData.ucColorTemp_CAD = UserData.ucColorTemp;break;
#endif        
#if	ENABLE_PICTURE_MODE_ANIMATION == ON
         case PICTURE_MODE_ANIMATION:
             UserData.ucColorTemp_Animation = UserData.ucColorTemp;break;
#endif
#if	ENABLE_PRESENTATION_MODE == ON
         case PICTURE_MODE_PRESENTATION:
             UserData.ucColorTemp_Presentation = UserData.ucColorTemp;break;
#endif        
         case PICTURE_MODE_LOW_BL:
             switch(UserData.ucLBLMode){
                 case MULTIMEDIA:
                     UserData.ucColorTemp_LBL_Mult = UserData.ucColorTemp;break;
                 case WEB_SURFING:
                     UserData.ucColorTemp_LBL_Web = UserData.ucColorTemp;break;
                 case OFFICE:
                     UserData.ucColorTemp_LBL_Office = UserData.ucColorTemp;break;
                 case READING:
                     UserData.ucColorTemp_LBL_Read = UserData.ucColorTemp;break;
                 default:break;
             }
             break;
#if ENABLE_PICTURE_MODE_MOVIE == ON           
         case PICTURE_MODE_MOVIE:
             UserData.ucColorTemp_Movie = UserData.ucColorTemp;break;            
#endif    
#if ENABLE_PICTURE_MODE_GAME == ON    
         case PICTURE_MODE_GAME:
             UserData.ucColorTemp_Game = UserData.ucColorTemp;break;            
#endif    
#if ENABLE_PICTURE_MODE_PHOTO== ON       
         case PICTURE_MODE_PHOTO:
             UserData.ucColorTemp_Photo = UserData.ucColorTemp;break;            
#endif    
#if	ENABLE_PICTURE_MODE_DARKROOM == ON
         case PICTURE_MODE_DARKROOM:
             UserData.ucColorTemp_DarkRoom = UserData.ucColorTemp;break;            
#endif        
         case PICTURE_MODE_ECO:
             UserData.ucColorTemp_Standard = UserData.ucColorTemp;break; 
#if ENABLE_PICTURE_MODE_MBOOK == ON
         case PICTURE_MODE_MBOOK:
             UserData.ucColorTemp_MBOOK = UserData.ucColorTemp;break; 
#endif
         case PICTURE_MODE_USER:
             UserData.ucColorTemp_USER = UserData.ucColorTemp;break; 
             
         default:break;            
     }
    }
     #if ENABLE_PICTURE_DUAL_MODE == ON
     if(UserData.bSensEyeDemo == PICTURE_DUALMODE_ON){
         if(Custom_System.bDualviewAdjust == FALSE){
             MTXAPI_SelMatrix(MTX_LOCAL);
             SetLocalMatrix();
         }
         else{
             MTXAPI_EnableLocalMatrix(TRUE);  
         }
     }
     #endif
     SetColorTemperature(UserData.ucColorTemp);

}
//******************************************************************************
// Prototype: 
//  void UserSetOD(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
void UserSetOD(void)
{
#if ENABLE_OD == ON
#if 0//ENABLE_FREESYNC_FUNC == ON // lrd_dis_benq
   if (IsFreesync() == TRUE){
       SetODMode(OD_EXTREME+1);
   }
   else
#endif
    {
    switch(UserData.ucBFMode){
        case PICTURE_MODE_STANDARD:
            UserData.ucODMode_Standard= UserData.ucODMode;break;
#if	ENABLE_PICTURE_MODE_REC709== ON            
        case PICTURE_MODE_REC709:
            UserData.ucODMode_Rec709= UserData.ucODMode;break;
#endif            
        case PICTURE_MODE_SRGB:
            UserData.ucODMode_sRGB = UserData.ucODMode;break;
#if	ENABLE_PICTURE_MODE_CAD == ON
        case PICTURE_MODE_CAD:
            UserData.ucODMode_CAD = UserData.ucODMode;break;
#endif        
#if	ENABLE_PICTURE_MODE_ANIMATION == ON
        case PICTURE_MODE_ANIMATION:
            UserData.ucODMode_Animation = UserData.ucODMode;break;
#endif
#if	ENABLE_PRESENTATION_MODE == ON
        case PICTURE_MODE_PRESENTATION:
            UserData.ucODMode_Presentation = UserData.ucODMode;break;
#endif        
        case PICTURE_MODE_LOW_BL:
            switch(UserData.ucLBLMode){
                case MULTIMEDIA:
                    UserData.ucODMode_LBL_Mult = UserData.ucODMode;break;
                case WEB_SURFING:
                    UserData.ucODMode_LBL_Web = UserData.ucODMode;break;
                case OFFICE:
                    UserData.ucODMode_LBL_Office = UserData.ucODMode;break;
                case READING:
                    UserData.ucODMode_LBL_Read = UserData.ucODMode;break;
                default:break;
         }
         break;
#if ENABLE_PICTURE_MODE_MOVIE == ON           
        case PICTURE_MODE_MOVIE:
            UserData.ucODMode_Movie = UserData.ucODMode;break;            
#endif    
#if ENABLE_PICTURE_MODE_GAME == ON    
        case PICTURE_MODE_GAME:
            UserData.ucODMode_Game = UserData.ucODMode;break;            
#endif    
#if ENABLE_PICTURE_MODE_PHOTO== ON       
        case PICTURE_MODE_PHOTO:
            UserData.ucODMode_Photo = UserData.ucODMode;break;            
#endif    
#if	ENABLE_PICTURE_MODE_DARKROOM == ON
        case PICTURE_MODE_DARKROOM:
            UserData.ucODMode_DarkRoom = UserData.ucODMode;break;            
#endif        
        case PICTURE_MODE_ECO:
            UserData.ucODMode_Standard = UserData.ucODMode;break; 
#if ENABLE_PICTURE_MODE_MBOOK == ON
        case PICTURE_MODE_MBOOK:
            UserData.ucODMode_MBOOK = UserData.ucODMode;break; 
#endif
        case PICTURE_MODE_USER:
            UserData.ucODMode_USER = UserData.ucODMode;break; 
         
        default:break;            
    }
    if (UserData.ucODMode != OD_OFF) {
        
        SetODMode(UserData.ucODMode);
    }
    else {
        ODAPI_DisableOD();
    }
    }   
#endif
}

#else
void UserSetColorTemp(void)
{
     CheckMaxRange(UserData.ucColorTemp,MAXIMUM_CLR_TEMP);

    if(UserData.ucBFMode == PICTURE_MODE_STANDARD){
        UserData.ucColorTemp_Standard = UserData.ucColorTemp;
        SetColorTemperature(UserData.ucColorTemp);
    }
    else if(UserData.ucBFMode == PICTURE_MODE_USER){
        UserData.ucColorTemp_USER = UserData.ucColorTemp;
        SetColorTemperature(UserData.ucColorTemp);
    }
    
    if(UserData.ucBFMode == PICTURE_MODE_ECO
#if ENABLE_PICTURE_MODE_MOVIE == ON        
        || UserData.ucBFMode == PICTURE_MODE_MOVIE
#endif        
#if ENABLE_PICTURE_MODE_ANIMATION == ON
        || UserData.ucBFMode == PICTURE_MODE_ANIMATION
#endif
#if ENABLE_PICTURE_MODE_MBOOK == ON
        || UserData.ucBFMode == PICTURE_MODE_MBOOK
#endif        
        ){
        SetColorTemperature(CLRTMP_6500K);
    }
    else if(UserData.ucBFMode == PICTURE_MODE_SRGB){
        SetColorTemperature(CLRTMP_sRGB);
    }
    else if(FALSE
#if ENABLE_PICTURE_MODE_PHOTO == ON        
        ||UserData.ucBFMode == PICTURE_MODE_PHOTO
#endif  
#if ENABLE_PICTURE_MODE_GAME == ON
        || UserData.ucBFMode == PICTURE_MODE_GAME
#endif      
        ){
        SetColorTemperature(CLRTMP_9300K);
    }
    else if(FALSE
#if ENABLE_PICTURE_MODE_CAD == ON
        || UserData.ucBFMode == PICTURE_MODE_CAD 
#endif
#if ENABLE_PRESENTATION_MODE == ON
        || UserData.ucBFMode == PICTURE_MODE_PRESENTATION
#endif        
        ){
        SetColorTemperature(CLRTMP_5800K);
    }

    //v31_1106221_2200_SYS#1 end
}
//******************************************************************************
// Prototype: 
//  void UserSetOD(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
void UserSetOD(void)
{
#if ENABLE_OD == ON
#if ENABLE_FREESYNC_FUNC == ON
   if (IsFreesync() == TRUE){
       SetODMode(OD_EXTREME+1);
   }
   else
#endif
    {
    if (UserData.ucODMode != OD_OFF) {
        SetODMode(UserData.ucODMode);
    }
    else {
        ODAPI_DisableOD();
    }
    }   
#endif
}

#endif





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
void UserSetRGain(void)
{
    CheckMaxRange(UserData.ucUserRGain,MAXIMUM_USER_RGAIN);
    MTXAPI_SetRGain(GetRGain255()+1);
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
void UserSetGGain(void)
{
    CheckMaxRange(UserData.ucUserGGain,MAXIMUM_USER_GGAIN);
    MTXAPI_SetGGain(GetGGain255()+1);
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
void UserSetBGain(void)
{
    CheckMaxRange(UserData.ucUserBGain,MAXIMUM_USER_BGAIN);
    MTXAPI_SetBGain(GetBGain255()+1);
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
void UserSetROffset(void)
{
    CheckMaxRange(UserData.ucUserROffset,MAXIMUM_USER_ROFFSET);
    MTXAPI_SetROffset(GetROffset255());
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
void UserSetGOffset(void)
{
    CheckMaxRange(UserData.ucUserGOffset,MAXIMUM_USER_GOFFSET);
    MTXAPI_SetGOffset(GetGOffset255());
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
void UserSetBOffset(void)
{
    CheckMaxRange(UserData.ucUserBOffset,MAXIMUM_USER_BOFFSET);
    MTXAPI_SetBOffset(GetBOffset255());
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
void UserSetOSDH(void)
{
    CheckMaxRange(UserData.ucOSDX,MAXIMUM_OSD_HPOS);
    CheckMaxRange(UserData.ucOSDY,MAXIMUM_OSD_VPOS);
    OSDAPI_SetPosition(UserData.ucOSDX, UserData.ucOSDY);
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
void UserSetOSDV(void)
{
    bOSDAdjust = TRUE;
    UserSetOSDH();
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
void UserSetTransparent(void)
{
#if !lrd_dis
    OSDWindow id;
    CheckMaxRange(UserData.ucOSDTransparent,MAXIMUM_OSD_TRANS);
    OSDAPI_SetOSDFgBgTran(UserData.ucOSDTransparent);
    OSDAPI_SetOSDSpecialBgTran(0xFF);
    for (id = OSD_WINDOW1; id <= OSD_WINDOW8; id++) {
        OSDAPI_SelOSDWin(id);
        OSDAPI_SetOSDWinTran(UserData.ucOSDTransparent);
    }
#else
    {
          OSDWindow id;
        CheckMaxRange(UserData.ucOSDTransparent,MAXIMUM_OSD_TRANS);
        OSDAPI_SetOSDFgBgTran(UserData.ucOSDTransparent);
        OSDAPI_SetOSDSpecialBgTran(0xFF);
        for (id = OSD_WINDOW1; id <= OSD_WINDOW8; id++) {
            OSDAPI_SelOSDWin(id);

            {
                if(id == OSD_WINDOW5){
               OSDAPI_SetOSDWinTran(1);
                }
             else{
                OSDAPI_SetOSDWinTran(0);
            }
        }
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
void UserSetTimeout(void)
{
#if !lrd_dis
    OSDConfigTimeout((USHRT)UserData.ucOSDTimer*1000);
#else
    OSDConfigTimeout((USHRT)UserData.ucOSDTimer);
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
void UserSetOSDRotation(void)
{
    if (UserData.bOSDRotation) {
        OSDAPI_RotateOSDPosition(OSD_POS_ROT_270);
    }
    else {
        OSDAPI_RotateOSDPosition(OSD_POS_ROT_OFF);
    }

#if 0
    if (OSDAPI_IsOSDOn()) {
        OSDAPI_TurnOffOSD();
        OSDTurnOnOSD();
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
void UserSetLanguage(void)
{
    CheckMaxRange(UserData.ucLanguage,MAXIMUM_OSD_LANG);
#if ENABLE_HW_CEC == ON
    APPRequestCECAct(CECATN_SET_LANGUAGE);
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
void UserSetAudioMute(void)
{
    if (UserData.bAudioMute == TRUE) {
        AudioMuteOn();
    }
    else {
        AudioMuteOff();
    }
}

//******************************************************************************
// Prototype: 
//  void UserSetDCR(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
void UserSetDCR(void)
{
//fixed to windows 1 //nick20100817+
    // DCR need to full screen 
   // printf("UserSetDCR\r\n");
#if ENABLE_PICTURE_DUAL_MODE == ON
    if(Custom_System.bDualviewAdjust == TRUE){
        BFAPI_SetActiveWindow(BF_WINDOW_2);
    }else
#endif    
    {
        BFAPI_SetActiveWindow(BF_WINDOW_1);
    }
    SetDemo();
   // BFAPI_SetWindowSize(BF_WINDOW_FULLSCREEN);
#if ENABLE_DBC == ON
    if (UserData.ucBFMode != PICTURE_MODE_ECO) {
        UserData.bDBCMode = OFF;
        DisableDBCSmooth(TRUE); //v07_121030_1800_SYS#1
    }
#endif

    CheckMaxRange(UserData.ucDynamicContrast,MAXIMUM_DYNCONTRAST);
    if(isOSDAllowDCR()){
        if (( UserData.ucDynamicContrast > 0 )&&(UserData.bDBCMode == OFF)) {
            DisableDBC();
#if DCR_SMOOTH_PWM==ON        
            if ( OSDAPI_IsOSDOn() ) {
               DCR_BenQ_FroceSetBk();
            }
            if ( DCR_BenQ_Init() ) { 
                PerformDCR(1);
            }
            else {
                PerformDCR(0);
            }
#else
            PerformDCR(1);
#endif
        }
        else {
            DisableDCR();
        }
    }
    else {
        DisableDCR();
    }
        
//#endif
    
}


//******************************************************************************
// Prototype: 
//  void UserSetLD(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Set LD mode
// Notes:
//  None
//******************************************************************************
#if ENABLE_LD == ON
void UserSetLD(void)
{
//    SetLDMode(UserData.ucLDOnOff);
        SetLDMode(UserData.ucBFMode);
}
#endif

//******************************************************************************
// Prototype:
//  void UserSetAspectRatio(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
#if  ENABLE_OVERSCAN == OFF     //  lrd add 
void UserSetAspectRatio(void)
{
    SetDisplayMode(UserData.ucAspectRatio);

    // Resize BF window by current aspect ratio.
    BFAPI_SetActiveWindow(BF_WINDOW_2);
    BFAPI_SetWindowSize(BF_WINDOW_FULLSCREEN);
#if ENABLE_ESD_PROTECT == ON
    ReadESDCheckSum();
#endif
}
#else
void UserSetAspectRatio(void)
{
    UCHAR ucAspectRatio_tmp,ucAspectRatiobase;
    BOOL bBLcheck = FALSE;
    
    GetAspRatioSetting();
    CheckDataRange(UserData.ucAspectRatio,MAXIMUM_ASPECT_RATIO,MINIMUM_ASPECT_RATIO,UserDataDefault.ucAspectRatio);
    ucAspectRatiobase = UserData.ucAspectRatio;

#if !lrd_dis_benq
        if((UserData.ucAspectRatio > DSP_SIZE_43)&&((ULONG)pInputTiming->usModeVActive> PANEL_HEIGHT)){
#else
        if((UserData.ucAspectRatio > DSP_SIZE_43)&&((ULONG)InputTiming.usModeVActive> PANEL_HEIGHT)){
#endif
            UserData.ucAspectRatio = DSP_SIZE_FULL;
        }
        if((UserData.ucAspectRatio > DSP_SIZE_FULL)&&(APPIsOutOfLimit())){
            UserData.ucAspectRatio = DSP_SIZE_FULL;
        }

        switch (UserData.ucAspectRatio) {
            case DSP_SIZE_FULL:
                ucAspectRatio_tmp = ASP_RATIO_FULL;
                break;
        case DSP_SIZE_SMART:
            ucAspectRatio_tmp = ASP_RATIO_SCALE;
            break;
            case DSP_SIZE_43:
                ucAspectRatio_tmp = ASP_RATIO_4_3;
                break;
        /*
            case DSP_SIZE_SMART_43:
                if (DetectAspectRatio() != DSP_SIZE_FULL) {
                    ucAspectRatio_tmp = ASP_RATIO_4_3;
      }
      else {
                    ucAspectRatio_tmp = ASP_RATIO_FULL;
                }
                break;
        */
    #if 0//ENABLE_OVERSCAN == ON
        case DSP_OVERSCAN:
                ucAspectRatio_tmp = ASP_RATIO_FULL;
                break;
    #endif
            case DSP_SIZE_1By1:            
                ucAspectRatio_tmp = ASP_RATIO_REAL;
                break;
    }
    if (UserData.ucPIPMode == PIP_TYPE_PBP_SBS) {
                ucAspectRatio_tmp = ASP_RATIO_FULL;
       }
        
    if (IsBackLightOn()) {
        bBLcheck = TRUE;
        BacklightOff();
        }
    SetDisplayMode(ucAspectRatio_tmp); 
    #if !lrd_dis_benq
    if (GetScalerModeHandleState(_MainChannel) == WAIT_MODE_CHANGE)
    #endif
    {
        GraphicDisplayWindowDisable();
    }
#if ENABLE_OVERSCAN == ON  
        CheckOverScan();
#endif

#if !lrd_dis_benq
    pInputTiming = GetModeHandleInputTiming(_MainChannel);
#endif
    if (UserData.ucAspectRatio == DSP_SIZE_1By1) { //Avoid set display window again!
       // SetupDisplayTiming(pInputTiming->usHTotal50);
#if ENABLE_AUTOFRAMEDOWN == ON
        SC_PIP_FRC = 0x00;
#endif       
#if ENABLE_SR == ON
        SetSRInputTimingParameter();
#endif  
    }
    else{
#if ENABLE_AUTOFRAMEDOWN == ON
        if(GetAutoFrameDownRatio!=1) {
            SC_PIP_FRC |= BIT0;
        }
#endif        
#if !lrd_dis_benq
        SetupDisplayTiming(pInputTiming->usHTotal50);
#else
        SetupDisplayTiming(InputTiming.usHTotal50);
#endif
    }
    

    if (bBLcheck == TRUE) {
        Sleep(400);
    }
    /*
#else    
    SetDisplayMode(ucAspectRatio_tmp);
#endif   
*/
         SetDemo();
    
     if ((SC_FRC_CTRL&BIT0) != 0) {
         if ((SC_FRC_CENTER_MODE&BIT7)!=0) { //center mode
             SC_FRC_CTRL = 0x17; //for center mode
         }
         else {
            #if !lrd_dis_benq
             if (MDState[_MainChannel].InputTiming.usVSyncFreq > 620) {
            #else
            if (InputTiming.usVSyncFreq > 620) {            
            #endif
                 SC_FRC_CTRL = 0x33;
             }
             else {
                SC_FRC_CTRL = 0x13;
             }
         }
     }

#if ENABLE_OVERSCAN == ON
#if !lrd_dis_benq
    if (GetScalerModeHandleState(_MainChannel) == WAIT_MODE_CHANGE)
#endif
    {
        GraphicDisplayWindowEnable();
    }
#endif
Sleep(100);
if (bBLcheck) {
    BacklightOn();
}
 UserData.ucAspectRatio = ucAspectRatiobase;
}

#endif

//******************************************************************************
// Prototype:
//  void UserSetOverScan(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
#if ENABLE_OVERSCAN == ON
#if !lrd_dis
void UserSetOverScan(void)
{
    BacklightOff();
//    WaitDisVSync();
//    DisplayMuteImage();
//    WaitDisVSync();
    WaitDisVSync();
    GraphicDisplayWindowDisable();
    CheckOverScan();
    SetHmask();
    SetupDisplayTiming(InputTiming.usHTotal50);
    Sleep(80);
//    WaitDisVSync();
//    DisplayNormalImage();
    WaitDisVSync();
    GraphicDisplayWindowEnable();
    BacklightOn();
}
#endif
#endif

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
void UserSetGamma(void)
{
#if ENABLE_NVT_FGA == ON
    UCHAR colortemp;
    SetFGAGamma(GetGammaNum());
    //SetColorTemperature(UserData.ucColorTemp );
    colortemp = GetColorTempature();
    if((colortemp != CLRTMP_USER) && (UserData.ucBFMode != PICTURE_MODE_LOW_BL)){
        LoadColorTempByGamma(FGA_GetCTIndex(colortemp),GetGammaNum());  
    }
#else
    LoadGamma();
#endif
    if (UserData.bGammaOnOff == 1)
        GMAPI_EnableGamma();
    else
        GMAPI_DisableGamma();
}

//******************************************************************************
// Prototype: 
//  void UserSetOD(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
#if !lrd_dis
void UserSetOD(void)
{

#if ENABLE_OD == ON
    if (UserData.ucODMode == ON) {
        SetODMode(0);
    }
    else {
        ODAPI_DisableOD();
    }
#endif
}
#endif
//******************************************************************************
// Prototype: 
//  void UserSetVolume(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
void UserSetVolume(void)
{
    CheckMaxRange(UserData.ucVolume,MAXIMUM_VOLUME);
    SetVolume(Remap100To1023(UserData.ucVolume));
}


//******************************************************************************
// Prototype: 
//  void UserSetVolumeAndMute(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  v31_110614_1350_SYS#1
//******************************************************************************
void UserSetVolumeAndMute(void)
{
    if(UserData.bAudioMute){
        SetVolume(0);
    }
    else
    {
        UserSetVolume();
    }
    UserSetAudioMute();
}

//******************************************************************************
// Prototype: 
//  void UserRecallConfiguration(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
void UserRecallConfiguration(void)
{
    UCHAR tmp_AspectRatio;  
#if TPV_DP_VERSION_SELECT == ON
        BOOL tmp_DPVesion;
#endif
#if ENABLE_OVERSCAN == ON
    BOOL tmp_Overscan, tmp_SOGOverscan;
#endif

#if TPV_DP_VERSION_SELECT == ON
        tmp_DPVesion = UserData.bDPVersion;
#endif

#if ENABLE_OVERSCAN == ON
        tmp_Overscan = UserData.bOverScan;
        tmp_SOGOverscan = UserData.bSOGOverScan;
#endif

    UserData = UserDataDefault;
    UserSetBrightness();    
    UserSetContrast();
    UserSetGamma();
    UserSetColorTemp();
    UserSetOSDH();
    UserSetOSDV();
    UserSetTransparent();
    UserSetTimeout();
    UserSetOSDRotation();
  //UserSetVolume();
  //UserSetAudioMute();
    UserSetVolumeAndMute();//v31_110614_1350_SYS#1    
    UserSetDCR();  
    
    UserSetDDCCI();

  //UserSetOverScan();
    UserSetOD();  
    SetDemo();
    UserSetBF();
#if ENABLE_SR == ON
    UserSetSR();
#endif
#if ENABLE_3D_CNV == ON
    //UserSet2DTo3DMode();
    UserSet2DTo3DAdaptive();
    UserSet2DTo3DDepth();
    UserSet2DTo3DView();
    UserSet3DLRSwap();
    UserSet3DTo2D();
#endif    
#if ENABLE_ECO_SENSOR
    UserSetECO();
    UserSetECOMeter();
    UserSetECOSensorRange();
#endif
#if ENABLE_EYE_PROTECT
    UserSetEyeProtect();
    UserSetEyeProtectMeter();
#endif
    UserSetAudioChannel();

    NvramClearTiming(); //To avoid previous wrong Nvram data
    /* We disable writing timing info to nvram in recall to avoid wrong timing info writing to nvram again
    //Samuel-2010-02-09: When factory reset in DVI/HDMI, the timing information should not be written into nvram.
    if (GetInputSyncMode() != DIG_SYNC) { 
        NvramWriteTimingData(&InputTiming);
    }
    */
    
    SetColorSpace();
#if ENABLE_PIP == ON
        UserSetPictureMode();
        UserSetPIPConfig();
#else
        if ((tmp_AspectRatio != UserData.ucAspectRatio)
#if ENABLE_OVERSCAN == ON        
            ||(tmp_Overscan!= UserData.bOverScan)||(tmp_SOGOverscan!= UserData.bSOGOverScan)
#endif        
            )
        {
#if TPV_DP_VERSION_SELECT == ON
            if(tmp_DPVesion == UserData.bDPVersion || (UserData.ucInputSource != INPUT_SC_DP && UserData.ucInputSource != INPUT_SC_DP1 && UserData.ucInputSource != INPUT_SC_DP2))// avoid mute 2 times
#endif
            {
              UserSetAspectRatio();
            }
        }
#endif
    
    UserPerformAutoTune();

    if (GetProductModeFlag()) {   // DFM  : Recall need exit BurnIn and clear POT Timer  //v05_120608_1430_OSD#6
        ClrProductModeFlag();
        SystemData.ucPowerOnTimerM = 0x00;
        SystemData.usPowerOnTimerH = 0x00;
        SystemData.ucMonitorPowerOnTimerM = 0x00;
        SystemData.usMonitorPowerOnTimerH = 0x0000;        
        SystemData.usPOTimerH_FE2P = 0x00;
        SystemData.ucPOTimerM_FE2P = 0x00;
#if ENABLE_FE2P == ON
        EraseTimeScale();
#endif
        NvramWriteSystemData(&SystemData);
    }

    if (SystemData.bBurnIn == TRUE) {
        SystemData.bBurnIn = FALSE;
        NvramWriteSystemData(&SystemData);
    }
#if TPV_DP_VERSION_SELECT == ON
    if (tmp_DPVesion != UserData.bDPVersion) {
        SetDPSpeed(UserData.bDPVersion);
        SYSAPI_PerformHPDOff(HPD_FORCE_DP);
    }
#endif
}

//******************************************************************************
// Prototype: 
//  void UserRecallColor(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
void UserRecallColor(void)
{
    UserData.ucUserROffset = UserDataDefault.ucUserROffset;
    UserData.ucUserGOffset = UserDataDefault.ucUserGOffset;
    UserData.ucUserBOffset = UserDataDefault.ucUserBOffset;
    UserSetROffset();
    UserSetGOffset();
    UserSetBOffset();
    UserData.ucBrightness = UserDataDefault.ucBrightness;
    UserData.ucContrast = UserDataDefault.ucContrast;

    //UserSetContrast();
    UserData.ucUserRGain = UserDataDefault.ucUserRGain;
    UserData.ucUserGGain = UserDataDefault.ucUserGGain;
    UserData.ucUserBGain = UserDataDefault.ucUserBGain;
    UserData.ucColorTemp = UserDataDefault.ucColorTemp;
    UserData.ucBrightness_sRGB=UserDataDefault.ucBrightness_sRGB;    
    UserData.ucBrightness_Standard=UserDataDefault.ucBrightness_Standard;
    UserData.ucBrightness_LBL_Mult=UserDataDefault.ucBrightness_LBL_Mult;
    UserData.ucBrightness_LBL_Web=UserDataDefault.ucBrightness_LBL_Web;    
    UserData.ucBrightness_LBL_Office=UserDataDefault.ucBrightness_LBL_Office;
    UserData.ucBrightness_LBL_Read=UserDataDefault.ucBrightness_LBL_Read;
#if ENABLE_PICTURE_MODE_MOVIE == ON    
    UserData.ucBrightness_Movie=UserDataDefault.ucBrightness_Movie;
    UserData.ucContrast_Movie=UserDataDefault.ucContrast_Movie;
    UserData.ucSharpness_Movie=UserDataDefault.ucSharpness_Movie;
#endif
#if ENABLE_PICTURE_MODE_GAME == ON
    UserData.ucBrightness_Game=UserDataDefault.ucBrightness_Game;    
    UserData.ucContrast_Game=UserDataDefault.ucContrast_Game;   
    UserData.ucSharpness_Game=UserDataDefault.ucSharpness_Game;            
#endif
#if ENABLE_PICTURE_MODE_PHOTO == ON
    UserData.ucBrightness_Photo=UserDataDefault.ucBrightness_Photo;
    UserData.ucContrast_Photo=UserDataDefault.ucContrast_Photo;
    UserData.ucSharpness_Photo=UserDataDefault.ucSharpness_Photo;        
#endif
    UserData.ucBrightness_USER=UserDataDefault.ucBrightness_USER;
#if ENABLE_PICTURE_MODE_MBOOK== ON
    UserData.ucBrightness_MBOOK=UserDataDefault.ucBrightness_MBOOK;
    UserData.ucContrast_MBOOK=UserDataDefault.ucContrast_MBOOK;    
    UserData.ucSharpness_MBOOK=UserDataDefault.ucSharpness_MBOOK;    
#endif
#if	ENABLE_PICTURE_MODE_ANIMATION == ON      
    UserData.ucBrightness_Animation=UserDataDefault.ucBrightness_Animation;
    UserData.ucContrast_Animation=UserDataDefault.ucContrast_Animation;
    UserData.ucSharpness_Animation=UserDataDefault.ucSharpness_Animation;    
#endif
#if	ENABLE_PICTURE_MODE_CAD == ON
    UserData.ucBrightness_CAD=UserDataDefault.ucBrightness_CAD;
    UserData.ucContrast_CAD=UserDataDefault.ucContrast_CAD;
    UserData.ucSharpness_CAD=UserDataDefault.ucSharpness_CAD;    
#endif
#if	ENABLE_PRESENTATION_MODE == ON
    UserData.ucBrightness_Presentation=UserDataDefault.ucBrightness_Presentation;
    UserData.ucContrast_Presentation=UserDataDefault.ucContrast_Presentation;
    UserData.ucSharpness_Presentation=UserDataDefault.ucSharpness_Presentation;    
#endif
#if	ENABLE_PICTURE_MODE_REC709 == ON
    UserData.ucBrightness_Rec709=UserDataDefault.ucBrightness_Rec709;
    UserData.ucContrast_Rec709=UserDataDefault.ucContrast_Rec709;
    UserData.ucSharpness_Rec709=UserDataDefault.ucSharpness_Rec709;    
#endif
#if	ENABLE_PICTURE_MODE_DARKROOM == ON
    UserData.ucBrightness_DarkRoom=UserDataDefault.ucBrightness_DarkRoom;
    UserData.ucContrast_DarkRoom=UserDataDefault.ucContrast_DarkRoom;
    UserData.ucSharpness_DarkRoom=UserDataDefault.ucSharpness_DarkRoom;    
#endif
    UserData.ucContrast_sRGB=UserDataDefault.ucContrast_sRGB;
    UserData.ucContrast_Standard=UserDataDefault.ucContrast_Standard;
    UserData.ucContrast_LBL_Mult=UserDataDefault.ucContrast_LBL_Mult;
    UserData.ucContrast_LBL_Web=UserDataDefault.ucContrast_LBL_Web;    
    UserData.ucContrast_LBL_Office=UserDataDefault.ucContrast_LBL_Office;
    UserData.ucContrast_LBL_Read=UserDataDefault.ucContrast_LBL_Read;
    UserData.ucContrast_USER=UserDataDefault.ucContrast_USER;

    UserData.ucColorTemp_Standard=UserDataDefault.ucColorTemp_Standard;
    UserData.ucColorTemp_USER=UserDataDefault.ucColorTemp_USER;    
    UserData.ucBrightness = UserDataDefault.ucBrightness;
    UserData.ucContrast = UserDataDefault.ucContrast;        
    UserData.ucSharpness = UserDataDefault.ucSharpness;
    UserData.ucHue = UserDataDefault.ucHue;
    UserData.ucSaturation = UserDataDefault.ucSaturation;
    UserData.ucGammaNum = UserDataDefault.ucGammaNum;
    UserData.ucGammaNum_Standard= UserDataDefault.ucGammaNum_Standard;
    UserData.ucGammaNum_USER= UserDataDefault.ucGammaNum_USER;
    UserData.ucSharpness_sRGB=UserDataDefault.ucSharpness_sRGB;    
    UserData.ucSharpness_Standard=UserDataDefault.ucSharpness_Standard;
    UserData.ucSharpness_LBL_Mult=UserDataDefault.ucSharpness_LBL_Mult;
    UserData.ucSharpness_LBL_Web=UserDataDefault.ucSharpness_LBL_Web;    
    UserData.ucSharpness_LBL_Office=UserDataDefault.ucSharpness_LBL_Office;
    UserData.ucSharpness_LBL_Read=UserDataDefault.ucSharpness_LBL_Read;
    UserData.ucSharpness_USER=UserDataDefault.ucSharpness_USER;

    UserSetBF();
}


//******************************************************************************
// Prototype: 
//  void UserRecallHVPosition(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Rcall H/V position 
// Notes:
//  None
//******************************************************************************
void UserRecallHVPosition(void)
{
    InputTiming.usHTotal = InputTiming.usHTotal50;
    InputTiming.usHStart = InputTiming.usHStart50;
    InputTiming.usVStart = InputTiming.usVStart50;
    InputTiming.ucPhase = 32;
    SetADCPLL2(InputTiming.usHTotal);
    SetHP(InputTiming.usHStart);
    SetVP(InputTiming.usVStart);
    SetADCPhase(InputTiming.ucPhase);
#if ENABLE_ESD_PROTECT == ON
    ReadESDCheckSum();
#endif
}

//******************************************************************************
// Prototype: 
//  void UserPerformAutoTune(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
void UserPerformAutoTune(void)
{
    if (IsAutoTuneValid()) {
        InputTiming.ucAutoTune = AutoTune();
    #if ENABLE_ESD_PROTECT == ON
        ReadESDCheckSum();
    #endif
        if (InputTiming.ucAutoTune) {
            InputTiming.usHTotal = GetAngInputHTotal();
            InputTiming.usHStart = GetInputHStart();
            InputTiming.usVStart = GetInputVStart();
            InputTiming.ucPhase = GetAngInputPhase();
            InputTiming.usHTotal50 = InputTiming.usHTotal;
            InputTiming.usHStart50 = InputTiming.usHStart;
            InputTiming.usVStart50 = InputTiming.usVStart;
            SetMinMax();
        }
    }
}

//******************************************************************************
// Prototype: 
//  void UserSetBF(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
void UserSetBF(void)
{
    CheckMaxRange(UserData.ucBFMode,MAXIMUM_BF_MODE);
    SetThemeMode(UserData.ucBFMode);
    SetPictureMode(UserData.ucBFMode);//Brightness & contrast color temp   
#if ENABLE_ECO_EYE_SENSOR
    ECOEYESensorOnOff();
#endif
}

//******************************************************************************
// Prototype:
//  void UserSetSR(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Set SR mode
// Notes:
//  None
//******************************************************************************
#if ENABLE_SR == ON
void UserSetSR(void)
{
    SetSRMode(UserData.ucSRMode);
}
#endif

//******************************************************************************
// Prototype: 
//  void UserSet2DTo3DMode(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Set 2D to 3D mode
// Notes:
//  None
//******************************************************************************
#if ENABLE_3D_CNV == ON
void UserSet2DTo3DMode(void)
{
    CheckMaxRange(UserData.uc2DTo3DMode, MAXIMUM_2DTO3D_MODE);
    Set2DTo3DMode(UserData.uc2DTo3DMode);
}
#endif

//******************************************************************************
// Prototype: 
//  void UserSet2DTo3DAdaptive(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Enable 2D to 3D adpative mode
// Notes:
//  None
//******************************************************************************
#if ENABLE_3D_CNV == ON
void UserSet2DTo3DAdaptive(void)
{
    if (Is2DTo3DAdaptive()) {
        Set2DTo3DAdaptive(TRUE);
    }
    else {
        Set2DTo3DAdaptive(FALSE);
    }
}
#endif

//******************************************************************************
// Prototype: 
//  void UserSet2DTo3DDepth(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Set 2D to 3D mode
// Notes:
//  None
//******************************************************************************
#if ENABLE_3D_CNV == ON
void UserSet2DTo3DDepth(void)
{
    CheckMaxRange(UserData.uc2Dto3DDepth, MAXIMUM_2DTO3D_DEPTH);
    Set2DTo3DDepth(UserData.uc2Dto3DDepth);
}
#endif

//******************************************************************************
// Prototype: 
//  void UserSet2DTo3DView(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Set 2D to 3D mode
// Notes:
//  None
//******************************************************************************
#if ENABLE_3D_CNV == ON
void UserSet2DTo3DView(void)
{
    CheckMaxRange(UserData.uc2Dto3DView, MAXIMUM_2DTO3D_VIEW);
    Set2DTo3DView(UserData.uc2Dto3DView);
}
#endif

//******************************************************************************
// Prototype: 
//  void UserSet3DLRSwap(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Set 2D to 3D mode
// Notes:
//  None
//******************************************************************************
#if ENABLE_3D_CNV == ON
void UserSet3DLRSwap(void)
{
    if (Is3DLRSwap()) {
        Set3DLRSwap(TRUE);
    }
    else {
        Set3DLRSwap(FALSE);
    }
}
#endif

//******************************************************************************
// Prototype: 
//  void UserSet3DTo2D(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Set 3D to 2D mode
// Notes:
//  None
//******************************************************************************
#if ENABLE_FUNC_OSD == ON && ENABLE_3D_CNV == ON
void UserSet3DTo2D(void)
{
    if (Is3DTo2DEnabled()) {
        Set3DTo2DMode(TRUE);
    }
    else {
        Set3DTo2DMode(FALSE);
    }
}
#endif

//******************************************************************************
// Prototype: 
//  void UserSetInputSource(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
void UserSetInputSource(void)
{
#if IS_NT68810_SERIES || IS_NT68870_SERIES
#if ENABLE_SCALER_AUDIO == ON
    ScalerAudioPreMute();
#endif
#endif
#if (INPUT_INTERFACE&INPUT_MHL_MASK)
#if IS_NT68810_SERIES || IS_NT68870_SERIES
    MHLInit();
#else
    if (MHL_IsMHLPathEnable() ) {
        Force2Background(0, 0, 0); //Mute screen and display black pattern
        MHLClearHPD();
    }
#endif
#endif
    AudioMuteOn();
    //Sleep(100); // Wait mute taking effect!
    SetInputInterface(GetPortTabIntertface(UserData.ucInputSource));
}

//******************************************************************************
// Prototype: 
//  UCHAR UserGetInputSource(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
UCHAR UserGetInputSource(void)
{
    UCHAR i;
    UCHAR src = GetCurrInputInterface();
    UCHAR num = sizeof(ucInputPortTable)/sizeof(tINPUTPORT);

//	SC_ADC_CLAMP_CTRL = src;  // feng-160823
	
    for (i = 0; i < num; i++) {
        if ((src & PORT_MASK) == (ucInputPortTable[i].ucInputPort & PORT_MASK)) {
            break;
        }
    }
    
    if (i < num){
        return ucInputPortTable[i].ucPortName;
    }
    
    return INPUT_SC_VGA;
}

//******************************************************************************
// Prototype:
//  void GetAspRatioSetting(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
void GetAspRatioSetting(void)
{
   UCHAR InputSource_temp;
   InputSource_temp = UserGetInputSource();

    if ((InputSource_temp == INPUT_SC_DVI) || (InputSource_temp == INPUT_SC_VGA)|| (InputSource_temp == INPUT_SC_DP)|| (InputSource_temp == INPUT_SC_DP2)) {
        if ((DetectAspectRatio() == DSP_SIZE_FULL)&&(UserData.ucAspectRatio_VGADVIDP == DSP_SIZE_43)) {
            UserData.ucAspectRatio = DSP_SIZE_FULL;
        }
        else {
            UserData.ucAspectRatio = UserData.ucAspectRatio_VGADVIDP;
        }
        #if !lrd_dis_benq
        if ((MDState[_MainChannel].InputTiming.usModeVActive == PANEL_HEIGHT)&&(MDState[_MainChannel].InputTiming.usModeHActive == PANEL_WIDTH)) {
        #else
        if ((InputTiming.usModeVActive == PANEL_HEIGHT)&&(InputTiming.usModeHActive == PANEL_WIDTH)) {        
        #endif
            if ((UserData.ucAspectRatio == DSP_SIZE_1By1)) {
                UserData.ucAspectRatio = DSP_SIZE_FULL;
                UserData.ucAspectRatio_VGADVIDP = DSP_SIZE_1By1;
            }
            else if (DetectAspectRatio() != DSP_SIZE_FULL) {
                UserData.ucAspectRatio = DSP_SIZE_FULL ;
                UserData.ucAspectRatio_VGADVIDP = DSP_SIZE_FULL ;
            }
        }
    }
    else if ((InputSource_temp == INPUT_SC_HDMI) || (InputSource_temp == INPUT_SC_HDMI1) || (InputSource_temp == INPUT_SC_HDMI2) || 
        (InputSource_temp == INPUT_SC_HDMI3) || (InputSource_temp == INPUT_SC_HDMI4)) {
        if ((DetectAspectRatio() == DSP_SIZE_FULL)&&(UserData.ucAspectRatio_HDMI == DSP_SIZE_43)) {
            UserData.ucAspectRatio = DSP_SIZE_FULL;
        }
        else {
            UserData.ucAspectRatio = UserData.ucAspectRatio_HDMI;
        }
        #if !lrd_dis_benq
        if (MDState[_MainChannel].InputTiming.usModeHActive == PANEL_WIDTH && MDState[_MainChannel].InputTiming.usModeVActive == PANEL_HEIGHT){//140107_1000_SYS#2
        #else
        if (InputTiming.usModeHActive == PANEL_WIDTH && InputTiming.usModeVActive == PANEL_HEIGHT){//140107_1000_SYS#2
        #endif
            if ((UserData.ucAspectRatio == DSP_SIZE_1By1)) {
                UserData.ucAspectRatio = DSP_SIZE_FULL;
                UserData.ucAspectRatio_HDMI = DSP_SIZE_1By1;
            }
        }
    }
}


void SetAspRatioSetting(void)
{
    UCHAR InputSource_temp;
    InputSource_temp = UserGetInputSource();

    if ((InputSource_temp == INPUT_SC_DVI) || (InputSource_temp == INPUT_SC_VGA)|| (InputSource_temp == INPUT_SC_DP)|| (InputSource_temp == INPUT_SC_DP2)) {
        UserData.ucAspectRatio_VGADVIDP = UserData.ucAspectRatio;
    }
    else if ((InputSource_temp == INPUT_SC_HDMI) || (InputSource_temp == INPUT_SC_HDMI1) || (InputSource_temp == INPUT_SC_HDMI2) ||
        (InputSource_temp == INPUT_SC_HDMI3) || (InputSource_temp == INPUT_SC_HDMI4)) {
        UserData.ucAspectRatio_HDMI = UserData.ucAspectRatio;
    }
}

//******************************************************************************
// Prototype: 
//  void UserSetAudioChannel(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Set audio input/output channel
// Notes:
//  None
//******************************************************************************
#if 0
void UserSetAudioChannel(void)
{
#if ENABLE_SCALER_AUDIO == ON
#if AUDIO_OUT == IIS_OUT
    ScalerAudioSelect(AUDIO_HDMI_IIS);
#else
    #if AUDIO_LINE_IN == LINE_IN1
    switch(UserGetInputSource()) {
        case INPUT_SC_VGA:
            ScalerAudioSelect(AUDIO_LINEIN1_LINOUT);
            break;
        case INPUT_SC_DVI:
            ScalerAudioSelect(AUDIO_LINEIN1_LINOUT);//AUDIO_HDMI_LINOUT);  //  feng-160825
            break;
        case INPUT_SC_DVI1:
            ScalerAudioSelect(AUDIO_LINEIN1_LINOUT);//AUDIO_HDMI_LINOUT); //  feng-160825
            break;
        case INPUT_SC_HDMI:
            ScalerAudioSelect(AUDIO_HDMI_LINOUT);
            break;
        case INPUT_SC_HDMI1:
            ScalerAudioSelect(AUDIO_HDMI_LINOUT);
            break;
        case INPUT_SC_HDMI2:
            ScalerAudioSelect(AUDIO_HDMI_LINOUT);
            break;
        case INPUT_SC_HDMI3:
            ScalerAudioSelect(AUDIO_HDMI_LINOUT);
            break;
        case INPUT_SC_HDMI4:
            ScalerAudioSelect(AUDIO_HDMI_LINOUT);
            break;
        case INPUT_SC_YPbPr:
            ScalerAudioSelect(AUDIO_LINEIN1_LINOUT);
            break;
        case INPUT_SC_DP:
            ScalerAudioSelect(AUDIO_HDMI_LINOUT);
            break;
        case INPUT_SC_DP1:
            ScalerAudioSelect(AUDIO_HDMI_LINOUT);
            break;
        default:
            break;
    }
    #else
    switch(UserGetInputSource()) {
        case INPUT_SC_VGA:
            ScalerAudioSelect(AUDIO_LINEIN2_LINOUT);
            break;
        case INPUT_SC_DVI:
            ScalerAudioSelect(AUDIO_HDMI_LINOUT);
            break;
        case INPUT_SC_DVI1:
            ScalerAudioSelect(AUDIO_HDMI_LINOUT);
            break;
        case INPUT_SC_HDMI:
            ScalerAudioSelect(AUDIO_HDMI_LINOUT);
            break;
        case INPUT_SC_HDMI1:
            ScalerAudioSelect(AUDIO_HDMI_LINOUT);
            break;
        case INPUT_SC_HDMI2:
            ScalerAudioSelect(AUDIO_HDMI_LINOUT);
            break;
        case INPUT_SC_HDMI3:
            ScalerAudioSelect(AUDIO_HDMI_LINOUT);
            break;
        case INPUT_SC_HDMI4:
            ScalerAudioSelect(AUDIO_HDMI_LINOUT);
            break;
        case INPUT_SC_YPbPr:
            ScalerAudioSelect(AUDIO_LINEIN2_LINOUT);
            break;
        case INPUT_SC_DP:
            ScalerAudioSelect(AUDIO_HDMI_LINOUT);
            break;
        case INPUT_SC_DP1:
            ScalerAudioSelect(AUDIO_HDMI_LINOUT);
            break;
        default:
            break;
    }
    #endif
#endif
#endif
}
#else
void UserSetAudioChannel(void)
{
    UCHAR interface, ucAudio_Select; 
    
    interface = UserGetInputSource();

    if(UserData.ucInputSource == INPUT_SC_HDMI){
        ucAudio_Select = UserData.ucHDMIAudioSelect;
    }
    else if(UserData.ucInputSource == INPUT_SC_DP){
        ucAudio_Select = UserData.ucDPAudioSelect;
    }
    else{
        ucAudio_Select = UserData.ucAudioSelect;
    }

#if ENABLE_SCALER_AUDIO == ON
#if AUDIO_OUT == IIS_OUT
    ScalerAudioSelect(AUDIO_HDMI_IIS);
#else


    #if AUDIO_LINE_IN == LINE_IN1
        if (ucAudio_Select == AUDIOSRC_PC) {
        ScalerAudioSelect(AUDIO_LINEIN1_LINOUT);
    }
    else if(ucAudio_Select == AUDIOSRC_HDMI){
        ScalerAudioSelect(AUDIO_HDMI_LINOUT);                  
    }
    else if(ucAudio_Select == AUDIOSRC_DP){
        ScalerAudioSelect(AUDIO_HDMI_LINOUT);                  
    } 
    else {  //Auto
        switch(interface) {
            case INPUT_SC_VGA:
                ScalerAudioSelect(AUDIO_LINEIN1_LINOUT);
                break;
            case INPUT_SC_DVI:
                ScalerAudioSelect(AUDIO_LINEIN1_LINOUT);//AUDIO_HDMI_LINOUT);  //  feng-160825
                break;
            case INPUT_SC_DVI1:
                ScalerAudioSelect(AUDIO_LINEIN1_LINOUT);//AUDIO_HDMI_LINOUT); //  feng-160825
                break;
            case INPUT_SC_HDMI:
                ScalerAudioSelect(AUDIO_HDMI_LINOUT);
                break;
            case INPUT_SC_HDMI1:
                ScalerAudioSelect(AUDIO_HDMI_LINOUT);
                break;
            case INPUT_SC_HDMI2:
                ScalerAudioSelect(AUDIO_HDMI_LINOUT);
                break;
            case INPUT_SC_HDMI3:
                ScalerAudioSelect(AUDIO_HDMI_LINOUT);
                break;
            case INPUT_SC_HDMI4:
                ScalerAudioSelect(AUDIO_HDMI_LINOUT);
                break;
            case INPUT_SC_YPbPr:
                ScalerAudioSelect(AUDIO_LINEIN1_LINOUT);
                break;
            case INPUT_SC_DP:
                ScalerAudioSelect(AUDIO_HDMI_LINOUT);
                break;
            case INPUT_SC_DP1:
                ScalerAudioSelect(AUDIO_HDMI_LINOUT);
                break;
            default:
                break;
        }
    }
    #else
    if (ucAudio_Select == AUDIOSRC_PC) {
        ScalerAudioSelect(AUDIO_LINEIN2_LINOUT);
    }
    else if(ucAudio_Select == AUDIOSRC_HDMI){
        ScalerAudioSelect(AUDIO_HDMI_LINOUT);                  
    }
    else if(ucAudio_Select == AUDIOSRC_DP){
        ScalerAudioSelect(AUDIO_HDMI_LINOUT);                  
    } 
    else {  //Auto
    switch(UserGetInputSource()) {
        case INPUT_SC_VGA:
            ScalerAudioSelect(AUDIO_LINEIN2_LINOUT);
            break;
        case INPUT_SC_DVI:
            ScalerAudioSelect(AUDIO_LINEIN2_LINOUT);
            break;
        case INPUT_SC_DVI1:
            ScalerAudioSelect(AUDIO_LINEIN2_LINOUT);
            break;
        case INPUT_SC_HDMI:
            ScalerAudioSelect(AUDIO_HDMI_LINOUT);
            break;
        case INPUT_SC_HDMI1:
            ScalerAudioSelect(AUDIO_HDMI_LINOUT);
            break;
        case INPUT_SC_HDMI2:
            ScalerAudioSelect(AUDIO_HDMI_LINOUT);
            break;
        case INPUT_SC_HDMI3:
            ScalerAudioSelect(AUDIO_HDMI_LINOUT);
            break;
        case INPUT_SC_HDMI4:
            ScalerAudioSelect(AUDIO_HDMI_LINOUT);
            break;
        case INPUT_SC_YPbPr:
            ScalerAudioSelect(AUDIO_LINEIN2_LINOUT);
            break;
        case INPUT_SC_DP:
            ScalerAudioSelect(AUDIO_HDMI_LINOUT);
            break;
        case INPUT_SC_DP1:
            ScalerAudioSelect(AUDIO_HDMI_LINOUT);
            break;
        default:
            break;
        }
    }
    #endif
#endif
#endif
}


#endif
#if !lrd_dis
//******************************************************************************
// Prototype:
//  UCHAR UserGetNormalPhase(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
UCHAR UserGetNormalPhase(void)
{
    //UCHAR phase;
    //phase = (USHRT) InputTiming.ucPhase * 100 / MAXIMUM_PHASE;
    //return phase;
    return ucADCPhase100;
}
#endif
//******************************************************************************
// Prototype: 
//  UCHAR UserGetNormalClock(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
UCHAR UserGetNormalClock(void)
{
    UCHAR clock;
    clock = ((USHRT) InputTiming.usHTotal - InputTiming.usHTotalMin) * 100 / CLOCK_SCOPE;
    return clock;
}

//******************************************************************************
// Prototype: 
//  UCHAR UserGetNormalHPosn(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
UCHAR UserGetNormalHPosn(void)
{
    UCHAR pos;
    pos = ((USHRT) InputTiming.usHStart - InputTiming.usHStartMin) * 100 / HPOSN_SCOPE;
    pos = 100 - pos;
    return pos;
}

//******************************************************************************
// Prototype: 
//  UCHAR UserGetNormalVPosn(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
UCHAR UserGetNormalVPosn(void)
{
    //UCHAR pos;
    //pos = ((USHRT) InputTiming.usVStart - InputTiming.usVStartMin) * 100 / VPOSN_SCOPE;
    //return pos;
    return ucVstart100;
}

//******************************************************************************
// Prototype: 
//  UCHAR UserGetNormal2DTo3DDpth(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
#if MD_ENABLE_FUNC_OSD == ON
UCHAR UserGetNormal2DTo3DDpth(void)
{
    UCHAR tmp;
    tmp = (USHRT) UserData.uc2Dto3DDepth * 100 / MAXIMUM_2DTO3D_DEPTH;
    return tmp;
}
#endif

//******************************************************************************
// Prototype: 
//  UCHAR UserGetNormal2DTo3DView(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
#if MD_ENABLE_FUNC_OSD == ON
UCHAR UserGetNormal2DTo3DView(void)
{
    UCHAR tmp;
    tmp = (USHRT) UserData.uc2Dto3DView * 100 / MAXIMUM_2DTO3D_VIEW;
    return tmp;
}
#endif


//******************************************************************************
// Prototype: 
//  UCHAR GetInputPortName(UCHAR PortIdex)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
UCHAR GetInputPortName(UCHAR PortIdex)
{

#if 0 // 0 lrd add 
	UCHAR i,j;
	if (PortIdex >= (CheckTotalPortNum())) {
		return NUM_INPUT_SC;
	}
	for (j = 0;j < NUM_INPUT_SC; j++) {
		for (i = 0; i < (sizeof(ucInputPortTable) / sizeof(tINPUTPORT)); i++) {
			if (ucInputPortTable[i].ucPortName == INPUT_SC_NULL)
				continue;
			if (ucInputPortTable[i].ucPortName == j) {
				if (PortIdex-- == 0)
					return j;
			}
		}
	}

	return 0;
#else
	UCHAR i;
	i=0;

	for (i = 0; i < (sizeof(ucInputPortTable) / sizeof(tINPUTPORT)); i++) {
		if ((ucInputPortTable[i].ucPortName == INPUT_SC_NULL) || (i != PortIdex))
			continue;
		else
			return ucInputPortTable[i].ucPortName;
	}

	for(i = 0;i <(sizeof(ucInputPortTable) / sizeof(tINPUTPORT));i++)
	{
		if (ucInputPortTable[i].ucPortName != INPUT_SC_NULL)
		return ucInputPortTable[i].ucPortName;
	}

	return 0;

#endif
} 

//******************************************************************************
// Prototype: 
//  UCHAR GetInputPortIndex(UCHAR PortName)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
UCHAR GetInputPortIndex(UCHAR PortName)
{

#if 0 // 0 lrd add 
	UCHAR i,j,count=0;
	for (j = 0; j < NUM_INPUT_SC; j++) {
		for (i = 0; i < (sizeof(ucInputPortTable)/sizeof(tINPUTPORT)); i++) {
			if (ucInputPortTable[i].ucPortName == INPUT_SC_NULL) {
				continue;
			}
			if (ucInputPortTable[i].ucPortName == j) {
				if (j == PortName) {
					return count;
				}
				count++;
			}
		}
	}

	return 0;
#else
	UCHAR i,count;
	i = 0;
	count =0;
		for (i = 0; i < (sizeof(ucInputPortTable)/sizeof(tINPUTPORT)); i++) {
			if (ucInputPortTable[i].ucPortName == INPUT_SC_NULL) {
				continue;
			}
			if (ucInputPortTable[i].ucPortName == PortName) {
					return count;
			}			
			else
				count++;
		}
	return 0;
#endif
}

#if OSDTYPE == OSD_BENQ_V2
#if !lrd_dis_benq
//******************************************************************************
// Prototype:
// UCHAR LangPointToItem(UCHAR ucPoint)
// Parameters:
//  None
// Return:
// Purpose:
// Notes:
//  None
//******************************************************************************
UCHAR LangPointToItem(UCHAR ucPoint)
{
    UCHAR ucNumber = GetLangTotalNum();
    if (ucPoint == 0xff || (ucPoint >= ucNumber)) {
        return OSDLANG_NONE;
    }

    return Langtab[ucPoint];
}

//******************************************************************************
// Prototype:
// UCHAR LangItemToPoint(UCHAR ucLang)
// Parameters:
//  None
// Return:
// Purpose:
// Notes:
//  None
//******************************************************************************
UCHAR LangItemToPoint(UCHAR ucItem)
{
    UCHAR i,ucNumber = GetLangTotalNum();
    for (i=0;i<ucNumber;i++) {
        if (Langtab[i] == ucItem) {
            return i;
        }
    }

    return 0;
}
//******************************************************************************
// Prototype:
//UCHAR GetLangTotalNum(void)
// Parameters:
//  None
// Return:
// Purpose:
// Notes:
//  None
//******************************************************************************
UCHAR GetLangTotalNum(void)
{
    UCHAR ret = (sizeof(Langtab)/sizeof(Langtab[0]))-1;
    return ret;
}
#endif
#endif


#if ENABLE_PICTURE_DUAL_MODE == ON
UCHAR DualViewPointoBFMode(UCHAR DUALVIEW)
{
  UCHAR TBFMode;
  if(DUALVIEW == PICTURE_DUALMODE_ONOFF){
      DUALVIEW = Custom_System.ucDualViewTemp;
  }  
    switch(DUALVIEW){
    case PICTURE_DUALMODE_SRGB:
        TBFMode = PICTURE_MODE_SRGB;
        break;
#if	ENABLE_PICTURE_MODE_CAD == ON
    case PICTURE_DUALMODE_CAD:                     
        TBFMode = PICTURE_MODE_CAD;
        break;
#endif
#if	ENABLE_PICTURE_MODE_ANIMATION == ON
    case PICTURE_DUALMODE_Animation:                     
        TBFMode = PICTURE_MODE_ANIMATION;
        break;
#endif
    case PICTURE_DUALMODE_LBL:
        TBFMode = PICTURE_MODE_LOW_BL;
        break;
#if	ENABLE_PICTURE_MODE_DARKROOM == ON
    case PICTURE_DUALMODE_DARKROOM:
        TBFMode = PICTURE_MODE_DARKROOM;
        break;
#endif        
    case PICTURE_DUALMODE_USER:
        TBFMode = PICTURE_MODE_USER;
        break;
    default:
        TBFMode = PICTURE_MODE_SRGB;
        break;
    }
    return TBFMode;
}
void UserSetDualView(BOOL DUALMODEONOFF, UCHAR SETDUALVIEW)
{
    UCHAR tempBFMode;
    SetDemo();
    if(DUALMODEONOFF == PICTURE_DUALMODE_ON){
        Custom_System.bDualviewAdjust = TRUE;
        tempBFMode = DualViewPointoBFMode(SETDUALVIEW);
        CheckMaxRange(tempBFMode,MAXIMUM_BF_MODE);
        SetThemeMode(tempBFMode);
        SetPictureMode(tempBFMode);//Brightness & contrast color temp     
        Custom_System.bDualviewAdjust = FALSE;
    }
}
#endif

void UserGetSmartReminderTimer(void)
{
    switch (UserData.ucErgoTime) {
        case  ERGO_TIME_20MIN: Custom_System.usErgoTime = 200; 
        break;
        case  ERGO_TIME_40MIN: Custom_System.usErgoTime = 400; 
        break;
        case  ERGO_TIME_60MIN: Custom_System.usErgoTime = 600; 
        break;
        case  ERGO_TIME_80MIN: Custom_System.usErgoTime = 800; 
        break;
        case  ERGO_TIME_100MIN: Custom_System.usErgoTime = 1000; 
        break;
        default :
        break;
    }
    switch (UserData.ucErgoDuration) {
        case  ERGO_DURATION_5SEC: Custom_System.ucErgoDuration = 5; 
        break;
        case  ERGO_DURATION_10SEC: Custom_System.ucErgoDuration = 10; 
        break;
        case  ERGO_DURATION_15SEC: Custom_System.ucErgoDuration = 15; 
        break;
        case  ERGO_DURATION_20SEC: Custom_System.ucErgoDuration = 20; 
        break;
        case  ERGO_DURATION_25SEC: Custom_System.ucErgoDuration = 25; 
        break;
        default :
        break;        
    }
}
void UserSetAutoPowerOffTimer(void)
{
   float x;
   x= (float)100/115;
   
    switch (UserData.ucAutoPowerOffTime) {
        case  AUTO_POWER_OFF: 
            Custom_System.usAuto_poweroff_Time = 0; 
        break;
        case  AUTO_POWER_10MIN: 
            Custom_System.usAuto_poweroff_Time = (USHRT)(100*x); 
        break;
        case  AUTO_POWER_20MIN: 
            Custom_System.usAuto_poweroff_Time = (USHRT)(200*x); 
        break;
        case  AUTO_POWER_30MIN: 
            Custom_System.usAuto_poweroff_Time = (USHRT)(300*x); 
        break;
        default :
        break;        
    }
    Auto_Power_off_Timer = GetTimerTick();
}


//******************************************************************************
// Prototype: 
//  void UserSetSharpness(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
void UserSetSharpness(void)
{
#if ENABLE_SHARPNESS_FUNC == ON
#if !lrd_dis_benq
  UCHAR tmp = SC_CHANNEL_INDEX;
//  USHRT tmpSharpness;
  SelectChannelIndex(_MainChannel);
#endif
    CheckMaxRange(UserData.ucSharpness, MAXIMUM_SHARPNESS);
    SetCLRTMP_Sharpness();

//    if (UserData.ucSharpness == MAXIMUM_SHARPNESS) {
//        BFAPI_SetSharpness(0x0F);
//    }
    if (UserData.ucSharpness > 5) { //sharp
        BFAPI_SetSharpness((UserData.ucSharpness - 5) * 3);
    }
    else if (UserData.ucSharpness == 5) { //sharpness off
        BFAPI_SetSharpness(0);
    }
    else { //smooth
        BFAPI_SetSharpness(BIT7 | ((5 - UserData.ucSharpness) * 3));//Bit7 indicates smooth
    }
#if !lrd_dis_benq
    SC_CHANNEL_INDEX = tmp;
#endif
#endif
}

void UserSetColorReset(void)
{
        UserRecallColor();
        SetOSDUpdUsrFlag();
}


//******************************************************************************
// Prototype: 
// void UserSetDDCCI(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
void UserSetDDCCI(void)
{
    if (UserData.bDDCCI == ON) {
        McuEnableIIC(MCU_IIC_CON_DEFAULT);
    }
    else {
        McuDisableIIC(BIT0|BIT1|BIT2|BIT3|BIT4);
    }
}
void CurrentTimingSaved(void)
{
#if !lrd_dis_benq
    UserData.usCurrModeHactive = pInputTiming->usModeHActive;
    UserData.usCurrModeVactive = pInputTiming->usModeVActive;
    UserData.usCurrModeVsync = pInputTiming->usVSyncFreq;
    UserData.usCurrModeIndex = pInputTiming->usModeIndex;
#else
    UserData.usCurrModeHactive = InputTiming.usModeHActive;
    UserData.usCurrModeVactive = InputTiming.usModeVActive;
    UserData.usCurrModeVsync = InputTiming.usVSyncFreq;
    UserData.usCurrModeIndex = InputTiming.usModeIndex;
#endif
}

BOOL IsTimingChanged(void)
{
#if !lrd_dis_benq
    pInputTiming = GetModeHandleInputTiming(_MainChannel);
    if((pInputTiming->usModeHActive == UserData.usCurrModeHactive)
       &&(pInputTiming->usModeVActive == UserData.usCurrModeVactive)
       &&(pInputTiming->usVSyncFreq == UserData.usCurrModeVsync)
       &&(pInputTiming->usModeIndex == UserData.usCurrModeIndex)) {
    
       return FALSE;
    }
#else
	if((InputTiming.usModeHActive == UserData.usCurrModeHactive)
	   &&(InputTiming.usModeVActive == UserData.usCurrModeVactive)
	   &&(InputTiming.usVSyncFreq == UserData.usCurrModeVsync)
	   &&(InputTiming.usModeIndex == UserData.usCurrModeIndex)) { 
	   return FALSE;
	}
#endif
    return TRUE;    
}

BOOL IsShowResolutionNotice(void)
{

    if(IsComponentInput() == TRUE){//Input Component timing doesn't show Resnotice & non preset mode
        return FALSE;
    }
   #if OSDTYPE == OSD_BENQ_V1 || OSDTYPE == OSD_BENQ_V2
    if((UserData.bResNotice == ON)&& Custom_System.bIsTimingChanged == TRUE){
        Custom_System.bIsTimingChanged = FALSE;
        return TRUE;
    }
   #else
    if((UserData.bResNotice == ON)&&IsTimingChanged()){
        return TRUE;
    }
   #endif 
    return FALSE;
}
#if ENABLE_DBC == ON
//******************************************************************************
// Prototype: 
//  void UserSetDBC(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
void UserSetDBC(void)
{
    BFAPI_EnableWindow(BF_WINDOW_1);

    if (UserData.bDCRMode) {
        DisableDCR();
    }
    if (UserData.bDBCMode == ON) {
        EnableDBC();
    }
    else{    
        DisableDBC();        
        //DisableDBCSmooth(TRUE); //v07_121030_1800_SYS#1
    }

}
#endif


