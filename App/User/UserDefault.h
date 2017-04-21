/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
#ifndef __USER_DEFAULT_H__
#define __USER_DEFAULT_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "Typedef.h"

//******************************************************************************
// G L O B A L   D E F I N I T I O N S
//******************************************************************************
//#define RANGE_BRIGHTNESS_PWM        (MAXIMUM_BRIGHTNESS_PWM-MINIMUM_BRIGHTNESS_PWM)
//#define RANGE_BRIGHTNESS_PWM_ULTRA  (MAXIMUM_BRIGHTNESS_PWM_ULTRA-MINIMUM_BRIGHTNESS_PWM_ULTRA)

#define MAXIMUM_BRIGHTNESS          100
#define MAXIMUM_CONTRAST            100
#define MAXIMUM_PHASE               63
#define MAXIMUM_SHARPNESS           10
#define MAXIMUM_HUE                    100
#define MAXIMUM_SATURATION            100
#define MAXIMUM_CLR_TEMP            (NUMBER_CLRTMP - 1)
#define MAXIMUM_USER_RGAIN          100
#define MAXIMUM_USER_GGAIN          100
#define MAXIMUM_USER_BGAIN          100
#define MAXIMUM_USER_ROFFSET        100
#define MAXIMUM_USER_GOFFSET        100
#define MAXIMUM_USER_BOFFSET        100
#define MAXIMUM_OSD_HPOS            100
#define MAXIMUM_OSD_VPOS            100
#define MAXIMUM_OSD_TRANS           4
#define MAXIMUM_OSD_TIMER           120//60
#define MAXIMUM_OSD_ROT             1
#define MAXIMUM_OSD_LANG            (NUM_OSDLANGS - 1)
#define MAXIMUM_OSD_LOCK            1
#define MAXIMUM_MUTE                1
#define MAXIMUM_VOLUME              100
#define MAXIMUM_INPUT_SRC           NUM_INPUT_SC
#define MAXIMUM_DCR_MODE            1
#if PICTURE_FORMAT_NEW == ON
#define MAXIMUM_ASPECT_RATIO        4
#else
#define MAXIMUM_ASPECT_RATIO        2
#endif
#define MAXIMUM_OD_MODE             OD_NUM
#define MAXIMUM_BF_MODE             PICTURE_MODE_NUM
#define MAXIMUM_GAMMA_NUM           4
#define MAXIMUM_MONITOR_OFF_TIMER   24
#define MAXIMUM_ES_DST              2//4
#define MAXIMUM_ES_OFF              6
#define MAXIMUM_ADCGAIN             200
#define MAXIMUM_ADCOFFSET           200
#define MAXIMUM_CLRTEMP_GAIN        255
#define MAXIMUM_ClearVision_MODE    3//(NUMBER_ClearVision - 1)// 3
#define MAXIMUM_USER_DEF_VIDEO      3
#define MAXIMUM_USER_DEF_AUDIO      3
#define MAXIMUM_2DTO3D_MODE         4
#define MAXIMUM_2DTO3D_MODE         4
#define MAXIMUM_2DTO3D_ADPT         1
#define MAXIMUM_2DTO3D_DEPTH        10
#define MAXIMUM_2DTO3D_VIEW         11
#define MAXIMUM_3D_LR_SWAP          1
#define MAXIMUM_DYNCONTRAST         5
#define MAXIMUM_SMARTSCALING        100
#define MAXIMUM_ANIMATION_MODE      10

