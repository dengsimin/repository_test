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

#if ENABLE_SCALER_LEDDRV_ANA_MODE == ON
    SC_VREF_VOLTAGE_MODE3 = 0x0D;//0xE24
#endif
}

/**************************************************************************//**
 * Disable DBC function
 ******************************************************************************/
void DBCAPI_DisableDBC(void)
{
    WaitDisVSync();
    SC_DBC_CTRL &= ~BIT0;
    
#if ENABLE_SCALER_LEDDRV_ANA_MODE == ON
    SC_VREF_VOLTAGE_MODE3 = 0x0C;//0xE24
#endif    
}

/**************************************************************************//**
 * Load DBC LUT to scaler
 * @param ptab pointer to DBC LUT
 ******************************************************************************/
void DBCAPI_LoadTable(DBCTab *ptab)
{
    USHRT i;
    
#if DBC_TABLE_GENERATION == 1
    SC_DBC_INDEX_PORT = 0x10;
    for (i = 0; i <= 511; i++) {
        SC_DBC_INDEX_DATA = ptab->ucYGrayToLum[i];
    }
#elif DBC_TABLE_GENERATION == 2
    SC_DBC_INDEX_PORT = 0x10;
    for (i = 0; i <= 511; i=i+4) {
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
#if ENABLE_SCALER_LEDDRV == ON   
    if(DBCAPI_AbruptChange_IsEnable()){
    	SC_LEDDIMMING_CTRL &= ~BIT7;
    	SC_PWMA_CTRL1|=(BIT6|BIT3);
    	}
    else {
#if ENABLE_SCALER_LEDDRV_ANA_MODE == ON
     SC_LEDDIMMING_CTRL &= ~BIT7;
#else 
     SC_LEDDIMMING_CTRL |= BIT7;
#endif
    }
    SC_DBC_PWM_CTRL |= BIT7;
    
#if ENABLE_SCALER_LEDDRV_ANA_MODE == ON
//Only use the DBC Offset mode
    SC_DBC_PWM_CTRL &= ~(BIT5|BIT6);
    SC_DBC_PWM_CTRL |= BIT6; 
#endif

#else
#if IS_NT68770_SERIES
    switch ( port )
    {
      case PWM_A:
        SC_PWMA_CTRL1 |= BIT3;
        break;
      case PWM_B:
        SC_PWMB_CTRL1 |= BIT3;
        break;
      case PWM_C:
        SC_PWMC_CTRL1 |= BIT3;
        break;
      case PWM_D:
        SC_PWMD_CTRL1 |= BIT3;
        break;  
    }
#else
    switch ( pin )
    {
        case DBC_PIN_PWM_1:
            SC_MCU_IO_CTRL1 &= ~(BIT3|BIT2);
            SC_MCU_IO_CTRL1 |= BIT3;    
            break;
        case DBC_PIN_PWM_2:
            SC_MCU_IO_CTRL1 &= ~(BIT7|BIT6);
            SC_MCU_IO_CTRL1 |= BIT7;
            break;
        case DBC_PIN_PWM_3:
            SC_MCU_IO_CTRL1 &= ~(BIT5|BIT4);
            SC_MCU_IO_CTRL1 |= BIT5;        
            break;
        case DBC_PIN_PWM_4:
            SC_MCU_IO_CTRL3 &= ~(BIT7|BIT6);
            SC_MCU_IO_CTRL3 |= BIT7;
            break;
        case DBC_PIN_PWM_5:
            SC_MCU_IO_CTRL3 &= ~(BIT7|BIT6);
            SC_MCU_IO_CTRL3 |= BIT7;
            break;
        default:
            return;
    }
#endif    
    SC_DBC_PWM_CTRL |= BIT7;
/*    
    if (port == DBC_PIN_PWM_A) {
        SC_DBC_PWM_CTRL = (SC_DBC_PWM_CTRL&0x9F) | BIT5;
        SC_GI_SYNC_CTRL2 &= ~BIT1;
        SC_GPIO_CTRL |= BIT4;
        SC_MCU_IO_CTRL4 = (SC_MCU_IO_CTRL4&0x3F) | BIT7;
    }
    else if (port == DBC_PIN_PWM_B) {
        SC_DBC_PWM_CTRL = (SC_DBC_PWM_CTRL&0x9F) | BIT6;
        SC_GI_SYNC_CTRL2 &= ~BIT0;
        SC_GPIO_CTRL |= BIT5;
        SC_PWM_SELECT |= 0x82;
    }
*/
#endif
   port = 0;
   pin = 0;
}

/**************************************************************************//**
 * Disable DBC PWM control
 * @param port Assign DBC output port
 ******************************************************************************/
void DBCAPI_DisableDBCPWM(UCHAR port, UCHAR pin)
{
#if ENABLE_SCALER_LEDDRV==ON
    SC_DBC_PWM_CTRL &= ~BIT7;
    SC_LEDDIMMING_CTRL &= ~BIT7;
    SC_PWMA_CTRL1&=~(BIT6|BIT3);
#else
#if IS_NT68770_SERIES
     switch ( port )
     {
         case PWM_A:
            SC_PWMA_CTRL1 &= ~BIT3;
            break;
         case PWM_B:
            SC_PWMB_CTRL1 &= ~BIT3;
            break;
         case PWM_C:
            SC_PWMC_CTRL1 &= ~BIT3;
            break;
         case PWM_D:
            SC_PWMD_CTRL1 &= ~BIT3;
            break;  
     }
#else
    switch (pin)
    {
        case DBC_PIN_PWM_1:
            SC_MCU_IO_CTRL1 &= ~(BIT3|BIT2);
            SC_MCU_IO_CTRL1 |= BIT2;    
            break;
        case DBC_PIN_PWM_2:
            SC_MCU_IO_CTRL1 &= ~(BIT7|BIT6);
            SC_MCU_IO_CTRL1 |= BIT6;
            break;
        case DBC_PIN_PWM_3:
            SC_MCU_IO_CTRL1 &= ~(BIT5|BIT4);
            SC_MCU_IO_CTRL1 |= BIT4;        
            break;
        case DBC_PIN_PWM_4:
            SC_MCU_IO_CTRL3 &= ~(BIT7|BIT6);
            SC_MCU_IO_CTRL3 |= BIT6; 
            break;
        case DBC_PIN_PWM_5:
            SC_MCU_IO_CTRL3 &= ~(BIT7|BIT6);
            SC_MCU_IO_CTRL3 |= BIT6; 
            break;
        default:
            return;
    }
 #endif
 
    SC_DBC_PWM_CTRL &= ~BIT7;
#endif
    port = 0;
    pin = 0;
}

/**************************************************************************//**
 * Set DBC saving ratio
 * @param mode Saving ratio mode
 ******************************************************************************/
void DBCAPI_SetSavingRatio(UCHAR ratio1, UCHAR ratio2)
{
    SC_DBC_AVERAGE_MODE = (ratio2<<4) | ratio1;  //0x441 DBC Average Saving Mode
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
#if ENABLE_SCALER_LEDDRV_ANA_MODE == ON
//Only use the DBC offset mode
    SC_DBC_PWM_CTRL &= ~(BIT5|BIT6);
    SC_DBC_PWM_CTRL |= BIT6; 
#endif
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
 * Set abrupt change step function
 * @param step Abrupt step. Range is 0 ~ 3.
 ******************************************************************************/
void DBCAPI_SetAbruptStep(UCHAR step)
{
    SC_DBC_POSITION &= 0x9F;
	SC_DBC_POSITION |= (step<<5);
}

/**************************************************************************//**
 * Set abrupt change mode function
 * @param step Abrupt Mode. mode is 0 ~ 1.
 ******************************************************************************/
void DBCAPI_SetAbruptMode(UCHAR mode)
{
    SC_DBC_POSITION &= 0xEF;
	SC_DBC_POSITION |= (mode<<4);
}

/**************************************************************************//**
 * Disable abrupt change function
 ******************************************************************************/
void DBCAPI_DisableAbruptChange(void)
{
    SC_DBC_CTRL &= ~BIT3;
}

#if !IS_NT68770_SERIES && !IS_NT68850_SERIES && !IS_NT68655_SERIES && !IS_NT68150_SERIES && !IS_NT68790_SERIES && !IS_NT68658_SERIES
/**************************************************************************//**
 * Get active PWM duty.
 * @return Active PWM duty.
 ******************************************************************************/
UCHAR DBCAPI_GetActPWM(void)
{
    return SC_DBC_PWM_ACT;
}
#endif

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
#if 1//(IS_NT68655_SERIES || IS_NT68770_SERIES || IS_NT68850_SERIES )
#if ENABLE_SCALER_LEDDRV_ANA_MODE == ON
    max = (USHRT)GetLEDCurrentlimit()*max/255;
    min = (USHRT)GetLEDCurrentlimit()*max/255;
#endif        
    SC_DBC_PWM_OFFSET = max; //v07_121030_1800_SYS#1
    SC_DBC_PWM_MIN = min;
#else
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

    if (min > DBCAPI_GetActPWM())  {
        max = SC_DBC_AVERAGE_MODE;
        SC_DBC_AVERAGE_MODE &= 0xF8;
        WaitDisVSync();
        SC_DBC_AVERAGE_MODE = max;
    }
#endif
}

#if ENABLE_DBC_HW_DEBOUNCE == ON
/**************************************************************************//**
 * Set De-bouncing Mode
 * @param Bounce 0=off, 1:2, 2:4, 3:6, 4:10.
 ******************************************************************************/
void DBCAPI_SetDebouncingMode(UCHAR Bounce1, UCHAR Bounce2)
{
    SC_DBC_DEBOUNCINT_MODE = (Bounce2<<4) | Bounce1;    //0x442 DBC De-bouncing Mode
}

#endif

/**************************************************************************//**
 * Set Non-Linear Gain Slop
 * @param 
 ******************************************************************************/
void DBCAPI_SetNLGain(UCHAR Gain)
{
    SC_DBC_POSITION &= 0xF1;
    SC_DBC_POSITION |= (Gain<<1);
}

/*
void DBCAPI_EnableNLGain()
{
    SC_DBC_NON_LINEAR_GAIN_CTRL |= BIT0;
}
*/

void DBCAPI_DisableNLGain()
{
    SC_DBC_NON_LINEAR_GAIN_CTRL &= ~BIT0;
}

void DBCAPI_SetNLGainBreak(UCHAR BrkGain, UCHAR BrkGainRef)
{
    SC_DBC_NON_LINEAR_GAIN_CTRL = (SC_DBC_NON_LINEAR_GAIN_CTRL&0x01) | (BrkGain<<3) | (BrkGainRef<<1);
}

void DBCAPI_SetLUTGray2PWMLim(UCHAR Lim)
{
    SC_DBC_PWM_LUT_LIM = Lim;
}

void DBCAPI_SetLUTGray2GainLim(UCHAR Lim)
{
    SC_DBC_GRAY_LUT_LIM = Lim;
}

void DBCAPI_SetLUTRef(UCHAR mode)
{
    SC_DBC_EXT_CTRL = (SC_DBC_EXT_CTRL&0xBF) | (mode<<6);
}

#if DBC_TABLE_GENERATION != 0
/**************************************************************************//**
 * Set LUT point of gray to PWM limit control
 * @param limit LUT limit point
 ******************************************************************************/
void DBCAPI_SetGray2PwmLim(UCHAR limit)
{
    SC_DBC_PWM_LUT_LIM = limit;
}

/**************************************************************************//**
 * Set LUT point of gray to gain limit control
 * @param limit LUT limit point
 ******************************************************************************/
void DBCAPI_SetGray2GainLim(UCHAR limit)
{
    SC_DBC_GRAY_LUT_LIM = limit;
}
#endif

#if ENABLE_SCALER_LEDDRV == ON
/**************************************************************************//**
 * return if abrupt change function is enable or not
 ******************************************************************************/
BOOL DBCAPI_AbruptChange_IsEnable(void)
{
    if( (SC_DBC_CTRL & BIT3) && (SC_DBC_POSITION &(BIT6|BIT5))==0 )
    	return TRUE;
    else
    	return FALSE;
}
#endif

#endif //ENABLE_DBC == ON
