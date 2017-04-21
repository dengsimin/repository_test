#include "Include.h"



#define GetProductModeFlag()        (SystemData.usProductMode == 0x55AA)
#define SetProductModeFlag()        (SystemData.usProductMode = 0x55AA)
#define ClrProductModeFlag()        (SystemData.usProductMode = 0xBB99)

#if FOSDTYPE == AOC_FactoryOSD
#include "FOSDView_AOC/FOSDView.h"
#elif FOSDTYPE == OTS_FactoryOSD
#include "FOSDView_OTS/FOSDView.h"
#endif

