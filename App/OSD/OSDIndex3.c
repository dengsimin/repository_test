#include "Include.h"

#if OSDTYPE == OSD_BENQ
#include "OSD_BENQ/OSDIndex3.c"
#elif OSDTYPE == OSD_BENQ_V1
#include "OSD_BENQ_V1/OSDIndex3.c"
#elif OSDTYPE == OSD_BENQ_V2
#include "OSD_BENQ_V2/OSDIndex3.c"
#endif 

