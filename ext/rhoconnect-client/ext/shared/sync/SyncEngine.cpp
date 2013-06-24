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
*------------------------------------------------------------------------*/

#include "SyncEngine.h"
#include "SyncSource.h"
#include "SyncThread.h"

#include "json/JSONIterator.h"
#include "common/RhoConf.h"
#include "common/StringConverter.h"
#include "sync/ClientRegister.h"
#include "net/URI.h"
#include "statistic/RhoProfiler.h"
#include "common/RhoTime.h"
#include "common/RhoFilePath.h"
#include "common/RhoFile.h"
#include "common/RhoAppAdapter.h"
#include "SyncProtocol_4.h"
#include "SyncProtocol_3.h"
#include "common/RhoSettingsDefs.h"
#include "common/Tokenizer.h"

#ifdef _MSC_VER
// Disable warnings about using "this" in member initializater list
#pragma warning(disable: 4355)
#endif

namespace rho {
namespace sync {
IMPLEMENT_LOGCLASS(CSyncEngine,"Sync");

using namespace rho::net;
using namespace rho::common;
using namespace rho::json;
CSyncEngine::CSourceOptions CSyncEngine::m_oSourceOptions;

CSyncEngine::CSyncEngine(): m_syncState(esNone), m_oSyncNotify(*this)
{
    m_bNoThreaded = false;
    m_bStopByUser = false;
    m_nSyncPageSize = 2000;

    initProtocol();
}

void CSyncEngine::initProtocol()
{
    int protocolVersion = RHOCONF().getInt("rc_protocol_version");
    switch(protocolVersion) {
    case 3:
        m_SyncProtocol = new CSyncProtocol_3();
        break;
    default:
        // unknown version - use V4
        LOG(ERROR) + "Unknown Sync Protocol Version has been requested: "  +  convertToStringA(protocolVersion) + ", using Version 4 instead.";
        // no break here - intentionally - to proceed with version 4
    case 0: // 0 - means default
    case 4:
        m_SyncProtocol = new CSyncProtocol_4();
        break;
    }
}

void CSyncEngine::setSslVerifyPeer(boolean b)
{ 
    m_NetRequest.setSslVerifyPeer(b); 
    m_NetRequestClientID.setSslVerifyPeer(b); 

    CClientRegister::SetSslVerifyPeer(b);
}
    
bool CSyncEngine::getSslVerifyPeer()
{
    return m_NetRequest.getSslVerifyPeer() && m_NetRequestClientID.getSslVerifyPeer() && CClientRegister::GetSslVerifyPeer();
}

void CSyncEngine::CSourceOptions::setProperty(int nSrcID, const char* szPropName, const char* szPropValue)
{
    synchronized(m_mxSrcOptions)
    {
        Hashtable<String,String>* phashOptions = m_hashSrcOptions.get(nSrcID);
        if ( phashOptions == null )
        {
            phashOptions = new Hashtable<String,String>();
            m_hashSrcOptions.put( nSrcID, phashOptions );
        }

        Hashtable<String,String>& hashOptions = *phashOptions;
        hashOptions.put(szPropName,szPropValue!=null?szPropValue:"");
    }
}

String CSyncEngine::CSourceOptions::getProperty(int nSrcID, const char* szPropName)
{
    String res = "";
    synchronized(m_mxSrcOptions)
    {
        Hashtable<String,String>* phashOptions = m_hashSrcOptions.get(nSrcID);
        if ( phashOptions != null )
        {
            Hashtable<String,String>& hashOptions = *phashOptions;
            res = hashOptions.get(szPropName);
        }
    }

    return res;
}

boolean CSyncEngine::CSourceOptions::getBoolProperty(int nSrcID, const char* szPropName)
{
    String strValue = getProperty(nSrcID, szPropName);

    return strValue.compare("1") == 0 || strValue.compare("true") == 0 ? true : false;
}

int CSyncEngine::CSourceOptions::getIntProperty(int nSrcID, const char* szPropName)
{
    String strValue = getProperty(nSrcID, szPropName);

    return strValue.length() ? atoi(strValue.c_str()) : 0;
}
	
void CSyncEngine::CSourceOptions::clearProperties()
{
	synchronized(m_mxSrcOptions)
	{
		m_hashSrcOptions.clear();
	}
}
	
void CSyncEngine::prepareSync(ESyncState eState, const CSourceID* oSrcID)
{
    setState(eState);
    m_bIsSearch =  eState == esSearch;
    m_bStopByUser = false;
    m_nErrCode = RhoAppAdapter.ERR_NONE;
    m_strError = "";
    m_bIsSchemaChanged = false;

    loadAllSources();

    m_strSession = loadSession();
    if ( isSessionExist()  )
    {
        m_clientID = loadClientID();
        if ( m_nErrCode == RhoAppAdapter.ERR_NONE )
        {
            getNotify().cleanLastSyncObjectCount();
   	        doBulkSync();

            return;
        }
    }else
        m_nErrCode = RhoAppAdapter.ERR_CLIENTISNOTLOGGEDIN;

    CSyncSource* src = null;
    if ( oSrcID != null )
    	src = findSource(*oSrcID);
    
	if ( src != null )
	{
        src->m_nErrCode = m_nErrCode;
        src->m_strError = m_strError;
        getNotify().fireSyncNotification(src, true, src->m_nErrCode, "");
    }else
    {
        getNotify().fireAllSyncNotifications(true, m_nErrCode, m_strError/*, ""*/ );
    }

    stopSync();
}

void CSyncEngine::doSyncAllSources(const String& strQueryParams, boolean bSyncOnlyChangedSources)
{
    prepareSync(esSyncAllSources, null);

    if ( isContinueSync() )
    {
	    PROF_CREATE_COUNTER("Net");	    
	    PROF_CREATE_COUNTER("Parse");
	    PROF_CREATE_COUNTER("DB");
	    PROF_CREATE_COUNTER("Data");
	    PROF_CREATE_COUNTER("Data1");
	    PROF_CREATE_COUNTER("Pull");
	    PROF_START("Sync");

        syncAllSources(strQueryParams, bSyncOnlyChangedSources);

	    PROF_DESTROY_COUNTER("Net");	    
	    PROF_DESTROY_COUNTER("Parse");
	    PROF_DESTROY_COUNTER("DB");
	    PROF_DESTROY_COUNTER("Data");
	    PROF_DESTROY_COUNTER("Data1");
	    PROF_DESTROY_COUNTER("Pull");
	    PROF_STOP("Sync");

    }

    getNotify().cleanCreateObjectErrors();

    if ( getState() != esExit )
        setState(esNone);
}

bool CSyncEngine::recoverSearch(const String& strUrl, const String& strBody, int& errorCode, String& strError, int nProgressStep ) {
    
    LOG(INFO) + "Call search on server for previous request. Url: " + (strUrl);

    Hashtable<String, String> reqHeaders;
    reqHeaders.put(getProtocol().getClientIDHeader(), getClientID());
    
    NetResponse resp = getNet().doRequest(getProtocol().getServerSearchMethod(), 
                strUrl, strBody, this, &reqHeaders);

    if ( !resp.isOK() )
    {
        errorCode = RhoAppAdapter.getErrorFromResponse(resp);
        strError = resp.getCharData();
        return false;
    }
    
    const char* szData = resp.getCharData();
    
    CJSONArrayIterator oJsonArr(szData);
    
    for( ; !oJsonArr.isEnd() ; oJsonArr.next() )
    {
        CJSONArrayIterator oSrcArr(oJsonArr.getCurItem());
        if (oSrcArr.isEnd())
            break;
        
        int nVersion = 0;
        if ( !oSrcArr.isEnd() && oSrcArr.getCurItem().hasName("version") )
        {
            nVersion = oSrcArr.getCurItem().getInt("version");
            oSrcArr.next();
        }
        
        if ( nVersion != getProtocol().getVersion() )
        {
            LOG(ERROR) + "Sync server send search data with incompatible version. Client version: " + convertToStringA(getProtocol().getVersion()) +
            "; Server response version: " + convertToStringA(nVersion);
            errorCode = RhoAppAdapter.ERR_SYNCVERSION;
            return false;
        }
        
        if ( !oSrcArr.isEnd() && oSrcArr.getCurItem().hasName("token"))
        {
            oSrcArr.next();
        }
        
        if ( !oSrcArr.getCurItem().hasName("source") )
        {
            LOG(ERROR) + "Sync server send search data without source name.";
            errorCode = RhoAppAdapter.ERR_UNEXPECTEDSERVERRESPONSE;
            strError = szData;
            return false;
        }
        
        String strSrcName = oSrcArr.getCurItem().getString("source");
        CSyncSource* pSrc = findSourceByName(strSrcName);
        if ( pSrc == null )
        {
            LOG(ERROR) + "Sync server send search data for unknown source name:" + strSrcName;
            errorCode = RhoAppAdapter.ERR_UNEXPECTEDSERVERRESPONSE;
            strError = szData;
            return false;
        }
        
        oSrcArr.reset(0);
        pSrc->setProgressStep(nProgressStep);
        
        pSrc->processServerResponse_ver3(oSrcArr,true);
    }
            
    return true;
}

void CSyncEngine::doSearch(rho::Vector<rho::String>& arSources, String strParams, const String& strFrom, boolean bSearchSyncChanges, int nProgressStep)
{
    prepareSync(esSearch, null);
    if ( !isContinueSync() )
    {
        if ( getState() != esExit )
            setState(esNone);

        return;
    }

    CTimeInterval startTime = CTimeInterval::getCurrentTime();

    if ( bSearchSyncChanges )
    {
        for ( int i = 0; i < (int)arSources.size(); i++ )
        {
            CSyncSource* pSrc = findSourceByName(arSources.elementAt(i));
            if ( pSrc != null )
                pSrc->syncClientChanges();
        }
    }

    while( isContinueSync() )
    {
        int nSearchCount = 0;

        /* Recover state if previous search request wasn't successful. */
        if ( (RHOCONF().isExist("search_request")) && (RHOCONF().getString("search_request").length()>0) ) {
            String strError = "";
            int errorCode = 0;
            if (!recoverSearch(RHOCONF().getString("search_request_url"),RHOCONF().getString("search_request_body"), errorCode,strError,nProgressStep)) {
                stopSync();
                m_nErrCode = errorCode;
                m_strError = strError;
                continue;
            }
            
            RHOCONF().setString("search_request_url", "", true);
            RHOCONF().setString("search_request_body", "", true);            
        }
        
        
        String strSearchParams;
        if ( strParams.length() > 0 )
            strSearchParams += strParams.at(0) == '&' ? strParams : "&" + strParams;

        String strTestResp = "";
        Hashtable<String, String> source_tokens;
        Hashtable<String, String> recover_tokens;
        for ( int i = 0; i < (int)arSources.size(); i++ )
        {
            CSyncSource* pSrc = findSourceByName(arSources.elementAt(i));
            if ( pSrc != null )
            {
                String source_token;
                if ( !pSrc->isTokenFromDB() && pSrc->getToken() > 1 )
                    source_token = convertToStringA(pSrc->getToken());
                
                source_tokens.put(pSrc->getName(), source_token);
                recover_tokens.put(pSrc->getName(), "resend_token");

                strTestResp = getSourceOptions().getProperty(pSrc->getID(), "rho_server_response");
            }
        }
        String strUrl = getProtocol().getServerSearchUrl(getClientID(), getSyncPageSize(), strFrom, arSources, source_tokens) + strSearchParams;
        String strRecoverUrl = getProtocol().getServerSearchUrl(getClientID(), getSyncPageSize(), strFrom, arSources, recover_tokens) + strSearchParams;
        // for recover URL - set 'resend ' parameter
        strRecoverUrl += "&resend=1";
        Hashtable<String, String> reqHeaders;
        reqHeaders.put(getProtocol().getClientIDHeader(), getClientID());
        String strBody = getProtocol().getServerSearchBody(getSyncPageSize(), arSources, source_tokens);
        String strRecoverBody = getProtocol().getServerSearchBody(getSyncPageSize(), arSources, recover_tokens);

	    LOG(INFO) + "Call search on server. Url: " + (strUrl);
        // for recover URL - set 'resend ' parameter and store for recovery
        strRecoverUrl += "&resend=1";
        RHOCONF().setString("search_request_url", strRecoverUrl, true);
        RHOCONF().setString("search_request_body", strRecoverBody, true);

        NetResponse resp = getNet().doRequest(getProtocol().getServerSearchMethod(), 
                strUrl, strBody, this, &reqHeaders);

        // when request is completed - reset the recovery
        RHOCONF().setString("search_request_url", "", true);
        RHOCONF().setString("search_request_body", "", true);

        if ( !resp.isOK() )
        {
            stopSync();
            m_nErrCode = RhoAppAdapter.getErrorFromResponse(resp);
            m_strError = resp.getCharData();
            continue;
        }

        const char* szData = null;
        if ( strTestResp.length() > 0 )
        {
            szData = strTestResp.c_str();
            getNotify().setFakeServerResponse(true);
        }
        else
            szData = resp.getCharData();

        //LOG(INFO) + szData;
        CJSONArrayIterator oJsonArr(szData);

        for( ; !oJsonArr.isEnd() && isContinueSync(); oJsonArr.next() )
        {
            CJSONArrayIterator oSrcArr(oJsonArr.getCurItem());
            if (oSrcArr.isEnd())
                break;

            int nVersion = 0;
            if ( !oSrcArr.isEnd() && oSrcArr.getCurItem().hasName("version") )
            {
                nVersion = oSrcArr.getCurItem().getInt("version");
                oSrcArr.next();
            }

            if ( nVersion != getProtocol().getVersion() )
            {
                LOG(ERROR) + "Sync server send search data with incompatible version. Client version: " + convertToStringA(getProtocol().getVersion()) +
                    "; Server response version: " + convertToStringA(nVersion);
                stopSync();
                m_nErrCode = RhoAppAdapter.ERR_SYNCVERSION;
                continue;
            }

            if ( !oSrcArr.isEnd() && oSrcArr.getCurItem().hasName("token"))
            {
                oSrcArr.next();
            }

            if ( !oSrcArr.getCurItem().hasName("source") )
            {
                LOG(ERROR) + "Sync server send search data without source name.";
                stopSync();
                m_nErrCode = RhoAppAdapter.ERR_UNEXPECTEDSERVERRESPONSE;
                m_strError = szData;
                continue;
            }

            String strSrcName = oSrcArr.getCurItem().getString("source");
            CSyncSource* pSrc = findSourceByName(strSrcName);
            if ( pSrc == null )
            {
                LOG(ERROR) + "Sync server send search data for unknown source name:" + strSrcName;
                stopSync();
                m_nErrCode = RhoAppAdapter.ERR_UNEXPECTEDSERVERRESPONSE;
                m_strError = szData;
                continue;
            }

            oSrcArr.reset(0);
            pSrc->setProgressStep(nProgressStep);
            pSrc->processServerResponse_ver3(oSrcArr);

            nSearchCount += pSrc->getCurPageCount();
        }

        if ( nSearchCount == 0 )
        {
            for ( int i = 0; i < (int)arSources.size(); i++ )
            {
                CSyncSource* pSrc = findSourceByName(arSources.elementAt(i));
                if ( pSrc != null )
                    pSrc->processToken(0);
            }

            break;
        }

        if ( strTestResp.length() > 0 )
            break;
    }  

    getNotify().fireAllSyncNotifications(true, m_nErrCode, m_strError);

    //update db info
    CTimeInterval endTime = CTimeInterval::getCurrentTime();
    unsigned long timeUpdated = CLocalTime().toULong();
    for ( int i = 0; i < (int)arSources.size(); i++ )
    {
        CSyncSource* pSrc = findSourceByName(arSources.elementAt(i));
        if ( pSrc == null )
            continue;
        CSyncSource& oSrc = *pSrc;
        oSrc.getDB().executeSQL("UPDATE sources set last_updated=?,last_inserted_size=?,last_deleted_size=?, \
						 last_sync_duration=?,last_sync_success=?, backend_refresh_time=? WHERE source_id=?", 
                         timeUpdated, oSrc.getInsertedCount(), oSrc.getDeletedCount(), 
                         (endTime-startTime).toULong(), oSrc.m_nErrCode == RhoAppAdapter.ERR_NONE, oSrc.getRefreshTime(),
                         oSrc.getID() );
    }
    //

    getNotify().cleanCreateObjectErrors();
    if ( getState() != esExit )
        setState(esNone);
}

void CSyncEngine::doSyncSource(const CSourceID& oSrcID, const String& strQueryParams)
{
    prepareSync(esSyncSource, &oSrcID);

    if ( isContinueSync() )
    {
        CSyncSource* pSrc = findSource(oSrcID);
        if ( pSrc != null )
        {
            CSyncSource& src = *pSrc;
            LOG(INFO) +"Started synchronization of the data source: " + src.getName();
            src.m_strQueryParams = strQueryParams;
            src.sync();

            getNotify().fireSyncNotification(&src, true, src.m_nErrCode, src.m_nErrCode == RhoAppAdapter.ERR_NONE ? RhoAppAdapter.getMessageText("sync_completed") : "");
        }else
        {
            LOG(ERROR) + "Sync one source : Unknown Source " + oSrcID.toString();

            CSyncSource src(*this, getUserDB() );
    	    //src.m_strError = "Unknown sync source.";
            src.m_nErrCode = RhoAppAdapter.ERR_RUNTIME;

            getNotify().fireSyncNotification(&src, true, src.m_nErrCode, "");
        }
    }

    getNotify().cleanCreateObjectErrors();

    if ( getState() != esExit )
        setState(esNone);
}

CSyncSource* CSyncEngine::findSource(const CSourceID& oSrcID)
{
    for( int i = 0; i < (int)m_sources.size(); i++ )
    {
        CSyncSource& src = *m_sources.elementAt(i);
        if ( oSrcID.isEqual(src) )
            return &src;
    }
    
    return null;
}

CSyncSource* CSyncEngine::findSourceByName(const String& strSrcName)
{
    return findSource(CSourceID(strSrcName));
}
	
CSyncSource* CSyncEngine::findSourceById(int srcId)
{
	for( int i = 0; i < (int)m_sources.size(); i++ )
    {
        CSyncSource& src = *m_sources.elementAt(i);
        if ( src.getID() == srcId )
            return &src;
    }
    
    return null;
}


void CSyncEngine::applyChangedValues(db::CDBAdapter& db)
{
    IDBResult resSrc = db.executeSQL( "SELECT DISTINCT(source_id) FROM changed_values" );
    for ( ; !resSrc.isEnd(); resSrc.next() )
    {
        int nSrcID = resSrc.getIntByIdx(0);
        IDBResult res = db.executeSQL("SELECT source_id,sync_type,name, partition from sources WHERE source_id=?", nSrcID);
        if ( res.isEnd() )
            continue;

        CSyncSource src( res.getIntByIdx(0), res.getStringByIdx(2), "none", db, *this );

        src.applyChangedValues();
    }
}

void CSyncEngine::loadAllSources()
{
    if (rho_ruby_is_started())
    {
        if (isNoThreadedMode())
            RhoAppAdapter.loadAllSyncSources();
        else
        {
            NetResponse resp = getNet().pushData( getNet().resolveUrl("/system/loadallsyncsources"), "", null );
        }
    }else
        RhoAppAdapter.loadAllSyncSources();

    m_sources.removeAllElements();

    Vector<String> arPartNames = db::CDBAdapter::getDBAllPartitionNames();

    for( int i = 0; i < (int)arPartNames.size(); i++ )
    {
        db::CDBAdapter& dbPart = db::CDBAdapter::getDB(arPartNames.elementAt(i).c_str());
        IDBResult  res = dbPart.executeSQL("SELECT source_id,sync_type,name from sources ORDER BY sync_priority");
        for ( ; !res.isEnd(); res.next() )
        { 
            String strShouldSync = res.getStringByIdx(1);
            if ( strShouldSync.compare("none") == 0 )
                continue;

            String strName = res.getStringByIdx(2);

            m_sources.addElement( new CSyncSource( res.getIntByIdx(0), strName, strShouldSync, dbPart, *this) );
        }
    }

    checkSourceAssociations();
}

static int findSrcIndex( VectorPtr<CSyncSource*>& sources, const String& strSrcName)
{
    for ( int i = 0; i < (int)sources.size(); i++)
    {
        if (strSrcName.compare(sources.elementAt(i)->getName()) == 0 )
            return i;
    }

    return -1;
}

void CSyncEngine::checkSourceAssociations()
{
    Hashtable<String, int> hashPassed;
    
    for( int nCurSrc = m_sources.size()-1; nCurSrc >= 0 ; )
    {
        CSyncSource& oCurSrc = *(m_sources.elementAt(nCurSrc));
        if ( oCurSrc.getAssociations().size() == 0 || hashPassed.containsKey(oCurSrc.getName()) )
            nCurSrc--;
        else
        {
            int nSrc = nCurSrc;
            for( int i = 0; i < (int)oCurSrc.getAssociations().size(); i++ )
            {
                const CSyncSource::CAssociation& oAssoc = oCurSrc.getAssociations().elementAt(i);
                int nAssocSrcIndex = findSrcIndex( m_sources, oAssoc.m_strSrcName);
                if ( nAssocSrcIndex >= 0 )
                    m_sources.elementAt(nAssocSrcIndex)->addBelongsTo( oAssoc.m_strAttrib, oCurSrc.getID() );

                if ( nAssocSrcIndex >=0 && nAssocSrcIndex < nSrc )
                {
                    m_sources.removeElementAt( nSrc, false );
                    m_sources.insertElementAt( &oCurSrc, nAssocSrcIndex );

                    nSrc = nAssocSrcIndex;
                }
            }
        }

        hashPassed.put(oCurSrc.getName(), 1);
    }
}

String CSyncEngine::readClientID()
{
    String clientID = "";
    synchronized(m_mxLoadClientID)
    {
        IDBResult res = getUserDB().executeSQL("SELECT client_id,reset from client_info limit 1");
        if ( !res.isEnd() )
            clientID = res.getStringByIdx(0);
    }

    return clientID;
}

String CSyncEngine::loadClientID()
{
    String clientID = "";
    synchronized(m_mxLoadClientID)
    {
        boolean bResetClient = false;
        {
            IDBResult res = getUserDB().executeSQL("SELECT client_id,reset from client_info limit 1");
            if ( !res.isEnd() )
            {
                clientID = res.getStringByIdx(0);
                bResetClient = res.getIntByIdx(1) > 0;
            }
        }

        if ( clientID.length() == 0 )
        {
            clientID = requestClientIDByNet();

            IDBResult res = getUserDB().executeSQL("SELECT * FROM client_info");
            if ( !res.isEnd() )
                getUserDB().executeSQL("UPDATE client_info SET client_id=?", clientID);
            else
                getUserDB().executeSQL("INSERT INTO client_info (client_id) values (?)", clientID);

        }else if ( bResetClient )
        {
    	    if ( !resetClientIDByNet(clientID) )
    		    stopSync();
    	    else
    		    getUserDB().executeSQL("UPDATE client_info SET reset=? where client_id=?", 0, clientID );	    	
        }
    }

    return clientID;
}

void CSyncEngine::processServerSources(String strSources)
{
    if ( strSources.length() > 0 )
    {
        if (rho_ruby_is_started())
        {
            if (isNoThreadedMode())
                RhoAppAdapter.loadServerSources(strSources);
            else
            {
                NetResponse resp = getNet().pushData( getNet().resolveUrl("/system/loadserversources"), strSources, null );
            }
        }else
            RhoAppAdapter.loadServerSources(strSources);

        loadAllSources();

        rho_db_init_attr_manager();
    }
}

boolean CSyncEngine::resetClientIDByNet(const String& strClientID)//throws Exception
{
    NetResponse resp = getNetClientID().doRequest(getProtocol().getClientResetMethod(),
        getProtocol().getClientResetUrl(strClientID), getProtocol().getClientResetBody(), this, null );
    if ( !resp.isOK() )
    {
        m_nErrCode = RhoAppAdapter.getErrorFromResponse(resp);
        m_strError = resp.getCharData();
    }else
        RHOCONF().setString("reset_models", "", true);

    return resp.isOK();
}

String CSyncEngine::requestClientIDByNet()
{
    String clientCreateBody;
    NetResponse resp = getNetClientID().doRequest(getProtocol().getClientCreateMethod(),
        getProtocol().getClientCreateUrl(), "", this, null);
    if ( resp.isOK() && resp.getCharData() != null )
    {
        const char* szData = resp.getCharData();

        CJSONEntry oJsonEntry(szData);

        CJSONEntry oJsonObject = oJsonEntry.getEntry("client");
        if ( !oJsonObject.isEmpty() )
            return oJsonObject.getString("client_id");
    }else
    {
        m_nErrCode = RhoAppAdapter.getErrorFromResponse(resp);
        m_strError = resp.getCharData();

        if ( m_nErrCode == RhoAppAdapter.ERR_NONE )
            m_nErrCode = RhoAppAdapter.ERR_UNEXPECTEDSERVERRESPONSE;
    }

    return "";
}

void CSyncEngine::doBulkSync()//throws Exception
{
//    processServerSources(String("{\"partition\":\"") + "application" + "\"}");

    if ( !RHOCONF().isExist(RHO_SETTING_BULKSYNC_STATE) )
        return;

    int nBulkSyncState = RHOCONF().getInt(RHO_SETTING_BULKSYNC_STATE);
	if ( !isContinueSync() ) {
		return;
	}
	
	switch (nBulkSyncState) {
		case ebsNotSynced:
			loadBulkPartitions();
			
			if ( !isContinueSync() ) {
				return;
			}
			
			//no break here is intentional.
		case ebsLoadBlobs:
			if ( !processBlobs() ) {
				return;
			}
			break;
			
		default:
			return;
	}

    if (isContinueSync())
    {
        RHOCONF().setInt(RHO_SETTING_BULKSYNC_STATE, ebsSynced, true);
        getNotify().fireBulkSyncNotification(true, "complete", "", RhoAppAdapter.ERR_NONE);
    }
}
	
void CSyncEngine::loadBulkPartitions() {
	LOG(INFO) + "Bulk sync: start";
	getNotify().fireBulkSyncNotification(false, "start", "", RhoAppAdapter.ERR_NONE);        
	Vector<String> arPartNames = db::CDBAdapter::getDBAllPartitionNames();
	
	for (int i = 0; i < (int)arPartNames.size() && isContinueSync(); i++)
	{
		if ( arPartNames.elementAt(i).compare("local") !=0 )
			loadBulkPartition(arPartNames.elementAt(i));
	}
}

boolean CSyncEngine::processBlobs() {
	LOG(INFO) + "Bulk sync: download BLOBs";
	
	RHOCONF().setInt(RHO_SETTING_BULKSYNC_STATE, ebsLoadBlobs, true );
	getNotify().fireBulkSyncNotification( false, "blobs", "", RhoAppAdapter.ERR_NONE);
	
	LOG(TRACE) + "=== Processing server blob attributes ===";
	
	for ( int i = 0; i < (int)m_sources.size(); ++i ) {
		CSyncSource& src = *m_sources.elementAt(i);
		if ( !src.processServerBlobAttrs() ) {
			getNotify().fireBulkSyncNotification(false, "error", "", RhoAppAdapter.ERR_UNEXPECTEDSERVERRESPONSE);
			return false;
		}
	}
	
	LOG(TRACE) + "=== Processing server blob attributes DONE ===";
	
	rho_db_init_attr_manager();
	
	for ( int i = 0; i < (int)m_sources.size(); ++i ) {
		CSyncSource& src = *m_sources.elementAt(i);
		if (!src.processAllBlobs()) {
			getNotify().fireBulkSyncNotification(false, "error", "", RhoAppAdapter.ERR_UNEXPECTEDSERVERRESPONSE);
			return false;
		}
	}
	
	return true;
}
	
	
extern "C" int rho_sys_unzip_file(const char* szZipPath, const char* psw);

static String getHostFromUrl( const String& strUrl );
void CSyncEngine::loadBulkPartition(const String& strPartition )
{
    db::CDBAdapter& dbPartition = getDB(strPartition); 
 
    Vector<String> source_names;
    for ( int i = 0; i < (int)m_sources.size(); ++i ) {
        source_names.push_back(m_sources[i]->getName());
    }

    String serverUrl = RHOCONF().getPath("syncserver");
    String strUrl = getProtocol().getServerBulkDataUrl(getClientID(), strPartition, source_names);
    String strBody = getProtocol().getServerBulkDataBody(strPartition, source_names);   
    String strDataUrl = "", strCmd = "", strCryptKey = "";

  	getNotify().fireBulkSyncNotification(false, "start", strPartition, RhoAppAdapter.ERR_NONE);

    while(strCmd.length() == 0&&isContinueSync())
    {	   
        Hashtable<String, String> reqHeaders;
        reqHeaders.put(getProtocol().getClientIDHeader(), getClientID()); 
        NetResponse resp = getNet().doRequest(getProtocol().getServerBulkDataMethod(), strUrl, strBody, this, &reqHeaders);
        const char* szData = resp.getCharData();
        if ( !resp.isOK() || szData == null || *szData == 0)
        {
    	    LOG(ERROR) + "Bulk sync failed: server return an error.";
    	    stopSync();
    	    getNotify().fireBulkSyncNotification(true, "", strPartition, RhoAppAdapter.getErrorFromResponse(resp));
    	    return;
        }

	    LOG(INFO) + "Bulk sync: got response from server: " + szData;
    	
        CJSONEntry oJsonEntry(szData);
        strCmd = oJsonEntry.getString("result");
        if ( oJsonEntry.hasName("url") )
   	        strDataUrl = oJsonEntry.getString("url");
        
        if ( strCmd.compare("wait") == 0)
        {
            int nTimeout = RHOCONF().getInt("bulksync_timeout_sec");
            if ( nTimeout == 0 )
                nTimeout = 5;

            CSyncThread::getInstance()->wait(nTimeout*1000);
            strCmd = "";
        }
    }

    if ( strCmd.compare("nop") == 0)
    {
	    LOG(INFO) + "Bulk sync return no data.";
      	getNotify().fireBulkSyncNotification(true, "ok", strPartition, RhoAppAdapter.ERR_NONE);

	    return;
    }

    if ( !isContinueSync() )
        return;

   	getNotify().fireBulkSyncNotification(false, "download", strPartition, RhoAppAdapter.ERR_NONE);

    String fDataName = makeBulkDataFileName(strDataUrl, dbPartition.getDBPath(), "");
    String strZip = ".rzip";
    String strSqlDataUrl = CFilePath::join(getHostFromUrl(serverUrl), strDataUrl) +strZip;
    LOG(INFO) + "Bulk sync: download data from server: " + strSqlDataUrl;
    {
        NetResponse resp1 = getNet().pullFile(strSqlDataUrl, fDataName+strZip, this, null, true, false);
        if ( !resp1.isOK() )
        {
	        LOG(ERROR) + "Bulk sync failed: cannot download database file.";
	        stopSync();
	        getNotify().fireBulkSyncNotification(true, "", strPartition, RhoAppAdapter.getErrorFromResponse(resp1));
	        return;
        }
    }

    if ( !isContinueSync() )
        return;

    LOG(INFO) + "Bulk sync: unzip db";

    if ( !rho_sys_unzip_file((fDataName+strZip).c_str(), ""), 0 )
    {
        CRhoFile::deleteFile((fDataName+strZip).c_str());
        LOG(ERROR) + "Bulk sync failed: cannot unzip database file.";
        stopSync();
        getNotify().fireBulkSyncNotification(true, "", strPartition, RhoAppAdapter.ERR_UNEXPECTEDSERVERRESPONSE);
        return;
    }
    CRhoFile::deleteFile((fDataName+strZip).c_str());

	LOG(INFO) + "Bulk sync: start change db";
   	getNotify().fireBulkSyncNotification(false, "change_db", strPartition, RhoAppAdapter.ERR_NONE);
    
    dbPartition.setBulkSyncDB(fDataName, strCryptKey);
	getSourceOptions().clearProperties();
    processServerSources(String("{\"partition\":\"") + strPartition + "\"}");

	LOG(INFO) + "Bulk sync: end change db";
   	getNotify().fireBulkSyncNotification(false, "ok", strPartition, RhoAppAdapter.ERR_NONE);
}

String CSyncEngine::makeBulkDataFileName(String strDataUrl, String strDbPath, String strExt)
{
    CFilePath oUrlPath(strDataUrl);
	String strNewName = oUrlPath.getBaseName();
    
    String strOldName = RHOCONF().getString("bulksync_filename");

    if ( strOldName.length() > 0 && strNewName.compare(strOldName) != 0 )
    {
        CFilePath oFilePath(strDbPath);
        String strFToDelete = oFilePath.changeBaseName(strOldName+strExt);
        LOG(INFO) + "Bulk sync: remove old bulk file '" + strFToDelete + "'";

        CRhoFile::deleteFile( strFToDelete.c_str() );
    }

    RHOCONF().setString("bulksync_filename", strNewName, true);

    CFilePath oFilePath(strDbPath);
    return oFilePath.changeBaseName(strNewName+strExt);
}
/*
int CSyncEngine::getStartSource()
{
    for( int i = 0; i < (int)m_sources.size(); i++ )
    {
        CSyncSource& src = *m_sources.elementAt(i);
        if ( !src.isEmptyToken() )
            return i;
    }

    return -1;
}*/

void CSyncEngine::syncOneSource(int i, const String& strQueryParams, boolean syncOnlyIfChanged)
{
    CSyncSource& src = *m_sources.elementAt(i);
    if ( src.getSyncType().compare("bulk_sync_only")==0 )
        return;

    if ( isSessionExist() && getState() != esStop )
    {
        src.m_strQueryParams = strQueryParams;
		if (syncOnlyIfChanged) {
			if (src.haveChangedValues() ) {
				src.sync();
			}
		} else {
			src.sync();
		}
    }

    getNotify().onSyncSourceEnd(i, m_sources);

//    return src.m_nErrCode == RhoAppAdapter.ERR_NONE;
}

void CSyncEngine::syncAllSources(const String& strQueryParams, boolean bSyncOnlyChangedSources)
{
//    boolean bError = false;

//    int nStartSrc = getStartSource();
//    if ( nStartSrc >= 0 )
//        bError = !syncOneSource(nStartSrc);

    for( int i = 0; i < (int)m_sources.size() && isContinueSync(); i++ )
    {
        /*bError = !*/syncOneSource(i, strQueryParams, bSyncOnlyChangedSources);
    }

    if ( !isSchemaChanged() && getState() != CSyncEngine::esStop )
    	getNotify().fireSyncNotification(null, true, RhoAppAdapter.ERR_NONE, RhoAppAdapter.getMessageText("sync_completed"));
}

void CSyncEngine::login(String name, String password, const CSyncNotification& oNotify)
{
//    processServerSources("{\"sources\":{ \"Product\":{}, \"Customer\":{}}}");
/*
    processServerSources(
        "{\"sources\":{ \"ProductEx\":{ "
        "\"sync_type\":\"incremental\", \"partition\":\"application\", \"source_id\":\"7\","
        " \"sync_priority\":\"0\", \"model_type\":\"fixed_schema\", "
        " \"schema\":{\"version\":\"1.1\", \"property\":{\"brand\":\"string\", \"price\":\"string\", \"quantity\":\"string\", \"name\":\"string\", "
        " \"image_url\":\"blob\", \"image_url_ex\":\"blob,overwrite\"}, "
        " \"index\":[{\"by_brand_price1\":\"brand,price\"}, {\"by_quantity1\":\"quantity\"}], \"unique_index\":[{\"by_name1\":\"name\"}]}, "
        " \"belongs_to\":{\"brand\":\"Customer\"}}}}");//, \"schema_version\":\"1.0\"
*/
    PROF_START("Login");
    m_bStopByUser = false;
	//try {
    loadAllSources();

    NetResponse resp = getNet().pullCookies( getProtocol().getLoginUrl(), getProtocol().getLoginBody(name, password), this );
    int nErrCode = RhoAppAdapter.getErrorFromResponse(resp);
    if ( nErrCode != RhoAppAdapter.ERR_NONE )
    {
        getNotify().callLoginCallback(oNotify, nErrCode, resp.getCharData());
        return;
    }

    String strSession = resp.getCharData();
    if ( strSession.length() == 0 )
    {
    	LOG(ERROR) + "Return empty session.";
    	getNotify().callLoginCallback(oNotify, RhoAppAdapter.ERR_UNEXPECTEDSERVERRESPONSE, "" );
        return;
    }

   	if ( isStoppedByUser() )
	{
		LOG(INFO) + "Login was stopped by application.";
        return;
	}

	{
		IDBResult res = getUserDB().executeSQL("SELECT * FROM client_info");
		if ( !res.isEnd() )
			getUserDB().executeSQL( "UPDATE client_info SET session=?", strSession );
		else
			getUserDB().executeSQL("INSERT INTO client_info (session) values (?)", strSession);
	}
	
    if ( RHOCONF().isExist("rho_sync_user") )
    {
        String strOldUser = RHOCONF().getString("rho_sync_user");
        if ( name.compare(strOldUser) != 0 )
        {
            if ( !RhoAppAdapter.callCallbackOnSyncUserChanged())
            {
                if (rho_ruby_is_started())
                {
                    if (isNoThreadedMode())
                        RhoAppAdapter.resetDBOnSyncUserChanged();
                    else
                    {
                        NetResponse resp = getNet().pushData( getNet().resolveUrl("/system/resetDBOnSyncUserChanged"), "", null );
                    }
                }
            }
        }
    }
    RHOCONF().setString("rho_sync_user", name, true);

    getNotify().callLoginCallback(oNotify, RhoAppAdapter.ERR_NONE, "" );
	
    PROF_STOP("Login");

    getUserDB().executeSQL("UPDATE client_info SET token_sent=?", 0 );
    CClientRegister::Get()->setRhoconnectCredentials(name, password, strSession);

	//}catch(Exception exc)
	//{
	//	LOG.ERROR("Login failed.", exc);
    //	callLoginCallback(callback, RhoAppAdapter.ERR_RUNTIME, exc.getMessage() );
	//}
}

boolean CSyncEngine::isLoggedIn()
 {
    String strRes = "";
    IDBResult res = getUserDB().executeSQL("SELECT session FROM client_info");
    if ( !res.isOneEnd() )
    	strRes = res.getStringByIdx(0);
    
    return strRes.length() > 0;
}

String CSyncEngine::loadSession()
{
    synchronized(m_mxSessionID)
    {
        m_strSession = "";
        IDBResult res = getUserDB().executeSQL("SELECT session FROM client_info");
    
        if ( !res.isEnd() )
    	    m_strSession = res.getStringByIdx(0);
    
        return m_strSession;
    }
}

void CSyncEngine::logout_int()
{
    CClientRegister::Get()->dropRhoconnectCredentials(m_strSession);
    //CClientRegister::Destroy();

    getUserDB().executeSQL( "UPDATE client_info SET session=NULL" );
    m_strSession = "";

    //loadAllSources();
}

void CSyncEngine::logout()
{
    stopSync();
    logout_int();
}

void CSyncEngine::setSyncServer(const char* syncserver)
{
	String strOldSrv = RHOCONF().getString("syncserver");
	String strNewSrv = syncserver ? syncserver : "";
	
	if ( strOldSrv.compare(strNewSrv) != 0)
	{
		RHOCONF().setString("syncserver", syncserver, true);
		
		getUserDB().executeSQL("DELETE FROM client_info");

		logout_int();
	}
}
    
String CSyncEngine::getSyncServer() const {
    return RHOCONF().getString("syncserver");
}


static String getHostFromUrl( const String& strUrl )
{
    const char* url = strUrl.c_str();
    const char* pStartSrv, *pEndSrv;
    int nSrvLen;
    const char* pHttp = strstr(url,"://");
    if ( !pHttp )
        pHttp = strstr(url,":\\\\");

    if ( pHttp )
        pStartSrv = pHttp+3;
    else
        pStartSrv = url;

    pEndSrv = strchr( pStartSrv, '/');
    if ( !pEndSrv )
        pEndSrv = strchr( pStartSrv, '\\');

    nSrvLen = pEndSrv ? (pEndSrv+1 - url) : strlen(url);
    return String(url, nSrvLen);
}

String CSyncEngine::CSourceID::toString()const
{
    if ( m_strName.length() > 0 )
        return "name : " + m_strName;

    return "# : " + convertToStringA(m_nID);
}

boolean CSyncEngine::CSourceID::isEqual(CSyncSource& src)const
{
    if ( m_strName.length() > 0 )
        return src.getName().compare(m_strName)==0;

    return m_nID == src.getID();
}
}
}
