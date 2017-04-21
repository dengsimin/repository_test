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
#include "include.h"

#if ENABLE_DBC == ON

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
 * Enable DBC function
 ******************************************************************************/
void DBCAPI_EnableDBC(void)
{
    WaitDisVSync();
    SC_DBC_CTRL |= BIT0;
}

/**************************************************************************//**
 * Disable DBC function
 ******************************************************************************/
void DBCAPI_DisableDBC(void)
{
    WaitDisVSync();
    SC_DBC_CTRL &= ~BIT0;
}

/**************************************************************************//**
 * Load DBC LUT to scaler
 * @param ptab pointer to DBC LUT
 ******************************************************************************/
void DBCAPI_LoadTable(DBCTab *ptab)
{
    USHRT i;
    
    ResetWDTimer();
#if DBC_TABLE_GENERATION == 1
    SC_DBC_INDEX_PORT = 0x10;
    for (i = 0; i <= 511; i++) {
        SC_DBC_INDEX_DATA = ptab->ucYGrayToLum[i];
    }
#else
    SC_DBC_INDEX_PORT = 0x10;
    for (i = 0; i <= 255; i++) {
        SC_DBC_INDEX_DATA = ptab->ucYGrayToLum[i];
    }
    SC_DBC_INDEX_PORT = 0x20;
    for (i = 0; i <= 255; i++) {
        SC_DBC_INDEX_DATA = ptab->ucPWMToLum[i];
    }
    SC_DBC_INDEX_PORT = 0x30;
    for (i = 0; i <= 255; i++) {
        SC_DBC_INDEX_DATA = ptab->ucPWMToMult[i];
    }
#endif    
    SC_DBC_INDEX_PORT = 0x00;
    ResetWDTimer();
}

/**************************************************************************//**
 * Configure PWM port and frequency
 * @param freq PWM frequency of DBC. We limit the frequency to 60Hz ~ 11KHz
 * @param div  Dividor of DBC PWM
 ******************************************************************************/
void DBCAPI_ConfigPWM(USHRT freq, UCHAR div)
{
    ULONG total_div;

    // Limit the PWM frequency from 60Hz to 11KHz for keeping the number of 
    // adjustment steps as 1024.
    if (freq > 11000) {
        freq = 11000; 
    }
    if (freq < 60) {
        freq = 60; 
    }

    SC_DBC_CTRL &= ~BIT2;

    total_div = (float)REF_CLK / freq - 0.5;
    total_div = total_div / 1024;

    div <<= 6;
    SC_DBC_PWM_DIV1 = (SC_DBC_PWM_DIV1 & BIT5) | 0x1A | div;
    SC_DBC_PWM_DIV2 = (UCHAR)total_div;
    SC_DBC_PWM_DUTY = 0xFF;

    // Force DBC prior to Gamma
    SC_DBC_POSITION |= BIT0;
}

/**************************************************************************//**
 * Enable DBC PWM control
 * @param port Assign DBC output port
 ******************************************************************************/
void DBCAPI_EnableDBCPWM(UCHAR port, UCHAR pin)
{
	pin=0;//to avoid compile warnning
#if IS_NT68660_SERIES
    if (port == DBC_PIN_PWM_A) {
        if ((SC_MCU_IO_CTRL3 & 0x0C) == 0x04) {
            SC_MCU_IO_CTRL3 &= 0xF3;
            SC_MCU_IO_CTRL3 |= 0x08;
        }
        else if ((SC_MCU_IO_CTRL2 & 0x0C) == 0x04) {
            SC_MCU_IO_CTRL2 &= 0xF3;
            SC_MCU_IO_CTRL2 |= 0x08;
        }
    }
    else if (port == DBC_PIN_PWM_D) {
        if ((SC_MCU_IO_CTRL & 0x30) == 0x10) {
            SC_MCU_IO_CTRL &= 0xCF;
            SC_MCU_IO_CTRL |= 0x20;
        }
        else if ((SC_MCU_IO_CTRL & 0x0C) == 0x04) {
            SC_MCU_IO_CTRL &= 0xF3;
            SC_MCU_IO_CTRL |= 0x08;
        }
    }
#elif IS_NT68650_SERIES
    SC_LEDDIMMING_CTRL |= BIT7;
    port = 0;
#else
    if (port == DBC_PIN_PWM_A) {
        SC_DBC_PWM_CTRL = (SC_DBC_PWM_CTRL&0x9F) | BIT5;
        SC_GI_SYNC_CTRL2 &= ~BIT1;
        SC_GPIO_CTRL |= BIT4;
    }
    else if (port == DBC_PIN_PWM_B) {
        SC_DBC_PWM_CTRL = (SC_DBC_PWM_CTRL&0x9F) | BIT6;
        SC_GI_SYNC_CTRL2 &= ~BIT0;
        SC_GPIO_CTRL |= BIT5;
    }
#endif
    SC_DBC_PWM_CTRL |= BIT7;
}

