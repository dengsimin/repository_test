/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/
#ifndef __COLOR_CONFIG_H__
#define __COLOR_CONFIG_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "Typedef.h"
#include "ColorEngine.h"

//******************************************************************************
// G L O B A L   D E F I N I T I O N S
//******************************************************************************
enum {
    CE_NTSC_76,
    CE_NTSC_80,
    CE_NVTCLR_1,
    CE_NVTCLR_2,
    CE_OFF,
    CE_ClearVision_WEAK,
    CE_ClearVision_MEDIUM,
    CE_ClearVision_STRONG,
    NUMBER_CE_MODES    
} ;
 #if OSDTYPE == OSD_BENQ_V1
enum {
    IG_MOVIE,
    IG_CAD,
    IG_PHOTO,
    IG_M_BOOK,
    IG_PRESENTATION,
    IG_S_CURVE,
    IG_RS_CURVE,
    IG_RC_CURVE,
    IG_C_CURVE,
    IG_ANIMATION,
    IG_NVT_CURVE_2,
    IG_DEFAULT,
    NUMBER_IG_MODES
} ;

enum {
    HH_MODE_Movie,       //Benq Movie
    HH_MODE_CAD,         //Benq CAD
    HH_MODE_Photo,       //Benq Photo
    HH_MODE_M_Book,      //Benq M-Book
    HH_MODE_PRESENTATION,//Benq PRESENTATION
    HH_MODE_ANIMATION,   //Benq ANIMATION
    NUMBER_HH_MODES
} ;

enum {
    HS_MODE_Movie,       //Benq Movie
    HS_MODE_CAD,         //Benq CAD
    HS_MODE_Photo,       //Benq Photo
    HS_MODE_M_Book,      //Benq M-Book
    HS_MODE_PRESENTATION,//Benq PRESENTATION
    HS_MODE_ANIMATION,//Benq ANIMATION
    NUMBER_HS_MODES
} ;
#elif OSDTYPE == OSD_BENQ_V2
enum {
    IG_MOVIE,
    IG_CAD,
    IG_PHOTO,
    IG_M_BOOK,
    IG_PRESENTATION,
    IG_S_CURVE,
    IG_RS_CURVE,
    IG_RC_CURVE,
    IG_C_CURVE,
    IG_ANIMATION,
    IG_DARKROOM,
    IG_DEFAULT,
    NUMBER_IG_MODES
} ;

enum {
    HH_MODE_Movie,       //Benq Movie
    HH_MODE_CAD,         //Benq CAD
    HH_MODE_Photo,       //Benq Photo
    HH_MODE_M_Book,      //Benq M-Book
    HH_MODE_PRESENTATION,//Benq PRESENTATION
    HH_MODE_ANIMATION,   //Benq ANIMATION
    NUMBER_HH_MODES
} ;

enum {
    HS_MODE_Movie,       //Benq Movie
    HS_MODE_CAD,         //Benq CAD
    HS_MODE_Photo,       //Benq Photo
    HS_MODE_M_Book,      //Benq M-Book
    HS_MODE_PRESENTATION,//Benq PRESENTATION
    HS_MODE_ANIMATION,//Benq ANIMATION
    NUMBER_HS_MODES
} ;
#else
enum {
    IG_MOVIE,
    IG_PHOTO,
    IG_GAME,
    IG_RS_CURVE,
    IG_RC_CURVE,
    IG_C_CURVE,
    IG_ANIMATION,
    IG_NVT_CURVE_2,
    IG_DEFAULT,
    NUMBER_IG_MODES
} ;

enum {
    HH_MODE_1, //Benq Movie
    HH_MODE_2, //Benq Game
    HH_MODE_3, //Benq Photo
    HH_MODE_4, //Benq M-Book
    NUMBER_HH_MODES
} ;

