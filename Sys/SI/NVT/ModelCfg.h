/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/
#ifndef __MODELCFG_DUMMY_H__
#define __MODELCFG_DUMMY_H__


#define GW_SERIES  0x0100
#define BL_SERIES  0x0200
#define PD_SERIES  0x0300

/*******************************************************************************
              OSD Definition
*******************************************************************************/

#define OSD_BENQ              0x00
#define OSD_BENQ_V1           0x01
#define OSD_BENQ_V2           0x02

/*******************************************************************************
             Factory OSD Definition
*******************************************************************************/
#define AOC_FactoryOSD            0x01
#define OTS_FactoryOSD            0x02

/*******************************************************************************
        Location of a TPV factory
*******************************************************************************/
#define TPV_FUQING          0x00
#define TPV_BEIJING         0x01
#define TPV_WUHAN           0x02  

/*******************************************************************************/
#define BENQ_DEMO                   (0xF011|GW_SERIES)
#define BENQ_BOARD_DEMO             (0xF012|GW_SERIES)
#define BENQ_GW2765HT               (0xF013|GW_SERIES)
#define BENQ_BL2420PT               (0xF014|BL_SERIES)
#define BENQ_BL2720PT               (0xF015|BL_SERIES)
#define BENQ_BL2720PT_DEMO_FD       (0xF016|BL_SERIES)
#define BENQ_PD2700Q                (0xF017|PD_SERIES)


#define ModelName  BENQ_PD2700Q//BENQ_BL2720PT_DEMO_FD//ENQ_BL2720PT_DEMO_FD//BENQ_PD2700Q//BENQ_BL2720PT_DEMO_FD


#define ISENETOUCHKEY (0)


