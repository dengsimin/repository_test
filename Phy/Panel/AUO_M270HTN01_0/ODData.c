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
static code UCHAR ucODTable_4ms[] = {    //  7.54ms   20150504
#if ENABLE_OD_TRANSFORM == ON
/*
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x11,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
    0x26,0x25,0x20,0x20,0x20,0x20,0x20,0x1B,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,
    0x3A,0x39,0x37,0x30,0x30,0x30,0x30,0x30,0x2B,0x28,0x28,0x28,0x28,0x28,0x28,0x28,0x28,
    0x51,0x4E,0x49,0x47,0x40,0x40,0x40,0x40,0x3B,0x39,0x39,0x39,0x37,0x37,0x37,0x37,0x37,
    0x64,0x63,0x5F,0x5A,0x57,0x50,0x50,0x50,0x4F,0x4B,0x49,0x49,0x49,0x49,0x49,0x37,0x37,
    0x7C,0x78,0x6F,0x6B,0x69,0x67,0x60,0x60,0x60,0x5F,0x5C,0x58,0x56,0x49,0x49,0x40,0x37,
    0x8C,0x89,0x86,0x80,0x7B,0x79,0x77,0x70,0x70,0x70,0x6E,0x6A,0x68,0x56,0x56,0x54,0x40,
    0xA8,0xA1,0x9B,0x95,0x93,0x8E,0x8A,0x87,0x80,0x80,0x80,0x7C,0x7A,0x66,0x66,0x5C,0x50,
    0xB7,0xB6,0xB1,0xAA,0xA8,0xA4,0xA1,0x9B,0x97,0x90,0x90,0x90,0x8C,0x79,0x76,0x6F,0x5C,
    0xCB,0xC8,0xC1,0xBF,0xBB,0xB6,0xB4,0xAE,0xAD,0xA7,0xA0,0xA0,0x9E,0x90,0x89,0x7F,0x70,
    0xDA,0xD9,0xD5,0xD1,0xCD,0xCB,0xC9,0xC1,0xBE,0xBB,0xB7,0xB0,0xB0,0xA8,0xA0,0x8F,0x80,
    0xE7,0xE6,0xE5,0xE1,0xDF,0xDD,0xDB,0xD9,0xD3,0xCF,0xCE,0xCA,0xC0,0xC0,0xB8,0xAA,0x97,
    0xF3,0xF3,0xF2,0xF1,0xEE,0xED,0xEB,0xE6,0xE5,0xE3,0xE1,0xDE,0xDA,0xD0,0xD0,0xC2,0xB3,
    0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF7,0xF6,0xF5,0xF4,0xF3,0xF0,0xED,0xEA,0xE0,0xDA,0xD2,
    0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFB,0xFA,0xF0,0xF0,
*/
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x16,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x35,0x33,0x20,0x09,0x09,0x06,0x06,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x4D,0x49,0x47,0x30,0x1B,0x17,0x17,0x17,0x0F,0x0C,0x09,0x05,0x03,0x00,0x00,0x00,0x00,
    0x64,0x5E,0x59,0x56,0x40,0x29,0x27,0x27,0x1F,0x1D,0x1B,0x17,0x15,0x09,0x09,0x09,0x07,
    0x79,0x73,0x6F,0x6A,0x66,0x50,0x39,0x39,0x33,0x2F,0x2D,0x29,0x27,0x19,0x19,0x19,0x0F,
    0x91,0x88,0x7F,0x7B,0x79,0x76,0x60,0x48,0x46,0x42,0x3F,0x3B,0x39,0x2C,0x2C,0x23,0x17,
    0xA1,0x99,0x96,0x90,0x8B,0x89,0x87,0x70,0x58,0x54,0x51,0x4D,0x4B,0x39,0x39,0x37,0x23,
    0xBD,0xB1,0xAB,0xA5,0xA3,0x9E,0x9A,0x97,0x80,0x68,0x64,0x5F,0x5D,0x49,0x49,0x3F,0x33,
    0xCB,0xC6,0xC1,0xBA,0xB8,0xB4,0xB1,0xAB,0xA7,0x90,0x78,0x74,0x6F,0x5C,0x59,0x52,0x3F,
    0xDF,0xD8,0xD1,0xCF,0xCB,0xC6,0xC4,0xBE,0xBD,0xB7,0xA0,0x89,0x81,0x73,0x6C,0x62,0x53,
    0xEB,0xE9,0xE5,0xE1,0xDD,0xDB,0xD9,0xD1,0xCE,0xCB,0xC7,0xB0,0x96,0x8B,0x83,0x72,0x63,
    0xFB,0xF9,0xF5,0xF1,0xEF,0xED,0xEB,0xE9,0xE3,0xDF,0xDE,0xDA,0xC0,0xA3,0x9B,0x8D,0x7A,
    0xFF,0xFF,0xFF,0xFF,0xFE,0xFD,0xFB,0xF5,0xF5,0xF3,0xF1,0xEE,0xEA,0xD0,0xB4,0xA5,0x96,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFD,0xFA,0xE0,0xBD,0xB5,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,0xD6,

#else
/*
            0xFF,0x00,0x11,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,0x00,
            0x00,0x00,0x10,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,0x00,
            0x00,0x00,0x10,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,0x00,
            0x00,0x00,0x10,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,0x00,
            0x00,0xFF,0x15,0x11,0xFB,0x00,0x15,0x10,0x00,0x00,0x10,0x10,0x00,0x00,0x10,0x10,
            0x00,0x00,0x10,0x10,0x00,0x00,0x10,0x10,0xFB,0x00,0x10,0x10,0xFB,0x00,0x0B,0x10,
            0x00,0x00,0x06,0x10,0x00,0x00,0x06,0x10,0x00,0x00,0x06,0x10,0x00,0x00,0x06,0x10,
            0x00,0x00,0x06,0x10,0x00,0x00,0x06,0x10,0x00,0x00,0x06,0x10,0x00,0x00,0x06,0x10,
            0x00,0xFF,0x14,0x26,0x03,0xFB,0x14,0x25,0xF9,0x00,0x17,0x20,0x00,0x00,0x10,0x20,
            0x00,0x00,0x10,0x20,0x00,0x00,0x10,0x20,0x05,0xFB,0x10,0x20,0x00,0xFB,0x15,0x1B,
            0xFD,0x00,0x15,0x16,0x00,0x00,0x12,0x16,0x00,0x00,0x12,0x16,0x00,0x00,0x12,0x16,
            0x00,0x00,0x12,0x16,0x00,0x00,0x12,0x16,0x00,0x00,0x12,0x16,0x00,0x00,0x12,0x16,
            0xFE,0xFF,0x17,0x3A,0xFD,0xFE,0x15,0x39,0x05,0xF9,0x12,0x37,0xF9,0x00,0x17,0x30,
            0x00,0x00,0x10,0x30,0x00,0x00,0x10,0x30,0x00,0x00,0x10,0x30,0x00,0xFB,0x10,0x30,
            0x01,0xFD,0x10,0x2B,0x00,0x00,0x11,0x28,0x00,0x00,0x11,0x28,0xFE,0x00,0x11,0x28,
            0x00,0x00,0x0F,0x28,0x00,0x00,0x0F,0x28,0x00,0x00,0x0F,0x28,0x00,0x00,0x0F,0x28,
            0x02,0xFD,0x13,0x51,0x01,0xFB,0x15,0x4E,0xFD,0xFE,0x16,0x49,0x04,0xF9,0x13,0x47,
            0xF9,0x00,0x17,0x40,0x00,0x00,0x10,0x40,0x00,0x00,0x10,0x40,0x04,0xFB,0x10,0x40,
            0xFE,0xFE,0x14,0x3B,0xFE,0x00,0x12,0x39,0x00,0x00,0x10,0x39,0x02,0xFE,0x10,0x39,
            0x00,0x00,0x12,0x37,0x00,0x00,0x12,0x37,0xEE,0x00,0x12,0x37,0x00,0x00,0x00,0x37,
            0xFD,0xFF,0x18,0x64,0xFB,0xFC,0x15,0x63,0x01,0xFB,0x10,0x5F,0x01,0xFD,0x11,0x5A,
            0x05,0xF9,0x12,0x57,0xF9,0x00,0x17,0x50,0x00,0x00,0x10,0x50,0x01,0xFF,0x10,0x50,
            0x03,0xFC,0x11,0x4F,0xFF,0xFE,0x14,0x4B,0xFC,0x00,0x13,0x49,0xFE,0x00,0x0F,0x49,
            0xF3,0x00,0x0D,0x49,0x00,0x00,0x00,0x49,0x09,0xEE,0x00,0x49,0xF7,0x00,0x09,0x37,
            0x01,0xFC,0x10,0x7C,0x06,0xF7,0x11,0x78,0xFE,0xFC,0x17,0x6F,0xFD,0xFE,0x15,0x6B,
            0x00,0xFE,0x12,0x69,0x05,0xF9,0x12,0x67,0xF9,0x00,0x17,0x60,0x00,0x00,0x10,0x60,
            0x01,0xFF,0x10,0x60,0x01,0xFD,0x11,0x5F,0x00,0xFC,0x12,0x5C,0x00,0xFE,0x12,0x58,
            0xFB,0xF3,0x12,0x56,0x00,0x00,0x0D,0x49,0x07,0xF7,0x0D,0x49,0xF5,0xF7,0x14,0x40,
            0xFC,0xFD,0x1C,0x8C,0xFD,0xFD,0x18,0x89,0x00,0xFA,0x15,0x86,0x03,0xFB,0x15,0x80,
            0xFD,0xFE,0x18,0x7B,0xFE,0xFE,0x15,0x79,0x04,0xF9,0x13,0x77,0xF9,0x00,0x17,0x70,
            0x00,0x00,0x10,0x70,0x02,0xFE,0x10,0x70,0x00,0xFC,0x12,0x6E,0x00,0xFE,0x12,0x6A,
            0xFE,0xEE,0x12,0x68,0x00,0x00,0x10,0x56,0xF8,0xFE,0x10,0x56,0x08,0xEC,0x08,0x54,
            0x06,0xF9,0x0F,0xA8,0x01,0xFA,0x15,0xA1,0xFF,0xFA,0x16,0x9B,0x00,0xFE,0x15,0x95,
            0x01,0xFB,0x15,0x93,0x01,0xFC,0x16,0x8E,0xFD,0xFD,0x17,0x8A,0x03,0xF9,0x14,0x87,
            0xF9,0x00,0x17,0x80,0x00,0x00,0x10,0x80,0x04,0xFC,0x10,0x80,0xFE,0xFE,0x14,0x7C,
            0x01,0xEC,0x12,0x7A,0xFD,0x00,0x13,0x66,0x03,0xF6,0x10,0x66,0xF9,0xF4,0x13,0x5C,
            0xFE,0xFF,0x14,0xB7,0xFE,0xFB,0x12,0xB6,0x05,0xF9,0x10,0xB1,0xFE,0xFE,0x15,0xAA,
            0xFF,0xFC,0x13,0xA8,0x01,0xFD,0x12,0xA4,0x00,0xFA,0x13,0xA1,0x03,0xFC,0x13,0x9B,
            0x01,0xF9,0x16,0x97,0xF9,0x00,0x17,0x90,0x00,0x00,0x10,0x90,0x02,0xFC,0x10,0x90,
            0x05,0xED,0x12,0x8C,0xFC,0xFD,0x17,0x79,0xFD,0xF9,0x13,0x76,0x04,0xED,0x10,0x6F,
            0x02,0xFD,0x0F,0xCB,0x03,0xF9,0x11,0xC8,0xFE,0xFE,0x14,0xC1,0x00,0xFC,0x12,0xBF,
            0x03,0xFB,0x12,0xBB,0x00,0xFE,0x15,0xB6,0xFE,0xFA,0x15,0xB4,0xFE,0xFF,0x13,0xAE,
            0x03,0xFA,0x11,0xAD,0x03,0xF9,0x14,0xA7,0xF9,0x00,0x17,0xA0,0x02,0xFE,0x10,0xA0,
            0x06,0xF2,0x12,0x9E,0xFF,0xF9,0x18,0x90,0xF9,0xF6,0x17,0x89,0x00,0xF1,0x10,0x7F,
            0x00,0xFF,0x0D,0xDA,0x03,0xFC,0x0D,0xD9,0x00,0xFC,0x10,0xD5,0x02,0xFC,0x10,0xD1,
            0x00,0xFE,0x12,0xCD,0x00,0xFE,0x12,0xCB,0x06,0xF8,0x12,0xC9,0xFD,0xFD,0x18,0xC1,
            0xFF,0xFD,0x15,0xBE,0x03,0xFC,0x14,0xBB,0x03,0xF9,0x17,0xB7,0xF6,0x00,0x1A,0xB0,
            0x08,0xF8,0x10,0xB0,0x00,0xF8,0x18,0xA8,0x03,0xEF,0x18,0xA0,0xFC,0xF1,0x1B,0x8F,
            0x01,0xFF,0x0C,0xE7,0x00,0xFF,0x0D,0xE6,0x03,0xFC,0x0D,0xE5,0xFF,0xFE,0x10,0xE1,
            0x01,0xFE,0x0F,0xDF,0x00,0xFE,0x10,0xDD,0xFD,0xFE,0x10,0xDB,0x05,0xFA,0x0D,0xD9,
            0x02,0xFC,0x12,0xD3,0xFF,0xFF,0x14,0xCF,0x01,0xFC,0x13,0xCE,0x06,0xF6,0x14,0xCA,
            0xF6,0x00,0x1A,0xC0,0x08,0xF8,0x10,0xC0,0x00,0xF2,0x18,0xB8,0x04,0xED,0x18,0xAA,
            0x00,0x00,0x05,0xF3,0x01,0xFF,0x05,0xF3,0x01,0xFF,0x06,0xF2,0x03,0xFD,0x07,0xF1,
            0x01,0xFF,0x0A,0xEE,0x01,0xFE,0x0B,0xED,0x04,0xFB,0x0C,0xEB,0x00,0xFF,0x10,0xE6,
            0x01,0xFE,0x10,0xE5,0x01,0xFE,0x11,0xE3,0x00,0xFD,0x12,0xE1,0x01,0xFC,0x12,0xDE,
            0x07,0xF6,0x13,0xDA,0xF6,0x00,0x1A,0xD0,0x08,0xF2,0x10,0xD0,0x07,0xF1,0x18,0xC2,
            0x00,0x00,0x04,0xF8,0x00,0x00,0x04,0xF8,0x00,0x00,0x04,0xF8,0x00,0x00,0x04,0xF8,
            0x00,0x00,0x04,0xF8,0x01,0xFF,0x04,0xF8,0x01,0xFF,0x05,0xF7,0x01,0xFF,0x06,0xF6,
            0x01,0xFF,0x07,0xF5,0x01,0xFF,0x08,0xF4,0x03,0xFD,0x09,0xF3,0x03,0xFD,0x0C,0xF0,
            0x02,0xFD,0x0F,0xED,0x09,0xF6,0x11,0xEA,0xFC,0xFA,0x1A,0xE0,0x08,0xF8,0x16,0xDA,
            0x00,0x00,0x04,0xFC,0x00,0x00,0x04,0xFC,0x00,0x00,0x04,0xFC,0x00,0x00,0x04,0xFC,
            0x00,0x00,0x04,0xFC,0x00,0x00,0x04,0xFC,0x00,0x00,0x04,0xFC,0x00,0x00,0x04,0xFC,
            0x00,0x00,0x04,0xFC,0x00,0x00,0x04,0xFC,0x00,0x00,0x04,0xFC,0x00,0x00,0x04,0xFC,
            0x01,0xFF,0x04,0xFC,0x01,0xFF,0x05,0xFB,0x0A,0xF6,0x06,0xFA,0x00,0x00,0x10,0xF0,
            */
    0xFA,0x00,0x16,0x00,0xF0,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x04,0xFA,0x1F,0x16,0xFD,0xF0,0x23,0x10,0xE9,0x00,0x20,0x00,0x00,0x00,0x09,0x00,
    0xFD,0x00,0x09,0x00,0x00,0x00,0x06,0x00,0xFE,0x00,0x06,0x00,0xFC,0x00,0x04,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0xFE,0xFE,0x18,0x35,0x11,0xED,0x16,0x33,0x00,0xE9,0x27,0x20,0xEB,0x00,0x27,0x09,
    0xFF,0xFD,0x12,0x09,0x00,0x00,0x11,0x06,0x02,0xFE,0x11,0x06,0xFC,0xFC,0x13,0x04,
    0xFD,0x00,0x0F,0x00,0xFD,0x00,0x0C,0x00,0xFC,0x00,0x09,0x00,0xFE,0x00,0x05,0x00,
    0xFD,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0xFE,0xFC,0x17,0x4D,0xFD,0xFE,0x15,0x49,0x14,0xE9,0x12,0x47,0xFF,0xEB,0x26,0x30,
    0xED,0xFC,0x25,0x1B,0xFE,0x00,0x12,0x17,0x00,0x00,0x10,0x17,0x00,0xF8,0x10,0x17,
    0x01,0xFD,0x10,0x0F,0x01,0xFD,0x11,0x0C,0x00,0xFC,0x12,0x09,0x00,0xFE,0x12,0x05,
    0xF7,0xFD,0x12,0x03,0x00,0x00,0x09,0x00,0x00,0x00,0x09,0x00,0xFE,0x00,0x09,0x00,
    0x00,0xFA,0x15,0x64,0x01,0xFB,0x15,0x5E,0xFE,0xFD,0x16,0x59,0x12,0xEA,0x14,0x56,
    0x01,0xE9,0x26,0x40,0xEB,0xFE,0x27,0x29,0x00,0x00,0x12,0x27,0x02,0xF8,0x12,0x27,
    0xFE,0xFE,0x14,0x1F,0x00,0xFE,0x12,0x1D,0x00,0xFC,0x12,0x1B,0x00,0xFE,0x12,0x17,
    0xFE,0xF4,0x12,0x15,0x00,0x00,0x10,0x09,0x00,0x00,0x10,0x09,0xF8,0xFE,0x10,0x09,
    0xFD,0xFA,0x18,0x79,0xFB,0xFC,0x15,0x73,0x01,0xFB,0x10,0x6F,0x02,0xFC,0x11,0x6A,
    0x13,0xEA,0x13,0x66,0x01,0xE9,0x26,0x50,0xE8,0x00,0x27,0x39,0x04,0xFA,0x0F,0x39,
    0x00,0xFC,0x13,0x33,0xFF,0xFE,0x13,0x2F,0x00,0xFC,0x12,0x2D,0x00,0xFE,0x12,0x29,
    0x01,0xF2,0x12,0x27,0x00,0x00,0x13,0x19,0xF7,0x00,0x13,0x19,0xFE,0xF6,0x0A,0x19,
    0x01,0xF7,0x10,0x91,0x06,0xF7,0x11,0x88,0xFE,0xFC,0x17,0x7F,0xFD,0xFE,0x15,0x7B,
    0x01,0xFD,0x12,0x79,0x14,0xEA,0x13,0x76,0x01,0xE8,0x27,0x60,0xEA,0xFE,0x28,0x48,
    0x00,0xFC,0x12,0x46,0x00,0xFD,0x12,0x42,0x00,0xFC,0x12,0x3F,0x00,0xFE,0x12,0x3B,
    0xFB,0xF3,0x12,0x39,0x00,0x00,0x0D,0x2C,0x07,0xF7,0x0D,0x2C,0xF8,0xF4,0x14,0x23,
    0xFC,0xF8,0x1C,0xA1,0xFD,0xFD,0x18,0x99,0x00,0xFA,0x15,0x96,0x03,0xFB,0x15,0x90,
    0xFD,0xFE,0x18,0x8B,0xFE,0xFE,0x15,0x89,0x14,0xE9,0x13,0x87,0x01,0xE8,0x27,0x70,
    0xEC,0xFC,0x28,0x58,0xFF,0xFD,0x14,0x54,0xFF,0xFC,0x13,0x51,0x00,0xFE,0x12,0x4D,
    0xFE,0xEE,0x12,0x4B,0x00,0x00,0x10,0x39,0xF8,0xFE,0x10,0x39,0x08,0xEC,0x08,0x37,
    0x07,0xF4,0x0E,0xBD,0x01,0xFA,0x15,0xB1,0xFF,0xFA,0x16,0xAB,0x00,0xFE,0x15,0xA5,
    0x01,0xFB,0x15,0xA3,0x01,0xFC,0x16,0x9E,0xFD,0xFD,0x17,0x9A,0x13,0xE9,0x14,0x97,
    0x01,0xE8,0x27,0x80,0xEC,0xFC,0x28,0x68,0x01,0xFB,0x14,0x64,0xFD,0xFE,0x15,0x5F,
    0x01,0xEC,0x12,0x5D,0xFD,0x00,0x13,0x49,0x03,0xF6,0x10,0x49,0xF9,0xF4,0x13,0x3F,
    0xFE,0xFB,0x14,0xCB,0xFE,0xFB,0x12,0xC6,0x05,0xF9,0x10,0xC1,0xFE,0xFE,0x15,0xBA,
    0xFF,0xFC,0x13,0xB8,0x01,0xFD,0x12,0xB4,0x00,0xFA,0x13,0xB1,0x03,0xFC,0x13,0xAB,
    0x11,0xE9,0x16,0xA7,0x01,0xE8,0x27,0x90,0xED,0xFC,0x28,0x78,0xFD,0xFB,0x15,0x74,
    0x05,0xED,0x12,0x6F,0xFC,0xFD,0x17,0x5C,0xFD,0xF9,0x13,0x59,0x04,0xED,0x10,0x52,
    0x05,0xF9,0x0C,0xDF,0x03,0xF9,0x11,0xD8,0xFE,0xFE,0x14,0xD1,0x00,0xFC,0x12,0xCF,
    0x03,0xFB,0x12,0xCB,0x00,0xFE,0x15,0xC6,0xFE,0xFA,0x15,0xC4,0xFE,0xFF,0x13,0xBE,
    0x03,0xFA,0x11,0xBD,0x13,0xE9,0x14,0xB7,0x00,0xE9,0x27,0xA0,0xEE,0xF8,0x27,0x89,
    0x03,0xF2,0x15,0x81,0xFF,0xF9,0x18,0x73,0xF9,0xF6,0x17,0x6C,0x00,0xF1,0x10,0x62,
    0x00,0xFE,0x10,0xEB,0x00,0xFC,0x10,0xE9,0x00,0xFC,0x10,0xE5,0x02,0xFC,0x10,0xE1,
    0x00,0xFE,0x12,0xDD,0x00,0xFE,0x12,0xDB,0x06,0xF8,0x12,0xD9,0xFD,0xFD,0x18,0xD1,
    0xFF,0xFD,0x15,0xCE,0x03,0xFC,0x14,0xCB,0x13,0xE9,0x17,0xC7,0x00,0xE6,0x2A,0xB0,
    0xEE,0xF5,0x2A,0x96,0x00,0xF8,0x18,0x8B,0x03,0xEF,0x18,0x83,0xFC,0xF1,0x1B,0x72,
    0x02,0xFE,0x04,0xFB,0x04,0xFC,0x06,0xF9,0x04,0xFC,0x0A,0xF5,0x01,0xFE,0x0E,0xF1,
    0x01,0xFE,0x0F,0xEF,0x00,0xFE,0x10,0xED,0xFC,0xFE,0x10,0xEB,0x06,0xFA,0x0C,0xE9,
    0x02,0xFC,0x12,0xE3,0xFF,0xFF,0x14,0xDF,0x01,0xFC,0x13,0xDE,0x16,0xE6,0x14,0xDA,
    0x03,0xE3,0x2A,0xC0,0xEC,0xF8,0x2D,0xA3,0xFF,0xF2,0x19,0x9B,0x04,0xED,0x18,0x8D,
    0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x01,0xFF,0x00,0xFF,
    0x01,0xFF,0x01,0xFE,0x02,0xFE,0x02,0xFD,0x06,0xFA,0x04,0xFB,0x00,0x00,0x0A,0xF5,
    0x02,0xFE,0x0A,0xF5,0x02,0xFE,0x0C,0xF3,0x03,0xFD,0x0E,0xF1,0x02,0xFC,0x11,0xEE,
    0x17,0xE6,0x13,0xEA,0x02,0xE4,0x2A,0xD0,0xEC,0xF1,0x2C,0xB4,0x07,0xF1,0x18,0xA5,
    0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,
    0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,
    0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x02,0xFE,0x00,0xFF,
    0x03,0xFD,0x02,0xFD,0x1A,0xE6,0x05,0xFA,0x14,0xDD,0x1F,0xE0,0xEE,0xF8,0x33,0xBD,
    0x00,0x00,0x01,0xFF,0x00,0x00,0x01,0xFF,0x00,0x00,0x01,0xFF,0x00,0x00,0x01,0xFF,
    0x00,0x00,0x01,0xFF,0x00,0x00,0x01,0xFF,0x00,0x00,0x01,0xFF,0x00,0x00,0x01,0xFF,
    0x00,0x00,0x01,0xFF,0x00,0x00,0x01,0xFF,0x00,0x00,0x01,0xFF,0x00,0x00,0x01,0xFF,
    0x00,0x00,0x01,0xFF,0x00,0x00,0x01,0xFF,0x0F,0xF1,0x01,0xFF,0x1A,0xE6,0x10,0xF0,
#endif


};

