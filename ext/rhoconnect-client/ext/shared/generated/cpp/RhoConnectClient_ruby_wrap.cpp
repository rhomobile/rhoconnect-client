#include "RhoConnectClientBase.h"

#include "logging/RhoLog.h"
#undef DEFAULT_LOGCATEGORY
#define DEFAULT_LOGCATEGORY "RhoConnectClient"

#include "ruby/ext/rho/rhoruby.h"
#include "common/StringConverter.h"
#include "common/AutoPointer.h"

using namespace rho;
using namespace rho::common;

extern "C"
{

void rho_wm_impl_performOnUiThread(rho::common::IRhoRunnable* pTask);
VALUE getRuby_RhoConnectClient_Module();



static void string_iter(const char* szVal, void* par)
{
    rho::Vector<rho::String>& ar = *((rho::Vector<rho::String>*)(par));
    ar.addElement( szVal );
}

static void getStringArrayFromValue(VALUE val, rho::Vector<rho::String>& res)
{
    rho_ruby_enum_strary_json(val, string_iter, &res);
}

static void hash_eachstr(const char* szName, const char* szVal, void* par)
{
    rho::Hashtable<rho::String, rho::String>& hash = *((rho::Hashtable<rho::String, rho::String>*)(par));
    hash.put( szName, szVal );
}

static void getStringHashFromValue(VALUE val, rho::Hashtable<rho::String, rho::String>& res)
{
    rho_ruby_enum_strhash_json(val, hash_eachstr, &res);
}


VALUE rb_s_RhoConnectClient_getUserName(int argc, VALUE *argv)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(0) );
        return oRes.toRuby();
    }
    pFunctor = rho_makeInstanceClassFunctor1( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::getUserName,  oRes );

    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->getUserName(  oRes );

    }
    return oRes.toRuby();
}






VALUE rb_s_RhoConnectClient_getPollInterval(int argc, VALUE *argv)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(0) );
        return oRes.toRuby();
    }
    pFunctor = rho_makeInstanceClassFunctor1( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::getPollInterval,  oRes );

    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->getPollInterval(  oRes );

    }
    return oRes.toRuby();
}






VALUE rb_s_RhoConnectClient_setPollInterval(int argc, VALUE *argv)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    nCallbackArg = 1;
    if ( argc == 0 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toRuby();
    }
    int arg0;
    if ( argc > 0 )
    {
        if ( rho_ruby_is_integer(argv[0]) )
            arg0 = rho_ruby_get_int(argv[0]);
        else if (!rho_ruby_is_NIL(argv[0]))
        {
            oRes.setArgError("Type error: argument " "0" " should be " "integer" );
            return oRes.toRuby();
        }
    }

    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toRuby();
    }
    pFunctor = rho_makeInstanceClassFunctor2( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::setPollInterval, arg0,  oRes );

    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->setPollInterval( arg0,  oRes );

    }
    return oRes.toRuby();
}






VALUE rb_s_RhoConnectClient_getSyncServer(int argc, VALUE *argv)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(0) );
        return oRes.toRuby();
    }
    pFunctor = rho_makeInstanceClassFunctor1( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::getSyncServer,  oRes );

    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->getSyncServer(  oRes );

    }
    return oRes.toRuby();
}






VALUE rb_s_RhoConnectClient_setSyncServer(int argc, VALUE *argv)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    nCallbackArg = 1;
    if ( argc == 0 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toRuby();
    }
    rho::String arg0;
    if ( argc > 0 )
    {
        if ( rho_ruby_is_string(argv[0]) )
        {
            arg0 = getStringFromValue(argv[0]);

            oRes.setParamName(getStringFromValue(argv[0]));

        }
        else if (!rho_ruby_is_NIL(argv[0]))
        {
            oRes.setArgError("Type error: argument " "0" " should be " "string" );
            return oRes.toRuby();
        }
    }

    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toRuby();
    }
    pFunctor = rho_makeInstanceClassFunctor2( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::setSyncServer, arg0,  oRes );

    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->setSyncServer( arg0,  oRes );

    }
    return oRes.toRuby();
}






