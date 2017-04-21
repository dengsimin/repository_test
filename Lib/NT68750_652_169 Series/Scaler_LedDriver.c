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

#if ENABLE_SCALER_LEDDRV == ON

//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************
#define OVP_MAX_VOLTAGE (PANEL_LED_VOLTAGE_MAX * 1.13 + 1.5) /*!< The target voltage of OVP threshold. */
#define OVP_TYP_VOLTAGE (PANEL_LED_VOLTAGE_TYP * 1.06 + 1.5) /*!< The target voltage of OVP threshold. */
#define OVP_TH_MAX_VOL  24 /*!< The maximum value of OVP threshold. */
#define OVP_TH_MIN_VOL  8  /*!< The minimum value of OVP threshold. */
#define OVP_TH_STEPS    (OVP_TH_MAX_VOL - OVP_TH_MIN_VOL) /*!< Number of steps of OVP threshold. */
#define OVP_SD_VOLTAGE  (PANEL_LED_VOLTAGE_MAX * 1.15 + 1.5) /*!< The target voltage of OVP shutdown. */
#define OVP_SD_MAX_VOL  250 /*!< The maximum value of OVP shutdown. */
#define OVP_SD_MIN_VOL  120 /*!< The maximum value of OVP shutdown. */
#define OVP_SD_STEPS    (OVP_SD_MAX_VOL - OVP_SD_MIN_VOL) /*!< Number of steps of OVP shutdown. */

//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************
/*!
 * The LED driver initial table.
 * The values are recommended by APN.
 */
static code UCHAR ucLEDDrvInitTable[32] = LED_DRV_REG_TABLE;

//******************************************************************************
// E X T E R N A L   V A R I A B L E   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// S T A T I C   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
static UCHAR GetLEDOVPTH(BOOL type, USHRT r1, USHRT r2);
static UCHAR GetLEDOVPSD(USHRT r1, USHRT r2);
static UCHAR GetLEDCurrent(UCHAR current);

//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// F U N C T I O N   B O D Y S
//******************************************************************************

/**************************************************************************//**
 * Get LED OVP threshold.
 * Recommend detection voltage of OVP_TH = VLED_Max * 1.08 + 1.5V.
 * @param type TRUE to get high threshold, FALSE to get low threshold
 * @param r1 Resistor value of OVP on the PCBA.
 * @param r2 Resistor value of OVP on the PCBA.
 * @return Value of OVP threshold.
 ******************************************************************************/
static UCHAR GetLEDOVPTH(BOOL type, USHRT r1, USHRT r2)
{
    float ovp_th;
    UCHAR tmpreg;

    if (type == HIGH) {
        ovp_th = (float) 10 * OVP_MAX_VOLTAGE * r1 / (r1 + r2); // 0.1 volts
    }
    else {
        ovp_th = (float) 10 * OVP_TYP_VOLTAGE * r1 / (r1 + r2); // 0.1 volts
    }

    if (ovp_th > OVP_TH_MAX_VOL) {
        ovp_th = OVP_TH_MAX_VOL;
    }
    else if (ovp_th < OVP_TH_MIN_VOL) {
        ovp_th = OVP_TH_MIN_VOL;
    }

    tmpreg = (ovp_th - OVP_TH_MIN_VOL) * 127 / OVP_TH_STEPS;

    if (tmpreg > 127) {
        tmpreg = 127;
    }

    return tmpreg;
}

/**************************************************************************//**
 * Get LED OVP shutdown.
 * OVP_SD (V) = 1.2V,1.4V,1.6V,1.8V,1.95V,2.1V,2.3V,2.5V.
 * @param r1 Resistor value of OVP on the PCBA.
 * @param r2 Resistor value of OVP on the PCBA.
 * @return Value of OVP shutdown.
 ******************************************************************************/
