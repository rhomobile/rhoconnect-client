#include "RhoConnectClient.h"

#include "MethodResultJni.h"

#include "logging/RhoLog.h"
#undef DEFAULT_LOGCATEGORY
#define DEFAULT_LOGCATEGORY "RhoConnectClientRUBY"

#include "ext/rho/rhoruby.h"
#include "rhodes/JNIRhoRuby.h"

typedef rho::CRhoConnectClientProxy<ArgumentsAdapter<std::vector<VALUE> > > ObjectProxy;

using namespace rhoelements;
extern "C"
{

VALUE getRuby_RhoConnectClient_Module();




VALUE rb_s_RhoConnectClient_getUserName(int argc, VALUE *argv)
{
    RAWTRACE(__FUNCTION__);
    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toRuby();
    }


    if((argc < 0) || (argc > 0))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toRuby();
    }
    
    unsigned realParamCount = (argc < 0) ? argc : 0;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    if(argc > 0)
    {
        if (rho_ruby_is_proc(argv[0]) || rho_ruby_is_method(argv[0]))
        {
            result.setRubyProcCallBack(argv[0]);
        } else
        {
            if(argc > 1)
                result.setCallBack(argv[0], argv[1]);
            else
                result.setCallBack(argv[0]);
    
        }
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toRuby();
        }
    }

    ObjectProxy::getUserName(argumentsAdapter(arguments), result); 
    VALUE res = 
        result.toRuby();

    RAWTRACE(__FUNCTION__);
    return res;
}

VALUE rb_s_RhoConnectClient_getPollInterval(int argc, VALUE *argv)
{
    RAWTRACE(__FUNCTION__);
    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toRuby();
    }


    if((argc < 0) || (argc > 0))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toRuby();
    }
    
    unsigned realParamCount = (argc < 0) ? argc : 0;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    if(argc > 0)
    {
        if (rho_ruby_is_proc(argv[0]) || rho_ruby_is_method(argv[0]))
        {
            result.setRubyProcCallBack(argv[0]);
        } else
        {
            if(argc > 1)
                result.setCallBack(argv[0], argv[1]);
            else
                result.setCallBack(argv[0]);
    
        }
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toRuby();
        }
    }

    ObjectProxy::getPollInterval(argumentsAdapter(arguments), result); 
    VALUE res = 
        result.toRuby();

    RAWTRACE(__FUNCTION__);
    return res;
}

VALUE rb_s_RhoConnectClient_setPollInterval(int argc, VALUE *argv)
{
    RAWTRACE(__FUNCTION__);
    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toRuby();
    }


    if((argc < 1) || (argc > 1))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toRuby();
    }
    
    unsigned realParamCount = (argc < 1) ? argc : 1;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    if(argc > 1)
    {
        if (rho_ruby_is_proc(argv[1]) || rho_ruby_is_method(argv[1]))
        {
            result.setRubyProcCallBack(argv[1]);
        } else
        {
            if(argc > 2)
                result.setCallBack(argv[1], argv[2]);
            else
                result.setCallBack(argv[1]);
    
        }
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toRuby();
        }
    }

    ObjectProxy::setPollInterval(argumentsAdapter(arguments), result); 
    VALUE res = 
        result.toRuby();

    RAWTRACE(__FUNCTION__);
    return res;
}

VALUE rb_s_RhoConnectClient_getSyncServer(int argc, VALUE *argv)
{
    RAWTRACE(__FUNCTION__);
    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toRuby();
    }


    if((argc < 0) || (argc > 0))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toRuby();
    }
    
    unsigned realParamCount = (argc < 0) ? argc : 0;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    if(argc > 0)
    {
        if (rho_ruby_is_proc(argv[0]) || rho_ruby_is_method(argv[0]))
        {
            result.setRubyProcCallBack(argv[0]);
        } else
        {
            if(argc > 1)
                result.setCallBack(argv[0], argv[1]);
            else
                result.setCallBack(argv[0]);
    
        }
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toRuby();
        }
    }

    ObjectProxy::getSyncServer(argumentsAdapter(arguments), result); 
    VALUE res = 
        result.toRuby();

    RAWTRACE(__FUNCTION__);
    return res;
}

