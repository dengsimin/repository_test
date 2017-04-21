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
#include "ScalerProfile.h"

//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************

//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************

//******************************************************************************
// E X T E R N A L   V A R I A B L E   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// S T A T I C   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// F U N C T I O N   B O D Y S
//******************************************************************************
/**************************************************************************//**
 * Configure the PWM output frequency.
 * @param port PWM output port. (e.x. PWMA, PWMB etc...)
 * @param pin PWM output pin.
 * @param freq Output frequency of PWM.
 ******************************************************************************/
void ConfigScalerPWM(UCHAR port, UCHAR pin, ULONG freq)
{
    ULONG total_div;
    UCHAR div_hi, div_lo, pwm_ctrl;
    USHRT base_div;

    //check freq
    total_div = (float)REF_CLK / freq - 0.5;
    if (total_div >= 1024) {
        pwm_ctrl = 10;
        base_div = 1024;
    }
    else if (total_div >= 256) {
        pwm_ctrl = 8;
        base_div = 256;
    }
    else {
        pwm_ctrl = 4;
        base_div = 16;
    }
    total_div = (float)REF_CLK / base_div / freq - 0.5;
    for (pwm_ctrl; pwm_ctrl<15; pwm_ctrl++) {
        if (total_div > 255) {
            total_div >>= 1;
        }
        else {
            break;
        }
    }
    div_hi = pwm_ctrl / 4;
    div_lo = pwm_ctrl % 4;
    if (port == PWM_A) {
        div_lo = div_lo << 1;
        pwm_ctrl = SC_PWM_CTRL1 & 0xF9;
        SC_PWM_CTRL1 = pwm_ctrl | div_lo;
        pwm_ctrl = SC_PWM_CTRL2 & 0xFC;
        SC_PWM_CTRL2 = pwm_ctrl | BIT4 | div_hi;
        SC_PWMA_LCNT = (UCHAR)total_div;
        SC_PWMA_HCNT = SC_PWMA_HCNT;

#if IS_NT68674_SERIES
        if (pin == PWMA_PD0) {
            SC_PWMA_OUTPUT_CTRL |= PD0_OUTPUT_EN;
        }
        else if (pin == PWMA_PC6) {
            SC_PWMA_OUTPUT_CTRL |= PC6_OUTPUT_EN;
        }
#endif
    }
    else if (port == PWM_B) {
        div_lo = div_lo << 5;
        div_hi = div_hi << 2;
        pwm_ctrl = SC_PWM_CTRL1 & 0x9F;
        SC_PWM_CTRL1 = pwm_ctrl | div_lo;
        pwm_ctrl = SC_PWM_CTRL2 & 0xF3;
        SC_PWM_CTRL2 = pwm_ctrl | BIT5 | div_hi;
        SC_PWMB_LCNT = (UCHAR)total_div;
        SC_PWMB_HCNT = SC_PWMB_HCNT;

#if IS_NT68674_SERIES
        if (pin == PWMB_PD1) {
            SC_PWMB_OUTPUT_CTRL |= PD1_OUTPUT_EN;
        }
        else if (pin == PWMB_PC5) {
            SC_PWMB_OUTPUT_CTRL |= PC5_OUTPUT_EN;
        }
        else if (pin == PWMB_PC2) {
            SC_PWMB_OUTPUT_CTRL |= PC2_OUTPUT_EN;
        }
#endif
    }

    pin = 0; // Disable compile warning only.
}

/**************************************************************************//**
 * Set PWM duty.
 * @param port PWM output port. (e.x. PWMA, PWMB etc...)
 * @param value PWM duty.
 ******************************************************************************/
void SetScalerPWM(UCHAR port, USHRT value)
{
    if (port == PWM_A) {
        SC_PWMA_DUTY_LO = ((UCHAR)value & 0x03);
        SC_PWMA_HCNT = (value >> 2);
        if (value == 0) {
            SC_PWM_CTRL2 &= ~BIT4;
        }
        else {
            SC_PWM_CTRL2 |= BIT4;
        }
    }
    else if (port == PWM_B) {
        SC_PWMB_DUTY_LO = ((UCHAR)value & 0x03);
        SC_PWMB_HCNT = (value >> 2);
        if (value == 0) {
            SC_PWM_CTRL2 &= ~BIT5;
        }
        else {
            SC_PWM_CTRL2 |= BIT5;
        }
    }
}

/**************************************************************************//**
 * Get current PWM duty setting.
 * @return PWM duty setting.
 ******************************************************************************/
/*
USHRT GetScalerPWM(UCHAR port)
{
    USHRT pwm;
    UCHAR ch;
    if (port == PWM_A) {
        pwm = SC_PWMA_HCNT;
        ch = SC_PWMA_DUTY_LO & 0x03;
        pwm = (pwm << 2) | ch;
    }
    else if (port == PWM_B) {
        pwm = SC_PWMB_HCNT;
        ch = SC_PWMB_DUTY_LO & 0x03;
        pwm = (pwm << 2) | ch;
    }
    return pwm;
}
*/

/**************************************************************************//**
 * Enable PWM function.
 ******************************************************************************/
void EnableScalerPWM(void)
{
    SC_GPIO_CTRL = 0x30; //Turn on PWMA/PWMB
}

/**************************************************************************//**
 * Disable PWM function.
 ******************************************************************************/
void DisableScalerPWM(void)
{
    SC_GPIO_CTRL = 0x00; //Turn off PWMA/PWMB
}

/**************************************************************************//**
 * Set the function of VSync-reset PWM duty.
 * @param port PWM output port.
 * @param on TRUE to turn on VSync-reset function else FALSE.
 ******************************************************************************/
void SetVSyncResetPWM(UCHAR port, UCHAR on)
{
    on &= BIT0;
    if (port == PWM_A) {
        SC_PWM_CTRL2 = (SC_PWM_CTRL2 & 0xBF) | (on << 6);
    }
    else if (port == PWM_B) {
        SC_PWM_CTRL2 = (SC_PWM_CTRL2 & 0x7F) | (on << 7);
    }
}
