#include "api_generator/js_helpers.h"

#include "logging/RhoLog.h"
#undef DEFAULT_LOGCATEGORY
#define DEFAULT_LOGCATEGORY "RhoConnectClient"


rho::String js_s_RhoConnectClient_getUserName(rho::json::CJSONArray& argv, const rho::String& strObjID);

rho::String js_s_RhoConnectClient_getPollInterval(rho::json::CJSONArray& argv, const rho::String& strObjID);

rho::String js_s_RhoConnectClient_setPollInterval(rho::json::CJSONArray& argv, const rho::String& strObjID);

rho::String js_s_RhoConnectClient_getSyncServer(rho::json::CJSONArray& argv, const rho::String& strObjID);

rho::String js_s_RhoConnectClient_setSyncServer(rho::json::CJSONArray& argv, const rho::String& strObjID);

rho::String js_s_RhoConnectClient_getPageSize(rho::json::CJSONArray& argv, const rho::String& strObjID);

rho::String js_s_RhoConnectClient_setPageSize(rho::json::CJSONArray& argv, const rho::String& strObjID);

rho::String js_s_RhoConnectClient_getThreadedMode(rho::json::CJSONArray& argv, const rho::String& strObjID);

rho::String js_s_RhoConnectClient_setThreadedMode(rho::json::CJSONArray& argv, const rho::String& strObjID);

rho::String js_s_RhoConnectClient_getShowStatusPopup(rho::json::CJSONArray& argv, const rho::String& strObjID);

rho::String js_s_RhoConnectClient_setShowStatusPopup(rho::json::CJSONArray& argv, const rho::String& strObjID);

rho::String js_s_RhoConnectClient_getSslVerifyPeer(rho::json::CJSONArray& argv, const rho::String& strObjID);

rho::String js_s_RhoConnectClient_setSslVerifyPeer(rho::json::CJSONArray& argv, const rho::String& strObjID);

rho::String js_s_RhoConnectClient_loggedIn(rho::json::CJSONArray& argv, const rho::String& strObjID);

rho::String js_s_RhoConnectClient_syncing(rho::json::CJSONArray& argv, const rho::String& strObjID);

rho::String js_s_RhoConnectClient_onSyncCreateError(rho::json::CJSONArray& argv, const rho::String& strObjID);

rho::String js_s_RhoConnectClient_pushChanges(rho::json::CJSONArray& argv, const rho::String& strObjID);

rho::String js_s_RhoConnectClient_onSyncUpdateError(rho::json::CJSONArray& argv, const rho::String& strObjID);

rho::String js_s_RhoConnectClient_onSyncDeleteError(rho::json::CJSONArray& argv, const rho::String& strObjID);

rho::String js_s_RhoConnectClient_search(rho::json::CJSONArray& argv, const rho::String& strObjID);

rho::String js_s_RhoConnectClient_doSync(rho::json::CJSONArray& argv, const rho::String& strObjID);

rho::String js_s_RhoConnectClient_doSyncSource(rho::json::CJSONArray& argv, const rho::String& strObjID);

rho::String js_s_RhoConnectClient_login(rho::json::CJSONArray& argv, const rho::String& strObjID);

rho::String js_s_RhoConnectClient_logout(rho::json::CJSONArray& argv, const rho::String& strObjID);

rho::String js_s_RhoConnectClient_stopSync(rho::json::CJSONArray& argv, const rho::String& strObjID);

rho::String js_s_RhoConnectClient_setNotification(rho::json::CJSONArray& argv, const rho::String& strObjID);

rho::String js_s_RhoConnectClient_clearNotification(rho::json::CJSONArray& argv, const rho::String& strObjID);

rho::String js_s_RhoConnectClient_setObjectNotification(rho::json::CJSONArray& argv, const rho::String& strObjID);

rho::String js_s_RhoConnectClient_addObjectNotify(rho::json::CJSONArray& argv, const rho::String& strObjID);

rho::String js_s_RhoConnectClient_cleanObjectNotify(rho::json::CJSONArray& argv, const rho::String& strObjID);

rho::String js_s_RhoConnectClient_getLastSyncObjectCount(rho::json::CJSONArray& argv, const rho::String& strObjID);

rho::String js_s_RhoConnectClient_setSourceProperty(rho::json::CJSONArray& argv, const rho::String& strObjID);

rho::String js_s_RhoConnectClient_getSourceProperty(rho::json::CJSONArray& argv, const rho::String& strObjID);





