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

#pragma once

#include "common/RhoStd.h"
#include "common/IRhoClassFactory.h"
#include "common/RhoMutexLock.h"
#include "net/INetRequest.h"
#include "ISyncProtocol.h"

#include "SyncSource.h"
#include "SyncNotify.h"
#include "db/DBAdapter.h"
#include "logging/RhoLog.h"

namespace rho {
namespace sync {

class CSyncEngine : public net::IRhoSession
{
    DEFINE_LOGCLASS;
public:
    enum ESyncState{ esNone, esSyncAllSources, esSyncSource, esSearch, esStop, esExit };
	enum EBulkSyncState { ebsNotSynced = 0, ebsSynced = 1, ebsLoadBlobs = 2 };

    struct CSourceID
    {
        String m_strName;
        int m_nID;

        CSourceID(int id, const String& strName ){ m_nID = id; m_strName = strName; }
        CSourceID(const String& strName ){ m_strName = strName; }

        String toString()const;
        boolean isEqual(CSyncSource& src)const;
    };

    class CSourceOptions
    {
        common::CMutex m_mxSrcOptions;
        HashtablePtr<int, Hashtable<String,String>* > m_hashSrcOptions;
    public:
        void setProperty(int nSrcID, const char* szPropName, const char* szPropValue);
        String getProperty(int nSrcID, const char* szPropName);
        boolean getBoolProperty(int nSrcID, const char* szPropName);
        int getIntProperty(int nSrcID, const char* szPropName);
		void clearProperties();
    };

private:
    VectorPtr<CSyncSource*> m_sources;
    NetRequest m_NetRequest, m_NetRequestClientID;
    common::CAutoPtr<ISyncProtocol> m_SyncProtocol;
    ESyncState m_syncState;
    String     m_clientID;
    common::CMutex m_mxLoadClientID, m_mxSessionID;
    String m_strSession;
    CSyncNotify m_oSyncNotify;
    boolean m_bStopByUser;
    int m_nSyncPageSize;
	boolean m_bNoThreaded;
    int m_nErrCode;
    String m_strError;
    boolean m_bIsSearch, m_bIsSchemaChanged;
    static CSourceOptions m_oSourceOptions;

    net::CNetRequestWrapper getNetClientID(){ return getNetRequest(&m_NetRequestClientID); }

public:
    CSyncEngine();
    ~CSyncEngine(void){}

    static CSourceOptions& getSourceOptions(){ return m_oSourceOptions; }
    net::CNetRequestWrapper getNet(){ return getNetRequest(&m_NetRequest); }

    void doSyncAllSources(const String& strQueryParams, boolean bSyncOnlyChangedSources);
    void doSyncSource(const CSourceID& oSrcID, const String& strQueryParams);
    void doSearch(rho::Vector<rho::String>& arSources, String strParams, const String& from,  boolean bSearchSyncChanges, int nProgressStep);

    void login(String name, String password, const CSyncNotification& oNotify);
    boolean isLoggedIn();
    String loadSession();
    void logout();
    void logout_int();

	void setSyncServer(const char* syncserver);
    String getSyncServer() const;

    void setState(ESyncState eState){ m_syncState = eState; }
    ESyncState getState()const{ return m_syncState; }
    boolean isSearch()const{ return m_bIsSearch; }
    boolean isContinueSync()const{ return m_syncState != esExit && m_syncState != esStop; }
	boolean isSyncing()const{ return m_syncState == esSyncAllSources || m_syncState == esSyncSource || m_syncState == esSearch; }
    void stopSync(){ if (isContinueSync()){ setState(esStop); m_NetRequest.cancel();m_NetRequestClientID.cancel();} }
    void stopSyncByUser(){ m_bStopByUser = true; stopSync(); }
    void exitSync(){ setState(esExit); m_NetRequest.cancel(); m_NetRequestClientID.cancel();}
    boolean isStoppedByUser(){ return m_bStopByUser; }
    void setSslVerifyPeer(boolean b);

//private:
    String getClientID()const{ return m_clientID; }
    void setSession(String strSession){m_strSession=strSession;}
    boolean isSessionExist(){ return m_strSession.length() > 0; }

    void setSchemaChanged(boolean bChanged){ m_bIsSchemaChanged = bChanged; }
    boolean isSchemaChanged(){ return m_bIsSchemaChanged; }
//IRhoSession
    virtual const String& getSession()
    { 
        synchronized(m_mxSessionID){
            return m_strSession;
        }
    }
    virtual const String& getContentType(){ return getProtocol().getContentType();}

    void loadAllSources();
    void prepareSync(ESyncState eState, const CSourceID* oSrcID);

    VectorPtr<CSyncSource*>& getSources(){ return m_sources; }
    //int getStartSource();
    String loadClientID();
    String readClientID();
    String requestClientIDByNet();
    boolean resetClientIDByNet(const String& strClientID);//throws Exception
    void doBulkSync();//throws Exception

    CSyncNotify& getNotify(){ return m_oSyncNotify; }
    ISyncProtocol& getProtocol(){ return *m_SyncProtocol; }

    CSyncSource* findSourceByName(const String& strSrcName);
	CSyncSource* findSourceById(int srcId);


    int getSyncPageSize() { return m_nSyncPageSize; }
    void setSyncPageSize(int nPageSize){ m_nSyncPageSize = nPageSize; }

    boolean isNoThreadedMode(){ return m_bNoThreaded; }
    void setNonThreadedMode(boolean b){m_bNoThreaded = b;}

    void applyChangedValues(db::CDBAdapter& db);
private:
    
    bool recoverSearch( const String& strUrl, const String& strBody, int& errorCode, String& strError, int nProgressStep );

    CSyncSource* findSource(const CSourceID& oSrcID);

    void loadBulkPartition(const String& strPartition);
    String makeBulkDataFileName(String strDataUrl, String strDbPath, String strExt);
    db::CDBAdapter& getUserDB(){ return db::CDBAdapter::getUserDB(); }
    db::CDBAdapter& getDB(const String& strPartition){ return db::CDBAdapter::getDB(strPartition.c_str()); }

    void initProtocol();
    void processServerSources(String strSources);
    void checkSourceAssociations();

    void syncOneSource(int i, const String& strQueryParams, boolean bSyncOnlyIfChanged);
    void syncAllSources(const String& strQueryParams, boolean bSyncOnlyChangedSources);
	
	boolean processBlobs();
	void loadBulkPartitions();

    friend class CSyncSource;
};

}
}
