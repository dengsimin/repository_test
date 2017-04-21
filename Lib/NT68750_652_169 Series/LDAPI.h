/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/

#ifndef __LDAPI_H__
#define __LDAPI_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "ScalerType.h"
#include "Typedef.h"

//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************
#define LD_GRAY2DUTY_TABLE_LEN 48   /*!< Size of Gray2Duty table. */
#define LD_LV2GAIN_TABLE_LEN   32   /*!< Size of LV2Gain table. */
#define LD_PROFILE_LEN         988  /*!< Size of LD profile. */

//******************************************************************************
// D A T A   T Y P E   D E F I N E S
//******************************************************************************
/*!
 * Data type for LD mode.
 */
typedef enum _LD_MODE_ {
    LD_OFF,     /*!< LD off. */
    LD_ON,      /*!< LD on. */
    LD_DEMO,    /*!< LD demo mode. */
    NUM_LD_MODE /*!< Number of LD modes. */
} LDMode;

/*!
 * Data type for LD tables.
 */
typedef struct _LD_Table_ {
    UCHAR ucGary2DutyTable[2][LD_GRAY2DUTY_TABLE_LEN]; /*!< Table of Gray2Duty. */
    UCHAR ucLv2GainTable[2][LD_LV2GAIN_TABLE_LEN];     /*!< Table of LV2Gain. */
    UCHAR ucLightProfile[8][LD_PROFILE_LEN];           /*!< Table of profile. */
} LDTable;

//******************************************************************************
// V A R I A B L E S    P R O T O T Y P E
//******************************************************************************

//******************************************************************************
// F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
void LDAPI_Init(void);
void LDAPI_SetHVSamples(UCHAR num_h, UCHAR num_v);
void LDAPI_SetHVZones(UCHAR num_h, UCHAR num_v);
void LDAPI_SetHVBound(UCHAR h, UCHAR v);
void LDAPI_SetDimDef(UCHAR dim01, UCHAR dim23, UCHAR dim45, UCHAR dim67);
void LDAPI_LoadTable(LDTable * table);
void LDAPI_SetLDMode(LDMode mode);
void LDAPI_SetBrightness(UCHAR duty);

#endif //__LDAPI_H__