extern "C" void Init_JSAPI_RhoConnectClient(void)
{

    rho::apiGenerator::js_define_method("Rho:RhoConnectClient:userName", js_s_RhoConnectClient_getUserName);

    rho::apiGenerator::js_define_method("Rho:RhoConnectClient:pollInterval", js_s_RhoConnectClient_getPollInterval);

    rho::apiGenerator::js_define_method("Rho:RhoConnectClient:pollInterval=", js_s_RhoConnectClient_setPollInterval);

    rho::apiGenerator::js_define_method("Rho:RhoConnectClient:syncServer", js_s_RhoConnectClient_getSyncServer);

    rho::apiGenerator::js_define_method("Rho:RhoConnectClient:syncServer=", js_s_RhoConnectClient_setSyncServer);

    rho::apiGenerator::js_define_method("Rho:RhoConnectClient:pageSize", js_s_RhoConnectClient_getPageSize);

    rho::apiGenerator::js_define_method("Rho:RhoConnectClient:pageSize=", js_s_RhoConnectClient_setPageSize);

    rho::apiGenerator::js_define_method("Rho:RhoConnectClient:threadedMode?", js_s_RhoConnectClient_getThreadedMode);

    rho::apiGenerator::js_define_method("Rho:RhoConnectClient:threadedMode?=", js_s_RhoConnectClient_setThreadedMode);

    rho::apiGenerator::js_define_method("Rho:RhoConnectClient:showStatusPopup?", js_s_RhoConnectClient_getShowStatusPopup);

    rho::apiGenerator::js_define_method("Rho:RhoConnectClient:showStatusPopup?=", js_s_RhoConnectClient_setShowStatusPopup);

    rho::apiGenerator::js_define_method("Rho:RhoConnectClient:sslVerifyPeer?", js_s_RhoConnectClient_getSslVerifyPeer);

    rho::apiGenerator::js_define_method("Rho:RhoConnectClient:sslVerifyPeer?=", js_s_RhoConnectClient_setSslVerifyPeer);

    rho::apiGenerator::js_define_method("Rho:RhoConnectClient:loggedIn?", js_s_RhoConnectClient_loggedIn);

    rho::apiGenerator::js_define_method("Rho:RhoConnectClient:syncing?", js_s_RhoConnectClient_syncing);

    rho::apiGenerator::js_define_method("Rho:RhoConnectClient:onSyncCreateError", js_s_RhoConnectClient_onSyncCreateError);

    rho::apiGenerator::js_define_method("Rho:RhoConnectClient:pushChanges", js_s_RhoConnectClient_pushChanges);

    rho::apiGenerator::js_define_method("Rho:RhoConnectClient:onSyncUpdateError", js_s_RhoConnectClient_onSyncUpdateError);

    rho::apiGenerator::js_define_method("Rho:RhoConnectClient:onSyncDeleteError", js_s_RhoConnectClient_onSyncDeleteError);

    rho::apiGenerator::js_define_method("Rho:RhoConnectClient:search", js_s_RhoConnectClient_search);

    rho::apiGenerator::js_define_method("Rho:RhoConnectClient:doSync", js_s_RhoConnectClient_doSync);

    rho::apiGenerator::js_define_method("Rho:RhoConnectClient:doSyncSource", js_s_RhoConnectClient_doSyncSource);

    rho::apiGenerator::js_define_method("Rho:RhoConnectClient:login", js_s_RhoConnectClient_login);

    rho::apiGenerator::js_define_method("Rho:RhoConnectClient:logout", js_s_RhoConnectClient_logout);

    rho::apiGenerator::js_define_method("Rho:RhoConnectClient:stopSync", js_s_RhoConnectClient_stopSync);

    rho::apiGenerator::js_define_method("Rho:RhoConnectClient:setNotification", js_s_RhoConnectClient_setNotification);

    rho::apiGenerator::js_define_method("Rho:RhoConnectClient:clearNotification", js_s_RhoConnectClient_clearNotification);

    rho::apiGenerator::js_define_method("Rho:RhoConnectClient:setObjectNotification", js_s_RhoConnectClient_setObjectNotification);

    rho::apiGenerator::js_define_method("Rho:RhoConnectClient:addObjectNotify", js_s_RhoConnectClient_addObjectNotify);

    rho::apiGenerator::js_define_method("Rho:RhoConnectClient:cleanObjectNotify", js_s_RhoConnectClient_cleanObjectNotify);

    rho::apiGenerator::js_define_method("Rho:RhoConnectClient:getLastSyncObjectCount", js_s_RhoConnectClient_getLastSyncObjectCount);

    rho::apiGenerator::js_define_method("Rho:RhoConnectClient:setSourceProperty", js_s_RhoConnectClient_setSourceProperty);

    rho::apiGenerator::js_define_method("Rho:RhoConnectClient:getSourceProperty", js_s_RhoConnectClient_getSourceProperty);


}