VALUE rb_s_RhoConnectClient_getPageSize(int argc, VALUE *argv)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(0) );
        return oRes.toRuby();
    }
    pFunctor = rho_makeInstanceClassFunctor1( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::getPageSize,  oRes );

    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->getPageSize(  oRes );

    }
    return oRes.toRuby();
}






VALUE rb_s_RhoConnectClient_setPageSize(int argc, VALUE *argv)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    nCallbackArg = 1;
    if ( argc == 0 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toRuby();
    }
    int arg0;
    if ( argc > 0 )
    {
        if ( rho_ruby_is_integer(argv[0]) )
            arg0 = rho_ruby_get_int(argv[0]);
        else if (!rho_ruby_is_NIL(argv[0]))
        {
            oRes.setArgError("Type error: argument " "0" " should be " "integer" );
            return oRes.toRuby();
        }
    }

    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toRuby();
    }
    pFunctor = rho_makeInstanceClassFunctor2( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::setPageSize, arg0,  oRes );

    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->setPageSize( arg0,  oRes );

    }
    return oRes.toRuby();
}






VALUE rb_s_RhoConnectClient_getThreadedMode(int argc, VALUE *argv)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(0) );
        return oRes.toRuby();
    }
    pFunctor = rho_makeInstanceClassFunctor1( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::getThreadedMode,  oRes );

    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->getThreadedMode(  oRes );

    }
    return oRes.toRuby();
}






VALUE rb_s_RhoConnectClient_setThreadedMode(int argc, VALUE *argv)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    nCallbackArg = 1;
    if ( argc == 0 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toRuby();
    }
    bool arg0;
    if ( argc > 0 )
    {
        if ( rho_ruby_is_boolean(argv[0]) )
            arg0 = rho_ruby_get_bool(argv[0]) ? true : false;
        else if (!rho_ruby_is_NIL(argv[0]))
        {
            oRes.setArgError("Type error: argument " "0" " should be " "boolean" );
            return oRes.toRuby();
        }
    }

    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toRuby();
    }
    pFunctor = rho_makeInstanceClassFunctor2( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::setThreadedMode, arg0,  oRes );

    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->setThreadedMode( arg0,  oRes );

    }
    return oRes.toRuby();
}






VALUE rb_s_RhoConnectClient_getShowStatusPopup(int argc, VALUE *argv)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(0) );
        return oRes.toRuby();
    }
    pFunctor = rho_makeInstanceClassFunctor1( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::getShowStatusPopup,  oRes );

    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->getShowStatusPopup(  oRes );

    }
    return oRes.toRuby();
}






VALUE rb_s_RhoConnectClient_setShowStatusPopup(int argc, VALUE *argv)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    nCallbackArg = 1;
    if ( argc == 0 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toRuby();
    }
    bool arg0;
    if ( argc > 0 )
    {
        if ( rho_ruby_is_boolean(argv[0]) )
            arg0 = rho_ruby_get_bool(argv[0]) ? true : false;
        else if (!rho_ruby_is_NIL(argv[0]))
        {
            oRes.setArgError("Type error: argument " "0" " should be " "boolean" );
            return oRes.toRuby();
        }
    }

    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toRuby();
    }
    pFunctor = rho_makeInstanceClassFunctor2( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::setShowStatusPopup, arg0,  oRes );

    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->setShowStatusPopup( arg0,  oRes );

    }
    return oRes.toRuby();
}






VALUE rb_s_RhoConnectClient_getSslVerifyPeer(int argc, VALUE *argv)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(0) );
        return oRes.toRuby();
    }
    pFunctor = rho_makeInstanceClassFunctor1( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::getSslVerifyPeer,  oRes );

    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->getSslVerifyPeer(  oRes );

    }
    return oRes.toRuby();
}