static code UCHAR ucODTable_3ms[] = {    //  6.59ms   20150504
#if ENABLE_OD_TRANSFORM == ON
            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
            0x13,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
            0x28,0x27,0x20,0x20,0x20,0x1E,0x1E,0x19,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,
            0x3C,0x3B,0x39,0x30,0x30,0x30,0x30,0x30,0x29,0x26,0x26,0x26,0x26,0x26,0x26,0x26,0x26,
            0x53,0x50,0x4B,0x49,0x40,0x40,0x40,0x40,0x39,0x37,0x37,0x37,0x35,0x35,0x35,0x35,0x35,
            0x66,0x65,0x61,0x5C,0x59,0x50,0x50,0x50,0x4D,0x49,0x47,0x47,0x47,0x47,0x47,0x35,0x35,
            0x7E,0x7A,0x71,0x6D,0x6B,0x69,0x60,0x60,0x60,0x5D,0x5A,0x56,0x54,0x47,0x47,0x3E,0x35,
            0x8E,0x8B,0x88,0x82,0x7D,0x7B,0x79,0x70,0x70,0x6F,0x6C,0x68,0x66,0x54,0x54,0x52,0x3E,
            0xAA,0xA3,0x9D,0x97,0x95,0x90,0x8C,0x89,0x80,0x80,0x7F,0x7A,0x78,0x64,0x64,0x5A,0x4E,
            0xB9,0xB8,0xB3,0xAC,0xAA,0xA6,0xA3,0x9D,0x99,0x90,0x90,0x8F,0x8A,0x77,0x74,0x6D,0x5A,
            0xCD,0xCA,0xC3,0xC1,0xBD,0xB8,0xB6,0xB0,0xAF,0xA9,0xA0,0xA0,0x9C,0x8E,0x87,0x7D,0x6E,
            0xDC,0xDB,0xD7,0xD3,0xCF,0xCD,0xCB,0xC3,0xC0,0xBD,0xB9,0xB0,0xB0,0xA6,0x9E,0x8D,0x7E,
            0xE7,0xE7,0xE7,0xE3,0xE1,0xDF,0xDD,0xDB,0xD5,0xD1,0xD0,0xCC,0xC0,0xBE,0xB6,0xA8,0x95,
            0xF3,0xF3,0xF3,0xF3,0xF0,0xEF,0xED,0xE8,0xE7,0xE5,0xE3,0xE0,0xDC,0xD0,0xCF,0xC0,0xB1,
            0xFA,0xFA,0xFA,0xFA,0xFA,0xFA,0xF8,0xF8,0xF7,0xF6,0xF5,0xF2,0xEF,0xEC,0xE0,0xD8,0xD0,
            0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFC,0xF0,0xF0,
#else
            0xFD,0x00,0x13,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,0x00,
            0x00,0x00,0x10,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,0x00,
            0x00,0x00,0x10,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,0x00,
            0x00,0x00,0x10,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,0x00,
            0x02,0xFD,0x15,0x13,0xF9,0x00,0x17,0x10,0x00,0x00,0x10,0x10,0x00,0x00,0x10,0x10,
            0xFE,0x00,0x10,0x10,0x00,0x00,0x0E,0x10,0xFB,0x00,0x0E,0x10,0xFB,0x00,0x09,0x10,
            0x00,0x00,0x04,0x10,0x00,0x00,0x04,0x10,0x00,0x00,0x04,0x10,0x00,0x00,0x04,0x10,
            0x00,0x00,0x04,0x10,0x00,0x00,0x04,0x10,0x00,0x00,0x04,0x10,0x00,0x00,0x04,0x10,
            0x00,0xFF,0x14,0x28,0x05,0xF9,0x14,0x27,0xF7,0x00,0x19,0x20,0x00,0x00,0x10,0x20,
            0x02,0xFE,0x10,0x20,0x00,0x00,0x12,0x1E,0x05,0xFB,0x12,0x1E,0xFE,0xFB,0x17,0x19,
            0xFD,0x00,0x15,0x14,0x00,0x00,0x12,0x14,0x00,0x00,0x12,0x14,0x00,0x00,0x12,0x14,
            0x00,0x00,0x12,0x14,0x00,0x00,0x12,0x14,0x00,0x00,0x12,0x14,0x00,0x00,0x12,0x14,
            0xFE,0xFF,0x17,0x3C,0xFD,0xFE,0x15,0x3B,0x07,0xF7,0x12,0x39,0xF7,0x00,0x19,0x30,
            0x00,0x00,0x10,0x30,0x00,0x00,0x10,0x30,0x00,0x00,0x10,0x30,0x00,0xF9,0x10,0x30,
            0x01,0xFD,0x10,0x29,0x00,0x00,0x11,0x26,0x00,0x00,0x11,0x26,0xFE,0x00,0x11,0x26,
            0x00,0x00,0x0F,0x26,0x00,0x00,0x0F,0x26,0x00,0x00,0x0F,0x26,0x00,0x00,0x0F,0x26,
            0x02,0xFD,0x13,0x53,0x01,0xFB,0x15,0x50,0xFD,0xFE,0x16,0x4B,0x06,0xF7,0x13,0x49,
            0xF7,0x00,0x19,0x40,0x00,0x00,0x10,0x40,0x00,0x00,0x10,0x40,0x04,0xF9,0x10,0x40,
            0xFE,0xFE,0x14,0x39,0xFE,0x00,0x12,0x37,0x00,0x00,0x10,0x37,0x02,0xFE,0x10,0x37,
            0x00,0x00,0x12,0x35,0x00,0x00,0x12,0x35,0xEE,0x00,0x12,0x35,0x00,0x00,0x00,0x35,
            0xFD,0xFF,0x18,0x66,0xFB,0xFC,0x15,0x65,0x01,0xFB,0x10,0x61,0x01,0xFD,0x11,0x5C,
            0x07,0xF7,0x12,0x59,0xF7,0x00,0x19,0x50,0x00,0x00,0x10,0x50,0x03,0xFD,0x10,0x50,
            0x01,0xFC,0x13,0x4D,0xFF,0xFE,0x14,0x49,0xFC,0x00,0x13,0x47,0xFE,0x00,0x0F,0x47,
            0xF3,0x00,0x0D,0x47,0x00,0x00,0x00,0x47,0x09,0xEE,0x00,0x47,0xF7,0x00,0x09,0x35,
            0x01,0xFC,0x10,0x7E,0x06,0xF7,0x11,0x7A,0xFE,0xFC,0x17,0x71,0xFD,0xFE,0x15,0x6D,
            0x00,0xFE,0x12,0x6B,0x07,0xF7,0x12,0x69,0xF7,0x00,0x19,0x60,0x00,0x00,0x10,0x60,
            0x02,0xFD,0x10,0x60,0x00,0xFD,0x12,0x5D,0x00,0xFC,0x12,0x5A,0x00,0xFE,0x12,0x56,
            0xFB,0xF3,0x12,0x54,0x00,0x00,0x0D,0x47,0x07,0xF7,0x0D,0x47,0xF5,0xF7,0x14,0x3E,
            0xFC,0xFD,0x1C,0x8E,0xFD,0xFD,0x18,0x8B,0x00,0xFA,0x15,0x88,0x03,0xFB,0x15,0x82,
            0xFD,0xFE,0x18,0x7D,0xFE,0xFE,0x15,0x7B,0x06,0xF7,0x13,0x79,0xF7,0x00,0x19,0x70,
            0x01,0xFF,0x10,0x70,0x02,0xFD,0x11,0x6F,0xFF,0xFC,0x13,0x6C,0x00,0xFE,0x12,0x68,
            0xFE,0xEE,0x12,0x66,0x00,0x00,0x10,0x54,0xF8,0xFE,0x10,0x54,0x08,0xEC,0x08,0x52,
            0x06,0xF9,0x0F,0xAA,0x01,0xFA,0x15,0xA3,0xFF,0xFA,0x16,0x9D,0x00,0xFE,0x15,0x97,
            0x01,0xFB,0x15,0x95,0x01,0xFC,0x16,0x90,0xFD,0xFD,0x17,0x8C,0x05,0xF7,0x14,0x89,
            0xF7,0x00,0x19,0x80,0x01,0xFF,0x10,0x80,0x04,0xFB,0x11,0x7F,0xFD,0xFE,0x15,0x7A,
            0x01,0xEC,0x12,0x78,0xFD,0x00,0x13,0x64,0x03,0xF6,0x10,0x64,0xF9,0xF4,0x13,0x5A,
            0xFE,0xFF,0x14,0xB9,0xFE,0xFB,0x12,0xB8,0x05,0xF9,0x10,0xB3,0xFE,0xFE,0x15,0xAC,
            0xFF,0xFC,0x13,0xAA,0x01,0xFD,0x12,0xA6,0x00,0xFA,0x13,0xA3,0x03,0xFC,0x13,0x9D,
            0x03,0xF7,0x16,0x99,0xF7,0x00,0x19,0x90,0x01,0xFF,0x10,0x90,0x01,0xFB,0x11,0x8F,
            0x05,0xED,0x12,0x8A,0xFC,0xFD,0x17,0x77,0xFD,0xF9,0x13,0x74,0x04,0xED,0x10,0x6D,
            0x02,0xFD,0x0F,0xCD,0x03,0xF9,0x11,0xCA,0xFE,0xFE,0x14,0xC3,0x00,0xFC,0x12,0xC1,
            0x03,0xFB,0x12,0xBD,0x00,0xFE,0x15,0xB8,0xFE,0xFA,0x15,0xB6,0xFE,0xFF,0x13,0xB0,
            0x03,0xFA,0x11,0xAF,0x05,0xF7,0x14,0xA9,0xF7,0x00,0x19,0xA0,0x04,0xFC,0x10,0xA0,
            0x04,0xF2,0x14,0x9C,0xFF,0xF9,0x18,0x8E,0xF9,0xF6,0x17,0x87,0x00,0xF1,0x10,0x7D,
            0x01,0xFF,0x0B,0xDC,0x04,0xFC,0x0C,0xDB,0x00,0xFC,0x10,0xD7,0x02,0xFC,0x10,0xD3,
            0x00,0xFE,0x12,0xCF,0x00,0xFE,0x12,0xCD,0x06,0xF8,0x12,0xCB,0xFD,0xFD,0x18,0xC3,
            0xFF,0xFD,0x15,0xC0,0x03,0xFC,0x14,0xBD,0x05,0xF7,0x17,0xB9,0xF4,0x00,0x1C,0xB0,
            0x08,0xF6,0x10,0xB0,0x00,0xF8,0x18,0xA6,0x03,0xEF,0x18,0x9E,0xFC,0xF1,0x1B,0x8D,
            0x00,0x00,0x0C,0xE7,0x00,0x00,0x0C,0xE7,0x04,0xFC,0x0C,0xE7,0xFF,0xFE,0x10,0xE3,
            0x01,0xFE,0x0F,0xE1,0x00,0xFE,0x10,0xDF,0xFD,0xFE,0x10,0xDD,0x05,0xFA,0x0D,0xDB,
            0x02,0xFC,0x12,0xD5,0xFF,0xFF,0x14,0xD1,0x01,0xFC,0x13,0xD0,0x08,0xF4,0x14,0xCC,
            0xF6,0xFE,0x1C,0xC0,0x07,0xF8,0x12,0xBE,0xFF,0xF2,0x19,0xB6,0x04,0xED,0x18,0xA8,
            0x00,0x00,0x07,0xF3,0x00,0x00,0x07,0xF3,0x00,0x00,0x07,0xF3,0x03,0xFD,0x07,0xF3,
            0x01,0xFF,0x0A,0xF0,0x00,0xFE,0x0B,0xEF,0x05,0xFB,0x0B,0xED,0x00,0xFF,0x10,0xE8,
            0x01,0xFE,0x10,0xE7,0x01,0xFE,0x11,0xE5,0x00,0xFD,0x12,0xE3,0x01,0xFC,0x12,0xE0,
            0x09,0xF4,0x13,0xDC,0xF5,0xFF,0x1C,0xD0,0x07,0xF1,0x11,0xCF,0x07,0xF1,0x18,0xC0,
            0x00,0x00,0x03,0xFA,0x00,0x00,0x03,0xFA,0x00,0x00,0x03,0xFA,0x00,0x00,0x03,0xFA,
            0x00,0x00,0x03,0xFA,0x02,0xFE,0x03,0xFA,0x00,0x00,0x05,0xF8,0x01,0xFF,0x05,0xF8,
            0x01,0xFF,0x06,0xF7,0x01,0xFF,0x07,0xF6,0x03,0xFD,0x08,0xF5,0x03,0xFD,0x0B,0xF2,
            0x03,0xFD,0x0E,0xEF,0x0B,0xF4,0x11,0xEC,0xFC,0xF8,0x1C,0xE0,0x08,0xF8,0x18,0xD8,
            0x00,0x00,0x03,0xFD,0x00,0x00,0x03,0xFD,0x00,0x00,0x03,0xFD,0x00,0x00,0x03,0xFD,
            0x00,0x00,0x03,0xFD,0x00,0x00,0x03,0xFD,0x00,0x00,0x03,0xFD,0x00,0x00,0x03,0xFD,
            0x00,0x00,0x03,0xFD,0x00,0x00,0x03,0xFD,0x00,0x00,0x03,0xFD,0x00,0x00,0x03,0xFD,
            0x00,0x00,0x03,0xFD,0x01,0xFF,0x03,0xFD,0x0C,0xF4,0x04,0xFC,0x00,0x00,0x10,0xF0,
#endif



};


