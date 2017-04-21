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

#if ENABLE_SCALER_LEDDRV == ON

//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************
#define OVP_TH_VOLTAGE  (PANEL_LED_VOLTAGE_TYP + 3) /*!< The target voltage of OVP threshold. */
#define OVP_TH_MAX_VOL  24 /*!< The maximum value of OVP threshold. */
#define OVP_TH_MIN_VOL  8  /*!< The minimum value of OVP threshold. */
#define OVP_TH_STEPS    (OVP_TH_MAX_VOL - OVP_TH_MIN_VOL) /*!< Number of steps of OVP threshold. */
#define OVP_SD_VOLTAGE  PANEL_LED_VOLTAGE_MAX /*!< The target voltage of OVP shutdown. */
#define OVP_SD_MAX_VOL  26 /*!< The maximum value of OVP shutdown. */
#define OVP_SD_MIN_VOL  12 /*!< The maximum value of OVP shutdown. */
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
static code UCHAR ucLEDDrvInitTable[32] = {
    0x00, 0xFF, 0x00, 0x03, 0x2F, 0x3B, 0x8F, 0x08,
    0x70, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00,
    0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xCC,
    0x02, 0x80, 0x00, 0x6D, 0x2E, 0x0F, 0xFF, 0x00
};

//******************************************************************************
// E X T E R N A L   V A R I A B L E   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// S T A T I C   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
static UCHAR GetLEDOVPTH(USHRT r1, USHRT r2);
static UCHAR GetLEDOVPSD(USHRT r1, USHRT r2);

//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// F U N C T I O N   B O D Y S
//******************************************************************************

/**************************************************************************//**
 * Get LED OVP threshold.
 * @param r1 Resistor value of OVP on the PCBA.
 * @param r2 Resistor value of OVP on the PCBA.
 * @return Value of OVP threshold.
 ******************************************************************************/
static UCHAR GetLEDOVPTH(USHRT r1, USHRT r2)
{
    UCHAR ovp_th;
    UCHAR tmpreg;

    ovp_th = (UCHAR) ((ULONG) 10 * OVP_TH_VOLTAGE * r1 / (r1 + r2)); // 0.1 volts

    if (ovp_th > OVP_TH_MAX_VOL) {
        ovp_th = OVP_TH_MAX_VOL;
    }
    else if (ovp_th < OVP_TH_MIN_VOL) {
        ovp_th = OVP_TH_MIN_VOL;
    }

    tmpreg = (USHRT) (ovp_th - OVP_TH_MIN_VOL) * 0x7F / OVP_TH_STEPS;
    if (tmpreg < 0x7F) {
        tmpreg = tmpreg + 1;
    }

    return tmpreg;
}

/**************************************************************************//**
 * Get LED OVP shutdown.
 * @param r1 Resistor value of OVP on the PCBA.
 * @param r2 Resistor value of OVP on the PCBA.
 * @return Value of OVP shutdown.
 ******************************************************************************/
static UCHAR GetLEDOVPSD(USHRT r1, USHRT r2)
{
    UCHAR ovp_sd;
    UCHAR tmpreg;

    ovp_sd = (UCHAR) ((ULONG) 10 * OVP_SD_VOLTAGE * r1 / (r1 + r2)); // 0.1 volts

    if (ovp_sd > OVP_SD_MAX_VOL) {
        ovp_sd = OVP_SD_MAX_VOL;
    }
    else if (ovp_sd < OVP_SD_MIN_VOL) {
        ovp_sd = OVP_SD_MIN_VOL;
    }

    tmpreg = (ULONG) (ovp_sd - OVP_SD_MIN_VOL) * 0x07 / OVP_SD_STEPS;
    if (tmpreg < 0x07) {
        tmpreg = tmpreg + 1;
    }
    tmpreg = (SC_LED_PROTECT_CTRL2 & 0xF8) | tmpreg;

    return tmpreg;
}

/**************************************************************************//**
 * Translate the panel current to LED driver current setting.
 * @param current Current in panel spec. The unit is mA.
 * @return Value of LED current.
 ******************************************************************************/
static UCHAR GetLEDCurrent(UCHAR current)
{
    USHRT v_ref;
    UCHAR tmpreg;

    v_ref = (USHRT)125 * current; // mVolts
    tmpreg = ((ULONG) v_ref - 113) * 0xFF / (9750 - 1130);

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
    ptr[5] = GetLEDOVPTH(OVP_RLOWER, OVP_RUPPER);
    for (i = 6; i < sizeof(ucLEDDrvInitTable); i++) {
        *ptr = ucLEDDrvInitTable[i];
        ptr++;
    }
}

/**************************************************************************//**
 * Turn on/off LED driver.
 * @param on TRUE to turn on LED driver else FALSE.
 ******************************************************************************/
void LEDDriverOnOff(UCHAR on)
{
    if (on == ON) {
        SC_LEDDRIVER_ENABLE = 0x04; // enable LED bias
        SC_PWMA_CTRL1 = (SC_PWMA_CTRL1 & 0xFC) | 0x81;
        Sleep(100);
        SC_LEDPROTECT_ENABLE = 0x4D; // disable OCP_CP
        SC_LEDSTATUS = 0xFF; // clear flag
        SC_LEDDRIVER_ENABLE = 0x05;
        Sleep(100);
        SC_LEDDRIVER_ENABLE = 0x07; // enable LED DRV
        Sleep(200); // wait power up for soft start
        SC_LEDSTATUS = 0xFF; // clear flag again
        SC_LEDPROTECT_ENABLE = 0x6D; // enable OCP_CP
    }
    else {
        SC_PWMA_CTRL1 = (SC_PWMA_CTRL1 & 0x7C) | 0x01;
        SC_LEDDRIVER_ENABLE = 0x00;
    }
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