VALUE rb_s_RhoConnectClient_setSyncServer(int argc, VALUE *argv)
{
    RAWTRACE(__FUNCTION__);
    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toRuby();
    }


    if((argc < 1) || (argc > 1))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toRuby();
    }
    
    unsigned realParamCount = (argc < 1) ? argc : 1;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    if(argc > 1)
    {
        if (rho_ruby_is_proc(argv[1]) || rho_ruby_is_method(argv[1]))
        {
            result.setRubyProcCallBack(argv[1]);
        } else
        {
            if(argc > 2)
                result.setCallBack(argv[1], argv[2]);
            else
                result.setCallBack(argv[1]);
    
        }
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toRuby();
        }
    }

    ObjectProxy::setSyncServer(argumentsAdapter(arguments), result); 
    VALUE res = 
        result.toRuby();

    RAWTRACE(__FUNCTION__);
    return res;
}

VALUE rb_s_RhoConnectClient_getPageSize(int argc, VALUE *argv)
{
    RAWTRACE(__FUNCTION__);
    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toRuby();
    }


    if((argc < 0) || (argc > 0))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toRuby();
    }
    
    unsigned realParamCount = (argc < 0) ? argc : 0;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    if(argc > 0)
    {
        if (rho_ruby_is_proc(argv[0]) || rho_ruby_is_method(argv[0]))
        {
            result.setRubyProcCallBack(argv[0]);
        } else
        {
            if(argc > 1)
                result.setCallBack(argv[0], argv[1]);
            else
                result.setCallBack(argv[0]);
    
        }
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toRuby();
        }
    }

    ObjectProxy::getPageSize(argumentsAdapter(arguments), result); 
    VALUE res = 
        result.toRuby();

    RAWTRACE(__FUNCTION__);
    return res;
}

VALUE rb_s_RhoConnectClient_setPageSize(int argc, VALUE *argv)
{
    RAWTRACE(__FUNCTION__);
    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toRuby();
    }


    if((argc < 1) || (argc > 1))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toRuby();
    }
    
    unsigned realParamCount = (argc < 1) ? argc : 1;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    if(argc > 1)
    {
        if (rho_ruby_is_proc(argv[1]) || rho_ruby_is_method(argv[1]))
        {
            result.setRubyProcCallBack(argv[1]);
        } else
        {
            if(argc > 2)
                result.setCallBack(argv[1], argv[2]);
            else
                result.setCallBack(argv[1]);
    
        }
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toRuby();
        }
    }

    ObjectProxy::setPageSize(argumentsAdapter(arguments), result); 
    VALUE res = 
        result.toRuby();

    RAWTRACE(__FUNCTION__);
    return res;
}

VALUE rb_s_RhoConnectClient_getThreadedMode(int argc, VALUE *argv)
{
    RAWTRACE(__FUNCTION__);
    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toRuby();
    }


    if((argc < 0) || (argc > 0))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toRuby();
    }
    
    unsigned realParamCount = (argc < 0) ? argc : 0;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    if(argc > 0)
    {
        if (rho_ruby_is_proc(argv[0]) || rho_ruby_is_method(argv[0]))
        {
            result.setRubyProcCallBack(argv[0]);
        } else
        {
            if(argc > 1)
                result.setCallBack(argv[0], argv[1]);
            else
                result.setCallBack(argv[0]);
    
        }
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toRuby();
        }
    }

    ObjectProxy::getThreadedMode(argumentsAdapter(arguments), result); 
    VALUE res = 
        result.toRuby();

    RAWTRACE(__FUNCTION__);
    return res;
}

VALUE rb_s_RhoConnectClient_setThreadedMode(int argc, VALUE *argv)
{
    RAWTRACE(__FUNCTION__);
    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toRuby();
    }


    if((argc < 1) || (argc > 1))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toRuby();
    }
    
    unsigned realParamCount = (argc < 1) ? argc : 1;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    if(argc > 1)
    {
        if (rho_ruby_is_proc(argv[1]) || rho_ruby_is_method(argv[1]))
        {
            result.setRubyProcCallBack(argv[1]);
        } else
        {
            if(argc > 2)
                result.setCallBack(argv[1], argv[2]);
            else
                result.setCallBack(argv[1]);
    
        }
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toRuby();
        }
    }

    ObjectProxy::setThreadedMode(argumentsAdapter(arguments), result); 
    VALUE res = 
        result.toRuby();

    RAWTRACE(__FUNCTION__);
    return res;
}