static code UCHAR ucODTable_2ms[] = {   // 5.58ms  20150504
#if ENABLE_OD_TRANSFORM == ON
            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
            0x15,0x10,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,
            0x2A,0x29,0x20,0x20,0x20,0x1D,0x1D,0x18,0x13,0x13,0x13,0x13,0x13,0x13,0x13,0x13,0x13,
            0x3E,0x3D,0x3B,0x30,0x30,0x30,0x30,0x30,0x28,0x25,0x25,0x25,0x25,0x25,0x25,0x25,0x25,
            0x55,0x52,0x4D,0x4B,0x40,0x40,0x40,0x40,0x38,0x36,0x36,0x36,0x34,0x34,0x34,0x34,0x34,
            0x68,0x67,0x63,0x5E,0x5B,0x50,0x50,0x50,0x4C,0x48,0x46,0x46,0x46,0x46,0x46,0x34,0x34,
            0x80,0x7C,0x73,0x6F,0x6D,0x6B,0x60,0x60,0x60,0x5C,0x59,0x55,0x53,0x46,0x46,0x3D,0x34,
            0x90,0x8D,0x8A,0x84,0x7F,0x7D,0x7B,0x70,0x70,0x6E,0x6B,0x67,0x65,0x53,0x53,0x51,0x3D,
            0xAC,0xA5,0x9F,0x99,0x97,0x92,0x8E,0x8B,0x80,0x80,0x7E,0x79,0x77,0x63,0x63,0x59,0x4D,
            0xBB,0xBA,0xB5,0xAE,0xAC,0xA8,0xA5,0x9F,0x9B,0x90,0x90,0x8E,0x89,0x76,0x73,0x6C,0x59,
            0xCF,0xCC,0xC5,0xC3,0xBF,0xBA,0xB8,0xB2,0xB1,0xAB,0xA0,0xA0,0x9B,0x8D,0x86,0x7C,0x6D,
            0xDE,0xDD,0xD9,0xD5,0xD1,0xCF,0xCD,0xC5,0xC2,0xBF,0xBB,0xB0,0xB0,0xA5,0x9D,0x8C,0x7D,
            0xEE,0xED,0xE9,0xE5,0xE3,0xE1,0xDF,0xDD,0xD7,0xD3,0xD2,0xCE,0xC0,0xBD,0xB5,0xA7,0x94,
            0xF6,0xF6,0xF6,0xF5,0xF2,0xF1,0xEF,0xEA,0xE9,0xE7,0xE5,0xE2,0xDE,0xD0,0xCE,0xBF,0xB0,
            0xFD,0xFD,0xFD,0xFD,0xFD,0xFC,0xFB,0xFA,0xF9,0xF8,0xF7,0xF4,0xF1,0xEE,0xE0,0xD7,0xCF,
            0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xF0,0xF0,
#else
            0xFB,0x00,0x15,0x00,0xFF,0x00,0x10,0x00,0x00,0x00,0x0F,0x00,0x00,0x00,0x0F,0x00,
            0x00,0x00,0x0F,0x00,0x00,0x00,0x0F,0x00,0x00,0x00,0x0F,0x00,0x00,0x00,0x0F,0x00,
            0x00,0x00,0x0F,0x00,0x00,0x00,0x0F,0x00,0x00,0x00,0x0F,0x00,0x00,0x00,0x0F,0x00,
            0x00,0x00,0x0F,0x00,0x00,0x00,0x0F,0x00,0x00,0x00,0x0F,0x00,0x00,0x00,0x0F,0x00,
            0x04,0xFB,0x15,0x15,0xF8,0xFF,0x19,0x10,0x00,0x00,0x11,0x0F,0x00,0x00,0x11,0x0F,
            0xFD,0x00,0x11,0x0F,0x00,0x00,0x0E,0x0F,0xFB,0x00,0x0E,0x0F,0xFB,0x00,0x09,0x0F,
            0x00,0x00,0x04,0x0F,0x00,0x00,0x04,0x0F,0x00,0x00,0x04,0x0F,0x00,0x00,0x04,0x0F,
            0x00,0x00,0x04,0x0F,0x00,0x00,0x04,0x0F,0x00,0x00,0x04,0x0F,0x00,0x00,0x04,0x0F,
            0x00,0xFF,0x14,0x2A,0x07,0xF7,0x14,0x29,0xF5,0x00,0x1B,0x20,0x00,0x00,0x10,0x20,
            0x03,0xFD,0x10,0x20,0x00,0x00,0x13,0x1D,0x05,0xFB,0x13,0x1D,0xFD,0xFB,0x18,0x18,
            0xFD,0x00,0x15,0x13,0x00,0x00,0x12,0x13,0x00,0x00,0x12,0x13,0x00,0x00,0x12,0x13,
            0x00,0x00,0x12,0x13,0x00,0x00,0x12,0x13,0x00,0x00,0x12,0x13,0x00,0x00,0x12,0x13,
            0xFE,0xFF,0x17,0x3E,0xFD,0xFE,0x15,0x3D,0x09,0xF5,0x12,0x3B,0xF5,0x00,0x1B,0x30,
            0x00,0x00,0x10,0x30,0x00,0x00,0x10,0x30,0x00,0x00,0x10,0x30,0x00,0xF8,0x10,0x30,
            0x01,0xFD,0x10,0x28,0x00,0x00,0x11,0x25,0x00,0x00,0x11,0x25,0xFE,0x00,0x11,0x25,
            0x00,0x00,0x0F,0x25,0x00,0x00,0x0F,0x25,0x00,0x00,0x0F,0x25,0x00,0x00,0x0F,0x25,
            0x02,0xFD,0x13,0x55,0x01,0xFB,0x15,0x52,0xFD,0xFE,0x16,0x4D,0x08,0xF5,0x13,0x4B,
            0xF5,0x00,0x1B,0x40,0x00,0x00,0x10,0x40,0x00,0x00,0x10,0x40,0x04,0xF8,0x10,0x40,
            0xFE,0xFE,0x14,0x38,0xFE,0x00,0x12,0x36,0x00,0x00,0x10,0x36,0x02,0xFE,0x10,0x36,
            0x00,0x00,0x12,0x34,0x00,0x00,0x12,0x34,0xEE,0x00,0x12,0x34,0x00,0x00,0x00,0x34,
            0xFD,0xFF,0x18,0x68,0xFB,0xFC,0x15,0x67,0x01,0xFB,0x10,0x63,0x01,0xFD,0x11,0x5E,
            0x09,0xF5,0x12,0x5B,0xF5,0x00,0x1B,0x50,0x00,0x00,0x10,0x50,0x04,0xFC,0x10,0x50,
            0x00,0xFC,0x14,0x4C,0xFF,0xFE,0x14,0x48,0xFC,0x00,0x13,0x46,0xFE,0x00,0x0F,0x46,
            0xF3,0x00,0x0D,0x46,0x00,0x00,0x00,0x46,0x09,0xEE,0x00,0x46,0xF7,0x00,0x09,0x34,
            0x01,0xFC,0x10,0x80,0x06,0xF7,0x11,0x7C,0xFE,0xFC,0x17,0x73,0xFD,0xFE,0x15,0x6F,
            0x00,0xFE,0x12,0x6D,0x09,0xF5,0x12,0x6B,0xF5,0x00,0x1B,0x60,0x00,0x00,0x10,0x60,
            0x02,0xFC,0x10,0x60,0x00,0xFD,0x12,0x5C,0x00,0xFC,0x12,0x59,0x00,0xFE,0x12,0x55,
            0xFB,0xF3,0x12,0x53,0x00,0x00,0x0D,0x46,0x07,0xF7,0x0D,0x46,0xF5,0xF7,0x14,0x3D,
            0xFC,0xFD,0x1C,0x90,0xFD,0xFD,0x18,0x8D,0x00,0xFA,0x15,0x8A,0x03,0xFB,0x15,0x84,
            0xFD,0xFE,0x18,0x7F,0xFE,0xFE,0x15,0x7D,0x08,0xF5,0x13,0x7B,0xF5,0x00,0x1B,0x70,
            0x02,0xFE,0x10,0x70,0x01,0xFD,0x12,0x6E,0xFF,0xFC,0x13,0x6B,0x00,0xFE,0x12,0x67,
            0xFE,0xEE,0x12,0x65,0x00,0x00,0x10,0x53,0xF8,0xFE,0x10,0x53,0x08,0xEC,0x08,0x51,
            0x06,0xF9,0x0F,0xAC,0x01,0xFA,0x15,0xA5,0xFF,0xFA,0x16,0x9F,0x00,0xFE,0x15,0x99,
            0x01,0xFB,0x15,0x97,0x01,0xFC,0x16,0x92,0xFD,0xFD,0x17,0x8E,0x07,0xF5,0x14,0x8B,
            0xF5,0x00,0x1B,0x80,0x02,0xFE,0x10,0x80,0x03,0xFB,0x12,0x7E,0xFD,0xFE,0x15,0x79,
            0x01,0xEC,0x12,0x77,0xFD,0x00,0x13,0x63,0x03,0xF6,0x10,0x63,0xF9,0xF4,0x13,0x59,
            0xFE,0xFF,0x14,0xBB,0xFE,0xFB,0x12,0xBA,0x05,0xF9,0x10,0xB5,0xFE,0xFE,0x15,0xAE,
            0xFF,0xFC,0x13,0xAC,0x01,0xFD,0x12,0xA8,0x00,0xFA,0x13,0xA5,0x03,0xFC,0x13,0x9F,
            0x05,0xF5,0x16,0x9B,0xF5,0x00,0x1B,0x90,0x02,0xFE,0x10,0x90,0x00,0xFB,0x12,0x8E,
            0x05,0xED,0x12,0x89,0xFC,0xFD,0x17,0x76,0xFD,0xF9,0x13,0x73,0x04,0xED,0x10,0x6C,
            0x02,0xFD,0x0F,0xCF,0x03,0xF9,0x11,0xCC,0xFE,0xFE,0x14,0xC5,0x00,0xFC,0x12,0xC3,
            0x03,0xFB,0x12,0xBF,0x00,0xFE,0x15,0xBA,0xFE,0xFA,0x15,0xB8,0xFE,0xFF,0x13,0xB2,
            0x03,0xFA,0x11,0xB1,0x07,0xF5,0x14,0xAB,0xF5,0x00,0x1B,0xA0,0x05,0xFB,0x10,0xA0,
            0x03,0xF2,0x15,0x9B,0xFF,0xF9,0x18,0x8D,0xF9,0xF6,0x17,0x86,0x00,0xF1,0x10,0x7C,
            0x00,0xFF,0x10,0xDE,0x00,0xFC,0x10,0xDD,0x00,0xFC,0x10,0xD9,0x02,0xFC,0x10,0xD5,
            0x00,0xFE,0x12,0xD1,0x00,0xFE,0x12,0xCF,0x06,0xF8,0x12,0xCD,0xFD,0xFD,0x18,0xC5,
            0xFF,0xFD,0x15,0xC2,0x03,0xFC,0x14,0xBF,0x07,0xF5,0x17,0xBB,0xF2,0x00,0x1E,0xB0,
            0x08,0xF5,0x10,0xB0,0x00,0xF8,0x18,0xA5,0x03,0xEF,0x18,0x9D,0xFC,0xF1,0x1B,0x8C,
            0x01,0xFF,0x08,0xEE,0x04,0xFC,0x09,0xED,0x03,0xFC,0x0D,0xE9,0xFF,0xFE,0x10,0xE5,
            0x01,0xFE,0x0F,0xE3,0x00,0xFE,0x10,0xE1,0xFD,0xFE,0x10,0xDF,0x05,0xFA,0x0D,0xDD,
            0x02,0xFC,0x12,0xD7,0xFF,0xFF,0x14,0xD3,0x01,0xFC,0x13,0xD2,0x0A,0xF2,0x14,0xCE,
            0xF5,0xFD,0x1E,0xC0,0x06,0xF8,0x13,0xBD,0xFF,0xF2,0x19,0xB5,0x04,0xED,0x18,0xA7,
            0x00,0x00,0x07,0xF6,0x00,0x00,0x07,0xF6,0x01,0xFF,0x07,0xF6,0x03,0xFD,0x08,0xF5,
            0x00,0xFF,0x0B,0xF2,0x01,0xFE,0x0B,0xF1,0x04,0xFB,0x0C,0xEF,0x00,0xFF,0x10,0xEA,
            0x01,0xFE,0x10,0xE9,0x01,0xFE,0x11,0xE7,0x00,0xFD,0x12,0xE5,0x01,0xFC,0x12,0xE2,
            0x0B,0xF2,0x13,0xDE,0xF4,0xFE,0x1E,0xD0,0x06,0xF1,0x12,0xCE,0x07,0xF1,0x18,0xBF,
            0x00,0x00,0x01,0xFD,0x00,0x00,0x01,0xFD,0x00,0x00,0x01,0xFD,0x00,0x00,0x01,0xFD,
            0x01,0xFF,0x01,0xFD,0x01,0xFF,0x02,0xFC,0x01,0xFF,0x03,0xFB,0x01,0xFF,0x04,0xFA,
            0x01,0xFF,0x05,0xF9,0x01,0xFF,0x06,0xF8,0x03,0xFD,0x07,0xF7,0x03,0xFD,0x0A,0xF4,
            0x03,0xFD,0x0D,0xF1,0x0E,0xF2,0x10,0xEE,0xFB,0xF7,0x1E,0xE0,0x08,0xF8,0x19,0xD7,
            0x00,0x00,0x02,0xFE,0x00,0x00,0x02,0xFE,0x00,0x00,0x02,0xFE,0x00,0x00,0x02,0xFE,
            0x00,0x00,0x02,0xFE,0x00,0x00,0x02,0xFE,0x00,0x00,0x02,0xFE,0x00,0x00,0x02,0xFE,
            0x00,0x00,0x02,0xFE,0x00,0x00,0x02,0xFE,0x00,0x00,0x02,0xFE,0x00,0x00,0x02,0xFE,
            0x00,0x00,0x02,0xFE,0x00,0x00,0x02,0xFE,0x0E,0xF2,0x02,0xFE,0x00,0x00,0x10,0xF0,
#endif



};

