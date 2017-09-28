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

#include "SyncNotify.h"
#include "SyncEngine.h"
//#include "net/URI.h"
#include "common/RhoFilePath.h"
#include "common/RhoAppAdapter.h"
#include "common/RhodesApp.h"
#include "json/JSONIterator.h"

#ifndef RHO_NO_RUBY
    #include "rubyext/WebView.h"
#endif

namespace rho {
namespace sync {
IMPLEMENT_LOGCLASS(CSyncNotify,"Sync");
using namespace rho::net;
using namespace rho::common;
using namespace rho::db;

common::CAutoPtr<CObjectNotification> CSyncNotify::m_pObjectNotify;
common::CMutex CSyncNotify::m_mxObjectNotify;

void CSyncNotify::addObjectNotify(int nSrcID, const String& strObject)
{
    synchronized(m_mxObjectNotify)
    {
        Hashtable<String,int>* phashObject = m_hashSrcIDAndObject.get(nSrcID);
        if ( phashObject == 0 )
        {
            phashObject = new Hashtable<String,int>();
            m_hashSrcIDAndObject.put( nSrcID, phashObject );
        }

        Hashtable<String,int>& hashObject = *phashObject;
        hashObject.put(strObject,enNone);
    }
}

void CSyncNotify::addObjectNotify(const String& strSrcName, const String& strObject )
{
    synchronized(m_mxObjectNotify)
    {
        m_strSingleObjectSrcName = strSrcName;
        m_strSingleObjectID = strObject[0] == '{' ? strObject.substr(1,strObject.length()-2) : strObject ;
    }
}

void CSyncNotify::cleanObjectNotifications()
{
    synchronized(m_mxObjectNotify)
    {
        m_strSingleObjectSrcName = "";
        m_strSingleObjectID = "";
        m_hashSrcIDAndObject.clear();
    }
}

void CSyncNotify::cleanCreateObjectErrors()
{
    synchronized(m_mxObjectNotify)
    {
        m_hashCreateObjectErrors.clear();
    }
}

void CSyncNotify::processSingleObject()
{
    if ( m_strSingleObjectSrcName.length() == 0 )
        return;

    CSyncSource* pSrc = getSync().findSourceByName(m_strSingleObjectSrcName);
    if ( pSrc )
    {
        int nSrcID = pSrc->getID();
        addObjectNotify(nSrcID,m_strSingleObjectID);
    }

    m_strSingleObjectSrcName = "";
    m_strSingleObjectID = "";
}

void CSyncNotify::fireObjectsNotification()
{
	Hashtable<String, String> result;
	Hashtable<String, Hashtable<String,String> > l2Result;
	Hashtable<String, String> hashDeleted,hashUpdated,hashCreated;

    {
        synchronized(m_mxObjectNotify)

        if ( !m_pObjectNotify)
            return;

        for (HashtablePtr<int, Hashtable<String,int>* >::iterator it = m_hashSrcIDAndObject.begin();  it != m_hashSrcIDAndObject.end(); ++it )
        {
            int nSrcID = it->first;
            Hashtable<String,int>& hashObject = *(it->second);
            for ( Hashtable<String,int>::iterator itObject = hashObject.begin();  itObject != hashObject.end(); ++itObject )
            {
                int nNotifyType = itObject->second;
                if (nNotifyType == enNone)
                    continue;
                //This is slow operation
/*
                if ( nNotifyType == enDelete )
                {
                    //TODO: get db for source
                    IDBResult res = getDB().executeSQL("SELECT object FROM object_values where object=? LIMIT 1 OFFSET 0", itObject->first );
                    if ( !res.isEnd() )
                        nNotifyType = enUpdate;    
                }
*/
                Hashtable<String,String>* pHash = 0;
                switch(nNotifyType)
                {
                case enDelete:
                    pHash = &hashDeleted;
                    break;
                case enUpdate:
                    pHash = &hashUpdated;
                    break;
                case enCreate:
                    pHash = &hashCreated;
                    break;
                }
				
                if (pHash != 0) {
                    pHash->put( itObject->first, convertToStringA(nSrcID) );
                }

                hashObject.put(itObject->first, enNone);
            }
        }

        if ( (hashDeleted.size() + hashCreated.size() + hashUpdated.size() ) == 0 )
            return;
    }
	
	l2Result.put("created",hashCreated);
	l2Result.put("updated",hashUpdated);
	l2Result.put("deleted",hashDeleted);

	callNotify( CSyncNotification(m_pObjectNotify->m_callbackData,false), result, &l2Result );
}

void CSyncNotify::onObjectChanged(int nSrcID, const String& strObject, int nType)
{
    synchronized(m_mxObjectNotify)
    {
        processSingleObject();

        Hashtable<String,int>* phashObject = m_hashSrcIDAndObject.get(nSrcID);
        if ( phashObject == 0 )
            return;

        Hashtable<String,int>& hashObject = *phashObject;
        if( hashObject.containsKey(strObject) )
            hashObject.put(strObject,nType);
    }
}

void CSyncNotify::addCreateObjectError(int nSrcID, const String& strObject, const String& strError)
{
    synchronized(m_mxObjectNotify)
    {
        Hashtable<String,String>* phashErrors = m_hashCreateObjectErrors.get(nSrcID);
        if ( phashErrors == 0 )
        {
            phashErrors = new Hashtable<String,String>();
            m_hashCreateObjectErrors.put( nSrcID, phashErrors );
        }

        Hashtable<String,String>& hashErrors = *phashErrors;
        hashErrors.put(strObject,strError);
    }
}

void CSyncNotify::appendCreateObjectErrorInfo(int nSrcID, Hashtable< String, Hashtable<String, String> >& result )
{
    String strBody = "";

    synchronized(m_mxObjectNotify)
    {
        Hashtable<String,String>* phashErrors = m_hashCreateObjectErrors.get(nSrcID);
		
		
        if ( phashErrors == 0 )
            return ;

        Hashtable<String,String>& hashErrors = *phashErrors;
		
        result.put("create_error",hashErrors);

        hashErrors.clear();
    }
}

void CSyncNotify::setObjectNotification(CObjectNotification* pNotify)
{ 
    synchronized(m_mxObjectNotify)
    {
        m_pObjectNotify = pNotify; 
    }
}

CObjectNotification* CSyncNotify::getObjectNotification()
{
    synchronized(m_mxObjectNotify)
    {
        return m_pObjectNotify;
    }
}

void CSyncNotify::onSyncSourceEnd( int nSrc, VectorPtr<CSyncSource*>& sources )
{
    CSyncSource& src = *sources.elementAt(nSrc);

/*    if ( getSync().getState() == CSyncEngine::esStop && src.m_nErrCode != RhoAppAdapter.ERR_NONE )
    {
		CSyncNotification* pSN = getSyncNotifyBySrc(&src);
		if ( pSN != 0 )
			fireSyncNotification(&src, true, src.m_nErrCode, "");
		else
			fireAllSyncNotifications(true, src.m_nErrCode, src.m_strError, "" );
    }
    else*/
        fireSyncNotification(&src, true, src.m_nErrCode, "");

    cleanCreateObjectErrors();
}

void CSyncNotify::setSyncNotification(int source_id, CSyncNotification* pNotify )
{
    LOG(INFO) + "Set notification. Source ID: " + source_id + ";" + (pNotify ? pNotify->toString() : "");

	if ( source_id == -1 )
	{
		synchronized(m_mxSyncNotifications)
        {
            m_pAllNotification = pNotify;
        }
	}else
	{
        synchronized(m_mxSyncNotifications)
        {
            m_mapSyncNotifications.put( source_id, pNotify );
        }
    }
}

CSyncNotification::CSyncNotification(const apiGenerator::CMethodResult& callbackData, boolean bRemoveAfterFire) :
    m_callbackData(callbackData), m_cCallback(0), m_cCallbackData(0), m_bRemoveAfterFire(bRemoveAfterFire)
{
//    if ( m_callbackData.strUrl.length() > 0 )
//        m_callbackData.strUrl = RHODESAPPBASE().canonicalizeRhoUrl(m_callbackData.strUrl);
}

CSyncNotification::~CSyncNotification()
{
    if ( m_cCallbackData )
		rho_free_callbackdata(m_cCallbackData);
}
	
String CSyncNotification::toString()const
{
	if ( m_cCallback )
		return "C_Callback";
	
	String strRes = "Url :";
//	strRes += m_strUrl;
	strRes += "; Params: ";
//	strRes += m_strParams;
	return strRes;
}
    
CObjectNotification::CObjectNotification(const apiGenerator::CMethodResult& callbackData) :
   m_callbackData(callbackData), m_cCallback(0), m_cCallbackData(0)
{
}

CObjectNotification::~CObjectNotification()
{
    if ( m_cCallbackData )
        rho_free_callbackdata(m_cCallbackData);
}

String CObjectNotification::toString()const
{
    if ( m_cCallback )
        return "C_Callback";
    
    String strRes = "Url :";
//    strRes += m_callbackData.strUrl;
    return strRes;
}

void CSyncNotify::setSearchNotification(CSyncNotification* pNotify )
{
    LOG(INFO) + "Set search notification." + (pNotify ? pNotify->toString() : "");
    synchronized(m_mxSyncNotifications)
    {
        m_pSearchNotification = pNotify;
    }
}

void CSyncNotify::showStatusPopup(const String& status)
{
    LOG(INFO) + "Status: "+status;

    if ( m_strStatusHide.length() == 0 )
        m_strStatusHide = RhoAppAdapter.getMessageText("hide");

    if ( status.length() > 0 )
        alert_show_status("", status.c_str(), m_strStatusHide.c_str());
}

void CSyncNotify::reportSyncStatus(String status, int error, String strDetails) 
{
	synchronized(m_mxSyncNotifications)
	{    	
    	if (/*m_syncStatusListener != 0 && */(isReportingEnabled() || error == RhoAppAdapter.ERR_SYNCVERSION) ) {
    		
    		if ( error == RhoAppAdapter.ERR_SYNCVERSION )
            {
    			status = RhoAppAdapter.getErrorText(error);
                showStatusPopup(status);
            }
    		else if ( isReportingEnabled() )
    		{
	    		if ( strDetails.length() == 0 && error != RhoAppAdapter.ERR_NONE)
	    			strDetails = RhoAppAdapter.getErrorText(error);
	    		status += (strDetails.length() > 0 ? RhoAppAdapter.getMessageText("details") + strDetails: "");

        	    //m_syncStatusListener.reportStatus( status, error);
                showStatusPopup(status);
    		}
    	}
	}
}

void CSyncNotify::fireBulkSyncNotification( boolean bFinish, String status, String partition, int nErrCode )
{
    if ( getSync().getState() == CSyncEngine::esExit )
		return;

	if( nErrCode != RhoAppAdapter.ERR_NONE)
	{
		String strMessage = RhoAppAdapter.getMessageText("sync_failed_for") + "bulk.";
		reportSyncStatus(strMessage,nErrCode,"");
	}
	
	Hashtable<String,String> params;
	params.put("partition",partition);
	params.put("bulk_status",status);
	params.put("sync_type","bulk");

    doFireSyncNotification( 0, bFinish, nErrCode, "", &params, 0 );
}


void CSyncNotify::fireAllSyncNotifications( boolean bFinish, int nErrCode, String strError/*, String strServerError*/ )
{
    if ( getSync().getState() == CSyncEngine::esExit )
		return;

    synchronized(m_mxSyncNotifications)
    {
        CSyncNotification* pSN = getSyncNotifyBySrc(0);    
        if ( pSN != 0 )
            doFireSyncNotification( 0, bFinish, nErrCode, strError, 0, 0/*strServerError*/ );
    }
}


void CSyncNotify::fireSyncNotification( CSyncSource* src, boolean bFinish, int nErrCode, String strMessage)
{
    if ( getSync().getState() == CSyncEngine::esExit )
		return;
	
	if( strMessage.length() > 0 || nErrCode != RhoAppAdapter.ERR_NONE)
	{
		if ( !getSync().isSearch() )
        {
			if ( src != 0 && strMessage.length() == 0 )
				strMessage = RhoAppAdapter.getMessageText("sync_failed_for") + (*src).getName() + ".";
			
            reportSyncStatus(strMessage,nErrCode, (src != 0 ? (*src).m_strError : "") );
        }
	}

    doFireSyncNotification(src, bFinish, nErrCode, "", 0, 0 );
}

CSyncNotification* CSyncNotify::getSyncNotifyBySrc(CSyncSource* src)
{
    CSyncNotification* pSN = 0;
	if ( getSync().isSearch() )
		pSN = m_pSearchNotification;
	else
    {
        if ( src != 0 )
		    pSN = m_mapSyncNotifications.get( (*src).getID());

        if ( pSN == 0 )
            pSN = m_pAllNotification;
    }

	if ( pSN == 0 && !getSync().isNoThreadedMode() )
        return 0;

    return pSN != 0 ? pSN : &m_emptyNotify;
}

void CSyncNotify::fireSyncNotification2( CSyncSource* src, boolean bFinish, int nErrCode, const Hashtable<String,String>& serverErrors)
{
    doFireSyncNotification(src, bFinish, nErrCode, "", 0, &serverErrors);
}

void CSyncNotify::doFireSyncNotification( CSyncSource* src, boolean bFinish, int nErrCode, String strError, const Hashtable<String,String>* params, const Hashtable<String,String>* pServerErrors)
{
	if ( getSync().isStoppedByUser() )
		return;

    CSyncNotification* pSN;

	Hashtable<String, String> result;
	Hashtable<String, Hashtable<String,String> > errorsL2;
	
    boolean bRemoveAfterFire = bFinish;
    {
        synchronized(m_mxSyncNotifications)
        {
            pSN = getSyncNotifyBySrc(src);
	        if ( pSN == 0 )
                return;
			
			if ( params != 0 ) {
				result = *params;
			}else {
				result.put("sync_type","incremental");
			}

            if ( src != 0 )
            {
				result.put("total_count", convertToStringA( (*src).getTotalCount()));
				result.put("processed_count", convertToStringA( (*src).getTotalCount()));
				result.put("cumulative_count", convertToStringA( (*src).getCurPageCount()));
				result.put("source_id", convertToStringA( (*src).getID()));
				result.put("source_name", (*src).getName());
			}

			String status;
            if ( bFinish )
            {
                if ( nErrCode == RhoAppAdapter.ERR_NONE )
                {
                    if ( getSync().isSchemaChanged() )
                        status = "schema_changed";
                    else
                        status = (src == 0 && ( (params==0) || params->size()==0 ) ) ? "complete" : "ok";
                }
	            else
	            {
                    if ( getSync().isStoppedByUser() )
                        nErrCode = RhoAppAdapter.ERR_CANCELBYUSER;

					status = "error";
					
					result.put("error_code", convertToStringA(nErrCode) );
					
					String error;
					if ( strError.length() > 0 ) {
                        error = strError;
					} else if ( src != 0 ) {
                        error = (*src).m_strError;
					}
					
					result.put("error_message",error);
					
					if ( pServerErrors != 0 ) {
						errorsL2.put("server_errors",*pServerErrors);
					}
				}

                if ( src != 0 ) {
                    appendCreateObjectErrorInfo( (*src).getID(), errorsL2 );
				}
            } else {
        	    status = "in_progress";
			}
						   
			result.put("status",status);
						   			
            bRemoveAfterFire = bRemoveAfterFire && pSN->m_bRemoveAfterFire;
        }
    }
    LOG(INFO) + "Fire notification. Source : " + (src != 0 ? (*src).getName():"") + "; " + pSN->toString();
	
    if ( callNotify(*pSN, result, &errorsL2 ) || bRemoveAfterFire)
        clearNotification(src);
}

const String& CSyncNotify::getNotifyBody()
{
    const static String emptyBody = String();
    if ( m_arNotifyBody.size() == 0 )
        return emptyBody;

    if ( isFakeServerResponse() )
        return m_arNotifyBody[0];

    return m_arNotifyBody[m_arNotifyBody.size()-1];
}
	
	
String CSyncNotify::notifyParamToStr( const Hashtable<String,String>& result, const Hashtable< String, Hashtable< String, String > >* l2Hashes) {

	String ret = "";
    
    struct JSONCreator {
        static String& addCommaIfNeeded( String& result ) {
            result = String_trimRight(result);
            if ( (result.length()>0) && !(String_endsWith(result,"[" ) || String_endsWith(result,"{") ) ) { //|| String_endsWith(result,",")
                result += ",";
            }
            return result;
        }
        
        static String& addNode( const String& key, const String& value, bool jsonValue, String& result ) {
            addCommaIfNeeded(result);
            //String quote = jsonValue?"":"\"";
            result += "\"" + key + "\":" + (jsonValue?value: rho::json::CJSONEntry::quoteValue(value));
            return result;
        }
        
        static String& addNode( const Hashtable<String,String>& objects, const Hashtable< String, Hashtable< String, String > >* l2Hashes, String& result, bool skipComma = false ) {
            if ( !skipComma ) {
                addCommaIfNeeded(result);
            }
            
            //TODO : fix object notify with empty hash
            if ( (objects.size()==0) && ((l2Hashes==0) || (l2Hashes->size()==0)) ) {
                return result;
            }
            
            result += "{";

            for ( Hashtable<String,String>::const_iterator it = objects.begin(); it != objects.end(); ++it ) {
                String key = it->first;
                bool jsonValue = false;
                if ( String_endsWith(it->first,"-json")) {
                    jsonValue = true;
                    key = key.substr( 0, key.length() - 5 );
                }
                addNode( key, it->second, jsonValue, result );
            }
            
            if ( l2Hashes !=0 ) {
                if ( l2Hashes->size() > 0 ) {
                    addCommaIfNeeded(result);
                }

                for ( Hashtable< String, Hashtable< String, String > >::const_iterator it = l2Hashes->begin(); it != l2Hashes->end(); ++it ) {
                    //addCommaIfNeeded(result);
                    result += "\"" + it->first + "\":";
                    addNode( it->second, 0, result, true );
                }
            }
            
            result += "}";
            
            return result;
        }
        
    };
    
    JSONCreator::addNode( result, l2Hashes, ret );
    
	return ret;
}


boolean CSyncNotify::callNotify(const CSyncNotification& oNotify, const Hashtable<String, String>& result, const Hashtable<String,Hashtable<String,String> >* l2Hashes )
{
	apiGenerator::CMethodResult cb = oNotify.m_callbackData;
    
    String strBody = notifyParamToStr( result, l2Hashes );
	
    if ( getSync().isNoThreadedMode() )
    {
        m_arNotifyBody.addElement( strBody );
        return false;
    }
	
    if ( oNotify.m_cCallback )
    {
        m_isInsideCallback = true;        
        int nRet = (*oNotify.m_cCallback)(strBody.c_str(), oNotify.m_cCallbackData);
        m_isInsideCallback = false;
        return nRet == 1;
    }

	m_isInsideCallback = true;

	cb.setJSON(strBody);

    
	m_isInsideCallback = false;

	return true;
}

void CSyncNotify::clearNotification(CSyncSource* src)
{
    LOG(INFO) + "Clear notification. Source : " + (src != 0 ? (*src).getName() : "");

    synchronized(m_mxSyncNotifications)
    {
        if ( getSync().isSearch() )
            m_pSearchNotification = 0;
        else if ( src != 0 )
            m_mapSyncNotifications.remove( (*src).getID());
    }
}

void CSyncNotify::clearSyncNotification(int source_id) 
{
	LOG(INFO) + "Clear notification. Source ID: " + source_id;
	
    synchronized(m_mxSyncNotifications)
    {
        if ( source_id == -1 )//Clear all
            m_pAllNotification = 0;
        else
            m_mapSyncNotifications.remove(source_id);
    }
}

void CSyncNotify::cleanLastSyncObjectCount()
{
    synchronized(m_mxSyncNotifications)
    {
        m_hashSrcObjectCount.clear();
    }
}

int CSyncNotify::incLastSyncObjectCount(int nSrcID)
{
    int nCount = 0;
    synchronized(m_mxSyncNotifications)
    {
        nCount = m_hashSrcObjectCount.get(nSrcID)+1;
        m_hashSrcObjectCount.put(nSrcID,nCount);
    }

    return nCount;
}

int CSyncNotify::getLastSyncObjectCount(int nSrcID)
{
    int nCount = 0;
    synchronized(m_mxSyncNotifications)
    {
        nCount = m_hashSrcObjectCount.get(nSrcID);
    }

    return nCount;
}

void CSyncNotify::callLoginCallback(const CSyncNotification& oNotify, int nErrCode, String strMessage)
{
	if ( getSync().isStoppedByUser() )
		return;
	
	Hashtable<String, String> result;
	String strErrorCode = convertToStringA(nErrCode);
	String strEncodedMessage = strMessage;//URI::urlEncode(strMessage);
	
	result.put("error_code", strErrorCode);
	result.put("error_message", strEncodedMessage);

    LOG(INFO) + "Login callback: " + oNotify.toString() + ". Error code: "+ strErrorCode + ". Message: " + strEncodedMessage;

    callNotify(oNotify,result);
}

}
}

