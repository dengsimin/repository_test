#include "Include.h"

#if OSDTYPE == OSD_BENQ
#include "OSD_BENQ/OSDIndex2.c"
#elif OSDTYPE == OSD_BENQ_V1
#include "OSD_BENQ_V1/OSDIndex2.c"
#elif OSDTYPE == OSD_BENQ_V2
#include "OSD_BENQ_V2/OSDIndex2.c"
#endif 

