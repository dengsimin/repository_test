/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/
#ifndef __KEYPAD_H__
#define __KEYPAD_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "KeyPadList.h"

#if (KEYPAD_TYPE == NT68168_DEMO_KEYPAD)
#include "NT68168_DEMO_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68650_DEMO_KEYPAD)
#include "NT68650_DEMO_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68660_DEMO_KEYPAD)
#include "NT68660_DEMO_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68660_MODULE_KEYPAD)
#include "NT68660_MODULE_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68668_DEMO_KEYPAD)
#include "NT68668_DEMO_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68669_DEMO_KEYPAD)
#include "NT68669_DEMO_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68671_DEMO_KEYPAD)
#include "NT68671_DEMO_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68672_DEMO_KEYPAD)
#include "NT68672_DEMO_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68673_DEMO_KEYPAD)
#include "NT68673_DEMO_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68674_DEMO_KEYPAD)
#include "NT68674_DEMO_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68675_DEMO_KEYPAD)
#include "NT68675_DEMO_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68676_DEMO_KEYPAD)
#include "NT68676_DEMO_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68677_DEMO_KEYPAD)
#include "NT68677_DEMO_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68750_DEMO_KEYPAD)
#include "NT68750_DEMO_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68776_DEMO_KEYPAD)
#include "NT68776_DEMO_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68777_DEMO_KEYPAD)
#include "NT68777_DEMO_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68778_DEMO_KEYPAD)
#include "NT68778_DEMO_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68779_DEMO_KEYPAD)
#include "NT68779_DEMO_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68750_DEMO_KEYPAD)
#include "NT68750_DEMO_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68751_DEMO_KEYPAD)
#include "NT68751_DEMO_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68752_DEMO_KEYPAD)
#include "NT68752_DEMO_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68753_DEMO_KEYPAD)
#include "NT68753_DEMO_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68750_MODULE_KEYPAD)
#include "NT68750_MODULE_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68360_DEMO_KEYPAD)
#include "NT68360_DEMO_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68360_MODULE_KEYPAD)
#include "NT68360_MODULE_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68364_MODULE_KEYPAD)
#include "NT68364_MODULE_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68652_DEMO_KEYPAD)
#include "NT68652_DEMO_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68652_MODULE_KEYPAD)
#include "NT68652_MODULE_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68169_DEMO_KEYPAD)
#include "NT68169_DEMO_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68169_MODULE_KEYPAD)
#include "NT68169_MODULE_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68169_FPGA_KEYPAD)
#include "NT68169_FPGA_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68169_RA_KEYPAD)
#include "NT68169_RA_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68661_DEMO_KEYPAD)
#include "NT68661_DEMO_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68661_MODULE_KEYPAD)
#include "NT68661_MODULE_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68661_FPGA_KEYPAD)
#include "NT68661_FPGA_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68770_DEMO_KEYPAD)
#include "NT68770_DEMO_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68770_MODULE_KEYPAD)
#include "NT68770_MODULE_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68662_MODULE_KEYPAD)
#include "NT68662_MODULE_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68850_DEMO_KEYPAD)
#include "NT68850_DEMO_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68850_MODULE_KEYPAD)
#include "NT68850_MODULE_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68655_DEMO_KEYPAD)
#include "NT68655_DEMO_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68655_MODULE_KEYPAD)
#include "NT68655_MODULE_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68857_DEMO_KEYPAD)
#include "NT68857_DEMO_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68857_MODULE_KEYPAD)
#include "NT68857_MODULE_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68859_DEMO_KEYPAD)
#include "NT68859_DEMO_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68859_MODULE_KEYPAD)
#include "NT68859_MODULE_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68150_FPGA_KEYPAD)
#include "NT68150_FPGA_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68150_DEMO_KEYPAD)
#include "NT68150_DEMO_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68150_MODULE_KEYPAD)
#include "NT68150_MODULE_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68150_RA_KEYPAD)
#include "NT68150_RA_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68790_MODULE_KEYPAD)
#include "NT68790_MODULE_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68790_DEMO_KEYPAD)
#include "NT68790_DEMO_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68658_FPGA_KEYPAD)
#include "NT68658_FPGA_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68658_DEMO_KEYPAD)
#include "NT68658_DEMO_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68658_MODULE_KEYPAD)
#include "NT68658_MODULE_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68810_FPGA_KEYPAD)
#include "NT68810_FPGA_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68810_MODULE_KEYPAD)
#include "NT68810_MODULE_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68810_MODULE_KEYPAD_80L)
#include "NT68810_MODULE_KEYPAD_80L\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68810_MODULE_KEYPAD_80A)
#include "NT68810_MODULE_KEYPAD_80A\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68810_DEMO_KEYPAD)
#include "NT68810_DEMO_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68870_FPGA_KEYPAD)
#include "NT68870_FPGA_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68870_MODULE_KEYPAD)
#include "NT68870_MODULE_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68860_MODULE_KEYPAD)
#include "NT68860_MODULE_KEYPAD\KeyPadConfig.h"
#elif (KEYPAD_TYPE == NT68890_DEMO_KEYPAD)
#include "NT68890_DEMO_KEYPAD\KeyPadConfig.h"
#else
#error "Unknown keypad type! Please define keypad type in model config file."
#endif

//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
extern UCHAR ScanKeyPad(void);
extern UCHAR GetKey(void);
#if 1//MD_ENABLE_AO_DETECT == ON
extern bit CheckFactoryMode(void);
#endif
#endif //__KEYPAD_H__
