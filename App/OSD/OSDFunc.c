#include "Include.h"

#if OSDTYPE == OSD_BENQ
#include "OSD_BENQ/OSDFunc.c"
#elif OSDTYPE == OSD_BENQ_V1
#include "OSD_BENQ_V1/OSDFunc.c"
#elif OSDTYPE == OSD_BENQ_V2
#include "OSD_BENQ_V2/OSDFunc.c"
#endif 
