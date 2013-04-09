#ifdef __cplusplus
extern "C" {
#endif
	
#include "logging/RhoLog.h"

extern void Init_RhoConnectClient_API(void);
extern void initRhoconnectClient();

// this method executed once on start of program
void Init_Rhoconnectclient_extension(void) {
	Init_RhoConnectClient_API();
	initRhoconnectClient();
}

#ifdef __cplusplus
} //extern "C"
#endif