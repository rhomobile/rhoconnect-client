
#include "sync/RhoconnectClientManager.h"
#include "sync/SyncThread.h"
#include "sync/ClientRegister.h"

class RhoconnectClientImpl : public rho::sync::IRhoconnectClient {
public:
	virtual ~RhoconnectClientImpl() {}
	
	virtual void doSyncSourceByName( const char* srcName ) {
		rho_sync_doSyncSourceByName( srcName );
	}
	
	virtual void doSyncAllSources( int show_status_popup, const char* query_params, int sync_only_changed_sources ) {
		rho_sync_doSyncAllSources(show_status_popup, query_params, sync_only_changed_sources );
	}
	
	virtual void clientRegisterCreate( const char* szDevicePin ) {
		rho::sync::CClientRegister::Create(szDevicePin);
	}
	
	virtual void rho_sync_addobjectnotify_bysrcname(const char* szSrcName, const char* szObject) {
		rho_sync_addobjectnotify_bysrcname(szSrcName, szObject);
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
	
	virtual bool syncEngineNotifyIsReportingEnabled() {
		return rho::sync::CSyncThread::getInstance()->getSyncEngine().getNotify().isReportingEnabled();
	}
	
	virtual int rho_sync_issyncing() {
		return rho_sync_issyncing();
	}

};

RhoconnectClientImpl g_client;

extern "C" {

void initRhoconnectClient() {
	
	rho::sync::RhoconnectClientManager::setRhoconnectClientImpl( &g_client );
	
}

}