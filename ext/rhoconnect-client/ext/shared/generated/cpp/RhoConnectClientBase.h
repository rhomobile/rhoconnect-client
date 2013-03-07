#include "IRhoConnectClient.h"
#include "logging/RhoLog.h"
#include "common/StringConverter.h"
#include "common/ExtManager.h"


namespace rho {

using namespace rho::apiGenerator;

class CRhoConnectClientFactoryBase : public CModuleFactoryBase<IRhoConnectClient, IRhoConnectClientSingleton, IRhoConnectClientFactory>
{
protected:
    static rho::common::CAutoPtr<CRhoConnectClientFactoryBase> m_pInstance;
    HashtablePtr<rho::String,IRhoConnectClient*> m_hashModules;

public:

    static void setInstance(CRhoConnectClientFactoryBase* pInstance){ m_pInstance = pInstance; }
    static CRhoConnectClientFactoryBase* getInstance(){ return m_pInstance; }

    static IRhoConnectClientSingleton* getRhoConnectClientSingletonS(){ return getInstance()->getModuleSingleton(); }

    virtual IRhoConnectClient* getModuleByID(const rho::String& strID)
    {
        if ( !m_hashModules.containsKey(strID) )
        {
            IRhoConnectClient* pObj = createModuleByID(strID);
            m_hashModules.put(strID, pObj );

            return pObj;
        }

        return m_hashModules[strID];
    }

    virtual IRhoConnectClient* createModuleByID(const rho::String& strID){ return (IRhoConnectClient*)0; };
    virtual void deleteModuleByID(const rho::String& strID)
    {
        m_hashModules.remove(strID);
    }

};

class CRhoConnectClientSingletonBase : public CModuleSingletonBase< IRhoConnectClientSingleton >, public rho::common::IRhoExtension
{
protected:
    DEFINE_LOGCLASS;





public:
    virtual rho::LogCategory getModuleLogCategory(){ return getLogCategory(); }

    CRhoConnectClientSingletonBase();
    ~CRhoConnectClientSingletonBase();






};

class CRhoConnectClientBase: public IRhoConnectClient
{
protected:
    DEFINE_LOGCLASS;


public:



 

};

extern "C" void Init_RhoConnectClient_API();


}