VALUE rb_s_RhoConnectClient_setSslVerifyPeer(int argc, VALUE *argv)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    nCallbackArg = 1;
    if ( argc == 0 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toRuby();
    }
    bool arg0;
    if ( argc > 0 )
    {
        if ( rho_ruby_is_boolean(argv[0]) )
            arg0 = rho_ruby_get_bool(argv[0]) ? true : false;
        else if (!rho_ruby_is_NIL(argv[0]))
        {
            oRes.setArgError("Type error: argument " "0" " should be " "boolean" );
            return oRes.toRuby();
        }
    }

    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toRuby();
    }
    pFunctor = rho_makeInstanceClassFunctor2( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::setSslVerifyPeer, arg0,  oRes );

    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->setSslVerifyPeer( arg0,  oRes );

    }
    return oRes.toRuby();
}






VALUE rb_s_RhoConnectClient_loggedIn(int argc, VALUE *argv)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(0) );
        return oRes.toRuby();
    }
    pFunctor = rho_makeInstanceClassFunctor1( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::loggedIn,  oRes );

    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->loggedIn(  oRes );

    }
    return oRes.toRuby();
}






VALUE rb_s_RhoConnectClient_syncing(int argc, VALUE *argv)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(0) );
        return oRes.toRuby();
    }
    pFunctor = rho_makeInstanceClassFunctor1( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::syncing,  oRes );

    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->syncing(  oRes );

    }
    return oRes.toRuby();
}






VALUE rb_s_RhoConnectClient_search(int argc, VALUE *argv)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    nCallbackArg = 1;
    if ( argc == 0 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toRuby();
    }
    rho::Hashtable<rho::String, rho::String> arg0;
    if ( argc > 0 )
    {
        if ( rho_ruby_is_hash(argv[0]) )
            getStringHashFromValue(argv[0], arg0);
        else if (!rho_ruby_is_NIL(argv[0]))
        {
            oRes.setArgError("Type error: argument " "0" " should be " "hash" );
            return oRes.toRuby();
        }
    }

    if ( argc > nCallbackArg )
    {

        if ( rho_ruby_is_proc(argv[nCallbackArg]) || rho_ruby_is_method(argv[nCallbackArg]) )
        {
            oRes.setRubyCallbackProc( argv[nCallbackArg] );
        }else if ( rho_ruby_is_string(argv[nCallbackArg]) )
        {
            oRes.setRubyCallback( getStringFromValue(argv[nCallbackArg]) );
        }else
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toRuby();
        }

        oRes.setCallInUIThread(false);
        if ( argc > nCallbackArg + 1 )
        {
            if ( !rho_ruby_is_string(argv[nCallbackArg + 1]) )
            {
                oRes.setArgError("Type error: callback parameter should be String");
                return oRes.toRuby();
            }

            oRes.setCallbackParam( getStringFromValue(argv[nCallbackArg + 1]) );
        }
        
        bUseCallback = true;
    }
    pFunctor = rho_makeInstanceClassFunctor2( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::search, arg0,  oRes );
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->search( arg0,  oRes );

    }
    return oRes.toRuby();
}






