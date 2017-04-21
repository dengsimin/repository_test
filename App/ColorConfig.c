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
#define DBC_ULTRA_LOW
#ifdef DBC_ULTRA_LOW
#define DBC_TIME_TO_OFF     10000
#define DBC_BACKLIGHT_OFF   ULTRA_MIN_BACKLIGHT_VALUE
#define DBC_LTHD_BLANK      4
#define DBC_HTHD_BLANK      7
#endif
#define MapDBCBacklight(s)  ((ULONG)s * (1023 - MIN_BACKLIGHT_VALUE) / 1023 + MIN_BACKLIGHT_VALUE)
//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************
#if  OSDTYPE == OSD_BENQ_V1
#if defined(AUO_M238DAN01_0)
static code IGBlock IGModes[NUMBER_IG_MODES] = {
    {16,   0,  64, 128,  192,  256,  320,  384,  448,  512,  576,  640,   704,  768,  832,  896,   960,   1024},  //IG_MOVIE   0909 Stanley
    {16,   0,  0,    0,  0x4c, 0xa4, 0xf8, 0x148,0x18d,0x1dd,0x229,0x275, 0x2b2,0x2fa,0x336,0x376, 0x3A6, 1024},  //IG_CAD
    {16,   0,  0x54,0xa8,0xd8, 0x110,0x140,0x180,0x1c0,0x200,0x240,0x280, 0x2c0,0x300,0x340,0x380, 0x3c0, 1024},  //IG_PHOTO   0909 Stanley
    {16,   0,  0x5c,0x90,0xc0, 0x100,0x140,0x180,0x1c0,0x200,0x240,0x280, 0x2c0,0x300,0x340,0x380, 0x3c0, 1024},  //IG_M_BOOK    
    {16,0x10,  0x6c,0xb4,0xe8, 0x120,0x150,0x180,0x1c0,0x200,0x240,0x280, 0x2c0,0x300,0x340,0x380, 0x3c0, 1024},  //IG_PRESENTATION
    {16,   0,  58, 116, 168, 228, 288, 356, 428, 504, 584, 660, 732, 800, 860, 920, 972, 1024},  //IG_S_CURVE
    {16,   0,  58, 128, 216, 288, 352, 412, 468, 520, 568, 620, 676, 736, 800, 872, 964, 1024},  //IG_RS_CURVE
    {16,   0,  48, 100, 152, 204, 260, 320, 380, 440, 504, 572, 640, 712, 784, 864, 964, 1024},  //IG_RC_CURVE
    {16,   0,  84, 164, 240, 312, 384, 452, 520, 584, 648, 708, 764, 820, 876, 928, 976, 1024},  //IG_C_CURVE
    {16,   0,  64, 128, 192, 256, 320, 384, 448, 512, 576, 640, 704, 768, 832, 896, 960, 1024},  //IG_ANIMATION   //test
    {16,   0,  48, 108, 164, 228, 276, 340, 408, 488, 540, 596, 664, 736, 804, 876, 948, 1024},  //IG_NVT_CURVE_2
    {16,   0,  64, 128, 192, 256, 320, 384, 448, 512, 576, 640, 704, 768, 832, 896, 960, 1024},  //IG_DEFAULT
};

static code UCHAR DefaultMinIGPoints[] = {
    58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58
};

static code HHBlock HHModes[NUMBER_HH_MODES] = {
    {
        24,    //Benq HH Movie 0909 Stanley
        0x00,        
        0x00,0x20,0x10,0x00,
        0x20,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
    },
    {        //Benq HH CAD
        24,
        0x00,
        0x01,0x20,0x10,0x00,
        0x20,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x21,0x00,0x00,0x00,
    },
    {        //Benq HH photo 0909 Stanley
        24,
        0x00,
        0x00,0x01,0x10,0x03,
        0x20,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
    },
    {         //Benq HH M-Book
        24,
        0x00,
        0x00,0x05,0x10,0x00,
        0x20,0x00,0x00,0x00,
        0x00,0x00,0x83,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x02,0x02,0x20,0x00,
    },
    {         //Benq HH PRESENTATION
        24,
        0x00,
        0x00,0x00,0x00,0x00,
        0x04,0x00,0x00,0x00,
        0x00,0x08,0x08,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x10,
        0x27,0x28,0x24,0x00,
    },
    {
        24,    //Benq HH Animation 0909 Stanley
        0x00,        
        0x00,0x20,0x10,0x00,
        0x20,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
    },
};

static code HSBlock HSModes[NUMBER_HS_MODES] = {
    {
        24,        //Benq HS Movie 0909 Stanley
        0x00,
        0x98,0x88,0x90,0x90,
        0x90,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x90,        
    },
    {
        24,        //Benq HS CAD
        0x00,
        0x68,0x88,0x90,0x90,
        0x70,0x80,0x80,0x80,
        0x68,0x80,0x80,0x80,
        0x70,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x68,0x80,0x80,
    },{
        24,        //Benq HS Photo 0909 Stanley
        0x00,
        0x88,0x80,0x90,0x88,
        0x90,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x90,
    },
    {
        24,         //Benq HS M-book
        0x00,
        0x90,0x70,0x80,0x90,
        0x90,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x70,0x90,
    },
    {
        24,         //Benq HS PRESENTATION
        0x00,
        0x70,0x78,0x80,0x80,
        0x90,0x90,0x80,0x80,
        0x80,0x90,0x90,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x90,
        0x90,0x88,0x78,0x70,
    },
    {
        24,        //Benq HS animation 0909 Stanley
        0x00,
        0x98,0x88,0x90,0x90,
        0x90,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x90,        
    },
};
#elif defined(AUO_M238DAN01_3)
static code IGBlock IGModes[NUMBER_IG_MODES] = {
    {16,   0,  0x54, 0x98,  0xdc,  0x110,  0x144,  0x180,  0x1c0,  0x200,  0x240,  0x280,   0x2c0,  0x300,  0x340,  0x380,   0x3c0,   1024},  //IG_MOVIE   0909 Stanley
    {16,   0,  0x10, 0x34,  0x70, 0xbc, 0xfc, 0x148,0x195,0x1dd,0x229,0x275, 0x2ba,0x2fa,0x336,0x376, 0x3AE, 1024},  //IG_CAD
    {16,   0,  0x44, 0x8c,0xd8, 0x118, 0x150,0x189,0x1c0,0x200,0x240,0x280, 0x2c0,0x300,0x340,0x380, 0x3c0, 1024},  //IG_PHOTO   0909 Stanley
    {16,   0,  0x44, 0x88,  0xc8, 0x100,0x140,0x180,0x1c0,0x200,0x240,0x280, 0x2c0,0x300,0x340,0x380, 0x3c0, 1024},  //IG_M_BOOK    
    {16,  0x28,  0x8c,0xd8,0x114, 0x14c,0x181,0x1b9,0x1ed,0x225,0x259,0x28d, 0x2c0,0x300,0x340,0x380, 0x3c0, 1024},  //IG_PRESENTATION
    {16,   0,  58, 116, 168, 228, 288, 356, 428, 504, 584, 660, 732, 800, 860, 920, 972, 1024},  //IG_S_CURVE
    {16,   0,  58, 128, 216, 288, 352, 412, 468, 520, 568, 620, 676, 736, 800, 872, 964, 1024},  //IG_RS_CURVE
    {16,   0,  48, 100, 152, 204, 260, 320, 380, 440, 504, 572, 640, 712, 784, 864, 964, 1024},  //IG_RC_CURVE
    {16,   0,  84, 164, 240, 312, 384, 452, 520, 584, 648, 708, 764, 820, 876, 928, 976, 1024},  //IG_C_CURVE
    {16,   0,  0x50, 0x90, 0xcc, 0x106, 0x146, 0x186, 0x1c6, 0x200, 0x245, 0x284, 0x2c3, 0x300, 0x340, 0x380, 0x3c0, 1024},  //IG_ANIMATION   //test
    {16,   0,  48, 108, 164, 228, 276, 340, 408, 488, 540, 596, 664, 736, 804, 876, 948, 1024},  //IG_NVT_CURVE_2
    {16,   0,  64, 128, 192, 256, 320, 384, 448, 512, 576, 640, 704, 768, 832, 896, 960, 1024},  //IG_DEFAULT
};

static code UCHAR DefaultMinIGPoints[] = {
    58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58
};

static code HHBlock HHModes[NUMBER_HH_MODES] = {
    {
        24,    //Benq HH Movie 0909 Stanley
        0x00,        
        0x00,0x20,0x08,0x00,
        0x20,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
    },
    {        //Benq HH CAD
        24,
        0x00,
        0xf0,0x08,0x10,0x10,
        0x08,0xf0,0x10,0x10,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0xf0,
        0x00,0x00,0x00,0x00,
        0x00,0xe0,0xe0,0xe0,
    },
    {        //Benq HH photo 0909 Stanley
        24,
        0x00,
        0x00,0x10,0x20,0x13,
        0x20,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
    },
    {         //Benq HH M-Book
        24,
        0x00,
        0x00,0x05,0x20,0x28,
        0x10,0x08,0xe8,0xe8,
        0x08,0x00,0x00,0x00,
        0xf0,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x02,0x02,0xf4,0x00,
    },
    {         //Benq HH PRESENTATION
        24,
        0x00,
        0x00,0xf8,0xf8,0x00,
        0x04,0x00,0xf0,0x00,
        0xf0,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x20,0x30,
        0x30,0x28,0x20,0x00,
    },
    {         //Benq HH animation
        24,
        0x00,
        0x00,0xd8,0xfa,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
    }
};

static code HSBlock HSModes[NUMBER_HS_MODES] = {
    {
        24,        //Benq HS Movie 0909 Stanley
        0x00,
        0x98,0x85,0x8a,0x80,
        0x90,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x90,        
    },
    {
        24,        //Benq HS CAD
        0x00,
        0x90,0x90,0x90,0x90,
        0x90,0x90,0x90,0x90,
        0x90,0x80,0x80,0x80,
        0x70,0x80,0x88,0x90,
        0x90,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
    },{
        24,        //Benq HS Photo 0909 Stanley
        0x00,
        0x88,0x85,0x8a,0x80,
        0x90,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x90,
    },
    {
        24,         //Benq HS M-book
        0x00,
        0x78,0x88,0x88,0x90,
        0x88,0x78,0x70,0x70,
        0x70,0x70,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x78,0x78,
    },
    {
        24,         //Benq HS PRESENTATION
        0x00,
        0x70,0x70,0x78,0x70,
        0x70,0x88,0x88,0x70,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x88,0x90,
        0x90,0x80,0x70,0x60,
    },
    {
        24,         //Benq HS animation
        0x00,
        0x80,0x78,0x78,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
    }
};
#endif
static code CMBlock CMModes[PICTURE_MODE_NUM] = {
#if OSDTYPE == OSD_BENQ_V1
    {// Benq SRGB
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
        0x80,    // Saturation
        0x80,    // Intensity
        0x80,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
        0x00,    // Sharpness
        0x00,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
        &IGModes[IG_DEFAULT],
        NULLPTR, // HH Table
        NULLPTR, // HS Table
        NULLPTR, // HI Table
    },
#if	ENABLE_PICTURE_MODE_CAD == ON
{// Benq CAD
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
    0x90,    // Saturation
        0x80,    // Intensity
    0x82,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
        0x01,    // Sharpness
        0x01,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
        &IGModes[IG_CAD],
        &HHModes[HH_MODE_CAD],
        &HSModes[HS_MODE_CAD],
        NULLPTR, // HI Table
    },
#endif
#if	ENABLE_PICTURE_MODE_ANIMATION == ON
{// Benq Animation
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
    0x90,    // Saturation
        0x80,    // Intensity
    0x82,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
    0x01,    // Sharpness
    0x01,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
    	&IGModes[IG_ANIMATION],
        &HHModes[HH_MODE_ANIMATION],
        &HSModes[HS_MODE_ANIMATION],
        NULLPTR, // HI Table
    },
#endif
#if	ENABLE_PRESENTATION_MODE == ON
{// Benq Presentation
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
        0x80,    // Saturation
        0x80,    // Intensity
        0x80,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
        0x00,    // Sharpness
        0x00,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
        &IGModes[IG_PRESENTATION],
        &HHModes[HH_MODE_PRESENTATION],
        &HSModes[HS_MODE_PRESENTATION],
        NULLPTR, // HI Table
    },
#endif    
#endif
    {// Benq Standard
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
        0x80,    // Saturation
        0x80,    // Intensity
        0x80,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
        0x00,    // Sharpness
        0x00,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
        &IGModes[IG_DEFAULT],
        NULLPTR, // HH Table
        NULLPTR, // HS Table
        NULLPTR, // HI Table
    },
    {// Benq Low Blue Light
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
        0x98,    // Saturation
        0x80,    // Intensity
        0x82,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
        0x01,    // Sharpness
        0x01,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
        &IGModes[IG_DEFAULT],
        NULLPTR,
        NULLPTR,
        NULLPTR, // HI Table
    },
#if ENABLE_PICTURE_MODE_MOVIE == ON   
    {// Benq Movie
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
        0x90,    // Saturation
        0x80,    // Intensity
        0x82,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
        0x01,    // Sharpness
        0x01,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
        &IGModes[IG_MOVIE],
        &HHModes[HH_MODE_Movie],
        &HSModes[HS_MODE_Movie],
        NULLPTR, // HI Table
        },
#endif        
#if ENABLE_PICTURE_MODE_GAME == ON            
        {/// Benq Game
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
        0x82,    // Saturation
        0x80,    // Intensity
        0x80,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
        0x00,    // Sharpness
        0x00,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
        &IGModes[IG_DEFAULT],
        NULLPTR,
        NULLPTR,
        NULLPTR, // HI Table
        },
#endif        
#if ENABLE_PICTURE_MODE_PHOTO== ON   
        {// Benq Photo
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
        0x82,    // Saturation
        0x80,    // Intensity
        0x80,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
        0x00,    // Sharpness
        0x00,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
        &IGModes[IG_PHOTO],
        &HHModes[HH_MODE_Photo],
        &HSModes[HS_MODE_Photo],
        NULLPTR, // HI Table
    },
#endif    
#if OSDTYPE == OSD_BENQ
    {// Benq SRGB
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
        0x80,    // Saturation
        0x80,    // Intensity
        0x80,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
        0x00,    // Sharpness
        0x00,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
        &IGModes[IG_DEFAULT],
        NULLPTR, // HH Table
        NULLPTR, // HS Table
        NULLPTR, // HI Table
    },
#endif
    {// Benq ECO
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
        0x80,    // Saturation
        0x80,    // Intensity
        0x80,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
        0x00,    // Sharpness
        0x00,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
        &IGModes[IG_DEFAULT],
        NULLPTR, // HH Table
        NULLPTR, // HS Table
        NULLPTR, // HI Table        
#if ENABLE_PICTURE_MODE_MBOOK == ON
    },
    {// Benq M-Book
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
    0x90,    // Saturation
        0x80,    // Intensity
    0x82,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
    0x01,    // Sharpness
    0x01,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
    &IGModes[IG_M_BOOK],
    &HHModes[HH_MODE_M_Book],
    &HSModes[HS_MODE_M_Book],
        NULLPTR, // HI Table     
#endif  
    },
    {//OFF
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
        0x80,    // Saturation
        0x80,    // Intensity
        0x80,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
        0x00,    // Sharpness
        0x00,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
        &IGModes[IG_DEFAULT],
        NULLPTR, // HH Table
        NULLPTR, // HS Table
        NULLPTR, // HI Table
    },
};

static code CTGamma CT5800K[5]={
{
	0,	//R_offset
	(-5),	//G_offset
	(-5),	//B_offset
},
{
	0,	//R_offset
	(-3),	//G_offset
	(-3),	//B_offset
},
{
	0,	//R_offset
	0,	//G_offset
	0,	//B_offset
},
{
	0,	//R_offset
	0,	//G_offset
	(2),	//B_offset
},
{
	0,	//R_offset
	2,	//G_offset
	(2),	//B_offset
},
};

static code CTGamma CT9300K[5]={
{
	(-9),//(-15),	//R_offset
	(-7),//(-12),	//G_offset
	0,	//B_offset
},
{
	(-3),//(-8),	//R_offset
	(-4),//(-8),	//G_offset
	0,	//B_offset
},
{
	0,	//R_offset
	0,	//G_offset
	0,	//B_offset
},
{
	4,	//R_offset
	2,	//G_offset
	0,	//B_offset
},
{
	(-12),//6,	//R_offset
	4,	//G_offset
	0,	//B_offset
},

};

static code CTGamma CT6500K[5]={
{
	0,	//R_offset
	(-4),	//G_offset
	(-3),	//B_offset
},
{
	0,	//R_offset
	(-4),	//G_offset
	(-3),	//B_offset
},
{
	0,	//R_offset
	0,	//G_offset
	0,	//B_offset
},
{
	0,	//R_offset
	0,	//G_offset
	0,	//B_offset
},
{
	0,	//R_offset
	0,	//G_offset
	0,	//B_offset
},

};
#elif OSDTYPE == OSD_BENQ_V2
static code IGBlock IGModes[NUMBER_IG_MODES] = {
    {16,   0,  64, 128,  192,  256,  320,  384,  448,  512,  576,  640,   704,  768,  832,  896,   960,   1024},  //IG_MOVIE   0909 Stanley
    {16,   0,  0x10, 0x34,  0x70, 0xBC, 0xFC, 0x148,0x195,0x1dd,0x229,0x275, 0x2BA,0x2fa,0x336,0x376, 0x3AE, 1024},  //IG_CAD
    {16,   0,  0x54,0xa8,0xd8, 0x110,0x140,0x180,0x1c0,0x200,0x240,0x280, 0x2c0,0x300,0x340,0x380, 0x3c0, 1024},  //IG_PHOTO   0909 Stanley
    {16,   0,  0x5c,0x90,0xc0, 0x100,0x140,0x180,0x1c0,0x200,0x240,0x280, 0x2c0,0x300,0x340,0x380, 0x3c0, 1024},  //IG_M_BOOK    
    {16,0x10,  0x6c,0xb4,0xe8, 0x120,0x150,0x180,0x1c0,0x200,0x240,0x280, 0x2c0,0x300,0x340,0x380, 0x3c0, 1024},  //IG_PRESENTATION
    {16,   0,  58, 116, 168, 228, 288, 356, 428, 504, 584, 660, 732, 800, 860, 920, 972, 1024},  //IG_S_CURVE
    {16,   0,  58, 128, 216, 288, 352, 412, 468, 520, 568, 620, 676, 736, 800, 872, 964, 1024},  //IG_RS_CURVE
    {16,   0,  48, 100, 152, 204, 260, 320, 380, 440, 504, 572, 640, 712, 784, 864, 964, 1024},  //IG_RC_CURVE
    {16,   0,  84, 164, 240, 312, 384, 452, 520, 584, 648, 708, 764, 820, 876, 928, 976, 1024},  //IG_C_CURVE
    {16,   0,  0x80, 0xD4, 0x11C, 0x15D, 0x195, 0x1CD, 0x205, 0x23D, 0x26D, 0x2A1, 0x2DE, 0x312, 0x340, 0x380, 0x3C0, 1024},  //IG_ANIMATION   //test
    {16,   0,  0x74, 0xCC, 0x11C, 0x15D, 0x195, 0x1CD, 0x201, 0x235, 0x265, 0x299, 0x2CE, 0x302, 0x33A, 0x372, 0x3B6, 1024},  //IG_DARKROOM
    {16,   0,  64, 128, 192, 256, 320, 384, 448, 512, 576, 640, 704, 768, 832, 896, 960, 1024},  //IG_DEFAULT
};

