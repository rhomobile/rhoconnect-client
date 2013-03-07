#include "RhoConnectClientBase.h"
#include "api_generator/js_helpers.h"

#include "logging/RhoLog.h"
#undef DEFAULT_LOGCATEGORY
#define DEFAULT_LOGCATEGORY "RhoConnectClient"

#include "common/StringConverter.h"

extern "C" void rho_wm_impl_performOnUiThread(rho::common::IRhoRunnable* pTask);

using namespace rho;
using namespace rho::json;
using namespace rho::common;


rho::String js_s_RhoConnectClient_getUserName(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int argc = argv.getSize();
    int nCallbackArg = 0;




    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(0) );
        return oRes.toJSON();


        if ( !argv[nCallbackArg].isString() )
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toJSON();
        }

        oRes.setCallInUIThread(false);
        oRes.setRubyCallback( argv[nCallbackArg].getString() );
        if ( argc > nCallbackArg + 1 )
        {
            if ( !argv[nCallbackArg + 1].isString() )
            {
                oRes.setArgError("Type error: callback parameter should be String");
                return oRes.toJSON();
            }

            oRes.setCallbackParam( argv[nCallbackArg + 1].getString() );
        }

    }


    pFunctor = rho_makeInstanceClassFunctor1( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::getUserName,  oRes );




    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->getUserName(  oRes );


    }


    return oRes.toJSON();

}

rho::String js_s_RhoConnectClient_getPollInterval(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int argc = argv.getSize();
    int nCallbackArg = 0;




    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(0) );
        return oRes.toJSON();


        if ( !argv[nCallbackArg].isString() )
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toJSON();
        }

        oRes.setCallInUIThread(false);
        oRes.setRubyCallback( argv[nCallbackArg].getString() );
        if ( argc > nCallbackArg + 1 )
        {
            if ( !argv[nCallbackArg + 1].isString() )
            {
                oRes.setArgError("Type error: callback parameter should be String");
                return oRes.toJSON();
            }

            oRes.setCallbackParam( argv[nCallbackArg + 1].getString() );
        }

    }


    pFunctor = rho_makeInstanceClassFunctor1( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::getPollInterval,  oRes );




    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->getPollInterval(  oRes );


    }


    return oRes.toJSON();

}

rho::String js_s_RhoConnectClient_setPollInterval(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int argc = argv.getSize();
    int nCallbackArg = 0;



    nCallbackArg = 1;

    
    if ( argc == 0 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toJSON();
    }
    




    int arg0;
    if ( argc > 0 )
    {
        if ( argv[0].isString() )
            arg0 = argv[0].getInt();
        else if (!argv[0].isNull())
        {
            oRes.setArgError("Type error: argument " "0" " should be " "integer" );
            return oRes.toJSON();
        }
    }
















    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toJSON();


        if ( !argv[nCallbackArg].isString() )
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toJSON();
        }

        oRes.setCallInUIThread(false);
        oRes.setRubyCallback( argv[nCallbackArg].getString() );
        if ( argc > nCallbackArg + 1 )
        {
            if ( !argv[nCallbackArg + 1].isString() )
            {
                oRes.setArgError("Type error: callback parameter should be String");
                return oRes.toJSON();
            }

            oRes.setCallbackParam( argv[nCallbackArg + 1].getString() );
        }

    }


    pFunctor = rho_makeInstanceClassFunctor2( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::setPollInterval, arg0,  oRes );




    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->setPollInterval( arg0,  oRes );


    }


    return oRes.toJSON();

}

rho::String js_s_RhoConnectClient_getSyncServer(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int argc = argv.getSize();
    int nCallbackArg = 0;




    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(0) );
        return oRes.toJSON();


        if ( !argv[nCallbackArg].isString() )
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toJSON();
        }

        oRes.setCallInUIThread(false);
        oRes.setRubyCallback( argv[nCallbackArg].getString() );
        if ( argc > nCallbackArg + 1 )
        {
            if ( !argv[nCallbackArg + 1].isString() )
            {
                oRes.setArgError("Type error: callback parameter should be String");
                return oRes.toJSON();
            }

            oRes.setCallbackParam( argv[nCallbackArg + 1].getString() );
        }

    }


    pFunctor = rho_makeInstanceClassFunctor1( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::getSyncServer,  oRes );




    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->getSyncServer(  oRes );


    }


    return oRes.toJSON();

}

