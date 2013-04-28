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

#include "SyncSource.h"
#include "SyncEngine.h"
#include "SyncThread.h"

#include "common/RhoTime.h"
#include "common/StringConverter.h"
#include "common/RhodesApp.h"
#include "common/Tokenizer.h"
#include "common/RhoFilePath.h"
#include "common/RhoFile.h"
#include "common/RhoAppAdapter.h"
#include "common/RhoConf.h"
#include "json/JSONIterator.h"
#include "statistic/RhoProfiler.h"
#include "net/URI.h"
#ifndef RHO_NO_RUBY
#include "ruby/ext/rho/rhoruby.h"
#endif //RHO_NO_RUBY


namespace rho {
namespace sync {
IMPLEMENT_LOGCLASS(CSyncSource,"Sync");

using namespace rho::net;
using namespace rho::db;
using namespace rho::common;
using namespace rho::json;
/*
CSyncSource::CSyncSource() : m_syncEngine( *new CSyncEngine(*new db::CDBAdapter()))
{
    m_bTokenFromDB = true;

    m_nCurPageCount = 0;
    m_nInserted = 0;
    m_nDeleted = 0;
    m_nTotalCount = 0;

    m_nErrCode = RhoAppAdapter.ERR_NONE;

    m_bIsSearch = false;
}
*/
CSyncSource::CSyncSource(CSyncEngine& syncEngine, db::CDBAdapter& db  ) : m_syncEngine(syncEngine), m_dbAdapter(db)
{
    m_bTokenFromDB = true;
    m_nProgressStep = 0;
    m_nCurPageCount = 0;
    m_nInserted = 0;
    m_nDeleted = 0;                                     
    m_nTotalCount = 0;
    m_nRefreshTime = 0;

    m_nErrCode = RhoAppAdapter.ERR_NONE;
    m_bSchemaSource = db.isTableExist(m_strName);
}

CSyncSource::CSyncSource(int id, const String& strName, const String& strSyncType, db::CDBAdapter& db, CSyncEngine& syncEngine ) : m_syncEngine(syncEngine), m_dbAdapter(db)
{
    m_nID = id;
    m_strName = strName;
    m_strSyncType = strSyncType;
    m_nProgressStep = 0;

    m_nCurPageCount = 0;
    m_nInserted = 0;
    m_nDeleted = 0;
    m_nTotalCount = 0;
    m_nRefreshTime = 0;

    m_nErrCode = RhoAppAdapter.ERR_NONE;
	
    IDBResult res = db.executeSQL("SELECT token,associations from sources WHERE source_id=?", m_nID);
    if ( !res.isEnd() )
    {
        m_token = res.getUInt64ByIdx(0);
        m_bTokenFromDB = true;
    }else
    {
        m_token = 0;
        m_bTokenFromDB = true;
    }

    m_bSchemaSource = db.isTableExist(m_strName);
    parseAssociations(res.getStringByIdx(1));
}

void CSyncSource::parseAssociations(const String& strAssociations)
{
    if (strAssociations.length() == 0 )
        return;

    CTokenizer oTokenizer( strAssociations, "," );

    String strSrcName = "";
    while (oTokenizer.hasMoreTokens()) 
    {
	    String tok = oTokenizer.nextToken();
	    if (tok.length() == 0)
		    continue;
        
        if ( strSrcName.length() > 0 )
        {
            m_arAssociations.addElement( CAssociation(strSrcName, tok) );
            strSrcName = "";
        }else
            strSrcName = tok;
    }
}

net::CNetRequestWrapper CSyncSource::getNet(){ return getSync().getNet(); }
CSyncNotify& CSyncSource::getNotify(){ return getSync().getNotify(); }
ISyncProtocol& CSyncSource::getProtocol(){ return getSync().getProtocol(); }

void CSyncSource::sync()
{
    getNotify().reportSyncStatus(RhoAppAdapter.getMessageText("syncronizing") + getName() + "...", m_nErrCode, m_strError );

    CTimeInterval startTime = CTimeInterval::getCurrentTime();
    //m_bIsSearch = false;

//    if ( isTokenFromDB() && getToken() > 1 )
//        syncServerChanges();  //sync only server changes, which was paused before
//    else
//    {
        if ( isEmptyToken() )
            processToken(1);
	
			syncClientChanges();
			syncServerChanges();		

/*
        boolean bSyncedServer = syncClientChanges();
        if ( !bSyncedServer )
            syncServerChanges();
*/
//    }

    CTimeInterval endTime = CTimeInterval::getCurrentTime();

    int nSyncSucess = m_nErrCode == RhoAppAdapter.ERR_NONE ? 1 : 0;
    if ( nSyncSucess > 0 )
        getDB().executeSQL( "UPDATE sources set last_updated=?,last_inserted_size=?,last_deleted_size=?, \
						     last_sync_duration=?,last_sync_success=?, backend_refresh_time=? WHERE source_id=?", 
                             CLocalTime().toULong(), getInsertedCount(), getDeletedCount(), (endTime-startTime).toULong(), nSyncSucess, m_nRefreshTime,
                             getID() );
    else
        getDB().executeSQL( "UPDATE sources set last_inserted_size=?,last_deleted_size=?, \
						     last_sync_duration=?,last_sync_success=?, backend_refresh_time=? WHERE source_id=?", 
                             getInsertedCount(), getDeletedCount(), (endTime-startTime).toULong(), nSyncSucess, m_nRefreshTime,
                             getID() );

}

void CSyncSource::syncClientChanges()
{
  	PROF_START("Pull");

    boolean bSyncClient  = haveChangedValues();

    if ( bSyncClient )
        doSyncClientChanges();

    PROF_STOP("Pull");
}

/*
boolean CSyncSource::syncClientChanges()
{
    boolean bSyncedServer = false;
    if ( isPendingClientChanges() )
    {
     	LOG(INFO) + "Client has unconfirmed created items. Call server to update them.";
        syncServerChanges();
        bSyncedServer = true;
    }

    if ( bSyncedServer && isPendingClientChanges() )
    {
        LOG(INFO) + "Server does not sent created items. Stop sync.";
        getSync().setState(CSyncEngine::esStop);
    }
    else
    {   
      	PROF_START("Pull");

        boolean bSyncClient = false;
        {
            IDBResult res = getDB().executeSQL("SELECT object FROM changed_values WHERE source_id=? LIMIT 1 OFFSET 0", getID());
            bSyncClient = !res.isEnd();
        }
        if ( bSyncClient )
        {
            doSyncClientChanges();
            bSyncedServer = false;
        }

        PROF_STOP("Pull");
    }

    return bSyncedServer;
}

boolean CSyncSource::isPendingClientChanges()
{
    IDBResult res = getDB().executeSQL("SELECT object FROM changed_values WHERE source_id=? and update_type='create' and sent>1  LIMIT 1 OFFSET 0", getID());
    return !res.isEnd();
}*/

void CSyncSource::addBelongsTo(const String& strAttrib, int nSrcID)
{
    m_hashBelongsTo.put(strAttrib, nSrcID);
}

int CSyncSource::getBelongsToSrcID(const String& strAttrib)
{
    if ( m_hashBelongsTo.containsKey(strAttrib) )
        return m_hashBelongsTo.get(strAttrib);

    return -1;
}

void CSyncSource::checkIgnorePushObjects()
{
    // ignore changes in pending creates
    {
        IDBResult res = getDB().executeSQL("SELECT distinct(object) FROM changed_values where source_id=? and sent>=2", getID() );
        for( ; !res.isEnd(); res.next() )
        {
            String strObject = res.getStringByIdx(0);
            m_hashIgnorePushObjects.put(strObject, 1);
        }
    }

    //check for belongs_to
    String strAttribQuests = "";
    Vector<String> arValues;
    arValues.addElement(convertToStringA(getID()));
    for ( Hashtable<String,int>::iterator it = m_hashBelongsTo.begin();  it != m_hashBelongsTo.end(); ++it )
    {
        if ( strAttribQuests.length() > 0 )
            strAttribQuests += ",";

        strAttribQuests += "?";
        arValues.addElement(it->first);
    }

    if ( strAttribQuests.length() > 0 )
    {
        IDBResult res = getDB().executeSQLEx( (String("SELECT object, attrib, value FROM changed_values where source_id=? and sent<=1 and attrib IN ( ") + strAttribQuests + " )").c_str(), 
             arValues );

        for( ; !res.isEnd(); res.next() )
        {
            String strObject = res.getStringByIdx(0);
            String strAttrib = res.getStringByIdx(1);
            String strValue = res.getStringByIdx(2);

            IDBResult res2 = getDB().executeSQL(
                "SELECT object FROM changed_values where source_id=? and sent>=2 and object=? LIMIT 1 OFFSET 0", 
                getBelongsToSrcID(strAttrib), strValue );
            
            if (!res2.isEnd())
                m_hashIgnorePushObjects.put(strObject, 1);

        }
    }
}

void CSyncSource::doSyncClientChanges()
{
    String arUpdateTypes[] = {"create", "update", "delete"};
    boolean arUpdateSent[] = {false, false, false};

    m_arMultipartItems.removeAllElements();
    m_arBlobAttrs.removeAllElements();
    String strBody = "{\"source_name\":" + CJSONEntry::quoteValue(getName()) + ",\"client_id\":" + CJSONEntry::quoteValue(getSync().getClientID());
    boolean bSend = false;
    int i = 0;

    getDB().Lock();
    getDB().updateAllAttribChanges();
    checkIgnorePushObjects();
    if ( getSync().getSourceOptions().getBoolProperty(getID(), "full_update") )
        getDB().updateFullUpdateChanges( getID() );

    for( i = 0; i < 3; i++ )
    {
        String strBody1;
        makePushBody_Ver3(strBody1, arUpdateTypes[i], true);
        if (strBody1.length() > 0)
        {
            strBody += "," + strBody1;

            String strBlobAttrs = "";
            for ( int j = 0; j < (int)m_arBlobAttrs.size(); j++)
            {
                if ( strBlobAttrs.length() > 0 )   
                    strBlobAttrs += ",";

                strBlobAttrs += CJSONEntry::quoteValue(m_arBlobAttrs.elementAt(j));
            }

            if ( strBlobAttrs.length() > 0 )
                strBody += ",\"blob_fields\":[" + strBlobAttrs + "]";

            arUpdateSent[i] = true;
            bSend = true;
        }
    }

    if (!bSend)
    {
        //check for push_changes
        IDBResult res = getDB().executeSQL("SELECT attrib_type FROM changed_values where source_id=? and update_type =?", getID(), "push_changes" );
        bSend = !res.isEnd();
    }

    strBody += "}";

    getDB().Unlock();

    if ( bSend && getSync().isContinueSync())
    {
        LOG(INFO) + "Push client changes to server. Source: " + getName() + "Size :" + strBody.length();
        if ( !RHOCONF().getBool("log_skip_post") )
            LOG(TRACE) + "Push body: " + strBody;		

        if ( getSync().getSourceOptions().getBoolProperty(getID(), "set_sync_push_body" ) )
            getSync().getSourceOptions().setProperty(getID(), "sync_push_body", strBody.c_str() );

        if ( getSync().getSourceOptions().getIntProperty(getID(), "sync_push_error" ) > 0 )
        {
            m_nErrCode = getSync().getSourceOptions().getIntProperty(getID(), "sync_push_error" );
            m_strError = getSync().getSourceOptions().getProperty(getID(), "sync_push_error_text" );
        }else
        {
            Hashtable<String, String> reqHeaders;
            reqHeaders.put(getProtocol().getClientIDHeader(), getSync().getClientID());
            if ( m_arMultipartItems.size() > 0 )
            {
                CMultipartItem* pItem = new CMultipartItem();
                CMultipartItem& oItem = *pItem;
                oItem.m_strBody = strBody;
                //oItem.m_strContentType = getProtocol().getContentType();
                oItem.m_strName = "cud";
                m_arMultipartItems.addElement(pItem);

                NetResponse resp = getNet().pushMultipartData( getProtocol().getClientChangesUrl(getName()), m_arMultipartItems, &getSync(), &reqHeaders);
                if ( !resp.isOK() )
                {
                    //getSync().stopSync();
                    m_nErrCode = RhoAppAdapter.getErrorFromResponse(resp);
                    m_strError = resp.getCharData();
                }
            }else
            {
                NetResponse resp = getNet().doRequest("POST", getProtocol().getClientChangesUrl(getName()), strBody, &getSync(), &reqHeaders);
                if ( !resp.isOK() )
                {
                    //getSync().stopSync();
                    m_nErrCode = RhoAppAdapter.getErrorFromResponse(resp);
                    m_strError = resp.getCharData();
                }
            }
        }

#ifndef RHO_NO_RUBY    
        if ( getSync().isNoThreadedMode() && getSync().getSourceOptions().getProperty(getID(), "sync_push_callback" ).length() > 0 )
            rho_ruby_callmethod( getSync().getSourceOptions().getProperty(getID(), "sync_push_callback" ).c_str() );
#endif //RHO_NO_RUBY

        getDB().Lock();
        for( i = 0; i < 3; i++ )
        {
            if ( arUpdateSent[i] )
            {
                if ( m_nErrCode == RhoAppAdapter.ERR_NONE )
                {
                    //oo conflicts
                    if ( i < 1 &&  !getSync().getSourceOptions().getBoolProperty(getID(), "pass_through") ) //create
                        getDB().executeSQL("UPDATE changed_values SET sent=2 WHERE source_id=? and update_type=? and sent=1", getID(), arUpdateTypes[i] );
                    else
                    //
                        getDB().executeSQL("DELETE FROM changed_values WHERE source_id=? and update_type=? and sent=1", getID(), arUpdateTypes[i] );
                }else
                {
                    if ( i == 0 ) //create
                    {
                        //remove deleted while sync objects
                        Hashtable<String,int> hashDeletes;
                        {
                            IDBResult res = getDB().executeSQL("SELECT distinct(object) FROM changed_values where source_id=? and update_type=? and sent=0", getID(), "delete" );
                            for( ; !res.isEnd(); res.next() )
                                hashDeletes.put( res.getStringByIdx(0), 1 );
                        }

                        Vector<String> arObjs;
                        IDBResult res = getDB().executeSQL("SELECT distinct(object) FROM changed_values where source_id=? and update_type=? and sent=1", getID(), arUpdateTypes[i] );
                        for( ; !res.isEnd(); res.next() )
                            arObjs.addElement( res.getStringByIdx(0) );

                        for ( int j = 0; j < (int)arObjs.size(); j++ )
                        {
                            if ( !hashDeletes.containsKey(arObjs[j]) )
                                getDB().executeSQL("INSERT INTO changed_values(update_type, attrib, source_id, object) VALUES(?,?,?,?)", arUpdateTypes[i], "object", getID(), arObjs[j] );
                        }

                        for ( int j = 0; j < (int)arObjs.size(); j++ )
                            getDB().executeSQL("DELETE FROM changed_values WHERE source_id=? and object=? and attrib<>?", getID(), arObjs[j], "object" );

                    }
                    else if ( i == 1 )//update
                    {
                        //remove updates with sent=1 if sent=0 exists
                        Vector<String> arObjs, arAttribs;
                        IDBResult res = getDB().executeSQL("SELECT object, attrib FROM changed_values where source_id=? and update_type=? and sent=0", getID(), arUpdateTypes[i] );
                        for( ; !res.isEnd(); res.next() )
                        {
                            arObjs.addElement( res.getStringByIdx(0) );
                            arAttribs.addElement( res.getStringByIdx(1) );
                        }
                        for ( int j = 0; j < (int)arObjs.size(); j++ )
                        {
                            getDB().executeSQL("DELETE FROM changed_values WHERE source_id=? and object=? and attrib=? and update_type = ? and sent=1", getID(), arObjs[j], arAttribs[j], arUpdateTypes[i] );
                        }

                        getDB().executeSQL("UPDATE changed_values SET sent=0 WHERE source_id=? and update_type=? and sent=1", getID(), arUpdateTypes[i] );
                    }
                    else
                        getDB().executeSQL("UPDATE changed_values SET sent=0 WHERE source_id=? and update_type=? and sent=1", getID(), arUpdateTypes[i] );
                }
            }
        }

        if (m_nErrCode == RhoAppAdapter.ERR_NONE)
            getDB().executeSQL("DELETE FROM changed_values WHERE source_id=? and update_type=?", getID(), "push_changes" );

        getDB().Unlock();
    }

    m_arMultipartItems.removeAllElements();
    m_arBlobAttrs.removeAllElements();
}
/*
static void escapeDoubleQuotes(String& str)
{
    const char* szQuote = strchr(str.c_str(), '\"');
    while(szQuote)
    {
        int nPos = szQuote - str.c_str();
        str.insert(nPos, 1, '\\');
        if ( nPos+2 < str.length() )
            szQuote = strchr(str.c_str()+nPos+2, '\"');
        else
            szQuote = 0;
    }
}*/

//{"source_name":"SampleAdapter","client_id":1,"create":{"1":{"brand":"Apple","name":"iPhone","price":"199.99"}}}
//{"source_name":"SampleAdapter","client_id":1,"update":{"1":{"brand":"Apple","name":"iPhone","price":"199.99"}}}
//{"source_name":"SampleAdapter","client_id":1,"delete":{"1":{"brand":"Apple","name":"iPhone","price":"199.99"}}}
//{"source_name":"SampleAdapter","client_id":1,"delete":{"3":{"brand":"HTC","name":"Fuze","price":"299.99"}},"create":{"1":{"brand":"Apple","name":"iPhone","price":"199.99"}},"update":{"2":{"brand":"Android","name":"G2","price":"99.99"}}}
void CSyncSource::makePushBody_Ver3(String& strBody, const String& strUpdateType, boolean isSync)
{
    getDB().Lock();

    //if ( isSync )
    //    getDB().updateAllAttribChanges();

    IDBResult res = getDB().executeSQL("SELECT attrib, object, value, attrib_type "
        "FROM changed_values where source_id=? and update_type =? and sent<=1 ORDER BY object", getID(), strUpdateType.c_str() );

    if ( res.isEnd() )
    {
        getDB().Unlock();
        return;
    }

    String strCurObject = "";
    boolean bFirst = true;
    for( ; !res.isEnd(); res.next() )
    {
        String strAttrib = res.getStringByIdx(0);
        String strObject = res.getStringByIdx(1);
        String value = res.getStringByIdx(2);
        String attribType = res.getStringByIdx(3);

        if ( m_hashIgnorePushObjects.containsKey(strObject) || strObject.length() == 0 )
            continue;

        if ( attribType.compare("blob.file") == 0 && value.length() > 0 )
        {
            CMultipartItem* pItem = new CMultipartItem();
            CMultipartItem& oItem = *pItem;
            oItem.m_strFilePath = RHODESAPPBASE().resolveDBFilesPath(value);
            oItem.m_strContentType = "application/octet-stream";
            oItem.m_strName = strAttrib + "-" + strObject;

            if ( m_arBlobAttrs.indexOf(strAttrib) == -1 )
                m_arBlobAttrs.addElement(strAttrib);

            m_arMultipartItems.addElement(pItem);
        }

        if ( strBody.length() == 0 )
        {
            if ( !isSync )
                strBody += "{";
            else
                strBody += "\"" + strUpdateType + "\":{";
        }

        if ( strObject.compare(strCurObject) != 0 )
        {
            if ( strCurObject.length() > 0 )
            {
                if ( !bFirst )
                    strBody += "}";
                strBody += ",";
            }

            bFirst = true;
            strBody += CJSONEntry::quoteValue(strObject);
            strCurObject = strObject;
        }
            
        if (!bFirst)
            strBody += ",";

        if ( strAttrib.length() > 0  )
        {
            if ( bFirst )
                strBody += ":{";

            strBody += CJSONEntry::quoteValue(strAttrib) + ":" + CJSONEntry::quoteValue(value);
            bFirst = false;
        }
    }

    if ( strBody.length() > 0 )
    {
        if ( !bFirst )
            strBody += "}";

        strBody += "}";
    }

    if ( isSync )
        getDB().executeSQL("UPDATE changed_values SET sent=1 WHERE source_id=? and update_type=? and sent=0", getID(), strUpdateType.c_str() );

    getDB().Unlock();
}

void CSyncSource::applyChangedValues()
{
    String strBody = "";
    makePushBody_Ver3(strBody, "create", false);
    if ( strBody.length() > 0 )
    {
        CJSONEntry oEntry(strBody.c_str());
        processSyncCommand("insert", oEntry, false );
    }

    strBody = "";
    makePushBody_Ver3(strBody, "delete", false);
    if ( strBody.length() > 0 )
    {
        CJSONEntry oEntry(strBody.c_str());
        processSyncCommand("delete", oEntry, false );
    }

    strBody = "";
    makePushBody_Ver3(strBody, "update", false);
    if ( strBody.length() > 0 )
    {
        CJSONEntry oEntry(strBody.c_str());
        processSyncCommand("insert", oEntry, false );
    }
}

void CSyncSource::syncServerChanges()
{
    LOG(INFO) + "Sync server changes source ID :" + getID();

    while( getSync().isContinueSync() && 
           ( m_nErrCode == RhoAppAdapter.ERR_NONE || m_nErrCode == RhoAppAdapter.ERR_CUSTOMSYNCSERVER) )
    {
        setCurPageCount(0);
        String strUrl = getProtocol().getServerQueryUrl(getName(), getSync().getClientID(), getSync().getSyncPageSize());
        Hashtable<String, String> reqHeaders;
        reqHeaders.put(getProtocol().getClientIDHeader(), getSync().getClientID());

        if ( !m_bTokenFromDB && getToken() > 1 )
            strUrl += "&token=" + convertToStringA(getToken());

        if ( m_strQueryParams.length() > 0 )
            strUrl += "&" + m_strQueryParams; 

		LOG(INFO) + "Pull changes from server. Url: " + strUrl;
        PROF_START("Net");	    
        NetResponse resp = getNet().doRequest("GET", strUrl, "", &getSync(), &reqHeaders);
	    PROF_STOP("Net");

        if ( !resp.isOK() )
        {
            //getSync().stopSync();
		    m_nErrCode = RhoAppAdapter.getErrorFromResponse(resp);
            m_strError = resp.getCharData();
            continue;
        }

        const char* szData = null;
        String strTestResp = getSync().getSourceOptions().getProperty(getID(), "rho_server_response");
        if ( strTestResp.length() > 0 )
        {
            szData = strTestResp.c_str();
            getNotify().setFakeServerResponse(true);
        }
        else
            szData = resp.getCharData();

        //LOG(INFO) + szData;
        PROF_START("Parse");
        CJSONArrayIterator oJsonArr(szData);
        PROF_STOP("Parse");

        processServerResponse_ver3(oJsonArr);

        if (getSync().getSourceOptions().getBoolProperty(getID(), "pass_through"))
            processToken(0);

        if ( getToken() == 0 )
            break;

        if ( strTestResp.length() > 0 )
            break;
    }

    if ( getSync().isSchemaChanged() )
        getSync().stopSync();
}

//{"create-error":{"0_broken_object_id":{"name":"wrongname","an_attribute":"error create"},"0_broken_object_id-error":{"message":"error create"}}}
void CSyncSource::processServerErrors(CJSONEntry& oCmds)
{
    Hashtable<String, String> errors;

    const char* arErrTypes[] = {"source-error", "search-error", "create-error", "update-error", "delete-error", "update-rollback", null};
    for( int i = 0; ; i++ )
    {
        if ( arErrTypes[i] == null )
            break;
        if ( !oCmds.hasName(arErrTypes[i]) )
            continue;

		String strServerError = "";

        CJSONEntry errSrc = oCmds.getEntry(arErrTypes[i]);
        
        String errorType = "";
        CJSONStructIterator errIter(errSrc);

        if ( i == 0 || i == 1 )//"source-error", "search-error"
        {
            if ( errIter.getCurValue().hasName("message") ) {
                errorType = errIter.getCurKey() + "-json";
                strServerError = String("{message:\"")+errIter.getCurValue().getString("message")+"\"}";
            }
        } else {
            //"create-error", "update-error", "delete-error", "update-rollback"
            errorType = String(arErrTypes[i]) + "-json";
            
            Hashtable<String,String> objErrors;
                        
            //iterate objects
            for( ; !errIter.isEnd(); errIter.next() )
            {
                String strObject = errIter.getCurKey();
                

                if ( String_endsWith(strObject, "-error") )
                {
                    strObject = strObject.substr(0, strObject.length()-6);
                }
                
                String strValue = objErrors.get(strObject);
                
                if ( strValue.length() == 0 ) {
                    strValue = "{";
                }
                
                if ( String_endsWith(strValue, "}") ) {
                    strValue = strValue.substr(0,strValue.length()-1);
                }
                
                if ( errIter.getCurValue().hasName("message") )
                {
                    if (strValue.length() > 1) {
                        strValue += ",";
                    }
                    strValue += String("message:\"") + errIter.getCurValue().getString("message") + "\"";
                } else {                
                    CJSONStructIterator attrIter(errIter.getCurValue());
                    bool first = true;
                    String strAttrs = "";
                    if ( !attrIter.isEnd() ) {
                        if (strValue.length() > 1) {
                            strValue += ",";
                        }
                        strAttrs += "attributes:{";
                    }

                    for( ; !attrIter.isEnd(); attrIter.next() ) {
                        if ( first ) {
                            first = false;
                        } else {
                            strAttrs += ",";
                        }
                    
                        String strAttrName = attrIter.getCurKey();
                        String strAttrValue = attrIter.getCurString();
                    
                        strAttrs += "\""+strAttrName+"\":\""+strAttrValue+"\"";
                    }
                    
                    if ( strAttrs.length() > 0 ) {
                        strAttrs += "}";
                    }
                    
                    if ( strValue.length() > 1 ) {
                        strValue += ",";
                    }
                    
                    strValue += strAttrs;
                }
                
                strValue += "}";
                
                objErrors.put(strObject,strValue);
                
            }
            
            if ( objErrors.size() > 0 ) {
                strServerError = "{";
                for ( Hashtable<String,String>::const_iterator it = objErrors.begin(); it != objErrors.end(); ++it ) {
                    strServerError += "\"" + it->first + "\":" + it->second;
                }
                strServerError += "}";
            }
        }
    
        
        if ( (errorType.length()>0) && (strServerError.size()>0) ) {
            errors.put(errorType,strServerError);
        }

		
    }
    
    if ( errors.size() > 0 ) {
        getNotify().fireSyncNotification2(this, true, RhoAppAdapter.ERR_CUSTOMSYNCSERVER, errors);
    }
}

void CSyncSource::processServerResponse_ver3(CJSONArrayIterator& oJsonArr, bool isRecoveryMode )
{
    PROF_START("Data1");

    if ( oJsonArr.isEnd() )
    {
        getSync().stopSync();
        m_nErrCode = RhoAppAdapter.ERR_UNEXPECTEDSERVERRESPONSE;
        return;
    }

    int nVersion = 0;
    if ( !oJsonArr.isEnd() && oJsonArr.getCurItem().hasName("version") )
    {
        nVersion = oJsonArr.getCurItem().getInt("version");
        oJsonArr.next();
    }

    if ( nVersion != getProtocol().getVersion() )
    {
        LOG(ERROR) + "Sync server send data with incompatible version. Client version: " + convertToStringA(getProtocol().getVersion()) +
            "; Server response version: " + convertToStringA(nVersion) + ". Source name: " + getName();
        getSync().stopSync();
        m_nErrCode = RhoAppAdapter.ERR_SYNCVERSION;
        return;
    }

    if ( !oJsonArr.isEnd() && oJsonArr.getCurItem().hasName("token"))
    {
        processToken(oJsonArr.getCurItem().getUInt64("token"));
        oJsonArr.next();
    }

    if ( !oJsonArr.isEnd() && oJsonArr.getCurItem().hasName("source") )
    {
        //skip it. it uses in search only
        oJsonArr.next();
    }

    if ( !oJsonArr.isEnd() && oJsonArr.getCurItem().hasName("count") )
    {
        setCurPageCount(oJsonArr.getCurItem().getInt("count"));
        oJsonArr.next();
    }

    if ( !oJsonArr.isEnd() && oJsonArr.getCurItem().hasName("refresh_time") )
    {
        setRefreshTime(oJsonArr.getCurItem().getInt("refresh_time"));
        oJsonArr.next();
    }

    if ( !oJsonArr.isEnd() && oJsonArr.getCurItem().hasName("progress_count") )
    {
        //TODO: progress_count
        //setTotalCount(oJsonArr.getCurItem().getInt("progress_count"));
        oJsonArr.next();
    }

    if ( !oJsonArr.isEnd() && oJsonArr.getCurItem().hasName("total_count") )
    {
        setTotalCount(oJsonArr.getCurItem().getInt("total_count"));
        oJsonArr.next();
    }

    //if ( getServerObjectsCount() == 0 )
    //    getNotify().fireSyncNotification(this, false, RhoAppAdapter.ERR_NONE, "");

    if ( getToken() == 0 )
    {
        //oo conflicts
        getDB().executeSQL("DELETE FROM changed_values where source_id=? and sent>=3", getID() );
        //

    }

	LOG(INFO) + "Got " + getCurPageCount() + "(Processed: " +  getServerObjectsCount() + ") records of " + getTotalCount() + " from server. Source: " + getName()
         + ". Version: " + nVersion;

    PROF_STOP("Data1");
    if ( !oJsonArr.isEnd() && getSync().isContinueSync() )
    {
        CJSONEntry oCmds = oJsonArr.getCurItem();
        PROF_START("Data");
        //TODO: use isUIWaitDB inside processSyncCommand
        //    if ( getDB().isUIWaitDB() )
        //    {
		//        LOG(INFO) + "Commit transaction because of UI request.";
        //        getDB().endTransaction();
        //        getDB().startTransaction();
        //    }

        if ( oCmds.hasName("schema-changed") )
        {
            getSync().setSchemaChanged(true);
        }else
        {
            processServerErrors(oCmds);

            getDB().startTransaction();

            if (getSync().getSourceOptions().getBoolProperty(getID(), "pass_through"))
            {
                if ( m_bSchemaSource )
                    getDB().executeSQL( (String("DELETE FROM ") + getName()).c_str() );
                else
                    getDB().executeSQL("DELETE FROM object_values WHERE source_id=?", getID() );
            }

            if ( oCmds.hasName("metadata") && getSync().isContinueSync() )
            {
                String strMetadata = oCmds.getString("metadata");
                getDB().executeSQL("UPDATE sources SET metadata=? WHERE source_id=?", strMetadata, getID() );
            }
            if ( oCmds.hasName("links") && getSync().isContinueSync() )
                processSyncCommand("links", oCmds.getEntry("links"), true );
            if ( oCmds.hasName("delete") && getSync().isContinueSync() )
                processSyncCommand("delete", oCmds.getEntry("delete"), true );
            if ( oCmds.hasName("insert") && getSync().isContinueSync() )
                processSyncCommand("insert", oCmds.getEntry("insert"), true );

            PROF_STOP("Data");

	        PROF_START("DB");
            getDB().endTransaction();
            PROF_STOP("DB");

            if (!isRecoveryMode) {
                getNotify().fireObjectsNotification();
            }
        }
    }

	PROF_START("Data1");
    if ( getCurPageCount() > 0 ) {
        if ( !isRecoveryMode ) {
            getNotify().fireSyncNotification(this, false, RhoAppAdapter.ERR_NONE, "");
        }
    }
	PROF_STOP("Data1");
}

void CSyncSource::processSyncCommand(const String& strCmd, CJSONEntry oCmdEntry, boolean bCheckUIRequest)
{
    CJSONStructIterator objIter(oCmdEntry);

    for( ; !objIter.isEnd() && getSync().isContinueSync(); objIter.next() )
    {
        String strObject = objIter.getCurKey();
        CJSONStructIterator attrIter( objIter.getCurValue() );
        if ( m_bSchemaSource )
            processServerCmd_Ver3_Schema(strCmd,strObject,attrIter,bCheckUIRequest);
        else
        {
            for( ; !attrIter.isEnd(); attrIter.next() )
            {
                String strAttrib = attrIter.getCurKey();
                String strValue = attrIter.getCurString();

                processServerCmd_Ver3(strCmd,strObject,strAttrib,strValue,bCheckUIRequest);
            }
        }

        if ( getSyncType().compare("none") == 0 )
            continue;

        if ( bCheckUIRequest )
        {
            if ( getDB().isUIWaitDB() )
            {
	            LOG(INFO) + "Commit transaction because of UI request.";
                getDB().endTransaction();

                checkProgressStepNotify(false);

                CSyncThread::getInstance()->sleep(1000);
                getDB().startTransaction();
            }else
                checkProgressStepNotify(true);
        }
    }
}

void CSyncSource::checkProgressStepNotify(boolean bEndTransaction)
{
    int nSyncObjectCount  = getNotify().incLastSyncObjectCount(getID());
    if ( getProgressStep() > 0 && (nSyncObjectCount%getProgressStep() == 0) )
    {
        if ( bEndTransaction )
        {
            LOG(INFO) + "Commit transaction because of Sync Progress notification.";
            getDB().endTransaction();
        }

        getNotify().fireSyncNotification(this, false, RhoAppAdapter.ERR_NONE, "");

        if ( bEndTransaction )
            getDB().startTransaction();
    }
}

void CSyncSource::processAssociations(const String& strOldObject, const String& strNewObject)
{
    for ( int i = 0; i < (int)m_arAssociations.size(); i++ )
    {
        CSyncSource* pSrc = getSync().findSourceByName(m_arAssociations.elementAt(i).m_strSrcName);
        if ( pSrc != null )
            pSrc->updateAssociation(strOldObject, strNewObject, m_arAssociations.elementAt(i).m_strAttrib);
    }
}

void CSyncSource::updateAssociation(const String& strOldObject, const String& strNewObject, const String& strAttrib)
{
    if ( m_bSchemaSource )
    {
        String strSqlUpdate = "UPDATE ";
        strSqlUpdate += getName() + " SET " + strAttrib + "=? where " + strAttrib + "=?";

        getDB().executeSQL(strSqlUpdate.c_str(), strNewObject, strOldObject );
    }
    else
        getDB().executeSQL("UPDATE object_values SET value=? where attrib=? and source_id=? and value=?", 
            strNewObject, strAttrib, getID(), strOldObject );

    getDB().executeSQL("UPDATE changed_values SET value=? where attrib=? and source_id=? and value=?", 
        strNewObject, strAttrib, getID(), strOldObject );
}

void CSyncSource::processServerCmd_Ver3_Schema(const String& strCmd, const String& strObject, CJSONStructIterator& attrIter, boolean bCheckUIRequest)//throws Exception
{
    if ( strCmd.compare("insert") == 0 )
    {
        Vector<String> vecValues, vecAttrs;
        String strCols = "", strQuest = "", strSet = "";
        for( ; !attrIter.isEnd(); attrIter.next() )
        {
            CAttrValue oAttrValue(attrIter.getCurKey(),attrIter.getCurString());

    	    if ( bCheckUIRequest && !checkFreezedProps(oAttrValue.m_strAttrib))
    		    continue;
			
            if ( !processBlob(strCmd,strObject,oAttrValue) )
                break;

            if ( strCols.length() > 0 )
                strCols += ",";
            if ( strQuest.length() > 0)
                strQuest += ",";
            if ( strSet.length() > 0)
                strSet += ",";

            strCols += oAttrValue.m_strAttrib;
            strQuest += "?";
            strSet += oAttrValue.m_strAttrib + "=?";
            vecAttrs.addElement(oAttrValue.m_strAttrib);
            vecValues.addElement(oAttrValue.m_strValue);
        }
        vecValues.addElement(strObject);
        if ( strCols.length() > 0 )
            strCols += ",";
        if ( strQuest.length() > 0)
            strQuest += ",";

        strCols += "object";
        strQuest += "?";

        String strSqlInsert = "INSERT INTO ";
        strSqlInsert += getName() + " (";
        strSqlInsert += strCols + ") VALUES(" + strQuest + ")";

        if ( !getSync().isContinueSync() )
            return;

        IDBResult resInsert = getDB().executeSQLReportNonUniqueEx(strSqlInsert.c_str(), vecValues );
        if ( resInsert.isNonUnique() )
        {
            String strSqlUpdate = "UPDATE ";
            strSqlUpdate += getName() + " SET " + strSet + " WHERE object=?";
            getDB().executeSQLEx(strSqlUpdate.c_str(), vecValues);

            if ( getSyncType().compare("none") != 0 )
            {
                // oo conflicts
                for( int i = 0; i < (int)vecAttrs.size(); i++ )
                {
                    getDB().executeSQL("UPDATE changed_values SET sent=4 where object=? and attrib=? and source_id=? and update_type=? and sent>1", 
                        strObject, vecAttrs.elementAt(i), getID(), "create" );
                }
                //
            }
        }

        if ( getSyncType().compare("none") != 0 )
            getNotify().onObjectChanged(getID(),strObject, CSyncNotify::enUpdate);

        m_nInserted++;
    }else if (strCmd.compare("delete") == 0)
    {
        Vector<String> vecAttrs;
        String strSet = "";
        for( ; !attrIter.isEnd() && getSync().isContinueSync(); attrIter.next() )
        {
            CAttrValue oAttrValue(attrIter.getCurKey(),attrIter.getCurString());

            if ( strSet.length() > 0 )
                strSet += ",";

            vecAttrs.addElement(oAttrValue.m_strAttrib);
            strSet += oAttrValue.m_strAttrib + "=NULL";
        }

        String strSqlUpdate = "UPDATE ";
        strSqlUpdate += getName() + " SET " + strSet + " WHERE object=?";

        if ( strSet.length() == 0 )
            return;

        getDB().executeSQL(strSqlUpdate.c_str(), strObject);
        //Remove item if all nulls
        String strSelect = String("SELECT * FROM ") + getName() + " WHERE object=?";
        IDBResult res = getDB().executeSQL( strSelect.c_str(), strObject );
        if ( !res.isEnd() )
        {
            boolean bAllNulls = true;
            for( int i = 0; i < res.getColCount(); i ++)
            {
                if ( !res.isNullByIdx(i) && res.getColName(i).compare("object")!=0 )
                {
                    bAllNulls = false;
                    break;
                }
            }

            if (bAllNulls)
            {
                String strDelete = String("DELETE FROM ") + getName() + " WHERE object=?";
                getDB().executeSQL( strDelete.c_str(), strObject);
            }
        }

        if ( getSyncType().compare("none") != 0 )
        {
            getNotify().onObjectChanged(getID(), strObject, CSyncNotify::enDelete);
            // oo conflicts
            for( int i = 0; i < (int)vecAttrs.size(); i++ )
            {
                getDB().executeSQL("UPDATE changed_values SET sent=3 where object=? and attrib=? and source_id=? and update_type=?", 
                    strObject, vecAttrs.elementAt(i), getID(), "create" );
            }
            //
        }

        m_nDeleted++;
    }else if ( strCmd.compare("links") == 0 )
    {
        String strValue = attrIter.getCurString();
        processAssociations(strObject, strValue);

        String strSqlUpdate = "UPDATE ";
        strSqlUpdate += getName() + " SET object=? WHERE object=?";
        getDB().executeSQL(strSqlUpdate.c_str(), strValue, strObject);

        getDB().executeSQL("UPDATE changed_values SET object=?,sent=3 where object=? and source_id=? and update_type=?", strValue, strObject, getID(), "create" );
        getNotify().onObjectChanged(getID(), strObject, CSyncNotify::enCreate);
    }

}

boolean CSyncSource::processBlob( const String& strCmd, const String& strObject, CAttrValue& oAttrValue )
{
    //TODO: when server return delete with rhoblob postfix - delete isBlobAttr
    if ( !(oAttrValue.m_strBlobSuffix.length() > 0 || getDB().getAttrMgr().isBlobAttr(getID(), oAttrValue.m_strAttrib.c_str())) )
        return true;

    boolean bDownload = true;
    String strDbValue = "";
    if ( !getDB().getAttrMgr().isOverwriteBlobFromServer(getID(), oAttrValue.m_strAttrib) )
    {
        if ( m_bSchemaSource )
        {
            String strSelect = String("SELECT ") + oAttrValue.m_strAttrib + " FROM " + getName() + " WHERE object=?";
            IDBResult res = getDB().executeSQL( strSelect.c_str(), strObject);
            if (!res.isEnd())
            {
                strDbValue = res.getStringByIdx(0);
                bDownload = strDbValue.length() == 0;
            }
        }else
        {
            IDBResult res = getDB().executeSQL(
                "SELECT value FROM object_values WHERE object=? and attrib=? and source_id=?",
                strObject, oAttrValue.m_strAttrib, getID() );
            if (!res.isEnd())
            {
                strDbValue = res.getStringByIdx(0);
                bDownload = strDbValue.length() == 0;
            }
        }
    }

    if ( bDownload )
    {
        getDB().endTransaction();
        boolean bRes = downloadBlob(oAttrValue);
        getDB().startTransaction();

        return bRes;
    }

    oAttrValue.m_strValue = strDbValue;
    return true;
}
	
boolean CSyncSource::processServerBlobAttrs() {
	if ( m_bSchemaSource ) {
		return true;
	} else {
		static const String blobSfx = "-rhoblob";
		
		getDB().startTransaction();
		IDBResult res = getDB().executeSQL( "SELECT source_attribs,blob_attribs from sources WHERE source_id=?", getID() );
		
		Vector<String> attrsToRename;
		
		String newAttrs = "";
		
		for ( ; !res.isEnd(); res.next() ) 
        {
			String attrs = res.getStringByIdx(0);
			String blobs = res.getStringByIdx(1);
			
			CTokenizer tokenizer(attrs,",");
			while (tokenizer.hasMoreTokens()) {
				String attrName = tokenizer.nextToken();
				if (!tokenizer.hasMoreTokens()) {
					break;
				}
				String attrVal = tokenizer.nextToken();
				
				
				if ( String_endsWith( attrName, blobSfx ) ) {
					if ( blobs.length() > 0 ) {
						blobs += ",";
					}
					blobs += attrName.substr(0,attrName.length()-blobSfx.length()) + "," + attrVal;
					attrsToRename.addElement(attrName);
				} else {
					if (newAttrs.length() > 0 ) {
						newAttrs += ",";
					}
					newAttrs += attrName + "," + attrVal;
				}
			}
			
			LOG(TRACE) + "Updating attributes for source " + getName() + ". Old attribs=" + attrs + ", new attribs=" + newAttrs + ", blob attribs=" + blobs;
			
			getDB().executeSQL("UPDATE sources SET source_attribs=?,blob_attribs=? WHERE source_id=?", newAttrs, blobs, getID() );
		}
		
		for ( int i = 0; i < (int)attrsToRename.size(); i++ ) 
		{
			String strAttr = (String)attrsToRename.elementAt(i);
			LOG(TRACE) + "Updating objects with blob attribute " + strAttr + " for source " + getName();
			getDB().executeSQL( "UPDATE object_values SET attrib=? WHERE attrib=? and source_id=?", strAttr.substr( 0, strAttr.length()-blobSfx.length()), strAttr, getID() );
		}

		getDB().endTransaction();
	}
	return true;
}

	
boolean CSyncSource::processAllBlobs() 
{
	if (m_bSchemaSource) {
		Vector<String> blobAttrs = getDB().getAttrMgr().getBlobAttrs( getID() );

		for ( int i = 0; i < (int)blobAttrs.size(); i ++ ) 
		{
			String strAttr = (String)blobAttrs.elementAt(i);
			String sql = "SELECT object," + strAttr + " FROM " + getName();
			
			IDBResult res = getDB().executeSQL( sql.c_str() );
			
			LOG(TRACE) + "Processing blobs for source " + getName() + ", attribute " + strAttr;
			
			for ( ; !res.isEnd(); res.next() )
			{ 
				String object = res.getStringByIdx(0);
				String value = res.getStringByIdx(1);
				
				if ( value.find("://") != String::npos ) {
					LOG(TRACE) + "Processing remote blob: " + value;
					CAttrValue attr( strAttr, value );
					if ( !downloadBlob( attr ) ) {
						return false;
					}
					
					sql = "UPDATE " + getName() + " SET " + strAttr + "=? WHERE object=?";
					
					getDB().executeSQL( sql.c_str(), attr.m_strValue, object  );
				}
			}
		}
	} else {
		Vector<String> blobAttrs = getDB().getAttrMgr().getBlobAttrs( getID() );
	
		for ( int i = 0; i < (int)blobAttrs.size(); i ++ ) 
		{
			String strAttr = (String)blobAttrs.elementAt(i);
			IDBResult res = getDB().executeSQL("SELECT object,value FROM object_values WHERE attrib=? and source_id=?", strAttr, getID());
		
			LOG(TRACE) + "Processing blobs for source " + getName() + ", attribute " + strAttr;
		
			for ( ; !res.isEnd(); res.next() )
			{ 
				String object = res.getStringByIdx(0);
				String value = res.getStringByIdx(1);
			
				if ( value.find("://") != String::npos ) {
					LOG(TRACE) + "Processing remote blob: " + value;
					CAttrValue attr( strAttr, value );
					if ( !downloadBlob( attr ) ) {
						return false;
					}
				
					getDB().executeSQL("UPDATE object_values SET value=? where object=? and source_id=? and attrib=?", attr.m_strValue, object, getID(), strAttr);
				}
			}
		}
	}
	
	return true;
}

boolean CSyncSource::checkFreezedProps(String strProp)
{
	String strFreezedProps = getSync().getSourceOptions().getProperty(getID(), "freezed");
	
	if ( strFreezedProps.length() > 0 )
	{
		CTokenizer oTokenizer( strFreezedProps, "," );
		boolean bFound =false;
		while (oTokenizer.hasMoreTokens() && (!bFound) ) 
		{
			String tok = oTokenizer.nextToken();
			if (tok.length() == 0)
				continue;
		
			if (tok.compare(strProp)==0)
			{
				bFound = true;
			}
		}
	
		if (!bFound)
		{
			LOG(INFO) + "Skip Non-exist property : " + strProp + ". For model : " + getName();
			return false;				
		}
	}
	
	return true;
}

void CSyncSource::processServerCmd_Ver3(const String& strCmd, const String& strObject, const String& strAttriba, const String& strValuea, boolean bCheckUIRequest)//throws Exception
{
    CAttrValue oAttrValue(strAttriba,strValuea);

    if ( strCmd.compare("insert") == 0 )
    {
    	if ( bCheckUIRequest && !checkFreezedProps(oAttrValue.m_strAttrib))
    		return;

        if ( !processBlob(strCmd,strObject,oAttrValue) )
            return;

        IDBResult resInsert = getDB().executeSQLReportNonUnique("INSERT INTO object_values \
            (attrib, source_id, object, value) VALUES(?,?,?,?)", 
            oAttrValue.m_strAttrib, getID(), strObject, oAttrValue.m_strValue );
        if ( resInsert.isNonUnique() )
        {
            getDB().executeSQL("UPDATE object_values \
                SET value=? WHERE object=? and attrib=? and source_id=?", 
                oAttrValue.m_strValue, strObject, oAttrValue.m_strAttrib, getID() );

            if ( getSyncType().compare("none") != 0 )
            {
                // oo conflicts
                getDB().executeSQL("UPDATE changed_values SET sent=4 where object=? and attrib=? and source_id=? and update_type=? and sent>1", 
                    strObject, oAttrValue.m_strAttrib, getID(), "create" );
                //
            }
        }

        if ( getSyncType().compare("none") != 0 )
           getNotify().onObjectChanged(getID(),strObject, CSyncNotify::enUpdate);

        m_nInserted++;
    }else if (strCmd.compare("delete") == 0)
    {
        getDB().executeSQL("DELETE FROM object_values where object=? and attrib=? and source_id=?", strObject, oAttrValue.m_strAttrib, getID() );

        if ( getSyncType().compare("none") != 0 )
        {
            getNotify().onObjectChanged(getID(), strObject, CSyncNotify::enDelete);
            // oo conflicts
            getDB().executeSQL("UPDATE changed_values SET sent=3 where object=? and attrib=? and source_id=? and update_type=?", strObject, oAttrValue.m_strAttrib, getID(), "create" );
            //
        }

        m_nDeleted++;
    }else if ( strCmd.compare("links") == 0 )
    {
        processAssociations(strObject, oAttrValue.m_strValue);

        getDB().executeSQL("UPDATE object_values SET object=? where object=? and source_id=?", oAttrValue.m_strValue, strObject, getID() );
        getDB().executeSQL("UPDATE changed_values SET object=?,sent=3 where object=? and source_id=? and update_type=?", oAttrValue.m_strValue, strObject, getID(), "create" );

        getNotify().onObjectChanged(getID(), strObject, CSyncNotify::enCreate);
    }

}

String CSyncSource::makeFileName(const CAttrValue& value)//throws Exception
{
	String strExt = "";

    URI uri(value.m_strValue);    
    String strQuest = uri.getQueryString();

    if (strQuest.length() > 0)
    {
		int nExt = strQuest.find("extension=");
		if ( nExt >= 0 )
        {
			int nExtEnd = strQuest.find("&", nExt);
			if (nExtEnd < 0 )
				nExtEnd = strQuest.length();
			
			strExt = strQuest.substr(nExt+10, nExtEnd);
		}
    }

    if ( strExt.length() == 0 )
    {
        String strFileName = uri.getLastNamePart();
        int nExt = strFileName.find_last_of('.');
		if ( nExt >= 0 )
            strExt = strFileName.substr(nExt);
    }

    if ( strExt.length() == 0 )
        strExt = ".bin";
    else if ( strExt.at(0) != '.' )    
        strExt = "." + strExt;

    static int g_nBlobCounter = 0;
    String fName = RHODESAPPBASE().getBlobsDirPath() + "/id_" + CLocalTime().toString(true,true) + convertToStringA(g_nBlobCounter) + strExt;
    g_nBlobCounter++;
	
	return  fName;
}

CAttrValue::CAttrValue(const String& strAttrib, const String& strValue)
{
    m_strAttrib = strAttrib;
    m_strValue = strValue;

	if ( String_endsWith(m_strAttrib,"-rhoblob")  )
    {
		m_strBlobSuffix = "-rhoblob";
        m_strAttrib = m_strAttrib.substr(0,m_strAttrib.length()-m_strBlobSuffix.length());
    }
}

boolean CSyncSource::downloadBlob(CAttrValue& value)//throws Exception
{
	String fName = makeFileName( value );
	String url = value.m_strValue;
	
	LOG(TRACE) + "Download blob: " + url + " => " + fName;
	
	const char* nQuest = strchr(url.c_str(),'?');
	if ( nQuest > 0 )
		url += "&";
	else
		url += "?";
	url += "client_id=" + getSync().getClientID();

    NetResponse resp = getNet().pullFile(url, fName, &getSync(), null, true, false);
    if ( !resp.isOK() )
    {
        CRhoFile::deleteFile(fName.c_str());
        //getSync().stopSync();
		m_nErrCode = RhoAppAdapter.getErrorFromResponse(resp);
        //m_strError = resp.getCharData();
        return false;
    }

    value.m_strValue = RHODESAPPBASE().getRelativeDBFilesPath( fName );
    
    return true;
}

void CSyncSource::processToken(uint64 token)
{
    if ( token > 1 && getToken() == token ){
		//Delete non-confirmed records

        setToken( token ); //For m_bTokenFromDB = false;
        //getDB().executeSQL("DELETE FROM object_values where source_id=? and token=?", getID(), token );
        //TODO: add special table for id,token
	}else
    {
        setToken( token );
        getDB().executeSQL("UPDATE sources SET token=? where source_id=?", token, getID() );
	}

}

bool CSyncSource::haveChangedValues()
{
	IDBResult res = getDB().executeSQL("SELECT object FROM changed_values WHERE source_id=? and sent<=1 LIMIT 1 OFFSET 0", getID());
	return !res.isEnd();
}

}
}
