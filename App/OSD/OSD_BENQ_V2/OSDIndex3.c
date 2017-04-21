#include "Include.h"

code UCHAR EN_BurningStr[] = {13, 'B', 'u', 'r', 'n', 'i', 'n', 'g', '.', '.', '.', '.', '.','.'};

code UCHAR *BurningStrTab[] = {
     EN_BurningStr,
     EN_BurningStr,
     EN_BurningStr,
     EN_BurningStr,
     EN_BurningStr,
     EN_BurningStr,
     EN_BurningStr,
     EN_BurningStr,
     EN_BurningStr,
     EN_BurningStr,
     EN_BurningStr,
     EN_BurningStr,
     EN_BurningStr,
     EN_BurningStr,
     EN_BurningStr,
     EN_BurningStr,
     EN_BurningStr,
     EN_BurningStr,
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
code UCHAR AR_AutoDialogStr[] = {6, 0, 1, 2, 3, 4, 5,};

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
     AR_AutoDialogStr,
};

// picture advanced mode
code UCHAR EN_StanddardStr11[] = {8, 'S', 't', 'a', 'n', 'd', 'a', 'r', 'd', };
code UCHAR FR_StanddardStr11[] = {8, 'S', 't', 'a', 'n', 'd', 'a', 'r', 'd', };
code UCHAR GE_StanddardStr11[] = {8, 'S', 't', 'a', 'n', 'd', 'a', 'r', 'd', };
code UCHAR IT_StanddardStr11[] = {8, 'S', 't', 'a', 'n', 'd', 'a', 'r', 'd', };
code UCHAR SP_StanddardStr11[] = {8, 'E', 's', 't', 0, 'n', 'd', 'a', 'r', };
code UCHAR PO_StanddardStr11[] = {8, 'S', 't', 'a', 'n', 'd', 'a', 'r', 'd', };
code UCHAR CZ_StanddardStr11[] = {10, 'S', 't', 'a', 'n', 'd', 'a', 'r', 'd', 'n', 1, };
code UCHAR MA_StanddardStr11[] = {7, 'N', 'o', 'r', 'm', 0, 'l', ' ', };
code UCHAR SE_StanddardStr11[] = {8, 'S', 't', 'a', 'n', 'd', 'a', 'r', 'd', };
code UCHAR RO_StanddardStr11[] = {8, 'S', 't', 'a', 'n', 'd', 'a', 'r', 'd', };
code UCHAR DU_StanddardStr11[] = {9, 'S', 't', 'a', 'n', 'd', 'a', 'a', 'r', 'd', };
code UCHAR RU_StanddardStr11[] = {8, 164, 132, 143, 144, 139, 143, 133, 132, };
code UCHAR SW_StanddardStr11[] = {8, 'S', 't', 'a', 'n', 'd', 'a', 'r', 'd', };
code UCHAR PR_StanddardStr11[] = {6, 'P', 'a', 'd', 'r', 123, 'o', };
code UCHAR JA_StanddardStr11[] = {3, 133, 134, 162, };
code UCHAR CT_StanddardStr11[] = {2, 124, 125, };
code UCHAR CS_StanddardStr11[] = {2, 125, 126, };
code UCHAR AR_StanddardStr11[] = {5,236,174,137,239,210};

#if ENABLE_PICTURE_MODE_ANIMATION == ON

code UCHAR EN_AnimationStr11[] = {9, 'A','n','i','m','a','t','i','o','n'};
code UCHAR FR_AnimationStr11[] = {9, 'A','n','i','m','a','t','i','o','n'};
code UCHAR GE_AnimationStr11[] = {9, 'A','n','i','m','a','t','i','o','n'};
code UCHAR IT_AnimationStr11[] = {10, 'A','n','i','m','a','z','i','o','n','e'};
code UCHAR SP_AnimationStr11[] = {9, 'A','n','i','m','a','c','i',4,'n'};
code UCHAR PO_AnimationStr11[] = {8, 'A','n','i','m','a','c','j','a'};
code UCHAR CZ_AnimationStr11[] = {7, 'A','n','i','m','a','c','e'};
code UCHAR MA_AnimationStr11[] = {8, 'A','n','i','m',0,'c','i',4};
code UCHAR SE_AnimationStr11[] = {9, 'A','n','i','m','a','c','i','j','a'};
code UCHAR RO_AnimationStr11[] = {8, 'A','n','i','m','a',124,'i','e'};
code UCHAR DU_AnimationStr11[] = {8, 'A','n','i','m','a','t','i','e'};
code UCHAR RU_AnimationStr11[] = {8, 130,144,124,146,143,171,124,149};
code UCHAR SW_AnimationStr11[] = {9, 'A','n','i','m','a','t','i','o','n'};
code UCHAR PR_AnimationStr11[] = {8, 'A','n','i','m','a',7,123,'o'};
code UCHAR JA_AnimationStr11[] = {4, 161, 140, 165,28};
code UCHAR CT_AnimationStr11[] = {4, 3,173,147,174};
code UCHAR CS_AnimationStr11[] = {4, 3,172,145,173};
code UCHAR AR_AnimationStr11[] = {6,143,214,169,159,218,136};

#endif

#if	ENABLE_PICTURE_MODE_CAD == ON