static UCHAR GetLEDOVPSD(USHRT r1, USHRT r2)
{
    code UCHAR OVP_SD_Tab[] = {120, 140, 160, 180, 195, 210, 230, 250};
    float ovp_sd;
    UCHAR tmpreg;

    ovp_sd = (float) 100 * OVP_SD_VOLTAGE * r1 / (r1 + r2); // 0.1 volts

    if (ovp_sd > OVP_SD_MAX_VOL) {
        ovp_sd = OVP_SD_MAX_VOL;
    }
    else if (ovp_sd < OVP_SD_MIN_VOL) {
        ovp_sd = OVP_SD_MIN_VOL;
    }

    for (tmpreg = 0; tmpreg < (sizeof(OVP_SD_Tab) / sizeof(OVP_SD_Tab[0])); tmpreg++) {
        if (OVP_SD_Tab[tmpreg] >= ovp_sd) {
            break;
        }
    }

    if (tmpreg >= (sizeof(OVP_SD_Tab) / sizeof(OVP_SD_Tab[0]))) {
        tmpreg = (sizeof(OVP_SD_Tab) / sizeof(OVP_SD_Tab[0])) - 1;
    }

    tmpreg = (SC_LED_PROTECT_CTRL2 & 0xF8) | BIT6 | tmpreg;

    return tmpreg;
}

/**************************************************************************//**
 * Translate the panel current to LED driver current setting.
 * Per channel current = (0xE04 x 0.249mA + 9.76mA).
 * V_ref = 98% x current
 * @param current Current in panel spec. The unit is mA.
 * @return Value of LED current.
 ******************************************************************************/
static UCHAR GetLEDCurrent(UCHAR current)
{
    USHRT v_ref;
    UCHAR tmpreg;

    v_ref = (USHRT)98 * current; // mVolts
    tmpreg = ((ULONG) v_ref - 976) * 10 / 249;

    return tmpreg;
}

/**************************************************************************//**
 * Initialize LED driver registers.
 ******************************************************************************/
void InitLEDDriver(void)
{
    UCHAR xdata *ptr;
    UCHAR i, mask, str;

    mask = 1;
    str = 0;
    for (i = 0; i++; i < 8) {
        if ((PCBA_LEDSTR_EN & mask) != 0) {
            str++;
        }
        mask *= 2;
    }
    str /= PCBA_LEDSTR_PARALLEL;
    if (str != PANEL_LED_STR_NO) {
        // XXX
        // How to indicate the error of LED string setting.
    }

    ptr = &SC_LEDDRIVER_ENABLE;
    ptr[0] = ucLEDDrvInitTable[0];
    ptr[1] = PCBA_LEDSTR_EN;
    ptr[2] = ucLEDDrvInitTable[2];
    ptr[3] = GetLEDOVPSD(OVP_RLOWER, OVP_RUPPER);
    ptr[4] = GetLEDCurrent(PANEL_LED_BINCURRENT/PCBA_LEDSTR_PARALLEL);
    ptr[5] = GetLEDOVPTH(HIGH, OVP_RLOWER, OVP_RUPPER);
    for (i = 6; i < sizeof(ucLEDDrvInitTable); i++) {
        ptr[i] = ucLEDDrvInitTable[i];
    }
}

/**************************************************************************//**
 * Turn on/off LED driver.
 * @param on TRUE to turn on LED driver else FALSE.
 ******************************************************************************/