VALUE rb_s_RhoConnectClient_getShowStatusPopup(int argc, VALUE *argv)
{
    RAWTRACE(__FUNCTION__);
    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toRuby();
    }


    if((argc < 0) || (argc > 0))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toRuby();
    }
    
    unsigned realParamCount = (argc < 0) ? argc : 0;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    if(argc > 0)
    {
        if (rho_ruby_is_proc(argv[0]) || rho_ruby_is_method(argv[0]))
        {
            result.setRubyProcCallBack(argv[0]);
        } else
        {
            if(argc > 1)
                result.setCallBack(argv[0], argv[1]);
            else
                result.setCallBack(argv[0]);
    
        }
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toRuby();
        }
    }

    ObjectProxy::getShowStatusPopup(argumentsAdapter(arguments), result); 
    VALUE res = 
        result.toRuby();

    RAWTRACE(__FUNCTION__);
    return res;
}

VALUE rb_s_RhoConnectClient_setShowStatusPopup(int argc, VALUE *argv)
{
    RAWTRACE(__FUNCTION__);
    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toRuby();
    }


    if((argc < 1) || (argc > 1))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toRuby();
    }
    
    unsigned realParamCount = (argc < 1) ? argc : 1;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    if(argc > 1)
    {
        if (rho_ruby_is_proc(argv[1]) || rho_ruby_is_method(argv[1]))
        {
            result.setRubyProcCallBack(argv[1]);
        } else
        {
            if(argc > 2)
                result.setCallBack(argv[1], argv[2]);
            else
                result.setCallBack(argv[1]);
    
        }
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toRuby();
        }
    }

    ObjectProxy::setShowStatusPopup(argumentsAdapter(arguments), result); 
    VALUE res = 
        result.toRuby();

    RAWTRACE(__FUNCTION__);
    return res;
}

VALUE rb_s_RhoConnectClient_getSslVerifyPeer(int argc, VALUE *argv)
{
    RAWTRACE(__FUNCTION__);
    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toRuby();
    }


    if((argc < 0) || (argc > 0))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toRuby();
    }
    
    unsigned realParamCount = (argc < 0) ? argc : 0;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    if(argc > 0)
    {
        if (rho_ruby_is_proc(argv[0]) || rho_ruby_is_method(argv[0]))
        {
            result.setRubyProcCallBack(argv[0]);
        } else
        {
            if(argc > 1)
                result.setCallBack(argv[0], argv[1]);
            else
                result.setCallBack(argv[0]);
    
        }
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toRuby();
        }
    }

    ObjectProxy::getSslVerifyPeer(argumentsAdapter(arguments), result); 
    VALUE res = 
        result.toRuby();

    RAWTRACE(__FUNCTION__);
    return res;
}

VALUE rb_s_RhoConnectClient_setSslVerifyPeer(int argc, VALUE *argv)
{
    RAWTRACE(__FUNCTION__);
    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toRuby();
    }


    if((argc < 1) || (argc > 1))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toRuby();
    }
    
    unsigned realParamCount = (argc < 1) ? argc : 1;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    if(argc > 1)
    {
        if (rho_ruby_is_proc(argv[1]) || rho_ruby_is_method(argv[1]))
        {
            result.setRubyProcCallBack(argv[1]);
        } else
        {
            if(argc > 2)
                result.setCallBack(argv[1], argv[2]);
            else
                result.setCallBack(argv[1]);
    
        }
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toRuby();
        }
    }

    ObjectProxy::setSslVerifyPeer(argumentsAdapter(arguments), result); 
    VALUE res = 
        result.toRuby();

    RAWTRACE(__FUNCTION__);
    return res;
}

VALUE rb_s_RhoConnectClient_loggedIn(int argc, VALUE *argv)
{
    RAWTRACE(__FUNCTION__);
    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toRuby();
    }


    if((argc < 0) || (argc > 0))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toRuby();
    }
    
    unsigned realParamCount = (argc < 0) ? argc : 0;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    if(argc > 0)
    {
        if (rho_ruby_is_proc(argv[0]) || rho_ruby_is_method(argv[0]))
        {
            result.setRubyProcCallBack(argv[0]);
        } else
        {
            if(argc > 1)
                result.setCallBack(argv[0], argv[1]);
            else
                result.setCallBack(argv[0]);
    
        }
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toRuby();
        }
    }

    ObjectProxy::loggedIn(argumentsAdapter(arguments), result); 
    VALUE res = 
        result.toRuby();

    RAWTRACE(__FUNCTION__);
    return res;
}

