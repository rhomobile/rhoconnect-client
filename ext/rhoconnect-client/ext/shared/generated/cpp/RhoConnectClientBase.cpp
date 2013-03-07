#include "RhoConnectClientBase.h"
#include "common/RhodesApp.h"


namespace rho {

IMPLEMENT_LOGCLASS(CRhoConnectClientSingletonBase, "RhoConnectClient");
IMPLEMENT_LOGCLASS(CRhoConnectClientBase, "RhoConnectClient");

rho::common::CAutoPtr< CRhoConnectClientFactoryBase> CRhoConnectClientFactoryBase::m_pInstance;



///////////////////////////////////////
//string constants definiton 

////////////////////////////////////////////////

CRhoConnectClientSingletonBase::CRhoConnectClientSingletonBase()
{

    RHODESAPP().getExtManager().registerExtension( "RhoConnectClient", this ); 
}

CRhoConnectClientSingletonBase::~CRhoConnectClientSingletonBase()
{
    CRhoConnectClientFactoryBase::setInstance(0);
}


}