void LEDDriverOnOff(UCHAR on)
{
#if 1
    UCHAR led_string, pwm_duty1, pwm_duty2;
    UCHAR xdata *ptr;

    ptr = &SC_LEDDRIVER_ENABLE;

    if (on == ON) {
        SC_PWMA_CTRL1 = (SC_PWMA_CTRL1 & 0xFC) | 0x81;
        pwm_duty1 = SC_PWMA_CTRL4; // Backup PWM duty setting
        pwm_duty2 = SC_PWMA_CTRL5;
        led_string = ptr[0x01]; // Backup LED string enable setting
        SC_PWMA_CTRL5 = 0x00; // Set LSB of PWM duty as 00 to make sure the behavior of the shifter circuit as normal.
        SC_PWMA_CTRL4 = 0xFF; // Set max duty for faster discharge
        ptr[0x00] = 0x06; // Enable LED bias & dim
        Sleep(2); //Wait bias stable
        ptr[0x01] = 0x00; // Disable all LED strings
        ptr[0x1B] = 0x65; // Disable open/short detection
        ptr[0x05] = 0x00; // Set OVP to min for min VLED
        ptr[0x00] = 0x07;
        Sleep(2); // Wait for discharging COMP
        ptr[0x00] = 0x06;
        SC_PWMA_CTRL4 = pwm_duty1; // Restore PWM duty setting
        ptr[0x01] = led_string; // Restore LED string setting
        ptr[0x0A] = 0xF7; // Reduce EA driving current to reduce VLED overshoot
        ptr[0x1B] = 0xE5; // Enable open/short detection
        ptr[0x05] = GetLEDOVPTH(HIGH, OVP_RLOWER, OVP_RUPPER); // set OVP_TH to min
        ptr[0x06] = ucLEDDrvInitTable[6] | 0x50; // Clear open & short
        ptr[0x06] = ucLEDDrvInitTable[6];
        ptr[0x02] = 0xFB; // disable OCP_CP
        ptr[0x15] = 0xFF; // clear flag
        ptr[0x00] = 0x07; // enable LED DRV
        Sleep(20);
        ptr[0x0A] = ucLEDDrvInitTable[10]; // enhance current matching   0xE0A= 0xF7->0xF6->0xFC
        ptr[0x02] = 0xFF; // En OCP_CP
        if ((SC_LED_OPEN_STATUS == 0xFF) || (SC_LED_SHORT_STATUS == ptr[0x01])) {
            ptr[0x00] = 0x06; // 0x04
            ptr[0x15] = 0xFF; // clear flag
            ptr[0x06] = ucLEDDrvInitTable[6] | 0x50; // Clear open & short
            ptr[0x06] = ucLEDDrvInitTable[6];
            ptr[0x00] = 0x07; // enable LED DRV
        }
        // Restore the LSB of PWM duty
        SC_PWMA_CTRL5 = pwm_duty2;
        SC_PWMA_CTRL4 = pwm_duty1;
    }
    else {
        SC_PWMA_CTRL1 = (SC_PWMA_CTRL1 & 0x7C) | 0x01;
        SC_LEDDRIVER_ENABLE = 0x00;
    }
#else
    UCHAR xdata *ptr;

    ptr = &SC_LEDDRIVER_ENABLE;
    if (on == ON) {
        SC_PWMA_CTRL1 = (SC_PWMA_CTRL1 & 0xFC) | 0x81;
        ptr[0x00] = 0x06;
        ptr[0x0A] = 0xF7;
        ptr[0x05] = GetLEDOVPTH(HIGH, OVP_RLOWER, OVP_RUPPER);
        Sleep(2); //Wait bias stable
        ptr[0x06] = ucLEDDrvInitTable[6] | 0x50; // Clear open & short
        ptr[0x06] = ucLEDDrvInitTable[6];
        ptr[0x02] = 0xFB; // disable OCP_CP
        ptr[0x15] = 0xFF; // clear flag     
        ptr[0x00] = 0x07; // enable LED DRV
        Sleep(5);
        ptr[0x0A] = ucLEDDrvInitTable[10];
        ptr[0x02] = 0xFF; // En OCP_CP
        ptr[0x05] = GetLEDOVPTH(HIGH, OVP_RLOWER, OVP_RUPPER);
        if (ptr[0x13] == 0xFF) {
            ptr[0x00] = 0x06;
            ptr[0x15] = 0xFF; // clear flag     
            ptr[0x06] = ucLEDDrvInitTable[6] | 0x50; // Clear open & short
            ptr[0x06] = ucLEDDrvInitTable[6];
            ptr[0x00] = 0x07; // enable LED DRV
        }
    }
    else {
        SC_PWMA_CTRL1 = (SC_PWMA_CTRL1 & 0x7C) | 0x01;
        SC_LEDDRIVER_ENABLE = 0x00;
    }
#endif
}

/**************************************************************************//**
 * Set the LED driver PWM frequency
 * @param freq PWM frequency (22000Hz ~ 22Hz).
 ******************************************************************************/
void SetLEDDriverFreq(USHRT freq)
{
    UCHAR ch;
    USHRT div;

    SC_PWMA_CTRL1 = (SC_PWMA_CTRL1 & 0xFC) | 0x01;
    if (freq > 22000) {
        freq = 22000;
    }
    div = (USHRT) ((float) REF_CLK * 8 / 4096 / freq - 0.5);
    ch = (div >> 4) & 0x30;
    SC_PWMA_CTRL2 = 0x0C | ch;
    SC_PWMA_CTRL3 = (UCHAR) div;
}
#endif //ENABLE_SCALER_LEDDRV == ON