VALUE rb_s_RhoConnectClient_doSync(int argc, VALUE *argv)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    nCallbackArg = 1;
    bool arg0;
    if ( argc > 0 )
    {
        if ( rho_ruby_is_boolean(argv[0]) )
            arg0 = rho_ruby_get_bool(argv[0]) ? true : false;
        else if (!rho_ruby_is_NIL(argv[0]))
        {
            oRes.setArgError("Type error: argument " "0" " should be " "boolean" );
            return oRes.toRuby();
        }
    }

    nCallbackArg = 2;
    rho::String arg1;
    if ( argc > 1 )
    {
        if ( rho_ruby_is_string(argv[1]) )
        {
            arg1 = getStringFromValue(argv[1]);

        }
        else if (!rho_ruby_is_NIL(argv[1]))
        {
            oRes.setArgError("Type error: argument " "1" " should be " "string" );
            return oRes.toRuby();
        }
    }

    nCallbackArg = 3;
    bool arg2;
    if ( argc > 2 )
    {
        if ( rho_ruby_is_boolean(argv[2]) )
            arg2 = rho_ruby_get_bool(argv[2]) ? true : false;
        else if (!rho_ruby_is_NIL(argv[2]))
        {
            oRes.setArgError("Type error: argument " "2" " should be " "boolean" );
            return oRes.toRuby();
        }
    }

    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(3) );
        return oRes.toRuby();
    }
    pFunctor = rho_makeInstanceClassFunctor4( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::doSync, arg0, arg1, arg2,  oRes );

    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->doSync( arg0, arg1, arg2,  oRes );

    }
    return oRes.toRuby();
}






VALUE rb_s_RhoConnectClient_doSyncSource(int argc, VALUE *argv)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    nCallbackArg = 1;
    if ( argc == 0 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(3) );
        return oRes.toRuby();
    }
    rho::String arg0;
    if ( argc > 0 )
    {
        if ( rho_ruby_is_string(argv[0]) )
        {
            arg0 = getStringFromValue(argv[0]);

            oRes.setParamName(getStringFromValue(argv[0]));

        }
        else if (!rho_ruby_is_NIL(argv[0]))
        {
            oRes.setArgError("Type error: argument " "0" " should be " "string" );
            return oRes.toRuby();
        }
    }

    nCallbackArg = 2;
    bool arg1;
    if ( argc > 1 )
    {
        if ( rho_ruby_is_boolean(argv[1]) )
            arg1 = rho_ruby_get_bool(argv[1]) ? true : false;
        else if (!rho_ruby_is_NIL(argv[1]))
        {
            oRes.setArgError("Type error: argument " "1" " should be " "boolean" );
            return oRes.toRuby();
        }
    }

    nCallbackArg = 3;
    rho::String arg2;
    if ( argc > 2 )
    {
        if ( rho_ruby_is_string(argv[2]) )
        {
            arg2 = getStringFromValue(argv[2]);

        }
        else if (!rho_ruby_is_NIL(argv[2]))
        {
            oRes.setArgError("Type error: argument " "2" " should be " "string" );
            return oRes.toRuby();
        }
    }

    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(3) );
        return oRes.toRuby();
    }
    pFunctor = rho_makeInstanceClassFunctor4( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::doSyncSource, arg0, arg1, arg2,  oRes );

    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->doSyncSource( arg0, arg1, arg2,  oRes );

    }
    return oRes.toRuby();
}






VALUE rb_s_RhoConnectClient_login(int argc, VALUE *argv)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    nCallbackArg = 1;
    if ( argc == 0 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(2) );
        return oRes.toRuby();
    }
    rho::String arg0;
    if ( argc > 0 )
    {
        if ( rho_ruby_is_string(argv[0]) )
        {
            arg0 = getStringFromValue(argv[0]);

            oRes.setParamName(getStringFromValue(argv[0]));

        }
        else if (!rho_ruby_is_NIL(argv[0]))
        {
            oRes.setArgError("Type error: argument " "0" " should be " "string" );
            return oRes.toRuby();
        }
    }

    nCallbackArg = 2;
    if ( argc == 1 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(2) );
        return oRes.toRuby();
    }
    rho::String arg1;
    if ( argc > 1 )
    {
        if ( rho_ruby_is_string(argv[1]) )
        {
            arg1 = getStringFromValue(argv[1]);

        }
        else if (!rho_ruby_is_NIL(argv[1]))
        {
            oRes.setArgError("Type error: argument " "1" " should be " "string" );
            return oRes.toRuby();
        }
    }

    if ( argc > nCallbackArg )
    {

        if ( rho_ruby_is_proc(argv[nCallbackArg]) || rho_ruby_is_method(argv[nCallbackArg]) )
        {
            oRes.setRubyCallbackProc( argv[nCallbackArg] );
        }else if ( rho_ruby_is_string(argv[nCallbackArg]) )
        {
            oRes.setRubyCallback( getStringFromValue(argv[nCallbackArg]) );
        }else
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toRuby();
        }

        oRes.setCallInUIThread(false);
        if ( argc > nCallbackArg + 1 )
        {
            if ( !rho_ruby_is_string(argv[nCallbackArg + 1]) )
            {
                oRes.setArgError("Type error: callback parameter should be String");
                return oRes.toRuby();
            }

            oRes.setCallbackParam( getStringFromValue(argv[nCallbackArg + 1]) );
        }
        
        bUseCallback = true;
    }
    else
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(3) + ".Mandatory Callback parameter is mised." );
        return oRes.toRuby();
    }
    pFunctor = rho_makeInstanceClassFunctor3( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::login, arg0, arg1,  oRes );
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->login( arg0, arg1,  oRes );

    }
    return oRes.toRuby();
}






