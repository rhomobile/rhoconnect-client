#ifdef __cplusplus
extern "C" {
#endif
	
#include "logging/RhoLog.h"

extern void Init_RhoConnectClient_API(void);
extern void initRhoconnectClient();

// this method executed once on start of program
void Init_Rhoconnectclient_extension(void) {
	RAWLOG_INFO("Init_Rhoconnectclient_extension 0");
	
	Init_RhoConnectClient_API();
	RAWLOG_INFO("Init_Rhoconnectclient_extension 1");
		
	initRhoconnectClient();
	RAWLOG_INFO("Init_Rhoconnectclient_extension 2");

}

#ifdef __cplusplus
} //extern "C"
#endif