code UCHAR EN_CADStr11[] = {7, 'C','A','D',47,'C','A','M'};
code UCHAR FR_CADStr11[] = {7, 'C','A','O',47,'P','A','O'};
code UCHAR GE_CADStr11[] = {7, 'C','A','D',47,'C','A','M'};
code UCHAR IT_CADStr11[] = {7, 'C','A','D',47,'C','A','M'};
code UCHAR SP_CADStr11[] = {7, 'C','A','D',47,'C','A','M'};
code UCHAR PO_CADStr11[] = {7, 'C','A','D',47,'C','A','M'};
code UCHAR CZ_CADStr11[] = {7, 'C','A','D',47,'C','A','M'};
code UCHAR MA_CADStr11[] = {7, 'C','A','D',47,'C','A','M'};
code UCHAR SE_CADStr11[] = {7, 'C','A','D',47,'C','A','M'};
code UCHAR RO_CADStr11[] = {7, 'C','A','D',47,'C','A','M'};
code UCHAR DU_CADStr11[] = {7, 'C','A','D',47,'C','A','M'};
code UCHAR RU_CADStr11[] = {7, 'C','A','D',47,'C','A','M'};
code UCHAR SW_CADStr11[] = {7, 'C','A','D',47,'C','A','M'};
code UCHAR PR_CADStr11[] = {7, 'C','A','D',47,'C','A','M'};
code UCHAR JA_CADStr11[] = {7, 'C','A','D',47,'C','A','M'};
code UCHAR CT_CADStr11[] = {7, 67,65,68,47,67,65,77 };
code UCHAR CS_CADStr11[] = {7, 67,65,68,47,67,65,77};
code UCHAR AR_CADStr11[] = {7, 67,65,68,47,67,65,77};
#endif
#if	ENABLE_PRESENTATION_MODE == ON
code UCHAR EN_PresentationStr11[] = {12, 'P','r','e','s','e','n','t','a','t','i','o','n'};
code UCHAR FR_PresentationStr11[] = {12, 'P','r',2,'s','e','n','t','a','t','i','o','n'};
code UCHAR GE_PresentationStr11[] = {12, 'P','r',3,'s','e','n','t','a','t','i','o','n'};
code UCHAR IT_PresentationStr11[] = {8, 'P','r','e','s','e','n','t','e'};
code UCHAR SP_PresentationStr11[] = {12, 'P','r','e','s','e','n','t','a','c','i',4,'n'};
code UCHAR PO_PresentationStr11[] = {14, 'P','r','z','e','d','s','t','a','w','i','a','n','i','e'};
code UCHAR CZ_PresentationStr11[] = {10, 'P','r','e','z','e','n','t','a','c','e'};
code UCHAR MA_PresentationStr11[] = {11, 'P','r','e','z','e','n','t',0,'c','i',4};
code UCHAR SE_PresentationStr11[] = {12, 'P','r','e','z','e','n','t','a','c','i','j','a'};
code UCHAR RO_PresentationStr11[] = {10, 'P','r','e','z','e','n','t','a','r','e'};
code UCHAR DU_PresentationStr11[] = {11, 'P','r','e','s','e','n','t','a','t','i','e'};
code UCHAR RU_PresentationStr11[] = {11, 167,133,128,141,128,144,132,143,171,124,149};
code UCHAR SW_PresentationStr11[] = {10, 'P','r','e','s','e','n','t','e','r','a'};
code UCHAR PR_PresentationStr11[] = {12, 'A','p','r','e','s','e','n','t','a',7,123,'o'};
code UCHAR JA_PresentationStr11[] = {2, 179,0};
code UCHAR CT_PresentationStr11[] = {2, 175, 176};
code UCHAR CS_PresentationStr11[] = {2, 174,175};
code UCHAR AR_PresentationStr11[] = {2, 174,175};
#endif
#if ENABLE_PICTURE_MODE_MOVIE == ON           
code UCHAR EN_MovieStr11[] = {5, 'M', 'o', 'v', 'i', 'e', };
code UCHAR FR_MovieStr11[] = {5, 'F', 'i', 'l', 'm', ' ', };
code UCHAR GE_MovieStr11[] = {4, 'F', 'i', 'l', 'm', };
code UCHAR IT_MovieStr11[] = {4, 'F', 'i', 'l', 'm', };
code UCHAR SP_MovieStr11[] = {8, 'P', 'e', 'l', 1, 'c', 'u', 'l', 'a', };
code UCHAR PO_MovieStr11[] = {5, 'F', 'i', 'l', 'm', ' ', };
code UCHAR CZ_MovieStr11[] = {5, 'F', 'i', 'l', 'm', ' ', };
code UCHAR MA_MovieStr11[] = {5, 'F', 'i', 'l', 'm', ' ', };
code UCHAR SE_MovieStr11[] = {5, 'F', 'i', 'l', 'm', ' ', };
code UCHAR RO_MovieStr11[] = {5, 'F', 'i', 'l', 'm', ' ', };
code UCHAR DU_MovieStr11[] = {5, 'F', 'i', 'l', 'm', ' ', };
code UCHAR RU_MovieStr11[] = {5, 153, 124, 144, 136, ' ', };
code UCHAR SW_MovieStr11[] = {5, 'F', 'i', 'l', 'm', ' ', };
code UCHAR PR_MovieStr11[] = {6, 'F', 'i', 'l', 'm', 'e', ' ', };
code UCHAR JA_MovieStr11[] = {2, 3, 25, };
code UCHAR CT_MovieStr11[] = {2, 167, 168, };
code UCHAR CS_MovieStr11[] = {2, 165, 168, };
code UCHAR AR_MovieStr11[] = {2, 165, 168, };
#endif
#if ENABLE_PICTURE_MODE_GAME == ON           
code UCHAR EN_GameStr11[] =  {4, 'G', 'a', 'm', 'e', };
code UCHAR FR_GameStr11[] =  {3, 'J', 'e', 'u', };
code UCHAR GE_GameStr11[] =  {6, 'S', 'p', 'i', 'e', 'l', 'e', };
code UCHAR IT_GameStr11[] =  {6, 'G', 'i', 'o', 'c', 'h', 'i', };
code UCHAR SP_GameStr11[] =  {5, 'J', 'u', 'e', 'g', 'o', };
code UCHAR PO_GameStr11[] =  {3, 'G', 'r', 'y', };
code UCHAR CZ_GameStr11[] =  {3, 'H', 'r', 'a', };
code UCHAR MA_GameStr11[] =  {5, 'J', 0, 't', 2, 'k', };
code UCHAR SE_GameStr11[] =  {4, 'I', 'g', 'r', 'a', };
code UCHAR RO_GameStr11[] =  {6, 'J', 'o', 'c', 'u', 'r', 'i', };
code UCHAR DU_GameStr11[] =  {4, 'S', 'p', 'e', 'l', };
code UCHAR RU_GameStr11[] =  {4, 150, 'r', 'p', 'a', };
code UCHAR SW_GameStr11[] =  {4, 'S', 'p', 'e', 'l', };
code UCHAR PR_GameStr11[] =  {4, 'J', 'o', 'g', 'o', };
code UCHAR JA_GameStr11[] =  {3, 176, 21, 154, };
code UCHAR CT_GameStr11[] =  {2, 165, 166, };
code UCHAR CS_GameStr11[] =  {2, 166, 167, };
code UCHAR AR_GameStr11[] =  {2, 166, 167, };
#endif
#if ENABLE_PICTURE_MODE_PHOTO == ON           
code UCHAR EN_PhotoStr11[] = {5, 'P', 'h', 'o', 't', 'o', };
code UCHAR FR_PhotoStr11[] = {5, 'P', 'h', 'o', 't', 'o', };
code UCHAR GE_PhotoStr11[] = {4, 'F', 'o', 't', 'o', };
code UCHAR IT_PhotoStr11[] = {4, 'F', 'o', 't', 'o', };
code UCHAR SP_PhotoStr11[] = {8, 'F', 'o', 't', 'o', 12, 12, 12, 12, };
code UCHAR PO_PhotoStr11[] = {7, 'Z', 'd', 'j', 128, 'c', 'i', 'e', };
code UCHAR CZ_PhotoStr11[] = {4, 'F', 'o', 't', 'o', };
code UCHAR MA_PhotoStr11[] = {4, 'F', 'o', 't', 4, };
code UCHAR SE_PhotoStr11[] = {4, 'F', 'o', 't', 'o', };
code UCHAR RO_PhotoStr11[] = {4, 'F', 'o', 't', 'o', };
code UCHAR DU_PhotoStr11[] = {4, 'F', 'o', 't', 'o', };
code UCHAR RU_PhotoStr11[] = {4, 145, 136, 132, 136, };
code UCHAR SW_PhotoStr11[] = {4, 'F', 'o', 't', 'o', };
code UCHAR PR_PhotoStr11[] = {4, 'F', 'o', 't', 'o', };
code UCHAR JA_PhotoStr11[] = {2, 174, 175, };
code UCHAR CT_PhotoStr11[] = {3, 164, 24, ' ', };
code UCHAR CS_PhotoStr11[] = {2, 23, 24, };
code UCHAR AR_PhotoStr11[] = {2, 23, 24, };

