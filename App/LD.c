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

#if ENABLE_LD == ON

#include "LDData.c"

//******************************************************************************
// M A C R O   D E F I N I T I O N S
//******************************************************************************

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************

//******************************************************************************
// G L O B A L   V A R I A B L E S
//******************************************************************************

//******************************************************************************
// S T A T I C   V A R I A B L E S
//******************************************************************************
#if ENABLE_DYNAMIC_LD == ON 
static xdata UCHAR ucLDULFlag = 0x00;
#endif   
static xdata UCHAR ucLDSceneChanged = 0x0;
static xdata UCHAR ucLDPrevSceneChanged = 0x80;
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
// Prototype:
//  void InitLD(void)
// Parameters:
//  None
// Return:
//  None
// Purpose:
//  Configure the Local Dimming of Scaler
// Notes:
//  None
//******************************************************************************
void InitLD(void)
{
    LDAPI_Init();
    LDAPI_SetHVZones(LD_H_ZONES, LD_V_ZONES);
    LDAPI_SetHVBound(LD_H_BOUND, LD_V_BOUND);
    LDAPI_SetHVSamples(LD_H_SAMPLES, LD_V_SAMPLES);
    LDAPI_SetDimDef(LD_DIM01_DEF, LD_DIM23_DEF, LD_DIM45_DEF, LD_DIM67_DEF);
    LDAPI_LoadTable(&LightProfile);
}

//******************************************************************************
// Prototype:
//  void SetLDMode(LDMode mode)
// Parameters:
//  mode : LD_OFF / LD_ON / LD_DEMO
// Return:
//  None
// Purpose:
//  Set LD mode
// Notes:
//  None
//******************************************************************************
void SetLDMode(LDMode mode)
{
	/* voltage mode setting 
    if ( mode == LD_ON || mode == LD_DEMO ) {
        if ( LDAPI_GetVoltageModePoint() == FALSE) {
            LDAPI_SetLDMode(LD_OFF);
            return;
        }

        SC_ADC_LDO_TRIM |= BIT7;
    }
   SC_VREF_VOLTAGE_MODE1 = 0x4C;//0x5A;
  */
	 
   LDAPI_SetLDMode(mode);
    
#if ENABLE_DYNAMIC_LD == ON 
     if(mode == LD_ON) {
		ucLDULFlag = BIT7;
	}
#endif	
}

//******************************************************************************
// Prototype:
// BOOL LDAPI_GetVoltageModePoint()
// Parameters:
// None
// Return:
//  None
// Purpose:
//  Get Local dimming mode point 
// Notes:
//  None
//******************************************************************************
/*
BOOL LDAPI_GetVoltageModePoint()
{
#define VREF_COUNT 3
#define VREF_CONT_COUNT 8
#define VREF_MIN 64
#define VREF_MAX 189
    UCHAR pass_cnt;
    UCHAR i, vref;
    USHRT brt, voltage_point = 0;
    //USHRT local_timer;
    
    SC_LD_CTRL &= ~BIT0;
    SC_ADC_LDO_TRIM &= ~BIT7; //sel current mode    
    brt = GetBrightness();
    SetBrightness(1023);

#if 1
    for (i=0; i<VREF_COUNT; i++) {
        pass_cnt = 0;
        for(vref=VREF_MIN; vref<(VREF_MAX+1); vref++ ) {
            SC_VREF_VOLTAGE_MODE1 = vref;
            Sleep(1);
            if ( (SC_VREF_VOLTAGE_MODE2 & BIT0) != 0 ) {
                if ( ++pass_cnt >= VREF_CONT_COUNT ) {
                    voltage_point += (vref-VREF_CONT_COUNT+1);
                    //printf("get vref=%d\r\n", (USHRT)(vref-VREF_CONT_COUNT+1));
                    break;
                }
            }
            else {
                pass_cnt = 0;
            }
        }
        if ( pass_cnt < VREF_CONT_COUNT ) {
            break;
        }
    }

	SC_VREF_VOLTAGE_MODE1 -= 0x08;
    SetBrightness(brt);
    
    if ( pass_cnt < VREF_CONT_COUNT ) {
        return FALSE;
    }    
#else
    for (i=0; i<VREF_COUNT; i++) {
        for(vref=VREF_MIN; vref<(VREF_MAX+1); vref++ ) {
            ResetWDTimer();
            pass_cnt = 1;
            SC_VREF_VOLTAGE_MODE1 = vref;
            local_timer = GetTimerTick();
            do {
                if ( (SC_VREF_VOLTAGE_MODE2 & BIT0) == 0 ) {
                    pass_cnt = 0;
                    break;
                }
            } while ((GetTimerTick() - local_timer) < 20); 
            
            if ( pass_cnt ) {
                printf("p=%d\r\n", (USHRT)vref);
                voltage_point += vref;
                break;
            }
        }
        if ( pass_cnt == 0 ) {
            break; //fail
        }
    }

    SetBrightness(brt);
    
    if ( pass_cnt == 0 ) {
        return FALSE;
    }    
#endif

    
    SC_VREF_VOLTAGE_MODE1 = voltage_point/VREF_COUNT;

    return TRUE;
}
*/