rho::String js_s_RhoConnectClient_setSyncServer(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int argc = argv.getSize();
    int nCallbackArg = 0;



    nCallbackArg = 1;

    
    if ( argc == 0 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toJSON();
    }
    


    rho::String arg0;
    if ( argc > 0 )
    {
        if ( argv[0].isString() )
        {
            arg0 = argv[0].getString();

            oRes.setParamName(argv[0].getString());

        }
        else if (!argv[0].isNull())
        {
            oRes.setArgError( "Type error: argument " "0" " should be " "string" );
            return oRes.toJSON();
        }
    }


















    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toJSON();


        if ( !argv[nCallbackArg].isString() )
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toJSON();
        }

        oRes.setCallInUIThread(false);
        oRes.setRubyCallback( argv[nCallbackArg].getString() );
        if ( argc > nCallbackArg + 1 )
        {
            if ( !argv[nCallbackArg + 1].isString() )
            {
                oRes.setArgError("Type error: callback parameter should be String");
                return oRes.toJSON();
            }

            oRes.setCallbackParam( argv[nCallbackArg + 1].getString() );
        }

    }


    pFunctor = rho_makeInstanceClassFunctor2( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::setSyncServer, arg0,  oRes );




    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->setSyncServer( arg0,  oRes );


    }


    return oRes.toJSON();

}

rho::String js_s_RhoConnectClient_getPageSize(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int argc = argv.getSize();
    int nCallbackArg = 0;




    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(0) );
        return oRes.toJSON();


        if ( !argv[nCallbackArg].isString() )
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toJSON();
        }

        oRes.setCallInUIThread(false);
        oRes.setRubyCallback( argv[nCallbackArg].getString() );
        if ( argc > nCallbackArg + 1 )
        {
            if ( !argv[nCallbackArg + 1].isString() )
            {
                oRes.setArgError("Type error: callback parameter should be String");
                return oRes.toJSON();
            }

            oRes.setCallbackParam( argv[nCallbackArg + 1].getString() );
        }

    }


    pFunctor = rho_makeInstanceClassFunctor1( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::getPageSize,  oRes );




    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->getPageSize(  oRes );


    }


    return oRes.toJSON();

}

rho::String js_s_RhoConnectClient_setPageSize(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int argc = argv.getSize();
    int nCallbackArg = 0;



    nCallbackArg = 1;

    
    if ( argc == 0 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toJSON();
    }
    




    int arg0;
    if ( argc > 0 )
    {
        if ( argv[0].isString() )
            arg0 = argv[0].getInt();
        else if (!argv[0].isNull())
        {
            oRes.setArgError("Type error: argument " "0" " should be " "integer" );
            return oRes.toJSON();
        }
    }
















    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toJSON();


        if ( !argv[nCallbackArg].isString() )
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toJSON();
        }

        oRes.setCallInUIThread(false);
        oRes.setRubyCallback( argv[nCallbackArg].getString() );
        if ( argc > nCallbackArg + 1 )
        {
            if ( !argv[nCallbackArg + 1].isString() )
            {
                oRes.setArgError("Type error: callback parameter should be String");
                return oRes.toJSON();
            }

            oRes.setCallbackParam( argv[nCallbackArg + 1].getString() );
        }

    }


    pFunctor = rho_makeInstanceClassFunctor2( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::setPageSize, arg0,  oRes );




    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->setPageSize( arg0,  oRes );


    }


    return oRes.toJSON();

}

rho::String js_s_RhoConnectClient_getThreadedMode(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int argc = argv.getSize();
    int nCallbackArg = 0;




    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(0) );
        return oRes.toJSON();


        if ( !argv[nCallbackArg].isString() )
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toJSON();
        }

        oRes.setCallInUIThread(false);
        oRes.setRubyCallback( argv[nCallbackArg].getString() );
        if ( argc > nCallbackArg + 1 )
        {
            if ( !argv[nCallbackArg + 1].isString() )
            {
                oRes.setArgError("Type error: callback parameter should be String");
                return oRes.toJSON();
            }

            oRes.setCallbackParam( argv[nCallbackArg + 1].getString() );
        }

    }


    pFunctor = rho_makeInstanceClassFunctor1( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::getThreadedMode,  oRes );




    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->getThreadedMode(  oRes );


    }


    return oRes.toJSON();

}

rho::String js_s_RhoConnectClient_setThreadedMode(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int argc = argv.getSize();
    int nCallbackArg = 0;



    nCallbackArg = 1;

    
    if ( argc == 0 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toJSON();
    }
    






    bool arg0;
    if ( argc > 0 )
    {
        if ( argv[0].isString() )
            arg0 = argv[0].getInt() ? true : false;
        else if (!argv[0].isNull())
        {
            oRes.setArgError("Type error: argument " "0" " should be " "boolean" );
            return oRes.toJSON();
        }
    }














    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toJSON();


        if ( !argv[nCallbackArg].isString() )
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toJSON();
        }

        oRes.setCallInUIThread(false);
        oRes.setRubyCallback( argv[nCallbackArg].getString() );
        if ( argc > nCallbackArg + 1 )
        {
            if ( !argv[nCallbackArg + 1].isString() )
            {
                oRes.setArgError("Type error: callback parameter should be String");
                return oRes.toJSON();
            }

            oRes.setCallbackParam( argv[nCallbackArg + 1].getString() );
        }

    }


    pFunctor = rho_makeInstanceClassFunctor2( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::setThreadedMode, arg0,  oRes );




    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->setThreadedMode( arg0,  oRes );


    }


    return oRes.toJSON();

}

