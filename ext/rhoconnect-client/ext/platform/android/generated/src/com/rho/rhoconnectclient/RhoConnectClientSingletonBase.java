package com.rho.rhoconnectclient;

import java.util.List;
import java.util.Map;

import com.rhomobile.rhodes.api.IMethodResult;

public abstract class RhoConnectClientSingletonBase  {


    public static class getUserNameTask implements Runnable {
        private IRhoConnectClientSingleton mApiSingleton; 
        private IMethodResult mResult;

        public getUserNameTask(IRhoConnectClientSingleton obj,         
                IMethodResult result) {
            this.mApiSingleton = obj;         
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiSingleton.getUserName( mResult);
        }
    }

    public static class getPollIntervalTask implements Runnable {
        private IRhoConnectClientSingleton mApiSingleton; 
        private IMethodResult mResult;

        public getPollIntervalTask(IRhoConnectClientSingleton obj,         
                IMethodResult result) {
            this.mApiSingleton = obj;         
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiSingleton.getPollInterval( mResult);
        }
    }

    public static class setPollIntervalTask implements Runnable {
        private IRhoConnectClientSingleton mApiSingleton; 
        private int value; 
        private IMethodResult mResult;

        public setPollIntervalTask(IRhoConnectClientSingleton obj, 
                int value,         
                IMethodResult result) {
            this.mApiSingleton = obj; 
            this.value = value;        
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiSingleton.setPollInterval(
                value,  mResult);
        }
    }

    public static class getSyncServerTask implements Runnable {
        private IRhoConnectClientSingleton mApiSingleton; 
        private IMethodResult mResult;

        public getSyncServerTask(IRhoConnectClientSingleton obj,         
                IMethodResult result) {
            this.mApiSingleton = obj;         
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiSingleton.getSyncServer( mResult);
        }
    }

    public static class setSyncServerTask implements Runnable {
        private IRhoConnectClientSingleton mApiSingleton; 
        private String value; 
        private IMethodResult mResult;

        public setSyncServerTask(IRhoConnectClientSingleton obj, 
                String value,         
                IMethodResult result) {
            this.mApiSingleton = obj; 
            this.value = value;        
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiSingleton.setSyncServer(
                value,  mResult);
        }
    }

    public static class getPageSizeTask implements Runnable {
        private IRhoConnectClientSingleton mApiSingleton; 
        private IMethodResult mResult;

        public getPageSizeTask(IRhoConnectClientSingleton obj,         
                IMethodResult result) {
            this.mApiSingleton = obj;         
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiSingleton.getPageSize( mResult);
        }
    }

    public static class setPageSizeTask implements Runnable {
        private IRhoConnectClientSingleton mApiSingleton; 
        private int value; 
        private IMethodResult mResult;

        public setPageSizeTask(IRhoConnectClientSingleton obj, 
                int value,         
                IMethodResult result) {
            this.mApiSingleton = obj; 
            this.value = value;        
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiSingleton.setPageSize(
                value,  mResult);
        }
    }

    public static class getThreadedModeTask implements Runnable {
        private IRhoConnectClientSingleton mApiSingleton; 
        private IMethodResult mResult;

        public getThreadedModeTask(IRhoConnectClientSingleton obj,         
                IMethodResult result) {
            this.mApiSingleton = obj;         
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiSingleton.getThreadedMode( mResult);
        }
    }

    public static class setThreadedModeTask implements Runnable {
        private IRhoConnectClientSingleton mApiSingleton; 
        private boolean value; 
        private IMethodResult mResult;

        public setThreadedModeTask(IRhoConnectClientSingleton obj, 
                boolean value,         
                IMethodResult result) {
            this.mApiSingleton = obj; 
            this.value = value;        
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiSingleton.setThreadedMode(
                value,  mResult);
        }
    }

    public static class getShowStatusPopupTask implements Runnable {
        private IRhoConnectClientSingleton mApiSingleton; 
        private IMethodResult mResult;