static code UCHAR ucODTable_1ms[] = {    //  1.88ms  20150310
#if ENABLE_OD_TRANSFORM == ON
            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
            0x16,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
            0x35,0x33,0x20,0x09,0x09,0x06,0x06,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
            0x4D,0x49,0x47,0x30,0x1B,0x17,0x17,0x17,0x0F,0x0C,0x09,0x05,0x03,0x00,0x00,0x00,0x00,
            0x64,0x5E,0x59,0x56,0x40,0x29,0x27,0x27,0x1F,0x1D,0x1B,0x17,0x15,0x09,0x09,0x09,0x07,
            0x79,0x73,0x6F,0x6A,0x66,0x50,0x39,0x39,0x33,0x2F,0x2D,0x29,0x27,0x19,0x19,0x19,0x0F,
            0x91,0x88,0x7F,0x7B,0x79,0x76,0x60,0x48,0x46,0x42,0x3F,0x3B,0x39,0x2C,0x2C,0x23,0x17,
            0xA1,0x99,0x96,0x90,0x8B,0x89,0x87,0x70,0x58,0x54,0x51,0x4D,0x4B,0x39,0x39,0x37,0x23,
            0xBD,0xB1,0xAB,0xA5,0xA3,0x9E,0x9A,0x97,0x80,0x68,0x64,0x5F,0x5D,0x49,0x49,0x3F,0x33,
            0xCB,0xC6,0xC1,0xBA,0xB8,0xB4,0xB1,0xAB,0xA7,0x90,0x78,0x74,0x6F,0x5C,0x59,0x52,0x3F,
            0xDF,0xD8,0xD1,0xCF,0xCB,0xC6,0xC4,0xBE,0xBD,0xB7,0xA0,0x89,0x81,0x73,0x6C,0x62,0x53,
            0xEB,0xE9,0xE5,0xE1,0xDD,0xDB,0xD9,0xD1,0xCE,0xCB,0xC7,0xB0,0x96,0x8B,0x83,0x72,0x63,
            0xFB,0xF9,0xF5,0xF1,0xEF,0xED,0xEB,0xE9,0xE3,0xDF,0xDE,0xDA,0xC0,0xA3,0x9B,0x8D,0x7A,
            0xFF,0xFF,0xFF,0xFF,0xFE,0xFD,0xFB,0xF5,0xF5,0xF3,0xF1,0xEE,0xEA,0xD0,0xB4,0xA5,0x96,
            0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFD,0xFA,0xE0,0xBD,0xB5,
            0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,0xD6,
#else
            0xFA,0x00,0x16,0x00,0xF0,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
            0x04,0xFA,0x1F,0x16,0xFD,0xF0,0x23,0x10,0xE9,0x00,0x20,0x00,0x00,0x00,0x09,0x00,
            0xFD,0x00,0x09,0x00,0x00,0x00,0x06,0x00,0xFE,0x00,0x06,0x00,0xFC,0x00,0x04,0x00,
            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
            0xFE,0xFE,0x18,0x35,0x11,0xED,0x16,0x33,0x00,0xE9,0x27,0x20,0xEB,0x00,0x27,0x09,
            0xFF,0xFD,0x12,0x09,0x00,0x00,0x11,0x06,0x02,0xFE,0x11,0x06,0xFC,0xFC,0x13,0x04,
            0xFD,0x00,0x0F,0x00,0xFD,0x00,0x0C,0x00,0xFC,0x00,0x09,0x00,0xFE,0x00,0x05,0x00,
            0xFD,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
            0xFE,0xFC,0x17,0x4D,0xFD,0xFE,0x15,0x49,0x14,0xE9,0x12,0x47,0xFF,0xEB,0x26,0x30,
            0xED,0xFC,0x25,0x1B,0xFE,0x00,0x12,0x17,0x00,0x00,0x10,0x17,0x00,0xF8,0x10,0x17,
            0x01,0xFD,0x10,0x0F,0x01,0xFD,0x11,0x0C,0x00,0xFC,0x12,0x09,0x00,0xFE,0x12,0x05,
            0xF7,0xFD,0x12,0x03,0x00,0x00,0x09,0x00,0x00,0x00,0x09,0x00,0xFE,0x00,0x09,0x00,
            0x00,0xFA,0x15,0x64,0x01,0xFB,0x15,0x5E,0xFE,0xFD,0x16,0x59,0x12,0xEA,0x14,0x56,
            0x01,0xE9,0x26,0x40,0xEB,0xFE,0x27,0x29,0x00,0x00,0x12,0x27,0x02,0xF8,0x12,0x27,
            0xFE,0xFE,0x14,0x1F,0x00,0xFE,0x12,0x1D,0x00,0xFC,0x12,0x1B,0x00,0xFE,0x12,0x17,
            0xFE,0xF4,0x12,0x15,0x00,0x00,0x10,0x09,0x00,0x00,0x10,0x09,0xF8,0xFE,0x10,0x09,
            0xFD,0xFA,0x18,0x79,0xFB,0xFC,0x15,0x73,0x01,0xFB,0x10,0x6F,0x02,0xFC,0x11,0x6A,
            0x13,0xEA,0x13,0x66,0x01,0xE9,0x26,0x50,0xE8,0x00,0x27,0x39,0x04,0xFA,0x0F,0x39,
            0x00,0xFC,0x13,0x33,0xFF,0xFE,0x13,0x2F,0x00,0xFC,0x12,0x2D,0x00,0xFE,0x12,0x29,
            0x01,0xF2,0x12,0x27,0x00,0x00,0x13,0x19,0xF7,0x00,0x13,0x19,0xFE,0xF6,0x0A,0x19,
            0x01,0xF7,0x10,0x91,0x06,0xF7,0x11,0x88,0xFE,0xFC,0x17,0x7F,0xFD,0xFE,0x15,0x7B,
            0x01,0xFD,0x12,0x79,0x14,0xEA,0x13,0x76,0x01,0xE8,0x27,0x60,0xEA,0xFE,0x28,0x48,
            0x00,0xFC,0x12,0x46,0x00,0xFD,0x12,0x42,0x00,0xFC,0x12,0x3F,0x00,0xFE,0x12,0x3B,
            0xFB,0xF3,0x12,0x39,0x00,0x00,0x0D,0x2C,0x07,0xF7,0x0D,0x2C,0xF8,0xF4,0x14,0x23,
            0xFC,0xF8,0x1C,0xA1,0xFD,0xFD,0x18,0x99,0x00,0xFA,0x15,0x96,0x03,0xFB,0x15,0x90,
            0xFD,0xFE,0x18,0x8B,0xFE,0xFE,0x15,0x89,0x14,0xE9,0x13,0x87,0x01,0xE8,0x27,0x70,
            0xEC,0xFC,0x28,0x58,0xFF,0xFD,0x14,0x54,0xFF,0xFC,0x13,0x51,0x00,0xFE,0x12,0x4D,
            0xFE,0xEE,0x12,0x4B,0x00,0x00,0x10,0x39,0xF8,0xFE,0x10,0x39,0x08,0xEC,0x08,0x37,
            0x07,0xF4,0x0E,0xBD,0x01,0xFA,0x15,0xB1,0xFF,0xFA,0x16,0xAB,0x00,0xFE,0x15,0xA5,
            0x01,0xFB,0x15,0xA3,0x01,0xFC,0x16,0x9E,0xFD,0xFD,0x17,0x9A,0x13,0xE9,0x14,0x97,
            0x01,0xE8,0x27,0x80,0xEC,0xFC,0x28,0x68,0x01,0xFB,0x14,0x64,0xFD,0xFE,0x15,0x5F,
            0x01,0xEC,0x12,0x5D,0xFD,0x00,0x13,0x49,0x03,0xF6,0x10,0x49,0xF9,0xF4,0x13,0x3F,
            0xFE,0xFB,0x14,0xCB,0xFE,0xFB,0x12,0xC6,0x05,0xF9,0x10,0xC1,0xFE,0xFE,0x15,0xBA,
            0xFF,0xFC,0x13,0xB8,0x01,0xFD,0x12,0xB4,0x00,0xFA,0x13,0xB1,0x03,0xFC,0x13,0xAB,
            0x11,0xE9,0x16,0xA7,0x01,0xE8,0x27,0x90,0xED,0xFC,0x28,0x78,0xFD,0xFB,0x15,0x74,
            0x05,0xED,0x12,0x6F,0xFC,0xFD,0x17,0x5C,0xFD,0xF9,0x13,0x59,0x04,0xED,0x10,0x52,
            0x05,0xF9,0x0C,0xDF,0x03,0xF9,0x11,0xD8,0xFE,0xFE,0x14,0xD1,0x00,0xFC,0x12,0xCF,
            0x03,0xFB,0x12,0xCB,0x00,0xFE,0x15,0xC6,0xFE,0xFA,0x15,0xC4,0xFE,0xFF,0x13,0xBE,
            0x03,0xFA,0x11,0xBD,0x13,0xE9,0x14,0xB7,0x00,0xE9,0x27,0xA0,0xEE,0xF8,0x27,0x89,
            0x03,0xF2,0x15,0x81,0xFF,0xF9,0x18,0x73,0xF9,0xF6,0x17,0x6C,0x00,0xF1,0x10,0x62,
            0x00,0xFE,0x10,0xEB,0x00,0xFC,0x10,0xE9,0x00,0xFC,0x10,0xE5,0x02,0xFC,0x10,0xE1,
            0x00,0xFE,0x12,0xDD,0x00,0xFE,0x12,0xDB,0x06,0xF8,0x12,0xD9,0xFD,0xFD,0x18,0xD1,
            0xFF,0xFD,0x15,0xCE,0x03,0xFC,0x14,0xCB,0x13,0xE9,0x17,0xC7,0x00,0xE6,0x2A,0xB0,
            0xEE,0xF5,0x2A,0x96,0x00,0xF8,0x18,0x8B,0x03,0xEF,0x18,0x83,0xFC,0xF1,0x1B,0x72,
            0x02,0xFE,0x04,0xFB,0x04,0xFC,0x06,0xF9,0x04,0xFC,0x0A,0xF5,0x01,0xFE,0x0E,0xF1,
            0x01,0xFE,0x0F,0xEF,0x00,0xFE,0x10,0xED,0xFC,0xFE,0x10,0xEB,0x06,0xFA,0x0C,0xE9,
            0x02,0xFC,0x12,0xE3,0xFF,0xFF,0x14,0xDF,0x01,0xFC,0x13,0xDE,0x16,0xE6,0x14,0xDA,
            0x03,0xE3,0x2A,0xC0,0xEC,0xF8,0x2D,0xA3,0xFF,0xF2,0x19,0x9B,0x04,0xED,0x18,0x8D,
            0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x01,0xFF,0x00,0xFF,
            0x01,0xFF,0x01,0xFE,0x02,0xFE,0x02,0xFD,0x06,0xFA,0x04,0xFB,0x00,0x00,0x0A,0xF5,
            0x02,0xFE,0x0A,0xF5,0x02,0xFE,0x0C,0xF3,0x03,0xFD,0x0E,0xF1,0x02,0xFC,0x11,0xEE,
            0x17,0xE6,0x13,0xEA,0x02,0xE4,0x2A,0xD0,0xEC,0xF1,0x2C,0xB4,0x07,0xF1,0x18,0xA5,
            0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,
            0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,
            0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x02,0xFE,0x00,0xFF,
            0x03,0xFD,0x02,0xFD,0x1A,0xE6,0x05,0xFA,0x14,0xDD,0x1F,0xE0,0xEE,0xF8,0x33,0xBD,
            0x00,0x00,0x01,0xFF,0x00,0x00,0x01,0xFF,0x00,0x00,0x01,0xFF,0x00,0x00,0x01,0xFF,
            0x00,0x00,0x01,0xFF,0x00,0x00,0x01,0xFF,0x00,0x00,0x01,0xFF,0x00,0x00,0x01,0xFF,
            0x00,0x00,0x01,0xFF,0x00,0x00,0x01,0xFF,0x00,0x00,0x01,0xFF,0x00,0x00,0x01,0xFF,
            0x00,0x00,0x01,0xFF,0x00,0x00,0x01,0xFF,0x0F,0xF1,0x01,0xFF,0x1A,0xE6,0x10,0xF0,
#endif


};

static code UCHAR* ODTable[] = {
    ucODTable_4ms, ucODTable_3ms, ucODTable_2ms,ucODTable_1ms
};

#endif //#if ENABLE_OD == ON

