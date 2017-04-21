#include "Include.h"

#if OSDTYPE == OSD_BENQ
#include "OSD_BENQ/OSDView2.c"
#elif OSDTYPE == OSD_BENQ_V1
#include "OSD_BENQ_V1/OSDView2.c"
#elif OSDTYPE == OSD_BENQ_V2
#include "OSD_BENQ_V2/OSDView2.c"
#endif
