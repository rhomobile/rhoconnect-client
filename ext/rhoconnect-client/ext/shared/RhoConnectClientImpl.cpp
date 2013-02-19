#include "RhoConnectClientBase.h"


namespace rho {

rho::common::CAutoPtr< CRhoConnectClientFactoryBase> CRhoConnectClientFactoryBase::m_pInstance;



RhoConnectClientImpl::RhoConnectClientImpl()
{
}
	
void RhoConnectClientImpl::getUserName(rho::apiGenerator::CMethodResult& oResult) {
}
	
void RhoConnectClientImpl::getPollInterval(rho::apiGenerator::CMethodResult& oResult) {
}
	
void RhoConnectClientImpl::setPollInterval( int value, rho::apiGenerator::CMethodResult& oResult) {
}
	
void RhoConnectClientImpl::getSyncServer(rho::apiGenerator::CMethodResult& oResult) {
}
	
void RhoConnectClientImpl::setSyncServer( const rho::String& value, rho::apiGenerator::CMethodResult& oResult) {
}
	
void RhoConnectClientImpl::getPageSize(rho::apiGenerator::CMethodResult& oResult) {
}
	
void RhoConnectClientImpl::setPageSize( int value, rho::apiGenerator::CMethodResult& oResult) {
}
	
void RhoConnectClientImpl::getThreadedMode(rho::apiGenerator::CMethodResult& oResult) {
}
	
void RhoConnectClientImpl::setThreadedMode( bool value, rho::apiGenerator::CMethodResult& oResult) {
}
	
void RhoConnectClientImpl::getShowStatusPopup(rho::apiGenerator::CMethodResult& oResult) {
}
	
void RhoConnectClientImpl::setShowStatusPopup( bool value, rho::apiGenerator::CMethodResult& oResult) {
}
	
void RhoConnectClientImpl::getSslVerifyPeer(rho::apiGenerator::CMethodResult& oResult) {
}
	
void RhoConnectClientImpl::setSslVerifyPeer( bool value, rho::apiGenerator::CMethodResult& oResult) {
}
	
void RhoConnectClientImpl::loggedIn(rho::apiGenerator::CMethodResult& oResult) {
}
	
void RhoConnectClientImpl::syncing(rho::apiGenerator::CMethodResult& oResult) {
}
	
void RhoConnectClientImpl::onSyncCreateError( const rho::String& srcName,  const rho::Vector<rho::String>& objects,  const rho::String& action, rho::apiGenerator::CMethodResult& oResult) {
}
	
void RhoConnectClientImpl::pushChanges( const rho::String& srcName, rho::apiGenerator::CMethodResult& oResult) {
}

void RhoConnectClientImpl::onSyncUpdateError( const rho::String& srcName,  const rho::Vector<rho::String>& objects,  const rho::String& action,  const rho::String& rollbackData, rho::apiGenerator::CMethodResult& oResult) {
}
	
void RhoConnectClientImpl::onSyncDeleteError( const rho::String& srcName,  const rho::Vector<rho::String>& objects,  const rho::String& action, rho::apiGenerator::CMethodResult& oResult) {
}
	
void RhoConnectClientImpl::search( const rho::Hashtable<rho::String, rho::String>& args, rho::apiGenerator::CMethodResult& oResult) {
}
	
void RhoConnectClientImpl::doSync( bool showStatusPopup,  const rho::String& queryParams,  bool syncOnlyChangedSources, rho::apiGenerator::CMethodResult& oResult) {
}
	
void RhoConnectClientImpl::doSyncSource( const rho::String& sourceName,  bool showStatusPopup,  const rho::String& queryParams, rho::apiGenerator::CMethodResult& oResult) {
}
	
void RhoConnectClientImpl::login( const rho::String& login,  const rho::String& password, rho::apiGenerator::CMethodResult& oResult) {
}
	
void RhoConnectClientImpl::logout(rho::apiGenerator::CMethodResult& oResult) {
}
	
void RhoConnectClientImpl::stopSync(rho::apiGenerator::CMethodResult& oResult) {
}
	
void RhoConnectClientImpl::setNotification( const rho::String& sourceName, rho::apiGenerator::CMethodResult& oResult) {
}
	
void RhoConnectClientImpl::clearNotification( const rho::String& sourceName, rho::apiGenerator::CMethodResult& oResult) {
}
	
void RhoConnectClientImpl::setObjectNotification(rho::apiGenerator::CMethodResult& oResult) {
}
	
void RhoConnectClientImpl::addObjectNotify( const rho::String& sourceName,  const rho::String& object, rho::apiGenerator::CMethodResult& oResult) {
}
	
void RhoConnectClientImpl::cleanObjectNotify(rho::apiGenerator::CMethodResult& oResult) {
}
	
void RhoConnectClientImpl::getLastSyncObjectCount( const rho::String& sourceName, rho::apiGenerator::CMethodResult& oResult) {
}
	
void RhoConnectClientImpl::setSourceProperty( const rho::String& sourceName,  const rho::String& propertyName,  const rho::String& propertyValue, rho::apiGenerator::CMethodResult& oResult) {
}
	
void RhoConnectClientImpl::getSourceProperty( const rho::String& sourceName,  const rho::String& propertyName, rho::apiGenerator::CMethodResult& oResult) {
}
	
	
	
}