rho::String js_s_RhoConnectClient_getShowStatusPopup(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int argc = argv.getSize();
    int nCallbackArg = 0;




    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(0) );
        return oRes.toJSON();


        if ( !argv[nCallbackArg].isString() )
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toJSON();
        }

        oRes.setCallInUIThread(false);
        oRes.setRubyCallback( argv[nCallbackArg].getString() );
        if ( argc > nCallbackArg + 1 )
        {
            if ( !argv[nCallbackArg + 1].isString() )
            {
                oRes.setArgError("Type error: callback parameter should be String");
                return oRes.toJSON();
            }

            oRes.setCallbackParam( argv[nCallbackArg + 1].getString() );
        }

    }


    pFunctor = rho_makeInstanceClassFunctor1( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::getShowStatusPopup,  oRes );




    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->getShowStatusPopup(  oRes );


    }


    return oRes.toJSON();

}

rho::String js_s_RhoConnectClient_setShowStatusPopup(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int argc = argv.getSize();
    int nCallbackArg = 0;



    nCallbackArg = 1;

    
    if ( argc == 0 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toJSON();
    }
    






    bool arg0;
    if ( argc > 0 )
    {
        if ( argv[0].isString() )
            arg0 = argv[0].getInt() ? true : false;
        else if (!argv[0].isNull())
        {
            oRes.setArgError("Type error: argument " "0" " should be " "boolean" );
            return oRes.toJSON();
        }
    }














    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toJSON();


        if ( !argv[nCallbackArg].isString() )
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toJSON();
        }

        oRes.setCallInUIThread(false);
        oRes.setRubyCallback( argv[nCallbackArg].getString() );
        if ( argc > nCallbackArg + 1 )
        {
            if ( !argv[nCallbackArg + 1].isString() )
            {
                oRes.setArgError("Type error: callback parameter should be String");
                return oRes.toJSON();
            }

            oRes.setCallbackParam( argv[nCallbackArg + 1].getString() );
        }

    }


    pFunctor = rho_makeInstanceClassFunctor2( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::setShowStatusPopup, arg0,  oRes );




    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->setShowStatusPopup( arg0,  oRes );


    }


    return oRes.toJSON();

}

rho::String js_s_RhoConnectClient_getSslVerifyPeer(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int argc = argv.getSize();
    int nCallbackArg = 0;




    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(0) );
        return oRes.toJSON();


        if ( !argv[nCallbackArg].isString() )
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toJSON();
        }

        oRes.setCallInUIThread(false);
        oRes.setRubyCallback( argv[nCallbackArg].getString() );
        if ( argc > nCallbackArg + 1 )
        {
            if ( !argv[nCallbackArg + 1].isString() )
            {
                oRes.setArgError("Type error: callback parameter should be String");
                return oRes.toJSON();
            }

            oRes.setCallbackParam( argv[nCallbackArg + 1].getString() );
        }

    }


    pFunctor = rho_makeInstanceClassFunctor1( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::getSslVerifyPeer,  oRes );




    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->getSslVerifyPeer(  oRes );


    }


    return oRes.toJSON();

}

rho::String js_s_RhoConnectClient_setSslVerifyPeer(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int argc = argv.getSize();
    int nCallbackArg = 0;



    nCallbackArg = 1;

    
    if ( argc == 0 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toJSON();
    }
    






    bool arg0;
    if ( argc > 0 )
    {
        if ( argv[0].isString() )
            arg0 = argv[0].getInt() ? true : false;
        else if (!argv[0].isNull())
        {
            oRes.setArgError("Type error: argument " "0" " should be " "boolean" );
            return oRes.toJSON();
        }
    }














    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toJSON();


        if ( !argv[nCallbackArg].isString() )
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toJSON();
        }

        oRes.setCallInUIThread(false);
        oRes.setRubyCallback( argv[nCallbackArg].getString() );
        if ( argc > nCallbackArg + 1 )
        {
            if ( !argv[nCallbackArg + 1].isString() )
            {
                oRes.setArgError("Type error: callback parameter should be String");
                return oRes.toJSON();
            }

            oRes.setCallbackParam( argv[nCallbackArg + 1].getString() );
        }

    }


    pFunctor = rho_makeInstanceClassFunctor2( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::setSslVerifyPeer, arg0,  oRes );




    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->setSslVerifyPeer( arg0,  oRes );


    }


    return oRes.toJSON();

}

