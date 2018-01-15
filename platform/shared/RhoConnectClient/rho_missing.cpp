#include "common/RhoTime.h"

namespace rho {
    namespace common {
        
        void CRhoTimer::addNativeTimer(int, rho::common::CRhoTimer::ICallback*) {}
        void CRhoTimer::stopNativeTimer(rho::common::CRhoTimer::ICallback*) {}
    }
        
}


extern "C" {
    
void rho_ios_log_console_output() {
}

void rho_http_sendresponse() {
    
}

void tau_decrypt_file() {
    
}

};
