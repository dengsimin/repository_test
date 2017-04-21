/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/
//For BENQ Service Menu
//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "Include.h"

//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************
typedef struct _LIGHTBAR_ {
    UCHAR x;
    UCHAR y;
    UCHAR len;
} LightBar ;

enum OSD_ServiceMenu {
    mHDMI_HPD,
    mDP_HPD,
#if ENABLE_SERVICEMENU_DVIHPD == ON    
    mDVI_HPD,
#endif    
    mLOGO,
    mAUTOPOWER,    
    mCABLE,    
};

/*
#define SetFactUpdFlag()    {ucUpdateFlag = 1;}
#define ClearFactUpdFlag()  {ucUpdateFlag = 0;}
*/
//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************
static code UCHAR ucSMTitleText[]={17,"BENQ Service Page"};
static code UCHAR ucSMSnText[]={4,"S/N:"};
static code UCHAR ucSMModelText[]={11,"Model name:"};
static code UCHAR ucSMVenderText[]={7,"Vender:"};
static code UCHAR ucSMPanelText[]={6,"Panel:"};
static code UCHAR ucSMScalerText[]={7,"Scaler:"};
static code UCHAR ucSMVersionText[]={12,"F/W Version:"};
static code UCHAR ucSMMOTText[]={16,"Monitor On Time:"};
static code UCHAR ucSMBOTText[]={18,"Backlight On Time:"};
static code UCHAR ucSMHdmiHPDText[]={8,"HDMI HPD"};
static code UCHAR ucSMDviHPDText[]={7,"DVI HPD"};
static code UCHAR ucSMDpHPDText[]={6,"DP HPD"};
static code UCHAR ucSMLogoText[]={4,"Logo"};
static code UCHAR ucSMAutoPowerText[]={9,"AutoPower"};
static code UCHAR ucSMCableText[]={12,"DVI/HDMI 10M"};
static code UCHAR ucSMInfoText[]={44,"(Enter the service mode:Power On       Menu)"};

static code UCHAR ucSMModel[]={sizeof(Model_TEXT)-1,Model_TEXT};
static code UCHAR ucSMVender[]={3,"TPV"};
static code UCHAR ucSMSn[]={4,"????"};
static code UCHAR ucSMPanel[]={sizeof(PANEL_NAME)-1,PANEL_NAME};
static code UCHAR ucSMScaler[]={sizeof(SCALER_TEXT)-1,SCALER_TEXT};
static code UCHAR ucSMVersion[]={15,'V',VERSION+'0',(REVERSION/10)+'0',(REVERSION%10)+'0',' ',DATE};

static code UCHAR ucOnText[]={2,"On"};
static code UCHAR ucOffText[]={3,"Off"};

code LightBar SMLBar[] = {
    {1, OSD_SM_HdmiHPD_Y,7},
    {1, OSD_SM_DpHPD_Y,7},
#if ENABLE_SERVICEMENU_DVIHPD == ON
    {1, OSD_SM_DviHPD_Y,7},//DVI HPD
#endif    
    {1, OSD_SM_Logo_Y,7},
    {1, OSD_SM_AutoPower_Y,7},
    {1, OSD_SM_Cable_Y,9},
};

xdata UCHAR ucServiceMenuIndex;
//******************************************************************************
// E X T E R N A L   V A R I A B L E   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// S T A T I C   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
static void ServiceMenuSelect(void);
static void ServiceMenuUnSelect(void);
static void ServiceMenuShowHdmiHPD(void);
static void ServiceMenuShowDpHPD(void);
static void ServiceMenuShowDviHPD(void);
static void ServiceMenuShowLogo(void);
static void ServiceMenuShowAutoPower(void);
static void ServiceMenuShowCable(void);

//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// Prototype:
//  UCHAR OSDFactoryUpdate(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Return flag for informing system to save caldata
// Notes:
//  None
//******************************************************************************

void GetSerialNumber(UCHAR * buf)
{
    UCHAR i;
    for (i=0;i<SystemData.SN_len;i++){    
            buf[i] = SystemData.ucSN[i];
    }
}
//******************************************************************************
// Prototype:
//  void OSDShowFactory(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Show Factory OSD
// Notes:
//  None
//******************************************************************************