        public getShowStatusPopupTask(IRhoConnectClientSingleton obj,         
                IMethodResult result) {
            this.mApiSingleton = obj;         
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiSingleton.getShowStatusPopup( mResult);
        }
    }

    public static class setShowStatusPopupTask implements Runnable {
        private IRhoConnectClientSingleton mApiSingleton; 
        private boolean value; 
        private IMethodResult mResult;

        public setShowStatusPopupTask(IRhoConnectClientSingleton obj, 
                boolean value,         
                IMethodResult result) {
            this.mApiSingleton = obj; 
            this.value = value;        
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiSingleton.setShowStatusPopup(
                value,  mResult);
        }
    }

    public static class getSslVerifyPeerTask implements Runnable {
        private IRhoConnectClientSingleton mApiSingleton; 
        private IMethodResult mResult;

        public getSslVerifyPeerTask(IRhoConnectClientSingleton obj,         
                IMethodResult result) {
            this.mApiSingleton = obj;         
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiSingleton.getSslVerifyPeer( mResult);
        }
    }

    public static class setSslVerifyPeerTask implements Runnable {
        private IRhoConnectClientSingleton mApiSingleton; 
        private boolean value; 
        private IMethodResult mResult;

        public setSslVerifyPeerTask(IRhoConnectClientSingleton obj, 
                boolean value,         
                IMethodResult result) {
            this.mApiSingleton = obj; 
            this.value = value;        
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiSingleton.setSslVerifyPeer(
                value,  mResult);
        }
    }

    public static class loggedInTask implements Runnable {
        private IRhoConnectClientSingleton mApiSingleton; 
        private IMethodResult mResult;

        public loggedInTask(IRhoConnectClientSingleton obj,         
                IMethodResult result) {
            this.mApiSingleton = obj;         
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiSingleton.loggedIn( mResult);
        }
    }

    public static class syncingTask implements Runnable {
        private IRhoConnectClientSingleton mApiSingleton; 
        private IMethodResult mResult;

        public syncingTask(IRhoConnectClientSingleton obj,         
                IMethodResult result) {
            this.mApiSingleton = obj;         
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiSingleton.syncing( mResult);
        }
    }

    public static class onSyncCreateErrorTask implements Runnable {
        private IRhoConnectClientSingleton mApiSingleton; 
        private String srcName; 
        private List<String> objects; 
        private String action; 
        private IMethodResult mResult;

        public onSyncCreateErrorTask(IRhoConnectClientSingleton obj, 
                String srcName, 
                List<String> objects, 
                String action,         
                IMethodResult result) {
            this.mApiSingleton = obj; 
            this.srcName = srcName;
            this.objects = objects;
            this.action = action;        
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiSingleton.onSyncCreateError(
                srcName, 
                objects, 
                action,  mResult);
        }
    }

    public static class pushChangesTask implements Runnable {
        private IRhoConnectClientSingleton mApiSingleton; 
        private String srcName; 
        private IMethodResult mResult;

        public pushChangesTask(IRhoConnectClientSingleton obj, 
                String srcName,         
                IMethodResult result) {
            this.mApiSingleton = obj; 
            this.srcName = srcName;        
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiSingleton.pushChanges(
                srcName,  mResult);
        }
    }

    public static class onSyncUpdateErrorTask implements Runnable {
        private IRhoConnectClientSingleton mApiSingleton; 
        private String srcName; 
        private List<String> objects; 
        private String action; 
        private String rollbackData; 
        private IMethodResult mResult;

        public onSyncUpdateErrorTask(IRhoConnectClientSingleton obj, 
                String srcName, 
                List<String> objects, 
                String action, 
                String rollbackData,         
                IMethodResult result) {
            this.mApiSingleton = obj; 
            this.srcName = srcName;
            this.objects = objects;
            this.action = action;
            this.rollbackData = rollbackData;        
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiSingleton.onSyncUpdateError(
                srcName, 
                objects, 
                action, 
                rollbackData,  mResult);
        }
    }