VALUE rb_s_RhoConnectClient_logout(int argc, VALUE *argv)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(0) );
        return oRes.toRuby();
    }
    pFunctor = rho_makeInstanceClassFunctor1( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::logout,  oRes );

    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->logout(  oRes );

    }
    return oRes.toRuby();
}






VALUE rb_s_RhoConnectClient_stopSync(int argc, VALUE *argv)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(0) );
        return oRes.toRuby();
    }
    pFunctor = rho_makeInstanceClassFunctor1( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::stopSync,  oRes );

    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->stopSync(  oRes );

    }
    return oRes.toRuby();
}






VALUE rb_s_RhoConnectClient_setNotification(int argc, VALUE *argv)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    nCallbackArg = 1;
    if ( argc == 0 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toRuby();
    }
    rho::String arg0;
    if ( argc > 0 )
    {
        if ( rho_ruby_is_string(argv[0]) )
        {
            arg0 = getStringFromValue(argv[0]);

            oRes.setParamName(getStringFromValue(argv[0]));

        }
        else if (!rho_ruby_is_NIL(argv[0]))
        {
            oRes.setArgError("Type error: argument " "0" " should be " "string" );
            return oRes.toRuby();
        }
    }

    if ( argc > nCallbackArg )
    {

        if ( rho_ruby_is_proc(argv[nCallbackArg]) || rho_ruby_is_method(argv[nCallbackArg]) )
        {
            oRes.setRubyCallbackProc( argv[nCallbackArg] );
        }else if ( rho_ruby_is_string(argv[nCallbackArg]) )
        {
            oRes.setRubyCallback( getStringFromValue(argv[nCallbackArg]) );
        }else
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toRuby();
        }

        oRes.setCallInUIThread(false);
        if ( argc > nCallbackArg + 1 )
        {
            if ( !rho_ruby_is_string(argv[nCallbackArg + 1]) )
            {
                oRes.setArgError("Type error: callback parameter should be String");
                return oRes.toRuby();
            }

            oRes.setCallbackParam( getStringFromValue(argv[nCallbackArg + 1]) );
        }
        
        bUseCallback = true;
    }
    else
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(2) + ".Mandatory Callback parameter is mised." );
        return oRes.toRuby();
    }
    pFunctor = rho_makeInstanceClassFunctor2( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::setNotification, arg0,  oRes );
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->setNotification( arg0,  oRes );

    }
    return oRes.toRuby();
}






