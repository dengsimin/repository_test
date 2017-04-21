/******************************************************************************/
/*                       Novatek MicroElectronics Corp.                       */
/*       6F, No. 1-2, Innovation Road I, Science-Based Industrial Park,       */
/*                         HsinChu 300, Taiwan, R.O.C.                        */
/*                 TEL:886-3-567-0889       FAX:886-3-577-0132                */
/*                            All Rights Reserved                             */
/******************************************************************************/
#if 1

#ifndef __KEYPAD_CONFIG_H__
#define __KEYPAD_CONFIG_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "Board.h"
#include "Typedef.h"

//******************************************************************************
// G L O B A L   D E F I N I T I O N S
//******************************************************************************
/*******************************************************************************
                         Specific ADC code of AD key
*******************************************************************************/
#define KEY_TYP_LEVEL0      0x28//0x3f                     //40            //51
#define KEY_TYP_LEVEL1      0x3f//0x57                     //63            //79
#define KEY_TYP_LEVEL2      0x60//0x70                     //96            //109
#define KEY_TYP_LEVEL3      0x7a                       //122  

/*******************************************************************************
                           Specific key stable time
*******************************************************************************/
#define KEY_STABLE_TIME     50

/*******************************************************************************
                            Specific keypad layout
*******************************************************************************/
// Do not apply any change to BTN_CODE_#
#define BTN_CODE_1          0x01
#define BTN_CODE_2          0x02
#define BTN_CODE_3          0x04
#define BTN_CODE_4          0x08
#define BTN_CODE_5          0x10
#define BTN_CODE_6          0x20
#define BTN_CODE_7          0x40
#define BTN_CODE_8          0x80

// Define active AD key
#define ADGRP1_CODE_1       BTN_CODE_1//BTN_CODE_1 //p
#define ADGRP1_CODE_2       BTN_CODE_2//BTN_CODE_2 //<-
#define ADGRP1_CODE_3       BTN_CODE_3//BTN_CODE_4 //M

#define ADGRP2_CODE_1       BTN_CODE_4//BTN_CODE_6 //->
#define ADGRP2_CODE_2       BTN_CODE_5//BTN_CODE_3 //A
#define ADGRP2_CODE_3       BTN_CODE_6//0X00//BTN_CODE_6

// Define active IO key
#define IOBTN_CODE_1        0x00
#define IOBTN_CODE_2        0x00
#define IOBTN_CODE_3        0x00
#define IOBTN_CODE_4        0x00
#define IOBTN_CODE_5        0x00
#define IOBTN_CODE_6        0x00
#define IOBTN_CODE_7        0x00
#define IOBTN_CODE_8        BTN_CODE_8

// Use the following defines to change the order of keypad layout
#define KEYCODE_PWR         ADGRP1_CODE_1//IOBTN_CODE_8
#define KEYCODE_MENU        ADGRP1_CODE_2//ADGRP2_CODE_1//ADGRP1_CODE_3//ADGRP1_CODE_2
#define KEYCODE_AUTO        ADGRP2_CODE_1//ADGRP1_CODE_2//ADGRP2_CODE_2//ADGRP2_CODE_1
#define KEYCODE_INPUT       0x00
#define KEYCODE_FUNC        0x00
#define KEYCODE_UP          ADGRP2_CODE_2//ADGRP1_CODE_2//ADGRP2_CODE_2
#define KEYCODE_DOWN        ADGRP1_CODE_3//ADGRP2_CODE_3//ADGRP1_CODE_1
#define KEYCODE_LEFT        0x00
#define KEYCODE_RIGHT       0x00
#define KEYCODE_FACT       (KEYCODE_PWR|KEYCODE_AUTO)
#define KEYCODE_DEMO        0x00
#define KEYCODE_PWLOCK      0x00
#define KEYCODE_OSDLOCK     0x00
#define KEYCODE_TMG_SW      0x00

#endif //__KEYPAD_CONFIG_H__

#else
#ifndef __KEYPAD_CONFIG_H__
#define __KEYPAD_CONFIG_H__

//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "Board.h"
#include "Typedef.h"

//******************************************************************************
// G L O B A L   D E F I N I T I O N S
//******************************************************************************
/*******************************************************************************
                         Specific ADC code of AD key
*******************************************************************************/
#define KEY_TYP_LEVEL0      0x28//0x3f                     //40            //51
#define KEY_TYP_LEVEL1      0x3f//0x57                     //63            //79
#define KEY_TYP_LEVEL2      0x60//0x70                     //96            //109
#define KEY_TYP_LEVEL3      0x7a                       //122  

/*******************************************************************************
                           Specific key stable time
*******************************************************************************/
#define KEY_STABLE_TIME     50

/*******************************************************************************
                            Specific keypad layout
*******************************************************************************/
// Do not apply any change to BTN_CODE_#
#define BTN_CODE_1          0x01
#define BTN_CODE_2          0x02
#define BTN_CODE_3          0x04
#define BTN_CODE_4          0x08
#define BTN_CODE_5          0x10
#define BTN_CODE_6          0x20
#define BTN_CODE_7          0x40
#define BTN_CODE_8          0x80

// Define active AD key
#define ADGRP1_CODE_1       BTN_CODE_1 //p
#define ADGRP1_CODE_2       BTN_CODE_2 //<-
#define ADGRP1_CODE_3       BTN_CODE_4 //M

#define ADGRP2_CODE_1       BTN_CODE_6 //->
#define ADGRP2_CODE_2       BTN_CODE_3 //A
#define ADGRP2_CODE_3       0X00//BTN_CODE_6

// Define active IO key
#define IOBTN_CODE_1        0x00
#define IOBTN_CODE_2        0x00
#define IOBTN_CODE_3        0x00
#define IOBTN_CODE_4        0x00
#define IOBTN_CODE_5        0x00
#define IOBTN_CODE_6        0x00
#define IOBTN_CODE_7        0x00
#define IOBTN_CODE_8        BTN_CODE_8

// Use the following defines to change the order of keypad layout
#define KEYCODE_PWR         BTN_CODE_1//IOBTN_CODE_8
#define KEYCODE_MENU        BTN_CODE_4//ADGRP1_CODE_2
#define KEYCODE_AUTO        BTN_CODE_3//ADGRP2_CODE_1
#define KEYCODE_INPUT       0x00
#define KEYCODE_FUNC        0x00
#define KEYCODE_UP          BTN_CODE_2//ADGRP2_CODE_2
#define KEYCODE_DOWN        BTN_CODE_6//ADGRP1_CODE_1
#define KEYCODE_LEFT        0x00
#define KEYCODE_RIGHT       0x00
#define KEYCODE_FACT       (KEYCODE_PWR|KEYCODE_AUTO)
#define KEYCODE_DEMO        0x00
#define KEYCODE_PWLOCK      0x00
#define KEYCODE_OSDLOCK     0x00
#define KEYCODE_TMG_SW      0x00

#endif //__KEYPAD_CONFIG_H__
#endif