#ifdef NT68168_DEMO
#include "NT68168_DEMO\ModelConfig.h"
#include "NT68168_DEMO\GlobalTimerDef.h"
#include "NT68168_DEMO\NonSupportTimingList.h"
#include "NT68168_DEMO\OSDConfig.h"
#elif defined(NT68650_DEMO)
#include "NT68650_DEMO\ModelConfig.h"
#include "NT68650_DEMO\GlobalTimerDef.h"
#include "NT68650_DEMO\NonSupportTimingList.h"
#include "NT68650_DEMO\OSDConfig.h"
#elif defined(NT68660_DEMO)
#include "NT68660_DEMO\ModelConfig.h"
#include "NT68660_DEMO\GlobalTimerDef.h"
#include "NT68660_DEMO\NonSupportTimingList.h"
#include "NT68660_DEMO\OSDConfig.h"
#elif defined(NT68660_MODULE)
#include "NT68660_MODULE\ModelConfig.h"
#include "NT68660_MODULE\GlobalTimerDef.h"
#include "NT68660_MODULE\NonSupportTimingList.h"
#include "NT68660_MODULE\OSDConfig.h"
#elif defined(NT68668_DEMO)
#include "NT68668_DEMO\ModelConfig.h"
#include "NT68668_DEMO\GlobalTimerDef.h"
#include "NT68668_DEMO\NonSupportTimingList.h"
#include "NT68668_DEMO\OSDConfig.h"
#elif defined(NT68669_DEMO)
#include "NT68669_DEMO\ModelConfig.h"
#include "NT68669_DEMO\GlobalTimerDef.h"
#include "NT68669_DEMO\NonSupportTimingList.h"
#include "NT68669_DEMO\OSDConfig.h"
#elif defined(NT68671_DEMO)
#include "NT68671_DEMO\ModelConfig.h"
#include "NT68671_DEMO\GlobalTimerDef.h"
#include "NT68671_DEMO\NonSupportTimingList.h"
#include "NT68671_DEMO\OSDConfig.h"
#elif defined(NT68672_DEMO)
#include "NT68672_DEMO\ModelConfig.h"
#include "NT68672_DEMO\GlobalTimerDef.h"
#include "NT68672_DEMO\NonSupportTimingList.h"
#include "NT68672_DEMO\OSDConfig.h"
#elif defined(NT68673_DEMO)
#include "NT68673_DEMO\ModelConfig.h"
#include "NT68673_DEMO\GlobalTimerDef.h"
#include "NT68673_DEMO\NonSupportTimingList.h"
#include "NT68673_DEMO\OSDConfig.h"
#elif defined(NT68674_DEMO)
#include "NT68674_DEMO\ModelConfig.h"
#include "NT68674_DEMO\GlobalTimerDef.h"
#include "NT68674_DEMO\NonSupportTimingList.h"
#include "NT68674_DEMO\OSDConfig.h"
#elif defined(NT68675_DEMO)
#include "NT68675_DEMO\ModelConfig.h"
#include "NT68675_DEMO\GlobalTimerDef.h"
#include "NT68675_DEMO\NonSupportTimingList.h"
#include "NT68675_DEMO\OSDConfig.h"
#elif defined(NT68676_DEMO)
#include "NT68676_DEMO\ModelConfig.h"
#include "NT68676_DEMO\GlobalTimerDef.h"
#include "NT68676_DEMO\NonSupportTimingList.h"
#include "NT68676_DEMO\OSDConfig.h"
#elif defined(NT68677_DEMO)
#include "NT68677_DEMO\ModelConfig.h"
#include "NT68677_DEMO\GlobalTimerDef.h"
#include "NT68677_DEMO\NonSupportTimingList.h"
#include "NT68677_DEMO\OSDConfig.h"
#elif defined(NT68776_DEMO)
#include "NT68776_DEMO\ModelConfig.h"
#include "NT68776_DEMO\GlobalTimerDef.h"
#include "NT68776_DEMO\NonSupportTimingList.h"
#include "NT68776_DEMO\OSDConfig.h"
#include "NT68776_DEMO\SRConfig.h"
#elif defined(NT68777_DEMO)
#include "NT68777_DEMO\ModelConfig.h"
#include "NT68777_DEMO\GlobalTimerDef.h"
#include "NT68777_DEMO\NonSupportTimingList.h"
#include "NT68777_DEMO\OSDConfig.h"
#include "NT68777_DEMO\SRConfig.h"
#elif defined(NT68778_DEMO)
#include "NT68778_DEMO\ModelConfig.h"
#include "NT68778_DEMO\GlobalTimerDef.h"
#include "NT68778_DEMO\NonSupportTimingList.h"
#include "NT68778_DEMO\OSDConfig.h"
#include "NT68778_DEMO\SRConfig.h"
#elif defined(NT68779_DEMO)
#include "NT68779_DEMO\ModelConfig.h"
#include "NT68779_DEMO\GlobalTimerDef.h"
#include "NT68779_DEMO\NonSupportTimingList.h"
#include "NT68779_DEMO\OSDConfig.h"
#include "NT68779_DEMO\SRConfig.h"
#elif defined(NT68750_DEMO)
#include "NT68750_DEMO\ModelConfig.h"
#include "NT68750_DEMO\GlobalTimerDef.h"
#include "NT68750_DEMO\NonSupportTimingList.h"
#include "NT68750_DEMO\OSDConfig.h"
#include "NT68750_DEMO\SRConfig.h"
#elif defined(NT68751_DEMO)
#include "NT68751_DEMO\ModelConfig.h"
#include "NT68751_DEMO\GlobalTimerDef.h"
#include "NT68751_DEMO\NonSupportTimingList.h"
#include "NT68751_DEMO\OSDConfig.h"
#include "NT68751_DEMO\SRConfig.h"
#elif defined(NT68752_DEMO)
#include "NT68752_DEMO\ModelConfig.h"
#include "NT68752_DEMO\GlobalTimerDef.h"
#include "NT68752_DEMO\NonSupportTimingList.h"
#include "NT68752_DEMO\OSDConfig.h"
#include "NT68752_DEMO\SRConfig.h"
#elif defined(NT68753_DEMO)
#include "NT68753_DEMO\ModelConfig.h"
#include "NT68753_DEMO\GlobalTimerDef.h"
#include "NT68753_DEMO\NonSupportTimingList.h"
#include "NT68753_DEMO\OSDConfig.h"
#include "NT68753_DEMO\SRConfig.h"
#elif defined(NT68750_MODULE)
#include "NT68750_MODULE\ModelConfig.h"
#include "NT68750_MODULE\GlobalTimerDef.h"
#include "NT68750_MODULE\NonSupportTimingList.h"
#include "NT68750_MODULE\OSDConfig.h"
#include "NT68750_MODULE\SRConfig.h"
#elif defined(NT68360_DEMO)
#include "NT68360_DEMO\ModelConfig.h"
#include "NT68360_DEMO\GlobalTimerDef.h"
#include "NT68360_DEMO\NonSupportTimingList.h"
#include "NT68360_DEMO\OSDConfig.h"
#elif defined(NT68360_MODULE)
#include "NT68360_MODULE\ModelConfig.h"
#include "NT68360_MODULE\GlobalTimerDef.h"
#include "NT68360_MODULE\NonSupportTimingList.h"
#include "NT68360_MODULE\OSDConfig.h"
#elif defined(NT68361_DEMO)
#include "NT68361_DEMO\ModelConfig.h"
#include "NT68361_DEMO\GlobalTimerDef.h"
#include "NT68361_DEMO\NonSupportTimingList.h"
#include "NT68361_DEMO\OSDConfig.h"
#elif defined(NT68364_MODULE)
#include "NT68364_MODULE\ModelConfig.h"
#include "NT68364_MODULE\GlobalTimerDef.h"
#include "NT68364_MODULE\NonSupportTimingList.h"
#include "NT68364_MODULE\OSDConfig.h"
#elif defined(NT68652_DEMO)
#include "NT68652_DEMO\ModelConfig.h"
#include "NT68652_DEMO\GlobalTimerDef.h"
#include "NT68652_DEMO\NonSupportTimingList.h"
#include "NT68652_DEMO\OSDConfig.h"
#elif defined(NT68652_MODULE)
#include "NT68652_MODULE\ModelConfig.h"
#include "NT68652_MODULE\GlobalTimerDef.h"
#include "NT68652_MODULE\NonSupportTimingList.h"
#include "NT68652_MODULE\OSDConfig.h"
#elif defined(NT68169_DEMO)
#include "NT68169_DEMO\ModelConfig.h"
#include "NT68169_DEMO\GlobalTimerDef.h"
#include "NT68169_DEMO\NonSupportTimingList.h"
#include "NT68169_DEMO\OSDConfig.h"
#elif defined(NT68169_MODULE)
#include "NT68169_MODULE\ModelConfig.h"
#include "NT68169_MODULE\GlobalTimerDef.h"
#include "NT68169_MODULE\NonSupportTimingList.h"
#include "NT68169_MODULE\OSDConfig.h"
#elif defined(NT68169_FPGA)
#include "NT68169_FPGA\ModelConfig.h"
#include "NT68169_FPGA\GlobalTimerDef.h"
#include "NT68169_FPGA\NonSupportTimingList.h"
#include "NT68169_FPGA\OSDConfig.h"
#elif defined(NT68661_DEMO)
#include "NT68661_DEMO\ModelConfig.h"
#include "NT68661_DEMO\GlobalTimerDef.h"
#include "NT68661_DEMO\NonSupportTimingList.h"
#include "NT68661_DEMO\OSDConfig.h"
#include "NT68661_DEMO\SRConfig.h"
#elif defined(NT68661_MODULE)
#include "NT68661_MODULE\ModelConfig.h"
#include "NT68661_MODULE\GlobalTimerDef.h"
#include "NT68661_MODULE\NonSupportTimingList.h"
#include "NT68661_MODULE\OSDConfig.h"
#include "NT68661_MODULE\SRConfig.h"
#elif defined(NT68661_FPGA)
#include "NT68661_FPGA\ModelConfig.h"
#include "NT68661_FPGA\GlobalTimerDef.h"
#include "NT68661_FPGA\NonSupportTimingList.h"
#include "NT68661_FPGA\OSDConfig.h"
#include "NT68661_FPGA\SRConfig.h"
#elif defined(NT68770_DEMO)
#include "NT68770_DEMO\ModelConfig.h"
#include "NT68770_DEMO\GlobalTimerDef.h"
#include "NT68770_DEMO\NonSupportTimingList.h"
#include "NT68770_DEMO\OSDConfig.h"
#include "NT68770_DEMO\SRConfig.h"
#elif defined(NT68770_MODULE)
#include "NT68770_MODULE\ModelConfig.h"
#include "NT68770_MODULE\GlobalTimerDef.h"
#include "NT68770_MODULE\NonSupportTimingList.h"
#include "NT68770_MODULE\OSDConfig.h"
#include "NT68770_MODULE\SRConfig.h"
#elif defined(NT68771_MODULE)
#include "NT68771_MODULE\ModelConfig.h"
#include "NT68771_MODULE\GlobalTimerDef.h"
#include "NT68771_MODULE\NonSupportTimingList.h"
#include "NT68771_MODULE\OSDConfig.h"
#include "NT68771_MODULE\SRConfig.h"
#elif defined(NT68772_MODULE)
#include "NT68772_MODULE\ModelConfig.h"
#include "NT68772_MODULE\GlobalTimerDef.h"
#include "NT68772_MODULE\NonSupportTimingList.h"
#include "NT68772_MODULE\OSDConfig.h"
#include "NT68772_MODULE\SRConfig.h"
#elif defined(NT68773_MODULE)
#include "NT68773_MODULE\ModelConfig.h"
#include "NT68773_MODULE\GlobalTimerDef.h"
#include "NT68773_MODULE\NonSupportTimingList.h"
#include "NT68773_MODULE\OSDConfig.h"
#include "NT68773_MODULE\SRConfig.h"
#elif defined(NT68774_MODULE)
#include "NT68774_MODULE\ModelConfig.h"
#include "NT68774_MODULE\GlobalTimerDef.h"
#include "NT68774_MODULE\NonSupportTimingList.h"
#include "NT68774_MODULE\OSDConfig.h"
#include "NT68774_MODULE\SRConfig.h"
#elif defined(NT68775_DEMO)
#include "NT68775_DEMO\ModelConfig.h"
#include "NT68775_DEMO\GlobalTimerDef.h"
#include "NT68775_DEMO\NonSupportTimingList.h"
#include "NT68775_DEMO\OSDConfig.h"
#include "NT68775_DEMO\SRConfig.h"
#elif defined(NT68775_MODULE)
#include "NT68775_MODULE\ModelConfig.h"
#include "NT68775_MODULE\GlobalTimerDef.h"
#include "NT68775_MODULE\NonSupportTimingList.h"
#include "NT68775_MODULE\OSDConfig.h"
#include "NT68775_MODULE\SRConfig.h"
#elif defined(NT68662_MODULE)
#include "NT68662_MODULE\ModelConfig.h"
#include "NT68662_MODULE\GlobalTimerDef.h"
#include "NT68662_MODULE\NonSupportTimingList.h"
#include "NT68662_MODULE\OSDConfig.h"
#include "NT68662_MODULE\SRConfig.h"
#elif defined(NT68785_DEMO)
#include "NT68785_DEMO\ModelConfig.h"
#include "NT68785_DEMO\GlobalTimerDef.h"
#include "NT68785_DEMO\NonSupportTimingList.h"
#include "NT68785_DEMO\OSDConfig.h"
#include "NT68785_DEMO\SRConfig.h"
#elif defined(NT68785_MODULE)
#include "NT68785_MODULE\ModelConfig.h"
#include "NT68785_MODULE\GlobalTimerDef.h"
#include "NT68785_MODULE\NonSupportTimingList.h"
#include "NT68785_MODULE\OSDConfig.h"
#include "NT68785_MODULE\SRConfig.h"
#elif defined(NT68850_DEMO)
#include "NT68850_DEMO\ModelConfig.h"
#include "NT68850_DEMO\GlobalTimerDef.h"
#include "NT68850_DEMO\NonSupportTimingList.h"
#include "NT68850_DEMO\OSDConfig.h"
#include "NT68850_DEMO\SRConfig.h"
#elif defined(NT68850_MODULE)
#include "NT68850_MODULE\ModelConfig.h"
#include "NT68850_MODULE\GlobalTimerDef.h"
#include "NT68850_MODULE\NonSupportTimingList.h"
#include "NT68850_MODULE\OSDConfig.h"
#elif defined(NT68857_DEMO)
#include "NT68857_DEMO\ModelConfig.h"
#include "NT68857_DEMO\GlobalTimerDef.h"
#include "NT68857_DEMO\NonSupportTimingList.h"
#include "NT68857_DEMO\OSDConfig.h"
#elif defined(NT68857_MODULE)
#include "NT68857_MODULE\ModelConfig.h"
#include "NT68857_MODULE\GlobalTimerDef.h"
#include "NT68857_MODULE\NonSupportTimingList.h"
#include "NT68857_MODULE\OSDConfig.h"
#include "NT68857_MODULE\SRConfig.h"
#elif defined(NT68859_DEMO)
#include "NT68859_DEMO\ModelConfig.h"
#include "NT68859_DEMO\GlobalTimerDef.h"
#include "NT68859_DEMO\NonSupportTimingList.h"
#include "NT68859_DEMO\OSDConfig.h"
#include "NT68859_DEMO\SRConfig.h"
#elif defined(NT68859_MODULE)
#include "NT68859_MODULE\ModelConfig.h"
#include "NT68859_MODULE\GlobalTimerDef.h"
#include "NT68859_MODULE\NonSupportTimingList.h"
#include "NT68859_MODULE\OSDConfig.h"
#include "NT68859_MODULE\SRConfig.h"
#elif defined(NT68655_DEMO)
#include "NT68655_DEMO\ModelConfig.h"
#include "NT68655_DEMO\GlobalTimerDef.h"
#include "NT68655_DEMO\NonSupportTimingList.h"
#include "NT68655_DEMO\OSDConfig.h"
#elif defined(NT68655_MODULE)
#include "NT68655_MODULE\ModelConfig.h"
#include "NT68655_MODULE\GlobalTimerDef.h"
#include "NT68655_MODULE\NonSupportTimingList.h"
#include "NT68655_MODULE\OSDConfig.h"
#elif defined(NT68150_FPGA)
#include "NT68150_FPGA\ModelConfig.h"
#include "NT68150_FPGA\GlobalTimerDef.h"
#include "NT68150_FPGA\NonSupportTimingList.h"
#include "NT68150_FPGA\OSDConfig.h"
#elif defined(NT68150_DEMO)
#include "NT68150_DEMO\ModelConfig.h"
#include "NT68150_DEMO\GlobalTimerDef.h"
#include "NT68150_DEMO\NonSupportTimingList.h"
#include "NT68150_DEMO\OSDConfig.h"
#elif defined(NT68150_MODULE)
#include "NT68150_MODULE\ModelConfig.h"
#include "NT68150_MODULE\GlobalTimerDef.h"
#include "NT68150_MODULE\NonSupportTimingList.h"
#include "NT68150_MODULE\OSDConfig.h"
#elif defined(NT68150_RA)
#include "NT68150_RA\ModelConfig.h"
#include "NT68150_RA\GlobalTimerDef.h"
#include "NT68150_RA\NonSupportTimingList.h"
#include "NT68150_RA\OSDConfig.h"
#elif defined(NT68790_FPGA)
#include "NT68790_FPGA\ModelConfig.h"
#include "NT68790_FPGA\GlobalTimerDef.h"
#include "NT68790_FPGA\NonSupportTimingList.h"
#include "NT68790_FPGA\OSDConfig.h"
#elif defined(NT68790_MODULE)
#include "NT68790_MODULE\ModelConfig.h"
#include "NT68790_MODULE\GlobalTimerDef.h"
#include "NT68790_MODULE\NonSupportTimingList.h"
#include "NT68790_MODULE\OSDConfig.h"
#elif defined(NT68795_MODULE)
#include "NT68795_MODULE\ModelConfig.h"
#include "NT68795_MODULE\GlobalTimerDef.h"
#include "NT68795_MODULE\NonSupportTimingList.h"
#include "NT68795_MODULE\OSDConfig.h"
#elif defined(NT68799_MODULE)
#include "NT68799_MODULE\ModelConfig.h"
#include "NT68799_MODULE\GlobalTimerDef.h"
#include "NT68799_MODULE\NonSupportTimingList.h"
#include "NT68799_MODULE\OSDConfig.h"
#elif defined(NT68790_DEMO)
#include "NT68790_DEMO\ModelConfig.h"
#include "NT68790_DEMO\GlobalTimerDef.h"
#include "NT68790_DEMO\NonSupportTimingList.h"
#include "NT68790_DEMO\OSDConfig.h"
#elif defined(NT68795_DEMO)
#include "NT68795_DEMO\ModelConfig.h"
#include "NT68795_DEMO\GlobalTimerDef.h"
#include "NT68795_DEMO\NonSupportTimingList.h"
#include "NT68795_DEMO\OSDConfig.h"
#elif defined(NT68799_DEMO)
#include "NT68799_DEMO\ModelConfig.h"
#include "NT68799_DEMO\GlobalTimerDef.h"
#include "NT68799_DEMO\NonSupportTimingList.h"
#include "NT68799_DEMO\OSDConfig.h"
#elif defined(NT68790_RA)
#include "NT68790_RA\ModelConfig.h"
#include "NT68790_RA\GlobalTimerDef.h"
#include "NT68790_RA\NonSupportTimingList.h"
#include "NT68790_RA\OSDConfig.h"
#elif defined(NT68658_FPGA)
#include "NT68658_FPGA\ModelConfig.h"
#include "NT68658_FPGA\GlobalTimerDef.h"
#include "NT68658_FPGA\NonSupportTimingList.h"
#include "NT68658_FPGA\OSDConfig.h"
#elif defined(NT68658_DEMO)
#include "NT68658_DEMO\ModelConfig.h"
#include "NT68658_DEMO\GlobalTimerDef.h"
#include "NT68658_DEMO\NonSupportTimingList.h"
#include "NT68658_DEMO\OSDConfig.h"
#elif defined(NT68658_MODULE)
#include "NT68658_MODULE\ModelConfig.h"
#include "NT68658_MODULE\GlobalTimerDef.h"
#include "NT68658_MODULE\NonSupportTimingList.h"
#include "NT68658_MODULE\OSDConfig.h"
#elif defined(NT68658_RA)
#include "NT68658_RA\ModelConfig.h"
#include "NT68658_RA\GlobalTimerDef.h"
#include "NT68658_RA\NonSupportTimingList.h"
#include "NT68658_RA\OSDConfig.h"
#elif defined(NT68810_FPGA)
#include "NT68810_FPGA\ModelConfig.h"
#include "NT68810_FPGA\GlobalTimerDef.h"
#include "NT68810_FPGA\NonSupportTimingList.h"
#include "NT68810_FPGA\OSDConfig.h"
#elif defined(NT68810_MODULE)
#include "NT68810_MODULE\ModelConfig.h"
#include "NT68810_MODULE\GlobalTimerDef.h"
#include "NT68810_MODULE\NonSupportTimingList.h"
#include "NT68810_MODULE\OSDConfig.h"
#elif defined(NT68810_MODULE_2H)
#include "NT68810_MODULE_2H\ModelConfig.h"
#include "NT68810_MODULE_2H\GlobalTimerDef.h"
#include "NT68810_MODULE_2H\NonSupportTimingList.h"
#include "NT68810_MODULE_2H\OSDConfig.h"
#elif defined(NT68810_MODULE_2DP)
#include "NT68810_MODULE_2DP\ModelConfig.h"
#include "NT68810_MODULE_2DP\GlobalTimerDef.h"
#include "NT68810_MODULE_2DP\NonSupportTimingList.h"
#include "NT68810_MODULE_2DP\OSDConfig.h"
#elif defined(NT68810_MODULE_80A)
#include "NT68810_MODULE_80A\ModelConfig.h"
#include "NT68810_MODULE_80A\GlobalTimerDef.h"
#include "NT68810_MODULE_80A\NonSupportTimingList.h"
#include "NT68810_MODULE_80A\OSDConfig.h"
#elif defined(NT68810_MODULE_80L)
#include "NT68810_MODULE_80L\ModelConfig.h"
#include "NT68810_MODULE_80L\GlobalTimerDef.h"
#include "NT68810_MODULE_80L\NonSupportTimingList.h"
#include "NT68810_MODULE_80L\OSDConfig.h"
#elif defined(NT68810_DEMO)
#include "NT68810_DEMO\ModelConfig.h"
#include "NT68810_DEMO\GlobalTimerDef.h"
#include "NT68810_DEMO\NonSupportTimingList.h"
#include "NT68810_DEMO\OSDConfig.h"
#elif defined(NT68810_DEMO_2H)
#include "NT68810_DEMO_2H\ModelConfig.h"
#include "NT68810_DEMO_2H\GlobalTimerDef.h"
#include "NT68810_DEMO_2H\NonSupportTimingList.h"
#include "NT68810_DEMO_2H\OSDConfig.h"
#elif defined(NT68870_FPGA)
#include "NT68870_FPGA\ModelConfig.h"
#include "NT68870_FPGA\GlobalTimerDef.h"
#include "NT68870_FPGA\NonSupportTimingList.h"
#include "NT68870_FPGA\OSDConfig.h"
#elif defined(NT68870_MODULE)
#include "NT68870_MODULE\ModelConfig.h"
#include "NT68870_MODULE\GlobalTimerDef.h"
#include "NT68870_MODULE\NonSupportTimingList.h"
#include "NT68870_MODULE\OSDConfig.h"
#elif defined(NT68877_MODULE)
#include "NT68877_MODULE\ModelConfig.h"
#include "NT68877_MODULE\GlobalTimerDef.h"
#include "NT68877_MODULE\NonSupportTimingList.h"
#include "NT68877_MODULE\OSDConfig.h"
#elif defined(NT68879_MODULE)
#include "NT68879_MODULE\ModelConfig.h"
#include "NT68879_MODULE\GlobalTimerDef.h"
#include "NT68879_MODULE\NonSupportTimingList.h"
#include "NT68879_MODULE\OSDConfig.h"
#elif defined(NT68860_MODULE)
#include "NT68860_MODULE\ModelConfig.h"
#include "NT68860_MODULE\GlobalTimerDef.h"
#include "NT68860_MODULE\NonSupportTimingList.h"
#include "NT68860_MODULE\OSDConfig.h"
#elif defined(NT68867_MODULE)
#include "NT68867_MODULE\ModelConfig.h"
#include "NT68867_MODULE\GlobalTimerDef.h"
#include "NT68867_MODULE\NonSupportTimingList.h"
#include "NT68867_MODULE\OSDConfig.h"
#elif defined(NT68869_MODULE)
#include "NT68869_MODULE\ModelConfig.h"
#include "NT68869_MODULE\GlobalTimerDef.h"
#include "NT68869_MODULE\NonSupportTimingList.h"
#include "NT68869_MODULE\OSDConfig.h"
#elif defined(NT68890_DEMO)
#include "NT68890_DEMO\ModelConfig.h"
#include "NT68890_DEMO\GlobalTimerDef.h"
#include "NT68890_DEMO\NonSupportTimingList.h"
#include "NT68890_DEMO\OSDConfig.h"
#else
#error "Unknown model! Please define model in Keilc profile."
#endif


