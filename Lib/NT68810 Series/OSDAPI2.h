/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/
#ifndef __OSD_API_2H__
#define __OSD_API_2H__


//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "Typedef.h"
#if 1
typedef enum _OSDWIN_DEGREE_ {
    OSD_WIN_DEGREE_0,   /*!< Rotate 0 degree. */
    OSD_WIN_DEGREE_90,  /*!< Rotate 90 degree. */
    OSD_WIN_DEGREE_180, /*!< Rotate 180 degree. */
    OSD_WIN_DEGREE_270, /*!< Rotate 270 degree. */
    NUM_OSD_WIN_DEGREE  /*!< Number of rotation modes for OSD windows. */
} OSDWinDegree;
#endif
//******************************************************************************
// G L O B A L   D E F I N I T I O N S
//******************************************************************************
void OSDAPI_SetIndentString(UCHAR *ptr) small;
extern void OSDUnselectSubItem(UCHAR id);
extern void OSDAPI_SetPosition(USHRT x, USHRT y);
extern void OSDAPI_RotateOSDWinPosition(USHRT sx, USHRT sy, USHRT ex, USHRT ey, OSDWinDegree degree, UCHAR rot);
extern void OSDAPI_RotateOSDWin(OSDWindow id, OSDPosRotation rot);

#endif //__OSD_API_2H__

