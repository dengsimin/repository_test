#include "Include.h"

#if OSDTYPE == OSD_BENQ
#include "OSD_BENQ/OSDFont.c"
#elif OSDTYPE == OSD_BENQ_V1
#include "OSD_BENQ_V1/OSDFont.c"
#elif OSDTYPE == OSD_BENQ_V2
#include "OSD_BENQ_V2/OSDFont.c"
#endif 