/**************************************************************************//**
 * Disable DBC PWM control
 * @param port Assign DBC output port
 ******************************************************************************/
void DBCAPI_DisableDBCPWM(UCHAR port, UCHAR pin)
{
	pin=0;//to avoid compile warnning
#if IS_NT68660_SERIES
    SC_DBC_PWM_CTRL &= ~BIT7;
    if (port == DBC_PIN_PWM_A) {
        if ((SC_MCU_IO_CTRL3 & 0x0C) == 0x08) {
            SC_MCU_IO_CTRL3 &= 0xF3;
            SC_MCU_IO_CTRL3 |= 0x04;
        }
        else if ((SC_MCU_IO_CTRL2 & 0x0C) == 0x08) {
            SC_MCU_IO_CTRL2 &= 0xF3;
            SC_MCU_IO_CTRL2 |= 0x04;
        }
    }
    else if (port == DBC_PIN_PWM_D) {
        if ((SC_MCU_IO_CTRL & 0x30) == 0x20) {
            SC_MCU_IO_CTRL &= 0xCF;
            SC_MCU_IO_CTRL |= 0x10;
        }
        else if ((SC_MCU_IO_CTRL & 0x0C) == 0x08) {
            SC_MCU_IO_CTRL &= 0xF3;
            SC_MCU_IO_CTRL |= 0x04;
        }
    }
#elif IS_NT68650_SERIES
    SC_DBC_PWM_CTRL &= ~BIT7;
    SC_LEDDIMMING_CTRL &= ~BIT7;
    port = 0;
#else
    if (port == DBC_PIN_PWM_A) {
        SC_DBC_PWM_CTRL &= ~(BIT7|BIT5);
    }
    else if (port == DBC_PIN_PWM_B) {
        SC_DBC_PWM_CTRL &= ~(BIT7|BIT6);
    }
#endif
}

/**************************************************************************//**
 * Set DBC saving ratio
 * @param mode Saving ratio mode
 ******************************************************************************/
void DBCAPI_SetSavingRatio(UCHAR ratio1, UCHAR ratio2)
{
#if IS_NT68168_SERIES || IS_NT68668_SERIES
    if (ratio1 == DBC_SAVING_MODE_MAX) {
        SC_DBC_PWM_CTRL &= ~BIT4;
    }
    else {
        SC_DBC_PWM_CTRL |= BIT4;
    }
#else
    SC_DBC_AVERAGE_MODE &= 0xF8;
    SC_DBC_AVERAGE_MODE |= ratio1;
#endif
   ratio2 = 0;
}

/**************************************************************************//**
 * Set PWM adjustment rate and step size
 * @param rate DBC control adjustment rate. The range is 0 ~ 15.
 * @param step DBC control adjustment step size. The range is 0 ~ 15.
 ******************************************************************************/
void DBCAPI_SetPWMAdjustment(UCHAR rate, UCHAR step)
{
    SC_DBC_ADJ = ((rate & 0x0F) << 4);
    SC_DBC_ADJ |= step & 0x0F;
}

/**************************************************************************//**
 * Set the polarity of DBC PWM
 * @param inv Invert PWM polarity
 ******************************************************************************/
void DBCAPI_SetPWMInvert(BOOL inv)
{
    if (inv) {
        SC_DBC_PWM_DIV1 |= BIT5;
    }
    else {
        SC_DBC_PWM_DIV1 &= ~BIT5;
    }
}

/**************************************************************************//**
 * Enable RGB compensation
 ******************************************************************************/
void DBCAPI_EnableRGBCompensation(void)
{
    SC_DBC_CTRL |= BIT1;
}

/**************************************************************************//**
 * Disable RGB compensation
 ******************************************************************************/
void DBCAPI_DisableRGBCompensation(void)
{
    SC_DBC_CTRL &= ~BIT1;
}

/**************************************************************************//**
 * Set the allowable distortion
 * @param distort The allowable distortion
 ******************************************************************************/