#ifndef ENABLE_BACKGROUND_TO_BLUE
#define ENABLE_BACKGROUND_TO_BLUE    OFF 
#endif


#ifndef MD_ENABLE_LOW_PWR_MODE
#define MD_ENABLE_LOW_PWR_MODE     OFF
#endif
#ifndef MD_ENABLE_CHECK_SYS5V
#define MD_ENABLE_CHECK_SYS5V      OFF
#endif
#ifndef MD_ENABLE_LPD
#define MD_ENABLE_LPD              OFF
#endif
#ifndef MD_ENABLE_HDCP
#define MD_ENABLE_HDCP             OFF
#endif
#ifndef MD_ENABLE_HDCP_KEY_DCRPT
#define MD_ENABLE_HDCP_KEY_DCRPT   OFF
#endif
#ifndef MD_ENABLE_DEMO_HDCP_KEY
#define MD_ENABLE_DEMO_HDCP_KEY    OFF
#endif
#ifndef MD_ENABLE_NVT_HDCP_WRITER
#define MD_ENABLE_NVT_HDCP_WRITER  OFF
#endif
#ifndef MD_ENABLE_HDCP_TRIM_MODE
#define MD_ENABLE_HDCP_TRIM_MODE             OFF
#endif
#ifndef MD_ENABLE_EDID_TRIM_MODE
#define MD_ENABLE_EDID_TRIM_MODE             OFF
#endif
#ifndef MD_ENABLE_GAMMA
#define MD_ENABLE_GAMMA            OFF
#endif
#ifndef MD_ENABLE_10TO10_GAMMA
#define MD_ENABLE_10TO10_GAMMA     OFF
#endif
#ifndef MD_ENABLE_10TO12_GAMMA
#define MD_ENABLE_10TO12_GAMMA     OFF
#endif
#ifndef MD_ENABLE_PRE_REV_GAMMA
#define MD_ENABLE_PRE_REV_GAMMA     OFF
#endif
#ifndef MD_ENABLE_SINGLE_DDR
#define MD_ENABLE_SINGLE_DDR       OFF
#endif
#ifndef MD_ENABLE_OD
#define MD_ENABLE_OD               OFF
#endif
#ifndef MD_ENABLE_OD_TRANSFORM
#define MD_ENABLE_OD_TRANSFORM     OFF
#endif
#ifndef MD_ENABLE_OD_MOTION_CHK
#define MD_ENABLE_OD_MOTION_CHK    OFF
#endif
#ifndef MD_ENABLE_OD_3D_MODE
#define MD_ENABLE_OD_3D_MODE       OFF
#endif
#ifndef MD_ENABLE_MMU
#define MD_ENABLE_MMU              OFF
#endif
#ifndef MD_ENABLE_FE2P
#define MD_ENABLE_FE2P             OFF
#endif
#ifndef MD_ENABLE_DIRECT_FE2P
#define MD_ENABLE_DIRECT_FE2P      OFF
#endif
#ifndef MD_ENABLE_DVI_DUAL_LINK
#define MD_ENABLE_DVI_DUAL_LINK    OFF
#endif
#ifndef MD_ENABLE_HDMI
#define MD_ENABLE_HDMI             OFF
#endif
#ifndef MD_ENABLE_HDMI_PRETEST
#define MD_ENABLE_HDMI_PRETEST     OFF
#endif
#ifndef MD_ENABLE_AUTO_CONTROL
#define MD_ENABLE_AUTO_CONTROL     OFF
#endif
#ifndef MD_ENABLE_HW_CEC
#define MD_ENABLE_HW_CEC           OFF
#endif
#ifndef MD_ENABLE_HDMI_FS_MUTE
#define MD_ENABLE_HDMI_FS_MUTE     OFF
#endif
#ifndef MD_ENABLE_HDMI_AUDIO_AUTO_MUTE
#define MD_ENABLE_HDMI_AUDIO_AUTO_MUTE OFF
#endif
#ifndef MD_ENABLE_DBC
#define MD_ENABLE_DBC              OFF
#endif
#ifndef MD_ENABLE_DBC_HW_DEBOUNCE
#define MD_ENABLE_DBC_HW_DEBOUNCE  OFF
#endif
#ifndef MD_ENABLE_DIGI3_HPD
#define MD_ENABLE_DIGI3_HPD        OFF
#endif
#ifndef MD_ENABLE_DIGI2_HPD
#define MD_ENABLE_DIGI2_HPD        OFF
#endif
#ifndef MD_ENABLE_DIGI1_HPD
#define MD_ENABLE_DIGI1_HPD        OFF
#endif
#ifndef MD_ENABLE_DIGI0_HPD
#define MD_ENABLE_DIGI0_HPD        OFF
#endif
#ifndef MD_ENABLE_DP_HPD
#define MD_ENABLE_DP_HPD           OFF
#endif
#ifndef MD_ENABLE_DP_ADV_HPD
#define MD_ENABLE_DP_ADV_HPD       OFF
#endif
#ifndef MD_ENABLE_DP1_HPD
#define MD_ENABLE_DP1_HPD          OFF
#endif
#ifndef MD_ENABLE_DP1_ADV_HPD
#define MD_ENABLE_DP1_ADV_HPD      OFF
#endif
#ifndef MD_ENABLE_DP2_HPD
#define MD_ENABLE_DP2_HPD          OFF
#endif
#ifndef MD_ENABLE_DP2_ADV_HPD
#define MD_ENABLE_DP2_ADV_HPD      OFF
#endif
#ifndef MD_ENABLE_DP3_HPD
#define MD_ENABLE_DP3_HPD          OFF
#endif
#ifndef MD_ENABLE_DP3_ADV_HPD
#define MD_ENABLE_DP3_ADV_HPD      OFF
#endif
#ifndef MD_ENABLE_SCALER_AUDIO
#define MD_ENABLE_SCALER_AUDIO     OFF
#endif
#ifndef MD_ENABLE_INTERNAL_AUDIO_BUZZER
#define MD_ENABLE_INTERNAL_AUDIO_BUZZER OFF
#endif
#ifndef MD_ENABLE_OSD_WINDOWS
#define MD_ENABLE_OSD_WINDOWS      OFF
#endif
#ifndef MD_ENABLE_OSD_ROTATION
#define MD_ENABLE_OSD_ROTATION     OFF
#endif
#ifndef MD_ENABLE_OSD_MIRROR
#define MD_ENABLE_OSD_MIRROR       OFF
#endif
#ifndef MD_ENABLE_OSD_FLIP
#define MD_ENABLE_OSD_FLIP         OFF
#endif
#ifndef MD_ENABLE_INTERNAL_LDO
#define MD_ENABLE_INTERNAL_LDO     OFF
#endif
#ifndef MD_ENABLE_INTERNAL_ADC_LDO
#define MD_ENABLE_INTERNAL_ADC_LDO OFF
#endif
#ifndef MD_ENABLE_INTERNAL_ADC_RES
#define MD_ENABLE_INTERNAL_ADC_RES OFF
#endif
#ifndef MD_ENABLE_EMBEDDED_CHECKSUM
#define MD_ENABLE_EMBEDDED_CHECKSUM OFF
#endif
#ifndef MD_ENABLE_OVERSCAN
#define MD_ENABLE_OVERSCAN         OFF
#endif
#ifndef MD_ENABLE_PWM_SMOOTH
#define MD_ENABLE_PWM_SMOOTH       OFF
#endif
#ifndef MD_ENABLE_FLASH_IDLE_MODE
#define MD_ENABLE_FLASH_IDLE_MODE  OFF
#endif
#ifndef MD_ENABLE_FIT_ALL_PANEL_SPEC
#define MD_ENABLE_FIT_ALL_PANEL_SPEC OFF
#endif
#ifndef MD_ENABLE_NR_BYTIMING
#define MD_ENABLE_NR_BYTIMING      OFF
#endif
#ifndef MD_ENABLE_SCALER_3D
#define MD_ENABLE_SCALER_3D        OFF
#endif
#ifndef MD_ENABLE_3D_CNV
#define MD_ENABLE_3D_CNV           OFF
#endif
#ifndef MD_ENABLE_3D_CNV_120Hz
#define MD_ENABLE_3D_CNV_120Hz     OFF
#endif
#ifndef MD_ENABLE_SHUTTER_3D
#define MD_ENABLE_SHUTTER_3D       OFF
#endif
#ifndef MD_ENABLE_LD
#define MD_ENABLE_LD               OFF
#endif
#ifndef MD_ENABLE_SR
#define MD_ENABLE_SR               OFF
#endif
#ifndef MD_ENABLE_SELF_AUTOCOLOR
#define MD_ENABLE_SELF_AUTOCOLOR   OFF
#endif
#ifndef MD_ENABLE_HW_AUTOCOLOR
#define MD_ENABLE_HW_AUTOCOLOR     OFF
#endif
#ifndef MD_ENABLE_FUNC_OSD
#define MD_ENABLE_FUNC_OSD         OFF
#endif
#ifndef MD_ENABLE_DEMO_DP_EDID
#define MD_ENABLE_DEMO_DP_EDID     OFF
#endif
#ifndef MD_ENABLE_DEMO_MHL_EDID
#define MD_ENABLE_DEMO_MHL_EDID     OFF
#endif
#ifndef MD_ENABLE_PREFRC
#define MD_ENABLE_PREFRC           OFF
#endif
#ifndef MD_ENABLE_DFR
#define MD_ENABLE_DFR              OFF
#endif
#ifndef MD_ENABLE_SCALER_LEDDRV_ANA_MODE
#define MD_ENABLE_SCALER_LEDDRV_ANA_MODE              OFF
#endif
#ifndef MD_ENABLE_SCALER_LEDDRV_IO_MODE
#define MD_ENABLE_SCALER_LEDDRV_IO_MODE              OFF
#endif
#ifndef MD_ENABLE_SCALER_LEDDRV
#define MD_ENABLE_SCALER_LEDDRV              OFF
#endif
#ifndef MD_ENABLE_ESD_PROTECT
#define MD_ENABLE_ESD_PROTECT     OFF
#endif
#ifndef MD_ENABLE_DP_AUX_MONITOR
#define MD_ENABLE_DP_AUX_MONITOR     OFF 
#endif
#ifndef MD_ENABLE_EDP
#define MD_ENABLE_EDP               OFF 
#endif
#ifndef MD_ENABLE_POSTFRC
#define MD_ENABLE_POSTFRC           OFF
#endif
#ifndef MD_ENABLE_AUTOFRAMEDOWN
#define MD_ENABLE_AUTOFRAMEDOWN     OFF
#endif
#ifndef MD_ENABLE_USB_TYPE_C
#define MD_ENABLE_USB_TYPE_C        OFF
#endif