rho::String js_s_RhoConnectClient_loggedIn(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int argc = argv.getSize();
    int nCallbackArg = 0;




    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(0) );
        return oRes.toJSON();


        if ( !argv[nCallbackArg].isString() )
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toJSON();
        }

        oRes.setCallInUIThread(false);
        oRes.setRubyCallback( argv[nCallbackArg].getString() );
        if ( argc > nCallbackArg + 1 )
        {
            if ( !argv[nCallbackArg + 1].isString() )
            {
                oRes.setArgError("Type error: callback parameter should be String");
                return oRes.toJSON();
            }

            oRes.setCallbackParam( argv[nCallbackArg + 1].getString() );
        }

    }


    pFunctor = rho_makeInstanceClassFunctor1( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::loggedIn,  oRes );




    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->loggedIn(  oRes );


    }


    return oRes.toJSON();

}

rho::String js_s_RhoConnectClient_syncing(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int argc = argv.getSize();
    int nCallbackArg = 0;




    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(0) );
        return oRes.toJSON();


        if ( !argv[nCallbackArg].isString() )
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toJSON();
        }

        oRes.setCallInUIThread(false);
        oRes.setRubyCallback( argv[nCallbackArg].getString() );
        if ( argc > nCallbackArg + 1 )
        {
            if ( !argv[nCallbackArg + 1].isString() )
            {
                oRes.setArgError("Type error: callback parameter should be String");
                return oRes.toJSON();
            }

            oRes.setCallbackParam( argv[nCallbackArg + 1].getString() );
        }

    }


    pFunctor = rho_makeInstanceClassFunctor1( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::syncing,  oRes );




    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->syncing(  oRes );


    }


    return oRes.toJSON();

}

rho::String js_s_RhoConnectClient_search(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int argc = argv.getSize();
    int nCallbackArg = 0;



    nCallbackArg = 1;

    
    if ( argc == 0 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toJSON();
    }
    












    rho::Hashtable<rho::String, rho::String> arg0;
    if ( argc > 0 )
    {
        if ( argv[0].isObject() )
        {
            CJSONStructIterator objIter(argv[0]);

            for( ; !objIter.isEnd(); objIter.next() )
            {
                arg0[objIter.getCurKey()] = objIter.getCurString();
            }
        }
        else if (!argv[0].isNull())
        {
            oRes.setArgError("Type error: argument " "0" " should be " "hash" );
            return oRes.toJSON();
        }
    }








    if ( argc > nCallbackArg )
    {


        if ( !argv[nCallbackArg].isString() )
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toJSON();
        }

        oRes.setCallInUIThread(false);
        oRes.setRubyCallback( argv[nCallbackArg].getString() );
        if ( argc > nCallbackArg + 1 )
        {
            if ( !argv[nCallbackArg + 1].isString() )
            {
                oRes.setArgError("Type error: callback parameter should be String");
                return oRes.toJSON();
            }

            oRes.setCallbackParam( argv[nCallbackArg + 1].getString() );
        }

    }


    pFunctor = rho_makeInstanceClassFunctor2( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::search, arg0,  oRes );



    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->search( arg0,  oRes );


    }


    return oRes.toJSON();

}

rho::String js_s_RhoConnectClient_doSync(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int argc = argv.getSize();
    int nCallbackArg = 0;



    nCallbackArg = 1;

    






    bool arg0;
    if ( argc > 0 )
    {
        if ( argv[0].isString() )
            arg0 = argv[0].getInt() ? true : false;
        else if (!argv[0].isNull())
        {
            oRes.setArgError("Type error: argument " "0" " should be " "boolean" );
            return oRes.toJSON();
        }
    }













    nCallbackArg = 2;

    


    rho::String arg1;
    if ( argc > 1 )
    {
        if ( argv[1].isString() )
        {
            arg1 = argv[1].getString();

        }
        else if (!argv[1].isNull())
        {
            oRes.setArgError( "Type error: argument " "1" " should be " "string" );
            return oRes.toJSON();
        }
    }

















    nCallbackArg = 3;

    






    bool arg2;
    if ( argc > 2 )
    {
        if ( argv[2].isString() )
            arg2 = argv[2].getInt() ? true : false;
        else if (!argv[2].isNull())
        {
            oRes.setArgError("Type error: argument " "2" " should be " "boolean" );
            return oRes.toJSON();
        }
    }














    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(3) );
        return oRes.toJSON();


        if ( !argv[nCallbackArg].isString() )
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toJSON();
        }

        oRes.setCallInUIThread(false);
        oRes.setRubyCallback( argv[nCallbackArg].getString() );
        if ( argc > nCallbackArg + 1 )
        {
            if ( !argv[nCallbackArg + 1].isString() )
            {
                oRes.setArgError("Type error: callback parameter should be String");
                return oRes.toJSON();
            }

            oRes.setCallbackParam( argv[nCallbackArg + 1].getString() );
        }

    }


    pFunctor = rho_makeInstanceClassFunctor4( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::doSync, arg0, arg1, arg2,  oRes );




    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->doSync( arg0, arg1, arg2,  oRes );


    }


    return oRes.toJSON();

}