void DBCAPI_SetDistortion(UCHAR distort)
{
    SC_DBC_PWM_CTRL = (SC_DBC_PWM_CTRL & 0xF0) | (distort & 0x0F);
}

/**************************************************************************//**
 * Enable abrupt change function
 * @param thd Threshold of difference of current frame and previous frame. Range is 0 ~ 15.
 ******************************************************************************/
void DBCAPI_EnableAbruptChange(UCHAR thd)
{
    SC_DBC_CTRL = (SC_DBC_CTRL & 0x0F) | ((thd & 0x0F) << 4);
    SC_DBC_CTRL |= BIT3;
}

/**************************************************************************//**
 * Disable abrupt change function
 ******************************************************************************/
void DBCAPI_DisableAbruptChange(void)
{
    SC_DBC_CTRL &= ~BIT3;
}

/**************************************************************************//**
 * Get current PWM offset
 * @return Return PWM offset
 ******************************************************************************/
UCHAR DBCAPI_GetPWMOffset(void)
{
    return SC_DBC_PWM_OFFSET;
}

/**************************************************************************//**
 * Get active PWM duty.
 * @return Active PWM duty.
 ******************************************************************************/
UCHAR DBCAPI_GetActPWM(void)
{
    return SC_DBC_PWM_ACT;
}

#if ENABLE_DBC == ON && ENABLE_DBC_HW_DEBOUNCE == OFF
/**************************************************************************//**
 * Get average Y of current display
 * @return Average Y of current image.
 ******************************************************************************/
UCHAR DBCAPI_GetAverageY(void)
{
    return SC_DBC_AVG_Y;
}

/**************************************************************************//**
 * Get the effect color value of current display
 * @return Effective color value
 ******************************************************************************/
UCHAR DBCAPI_GetEffectiveColor(void)
{
    return SC_EFFECTIVE_COLOR_VALUE;
}
#endif

/**************************************************************************//**
 * Set minimum and maximum PWM duty
 * @param min Set minimum PWM duty. The range is 0 ~ 255.
 * @param max Set maximum PWM duty. The range is 0 ~ 255.
 ******************************************************************************/
void DBCAPI_SetDBCMinMax(UCHAR min, UCHAR max)
{
    UCHAR duty_div;
    USHRT duty_range;
    USHRT min_duty, max_duty;
    UCHAR offset;
    
    if (max < min) return;
    
    duty_div   = ((SC_DBC_PWM_DIV1 >> 6) + 1);
    duty_range = (USHRT)duty_div * 256 - 1;

    min_duty = (ULONG)min * 1019 / 255 + 4;
    max_duty = (ULONG)max * 1019 / 255 + 4;
    
    if (max_duty >= duty_range) {
        offset = (max_duty - duty_range) / 4;
    }
    else {
        offset = (1024 + max_duty - duty_range) / 4;
    }
    
    // Force the difference of max_duty and min_duty is smaller than duty_range
    if ((min_duty + duty_range) < max_duty)
        min_duty = max_duty - duty_range;

    min = (min_duty + duty_range - max_duty) / duty_div;

    SC_DBC_PWM_OFFSET = offset;
    SC_DBC_PWM_MIN = min;
#if IS_NT68168_SERIES || IS_NT68668_SERIES
    if (min > DBCAPI_GetActPWM())  {
        offset = SC_DBC_PWM_CTRL;
        SC_DBC_PWM_CTRL &= ~BIT4;
        WaitDisVSync();
        SC_DBC_PWM_CTRL = offset;
    }
#endif
}

#if IS_NT68650_SERIES || IS_NT68660_SERIES
#if ENABLE_DBC_HW_DEBOUNCE == ON
/**************************************************************************//**
 * Set De-bouncing Mode
 * @param Bounce 0=off, 1:2, 2:4, 3:6, 4:10.
 ******************************************************************************/
void DBCAPI_SetDebouncingMode(UCHAR Bounce1, UCHAR Bounce2)
{
    switch (Bounce1) {
    case 0:
        SC_DBC_DEBOUNCINT_MODE = 0x00;
        break;
    case 1:
        SC_DBC_DEBOUNCINT_MODE = 0x01;
        break;
    case 2:
        SC_DBC_DEBOUNCINT_MODE = 0x03;
        break;
    case 3:
        SC_DBC_DEBOUNCINT_MODE = 0x05;
        break;
    case 4:
        SC_DBC_DEBOUNCINT_MODE = 0x07;
        break;
    }

    Bounce2 = 0;
}
#endif
#endif

#endif //ENABLE_DBC == ON