    public static class onSyncDeleteErrorTask implements Runnable {
        private IRhoConnectClientSingleton mApiSingleton; 
        private String srcName; 
        private List<String> objects; 
        private String action; 
        private IMethodResult mResult;

        public onSyncDeleteErrorTask(IRhoConnectClientSingleton obj, 
                String srcName, 
                List<String> objects, 
                String action,         
                IMethodResult result) {
            this.mApiSingleton = obj; 
            this.srcName = srcName;
            this.objects = objects;
            this.action = action;        
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiSingleton.onSyncDeleteError(
                srcName, 
                objects, 
                action,  mResult);
        }
    }

    public static class searchTask implements Runnable {
        private IRhoConnectClientSingleton mApiSingleton; 
        private Map<String, String> args; 
        private IMethodResult mResult;

        public searchTask(IRhoConnectClientSingleton obj, 
                Map<String, String> args,         
                IMethodResult result) {
            this.mApiSingleton = obj; 
            this.args = args;        
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiSingleton.search(
                args,  mResult);
        }
    }

    public static class doSyncTask implements Runnable {
        private IRhoConnectClientSingleton mApiSingleton; 
        private boolean showStatusPopup; 
        private String queryParams; 
        private boolean syncOnlyChangedSources; 
        private IMethodResult mResult;

        public doSyncTask(IRhoConnectClientSingleton obj, 
                boolean showStatusPopup, 
                String queryParams, 
                boolean syncOnlyChangedSources,         
                IMethodResult result) {
            this.mApiSingleton = obj; 
            this.showStatusPopup = showStatusPopup;
            this.queryParams = queryParams;
            this.syncOnlyChangedSources = syncOnlyChangedSources;        
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiSingleton.doSync(
                showStatusPopup, 
                queryParams, 
                syncOnlyChangedSources,  mResult);
        }
    }

    public static class doSyncSourceTask implements Runnable {
        private IRhoConnectClientSingleton mApiSingleton; 
        private String sourceName; 
        private boolean showStatusPopup; 
        private String queryParams; 
        private IMethodResult mResult;

        public doSyncSourceTask(IRhoConnectClientSingleton obj, 
                String sourceName, 
                boolean showStatusPopup, 
                String queryParams,         
                IMethodResult result) {
            this.mApiSingleton = obj; 
            this.sourceName = sourceName;
            this.showStatusPopup = showStatusPopup;
            this.queryParams = queryParams;        
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiSingleton.doSyncSource(
                sourceName, 
                showStatusPopup, 
                queryParams,  mResult);
        }
    }

    public static class loginTask implements Runnable {
        private IRhoConnectClientSingleton mApiSingleton; 
        private String login; 
        private String password; 
        private IMethodResult mResult;

        public loginTask(IRhoConnectClientSingleton obj, 
                String login, 
                String password,         
                IMethodResult result) {
            this.mApiSingleton = obj; 
            this.login = login;
            this.password = password;        
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiSingleton.login(
                login, 
                password,  mResult);
        }
    }

    public static class logoutTask implements Runnable {
        private IRhoConnectClientSingleton mApiSingleton; 
        private IMethodResult mResult;

        public logoutTask(IRhoConnectClientSingleton obj,         
                IMethodResult result) {
            this.mApiSingleton = obj;         
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiSingleton.logout( mResult);
        }
    }

    public static class stopSyncTask implements Runnable {
        private IRhoConnectClientSingleton mApiSingleton; 
        private IMethodResult mResult;

        public stopSyncTask(IRhoConnectClientSingleton obj,         
                IMethodResult result) {
            this.mApiSingleton = obj;         
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiSingleton.stopSync( mResult);
        }
    }

    public static class setNotificationTask implements Runnable {
        private IRhoConnectClientSingleton mApiSingleton; 
        private String sourceName; 
        private IMethodResult mResult;

