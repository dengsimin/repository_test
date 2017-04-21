#if OSDTYPE == OSD_BENQ
#include "OSD_BENQ/OSDConfig.h"
#elif OSDTYPE == OSD_BENQ_V1
#include "OSD_BENQ_V1/OSDConfig.h"
#elif OSDTYPE == OSD_BENQ_V2
#include "OSD_BENQ_V2/OSDConfig.h"
#endif






#ifndef OSDLANG_ARAB
#define OSDLANG_ARAB   OSDLANG_NONE
#endif

#ifndef ENABLE_OSD_AUDIO_INPUT_SEL
#define ENABLE_OSD_AUDIO_INPUT_SEL   OFF
#endif
