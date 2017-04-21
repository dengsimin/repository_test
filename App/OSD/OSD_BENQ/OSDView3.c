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

UCHAR isOSDAllowSenseyeDemo (void)
{
    if ( (UserData.ucBFMode == PICTURE_MODE_MOVIE)
#if ENABLE_PICTURE_MODE_GAME == ON
        ||(UserData.ucBFMode == PICTURE_MODE_GAME)
#endif
#if	ENABLE_CAD_MODE == ON
        ||(UserData.ucBFMode==PICTURE_MODE_CAD)
#endif        
#if	ENABLE_ANIMATION_MODE == ON
        ||(UserData.ucBFMode==PICTURE_MODE_ANIMATION)
#endif        
#if ENABLE_PICTURE_MODE_MBOOK == ON     
        ||(UserData.ucBFMode==PICTURE_MODE_MBOOK)
#endif
        ||(UserData.ucBFMode == PICTURE_MODE_PHOTO)){
        return TRUE;
    } 
    else{
        return FALSE;
    }
}

UCHAR isOSDAllowDCR (void)
{
    if ( (UserData.ucBFMode == PICTURE_MODE_MOVIE)
#if ENABLE_PICTURE_MODE_GAME == ON
        ||(UserData.ucBFMode == PICTURE_MODE_GAME)
#endif        
        ||(UserData.ucBFMode == PICTURE_MODE_PHOTO)){
        return TRUE;
    } 
    else{
        return FALSE;
    }
}

