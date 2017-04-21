/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/

#ifndef __SCALER_DISPLAY_H__
#define __SCALER_DISPLAY_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "ScalerType.h"
#include "Typedef.h"

//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************

//******************************************************************************
// D A T A   T Y P E   D E F I N E S
//******************************************************************************
/*!
 * Data type for aspect ratio.
 */
typedef enum _ASPECTRATIO_ {
    ASP_RATIO_FULL,      /*!< Full screen display. */
    ASP_RATIO_SCALE,     /*!< Original aspect ratio display. */
    ASP_RATIO_4_3,       /*!< 4:3 display. */
    ASP_RATIO_SMART_4_3, /*!< Smart 4:3 display. */
    ASP_RATIO_REAL       /*!< Pixel-by-pixel display. */
} AspectRatio;

typedef struct{
 ULONG clock;
 USHRT htotal;
 USHRT vtotal;
 USHRT active_width;
 USHRT active_height;
}tTIMING;

//******************************************************************************
// V A R I A B L E S   P R O T O T Y P E
//******************************************************************************

//******************************************************************************
// F U N C T I O N    P R O T O T Y P E S
//******************************************************************************
void DisplayInit(void);
void EnableDPLL(void);
void DisableDPLL(void);
void EnableDclk(void);
void LoadDefaultPanelData(void);
void SetDisplayDCLK(ULONG clk);
#if ENABLE_LD == ON
ULONG GetDisplayDCLK(void);
#endif
void SetFreeRunClk(void);
void DispClkCompress(tTIMING *input,tTIMING *disp);
BOOL SetupDisplayTiming(USHRT htotal50);
void SetPostBGColor(UCHAR r, UCHAR g, UCHAR b);
void Force2Background(UCHAR r, UCHAR g, UCHAR b);
void WaitDisVSync(void);
void GraphicDisplayWindowEnable(void);
void GraphicDisplayWindowDisable(void);
//USHRT GetCustomDspRatio(void);
void SetCustomDspRatio(USHRT ratio);
void SetDisplayMode(AspectRatio aspectmode);
void NormalDisplay(void);
void DisplayPostPattern(UCHAR pattern);
void DisplayMuteImage(void);
void DisplayNormalImage(void);
void EnableDclkSSC(void);
void DisableDclkSSC(void);
void SetDclkSSCRatio(UCHAR ratio);
void SetDclkSSCFreq(UCHAR freq);
void SetDclkSSC(UCHAR value);
void CheckFIFO(void);

#endif //__SCALER_DISPLAY_H__
