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
#define _0xE8 0x00
#define _0x901F 0x01
#define _0x9078 0x02
#define _0xE0 0x03
#define _0xE1 0x04
#define _0x9AD8 0x05
#define _0xE4 0x06
#define _0xE7 0x07
#define _0xE9 0x08
#define _0x0001 0x09
#define _0x9ED8 0x0A
#define _0xED 0x0B
#define _0xF1 0x0C
#define _0xF3 0x0D
#define _0x7B80 0x0E
#define _0xFA 0x0F
#define _0xFC 0x10
#define _0x91CF 0x11
#define _0x92B3 0x12
#define _0x9510 0x13
#define _0x958B 0x14
#define _0x9593 0x15
#define _0x95F4 0x16
#define _0x96E2 0x17
#define _0x9752 0x18
#define _0x97F3 0x19
#define _0x9810 0x1A
#define _0x986F 0x1B
#define _0x9AD4 0x1C
#define _0x9AD5 0x1D
#define _0x9AD6 0x1E
#define _0x570D 0x1F
#define _0x0002 0x3C
#define _0x0003 0x3E
#define _0x983B 0x5B
#define _0x7387 0x5C
#define _0x9891 0x5D
#define _0x85CD 0x5E
#define _0x663E 0x5F
#define _0x90E8 0x60
#define _0x3044 0x7B
#define _0x3048 0x7C
#define _0x304F 0x7D
#define _0x3055 0x7E
#define _0x305D 0x7F
#define _0x306E 0x80
#define _0x306F 0x81
#define _0x30A3 0x82
#define _0x30A4 0x83
#define _0x30A7 0x84
#define _0x30AB 0x85
#define _0x30B3 0x86
#define _0x30B6 0x87
#define _0x30B9 0x88
#define _0x30BA 0x89
#define _0x30C7 0x8A
#define _0x30C8 0x8B
#define _0x30CB 0x8C
#define _0x30D5 0x8D
#define _0x30D7 0x8E
#define _0x30E1 0x8F
#define _0x30E5 0x90
#define _0x30E6 0x91
#define _0x30E9 0x92
#define _0x30EA 0x93
#define _0x30EB 0x94
#define _0x30EC 0x95
#define _0x30F3 0x96
#define _0x4E00 0x97
#define _0x4E0D 0x98
#define _0x4E2D 0x99
#define _0x4E3B 0x9A
#define _0x4E86 0x9B
#define _0x4EAE 0x9C
#define _0x4ED6 0x9D
#define _0x4F18 0x9E
#define _0x4F4D 0x9F
#define _0x4F53 0xA0
#define _0x4F55 0xA1
#define _0x4F7F 0xA2
#define _0x503C 0xA3
#define _0x50CF 0xA4
#define _0x512A 0xA5
#define _0x5168 0xA6
#define _0x5176 0xA7
#define _0x51E0 0xA8
#define _0x51FA 0xA9
#define _0x5229 0xAA
#define _0x52A8 0xAB
#define _0x52D5 0xAC
#define _0x5316 0xAD
#define _0x5355 0xAE
#define _0x53CA 0xAF
#define _0x53F7 0xB0
#define _0x5426 0xB1
#define _0x5468 0xB2
#define _0x548C 0xB3
#define _0x55AE 0xB4
#define _0x56DE 0xB5
#define _0x56F4 0xB6
#define _0x5782 0xB7
#define _0x5831 0xB8
#define _0x590D 0xB9
#define _0x5B9A 0xBA
#define _0x5BF9 0xBB
#define _0x5C0D 0xBC
#define _0x5E73 0xBD
#define _0x5E7E 0xBE
#define _0x5EA6 0xBF
#define _0x5F00 0xC0
#define _0x5F31 0xC1
#define _0x5F37 0xC2
#define _0x5F69 0xC3
#define _0x5FA9 0xC4
#define _0x6062 0xC5
#define _0x60C5 0xC6
#define _0x62E9 0xC7
#define _0x64C7 0xC8
#define _0x6548 0xC9
#define _0x6570 0xCA
#define _0x6574 0xCB
#define _0x6587 0xCC
#define _0x65E0 0xCD
#define _0x65E5 0xCE
#define _0x65F6 0xCF
#define _0x660E 0xD0
#define _0x662F 0xd1
#define _0x6642 0xD2
#define _0x6781 0xD3
#define _0x67D4 0xD4
#define _0x6975 0xD5
#define _0x6BD4 0xD6
#define _0x6C34 0xD7
#define _0x6CE2 0xD8
#define _0x7121 0xD9
#define _0x7528 0xDA
#define _0x76F4 0xDB
#define _0x76F8 0xDC
#define _0x793A 0xDD
#define _0x79BB 0xDE
#define _0x7BC4 0xDF
#define _0x7D05 0xE0
#define _0x7D20 0xE1
#define _0x7D42 0xE2
#define _0x7DA0 0xE3
#define _0x7E41 0xE4
#define _0x7EA2 0xE5
#define _0x7EFF 0xE6
#define _0x7F6E 0xE7
#define _0x8005 0xE8
#define _0x80FD 0xE9
#define _0x81EA 0xEA
#define _0x8272 0xEB
#define _0x8282 0xEC
#define _0x8303 0xED
#define _0x83DC 0xEE
#define _0x84DD 0xEF
#define _0x865F 0xF0
#define _0x8868 0xF1
#define _0x8A00 0xF2
#define _0x8A0A 0xF3
#define _0x8A2D 0xF4
#define _0x8A9E 0xF5
#define _0x8ABF 0xF6
#define _0x8BA4 0xF7
#define _0x8BAF 0xF8
#define _0x8BBE 0xF9
#define _0x8BED 0xFA
#define _0x8C03 0xFB
#define _0x8D64 0xFC
#define _0x8D85 0xFD
#define _0x8F1D 0xFE
#define _0x9009 0xFF

//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************

//code UCHAR MenuTitleStr[] = {14, "Mode: Standard"};

code UCHAR EN_DisplayTab1[]={7, 'D', 'i', 's', 'p', 'l', 'a', 'y', };
code UCHAR FR_DisplayTab1[]={7, 'A', 'f', 'f', 'i', 'c', 'h', '.', };
code UCHAR GE_DisplayTab1[]={7, 'A', 'n', 'z', 'e', 'i', 'g', 'e', };
code UCHAR IT_DisplayTab1[]={8, 'D', 'i', 's', 'p', 'l', 'a', 'y', ' ', };
code UCHAR SP_DisplayTab1[]={9, 'P', 'a', 'n', 't', 'a', 'l', 'l', 'a', ' ', };
code UCHAR PO_DisplayTab1[]={5, 'W', 'y', 123, 'w', '.', };
code UCHAR CZ_DisplayTab1[]={8, 'D', 'i', 's', 'p', 'l', 'e', 'j', ' ', };
code UCHAR MA_DisplayTab1[]={7, 'M', 'e', 'g', 'j', 'e', 'l', '.', };
code UCHAR SE_DisplayTab1[]={6, 'P', 'r', 'i', 'k', 'a', 'z', };
code UCHAR RO_DisplayTab1[]={6, 'A', 'f', 'i', 123, 'a', 'j', };
code UCHAR DU_DisplayTab1[]={6, 'S', 'c', 'h', 'e', 'r', 'm', };
code UCHAR RU_DisplayTab1[]={7, 123, 124, 125, 126, 127, 128, 129, };
code UCHAR SW_DisplayTab1[]={4, 'V', 'i', 's', 'a', };
code UCHAR PR_DisplayTab1[]={4, 'E', 'c', 'r', 123, };
code UCHAR JA_DisplayTab1[]={2, 0, 1, };
code UCHAR CT_DisplayTab1[]={2, 0, 1, };
code UCHAR CS_DisplayTab1[]={2, 0, 1, };

 code UCHAR EN_PictureTab1[]={7, 'P', 'i', 'c', 't', 'u', 'r', 'e', };
code UCHAR FR_PictureTab1[]={5, 'I', 'm', 'a', 'g', 'e', };
code UCHAR GE_PictureTab1[]={4, 'B', 'i', 'l', 'd', };
code UCHAR IT_PictureTab1[]={8, 'I', 'm', 'm', 'a', 'g', 'i', 'n', 'e', };
code UCHAR SP_PictureTab1[]={6, 'I', 'm', 'a', 'g', 'e', 'n', };
code UCHAR PO_PictureTab1[]={5, 'O', 'b', 'r', 'a', 'z', };
code UCHAR CZ_PictureTab1[]={5, 'O', 'b', 'r', 'a', 'z', };
code UCHAR MA_PictureTab1[]={3, 'K', 2, 'p', };
code UCHAR SE_PictureTab1[]={5, 'S', 'l', 'i', 'k', 'a', };
code UCHAR RO_PictureTab1[]={7, 'I', 'm', 'a', 'g', 'i', 'n', 'e', };
code UCHAR DU_PictureTab1[]={5, 'B', 'e', 'e', 'l', 'd', };
code UCHAR RU_PictureTab1[]={11, 150, 141, 136, 151, 133, 143, 152, 128, 144, 124, 128, };
code UCHAR SW_PictureTab1[]={4, 'B', 'i', 'l', 'd', };
code UCHAR PR_PictureTab1[]={6, 'I', 'm', 'a', 'g', 'e', 'm', };
code UCHAR JA_PictureTab1[]={2, 25, 26, };
code UCHAR CT_PictureTab1[]={2, 23, 24, };
code UCHAR CS_PictureTab1[]={2, 23, 24, };

code UCHAR EN_PictureAdvancedTab1[]={16, 'P', 'i', 'c', 't', 'u', 'r', 'e', ' ', 'A', 'd', 'v', 'a', 'n', 'c', 'e', 'd', };
code UCHAR FR_PictureAdvancedTab1[]={13, 'I', 'm', 'a', 'g', 'e', ' ', 'a', 'v', 'a', 'n', 'c', 2, 'e', };
code UCHAR GE_PictureAdvancedTab1[]={14, 'B', 'i', 'l', 'd', ' ', 'e', 'r', 'w', 'e', 'i', 't', 'e', 'r', 't', };
code UCHAR IT_PictureAdvancedTab1[]={12, 'I', 'm', 'm', ' ', 'a', 'v', 'a', 'n', 'z', 'a', 't', 'a', };
code UCHAR SP_PictureAdvancedTab1[]={15, 'I', 'm', 'a', 'g', 'e', 'n', ' ', 'a', 'v', 'a', 'n', 'z', 'a', 'd', 'a', };
code UCHAR PO_PictureAdvancedTab1[]={13, 'O', 'b', 'r', 'a', 'z', ' ', 'z', 'a', 'a', 'w', 'a', 'n', '.', };
code UCHAR CZ_PictureAdvancedTab1[]={16, 'O', 'b', 'r', 'a', 'z', ' ', 126, ' ', 'U', 'p', 124, 'e', 's', 'n', 'i', 't', };
code UCHAR MA_PictureAdvancedTab1[]={13, 'K', 2, 'p', ' ', 's', 'p', 'e', 'c', 'i', 0, 'l', 'i', 's', };
code UCHAR SE_PictureAdvancedTab1[]={16, 'N', 'a', 'p', 'r', '.', ' ', 'p', 'o', 'd', '.', ' ', 's', 'l', 'i', 'k', 'e', };
code UCHAR RO_PictureAdvancedTab1[]={16, 'I', 'm', 'a', 'g', 'i', 'n', 'e', ' ', 'a', 'v', 'a', 'n', 's', 'a', 't', 125, };
code UCHAR DU_PictureAdvancedTab1[]={14, 'B', 'e', 'e', 'l', 'd', ' ', 'g', 'e', 'a', 'v', 'a', 'n', 'c', '.', };
code UCHAR RU_PictureAdvancedTab1[]={11, 158, 143, 125, 132, '.', 124, 141, 136, 151, 133, '.', };
code UCHAR SW_PictureAdvancedTab1[]={14, 'A', 'v', 'a', 'n', 'c', 'e', 'r', 'a', 'd', ' ', 'b', 'i', 'l', 'd', };
code UCHAR PR_PictureAdvancedTab1[]={15, 'I', 'm', 'a', 'g', 'e', 'm', ' ', 'a', 'v', 'a', 'n', 7, 'a', 'd', 'a', };
code UCHAR JA_PictureAdvancedTab1[]={7, 25, 26, 145, 157, 158, 141, 142, };
code UCHAR CT_PictureAdvancedTab1[]={8, 23, 24, 146, 141, 147, 133, ' ', 148, };
code UCHAR CS_PictureAdvancedTab1[]={6, 23, 16, 140, 141, 145, 13, };

 code UCHAR EN_AudioTab1[]={5, 'A', 'u', 'd', 'i', 'o', };
 code UCHAR FR_AudioTab1[]={3, 'S', 'o', 'n', };
 code UCHAR GE_AudioTab1[]={5, 'A', 'u', 'd', 'i', 'o', };
 code UCHAR IT_AudioTab1[]={5, 'A', 'u', 'd', 'i', 'o', };
 code UCHAR SP_AudioTab1[]={6, 'S', 'o', 'n', 'i', 'd', 'o', };
 code UCHAR PO_AudioTab1[]={5, 'A', 'u', 'd', 'i', 'o', };
 code UCHAR CZ_AudioTab1[]={4, 'Z', 'v', 'u', 'k', };
 code UCHAR MA_AudioTab1[]={4, 'H', 'a', 'n', 'g', };
 code UCHAR SE_AudioTab1[]={4, 'Z', 'v', 'u', 'k', };
 code UCHAR RO_AudioTab1[]={5, 'A', 'u', 'd', 'i', 'o', };
 code UCHAR DU_AudioTab1[]={5, 'A', 'u', 'd', 'i', 'o', };
 code UCHAR RU_AudioTab1[]={5, 130, 135, 139, 124, 136, };
 code UCHAR SW_AudioTab1[]={4, 'L', 'j', 'u', 'd', };
 code UCHAR PR_AudioTab1[]={6, 21, 'U', 'D', 'I', 'O', ' ', };
 code UCHAR JA_AudioTab1[]={5, 149, 21, 161, 170, 149, };
 code UCHAR CT_AudioTab1[]={4, 190, 191, 147, 133, };
 code UCHAR CS_AudioTab1[]={4, 189, 148, 145, 133, };

code UCHAR EN_SystemTab1[]={6, 'S', 'y', 's', 't', 'e', 'm', };
code UCHAR FR_SystemTab1[]={7, 'S', 'y', 's', 't', 29, 'm', 'e', };
code UCHAR GE_SystemTab1[]={6, 'S', 'y', 's', 't', 'e', 'm', };
code UCHAR IT_SystemTab1[]={7, 'S', 'i', 's', 't', 'e', 'm', 'a', };
code UCHAR SP_SystemTab1[]={7, 'S', 'i', 's', 't', 'e', 'm', 'a', };
code UCHAR PO_SystemTab1[]={6, 'S', 'y', 's', 't', 'e', 'm', };
code UCHAR CZ_SystemTab1[]={6, 'S', 'y', 's', 't', 2, 'm', };
code UCHAR MA_SystemTab1[]={8, 'R', 'e', 'n', 'd', 's', 'z', 'e', 'r', };
code UCHAR SE_SystemTab1[]={6, 'S', 'u', 's', 't', 'a', 'v', };
code UCHAR RO_SystemTab1[]={6, 'S', 'i', 's', 't', 'e', 'm', };
code UCHAR DU_SystemTab1[]={7, 'S', 'y', 's', 't', 'e', 'e', 'm', };
code UCHAR RU_SystemTab1[]={7, 164, 124, 125, 132, 128, 146, 143, };
code UCHAR SW_SystemTab1[]={6, 'S', 'y', 's', 't', 'e', 'm', };
code UCHAR PR_SystemTab1[]={7, 'S', 'i', 's', 't', 'e', 'm', 'a', };
code UCHAR JA_SystemTab1[]={4, 125, 31, 205, 154, };
code UCHAR CT_SystemTab1[]={2, 199, 200, };
code UCHAR CS_SystemTab1[]={2, 198, 199, };

code UCHAR EN_ErgonomicsTab1[]={10, 'E', 'R', 'G', 'O', 'N', 'O', 'M', 'I', 'C', 'S', };
code UCHAR FR_ErgonomicsTab1[]={9, 'E', 'R', 'G', 'O', 'N', 'O', 'M', 'I', 'E', };
code UCHAR GE_ErgonomicsTab1[]={9, 'E', 'R', 'G', 'O', 'N', 'O', 'M', 'I', 'E', };
code UCHAR IT_ErgonomicsTab1[]={10, 'E', 'R', 'G', 'O', 'N', 'O', 'M', 'I', 'C', 'O', };
code UCHAR SP_ErgonomicsTab1[]={10, 'E', 'R', 'G', 'O', 'N', 30, 'M', 'I', 'C', 'O', };
code UCHAR PO_ErgonomicsTab1[]={9, 'E', 'R', 'G', 'O', 'N', 'O', 'M', 'I', 'A', };
code UCHAR CZ_ErgonomicsTab1[]={9, 'E', 'R', 'G', 'O', 'N', 'O', 'M', 'I', 'E', };
code UCHAR MA_ErgonomicsTab1[]={9, 'E', 'R', 'G', 'O', 'N', 30, 'M', 'I', 'A', };
code UCHAR SE_ErgonomicsTab1[]={10, 'E', 'R', 'G', 'O', 'N', 'O', 'M', 'I', 'J', 'A', };
code UCHAR RO_ErgonomicsTab1[]={9, 'E', 'R', 'G', 'O', 'N', 'O', 'M', 'I', 'E', };
code UCHAR DU_ErgonomicsTab1[]={9, 'E', 'R', 'G', 'O', 'N', 'O', 'M', 'I', 'E', };
code UCHAR RU_ErgonomicsTab1[]={10, 178, 156, 140, 162, 158, 162, 168, 150, 153, 130, };
code UCHAR SW_ErgonomicsTab1[]={8, 'E', 'R', 'G', 'O', 'N', 'O', 'M', 'I', };
code UCHAR PR_ErgonomicsTab1[]={9, 'E', 'R', 'G', 'O', 'N', 'O', 'M', 'I', 'A', };
code UCHAR JA_ErgonomicsTab1[]={7, 173, 164, 240, 241, 152, 217, 31, };
code UCHAR CT_ErgonomicsTab1[]={4, 233, 163, 234, 235, };
code UCHAR CS_ErgonomicsTab1[]={5, 232, 163, 233, 234, 235, };
     
code UCHAR *MainMenuStrTab[]={
     EN_DisplayTab1,
     FR_DisplayTab1,
     GE_DisplayTab1,
     IT_DisplayTab1,
     SP_DisplayTab1,
     PO_DisplayTab1,
     CZ_DisplayTab1,
     MA_DisplayTab1,
     SE_DisplayTab1,
     RO_DisplayTab1,
     DU_DisplayTab1,
     RU_DisplayTab1,
     SW_DisplayTab1,
     PR_DisplayTab1,
     JA_DisplayTab1,
     CT_DisplayTab1,
     CS_DisplayTab1,
     
     EN_PictureTab1,
     FR_PictureTab1,
     GE_PictureTab1,
     IT_PictureTab1,
     SP_PictureTab1,
     PO_PictureTab1,
     CZ_PictureTab1,
     MA_PictureTab1,
     SE_PictureTab1,
     RO_PictureTab1,
     DU_PictureTab1,
     RU_PictureTab1,
     SW_PictureTab1,
     PR_PictureTab1,
     JA_PictureTab1,
     CT_PictureTab1,
     CS_PictureTab1,
     
     EN_PictureAdvancedTab1,
     FR_PictureAdvancedTab1,
     GE_PictureAdvancedTab1,
     IT_PictureAdvancedTab1,
     SP_PictureAdvancedTab1,
     PO_PictureAdvancedTab1,
     CZ_PictureAdvancedTab1,
     MA_PictureAdvancedTab1,
     SE_PictureAdvancedTab1,
     RO_PictureAdvancedTab1,
     DU_PictureAdvancedTab1,
     RU_PictureAdvancedTab1,
     SW_PictureAdvancedTab1,
     PR_PictureAdvancedTab1,
     JA_PictureAdvancedTab1,
     CT_PictureAdvancedTab1,
     CS_PictureAdvancedTab1,

     EN_AudioTab1,
     FR_AudioTab1,
     GE_AudioTab1,
     IT_AudioTab1,
     SP_AudioTab1,
     PO_AudioTab1,
     CZ_AudioTab1,
     MA_AudioTab1,
     SE_AudioTab1,
     RO_AudioTab1,
     DU_AudioTab1,
     RU_AudioTab1,
     SW_AudioTab1,
     PR_AudioTab1,
     JA_AudioTab1,
     CT_AudioTab1,
     CS_AudioTab1,

     EN_SystemTab1,
     FR_SystemTab1,
     GE_SystemTab1,
     IT_SystemTab1,
     SP_SystemTab1,
     PO_SystemTab1,
     CZ_SystemTab1,
     MA_SystemTab1,
     SE_SystemTab1,
     RO_SystemTab1,
     DU_SystemTab1,
     RU_SystemTab1,
     SW_SystemTab1,
     PR_SystemTab1,
     JA_SystemTab1,
     CT_SystemTab1,
     CS_SystemTab1,

     EN_ErgonomicsTab1,
     FR_ErgonomicsTab1,
     GE_ErgonomicsTab1,
     IT_ErgonomicsTab1,
     SP_ErgonomicsTab1,
     PO_ErgonomicsTab1,
     CZ_ErgonomicsTab1,
     MA_ErgonomicsTab1,
     SE_ErgonomicsTab1,
     RO_ErgonomicsTab1,
     DU_ErgonomicsTab1,
     RU_ErgonomicsTab1,
     SW_ErgonomicsTab1,
     PR_ErgonomicsTab1,
     JA_ErgonomicsTab1,
     CT_ErgonomicsTab1,
     CS_ErgonomicsTab1,
 };


// Display string item
code UCHAR EN_AutoAdjustmentStr1[] = {15, 'A', 'u', 't', 'o', ' ', 'A', 'd', 'j', 'u', 's', 't', 'm', 'e', 'n', 't', };
code UCHAR FR_AutoAdjustmentStr1[] = {15, 'A', 'j', 'u', 's', 't', 'e', 'm', 'e', 'n', 't', ' ', 'a', 'u', 't', 'o', };
code UCHAR GE_AutoAdjustmentStr1[] = {11, 'A', 'u', 't', 'o', '-', 'E', 'i', 'n', 's', 't', '.', };
code UCHAR IT_AutoAdjustmentStr1[] = {14, 'R', 'e', 'g', ' ', 'a', 'u', 't', 'o', 'm', 'a', 't', 'i', 'c', 'a', };
code UCHAR SP_AutoAdjustmentStr1[] = {17, 'A', 'j', 'u', 's', 't', 'e', ' ', 'a', 'u', 't', 'o', 'm', 0, 't', 'i', 'c', 'o', };
code UCHAR PO_AutoAdjustmentStr1[] = {18, 'A', 'u', 't', 'o', '.', ' ', 'd', 'o', 's', 't', 'o', 's', 'o', 'w', 'a', 'n', 'i', 'e', };
code UCHAR CZ_AutoAdjustmentStr1[] = {16, 'A', 'u', 't', 'o', 'm', '.', ' ', 'n', 'a', 's', 't', 'a', 'v', 'e', 'n', 1, };
code UCHAR MA_AutoAdjustmentStr1[] = {17, 'A', 'u', 't', 'o', '.', ' ', 'B', 'e', 0, 'l', 'l', 1, 't', 0, 's', ' ', 5, };
code UCHAR SE_AutoAdjustmentStr1[] = {16, 'A', 'u', 't', 'o', 'm', '.', ' ', 'p', 'o', 'd', 'e', 20, 'a', 'v', '.', 5, };
code UCHAR RO_AutoAdjustmentStr1[] = {14, 'R', 'e', 'g', 'l', 'a', 'r', 'e', ' ', 'a', 'u', 't', 'o', 'm', '.', };
code UCHAR DU_AutoAdjustmentStr1[] = {15, 'A', 'u', 't', 'o', '-', 'a', 'a', 'n', 'p', 'a', 's', 's', 'i', 'n', 'g', };
code UCHAR RU_AutoAdjustmentStr1[] = {14, 130, 131, 132, '.', ' ', 133, 128, 134, 135, 127, 124, 133, '.', 5, };
code UCHAR SW_AutoAdjustmentStr1[] = {13, 'A', 'u', 't', 'o', 'j', 'u', 's', 't', 'e', 'r', 'i', 'n', 'g', };
code UCHAR PR_AutoAdjustmentStr1[] = {13, 'A', 'j', 'u', 's', 't', 'e', ' ', 'a', 'u', 't', 'o', '.', 5, };
code UCHAR JA_AutoAdjustmentStr1[] = {4, 2, 3, 4, 5, };
code UCHAR CT_AutoAdjustmentStr1[] = {4, 2, 3, 4, 5, };
code UCHAR CS_AutoAdjustmentStr1[] = {4, 2, 3, 4, 5, };

#if ENABLE_AUTO_POVIT_FUNC == ON  
code UCHAR EN_AutoPivotStr1[]={10, 'A', 'u', 't', 'o', ' ', 'P', 'i', 'v', 'o', 't', };
code UCHAR FR_AutoPivotStr1[]={13, 'R', 'o', 't', 'a', 't', 'i', 'o', 'n', ' ', 'a', 'u', 't', 'o', };
code UCHAR GE_AutoPivotStr1[]={14, 'A', 'u', 't', 'o', 'm', '.', ' ', 'D', 'r', 'e', 'h', 'u', 'n', 'g', };
code UCHAR IT_AutoPivotStr1[]={20, 'R', 'o', 't', 'a', 'z', 'i', 'o', 'n', 'e', ' ', 'a', 'u', 't', 'o', 'm', 'a', 't', 'i', 'c', 'a', };
code UCHAR SP_AutoPivotStr1[]={19, 'R', 'o', 't', 'a', 'c', 'i', 4, 'n', ' ', 'a', 'u', 't', 'o', 'm', 0, 't', 'i', 'c', 'a', };
code UCHAR PO_AutoPivotStr1[]={15, 'A', 'u', 't', 'o', '.', ' ', 'O', 'b', 'r', 'a', 'c', 'a', 'n', 'i', 'e', };
code UCHAR CZ_AutoPivotStr1[]={14, 'A', 'u', 't', 'o', 'm', '.', ' ', 'O', 't', 'o', 6, 'e', 'n', 1, };
code UCHAR MA_AutoPivotStr1[]={16, 'A', 'u', 't', 'o', '.', ' ', 'E', 'l', 'f', 'o', 'r', 'g', 'a', 't', 0, 's', };
code UCHAR SE_AutoPivotStr1[]={14, 'A', 'u', 't', '.', ' ', 'o', 'k', 'r', 'e', 't', 'a', 'n', 'j', 'e', };
code UCHAR RO_AutoPivotStr1[]={15, 'P', 'i', 'v', 'o', 't', 'a', 'r', 'e', ' ', 'a', 'u', 't', 'o', 'm', '.', };
code UCHAR DU_AutoPivotStr1[]={12, 'A', 'u', 't', 'o', '-', 'd', 'r', 'a', 'a', 'i', 'e', 'n', };
code UCHAR RU_AutoPivotStr1[]={11, 130, 131, 132, 136, 126, 136, 131, 136, 133, 136, 132, };
code UCHAR SW_AutoPivotStr1[]={17, 'S', 'v', 3, 'n', 'g', ' ', 'a', 'u', 't', 'o', 'm', 'a', 't', 'i', 's', 'k', 't', };
code UCHAR PR_AutoPivotStr1[]={20, 'B', 'a', 's', 'e', ' ', 'r', 'o', 't', 'a', 't', 'i', 'v', 'a', ' ', 'a', 'u', 't', 'o', 'm', '.', };
code UCHAR JA_AutoPivotStr1[]={4, 2, 3, 6, 7, };
code UCHAR CT_AutoPivotStr1[]={4, 2, 3, 6, 7, };
code UCHAR CS_AutoPivotStr1[]={4, 2, 3, 6, 7, };
#endif

code UCHAR EN_InputStr1[] = {5, 'I', 'n', 'p', 'u', 't', };
code UCHAR FR_InputStr1[] = {6, 'E', 'n', 't', 'r', 2, 'e', };
code UCHAR GE_InputStr1[] = {7, 'E', 'i', 'n', 'g', 'a', 'b', 'e', };
code UCHAR IT_InputStr1[] = {5, 'I', 'n', 'p', 'u', 't', };
code UCHAR SP_InputStr1[] = {7, 'E', 'n', 't', 'r', 'a', 'd', 'a', };
code UCHAR PO_InputStr1[] = {7, 'W', 'e', 'j', 123, 'c', 'i', 'e', };
code UCHAR CZ_InputStr1[] = {5, 'V', 's', 't', 'u', 'p', };
code UCHAR MA_InputStr1[] = {7, 'B', 'e', 'm', 'e', 'n', 'e', 't', };
code UCHAR SE_InputStr1[] = {4, 'U', 'l', 'a', 'z', };
code UCHAR RO_InputStr1[] = {7, 'I', 'n', 't', 'r', 'a', 'r', 'e', };
code UCHAR DU_InputStr1[] = {5, 'I', 'n', 'p', 'u', 't', };
code UCHAR RU_InputStr1[] = {4, 137, 138, 136, 139, };
code UCHAR SW_InputStr1[] = {6, 'I', 'n', 'g', 123, 'n', 'g', };
code UCHAR PR_InputStr1[] = {7, 'E', 'n', 't', 'r', 'a', 'd', 'a', };
code UCHAR JA_InputStr1[] = {2, 8, 9, };
code UCHAR CT_InputStr1[] = {2, 8, 9, };
code UCHAR CS_InputStr1[] = {2, 8, 9, };

code UCHAR EN_HPositionStr1[] = {11, 'H', '.', ' ', 'P', 'o', 's', 'i', 't', 'i', 'o', 'n', };
code UCHAR FR_HPositionStr1[] = {11, 'P', 'o', 's', 'i', 't', 'i', 'o', 'n', ' ', 'H', '.', };
code UCHAR GE_HPositionStr1[] = {11, 'H', '.', ' ', 'P', 'o', 's', 'i', 't', 'i', 'o', 'n', };
code UCHAR IT_HPositionStr1[] = {12, 'P', 'o', 's', 'i', 'z', 'i', 'o', 'n', 'e', ' ', 'O', '.', };
code UCHAR SP_HPositionStr1[] = {11, 'P', 'o', 's', 'i', 'c', 'i', 4, 'n', ' ', 'H', '.', };
code UCHAR PO_HPositionStr1[] = {13, 'U', 's', 't', 'a', 'w', '.', ' ', 'p', 'o', 'z', '.', ' ', 5, };
code UCHAR CZ_HPositionStr1[] = {13, 'P', 'o', 'z', 'i', 'c', 'e', ' ', 'v', 'o', 'd', 'o', 'r', '.', };
code UCHAR MA_HPositionStr1[] = {12, 'V', '.', ' ', 'p', 'o', 'z', 1, 'c', 'i', 4, ' ', 5, };
code UCHAR SE_HPositionStr1[] = {13, 'H', 'o', 'r', 'i', 'z', '.', ' ', 'p', 'o', 'z', '.', ' ', 5, };
code UCHAR RO_HPositionStr1[] = {10, 'P', 'o', 'z', 'i', 124, 'i', 'e', ' ', 'o', '.', };
code UCHAR DU_HPositionStr1[] = {12, 'H', '.', ' ', 'p', 'o', 's', 'i', 't', 'i', 'e', ' ', 5, };
code UCHAR RU_HPositionStr1[] = {10, 140, 136, 133, '.', ' ', 126, 136, 141, '.', 5, };
code UCHAR SW_HPositionStr1[] = {11, 'H', '.', ' ', 'P', 'o', 's', 'i', 't', 'i', 'o', 'n', };
code UCHAR PR_HPositionStr1[] = {10, 'P', 'o', 's', 'i', 7, 123, 'o', ' ', 'H', '.', };
code UCHAR JA_HPositionStr1[] = {4, 10, 11, 12, 13, };
code UCHAR CT_HPositionStr1[] = {4, 10, 11, 12, 13, };
code UCHAR CS_HPositionStr1[] = {4, 10, 11, 12, 13, };


code UCHAR EN_VPositionStr1[] = {11, 'V', '.', ' ', 'P', 'o', 's', 'i', 't', 'i', 'o', 'n', };
code UCHAR FR_VPositionStr1[] = {11, 'P', 'o', 's', 'i', 't', 'i', 'o', 'n', ' ', 'V', '.', };
code UCHAR GE_VPositionStr1[] = {11, 'V', '.', ' ', 'P', 'o', 's', 'i', 't', 'i', 'o', 'n', };
code UCHAR IT_VPositionStr1[] = {12, 'P', 'o', 's', 'i', 'z', 'i', 'o', 'n', 'e', ' ', 'V', '.', };
code UCHAR SP_VPositionStr1[] = {11, 'P', 'o', 's', 'i', 'c', 'i', 4, 'n', ' ', 'V', '.', };
code UCHAR PO_VPositionStr1[] = {13, 'U', 's', 't', 'a', 'w', '.', ' ', 'p', 'i', 'o', 'n', '.', 5, };
code UCHAR CZ_VPositionStr1[] = {13, 'P', 'o', 'z', 'i', 'c', 'e', ' ', 's', 'v', 'i', 's', 'l', '.', };
code UCHAR MA_VPositionStr1[] = {11, 'F', '.', ' ', 'p', 'o', 'z', 1, 'c', 'i', 4, 5, };
code UCHAR SE_VPositionStr1[] = {11, 'V', 'e', 'r', 't', '.', ' ', 'p', 'o', 'z', '.', 5, };
code UCHAR RO_VPositionStr1[] = {10, 'P', 'o', 'z', 'i', 124, 'i', 'e', ' ', 'v', '.', };
code UCHAR DU_VPositionStr1[] = {11, 'V', '.', ' ', 'p', 'o', 's', 'i', 't', 'i', 'e', 5, };
code UCHAR RU_VPositionStr1[] = {11, 137, 128, 133, 132, '.', ' ', 126, 136, 141, '.', 5, };
code UCHAR SW_VPositionStr1[] = {11, 'V', '.', ' ', 'P', 'o', 's', 'i', 't', 'i', 'o', 'n', };
code UCHAR PR_VPositionStr1[] = {10, 'P', 'o', 's', 'i', 7, 123, 'o', ' ', 'V', '.', };
code UCHAR JA_VPositionStr1[] = {4, 14, 15, 12, 13, };
code UCHAR CT_VPositionStr1[] = {4, 14, 15, 12, 13, };
code UCHAR CS_VPositionStr1[] = {4, 14, 15, 12, 13, };


code UCHAR EN_PixelClockStr1[] = {11, 'P', 'i', 'x', 'e', 'l', ' ', 'C', 'l', 'o', 'c', 'k', };
code UCHAR FR_PixelClockStr1[] = {13, 'H', 'o', 'r', 'l', 'o', 'g', 'e', ' ', 'P', 'i', 'x', 'e', 'l', };
code UCHAR GE_PixelClockStr1[] = {8, 'P', 'i', 'x', 'e', 'l', 'u', 'h', 'r', };
code UCHAR IT_PixelClockStr1[] = {11, 'P', 'i', 'x', 'e', 'l', ' ', 'C', 'l', 'o', 'c', 'k', };
code UCHAR SP_PixelClockStr1[] = {14, 'R', 'e', 'l', 'o', 'j', ' ', 'd', 'e', ' ', 'P', 1, 'x', 'e', 'l', };
code UCHAR PO_PixelClockStr1[] = {12, 'S', 'z', 'e', 'r', '.', ' ', 'P', 'a', 's', 'm', 'a', ' ', };
code UCHAR CZ_PixelClockStr1[] = {12, 123, 1, 124, 'k', 'a', ' ', 'p', 0, 's', 'm', 'a', 5, };
code UCHAR MA_PixelClockStr1[] = {12, 'P', 'o', 'n', 't', 'f', 'r', 'e', 'k', 'v', '.', ' ', 5, };
code UCHAR SE_PixelClockStr1[] = {13, 'P', 'i', 'x', 'e', 'l', ' ', 'C', 'l', 'o', 'c', 'k', ' ', 5, };
code UCHAR RO_PixelClockStr1[] = {10, 'T', 'a', 'c', 't', ' ', 'p', 'i', 'x', 'e', 'l', };
code UCHAR DU_PixelClockStr1[] = {10, 'P', 'i', 'x', 'e', 'l', 'k', 'l', 'o', 'k', 5, };
code UCHAR RU_PixelClockStr1[] = {11, 142, 143, 125, 132, '.', 125, 124, 144, 138, 133, '.', };
code UCHAR SW_PixelClockStr1[] = {11, 'P', 'i', 'x', 'e', 'l', 'k', 'l', 'o', 'c', 'k', 'a', };
code UCHAR PR_PixelClockStr1[] = {17, 'R', 'e', 'l', 4, 'g', 'i', 'o', ' ', 'd', 'e', ' ', 'p', 'i', 'x', 2, 'i', 's', };
code UCHAR JA_PixelClockStr1[] = {3, 16, 17, 18, };
code UCHAR CT_PixelClockStr1[] = {4, 16, 17, 18, 19, };
code UCHAR CS_PixelClockStr1[] = {4, 16, 17, 18, 19, };

code UCHAR EN_PhaseStr1[] = {5, 'P', 'h', 'a', 's', 'e', };
code UCHAR FR_PhaseStr1[] = {5, 'P', 'h', 'a', 's', 'e', };
code UCHAR GE_PhaseStr1[] = {5, 'P', 'h', 'a', 's', 'e', };
code UCHAR IT_PhaseStr1[] = {4, 'F', 'a', 's', 'e', };
code UCHAR SP_PhaseStr1[] = {4, 'F', 'a', 's', 'e', };
code UCHAR PO_PhaseStr1[] = {4, 'F', 'a', 'z', 'a', };
code UCHAR CZ_PhaseStr1[] = {4, 'F', 0, 'z', 'e', };
code UCHAR MA_PhaseStr1[] = {5, 'F', 0, 'z', 'i', 's', };
code UCHAR SE_PhaseStr1[] = {4, 'F', 'a', 'z', 'a', };
code UCHAR RO_PhaseStr1[] = {4, 'F', 'a', 'z', 'a', };
code UCHAR DU_PhaseStr1[] = {5, 'F', 'a', 's', 'e', ' ', };
code UCHAR RU_PhaseStr1[] = {4, 145, 143, 141, 143, };
code UCHAR SW_PhaseStr1[] = {7, 'F', 'a', 's', 'n', 'i', 'n', 'g', };
code UCHAR PR_PhaseStr1[] = {4, 'F', 'a', 's', 'e', };
code UCHAR JA_PhaseStr1[] = {4, 19, 20, 21, 22, };
code UCHAR CT_PhaseStr1[] = {4, 20, 12, 4, 5, };
code UCHAR CS_PhaseStr1[] = {4, 20, 12, 4, 5, };

 code UCHAR *DisplayTab[] = {

     EN_AutoAdjustmentStr1,
     FR_AutoAdjustmentStr1,
     GE_AutoAdjustmentStr1,
     IT_AutoAdjustmentStr1,
     SP_AutoAdjustmentStr1,
     PO_AutoAdjustmentStr1,
     CZ_AutoAdjustmentStr1,
     MA_AutoAdjustmentStr1,
     SE_AutoAdjustmentStr1,
     RO_AutoAdjustmentStr1,
     DU_AutoAdjustmentStr1,
     RU_AutoAdjustmentStr1,
     SW_AutoAdjustmentStr1,
     PR_AutoAdjustmentStr1,
     JA_AutoAdjustmentStr1,
     CT_AutoAdjustmentStr1,
     CS_AutoAdjustmentStr1,

#if ENABLE_AUTO_POVIT_FUNC == ON//ULEric140327
     EN_AutoPivotStr1,
     FR_AutoPivotStr1,
     GE_AutoPivotStr1,
     IT_AutoPivotStr1,
     SP_AutoPivotStr1,
     PO_AutoPivotStr1,
     CZ_AutoPivotStr1,
     MA_AutoPivotStr1,
     SE_AutoPivotStr1,
     RO_AutoPivotStr1,
     DU_AutoPivotStr1,
     RU_AutoPivotStr1,
     SW_AutoPivotStr1,
     PR_AutoPivotStr1,
     JA_AutoPivotStr1,
     CT_AutoPivotStr1,
     CS_AutoPivotStr1,
#endif
     
     EN_InputStr1,
     FR_InputStr1,
     GE_InputStr1,
     IT_InputStr1,
     SP_InputStr1,
     PO_InputStr1,
     CZ_InputStr1,
     MA_InputStr1,
     SE_InputStr1,
     RO_InputStr1,
     DU_InputStr1,
     RU_InputStr1,
     SW_InputStr1,
     PR_InputStr1,
     JA_InputStr1,
     CT_InputStr1,
     CS_InputStr1,
     
     EN_HPositionStr1,
     FR_HPositionStr1,
     GE_HPositionStr1,
     IT_HPositionStr1,
     SP_HPositionStr1,
     PO_HPositionStr1,
     CZ_HPositionStr1,
     MA_HPositionStr1,
     SE_HPositionStr1,
     RO_HPositionStr1,
     DU_HPositionStr1,
     RU_HPositionStr1,
     SW_HPositionStr1,
     PR_HPositionStr1,
     JA_HPositionStr1,
     CT_HPositionStr1,
     CS_HPositionStr1,
     
     EN_VPositionStr1,
     FR_VPositionStr1,
     GE_VPositionStr1,
     IT_VPositionStr1,
     SP_VPositionStr1,
     PO_VPositionStr1,
     CZ_VPositionStr1,
     MA_VPositionStr1,
     SE_VPositionStr1,
     RO_VPositionStr1,
     DU_VPositionStr1,
     RU_VPositionStr1,
     SW_VPositionStr1,
     PR_VPositionStr1,
     JA_VPositionStr1,
     CT_VPositionStr1,
     CS_VPositionStr1,

     EN_PixelClockStr1,
     FR_PixelClockStr1,
     GE_PixelClockStr1,
     IT_PixelClockStr1,
     SP_PixelClockStr1,
     PO_PixelClockStr1,
     CZ_PixelClockStr1,
     MA_PixelClockStr1,
     SE_PixelClockStr1,
     RO_PixelClockStr1,
     DU_PixelClockStr1,
     RU_PixelClockStr1,
     SW_PixelClockStr1,
     PR_PixelClockStr1,
     JA_PixelClockStr1,
     CT_PixelClockStr1,
     CS_PixelClockStr1,

     EN_PhaseStr1,
     FR_PhaseStr1,
     GE_PhaseStr1,
     IT_PhaseStr1,
     SP_PhaseStr1,
     PO_PhaseStr1,
     CZ_PhaseStr1,
     MA_PhaseStr1,
     SE_PhaseStr1,
     RO_PhaseStr1,
     DU_PhaseStr1,
     RU_PhaseStr1,
     SW_PhaseStr1,
     PR_PhaseStr1,
     JA_PhaseStr1,
     CT_PhaseStr1,
     CS_PhaseStr1,
};


// Picture string item
code UCHAR EN_BrightnessStr1[] = {10, 'B', 'r', 'i', 'g', 'h', 't', 'n', 'e', 's', 's', };
code UCHAR FR_BrightnessStr1[] = {11, 'L', 'u', 'm', 'i', 'n', 'o', 's', 'i', 't', 2, 5, };
code UCHAR GE_BrightnessStr1[] = {10, 'H', 'e', 'l', 'l', 'i', 'g', 'k', 'e', 'i', 't', };
code UCHAR IT_BrightnessStr1[] = {10, 'L', 'u', 'm', 'i', 'n', 'o', 's', 'i', 't', 123, };
code UCHAR SP_BrightnessStr1[] = {6, 'B', 'r', 'i', 'l', 'l', 'o', };
code UCHAR PO_BrightnessStr1[] = {7, 'J', 'a', 's', 'n', 'o', 123, 22, };
code UCHAR CZ_BrightnessStr1[] = {3, 'J', 'a', 's', };
code UCHAR MA_BrightnessStr1[] = {7, 'F', 2, 'n', 'y', 'e', 'r', 123, };
code UCHAR SE_BrightnessStr1[] = {19, 'J', 'a', 6, 'i', 'n', 'a', ' ', 'o', 's', 'v', 'j', 'e', 't', 'l', 'j', 'e', 'n', 'j', 'a', };
code UCHAR RO_BrightnessStr1[] = {12, 'L', 'u', 'm', 'i', 'n', 'o', 'z', 'i', 't', 'a', 't', 'e', };
code UCHAR DU_BrightnessStr1[] = {10, 'H', 'e', 'l', 'd', 'e', 'r', 'h', 'e', 'i', 'd', };
code UCHAR RU_BrightnessStr1[] = {7, 154, 133, 148, 136, 125, 132, 155, };
code UCHAR SW_BrightnessStr1[] = {10, 'L', 'j', 'u', 's', 's', 't', 'y', 'r', 'k', 'a', };
code UCHAR PR_BrightnessStr1[] = {6, 'B', 'r', 'i', 'l', 'h', 'o', };
code UCHAR JA_BrightnessStr1[] = {2, 123, 124, };
code UCHAR CT_BrightnessStr1[] = {2, 27, 28, };
code UCHAR CS_BrightnessStr1[] = {2, 27, 28, };

code UCHAR EN_ContrastStr1[]={8, 'C', 'o', 'n', 't', 'r', 'a', 's', 't', };
code UCHAR FR_ContrastStr1[]={9, 'C', 'o', 'n', 't', 'r', 'a', 's', 't', 'e', };
code UCHAR GE_ContrastStr1[]={8, 'K', 'o', 'n', 't', 'r', 'a', 's', 't', };
code UCHAR IT_ContrastStr1[]={9, 'C', 'o', 'n', 't', 'r', 'a', 's', 't', 'o', };
code UCHAR SP_ContrastStr1[]={9, 'C', 'o', 'n', 't', 'r', 'a', 's', 't', 'e', };
code UCHAR PO_ContrastStr1[]={8, 'K', 'o', 'n', 't', 'r', 'a', 's', 't', };
code UCHAR CZ_ContrastStr1[]={8, 'K', 'o', 'n', 't', 'r', 'a', 's', 't', };
code UCHAR MA_ContrastStr1[]={9, 'K', 'o', 'n', 't', 'r', 'a', 's', 'z', 't', };
code UCHAR SE_ContrastStr1[]={8, 'K', 'o', 'n', 't', 'r', 'a', 's', 't', };
code UCHAR RO_ContrastStr1[]={8, 'C', 'o', 'n', 't', 'r', 'a', 's', 't', };
code UCHAR DU_ContrastStr1[]={8, 'C', 'o', 'n', 't', 'r', 'a', 's', 't', };
code UCHAR RU_ContrastStr1[]={8, 153, 136, 144, 132, 133, 143, 125, 132, };
code UCHAR SW_ContrastStr1[]={8, 'K', 'o', 'n', 't', 'r', 'a', 's', 't', };
code UCHAR PR_ContrastStr1[]={9, 'C', 'o', 'n', 't', 'r', 'a', 's', 't', 'e', };
code UCHAR JA_ContrastStr1[]={6, 27, 28, 29, 30, 31, 29, };
code UCHAR CT_ContrastStr1[]={2, 25, 26, };
code UCHAR CS_ContrastStr1[]={2, 25, 26, };
 
code UCHAR EN_SharpnessStr1[] = {9, 'S', 'h', 'a', 'r', 'p', 'n', 'e', 's', 's', };
code UCHAR FR_SharpnessStr1[] = {7, 'F', 'i', 'n', 'e', 's', 's', 'e', };
code UCHAR GE_SharpnessStr1[] = {7, 'S', 'c', 'h', 3, 'r', 'f', 'e', };
code UCHAR IT_SharpnessStr1[] = {9, 'N', 'i', 't', 'i', 'd', 'e', 'z', 'z', 'a', };
code UCHAR SP_SharpnessStr1[] = {7, 'N', 'i', 't', 'i', 'd', 'e', 'z', };
code UCHAR PO_SharpnessStr1[] = {7, 'O', 's', 't', 'r', 'o', 123, 22, };
code UCHAR CZ_SharpnessStr1[] = {7, 'O', 's', 't', 'r', 'o', 's', 't', };
code UCHAR MA_SharpnessStr1[] = {7, 24, 'l', 'e', 's', 's', 2, 'g', };
code UCHAR SE_SharpnessStr1[] = {7, 'o', 20, 't', 'r', 'i', 'n', 'a', };
code UCHAR RO_SharpnessStr1[] = {10, 'C', 'l', 'a', 'r', 'i', 't', 'a', 't', 'e', 5, };
code UCHAR DU_SharpnessStr1[] = {8, 'S', 'c', 'h', 'e', 'r', 'p', 't', 'e', };
code UCHAR RU_SharpnessStr1[] = {8, 156, 128, 141, 148, 136, 125, 132, 155, };
code UCHAR SW_SharpnessStr1[] = {7, 'S', 'k', 3, 'r', 'p', 'a', ' ', };
code UCHAR PR_SharpnessStr1[] = {7, 'N', 'i', 't', 'i', 'd', 'e', 'z', };
code UCHAR JA_SharpnessStr1[] = {6, 125, 126, 21, 127, 128, 31, };
code UCHAR CT_SharpnessStr1[] = {3, 29, 30, 28, };
code UCHAR CS_SharpnessStr1[] = {3, 29, 30, 28, };

code UCHAR EN_GammaStr1[]={5, 'G', 'a', 'm', 'm', 'a', };
code UCHAR FR_GammaStr1[]={5, 'G', 'a', 'm', 'm', 'a', };
code UCHAR GE_GammaStr1[]={5, 'G', 'a', 'm', 'm', 'a', };
code UCHAR IT_GammaStr1[]={5, 'G', 'a', 'm', 'm', 'a', };
code UCHAR SP_GammaStr1[]={5, 'G', 'a', 'm', 'm', 'a', };
code UCHAR PO_GammaStr1[]={5, 'G', 'a', 'm', 'm', 'a', };
code UCHAR CZ_GammaStr1[]={5, 'G', 'a', 'm', 'm', 'a', };
code UCHAR MA_GammaStr1[]={5, 'G', 'a', 'm', 'm', 'a', };
code UCHAR SE_GammaStr1[]={4, 'G', 'a', 'm', 'a', };
code UCHAR RO_GammaStr1[]={5, 'G', 'a', 'm', 'm', 'a', };
code UCHAR DU_GammaStr1[]={5, 'G', 'a', 'm', 'm', 'a', };
code UCHAR RU_GammaStr1[]={5, 140, 143, 146, 146, 143, };
code UCHAR SW_GammaStr1[]={5, 'G', 'a', 'm', 'm', 'a', };
code UCHAR PR_GammaStr1[]={5, 'G', 'a', 'm', 'm', 'a', };
code UCHAR JA_GammaStr1[]={3, 129, 28, 130, };
code UCHAR CT_GammaStr1[]={5, 'G', 'a', 'm', 'm', 'a', };
code UCHAR CS_GammaStr1[]={2, 31, 28, };

code UCHAR EN_ColorTempStr1[]={17, 'C', 'o', 'l', 'o', 'r', ' ', 'T', 'e', 'm', 'p', 'e', 'r', 'a', 't', 'u', 'r', 'e', };
code UCHAR FR_ColorTempStr1[]={13, 'T', 'e', 'm', 'p', '.', ' ', 'c', 'o', 'u', 'l', 'e', 'u', 'r', };
code UCHAR GE_ColorTempStr1[]={14, 'F', 'a', 'r', 'b', 't', 'e', 'm', 'p', 'e', 'r', 'a', 't', 'u', 'r', };
code UCHAR IT_ColorTempStr1[]={11, 'T', 'e', 'm', 'p', ' ', 'c', 'o', 'l', 'o', 'r', 'e', };
code UCHAR SP_ColorTempStr1[]={17, 'T', 'e', 'm', 'p', 'e', 'r', 'a', 't', 'u', 'r', 'a', ' ', 'c', 'o', 'l', 'o', 'r', };
code UCHAR PO_ColorTempStr1[]={13, 'T', 'e', 'm', 'p', '.', ' ', 'b', 'a', 'r', 'w', 'o', 'w', 'a', };
code UCHAR CZ_ColorTempStr1[]={13, 'T', 'e', 'p', 'l', 'o', 't', 'a', ' ', 'b', 'a', 'r', 'e', 'v', };
code UCHAR MA_ColorTempStr1[]={16, 'S', 'z', 1, 'n', 'h', 123, 'm', 2, 'r', 's', 2, 'k', 'l', 'e', 't', 28, };
code UCHAR SE_ColorTempStr1[]={16, 'T', 'e', 'm', 'p', 'e', 'r', 'a', 't', 'u', 'r', 'a', ' ', 'b', 'o', 'j', 'e', };
code UCHAR RO_ColorTempStr1[]={19, 'T', 'e', 'm', 'p', 'e', 'r', 'a', 't', 'u', 'r', 125, ' ', 'c', 'u', 'l', 'o', 'a', 'r', 'e', };
code UCHAR DU_ColorTempStr1[]={16, 'K', 'l', 'e', 'u', 'r', 't', 'e', 'm', 'p', 'e', 'r', 'a', 't', 'u', 'u', 'r', };
code UCHAR RU_ColorTempStr1[]={13, 157, 131, 128, 132, '.', ' ', 132, 128, 146, 126, '-', 133, 143, };
code UCHAR SW_ColorTempStr1[]={14, 'F', 3, 'r', 'g', 't', 'e', 'm', 'p', 'e', 'r', 'a', 't', 'u', 'r', };
code UCHAR PR_ColorTempStr1[]={18, 'T', 'e', 'm', 'p', 'e', 'r', 'a', 't', 'u', 'r', 'a', ' ', 'd', 'a', ' ', 'c', 'o', 'r', };
code UCHAR JA_ColorTempStr1[]={3, 131, 132, 124, };
code UCHAR CT_ColorTempStr1[]={2, 31, 123, };
code UCHAR CS_ColorTempStr1[]={2, 123, 124, };

code UCHAR EN_HueStr1[] = {3, 'H', 'u', 'e', };
code UCHAR FR_HueStr1[] = {6, 'T', 'e', 'i', 'n', 't', 'e', };
code UCHAR GE_HueStr1[] = {7, 'F', 'a', 'r', 'b', 't', 'o', 'n', };
code UCHAR IT_HueStr1[] = {8, 'T', 'o', 'n', 'a', 'l', 'i', 't', 123, };
code UCHAR SP_HueStr1[] = {5, 'M', 'a', 't', 'i', 'z', };
code UCHAR PO_HueStr1[] = {5, 'B', 'a', 'r', 'w', 'a', };
code UCHAR CZ_HueStr1[] = {6, 'O', 'd', 's', 't', 1, 'n', };
code UCHAR MA_HueStr1[] = {12, 'S', 'z', 1, 'n', 0, 'r', 'n', 'y', 'a', 'l', 'a', 't', };
code UCHAR SE_HueStr1[] = {11, 'B', 'a', 'l', 'a', 'n', 's', ' ', 'b', 'o', 'j', 'a', };
code UCHAR RO_HueStr1[] = {11, 'T', 'o', 'n', ' ', 'c', 'u', 'l', 'o', 'a', 'r', 'e', };
code UCHAR DU_HueStr1[] = {11, 'K', 'l', 'e', 'u', 'r', 't', 'i', 'n', 't', 'e', 'n', };
code UCHAR RU_HueStr1[] = {7, 162, 132, 132, 128, 144, 136, 148, };
code UCHAR SW_HueStr1[] = {7, 'F', 3, 'r', 'g', 't', 'o', 'n', };
code UCHAR PR_HueStr1[] = {10, 'T', 'o', 'n', 'a', 'l', 'i', 'd', 'a', 'd', 'e', };
code UCHAR JA_HueStr1[] = {2, 131, 143, };
code UCHAR CT_HueStr1[] = {2, 31, 28, };
code UCHAR CS_HueStr1[] = {2, 123, 28, };

code UCHAR EN_SaturationStr1[]= {10, 'S', 'a', 't', 'u', 'r', 'a', 't', 'i', 'o', 'n', };
code UCHAR FR_SaturationStr1[]= {10, 'S', 'a', 't', 'u', 'r', 'a', 't', 'i', 'o', 'n', };
code UCHAR GE_SaturationStr1[]= {9, 'S', 3, 't', 't', 'i', 'g', 'u', 'n', 'g', };
code UCHAR IT_SaturationStr1[]= {11, 'S', 'a', 't', 'u', 'r', 'a', 'z', 'i', 'o', 'n', 'e', };
code UCHAR SP_SaturationStr1[]= {10, 'S', 'a', 't', 'u', 'r', 'a', 'c', 'i', 4, 'n', };
code UCHAR PO_SaturationStr1[]= {9, 'S', 'a', 't', 'u', 'r', 'a', 'c', 'j', 'a', };
code UCHAR CZ_SaturationStr1[]= {6, 'S', 'y', 't', 'o', 's', 't', };
code UCHAR MA_SaturationStr1[]= {11, 'T', 'e', 'l', 1, 't', 'e', 't', 't', 's', 2, 'g', };
code UCHAR SE_SaturationStr1[]= {14, 'Z', 'a', 's', 'i', 22, 'e', 'n', 'j', 'e', ' ', 'b', 'o', 'j', 'e', };
code UCHAR RO_SaturationStr1[]= {8, 'S', 'a', 't', 'u', 'r', 'a', 'r', 'e', };
code UCHAR DU_SaturationStr1[]= {11, 'V', 'e', 'r', 'z', 'a', 'd', 'i', 'g', 'i', 'n', 'g', };
code UCHAR RU_SaturationStr1[]= {12, 158, 143, 125, 159, 163, 128, 144, 144, 136, 125, 132, 155, };
code UCHAR SW_SaturationStr1[]= {11, 'F', 3, 'r', 'g', 'm', 3, 't', 't', 'n', 'a', 'd', };
code UCHAR PR_SaturationStr1[]= {9, 'S', 'a', 't', 'u', 'r', 'a', 7, 123, 'o', };
code UCHAR JA_SaturationStr1[]= {2, 144, 124, };
code UCHAR CT_SaturationStr1[]= {2, 135, 28, };
code UCHAR CS_SaturationStr1[]= {2, 135, 28, };

code UCHAR EN_ResetColorStr1[] ={11, 'R', 'e', 's', 'e', 't', ' ', 'C', 'o', 'l', 'o', 'r', };
code UCHAR FR_ResetColorStr1[] ={15, 'R', 2, 'i', 'n', 'i', 't', '.', ' ', 'c', 'o', 'u', 'l', 'e', 'u', 'r', };
code UCHAR GE_ResetColorStr1[] ={14, 'F', 'a', 'r', 'b', 'e', ' ', 'z', 'u', 'r', 23, 'c', 'k', 's', '.', };
code UCHAR IT_ResetColorStr1[] ={12, 'R', 'e', 'i', 'm', 'p', ' ', 'c', 'o', 'l', 'o', 'r', 'e', };
code UCHAR SP_ResetColorStr1[] ={17, 'R', 'e', 's', 't', 'a', 'b', 'l', 'e', 'c', 'e', 'r', ' ', 'c', 'o', 'l', 'o', 'r', };
code UCHAR PO_ResetColorStr1[] ={18, 'R', 'e', 's', 'e', 't', 'o', 'w', 'a', 22, ' ', 'k', 'o', 'l', 'o', 'r', ' ', ' ', 5, };
code UCHAR CZ_ResetColorStr1[] ={13, 'O', 'b', 'n', 'o', 'v', 'i', 't', ' ', 'b', 'a', 'r', 'v', 'u', };
code UCHAR MA_ResetColorStr1[] ={16, 'S', 'z', 1, 'n', 'e', 'k', ' ', 'a', 'l', 'a', 'p', 'h', 'e', 'l', 'y', '.', };
code UCHAR SE_ResetColorStr1[] ={14, 'R', 'e', 's', 'e', 't', 'i', 'r', 'a', 'j', ' ', 'b', 'o', 'j', 'e', };
code UCHAR RO_ResetColorStr1[] ={14, 'R', 'e', 'i', 'n', 'i', 124, '.', ' ', 'c', 'u', 'l', 'o', 'r', 'i', };
code UCHAR DU_ResetColorStr1[] ={16, 'K', 'l', 'e', 'u', 'r', ' ', 'h', 'e', 'r', 's', 't', 'e', 'l', 'l', 'e', 'n', };
code UCHAR RU_ResetColorStr1[] ={13, 164, 151, 133, 136, 125, 124, 132, 155, ' ', 157, 131, 128, 132, };
code UCHAR SW_ResetColorStr1[] ={14, 124, 't', 'e', 'r', 's', 't', 3, 'l', 'l', ' ', 'f', 3, 'r', 'g', };
code UCHAR PR_ResetColorStr1[] ={13, 'R', 'e', 'd', 'e', 'f', 'i', 'n', 'i', 'r', ' ', 'c', 'o', 'r', };
code UCHAR JA_ResetColorStr1[] ={6, 131, 145, 146, 147, 148, 29, };
code UCHAR CT_ResetColorStr1[] ={4, 31, 135, 136, 137, };
code UCHAR CS_ResetColorStr1[] ={4, 123, 135, 136, 137, };

code UCHAR EN_AMAStr1[] = {3,"AMA"};
/*
code UCHAR FR_AMAStr1[] = {3,"AMA"};
code UCHAR GE_AMAStr1[] = {3,"AMA"};
code UCHAR IT_AMAStr1[] = {3,"AMA"};
code UCHAR SP_AMAStr1[] = {3,"AMA"};
code UCHAR PO_AMAStr1[] = {3,"AMA"};
code UCHAR CZ_AMAStr1[] = {3,"AMA"};
code UCHAR MA_AMAStr1[] = {3,"AMA"};
code UCHAR SE_AMAStr1[] = {3,"AMA"};
code UCHAR RO_AMAStr1[] = {3,"AMA"};
code UCHAR DU_AMAStr1[] = {3,"AMA"};
code UCHAR RU_AMAStr1[] = {3,"AMA"};
code UCHAR SW_AMAStr1[] = {3,"AMA"};
code UCHAR PR_AMAStr1[] = {3,"AMA"};
code UCHAR JA_AMAStr1[] = {3,"AMA"};
code UCHAR CT_AMAStr1[] = {3,"AMA"};
code UCHAR CS_AMAStr1[] = {3,"AMA"};
*/

code UCHAR *PictureTab[] = {
     EN_BrightnessStr1,
     FR_BrightnessStr1,
     GE_BrightnessStr1,
     IT_BrightnessStr1,
     SP_BrightnessStr1,
     PO_BrightnessStr1,
     CZ_BrightnessStr1,
     MA_BrightnessStr1,
     SE_BrightnessStr1,
     RO_BrightnessStr1,
     DU_BrightnessStr1,
     RU_BrightnessStr1,
     SW_BrightnessStr1,
     PR_BrightnessStr1,
     JA_BrightnessStr1,
     CT_BrightnessStr1,
     CS_BrightnessStr1,
     
     EN_ContrastStr1,
     FR_ContrastStr1,
     GE_ContrastStr1,
     IT_ContrastStr1,
     SP_ContrastStr1,
     PO_ContrastStr1,
     CZ_ContrastStr1,
     MA_ContrastStr1,
     SE_ContrastStr1,
     RO_ContrastStr1,
     DU_ContrastStr1,
     RU_ContrastStr1,
     SW_ContrastStr1,
     PR_ContrastStr1,
     JA_ContrastStr1,
     CT_ContrastStr1,
     CS_ContrastStr1,
     
     EN_SharpnessStr1,
     FR_SharpnessStr1,
     GE_SharpnessStr1,
     IT_SharpnessStr1,
     SP_SharpnessStr1,
     PO_SharpnessStr1,
     CZ_SharpnessStr1,
     MA_SharpnessStr1,
     SE_SharpnessStr1,
     RO_SharpnessStr1,
     DU_SharpnessStr1,
     RU_SharpnessStr1,
     SW_SharpnessStr1,
     PR_SharpnessStr1,
     JA_SharpnessStr1,
     CT_SharpnessStr1,
     CS_SharpnessStr1,
     
     
     EN_GammaStr1,
     FR_GammaStr1,
     GE_GammaStr1,
     IT_GammaStr1,
     SP_GammaStr1,
     PO_GammaStr1,
     CZ_GammaStr1,
     MA_GammaStr1,
     SE_GammaStr1,
     RO_GammaStr1,
     DU_GammaStr1,
     RU_GammaStr1,
     SW_GammaStr1,
     PR_GammaStr1,
     JA_GammaStr1,
     CT_GammaStr1,
     CS_GammaStr1,
     
     EN_ColorTempStr1,
     FR_ColorTempStr1,
     GE_ColorTempStr1,
     IT_ColorTempStr1,
     SP_ColorTempStr1,
     PO_ColorTempStr1,
     CZ_ColorTempStr1,
     MA_ColorTempStr1,
     SE_ColorTempStr1,
     RO_ColorTempStr1,
     DU_ColorTempStr1,
     RU_ColorTempStr1,
     SW_ColorTempStr1,
     PR_ColorTempStr1,
     JA_ColorTempStr1,
     CT_ColorTempStr1,
     CS_ColorTempStr1,
     
     EN_HueStr1,
     FR_HueStr1,
     GE_HueStr1,
     IT_HueStr1,
     SP_HueStr1,
     PO_HueStr1,
     CZ_HueStr1,
     MA_HueStr1,
     SE_HueStr1,
     RO_HueStr1,
     DU_HueStr1,
     RU_HueStr1,
     SW_HueStr1,
     PR_HueStr1,
     JA_HueStr1,
     CT_HueStr1,
     CS_HueStr1,
     
     EN_SaturationStr1,
     FR_SaturationStr1,
     GE_SaturationStr1,
     IT_SaturationStr1,
     SP_SaturationStr1,
     PO_SaturationStr1,
     CZ_SaturationStr1,
     MA_SaturationStr1,
     SE_SaturationStr1,
     RO_SaturationStr1,
     DU_SaturationStr1,
     RU_SaturationStr1,
     SW_SaturationStr1,
     PR_SaturationStr1,
     JA_SaturationStr1,
     CT_SaturationStr1,
     CS_SaturationStr1,
     
     EN_ResetColorStr1,
     FR_ResetColorStr1,
     GE_ResetColorStr1,
     IT_ResetColorStr1,
     SP_ResetColorStr1,
     PO_ResetColorStr1,
     CZ_ResetColorStr1,
     MA_ResetColorStr1,
     SE_ResetColorStr1,
     RO_ResetColorStr1,
     DU_ResetColorStr1,
     RU_ResetColorStr1,
     SW_ResetColorStr1,
     PR_ResetColorStr1,
     JA_ResetColorStr1,
     CT_ResetColorStr1,
     CS_ResetColorStr1,
     
     EN_AMAStr1,
     EN_AMAStr1,//FR
     EN_AMAStr1,//GE
     EN_AMAStr1,//IT
     EN_AMAStr1,//SP
     EN_AMAStr1,//PO
     EN_AMAStr1,//CZ
     EN_AMAStr1,//MA
     EN_AMAStr1,//SE
     EN_AMAStr1,//RO
     EN_AMAStr1,//DU
     EN_AMAStr1,//RU
     EN_AMAStr1,//SW
     EN_AMAStr1,//PR
     EN_AMAStr1,//JA
     EN_AMAStr1,//CT
     EN_AMAStr1,//CS
};

 code UCHAR EN_ResetColorConfirmStr1[]={13, 'R', 'e', 's', 'e', 't', ' ', 'C', 'o', 'l', 'o', 'r', ' ', '?', };
 code UCHAR FR_ResetColorConfirmStr1[]={17, 'R', 2, 'i', 'n', 'i', 't', '.', ' ', 'c', 'o', 'u', 'l', 'e', 'u', 'r', ' ', '?', };
 code UCHAR GE_ResetColorConfirmStr1[]={16, 'F', 'a', 'r', 'b', 'e', ' ', 'z', 'u', 'r', 23, 'c', 'k', 's', '.', ' ', '?', };
 code UCHAR IT_ResetColorConfirmStr1[]={14, 'R', 'e', 'i', 'm', 'p', ' ', 'c', 'o', 'l', 'o', 'r', 'e', ' ', '?', };
 code UCHAR SP_ResetColorConfirmStr1[]={21, 123, 'R', 'e', 's', 't', 'a', 'b', 'l', 'e', 'c', 'e', 'r', ' ', 'c', 'o', 'l', 'o', 'r', '?', ' ', 5, };
 code UCHAR PO_ResetColorConfirmStr1[]={19, 'R', 'e', 's', 'e', 't', 'o', 'w', 'a', 22, ' ', 'k', 'o', 'l', 'o', 'r', ' ', '?', ' ', 5, };
 code UCHAR CZ_ResetColorConfirmStr1[]={15, 'O', 'b', 'n', 'o', 'v', 'i', 't', ' ', 'b', 'a', 'r', 'v', 'u', ' ', '?', };
 code UCHAR MA_ResetColorConfirmStr1[]={18, 'S', 'z', 1, 'n', 'e', 'k', ' ', 'a', 'l', 'a', 'p', 'h', 'e', 'l', 'y', '.', ' ', '?', };
 code UCHAR SE_ResetColorConfirmStr1[]={16, 'R', 'e', 's', 'e', 't', 'i', 'r', 'a', 'j', ' ', 'b', 'o', 'j', 'e', ' ', '?', };
 code UCHAR RO_ResetColorConfirmStr1[]={16, 'R', 'e', 'i', 'n', 'i', 124, '.', ' ', 'c', 'u', 'l', 'o', 'r', 'i', ' ', '?', };
 code UCHAR DU_ResetColorConfirmStr1[]={18, 'K', 'l', 'e', 'u', 'r', ' ', 'h', 'e', 'r', 's', 't', 'e', 'l', 'l', 'e', 'n', ' ', '?', };
 code UCHAR RU_ResetColorConfirmStr1[]={14, 164, 151, 133, 136, 125, 124, 132, 155, ' ', 157, 131, 128, 132, '?', };
 code UCHAR SW_ResetColorConfirmStr1[]={16, 124, 't', 'e', 'r', 's', 't', 3, 'l', 'l', ' ', 'f', 3, 'r', 'g', ' ', '?', };
 code UCHAR PR_ResetColorConfirmStr1[]={14, 'R', 'e', 'd', 'e', 'f', 'i', 'n', 'i', 'r', ' ', 'c', 'o', 'r', '?', };
 code UCHAR JA_ResetColorConfirmStr1[]={8, 131, 145, 146, 147, 148, 29, ' ', '?', };
 code UCHAR CT_ResetColorConfirmStr1[]={6, 31, 135, 136, 137, ' ', '?', };
 code UCHAR CS_ResetColorConfirmStr1[]={6, 123, 135, 136, 137, ' ', '?', };



code UCHAR *ResetColorTab[] = {
     
     EN_ResetColorConfirmStr1,
     FR_ResetColorConfirmStr1,
     GE_ResetColorConfirmStr1,
     IT_ResetColorConfirmStr1,
     SP_ResetColorConfirmStr1,
     PO_ResetColorConfirmStr1,
     CZ_ResetColorConfirmStr1,
     MA_ResetColorConfirmStr1,
     SE_ResetColorConfirmStr1,
     RO_ResetColorConfirmStr1,
     DU_ResetColorConfirmStr1,
     RU_ResetColorConfirmStr1,
     SW_ResetColorConfirmStr1,
     PR_ResetColorConfirmStr1,
     JA_ResetColorConfirmStr1,
     CT_ResetColorConfirmStr1,
     CS_ResetColorConfirmStr1,
     
};
 code UCHAR EN_ResetAllConfirmStr1[]={20, 'R', 'e', 's', 'e', 't', ' ', 'A', 'l', 'l', ' ', 'S', 'e', 't', 't', 'i', 'n', 'g', 's', ' ', '?', };
 code UCHAR FR_ResetAllConfirmStr1[]={19, 'R', 2, 'i', 'n', 'i', 't', '.', ' ', 'T', 's', ' ', 'P', 'a', 'r', 'a', 'm', '.', ' ', '?', };
 code UCHAR GE_ResetAllConfirmStr1[]={20, 'A', 'l', 'l', 'e', ' ', 'E', 'i', 'n', 's', 't', '.', ' ', 'Z', 'u', 'r', 23, 'c', 'k', ' ', '?', };
 code UCHAR IT_ResetAllConfirmStr1[]={19, 'R', 'i', 'p', 'r', ' ', 't', 'u', 't', 't', 'e', ' ', 'l', 'e', ' ', 'i', 'm', 'p', ' ', '?', };
 code UCHAR SP_ResetAllConfirmStr1[]={21, 123, 'R', 'e', 's', 't', '.', ' ', 'T', 'o', 'd', 'a', ' ', 'C', 'o', 'n', 'f', 'i', 'g', '.', '?', 5, };
 code UCHAR PO_ResetAllConfirmStr1[]={25, 'R', 'e', 's', 'e', 't', '.', ' ', 'w', 's', 'z', 'y', 's', 't', 'k', 'i', 'e', ' ', 'u', 's', 't', 'a', 'w', '.', ' ', '?', };
 code UCHAR CZ_ResetAllConfirmStr1[]={19, 'O', 'b', 'n', 'o', 'v', 'i', 't', ' ', 'n', 'a', 's', 't', 'a', 'v', 'e', 'n', 1, ' ', '?', };
 code UCHAR MA_ResetAllConfirmStr1[]={24, 'B', 'e', 0, 'l', 'l', 1, 't', '.', ' ', 'a', 'l', 'a', 'p', 'h', 'e', 'l', 'y', 'z', 'e', 't', 'b', 'e', ' ', '?', };
 code UCHAR SE_ResetAllConfirmStr1[]={24, 'R', 'e', 's', 'e', 't', 'i', 'r', 'a', 'j', ' ', 's', 'v', 'e', ' ', 'p', 'o', 's', 't', 'a', 'v', 'k', 'e', ' ', '?', };
 code UCHAR RO_ResetAllConfirmStr1[]={24, 'R', 'e', 'i', 'n', 'i', 124, '.', ' ', 't', 'o', 'a', 't', 'e', ' ', 's', 'e', 't', 125, 'r', 'i', 'l', 'e', ' ', '?', };
 code UCHAR DU_ResetAllConfirmStr1[]={24, 'A', 'l', 'l', 'e', ' ', 'i', 'n', 's', 't', 'l', 'l', ' ', 'h', 'e', 'r', 's', 't', 'e', 'l', 'l', 'e', 'n', ' ', '?', };
 code UCHAR RU_ResetAllConfirmStr1[]={23, 164, 151, 133, 136, 125, 124, 132, 155, ' ', 131, 125, 128, ' ', 144, 143, 125, 132, 133, 136, 129, 148, 124, '?', };
 code UCHAR SW_ResetAllConfirmStr1[]={20, 124, 't', 'e', 'r', 's', 't', '.', ' ', 'a', 'l', 'l', 'a', ' ', 'i', 'n', 's', 't', '.', ' ', '?', };
 code UCHAR PR_ResetAllConfirmStr1[]={20, 'R', 'e', 'p', 'o', 'r', ' ', 't', 'o', 'd', 'a', 's', ' ', 'd', 'e', 'f', 'i', 'n', '.', '?', 5, };
 code UCHAR JA_ResetAllConfirmStr1[]={8, 187, 141, 142, 230, 211, 208, ' ', '?', };
 code UCHAR CT_ResetAllConfirmStr1[]={6, 181, 202, 136, 137, ' ', '?', };
 code UCHAR CS_ResetAllConfirmStr1[]={6, 180, 201, 136, 137, ' ', '?', };



code UCHAR *ResetAllTab[] = {
     
     EN_ResetAllConfirmStr1,
     FR_ResetAllConfirmStr1,
     GE_ResetAllConfirmStr1,
     IT_ResetAllConfirmStr1,
     SP_ResetAllConfirmStr1,
     PO_ResetAllConfirmStr1,
     CZ_ResetAllConfirmStr1,
     MA_ResetAllConfirmStr1,
     SE_ResetAllConfirmStr1,
     RO_ResetAllConfirmStr1,
     DU_ResetAllConfirmStr1,
     RU_ResetAllConfirmStr1,
     SW_ResetAllConfirmStr1,
     PR_ResetAllConfirmStr1,
     JA_ResetAllConfirmStr1,
     CT_ResetAllConfirmStr1,
     CS_ResetAllConfirmStr1,
     
};

// Picture Advanced string item
code UCHAR EN_PictureModeStr1[] = {12, 'P', 'i', 'c', 't', 'u', 'r', 'e', ' ', 'M', 'o', 'd', 'e', };
code UCHAR FR_PictureModeStr1[] = {12, 'M', 'o', 'd', 'e', ' ', 'd', 124, 'i', 'm', 'a', 'g', 'e', };
code UCHAR GE_PictureModeStr1[] = {9, 'B', 'i', 'l', 'd', 'm', 'o', 'd', 'u', 's', };
code UCHAR IT_PictureModeStr1[] = {12, 'M', 'o', 'd', ' ', 'I', 'm', 'm', 'a', 'g', 'i', 'n', 'e', };
code UCHAR SP_PictureModeStr1[] = {11, 'M', 'o', 'd', 'o', ' ', 'i', 'm', 'a', 'g', 'e', 'n', };
code UCHAR PO_PictureModeStr1[] = {11, 'T', 'r', 'y', 'b', ' ', 'o', 'b', 'r', 'a', 'z', 'u', };
code UCHAR CZ_PictureModeStr1[] = {12, 'R', 'e', 26, 'i', 'm', ' ', 'o', 'b', 'r', 'a', 'z', 'u', };
code UCHAR MA_PictureModeStr1[] = {6, 'K', 2, 'p', 'm', 4, 'd', };
code UCHAR SE_PictureModeStr1[] = {9, 'M', 'o', 'd', ' ', 's', 'l', 'i', 'k', 'e', };
code UCHAR RO_PictureModeStr1[] = {11, 'M', 'o', 'd', ' ', 'I', 'm', 'a', 'g', 'i', 'n', 'e', };
code UCHAR DU_PictureModeStr1[] = {10, 'B', 'e', 'e', 'l', 'd', 'm', 'o', 'd', 'u', 's', };
code UCHAR RU_PictureModeStr1[] = {12, 156, 128, 152, 124, 146, ' ', 124, 141, 136, 151, 133, '.', };
code UCHAR SW_PictureModeStr1[] = {8, 'B', 'i', 'l', 'd', 'l', 3, 'g', 'e', };
code UCHAR PR_PictureModeStr1[] = {11, 'M', 'o', 'd', 'o', ' ', 'i', 'm', 'a', 'g', 'e', 'm', };
code UCHAR JA_PictureModeStr1[] ={5, 25, 26, 159, 21, 160, };
code UCHAR CT_PictureModeStr1[] ={4, 23, 24, 149, 150, };
code UCHAR CS_PictureModeStr1[] ={4, 23, 16, 146, 147, };

 code UCHAR EN_SenseyeDemoStr1[] =  {13, 'S', 'e', 'n', 's', 'e', 'y', 'e', ' ', 'D', 'e', 'm', 'o', ' ', };
code UCHAR FR_SenseyeDemoStr1[] =  {12, 'P', 'r', 2, 's', 'e', 'n', 't', 'a', 't', 'i', 'o', 'n', };
code UCHAR GE_SenseyeDemoStr1[] =  {12, 'D', 'e', 'm', 'o', ' ', 'S', 'e', 'n', 's', 'e', 'y', 'e', };
code UCHAR IT_SenseyeDemoStr1[] =  {12, 'S', 'e', 'n', 's', 'e', 'y', 'e', ' ', 'D', 'e', 'm', 'o', };
code UCHAR SP_SenseyeDemoStr1[] =  {13, 'D', 'e', 'm', 'o', ' ', 'S', 'e', 'n', 's', 'e', 'y', 'e', 5, };
code UCHAR PO_SenseyeDemoStr1[] =  {4, 'D', 'e', 'm', 'o', };
code UCHAR CZ_SenseyeDemoStr1[] =  {12, 'D', 'e', 'm', 'o', ' ', 'S', 'e', 'n', 's', 'e', 'y', 'e', };
code UCHAR MA_SenseyeDemoStr1[] =  {13, 'S', 'e', 'n', 's', 'e', 'y', 'e', ' ', 'd', 'e', 'm', 4, 5, };
code UCHAR SE_SenseyeDemoStr1[] =  {12, 'D', 'e', 'm', 'o', ' ', 'S', 'e', 'n', 's', 'e', 'y', 'e', };
code UCHAR RO_SenseyeDemoStr1[] =  {12, 'D', 'e', 'm', 'o', ' ', 'S', 'e', 'n', 's', 'e', 'y', 'e', };
code UCHAR DU_SenseyeDemoStr1[] =  {12, 'D', 'e', 'm', 'o', ' ', 'S', 'e', 'n', 's', 'e', 'y', 'e', };
code UCHAR RU_SenseyeDemoStr1[] =  {12, 123, 128, 146, 136, ' ', 'S', 'e', 'n', 's', 'e', 'y', 'e', };
code UCHAR SW_SenseyeDemoStr1[] =  {17, 'S', 'e', 'n', 's', 'e', 'y', 'e', ' ', 'D', 'e', 'm', 'o', ' ', 'l', 3, 'g', 'e', };
code UCHAR PR_SenseyeDemoStr1[] =  {13, 'S', 'e', 'n', 's', 'e', 'y', 'e', ' ', 'D', 'e', 'm', 'o', ' ', };
code UCHAR JA_SenseyeDemoStr1[] = {2, 161, 159, };
code UCHAR CT_SenseyeDemoStr1[] = {9, 'S', 'e', 'n', 's', 'e', 'y', 'e', 151, 152, };
code UCHAR CS_SenseyeDemoStr1[] = {11, 'S', 'e', 'n', 's', 'e', 'y', 'e', 148, 149, 150, 151, };

code UCHAR EN_DynamicContrastStr1[] = {15, 'D', 'y', 'n', 'a', 'm', 'i', 'c', 'C', 'o', 'n', 't', 'r', 'a', 's', 't', };
code UCHAR FR_DynamicContrastStr1[] = {15, 'D', 'y', 'n', 'a', 'm', 'i', 'c', 'C', 'o', 'n', 't', 'r', 'a', 's', 't', };
code UCHAR GE_DynamicContrastStr1[] = {15, 'D', 'y', 'n', 'a', 'm', 'i', 'c', 'C', 'o', 'n', 't', 'r', 'a', 's', 't', };
code UCHAR IT_DynamicContrastStr1[] = {15, 'D', 'y', 'n', 'a', 'm', 'i', 'c', 'C', 'o', 'n', 't', 'r', 'a', 's', 't', };
code UCHAR SP_DynamicContrastStr1[] = {15, 'D', 'y', 'n', 'a', 'm', 'i', 'c', 'C', 'o', 'n', 't', 'r', 'a', 's', 't', };
code UCHAR PO_DynamicContrastStr1[] = {15, 'D', 'y', 'n', 'a', 'm', 'i', 'c', 'C', 'o', 'n', 't', 'r', 'a', 's', 't', };
code UCHAR CZ_DynamicContrastStr1[] = {15, 'D', 'y', 'n', 'a', 'm', 'i', 'c', 'C', 'o', 'n', 't', 'r', 'a', 's', 't', };
code UCHAR MA_DynamicContrastStr1[] = {15, 'D', 'y', 'n', 'a', 'm', 'i', 'c', 'C', 'o', 'n', 't', 'r', 'a', 's', 't', };
code UCHAR SE_DynamicContrastStr1[] = {15, 'D', 'y', 'n', 'a', 'm', 'i', 'c', 'C', 'o', 'n', 't', 'r', 'a', 's', 't', };
code UCHAR RO_DynamicContrastStr1[] = {15, 'D', 'y', 'n', 'a', 'm', 'i', 'c', 'C', 'o', 'n', 't', 'r', 'a', 's', 't', };
code UCHAR DU_DynamicContrastStr1[] = {15, 'D', 'y', 'n', 'a', 'm', 'i', 'c', 'C', 'o', 'n', 't', 'r', 'a', 's', 't', };
code UCHAR RU_DynamicContrastStr1[] = {15, 'D', 'y', 'n', 'a', 'm', 'i', 'c', 'C', 'o', 'n', 't', 'r', 'a', 's', 't', };
code UCHAR SW_DynamicContrastStr1[] = {15, 'D', 'y', 'n', 'a', 'm', 'i', 'c', 'C', 'o', 'n', 't', 'r', 'a', 's', 't', };
code UCHAR PR_DynamicContrastStr1[] = {15, 'D', 'y', 'n', 'a', 'm', 'i', 'c', 'C', 'o', 'n', 't', 'r', 'a', 's', 't', };
code UCHAR JA_DynamicContrastStr1[] = {3, 'D', 'C', 'R', };
code UCHAR CT_DynamicContrastStr1[] = {6, 3, 142, 25, 26, 143, ' ', };
code UCHAR CS_DynamicContrastStr1[] = {5, 3, 142, 25, 26, ' ', };

code UCHAR EN_DisplayModeStr1[] = {12, 'D', 'i', 's', 'p', 'l', 'a', 'y', ' ', 'M', 'o', 'd', 'e', };
code UCHAR FR_DisplayModeStr1[] = {16, 'M', 'o', 'd', 'e', ' ', 'd', 39, 'a', 'f', 'f', 'i', 'c', 'h', 'a', 'g', 'e', };
code UCHAR GE_DisplayModeStr1[] = {12, 'A', 'n', 'z', 'e', 'i', 'g', 'e', 'm', 'o', 'd', 'u', 's', };
code UCHAR IT_DisplayModeStr1[] = {16, 'M', 'o', 'd', 'a', 'l', 'i', 't', 123, ' ', 'd', 'i', 's', 'p', 'l', 'a', 'y', };
code UCHAR SP_DisplayModeStr1[] = {18, 'M', 'o', 'd', 'o', ' ', 'v', 'i', 's', 'u', 'a', 'l', 'i', 'z', 'a', 'c', 'i', 4, 'n', };
code UCHAR PO_DisplayModeStr1[] = {17, 'T', 'r', 'y', 'b', ' ', 'w', 'y', 123, 'w', 'i', 'e', 't', 'l', 'a', 'n', 'i', 'a', };
code UCHAR CZ_DisplayModeStr1[] = {15, 'R', 'e', 26, 'i', 'm', ' ', 'z', 'o', 'b', 'r', 'a', 'z', 'e', 'n', 1, };
code UCHAR MA_DisplayModeStr1[] = {11, 'K', 'i', 'j', 'e', 'l', 'z', 123, ' ', 'm', 4, 'd', };
code UCHAR SE_DisplayModeStr1[] = {13, 'N', 'a', 6, 'i', 'n', ' ', 'p', 'r', 'i', 'k', 'a', 'z', 'a', };
code UCHAR RO_DisplayModeStr1[] = {11, 'M', 'o', 'd', ' ', 'a', 'f', 'i', 123, 'a', 'r', 'e', };
code UCHAR DU_DisplayModeStr1[] = {13, 'W', 'e', 'e', 'r', 'g', 'a', 'v', 'e', 'm', 'o', 'd', 'u', 's', };
code UCHAR RU_DisplayModeStr1[] = {14, 156, 128, 152, 124, 146, ' ', 136, 132, 136, 151, 133, 143, 152, '.', };
code UCHAR SW_DisplayModeStr1[] = {16, 'B', 'i', 'l', 'd', 'v', 'i', 's', 'n', 'i', 'n', 'g', 's', 'l', 3, 'g', 'e', };
code UCHAR PR_DisplayModeStr1[] = {13, 'M', 'o', 'd', 'a', 'l', 'i', 'd', '.', ' ', 'V', 'i', 's', '.', };
code UCHAR JA_DisplayModeStr1[] = {5, 25, 186, 159, 21, 160,};
code UCHAR CT_DisplayModeStr1[] ={4, 0, 1, 149, 150, };
code UCHAR CS_DisplayModeStr1[] ={4, 0, 1, 146, 147, };
 
code UCHAR EN_OverscanModeStr1[] = {8, 'O', 'v', 'e', 'r', 's', 'c', 'a', 'n', };
code UCHAR FR_OverscanModeStr1[] = {8, 'O', 'v', 'e', 'r', 's', 'c', 'a', 'n', };
code UCHAR GE_OverscanModeStr1[] = {8, 'O', 'v', 'e', 'r', 's', 'c', 'a', 'n', };
code UCHAR IT_OverscanModeStr1[] = {8, 'O', 'v', 'e', 'r', 's', 'c', 'a', 'n', };
code UCHAR SP_OverscanModeStr1[] = {8, 'O', 'v', 'e', 'r', 's', 'c', 'a', 'n', };
code UCHAR PO_OverscanModeStr1[] = {8, 'O', 'v', 'e', 'r', 's', 'c', 'a', 'n', };
code UCHAR CZ_OverscanModeStr1[] = {8, 'O', 'v', 'e', 'r', 's', 'c', 'a', 'n', };
code UCHAR MA_OverscanModeStr1[] = {8, 'O', 'v', 'e', 'r', 's', 'c', 'a', 'n', };
code UCHAR SE_OverscanModeStr1[] = {8, 'O', 'v', 'e', 'r', 's', 'c', 'a', 'n', };
code UCHAR RO_OverscanModeStr1[] = {8, 'O', 'v', 'e', 'r', 's', 'c', 'a', 'n', };
code UCHAR DU_OverscanModeStr1[] = {8, 'O', 'v', 'e', 'r', 's', 'c', 'a', 'n', };
code UCHAR RU_OverscanModeStr1[] = {8, 'O', 'v', 'e', 'r', 's', 'c', 'a', 'n', };
code UCHAR SW_OverscanModeStr1[] = {8, 'O', 'v', 'e', 'r', 's', 'c', 'a', 'n', };
code UCHAR PR_OverscanModeStr1[] = {8, 'O', 'v', 'e', 'r', 's', 'c', 'a', 'n', };
code UCHAR JA_OverscanModeStr1[] = {8, 'O', 'v', 'e', 'r', 's', 'c', 'a', 'n', };
code UCHAR CT_OverscanModeStr1[] = {8, 'O', 'v', 'e', 'r', 's', 'c', 'a', 'n', };
code UCHAR CS_OverscanModeStr1[] = {8, 'O', 'v', 'e', 'r', 's', 'c', 'a', 'n', };

code UCHAR EN_ColorFormatStr1[] = {12, 'C', 'o', 'l', 'o', 'r', ' ', 'F', 'o', 'r', 'm', 'a', 't', };
code UCHAR FR_ColorFormatStr1[] = {14, 'F', 'o', 'r', 'm', 'a', 't', ' ', 'c', 'o', 'u', 'l', 'e', 'u', 'r', };
code UCHAR GE_ColorFormatStr1[] = {10, 'F', 'a', 'r', 'b', 'f', 'o', 'r', 'm', 'a', 't', };
code UCHAR IT_ColorFormatStr1[] = {14, 'F', 'o', 'r', 'm', 'a', 't', 'o', ' ', 'c', 'o', 'l', 'o', 'r', 'e', };
code UCHAR SP_ColorFormatStr1[] = {16, 'F', 'o', 'r', 'm', 'a', 't', 'o', ' ', 'd', 'e', ' ', 'c', 'o', 'l', 'o', 'r', };
code UCHAR PO_ColorFormatStr1[] = {13, 'F', 'o', 'r', 'm', 'a', 't', ' ', 'k', 'o', 'l', 'o', 'r', 'u', };
code UCHAR CZ_ColorFormatStr1[] = {12, 'F', 'o', 'r', 'm', 0, 't', ' ', 'b', 'a', 'r', 'e', 'v', };
code UCHAR MA_ColorFormatStr1[] = {12, 'S', 'z', 1, 'n', 'f', 'o', 'r', 'm', 0, 't', 'u', 'm', };
code UCHAR SE_ColorFormatStr1[] = {11, 'F', 'o', 'r', 'm', 'a', 't', ' ', 'b', 'o', 'j', 'e', };
code UCHAR RO_ColorFormatStr1[] = {14, 'F', 'o', 'r', 'm', 'a', 't', ' ', 'c', 'u', 'l', 'o', 'a', 'r', 'e', };
code UCHAR DU_ColorFormatStr1[] = {12, 'K', 'l', 'e', 'u', 'r', 'f', 'o', 'r', 'm', 'a', 'a', 't', };
code UCHAR RU_ColorFormatStr1[] = {13, 145, 136, 133, 146, 143, 132, 143, ' ', 171, 131, 128, 132, 143, };
code UCHAR SW_ColorFormatStr1[] = {10, 'F', 3, 'r', 'g', 'f', 'o', 'r', 'm', 'a', 't', };
code UCHAR PR_ColorFormatStr1[] = {14, 'F', 'o', 'r', 'm', 'a', 't', 'o', ' ', 'd', 'e', ' ', 'C', 'o', 'r', };
code UCHAR JA_ColorFormatStr1[] ={9, 191, 30, 21, 19, 192, 21, 130, 148, 29, };
code UCHAR CT_ColorFormatStr1[] ={4, 31, 135, 186, 150, };
code UCHAR CS_ColorFormatStr1[] ={4, 185, 123, 186, 147, };
//ULEric140423
code UCHAR EN_HDMIRGBPCRangeStr1[] = {17, 'H','D','M','I',32,'R','G','B',32,'P','C',32,'R','a','n','g','e' };
code UCHAR FR_HDMIRGBPCRangeStr1[] = {17, 'P','l','a','g','e',32,'P','C',32,'R','V','B',32,'H','D','M','I'};
code UCHAR GE_HDMIRGBPCRangeStr1[] = {20, 'H','D','M','I',32,'R','G','B',32,'P','C',32,'-','B','e','r','e','i','c','h' };
code UCHAR IT_HDMIRGBPCRangeStr1[] = {17, 'G','a','m','m','a',32,'P','C',32,'R','G','B',32,'H','D','M','I'};
code UCHAR SP_HDMIRGBPCRangeStr1[] = {17, 'R','a','n','g','o',32,'R','G','B',32,'H','D','M','I',32,'P','C'};
code UCHAR PO_HDMIRGBPCRangeStr1[] = {17, 'Z','a','k','r','.',32,'H','D','M','I',32,'R','G','B',32,'P','C'};
code UCHAR CZ_HDMIRGBPCRangeStr1[] = {18, 'R','o','z','s','a','h',32,'H','D','M','I',32,'R','G','B',32,'P','C'};
code UCHAR MA_HDMIRGBPCRangeStr1[] = {17, 'H','D','M','I',32,'R','G','B',32,'P','C',32,'t','a','r','t','.' };
code UCHAR SE_HDMIRGBPCRangeStr1[] = {18, 'H','D','M','I',32,'R','G','B',32,'P','C',32,'r','a','s','p','o','n' };
code UCHAR RO_HDMIRGBPCRangeStr1[] = {16, 'H','D','M','I',32,'R','G','B',32,'g','a','m','a',32,'P','C'};
code UCHAR DU_HDMIRGBPCRangeStr1[] = {18, 'H','D','M','I',32,'R','G','B',32,'p','c','-','b','e','r','e','i','k'};
code UCHAR RU_HDMIRGBPCRangeStr1[] = {17, 'H','D','M','I',32,'R','G','B',32,139,124,143,126,'.',32,167,153};
code UCHAR SW_HDMIRGBPCRangeStr1[] = {16, 'H','D','M','I',32,'R','G','B',32,'P','C','-','o','m','r','.'};
code UCHAR PR_HDMIRGBPCRangeStr1[] = {17, 'A','m','p','l','.',32,'H','D','M','I',32,'R','G','B',32,'P','C'};
code UCHAR JA_HDMIRGBPCRangeStr1[] ={14, 'H','D','M','I',32,'R','G','B',32,'P','C',32,193,194};
code UCHAR CT_HDMIRGBPCRangeStr1[] ={13, 'H','D','M','I',32,'R','G','B',32,167,187,188,189};
code UCHAR CS_HDMIRGBPCRangeStr1[] ={13, 'H','D','M','I',32,'R','G','B',32,'P','C',187,188};
     
code UCHAR *PictureAdvancedTab[] = {
     EN_PictureModeStr1,
     FR_PictureModeStr1,
     GE_PictureModeStr1,
     IT_PictureModeStr1,
     SP_PictureModeStr1,
     PO_PictureModeStr1,
     CZ_PictureModeStr1,
     MA_PictureModeStr1,
     SE_PictureModeStr1,
     RO_PictureModeStr1,
     DU_PictureModeStr1,
     RU_PictureModeStr1,
     SW_PictureModeStr1,
     PR_PictureModeStr1,
     JA_PictureModeStr1,
     CT_PictureModeStr1,
     CS_PictureModeStr1,
     
     EN_SenseyeDemoStr1,
     FR_SenseyeDemoStr1,
     GE_SenseyeDemoStr1,
     IT_SenseyeDemoStr1,
     SP_SenseyeDemoStr1,
     PO_SenseyeDemoStr1,
     CZ_SenseyeDemoStr1,
     MA_SenseyeDemoStr1,
     SE_SenseyeDemoStr1,
     RO_SenseyeDemoStr1,
     DU_SenseyeDemoStr1,
     RU_SenseyeDemoStr1,
     SW_SenseyeDemoStr1,
     PR_SenseyeDemoStr1,
     JA_SenseyeDemoStr1,
     CT_SenseyeDemoStr1,
     CS_SenseyeDemoStr1,
     
     EN_DynamicContrastStr1,
     FR_DynamicContrastStr1,
     GE_DynamicContrastStr1,
     IT_DynamicContrastStr1,
     SP_DynamicContrastStr1,
     PO_DynamicContrastStr1,
     CZ_DynamicContrastStr1,
     MA_DynamicContrastStr1,
     SE_DynamicContrastStr1,
     RO_DynamicContrastStr1,
     DU_DynamicContrastStr1,
     RU_DynamicContrastStr1,
     SW_DynamicContrastStr1,
     PR_DynamicContrastStr1,
     JA_DynamicContrastStr1,
     CT_DynamicContrastStr1,
     CS_DynamicContrastStr1,
     
     EN_OverscanModeStr1,
     FR_OverscanModeStr1,
     GE_OverscanModeStr1,
     IT_OverscanModeStr1,
     SP_OverscanModeStr1,
     PO_OverscanModeStr1,
     CZ_OverscanModeStr1,
     MA_OverscanModeStr1,
     SE_OverscanModeStr1,
     RO_OverscanModeStr1,
     DU_OverscanModeStr1,
     RU_OverscanModeStr1,
     SW_OverscanModeStr1,
     PR_OverscanModeStr1,
     JA_OverscanModeStr1,
     CT_OverscanModeStr1,
     CS_OverscanModeStr1,

     EN_DisplayModeStr1,
     FR_DisplayModeStr1,
     GE_DisplayModeStr1,
     IT_DisplayModeStr1,
     SP_DisplayModeStr1,
     PO_DisplayModeStr1,
     CZ_DisplayModeStr1,
     MA_DisplayModeStr1,
     SE_DisplayModeStr1,
     RO_DisplayModeStr1,
     DU_DisplayModeStr1,
     RU_DisplayModeStr1,
     SW_DisplayModeStr1,
     PR_DisplayModeStr1,
     JA_DisplayModeStr1,
     CT_DisplayModeStr1,
     CS_DisplayModeStr1,
     
     EN_ColorFormatStr1,
     FR_ColorFormatStr1,
     GE_ColorFormatStr1,
     IT_ColorFormatStr1,
     SP_ColorFormatStr1,
     PO_ColorFormatStr1,
     CZ_ColorFormatStr1,
     MA_ColorFormatStr1,
     SE_ColorFormatStr1,
     RO_ColorFormatStr1,
     DU_ColorFormatStr1,
     RU_ColorFormatStr1,
     SW_ColorFormatStr1,
     PR_ColorFormatStr1,
     JA_ColorFormatStr1,
     CT_ColorFormatStr1,
     CS_ColorFormatStr1,

     EN_HDMIRGBPCRangeStr1,
     FR_HDMIRGBPCRangeStr1,//FR
     GE_HDMIRGBPCRangeStr1,//GE
     IT_HDMIRGBPCRangeStr1,//IT
     SP_HDMIRGBPCRangeStr1,//SP
     PO_HDMIRGBPCRangeStr1,//PO
     CZ_HDMIRGBPCRangeStr1,//CZ
     MA_HDMIRGBPCRangeStr1,//MA
     SE_HDMIRGBPCRangeStr1,//SE
     RO_HDMIRGBPCRangeStr1,//RO
     DU_HDMIRGBPCRangeStr1,//DU
     RU_HDMIRGBPCRangeStr1,//RU
     SW_HDMIRGBPCRangeStr1,//SW
     PR_HDMIRGBPCRangeStr1,//PR
     JA_HDMIRGBPCRangeStr1,//JA
     CT_HDMIRGBPCRangeStr1,//CT
     CS_HDMIRGBPCRangeStr1,//CS
};
// audio string item
code UCHAR EN_VolumeStr1[]={6, 'V', 'o', 'l', 'u', 'm', 'e', };
code UCHAR FR_VolumeStr1[]={6, 'V', 'o', 'l', 'u', 'm', 'e', };
code UCHAR GE_VolumeStr1[]={10, 'L', 'a', 'u', 't', 's', 't', 3, 'r', 'k', 'e', };
code UCHAR IT_VolumeStr1[]={6, 'V', 'o', 'l', 'u', 'm', 'e', };
code UCHAR SP_VolumeStr1[]={7, 'V', 'o', 'l', 'u', 'm', 'e', 'n', };
code UCHAR PO_VolumeStr1[]={9, 'G', 129, 'o', 123, 'n', 'o', 123, 22, 5, };
code UCHAR CZ_VolumeStr1[]={9, 'H', 'l', 'a', 's', 'i', 't', 'o', 's', 't', };
code UCHAR MA_VolumeStr1[]={7, 'H', 'a', 'n', 'g', 'e', 'r', 123, };
code UCHAR SE_VolumeStr1[]={10, 'G', 'l', 'a', 's', 'n', 'o', 22, 'a', ' ', 5, };
code UCHAR RO_VolumeStr1[]={5, 'V', 'o', 'l', 'u', 'm', };
code UCHAR DU_VolumeStr1[]={6, 'V', 'o', 'l', 'u', 'm', 'e', };
code UCHAR RU_VolumeStr1[]={9, 140, 133, 136, 146, 148, 136, 125, 132, 155, };
code UCHAR SW_VolumeStr1[]={5, 'V', 'o', 'l', 'y', 'm', };
code UCHAR PR_VolumeStr1[]={6, 'V', 'o', 'l', 'u', 'm', 'e', };
code UCHAR JA_VolumeStr1[]={4, 195, 196, 4, 5, };
code UCHAR CT_VolumeStr1[]={4, 190, 192, 4, 5, };
code UCHAR CS_VolumeStr1[]={4, 189, 190, 4, 191, };

code UCHAR EN_MuteStr1[]={4, 'M', 'u', 't', 'e', };
code UCHAR FR_MuteStr1[]={4, 'M', 'u', 'e', 't', };
code UCHAR GE_MuteStr1[]={5, 'S', 't', 'u', 'm', 'm', };
code UCHAR IT_MuteStr1[]={15, 'D', 'i', 's', 'a', 't', 't', 'i', 'v', 'a', ' ', 'a', 'u', 'd', 'i', 'o', };
code UCHAR SP_MuteStr1[]={9, 'S', 'i', 'l', 'e', 'n', 'c', 'i', 'a', 'r', };
code UCHAR PO_MuteStr1[]={7, 'W', 'y', 'c', 'i', 's', 'z', 5, };
code UCHAR CZ_MuteStr1[]={7, 'Z', 't', 'l', 'u', 'm', 'i', 't', };
code UCHAR MA_MuteStr1[]={5, 'N', 2, 'm', 1, 't', };
code UCHAR SE_MuteStr1[]={7, 'U', 't', 'i', 20, 'a', 'n', 'o', };
code UCHAR RO_MuteStr1[]={3, 'M', 'u', 't', };
code UCHAR DU_MuteStr1[]={10, 'G', 'e', 'l', 'u', 'i', 'd', ' ', 'u', 'i', 't', };
code UCHAR RU_MuteStr1[]={14, 137, 159, 148, 127, 174, 147, 124, 132, 155, ' ', 141, 131, 135, 148, };
code UCHAR SW_MuteStr1[]={4, 'T', 'y', 's', 't', };
code UCHAR PR_MuteStr1[]={7, 'S', 'e', 'm', ' ', 's', 'o', 'm', };
code UCHAR JA_MuteStr1[]={4, 152, 197, 21, 29, };
code UCHAR CT_MuteStr1[]={2, 193, 190, };
code UCHAR CS_MuteStr1[]={2, 192, 189, };


 code UCHAR EN_AudioSelectStr1[]={12, 'A', 'u', 'd', 'i', 'o', ' ', 'S', 'e', 'l', 'e', 'c', 't', };
 code UCHAR FR_AudioSelectStr1[]={15, 'S', 2, 'l', 'e', 'c', 't', 'i', 'o', 'n', ' ', 'a', 'u', 'd', 'i', 'o', };
 code UCHAR GE_AudioSelecteStr1[]={13, 'A', 'u', 'd', 'i', 'o', '-', 'A', 'u', 's', 'w', 'a', 'h', 'l', };
 code UCHAR IT_AudioSelectStr1[]={11, 'S', 'e', 'l', 'e', 'z', ' ', 'a', 'u', 'd', 'i', 'o', };
 code UCHAR SP_AudioSelectStr1[]={12, 'S', 'e', 'l', 'e', 'c', 'c', ' ', 'a', 'u', 'd', 'i', 'o', };
 code UCHAR PO_AudioSelectStr[]={13, 'W', 'y', 'b', 4, 'r', ' ', 'd', 130, 'w', 'i', 128, 'k', 'u', };
 code UCHAR CZ_AudioSelectStr1[]={11, 'V', 'y', 'b', 'r', 'a', 't', ' ', 'z', 'v', 'u', 'k', };
 code UCHAR MA_AudioSelectStr1[]={13, 'H', 'a', 'n', 'g', 'v', 0, 'l', 'a', 's', 'z', 't', 0, 's', };
 code UCHAR SE_AudioSelectStr1[]={14, 'I', 'z', 'b', 'o', 'r', ' ', 'a', 'u', 'd', 'i', 'o', ' ', 's', '.', };
 code UCHAR RO_AudioSelectStr1[]={14, 'S', 'e', 'l', 'e', 'c', 124, 'i', 'e', ' ', 'A', 'u', 'd', 'i', 'o', };
 code UCHAR DU_AudioSelectStr1[]={16, 'A', 'u', 'd', 'i', 'o', ' ', 's', 'e', 'l', 'e', 'c', 't', 'e', 'r', 'e', 'n', };
 code UCHAR RU_AudioSelectStr1[]={11, 137, 159, 151, 136, 133, ' ', 141, 131, 135, 148, 143, };
 code UCHAR SW_AudioSelectStr1[]={7, 'L', 'j', 'u', 'd', 'v', 'a', 'l', };
 code UCHAR PR_AudioSelectStr1[]={12, 'S', 'e', 'l', 'e', 'c', '.', ' ', 21, 'u', 'd', 'i', 'o', };
 code UCHAR JA_AudioSelectStr1[]={7, 149, 21, 161, 170, 149, 200, 201, };
 code UCHAR CT_AudioSelectStr1[]={4, 195, 196, 190, 191, };
 code UCHAR CS_AudioSelectStr1[]={4, 189, 18, 194, 195, };


code UCHAR *AudioTab[] = {

    EN_VolumeStr1,
    FR_VolumeStr1,
    GE_VolumeStr1,
    IT_VolumeStr1,
    SP_VolumeStr1,
    PO_VolumeStr1,
    CZ_VolumeStr1,
    MA_VolumeStr1,
    SE_VolumeStr1,
    RO_VolumeStr1,
    DU_VolumeStr1,
    RU_VolumeStr1,
    SW_VolumeStr1,
    PR_VolumeStr1,
    JA_VolumeStr1,
    CT_VolumeStr1,
    CS_VolumeStr1,


    EN_MuteStr1,
    FR_MuteStr1,
    GE_MuteStr1,
    IT_MuteStr1,
    SP_MuteStr1,
    PO_MuteStr1,
    CZ_MuteStr1,
    MA_MuteStr1,
    SE_MuteStr1,
    RO_MuteStr1,
    DU_MuteStr1,
    RU_MuteStr1,
    SW_MuteStr1,
    PR_MuteStr1,
    JA_MuteStr1,
    CT_MuteStr1,
    CS_MuteStr1,


    EN_AudioSelectStr1,
    FR_AudioSelectStr1,
    GE_AudioSelecteStr1,
    IT_AudioSelectStr1,
    SP_AudioSelectStr1,
    PO_AudioSelectStr,
    CZ_AudioSelectStr1,
    MA_AudioSelectStr1,
    SE_AudioSelectStr1,
    RO_AudioSelectStr1,
    DU_AudioSelectStr1,
    RU_AudioSelectStr1,
    SW_AudioSelectStr1,
    PR_AudioSelectStr1,
    JA_AudioSelectStr1,
    CT_AudioSelectStr1,
    CS_AudioSelectStr1,


};


// System string item
code UCHAR EN_OSDSettingsStr1[] = {12, 'O', 'S', 'D', ' ', 'S', 'e', 't', 't', 'i', 'n', 'g', 's', };
code UCHAR FR_OSDSettingsStr1[] = {14, 'P', 'a', 'r', 'a', 'm', 29, 't', 'r', 'e', 's', ' ', 'O', 'S', 'D', };
code UCHAR GE_OSDSettingsStr1[] = {10, 'O', 'S', 'D', '-', 'E', 'i', 'n', 's', 't', '.', };
code UCHAR IT_OSDSettingsStr1[] = {9, 'I', 'm', 'p', '.', ' ', 'O', 'S', 'D', ' ', };
code UCHAR SP_OSDSettingsStr1[] = {12, 'C', 'o', 'n', 'f', 'i', 'g', '.', ' ', 'O', 'S', 'D', 5, };
code UCHAR PO_OSDSettingsStr1[] = {11, 'U', 's', 't', 'a', 'w', '.', ' ', 'O', 'S', 'D', 5, };
code UCHAR CZ_OSDSettingsStr1[] = {13, 'N', 'a', 's', 't', 'a', 'v', 'e', 'n', 1, ' ', 'O', 'S', 'D', };
code UCHAR MA_OSDSettingsStr1[] = {11, 'O', 'S', 'D', ' ', 'b', 'e', 0, 'l', 'l', '.', ' ', };
code UCHAR SE_OSDSettingsStr1[] = {12, 'O', 'S', 'D', ' ', 'p', 'o', 's', 't', 'a', 'v', 'k', 'e', };
code UCHAR RO_OSDSettingsStr1[] = {10, 'S', 'e', 't', 125, 'r', 'i', ' ', 'O', 'S', 'D', };
code UCHAR DU_OSDSettingsStr1[] = {16, 'O', 'S', 'D', '-', 'i', 'n', 's', 't', 'e', 'l', 'l', 'i', 'n', 'g', 'e', 'n', };
code UCHAR RU_OSDSettingsStr1[] = {16, 158, 143, 125, 132, 133, '.', ' ', 176, 148, 133, '.', ' ', 146, 128, 144, 174, };
code UCHAR SW_OSDSettingsStr1[] = {15, 'O', 'S', 'D', ' ', 'I', 'n', 's', 't', 3, 'l', 'l', 'n', 'i', 'n', 'g', };
code UCHAR PR_OSDSettingsStr1[] = {14, 'D', 'e', 'f', 'i', 'n', 'i', 7, 124, 'e', 's', ' ', 'O', 'S', 'D', };
code UCHAR JA_OSDSettingsStr1[] = {6, 'O', 'S', 'D', ' ', 141, 142, };
code UCHAR CT_OSDSettingsStr1[] = {6, 'O', 'S', 'D', ' ', 147, 133, };
code UCHAR CS_OSDSettingsStr1[] = {6, 'O', 'S', 'D', ' ', 145, 13, };

code UCHAR EN_CustomKey1Str1[] = {12, 'C', 'u', 's', 't', 'o', 'm', ' ', 'k', 'e', 'y', ' ', '1', };
code UCHAR FR_CustomKey1Str1[] = {14, 'T', 'o', 'u', 'c', 'h', 'e', ' ', 'p', 'e', 'r', 's', 'o', ' ', '1', };
code UCHAR GE_CustomKey1Str1[] = {16, 'B', 'e', 'n', 'u', 't', 'z', 'e', 'r', '-', 'T', 'a', 's', 't', 'e', ' ', '1', };
code UCHAR IT_CustomKey1Str1[] = {19, 'T', 'a', 's', 't', 'o', ' ', 'p', 'e', 'r', 's', 'o', 'n', 'a', 'l', 'i', 'z', 'z', ' ', '1', };
code UCHAR SP_CustomKey1Str1[] = {19, 'T', 'e', 'c', 'l', 'a', ' ', 'p', 'e', 'r', 's', 'o', 'n', 'a', 'l', 'i', 'z', '.', ' ', '1', };
code UCHAR PO_CustomKey1Str1[] = {19, 'P', 'r', 'z', 'y', 'c', 'i', 's', 'k', ' ', 'n', 'i', 'e', 's', 't', 'a', 'n', '.', ' ', '1', };
code UCHAR CZ_CustomKey1Str1[] = {17, 'V', 'l', 'a', 's', 't', 'n', 1, ' ', 'k', 'l', 0, 'v', 'e', 's', 'a', ' ', '1', };
code UCHAR MA_CustomKey1Str1[] = {14, 'E', 'g', 'y', 2, 'n', 'i', ' ', 'k', 'u', 'l', 'c', 's', ' ', '1', };
code UCHAR SE_CustomKey1Str1[] = {18, 'K', 'o', 'r', 'i', 's', 'n', 'i', 6, 'k', 'a', ' ', 't', 'i', 'p', 'k', 'a', ' ', '1', };
code UCHAR RO_CustomKey1Str1[] = {19, 'T', 'a', 's', 't', 125, ' ', 'p', 'e', 'r', 's', 'o', 'n', 'a', 'l', 'i', 'z', '.', ' ', '1', };
code UCHAR DU_CustomKey1Str1[] = {18, 'A', 'a', 'n', 'g', 'e', 'p', 'a', 's', 't', 'e', ' ', 't', 'o', 'e', 't', 's', ' ', '1', };
code UCHAR RU_CustomKey1Str1[] = {19, 153, 144, 136, 126, 148, 143, ' ', '"', 167, 136, 127, 155, 141, 136, 131, '.', '"', ' ', '1', };
code UCHAR SW_CustomKey1Str1[] = {16, 'A', 'n', 'p', 'a', 's', 's', 'a', 'd', ' ', 'k', 'n', 'a', 'p', 'p', ' ', '1', };
code UCHAR PR_CustomKey1Str1[] = {15, 'C', 'h', 'a', 'v', 'e', ' ', 'P', 'e', 'r', 's', 'o', 'n', '.', ' ', '1', };
code UCHAR JA_CustomKey1Str1[] = {9, 191, 31, 225, 154, ' ', 218, 21, ' ', '1', };
code UCHAR CT_CustomKey1Str1[] = {5, 2, 220, 212, ' ', '1', };
code UCHAR CS_CustomKey1Str1[] = {6, 2, 133, 134, 211, ' ', '1', };

code UCHAR EN_CustomKey2Str1[] = {12, 'C', 'u', 's', 't', 'o', 'm', ' ', 'k', 'e', 'y', ' ', '2', };
code UCHAR FR_CustomKey2Str1[] = {14, 'T', 'o', 'u', 'c', 'h', 'e', ' ', 'p', 'e', 'r', 's', 'o', ' ', '2', };
code UCHAR GE_CustomKey2Str1[] = {16, 'B', 'e', 'n', 'u', 't', 'z', 'e', 'r', '-', 'T', 'a', 's', 't', 'e', ' ', '2', };
code UCHAR IT_CustomKey2Str1[] = {19, 'T', 'a', 's', 't', 'o', ' ', 'p', 'e', 'r', 's', 'o', 'n', 'a', 'l', 'i', 'z', 'z', ' ', '2', };
code UCHAR SP_CustomKey2Str1[] = {19, 'T', 'e', 'c', 'l', 'a', ' ', 'p', 'e', 'r', 's', 'o', 'n', 'a', 'l', 'i', 'z', '.', ' ', '2', };
code UCHAR PO_CustomKey2Str1[] = {19, 'P', 'r', 'z', 'y', 'c', 'i', 's', 'k', ' ', 'n', 'i', 'e', 's', 't', 'a', 'n', '.', ' ', '2', };
code UCHAR CZ_CustomKey2Str1[] = {17, 'V', 'l', 'a', 's', 't', 'n', 1, ' ', 'k', 'l', 0, 'v', 'e', 's', 'a', ' ', '2', };
code UCHAR MA_CustomKey2Str1[] = {14, 'E', 'g', 'y', 2, 'n', 'i', ' ', 'k', 'u', 'l', 'c', 's', ' ', '2', };
code UCHAR SE_CustomKey2Str1[] = {18, 'K', 'o', 'r', 'i', 's', 'n', 'i', 6, 'k', 'a', ' ', 't', 'i', 'p', 'k', 'a', ' ', '2', };
code UCHAR RO_CustomKey2Str1[] = {19, 'T', 'a', 's', 't', 125, ' ', 'p', 'e', 'r', 's', 'o', 'n', 'a', 'l', 'i', 'z', '.', ' ', '2', };
code UCHAR DU_CustomKey2Str1[] = {18, 'A', 'a', 'n', 'g', 'e', 'p', 'a', 's', 't', 'e', ' ', 't', 'o', 'e', 't', 's', ' ', '2', };
code UCHAR RU_CustomKey2Str1[] = {19, 153, 144, 136, 126, 148, 143, ' ', '"', 167, 136, 127, 155, 141, 136, 131, '.', '"', ' ', '2', };
code UCHAR SW_CustomKey2Str1[] = {16, 'A', 'n', 'p', 'a', 's', 's', 'a', 'd', ' ', 'k', 'n', 'a', 'p', 'p', ' ', '2', };
code UCHAR PR_CustomKey2Str1[] = {15, 'C', 'h', 'a', 'v', 'e', ' ', 'P', 'e', 'r', 's', 'o', 'n', '.', ' ', '2', };
code UCHAR JA_CustomKey2Str1[] = {9, 191, 31, 225, 154, ' ', 218, 21, ' ', '2', };
code UCHAR CT_CustomKey2Str1[] ={5, 2, 220, 212, ' ', '2', };
code UCHAR CS_CustomKey2Str1[] ={6, 2, 133, 134, 211, ' ', '2', };
 
code UCHAR EN_CustomKey3Str1[] = {12, 'C', 'u', 's', 't', 'o', 'm', ' ', 'k', 'e', 'y', ' ', '3', };
code UCHAR FR_CustomKey3Str1[] = {14, 'T', 'o', 'u', 'c', 'h', 'e', ' ', 'p', 'e', 'r', 's', 'o', ' ', '3', };
code UCHAR GE_CustomKey3Str1[] = {16, 'B', 'e', 'n', 'u', 't', 'z', 'e', 'r', '-', 'T', 'a', 's', 't', 'e', ' ', '3', };
code UCHAR IT_CustomKey3Str1[] = {19, 'T', 'a', 's', 't', 'o', ' ', 'p', 'e', 'r', 's', 'o', 'n', 'a', 'l', 'i', 'z', 'z', ' ', '3', };
code UCHAR SP_CustomKey3Str1[] = {19, 'T', 'e', 'c', 'l', 'a', ' ', 'p', 'e', 'r', 's', 'o', 'n', 'a', 'l', 'i', 'z', '.', ' ', '3', };
code UCHAR PO_CustomKey3Str1[] = {19, 'P', 'r', 'z', 'y', 'c', 'i', 's', 'k', ' ', 'n', 'i', 'e', 's', 't', 'a', 'n', '.', ' ', '3', };
code UCHAR CZ_CustomKey3Str1[] = {17, 'V', 'l', 'a', 's', 't', 'n', 1, ' ', 'k', 'l', 0, 'v', 'e', 's', 'a', ' ', '3', };
code UCHAR MA_CustomKey3Str1[] = {14, 'E', 'g', 'y', 2, 'n', 'i', ' ', 'k', 'u', 'l', 'c', 's', ' ', '3', };
code UCHAR SE_CustomKey3Str1[] = {18, 'K', 'o', 'r', 'i', 's', 'n', 'i', 6, 'k', 'a', ' ', 't', 'i', 'p', 'k', 'a', ' ', '3', };
code UCHAR RO_CustomKey3Str1[] = {19, 'T', 'a', 's', 't', 125, ' ', 'p', 'e', 'r', 's', 'o', 'n', 'a', 'l', 'i', 'z', '.', ' ', '3', };
code UCHAR DU_CustomKey3Str1[] = {18, 'A', 'a', 'n', 'g', 'e', 'p', 'a', 's', 't', 'e', ' ', 't', 'o', 'e', 't', 's', ' ', '3', };
code UCHAR RU_CustomKey3Str1[] = {19, 153, 144, 136, 126, 148, 143, ' ', '"', 167, 136, 127, 155, 141, 136, 131, '.', '"', ' ', '3', };
code UCHAR SW_CustomKey3Str1[] = {16, 'A', 'n', 'p', 'a', 's', 's', 'a', 'd', ' ', 'k', 'n', 'a', 'p', 'p', ' ', '3', };
code UCHAR PR_CustomKey3Str1[] = {15, 'C', 'h', 'a', 'v', 'e', ' ', 'P', 'e', 'r', 's', 'o', 'n', '.', ' ', '3', };
code UCHAR JA_CustomKey3Str1[] = {9, 191, 31, 225, 154, ' ', 218, 21, ' ', '3', };
code UCHAR CT_CustomKey3Str1[] = {5, 2, 220, 212, ' ', '3', };
code UCHAR CS_CustomKey3Str1[] = {6, 2, 133, 134, 211, ' ', '3', };
 
code UCHAR EN_DDCCiStr1[] = {6,"DDC/CI"};
/*
code UCHAR FR_DDCCiStr1[] = {6,"DDC/CI"};
code UCHAR GE_DDCCiStr1[] = {6,"DDC/CI"};
code UCHAR IT_DDCCiStr1[] = {6,"DDC/CI"};
code UCHAR SP_DDCCiStr1[] = {6,"DDC/CI"};
code UCHAR PO_DDCCiStr1[] = {6,"DDC/CI"};
code UCHAR CZ_DDCCiStr1[] = {6,"DDC/CI"};
code UCHAR MA_DDCCiStr1[] = {6,"DDC/CI"};
code UCHAR SE_DDCCiStr1[] = {6,"DDC/CI"};
code UCHAR RO_DDCCiStr1[] = {6,"DDC/CI"};
code UCHAR DU_DDCCiStr1[] = {6,"DDC/CI"};
code UCHAR RU_DDCCiStr1[] = {6,"DDC/CI"};
code UCHAR SW_DDCCiStr1[] = {6,"DDC/CI"};
code UCHAR PR_DDCCiStr1[] = {6,"DDC/CI"};
code UCHAR JA_DDCCiStr1[] = {6,"DDC/CI"};
code UCHAR CT_DDCCiStr1[] = {6,"DDC/CI"};
code UCHAR CS_DDCCiStr1[] = {6,"DDC/CI"};
*/

code UCHAR EN_DPAutoSwitchStr1[]={14, 'D', 'P', ' ', 'A', 'u', 't', 'o', ' ', 'S', 'w', 'i', 't', 'c', 'h', };
code UCHAR FR_DPAutoSwitchStr1[]={14, 'C', 'o', 'm', 'm', 'u', 't', '.', 'a', 'u', 't', 'o', ' ', 'D', 'P', };
code UCHAR GE_DPAutoSwitchStr1[]={14, 'A', 'u', 't', '.', ' ', 'D', 'P', '-', 'W', 'e', 'c', 'h', 's', '.', };
code UCHAR IT_DPAutoSwitchStr1[]={12, 'C', 'o', 'm', 'm', ' ', 'a', 'u', 't', 'o', ' ', 'D', 'P', };
code UCHAR SP_DPAutoSwitchStr1[]={16, 'C', 'a', 'm', 'b', 'i', 'o', ' ', 'a', 'u', 't', 'o', 'm', '.', ' ', 'D', 'P', };
code UCHAR PO_DPAutoSwitchStr1[]={15, 'A', 'u', 't', 'o', '.', ' ', 'p', 'r', 'z', 'e', 129, '.', ' ', 'D', 'P', };
code UCHAR CZ_DPAutoSwitchStr1[]={12, 'A', 'u', 't', '.', 'p', 124, 'e', 'p', '.', ' ', 'D', 'P', };
code UCHAR MA_DPAutoSwitchStr1[]={16, 'D', 'P', ' ', 'A', 'u', 't', 'o', ' ', 'K', 'a', 'p', 'c', 's', 'o', 'l', 4, };
code UCHAR SE_DPAutoSwitchStr1[]={15, 'A', 'u', 't', '.', 'p', 'r', 'e', 'k', 'l', 'a', 'p', '.', ' ', 'D', 'P', };
code UCHAR RO_DPAutoSwitchStr1[]={14, 'C', 'o', 'm', 'u', 't', '.', ' ', 'a', 'u', 't', 'o', ' ', 'D', 'P', };
code UCHAR DU_DPAutoSwitchStr1[]={14, 'D', 'P', ' ', 'a', 'u', 't', 'o', '-', 'o', 'm', 's', 'c', 'h', '.', };
code UCHAR RU_DPAutoSwitchStr1[]={14, 130, 131, 132, 136, 126, 128, 133, 128, 148, 127, '.', ' ', 'D', 'P', };
code UCHAR SW_DPAutoSwitchStr1[]={14, 'D', 'P', '-', 'a', 'u', 't', 'o', 'v', 3, 'x', 'l', 'i', 'n', 'g', };
code UCHAR PR_DPAutoSwitchStr1[]={12, 'I', 'n', 't', '.', ' ', 'a', 'u', 't', 'o', ' ', 'D', 'P', };
code UCHAR JA_DPAutoSwitchStr1[]={7, 'D', 'P', ' ', 2, 3, 236, 237, };
code UCHAR CT_DPAutoSwitchStr1[]={7, 'D', 'P', ' ', 2, 3, 230, 231, };
code UCHAR CS_DPAutoSwitchStr1[]={7, 'D', 'P', ' ', 2, 3, 229, 230, };


code UCHAR EN_HDMIAutoSwitchStr1[]={16, 'H', 'D', 'M', 'I', ' ', 'A', 'u', 't', 'o', ' ', 'S', 'w', 'i', 't', 'c', 'h', };
code UCHAR FR_HDMIAutoSwitchStr1[]={16, 'C', 'o', 'm', 'm', 'u', 't', '.', 'a', 'u', 't', 'o', ' ', 'H', 'D', 'M', 'I', };
code UCHAR GE_HDMIAutoSwitchStr1[]={16, 'A', 'u', 't', '.', ' ', 'H', 'D', 'M', 'I', '-', 'W', 'e', 'c', 'h', 's', '.', };
code UCHAR IT_HDMIAutoSwitchStr1[]={14, 'C', 'o', 'm', 'm', ' ', 'a', 'u', 't', 'o', ' ', 'H', 'D', 'M', 'I', };
code UCHAR SP_HDMIAutoSwitchStr1[]={16, 'E', 'n', 'c', 'e', 'n', 'd', ' ', 'a', 'u', 't', 'o', ' ', 'H', 'D', 'M', 'I', };
code UCHAR PO_HDMIAutoSwitchStr1[]={17, 'A', 'u', 't', 'o', '.', ' ', 'p', 'r', 'z', 'e', 129, '.', ' ', 'H', 'D', 'M', 'I', };
code UCHAR CZ_HDMIAutoSwitchStr1[]={14, 'A', 'u', 't', '.', 'p', 124, 'e', 'p', '.', ' ', 'H', 'D', 'M', 'I', };
code UCHAR MA_HDMIAutoSwitchStr1[]={16, 'H', 'D', 'M', 'I', ' ', 'a', 'u', 't', 'o', ' ', 'v', 0, 'l', 't', 0, 's', };
code UCHAR SE_HDMIAutoSwitchStr1[]={16, 'H', 'D', 'M', 'I', ' ', 'a', 'u', 't', '.', 'p', 'r', 'e', 'b', 'a', 'c', '.', };
code UCHAR RO_HDMIAutoSwitchStr1[]={16, 'C', 'o', 'm', 'u', 't', '.', ' ', 'a', 'u', 't', 'o', ' ', 'H', 'D', 'M', 'I', };
code UCHAR DU_HDMIAutoSwitchStr1[]={16, 'H', 'd', 'm', 'i', ' ', 'a', 'u', 't', 'o', '-', 'o', 'm', 's', 'c', 'h', '.', };
code UCHAR RU_HDMIAutoSwitchStr1[]={16, 130, 131, 132, 136, 126, 128, 133, 128, 148, 127, '.', ' ', 'H', 'D', 'M', 'I', };
code UCHAR SW_HDMIAutoSwitchStr1[]={16, 'H', 'D', 'M', 'I', '-', 'a', 'u', 't', 'o', 'v', 3, 'x', 'l', 'i', 'n', 'g', };
code UCHAR PR_HDMIAutoSwitchStr1[]={14, 'I', 'n', 't', '.', ' ', 'a', 'u', 't', 'o', ' ', 'H', 'D', 'M', 'I', };
code UCHAR JA_HDMIAutoSwitchStr1[]={9, 'H', 'D', 'M', 'I', ' ', 2, 3, 236, 237, };
code UCHAR CT_HDMIAutoSwitchStr1[]={9, 'H', 'D', 'M', 'I', ' ', 2, 3, 230, 231, };
code UCHAR CS_HDMIAutoSwitchStr1[]={9, 'H', 'D', 'M', 'I', ' ', 2, 3, 229, 230, };



code UCHAR EN_AutoPowerOffStr1[] = {14, 'A', 'u', 't', 'o', ' ', 'P', 'o', 'w', 'e', 'r', ' ', 'o', 'f', 'f', };
code UCHAR FR_AutoPowerOffStr1[] = {19, 'A', 'l', 'i', 'm', '.', ' ', 'a', 'u', 't', 'o', '.', ' ', 'd', 2, 's', 'a', 'c', 't', '.', };
code UCHAR GE_AutoPowerOffStr1[] = {16, 'A', 'u', 't', 'o', '-', 'A', 'b', 's', 'c', 'h', 'a', 'l', 't', 'u', 'n', 'g', };
code UCHAR IT_AutoPowerOffStr1[] = {18, 'S', 'p', 'e', 'g', 'n', 'i', 'm', 'e', 'n', 't', 'o', ' ', 'a', 'u', 't', 'o', 'm', '.', };
code UCHAR SP_AutoPowerOffStr1[] = {18, 'A', 'p', 'a', 'g', 'a', 'd', 'o', ' ', 'a', 'u', 't', 'o', 'm', 0, 't', 'i', 'c', 'o', };
code UCHAR PO_AutoPowerOffStr1[] = {21, 'A', 'u', 't', 'o', 'm', '.', ' ', 'w', 'y', 129, '.', ' ', 'Z', 'a', 's', 'i', 'l', 'a', 'n', 'i', 'a', };
code UCHAR CZ_AutoPowerOffStr1[] = {19, 'A', 'u', 't', 'o', 'm', 'a', 't', 'i', 'c', 'k', 2, ' ', 'v', 'y', 'p', 'n', 'u', 't', 1, };
code UCHAR MA_AutoPowerOffStr1[] = {17, 'A', 'u', 't', 'o', '.', ' ', 'k', 'i', 'k', 'a', 'p', 'c', 's', 'o', 'l', 0, 's', };
code UCHAR SE_AutoPowerOffStr1[] = {20, 'A', 'u', 't', 'o', 'm', '.', ' ', 'I', 's', 'k', 'l', 'j', 'u', 6, 'i', 'v', 'a', 'n', 'j', 'e', };
code UCHAR RO_AutoPowerOffStr1[] = {15, 'O', 'p', 'r', 'i', 'r', 'e', ' ', 'a', 'u', 't', 'o', 'm', 'a', 't', 125, };
code UCHAR DU_AutoPowerOffStr1[] = {15, 'A', 'u', 't', 'o', 'm', 'a', 't', 'i', 's', 'c', 'h', ' ', 'u', 'i', 't', };
code UCHAR RU_AutoPowerOffStr1[] = {15, 130, 131, 132, '.', ' ', 131, 159, 148, 127, '.', ' ', 126, 124, 132, '.', };
code UCHAR SW_AutoPowerOffStr1[] = {14, 'A', 'u', 't', 'o', ' ', 'P', 'o', 'w', 'e', 'r', ' ', 'o', 'f', 'f', };
code UCHAR PR_AutoPowerOffStr1[] = {13, 'D', 'e', 'l', 'i', 'g', 'a', 'r', ' ', 'A', 'u', 't', 'o', '.', };
code UCHAR JA_AutoPowerOffStr1[] ={6, 2, 3, 238, 239, 149, 19, };
code UCHAR CT_AutoPowerOffStr1[] ={4, 2, 3, 138, 232, };
code UCHAR CS_AutoPowerOffStr1[] ={6, 2, 3, 165, 231, 138, 139, };
 
code UCHAR EN_ResolutionNoticeStr1[] = {17, 'R', 'e', 's', 'o', 'l', 'u', 't', 'i', 'o', 'n', ' ', 'N', 'o', 't', 'i', 'c', 'e', };
code UCHAR FR_ResolutionNoticeStr1[] = {18, 'A', 'v', 'i', 's', ' ', 'd', 'e', ' ', 'r', 2, 's', 'o', 'l', 'u', 't', 'i', 'o', 'n', };
code UCHAR GE_ResolutionNoticeStr1[] = {17, 'A', 'u', 'f', 'l', 10, 's', 'u', 'n', 'g', 's', 'h', 'i', 'n', 'w', 'e', 'i', 's', };
code UCHAR IT_ResolutionNoticeStr1[] = {18, 'A', 'v', 'v', 'i', 's', 'o', ' ', 'r', 'i', 's', 'o', 'l', 'u', 'z', 'i', 'o', 'n', 'e', };
code UCHAR SP_ResolutionNoticeStr1[] = {19, 'A', 'v', 'i', 's', 'o', ' ', 'd', 'e', ' ', 'r', 'e', 's', 'o', 'l', 'u', 'c', 'i', 4, 'n', };
code UCHAR PO_ResolutionNoticeStr1[] = {16, 'P', 'o', 'w', 'i', 'a', 'd', '.', ' ', 'o', ' ', 'r', 'o', 'z', 'd', 'z', '.', };
code UCHAR CZ_ResolutionNoticeStr1[] = {20, 'O', 'z', 'n', 0, 'm', 'e', 'n', 1, ' ', 'o', ' ', 'r', 'o', 'z', 'l', 'i', 20, 'e', 'n', 1, };
code UCHAR MA_ResolutionNoticeStr1[] = {17, 'F', 'e', 'l', 'b', 'o', 'n', 't', '.', 'm', 'e', 'g', 'j', 'e', 'g', 'y', 'z', '.', };
code UCHAR SE_ResolutionNoticeStr1[] = {19, 'U', 'p', 'i', 't', ' ', 'o', ' ', 'r', 'a', 'z', 'l', 'u', 6, 'i', 'v', 'o', 's', 't', 'i', };
code UCHAR RO_ResolutionNoticeStr1[] = {20, 'N', 'o', 't', 'i', 'f', 'i', 'c', 'a', 'r', 'e', ' ', 'r', 'e', 'z', 'o', 'l', 'u', 124, 'i', 'e', };
code UCHAR DU_ResolutionNoticeStr1[] = {16, 'R', 'e', 's', 'o', 'l', 'u', 't', 'i', 'e', 'm', 'e', 'l', 'd', 'i', 'n', 'g', };
code UCHAR RU_ResolutionNoticeStr1[] = {16, 173, 131, 128, 139, 136, 146, 127, '.', ' ', 136, ' ', 133, 143, 141, 133, '.', };
code UCHAR SW_ResolutionNoticeStr1[] = {18, 'U', 'p', 'p', 'l', 10, 's', 'n', 'i', 'n', 'g', 's', 'v', 'a', 'r', 'n', 'i', 'n', 'g', };
code UCHAR PR_ResolutionNoticeStr1[] = {18, 'A', 'v', 'i', 's', 'o', ' ', 'd', 'e', ' ', 'R', 'e', 's', 'o', 'l', 'u', 7, 123, 'o', };
code UCHAR JA_ResolutionNoticeStr1[] = {10, 180, 26, 124, 181, 182, 183, 184, 145, 155, 156, };
code UCHAR CT_ResolutionNoticeStr1[] = {5, 177, 178, 28, 179, 180, };
code UCHAR CS_ResolutionNoticeStr1[] = {5, 176, 177, 19, 178, 179, };
 
code UCHAR EN_InformationStr1[] = {11, 'I', 'n', 'f', 'o', 'r', 'm', 'a', 't', 'i', 'o', 'n', };
code UCHAR FR_InformationStr1[] = {11, 'I', 'n', 'f', 'o', 'r', 'm', 'a', 't', 'i', 'o', 'n', };
code UCHAR GE_InformationStr1[] = {13, 'I', 'n', 'f', 'o', 'r', 'm', 'a', 't', 'i', 'o', 'n', 'e', 'n', };
code UCHAR IT_InformationStr1[] = {12, 'I', 'n', 'f', 'o', 'r', 'm', 'a', 'z', 'i', 'o', 'n', 'i', };
code UCHAR SP_InformationStr1[] = {11, 'I', 'n', 'f', 'o', 'r', 'm', 'a', 'c', 'i', 4, 'n', };
code UCHAR PO_InformationStr1[] = {10, 'I', 'n', 'f', 'o', 'r', 'm', 'a', 'c', 'j', 'a', };
code UCHAR CZ_InformationStr1[] = {9, 'I', 'n', 'f', 'o', 'r', 'm', 'a', 'c', 'e', };
code UCHAR MA_InformationStr1[] = {6, 'I', 'n', 'f', 'o', '.', ' ', };
code UCHAR SE_InformationStr1[] = {11, 'I', 'n', 'f', 'o', 'r', 'm', 'a', 'c', 'i', 'j', 'e', };
code UCHAR RO_InformationStr1[] = {10, 'I', 'n', 'f', 'o', 'r', 'm', 'a', 124, 'i', 'i', };
code UCHAR DU_InformationStr1[] = {10, 'I', 'n', 'f', 'o', 'r', 'm', 'a', 't', 'i', 'e', };
code UCHAR RU_InformationStr1[] = {8, 164, 131, 128, 139, 128, 144, 124, 149, };
code UCHAR SW_InformationStr1[] = {11, 'I', 'n', 'f', 'o', 'r', 'm', 'a', 't', 'i', 'o', 'n', };
code UCHAR PR_InformationStr1[] = {10, 'I', 'n', 'f', 'o', 'r', 'm', 'a', 7, 123, 'o', };
code UCHAR JA_InformationStr1[] ={2, 206, 207, };
code UCHAR CT_InformationStr1[] ={2, 201, 8, };
code UCHAR CS_InformationStr1[] ={2, 8, 200, };

code UCHAR EN_DisplayPortStr1[] = {11, 'D','i','s','p','l','a','y','P','o','r','t' };
/*
code UCHAR FR_DisplayPortStr1[] = {11, 'D','i','s','p','l','a','y','P','o','r','t' };
code UCHAR GE_DisplayPortStr1[] = {11, 'D','i','s','p','l','a','y','P','o','r','t' };
code UCHAR IT_DisplayPortStr1[] = {11, 'D','i','s','p','l','a','y','P','o','r','t' };
code UCHAR SP_DisplayPortStr1[] = {11, 'D','i','s','p','l','a','y','P','o','r','t' };
code UCHAR PO_DisplayPortStr1[] = {11, 'D','i','s','p','l','a','y','P','o','r','t' };
code UCHAR CZ_DisplayPortStr1[] = {11, 'D','i','s','p','l','a','y','P','o','r','t' };
code UCHAR MA_DisplayPortStr1[] = {11, 'D','i','s','p','l','a','y','P','o','r','t' };
code UCHAR SE_DisplayPortStr1[] = {11, 'D','i','s','p','l','a','y','P','o','r','t' };
code UCHAR RO_DisplayPortStr1[] = {11, 'D','i','s','p','l','a','y','P','o','r','t' };
code UCHAR DU_DisplayPortStr1[] = {11, 'D','i','s','p','l','a','y','P','o','r','t' };
code UCHAR RU_DisplayPortStr1[] = {11, 'D','i','s','p','l','a','y','P','o','r','t' };
code UCHAR SW_DisplayPortStr1[] = {11, 'D','i','s','p','l','a','y','P','o','r','t' };
code UCHAR PR_DisplayPortStr1[] = {11, 'D','i','s','p','l','a','y','P','o','r','t' };
code UCHAR JA_DisplayPortStr1[] ={11, 'D','i','s','p','l','a','y','P','o','r','t' };
code UCHAR CT_DisplayPortStr1[] ={11, 'D','i','s','p','l','a','y','P','o','r','t' };
code UCHAR CS_DisplayPortStr1[] ={11, 'D','i','s','p','l','a','y','P','o','r','t' };
*/

code UCHAR EN_ResetAllStr1[] = {9, 'R', 'e', 's', 'e', 't', ' ', 'A', 'l', 'l', };
code UCHAR FR_ResetAllStr1[] = {13, 'R', 2, 't', 'a', 'b', 'l', 'i', 'r', ' ', 't', 'o', 'u', 't', };
code UCHAR GE_ResetAllStr1[] = {7, 'V', 'o', 'r', 'g', 'a', 'b', 'e', };
code UCHAR IT_ResetAllStr1[] = {15, 'R', 'e', 'i', 'm', 'p', 'o', 's', 't', 'a', ' ', 't', 'u', 't', 't', 'o', };
code UCHAR SP_ResetAllStr1[] = {16, 'R', 'e', 's', 't', 'a', 'b', 'l', 'e', 'c', '.', ' ', 'T', 'o', 'd', 'o', ' ', };
code UCHAR PO_ResetAllStr1[] = {15, 'R', 'e', 's', 'e', 't', '.', ' ', 'w', 's', 'z', 'y', 's', 't', '.', 5, };
code UCHAR CZ_ResetAllStr1[] = {12, 'O', 'b', 'n', 'o', 'v', 'i', 't', ' ', 'v', 20, 'e', 28, };
code UCHAR MA_ResetAllStr1[] = {10, 'A', 'l', 'a', 'p', 'h', 'e', 'l', 'y', '.', ' ', };
code UCHAR SE_ResetAllStr1[] = {13, 'R', 'e', 's', 'e', 't', 'i', 'r', 'a', 'j', ' ', 's', 'v', 'e', };
code UCHAR RO_ResetAllStr1[] = {21, 'R', 'e', 'i', 'n', 'i', 124, 'i', 'a', 'l', 'i', 'z', 'a', 'r', 'e', ' ', 't', 'o', 't', 'a', 'l', 125, };
code UCHAR DU_ResetAllStr1[] = {13, 'B', 'e', 'g', 'i', 'n', 'w', 'a', 'a', 'r', 'd', 'e', 'n', 28, };
code UCHAR RU_ResetAllStr1[] = {12, 164, 151, 133, 136, 125, 124, 132, 155, ' ', 131, 125, 128, };
code UCHAR SW_ResetAllStr1[] = {15, 124, 't', 'e', 'r', 's', 't', 3, 'l', 'l', ' ', 'a', 'l', 'l', 't', 28, };
code UCHAR PR_ResetAllStr1[] = {10, 'R', 'e', 'p', 'o', 'r', ' ', 't', 'u', 'd', 'o', };
code UCHAR JA_ResetAllStr1[] ={7, 208, 209, 184, 210, 181, 211, 208, };
code UCHAR CT_ResetAllStr1[] ={4, 181, 202, 203, 147, };
code UCHAR CS_ResetAllStr1[] ={4, 180, 201, 202, 145, };

code UCHAR *SystemTab[] = {
     EN_OSDSettingsStr1,
     FR_OSDSettingsStr1,
     GE_OSDSettingsStr1,
     IT_OSDSettingsStr1,
     SP_OSDSettingsStr1,
     PO_OSDSettingsStr1,
     CZ_OSDSettingsStr1,
     MA_OSDSettingsStr1,
     SE_OSDSettingsStr1,
     RO_OSDSettingsStr1,
     DU_OSDSettingsStr1,
     RU_OSDSettingsStr1,
     SW_OSDSettingsStr1,
     PR_OSDSettingsStr1,
     JA_OSDSettingsStr1,
     CT_OSDSettingsStr1,
     CS_OSDSettingsStr1,
     
     EN_CustomKey1Str1,
     FR_CustomKey1Str1,
     GE_CustomKey1Str1,
     IT_CustomKey1Str1,
     SP_CustomKey1Str1,
     PO_CustomKey1Str1,
     CZ_CustomKey1Str1,
     MA_CustomKey1Str1,
     SE_CustomKey1Str1,
     RO_CustomKey1Str1,
     DU_CustomKey1Str1,
     RU_CustomKey1Str1,
     SW_CustomKey1Str1,
     PR_CustomKey1Str1,
     JA_CustomKey1Str1,
     CT_CustomKey1Str1,
     CS_CustomKey1Str1,
     
     EN_CustomKey2Str1,
     FR_CustomKey2Str1,
     GE_CustomKey2Str1,
     IT_CustomKey2Str1,
     SP_CustomKey2Str1,
     PO_CustomKey2Str1,
     CZ_CustomKey2Str1,
     MA_CustomKey2Str1,
     SE_CustomKey2Str1,
     RO_CustomKey2Str1,
     DU_CustomKey2Str1,
     RU_CustomKey2Str1,
     SW_CustomKey2Str1,
     PR_CustomKey2Str1,
     JA_CustomKey2Str1,
     CT_CustomKey2Str1,
     CS_CustomKey2Str1,
     
     EN_CustomKey3Str1,
     FR_CustomKey3Str1,
     GE_CustomKey3Str1,
     IT_CustomKey3Str1,
     SP_CustomKey3Str1,
     PO_CustomKey3Str1,
     CZ_CustomKey3Str1,
     MA_CustomKey3Str1,
     SE_CustomKey3Str1,
     RO_CustomKey3Str1,
     DU_CustomKey3Str1,
     RU_CustomKey3Str1,
     SW_CustomKey3Str1,
     PR_CustomKey3Str1,
     JA_CustomKey3Str1,
     CT_CustomKey3Str1,
     CS_CustomKey3Str1,
     
     EN_DDCCiStr1,
     EN_DDCCiStr1,//FR
     EN_DDCCiStr1,//GE
     EN_DDCCiStr1,//IT
     EN_DDCCiStr1,//SP
     EN_DDCCiStr1,//PO
     EN_DDCCiStr1,//CZ
     EN_DDCCiStr1,//MA
     EN_DDCCiStr1,//SE
     EN_DDCCiStr1,//RO
     EN_DDCCiStr1,//DU
     EN_DDCCiStr1,//RU
     EN_DDCCiStr1,//SW
     EN_DDCCiStr1,//PR
     EN_DDCCiStr1,//JA
     EN_DDCCiStr1,//CT
     EN_DDCCiStr1,//CS

     EN_DPAutoSwitchStr1,
     FR_DPAutoSwitchStr1,
     GE_DPAutoSwitchStr1,
     IT_DPAutoSwitchStr1,
     SP_DPAutoSwitchStr1,
     PO_DPAutoSwitchStr1,
     CZ_DPAutoSwitchStr1,
     MA_DPAutoSwitchStr1,
     SE_DPAutoSwitchStr1,
     RO_DPAutoSwitchStr1,
     DU_DPAutoSwitchStr1,
     RU_DPAutoSwitchStr1,
     SW_DPAutoSwitchStr1,
     PR_DPAutoSwitchStr1,
     JA_DPAutoSwitchStr1,
     CT_DPAutoSwitchStr1,
     CS_DPAutoSwitchStr1,


     EN_HDMIAutoSwitchStr1,
     FR_HDMIAutoSwitchStr1,
     GE_HDMIAutoSwitchStr1,
     IT_HDMIAutoSwitchStr1,
     SP_HDMIAutoSwitchStr1,
     PO_HDMIAutoSwitchStr1,
     CZ_HDMIAutoSwitchStr1,
     MA_HDMIAutoSwitchStr1,
     SE_HDMIAutoSwitchStr1,
     RO_HDMIAutoSwitchStr1,
     DU_HDMIAutoSwitchStr1,
     RU_HDMIAutoSwitchStr1,
     SW_HDMIAutoSwitchStr1,
     PR_HDMIAutoSwitchStr1,
     JA_HDMIAutoSwitchStr1,
     CT_HDMIAutoSwitchStr1,
     CS_HDMIAutoSwitchStr1,



     EN_AutoPowerOffStr1,
     FR_AutoPowerOffStr1,
     GE_AutoPowerOffStr1,
     IT_AutoPowerOffStr1,
     SP_AutoPowerOffStr1,
     PO_AutoPowerOffStr1,
     CZ_AutoPowerOffStr1,
     MA_AutoPowerOffStr1,
     SE_AutoPowerOffStr1,
     RO_AutoPowerOffStr1,
     DU_AutoPowerOffStr1,
     RU_AutoPowerOffStr1,
     SW_AutoPowerOffStr1,
     PR_AutoPowerOffStr1,
     JA_AutoPowerOffStr1,
     CT_AutoPowerOffStr1,
     CS_AutoPowerOffStr1,
     
     EN_ResolutionNoticeStr1,
     FR_ResolutionNoticeStr1,
     GE_ResolutionNoticeStr1,
     IT_ResolutionNoticeStr1,
     SP_ResolutionNoticeStr1,
     PO_ResolutionNoticeStr1,
     CZ_ResolutionNoticeStr1,
     MA_ResolutionNoticeStr1,
     SE_ResolutionNoticeStr1,
     RO_ResolutionNoticeStr1,
     DU_ResolutionNoticeStr1,
     RU_ResolutionNoticeStr1,
     SW_ResolutionNoticeStr1,
     PR_ResolutionNoticeStr1,
     JA_ResolutionNoticeStr1,
     CT_ResolutionNoticeStr1,
     CS_ResolutionNoticeStr1,
     
     EN_InformationStr1,
     FR_InformationStr1,
     GE_InformationStr1,
     IT_InformationStr1,
     SP_InformationStr1,
     PO_InformationStr1,
     CZ_InformationStr1,
     MA_InformationStr1,
     SE_InformationStr1,
     RO_InformationStr1,
     DU_InformationStr1,
     RU_InformationStr1,
     SW_InformationStr1,
     PR_InformationStr1,
     JA_InformationStr1,
     CT_InformationStr1,
     CS_InformationStr1,

     EN_DisplayPortStr1,
     EN_DisplayPortStr1,//FR
     EN_DisplayPortStr1,//GE
     EN_DisplayPortStr1,//IT
     EN_DisplayPortStr1,//SP
     EN_DisplayPortStr1,//PO
     EN_DisplayPortStr1,//CZ
     EN_DisplayPortStr1,//MA
     EN_DisplayPortStr1,//SE
     EN_DisplayPortStr1,//RO
     EN_DisplayPortStr1,//DU
     EN_DisplayPortStr1,//RU
     EN_DisplayPortStr1,//SW
     EN_DisplayPortStr1,//PR
     EN_DisplayPortStr1,//JA
     EN_DisplayPortStr1,//CT
     EN_DisplayPortStr1,//CS

     
     EN_ResetAllStr1,
     FR_ResetAllStr1,
     GE_ResetAllStr1,
     IT_ResetAllStr1,
     SP_ResetAllStr1,
     PO_ResetAllStr1,
     CZ_ResetAllStr1,
     MA_ResetAllStr1,
     SE_ResetAllStr1,
     RO_ResetAllStr1,
     DU_ResetAllStr1,
     RU_ResetAllStr1,
     SW_ResetAllStr1,
     PR_ResetAllStr1,
     JA_ResetAllStr1,
     CT_ResetAllStr1,
     CS_ResetAllStr1,
};




// Top Page icon strings
code UCHAR EN_MenuStr1[] = {4,'M','e','n','u'};
code UCHAR FR_MenuStr1[] = {4,'M','e','n','u'};
code UCHAR GE_MenuStr1[] = {4,'M','e','n',23};
code UCHAR IT_MenuStr1[] = {4,'M','e','n','u'};
code UCHAR SP_MenuStr1[] = {4,'M','e','n',25};
code UCHAR PO_MenuStr1[] = {4,'M','e','n','u'};
code UCHAR CZ_MenuStr1[] = {7,'N','a','b',1,'d','k','a'};
code UCHAR MA_MenuStr1[] = {4,'M','e','n',23};
code UCHAR SE_MenuStr1[] = {8,'I','z','b','o','r','n','i','k'};
code UCHAR RO_MenuStr1[] = {5,'M','e','n','i','u'};
code UCHAR DU_MenuStr1[] = {4,'M','e','n','u'};
code UCHAR RU_MenuStr1[] = {4, 168,128,144,174,};
code UCHAR SW_MenuStr1[] = {4,'M','e','n','y'};
code UCHAR PR_MenuStr1[] = {4,'M','e','n','u'};
code UCHAR JA_MenuStr1[] = {4,172,224,197,21};
code UCHAR CT_MenuStr1[] = {3,91,92,240};
code UCHAR CS_MenuStr1[] = {2,244,245};

code UCHAR EN_ExitStr1[] = {4,'E','x','i','t'};
code UCHAR FR_ExitStr1[] = {7,'Q','u','i','t','t','e','r'};
code UCHAR GE_ExitStr1[] = {5,'B','e','e','n',46};
code UCHAR IT_ExitStr1[] = {4,'E','s','c','i'};
code UCHAR SP_ExitStr1[] = {5,'S','a','l','i','r'};
code UCHAR PO_ExitStr1[] = {7,'Z','a','k','o',132,'c','z'};
code UCHAR CZ_ExitStr1[] = {5,'K','o','n','e','c'};
code UCHAR MA_ExitStr1[] = {6,'K','i','l',2,'p',32};
code UCHAR SE_ExitStr1[] = {5,'I','z','l','a','z'};
code UCHAR RO_ExitStr1[] = {6,'I','e',123,'i','r','e'};
code UCHAR DU_ExitStr1[] = {5,'A','f','s','l','t'};
code UCHAR RU_ExitStr1[] = {5, 137,159,138,136,139,};
code UCHAR SW_ExitStr1[] = {7,'A','v','s','l','u','t','a'};
code UCHAR PR_ExitStr1[] = {4,'S','a','i','r'};
code UCHAR JA_ExitStr1[] = {2,91,92};
code UCHAR CT_ExitStr1[] = {2,255,96};
code UCHAR CS_ExitStr1[] = {2,253 ,254};

//ULEric140402
code UCHAR EN_LowBlueLightStr1[]={14, 'L', 'o', 'w', ' ', 'B', 'l', 'u', 'e', ' ', 'L', 'i', 'g', 'h', 't', };
code UCHAR JA_LowBlueLightStr1[]={8,163,164,21,30,165,29,166,167}; 
code UCHAR CT_LowBlueLightStr1[]={3,153,127,154};
code UCHAR CS_LowBlueLightStr1[]={3,152,128,153};
/*
code UCHAR FR_LowBlueLightStr1[]={16, 'F', 'a', 'i', 'b', 'l', 'e', ' ', 'l', 'u', 'm', '.', 'b', 'l', 'e', 'u', 'e', };
code UCHAR GE_LowBlueLightStr1[]={16, 'H', 'e', 'l', 'l', 'b', 'l', 'a', 'u', 'e', 's', ' ', 'L', 'i', 'c', 'h', 't', };
code UCHAR IT_LowBlueLightStr1[]={15, 'R', 'i', 'd', 'u', 'z', '.', ' ', 'l', 'u', 'c', 'e', ' ', 'b', 'l', 'u', };
code UCHAR SP_LowBlueLightStr1[]={13, 'L', 'u', 'z', ' ', 'a', 'z', 'u', 'l', ' ', 'b', 'a', 'j', 'a', };
code UCHAR PO_LowBlueLightStr1[]={16, 'N', 'i', 's', '.', ' ', 'i', 'l', '.', 'n', 'i', 'e', 'b', '.', ' ', 127, 'w', };
code UCHAR CZ_LowBlueLightStr1[]={15, 'S', 'l', 'a', 'b', 2, ' ', 'm', 'o', 'd', 'r', 2, ' ', 's', 'v', '.', };
code UCHAR MA_LowBlueLightStr1[]={15, 'H', 'a', 'l', 'v', 0, 'n', 'y', 'k', 2, 'k', ' ', 'f', 2, 'n', 'y', };
code UCHAR SE_LowBlueLightStr1[]={16, 'P', 'r', 'i', 'g', 'u', 20, 'e', 'n', 'j', 'e', ' ', 'p', 'l', 'a', 'v', 'e', };
code UCHAR RO_LowBlueLightStr1[]={16, 'L', 'u', 'm', '.', ' ', 'a', 'l', 'b', 'a', 's', '.', ' ', 'r', 'e', 'd', '.', };
code UCHAR DU_LowBlueLightStr1[]={16, 'Z', 'a', 'c', 'h', 't', 'b', 'l', 'a', 'u', 'w', ' ', 'l', 'i', 'c', 'h', 't', };
code UCHAR RU_LowBlueLightStr1[]={16, 170, 127, 136, 148, 124, 133, '.', ' ', 125, 124, 144, '.', ' ', 171, 131, '.', };
code UCHAR SW_LowBlueLightStr1[]={16, 'S', 'v', 'a', 'g', 't', ' ', 'b', 'l', 123, 't', 't', ' ', 'l', 'j', 'u', 's', };
code UCHAR PR_LowBlueLightStr1[]={14, 'L', 'u', 'z', ' ', 'A', 'z', 'u', 'l', ' ', 'B', 'a', 'i', 'x', 'a', };
code UCHAR JA_LowBlueLightStr1[]={8, 163, 164, 21, 30, 165, 29, 166, 167, };
code UCHAR CT_LowBlueLightStr1[]={3, 153, 127, 154, };
code UCHAR CS_LowBlueLightStr1[]={3, 152, 128, 153, };
*/
code UCHAR EN_SmartReminderStr1[]={14, 'S', 'm', 'a', 'r', 't', ' ', 'R', 'e', 'm', 'i', 'n', 'd', 'e', 'r', };
code UCHAR FR_SmartReminderStr1[]={18, 'R', 'a', 'p', 'p', 'e', 'l', ' ', 'I', 'n', 't', 'e', 'l', 'l', 'i', 'g', 'e', 'n', 't', };
code UCHAR GE_SmartReminderStr1[]={18, 'I', 'n', 't', 'e', 'l', 'l', '.', ' ', 'E', 'r', 'i', 'n', 'n', 'e', 'r', 'u', 'n', 'g', };
code UCHAR IT_SmartReminderStr1[]={20, 'P', 'r', 'o', 'm', 'e', 'm', 'o', 'r', 'i', 'a', ' ', 'i', 'n', 't', 'e', 'l', 'l', 'i', 'g', '.', };
code UCHAR SP_SmartReminderStr1[]={17, 'A', 'v', 'i', 's', 'o', ' ', 'i', 'n', 't', 'e', 'l', 'i', 'g', 'e', 'n', 't', 'e', };
code UCHAR PO_SmartReminderStr1[]={19, 'I', 'n', 't', 'e', 'l', 'i', 'g', 'e', 'n', 't', 'n', 'e', ' ', 'p', 'r', 'z', 'y', 'p', '.', };
code UCHAR CZ_SmartReminderStr1[]={20, 'I', 'n', 't', 'e', 'l', 'i', 'g', 'e', 'n', 't', 'n', 1, ' ', 'p', 124, 'i', 'p', 'o', 'm', '.', };
code UCHAR MA_SmartReminderStr1[]={19, 'I', 'n', 't', 'e', 'l', 'l', '.', ' ', 'e', 'm', 'l', 2, 'k', 'e', 'z', 't', 'e', 't', 123, };
code UCHAR SE_SmartReminderStr1[]={18, 'P', 'a', 'm', 'e', 't', 'n', 'i', ' ', 'p', 'o', 'd', 's', 'j', 'e', 't', 'n', 'i', 'k', };
code UCHAR RO_SmartReminderStr1[]={18, 'M', 'e', 'm', 'e', 'n', 't', 'o', ' ', 'i', 'n', 't', 'e', 'l', 'i', 'g', 'e', 'n', 't', };
code UCHAR DU_SmartReminderStr1[]={19, 'S', 'l', 'i', 'm', 'm', 'e', 'r', ' ', 'h', 'e', 'r', 'i', 'n', 'n', 'e', 'r', 'i', 'n', 'g', };
code UCHAR RU_SmartReminderStr1[]={17, 173, 146, 144, 136, 128, ' ', 144, 143, 126, 136, 146, 124, 144, 143, 144, 124, 128, };
code UCHAR SW_SmartReminderStr1[]={16, 'S', 'm', 'a', 'r', 't', ' ', 'p', 123, 'm', 'i', 'n', 'n', 'e', 'l', 's', 'e', };
code UCHAR PR_SmartReminderStr1[]={20, 'L', 'e', 'm', 'b', 'r', 'e', 't', 'e', ' ', 'I', 'n', 't', 'e', 'l', 'i', 'g', 'e', 'n', 't', 'e', };
code UCHAR JA_SmartReminderStr1[]={6, 31, 130, 21, 29, 244, 245, };
code UCHAR CT_SmartReminderStr1[]={4, 241, 242, 179, 180, };
code UCHAR CS_SmartReminderStr1[]={4, 239, 240, 241, 242, };

code UCHAR *TopPageStrTab[] = {
     EN_PictureModeStr1,
     FR_PictureModeStr1,
     GE_PictureModeStr1,
     IT_PictureModeStr1,
     SP_PictureModeStr1,
     PO_PictureModeStr1,
     CZ_PictureModeStr1,
     MA_PictureModeStr1,
     SE_PictureModeStr1,
     RO_PictureModeStr1,
     DU_PictureModeStr1,
     RU_PictureModeStr1,
     SW_PictureModeStr1,
     PR_PictureModeStr1,
     JA_PictureModeStr1,
     CT_PictureModeStr1,
     CS_PictureModeStr1,
     
     EN_DisplayModeStr1,
     FR_DisplayModeStr1,
     GE_DisplayModeStr1,
     IT_DisplayModeStr1,
     SP_DisplayModeStr1,
     PO_DisplayModeStr1,
     CZ_DisplayModeStr1,
     MA_DisplayModeStr1,
     SE_DisplayModeStr1,
     RO_DisplayModeStr1,
     DU_DisplayModeStr1,
     RU_DisplayModeStr1,
     SW_DisplayModeStr1,
     PR_DisplayModeStr1,
     JA_DisplayModeStr1,
     CT_DisplayModeStr1,
     CS_DisplayModeStr1,
     
     EN_BrightnessStr1,
     FR_BrightnessStr1,
     GE_BrightnessStr1,
     IT_BrightnessStr1,
     SP_BrightnessStr1,
     PO_BrightnessStr1,
     CZ_BrightnessStr1,
     MA_BrightnessStr1,
     SE_BrightnessStr1,
     RO_BrightnessStr1,
     DU_BrightnessStr1,
     RU_BrightnessStr1,
     SW_BrightnessStr1,
     PR_BrightnessStr1,
     JA_BrightnessStr1,
     CT_BrightnessStr1,
     CS_BrightnessStr1,
     
     EN_ContrastStr1,
     FR_ContrastStr1,
     GE_ContrastStr1,
     IT_ContrastStr1,
     SP_ContrastStr1,
     PO_ContrastStr1,
     CZ_ContrastStr1,
     MA_ContrastStr1,
     SE_ContrastStr1,
     RO_ContrastStr1,
     DU_ContrastStr1,
     RU_ContrastStr1,
     SW_ContrastStr1,
     PR_ContrastStr1,
     JA_ContrastStr1,
     CT_ContrastStr1,
     CS_ContrastStr1,
     
     EN_AutoAdjustmentStr1,
     FR_AutoAdjustmentStr1,
     GE_AutoAdjustmentStr1,
     IT_AutoAdjustmentStr1,
     SP_AutoAdjustmentStr1,
     PO_AutoAdjustmentStr1,
     CZ_AutoAdjustmentStr1,
     MA_AutoAdjustmentStr1,
     SE_AutoAdjustmentStr1,
     RO_AutoAdjustmentStr1,
     DU_AutoAdjustmentStr1,
     RU_AutoAdjustmentStr1,
     SW_AutoAdjustmentStr1,
     PR_AutoAdjustmentStr1,
     JA_AutoAdjustmentStr1,
     CT_AutoAdjustmentStr1,
     CS_AutoAdjustmentStr1,
     
     EN_InputStr1,
     FR_InputStr1,
     GE_InputStr1,
     IT_InputStr1,
     SP_InputStr1,
     PO_InputStr1,
     CZ_InputStr1,
     MA_InputStr1,
     SE_InputStr1,
     RO_InputStr1,
     DU_InputStr1,
     RU_InputStr1,
     SW_InputStr1,
     PR_InputStr1,
     JA_InputStr1,
     CT_InputStr1,
     CS_InputStr1,
     
     //ULEric140402
     EN_VolumeStr1,
     FR_VolumeStr1,
     GE_VolumeStr1,
     IT_VolumeStr1,
     SP_VolumeStr1,
     PO_VolumeStr1,
     CZ_VolumeStr1,
     MA_VolumeStr1,
     SE_VolumeStr1,
     RO_VolumeStr1,
     DU_VolumeStr1,
     RU_VolumeStr1,
     SW_VolumeStr1,
     PR_VolumeStr1,
     JA_VolumeStr1,
     CT_VolumeStr1,
     CS_VolumeStr1,
     
     EN_MuteStr1,
     FR_MuteStr1,
     GE_MuteStr1,
     IT_MuteStr1,
     SP_MuteStr1,
     PO_MuteStr1,
     CZ_MuteStr1,
     MA_MuteStr1,
     SE_MuteStr1,
     RO_MuteStr1,
     DU_MuteStr1,
     RU_MuteStr1,
     SW_MuteStr1,
     PR_MuteStr1,
     JA_MuteStr1,
     CT_MuteStr1,
     CS_MuteStr1,
     
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     JA_LowBlueLightStr1,
     CT_LowBlueLightStr1,
     CS_LowBlueLightStr1,
     
     EN_SmartReminderStr1,
     FR_SmartReminderStr1,
     GE_SmartReminderStr1,
     IT_SmartReminderStr1,
     SP_SmartReminderStr1,
     PO_SmartReminderStr1,
     CZ_SmartReminderStr1,
     MA_SmartReminderStr1,
     SE_SmartReminderStr1,
     RO_SmartReminderStr1,
     DU_SmartReminderStr1,
     RU_SmartReminderStr1,
     SW_SmartReminderStr1,
     PR_SmartReminderStr1,
     JA_SmartReminderStr1,
     CT_SmartReminderStr1,
     CS_SmartReminderStr1,
     
     EN_MenuStr1,
     FR_MenuStr1,
     GE_MenuStr1,
     IT_MenuStr1,
     SP_MenuStr1,
     PO_MenuStr1,
     CZ_MenuStr1,
     MA_MenuStr1,
     SE_MenuStr1,
     RO_MenuStr1,
     DU_MenuStr1,
     RU_MenuStr1,
     SW_MenuStr1,
     PR_MenuStr1,
     JA_MenuStr1,
     CT_MenuStr1,
     CS_MenuStr1,
     
     EN_ExitStr1,
     FR_ExitStr1,
     GE_ExitStr1,
     IT_ExitStr1,
     SP_ExitStr1,
     PO_ExitStr1,
     CZ_ExitStr1,
     MA_ExitStr1,
     SE_ExitStr1,
     RO_ExitStr1,
     DU_ExitStr1,
     RU_ExitStr1,
     SW_ExitStr1,
     PR_ExitStr1,
     JA_ExitStr1,
     CT_ExitStr1,
     CS_ExitStr1,
 };



code UCHAR EN_AutoDialogStr[] = {15, 'A', 'u', 't', 'o', ' ', 'A', 'd', 'j', 'u', 's', 't', 'i', 'n', 'g', 11, };
code UCHAR FR_AutoDialogStr[] = {24, 'A', 'j', 'u', 's', 't', 'e', 'm', 'e', 'n', 't', ' ', 5, 'a', 'u', 't', 'o', 'm', 'a', 't', 'i', 'q', 'u', 'e', 11, };
code UCHAR GE_AutoDialogStr[] = {27, 'A', 'u', 't', 'o', '.', ' ', 'E', 'i', 'n', 's', 't', 'e', 'l', 'l', 'u', 'n', 'g', ' ', 5, 'l', 3, 'u', 'f', 't', '.', '.', '.', };
code UCHAR IT_AutoDialogStr[] = {23, 'R', 'e', 'g', 'o', 'l', 'a', 'z', 'i', 'o', 'n', 'e', ' ', 'a', 'u', 't', 'o', 'm', 'a', 't', 'i', 'c', 'a', 11, };
code UCHAR SP_AutoDialogStr[] = {28, 'A', 'j', 'u', 's', 't', 'a', 'n', 'd', 'o', ' ', 'a', 'u', 't', 'o', 'm', 0, 't', 'i', 'c', 'a', 'm', 'e', 'n', 't', 'e', '.', '.', '.', };
code UCHAR PO_AutoDialogStr[] = {23, 'A', 'u', 't', 'o', 'm', 'a', 't', 'y', 'c', 'z', 'n', 'a', ' ', 'r', 'e', 'g', 'u', 'l', 'a', 'c', 'j', 'a', 11, };
code UCHAR CZ_AutoDialogStr[] = {22, 'A', 'u', 't', 'o', 'm', 'a', 't', 'i', 'c', 'k', 2, ' ', 'n', 'a', 's', 't', 'a', 'v', 'e', 'n', 1, 11, };
code UCHAR MA_AutoDialogStr[] = {15, 'A', 'u', 't', '.', ' ', 'B', 'e', 0, 'l', 'l', 1, 't', 0, 's', 11, };
code UCHAR SE_AutoDialogStr[] = {17, 'A', 'u', 't', 'o', ' ', 'p', 'o', 'd', 'e', 20, 'a', 'v', 'a', 'n', 'j', 'e', 11, };
code UCHAR RO_AutoDialogStr[] = {17, 'R', 'e', 'g', 'l', 'a', 'r', 'e', ' ', 'a', 'u', 't', 'o', 'm', 'a', 't', 125, 11, };
code UCHAR DU_AutoDialogStr[] = {16, 'A', 'u', 't', 'o', '-', 'a', 'a', 'n', 'p', 'a', 's', 's', 'i', 'n', 'g', 11, };
code UCHAR RU_AutoDialogStr[] = {27, 130, 131, 132, 136, 146, 143, 132, 124, 147, 128, 125, 148, 143, 149, ' ', 133, 128, 134, 135, 127, 124, 133, 136, 131, 148, 143, 11, };
code UCHAR SW_AutoDialogStr[] = {21, 'A', 'u', 't', 'o', 'm', 'a', 't', 'i', 's', 'k', ' ', 'j', 'u', 's', 't', 'e', 'r', 'i', 'n', 'g', 11, };
code UCHAR PR_AutoDialogStr[] = {17, 'A', ' ', 'a', 'j', 'u', 's', 't', 'a', 'r', ' ', 'a', 'u', 't', 'o', 11, ' ', 5, };
code UCHAR JA_AutoDialogStr[] = {6, 0, 1, 2, 3, 4, 5,};
code UCHAR CT_AutoDialogStr[] = {6, 0, 1, 2, 3, 4, 5,};
code UCHAR CS_AutoDialogStr[] = {6, 0, 1, 2, 3, 4, 5,};
 

code UCHAR *AutoStrTab[] = {
     EN_AutoDialogStr,
     FR_AutoDialogStr,
     GE_AutoDialogStr,
     IT_AutoDialogStr,
     SP_AutoDialogStr,
     PO_AutoDialogStr,
     CZ_AutoDialogStr,
     MA_AutoDialogStr,
     SE_AutoDialogStr,
     RO_AutoDialogStr,
     DU_AutoDialogStr,
     RU_AutoDialogStr,
     SW_AutoDialogStr,
     PR_AutoDialogStr,
     JA_AutoDialogStr,
     CT_AutoDialogStr,
     CS_AutoDialogStr,
};


 code UCHAR EN_OSDLCOKEDStr[]={10, 'O', 'S', 'D', ' ', 'l', 'o', 'c', 'k', 'e', 'd', };
 code UCHAR FR_OSDLCOKEDStr[]={14, 'O', 'S', 'D', ' ', 'v', 'e', 'r', 'r', 'o', 'u', 'i', 'l', 'l', 2, };
 code UCHAR GE_OSDLCOKEDStr[]={12, 'O', 'S', 'D', ' ', 'g', 'e', 's', 'p', 'e', 'r', 'r', 't', };
 code UCHAR IT_OSDLCOKEDStr[]={12, 'O', 'S', 'D', ' ', 'b', 'l', 'o', 'c', 'c', 'a', 't', 'o', };
 code UCHAR SP_OSDLCOKEDStr[]={13, 'O', 'S', 'D', ' ', 'b', 'l', 'o', 'q', 'u', 'e', 'a', 'd', 'o', };
 code UCHAR PO_OSDLCOKEDStr[]={14, 'M', 'e', 'n', 'u', ' ', 'e', 'k', 'r', '.', ' ', 'z', 'a', 'b', 'l', };
 code UCHAR CZ_OSDLCOKEDStr[]={11, 'Z', 'a', 'm', 6, 'e', 'n', 'o', ' ', 'O', 'S', 'D', };
 code UCHAR MA_OSDLCOKEDStr[]={11, 'O', 'S', 'D', ' ', 'z', 0, 'r', 'o', 'l', 'v', 'a', };
 code UCHAR SE_OSDLCOKEDStr[]={12, 'O', 'S', 'D', ' ', 'b', 'l', 'o', 'k', 'i', 'r', 'a', 'n', };
 code UCHAR RO_OSDLCOKEDStr[]={12, 'M', 'e', 'n', 'i', 'u', ' ', 'b', 'l', 'o', 'c', 'a', 't', };
 code UCHAR DU_OSDLCOKEDStr[]={15, 'O', 'S', 'D', ' ', 'g', 'e', 'b', 'l', 'o', 'k', 'k', 'e', 'e', 'r', 'd', };
 code UCHAR RU_OSDLCOKEDStr[]={11, 168, 128, 144, 174, ' ', 141, 143, 151, 127, 136, 148, };
 code UCHAR SW_OSDLCOKEDStr[]={14, 'O', 'S', 'D', ' ', 'm', 'e', 'n', 'y', 'n', ' ', 'l', 123, 's', 't', };
 code UCHAR PR_OSDLCOKEDStr[]={13, 'O', 'S', 'D', ' ', 'b', 'l', 'o', 'q', 'u', 'e', 'a', 'd', 'o', };
 code UCHAR JA_OSDLCOKEDStr[]={9, 'O', 'S', 'D', ' ', 188, 15, 134, 189, 190, };
 code UCHAR CT_OSDLCOKEDStr[]={7, 'O', 'S', 'D', ' ', 190, 191, 192, };
 code UCHAR CS_OSDLCOKEDStr[]={7, 'O', 'S', 'D', ' ', 186, 187, 188, };

 code UCHAR EN_OSDUNLCOKEDStr[]={12, 'O', 'S', 'D', ' ', 'u', 'n', 'l', 'o', 'c', 'k', 'e', 'd', };
 code UCHAR FR_OSDUNLCOKEDStr[]={16, 'O', 'S', 'D', ' ', 'd', 2, 'v', 'e', 'r', 'r', 'o', 'u', 'i', 'l', 'l', 2, };
 code UCHAR GE_OSDUNLCOKEDStr[]={13, 'O', 'S', 'D', ' ', 'e', 'n', 't', 's', 'p', 'e', 'r', 'r', 't', };
 code UCHAR IT_OSDUNLCOKEDStr[]={13, 'O', 'S', 'D', ' ', 's', 'b', 'l', 'o', 'c', 'c', 'a', 't', 'o', };
 code UCHAR SP_OSDUNLCOKEDStr[]={16, 'O', 'S', 'D', ' ', 'n', 'o', ' ', 'b', 'l', 'o', 'q', 'u', 'e', 'a', 'd', 'o', };
 code UCHAR PO_OSDUNLCOKEDStr[]={14, 'M', 'e', 'n', 'u', ' ', 'e', 'k', 'r', '.', ' ', 'o', 'd', 'b', 'l', };
 code UCHAR CZ_OSDUNLCOKEDStr[]={12, 'O', 'd', 'e', 'm', 6, 'e', 'n', 'o', ' ', 'O', 'S', 'D', };
 code UCHAR MA_OSDUNLCOKEDStr[]={12, 'O', 'S', 'D', ' ', 'f', 'e', 'l', 'o', 'l', 'd', 'v', 'a', };
 code UCHAR SE_OSDUNLCOKEDStr[]={14, 'O', 'S', 'D', ' ', 'o', 'd', 'b', 'l', 'o', 'k', 'i', 'r', 'a', 'n', };
 code UCHAR RO_OSDUNLCOKEDStr[]={14, 'M', 'e', 'n', 'i', 'u', ' ', 'd', 'e', 'b', 'l', 'o', 'c', 'a', 't', };
 code UCHAR DU_OSDUNLCOKEDStr[]={15, 'O', 'S', 'D', ' ', 'v', 'r', 'i', 'j', 'g', 'e', 'g', 'e', 'v', 'e', 'n', };
 code UCHAR RU_OSDUNLCOKEDStr[]={12, 168, 128, 144, 174, ' ', 133, 143, 141, 151, 127, 136, 148, };
 code UCHAR SW_OSDUNLCOKEDStr[]={11, 'O', 'S', 'D', ' ', 'u', 'p', 'p', 'l', 123, 's', 't', };
 code UCHAR PR_OSDUNLCOKEDStr[]={16, 'O', 'S', 'D', ' ', 'd', 'e', 's', 'b', 'l', 'o', 'q', 'u', 'e', 'a', 'd', 'o', };
 code UCHAR JA_OSDUNLCOKEDStr[]={9, 'O', 'S', 'D', ' ', 188, 15, 134, 191, 192, };
 code UCHAR CT_OSDUNLCOKEDStr[]={7, 'O', 'S', 'D', ' ', 190, 193, 191, };
 code UCHAR CS_OSDUNLCOKEDStr[]={7, 'O', 'S', 'D', ' ', 186, 189, 187, };

code UCHAR *OSDLOckStrTab[] = {
EN_OSDUNLCOKEDStr,
FR_OSDUNLCOKEDStr,
GE_OSDUNLCOKEDStr,
IT_OSDUNLCOKEDStr,
SP_OSDUNLCOKEDStr,
PO_OSDUNLCOKEDStr,
CZ_OSDUNLCOKEDStr,
MA_OSDUNLCOKEDStr,
SE_OSDUNLCOKEDStr,
RO_OSDUNLCOKEDStr,
DU_OSDUNLCOKEDStr,
RU_OSDUNLCOKEDStr,
SW_OSDUNLCOKEDStr,
PR_OSDUNLCOKEDStr,
JA_OSDUNLCOKEDStr,
CT_OSDUNLCOKEDStr,
CS_OSDUNLCOKEDStr,
    
EN_OSDLCOKEDStr,
FR_OSDLCOKEDStr,
GE_OSDLCOKEDStr,
IT_OSDLCOKEDStr,
SP_OSDLCOKEDStr,
PO_OSDLCOKEDStr,
CZ_OSDLCOKEDStr,
MA_OSDLCOKEDStr,
SE_OSDLCOKEDStr,
RO_OSDLCOKEDStr,
DU_OSDLCOKEDStr,
RU_OSDLCOKEDStr,
SW_OSDLCOKEDStr,
PR_OSDLCOKEDStr,
JA_OSDLCOKEDStr,
CT_OSDLCOKEDStr,
CS_OSDLCOKEDStr,


    
};

  code UCHAR EN_OSDUNLCOKKEYStr[]={26, 'P', 'r', 'e', 's', 's', ' ', 'a', 'n', 'd', ' ', 'h', 'o', 'l', 'd', ' ', 'a', 'n', 'y', ' ', 'k', 'e', 'y', ' ', 'f', 'o', 'r' ,' ',};
  code UCHAR EN_OSDUNLCOKKEYStr2[]={25, '1', '0', ' ', 's', 'e', 'c', 'o', 'n', 'd', 's', ' ', 't', 'o', ' ', 'u', 'n', 'l', 'o', 'c', 'k', ' ', 'O', 'S', 'D', ' ' };
  
  code UCHAR FR_OSDUNLCOKKEYStr[]={37, 'M', 'a', 'i', 'n', 't', 'e', 'n', 'e', 'z', ' ', 'u', 'n', 'e', ' ', 't', 'o', 'u', 'c', 'h', 'e', ' ', 'a', 'p', 'p', 'u', 'y', 2, 'e', ' ', 'p', 'e', 'n', 'd', 'a', 'n', 't', ' ',};
  code UCHAR FR_OSDUNLCOKKEYStr2[]={29,    '1', '0', ' ', 's', ' ', 'p', 'o', 'u', 'r', ' ', 'd', 2, 'v', 'e', 'r', 'r', 'o', 'u', 'i', 'l', 'l', 'e', 'r', ' ', 'l', 39, 'O', 'S', 'D', };//ULEric140423
  
  code UCHAR GE_OSDUNLCOKKEYStr[]={44, 'H', 'a', 'l', 't', 'e', 'n', ' ', 'S', 'i', 'e', ' ', 'e', 'i', 'n', 'e', ' ', 'b', 'e', 'l', 'i', 'e', 'b', 'i', 'g', 'e', ' ', 'T', 'a', 's', 't', 'e', ' ','1', '0', ' ', 'S', 'e', 'k', 'u', 'n', 'd', 'e', 'n', ' ', };
  code UCHAR GE_OSDUNLCOKKEYStr2[]={39,  'l', 'a', 'n', 'g', ' ', 'g', 'e', 'd', 'r', 23, 'c', 'k', 't', ',', ' ', 'u', 'm', ' ', 'd', 'a', 's', ' ', 'O', 'S', 'D', ' ', 'z', 'u', ' ', 'e', 'n', 't', 's', 'p', 'e', 'r', 'r', 'e', 'n', };
  
  code UCHAR IT_OSDUNLCOKKEYStr[]={34, 'T', 'e', 'n', 'e', 'r', 'e', ' ', 'p', 'r', 'e', 'm', 'u', 't', 'o', ' ', 'u', 'n', ' ', 't', 'a', 's', 't', 'o', ' ', 'q', 'u', 'a', 'l', 's', 'i', 'a', 's', 'i', ' ', };
  code UCHAR IT_OSDUNLCOKKEYStr2[]={34, 'p', 'e', 'r', ' ', '1', '0', ' ', 's', 'e', 'c', 'o', 'n', 'd', 'i', ' ', 'p', 'e', 'r', ' ', 's', 'b', 'l', 'o', 'c', 'c', 'a', 'r', 'e', ' ', 'l', 39, 'O', 'S', 'D', };
  
  code UCHAR SP_OSDUNLCOKKEYStr[]={41, 'M', 'a', 'n', 't', 'e', 'n', 'g', 'a', ' ', 'p', 'u', 'l', 's', 'a', 'd', 'a', ' ', 'c', 'u', 'a', 'l', 'q', 'u', 'i', 'e', 'r', ' ', 't', 'e', 'c', 'l', 'a', ' ', 'd', 'u', 'r', 'a', 'n', 't', 'e', ' ',};
  code UCHAR SP_OSDUNLCOKKEYStr2[]={32, '1', '0', ' ', 's', 'e', 'g', 'u', 'n', 'd', 'o', 's', ' ', 'p', 'a', 'r', 'a', ' ', 'd', 'e', 's', 'b', 'l', 'o', 'q', 'u', 'e', 'a', 'r', ' ', 'O', 'S', 'D', };

  
  code UCHAR PO_OSDUNLCOKKEYStr[]={40, 'N', 'a', 'c', 'i', 123, 'n', 'i', 'j', ' ', 'i', ' ', 'p', 'r', 'z', 'y', 't', 'r', 'z', 'y', 'm', 'a', 'j', ' ', 'd', 'o', 'w', 'o', 'l', 'n', 'y', ' ', 'p', 'r', 'z', 'y', 'c', 'i', 's', 'k', ' ',};
  code UCHAR PO_OSDUNLCOKKEYStr2[]={45, 'p', 'r', 'z', 'e', 'z', ' ', '1', '0', ' ', 's', 'e', 'k', 'u', 'n', 'd', ',', ' ', 'a', 'b', 'y', ' ', 'o', 'd', 'b', 'l', 'o', 'k', 'o', 'w', 'a', 22, ' ', 'm', 'e', 'n', 'u', ' ', 'e', 'k', 'r', 'a', 'n', 'o', 'w', 'e', };
  
  code UCHAR CZ_OSDUNLCOKKEYStr[]={38, 'P', 'r', 'o', ' ', 'o', 'd', 'e', 'm', 6, 'e', 'n', 1, ' ', 'O', 'S', 'D', ' ', 's', 't', 'i', 's', 'k', 'n', 127, 't', 'e', ' ', 'a', ' ', 'p', 124, 'i', 'd', 'r', 26, 't', 'e', ' '};
  code UCHAR CZ_OSDUNLCOKKEYStr2[]={31, 'l', 'i', 'b', 'o', 'v', 'o', 'l', 'n', 2, ' ', 't', 'l', 'a', 6, 1, 't', 'k', 'o', ' ', 'p', 'o', ' ', '1', '0', ' ', 's', 'e', 'k', 'u', 'n', 'd', };
  
  code UCHAR MA_OSDUNLCOKKEYStr[]={35, 'A', 'z', ' ', 'O', 'S', 'D', ' ', 'f', 'e', 'l', 'o', 'l', 'd', 0, 's', 0, 'h', 'o', 'z', ' ', '1', '0', ' ','m', 0, 's', 'o', 'd', 'p', 'e', 'r', 'c', 'i', 'g', ' ', };
  code UCHAR MA_OSDUNLCOKKEYStr2[]={33, 't', 'a', 'r', 't', 's', 'a', ' ', 'l', 'e', 'n', 'y', 'o', 'm', 'v', 'a', ' ', 'v', 'a', 'l', 'a', 'm', 'e', 'l', 'y', 'i', 'k', ' ', 'g', 'o', 'm', 'b', 'o', 't', };
  
  code UCHAR SE_OSDUNLCOKKEYStr[]={39, 'P', 'r', 'i', 't', 'i', 's', 'n', 'i', 't', 'e', ' ', 'i', ' ', 'd', 'r', 26, 'i', 't', 'e', ' ', 'b', 'i', 'l', 'o', ' ','t', 'i', 'p', 'k', 'u', ' ', 't', 'i', 'j', 'e', 'k', 'o', 'm', ' '};
  code UCHAR SE_OSDUNLCOKKEYStr2[]={32,  '1', '0', ' ', 's', 'e', 'k', 'u', 'n', 'd', 'i', ' ', 'z', 'a', ' ', 'o', 'd', 'b', 'l', 'o', 'k', 'i', 'r', 'a', 'n', 'j', 'e', ' ', 'O', 'S', 'D', '-', 'a', };
  
  code UCHAR RO_OSDUNLCOKKEYStr[]={33, 'A', 'p', 125, 's', 'a', 124, 'i', ' ', 'l', 'u', 'n', 'g', ' ', 'o', 'r', 'i', 'c', 'e', ' ', 't', 'a', 's', 't', 125, ' ', 't', 'i', 'm', 'p', ' ', 'd', 'e', ' ', };
  code UCHAR RO_OSDUNLCOKKEYStr2[]={34,  '1', '0', ' ', 's', 'e', 'c', 'u', 'n', 'd', 'e', ' ', 'p', 'e', 'n', 't', 'r', 'u', ' ', 'a', ' ', 'd', 'e', 'b', 'l', 'o', 'c', 'a', ' ', 'm', 'e', 'n', 'i', 'u', 'l', };
  
  code UCHAR DU_OSDUNLCOKKEYStr[]={40, 'H', 'o', 'u', 'd', ' ', 'e', 'e', 'n', ' ', 'w', 'i', 'l', 'l', 'e', 'k', 'e', 'u', 'r', 'i', 'g', 'e', ' ', 't', 'o', 'e', 't', 's', ' ', '1', '0', ' ', 's', 'e', 'c', 'o', 'n', 'd', 'e', 'n', ' ',};
  code UCHAR DU_OSDUNLCOKKEYStr2[]={33, 'i', 'n', 'g', 'e', 'd', 'r', 'u', 'k', 't', ' ', 'o', 'm', ' ', 'd', 'e', ' ', 'O', 'S', 'D', ' ', 'v', 'r', 'i', 'j', ' ', 't', 'e', ' ', 'g', 'e', 'v', 'e', 'n', };
  
  code UCHAR RU_OSDUNLCOKKEYStr[]={46, 142, 132, 136, 151, 159, ' ', 133, 143, 141, 151, 127, 136, 148, 124, 133, 136, 131, 143, 132, 155, ' ', 176, 148, 133, 143, 144, 144, 136, 128, ' ', 146, 128, 144, 174, ',', ' ', 144, 143, 152, 146, 124, 132, 128, ' ', 124, ' ', };
  code UCHAR RU_OSDUNLCOKKEYStr2[]={44, 135, 139, 128, 133, 152, 124, 131, 143, 129, 132, 128, ' ', 127, 174, 151, 135, 174, ' ', 148, 144, 136, 126, 148, 135, ' ', 131, ' ', 132, 128, 147, 128, 144, 124, 128, ' ', '1', '0', ' ', 125, 128, 148, 135, 144, 139, };
  
  code UCHAR SW_OSDUNLCOKKEYStr[]={27, 'H', 123, 'l', 'l', ' ', 'n', 'e', 'd', ' ', 'v', 'a', 'l', 'f', 'r', 'i', ' ', 'k', 'n', 'a', 'p', 'p', ' ', 'i', ' ', '1', '0', ' '};
  code UCHAR SW_OSDUNLCOKKEYStr2[]={29, 's', 'e', 'k', 'u', 'n', 'd', 'e', 'r', ' ', 'f', 10, 'r', ' ', 'a', 't', 't', ' ', 'l', 123, 's', 'a', ' ', 'u', 'p', 'p', ' ', 'O', 'S', 'D', };
  
  code UCHAR PR_OSDUNLCOKKEYStr[]={40, 'P', 'r', 'i', 'm', 'a', ' ', 'l', 'o', 'n', 'g', 'a', 'm', 'e', 'n', 't', 'e', ' ', 'q', 'u', 'a', 'l', 'q', 'u', 'e', 'r', ' ', 't', 'e', 'c', 'l', 'a', ' ', 'd', 'u', 'r', 'a', 'n', 't', 'e', ' ',};
  code UCHAR PR_OSDUNLCOKKEYStr2[]={34,  '1', '0', ' ', 's', 'e', 'g', 'u', 'n', 'd', 'o', 's', ' ', 'p', 'a', 'r', 'a', ' ', 'd', 'e', 's', 'b', 'l', 'o', 'q', 'u', 'e', 'a', 'r', ' ', 'o', ' ', 'O', 'S', 'D', };
  
  code UCHAR JA_OSDUNLCOKKEYStr[]={25, 173, 18, 165, 174, 28, 9, 193, '1', '0', 194, 195, 12, 196, 138, 197, 136, 19, 198, 18, 23, 19, 10, 199, 147, 144,};
  code UCHAR JA_OSDUNLCOKKEYStr2[]={13, 'O', 'S', 'D', 24, 188, 15, 134, 191, 192, 27, 28, 29, 10, };
  
  code UCHAR CT_OSDUNLCOKKEYStr[]={9, 164, 194, 165, 195, 167, ' ', '1', '0', ' ',};
  code UCHAR CT_OSDUNLCOKKEYStr2[]={11, 196, 197, 169, 138, ' ', 'O', 'S', 'D', ' ', 193, 191, };
  
  code UCHAR CS_OSDUNLCOKKEYStr[]={9, 159, 190, 160, 191, 162, ' ', '1', '0', ' ', };
  code UCHAR CS_OSDUNLCOKKEYStr2[]={9, 192, 193, 163, 189, 187, ' ', 'O', 'S', 'D', };

code UCHAR *OSDUnLockkeyStrTab[] = {
EN_OSDUNLCOKKEYStr,
FR_OSDUNLCOKKEYStr,
GE_OSDUNLCOKKEYStr,
IT_OSDUNLCOKKEYStr,
SP_OSDUNLCOKKEYStr,
PO_OSDUNLCOKKEYStr,
CZ_OSDUNLCOKKEYStr,
MA_OSDUNLCOKKEYStr,
SE_OSDUNLCOKKEYStr,
RO_OSDUNLCOKKEYStr,
DU_OSDUNLCOKKEYStr,
RU_OSDUNLCOKKEYStr,
SW_OSDUNLCOKKEYStr,
PR_OSDUNLCOKKEYStr,
JA_OSDUNLCOKKEYStr,
CT_OSDUNLCOKKEYStr,
CS_OSDUNLCOKKEYStr,

EN_OSDUNLCOKKEYStr2,
FR_OSDUNLCOKKEYStr2,
GE_OSDUNLCOKKEYStr2,
IT_OSDUNLCOKKEYStr2,
SP_OSDUNLCOKKEYStr2,
PO_OSDUNLCOKKEYStr2,
CZ_OSDUNLCOKKEYStr2,
MA_OSDUNLCOKKEYStr2,
SE_OSDUNLCOKKEYStr2,
RO_OSDUNLCOKKEYStr2,
DU_OSDUNLCOKKEYStr2,
RU_OSDUNLCOKKEYStr2,
SW_OSDUNLCOKKEYStr2,
PR_OSDUNLCOKKEYStr2,
JA_OSDUNLCOKKEYStr2,
CT_OSDUNLCOKKEYStr2,
CS_OSDUNLCOKKEYStr2,

};

code UCHAR EN_OutOfRangeStr[]={14, 'O', 'u', 't', ' ', 'o', 'f', ' ', 'R', 'a', 'n', 'g', 'e', ' ', '!', };
code UCHAR FR_OutOfRangeStr[]={16, 'H', 'o', 'r', 's', ' ', 'd', 'e', ' ', 'p', 'o', 'r', 't', 2, 'e', ' ', '!', };
code UCHAR GE_OutOfRangeStr[]={31, 'S', 'i', 'g', 'n', 'a', 'l', ' ', 'a', 'u', 123, 'e', 'r', 'h', 'a', 'l', 'b', ' ', 'd', 'e', 's', ' ', 'B', 'e', 'r', 'e', 'i', 'c', 'h', 's', ' ', '!', };
code UCHAR IT_OutOfRangeStr[]={13, 'F', 'u', 'o', 'r', 'i', ' ', 'c', 'a', 'm', 'p', 'o', ' ', '!', };
code UCHAR SP_OutOfRangeStr[]={31, 'F', 'r', 'e', 'c', 'u', 'e', 'n', 'c', 'i', 'a', ' ', 'f', 'u', 'e', 'r', 'a', ' ', 'd', 'e', ' ', 'i', 'n', 't', 'e', 'r', 'v', 'a', 'l', 'o', ' ', '!', };
code UCHAR PO_OutOfRangeStr[]={23, 'P', 'r', 'z', 'e', 'k', 'r', 'o', 'c', 'z', 'e', 'n', 'i', 'e', ' ', 'z', 'a', 'k', 'r', 'e', 's', 'u', ' ', '!', };
code UCHAR CZ_OutOfRangeStr[]={13, 'M', 'i', 'm', 'o', ' ', 'r', 'o', 'z', 's', 'a', 'h', ' ', '!', };
code UCHAR MA_OutOfRangeStr[]={10, 'T', 25, 'l', ' ', 'n', 'a', 'g', 'y', ' ', '!', };
code UCHAR SE_OutOfRangeStr[]={14, 'I', 'z', 'v', 'a', 'n', ' ', 'd', 'o', 's', 'e', 'g', 'a', ' ', '!', };
code UCHAR RO_OutOfRangeStr[]={16, 127, 'n', ' ', 'a', 'f', 'a', 'r', 'a', ' ', 'g', 'a', 'm', 'e', 'i', ' ', '!', };
code UCHAR DU_OutOfRangeStr[]={15, 'B', 'u', 'i', 't', 'e', 'n', ' ', 'b', 'e', 'r', 'e', 'i', 'k', ' ', '!', };
code UCHAR RU_OutOfRangeStr[]={27, 137, 144, 128, ' ', 139, 136, 126, 135, 125, 132, 124, 146, 136, 134, 136, ' ', 139, 124, 143, 126, 143, 141, 136, 144, 143, ' ', '!', };
code UCHAR SW_OutOfRangeStr[]={26, 'S', 'i', 'g', 'n', 'a', 'l', ' ', 'u', 't', 'a', 'n', 'f', 10, 'r', ' ', 'i', 'n', 't', 'e', 'r', 'v', 'a', 'l', 'l', ' ', '!', };
code UCHAR PR_OutOfRangeStr[]={15, 'F', 'o', 'r', 'a', ' ', 'd', 'a', ' ', 'F', 'a', 'i', 'x', 'a', ' ', '!', };
code UCHAR JA_OutOfRangeStr[]={7, 6, 7, 8, 9, 10, ' ', '!', };
code UCHAR CT_OutOfRangeStr[]={8, 6, 7, 8, 9, 10, 11, ' ', 12, };
code UCHAR CS_OutOfRangeStr[]={8, 6, 7, 8, 9, 10, 11, ' ', 12, };

code UCHAR *DialogOutOfRangStrTab[] = {
    EN_OutOfRangeStr,
    FR_OutOfRangeStr,
    GE_OutOfRangeStr,
    IT_OutOfRangeStr,
    SP_OutOfRangeStr,
    PO_OutOfRangeStr,
    CZ_OutOfRangeStr,
    MA_OutOfRangeStr,
    SE_OutOfRangeStr,
    RO_OutOfRangeStr,
    DU_OutOfRangeStr,
    RU_OutOfRangeStr,
    SW_OutOfRangeStr,
    PR_OutOfRangeStr,
    JA_OutOfRangeStr,
    CT_OutOfRangeStr,
    CS_OutOfRangeStr,
};


code UCHAR EN_NosyncStr[] = {20, 'N', 'o', ' ', 'S', 'i', 'g', 'n', 'a', 'l', ' ', 'D', 'e', 't', 'e', 'c', 't', 'e', 'd', ' ', '!', };
code UCHAR FR_NosyncStr[] = {23, 'P', 'a', 's', ' ', 'd', 'e', ' ', 's', 'i', 'g', 'n', 'a', 'l', ' ', 'd', 2, 't', 'e', 'c', 't', 2, 12, '!', };
code UCHAR GE_NosyncStr[] = {13, 'K', 'e', 'i', 'n', ' ', 'S', 'i', 'g', 'n', 'a', 'l', ' ', '!', };
code UCHAR IT_NosyncStr[] = {25, 'N', 'e', 's', 's', 'u', 'n', ' ', 's', 'e', 'g', 'n', 'a', 'l', 'e', ' ', 'r', 'i', 'l', 'e', 'v', 'a', 't', 'o', ' ', '!', };
code UCHAR SP_NosyncStr[] = {29, 'N', 'o', ' ', 's', 'e', ' ', 'd', 'e', 't', 'e', 'c', 't', 'a', ' ', 'n', 'i', 'n', 'g', 'u', 'n', 'a', ' ', 's', 'e', 124, 'a', 'l', ' ', '!', };
code UCHAR PO_NosyncStr[] = {21, 'N', 'i', 'e', ' ', 'w', 'y', 'k', 'r', 'y', 't', 'o', ' ', 's', 'y', 'g', 'n', 'a', 129, 'u', ' ', '!', };
code UCHAR CZ_NosyncStr[] = {28, 'N', 'e', 'b', 'y', 'l', ' ', 'z', 'j', 'i', 20, 't', 127, 'n', ' ', 26, 0, 'd', 'n', 128, ' ', 's', 'i', 'g', 'n', 0, 'l', ' ', '!', };
code UCHAR MA_NosyncStr[] = {19, 'N', 'e', 'm', ' ', 2, 'r', 'z', 2, 'k', 'e', 'l', ' ', 'j', 'e', 'l', 'e', 't', ' ', '!', };
code UCHAR SE_NosyncStr[] = {14, 'N', 'e', 'm', 'a', ' ', 's', 'i', 'g', 'n', 'a', 'l', 'a', ' ', '!', };
code UCHAR RO_NosyncStr[] = {30, 'N', 'u', ' ', 'a', ' ', 'f', 'o', 's', 't', ' ', 'd', 'e', 't', 'e', 'c', 't', 'a', 't', ' ', 'u', 'n', ' ', 's', 'e', 'm', 'n', 'a', 'l', ' ', '!', };
code UCHAR DU_NosyncStr[] = {27, 'G', 'e', 'e', 'n', ' ', 's', 'i', 'g', 'n', 'a', 'a', 'l', ' ', 'g', 'e', 'd', 'e', 't', 'e', 'c', 't', 'e', 'e', 'r', 'd', ' ', '!', };
code UCHAR RU_NosyncStr[] = {21, 164, 124, 134, 144, 143, 127, ' ', 144, 128, ' ', 136, 151, 144, 143, 133, 135, 152, 128, 144, ' ', '!', };
code UCHAR SW_NosyncStr[] = {22, 'I', 'n', 'g', 'e', 'n', ' ', 's', 'i', 'g', 'n', 'a', 'l', ' ', 'u', 'p', 'p', 't', 3, 'c', 'k', 's', '!', };
code UCHAR PR_NosyncStr[] = {21, 'S', 'e', 'm', ' ', 'S', 'i', 'n', 'a', 'l', ' ', 'D', 'e', 't', 'e', 'c', 't', 'a', 'd', 'o', ' ', '!', };
code UCHAR JA_NosyncStr[] = {13, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, '!', };
code UCHAR CT_NosyncStr[] = {8, 18, 19, 20, 21, 22, 23, ' ', 12, };
code UCHAR CS_NosyncStr[] = {8, 18, 19, 20, 21, 22, 23, ' ', 12, };

code UCHAR *DialogNosyncStrTab[] = {
    EN_NosyncStr,
    FR_NosyncStr,
    GE_NosyncStr,
    IT_NosyncStr,
    SP_NosyncStr,
    PO_NosyncStr,
    CZ_NosyncStr,
    MA_NosyncStr,
    SE_NosyncStr,
    RO_NosyncStr,
    DU_NosyncStr,
    RU_NosyncStr,
    SW_NosyncStr,
    PR_NosyncStr,
    JA_NosyncStr,
    CT_NosyncStr,
    CS_NosyncStr,
};



code UCHAR  EN_DialogReminderStr[]={35, 'Y', 'o', 'u', 'r', ' ', 'e', 'y', 'e', 's', ' ', 'd', 'e', 's', 'e', 'r', 'v', 'e', ' ', 'a', ' ', 'w', 'e', 'l', 'l', '-', 't', 'i', 'm', 'e', 'd', ' ', 'r', 'e', 's', 't'};
code UCHAR  FR_DialogReminderStr[]={52, 'D', 'e', 's', ' ', 'p', 'a', 'u', 's', 'e', 's', ' ', 'b', 'i', 'e', 'n', ' ', 'm', 2, 'r', 'i', 't', 2, 'e', 's', ' ', 'p', 'o', 'u', 'r', ' ', 'v', 'o', 's', ' ', 'y', 'e', 'u', 'x', ' ', 'a', 'u', ' ', 'b', 'o', 'n', ' ', 'm', 'o', 'm', 'e', 'n', 't', };
code UCHAR  GE_DialogReminderStr[]={31, 'I', 'h', 'r', 'e', ' ', 'A', 'u', 'g', 'e', 'n', ' ', 'v', 'e', 'r', 'd', 'i', 'e', 'n', 'e', 'n', ' ', 'e', 'i', 'n', 'e', ' ', 'P', 'a', 'u', 's', 'e', };
code UCHAR  IT_DialogReminderStr[]={46, 'G', 'l', 'i', ' ', 'o', 'c', 'c', 'h', 'i', ' ', 'm', 'e', 'r', 'i', 't', 'a', 'n', 'o', ' ', 'i', 'l', ' ', 'g', 'i', 'u', 's', 't', 'o', ' ', 'p', 'e', 'r', 'i', 'o', 'd', 'o', ' ', 'd', 'i', ' ', 'r', 'i', 'p', 'o', 's', 'o', };
code UCHAR  SP_DialogReminderStr[]={36, 'S', 'u', 's', ' ', 'o', 'j', 'o', 's', ' ', 's', 'e', ' ', 'm', 'e', 'r', 'e', 'c', 'e', 'n', ' ', 'u', 'n', ' ', 'b', 'u', 'e', 'n', ' ', 'd', 'e', 's', 'c', 'a', 'n', 's', 'o', };
code UCHAR  PO_DialogReminderStr[]={42, 'T', 'w', 'o', 'j', 'e', ' ', 'o', 'c', 'z', 'y', ' ', 'z', 'a', 's', 129, 'u', 124, 'y', 129, 'y', ' ', 'n', 'a', ' ', 'o', 'd', 'r', 'o', 'b', 'i', 128, ' ', 'o', 'd', 'p', 'o', 'c', 'z', 'y', 'n', 'k', 'u', };
code UCHAR  CZ_DialogReminderStr[]={41, 'V', 'a', 20, 'e', ' ', 'o', 6, 'i', ' ', 's', 'i', ' ', 'z', 'a', 's', 'l', 'o', 'u', 26, 1, ' ', 'd', 'o', 's', 't', 'a', 't', 'e', 6, 'n', 128, ' ', 'o', 'd', 'p', 'o', 6, 'i', 'n', 'e', 'k', };
code UCHAR  MA_DialogReminderStr[]={50, 'A', ' ', 's', 'z', 'e', 'm', 'e', 'i', 't', ' ', 'r', 'e', 'n', 'd', 's', 'z', 'e', 'r', 'e', 's', ' ', 'i', 'd', 123, 'k', 10, 'z', 10, 'n', 'k', 2, 'n', 't', ' ', 'p', 'i', 'h', 'e', 'n', 't', 'e', 't', 'n', 'i', 'e', ' ', 'k', 'e', 'l', 'l', };
code UCHAR  SE_DialogReminderStr[]={40, 'V', 'a', 20, 'e', ' ', 'o', 6, 'i', ' ', 'z', 'a', 's', 'l', 'u', 26, 'u', 'j', 'u', ' ', 'o', 'd', 'm', 'o', 'r', ' ', 'u', ' ', 'p', 'r', 'a', 'v', 'o', ' ', 'v', 'r', 'i', 'j', 'e', 'm', 'e', };
code UCHAR  RO_DialogReminderStr[]={39, 'O', 'c', 'h', 'i', 'i', ' ', 'd', 'v', 's', '.', ' ', 'a', 'u', ' ', 'n', 'e', 'v', 'o', 'i', 'e', ' ', 'p', 'e', 'r', 'i', 'o', 'd', 'i', 'c', ' ', 'd', 'e', ' ', 'o', 'd', 'i', 'h', 'n', 125, };
code UCHAR  DU_DialogReminderStr[]={43, 'U', 'w', ' ', 'o', 'g', 'e', 'n', ' ', 'z', 'i', 'j', 'n', ' ', 't', 'o', 'e', ' ', 'a', 'a', 'n', ' ', 'e', 'e', 'n', ' ', 'w', 'e', 'l', 'v', 'e', 'r', 'd', 'i', 'e', 'n', 'd', 'e', ' ', 'p', 'a', 'u', 'z', 'e', };
code UCHAR  RU_DialogReminderStr[]={44, 137, 143, 177, 124, ' ', 134, 127, 143, 141, 143, ' ', 141, 143, 125, 127, 135, 152, 124, 131, 143, 174, 132, ' ', 125, 131, 136, 128, 131, 133, 128, 146, 128, 144, 144, 136, 134, 136, ' ', 136, 132, 139, 159, 138, 143, };
code UCHAR  SW_DialogReminderStr[]={42, 'D', 'i', 'n', 'a', ' ', 10, 'g', 'o', 'n', ' ', 'f', 10, 'r', 't', 'j', 3, 'n', 'a', 'r', ' ', 'v', 'i', 'l', 'a', ' ', 'v', 'i', 'd', ' ', 'r', 3, 't', 't', ' ', 't', 'i', 'd', 'p', 'u', 'n', 'k', 't', };
code UCHAR  PR_DialogReminderStr[]={36, 'D', 'e', 's', 'c', 'a', 'n', 's', 'e', ' ', 'o', 's', ' ', 's', 'e', 'u', 's', ' ', 'o', 'l', 'h', 'o', 's', ';', ' ', 'e', 'l', 'e', 's', ' ', 'm', 'e', 'r', 'e', 'c', 'e', 'm', };
code UCHAR  JA_DialogReminderStr[]={14, 161, 143, 162, 146, 159, 163, 164, 165, 166, 167, 147, 160, 29, 10, };
code UCHAR  CT_DialogReminderStr[]={10, 123, 146, 147, 148, 149, 150, 151, 129, 152, 153, };
code UCHAR  CS_DialogReminderStr[]={10, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, };


code UCHAR *DialogReminderStrTab[] = {
    EN_DialogReminderStr,
    FR_DialogReminderStr,
    GE_DialogReminderStr,
    IT_DialogReminderStr,
    SP_DialogReminderStr,
    PO_DialogReminderStr,
    CZ_DialogReminderStr,
    MA_DialogReminderStr,
    SE_DialogReminderStr,
    RO_DialogReminderStr,
    DU_DialogReminderStr,
    RU_DialogReminderStr,
    SW_DialogReminderStr,
    PR_DialogReminderStr,
    JA_DialogReminderStr,
    CT_DialogReminderStr,
    CS_DialogReminderStr,

};


code UCHAR ResolutionStr[] ={9,50,53,54,48,'x',49,52,52,48};

code UCHAR EN_NocableStr[] ={20, 'N', 'o', ' ', 'C', 'a', 'b', 'l', 'e', ' ', 'C', 'o', 'n', 'n', 'e', 'c', 't', 'e', 'd', ' ', '!', };
code UCHAR FR_NocableStr[] ={22, 'A', 'u', 'c', 'u', 'n', ' ', 'c', 123, 'b', 'l', 'e', ' ', 'c', 'o', 'n', 'n', 'e', 'c', 't', 2, ' ', '!', };
code UCHAR GE_NocableStr[] ={26, 'K','e','i','n',32,'K','a','b','e','l',32,'a','n','g','e','s','c','h','l','o','s','s','e','n',32,33};
code UCHAR IT_NocableStr[] ={20, 'C', 'a', 'v', 'o', ' ', 's', 'e', 'g', 'n', ' ', 'n', 'o', 'n', ' ', 'c', 'o', 'l', 'l', ' ', '!', };
code UCHAR SP_NocableStr[] ={22, 'C', 'a', 'b', '.', ' ', 's', 'e', 124, 'a', 'l', ' ', 'n', 'o', ' ', 'c', 'o', 'n', 'e', 'c', '.', ' ', '!', };
code UCHAR PO_NocableStr[] ={22, 'K', 'a', 'b', 'e', 'l', ' ', 's', 'y', 'g', '.', ' ', 'n', 'i', 'e', ' ', 'p', 'o', 'd', 129, '.', ' ', '!', };
code UCHAR CZ_NocableStr[] ={21, 'S', 'i', 'g', 'n', '.', ' ', 'k', 'a', 'b', 'e', 'l', ' ', 'n', 'e', 'p', 124, 'i', 'p', '.', ' ', '!', };
code UCHAR MA_NocableStr[] ={22, 'J', 'e', 'l', 'k', 0, 'b', 'e', 'l', ' ', 'n', 'i', 'n', 'c', 's', ' ', 'c', 's', 'a', 't', '.', ' ', '!', };
code UCHAR SE_NocableStr[] ={22, 'S', 'i', 'g', 'n', '.', 'k', 'a', 'b', '.', 'n', 'i', 'j', 'e', ' ', 's', 'p', 'o', 'j', 'e', 'n', ' ', '!', };
code UCHAR RO_NocableStr[] ={22, 'C', 'a', 'b', 'l', 'u', ' ', 's', 'e', 'm', 'n', '.', ' ', 'D', 'e', 'c', 'o', 'n', 'e', 'c', 't', ' ', '!', };
code UCHAR DU_NocableStr[] ={21, 'K', 'a', 'b', 'e', 'l', ' ', 'n', 'i', 'e', 't', ' ', 'a', 'a', 'n', 'g', 'e', 's', 'l', '.', ' ', '!', };
code UCHAR RU_NocableStr[] ={24, 164, 124, 134, 144, '.', 148, 143, 151, '.', ' ', 144, 128, ' ', 126, 136, 139, 148, 127, 174, 147, 128, 144, ' ', '!', };
code UCHAR SW_NocableStr[] ={24, 'E', 'j', ' ', 'a', 'n', 's', 'l', 'u', 't', 'e', 'n', ' ', 's', 'i', 'g', 'n', 'a', 'l', 'k', 'a', 'b', 'e', 'l', '!', };
code UCHAR PR_NocableStr[] ={22, 'C', 'a', 'b', 'o', ' ', 's', 'i', 'n', 'a', 'l', ' ', 'd', 'e', 's', 'l', 'i', 'g', 'a', 'd', 'o', ' ', '!', };
code UCHAR JA_NocableStr[] ={15, 123, 18, 124, 23, 24, 125, 126, 27, 28, 127, 128, 29, 30, 31, '!', };
code UCHAR CT_NocableStr[] ={9, 24, 25, 26, 27, 28, 29, 30, ' ', '!', };
code UCHAR CS_NocableStr[] ={8, 24, 25, 26, 27, 28, 29, ' ', '!', };

code UCHAR *DialogNocableStrTab[] = {
    EN_NocableStr,
    FR_NocableStr,
    GE_NocableStr,
    IT_NocableStr,
    SP_NocableStr,
    PO_NocableStr,
    CZ_NocableStr,
    MA_NocableStr,
    SE_NocableStr,
    RO_NocableStr,
    DU_NocableStr,
    RU_NocableStr,
    SW_NocableStr,
    PR_NocableStr,
    JA_NocableStr,
    CT_NocableStr,
    CS_NocableStr,
};

  code UCHAR EN_ResNoteStr[]={28, 'S', 'u', 'g', 'g', 'e', 's', 't', 'e', 'd', ' ', 'M', 'o', 'n', 'i', 't', 'o', 'r', ' ', 'R', 'e', 's', 'o', 'l', 'u', 't', 'i', 'o', 'n', };
  code UCHAR FR_ResNoteStr[]={31, 'R', 2, 's', 'o', 'l', 'u', 't', 'i', 'o', 'n', ' ', 's', 'u', 'g', 'g', 2, 'r', 2, 'e', ' ', 'd', 'u', ' ', 'm', 'o', 'n', 'i', 't', 'e', 'u', 'r', };
  code UCHAR GE_ResNoteStr[]={27, 'E', 'm', 'p', 'f', 'o', 'h', 'l', 'e', 'n', 'e', ' ', 'M', 'o', 'n', 'i', 't', 'o', 'r', 'a', 'u', 'f', 'l', 10, 's', 'u', 'n', 'g', };
  code UCHAR IT_ResNoteStr[]={29, 'R', 'i', 's', 'o', 'l', 'u', 'z', 'i', 'o', 'n', 'e', ' ', 'm', 'o', 'n', 'i', 't', 'o', 'r', ' ', 's', 'u', 'g', 'g', 'e', 'r', 'i', 't', 'a', };
  code UCHAR SP_ResNoteStr[]={33, 'R', 'e', 's', 'o', 'l', 'u', 'c', 'i', 4, 'n', ' ', 'd', 'e', 'l', ' ', 'm', 'o', 'n', 'i', 't', 'o', 'r', ' ', 'a', 'c', 'o', 'n', 's', 'e', 'j', 'a', 'd', 'a', };
  code UCHAR PO_ResNoteStr[]={33, 'S', 'u', 'g', 'e', 'r', 'o', 'w', 'a', 'n', 'a', ' ', 'r', 'o', 'z', 'd', 'z', 'i', 'e', 'l', 'c', 'z', 'o', 123, 22, ' ', 'm', 'o', 'n', 'i', 't', 'o', 'r', 'a', };
  code UCHAR CZ_ResNoteStr[]={29, 'D', 'o', 'p', 'o', 'r', 'u', 6, 'e', 'n', 2, ' ', 'r', 'o', 'z', 'l', 'i', 20, 'e', 'n', 1, ' ', 'm', 'o', 'n', 'i', 't', 'o', 'r', 'u', };
  code UCHAR MA_ResNoteStr[]={27, 'M', 'o', 'n', 'i', 't', 'o', 'r', ' ', 'j', 'a', 'v', 'a', 's', 'o', 'l', 't', ' ', 'f', 'e', 'l', 'b', 'o', 'n', 't', 0, 's', 'a', };
  code UCHAR SE_ResNoteStr[]={31, 'P', 'r', 'e', 'p', 'o', 'r', 'u', 6, 'e', 'n', 'a', ' ', 'r', 'a', 'z', 'l', 'u', 6, 'i', 'v', 'o', 's', 't', ' ', 'z', 'a', 's', 'l', 'o', 'n', 'a', };
  code UCHAR RO_ResNoteStr[]={35, 'R', 'e', 'z', 'o', 'l', 'u', 124, 'i', 'e', ' ', 'r', 'e', 'c', 'o', 'm', 'a', 'n', 'd', 'a', 't', 125, ' ', 'a', ' ', 'm', 'o', 'n', 'i', 't', 'o', 'r', 'u', 'l', 'u', 'i', };
  code UCHAR DU_ResNoteStr[]={27, 'A', 'a', 'n', 'b', 'e', 'v', 'o', 'l', 'e', 'n', ' ', 'm', 'o', 'n', 'i', 't', 'o', 'r', 'r', 'e', 's', 'o', 'l', 'u', 't', 'i', 'e', };
  code UCHAR RU_ResNoteStr[]={33, 156, 128, 148, 136, 146, 128, 144, 139, 135, 128, 146, 136, 128, ' ', 133, 143, 141, 133, 128, 177, 128, 144, 124, 128, ' ', 146, 136, 144, 124, 132, 136, 133, 143, };
  code UCHAR SW_ResNoteStr[]={26, 'F', 10, 'r', 'e', 's', 'l', 'a', 'g', 'e', 'n', ' ', 's', 'k', 3, 'r', 'm', 'u', 'p', 'p', 'l', 10, 's', 'n', 'i', 'n', 'g', };
  code UCHAR PR_ResNoteStr[]={29, 'R', 'e', 's', 'o', 'l', 'u', 7, 123, 'o', ' ', 'd', 'o', ' ', 'M', 'o', 'n', 'i', 't', 'o', 'r', ' ', 'S', 'u', 'g', 'e', 'r', 'i', 'd', 'a', };
  code UCHAR JA_ResNoteStr[]={12, 219, 220, 221, 222, 223, 159, 224, 225, 21, 180, 26, 124, };
  code UCHAR CT_ResNoteStr[]={9, 213, 214, 215, 0, 1, 211, 177, 178, 28, };
  code UCHAR CS_ResNoteStr[]={11, 212, 213, 214, 131, 215, 0, 1, 210, 176, 177, 19, };
  
code UCHAR *ResNoteStrTab[] = {
    EN_ResNoteStr,
    FR_ResNoteStr,
    GE_ResNoteStr,
    IT_ResNoteStr,
    SP_ResNoteStr,
    PO_ResNoteStr,
    CZ_ResNoteStr,
    MA_ResNoteStr,
    SE_ResNoteStr,
    RO_ResNoteStr,
    DU_ResNoteStr,
    RU_ResNoteStr,
    SW_ResNoteStr,
    PR_ResNoteStr,
    JA_ResNoteStr,
    CT_ResNoteStr,
    CS_ResNoteStr,
};

//Ergonomics Strings
code UCHAR EN_TimeIntervalStr1[]={20, 'T', 'i', 'm', 'e', ' ', 'I', 'n', 't', 'e', 'r', 'v', 'a', 'l', ' ', '(', 'm', 'i', 'n', '.', ')', };
code UCHAR FR_TimeIntervalStr1[]={16, 'I', 'n', 't', 'e', 'r', 'v', 'a', 'l', 'l', 'e', ' ', '(', 'm', 'i', 'n', ')', };
code UCHAR GE_TimeIntervalStr1[]={16, 'I', 'n', 't', 'e', 'r', 'v', 'a', 'l', 'l', ' ', '(', 'M', 'i', 'n', '.', ')', };
code UCHAR IT_TimeIntervalStr1[]={19, 'I', 'n', 't', 'e', 'r', 'v', ' ', 't', 'e', 'm', 'p', 'o', ' ', '(', 'm', 'i', 'n', '.', ')', };
code UCHAR SP_TimeIntervalStr1[]={16, 'I', 'n', 't', 'e', 'r', 'v', 'a', 'l', 'o', ' ', '(', 'm', 'i', 'n', '.', ')', };
code UCHAR PO_TimeIntervalStr1[]={18, 'P', 'r', 'z', 'e', '.', ' ', 'c', 'z', 'a', 's', '.', ' ', '(', 'm', 'i', 'n', '.', ')', };
code UCHAR CZ_TimeIntervalStr1[]={16, 27, 'a', 's', '.', ' ', 'i', 'n', 't', '.', ' ', '(', 'm', 'i', 'n', '.', ')', };
code UCHAR MA_TimeIntervalStr1[]={13, 'I', 'd', 123, 'k', 10, 'z', ' ', '(', 'p', 'e', 'r', 'c', ')', };
code UCHAR SE_TimeIntervalStr1[]={17, 'V', 'r', 'e', 'm', '.', ' ', 'i', 'n', 't', '.', ' ', '(', 'm', 'i', 'n', '.', ')', };
code UCHAR RO_TimeIntervalStr1[]={15, 'I', 'n', 't', 'e', 'r', 'v', 'a', 'l', ' ', '(', 'm', 'i', 'n', '.', ')', };
code UCHAR DU_TimeIntervalStr1[]={15, 'I', 'n', 't', 'e', 'r', 'v', 'a', 'l', ' ', '(', 'm', 'i', 'n', '.', ')', };
code UCHAR RU_TimeIntervalStr1[]={15, 150, 144, 132, 128, 133, 131, 143, 127, ' ', '(', 146, 124, 144, '.', ')', };
code UCHAR SW_TimeIntervalStr1[]={20, 'T', 'i', 'd', 's', 'i', 'n', 't', 'e', 'r', 'v', 'a', 'l', 'l', ' ', '(', 'm', 'i', 'n', '.', ')', };
code UCHAR PR_TimeIntervalStr1[]={17, 'I', 'n', 't', '.', ' ', 't', 'e', 'm', 'p', 'o', ' ', '(', 'm', 'i', 'n', '.', ')', };
code UCHAR JA_TimeIntervalStr1[]={9, 246, 215, 145, 247, 221, ' ', '(', 235, ')', };
code UCHAR CT_TimeIntervalStr1[]={7, 206, 207, 207, 243, 40, 227, 41, };
code UCHAR CS_TimeIntervalStr1[]={8, 205, 206, 206, 243, 40, 176, 226, 41, };

code UCHAR EN_DurationStr1[]={15, 'D', 'u', 'r', 'a', 't', 'i', 'o', 'n', ' ', '(', 's', 'e', 'c', '.', ')', };
code UCHAR FR_DurationStr1[]={12, 'D', 'u', 'r', 2, 'e', ' ', '(', 's', 'e', 'c', '.', ')', };
code UCHAR GE_DurationStr1[]={12, 'D', 'a', 'u', 'e', 'r', ' ', '(', 'S', 'e', 'k', '.', ')', };
code UCHAR IT_DurationStr1[]={13, 'D', 'u', 'r', 'a', 't', 'a', ' ', '(', 's', 'e', 'c', '.', ')', };
code UCHAR SP_DurationStr1[]={15, 'D', 'u', 'r', 'a', 'c', 'i', 4, 'n', ' ', '(', 's', 'e', 'g', '.', ')', };
code UCHAR PO_DurationStr1[]={17, 'C', 'z', 'a', 's', ' ', 't', 'r', 'w', 'a', '.', ' ', '(', 's', 'e', 'k', '.', ')', };
code UCHAR CZ_DurationStr1[]={10, 'T', 'r', 'v', 0, 'n', 1, ' ', '(', 's', ')', };
code UCHAR MA_DurationStr1[]={15, 'I', 'd', 123, 't', 'a', 'r', 't', 'a', 'm', ' ', '(', 'm', 'p', '.', ')', };
code UCHAR SE_DurationStr1[]={12, 'T', 'r', 'a', 'j', 'a', 'n', 'j', 'e', ' ', '(', 's', ')', };
code UCHAR RO_DurationStr1[]={13, 'D', 'u', 'r', 'a', 't', 125, ' ', '(', 's', 'e', 'c', '.', ')', };
code UCHAR DU_DurationStr1[]={11, 'D', 'u', 'u', 'r', ' ', '(', 's', 'e', 'c', '.', ')', };
code UCHAR RU_DurationStr1[]={14, 123, 127, 124, 132, '-', 132, 155, ' ', '(', 125, 128, 148, '.', ')', };
code UCHAR SW_DurationStr1[]={18, 'V', 'a', 'r', 'a', 'k', 't', 'i', 'g', 'h', 'e', 't', ' ', '(', 's', 'e', 'k', '.', ')', };
code UCHAR PR_DurationStr1[]={14, 'D', 'u', 'r', 'a', 7, 123, 'o', ' ', '(', 's', 'e', 'g', '.', ')', };
code UCHAR JA_DurationStr1[]={6, 247, 221, ' ', '(', 234, ')', };
code UCHAR CT_DurationStr1[]={7, 246, 247, 206, 207, 40, 226, 41, };
code UCHAR CS_DurationStr1[]={5, 205, 246, 40, 225, 41, };

code UCHAR *ErgonomicsTab[] = {

     EN_SmartReminderStr1,
     FR_SmartReminderStr1,
     GE_SmartReminderStr1,
     IT_SmartReminderStr1,
     SP_SmartReminderStr1,
     PO_SmartReminderStr1,
     CZ_SmartReminderStr1,
     MA_SmartReminderStr1,
     SE_SmartReminderStr1,
     RO_SmartReminderStr1,
     DU_SmartReminderStr1,
     RU_SmartReminderStr1,
     SW_SmartReminderStr1,
     PR_SmartReminderStr1,
     JA_SmartReminderStr1,
     CT_SmartReminderStr1,
     CS_SmartReminderStr1,

     EN_TimeIntervalStr1,
     FR_TimeIntervalStr1,
     GE_TimeIntervalStr1,
     IT_TimeIntervalStr1,
     SP_TimeIntervalStr1,
     PO_TimeIntervalStr1,
     CZ_TimeIntervalStr1,
     MA_TimeIntervalStr1,
     SE_TimeIntervalStr1,
     RO_TimeIntervalStr1,
     DU_TimeIntervalStr1,
     RU_TimeIntervalStr1,
     SW_TimeIntervalStr1,
     PR_TimeIntervalStr1,
     JA_TimeIntervalStr1,
     CT_TimeIntervalStr1,
     CS_TimeIntervalStr1,

     EN_DurationStr1,
     FR_DurationStr1,
     GE_DurationStr1,
     IT_DurationStr1,
     SP_DurationStr1,
     PO_DurationStr1,
     CZ_DurationStr1,
     MA_DurationStr1,
     SE_DurationStr1,
     RO_DurationStr1,
     DU_DurationStr1,
     RU_DurationStr1,
     SW_DurationStr1,
     PR_DurationStr1,
     JA_DurationStr1,
     CT_DurationStr1,
     CS_DurationStr1,

};
code UCHAR **Layer2StringTab[] = {DisplayTab, PictureTab, PictureAdvancedTab, AudioTab,SystemTab,ErgonomicsTab};


// input
code UCHAR DSubStr1[] = {5,"D-Sub"};
code UCHAR DviStr1[] = {3,"DVI"};
code UCHAR HdmiStr1[] = {4,"HDMI"};
code UCHAR DispStr1[] = {11,"DisplayPort"};

code UCHAR *InputTab1[] = {
    DSubStr1,DSubStr1,DSubStr1,DSubStr1,DSubStr1,DSubStr1,DSubStr1,DSubStr1,DSubStr1,DSubStr1,DSubStr1,DSubStr1,DSubStr1,DSubStr1,DSubStr1,DSubStr1,DSubStr1,
    DviStr1,DviStr1,DviStr1,DviStr1,DviStr1,DviStr1,DviStr1,DviStr1,DviStr1,DviStr1,DviStr1,DviStr1,DviStr1,DviStr1,DviStr1,DviStr1,DviStr1,
    HdmiStr1,HdmiStr1,HdmiStr1,HdmiStr1,HdmiStr1,HdmiStr1,HdmiStr1,HdmiStr1,HdmiStr1,HdmiStr1,HdmiStr1,HdmiStr1,HdmiStr1,HdmiStr1,HdmiStr1,HdmiStr1,HdmiStr1,
    DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,
   };


// gamma string item
/*
code UCHAR EN_Gamma1Str1[]={6, 'G', 'a', 'm', 'm', 'a',49};
code UCHAR FR_Gamma1Str1[]={6, 'G', 'a', 'm', 'm', 'a',49};
code UCHAR GE_Gamma1Str1[]={6, 'G', 'a', 'm', 'm', 'a',49 };
code UCHAR IT_Gamma1Str1[]={6, 'G', 'a', 'm', 'm', 'a',49 };
code UCHAR SP_Gamma1Str1[]={6, 'G', 'a', 'm', 'm', 'a',49 };
code UCHAR PO_Gamma1Str1[]={6, 'G', 'a', 'm', 'm', 'a',49 };
code UCHAR CZ_Gamma1Str1[]={6, 'G', 'a', 'm', 'm', 'a',49 };
code UCHAR MA_Gamma1Str1[]={6, 'G', 'a', 'm', 'm', 'a',49 };
code UCHAR SE_Gamma1Str1[]={5, 'G', 'a', 'm', 'a',49 };
code UCHAR RO_Gamma1Str1[]={6, 'G', 'a', 'm', 'm', 'a',49 };
code UCHAR DU_Gamma1Str1[]={6, 'G', 'a', 'm', 'm', 'a',49 };
code UCHAR RU_Gamma1Str1[]={6, 140, 143, 146, 146, 143,49 };
code UCHAR SW_Gamma1Str1[]={6, 'G', 'a', 'm', 'm', 'a',49 };
code UCHAR PR_Gamma1Str1[]={6, 'G', 'a', 'm', 'm', 'a',49 };
code UCHAR JA_Gamma1Str1[]={4, 129, 28, 130, 49};
code UCHAR CT_Gamma1Str1[]={6, 'G', 'a', 'm', 'm', 'a',49 };
code UCHAR CS_Gamma1Str1[]={3, 31, 28,49 };
 
code UCHAR EN_Gamma2Str1[]={6, 'G', 'a', 'm', 'm', 'a',50};
code UCHAR FR_Gamma2Str1[]={6, 'G', 'a', 'm', 'm', 'a',50};
code UCHAR GE_Gamma2Str1[]={6, 'G', 'a', 'm', 'm', 'a',50 };
code UCHAR IT_Gamma2Str1[]={6, 'G', 'a', 'm', 'm', 'a',50 };
code UCHAR SP_Gamma2Str1[]={6, 'G', 'a', 'm', 'm', 'a',50 };
code UCHAR PO_Gamma2Str1[]={6, 'G', 'a', 'm', 'm', 'a',50 };
code UCHAR CZ_Gamma2Str1[]={6, 'G', 'a', 'm', 'm', 'a',50 };
code UCHAR MA_Gamma2Str1[]={6, 'G', 'a', 'm', 'm', 'a',50 };
code UCHAR SE_Gamma2Str1[]={5, 'G', 'a', 'm', 'a',50 };
code UCHAR RO_Gamma2Str1[]={6, 'G', 'a', 'm', 'm', 'a',50 };
code UCHAR DU_Gamma2Str1[]={6, 'G', 'a', 'm', 'm', 'a',50 };
code UCHAR RU_Gamma2Str1[]={6, 140, 143, 146, 146, 143,50 };
code UCHAR SW_Gamma2Str1[]={6, 'G', 'a', 'm', 'm', 'a',50 };
code UCHAR PR_Gamma2Str1[]={6, 'G', 'a', 'm', 'm', 'a',50 };
code UCHAR JA_Gamma2Str1[]={4, 129, 28, 130,50 };
code UCHAR CT_Gamma2Str1[]={6, 'G', 'a', 'm', 'm', 'a',50 };
code UCHAR CS_Gamma2Str1[]={3, 31, 28,50};

code UCHAR EN_Gamma3Str1[]={6, 'G', 'a', 'm', 'm', 'a',51};
code UCHAR FR_Gamma3Str1[]={6, 'G', 'a', 'm', 'm', 'a',51};
code UCHAR GE_Gamma3Str1[]={6, 'G', 'a', 'm', 'm', 'a',51 };
code UCHAR IT_Gamma3Str1[]={6, 'G', 'a', 'm', 'm', 'a',51 };
code UCHAR SP_Gamma3Str1[]={6, 'G', 'a', 'm', 'm', 'a',51 };
code UCHAR PO_Gamma3Str1[]={6, 'G', 'a', 'm', 'm', 'a',51 };
code UCHAR CZ_Gamma3Str1[]={6, 'G', 'a', 'm', 'm', 'a',51 };
code UCHAR MA_Gamma3Str1[]={6, 'G', 'a', 'm', 'm', 'a',51 };
code UCHAR SE_Gamma3Str1[]={5, 'G', 'a', 'm', 'a',51 };
code UCHAR RO_Gamma3Str1[]={6, 'G', 'a', 'm', 'm', 'a',51 };
code UCHAR DU_Gamma3Str1[]={6, 'G', 'a', 'm', 'm', 'a',51 };
code UCHAR RU_Gamma3Str1[]={6, 140, 143, 146, 146, 143,51 };
code UCHAR SW_Gamma3Str1[]={6, 'G', 'a', 'm', 'm', 'a',51 };
code UCHAR PR_Gamma3Str1[]={6, 'G', 'a', 'm', 'm', 'a',51 };
code UCHAR JA_Gamma3Str1[]={4, 129, 28, 130,51 };
code UCHAR CT_Gamma3Str1[]={6, 'G', 'a', 'm', 'm', 'a',51 };
code UCHAR CS_Gamma3Str1[]={3, 31, 28,51};

code UCHAR EN_Gamma4Str1[]={6, 'G', 'a', 'm', 'm', 'a',52};
code UCHAR FR_Gamma4Str1[]={6, 'G', 'a', 'm', 'm', 'a',52};
code UCHAR GE_Gamma4Str1[]={6, 'G', 'a', 'm', 'm', 'a',52 };
code UCHAR IT_Gamma4Str1[]={6, 'G', 'a', 'm', 'm', 'a',52 };
code UCHAR SP_Gamma4Str1[]={6, 'G', 'a', 'm', 'm', 'a',52 };
code UCHAR PO_Gamma4Str1[]={6, 'G', 'a', 'm', 'm', 'a',52 };
code UCHAR CZ_Gamma4Str1[]={6, 'G', 'a', 'm', 'm', 'a',52 };
code UCHAR MA_Gamma4Str1[]={6, 'G', 'a', 'm', 'm', 'a',52 };
code UCHAR SE_Gamma4Str1[]={5, 'G', 'a', 'm', 'a',52 };
code UCHAR RO_Gamma4Str1[]={6, 'G', 'a', 'm', 'm', 'a',52 };
code UCHAR DU_Gamma4Str1[]={6, 'G', 'a', 'm', 'm', 'a',52 };
code UCHAR RU_Gamma4Str1[]={6, 140, 143, 146, 146, 143,52 };
code UCHAR SW_Gamma4Str1[]={6, 'G', 'a', 'm', 'm', 'a',52 };
code UCHAR PR_Gamma4Str1[]={6, 'G', 'a', 'm', 'm', 'a',52 };
code UCHAR JA_Gamma4Str1[]={4, 129, 28, 130,52 };
code UCHAR CT_Gamma4Str1[]={6, 'G', 'a', 'm', 'm', 'a',52 };
code UCHAR CS_Gamma4Str1[]={3, 31, 28,52};

code UCHAR EN_Gamma5Str1[]={6, 'G', 'a', 'm', 'm', 'a',53};
code UCHAR FR_Gamma5Str1[]={6, 'G', 'a', 'm', 'm', 'a',53};
code UCHAR GE_Gamma5Str1[]={6, 'G', 'a', 'm', 'm', 'a',53 };
code UCHAR IT_Gamma5Str1[]={6, 'G', 'a', 'm', 'm', 'a',53 };
code UCHAR SP_Gamma5Str1[]={6, 'G', 'a', 'm', 'm', 'a',53 };
code UCHAR PO_Gamma5Str1[]={6, 'G', 'a', 'm', 'm', 'a',53 };
code UCHAR CZ_Gamma5Str1[]={6, 'G', 'a', 'm', 'm', 'a',53 };
code UCHAR MA_Gamma5Str1[]={6, 'G', 'a', 'm', 'm', 'a',53 };
code UCHAR SE_Gamma5Str1[]={5, 'G', 'a', 'm', 'a',53 };
code UCHAR RO_Gamma5Str1[]={6, 'G', 'a', 'm', 'm', 'a',53 };
code UCHAR DU_Gamma5Str1[]={6, 'G', 'a', 'm', 'm', 'a',53 };
code UCHAR RU_Gamma5Str1[]={6, 140, 143, 146, 146, 143,53 };
code UCHAR SW_Gamma5Str1[]={6, 'G', 'a', 'm', 'm', 'a',53 };
code UCHAR PR_Gamma5Str1[]={6, 'G', 'a', 'm', 'm', 'a',53 };
code UCHAR JA_Gamma5Str1[]={4, 129, 28, 130,53 };
code UCHAR CT_Gamma5Str1[]={6, 'G', 'a', 'm', 'm', 'a',53 };
code UCHAR CS_Gamma5Str1[]={3, 31, 28,53};
*/

code UCHAR EN_Gamma1Str1[]={1, 49};
code UCHAR EN_Gamma2Str1[]={1, 50};
code UCHAR EN_Gamma3Str1[]={1, 51};
code UCHAR EN_Gamma4Str1[]={1, 52};
code UCHAR EN_Gamma5Str1[]={1, 53};



code UCHAR *GammaStrTab[] = {
     EN_Gamma1Str1,
     EN_Gamma1Str1,
     EN_Gamma1Str1,
     EN_Gamma1Str1,
     EN_Gamma1Str1,
     EN_Gamma1Str1,
     EN_Gamma1Str1,
     EN_Gamma1Str1,
     EN_Gamma1Str1,
     EN_Gamma1Str1,
     EN_Gamma1Str1,
     EN_Gamma1Str1,
     EN_Gamma1Str1,
     EN_Gamma1Str1,
     EN_Gamma1Str1,
     EN_Gamma1Str1,
     EN_Gamma1Str1,
     
     EN_Gamma2Str1,
     EN_Gamma2Str1,
     EN_Gamma2Str1,
     EN_Gamma2Str1,
     EN_Gamma2Str1,
     EN_Gamma2Str1,
     EN_Gamma2Str1,
     EN_Gamma2Str1,
     EN_Gamma2Str1,
     EN_Gamma2Str1,
     EN_Gamma2Str1,
     EN_Gamma2Str1,
     EN_Gamma2Str1,
     EN_Gamma2Str1,
     EN_Gamma2Str1,
     EN_Gamma2Str1,
     EN_Gamma2Str1,
     
     EN_Gamma3Str1,
     EN_Gamma3Str1,
     EN_Gamma3Str1,
     EN_Gamma3Str1,
     EN_Gamma3Str1,
     EN_Gamma3Str1,
     EN_Gamma3Str1,
     EN_Gamma3Str1,
     EN_Gamma3Str1,
     EN_Gamma3Str1,
     EN_Gamma3Str1,
     EN_Gamma3Str1,
     EN_Gamma3Str1,
     EN_Gamma3Str1,
     EN_Gamma3Str1,
     EN_Gamma3Str1,
     EN_Gamma3Str1,
     
     EN_Gamma4Str1,
     EN_Gamma4Str1,
     EN_Gamma4Str1,
     EN_Gamma4Str1,
     EN_Gamma4Str1,
     EN_Gamma4Str1,
     EN_Gamma4Str1,
     EN_Gamma4Str1,
     EN_Gamma4Str1,
     EN_Gamma4Str1,
     EN_Gamma4Str1,
     EN_Gamma4Str1,
     EN_Gamma4Str1,
     EN_Gamma4Str1,
     EN_Gamma4Str1,
     EN_Gamma4Str1,
     EN_Gamma4Str1,
     
     EN_Gamma5Str1,
     EN_Gamma5Str1,
     EN_Gamma5Str1,
     EN_Gamma5Str1,
     EN_Gamma5Str1,
     EN_Gamma5Str1,
     EN_Gamma5Str1,
     EN_Gamma5Str1,
     EN_Gamma5Str1,
     EN_Gamma5Str1,
     EN_Gamma5Str1,
     EN_Gamma5Str1,
     EN_Gamma5Str1,
     EN_Gamma5Str1,
     EN_Gamma5Str1,
     EN_Gamma5Str1,
     EN_Gamma5Str1,
};

// color temperature item
code UCHAR EN_ColorTempItem1Str1[] = {6, 'N', 'o', 'r', 'm', 'a', 'l', };
code UCHAR FR_ColorTempItem1Str1[] = {6, 'N', 'o', 'r', 'm', 'a', 'l', };
code UCHAR GE_ColorTempItem1Str1[] = {6, 'N', 'o', 'r', 'm', 'a', 'l', };
code UCHAR IT_ColorTempItem1Str1[] = {7, 'N', 'o', 'r', 'm', 'a', 'l', 'e', };
code UCHAR SP_ColorTempItem1Str1[] = {6, 'N', 'o', 'r', 'm', 'a', 'l', };
code UCHAR PO_ColorTempItem1Str1[] = {8, 'N', 'o', 'r', 'm', 'a', 'l', 'n', 'y', };
code UCHAR CZ_ColorTempItem1Str1[] = {8, 'N', 'o', 'r', 'm', 0, 'l', 'n', 1, };
code UCHAR MA_ColorTempItem1Str1[] = {6, 'N', 'o', 'r', 'm', 0, 'l', };
code UCHAR SE_ColorTempItem1Str1[] = {8, 'N', 'o', 'r', 'm', 'a', 'l', 'n', 'o', };
code UCHAR RO_ColorTempItem1Str1[] = {6, 'N', 'o', 'r', 'm', 'a', 'l', };
code UCHAR DU_ColorTempItem1Str1[] = {7, 'N', 'o', 'r', 'm', 'a', 'a', 'l', };
code UCHAR RU_ColorTempItem1Str1[] = {10, 158, 136, 133, 146, 143, 127, 155, 144, 159, 129, };
code UCHAR SW_ColorTempItem1Str1[] = {6, 'N', 'o', 'r', 'm', 'a', 'l', };
code UCHAR PR_ColorTempItem1Str1[] = {6, 'N', 'o', 'r', 'm', 'a', 'l', };
code UCHAR JA_ColorTempItem1Str1[] = {2, 133, 134, };
code UCHAR CT_ColorTempItem1Str1[] = {2, 124, 125, };
code UCHAR CS_ColorTempItem1Str1[] = {2, 125, 126, };

code UCHAR EN_ColorTempItem2Str1[] = {6, 'B', 'l', 'u', 'i', 's', 'h', };
code UCHAR FR_ColorTempItem2Str1[] = {8, 'B', 'l', 'e', 'u', 123, 't', 'r', 'e', };
code UCHAR GE_ColorTempItem2Str1[] = {8, 'B', 'l', 3, 'u', 'l', 'i', 'c', 'h', };
code UCHAR IT_ColorTempItem2Str1[] = {8, 'B', 'l', 'u', 'a', 's', 't', 'r', 'o', };
code UCHAR SP_ColorTempItem2Str1[] = {7, 'A', 'z', 'u', 'l', 'a', 'd', 'o', };
code UCHAR PO_ColorTempItem2Str1[] = {11, 'N', 'i', 'e', 'b', 'i', 'e', 's', 'k', 'a', 'w', 'y', };
code UCHAR CZ_ColorTempItem2Str1[] = {7, 'N', 'a', 'm', 'o', 'd', 'r', '.', };
code UCHAR MA_ColorTempItem2Str1[] = {5, 'K', 2, 'k', 'e', 's', };
code UCHAR SE_ColorTempItem2Str1[] = {9, 'P', 'l', 'a', 'v', 'k', 'a', 's', 't', 'o', };
code UCHAR RO_ColorTempItem2Str1[] = {8, 'A', 'l', 'b', 125, 's', 't', 'r', '.', };
code UCHAR DU_ColorTempItem2Str1[] = {10, 'B', 'l', 'w', '.', ' ', 'T', 'i', 'n', 't', ' ', };
code UCHAR RU_ColorTempItem2Str1[] = {8, 160, 136, 127, 136, 139, 144, 159, 128, };
code UCHAR SW_ColorTempItem2Str1[] = {8, 'B', 'l', 123, 'a', 'k', 't', 'i', 'g', };
code UCHAR PR_ColorTempItem2Str1[] = {7, 'A', 'z', 'u', 'l', 'a', 'd', 'o', };
code UCHAR JA_ColorTempItem2Str1[] = {2, 135, 136, };
code UCHAR CT_ColorTempItem2Str1[] ={2, 126, 127, };
code UCHAR CS_ColorTempItem2Str1[] ={3, 127, 128, 123, };
 
code UCHAR EN_ColorTempItem3Str1[] = {7, 'R', 'e', 'd', 'd', 'i', 's', 'h', };
code UCHAR FR_ColorTempItem3Str1[] = {9, 'R', 'o', 'u', 'g', 'e', 123, 't', 'r', 'e', };
code UCHAR GE_ColorTempItem3Str1[] = {7, 'R', 10, 't', 'l', 'i', 'c', 'h', };
code UCHAR IT_ColorTempItem3Str1[] = {9, 'R', 'o', 's', 's', 'a', 's', 't', 'r', 'o', };
code UCHAR SP_ColorTempItem3Str1[] = {6, 'R', 'o', 'j', 'i', 'z', 'o', };
code UCHAR PO_ColorTempItem3Str1[] = {10, 'C', 'z', 'e', 'r', 'w', 'o', 'n', 'a', 'w', 'y', };
code UCHAR CZ_ColorTempItem3Str1[] = {9, 'N', 'a', 6, 'e', 'r', 'v', 'e', 'n', '.', };
code UCHAR MA_ColorTempItem3Str1[] = {7, 'V', 10, 'r', 10, 's', 'e', 's', };
code UCHAR SE_ColorTempItem3Str1[] = {10, 'C', 'r', 'v', 'e', 'n', 'k', 'a', 's', 't', 'o', };
code UCHAR RO_ColorTempItem3Str1[] = {9, 'R', 'o', 123, 'i', 'a', 't', 'i', 'c', 125, };
code UCHAR DU_ColorTempItem3Str1[] = {9, 'R', 'o', 'd', 'e', ' ', 't', 'i', 'n', 't', };
code UCHAR RU_ColorTempItem3Str1[] = {6, 161, 128, 126, 127, 159, 128, };
code UCHAR SW_ColorTempItem3Str1[] = {8, 'R', 10, 'd', 'a', 'k', 't', 'i', 'g', };
code UCHAR PR_ColorTempItem3Str1[] = {9, 'A', 'v', 'e', 'r', 'm', 'e', 'l', 'h', '.', };
code UCHAR JA_ColorTempItem3Str1[] = {2, 135, 137, };
code UCHAR CT_ColorTempItem3Str1[] = {2, 126, 128, };
code UCHAR CS_ColorTempItem3Str1[] = {3, 127, 129, 123, };
 
code UCHAR EN_ColorTempItem4Str1[] = {11, 'U', 's', 'e', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', };
code UCHAR FR_ColorTempItem4Str1[] = {20, 'D', 2, 'f', '.', ' ', 'p', 'a', 'r', ' ', 'u', 't', 'i', 'l', 'i', 's', 'a', 't', 'e', 'u', 'r', };
code UCHAR GE_ColorTempItem4Str1[] = {17, 'B', 'e', 'n', 'u', 't', 'z', 'e', 'r', 'd', 'e', 'f', 'i', 'n', 'i', 'e', 'r', 't', };
code UCHAR IT_ColorTempItem4Str1[] = {20, 'D', 'e', 'f', 'i', 'n', 'i', 't', 'o', ' ', 'd', 'a', 'l', 'l', 39, 'u', 't', 'e', 'n', 't', 'e', };
code UCHAR SP_ColorTempItem4Str1[] = {20, 'D', 'e', 'f', 'i', 'n', 'i', 'd', 'o', ' ', 'p', 'o', 'r', ' ', 'u', 's', 'u', 'a', 'r', 'i', 'o', };
code UCHAR PO_ColorTempItem4Str1[] = {12, 'Z', 'd', 'e', 'f', '.', ' ', 'u', 124, 'y', 't', 'k', '.', };
code UCHAR CZ_ColorTempItem4Str1[] = {16, 'U', 26, 'i', 'v', '.', ' ', 'D', 'e', 'f', 'i', 'n', 'o', 'v', 0, 'n', 'o', };
code UCHAR MA_ColorTempItem4Str1[] = {17, 'F', 'e', 'l', 'h', 'a', 's', 'z', 'n', 0, 'l', 4, 'i', ' ', 'd', 'e', 'f', '.', };
code UCHAR SE_ColorTempItem4Str1[] = {17, 'O', 'd', 'r', 'e', 123, 'u', 'j', 'e', ' ', 'k', 'o', 'r', 'i', 's', 'n', 'i', 'k', };
code UCHAR RO_ColorTempItem4Str1[] = {14, 'D', 'e', 'f', 'i', 'n', '.', ' ', 'u', 't', 'i', 'l', 'i', 'z', '.', };
code UCHAR DU_ColorTempItem4Str1[] = {14, 'G', 'e', 'b', 'r', 'u', 'i', 'k', 'e', 'r', 'i', 'n', 's', 't', '.', };
code UCHAR RU_ColorTempItem4Str1[] = {14, 162, 126, 133, '.', ' ', 126, 136, 127, 155, 141, '-', 127, 128, 146, };
code UCHAR SW_ColorTempItem4Str1[] = {19, 'A', 'n', 'v', 3, 'n', 'd', 'a', 'r', 'd', 'e', 'f', 'i', 'n', 'i', 'e', 'r', 'i', 'n', 'g', };
code UCHAR PR_ColorTempItem4Str1[] = {17, 'D', 'e', 'f', 'i', 'n', '.', ' ', 'U', 't', 'i', 'l', 'i', 'z', 'a', 'd', 'o', 'r', };
code UCHAR JA_ColorTempItem4Str1[] = {6, 139, 21, 140, 21, 141, 142, };
code UCHAR CT_ColorTempItem4Str1[] = {5, 130, 131, 132, 133, 134, };
code UCHAR CS_ColorTempItem4Str1[] = {4, 131, 132, 133, 134, };
 
code UCHAR *ColorTempItemTab[] = {
     EN_ColorTempItem1Str1,
     FR_ColorTempItem1Str1,
     GE_ColorTempItem1Str1,
     IT_ColorTempItem1Str1,
     SP_ColorTempItem1Str1,
     PO_ColorTempItem1Str1,
     CZ_ColorTempItem1Str1,
     MA_ColorTempItem1Str1,
     SE_ColorTempItem1Str1,
     RO_ColorTempItem1Str1,
     DU_ColorTempItem1Str1,
     RU_ColorTempItem1Str1,
     SW_ColorTempItem1Str1,
     PR_ColorTempItem1Str1,
     JA_ColorTempItem1Str1,
     CT_ColorTempItem1Str1,
     CS_ColorTempItem1Str1,
     
     EN_ColorTempItem2Str1,
     FR_ColorTempItem2Str1,
     GE_ColorTempItem2Str1,
     IT_ColorTempItem2Str1,
     SP_ColorTempItem2Str1,
     PO_ColorTempItem2Str1,
     CZ_ColorTempItem2Str1,
     MA_ColorTempItem2Str1,
     SE_ColorTempItem2Str1,
     RO_ColorTempItem2Str1,
     DU_ColorTempItem2Str1,
     RU_ColorTempItem2Str1,
     SW_ColorTempItem2Str1,
     PR_ColorTempItem2Str1,
     JA_ColorTempItem2Str1,
     CT_ColorTempItem2Str1,
     CS_ColorTempItem2Str1,
     
     EN_ColorTempItem3Str1,
     FR_ColorTempItem3Str1,
     GE_ColorTempItem3Str1,
     IT_ColorTempItem3Str1,
     SP_ColorTempItem3Str1,
     PO_ColorTempItem3Str1,
     CZ_ColorTempItem3Str1,
     MA_ColorTempItem3Str1,
     SE_ColorTempItem3Str1,
     RO_ColorTempItem3Str1,
     DU_ColorTempItem3Str1,
     RU_ColorTempItem3Str1,
     SW_ColorTempItem3Str1,
     PR_ColorTempItem3Str1,
     JA_ColorTempItem3Str1,
     CT_ColorTempItem3Str1,
     CS_ColorTempItem3Str1,
     
     EN_ColorTempItem4Str1,
     FR_ColorTempItem4Str1,
     GE_ColorTempItem4Str1,
     IT_ColorTempItem4Str1,
     SP_ColorTempItem4Str1,
     PO_ColorTempItem4Str1,
     CZ_ColorTempItem4Str1,
     MA_ColorTempItem4Str1,
     SE_ColorTempItem4Str1,
     RO_ColorTempItem4Str1,
     DU_ColorTempItem4Str1,
     RU_ColorTempItem4Str1,
     SW_ColorTempItem4Str1,
     PR_ColorTempItem4Str1,
     JA_ColorTempItem4Str1,
     CT_ColorTempItem4Str1,
     CS_ColorTempItem4Str1,
};


// AMA
code UCHAR EN_AMAItem3Str1[] = {7, 'P', 'r', 'e', 'm', 'i', 'u', 'm', };
code UCHAR FR_AMAItem3Str1[] = {7, 'P', 'r', 'e', 'm', 'i', 'u', 'm', };
code UCHAR GE_AMAItem3Str1[] = {7, 'P', 'r', 'e', 'm', 'i', 'u', 'm', };
code UCHAR IT_AMAItem3Str1[] = {7, 'P', 'r', 'e', 'm', 'i', 'u', 'm', };
code UCHAR SP_AMAItem3Str1[] = {7, 'P', 'r', 'e', 'm', 'i', 'u', 'm', };
code UCHAR PO_AMAItem3Str1[] = {7, 'P', 'r', 'e', 'm', 'i', 'u', 'm', };
code UCHAR CZ_AMAItem3Str1[] = {7, 'P', 'r', 'e', 'm', 'i', 'u', 'm', };
code UCHAR MA_AMAItem3Str1[] = {7, 'P', 'r', 2, 'm', 'i', 'u', 'm', };
code UCHAR SE_AMAItem3Str1[] = {8, 'V', 'r', 'h', 'u', 'n', 's', 'k', 'a', };
code UCHAR RO_AMAItem3Str1[] = {7, 'P', 'r', 'e', 'm', 'i', 'u', 'm', };
code UCHAR DU_AMAItem3Str1[] = {7, 'P', 'r', 'e', 'm', 'i', 'u', 'm', };
code UCHAR RU_AMAItem3Str1[] = {7, 167, 133, 128, 146, 124, 135, 146, };
code UCHAR SW_AMAItem3Str1[] = {7, 'P', 'r', 'e', 'm', 'i', 'u', 'm', };
code UCHAR PR_AMAItem3Str1[] = {7, 'P', 'r', 'e', 'm', 'i', 'u', 'm', };
code UCHAR JA_AMAItem3Str1[] = {5, 127, 151, 152, 153, 154, };
code UCHAR CT_AMAItem3Str1[] = {2, 140, 141, };
code UCHAR CS_AMAItem3Str1[] = {2, 140, 141, };

code UCHAR EN_AMAItem2Str1[] = {4, 'H', 'i', 'g', 'h', };
code UCHAR FR_AMAItem2Str1[] = {6, 24, 'l', 'e', 'v', 2, 'e', };
code UCHAR GE_AMAItem2Str1[] = {4, 'H', 'o', 'c', 'h', };
code UCHAR IT_AMAItem2Str1[] = {4, 'A', 'l', 't', 'o', };
code UCHAR SP_AMAItem2Str1[] = {4, 'A', 'l', 't', 'a', };
code UCHAR PO_AMAItem2Str1[] = {6, 'W', 'y', 's', 'o', 'k', 'a', };
code UCHAR CZ_AMAItem2Str1[] = {6, 'V', 'y', 's', 'o', 'k', 0, };
code UCHAR MA_AMAItem2Str1[] = {5, 'M', 'a', 'g', 'a', 's', };
code UCHAR SE_AMAItem2Str1[] = {11, 'H', 'i', 'g', 'h', '-', 'c', 'o', 'l', 'o', 'u', 'r', };
code UCHAR RO_AMAItem2Str1[] = {8, 'R', 'i', 'd', 'i', 'c', 'a', 't', 125, };
code UCHAR DU_AMAItem2Str1[] = {4, 'H', 'o', 'o', 'g', };
code UCHAR RU_AMAItem2Str1[] = {4, 137, 159, 125, '.', };
code UCHAR SW_AMAItem2Str1[] = {3, 'H', 10, 'g', };
code UCHAR PR_AMAItem2Str1[] = {4, 'A', 'l', 't', 'o', };
code UCHAR JA_AMAItem2Str1[] = {1, 150, };
code UCHAR CT_AMAItem2Str1[] = {1, 140, };
code UCHAR CS_AMAItem2Str1[] = {1, 140, };

code UCHAR EN_AMAItem1Str1[] = {3, 'O', 'F', 'F', };
code UCHAR FR_AMAItem1Str1[] = {7, 'D', 24, 'S', 'A', 'C', 'T', ' ', };
code UCHAR GE_AMAItem1Str1[] = {3, 'A', 'U', 'S', };
code UCHAR IT_AMAItem1Str1[] = {9, 'D', 'I', 'S', 'A', 'T', 'T', 'I', 'V', '.', };
code UCHAR SP_AMAItem1Str1[] = {7, 'D', 'E', 'S', 'A', 'C', 'T', '.', };
code UCHAR PO_AMAItem1Str1[] = {7, 'W', 'Y', 125, 126, 'C', 'Z', '.', };
code UCHAR CZ_AMAItem1Str1[] = {4, 'V', 'Y', 'P', '.', };
code UCHAR MA_AMAItem1Str1[] = {2, 'K', 'I', };
code UCHAR SE_AMAItem1Str1[] = {6, 'I', 'S', 'K', 'L', 'J', '.', };
code UCHAR RO_AMAItem1Str1[] = {5, 'O', 'P', 'R', 'I', 'T', };
code UCHAR DU_AMAItem1Str1[] = {3, 'U', 'I', 'T', };
code UCHAR RU_AMAItem1Str1[] = {5, 137, 165, 153, 166, '.', };
code UCHAR SW_AMAItem1Str1[] = {2, 'A', 'V', };
code UCHAR PR_AMAItem1Str1[] = {8, 'D', 'e', 's', 'l', 'i', 'g', 'a', 'r', };
code UCHAR JA_AMAItem1Str1[] = {2, 149, 19, };
code UCHAR CT_AMAItem1Str1[] = {2, 138, 139, };
code UCHAR CS_AMAItem1Str1[] = {2, 138, 139, };

code UCHAR *AMAItemTab[] = {
     EN_AMAItem1Str1,
     FR_AMAItem1Str1,
     GE_AMAItem1Str1,
     IT_AMAItem1Str1,
     SP_AMAItem1Str1,
     PO_AMAItem1Str1,
     CZ_AMAItem1Str1,
     MA_AMAItem1Str1,
     SE_AMAItem1Str1,
     RO_AMAItem1Str1,
     DU_AMAItem1Str1,
     RU_AMAItem1Str1,
     SW_AMAItem1Str1,
     PR_AMAItem1Str1,
     JA_AMAItem1Str1,
     CT_AMAItem1Str1,
     CS_AMAItem1Str1,
     
     EN_AMAItem2Str1,
     FR_AMAItem2Str1,
     GE_AMAItem2Str1,
     IT_AMAItem2Str1,
     SP_AMAItem2Str1,
     PO_AMAItem2Str1,
     CZ_AMAItem2Str1,
     MA_AMAItem2Str1,
     SE_AMAItem2Str1,
     RO_AMAItem2Str1,
     DU_AMAItem2Str1,
     RU_AMAItem2Str1,
     SW_AMAItem2Str1,
     PR_AMAItem2Str1,
     JA_AMAItem2Str1,
     CT_AMAItem2Str1,
     CS_AMAItem2Str1,
     
     EN_AMAItem3Str1,
     FR_AMAItem3Str1,
     GE_AMAItem3Str1,
     IT_AMAItem3Str1,
     SP_AMAItem3Str1,
     PO_AMAItem3Str1,
     CZ_AMAItem3Str1,
     MA_AMAItem3Str1,
     SE_AMAItem3Str1,
     RO_AMAItem3Str1,
     DU_AMAItem3Str1,
     RU_AMAItem3Str1,
     SW_AMAItem3Str1,
     PR_AMAItem3Str1,
     JA_AMAItem3Str1,
     CT_AMAItem3Str1,
     CS_AMAItem3Str1,
};


// Yes No
code UCHAR EN_YesStr1[] = {3, 'Y', 'E', 'S', };
code UCHAR FR_YesStr1[] = {3, 'O', 'U', 'I', };
code UCHAR GE_YesStr1[] = {2, 'J', 'A', };
code UCHAR IT_YesStr1[] = {2, 'S', 'I', };
code UCHAR SP_YesStr1[] = {2, 'S', 31, };
code UCHAR PO_YesStr1[] = {3, 'T', 'A', 'K', };
code UCHAR CZ_YesStr1[] = {3, 'A', 'N', 'O', };
code UCHAR MA_YesStr1[] = {4, 'I', 'G', 'E', 'N', };
code UCHAR SE_YesStr1[] = {2, 'D', 'A', };
code UCHAR RO_YesStr1[] = {2, 'D', 'A', };
code UCHAR DU_YesStr1[] = {2, 'J', 'A', };
code UCHAR RU_YesStr1[] = {2, 123, 130, };
code UCHAR SW_YesStr1[] = {2, 'J', 'A', };
code UCHAR PR_YesStr1[] = {3, 'S', 'I', 'M', };
code UCHAR JA_YesStr1[] = {2, 254, 183, };
code UCHAR CT_YesStr1[] = {1, 253, };
code UCHAR CS_YesStr1[] = {1, 251, };
 
code UCHAR EN_NoStr1[] = {2, 'N', 'O', };
code UCHAR FR_NoStr1[] = {3, 'N', 'O', 'N', };
code UCHAR GE_NoStr1[] = {4, 'N', 'E', 'I', 'N', };
code UCHAR IT_NoStr1[] = {2, 'N', 'O', };
code UCHAR SP_NoStr1[] = {2, 'N', 'O', };
code UCHAR PO_NoStr1[] = {3, 'N', 'I', 'E', };
code UCHAR CZ_NoStr1[] = {2, 'N', 'E', };
code UCHAR MA_NoStr1[] = {3, 'N', 'E', 'M', };
code UCHAR SE_NoStr1[] = {2, 'N', 'E', };
code UCHAR RO_NoStr1[] = {2, 'N', 'U', };
code UCHAR DU_NoStr1[] = {3, 'N', 'E', 'E', };
code UCHAR RU_NoStr1[] = {3, 158, 169, 161, };
code UCHAR SW_NoStr1[] = {3, 'N', 'E', 'J', };
code UCHAR PR_NoStr1[] = {3, 'N', 125, 'O', };
code UCHAR JA_NoStr1[] = {3, 183, 183, 255, };
code UCHAR CT_NoStr1[] = {1, 254, };
code UCHAR CS_NoStr1[] = {1, 252, };
 
code UCHAR EN_OnStr1[] = {2, 'O', 'N', };
code UCHAR FR_OnStr1[] = {6, 'A', 'C', 'T', 'I', 'V', 24, };
code UCHAR GE_OnStr1[] = {3, 'E', 'I', 'N', };
code UCHAR IT_OnStr1[] = {8, 'A', 'T', 'T', 'I', 'V', 'A', 'T', 'O', };
code UCHAR SP_OnStr1[] = {7, 'A', 'C', 'T', 'I', 'V', 'A', 'R', };
code UCHAR PO_OnStr1[] = {8, 'W', 'L', 126, 'C', 'Z', 'O', 'N', 'Y', };
code UCHAR CZ_OnStr1[] = {4, 'Z', 'A', 'P', '.', };
code UCHAR MA_OnStr1[] = {2, 'B', 'E', };
code UCHAR SE_OnStr1[] = {5, 'U', 'K', 'L', 'J', '.', };
code UCHAR RO_OnStr1[] = {6, 'P', 'O', 'R', 'N', 'I', 'T', };
code UCHAR DU_OnStr1[] = {3, 'A', 'A', 'N', };
code UCHAR RU_OnStr1[] = {4, 137, 153, 166, '.', };
code UCHAR SW_OnStr1[] = {2, 'P', 124, };
code UCHAR PR_OnStr1[] = {5, 'L', 'i', 'g', 'a', 'r', };
code UCHAR JA_OnStr1[] = {2, 149, 28, };
code UCHAR CT_OnStr1[] = {2, 228, 229, };
code UCHAR CS_OnStr1[] = {2, 227, 228, };
 
code UCHAR EN_OffStr1[] = {3, 'O', 'F', 'F', };
code UCHAR FR_OffStr1[] = {7, 'D', 24, 'S', 'A', 'C', 'T', ' ', };
code UCHAR GE_OffStr1[] = {3, 'A', 'U', 'S', };
code UCHAR IT_OffStr1[] = {9, 'D', 'I', 'S', 'A', 'T', 'T', 'I', 'V', '.', };
code UCHAR SP_OffStr1[] = {7, 'D', 'E', 'S', 'A', 'C', 'T', '.', };
code UCHAR PO_OffStr1[] = {7, 'W', 'Y', 125, 126, 'C', 'Z', '.', };
code UCHAR CZ_OffStr1[] = {4, 'V', 'Y', 'P', '.', };
code UCHAR MA_OffStr1[] = {2, 'K', 'I', };
code UCHAR SE_OffStr1[] = {6, 'I', 'S', 'K', 'L', 'J', '.', };
code UCHAR RO_OffStr1[] = {5, 'O', 'P', 'R', 'I', 'T', };
code UCHAR DU_OffStr1[] = {3, 'U', 'I', 'T', };
code UCHAR RU_OffStr1[] = {5, 137, 165, 153, 166, '.', };
code UCHAR SW_OffStr1[] = {2, 'A', 'V', };
code UCHAR PR_OffStr1[] = {8, 'D', 'e', 's', 'l', 'i', 'g', 'a', 'r', };
code UCHAR JA_OffStr1[] = {2, 149, 19, };
code UCHAR CT_OffStr1[] = {2, 138, 139, };
code UCHAR CS_OffStr1[] = {2, 138, 139, };

code UCHAR *YesNoTab1[] = {
     EN_YesStr1,
     FR_YesStr1,
     GE_YesStr1,
     IT_YesStr1,
     SP_YesStr1,
     PO_YesStr1,
     CZ_YesStr1,
     MA_YesStr1,
     SE_YesStr1,
     RO_YesStr1,
     DU_YesStr1,
     RU_YesStr1,
     SW_YesStr1,
     PR_YesStr1,
     JA_YesStr1,
     CT_YesStr1,
     CS_YesStr1,
     
     EN_NoStr1,
     FR_NoStr1,
     GE_NoStr1,
     IT_NoStr1,
     SP_NoStr1,
     PO_NoStr1,
     CZ_NoStr1,
     MA_NoStr1,
     SE_NoStr1,
     RO_NoStr1,
     DU_NoStr1,
     RU_NoStr1,
     SW_NoStr1,
     PR_NoStr1,
     JA_NoStr1,
     CT_NoStr1,
     CS_NoStr1,
};
code UCHAR *OnOffTab1[] = {
     EN_OnStr1,
     FR_OnStr1,
     GE_OnStr1,
     IT_OnStr1,
     SP_OnStr1,
     PO_OnStr1,
     CZ_OnStr1,
     MA_OnStr1,
     SE_OnStr1,
     RO_OnStr1,
     DU_OnStr1,
     RU_OnStr1,
     SW_OnStr1,
     PR_OnStr1,
     JA_OnStr1,
     CT_OnStr1,
     CS_OnStr1,
     
     EN_OffStr1,
     FR_OffStr1,
     GE_OffStr1,
     IT_OffStr1,
     SP_OffStr1,
     PO_OffStr1,
     CZ_OffStr1,
     MA_OffStr1,
     SE_OffStr1,
     RO_OffStr1,
     DU_OffStr1,
     RU_OffStr1,
     SW_OffStr1,
     PR_OffStr1,
     JA_OffStr1,
     CT_OffStr1,
     CS_OffStr1,
};

#if ENABLE_AUTO_POVIT_FUNC == ON  
code UCHAR **SecondLevelTabOfMItem1[] = {NULL,OnOffTab1,InputTab1, NULL, NULL, NULL, NULL};
#else
code UCHAR **SecondLevelTabOfMItem1[] = {NULL,InputTab1, NULL, NULL, NULL, NULL};
#endif

code UCHAR **SecondLevelTabOfMItem2[] = {NULL, NULL, NULL, GammaStrTab, ColorTempItemTab, NULL, NULL, YesNoTab1, AMAItemTab};


// picture advanced mode
code UCHAR EN_StanddardStr1[] = {8, 'S', 't', 'a', 'n', 'd', 'a', 'r', 'd', };
code UCHAR FR_StanddardStr1[] = {8, 'S', 't', 'a', 'n', 'd', 'a', 'r', 'd', };
code UCHAR GE_StanddardStr1[] = {8, 'S', 't', 'a', 'n', 'd', 'a', 'r', 'd', };
code UCHAR IT_StanddardStr1[] = {8, 'S', 't', 'a', 'n', 'd', 'a', 'r', 'd', };
code UCHAR SP_StanddardStr1[] = {8, 'E', 's', 't', 0, 'n', 'd', 'a', 'r', };
code UCHAR PO_StanddardStr1[] = {8, 'S', 't', 'a', 'n', 'd', 'a', 'r', 'd', };
code UCHAR CZ_StanddardStr1[] = {10, 'S', 't', 'a', 'n', 'd', 'a', 'r', 'd', 'n', 1, };
code UCHAR MA_StanddardStr1[] = {7, 'N', 'o', 'r', 'm', 0, 'l', ' ', };
code UCHAR SE_StanddardStr1[] = {8, 'S', 't', 'a', 'n', 'd', 'a', 'r', 'd', };
code UCHAR RO_StanddardStr1[] = {8, 'S', 't', 'a', 'n', 'd', 'a', 'r', 'd', };
code UCHAR DU_StanddardStr1[] = {9, 'S', 't', 'a', 'n', 'd', 'a', 'a', 'r', 'd', };
code UCHAR RU_StanddardStr1[] = {8, 164, 132, 143, 144, 139, 143, 133, 132, };
code UCHAR SW_StanddardStr1[] = {8, 'S', 't', 'a', 'n', 'd', 'a', 'r', 'd', };
code UCHAR PR_StanddardStr1[] = {6, 'P', 'a', 'd', 'r', 123, 'o', };
code UCHAR JA_StanddardStr1[] = {3, 133, 134, 162, };
code UCHAR CT_StanddardStr1[] = {2, 124, 125, };
code UCHAR CS_StanddardStr1[] = {2, 125, 126, };

code UCHAR EN_MovieStr1[] = {5, 'M', 'o', 'v', 'i', 'e', };
code UCHAR FR_MovieStr1[] = {5, 'F', 'i', 'l', 'm', ' ', };
code UCHAR GE_MovieStr1[] = {4, 'F', 'i', 'l', 'm', };
code UCHAR IT_MovieStr1[] = {4, 'F', 'i', 'l', 'm', };
code UCHAR SP_MovieStr1[] = {8, 'P', 'e', 'l', 1, 'c', 'u', 'l', 'a', };
code UCHAR PO_MovieStr1[] = {5, 'F', 'i', 'l', 'm', ' ', };
code UCHAR CZ_MovieStr1[] = {5, 'F', 'i', 'l', 'm', ' ', };
code UCHAR MA_MovieStr1[] = {5, 'F', 'i', 'l', 'm', ' ', };
code UCHAR SE_MovieStr1[] = {5, 'F', 'i', 'l', 'm', ' ', };
code UCHAR RO_MovieStr1[] = {5, 'F', 'i', 'l', 'm', ' ', };
code UCHAR DU_MovieStr1[] = {5, 'F', 'i', 'l', 'm', ' ', };
code UCHAR RU_MovieStr1[] = {5, 153, 124, 144, 136, ' ', };
code UCHAR SW_MovieStr1[] = {5, 'F', 'i', 'l', 'm', ' ', };
code UCHAR PR_MovieStr1[] = {6, 'F', 'i', 'l', 'm', 'e', ' ', };
code UCHAR JA_MovieStr1[] = {2, 3, 25, };
code UCHAR CT_MovieStr1[] = {2, 167, 168, };
code UCHAR CS_MovieStr1[] = {2, 165, 168, };

code UCHAR EN_GameStr1[] =  {4, 'G', 'a', 'm', 'e', };
code UCHAR FR_GameStr1[] =  {3, 'J', 'e', 'u', };
code UCHAR GE_GameStr1[] =  {6, 'S', 'p', 'i', 'e', 'l', 'e', };
code UCHAR IT_GameStr1[] =  {6, 'G', 'i', 'o', 'c', 'h', 'i', };
code UCHAR SP_GameStr1[] =  {5, 'J', 'u', 'e', 'g', 'o', };
code UCHAR PO_GameStr1[] =  {3, 'G', 'r', 'y', };
code UCHAR CZ_GameStr1[] =  {3, 'H', 'r', 'a', };
code UCHAR MA_GameStr1[] =  {5, 'J', 0, 't', 2, 'k', };
code UCHAR SE_GameStr1[] =  {4, 'I', 'g', 'r', 'a', };
code UCHAR RO_GameStr1[] =  {6, 'J', 'o', 'c', 'u', 'r', 'i', };
code UCHAR DU_GameStr1[] =  {4, 'S', 'p', 'e', 'l', };
code UCHAR RU_GameStr1[] =  {4, 150, 'r', 'p', 'a', };
code UCHAR SW_GameStr1[] =  {4, 'S', 'p', 'e', 'l', };
code UCHAR PR_GameStr1[] =  {4, 'J', 'o', 'g', 'o', };
code UCHAR JA_GameStr1[] =  {3, 176, 21, 154, };
code UCHAR CT_GameStr1[] =  {2, 165, 166, };
code UCHAR CS_GameStr1[] =  {2, 166, 167, };

code UCHAR EN_PhotoStr1[] = {5, 'P', 'h', 'o', 't', 'o', };
code UCHAR FR_PhotoStr1[] = {5, 'P', 'h', 'o', 't', 'o', };
code UCHAR GE_PhotoStr1[] = {4, 'F', 'o', 't', 'o', };
code UCHAR IT_PhotoStr1[] = {4, 'F', 'o', 't', 'o', };
code UCHAR SP_PhotoStr1[] = {8, 'F', 'o', 't', 'o', 12, 12, 12, 12, };
code UCHAR PO_PhotoStr1[] = {7, 'Z', 'd', 'j', 128, 'c', 'i', 'e', };
code UCHAR CZ_PhotoStr1[] = {4, 'F', 'o', 't', 'o', };
code UCHAR MA_PhotoStr1[] = {4, 'F', 'o', 't', 4, };
code UCHAR SE_PhotoStr1[] = {4, 'F', 'o', 't', 'o', };
code UCHAR RO_PhotoStr1[] = {4, 'F', 'o', 't', 'o', };
code UCHAR DU_PhotoStr1[] = {4, 'F', 'o', 't', 'o', };
code UCHAR RU_PhotoStr1[] = {4, 145, 136, 132, 136, };
code UCHAR SW_PhotoStr1[] = {4, 'F', 'o', 't', 'o', };
code UCHAR PR_PhotoStr1[] = {4, 'F', 'o', 't', 'o', };
code UCHAR JA_PhotoStr1[] = {2, 174, 175, };
code UCHAR CT_PhotoStr1[] = {3, 164, 24, ' ', };
code UCHAR CS_PhotoStr1[] = {2, 23, 24, };

code UCHAR EN_sRGBStr1[] = {4,"sRGB"};
/*
code UCHAR FR_sRGBStr1[] = {4,"sRGB"};
code UCHAR GE_sRGBStr1[] = {4,"sRGB"};
code UCHAR IT_sRGBStr1[] = {4,"sRGB"};
code UCHAR SP_sRGBStr1[] = {4,"sRGB"};
code UCHAR PO_sRGBStr1[] = {4,"sRGB"};
code UCHAR CZ_sRGBStr1[] = {4,"sRGB"};
code UCHAR MA_sRGBStr1[] = {4,"sRGB"};
code UCHAR SE_sRGBStr1[] = {4,"sRGB"};
code UCHAR RO_sRGBStr1[] = {4,"sRGB"};
code UCHAR DU_sRGBStr1[] = {4,"sRGB"};
code UCHAR RU_sRGBStr1[] = {4,"sRGB"};
code UCHAR SW_sRGBStr1[] = {4,"sRGB"};
code UCHAR PR_sRGBStr1[] = {4,"sRGB"};
code UCHAR JA_sRGBStr1[] = {4,"sRGB"};
code UCHAR CT_sRGBStr1[] = {4,"sRGB"};
code UCHAR CS_sRGBStr1[] = {4,"sRGB"};
*/

/*
code UCHAR EN_ReadingStr1[] =  {7, 'R', 'e', 'a', 'd', 'i', 'n', 'g', };
code UCHAR FR_ReadingStr1[] =  {7, 'L', 'e', 'c', 't', 'u', 'r', 'e', };
code UCHAR GE_ReadingStr1[] =  {5, 'L', 'e', 's', 'e', 'n', };
code UCHAR IT_ReadingStr1[] =  {7, 'L', 'e', 't', 't', 'u', 'r', 'a', };
code UCHAR SP_ReadingStr1[] =  {7, 'L', 'e', 'c', 't', 'u', 'r', 'a', };
code UCHAR PO_ReadingStr1[] =  {8, 'C', 'z', 'y', 't', 'a', 'n', 'i', 'e', };
code UCHAR CZ_ReadingStr1[] =  {5, 27, 't', 'e', 'n', 1, };
code UCHAR MA_ReadingStr1[] =  {7, 'O', 'l', 'v', 'a', 's', 0, 's', };
code UCHAR SE_ReadingStr1[] =  {7, 27, 'i', 't', 'a', 'n', 'j', 'e', };
code UCHAR RO_ReadingStr1[] =  {6, 'C', 'i', 't', 'i', 'r', 'e', };
code UCHAR DU_ReadingStr1[] =  {5, 'L', 'e', 'z', 'e', 'n', };
code UCHAR RU_ReadingStr1[] =  {6, 147, 132, 128, 144, 124, 128, };
code UCHAR SW_ReadingStr1[] =  {7, 'L', 3, 's', 'n', 'i', 'n', 'g', };
code UCHAR PR_ReadingStr1[] =  {7, 'L', 'e', 'i', 't', 'u', 'r', 'a', };
code UCHAR JA_ReadingStr1[] =  {2, 177, 178, };
code UCHAR CT_ReadingStr1[] =  {2, 171, 172, };
code UCHAR CS_ReadingStr1[] =  {2, 170, 171, };*/

code UCHAR EN_EcoStr1[] = {3, 'E', 'c', 'o', };
code UCHAR FR_EcoStr1[] = {3, 24, 'c', 'o', };
code UCHAR GE_EcoStr1[] = {4, 'S', 'p', 'a', 'r', };
code UCHAR IT_EcoStr1[] = {3, 'E', 'c', 'o', };
code UCHAR SP_EcoStr1[] = {3, 'E', 'c', 'o', };
code UCHAR PO_EcoStr1[] = {3, 'E', 'k', 'o', };
code UCHAR CZ_EcoStr1[] = {3, 'E', 'k', 'o', };
code UCHAR MA_EcoStr1[] = {9, 'T', 'a', 'k', 'a', 'r', 2, 'k', 'o', 's', };
code UCHAR SE_EcoStr1[] = {3, 'E', 'k', 'o', };
code UCHAR RO_EcoStr1[] = {3, 'E', 'c', 'o', };
code UCHAR DU_EcoStr1[] = {3, 'E', 'c', 'o', };
code UCHAR RU_EcoStr1[] = {3, 'E', 'c', 'o', };
code UCHAR SW_EcoStr1[] = {3, 'E', 'k', 'o', };
code UCHAR PR_EcoStr1[] = {3, 'E', 'c', 'o', };
code UCHAR JA_EcoStr1[] = {2, 173, 27, };
code UCHAR CT_EcoStr1[] = {3, 'E', 'c', 'o', };
code UCHAR CS_EcoStr1[] = {2, 164, 165, };

code UCHAR EN_MbookStr1[] = {6, 'M', '-', 'b', 'o', 'o', 'k', };
/*
code UCHAR FR_MbookStr1[] = {6, 'M', '-', 'b', 'o', 'o', 'k', };
code UCHAR GE_MbookStr1[] = {6, 'M', '-', 'b', 'o', 'o', 'k', };
code UCHAR IT_MbookStr1[] = {6, 'M', '-', 'b', 'o', 'o', 'k', };
code UCHAR SP_MbookStr1[] = {6, 'M', '-', 'b', 'o', 'o', 'k', };
code UCHAR PO_MbookStr1[] = {6, 'M', '-', 'b', 'o', 'o', 'k', };
code UCHAR CZ_MbookStr1[] = {6, 'M', '-', 'b', 'o', 'o', 'k', };
code UCHAR MA_MbookStr1[] = {6, 'M', '-', 'b', 'o', 'o', 'k', };
code UCHAR SE_MbookStr1[] = {6, 'M', '-', 'b', 'o', 'o', 'k', };
code UCHAR RO_MbookStr1[] = {6, 'M', '-', 'b', 'o', 'o', 'k', };
code UCHAR DU_MbookStr1[] = {6, 'M', '-', 'b', 'o', 'o', 'k', };
code UCHAR RU_MbookStr1[] = {6, 'M', '-', 'b', 'o', 'o', 'k', };
code UCHAR SW_MbookStr1[] = {6, 'M', '-', 'b', 'o', 'o', 'k', };
code UCHAR PR_MbookStr1[] = {6, 'M', '-', 'b', 'o', 'o', 'k', };
code UCHAR JA_MbookStr1[] = {6, 'M', '-', 'b', 'o', 'o', 'k', };
code UCHAR CT_MbookStr1[] = {6, 'M', '-', 'b', 'o', 'o', 'k', };
code UCHAR CS_MbookStr1[] = {6, 'M', '-', 'b', 'o', 'o', 'k', };
*/
 
code UCHAR EN_UserStr1[] = {4, 'U', 's', 'e', 'r', };
code UCHAR FR_UserStr1[] = {11, 'U', 't', 'i', 'l', 'i', 's', 'a', 't', 'e', 'u', 'r', };
code UCHAR GE_UserStr1[] = {8, 'B', 'e', 'n', 'u', 't', 'z', 'e', 'r', };
code UCHAR IT_UserStr1[] = {6, 'U', 't', 'e', 'n', 't', 'e', };
code UCHAR SP_UserStr1[] = {7, 'U', 's', 'u', 'a', 'r', 'i', 'o', };
code UCHAR PO_UserStr1[] = {6, 'U', 124, 'y', 't', 'k', '.', };
code UCHAR CZ_UserStr1[] = {8, 'U', 26, 'i', 'v', 'a', 't', 'e', 'l', };
code UCHAR MA_UserStr1[] = {11, 'F', 'e', 'l', 'h', 'a', 's', 'z', 'n', 0, 'l', 4, };
code UCHAR SE_UserStr1[] = {8, 'K', 'o', 'r', 'i', 's', 'n', 'i', 'k', };
code UCHAR RO_UserStr1[] = {10, 'U', 't', 'i', 'l', 'i', 'z', 'a', 't', 'o', 'r', };
code UCHAR DU_UserStr1[] = {9, 'G', 'e', 'b', 'r', 'u', 'i', 'k', 'e', 'r', };
code UCHAR RU_UserStr1[] = {8, 167, 136, 127, 155, 141, 136, 131, '.', };
code UCHAR SW_UserStr1[] = {9, 'A', 'n', 'v', 3, 'n', 'd', 'a', 'r', 'e', };
code UCHAR PR_UserStr1[] = {10, 'U', 't', 'i', 'l', 'i', 'z', 'a', 'd', 'o', 'r', };
code UCHAR JA_UserStr1[] = {4, 139, 21, 140, 21, };
code UCHAR CT_UserStr1[] = {3, 130, 131, 132, };
code UCHAR CS_UserStr1[] = {2, 131, 132, };

code UCHAR *PictureModeTab1[] = {
     
     EN_StanddardStr1,
     FR_StanddardStr1,
     GE_StanddardStr1,
     IT_StanddardStr1,
     SP_StanddardStr1,
     PO_StanddardStr1,
     CZ_StanddardStr1,
     MA_StanddardStr1,
     SE_StanddardStr1,
     RO_StanddardStr1,
     DU_StanddardStr1,
     RU_StanddardStr1,
     SW_StanddardStr1,
     PR_StanddardStr1,
     JA_StanddardStr1,
     CT_StanddardStr1,
     CS_StanddardStr1,
     
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     JA_LowBlueLightStr1,
     CT_LowBlueLightStr1,
     CS_LowBlueLightStr1,
     
     EN_MovieStr1,
     FR_MovieStr1,
     GE_MovieStr1,
     IT_MovieStr1,
     SP_MovieStr1,
     PO_MovieStr1,
     CZ_MovieStr1,
     MA_MovieStr1,
     SE_MovieStr1,
     RO_MovieStr1,
     DU_MovieStr1,
     RU_MovieStr1,
     SW_MovieStr1,
     PR_MovieStr1,
     JA_MovieStr1,
     CT_MovieStr1,
     CS_MovieStr1,

     EN_GameStr1,
     FR_GameStr1,
     GE_GameStr1,
     IT_GameStr1,
     SP_GameStr1,
     PO_GameStr1,
     CZ_GameStr1,
     MA_GameStr1,
     SE_GameStr1,
     RO_GameStr1,
     DU_GameStr1,
     RU_GameStr1,
     SW_GameStr1,
     PR_GameStr1,
     JA_GameStr1,
     CT_GameStr1,
     CS_GameStr1,

     EN_PhotoStr1,
     FR_PhotoStr1,
     GE_PhotoStr1,
     IT_PhotoStr1,
     SP_PhotoStr1,
     PO_PhotoStr1,
     CZ_PhotoStr1,
     MA_PhotoStr1,
     SE_PhotoStr1,
     RO_PhotoStr1,
     DU_PhotoStr1,
     RU_PhotoStr1,
     SW_PhotoStr1,
     PR_PhotoStr1,
     JA_PhotoStr1,
     CT_PhotoStr1,
     CS_PhotoStr1,
     

     /*
     EN_ReadingStr1,
     FR_ReadingStr1,
     GE_ReadingStr1,
     IT_ReadingStr1,
     SP_ReadingStr1,
     PO_ReadingStr1,
     CZ_ReadingStr1,
     MA_ReadingStr1,
     SE_ReadingStr1,
     RO_ReadingStr1,
     DU_ReadingStr1,
     RU_ReadingStr1,
     SW_ReadingStr1,
     PR_ReadingStr1,
     JA_ReadingStr1,
     CT_ReadingStr1,
     CS_ReadingStr1,*/

     EN_sRGBStr1,
     EN_sRGBStr1,//FR
     EN_sRGBStr1,//GE
     EN_sRGBStr1,//IT
     EN_sRGBStr1,//SP
     EN_sRGBStr1,//PO
     EN_sRGBStr1,//CZ
     EN_sRGBStr1,//MA
     EN_sRGBStr1,//SE
     EN_sRGBStr1,//RO
     EN_sRGBStr1,//DU
     EN_sRGBStr1,//RU
     EN_sRGBStr1,//SW
     EN_sRGBStr1,//PR
     EN_sRGBStr1,//JA
     EN_sRGBStr1,//CT
     EN_sRGBStr1,//CS
     
     EN_EcoStr1,
     FR_EcoStr1,
     GE_EcoStr1,
     IT_EcoStr1,
     SP_EcoStr1,
     PO_EcoStr1,
     CZ_EcoStr1,
     MA_EcoStr1,
     SE_EcoStr1,
     RO_EcoStr1,
     DU_EcoStr1,
     RU_EcoStr1,
     SW_EcoStr1,
     PR_EcoStr1,
     JA_EcoStr1,
     CT_EcoStr1,
     CS_EcoStr1,
#if ENABLE_PICTURE_MODE_MBOOK == ON
     EN_MbookStr1,
     EN_MbookStr1,//FR
     EN_MbookStr1,//GE
     EN_MbookStr1,//IT
     EN_MbookStr1,//SP
     EN_MbookStr1,//PO
     EN_MbookStr1,//CZ
     EN_MbookStr1,//MA
     EN_MbookStr1,//SE
     EN_MbookStr1,//RO
     EN_MbookStr1,//DU
     EN_MbookStr1,//RU
     EN_MbookStr1,//SW
     EN_MbookStr1,//PR
     EN_MbookStr1,//JA
     EN_MbookStr1,//CT
     EN_MbookStr1,//CS
#endif
     EN_UserStr1,
     FR_UserStr1,
     GE_UserStr1,
     IT_UserStr1,
     SP_UserStr1,
     PO_UserStr1,
     CZ_UserStr1,
     MA_UserStr1,
     SE_UserStr1,
     RO_UserStr1,
     DU_UserStr1,
     RU_UserStr1,
     SW_UserStr1,
     PR_UserStr1,
     JA_UserStr1,
     CT_UserStr1,
     CS_UserStr1,
};
code UCHAR EN_1TO1Str1[] = {3, 49,58,49};
code UCHAR FR_1TO1Str1[] = {3, 49,58,49};
code UCHAR GE_1TO1Str1[] = {3, 49,58,49};
code UCHAR IT_1TO1Str1[] = {3, 49,58,49};
code UCHAR SP_1TO1Str1[] = {3, 49,58,49};
code UCHAR PO_1TO1Str1[] = {3, 49,58,49};
code UCHAR CZ_1TO1Str1[] = {3, 49,58,49};
code UCHAR MA_1TO1Str1[] = {3, 49,58,49};
code UCHAR SE_1TO1Str1[] = {3, 49,58,49};
code UCHAR RO_1TO1Str1[] = {3, 49,58,49};
code UCHAR DU_1TO1Str1[] = {3, 49,58,49};
code UCHAR RU_1TO1Str1[] = {3, 49,58,49};
code UCHAR SW_1TO1Str1[] = {3, 49,58,49};
code UCHAR PR_1TO1Str1[] = {3, 49,58,49};
code UCHAR JA_1TO1Str1[] = {3, 49,58,49};
code UCHAR CT_1TO1Str1[] = {3, 49,58,49};
code UCHAR CS_1TO1Str1[] = {3, 49,58,49};

code UCHAR EN_FullStr1[] = {4, 'F', 'u', 'l', 'l', };
code UCHAR FR_FullStr1[] = {5, 'P', 'l', 'e', 'i', 'n', };
code UCHAR GE_FullStr1[] = {4, 'V', 'o', 'l', 'l', };
code UCHAR IT_FullStr1[] = {6, 'I', 'n', 't', 'e', 'r', 'o', };
code UCHAR SP_FullStr1[] = {5, 'L', 'l', 'e', 'n', 'o', };
code UCHAR PO_FullStr1[] = {5, 'P', 'e', 129, 'n', 'y', };
code UCHAR CZ_FullStr1[] = {4, 'C', 'e', 'l', 0, };
code UCHAR MA_FullStr1[] = {6, 'T', 'e', 'l', 'j', 'e', 's', };
code UCHAR SE_FullStr1[] = {5, 'P', 'u', 'n', 'i', ' ', };
code UCHAR RO_FullStr1[] = {7, 'C', 'o', 'm', 'p', 'l', 'e', 't', };
code UCHAR DU_FullStr1[] = {8, 'V', 'o', 'l', 'l', 'e', 'd', 'i', 'g', };
code UCHAR RU_FullStr1[] = {4, 137, 128, 125, 155, };
code UCHAR SW_FullStr1[] = {3, 'H', 'e', 'l', };
code UCHAR PR_FullStr1[] = {8, 'C', 'o', 'm', 'p', 'l', 'e', 't', 'o', };
code UCHAR JA_FullStr1[] = {3, 187, 25, 186, };
code UCHAR CT_FullStr1[] = {3, 181, 182, 183, };
code UCHAR CS_FullStr1[] = {3, 180, 181, 182, };

code UCHAR EN_AspectStr1[] = {6, 'A', 's', 'p', 'e', 'c', 't', };
code UCHAR FR_AspectStr1[] = {6, 'F', 'o', 'r', 'm', 'a', 't', };
code UCHAR GE_AspectStr1[] = {16, 'S', 'e', 'i', 't', 'e', 'n', 'v', 'e', 'r', 'h', 3, 'l', 't', 'n', 'i', 's', };
code UCHAR IT_AspectStr1[] = {15, 'P', 'r', 'o', 'p', 'o', 'r', 'z', 'i', 'o', 'n', 'i', ' ', 'i', 'm', 'm', };
code UCHAR SP_AspectStr1[] = {10, 'P', 'r', 'o', 'p', 'o', 'r', 'c', 'i', 4, 'n', };
code UCHAR PO_AspectStr1[] = {13, 'F', 'o', 'r', 'm', 'a', 't', ' ', 'o', 'b', 'r', 'a', 'z', 'u', };
code UCHAR CZ_AspectStr1[] = {11, 'P', 'o', 'm', 127, 'r', ' ', 's', 't', 'r', 'a', 'n', };
code UCHAR MA_AspectStr1[] = {8, 'K', 2, 'p', 'a', 'r', 0, 'n', 'y', };
code UCHAR SE_AspectStr1[] = {9, 'O', 6, 'e', 'k', 'i', 'v', 'a', 'n', 'i', };
code UCHAR RO_AspectStr1[] = {6, 'A', 's', 'p', 'e', 'c', 't', };
code UCHAR DU_AspectStr1[] = {15, 'B', 'e', 'e', 'l', 'd', 'v', 'e', 'r', 'h', 'o', 'u', 'd', 'i', 'n', 'g', };
code UCHAR RU_AspectStr1[] = {6, 145, 136, 133, 146, 143, 132, };
code UCHAR SW_AspectStr1[] = {15, 'B', 'i', 'l', 'd', 'f', 10, 'r', 'h', 123, 'l', 'l', 'a', 'n', 'd', 'e', };
code UCHAR PR_AspectStr1[] = {7, 'A', 's', 'p', 'e', 'c', 't', 'o', };
code UCHAR JA_AspectStr1[] = {3, 188, 189, 190, };
code UCHAR CT_AspectStr1[] = {3, 184, 26, 185, };
code UCHAR CS_AspectStr1[] = {3, 183, 26, 184, };
 
code UCHAR *FullAspectTab1[] = {
     EN_1TO1Str1,
     FR_1TO1Str1,
     GE_1TO1Str1,
     IT_1TO1Str1,
     SP_1TO1Str1,
     PO_1TO1Str1,
     CZ_1TO1Str1,
     MA_1TO1Str1,
     SE_1TO1Str1,
     RO_1TO1Str1,
     DU_1TO1Str1,
     RU_1TO1Str1,
     SW_1TO1Str1,
     PR_1TO1Str1,
     JA_1TO1Str1,
     CT_1TO1Str1,
     CS_1TO1Str1,

     EN_FullStr1,
     FR_FullStr1,
     GE_FullStr1,
     IT_FullStr1,
     SP_FullStr1,
     PO_FullStr1,
     CZ_FullStr1,
     MA_FullStr1,
     SE_FullStr1,
     RO_FullStr1,
     DU_FullStr1,
     RU_FullStr1,
     SW_FullStr1,
     PR_FullStr1,
     JA_FullStr1,
     CT_FullStr1,
     CS_FullStr1,
     
     EN_AspectStr1,
     FR_AspectStr1,
     GE_AspectStr1,
     IT_AspectStr1,
     SP_AspectStr1,
     PO_AspectStr1,
     CZ_AspectStr1,
     MA_AspectStr1,
     SE_AspectStr1,
     RO_AspectStr1,
     DU_AspectStr1,
     RU_AspectStr1,
     SW_AspectStr1,
     PR_AspectStr1,
     JA_AspectStr1,
     CT_AspectStr1,
     CS_AspectStr1,
};

code UCHAR EN_RGBStr1[] = {3,"RGB"};
/*
code UCHAR FR_RGBStr1[] = {3,"RGB"};
code UCHAR GE_RGBStr1[] = {3,"RGB"};
code UCHAR IT_RGBStr1[] = {3,"RGB"};
code UCHAR SP_RGBStr1[] = {3,"RGB"};
code UCHAR PO_RGBStr1[] = {3,"RGB"};
code UCHAR CZ_RGBStr1[] = {3,"RGB"};
code UCHAR MA_RGBStr1[] = {3,"RGB"};
code UCHAR SE_RGBStr1[] = {3,"RGB"};
code UCHAR RO_RGBStr1[] = {3,"RGB"};
code UCHAR DU_RGBStr1[] = {3,"RGB"};
code UCHAR RU_RGBStr1[] = {3,"RGB"};
code UCHAR SW_RGBStr1[] = {3,"RGB"};
code UCHAR PR_RGBStr1[] = {3,"RGB"};
code UCHAR JA_RGBStr1[] = {3,"RGB"};
code UCHAR CT_RGBStr1[] = {3,"RGB"};
code UCHAR CS_RGBStr1[] = {3,"RGB"};
*/

code UCHAR EN_YUVStr1[] = {3,"YUV"};
/*
code UCHAR FR_YUVStr1[] = {3,"YUV"};
code UCHAR GE_YUVStr1[] = {3,"YUV"};
code UCHAR IT_YUVStr1[] = {3,"YUV"};
code UCHAR SP_YUVStr1[] = {3,"YUV"};
code UCHAR PO_YUVStr1[] = {3,"YUV"};
code UCHAR CZ_YUVStr1[] = {3,"YUV"};
code UCHAR MA_YUVStr1[] = {3,"YUV"};
code UCHAR SE_YUVStr1[] = {3,"YUV"};
code UCHAR RO_YUVStr1[] = {3,"YUV"};
code UCHAR DU_YUVStr1[] = {3,"YUV"};
code UCHAR RU_YUVStr1[] = {3,"YUV"};
code UCHAR SW_YUVStr1[] = {3,"YUV"};
code UCHAR PR_YUVStr1[] = {3,"YUV"};
code UCHAR JA_YUVStr1[] = {3,"YUV"};
code UCHAR CT_YUVStr1[] = {3,"YUV"};
code UCHAR CS_YUVStr1[] = {3,"YUV"};
*/

code UCHAR *ColorFormatTab1[] = {
     EN_RGBStr1,
     EN_RGBStr1,//FR
     EN_RGBStr1,//GE
     EN_RGBStr1,//IT
     EN_RGBStr1,//SP
     EN_RGBStr1,//PO
     EN_RGBStr1,//CZ
     EN_RGBStr1,//MA
     EN_RGBStr1,//SE
     EN_RGBStr1,//RO
     EN_RGBStr1,//DU
     EN_RGBStr1,//RU
     EN_RGBStr1,//SW
     EN_RGBStr1,//PR
     EN_RGBStr1,//JA
     EN_RGBStr1,//CT
     EN_RGBStr1,//CS
     
     EN_YUVStr1,
     EN_YUVStr1,//FR
     EN_YUVStr1,//GE
     EN_YUVStr1,//IT
     EN_YUVStr1,//SP
     EN_YUVStr1,//PO
     EN_YUVStr1,//CZ
     EN_YUVStr1,//MA
     EN_YUVStr1,//SE
     EN_YUVStr1,//RO
     EN_YUVStr1,//DU
     EN_YUVStr1,//RU
     EN_YUVStr1,//SW
     EN_YUVStr1,//PR
     EN_YUVStr1,//JA
     EN_YUVStr1,//CT
     EN_YUVStr1,//CS
};






code UCHAR EN_RGB0to255Str1[] = {11,'R','G','B',40,48,94,50,53,53,41,32};
/*
code UCHAR FR_RGB0to255Str1[] = {11,'R','G','B',40,48,94,50,53,53,41,32};
code UCHAR GE_RGB0to255Str1[] = {11,'R','G','B',40,48,94,50,53,53,41,32};
code UCHAR IT_RGB0to255Str1[] = {11,'R','G','B',40,48,94,50,53,53,41,32};
code UCHAR SP_RGB0to255Str1[] = {11,'R','G','B',40,48,94,50,53,53,41,32};
code UCHAR PO_RGB0to255Str1[] = {11,'R','G','B',40,48,94,50,53,53,41,32};
code UCHAR CZ_RGB0to255Str1[] = {11,'R','G','B',40,48,94,50,53,53,41,32};
code UCHAR MA_RGB0to255Str1[] = {11,'R','G','B',40,48,94,50,53,53,41,32};
code UCHAR SE_RGB0to255Str1[] = {11,'R','G','B',40,48,94,50,53,53,41,32};
code UCHAR RO_RGB0to255Str1[] = {11,'R','G','B',40,48,94,50,53,53,41,32};
code UCHAR DU_RGB0to255Str1[] = {11,'R','G','B',40,48,94,50,53,53,41,32};
code UCHAR RU_RGB0to255Str1[] = {11,'R','G','B',40,48,94,50,53,53,41,32};
code UCHAR SW_RGB0to255Str1[] = {11,'R','G','B',40,48,94,50,53,53,41,32};
code UCHAR PR_RGB0to255Str1[] = {11,'R','G','B',40,48,94,50,53,53,41,32};
code UCHAR JA_RGB0to255Str1[] = {11,'R','G','B',40,48,94,50,53,53,41,32};
code UCHAR CT_RGB0to255Str1[] = {11,'R','G','B',40,48,94,50,53,53,41,32};
code UCHAR CS_RGB0to255Str1[] = {11,'R','G','B',40,48,94,50,53,53,41,32};
*/

code UCHAR EN_RGB16to255Str1[] = {12,'R','G','B',40,49,54,94,50,51,53,41,32};
/*
code UCHAR FR_RGB16to255Str1[] = {12,'R','G','B',40,49,54,94,50,51,53,41,32};
code UCHAR GE_RGB16to255Str1[] = {12,'R','G','B',40,49,54,94,50,51,53,41,32};
code UCHAR IT_RGB16to255Str1[] = {12,'R','G','B',40,49,54,94,50,51,53,41,32};
code UCHAR SP_RGB16to255Str1[] = {12,'R','G','B',40,49,54,94,50,51,53,41,32};
code UCHAR PO_RGB16to255Str1[] = {12,'R','G','B',40,49,54,94,50,51,53,41,32};
code UCHAR CZ_RGB16to255Str1[] = {12,'R','G','B',40,49,54,94,50,51,53,41,32};
code UCHAR MA_RGB16to255Str1[] = {12,'R','G','B',40,49,54,94,50,51,53,41,32};
code UCHAR SE_RGB16to255Str1[] = {12,'R','G','B',40,49,54,94,50,51,53,41,32};
code UCHAR RO_RGB16to255Str1[] = {12,'R','G','B',40,49,54,94,50,51,53,41,32};
code UCHAR DU_RGB16to255Str1[] = {12,'R','G','B',40,49,54,94,50,51,53,41,32};
code UCHAR RU_RGB16to255Str1[] = {12,'R','G','B',40,49,54,94,50,51,53,41,32};
code UCHAR SW_RGB16to255Str1[] = {12,'R','G','B',40,49,54,94,50,51,53,41,32};
code UCHAR PR_RGB16to255Str1[] = {12,'R','G','B',40,49,54,94,50,51,53,41,32};
code UCHAR JA_RGB16to255Str1[] = {12,'R','G','B',40,49,54,94,50,51,53,41,32};
code UCHAR CT_RGB16to255Str1[] = {12,'R','G','B',40,49,54,94,50,51,53,41,32};
code UCHAR CS_RGB16to255Str1[] = {12,'R','G','B',40,49,54,94,50,51,53,41,32};
*/
code UCHAR *HDMIRGBPCRangeTab1[] = {
     EN_RGB0to255Str1,
     EN_RGB0to255Str1,//FR
     EN_RGB0to255Str1,//GE
     EN_RGB0to255Str1,//IT
     EN_RGB0to255Str1,//SP
     EN_RGB0to255Str1,//PO
     EN_RGB0to255Str1,//CZ
     EN_RGB0to255Str1,//MA
     EN_RGB0to255Str1,//SE
     EN_RGB0to255Str1,//RO
     EN_RGB0to255Str1,//DU
     EN_RGB0to255Str1,//RU
     EN_RGB0to255Str1,//SW
     EN_RGB0to255Str1,//PR
     EN_RGB0to255Str1,//JA
     EN_RGB0to255Str1,//CT
     EN_RGB0to255Str1,//CS
     
     EN_RGB16to255Str1,
     EN_RGB16to255Str1,//FR
     EN_RGB16to255Str1,//GE
     EN_RGB16to255Str1,//IT
     EN_RGB16to255Str1,//SP
     EN_RGB16to255Str1,//PO
     EN_RGB16to255Str1,//CZ
     EN_RGB16to255Str1,//MA
     EN_RGB16to255Str1,//SE
     EN_RGB16to255Str1,//RO
     EN_RGB16to255Str1,//DU
     EN_RGB16to255Str1,//RU
     EN_RGB16to255Str1,//SW
     EN_RGB16to255Str1,//PR
     EN_RGB16to255Str1,//JA
     EN_RGB16to255Str1,//CT
     EN_RGB16to255Str1,//CS

    
};
code UCHAR **SecondLevelTabOfMItem3[] = {PictureModeTab1, OnOffTab1, NULL, OnOffTab1,FullAspectTab1, ColorFormatTab1,HDMIRGBPCRangeTab1};

 code UCHAR EN_PCAudioStr1[]={8, 'P', 'C', ' ', 'A', 'u', 'd', 'i', 'o', };
 code UCHAR FR_PCAudioStr1[]={8, 'A', 'u', 'd', 'i', 'o', ' ', 'P', 'C', };
 code UCHAR GE_PCAudioStr1[]={8, 'P', 'C', '-', 'A', 'u', 'd', 'i', 'o', };
 code UCHAR IT_PCAudioStr1[]={8, 'A', 'u', 'd', 'i', 'o', ' ', 'P', 'C', };
 code UCHAR SP_PCAudioStr1[]={8, 'A', 'u', 'd', 'i', 'o', ' ', 'P', 'C', };
 code UCHAR PO_PCAudioStr1[]={8, 'K', 'o', 'm', 'p', '.', ' ', 'P', 'C', };
 code UCHAR CZ_PCAudioStr1[]={7, 'Z', 'v', 'u', 'k', ' ', 'P', 'C', };
 code UCHAR MA_PCAudioStr1[]={9, 'P', 'C', '-', 's', ' ', 'h', 'a', 'n', 'g', };
 code UCHAR SE_PCAudioStr1[]={8, 'P', 'C', ' ', 'a', 'u', 'd', 'i', 'o', };
 code UCHAR RO_PCAudioStr1[]={8, 'A', 'u', 'd', 'i', 'o', ' ', 'P', 'C', };
 code UCHAR DU_PCAudioStr1[]={8, 'P', 'c', '-', 'a', 'u', 'd', 'i', 'o', };
 code UCHAR RU_PCAudioStr1[]={9, 175, 131, 135, 148, ' ', 125, ' ', 167, 153, };
 code UCHAR SW_PCAudioStr1[]={7, 'P', 'C', '-', 'l', 'j', 'u', 'd', };
 code UCHAR PR_PCAudioStr1[]={8, 21, 'u', 'd', 'i', 'o', ' ', 'P', 'C', };
 code UCHAR JA_PCAudioStr1[]={5, 'P', 'C', ' ', 195, 202, };
 code UCHAR CT_PCAudioStr1[]={5, 'P', 'C', ' ', 190, 191, };
 code UCHAR CS_PCAudioStr1[]={5, 'P', 'C', ' ', 189, 18, };


 code UCHAR EN_AutoDetectStr1[]={11, 'A', 'u', 't', 'o', ' ', 'D', 'e', 't', 'e', 'c', 't', };
 code UCHAR FR_AutoDetectStr1[]={10, 'D', 2, 't', 'e', 'c', ' ', 'a', 'u', 't', 'o', };
 code UCHAR GE_AutoDetectStr1[]={9, 'A', 'u', 't', '.', ' ', 'E', 'r', 'k', '.', };
 code UCHAR IT_AutoDetectStr1[]={10, 'R', 'i', 'l', 'e', 'v', ' ', 'a', 'u', 't', 'o', };
 code UCHAR SP_AutoDetectStr1[]={10, 'D', 'e', 't', 'e', ' ', 'a', 'u', 't', 'o', 'm', };
 code UCHAR PO_AutoDetectStr1[]={4, 'A', 'u', 't', 'o', };
 code UCHAR CZ_AutoDetectStr1[]={10, 'A', 'u', 't', 'o', 'm', '.', 'd', 'e', 't', '.', };
 code UCHAR MA_AutoDetectStr1[]={10, 'A', 'u', 't', 'o', ' ', 'f', 'e', 'l', 'i', 's', };
 code UCHAR SE_AutoDetectStr1[]={10, 'A', 'u', 't', '.', 'd', 'e', 't', 'e', 'k', '.', };
 code UCHAR RO_AutoDetectStr1[]={9, 'D', 'e', 't', '.', ' ', 'A', 'u', 't', 'o', };
 code UCHAR DU_AutoDetectStr1[]={10, 'A', 'u', 't', 'o', 'd', 'e', 't', 'e', 'c', '.', };
 code UCHAR RU_AutoDetectStr1[]={10, 130, 131, 132, 136, 136, 126, 133, 128, 139, '.', };
 code UCHAR SW_AutoDetectStr1[]={15, 'A', 'u', 't', 'o', 'd', 'e', 't', 'e', 'k', 't', 'e', 'r', 'i', 'n', 'g', };
 code UCHAR PR_AutoDetectStr1[]={10, 'D', 'e', 't', 'e', 'c', ' ', 'a', 'u', 't', 'o', };
 code UCHAR JA_AutoDetectStr1[]={4, 2, 3, 203, 204, };
 code UCHAR CT_AutoDetectStr1[]={4, 2, 3, 197, 198, };
 code UCHAR CS_AutoDetectStr1 []={4, 2, 3, 196, 197, };

 code UCHAR EN_HDMIAudioStr1[]={10, 'H', 'D', 'M', 'I', ' ', 'A', 'u', 'd', 'i', 'o', };
 code UCHAR FR_HDMIAudioStr1[]={10, 'A', 'u', 'd', 'i', 'o', ' ', 'H', 'D', 'M', 'I', };
 code UCHAR GE_HDMIAudioStr1[]={10, 'H', 'D', 'M', 'I', ' ', 'A', 'u', 'd', 'i', 'o', };
 code UCHAR IT_HDMIAudioStr1[]={10, 'A', 'u', 'd', 'i', 'o', ' ', 'H', 'D', 'M', 'I', };
 code UCHAR SP_HDMIAudioStr1[]={10, 'A', 'u', 'd', 'i', 'o', ' ', 'H', 'D', 'M', 'I', };
 code UCHAR PO_HDMIAudioStr1[]={10, 'D', 130, 'w', 'i', '.', ' ', 'H', 'D', 'M', 'I', };
 code UCHAR CZ_HDMIAudioStr1[]={9, 'Z', 'v', 'u', 'k', ' ', 'H', 'D', 'M', 'I', };
 code UCHAR MA_HDMIAudioStr1[]={9, 'H', 'D', 'M', 'I', ' ', 'h', 'a', 'n', 'g', };
 code UCHAR SE_HDMIAudioStr1[]={10, 'H', 'D', 'M', 'I', ' ', 'A', 'u', 'd', 'i', 'o', };
 code UCHAR RO_HDMIAudioStr1[]={10, 'A', 'u', 'd', 'i', 'o', ' ', 'H', 'D', 'M', 'I', };
 code UCHAR DU_HDMIAudioStr1[]={10, 'H', 'd', 'm', 'i', ' ', 'a', 'u', 'd', 'i', 'o', };
 code UCHAR RU_HDMIAudioStr1[]={9, 175, 131, 135, 148, ' ', 'H', 'D', 'M', 'I', };
 code UCHAR SW_HDMIAudioStr1[]={9, 'H', 'D', 'M', 'I', '-', 'l', 'j', 'u', 'd', };
 code UCHAR PR_HDMIAudioStr1[]={10, 21, 'u', 'd', 'i', 'o', ' ', 'H', 'D', 'M', 'I', };
 code UCHAR JA_HDMIAudioStr1[]={11, 'H','D','M','I',32,149,21,161,170,149,32,};
 code UCHAR CT_HDMIAudioStr1[]={7, 'H', 'D', 'M', 'I', ' ', 190, 191, };
 code UCHAR CS_HDMIAudioStr1[]={7, 'H', 'D', 'M', 'I', ' ', 189, 18, };



code UCHAR *AudioSelectTab1[] = {
     EN_PCAudioStr1,
     FR_PCAudioStr1,
     GE_PCAudioStr1,
     IT_PCAudioStr1,
     SP_PCAudioStr1,
     PO_PCAudioStr1,
     CZ_PCAudioStr1,
     MA_PCAudioStr1,
     SE_PCAudioStr1,
     RO_PCAudioStr1,
     DU_PCAudioStr1,
     RU_PCAudioStr1,
     SW_PCAudioStr1,
     PR_PCAudioStr1,
     JA_PCAudioStr1,
     CT_PCAudioStr1,
     CS_PCAudioStr1,

    EN_HDMIAudioStr1,
    FR_HDMIAudioStr1,
    GE_HDMIAudioStr1,
    IT_HDMIAudioStr1,
    SP_HDMIAudioStr1,
    PO_HDMIAudioStr1,
    CZ_HDMIAudioStr1,
    MA_HDMIAudioStr1,
    SE_HDMIAudioStr1,
    RO_HDMIAudioStr1,
    DU_HDMIAudioStr1,
    RU_HDMIAudioStr1,
    SW_HDMIAudioStr1,
    PR_HDMIAudioStr1,
    JA_HDMIAudioStr1,     
    CT_HDMIAudioStr1,
    CS_HDMIAudioStr1,
    
     EN_AutoDetectStr1,
     FR_AutoDetectStr1,
     GE_AutoDetectStr1,
     IT_AutoDetectStr1,
     SP_AutoDetectStr1,
     PO_AutoDetectStr1,
     CZ_AutoDetectStr1,
     MA_AutoDetectStr1,
     SE_AutoDetectStr1,
     RO_AutoDetectStr1,
     DU_AutoDetectStr1,
     RU_AutoDetectStr1,
     SW_AutoDetectStr1,
     PR_AutoDetectStr1,
     JA_AutoDetectStr1,
     CT_AutoDetectStr1,
     CS_AutoDetectStr1,
    
};
code UCHAR **SecondLevelTabOfMItemAudio[] = {NULL, OnOffTab1, AudioSelectTab1};

code UCHAR EN_LanguageStr1[] = {8, 'L', 'a', 'n', 'g', 'u', 'a', 'g', 'e', };
code UCHAR FR_LanguageStr1[] = {6, 'L', 'a', 'n', 'g', 'u', 'e', };
code UCHAR GE_LanguageStr1[] = {8, 'S', 'p', 'r', 'a', 'c', 'h', 'e', ' ', };
code UCHAR IT_LanguageStr1[] = {6, 'L', 'i', 'n', 'g', 'u', 'a', };
code UCHAR SP_LanguageStr1[] = {6, 'I', 'd', 'i', 'o', 'm', 'a', };
code UCHAR PO_LanguageStr1[] = {5, 'J', 128, 'z', 'y', 'k', };
code UCHAR CZ_LanguageStr1[] = {5, 'J', 'a', 'z', 'y', 'k', };
code UCHAR MA_LanguageStr1[] = {5, 'N', 'y', 'e', 'l', 'v', };
code UCHAR SE_LanguageStr1[] = {5, 'J', 'e', 'z', 'i', 'k', };
code UCHAR RO_LanguageStr1[] = {5, 'L', 'i', 'm', 'b', 'a', };
code UCHAR DU_LanguageStr1[] = {4, 'T', 'a', 'a', 'l', };
code UCHAR RU_LanguageStr1[] = {4, 154, 141, 159, 148, };
code UCHAR SW_LanguageStr1[] = {5, 'S', 'p', 'r', 123, 'k', };
code UCHAR PR_LanguageStr1[] = {6, 'I', 'd', 'i', 'o', 'm', 'a', };
code UCHAR JA_LanguageStr1[] = {2, 212, 213, };
code UCHAR CT_LanguageStr1[] ={4, 204, 205, 147, 133, };
code UCHAR CS_LanguageStr1[] ={4, 203, 204, 145, 133, };
 
code UCHAR EN_DisplayTimeStr1[] = {12, 'D', 'i', 's', 'p', 'l', 'a', 'y', ' ', 'T', 'i', 'm', 'e', };
code UCHAR FR_DisplayTimeStr1[] = {17, 'T', 'e', 'm', 'p', 's', ' ', 'd', 39, 'a', 'f', 'f', 'i', 'c', 'h', 'a', 'g', 'e', };
code UCHAR GE_DisplayTimeStr1[] = {11, 'A', 'n', 'z', 'e', 'i', 'g', 'e', 'z', 'e', 'i', 't', };
code UCHAR IT_DisplayTimeStr1[] = {22, 'D', 'u', 'r', 'a', 't', 'a', ' ', 'v', 'i', 's', 'u', 'a', 'l', 'i', 'z', 'z', 'a', 'z', 'i', 'o', 'n', 'e', };
code UCHAR SP_DisplayTimeStr1[] = {19, 'T', 'i', 'e', 'm', 'p', ' ', 'v', 'i', 's', 'u', 'a', 'l', 'i', 'z', 'a', 'c', 'i', 4, 'n', };
code UCHAR PO_DisplayTimeStr1[] = {18, 'C', 'z', 'a', 's', ' ', 'w', 'y', 123, 'w', 'i', 'e', 't', 'l', 'a', 'n', 'i', 'a', 5, };
code UCHAR CZ_DisplayTimeStr1[] = {14, 'D', 'o', 'b', 'a', ' ', 'z', 'o', 'b', 'r', 'a', 'z', 'e', 'n', 1, };
code UCHAR MA_DisplayTimeStr1[] = {17, 'M', 'e', 'g', 'j', 'e', 'l', 'e', 'n', 1, 't', 2, 's', 'i', ' ', 'i', 'd', 123, };
code UCHAR SE_DisplayTimeStr1[] = {15, 'V', 'r', 'i', 'j', 'e', 'm', 'e', ' ', 'p', 'r', 'i', 'k', 'a', 'z', 'a', };
code UCHAR RO_DisplayTimeStr1[] = {11, 'A', 'f', 'i', 123, 'a', 'r', 'e', ' ', 'o', 'r', 125, };
code UCHAR DU_DisplayTimeStr1[] = {14, 'T', 'i', 'j', 'd', ' ', 'w', 'e', 'e', 'r', 'g', 'e', 'v', 'e', 'n', };
code UCHAR RU_DisplayTimeStr1[] = {14, 167, 136, 148, 143, 141, 143, 132, 155, ' ', 131, 133, 128, 146, 149, };
code UCHAR SW_DisplayTimeStr1[] = {11, 'V', 'i', 's', 'n', 'i', 'n', 'g', 's', 't', 'i', 'd', };
code UCHAR PR_DisplayTimeStr1[] = {15, 'T', 'e', 'm', 'p', 'o', ' ', 'v', 'i', 's', 'u', 'a', 'l', 'i', 'z', '.', };
code UCHAR JA_DisplayTimeStr1[] = {4, 0, 1, 214, 215, };
code UCHAR CT_DisplayTimeStr1[] = {4, 0, 1, 206, 207, };
code UCHAR CS_DisplayTimeStr1[] = {4, 0, 1, 205, 206, };
 
code UCHAR EN_OsdLockStr1[] =  {8, 'O', 'S', 'D', ' ', 'L', 'o', 'c', 'k', };
code UCHAR FR_OsdLockStr1[] =  {10, 'V', 'e', 'r', 'r', 'o', 'u', ' ', 'O', 'S', 'D', };
code UCHAR GE_OsdLockStr1[] =  {10, 'O', 'S', 'D', '-', 'S', 'p', 'e', 'r', 'r', 'e', };
code UCHAR IT_OsdLockStr1[] =  {10, 'B', 'l', 'o', 'c', 'c', 'o', ' ', 'O', 'S', 'D', };
code UCHAR SP_OsdLockStr1[] =  {11, 'B', 'l', 'o', 'q', 'u', 'e', 'o', ' ', 'O', 'S', 'D', };
code UCHAR PO_OsdLockStr1[] =  {11, 'B', 'l', 'o', 'k', 'a', 'd', 'a', ' ', 'O', 'S', 'D', };
code UCHAR CZ_OsdLockStr1[] =  {9, 'Z', 0, 'm', 'e', 'k', ' ', 'O', 'S', 'D', };
code UCHAR MA_OsdLockStr1[] =  {12, 'O', 'S', 'D', ' ', 'z', 0, 'r', 'o', 'l', 0, 's', 'a', };
code UCHAR SE_OsdLockStr1[] =  {11, 'O', 'S', 'D', ' ', 'z', 'a', 'k', 'l', 'j', '.', ' ', };
code UCHAR RO_OsdLockStr1[] =  {11, 'B', 'l', 'o', 'c', 'a', 'r', 'e', ' ', 'O', 'S', 'D', };
code UCHAR DU_OsdLockStr1[] =  {17, 'O', 'S', 'D', '-', 'v', 'e', 'r', 'g', 'r', 'e', 'n', 'd', 'e', 'l', 'i', 'n', 'g', };
code UCHAR RU_OsdLockStr1[] =  {17, 170, 127, 136, 148, 124, 133, '.', ' ', 176, 148, 133, '.', ' ', 146, 128, 144, 174, };
code UCHAR SW_OsdLockStr1[] =  {7, 'O', 'S', 'D', '-', 'l', 123, 's', };
code UCHAR PR_OsdLockStr1[] =  {12, 'B', 'l', 'o', 'q', 'u', 'e', 'i', 'o', ' ', 'O', 'S', 'D', };
code UCHAR JA_OsdLockStr1[] =  {7, 'O', 'S', 'D', ' ', 216, 148, 217, };
code UCHAR CT_OsdLockStr1[] = {5, 208, 133, 'O', 'S', 'D', };
code UCHAR CS_OsdLockStr1[] = {4, 'O', 'S', 'D', 207, };
 
code UCHAR *OSDSettingTab1[] = {
     EN_LanguageStr1,
     FR_LanguageStr1,
     GE_LanguageStr1,
     IT_LanguageStr1,
     SP_LanguageStr1,
     PO_LanguageStr1,
     CZ_LanguageStr1,
     MA_LanguageStr1,
     SE_LanguageStr1,
     RO_LanguageStr1,
     DU_LanguageStr1,
     RU_LanguageStr1,
     SW_LanguageStr1,
     PR_LanguageStr1,
     JA_LanguageStr1,
     CT_LanguageStr1,
     CS_LanguageStr1,
     
     EN_DisplayTimeStr1,
     FR_DisplayTimeStr1,
     GE_DisplayTimeStr1,
     IT_DisplayTimeStr1,
     SP_DisplayTimeStr1,
     PO_DisplayTimeStr1,
     CZ_DisplayTimeStr1,
     MA_DisplayTimeStr1,
     SE_DisplayTimeStr1,
     RO_DisplayTimeStr1,
     DU_DisplayTimeStr1,
     RU_DisplayTimeStr1,
     SW_DisplayTimeStr1,
     PR_DisplayTimeStr1,
     JA_DisplayTimeStr1,
     CT_DisplayTimeStr1,
     CS_DisplayTimeStr1,
     
     EN_OsdLockStr1,
     FR_OsdLockStr1,
     GE_OsdLockStr1,
     IT_OsdLockStr1,
     SP_OsdLockStr1,
     PO_OsdLockStr1,
     CZ_OsdLockStr1,
     MA_OsdLockStr1,
     SE_OsdLockStr1,
     RO_OsdLockStr1,
     DU_OsdLockStr1,
     RU_OsdLockStr1,
     SW_OsdLockStr1,
     PR_OsdLockStr1,
     JA_OsdLockStr1,
     CT_OsdLockStr1,
     CS_OsdLockStr1,
};

code UCHAR EN_min10Str1[] = {6, 49,48, 'm', 'i', 'n', '.', };
code UCHAR FR_min10Str1[] = {5, 49,48, 'm', 'i', 'n', };
code UCHAR GE_min10Str1[] = {6, 49,48, 'M', 'i', 'n', '.', };
code UCHAR IT_min10Str1[] = {6, 49,48, 'm', 'i', 'n', '.', };
code UCHAR SP_min10Str1[] = {6, 49,48, 'm', 'i', 'n', '.', };
code UCHAR PO_min10Str1[] = {6, 49,48, 'm', 'i', 'n', '.', };
code UCHAR CZ_min10Str1[] = {6, 49,48, 'm', 'i', 'n', '.', };
code UCHAR MA_min10Str1[] = {6, 49,48, 'p', 'e', 'r', 'c', };
code UCHAR SE_min10Str1[] = {6, 49,48, 'm', 'i', 'n', '.', };
code UCHAR RO_min10Str1[] = {6, 49,48, 'm', 'i', 'n', '.', };
code UCHAR DU_min10Str1[] = {6, 49,48, 'm', 'i', 'n', '.', };
code UCHAR RU_min10Str1[] = {6, 49,48, 146, 124, 144, '.', };
code UCHAR SW_min10Str1[] = {6, 49,48, 'm', 'i', 'n', '.', };
code UCHAR PR_min10Str1[] = {6, 49,48, 'm', 'i', 'n', '.', };
code UCHAR JA_min10Str1[] = {3, 49,48, 235, };
code UCHAR CT_min10Str1[] = {3, 49,48, 227, };
code UCHAR CS_min10Str1[] = {4, 49,48, 176, 226, };

code UCHAR EN_min20Str1[] = {6, 50,48, 'm', 'i', 'n', '.', };
code UCHAR FR_min20Str1[] = {5, 50,48, 'm', 'i', 'n', };
code UCHAR GE_min20Str1[] = {6, 50,48, 'M', 'i', 'n', '.', };
code UCHAR IT_min20Str1[] = {6, 50,48, 'm', 'i', 'n', '.', };
code UCHAR SP_min20Str1[] = {6, 50,48, 'm', 'i', 'n', '.', };
code UCHAR PO_min20Str1[] = {6, 50,48, 'm', 'i', 'n', '.', };
code UCHAR CZ_min20Str1[] = {6, 50,48, 'm', 'i', 'n', '.', };
code UCHAR MA_min20Str1[] = {6, 50,48, 'p', 'e', 'r', 'c', };
code UCHAR SE_min20Str1[] = {6, 50,48, 'm', 'i', 'n', '.', };
code UCHAR RO_min20Str1[] = {6, 50,48, 'm', 'i', 'n', '.', };
code UCHAR DU_min20Str1[] = {6, 50,48, 'm', 'i', 'n', '.', };
code UCHAR RU_min20Str1[] = {6, 50,48, 146, 124, 144, '.', };
code UCHAR SW_min20Str1[] = {6, 50,48, 'm', 'i', 'n', '.', };
code UCHAR PR_min20Str1[] = {6, 50,48, 'm', 'i', 'n', '.', };
code UCHAR JA_min20Str1[] = {3, 50,48, 235, };
code UCHAR CT_min20Str1[] = {3, 50,48, 227, };
code UCHAR CS_min20Str1[] = {4, 50,48, 176, 226, };

code UCHAR EN_min30Str1[] = {6, 51,48, 'm', 'i', 'n', '.', };
code UCHAR FR_min30Str1[] = {5, 51,48, 'm', 'i', 'n', };
code UCHAR GE_min30Str1[] = {6, 51,48, 'M', 'i', 'n', '.', };
code UCHAR IT_min30Str1[] = {6, 51,48, 'm', 'i', 'n', '.', };
code UCHAR SP_min30Str1[] = {6, 51,48, 'm', 'i', 'n', '.', };
code UCHAR PO_min30Str1[] = {6, 51,48, 'm', 'i', 'n', '.', };
code UCHAR CZ_min30Str1[] = {6, 51,48, 'm', 'i', 'n', '.', };
code UCHAR MA_min30Str1[] = {6, 51,48, 'p', 'e', 'r', 'c', };
code UCHAR SE_min30Str1[] = {6, 51,48, 'm', 'i', 'n', '.', };
code UCHAR RO_min30Str1[] = {6, 51,48, 'm', 'i', 'n', '.', };
code UCHAR DU_min30Str1[] = {6, 51,48, 'm', 'i', 'n', '.', };
code UCHAR RU_min30Str1[] = {6, 51,48, 146, 124, 144, '.', };
code UCHAR SW_min30Str1[] = {6, 51,48, 'm', 'i', 'n', '.', };
code UCHAR PR_min30Str1[] = {6, 51,48, 'm', 'i', 'n', '.', };
code UCHAR JA_min30Str1[] = {3, 51,48, 235, };
code UCHAR CT_min30Str1[] = {3, 51,48, 227, };
code UCHAR CS_min30Str1[] = {4, 51,48, 176, 226, };

// customer key1, 2 , 3 need to be check



// auto power off
code UCHAR *AutoPowerOffTab1[] = {
     EN_OffStr1,
     FR_OffStr1,
     GE_OffStr1,
     IT_OffStr1,
     SP_OffStr1,
     PO_OffStr1,
     CZ_OffStr1,
     MA_OffStr1,
     SE_OffStr1,
     RO_OffStr1,
     DU_OffStr1,
     RU_OffStr1,
     SW_OffStr1,
     PR_OffStr1,
     JA_OffStr1,
     CT_OffStr1,
     CS_OffStr1,
     
     EN_min10Str1,
     FR_min10Str1,
     GE_min10Str1,
     IT_min10Str1,
     SP_min10Str1,
     PO_min10Str1,
     CZ_min10Str1,
     MA_min10Str1,
     SE_min10Str1,
     RO_min10Str1,
     DU_min10Str1,
     RU_min10Str1,
     SW_min10Str1,
     PR_min10Str1,
     JA_min10Str1,
     CT_min10Str1,
     CS_min10Str1,
     
     EN_min20Str1,
     FR_min20Str1,
     GE_min20Str1,
     IT_min20Str1,
     SP_min20Str1,
     PO_min20Str1,
     CZ_min20Str1,
     MA_min20Str1,
     SE_min20Str1,
     RO_min20Str1,
     DU_min20Str1,
     RU_min20Str1,
     SW_min20Str1,
     PR_min20Str1,
     JA_min20Str1,
     CT_min20Str1,
     CS_min20Str1,
     
     EN_min30Str1,
     FR_min30Str1,
     GE_min30Str1,
     IT_min30Str1,
     SP_min30Str1,
     PO_min30Str1,
     CZ_min30Str1,
     MA_min30Str1,
     SE_min30Str1,
     RO_min30Str1,
     DU_min30Str1,
     RU_min30Str1,
     SW_min30Str1,
     PR_min30Str1,
     JA_min30Str1,
     CT_min30Str1,
     CS_min30Str1,
};


// info
code UCHAR EN_CurrentResStr1[] = {18, 'C', 'u', 'r', 'r', 'e', 'n', 't', ' ', 'R', 'e', 's', 'o', 'l', 'u', 't', 'i', 'o', 'n', };
code UCHAR FR_CurrentResStr1[] = {19, 'R', 2, 's', 'o', 'l', 'u', 't', 'i', 'o', 'n', ' ', 'a', 'c', 't', 'u', 'e', 'l', 'l', 'e', };
code UCHAR GE_CurrentResStr1[] = {18, 'A', 'k', 't', 'u', 'e', 'l', 'l', 'e', ' ', 'A', 'u', 'f', 'l', 10, 's', 'u', 'n', 'g', };
code UCHAR IT_CurrentResStr1[] = {20, 'R', 'i', 's', 'o', 'l', 'u', 'z', 'i', 'o', 'n', 'e', ' ', 'c', 'o', 'r', 'r', 'e', 'n', 't', 'e', };
code UCHAR SP_CurrentResStr1[] = {17, 'R', 'e', 's', 'o', 'l', 'u', 'c', 'i', 4, 'n', ' ', 'a', 'c', 't', 'u', 'a', 'l', };
code UCHAR PO_CurrentResStr1[] = {10, 'A', 'k', 't', '.', ' ', 'r', 'o', 'z', 'd', '.', };
code UCHAR CZ_CurrentResStr1[] = {18, 'A', 'k', 't', 'u', 0, 'l', 'n', 1, ' ', 'r', 'o', 'z', 'l', 'i', 20, 'e', 'n', 1, };
code UCHAR MA_CurrentResStr1[] = {19, 'J', 'e', 'l', 'e', 'n', 'l', 'e', 'g', 'i', ' ', 'f', 'e', 'l', 'b', 'o', 'n', 't', 0, 's', };
code UCHAR SE_CurrentResStr1[] = {20, 'T', 'r', 'e', 'n', 'u', 't', 'n', 'a', ' ', 'r', 'a', 'z', 'l', 'u', 6, 'i', 'v', 'o', 's', 't', };
code UCHAR RO_CurrentResStr1[] = {17, 'R', 'e', 'z', 'o', 'l', 'u', 124, 'i', 'e', ' ', 'a', 'c', 't', 'u', 'a', 'l', 125, };
code UCHAR DU_CurrentResStr1[] = {17, 'H', 'u', 'i', 'd', 'i', 'g', 'e', ' ', 'r', 'e', 's', 'o', 'l', 'u', 't', 'i', 'e', };
code UCHAR RU_CurrentResStr1[] = {12, 161, 128, 148, 135, 163, '.', ' ', 133, 143, 141, 133, '.', };
code UCHAR SW_CurrentResStr1[] = {18, 'A', 'k', 't', 'u', 'e', 'l', 'l', ' ', 'u', 'p', 'p', 'l', 10, 's', 'n', 'i', 'n', 'g', };
code UCHAR PR_CurrentResStr1[] = {16, 'R', 'e', 's', 'o', 'l', 'u', 7, 123, 'o', ' ', 'A', 'c', 't', 'u', 'a', 'l', };
code UCHAR JA_CurrentResStr1[] = {6, 226, 227, 145, 180, 26, 124, };
code UCHAR CT_CurrentResStr1[] = {6, 216, 217, 215, 177, 178, 28, };
code UCHAR CS_CurrentResStr1[] = {5, 216, 217, 176, 177, 19, };
 
code UCHAR EN_OptimumResStr1[] = {18, 'O', 'p', 't', 'i', 'm', 'u', 'm', ' ', 'R', 'e', 's', 'o', 'l', 'u', 't', 'i', 'o', 'n', };
code UCHAR FR_OptimumResStr1[] = {19, 'R', 2, 's', 'o', 'l', 'u', 't', 'i', 'o', 'n', ' ', 'o', 'p', 't', 'i', 'm', 'a', 'l', 'e', };
code UCHAR GE_OptimumResStr1[] = {18, 'O', 'p', 't', 'i', 'm', 'a', 'l', 'e', ' ', 'A', 'u', 'f', 'l', 10, 's', 'u', 'n', 'g', };
code UCHAR IT_OptimumResStr1[] = {20, 'R', 'i', 's', 'o', 'l', 'u', 'z', 'i', 'o', 'n', 'e', ' ', 'o', 't', 't', 'i', 'm', 'a', 'l', 'e', };
code UCHAR SP_OptimumResStr1[] = {17, 'R', 'e', 's', 'o', 'l', 'u', 'c', 'i', 4, 'n', ' ', 4, 'p', 't', 'i', 'm', 'a', };
code UCHAR PO_OptimumResStr1[] = {10, 'O', 'p', 't', '.', ' ', 'r', 'o', 'z', 'd', '.', };
code UCHAR CZ_OptimumResStr1[] = {19, 'O', 'p', 't', 'i', 'm', 0, 'l', 'n', 1, ' ', 'r', 'o', 'z', 'l', 'i', 20, 'e', 'n', 1, };
code UCHAR MA_OptimumResStr1[] = {19, 'O', 'p', 't', 'i', 'm', 0, 'l', 'i', 's', ' ', 'f', 'e', 'l', 'b', 'o', 'n', 't', 0, 's', };
code UCHAR SE_OptimumResStr1[] = {21, 'O', 'p', 't', 'i', 'm', 'a', 'l', 'n', 'a', ' ', 'r', 'a', 'z', 'l', 'u', 6, 'i', 'v', 'o', 's', 't', };
code UCHAR RO_OptimumResStr1[] = {16, 'R', 'e', 'z', 'o', 'l', 'u', 124, 'i', 'e', ' ', 'o', 'p', 't', 'i', 'm', 125, };
code UCHAR DU_OptimumResStr1[] = {18, 'O', 'p', 't', 'i', 'm', 'a', 'l', 'e', ' ', 'r', 'e', 's', 'o', 'l', 'u', 't', 'i', 'e', };
code UCHAR RU_OptimumResStr1[] = {10, 162, 126, 132, '.', ' ', 133, 143, 141, 133, '.', };
code UCHAR SW_OptimumResStr1[] = {18, 'O', 'p', 't', 'i', 'm', 'a', 'l', ' ', 'u', 'p', 'p', 'l', 10, 's', 'n', 'i', 'n', 'g', };
code UCHAR PR_OptimumResStr1[] = {15, 'R', 'e', 's', 'o', 'l', 'u', 7, 123, 'o', ' ', 'I', 'd', 'e', 'a', 'l', };
code UCHAR JA_OptimumResStr1[] = {5, 228, 229, 180, 26, 124, };
code UCHAR CT_OptimumResStr1[] = {5, 218, 219, 177, 178, 28, };
code UCHAR CS_OptimumResStr1[] = {5, 218, 219, 176, 177, 19, };
 
code UCHAR EN_ModelNameStr1[] = {10, 'M', 'o', 'd', 'e', 'l', ' ', 'N', 'a', 'm', 'e', };
code UCHAR FR_ModelNameStr1[] = {13, 'N', 'o', 'm', ' ', 'd', 'e', ' ', 'm', 'o', 'd', 29, 'l', 'e', };
code UCHAR GE_ModelNameStr1[] = {10, 'M', 'o', 'd', 'e', 'l', 'l', 'n', 'a', 'm', 'e', };
code UCHAR IT_ModelNameStr1[] = {12, 'N', 'o', 'm', 'e', ' ', 'm', 'o', 'd', 'e', 'l', 'l', 'o', };
code UCHAR SP_ModelNameStr1[] = {17, 'N', 'o', 'm', 'b', 'r', 'e', ' ', 'd', 'e', 'l', ' ', 'm', 'o', 'd', 'e', 'l', 'o', };
code UCHAR PO_ModelNameStr1[] = {12, 'N', 'a', 'z', 'w', 'a', ' ', 'm', 'o', 'd', 'e', 'l', 'u', };
code UCHAR CZ_ModelNameStr1[] = {12, 'N', 0, 'z', 'e', 'v', ' ', 'm', 'o', 'd', 'e', 'l', 'u', };
code UCHAR MA_ModelNameStr1[] = {10, 'T', 1, 'p', 'u', 's', ' ', 'n', 'e', 'v', 'e', };
code UCHAR SE_ModelNameStr1[] = {12, 'N', 'a', 'z', 'i', 'v', ' ', 'm', 'o', 'd', 'e', 'l', 'a', };
code UCHAR RO_ModelNameStr1[] = {10, 'N', 'u', 'm', 'e', ' ', 'm', 'o', 'd', 'e', 'l', };
code UCHAR DU_ModelNameStr1[] = {9, 'M', 'o', 'd', 'e', 'l', 'n', 'a', 'a', 'm', };
code UCHAR RU_ModelNameStr1[] = {15, 158, 143, 141, 131, 143, 144, 124, 128, ' ', 146, 136, 139, 128, 127, 124, };
code UCHAR SW_ModelNameStr1[] = {10, 'M', 'o', 'd', 'e', 'l', 'l', 'n', 'a', 'm', 'n', };
code UCHAR PR_ModelNameStr1[] = {14, 'N', 'o', 'm', 'e', ' ', 'd', 'o', ' ', 'M', 'o', 'd', 'e', 'l', 'o', };
code UCHAR JA_ModelNameStr1[] = {4, 159, 161, 164, 233, };
code UCHAR CT_ModelNameStr1[] = {4, 223, 9, 224, 225, };
code UCHAR CS_ModelNameStr1[] = {4, 222, 9, 223, 224, };
 
code UCHAR *InfoTab1[] = {
     EN_InputStr1,
     FR_InputStr1,
     GE_InputStr1,
     IT_InputStr1,
     SP_InputStr1,
     PO_InputStr1,
     CZ_InputStr1,
     MA_InputStr1,
     SE_InputStr1,
     RO_InputStr1,
     DU_InputStr1,
     RU_InputStr1,
     SW_InputStr1,
     PR_InputStr1,
     JA_InputStr1,
     CT_InputStr1,
     CS_InputStr1,
     
     EN_CurrentResStr1,
     FR_CurrentResStr1,
     GE_CurrentResStr1,
     IT_CurrentResStr1,
     SP_CurrentResStr1,
     PO_CurrentResStr1,
     CZ_CurrentResStr1,
     MA_CurrentResStr1,
     SE_CurrentResStr1,
     RO_CurrentResStr1,
     DU_CurrentResStr1,
     RU_CurrentResStr1,
     SW_CurrentResStr1,
     PR_CurrentResStr1,
     JA_CurrentResStr1,
     CT_CurrentResStr1,
     CS_CurrentResStr1,
     
     EN_OptimumResStr1,
     FR_OptimumResStr1,
     GE_OptimumResStr1,
     IT_OptimumResStr1,
     SP_OptimumResStr1,
     PO_OptimumResStr1,
     CZ_OptimumResStr1,
     MA_OptimumResStr1,
     SE_OptimumResStr1,
     RO_OptimumResStr1,
     DU_OptimumResStr1,
     RU_OptimumResStr1,
     SW_OptimumResStr1,
     PR_OptimumResStr1,
     JA_OptimumResStr1,
     CT_OptimumResStr1,
     CS_OptimumResStr1,
     
     EN_ModelNameStr1,
     FR_ModelNameStr1,
     GE_ModelNameStr1,
     IT_ModelNameStr1,
     SP_ModelNameStr1,
     PO_ModelNameStr1,
     CZ_ModelNameStr1,
     MA_ModelNameStr1,
     SE_ModelNameStr1,
     RO_ModelNameStr1,
     DU_ModelNameStr1,
     RU_ModelNameStr1,
     SW_ModelNameStr1,
     PR_ModelNameStr1,
     JA_ModelNameStr1,
     CT_ModelNameStr1,
     CS_ModelNameStr1,
};

//Hot key string
code UCHAR *CustKeyTabStr1[] = {
     //ULEric140331
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     EN_LowBlueLightStr1,
     JA_LowBlueLightStr1,
     CT_LowBlueLightStr1,
     CS_LowBlueLightStr1,
     
     EN_PictureModeStr1,
     FR_PictureModeStr1,
     GE_PictureModeStr1,
     IT_PictureModeStr1,
     SP_PictureModeStr1,
     PO_PictureModeStr1,
     CZ_PictureModeStr1,
     MA_PictureModeStr1,
     SE_PictureModeStr1,
     RO_PictureModeStr1,
     DU_PictureModeStr1,
     RU_PictureModeStr1,
     SW_PictureModeStr1,
     PR_PictureModeStr1,
     JA_PictureModeStr1,
     CT_PictureModeStr1,
     CS_PictureModeStr1,
     
     EN_DisplayModeStr1,
     FR_DisplayModeStr1,
     GE_DisplayModeStr1,
     IT_DisplayModeStr1,
     SP_DisplayModeStr1,
     PO_DisplayModeStr1,
     CZ_DisplayModeStr1,
     MA_DisplayModeStr1,
     SE_DisplayModeStr1,
     RO_DisplayModeStr1,
     DU_DisplayModeStr1,
     RU_DisplayModeStr1,
     SW_DisplayModeStr1,
     PR_DisplayModeStr1,
     JA_DisplayModeStr1,
     CT_DisplayModeStr1,
     CS_DisplayModeStr1,
     
     EN_BrightnessStr1,
     FR_BrightnessStr1,
     GE_BrightnessStr1,
     IT_BrightnessStr1,
     SP_BrightnessStr1,
     PO_BrightnessStr1,
     CZ_BrightnessStr1,
     MA_BrightnessStr1,
     SE_BrightnessStr1,
     RO_BrightnessStr1,
     DU_BrightnessStr1,
     RU_BrightnessStr1,
     SW_BrightnessStr1,
     PR_BrightnessStr1,
     JA_BrightnessStr1,
     CT_BrightnessStr1,
     CS_BrightnessStr1,

     EN_ContrastStr1,
     FR_ContrastStr1,
     GE_ContrastStr1,
     IT_ContrastStr1,
     SP_ContrastStr1,
     PO_ContrastStr1,
     CZ_ContrastStr1,
     MA_ContrastStr1,
     SE_ContrastStr1,
     RO_ContrastStr1,
     DU_ContrastStr1,
     RU_ContrastStr1,
     SW_ContrastStr1,
     PR_ContrastStr1,
     JA_ContrastStr1,
     CT_ContrastStr1,
     CS_ContrastStr1,
     
     EN_AutoAdjustmentStr1,
     FR_AutoAdjustmentStr1,
     GE_AutoAdjustmentStr1,
     IT_AutoAdjustmentStr1,
     SP_AutoAdjustmentStr1,
     PO_AutoAdjustmentStr1,
     CZ_AutoAdjustmentStr1,
     MA_AutoAdjustmentStr1,
     SE_AutoAdjustmentStr1,
     RO_AutoAdjustmentStr1,
     DU_AutoAdjustmentStr1,
     RU_AutoAdjustmentStr1,
     SW_AutoAdjustmentStr1,
     PR_AutoAdjustmentStr1,
     JA_AutoAdjustmentStr1,
     CT_AutoAdjustmentStr1,
     CS_AutoAdjustmentStr1,
     
     EN_VolumeStr1,
     FR_VolumeStr1,
     GE_VolumeStr1,
     IT_VolumeStr1,
     SP_VolumeStr1,
     PO_VolumeStr1,
     CZ_VolumeStr1,
     MA_VolumeStr1,
     SE_VolumeStr1,
     RO_VolumeStr1,
     DU_VolumeStr1,
     RU_VolumeStr1,
     SW_VolumeStr1,
     PR_VolumeStr1,
     JA_VolumeStr1,
     CT_VolumeStr1,
     CS_VolumeStr1,

     EN_MuteStr1,
     FR_MuteStr1,
     GE_MuteStr1,
     IT_MuteStr1,
     SP_MuteStr1,
     PO_MuteStr1,
     CZ_MuteStr1,
     MA_MuteStr1,
     SE_MuteStr1,
     RO_MuteStr1,
     DU_MuteStr1,
     RU_MuteStr1,
     SW_MuteStr1,
     PR_MuteStr1,
     JA_MuteStr1,
     CT_MuteStr1,
     CS_MuteStr1,

     EN_InputStr1,
     FR_InputStr1,
     GE_InputStr1,
     IT_InputStr1,
     SP_InputStr1,
     PO_InputStr1,
     CZ_InputStr1,
     MA_InputStr1,
     SE_InputStr1,
     RO_InputStr1,
     DU_InputStr1,
     RU_InputStr1,
     SW_InputStr1,
     PR_InputStr1,
     JA_InputStr1,
     CT_InputStr1,
     CS_InputStr1,

     EN_SmartReminderStr1,
     FR_SmartReminderStr1,
     GE_SmartReminderStr1,
     IT_SmartReminderStr1,
     SP_SmartReminderStr1,
     PO_SmartReminderStr1,
     CZ_SmartReminderStr1,
     MA_SmartReminderStr1,
     SE_SmartReminderStr1,
     RO_SmartReminderStr1,
     DU_SmartReminderStr1,
     RU_SmartReminderStr1,
     SW_SmartReminderStr1,
     PR_SmartReminderStr1,
     JA_SmartReminderStr1,
     CT_SmartReminderStr1,
     CS_SmartReminderStr1,
     
};





code UCHAR **SecondLevelTabOfMItem4[] = {OSDSettingTab1, CustKeyTabStr1, CustKeyTabStr1, CustKeyTabStr1, OnOffTab1,OnOffTab1,OnOffTab1, AutoPowerOffTab1
, OnOffTab1, InfoTab1, DPmodeStrTab,YesNoTab1};

code UCHAR EN_20Str1[] = {2, 50, 48, };

code UCHAR EN_40Str1[] = {2, 52, 48, };

code UCHAR EN_60Str1[] = {2, 54, 48, };

code UCHAR EN_80Str1[] = {2, 56, 48, };

code UCHAR EN_100Str1[] = {3, 49, 48, 48};
code UCHAR *TimeIntervalTab1[] = {
     EN_20Str1,
     EN_20Str1,
     EN_20Str1,
     EN_20Str1,
     EN_20Str1,
     EN_20Str1,
     EN_20Str1,
     EN_20Str1,
     EN_20Str1,
     EN_20Str1,
     EN_20Str1,
     EN_20Str1,
     EN_20Str1,
     EN_20Str1,
     EN_20Str1,
     EN_20Str1,
     EN_20Str1,
     
     EN_40Str1,
     EN_40Str1,
     EN_40Str1,
     EN_40Str1,
     EN_40Str1,
     EN_40Str1,
     EN_40Str1,
     EN_40Str1,
     EN_40Str1,
     EN_40Str1,
     EN_40Str1,
     EN_40Str1,
     EN_40Str1,
     EN_40Str1,
     EN_40Str1,
     EN_40Str1,
     EN_40Str1,

     EN_60Str1,
     EN_60Str1,
     EN_60Str1,
     EN_60Str1,
     EN_60Str1,
     EN_60Str1,
     EN_60Str1,
     EN_60Str1,
     EN_60Str1,
     EN_60Str1,
     EN_60Str1,
     EN_60Str1,
     EN_60Str1,
     EN_60Str1,
     EN_60Str1,
     EN_60Str1,
     EN_60Str1,

     EN_80Str1,
     EN_80Str1,
     EN_80Str1,
     EN_80Str1,
     EN_80Str1,
     EN_80Str1,
     EN_80Str1,
     EN_80Str1,
     EN_80Str1,
     EN_80Str1,
     EN_80Str1,
     EN_80Str1,
     EN_80Str1,
     EN_80Str1,
     EN_80Str1,
     EN_80Str1,
     EN_80Str1,

     EN_100Str1,
     EN_100Str1,
     EN_100Str1,
     EN_100Str1,
     EN_100Str1,
     EN_100Str1,
     EN_100Str1,
     EN_100Str1,
     EN_100Str1,
     EN_100Str1,
     EN_100Str1,
     EN_100Str1,
     EN_100Str1,
     EN_100Str1,
     EN_100Str1,
     EN_100Str1,
     EN_100Str1,
     
};

code UCHAR EN_5Str1[] = {1, 53, };

code UCHAR EN_10Str1[] = {2, 49, 48};

code UCHAR EN_15Str1[] = {2, 49, 53};

code UCHAR EN_25Str1[] = {2, 50, 53};
code UCHAR *DurationTab1[] = {
     EN_5Str1,
     EN_5Str1,
     EN_5Str1,
     EN_5Str1,
     EN_5Str1,
     EN_5Str1,
     EN_5Str1,
     EN_5Str1,
     EN_5Str1,
     EN_5Str1,
     EN_5Str1,
     EN_5Str1,
     EN_5Str1,
     EN_5Str1,
     EN_5Str1,
     EN_5Str1,
     EN_5Str1,


     EN_10Str1,
     EN_10Str1,
     EN_10Str1,
     EN_10Str1,
     EN_10Str1,
     EN_10Str1,
     EN_10Str1,
     EN_10Str1,
     EN_10Str1,
     EN_10Str1,
     EN_10Str1,
     EN_10Str1,
     EN_10Str1,
     EN_10Str1,
     EN_10Str1,
     EN_10Str1,
     EN_10Str1,


     EN_15Str1,
     EN_15Str1,
     EN_15Str1,
     EN_15Str1,
     EN_15Str1,
     EN_15Str1,
     EN_15Str1,
     EN_15Str1,
     EN_15Str1,
     EN_15Str1,
     EN_15Str1,
     EN_15Str1,
     EN_15Str1,
     EN_15Str1,
     EN_15Str1,
     EN_15Str1,
     EN_15Str1,

     EN_20Str1,
     EN_20Str1,
     EN_20Str1,
     EN_20Str1,
     EN_20Str1,
     EN_20Str1,
     EN_20Str1,
     EN_20Str1,
     EN_20Str1,
     EN_20Str1,
     EN_20Str1,
     EN_20Str1,
     EN_20Str1,
     EN_20Str1,
     EN_20Str1,
     EN_20Str1,
     EN_20Str1,

     EN_25Str1,
     EN_25Str1,
     EN_25Str1,
     EN_25Str1,
     EN_25Str1,
     EN_25Str1,
     EN_25Str1,
     EN_25Str1,
     EN_25Str1,
     EN_25Str1,
     EN_25Str1,
     EN_25Str1,
     EN_25Str1,
     EN_25Str1,
     EN_25Str1,
     EN_25Str1,
     EN_25Str1,
};




code UCHAR **SecondLevelTabOfMItemErgo[] = {OnOffTab1,TimeIntervalTab1,DurationTab1};

code UCHAR ***TestTable2[] = {SecondLevelTabOfMItem1, SecondLevelTabOfMItem2, SecondLevelTabOfMItem3, SecondLevelTabOfMItemAudio,
SecondLevelTabOfMItem4,SecondLevelTabOfMItemErgo};




code UCHAR EN_sec05Str1[] = {5,53, 's', 'e', 'c', '.', };
code UCHAR FR_sec05Str1[] = {5,53, 's', 'e', 'c', '.', };
code UCHAR GE_sec05Str1[] = {5,53, 'S', 'e', 'k', '.', };
code UCHAR IT_sec05Str1[] = {5,53, 's', 'e', 'c', '.', };
code UCHAR SP_sec05Str1[] = {5,53, 's', 'e', 'g', '.', };
code UCHAR PO_sec05Str1[] = {5,53, 's', 'e', 'k', '.', };
code UCHAR CZ_sec05Str1[] = {2,53, 's', };
code UCHAR MA_sec05Str1[] = {4,53, 'm', 'p', '.', };
code UCHAR SE_sec05Str1[] = {2,53, 's', };
code UCHAR RO_sec05Str1[] = {5,53, 's', 'e', 'c', '.', };
code UCHAR DU_sec05Str1[] = {5,53, 's', 'e', 'c', '.', };
code UCHAR RU_sec05Str1[] = {5,53, 125, 128, 148, '.', };
code UCHAR SW_sec05Str1[] = {5,53, 's', 'e', 'k', '.', };
code UCHAR PR_sec05Str1[] = {5,53, 's', 'e', 'g', '.', };
code UCHAR JA_sec05Str1[] = {2,53, 234,};
code UCHAR CT_sec05Str1[] = {2,53, 226,};
code UCHAR CS_sec05Str1[] = {2,53, 225,};
 
code UCHAR EN_sec10Str1[] = {6,49,48,'s', 'e', 'c', '.', };
code UCHAR FR_sec10Str1[] = {6,49,48, 's', 'e', 'c', '.', };
code UCHAR GE_sec10Str1[] = {6,49,48, 'S', 'e', 'k', '.', };
code UCHAR IT_sec10Str1[] = {6,49,48, 's', 'e', 'c', '.', };
code UCHAR SP_sec10Str1[] = {6,49,48, 's', 'e', 'g', '.', };
code UCHAR PO_sec10Str1[] = {6,49,48, 's', 'e', 'k', '.', };
code UCHAR CZ_sec10Str1[] = {3,49,48, 's', };
code UCHAR MA_sec10Str1[] = {5,49,48, 'm', 'p', '.', };
code UCHAR SE_sec10Str1[] = {3,49,48, 's', };
code UCHAR RO_sec10Str1[] = {6,49,48, 's', 'e', 'c', '.', };
code UCHAR DU_sec10Str1[] = {6,49,48, 's', 'e', 'c', '.', };
code UCHAR RU_sec10Str1[] = {6,49,48, 125, 128, 148, '.', };
code UCHAR SW_sec10Str1[] = {6,49,48, 's', 'e', 'k', '.', };
code UCHAR PR_sec10Str1[] = {6,49,48, 's', 'e', 'g', '.', };
code UCHAR JA_sec10Str1[] = {3,49,48, 234, };
code UCHAR CT_sec10Str1[] = {3,49,48, 226, };
code UCHAR CS_sec10Str1[] = {3,49,48, 225, };

code UCHAR EN_sec15Str1[] = {6,49,53,'s', 'e', 'c', '.', };
code UCHAR FR_sec15Str1[] = {6,49,53, 's', 'e', 'c', '.', };
code UCHAR GE_sec15Str1[] = {6,49,53, 'S', 'e', 'k', '.', };
code UCHAR IT_sec15Str1[] = {6,49,53, 's', 'e', 'c', '.', };
code UCHAR SP_sec15Str1[] = {6,49,53, 's', 'e', 'g', '.', };
code UCHAR PO_sec15Str1[] = {6,49,53, 's', 'e', 'k', '.', };
code UCHAR CZ_sec15Str1[] = {3,49,53, 's', };
code UCHAR MA_sec15Str1[] = {5,49,53, 'm', 'p', '.', };
code UCHAR SE_sec15Str1[] = {3,49,53, 's', };
code UCHAR RO_sec15Str1[] = {6,49,53, 's', 'e', 'c', '.', };
code UCHAR DU_sec15Str1[] = {6,49,53, 's', 'e', 'c', '.', };
code UCHAR RU_sec15Str1[] = {6,49,53, 125, 128, 148, '.', };
code UCHAR SW_sec15Str1[] = {6,49,53, 's', 'e', 'k', '.', };
code UCHAR PR_sec15Str1[] = {6,49,53, 's', 'e', 'g', '.', };
code UCHAR JA_sec15Str1[] = {3,49,53, 234, };
code UCHAR CT_sec15Str1[] = {3,49,53, 226, };
code UCHAR CS_sec15Str1[] = {3,49,53, 225, };

code UCHAR EN_sec20Str1[] = {6,50,48,'s', 'e', 'c', '.', };
code UCHAR FR_sec20Str1[] = {6,50,48, 's', 'e', 'c', '.', };
code UCHAR GE_sec20Str1[] = {6,50,48, 'S', 'e', 'k', '.', };
code UCHAR IT_sec20Str1[] = {6,50,48, 's', 'e', 'c', '.', };
code UCHAR SP_sec20Str1[] = {6,50,48, 's', 'e', 'g', '.', };
code UCHAR PO_sec20Str1[] = {6,50,48, 's', 'e', 'k', '.', };
code UCHAR CZ_sec20Str1[] = {3,50,48, 's', };
code UCHAR MA_sec20Str1[] = {5,50,48, 'm', 'p', '.', };
code UCHAR SE_sec20Str1[] = {3,50,48, 's', };
code UCHAR RO_sec20Str1[] = {6,50,48, 's', 'e', 'c', '.', };
code UCHAR DU_sec20Str1[] = {6,50,48, 's', 'e', 'c', '.', };
code UCHAR RU_sec20Str1[] = {6,50,48, 125, 128, 148, '.', };
code UCHAR SW_sec20Str1[] = {6,50,48, 's', 'e', 'k', '.', };
code UCHAR PR_sec20Str1[] = {6,50,48, 's', 'e', 'g', '.', };
code UCHAR JA_sec20Str1[] = {3,50,48, 234,};
code UCHAR CT_sec20Str1[] = {3,50,48, 226,};
code UCHAR CS_sec20Str1[] = {3,50,48, 225,};

code UCHAR EN_sec25Str1[] = {6,50,53,'s', 'e', 'c', '.', };
code UCHAR FR_sec25Str1[] = {6,50,53, 's', 'e', 'c', '.', };
code UCHAR GE_sec25Str1[] = {6,50,53, 'S', 'e', 'k', '.', };
code UCHAR IT_sec25Str1[] = {6,50,53, 's', 'e', 'c', '.', };
code UCHAR SP_sec25Str1[] = {6,50,53, 's', 'e', 'g', '.', };
code UCHAR PO_sec25Str1[] = {6,50,53, 's', 'e', 'k', '.', };
code UCHAR CZ_sec25Str1[] = {3,50,53, 's', };
code UCHAR MA_sec25Str1[] = {5,50,53, 'm', 'p', '.', };
code UCHAR SE_sec25Str1[] = {3,50,53, 's', };
code UCHAR RO_sec25Str1[] = {6,50,53, 's', 'e', 'c', '.', };
code UCHAR DU_sec25Str1[] = {6,50,53, 's', 'e', 'c', '.', };
code UCHAR RU_sec25Str1[] = {6,50,53, 125, 128, 148, '.', };
code UCHAR SW_sec25Str1[] = {6,50,53, 's', 'e', 'k', '.', };
code UCHAR PR_sec25Str1[] = {6,50,53, 's', 'e', 'g', '.', };
code UCHAR JA_sec25Str1[] = {3,50,53, 234,};
code UCHAR CT_sec25Str1[] = {3,50,53,226,};
code UCHAR CS_sec25Str1[] = {3,50,53,225,};

code UCHAR EN_sec30Str1[] = {6,51,48,'s', 'e', 'c', '.', };
code UCHAR FR_sec30Str1[] = {6,51,48, 's', 'e', 'c', '.', };
code UCHAR GE_sec30Str1[] = {6,51,48, 'S', 'e', 'k', '.', };
code UCHAR IT_sec30Str1[] = {6,51,48, 's', 'e', 'c', '.', };
code UCHAR SP_sec30Str1[] = {6,51,48, 's', 'e', 'g', '.', };
code UCHAR PO_sec30Str1[] = {6,51,48, 's', 'e', 'k', '.', };
code UCHAR CZ_sec30Str1[] = {3,51,48, 's', };
code UCHAR MA_sec30Str1[] = {5,51,48, 'm', 'p', '.', };
code UCHAR SE_sec30Str1[] = {3,51,48, 's', };
code UCHAR RO_sec30Str1[] = {6,51,48, 's', 'e', 'c', '.', };
code UCHAR DU_sec30Str1[] = {6,51,48, 's', 'e', 'c', '.', };
code UCHAR RU_sec30Str1[] = {6,51,48, 125, 128, 148, '.', };
code UCHAR SW_sec30Str1[] = {6,51,48, 's', 'e', 'k', '.', };
code UCHAR PR_sec30Str1[] = {6,51,48, 's', 'e', 'g', '.', };
code UCHAR JA_sec30Str1[] = {3,51,48,234,};
code UCHAR CT_sec30Str1[] = {3,51,48,226,};
code UCHAR CS_sec30Str1[] = {3,51,48,225,};

code UCHAR *DisplayTimeTab[] = {
     EN_sec05Str1,
     FR_sec05Str1,
     GE_sec05Str1,
     IT_sec05Str1,
     SP_sec05Str1,
     PO_sec05Str1,
     CZ_sec05Str1,
     MA_sec05Str1,
     SE_sec05Str1,
     RO_sec05Str1,
     DU_sec05Str1,
     RU_sec05Str1,
     SW_sec05Str1,
     PR_sec05Str1,
     JA_sec05Str1,
     CT_sec05Str1,
     CS_sec05Str1,
     
     EN_sec10Str1,
     FR_sec10Str1,
     GE_sec10Str1,
     IT_sec10Str1,
     SP_sec10Str1,
     PO_sec10Str1,
     CZ_sec10Str1,
     MA_sec10Str1,
     SE_sec10Str1,
     RO_sec10Str1,
     DU_sec10Str1,
     RU_sec10Str1,
     SW_sec10Str1,
     PR_sec10Str1,
     JA_sec10Str1,
     CT_sec10Str1,
     CS_sec10Str1,
     
     EN_sec15Str1,
     FR_sec15Str1,
     GE_sec15Str1,
     IT_sec15Str1,
     SP_sec15Str1,
     PO_sec15Str1,
     CZ_sec15Str1,
     MA_sec15Str1,
     SE_sec15Str1,
     RO_sec15Str1,
     DU_sec15Str1,
     RU_sec15Str1,
     SW_sec15Str1,
     PR_sec15Str1,
     JA_sec15Str1,
     CT_sec15Str1,
     CS_sec15Str1,
     
     EN_sec20Str1,
     FR_sec20Str1,
     GE_sec20Str1,
     IT_sec20Str1,
     SP_sec20Str1,
     PO_sec20Str1,
     CZ_sec20Str1,
     MA_sec20Str1,
     SE_sec20Str1,
     RO_sec20Str1,
     DU_sec20Str1,
     RU_sec20Str1,
     SW_sec20Str1,
     PR_sec20Str1,
     JA_sec20Str1,
     CT_sec20Str1,
     CS_sec20Str1,
     
     EN_sec25Str1,
     FR_sec25Str1,
     GE_sec25Str1,
     IT_sec25Str1,
     SP_sec25Str1,
     PO_sec25Str1,
     CZ_sec25Str1,
     MA_sec25Str1,
     SE_sec25Str1,
     RO_sec25Str1,
     DU_sec25Str1,
     RU_sec25Str1,
     SW_sec25Str1,
     PR_sec25Str1,
     JA_sec25Str1,
     CT_sec25Str1,
     CS_sec25Str1,
     
     EN_sec30Str1,
     FR_sec30Str1,
     GE_sec30Str1,
     IT_sec30Str1,
     SP_sec30Str1,
     PO_sec30Str1,
     CZ_sec30Str1,
     MA_sec30Str1,
     SE_sec30Str1,
     RO_sec30Str1,
     DU_sec30Str1,
     RU_sec30Str1,
     SW_sec30Str1,
     PR_sec30Str1,
     JA_sec30Str1,
     CT_sec30Str1,
     CS_sec30Str1,
};

code UCHAR EN_EnglishStr1[] = {7,"English"};
/*
code UCHAR FR_EnglishStr1[] = {7,"English"};
code UCHAR GE_EnglishStr1[] = {7,"English"};
code UCHAR IT_EnglishStr1[] = {7,"English"};
code UCHAR SP_EnglishStr1[] = {7,"English"};
code UCHAR PO_EnglishStr1[] = {7,"English"};
code UCHAR CZ_EnglishStr1[] = {7,"English"};
code UCHAR MA_EnglishStr1[] = {7,"English"};
code UCHAR SE_EnglishStr1[] = {7,"English"};
code UCHAR RO_EnglishStr1[] = {7,"English"};
code UCHAR DU_EnglishStr1[] = {7,"English"};
code UCHAR RU_EnglishStr1[] = {7,"English"};
code UCHAR SW_EnglishStr1[] = {7,"English"};
code UCHAR PR_EnglishStr1[] = {7,"English"};
code UCHAR JA_EnglishStr1[] = {7,"English"};
code UCHAR CT_EnglishStr1[] = {7,"English"};
code UCHAR CS_EnglishStr1[] = {7,"English"};
*/

code UCHAR EN_FrancaisStr1[] = {9, 'F', 'r', 'a', 'n', 7, 'a', 'i', 's', ' ', };
/*
code UCHAR FR_FrancaisStr1[] = {9, 'F', 'r', 'a', 'n', 7, 'a', 'i', 's', ' ', };
code UCHAR GE_FrancaisStr1[] = {9, 'F', 'r', 'a', 'n', 7, 'a', 'i', 's', ' ', };
code UCHAR IT_FrancaisStr1[] = {9, 'F', 'r', 'a', 'n', 7, 'a', 'i', 's', ' ', };
code UCHAR SP_FrancaisStr1[] = {9, 'F', 'r', 'a', 'n', 7, 'a', 'i', 's', ' ', };
code UCHAR PO_FrancaisStr1[] = {9, 'F', 'r', 'a', 'n', 7, 'a', 'i', 's', ' ', };
code UCHAR CZ_FrancaisStr1[] = {9, 'F', 'r', 'a', 'n', 7, 'a', 'i', 's', ' ', };
code UCHAR MA_FrancaisStr1[] = {9, 'F', 'r', 'a', 'n', 7, 'a', 'i', 's', ' ', };
code UCHAR SE_FrancaisStr1[] = {9, 'F', 'r', 'a', 'n', 7, 'a', 'i', 's', ' ', };
code UCHAR RO_FrancaisStr1[] = {9, 'F', 'r', 'a', 'n', 7, 'a', 'i', 's', ' ', };
code UCHAR DU_FrancaisStr1[] = {9, 'F', 'r', 'a', 'n', 7, 'a', 'i', 's', ' ', };
code UCHAR RU_FrancaisStr1[] = {9, 'F', 'r', 'a', 'n', 7, 'a', 'i', 's', ' ', };
code UCHAR SW_FrancaisStr1[] = {9, 'F', 'r', 'a', 'n', 7, 'a', 'i', 's', ' ', };
code UCHAR PR_FrancaisStr1[] = {9, 'F', 'r', 'a', 'n', 7, 'a', 'i', 's', ' ', };
*/
code UCHAR JA_FrancaisStr1[] = {9, 'F', 'r', 'a', 'n', 200, 'a', 'i', 's', ' ', };
code UCHAR CT_FrancaisStr1[] = {9, 'F', 'r', 'a', 'n', 198, 'a', 'i', 's', ' ', };
code UCHAR CS_FrancaisStr1[] = {9, 'F', 'r', 'a', 'n', 194, 'a', 'i', 's', ' ', };

code UCHAR EN_DeutschStr1[] = {7,"Deutsch"};
/*
code UCHAR FR_DeutschStr1[] = {7,"Deutsch"};
code UCHAR GE_DeutschStr1[] = {7,"Deutsch"};
code UCHAR IT_DeutschStr1[] = {7,"Deutsch"};
code UCHAR SP_DeutschStr1[] = {7,"Deutsch"};
code UCHAR PO_DeutschStr1[] = {7,"Deutsch"};
code UCHAR CZ_DeutschStr1[] = {7,"Deutsch"};
code UCHAR MA_DeutschStr1[] = {7,"Deutsch"};
code UCHAR SE_DeutschStr1[] = {7,"Deutsch"};
code UCHAR RO_DeutschStr1[] = {7,"Deutsch"};
code UCHAR DU_DeutschStr1[] = {7,"Deutsch"};
code UCHAR RU_DeutschStr1[] = {7,"Deutsch"};
code UCHAR SW_DeutschStr1[] = {7,"Deutsch"};
code UCHAR PR_DeutschStr1[] = {7,"Deutsch"};
code UCHAR JA_DeutschStr1[] = {7,"Deutsch"};
code UCHAR CT_DeutschStr1[] = {7,"Deutsch"};
code UCHAR CS_DeutschStr1[] = {7,"Deutsch"};
*/

code UCHAR EN_ItalianoStr1[] = {8,"Italiano"};
/*
code UCHAR FR_ItalianoStr1[] = {8,"Italiano"};
code UCHAR GE_ItalianoStr1[] = {8,"Italiano"};
code UCHAR IT_ItalianoStr1[] = {8,"Italiano"};
code UCHAR SP_ItalianoStr1[] = {8,"Italiano"};
code UCHAR PO_ItalianoStr1[] = {8,"Italiano"};
code UCHAR CZ_ItalianoStr1[] = {8,"Italiano"};
code UCHAR MA_ItalianoStr1[] = {8,"Italiano"};
code UCHAR SE_ItalianoStr1[] = {8,"Italiano"};
code UCHAR RO_ItalianoStr1[] = {8,"Italiano"};
code UCHAR DU_ItalianoStr1[] = {8,"Italiano"};
code UCHAR RU_ItalianoStr1[] = {8,"Italiano"};
code UCHAR SW_ItalianoStr1[] = {8,"Italiano"};
code UCHAR PR_ItalianoStr1[] = {8,"Italiano"};
code UCHAR JA_ItalianoStr1[] = {8,"Italiano"};
code UCHAR CT_ItalianoStr1[] = {8,"Italiano"};
code UCHAR CS_ItalianoStr1[] = {8,"Italiano"};
*/

code UCHAR EN_EspanolStr1[] = {7,'E','s','p','a',38,'o','l'};
/*
code UCHAR FR_EspanolStr1[] = {7,"Espanol"};
code UCHAR GE_EspanolStr1[] = {7,"Espanol"};
code UCHAR IT_EspanolStr1[] = {7,"Espanol"};
code UCHAR SP_EspanolStr1[] = {7,"Espanol"};
code UCHAR PO_EspanolStr1[] = {7,"Espanol"};
code UCHAR CZ_EspanolStr1[] = {7,"Espanol"};
code UCHAR MA_EspanolStr1[] = {7,"Espanol"};
code UCHAR SE_EspanolStr1[] = {7,"Espanol"};
code UCHAR RO_EspanolStr1[] = {7,"Espanol"};
code UCHAR DU_EspanolStr1[] = {7,"Espanol"};
code UCHAR RU_EspanolStr1[] = {7,"Espanol"};
code UCHAR SW_EspanolStr1[] = {7,"Espanol"};
code UCHAR PR_EspanolStr1[] = {7,"Espanol"};
code UCHAR JA_EspanolStr1[] = {7,"Espanol"};
code UCHAR CT_EspanolStr1[] = {7,"Espanol"};
code UCHAR CS_EspanolStr1[] = {7,"Espanol"};
*/

code UCHAR EN_PolishStr1[] = {6,"Polski"};
/*
code UCHAR FR_PolishStr1[] = {6,"Polish"};
code UCHAR GE_PolishStr1[] = {6,"Polish"};
code UCHAR IT_PolishStr1[] = {6,"Polish"};
code UCHAR SP_PolishStr1[] = {6,"Polish"};
code UCHAR PO_PolishStr1[] = {6,"Polish"};
code UCHAR CZ_PolishStr1[] = {6,"Polish"};
code UCHAR MA_PolishStr1[] = {6,"Polish"};
code UCHAR SE_PolishStr1[] = {6,"Polish"};
code UCHAR RO_PolishStr1[] = {6,"Polish"};
code UCHAR DU_PolishStr1[] = {6,"Polish"};
code UCHAR RU_PolishStr1[] = {6,"Polish"};
code UCHAR SW_PolishStr1[] = {6,"Polish"};
code UCHAR PR_PolishStr1[] = {6,"Polish"};
code UCHAR JA_PolishStr1[] = {6,"Polish"};
code UCHAR CT_PolishStr1[] = {6,"Polish"};
code UCHAR CS_PolishStr1[] = {6,"Polish"};
*/

code UCHAR EN_CzechStr1[] = {5,27,'e','s','k','y'};
/*
code UCHAR FR_CzechStr1[] = {5,"Czech"};
code UCHAR GE_CzechStr1[] = {5,"Czech"};
code UCHAR IT_CzechStr1[] = {5,"Czech"};
code UCHAR SP_CzechStr1[] = {5,"Czech"};
code UCHAR PO_CzechStr1[] = {5,"Czech"};
code UCHAR CZ_CzechStr1[] = {5,"Czech"};
code UCHAR MA_CzechStr1[] = {5,"Czech"};
code UCHAR SE_CzechStr1[] = {5,"Czech"};
code UCHAR RO_CzechStr1[] = {5,"Czech"};
code UCHAR DU_CzechStr1[] = {5,"Czech"};
code UCHAR RU_CzechStr1[] = {5,"Czech"};
code UCHAR SW_CzechStr1[] = {5,"Czech"};
code UCHAR PR_CzechStr1[] = {5,"Czech"};
code UCHAR JA_CzechStr1[] = {5,"Czech"};
code UCHAR CT_CzechStr1[] = {5,"Czech"};
code UCHAR CS_CzechStr1[] = {5,"Czech"};
*/

code UCHAR EN_HungarianStr1[] = {6,"Magyar"};
/*
code UCHAR FR_HungarianStr1[] = {9,"Hungarian"};
code UCHAR GE_HungarianStr1[] = {9,"Hungarian"};
code UCHAR IT_HungarianStr1[] = {9,"Hungarian"};
code UCHAR SP_HungarianStr1[] = {9,"Hungarian"};
code UCHAR PO_HungarianStr1[] = {9,"Hungarian"};
code UCHAR CZ_HungarianStr1[] = {9,"Hungarian"};
code UCHAR MA_HungarianStr1[] = {9,"Hungarian"};
code UCHAR SE_HungarianStr1[] = {9,"Hungarian"};
code UCHAR RO_HungarianStr1[] = {9,"Hungarian"};
code UCHAR DU_HungarianStr1[] = {9,"Hungarian"};
code UCHAR RU_HungarianStr1[] = {9,"Hungarian"};
code UCHAR SW_HungarianStr1[] = {9,"Hungarian"};
code UCHAR PR_HungarianStr1[] = {9,"Hungarian"};
code UCHAR JA_HungarianStr1[] = {9,"Hungarian"};
code UCHAR CT_HungarianStr1[] = {9,"Hungarian"};
code UCHAR CS_HungarianStr1[] = {9,"Hungarian"};
*/

code UCHAR EN_Serbo_croatianStr1[] = {16, "SiCG / BiH / CRO"};
/*
code UCHAR FR_Serbo_croatianStr1[] = {14, 'S', 'e', 'r', 'b', 'o', '-', 'c', 'r', 'o', 'a', 't', 'i', 'a', 'n', };
code UCHAR GE_Serbo_croatianStr1[] = {14, 'S', 'e', 'r', 'b', 'o', '-', 'c', 'r', 'o', 'a', 't', 'i', 'a', 'n', };
code UCHAR IT_Serbo_croatianStr1[] = {14, 'S', 'e', 'r', 'b', 'o', '-', 'c', 'r', 'o', 'a', 't', 'i', 'a', 'n', };
code UCHAR SP_Serbo_croatianStr1[] = {14, 'S', 'e', 'r', 'b', 'o', '-', 'c', 'r', 'o', 'a', 't', 'i', 'a', 'n', };
code UCHAR PO_Serbo_croatianStr1[] = {14, 'S', 'e', 'r', 'b', 'o', '-', 'c', 'r', 'o', 'a', 't', 'i', 'a', 'n', };
code UCHAR CZ_Serbo_croatianStr1[] = {14, 'S', 'e', 'r', 'b', 'o', '-', 'c', 'r', 'o', 'a', 't', 'i', 'a', 'n', };
code UCHAR MA_Serbo_croatianStr1[] = {14, 'S', 'e', 'r', 'b', 'o', '-', 'c', 'r', 'o', 'a', 't', 'i', 'a', 'n', };
code UCHAR SE_Serbo_croatianStr1[] = {14, 'S', 'e', 'r', 'b', 'o', '-', 'c', 'r', 'o', 'a', 't', 'i', 'a', 'n', };
code UCHAR RO_Serbo_croatianStr1[] = {14, 'S', 'e', 'r', 'b', 'o', '-', 'c', 'r', 'o', 'a', 't', 'i', 'a', 'n', };
code UCHAR DU_Serbo_croatianStr1[] = {14, 'S', 'e', 'r', 'b', 'o', '-', 'c', 'r', 'o', 'a', 't', 'i', 'a', 'n', };
code UCHAR RU_Serbo_croatianStr1[] = {14, 'S', 'e', 'r', 'b', 'o', '-', 'c', 'r', 'o', 'a', 't', 'i', 'a', 'n', };
code UCHAR SW_Serbo_croatianStr1[] = {14, 'S', 'e', 'r', 'b', 'o', '-', 'c', 'r', 'o', 'a', 't', 'i', 'a', 'n', };
code UCHAR PR_Serbo_croatianStr1[] = {14, 'S', 'e', 'r', 'b', 'o', '-', 'c', 'r', 'o', 'a', 't', 'i', 'a', 'n', };
code UCHAR JA_Serbo_croatianStr1[] = {14, 'S', 'e', 'r', 'b', 'o', '-', 'c', 'r', 'o', 'a', 't', 'i', 'a', 'n', };
code UCHAR CT_Serbo_croatianStr1[] = {14, 'S', 'e', 'r', 'b', 'o', '-', 'c', 'r', 'o', 'a', 't', 'i', 'a', 'n', };
code UCHAR CS_Serbo_croatianStr1[] = {14, 'S', 'e', 'r', 'b', 'o', '-', 'c', 'r', 'o', 'a', 't', 'i', 'a', 'n', };
*/

code UCHAR EN_RomanianStr1[] = {6,'R','o','m',42,'n',42};
/*
code UCHAR FR_RomanianStr1[] = {8,"Romanian"};
code UCHAR GE_RomanianStr1[] = {8,"Romanian"};
code UCHAR IT_RomanianStr1[] = {8,"Romanian"};
code UCHAR SP_RomanianStr1[] = {8,"Romanian"};
code UCHAR PO_RomanianStr1[] = {8,"Romanian"};
code UCHAR CZ_RomanianStr1[] = {8,"Romanian"};
code UCHAR MA_RomanianStr1[] = {8,"Romanian"};
code UCHAR SE_RomanianStr1[] = {8,"Romanian"};
code UCHAR RO_RomanianStr1[] = {8,"Romanian"};
code UCHAR DU_RomanianStr1[] = {8,"Romanian"};
code UCHAR RU_RomanianStr1[] = {8,"Romanian"};
code UCHAR SW_RomanianStr1[] = {8,"Romanian"};
code UCHAR PR_RomanianStr1[] = {8,"Romanian"};
code UCHAR JA_RomanianStr1[] = {8,"Romanian"};
code UCHAR CT_RomanianStr1[] = {8,"Romanian"};
code UCHAR CS_RomanianStr1[] = {8,"Romanian"};
*/

code UCHAR EN_NetherlandsStr1[] = {10,"Nederlands"};
/*
code UCHAR FR_NetherlandsStr1[] = {11,"Netherlands"};
code UCHAR GE_NetherlandsStr1[] = {11,"Netherlands"};
code UCHAR IT_NetherlandsStr1[] = {11,"Netherlands"};
code UCHAR SP_NetherlandsStr1[] = {11,"Netherlands"};
code UCHAR PO_NetherlandsStr1[] = {11,"Netherlands"};
code UCHAR CZ_NetherlandsStr1[] = {11,"Netherlands"};
code UCHAR MA_NetherlandsStr1[] = {11,"Netherlands"};
code UCHAR SE_NetherlandsStr1[] = {11,"Netherlands"};
code UCHAR RO_NetherlandsStr1[] = {11,"Netherlands"};
code UCHAR DU_NetherlandsStr1[] = {11,"Netherlands"};
code UCHAR RU_NetherlandsStr1[] = {11,"Netherlands"};
code UCHAR SW_NetherlandsStr1[] = {11,"Netherlands"};
code UCHAR PR_NetherlandsStr1[] = {11,"Netherlands"};
code UCHAR JA_NetherlandsStr1[] = {11,"Netherlands"};
code UCHAR CT_NetherlandsStr1[] = {11,"Netherlands"};
code UCHAR CS_NetherlandsStr1[] = {11,"Netherlands"};
*/

code UCHAR EN_RussianStr1[] = {7,'P','y','c','c',35,36,38};
/*
code UCHAR FR_RussianStr1[] = {7,"Russian"};
code UCHAR GE_RussianStr1[] = {7,"Russian"};
code UCHAR IT_RussianStr1[] = {7,"Russian"};
code UCHAR SP_RussianStr1[] = {7,"Russian"};
code UCHAR PO_RussianStr1[] = {7,"Russian"};
code UCHAR CZ_RussianStr1[] = {7,"Russian"};
code UCHAR MA_RussianStr1[] = {7,"Russian"};
code UCHAR SE_RussianStr1[] = {7,"Russian"};
code UCHAR RO_RussianStr1[] = {7,"Russian"};
code UCHAR DU_RussianStr1[] = {7,"Russian"};
code UCHAR RU_RussianStr1[] = {7,"Russian"};
code UCHAR SW_RussianStr1[] = {7,"Russian"};
code UCHAR PR_RussianStr1[] = {7,"Russian"};
code UCHAR JA_RussianStr1[] = {7,"Russian"};
code UCHAR CT_RussianStr1[] = {7,"Russian"};
code UCHAR CS_RussianStr1[] = {7,"Russian"};
*/

code UCHAR EN_SwedishStr1[] = {7,"Svenska"};
/*
code UCHAR FR_SwedishStr1[] = {7,"Swedish"};
code UCHAR GE_SwedishStr1[] = {7,"Swedish"};
code UCHAR IT_SwedishStr1[] = {7,"Swedish"};
code UCHAR SP_SwedishStr1[] = {7,"Swedish"};
code UCHAR PO_SwedishStr1[] = {7,"Swedish"};
code UCHAR CZ_SwedishStr1[] = {7,"Swedish"};
code UCHAR MA_SwedishStr1[] = {7,"Swedish"};
code UCHAR SE_SwedishStr1[] = {7,"Swedish"};
code UCHAR RO_SwedishStr1[] = {7,"Swedish"};
code UCHAR DU_SwedishStr1[] = {7,"Swedish"};
code UCHAR RU_SwedishStr1[] = {7,"Swedish"};
code UCHAR SW_SwedishStr1[] = {7,"Swedish"};
code UCHAR PR_SwedishStr1[] = {7,"Swedish"};
code UCHAR JA_SwedishStr1[] = {7,"Swedish"};
code UCHAR CT_SwedishStr1[] = {7,"Swedish"};
code UCHAR CS_SwedishStr1[] = {7,"Swedish"};
*/

code UCHAR EN_ProtugueseStr1[] = {9,'P','o','r','t','u','g','u',43,'s'};
/*
code UCHAR FR_ProtugueseStr1[] = {10,"Protuguese"};
code UCHAR GE_ProtugueseStr1[] = {10,"Protuguese"};
code UCHAR IT_ProtugueseStr1[] = {10,"Protuguese"};
code UCHAR SP_ProtugueseStr1[] = {10,"Protuguese"};
code UCHAR PO_ProtugueseStr1[] = {10,"Protuguese"};
code UCHAR CZ_ProtugueseStr1[] = {10,"Protuguese"};
code UCHAR MA_ProtugueseStr1[] = {10,"Protuguese"};
code UCHAR SE_ProtugueseStr1[] = {10,"Protuguese"};
code UCHAR RO_ProtugueseStr1[] = {10,"Protuguese"};
code UCHAR DU_ProtugueseStr1[] = {10,"Protuguese"};
code UCHAR RU_ProtugueseStr1[] = {10,"Protuguese"};
code UCHAR SW_ProtugueseStr1[] = {10,"Protuguese"};
code UCHAR PR_ProtugueseStr1[] = {10,"Protuguese"};
code UCHAR JA_ProtugueseStr1[] = {10,"Protuguese"};
code UCHAR CT_ProtugueseStr1[] = {10,"Protuguese"};
code UCHAR CS_ProtugueseStr1[] = {10,"Protuguese"};
*/

code UCHAR EN_JapaneseStr1[] = {3, 13, 14, 15, };
/*
code UCHAR FR_JapaneseStr1[] = {3, 13, 14, 15, };
code UCHAR GE_JapaneseStr1[] = {3, 13, 14, 15, };
code UCHAR IT_JapaneseStr1[] = {3, 13, 14, 15, };
code UCHAR SP_JapaneseStr1[] = {3, 13, 14, 15, };
code UCHAR PO_JapaneseStr1[] = {3, 13, 14, 15, };
code UCHAR CZ_JapaneseStr1[] = {3, 13, 14, 15, };
code UCHAR MA_JapaneseStr1[] = {3, 13, 14, 15, };
code UCHAR SE_JapaneseStr1[] = {3, 13, 14, 15, };
code UCHAR RO_JapaneseStr1[] = {3, 13, 14, 15, };
code UCHAR DU_JapaneseStr1[] = {3, 13, 14, 15, };
code UCHAR RU_JapaneseStr1[] = {3, 13, 14, 15, };
code UCHAR SW_JapaneseStr1[] = {3, 13, 14, 15, };
code UCHAR PR_JapaneseStr1[] = {3, 13, 14, 15, };
*/
code UCHAR JA_JapaneseStr1[] = {3, 201, 202, 203, };
code UCHAR CT_JapaneseStr1[] = {3, 199, 200, 201, };
code UCHAR CS_JapaneseStr1[] = {3, 195, 196, 197, };

code UCHAR EN_ChineseS_Str1[] = {4, 16, 17, 8, 9, };
/*
code UCHAR FR_ChineseS_Str1[] = {4, 16, 17, 8, 9, };
code UCHAR GE_ChineseS_Str1[] = {4, 16, 17, 8, 9, };
code UCHAR IT_ChineseS_Str1[] = {4, 16, 17, 8, 9, };
code UCHAR SP_ChineseS_Str1[] = {4, 16, 17, 8, 9, };
code UCHAR PO_ChineseS_Str1[] = {4, 16, 17, 8, 9, };
code UCHAR CZ_ChineseS_Str1[] = {4, 16, 17, 8, 9, };
code UCHAR MA_ChineseS_Str1[] = {4, 16, 17, 8, 9, };
code UCHAR SE_ChineseS_Str1[] = {4, 16, 17, 8, 9, };
code UCHAR RO_ChineseS_Str1[] = {4, 16, 17, 8, 9, };
code UCHAR DU_ChineseS_Str1[] = {4, 16, 17, 8, 9, };
code UCHAR RU_ChineseS_Str1[] = {4, 16, 17, 8, 9, };
code UCHAR SW_ChineseS_Str1[] = {4, 16, 17, 8, 9, };
code UCHAR PR_ChineseS_Str1[] = {4, 16, 17, 8, 9, };
*/
code UCHAR JA_ChineseS_Str1[] = {4, 204, 205, 4, 206, };
code UCHAR CT_ChineseS_Str1[] = {4, 202, 203, 4, 204, };
code UCHAR CS_ChineseS_Str1[] = {4, 198, 199, 4, 200, };

code UCHAR EN_ChineseT_Str1[] = {4, 18, 19, 8, 9, };
/*
code UCHAR FR_ChineseT_Str1[] = {4, 18, 19, 8, 9, };
code UCHAR GE_ChineseT_Str1[] = {4, 18, 19, 8, 9, };
code UCHAR IT_ChineseT_Str1[] = {4, 18, 19, 8, 9, };
code UCHAR SP_ChineseT_Str1[] = {4, 18, 19, 8, 9, };
code UCHAR PO_ChineseT_Str1[] = {4, 18, 19, 8, 9, };
code UCHAR CZ_ChineseT_Str1[] = {4, 18, 19, 8, 9, };
code UCHAR MA_ChineseT_Str1[] = {4, 18, 19, 8, 9, };
code UCHAR SE_ChineseT_Str1[] = {4, 18, 19, 8, 9, };
code UCHAR RO_ChineseT_Str1[] = {4, 18, 19, 8, 9, };
code UCHAR DU_ChineseT_Str1[] = {4, 18, 19, 8, 9, };
code UCHAR RU_ChineseT_Str1[] = {4, 18, 19, 8, 9, };
code UCHAR SW_ChineseT_Str1[] = {4, 18, 19, 8, 9, };
code UCHAR PR_ChineseT_Str1[] = {4, 18, 19, 8, 9, };
*/
code UCHAR JA_ChineseT_Str1[] = {4, 207, 208, 4, 206, };
code UCHAR CT_ChineseT_Str1[] = {4, 205, 206, 4, 204, };
code UCHAR CS_ChineseT_Str1[] = {4, 201, 202, 4, 200, };

code UCHAR NULL_Str1[] = {1,' '};

code UCHAR *LanguageTab[] = {
EN_EnglishStr1,
EN_EnglishStr1,//FR
EN_EnglishStr1,//GE
EN_EnglishStr1,//IT
EN_EnglishStr1,//SP
EN_EnglishStr1,//PO
EN_EnglishStr1,//CZ
EN_EnglishStr1,//MA
EN_EnglishStr1,//SE
EN_EnglishStr1,//RO
EN_EnglishStr1,//DU
EN_EnglishStr1,//RU
EN_EnglishStr1,//SW
EN_EnglishStr1,//PR
EN_EnglishStr1,//JA
EN_EnglishStr1,//CT
EN_EnglishStr1,//CS

EN_FrancaisStr1,
EN_FrancaisStr1,//FR
EN_FrancaisStr1,//GE
EN_FrancaisStr1,//IT
EN_FrancaisStr1,//SP
EN_FrancaisStr1,//PO
EN_FrancaisStr1,//CZ
EN_FrancaisStr1,//MA
EN_FrancaisStr1,//SE
EN_FrancaisStr1,//RO
EN_FrancaisStr1,//DU
EN_FrancaisStr1,//RU
EN_FrancaisStr1,//SW
EN_FrancaisStr1,//PR
JA_FrancaisStr1,
CT_FrancaisStr1,
CS_FrancaisStr1,

EN_DeutschStr1,
EN_DeutschStr1,//FR
EN_DeutschStr1,//GE
EN_DeutschStr1,//IT
EN_DeutschStr1,//SP
EN_DeutschStr1,//PO
EN_DeutschStr1,//CZ
EN_DeutschStr1,//MA
EN_DeutschStr1,//SE
EN_DeutschStr1,//RO
EN_DeutschStr1,//DU
EN_DeutschStr1,//RU
EN_DeutschStr1,//SW
EN_DeutschStr1,//PR
EN_DeutschStr1,//JA
EN_DeutschStr1,//CT
EN_DeutschStr1,//CS

EN_ItalianoStr1,
EN_ItalianoStr1,//FR
EN_ItalianoStr1,//GE
EN_ItalianoStr1,//IT
EN_ItalianoStr1,//SP
EN_ItalianoStr1,//PO
EN_ItalianoStr1,//CZ
EN_ItalianoStr1,//MA
EN_ItalianoStr1,//SE
EN_ItalianoStr1,//RO
EN_ItalianoStr1,//DU
EN_ItalianoStr1,//RU
EN_ItalianoStr1,//SW
EN_ItalianoStr1,//PR
EN_ItalianoStr1,//JA
EN_ItalianoStr1,//CT
EN_ItalianoStr1,//CS

EN_EspanolStr1,
EN_EspanolStr1,//FR
EN_EspanolStr1,//GE
EN_EspanolStr1,//IT
EN_EspanolStr1,//SP
EN_EspanolStr1,//PO
EN_EspanolStr1,//CZ
EN_EspanolStr1,//MA
EN_EspanolStr1,//SE
EN_EspanolStr1,//RO
EN_EspanolStr1,//DU
EN_EspanolStr1,//RU
EN_EspanolStr1,//SW
EN_EspanolStr1,//PR
EN_EspanolStr1,//JA
EN_EspanolStr1,//CT
EN_EspanolStr1,//CS

EN_PolishStr1,
EN_PolishStr1,//FR
EN_PolishStr1,//GE
EN_PolishStr1,//IT
EN_PolishStr1,//SP
EN_PolishStr1,//PO
EN_PolishStr1,//CZ
EN_PolishStr1,//MA
EN_PolishStr1,//SE
EN_PolishStr1,//RO
EN_PolishStr1,//DU
EN_PolishStr1,//RU
EN_PolishStr1,//SW
EN_PolishStr1,//PR
EN_PolishStr1,//JA
EN_PolishStr1,//CT
EN_PolishStr1,//CS

EN_CzechStr1,
EN_CzechStr1,//FR
EN_CzechStr1,//GE
EN_CzechStr1,//IT
EN_CzechStr1,//SP
EN_CzechStr1,//PO
EN_CzechStr1,//CZ
EN_CzechStr1,//MA
EN_CzechStr1,//SE
EN_CzechStr1,//RO
EN_CzechStr1,//DU
EN_CzechStr1,//RU
EN_CzechStr1,//SW
EN_CzechStr1,//PR
EN_CzechStr1,//JA
EN_CzechStr1,//CT
EN_CzechStr1,//CS

EN_HungarianStr1,
EN_HungarianStr1,//FR
EN_HungarianStr1,//GE
EN_HungarianStr1,//IT
EN_HungarianStr1,//SP
EN_HungarianStr1,//PO
EN_HungarianStr1,//CZ
EN_HungarianStr1,//MA
EN_HungarianStr1,//SE
EN_HungarianStr1,//RO
EN_HungarianStr1,//DU
EN_HungarianStr1,//RU
EN_HungarianStr1,//SW
EN_HungarianStr1,//PR
EN_HungarianStr1,//JA
EN_HungarianStr1,//CT
EN_HungarianStr1,//CS

EN_Serbo_croatianStr1,
EN_Serbo_croatianStr1,//FR
EN_Serbo_croatianStr1,//GE
EN_Serbo_croatianStr1,//IT
EN_Serbo_croatianStr1,//SP
EN_Serbo_croatianStr1,//PO
EN_Serbo_croatianStr1,//CZ
EN_Serbo_croatianStr1,//MA
EN_Serbo_croatianStr1,//SE
EN_Serbo_croatianStr1,//RO
EN_Serbo_croatianStr1,//DU
EN_Serbo_croatianStr1,//RU
EN_Serbo_croatianStr1,//SW
EN_Serbo_croatianStr1,//PR
EN_Serbo_croatianStr1,//JA
EN_Serbo_croatianStr1,//CT
EN_Serbo_croatianStr1,//CS

EN_RomanianStr1,
EN_RomanianStr1,//FR
EN_RomanianStr1,//GE
EN_RomanianStr1,//IT
EN_RomanianStr1,//SP
EN_RomanianStr1,//PO
EN_RomanianStr1,//CZ
EN_RomanianStr1,//MA
EN_RomanianStr1,//SE
EN_RomanianStr1,//RO
EN_RomanianStr1,//DU
EN_RomanianStr1,//RU
EN_RomanianStr1,//SW
EN_RomanianStr1,//PR
EN_RomanianStr1,//JA
EN_RomanianStr1,//CT
EN_RomanianStr1,//CS

EN_NetherlandsStr1,
EN_NetherlandsStr1,//FR
EN_NetherlandsStr1,//GE
EN_NetherlandsStr1,//IT
EN_NetherlandsStr1,//SP
EN_NetherlandsStr1,//PO
EN_NetherlandsStr1,//CZ
EN_NetherlandsStr1,//MA
EN_NetherlandsStr1,//SE
EN_NetherlandsStr1,//RO
EN_NetherlandsStr1,//DU
EN_NetherlandsStr1,//RU
EN_NetherlandsStr1,//SW
EN_NetherlandsStr1,//PR
EN_NetherlandsStr1,//JA
EN_NetherlandsStr1,//CT
EN_NetherlandsStr1,//CS

EN_RussianStr1,
EN_RussianStr1,//FR
EN_RussianStr1,//GE
EN_RussianStr1,//IT
EN_RussianStr1,//SP
EN_RussianStr1,//PO
EN_RussianStr1,//CZ
EN_RussianStr1,//MA
EN_RussianStr1,//SE
EN_RussianStr1,//RO
EN_RussianStr1,//DU
EN_RussianStr1,//RU
EN_RussianStr1,//SW
EN_RussianStr1,//PR
EN_RussianStr1,//JA
EN_RussianStr1,//CT
EN_RussianStr1,//CS


EN_SwedishStr1,
EN_SwedishStr1,//FR
EN_SwedishStr1,//GE
EN_SwedishStr1,//IT
EN_SwedishStr1,//SP
EN_SwedishStr1,//PO
EN_SwedishStr1,//CZ
EN_SwedishStr1,//MA
EN_SwedishStr1,//SE
EN_SwedishStr1,//RO
EN_SwedishStr1,//DU
EN_SwedishStr1,//RU
EN_SwedishStr1,//SW
EN_SwedishStr1,//PR
EN_SwedishStr1,//JA
EN_SwedishStr1,//CT
EN_SwedishStr1,//CS

EN_ProtugueseStr1,
EN_ProtugueseStr1,//FR
EN_ProtugueseStr1,//GE
EN_ProtugueseStr1,//IT
EN_ProtugueseStr1,//SP
EN_ProtugueseStr1,//PO
EN_ProtugueseStr1,//CZ
EN_ProtugueseStr1,//MA
EN_ProtugueseStr1,//SE
EN_ProtugueseStr1,//RO
EN_ProtugueseStr1,//DU
EN_ProtugueseStr1,//RU
EN_ProtugueseStr1,//SW
EN_ProtugueseStr1,//PR
EN_ProtugueseStr1,//JA
EN_ProtugueseStr1,//CT
EN_ProtugueseStr1,//CS

EN_JapaneseStr1,
EN_JapaneseStr1,//FR
EN_JapaneseStr1,//GE
EN_JapaneseStr1,//IT
EN_JapaneseStr1,//SP
EN_JapaneseStr1,//PO
EN_JapaneseStr1,//CZ
EN_JapaneseStr1,//MA
EN_JapaneseStr1,//SE
EN_JapaneseStr1,//RO
EN_JapaneseStr1,//DU
EN_JapaneseStr1,//RU
EN_JapaneseStr1,//SW
EN_JapaneseStr1,//PR
JA_JapaneseStr1,
CT_JapaneseStr1,
CS_JapaneseStr1,

EN_ChineseS_Str1,
EN_ChineseS_Str1,//FR
EN_ChineseS_Str1,//GE
EN_ChineseS_Str1,//IT
EN_ChineseS_Str1,//SP
EN_ChineseS_Str1,//PO
EN_ChineseS_Str1,//CZ
EN_ChineseS_Str1,//MA
EN_ChineseS_Str1,//SE
EN_ChineseS_Str1,//RO
EN_ChineseS_Str1,//DU
EN_ChineseS_Str1,//RU
EN_ChineseS_Str1,//SW
EN_ChineseS_Str1,//PR
JA_ChineseS_Str1,
CT_ChineseS_Str1,
CS_ChineseS_Str1,

EN_ChineseT_Str1,
EN_ChineseT_Str1,//FR
EN_ChineseT_Str1,//GE
EN_ChineseT_Str1,//IT
EN_ChineseT_Str1,//SP
EN_ChineseT_Str1,//PO
EN_ChineseT_Str1,//CZ
EN_ChineseT_Str1,//MA
EN_ChineseT_Str1,//SE
EN_ChineseT_Str1,//RO
EN_ChineseT_Str1,//DU
EN_ChineseT_Str1,//RU
EN_ChineseT_Str1,//SW
EN_ChineseT_Str1,//PR
JA_ChineseT_Str1,
CT_ChineseT_Str1,
CS_ChineseT_Str1,

NULL_Str1,

 };

 code UCHAR EN_NonPreSentMode_Str[]={14, 'N', 'o', 'n', 'p', 'r', 'e', 's', 'e', 't', ' ', 'M', 'o', 'd', 'e', };
 code UCHAR FR_NonPreSentMode_Str[]={19, 'M', 'o', 'd', 'e', ' ', 'n', 'o', 'n', ' ', 'p', 'r', 2, 'd', 2, 'f', 'i', 'n', 'i', 12, };
 code UCHAR GE_NonPreSentMode_Str[]={27, 'K', 'e', 'i', 'n', ' ', 'v', 'o', 'r', 'e', 'i', 'n', 'g', 'e', 's', 't', 'e', 'l', 'l', 't', 'e', 'r', ' ', 'M', 'o', 'd', 'u', 's', };
 code UCHAR IT_NonPreSentMode_Str[]={25, 'M', 'o', 'd', 'a', 'l', 'i', 't', 123, ' ', 'n', 'o', 'n', ' ', 'p', 'r', 'e', 'i', 'm', 'p', 'o', 's', 't', 'a', 't', 'a', };
 code UCHAR SP_NonPreSentMode_Str[]={22, 'N', 'o', ' ', 's', 'e', ' ', 'a', 'd', 'm', 'i', 't', 'e', ' ', 'e', 's', 't', 'e', ' ', 'm', 'o', 'd', 'o', };
 code UCHAR PO_NonPreSentMode_Str[]={15, 'B', 'r', 'a', 'k', ' ', 't', 'e', 'g', 'o', ' ', 't', 'r', 'y', 'b', 'u', };
 code UCHAR CZ_NonPreSentMode_Str[]={18, 'N', 'e', 'e', 'x', 'i', 's', 't', 'u', 'j', 1, 'c', 1, ' ', 'r', 'e', 26, 'i', 'm', };
 code UCHAR MA_NonPreSentMode_Str[]={13, 'N', 'e', 'm', ' ', 'n', 'a', 't', 1, 'v', ' ', 'm', 4, 'd', };
 code UCHAR SE_NonPreSentMode_Str[]={22, 'N', 'e', 'p', 'o', 's', 't', 'o', 'j', 'e', 22, 'i', ' ', 'n', 'a', 6, 'i', 'n', ' ', 'r', 'a', 'd', 'a', };
 code UCHAR RO_NonPreSentMode_Str[]={14, 'M', 'o', 'd', ' ', 'i', 'n', 'e', 'x', 'i', 's', 't', 'e', 'n', 't', };
 code UCHAR DU_NonPreSentMode_Str[]={19, 'M', 'o', 'd', 'u', 's', ' ', 'n', 'i', 'e', 't', ' ', 'a', 'a', 'n', 'w', 'e', 'z', 'i', 'g', };
 code UCHAR RU_NonPreSentMode_Str[]={19, 162, 132, 125, 135, 132, 125, 132, 131, 135, 174, 163, 124, 129, ' ', 133, 128, 152, 124, 146, };
 code UCHAR SW_NonPreSentMode_Str[]={19, 'E', 'j', ' ', 'f', 10, 'r', 'i', 'n', 's', 't', 3, 'l', 'l', 't', ' ', 'l', 3, 'g', 'e', };
 code UCHAR PR_NonPreSentMode_Str[]={17, 'M', 'o', 'd', 'o', ' ', 'N', 123, 'o', ' ', 'P', 'r', 'e', 's', 'e', 'n', 't', 'e', };
 code UCHAR JA_NonPreSentMode_Str[]={11, 11, 12, 13, 14, 15, 16, 17, 18, 19, 9, 10, };
 code UCHAR CT_NonPreSentMode_Str[]={5, 13, 14, 15, 16, 17, };
 code UCHAR CS_NonPreSentMode_Str[]={5, 13, 14, 15, 16, 17, };

code UCHAR *NonPreSentModeTab[] = {
       EN_NonPreSentMode_Str,
       FR_NonPreSentMode_Str,
       GE_NonPreSentMode_Str,
       IT_NonPreSentMode_Str,
       SP_NonPreSentMode_Str,
       PO_NonPreSentMode_Str,
       CZ_NonPreSentMode_Str,
       MA_NonPreSentMode_Str,
       SE_NonPreSentMode_Str,
       RO_NonPreSentMode_Str,
       DU_NonPreSentMode_Str,
       RU_NonPreSentMode_Str,
       SW_NonPreSentMode_Str,
       PR_NonPreSentMode_Str,
       JA_NonPreSentMode_Str,
       CT_NonPreSentMode_Str,
       CS_NonPreSentMode_Str,    
};

code UCHAR ModelWord_Str1[] = {8, 'G','W',50,55,54,53,'H','T'};
code UCHAR *ModelWordStrTab[] = {
    ModelWord_Str1,
};

code UCHAR DPmode1_2_Str1[] = {3, 49,'.',50};
code UCHAR DPmode1_1_Str1[] = {3, 49,'.',49};
code UCHAR *DPmodeStrTab[] = {
    DPmode1_1_Str1, 
    DPmode1_1_Str1, 
    DPmode1_1_Str1, 
    DPmode1_1_Str1, 
    DPmode1_1_Str1,     
    DPmode1_1_Str1, 
    DPmode1_1_Str1, 
    DPmode1_1_Str1, 
    DPmode1_1_Str1, 
    DPmode1_1_Str1, 
    DPmode1_1_Str1, 
    DPmode1_1_Str1, 
    DPmode1_1_Str1, 
    DPmode1_1_Str1, 
    DPmode1_1_Str1,     
    DPmode1_1_Str1, 
    DPmode1_1_Str1,     
    
    DPmode1_2_Str1,
    DPmode1_2_Str1,
    DPmode1_2_Str1,
    DPmode1_2_Str1,
    DPmode1_2_Str1,    
    DPmode1_2_Str1,
    DPmode1_2_Str1,
    DPmode1_2_Str1,
    DPmode1_2_Str1,
    DPmode1_2_Str1,
    DPmode1_2_Str1,
    DPmode1_2_Str1,
    DPmode1_2_Str1,
    DPmode1_2_Str1,
    DPmode1_2_Str1,    
    DPmode1_2_Str1,
    DPmode1_2_Str1,    
};


/*
  code UCHAR EN_SaveSetting_Str[]={13, 'S', 'a', 'v', 'e', ' ', 'S', 'e', 't', 't', 'i', 'n', 'g', 's', };
  code UCHAR FR_SaveSetting_Str[]={15, 'E', 'n', 'r', 'e', 'g', '.', ' ', 'R', 2, 'g', 'l', 'a', 'g', 'e', 's', };
  code UCHAR GE_SaveSetting_Str[]={16, 'E', 'i', 'n', 's', 't', '.', ' ', 'S', 'p', 'e', 'i', 'c', 'h', 'e', 'r', 'n', };
  code UCHAR IT_SaveSetting_Str[]={18, 'S', 'a', 'l', 'v', 'a', ' ', 'I', 'm', 'p', 'o', 's', 't', 'a', 'z', 'i', 'o', 'n', 'i', };
  code UCHAR SP_SaveSetting_Str[]={15, 'G', 'u', 'a', 'r', 'd', 'a', 'r', ' ', 'A', 'j', 'u', 's', 't', 'e', 's', };
  code UCHAR PO_SaveSetting_Str[]={17, 'Z', 'a', 'p', 'i', 's', 'z', ' ', 'U', 's', 't', 'a', 'w', 'i', 'e', 'n', 'i', 'a', };
  
  code UCHAR CZ_SaveSetting_Str[]={16, 'U', 'l', 'o', 26, 'i', 't', ' ', 'N', 'a', 's', 't', 'a', 'v', 'e', 'n', 1, };
  code UCHAR MA_SaveSetting_Str[]={15, 'B', 'e', 0, 'l', 'l', 1, 't', 0, 's', 'm', 'e', 'n', 't', 2, 's', };
  code UCHAR SE_SaveSetting_Str[]={15, 'S', 'p', 'r', 'e', 'm', 'i', ' ', 'P', 'o', 's', 't', 'a', 'v', 'k', 'e', };
  code UCHAR RO_SaveSetting_Str[]={14, 'S', 'a', 'l', 'v', 'a', 'r', 'e', ' ', 'S', 'e', 't', 125, 'r', 'i', };
  code UCHAR DU_SaveSetting_Str[]={12, 'I', 'n', 's', 't', ' ', 'O', 'p', 's', 'l', 'a', 'a', 'n', };
  code UCHAR RU_SaveSetting_Str[]={12, 164, 136, 138, 133, '.', ' ', 144, 143, 125, 132, 133, '.', };
  code UCHAR SW_SaveSetting_Str[]={5, 'S', 'p', 'a', 'r', 'a', };
  code UCHAR PR_SaveSetting_Str[]={14, 'G', 'u', 'a', 'r', 'd', 'a', 'r', ' ', 'D', 'e', 'f', 'i', 'n', '.', };
  code UCHAR JA_SaveSetting_Str[]={5,   141, 142, 230, 231, 232, };
  code UCHAR CT_SaveSetting_Str[]={4,   221, 222, 147, 133, };
  code UCHAR CS_SaveSetting_Str[]={4,   220, 221, 145, 13, };

code UCHAR *SaveSettingModeTab[] = {
       EN_SaveSetting_Str,
       FR_SaveSetting_Str,
       GE_SaveSetting_Str,
       IT_SaveSetting_Str,
       SP_SaveSetting_Str,
       PO_SaveSetting_Str,
       CZ_SaveSetting_Str,
       MA_SaveSetting_Str,
       SE_SaveSetting_Str,
       RO_SaveSetting_Str,
       DU_SaveSetting_Str,
       RU_SaveSetting_Str,
       SW_SaveSetting_Str,
       PR_SaveSetting_Str,
       JA_SaveSetting_Str,
       CT_SaveSetting_Str,
       CS_SaveSetting_Str,    
};
*/
code UCHAR EN_CustomKey1SaveStr1[] = {26, 'C', 'u', 's', 't', 'o', 'm', ' ', 'k', 'e', 'y', ' ', '1',' ','S', 'a', 'v', 'e', ' ', 'S', 'e', 't', 't', 'i', 'n', 'g', 's', };
code UCHAR FR_CustomKey1SaveStr1[] = {30, 'T', 'o', 'u', 'c', 'h', 'e', ' ', 'p', 'e', 'r', 's', 'o', ' ', '1', ' ', 'E', 'n', 'r', 'e', 'g', '.', ' ', 'R', 2, 'g', 'l', 'a', 'g', 'e', 's',};
code UCHAR GE_CustomKey1SaveStr1[] = {33, 'B', 'e', 'n', 'u', 't', 'z', 'e', 'r', '-', 'T', 'a', 's', 't', 'e', ' ', '1', ' ', 'E', 'i', 'n', 's', 't', '.', ' ', 'S', 'p', 'e', 'i', 'c', 'h', 'e', 'r', 'n',};
code UCHAR IT_CustomKey1SaveStr1[] = {38, 'T', 'a', 's', 't', 'o', ' ', 'p', 'e', 'r', 's', 'o', 'n', 'a', 'l', 'i', 'z', 'z', ' ', '1', ' ','S', 'a', 'l', 'v', 'a', ' ', 'I', 'm', 'p', 'o', 's', 't', 'a', 'z', 'i', 'o', 'n', 'i',};
code UCHAR SP_CustomKey1SaveStr1[] = {35, 'T', 'e', 'c', 'l', 'a', ' ', 'p', 'e', 'r', 's', 'o', 'n', 'a', 'l', 'i', 'z', '.', ' ', '1', ' ', 'G', 'u', 'a', 'r', 'd', 'a', 'r', ' ', 'A', 'j', 'u', 's', 't', 'e', 's',};
code UCHAR PO_CustomKey1SaveStr1[] = {37, 'P', 'r', 'z', 'y', 'c', 'i', 's', 'k', ' ', 'n', 'i', 'e', 's', 't', 'a', 'n', '.', ' ', '1', ' ','Z', 'a', 'p', 'i', 's', 'z', ' ', 'U', 's', 't', 'a', 'w', 'i', 'e', 'n', 'i', 'a',};
code UCHAR CZ_CustomKey1SaveStr1[] = {34, 'V', 'l', 'a', 's', 't', 'n', 1, ' ', 'k', 'l', 0, 'v', 'e', 's', 'a', ' ', '1',  ' ', 'U', 'l', 'o', 26, 'i', 't', ' ', 'N', 'a', 's', 't', 'a', 'v', 'e', 'n', 1, };
code UCHAR MA_CustomKey1SaveStr1[] = {30, 'E', 'g', 'y', 2, 'n', 'i', ' ', 'k', 'u', 'l', 'c', 's', ' ', '1',  ' ', 'B', 'e', 0, 'l', 'l', 1, 't', 0, 's', 'm', 'e', 'n', 't', 2, 's', };
code UCHAR SE_CustomKey1SaveStr1[] = {34, 'K', 'o', 'r', 'i', 's', 'n', 'i', 6, 'k', 'a', ' ', 't', 'i', 'p', 'k', 'a', ' ', '1',  ' ', 'S', 'p', 'r', 'e', 'm', 'i', ' ', 'P', 'o', 's', 't', 'a', 'v', 'k', 'e', };
code UCHAR RO_CustomKey1SaveStr1[] = {34, 'T', 'a', 's', 't', 125, ' ', 'p', 'e', 'r', 's', 'o', 'n', 'a', 'l', 'i', 'z', '.', ' ', '1',  ' ', 'S', 'a', 'l', 'v', 'a', 'r', 'e', ' ', 'S', 'e', 't', 125, 'r', 'i', };
code UCHAR DU_CustomKey1SaveStr1[] = {31, 'A', 'a', 'n', 'g', 'e', 'p', 'a', 's', 't', 'e', ' ', 't', 'o', 'e', 't', 's', ' ', '1',  ' ', 'I', 'n', 's', 't', ' ', 'O', 'p', 's', 'l', 'a', 'a', 'n', };
code UCHAR RU_CustomKey1SaveStr1[] = {32, 153, 144, 136, 126, 148, 143, ' ', '"', 167, 136, 127, 155, 141, 136, 131, '.', '"', ' ', '1', ' ', 164, 136, 138, 133, '.', ' ', 144, 143, 125, 132, 133, '.', };
code UCHAR SW_CustomKey1SaveStr1[] = {22, 'A', 'n', 'p', 'a', 's', 's', 'a', 'd', ' ', 'k', 'n', 'a', 'p', 'p', ' ', '1', ' ','S', 'p', 'a', 'r', 'a', };
code UCHAR PR_CustomKey1SaveStr1[] = {30, 'C', 'h', 'a', 'v', 'e', ' ', 'P', 'e', 'r', 's', 'o', 'n', '.', ' ', '1',  ' ', 'G', 'u', 'a', 'r', 'd', 'a', 'r', ' ', 'D', 'e', 'f', 'i', 'n', '.', };
code UCHAR JA_CustomKey1SaveStr1[] = {15, 191, 31, 225, 154, ' ', 218, 21, ' ', '1',  ' ', 141, 142, 230, 231, 232, };
code UCHAR CT_CustomKey1SaveStr1[] = {10, 2, 220, 212, ' ', '1', ' ', 221, 222, 147, 133, };
code UCHAR CS_CustomKey1SaveStr1[] = {11, 2, 133, 134, 211, ' ', '1',  ' ', 220, 221, 145, 13, };

code UCHAR EN_CustomKey2SaveStr1[] = {26, 'C', 'u', 's', 't', 'o', 'm', ' ', 'k', 'e', 'y', ' ', '2',' ','S', 'a', 'v', 'e', ' ', 'S', 'e', 't', 't', 'i', 'n', 'g', 's', };
code UCHAR FR_CustomKey2SaveStr1[] = {30, 'T', 'o', 'u', 'c', 'h', 'e', ' ', 'p', 'e', 'r', 's', 'o', ' ', '2', ' ', 'E', 'n', 'r', 'e', 'g', '.', ' ', 'R', 2, 'g', 'l', 'a', 'g', 'e', 's',};
code UCHAR GE_CustomKey2SaveStr1[] = {33, 'B', 'e', 'n', 'u', 't', 'z', 'e', 'r', '-', 'T', 'a', 's', 't', 'e', ' ', '2', ' ', 'E', 'i', 'n', 's', 't', '.', ' ', 'S', 'p', 'e', 'i', 'c', 'h', 'e', 'r', 'n',};
code UCHAR IT_CustomKey2SaveStr1[] = {38, 'T', 'a', 's', 't', 'o', ' ', 'p', 'e', 'r', 's', 'o', 'n', 'a', 'l', 'i', 'z', 'z', ' ', '2', ' ','S', 'a', 'l', 'v', 'a', ' ', 'I', 'm', 'p', 'o', 's', 't', 'a', 'z', 'i', 'o', 'n', 'i',};
code UCHAR SP_CustomKey2SaveStr1[] = {35, 'T', 'e', 'c', 'l', 'a', ' ', 'p', 'e', 'r', 's', 'o', 'n', 'a', 'l', 'i', 'z', '.', ' ', '2', ' ', 'G', 'u', 'a', 'r', 'd', 'a', 'r', ' ', 'A', 'j', 'u', 's', 't', 'e', 's',};
code UCHAR PO_CustomKey2SaveStr1[] = {37, 'P', 'r', 'z', 'y', 'c', 'i', 's', 'k', ' ', 'n', 'i', 'e', 's', 't', 'a', 'n', '.', ' ', '2', ' ','Z', 'a', 'p', 'i', 's', 'z', ' ', 'U', 's', 't', 'a', 'w', 'i', 'e', 'n', 'i', 'a',};
code UCHAR CZ_CustomKey2SaveStr1[] = {34, 'V', 'l', 'a', 's', 't', 'n', 1, ' ', 'k', 'l', 0, 'v', 'e', 's', 'a', ' ', '2',  ' ', 'U', 'l', 'o', 26, 'i', 't', ' ', 'N', 'a', 's', 't', 'a', 'v', 'e', 'n', 1, };
code UCHAR MA_CustomKey2SaveStr1[] ={30, 'E', 'g', 'y', 2, 'n', 'i', ' ', 'k', 'u', 'l', 'c', 's', ' ', '2',  ' ', 'B', 'e', 0, 'l', 'l', 1, 't', 0, 's', 'm', 'e', 'n', 't', 2, 's', };
code UCHAR SE_CustomKey2SaveStr1[] = {34, 'K', 'o', 'r', 'i', 's', 'n', 'i', 6, 'k', 'a', ' ', 't', 'i', 'p', 'k', 'a', ' ', '2',  ' ', 'S', 'p', 'r', 'e', 'm', 'i', ' ', 'P', 'o', 's', 't', 'a', 'v', 'k', 'e', };
code UCHAR RO_CustomKey2SaveStr1[] = {34, 'T', 'a', 's', 't', 125, ' ', 'p', 'e', 'r', 's', 'o', 'n', 'a', 'l', 'i', 'z', '.', ' ', '2',  ' ', 'S', 'a', 'l', 'v', 'a', 'r', 'e', ' ', 'S', 'e', 't', 125, 'r', 'i', };
code UCHAR DU_CustomKey2SaveStr1[] ={31, 'A', 'a', 'n', 'g', 'e', 'p', 'a', 's', 't', 'e', ' ', 't', 'o', 'e', 't', 's', ' ', '2',  ' ', 'I', 'n', 's', 't', ' ', 'O', 'p', 's', 'l', 'a', 'a', 'n', };
code UCHAR RU_CustomKey2SaveStr1[] = {32, 153, 144, 136, 126, 148, 143, ' ', '"', 167, 136, 127, 155, 141, 136, 131, '.', '"', ' ', '2', ' ', 164, 136, 138, 133, '.', ' ', 144, 143, 125, 132, 133, '.', };
code UCHAR SW_CustomKey2SaveStr1[] = {22, 'A', 'n', 'p', 'a', 's', 's', 'a', 'd', ' ', 'k', 'n', 'a', 'p', 'p', ' ', '2', ' ','S', 'p', 'a', 'r', 'a', };
code UCHAR PR_CustomKey2SaveStr1[] = {30, 'C', 'h', 'a', 'v', 'e', ' ', 'P', 'e', 'r', 's', 'o', 'n', '.', ' ', '2',  ' ', 'G', 'u', 'a', 'r', 'd', 'a', 'r', ' ', 'D', 'e', 'f', 'i', 'n', '.', };
code UCHAR JA_CustomKey2SaveStr1[] = {15, 191, 31, 225, 154, ' ', 218, 21, ' ', '2',  ' ', 141, 142, 230, 231, 232, };
code UCHAR CT_CustomKey2SaveStr1[] ={10, 2, 220, 212, ' ', '2', ' ', 221, 222, 147, 133, };
code UCHAR CS_CustomKey2SaveStr1[] ={11, 2, 133, 134, 211, ' ', '2',  ' ', 220, 221, 145, 13, };
 
code UCHAR EN_CustomKey3SaveStr1[] = {26, 'C', 'u', 's', 't', 'o', 'm', ' ', 'k', 'e', 'y', ' ', '3',' ','S', 'a', 'v', 'e', ' ', 'S', 'e', 't', 't', 'i', 'n', 'g', 's', };
code UCHAR FR_CustomKey3SaveStr1[] = {30, 'T', 'o', 'u', 'c', 'h', 'e', ' ', 'p', 'e', 'r', 's', 'o', ' ', '3', ' ', 'E', 'n', 'r', 'e', 'g', '.', ' ', 'R', 2, 'g', 'l', 'a', 'g', 'e', 's',};
code UCHAR GE_CustomKey3SaveStr1[] = {33, 'B', 'e', 'n', 'u', 't', 'z', 'e', 'r', '-', 'T', 'a', 's', 't', 'e', ' ', '3', ' ', 'E', 'i', 'n', 's', 't', '.', ' ', 'S', 'p', 'e', 'i', 'c', 'h', 'e', 'r', 'n',};
code UCHAR IT_CustomKey3SaveStr1[] = {38, 'T', 'a', 's', 't', 'o', ' ', 'p', 'e', 'r', 's', 'o', 'n', 'a', 'l', 'i', 'z', 'z', ' ', '3', ' ','S', 'a', 'l', 'v', 'a', ' ', 'I', 'm', 'p', 'o', 's', 't', 'a', 'z', 'i', 'o', 'n', 'i',};
code UCHAR SP_CustomKey3SaveStr1[] = {35, 'T', 'e', 'c', 'l', 'a', ' ', 'p', 'e', 'r', 's', 'o', 'n', 'a', 'l', 'i', 'z', '.', ' ', '3', ' ', 'G', 'u', 'a', 'r', 'd', 'a', 'r', ' ', 'A', 'j', 'u', 's', 't', 'e', 's',};
code UCHAR PO_CustomKey3SaveStr1[] = {37, 'P', 'r', 'z', 'y', 'c', 'i', 's', 'k', ' ', 'n', 'i', 'e', 's', 't', 'a', 'n', '.', ' ', '3', ' ','Z', 'a', 'p', 'i', 's', 'z', ' ', 'U', 's', 't', 'a', 'w', 'i', 'e', 'n', 'i', 'a',};
code UCHAR CZ_CustomKey3SaveStr1[] = {34, 'V', 'l', 'a', 's', 't', 'n', 1, ' ', 'k', 'l', 0, 'v', 'e', 's', 'a', ' ', '3',  ' ', 'U', 'l', 'o', 26, 'i', 't', ' ', 'N', 'a', 's', 't', 'a', 'v', 'e', 'n', 1, };
code UCHAR MA_CustomKey3SaveStr1[] ={30, 'E', 'g', 'y', 2, 'n', 'i', ' ', 'k', 'u', 'l', 'c', 's', ' ', '3',  ' ', 'B', 'e', 0, 'l', 'l', 1, 't', 0, 's', 'm', 'e', 'n', 't', 2, 's', };
code UCHAR SE_CustomKey3SaveStr1[] = {34, 'K', 'o', 'r', 'i', 's', 'n', 'i', 6, 'k', 'a', ' ', 't', 'i', 'p', 'k', 'a', ' ', '3',  ' ', 'S', 'p', 'r', 'e', 'm', 'i', ' ', 'P', 'o', 's', 't', 'a', 'v', 'k', 'e', };
code UCHAR RO_CustomKey3SaveStr1[] = {34, 'T', 'a', 's', 't', 125, ' ', 'p', 'e', 'r', 's', 'o', 'n', 'a', 'l', 'i', 'z', '.', ' ', '3',  ' ', 'S', 'a', 'l', 'v', 'a', 'r', 'e', ' ', 'S', 'e', 't', 125, 'r', 'i', };
code UCHAR DU_CustomKey3SaveStr1[] ={31, 'A', 'a', 'n', 'g', 'e', 'p', 'a', 's', 't', 'e', ' ', 't', 'o', 'e', 't', 's', ' ', '3',  ' ', 'I', 'n', 's', 't', ' ', 'O', 'p', 's', 'l', 'a', 'a', 'n', };
code UCHAR RU_CustomKey3SaveStr1[] = {32, 153, 144, 136, 126, 148, 143, ' ', '"', 167, 136, 127, 155, 141, 136, 131, '.', '"', ' ', '3', ' ', 164, 136, 138, 133, '.', ' ', 144, 143, 125, 132, 133, '.', };
code UCHAR SW_CustomKey3SaveStr1[] = {22, 'A', 'n', 'p', 'a', 's', 's', 'a', 'd', ' ', 'k', 'n', 'a', 'p', 'p', ' ', '3', ' ','S', 'p', 'a', 'r', 'a', };
code UCHAR PR_CustomKey3SaveStr1[] = {30, 'C', 'h', 'a', 'v', 'e', ' ', 'P', 'e', 'r', 's', 'o', 'n', '.', ' ', '3',  ' ', 'G', 'u', 'a', 'r', 'd', 'a', 'r', ' ', 'D', 'e', 'f', 'i', 'n', '.', };
code UCHAR JA_CustomKey3SaveStr1[] = {15, 191, 31, 225, 154, ' ', 218, 21, ' ', '3',  ' ', 141, 142, 230, 231, 232, };
code UCHAR CT_CustomKey3SaveStr1[] = {10, 2, 220, 212, ' ', '3', ' ', 221, 222, 147, 133, };
code UCHAR CS_CustomKey3SaveStr1[] = {11, 2, 133, 134, 211, ' ', '3',  ' ', 220, 221, 145, 13, };

code UCHAR *CustomKeyTab[] = {
     EN_CustomKey1SaveStr1,
     FR_CustomKey1SaveStr1,
     GE_CustomKey1SaveStr1,
     IT_CustomKey1SaveStr1,
     SP_CustomKey1SaveStr1,
     PO_CustomKey1SaveStr1,
     CZ_CustomKey1SaveStr1,
     MA_CustomKey1SaveStr1,
     SE_CustomKey1SaveStr1,
     RO_CustomKey1SaveStr1,
     DU_CustomKey1SaveStr1,
     RU_CustomKey1SaveStr1,
     SW_CustomKey1SaveStr1,
     PR_CustomKey1SaveStr1,
     JA_CustomKey1SaveStr1,
     CT_CustomKey1SaveStr1,
     CS_CustomKey1SaveStr1,
     
     EN_CustomKey2SaveStr1,
     FR_CustomKey2SaveStr1,
     GE_CustomKey2SaveStr1,
     IT_CustomKey2SaveStr1,
     SP_CustomKey2SaveStr1,
     PO_CustomKey2SaveStr1,
     CZ_CustomKey2SaveStr1,
     MA_CustomKey2SaveStr1,
     SE_CustomKey2SaveStr1,
     RO_CustomKey2SaveStr1,
     DU_CustomKey2SaveStr1,
     RU_CustomKey2SaveStr1,
     SW_CustomKey2SaveStr1,
     PR_CustomKey2SaveStr1,
     JA_CustomKey2SaveStr1,
     CT_CustomKey2SaveStr1,
     CS_CustomKey2SaveStr1,
     
     EN_CustomKey3SaveStr1,
     FR_CustomKey3SaveStr1,
     GE_CustomKey3SaveStr1,
     IT_CustomKey3SaveStr1,
     SP_CustomKey3SaveStr1,
     PO_CustomKey3SaveStr1,
     CZ_CustomKey3SaveStr1,
     MA_CustomKey3SaveStr1,
     SE_CustomKey3SaveStr1,
     RO_CustomKey3SaveStr1,
     DU_CustomKey3SaveStr1,
     RU_CustomKey3SaveStr1,
     SW_CustomKey3SaveStr1,
     PR_CustomKey3SaveStr1,
     JA_CustomKey3SaveStr1,
     CT_CustomKey3SaveStr1,
     CS_CustomKey3SaveStr1,
};

code UCHAR EN_DialogDCRStr1[] = {26, 'A','c','t','i','v','a','t','i','n','g',' ','D','y','n','a','m','i','c','C','o','n','t','r','a','s','t', };
code UCHAR FR_DialogDCRStr1[] = {31, 'L',124,'a','c','t','i','v','a','t','i','o','n',' ','d','e',' ','D','y','n','a','m','i','c','C','o','n','t','r','a','s','t',};
code UCHAR GE_DialogDCRStr1[] = {24, 'W','e','n','n',' ','S','i','e',' ','D','y','n','a','m','i','c','C','o','n','t','r','a','s','t',};
code UCHAR IT_DialogDCRStr1[] = {25, 'A','t','t','i','v','a','n','d','o',' ','D','y','n','a','m','i','c','C','o','n','t','r','a','s','t'};
code UCHAR SP_DialogDCRStr1[] = {29, 'A','l',' ','a','c','t','i','v','a','r',' ','D','y','n','a','m','i','c','C','o','n','t','r','a','s','t',' ','s','e',};
code UCHAR PO_DialogDCRStr1[] = {28, 'U','a','k','t','y','w','n','i','e','n','i','e',' ','D','y','n','a','m','i','c','C','o','n','t','r','a','s','t',};
code UCHAR CZ_DialogDCRStr1[] = {31, 'A','k','t','i','v','a','c',1,' ','f','u','n','k','c','e',' ','D','y','n','a','m','i','c','C','o','n','t','r','a','s','t',};
code UCHAR MA_DialogDCRStr1[] = {33, 'A',' ','D','y','n','a','m','i','c','C','o','n','t','r','a','s','t',' ','b','e','k','a','p','c','s','o','l',0,'s','a','k','o','r',};
code UCHAR SE_DialogDCRStr1[] = {32, 'A','k','t','i','v','i','r','a','n','j','e',' ','d','i','n','a','m','i', 6,'k','o','g',' ','k','o','n','t','r','a','s','t','a',};
code UCHAR RO_DialogDCRStr1[] = {28, 'A','c','t','i','v','a','r','e','a',' ','D','y','n','a','m','i','c','C','o','n','t','r','a','s','t',' ','v','a', };
code UCHAR DU_DialogDCRStr1[] = {29, 'A','c','t','i','v','e','r','e','n',' ','v','a','n',' ','D','y','n','a','m','i','c','C','o','n','t','r','a','s','t',};
code UCHAR RU_DialogDCRStr1[] = {25, 137,148,127,174,147,128,144,124,128,' ','D','y','n','a','m','i','c','C','o','n','t','r','a','s','t',};
code UCHAR SW_DialogDCRStr1[] = {29, 'A','k','t','i','v','e','r','i','n','g',' ','a','v',' ','D','y','n','a','m','i','c','C','o','n','t','r','a','s','t', };
code UCHAR PR_DialogDCRStr1[] = {30, 'A',' ','a','c','t','i','v','a',  7,123,'o',' ','d','o',' ','D','y','n','a','m','i','c','C','o','n','t','r','a','s','t',};
code UCHAR JA_DialogDCRStr1[] = {16, 131,132,22,133,15,134,' ',135,136,16,137,138,16,139,140,141, };
code UCHAR CT_DialogDCRStr1[] = {10, 31,123,124,125,1,126,127,128,129,130, };
code UCHAR CS_DialogDCRStr1[] = {6, 30,31,1,123,124,125, };
//UL Justin 140424
code UCHAR EN_DialogDCRStr2[] = {27,'w','i','l','l',' ','d','i','s','a','b','l','e',' ','B','r','i','g','h','t','n','e','s','s',' ','a','n','d',};
code UCHAR FR_DialogDCRStr2[] = {28,'d',2,'s','a','c','t','i','v','e','r','a',' ','l','e','s',' ','c','o','n','t','r',125,'l','e','s',' ','d','e',};
code UCHAR GE_DialogDCRStr2[] = {35,'a','k','t','i','v',46,44,' ','w','e','r','d',46,' ','E','i','n','s','t','e','l','l',46,' ','f',46,' ','H','e','l','l','i','g','k',46,};
code UCHAR IT_DialogDCRStr2[] = {32,'v','e','r','r','a','n','n','o',' ','d','i','s','a','t','t','i','v','a','t','i',' ','i',' ','c','o','n','t','r','o','l','l','i',};
code UCHAR SP_DialogDCRStr2[] = {28,'d','e','s','h','a','b','i','l','i','t','a','r',0,'n',' ','l','o','s',' ','c','o','n','t','r','o','l','e','s',};
code UCHAR PO_DialogDCRStr2[] = {28,'w','y',129,131,'c','z','y',' ','s','t','e','r','o','w','a','n','i','e',' ','j','a','s','n','o',123,'c','i',131,};
code UCHAR CZ_DialogDCRStr2[] = {23,'s','e',' ','v','y','p','n','e',' ','o','v','l',0,'d',0,'n',1,' ','p','r','v','k',129,};
code UCHAR MA_DialogDCRStr2[] = {34,'a',' ','f',  2,'n','y','e','r',123,' ',  2,'s',' ','a',' ','k','o','n','t','r','a','s','z','t',' ','k',23,'l',10,'n',' ','n','e','m',};
code UCHAR SE_DialogDCRStr2[] = {30,'i','s','k','l','j','u', 6,'u','j','e',' ','u','p','r','a','v','l','j','a','n','j','e',' ','j','a', 6,'i','n','o','m',};
code UCHAR RO_DialogDCRStr2[] = {32,'d','e','z','a','c','t','i','v','a',' ','c','o','m','e','n','z','i','l','e',' ','L','u','m','i','n','o','z','i','t','a','t','e',};
code UCHAR DU_DialogDCRStr2[] = {36,'s','c','h','a','k','e','l','t',' ','b','e','s','t','u','r','i','n','g',' ','v','a','n',' ','H','e','l','d','e','r','h','e','i','d',' ','e','n',};
code UCHAR RU_DialogDCRStr2[] = {21,126,133,124,131,128,139,128,132,' ',148,' ',136,132,148,127,174,147,128,144,124,174,};
code UCHAR SW_DialogDCRStr2[] = {24,'a','v','a','k','t','i','v','e','r','a','r',' ','k','o','n','t','r','o','l','l','e','r','n','a',};
code UCHAR PR_DialogDCRStr2[] = {30,'v','a','i',' ','d','e','s','a','c','t','i','v','a','r',' ','o','s',' ','c','o','n','t','r','o','l','o','s',' ','d','e',};
code UCHAR JA_DialogDCRStr2[] = {15,142,143,144,145,146,147,135,136,16,137,138,16,148,2,3,};
code UCHAR CT_DialogDCRStr2[] = {9,131,132,133,127,128,134,135,136,137,};
code UCHAR CS_DialogDCRStr2[] = {6,126,127,128,129,130,131,};
//UL Justin 140424
code UCHAR EN_DialogDCRStr3[] = {17,'C','o','n','t','r','a','s','t',' ','c','o','n','t','r','o','l','s'};
code UCHAR FR_DialogDCRStr3[] = {23,'L','u','m','i','n','o','s','i','t',2,' ','e','t',' ','C','o','n','t','r','a','s','t','e',};
code UCHAR GE_DialogDCRStr3[] = {19,'u','n','d',' ','K','o','n','t','r',46,' ','d','e','a','k','t','i','v',46,};
code UCHAR IT_DialogDCRStr3[] = {22,'L','u','m','i','n','o','s','i','t',123,' ','e',' ','C','o','n','t','r','a','s','t','o',};
code UCHAR SP_DialogDCRStr3[] = {21,'d','e',' ','B','r','i','l','l','o',' ','y',' ','C','o','n','t','r','a','s','t','e',};
code UCHAR PO_DialogDCRStr3[] = {13,'i',' ','k','o','n','t','r','a','s','t','e','m',46,};
code UCHAR CZ_DialogDCRStr3[] = {13,'J','a','s',' ','a',' ','K','o','n','t','r','a','s','t',};
code UCHAR MA_DialogDCRStr3[] = {14,'s','z','a','b',  0,'l','y','o','z','h','a','t',  4, 46,};
code UCHAR SE_DialogDCRStr3[] = {25,'o','s','v','j','e','t','l','j','e','n','j','a',' ','i',' ','k','o','n','t','r','a','s','t','o','m',};
code UCHAR RO_DialogDCRStr3[] = {11,123,'i',' ','C','o','n','t','r','a','s','t',};
code UCHAR DU_DialogDCRStr3[] = {13,'C','o','n','t','r','a','s','t',' ','u','i','t',46,};
code UCHAR RU_DialogDCRStr3[] = {32,156,128,134,135,127,124,133,136,131,148,124,' ',149,133,148,136,125,132,124,' ',124,' ',148,136,144,132,133,143,125,132,143,46};
code UCHAR SW_DialogDCRStr3[] = {23,'L','j','u','s','s','t','y','r','k','a',' ','o','c','h',' ','K','o','n','t','r','a','s','t',};
code UCHAR PR_DialogDCRStr3[] = {18,'B','r','i','l','h','o',' ','e',' ','C','o','n','t','r','a','s','t','e',};
code UCHAR JA_DialogDCRStr3[] = {7,143,9,149,29,30,31,150};
code UCHAR CT_DialogDCRStr3[] = {4,138,139,125,140};
code UCHAR CS_DialogDCRStr3[] = {5,124,125,130,132,133};

code UCHAR *DialogDCRTab[] = {
    EN_DialogDCRStr1,
    FR_DialogDCRStr1, 
    GE_DialogDCRStr1, 
    IT_DialogDCRStr1,
    SP_DialogDCRStr1,
    PO_DialogDCRStr1,
    CZ_DialogDCRStr1,
    MA_DialogDCRStr1,
    SE_DialogDCRStr1,
    RO_DialogDCRStr1,
    DU_DialogDCRStr1,
    RU_DialogDCRStr1,
    SW_DialogDCRStr1,
    PR_DialogDCRStr1,
    JA_DialogDCRStr1,
    CT_DialogDCRStr1,
    CS_DialogDCRStr1,
//UL Justin 140424
    EN_DialogDCRStr2,
    FR_DialogDCRStr2, 
    GE_DialogDCRStr2, 
    IT_DialogDCRStr2,
    SP_DialogDCRStr2,
    PO_DialogDCRStr2,
    CZ_DialogDCRStr2,
    MA_DialogDCRStr2,
    SE_DialogDCRStr2,
    RO_DialogDCRStr2,
    DU_DialogDCRStr2,
    RU_DialogDCRStr2,
    SW_DialogDCRStr2,
    PR_DialogDCRStr2,
    JA_DialogDCRStr2,
    CT_DialogDCRStr2,
    CS_DialogDCRStr2,
//UL Justin 140424
    EN_DialogDCRStr3,
    FR_DialogDCRStr3, 
    GE_DialogDCRStr3, 
    IT_DialogDCRStr3,
    SP_DialogDCRStr3,
    PO_DialogDCRStr3,
    CZ_DialogDCRStr3,
    MA_DialogDCRStr3,
    SE_DialogDCRStr3,
    RO_DialogDCRStr3,
    DU_DialogDCRStr3,
    RU_DialogDCRStr3,
    SW_DialogDCRStr3,
    PR_DialogDCRStr3,
    JA_DialogDCRStr3,
    CT_DialogDCRStr3,
    CS_DialogDCRStr3,
    
};
code UCHAR SenseyeOffStr1[] =  {11, 'S', 'e', 'n', 's', 'e', 'y', 'e',' ','O','f','f'};
code UCHAR SenseyeOnStr1[] =  {10, 'S', 'e', 'n', 's', 'e', 'y', 'e',' ','O','n'};
code UCHAR *SenseyeOnOffTab[] = {
    SenseyeOffStr1,
    SenseyeOnStr1,
};

