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
#define HSYNC_LOWER_BOUND   12   /*!< The lower bound of valid HSync frequency. The unit is KHz. */
#define HSYNC_UPPER_BOUND   200  /*!< The upper bound of valid HSync frequency. The unit is KHz. */
#define VSYNC_LOWER_BOUND   20   /*!< The lower bound of valid VSync frequency. The unit is Hz. */
#define VSYNC_UPPER_BOUND   200  /*!< The upper bound of valid VSync frequency. The unit is Hz. */
#define H_CNT_LOW_THLD      (8UL*REF_CLK/1000/HSYNC_UPPER_BOUND) /*!< The low threshold of valid HSync counter. */
#define H_CNT_HIGH_THLD     (8UL*REF_CLK/1000/HSYNC_LOWER_BOUND) /*!< The high threshold of valid HSync counter. */
#define V_CNT_LOW_THLD      (1UL*REF_CLK/256/VSYNC_UPPER_BOUND)  /*!< The low threshold of valid VSync counter. */
#define V_CNT_HIGH_THLD     (1UL*REF_CLK/256/VSYNC_LOWER_BOUND)  /*!< The high threshold of valid VSync counter. */
#define DIG_VALID_PIXEL_RATE 22

//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************
xdata USHRT usHSyncFreq; /*!< HSync frequency. The unit is 0.1KHz. */
xdata USHRT usVSyncFreq; /*!< VSync frequency. The unit is 0.1Hz. */
xdata UCHAR ucZpInterface; /*!< Interface ID in the zero power mode. */

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************

//******************************************************************************
// E X T E R N A L   V A R I A B L E   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// S T A T I C   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************
static BOOL CheckSOG(void);
static BOOL ZpSyncDetect(void);

//******************************************************************************
// E X T E R N A L   F U N C T I O N   P R O T O T Y P E S
//******************************************************************************

//******************************************************************************
// F U N C T I O N   B O D Y S
//******************************************************************************

/**************************************************************************//**
 * Initialize Sync-related registers.
 ******************************************************************************/
void SyncInit(void)
{
    SC_GI_SYNC_CTRL = 0x24;
    SC_GI_SYNC_CTRL2 = 0xC0;
    SC_GI_SYNC_CTRL3 = 0x42;
    SC_HPRE_THR_LO = 0x00;
    SC_HPRE_THR_HI = 0x1F;
    SC_VPRE_THR_LO = 0x13;
    SC_VPRE_THR_HI = 0x42;
    SC_HCNT_THR = 0x04;
    SC_V_CHANG_CTRL = 0x24;
    SC_SYNC_INT_EN1 = 0x3C;
    SC_SYNC_INT_EN2 = 0x07;
    SC_SYNC_INT_FLAG1 = 0x3F;
    SC_SYNC_INT_FLAG2 = 0x1F;
    SC_GI_FIELD_WIN = 0xC5;

    SC_NEW_HSYNC_CTRL1 |= BIT0;
    SC_FAST_MUTE_CTRL = 0x4A;
    SC_FIELD_POLARITY_CTRL = 0x02;
}

/**************************************************************************//**
 * Get current input HSync frequency.
 * The unit is 0.1KHz.
 * @return Input HSync frequency.
 ******************************************************************************/
USHRT GetInputHFreq(void)
{
    USHRT cnt;

    cnt = ReadShortScaler(&SC_GI_HCNT_LO) & 0x1FFF;

    // Valid HSync range : 12KHz < HS < 200KHz
    if ((cnt > H_CNT_HIGH_THLD) || (cnt < H_CNT_LOW_THLD)) {
        usHSyncFreq = 0xFFFF;
    }
    else {
        usHSyncFreq = (USHRT) ((8UL * REF_CLK / cnt + 50) / 100);
    }

    return usHSyncFreq;
}

/**************************************************************************//**
 * Get current input VSync frequency.
 * The unit is 0.1Hz.
 * @return Input VSync frequency.
 ******************************************************************************/
USHRT GetInputVFreq(void)
{
    USHRT cnt;

    cnt = ReadShortScaler(&SC_GI_VCNT_LO) & 0x1FFF;

    // Valid VSync range : 20Hz < VS < 200Hz
    if ((cnt > V_CNT_HIGH_THLD) || (cnt < V_CNT_LOW_THLD)) {
        usVSyncFreq = 0xFFFF;
    }
    else {
        usVSyncFreq = (USHRT) ((10UL * REF_CLK / cnt + 128) / 256);
    }

    return usVSyncFreq;
}

/**************************************************************************//**
 * Get current input HSync/VSync polarity.
 * The unit is 0.1Hz.
 * @return Input HSync/VSync polarity.
 ******************************************************************************/
