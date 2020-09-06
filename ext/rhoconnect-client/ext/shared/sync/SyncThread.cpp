/*------------------------------------------------------------------------
* (The MIT License)
* 
* Copyright (c) 2008-2011 Rhomobile, Inc.
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
* 
* http://rhomobile.com

* Copyright (c) 2011-2016 Symbol Technologies, Inc.
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
* 
* http://symbol.com
*------------------------------------------------------------------------*/

#include "SyncThread.h"
#include "common/RhoTime.h"
#include "common/RhoSettingsDefs.h"
#include "common/RhoConf.h"
#include "common/RhoFilePath.h"

#ifndef RHO_NO_RUBY
#include "ruby/ext/rho/rhoruby.h"
#endif //RHO_NO_RUBY
#include "sync/ClientRegister.h"
#include "common/RhoAppAdapter.h"

#undef DEFAULT_LOGCATEGORY
#define DEFAULT_LOGCATEGORY "SyncThread"

namespace rho {
namespace sync {

using namespace rho::common;
using namespace rho::db;

IMPLEMENT_LOGCLASS(CSyncThread,"Sync");
CSyncThread* CSyncThread::m_pInstance = 0;

/*static*/ CSyncThread* CSyncThread::Create()
{
    if ( m_pInstance ) 
        return m_pInstance;

    m_pInstance = new CSyncThread();
    return m_pInstance;
}

/*static*/void CSyncThread::Destroy()
{
    if ( m_pInstance )
        delete m_pInstance;

    m_pInstance = 0;
}

CSyncThread::CSyncThread() : CThreadQueue()
{
    CThreadQueue::setLogCategory(getLogCategory());
    
    int pollInterval = 60;

    if( RHOCONF().isExist("sync_poll_interval") ) {
        pollInterval = RHOCONF().getInt("sync_poll_interval");
    }

    setPollInterval(pollInterval);
    
    LOG(INFO) + "sync_poll_interval: " + pollInterval;
    LOG(INFO) + "syncserver: " + RHOCONF().getString("syncserver");
    LOG(INFO) + "bulksync_state: " + RHOCONF().getInt("bulksync_state");
#ifdef OS_WINCE
    start(epCritical);
#else
	start(epLow);
#endif
}

CSyncThread::~CSyncThread(void)
{
    m_oSyncEngine.exitSync();
    LOG(INFO) + "Stopping Sync thread";
    stop(SYNC_WAIT_BEFOREKILL_SECONDS);
}

/*
#ifndef RHO_NO_RUBY
unsigned long CSyncThread::getRetValue()
{
    unsigned long ret = rho_ruby_get_NIL();
    if ( isNoThreadedMode()  )
    {
        ret = rho_ruby_create_string( getSyncEngine().getNotify().getNotifyBody().c_str() );
        getSyncEngine().getNotify().cleanNotifyBody();
    }

    return ret;
}
#else
*/
unsigned long CSyncThread::getRetValue()
{
    unsigned long ret = 0;
    if ( isNoThreadedMode()  )
    {
        ret = (unsigned long)rho_sync_create_string( getSyncEngine().getNotify().getNotifyBody().c_str() );
        getSyncEngine().getNotify().cleanNotifyBody();
    }

    return ret;
}
//#endif

int CSyncThread::getLastPollInterval()
{
    uint64 nowTime = CLocalTime().toULong();
    uint64 latestTimeUpdated = 0;

    Vector<String> arPartNames = db::CDBAdapter::getDBAllPartitionNames();
    for( int i = 0; i < (int)arPartNames.size(); i++ )
    {
        db::CDBAdapter& dbPart = db::CDBAdapter::getDB(arPartNames.elementAt(i).c_str());

        IDBResult res = dbPart.executeSQL("SELECT last_updated from sources");
        for ( ; !res.isEnd(); res.next() )
        { 
            uint64 timeUpdated = res.getUInt64ByIdx(0);
            if ( latestTimeUpdated < timeUpdated )
        	    latestTimeUpdated = timeUpdated;
        }
    }

	return latestTimeUpdated > 0 ? (int)(nowTime-latestTimeUpdated) : 0;
}

void CSyncThread::onTimeout()//throws Exception
{
    if ( isNoCommands() && getPollInterval()>0 )
        addQueueCommandInt(new CSyncCommand(scSyncAll,false,"",false));
}

void CSyncThread::checkShowStatus(CSyncCommand& oSyncCmd)
{
	boolean bShowStatus = oSyncCmd.m_bShowStatus;
	m_oSyncEngine.getNotify().enableReporting(bShowStatus);
    if (m_oSyncEngine.getNotify().isReportingEnabled())
        m_oSyncEngine.getNotify().showStatusPopup(RhoAppAdapter.getMessageText("syncronizing_data"));
    //m_statusListener.createStatusPopup(RhoRuby.getMessageText("syncronizing_data"));
}	

void CSyncThread::processCommand(IQueueCommand* pCmd)
{
    CSyncCommand& oSyncCmd = *((CSyncCommand*)pCmd);
    checkShowStatus(oSyncCmd);
    oSyncCmd.executeForSyncEngine( m_oSyncEngine );
}

void CSyncThread::CSyncCommand::executeForSyncEngine( CSyncEngine& sync )
{
    switch(m_nCmdCode)
    {
    case scSyncAll:
        sync.doSyncAllSources(m_strQueryParams,m_bSyncOnlyChangedSources);
        break;

    case scSyncOne:
        sync.doSyncSource(CSyncEngine::CSourceID(m_nCmdParam,m_strCmdParam), m_strQueryParams );
        break;
    }
}

void CSyncThread::CSyncSearchCommand::executeForSyncEngine(CSyncEngine &sync)
{
    sync.doSearch( m_arSources, m_strCmdParam, m_strFrom, m_bSyncChanges, m_nCmdParam);
}

void CSyncThread::CSyncLoginCommand::executeForSyncEngine(CSyncEngine &sync)
{
    sync.login(m_strName, m_strPassword, *m_pNotify );
}

void CSyncThread::CSyncSetProtoExtrasCommand::executeForSyncEngine(CSyncEngine &sync)
{
    sync.setProtocolExtras( m_extras );
}

void CSyncThread::setPollInterval(int nInterval)
{ 
//    if ( nInterval == 0 )
//        m_oSyncEngine.stopSync();

    CThreadQueue::setPollInterval(nInterval);
}
    
void CSyncThread::stopAll() {
	LOG(INFO)+"STOP sync";
	
	if (CSyncThread::getSyncEngine().isSyncing() )
	{
		LOG(INFO)+"STOP sync in progress.";

        {
            synchronized(getCommandLock());
        
            getCommands().clear();
        }
        
	CSyncThread::getSyncEngine().stopSyncByUser();

	//don't wait if calling from notify callback
	if ( CSyncThread::getSyncEngine().getNotify().isInsideCallback() )
	{
		LOG(INFO)+"STOP sync called inside notify.";
		return;
	}

        CSyncThread::getInstance()->stopWait();

	 while (!CSyncThread::getInstance()->isWaiting()) {
            CSyncThread::getInstance()->sleep(100);
        }

        while( CDBAdapter::isAnyInsideTransaction() )
			CSyncThread::getInstance()->sleep(100);
	}
}


String CSyncThread::CSyncCommand::toString()
{
    switch(m_nCmdCode)
    {
    case scNone:
        return "CheckPollInterval";

    case scSyncAll:
        return "SyncAll";
    case scSyncOne:
        return "SyncOne";
    case scLogin:
        return "Login";
    case scSearchOne:
        return "Search";
    case scSetProtoExtras:
        return "SetProtoExtras";
    }

    return "Unknown; Code : " + convertToStringA(m_nCmdCode);
}

};
};