#define MINIMUM_BRIGHTNESS          0
#define MINIMUM_CONTRAST            0
#define MINIMUM_PHASE               0
#define MINIMUM_SHARPNESS           1
#define MINIMUM_HUE                    0
#define MINIMUM_SATURATION          0
#define MINIMUM_CLR_TEMP            0
#define MINIMUM_USER_RGAIN          0
#define MINIMUM_USER_GGAIN          0
#define MINIMUM_USER_BGAIN          0
#define MINIMUM_USER_ROFFSET        0
#define MINIMUM_USER_GOFFSET        0
#define MINIMUM_USER_BOFFSET        0
#define MINIMUM_OSD_HPOS            0
#define MINIMUM_OSD_VPOS            0
#define MINIMUM_OSD_TRANS           0
#define MINIMUM_OSD_ROT             0
#define MINIMUM_OSD_TIMER           5
#define MINIMUM_OSD_LANG            0
#define MIMIMUM_OSD_LOCK            0
#define MINIMUM_MUTE                0
#define MINIMUM_VOLUME              0
#define MINIMUM_INPUT_SRC           0
#define MINIMUM_DCR_MODE            0
#define MINIMUM_ASPECT_RATIO        0
#define MINIMUM_OD_MODE             0
#define MINIMUM_BF_MODE             0
#define MINIMUM_2DTO3D_MODE         0
#define MINIMUM_2DTO3D_ADPT         0
#define MINIMUM_2DTO3D_DEPTH        0
#define MINIMUM_2DTO3D_VIEW         0
#define MINIMUM_3D_LR_SWAP          0
#define MINIMUM_GAMMA_NUM           0
#define MINIMUM_MONITOR_OFF_TIMER   0
#define MINIMUM_ES_DST              0
#define MINIMUM_ES_OFF              0
#define MINIMUM_ADCGAIN             50
#define MINIMUM_ADCOFFSET           50
#define MINIMUM_CLRTEMP_GAIN        50
#define MINIMUM_ClearVision_MODE    0
#define MINIMUM_USER_DEF_VIDEO      0
#define MINIMUM_USER_DEF_AUDIO      0
#define MINIMUM_DYNCONTRAST         0
#define MINIMUM_SMARTSCALING        0
#define MINIMUM_ANIMATION_MODE      0
//user data default value
#if OSDTYPE == OSD_BENQ_V2
#define DEFAULT_INPUTSOURCE        MODEL_INPUT_DIG7
#define DEF_ANIMATIONMODE           1  //UCHAR ucAnimationMode;
#define DEFAULT_DPAUTOSWITCH        OFF
#define DEFAULT_SensEyeDemo         PICTURE_DUALMODE_OFF
#define DEFAULT_COLOR_AUTO          COLOR_AUTO
#define DEF_BRIGHTNESS              0x64
#define DEF_BRIGHTNESS_STANDARD     90
#define DEF_BRIGHTNESS_CAD          90
#define DEF_BRIGHTNESS_REC709       17
#define DEF_BRIGHTNESS_DARKROOM     14


#define DEF_CONTRAST                0x32


#define DEFAULT_GAMMA               nGamma_18
#define DEFAULT_GAMMA_SRGB          nGamma_22
#define DEFAULT_GAMMA_STANDARD      nGamma_22
#define DEFAULT_GAMMA_LBL_MULT      nGamma_18
#define DEFAULT_GAMMA_LBL_WEB       nGamma_18
#define DEFAULT_GAMMA_LBL_OFFICE    nGamma_18
#define DEFAULT_GAMMA_LBL_READ      nGamma_18
#define DEFAULT_GAMMA_MOVIE         nGamma_20
#define DEFAULT_GAMMA_GAME          nGamma_22
#define DEFAULT_GAMMA_PHOTO         nGamma_26
#define DEFAULT_GAMMA_USER          nGamma_22
#define DEFAULT_GAMMA_MBOOK         nGamma_18
#define DEFAULT_GAMMA_ANIMATION     nGamma_22
#define DEFAULT_GAMMA_CAD           nGamma_26
#define DEFAULT_GAMMA_PRESENTATION  nGamma_20
#define DEFAULT_GAMMA_REC709        nGamma_24
#define DEFAULT_GAMMA_DARKROOM      nGamma_20

#define DEFAULT_COLORTEMP               CLRTMP_6500K
#define DEFAULT_COLORTEMP_SRGB          CLRTMP_6500K
#define DEFAULT_COLORTEMP_STANDARD      CLRTMP_6500K
#define DEFAULT_COLORTEMP_LBL_MULT      CLRTMP_6500K
#define DEFAULT_COLORTEMP_LBL_WEB       CLRTMP_6500K
#define DEFAULT_COLORTEMP_LBL_OFFICE    CLRTMP_6500K
#define DEFAULT_COLORTEMP_LBL_READ      CLRTMP_6500K
#define DEFAULT_COLORTEMP_MOVIE         CLRTMP_6500K
#define DEFAULT_COLORTEMP_GAME          CLRTMP_9300K
#define DEFAULT_COLORTEMP_PHOTO         CLRTMP_9300K
#define DEFAULT_COLORTEMP_USER          CLRTMP_6500K
#define DEFAULT_COLORTEMP_MBOOK         CLRTMP_6500K
#define DEFAULT_COLORTEMP_ANIMATION     CLRTMP_6500K
#define DEFAULT_COLORTEMP_CAD           CLRTMP_5000K
#define DEFAULT_COLORTEMP_PRESENTATION  CLRTMP_9300K
#define DEFAULT_COLORTEMP_REC709        CLRTMP_6500K
#define DEFAULT_COLORTEMP_DARKROOM      CLRTMP_6500K