rho::String js_s_RhoConnectClient_doSyncSource(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int argc = argv.getSize();
    int nCallbackArg = 0;



    nCallbackArg = 1;

    
    if ( argc == 0 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(3) );
        return oRes.toJSON();
    }
    


    rho::String arg0;
    if ( argc > 0 )
    {
        if ( argv[0].isString() )
        {
            arg0 = argv[0].getString();

            oRes.setParamName(argv[0].getString());

        }
        else if (!argv[0].isNull())
        {
            oRes.setArgError( "Type error: argument " "0" " should be " "string" );
            return oRes.toJSON();
        }
    }

















    nCallbackArg = 2;

    






    bool arg1;
    if ( argc > 1 )
    {
        if ( argv[1].isString() )
            arg1 = argv[1].getInt() ? true : false;
        else if (!argv[1].isNull())
        {
            oRes.setArgError("Type error: argument " "1" " should be " "boolean" );
            return oRes.toJSON();
        }
    }













    nCallbackArg = 3;

    


    rho::String arg2;
    if ( argc > 2 )
    {
        if ( argv[2].isString() )
        {
            arg2 = argv[2].getString();

        }
        else if (!argv[2].isNull())
        {
            oRes.setArgError( "Type error: argument " "2" " should be " "string" );
            return oRes.toJSON();
        }
    }


















    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(3) );
        return oRes.toJSON();


        if ( !argv[nCallbackArg].isString() )
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toJSON();
        }

        oRes.setCallInUIThread(false);
        oRes.setRubyCallback( argv[nCallbackArg].getString() );
        if ( argc > nCallbackArg + 1 )
        {
            if ( !argv[nCallbackArg + 1].isString() )
            {
                oRes.setArgError("Type error: callback parameter should be String");
                return oRes.toJSON();
            }

            oRes.setCallbackParam( argv[nCallbackArg + 1].getString() );
        }

    }


    pFunctor = rho_makeInstanceClassFunctor4( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::doSyncSource, arg0, arg1, arg2,  oRes );




    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->doSyncSource( arg0, arg1, arg2,  oRes );


    }


    return oRes.toJSON();

}

rho::String js_s_RhoConnectClient_login(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int argc = argv.getSize();
    int nCallbackArg = 0;



    nCallbackArg = 1;

    
    if ( argc == 0 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(2) );
        return oRes.toJSON();
    }
    


    rho::String arg0;
    if ( argc > 0 )
    {
        if ( argv[0].isString() )
        {
            arg0 = argv[0].getString();

            oRes.setParamName(argv[0].getString());

        }
        else if (!argv[0].isNull())
        {
            oRes.setArgError( "Type error: argument " "0" " should be " "string" );
            return oRes.toJSON();
        }
    }

















    nCallbackArg = 2;

    
    if ( argc == 1 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(2) );
        return oRes.toJSON();
    }
    


    rho::String arg1;
    if ( argc > 1 )
    {
        if ( argv[1].isString() )
        {
            arg1 = argv[1].getString();

        }
        else if (!argv[1].isNull())
        {
            oRes.setArgError( "Type error: argument " "1" " should be " "string" );
            return oRes.toJSON();
        }
    }


















    if ( argc > nCallbackArg )
    {


        if ( !argv[nCallbackArg].isString() )
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toJSON();
        }

        oRes.setCallInUIThread(false);
        oRes.setRubyCallback( argv[nCallbackArg].getString() );
        if ( argc > nCallbackArg + 1 )
        {
            if ( !argv[nCallbackArg + 1].isString() )
            {
                oRes.setArgError("Type error: callback parameter should be String");
                return oRes.toJSON();
            }

            oRes.setCallbackParam( argv[nCallbackArg + 1].getString() );
        }

    }


    pFunctor = rho_makeInstanceClassFunctor3( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::login, arg0, arg1,  oRes );



    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->login( arg0, arg1,  oRes );


    }


    return oRes.toJSON();

}