void OSDShowServiceMenu(void)
{
    UCHAR buff[20];
#if !lrd_dis_benq
	UCHAR MonitorPowerOnTimerM, PowerOnTimerM;
#endif    
    OSDAPI_TurnOffOSD();    
    OSDLoadFont(Service_font);
    OSDInitFrame(OSD_SM_W,OSD_SM_H,SM_FRAME_COLOR);
    OSDAPI_SetPosition(50,50);
    // ----------------------------------------

    OSDAPI_SetIndentIndex(2);

    OSDAPI_SetAlignType(OSD_ALIGN_CENTER);
    buff[0]    =SystemData.SN_len;
    GetSerialNumber(&buff[1]);
    ShowIndentString(FALSE,  0, 1,25,ucSMTitleText);
    ShowIndentString(FALSE,  0, 31,27,ucSMInfoText);
    
    OSDAPI_SetAlignType(OSD_ALIGN_LEFT);

    ShowIndentString(FALSE,  1, OSD_SM_Model_Y,1,ucSMModelText);
    ShowIndentString(FALSE,  1, OSD_SM_Sn_Y,1,ucSMSnText);    
    ShowIndentString(FALSE,  1, OSD_SM_Vender_Y,1,ucSMVenderText);
    ShowIndentString(FALSE,  1, OSD_SM_Panel_Y,1,ucSMPanelText);
    ShowIndentString(FALSE,  1, OSD_SM_Scaler_Y,1,ucSMScalerText);
    ShowIndentString(FALSE,  1, OSD_SM_Version_Y,1,ucSMVersionText);
    ShowIndentString(FALSE,  1, OSD_SM_MOT_Y,1,ucSMMOTText);
    ShowIndentString(FALSE,  1, OSD_SM_BOT_Y,1,ucSMBOTText);
    ShowIndentString(FALSE,  1, OSD_SM_HdmiHPD_Y,1,ucSMHdmiHPDText);
    ShowIndentString(FALSE,  1, OSD_SM_DpHPD_Y,1,ucSMDpHPDText);
#if ENABLE_SERVICEMENU_DVIHPD == ON   
    ShowIndentString(FALSE,  1, OSD_SM_DviHPD_Y,1,ucSMDviHPDText);
#endif
    ShowIndentString(FALSE,  1, OSD_SM_Logo_Y,1,ucSMLogoText);
    ShowIndentString(FALSE,  1, OSD_SM_AutoPower_Y,1,ucSMAutoPowerText);
    ShowIndentString(FALSE,  1, OSD_SM_Cable_Y,1,ucSMCableText);

    ShowIndentString(FALSE,  13, OSD_SM_Model_Y,1,ucSMModel);
    ShowIndentString(FALSE,  13, OSD_SM_Sn_Y,SystemData.SN_len, buff);    
    ShowIndentString(FALSE,  13, OSD_SM_Vender_Y,1,ucSMVender);
    ShowIndentString(FALSE,  13, OSD_SM_Panel_Y,1,ucSMPanel);
    ShowIndentString(FALSE,  13, OSD_SM_Scaler_Y,1,ucSMScaler);
    ShowIndentString(FALSE,  13, OSD_SM_Version_Y,1,ucSMVersion);
    #if !lrd_dis_benq
    if(SystemData.ucMonitorPowerOnTimerM >=30){
       MonitorPowerOnTimerM = 30;
    }
    else{
        MonitorPowerOnTimerM = 0;
    }
    if(SystemData.ucPowerOnTimerM >=30){
        PowerOnTimerM = 30;
    }
    else{
        PowerOnTimerM = 0;
    }
    sprintf(buff,"n%05d Hr %02d Min",SystemData.usMonitorPowerOnTimerH,(USHRT)MonitorPowerOnTimerM);    
    buff[0] = 15;    
    ShowIndentString(FALSE,  13, OSD_SM_MOT_Y,1,buff);
    sprintf(buff,"n%05d Hr %02d Min",SystemData.usPowerOnTimerH,(USHRT)PowerOnTimerM);    
    buff[0] = 15;        
    ShowIndentString(FALSE,  13, OSD_SM_BOT_Y,1,buff);
    #else
    sprintf(buff,"n%05d Hr %02d Min",SystemData.usMonitorPowerOnTimerH,(USHRT)SystemData.ucMonitorPowerOnTimerM);    
    buff[0] = 15;    
    ShowIndentString(FALSE,  13, OSD_SM_MOT_Y,1,buff);
    sprintf(buff,"n%05d Hr %02d Min",SystemData.usPowerOnTimerH,(USHRT)SystemData.ucPowerOnTimerM);    
    buff[0] = 15;        
    ShowIndentString(FALSE,  13, OSD_SM_BOT_Y,1,buff);
    #endif
    
    OSDAPI_WriteXYChar(FALSE, 21, 31, 1);

    ServiceMenuShowHdmiHPD();
    ServiceMenuShowDpHPD();
#if ENABLE_SERVICEMENU_DVIHPD == ON       
    ServiceMenuShowDviHPD();
#endif
    ServiceMenuShowLogo();
    ServiceMenuShowAutoPower();
    ServiceMenuShowCable();    
    
    ucServiceMenuIndex = mHDMI_HPD;
    ServiceMenuSelect();
//=====================
 // OSDShowNum(20,OSD_SM_Cable_Y-2-2,(McuGetIOBit(DIGI1_CABLE_PORT, DIGI1_CABLE_BIT) == DIGI1_CABLE_ACTIVE)); //dvi
  
 // OSDShowNum(20,OSD_SM_Cable_Y-2,(McuGetIOBit(DP_CABLE_PORT, DP_CABLE_BIT) == DP_CABLE_ACTIVE)); //dp
 
 // OSDShowNum(20,OSD_SM_Cable_Y,(McuGetIOBit(DIGI3_CABLE_PORT, DIGI3_CABLE_BIT) == DIGI3_CABLE_ACTIVE));//hdmi
//====================
    OSDTurnOnOSD();
}

