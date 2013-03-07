#include "RhoConnectClient.h"

#include "MethodResultJni.h"


namespace rho {

IMPLEMENT_LOGCLASS(CRhoConnectClientBase, "RhoConnectClientJNI");

using rhoelements::MethodExecutorJni;

//RhoConnectClientFactorySingleton staff
const char* const CRhoConnectClientBase::FACTORY_SINGLETON_CLASS = "com.rho.rhoconnectclient.RhoConnectClientFactorySingleton";
jclass CRhoConnectClientBase::s_clsFactorySingleton = 0;
jmethodID CRhoConnectClientBase::s_midFactorySetInstance;
jmethodID CRhoConnectClientBase::s_midFactoryGetInstance;

//RhoConnectClientFactory staff
const char* const CRhoConnectClientBase::IFACTORY_CLASS = "com.rho.rhoconnectclient.IRhoConnectClientFactory";
jclass CRhoConnectClientBase::s_clsIFactory = 0;
jmethodID CRhoConnectClientBase::s_midGetApiSingleton;
jmethodID CRhoConnectClientBase::s_midGetApiObject;

//RhoConnectClientSingletonBase staff
const char* const CRhoConnectClientBase::SINGLETON_BASE_CLASS = "com.rho.rhoconnectclient.RhoConnectClientSingletonBase";
jclass CRhoConnectClientBase::s_clsSingletonBase = 0;

//RhoConnectClientBase staff
const char* const CRhoConnectClientBase::OBJECT_BASE_CLASS = "com.rho.rhoconnectclient.RhoConnectClientBase";
jclass CRhoConnectClientBase::s_clsObjectBase = 0;



//Method tasks

const char* const CRhoConnectClientBase::GETUSERNAME_TASK_CLASS = 
        "com.rho.rhoconnectclient.RhoConnectClientSingletonBase$getUserNameTask";

jclass CRhoConnectClientBase::s_clsgetUserNameTask = 0;
jmethodID CRhoConnectClientBase::s_midgetUserNameTask;

const char* const CRhoConnectClientBase::GETPOLLINTERVAL_TASK_CLASS = 
        "com.rho.rhoconnectclient.RhoConnectClientSingletonBase$getPollIntervalTask";

jclass CRhoConnectClientBase::s_clsgetPollIntervalTask = 0;
jmethodID CRhoConnectClientBase::s_midgetPollIntervalTask;

const char* const CRhoConnectClientBase::SETPOLLINTERVAL_TASK_CLASS = 
        "com.rho.rhoconnectclient.RhoConnectClientSingletonBase$setPollIntervalTask";

jclass CRhoConnectClientBase::s_clssetPollIntervalTask = 0;
jmethodID CRhoConnectClientBase::s_midsetPollIntervalTask;

const char* const CRhoConnectClientBase::GETSYNCSERVER_TASK_CLASS = 
        "com.rho.rhoconnectclient.RhoConnectClientSingletonBase$getSyncServerTask";

jclass CRhoConnectClientBase::s_clsgetSyncServerTask = 0;
jmethodID CRhoConnectClientBase::s_midgetSyncServerTask;

const char* const CRhoConnectClientBase::SETSYNCSERVER_TASK_CLASS = 
        "com.rho.rhoconnectclient.RhoConnectClientSingletonBase$setSyncServerTask";

jclass CRhoConnectClientBase::s_clssetSyncServerTask = 0;
jmethodID CRhoConnectClientBase::s_midsetSyncServerTask;

const char* const CRhoConnectClientBase::GETPAGESIZE_TASK_CLASS = 
        "com.rho.rhoconnectclient.RhoConnectClientSingletonBase$getPageSizeTask";

jclass CRhoConnectClientBase::s_clsgetPageSizeTask = 0;
jmethodID CRhoConnectClientBase::s_midgetPageSizeTask;

const char* const CRhoConnectClientBase::SETPAGESIZE_TASK_CLASS = 
        "com.rho.rhoconnectclient.RhoConnectClientSingletonBase$setPageSizeTask";

jclass CRhoConnectClientBase::s_clssetPageSizeTask = 0;
jmethodID CRhoConnectClientBase::s_midsetPageSizeTask;

const char* const CRhoConnectClientBase::GETTHREADEDMODE_TASK_CLASS = 
        "com.rho.rhoconnectclient.RhoConnectClientSingletonBase$getThreadedModeTask";

jclass CRhoConnectClientBase::s_clsgetThreadedModeTask = 0;
jmethodID CRhoConnectClientBase::s_midgetThreadedModeTask;

const char* const CRhoConnectClientBase::SETTHREADEDMODE_TASK_CLASS = 
        "com.rho.rhoconnectclient.RhoConnectClientSingletonBase$setThreadedModeTask";

jclass CRhoConnectClientBase::s_clssetThreadedModeTask = 0;
jmethodID CRhoConnectClientBase::s_midsetThreadedModeTask;

const char* const CRhoConnectClientBase::GETSHOWSTATUSPOPUP_TASK_CLASS = 
        "com.rho.rhoconnectclient.RhoConnectClientSingletonBase$getShowStatusPopupTask";

jclass CRhoConnectClientBase::s_clsgetShowStatusPopupTask = 0;
jmethodID CRhoConnectClientBase::s_midgetShowStatusPopupTask;

const char* const CRhoConnectClientBase::SETSHOWSTATUSPOPUP_TASK_CLASS = 
        "com.rho.rhoconnectclient.RhoConnectClientSingletonBase$setShowStatusPopupTask";

jclass CRhoConnectClientBase::s_clssetShowStatusPopupTask = 0;
jmethodID CRhoConnectClientBase::s_midsetShowStatusPopupTask;

const char* const CRhoConnectClientBase::GETSSLVERIFYPEER_TASK_CLASS = 
        "com.rho.rhoconnectclient.RhoConnectClientSingletonBase$getSslVerifyPeerTask";

jclass CRhoConnectClientBase::s_clsgetSslVerifyPeerTask = 0;
jmethodID CRhoConnectClientBase::s_midgetSslVerifyPeerTask;

const char* const CRhoConnectClientBase::SETSSLVERIFYPEER_TASK_CLASS = 
        "com.rho.rhoconnectclient.RhoConnectClientSingletonBase$setSslVerifyPeerTask";

jclass CRhoConnectClientBase::s_clssetSslVerifyPeerTask = 0;
jmethodID CRhoConnectClientBase::s_midsetSslVerifyPeerTask;

const char* const CRhoConnectClientBase::LOGGEDIN_TASK_CLASS = 
        "com.rho.rhoconnectclient.RhoConnectClientSingletonBase$loggedInTask";

jclass CRhoConnectClientBase::s_clsloggedInTask = 0;
jmethodID CRhoConnectClientBase::s_midloggedInTask;

const char* const CRhoConnectClientBase::SYNCING_TASK_CLASS = 
        "com.rho.rhoconnectclient.RhoConnectClientSingletonBase$syncingTask";

jclass CRhoConnectClientBase::s_clssyncingTask = 0;
jmethodID CRhoConnectClientBase::s_midsyncingTask;

const char* const CRhoConnectClientBase::SEARCH_TASK_CLASS = 
        "com.rho.rhoconnectclient.RhoConnectClientSingletonBase$searchTask";

jclass CRhoConnectClientBase::s_clssearchTask = 0;
jmethodID CRhoConnectClientBase::s_midsearchTask;

const char* const CRhoConnectClientBase::DOSYNC_TASK_CLASS = 
        "com.rho.rhoconnectclient.RhoConnectClientSingletonBase$doSyncTask";

jclass CRhoConnectClientBase::s_clsdoSyncTask = 0;
jmethodID CRhoConnectClientBase::s_middoSyncTask;

const char* const CRhoConnectClientBase::DOSYNCSOURCE_TASK_CLASS = 
        "com.rho.rhoconnectclient.RhoConnectClientSingletonBase$doSyncSourceTask";

jclass CRhoConnectClientBase::s_clsdoSyncSourceTask = 0;
jmethodID CRhoConnectClientBase::s_middoSyncSourceTask;

const char* const CRhoConnectClientBase::LOGIN_TASK_CLASS = 
        "com.rho.rhoconnectclient.RhoConnectClientSingletonBase$loginTask";

jclass CRhoConnectClientBase::s_clsloginTask = 0;
jmethodID CRhoConnectClientBase::s_midloginTask;

const char* const CRhoConnectClientBase::LOGOUT_TASK_CLASS = 
        "com.rho.rhoconnectclient.RhoConnectClientSingletonBase$logoutTask";

jclass CRhoConnectClientBase::s_clslogoutTask = 0;
jmethodID CRhoConnectClientBase::s_midlogoutTask;

const char* const CRhoConnectClientBase::STOPSYNC_TASK_CLASS = 
        "com.rho.rhoconnectclient.RhoConnectClientSingletonBase$stopSyncTask";

jclass CRhoConnectClientBase::s_clsstopSyncTask = 0;
jmethodID CRhoConnectClientBase::s_midstopSyncTask;

const char* const CRhoConnectClientBase::SETNOTIFICATION_TASK_CLASS = 
        "com.rho.rhoconnectclient.RhoConnectClientSingletonBase$setNotificationTask";

jclass CRhoConnectClientBase::s_clssetNotificationTask = 0;
jmethodID CRhoConnectClientBase::s_midsetNotificationTask;

const char* const CRhoConnectClientBase::CLEARNOTIFICATION_TASK_CLASS = 
        "com.rho.rhoconnectclient.RhoConnectClientSingletonBase$clearNotificationTask";

jclass CRhoConnectClientBase::s_clsclearNotificationTask = 0;
jmethodID CRhoConnectClientBase::s_midclearNotificationTask;

const char* const CRhoConnectClientBase::SETOBJECTNOTIFICATION_TASK_CLASS = 
        "com.rho.rhoconnectclient.RhoConnectClientSingletonBase$setObjectNotificationTask";

jclass CRhoConnectClientBase::s_clssetObjectNotificationTask = 0;
jmethodID CRhoConnectClientBase::s_midsetObjectNotificationTask;

const char* const CRhoConnectClientBase::ADDOBJECTNOTIFY_TASK_CLASS = 
        "com.rho.rhoconnectclient.RhoConnectClientSingletonBase$addObjectNotifyTask";

jclass CRhoConnectClientBase::s_clsaddObjectNotifyTask = 0;
jmethodID CRhoConnectClientBase::s_midaddObjectNotifyTask;

const char* const CRhoConnectClientBase::CLEANOBJECTNOTIFY_TASK_CLASS = 
        "com.rho.rhoconnectclient.RhoConnectClientSingletonBase$cleanObjectNotifyTask";

jclass CRhoConnectClientBase::s_clscleanObjectNotifyTask = 0;
jmethodID CRhoConnectClientBase::s_midcleanObjectNotifyTask;

const char* const CRhoConnectClientBase::GETLASTSYNCOBJECTCOUNT_TASK_CLASS = 
        "com.rho.rhoconnectclient.RhoConnectClientSingletonBase$getLastSyncObjectCountTask";

jclass CRhoConnectClientBase::s_clsgetLastSyncObjectCountTask = 0;
jmethodID CRhoConnectClientBase::s_midgetLastSyncObjectCountTask;

const char* const CRhoConnectClientBase::SETSOURCEPROPERTY_TASK_CLASS = 
        "com.rho.rhoconnectclient.RhoConnectClientSingletonBase$setSourcePropertyTask";

jclass CRhoConnectClientBase::s_clssetSourcePropertyTask = 0;
jmethodID CRhoConnectClientBase::s_midsetSourcePropertyTask;

const char* const CRhoConnectClientBase::GETSOURCEPROPERTY_TASK_CLASS = 
        "com.rho.rhoconnectclient.RhoConnectClientSingletonBase$getSourcePropertyTask";

jclass CRhoConnectClientBase::s_clsgetSourcePropertyTask = 0;
jmethodID CRhoConnectClientBase::s_midgetSourcePropertyTask;


//----------------------------------------------------------------------------------------------------------------------

JNIEnv* CRhoConnectClientBase::jniInit()
{
    JNIEnv *env = jnienv();
    if(!env)
    {
        LOG(FATAL) + "JNI init failed: JNIEnv is null";
        return 0;
    }
    return jniInit(env);
}
//----------------------------------------------------------------------------------------------------------------------

JNIEnv* CRhoConnectClientBase::jniInit(JNIEnv* env)
{
    static bool initialized = false;
    env = MethodExecutorJni::jniInit(env);
    if (!env) {
        LOG(FATAL) + "JNI init failed";
        return 0;
    }

    if(!initialized)
    {
        //init RhoConnectClientFactorySingleton JNI
        s_clsFactorySingleton = loadClass(env, FACTORY_SINGLETON_CLASS);
        if (!s_clsFactorySingleton) return 0;

        s_midFactorySetInstance = env->GetStaticMethodID(s_clsFactorySingleton, "setInstance", "(Lcom/rho/rhoconnectclient/IRhoConnectClientFactory;)V");
        if(!s_midFactorySetInstance)
        {
            LOG(FATAL) + "Failed to get method 'setInstance' for java class " + FACTORY_SINGLETON_CLASS;
            return NULL;
        }
        s_midFactoryGetInstance = env->GetStaticMethodID(s_clsFactorySingleton, "getInstance", "()Lcom/rho/rhoconnectclient/IRhoConnectClientFactory;");
        if(!s_midFactoryGetInstance)
        {
            LOG(FATAL) + "Failed to get method 'getInstance' for java class " + FACTORY_SINGLETON_CLASS;
            return NULL;
        }

        //init IRhoConnectClientFactory JNI
        s_clsIFactory = loadClass(env, IFACTORY_CLASS);
        if (!s_clsIFactory) return 0;
        s_midGetApiSingleton = env->GetMethodID(s_clsIFactory, "getApiSingleton", "()Lcom/rho/rhoconnectclient/IRhoConnectClientSingleton;");
        if(!s_midGetApiSingleton)
        {
            LOG(FATAL) + "Failed to get method 'getApiSingleton' for java class " + IFACTORY_CLASS;
            return NULL;
        }
        s_midGetApiObject = env->GetMethodID(s_clsIFactory, "getApiObject", "(Ljava/lang/String;)Lcom/rho/rhoconnectclient/IRhoConnectClient;");
        if(!s_midGetApiObject)
        {
            LOG(FATAL) + "Failed to get method 'getApiObject' for java class " + IFACTORY_CLASS;
            return NULL;
        }

        s_clsSingletonBase = loadClass(env, SINGLETON_BASE_CLASS);
        if (!s_clsSingletonBase) return 0;
        s_clsObjectBase = loadClass(env, OBJECT_BASE_CLASS);
        if (!s_clsObjectBase) return 0;



        s_clsgetUserNameTask = loadClass(env, GETUSERNAME_TASK_CLASS);
        if (!s_clsgetUserNameTask) return 0;
        s_midgetUserNameTask = env->GetMethodID(s_clsgetUserNameTask, "<init>",
                        "(Lcom/rho/rhoconnectclient/IRhoConnectClientSingleton;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midgetUserNameTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + GETUSERNAME_TASK_CLASS;
            return NULL;
        }

        s_clsgetPollIntervalTask = loadClass(env, GETPOLLINTERVAL_TASK_CLASS);
        if (!s_clsgetPollIntervalTask) return 0;
        s_midgetPollIntervalTask = env->GetMethodID(s_clsgetPollIntervalTask, "<init>",
                        "(Lcom/rho/rhoconnectclient/IRhoConnectClientSingleton;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midgetPollIntervalTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + GETPOLLINTERVAL_TASK_CLASS;
            return NULL;
        }

        s_clssetPollIntervalTask = loadClass(env, SETPOLLINTERVAL_TASK_CLASS);
        if (!s_clssetPollIntervalTask) return 0;
        s_midsetPollIntervalTask = env->GetMethodID(s_clssetPollIntervalTask, "<init>",
                        "(Lcom/rho/rhoconnectclient/IRhoConnectClientSingleton;ILcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midsetPollIntervalTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + SETPOLLINTERVAL_TASK_CLASS;
            return NULL;
        }

        s_clsgetSyncServerTask = loadClass(env, GETSYNCSERVER_TASK_CLASS);
        if (!s_clsgetSyncServerTask) return 0;
        s_midgetSyncServerTask = env->GetMethodID(s_clsgetSyncServerTask, "<init>",
                        "(Lcom/rho/rhoconnectclient/IRhoConnectClientSingleton;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midgetSyncServerTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + GETSYNCSERVER_TASK_CLASS;
            return NULL;
        }

        s_clssetSyncServerTask = loadClass(env, SETSYNCSERVER_TASK_CLASS);
        if (!s_clssetSyncServerTask) return 0;
        s_midsetSyncServerTask = env->GetMethodID(s_clssetSyncServerTask, "<init>",
                        "(Lcom/rho/rhoconnectclient/IRhoConnectClientSingleton;Ljava/lang/String;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midsetSyncServerTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + SETSYNCSERVER_TASK_CLASS;
            return NULL;
        }

        s_clsgetPageSizeTask = loadClass(env, GETPAGESIZE_TASK_CLASS);
        if (!s_clsgetPageSizeTask) return 0;
        s_midgetPageSizeTask = env->GetMethodID(s_clsgetPageSizeTask, "<init>",
                        "(Lcom/rho/rhoconnectclient/IRhoConnectClientSingleton;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midgetPageSizeTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + GETPAGESIZE_TASK_CLASS;
            return NULL;
        }

        s_clssetPageSizeTask = loadClass(env, SETPAGESIZE_TASK_CLASS);
        if (!s_clssetPageSizeTask) return 0;
        s_midsetPageSizeTask = env->GetMethodID(s_clssetPageSizeTask, "<init>",
                        "(Lcom/rho/rhoconnectclient/IRhoConnectClientSingleton;ILcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midsetPageSizeTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + SETPAGESIZE_TASK_CLASS;
            return NULL;
        }

        s_clsgetThreadedModeTask = loadClass(env, GETTHREADEDMODE_TASK_CLASS);
        if (!s_clsgetThreadedModeTask) return 0;
        s_midgetThreadedModeTask = env->GetMethodID(s_clsgetThreadedModeTask, "<init>",
                        "(Lcom/rho/rhoconnectclient/IRhoConnectClientSingleton;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midgetThreadedModeTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + GETTHREADEDMODE_TASK_CLASS;
            return NULL;
        }

        s_clssetThreadedModeTask = loadClass(env, SETTHREADEDMODE_TASK_CLASS);
        if (!s_clssetThreadedModeTask) return 0;
        s_midsetThreadedModeTask = env->GetMethodID(s_clssetThreadedModeTask, "<init>",
                        "(Lcom/rho/rhoconnectclient/IRhoConnectClientSingleton;ZLcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midsetThreadedModeTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + SETTHREADEDMODE_TASK_CLASS;
            return NULL;
        }

        s_clsgetShowStatusPopupTask = loadClass(env, GETSHOWSTATUSPOPUP_TASK_CLASS);
        if (!s_clsgetShowStatusPopupTask) return 0;
        s_midgetShowStatusPopupTask = env->GetMethodID(s_clsgetShowStatusPopupTask, "<init>",
                        "(Lcom/rho/rhoconnectclient/IRhoConnectClientSingleton;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midgetShowStatusPopupTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + GETSHOWSTATUSPOPUP_TASK_CLASS;
            return NULL;
        }

        s_clssetShowStatusPopupTask = loadClass(env, SETSHOWSTATUSPOPUP_TASK_CLASS);
        if (!s_clssetShowStatusPopupTask) return 0;
        s_midsetShowStatusPopupTask = env->GetMethodID(s_clssetShowStatusPopupTask, "<init>",
                        "(Lcom/rho/rhoconnectclient/IRhoConnectClientSingleton;ZLcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midsetShowStatusPopupTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + SETSHOWSTATUSPOPUP_TASK_CLASS;
            return NULL;
        }

        s_clsgetSslVerifyPeerTask = loadClass(env, GETSSLVERIFYPEER_TASK_CLASS);
        if (!s_clsgetSslVerifyPeerTask) return 0;
        s_midgetSslVerifyPeerTask = env->GetMethodID(s_clsgetSslVerifyPeerTask, "<init>",
                        "(Lcom/rho/rhoconnectclient/IRhoConnectClientSingleton;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midgetSslVerifyPeerTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + GETSSLVERIFYPEER_TASK_CLASS;
            return NULL;
        }

        s_clssetSslVerifyPeerTask = loadClass(env, SETSSLVERIFYPEER_TASK_CLASS);
        if (!s_clssetSslVerifyPeerTask) return 0;
        s_midsetSslVerifyPeerTask = env->GetMethodID(s_clssetSslVerifyPeerTask, "<init>",
                        "(Lcom/rho/rhoconnectclient/IRhoConnectClientSingleton;ZLcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midsetSslVerifyPeerTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + SETSSLVERIFYPEER_TASK_CLASS;
            return NULL;
        }

        s_clsloggedInTask = loadClass(env, LOGGEDIN_TASK_CLASS);
        if (!s_clsloggedInTask) return 0;
        s_midloggedInTask = env->GetMethodID(s_clsloggedInTask, "<init>",
                        "(Lcom/rho/rhoconnectclient/IRhoConnectClientSingleton;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midloggedInTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + LOGGEDIN_TASK_CLASS;
            return NULL;
        }

        s_clssyncingTask = loadClass(env, SYNCING_TASK_CLASS);
        if (!s_clssyncingTask) return 0;
        s_midsyncingTask = env->GetMethodID(s_clssyncingTask, "<init>",
                        "(Lcom/rho/rhoconnectclient/IRhoConnectClientSingleton;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midsyncingTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + SYNCING_TASK_CLASS;
            return NULL;
        }

        s_clssearchTask = loadClass(env, SEARCH_TASK_CLASS);
        if (!s_clssearchTask) return 0;
        s_midsearchTask = env->GetMethodID(s_clssearchTask, "<init>",
                        "(Lcom/rho/rhoconnectclient/IRhoConnectClientSingleton;Ljava/util/Map;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midsearchTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + SEARCH_TASK_CLASS;
            return NULL;
        }

        s_clsdoSyncTask = loadClass(env, DOSYNC_TASK_CLASS);
        if (!s_clsdoSyncTask) return 0;
        s_middoSyncTask = env->GetMethodID(s_clsdoSyncTask, "<init>",
                        "(Lcom/rho/rhoconnectclient/IRhoConnectClientSingleton;ZLjava/lang/String;ZLcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_middoSyncTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + DOSYNC_TASK_CLASS;
            return NULL;
        }

        s_clsdoSyncSourceTask = loadClass(env, DOSYNCSOURCE_TASK_CLASS);
        if (!s_clsdoSyncSourceTask) return 0;
        s_middoSyncSourceTask = env->GetMethodID(s_clsdoSyncSourceTask, "<init>",
                        "(Lcom/rho/rhoconnectclient/IRhoConnectClientSingleton;Ljava/lang/String;ZLjava/lang/String;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_middoSyncSourceTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + DOSYNCSOURCE_TASK_CLASS;
            return NULL;
        }

        s_clsloginTask = loadClass(env, LOGIN_TASK_CLASS);
        if (!s_clsloginTask) return 0;
        s_midloginTask = env->GetMethodID(s_clsloginTask, "<init>",
                        "(Lcom/rho/rhoconnectclient/IRhoConnectClientSingleton;Ljava/lang/String;Ljava/lang/String;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midloginTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + LOGIN_TASK_CLASS;
            return NULL;
        }

        s_clslogoutTask = loadClass(env, LOGOUT_TASK_CLASS);
        if (!s_clslogoutTask) return 0;
        s_midlogoutTask = env->GetMethodID(s_clslogoutTask, "<init>",
                        "(Lcom/rho/rhoconnectclient/IRhoConnectClientSingleton;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midlogoutTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + LOGOUT_TASK_CLASS;
            return NULL;
        }

        s_clsstopSyncTask = loadClass(env, STOPSYNC_TASK_CLASS);
        if (!s_clsstopSyncTask) return 0;
        s_midstopSyncTask = env->GetMethodID(s_clsstopSyncTask, "<init>",
                        "(Lcom/rho/rhoconnectclient/IRhoConnectClientSingleton;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midstopSyncTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + STOPSYNC_TASK_CLASS;
            return NULL;
        }

        s_clssetNotificationTask = loadClass(env, SETNOTIFICATION_TASK_CLASS);
        if (!s_clssetNotificationTask) return 0;
        s_midsetNotificationTask = env->GetMethodID(s_clssetNotificationTask, "<init>",
                        "(Lcom/rho/rhoconnectclient/IRhoConnectClientSingleton;Ljava/lang/String;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midsetNotificationTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + SETNOTIFICATION_TASK_CLASS;
            return NULL;
        }

        s_clsclearNotificationTask = loadClass(env, CLEARNOTIFICATION_TASK_CLASS);
        if (!s_clsclearNotificationTask) return 0;
        s_midclearNotificationTask = env->GetMethodID(s_clsclearNotificationTask, "<init>",
                        "(Lcom/rho/rhoconnectclient/IRhoConnectClientSingleton;Ljava/lang/String;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midclearNotificationTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + CLEARNOTIFICATION_TASK_CLASS;
            return NULL;
        }

        s_clssetObjectNotificationTask = loadClass(env, SETOBJECTNOTIFICATION_TASK_CLASS);
        if (!s_clssetObjectNotificationTask) return 0;
        s_midsetObjectNotificationTask = env->GetMethodID(s_clssetObjectNotificationTask, "<init>",
                        "(Lcom/rho/rhoconnectclient/IRhoConnectClientSingleton;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midsetObjectNotificationTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + SETOBJECTNOTIFICATION_TASK_CLASS;
            return NULL;
        }

        s_clsaddObjectNotifyTask = loadClass(env, ADDOBJECTNOTIFY_TASK_CLASS);
        if (!s_clsaddObjectNotifyTask) return 0;
        s_midaddObjectNotifyTask = env->GetMethodID(s_clsaddObjectNotifyTask, "<init>",
                        "(Lcom/rho/rhoconnectclient/IRhoConnectClientSingleton;Ljava/lang/String;Ljava/lang/String;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midaddObjectNotifyTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + ADDOBJECTNOTIFY_TASK_CLASS;
            return NULL;
        }

        s_clscleanObjectNotifyTask = loadClass(env, CLEANOBJECTNOTIFY_TASK_CLASS);
        if (!s_clscleanObjectNotifyTask) return 0;
        s_midcleanObjectNotifyTask = env->GetMethodID(s_clscleanObjectNotifyTask, "<init>",
                        "(Lcom/rho/rhoconnectclient/IRhoConnectClientSingleton;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midcleanObjectNotifyTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + CLEANOBJECTNOTIFY_TASK_CLASS;
            return NULL;
        }

        s_clsgetLastSyncObjectCountTask = loadClass(env, GETLASTSYNCOBJECTCOUNT_TASK_CLASS);
        if (!s_clsgetLastSyncObjectCountTask) return 0;
        s_midgetLastSyncObjectCountTask = env->GetMethodID(s_clsgetLastSyncObjectCountTask, "<init>",
                        "(Lcom/rho/rhoconnectclient/IRhoConnectClientSingleton;Ljava/lang/String;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midgetLastSyncObjectCountTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + GETLASTSYNCOBJECTCOUNT_TASK_CLASS;
            return NULL;
        }

        s_clssetSourcePropertyTask = loadClass(env, SETSOURCEPROPERTY_TASK_CLASS);
        if (!s_clssetSourcePropertyTask) return 0;
        s_midsetSourcePropertyTask = env->GetMethodID(s_clssetSourcePropertyTask, "<init>",
                        "(Lcom/rho/rhoconnectclient/IRhoConnectClientSingleton;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midsetSourcePropertyTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + SETSOURCEPROPERTY_TASK_CLASS;
            return NULL;
        }

        s_clsgetSourcePropertyTask = loadClass(env, GETSOURCEPROPERTY_TASK_CLASS);
        if (!s_clsgetSourcePropertyTask) return 0;
        s_midgetSourcePropertyTask = env->GetMethodID(s_clsgetSourcePropertyTask, "<init>",
                        "(Lcom/rho/rhoconnectclient/IRhoConnectClientSingleton;Ljava/lang/String;Ljava/lang/String;Lcom/rhomobile/rhodes/api/IMethodResult;)V");
        if(!s_midgetSourcePropertyTask)
        {
            LOG(FATAL) + "Failed to get constructor for java class " + GETSOURCEPROPERTY_TASK_CLASS;
            return NULL;
        }



        initialized = true;
        LOG(TRACE) + "CRhoConnectClient JNI init succeeded";
    }
    return env;
}
//----------------------------------------------------------------------------------------------------------------------

void CRhoConnectClientBase::setJavaFactory(JNIEnv* env, jobject jFactory)
{
    LOG(TRACE) + "setJavaFactory";

    env = jniInit(env);
    if (!env) {
        LOG(FATAL) + "JNI initialization failed";
        return;
    }

    env->CallStaticVoidMethod(s_clsFactorySingleton, s_midFactorySetInstance, jFactory);

    LOG(TRACE) + "setJavaFactory succeeded";
}
//----------------------------------------------------------------------------------------------------------------------

jobject CRhoConnectClientBase::getFactory(JNIEnv* env)
{
    jobject res = env->CallStaticObjectMethod(s_clsFactorySingleton, s_midFactoryGetInstance);
    return res;
}
//----------------------------------------------------------------------------------------------------------------------

jobject CRhoConnectClientBase::getSingleton(JNIEnv* env)
{
    jhobject jhFactory = getFactory(env);
    jobject res = env->CallObjectMethod(jhFactory.get(), s_midGetApiSingleton);
    return res;
}
//----------------------------------------------------------------------------------------------------------------------

jobject CRhoConnectClientBase::getObject(JNIEnv* env)
{
    jhstring jhId = rho_cast<jstring>(env, m_id);
    jhobject jhFactory = getFactory(env);
    jobject res = env->CallObjectMethod(jhFactory.get(), s_midGetApiObject, jhId.get());
    return res;
}
//----------------------------------------------------------------------------------------------------------------------


}
