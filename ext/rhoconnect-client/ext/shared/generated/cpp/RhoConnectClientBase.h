#include "IRhoConnectClient.h"
#include "common/StringConverter.h"


namespace rho {

using namespace rho::apiGenerator;

class CRhoConnectClientFactoryBase : public CModuleFactoryBase<IRhoConnectClient, IRhoConnectClientSingleton, IRhoConnectClientFactory>
{
protected:
    static rho::common::CAutoPtr<CRhoConnectClientFactoryBase> m_pInstance;
    Hashtable<rho::String,IRhoConnectClient*> m_hashModules;

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

};

class CRhoConnectClientSingletonBase : public CModuleSingletonBase< IRhoConnectClientSingleton >
{
protected:




public:


    CRhoConnectClientSingletonBase();



};

class CRhoConnectClientBase: public IRhoConnectClient
{
protected:

public:


 

};

extern "C" void Init_RhoConnectClient_API();


}
