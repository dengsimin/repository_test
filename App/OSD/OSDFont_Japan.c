//******************************************************************************
// I N C L U D E   F I L E S
//******************************************************************************
#include "Include.h"

#if OSDTYPE == OSD_BENQ
#include "OSD_BENQ/OSDFont_Japan.c"
#elif OSDTYPE == OSD_BENQ_V1
#include "OSD_BENQ_V1/OSDFont_Japan.c"
#elif OSDTYPE == OSD_BENQ_V2
#include "OSD_BENQ_V2/OSDFont_Japan.c"
#endif 