VALUE rb_s_RhoConnectClient_syncing(int argc, VALUE *argv)
{
    RAWTRACE(__FUNCTION__);
    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toRuby();
    }


    if((argc < 0) || (argc > 0))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toRuby();
    }
    
    unsigned realParamCount = (argc < 0) ? argc : 0;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    if(argc > 0)
    {
        if (rho_ruby_is_proc(argv[0]) || rho_ruby_is_method(argv[0]))
        {
            result.setRubyProcCallBack(argv[0]);
        } else
        {
            if(argc > 1)
                result.setCallBack(argv[0], argv[1]);
            else
                result.setCallBack(argv[0]);
    
        }
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toRuby();
        }
    }

    ObjectProxy::syncing(argumentsAdapter(arguments), result); 
    VALUE res = 
        result.toRuby();

    RAWTRACE(__FUNCTION__);
    return res;
}

VALUE rb_s_RhoConnectClient_onSyncCreateError(int argc, VALUE *argv)
{
    RAWTRACE(__FUNCTION__);
    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toRuby();
    }


    if((argc < 3) || (argc > 3))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toRuby();
    }
    
    unsigned realParamCount = (argc < 3) ? argc : 3;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    if(argc > 3)
    {
        if (rho_ruby_is_proc(argv[3]) || rho_ruby_is_method(argv[3]))
        {
            result.setRubyProcCallBack(argv[3]);
        } else
        {
            if(argc > 4)
                result.setCallBack(argv[3], argv[4]);
            else
                result.setCallBack(argv[3]);
    
        }
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toRuby();
        }
    }

    ObjectProxy::onSyncCreateError(argumentsAdapter(arguments), result); 
    VALUE res = 
        result.toRuby();

    RAWTRACE(__FUNCTION__);
    return res;
}

VALUE rb_s_RhoConnectClient_pushChanges(int argc, VALUE *argv)
{
    RAWTRACE(__FUNCTION__);
    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toRuby();
    }


    if((argc < 1) || (argc > 1))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toRuby();
    }
    
    unsigned realParamCount = (argc < 1) ? argc : 1;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    if(argc > 1)
    {
        if (rho_ruby_is_proc(argv[1]) || rho_ruby_is_method(argv[1]))
        {
            result.setRubyProcCallBack(argv[1]);
        } else
        {
            if(argc > 2)
                result.setCallBack(argv[1], argv[2]);
            else
                result.setCallBack(argv[1]);
    
        }
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toRuby();
        }
    }

    ObjectProxy::pushChanges(argumentsAdapter(arguments), result); 
    VALUE res = 
        result.toRuby();

    RAWTRACE(__FUNCTION__);
    return res;
}

VALUE rb_s_RhoConnectClient_onSyncUpdateError(int argc, VALUE *argv)
{
    RAWTRACE(__FUNCTION__);
    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toRuby();
    }


    if((argc < 3) || (argc > 4))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toRuby();
    }
    
    unsigned realParamCount = (argc < 4) ? argc : 4;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    if(argc > 4)
    {
        if (rho_ruby_is_proc(argv[4]) || rho_ruby_is_method(argv[4]))
        {
            result.setRubyProcCallBack(argv[4]);
        } else
        {
            if(argc > 5)
                result.setCallBack(argv[4], argv[5]);
            else
                result.setCallBack(argv[4]);
    
        }
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toRuby();
        }
    }

    ObjectProxy::onSyncUpdateError(argumentsAdapter(arguments), result); 
    VALUE res = 
        result.toRuby();

    RAWTRACE(__FUNCTION__);
    return res;
}

VALUE rb_s_RhoConnectClient_onSyncDeleteError(int argc, VALUE *argv)
{
    RAWTRACE(__FUNCTION__);
    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toRuby();
    }


    if((argc < 3) || (argc > 3))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toRuby();
    }
    
    unsigned realParamCount = (argc < 3) ? argc : 3;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    if(argc > 3)
    {
        if (rho_ruby_is_proc(argv[3]) || rho_ruby_is_method(argv[3]))
        {
            result.setRubyProcCallBack(argv[3]);
        } else
        {
            if(argc > 4)
                result.setCallBack(argv[3], argv[4]);
            else
                result.setCallBack(argv[3]);
    
        }
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toRuby();
        }
    }

    ObjectProxy::onSyncDeleteError(argumentsAdapter(arguments), result); 
    VALUE res = 
        result.toRuby();

    RAWTRACE(__FUNCTION__);
    return res;
}

