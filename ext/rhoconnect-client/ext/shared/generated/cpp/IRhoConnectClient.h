#pragma once

#include "common/RhoStd.h"
#include "api_generator/MethodResult.h"
#include "api_generator/BaseClasses.h"


namespace rho {
///////////////////////////////////////////////////////////
struct IRhoConnectClient
{
//constants


//methods
    virtual ~IRhoConnectClient(){}


};

struct IRhoConnectClientSingleton
{
//constants


    virtual ~IRhoConnectClientSingleton(){}

//methods
    virtual void getUserName(rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void getPollInterval(rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void setPollInterval( int value, rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void getSyncServer(rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void setSyncServer( const rho::String& value, rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void getPageSize(rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void setPageSize( int value, rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void getThreadedMode(rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void setThreadedMode( bool value, rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void getShowStatusPopup(rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void setShowStatusPopup( bool value, rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void getSslVerifyPeer(rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void setSslVerifyPeer( bool value, rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void loggedIn(rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void syncing(rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void search( const rho::Hashtable<rho::String, rho::String>& args, rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void doSync( bool showStatusPopup,  const rho::String& queryParams,  bool syncOnlyChangedSources, rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void doSyncSource( const rho::String& sourceName,  bool showStatusPopup,  const rho::String& queryParams, rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void login( const rho::String& login,  const rho::String& password, rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void logout(rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void stopSync(rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void setNotification( const rho::String& sourceName, rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void clearNotification( const rho::String& sourceName, rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void setObjectNotification(rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void addObjectNotify( const rho::String& sourceName,  const rho::String& object, rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void cleanObjectNotify(rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void getLastSyncObjectCount( const rho::String& sourceName, rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void setSourceProperty( const rho::String& sourceName,  const rho::String& propertyName,  const rho::String& propertyValue, rho::apiGenerator::CMethodResult& oResult) = 0;
    virtual void getSourceProperty( const rho::String& sourceName,  const rho::String& propertyName, rho::apiGenerator::CMethodResult& oResult) = 0;


    virtual void addCommandToQueue(rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor) = 0;
    virtual void callCommandInThread(rho::common::IRhoRunnable* pFunctor) = 0;
};

struct IRhoConnectClientFactory
{
    virtual ~IRhoConnectClientFactory(){}

    virtual IRhoConnectClientSingleton* getModuleSingleton() = 0;


};


}
