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

#if ENABLE_GAMMA == ON

#ifdef ENABLE_512_GAMMA

#define GAMMA_512TO320(l0, h0, l1, h1, l2, h2, l3, h3, l4, h4, l5, h5, l6, h6, l7, h7) \
            (l0>>6 | l1>>4 | l2>>2 | l3), h0, h1, h2, h3, \
            (l4>>6 | l5>>4 | l6>>2 | l7), h4, h5, h6, h7

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************
static code Gamma320 GammaTable = {
    {
        GAMMA_512TO320(0,0,0,0,0,0,0,1,0,1,0,3,0,4,0,5),
        GAMMA_512TO320(0,6,0,7,0,8,0,9,0,11,0,12,0,13,0,14),
        GAMMA_512TO320(0,15,128,16,0,17,0,18,128,19,128,20,192,21,192,22),
        GAMMA_512TO320(64,23,64,24,128,25,64,26,64,27,64,28,128,29,128,30),
        GAMMA_512TO320(64,31,0,32,64,33,64,34,64,35,64,36,0,37,0,38),
        GAMMA_512TO320(192,38,128,39,128,40,0,41,0,42,0,43,192,43,128,44),
        GAMMA_512TO320(128,45,128,46,128,47,128,48,128,49,64,50,0,51,0,52),
        GAMMA_512TO320(0,53,192,53,192,54,192,55,128,56,64,57,0,58,0,59),
        GAMMA_512TO320(0,60,0,61,192,61,192,62,128,63,128,64,64,65,0,66),
        GAMMA_512TO320(0,67,192,67,192,68,0,70,192,70,192,71,128,72,64,73),
        GAMMA_512TO320(64,74,0,75,0,76,64,77,64,78,64,79,0,80,0,81),
        GAMMA_512TO320(0,82,0,83,0,84,64,85,64,86,192,86,192,87,192,88),
        GAMMA_512TO320(0,90,0,91,192,91,192,92,192,93,192,94,128,95,64,96),
        GAMMA_512TO320(64,97,128,98,64,99,0,100,0,101,0,102,0,103,192,103),
        GAMMA_512TO320(192,104,192,105,192,106,192,107,192,108,192,109,192,110,192,111),
        GAMMA_512TO320(192,112,192,113,192,114,128,115,64,116,64,117,64,118,64,119),
        GAMMA_512TO320(64,120,0,121,64,122,64,123,64,124,0,125,0,126,64,127),
        GAMMA_512TO320(64,128,128,129,128,130,128,131,192,132,192,133,192,134,192,135),
        GAMMA_512TO320(0,137,0,138,0,139,0,140,0,141,0,142,192,142,192,143),
        GAMMA_512TO320(0,145,0,146,0,147,0,148,64,149,64,150,64,151,64,152),
        GAMMA_512TO320(128,153,128,154,192,155,192,156,192,157,192,158,64,160,64,161),
        GAMMA_512TO320(64,162,64,163,128,164,128,165,128,166,0,168,0,169,0,170),
        GAMMA_512TO320(0,171,0,172,0,173,0,174,64,175,64,176,64,177,64,178),
        GAMMA_512TO320(128,179,192,180,64,182,0,183,0,184,192,184,64,186,64,187),
        GAMMA_512TO320(0,188,64,189,0,190,64,191,0,192,0,193,192,193,128,194),
        GAMMA_512TO320(128,195,128,196,64,197,0,198,192,198,64,199,64,200,64,201),
        GAMMA_512TO320(0,202,192,202,128,203,64,204,0,205,192,205,0,207,192,207),
        GAMMA_512TO320(128,208,128,209,128,210,64,211,0,212,192,212,64,214,192,214),
        GAMMA_512TO320(0,216,192,216,128,217,192,218,192,219,128,220,128,221,128,222),
        GAMMA_512TO320(64,223,64,224,128,225,128,226,128,227,128,228,128,229,128,230),
        GAMMA_512TO320(192,231,192,232,192,233,0,235,0,236,0,237,0,238,0,239),
        GAMMA_512TO320(64,240,64,241,128,242,192,243,0,245,0,247,64,250,0,255),
    },
    {
        GAMMA_512TO320(0,0,0,0,0,0,0,1,0,1,0,3,0,4,0,5),
        GAMMA_512TO320(0,6,0,7,0,8,0,9,0,10,0,11,0,13,0,14),
        GAMMA_512TO320(0,15,0,16,0,17,0,18,64,19,64,20,64,21,64,22),
        GAMMA_512TO320(64,23,64,24,64,25,64,26,128,27,128,28,64,29,64,30),
        GAMMA_512TO320(64,31,64,32,64,33,64,34,64,35,64,36,64,37,64,38),
        GAMMA_512TO320(64,39,0,40,0,41,0,42,0,43,0,44,0,45,192,45),
        GAMMA_512TO320(192,46,192,47,192,48,192,49,128,50,128,51,64,52,64,53),
        GAMMA_512TO320(64,54,0,55,0,56,192,56,192,57,192,58,128,59,64,60),
        GAMMA_512TO320(64,61,0,62,192,62,192,63,192,64,192,65,192,66,192,67),
        GAMMA_512TO320(192,68,192,69,192,70,192,71,192,72,192,73,192,74,192,75),
        GAMMA_512TO320(192,76,192,77,192,78,192,79,192,80,192,81,192,82,192,83),
        GAMMA_512TO320(0,85,0,86,0,87,0,88,0,89,0,90,0,91,0,92),
        GAMMA_512TO320(0,93,0,94,0,95,0,96,192,96,192,97,192,98,192,99),
        GAMMA_512TO320(192,100,192,101,128,102,128,103,128,104,128,105,64,106,64,107),
        GAMMA_512TO320(64,108,64,109,64,110,64,111,64,112,0,113,0,114,0,115),
        GAMMA_512TO320(0,116,0,117,0,118,0,119,0,120,0,121,0,122,192,122),
        GAMMA_512TO320(192,123,192,124,192,125,192,126,192,127,192,128,192,129,128,130),
        GAMMA_512TO320(128,131,128,132,128,133,192,134,192,135,192,136,192,137,0,139),
        GAMMA_512TO320(0,140,0,141,0,142,0,143,64,144,64,145,64,146,64,147),
        GAMMA_512TO320(64,148,64,149,64,150,128,151,128,152,128,153,128,154,128,155),
        GAMMA_512TO320(128,156,128,157,192,158,192,159,192,160,192,161,192,162,192,163),
        GAMMA_512TO320(192,164,192,165,0,167,0,168,0,169,64,170,64,171,64,172),
        GAMMA_512TO320(64,173,64,174,64,175,64,176,64,177,64,178,64,179,64,180),
        GAMMA_512TO320(64,181,64,182,128,183,128,184,128,185,128,186,128,187,128,188),
        GAMMA_512TO320(192,189,192,190,192,191,128,192,64,193,0,194,192,194,128,195),
        GAMMA_512TO320(64,196,0,197,192,197,128,198,64,199,0,200,192,200,128,201),
        GAMMA_512TO320(64,202,0,203,192,203,128,204,64,205,0,206,192,206,192,207),
        GAMMA_512TO320(128,208,64,209,0,210,192,210,192,211,128,212,64,213,0,214),
        GAMMA_512TO320(0,215,192,215,128,216,128,217,64,218,64,219,0,220,0,221),
        GAMMA_512TO320(192,221,192,222,128,223,128,224,64,225,64,226,64,227,64,228),
        GAMMA_512TO320(64,229,64,230,64,231,64,232,64,233,128,234,128,235,192,236),
        GAMMA_512TO320(0,238,0,240,64,241,0,243,128,245,128,249,192,252,0,255),
    },
    {
        GAMMA_512TO320(0,0,0,0,0,0,0,1,0,1,0,2,0,3,0,4),
        GAMMA_512TO320(0,5,0,6,0,7,0,8,0,10,0,11,0,12,128,12),
        GAMMA_512TO320(64,13,0,14,128,15,64,16,0,17,192,17,0,19,128,20),
        GAMMA_512TO320(0,21,192,22,0,24,192,24,0,26,192,26,0,28,192,28),
        GAMMA_512TO320(64,30,192,31,192,32,192,33,192,34,192,35,192,36,0,38),
        GAMMA_512TO320(192,38,192,39,192,40,0,42,192,42,0,44,192,44,0,46),
        GAMMA_512TO320(0,47,0,48,64,49,64,50,128,51,64,52,192,53,192,54),
        GAMMA_512TO320(192,55,192,56,192,57,128,58,192,59,0,61,192,61,0,63),
        GAMMA_512TO320(192,63,192,64,0,66,192,66,0,68,64,69,0,70,128,71),
        GAMMA_512TO320(128,72,64,73,0,75,192,75,192,76,64,78,64,79,0,80),
        GAMMA_512TO320(64,81,64,82,0,83,64,84,192,85,0,87,128,87,128,88),
        GAMMA_512TO320(0,90,192,90,0,92,0,93,192,93,0,95,192,95,128,96),
        GAMMA_512TO320(192,97,192,98,128,99,64,100,0,101,0,102,64,103,0,104),
        GAMMA_512TO320(192,104,64,106,0,107,192,107,0,109,0,110,64,111,0,112),
        GAMMA_512TO320(0,113,64,114,0,115,0,116,64,117,0,118,192,118,128,119),
        GAMMA_512TO320(128,120,128,121,128,122,64,123,64,124,0,125,192,125,64,127),
        GAMMA_512TO320(0,128,192,128,0,130,0,131,64,132,0,133,192,133,128,134),
        GAMMA_512TO320(128,135,128,136,64,137,64,138,128,139,64,140,0,141,64,142),
        GAMMA_512TO320(64,143,0,144,192,144,192,145,0,147,192,147,192,148,0,150),
        GAMMA_512TO320(192,150,192,151,0,153,0,154,192,154,128,155,64,156,64,157),
        GAMMA_512TO320(128,158,64,159,64,160,0,161,192,161,192,162,128,163,128,164),
        GAMMA_512TO320(128,165,128,166,128,167,64,168,64,169,64,170,64,171,0,172),
        GAMMA_512TO320(0,173,0,174,0,175,0,176,0,177,192,177,192,178,192,179),
        GAMMA_512TO320(192,180,192,181,128,182,128,183,64,184,0,185,0,186,192,186),
        GAMMA_512TO320(192,187,192,188,128,189,64,190,192,190,192,191,128,192,64,193),
        GAMMA_512TO320(192,193,128,194,64,195,64,196,192,196,128,197,64,198,0,199),
        GAMMA_512TO320(192,199,128,200,64,201,0,202,192,202,64,203,0,204,192,204),
        GAMMA_512TO320(128,205,64,206,0,207,192,207,128,208,64,209,64,210,0,211),
        GAMMA_512TO320(192,211,128,212,64,213,0,214,0,215,128,215,128,216,64,217),
        GAMMA_512TO320(64,218,192,218,128,219,128,220,128,221,64,222,64,223,192,223),
        GAMMA_512TO320(192,224,192,225,128,226,128,227,192,228,128,229,128,230,128,231),
        GAMMA_512TO320(128,232,192,233,128,234,128,235,128,236,128,237,0,239,0,255),
    }
};
#else
static code Gamma320 GammaTable = {
    {
        0x00,0x01,0x02,0x03,0x04,0x55,0x05,0x06,0x07,0x08,0xAA,0x09,0x0A,0x0B,0x0C,0xFF,0x0D,0x0E,0x0F,0x10,
        0x90,0x12,0x13,0x14,0x15,0x4F,0x16,0x17,0x19,0x1A,0x3A,0x1B,0x1C,0x1D,0x1F,0xE5,0x20,0x21,0x22,0x23,
        0x50,0x25,0x26,0x27,0x28,0xFA,0x29,0x2A,0x2B,0x2C,0x50,0x2E,0x2F,0x30,0x31,0xFA,0x32,0x33,0x34,0x35,
        0x50,0x37,0x38,0x39,0x3A,0xFA,0x3B,0x3C,0x3D,0x3E,0x50,0x40,0x41,0x42,0x43,0xFA,0x44,0x45,0x46,0x47,
        0x00,0x49,0x4A,0x4B,0x4C,0x55,0x4D,0x4E,0x4F,0x50,0xAA,0x51,0x52,0x53,0x54,0xFF,0x55,0x56,0x57,0x58,
        0x00,0x5A,0x5B,0x5C,0x5D,0x00,0x5E,0x5F,0x60,0x61,0x00,0x62,0x63,0x64,0x65,0x00,0x66,0x67,0x68,0x69,
        0x00,0x6A,0x6B,0x6C,0x6D,0x00,0x6E,0x6F,0x70,0x71,0x00,0x72,0x73,0x74,0x75,0x00,0x76,0x77,0x78,0x79,
        0xFC,0x7A,0x7A,0x7B,0x7C,0xAB,0x7D,0x7E,0x7F,0x80,0x56,0x81,0x82,0x83,0x84,0x01,0x85,0x86,0x87,0x88,
        0xFC,0x89,0x89,0x8A,0x8B,0xAA,0x8C,0x8D,0x8E,0x8F,0x55,0x90,0x91,0x92,0x93,0x00,0x94,0x95,0x96,0x97,
        0xFF,0x97,0x98,0x99,0x9A,0xAA,0x9B,0x9C,0x9D,0x9E,0x55,0x9F,0xA0,0xA1,0xA2,0x00,0xA3,0xA4,0xA5,0xA6,
        0xFF,0xA6,0xA7,0xA8,0xA9,0xAA,0xAA,0xAB,0xAC,0xAD,0x55,0xAE,0xAF,0xB0,0xB1,0x00,0xB2,0xB3,0xB4,0xB5,
        0x00,0xB6,0xB7,0xB8,0xB9,0x00,0xBA,0xBB,0xBC,0xBD,0x00,0xBE,0xBF,0xC0,0xC1,0x00,0xC2,0xC3,0xC4,0xC5,
        0x5B,0xC5,0xC6,0xC7,0xC8,0xAC,0xC9,0xC9,0xCA,0xCB,0xF1,0xCC,0xCD,0xCD,0xCE,0x06,0xCF,0xD0,0xD1,0xD2,
        0x1B,0xD2,0xD3,0xD4,0xD5,0x1B,0xD5,0xD6,0xD7,0xD8,0x1B,0xD8,0xD9,0xDA,0xDB,0x1B,0xDB,0xDC,0xDD,0xDE,
        0x00,0xDF,0xE0,0xE1,0xE2,0x00,0xE3,0xE4,0xE5,0xE6,0x00,0xE7,0xE8,0xE9,0xEA,0x00,0xEB,0xEC,0xED,0xEE,
        0x40,0xEF,0xF0,0xF1,0xF2,0x95,0xF3,0xF4,0xF5,0xF6,0xEA,0xF7,0xF8,0xF9,0xFA,0x3F,0xFB,0xFC,0xFD,0xFF,
    },
    {
        0x50,0x00,0x01,0x02,0x03,0xFA,0x04,0x05,0x06,0x07,0x50,0x09,0x0A,0x0B,0x0C,0xFA,0x0D,0x0E,0x0F,0x10,
        0x50,0x12,0x13,0x14,0x15,0xFA,0x16,0x17,0x18,0x19,0x50,0x1B,0x1C,0x1D,0x1E,0xFA,0x1F,0x20,0x21,0x22,
        0x90,0x24,0x25,0x26,0x27,0x4F,0x28,0x29,0x2B,0x2C,0x3A,0x2D,0x2E,0x2F,0x31,0xE5,0x32,0x33,0x34,0x35,
        0x50,0x37,0x38,0x39,0x3A,0xFA,0x3B,0x3C,0x3D,0x3E,0x50,0x40,0x41,0x42,0x43,0xFA,0x44,0x45,0x46,0x47,
        0x00,0x49,0x4A,0x4B,0x4C,0x55,0x4D,0x4E,0x4F,0x50,0xAA,0x51,0x52,0x53,0x54,0xFF,0x55,0x56,0x57,0x58,
        0x00,0x5A,0x5B,0x5C,0x5D,0x00,0x5E,0x5F,0x60,0x61,0x00,0x62,0x63,0x64,0x65,0x00,0x66,0x67,0x68,0x69,
        0x00,0x6A,0x6B,0x6C,0x6D,0x00,0x6E,0x6F,0x70,0x71,0x00,0x72,0x73,0x74,0x75,0x00,0x76,0x77,0x78,0x79,
        0xFC,0x7A,0x7A,0x7B,0x7C,0xAB,0x7D,0x7E,0x7F,0x80,0x56,0x81,0x82,0x83,0x84,0x01,0x85,0x86,0x87,0x88,
        0xFC,0x89,0x89,0x8A,0x8B,0xAA,0x8C,0x8D,0x8E,0x8F,0x55,0x90,0x91,0x92,0x93,0x00,0x94,0x95,0x96,0x97,
        0xFF,0x97,0x98,0x99,0x9A,0xAA,0x9B,0x9C,0x9D,0x9E,0x55,0x9F,0xA0,0xA1,0xA2,0x00,0xA3,0xA4,0xA5,0xA6,
        0x00,0xA7,0xA8,0xA9,0xAA,0x00,0xAB,0xAC,0xAD,0xAE,0x00,0xAF,0xB0,0xB1,0xB2,0x00,0xB3,0xB4,0xB5,0xB6,
        0xFF,0xB6,0xB7,0xB8,0xB9,0xAA,0xBA,0xBB,0xBC,0xBD,0x55,0xBE,0xBF,0xC0,0xC1,0x00,0xC2,0xC3,0xC4,0xC5,
        0x5B,0xC5,0xC6,0xC7,0xC8,0xAC,0xC9,0xC9,0xCA,0xCB,0xF1,0xCC,0xCD,0xCD,0xCE,0x06,0xCF,0xD0,0xD1,0xD2,
        0x1B,0xD2,0xD3,0xD4,0xD5,0x1B,0xD5,0xD6,0xD7,0xD8,0x1B,0xD8,0xD9,0xDA,0xDB,0x1B,0xDB,0xDC,0xDD,0xDE,
        0xFF,0xDE,0xDF,0xE0,0xE1,0xAA,0xE2,0xE3,0xE4,0xE5,0x55,0xE6,0xE7,0xE8,0xE9,0x00,0xEA,0xEB,0xEC,0xED,
        0x94,0xEE,0xEF,0xF0,0xF1,0x3E,0xF2,0xF3,0xF4,0xF6,0x94,0xF7,0xF8,0xF9,0xFA,0x3E,0xFB,0xFC,0xFD,0xFF,
    },
    {
        0x74,0x00,0x01,0x02,0x04,0x23,0x05,0x07,0x08,0x0A,0xDE,0x0B,0x0C,0x0E,0x0F,0x89,0x11,0x12,0x14,0x15,
        0x34,0x17,0x18,0x19,0x1B,0x9E,0x1C,0x1D,0x1F,0x20,0x34,0x22,0x23,0x24,0x26,0x9E,0x27,0x28,0x2A,0x2B,
        0xE4,0x2D,0x2E,0x2F,0x30,0xE4,0x32,0x33,0x34,0x35,0xE4,0x37,0x38,0x39,0x3A,0xE4,0x3C,0x3D,0x3E,0x3F,
        0x50,0x41,0x42,0x43,0x44,0xFA,0x45,0x46,0x47,0x48,0x50,0x4A,0x4B,0x4C,0x4D,0xFA,0x4E,0x4F,0x50,0x51,
        0x50,0x53,0x54,0x55,0x56,0xFA,0x57,0x58,0x59,0x5A,0x50,0x5C,0x5D,0x5E,0x5F,0xFA,0x60,0x61,0x62,0x63,
        0x00,0x65,0x66,0x67,0x68,0x00,0x69,0x6A,0x6B,0x6C,0x00,0x6D,0x6E,0x6F,0x70,0x00,0x71,0x72,0x73,0x74,
        0x00,0x75,0x76,0x77,0x78,0x00,0x79,0x7A,0x7B,0x7C,0x00,0x7D,0x7E,0x7F,0x80,0x00,0x81,0x82,0x83,0x84,
        0x00,0x85,0x86,0x87,0x88,0x00,0x89,0x8A,0x8B,0x8C,0x00,0x8D,0x8E,0x8F,0x90,0x00,0x91,0x92,0x93,0x94,
        0xAC,0x95,0x95,0x96,0x97,0x05,0x98,0x99,0x9A,0x9B,0xAF,0x9B,0x9C,0x9D,0x9E,0x05,0x9F,0xA0,0xA1,0xA2,
        0xAF,0xA2,0xA3,0xA4,0xA5,0x05,0xA6,0xA7,0xA8,0xA9,0xAF,0xA9,0xAA,0xAB,0xAC,0x05,0xAD,0xAE,0xAF,0xB0,
        0x00,0xB1,0xB2,0xB3,0xB4,0x00,0xB5,0xB6,0xB7,0xB8,0x00,0xB9,0xBA,0xBB,0xBC,0x00,0xBD,0xBE,0xBF,0xC0,
        0xC6,0xC0,0xC1,0xC2,0xC2,0xB1,0xC3,0xC4,0xC4,0xC5,0x6C,0xC6,0xC6,0xC7,0xC8,0x1B,0xC8,0xC9,0xCA,0xCB,
        0x1B,0xCB,0xCC,0xCD,0xCE,0x1B,0xCE,0xCF,0xD0,0xD1,0x1B,0xD1,0xD2,0xD3,0xD4,0x1B,0xD4,0xD5,0xD6,0xD7,
        0x1B,0xD7,0xD8,0xD9,0xDA,0x1B,0xDA,0xDB,0xDC,0xDD,0x1B,0xDD,0xDE,0xDF,0xE0,0x1B,0xE0,0xE1,0xE2,0xE3,
        0x5B,0xE3,0xE4,0xE5,0xE6,0xAC,0xE7,0xE7,0xE8,0xE9,0xF1,0xEA,0xEB,0xEB,0xEC,0x06,0xED,0xEE,0xEF,0xF0,
        0xFF,0xF0,0xF1,0xF2,0xF3,0xAA,0xF4,0xF5,0xF6,0xF7,0x55,0xF8,0xF9,0xFA,0xFB,0x00,0xFC,0xFD,0xFE,0xFF,
    }
};
#endif

#endif //#if ENABLE_GAMMA == ON