#ifndef MD_ENABLE_FREESYNC_DEMO
#define MD_ENABLE_FREESYNC_DEMO     OFF
#endif
#ifndef MD_ENABLE_FREESYNC_HDMI_FUNC
#define MD_ENABLE_FREESYNC_HDMI_FUNC OFF
#endif

#ifndef MD_ENABLE_CENTER_MODE
#define MD_ENABLE_CENTER_MODE       OFF
#endif


#ifndef ENABLE_COLOR_FORMAT
#define ENABLE_COLOR_FORMAT    ON
#endif

#ifndef ENABLE_AUDIO_SELECT
#define ENABLE_AUDIO_SELECT ON
#endif


#ifndef ENABLE_LVDS_OUTPUT_10BIT
#define ENABLE_LVDS_OUTPUT_10BIT    OFF 
#endif

#ifndef ENABLE_ENE_CLOSE_Behavior
#define ENABLE_ENE_CLOSE_Behavior    OFF 
#endif

#ifndef DPTEST_THERMAL_SETTING
#define DPTEST_THERMAL_SETTING    OFF 
#endif

#ifndef ENABLE_DPHDMI_AUTO_SWITCH
#define ENABLE_DPHDMI_AUTO_SWITCH    OFF
#endif

#ifndef ENABLE_LOGO_ENERGYSTART
#define ENABLE_LOGO_ENERGYSTART    OFF
#endif