extern "C" {

using namespace rho::sync;
using namespace rho::db;
	
unsigned long rho_sync_doSyncAllSources(int show_status_popup, const char * query_params/* = 0*/, int sync_only_changed_sources)
{
    CSyncThread::getInstance()->addQueueCommand(new CSyncThread::CSyncCommand(CSyncThread::scSyncAll,show_status_popup!=0,query_params,sync_only_changed_sources!=0));

    return CSyncThread::getInstance()->getRetValue();
}

unsigned long rho_sync_doSyncSourceByID(int nSrcID)
{
    CSyncThread::getInstance()->addQueueCommand(new CSyncThread::CSyncCommand(CSyncThread::scSyncOne, "", nSrcID, false, "" ) );
    return CSyncThread::getInstance()->getRetValue();
}

unsigned long rho_sync_doSyncSourceByName(const char* szSrcName)
{
    CSyncThread::getInstance()->addQueueCommand(new CSyncThread::CSyncCommand(CSyncThread::scSyncOne, szSrcName, 0, false, "" ) );
    return CSyncThread::getInstance()->getRetValue();
}

#ifndef RHO_NO_RUBY
unsigned long rho_sync_doSyncSource(unsigned long nSrcID,int show_status_popup, const char * query_params/* = 0*/)
{
    CRhoRubyStringOrInt oSrcID = rho_ruby_getstringorint(nSrcID);
    CSyncThread::getInstance()->addQueueCommand(new CSyncThread::CSyncCommand(CSyncThread::scSyncOne, oSrcID.m_szStr, (int)oSrcID.m_nInt, show_status_popup!=0, query_params, false ) );

    return CSyncThread::getInstance()->getRetValue();
}	
#endif //RHO_NO_RUBY

void rho_sync_set_bulksyncstate(const int new_state)
{
    RHOCONF().setInt(RHO_SETTING_BULKSYNC_STATE, new_state, true);
}

int rho_sync_get_bulksyncstate()
{
    if(!RHOCONF().isExist(RHO_SETTING_BULKSYNC_STATE))
        return -1;
    return RHOCONF().getInt(RHO_SETTING_BULKSYNC_STATE);
}

bool rho_sync_has_bulksyncstate()
{
    return RHOCONF().isExist(RHO_SETTING_BULKSYNC_STATE);
}

void rho_sync_stop()
{
	CSyncThread::getInstance()->stopAll();
}

int  rho_sync_issyncing()
{
    return CSyncThread::getSyncEngine().isSyncing() ? 1 : 0;
}

#ifndef RHO_NO_RUBY
unsigned long rho_sync_is_syncing()
{
    return rho_ruby_create_boolean(rho_sync_issyncing());
}
#endif //RHO_NO_RUBY

void
source_iter(const char* szName, int nameLen, void* parSources)
{
    rho::Vector<rho::String>& arSources = *((rho::Vector<rho::String>*)(parSources));
    arSources.addElement(szName);
}
}

