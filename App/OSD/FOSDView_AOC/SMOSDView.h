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
#include "Typedef.h"
#include "OSDFont.h"

//******************************************************************************
// G L O B A L   D E F I N I T I O N S
//******************************************************************************
#define OSD_SM_W 32
#define OSD_SM_H 32

#define OSD_SM_Model_Y          3
#define OSD_SM_Sn_Y             OSD_SM_Model_Y + 2
#define OSD_SM_Vender_Y         OSD_SM_Sn_Y + 2
#define OSD_SM_Panel_Y          OSD_SM_Vender_Y + 2
#define OSD_SM_Scaler_Y         OSD_SM_Panel_Y + 2
#define OSD_SM_Version_Y        OSD_SM_Scaler_Y + 2
#define OSD_SM_MOT_Y            OSD_SM_Version_Y + 2
#define OSD_SM_BOT_Y            OSD_SM_MOT_Y + 2
#define OSD_SM_HdmiHPD_Y        OSD_SM_BOT_Y + 2
#define OSD_SM_DpHPD_Y          OSD_SM_HdmiHPD_Y + 2
#if ENABLE_SERVICEMENU_DVIHPD == ON
#define OSD_SM_DviHPD_Y         OSD_SM_DpHPD_Y + 2
#define OSD_SM_Logo_Y           OSD_SM_DviHPD_Y + 2
#else
#define OSD_SM_Logo_Y           OSD_SM_DpHPD_Y + 2
#endif
#define OSD_SM_AutoPower_Y      OSD_SM_Logo_Y + 2
#define OSD_SM_Cable_Y          OSD_SM_AutoPower_Y + 2

#define SM_FRAME_COLOR   (((I_WHITE-1)<<8)|(I_BLUE<<4))
#define SM_ITEM_COLOR    (((I_BLUE-1)<<8)|(I_WHITE<<4))
#define SM_SELECT_COLOR    (((I_WHITE-1)<<8)|(I_TBLUE<<4))

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
void OSDShowServiceMenu(void);
void OSDServiceMenuUp(void);
void OSDServiceMenuDown(void);
void OSDServiceMenuAdjItm(void);

UCHAR OSDServiceMenuUpdate(void);
void OSDShowServiceMenu(void);

