#include "Include.h"


#if ENABLE_GAMMA == ON
/*!
 * Write red gamma through index port.
 */
#define GMAPI_LoadRGM320(p) WriteScalerIndexPort(GAMMA_TBL_RED|BIT2, 0, 320, p)
/*!
 * Write green gamma through index port.
 */
#define GMAPI_LoadGGM320(p) WriteScalerIndexPort(GAMMA_TBL_GREEN|BIT2, 0, 320, p)
/*!
 * Write blue gamma through index port.
 */
#define GMAPI_LoadBGM320(p) WriteScalerIndexPort(GAMMA_TBL_BLUE|BIT2, 0, 320, p)

/**************************************************************************//**
 * Write R/G/B 320-bytes gamma tables to scaler.
 * @param pgamma Pointer to the R/G/B 320-bytes gamma table.
 ******************************************************************************/
void GMAPI_LoadGamma320(Gamma320 *pgamma)
{
    GMAPI_DisableGamma();
    Sleep(50); // 24Hz is around 41ms
#if ENABLE_10TO12_GAMMA == ON
#elif ENABLE_10TO10_GAMMA == ON
    GMAPI_LoadSingleTable320To1280(pgamma->ucRGamma, GAMMA_TBL_RED);
    GMAPI_LoadSingleTable320To1280(pgamma->ucGGamma, GAMMA_TBL_GREEN);
    GMAPI_LoadSingleTable320To1280(pgamma->ucBGamma, GAMMA_TBL_BLUE);
#else
    GMAPI_LoadRGM320(pgamma->ucRGamma);
    GMAPI_LoadGGM320(pgamma->ucGGamma);
    GMAPI_LoadBGM320(pgamma->ucBGamma);
#endif
}

#endif