VALUE rb_s_RhoConnectClient_clearNotification(int argc, VALUE *argv)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    nCallbackArg = 1;
    if ( argc == 0 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toRuby();
    }
    rho::String arg0;
    if ( argc > 0 )
    {
        if ( rho_ruby_is_string(argv[0]) )
        {
            arg0 = getStringFromValue(argv[0]);

            oRes.setParamName(getStringFromValue(argv[0]));

        }
        else if (!rho_ruby_is_NIL(argv[0]))
        {
            oRes.setArgError("Type error: argument " "0" " should be " "string" );
            return oRes.toRuby();
        }
    }

    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toRuby();
    }
    pFunctor = rho_makeInstanceClassFunctor2( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::clearNotification, arg0,  oRes );

    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->clearNotification( arg0,  oRes );

    }
    return oRes.toRuby();
}






VALUE rb_s_RhoConnectClient_setObjectNotification(int argc, VALUE *argv)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    if ( argc > nCallbackArg )
    {

        if ( rho_ruby_is_proc(argv[nCallbackArg]) || rho_ruby_is_method(argv[nCallbackArg]) )
        {
            oRes.setRubyCallbackProc( argv[nCallbackArg] );
        }else if ( rho_ruby_is_string(argv[nCallbackArg]) )
        {
            oRes.setRubyCallback( getStringFromValue(argv[nCallbackArg]) );
        }else
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toRuby();
        }

        oRes.setCallInUIThread(false);
        if ( argc > nCallbackArg + 1 )
        {
            if ( !rho_ruby_is_string(argv[nCallbackArg + 1]) )
            {
                oRes.setArgError("Type error: callback parameter should be String");
                return oRes.toRuby();
            }

            oRes.setCallbackParam( getStringFromValue(argv[nCallbackArg + 1]) );
        }
        
        bUseCallback = true;
    }
    else
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) + ".Mandatory Callback parameter is mised." );
        return oRes.toRuby();
    }
    pFunctor = rho_makeInstanceClassFunctor1( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::setObjectNotification,  oRes );
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->setObjectNotification(  oRes );

    }
    return oRes.toRuby();
}






VALUE rb_s_RhoConnectClient_addObjectNotify(int argc, VALUE *argv)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    nCallbackArg = 1;
    if ( argc == 0 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(2) );
        return oRes.toRuby();
    }
    rho::String arg0;
    if ( argc > 0 )
    {
        if ( rho_ruby_is_string(argv[0]) )
        {
            arg0 = getStringFromValue(argv[0]);

            oRes.setParamName(getStringFromValue(argv[0]));

        }
        else if (!rho_ruby_is_NIL(argv[0]))
        {
            oRes.setArgError("Type error: argument " "0" " should be " "string" );
            return oRes.toRuby();
        }
    }

    nCallbackArg = 2;
    if ( argc == 1 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(2) );
        return oRes.toRuby();
    }
    rho::String arg1;
    if ( argc > 1 )
    {
        if ( rho_ruby_is_string(argv[1]) )
        {
            arg1 = getStringFromValue(argv[1]);

        }
        else if (!rho_ruby_is_NIL(argv[1]))
        {
            oRes.setArgError("Type error: argument " "1" " should be " "string" );
            return oRes.toRuby();
        }
    }

    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(2) );
        return oRes.toRuby();
    }
    pFunctor = rho_makeInstanceClassFunctor3( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::addObjectNotify, arg0, arg1,  oRes );

    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addObjectNotify( arg0, arg1,  oRes );

    }
    return oRes.toRuby();
}






VALUE rb_s_RhoConnectClient_cleanObjectNotify(int argc, VALUE *argv)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(0) );
        return oRes.toRuby();
    }
    pFunctor = rho_makeInstanceClassFunctor1( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::cleanObjectNotify,  oRes );

    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->cleanObjectNotify(  oRes );

    }
    return oRes.toRuby();
}






