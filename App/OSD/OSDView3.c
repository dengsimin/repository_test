#include "Include.h"

#if OSDTYPE == OSD_BENQ
#include "OSD_BENQ/OSDView3.c"
#elif OSDTYPE == OSD_BENQ_V1
#include "OSD_BENQ_V1/OSDView3.c"
#elif OSDTYPE == OSD_BENQ_V2
#include "OSD_BENQ_V2/OSDView3.c"
#endif