UCHAR GetInputHVPolarity(void)
{
    UCHAR polarity;

    switch (SC_GI_SYNC_STATUS & 0x03) {
        case 0x00:
            polarity = HNVN;
            break;

        case 0x01:
            polarity = HPVN;
            break;

        case 0x02:
            polarity = HNVP;
            break;

        case 0x03:
            polarity = HPVP;
            break;
    
        default:
            polarity = HPVP;
            break;
    }

    return polarity;
}

/**************************************************************************//**
 * Get current input HSync width.
 * The value is number of 12MHz.
 * @return Input HSync width.
 ******************************************************************************/
UCHAR GetInputHSyncWidth(void)
{
    return SC_GI_HS_WID;
}

/**************************************************************************//**
 * Get current input VSync width.
 * The value is number of lines.
 * @return Input VSync width.
 ******************************************************************************/
UCHAR GetInputVSyncWidth(void)
{
    return SC_GI_VS_WID;
}

/**************************************************************************//**
 * Get current input VTotal
 * The value is number of 12MHz.
 * @return Input VTotal.
 ******************************************************************************/
USHRT GetInputVTotal(void)
{
    // Sometimes, we may get wrong vtotal during mode search because scaler does not update the vtotal yet.
    // To solve this issue, we always get vtotal from H/V sync calculation.
    // Jude 2011/10/18
#if 1
    USHRT hcnt, vcnt;

    hcnt = ReadShortScaler(&SC_GI_HCNT_LO) & 0x1FFF;
    if ((hcnt > H_CNT_HIGH_THLD) || (hcnt < H_CNT_LOW_THLD)) {
        return 0;
    }

    vcnt = ReadShortScaler(&SC_GI_VCNT_LO) & 0x1FFF;
    if ((vcnt > V_CNT_HIGH_THLD) || (vcnt < V_CNT_LOW_THLD)) {
        return 0;
    }

    return (USHRT)((float)2048 * vcnt / hcnt + 0.5);
#else
    USHRT hcnt, vcnt;
    UCHAR interface = GetCurrInputInterface();

    hcnt = ReadShortScaler(&SC_GI_HCNT_LO) & 0x1FFF;
    if ((hcnt > H_CNT_HIGH_THLD) || (hcnt < H_CNT_LOW_THLD)) {
        return 0;
    }

    vcnt = ReadShortScaler(&SC_GI_VCNT_LO) & 0x1FFF;
    if ((vcnt > V_CNT_HIGH_THLD) || (vcnt < V_CNT_LOW_THLD)) {
        return 0;
    }

    // We can not get correct vtotal under DVI if signal is pure DE
    // or if sync-processor is in DE mode. To solve this issue, we
    // return vtotal by Hsync/Vsync when input is digital signal.
    if ((interface == DIGITAL_INPUT0) || (interface == DIGITAL_INPUT1)) {
        return (USHRT)((float)2048 * vcnt / hcnt + 0.5);
    }

    return ReadShortScaler(&SC_GRAPHIC_VTOTAL_COUNTER_LO) + 1;
#endif
}

/**************************************************************************//**
 * Setup Hync overflow mask to reduce mode change time.
 * @param on TRUE to setup overflow mask by HSync. FALSE to setup default overflow mask.
 ******************************************************************************/
void SetupHSyncOverflowMask(UCHAR on)
{
#define HSYNC_BAND_LOW  ((float)REF_CLK/12000000*244)
#define HSYNC_BAND_MID  ((float)REF_CLK/12000000*478)
#define HSYNC_BAND_MAX  ((float)REF_CLK/12000000*947)

    SC_INPUT_SELECT &= 0x0F;
    SC_INPUT_SELECT |= 0x80; // Default overflow point 11.72KHz

    if (on) {
        if (usHSyncFreq > HSYNC_BAND_MAX) {
            SC_INPUT_SELECT |= 0xF0; // overflow point 93.75KHz
        }
        else if (usHSyncFreq > HSYNC_BAND_MID) {
            SC_INPUT_SELECT |= 0xE0; // overflow point 46.8KHz
        }
        else if (usHSyncFreq > HSYNC_BAND_LOW) {
            SC_INPUT_SELECT |= 0xC0; // overflow point 23.4KHz
        }
    }

#undef HSYNC_BAND_LOW
#undef HSYNC_BAND_MID
#undef HSYNC_BAND_MAX    
}

/**************************************************************************//**
 * Check current input sync status.
 * @return The value would be one of NO_SYNC/SEP_SYNC/COM_SYNC/SOG_SYNC/DIG_SYNC.
 ******************************************************************************/