VALUE rb_s_RhoConnectClient_getLastSyncObjectCount(int argc, VALUE *argv)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    nCallbackArg = 1;
    if ( argc == 0 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toRuby();
    }
    rho::String arg0;
    if ( argc > 0 )
    {
        if ( rho_ruby_is_string(argv[0]) )
        {
            arg0 = getStringFromValue(argv[0]);

            oRes.setParamName(getStringFromValue(argv[0]));

        }
        else if (!rho_ruby_is_NIL(argv[0]))
        {
            oRes.setArgError("Type error: argument " "0" " should be " "string" );
            return oRes.toRuby();
        }
    }

    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toRuby();
    }
    pFunctor = rho_makeInstanceClassFunctor2( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::getLastSyncObjectCount, arg0,  oRes );

    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->getLastSyncObjectCount( arg0,  oRes );

    }
    return oRes.toRuby();
}






VALUE rb_s_RhoConnectClient_setSourceProperty(int argc, VALUE *argv)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    nCallbackArg = 1;
    if ( argc == 0 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(3) );
        return oRes.toRuby();
    }
    rho::String arg0;
    if ( argc > 0 )
    {
        if ( rho_ruby_is_string(argv[0]) )
        {
            arg0 = getStringFromValue(argv[0]);

            oRes.setParamName(getStringFromValue(argv[0]));

        }
        else if (!rho_ruby_is_NIL(argv[0]))
        {
            oRes.setArgError("Type error: argument " "0" " should be " "string" );
            return oRes.toRuby();
        }
    }

    nCallbackArg = 2;
    if ( argc == 1 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(3) );
        return oRes.toRuby();
    }
    rho::String arg1;
    if ( argc > 1 )
    {
        if ( rho_ruby_is_string(argv[1]) )
        {
            arg1 = getStringFromValue(argv[1]);

        }
        else if (!rho_ruby_is_NIL(argv[1]))
        {
            oRes.setArgError("Type error: argument " "1" " should be " "string" );
            return oRes.toRuby();
        }
    }

    nCallbackArg = 3;
    if ( argc == 2 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(3) );
        return oRes.toRuby();
    }
    rho::String arg2;
    if ( argc > 2 )
    {
        if ( rho_ruby_is_string(argv[2]) )
        {
            arg2 = getStringFromValue(argv[2]);

        }
        else if (!rho_ruby_is_NIL(argv[2]))
        {
            oRes.setArgError("Type error: argument " "2" " should be " "string" );
            return oRes.toRuby();
        }
    }

    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(3) );
        return oRes.toRuby();
    }
    pFunctor = rho_makeInstanceClassFunctor4( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::setSourceProperty, arg0, arg1, arg2,  oRes );

    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->setSourceProperty( arg0, arg1, arg2,  oRes );

    }
    return oRes.toRuby();
}






VALUE rb_s_RhoConnectClient_getSourceProperty(int argc, VALUE *argv)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int nCallbackArg = 0;
    nCallbackArg = 1;
    if ( argc == 0 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(2) );
        return oRes.toRuby();
    }
    rho::String arg0;
    if ( argc > 0 )
    {
        if ( rho_ruby_is_string(argv[0]) )
        {
            arg0 = getStringFromValue(argv[0]);

            oRes.setParamName(getStringFromValue(argv[0]));

        }
        else if (!rho_ruby_is_NIL(argv[0]))
        {
            oRes.setArgError("Type error: argument " "0" " should be " "string" );
            return oRes.toRuby();
        }
    }

    nCallbackArg = 2;
    if ( argc == 1 )
    {
        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(2) );
        return oRes.toRuby();
    }
    rho::String arg1;
    if ( argc > 1 )
    {
        if ( rho_ruby_is_string(argv[1]) )
        {
            arg1 = getStringFromValue(argv[1]);

        }
        else if (!rho_ruby_is_NIL(argv[1]))
        {
            oRes.setArgError("Type error: argument " "1" " should be " "string" );
            return oRes.toRuby();
        }
    }

    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(2) );
        return oRes.toRuby();
    }
    pFunctor = rho_makeInstanceClassFunctor3( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::getSourceProperty, arg0, arg1,  oRes );

    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->getSourceProperty( arg0, arg1,  oRes );

    }
    return oRes.toRuby();
}







}