        public setNotificationTask(IRhoConnectClientSingleton obj, 
                String sourceName,         
                IMethodResult result) {
            this.mApiSingleton = obj; 
            this.sourceName = sourceName;        
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiSingleton.setNotification(
                sourceName,  mResult);
        }
    }

    public static class clearNotificationTask implements Runnable {
        private IRhoConnectClientSingleton mApiSingleton; 
        private String sourceName; 
        private IMethodResult mResult;

        public clearNotificationTask(IRhoConnectClientSingleton obj, 
                String sourceName,         
                IMethodResult result) {
            this.mApiSingleton = obj; 
            this.sourceName = sourceName;        
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiSingleton.clearNotification(
                sourceName,  mResult);
        }
    }

    public static class setObjectNotificationTask implements Runnable {
        private IRhoConnectClientSingleton mApiSingleton; 
        private IMethodResult mResult;

        public setObjectNotificationTask(IRhoConnectClientSingleton obj,         
                IMethodResult result) {
            this.mApiSingleton = obj;         
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiSingleton.setObjectNotification( mResult);
        }
    }

    public static class addObjectNotifyTask implements Runnable {
        private IRhoConnectClientSingleton mApiSingleton; 
        private String sourceName; 
        private String object; 
        private IMethodResult mResult;

        public addObjectNotifyTask(IRhoConnectClientSingleton obj, 
                String sourceName, 
                String object,         
                IMethodResult result) {
            this.mApiSingleton = obj; 
            this.sourceName = sourceName;
            this.object = object;        
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiSingleton.addObjectNotify(
                sourceName, 
                object,  mResult);
        }
    }

    public static class cleanObjectNotifyTask implements Runnable {
        private IRhoConnectClientSingleton mApiSingleton; 
        private IMethodResult mResult;

        public cleanObjectNotifyTask(IRhoConnectClientSingleton obj,         
                IMethodResult result) {
            this.mApiSingleton = obj;         
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiSingleton.cleanObjectNotify( mResult);
        }
    }

    public static class getLastSyncObjectCountTask implements Runnable {
        private IRhoConnectClientSingleton mApiSingleton; 
        private String sourceName; 
        private IMethodResult mResult;

        public getLastSyncObjectCountTask(IRhoConnectClientSingleton obj, 
                String sourceName,         
                IMethodResult result) {
            this.mApiSingleton = obj; 
            this.sourceName = sourceName;        
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiSingleton.getLastSyncObjectCount(
                sourceName,  mResult);
        }
    }

    public static class setSourcePropertyTask implements Runnable {
        private IRhoConnectClientSingleton mApiSingleton; 
        private String sourceName; 
        private String propertyName; 
        private String propertyValue; 
        private IMethodResult mResult;

        public setSourcePropertyTask(IRhoConnectClientSingleton obj, 
                String sourceName, 
                String propertyName, 
                String propertyValue,         
                IMethodResult result) {
            this.mApiSingleton = obj; 
            this.sourceName = sourceName;
            this.propertyName = propertyName;
            this.propertyValue = propertyValue;        
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiSingleton.setSourceProperty(
                sourceName, 
                propertyName, 
                propertyValue,  mResult);
        }
    }

    public static class getSourcePropertyTask implements Runnable {
        private IRhoConnectClientSingleton mApiSingleton; 
        private String sourceName; 
        private String propertyName; 
        private IMethodResult mResult;

        public getSourcePropertyTask(IRhoConnectClientSingleton obj, 
                String sourceName, 
                String propertyName,         
                IMethodResult result) {
            this.mApiSingleton = obj; 
            this.sourceName = sourceName;
            this.propertyName = propertyName;        
            this.mResult = result;
        }

        @Override
        public void run() {
            mApiSingleton.getSourceProperty(
                sourceName, 
                propertyName,  mResult);
        }
    }

    
}
