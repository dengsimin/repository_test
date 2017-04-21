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
xdata InputTimingFormat InputTiming; /*!< Variable of input timing information. */
xdata NvramUserData UserData; /*!< Variable of user data. */
xdata NvramCalibData CalibData; /*!< Variable of calibration data. */
xdata NvramSystemData SystemData; /*!< Variable of system data. */
xdata PanelData UserPanelData; /*!< Variable of panel timing information. */
xdata UCHAR ucADCPhase100; /*!< Variable of ADC phase normalized to 100. */
xdata UCHAR ucVstart100; /*!< Variable of Vstart normalized to 100. */

xdata tCUSTOM_SYS Custom_System;
#if ENABLE_HDCP_TRIM_MODE == ON || ENABLE_EDID_TRIM_MODE == ON
xdata UCHAR ucEFUSE_ID;
xdata UCHAR ucEFUSETrimSucess;
xdata UCHAR ucLEDTRIM_LO;
xdata UCHAR ucLEDTRIM_HI;
xdata UCHAR ucADCTRIM;
xdata UCHAR ucADCTRIM_SEL;
#endif
xdata USHRT usAudioMuteDelay = 0;
xdata USHRT usTimerANAMute;
#if ENABLE_FREESYNC_DEMO == ON
bit bFreeSyncMode;
#endif
xdata UCHAR glob_FontBuff[GLOB_FONTBUF_LEN];
bit bSelectTable = OSDFontTble1;

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

/**************************************************************************//**
 * Initialize all global variables.
 ******************************************************************************/
void RamInitialize(void)
{
    UserData = UserDataDefault;
    CalibData = CalibDataDefault;
    SystemData = SystemDataDefault;
    UserPanelData = PanelDataDefault;
}
