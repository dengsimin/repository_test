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

#if ENABLE_OD == ON
//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************
static code UCHAR ucODTable_4ms[] = { //4ms
#if ENABLE_OD_TRANSFORM == ON
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x12,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x25,0x25,0x20,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x12,0x12,
    0x38,0x38,0x37,0x30,0x27,0x1F,0x1F,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x12,0x12,
    0x4B,0x48,0x48,0x47,0x40,0x3A,0x3A,0x38,0x38,0x30,0x30,0x2B,0x2B,0x22,0x22,0x13,0x13,
    0x60,0x5E,0x5C,0x5C,0x55,0x50,0x48,0x42,0x40,0x3C,0x32,0x2E,0x2B,0x22,0x22,0x22,0x16,
    0x78,0x78,0x78,0x6D,0x6D,0x65,0x60,0x58,0x58,0x58,0x4D,0x48,0x44,0x3C,0x3A,0x3A,0x16,
    0x84,0x83,0x82,0x81,0x80,0x7D,0x76,0x70,0x68,0x62,0x57,0x56,0x56,0x4E,0x4E,0x4D,0x1F,
    0xA7,0xA7,0xA7,0xA3,0xA3,0x92,0x92,0x86,0x80,0x77,0x76,0x6B,0x66,0x60,0x52,0x52,0x1F,
    0xA7,0xA7,0xA7,0xA2,0xA2,0xA1,0x9C,0x9C,0x95,0x90,0x8A,0x87,0x80,0x75,0x6F,0x6F,0x2E,
    0xD2,0xD2,0xD2,0xCA,0xCA,0xC0,0xC0,0xB2,0xB2,0xA5,0xA0,0x98,0x8F,0x8F,0x6F,0x6F,0x2E,
    0xD2,0xD2,0xD2,0xCA,0xCA,0xC5,0xC4,0xC1,0xBD,0xBB,0xB6,0xB0,0xA6,0xA3,0x9A,0x9A,0x3E,
    0xEE,0xEE,0xEE,0xEB,0xEB,0xE5,0xE5,0xDD,0xDD,0xD2,0xD2,0xC4,0xC0,0xBA,0x9A,0x9A,0x3E,
    0xEE,0xEE,0xEE,0xEB,0xEB,0xE5,0xE5,0xE4,0xE4,0xDE,0xDC,0xD8,0xD5,0xD0,0xCA,0xC9,0x70,
    0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFC,0xFC,0xF6,0xF6,0xE3,0xE0,0xD9,0x70,
    0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFC,0xFC,0xF6,0xF6,0xF5,0xF4,0xF0,0xEE,
#else
    0xFE,0x00,0x12,0x00,0xF0,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x02,0xFE,0x13,0x12,0x0B,0xF0,0x15,0x10,0xFE,0x00,0x20,0x00,0x00,0x00,0x1E,0x00,
    0x00,0x00,0x1E,0x00,0x00,0x00,0x1E,0x00,0x00,0x00,0x1E,0x00,0x00,0x00,0x1E,0x00,
    0x00,0x00,0x1E,0x00,0x00,0x00,0x1E,0x00,0x00,0x00,0x1E,0x00,0x00,0x00,0x1E,0x00,
    0x00,0x00,0x1E,0x00,0x00,0x00,0x1E,0x00,0xF4,0x00,0x1E,0x00,0x00,0x00,0x12,0x00,
    0x00,0x00,0x13,0x25,0x04,0xFB,0x13,0x25,0xFB,0xFE,0x17,0x20,0xF7,0x00,0x12,0x1E,
    0xF8,0x00,0x09,0x1E,0x00,0x00,0x01,0x1E,0xFF,0x00,0x01,0x1E,0x00,0x00,0x00,0x1E,
    0x00,0x00,0x00,0x1E,0x00,0x00,0x00,0x1E,0x00,0x00,0x00,0x1E,0x00,0x00,0x00,0x1E,
    0x00,0x00,0x00,0x1E,0x00,0x00,0x00,0x1E,0x00,0xF4,0x00,0x1E,0x00,0x00,0x00,0x12,
    0xFD,0x00,0x13,0x38,0x01,0xFF,0x10,0x38,0x06,0xF9,0x11,0x37,0x02,0xF7,0x17,0x30,
    0x02,0xF8,0x19,0x27,0x00,0x00,0x1B,0x1F,0xFF,0xFF,0x1B,0x1F,0x00,0x00,0x1A,0x1E,
    0xF8,0x00,0x1A,0x1E,0x00,0x00,0x12,0x1E,0xFB,0x00,0x12,0x1E,0x00,0x00,0x0D,0x1E,
    0xF7,0x00,0x0D,0x1E,0x00,0x00,0x04,0x1E,0xFD,0xF4,0x04,0x1E,0x00,0x00,0x01,0x12,
    0x01,0xFD,0x15,0x4B,0xFE,0x00,0x16,0x48,0x01,0xFF,0x14,0x48,0x00,0xF9,0x15,0x47,
    0x01,0xFA,0x15,0x40,0xF8,0x00,0x16,0x3A,0xFC,0xFE,0x0E,0x3A,0xFE,0x00,0x0A,0x38,
    0x04,0xF8,0x08,0x38,0xF6,0x00,0x0C,0x30,0x01,0xFB,0x02,0x30,0xFD,0x00,0x03,0x2B,
    0x00,0xF7,0x00,0x2B,0x00,0x00,0x00,0x22,0x0F,0xF1,0x00,0x22,0xF4,0x00,0x0F,0x13,
    0x02,0xFE,0x18,0x60,0x02,0xFE,0x1A,0x5E,0xF5,0x00,0x1C,0x5C,0x07,0xF9,0x11,0x5C,
    0xFD,0xFB,0x18,0x55,0x03,0xF8,0x15,0x50,0xFE,0xFA,0x18,0x48,0x02,0xFE,0x16,0x42,
    0x04,0xFC,0x18,0x40,0xFF,0xF6,0x1C,0x3C,0xFF,0xFC,0x1B,0x32,0xFF,0xFD,0x1A,0x2E,
    0x01,0xF7,0x19,0x2B,0xFE,0x00,0x1A,0x22,0x00,0x00,0x18,0x22,0xE8,0xF4,0x18,0x22,
    0xFF,0x00,0x0C,0x78,0xFF,0x00,0x0B,0x78,0x0A,0xF5,0x0A,0x78,0xFF,0x00,0x14,0x6D,
    0x05,0xF8,0x13,0x6D,0xFE,0xFB,0x18,0x65,0x02,0xF8,0x16,0x60,0xF8,0x00,0x18,0x58,
    0xFA,0x00,0x10,0x58,0x00,0xF5,0x0A,0x58,0x04,0xFB,0x0A,0x4D,0x04,0xFC,0x0E,0x48,
    0x00,0xF8,0x12,0x44,0x02,0xFE,0x12,0x3C,0xFF,0x00,0x14,0x3A,0xF6,0xDC,0x13,0x3A,
    0x01,0xFF,0x23,0x84,0x01,0xFF,0x24,0x83,0xFD,0xFF,0x25,0x82,0x01,0xFF,0x22,0x81,
    0xF2,0xFD,0x23,0x80,0x07,0xF9,0x15,0x7D,0xFA,0xFA,0x1C,0x76,0x02,0xF8,0x16,0x70,
    0xFD,0xFA,0x18,0x68,0x0A,0xF5,0x15,0x62,0xF6,0xFF,0x1F,0x57,0xFB,0x00,0x15,0x56,
    0x02,0xF8,0x10,0x56,0xF2,0x00,0x12,0x4E,0x01,0xFF,0x04,0x4E,0xFB,0xD2,0x05,0x4D,
    0x00,0x00,0x00,0xA7,0x00,0x00,0x00,0xA7,0xFF,0xFC,0x00,0xA7,0x00,0x00,0xFF,0xA3,
    0x10,0xEF,0xFF,0xA3,0xFB,0x00,0x0F,0x92,0x0C,0xF4,0x0A,0x92,0xFF,0xFA,0x16,0x86,
    0x04,0xF7,0x15,0x80,0xFB,0xFF,0x19,0x77,0x08,0xF5,0x14,0x76,0xFE,0xFB,0x1C,0x6B,
    0xFB,0xFA,0x1A,0x66,0x08,0xF2,0x15,0x60,0x00,0x00,0x1D,0x52,0xF2,0xCD,0x1D,0x52,
    0x00,0x00,0x2B,0xA7,0x00,0x00,0x2B,0xA7,0xFD,0xFB,0x2B,0xA7,0x00,0x00,0x28,0xA2,
    0xF7,0xFF,0x28,0xA2,0x05,0xFB,0x1F,0xA1,0xF2,0x00,0x24,0x9C,0x07,0xF9,0x16,0x9C,
    0xF8,0xFB,0x1D,0x95,0x01,0xFA,0x15,0x90,0xFB,0xFD,0x16,0x8A,0xFE,0xF9,0x11,0x87,
    0x0B,0xF5,0x0F,0x80,0xE6,0xFA,0x1A,0x75,0x00,0x00,0x00,0x6F,0x00,0xBF,0x00,0x6F,
    0x00,0x00,0x00,0xD2,0x00,0x00,0x00,0xD2,0x00,0xF8,0x00,0xD2,0x00,0x00,0x00,0xCA,
    0x05,0xF6,0x00,0xCA,0xFF,0x00,0x05,0xC0,0x0B,0xF2,0x04,0xC0,0xFC,0x00,0x0F,0xB2,
    0x0B,0xF3,0x0B,0xB2,0x00,0xFB,0x16,0xA5,0x02,0xF8,0x16,0xA0,0xFF,0xF7,0x18,0x98,
    0xFD,0x00,0x17,0x8F,0x17,0xE0,0x14,0x8F,0x00,0x00,0x2B,0x6F,0xE5,0xBF,0x2B,0x6F,
    0x00,0x00,0x1C,0xD2,0x00,0x00,0x1C,0xD2,0x05,0xF8,0x1C,0xD2,0x00,0x00,0x21,0xCA,
    0xFF,0xFB,0x21,0xCA,0x01,0xFF,0x20,0xC5,0xFB,0xFD,0x21,0xC4,0x04,0xFC,0x1C,0xC1,
    0xF7,0xFE,0x20,0xBD,0x05,0xFB,0x17,0xBB,0xF8,0xFA,0x1C,0xB6,0x06,0xF6,0x14,0xB0,
    0xFD,0xFD,0x1A,0xA6,0xE9,0xF7,0x17,0xA3,0x00,0x00,0x00,0x9A,0x00,0xA4,0x00,0x9A,
    0x00,0x00,0x00,0xEE,0x00,0x00,0x00,0xEE,0x00,0xFD,0x00,0xEE,0x00,0x00,0x00,0xEB,
    0x00,0xFA,0x00,0xEB,0x00,0x00,0x00,0xE5,0x07,0xF8,0x00,0xE5,0x00,0x00,0x07,0xDD,
    0x05,0xF5,0x07,0xDD,0xFE,0x00,0x0C,0xD2,0x0A,0xF2,0x0A,0xD2,0x01,0xFC,0x14,0xC4,
    0x01,0xFA,0x15,0xC0,0x1A,0xE0,0x16,0xBA,0xFF,0x00,0x30,0x9A,0x03,0xA4,0x2F,0x9A,
    0x00,0x00,0x0F,0xEE,0x00,0x00,0x0F,0xEE,0x03,0xFD,0x0F,0xEE,0x00,0x00,0x12,0xEB,
    0x06,0xFA,0x12,0xEB,0x00,0x00,0x18,0xE5,0x01,0xFF,0x18,0xE5,0x00,0x00,0x19,0xE4,
    0x05,0xFA,0x19,0xE4,0x02,0xFE,0x1E,0xDE,0xFE,0xFC,0x20,0xDC,0x03,0xFD,0x1E,0xD8,
    0xF2,0xFB,0x21,0xD5,0x03,0xFA,0x13,0xD0,0xFA,0xFF,0x16,0xCA,0xF0,0xA7,0x10,0xC9,
    0x00,0x00,0x00,0xFD,0x00,0x00,0x00,0xFD,0x00,0x00,0x00,0xFD,0x00,0x00,0x00,0xFD,
    0x00,0x00,0x00,0xFD,0x00,0x00,0x00,0xFD,0x00,0x00,0x00,0xFD,0x00,0x00,0x00,0xFD,
    0x00,0xFF,0x00,0xFD,0x00,0x00,0x00,0xFC,0x00,0xFA,0x00,0xFC,0x00,0x00,0x00,0xF6,
    0x12,0xED,0x00,0xF6,0x02,0xFD,0x12,0xE3,0x03,0xF9,0x14,0xE0,0x67,0x97,0x17,0xD9,
    0x00,0x00,0x03,0xFD,0x00,0x00,0x03,0xFD,0x00,0x00,0x03,0xFD,0x00,0x00,0x03,0xFD,
    0x00,0x00,0x03,0xFD,0x00,0x00,0x03,0xFD,0x00,0x00,0x03,0xFD,0x00,0x00,0x03,0xFD,
    0x01,0xFF,0x03,0xFD,0x00,0x00,0x04,0xFC,0x06,0xFA,0x04,0xFC,0x00,0x00,0x0A,0xF6,
    0x01,0xFF,0x0A,0xF6,0x01,0xFF,0x0B,0xF5,0x04,0xFC,0x0C,0xF4,0x02,0xFE,0x10,0xF0,
#endif
};