//******************************************************************************
// Prototype:
//  void OSDFactoryUp(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
void OSDServiceMenuUp(void)
{
    ServiceMenuUnSelect();
    if(--ucServiceMenuIndex > mCABLE)
        ucServiceMenuIndex = mCABLE;
    ServiceMenuSelect();

    
}

//******************************************************************************
// Prototype:
//  void OSDFactoryDown(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
void OSDServiceMenuDown(void)
{
    ServiceMenuUnSelect();
    if(++ucServiceMenuIndex > mCABLE)
        ucServiceMenuIndex = mHDMI_HPD;
    ServiceMenuSelect();
}

//******************************************************************************
// Prototype:
//  void OSDFactoryEnterItm(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  None
// Notes:
//  None
//******************************************************************************
void OSDServiceMenuAdjItm(void)
{
    switch(ucServiceMenuIndex)
    {
        case mHDMI_HPD:
    SystemData.bHDMI_HPD = ~SystemData.bHDMI_HPD;
    ServiceMenuShowHdmiHPD();
    break;
    case mDP_HPD:
    SystemData.bDP_HPD = ~SystemData.bDP_HPD;
    ServiceMenuShowDpHPD();
    break;
#if ENABLE_SERVICEMENU_DVIHPD == ON    
    case mDVI_HPD:
    SystemData.bDVI_HPD = ~SystemData.bDVI_HPD;
    ServiceMenuShowDviHPD();
    break;
#endif    
    case mLOGO:
    SystemData.bShowLogo = ~SystemData.bShowLogo;
    ServiceMenuShowLogo();
    break;
    case mAUTOPOWER:
    SystemData.bAutoPower = ~SystemData.bAutoPower;
    ServiceMenuShowAutoPower();
    break;
    case mCABLE:
    SystemData.bCable = ~SystemData.bCable;
    ServiceMenuShowCable();
    break;
    default:
    break;
    };
    SetOSDUpdSysFlag();
}

void ServiceMenuShowHdmiHPD(void)
{
    OSDAPI_SetIndentIndex(0xD5);
    OSDAPI_SetFontAttr(SM_ITEM_COLOR);
    if(SystemData.bHDMI_HPD)
    {
        ShowIndentString(TRUE,  13, OSD_SM_HdmiHPD_Y,1,ucOnText);
        OSDAPI_SetFontAttr(SM_FRAME_COLOR);
        ShowIndentString(TRUE,  17, OSD_SM_HdmiHPD_Y,1,ucOffText);
    }else{
        ShowIndentString(TRUE,  17, OSD_SM_HdmiHPD_Y,1,ucOffText);
        OSDAPI_SetFontAttr(SM_FRAME_COLOR);
        ShowIndentString(TRUE,  13, OSD_SM_HdmiHPD_Y,1,ucOnText);        
    }
}

