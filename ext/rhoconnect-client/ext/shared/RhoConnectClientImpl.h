#include "RhoConnectClientBase.h"

namespace rho {


class RhoconnectClientImpl : public CRhoConnectClientSingletonBase
{
protected:




public:


    RhoconnectClientImpl();
	
	virtual void getUserName(rho::apiGenerator::CMethodResult& oResult);
    virtual void getPollInterval(rho::apiGenerator::CMethodResult& oResult);
    virtual void setPollInterval( int value, rho::apiGenerator::CMethodResult& oResult);
    virtual void getSyncServer(rho::apiGenerator::CMethodResult& oResult);
    virtual void setSyncServer( const rho::String& value, rho::apiGenerator::CMethodResult& oResult);
    virtual void getPageSize(rho::apiGenerator::CMethodResult& oResult);
    virtual void setPageSize( int value, rho::apiGenerator::CMethodResult& oResult);
    virtual void getThreadedMode(rho::apiGenerator::CMethodResult& oResult);
    virtual void setThreadedMode( bool value, rho::apiGenerator::CMethodResult& oResult);
    virtual void getShowStatusPopup(rho::apiGenerator::CMethodResult& oResult);
    virtual void setShowStatusPopup( bool value, rho::apiGenerator::CMethodResult& oResult);
    virtual void getSslVerifyPeer(rho::apiGenerator::CMethodResult& oResult);
    virtual void setSslVerifyPeer( bool value, rho::apiGenerator::CMethodResult& oResult);
    virtual void loggedIn(rho::apiGenerator::CMethodResult& oResult);
    virtual void syncing(rho::apiGenerator::CMethodResult& oResult);
    virtual void onSyncCreateError( const rho::String& srcName,  const rho::Vector<rho::String>& objects,  const rho::String& action, rho::apiGenerator::CMethodResult& oResult);
    virtual void pushChanges( const rho::String& srcName, rho::apiGenerator::CMethodResult& oResult);
    virtual void onSyncUpdateError( const rho::String& srcName,  const rho::Vector<rho::String>& objects,  const rho::String& action,  const rho::String& rollbackData, rho::apiGenerator::CMethodResult& oResult);
    virtual void onSyncDeleteError( const rho::String& srcName,  const rho::Vector<rho::String>& objects,  const rho::String& action, rho::apiGenerator::CMethodResult& oResult);
    virtual void search( const rho::Hashtable<rho::String, rho::String>& args, rho::apiGenerator::CMethodResult& oResult);
    virtual void doSync( bool showStatusPopup,  const rho::String& queryParams,  bool syncOnlyChangedSources, rho::apiGenerator::CMethodResult& oResult);
    virtual void doSyncSource( const rho::String& sourceName,  bool showStatusPopup,  const rho::String& queryParams, rho::apiGenerator::CMethodResult& oResult);
    virtual void login( const rho::String& login,  const rho::String& password, rho::apiGenerator::CMethodResult& oResult);
    virtual void logout(rho::apiGenerator::CMethodResult& oResult);
    virtual void stopSync(rho::apiGenerator::CMethodResult& oResult);
    virtual void setNotification( const rho::String& sourceName, rho::apiGenerator::CMethodResult& oResult);
    virtual void clearNotification( const rho::String& sourceName, rho::apiGenerator::CMethodResult& oResult);
    virtual void setObjectNotification(rho::apiGenerator::CMethodResult& oResult);
    virtual void addObjectNotify( const rho::String& sourceName,  const rho::String& object, rho::apiGenerator::CMethodResult& oResult);
    virtual void cleanObjectNotify(rho::apiGenerator::CMethodResult& oResult);
    virtual void getLastSyncObjectCount( const rho::String& sourceName, rho::apiGenerator::CMethodResult& oResult);
    virtual void setSourceProperty( const rho::String& sourceName,  const rho::String& propertyName,  const rho::String& propertyValue, rho::apiGenerator::CMethodResult& oResult);
    virtual void getSourceProperty( const rho::String& sourceName,  const rho::String& propertyName, rho::apiGenerator::CMethodResult& oResult);


};


 

};

extern "C" void Init_RhoConnectClient_API();


}