static code UCHAR ucODTable_3ms[] = { // 3ms
#if ENABLE_OD_TRANSFORM == ON
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x16,0x10,0x0E,0x0C,0x0A,0x06,0x06,0x04,0x04,0x04,0x04,0x00,0x00,0x00,0x00,0x00,0x00,
    0x28,0x26,0x20,0x1E,0x16,0x14,0x12,0x12,0x0C,0x0C,0x0A,0x0A,0x08,0x08,0x06,0x06,0x06,
    0x3E,0x3A,0x36,0x30,0x2E,0x26,0x22,0x20,0x1E,0x1C,0x1A,0x16,0x14,0x12,0x0E,0x0A,0x0A,
    0x58,0x4E,0x4A,0x46,0x40,0x3E,0x36,0x32,0x2E,0x2A,0x26,0x24,0x1E,0x1A,0x16,0x14,0x10,
    0x6C,0x64,0x5E,0x5A,0x56,0x50,0x4E,0x42,0x3E,0x3C,0x36,0x32,0x2E,0x26,0x24,0x20,0x1E,
    0x80,0x7C,0x74,0x6E,0x6A,0x66,0x60,0x5E,0x54,0x4C,0x48,0x40,0x34,0x30,0x2C,0x28,0x24,
    0x90,0x90,0x88,0x84,0x7E,0x7A,0x76,0x70,0x6E,0x62,0x5A,0x52,0x4A,0x44,0x3C,0x34,0x30,
    0xA0,0xA0,0x9A,0x98,0x90,0x8A,0x88,0x86,0x80,0x7E,0x6C,0x64,0x54,0x4C,0x44,0x3E,0x36,
    0xB0,0xB0,0xAE,0xA8,0xA4,0xA0,0x9E,0x98,0x94,0x90,0x8E,0x7A,0x70,0x64,0x58,0x50,0x4A,
    0xC2,0xBE,0xBA,0xB8,0xB4,0xB0,0xAC,0xAA,0xA8,0xA4,0xA0,0x9E,0x88,0x80,0x70,0x68,0x60,
    0xD0,0xCE,0xCC,0xCA,0xC8,0xC6,0xC0,0xBE,0xBB,0xB8,0xB4,0xB0,0xAE,0x92,0x84,0x78,0x70,
    0xE6,0xE4,0xE2,0xE0,0xDE,0xDA,0xD8,0xD4,0xD0,0xCA,0xC8,0xC6,0xC0,0xBE,0x98,0x8C,0x80,
    0xE8,0xE6,0xE4,0xE2,0xE0,0xDE,0xDD,0xDC,0xDA,0xD8,0xD6,0xD4,0xD2,0xD0,0xCA,0xB0,0xA4,
    0xFF,0xFC,0xFC,0xF8,0xF8,0xF6,0xF6,0xF6,0xF6,0xF4,0xF4,0xF4,0xF4,0xE6,0xE0,0xDA,0xC0,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF6,0xF0,0xE8,
#else
    0xFA,0x00,0x16,0x00,0xFE,0x00,0x10,0x00,0xFE,0x00,0x0E,0x00,0xFE,0x00,0x0C,0x00,
    0xFC,0x00,0x0A,0x00,0x00,0x00,0x06,0x00,0xFE,0x00,0x06,0x00,0x00,0x00,0x04,0x00,
    0x00,0x00,0x04,0x00,0x00,0x00,0x04,0x00,0xFC,0x00,0x04,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x04,0xFA,0x12,0x16,0xFC,0xFE,0x16,0x10,0x00,0xFE,0x12,0x0E,0xFA,0xFE,0x12,0x0C,
    0x02,0xFC,0x0C,0x0A,0xFE,0x00,0x0E,0x06,0x02,0xFE,0x0C,0x06,0xFA,0x00,0x0E,0x04,
    0x00,0x00,0x08,0x04,0xFE,0x00,0x08,0x04,0x04,0xFC,0x06,0x04,0xFE,0x00,0x0A,0x00,
    0x00,0x00,0x08,0x00,0xFE,0x00,0x08,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x06,0x00,
    0xFE,0xFE,0x16,0x28,0x02,0xFA,0x14,0x26,0xFC,0xFE,0x16,0x20,0x06,0xF8,0x12,0x1E,
    0xFA,0xFE,0x18,0x16,0xFE,0xFE,0x12,0x14,0xFE,0x00,0x10,0x12,0x04,0xFA,0x0E,0x12,
    0xFE,0x00,0x12,0x0C,0x00,0xFE,0x10,0x0C,0xFC,0x00,0x10,0x0A,0x00,0xFE,0x0C,0x0A,
    0xFE,0x00,0x0C,0x08,0xFE,0xFE,0x0A,0x08,0xFC,0x00,0x08,0x06,0x00,0x00,0x04,0x06,
    0xFA,0xFC,0x1A,0x3E,0x00,0xFC,0x14,0x3A,0x02,0xFA,0x14,0x36,0xFC,0xFE,0x16,0x30,
    0x06,0xF8,0x12,0x2E,0xFC,0xFC,0x18,0x26,0xFE,0xFE,0x14,0x22,0xFE,0xFE,0x12,0x20,
    0xFE,0xFE,0x10,0x1E,0xFE,0xFE,0x0E,0x1C,0x02,0xFC,0x0C,0x1A,0xFC,0xFE,0x0E,0x16,
    0xFE,0xFE,0x0A,0x14,0x00,0xFC,0x08,0x12,0x02,0xFC,0x08,0x0E,0xFC,0x00,0x0A,0x0A,
    0x02,0xF6,0x14,0x58,0xFE,0xFC,0x16,0x4E,0x00,0xFC,0x14,0x4A,0x02,0xFA,0x14,0x46,
    0xFC,0xFE,0x16,0x40,0x06,0xF8,0x12,0x3E,0xF8,0xFC,0x18,0x36,0x00,0xFC,0x10,0x32,
    0x02,0xFC,0x10,0x2E,0xFE,0xFC,0x12,0x2A,0xFE,0xFE,0x10,0x26,0x02,0xFA,0x0E,0x24,
    0xFC,0xFC,0x10,0x1E,0x02,0xFC,0x0C,0x1A,0xFE,0xFE,0x0E,0x16,0x02,0xFC,0x0C,0x14,
    0x04,0xF8,0x14,0x6C,0xFE,0xFA,0x18,0x64,0xFE,0xFC,0x16,0x5E,0x00,0xFC,0x14,0x5A,
    0x02,0xFA,0x14,0x56,0xFC,0xFE,0x16,0x50,0x0A,0xF4,0x12,0x4E,0xFA,0xFC,0x1C,0x42,
    0xFA,0xFE,0x16,0x3E,0x02,0xFA,0x10,0x3C,0xFC,0xFC,0x12,0x36,0xF8,0xFC,0x0E,0x32,
    0x04,0xF8,0x06,0x2E,0xFE,0xFE,0x0A,0x26,0x00,0xFC,0x08,0x24,0xFE,0xFE,0x08,0x20,
    0x04,0xFC,0x10,0x80,0x00,0xF8,0x14,0x7C,0x02,0xFA,0x14,0x74,0xFE,0xFC,0x16,0x6E,
    0x00,0xFC,0x14,0x6A,0x02,0xFA,0x14,0x66,0xFC,0xFE,0x16,0x60,0x08,0xF6,0x12,0x5E,
    0xFC,0xF8,0x1A,0x54,0xFC,0xFC,0x16,0x4C,0x00,0xF8,0x12,0x48,0x04,0xF4,0x12,0x40,
    0xFE,0xFC,0x16,0x34,0xFC,0xFC,0x14,0x30,0xFC,0xFC,0x10,0x2C,0x00,0xFC,0x0C,0x28,
    0x00,0x00,0x10,0x90,0x02,0xF8,0x10,0x90,0x02,0xFC,0x12,0x88,0xFE,0xFA,0x14,0x84,
    0xFE,0xFC,0x12,0x7E,0x02,0xFC,0x10,0x7A,0x04,0xFA,0x12,0x76,0xFC,0xFE,0x16,0x70,
    0x0A,0xF4,0x12,0x6E,0xF6,0xF8,0x1C,0x62,0x00,0xF8,0x12,0x5A,0xF8,0xF8,0x12,0x52,
    0xFE,0xFA,0x0A,0x4A,0x00,0xF8,0x08,0x44,0x02,0xF8,0x08,0x3C,0xFC,0xFC,0x0A,0x34,
    0x00,0x00,0x10,0xA0,0x04,0xFA,0x10,0xA0,0xFC,0xFE,0x14,0x9A,0x04,0xF8,0x10,0x98,
    0x02,0xFA,0x14,0x90,0x00,0xFE,0x16,0x8A,0xFC,0xFE,0x16,0x88,0x02,0xFA,0x12,0x86,
    0xFE,0xFE,0x14,0x80,0x10,0xEE,0x12,0x7E,0xF4,0xF8,0x22,0x6C,0x06,0xF0,0x16,0x64,
    0xFC,0xF8,0x1C,0x54,0xFC,0xF8,0x18,0x4C,0xFE,0xFA,0x14,0x44,0x02,0xF8,0x12,0x3E,
    0xFC,0x00,0x12,0xB0,0xFE,0xFE,0x0E,0xB0,0x04,0xFA,0x0C,0xAE,0x00,0xFC,0x10,0xA8,
    0x00,0xFC,0x10,0xA4,0xFE,0xFE,0x10,0xA0,0x04,0xFA,0x0E,0x9E,0x02,0xFC,0x12,0x98,
    0x00,0xFC,0x14,0x94,0xFE,0xFE,0x14,0x90,0x12,0xEC,0x12,0x8E,0xF4,0xF6,0x24,0x7A,
    0x04,0xF4,0x18,0x70,0xFC,0xF4,0x1C,0x64,0x00,0xF8,0x18,0x58,0xFE,0xFA,0x18,0x50,
    0x02,0xFC,0x0E,0xC2,0x02,0xFC,0x10,0xBE,0x00,0xFE,0x12,0xBA,0x02,0xFC,0x12,0xB8,
    0x02,0xFC,0x14,0xB4,0xFE,0xFC,0x16,0xB0,0x00,0xFE,0x14,0xAC,0xFF,0xFE,0x14,0xAA,
    0x01,0xFC,0x13,0xA8,0x00,0xFC,0x14,0xA4,0xFE,0xFE,0x14,0xA0,0x14,0xEA,0x12,0x9E,
    0xEC,0xF8,0x26,0x88,0x02,0xF0,0x12,0x80,0xFC,0xF8,0x14,0x70,0x00,0xF8,0x10,0x68,
    0x00,0xFE,0x16,0xD0,0x00,0xFE,0x16,0xCE,0x00,0xFE,0x16,0xCC,0x00,0xFE,0x16,0xCA,
    0xFE,0xFE,0x16,0xC8,0x04,0xFA,0x14,0xC6,0xFE,0xFE,0x18,0xC0,0xFF,0xFD,0x16,0xBE,
    0xFD,0xFD,0x15,0xBB,0x02,0xFC,0x12,0xB8,0x02,0xFC,0x14,0xB4,0xFC,0xFE,0x16,0xB0,
    0x1A,0xE4,0x12,0xAE,0xE8,0xF2,0x2C,0x92,0x00,0xF4,0x14,0x84,0xFC,0xF8,0x14,0x78,
    0x00,0xFE,0x02,0xE6,0x00,0xFE,0x02,0xE4,0x00,0xFE,0x02,0xE2,0x00,0xFE,0x02,0xE0,
    0x02,0xFC,0x02,0xDE,0x01,0xFE,0x04,0xDA,0x03,0xFC,0x05,0xD8,0x02,0xFC,0x08,0xD4,
    0x04,0xFA,0x0A,0xD0,0x00,0xFE,0x0E,0xCA,0x00,0xFE,0x0E,0xC8,0x04,0xFA,0x0E,0xC6,
    0x00,0xFE,0x12,0xC0,0x20,0xDA,0x12,0xBE,0xF2,0xF4,0x32,0x98,0x00,0xF4,0x24,0x8C,
    0xFF,0xFE,0x17,0xE8,0x02,0xFE,0x16,0xE6,0xFE,0xFE,0x18,0xE4,0x02,0xFE,0x16,0xE2,
    0x00,0xFE,0x18,0xE0,0x01,0xFF,0x18,0xDE,0x01,0xFF,0x19,0xDD,0x02,0xFE,0x1A,0xDC,
    0x00,0xFE,0x1C,0xDA,0x02,0xFE,0x1C,0xD8,0x02,0xFE,0x1E,0xD6,0x02,0xFE,0x20,0xD4,
    0xF4,0xFE,0x22,0xD2,0x00,0xFA,0x16,0xD0,0x14,0xE6,0x16,0xCA,0xF2,0xF4,0x2A,0xB0,
    0x03,0xFD,0x00,0xFF,0x00,0x00,0x03,0xFC,0x04,0xFC,0x03,0xFC,0x00,0x00,0x07,0xF8,
    0x02,0xFE,0x07,0xF8,0x00,0x00,0x09,0xF6,0x00,0x00,0x09,0xF6,0x00,0x00,0x09,0xF6,
    0x02,0xFE,0x09,0xF6,0x00,0x00,0x0B,0xF4,0x00,0x00,0x0B,0xF4,0x00,0x00,0x0B,0xF4,
    0x0E,0xF2,0x0B,0xF4,0xFD,0xFA,0x19,0xE6,0x00,0xFA,0x16,0xE0,0x12,0xE6,0x16,0xDA,
    0x00,0x00,0x09,0xFF,0x00,0x00,0x09,0xFF,0x00,0x00,0x09,0xFF,0x00,0x00,0x09,0xFF,
    0x00,0x00,0x09,0xFF,0x00,0x00,0x09,0xFF,0x00,0x00,0x09,0xFF,0x00,0x00,0x09,0xFF,
    0x00,0x00,0x09,0xFF,0xFE,0x00,0x09,0xFF,0x00,0x00,0x07,0xFF,0x00,0x00,0x07,0xFF,
    0x00,0x00,0x07,0xFF,0x03,0xF7,0x07,0xFF,0x06,0xFA,0x0A,0xF6,0x08,0xF8,0x10,0xF0,
#endif
};

