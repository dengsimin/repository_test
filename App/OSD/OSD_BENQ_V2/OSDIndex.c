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
code UCHAR AR_DisplayTab1[]={6,184,250,169,199,218,136};


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
code UCHAR AR_PictureTab1[]={6,142,168,233,182,218,136};

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
code UCHAR AR_PictureAdvancedTab1[]={11,143,223,165,211,147,222,32,142,168,233,182};

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
 code UCHAR AR_AudioTab1[]={12,172, 126,169,218,136,32,144,137,198,137,223,174};

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
code UCHAR AR_SystemTab1[]={6,220,137,195,227,218,136};

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
code UCHAR AR_ErgonomicsTab1[]={10, 'E', 'R', 'G', 'O', 'N', 'O', 'M', 'I', 'C', 'S', };

 code UCHAR EN_ECOTab1[]={3, 'E', 'C', 'O' };
 code UCHAR FR_ECOTab1[]={3, 24,'C','O'};
 code UCHAR GE_ECOTab1[]={4, 'S','P','A','R'};
 code UCHAR IT_ECOTab1[]={3, 'E','C','O'};
 code UCHAR SP_ECOTab1[]={3, 'E','C','O'};
 code UCHAR PO_ECOTab1[]={3, 'E','K','O'};
 code UCHAR CZ_ECOTab1[]={3, 'E','K','O'};
 code UCHAR MA_ECOTab1[]={9, 'T','a','k','a','r',2,'k','o','s'};
 code UCHAR SE_ECOTab1[]={3, 'E','C','O'};
 code UCHAR RO_ECOTab1[]={3, 'E','C','O'};
 code UCHAR DU_ECOTab1[]={3, 'E','C','O'};
 code UCHAR RU_ECOTab1[]={3, 'E','C','O'};
 code UCHAR SW_ECOTab1[]={3, 'E','k','o'};
 code UCHAR PR_ECOTab1[]={3, 'E','C','O'};
 code UCHAR JA_ECOTab1[]={3, 'E','C','O'};
 code UCHAR CT_ECOTab1[]={3, 'E','C','O'};
 code UCHAR CS_ECOTab1[]={2, 164,165};
 code UCHAR AR_ECOTab1[]={3, 'E', 'C', 'O' };
 
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
     AR_DisplayTab1,
     
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
     AR_PictureTab1,
     
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
     AR_PictureAdvancedTab1,
         
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
     AR_AudioTab1,

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
     AR_SystemTab1,
         
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
     AR_ErgonomicsTab1,
#if ENABLE_ECO_SENSOR == ON
     EN_ECOTab1,
     FR_ECOTab1,
     GE_ECOTab1,
     IT_ECOTab1,
     SP_ECOTab1,
     PO_ECOTab1,
     CZ_ECOTab1,
     MA_ECOTab1,
     SE_ECOTab1,
     RO_ECOTab1,
     DU_ECOTab1,
     RU_ECOTab1,
     SW_ECOTab1,
     PR_ECOTab1,
     JA_ECOTab1,
     CT_ECOTab1,
     CS_ECOTab1,
     AR_ECOTab1,
#endif     
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
code UCHAR AR_AutoAdjustmentStr1[] = {15, 'A', 'u', 't', 'o', ' ', 'A', 'd', 'j', 'u', 's', 't', 'm', 'e', 'n', 't', };