UCHAR CheckInputSync(void)
{
    UCHAR curr_interface;
    UCHAR sync = NO_SYNC;

    curr_interface = GetCurrInputInterface();
    switch (curr_interface) {
        case ANALOG_SEP_INPUT0: //Composite signal's priority is higher than separate signal
            //H/V present, Composite non-present, H/V non-overflow
            if ((SC_GI_SYNC_STATUS & 0xF8) == 0x18) {
                McuScalerIntEnable(); //MCU will response to scaler interrupt
                sync = SEP_SYNC;
            } //H/V/Com present, H/V non-overflow
            else if ((SC_GI_SYNC_STATUS & 0xF8) == 0x38) {
                McuScalerIntEnable(); //MCU will response to scaler interrupt
                SetInputInterface(ANALOG_COM_INPUT0);
                sync = COM_SYNC;
            }
            break;

        case ANALOG_SEP_INPUT1: ////Composite signal's priority is higher than seperate signal
            //H/V present, Composite non-present, H/V non-overflow
            if ((SC_GI_SYNC_STATUS & 0xF8) == 0x18) {
                McuScalerIntEnable(); //MCU will response to scaler interrupt
                sync = SEP_SYNC;
            } //H/V/Com present, H/V non-overflow
            else if ((SC_GI_SYNC_STATUS & 0xF8) == 0x38) {
                McuScalerIntEnable(); //MCU will response to scaler interrupt
                SetInputInterface(ANALOG_COM_INPUT1);
                sync = COM_SYNC;
            }
            break;

        case ANALOG_COM_INPUT0:
        case ANALOG_COM_INPUT1:
            //Composite present, H/V non-overflow
            if ((SC_GI_SYNC_STATUS & 0xE8) == 0x28) {
                McuScalerIntEnable(); //MCU will response to scaler interrupt
                sync = COM_SYNC;
            }
            break;

        case ANALOG_SOG_INPUT0:
        case ANALOG_SOG_INPUT1:
        case ANALOG_YPBPR_INPUT0:
        case ANALOG_YPBPR_INPUT1:
            //Composite present, H/V non-overflow
            if ((SC_GI_SYNC_STATUS & 0xE0) == 0x20) {
                // Check vtotal to avoid the bug of new h-polarity detection.
                if (CheckSOG() == TRUE) {
                    McuScalerIntEnable(); //MCU will response to scaler interrupt
                    sync = SOG_SYNC;
                }
                else {
                    sync = NO_SYNC;
                }
            }
            break;

        case DIGITAL_INPUT0:
        case DIGITAL_INPUT1:
            DVI_PowerOn();
            //Check SCDT
            SC_HDMI_SOFTWARE_RESET |= BIT4;
            TMDSImpedanceDetection();
            if ((SC_DVI_STATUS & BIT0) != 0) {
                TMDSBandwidthDetection(FALSE);
            #if ENABLE_HDMI == ON
                // Always enable preamble detection during sync detection
                HDMIEnablePreambleDetection(TRUE);
            #endif
                if (TMDSClockStable() == TRUE) {
                    if (GetModeHandleState() == POWER_SAVING_MODE) {
                        // Turn on power to detect DeepColor timing when system under power saving mode
                        ScalerPowerUp();
                        SetInputInterface(curr_interface);
                    }

                    TMDSBandwidthDetection(TRUE);
                #if ENABLE_HDMI == ON
                    TMDSDeepColorDetection();
                #endif
                    // Double check H/V present to avoid abnormal display
                    // under pure DE digital signal. TMDSBandwidthDetection
                    // must be prior to H/V present checking
                #if DVI_MODE == DVI_DE_MODE
                    if ((SC_GI_SYNC_STATUS & 0xC0) == 0x00) {
                #else
                    if ((SC_GI_SYNC_STATUS & 0xF8) == 0x18) {
                #endif
                        McuScalerIntEnable(); //MCU will response to scaler interrupt
                        sync = DIG_SYNC;
                        SC_HDMI_SOFTWARE_RESET &= ~BIT4;
                    }
                }
            }
            break;

        default:
            sync = NO_SYNC;
            break;
    }

    if ((GetInputHFreq() == 0xFFFF) || (GetInputVFreq() == 0xFFFF)) {
        sync = NO_SYNC;
    }

    // Remove the condition to solve the issue of no image display when switching timing from 56KHz to 47KHz.
    // Jude 2011/09/28
    //if (sync == NO_SYNC) {
        // Recover the HSync overflow mask setting to default.
        SetupHSyncOverflowMask(FALSE);
    //}

    return sync;
}

/**************************************************************************//**
 * Check the input sync is SOG or not.
 * @return TRUE if input is SOG else FALSE.
 ******************************************************************************/
static BOOL CheckSOG(void)
{
#define LIMIT_SOG_HS ((8UL * REF_CLK) /150000)    //640 H sync can't bigger than 150KHz
#define LIMIT_SOG_VS ((ULONG)REF_CLK*10/256/915)    //512  V sync can't bigger than 91.5Hz

#define LIMIT_SOG_HSWID_1 ((((ULONG)REF_CLK*4.98)/1000000)+0.5)    //60
#define LIMIT_SOG_HSWID_2 ((((ULONG)REF_CLK*4.15)/1000000)+0.5)    //50
#define LIMIT_SOG_HSWID_3 ((((ULONG)REF_CLK*2.49)/1000000)+0.5)    //30

    USHRT temp1, temp2;

    //VSync width
    temp1 = SC_GI_VS_WID;
    if ((temp1 > 0x0F) || (temp1==0x00)) {
        return FALSE;
    }
    //HSync width
    temp1 = SC_GI_HS_WID;
    temp2 = ReadShortScaler(&SC_GI_HCNT_LO);
    if (temp1 > ((temp2 / 8) / 6)) { //HSync width is over 1/6 of HTotal
        return FALSE;
    }
    //HSync frequency
    temp1 = ReadShortScaler(&SC_GI_HCNT_LO);
    if ((temp1 < LIMIT_SOG_HS) || (temp1 == 0x1FFF)) {
        return FALSE;
    }
    //VSync frequency
    temp1 = ReadShortScaler(&SC_GI_VCNT_LO);
    if ((temp1 < LIMIT_SOG_VS) || (temp1 == 0x1FFF)) {
        return FALSE;
    }
    //VTotal
    temp1 = SC_GI_HS_WID;
    temp2 = ReadShortScaler(&SC_GRAPHIC_VTOTAL_COUNTER_LO)+1;
    if (temp2 < 200) {
        return FALSE;
    }
    if (temp2 < 380) { //576I SOG
        if (temp1 > LIMIT_SOG_HSWID_1) {
            return FALSE;
        }
    }
    else if (temp2 < 730) {
        if (temp1 > LIMIT_SOG_HSWID_2) {
            return FALSE;
        }
    }
    else {
        if (temp1 > LIMIT_SOG_HSWID_3) {
            return FALSE;
        }
    }
    
    return TRUE;
    
#undef LIMIT_SOG_HS
#undef LIMIT_SOG_VS
#undef LIMIT_SOG_HSWID_1
#undef LIMIT_SOG_HSWID_2
#undef LIMIT_SOG_HSWID_3
}

/**************************************************************************//**
 * Setup interlace settings.
 * Set interlace input enable (Reg0x020[2]) by SyncProcessor flag.
 ******************************************************************************/
void SetupInterlace(void)
{
    SC_GI_SYNC_CTRL3 &= ~BIT0;

    //Set 0x020[2] and 0x020[6]
    if (IsInterlaceSyncPreset()) { //If input is interlaced
        SC_GPORT_CTRL |= BIT2;
    }
    else {
        SC_GPORT_CTRL &= ~BIT2;
    }
}

/**************************************************************************//**
 * Check Interlace Sync Preset
 * @return TRUE if input is interlaced sync else FALSE.
 ******************************************************************************/
BOOL IsInterlaceSyncPreset(void)
{
    if ((SC_GI_SYNC_STATUS & BIT2) != 0) { //If input is interlaced
        return TRUE;
    }
    else {
        return FALSE;
    }
}

/**************************************************************************//**
 * Check the current timing is interlace or not.
 * @return TRUE if input is interlaced else FALSE.
 ******************************************************************************/
BOOL IsInterlaced(void)
{
    if ((SC_GPORT_CTRL & BIT2) != 0) { //If input is interlaced
        return TRUE;
    }
    else {
        return FALSE;
    }
}

/**************************************************************************//**
 * Delay time of 'n' frames.
 * @param n Number of frames. The max n is 10.
 ******************************************************************************/
void DelayVTime(UCHAR n) small
{
    USHRT temp, delay;

    // We limit n as smaller than 10.
    if (n > 10) {
        n = 10;
    }

    // If the input vsync freq is abnormal, we force the delay time as 20ms
    if ((usVSyncFreq < ((USHRT) VSYNC_LOWER_BOUND * 10)) ||
        (usVSyncFreq > ((USHRT) VSYNC_UPPER_BOUND * 10))) {
        delay = 20 * n;
    }
    else {
        delay = (ULONG) 10000 * n / usVSyncFreq + 1;
    }

    temp = GetTimerTick();
    while ((GetTimerTick() - temp) < delay) {
        ResetWDTimer();
    }
}