VALUE rb_s_RhoConnectClient_search(int argc, VALUE *argv)
{
    RAWTRACE(__FUNCTION__);
    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toRuby();
    }


    if((argc < 2) || (argc > 3))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toRuby();
    }
    
    unsigned realParamCount = (argc < 1) ? argc : 1;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    if(argc > 1)
    {
        if (rho_ruby_is_proc(argv[1]) || rho_ruby_is_method(argv[1]))
        {
            result.setRubyProcCallBack(argv[1]);
        } else
        {
            if(argc > 2)
                result.setCallBack(argv[1], argv[2]);
            else
                result.setCallBack(argv[1]);
    
        }
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toRuby();
        }
    }

    ObjectProxy::search(argumentsAdapter(arguments), result); 
    VALUE res = 
        result.toRuby();

    RAWTRACE(__FUNCTION__);
    return res;
}

VALUE rb_s_RhoConnectClient_doSync(int argc, VALUE *argv)
{
    RAWTRACE(__FUNCTION__);
    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toRuby();
    }


    if((argc < 3) || (argc > 3))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toRuby();
    }
    
    unsigned realParamCount = (argc < 3) ? argc : 3;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    if(argc > 3)
    {
        if (rho_ruby_is_proc(argv[3]) || rho_ruby_is_method(argv[3]))
        {
            result.setRubyProcCallBack(argv[3]);
        } else
        {
            if(argc > 4)
                result.setCallBack(argv[3], argv[4]);
            else
                result.setCallBack(argv[3]);
    
        }
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toRuby();
        }
    }

    ObjectProxy::doSync(argumentsAdapter(arguments), result); 
    VALUE res = 
        result.toRuby();

    RAWTRACE(__FUNCTION__);
    return res;
}

VALUE rb_s_RhoConnectClient_doSyncSource(int argc, VALUE *argv)
{
    RAWTRACE(__FUNCTION__);
    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toRuby();
    }


    if((argc < 1) || (argc > 3))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toRuby();
    }
    
    unsigned realParamCount = (argc < 3) ? argc : 3;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    if(argc > 3)
    {
        if (rho_ruby_is_proc(argv[3]) || rho_ruby_is_method(argv[3]))
        {
            result.setRubyProcCallBack(argv[3]);
        } else
        {
            if(argc > 4)
                result.setCallBack(argv[3], argv[4]);
            else
                result.setCallBack(argv[3]);
    
        }
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toRuby();
        }
    }

    ObjectProxy::doSyncSource(argumentsAdapter(arguments), result); 
    VALUE res = 
        result.toRuby();

    RAWTRACE(__FUNCTION__);
    return res;
}

VALUE rb_s_RhoConnectClient_login(int argc, VALUE *argv)
{
    RAWTRACE(__FUNCTION__);
    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toRuby();
    }


    if((argc < 3) || (argc > 4))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toRuby();
    }
    
    unsigned realParamCount = (argc < 2) ? argc : 2;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    if(argc > 2)
    {
        if (rho_ruby_is_proc(argv[2]) || rho_ruby_is_method(argv[2]))
        {
            result.setRubyProcCallBack(argv[2]);
        } else
        {
            if(argc > 3)
                result.setCallBack(argv[2], argv[3]);
            else
                result.setCallBack(argv[2]);
    
        }
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toRuby();
        }
    }

    ObjectProxy::login(argumentsAdapter(arguments), result); 
    VALUE res = 
        result.toRuby();

    RAWTRACE(__FUNCTION__);
    return res;
}

VALUE rb_s_RhoConnectClient_logout(int argc, VALUE *argv)
{
    RAWTRACE(__FUNCTION__);
    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toRuby();
    }


    if((argc < 0) || (argc > 0))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toRuby();
    }
    
    unsigned realParamCount = (argc < 0) ? argc : 0;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    if(argc > 0)
    {
        if (rho_ruby_is_proc(argv[0]) || rho_ruby_is_method(argv[0]))
        {
            result.setRubyProcCallBack(argv[0]);
        } else
        {
            if(argc > 1)
                result.setCallBack(argv[0], argv[1]);
            else
                result.setCallBack(argv[0]);
    
        }
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toRuby();
        }
    }

    ObjectProxy::logout(argumentsAdapter(arguments), result); 
    VALUE res = 
        result.toRuby();

    RAWTRACE(__FUNCTION__);
    return res;
}