static code UCHAR DefaultMinIGPoints[] = {
    58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58
};

static code HHBlock HHModes[NUMBER_HH_MODES] = {
    {
        24,    //Benq HH Movie 0909 Stanley
        0x00,        
        0x00,0x20,0x10,0x00,
        0x20,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
    },
    {        //Benq HH CAD
        24,
        0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
    },
    {        //Benq HH photo 0909 Stanley
        24,
        0x00,
        0x00,0x01,0x10,0x03,
        0x20,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
    },
    {         //Benq HH M-Book
        24,
        0x00,
        0x00,0x05,0x10,0x00,
        0x20,0x00,0x00,0x00,
        0x00,0x00,0x83,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x02,0x02,0x20,0x00,
    },
    {         //Benq HH PRESENTATION
        24,
        0x00,
        0x00,0x00,0x00,0x00,
        0x04,0x00,0x00,0x00,
        0x00,0x08,0x08,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x10,
        0x27,0x28,0x24,0x00,
    },
    {
        24,    //Benq HH Animation 
        0x00,        
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
    },
};

static code HSBlock HSModes[NUMBER_HS_MODES] = {
    {
        24,        //Benq HS Movie 0909 Stanley
        0x00,
        0x98,0x88,0x90,0x90,
        0x90,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x90,        
    },
    {
        24,        //Benq HS CAD 20160525
        0x00,
        0x78,0x88,0x90,0x90,
        0x88,0x80,0x80,0x80,
        0x78,0x80,0x80,0x80,
        0x78,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x85,0x80,0x80,
    },{
        24,        //Benq HS Photo 0909 Stanley
        0x00,
        0x88,0x80,0x90,0x88,
        0x90,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x90,
    },
    {
        24,         //Benq HS M-book
        0x00,
        0x90,0x70,0x80,0x90,
        0x90,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x70,0x90,
    },
    {
        24,         //Benq HS PRESENTATION
        0x00,
        0x70,0x78,0x80,0x80,
        0x90,0x90,0x80,0x80,
        0x80,0x90,0x90,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x90,
        0x90,0x88,0x78,0x70,
    },
    {
        24,        //Benq HS animation 20160525
        0x00,
        0x80,0x78,0x78,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,        
    },
};
static code CMBlock CMModes[PICTURE_MODE_NUM] = {
    {// Benq Standard
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
        0x80,    // Saturation
        0x80,    // Intensity
        0x80,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
        0x00,    // Sharpness
        0x00,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
        &IGModes[IG_DEFAULT],
        NULLPTR, // HH Table
        NULLPTR, // HS Table
        NULLPTR, // HI Table
    },
#if ENABLE_PICTURE_MODE_REC709== ON
    {// Benq Rec709
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
        0x80,    // Saturation
        0x80,    // Intensity
        0x80,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
        0x00,    // Sharpness
        0x00,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
        &IGModes[IG_DEFAULT],
        NULLPTR, // HH Table
        NULLPTR, // HS Table
        NULLPTR, // HI Table
    },
#endif
    {// Benq SRGB
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
        0x80,    // Saturation
        0x80,    // Intensity
        0x80,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
        0x00,    // Sharpness
        0x00,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
        &IGModes[IG_DEFAULT],
        NULLPTR, // HH Table
        NULLPTR, // HS Table
        NULLPTR, // HI Table
    },
#if	ENABLE_PICTURE_MODE_CAD == ON
{// Benq CAD
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
    0x90,    // Saturation
        0x80,    // Intensity
    0x82,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
        0x01,    // Sharpness
        0x01,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
        &IGModes[IG_CAD],
        &HHModes[HH_MODE_CAD],
        &HSModes[HS_MODE_CAD],
        NULLPTR, // HI Table
    },
#endif
#if	ENABLE_PICTURE_MODE_ANIMATION == ON
{// Benq Animation
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
    0x90,    // Saturation
        0x80,    // Intensity
    0x82,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
    0x01,    // Sharpness
    0x01,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
    	&IGModes[IG_ANIMATION],
        &HHModes[HH_MODE_ANIMATION],
        &HSModes[HS_MODE_ANIMATION],
        NULLPTR, // HI Table
    },
#endif
#if	ENABLE_PRESENTATION_MODE == ON
{// Benq Presentation
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
        0x80,    // Saturation
        0x80,    // Intensity
        0x80,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
        0x00,    // Sharpness
        0x00,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
        &IGModes[IG_PRESENTATION],
        &HHModes[HH_MODE_PRESENTATION],
        &HSModes[HS_MODE_PRESENTATION],
        NULLPTR, // HI Table
    },
#endif    
    {// Benq Low Blue Light
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
        0x98,    // Saturation
        0x80,    // Intensity
        0x82,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
        0x01,    // Sharpness
        0x01,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
        &IGModes[IG_DEFAULT],
        NULLPTR,
        NULLPTR,
        NULLPTR, // HI Table
    },
#if ENABLE_PICTURE_MODE_MOVIE == ON       
    {// Benq Movie
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
        0x90,    // Saturation
        0x80,    // Intensity
        0x82,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
        0x01,    // Sharpness
        0x01,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
        &IGModes[IG_MOVIE],
        &HHModes[HH_MODE_Movie],
        &HSModes[HS_MODE_Movie],
        NULLPTR, // HI Table
        },
#endif        
#if ENABLE_PICTURE_MODE_GAME == ON            
        {/// Benq Game
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
        0x82,    // Saturation
        0x80,    // Intensity
        0x80,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
        0x00,    // Sharpness
        0x00,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
        &IGModes[IG_DEFAULT],
        NULLPTR,
        NULLPTR,
        NULLPTR, // HI Table
        },
#endif 
#if ENABLE_PICTURE_MODE_PHOTO== ON       
        {// Benq Photo
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
        0x82,    // Saturation
        0x80,    // Intensity
        0x80,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
        0x00,    // Sharpness
        0x00,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
        &IGModes[IG_PHOTO],
        &HHModes[HH_MODE_Photo],
        &HSModes[HS_MODE_Photo],
        NULLPTR, // HI Table
    },
#endif  
#if ENABLE_PICTURE_MODE_DARKROOM == ON
    {// Benq DarkRoom
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
        0x80,    // Saturation
        0x80,    // Intensity
        0x80,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
        0x00,    // Sharpness
        0x00,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
        &IGModes[IG_DARKROOM],
        NULLPTR, // HH Table
        NULLPTR, // HS Table
        NULLPTR, // HI Table
    },
#endif
    {// Benq ECO
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
        0x80,    // Saturation
        0x80,    // Intensity
        0x80,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
        0x00,    // Sharpness
        0x00,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
        &IGModes[IG_DEFAULT],
        NULLPTR, // HH Table
        NULLPTR, // HS Table
        NULLPTR, // HI Table        
#if ENABLE_PICTURE_MODE_MBOOK == ON
    },
    {// Benq M-Book
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
    0x90,    // Saturation
        0x80,    // Intensity
    0x82,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
    0x01,    // Sharpness
    0x01,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
    &IGModes[IG_M_BOOK],
    &HHModes[HH_MODE_M_Book],
    &HSModes[HS_MODE_M_Book],
        NULLPTR, // HI Table     
#endif  
    },
    {//OFF
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
        0x80,    // Saturation
        0x80,    // Intensity
        0x80,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
        0x00,    // Sharpness
        0x00,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
        &IGModes[IG_DEFAULT],
        NULLPTR, // HH Table
        NULLPTR, // HS Table
        NULLPTR, // HI Table
    },
};

static code CTGamma CT5800K[5]={
{
	0,	//R_offset
	(-5),	//G_offset
	(-5),	//B_offset
},
{
	0,	//R_offset
	(-3),	//G_offset
	(-3),	//B_offset
},
{
	0,	//R_offset
	0,	//G_offset
	0,	//B_offset
},
{
	0,	//R_offset
	0,	//G_offset
	(2),	//B_offset
},
{
	0,	//R_offset
	2,	//G_offset
	(2),	//B_offset
},
};

static code CTGamma CT9300K[5]={
{
	(-9),//(-15),	//R_offset
	(-7),//(-12),	//G_offset
	0,	//B_offset
},
{
	(-3),//(-8),	//R_offset
	(-4),//(-8),	//G_offset
	0,	//B_offset
},
{
	0,	//R_offset
	0,	//G_offset
	0,	//B_offset
},
{
	4,	//R_offset
	2,	//G_offset
	0,	//B_offset
},
{
	(-12),//6,	//R_offset
	4,	//G_offset
	0,	//B_offset
},

};

static code CTGamma CT6500K[5]={
{
	0,	//R_offset
	(-4),	//G_offset
	(-3),	//B_offset
},
{
	0,	//R_offset
	(-4),	//G_offset
	(-3),	//B_offset
},
{
	0,	//R_offset
	0,	//G_offset
	0,	//B_offset
},
{
	0,	//R_offset
	0,	//G_offset
	0,	//B_offset
},
{
	0,	//R_offset
	0,	//G_offset
	0,	//B_offset
},
};
#else 
static code IGBlock IGModes[NUMBER_IG_MODES] = {
#if defined(AUO_M270DAN02_0)
    {16,   0,  84, 140, 192, 256, 320, 384, 448, 512, 576, 640, 704, 768, 832, 896, 960,1024}, //IG_MOVIE
    {16,   0,  76, 136, 200, 256, 320, 384, 448, 512, 576, 640, 704, 768, 832, 896, 960,1024}, //IG_PHOTO
    {16,   0,  72, 136, 192, 256, 320, 384, 448, 512, 576, 640, 704, 768, 832, 896, 960,1024}, //IG_GAME
#elif defined(AUO_M270DAN02_00B)
        {16,   0,  84, 140, 192, 256, 320, 384, 448, 512, 576, 640, 704, 768, 832, 896, 960,1024}, //IG_MOVIE
        {16,   0,  96, 176, 251, 312, 361, 413, 461, 512, 576, 640, 704, 768, 832, 896, 960, 1024}, //IG_PHOTO
        {16,   0,  80, 152, 216, 272, 332, 389, 448, 512, 576, 640, 704, 768, 832, 896, 960, 1024}, //IG_GAME
#elif defined(AUO_M270DAN01_0)
    {16,   28,  108, 152, 212, 256, 320, 384, 448, 512, 576, 640, 704, 768, 832, 896, 960,1024}, //IG_MOVIE
    {16,   0,  116, 152, 220, 256, 320, 384, 448, 512, 576, 640, 704, 768, 832, 896, 960,1024}, //IG_PHOTO
    {16,   0,  58, 116, 168, 228, 288, 356, 428, 504, 584, 660, 732, 800, 860, 920, 972,1024}, //IG_GAME
#else 
    {16,   28,  108, 152, 212, 256, 320, 384, 448, 512, 576, 640, 704, 768, 832, 896, 960,1024}, //IG_MOVIE
    {16,   0,  116, 152, 220, 256, 320, 384, 448, 512, 576, 640, 704, 768, 832, 896, 960,1024}, //IG_PHOTO
    {16,   0,  58, 116, 168, 228, 288, 356, 428, 504, 584, 660, 732, 800, 860, 920, 972,1024}, //IG_GAME
#endif
    {16,   0,  58, 128, 216, 288, 352, 412, 468, 520, 568, 620, 676, 736, 800, 872, 964,1024}, //IG_RS_CURVE
    {16,   0,  48, 100, 152, 204, 260, 320, 380, 440, 504, 572, 640, 712, 784, 864, 964,1024}, //IG_RC_CURVE
    {16,   0,  84, 164, 240, 312, 384, 452, 520, 584, 648, 708, 764, 820, 876, 928, 976,1024}, //IG_C_CURVE
    {16,   0,  64, 116, 184, 252, 332, 408, 472, 552, 620, 676, 732, 800, 860, 920, 972,1024}, //IG_ANIMATION
    {16,   0,  48, 108, 164, 228, 276, 340, 408, 488, 540, 596, 664, 736, 804, 876, 948,1024}, //IG_NVT_CURVE_2
    {16,   0,  64, 128, 192, 256, 320, 384, 448, 512, 576, 640, 704, 768, 832, 896, 960,1024}, //IG_DEFAULT
};

static code UCHAR DefaultMinIGPoints[] = {
    58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58
};

static code HHBlock HHModes[NUMBER_HH_MODES] = {
#if defined(AUO_M270DAN02_0) //color tune 1107
    {
        24,    //Benq HH Movie
        0x00,        
        0xE8,0x08,0x28,0x0C,
        0xE0,0xA8,0xA8,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x10,
        0x08,0x10,0xFF,0xE8,
    },
    {        //Benq HH Game
        24,
        0x00,
        0x18,0x10,0x20,0x08,
        0x08,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x08,0x08,0x00,
        0x00,0x00,0x00,0x00,
    },
    {        //Benq HH photo
        24,
        0x00,
        0x00,0x10,0x18,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x10,0x08,
        0x00,0x00,0x00,0x00,
    },
#elif defined(AUO_M270DAN02_00B) 
    {
        24,    //Benq HH Movie
        0x00,        
        0x00,0x00,0x00,0x00,
        0x00,0x00,0xF0,0xF5,
        0xF5,0xF8,0xFE,0xFE,
        0xFE,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
    },
    {        //Benq HH Game
        24,
        0x00,
        0x00,0x10,0x08,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0xF0,0xF0,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x10,0x10,

    },
    {        //Benq HH photo
        24,
        0x00,
        0x00,0x10,0x18,0xF5,
        0x00,0xF0,0xF0,0xF0,
        0x00,0x00,0x00,0x00,
        0xF5,0x00,0x00,0x00,
        0x00,0x00,0x10,0x08,
        0x00,0x00,0x15,0x00,
    },    
#elif defined(AUO_M270DAN01_0)    
    {
        24,    //Benq HH Movie
        0x00,        
        0x00,0x00,0x17,0xF0,
        0x32,0x20,0x00,0x30,
        0x00,0xD0,0x9A,0x95,
        0xAD,0xCC,0x17,0x02,
        0x0F,0x00,0x00,0x00,
        0x02,0x10,0x47,0x08,
    },{        //Benq HH Game
        24,
        0x00,
        0x29,0x1B,0x1F,0x16,
        0x55,0x9D,0xD3,0xBB,
        0x50,0x11,0xAF,0xEF,
        0xE3,0xBF,0xFF,0xF0,
        0x3C,0x00,0x00,0x00,
        0xBF,0xD7,0x00,0xD0,
    },{        //Benq HH photo
        24,
        0x00,
        0x00,0x00,0x00,0xF2,
        0x30,0x00,0x05,0x00,
        0x00,0xF2,0xF1,0xF8,
        0x80,0xD0,0xFF,0xE7,
        0x00,0x00,0x00,0x00,
        0xBF,0x00,0x00,0xFF,        
    },
#else   
    {
        24,    //Benq HH Movie
        0x00,        
        0x00,0x00,0x17,0xF0,
        0x32,0x20,0x00,0x30,
        0x00,0xD0,0x9A,0x95,
        0xAD,0xCC,0x17,0x02,
        0x0F,0x00,0x00,0x00,
        0x02,0x10,0x47,0x08,
    },{        //Benq HH Game
        24,
        0x00,
        0x29,0x1B,0x1F,0x16,
        0x55,0x9D,0xD3,0xBB,
        0x50,0x11,0xAF,0xEF,
        0xE3,0xBF,0xFF,0xF0,
        0x3C,0x00,0x00,0x00,
        0xBF,0xD7,0x00,0xD0,
    },{        //Benq HH photo
        24,
        0x00,
        0x00,0x00,0x00,0xF2,
        0x30,0x00,0x05,0x00,
        0x00,0xF2,0xF1,0xF8,
        0x80,0xD0,0xFF,0xE7,
        0x00,0x00,0x00,0x00,
        0xBF,0x00,0x00,0xFF,        
    },
#endif    
    {         //Benq HH M-Book
        24,
        0x00,
        0x00,0x04,0x02,0x04,
        0x18,0x20,0x83,0x04,
        0x08,0x04,0x00,0x00,
        0x00,0x08,0x10,0x08,
        0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x10,
    },
};

static code HSBlock HSModes[NUMBER_HS_MODES] = {
#if defined(AUO_M270DAN02_0) //color tune 1107
    {
        24,        //Benq HS Movie
        0x00,
        0x84,0x70,0x78,0x80,
        0x90,0x80,0x80,0x80,
        0x78,0x78,0x78,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x80,
    },{
        24,        //Benq HS Game
        0x00,
        0x94,0x90,0x90,0x88,
        0x88,0x80,0x80,0x80,
        0x80,0x88,0x88,0x88,
        0x80,0x80,0x88,0x80,
        0x80,0x88,0x88,0x80,
        0x80,0x80,0x88,0x88,
    },{
        24,        //Benq HS Photo
        0x00,
        0x84,0x88,0x88,0x88,
        0x88,0x80,0x80,0x80,
        0x80,0x84,0x84,0x84,
        0x80,0x80,0x84,0x80,
        0x80,0x88,0x88,0x80,
        0x80,0x80,0x80,0x80,
    },
#elif defined(AUO_M270DAN02_00B) //color tune 1107
{
    24,        //Benq HS Movie
    0x00,
    0x70,0x70,0x70,0x70,
    0x70,0x75,0x75,0x75,
    0x75,0x75,0x75,0x80,
    0x80,0x80,0x80,0x80,
    0x80,0x80,0x80,0x80,
    0x70,0x70,0x70,0x70,
},{
    24,        //Benq HS Game
    0x00,
    0x78,0x78,0x70,0x75,
    0x80,0x80,0x78,0x78,
    0x78,0x75,0x70,0x80,
    0x80,0x80,0x75,0x80,
    0x80,0x88,0x88,0x80,
    0x80,0x78,0x83,0x80,

    
},{
    24,        //Benq HS Photo
    0x00,
    0x78,0x75,0x75,0x76,
    0x80,0x75,0x80,0x80,
    0x78,0x78,0x80,0x80,
    0x70,0x80,0x80,0x80,
    0x80,0x80,0x80,0x80,
    0x80,0x80,0x80,0x80,
},
#elif defined(AUO_M270DAN01_0)    
    {
        24,        //Benq HS Movie
        0x00,
        0x80,0x80,0x80,0x80,
        0x80,0x60,0x70,0x90,
        0x70,0x70,0x80,0x80,
        0x80,0x90,0xA0,0x80,
        0x80,0x80,0x80,0x80,
        0xA0,0xA0,0xA0,0xA0,		
    },{
        24,        //Benq HS Game
        0x00,
        0xC0,0xB0,0x80,0xA0,
        0x80,0x80,0x80,0x80,
        0xB0,0xB0,0xB0,0xB0,
        0xB0,0xA0,0xA0,0xB0,
        0xA0,0x80,0x80,0x80,
        0x80,0x80,0x70,0xA0,
    },{
        24,        //Benq HS Photo
        0x00,
        0x90,0xA0,0x80,0x90,
        0x80,0x90,0xA0,0x8A,
        0x80,0x80,0x80,0x80,
        0x80,0x90,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0xA0,0x90,0x80,
    },
#else    
    {
        24,        //Benq HS Movie
        0x00,
        0x80,0x80,0x80,0x80,
        0x80,0x60,0x70,0x90,
        0x70,0x70,0x80,0x80,
        0x80,0x90,0xA0,0x80,
        0x80,0x80,0x80,0x80,
        0xA0,0xA0,0xA0,0xA0,		
    },{
        24,        //Benq HS Game
        0x00,
        0xC0,0xB0,0x80,0xA0,
        0x80,0x80,0x80,0x80,
        0xB0,0xB0,0xB0,0xB0,
        0xB0,0xA0,0xA0,0xB0,
        0xA0,0x80,0x80,0x80,
        0x80,0x80,0x70,0xA0,
    },{
        24,        //Benq HS Photo
        0x00,
        0x90,0xA0,0x80,0x90,
        0x80,0x90,0xA0,0x8A,
        0x80,0x80,0x80,0x80,
        0x80,0x90,0x80,0x80,
        0x80,0x80,0x80,0x80,
        0x80,0xA0,0x90,0x80,
    },
#endif    
    {
        24,         //Benq HS M-book
        0x00,
        0x8e,0x90,0x70,0xA0,
        0xa8,0xa8,0x98,0x88,
        0x90,0x88,0x80,0x80,
        0x80,0x90,0xa0,0x90,
        0x80,0x80,0x80,0x80,
        0x80,0x80,0x80,0x90,
    },
};

