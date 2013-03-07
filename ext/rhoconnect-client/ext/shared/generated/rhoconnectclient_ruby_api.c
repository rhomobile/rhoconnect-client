
#include "ruby.h"

static VALUE rb_mParent;
static VALUE rb_mRhoConnectClient;

VALUE rb_s_RhoConnectClient_getUserName(int argc, VALUE *argv);
VALUE rb_s_RhoConnectClient_getPollInterval(int argc, VALUE *argv);
VALUE rb_s_RhoConnectClient_setPollInterval(int argc, VALUE *argv);
VALUE rb_s_RhoConnectClient_getSyncServer(int argc, VALUE *argv);
VALUE rb_s_RhoConnectClient_setSyncServer(int argc, VALUE *argv);
VALUE rb_s_RhoConnectClient_getPageSize(int argc, VALUE *argv);
VALUE rb_s_RhoConnectClient_setPageSize(int argc, VALUE *argv);
VALUE rb_s_RhoConnectClient_getThreadedMode(int argc, VALUE *argv);
VALUE rb_s_RhoConnectClient_setThreadedMode(int argc, VALUE *argv);
VALUE rb_s_RhoConnectClient_getShowStatusPopup(int argc, VALUE *argv);
VALUE rb_s_RhoConnectClient_setShowStatusPopup(int argc, VALUE *argv);
VALUE rb_s_RhoConnectClient_getSslVerifyPeer(int argc, VALUE *argv);
VALUE rb_s_RhoConnectClient_setSslVerifyPeer(int argc, VALUE *argv);
VALUE rb_s_RhoConnectClient_loggedIn(int argc, VALUE *argv);
VALUE rb_s_RhoConnectClient_syncing(int argc, VALUE *argv);
VALUE rb_s_RhoConnectClient_search(int argc, VALUE *argv);
VALUE rb_s_RhoConnectClient_doSync(int argc, VALUE *argv);
VALUE rb_s_RhoConnectClient_doSyncSource(int argc, VALUE *argv);
VALUE rb_s_RhoConnectClient_login(int argc, VALUE *argv);
VALUE rb_s_RhoConnectClient_logout(int argc, VALUE *argv);
VALUE rb_s_RhoConnectClient_stopSync(int argc, VALUE *argv);
VALUE rb_s_RhoConnectClient_setNotification(int argc, VALUE *argv);
VALUE rb_s_RhoConnectClient_clearNotification(int argc, VALUE *argv);
VALUE rb_s_RhoConnectClient_setObjectNotification(int argc, VALUE *argv);
VALUE rb_s_RhoConnectClient_addObjectNotify(int argc, VALUE *argv);
VALUE rb_s_RhoConnectClient_cleanObjectNotify(int argc, VALUE *argv);
VALUE rb_s_RhoConnectClient_getLastSyncObjectCount(int argc, VALUE *argv);
VALUE rb_s_RhoConnectClient_setSourceProperty(int argc, VALUE *argv);
VALUE rb_s_RhoConnectClient_getSourceProperty(int argc, VALUE *argv);




VALUE getRuby_RhoConnectClient_Module(){ return rb_mRhoConnectClient; }



static void _free_class_object(void *p)
{
    ruby_xfree(p);
}

static VALUE _allocate_class_object(VALUE klass)
{
    VALUE valObj = 0;
    char ** ppString = NULL;
    void* pData = ALLOC(void*);
    memset( pData, 0, sizeof(pData) );
    
	valObj = Data_Wrap_Struct(klass, 0, _free_class_object, pData);

    Data_Get_Struct(valObj, char *, ppString);
    *ppString = xmalloc(10);
    sprintf(*ppString, "%X", valObj);

    return valObj;
}

void Init_RubyAPI_RhoConnectClient(void)
{

    VALUE tmpParent = Qnil;
    rb_mParent = rb_define_module("Rho");
    

	rb_mRhoConnectClient = rb_define_class_under(rb_mParent, "RhoConnectClient", rb_cObject);

	rb_define_alloc_func(rb_mRhoConnectClient, _allocate_class_object);
    //Constructor should be not available in case of static members
    //rb_undef_alloc_func(rb_mRhoConnectClient);

    rb_define_singleton_method(rb_mRhoConnectClient, "userName", rb_s_RhoConnectClient_getUserName, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "pollInterval", rb_s_RhoConnectClient_getPollInterval, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "pollInterval=", rb_s_RhoConnectClient_setPollInterval, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "syncServer", rb_s_RhoConnectClient_getSyncServer, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "syncServer=", rb_s_RhoConnectClient_setSyncServer, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "pageSize", rb_s_RhoConnectClient_getPageSize, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "pageSize=", rb_s_RhoConnectClient_setPageSize, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "threadedMode", rb_s_RhoConnectClient_getThreadedMode, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "threadedMode=", rb_s_RhoConnectClient_setThreadedMode, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "showStatusPopup", rb_s_RhoConnectClient_getShowStatusPopup, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "showStatusPopup=", rb_s_RhoConnectClient_setShowStatusPopup, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "sslVerifyPeer", rb_s_RhoConnectClient_getSslVerifyPeer, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "sslVerifyPeer=", rb_s_RhoConnectClient_setSslVerifyPeer, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "loggedIn?", rb_s_RhoConnectClient_loggedIn, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "syncing?", rb_s_RhoConnectClient_syncing, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "search", rb_s_RhoConnectClient_search, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "doSync", rb_s_RhoConnectClient_doSync, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "doSyncSource", rb_s_RhoConnectClient_doSyncSource, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "login", rb_s_RhoConnectClient_login, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "logout", rb_s_RhoConnectClient_logout, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "stopSync", rb_s_RhoConnectClient_stopSync, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "setNotification", rb_s_RhoConnectClient_setNotification, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "clearNotification", rb_s_RhoConnectClient_clearNotification, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "setObjectNotification", rb_s_RhoConnectClient_setObjectNotification, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "addObjectNotify", rb_s_RhoConnectClient_addObjectNotify, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "cleanObjectNotify", rb_s_RhoConnectClient_cleanObjectNotify, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "getLastSyncObjectCount", rb_s_RhoConnectClient_getLastSyncObjectCount, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "setSourceProperty", rb_s_RhoConnectClient_setSourceProperty, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "getSourceProperty", rb_s_RhoConnectClient_getSourceProperty, -1);






    rb_define_alias(rb_singleton_class(rb_mRhoConnectClient), "dosync", "doSync");
    rb_define_alias(rb_singleton_class(rb_mRhoConnectClient), "add_objectnotify", "addObjectNotify");
    rb_define_alias(rb_singleton_class(rb_mRhoConnectClient), "clean_objectnotify", "cleanObjectNotify");
    rb_define_alias(rb_singleton_class(rb_mRhoConnectClient), "stop_sync", "stopSync");


    rb_const_set(rb_mKernel, rb_intern("SyncEngine"), rb_mRhoConnectClient );
}

