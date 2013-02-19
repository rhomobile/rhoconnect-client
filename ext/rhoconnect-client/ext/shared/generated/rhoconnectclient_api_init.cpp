#include "common/app_build_capabilities.h"

extern "C" void Init_RubyAPI_RhoConnectClient();
extern "C" void Init_JSAPI_RhoConnectClient();

extern "C" void Init_RhoConnectClient_API()
{
#ifndef RHO_NO_RUBY_API
    Init_RubyAPI_RhoConnectClient();
#endif

#ifndef RHO_NO_JS_API
    Init_JSAPI_RhoConnectClient();
#endif
}
