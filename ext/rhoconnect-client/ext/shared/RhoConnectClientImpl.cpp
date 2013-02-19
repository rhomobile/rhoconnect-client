#include "RhoConnectClientBase.h"

namespace rho {

rho::common::CAutoPtr< CRhoConnectClientFactoryBase> CRhoConnectClientFactoryBase::m_pInstance;



RhoConnectClientImpl::RhoConnectClientImpl()
{
}
	
void RhoConnectClientImpl::getUserName(rho::apiGenerator::CMethodResult& oResult) {
	//implemented in Ruby
}
	
void RhoConnectClientImpl::getPollInterval(rho::apiGenerator::CMethodResult& oResult) {
	oResult.set( getSyncThread()->getPollInterval() );
}
	
void RhoConnectClientImpl::setPollInterval( int value, rho::apiGenerator::CMethodResult& oResult) {
	oResult.set( getSyncThread()->setPollInterval( value ) );
}
	
void RhoConnectClientImpl::getSyncServer(rho::apiGenerator::CMethodResult& oResult) {
	//TODO oResult.set( getSyncEngine().getSyncServer() );
}
	
void RhoConnectClientImpl::setSyncServer( const rho::String& value, rho::apiGenerator::CMethodResult& oResult) {
	rho_sync_set_syncserver(value.c_str());
}
	
void RhoConnectClientImpl::getPageSize(rho::apiGenerator::CMethodResult& oResult) {
	oResult.set( getSyncEngine().getSyncPageSize() );
}
	
void RhoConnectClientImpl::setPageSize( int value, rho::apiGenerator::CMethodResult& oResult) {
	getSyncEngine().setSyncPageSize( value );
}
	
void RhoConnectClientImpl::getThreadedMode(rho::apiGenerator::CMethodResult& oResult) {
	//TODO
}
	
void RhoConnectClientImpl::setThreadedMode( bool value, rho::apiGenerator::CMethodResult& oResult) {
	getSyncThread()->setNonThreadedMode(!value);
	getStncEngine().setNonThreadedMode(!value);
}
	
void RhoConnectClientImpl::getShowStatusPopup(rho::apiGenerator::CMethodResult& oResult) {
	//TODO
}
	
void RhoConnectClientImpl::setShowStatusPopup( bool value, rho::apiGenerator::CMethodResult& oResult) {
	getSyncEngine().getNotify().enableStatusPopup( value );
}
	
void RhoConnectClientImpl::getSslVerifyPeer(rho::apiGenerator::CMethodResult& oResult) {
	//TODO
}
	
void RhoConnectClientImpl::setSslVerifyPeer( bool value, rho::apiGenerator::CMethodResult& oResult) {
	getSyncEngine().setSslVerifyPeer(value);
}
	
void RhoConnectClientImpl::loggedIn(rho::apiGenerator::CMethodResult& oResult) {
	oResult.set( getSyncEngine().isLoggedIn() );
}
	
void RhoConnectClientImpl::syncing(rho::apiGenerator::CMethodResult& oResult) {
	oResult.set( getSyncEngine().isSyncing() );
}
	
void RhoConnectClientImpl::onSyncCreateError( const rho::String& srcName,  const rho::Vector<rho::String>& objects,  const rho::String& action, rho::apiGenerator::CMethodResult& oResult) {
	//implemented in Ruby
}
	
void RhoConnectClientImpl::pushChanges( const rho::String& srcName, rho::apiGenerator::CMethodResult& oResult) {
	//implemented in Ruby
}

void RhoConnectClientImpl::onSyncUpdateError( const rho::String& srcName,  const rho::Vector<rho::String>& objects,  const rho::String& action,  const rho::String& rollbackData, rho::apiGenerator::CMethodResult& oResult) {
	//implemented in Ruby
}
	
void RhoConnectClientImpl::onSyncDeleteError( const rho::String& srcName,  const rho::Vector<rho::String>& objects,  const rho::String& action, rho::apiGenerator::CMethodResult& oResult) {
	//implemented in Ruby
}
	
void RhoConnectClientImpl::search( const rho::Hashtable<rho::String, rho::String>& args, rho::apiGenerator::CMethodResult& oResult) {
	//TODO parse arguments
}
	
void RhoConnectClientImpl::doSync( bool showStatusPopup,  const rho::String& queryParams,  bool syncOnlyChangedSources, rho::apiGenerator::CMethodResult& oResult) {
    getSyncThread()->addQueueCommand(new sync::CSyncThread::CSyncCommand(sync::CSyncThread::scSyncAll,show_status_popup,query_params,sync_only_changed_sources));
	oResult.set( getSyncThread()->getRetValue() );	
}
	
void RhoConnectClientImpl::doSyncSource( const rho::String& sourceName,  bool showStatusPopup,  const rho::String& queryParams, rho::apiGenerator::CMethodResult& oResult) {
    getSyncThread()->addQueueCommand(new sync::CSyncThread::CSyncCommand(sync::CSyncThread::scSyncOne, szSrcName, 0, false, "" ) );
    oResult.set( getSyncThread()->getRetValue() );
}
	
void RhoConnectClientImpl::login( const rho::String& login,  const rho::String& password, rho::apiGenerator::CMethodResult& oResult) {
	//TODO callback?
	oResult.set( rho_sync_login( login.c_str(), password.c_str(), 0 ) );
}
	
void RhoConnectClientImpl::logout(rho::apiGenerator::CMethodResult& oResult) {
	rho_sync_logout();
}
	
void RhoConnectClientImpl::stopSync(rho::apiGenerator::CMethodResult& oResult) {
	oResult.set( getSyncThread()->stopAll() );
}
	
void RhoConnectClientImpl::setNotification( const rho::String& sourceName, rho::apiGenerator::CMethodResult& oResult) {
	//TODO callback?
}
	
void RhoConnectClientImpl::clearNotification( const rho::String& sourceName, rho::apiGenerator::CMethodResult& oResult) {
	getSyncEngine().getNotify().clearSyncNotification(sourceName);
}
	
void RhoConnectClientImpl::setObjectNotification(rho::apiGenerator::CMethodResult& oResult) {
	//TODO callback?
}
	
void RhoConnectClientImpl::addObjectNotify( const rho::String& sourceName,  const rho::String& object, rho::apiGenerator::CMethodResult& oResult) {
    getSyncEngine().getNotify().addObjectNotify(sourceName, object);
}
	
void RhoConnectClientImpl::cleanObjectNotify(rho::apiGenerator::CMethodResult& oResult) {
    sync::CSyncNotify::setObjectNotification(0); 
}
	
void RhoConnectClientImpl::getLastSyncObjectCount( const rho::String& sourceName, rho::apiGenerator::CMethodResult& oResult) {
    oResult.set( getSyncEngine().getNotify().getLastSyncObjectCount(sourceName) );
}
	
void RhoConnectClientImpl::setSourceProperty( const rho::String& sourceName,  const rho::String& propertyName,  const rho::String& propertyValue, rho::apiGenerator::CMethodResult& oResult) {
    sync::CSyncEngine::getSourceOptions().setProperty(sourceName, propertyName, propertyValue);
}
	
void RhoConnectClientImpl::getSourceProperty( const rho::String& sourceName,  const rho::String& propertyName, rho::apiGenerator::CMethodResult& oResult) {
	oResult.set( sync::CSyncEngine::getSourceOptions().getProperty(sourceName, propertyName) );
}
	
	
	
}