VALUE rb_s_RhoConnectClient_stopSync(int argc, VALUE *argv)
{
    RAWTRACE(__FUNCTION__);
    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toRuby();
    }


    if((argc < 0) || (argc > 0))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toRuby();
    }
    
    unsigned realParamCount = (argc < 0) ? argc : 0;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    if(argc > 0)
    {
        if (rho_ruby_is_proc(argv[0]) || rho_ruby_is_method(argv[0]))
        {
            result.setRubyProcCallBack(argv[0]);
        } else
        {
            if(argc > 1)
                result.setCallBack(argv[0], argv[1]);
            else
                result.setCallBack(argv[0]);
    
        }
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toRuby();
        }
    }

    ObjectProxy::stopSync(argumentsAdapter(arguments), result); 
    VALUE res = 
        result.toRuby();

    RAWTRACE(__FUNCTION__);
    return res;
}

VALUE rb_s_RhoConnectClient_setNotification(int argc, VALUE *argv)
{
    RAWTRACE(__FUNCTION__);
    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toRuby();
    }


    if((argc < 2) || (argc > 3))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toRuby();
    }
    
    unsigned realParamCount = (argc < 1) ? argc : 1;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    if(argc > 1)
    {
        if (rho_ruby_is_proc(argv[1]) || rho_ruby_is_method(argv[1]))
        {
            result.setRubyProcCallBack(argv[1]);
        } else
        {
            if(argc > 2)
                result.setCallBack(argv[1], argv[2]);
            else
                result.setCallBack(argv[1]);
    
        }
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toRuby();
        }
    }

    ObjectProxy::setNotification(argumentsAdapter(arguments), result); 
    VALUE res = 
        result.toRuby();

    RAWTRACE(__FUNCTION__);
    return res;
}

VALUE rb_s_RhoConnectClient_clearNotification(int argc, VALUE *argv)
{
    RAWTRACE(__FUNCTION__);
    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toRuby();
    }


    if((argc < 1) || (argc > 1))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toRuby();
    }
    
    unsigned realParamCount = (argc < 1) ? argc : 1;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    if(argc > 1)
    {
        if (rho_ruby_is_proc(argv[1]) || rho_ruby_is_method(argv[1]))
        {
            result.setRubyProcCallBack(argv[1]);
        } else
        {
            if(argc > 2)
                result.setCallBack(argv[1], argv[2]);
            else
                result.setCallBack(argv[1]);
    
        }
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toRuby();
        }
    }

    ObjectProxy::clearNotification(argumentsAdapter(arguments), result); 
    VALUE res = 
        result.toRuby();

    RAWTRACE(__FUNCTION__);
    return res;
}

VALUE rb_s_RhoConnectClient_setObjectNotification(int argc, VALUE *argv)
{
    RAWTRACE(__FUNCTION__);
    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toRuby();
    }


    if((argc < 1) || (argc > 2))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toRuby();
    }
    
    unsigned realParamCount = (argc < 0) ? argc : 0;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    if(argc > 0)
    {
        if (rho_ruby_is_proc(argv[0]) || rho_ruby_is_method(argv[0]))
        {
            result.setRubyProcCallBack(argv[0]);
        } else
        {
            if(argc > 1)
                result.setCallBack(argv[0], argv[1]);
            else
                result.setCallBack(argv[0]);
    
        }
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toRuby();
        }
    }

    ObjectProxy::setObjectNotification(argumentsAdapter(arguments), result); 
    VALUE res = 
        result.toRuby();

    RAWTRACE(__FUNCTION__);
    return res;
}

VALUE rb_s_RhoConnectClient_addObjectNotify(int argc, VALUE *argv)
{
    RAWTRACE(__FUNCTION__);
    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toRuby();
    }


    if((argc < 2) || (argc > 2))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toRuby();
    }
    
    unsigned realParamCount = (argc < 2) ? argc : 2;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    if(argc > 2)
    {
        if (rho_ruby_is_proc(argv[2]) || rho_ruby_is_method(argv[2]))
        {
            result.setRubyProcCallBack(argv[2]);
        } else
        {
            if(argc > 3)
                result.setCallBack(argv[2], argv[3]);
            else
                result.setCallBack(argv[2]);
    
        }
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toRuby();
        }
    }

    ObjectProxy::addObjectNotify(argumentsAdapter(arguments), result); 
    VALUE res = 
        result.toRuby();

    RAWTRACE(__FUNCTION__);
    return res;
}

