#include "Include.h"

#if OSDTYPE == OSD_BENQ
#include "OSD_BENQ/OSDCtrl.c"
#elif OSDTYPE == OSD_BENQ_V1
#include "OSD_BENQ_V1/OSDCtrl.c"
#elif OSDTYPE == OSD_BENQ_V2
#include "OSD_BENQ_V2/OSDCtrl.c"
#endif
