#include "RhoConnectClient.h"

#include "MethodResultJni.h"
#include "api_generator/MethodResult.h"

#include "logging/RhoLog.h"
#undef DEFAULT_LOGCATEGORY
#define DEFAULT_LOGCATEGORY "RhoConnectClientJS"

#include "rhodes/JNIRhoJS.h"

typedef rho::CRhoConnectClientProxy<ArgumentsAdapter<rho::json::CJSONArray> > ObjectProxy;

using namespace rhoelements;



rho::String js_s_RhoConnectClient_getUserName(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toJson();
    }


    int argc = argv.getSize();
    if((argc < 0) || (argc > 0))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toJson();
    }
    
    if(argc > 0)
    {
        if(argc > 1)
            result.setCallBack(argv[0], argv[1]);
        else
            result.setCallBack(argv[0]);
    
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toJson();
        }
    }

    ObjectProxy::getUserName(argumentsAdapter(argv), result); 
    rho::String res = 
        result.toJson();

    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_s_RhoConnectClient_getPollInterval(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toJson();
    }


    int argc = argv.getSize();
    if((argc < 0) || (argc > 0))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toJson();
    }
    
    if(argc > 0)
    {
        if(argc > 1)
            result.setCallBack(argv[0], argv[1]);
        else
            result.setCallBack(argv[0]);
    
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toJson();
        }
    }

    ObjectProxy::getPollInterval(argumentsAdapter(argv), result); 
    rho::String res = 
        result.toJson();

    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_s_RhoConnectClient_setPollInterval(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toJson();
    }


    int argc = argv.getSize();
    if((argc < 1) || (argc > 1))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toJson();
    }
    
    if(argc > 1)
    {
        if(argc > 2)
            result.setCallBack(argv[1], argv[2]);
        else
            result.setCallBack(argv[1]);
    
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toJson();
        }
    }

    ObjectProxy::setPollInterval(argumentsAdapter(argv), result); 
    rho::String res = 
        result.toJson();

    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_s_RhoConnectClient_getSyncServer(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toJson();
    }


    int argc = argv.getSize();
    if((argc < 0) || (argc > 0))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toJson();
    }
    
    if(argc > 0)
    {
        if(argc > 1)
            result.setCallBack(argv[0], argv[1]);
        else
            result.setCallBack(argv[0]);
    
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toJson();
        }
    }

    ObjectProxy::getSyncServer(argumentsAdapter(argv), result); 
    rho::String res = 
        result.toJson();

    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_s_RhoConnectClient_setSyncServer(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toJson();
    }


    int argc = argv.getSize();
    if((argc < 1) || (argc > 1))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toJson();
    }
    
    if(argc > 1)
    {
        if(argc > 2)
            result.setCallBack(argv[1], argv[2]);
        else
            result.setCallBack(argv[1]);
    
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toJson();
        }
    }

    ObjectProxy::setSyncServer(argumentsAdapter(argv), result); 
    rho::String res = 
        result.toJson();

    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_s_RhoConnectClient_getPageSize(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toJson();
    }


    int argc = argv.getSize();
    if((argc < 0) || (argc > 0))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toJson();
    }
    
    if(argc > 0)
    {
        if(argc > 1)
            result.setCallBack(argv[0], argv[1]);
        else
            result.setCallBack(argv[0]);
    
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toJson();
        }
    }

    ObjectProxy::getPageSize(argumentsAdapter(argv), result); 
    rho::String res = 
        result.toJson();

    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_s_RhoConnectClient_setPageSize(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toJson();
    }


    int argc = argv.getSize();
    if((argc < 1) || (argc > 1))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toJson();
    }
    
    if(argc > 1)
    {
        if(argc > 2)
            result.setCallBack(argv[1], argv[2]);
        else
            result.setCallBack(argv[1]);
    
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toJson();
        }
    }

    ObjectProxy::setPageSize(argumentsAdapter(argv), result); 
    rho::String res = 
        result.toJson();

    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_s_RhoConnectClient_getThreadedMode(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toJson();
    }


    int argc = argv.getSize();
    if((argc < 0) || (argc > 0))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toJson();
    }
    
    if(argc > 0)
    {
        if(argc > 1)
            result.setCallBack(argv[0], argv[1]);
        else
            result.setCallBack(argv[0]);
    
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toJson();
        }
    }

    ObjectProxy::getThreadedMode(argumentsAdapter(argv), result); 
    rho::String res = 
        result.toJson();

    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_s_RhoConnectClient_setThreadedMode(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toJson();
    }


    int argc = argv.getSize();
    if((argc < 1) || (argc > 1))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toJson();
    }
    
    if(argc > 1)
    {
        if(argc > 2)
            result.setCallBack(argv[1], argv[2]);
        else
            result.setCallBack(argv[1]);
    
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toJson();
        }
    }

    ObjectProxy::setThreadedMode(argumentsAdapter(argv), result); 
    rho::String res = 
        result.toJson();

    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_s_RhoConnectClient_getShowStatusPopup(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toJson();
    }


    int argc = argv.getSize();
    if((argc < 0) || (argc > 0))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toJson();
    }
    
    if(argc > 0)
    {
        if(argc > 1)
            result.setCallBack(argv[0], argv[1]);
        else
            result.setCallBack(argv[0]);
    
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toJson();
        }
    }

    ObjectProxy::getShowStatusPopup(argumentsAdapter(argv), result); 
    rho::String res = 
        result.toJson();

    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_s_RhoConnectClient_setShowStatusPopup(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toJson();
    }


    int argc = argv.getSize();
    if((argc < 1) || (argc > 1))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toJson();
    }
    
    if(argc > 1)
    {
        if(argc > 2)
            result.setCallBack(argv[1], argv[2]);
        else
            result.setCallBack(argv[1]);
    
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toJson();
        }
    }

    ObjectProxy::setShowStatusPopup(argumentsAdapter(argv), result); 
    rho::String res = 
        result.toJson();

    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_s_RhoConnectClient_getSslVerifyPeer(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toJson();
    }


    int argc = argv.getSize();
    if((argc < 0) || (argc > 0))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toJson();
    }
    
    if(argc > 0)
    {
        if(argc > 1)
            result.setCallBack(argv[0], argv[1]);
        else
            result.setCallBack(argv[0]);
    
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toJson();
        }
    }

    ObjectProxy::getSslVerifyPeer(argumentsAdapter(argv), result); 
    rho::String res = 
        result.toJson();

    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_s_RhoConnectClient_setSslVerifyPeer(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toJson();
    }


    int argc = argv.getSize();
    if((argc < 1) || (argc > 1))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toJson();
    }
    
    if(argc > 1)
    {
        if(argc > 2)
            result.setCallBack(argv[1], argv[2]);
        else
            result.setCallBack(argv[1]);
    
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toJson();
        }
    }

    ObjectProxy::setSslVerifyPeer(argumentsAdapter(argv), result); 
    rho::String res = 
        result.toJson();

    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_s_RhoConnectClient_loggedIn(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toJson();
    }


    int argc = argv.getSize();
    if((argc < 0) || (argc > 0))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toJson();
    }
    
    if(argc > 0)
    {
        if(argc > 1)
            result.setCallBack(argv[0], argv[1]);
        else
            result.setCallBack(argv[0]);
    
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toJson();
        }
    }

    ObjectProxy::loggedIn(argumentsAdapter(argv), result); 
    rho::String res = 
        result.toJson();

    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_s_RhoConnectClient_syncing(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toJson();
    }


    int argc = argv.getSize();
    if((argc < 0) || (argc > 0))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toJson();
    }
    
    if(argc > 0)
    {
        if(argc > 1)
            result.setCallBack(argv[0], argv[1]);
        else
            result.setCallBack(argv[0]);
    
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toJson();
        }
    }

    ObjectProxy::syncing(argumentsAdapter(argv), result); 
    rho::String res = 
        result.toJson();

    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_s_RhoConnectClient_onSyncCreateError(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toJson();
    }


    int argc = argv.getSize();
    if((argc < 3) || (argc > 3))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toJson();
    }
    
    if(argc > 3)
    {
        if(argc > 4)
            result.setCallBack(argv[3], argv[4]);
        else
            result.setCallBack(argv[3]);
    
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toJson();
        }
    }

    ObjectProxy::onSyncCreateError(argumentsAdapter(argv), result); 
    rho::String res = 
        result.toJson();

    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_s_RhoConnectClient_pushChanges(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toJson();
    }


    int argc = argv.getSize();
    if((argc < 1) || (argc > 1))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toJson();
    }
    
    if(argc > 1)
    {
        if(argc > 2)
            result.setCallBack(argv[1], argv[2]);
        else
            result.setCallBack(argv[1]);
    
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toJson();
        }
    }

    ObjectProxy::pushChanges(argumentsAdapter(argv), result); 
    rho::String res = 
        result.toJson();

    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_s_RhoConnectClient_onSyncUpdateError(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toJson();
    }


    int argc = argv.getSize();
    if((argc < 3) || (argc > 4))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toJson();
    }
    
    if(argc > 4)
    {
        if(argc > 5)
            result.setCallBack(argv[4], argv[5]);
        else
            result.setCallBack(argv[4]);
    
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toJson();
        }
    }

    ObjectProxy::onSyncUpdateError(argumentsAdapter(argv), result); 
    rho::String res = 
        result.toJson();

    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_s_RhoConnectClient_onSyncDeleteError(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toJson();
    }


    int argc = argv.getSize();
    if((argc < 3) || (argc > 3))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toJson();
    }
    
    if(argc > 3)
    {
        if(argc > 4)
            result.setCallBack(argv[3], argv[4]);
        else
            result.setCallBack(argv[3]);
    
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toJson();
        }
    }

    ObjectProxy::onSyncDeleteError(argumentsAdapter(argv), result); 
    rho::String res = 
        result.toJson();

    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_s_RhoConnectClient_search(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toJson();
    }


    int argc = argv.getSize();
    if((argc < 2) || (argc > 3))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toJson();
    }
    
    if(argc > 1)
    {
        if(argc > 2)
            result.setCallBack(argv[1], argv[2]);
        else
            result.setCallBack(argv[1]);
    
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toJson();
        }
    }

    ObjectProxy::search(argumentsAdapter(argv), result); 
    rho::String res = 
        result.toJson();

    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_s_RhoConnectClient_doSync(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toJson();
    }


    int argc = argv.getSize();
    if((argc < 3) || (argc > 3))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toJson();
    }
    
    if(argc > 3)
    {
        if(argc > 4)
            result.setCallBack(argv[3], argv[4]);
        else
            result.setCallBack(argv[3]);
    
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toJson();
        }
    }

    ObjectProxy::doSync(argumentsAdapter(argv), result); 
    rho::String res = 
        result.toJson();

    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_s_RhoConnectClient_doSyncSource(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toJson();
    }


    int argc = argv.getSize();
    if((argc < 1) || (argc > 3))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toJson();
    }
    
    if(argc > 3)
    {
        if(argc > 4)
            result.setCallBack(argv[3], argv[4]);
        else
            result.setCallBack(argv[3]);
    
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toJson();
        }
    }

    ObjectProxy::doSyncSource(argumentsAdapter(argv), result); 
    rho::String res = 
        result.toJson();

    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_s_RhoConnectClient_login(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toJson();
    }


    int argc = argv.getSize();
    if((argc < 3) || (argc > 4))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toJson();
    }
    
    if(argc > 2)
    {
        if(argc > 3)
            result.setCallBack(argv[2], argv[3]);
        else
            result.setCallBack(argv[2]);
    
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toJson();
        }
    }

    ObjectProxy::login(argumentsAdapter(argv), result); 
    rho::String res = 
        result.toJson();

    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_s_RhoConnectClient_logout(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toJson();
    }


    int argc = argv.getSize();
    if((argc < 0) || (argc > 0))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toJson();
    }
    
    if(argc > 0)
    {
        if(argc > 1)
            result.setCallBack(argv[0], argv[1]);
        else
            result.setCallBack(argv[0]);
    
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toJson();
        }
    }

    ObjectProxy::logout(argumentsAdapter(argv), result); 
    rho::String res = 
        result.toJson();

    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_s_RhoConnectClient_stopSync(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toJson();
    }


    int argc = argv.getSize();
    if((argc < 0) || (argc > 0))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toJson();
    }
    
    if(argc > 0)
    {
        if(argc > 1)
            result.setCallBack(argv[0], argv[1]);
        else
            result.setCallBack(argv[0]);
    
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toJson();
        }
    }

    ObjectProxy::stopSync(argumentsAdapter(argv), result); 
    rho::String res = 
        result.toJson();

    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_s_RhoConnectClient_setNotification(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toJson();
    }


    int argc = argv.getSize();
    if((argc < 2) || (argc > 3))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toJson();
    }
    
    if(argc > 1)
    {
        if(argc > 2)
            result.setCallBack(argv[1], argv[2]);
        else
            result.setCallBack(argv[1]);
    
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toJson();
        }
    }

    ObjectProxy::setNotification(argumentsAdapter(argv), result); 
    rho::String res = 
        result.toJson();

    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_s_RhoConnectClient_clearNotification(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toJson();
    }


    int argc = argv.getSize();
    if((argc < 1) || (argc > 1))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toJson();
    }
    
    if(argc > 1)
    {
        if(argc > 2)
            result.setCallBack(argv[1], argv[2]);
        else
            result.setCallBack(argv[1]);
    
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toJson();
        }
    }

    ObjectProxy::clearNotification(argumentsAdapter(argv), result); 
    rho::String res = 
        result.toJson();

    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_s_RhoConnectClient_setObjectNotification(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toJson();
    }


    int argc = argv.getSize();
    if((argc < 1) || (argc > 2))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toJson();
    }
    
    if(argc > 0)
    {
        if(argc > 1)
            result.setCallBack(argv[0], argv[1]);
        else
            result.setCallBack(argv[0]);
    
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toJson();
        }
    }

    ObjectProxy::setObjectNotification(argumentsAdapter(argv), result); 
    rho::String res = 
        result.toJson();

    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_s_RhoConnectClient_addObjectNotify(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toJson();
    }


    int argc = argv.getSize();
    if((argc < 2) || (argc > 2))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toJson();
    }
    
    if(argc > 2)
    {
        if(argc > 3)
            result.setCallBack(argv[2], argv[3]);
        else
            result.setCallBack(argv[2]);
    
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toJson();
        }
    }

    ObjectProxy::addObjectNotify(argumentsAdapter(argv), result); 
    rho::String res = 
        result.toJson();

    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_s_RhoConnectClient_cleanObjectNotify(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toJson();
    }


    int argc = argv.getSize();
    if((argc < 0) || (argc > 0))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toJson();
    }
    
    if(argc > 0)
    {
        if(argc > 1)
            result.setCallBack(argv[0], argv[1]);
        else
            result.setCallBack(argv[0]);
    
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toJson();
        }
    }

    ObjectProxy::cleanObjectNotify(argumentsAdapter(argv), result); 
    rho::String res = 
        result.toJson();

    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_s_RhoConnectClient_getLastSyncObjectCount(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toJson();
    }


    int argc = argv.getSize();
    if((argc < 1) || (argc > 1))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toJson();
    }
    
    if(argc > 1)
    {
        if(argc > 2)
            result.setCallBack(argv[1], argv[2]);
        else
            result.setCallBack(argv[1]);
    
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toJson();
        }
    }

    ObjectProxy::getLastSyncObjectCount(argumentsAdapter(argv), result); 
    rho::String res = 
        result.toJson();

    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_s_RhoConnectClient_setSourceProperty(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toJson();
    }


    int argc = argv.getSize();
    if((argc < 3) || (argc > 3))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toJson();
    }
    
    if(argc > 3)
    {
        if(argc > 4)
            result.setCallBack(argv[3], argv[4]);
        else
            result.setCallBack(argv[3]);
    
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toJson();
        }
    }

    ObjectProxy::setSourceProperty(argumentsAdapter(argv), result); 
    rho::String res = 
        result.toJson();

    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
rho::String js_s_RhoConnectClient_getSourceProperty(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    RAWTRACE2("%s(id=%s)", __FUNCTION__, strObjID.c_str());

    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toJson();
    }


    int argc = argv.getSize();
    if((argc < 2) || (argc > 2))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toJson();
    }
    
    if(argc > 2)
    {
        if(argc > 3)
            result.setCallBack(argv[2], argv[3]);
        else
            result.setCallBack(argv[2]);
    
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toJson();
        }
    }

    ObjectProxy::getSourceProperty(argumentsAdapter(argv), result); 
    rho::String res = 
        result.toJson();

    RAWTRACE2("%s(id=%s) end ^^^", __FUNCTION__, strObjID.c_str());
    return res;
}
