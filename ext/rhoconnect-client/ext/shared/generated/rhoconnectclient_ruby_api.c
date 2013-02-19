
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
VALUE rb_s_RhoConnectClient_onSyncCreateError(int argc, VALUE *argv);
VALUE rb_s_RhoConnectClient_pushChanges(int argc, VALUE *argv);
VALUE rb_s_RhoConnectClient_onSyncUpdateError(int argc, VALUE *argv);
VALUE rb_s_RhoConnectClient_onSyncDeleteError(int argc, VALUE *argv);
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



void Init_RubyAPI_RhoConnectClient(void)
{

    VALUE tmpParent = Qnil;
    rb_mParent = rb_define_module("Rho");
    

	rb_mRhoConnectClient = rb_define_class_under(rb_mParent, "RhoConnectClient", rb_cObject);

    //Constructor should be not available
	//rb_define_alloc_func(rb_cBarcode1, rb_barcode1_allocate);
    //rb_undef_alloc_func(rb_mRhoConnectClient);

    rb_define_singleton_method(rb_mRhoConnectClient, "userName", rb_s_RhoConnectClient_getUserName, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "pollInterval", rb_s_RhoConnectClient_getPollInterval, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "pollInterval=", rb_s_RhoConnectClient_setPollInterval, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "syncServer", rb_s_RhoConnectClient_getSyncServer, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "syncServer=", rb_s_RhoConnectClient_setSyncServer, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "pageSize", rb_s_RhoConnectClient_getPageSize, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "pageSize=", rb_s_RhoConnectClient_setPageSize, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "threadedMode?", rb_s_RhoConnectClient_getThreadedMode, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "threadedMode?=", rb_s_RhoConnectClient_setThreadedMode, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "showStatusPopup?", rb_s_RhoConnectClient_getShowStatusPopup, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "showStatusPopup?=", rb_s_RhoConnectClient_setShowStatusPopup, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "sslVerifyPeer?", rb_s_RhoConnectClient_getSslVerifyPeer, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "sslVerifyPeer?=", rb_s_RhoConnectClient_setSslVerifyPeer, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "loggedIn?", rb_s_RhoConnectClient_loggedIn, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "syncing?", rb_s_RhoConnectClient_syncing, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "onSyncCreateError", rb_s_RhoConnectClient_onSyncCreateError, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "pushChanges", rb_s_RhoConnectClient_pushChanges, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "onSyncUpdateError", rb_s_RhoConnectClient_onSyncUpdateError, -1);
    rb_define_singleton_method(rb_mRhoConnectClient, "onSyncDeleteError", rb_s_RhoConnectClient_onSyncDeleteError, -1);
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
    rb_define_alias(rb_singleton_class(rb_mRhoConnectClient), "dosync_source", "doSyncSource");
    rb_define_alias(rb_singleton_class(rb_mRhoConnectClient), "logged_in", "loggedIn?");
    rb_define_alias(rb_singleton_class(rb_mRhoConnectClient), "is_syncing", "syncing?");
    rb_define_alias(rb_singleton_class(rb_mRhoConnectClient), "set_objectnotify_url", "SetObjectNotification");
    rb_define_alias(rb_singleton_class(rb_mRhoConnectClient), "poll_interval=", "pollInterval=");
    rb_define_alias(rb_singleton_class(rb_mRhoConnectClient), "sync_server=", "syncServer=");
    rb_define_alias(rb_singleton_class(rb_mRhoConnectClient), "page_size=", "pageSize=");
    rb_define_alias(rb_singleton_class(rb_mRhoConnectClient), "threaded_mode?", "threadedMode?");
    rb_define_alias(rb_singleton_class(rb_mRhoConnectClient), "threaded_mode?=", "threadedMode?=");
    rb_define_alias(rb_singleton_class(rb_mRhoConnectClient), "show_status_popup?", "showStatusPopup?");
    rb_define_alias(rb_singleton_class(rb_mRhoConnectClient), "show_status_popup?=", "showStatusPopup?=");
    rb_define_alias(rb_singleton_class(rb_mRhoConnectClient), "ssl_verify_peer?", "sslVerifyPeer?");
    rb_define_alias(rb_singleton_class(rb_mRhoConnectClient), "ssl_verify_peer?=", "sslVerifyPeer?=");
    rb_define_alias(rb_singleton_class(rb_mRhoConnectClient), "logged_in?", "loggedIn?");
    rb_define_alias(rb_singleton_class(rb_mRhoConnectClient), "on_sync_create_error", "onSyncCreateError");
    rb_define_alias(rb_singleton_class(rb_mRhoConnectClient), "push_changes", "pushChanges");
    rb_define_alias(rb_singleton_class(rb_mRhoConnectClient), "on_sync_update_error", "onSyncUpdateError");
    rb_define_alias(rb_singleton_class(rb_mRhoConnectClient), "on_sync_delete_error", "onSyncDeleteError");
    rb_define_alias(rb_singleton_class(rb_mRhoConnectClient), "do_sync", "doSync");
    rb_define_alias(rb_singleton_class(rb_mRhoConnectClient), "do_sync_source", "doSyncSource");
    rb_define_alias(rb_singleton_class(rb_mRhoConnectClient), "stop_sync", "stopSync");
    rb_define_alias(rb_singleton_class(rb_mRhoConnectClient), "set_notification", "setNotification");
    rb_define_alias(rb_singleton_class(rb_mRhoConnectClient), "clear_notification", "clearNotification");
    rb_define_alias(rb_singleton_class(rb_mRhoConnectClient), "set_object_notification", "setObjectNotification");
    rb_define_alias(rb_singleton_class(rb_mRhoConnectClient), "add_object_notify", "addObjectNotify");
    rb_define_alias(rb_singleton_class(rb_mRhoConnectClient), "clean_object_notify", "cleanObjectNotify");
    rb_define_alias(rb_singleton_class(rb_mRhoConnectClient), "get_last_sync_object_count", "getLastSyncObjectCount");
    rb_define_alias(rb_singleton_class(rb_mRhoConnectClient), "set_source_property", "setSourceProperty");
    rb_define_alias(rb_singleton_class(rb_mRhoConnectClient), "get_source_property", "getSourceProperty");

//TODO: support module aliases
    rb_const_set(rb_mKernel, rb_intern("RhoConnectClient"), rb_mRhoConnectClient );
}