#ifndef RHO_NO_RUBY
unsigned long rho_sync_doSearch(unsigned long ar_sources, const char *from, const char *params, bool sync_changes, int nProgressStep, 
								/*const char* callback, const char* callback_params*/const rho::apiGenerator::CMethodResult& oResult)
{
    rho_sync_stop();
//    if ( callback && *callback )
        CSyncThread::getSyncEngine().getNotify().setSearchNotification( new CSyncNotification( oResult, true) );

    rho::Vector<rho::String> arSources;
    rho_ruby_enum_strary(ar_sources, source_iter, &arSources);

    CSyncThread::getInstance()->addQueueCommand(new CSyncThread::CSyncSearchCommand(from,params,arSources,sync_changes,nProgressStep) );

    return CSyncThread::getInstance()->getRetValue();
}	
#endif //RHO_NO_RUBY

extern "C"
{
unsigned long rho_sync_doSearchByNames(unsigned long ar_sources, const char *from, const char *params, bool sync_changes, int nProgressStep, 
    /*RHOC_CALLBACK*/void* callback, void* callback_data)
{
    rho_sync_stop();
    if ( callback )
        CSyncThread::getSyncEngine().getNotify().setSearchNotification( new CSyncNotification( (RHOC_CALLBACK)callback, callback_data, true ) );

    rho::Vector<rho::String>& arSources = *((rho::Vector<rho::String>*)ar_sources);

    CSyncThread::getInstance()->addQueueCommand(new CSyncThread::CSyncSearchCommand(from,params,arSources,sync_changes,nProgressStep) );

    return CSyncThread::getInstance()->getRetValue();
}	

int rho_sync_set_pollinterval(int nInterval)
{
    int nOldInterval = CSyncThread::getInstance()->getPollInterval();
    CSyncThread::getInstance()->setPollInterval(nInterval);

    return nOldInterval;
}

int rho_sync_get_pollinterval()
{
    return CSyncThread::getInstance()->getPollInterval();
}

void rho_sync_set_syncserver(const char* syncserver)
{
    rho_sync_stop();

	CSyncThread::getSyncEngine().setSyncServer(syncserver);

    if ( syncserver && *syncserver )
    {
        CSyncThread::getInstance()->start(CSyncThread::epLow);
        //CClientRegister::Create();
    }
    else
    {
        CSyncThread::getInstance()->stop(CSyncThread::SYNC_WAIT_BEFOREKILL_SECONDS);
        CClientRegister::Stop();
    }
}
}

unsigned long rho_sync_login(const char *name, const char *password, const rho::apiGenerator::CMethodResult& oResult)
{
    rho_sync_stop();
    CSyncThread::getInstance()->addQueueCommand(new CSyncThread::CSyncLoginCommand(name, password, 
		new CSyncNotification(oResult, false) ) );

    return CSyncThread::getInstance()->getRetValue();
}

