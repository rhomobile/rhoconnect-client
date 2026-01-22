#include "RhoConnectClientImpl.h"
#include "common/RhoSettingsDefs.h"
#include "logging/RhoLog.h"
#include "json/JSONIterator.h"
#include "net/URI.h"
#include "common/RhoConf.h"

#undef DEFAULT_LOGCATEGORY
#define DEFAULT_LOGCATEGORY "RhoConnectClientImpl"

namespace rho {


RhoConnectClientImpl::RhoConnectClientImpl()
{
}
	
void RhoConnectClientImpl::getUserName(rho::apiGenerator::CMethodResult& oResult) {
    oResult.set( RHOCONF().getString("rho_sync_user") );
}
	
void RhoConnectClientImpl::getPollInterval(rho::apiGenerator::CMethodResult& oResult) {
	oResult.set( getSyncThread()->getPollInterval() );
}
	
void RhoConnectClientImpl::setPollInterval( int value, rho::apiGenerator::CMethodResult& oResult) {
	getSyncThread()->setPollInterval( value );
}
	
void RhoConnectClientImpl::getSyncServer(rho::apiGenerator::CMethodResult& oResult) {
	oResult.set( getSyncEngine().getSyncServer() );
}
	
void RhoConnectClientImpl::setSyncServer( const rho::String& value, rho::apiGenerator::CMethodResult& oResult) {
	rho_sync_set_syncserver(value.c_str());
}

void RhoConnectClientImpl::getBulksyncState(rho::apiGenerator::CMethodResult& oResult) {
	oResult.set( RHOCONF().getInt(RHO_SETTING_BULKSYNC_STATE) );
}

void RhoConnectClientImpl::setBulksyncState(int state, rho::apiGenerator::CMethodResult& oResult) {
	RHOCONF().setInt(RHO_SETTING_BULKSYNC_STATE, state, true);
}
	
void RhoConnectClientImpl::getPageSize(rho::apiGenerator::CMethodResult& oResult) {
	oResult.set( getSyncEngine().getSyncPageSize() );
}
	
void RhoConnectClientImpl::setPageSize( int value, rho::apiGenerator::CMethodResult& oResult) {
	getSyncEngine().setSyncPageSize( value );
}
	
void RhoConnectClientImpl::getThreadedMode(rho::apiGenerator::CMethodResult& oResult) {
	oResult.set( !getSyncEngine().isNoThreadedMode() );
}
	
void RhoConnectClientImpl::setThreadedMode( bool value, rho::apiGenerator::CMethodResult& oResult) {
	getSyncThread()->setNonThreadedMode(!value);
	getSyncEngine().setNonThreadedMode(!value);
}
	
void RhoConnectClientImpl::getShowStatusPopup(rho::apiGenerator::CMethodResult& oResult) {
	oResult.set( getSyncEngine().getNotify().isStatusPopupEnabled() );
}
	
void RhoConnectClientImpl::setShowStatusPopup( bool value, rho::apiGenerator::CMethodResult& oResult) {
	getSyncEngine().getNotify().enableStatusPopup( value );
}
	
void RhoConnectClientImpl::getSslVerifyPeer(rho::apiGenerator::CMethodResult& oResult) {
	oResult.set( getSyncEngine().getSslVerifyPeer() );
}
	
void RhoConnectClientImpl::setSslVerifyPeer( bool value, rho::apiGenerator::CMethodResult& oResult) {
	getSyncEngine().setSslVerifyPeer(value);
}
	
void RhoConnectClientImpl::isLoggedIn(rho::apiGenerator::CMethodResult& oResult) {
	oResult.set( getSyncEngine().isLoggedIn() );
}
	
void RhoConnectClientImpl::isSyncing(rho::apiGenerator::CMethodResult& oResult) {
	oResult.set( getSyncEngine().isSyncing() );
}
 
void RhoConnectClientImpl::search( const rho::Hashtable<rho::String, rho::String>& args, rho::apiGenerator::CMethodResult& oResult) {
	getSyncThread()->stopAll();

	bool syncChanges = false;
	int progressStep = -1;
	rho::Vector<rho::String> sources;
	rho::String searchParams;
	rho::String from = "search";
	
	/* handle old-style callback setting */
	if (args.containsKey("callback")) {
		oResult.setRubyCallback(args.get("callback"));
        
        if (args.containsKey("callback_param")) {
            oResult.setCallbackParam(args.get("callback_param"));
        }
	}
		
	if (args.containsKey("from") ) {
		from = args.get("from");
	}
	
	/*this will return new arg value, overriding deprecated one, if it is present*/
	struct DeprecatedArgsHandler {
		static bool getArgValue( const rho::Hashtable<rho::String, rho::String>& args, const rho::String& newArgName, const rho::String& deprecatedArgName, rho::String& realArgValue ) {
			bool found = false;
			if ( args.containsKey(deprecatedArgName) ) {
				RAWLOG_WARNING2("'%s' argument is deprecated for search. Use '%s' instead.",deprecatedArgName.c_str(),newArgName.c_str());
				realArgValue = args.get(deprecatedArgName);
				found = true;
			}
			if ( args.containsKey(newArgName) ) {
				realArgValue = args.get(newArgName);
				found = true;
			}
			return found;
		}
	};
	
	
	String jsonSources;
	if ( DeprecatedArgsHandler::getArgValue(args,"sourceNames","source_names",jsonSources) ) {
		rho::json::CJSONEntry json(jsonSources.c_str());
		if ( json.isArray() ) {
			for( rho::json::CJSONArrayIterator array(json); !array.isEnd(); array.next()) {
				sources.push_back( array.getCurItem().getString() );
			}
		}
	}

	if (args.containsKey("offset")) {
		searchParams += "&offset=" + rho::net::URI::urlEncode(args.get("offset"));
	}
	
	rho::String maxResults;
	if ( DeprecatedArgsHandler::getArgValue(args,"maxResults","max_results",maxResults) ) {
		searchParams += "&max_results=" + rho::net::URI::urlEncode(maxResults);
	}
	
	
	rho::String jsonSearchParams;
	if ( DeprecatedArgsHandler::getArgValue(args,"searchParams","search_params",jsonSearchParams) ) {
		rho::json::CJSONEntry json(jsonSearchParams.c_str());
		if ( json.isObject() ) {
			for ( rho::json::CJSONStructIterator obj(json); !obj.isEnd(); obj.next() ) {
				rho::String key = rho::net::URI::urlEncode(obj.getCurKey());
				rho::String value = rho::net::URI::urlEncode(obj.getCurValue().getString());
				
				searchParams += "&search[" + key + "]=" + value;
			}
		}
	}
	
	rho::String strSyncChanges;
	if ( DeprecatedArgsHandler::getArgValue(args,"syncChanges","sync_changes",strSyncChanges) ) {
		syncChanges = (strSyncChanges=="true") || (strSyncChanges=="1");
	}
	
	rho::String strProgressStep;
	if ( DeprecatedArgsHandler::getArgValue(args,"progressStep","progress_step",strProgressStep) ) {
		progressStep = atoi(strProgressStep.c_str());
	}

	getSyncEngine().getNotify().setSearchNotification( new sync::CSyncNotification(oResult, true) );
	getSyncThread()->addQueueCommand(new sync::CSyncThread::CSyncSearchCommand(from,searchParams,sources,syncChanges,progressStep) );
		
	handleSyncResult(oResult);
}
	
void RhoConnectClientImpl::doSync( bool showStatusPopup,  const rho::String& queryParams,  bool syncOnlyChangedSources, rho::apiGenerator::CMethodResult& oResult) {
    getSyncThread()->addQueueCommand(new sync::CSyncThread::CSyncCommand(sync::CSyncThread::scSyncAll,showStatusPopup,queryParams.c_str(),syncOnlyChangedSources));
	
	handleSyncResult(oResult);
}
	
void RhoConnectClientImpl::doSyncSource( const rho::String& sourceName,  bool showStatusPopup,  const rho::String& queryParams, rho::apiGenerator::CMethodResult& oResult) {
    getSyncThread()->addQueueCommand(new sync::CSyncThread::CSyncCommand(sync::CSyncThread::scSyncOne, sourceName, 0, false, queryParams.c_str() ) );
	
	handleSyncResult(oResult);
}
	
void RhoConnectClientImpl::login( const rho::String& login,  const rho::String& password, rho::apiGenerator::CMethodResult& oResult) {	
	getSyncThread()->stopAll();
    getSyncThread()->addQueueCommand(new sync::CSyncThread::CSyncLoginCommand(login, password, new sync::CSyncNotification(oResult, false) ) );
	
	handleSyncResult(oResult);	
}

void RhoConnectClientImpl::setProtocolExtras( const rho::Hashtable<rho::String, rho::String>& extras, rho::apiGenerator::CMethodResult& oResult) {

    rho::sync::CSyncEngine::ProtocolExtras parsedExtras;

    for ( auto it = extras.begin(); it != extras.end(); ++it ) {

        rho::Hashtable< rho::String, rho::String > parsedExtra;

        rho::json::CJSONEntry json( it->second.c_str() );
        if ( json.isObject() ) {
            for( rho::json::CJSONStructIterator jobj( json ); !jobj.isEnd(); jobj.next()) {
                if ( jobj.getCurValue().isString()) {
                    parsedExtra.put( jobj.getCurKey(), jobj.getCurString() );
                }
            }
        }

        parsedExtras.put( it->first, parsedExtra );

    }

    getSyncThread()->addQueueCommand(new sync::CSyncThread::CSyncSetProtoExtrasCommand( parsedExtras ));
}	
	
void RhoConnectClientImpl::handleSyncResult(rho::apiGenerator::CMethodResult& oResult) {
	if ( getSyncEngine().isNoThreadedMode() ) {
		oResult.setCollectionMode(true);
		const char* ret = (const char*)getSyncThread()->getRetValue();
		if (ret != 0) {
			oResult.setJSON( ret );
		}
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
}