VALUE rb_s_RhoConnectClient_cleanObjectNotify(int argc, VALUE *argv)
{
    RAWTRACE(__FUNCTION__);
    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toRuby();
    }


    if((argc < 0) || (argc > 0))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toRuby();
    }
    
    unsigned realParamCount = (argc < 0) ? argc : 0;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    if(argc > 0)
    {
        if (rho_ruby_is_proc(argv[0]) || rho_ruby_is_method(argv[0]))
        {
            result.setRubyProcCallBack(argv[0]);
        } else
        {
            if(argc > 1)
                result.setCallBack(argv[0], argv[1]);
            else
                result.setCallBack(argv[0]);
    
        }
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toRuby();
        }
    }

    ObjectProxy::cleanObjectNotify(argumentsAdapter(arguments), result); 
    VALUE res = 
        result.toRuby();

    RAWTRACE(__FUNCTION__);
    return res;
}

VALUE rb_s_RhoConnectClient_getLastSyncObjectCount(int argc, VALUE *argv)
{
    RAWTRACE(__FUNCTION__);
    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toRuby();
    }


    if((argc < 1) || (argc > 1))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toRuby();
    }
    
    unsigned realParamCount = (argc < 1) ? argc : 1;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    if(argc > 1)
    {
        if (rho_ruby_is_proc(argv[1]) || rho_ruby_is_method(argv[1]))
        {
            result.setRubyProcCallBack(argv[1]);
        } else
        {
            if(argc > 2)
                result.setCallBack(argv[1], argv[2]);
            else
                result.setCallBack(argv[1]);
    
        }
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toRuby();
        }
    }

    ObjectProxy::getLastSyncObjectCount(argumentsAdapter(arguments), result); 
    VALUE res = 
        result.toRuby();

    RAWTRACE(__FUNCTION__);
    return res;
}

VALUE rb_s_RhoConnectClient_setSourceProperty(int argc, VALUE *argv)
{
    RAWTRACE(__FUNCTION__);
    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toRuby();
    }


    if((argc < 3) || (argc > 3))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toRuby();
    }
    
    unsigned realParamCount = (argc < 3) ? argc : 3;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    if(argc > 3)
    {
        if (rho_ruby_is_proc(argv[3]) || rho_ruby_is_method(argv[3]))
        {
            result.setRubyProcCallBack(argv[3]);
        } else
        {
            if(argc > 4)
                result.setCallBack(argv[3], argv[4]);
            else
                result.setCallBack(argv[3]);
    
        }
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toRuby();
        }
    }

    ObjectProxy::setSourceProperty(argumentsAdapter(arguments), result); 
    VALUE res = 
        result.toRuby();

    RAWTRACE(__FUNCTION__);
    return res;
}

VALUE rb_s_RhoConnectClient_getSourceProperty(int argc, VALUE *argv)
{
    RAWTRACE(__FUNCTION__);
    MethodResultJni result;
    if(!result)
    {
        result.setError("JNI error: failed to initialize MethodResult java object");
        RAWLOG_ERROR("JNI error: failed to initialize MethodResult java object ^^^");
        return result.toRuby();
    }


    if((argc < 2) || (argc > 2))
    {
        result.setArgError("Wrong number of arguments");
        RAWLOG_ERROR1("Wrong number of arguments: %d ^^^", argc);
        return result.toRuby();
    }
    
    unsigned realParamCount = (argc < 2) ? argc : 2;
    std::vector<VALUE> arguments(argv, argv + realParamCount);
    if(argc > 2)
    {
        if (rho_ruby_is_proc(argv[2]) || rho_ruby_is_method(argv[2]))
        {
            result.setRubyProcCallBack(argv[2]);
        } else
        {
            if(argc > 3)
                result.setCallBack(argv[2], argv[3]);
            else
                result.setCallBack(argv[2]);
    
        }
        if(!result.hasCallBackUrl())
        {
            RAWLOG_ERROR("Error setting callback ^^^");
            return result.toRuby();
        }
    }

    ObjectProxy::getSourceProperty(argumentsAdapter(arguments), result); 
    VALUE res = 
        result.toRuby();

    RAWTRACE(__FUNCTION__);
    return res;
}

}