#if ENABLE_AUTO_POVIT_FUNC == ON  
code UCHAR EN_AutoPivotStr1[]={10, 'A','u','t','o',32,'P','i','v','o','t'};
code UCHAR FR_AutoPivotStr1[]={13, 'R','o','t','a','t','i','o','n',32,'a','u','t','o'};
code UCHAR GE_AutoPivotStr1[]={14, 'A','u','t','o','m',46,32,'D','r','e','h','u','n','g'};
code UCHAR IT_AutoPivotStr1[]={20, 'R','o','t','a','z','i','o','n','e',32,'a','u','t','o','m','a','t','i','c','a'};
code UCHAR SP_AutoPivotStr1[]={19, 'R','o','t','a','c','i',4,'n',32,'a','u','t','o','m',0,'t','i','c','a'};
code UCHAR PO_AutoPivotStr1[]={15, 'A','u','t','o',46,32,'O','b','r','a','c','a','n','i','e'};
code UCHAR CZ_AutoPivotStr1[]={14, 'A','u','t','o','m',46,32,'O','t','o',6,'e','n',1};
code UCHAR MA_AutoPivotStr1[]={16, 'A','u','t','o',46,32,'E','l','f','o','r','g','a','t',0,'s'};
code UCHAR SE_AutoPivotStr1[]={14,'A','u','t',46,32,'o','k','r','e','t','a','n','j','e'};
code UCHAR RO_AutoPivotStr1[]={15, 'P','i','v','o','t','a','r','e',32,'a','u','t','o','m',46};
code UCHAR DU_AutoPivotStr1[]={12, 'A','u','t','o',45,'d','r','a','a','i','e','n'};
code UCHAR RU_AutoPivotStr1[]={11, 'A',131,132,136,126,136,131,136,133,136,132};
code UCHAR SW_AutoPivotStr1[]={17, 'S','v',3,'n','g',32,'a','u','t','o','m','a','t','i','s','k','t'};
code UCHAR PR_AutoPivotStr1[]={20, 'B','a','s','e',32,'r','o','t','a','t','i','v','a',32,'a','u','t','o','m',46};
code UCHAR JA_AutoPivotStr1[]={4, 2, 3, 6, 7, };
code UCHAR CT_AutoPivotStr1[]={4, 2, 3, 6, 7, };
code UCHAR CS_AutoPivotStr1[]={4, 2, 3, 6, 7, };
code UCHAR AR_AutoPivotStr1[]={22,35,137,239,134,137,211,219,146,32,217,239,203,179,147,218,136,32,204,137,211,238,130};
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
code UCHAR AR_InputStr1[] = {5,216,137,162,164,130};

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
code UCHAR AR_HPositionStr1[] = {4, 10, 11, 12, 13, };


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
code UCHAR AR_VPositionStr1[] = {4, 14, 15, 12, 13, };


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
code UCHAR AR_PixelClockStr1[] = {4, 16, 17, 18, 19, };

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
code UCHAR AR_PhaseStr1[] = {4, 20, 12, 4, 5, };

 code UCHAR *DisplayTab[] = {
#if ENABLE_OSD_ANALOG_FUNCTION ==OFF

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
     AR_AutoPivotStr1,
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
     AR_InputStr1,

#else
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
     AR_AutoAdjustmentStr1,
     
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
     AR_AutoPivotStr1,
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
     AR_InputStr1,
     
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
     AR_HPositionStr1,
     
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
     AR_VPositionStr1,

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
     AR_PixelClockStr1,

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
     AR_PhaseStr1,
#endif
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
code UCHAR AR_BrightnessStr1[] = {6,196,233,191,175,218,136};

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
code UCHAR AR_ContrastStr1[]={7,225,238,137,141,147,218,136};

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
code UCHAR AR_SharpnessStr1[] = {5,143,165,159,218,136};

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
code UCHAR AR_GammaStr1[]={4,137,222,137,154};

code UCHAR EN_ColorTempStr1[]={17, 'C', 'o', 'l', 'o', 'r', ' ', 'T', 'e', 'm', 'p', 'e', 'r', 'a', 't', 'u', 'r', 'e', };
code UCHAR FR_ColorTempStr1[]={13, 'T', 'e', 'm', 'p', '.', ' ', 'c', 'o', 'u', 'l', 'e', 'u', 'r', };
code UCHAR GE_ColorTempStr1[]={14, 'F', 'a', 'r', 'b', 't', 'e', 'm', 'p', 'e', 'r', 'a', 't', 'u', 'r', };
code UCHAR IT_ColorTempStr1[]={11, 'T', 'e', 'm', 'p', ' ', 'c', 'o', 'l', 'o', 'r', 'e', };
code UCHAR SP_ColorTempStr1[]={17, 'T', 'e', 'm', 'p', 'e', 'r', 'a', 't', 'u', 'r', 'a', ' ', 'c', 'o', 'l', 'o', 'r', };
code UCHAR PO_ColorTempStr1[]={13, 'T', 'e', 'm', 'p', '.', ' ', 'b', 'a', 'r', 'w', 'o', 'w', 'a', };
code UCHAR CZ_ColorTempStr1[]={13, 'T', 'e', 'p', 'l', 'o', 't', 'a', ' ', 'b', 'a', 'r', 'e', 'v', };
code UCHAR MA_ColorTempStr1[]={16, 'S', 'z', 1, 'n', 'h', 123, 'm', 2, 'r', 's', 2, 'k', 'l', 'e', 't', 28, };
code UCHAR SE_ColorTempStr1[]={16, 'T', 'e', 'm', 'p', 'e', 'r', 'a', 't', 'u', 'r', 'a', ' ', 'b', 'o', 'j', 'e', };
code UCHAR RO_ColorTempStr1[]={10, 'T', 'e', 'm', 'p', '.',  ' ', 'c', 'u', 'l', '.', };
code UCHAR DU_ColorTempStr1[]={16, 'K', 'l', 'e', 'u', 'r', 't', 'e', 'm', 'p', 'e', 'r', 'a', 't', 'u', 'u', 'r', };
code UCHAR RU_ColorTempStr1[]={13, 157, 131, 128, 132, '.', ' ', 132, 128, 146, 126, '-', 133, 143, };
code UCHAR SW_ColorTempStr1[]={14, 'F', 3, 'r', 'g', 't', 'e', 'm', 'p', 'e', 'r', 'a', 't', 'u', 'r', };
code UCHAR PR_ColorTempStr1[]={18, 'T', 'e', 'm', 'p', 'e', 'r', 'a', 't', 'u', 'r', 'a', ' ', 'd', 'a', ' ', 'c', 'o', 'r', };
code UCHAR JA_ColorTempStr1[]={3, 131, 132, 124, };
code UCHAR CT_ColorTempStr1[]={2, 31, 123, };
code UCHAR CS_ColorTempStr1[]={2, 123, 124, };
code UCHAR AR_ColorTempStr1[]={20,224,233,219,218,136,32,143,165,178,32,143,154,169,164,32,172,137,239,211,222};

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
code UCHAR AR_HueStr1[] = {10,224,233,219,218,136,32,153,169,165,146};

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
code UCHAR AR_SaturationStr1[]= {16,224,233,219,218,136,32,196,137,141,178,130,32,143,154,169,164};

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
code UCHAR AR_ResetColorStr1[] ={16,224,136,233,218,243,136,32,189,141,186,32,143,164,137,198,130};

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
     AR_BrightnessStr1,
     
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
     AR_ContrastStr1,
     
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
     AR_SharpnessStr1,    
     
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
     AR_GammaStr1,
     
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
     AR_ColorTempStr1,
     
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
     AR_HueStr1,
     
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
     AR_SaturationStr1,
         
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
     AR_ResetColorStr1,

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
     EN_AMAStr1,//AR
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
code UCHAR AR_PictureModeStr1[] ={9,168,233,183,218,136,32,197,186,232};
#if 0
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
code UCHAR AR_SenseyeDemoStr1[] = {11, 'S', 'e', 'n', 's', 'e', 'y', 'e', 148, 149, 150, 151, };

#else
code UCHAR EN_DualViewStr1[] =  {9, 'D', 'u', 'a', 'l', ' ', 'V', 'i', 'e', 'w',};
code UCHAR FR_DualViewStr1[] =  {16,'A', 'f', 'f', 'i', 'c', 'h', 'a', 'g', 'e', ' ', 'd', 'o', 'u', 'b', 'l', 'e',};
code UCHAR GE_DualViewStr1[] =  {12,'D', 'u', 'a', 'l', '-', 'A', 'n', 'z', 'e', 'i', 'g', 'e',};
code UCHAR IT_DualViewStr1[] =  {17,'V', 'i', 's', 'u', 'a', 'l', 'i', 'z', 'z', '.', ' ', 'd', 'o', 'p', 'p', 'i', 'a',};
code UCHAR SP_DualViewStr1[] =  {11,'V', 'i', 's', 't', 'a', ' ', 'd', 'o', 'b', 'l', 'e',};
code UCHAR PO_DualViewStr1[] =  {14,'W', 'i', 'd', 'o', 'k', ' ', 'p', 'o', 'd', 'w',   4, 'j', 'n', 'y',};
code UCHAR CZ_DualViewStr1[] =  {17, 'D', 'v', 'o', 'j', 'i', 't',   2, ' ', 'z', 'o', 'b', 'r', 'a', 'z', 'e', 'n',1};
code UCHAR MA_DualViewStr1[] =  {12,'K', 'e', 't', 't', 123, 's', ' ', 'n',   2, 'z', 'e', 't',};
code UCHAR SE_DualViewStr1[] =  {16,'D', 'v', 'o', 's', 't', 'r', 'u', 'k', 'i', ' ', 'p', 'r', 'i', 'k', 'a', 'z',};
code UCHAR RO_DualViewStr1[] =  {12,'V', 'e', 'd', 'e', 'r', 'e', ' ', 'd', 'u', 'b', 'l',  42,};
code UCHAR DU_DualViewStr1[] =  {16,'D', 'u', 'b', 'b', 'e', 'l', 'e', ' ', 'w', 'e', 'e', 'r', 'g', 'a', 'v', 'e',};
code UCHAR RU_DualViewStr1[] =  {15,123, 131, 143,  32, 124, 141, 136, 151, 133, 143, 152, 128, 144, 124, 149};
code UCHAR SW_DualViewStr1[] =  {8, 'D', 'u', 'b', 'b', 'e', 'l', 'v', 'y',};
code UCHAR PR_DualViewStr1[] =  {18,'V', 'i', 's', 'u', 'a', 'l', 'i', 'z', 'a',   7, 123, 'o', ' ', 'D', 'u', 'p', 'l', 'a',};
code UCHAR JA_DualViewStr1[] =  {7, 152, 180, 197,  23, 151, 180,  18, };
code UCHAR CT_DualViewStr1[] =  {5, 95, 182, 183, 0, 1,};
code UCHAR CS_DualViewStr1[] =  {4, 95, 181, 0, 1, };
code UCHAR AR_DualViewStr1[] =  {10,152, 233, 164, 170, 222,  32, 184, 250, 168, 123};

#endif
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
code UCHAR CT_DynamicContrastStr1[] = {4, 3, 142, 25, 26, };
code UCHAR CS_DynamicContrastStr1[] = {5, 3, 142, 25, 26, ' ', };
code UCHAR AR_DynamicContrastStr1[] = {18,236,215,239,222,137,227,239,165,218,136,32,225,238,137,141,147,218,136};

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
code UCHAR AR_DisplayModeStr1[] ={10,185,250,169,199,218,136,32,189,223,226};

#if ENABLE_SMART_SCALING == ON
code UCHAR EN_SmartScalingStr1[] = {7, 'S', 'c', 'a', 'l', 'i', 'n', 'g'};//{13, 'S', 'm', 'a', 'r', 't', ' ', 's', 'c', 'a', 'l', 'i', 'n', 'g'};
#endif
 
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
code UCHAR AR_OverscanModeStr1[] = {8, 'O', 'v', 'e', 'r', 's', 'c', 'a', 'n', };

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
code UCHAR AR_ColorFormatStr1[] ={12,224,136,233,218,243,136,32,209,239,175,227,146};

//ULEric140423
code UCHAR EN_HDMIRGBPCRangeStr1[] = {17, 'H','D','M','I',32,'R','G','B',32,'P','C',32,'R','a','n','g','e' };
code UCHAR FR_HDMIRGBPCRangeStr1[] = {17, 'P','l','a','g','e',32,'P','C',32,'R','G','B',32,'H','D','M','I'};
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
code UCHAR AR_HDMIRGBPCRangeStr1[] ={21, 72,68,77,73,32,82,71,66,32,169,146,233,239,141,223,214,32,208,137,191,226,};

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
     AR_PictureModeStr1,
#if 0     
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
     AR_SenseyeDemoStr1,
         
#else
     EN_DualViewStr1,
     FR_DualViewStr1,
     GE_DualViewStr1,
     IT_DualViewStr1,
     SP_DualViewStr1,
     PO_DualViewStr1,
     CZ_DualViewStr1,
     MA_DualViewStr1,
     SE_DualViewStr1,
     RO_DualViewStr1,
     DU_DualViewStr1,
     RU_DualViewStr1,
     SW_DualViewStr1,
     PR_DualViewStr1,
     JA_DualViewStr1,
     CT_DualViewStr1,
     CS_DualViewStr1,
     AR_DualViewStr1,

#endif
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
     AR_DynamicContrastStr1,
     
#if MD_ENABLE_OVERSCAN == ON        

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
     AR_OverscanModeStr1,
#endif

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
     AR_DisplayModeStr1,

#if ENABLE_SMART_SCALING == ON
     EN_SmartScalingStr1,
     EN_SmartScalingStr1,
     EN_SmartScalingStr1,
     EN_SmartScalingStr1,
     EN_SmartScalingStr1,
     EN_SmartScalingStr1,
     EN_SmartScalingStr1,
     EN_SmartScalingStr1,
     EN_SmartScalingStr1,
     EN_SmartScalingStr1,
     EN_SmartScalingStr1,
     EN_SmartScalingStr1,
     EN_SmartScalingStr1,
     EN_SmartScalingStr1,
     EN_SmartScalingStr1,
     EN_SmartScalingStr1,
     EN_SmartScalingStr1,    
     EN_SmartScalingStr1,    
#endif
#if ENABLE_COLOR_FORMAT == ON     
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
     AR_ColorFormatStr1,
#endif
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
     AR_HDMIRGBPCRangeStr1,
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
code UCHAR AR_VolumeStr1[]={11,144,233,183,218,136,32,234,233,147,175,222};

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
code UCHAR AR_MuteStr1[]={9,144,233,183,218,136,32,221,147,214};


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
 code UCHAR AR_AudioSelectStr1[]={11,144,233,183,218,136,32,165,238,165,158,146};


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
    AR_VolumeStr1,


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
    AR_MuteStr1,

#if ENABLE_AUDIO_SELECT == ON
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
    AR_AudioSelectStr1,
#endif

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
code UCHAR AR_OSDSettingsStr1[] = {18,143,178,137,179,218,136,32,189,141,186,32,144,137,164,137,165,198,130};

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
code UCHAR RU_CustomKey1Str1[] = {17, 153, 144, 136, 126, 148, 143, ' ', '"', 167, 136, 127, 155, 141, '.', '"', ' ', '1', };
code UCHAR SW_CustomKey1Str1[] = {16, 'A', 'n', 'p', 'a', 's', 's', 'a', 'd', ' ', 'k', 'n', 'a', 'p', 'p', ' ', '1', };
code UCHAR PR_CustomKey1Str1[] = {15, 'C', 'h', 'a', 'v', 'e', ' ', 'P', 'e', 'r', 's', 'o', 'n', '.', ' ', '1', };
code UCHAR JA_CustomKey1Str1[] = {9, 191, 31, 225, 154, ' ', 218, 21, ' ', '1', };
code UCHAR CT_CustomKey1Str1[] = {5, 2, 220, 212, ' ', '1', };
code UCHAR CS_CustomKey1Str1[] = {6, 2, 133, 134, 211, ' ', '1', };
code UCHAR AR_CustomKey1Str1[] = {13,49,181,251,183,163,222,32,156,137,147,207,222,32,};

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
code UCHAR RU_CustomKey2Str1[] = {17, 153, 144, 136, 126, 148, 143, ' ', '"', 167, 136, 127, 155, 141, '.', '"', ' ', '2', };
code UCHAR SW_CustomKey2Str1[] = {16, 'A', 'n', 'p', 'a', 's', 's', 'a', 'd', ' ', 'k', 'n', 'a', 'p', 'p', ' ', '2', };
code UCHAR PR_CustomKey2Str1[] = {15, 'C', 'h', 'a', 'v', 'e', ' ', 'P', 'e', 'r', 's', 'o', 'n', '.', ' ', '2', };
code UCHAR JA_CustomKey2Str1[] = {9, 191, 31, 225, 154, ' ', 218, 21, ' ', '2', };
code UCHAR CT_CustomKey2Str1[] = {5, 2, 220, 212, ' ', '2', };
code UCHAR CS_CustomKey2Str1[] = {6, 2, 133, 134, 211, ' ', '2', };
code UCHAR AR_CustomKey2Str1[] = {13,50,181,251,183,163,222,32,156,137,147,207,222,32,};
 
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
code UCHAR RU_CustomKey3Str1[] = {17, 153, 144, 136, 126, 148, 143, ' ', '"', 167, 136, 127, 155, 141, '.', '"', ' ', '3', };
code UCHAR SW_CustomKey3Str1[] = {16, 'A', 'n', 'p', 'a', 's', 's', 'a', 'd', ' ', 'k', 'n', 'a', 'p', 'p', ' ', '3', };
code UCHAR PR_CustomKey3Str1[] = {15, 'C', 'h', 'a', 'v', 'e', ' ', 'P', 'e', 'r', 's', 'o', 'n', '.', ' ', '3', };
code UCHAR JA_CustomKey3Str1[] = {9, 191, 31, 225, 154, ' ', 218, 21, ' ', '3', };
code UCHAR CT_CustomKey3Str1[] = {5, 2, 220, 212, ' ', '3', };
code UCHAR CS_CustomKey3Str1[] = {6, 2, 133, 134, 211, ' ', '3', };
code UCHAR AR_CustomKey3Str1[] = {13,51,181,251,183,163,222,32,156,137,147,207,222,32,};
code UCHAR EN_DDCCiStr1[] = {6,"DDC/CI"};
code UCHAR AR_DDCCiStr1[] = {6,"CI/DDC"};

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
code UCHAR AR_DPAutoSwitchStr1[]={17,156,137,147,207,222,32,68,80,32,236,134,137,211,219,147,218,136};


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
code UCHAR AR_HDMIAutoSwitchStr1[]={19,156,137,147,207,222,32,72,68,77,73,32,236,134,137,211,219,147,218,136};



code UCHAR EN_AutoPowerOffStr1[] = {14, 'A', 'u', 't', 'o', ' ', 'P', 'o', 'w', 'e', 'r', ' ', 'o', 'f', 'f', };
code UCHAR FR_AutoPowerOffStr1[] = {19, 'A', 'l', 'i', 'm', '.', ' ', 'a', 'u', 't', 'o', '.', ' ', 'd', 2, 's', 'a', 'c', 't', '.', };
code UCHAR GE_AutoPowerOffStr1[] = {16, 'A', 'u', 't', 'o', '-', 'A', 'b', 's', 'c', 'h', 'a', 'l', 't', 'u', 'n', 'g', };
code UCHAR IT_AutoPowerOffStr1[] = {18, 'S', 'p', 'e', 'g', 'n', 'i', 'm', 'e', 'n', 't', 'o', ' ', 'a', 'u', 't', 'o', 'm', '.', };
code UCHAR SP_AutoPowerOffStr1[] = {16, 'A', 'p', 'a', 'g', 'a', 'd', 'o', ' ', 'a', 'u', 't', 'o', 'm', 0, 't', '.', };
code UCHAR PO_AutoPowerOffStr1[] = {21, 'A', 'u', 't', 'o', 'm', '.', ' ', 'w', 'y', 129, '.', ' ', 'Z', 'a', 's', 'i', 'l', 'a', 'n', 'i', 'a', };
code UCHAR CZ_AutoPowerOffStr1[] = {12, 'A', 'u', 't', '.',  ' ', 'V', 'y', 'p', 'n', 'u', 't', 1, };
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
code UCHAR AR_AutoPowerOffStr1[] ={21, 127, 239, 134, 137, 211, 218, 146, 32, 216, 239, 203, 178, 147, 218, 136, 32, 204, 137, 211, 238, 130};

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
code UCHAR AR_ResolutionNoticeStr1[] = {11,143,211,165,218,136,32,168,137,191,162,130};

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
code UCHAR AR_InformationStr1[] ={9,144,137,222,233,219,199,223,218,136};

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
code UCHAR AR_ResetAllStr1[] ={14,217,215,218,136,32,189,141,186,32,143,164,137,198,130};

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
     AR_OSDSettingsStr1,

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
     AR_CustomKey1Str1,
         
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
     AR_CustomKey2Str1,

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
     AR_CustomKey3Str1,  
     
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
     AR_DDCCiStr1,//AR
#if ENABLE_DPHDMI_AUTO_SWITCH == ON         
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
     AR_DPAutoSwitchStr1,
#endif
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
     EN_DisplayPortStr1,//AR
#if ENABLE_DPHDMI_AUTO_SWITCH == ON         
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
     AR_HDMIAutoSwitchStr1,
#endif

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
     AR_AutoPowerOffStr1,

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
     AR_ResolutionNoticeStr1, 
     
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
     AR_InformationStr1,
     
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
     AR_ResetAllStr1,
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
code UCHAR AR_MenuStr1[] = {7,143,223,134,137,211,218,136};

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
code UCHAR AR_ExitStr1[] = {4,152,233,169,162};

//ULEric140402
code UCHAR EN_LowBlueLightStr1[]={14, 'L', 'o', 'w', ' ', 'B', 'l', 'u', 'e', ' ', 'L', 'i', 'g', 'h', 't', };
code UCHAR JA_LowBlueLightStr1[]={8,163,164,21,30,165,29,166,167}; 
code UCHAR CT_LowBlueLightStr1[]={3,153,127,154};
code UCHAR CS_LowBlueLightStr1[]={3,152,128,153};
code UCHAR AR_LowBlueLightStr1[]={14, 'L', 'o', 'w', ' ', 'B', 'l', 'u', 'e', ' ', 'L', 'i', 'g', 'h', 't', };

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
code UCHAR RU_SmartReminderStr1[]={12, 173,146,144,136,128,32,144,143,126,136,146,46 };
code UCHAR SW_SmartReminderStr1[]={16, 'S', 'm', 'a', 'r', 't', ' ', 'p', 123, 'm', 'i', 'n', 'n', 'e', 'l', 's', 'e', };
code UCHAR PR_SmartReminderStr1[]={20, 'L', 'e', 'm', 'b', 'r', 'e', 't', 'e', ' ', 'I', 'n', 't', 'e', 'l', 'i', 'g', 'e', 'n', 't', 'e', };
code UCHAR JA_SmartReminderStr1[]={6, 31, 130, 21, 29, 244, 245, };
code UCHAR CT_SmartReminderStr1[]={4, 241, 242, 179, 180, };
code UCHAR CS_SmartReminderStr1[]={4, 239, 240, 241, 242, };
code UCHAR AR_SmartReminderStr1[]={4, 239, 240, 241, 242, };

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
     AR_PictureModeStr1,
 
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
     AR_DisplayModeStr1,
     
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
     AR_BrightnessStr1,
     
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
     AR_ContrastStr1,
         
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
     AR_AutoAdjustmentStr1,
     
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
     AR_InputStr1,
     
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
     AR_VolumeStr1,

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
     AR_MuteStr1,
 
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
     AR_LowBlueLightStr1, 
     
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
     AR_SmartReminderStr1,
         
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
     AR_MenuStr1,   
     
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
     AR_ExitStr1,
 };















