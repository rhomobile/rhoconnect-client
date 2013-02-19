package com.rho.rhoconnectclient;



import java.util.Map;
import java.util.List;

import com.rhomobile.rhodes.api.IMethodResult;


public interface IRhoConnectClientSingleton
 {

    void getUserName(IMethodResult result);     void getPollInterval(IMethodResult result);     void setPollInterval(int value, IMethodResult result);     void getSyncServer(IMethodResult result);     void setSyncServer(String value, IMethodResult result);     void getPageSize(IMethodResult result);     void setPageSize(int value, IMethodResult result);     void getThreadedMode(IMethodResult result);     void setThreadedMode(boolean value, IMethodResult result);     void getShowStatusPopup(IMethodResult result);     void setShowStatusPopup(boolean value, IMethodResult result);     void getSslVerifyPeer(IMethodResult result);     void setSslVerifyPeer(boolean value, IMethodResult result);     void loggedIn(IMethodResult result);     void syncing(IMethodResult result);     void onSyncCreateError(String srcName, List<String> objects, String action, IMethodResult result);     void pushChanges(String srcName, IMethodResult result);     void onSyncUpdateError(String srcName, List<String> objects, String action, String rollbackData, IMethodResult result);     void onSyncDeleteError(String srcName, List<String> objects, String action, IMethodResult result);     void search(Map<String, String> args, IMethodResult result);     void doSync(boolean showStatusPopup, String queryParams, boolean syncOnlyChangedSources, IMethodResult result);     void doSyncSource(String sourceName, boolean showStatusPopup, String queryParams, IMethodResult result);     void login(String login, String password, IMethodResult result);     void logout(IMethodResult result);     void stopSync(IMethodResult result);     void setNotification(String sourceName, IMethodResult result);     void clearNotification(String sourceName, IMethodResult result);     void setObjectNotification(IMethodResult result);     void addObjectNotify(String sourceName, String object, IMethodResult result);     void cleanObjectNotify(IMethodResult result);     void getLastSyncObjectCount(String sourceName, IMethodResult result);     void setSourceProperty(String sourceName, String propertyName, String propertyValue, IMethodResult result);     void getSourceProperty(String sourceName, String propertyName, IMethodResult result); 

}