rho::String js_s_RhoConnectClient_logout(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int argc = argv.getSize();
    int nCallbackArg = 0;




    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(0) );
        return oRes.toJSON();


        if ( !argv[nCallbackArg].isString() )
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toJSON();
        }

        oRes.setCallInUIThread(false);
        oRes.setRubyCallback( argv[nCallbackArg].getString() );
        if ( argc > nCallbackArg + 1 )
        {
            if ( !argv[nCallbackArg + 1].isString() )
            {
                oRes.setArgError("Type error: callback parameter should be String");
                return oRes.toJSON();
            }

            oRes.setCallbackParam( argv[nCallbackArg + 1].getString() );
        }

    }


    pFunctor = rho_makeInstanceClassFunctor1( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::logout,  oRes );




    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->logout(  oRes );


    }


    return oRes.toJSON();

}

rho::String js_s_RhoConnectClient_stopSync(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int argc = argv.getSize();
    int nCallbackArg = 0;




    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(0) );
        return oRes.toJSON();


        if ( !argv[nCallbackArg].isString() )
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toJSON();
        }

        oRes.setCallInUIThread(false);
        oRes.setRubyCallback( argv[nCallbackArg].getString() );
        if ( argc > nCallbackArg + 1 )
        {
            if ( !argv[nCallbackArg + 1].isString() )
            {
                oRes.setArgError("Type error: callback parameter should be String");
                return oRes.toJSON();
            }

            oRes.setCallbackParam( argv[nCallbackArg + 1].getString() );
        }

    }


    pFunctor = rho_makeInstanceClassFunctor1( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::stopSync,  oRes );




    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->stopSync(  oRes );


    }


    return oRes.toJSON();

}

rho::String js_s_RhoConnectClient_setNotification(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int argc = argv.getSize();
    int nCallbackArg = 0;



    nCallbackArg = 1;

    
    if ( argc == 0 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toJSON();
    }
    


    rho::String arg0;
    if ( argc > 0 )
    {
        if ( argv[0].isString() )
        {
            arg0 = argv[0].getString();

            oRes.setParamName(argv[0].getString());

        }
        else if (!argv[0].isNull())
        {
            oRes.setArgError( "Type error: argument " "0" " should be " "string" );
            return oRes.toJSON();
        }
    }


















    if ( argc > nCallbackArg )
    {


        if ( !argv[nCallbackArg].isString() )
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toJSON();
        }

        oRes.setCallInUIThread(false);
        oRes.setRubyCallback( argv[nCallbackArg].getString() );
        if ( argc > nCallbackArg + 1 )
        {
            if ( !argv[nCallbackArg + 1].isString() )
            {
                oRes.setArgError("Type error: callback parameter should be String");
                return oRes.toJSON();
            }

            oRes.setCallbackParam( argv[nCallbackArg + 1].getString() );
        }

    }


    pFunctor = rho_makeInstanceClassFunctor2( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::setNotification, arg0,  oRes );



    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->setNotification( arg0,  oRes );


    }


    return oRes.toJSON();

}

rho::String js_s_RhoConnectClient_clearNotification(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int argc = argv.getSize();
    int nCallbackArg = 0;



    nCallbackArg = 1;

    
    if ( argc == 0 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toJSON();
    }
    


    rho::String arg0;
    if ( argc > 0 )
    {
        if ( argv[0].isString() )
        {
            arg0 = argv[0].getString();

            oRes.setParamName(argv[0].getString());

        }
        else if (!argv[0].isNull())
        {
            oRes.setArgError( "Type error: argument " "0" " should be " "string" );
            return oRes.toJSON();
        }
    }


















    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toJSON();


        if ( !argv[nCallbackArg].isString() )
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toJSON();
        }

        oRes.setCallInUIThread(false);
        oRes.setRubyCallback( argv[nCallbackArg].getString() );
        if ( argc > nCallbackArg + 1 )
        {
            if ( !argv[nCallbackArg + 1].isString() )
            {
                oRes.setArgError("Type error: callback parameter should be String");
                return oRes.toJSON();
            }

            oRes.setCallbackParam( argv[nCallbackArg + 1].getString() );
        }

    }


    pFunctor = rho_makeInstanceClassFunctor2( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::clearNotification, arg0,  oRes );




    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->clearNotification( arg0,  oRes );


    }


    return oRes.toJSON();

}

rho::String js_s_RhoConnectClient_setObjectNotification(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int argc = argv.getSize();
    int nCallbackArg = 0;




    if ( argc > nCallbackArg )
    {


        if ( !argv[nCallbackArg].isString() )
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toJSON();
        }

        oRes.setCallInUIThread(false);
        oRes.setRubyCallback( argv[nCallbackArg].getString() );
        if ( argc > nCallbackArg + 1 )
        {
            if ( !argv[nCallbackArg + 1].isString() )
            {
                oRes.setArgError("Type error: callback parameter should be String");
                return oRes.toJSON();
            }

            oRes.setCallbackParam( argv[nCallbackArg + 1].getString() );
        }

    }


    pFunctor = rho_makeInstanceClassFunctor1( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::setObjectNotification,  oRes );



    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->setObjectNotification(  oRes );


    }


    return oRes.toJSON();

}