//Ergonomics Strings
#if ENABLE_EYE_PROTECT == ON
code UCHAR EN_EyeProtectStr1[]={11, 'E', 'y', 'e', ' ', 'P', 'r', 'o', 't', 'e', 'c', 't'};
code UCHAR FR_EyeProtectStr1[]={11,'P','r','o','t',29,'g','e',32,'V','u','e'};
code UCHAR GE_EyeProtectStr1[]={11,'A','u','g','e','n','s','c','h','u','t','z'};
code UCHAR IT_EyeProtectStr1[]={16,'P','r','o','t','e','z','i','o','n','e',32,'o','c','c','h','i'};
code UCHAR SP_EyeProtectStr1[]={18,'P','r','o','t','e','c','c','i',4,'n',32,'d','e',32,'o','j','o','s'};
code UCHAR PO_EyeProtectStr1[]={12,'O','c','h','r','o','n','a',32,'o','c','z','u'};
code UCHAR CZ_EyeProtectStr1[]={13, 'O','c','h','r','a','n','a',32,'z','r','a','k','u'};
code UCHAR MA_EyeProtectStr1[]={11, 'S','z','e','m','v',2,'d','e','l','e','m'};
code UCHAR SE_EyeProtectStr1[]={13, 'Z','a',20,'t','i','t','a',32,'o',6,'i','j','u'};
code UCHAR RO_EyeProtectStr1[]={18, 'P','r','o','t','e','j','a','r','e','a',32,'o','c','h','i','l','o','r'};
code UCHAR DU_EyeProtectStr1[]={14, 'O','o','g','b','e','s','c','h','e','r','m','i','n','g'};
code UCHAR RU_EyeProtectStr1[]={13, 175,143,163,124,132,143,32,141,133,128,144,124,149};
code UCHAR SW_EyeProtectStr1[]={9, 125,'g','o','n','s','k','y','d','d'};
code UCHAR PR_EyeProtectStr1[]={16, 'P','r','o','t','e','c',7,123,'o',32,'O','c','u','l','a','r'};
code UCHAR JA_EyeProtectStr1[]={4, 242,145,231,243};
code UCHAR CT_EyeProtectStr1[]={4, 236,237,238,239};
code UCHAR CS_EyeProtectStr1[]={4, 236, 237, 220,238};
code UCHAR AR_EyeProtectStr1[]={4, 236, 237, 220,238};

code UCHAR EN_EyeProtectMeterStr1[]={17, 'E', 'y', 'e', ' ', 'P', 'r', 'o', 't', 'e', 'c', 't', ' ', 'M', 'e', 't', 'e', 'r'};
code UCHAR FR_EyeProtectMeterStr1[]={18, 'C','m','p','t','r',32,'p','r','o','t','e','c','t',46,'y','e','u','x'};
code UCHAR GE_EyeProtectMeterStr1[]={16, 'A','u','g','e','n','s','c','h','u','t','z',45,'M','e','s',46};
code UCHAR IT_EyeProtectMeterStr1[]={18, 'M','i','s','u','r',32,'p','r','o','t','e','z',32,'o','c','c','h','i'};
code UCHAR SP_EyeProtectMeterStr1[]={18, 'N','i','v','e','l',32,'p','r','o','t',46,32,'O','c','u','l','a','r'};
code UCHAR PO_EyeProtectMeterStr1[]={18, 'P','o','m','i','a','r',46,32,'o','c','h','r',46,32,'O','c','z','u'};
code UCHAR CZ_EyeProtectMeterStr1[]={18, 'M',127,124,'i',131,32,'n','a',32,'o','c','h','r',46,32,'o',131,1};
code UCHAR MA_EyeProtectMeterStr1[]={16, 'S','z','e','m','v',46,32,'m',2,'r',123,'m',125,'s','z',46};
code UCHAR SE_EyeProtectMeterStr1[]={20, 'I','n','d','i','k',46,32,'z','a',20,'t','i','t','e',32,'o',6,'i','j','u'};
code UCHAR RO_EyeProtectMeterStr1[]={19, 'I','n','d','i','c','a','t',46,32,'p','r','o','t',46,32,'O','c','h','i'};
code UCHAR DU_EyeProtectMeterStr1[]={15, 'M','e','t','e','r',32,'o','o','g','b','e','s','c','h',46};
code UCHAR RU_EyeProtectMeterStr1[]={13, 123,143,132,147,124,148,32,136,125,131,128,163,46};
code UCHAR SW_EyeProtectMeterStr1[]={16, 125,'g','o','n','s','k','y','d','d','s','m',3,'t','a','r','e'};
code UCHAR PR_EyeProtectMeterStr1[]={16, 'M','e','d',46,32,'P','r','o','t',46,32,'O','c','u','l',46};
code UCHAR JA_EyeProtectMeterStr1[]={8, 242, 145,231,243,172,21,225,21};
code UCHAR CT_EyeProtectMeterStr1[]={6, 236,237,238,239,192,240};
code UCHAR CS_EyeProtectMeterStr1[]={5, 238, 236, 173,190,210};
code UCHAR AR_EyeProtectMeterStr1[]={5, 238, 236, 173,190,210};
#endif
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
code UCHAR AR_TimeIntervalStr1[]={8, 205, 206, 206, 243, 40, 176, 226, 41, };

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
code UCHAR AR_DurationStr1[]={5, 205, 246, 40, 225, 41, };

code UCHAR *ErgonomicsTab[] = {
#if ENABLE_EYE_PROTECT == ON
     EN_EyeProtectStr1,
     FR_EyeProtectStr1,
     GE_EyeProtectStr1,
     IT_EyeProtectStr1,
     SP_EyeProtectStr1,
     PO_EyeProtectStr1,
     CZ_EyeProtectStr1,
     MA_EyeProtectStr1,
     SE_EyeProtectStr1,
     RO_EyeProtectStr1,
     DU_EyeProtectStr1,
     RU_EyeProtectStr1,
     SW_EyeProtectStr1,
     PR_EyeProtectStr1,
     JA_EyeProtectStr1,
     CT_EyeProtectStr1,
     CS_EyeProtectStr1,
     AR_EyeProtectStr1,

     EN_EyeProtectMeterStr1,
     FR_EyeProtectMeterStr1,
     GE_EyeProtectMeterStr1,
     IT_EyeProtectMeterStr1,
     SP_EyeProtectMeterStr1,
     PO_EyeProtectMeterStr1,
     CZ_EyeProtectMeterStr1,
     MA_EyeProtectMeterStr1,
     SE_EyeProtectMeterStr1,
     RO_EyeProtectMeterStr1,
     DU_EyeProtectMeterStr1,
     RU_EyeProtectMeterStr1,
     SW_EyeProtectMeterStr1,
     PR_EyeProtectMeterStr1,
     JA_EyeProtectMeterStr1,
     CT_EyeProtectMeterStr1,
     CS_EyeProtectMeterStr1,
     AR_EyeProtectMeterStr1,
#endif
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
     AR_SmartReminderStr1,

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
     AR_TimeIntervalStr1,

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
     AR_DurationStr1,

};

#if ENABLE_ECO_SENSOR == ON
code UCHAR EN_ECOSensorStr1[]={10, 'E', 'C', 'O', ' ', 'S', 'e', 'n', 's', 'o', 'r'};
code UCHAR FR_ECOSensorStr1[]={11, 'C','a','p','t','e','u','r',32,24,'C','O'};
code UCHAR GE_ECOSensorStr1[]={11, 'S','P','A','R',45,'S','e','n','s','o','r'};
code UCHAR IT_ECOSensorStr1[]={11, 'S','e','n','s','o','r','e',32,'E','C','O'};
code UCHAR SP_ECOSensorStr1[]={10, 'S','e','n','s','o','r',32,'E','C','O'};
code UCHAR PO_ECOSensorStr1[]={11, 'C','z','u','j','n','i','k',32,'E','K','O'};
code UCHAR CZ_ECOSensorStr1[]={10, 'S','n',1,'m','a',6,32,'E','K','O'};
code UCHAR MA_ECOSensorStr1[]={15, 'T','a','k','a','r',46,32,'m',4,'d',32,2,'r','z',46};
code UCHAR SE_ECOSensorStr1[]={12, 'E','C','O',32,'o','s','j','e','t','n','i','k'};
code UCHAR RO_ECOSensorStr1[]={10, 'S','e','n','z','o','r',32,'E','C','O'};
code UCHAR DU_ECOSensorStr1[]={10, 'E','C','O',45,'s','e','n','s','o','r'};
code UCHAR RU_ECOSensorStr1[]={10, 'E','C','O',45,139,143,132,147,124,148};
code UCHAR SW_ECOSensorStr1[]={10, 'E','k','o',45,'s','e','n','s','o','r'};
code UCHAR PR_ECOSensorStr1[]={10, 'S','e','n','s','o','r',32,'E','C','O'};
code UCHAR JA_ECOSensorStr1[]={8, 'E','C','O',32,147,28,169,21};
code UCHAR CT_ECOSensorStr1[]={7, 'E','C','O',32,248,249,211};
code UCHAR CS_ECOSensorStr1[]={5, 164,165,247,248,210};
code UCHAR AR_ECOSensorStr1[]={5, 164,165,247,248,210};

code UCHAR EN_ECOSensorMeterStr1[]={16, 'E', 'C', 'O', ' ', 'S', 'e', 'n', 's', 'o', 'r', ' ', 'M', 'e', 't', 'e', 'r'};
code UCHAR FR_ECOSensorMeterStr1[]={17, 'C','m','p','t','r',32,'c','a','p','t','e','u','r',32,24,'C','O'};
code UCHAR GE_ECOSensorMeterStr1[]={16, 'S','P','A','R',45,'S','e','n','s','o','r',45,'M','e','s',46};
code UCHAR IT_ECOSensorMeterStr1[]={17, 'M','i','s','u','r',32,'s','e','n','s','o','r','e',32,'E','C','O'};
code UCHAR SP_ECOSensorMeterStr1[]={18, 'M','e','d','i','d','o','r',32,'s','e','n','s','o','r',32,'E','C','O'};
code UCHAR PO_ECOSensorMeterStr1[]={20, 'L','i','c','z','n','i','k',32,'c','z','u','j','n','i','k','a',32,'E','K','O'};
code UCHAR CZ_ECOSensorMeterStr1[]={15, 'S','e','n','z',46,32,'m',127,124,'i',131,32,'E','K','O'};
code UCHAR MA_ECOSensorMeterStr1[]={14, 'E','C','O',32,'m',4,'d',32,'m',125,'s','z','e','r'};
code UCHAR SE_ECOSensorMeterStr1[]={18, 'I','n','d','i','k',46,32,'E','C','O',32,'s','e','n','z','o','r','a'};
code UCHAR RO_ECOSensorMeterStr1[]={17, 'I','n','d','i','c',46,32,'s','e','n','z','o','r',32,'E','C','O'};
code UCHAR DU_ECOSensorMeterStr1[]={15, 'E','C','O',45,'s','e','n','s','o','r','m','e','t','e','r'};
code UCHAR RU_ECOSensorMeterStr1[]={10, 139,143,132,147,124,148,32,'E','C','O'};
code UCHAR SW_ECOSensorMeterStr1[]={15, 'E','k','o','s','e','n','s','o','r','m',3,'t','a','r','e'};
code UCHAR PR_ECOSensorMeterStr1[]={16, 'M','e','d','i',46,32,'S','e','n','s','o','r',32,'E','C','O'};
code UCHAR JA_ECOSensorMeterStr1[]={8, 'E','C','O',32,248,245,249,250};
code UCHAR CT_ECOSensorMeterStr1[]={7, 250,167,248,249,211,192,240};
code UCHAR CS_ECOSensorMeterStr1[]={7, 164,165,247,248,173,190,210};
code UCHAR AR_ECOSensorMeterStr1[]={7, 164,165,247,248,173,190,210};

code UCHAR EN_SensorRangeStr1[]={12, 'S', 'e', 'n', 's', 'o', 'r',' ','R', 'a', 'n', 'g', 'e'};
code UCHAR FR_SensorRangeStr1[]={17, 'P','o','r','t',2,'e',32,'d','u',32,'C','a','p','t','e','u','r'};
code UCHAR GE_SensorRangeStr1[]={16, 'S','e','n','s','o','r','r','e','i','c','h','w','e','i','t','e'};
code UCHAR IT_SensorRangeStr1[]={15, 'P','o','r','t','a','t','a',32,'s','e','n','s','o','r','e'};
code UCHAR SP_SensorRangeStr1[]={16, 'R','a','n','g','o',32,'d','e','l',32,'s','e','n','s','o','r'};
code UCHAR PO_SensorRangeStr1[]={15, 'Z','a','s','i',128,'g',32,'c','z','u','j','n','i','k','a'};
code UCHAR CZ_SensorRangeStr1[]={14, 'R','o','z','s','a','h',32,'s','n',1,'m','a',131,'e'};
code UCHAR MA_SensorRangeStr1[]={19,24,'r','z',2,'k','e','l',123,32,'t','a','r','t','o','m',0,'n','y','a'};
code UCHAR SE_SensorRangeStr1[]={16, 'R','a','s','p','o','n',32,'o','s','j','e','t','n','i','k','a'};
code UCHAR RO_SensorRangeStr1[]={15, 'I','n','t','e','r','v','a','l',32,'s','e','n','z','o','r'};
code UCHAR DU_SensorRangeStr1[]={12, 'S','e','n','s','o','r','b','e','r','e','i','k'};										
code UCHAR RU_SensorRangeStr1[]={16,123,124,143,126,143,141,136,144,32,139,143,132,147,124,148,143};
code UCHAR SW_SensorRangeStr1[]={17, 'S','e','n','s','o','r','n','s',32,'r',3,'c','k','v','i','d','d'};
code UCHAR PR_SensorRangeStr1[]={19, 'A','m','p','l','i','t','u','d','e',32,'d','o',32,'S','e','n','s','o','r'};
code UCHAR JA_SensorRangeStr1[]={6, 147,28,169,21,193,194};
code UCHAR CT_SensorRangeStr1[]={5, 248,249,211,188,189};
code UCHAR CS_SensorRangeStr1[]={5, 247,248,210,187,188};
code UCHAR AR_SensorRangeStr1[]={5, 247,248,210,187,188};

