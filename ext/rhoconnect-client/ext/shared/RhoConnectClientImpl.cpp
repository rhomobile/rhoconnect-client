#include "RhoConnectClientImpl.h"
#include "logging/RhoLog.h"

namespace rho {


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
	getSyncThread()->setPollInterval( value );
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
	getSyncEngine().setNonThreadedMode(!value);
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

/*
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
*/
 
void RhoConnectClientImpl::search( const rho::Hashtable<rho::String, rho::String>& args, rho::apiGenerator::CMethodResult& oResult) {
	getSyncThread()->stopAll();
	
	getSyncEngine().getNotify().setSearchNotification( new sync::CSyncNotification(oResult, true) );
	
	rho::String params = "";
/*
	searchParams += '&offset=' + Rho::RhoSupport.url_encode(args[:offset]) if args[:offset]
        searchParams += '&max_results=' + Rho::RhoSupport.url_encode(args[:max_results]) if args[:max_results]
			
			callbackParams = args[:callback_param] ? args[:callback_param] : ""
			
			if args[:search_params]
				args[:search_params].each do |key,value|
					searchParams += '&' + "search[#{Rho::RhoSupport.url_encode(key)}]" + '=' + Rho::RhoSupport.url_encode(value)
					callbackParams += '&' + "search_params[#{Rho::RhoSupport.url_encode(key)}]" + '=' + Rho::RhoSupport.url_encode(value)
					end
					end

*/		
//	getSyncThread()->addQueueCommand(new sync::CSyncThread::CSyncSearchCommand(from,params,sources,syncChanges,progressStep) );
	
	oResult.setCollectionMode(true);
	const char* ret = (const char*)getSyncThread()->getRetValue();
	if (ret != 0) {
		oResult.set( ret );
	}
}
	
void RhoConnectClientImpl::doSync( bool showStatusPopup,  const rho::String& queryParams,  bool syncOnlyChangedSources, rho::apiGenerator::CMethodResult& oResult) {
    getSyncThread()->addQueueCommand(new sync::CSyncThread::CSyncCommand(sync::CSyncThread::scSyncAll,showStatusPopup,queryParams.c_str(),syncOnlyChangedSources));
	
	const char* ret = (const char*)getSyncThread()->getRetValue();
	if (ret != 0) {
		oResult.set( ret );
	}
}
	
void RhoConnectClientImpl::doSyncSource( const rho::String& sourceName,  bool showStatusPopup,  const rho::String& queryParams, rho::apiGenerator::CMethodResult& oResult) {
    getSyncThread()->addQueueCommand(new sync::CSyncThread::CSyncCommand(sync::CSyncThread::scSyncOne, sourceName, 0, false, "" ) );
	
	const char* ret = (const char*)getSyncThread()->getRetValue();
	if (ret != 0) {
		oResult.set( ret );
	}
}
	
void RhoConnectClientImpl::login( const rho::String& login,  const rho::String& password, rho::apiGenerator::CMethodResult& oResult) {	
	getSyncThread()->stopAll();
    getSyncThread()->addQueueCommand(new sync::CSyncThread::CSyncLoginCommand(login, password, new sync::CSyncNotification(oResult, false) ) );
	
	oResult.setCollectionMode(true);
	const char* ret = (const char*)getSyncThread()->getRetValue();
	if (ret != 0) {
		oResult.set( ret );
	}
}
	
void RhoConnectClientImpl::logout(rho::apiGenerator::CMethodResult& oResult) {
	rho_sync_logout();
}
	
void RhoConnectClientImpl::stopSync(rho::apiGenerator::CMethodResult& oResult) {
	getSyncThread()->stopAll();
}
	
void RhoConnectClientImpl::setNotification( const rho::String& sourceName, rho::apiGenerator::CMethodResult& oResult) {
	if ( sourceName == "*" ) {
		getSyncEngine().getNotify().setSyncNotification(-1, new sync::CSyncNotification(oResult, false) );
	} else {
		sync::CSyncSource* src = getSyncEngine().findSourceByName(sourceName);
		if ( src != 0 ) {
			getSyncEngine().getNotify().setSyncNotification(src->getID(), new sync::CSyncNotification(oResult, true) );
		}
	}
}
	
void RhoConnectClientImpl::clearNotification( const rho::String& sourceName, rho::apiGenerator::CMethodResult& oResult){
	if ( sourceName == "*" ) {
		getSyncEngine().getNotify().clearSyncNotification(-1);
	} else {
		sync::CSyncSource* src = getSyncEngine().findSourceByName(sourceName);
		if ( src != 0 ) {
			getSyncEngine().getNotify().clearSyncNotification(src->getID());
		}
	}
}
	
void RhoConnectClientImpl::setObjectNotification(rho::apiGenerator::CMethodResult& oResult) {
	sync::CSyncNotify::setObjectNotification(new sync::CObjectNotification(oResult));
}
	
void RhoConnectClientImpl::addObjectNotify( const rho::String& sourceName,  const rho::String& object, rho::apiGenerator::CMethodResult& oResult) {
    getSyncEngine().getNotify().addObjectNotify(sourceName, object);
}
	
void RhoConnectClientImpl::cleanObjectNotify(rho::apiGenerator::CMethodResult& oResult) {
    sync::CSyncNotify::setObjectNotification(0); 
}
	
void RhoConnectClientImpl::getLastSyncObjectCount( const rho::String& sourceName, rho::apiGenerator::CMethodResult& oResult) {
	int result = 0;
	sync::CSyncSource* src = getSyncEngine().findSourceByName(sourceName);
	if ( src != 0 ) {
		result = getSyncEngine().getNotify().getLastSyncObjectCount(src->getID());
	}
	
    oResult.set( result );
}
	
void RhoConnectClientImpl::setSourceProperty( const rho::String& sourceName,  const rho::String& propertyName,  const rho::String& propertyValue, rho::apiGenerator::CMethodResult& oResult) {
	
	sync::CSyncSource* src = getSyncEngine().findSourceByName(sourceName);
	if ( src != 0 ) {
		sync::CSyncEngine::getSourceOptions().setProperty(src->getID(), propertyName.c_str(), propertyValue.c_str());
	}
}
	
void RhoConnectClientImpl::getSourceProperty( const rho::String& sourceName,  const rho::String& propertyName, rho::apiGenerator::CMethodResult& oResult) {
	rho::String ret = "";
	sync::CSyncSource* src = getSyncEngine().findSourceByName(sourceName);
	if ( src != 0 ) {
		ret = sync::CSyncEngine::getSourceOptions().getProperty(src->getID(), propertyName.c_str());
	}
	oResult.set(ret);
}
/*
void RhoConnectClientImpl::getSourceNameById( int sourceId, rho::apiGenerator::CMethodResult& oResult) {
	if ( -1 == sourceId ) {
		oResult.set("*");
	} else {
		getSyncEngine().loadAllSources();
		sync::CSyncSource* src = getSyncEngine().findSourceById(sourceId);
		if ( src != 0 ) {
			oResult.set(src->getName());
		}
	}
}
*/
/*
void RhoConnectClientImpl::set_threaded_mode( bool threaded, rho::apiGenerator::CMethodResult& oResult) {
	setThreadedMode(threaded, oResult);
}

void RhoConnectClientImpl::set_ssl_verify_peer( bool verify, rho::apiGenerator::CMethodResult& oResult) {
	setSslVerifyPeer(verify, oResult);
}
	
void RhoConnectClientImpl::set_pollinterval( int interval, rho::apiGenerator::CMethodResult& oResult) {
	setPollInterval(interval, oResult);
		
}
	
void RhoConnectClientImpl::get_pollinterval(rho::apiGenerator::CMethodResult& oResult) {
	getPollInterval(oResult);
}
	
void RhoConnectClientImpl::set_syncserver( const rho::String& url, rho::apiGenerator::CMethodResult& oResult) {
	setSyncServer(url, oResult);
}
	
void RhoConnectClientImpl::set_pagesize( int size, rho::apiGenerator::CMethodResult& oResult) {
	setPageSize(size, oResult);
}
	
void RhoConnectClientImpl::get_pagesize(rho::apiGenerator::CMethodResult& oResult) {
	getPageSize(oResult);
}
	
void RhoConnectClientImpl::enable_status_popup( bool enable, rho::apiGenerator::CMethodResult& oResult) {
	setShowStatusPopup(enable,oResult);
}
	
void RhoConnectClientImpl::dosync_source( int source,  int showStatusPopup,  const rho::String& queryParams, rho::apiGenerator::CMethodResult& oResult) {
	sync::CSyncThread::getInstance()->addQueueCommand(new sync::CSyncThread::CSyncCommand(sync::CSyncThread::scSyncOne, "", source, showStatusPopup!=0, queryParams.c_str() ) );
    oResult.set( (const char*)sync::CSyncThread::getInstance()->getRetValue() );
}
	
void RhoConnectClientImpl::set_notification( int source, rho::apiGenerator::CMethodResult& oResult) {
	rho_sync_set_notification(source,"","");
}
	
void RhoConnectClientImpl::clear_notification( int source, rho::apiGenerator::CMethodResult& oResult) {
	rho_sync_clear_notification(source);
}
	
void RhoConnectClientImpl::add_objectnotify( int source,  const rho::String& object, rho::apiGenerator::CMethodResult& oResult) {
	rho_sync_addobjectnotify( source, object.c_str() );
}
	
void RhoConnectClientImpl::get_lastsync_objectcount( int source, rho::apiGenerator::CMethodResult& oResult) {
	oResult.set( rho_sync_get_lastsync_objectcount( source ) );
}
	
void RhoConnectClientImpl::set_source_property( int source,  const rho::String& propertyName,  const rho::String& propertyValue, rho::apiGenerator::CMethodResult& oResult) {
	rho_sync_set_source_property(source,propertyName.c_str(),propertyValue.c_str());
}
	
void RhoConnectClientImpl::get_source_property( int source,  const rho::String& propertyName, rho::apiGenerator::CMethodResult& oResult) {
	oResult.set(rho_sync_get_source_property(source,propertyName.c_str()));
}
	
void RhoConnectClientImpl::logged_in(rho::apiGenerator::CMethodResult& oResult) {
	oResult.set( getSyncEngine().isLoggedIn()?1:0 );
}
	
void RhoConnectClientImpl::is_syncing(rho::apiGenerator::CMethodResult& oResult) {
	oResult.set( getSyncEngine().isSyncing()?1:0 );
}
*/
}