rho::String js_s_RhoConnectClient_addObjectNotify(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int argc = argv.getSize();
    int nCallbackArg = 0;



    nCallbackArg = 1;

    
    if ( argc == 0 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(2) );
        return oRes.toJSON();
    }
    


    rho::String arg0;
    if ( argc > 0 )
    {
        if ( argv[0].isString() )
        {
            arg0 = argv[0].getString();

            oRes.setParamName(argv[0].getString());

        }
        else if (!argv[0].isNull())
        {
            oRes.setArgError( "Type error: argument " "0" " should be " "string" );
            return oRes.toJSON();
        }
    }

















    nCallbackArg = 2;

    
    if ( argc == 1 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(2) );
        return oRes.toJSON();
    }
    


    rho::String arg1;
    if ( argc > 1 )
    {
        if ( argv[1].isString() )
        {
            arg1 = argv[1].getString();

        }
        else if (!argv[1].isNull())
        {
            oRes.setArgError( "Type error: argument " "1" " should be " "string" );
            return oRes.toJSON();
        }
    }


















    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(2) );
        return oRes.toJSON();


        if ( !argv[nCallbackArg].isString() )
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toJSON();
        }

        oRes.setCallInUIThread(false);
        oRes.setRubyCallback( argv[nCallbackArg].getString() );
        if ( argc > nCallbackArg + 1 )
        {
            if ( !argv[nCallbackArg + 1].isString() )
            {
                oRes.setArgError("Type error: callback parameter should be String");
                return oRes.toJSON();
            }

            oRes.setCallbackParam( argv[nCallbackArg + 1].getString() );
        }

    }


    pFunctor = rho_makeInstanceClassFunctor3( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::addObjectNotify, arg0, arg1,  oRes );




    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addObjectNotify( arg0, arg1,  oRes );


    }


    return oRes.toJSON();

}

rho::String js_s_RhoConnectClient_cleanObjectNotify(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int argc = argv.getSize();
    int nCallbackArg = 0;




    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(0) );
        return oRes.toJSON();


        if ( !argv[nCallbackArg].isString() )
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toJSON();
        }

        oRes.setCallInUIThread(false);
        oRes.setRubyCallback( argv[nCallbackArg].getString() );
        if ( argc > nCallbackArg + 1 )
        {
            if ( !argv[nCallbackArg + 1].isString() )
            {
                oRes.setArgError("Type error: callback parameter should be String");
                return oRes.toJSON();
            }

            oRes.setCallbackParam( argv[nCallbackArg + 1].getString() );
        }

    }


    pFunctor = rho_makeInstanceClassFunctor1( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::cleanObjectNotify,  oRes );




    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->cleanObjectNotify(  oRes );


    }


    return oRes.toJSON();

}

rho::String js_s_RhoConnectClient_getLastSyncObjectCount(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int argc = argv.getSize();
    int nCallbackArg = 0;



    nCallbackArg = 1;

    
    if ( argc == 0 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toJSON();
    }
    


    rho::String arg0;
    if ( argc > 0 )
    {
        if ( argv[0].isString() )
        {
            arg0 = argv[0].getString();

            oRes.setParamName(argv[0].getString());

        }
        else if (!argv[0].isNull())
        {
            oRes.setArgError( "Type error: argument " "0" " should be " "string" );
            return oRes.toJSON();
        }
    }


















    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(1) );
        return oRes.toJSON();


        if ( !argv[nCallbackArg].isString() )
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toJSON();
        }

        oRes.setCallInUIThread(false);
        oRes.setRubyCallback( argv[nCallbackArg].getString() );
        if ( argc > nCallbackArg + 1 )
        {
            if ( !argv[nCallbackArg + 1].isString() )
            {
                oRes.setArgError("Type error: callback parameter should be String");
                return oRes.toJSON();
            }

            oRes.setCallbackParam( argv[nCallbackArg + 1].getString() );
        }

    }


    pFunctor = rho_makeInstanceClassFunctor2( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::getLastSyncObjectCount, arg0,  oRes );




    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->getLastSyncObjectCount( arg0,  oRes );


    }


    return oRes.toJSON();

}