code UCHAR *ECOTab[] = {

    EN_ECOSensorStr1,
    FR_ECOSensorStr1,
    GE_ECOSensorStr1,
    IT_ECOSensorStr1,
    SP_ECOSensorStr1,
    PO_ECOSensorStr1,
    CZ_ECOSensorStr1,
    MA_ECOSensorStr1,
    SE_ECOSensorStr1,
    RO_ECOSensorStr1,
    DU_ECOSensorStr1,
    RU_ECOSensorStr1,
    SW_ECOSensorStr1,
    PR_ECOSensorStr1,
    JA_ECOSensorStr1,
    CT_ECOSensorStr1,
    CS_ECOSensorStr1,
    AR_ECOSensorStr1,

    EN_ECOSensorMeterStr1,
    FR_ECOSensorMeterStr1,
    GE_ECOSensorMeterStr1,
    IT_ECOSensorMeterStr1,
    SP_ECOSensorMeterStr1,
    PO_ECOSensorMeterStr1,
    CZ_ECOSensorMeterStr1,
    MA_ECOSensorMeterStr1,
    SE_ECOSensorMeterStr1,
    RO_ECOSensorMeterStr1,
    DU_ECOSensorMeterStr1,
    RU_ECOSensorMeterStr1,
    SW_ECOSensorMeterStr1,
    PR_ECOSensorMeterStr1,
    JA_ECOSensorMeterStr1,
    CT_ECOSensorMeterStr1,
    CS_ECOSensorMeterStr1,
    AR_ECOSensorMeterStr1,

    EN_SensorRangeStr1,
    FR_SensorRangeStr1,
    GE_SensorRangeStr1,
    IT_SensorRangeStr1,
    SP_SensorRangeStr1,
    PO_SensorRangeStr1,
    CZ_SensorRangeStr1,
    MA_SensorRangeStr1,
    SE_SensorRangeStr1,
    RO_SensorRangeStr1,
    DU_SensorRangeStr1,
    RU_SensorRangeStr1,
    SW_SensorRangeStr1,
    PR_SensorRangeStr1,
    JA_SensorRangeStr1,
    CT_SensorRangeStr1,
    CS_SensorRangeStr1,
    AR_SensorRangeStr1,

};
#endif

#if ENABLE_ECO_SENSOR == ON
code UCHAR **Layer2StringTab[] = {DisplayTab, PictureTab, PictureAdvancedTab, AudioTab, SystemTab, ErgonomicsTab, ECOTab};
#else
code UCHAR **Layer2StringTab[] = {DisplayTab, PictureTab, PictureAdvancedTab, AudioTab, SystemTab, ErgonomicsTab};
#endif

// input
code UCHAR DSubStr1[] = {5,"D-Sub"};
code UCHAR DviStr1[] = {3,"DVI"};
code UCHAR HdmiStr1[] = {4,"HDMI"};
code UCHAR DispStr1[] = {11,"DisplayPort"};
code UCHAR MiniDispStr1[] = {16,"Mini DisplayPort"};

code UCHAR *InputTab1[] = {
#if (MD_INPUT_INTERFACE&INPUT_VGA_MASK) 
    DSubStr1,DSubStr1,DSubStr1,DSubStr1,DSubStr1,DSubStr1,DSubStr1,DSubStr1,DSubStr1,DSubStr1,DSubStr1,DSubStr1,DSubStr1,DSubStr1,DSubStr1,DSubStr1,DSubStr1,DSubStr1,
#endif
#if MODEL_INPUT_DIG0 == INPUT_SC_DVI||MODEL_INPUT_DIG1 == INPUT_SC_DVI||MODEL_INPUT_DIG2 == INPUT_SC_DVI||MODEL_INPUT_DIG3 == INPUT_SC_DVI
    DviStr1,DviStr1,DviStr1,DviStr1,DviStr1,DviStr1,DviStr1,DviStr1,DviStr1,DviStr1,DviStr1,DviStr1,DviStr1,DviStr1,DviStr1,DviStr1,DviStr1,DviStr1,
#endif
#if (MD_INPUT_INTERFACE&INPUT_DP) 
    DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,
#endif
#if MODEL_INPUT_DIG0 == INPUT_SC_HDMI||MODEL_INPUT_DIG1 == INPUT_SC_HDMI||MODEL_INPUT_DIG2 == INPUT_SC_HDMI||MODEL_INPUT_DIG3 == INPUT_SC_HDMI ||  MODEL_INPUT_DIG7 == INPUT_SC_HDMI
    HdmiStr1,HdmiStr1,HdmiStr1,HdmiStr1,HdmiStr1,HdmiStr1,HdmiStr1,HdmiStr1,HdmiStr1,HdmiStr1,HdmiStr1,HdmiStr1,HdmiStr1,HdmiStr1,HdmiStr1,HdmiStr1,HdmiStr1,HdmiStr1,
#endif   
//#if (MD_INPUT_INTERFACE&INPUT_DP) 
//    DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,DispStr1,
//#endif
#if(MD_INPUT_INTERFACE&INPUT_DP1) 
    MiniDispStr1,MiniDispStr1,MiniDispStr1,MiniDispStr1,MiniDispStr1,MiniDispStr1,MiniDispStr1,MiniDispStr1,MiniDispStr1,MiniDispStr1,MiniDispStr1,MiniDispStr1,MiniDispStr1,MiniDispStr1,MiniDispStr1,MiniDispStr1,MiniDispStr1,MiniDispStr1,
#endif
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

code UCHAR EN_Gamma1Str1[]={3, '1','.','8'};
code UCHAR EN_Gamma2Str1[]={3, '2','.','0'};
code UCHAR EN_Gamma3Str1[]={3, '2','.','2'};
code UCHAR EN_Gamma4Str1[]={3, '2','.','4'};
code UCHAR EN_Gamma5Str1[]={3, '2','.','6'};



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
code UCHAR AR_ColorTempItem1Str1[] = {4, 236, 164, 137,198};

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
code UCHAR AR_ColorTempItem2Str1[] = {15,208, 168, 170, 243, 136, 32, 224, 233, 218, 218, 32, 216, 134, 137, 222};
 
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
code UCHAR AR_ColorTempItem3Str1[] = {15,168, 222, 158, 243, 136, 32, 224, 233, 218, 218, 32, 216, 134, 137, 222};
 
code UCHAR EN_ColorTempItem4Str1[] = {11, 'U', 's', 'e', 'r', ' ', 'D', 'e', 'f', 'i', 'n', 'e', };
code UCHAR FR_ColorTempItem4Str1[] = {16, 'D', 2, 'f', '.', ' ', 'p', 'a', 'r', ' ', 'u', 't', 'i', 'l', 'i', 's', '.'};
code UCHAR GE_ColorTempItem4Str1[] = {12, 'B', 'e', 'n', 'u', 't', 'z', 'e', 'r', 'd', 'e', 'f', '.', };
code UCHAR IT_ColorTempItem4Str1[] = {15, 'D', 'e', 'f', 'i', 'n', ' ', 'd', 'a', ' ','u', 't', 'e', 'n', 't', 'e', };
code UCHAR SP_ColorTempItem4Str1[] = {16, 'D', 'e', 'f', '.', ' ', 'p', 'o', 'r', ' ', 'u', 's', 'u', 'a', 'r', 'i', 'o', };
code UCHAR PO_ColorTempItem4Str1[] = {12, 'Z', 'd', 'e', 'f', '.', ' ', 'u', 124, 'y', 't', 'k', '.', };
code UCHAR CZ_ColorTempItem4Str1[] = {10, 'U', 26, 'i', 'v', '.', ' ', 'd', 'e', 'f', '.', };
code UCHAR MA_ColorTempItem4Str1[] = {17, 'F', 'e', 'l', 'h', 'a', 's', 'z', 'n', 0, 'l', 4, 'i', ' ', 'd', 'e', 'f', '.', };
code UCHAR SE_ColorTempItem4Str1[] = {13, 'O', 'd', 'r', 'e', 123, 'u', 'j', 'e', ' ', 'k', 'o', 'r', '.',};
code UCHAR RO_ColorTempItem4Str1[] = {14, 'D', 'e', 'f', 'i', 'n', '.', ' ', 'u', 't', 'i', 'l', 'i', 'z', '.', };
code UCHAR DU_ColorTempItem4Str1[] = {14, 'G', 'e', 'b', 'r', 'u', 'i', 'k', 'e', 'r', 'i', 'n', 's', 't', '.', };
code UCHAR RU_ColorTempItem4Str1[] = {11, 162, 126, 133, '.', ' ', 126, 136, 127, 155, 141, '.',};
code UCHAR SW_ColorTempItem4Str1[] = {12, 'A', 'n', 'v', 3, 'n', 'd', 'a', 'r', 'd', 'e', 'f', '.',};
code UCHAR PR_ColorTempItem4Str1[] = {17, 'D', 'e', 'f', 'i', 'n', '.', ' ', 'U', 't', 'i', 'l', 'i', 'z', 'a', 'd', 'o', 'r', };
code UCHAR JA_ColorTempItem4Str1[] = {6, 139, 21, 140, 21, 141, 142, };
code UCHAR CT_ColorTempItem4Str1[] = {5, 130, 131, 132, 133, 134, };
code UCHAR CS_ColorTempItem4Str1[] = {4, 131, 132, 133, 134, };
code UCHAR AR_ColorTempItem4Str1[] = {14, 220, 164, 166, 146, 175, 223, 218, 136, 32, 204, 238, 168, 199, 146};
 
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
     AR_ColorTempItem1Str1,
 
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
     AR_ColorTempItem2Str1,

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
     AR_ColorTempItem3Str1,

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
     AR_ColorTempItem4Str1,
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
code UCHAR AR_AMAItem3Str1[] = {5, 220, 165, 211, 147, 222};

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
code UCHAR AR_AMAItem2Str1[] = {5, 197, 207, 146, 168, 222};

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
code UCHAR AR_AMAItem1Str1[] = {5, 204,137,211,238,130};

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
     AR_AMAItem1Str1,

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
     AR_AMAItem2Str1,
     
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
     AR_AMAItem3Str1,
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
code UCHAR AR_YesStr1[] = {3,221,199,226};

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
code UCHAR AR_NoStr1[] = {1, 247};

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
code UCHAR AR_OnStr1[] = {5,217,239,203,179,146};
 
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
code UCHAR AR_OffStr1[] = {5,204,137,211,238,130};

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
     AR_YesStr1,

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
     AR_NoStr1,
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
     AR_OnStr1,

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
     AR_OffStr1,     
};
#if ENABLE_OSD_ANALOG_FUNCTION == ON
#if ENABLE_AUTO_POVIT_FUNC == ON  
code UCHAR **SecondLevelTabOfMItem1[] = {NULL,OnOffTab1,InputTab1, NULL, NULL, NULL, NULL};
#else
code UCHAR **SecondLevelTabOfMItem1[] = {NULL,InputTab1, NULL, NULL, NULL, NULL};
#endif
#else
#if ENABLE_AUTO_POVIT_FUNC == ON  
code UCHAR **SecondLevelTabOfMItem1[] = {OnOffTab1,InputTab1};
#else
code UCHAR **SecondLevelTabOfMItem1[] = {InputTab1};
#endif

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
code UCHAR AR_StanddardStr1[] = {5,236,174,137,239,210};

#if ENABLE_PICTURE_MODE_ANIMATION == ON

code UCHAR EN_AnimationStr1[] = {9, 'A','n','i','m','a','t','i','o','n'};
code UCHAR FR_AnimationStr1[] = {9, 'A','n','i','m','a','t','i','o','n'};
code UCHAR GE_AnimationStr1[] = {9, 'A','n','i','m','a','t','i','o','n'};
code UCHAR IT_AnimationStr1[] = {10, 'A','n','i','m','a','z','i','o','n','e'};
code UCHAR SP_AnimationStr1[] = {9, 'A','n','i','m','a','c','i',4,'n'};
code UCHAR PO_AnimationStr1[] = {8, 'A','n','i','m','a','c','j','a'};
code UCHAR CZ_AnimationStr1[] = {7, 'A','n','i','m','a','c','e'};
code UCHAR MA_AnimationStr1[] = {8, 'A','n','i','m',0,'c','i',4};
code UCHAR SE_AnimationStr1[] = {9, 'A','n','i','m','a','c','i','j','a'};
code UCHAR RO_AnimationStr1[] = {8, 'A','n','i','m','a',124,'i','e'};
code UCHAR DU_AnimationStr1[] = {8, 'A','n','i','m','a','t','i','e'};
code UCHAR RU_AnimationStr1[] = {8, 130,144,124,146,143,171,124,149};
code UCHAR SW_AnimationStr1[] = {9, 'A','n','i','m','a','t','i','o','n'};
code UCHAR PR_AnimationStr1[] = {8, 'A','n','i','m','a',7,123,'o'};
code UCHAR JA_AnimationStr1[] = {4, 161, 140, 165,28};
code UCHAR CT_AnimationStr1[] = {4, 3,173,147,174};
code UCHAR CS_AnimationStr1[] = {4, 3,172,145,173};
code UCHAR AR_AnimationStr1[] = {6,143,214,169,159,218,136};

#endif

#if	ENABLE_PICTURE_MODE_CAD == ON