enum {
    HS_MODE_1, //Benq Movie
    HS_MODE_2, //Benq Game
    HS_MODE_3, //Benq Photo
    HS_MODE_4, //Benq M-Book
    NUMBER_HS_MODES
} ;
#endif
/*              // move to osdconfig.h
enum {
    CLRTMP_5000K,
    CLRTMP_6500K,
    CLRTMP_7500K,
    CLRTMP_8200K,
    CLRTMP_9300K,
    CLRTMP_11500K,
    CLRTMP_sRGB,
    CLRTMP_USER,
    NUMBER_CLRTMP
} ;
*/


enum {
    MULTIMEDIA,
    WEB_SURFING,
    OFFICE,
    READING,
    NUMBER_LBL_MODES
} ;


typedef struct _CM_BLOCK_ {
    UCHAR ROffset;
    UCHAR GOffset;
    UCHAR BOffset;
    UCHAR RGain;
    UCHAR GGain;
    UCHAR BGain;
    UCHAR Saturation;
    UCHAR Intensity;
    UCHAR Hue;
    UCHAR BlueMore;
    UCHAR GreenMore;
    UCHAR RedMore;
    UCHAR FTMore;
    UCHAR Sharpness;
    UCHAR Peaking;
    UCHAR TextEn;
    BFColorExMode ClrMode;
    IGBlock *pIG;
    HHBlock *pHH;
    HSBlock *pHS;
    HIBlock *pHI;
} CMBlock;

typedef enum _BF_IDV_COLOR_EN_MODE_
{
    _BF_IDV_COLOR_EN_NONE_,
    _BF_IDV_COLOR_EN_SKIN_,
    _BF_IDV_COLOR_EN_GREEN_,
    _BF_IDV_COLOR_EN_BLUE_,
    _BF_IDV_COLOR_EN_ALL_
} BF_IDV_COLOR_EN_MODE;

extern BOOL Standard_Gamma;

//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
void InitColor(void);
extern void SetThemeMode(UCHAR mode);
extern void DCR_BenQ_ResetDynBacklight(USHRT backlight);
extern void DCR_BenQ_FroceSetBk();
extern BOOL DCR_BenQ_Init();
extern void PerformDCR(UCHAR reset);
extern void DisableDCR(void);
extern void SetDBCBacklight(USHRT brightness, BOOL bSuperDCR);
extern void SetColorTemperature(UCHAR mode);
extern void SetLBLMode_BriCon(void);
extern void SetLBLMode_Sharpness(void);

extern void SetPictureMode(UCHAR mode);
//=== AOC ====
void SetBF_Brightness(void);
void SetBF_Contrast(void);
void BF_IdvColorEnhance(BF_IDV_COLOR_EN_MODE mode);
void BF_ColorEnhance(BFColorExMode mode);
void BF_SetWindowSize(UCHAR type);
void BF_SetSize(void);
void BF_SetHP(void);
void BF_SetVP(void);
void BF_SetWindowAfterAspectRatio();
//void SetBrightFrame(void);
void SetDCR(void);
extern void SetDemo(void);
#if 0
UCHAR GetECOBrightness(UCHAR mode);
UCHAR GetBrightnessAdj(UCHAR mode);
UCHAR GetECOContrast(UCHAR mode);
#endif
//void SetECO_DCR(void);
//#if BF_DYNAMIC_BACKLIGHT==1
//UCHAR ucDCRStableCount;
void ResetClearVision(void);
void BFSetClearVisionMode(UCHAR txt);
extern void UserSetSaturation(void);
extern void UserSetHue(void);
extern void UserSetAnimation(void);
extern void SetLBLMode(void);
extern void SetLocalMatrix(void);
extern void DCR_BenQ_Reset(void);
extern UCHAR GetGammaNum(void);
extern void SetGammaNum(UCHAR GammaNum);
extern UCHAR GetColorTempature(void);
extern void SetSenseEyeLeftMode(UCHAR mode);
extern void SetCLRTMP_Sharpness(void);
extern void SetCLRTMP_BriCon(void);

void BFAPI_SetPreACEModeWithStep(IGBlock *ptr, UCHAR Step);

//#endif
//===========================
#endif //__COLOR_CONFIG_H__

