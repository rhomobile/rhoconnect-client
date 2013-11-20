#include "generated/cpp/RhoConnectClientBase.h"
#include "sync/SyncThread.h"

namespace rho {
	
class RhoConnectClientImpl : public CRhoConnectClientSingletonBase
{
private:
	sync::CSyncThread* getSyncThread() const { return sync::CSyncThread::getInstance(); }
	sync::CSyncEngine& getSyncEngine() const { return sync::CSyncThread::getSyncEngine(); }
public:


    RhoConnectClientImpl();
	
	virtual void getUserName(rho::apiGenerator::CMethodResult& oResult);
    virtual void getPollInterval(rho::apiGenerator::CMethodResult& oResult);
    virtual void setPollInterval( int value, rho::apiGenerator::CMethodResult& oResult);
    virtual void getSyncServer(rho::apiGenerator::CMethodResult& oResult);
    virtual void setSyncServer( const rho::String& value, rho::apiGenerator::CMethodResult& oResult);
    virtual void getBulksyncState( rho::apiGenerator::CMethodResult& oResult);
    virtual void setBulksyncState( int state, rho::apiGenerator::CMethodResult& oResult);
    virtual void getPageSize(rho::apiGenerator::CMethodResult& oResult);
    virtual void setPageSize( int value, rho::apiGenerator::CMethodResult& oResult);
    virtual void getThreadedMode(rho::apiGenerator::CMethodResult& oResult);
    virtual void setThreadedMode( bool value, rho::apiGenerator::CMethodResult& oResult);
    virtual void getShowStatusPopup(rho::apiGenerator::CMethodResult& oResult);
    virtual void setShowStatusPopup( bool value, rho::apiGenerator::CMethodResult& oResult);
    virtual void getSslVerifyPeer(rho::apiGenerator::CMethodResult& oResult);
    virtual void setSslVerifyPeer( bool value, rho::apiGenerator::CMethodResult& oResult);
    virtual void isLoggedIn(rho::apiGenerator::CMethodResult& oResult);
    virtual void isSyncing(rho::apiGenerator::CMethodResult& oResult);

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
	
private:
	void handleSyncResult(rho::apiGenerator::CMethodResult& oResult);


};


 

}

extern "C" void Init_RhoConnectClient_API();
