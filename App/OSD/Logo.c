	#include "Include.h"

#if OSDTYPE == OSD_BENQ
#include "OSD_BENQ/Logo.c"
#elif OSDTYPE == OSD_BENQ_V1
#include "OSD_BENQ_V1/Logo.c"
#elif OSDTYPE == OSD_BENQ_V2
#include "OSD_BENQ_V2/Logo.c"
#endif