extern "C"
{
unsigned long rho_sync_login_c(const char *name, const char *password, /*RHOC_CALLBACK*/void* callback, void* callback_data)
{
    rho_sync_stop();
    CSyncThread::getInstance()->addQueueCommand(new CSyncThread::CSyncLoginCommand(name, password, 
		new CSyncNotification((RHOC_CALLBACK)callback,callback_data,false)) );

    return CSyncThread::getInstance()->getRetValue();
}

int rho_sync_logged_in()
{
	//CDBAdapter& db = CDBAdapter::getUserDB();
    return CSyncThread::getSyncEngine().isLoggedIn() ? 1 : 0;
}

void rho_sync_logout()
{
	LOG(INFO) + "Logout";

    rho_sync_stop();

	//CDBAdapter& db = CDBAdapter::getUserDB();
	LOG(INFO) + "stopSyncByUser";
    CSyncThread::getSyncEngine().logout_int();
}
}

void rho_sync_set_notification(int source_id, const rho::apiGenerator::CMethodResult& oResult)
{
    CSyncThread::getSyncEngine().getNotify().setSyncNotification(source_id, new CSyncNotification(oResult, source_id != -1) );
}

extern "C"
{
void rho_sync_set_notification_c(int source_id, /*RHOC_CALLBACK*/void* callback, void* callback_data)
{
    CSyncThread::getSyncEngine().getNotify().setSyncNotification(source_id, new CSyncNotification((RHOC_CALLBACK)callback, callback_data, source_id != -1) );
}

void rho_sync_clear_notification(int source_id)
{
    CSyncThread::getSyncEngine().getNotify().clearSyncNotification(source_id);
}

#ifndef RHO_NO_RUBY
unsigned long rho_sync_get_attrs(const char* szPartition, int nSrcID)
{
    return 0;//(VALUE)CDBAdapter::getDB(szPartition).getAttrMgr().getAttrsBySrc(nSrcID);
}

#endif //RHO_NO_RUBY

void rho_sync_setobjectnotify_url(const char* szUrl)
{
    // commented out because it will cause a crash: constructor parameter should be a MethodResult, not char*
    //CSyncNotify::setObjectNotification(new CObjectNotification(szUrl));
}

void rho_sync_setobjectnotify_url_c(/*RHOC_CALLBACK*/void* callback, void* callback_data)
{
    CSyncNotify::setObjectNotification( new CObjectNotification((RHOC_CALLBACK)callback, callback_data));
}

void rho_sync_clear_object_notification()
{
    CSyncNotify::setObjectNotification(0);   
}
    
void rho_sync_addobjectnotify(int nSrcID, const char* szObject)
{
    CSyncThread::getSyncEngine().getNotify().addObjectNotify(nSrcID, szObject);
}

void rho_sync_addobjectnotify_bysrcname(const char* szSrcName, const char* szObject)
{
    CSyncThread::getSyncEngine().getNotify().addObjectNotify(szSrcName, szObject);
}

void rho_sync_cleanobjectnotify()
{
    CSyncThread::getSyncEngine().getNotify().cleanObjectNotifications();
}

int rho_sync_get_lastsync_objectcount(int nSrcID)
{
    return CSyncThread::getSyncEngine().getNotify().getLastSyncObjectCount(nSrcID);
}

int rho_sync_get_pagesize()
{
    return CSyncThread::getSyncEngine().getSyncPageSize();
}

void rho_sync_set_pagesize(int nPageSize)
{
    CSyncThread::getSyncEngine().setSyncPageSize(nPageSize);
}

void rho_sync_set_threaded_mode(int b)
{
    if(!CSyncThread::getInstance())
    {
        RAWLOG_ERROR("No SyncThread instance!");
    }
    
    CSyncThread::getInstance()->setNonThreadedMode(b==0);
    CSyncThread::getSyncEngine().setNonThreadedMode(b==0);
}

char* rho_sync_create_string(const char* szStr)
{
    return strdup(szStr);
}

void rho_sync_free_string(char* szStr)
{
    if (NULL != szStr)
        free(szStr);
}

void rho_sync_enable_status_popup(int b)
{
    CSyncThread::getSyncEngine().getNotify().enableStatusPopup(b == 0 ? false : true);
}

void rho_sync_set_source_property(int nSrcID, const char* szPropName, const char* szPropValue)
{
    CSyncEngine::getSourceOptions().setProperty(nSrcID, szPropName, szPropValue);
}

#ifndef RHO_NO_RUBY
unsigned long rho_sync_get_source_property(int nSrcID, const char* szPropName)
{
    return rho_ruby_create_string( CSyncEngine::getSourceOptions().getProperty(nSrcID, szPropName).c_str() );
}
#endif //RHO_NO_RUBY

void rho_sync_set_ssl_verify_peer(int b)
{
    CSyncThread::getSyncEngine().setSslVerifyPeer(b == 0 ? false : true);
}


void rho_sync_register_push()
{
    RAWLOG_WARNING("'register_push' is not implemented!");
}

}