#endif
#if	ENABLE_PICTURE_MODE_REC709 == ON      
code UCHAR EN_Rec709Str11[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
code UCHAR FR_Rec709Str11[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
code UCHAR GE_Rec709Str11[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
code UCHAR IT_Rec709Str11[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
code UCHAR SP_Rec709Str11[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
code UCHAR PO_Rec709Str11[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
code UCHAR CZ_Rec709Str11[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
code UCHAR MA_Rec709Str11[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
code UCHAR SE_Rec709Str11[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
code UCHAR RO_Rec709Str11[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
code UCHAR DU_Rec709Str11[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
code UCHAR RU_Rec709Str11[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
code UCHAR SW_Rec709Str11[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
code UCHAR PR_Rec709Str11[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
code UCHAR JA_Rec709Str11[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
code UCHAR CT_Rec709Str11[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
code UCHAR CS_Rec709Str11[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
code UCHAR AR_Rec709Str11[] = {7, 'R', 'e', 'c', '.', '7', '0', '9'};
#endif
#if	ENABLE_PICTURE_MODE_DARKROOM == ON      
code UCHAR EN_DarkroomStr11[] = {8,  'D', 'a', 'r', 'k', 'R', 'o', 'o', 'm'};
code UCHAR FR_DarkroomStr11[] = {13, 'C', 'h', 'a', 'm', 'b', 'r', 'e', ' ', 'n', 'o', 'i', 'r', 'e',};
code UCHAR GE_DarkroomStr11[] = {12, 'D', 'u', 'n', 'k', 'e', 'l', 'k', 'a', 'm', 'm', 'e', 'r',};
code UCHAR IT_DarkroomStr11[] = {13, 'C', 'a', 'm', 'e', 'r', 'a', ' ', 'o', 's', 'c', 'u', 'r', 'a',};
code UCHAR SP_DarkroomStr11[] = {13, 'C', 'u', 'a', 'r', 't', 'o', ' ', 'o', 's', 'c', 'u', 'r', 'o',};
code UCHAR PO_DarkroomStr11[] = {7,  'C', 'i', 'e', 'm', 'n', 'i', 'a', };
code UCHAR CZ_DarkroomStr11[] = {14, 'T', 'm', 'a', 'v',  0, ' ', 'm', 1, 's', 't', 'n', 'o', 's', 't',};
code UCHAR MA_DarkroomStr11[] = {10, 'S',  10, 't', 2,  't', 'k', 'a', 'm', 'r', 'a',};
code UCHAR SE_DarkroomStr11[] = {11, 'M', 'r', 'a', 6, 'n', 'a', ' ', 's', 'o', 'b', 'a',};
code UCHAR RO_DarkroomStr11[] = {14, 'C', 'a', 'm', 'e', 'r', 42, ' ', 'o', 'b', 's', 'c', 'u', 'r', 42,};
code UCHAR DU_DarkroomStr11[] = {13, 'D', 'o', 'n', 'k', 'e', 'r', 'e', ' ', 'k', 'a', 'm', 'e', 'r',};
code UCHAR RU_DarkroomStr11[] = {14, 161, 128, 146, 144, 143, 149, 32, 148, 136, 146, 144, 143, 132, 143};
code UCHAR SW_DarkroomStr11[] = {7,  'M', 10, 'r', 'k', 'r', 'u', 'm',};
code UCHAR PR_DarkroomStr11[] = {13, 'Q', 'u', 'a', 'r', 't', 'o', ' ', 'e', 's', 'c', 'u', 'r', 'o',};
code UCHAR JA_DarkroomStr11[] = {2, 93, 95,};
code UCHAR CT_DarkroomStr11[] = {2, 60, 62, };
code UCHAR CS_DarkroomStr11[] = {2, 92, 93, };
code UCHAR AR_DarkroomStr11[] = {10,143,223,219,195,222,32,143,206,169,202};

#endif

code UCHAR EN_sRGBStr11[] = {4,"sRGB"};


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

code UCHAR EN_EcoStr11[] = {3, 'E', 'C', 'O', };
code UCHAR FR_EcoStr11[] = {3, 24, 'C', 'O', };
code UCHAR GE_EcoStr11[] = {4, 'S', 'P', 'A', 'R', };
code UCHAR IT_EcoStr11[] = {3, 'E', 'C', 'O', };
code UCHAR SP_EcoStr11[] = {3, 'E', 'C', 'O', };
code UCHAR PO_EcoStr11[] = {3, 'E', 'K', 'O', };
code UCHAR CZ_EcoStr11[] = {3, 'E', 'K', 'O', };
code UCHAR MA_EcoStr11[] = {9, 'T', 'a', 'k', 'a', 'r', 2, 'k', 'o', 's', };
code UCHAR SE_EcoStr11[] = {3, 'E', 'C', 'O', };
code UCHAR RO_EcoStr11[] = {3, 'E', 'C', 'O', };
code UCHAR DU_EcoStr11[] = {3, 'E', 'C', 'O', };
code UCHAR RU_EcoStr11[] = {3, 'E', 'C', 'O', };
code UCHAR SW_EcoStr11[] = {3, 'E', 'K', 'O', };
code UCHAR PR_EcoStr11[] = {3, 'E', 'C', 'O', };
code UCHAR JA_EcoStr11[] = {2, 173, 27, };
code UCHAR CT_EcoStr11[] = {3, 'E', 'C', 'O', };
code UCHAR CS_EcoStr11[] = {2, 164, 165, };
code UCHAR AR_EcoStr11[] = {4,143,135,239,140};

code UCHAR EN_MbookStr11[] = {6, 'M', 45, 'b', 'o', 'o', 'k', };
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
 
code UCHAR EN_UserStr11[] = {4, 'U', 's', 'e', 'r', };
code UCHAR FR_UserStr11[] = {11, 'U', 't', 'i', 'l', 'i', 's', 'a', 't', 'e', 'u', 'r', };
code UCHAR GE_UserStr11[] = {8, 'B', 'e', 'n', 'u', 't', 'z', 'e', 'r', };
code UCHAR IT_UserStr11[] = {6, 'U', 't', 'e', 'n', 't', 'e', };
code UCHAR SP_UserStr11[] = {7, 'U', 's', 'u', 'a', 'r', 'i', 'o', };
code UCHAR PO_UserStr11[] = {6, 'U', 124, 'y', 't', 'k', '.', };
code UCHAR CZ_UserStr11[] = {8, 'U', 26, 'i', 'v', 'a', 't', 'e', 'l', };
code UCHAR MA_UserStr11[] = {11, 'F', 'e', 'l', 'h', 'a', 's', 'z', 'n', 0, 'l', 4, };
code UCHAR SE_UserStr11[] = {8, 'K', 'o', 'r', 'i', 's', 'n', 'i', 'k', };
code UCHAR RO_UserStr11[] = {10, 'U', 't', 'i', 'l', 'i', 'z', 'a', 't', 'o', 'r', };
code UCHAR DU_UserStr11[] = {9, 'G', 'e', 'b', 'r', 'u', 'i', 'k', 'e', 'r', };
code UCHAR RU_UserStr11[] = {8, 167, 136, 127, 155, 141, 136, 131, '.', };
code UCHAR SW_UserStr11[] = {9, 'A', 'n', 'v', 3, 'n', 'd', 'a', 'r', 'e', };
code UCHAR PR_UserStr11[] = {10, 'U', 't', 'i', 'l', 'i', 'z', 'a', 'd', 'o', 'r', };
code UCHAR JA_UserStr11[] = {4, 139, 21, 140, 21, };
code UCHAR CT_UserStr11[] = {3, 130, 131, 132, };
code UCHAR CS_UserStr11[] = {2, 131, 132, };
code UCHAR AR_UserStr11[] = {8,220,165,162,147,175,223,218,136};

code UCHAR EN_LowBlueLightStr12[]={14, 'L', 'o', 'w', ' ', 'B', 'l', 'u', 'e', ' ', 'L', 'i', 'g', 'h', 't', };
code UCHAR JA_LowBlueLightStr12[]={8,163,164,21,30,165,29,166,167}; 
code UCHAR CT_LowBlueLightStr12[]={3,153,127,154};
code UCHAR CS_LowBlueLightStr12[]={3,152,128,153};
code UCHAR AR_LowBlueLightStr12[]={14, 'L', 'o', 'w', ' ', 'B', 'l', 'u', 'e', ' ', 'L', 'i', 'g', 'h', 't', };

code UCHAR *PictureModeTab11[] = {
         EN_StanddardStr11,
         FR_StanddardStr11,
         GE_StanddardStr11,
         IT_StanddardStr11,
         SP_StanddardStr11,
         PO_StanddardStr11,
         CZ_StanddardStr11,
         MA_StanddardStr11,
         SE_StanddardStr11,
         RO_StanddardStr11,
         DU_StanddardStr11,
         RU_StanddardStr11,
         SW_StanddardStr11,
         PR_StanddardStr11,
         JA_StanddardStr11,
         CT_StanddardStr11,
         CS_StanddardStr11,
         AR_StanddardStr11,
#if ENABLE_PICTURE_MODE_REC709 == ON     
        EN_Rec709Str11,
        FR_Rec709Str11,
        GE_Rec709Str11,
        IT_Rec709Str11,
        SP_Rec709Str11,
        PO_Rec709Str11,
        CZ_Rec709Str11,
        MA_Rec709Str11,
        SE_Rec709Str11,
        RO_Rec709Str11,
        DU_Rec709Str11,
        RU_Rec709Str11,
        SW_Rec709Str11,
        PR_Rec709Str11,
        JA_Rec709Str11,
        CT_Rec709Str11,
        CS_Rec709Str11,
        AR_Rec709Str11,
#endif     
    
     EN_sRGBStr11,
     EN_sRGBStr11,//FR
     EN_sRGBStr11,//GE
     EN_sRGBStr11,//IT
     EN_sRGBStr11,//SP
     EN_sRGBStr11,//PO
     EN_sRGBStr11,//CZ
     EN_sRGBStr11,//MA
     EN_sRGBStr11,//SE
     EN_sRGBStr11,//RO
     EN_sRGBStr11,//DU
     EN_sRGBStr11,//RU
     EN_sRGBStr11,//SW
     EN_sRGBStr11,//PR
     EN_sRGBStr11,//JA
     EN_sRGBStr11,//CT
     EN_sRGBStr11,//CS
     EN_sRGBStr11,//AR

#if	ENABLE_PICTURE_MODE_CAD == ON
    EN_CADStr11,
    FR_CADStr11,
    GE_CADStr11,
    IT_CADStr11,
    SP_CADStr11,
    PO_CADStr11,
    CZ_CADStr11,
    MA_CADStr11,
    SE_CADStr11,
    RO_CADStr11,
    DU_CADStr11,
    RU_CADStr11,
    SW_CADStr11,
    PR_CADStr11,
    JA_CADStr11,
    CT_CADStr11,
    CS_CADStr11,
    AR_CADStr11,
#endif
#if ENABLE_PICTURE_MODE_ANIMATION == ON
    EN_AnimationStr11,
    FR_AnimationStr11,
    GE_AnimationStr11,
    IT_AnimationStr11,
    SP_AnimationStr11,
    PO_AnimationStr11,
    CZ_AnimationStr11,
    MA_AnimationStr11,
    SE_AnimationStr11,
    RO_AnimationStr11,
    DU_AnimationStr11,
    RU_AnimationStr11,
    SW_AnimationStr11,
    PR_AnimationStr11,
    JA_AnimationStr11,
    CT_AnimationStr11,
    CS_AnimationStr11,
    AR_AnimationStr11,
#endif
#if	ENABLE_PRESENTATION_MODE == ON
    EN_PresentationStr11,
    FR_PresentationStr11,
    GE_PresentationStr11,
    IT_PresentationStr11,
    SP_PresentationStr11,
    PO_PresentationStr11,
    CZ_PresentationStr11,
    MA_PresentationStr11,
    SE_PresentationStr11,
    RO_PresentationStr11,
    DU_PresentationStr11,
    RU_PresentationStr11,
    SW_PresentationStr11,
    PR_PresentationStr11,
    JA_PresentationStr11,
    CT_PresentationStr11,
    CS_PresentationStr11,
    AR_PresentationStr11,
#endif
     EN_LowBlueLightStr12,
     EN_LowBlueLightStr12,
     EN_LowBlueLightStr12,
     EN_LowBlueLightStr12,
     EN_LowBlueLightStr12,
     EN_LowBlueLightStr12,
     EN_LowBlueLightStr12,
     EN_LowBlueLightStr12,
     EN_LowBlueLightStr12,
     EN_LowBlueLightStr12,
     EN_LowBlueLightStr12,
     EN_LowBlueLightStr12,
     EN_LowBlueLightStr12,
     EN_LowBlueLightStr12,
     JA_LowBlueLightStr12,
     CT_LowBlueLightStr12,
     CS_LowBlueLightStr12,
     AR_LowBlueLightStr12, 
#if ENABLE_PICTURE_MODE_MOVIE == ON              
     EN_MovieStr11,
     FR_MovieStr11,
     GE_MovieStr11,
     IT_MovieStr11,
     SP_MovieStr11,
     PO_MovieStr11,
     CZ_MovieStr11,
     MA_MovieStr11,
     SE_MovieStr11,
     RO_MovieStr11,
     DU_MovieStr11,
     RU_MovieStr11,
     SW_MovieStr11,
     PR_MovieStr11,
     JA_MovieStr11,
     CT_MovieStr11,
     CS_MovieStr11,
     AR_MovieStr11,
#endif
#if ENABLE_PICTURE_MODE_GAME == ON
     EN_GameStr11,
     FR_GameStr11,
     GE_GameStr11,
     IT_GameStr11,
     SP_GameStr11,
     PO_GameStr11,
     CZ_GameStr11,
     MA_GameStr11,
     SE_GameStr11,
     RO_GameStr11,
     DU_GameStr11,
     RU_GameStr11,
     SW_GameStr11,
     PR_GameStr11,
     JA_GameStr11,
     CT_GameStr11,
     CS_GameStr11,
     AR_GameStr11,
#endif
#if ENABLE_PICTURE_MODE_PHOTO == ON
     EN_PhotoStr11,
     FR_PhotoStr11,
     GE_PhotoStr11,
     IT_PhotoStr11,
     SP_PhotoStr11,
     PO_PhotoStr11,
     CZ_PhotoStr11,
     MA_PhotoStr11,
     SE_PhotoStr11,
     RO_PhotoStr11,
     DU_PhotoStr11,
     RU_PhotoStr11,
     SW_PhotoStr11,
     PR_PhotoStr11,
     JA_PhotoStr11,
     CT_PhotoStr11,
     CS_PhotoStr11,
     CS_PhotoStr11,
#endif
#if	ENABLE_PICTURE_MODE_DARKROOM == ON     
    EN_DarkroomStr11,
    FR_DarkroomStr11,
    GE_DarkroomStr11,
    IT_DarkroomStr11,
    SP_DarkroomStr11,
    PO_DarkroomStr11,
    CZ_DarkroomStr11,
    MA_DarkroomStr11,
    SE_DarkroomStr11,
    RO_DarkroomStr11,
    DU_DarkroomStr11,
    RU_DarkroomStr11,
    SW_DarkroomStr11,
    PR_DarkroomStr11,
    JA_DarkroomStr11,
    CT_DarkroomStr11,
    CS_DarkroomStr11,
    AR_DarkroomStr11,
#endif     
     EN_EcoStr11,
     FR_EcoStr11,
     GE_EcoStr11,
     IT_EcoStr11,
     SP_EcoStr11,
     PO_EcoStr11,
     CZ_EcoStr11,
     MA_EcoStr11,
     SE_EcoStr11,
     RO_EcoStr11,
     DU_EcoStr11,
     RU_EcoStr11,
     SW_EcoStr11,
     PR_EcoStr11,
     JA_EcoStr11,
     CT_EcoStr11,
     CS_EcoStr11,
     AR_EcoStr11,
#if ENABLE_PICTURE_MODE_MBOOK == ON
     EN_MbookStr11,
     EN_MbookStr11,//FR
     EN_MbookStr11,//GE
     EN_MbookStr11,//IT
     EN_MbookStr11,//SP
     EN_MbookStr11,//PO
     EN_MbookStr11,//CZ
     EN_MbookStr11,//MA
     EN_MbookStr11,//SE
     EN_MbookStr11,//RO
     EN_MbookStr11,//DU
     EN_MbookStr11,//RU
     EN_MbookStr11,//SW
     EN_MbookStr11,//PR
     EN_MbookStr11,//JA
     EN_MbookStr11,//CT
     EN_MbookStr11,//CS
     EN_MbookStr11,//AR
#endif
     EN_UserStr11,
     FR_UserStr11,
     GE_UserStr11,
     IT_UserStr11,
     SP_UserStr11,
     PO_UserStr11,
     CZ_UserStr11,
     MA_UserStr11,
     SE_UserStr11,
     RO_UserStr11,
     DU_UserStr11,
     RU_UserStr11,
     SW_UserStr11,
     PR_UserStr11,
     JA_UserStr11,
     CT_UserStr11,
     CS_UserStr11,
     AR_UserStr11,
};


code UCHAR *DualViewTab11[] = {
    EN_sRGBStr11,
    EN_sRGBStr11,//FR
    EN_sRGBStr11,//GE
    EN_sRGBStr11,//IT
    EN_sRGBStr11,//SP
    EN_sRGBStr11,//PO
    EN_sRGBStr11,//CZ
    EN_sRGBStr11,//MA
    EN_sRGBStr11,//SE
    EN_sRGBStr11,//RO
    EN_sRGBStr11,//DU
    EN_sRGBStr11,//RU
    EN_sRGBStr11,//SW
    EN_sRGBStr11,//PR
    EN_sRGBStr11,//JA
    EN_sRGBStr11,//CT
    EN_sRGBStr11,//CS
    EN_sRGBStr11,//AR

     EN_sRGBStr11,
     EN_sRGBStr11,//FR
     EN_sRGBStr11,//GE
     EN_sRGBStr11,//IT
     EN_sRGBStr11,//SP
     EN_sRGBStr11,//PO
     EN_sRGBStr11,//CZ
     EN_sRGBStr11,//MA
     EN_sRGBStr11,//SE
     EN_sRGBStr11,//RO
     EN_sRGBStr11,//DU
     EN_sRGBStr11,//RU
     EN_sRGBStr11,//SW
     EN_sRGBStr11,//PR
     EN_sRGBStr11,//JA
     EN_sRGBStr11,//CT
     EN_sRGBStr11,//CS
     EN_sRGBStr11,//AR

#if	ENABLE_PICTURE_MODE_CAD == ON
    EN_CADStr11,
    FR_CADStr11,
    GE_CADStr11,
    IT_CADStr11,
    SP_CADStr11,
    PO_CADStr11,
    CZ_CADStr11,
    MA_CADStr11,
    SE_CADStr11,
    RO_CADStr11,
    DU_CADStr11,
    RU_CADStr11,
    SW_CADStr11,
    PR_CADStr11,
    JA_CADStr11,
    CT_CADStr11,
    CS_CADStr11,
    AR_CADStr11,
#endif
#if ENABLE_PICTURE_MODE_ANIMATION == ON
    EN_AnimationStr11,
    FR_AnimationStr11,
    GE_AnimationStr11,
    IT_AnimationStr11,
    SP_AnimationStr11,
    PO_AnimationStr11,
    CZ_AnimationStr11,
    MA_AnimationStr11,
    SE_AnimationStr11,
    RO_AnimationStr11,
    DU_AnimationStr11,
    RU_AnimationStr11,
    SW_AnimationStr11,
    PR_AnimationStr11,
    JA_AnimationStr11,
    CT_AnimationStr11,
    CS_AnimationStr11,
    AR_AnimationStr11,
#endif    
     EN_LowBlueLightStr12,
     EN_LowBlueLightStr12,
     EN_LowBlueLightStr12,
     EN_LowBlueLightStr12,
     EN_LowBlueLightStr12,
     EN_LowBlueLightStr12,
     EN_LowBlueLightStr12,
     EN_LowBlueLightStr12,
     EN_LowBlueLightStr12,
     EN_LowBlueLightStr12,
     EN_LowBlueLightStr12,
     EN_LowBlueLightStr12,
     EN_LowBlueLightStr12,
     EN_LowBlueLightStr12,
     JA_LowBlueLightStr12,
     CT_LowBlueLightStr12,
     CS_LowBlueLightStr12,
     AR_LowBlueLightStr12, 
#if	ENABLE_PICTURE_MODE_DARKROOM == ON     
        EN_DarkroomStr11,
        FR_DarkroomStr11,
        GE_DarkroomStr11,
        IT_DarkroomStr11,
        SP_DarkroomStr11,
        PO_DarkroomStr11,
        CZ_DarkroomStr11,
        MA_DarkroomStr11,
        SE_DarkroomStr11,
        RO_DarkroomStr11,
        DU_DarkroomStr11,
        RU_DarkroomStr11,
        SW_DarkroomStr11,
        PR_DarkroomStr11,
        JA_DarkroomStr11,
        CT_DarkroomStr11,
        CS_DarkroomStr11,
        AR_DarkroomStr11,
#endif     
     EN_UserStr11,
     FR_UserStr11,
     GE_UserStr11,
     IT_UserStr11,
     SP_UserStr11,
     PO_UserStr11,
     CZ_UserStr11,
     MA_UserStr11,
     SE_UserStr11,
     RO_UserStr11,
     DU_UserStr11,
     RU_UserStr11,
     SW_UserStr11,
     PR_UserStr11,
     JA_UserStr11,
     CT_UserStr11,
     CS_UserStr11,
     AR_UserStr11,
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
code UCHAR AR_NosyncStr[] = {26,33,32,143,168,137,178,130,32,236,126,32,225,198,32,205,179,215,218,136,32,221,147,238,32,221,218};

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
    AR_NosyncStr,
};


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
code UCHAR AR_NocableStr[] ={18,33,32,217,183,147,222,32,217,140,137,214,32,165,154,233,238,32,247};

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
    AR_NocableStr,
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
code UCHAR AR_OutOfRangeStr[]={13,33,32,208,137,191,227,218,136,32,153,168,137,162};

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
    AR_OutOfRangeStr,
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
 code UCHAR AR_OSDLCOKEDStr[]={7,79,83,68,32,217,207,210};

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
 code UCHAR AR_OSDUNLCOKEDStr[]={13,79,83,68,32,217,207,210,32,123,137,203,218,130};

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
AR_OSDUNLCOKEDStr,

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
AR_OSDLCOKEDStr,

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
 code UCHAR AR_NonPreSentMode_Str[]={22,208,140,175,223,218,136,32,189,140,186,218,136,32,123,137,203,218,130,32,197,186,232};

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
       AR_NonPreSentMode_Str,
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
code UCHAR  AR_DialogReminderStr[]={10, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, };


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
    AR_DialogReminderStr,

};

  code UCHAR EN_ResNoteStr[]={28, 'S', 'u', 'g', 'g', 'e', 's', 't', 'e', 'd', ' ', 'M', 'o', 'n', 'i', 't', 'o', 'r', ' ', 'R', 'e', 's', 'o', 'l', 'u', 't', 'i', 'o', 'n', };
  code UCHAR FR_ResNoteStr[]={31, 'R', 2, 's', 'o', 'l', 'u', 't', 'i', 'o', 'n', ' ', 's', 'u', 'g', 'g', 2, 'r', 2, 'e', ' ', 'd', 'u', ' ', 'm', 'o', 'n', 'i', 't', 'e', 'u', 'r', };
  code UCHAR GE_ResNoteStr[]={27, 'E', 'm', 'p', 'f', 'o', 'h', 'l', 'e', 'n', 'e', ' ', 'M', 'o', 'n', 'i', 't', 'o', 'r', 'a', 'u', 'f', 'l', 10, 's', 'u', 'n', 'g', };
  code UCHAR IT_ResNoteStr[]={29, 'R', 'i', 's', 'o', 'l', 'u', 'z', 'i', 'o', 'n', 'e', ' ', 'm', 'o', 'n', 'i', 't', 'o', 'r', ' ', 's', 'u', 'g', 'g', 'e', 'r', 'i', 't', 'a', };
  code UCHAR SP_ResNoteStr[]={33, 'R', 'e', 's', 'o', 'l', 'u', 'c', 'i', 4, 'n', ' ', 'd', 'e', 'l', ' ', 'm', 'o', 'n', 'i', 't', 'o', 'r', ' ', 'a', 'c', 'o', 'n', 's', 'e', 'j', 'a', 'd', 'a', };
  code UCHAR PO_ResNoteStr[]={26, 'S', 'u', 'g', 'e', 'r', 'o', 'w', 'a', 'n', 'a', ' ', 'r', 'o', 'z', 'd', 'z', '.',' ', 'm', 'o', 'n', 'i', 't', 'o', 'r', 'a', };
  code UCHAR CZ_ResNoteStr[]={29, 'D', 'o', 'p', 'o', 'r', 'u', 6, 'e', 'n', 2, ' ', 'r', 'o', 'z', 'l', 'i', 20, 'e', 'n', 1, ' ', 'm', 'o', 'n', 'i', 't', 'o', 'r', 'u', };
  code UCHAR MA_ResNoteStr[]={27, 'M', 'o', 'n', 'i', 't', 'o', 'r', ' ', 'j', 'a', 'v', 'a', 's', 'o', 'l', 't', ' ', 'f', 'e', 'l', 'b', 'o', 'n', 't', 0, 's', 'a', };
  code UCHAR SE_ResNoteStr[]={31, 'P', 'r', 'e', 'p', 'o', 'r', 'u', 6, 'e', 'n', 'a', ' ', 'r', 'a', 'z', 'l', 'u', 6, 'i', 'v', 'o', 's', 't', ' ', 'z', 'a', 's', 'l', 'o', 'n', 'a', };
  code UCHAR RO_ResNoteStr[]={29, 'R', 'e', 'z', 'o', 'l', 'u', 124, 'i', 'e', ' ', 'r', 'e', 'c', 'o', 'm', 'a', 'n', 'd', 'a', 't', 125, ' ', 'm', 'o', 'n', 'i', 't', 'o', 'r', };
  code UCHAR DU_ResNoteStr[]={27, 'A', 'a', 'n', 'b', 'e', 'v', 'o', 'l', 'e', 'n', ' ', 'm', 'o', 'n', 'i', 't', 'o', 'r', 'r', 'e', 's', 'o', 'l', 'u', 't', 'i', 'e', };
  code UCHAR RU_ResNoteStr[]={23, 156, 128, 148, 136, 146, '.', ' ', 133, 143, 141, 133, 128, 177, '.', ' ', 146, 136, 144, 124, 132, 136, 133, 143, };
  code UCHAR SW_ResNoteStr[]={26, 'F', 10, 'r', 'e', 's', 'l', 'a', 'g', 'e', 'n', ' ', 's', 'k', 3, 'r', 'm', 'u', 'p', 'p', 'l', 10, 's', 'n', 'i', 'n', 'g', };
  code UCHAR PR_ResNoteStr[]={29, 'R', 'e', 's', 'o', 'l', 'u', 7, 123, 'o', ' ', 'd', 'o', ' ', 'M', 'o', 'n', 'i', 't', 'o', 'r', ' ', 'S', 'u', 'g', 'e', 'r', 'i', 'd', 'a', };
  code UCHAR JA_ResNoteStr[]={12, 219, 220, 221, 222, 223, 159, 224, 225, 21, 180, 26, 124, };
  code UCHAR CT_ResNoteStr[]={9, 213, 214, 215, 0, 1, 211, 177, 178, 28, };
  code UCHAR CS_ResNoteStr[]={11, 212, 213, 214, 131, 215, 0, 1, 210, 176, 177, 19, };
  code UCHAR AR_ResNoteStr[]={24, 156, 168, 146, 211, 223, 218, 136, 32, 143, 178, 137, 178, 218, 136, 32, 143, 210, 164, 32, 234, 233, 146, 175, 222};
  
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
    AR_ResNoteStr,
};

code UCHAR ResolutionStr[] ={9,50,53,54,48,'x',49,52,52,48};
code UCHAR ResolutionVGAStr[] ={9,49,57,50,48,'x',49,48,56,48};

code UCHAR EN_CustomKey1SaveStr1[] = {26, 'C','u','s','t','o','m',32,'k','e','y',32,49,32,'s','e','t','t','i','n','g',32,'s','a','v','e','d', };
code UCHAR FR_CustomKey1SaveStr1[] = {35, 'P', 'a', 'r', 'a', 'm', 29,  't', 'r', 'e', ' ', 'T', 'o', 'u', 'c', 'h', 'e', ' ', 'p', 'e', 'r', 's', 'o', ' ', '1', ' ', 'e', 'n', 'r', 'e', 'g', 'i', 's', 't',  'r',2,};
code UCHAR GE_CustomKey1SaveStr1[] = {40, 'B', 'e', 'n', 'u', 't', 'z', 'e', 'r', '-', 'T', 'a', 's', 't', 'e', ' ', '1', ' ', 'E', 'i', 'n', 's', 't', 'e', 'l', 'l', 'u', 'n', 'g',' ', 'g', 'e', 's', 'p', 'e', 'i', 'c', 'h', 'e', 'r', 't',};
code UCHAR IT_CustomKey1SaveStr1[] = {40, 'I', 'm', 'p', 'o', 's', 't', 'a', 'z', 'i', 'o', 'n', 'e', ' ','T', 'a', 's', 't', 'o', ' ', 'p', 'e', 'r', 's', 'o', 'n', 'a', 'l', 'i', 'z', 'z', ' ', '1', ' ','s', 'a', 'l', 'v', 'a', 't', 'a',  };
code UCHAR SP_CustomKey1SaveStr1[] = {35,  'A', 'j', 'u', 's', 't', 'e', ' ','T', 'e', 'c', 'l', 'a', ' ', 'p', 'e', 'r', 's', 'o', 'n', 'a', 'l', 'i', 'z', '.', ' ', '1', ' ', 'g', 'u', 'a', 'r', 'd', 'a', 'd', 'o',};
code UCHAR PO_CustomKey1SaveStr1[] = {40, 'Z', 'a', 'p', 'i', 's', 'a','n', 'o', ' ', 'u', 's', 't', 'a', 'w', 'i', 'e', 'n', 'i', 'e',' ','p', 'r', 'z', 'y', 'c', 'i', 's', 'k', 'u',' ', 'n', 'i', 'e', 's', 't', 'a', 'n', '.', ' ', '1', };
code UCHAR CZ_CustomKey1SaveStr1[] = {35,  'N', 'a', 's', 't', 'a', 'v', 'e', 'n', 1, ' ', 'V', 'l', 'a', 's', 't', 'n', 1, ' ', 'k', 'l', 0, 'v', 'e', 's', 'y', ' ', '1',  ' ', 'u', 'l', 'o', 26, 'e', 'n','o',};
code UCHAR MA_CustomKey1SaveStr1[] = {33, 'E', 'g', 'y', 2, 'n', 'i', ' ', 'k', 'u', 'l', 'c', 's', ' ', '1',  ' ', 'b', 'e', 0, 'l', 'l', 1, 't', 0, 's',' ','e', 'l', 'm', 'e', 'n', 't', 'v', 'e', };
code UCHAR SE_CustomKey1SaveStr1[] = {38, 'P', 'o', 's', 't', 'a', 'v', 'k', 'a',' ', 'k', 'o', 'r', 'i', 's', 'n', 'i', 6, 'k', 'a', ' ', 't', 'i', 'p', 'k', 'e', ' ', '1',  ' ', 's', 'p', 'r', 'e', 'm', 'l','j', 'e', 'n', 'a',};
code UCHAR RO_CustomKey1SaveStr1[] = {34,  'S', 'e', 't', 'a','r', 'e',' ','t', 'a', 's', 't', 125, ' ', 'p', 'e', 'r', 's', 'o', 'n', 'a', 'l', 'i', 'z', '.', ' ', '1',  ' ', 's', 'a', 'l', 'v', 'a', 't',125,};
code UCHAR DU_CustomKey1SaveStr1[] = {40, 'A', 'a', 'n', 'g', 'e', 'p', 'a', 's', 't', 'e', ' ', 't', 'o', 'e', 't', 's', ' ', '1',  '-', 'i', 'n', 's', 't', 'e', 'l', 'l', 'i', 'n', 'g', ' ', 'o','p', 'g', 'e', 's', 'l', 'a', 'g', 'e', 'n',};
code UCHAR RU_CustomKey1SaveStr1[] = {39, 158, 143, 125, 132, 133, 136, 129, 148, 143,' ',148, 144, 136, 126, 148, 124, ' ', '"', 167, 136, 127, 155, 141, 136, 131, '.', '"', ' ', '1', ' ', 125, 136, 138, 133,143, 144, 128, 144,143, };
code UCHAR SW_CustomKey1SaveStr1[] = {39, 'I', 'n', 's', 't', 3, 'l', 'l','n', 'i', 'n', 'g',' ','f', 10, 'r',' ', 'A', 'n', 'p', 'a', 's', 's', 'a', 'd', ' ', 'k', 'n', 'a', 'p', 'p', ' ', '1', ' ','s', 'p', 'a', 'r', 'a','d', };
code UCHAR PR_CustomKey1SaveStr1[] = {34,  'D', 'e', 'f', 'i', 'n',  'i', 7, 123, 'o',' ', 'c', 'h', 'a', 'v', 'e', ' ', 'p', 'e', 'r', 's', 'o', 'n', '.', ' ', '1',  ' ', 'g', 'u', 'a', 'r', 'd', 'a','d', 'a', };
code UCHAR JA_CustomKey1SaveStr1[] = {20, 209, 138, 210, 211, ' ', 173, 18, ' ', '1', 148, 212, 213, 24, 214, 215, 27, 28, 29, 160, 216, };
code UCHAR CT_CustomKey1SaveStr1[] = {11, 143, 221, 222, 2, 220, 212, ' ', '1', ' ',  147, 133, };
code UCHAR CS_CustomKey1SaveStr1[] = {12, 2, 133, 134, 211, ' ', '1',  ' ', 145, 13, 91,220, 221, };
code UCHAR AR_CustomKey1SaveStr1[] = {25,49,32,181,183,163,222,32,156,137,147,207,222,32,164,136,165,198,130,32,193,207,158,32,220,146};

code UCHAR EN_CustomKey2SaveStr1[] = {26, 'C','u','s','t','o','m',32,'k','e','y',32,50,32,'s','e','t','t','i','n','g',32,'s','a','v','e','d', };
code UCHAR FR_CustomKey2SaveStr1[] = {35, 'P', 'a', 'r', 'a', 'm', 29,  't', 'r', 'e', ' ', 'T', 'o', 'u', 'c', 'h', 'e', ' ', 'p', 'e', 'r', 's', 'o', ' ', '2', ' ', 'e', 'n', 'r', 'e', 'g', 'i', 's', 't',  'r',2,};
code UCHAR GE_CustomKey2SaveStr1[] = {40, 'B', 'e', 'n', 'u', 't', 'z', 'e', 'r', '-', 'T', 'a', 's', 't', 'e', ' ', '2', ' ', 'E', 'i', 'n', 's', 't', 'e', 'l', 'l', 'u', 'n', 'g',' ', 'g', 'e', 's', 'p', 'e', 'i', 'c', 'h', 'e', 'r', 't',};
code UCHAR IT_CustomKey2SaveStr1[] = {40, 'I', 'm', 'p', 'o', 's', 't', 'a', 'z', 'i', 'o', 'n', 'e', ' ','T', 'a', 's', 't', 'o', ' ', 'p', 'e', 'r', 's', 'o', 'n', 'a', 'l', 'i', 'z', 'z', ' ', '2', ' ','s', 'a', 'l', 'v', 'a', 't', 'a',};
code UCHAR SP_CustomKey2SaveStr1[] = {35,  'A', 'j', 'u', 's', 't', 'e', ' ','T', 'e', 'c', 'l', 'a', ' ', 'p', 'e', 'r', 's', 'o', 'n', 'a', 'l', 'i', 'z', '.', ' ', '2', ' ', 'g', 'u', 'a', 'r', 'd', 'a', 'd', 'o',};
code UCHAR PO_CustomKey2SaveStr1[] = {40, 'Z', 'a', 'p', 'i', 's', 'a','n', 'o', ' ', 'u', 's', 't', 'a', 'w', 'i', 'e', 'n', 'i', 'e',' ','p', 'r', 'z', 'y', 'c', 'i', 's', 'k', 'u',' ', 'n', 'i', 'e', 's', 't', 'a', 'n', '.', ' ', '2', };
code UCHAR CZ_CustomKey2SaveStr1[] = {35,  'N', 'a', 's', 't', 'a', 'v', 'e', 'n', 1, ' ', 'V', 'l', 'a', 's', 't', 'n', 1, ' ', 'k', 'l', 0, 'v', 'e', 's', 'y', ' ', '2',  ' ', 'u', 'l', 'o', 26, 'e', 'n','o',};
code UCHAR MA_CustomKey2SaveStr1[] = {33, 'E', 'g', 'y', 2, 'n', 'i', ' ', 'k', 'u', 'l', 'c', 's', ' ', '2',  ' ', 'b', 'e', 0, 'l', 'l', 1, 't', 0, 's',' ','e', 'l', 'm', 'e', 'n', 't', 'v', 'e', };
code UCHAR SE_CustomKey2SaveStr1[] = {38, 'P', 'o', 's', 't', 'a', 'v', 'k', 'a',' ', 'k', 'o', 'r', 'i', 's', 'n', 'i', 6, 'k', 'a', ' ', 't', 'i', 'p', 'k', 'e', ' ', '2',  ' ', 's', 'p', 'r', 'e', 'm', 'l','j', 'e', 'n', 'a',};
code UCHAR RO_CustomKey2SaveStr1[] = {34,  'S', 'e', 't', 'a','r', 'e',' ','t', 'a', 's', 't', 125, ' ', 'p', 'e', 'r', 's', 'o', 'n', 'a', 'l', 'i', 'z', '.', ' ', '2',  ' ', 's', 'a', 'l', 'v', 'a', 't',125,};
code UCHAR DU_CustomKey2SaveStr1[] = {40, 'A', 'a', 'n', 'g', 'e', 'p', 'a', 's', 't', 'e', ' ', 't', 'o', 'e', 't', 's', ' ', '2',  '-', 'i', 'n', 's', 't', 'e', 'l', 'l', 'i', 'n', 'g', ' ', 'o','p', 'g', 'e', 's', 'l', 'a', 'g', 'e', 'n',};
code UCHAR RU_CustomKey2SaveStr1[] = {39, 158, 143, 125, 132, 133, 136, 129, 148, 143,' ',148, 144, 136, 126, 148, 124, ' ', '"', 167, 136, 127, 155, 141, 136, 131, '.', '"', ' ', '2', ' ', 125, 136, 138, 133,143, 144, 128, 144,143, };
code UCHAR SW_CustomKey2SaveStr1[] = {39, 'I', 'n', 's', 't', 3, 'l', 'l','n', 'i', 'n', 'g',' ','f', 10, 'r',' ', 'A', 'n', 'p', 'a', 's', 's', 'a', 'd', ' ', 'k', 'n', 'a', 'p', 'p', ' ', '2', ' ','s', 'p', 'a', 'r', 'a','d', };
code UCHAR PR_CustomKey2SaveStr1[] = {34,  'D', 'e', 'f', 'i', 'n',  'i', 7, 123, 'o',' ', 'c', 'h', 'a', 'v', 'e', ' ', 'p', 'e', 'r', 's', 'o', 'n', '.', ' ', '2',  ' ', 'g', 'u', 'a', 'r', 'd', 'a','d', 'a', };
code UCHAR JA_CustomKey2SaveStr1[] = {20, 209, 138, 210, 211, ' ', 173, 18, ' ', '2', 148, 212, 213, 24, 214, 215, 27, 28, 29, 160, 216, };
code UCHAR CT_CustomKey2SaveStr1[] = {11, 143, 221, 222, 2, 220, 212, ' ', '2', ' ',  147, 133, };
code UCHAR CS_CustomKey2SaveStr1[] = {12, 2, 133, 134, 211, ' ', '2',  ' ', 145, 13, 91,220, 221, };
code UCHAR AR_CustomKey2SaveStr1[] = {25,50,32,181,183,163,222,32,156,137,147,207,222,32,164,136,165,198,130,32,193,207,158,32,220,146};

code UCHAR EN_CustomKey3SaveStr1[] = {26, 'C','u','s','t','o','m',32,'k','e','y',32,51,32,'s','e','t','t','i','n','g',32,'s','a','v','e','d', };
code UCHAR FR_CustomKey3SaveStr1[] = {35, 'P', 'a', 'r', 'a', 'm', 29,  't', 'r', 'e', ' ', 'T', 'o', 'u', 'c', 'h', 'e', ' ', 'p', 'e', 'r', 's', 'o', ' ', '3', ' ', 'e', 'n', 'r', 'e', 'g', 'i', 's', 't',  'r',2,};
code UCHAR GE_CustomKey3SaveStr1[] = {40, 'B', 'e', 'n', 'u', 't', 'z', 'e', 'r', '-', 'T', 'a', 's', 't', 'e', ' ', '3', ' ', 'E', 'i', 'n', 's', 't', 'e', 'l', 'l', 'u', 'n', 'g',' ', 'g', 'e', 's', 'p', 'e', 'i', 'c', 'h', 'e', 'r', 't',};
code UCHAR IT_CustomKey3SaveStr1[] = {40, 'I', 'm', 'p', 'o', 's', 't', 'a', 'z', 'i', 'o', 'n', 'e', ' ','T', 'a', 's', 't', 'o', ' ', 'p', 'e', 'r', 's', 'o', 'n', 'a', 'l', 'i', 'z', 'z', ' ', '3', ' ','s', 'a', 'l', 'v', 'a', 't', 'a',};
code UCHAR SP_CustomKey3SaveStr1[] = {35,  'A', 'j', 'u', 's', 't', 'e', ' ','T', 'e', 'c', 'l', 'a', ' ', 'p', 'e', 'r', 's', 'o', 'n', 'a', 'l', 'i', 'z', '.', ' ', '3', ' ', 'g', 'u', 'a', 'r', 'd', 'a', 'd', 'o',};
code UCHAR PO_CustomKey3SaveStr1[] = {40, 'Z', 'a', 'p', 'i', 's', 'a','n', 'o', ' ', 'u', 's', 't', 'a', 'w', 'i', 'e', 'n', 'i', 'e',' ','p', 'r', 'z', 'y', 'c', 'i', 's', 'k', 'u',' ', 'n', 'i', 'e', 's', 't', 'a', 'n', '.', ' ', '3', };
code UCHAR CZ_CustomKey3SaveStr1[] = {35,  'N', 'a', 's', 't', 'a', 'v', 'e', 'n', 1, ' ', 'V', 'l', 'a', 's', 't', 'n', 1, ' ', 'k', 'l', 0, 'v', 'e', 's', 'y', ' ', '3',  ' ', 'u', 'l', 'o', 26, 'e', 'n','o',};
code UCHAR MA_CustomKey3SaveStr1[] = {33, 'E', 'g', 'y', 2, 'n', 'i', ' ', 'k', 'u', 'l', 'c', 's', ' ', '3',  ' ', 'b', 'e', 0, 'l', 'l', 1, 't', 0, 's',' ','e', 'l', 'm', 'e', 'n', 't', 'v', 'e', };
code UCHAR SE_CustomKey3SaveStr1[] = {38, 'P', 'o', 's', 't', 'a', 'v', 'k', 'a',' ', 'k', 'o', 'r', 'i', 's', 'n', 'i', 6, 'k', 'e', ' ', 't', 'i', 'p', 'k', 'a', ' ', '3',  ' ', 's', 'p', 'r', 'e', 'm', 'l','j', 'e', 'n', 'a',};
code UCHAR RO_CustomKey3SaveStr1[] = {34,  'S', 'e', 't', 'a','r', 'e',' ','t', 'a', 's', 't', 125, ' ', 'p', 'e', 'r', 's', 'o', 'n', 'a', 'l', 'i', 'z', '.', ' ', '3',  ' ', 's', 'a', 'l', 'v', 'a', 't',125,};
code UCHAR DU_CustomKey3SaveStr1[] = {40, 'A', 'a', 'n', 'g', 'e', 'p', 'a', 's', 't', 'e', ' ', 't', 'o', 'e', 't', 's', ' ', '3',  '-', 'i', 'n', 's', 't', 'e', 'l', 'l', 'i', 'n', 'g', ' ', 'o','p', 'g', 'e', 's', 'l', 'a', 'g', 'e', 'n',};
code UCHAR RU_CustomKey3SaveStr1[] = {39, 158, 143, 125, 132, 133, 136, 129, 148, 143,' ',148, 144, 136, 126, 148, 124, ' ', '"', 167, 136, 127, 155, 141, 136, 131, '.', '"', ' ', '3', ' ', 125, 136, 138, 133,143, 144, 128, 144,143, };
code UCHAR SW_CustomKey3SaveStr1[] = {39, 'I', 'n', 's', 't', 3, 'l', 'l','n', 'i', 'n', 'g',' ','f', 10, 'r',' ', 'A', 'n', 'p', 'a', 's', 's', 'a', 'd', ' ', 'k', 'n', 'a', 'p', 'p', ' ', '3', ' ','s', 'p', 'a', 'r', 'a','d', };
code UCHAR PR_CustomKey3SaveStr1[] = {34,  'D', 'e', 'f', 'i', 'n',  'i', 7, 123, 'o',' ', 'c', 'h', 'a', 'v', 'e', ' ', 'p', 'e', 'r', 's', 'o', 'n', '.', ' ', '3',  ' ', 'g', 'u', 'a', 'r', 'd', 'a','d', 'a', };
code UCHAR JA_CustomKey3SaveStr1[] = {20, 209, 138, 210, 211, ' ', 173, 18, ' ', '3', 148, 212, 213, 24, 214, 215, 27, 28, 29, 160, 216, };
code UCHAR CT_CustomKey3SaveStr1[] = {11, 143, 221, 222, 2, 220, 212, ' ', '3', ' ',  147, 133, };
code UCHAR CS_CustomKey3SaveStr1[] = {12, 2, 133, 134, 211, ' ', '3',  ' ', 145, 13, 91,220, 221, };
code UCHAR AR_CustomKey3SaveStr1[] = {25,51,32,181,183,163,222,32,156,137,147,207,222,32,164,136,165,198,130,32,193,207,158,32,220,146};

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
     AR_CustomKey1SaveStr1,
     
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
     AR_CustomKey2SaveStr1,
     
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
     AR_CustomKey3SaveStr1,
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

code UCHAR AR_OSDUNLCOKKEYStr[]={31,143,165,223,218,32,156,137,147,207,222,32,236,126,32,235,219,198,32,168,137,169,223,147,174,137,140,32,189,203,186,136};
code UCHAR AR_OSDUNLCOKKEYStr2[]={21,79,83,68,32,217,207,210,32,123,137,203,218,245,32,224,136,233,150,32,49,48};

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
AR_OSDUNLCOKKEYStr,

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
AR_OSDUNLCOKKEYStr2,

};

code UCHAR SenseyeOffStr1[] =  {13, 'D', 'u', 'a', 'l',' ', 'V', 'i', 'e','W',' ','O','f','f'};
code UCHAR SenseyeOnStr1[] =  {12, 'D', 'u', 'a', 'l',' ', 'V', 'i', 'e','W',' ','O','n'};
code UCHAR *SenseyeOnOffTab[] = {
    SenseyeOffStr1,
    SenseyeOnStr1,
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
code UCHAR CS_DialogDCRStr1[] = {6,  30,31,1,123,124,125, };
code UCHAR AR_DialogDCRStr1[] = {25, 189,179,226,218,136,32,225,238,137,140,147,218,136,32,143,239,182,137,178,32,189,239,179,146,226, };

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
code UCHAR CT_DialogDCRStr2[] = {9, 131,132,133,127,128,134,135,136,137,};
code UCHAR CS_DialogDCRStr2[] = {6, 126,127,128,129,130,131,};
code UCHAR AR_DialogDCRStr2[] = {25,221,214,158,147,218,136,32,217,239,143,199,145,32,235,218,130,32,236,164,233,238,32,204,233,174};

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
code UCHAR JA_DialogDCRStr3[] = {7, 143,9,149,29,30,31,150};
code UCHAR CT_DialogDCRStr3[] = {4, 138,139,125,140};
code UCHAR CS_DialogDCRStr3[] = {5, 124,125,130,132,133};
code UCHAR AR_DialogDCRStr3[] = {18,225,238,137,140,147,218,136,233,32,196,233,189,175,218,136,32,237,206};

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
    AR_DialogDCRStr1,
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
    AR_DialogDCRStr2,
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
    AR_DialogDCRStr3,
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
 code UCHAR AR_ResetColorConfirmStr1[]={17,252,224,136,233,218,243,136,32,189,141,186,32,143,164,137,198,130};



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
     AR_ResetColorConfirmStr1,
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
 code UCHAR SW_ResetAllConfirmStr1[]={30, 124,'t','e','r','s','t',3,'l','l','a',32,'a','l','l','a',32,'i','n','s','t',3,'l','l','n','i','n','g','a','r',63};
 code UCHAR PR_ResetAllConfirmStr1[]={20, 'R', 'e', 'p', 'o', 'r', ' ', 't', 'o', 'd', 'a', 's', ' ', 'd', 'e', 'f', 'i', 'n', '.', '?', 5, };
 code UCHAR JA_ResetAllConfirmStr1[]={8, 187, 141, 142, 230, 211, 208, ' ', '?', };
 code UCHAR CT_ResetAllConfirmStr1[]={6, 181, 202, 136, 137, ' ', '?', };
 code UCHAR CS_ResetAllConfirmStr1[]={6, 180, 201, 136, 137, ' ', '?', };
 code UCHAR AR_ResetAllConfirmStr1[]={22,252,144,137,164,137,165,198,245,136,32,217,214,32,189,141,186,32,143,164,137,198,130};



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
     AR_ResetAllConfirmStr1,
};

