
#include "sync/RhoconnectClientManager.h"
#include "sync/ILoginListener.h"
#include "sync/SyncThread.h"
#include "sync/ClientRegister.h"
#include "RhoConnectClientImpl.h"
#include "common/RhodesApp.h"

class RhoConnectClientRhodesInterfaceImpl : public rho::sync::IRhoconnectClient {
public:
	virtual ~RhoConnectClientRhodesInterfaceImpl() {}
	
	virtual void doSyncSourceByName( const char* srcName ) {
		rho_sync_doSyncSourceByName( srcName );
	}
	
	virtual void doSyncAllSources( int show_status_popup, const char* query_params, int sync_only_changed_sources ) {
		rho_sync_doSyncAllSources(show_status_popup, query_params, sync_only_changed_sources );
	}
	
	virtual void clientRegisterCreate( const char* szDevicePin ) {
		rho::sync::CClientRegister::Create(szDevicePin);
	}

	virtual void clientRegisterDestroy() {
		rho::sync::CClientRegister::Destroy();
	}

        virtual bool clientRegisterHaveInstance() {
		return rho::sync::CClientRegister::getInstance() != 0;
	}

	virtual void clientRegisterCreate( ) {
		rho::sync::CClientRegister::Create();
	}

	virtual void clientRegisterAddLoginListener( rho::sync::ILoginListener* listener ) {
		rho::sync::CClientRegister::AddLoginListener(listener);
	}

        virtual void clientRegisterSetDevicePin(const char* pin ) {
		rho::sync::CClientRegister::Get()->setDevicehPin(pin);
	}
	
	virtual void rho_sync_addobjectnotify_bysrcname(const char* szSrcName, const char* szObject) {
		rho::sync::CSyncThread::getSyncEngine().getNotify().addObjectNotify(szSrcName, szObject);
	}
	
	virtual const rho::String& clientRegisterGetDevicePin() {
		return rho::sync::CClientRegister::Get()->getDevicePin();
	}
	
	virtual rho::String syncEnineReadClientID() {
		return rho::sync::CSyncThread::getSyncEngine().readClientID();
	}
	
	virtual rho::net::IRhoSession* getRhoSession() {
		return &(rho::sync::CSyncThread::getSyncEngine());
	}
	
	virtual void syncEngineApplyChangedValues(rho::db::CDBAdapter& db) {
		rho::sync::CSyncThread::getSyncEngine().applyChangedValues(db);
	}
	
	virtual void syncThreadCreate() {
		rho::sync::CSyncThread::Create();
	}
	
	virtual void syncThreadDestroy() {
		rho::sync::CSyncThread::Destroy();
	}
	
	virtual bool haveSyncThread() {
		return rho::sync::CSyncThread::getInstance() != 0;
	}
	
	virtual unsigned int syncThreadGetThreadID() {
		rho::sync::CSyncThread* t = rho::sync::CSyncThread::getInstance();
		return (t!=0)?t->getThreadID():((unsigned int)-1);
		
	}
	
	virtual bool syncEngineNotifyIsReportingEnabled() {
		return rho::sync::CSyncThread::getInstance()->getSyncEngine().getNotify().isReportingEnabled();
	}
	
	virtual int rho_sync_issyncing() {
		return rho_sync_issyncing();
	}
	
	virtual int logged_in() {
		return rho_sync_logged_in();
	}
	
	virtual unsigned long login(const char* login, const char* password, const char* callback) {
		return rho_sync_login(login, password, callback);
	}
	
	virtual void logout() {
		rho_sync_logout();
	}
	
	virtual void stop() {
		rho_sync_stop();
	}
	
	virtual int set_pollinterval( int interval ) {
		return rho_sync_set_pollinterval(interval);
	}
	
	virtual int get_pollinterval() {
		return rho_sync_get_pollinterval();
	}
	
	virtual void set_syncserver( const char* syncserver ) {
		rho_sync_set_syncserver(syncserver);
	}
	
	virtual int get_pagesize() {
		return rho_sync_get_pagesize();
	}
	
	virtual void set_pagesize(int nPageSize) {
		rho_sync_set_pagesize(nPageSize);
	}
	
	virtual int get_lastsync_objectcount(int nSrcID) {
		return rho_sync_get_lastsync_objectcount(nSrcID);
	}
	
	virtual int issyncing() {
		return rho_sync_issyncing();
	}
	
	virtual void enable_status_popup(int b) {
		rho_sync_enable_status_popup(b);
	}
	
	virtual void set_threaded_mode(int b) {
		rho_sync_set_threaded_mode(b);
	}
	
	virtual void register_push() {
		rho_sync_register_push();
	}
	
	virtual void set_ssl_verify_peer(int b) {
		rho_sync_set_ssl_verify_peer(b);
	}
	
	virtual void setobjectnotify_url(const char* szUrl) {
		rho_sync_setobjectnotify_url(szUrl);
	}
	
	virtual void cleanobjectnotify() {
		rho_sync_cleanobjectnotify();
	}
	
	virtual void clear_notification(int srcID) {
		rho_sync_clear_notification(srcID);
	}


};

RhoConnectClientRhodesInterfaceImpl g_client;

namespace rho {

class RhoConnectClientFactory : public CRhoConnectClientFactoryBase
{
public:
    RhoConnectClientFactory(){}
	
    IRhoConnectClientSingleton* createModuleSingleton(){ return new RhoConnectClientImpl(); }
};

}

extern "C" {

void initRhoconnectClient() {
	RHODESAPP().getExtManager().requireRubyFile("RhoConnectClient");

	rho::RhoConnectClientFactory::setInstance( new rho::RhoConnectClientFactory() );
	
	rho::sync::RhoconnectClientManager::setRhoconnectClientImpl( &g_client );
}

}