void ServiceMenuShowDpHPD(void)
{
    OSDAPI_SetIndentIndex(0xDA);
    OSDAPI_SetFontAttr(SM_ITEM_COLOR);
    if(SystemData.bDP_HPD)
    {
        ShowIndentString(TRUE,  13, OSD_SM_DpHPD_Y,1,ucOnText);
        OSDAPI_SetFontAttr(SM_FRAME_COLOR);
        ShowIndentString(TRUE,  17, OSD_SM_DpHPD_Y,1,ucOffText);
    }else{
        ShowIndentString(TRUE,  17, OSD_SM_DpHPD_Y,1,ucOffText);
        OSDAPI_SetFontAttr(SM_FRAME_COLOR);
        ShowIndentString(TRUE,  13, OSD_SM_DpHPD_Y,1,ucOnText);        
    }
}
#if ENABLE_SERVICEMENU_DVIHPD == ON
void ServiceMenuShowDviHPD(void)
{
    OSDAPI_SetIndentIndex(0xDF);
    OSDAPI_SetFontAttr(SM_ITEM_COLOR);
    if(SystemData.bDVI_HPD)
    {
        ShowIndentString(TRUE,  13, OSD_SM_DviHPD_Y,1,ucOnText);
        OSDAPI_SetFontAttr(SM_FRAME_COLOR);
        ShowIndentString(TRUE,  17, OSD_SM_DviHPD_Y,1,ucOffText);
    }else{
        ShowIndentString(TRUE,  17, OSD_SM_DviHPD_Y,1,ucOffText);
        OSDAPI_SetFontAttr(SM_FRAME_COLOR);
        ShowIndentString(TRUE,  13, OSD_SM_DviHPD_Y,1,ucOnText);        
    }
}
#endif
void ServiceMenuShowLogo(void)
{
    OSDAPI_SetIndentIndex(0xE4);
    OSDAPI_SetFontAttr(SM_ITEM_COLOR);
    if(SystemData.bShowLogo)
    {
        ShowIndentString(TRUE,  13, OSD_SM_Logo_Y,1,ucOnText);
        OSDAPI_SetFontAttr(SM_FRAME_COLOR);
        ShowIndentString(TRUE,  17, OSD_SM_Logo_Y,1,ucOffText);
    }else{
        ShowIndentString(TRUE,  17, OSD_SM_Logo_Y,1,ucOffText);
        OSDAPI_SetFontAttr(SM_FRAME_COLOR);
        ShowIndentString(TRUE,  13, OSD_SM_Logo_Y,1,ucOnText);        
    }
}

void ServiceMenuShowAutoPower(void)
{
    OSDAPI_SetIndentIndex(0xE9);
    OSDAPI_SetFontAttr(SM_ITEM_COLOR);
    if(SystemData.bAutoPower)
    {
        ShowIndentString(TRUE,  13, OSD_SM_AutoPower_Y,1,ucOnText);
        OSDAPI_SetFontAttr(SM_FRAME_COLOR);
        ShowIndentString(TRUE,  17, OSD_SM_AutoPower_Y,1,ucOffText);
    }else{
        ShowIndentString(TRUE,  17, OSD_SM_AutoPower_Y,1,ucOffText);
        OSDAPI_SetFontAttr(SM_FRAME_COLOR);
        ShowIndentString(TRUE,  13, OSD_SM_AutoPower_Y,1,ucOnText);        
    }
}

void ServiceMenuShowCable(void)
{
    OSDAPI_SetIndentIndex(0xEE);
    OSDAPI_SetFontAttr(SM_ITEM_COLOR);
    if(SystemData.bCable)
    {
        ShowIndentString(TRUE,  13, OSD_SM_Cable_Y,1,ucOnText);
        OSDAPI_SetFontAttr(SM_FRAME_COLOR);
        ShowIndentString(TRUE,  17, OSD_SM_Cable_Y,1,ucOffText);
    }else{
        ShowIndentString(TRUE,  17, OSD_SM_Cable_Y,1,ucOffText);
        OSDAPI_SetFontAttr(SM_FRAME_COLOR);
        ShowIndentString(TRUE,  13, OSD_SM_Cable_Y,1,ucOnText);        
    }
}

void ServiceMenuSelect(void)
{
    OSDAPI_FillLineAttr(SMLBar[ucServiceMenuIndex].x, SMLBar[ucServiceMenuIndex].y,
                        SMLBar[ucServiceMenuIndex].len,SM_SELECT_COLOR);
}

void ServiceMenuUnSelect(void)
{
    OSDAPI_FillLineAttr(SMLBar[ucServiceMenuIndex].x, SMLBar[ucServiceMenuIndex].y,
                        SMLBar[ucServiceMenuIndex].len, SM_FRAME_COLOR);
}