rho::String js_s_RhoConnectClient_setSourceProperty(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int argc = argv.getSize();
    int nCallbackArg = 0;



    nCallbackArg = 1;

    
    if ( argc == 0 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(3) );
        return oRes.toJSON();
    }
    


    rho::String arg0;
    if ( argc > 0 )
    {
        if ( argv[0].isString() )
        {
            arg0 = argv[0].getString();

            oRes.setParamName(argv[0].getString());

        }
        else if (!argv[0].isNull())
        {
            oRes.setArgError( "Type error: argument " "0" " should be " "string" );
            return oRes.toJSON();
        }
    }

















    nCallbackArg = 2;

    
    if ( argc == 1 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(3) );
        return oRes.toJSON();
    }
    


    rho::String arg1;
    if ( argc > 1 )
    {
        if ( argv[1].isString() )
        {
            arg1 = argv[1].getString();

        }
        else if (!argv[1].isNull())
        {
            oRes.setArgError( "Type error: argument " "1" " should be " "string" );
            return oRes.toJSON();
        }
    }

















    nCallbackArg = 3;

    
    if ( argc == 2 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(3) );
        return oRes.toJSON();
    }
    


    rho::String arg2;
    if ( argc > 2 )
    {
        if ( argv[2].isString() )
        {
            arg2 = argv[2].getString();

        }
        else if (!argv[2].isNull())
        {
            oRes.setArgError( "Type error: argument " "2" " should be " "string" );
            return oRes.toJSON();
        }
    }


















    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(3) );
        return oRes.toJSON();


        if ( !argv[nCallbackArg].isString() )
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toJSON();
        }

        oRes.setCallInUIThread(false);
        oRes.setRubyCallback( argv[nCallbackArg].getString() );
        if ( argc > nCallbackArg + 1 )
        {
            if ( !argv[nCallbackArg + 1].isString() )
            {
                oRes.setArgError("Type error: callback parameter should be String");
                return oRes.toJSON();
            }

            oRes.setCallbackParam( argv[nCallbackArg + 1].getString() );
        }

    }


    pFunctor = rho_makeInstanceClassFunctor4( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::setSourceProperty, arg0, arg1, arg2,  oRes );




    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->setSourceProperty( arg0, arg1, arg2,  oRes );


    }


    return oRes.toJSON();

}

rho::String js_s_RhoConnectClient_getSourceProperty(rho::json::CJSONArray& argv, const rho::String& strObjID)
{
    rho::apiGenerator::CMethodResult oRes;

    rho::common::CInstanceClassFunctorBase<rho::apiGenerator::CMethodResult>* pFunctor = 0;
    bool bUseCallback = false;
    int argc = argv.getSize();
    int nCallbackArg = 0;



    nCallbackArg = 1;

    
    if ( argc == 0 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(2) );
        return oRes.toJSON();
    }
    


    rho::String arg0;
    if ( argc > 0 )
    {
        if ( argv[0].isString() )
        {
            arg0 = argv[0].getString();

            oRes.setParamName(argv[0].getString());

        }
        else if (!argv[0].isNull())
        {
            oRes.setArgError( "Type error: argument " "0" " should be " "string" );
            return oRes.toJSON();
        }
    }

















    nCallbackArg = 2;

    
    if ( argc == 1 )
    {
        oRes.setArgError( "Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(2) );
        return oRes.toJSON();
    }
    


    rho::String arg1;
    if ( argc > 1 )
    {
        if ( argv[1].isString() )
        {
            arg1 = argv[1].getString();

        }
        else if (!argv[1].isNull())
        {
            oRes.setArgError( "Type error: argument " "1" " should be " "string" );
            return oRes.toJSON();
        }
    }


















    if ( argc > nCallbackArg )
    {

        oRes.setArgError("Wrong number of arguments: " + convertToStringA(argc) + " instead of " + convertToStringA(2) );
        return oRes.toJSON();


        if ( !argv[nCallbackArg].isString() )
        {
            oRes.setArgError("Type error: callback should be String");
            return oRes.toJSON();
        }

        oRes.setCallInUIThread(false);
        oRes.setRubyCallback( argv[nCallbackArg].getString() );
        if ( argc > nCallbackArg + 1 )
        {
            if ( !argv[nCallbackArg + 1].isString() )
            {
                oRes.setArgError("Type error: callback parameter should be String");
                return oRes.toJSON();
            }

            oRes.setCallbackParam( argv[nCallbackArg + 1].getString() );
        }

    }


    pFunctor = rho_makeInstanceClassFunctor3( rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS(), &rho::IRhoConnectClientSingleton::getSourceProperty, arg0, arg1,  oRes );




    if ( bUseCallback )
        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->addCommandToQueue( pFunctor );
    else 
    {
        delete pFunctor;


        rho::CRhoConnectClientFactoryBase::getRhoConnectClientSingletonS()->getSourceProperty( arg0, arg1,  oRes );


    }


    return oRes.toJSON();

}