code UCHAR EN_CADStr1[] = {7, 'C','A','D',47,'C','A','M'};
code UCHAR FR_CADStr1[] = {7, 'C','A','O',47,'P','A','O'};
code UCHAR GE_CADStr1[] = {7, 'C','A','D',47,'C','A','M'};
code UCHAR IT_CADStr1[] = {7, 'C','A','D',47,'C','A','M'};
code UCHAR SP_CADStr1[] = {7, 'C','A','D',47,'C','A','M'};
code UCHAR PO_CADStr1[] = {7, 'C','A','D',47,'C','A','M'};
code UCHAR CZ_CADStr1[] = {7, 'C','A','D',47,'C','A','M'};
code UCHAR MA_CADStr1[] = {7, 'C','A','D',47,'C','A','M'};
code UCHAR SE_CADStr1[] = {7, 'C','A','D',47,'C','A','M'};
code UCHAR RO_CADStr1[] = {7, 'C','A','D',47,'C','A','M'};
code UCHAR DU_CADStr1[] = {7, 'C','A','D',47,'C','A','M'};
code UCHAR RU_CADStr1[] = {7, 'C','A','D',47,'C','A','M'};
code UCHAR SW_CADStr1[] = {7, 'C','A','D',47,'C','A','M'};
code UCHAR PR_CADStr1[] = {7, 'C','A','D',47,'C','A','M'};
code UCHAR JA_CADStr1[] = {7, 'C','A','D',47,'C','A','M'};
code UCHAR CT_CADStr1[] = {7, 67,65,68,47,67,65,77 };
code UCHAR CS_CADStr1[] = {7, 67,65,68,47,67,65,77};
code UCHAR AR_CADStr1[] = {7, 67,65,68,47,67,65,77};
#endif
#if	ENABLE_PRESENTATION_MODE == ON
code UCHAR EN_PresentationStr1[] = {12, 'P','r','e','s','e','n','t','a','t','i','o','n'};
code UCHAR FR_PresentationStr1[] = {12, 'P','r',2,'s','e','n','t','a','t','i','o','n'};
code UCHAR GE_PresentationStr1[] = {12, 'P','r',3,'s','e','n','t','a','t','i','o','n'};
code UCHAR IT_PresentationStr1[] = {8, 'P','r','e','s','e','n','t','e'};
code UCHAR SP_PresentationStr1[] = {12, 'P','r','e','s','e','n','t','a','c','i',4,'n'};
code UCHAR PO_PresentationStr1[] = {14, 'P','r','z','e','d','s','t','a','w','i','a','n','i','e'};
code UCHAR CZ_PresentationStr1[] = {10, 'P','r','e','z','e','n','t','a','c','e'};
code UCHAR MA_PresentationStr1[] = {11, 'P','r','e','z','e','n','t',0,'c','i',4};
code UCHAR SE_PresentationStr1[] = {12, 'P','r','e','z','e','n','t','a','c','i','j','a'};
code UCHAR RO_PresentationStr1[] = {10, 'P','r','e','z','e','n','t','a','r','e'};
code UCHAR DU_PresentationStr1[] = {11, 'P','r','e','s','e','n','t','a','t','i','e'};
code UCHAR RU_PresentationStr1[] = {11, 167,133,128,141,128,144,132,143,171,124,149};
code UCHAR SW_PresentationStr1[] = {10, 'P','r','e','s','e','n','t','e','r','a'};
code UCHAR PR_PresentationStr1[] = {12, 'A','p','r','e','s','e','n','t','a',7,123,'o'};
code UCHAR JA_PresentationStr1[] = {2, 179,0};
code UCHAR CT_PresentationStr1[] = {2, 175, 176};
code UCHAR CS_PresentationStr1[] = {2, 174,175};
code UCHAR AR_PresentationStr1[] = {2, 174,175};
#endif
#if ENABLE_PICTURE_MODE_MOVIE == ON           
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
code UCHAR AR_MovieStr1[] = {2, 165, 168, };
#endif
#if ENABLE_PICTURE_MODE_GAME == ON           
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
code UCHAR AR_GameStr1[] =  {2, 166, 167, };
#endif
#if ENABLE_PICTURE_MODE_PHOTO == ON           
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
code UCHAR AR_PhotoStr1[] = {2, 23, 24, };