#define DEFAULT_OD                      OD_High
#define DEFAULT_OD_SRGB                 OD_High
#define DEFAULT_OD_STANDARD             OD_High
#define DEFAULT_OD_LBL_MULT             OD_High
#define DEFAULT_OD_LBL_WEB              OD_High
#define DEFAULT_OD_LBL_OFFICE           OD_High
#define DEFAULT_OD_LBL_READ             OD_High
#define DEFAULT_OD_MOVIE                OD_High
#define DEFAULT_OD_GAME                 OD_High
#define DEFAULT_OD_PHOTO                OD_High
#define DEFAULT_OD_USER                 OD_High
#define DEFAULT_OD_MBOOK                OD_High
#define DEFAULT_OD_ANIMATION            OD_High
#define DEFAULT_OD_CAD                  OD_High
#define DEFAULT_OD_PRESENTATION         OD_High
#define DEFAULT_OD_REC709               OD_High
#define DEFAULT_OD_DARKROOM             OD_High

#define DEFAULT_AUTOSORUCE   ON//OFF
#elif 0 // OSDTYPE == OSD_BENQ_V1
#define DEFAULT_INPUTSOURCE        MODEL_INPUT_DIG2
#define DEF_ANIMATIONMODE           1  //UCHAR ucAnimationMode;
#define DEFAULT_DPAUTOSWITCH        ON
#define DEFAULT_SensEyeDemo         OFF
#define DEFAULT_COLOR_AUTO   COLOR_LIMIT
#define DEF_BRIGHTNESS              0x64
#define DEF_BRIGHTNESS_STANDARD     0x64
#define DEF_BRIGHTNESS_CAD          0x64
#define DEF_BRIGHTNESS_REC709       0x64
#define DEF_BRIGHTNESS_DARKROOM     0x64

#define DEFAULT_GAMMA               nGamma_18
#define DEFAULT_GAMMA_SRGB          nGamma_22
#define DEFAULT_GAMMA_STANDARD      nGamma_22
#define DEFAULT_GAMMA_LBL_MULT      nGamma_18
#define DEFAULT_GAMMA_LBL_WEB       nGamma_18
#define DEFAULT_GAMMA_LBL_OFFICE    nGamma_18
#define DEFAULT_GAMMA_LBL_READ      nGamma_18
#define DEFAULT_GAMMA_MOVIE         nGamma_20
#define DEFAULT_GAMMA_GAME          nGamma_22
#define DEFAULT_GAMMA_PHOTO         nGamma_26
#define DEFAULT_GAMMA_USER          nGamma_22
#define DEFAULT_GAMMA_MBOOK         nGamma_18
#define DEFAULT_GAMMA_ANIMATION     nGamma_22
#define DEFAULT_GAMMA_CAD           nGamma_22
#define DEFAULT_GAMMA_PRESENTATION  nGamma_20
#define DEFAULT_GAMMA_REC709        nGamma_26
#define DEFAULT_GAMMA_DARKROOM      nGamma_26

#define DEFAULT_COLORTEMP               CLRTMP_6500K
#define DEFAULT_COLORTEMP_SRGB          CLRTMP_6500K
#define DEFAULT_COLORTEMP_STANDARD      CLRTMP_6500K
#define DEFAULT_COLORTEMP_LBL_MULT      CLRTMP_6500K
#define DEFAULT_COLORTEMP_LBL_WEB       CLRTMP_6500K
#define DEFAULT_COLORTEMP_LBL_OFFICE    CLRTMP_6500K
#define DEFAULT_COLORTEMP_LBL_READ      CLRTMP_6500K
#define DEFAULT_COLORTEMP_MOVIE         CLRTMP_6500K
#define DEFAULT_COLORTEMP_GAME          CLRTMP_9300K
#define DEFAULT_COLORTEMP_PHOTO         CLRTMP_9300K
#define DEFAULT_COLORTEMP_USER          CLRTMP_6500K
#define DEFAULT_COLORTEMP_MBOOK         CLRTMP_6500K
#define DEFAULT_COLORTEMP_ANIMATION     CLRTMP_6500K
#define DEFAULT_COLORTEMP_CAD           CLRTMP_9300K
#define DEFAULT_COLORTEMP_PRESENTATION  CLRTMP_9300K
#define DEFAULT_COLORTEMP_REC709        CLRTMP_6500K
#define DEFAULT_COLORTEMP_DARKROOM      CLRTMP_6500K

#define DEFAULT_OD                      OD_High
#define DEFAULT_OD_SRGB                 OD_High
#define DEFAULT_OD_STANDARD             OD_High
#define DEFAULT_OD_LBL_MULT             OD_High
#define DEFAULT_OD_LBL_WEB              OD_High
#define DEFAULT_OD_LBL_OFFICE           OD_High
#define DEFAULT_OD_LBL_READ             OD_High
#define DEFAULT_OD_MOVIE                OD_High
#define DEFAULT_OD_GAME                 OD_High
#define DEFAULT_OD_PHOTO                OD_High
#define DEFAULT_OD_USER                 OD_High
#define DEFAULT_OD_MBOOK                OD_High
#define DEFAULT_OD_ANIMATION            OD_High
#define DEFAULT_OD_CAD                  OD_High
#define DEFAULT_OD_PRESENTATION         OD_High
#define DEFAULT_OD_REC709               OD_High
#define DEFAULT_OD_DARKROOM             OD_High