#ifndef ENABLE_AUDIO_SELECT
#define ENABLE_AUDIO_SELECT ON
#endif
#ifndef ENABLE_SERVICEMENU_DVIHPD
#define ENABLE_SERVICEMENU_DVIHPD ON
#endif
#ifndef TPV_USB_APPLICATION
#define TPV_USB_APPLICATION    OFF 
#endif

#ifndef TPV_PS
#define TPV_PS    OFF 
#endif

#ifndef ENABLE_PICTURE_DUAL_MODE
#define ENABLE_PICTURE_DUAL_MODE    ON
#endif

#ifndef DP_WAKEUP_CHECK_PLUG
#define DP_WAKEUP_CHECK_PLUG    OFF 
#endif

#ifndef ENABLE_LBL_BASE_FGA
#define ENABLE_LBL_BASE_FGA  OFF
#endif


#ifndef ENABLE_DUAL_370
#define ENABLE_DUAL_370         OFF
#endif


#ifndef ENABLE_PIP
#define ENABLE_PIP              OFF
#endif


#ifndef PICTURE_FORMAT_NEW
#define PICTURE_FORMAT_NEW     OFF
#endif


#ifndef ENABLE_NVT_FGA
#define ENABLE_NVT_FGA      OFF
#endif


#include "ModelVerification.h"

#endif //__MODELCFG_DUMMY_H__