//******************************************************************************
// Prototype:
//  void PerformDynamicLD()
// Parameters:
//  None
// Return:
//  None
// Purpose:
// Dynamic switching off LD for samsung special pattern, such as Three Bar.................
// Notes:
//  None
//******************************************************************************
#if ENABLE_DYNAMIC_LD == ON 
void PerformDynamicLD()
{
    if ((ucLDULFlag & BIT7) != 0) {
        ucLDULFlag &= ~BIT7;
        DCR_UpdateHistogram(TRUE);
    }
    else if (DCR_UpdateHistogram(FALSE)) {
        UCHAR i;

        if(DCR_IsSceneChanged()) { 
			UCHAR tmp_flag = ucLDULFlag;
			USHRT total,sum;
			
			DCR_UpdatePrevHistogram();
			if((ucLDSceneChanged & 0x80) == 0) {
				ucLDSceneChanged += 8;
                if(ucLDSceneChanged > 0x40) {
                    ucLDSceneChanged = 0x80;
                    SC_DBC_ADJ = 0x41;         	// 0x431
                    //SC_DBC_CTRL = 0x8B;         // 0x430
                    
                    //printf("Dynamic\r\n");
                }
            }
            else {
                ucLDSceneChanged = 0x80;
            }
		
			// Three Bar
            sum = 0;
            ucLDULFlag &= ~BIT3;
            sum = (DCR_GetHistogram(BF_IG_PARTITIONS-1) + DCR_GetHistogram(0));         
            total = (DCR_GetTotalHistogram() >> 1) + (DCR_GetTotalHistogram() >> 2);   // 0.75

            if((DCR_GetHistogram(BF_IG_PARTITIONS-1)>(DCR_GetTotalHistogram()>>4))&&(DCR_GetHistogram(0)>(DCR_GetTotalHistogram()>>4))&&(sum > total)) {
                ucLDULFlag |= BIT3;
            }

			// Gray
            sum = 0;
            ucLDULFlag &= ~BIT4;           
            total = (DCR_GetTotalHistogram()/BF_IG_PARTITIONS); // the average pixels of each section
            for(i = 0 ; i < BF_IG_PARTITIONS ; i++) {
                if(abs(DCR_GetHistogram(i) - total) > ((total>>1)+(total>>2))) {
                    sum = 1;
                    break;
                }
            }
           
            if(sum == 0) {    
                ucLDULFlag |= BIT4;
            }         

        }
        else {
            if((ucLDSceneChanged & 0x80) == 0) {
                if(ucLDSceneChanged > 0)
                    ucLDSceneChanged--;
            }
            else {
                ucLDSceneChanged++;
                if(ucLDSceneChanged > 0xF0) {
                    ucLDSceneChanged = 0x00;                
                }
            }
        }
    }

	{
		ucLDPrevSceneChanged = ucLDSceneChanged;
		if((ucLDSceneChanged & 0x80) != 0) {
			// Dynamic
			SC_LD_INC_SPEED = 0x48;
			SC_LD_DEC_SPEED = 0x88;
			SC_LD_CTRL |= BIT0;//0x81;
			LDAPI_SetLDDutyWeight(6,12,8);
			//printf("Dynamic\r\n");
		}
		else {
			// Static
			SC_LD_INC_SPEED = 0x08;
			SC_LD_DEC_SPEED = 0x08;
			LDAPI_SetLDDutyWeight(8,10,8);
			if(ucLDULFlag & BIT3) {
				// Three Bar
				SC_LD_CTRL &= ~BIT0;//0x80;
			}
			else if(ucLDULFlag & BIT4) {
				// Gray
				SC_LD_CTRL |= BIT0;;//0x81;
			}
			else {
				// Video
				SC_LD_CTRL |= BIT0;;//0x81;
			}
			//printf("Static\r\n");
		} 
	}
}
#endif
#else
void ForLDCompilerCodePass(void)
{
  code UCHAR temp[]={0x00};
  UCHAR i;
  i = temp[0];
}
#endif //#if ENABLE_LD == ON