static code UCHAR ucODTable_2ms[] = { // 2ms
#if ENABLE_OD_TRANSFORM == ON
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x16,0x10,0x0E,0x0C,0x0A,0x06,0x06,0x04,0x04,0x04,0x04,0x00,0x00,0x00,0x00,0x00,0x00,
    0x28,0x26,0x20,0x1E,0x16,0x14,0x12,0x12,0x0C,0x0C,0x0A,0x0A,0x08,0x08,0x06,0x06,0x06,
    0x3E,0x3A,0x36,0x30,0x2E,0x26,0x22,0x20,0x1E,0x1C,0x1A,0x16,0x14,0x12,0x0E,0x0A,0x0A,
    0x58,0x4E,0x4A,0x46,0x40,0x3E,0x36,0x32,0x2E,0x2A,0x26,0x24,0x1E,0x1A,0x16,0x14,0x10,
    0x6C,0x64,0x5E,0x5A,0x56,0x50,0x4E,0x42,0x3E,0x3C,0x36,0x32,0x2E,0x26,0x24,0x20,0x1E,
    0x82,0x7E,0x74,0x6E,0x6A,0x66,0x60,0x5E,0x54,0x4C,0x48,0x40,0x34,0x30,0x2C,0x28,0x24,
    0x94,0x92,0x88,0x84,0x7E,0x7A,0x76,0x70,0x6E,0x62,0x5A,0x52,0x4A,0x44,0x3C,0x34,0x30,
    0xA8,0xA4,0x9C,0x9A,0x92,0x90,0x8A,0x88,0x80,0x7E,0x6C,0x64,0x54,0x4C,0x44,0x3E,0x36,
    0xBA,0xB6,0xB2,0xB2,0xA8,0xA4,0xA2,0x9C,0x96,0x90,0x8E,0x7A,0x70,0x64,0x58,0x50,0x4A,
    0xD0,0xD0,0xC6,0xC6,0xBE,0xBE,0xBA,0xB4,0xAE,0xA8,0xA0,0x9E,0x88,0x80,0x70,0x68,0x60,
    0xD8,0xD6,0xD4,0xD4,0xDE,0xCC,0xCA,0xC6,0xC0,0xC0,0xB6,0xB0,0xAE,0x92,0x84,0x78,0x6E,
    0xEA,0xE8,0xE4,0xE4,0xE0,0xE0,0xDC,0xDA,0xDA,0xD8,0xD6,0xD4,0xC0,0xB0,0x94,0x8A,0x74,
    0xFA,0xFA,0xF6,0xF6,0xF4,0xF4,0xF2,0xF0,0xEA,0xEA,0xEA,0xE4,0xDE,0xD0,0xC2,0x9A,0x90,
    0xFF,0xFF,0xFF,0xFC,0xFC,0xFC,0xFC,0xFC,0xFA,0xFA,0xFA,0xFA,0xFA,0xEC,0xE2,0xD2,0xB2,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0xF0,0xD8,
#else
    0xFA,0x00,0x16,0x00,0xFE,0x00,0x10,0x00,0xFE,0x00,0x0E,0x00,0xFE,0x00,0x0C,0x00,
    0xFC,0x00,0x0A,0x00,0x00,0x00,0x06,0x00,0xFE,0x00,0x06,0x00,0x00,0x00,0x04,0x00,
    0x00,0x00,0x04,0x00,0x00,0x00,0x04,0x00,0xFC,0x00,0x04,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x04,0xFA,0x12,0x16,0xFC,0xFE,0x16,0x10,0x00,0xFE,0x12,0x0E,0xFA,0xFE,0x12,0x0C,
    0x02,0xFC,0x0C,0x0A,0xFE,0x00,0x0E,0x06,0x02,0xFE,0x0C,0x06,0xFA,0x00,0x0E,0x04,
    0x00,0x00,0x08,0x04,0xFE,0x00,0x08,0x04,0x04,0xFC,0x06,0x04,0xFE,0x00,0x0A,0x00,
    0x00,0x00,0x08,0x00,0xFE,0x00,0x08,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x06,0x00,
    0xFE,0xFE,0x16,0x28,0x02,0xFA,0x14,0x26,0xFC,0xFE,0x16,0x20,0x06,0xF8,0x12,0x1E,
    0xFA,0xFE,0x18,0x16,0xFE,0xFE,0x12,0x14,0xFE,0x00,0x10,0x12,0x04,0xFA,0x0E,0x12,
    0xFE,0x00,0x12,0x0C,0x00,0xFE,0x10,0x0C,0xFC,0x00,0x10,0x0A,0x00,0xFE,0x0C,0x0A,
    0xFE,0x00,0x0C,0x08,0xFE,0xFE,0x0A,0x08,0xFC,0x00,0x08,0x06,0x00,0x00,0x04,0x06,
    0xFA,0xFC,0x1A,0x3E,0x00,0xFC,0x14,0x3A,0x02,0xFA,0x14,0x36,0xFC,0xFE,0x16,0x30,
    0x06,0xF8,0x12,0x2E,0xFC,0xFC,0x18,0x26,0xFE,0xFE,0x14,0x22,0xFE,0xFE,0x12,0x20,
    0xFE,0xFE,0x10,0x1E,0xFE,0xFE,0x0E,0x1C,0x02,0xFC,0x0C,0x1A,0xFC,0xFE,0x0E,0x16,
    0xFE,0xFE,0x0A,0x14,0x00,0xFC,0x08,0x12,0x02,0xFC,0x08,0x0E,0xFC,0x00,0x0A,0x0A,
    0x02,0xF6,0x14,0x58,0xFE,0xFC,0x16,0x4E,0x00,0xFC,0x14,0x4A,0x02,0xFA,0x14,0x46,
    0xFC,0xFE,0x16,0x40,0x06,0xF8,0x12,0x3E,0xF8,0xFC,0x18,0x36,0x00,0xFC,0x10,0x32,
    0x02,0xFC,0x10,0x2E,0xFE,0xFC,0x12,0x2A,0xFE,0xFE,0x10,0x26,0x02,0xFA,0x0E,0x24,
    0xFC,0xFC,0x10,0x1E,0x02,0xFC,0x0C,0x1A,0xFE,0xFE,0x0E,0x16,0x02,0xFC,0x0C,0x14,
    0x04,0xF8,0x16,0x6C,0xFC,0xFA,0x1A,0x64,0xFE,0xFC,0x16,0x5E,0x00,0xFC,0x14,0x5A,
    0x02,0xFA,0x14,0x56,0xFC,0xFE,0x16,0x50,0x0A,0xF4,0x12,0x4E,0xFA,0xFC,0x1C,0x42,
    0xFA,0xFE,0x16,0x3E,0x02,0xFA,0x10,0x3C,0xFC,0xFC,0x12,0x36,0xF8,0xFC,0x0E,0x32,
    0x04,0xF8,0x06,0x2E,0xFE,0xFE,0x0A,0x26,0x00,0xFC,0x08,0x24,0xFE,0xFE,0x08,0x20,
    0x02,0xFC,0x12,0x82,0x00,0xF6,0x14,0x7E,0x02,0xFA,0x14,0x74,0xFE,0xFC,0x16,0x6E,
    0x00,0xFC,0x14,0x6A,0x02,0xFA,0x14,0x66,0xFC,0xFE,0x16,0x60,0x08,0xF6,0x12,0x5E,
    0xFC,0xF8,0x1A,0x54,0xFC,0xFC,0x16,0x4C,0x00,0xF8,0x12,0x48,0x04,0xF4,0x12,0x40,
    0xFE,0xFC,0x16,0x34,0xFC,0xFC,0x14,0x30,0xFC,0xFC,0x10,0x2C,0x00,0xFC,0x0C,0x28,
    0xFE,0xFE,0x14,0x94,0x02,0xF6,0x12,0x92,0x02,0xFC,0x14,0x88,0xFE,0xFA,0x16,0x84,
    0x02,0xFC,0x14,0x7E,0xFE,0xFC,0x16,0x7A,0x04,0xFA,0x14,0x76,0xFA,0xFE,0x18,0x70,
    0x0A,0xF4,0x12,0x6E,0xF6,0xF8,0x1C,0x62,0x00,0xF8,0x12,0x5A,0xF8,0xF8,0x12,0x52,
    0xFE,0xFA,0x0A,0x4A,0x00,0xF8,0x08,0x44,0x02,0xF8,0x08,0x3C,0xFC,0xFC,0x0A,0x34,
    0x00,0xFC,0x12,0xA8,0x04,0xF8,0x12,0xA4,0x02,0xFE,0x16,0x9C,0xFE,0xF8,0x18,0x9A,
    0xFE,0xFE,0x16,0x92,0x04,0xFA,0x14,0x90,0xFC,0xFE,0x18,0x8A,0x02,0xF8,0x14,0x88,
    0xFC,0xFE,0x16,0x80,0x10,0xEE,0x12,0x7E,0xF4,0xF8,0x22,0x6C,0x06,0xF0,0x16,0x64,
    0xFC,0xF8,0x1C,0x54,0xFC,0xF8,0x18,0x4C,0xFE,0xFA,0x14,0x44,0x02,0xF8,0x12,0x3E,
    0x04,0xFC,0x16,0xBA,0xFA,0xFC,0x1A,0xB6,0x00,0x00,0x14,0xB2,0x02,0xF6,0x14,0xB2,
    0x04,0xFC,0x16,0xA8,0xFE,0xFE,0x1A,0xA4,0x00,0xFA,0x18,0xA2,0x00,0xFA,0x18,0x9C,
    0x00,0xFA,0x18,0x96,0xFA,0xFE,0x18,0x90,0x12,0xEC,0x12,0x8E,0xF4,0xF6,0x24,0x7A,
    0x04,0xF4,0x18,0x70,0xFC,0xF4,0x1C,0x64,0x00,0xF8,0x18,0x58,0xFE,0xFA,0x18,0x50,
    0xFE,0x00,0x08,0xD0,0x08,0xF6,0x06,0xD0,0x00,0x00,0x0E,0xC6,0x12,0xF8,0x0E,0xC6,
    0xEE,0x00,0x20,0xBE,0x02,0xFC,0x0E,0xBE,0x02,0xFA,0x10,0xBA,0x00,0xFA,0x12,0xB4,
    0x06,0xFA,0x12,0xAE,0xFE,0xF8,0x18,0xA8,0xFC,0xFE,0x16,0xA0,0x14,0xEA,0x12,0x9E,
    0xEC,0xF8,0x26,0x88,0x02,0xF0,0x12,0x80,0xFC,0xF8,0x14,0x70,0xFE,0xF8,0x10,0x68,
    0x00,0xFE,0x12,0xD8,0xFE,0xFE,0x12,0xD6,0x00,0x00,0x10,0xD4,0xF2,0x0A,0x10,0xD4,
    0x12,0xEE,0x02,0xDE,0xFE,0xFE,0x14,0xCC,0x02,0xFC,0x12,0xCA,0x06,0xFA,0x14,0xC6,
    0xFE,0x00,0x1A,0xC0,0x08,0xF6,0x18,0xC0,0x04,0xFA,0x20,0xB6,0xEE,0xFE,0x24,0xB0,
    0x0C,0xE4,0x12,0xAE,0xF2,0xF2,0x1E,0x92,0x02,0xF4,0x10,0x84,0xF4,0xF6,0x12,0x78,
    0x02,0xFE,0x10,0xEA,0x00,0xFC,0x12,0xE8,0x00,0x00,0x12,0xE4,0x02,0xFC,0x12,0xE4,
    0x00,0x00,0x14,0xE0,0x02,0xFC,0x14,0xE0,0x00,0xFE,0x16,0xDC,0xFA,0x00,0x16,0xDA,
    0x02,0xFE,0x10,0xDA,0x02,0xFE,0x12,0xD8,0xFC,0xFE,0x14,0xD6,0x0E,0xEC,0x10,0xD4,
    0x02,0xF0,0x1E,0xC0,0x0E,0xE4,0x20,0xB0,0xE2,0xF6,0x2E,0x94,0x0C,0xEA,0x10,0x8A,
    0x00,0x00,0x05,0xFA,0x04,0xFC,0x05,0xFA,0xFD,0x00,0x09,0xF6,0x02,0xFE,0x06,0xF6,
    0x00,0x00,0x08,0xF4,0x02,0xFE,0x08,0xF4,0x02,0xFE,0x0A,0xF2,0x04,0xFA,0x0C,0xF0,
    0x00,0x00,0x10,0xEA,0x00,0x00,0x10,0xEA,0x06,0xFA,0x10,0xEA,0x06,0xFA,0x16,0xE4,
    0x00,0xF2,0x1C,0xDE,0x04,0xF2,0x1C,0xD0,0x18,0xD8,0x20,0xC2,0xEA,0xF6,0x38,0x9A,
    0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x03,0xFD,0x00,0xFF,0x00,0x00,0x03,0xFC,
    0x00,0x00,0x03,0xFC,0x00,0x00,0x03,0xFC,0x00,0x00,0x03,0xFC,0x02,0xFE,0x03,0xFC,
    0x00,0x00,0x05,0xFA,0x00,0x00,0x05,0xFA,0x00,0x00,0x05,0xFA,0x00,0x00,0x05,0xFA,
    0x0E,0xF2,0x05,0xFA,0x07,0xF6,0x13,0xEC,0x04,0xF0,0x1A,0xE2,0x08,0xE0,0x1E,0xD2,
    0x00,0x00,0x09,0xFF,0x00,0x00,0x09,0xFF,0x00,0x00,0x09,0xFF,0x00,0x00,0x09,0xFF,
    0x00,0x00,0x09,0xFF,0x00,0x00,0x09,0xFF,0x00,0x00,0x09,0xFF,0x00,0x00,0x09,0xFF,
    0x00,0x00,0x09,0xFF,0xFE,0x00,0x09,0xFF,0x00,0x00,0x07,0xFF,0x00,0x00,0x07,0xFF,
    0x00,0x00,0x07,0xFF,0x01,0xFD,0x07,0xFF,0x0C,0xF4,0x08,0xFC,0xAA,0xE8,0x14,0xF0,
#endif
};

static code UCHAR* ODTable[] = {
    ucODTable_4ms, ucODTable_3ms, ucODTable_2ms
};

#endif //#if ENABLE_OD == ON