static code CMBlock CMModes[PICTURE_MODE_NUM] = {
   {// Benq Standard
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
        0x80,    // Saturation
        0x80,    // Intensity
        0x80,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
        0x00,    // Sharpness
        0x00,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
        &IGModes[IG_DEFAULT],
        NULLPTR, // HH Table
        NULLPTR, // HS Table
        NULLPTR, // HI Table
    },{// Benq Low Blue Light
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
        0x98,    // Saturation
        0x80,    // Intensity
        0x82,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
        0x01,    // Sharpness
        0x01,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
        &IGModes[IG_DEFAULT],
        NULLPTR,
        NULLPTR,
        NULLPTR, // HI Table
    },{// Benq Movie
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
        0x90,    // Saturation
        0x80,    // Intensity
        0x82,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
        0x01,    // Sharpness
        0x01,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
        &IGModes[IG_MOVIE],
        &HHModes[HH_MODE_1],
        &HSModes[HS_MODE_1],
        NULLPTR, // HI Table
    },{/// Benq Game
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
        0x82,    // Saturation
        0x80,    // Intensity
        0x80,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
        0x00,    // Sharpness
        0x00,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
#if defined(AUO_M270DAN02_0) //color tune 1107
        &IGModes[IG_GAME],
#elif defined(AUO_M270DAN02_00B)
        &IGModes[IG_GAME],        
#else        
        &IGModes[IG_DEFAULT],
#endif        
        &HHModes[HH_MODE_2],
        &HSModes[HS_MODE_2],
        NULLPTR, // HI Table
    },{// Benq Photo
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
        0x82,    // Saturation
        0x80,    // Intensity
        0x80,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
        0x00,    // Sharpness
        0x00,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
        &IGModes[IG_PHOTO],
        &HHModes[HH_MODE_3],
        &HSModes[HS_MODE_3],
        NULLPTR, // HI Table
    },
    {// Benq SRGB
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
        0x80,    // Saturation
        0x80,    // Intensity
        0x80,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
        0x00,    // Sharpness
        0x00,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
        &IGModes[IG_DEFAULT],
        NULLPTR, // HH Table
        NULLPTR, // HS Table
        NULLPTR, // HI Table
    },{// Benq ECO
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
        0x80,    // Saturation
        0x80,    // Intensity
        0x80,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
        0x00,    // Sharpness
        0x00,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
        &IGModes[IG_DEFAULT],
        NULLPTR, // HH Table
        NULLPTR, // HS Table
        NULLPTR, // HI Table        
#if ENABLE_PICTURE_MODE_MBOOK == ON
    },{// Benq M-Book
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
        0x80,    // Saturation
        0x80,    // Intensity
        0x80,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
        0x00,    // Sharpness
        0x00,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
        &IGModes[IG_DEFAULT],
        &HHModes[HH_MODE_4],
        &HSModes[HS_MODE_4],
        NULLPTR, // HI Table     
#endif  
    },{//OFF
        0x80,    //R Offset
        0x80,    //G Offset
        0x80,    //B Offset
        0x80,    //R Gain
        0x80,    //G Gain
        0x80,    //B Gain
        0x80,    // Saturation
        0x80,    // Intensity
        0x80,    // Hue
        0x80,    // BlueMore
        0x80,    // GreenMore
        0x80,    // RedMore
        0x00,    // FTMore
        0x00,    // Sharpness
        0x00,    // Peaking
        0x00,    // TextEn
        BF_COLOR_INIT,
        &IGModes[IG_DEFAULT],
        NULLPTR, // HH Table
        NULLPTR, // HS Table
        NULLPTR, // HI Table
    },
};
static code CTGamma CT5800K[5]={
{
	0,	//R_offset
	0,	//G_offset
	0,	//B_offset
},
{
	0,	//R_offset
	0,	//G_offset
	0,	//B_offset
},
{
	0,	//R_offset
	0,	//G_offset
	0,	//B_offset
},
{
	0,	//R_offset
	0,	//G_offset
	0,	//B_offset
},
{
	0,	//R_offset
	0,	//G_offset
	0,	//B_offset
},
};

static code CTGamma CT9300K[5]={
{
	0,	//R_offset
	0,	//G_offset
	0,	//B_offset
},
{
	0,	//R_offset
	0,	//G_offset
	0,	//B_offset
},
{
	0,	//R_offset
	0,	//G_offset
	0,	//B_offset
},
{
	0,	//R_offset
	0,	//G_offset
	0,	//B_offset
},
{
	0,	//R_offset
	0,	//G_offset
	0,	//B_offset
},
};
static code CTGamma CT6500K[5]={
{
	0,	//R_offset
	0,	//G_offset
	0,	//B_offset
},
{
	0,	//R_offset
	0,	//G_offset
	0,	//B_offset
},
{
	0,	//R_offset
	0,	//G_offset
	0,	//B_offset
},
{
	0,	//R_offset
	0,	//G_offset
	0,	//B_offset
},
{
	0,	//R_offset
	0,	//G_offset
	0,	//B_offset
},
};
#endif

//=== AOC ===
#define ACE_PARTITIONS 16 // 4,8,16
#define BF_DYNAMIC_ARRAY
#define BF_SMOOTH_AUTOACE
#define BF_DYNAMIC_ACC_TIME     5

static code long float BF_H[7]={0.125,0.21,0.25,0.333,0.5,0.5,1};
static code long float BF_V[7]={0.125,0.21,0.25,0.333,0.5,1,1};
static code UCHAR BrightnessTab[]={ 90,20,40,60,80,100};
static code UCHAR ContrastTab[]=  { 50,50,50,50,50,50};
static xdata USHRT usBFWindowWidth = PANEL_WIDTH;
static xdata USHRT usBFWindowHeight= PANEL_HEIGHT;
static xdata USHRT usBFWindowBegin = 0;

//static xdata UCHAR ucAOC_ColorConfig_Byte;
extern xdata ULONG ulCurHisgrmTotal;
extern xdata USHRT usCurHisgrm[BF_IG_PARTITIONS];
BOOL Standard_Gamma = 0;
//******************************************************************************
// Prototype: 
//  void InitColor(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Color setting initialization.
// Notes:
//  None
//******************************************************************************
void InitColor(void)
{
    #if ENABLE_CM2 == ON
        BFAPI_Init(BF_TWO_GEN);
    #else
        BFAPI_Init(BF_ONE_GEN);
    #endif
        BFAPI_SetActiveWindow(BF_WINDOW_1);

#ifdef NVT_72314_3840X2160_FP//using sRGB 1:1 BF2 to cover Y issue 
   // BFAPI_SetActiveWindow(BF_WINDOW_2);
    //BFAPI_SetWindowSize(BF_WINDOW_FULLSCREEN);
   // BFAPI_EnableWindow(BF_WINDOW_2);    
   // MTXAPI_SelMatrix(MTX_LOCAL);
   // MTXAPI_EnableLocalMatrix(TRUE);
   // MTXAPI_SetRGBGain(128,128,128);      

#endif
        // Always access global 3x3 matrix when adjust contrast and colortemp.
        // P.S. MTXAPI_EnableLocalMatrix must be after BFAPI_Init.
        MTXAPI_SelMatrix(MTX_GLOBAL);
    //MTXAPI_EnableLocalMatrix(FALSE);
}
    
//******************************************************************************
// Prototype: 
//  void SetThemeMode(UCHAR mode)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Set Color Theme
// Notes:
//  None
//******************************************************************************
void SetThemeMode(UCHAR mode)
{
    //UCHAR tmp = GetSPIIndex();
#if ENABLE_PICTURE_DUAL_MODE == ON
  if(Custom_System.bDualviewAdjust == TRUE){
        BFAPI_SetActiveWindow(BF_WINDOW_2);    
    }
    else
#endif
    {
        BFAPI_SetActiveWindow(BF_WINDOW_1);    
    }
    BFAPI_EnableCM(CM_ALL);
    BFAPI_SetROffset(CMModes[mode].ROffset);
    BFAPI_SetGOffset(CMModes[mode].GOffset);
    BFAPI_SetBOffset(CMModes[mode].BOffset);
    BFAPI_SetRGain(CMModes[mode].RGain);
    BFAPI_SetGGain(CMModes[mode].GGain);
    BFAPI_SetBGain(CMModes[mode].BGain);
    if(mode == PICTURE_MODE_USER){
        UserSetSaturation();
        UserSetHue();    
    }
    else{
        BFAPI_SetHue(CMModes[mode].Hue);
        BFAPI_SetSaturation(CMModes[mode].Saturation);
    }
    BFAPI_SetIntensity(CMModes[mode].Intensity);
    BFAPI_CorrectFleshTone(CMModes[mode].FTMore);
    BFAPI_EnhanceRed(CMModes[mode].RedMore);
    BFAPI_EnhanceGreen(CMModes[mode].GreenMore);
    BFAPI_EnhanceBlue(CMModes[mode].BlueMore);
    //UserSetSharpness();//BFAPI_SetSharpness(CMModes[mode].Sharpness);
    BFAPI_SetYPeaking(CMModes[mode].Peaking);
    BFAPI_SetTextEnhancement(CMModes[mode].TextEn);
    BFAPI_ColorEnhance(CMModes[mode].ClrMode);
    if (!UserData.bDCRMode) {
        BFAPI_SetPreACEMode(CMModes[mode].pIG);
    }
    BFAPI_SetHHTable(CMModes[mode].pHH);
    BFAPI_SetHSTable(CMModes[mode].pHS);
    BFAPI_SetHITable(CMModes[mode].pHI);
    
    //SelectSPIIndex(_All);
    SetDemo();    //Set Window Size
#if ENABLE_PICTURE_DUAL_MODE == ON
  if(Custom_System.bDualviewAdjust == TRUE){
        BFAPI_EnableWindow(BF_WINDOW_2);    
    }
    else
#endif
    {
        BFAPI_EnableWindow(BF_WINDOW_1);    
    }
    //SelectSPIIndex(tmp);     
}

#ifdef DBC_ULTRA_LOW
//******************************************************************************
// Prototype: 
//  static BOOL IsBlankVideo(void)
// Parameters:
//  None
// Return:
//  Return TRUE/FALSE
// Purpose:
//  Check the current input video is blank or not.
// Notes:
//  None
//******************************************************************************
static BOOL IsBlankVideo(void)
{
#if ((ENABLE_HDMI == ON) || (INPUT_INTERFACE&INPUT_DP) || (INPUT_INTERFACE&INPUT_DP1))
#define Y_Sample_Cnt 4
#define BLACK_PATTERN_THD 26//10
#define BLACK_PATTERN_MAXTHD 26//16

    static BOOL blank_flag = FALSE;
    UCHAR Yavg, Ymax;

    if ((SC_DBC_CTRL&BIT0) == 0x00)  {
        SC_DBC_CTRL |= BIT0;
        SC_DBC_CTRL &= ~BIT1;
    }

    Yavg = SC_DBC_AVG_Y;
    Ymax = SC_EFFECTIVE_COLOR_VALUE;
    
  //  printf("Yavg Ymax=%d,%d\r\n",(USHRT)Yavg,(USHRT)Ymax);
    if (Yavg < BLACK_PATTERN_THD && Ymax < BLACK_PATTERN_MAXTHD) {
        blank_flag = TRUE;
    }
    else {
        blank_flag = FALSE;
    }
/*
    WaitDisVSync();
    SC_BYPASS_CTRL |= BIT2;
    Sleep(25);
    SC_DBC_CTRL = tmpreg;
    Sleep(25);
    WaitDisVSync();
    SC_BYPASS_CTRL &= ~BIT2;
*/
    return blank_flag;
#else
    static BOOL blank_flag = FALSE;
    UCHAR rcode, gcode, bcode;

    if (DCR_IsReadyToGetMax()) {
        rcode = DCR_GetRMax();
        gcode = DCR_GetGMax();
        bcode = DCR_GetBMax(); 

        if ((rcode < DBC_LTHD_BLANK) && (gcode < DBC_LTHD_BLANK) && (bcode < DBC_LTHD_BLANK)) {
            blank_flag = TRUE;
        }
        else if ((rcode > DBC_HTHD_BLANK) || (gcode > DBC_HTHD_BLANK) || (bcode > DBC_HTHD_BLANK)) {
            blank_flag = FALSE;
        }
    }

    return blank_flag;
#endif    
}

#if 0
//******************************************************************************
// Prototype:
//  static void PerformDBC(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Periodic DBC routine
// Notes:
//  None
//******************************************************************************
static void PerformDBC(void)
{
    static BOOL is_spr_dcr = FALSE;
    static xdata USHRT local_timer = 0;

    if (!IsBlankVideo()) {
        local_timer = GetTimerTick();

        if (is_spr_dcr) {
            is_spr_dcr = FALSE;
            DCR_ResetDymBacklight(0);
        }
    }
    else {
        if ((GetTimerTick() - local_timer) > DBC_TIME_TO_OFF) {
            local_timer = GetTimerTick();
            if (is_spr_dcr == FALSE) {
                is_spr_dcr = TRUE;
                SetBrightness(DBC_BACKLIGHT_OFF);
            }
        }
    }

    if (is_spr_dcr == FALSE) {
        DCR_SetDymBacklight();
    }
}
#endif
#endif
//******************************************************************************
// Prototype:
//  void PerformDCR(UCHAR reset)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Periodic DCR routine
// Notes:
//  None
//******************************************************************************
#if 0//BF_DYNAMIC_BACKLIGHT==1
       #define DCR_OFFBKL              ON 
        #define DCR_Black_Degree_1 11//10  // Totaol Histogram - Histogram[0]
    #define DCR_Black_Degree_2 400//10  // Totaol Histogram - Histogram[0]
    #define DCR_White_Level_1  15// 1   // the biggest white level 0~255 in a frame
    #define DCR_White_Level_2 18     // 5 // the biggest white level 0~255 in a frame
    #define MX_DCR_Transit_Speed 1
    
    USHRT usDCRStableCount = 0;
    USHRT usDCRStableCount2 = 0;
    static UCHAR ucNewDynBk = 0;//ucNewDynBk : new brightness value on OSD
    //iCurDynBk : current brightness value on OSD
    void BF_SetDymBacklight(void);
#endif
#if 0
void PerformDCR(UCHAR reset)
{
    if (reset) {
        DCR_SetDynACEType(ACE_SMOOTH);
        DCR_SetDynACEPnts(DefaultMinIGPoints);//v31_110803_0930_SYS#1
    }

    if (UserData.bDCRMode) {
        DCR_UpdateHistogram(reset);
        
#if BF_DYNAMIC_BACKLIGHT == 0
        DCR_SetDymACE(reset);
        if (reset) {
            DCR_ResetDymBacklight(GetBrightness1023());
        }
        else {
           DCR_SetDymBacklight();
        }
#else
        if (reset) {
   #if NT72314_RST_PORT ==  MCU_PORT_NULL       
            SC_DBC_CTRL = 0x01;
   #endif
            DCR_ResetDymBacklight(GetBrightness1023());
        }
        else {
        #ifdef DBC_ULTRA_LOW
            PerformDBC();
        #else
            //DCR_GetHistogram();
            BF_SetDymBacklight();
        #endif
        }
#endif
        }
   if (AOC_ColorBoostBuffer.bTempAutoDetect) {
            BF_SetDymACEMode(0);
    }
    
}
#endif
//******************************************************************************
// Prototype:
//  void DCR_BenQ_SetDymBacklight(UCHAR reset)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Periodic DCR routine
// Notes:
//  None
//******************************************************************************
#define DCR_BenQ_BKSTEP 4 //2010-12-21, 
#define DBC_MAX_BACKLIGHT 1023
#if ENABLE_BENQ_DCR
#define DBC_MIN_BACKLIGHT 550//200
#else
#define DBC_MIN_BACKLIGHT 500
#endif
#if defined(AUO_M240HW02_V1)
#define DCR_LEVEL_1 DBC_MAX_BACKLIGHT*0.04//0.205
#define DCR_LEVEL_2 DBC_MAX_BACKLIGHT*0.02//0.179
#define DCR_LEVEL_3 DBC_MAX_BACKLIGHT*0.01//0.150//0.154
#define DCR_LEVEL_4 DBC_MAX_BACKLIGHT*0.005//0.123//0.128 
#define DCR_LEVEL_5 DBC_MAX_BACKLIGHT*0.005//0.082//0.107
#else //if defined(AUO_M270HW02_V0) 
#define DCR_LEVEL_1 DBC_MAX_BACKLIGHT*0.04
#define DCR_LEVEL_2 DBC_MAX_BACKLIGHT*0.03
#define DCR_LEVEL_3 DBC_MAX_BACKLIGHT*0.02
#define DCR_LEVEL_4 DBC_MAX_BACKLIGHT*0.01
#define DCR_LEVEL_5 DBC_MAX_BACKLIGHT*0.01
#endif

//static xdata DBCType ucDBCMode = DBC_MODE3;
static xdata USHRT usTargetBacklight = DBC_MAX_BACKLIGHT;
static xdata USHRT usCurrentBacklight;
static BOOL bSuperDCR = FALSE;
static xdata USHRT usSuperDCRTimer = 0;
static BOOL bForceSetBK = FALSE;
static BOOL bInitDCR = FALSE;

