#include "Include.h"


#if OSDTYPE == OSD_BENQ
#include "OSD_BENQ/OSDFont_Europe.c"
#elif OSDTYPE == OSD_BENQ_V1
#include "OSD_BENQ_V1/OSDFont_Europe.c"
#elif OSDTYPE == OSD_BENQ_V2
#include "OSD_BENQ_V2/OSDFont_Europe.c"
#endif 