#define DEFAULT_AUTOSORUCE   ON
#else
#define DEFAULT_INPUTSOURCE        MODEL_INPUT_DIG2
#define DEFAULT_DPAUTOSWITCH        ON
#define DEFAULT_SensEyeDemo         OFF
#define DEFAULT_COLOR_AUTO   COLOR_LIMIT
#define DEF_BRIGHTNESS              0x64
#define DEF_BRIGHTNESS_STANDARD     0x64
#define DEF_BRIGHTNESS_CAD          0x64
#define DEF_BRIGHTNESS_REC709       0x64
#define DEF_BRIGHTNESS_DARKROOM     0x64

#define DEFAULT_GAMMA               nGamma_22
#define DEFAULT_GAMMA_SRGB          nGamma_22
#define DEFAULT_GAMMA_STANDARD      nGamma_22
#define DEFAULT_GAMMA_LBL_MULT      nGamma_18
#define DEFAULT_GAMMA_LBL_WEB       nGamma_18
#define DEFAULT_GAMMA_LBL_OFFICE    nGamma_18
#define DEFAULT_GAMMA_LBL_READ      nGamma_18
#define DEFAULT_GAMMA_MOVIE         nGamma_20
#define DEFAULT_GAMMA_GAME          nGamma_22
#define DEFAULT_GAMMA_PHOTO         nGamma_26
#define DEFAULT_GAMMA_USER          nGamma_22
#define DEFAULT_GAMMA_MBOOK         nGamma_18
#define DEFAULT_GAMMA_ANIMATION     nGamma_22
#define DEFAULT_GAMMA_CAD           nGamma_22
#define DEFAULT_GAMMA_PRESENTATION  nGamma_20
#define DEFAULT_GAMMA_REC709        nGamma_26
#define DEFAULT_GAMMA_DARKROOM      nGamma_26

#define DEFAULT_COLORTEMP               CLRTMP_6500K
#define DEFAULT_COLORTEMP_SRGB          CLRTMP_6500K
#define DEFAULT_COLORTEMP_STANDARD      CLRTMP_6500K
#define DEFAULT_COLORTEMP_LBL_MULT      CLRTMP_6500K
#define DEFAULT_COLORTEMP_LBL_WEB       CLRTMP_6500K
#define DEFAULT_COLORTEMP_LBL_OFFICE    CLRTMP_6500K
#define DEFAULT_COLORTEMP_LBL_READ      CLRTMP_6500K
#define DEFAULT_COLORTEMP_MOVIE         CLRTMP_6500K
#define DEFAULT_COLORTEMP_GAME          CLRTMP_9300K
#define DEFAULT_COLORTEMP_PHOTO         CLRTMP_9300K
#define DEFAULT_COLORTEMP_USER          CLRTMP_6500K
#define DEFAULT_COLORTEMP_MBOOK         CLRTMP_6500K
#define DEFAULT_COLORTEMP_ANIMATION     CLRTMP_6500K
#define DEFAULT_COLORTEMP_CAD           CLRTMP_9300K
#define DEFAULT_COLORTEMP_PRESENTATION  CLRTMP_9300K
#define DEFAULT_COLORTEMP_REC709        CLRTMP_6500K
#define DEFAULT_COLORTEMP_DARKROOM      CLRTMP_6500K

#define DEFAULT_OD                      OD_High
#define DEFAULT_OD_SRGB                 OD_High
#define DEFAULT_OD_STANDARD             OD_High
#define DEFAULT_OD_LBL_MULT             OD_High
#define DEFAULT_OD_LBL_WEB              OD_High
#define DEFAULT_OD_LBL_OFFICE           OD_High
#define DEFAULT_OD_LBL_READ             OD_High
#define DEFAULT_OD_MOVIE                OD_High
#define DEFAULT_OD_GAME                 OD_High
#define DEFAULT_OD_PHOTO                OD_High
#define DEFAULT_OD_USER                 OD_High
#define DEFAULT_OD_MBOOK                OD_High
#define DEFAULT_OD_ANIMATION            OD_High
#define DEFAULT_OD_CAD                  OD_High
#define DEFAULT_OD_PRESENTATION         OD_High
#define DEFAULT_OD_REC709               OD_High
#define DEFAULT_OD_DARKROOM             OD_High

#define DEFAULT_AUTOSORUCE   ON
#endif
#endif //__USER_DEFAULT_H__
/******************************************************************************/