#if ENABLE_BENQ_DCR
static xdata USHRT usDBCMinBackLight = DBC_MIN_BACKLIGHT;
#endif
void DCR_BenQ_Reset(void)
{

    usTargetBacklight = DBC_MAX_BACKLIGHT;
    usCurrentBacklight = GetBrightness1023();
}
void DCR_BenQ_SetDymBacklight(void)
{
    USHRT tmp;
    static UCHAR ucUpdateBK = 0;
    if (ulCurHisgrmTotal == 0)
        return;
    
#if ENABLE_BENQ_DCR
    usDBCMinBackLight = DBC_MIN_BACKLIGHT - ((USHRT)UserData.ucDynamicContrast) * 100; 
    if (IsHDMI())
        tmp = (ulCurHisgrmTotal-(usCurHisgrm[0]+usCurHisgrm[1]))*(DBC_MAX_BACKLIGHT-usDBCMinBackLight)/ulCurHisgrmTotal+usDBCMinBackLight;
    else
        tmp = (ulCurHisgrmTotal-usCurHisgrm[0])*(DBC_MAX_BACKLIGHT-usDBCMinBackLight)/ulCurHisgrmTotal+usDBCMinBackLight;

    if (tmp != usTargetBacklight) {
        usTargetBacklight = tmp;
        if (usTargetBacklight < usDBCMinBackLight)
            usTargetBacklight = usDBCMinBackLight;
        else if (usTargetBacklight > DBC_MAX_BACKLIGHT)
            usTargetBacklight = DBC_MAX_BACKLIGHT;
    }

#if DCR_SMOOTH_PWM==ON
    if ((IsBlankVideo() == TRUE) && (usTargetBacklight == usDBCMinBackLight) && (usCurrentBacklight == usDBCMinBackLight)) { //Harry-2010-04-01: For Supper DCR
#else
    if ((IsBlankVideo() == TRUE) && (OSDAPI_IsOSDOn() == FALSE) && (usTargetBacklight == usDBCMinBackLight) && (usCurrentBacklight == usDBCMinBackLight)) { //Harry-2010-04-01: For Supper DCR
#endif

#else /*24" panel */
    tmp = (ulCurHisgrmTotal-usCurHisgrm[0])*
          (DBC_MAX_BACKLIGHT-DBC_MIN_BACKLIGHT)/
          ulCurHisgrmTotal+DBC_MIN_BACKLIGHT;

    if (tmp != usTargetBacklight) {
        usTargetBacklight = tmp;
        if (usTargetBacklight < DBC_MIN_BACKLIGHT)
            usTargetBacklight = DBC_MIN_BACKLIGHT;
        else if (usTargetBacklight > DBC_MAX_BACKLIGHT)
            usTargetBacklight = DBC_MAX_BACKLIGHT;
    }
#if DCR_SMOOTH_PWM==ON 
    if ((IsBlankVideo() == TRUE) && (usTargetBacklight == DBC_MIN_BACKLIGHT) && (usCurrentBacklight == DBC_MIN_BACKLIGHT)) { //Harry-2010-04-01: For Supper DCR
#else
    if ((IsBlankVideo() == TRUE) && (OSDAPI_IsOSDOn() == FALSE) && (usTargetBacklight == DBC_MIN_BACKLIGHT) && (usCurrentBacklight == DBC_MIN_BACKLIGHT)) { //Harry-2010-04-01: For Supper DCR
#endif

#endif /*panel size */
        if (((GetTimerTick() - usSuperDCRTimer) > 3000) && (OSDAPI_IsOSDOn() == FALSE)) { //Harry-2010-04-04: Wait 3 Secs then enter Supper DCR
            if (bSuperDCR == FALSE) {
                bSuperDCR = TRUE;
                bForceSetBK = TRUE;
            }
        }
#if DCR_SMOOTH_PWM==ON
        if ((OSDAPI_IsOSDOn() == TRUE) && (IsBackLightOn() == FALSE)) { //when super dcr 5, and user call OSD On
            BacklightOn();
            usTargetBacklight = DBC_MAX_BACKLIGHT;
        }
#endif
    }
    else {
        usSuperDCRTimer = GetTimerTick();
        if (bSuperDCR == TRUE) {
            BacklightOn(); //Harry-2010-08-20: Whatever LED or Non-LED Panel We always use black light off to do SuperDCR, Recover from SuperDCR, must use BacklightOn();
            bSuperDCR = FALSE;
            bForceSetBK = TRUE;
        }
    }

    //Harry-2010-04-08: Add "&& (bForceSetBK == FALSE)" for little change pattern into ALL BLACK still can enter SuperDCR
    //Harry-2010-07-01: Add "&& (usTargetBacklight != usDBCMinBackLight)" for Enter SuperDCR do not be blocked here.

#if ENABLE_BENQ_DCR
    if ( (abs(usCurrentBacklight - usTargetBacklight) < 100) && (ucUpdateBK == 0) && (bForceSetBK == FALSE) && (usTargetBacklight != usDBCMinBackLight) ) {
        return;
    }
#else
    if ( (abs(usCurrentBacklight - usTargetBacklight) < 100) && (ucUpdateBK == 0) && (bForceSetBK == FALSE) && (usTargetBacklight != DBC_MIN_BACKLIGHT) ) {
        return;
    }
#endif

#if DCR_SMOOTH_PWM==ON
    if ((ucUpdateBK == 0) && //(bForceSetBK == FALSE) && 
        (bSuperDCR==TRUE) &&  (UserData.ucDynamicContrast==5) && (OSDAPI_IsOSDOn() == FALSE)) {              
        BacklightOff();
    }
#endif

    ucUpdateBK = 1;
    if ((usCurrentBacklight != usTargetBacklight) || (bForceSetBK == TRUE)) { //Harry-2010-04-08: Add "|| (bForceSetBK == TRUE)" for little change pattern into ALL BLACK still can enter SuperDCR 
        if (abs(usCurrentBacklight - usTargetBacklight) < 512) {
            if (usCurrentBacklight < usTargetBacklight) {
                if (abs(usTargetBacklight - usCurrentBacklight) >= DCR_BenQ_BKSTEP)
                    usCurrentBacklight+=DCR_BenQ_BKSTEP;
                else
                    usCurrentBacklight = usTargetBacklight;
            }
            else {
                if (abs(usTargetBacklight - usCurrentBacklight) >= DCR_BenQ_BKSTEP)
                    usCurrentBacklight-=DCR_BenQ_BKSTEP;
                else
                    usCurrentBacklight = usTargetBacklight;
            }
        }
        else {
            if (usCurrentBacklight < usTargetBacklight) {
                usCurrentBacklight = usTargetBacklight;
            }
            else {
                if (abs(usTargetBacklight - usCurrentBacklight) >= DCR_BenQ_BKSTEP)
                    usCurrentBacklight-=DCR_BenQ_BKSTEP;
                else
                    usCurrentBacklight = usTargetBacklight;
            }
        }

        SetDBCBacklight(usCurrentBacklight, bSuperDCR);
        bForceSetBK = FALSE;
    }
    else
        ucUpdateBK = 0;
}

//******************************************************************************
// Prototype:
//  void DCR_BenQ_ResetDynBacklight(USHRT backlight)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Periodic DCR routine
// Notes:
//  None
//******************************************************************************

void DCR_BenQ_ResetDynBacklight(USHRT backlight)
{
    usCurrentBacklight = backlight;
    DCR_BenQ_SetDymBacklight();
}


//******************************************************************************
// Prototype:
//  void DCR_BenQ_FroceSetBk()
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Force to set backlight immediately if user change DCR_LEVEL
// Notes:
//  None
//******************************************************************************

void DCR_BenQ_FroceSetBk()
{
    bForceSetBK = 1;
}

//******************************************************************************
// Prototype:
//  BOOL DCR_BenQ_Init()
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Force to set backlight immediately if user change DCR_LEVEL
// Notes:
//  None
//******************************************************************************

BOOL DCR_BenQ_Init()
{
    if ( !bInitDCR ) {
        bInitDCR = TRUE;
//        usCurrentBacklight = GetScalerPWM(BKL_PWM_PORT);
        return TRUE;
    }
    return FALSE;
}
//******************************************************************************
// Prototype:
//  void PerformDCR(UCHAR reset)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Periodic DCR routine
// Notes:
//  None
//******************************************************************************
#if 1//!lrd_dis_benq
void PerformDCR(UCHAR reset)
{
    if (reset) {
        DCR_SetDynACEType(ACE_SMOOTH);
    }

    //if (UserData.bDCRMode) {
    if ( UserData.ucDynamicContrast > 0 ) {
        DCR_UpdateHistogram(reset);
        DCR_SetDymACE(reset);
        if (reset) {
#if 1//BF_DYNAMIC_BACKLIGHT == ON
            WaitDisVSync();
            SC_BYPASS_CTRL |= BIT2;
            Sleep(25);
            SC_DBC_CTRL = 0x01;
            Sleep(25);
            WaitDisVSync();
            SC_BYPASS_CTRL &= ~BIT2;
#endif
#if DCR_SMOOTH_PWM==ON
            DCR_BenQ_ResetDynBacklight(GetScalerPWM(BKL_PWM_PORT));
#else
            DCR_BenQ_ResetDynBacklight(GetBrightness1023());
#endif
        }
        else {
            DCR_BenQ_SetDymBacklight();
        }
    }
}
#else
static void PerformDBC(void)
{
    static BOOL is_spr_dcr = FALSE;
    static xdata USHRT local_timer = 0;

    if (!IsBlankVideo()) {
        local_timer = GetTimerTick();

        if (is_spr_dcr) {
            is_spr_dcr = FALSE;
            DCR_ResetDymBacklight(0);
        }
    }
    else {
        if ((GetTimerTick() - local_timer) > DBC_TIME_TO_OFF) {
            local_timer = GetTimerTick();
            if (is_spr_dcr == FALSE) {
                is_spr_dcr = TRUE;
                SetBrightness(DBC_BACKLIGHT_OFF);
            }
        }
    }

    if (is_spr_dcr == FALSE) {
        DCR_SetDymBacklight();
    }
}

void PerformDCR(UCHAR reset)
{
    if (reset) {
        DCR_SetDynACEType(ACE_SMOOTH);
        DCR_SetDynACEPnts(DefaultMinIGPoints);
    }

    if ( UserData.ucDCRMode == BKL_CTRL_DCR ) {
        DCR_UpdateHistogram(reset);
        DCR_SetDymACE(reset);
        if (reset) {
            DCR_ResetDymBacklight(GetBrightness1023());
        }
        else {
        #ifdef DBC_ULTRA_LOW
            PerformDBC();
        #else
            DCR_SetDymBacklight();
        #endif
        }
    }
}

#endif
//******************************************************************************
// Prototype: 
//  void DisableDCR(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Recall brightness setting while turn off DCR function
// Notes:
//  None
//******************************************************************************
void DisableDCR(void)
{
//    UserSetBF();
    UserSetBrightness();
}

//******************************************************************************
// Prototype: 
//  void DisableDCR(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Recall brightness setting while turn off DCR function
// Notes:
//  None
//******************************************************************************
//void DisableDCR(void)
//{
//#if BF_DYNAMIC_BACKLIGHT==ON
//   #if NT72314_RST_PORT ==  MCU_PORT_NULL       
//      SC_DBC_CTRL = 0x00; //Laurence Mark,dont operate 0x430 at normal display
//   #endif
//#endif
//    UserSetBF();
//    UserSetBrightness();
//}

//******************************************************************************
// Prototype: 
//  void SetDBCBacklight(USHRT brightness, BOOL bSuperDCR)
// Parameters:
//  brightness : range is 0~1023
// Return:
//  None
// Purpose:
//  This is call-back function for ColorEngine library.
// Notes:
//  None
//******************************************************************************
void SetDBCBacklight(USHRT brightness, BOOL bSuperDCR)
{
    code USHRT SuperDCRLevel[6] = {
        DBC_MAX_BACKLIGHT,
        DCR_LEVEL_1,
        DCR_LEVEL_2,
        DCR_LEVEL_3,
        DCR_LEVEL_4,
        DCR_LEVEL_5,
    };

#if ENABLE_BENQ_DCR
    if ((bSuperDCR == TRUE) && (brightness == usDBCMinBackLight)){
//        if(UserData.ucDynamicContrast == 5)
//            BacklightOff(); //Harry-2010-04-04: By Philips Request for Super DCR
        brightness = SuperDCRLevel[UserData.ucDynamicContrast];
    }
    else if (brightness < usDBCMinBackLight) {//Harry-2010-03-17: To avoid backlight shutdown
        brightness = usDBCMinBackLight;
    }
#else
    if ((bSuperDCR == TRUE) && (brightness == DBC_MIN_BACKLIGHT)){
//        if(UserData.ucDynamicContrast == 5)
//            BacklightOff(); //Harry-2010-04-04: By Philips Request for Super DCR
        brightness = SuperDCRLevel[UserData.ucDynamicContrast];
    }
    else if (brightness < DBC_MIN_BACKLIGHT) {//Harry-2010-03-17: To avoid backlight shutdown
        brightness = DBC_MIN_BACKLIGHT;
    }

#endif
    SetBrightness(brightness);
}

//******************************************************************************
// Prototype: 
//  void SetColorTemperature(UCHAR mode)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Set Color Temperature
// Notes:
//  None
//******************************************************************************
#if ENABLE_NVT_FGA == ON
void SetColorTemperature(UCHAR mode)
{
    USHRT r,g,b,GammaTemp;
    UCHAR CTGain[3];	
    GammaTemp = GetGammaNum();//current Gamma no.
    
    
    switch (mode) {
        /*case CLRTMP_5000K:
            r = CalibData.uc5000KRGain;
            g = CalibData.uc5000KGGain;
            b = CalibData.uc5000KBGain;
            break;*/
        default:
        case CLRTMP_6500K:
   	    	LG_FGA_LoadColorTemp(GammaTemp, CT_6500K,&CTGain[0],&CTGain[1],&CTGain[2]);	
            r = CTGain[0];
            g = CTGain[1];
            b = CTGain[2];
			//printf("6500 %d,%d,%d\r\n",(USHRT)r,(USHRT)g,(USHRT)b);	 
            break;
        #if 0
        case CLRTMP_7500K:
            r = CalibData.uc7500KRGain;
            g = CalibData.uc7500KGGain;
            b = CalibData.uc7500KBGain;
            break;
        case CLRTMP_8200K:
            r = CalibData.uc8200KRGain;
            g = CalibData.uc8200KGGain;
            b = CalibData.uc8200KBGain;
            break;
        #endif    
        case CLRTMP_9300K:					
   	    	LG_FGA_LoadColorTemp(GammaTemp, CT_9300K,&CTGain[0],&CTGain[1],&CTGain[2]);						
            r = CTGain[0];
            g = CTGain[1];
            b = CTGain[2];
            //printf("9300 %d,%d,%d\r\n",(USHRT)r,(USHRT)g,(USHRT)b);	 
            break;
        case CLRTMP_5800K:
   	        LG_FGA_LoadColorTemp(GammaTemp, CT_5800K,&CTGain[0],&CTGain[1],&CTGain[2]);									
            r = CTGain[0];
            g = CTGain[1];
            b = CTGain[2];
   	        //printf("5800 %d,%d,%d\r\n",(USHRT)r,(USHRT)g,(USHRT)b);	 
            break;
        #if 0
        case CLRTMP_11500K:
            r = CalibData.uc11500KRGain;
            g = CalibData.uc11500KGGain;
            b = CalibData.uc11500KBGain;
            break;
        #endif
        case CLRTMP_sRGB:
   	        LG_FGA_LoadColorTemp(GammaTemp, CT_6500K,&CTGain[0],&CTGain[1],&CTGain[2]);						
            r = CTGain[0];
            g = CTGain[1];
            b = CTGain[2];
   	        //printf("sRGB %d,%d,%d\r\n",(USHRT)r,(USHRT)g,(USHRT)b);	 
            break;
        case CLRTMP_USER:
            r = (USHRT)GetRGain255();
            g = (USHRT)GetGGain255();
            b = (USHRT)GetBGain255();
            break;
    };  
    
    // To bypass the 3x3 matrix, we need to assign 0x100 to MTXAPI_SetRGBGain.
    // However, the max gain value in this function is 0xFF.
    // So, we plus one to achieve bypassing 3x3 matrix
    // Jude 2011/07/28
#if ENABLE_PICTURE_DUAL_MODE == ON
    if(UserData.ucBFMode == PICTURE_MODE_LOW_BL){
#if ENABLE_LBL_BASE_FGA == OFF
        switch(UserData.ucLBLMode) {
            case MULTIMEDIA:
                r = DEF_MULTIMEDIA_RGain + 1;
                g = DEF_MULTIMEDIA_GGain + 1;
                b = DEF_MULTIMEDIA_BGain + 1;
                break;
            case WEB_SURFING:
                r = DEF_WEB_SURFING_RGain + 1;
                g = DEF_WEB_SURFING_GGain + 1;
                b = DEF_WEB_SURFING_BGain + 1;
                break;
            case OFFICE:
                r = DEF_OFFICE_RGain + 1;
                g = DEF_OFFICE_GGain + 1;
                b = DEF_OFFICE_BGain + 1;
                break;
            case READING:
                r = DEF_READING_RGain + 1;
                g = DEF_READING_GGain + 1;
                b = DEF_READING_BGain + 1;
                break;
#else
        LG_FGA_LoadColorTemp(GammaTemp, CT_6500K,&CTGain[0],&CTGain[1],&CTGain[2]);
        switch(UserData.ucLBLMode) {
            case MULTIMEDIA:
                r = CTGain[0] + DEF_MULTIMEDIA_RGain_Shift+ 1;
                g = CTGain[1] + DEF_MULTIMEDIA_GGain_Shift + 1;
                b = CTGain[2] + DEF_MULTIMEDIA_BGain_Shift + 1;
                break;
            case WEB_SURFING:
                r = CTGain[0] + DEF_WEB_SURFING_RGain_Shift + 1;
                g = CTGain[1] + DEF_WEB_SURFING_GGain_Shift + 1;
                b = CTGain[2] + DEF_WEB_SURFING_BGain_Shift + 1;
                break;
            case OFFICE:
                r = CTGain[0] + DEF_OFFICE_RGain_Shift + 1;
                g = CTGain[1] + DEF_OFFICE_GGain_Shift + 1;
                b = CTGain[2] + DEF_OFFICE_BGain_Shift + 1;
                break;
            case READING:
                r = CTGain[0] + DEF_READING_RGain_Shift + 1;
                g = CTGain[1] + DEF_READING_GGain_Shift + 1;
                b = CTGain[2] + DEF_READING_BGain_Shift + 1;
                break;     
#endif
            default:
                break;     
        }   
#endif
    }    

    MTXAPI_SetRGBGain(r + 1,g + 1,b + 1);
}
#else
void SetColorTemperature(UCHAR mode)
{ 
    USHRT r,g,b,GammaTemp;
    GammaTemp = GetGammaNum();
    switch (mode) {
        /*case CLRTMP_5000K:
            r = CalibData.uc5000KRGain;
            g = CalibData.uc5000KGGain;
            b = CalibData.uc5000KBGain;
            break;*/
        default:
        case CLRTMP_6500K:
            r = CalibData.uc6500KRGain;//+CT6500K[GammaTemp].ROffset;
            g = CalibData.uc6500KGGain;//+CT6500K[GammaTemp].GOffset;
            b = CalibData.uc6500KBGain;//+CT6500K[GammaTemp].BOffset;
            break;
        /*case CLRTMP_7500K:
            r = CalibData.uc7500KRGain;
            g = CalibData.uc7500KGGain;
            b = CalibData.uc7500KBGain;
            break;*/
        /*case CLRTMP_8200K:
            r = CalibData.uc8200KRGain;
            g = CalibData.uc8200KGGain;
            b = CalibData.uc8200KBGain;
            break;*/
        case CLRTMP_9300K:
            r = CalibData.uc9300KRGain;//+CT9300K[GammaTemp].ROffset;
            g = CalibData.uc9300KGGain;//+CT9300K[GammaTemp].GOffset;
            b = CalibData.uc9300KBGain;//+CT9300K[GammaTemp].BOffset;
            break;
        case CLRTMP_5800K:
            r = CalibData.uc5800KRGain;//+CT5800K[GammaTemp].ROffset;
            g = CalibData.uc5800KGGain;//+CT5800K[GammaTemp].GOffset;
            b = CalibData.uc5800KBGain;//+CT5800K[GammaTemp].BOffset;
            break;
            
        /*case CLRTMP_11500K:
            r = CalibData.uc11500KRGain;
            g = CalibData.uc11500KGGain;
            b = CalibData.uc11500KBGain;
            break;*/
        case CLRTMP_sRGB:
            r = CalibData.ucsRGBRGain;//+CT6500K[GammaTemp].ROffset;
            g = CalibData.ucsRGBGGain;//+CT6500K[GammaTemp].GOffset;
            b = CalibData.ucsRGBBGain;//+CT6500K[GammaTemp].ROffset; 
            break;
        case CLRTMP_USER:
            r = (USHRT)GetRGain255();
            g = (USHRT)GetGGain255();
            b = (USHRT)GetBGain255();
            break;
    };  
    
    // To bypass the 3x3 matrix, we need to assign 0x100 to MTXAPI_SetRGBGain.
    // However, the max gain value in this function is 0xFF.
    // So, we plus one to achieve bypassing 3x3 matrix
    // Jude 2011/07/28
    MTXAPI_SetRGBGain(r + 1,g + 1,b + 1);
}
#endif
#if 0
//==== AOC ===============

void SetBF_Brightness(void)
{
    UCHAR tmp;
    tmp = ((USHRT)200*UserData.ucBF_Brightness/100+55);
    BFAPI_SetROffset(tmp);
    BFAPI_SetGOffset(tmp);
    BFAPI_SetBOffset(tmp);
}

void SetBF_Contrast(void)
{
    UCHAR tmp;
   
    tmp = ((USHRT)200*UserData.ucBF_Contrast/100+55);
    BFAPI_SetRGain(tmp);
    BFAPI_SetGGain(tmp);
    BFAPI_SetBGain(tmp);
    
}
#endif


/*

void GetCLRTMP_BriCon(void)
{
    //printf("colortemp=%x\r\n",(USHRT)UserData.ucColorTemp);    
    switch(UserData.ucColorTemp) {
        case CLRTMP_6500K:    
            UserData.ucBrightness = UserData.ucBrightness_6500;
            UserData.ucContrast = UserData.ucContrast_6500;
            break;
        case CLRTMP_9300K:
            UserData.ucBrightness = UserData.ucBrightness_9300;
            UserData.ucContrast = UserData.ucContrast_9300;
            break;
        case CLRTMP_7500K:
            UserData.ucBrightness = UserData.ucBrightness_NORMAL;
            UserData.ucContrast = UserData.ucContrast_NORMAL;
            break;
        case CLRTMP_USER:        
            UserData.ucBrightness = UserData.ucBrightness_USER;
            UserData.ucContrast = UserData.ucContrast_USER;
            break;
        case CLRTMP_sRGB:
            UserData.ucBrightness = UserData.ucBrightness_sRGB;
            UserData.ucContrast = UserData.ucContrast_sRGB;
            break;
        default:
            UserData.ucBrightness = UserData.ucBrightness;
            UserData.ucContrast = UserData.ucContrast;
            break;
      }
}
*/
void SetCLRTMP_BriCon(void)
{
    if(Custom_System.bDualviewAdjust == FALSE){
    switch(UserData.ucBFMode) {
        case PICTURE_MODE_SRGB:
         UserData.ucBrightness_sRGB = UserData.ucBrightness;
         UserData.ucContrast_sRGB = UserData.ucContrast;
            break;
#if	ENABLE_PICTURE_MODE_CAD == ON
        case PICTURE_MODE_CAD: 
            UserData.ucBrightness_CAD= UserData.ucBrightness;
            UserData.ucContrast_CAD = UserData.ucContrast;
            break;
#endif
#if	ENABLE_PICTURE_MODE_ANIMATION == ON
        case PICTURE_MODE_ANIMATION:            
            UserData.ucBrightness_Animation= UserData.ucBrightness;
            UserData.ucContrast_Animation = UserData.ucContrast;
            break;
#endif
#if	ENABLE_PRESENTATION_MODE == ON
        case PICTURE_MODE_PRESENTATION:            
            UserData.ucBrightness_Presentation= UserData.ucBrightness;
            UserData.ucContrast_Presentation = UserData.ucContrast;
            break;
#endif            
        case PICTURE_MODE_STANDARD:
         UserData.ucBrightness_Standard = UserData.ucBrightness;
         UserData.ucContrast_Standard = UserData.ucContrast;
         UserData.ucColorTemp_Standard = UserData.ucColorTemp;         
         break;
#if ENABLE_PICTURE_MODE_REC709 == ON 
        case PICTURE_MODE_REC709:
            UserData.ucBrightness_Rec709= UserData.ucBrightness;
            UserData.ucContrast_Rec709= UserData.ucContrast;            
            break;            
#endif
        case PICTURE_MODE_LOW_BL:
         SetLBLMode_BriCon();
            break;
#if ENABLE_PICTURE_MODE_MOVIE == ON                   
        case PICTURE_MODE_MOVIE:
         UserData.ucBrightness_Movie= UserData.ucBrightness;
         UserData.ucContrast_Movie = UserData.ucContrast;
            break;
#endif
#if ENABLE_PICTURE_MODE_PHOTO== ON       
        case PICTURE_MODE_PHOTO:
         UserData.ucBrightness_Photo= UserData.ucBrightness;
         UserData.ucContrast_Photo = UserData.ucContrast;
            break;
#endif            
#if ENABLE_PICTURE_MODE_GAME == ON            
        case PICTURE_MODE_GAME:
         UserData.ucBrightness_Game = UserData.ucBrightness;
         UserData.ucContrast_Game = UserData.ucContrast;
            break;            
#endif            
#if ENABLE_PICTURE_MODE_DARKROOM == ON 
        case PICTURE_MODE_DARKROOM:
            UserData.ucBrightness_DarkRoom = UserData.ucBrightness;
            UserData.ucContrast_DarkRoom = UserData.ucContrast;            
            break;            
#endif
        case PICTURE_MODE_ECO:
            break;            
#if ENABLE_PICTURE_MODE_MBOOK == ON
        case PICTURE_MODE_MBOOK:
         UserData.ucBrightness_MBOOK= UserData.ucBrightness;
         UserData.ucContrast_MBOOK = UserData.ucContrast;
            break;          
#endif
        case PICTURE_MODE_USER:            
         UserData.ucBrightness_USER = UserData.ucBrightness;
         UserData.ucContrast_USER = UserData.ucContrast;
         UserData.ucColorTemp_USER = UserData.ucColorTemp;         
            break; 
        default:
            break;
    }      
   }
}

void SetCLRTMP_Sharpness(void)
{
    switch(UserData.ucBFMode) {
        case PICTURE_MODE_SRGB:
         UserData.ucSharpness_sRGB = UserData.ucSharpness;
            break;
#if	ENABLE_PICTURE_MODE_CAD == ON
        case PICTURE_MODE_CAD: 
            UserData.ucSharpness_CAD= UserData.ucSharpness;
            break;
#endif
#if	ENABLE_PICTURE_MODE_ANIMATION == ON
        case PICTURE_MODE_ANIMATION:            
            UserData.ucSharpness_Animation= UserData.ucSharpness;
            break;
#endif
#if	ENABLE_PRESENTATION_MODE == ON
        case PICTURE_MODE_PRESENTATION:            
            UserData.ucSharpness_Presentation= UserData.ucSharpness;
            break;
#endif                        
        case PICTURE_MODE_STANDARD:
         UserData.ucSharpness_Standard = UserData.ucSharpness;
         break;
        case PICTURE_MODE_LOW_BL:
         SetLBLMode_Sharpness();
            break;
#if ENABLE_PICTURE_MODE_MOVIE == ON                   
        case PICTURE_MODE_MOVIE:
         UserData.ucSharpness_Movie= UserData.ucSharpness;
            break;
#endif
#if ENABLE_PICTURE_MODE_PHOTO== ON       
        case PICTURE_MODE_PHOTO:
         UserData.ucSharpness_Photo= UserData.ucSharpness;
            break;
#endif            
#if ENABLE_PICTURE_MODE_GAME == ON            
        case PICTURE_MODE_GAME:
         UserData.ucSharpness_Game = UserData.ucSharpness;
            break;            
#endif            
        case PICTURE_MODE_ECO:
            break;            
#if ENABLE_PICTURE_MODE_MBOOK == ON
        case PICTURE_MODE_MBOOK:
         UserData.ucSharpness_MBOOK= UserData.ucSharpness;
            break;          
#endif
        case PICTURE_MODE_USER:            
         UserData.ucSharpness_USER = UserData.ucSharpness;
            break;
#if ENABLE_PICTURE_MODE_REC709== ON
        case PICTURE_MODE_REC709:
         UserData.ucSharpness_Rec709= UserData.ucSharpness;
            break;          
#endif
#if ENABLE_PICTURE_MODE_DARKROOM== ON
        case PICTURE_MODE_DARKROOM:
         UserData.ucSharpness_DarkRoom= UserData.ucSharpness;
            break;          
#endif
        default:
            break;
    }        
}
void SetLBLMode_Sharpness(void)
{
    switch(UserData.ucLBLMode) {
        case MULTIMEDIA:
           UserData.ucSharpness_LBL_Mult = UserData.ucSharpness;
     break;
        case WEB_SURFING:
           UserData.ucSharpness_LBL_Web = UserData.ucSharpness;
     break;
        case OFFICE:
           UserData.ucSharpness_LBL_Office = UserData.ucSharpness;
     break;
        case READING:        
            UserData.ucSharpness_LBL_Read = UserData.ucSharpness;
            break;
        default:
            break;
    }        
}

void SetLBLMode_BriCon(void)
{
    switch(UserData.ucLBLMode) {
        case MULTIMEDIA:
         UserData.ucBrightness_LBL_Mult= UserData.ucBrightness;
         UserData.ucContrast_LBL_Mult = UserData.ucContrast;
     break;
        case WEB_SURFING:
         UserData.ucBrightness_LBL_Web= UserData.ucBrightness;
         UserData.ucContrast_LBL_Web = UserData.ucContrast;
     break;
        case OFFICE:
         UserData.ucBrightness_LBL_Office= UserData.ucBrightness;
         UserData.ucContrast_LBL_Office = UserData.ucContrast;
     break;
        case READING:        
         UserData.ucBrightness_LBL_Read= UserData.ucBrightness;
         UserData.ucContrast_LBL_Read = UserData.ucContrast;            
            break;
        default:
            break;
    }        
}
#if 0
void BF_IdvColorEnhance(BF_IDV_COLOR_EN_MODE mode)
{
    switch(mode) {
        case _BF_IDV_COLOR_EN_NONE_: //normal
            BFAPI_CorrectFleshTone(0x00);
            BFAPI_EnhanceRed(0x80);
            BFAPI_EnhanceGreen(0x80);
            BFAPI_EnhanceBlue(0x80);
            break;
        case _BF_IDV_COLOR_EN_SKIN_:
            BFAPI_CorrectFleshTone(0x4C);
            BFAPI_EnhanceRed(0xC6);
            BFAPI_EnhanceGreen(0x80);
            BFAPI_EnhanceBlue(0x80);
            break;
        case _BF_IDV_COLOR_EN_GREEN_:
            BFAPI_CorrectFleshTone(0x4C);
            BFAPI_EnhanceRed(0x80);
            BFAPI_EnhanceGreen(0xC6);
            BFAPI_EnhanceBlue(0x80);
            break;
        case _BF_IDV_COLOR_EN_BLUE_:
            BFAPI_CorrectFleshTone(0x00);
            BFAPI_EnhanceRed(0x80);
            BFAPI_EnhanceGreen(0x80);
            BFAPI_EnhanceBlue(0xC6);
            break;
        case _BF_IDV_COLOR_EN_ALL_:
            BFAPI_CorrectFleshTone(0x4C);
            BFAPI_EnhanceRed(0x97);
            BFAPI_EnhanceGreen(0x9F);
            BFAPI_EnhanceBlue(0x97);
            break;
    }
}
void BF_SetWindowSize(UCHAR type)
{
#if SCALER_TYPE == NT68671 || SCALER_TYPE == NT68672 || SCALER_TYPE == NT68672
        USHRT x,y,w,h;
        UCHAR temp_position,temp_size;
#endif
    if (AOC_ECOData.ucBFWSize == type) {
        return;
    }
    AOC_ECOData.ucBFWSize = type;
#if SCALER_TYPE == NT68671 || SCALER_TYPE == NT68672 || SCALER_TYPE == NT68672   //v31_110923_1900_SYS#8
        if ((type == 0) || (type == 1)){
            temp_position = 1;
            temp_size = type + 1;
        }    
        else if(type == 2){
            temp_position = 2;
            temp_size = 2;
        }
        else{
            temp_position = 1;
            temp_size = 1;
        }    
        x = ReadShortScaler(&SC_GRAPHIC_DISP_HOR_ACT_WID_LO) -(ReadShortScaler(&SC_GRAPHIC_DISP_HOR_ACT_WID_LO)/temp_position);
        y = 0;
        w = ReadShortScaler(&SC_GRAPHIC_DISP_HOR_ACT_WID_LO)/temp_size;
        h = ReadShortScaler(&SC_GRAPHIC_DISP_VER_ACT_LEN_LO);
        BFAPI_SetCustomWindow(x,y,w,h); 
        AOC_ECOData.ucBFWSize = 0xff;
#else
        BFAPI_SetWindowSize(type);
#endif
    
     
    //if ((ReadIIC560(BRIGHT_FRM_HS_LI)==0x00) &&ucWidemode)
    //{
        //WriteIIC560(BRIGHT_FRM_HS_LI, 0x01);
        //WriteIIC560(BRIGHT_FRM_HS_HI, 0x00);
    //}
}
#endif

#if ENABLE_RECALL_PREVIEW == ON
void BF_SetSize(void) //picture_boost
{
     USHRT xy;
//     xy =  H_ActiveTab[ucResolution]*BF_H[ucBF_Size] ;
     xy =  usBFWindowWidth*BF_H[UserData.ucBF_Size] ;

    SC_BRIGHT_FRM_HW_LO = xy&0xFF;
    SC_BRIGHT_FRM_HW_HI =  xy>>8;

    //WriteIIC560(BRIGHT_FRM_HW_LI, (xy&0xFF));
    //WriteIIC560(BRIGHT_FRM_HW_HI, xy>>8);  

//     xy =  V_ActiveTab[ucResolution]*BF_V[ucBF_Size] ;
     xy =  usBFWindowHeight*BF_V[UserData.ucBF_Size] ;


    SC_BRIGHT_FRM_VH_LO = xy&0xFF;
    SC_BRIGHT_FRM_VH_HI = xy>>8;
}
#endif
#if !lrd_dis
void BF_SetHP(void) //picture_boost
{
USHRT xy;
//    xy = (ULONG)(H_ActiveTab[ucResolution]*(1-BF_H[ucBF_Size])) * ucBF_HP / 100 ;
    xy = (ULONG)(usBFWindowWidth*(1-BF_H[UserData.ucBF_Size])) * UserData.ucBF_HP / 100 ;
    xy += usBFWindowBegin;
    //WriteIIC560(BRIGHT_FRM_HS_LI, (xy&0xFF)+1);
    //WriteIIC560(BRIGHT_FRM_HS_LI, (xy&0xFF));
    //WriteIIC560(BRIGHT_FRM_HS_HI, xy>>8);
    SC_BRIGHT_FRM_HS_LO = xy&0xFF;
    SC_BRIGHT_FRM_HS_HI = xy>>8;
}
     
void BF_SetVP(void) //picture_boost
{
USHRT xy;
//    xy = (ULONG)V_ActiveTab[ucResolution] *(1- BF_V[ucBF_Size])* ucBF_VP / 100;
    xy = (ULONG)usBFWindowHeight*(1- BF_V[UserData.ucBF_Size])* UserData.ucBF_VP / 100;
    //WriteIIC560(BRIGHT_FRM_VS_LI, xy&0xFF);
    //WriteIIC560(BRIGHT_FRM_VS_HI, xy>>8);

    SC_BRIGHT_FRM_VS_LO =  xy&0xFF;
    SC_BRIGHT_FRM_VS_HI =  xy>>8;
}
#endif
#if ENABLE_RECALL_PREVIEW == ON
void BF_SetWindowAfterAspectRatio()
{
#if 1 
   {
        BFAPI_SetActiveWindow(BF_WINDOW_1);
        //BFAPI_SetWindowSize(BF_WINDOW_FULLSCREEN);    
     if (UserData.bDemo) {
         BFAPI_SetWindowSize(BF_WINDOW_LEFTSIZE);
      }
      else {
            BFAPI_SetWindowSize(BF_WINDOW_FULLSCREEN);
       }
         //BF_SetWindowAfterAspectRatio();//Jerry
        
    }
#endif    

    usBFWindowWidth = ReadShortScaler(&SC_GRAPHIC_DISP_HOR_ACT_WID_LO);
#if ENABLE_DUAL_370
    usBFWindowWidth *=2;
#else
#if ENABLE_PIP
    if (UserData.ucPIPMode == PIP_TYPE_PBP_SBS) {
            usBFWindowWidth *=2;
    }
#endif    
#endif
    usBFWindowBegin = ReadShortScaler(&SC_GRAPHIC_DISP_HOR_ACT_BEG_LO)-ReadShortScaler(&SC_DH_BG_BEG_LO);
    
    if (UserData.bBrightFrame != 0 ) {
        BF_SetSize();
        BF_SetHP();
        BF_SetVP();
    }
}
#endif
typedef enum _BF_REF_ACTIVE_
{
    BF_REF_CAPTURE,
    BF_REF_DISPLAY,        

} BF_REF_ACTIVE;



void SetDemo(void)
{
#if ENABLE_PICTURE_DUAL_MODE == ON
    UCHAR tempBFMode;

    tempBFMode = DualViewPointoBFMode(UserData.ucDualViewMode);

    if ((UserData.bSensEyeDemo==PICTURE_DUALMODE_ON)&&(isOSDAllowSenseyeDemo())&& tempBFMode != UserData.ucBFMode)
    {
        BFAPI_SetActiveWindow(BF_WINDOW_1);   
        BFAPI_SetCustomWindow(0, 0, UserPanelData.usWidth/2, UserPanelData.usHeight);
        BFAPI_SetActiveWindow(BF_WINDOW_2);    
        BFAPI_SetCustomWindow(UserPanelData.usWidth/2, 0, UserPanelData.usWidth/2, UserPanelData.usHeight);
    }
    else {
        BFAPI_SetActiveWindow(BF_WINDOW_1);   
        BFAPI_SetCustomWindow(0, 0, UserPanelData.usWidth, UserPanelData.usHeight);
    }
#else
    if ((UserData.bSensEyeDemo==TRUE)&&(isOSDAllowSenseyeDemo()))
    {
        BFAPI_SetCustomWindow(UserPanelData.usWidth/2, 0, UserPanelData.usWidth/2, UserPanelData.usHeight);
    }
    else {
        BFAPI_SetCustomWindow(0, 0, UserPanelData.usWidth, UserPanelData.usHeight);
    }
#endif    
}
#if 0
void BF_SetDymACEMode(UCHAR reset)
{
    DCR_UpdateHistogram(reset);
    DCR_SetDynACEPnts(DefaultMinIGPoints);//v31_110803_0930_SYS#1
    DCR_SetDymACE(reset);
}
#endif
#if 0
UCHAR GetECOBrightness(UCHAR mode)
{
    if (UserData.ucECOMode != pECO_Standard && UserData.ucECOMode != pECO_DCR) {
        return BrightnessTab[mode];
    }
    else {
       // GetCLRTMP_BriCon();
        return UserData.ucBrightness;
    }
}

UCHAR GetECOContrast(UCHAR mode)
{
    if (UserData.ucECOMode != pECO_Standard && UserData.ucECOMode != pECO_DCR) {
        return ContrastTab[mode];
    }
    else {
        //GetCLRTMP_BriCon();
        return UserData.ucContrast;
    }
}
#endif

void UserSetHue(void)
{
#if ENABLE_PICTURE_DUAL_MODE == ON
  if(Custom_System.bDualviewAdjust == TRUE){
        BFAPI_SetActiveWindow(BF_WINDOW_2);    
    }
    else
    {
        BFAPI_SetActiveWindow(BF_WINDOW_1);    
    }
#endif

    BFAPI_SetHue(Remap100To255(UserData.ucHue));
}

void UserSetSaturation(void)
{
#if ENABLE_PICTURE_DUAL_MODE == ON
      if(Custom_System.bDualviewAdjust == TRUE){
            BFAPI_SetActiveWindow(BF_WINDOW_2);    
        }
        else
        {
            BFAPI_SetActiveWindow(BF_WINDOW_1);    
        }
#endif

    BFAPI_SetSaturation(Remap100To255(UserData.ucSaturation));
}
#if ENABLE_PICTURE_MODE_ANIMATION == ON
void UserSetAnimation(void)
{
#if OSDTYPE == OSD_BENQ_V2
#define ANI_STEP 1
#else
#define ANI_STEP 6//3 
#endif
//    UCHAR i;
    #if ENABLE_PICTURE_DUAL_MODE == ON
    if(Custom_System.bDualviewAdjust == TRUE){
        BFAPI_SetActiveWindow(BF_WINDOW_2);    
    }
    else
    #endif   
    {
        BFAPI_SetActiveWindow(BF_WINDOW_1);    
    }
    BFAPI_EnableCM(CM_ALL);
/*
    //test
//    for(i=0; i<17; i++)
    {
//        printf("%d\r\n",(USHRT)(CMModes[PICTURE_MODE_SRGB].pIG->IGamma[i]));
        //printf("%d\r\n",(USHRT)(CMModes[PICTURE_MODE_ANIMATION].pIG->IGamma[i]-CMModes[PICTURE_MODE_SRGB].pIG->IGamma[i]));
    }
*/
    if(UserData.ucAnimationMode == MINIMUM_ANIMATION_MODE){
        BFAPI_SetPreACEMode(CMModes[PICTURE_MODE_SRGB].pIG);//bypass
    }
    else if(UserData.ucAnimationMode == 1){
        BFAPI_SetPreACEMode(CMModes[PICTURE_MODE_ANIMATION].pIG);
    }   
    else{
        BFAPI_SetPreACEModeWithStep(CMModes[PICTURE_MODE_ANIMATION].pIG, (UserData.ucAnimationMode*ANI_STEP));
    }

    BFAPI_EnableWindow(BF_WINDOW_1);

}
#endif
void SetSenseEyeLeftMode(UCHAR mode)
{
#if ENABLE_PICTURE_DUAL_MODE == ON
    mode = mode;
    return;
#else
    //UCHAR tmp = GetSPIIndex();
    BFAPI_SetActiveWindow(BF_WINDOW_2);    
//    BFAPI_SetWindowSize(BF_WINDOW_LEFTSIZE);
    BFAPI_SetCustomWindow(0, 0, UserPanelData.usWidth/2, UserPanelData.usHeight);

    BFAPI_EnableCM(CM_ALL);
    BFAPI_SetROffset(CMModes[mode].ROffset);
    BFAPI_SetGOffset(CMModes[mode].GOffset);
    BFAPI_SetBOffset(CMModes[mode].BOffset);
    BFAPI_SetRGain(CMModes[mode].RGain);
    BFAPI_SetGGain(CMModes[mode].GGain);
    BFAPI_SetBGain(CMModes[mode].BGain);
    BFAPI_SetHue(CMModes[mode].Hue);
    BFAPI_SetSaturation(CMModes[mode].Saturation);
    BFAPI_SetIntensity(CMModes[mode].Intensity);
    BFAPI_CorrectFleshTone(CMModes[mode].FTMore);
    BFAPI_EnhanceRed(CMModes[mode].RedMore);
    BFAPI_EnhanceGreen(CMModes[mode].GreenMore);
    BFAPI_EnhanceBlue(CMModes[mode].BlueMore);
    //UserSetSharpness();//BFAPI_SetSharpness(CMModes[mode].Sharpness);
    BFAPI_SetYPeaking(CMModes[mode].Peaking);
    BFAPI_SetTextEnhancement(CMModes[mode].TextEn);
    BFAPI_ColorEnhance(CMModes[mode].ClrMode);
    if (!UserData.bDCRMode) {
        BFAPI_SetPreACEMode(CMModes[mode].pIG);
    }
    BFAPI_SetHHTable(CMModes[mode].pHH);
    BFAPI_SetHSTable(CMModes[mode].pHS);
    BFAPI_SetHITable(CMModes[mode].pHI);
   
    BFAPI_EnableWindow(BF_WINDOW_2);
    
#endif
}

#if ENABLE_NVT_FGA == ON
#if OSDTYPE == OSD_BENQ_V2
UCHAR GetColorTempature(void)
{
    UCHAR ColorTemp;
     switch(UserData.ucBFMode){
         case PICTURE_MODE_STANDARD:
             ColorTemp = UserData.ucColorTemp_Standard;break;
#if	ENABLE_PICTURE_MODE_REC709== ON            
         case PICTURE_MODE_REC709:
             ColorTemp = UserData.ucColorTemp_Rec709;break;
#endif            
         case PICTURE_MODE_SRGB:
             ColorTemp = UserData.ucColorTemp_sRGB;break;
#if	ENABLE_PICTURE_MODE_CAD == ON
         case PICTURE_MODE_CAD:
             ColorTemp = UserData.ucColorTemp_CAD;break;
#endif        
#if	ENABLE_PICTURE_MODE_ANIMATION == ON
         case PICTURE_MODE_ANIMATION:
             ColorTemp = UserData.ucColorTemp_Animation;break;
#endif
#if	ENABLE_PRESENTATION_MODE == ON
         case PICTURE_MODE_PRESENTATION:
             ColorTemp = UserData.ucColorTemp_Presentation;break;
#endif        
         case PICTURE_MODE_LOW_BL:
             switch(UserData.ucLBLMode){
                 case MULTIMEDIA:
                     ColorTemp = UserData.ucColorTemp_LBL_Mult;break;
                 case WEB_SURFING:
                     ColorTemp = UserData.ucColorTemp_LBL_Web;break;
                 case OFFICE:
                     ColorTemp = UserData.ucColorTemp_LBL_Office;break;
                 case READING:
                     ColorTemp = UserData.ucColorTemp_LBL_Read;break;
                 default:break;
             }
             break;
#if ENABLE_PICTURE_MODE_MOVIE == ON           
         case PICTURE_MODE_MOVIE:
             ColorTemp = UserData.ucColorTemp_Movie;break;            
#endif    
#if ENABLE_PICTURE_MODE_GAME == ON    
         case PICTURE_MODE_GAME:
             ColorTemp = UserData.ucColorTemp_Game;break;            
#endif    
#if ENABLE_PICTURE_MODE_PHOTO== ON       
         case PICTURE_MODE_PHOTO:
             ColorTemp = UserData.ucColorTemp_Photo;break;            
#endif    
#if	ENABLE_PICTURE_MODE_DARKROOM == ON
         case PICTURE_MODE_DARKROOM:
             ColorTemp = UserData.ucColorTemp_DarkRoom;break;            
#endif        
         case PICTURE_MODE_ECO:
             ColorTemp = UserData.ucColorTemp_Standard;break; 
#if ENABLE_PICTURE_MODE_MBOOK == ON
         case PICTURE_MODE_MBOOK:
             ColorTemp = UserData.ucColorTemp_MBOOK;break; 
#endif
         case PICTURE_MODE_USER:
             ColorTemp = UserData.ucColorTemp_USER;break; 
             
         default:break;            
     }
  
    //printf("-->CT %bx\r\n",ColorTemp);
    return ColorTemp;
}
#else
UCHAR GetColorTempature(void)
{
    UCHAR ColorTemp;
  
    if(UserData.ucBFMode == PICTURE_MODE_STANDARD){
        ColorTemp = UserData.ucColorTemp_Standard;
    }else if(UserData.ucBFMode == PICTURE_MODE_USER){
        ColorTemp = UserData.ucColorTemp_USER;
    }
    if(UserData.ucBFMode == PICTURE_MODE_ECO
#if ENABLE_PICTURE_MODE_MOVIE == ON               
        || UserData.ucBFMode == PICTURE_MODE_MOVIE
#endif        
#if ENABLE_PICTURE_MODE_ANIMATION== ON
        || UserData.ucBFMode == PICTURE_MODE_ANIMATION
#endif
#if ENABLE_PICTURE_MODE_MBOOK == ON
        || UserData.ucBFMode == PICTURE_MODE_MBOOK
#endif        
        ){
        ColorTemp = CLRTMP_6500K;
    }
    else if(UserData.ucBFMode == PICTURE_MODE_SRGB){
        ColorTemp = CLRTMP_6500K;
    }
#if ENABLE_PICTURE_MODE_PHOTO== ON           
    else if(UserData.ucBFMode == PICTURE_MODE_PHOTO){
        ColorTemp = CLRTMP_9300K;
    }
#endif    
    else if(FALSE
#if ENABLE_PICTURE_MODE_CAD == ON
        || UserData.ucBFMode == PICTURE_MODE_CAD 
#endif
#if ENABLE_PRESENTATION_MODE == ON
        || UserData.ucBFMode == PICTURE_MODE_PRESENTATION
#endif        
        ){
        ColorTemp = CLRTMP_5800K;
    }
    //printf("-->CT %bx\r\n",ColorTemp);
    return ColorTemp;
}
#endif
#endif
#if OSDTYPE == OSD_BENQ_V2
UCHAR GetGammaNum(void)
{
  UCHAR GammaTemp;
      switch(UserData.ucBFMode){
          case PICTURE_MODE_STANDARD:
              GammaTemp = UserData.ucGammaNum_Standard;break;
#if	ENABLE_PICTURE_MODE_REC709== ON            
          case PICTURE_MODE_REC709:
              GammaTemp = UserData.ucGammaNum_Rec709;break;
#endif            
          case PICTURE_MODE_SRGB:
              GammaTemp = UserData.ucGammaNum_sRGB;break;
#if	ENABLE_PICTURE_MODE_CAD == ON
          case PICTURE_MODE_CAD:
              GammaTemp = UserData.ucGammaNum_CAD;break;
#endif        
#if	ENABLE_PICTURE_MODE_ANIMATION == ON
          case PICTURE_MODE_ANIMATION:
              GammaTemp = UserData.ucGammaNum_Animation;break;
#endif
#if	ENABLE_PRESENTATION_MODE == ON
          case PICTURE_MODE_PRESENTATION:
              GammaTemp = UserData.ucGammaNum_Presentation;break;
#endif        
          case PICTURE_MODE_LOW_BL:
              switch(UserData.ucLBLMode){
                  case MULTIMEDIA:
                      GammaTemp = UserData.ucGammaNum_LBL_Mult;break;
                  case WEB_SURFING:
                      GammaTemp = UserData.ucGammaNum_LBL_Web;break;
                  case OFFICE:
                      GammaTemp = UserData.ucGammaNum_LBL_Office;break;
                  case READING:
                      GammaTemp = UserData.ucGammaNum_LBL_Read;break;
                  default:break;
              }
              break;
#if ENABLE_PICTURE_MODE_MOVIE == ON           
          case PICTURE_MODE_MOVIE:
              GammaTemp = UserData.ucGammaNum_Movie;break;            
#endif    
#if ENABLE_PICTURE_MODE_GAME == ON    
          case PICTURE_MODE_GAME:
              GammaTemp = UserData.ucGammaNum_Game;break;            
#endif    
#if ENABLE_PICTURE_MODE_PHOTO== ON       
          case PICTURE_MODE_PHOTO:
              GammaTemp = UserData.ucGammaNum_Photo;break;            
#endif    
#if	ENABLE_PICTURE_MODE_DARKROOM == ON
          case PICTURE_MODE_DARKROOM:
              GammaTemp = UserData.ucGammaNum_DarkRoom;break;            
#endif        
          case PICTURE_MODE_ECO:
              GammaTemp = UserData.ucGammaNum_Standard;break; 
#if ENABLE_PICTURE_MODE_MBOOK == ON
          case PICTURE_MODE_MBOOK:
              GammaTemp = UserData.ucGammaNum_MBOOK;break; 
#endif
          case PICTURE_MODE_USER:
              GammaTemp = UserData.ucGammaNum_USER;break; 
              
          default:break;            
      }
#if 0  
    if(UserData.ucBFMode == PICTURE_MODE_STANDARD){
        GammaTemp = UserData.ucGammaNum_Standard;
    }
    else if(UserData.ucBFMode == PICTURE_MODE_USER){
        GammaTemp = UserData.ucGammaNum_USER;
    }
    else{
        GammaTemp = UserData.ucGammaNum;
    }
    //printf("-->Gamma %bx\r\n",GammaTemp);
#endif    
    return GammaTemp;
}

void SetGammaNum(UCHAR GammaNum)
{
    switch(UserData.ucBFMode){
        case PICTURE_MODE_STANDARD:
            UserData.ucGammaNum_Standard = GammaNum;break;
#if	ENABLE_PICTURE_MODE_REC709== ON            
        case PICTURE_MODE_REC709:
            UserData.ucGammaNum_Rec709 = GammaNum;break;
#endif            
        case PICTURE_MODE_SRGB:
            UserData.ucGammaNum_sRGB = GammaNum;break;
#if	ENABLE_PICTURE_MODE_CAD == ON
        case PICTURE_MODE_CAD:
            UserData.ucGammaNum_CAD = GammaNum;break;
#endif        
#if	ENABLE_PICTURE_MODE_ANIMATION == ON
        case PICTURE_MODE_ANIMATION:
            UserData.ucGammaNum_Animation = GammaNum;break;
#endif
#if	ENABLE_PRESENTATION_MODE == ON
        case PICTURE_MODE_PRESENTATION:
            UserData.ucGammaNum_Presentation = GammaNum;break;
#endif        
        case PICTURE_MODE_LOW_BL:
            switch(UserData.ucLBLMode){
                case MULTIMEDIA:
                    UserData.ucGammaNum_LBL_Mult = GammaNum;break;
                case WEB_SURFING:
                    UserData.ucGammaNum_LBL_Web = GammaNum;break;
                case OFFICE:
                    UserData.ucGammaNum_LBL_Office = GammaNum;break;
                case READING:
                    UserData.ucGammaNum_LBL_Read = GammaNum;break;
                default:break;
            }
            break;
#if ENABLE_PICTURE_MODE_MOVIE == ON           
        case PICTURE_MODE_MOVIE:
            UserData.ucGammaNum_Movie = GammaNum;break;            
#endif    
#if ENABLE_PICTURE_MODE_GAME == ON    
        case PICTURE_MODE_GAME:
            UserData.ucGammaNum_Game = GammaNum;break;            
#endif    
#if ENABLE_PICTURE_MODE_PHOTO== ON       
        case PICTURE_MODE_PHOTO:
            UserData.ucGammaNum_Photo = GammaNum;break;            
#endif    
#if	ENABLE_PICTURE_MODE_DARKROOM == ON
        case PICTURE_MODE_DARKROOM:
            UserData.ucGammaNum_DarkRoom = GammaNum;break;            
#endif        
        case PICTURE_MODE_ECO:
            UserData.ucGammaNum_Standard = GammaNum;break; 
#if ENABLE_PICTURE_MODE_MBOOK == ON
        case PICTURE_MODE_MBOOK:
            UserData.ucGammaNum_MBOOK = GammaNum;break; 
#endif
        case PICTURE_MODE_USER:
            UserData.ucGammaNum_USER = GammaNum;break; 
            
        default:break;            
    }
    #if 0
    if(UserData.ucBFMode == PICTURE_MODE_STANDARD){
        UserData.ucGammaNum_Standard = GammaNum;
    }
    else if(UserData.ucBFMode == PICTURE_MODE_USER){
        UserData.ucGammaNum_USER = GammaNum;
    }
    else{
        UserData.ucGammaNum = GammaNum;
    }
    #endif
}

void SetPictureMode(UCHAR mode)
{
    UCHAR  ContrastTemp,ColorTempTemp, DBCModeTemp;
  
    ContrastTemp = UserData.ucContrast;
    ColorTempTemp = UserData.ucColorTemp;
    DBCModeTemp = UserData.bDBCMode;
    
    if(UserData.ucBFMode != PICTURE_MODE_ECO){
        UserData.bDBCMode = OFF;
    }
  
    switch(mode) {
        case PICTURE_MODE_SRGB:
            
            if(Custom_System.bDualviewAdjust == TRUE){
                UserData.ucContrast = UserData.ucContrast_sRGB;                
                UserData.ucColorTemp = UserData.ucColorTemp_sRGB;            
            }
            else{
                UserData.ucBrightness = UserData.ucBrightness_sRGB;
                UserData.ucContrast = UserData.ucContrast_sRGB;
                UserData.ucColorTemp = UserData.ucColorTemp_sRGB;            
                UserData.ucSharpness = UserData.ucSharpness_sRGB;
                UserData.ucODMode = UserData.ucODMode_sRGB;
            }
            //UserData.ucGammaNum = nGamma_22;
            //SetGammaNum(nGamma_22);
            Standard_Gamma = 1;
            break;
#if	ENABLE_PICTURE_MODE_CAD == ON
        case PICTURE_MODE_CAD: 
            if(Custom_System.bDualviewAdjust == TRUE){
                UserData.ucContrast = UserData.ucContrast_CAD;                
                UserData.ucColorTemp = UserData.ucColorTemp_CAD;            
            }
            else{
                UserData.ucBrightness = UserData.ucBrightness_CAD;
                UserData.ucContrast = UserData.ucContrast_CAD;
                UserData.ucColorTemp = UserData.ucColorTemp_CAD;            
                UserData.ucSharpness = UserData.ucSharpness_CAD;
                UserData.ucODMode = UserData.ucODMode_CAD;
            }          
            //UserData.ucGammaNum = nGamma_22;
            //SetGammaNum(nGamma_22);
            Standard_Gamma = 1; 
            if(UserData.bSensEyeDemo == TRUE)
            {
                 SetSenseEyeLeftMode(PICTURE_MODE_STANDARD);
            }
            break;
#endif
#if	ENABLE_PICTURE_MODE_ANIMATION == ON
        case PICTURE_MODE_ANIMATION:            
            if(Custom_System.bDualviewAdjust == TRUE){
                UserData.ucContrast = UserData.ucContrast_Animation;                
                UserData.ucColorTemp = UserData.ucColorTemp_Animation;            
            }
            else{
                UserData.ucBrightness = UserData.ucBrightness_Animation;
                UserData.ucContrast = UserData.ucContrast_Animation;
                UserData.ucColorTemp = UserData.ucColorTemp_Animation;            
                UserData.ucSharpness = UserData.ucSharpness_Animation;
                UserData.ucODMode = UserData.ucODMode_Animation;
            } 
            //UserData.ucGammaNum = nGamma_22;
            //SetGammaNum(nGamma_22);
            Standard_Gamma = 1;
            ////////////////////////////////////////
            UserSetAnimation();

            if(UserData.bSensEyeDemo == TRUE){
                 SetSenseEyeLeftMode(PICTURE_MODE_STANDARD);
            }
            break;
#endif
#if	ENABLE_PRESENTATION_MODE == ON
        case PICTURE_MODE_PRESENTATION:            
            if(Custom_System.bDualviewAdjust == TRUE){
                UserData.ucContrast = UserData.ucContrast_Presentation;
                UserData.ucColorTemp = UserData.ucColorTemp_Presentation;            
            }
            else{
                UserData.ucBrightness = UserData.ucBrightness_Presentation;
                UserData.ucContrast = UserData.ucContrast_Presentation;
                UserData.ucColorTemp = UserData.ucColorTemp_Presentation;            
                UserData.ucSharpness = UserData.ucSharpness_Presentation;
                UserData.ucODMode = UserData.ucODMode_Presentation;
            }
            //UserData.ucGammaNum = nGamma_20;
            //SetGammaNum(nGamma_20);
            Standard_Gamma = 0;         
            break;
#endif      
        case PICTURE_MODE_STANDARD:
            if(Custom_System.bDualviewAdjust == TRUE){
                UserData.ucContrast = UserData.ucContrast_Standard;
                UserData.ucColorTemp = UserData.ucColorTemp_Standard;            
            }
            else{
                UserData.ucBrightness = UserData.ucBrightness_Standard;
                UserData.ucContrast = UserData.ucContrast_Standard;
                UserData.ucColorTemp = UserData.ucColorTemp_Standard;            
                UserData.ucSharpness = UserData.ucSharpness_Standard;
                UserData.ucODMode = UserData.ucODMode_Standard;
            }
            //SetGammaNum(UserData.ucGammaNum_Standard);
            Standard_Gamma = 0;         
            break;
        case PICTURE_MODE_LOW_BL:
            // SetLBLMode();
            break;
#if ENABLE_PICTURE_MODE_MOVIE == ON                   
        case PICTURE_MODE_MOVIE:
            if(Custom_System.bDualviewAdjust == TRUE){
                UserData.ucContrast = UserData.ucContrast_Movie;
                UserData.ucColorTemp = UserData.ucColorTemp_Movie;            
            }
            else{
                UserData.ucBrightness = UserData.ucBrightness_Movie;
                UserData.ucContrast = UserData.ucContrast_Movie;
                UserData.ucColorTemp = UserData.ucColorTemp_Movie;            
                UserData.ucSharpness = UserData.ucSharpness_Movie;
                UserData.ucODMode = UserData.ucODMode_Movie;
            }         
            //SetGammaNum(nGamma_20);
            Standard_Gamma = 0;         
            if(UserData.bSensEyeDemo == TRUE)
            {
                 SetSenseEyeLeftMode(PICTURE_MODE_STANDARD);
            }
            break;
#endif
#if ENABLE_PICTURE_MODE_PHOTO== ON       
        case PICTURE_MODE_PHOTO:
                    UserData.ucContrast = UserData.ucContrast_Photo;
                    UserData.ucColorTemp = UserData.ucColorTemp_Photo; 
                if(Custom_System.bDualviewAdjust == FALSE){
                UserData.ucBrightness = UserData.ucBrightness_Photo;
                UserData.ucSharpness = UserData.ucSharpness_Photo;
                UserData.ucODMode = UserData.ucODMode_Photo;
                }
            //SetGammaNum(nGamma_26);
            Standard_Gamma = 0;
            if(UserData.bSensEyeDemo == TRUE)
            {
                 SetSenseEyeLeftMode(PICTURE_MODE_STANDARD);
            }
            break;
#endif            
        case PICTURE_MODE_ECO:
            UserData.bDBCMode = ON;
                UserData.ucContrast = UserDataDefault.ucContrast_Standard;
                UserData.ucColorTemp = UserData.ucColorTemp_Standard;  
            if(Custom_System.bDualviewAdjust == FALSE){
            UserData.ucBrightness = UserDataDefault.ucBrightness_Standard;
            UserData.ucSharpness = UserDataDefault.ucSharpness_Standard;
            UserData.ucODMode = UserData.ucODMode_Standard;
            }
            //SetGammaNum(nGamma_22);
            Standard_Gamma = 1;         
           // UserData.ucDynamicContrast = 0;            
            break;
#if ENABLE_PICTURE_MODE_GAME == ON
        case PICTURE_MODE_GAME:
                UserData.ucContrast = UserData.ucContrast_Game;
                UserData.ucColorTemp = UserData.ucColorTemp_Game;  
            if(Custom_System.bDualviewAdjust == FALSE){
            UserData.ucBrightness = UserData.ucBrightness_Game;
            UserData.ucSharpness = UserData.ucSharpness_Game;
            UserData.ucODMode = UserData.ucODMode_Game;
            }
            //SetGammaNum(nGamma_22);
            Standard_Gamma = 0;
            if(UserData.bSensEyeDemo == TRUE)
            {
                 SetSenseEyeLeftMode(PICTURE_MODE_STANDARD);
            }            
            break;            
#endif            
#if ENABLE_PICTURE_MODE_MBOOK == ON
        case PICTURE_MODE_MBOOK:
                    UserData.ucContrast = UserData.ucContrast_MBOOK;
                    UserData.ucColorTemp = UserData.ucColorTemp_MBOOK;  
                if(Custom_System.bDualviewAdjust == FALSE){
                UserData.ucBrightness = UserData.ucBrightness_MBOOK;
                UserData.ucSharpness = UserData.ucSharpness_MBOOK;
                UserData.ucODMode = UserData.ucODMode_MBOOK;
                }
            Standard_Gamma = 0;
            if(UserData.bSensEyeDemo == TRUE)
            {
                 SetSenseEyeLeftMode(PICTURE_MODE_STANDARD);
            }
            break;
#endif
        case PICTURE_MODE_USER:
                UserData.ucContrast = UserData.ucContrast_USER;
                UserData.ucColorTemp = UserData.ucColorTemp_USER;            
            if(Custom_System.bDualviewAdjust == FALSE){
                UserData.ucBrightness = UserData.ucBrightness_USER;
                UserData.ucSharpness = UserData.ucSharpness_USER;
                UserData.ucODMode = UserData.ucODMode_USER;
            }
            Standard_Gamma = 0;
            break;
#if ENABLE_PICTURE_MODE_REC709 == ON       
        case PICTURE_MODE_REC709:
                    UserData.ucContrast = UserData.ucContrast_Rec709;
                    UserData.ucColorTemp = UserData.ucColorTemp_Rec709;            
                if(Custom_System.bDualviewAdjust == FALSE){
                UserData.ucBrightness = UserData.ucBrightness_Rec709;
                UserData.ucSharpness = UserData.ucSharpness_Rec709;
                UserData.ucODMode = UserData.ucODMode_Rec709;
                }
            Standard_Gamma = 0;
            if(UserData.bSensEyeDemo == TRUE)
            {
                 SetSenseEyeLeftMode(PICTURE_MODE_STANDARD);
            }
            break;
#endif            
#if ENABLE_PICTURE_MODE_DARKROOM == ON       
        case PICTURE_MODE_DARKROOM:
                UserData.ucContrast = UserData.ucContrast_DarkRoom;
                UserData.ucColorTemp = UserData.ucColorTemp_DarkRoom;            
                if(Custom_System.bDualviewAdjust == FALSE){
                UserData.ucBrightness = UserData.ucBrightness_DarkRoom;
                UserData.ucSharpness = UserData.ucSharpness_DarkRoom;
                UserData.ucODMode = UserData.ucODMode_DarkRoom;
                }
            Standard_Gamma = 0;
            if(UserData.bSensEyeDemo == TRUE)
            {
                 SetSenseEyeLeftMode(PICTURE_MODE_STANDARD);
            }
            break;
#endif
        default:
            break;
    }
    SetDemo();
    if(mode == PICTURE_MODE_LOW_BL){
        SetLBLMode();
    }
    else{
        UserSetBrightness();
        UserSetContrast();        
        UserSetColorTemp();      
        UserSetGamma();
    }
    UserSetSharpness();
    
    if(DBCModeTemp != UserData.bDBCMode)
        UserSetDBC(); 
 
    UserSetDCR();  
    
    if(Custom_System.bDualviewAdjust == TRUE){
    UserData.ucContrast = ContrastTemp;
    UserData.ucColorTemp = ColorTempTemp;
    }
}

#else
UCHAR GetGammaNum(void)
{
  UCHAR GammaTemp;
    if(UserData.ucBFMode == PICTURE_MODE_STANDARD){
        GammaTemp = UserData.ucGammaNum_Standard;
    }
    else if(UserData.ucBFMode == PICTURE_MODE_USER){
        GammaTemp = UserData.ucGammaNum_USER;
    }
    else{
        GammaTemp = UserData.ucGammaNum;
    }
    //printf("-->Gamma %bx\r\n",GammaTemp);
    return GammaTemp;
}

void SetGammaNum(UCHAR GammaNum)
{
    if(UserData.ucBFMode == PICTURE_MODE_STANDARD){
        UserData.ucGammaNum_Standard = GammaNum;
    }
    else if(UserData.ucBFMode == PICTURE_MODE_USER){
        UserData.ucGammaNum_USER = GammaNum;
    }
    else{
        UserData.ucGammaNum = GammaNum;
    }
}

void SetPictureMode(UCHAR mode)
{
    UserData.bDBCMode = OFF;
    //UserData.ucColorTemp = CLRTMP_6500K;
    switch(mode) {
        case PICTURE_MODE_SRGB:
            UserData.ucBrightness = UserData.ucBrightness_sRGB;
            UserData.ucContrast = UserData.ucContrast_sRGB;
            UserData.ucSharpness = UserData.ucSharpness_sRGB;
            //UserData.ucGammaNum = nGamma_22;
            SetGammaNum(nGamma_22);
            Standard_Gamma = 1;
            break;
#if	ENABLE_PICTURE_MODE_CAD == ON
        case PICTURE_MODE_CAD: 
            UserData.ucBrightness = UserData.ucBrightness_CAD;
            UserData.ucContrast = UserData.ucContrast_CAD;
            //UserData.ucColorTemp = UserData.ucColorTemp_CAD;        
            UserData.ucSharpness = UserData.ucSharpness_CAD;
            //UserData.ucGammaNum = nGamma_22;
            SetGammaNum(nGamma_22);
            Standard_Gamma = 1; 
            if(UserData.bSensEyeDemo == TRUE)
            {
                 SetSenseEyeLeftMode(PICTURE_MODE_STANDARD);
            }
            break;
#endif
#if	ENABLE_PICTURE_MODE_ANIMATION == ON
        case PICTURE_MODE_ANIMATION:            
            UserData.ucBrightness = UserData.ucBrightness_Animation;
            UserData.ucContrast = UserData.ucContrast_Animation;
            //UserData.ucColorTemp = UserData.ucColorTemp_Animation;        
            UserData.ucSharpness = UserData.ucSharpness_Animation;
            //UserData.ucGammaNum = nGamma_22;
            SetGammaNum(nGamma_22);
            Standard_Gamma = 1;
            ////////////////////////////////////////
            UserSetAnimation();

            if(UserData.bSensEyeDemo == TRUE){
                 SetSenseEyeLeftMode(PICTURE_MODE_STANDARD);
            }
            break;
#endif
#if	ENABLE_PRESENTATION_MODE == ON
        case PICTURE_MODE_PRESENTATION:            
            UserData.ucBrightness = UserData.ucBrightness_Presentation;
            UserData.ucContrast = UserData.ucContrast_Presentation;
           // UserData.ucColorTemp = UserData.ucColorTemp_Presentation;        
            UserData.ucSharpness = UserData.ucSharpness_Presentation;
            //UserData.ucGammaNum = nGamma_20;
            SetGammaNum(nGamma_20);
            Standard_Gamma = 0;         
            break;
#endif      
        case PICTURE_MODE_STANDARD:
            UserData.ucBrightness = UserData.ucBrightness_Standard;
            UserData.ucContrast = UserData.ucContrast_Standard;
            UserData.ucColorTemp = UserData.ucColorTemp_Standard;        
            UserData.ucSharpness = UserData.ucSharpness_Standard;
            SetGammaNum(UserData.ucGammaNum_Standard);
            Standard_Gamma = 0;         
            break;
        case PICTURE_MODE_LOW_BL:
            // SetLBLMode();
            break;
#if ENABLE_PICTURE_MODE_MOVIE == ON                   
        case PICTURE_MODE_MOVIE:
            UserData.ucBrightness = UserData.ucBrightness_Movie;
            UserData.ucContrast = UserData.ucContrast_Movie;
            UserData.ucSharpness = UserData.ucSharpness_Movie;
            SetGammaNum(nGamma_20);
            Standard_Gamma = 0;         
            if(UserData.bSensEyeDemo == TRUE)
            {
                 SetSenseEyeLeftMode(PICTURE_MODE_STANDARD);
            }
            break;
#endif
#if ENABLE_PICTURE_MODE_PHOTO== ON       
        case PICTURE_MODE_PHOTO:
            UserData.ucBrightness = UserData.ucBrightness_Photo;
            UserData.ucContrast = UserData.ucContrast_Photo;
            UserData.ucSharpness = UserData.ucSharpness_Photo;
            SetGammaNum(nGamma_26);
            Standard_Gamma = 0;
            if(UserData.bSensEyeDemo == TRUE)
            {
                 SetSenseEyeLeftMode(PICTURE_MODE_STANDARD);
            }
            break;
#endif            
        case PICTURE_MODE_ECO:
            UserData.bDBCMode = ON;
            UserData.ucBrightness = UserDataDefault.ucBrightness_Standard;
            UserData.ucContrast = UserDataDefault.ucContrast_Standard;
            UserData.ucSharpness = UserDataDefault.ucSharpness_Standard;
            SetGammaNum(nGamma_22);
            Standard_Gamma = 1;         
           // UserData.ucDynamicContrast = 0;            
            break;
#if ENABLE_PICTURE_MODE_GAME == ON
        case PICTURE_MODE_GAME:
            UserData.ucBrightness = UserData.ucBrightness_Game;
            UserData.ucContrast = UserData.ucContrast_Game;
            UserData.ucSharpness = UserData.ucSharpness_Game;
            SetGammaNum(nGamma_22);
            Standard_Gamma = 0;
            if(UserData.bSensEyeDemo == TRUE)
            {
                 SetSenseEyeLeftMode(PICTURE_MODE_STANDARD);
            }            
            break;            
#endif            
#if ENABLE_PICTURE_MODE_MBOOK == ON
        case PICTURE_MODE_MBOOK:
            UserData.ucBrightness = UserData.ucBrightness_MBOOK;
            UserData.ucContrast = UserData.ucContrast_MBOOK;
            UserData.ucSharpness = UserData.ucSharpness_MBOOK;
            SetGammaNum(nGamma_18);
            Standard_Gamma = 0;
            if(UserData.bSensEyeDemo == TRUE)
            {
                 SetSenseEyeLeftMode(PICTURE_MODE_STANDARD);
            }
            break;
#endif
        case PICTURE_MODE_USER:
            UserData.ucBrightness = UserData.ucBrightness_USER;
            UserData.ucContrast = UserData.ucContrast_USER;
            UserData.ucSharpness = UserData.ucSharpness_USER;
            UserData.ucColorTemp = UserData.ucColorTemp_USER; 
            //UserData.ucGammaNum = UserData.ucGammaNum_USER;
            SetGammaNum(UserData.ucGammaNum_USER);
            Standard_Gamma = 0;
            break;
#if ENABLE_PICTURE_MODE_REC709 == ON       
        case PICTURE_MODE_REC709:
            UserData.ucBrightness = UserData.ucBrightness_Rec709;
            UserData.ucContrast = UserData.ucContrast_Rec709;
            UserData.ucSharpness = UserData.ucSharpness_Rec709;
            SetGammaNum(nGamma_26);
            Standard_Gamma = 0;
            if(UserData.bSensEyeDemo == TRUE)
            {
                 SetSenseEyeLeftMode(PICTURE_MODE_STANDARD);
            }
            break;
#endif            
#if ENABLE_PICTURE_MODE_DARKROOM == ON       
        case PICTURE_MODE_DARKROOM:
            UserData.ucBrightness = UserData.ucBrightness_DarkRoom;
            UserData.ucContrast = UserData.ucContrast_DarkRoom;
            UserData.ucSharpness = UserData.ucSharpness_DarkRoom;
            SetGammaNum(nGamma_26);
            Standard_Gamma = 0;
            if(UserData.bSensEyeDemo == TRUE)
            {
                 SetSenseEyeLeftMode(PICTURE_MODE_STANDARD);
            }
            break;
#endif
        default:
            break;
    }
    
    SetDemo();
    if(mode == PICTURE_MODE_LOW_BL){
      SetLBLMode();
    }
    else{
        UserSetBrightness();
        UserSetContrast();        
        UserSetColorTemp();      
        UserSetGamma();
   }
   
   UserSetSharpness();
   UserSetDBC(); 
   UserSetDCR();        
}

#endif
void SetLBLMode(void)
{
    switch(UserData.ucLBLMode) {
        case MULTIMEDIA:
         if(Custom_System.bDualviewAdjust == FALSE){
            UserData.ucBrightness = UserData.ucBrightness_LBL_Mult;
         }
         UserData.ucContrast = UserData.ucContrast_LBL_Mult;
         SetGammaNum(nGamma_22);
         Standard_Gamma = 1;
     break;
        case WEB_SURFING:
         if(Custom_System.bDualviewAdjust == FALSE){
            UserData.ucBrightness = UserData.ucBrightness_LBL_Web;
         }
         UserData.ucContrast = UserData.ucContrast_LBL_Web;
         SetGammaNum(nGamma_22);
         Standard_Gamma = 1;
     break;
        case OFFICE:
         if(Custom_System.bDualviewAdjust == FALSE){
            UserData.ucBrightness = UserData.ucBrightness_LBL_Office;
         }
         UserData.ucContrast = UserData.ucContrast_LBL_Office;
         SetGammaNum(nGamma_22);      
         Standard_Gamma = 1;
     break;
        case READING:
         if(Custom_System.bDualviewAdjust == FALSE){
            UserData.ucBrightness = UserData.ucBrightness_LBL_Read;
         }
         UserData.ucContrast = UserData.ucContrast_LBL_Read;
         SetGammaNum(nGamma_22);
         Standard_Gamma = 1;
     break;     
        default:
            break;     
    }
    UserSetBrightness(); 
    UserSetContrast();
    UserSetColorTemp();  
    UserSetGamma();    
}

#if ENABLE_NVT_FGA == ON
void BFAPI_GetRGBGainDependOnGamma(UCHAR mode, UCHAR *r, UCHAR *g , UCHAR *b)
{

    USHRT GammaTemp;
    UCHAR CTGain[3];	
    GammaTemp = GetGammaNum();
    
    switch (mode) {
        /*case CLRTMP_5000K:
            r = CalibData.uc5000KRGain;
            g = CalibData.uc5000KGGain;
            b = CalibData.uc5000KBGain;
            break;*/
        default:
        case CLRTMP_6500K:
  			LG_FGA_LoadColorTemp(GammaTemp, CT_6500K,&CTGain[0],&CTGain[1],&CTGain[2]);	
            *r = CTGain[0];
            *g = CTGain[1];
            *b = CTGain[2];		 
            break;
        /*case CLRTMP_7500K:
            r = CalibData.uc7500KRGain;
            g = CalibData.uc7500KGGain;
            b = CalibData.uc7500KBGain;
            break;*/
        /*case CLRTMP_8200K:
            r = CalibData.uc8200KRGain;
            g = CalibData.uc8200KGGain;
            b = CalibData.uc8200KBGain;
            break;*/
        case CLRTMP_9300K:
  			LG_FGA_LoadColorTemp(GammaTemp, CT_9300K,&CTGain[0],&CTGain[1],&CTGain[2]);	
            *r = CTGain[0];
            *g = CTGain[1];
            *b = CTGain[2];		 
            break;
        case CLRTMP_5800K:
  			LG_FGA_LoadColorTemp(GammaTemp, CT_5800K,&CTGain[0],&CTGain[1],&CTGain[2]);	
            *r = CTGain[0];
            *g = CTGain[1];
            *b = CTGain[2];		 
            break;
            
        /*case CLRTMP_11500K:
            r = CalibData.uc11500KRGain;
            g = CalibData.uc11500KGGain;
            b = CalibData.uc11500KBGain;
            break;*/
        case CLRTMP_sRGB:
  			LG_FGA_LoadColorTemp(GammaTemp, CT_6500K,&CTGain[0],&CTGain[1],&CTGain[2]);	
            *r = CTGain[0];
            *g = CTGain[1];
            *b = CTGain[2];		 
            break;
        case CLRTMP_USER:
            *r = (USHRT)GetRGain255();
            *g = (USHRT)GetGGain255();
            *b = (USHRT)GetBGain255();
            break;
    };  

	
}

void SetLocalMatrix(void)
{
    UCHAR Gain[3];	

    UCHAR ActiceMode;
#if ENABLE_PICTURE_DUAL_MODE == ON
    UCHAR tempBFMode;
    tempBFMode = DualViewPointoBFMode(UserData.ucDualViewMode);
    if(Custom_System.bDualviewAdjust == TRUE){
        ActiceMode = tempBFMode;   
        BFAPI_SetActiveWindow(BF_WINDOW_2);    
    }
    else
#endif   
  {
         ActiceMode = UserData.ucBFMode;
         BFAPI_SetActiveWindow(BF_WINDOW_1);     
    }
	
    switch(ActiceMode) {
#if ENABLE_PICTURE_MODE_MOVIE == ON               
        case PICTURE_MODE_MOVIE:
            MTXAPI_EnableLocalMatrix(TRUE);    
    	    BFAPI_GetRGBGainDependOnGamma(CLRTMP_6500K, &Gain[0],&Gain[1],&Gain[2]);			
            MTXAPI_SetRGBGain(Gain[0],Gain[1],Gain[2]);
            break;
#endif            
#if	ENABLE_PICTURE_MODE_CAD == ON
        case PICTURE_MODE_CAD: 
            MTXAPI_EnableLocalMatrix(TRUE);                      
    	    BFAPI_GetRGBGainDependOnGamma(CLRTMP_5800K, &Gain[0],&Gain[1],&Gain[2]);			
            MTXAPI_SetRGBGain(Gain[0],Gain[1],Gain[2]);
            break;
#endif
#if	ENABLE_PICTURE_MODE_ANIMATION == ON
        case PICTURE_MODE_ANIMATION:            
            MTXAPI_EnableLocalMatrix(TRUE);                      
    	    BFAPI_GetRGBGainDependOnGamma(CLRTMP_6500K, &Gain[0],&Gain[1],&Gain[2]);			
            MTXAPI_SetRGBGain(Gain[0],Gain[1],Gain[2]);
            break;
#endif
#if	ENABLE_PRESENTATION_MODE == ON
        case PICTURE_MODE_PRESENTATION:            
            MTXAPI_EnableLocalMatrix(TRUE);                      
    	    BFAPI_GetRGBGainDependOnGamma(CLRTMP_5800K, &Gain[0],&Gain[1],&Gain[2]);			
            MTXAPI_SetRGBGain(Gain[0],Gain[1],Gain[2]);
            break;
#endif            
     
#if ENABLE_PICTURE_MODE_GAME == ON
        case PICTURE_MODE_GAME:    
            MTXAPI_EnableLocalMatrix(TRUE);                      
    	    BFAPI_GetRGBGainDependOnGamma(CLRTMP_6500K, &Gain[0],&Gain[1],&Gain[2]);			
            MTXAPI_SetRGBGain(Gain[0],Gain[1],Gain[2]);
            break;    
#endif     
#if ENABLE_PICTURE_MODE_MBOOK == ON 
        case PICTURE_MODE_MBOOK:
            MTXAPI_EnableLocalMatrix(TRUE);                      
    	    BFAPI_GetRGBGainDependOnGamma(CLRTMP_6500K, &Gain[0],&Gain[1],&Gain[2]);			
            MTXAPI_SetRGBGain(Gain[0],Gain[1],Gain[2]);
            break;     
#endif
#if ENABLE_PICTURE_MODE_PHOTO== ON  
        case PICTURE_MODE_PHOTO: 
            MTXAPI_EnableLocalMatrix(TRUE);                      
    	    BFAPI_GetRGBGainDependOnGamma(CLRTMP_9300K, &Gain[0],&Gain[1],&Gain[2]);
            MTXAPI_SetRGBGain(Gain[0],Gain[1],Gain[2]);
            break;     
#endif            
        case PICTURE_MODE_LOW_BL:    
            MTXAPI_EnableLocalMatrix(TRUE);                      
            switch(UserData.ucLBLMode) {
#if ENABLE_LBL_BASE_FGA == OFF
                case MULTIMEDIA:
                    MTXAPI_SetRGBGain(DEF_MULTIMEDIA_RGain + 1,DEF_MULTIMEDIA_GGain + 1,DEF_MULTIMEDIA_BGain + 1);
                    break;
                case WEB_SURFING:
                    MTXAPI_SetRGBGain(DEF_WEB_SURFING_RGain + 1,DEF_WEB_SURFING_GGain + 1,DEF_WEB_SURFING_BGain + 1);
                    break;
                case OFFICE:
                    MTXAPI_SetRGBGain(DEF_OFFICE_RGain + 1,DEF_OFFICE_GGain + 1,DEF_OFFICE_BGain + 1);
                    break;
                case READING:
                    MTXAPI_SetRGBGain(DEF_READING_RGain + 1,DEF_READING_GGain + 1,DEF_READING_BGain + 1);
                    break;
#else  
                case MULTIMEDIA:                 
                    BFAPI_GetRGBGainDependOnGamma(CLRTMP_6500K, &Gain[0],&Gain[1],&Gain[2]);	
                    MTXAPI_SetRGBGain(Gain[0] + DEF_MULTIMEDIA_RGain_Shift + 1, Gain[1] + DEF_MULTIMEDIA_GGain_Shift + 1, Gain[2] + DEF_MULTIMEDIA_BGain_Shift + 1);
                    break;
                case WEB_SURFING:                
                    BFAPI_GetRGBGainDependOnGamma(CLRTMP_6500K, &Gain[0],&Gain[1],&Gain[2]);			
                    MTXAPI_SetRGBGain(Gain[0] + DEF_WEB_SURFING_RGain_Shift + 1, Gain[1] + DEF_WEB_SURFING_GGain_Shift + 1, Gain[2] + DEF_WEB_SURFING_BGain_Shift + 1);
                    break;
                case OFFICE:                
                    BFAPI_GetRGBGainDependOnGamma(CLRTMP_6500K, &Gain[0],&Gain[1],&Gain[2]);			
                    MTXAPI_SetRGBGain(Gain[0] + DEF_OFFICE_RGain_Shift + 1, Gain[1] + DEF_OFFICE_GGain_Shift + 1, Gain[2] + DEF_OFFICE_BGain_Shift + 1);
                    break;
                case READING:                
                    BFAPI_GetRGBGainDependOnGamma(CLRTMP_6500K, &Gain[0],&Gain[1],&Gain[2]);			
                    MTXAPI_SetRGBGain(Gain[0] + DEF_READING_RGain_Shift + 1, Gain[1] + DEF_READING_GGain_Shift + 1, Gain[2] + DEF_READING_BGain_Shift + 1);
#endif
                default:
                    break;     
            }    
            break;     
#if ENABLE_PICTURE_MODE_REC709 == ON       
        case PICTURE_MODE_REC709:
            MTXAPI_EnableLocalMatrix(TRUE);                      
            BFAPI_GetRGBGainDependOnGamma(CLRTMP_6500K, &Gain[0],&Gain[1],&Gain[2]);			
            MTXAPI_SetRGBGain(Gain[0],Gain[1],Gain[2]);            
            break;
#endif            
#if ENABLE_PICTURE_MODE_DARKROOM == ON       
        case PICTURE_MODE_DARKROOM:
            MTXAPI_EnableLocalMatrix(TRUE);                      
            BFAPI_GetRGBGainDependOnGamma(CLRTMP_6500K, &Gain[0],&Gain[1],&Gain[2]);			
            MTXAPI_SetRGBGain(Gain[0],Gain[1],Gain[2]);            
            break;
#endif     
        case PICTURE_MODE_SRGB:
            MTXAPI_EnableLocalMatrix(TRUE);                      
            BFAPI_GetRGBGainDependOnGamma(CLRTMP_6500K, &Gain[0],&Gain[1],&Gain[2]);			
            MTXAPI_SetRGBGain(Gain[0],Gain[1],Gain[2]);            
            break;
        case PICTURE_MODE_USER:
            Gain[0] = (USHRT)GetRGain255();
            Gain[1] = (USHRT)GetGGain255();
            Gain[2] = (USHRT)GetBGain255();
            if(UserData.bSensEyeDemo==PICTURE_DUALMODE_ON){
                MTXAPI_EnableLocalMatrix(TRUE);  
                MTXAPI_SetRGBGain(Gain[0],Gain[1],Gain[2]);            
            }
            else{
                BFAPI_SetLocalMatrix(0);     
                MTXAPI_EnableLocalMatrix(FALSE); 
                // MTXAPI_SetRGBGain(Gain[0], Gain[1], Gain[2]);
            }
            break;

        case PICTURE_MODE_STANDARD:
        case PICTURE_MODE_ECO:
            if(UserData.bSensEyeDemo==PICTURE_DUALMODE_ON){
                MTXAPI_EnableLocalMatrix(TRUE);  
                SetColorTemperature(UserData.ucColorTemp);
            }
            else{
                BFAPI_SetLocalMatrix(0);     
                MTXAPI_EnableLocalMatrix(FALSE); 
            }
            break;            
        default:        
            BFAPI_SetLocalMatrix(0);            
            MTXAPI_EnableLocalMatrix(FALSE);          
            break;     
    }            
}

#else
void SetLocalMatrix(void)
{
    BFAPI_SetActiveWindow(BF_WINDOW_1);	
    switch(UserData.ucBFMode) {
        case PICTURE_MODE_MOVIE:
              MTXAPI_EnableLocalMatrix(TRUE);		  			
              //MTXAPI_SetRGBGain(DEF_6500KRGain + 1,DEF_6500KGGain + 1,DEF_6500KBGain + 1);
              MTXAPI_SetRGBGain(CalibData.uc6500KRGain,CalibData.uc6500KGGain,CalibData.uc6500KBGain);	
	 break;
        case PICTURE_MODE_GAME:	
              MTXAPI_EnableLocalMatrix(TRUE);		  			
              MTXAPI_SetRGBGain(CalibData.uc9300KRGain, CalibData.uc9300KGGain, CalibData.uc9300KBGain);
	 break;	
#if ENABLE_PICTURE_MODE_MBOOK == ON 
        case PICTURE_MODE_MBOOK:
              MTXAPI_EnableLocalMatrix(TRUE);		  			
              MTXAPI_SetRGBGain(DEF_6500KRGain + 1,DEF_6500KGGain + 1,DEF_6500KBGain + 1);	  		  
	 break;	 
#endif
        case PICTURE_MODE_PHOTO:	
              MTXAPI_EnableLocalMatrix(TRUE);		  			
              MTXAPI_SetRGBGain(CalibData.uc9300KRGain ,CalibData.uc9300KGGain ,CalibData.uc9300KBGain );              
	 break;	 
        case PICTURE_MODE_LOW_BL:	
              MTXAPI_EnableLocalMatrix(TRUE);		  			
                 switch(UserData.ucLBLMode) {
                     case MULTIMEDIA:
            	     MTXAPI_SetRGBGain(DEF_MULTIMEDIA_RGain + 1,DEF_MULTIMEDIA_GGain + 1,DEF_MULTIMEDIA_BGain + 1);
             	 break;
                     case WEB_SURFING:
             	     MTXAPI_SetRGBGain(DEF_WEB_SURFING_RGain + 1,DEF_WEB_SURFING_GGain + 1,DEF_WEB_SURFING_BGain + 1);
             	 break;
                     case OFFICE:
             	     MTXAPI_SetRGBGain(DEF_OFFICE_RGain + 1,DEF_OFFICE_GGain + 1,DEF_OFFICE_BGain + 1);
             	 break;
                     case READING:
             	     MTXAPI_SetRGBGain(DEF_READING_RGain + 1,DEF_READING_GGain + 1,DEF_READING_BGain + 1);
             	 break;	 
                     default:
                         break;	 
                 }			
	 break;	 
        default:		
              BFAPI_SetLocalMatrix(0);			
              MTXAPI_EnableLocalMatrix(FALSE);		  
            break;	 
    }            
}


#endif


#if ENABLE_PICTURE_MODE_ANIMATION == ON
void BFAPI_SetPreACEModeWithStep(IGBlock *ptr, UCHAR Step)
{
    code IGBlock DefaultIG = {16, 0, 64, 128, 192, 256, 320, 384, 448, 512, 576, 640, 704, 768, 832, 896, 960,1024}; // 1:1 Linear
    code IGBlock Level10IG = {16, 0x20, 0x9c, 0xf8, 0x148, 0x18d, 0x1c5, 0x1f9, 0x229, 0x255, 0x285, 0x2B6, 0x2e6, 0x316, 0x34a, 0x386, 0x3c2,1024}; // 1:1 Linear

    UCHAR i, tmpReg;
    IGBlock *pIG;
    IGBlock *MinpIG;

    tmpReg = SC_ACE_FUNC_CTRL2 & 0x0E;
    //if (CurBFWin() == BF_WINDOW_2)
        //tmpReg |= 0x20;

    tmpReg |= 0x50; // Write Gamma
    SC_ACE_FUNC_CTRL2 = tmpReg;

    if (ptr == 0)
        pIG = &DefaultIG;
    else
        pIG = ptr;

#if OSDTYPE == OSD_BENQ_V2
    MinpIG = ptr;
    pIG = &Level10IG;
    
for (i = 0; i <= pIG->NumIG; i++) {
    
        if(abs(pIG->IGamma[i]-MinpIG->IGamma[i])<(MAXIMUM_ANIMATION_MODE-1)){
           tmpReg = 1;
        }
        else{
            tmpReg = (abs(pIG->IGamma[i]-MinpIG->IGamma[i])/(MAXIMUM_ANIMATION_MODE-1));
        }

        if(Step == 10){
            SC_ACE_DATA_PORT = pIG->IGamma[i] & 0xFF;
            SC_ACE_DATA_PORT = pIG->IGamma[i] >> 8;
        }
        else{
            if(pIG->IGamma[i]>MinpIG->IGamma[i]){
                if((MinpIG->IGamma[i]+ tmpReg*Step) > pIG->IGamma[i]){
                    SC_ACE_DATA_PORT = pIG->IGamma[i] & 0xFF;
                    SC_ACE_DATA_PORT = pIG->IGamma[i] >> 8;
                }
                else{
                    SC_ACE_DATA_PORT = (MinpIG->IGamma[i]+ tmpReg*Step) & 0xFF;
                    SC_ACE_DATA_PORT = (MinpIG->IGamma[i]+ tmpReg*Step) >> 8;
                }
            }
            else{
                if((MinpIG->IGamma[i]- tmpReg*Step) < pIG->IGamma[i]){
                    SC_ACE_DATA_PORT = pIG->IGamma[i] & 0xFF;
                    SC_ACE_DATA_PORT = pIG->IGamma[i] >> 8;
                }
                else{
                    SC_ACE_DATA_PORT = (MinpIG->IGamma[i]- tmpReg*Step) & 0xFF;
                    SC_ACE_DATA_PORT = (MinpIG->IGamma[i]- tmpReg*Step) >> 8;
                }

            }
        }
}
#else
    for (i = 0; i <= pIG->NumIG; i++) {
        if(i>0 && i<2){
            SC_ACE_DATA_PORT = (pIG->IGamma[i]+(Step/3)) & 0xFF;
            SC_ACE_DATA_PORT = (pIG->IGamma[i]+(Step/3)) >> 8;
        }
        else if(i==2){
            SC_ACE_DATA_PORT = (pIG->IGamma[i]+(Step/2)) & 0xFF;
            SC_ACE_DATA_PORT = (pIG->IGamma[i]+(Step/2)) >> 8;
        }        
        else if(i>=3 && i<=8){
            SC_ACE_DATA_PORT = (pIG->IGamma[i]+(Step)) & 0xFF;
            SC_ACE_DATA_PORT = (pIG->IGamma[i]+(Step)) >> 8;
        }        
        else if(i==9){
            SC_ACE_DATA_PORT = (pIG->IGamma[i]+((Step/6)*5)) & 0xFF;
            SC_ACE_DATA_PORT = (pIG->IGamma[i]+((Step/6)*5)) >> 8;
        }
        else if(i==10){
            SC_ACE_DATA_PORT = (pIG->IGamma[i]+((Step/6)*4)) & 0xFF;
            SC_ACE_DATA_PORT = (pIG->IGamma[i]+((Step/6)*4)) >> 8;
        }
        else if(i==11){
            SC_ACE_DATA_PORT = (pIG->IGamma[i]+((Step/6)*3)) & 0xFF;
            SC_ACE_DATA_PORT = (pIG->IGamma[i]+((Step/6)*3)) >> 8;
        }
        else{
            SC_ACE_DATA_PORT = (pIG->IGamma[i]) & 0xFF;
            SC_ACE_DATA_PORT = (pIG->IGamma[i]) >> 8;
        }
    }
#endif
    // Update I-Gamma
    SC_ACE_FUNC_CTRL2 = tmpReg | 0x90;
    WaitDisVSync();
    BFAPI_EnableACEMode();
    SC_ACE_FUNC_CTRL2 &= ~BIT7;
}
#endif