#endif
#if	ENABLE_PICTURE_MODE_REC709 == ON      
code UCHAR EN_Rec709Str1[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
code UCHAR FR_Rec709Str1[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
code UCHAR GE_Rec709Str1[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
code UCHAR IT_Rec709Str1[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
code UCHAR SP_Rec709Str1[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
code UCHAR PO_Rec709Str1[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
code UCHAR CZ_Rec709Str1[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
code UCHAR MA_Rec709Str1[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
code UCHAR SE_Rec709Str1[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
code UCHAR RO_Rec709Str1[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
code UCHAR DU_Rec709Str1[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
code UCHAR RU_Rec709Str1[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
code UCHAR SW_Rec709Str1[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
code UCHAR PR_Rec709Str1[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
code UCHAR JA_Rec709Str1[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
code UCHAR CT_Rec709Str1[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
code UCHAR CS_Rec709Str1[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
code UCHAR AR_Rec709Str1[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
#endif
#if	ENABLE_PICTURE_MODE_DARKROOM == ON      
code UCHAR EN_DarkroomStr1[] = {8,  'D', 'a', 'r', 'k', 'R', 'o', 'o', 'm'};
code UCHAR FR_DarkroomStr1[] = {13, 'C', 'h', 'a', 'm', 'b', 'r', 'e', ' ', 'n', 'o', 'i', 'r', 'e',};
code UCHAR GE_DarkroomStr1[] = {12, 'D', 'u', 'n', 'k', 'e', 'l', 'k', 'a', 'm', 'm', 'e', 'r',};
code UCHAR IT_DarkroomStr1[] = {13, 'C', 'a', 'm', 'e', 'r', 'a', ' ', 'o', 's', 'c', 'u', 'r', 'a',};
code UCHAR SP_DarkroomStr1[] = {13, 'C', 'u', 'a', 'r', 't', 'o', ' ', 'o', 's', 'c', 'u', 'r', 'o',};
code UCHAR PO_DarkroomStr1[] = {7,  'C', 'i', 'e', 'm', 'n', 'i', 'a', };
code UCHAR CZ_DarkroomStr1[] = {14, 'T', 'm', 'a', 'v',  0, ' ', 'm', 1, 's', 't', 'n', 'o', 's', 't',};
code UCHAR MA_DarkroomStr1[] = {10, 'S',  10, 't', 2,  't', 'k', 'a', 'm', 'r', 'a',};
code UCHAR SE_DarkroomStr1[] = {11, 'M', 'r', 'a', 6, 'n', 'a', ' ', 's', 'o', 'b', 'a',};
code UCHAR RO_DarkroomStr1[] = {14, 'C', 'a', 'm', 'e', 'r', 42, ' ', 'o', 'b', 's', 'c', 'u', 'r', 42,};
code UCHAR DU_DarkroomStr1[] = {13, 'D', 'o', 'n', 'k', 'e', 'r', 'e', ' ', 'k', 'a', 'm', 'e', 'r',};
code UCHAR RU_DarkroomStr1[] = {14, 161, 128, 146, 144, 143, 149, 32, 148, 136, 146, 144, 143, 132, 143};
code UCHAR SW_DarkroomStr1[] = {7,  'M', 10, 'r', 'k', 'r', 'u', 'm',};
code UCHAR PR_DarkroomStr1[] = {13, 'Q', 'u', 'a', 'r', 't', 'o', ' ', 'e', 's', 'c', 'u', 'r', 'o',};
code UCHAR JA_DarkroomStr1[] = {2, 93, 95,};
code UCHAR CT_DarkroomStr1[] = {2, 60, 62, };
code UCHAR CS_DarkroomStr1[] = {2, 92, 93, };
code UCHAR AR_DarkroomStr1[] = {10,143,223,219,195,222,32,143,206,169,202};

#endif

code UCHAR EN_sRGBStr1[] = {4,"sRGB"};


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

code UCHAR EN_EcoStr1[] = {3, 'E', 'C', 'O', };
code UCHAR FR_EcoStr1[] = {3, 24, 'C', 'O', };
code UCHAR GE_EcoStr1[] = {4, 'S', 'P', 'A', 'R', };
code UCHAR IT_EcoStr1[] = {3, 'E', 'C', 'O', };
code UCHAR SP_EcoStr1[] = {3, 'E', 'C', 'O', };
code UCHAR PO_EcoStr1[] = {3, 'E', 'K', 'O', };
code UCHAR CZ_EcoStr1[] = {3, 'E', 'K', 'O', };
code UCHAR MA_EcoStr1[] = {9, 'T', 'a', 'k', 'a', 'r', 2, 'k', 'o', 's', };
code UCHAR SE_EcoStr1[] = {3, 'E', 'C', 'O', };
code UCHAR RO_EcoStr1[] = {3, 'E', 'C', 'O', };
code UCHAR DU_EcoStr1[] = {3, 'E', 'C', 'O', };
code UCHAR RU_EcoStr1[] = {3, 'E', 'C', 'O', };
code UCHAR SW_EcoStr1[] = {3, 'E', 'K', 'O', };
code UCHAR PR_EcoStr1[] = {3, 'E', 'C', 'O', };
code UCHAR JA_EcoStr1[] = {2, 173, 27, };
code UCHAR CT_EcoStr1[] = {3, 'E', 'C', 'O', };
code UCHAR CS_EcoStr1[] = {2, 164, 165, };
code UCHAR AR_EcoStr1[] = {4,143,135,239,140};

code UCHAR EN_MbookStr1[] = {6, 'M', 45, 'b', 'o', 'o', 'k', };
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
code UCHAR AR_UserStr1[] = {8,220,165,162,147,175,223,218,136};

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
         AR_StanddardStr1,
#if ENABLE_PICTURE_MODE_REC709 == ON     
        EN_Rec709Str1,
        FR_Rec709Str1,
        GE_Rec709Str1,
        IT_Rec709Str1,
        SP_Rec709Str1,
        PO_Rec709Str1,
        CZ_Rec709Str1,
        MA_Rec709Str1,
        SE_Rec709Str1,
        RO_Rec709Str1,
        DU_Rec709Str1,
        RU_Rec709Str1,
        SW_Rec709Str1,
        PR_Rec709Str1,
        JA_Rec709Str1,
        CT_Rec709Str1,
        CS_Rec709Str1,
        AR_Rec709Str1,
#endif     
    
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
     EN_sRGBStr1,//AR

#if	ENABLE_PICTURE_MODE_CAD == ON
    EN_CADStr1,
    FR_CADStr1,
    GE_CADStr1,
    IT_CADStr1,
    SP_CADStr1,
    PO_CADStr1,
    CZ_CADStr1,
    MA_CADStr1,
    SE_CADStr1,
    RO_CADStr1,
    DU_CADStr1,
    RU_CADStr1,
    SW_CADStr1,
    PR_CADStr1,
    JA_CADStr1,
    CT_CADStr1,
    CS_CADStr1,
    AR_CADStr1,
#endif
#if ENABLE_PICTURE_MODE_ANIMATION == ON
    EN_AnimationStr1,
    FR_AnimationStr1,
    GE_AnimationStr1,
    IT_AnimationStr1,
    SP_AnimationStr1,
    PO_AnimationStr1,
    CZ_AnimationStr1,
    MA_AnimationStr1,
    SE_AnimationStr1,
    RO_AnimationStr1,
    DU_AnimationStr1,
    RU_AnimationStr1,
    SW_AnimationStr1,
    PR_AnimationStr1,
    JA_AnimationStr1,
    CT_AnimationStr1,
    CS_AnimationStr1,
    AR_AnimationStr1,
#endif
#if	ENABLE_PRESENTATION_MODE == ON
    EN_PresentationStr1,
    FR_PresentationStr1,
    GE_PresentationStr1,
    IT_PresentationStr1,
    SP_PresentationStr1,
    PO_PresentationStr1,
    CZ_PresentationStr1,
    MA_PresentationStr1,
    SE_PresentationStr1,
    RO_PresentationStr1,
    DU_PresentationStr1,
    RU_PresentationStr1,
    SW_PresentationStr1,
    PR_PresentationStr1,
    JA_PresentationStr1,
    CT_PresentationStr1,
    CS_PresentationStr1,
    AR_PresentationStr1,
#endif
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
     AR_LowBlueLightStr1, 
#if ENABLE_PICTURE_MODE_MOVIE == ON              
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
     AR_MovieStr1,
#endif
#if ENABLE_PICTURE_MODE_GAME == ON
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
     AR_GameStr1,
#endif
#if ENABLE_PICTURE_MODE_PHOTO == ON
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
     AR_PhotoStr1,
#endif
#if	ENABLE_PICTURE_MODE_DARKROOM == ON     
    EN_DarkroomStr1,
    FR_DarkroomStr1,
    GE_DarkroomStr1,
    IT_DarkroomStr1,
    SP_DarkroomStr1,
    PO_DarkroomStr1,
    CZ_DarkroomStr1,
    MA_DarkroomStr1,
    SE_DarkroomStr1,
    RO_DarkroomStr1,
    DU_DarkroomStr1,
    RU_DarkroomStr1,
    SW_DarkroomStr1,
    PR_DarkroomStr1,
    JA_DarkroomStr1,
    CT_DarkroomStr1,
    CS_DarkroomStr1,
    AR_DarkroomStr1,
#endif     
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
     AR_EcoStr1,
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
     EN_MbookStr1,//AR
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
     AR_UserStr1,
};
code UCHAR EN_OnOffStr1[] = {6, 'O', 'N', '/', 'O', 'F', 'F', };
code UCHAR FR_OnOffStr1[] = {14, 'A', 'C', 'T', 'I', 'V', 24, '/', 'D', 24, 'S', 'A', 'C', 'T', ' ', };
code UCHAR GE_OnOffStr1[] = {7, 'E', 'I', 'N', '/', 'A', 'U', 'S',};
code UCHAR IT_OnOffStr1[] = {18, 'A', 'T', 'T', 'I', 'V', 'A', 'T', 'O', '/', 'D', 'I', 'S', 'A', 'T', 'T', 'I', 'V', '.',};
code UCHAR SP_OnOffStr1[] = {15, 'A', 'C', 'T', 'I', 'V', 'A', 'R', '/', 'D', 'E', 'S', 'A', 'C', 'T', '.',};
code UCHAR PO_OnOffStr1[] = {16, 'W', 'L', 126, 'C', 'Z', 'O', 'N', 'Y', '/', 'W', 'Y', 125, 126, 'C', 'Z', '.', };
code UCHAR CZ_OnOffStr1[] = {9, 'Z', 'A', 'P', '.', '/', 'V', 'Y', 'P', '.', };
code UCHAR MA_OnOffStr1[] = {5, 'B', 'E', '/', 'K', 'I', };
code UCHAR SE_OnOffStr1[] = {12, 'U', 'K', 'L', 'J', '.', '/', 'I', 'S', 'K', 'L', 'J', '.',};
code UCHAR RO_OnOffStr1[] = {12, 'P', 'O', 'R', 'N', 'I', 'T', '/', 'O', 'P', 'R', 'I', 'T', };
code UCHAR DU_OnOffStr1[] = {7, 'A', 'A', 'N', '/', 'U', 'I', 'T', };
code UCHAR RU_OnOffStr1[] = {10, 137, 153, 166, '.', '/', 137, 165, 153, 166, '.', };
code UCHAR SW_OnOffStr1[] = {5, 'P', 124, '/', 'A', 'V', };
code UCHAR PR_OnOffStr1[] = {14, 'L', 'i', 'g', 'a', 'r', '/', 'D', 'e', 's', 'l', 'i', 'g', 'a', 'r',};
code UCHAR JA_OnOffStr1[] = {5, 149, 28, '/', 149, 19,};
code UCHAR CT_OnOffStr1[] = {5, 228, 229, '/', 138, 139,};
code UCHAR CS_OnOffStr1[] = {5, 227, 228, '/', 138, 139, };
code UCHAR AR_OnOffStr1[] = {11,217,239,203,179,146,'/',204,137,211,238,130};

code UCHAR *DualViewTab1[] = {     
EN_OnOffStr1,
FR_OnOffStr1,
GE_OnOffStr1,
IT_OnOffStr1,
SP_OnOffStr1,
PO_OnOffStr1,
CZ_OnOffStr1,
MA_OnOffStr1,
SE_OnOffStr1,
RO_OnOffStr1,
DU_OnOffStr1,
RU_OnOffStr1,
SW_OnOffStr1,
PR_OnOffStr1,
JA_OnOffStr1,
CT_OnOffStr1,
CS_OnOffStr1,
AR_OnOffStr1,    
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
     EN_sRGBStr1,//AR

#if	ENABLE_PICTURE_MODE_CAD == ON
    EN_CADStr1,
    FR_CADStr1,
    GE_CADStr1,
    IT_CADStr1,
    SP_CADStr1,
    PO_CADStr1,
    CZ_CADStr1,
    MA_CADStr1,
    SE_CADStr1,
    RO_CADStr1,
    DU_CADStr1,
    RU_CADStr1,
    SW_CADStr1,
    PR_CADStr1,
    JA_CADStr1,
    CT_CADStr1,
    CS_CADStr1,
    AR_CADStr1,
#endif
#if ENABLE_PICTURE_MODE_ANIMATION == ON
    EN_AnimationStr1,
    FR_AnimationStr1,
    GE_AnimationStr1,
    IT_AnimationStr1,
    SP_AnimationStr1,
    PO_AnimationStr1,
    CZ_AnimationStr1,
    MA_AnimationStr1,
    SE_AnimationStr1,
    RO_AnimationStr1,
    DU_AnimationStr1,
    RU_AnimationStr1,
    SW_AnimationStr1,
    PR_AnimationStr1,
    JA_AnimationStr1,
    CT_AnimationStr1,
    CS_AnimationStr1,
    AR_AnimationStr1,
#endif    
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
     AR_LowBlueLightStr1,
#if	ENABLE_PICTURE_MODE_DARKROOM == ON     
    EN_DarkroomStr1,
    FR_DarkroomStr1,
    GE_DarkroomStr1,
    IT_DarkroomStr1,
    SP_DarkroomStr1,
    PO_DarkroomStr1,
    CZ_DarkroomStr1,
    MA_DarkroomStr1,
    SE_DarkroomStr1,
    RO_DarkroomStr1,
    DU_DarkroomStr1,
    RU_DarkroomStr1,
    SW_DarkroomStr1,
    PR_DarkroomStr1,
    JA_DarkroomStr1,
    CT_DarkroomStr1,
    CS_DarkroomStr1,
    AR_DarkroomStr1,
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
     AR_UserStr1,
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
code UCHAR AR_1TO1Str1[] = {3, 49,58,49};

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
code UCHAR AR_FullStr1[] = {4,217,222,137,214};

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
code UCHAR AR_AspectStr1[] = {10,164,137,199,140,126,32,143,141,175,226};

#if ENABLE_MORE_DISPLAY_MODE == ON
code UCHAR EN_19inchStr1[] = {3, 49,57,34};
code UCHAR FR_19inchStr1[] = {3, 49,57,34};
code UCHAR GE_19inchStr1[] = {3, 49,57,34};
code UCHAR IT_19inchStr1[] = {3, 49,57,34};
code UCHAR SP_19inchStr1[] = {3, 49,57,34};
code UCHAR PO_19inchStr1[] = {3, 49,57,34};
code UCHAR CZ_19inchStr1[] = {3, 49,57,34};
code UCHAR MA_19inchStr1[] = {3, 49,57,34};
code UCHAR SE_19inchStr1[] = {3, 49,57,34};
code UCHAR RO_19inchStr1[] = {3, 49,57,34};
code UCHAR DU_19inchStr1[] = {3, 49,57,34};
code UCHAR RU_19inchStr1[] = {3, 49,57,34};
code UCHAR SW_19inchStr1[] = {3, 49,57,34};
code UCHAR PR_19inchStr1[] = {3, 49,57,34};
code UCHAR JA_19inchStr1[] = {3, 49,57,34};
code UCHAR CT_19inchStr1[] = {3, 49,57,34};
code UCHAR CS_19inchStr1[] = {3, 49,57,34};
code UCHAR AR_19inchStr1[] = {3, 49,57,34};

code UCHAR EN_22inchStr1[] = {3, 50,50,34};
code UCHAR FR_22inchStr1[] = {3, 50,50,34};
code UCHAR GE_22inchStr1[] = {3, 50,50,34};
code UCHAR IT_22inchStr1[] = {3, 50,50,34};
code UCHAR SP_22inchStr1[] = {3, 50,50,34};
code UCHAR PO_22inchStr1[] = {3, 50,50,34};
code UCHAR CZ_22inchStr1[] = {3, 50,50,34};
code UCHAR MA_22inchStr1[] = {3, 50,50,34};
code UCHAR SE_22inchStr1[] = {3, 50,50,34};
code UCHAR RO_22inchStr1[] = {3, 50,50,34};
code UCHAR DU_22inchStr1[] = {3, 50,50,34};
code UCHAR RU_22inchStr1[] = {3, 50,50,34};
code UCHAR SW_22inchStr1[] = {3, 50,50,34};
code UCHAR PR_22inchStr1[] = {3, 50,50,34};
code UCHAR JA_22inchStr1[] = {3, 50,50,34};
code UCHAR CT_22inchStr1[] = {3, 50,50,34};
code UCHAR CS_22inchStr1[] = {3, 50,50,34};
code UCHAR AR_22inchStr1[] = {3, 50,50,34};

code UCHAR EN_23inchStr1[] = {3, 50,51,34};
code UCHAR FR_23inchStr1[] = {3, 50,51,34};
code UCHAR GE_23inchStr1[] = {3, 50,51,34};
code UCHAR IT_23inchStr1[] = {3, 50,51,34};
code UCHAR SP_23inchStr1[] = {3, 50,51,34};
code UCHAR PO_23inchStr1[] = {3, 50,51,34};
code UCHAR CZ_23inchStr1[] = {3, 50,51,34};
code UCHAR MA_23inchStr1[] = {3, 50,51,34};
code UCHAR SE_23inchStr1[] = {3, 50,51,34};
code UCHAR RO_23inchStr1[] = {3, 50,51,34};
code UCHAR DU_23inchStr1[] = {3, 50,51,34};
code UCHAR RU_23inchStr1[] = {3, 50,51,34};
code UCHAR SW_23inchStr1[] = {3, 50,51,34};
code UCHAR PR_23inchStr1[] = {3, 50,51,34};
code UCHAR JA_23inchStr1[] = {3, 50,51,34};
code UCHAR CT_23inchStr1[] = {3, 50,51,34};
code UCHAR CS_23inchStr1[] = {3, 50,51,34};
code UCHAR AR_23inchStr1[] = {3, 50,51,34};

#endif
 
code UCHAR *FullAspectTab1[] = {     
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
     AR_FullStr1,
     
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
     AR_AspectStr1,
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
         AR_1TO1Str1,     
#if ENABLE_MORE_DISPLAY_MODE == ON
    EN_19inchStr1,
    FR_19inchStr1,
    GE_19inchStr1,
    IT_19inchStr1,
    SP_19inchStr1,
    PO_19inchStr1,
    CZ_19inchStr1,
    MA_19inchStr1,
    SE_19inchStr1,
    RO_19inchStr1,
    DU_19inchStr1,
    RU_19inchStr1,
    SW_19inchStr1,
    PR_19inchStr1,
    JA_19inchStr1,
    CT_19inchStr1,
    CS_19inchStr1,
    AR_19inchStr1,
    
    EN_22inchStr1,
    FR_22inchStr1,
    GE_22inchStr1,
    IT_22inchStr1,
    SP_22inchStr1,
    PO_22inchStr1,
    CZ_22inchStr1,
    MA_22inchStr1,
    SE_22inchStr1,
    RO_22inchStr1,
    DU_22inchStr1,
    RU_22inchStr1,
    SW_22inchStr1,
    PR_22inchStr1,
    JA_22inchStr1,
    CT_22inchStr1,
    CS_22inchStr1,
    AR_22inchStr1,

    EN_23inchStr1,
    FR_23inchStr1,
    GE_23inchStr1,
    IT_23inchStr1,
    SP_23inchStr1,
    PO_23inchStr1,
    CZ_23inchStr1,
    MA_23inchStr1,
    SE_23inchStr1,
    RO_23inchStr1,
    DU_23inchStr1,
    RU_23inchStr1,
    SW_23inchStr1,
    PR_23inchStr1,
    JA_23inchStr1,
    CT_23inchStr1,
    CS_23inchStr1,
    AR_23inchStr1,
#endif
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
code UCHAR EN_AUTOStr1[] = {11, "Auto Detect"};
code UCHAR FR_AUTOStr1[] = {10, 'D', 2, 't', 'e', 'c', ' ', 'a', 'u', 't', 'o',};
code UCHAR GE_AUTOStr1[] = {9, "Aut. Erk."};
code UCHAR IT_AUTOStr1[] = {10,"Rilev auto"};
code UCHAR SP_AUTOStr1[] = {10,"Dete autom"};
code UCHAR PO_AUTOStr1[] = {4, "Auto"};
code UCHAR CZ_AUTOStr1[] = {10,"Autom.det."};
code UCHAR MA_AUTOStr1[] = {10,"Auto felis"};
code UCHAR SE_AUTOStr1[] = {10,"Aut.detek."};
code UCHAR RO_AUTOStr1[] = {9, "Det. Auto"};
code UCHAR DU_AUTOStr1[] = {10,"Autodetec."};
code UCHAR RU_AUTOStr1[] = {10,130, 131, 132, 136, 136, 126, 133, 128, 139,'.'};
code UCHAR SW_AUTOStr1[] = {15,"Autodetektering"};
code UCHAR PR_AUTOStr1[] = {10,"Detec auto"};
code UCHAR JA_AUTOStr1[] = {4,2,3,203,204};
code UCHAR CT_AUTOStr1[] = {4,2,3,197,198};
code UCHAR CS_AUTOStr1[] = {4,2,3,196,197};
code UCHAR AR_AUTOStr1[] = {13, 237,134,137,203,218,146,32,204,137,179,151,214,136};

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
     EN_RGBStr1,//AR
     
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
     EN_YUVStr1,//AR
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
    EN_AUTOStr1,
    FR_AUTOStr1,
    GE_AUTOStr1,
    IT_AUTOStr1,
    SP_AUTOStr1,
    PO_AUTOStr1,
    CZ_AUTOStr1,
    MA_AUTOStr1,
    SE_AUTOStr1,
    RO_AUTOStr1,
    DU_AUTOStr1,
    RU_AUTOStr1,
    SW_AUTOStr1,
    PR_AUTOStr1,
    JA_AUTOStr1,
    CT_AUTOStr1,
    CS_AUTOStr1,
    AR_AUTOStr1,    

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
     EN_RGB0to255Str1,//AR
     
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
     EN_RGB16to255Str1,//AR
};
code UCHAR **SecondLevelTabOfMItem3[] = {
    PictureModeTab1,
    DualViewTab1,
    NULL,
#if MD_ENABLE_OVERSCAN == ON        
    OnOffTab1,
#endif    
    FullAspectTab1,
#if ENABLE_COLOR_FORMAT == ON
    ColorFormatTab1,
#endif    
    HDMIRGBPCRangeTab1,
};

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
 code UCHAR AR_PCAudioStr1[]={5, 'P', 'C', ' ', 189, 18, };


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
 code UCHAR AR_AutoDetectStr1 []={4, 2, 3, 196, 197, };

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
 code UCHAR AR_HDMIAudioStr1[]={7, 'H', 'D', 'M', 'I', ' ', 189, 18, };

code UCHAR EN_DPAudioStr1[]={8, 'D', 'P', ' ', 'A', 'u', 'd', 'i', 'o',};
code UCHAR FR_DPAudioStr1[]={8, 'A', 'u', 'd', 'i', 'o', ' ', 'D', 'P',};
code UCHAR GE_DPAudioStr1[]={8, 'D', 'P', ' ', 'A', 'u', 'd', 'i', 'o',};
code UCHAR IT_DPAudioStr1[]={8, 'A', 'u', 'd', 'i', 'o', ' ', 'D', 'P',};
code UCHAR SP_DPAudioStr1[]={8, 'A', 'u', 'd', 'i', 'o', ' ', 'D', 'P',};
code UCHAR PO_DPAudioStr1[]={8, 'D', 130, 'w', 'i', '.', ' ', 'D', 'P',};
code UCHAR CZ_DPAudioStr1[]={7, 'Z', 'v', 'u', 'k', ' ', 'D', 'P',};
code UCHAR MA_DPAudioStr1[]={7, 'D', 'P', ' ', 'h', 'a', 'n', 'g', };
code UCHAR SE_DPAudioStr1[]={8, 'D', 'P', ' ', 'A', 'u', 'd', 'i', 'o', };
code UCHAR RO_DPAudioStr1[]={8, 'A', 'u', 'd', 'i', 'o', ' ', 'D', 'P',};
code UCHAR DU_DPAudioStr1[]={8, 'D', 'P', ' ', 'a', 'u', 'd', 'i', 'o', };
code UCHAR RU_DPAudioStr1[]={7, 175, 131, 135, 148, ' ', 'D', 'P',};
code UCHAR SW_DPAudioStr1[]={7, 'D', 'P', '-', 'l', 'j', 'u', 'd', };
code UCHAR PR_DPAudioStr1[]={8, 21, 'u', 'd', 'i', 'o', ' ', 'D', 'P',};
code UCHAR JA_DPAudioStr1[]={9, 'D', 'P',32,149,21,161,170,149,32,};
code UCHAR CT_DPAudioStr1[]={5, 'D', 'P', ' ', 190, 191, };
code UCHAR CS_DPAudioStr1[]={5, 'D', 'P', ' ', 189, 18, };
code UCHAR AR_DPAudioStr1[]={5, 'D', 'P', ' ', 189, 18, };


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
     AR_PCAudioStr1,
     
    EN_DPAudioStr1,
    FR_DPAudioStr1,
    GE_DPAudioStr1,
    IT_DPAudioStr1,
    SP_DPAudioStr1,
    PO_DPAudioStr1,
    CZ_DPAudioStr1,
    MA_DPAudioStr1,
    SE_DPAudioStr1,
    RO_DPAudioStr1,
    DU_DPAudioStr1,
    RU_DPAudioStr1,
    SW_DPAudioStr1,
    PR_DPAudioStr1,
    JA_DPAudioStr1,
    CT_DPAudioStr1,
    CS_DPAudioStr1,
    AR_DPAudioStr1,

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
    AR_HDMIAudioStr1,
 
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
     AR_AutoDetectStr1,
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
code UCHAR AR_LanguageStr1[] ={5,143,203,219,218,136};
 
code UCHAR EN_DisplayTimeStr1[] = {12, 'D', 'i', 's', 'p', 'l', 'a', 'y', ' ', 'T', 'i', 'm', 'e', };
code UCHAR FR_DisplayTimeStr1[] = {17, 'T', 'e', 'm', 'p', 's', ' ', 'd', 39, 'a', 'f', 'f', 'i', 'c', 'h', 'a', 'g', 'e', };
code UCHAR GE_DisplayTimeStr1[] = {11, 'A', 'n', 'z', 'e', 'i', 'g', 'e', 'z', 'e', 'i', 't', };
code UCHAR IT_DisplayTimeStr1[] = {17, 'D', 'u', 'r', 'a', 't', 'a', ' ', 'v', 'i', 's', 'u', 'a', 'l', 'i', 'z', 'z', '.', };
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
code UCHAR AR_DisplayTimeStr1[] = {10,185,250,169,199,218,136,32,145,210,232};
 
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
code UCHAR RU_OsdLockStr1[] =  {15, 170, 127, 136, 148, '.', ' ', 176, 148, 133, '.', ' ', 146, 128, 144, 174, };
code UCHAR SW_OsdLockStr1[] =  {7, 'O', 'S', 'D', '-', 'l', 123, 's', };
code UCHAR PR_OsdLockStr1[] =  {12, 'B', 'l', 'o', 'q', 'u', 'e', 'i', 'o', ' ', 'O', 'S', 'D', };
code UCHAR JA_OsdLockStr1[] =  {7, 'O', 'S', 'D', ' ', 216, 148, 217, };
code UCHAR CT_OsdLockStr1[] = {5, 208, 133, 'O', 'S', 'D', };
code UCHAR CS_OsdLockStr1[] = {4, 'O', 'S', 'D', 207, };
code UCHAR AR_OsdLockStr1[] = {7,79,83,68,32,217,207,210};

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
     AR_LanguageStr1,
     
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
     AR_DisplayTimeStr1,

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
     AR_OsdLockStr1,
     
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
code UCHAR AR_min10Str1[] = {7, 143,211,239,211,164,49,48, };

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
code UCHAR AR_min20Str1[] = {7, 143,211,239,211,164,50,48, };

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
code UCHAR AR_min30Str1[] = {7, 143,211,239,211,164,51,48, };

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
     AR_OffStr1,

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
     AR_min10Str1,
  
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
     AR_min20Str1,
     
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
     AR_min30Str1,
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
code UCHAR AR_CurrentResStr1[] = {13,143,239,218,137,159,218,136,32,143,211,165,218,136};
 
code UCHAR EN_OptimumResStr1[] = {18, 'O', 'p', 't', 'i', 'm', 'u', 'm', ' ', 'R', 'e', 's', 'o', 'l', 'u', 't', 'i', 'o', 'n', };
code UCHAR FR_OptimumResStr1[] = {19, 'R', 2, 's', 'o', 'l', 'u', 't', 'i', 'o', 'n', ' ', 'o', 'p', 't', 'i', 'm', 'a', 'l', 'e', };
code UCHAR GE_OptimumResStr1[] = {18, 'O', 'p', 't', 'i', 'm', 'a', 'l', 'e', ' ', 'A', 'u', 'f', 'l', 10, 's', 'u', 'n', 'g', };
code UCHAR IT_OptimumResStr1[] = {20, 'R', 'i', 's', 'o', 'l', 'u', 'z', 'i', 'o', 'n', 'e', ' ', 'o', 't', 't', 'i', 'm', 'a', 'l', 'e', };
code UCHAR SP_OptimumResStr1[] = {17, 'R', 'e', 's', 'o', 'l', 'u', 'c', 'i', 4, 'n', ' ', 4, 'p', 't', 'i', 'm', 'a', };
code UCHAR PO_OptimumResStr1[] = {10, 'O', 'p', 't', '.', ' ', 'r', 'o', 'z', 'd', '.', };
code UCHAR CZ_OptimumResStr1[] = {19, 'O', 'p', 't', 'i', 'm', 0, 'l', 'n', 1, ' ', 'r', 'o', 'z', 'l', 'i', 20, 'e', 'n', 1, };
code UCHAR MA_OptimumResStr1[] = {19, 'O', 'p', 't', 'i', 'm', 0, 'l', 'i', 's', ' ', 'f', 'e', 'l', 'b', 'o', 'n', 't', 0, 's', };
code UCHAR SE_OptimumResStr1[] = {18, 'O', 'p', 't', 'i', 'm', '.', ' ', 'r', 'a', 'z', 'l', 'u', 6, 'i', 'v', 'o', 's', 't', };
code UCHAR RO_OptimumResStr1[] = {16, 'R', 'e', 'z', 'o', 'l', 'u', 124, 'i', 'e', ' ', 'o', 'p', 't', 'i', 'm', 125, };
code UCHAR DU_OptimumResStr1[] = {18, 'O', 'p', 't', 'i', 'm', 'a', 'l', 'e', ' ', 'r', 'e', 's', 'o', 'l', 'u', 't', 'i', 'e', };
code UCHAR RU_OptimumResStr1[] = {10, 162, 126, 132, '.', ' ', 133, 143, 141, 133, '.', };
code UCHAR SW_OptimumResStr1[] = {18, 'O', 'p', 't', 'i', 'm', 'a', 'l', ' ', 'u', 'p', 'p', 'l', 10, 's', 'n', 'i', 'n', 'g', };
code UCHAR PR_OptimumResStr1[] = {15, 'R', 'e', 's', 'o', 'l', 'u', 7, 123, 'o', ' ', 'I', 'd', 'e', 'a', 'l', };
code UCHAR JA_OptimumResStr1[] = {5, 228, 229, 180, 26, 124, };
code UCHAR CT_OptimumResStr1[] = {5, 218, 219, 177, 178, 28, };
code UCHAR CS_OptimumResStr1[] = {5, 218, 219, 176, 177, 19, };
code UCHAR AR_OptimumResStr1[] = {8,143,211,164,32,217,187,206,126};

#if ENABLE_OSD_SHOW_MODELNAME == ON 
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
code UCHAR AR_ModelNameStr1[] = {11,217,239,164,233,223,218,136,32,221,174,136};
#endif 
#if ENABLE_PICTURE_MODE_ANIMATION == ON

code UCHAR EN_AnimationStr13[] = {9, 'A','n','i','m','a','t','i','o','n'};
code UCHAR FR_AnimationStr13[] = {9, 'A','n','i','m','a','t','i','o','n'};
code UCHAR GE_AnimationStr13[] = {9, 'A','n','i','m','a','t','i','o','n'};
code UCHAR IT_AnimationStr13[] = {10, 'A','n','i','m','a','z','i','o','n','e'};
code UCHAR SP_AnimationStr13[] = {9, 'A','n','i','m','a','c','i',4,'n'};
code UCHAR PO_AnimationStr13[] = {8, 'A','n','i','m','a','c','j','a'};
code UCHAR CZ_AnimationStr13[] = {7, 'A','n','i','m','a','c','e'};
code UCHAR MA_AnimationStr13[] = {8, 'A','n','i','m',0,'c','i',4};
code UCHAR SE_AnimationStr13[] = {9, 'A','n','i','m','a','c','i','j','a'};
code UCHAR RO_AnimationStr13[] = {8, 'A','n','i','m','a',124,'i','e'};
code UCHAR DU_AnimationStr13[] = {8, 'A','n','i','m','a','t','i','e'};
code UCHAR RU_AnimationStr13[] = {8, 130,144,124,146,143,171,124,149};
code UCHAR SW_AnimationStr13[] = {9, 'A','n','i','m','a','t','i','o','n'};
code UCHAR PR_AnimationStr13[] = {8, 'A','n','i','m','a',7,123,'o'};
code UCHAR JA_AnimationStr13[] = {4, 161, 140, 165,28};
code UCHAR CT_AnimationStr13[] = {4, 3,173,147,174};
code UCHAR CS_AnimationStr13[] = {4, 3,172,145,173};
code UCHAR AR_AnimationStr13[] = {4, 3,172,145,173};

#endif


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
     AR_InputStr1,
     
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
     AR_CurrentResStr1,
     
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
     AR_OptimumResStr1,
#if ENABLE_OSD_SHOW_MODELNAME == ON
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
     AR_ModelNameStr1,
#endif     
};

//Hot key string
code UCHAR *CustKeyTabStr1[] = {
     //ULEric140331
#if 1//IS_BL_SERIES     
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
     AR_BrightnessStr1,

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
     AR_ContrastStr1,
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
    AR_InputStr1,

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
     AR_PictureModeStr1,
#if ENABLE_CUSTOMKEY_CAD == ON
    EN_CADStr1,
    FR_CADStr1,
    GE_CADStr1,
    IT_CADStr1,
    SP_CADStr1,
    PO_CADStr1,
    CZ_CADStr1,
    MA_CADStr1,
    SE_CADStr1,
    RO_CADStr1,
    DU_CADStr1,
    RU_CADStr1,
    SW_CADStr1,
    PR_CADStr1,
    JA_CADStr1,
    CT_CADStr1,
    CS_CADStr1,
    AR_CADStr1,
#endif
#if ENABLE_CUSTOMKEY_ANIMATION == ON
     EN_AnimationStr13,
     FR_AnimationStr13,
     GE_AnimationStr13,
     IT_AnimationStr13,
     SP_AnimationStr13,
     PO_AnimationStr13,
     CZ_AnimationStr13,
     MA_AnimationStr13,
     SE_AnimationStr13,
     RO_AnimationStr13,
     DU_AnimationStr13,
     RU_AnimationStr13,
     SW_AnimationStr13,
     PR_AnimationStr13,
     JA_AnimationStr13,
     CT_AnimationStr13,
     CS_AnimationStr13,
     AR_AnimationStr13,
#endif
#if ENABLE_CUSTOMKEY_LBL == ON
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
     AR_LowBlueLightStr1, 
#endif
#elif IS_GW_SERIES
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
#endif     
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
     AR_DisplayModeStr1,
     
#if ENABLE_CUSTOMKEY_AUTOADJ == ON             
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
     AR_AutoAdjustmentStr1,
     #endif
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
     AR_VolumeStr1,

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
     AR_MuteStr1,

#if ENABLE_EYE_PROTECT == ON
     EN_EyeProtectStr1,
     FR_EyeProtectStr1,
     GE_EyeProtectStr1,
     IT_EyeProtectStr1,
     SP_EyeProtectStr1,
     PO_EyeProtectStr1,
     CZ_EyeProtectStr1,
     MA_EyeProtectStr1,
     SE_EyeProtectStr1,
     RO_EyeProtectStr1,
     DU_EyeProtectStr1,
     RU_EyeProtectStr1,
     SW_EyeProtectStr1,
     PR_EyeProtectStr1,
     JA_EyeProtectStr1,
     CT_EyeProtectStr1,
     CS_EyeProtectStr1,
     AR_EyeProtectStr1,

     EN_EyeProtectMeterStr1,
     FR_EyeProtectMeterStr1,
     GE_EyeProtectMeterStr1,
     IT_EyeProtectMeterStr1,
     SP_EyeProtectMeterStr1,
     PO_EyeProtectMeterStr1,
     CZ_EyeProtectMeterStr1,
     MA_EyeProtectMeterStr1,
     SE_EyeProtectMeterStr1,
     RO_EyeProtectMeterStr1,
     DU_EyeProtectMeterStr1,
     RU_EyeProtectMeterStr1,
     SW_EyeProtectMeterStr1,
     PR_EyeProtectMeterStr1,
     JA_EyeProtectMeterStr1,
     CT_EyeProtectMeterStr1,
     CS_EyeProtectMeterStr1,
     AR_EyeProtectMeterStr1,
#endif
#if ENABLE_ECO_SENSOR == ON
    EN_ECOSensorStr1,
    FR_ECOSensorStr1,
    GE_ECOSensorStr1,
    IT_ECOSensorStr1,
    SP_ECOSensorStr1,
    PO_ECOSensorStr1,
    CZ_ECOSensorStr1,
    MA_ECOSensorStr1,
    SE_ECOSensorStr1,
    RO_ECOSensorStr1,
    DU_ECOSensorStr1,
    RU_ECOSensorStr1,
    SW_ECOSensorStr1,
    PR_ECOSensorStr1,
    JA_ECOSensorStr1,
    CT_ECOSensorStr1,
    CS_ECOSensorStr1,
    AR_ECOSensorStr1,

    EN_ECOSensorMeterStr1,
    FR_ECOSensorMeterStr1,
    GE_ECOSensorMeterStr1,
    IT_ECOSensorMeterStr1,
    SP_ECOSensorMeterStr1,
    PO_ECOSensorMeterStr1,
    CZ_ECOSensorMeterStr1,
    MA_ECOSensorMeterStr1,
    SE_ECOSensorMeterStr1,
    RO_ECOSensorMeterStr1,
    DU_ECOSensorMeterStr1,
    RU_ECOSensorMeterStr1,
    SW_ECOSensorMeterStr1,
    PR_ECOSensorMeterStr1,
    JA_ECOSensorMeterStr1,
    CT_ECOSensorMeterStr1,
    CS_ECOSensorMeterStr1,
    AR_ECOSensorMeterStr1,
#endif
#if ENABLE_ERGONOMICS == ON            
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
     AR_SmartReminderStr1,
#endif     
     
};





code UCHAR **SecondLevelTabOfMItem4[] = {
    OSDSettingTab1, 
    CustKeyTabStr1, 
    CustKeyTabStr1, 
    CustKeyTabStr1,
    OnOffTab1,
#if ENABLE_DPHDMI_AUTO_SWITCH == ON
    OnOffTab1,
#endif    
    DPmodeStrTab,
#if ENABLE_DPHDMI_AUTO_SWITCH == ON    
    OnOffTab1,
#endif    
    AutoPowerOffTab1,
    OnOffTab1,
    InfoTab1,
    YesNoTab1
};

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
     EN_25Str1,
};



#if ENABLE_EYE_PROTECT == ON
code UCHAR **SecondLevelTabOfMItemErgo[] = {OnOffTab1,OnOffTab1,OnOffTab1,TimeIntervalTab1,DurationTab1};
#else
code UCHAR **SecondLevelTabOfMItemErgo[] = {OnOffTab1,TimeIntervalTab1,DurationTab1};
#endif

#if ENABLE_ECO_SENSOR == ON
 code UCHAR EN_NearStr1[]={4, 'N', 'e', 'a', 'r'};
 code UCHAR FR_NearStr1[]={6, 'P','r','o','c','h','e'};
 code UCHAR GE_NearStr1[]={3, 'N','a','h'};
 code UCHAR IT_NearStr1[]={6, 'V','i','c','i','n','o'};
 code UCHAR SP_NearStr1[]={5, 'C','e','r','c','a'};
 code UCHAR PO_NearStr1[]={6, 'B','l','i','s','k','o'};
 code UCHAR CZ_NearStr1[]={6, 'B','l',1,'z','k','o'};
 code UCHAR MA_NearStr1[]={5, 'K',10,'z','e','l'};
 code UCHAR SE_NearStr1[]={5, 'B','l','i','z','u'}; 
 code UCHAR RO_NearStr1[]={7, 'A','p','r','o','a','p','e'};
 code UCHAR DU_NearStr1[]={8, 'D','i','c','h','t','b','i','j'};
 code UCHAR RU_NearStr1[]={5, 156,149,139,136,146};
 code UCHAR SW_NearStr1[]={4, 'N',3,'r','a'};
 code UCHAR PR_NearStr1[]={5, 'P','e','r','t','o'};
 code UCHAR JA_NearStr1[]={2, 251,183};
 code UCHAR CT_NearStr1[]={1, 251};
 code UCHAR CS_NearStr1[]={1, 249};
 code UCHAR AR_NearStr1[]={1, 249};


 code UCHAR EN_MiddleStr1[]={6, 'M', 'i', 'd', 'd', 'l', 'e'};
 code UCHAR FR_MiddleStr1[]={6, 'M','i','l','i','e','u'};
 code UCHAR GE_MiddleStr1[]={6, 'M','i','t','t','e','l'};
 code UCHAR IT_MiddleStr1[]={5, 'M','e','d','i','o'};
 code UCHAR SP_MiddleStr1[]={5, 'M','e','d','i','o'};
 code UCHAR PO_MiddleStr1[]={9, 'P','o',32,123,'r','o','d','k','u'};
 code UCHAR CZ_MiddleStr1[]={9, 'U','p','r','o','s','t',124,'e','d'};
 code UCHAR MA_MiddleStr1[]={6, 'K',125,10,'z',2,'p'};
 code UCHAR SE_MiddleStr1[]={7, 'S','r','e','d','n','j','e'};
 code UCHAR RO_MiddleStr1[]={6, 'M','i','j','l','o','c'};
 code UCHAR DU_MiddleStr1[]={7, 'M','i','d','d','e','n'};
 code UCHAR RU_MiddleStr1[]={10, 167,136,125,128,133,128,139,124,144,128};
 code UCHAR SW_MiddleStr1[]={10, 'M','e','d','e','l','l',123,'n','g','t'};
 code UCHAR PR_MiddleStr1[]={4, 'M','e','i','o'};
 code UCHAR JA_MiddleStr1[]={2, 23,252};
 code UCHAR CT_MiddleStr1[]={2, 124,125};
 code UCHAR CS_MiddleStr1[]={1, 21};
 code UCHAR AR_MiddleStr1[]={1, 21};

 code UCHAR EN_FarStr1[]={3, 'F', 'a', 'r'};
 code UCHAR FR_FarStr1[]={4, 'L','o','i','n'};
 code UCHAR GE_FarStr1[]={4, 'W','e','i','t'};
 code UCHAR IT_FarStr1[]={7, 'L','o','n','t','a','n','o'};
 code UCHAR SP_FarStr1[]={5, 'L','e','j','o','s'};
 code UCHAR PO_FarStr1[]={6, 'D','a','l','e','k','o'};
 code UCHAR CZ_FarStr1[]={6, 'D','a','l','e','k','o'};
 code UCHAR MA_FarStr1[]={5, 'T',0,'v','o','l'};
 code UCHAR SE_FarStr1[]={8, 'U','d','a','l','j','e','n','o'};
 code UCHAR RO_FarStr1[]={7, 'D','e','p','a','r','t','e'};
 code UCHAR DU_FarStr1[]={3, 'V','e','r'};
 code UCHAR RU_FarStr1[]={6, 123,143,127,128,148,136};
 code UCHAR SW_FarStr1[]={5, 'L',123,'n','g','t'};
 code UCHAR PR_FarStr1[]={5, 'L','o','n','g','e'};
 code UCHAR JA_FarStr1[]={2, 253,183};
 code UCHAR CT_FarStr1[]={1, 252};
 code UCHAR CS_FarStr1[]={1, 250};
 code UCHAR AR_FarStr1[]={1, 250};

code UCHAR *SensorRangeTab1[] = {
    EN_NearStr1,
    FR_NearStr1,
    GE_NearStr1,
    IT_NearStr1,
    SP_NearStr1,
    PO_NearStr1,
    CZ_NearStr1,
    MA_NearStr1,
    SE_NearStr1,
    RO_NearStr1,
    DU_NearStr1,
    RU_NearStr1,
    SW_NearStr1,
    PR_NearStr1,
    JA_NearStr1,
    CT_NearStr1,
    CS_NearStr1,
    AR_NearStr1,

    EN_MiddleStr1,
    FR_MiddleStr1,
    GE_MiddleStr1,
    IT_MiddleStr1,
    SP_MiddleStr1,
    PO_MiddleStr1,
    CZ_MiddleStr1,
    MA_MiddleStr1,
    SE_MiddleStr1,
    RO_MiddleStr1,
    DU_MiddleStr1,
    RU_MiddleStr1,
    SW_MiddleStr1,
    PR_MiddleStr1,
    JA_MiddleStr1,     
    CT_MiddleStr1,
    CS_MiddleStr1,
    AR_MiddleStr1,
        
    EN_FarStr1,
    FR_FarStr1,
    GE_FarStr1,
    IT_FarStr1,
    SP_FarStr1,
    PO_FarStr1,
    CZ_FarStr1,
    MA_FarStr1,
    SE_FarStr1,
    RO_FarStr1,
    DU_FarStr1,
    RU_FarStr1,
    SW_FarStr1,
    PR_FarStr1,
    JA_FarStr1,
    CT_FarStr1,
    CS_FarStr1,
    AR_FarStr1,
};
code UCHAR **SecondLevelTabOfMItemECO[] = {OnOffTab1,OnOffTab1,SensorRangeTab1};
#endif

#if ENABLE_ECO_SENSOR == ON
code UCHAR ***TestTable2[] = {SecondLevelTabOfMItem1, SecondLevelTabOfMItem2, SecondLevelTabOfMItem3, 
                              SecondLevelTabOfMItemAudio,SecondLevelTabOfMItem4,SecondLevelTabOfMItemErgo, SecondLevelTabOfMItemECO};
#else
code UCHAR ***TestTable2[] = {
    SecondLevelTabOfMItem1, 
    SecondLevelTabOfMItem2, 
    SecondLevelTabOfMItem3, 
    SecondLevelTabOfMItemAudio,
    SecondLevelTabOfMItem4,
    SecondLevelTabOfMItemErgo
};
#endif

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
code UCHAR AR_sec05Str1[] = {6,143,239,226,137,150,53, };
 
code UCHAR EN_sec10Str1[] = {6,49,48, 's', 'e', 'c', '.', };
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
code UCHAR AR_sec10Str1[] = {7,143,239,226,137,150,49,48, };

code UCHAR EN_sec15Str1[] = {6,49,53, 's', 'e', 'c', '.', };
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
code UCHAR AR_sec15Str1[] = {7,143,239,226,137,150,49,53, };

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
code UCHAR AR_sec20Str1[] = {7,143,239,226,137,150,50,48, };

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
code UCHAR AR_sec25Str1[] = {7,143,239,226,137,150,50,53,};

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
code UCHAR AR_sec30Str1[] = {7,143,239,226,137,150,51,48,143,};

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
     AR_sec05Str1,
     
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
     AR_sec10Str1,
     
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
     AR_sec15Str1,
     
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
     AR_sec20Str1,
     
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
     AR_sec25Str1,
     
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
     AR_sec30Str1,
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
code UCHAR AR_FrancaisStr1[] = {9, 'F', 'r', 'a', 'n', 194, 'a', 'i', 's', ' ', };

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
code UCHAR AR_JapaneseStr1[] = {3, 13, 14, 15, };

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
code UCHAR AR_ChineseS_Str1[] = {4, 'A','R','A','B' };

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
code UCHAR AR_ChineseT_Str1[] = {4, 18, 19, 8, 9, };

code UCHAR EN_ARABT_Str1[] = {4, 'A','r','a','b' };
code UCHAR AR_ARABT_Str1[] = {7,143,239,141,169,199,218,136};

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
EN_EnglishStr1,//AR

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
AR_FrancaisStr1,

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
EN_DeutschStr1,//AR

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
EN_ItalianoStr1,//AR

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
EN_EspanolStr1,//AR

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
EN_PolishStr1,//AR

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
EN_CzechStr1,//AR

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
EN_HungarianStr1,//AR

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
EN_Serbo_croatianStr1,//AR

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
EN_RomanianStr1,//AR

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
EN_NetherlandsStr1,//AR

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
EN_RussianStr1,//AR


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
EN_SwedishStr1,//AR

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
EN_ProtugueseStr1,//AR



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
AR_JapaneseStr1,

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
AR_ChineseS_Str1,

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
AR_ChineseT_Str1,



EN_ARABT_Str1,
EN_ARABT_Str1,//FR
EN_ARABT_Str1,//GE
EN_ARABT_Str1,//IT
EN_ARABT_Str1,//SP
EN_ARABT_Str1,//PO
EN_ARABT_Str1,//CZ
EN_ARABT_Str1,//MA
EN_ARABT_Str1,//SE
EN_ARABT_Str1,//RO
EN_ARABT_Str1,//DU
EN_ARABT_Str1,//RU
EN_ARABT_Str1,//SW
EN_ARABT_Str1,//PR
EN_ARABT_Str1,
EN_ARABT_Str1,
EN_ARABT_Str1,
AR_ARABT_Str1,

NULL_Str1,

 };


code UCHAR ModelWord_Str1[] = {sizeof(Inform_Model_TEXT)-1, Inform_Model_TEXT};
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



