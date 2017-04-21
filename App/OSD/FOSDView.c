#include "Include.h"

#if FOSDTYPE == AOC_FactoryOSD
#include "FOSDView_AOC/FOSDView.c"
#elif FOSDTYPE == OTS_FactoryOSD
#include "FOSDView_OTS/FOSDView.c"
#endif

