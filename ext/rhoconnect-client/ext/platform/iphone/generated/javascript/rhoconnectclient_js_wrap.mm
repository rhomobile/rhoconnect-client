#import "IRhoConnectClient.h"
//#import "api_generator/common/ruby_helpers.h"

#include "api_generator/js_helpers.h"

#import "api_generator/iphone/CMethodResult.h"
#import "api_generator/iphone/CJSConverter.h"

extern VALUE getRuby_RhoConnectClient_Module();



id<IRhoConnectClient> RhoConnectClient_makeInstanceByJSObject(rho::String sid) {
    const char* szID = sid.c_str();
    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    return [factory getRhoConnectClientByID:[NSString stringWithUTF8String:szID]];
}









@interface RhoConnectClient_getUserName_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(RhoConnectClient_getUserName_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation RhoConnectClient_getUserName_caller_params

@synthesize params,item,methodResult;

+(RhoConnectClient_getUserName_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    RhoConnectClient_getUserName_caller_params* par = [[RhoConnectClient_getUserName_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface RhoConnectClient_getUserName_caller : NSObject {

}
+(RhoConnectClient_getUserName_caller*) getSharedInstance;
+(void) getUserName:(RhoConnectClient_getUserName_caller_params*)caller_params;
+(void) getUserName_in_thread:(RhoConnectClient_getUserName_caller_params*)caller_params;
+(void) getUserName_in_UI_thread:(RhoConnectClient_getUserName_caller_params*)caller_params;

@end

static RhoConnectClient_getUserName_caller* our_RhoConnectClient_getUserName_caller = nil;

@implementation RhoConnectClient_getUserName_caller

+(RhoConnectClient_getUserName_caller*) getSharedInstance {
    if (our_RhoConnectClient_getUserName_caller == nil) {
        our_RhoConnectClient_getUserName_caller = [[RhoConnectClient_getUserName_caller alloc] init];
    }
    return our_RhoConnectClient_getUserName_caller;
}

-(void) command_getUserName:(RhoConnectClient_getUserName_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem getUserName:methodResult ];
}


+(void) getUserName:(RhoConnectClient_getUserName_caller_params*)caller_params {
    [[RhoConnectClient_getUserName_caller getSharedInstance] command_getUserName:caller_params];
}

+(void) getUserName_in_thread:(RhoConnectClient_getUserName_caller_params*)caller_params {
    [[RhoConnectClient_getUserName_caller getSharedInstance] performSelectorInBackground:@selector(command_getUserName:) withObject:caller_params];
}

+(void) getUserName_in_UI_thread:(RhoConnectClient_getUserName_caller_params*)caller_params {
    [[RhoConnectClient_getUserName_caller getSharedInstance] performSelectorOnMainThread:@selector(command_getUserName:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_RhoConnectClient_getUserName_Obj(rho::json::CJSONArray& argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[0+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    int argc = argv.getSize();
    
    static RHO_API_PARAM rho_api_params[] = {  };

    
    BOOL is_factory_param[] = { NO };

    int i;

    // init
    for (i = 0; i < (0); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    // enumerate params
    for (int i = 0; i < (0); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(0)];
    for (i = 0 ; i < (0); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (0+1)) {
        rho::json::CJSONEntry callback = argv.getItem(0);
        if (callback.isString()) {
            rho::json::CJSONEntry entry = argv.getItem(i);
            callbackURL = [((NSString*)[CJSConverter convertFromJS:&callback]) retain];
        }
    }
    // check callback param
    if (argc >= (0+2)) {
        rho::json::CJSONEntry callback_param = argv.getItem(0+1);
        if (callback_param.isString()) {
            callbackParam = [((NSString*)[CJSConverter convertFromJS:&callback_param]) retain];
        }
    }
    

    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [RhoConnectClient_getUserName_caller getUserName_in_thread:[RhoConnectClient_getUserName_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [RhoConnectClient_getUserName_caller getUserName:[RhoConnectClient_getUserName_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = "";
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    return resValue;
}


rho::String js_s_RhoConnectClient_getUserName(rho::json::CJSONArray& argv, const rho::String& strObjID) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return js_RhoConnectClient_getUserName_Obj(argv, singleton);

}







@interface RhoConnectClient_getPollInterval_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(RhoConnectClient_getPollInterval_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation RhoConnectClient_getPollInterval_caller_params

@synthesize params,item,methodResult;

+(RhoConnectClient_getPollInterval_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    RhoConnectClient_getPollInterval_caller_params* par = [[RhoConnectClient_getPollInterval_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface RhoConnectClient_getPollInterval_caller : NSObject {

}
+(RhoConnectClient_getPollInterval_caller*) getSharedInstance;
+(void) getPollInterval:(RhoConnectClient_getPollInterval_caller_params*)caller_params;
+(void) getPollInterval_in_thread:(RhoConnectClient_getPollInterval_caller_params*)caller_params;
+(void) getPollInterval_in_UI_thread:(RhoConnectClient_getPollInterval_caller_params*)caller_params;

@end

static RhoConnectClient_getPollInterval_caller* our_RhoConnectClient_getPollInterval_caller = nil;

@implementation RhoConnectClient_getPollInterval_caller

+(RhoConnectClient_getPollInterval_caller*) getSharedInstance {
    if (our_RhoConnectClient_getPollInterval_caller == nil) {
        our_RhoConnectClient_getPollInterval_caller = [[RhoConnectClient_getPollInterval_caller alloc] init];
    }
    return our_RhoConnectClient_getPollInterval_caller;
}

-(void) command_getPollInterval:(RhoConnectClient_getPollInterval_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem getPollInterval:methodResult ];
}


+(void) getPollInterval:(RhoConnectClient_getPollInterval_caller_params*)caller_params {
    [[RhoConnectClient_getPollInterval_caller getSharedInstance] command_getPollInterval:caller_params];
}

+(void) getPollInterval_in_thread:(RhoConnectClient_getPollInterval_caller_params*)caller_params {
    [[RhoConnectClient_getPollInterval_caller getSharedInstance] performSelectorInBackground:@selector(command_getPollInterval:) withObject:caller_params];
}

+(void) getPollInterval_in_UI_thread:(RhoConnectClient_getPollInterval_caller_params*)caller_params {
    [[RhoConnectClient_getPollInterval_caller getSharedInstance] performSelectorOnMainThread:@selector(command_getPollInterval:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_RhoConnectClient_getPollInterval_Obj(rho::json::CJSONArray& argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[0+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    int argc = argv.getSize();
    
    static RHO_API_PARAM rho_api_params[] = {  };

    
    BOOL is_factory_param[] = { NO };

    int i;

    // init
    for (i = 0; i < (0); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    // enumerate params
    for (int i = 0; i < (0); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(0)];
    for (i = 0 ; i < (0); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (0+1)) {
        rho::json::CJSONEntry callback = argv.getItem(0);
        if (callback.isString()) {
            rho::json::CJSONEntry entry = argv.getItem(i);
            callbackURL = [((NSString*)[CJSConverter convertFromJS:&callback]) retain];
        }
    }
    // check callback param
    if (argc >= (0+2)) {
        rho::json::CJSONEntry callback_param = argv.getItem(0+1);
        if (callback_param.isString()) {
            callbackParam = [((NSString*)[CJSConverter convertFromJS:&callback_param]) retain];
        }
    }
    

    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [RhoConnectClient_getPollInterval_caller getPollInterval_in_thread:[RhoConnectClient_getPollInterval_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [RhoConnectClient_getPollInterval_caller getPollInterval:[RhoConnectClient_getPollInterval_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = "";
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    return resValue;
}


rho::String js_s_RhoConnectClient_getPollInterval(rho::json::CJSONArray& argv, const rho::String& strObjID) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return js_RhoConnectClient_getPollInterval_Obj(argv, singleton);

}







@interface RhoConnectClient_setPollInterval_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(RhoConnectClient_setPollInterval_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation RhoConnectClient_setPollInterval_caller_params

@synthesize params,item,methodResult;

+(RhoConnectClient_setPollInterval_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    RhoConnectClient_setPollInterval_caller_params* par = [[RhoConnectClient_setPollInterval_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface RhoConnectClient_setPollInterval_caller : NSObject {

}
+(RhoConnectClient_setPollInterval_caller*) getSharedInstance;
+(void) setPollInterval:(RhoConnectClient_setPollInterval_caller_params*)caller_params;
+(void) setPollInterval_in_thread:(RhoConnectClient_setPollInterval_caller_params*)caller_params;
+(void) setPollInterval_in_UI_thread:(RhoConnectClient_setPollInterval_caller_params*)caller_params;

@end

static RhoConnectClient_setPollInterval_caller* our_RhoConnectClient_setPollInterval_caller = nil;

@implementation RhoConnectClient_setPollInterval_caller

+(RhoConnectClient_setPollInterval_caller*) getSharedInstance {
    if (our_RhoConnectClient_setPollInterval_caller == nil) {
        our_RhoConnectClient_setPollInterval_caller = [[RhoConnectClient_setPollInterval_caller alloc] init];
    }
    return our_RhoConnectClient_setPollInterval_caller;
}

-(void) command_setPollInterval:(RhoConnectClient_setPollInterval_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem setPollInterval:(int)[((NSNumber*)[params objectAtIndex:0]) intValue] ];
}


+(void) setPollInterval:(RhoConnectClient_setPollInterval_caller_params*)caller_params {
    [[RhoConnectClient_setPollInterval_caller getSharedInstance] command_setPollInterval:caller_params];
}

+(void) setPollInterval_in_thread:(RhoConnectClient_setPollInterval_caller_params*)caller_params {
    [[RhoConnectClient_setPollInterval_caller getSharedInstance] performSelectorInBackground:@selector(command_setPollInterval:) withObject:caller_params];
}

+(void) setPollInterval_in_UI_thread:(RhoConnectClient_setPollInterval_caller_params*)caller_params {
    [[RhoConnectClient_setPollInterval_caller getSharedInstance] performSelectorOnMainThread:@selector(command_setPollInterval:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_RhoConnectClient_setPollInterval_Obj(rho::json::CJSONArray& argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[1+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    int argc = argv.getSize();
    
    static RHO_API_PARAM rho_api_params[] = { {RHO_API_INTEGER, 0, "value", 0, 0 } };

    
    BOOL is_factory_param[] = { NO, NO };

    int i;

    // init
    for (i = 0; i < (1); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    // enumerate params
    for (int i = 0; i < (1); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(1)];
    for (i = 0 ; i < (1); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (1+1)) {
        rho::json::CJSONEntry callback = argv.getItem(1);
        if (callback.isString()) {
            rho::json::CJSONEntry entry = argv.getItem(i);
            callbackURL = [((NSString*)[CJSConverter convertFromJS:&callback]) retain];
        }
    }
    // check callback param
    if (argc >= (1+2)) {
        rho::json::CJSONEntry callback_param = argv.getItem(1+1);
        if (callback_param.isString()) {
            callbackParam = [((NSString*)[CJSConverter convertFromJS:&callback_param]) retain];
        }
    }
    

    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [RhoConnectClient_setPollInterval_caller setPollInterval_in_thread:[RhoConnectClient_setPollInterval_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [RhoConnectClient_setPollInterval_caller setPollInterval:[RhoConnectClient_setPollInterval_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = "";
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    return resValue;
}


rho::String js_s_RhoConnectClient_setPollInterval(rho::json::CJSONArray& argv, const rho::String& strObjID) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return js_RhoConnectClient_setPollInterval_Obj(argv, singleton);

}







@interface RhoConnectClient_getSyncServer_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(RhoConnectClient_getSyncServer_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation RhoConnectClient_getSyncServer_caller_params

@synthesize params,item,methodResult;

+(RhoConnectClient_getSyncServer_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    RhoConnectClient_getSyncServer_caller_params* par = [[RhoConnectClient_getSyncServer_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface RhoConnectClient_getSyncServer_caller : NSObject {

}
+(RhoConnectClient_getSyncServer_caller*) getSharedInstance;
+(void) getSyncServer:(RhoConnectClient_getSyncServer_caller_params*)caller_params;
+(void) getSyncServer_in_thread:(RhoConnectClient_getSyncServer_caller_params*)caller_params;
+(void) getSyncServer_in_UI_thread:(RhoConnectClient_getSyncServer_caller_params*)caller_params;

@end

static RhoConnectClient_getSyncServer_caller* our_RhoConnectClient_getSyncServer_caller = nil;

@implementation RhoConnectClient_getSyncServer_caller

+(RhoConnectClient_getSyncServer_caller*) getSharedInstance {
    if (our_RhoConnectClient_getSyncServer_caller == nil) {
        our_RhoConnectClient_getSyncServer_caller = [[RhoConnectClient_getSyncServer_caller alloc] init];
    }
    return our_RhoConnectClient_getSyncServer_caller;
}

-(void) command_getSyncServer:(RhoConnectClient_getSyncServer_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem getSyncServer:methodResult ];
}


+(void) getSyncServer:(RhoConnectClient_getSyncServer_caller_params*)caller_params {
    [[RhoConnectClient_getSyncServer_caller getSharedInstance] command_getSyncServer:caller_params];
}

+(void) getSyncServer_in_thread:(RhoConnectClient_getSyncServer_caller_params*)caller_params {
    [[RhoConnectClient_getSyncServer_caller getSharedInstance] performSelectorInBackground:@selector(command_getSyncServer:) withObject:caller_params];
}

+(void) getSyncServer_in_UI_thread:(RhoConnectClient_getSyncServer_caller_params*)caller_params {
    [[RhoConnectClient_getSyncServer_caller getSharedInstance] performSelectorOnMainThread:@selector(command_getSyncServer:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_RhoConnectClient_getSyncServer_Obj(rho::json::CJSONArray& argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[0+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    int argc = argv.getSize();
    
    static RHO_API_PARAM rho_api_params[] = {  };

    
    BOOL is_factory_param[] = { NO };

    int i;

    // init
    for (i = 0; i < (0); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    // enumerate params
    for (int i = 0; i < (0); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(0)];
    for (i = 0 ; i < (0); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (0+1)) {
        rho::json::CJSONEntry callback = argv.getItem(0);
        if (callback.isString()) {
            rho::json::CJSONEntry entry = argv.getItem(i);
            callbackURL = [((NSString*)[CJSConverter convertFromJS:&callback]) retain];
        }
    }
    // check callback param
    if (argc >= (0+2)) {
        rho::json::CJSONEntry callback_param = argv.getItem(0+1);
        if (callback_param.isString()) {
            callbackParam = [((NSString*)[CJSConverter convertFromJS:&callback_param]) retain];
        }
    }
    

    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [RhoConnectClient_getSyncServer_caller getSyncServer_in_thread:[RhoConnectClient_getSyncServer_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [RhoConnectClient_getSyncServer_caller getSyncServer:[RhoConnectClient_getSyncServer_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = "";
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    return resValue;
}


rho::String js_s_RhoConnectClient_getSyncServer(rho::json::CJSONArray& argv, const rho::String& strObjID) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return js_RhoConnectClient_getSyncServer_Obj(argv, singleton);

}







@interface RhoConnectClient_setSyncServer_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(RhoConnectClient_setSyncServer_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation RhoConnectClient_setSyncServer_caller_params

@synthesize params,item,methodResult;

+(RhoConnectClient_setSyncServer_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    RhoConnectClient_setSyncServer_caller_params* par = [[RhoConnectClient_setSyncServer_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface RhoConnectClient_setSyncServer_caller : NSObject {

}
+(RhoConnectClient_setSyncServer_caller*) getSharedInstance;
+(void) setSyncServer:(RhoConnectClient_setSyncServer_caller_params*)caller_params;
+(void) setSyncServer_in_thread:(RhoConnectClient_setSyncServer_caller_params*)caller_params;
+(void) setSyncServer_in_UI_thread:(RhoConnectClient_setSyncServer_caller_params*)caller_params;

@end

static RhoConnectClient_setSyncServer_caller* our_RhoConnectClient_setSyncServer_caller = nil;

@implementation RhoConnectClient_setSyncServer_caller

+(RhoConnectClient_setSyncServer_caller*) getSharedInstance {
    if (our_RhoConnectClient_setSyncServer_caller == nil) {
        our_RhoConnectClient_setSyncServer_caller = [[RhoConnectClient_setSyncServer_caller alloc] init];
    }
    return our_RhoConnectClient_setSyncServer_caller;
}

-(void) command_setSyncServer:(RhoConnectClient_setSyncServer_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem setSyncServer:(NSString*)[params objectAtIndex:0] ];
}


+(void) setSyncServer:(RhoConnectClient_setSyncServer_caller_params*)caller_params {
    [[RhoConnectClient_setSyncServer_caller getSharedInstance] command_setSyncServer:caller_params];
}

+(void) setSyncServer_in_thread:(RhoConnectClient_setSyncServer_caller_params*)caller_params {
    [[RhoConnectClient_setSyncServer_caller getSharedInstance] performSelectorInBackground:@selector(command_setSyncServer:) withObject:caller_params];
}

+(void) setSyncServer_in_UI_thread:(RhoConnectClient_setSyncServer_caller_params*)caller_params {
    [[RhoConnectClient_setSyncServer_caller getSharedInstance] performSelectorOnMainThread:@selector(command_setSyncServer:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_RhoConnectClient_setSyncServer_Obj(rho::json::CJSONArray& argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[1+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    int argc = argv.getSize();
    
    static RHO_API_PARAM rho_api_params[] = { {RHO_API_STRING, 0, "value", 0, 0 } };

    
    BOOL is_factory_param[] = { NO, NO };

    int i;

    // init
    for (i = 0; i < (1); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    // enumerate params
    for (int i = 0; i < (1); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(1)];
    for (i = 0 ; i < (1); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (1+1)) {
        rho::json::CJSONEntry callback = argv.getItem(1);
        if (callback.isString()) {
            rho::json::CJSONEntry entry = argv.getItem(i);
            callbackURL = [((NSString*)[CJSConverter convertFromJS:&callback]) retain];
        }
    }
    // check callback param
    if (argc >= (1+2)) {
        rho::json::CJSONEntry callback_param = argv.getItem(1+1);
        if (callback_param.isString()) {
            callbackParam = [((NSString*)[CJSConverter convertFromJS:&callback_param]) retain];
        }
    }
    

    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [RhoConnectClient_setSyncServer_caller setSyncServer_in_thread:[RhoConnectClient_setSyncServer_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [RhoConnectClient_setSyncServer_caller setSyncServer:[RhoConnectClient_setSyncServer_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = "";
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    return resValue;
}


rho::String js_s_RhoConnectClient_setSyncServer(rho::json::CJSONArray& argv, const rho::String& strObjID) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return js_RhoConnectClient_setSyncServer_Obj(argv, singleton);

}







@interface RhoConnectClient_getPageSize_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(RhoConnectClient_getPageSize_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation RhoConnectClient_getPageSize_caller_params

@synthesize params,item,methodResult;

+(RhoConnectClient_getPageSize_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    RhoConnectClient_getPageSize_caller_params* par = [[RhoConnectClient_getPageSize_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface RhoConnectClient_getPageSize_caller : NSObject {

}
+(RhoConnectClient_getPageSize_caller*) getSharedInstance;
+(void) getPageSize:(RhoConnectClient_getPageSize_caller_params*)caller_params;
+(void) getPageSize_in_thread:(RhoConnectClient_getPageSize_caller_params*)caller_params;
+(void) getPageSize_in_UI_thread:(RhoConnectClient_getPageSize_caller_params*)caller_params;

@end

static RhoConnectClient_getPageSize_caller* our_RhoConnectClient_getPageSize_caller = nil;

@implementation RhoConnectClient_getPageSize_caller

+(RhoConnectClient_getPageSize_caller*) getSharedInstance {
    if (our_RhoConnectClient_getPageSize_caller == nil) {
        our_RhoConnectClient_getPageSize_caller = [[RhoConnectClient_getPageSize_caller alloc] init];
    }
    return our_RhoConnectClient_getPageSize_caller;
}

-(void) command_getPageSize:(RhoConnectClient_getPageSize_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem getPageSize:methodResult ];
}


+(void) getPageSize:(RhoConnectClient_getPageSize_caller_params*)caller_params {
    [[RhoConnectClient_getPageSize_caller getSharedInstance] command_getPageSize:caller_params];
}

+(void) getPageSize_in_thread:(RhoConnectClient_getPageSize_caller_params*)caller_params {
    [[RhoConnectClient_getPageSize_caller getSharedInstance] performSelectorInBackground:@selector(command_getPageSize:) withObject:caller_params];
}

+(void) getPageSize_in_UI_thread:(RhoConnectClient_getPageSize_caller_params*)caller_params {
    [[RhoConnectClient_getPageSize_caller getSharedInstance] performSelectorOnMainThread:@selector(command_getPageSize:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_RhoConnectClient_getPageSize_Obj(rho::json::CJSONArray& argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[0+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    int argc = argv.getSize();
    
    static RHO_API_PARAM rho_api_params[] = {  };

    
    BOOL is_factory_param[] = { NO };

    int i;

    // init
    for (i = 0; i < (0); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    // enumerate params
    for (int i = 0; i < (0); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(0)];
    for (i = 0 ; i < (0); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (0+1)) {
        rho::json::CJSONEntry callback = argv.getItem(0);
        if (callback.isString()) {
            rho::json::CJSONEntry entry = argv.getItem(i);
            callbackURL = [((NSString*)[CJSConverter convertFromJS:&callback]) retain];
        }
    }
    // check callback param
    if (argc >= (0+2)) {
        rho::json::CJSONEntry callback_param = argv.getItem(0+1);
        if (callback_param.isString()) {
            callbackParam = [((NSString*)[CJSConverter convertFromJS:&callback_param]) retain];
        }
    }
    

    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [RhoConnectClient_getPageSize_caller getPageSize_in_thread:[RhoConnectClient_getPageSize_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [RhoConnectClient_getPageSize_caller getPageSize:[RhoConnectClient_getPageSize_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = "";
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    return resValue;
}


rho::String js_s_RhoConnectClient_getPageSize(rho::json::CJSONArray& argv, const rho::String& strObjID) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return js_RhoConnectClient_getPageSize_Obj(argv, singleton);

}







@interface RhoConnectClient_setPageSize_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(RhoConnectClient_setPageSize_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation RhoConnectClient_setPageSize_caller_params

@synthesize params,item,methodResult;

+(RhoConnectClient_setPageSize_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    RhoConnectClient_setPageSize_caller_params* par = [[RhoConnectClient_setPageSize_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface RhoConnectClient_setPageSize_caller : NSObject {

}
+(RhoConnectClient_setPageSize_caller*) getSharedInstance;
+(void) setPageSize:(RhoConnectClient_setPageSize_caller_params*)caller_params;
+(void) setPageSize_in_thread:(RhoConnectClient_setPageSize_caller_params*)caller_params;
+(void) setPageSize_in_UI_thread:(RhoConnectClient_setPageSize_caller_params*)caller_params;

@end

static RhoConnectClient_setPageSize_caller* our_RhoConnectClient_setPageSize_caller = nil;

@implementation RhoConnectClient_setPageSize_caller

+(RhoConnectClient_setPageSize_caller*) getSharedInstance {
    if (our_RhoConnectClient_setPageSize_caller == nil) {
        our_RhoConnectClient_setPageSize_caller = [[RhoConnectClient_setPageSize_caller alloc] init];
    }
    return our_RhoConnectClient_setPageSize_caller;
}

-(void) command_setPageSize:(RhoConnectClient_setPageSize_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem setPageSize:(int)[((NSNumber*)[params objectAtIndex:0]) intValue] ];
}


+(void) setPageSize:(RhoConnectClient_setPageSize_caller_params*)caller_params {
    [[RhoConnectClient_setPageSize_caller getSharedInstance] command_setPageSize:caller_params];
}

+(void) setPageSize_in_thread:(RhoConnectClient_setPageSize_caller_params*)caller_params {
    [[RhoConnectClient_setPageSize_caller getSharedInstance] performSelectorInBackground:@selector(command_setPageSize:) withObject:caller_params];
}

+(void) setPageSize_in_UI_thread:(RhoConnectClient_setPageSize_caller_params*)caller_params {
    [[RhoConnectClient_setPageSize_caller getSharedInstance] performSelectorOnMainThread:@selector(command_setPageSize:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_RhoConnectClient_setPageSize_Obj(rho::json::CJSONArray& argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[1+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    int argc = argv.getSize();
    
    static RHO_API_PARAM rho_api_params[] = { {RHO_API_INTEGER, 0, "value", 0, 0 } };

    
    BOOL is_factory_param[] = { NO, NO };

    int i;

    // init
    for (i = 0; i < (1); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    // enumerate params
    for (int i = 0; i < (1); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(1)];
    for (i = 0 ; i < (1); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (1+1)) {
        rho::json::CJSONEntry callback = argv.getItem(1);
        if (callback.isString()) {
            rho::json::CJSONEntry entry = argv.getItem(i);
            callbackURL = [((NSString*)[CJSConverter convertFromJS:&callback]) retain];
        }
    }
    // check callback param
    if (argc >= (1+2)) {
        rho::json::CJSONEntry callback_param = argv.getItem(1+1);
        if (callback_param.isString()) {
            callbackParam = [((NSString*)[CJSConverter convertFromJS:&callback_param]) retain];
        }
    }
    

    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [RhoConnectClient_setPageSize_caller setPageSize_in_thread:[RhoConnectClient_setPageSize_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [RhoConnectClient_setPageSize_caller setPageSize:[RhoConnectClient_setPageSize_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = "";
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    return resValue;
}


rho::String js_s_RhoConnectClient_setPageSize(rho::json::CJSONArray& argv, const rho::String& strObjID) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return js_RhoConnectClient_setPageSize_Obj(argv, singleton);

}







@interface RhoConnectClient_getThreadedMode_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(RhoConnectClient_getThreadedMode_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation RhoConnectClient_getThreadedMode_caller_params

@synthesize params,item,methodResult;

+(RhoConnectClient_getThreadedMode_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    RhoConnectClient_getThreadedMode_caller_params* par = [[RhoConnectClient_getThreadedMode_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface RhoConnectClient_getThreadedMode_caller : NSObject {

}
+(RhoConnectClient_getThreadedMode_caller*) getSharedInstance;
+(void) getThreadedMode:(RhoConnectClient_getThreadedMode_caller_params*)caller_params;
+(void) getThreadedMode_in_thread:(RhoConnectClient_getThreadedMode_caller_params*)caller_params;
+(void) getThreadedMode_in_UI_thread:(RhoConnectClient_getThreadedMode_caller_params*)caller_params;

@end

static RhoConnectClient_getThreadedMode_caller* our_RhoConnectClient_getThreadedMode_caller = nil;

@implementation RhoConnectClient_getThreadedMode_caller

+(RhoConnectClient_getThreadedMode_caller*) getSharedInstance {
    if (our_RhoConnectClient_getThreadedMode_caller == nil) {
        our_RhoConnectClient_getThreadedMode_caller = [[RhoConnectClient_getThreadedMode_caller alloc] init];
    }
    return our_RhoConnectClient_getThreadedMode_caller;
}

-(void) command_getThreadedMode:(RhoConnectClient_getThreadedMode_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem getThreadedMode:methodResult ];
}


+(void) getThreadedMode:(RhoConnectClient_getThreadedMode_caller_params*)caller_params {
    [[RhoConnectClient_getThreadedMode_caller getSharedInstance] command_getThreadedMode:caller_params];
}

+(void) getThreadedMode_in_thread:(RhoConnectClient_getThreadedMode_caller_params*)caller_params {
    [[RhoConnectClient_getThreadedMode_caller getSharedInstance] performSelectorInBackground:@selector(command_getThreadedMode:) withObject:caller_params];
}

+(void) getThreadedMode_in_UI_thread:(RhoConnectClient_getThreadedMode_caller_params*)caller_params {
    [[RhoConnectClient_getThreadedMode_caller getSharedInstance] performSelectorOnMainThread:@selector(command_getThreadedMode:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_RhoConnectClient_getThreadedMode_Obj(rho::json::CJSONArray& argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[0+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    int argc = argv.getSize();
    
    static RHO_API_PARAM rho_api_params[] = {  };

    
    BOOL is_factory_param[] = { NO };

    int i;

    // init
    for (i = 0; i < (0); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    // enumerate params
    for (int i = 0; i < (0); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(0)];
    for (i = 0 ; i < (0); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (0+1)) {
        rho::json::CJSONEntry callback = argv.getItem(0);
        if (callback.isString()) {
            rho::json::CJSONEntry entry = argv.getItem(i);
            callbackURL = [((NSString*)[CJSConverter convertFromJS:&callback]) retain];
        }
    }
    // check callback param
    if (argc >= (0+2)) {
        rho::json::CJSONEntry callback_param = argv.getItem(0+1);
        if (callback_param.isString()) {
            callbackParam = [((NSString*)[CJSConverter convertFromJS:&callback_param]) retain];
        }
    }
    

    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [RhoConnectClient_getThreadedMode_caller getThreadedMode_in_thread:[RhoConnectClient_getThreadedMode_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [RhoConnectClient_getThreadedMode_caller getThreadedMode:[RhoConnectClient_getThreadedMode_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = "";
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    return resValue;
}


rho::String js_s_RhoConnectClient_getThreadedMode(rho::json::CJSONArray& argv, const rho::String& strObjID) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return js_RhoConnectClient_getThreadedMode_Obj(argv, singleton);

}







@interface RhoConnectClient_setThreadedMode_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(RhoConnectClient_setThreadedMode_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation RhoConnectClient_setThreadedMode_caller_params

@synthesize params,item,methodResult;

+(RhoConnectClient_setThreadedMode_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    RhoConnectClient_setThreadedMode_caller_params* par = [[RhoConnectClient_setThreadedMode_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface RhoConnectClient_setThreadedMode_caller : NSObject {

}
+(RhoConnectClient_setThreadedMode_caller*) getSharedInstance;
+(void) setThreadedMode:(RhoConnectClient_setThreadedMode_caller_params*)caller_params;
+(void) setThreadedMode_in_thread:(RhoConnectClient_setThreadedMode_caller_params*)caller_params;
+(void) setThreadedMode_in_UI_thread:(RhoConnectClient_setThreadedMode_caller_params*)caller_params;

@end

static RhoConnectClient_setThreadedMode_caller* our_RhoConnectClient_setThreadedMode_caller = nil;

@implementation RhoConnectClient_setThreadedMode_caller

+(RhoConnectClient_setThreadedMode_caller*) getSharedInstance {
    if (our_RhoConnectClient_setThreadedMode_caller == nil) {
        our_RhoConnectClient_setThreadedMode_caller = [[RhoConnectClient_setThreadedMode_caller alloc] init];
    }
    return our_RhoConnectClient_setThreadedMode_caller;
}

-(void) command_setThreadedMode:(RhoConnectClient_setThreadedMode_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem setThreadedMode:(BOOL)[((NSNumber*)[params objectAtIndex:0]) boolValue] ];
}


+(void) setThreadedMode:(RhoConnectClient_setThreadedMode_caller_params*)caller_params {
    [[RhoConnectClient_setThreadedMode_caller getSharedInstance] command_setThreadedMode:caller_params];
}

+(void) setThreadedMode_in_thread:(RhoConnectClient_setThreadedMode_caller_params*)caller_params {
    [[RhoConnectClient_setThreadedMode_caller getSharedInstance] performSelectorInBackground:@selector(command_setThreadedMode:) withObject:caller_params];
}

+(void) setThreadedMode_in_UI_thread:(RhoConnectClient_setThreadedMode_caller_params*)caller_params {
    [[RhoConnectClient_setThreadedMode_caller getSharedInstance] performSelectorOnMainThread:@selector(command_setThreadedMode:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_RhoConnectClient_setThreadedMode_Obj(rho::json::CJSONArray& argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[1+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    int argc = argv.getSize();
    
    static RHO_API_PARAM rho_api_params[] = { {RHO_API_BOOLEAN, 0, "value", 0, 0 } };

    
    BOOL is_factory_param[] = { NO, NO };

    int i;

    // init
    for (i = 0; i < (1); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    // enumerate params
    for (int i = 0; i < (1); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(1)];
    for (i = 0 ; i < (1); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (1+1)) {
        rho::json::CJSONEntry callback = argv.getItem(1);
        if (callback.isString()) {
            rho::json::CJSONEntry entry = argv.getItem(i);
            callbackURL = [((NSString*)[CJSConverter convertFromJS:&callback]) retain];
        }
    }
    // check callback param
    if (argc >= (1+2)) {
        rho::json::CJSONEntry callback_param = argv.getItem(1+1);
        if (callback_param.isString()) {
            callbackParam = [((NSString*)[CJSConverter convertFromJS:&callback_param]) retain];
        }
    }
    

    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [RhoConnectClient_setThreadedMode_caller setThreadedMode_in_thread:[RhoConnectClient_setThreadedMode_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [RhoConnectClient_setThreadedMode_caller setThreadedMode:[RhoConnectClient_setThreadedMode_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = "";
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    return resValue;
}


rho::String js_s_RhoConnectClient_setThreadedMode(rho::json::CJSONArray& argv, const rho::String& strObjID) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return js_RhoConnectClient_setThreadedMode_Obj(argv, singleton);

}







@interface RhoConnectClient_getShowStatusPopup_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(RhoConnectClient_getShowStatusPopup_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation RhoConnectClient_getShowStatusPopup_caller_params

@synthesize params,item,methodResult;

+(RhoConnectClient_getShowStatusPopup_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    RhoConnectClient_getShowStatusPopup_caller_params* par = [[RhoConnectClient_getShowStatusPopup_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface RhoConnectClient_getShowStatusPopup_caller : NSObject {

}
+(RhoConnectClient_getShowStatusPopup_caller*) getSharedInstance;
+(void) getShowStatusPopup:(RhoConnectClient_getShowStatusPopup_caller_params*)caller_params;
+(void) getShowStatusPopup_in_thread:(RhoConnectClient_getShowStatusPopup_caller_params*)caller_params;
+(void) getShowStatusPopup_in_UI_thread:(RhoConnectClient_getShowStatusPopup_caller_params*)caller_params;

@end

static RhoConnectClient_getShowStatusPopup_caller* our_RhoConnectClient_getShowStatusPopup_caller = nil;

@implementation RhoConnectClient_getShowStatusPopup_caller

+(RhoConnectClient_getShowStatusPopup_caller*) getSharedInstance {
    if (our_RhoConnectClient_getShowStatusPopup_caller == nil) {
        our_RhoConnectClient_getShowStatusPopup_caller = [[RhoConnectClient_getShowStatusPopup_caller alloc] init];
    }
    return our_RhoConnectClient_getShowStatusPopup_caller;
}

-(void) command_getShowStatusPopup:(RhoConnectClient_getShowStatusPopup_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem getShowStatusPopup:methodResult ];
}


+(void) getShowStatusPopup:(RhoConnectClient_getShowStatusPopup_caller_params*)caller_params {
    [[RhoConnectClient_getShowStatusPopup_caller getSharedInstance] command_getShowStatusPopup:caller_params];
}

+(void) getShowStatusPopup_in_thread:(RhoConnectClient_getShowStatusPopup_caller_params*)caller_params {
    [[RhoConnectClient_getShowStatusPopup_caller getSharedInstance] performSelectorInBackground:@selector(command_getShowStatusPopup:) withObject:caller_params];
}

+(void) getShowStatusPopup_in_UI_thread:(RhoConnectClient_getShowStatusPopup_caller_params*)caller_params {
    [[RhoConnectClient_getShowStatusPopup_caller getSharedInstance] performSelectorOnMainThread:@selector(command_getShowStatusPopup:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_RhoConnectClient_getShowStatusPopup_Obj(rho::json::CJSONArray& argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[0+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    int argc = argv.getSize();
    
    static RHO_API_PARAM rho_api_params[] = {  };

    
    BOOL is_factory_param[] = { NO };

    int i;

    // init
    for (i = 0; i < (0); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    // enumerate params
    for (int i = 0; i < (0); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(0)];
    for (i = 0 ; i < (0); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (0+1)) {
        rho::json::CJSONEntry callback = argv.getItem(0);
        if (callback.isString()) {
            rho::json::CJSONEntry entry = argv.getItem(i);
            callbackURL = [((NSString*)[CJSConverter convertFromJS:&callback]) retain];
        }
    }
    // check callback param
    if (argc >= (0+2)) {
        rho::json::CJSONEntry callback_param = argv.getItem(0+1);
        if (callback_param.isString()) {
            callbackParam = [((NSString*)[CJSConverter convertFromJS:&callback_param]) retain];
        }
    }
    

    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [RhoConnectClient_getShowStatusPopup_caller getShowStatusPopup_in_thread:[RhoConnectClient_getShowStatusPopup_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [RhoConnectClient_getShowStatusPopup_caller getShowStatusPopup:[RhoConnectClient_getShowStatusPopup_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = "";
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    return resValue;
}


rho::String js_s_RhoConnectClient_getShowStatusPopup(rho::json::CJSONArray& argv, const rho::String& strObjID) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return js_RhoConnectClient_getShowStatusPopup_Obj(argv, singleton);

}







@interface RhoConnectClient_setShowStatusPopup_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(RhoConnectClient_setShowStatusPopup_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation RhoConnectClient_setShowStatusPopup_caller_params

@synthesize params,item,methodResult;

+(RhoConnectClient_setShowStatusPopup_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    RhoConnectClient_setShowStatusPopup_caller_params* par = [[RhoConnectClient_setShowStatusPopup_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface RhoConnectClient_setShowStatusPopup_caller : NSObject {

}
+(RhoConnectClient_setShowStatusPopup_caller*) getSharedInstance;
+(void) setShowStatusPopup:(RhoConnectClient_setShowStatusPopup_caller_params*)caller_params;
+(void) setShowStatusPopup_in_thread:(RhoConnectClient_setShowStatusPopup_caller_params*)caller_params;
+(void) setShowStatusPopup_in_UI_thread:(RhoConnectClient_setShowStatusPopup_caller_params*)caller_params;

@end

static RhoConnectClient_setShowStatusPopup_caller* our_RhoConnectClient_setShowStatusPopup_caller = nil;

@implementation RhoConnectClient_setShowStatusPopup_caller

+(RhoConnectClient_setShowStatusPopup_caller*) getSharedInstance {
    if (our_RhoConnectClient_setShowStatusPopup_caller == nil) {
        our_RhoConnectClient_setShowStatusPopup_caller = [[RhoConnectClient_setShowStatusPopup_caller alloc] init];
    }
    return our_RhoConnectClient_setShowStatusPopup_caller;
}

-(void) command_setShowStatusPopup:(RhoConnectClient_setShowStatusPopup_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem setShowStatusPopup:(BOOL)[((NSNumber*)[params objectAtIndex:0]) boolValue] ];
}


+(void) setShowStatusPopup:(RhoConnectClient_setShowStatusPopup_caller_params*)caller_params {
    [[RhoConnectClient_setShowStatusPopup_caller getSharedInstance] command_setShowStatusPopup:caller_params];
}

+(void) setShowStatusPopup_in_thread:(RhoConnectClient_setShowStatusPopup_caller_params*)caller_params {
    [[RhoConnectClient_setShowStatusPopup_caller getSharedInstance] performSelectorInBackground:@selector(command_setShowStatusPopup:) withObject:caller_params];
}

+(void) setShowStatusPopup_in_UI_thread:(RhoConnectClient_setShowStatusPopup_caller_params*)caller_params {
    [[RhoConnectClient_setShowStatusPopup_caller getSharedInstance] performSelectorOnMainThread:@selector(command_setShowStatusPopup:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_RhoConnectClient_setShowStatusPopup_Obj(rho::json::CJSONArray& argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[1+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    int argc = argv.getSize();
    
    static RHO_API_PARAM rho_api_params[] = { {RHO_API_BOOLEAN, 0, "value", 0, 0 } };

    
    BOOL is_factory_param[] = { NO, NO };

    int i;

    // init
    for (i = 0; i < (1); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    // enumerate params
    for (int i = 0; i < (1); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(1)];
    for (i = 0 ; i < (1); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (1+1)) {
        rho::json::CJSONEntry callback = argv.getItem(1);
        if (callback.isString()) {
            rho::json::CJSONEntry entry = argv.getItem(i);
            callbackURL = [((NSString*)[CJSConverter convertFromJS:&callback]) retain];
        }
    }
    // check callback param
    if (argc >= (1+2)) {
        rho::json::CJSONEntry callback_param = argv.getItem(1+1);
        if (callback_param.isString()) {
            callbackParam = [((NSString*)[CJSConverter convertFromJS:&callback_param]) retain];
        }
    }
    

    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [RhoConnectClient_setShowStatusPopup_caller setShowStatusPopup_in_thread:[RhoConnectClient_setShowStatusPopup_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [RhoConnectClient_setShowStatusPopup_caller setShowStatusPopup:[RhoConnectClient_setShowStatusPopup_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = "";
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    return resValue;
}


rho::String js_s_RhoConnectClient_setShowStatusPopup(rho::json::CJSONArray& argv, const rho::String& strObjID) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return js_RhoConnectClient_setShowStatusPopup_Obj(argv, singleton);

}







@interface RhoConnectClient_getSslVerifyPeer_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(RhoConnectClient_getSslVerifyPeer_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation RhoConnectClient_getSslVerifyPeer_caller_params

@synthesize params,item,methodResult;

+(RhoConnectClient_getSslVerifyPeer_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    RhoConnectClient_getSslVerifyPeer_caller_params* par = [[RhoConnectClient_getSslVerifyPeer_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface RhoConnectClient_getSslVerifyPeer_caller : NSObject {

}
+(RhoConnectClient_getSslVerifyPeer_caller*) getSharedInstance;
+(void) getSslVerifyPeer:(RhoConnectClient_getSslVerifyPeer_caller_params*)caller_params;
+(void) getSslVerifyPeer_in_thread:(RhoConnectClient_getSslVerifyPeer_caller_params*)caller_params;
+(void) getSslVerifyPeer_in_UI_thread:(RhoConnectClient_getSslVerifyPeer_caller_params*)caller_params;

@end

static RhoConnectClient_getSslVerifyPeer_caller* our_RhoConnectClient_getSslVerifyPeer_caller = nil;

@implementation RhoConnectClient_getSslVerifyPeer_caller

+(RhoConnectClient_getSslVerifyPeer_caller*) getSharedInstance {
    if (our_RhoConnectClient_getSslVerifyPeer_caller == nil) {
        our_RhoConnectClient_getSslVerifyPeer_caller = [[RhoConnectClient_getSslVerifyPeer_caller alloc] init];
    }
    return our_RhoConnectClient_getSslVerifyPeer_caller;
}

-(void) command_getSslVerifyPeer:(RhoConnectClient_getSslVerifyPeer_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem getSslVerifyPeer:methodResult ];
}


+(void) getSslVerifyPeer:(RhoConnectClient_getSslVerifyPeer_caller_params*)caller_params {
    [[RhoConnectClient_getSslVerifyPeer_caller getSharedInstance] command_getSslVerifyPeer:caller_params];
}

+(void) getSslVerifyPeer_in_thread:(RhoConnectClient_getSslVerifyPeer_caller_params*)caller_params {
    [[RhoConnectClient_getSslVerifyPeer_caller getSharedInstance] performSelectorInBackground:@selector(command_getSslVerifyPeer:) withObject:caller_params];
}

+(void) getSslVerifyPeer_in_UI_thread:(RhoConnectClient_getSslVerifyPeer_caller_params*)caller_params {
    [[RhoConnectClient_getSslVerifyPeer_caller getSharedInstance] performSelectorOnMainThread:@selector(command_getSslVerifyPeer:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_RhoConnectClient_getSslVerifyPeer_Obj(rho::json::CJSONArray& argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[0+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    int argc = argv.getSize();
    
    static RHO_API_PARAM rho_api_params[] = {  };

    
    BOOL is_factory_param[] = { NO };

    int i;

    // init
    for (i = 0; i < (0); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    // enumerate params
    for (int i = 0; i < (0); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(0)];
    for (i = 0 ; i < (0); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (0+1)) {
        rho::json::CJSONEntry callback = argv.getItem(0);
        if (callback.isString()) {
            rho::json::CJSONEntry entry = argv.getItem(i);
            callbackURL = [((NSString*)[CJSConverter convertFromJS:&callback]) retain];
        }
    }
    // check callback param
    if (argc >= (0+2)) {
        rho::json::CJSONEntry callback_param = argv.getItem(0+1);
        if (callback_param.isString()) {
            callbackParam = [((NSString*)[CJSConverter convertFromJS:&callback_param]) retain];
        }
    }
    

    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [RhoConnectClient_getSslVerifyPeer_caller getSslVerifyPeer_in_thread:[RhoConnectClient_getSslVerifyPeer_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [RhoConnectClient_getSslVerifyPeer_caller getSslVerifyPeer:[RhoConnectClient_getSslVerifyPeer_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = "";
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    return resValue;
}


rho::String js_s_RhoConnectClient_getSslVerifyPeer(rho::json::CJSONArray& argv, const rho::String& strObjID) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return js_RhoConnectClient_getSslVerifyPeer_Obj(argv, singleton);

}







@interface RhoConnectClient_setSslVerifyPeer_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(RhoConnectClient_setSslVerifyPeer_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation RhoConnectClient_setSslVerifyPeer_caller_params

@synthesize params,item,methodResult;

+(RhoConnectClient_setSslVerifyPeer_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    RhoConnectClient_setSslVerifyPeer_caller_params* par = [[RhoConnectClient_setSslVerifyPeer_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface RhoConnectClient_setSslVerifyPeer_caller : NSObject {

}
+(RhoConnectClient_setSslVerifyPeer_caller*) getSharedInstance;
+(void) setSslVerifyPeer:(RhoConnectClient_setSslVerifyPeer_caller_params*)caller_params;
+(void) setSslVerifyPeer_in_thread:(RhoConnectClient_setSslVerifyPeer_caller_params*)caller_params;
+(void) setSslVerifyPeer_in_UI_thread:(RhoConnectClient_setSslVerifyPeer_caller_params*)caller_params;

@end

static RhoConnectClient_setSslVerifyPeer_caller* our_RhoConnectClient_setSslVerifyPeer_caller = nil;

@implementation RhoConnectClient_setSslVerifyPeer_caller

+(RhoConnectClient_setSslVerifyPeer_caller*) getSharedInstance {
    if (our_RhoConnectClient_setSslVerifyPeer_caller == nil) {
        our_RhoConnectClient_setSslVerifyPeer_caller = [[RhoConnectClient_setSslVerifyPeer_caller alloc] init];
    }
    return our_RhoConnectClient_setSslVerifyPeer_caller;
}

-(void) command_setSslVerifyPeer:(RhoConnectClient_setSslVerifyPeer_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem setSslVerifyPeer:(BOOL)[((NSNumber*)[params objectAtIndex:0]) boolValue] ];
}


+(void) setSslVerifyPeer:(RhoConnectClient_setSslVerifyPeer_caller_params*)caller_params {
    [[RhoConnectClient_setSslVerifyPeer_caller getSharedInstance] command_setSslVerifyPeer:caller_params];
}

+(void) setSslVerifyPeer_in_thread:(RhoConnectClient_setSslVerifyPeer_caller_params*)caller_params {
    [[RhoConnectClient_setSslVerifyPeer_caller getSharedInstance] performSelectorInBackground:@selector(command_setSslVerifyPeer:) withObject:caller_params];
}

+(void) setSslVerifyPeer_in_UI_thread:(RhoConnectClient_setSslVerifyPeer_caller_params*)caller_params {
    [[RhoConnectClient_setSslVerifyPeer_caller getSharedInstance] performSelectorOnMainThread:@selector(command_setSslVerifyPeer:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_RhoConnectClient_setSslVerifyPeer_Obj(rho::json::CJSONArray& argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[1+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    int argc = argv.getSize();
    
    static RHO_API_PARAM rho_api_params[] = { {RHO_API_BOOLEAN, 0, "value", 0, 0 } };

    
    BOOL is_factory_param[] = { NO, NO };

    int i;

    // init
    for (i = 0; i < (1); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    // enumerate params
    for (int i = 0; i < (1); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(1)];
    for (i = 0 ; i < (1); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (1+1)) {
        rho::json::CJSONEntry callback = argv.getItem(1);
        if (callback.isString()) {
            rho::json::CJSONEntry entry = argv.getItem(i);
            callbackURL = [((NSString*)[CJSConverter convertFromJS:&callback]) retain];
        }
    }
    // check callback param
    if (argc >= (1+2)) {
        rho::json::CJSONEntry callback_param = argv.getItem(1+1);
        if (callback_param.isString()) {
            callbackParam = [((NSString*)[CJSConverter convertFromJS:&callback_param]) retain];
        }
    }
    

    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [RhoConnectClient_setSslVerifyPeer_caller setSslVerifyPeer_in_thread:[RhoConnectClient_setSslVerifyPeer_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [RhoConnectClient_setSslVerifyPeer_caller setSslVerifyPeer:[RhoConnectClient_setSslVerifyPeer_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = "";
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    return resValue;
}


rho::String js_s_RhoConnectClient_setSslVerifyPeer(rho::json::CJSONArray& argv, const rho::String& strObjID) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return js_RhoConnectClient_setSslVerifyPeer_Obj(argv, singleton);

}







@interface RhoConnectClient_loggedIn_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(RhoConnectClient_loggedIn_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation RhoConnectClient_loggedIn_caller_params

@synthesize params,item,methodResult;

+(RhoConnectClient_loggedIn_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    RhoConnectClient_loggedIn_caller_params* par = [[RhoConnectClient_loggedIn_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface RhoConnectClient_loggedIn_caller : NSObject {

}
+(RhoConnectClient_loggedIn_caller*) getSharedInstance;
+(void) loggedIn:(RhoConnectClient_loggedIn_caller_params*)caller_params;
+(void) loggedIn_in_thread:(RhoConnectClient_loggedIn_caller_params*)caller_params;
+(void) loggedIn_in_UI_thread:(RhoConnectClient_loggedIn_caller_params*)caller_params;

@end

static RhoConnectClient_loggedIn_caller* our_RhoConnectClient_loggedIn_caller = nil;

@implementation RhoConnectClient_loggedIn_caller

+(RhoConnectClient_loggedIn_caller*) getSharedInstance {
    if (our_RhoConnectClient_loggedIn_caller == nil) {
        our_RhoConnectClient_loggedIn_caller = [[RhoConnectClient_loggedIn_caller alloc] init];
    }
    return our_RhoConnectClient_loggedIn_caller;
}

-(void) command_loggedIn:(RhoConnectClient_loggedIn_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem loggedIn:methodResult ];
}


+(void) loggedIn:(RhoConnectClient_loggedIn_caller_params*)caller_params {
    [[RhoConnectClient_loggedIn_caller getSharedInstance] command_loggedIn:caller_params];
}

+(void) loggedIn_in_thread:(RhoConnectClient_loggedIn_caller_params*)caller_params {
    [[RhoConnectClient_loggedIn_caller getSharedInstance] performSelectorInBackground:@selector(command_loggedIn:) withObject:caller_params];
}

+(void) loggedIn_in_UI_thread:(RhoConnectClient_loggedIn_caller_params*)caller_params {
    [[RhoConnectClient_loggedIn_caller getSharedInstance] performSelectorOnMainThread:@selector(command_loggedIn:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_RhoConnectClient_loggedIn_Obj(rho::json::CJSONArray& argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[0+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    int argc = argv.getSize();
    
    static RHO_API_PARAM rho_api_params[] = {  };

    
    BOOL is_factory_param[] = { NO };

    int i;

    // init
    for (i = 0; i < (0); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    // enumerate params
    for (int i = 0; i < (0); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(0)];
    for (i = 0 ; i < (0); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (0+1)) {
        rho::json::CJSONEntry callback = argv.getItem(0);
        if (callback.isString()) {
            rho::json::CJSONEntry entry = argv.getItem(i);
            callbackURL = [((NSString*)[CJSConverter convertFromJS:&callback]) retain];
        }
    }
    // check callback param
    if (argc >= (0+2)) {
        rho::json::CJSONEntry callback_param = argv.getItem(0+1);
        if (callback_param.isString()) {
            callbackParam = [((NSString*)[CJSConverter convertFromJS:&callback_param]) retain];
        }
    }
    

    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [RhoConnectClient_loggedIn_caller loggedIn_in_thread:[RhoConnectClient_loggedIn_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [RhoConnectClient_loggedIn_caller loggedIn:[RhoConnectClient_loggedIn_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = "";
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    return resValue;
}


rho::String js_s_RhoConnectClient_loggedIn(rho::json::CJSONArray& argv, const rho::String& strObjID) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return js_RhoConnectClient_loggedIn_Obj(argv, singleton);

}







@interface RhoConnectClient_syncing_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(RhoConnectClient_syncing_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation RhoConnectClient_syncing_caller_params

@synthesize params,item,methodResult;

+(RhoConnectClient_syncing_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    RhoConnectClient_syncing_caller_params* par = [[RhoConnectClient_syncing_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface RhoConnectClient_syncing_caller : NSObject {

}
+(RhoConnectClient_syncing_caller*) getSharedInstance;
+(void) syncing:(RhoConnectClient_syncing_caller_params*)caller_params;
+(void) syncing_in_thread:(RhoConnectClient_syncing_caller_params*)caller_params;
+(void) syncing_in_UI_thread:(RhoConnectClient_syncing_caller_params*)caller_params;

@end

static RhoConnectClient_syncing_caller* our_RhoConnectClient_syncing_caller = nil;

@implementation RhoConnectClient_syncing_caller

+(RhoConnectClient_syncing_caller*) getSharedInstance {
    if (our_RhoConnectClient_syncing_caller == nil) {
        our_RhoConnectClient_syncing_caller = [[RhoConnectClient_syncing_caller alloc] init];
    }
    return our_RhoConnectClient_syncing_caller;
}

-(void) command_syncing:(RhoConnectClient_syncing_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem syncing:methodResult ];
}


+(void) syncing:(RhoConnectClient_syncing_caller_params*)caller_params {
    [[RhoConnectClient_syncing_caller getSharedInstance] command_syncing:caller_params];
}

+(void) syncing_in_thread:(RhoConnectClient_syncing_caller_params*)caller_params {
    [[RhoConnectClient_syncing_caller getSharedInstance] performSelectorInBackground:@selector(command_syncing:) withObject:caller_params];
}

+(void) syncing_in_UI_thread:(RhoConnectClient_syncing_caller_params*)caller_params {
    [[RhoConnectClient_syncing_caller getSharedInstance] performSelectorOnMainThread:@selector(command_syncing:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_RhoConnectClient_syncing_Obj(rho::json::CJSONArray& argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[0+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    int argc = argv.getSize();
    
    static RHO_API_PARAM rho_api_params[] = {  };

    
    BOOL is_factory_param[] = { NO };

    int i;

    // init
    for (i = 0; i < (0); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    // enumerate params
    for (int i = 0; i < (0); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(0)];
    for (i = 0 ; i < (0); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (0+1)) {
        rho::json::CJSONEntry callback = argv.getItem(0);
        if (callback.isString()) {
            rho::json::CJSONEntry entry = argv.getItem(i);
            callbackURL = [((NSString*)[CJSConverter convertFromJS:&callback]) retain];
        }
    }
    // check callback param
    if (argc >= (0+2)) {
        rho::json::CJSONEntry callback_param = argv.getItem(0+1);
        if (callback_param.isString()) {
            callbackParam = [((NSString*)[CJSConverter convertFromJS:&callback_param]) retain];
        }
    }
    

    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [RhoConnectClient_syncing_caller syncing_in_thread:[RhoConnectClient_syncing_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [RhoConnectClient_syncing_caller syncing:[RhoConnectClient_syncing_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = "";
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    return resValue;
}


rho::String js_s_RhoConnectClient_syncing(rho::json::CJSONArray& argv, const rho::String& strObjID) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return js_RhoConnectClient_syncing_Obj(argv, singleton);

}







@interface RhoConnectClient_search_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(RhoConnectClient_search_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation RhoConnectClient_search_caller_params

@synthesize params,item,methodResult;

+(RhoConnectClient_search_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    RhoConnectClient_search_caller_params* par = [[RhoConnectClient_search_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface RhoConnectClient_search_caller : NSObject {

}
+(RhoConnectClient_search_caller*) getSharedInstance;
+(void) search:(RhoConnectClient_search_caller_params*)caller_params;
+(void) search_in_thread:(RhoConnectClient_search_caller_params*)caller_params;
+(void) search_in_UI_thread:(RhoConnectClient_search_caller_params*)caller_params;

@end

static RhoConnectClient_search_caller* our_RhoConnectClient_search_caller = nil;

@implementation RhoConnectClient_search_caller

+(RhoConnectClient_search_caller*) getSharedInstance {
    if (our_RhoConnectClient_search_caller == nil) {
        our_RhoConnectClient_search_caller = [[RhoConnectClient_search_caller alloc] init];
    }
    return our_RhoConnectClient_search_caller;
}

-(void) command_search:(RhoConnectClient_search_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem search:(NSDictionary*)[params objectAtIndex:0] methodResult:methodResult ];
}


+(void) search:(RhoConnectClient_search_caller_params*)caller_params {
    [[RhoConnectClient_search_caller getSharedInstance] command_search:caller_params];
}

+(void) search_in_thread:(RhoConnectClient_search_caller_params*)caller_params {
    [[RhoConnectClient_search_caller getSharedInstance] performSelectorInBackground:@selector(command_search:) withObject:caller_params];
}

+(void) search_in_UI_thread:(RhoConnectClient_search_caller_params*)caller_params {
    [[RhoConnectClient_search_caller getSharedInstance] performSelectorOnMainThread:@selector(command_search:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_RhoConnectClient_search_Obj(rho::json::CJSONArray& argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[1+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    int argc = argv.getSize();
    
    static RHO_API_PARAM rho_api_params_param0_param0[] = { {RHO_API_STRING, 0, 0, 0, 0 } };
    static RHO_API_PARAM rho_api_params_param0[] = { {RHO_API_ARRAY, 0, "sourceNames", 1, rho_api_params_param0_param0 }, {RHO_API_STRING, 0, "from", 0, 0 }, {RHO_API_HASH, 0, "searchParams", 0, 0 }, {RHO_API_INTEGER, 0, "offset", 0, 0 }, {RHO_API_INTEGER, 0, "maxResults", 0, 0 }, {RHO_API_INTEGER, 0, "progressStep", 0, 0 }, {RHO_API_BOOLEAN, 0, "syncChanges", 0, 0 } };
    static RHO_API_PARAM rho_api_params[] = { {RHO_API_HASH, 0, "args", 7, rho_api_params_param0 } };

    
    BOOL is_factory_param[] = { NO, NO };

    int i;

    // init
    for (i = 0; i < (1); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    // enumerate params
    for (int i = 0; i < (1); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(1)];
    for (i = 0 ; i < (1); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (1+1)) {
        rho::json::CJSONEntry callback = argv.getItem(1);
        if (callback.isString()) {
            rho::json::CJSONEntry entry = argv.getItem(i);
            callbackURL = [((NSString*)[CJSConverter convertFromJS:&callback]) retain];
        }
    }
    // check callback param
    if (argc >= (1+2)) {
        rho::json::CJSONEntry callback_param = argv.getItem(1+1);
        if (callback_param.isString()) {
            callbackParam = [((NSString*)[CJSConverter convertFromJS:&callback_param]) retain];
        }
    }
    

    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [RhoConnectClient_search_caller search_in_thread:[RhoConnectClient_search_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [RhoConnectClient_search_caller search:[RhoConnectClient_search_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = "";
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    return resValue;
}


rho::String js_s_RhoConnectClient_search(rho::json::CJSONArray& argv, const rho::String& strObjID) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return js_RhoConnectClient_search_Obj(argv, singleton);

}







@interface RhoConnectClient_doSync_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(RhoConnectClient_doSync_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation RhoConnectClient_doSync_caller_params

@synthesize params,item,methodResult;

+(RhoConnectClient_doSync_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    RhoConnectClient_doSync_caller_params* par = [[RhoConnectClient_doSync_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface RhoConnectClient_doSync_caller : NSObject {

}
+(RhoConnectClient_doSync_caller*) getSharedInstance;
+(void) doSync:(RhoConnectClient_doSync_caller_params*)caller_params;
+(void) doSync_in_thread:(RhoConnectClient_doSync_caller_params*)caller_params;
+(void) doSync_in_UI_thread:(RhoConnectClient_doSync_caller_params*)caller_params;

@end

static RhoConnectClient_doSync_caller* our_RhoConnectClient_doSync_caller = nil;

@implementation RhoConnectClient_doSync_caller

+(RhoConnectClient_doSync_caller*) getSharedInstance {
    if (our_RhoConnectClient_doSync_caller == nil) {
        our_RhoConnectClient_doSync_caller = [[RhoConnectClient_doSync_caller alloc] init];
    }
    return our_RhoConnectClient_doSync_caller;
}

-(void) command_doSync:(RhoConnectClient_doSync_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem doSync:(BOOL)[((NSNumber*)[params objectAtIndex:0]) boolValue] queryParams:(NSString*)[params objectAtIndex:1] syncOnlyChangedSources:(BOOL)[((NSNumber*)[params objectAtIndex:2]) boolValue] methodResult:methodResult ];
}


+(void) doSync:(RhoConnectClient_doSync_caller_params*)caller_params {
    [[RhoConnectClient_doSync_caller getSharedInstance] command_doSync:caller_params];
}

+(void) doSync_in_thread:(RhoConnectClient_doSync_caller_params*)caller_params {
    [[RhoConnectClient_doSync_caller getSharedInstance] performSelectorInBackground:@selector(command_doSync:) withObject:caller_params];
}

+(void) doSync_in_UI_thread:(RhoConnectClient_doSync_caller_params*)caller_params {
    [[RhoConnectClient_doSync_caller getSharedInstance] performSelectorOnMainThread:@selector(command_doSync:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_RhoConnectClient_doSync_Obj(rho::json::CJSONArray& argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[3+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    int argc = argv.getSize();
    
    static RHO_API_PARAM rho_api_params[] = { {RHO_API_BOOLEAN, 0, "showStatusPopup", 0, 0 }, {RHO_API_STRING, 0, "queryParams", 0, 0 }, {RHO_API_BOOLEAN, 0, "syncOnlyChangedSources", 0, 0 } };

    
    BOOL is_factory_param[] = { NO, NO, NO, NO };

    int i;

    // init
    for (i = 0; i < (3); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    // enumerate params
    for (int i = 0; i < (3); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(3)];
    for (i = 0 ; i < (3); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (3+1)) {
        rho::json::CJSONEntry callback = argv.getItem(3);
        if (callback.isString()) {
            rho::json::CJSONEntry entry = argv.getItem(i);
            callbackURL = [((NSString*)[CJSConverter convertFromJS:&callback]) retain];
        }
    }
    // check callback param
    if (argc >= (3+2)) {
        rho::json::CJSONEntry callback_param = argv.getItem(3+1);
        if (callback_param.isString()) {
            callbackParam = [((NSString*)[CJSConverter convertFromJS:&callback_param]) retain];
        }
    }
    

    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [RhoConnectClient_doSync_caller doSync_in_thread:[RhoConnectClient_doSync_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [RhoConnectClient_doSync_caller doSync:[RhoConnectClient_doSync_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = "";
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    return resValue;
}


rho::String js_s_RhoConnectClient_doSync(rho::json::CJSONArray& argv, const rho::String& strObjID) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return js_RhoConnectClient_doSync_Obj(argv, singleton);

}







@interface RhoConnectClient_doSyncSource_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(RhoConnectClient_doSyncSource_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation RhoConnectClient_doSyncSource_caller_params

@synthesize params,item,methodResult;

+(RhoConnectClient_doSyncSource_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    RhoConnectClient_doSyncSource_caller_params* par = [[RhoConnectClient_doSyncSource_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface RhoConnectClient_doSyncSource_caller : NSObject {

}
+(RhoConnectClient_doSyncSource_caller*) getSharedInstance;
+(void) doSyncSource:(RhoConnectClient_doSyncSource_caller_params*)caller_params;
+(void) doSyncSource_in_thread:(RhoConnectClient_doSyncSource_caller_params*)caller_params;
+(void) doSyncSource_in_UI_thread:(RhoConnectClient_doSyncSource_caller_params*)caller_params;

@end

static RhoConnectClient_doSyncSource_caller* our_RhoConnectClient_doSyncSource_caller = nil;

@implementation RhoConnectClient_doSyncSource_caller

+(RhoConnectClient_doSyncSource_caller*) getSharedInstance {
    if (our_RhoConnectClient_doSyncSource_caller == nil) {
        our_RhoConnectClient_doSyncSource_caller = [[RhoConnectClient_doSyncSource_caller alloc] init];
    }
    return our_RhoConnectClient_doSyncSource_caller;
}

-(void) command_doSyncSource:(RhoConnectClient_doSyncSource_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem doSyncSource:(NSString*)[params objectAtIndex:0] showStatusPopup:(BOOL)[((NSNumber*)[params objectAtIndex:1]) boolValue] queryParams:(NSString*)[params objectAtIndex:2] methodResult:methodResult ];
}


+(void) doSyncSource:(RhoConnectClient_doSyncSource_caller_params*)caller_params {
    [[RhoConnectClient_doSyncSource_caller getSharedInstance] command_doSyncSource:caller_params];
}

+(void) doSyncSource_in_thread:(RhoConnectClient_doSyncSource_caller_params*)caller_params {
    [[RhoConnectClient_doSyncSource_caller getSharedInstance] performSelectorInBackground:@selector(command_doSyncSource:) withObject:caller_params];
}

+(void) doSyncSource_in_UI_thread:(RhoConnectClient_doSyncSource_caller_params*)caller_params {
    [[RhoConnectClient_doSyncSource_caller getSharedInstance] performSelectorOnMainThread:@selector(command_doSyncSource:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_RhoConnectClient_doSyncSource_Obj(rho::json::CJSONArray& argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[3+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    int argc = argv.getSize();
    
    static RHO_API_PARAM rho_api_params[] = { {RHO_API_STRING, 0, "sourceName", 0, 0 }, {RHO_API_BOOLEAN, 0, "showStatusPopup", 0, 0 }, {RHO_API_STRING, 0, "queryParams", 0, 0 } };

    
    BOOL is_factory_param[] = { NO, NO, NO, NO };

    int i;

    // init
    for (i = 0; i < (3); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    // enumerate params
    for (int i = 0; i < (3); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(3)];
    for (i = 0 ; i < (3); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (3+1)) {
        rho::json::CJSONEntry callback = argv.getItem(3);
        if (callback.isString()) {
            rho::json::CJSONEntry entry = argv.getItem(i);
            callbackURL = [((NSString*)[CJSConverter convertFromJS:&callback]) retain];
        }
    }
    // check callback param
    if (argc >= (3+2)) {
        rho::json::CJSONEntry callback_param = argv.getItem(3+1);
        if (callback_param.isString()) {
            callbackParam = [((NSString*)[CJSConverter convertFromJS:&callback_param]) retain];
        }
    }
    

    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [RhoConnectClient_doSyncSource_caller doSyncSource_in_thread:[RhoConnectClient_doSyncSource_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [RhoConnectClient_doSyncSource_caller doSyncSource:[RhoConnectClient_doSyncSource_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = "";
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    return resValue;
}


rho::String js_s_RhoConnectClient_doSyncSource(rho::json::CJSONArray& argv, const rho::String& strObjID) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return js_RhoConnectClient_doSyncSource_Obj(argv, singleton);

}







@interface RhoConnectClient_login_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(RhoConnectClient_login_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation RhoConnectClient_login_caller_params

@synthesize params,item,methodResult;

+(RhoConnectClient_login_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    RhoConnectClient_login_caller_params* par = [[RhoConnectClient_login_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface RhoConnectClient_login_caller : NSObject {

}
+(RhoConnectClient_login_caller*) getSharedInstance;
+(void) login:(RhoConnectClient_login_caller_params*)caller_params;
+(void) login_in_thread:(RhoConnectClient_login_caller_params*)caller_params;
+(void) login_in_UI_thread:(RhoConnectClient_login_caller_params*)caller_params;

@end

static RhoConnectClient_login_caller* our_RhoConnectClient_login_caller = nil;

@implementation RhoConnectClient_login_caller

+(RhoConnectClient_login_caller*) getSharedInstance {
    if (our_RhoConnectClient_login_caller == nil) {
        our_RhoConnectClient_login_caller = [[RhoConnectClient_login_caller alloc] init];
    }
    return our_RhoConnectClient_login_caller;
}

-(void) command_login:(RhoConnectClient_login_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem login:(NSString*)[params objectAtIndex:0] password:(NSString*)[params objectAtIndex:1] methodResult:methodResult ];
}


+(void) login:(RhoConnectClient_login_caller_params*)caller_params {
    [[RhoConnectClient_login_caller getSharedInstance] command_login:caller_params];
}

+(void) login_in_thread:(RhoConnectClient_login_caller_params*)caller_params {
    [[RhoConnectClient_login_caller getSharedInstance] performSelectorInBackground:@selector(command_login:) withObject:caller_params];
}

+(void) login_in_UI_thread:(RhoConnectClient_login_caller_params*)caller_params {
    [[RhoConnectClient_login_caller getSharedInstance] performSelectorOnMainThread:@selector(command_login:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_RhoConnectClient_login_Obj(rho::json::CJSONArray& argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[2+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    int argc = argv.getSize();
    
    static RHO_API_PARAM rho_api_params[] = { {RHO_API_STRING, 0, "login", 0, 0 }, {RHO_API_STRING, 0, "password", 0, 0 } };

    
    BOOL is_factory_param[] = { NO, NO, NO };

    int i;

    // init
    for (i = 0; i < (2); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    // enumerate params
    for (int i = 0; i < (2); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(2)];
    for (i = 0 ; i < (2); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (2+1)) {
        rho::json::CJSONEntry callback = argv.getItem(2);
        if (callback.isString()) {
            rho::json::CJSONEntry entry = argv.getItem(i);
            callbackURL = [((NSString*)[CJSConverter convertFromJS:&callback]) retain];
        }
    }
    // check callback param
    if (argc >= (2+2)) {
        rho::json::CJSONEntry callback_param = argv.getItem(2+1);
        if (callback_param.isString()) {
            callbackParam = [((NSString*)[CJSConverter convertFromJS:&callback_param]) retain];
        }
    }
    

    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [RhoConnectClient_login_caller login_in_thread:[RhoConnectClient_login_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [RhoConnectClient_login_caller login:[RhoConnectClient_login_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = "";
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    return resValue;
}


rho::String js_s_RhoConnectClient_login(rho::json::CJSONArray& argv, const rho::String& strObjID) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return js_RhoConnectClient_login_Obj(argv, singleton);

}







@interface RhoConnectClient_logout_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(RhoConnectClient_logout_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation RhoConnectClient_logout_caller_params

@synthesize params,item,methodResult;

+(RhoConnectClient_logout_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    RhoConnectClient_logout_caller_params* par = [[RhoConnectClient_logout_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface RhoConnectClient_logout_caller : NSObject {

}
+(RhoConnectClient_logout_caller*) getSharedInstance;
+(void) logout:(RhoConnectClient_logout_caller_params*)caller_params;
+(void) logout_in_thread:(RhoConnectClient_logout_caller_params*)caller_params;
+(void) logout_in_UI_thread:(RhoConnectClient_logout_caller_params*)caller_params;

@end

static RhoConnectClient_logout_caller* our_RhoConnectClient_logout_caller = nil;

@implementation RhoConnectClient_logout_caller

+(RhoConnectClient_logout_caller*) getSharedInstance {
    if (our_RhoConnectClient_logout_caller == nil) {
        our_RhoConnectClient_logout_caller = [[RhoConnectClient_logout_caller alloc] init];
    }
    return our_RhoConnectClient_logout_caller;
}

-(void) command_logout:(RhoConnectClient_logout_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem logout];
}


+(void) logout:(RhoConnectClient_logout_caller_params*)caller_params {
    [[RhoConnectClient_logout_caller getSharedInstance] command_logout:caller_params];
}

+(void) logout_in_thread:(RhoConnectClient_logout_caller_params*)caller_params {
    [[RhoConnectClient_logout_caller getSharedInstance] performSelectorInBackground:@selector(command_logout:) withObject:caller_params];
}

+(void) logout_in_UI_thread:(RhoConnectClient_logout_caller_params*)caller_params {
    [[RhoConnectClient_logout_caller getSharedInstance] performSelectorOnMainThread:@selector(command_logout:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_RhoConnectClient_logout_Obj(rho::json::CJSONArray& argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[0+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    int argc = argv.getSize();
    
    static RHO_API_PARAM rho_api_params[] = {  };

    
    BOOL is_factory_param[] = { NO };

    int i;

    // init
    for (i = 0; i < (0); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    // enumerate params
    for (int i = 0; i < (0); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(0)];
    for (i = 0 ; i < (0); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (0+1)) {
        rho::json::CJSONEntry callback = argv.getItem(0);
        if (callback.isString()) {
            rho::json::CJSONEntry entry = argv.getItem(i);
            callbackURL = [((NSString*)[CJSConverter convertFromJS:&callback]) retain];
        }
    }
    // check callback param
    if (argc >= (0+2)) {
        rho::json::CJSONEntry callback_param = argv.getItem(0+1);
        if (callback_param.isString()) {
            callbackParam = [((NSString*)[CJSConverter convertFromJS:&callback_param]) retain];
        }
    }
    

    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [RhoConnectClient_logout_caller logout_in_thread:[RhoConnectClient_logout_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [RhoConnectClient_logout_caller logout:[RhoConnectClient_logout_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = "";
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    return resValue;
}


rho::String js_s_RhoConnectClient_logout(rho::json::CJSONArray& argv, const rho::String& strObjID) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return js_RhoConnectClient_logout_Obj(argv, singleton);

}







@interface RhoConnectClient_stopSync_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(RhoConnectClient_stopSync_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation RhoConnectClient_stopSync_caller_params

@synthesize params,item,methodResult;

+(RhoConnectClient_stopSync_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    RhoConnectClient_stopSync_caller_params* par = [[RhoConnectClient_stopSync_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface RhoConnectClient_stopSync_caller : NSObject {

}
+(RhoConnectClient_stopSync_caller*) getSharedInstance;
+(void) stopSync:(RhoConnectClient_stopSync_caller_params*)caller_params;
+(void) stopSync_in_thread:(RhoConnectClient_stopSync_caller_params*)caller_params;
+(void) stopSync_in_UI_thread:(RhoConnectClient_stopSync_caller_params*)caller_params;

@end

static RhoConnectClient_stopSync_caller* our_RhoConnectClient_stopSync_caller = nil;

@implementation RhoConnectClient_stopSync_caller

+(RhoConnectClient_stopSync_caller*) getSharedInstance {
    if (our_RhoConnectClient_stopSync_caller == nil) {
        our_RhoConnectClient_stopSync_caller = [[RhoConnectClient_stopSync_caller alloc] init];
    }
    return our_RhoConnectClient_stopSync_caller;
}

-(void) command_stopSync:(RhoConnectClient_stopSync_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem stopSync];
}


+(void) stopSync:(RhoConnectClient_stopSync_caller_params*)caller_params {
    [[RhoConnectClient_stopSync_caller getSharedInstance] command_stopSync:caller_params];
}

+(void) stopSync_in_thread:(RhoConnectClient_stopSync_caller_params*)caller_params {
    [[RhoConnectClient_stopSync_caller getSharedInstance] performSelectorInBackground:@selector(command_stopSync:) withObject:caller_params];
}

+(void) stopSync_in_UI_thread:(RhoConnectClient_stopSync_caller_params*)caller_params {
    [[RhoConnectClient_stopSync_caller getSharedInstance] performSelectorOnMainThread:@selector(command_stopSync:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_RhoConnectClient_stopSync_Obj(rho::json::CJSONArray& argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[0+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    int argc = argv.getSize();
    
    static RHO_API_PARAM rho_api_params[] = {  };

    
    BOOL is_factory_param[] = { NO };

    int i;

    // init
    for (i = 0; i < (0); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    // enumerate params
    for (int i = 0; i < (0); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(0)];
    for (i = 0 ; i < (0); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (0+1)) {
        rho::json::CJSONEntry callback = argv.getItem(0);
        if (callback.isString()) {
            rho::json::CJSONEntry entry = argv.getItem(i);
            callbackURL = [((NSString*)[CJSConverter convertFromJS:&callback]) retain];
        }
    }
    // check callback param
    if (argc >= (0+2)) {
        rho::json::CJSONEntry callback_param = argv.getItem(0+1);
        if (callback_param.isString()) {
            callbackParam = [((NSString*)[CJSConverter convertFromJS:&callback_param]) retain];
        }
    }
    

    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [RhoConnectClient_stopSync_caller stopSync_in_thread:[RhoConnectClient_stopSync_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [RhoConnectClient_stopSync_caller stopSync:[RhoConnectClient_stopSync_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = "";
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    return resValue;
}


rho::String js_s_RhoConnectClient_stopSync(rho::json::CJSONArray& argv, const rho::String& strObjID) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return js_RhoConnectClient_stopSync_Obj(argv, singleton);

}







@interface RhoConnectClient_setNotification_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(RhoConnectClient_setNotification_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation RhoConnectClient_setNotification_caller_params

@synthesize params,item,methodResult;

+(RhoConnectClient_setNotification_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    RhoConnectClient_setNotification_caller_params* par = [[RhoConnectClient_setNotification_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface RhoConnectClient_setNotification_caller : NSObject {

}
+(RhoConnectClient_setNotification_caller*) getSharedInstance;
+(void) setNotification:(RhoConnectClient_setNotification_caller_params*)caller_params;
+(void) setNotification_in_thread:(RhoConnectClient_setNotification_caller_params*)caller_params;
+(void) setNotification_in_UI_thread:(RhoConnectClient_setNotification_caller_params*)caller_params;

@end

static RhoConnectClient_setNotification_caller* our_RhoConnectClient_setNotification_caller = nil;

@implementation RhoConnectClient_setNotification_caller

+(RhoConnectClient_setNotification_caller*) getSharedInstance {
    if (our_RhoConnectClient_setNotification_caller == nil) {
        our_RhoConnectClient_setNotification_caller = [[RhoConnectClient_setNotification_caller alloc] init];
    }
    return our_RhoConnectClient_setNotification_caller;
}

-(void) command_setNotification:(RhoConnectClient_setNotification_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem setNotification:(NSString*)[params objectAtIndex:0] methodResult:methodResult ];
}


+(void) setNotification:(RhoConnectClient_setNotification_caller_params*)caller_params {
    [[RhoConnectClient_setNotification_caller getSharedInstance] command_setNotification:caller_params];
}

+(void) setNotification_in_thread:(RhoConnectClient_setNotification_caller_params*)caller_params {
    [[RhoConnectClient_setNotification_caller getSharedInstance] performSelectorInBackground:@selector(command_setNotification:) withObject:caller_params];
}

+(void) setNotification_in_UI_thread:(RhoConnectClient_setNotification_caller_params*)caller_params {
    [[RhoConnectClient_setNotification_caller getSharedInstance] performSelectorOnMainThread:@selector(command_setNotification:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_RhoConnectClient_setNotification_Obj(rho::json::CJSONArray& argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[1+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    int argc = argv.getSize();
    
    static RHO_API_PARAM rho_api_params[] = { {RHO_API_STRING, 0, "sourceName", 0, 0 } };

    
    BOOL is_factory_param[] = { NO, NO };

    int i;

    // init
    for (i = 0; i < (1); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    // enumerate params
    for (int i = 0; i < (1); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(1)];
    for (i = 0 ; i < (1); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (1+1)) {
        rho::json::CJSONEntry callback = argv.getItem(1);
        if (callback.isString()) {
            rho::json::CJSONEntry entry = argv.getItem(i);
            callbackURL = [((NSString*)[CJSConverter convertFromJS:&callback]) retain];
        }
    }
    // check callback param
    if (argc >= (1+2)) {
        rho::json::CJSONEntry callback_param = argv.getItem(1+1);
        if (callback_param.isString()) {
            callbackParam = [((NSString*)[CJSConverter convertFromJS:&callback_param]) retain];
        }
    }
    

    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [RhoConnectClient_setNotification_caller setNotification_in_thread:[RhoConnectClient_setNotification_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [RhoConnectClient_setNotification_caller setNotification:[RhoConnectClient_setNotification_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = "";
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    return resValue;
}


rho::String js_s_RhoConnectClient_setNotification(rho::json::CJSONArray& argv, const rho::String& strObjID) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return js_RhoConnectClient_setNotification_Obj(argv, singleton);

}







@interface RhoConnectClient_clearNotification_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(RhoConnectClient_clearNotification_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation RhoConnectClient_clearNotification_caller_params

@synthesize params,item,methodResult;

+(RhoConnectClient_clearNotification_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    RhoConnectClient_clearNotification_caller_params* par = [[RhoConnectClient_clearNotification_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface RhoConnectClient_clearNotification_caller : NSObject {

}
+(RhoConnectClient_clearNotification_caller*) getSharedInstance;
+(void) clearNotification:(RhoConnectClient_clearNotification_caller_params*)caller_params;
+(void) clearNotification_in_thread:(RhoConnectClient_clearNotification_caller_params*)caller_params;
+(void) clearNotification_in_UI_thread:(RhoConnectClient_clearNotification_caller_params*)caller_params;

@end

static RhoConnectClient_clearNotification_caller* our_RhoConnectClient_clearNotification_caller = nil;

@implementation RhoConnectClient_clearNotification_caller

+(RhoConnectClient_clearNotification_caller*) getSharedInstance {
    if (our_RhoConnectClient_clearNotification_caller == nil) {
        our_RhoConnectClient_clearNotification_caller = [[RhoConnectClient_clearNotification_caller alloc] init];
    }
    return our_RhoConnectClient_clearNotification_caller;
}

-(void) command_clearNotification:(RhoConnectClient_clearNotification_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem clearNotification:(NSString*)[params objectAtIndex:0] ];
}


+(void) clearNotification:(RhoConnectClient_clearNotification_caller_params*)caller_params {
    [[RhoConnectClient_clearNotification_caller getSharedInstance] command_clearNotification:caller_params];
}

+(void) clearNotification_in_thread:(RhoConnectClient_clearNotification_caller_params*)caller_params {
    [[RhoConnectClient_clearNotification_caller getSharedInstance] performSelectorInBackground:@selector(command_clearNotification:) withObject:caller_params];
}

+(void) clearNotification_in_UI_thread:(RhoConnectClient_clearNotification_caller_params*)caller_params {
    [[RhoConnectClient_clearNotification_caller getSharedInstance] performSelectorOnMainThread:@selector(command_clearNotification:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_RhoConnectClient_clearNotification_Obj(rho::json::CJSONArray& argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[1+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    int argc = argv.getSize();
    
    static RHO_API_PARAM rho_api_params[] = { {RHO_API_STRING, 0, "sourceName", 0, 0 } };

    
    BOOL is_factory_param[] = { NO, NO };

    int i;

    // init
    for (i = 0; i < (1); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    // enumerate params
    for (int i = 0; i < (1); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(1)];
    for (i = 0 ; i < (1); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (1+1)) {
        rho::json::CJSONEntry callback = argv.getItem(1);
        if (callback.isString()) {
            rho::json::CJSONEntry entry = argv.getItem(i);
            callbackURL = [((NSString*)[CJSConverter convertFromJS:&callback]) retain];
        }
    }
    // check callback param
    if (argc >= (1+2)) {
        rho::json::CJSONEntry callback_param = argv.getItem(1+1);
        if (callback_param.isString()) {
            callbackParam = [((NSString*)[CJSConverter convertFromJS:&callback_param]) retain];
        }
    }
    

    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [RhoConnectClient_clearNotification_caller clearNotification_in_thread:[RhoConnectClient_clearNotification_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [RhoConnectClient_clearNotification_caller clearNotification:[RhoConnectClient_clearNotification_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = "";
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    return resValue;
}


rho::String js_s_RhoConnectClient_clearNotification(rho::json::CJSONArray& argv, const rho::String& strObjID) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return js_RhoConnectClient_clearNotification_Obj(argv, singleton);

}







@interface RhoConnectClient_setObjectNotification_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(RhoConnectClient_setObjectNotification_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation RhoConnectClient_setObjectNotification_caller_params

@synthesize params,item,methodResult;

+(RhoConnectClient_setObjectNotification_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    RhoConnectClient_setObjectNotification_caller_params* par = [[RhoConnectClient_setObjectNotification_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface RhoConnectClient_setObjectNotification_caller : NSObject {

}
+(RhoConnectClient_setObjectNotification_caller*) getSharedInstance;
+(void) setObjectNotification:(RhoConnectClient_setObjectNotification_caller_params*)caller_params;
+(void) setObjectNotification_in_thread:(RhoConnectClient_setObjectNotification_caller_params*)caller_params;
+(void) setObjectNotification_in_UI_thread:(RhoConnectClient_setObjectNotification_caller_params*)caller_params;

@end

static RhoConnectClient_setObjectNotification_caller* our_RhoConnectClient_setObjectNotification_caller = nil;

@implementation RhoConnectClient_setObjectNotification_caller

+(RhoConnectClient_setObjectNotification_caller*) getSharedInstance {
    if (our_RhoConnectClient_setObjectNotification_caller == nil) {
        our_RhoConnectClient_setObjectNotification_caller = [[RhoConnectClient_setObjectNotification_caller alloc] init];
    }
    return our_RhoConnectClient_setObjectNotification_caller;
}

-(void) command_setObjectNotification:(RhoConnectClient_setObjectNotification_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem setObjectNotification:methodResult ];
}


+(void) setObjectNotification:(RhoConnectClient_setObjectNotification_caller_params*)caller_params {
    [[RhoConnectClient_setObjectNotification_caller getSharedInstance] command_setObjectNotification:caller_params];
}

+(void) setObjectNotification_in_thread:(RhoConnectClient_setObjectNotification_caller_params*)caller_params {
    [[RhoConnectClient_setObjectNotification_caller getSharedInstance] performSelectorInBackground:@selector(command_setObjectNotification:) withObject:caller_params];
}

+(void) setObjectNotification_in_UI_thread:(RhoConnectClient_setObjectNotification_caller_params*)caller_params {
    [[RhoConnectClient_setObjectNotification_caller getSharedInstance] performSelectorOnMainThread:@selector(command_setObjectNotification:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_RhoConnectClient_setObjectNotification_Obj(rho::json::CJSONArray& argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[0+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    int argc = argv.getSize();
    
    static RHO_API_PARAM rho_api_params[] = {  };

    
    BOOL is_factory_param[] = { NO };

    int i;

    // init
    for (i = 0; i < (0); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    // enumerate params
    for (int i = 0; i < (0); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(0)];
    for (i = 0 ; i < (0); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (0+1)) {
        rho::json::CJSONEntry callback = argv.getItem(0);
        if (callback.isString()) {
            rho::json::CJSONEntry entry = argv.getItem(i);
            callbackURL = [((NSString*)[CJSConverter convertFromJS:&callback]) retain];
        }
    }
    // check callback param
    if (argc >= (0+2)) {
        rho::json::CJSONEntry callback_param = argv.getItem(0+1);
        if (callback_param.isString()) {
            callbackParam = [((NSString*)[CJSConverter convertFromJS:&callback_param]) retain];
        }
    }
    

    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [RhoConnectClient_setObjectNotification_caller setObjectNotification_in_thread:[RhoConnectClient_setObjectNotification_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [RhoConnectClient_setObjectNotification_caller setObjectNotification:[RhoConnectClient_setObjectNotification_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = "";
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    return resValue;
}


rho::String js_s_RhoConnectClient_setObjectNotification(rho::json::CJSONArray& argv, const rho::String& strObjID) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return js_RhoConnectClient_setObjectNotification_Obj(argv, singleton);

}







@interface RhoConnectClient_addObjectNotify_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(RhoConnectClient_addObjectNotify_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation RhoConnectClient_addObjectNotify_caller_params

@synthesize params,item,methodResult;

+(RhoConnectClient_addObjectNotify_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    RhoConnectClient_addObjectNotify_caller_params* par = [[RhoConnectClient_addObjectNotify_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface RhoConnectClient_addObjectNotify_caller : NSObject {

}
+(RhoConnectClient_addObjectNotify_caller*) getSharedInstance;
+(void) addObjectNotify:(RhoConnectClient_addObjectNotify_caller_params*)caller_params;
+(void) addObjectNotify_in_thread:(RhoConnectClient_addObjectNotify_caller_params*)caller_params;
+(void) addObjectNotify_in_UI_thread:(RhoConnectClient_addObjectNotify_caller_params*)caller_params;

@end

static RhoConnectClient_addObjectNotify_caller* our_RhoConnectClient_addObjectNotify_caller = nil;

@implementation RhoConnectClient_addObjectNotify_caller

+(RhoConnectClient_addObjectNotify_caller*) getSharedInstance {
    if (our_RhoConnectClient_addObjectNotify_caller == nil) {
        our_RhoConnectClient_addObjectNotify_caller = [[RhoConnectClient_addObjectNotify_caller alloc] init];
    }
    return our_RhoConnectClient_addObjectNotify_caller;
}

-(void) command_addObjectNotify:(RhoConnectClient_addObjectNotify_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem addObjectNotify:(NSString*)[params objectAtIndex:0] object:(NSString*)[params objectAtIndex:1] ];
}


+(void) addObjectNotify:(RhoConnectClient_addObjectNotify_caller_params*)caller_params {
    [[RhoConnectClient_addObjectNotify_caller getSharedInstance] command_addObjectNotify:caller_params];
}

+(void) addObjectNotify_in_thread:(RhoConnectClient_addObjectNotify_caller_params*)caller_params {
    [[RhoConnectClient_addObjectNotify_caller getSharedInstance] performSelectorInBackground:@selector(command_addObjectNotify:) withObject:caller_params];
}

+(void) addObjectNotify_in_UI_thread:(RhoConnectClient_addObjectNotify_caller_params*)caller_params {
    [[RhoConnectClient_addObjectNotify_caller getSharedInstance] performSelectorOnMainThread:@selector(command_addObjectNotify:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_RhoConnectClient_addObjectNotify_Obj(rho::json::CJSONArray& argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[2+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    int argc = argv.getSize();
    
    static RHO_API_PARAM rho_api_params[] = { {RHO_API_STRING, 0, "sourceName", 0, 0 }, {RHO_API_STRING, 0, "object", 0, 0 } };

    
    BOOL is_factory_param[] = { NO, NO, NO };

    int i;

    // init
    for (i = 0; i < (2); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    // enumerate params
    for (int i = 0; i < (2); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(2)];
    for (i = 0 ; i < (2); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (2+1)) {
        rho::json::CJSONEntry callback = argv.getItem(2);
        if (callback.isString()) {
            rho::json::CJSONEntry entry = argv.getItem(i);
            callbackURL = [((NSString*)[CJSConverter convertFromJS:&callback]) retain];
        }
    }
    // check callback param
    if (argc >= (2+2)) {
        rho::json::CJSONEntry callback_param = argv.getItem(2+1);
        if (callback_param.isString()) {
            callbackParam = [((NSString*)[CJSConverter convertFromJS:&callback_param]) retain];
        }
    }
    

    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [RhoConnectClient_addObjectNotify_caller addObjectNotify_in_thread:[RhoConnectClient_addObjectNotify_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [RhoConnectClient_addObjectNotify_caller addObjectNotify:[RhoConnectClient_addObjectNotify_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = "";
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    return resValue;
}


rho::String js_s_RhoConnectClient_addObjectNotify(rho::json::CJSONArray& argv, const rho::String& strObjID) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return js_RhoConnectClient_addObjectNotify_Obj(argv, singleton);

}







@interface RhoConnectClient_cleanObjectNotify_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(RhoConnectClient_cleanObjectNotify_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation RhoConnectClient_cleanObjectNotify_caller_params

@synthesize params,item,methodResult;

+(RhoConnectClient_cleanObjectNotify_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    RhoConnectClient_cleanObjectNotify_caller_params* par = [[RhoConnectClient_cleanObjectNotify_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface RhoConnectClient_cleanObjectNotify_caller : NSObject {

}
+(RhoConnectClient_cleanObjectNotify_caller*) getSharedInstance;
+(void) cleanObjectNotify:(RhoConnectClient_cleanObjectNotify_caller_params*)caller_params;
+(void) cleanObjectNotify_in_thread:(RhoConnectClient_cleanObjectNotify_caller_params*)caller_params;
+(void) cleanObjectNotify_in_UI_thread:(RhoConnectClient_cleanObjectNotify_caller_params*)caller_params;

@end

static RhoConnectClient_cleanObjectNotify_caller* our_RhoConnectClient_cleanObjectNotify_caller = nil;

@implementation RhoConnectClient_cleanObjectNotify_caller

+(RhoConnectClient_cleanObjectNotify_caller*) getSharedInstance {
    if (our_RhoConnectClient_cleanObjectNotify_caller == nil) {
        our_RhoConnectClient_cleanObjectNotify_caller = [[RhoConnectClient_cleanObjectNotify_caller alloc] init];
    }
    return our_RhoConnectClient_cleanObjectNotify_caller;
}

-(void) command_cleanObjectNotify:(RhoConnectClient_cleanObjectNotify_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem cleanObjectNotify];
}


+(void) cleanObjectNotify:(RhoConnectClient_cleanObjectNotify_caller_params*)caller_params {
    [[RhoConnectClient_cleanObjectNotify_caller getSharedInstance] command_cleanObjectNotify:caller_params];
}

+(void) cleanObjectNotify_in_thread:(RhoConnectClient_cleanObjectNotify_caller_params*)caller_params {
    [[RhoConnectClient_cleanObjectNotify_caller getSharedInstance] performSelectorInBackground:@selector(command_cleanObjectNotify:) withObject:caller_params];
}

+(void) cleanObjectNotify_in_UI_thread:(RhoConnectClient_cleanObjectNotify_caller_params*)caller_params {
    [[RhoConnectClient_cleanObjectNotify_caller getSharedInstance] performSelectorOnMainThread:@selector(command_cleanObjectNotify:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_RhoConnectClient_cleanObjectNotify_Obj(rho::json::CJSONArray& argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[0+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    int argc = argv.getSize();
    
    static RHO_API_PARAM rho_api_params[] = {  };

    
    BOOL is_factory_param[] = { NO };

    int i;

    // init
    for (i = 0; i < (0); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    // enumerate params
    for (int i = 0; i < (0); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(0)];
    for (i = 0 ; i < (0); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (0+1)) {
        rho::json::CJSONEntry callback = argv.getItem(0);
        if (callback.isString()) {
            rho::json::CJSONEntry entry = argv.getItem(i);
            callbackURL = [((NSString*)[CJSConverter convertFromJS:&callback]) retain];
        }
    }
    // check callback param
    if (argc >= (0+2)) {
        rho::json::CJSONEntry callback_param = argv.getItem(0+1);
        if (callback_param.isString()) {
            callbackParam = [((NSString*)[CJSConverter convertFromJS:&callback_param]) retain];
        }
    }
    

    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [RhoConnectClient_cleanObjectNotify_caller cleanObjectNotify_in_thread:[RhoConnectClient_cleanObjectNotify_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [RhoConnectClient_cleanObjectNotify_caller cleanObjectNotify:[RhoConnectClient_cleanObjectNotify_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = "";
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    return resValue;
}


rho::String js_s_RhoConnectClient_cleanObjectNotify(rho::json::CJSONArray& argv, const rho::String& strObjID) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return js_RhoConnectClient_cleanObjectNotify_Obj(argv, singleton);

}







@interface RhoConnectClient_getLastSyncObjectCount_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(RhoConnectClient_getLastSyncObjectCount_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation RhoConnectClient_getLastSyncObjectCount_caller_params

@synthesize params,item,methodResult;

+(RhoConnectClient_getLastSyncObjectCount_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    RhoConnectClient_getLastSyncObjectCount_caller_params* par = [[RhoConnectClient_getLastSyncObjectCount_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface RhoConnectClient_getLastSyncObjectCount_caller : NSObject {

}
+(RhoConnectClient_getLastSyncObjectCount_caller*) getSharedInstance;
+(void) getLastSyncObjectCount:(RhoConnectClient_getLastSyncObjectCount_caller_params*)caller_params;
+(void) getLastSyncObjectCount_in_thread:(RhoConnectClient_getLastSyncObjectCount_caller_params*)caller_params;
+(void) getLastSyncObjectCount_in_UI_thread:(RhoConnectClient_getLastSyncObjectCount_caller_params*)caller_params;

@end

static RhoConnectClient_getLastSyncObjectCount_caller* our_RhoConnectClient_getLastSyncObjectCount_caller = nil;

@implementation RhoConnectClient_getLastSyncObjectCount_caller

+(RhoConnectClient_getLastSyncObjectCount_caller*) getSharedInstance {
    if (our_RhoConnectClient_getLastSyncObjectCount_caller == nil) {
        our_RhoConnectClient_getLastSyncObjectCount_caller = [[RhoConnectClient_getLastSyncObjectCount_caller alloc] init];
    }
    return our_RhoConnectClient_getLastSyncObjectCount_caller;
}

-(void) command_getLastSyncObjectCount:(RhoConnectClient_getLastSyncObjectCount_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem getLastSyncObjectCount:(NSString*)[params objectAtIndex:0] methodResult:methodResult ];
}


+(void) getLastSyncObjectCount:(RhoConnectClient_getLastSyncObjectCount_caller_params*)caller_params {
    [[RhoConnectClient_getLastSyncObjectCount_caller getSharedInstance] command_getLastSyncObjectCount:caller_params];
}

+(void) getLastSyncObjectCount_in_thread:(RhoConnectClient_getLastSyncObjectCount_caller_params*)caller_params {
    [[RhoConnectClient_getLastSyncObjectCount_caller getSharedInstance] performSelectorInBackground:@selector(command_getLastSyncObjectCount:) withObject:caller_params];
}

+(void) getLastSyncObjectCount_in_UI_thread:(RhoConnectClient_getLastSyncObjectCount_caller_params*)caller_params {
    [[RhoConnectClient_getLastSyncObjectCount_caller getSharedInstance] performSelectorOnMainThread:@selector(command_getLastSyncObjectCount:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_RhoConnectClient_getLastSyncObjectCount_Obj(rho::json::CJSONArray& argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[1+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    int argc = argv.getSize();
    
    static RHO_API_PARAM rho_api_params[] = { {RHO_API_STRING, 0, "sourceName", 0, 0 } };

    
    BOOL is_factory_param[] = { NO, NO };

    int i;

    // init
    for (i = 0; i < (1); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    // enumerate params
    for (int i = 0; i < (1); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(1)];
    for (i = 0 ; i < (1); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (1+1)) {
        rho::json::CJSONEntry callback = argv.getItem(1);
        if (callback.isString()) {
            rho::json::CJSONEntry entry = argv.getItem(i);
            callbackURL = [((NSString*)[CJSConverter convertFromJS:&callback]) retain];
        }
    }
    // check callback param
    if (argc >= (1+2)) {
        rho::json::CJSONEntry callback_param = argv.getItem(1+1);
        if (callback_param.isString()) {
            callbackParam = [((NSString*)[CJSConverter convertFromJS:&callback_param]) retain];
        }
    }
    

    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [RhoConnectClient_getLastSyncObjectCount_caller getLastSyncObjectCount_in_thread:[RhoConnectClient_getLastSyncObjectCount_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [RhoConnectClient_getLastSyncObjectCount_caller getLastSyncObjectCount:[RhoConnectClient_getLastSyncObjectCount_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = "";
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    return resValue;
}


rho::String js_s_RhoConnectClient_getLastSyncObjectCount(rho::json::CJSONArray& argv, const rho::String& strObjID) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return js_RhoConnectClient_getLastSyncObjectCount_Obj(argv, singleton);

}







@interface RhoConnectClient_setSourceProperty_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(RhoConnectClient_setSourceProperty_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation RhoConnectClient_setSourceProperty_caller_params

@synthesize params,item,methodResult;

+(RhoConnectClient_setSourceProperty_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    RhoConnectClient_setSourceProperty_caller_params* par = [[RhoConnectClient_setSourceProperty_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface RhoConnectClient_setSourceProperty_caller : NSObject {

}
+(RhoConnectClient_setSourceProperty_caller*) getSharedInstance;
+(void) setSourceProperty:(RhoConnectClient_setSourceProperty_caller_params*)caller_params;
+(void) setSourceProperty_in_thread:(RhoConnectClient_setSourceProperty_caller_params*)caller_params;
+(void) setSourceProperty_in_UI_thread:(RhoConnectClient_setSourceProperty_caller_params*)caller_params;

@end

static RhoConnectClient_setSourceProperty_caller* our_RhoConnectClient_setSourceProperty_caller = nil;

@implementation RhoConnectClient_setSourceProperty_caller

+(RhoConnectClient_setSourceProperty_caller*) getSharedInstance {
    if (our_RhoConnectClient_setSourceProperty_caller == nil) {
        our_RhoConnectClient_setSourceProperty_caller = [[RhoConnectClient_setSourceProperty_caller alloc] init];
    }
    return our_RhoConnectClient_setSourceProperty_caller;
}

-(void) command_setSourceProperty:(RhoConnectClient_setSourceProperty_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem setSourceProperty:(NSString*)[params objectAtIndex:0] propertyName:(NSString*)[params objectAtIndex:1] propertyValue:(NSString*)[params objectAtIndex:2] ];
}


+(void) setSourceProperty:(RhoConnectClient_setSourceProperty_caller_params*)caller_params {
    [[RhoConnectClient_setSourceProperty_caller getSharedInstance] command_setSourceProperty:caller_params];
}

+(void) setSourceProperty_in_thread:(RhoConnectClient_setSourceProperty_caller_params*)caller_params {
    [[RhoConnectClient_setSourceProperty_caller getSharedInstance] performSelectorInBackground:@selector(command_setSourceProperty:) withObject:caller_params];
}

+(void) setSourceProperty_in_UI_thread:(RhoConnectClient_setSourceProperty_caller_params*)caller_params {
    [[RhoConnectClient_setSourceProperty_caller getSharedInstance] performSelectorOnMainThread:@selector(command_setSourceProperty:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_RhoConnectClient_setSourceProperty_Obj(rho::json::CJSONArray& argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[3+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    int argc = argv.getSize();
    
    static RHO_API_PARAM rho_api_params[] = { {RHO_API_STRING, 0, "sourceName", 0, 0 }, {RHO_API_STRING, 0, "propertyName", 0, 0 }, {RHO_API_STRING, 0, "propertyValue", 0, 0 } };

    
    BOOL is_factory_param[] = { NO, NO, NO, NO };

    int i;

    // init
    for (i = 0; i < (3); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    // enumerate params
    for (int i = 0; i < (3); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(3)];
    for (i = 0 ; i < (3); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (3+1)) {
        rho::json::CJSONEntry callback = argv.getItem(3);
        if (callback.isString()) {
            rho::json::CJSONEntry entry = argv.getItem(i);
            callbackURL = [((NSString*)[CJSConverter convertFromJS:&callback]) retain];
        }
    }
    // check callback param
    if (argc >= (3+2)) {
        rho::json::CJSONEntry callback_param = argv.getItem(3+1);
        if (callback_param.isString()) {
            callbackParam = [((NSString*)[CJSConverter convertFromJS:&callback_param]) retain];
        }
    }
    

    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [RhoConnectClient_setSourceProperty_caller setSourceProperty_in_thread:[RhoConnectClient_setSourceProperty_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [RhoConnectClient_setSourceProperty_caller setSourceProperty:[RhoConnectClient_setSourceProperty_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = "";
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    return resValue;
}


rho::String js_s_RhoConnectClient_setSourceProperty(rho::json::CJSONArray& argv, const rho::String& strObjID) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return js_RhoConnectClient_setSourceProperty_Obj(argv, singleton);

}







@interface RhoConnectClient_getSourceProperty_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(RhoConnectClient_getSourceProperty_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation RhoConnectClient_getSourceProperty_caller_params

@synthesize params,item,methodResult;

+(RhoConnectClient_getSourceProperty_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    RhoConnectClient_getSourceProperty_caller_params* par = [[RhoConnectClient_getSourceProperty_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface RhoConnectClient_getSourceProperty_caller : NSObject {

}
+(RhoConnectClient_getSourceProperty_caller*) getSharedInstance;
+(void) getSourceProperty:(RhoConnectClient_getSourceProperty_caller_params*)caller_params;
+(void) getSourceProperty_in_thread:(RhoConnectClient_getSourceProperty_caller_params*)caller_params;
+(void) getSourceProperty_in_UI_thread:(RhoConnectClient_getSourceProperty_caller_params*)caller_params;

@end

static RhoConnectClient_getSourceProperty_caller* our_RhoConnectClient_getSourceProperty_caller = nil;

@implementation RhoConnectClient_getSourceProperty_caller

+(RhoConnectClient_getSourceProperty_caller*) getSharedInstance {
    if (our_RhoConnectClient_getSourceProperty_caller == nil) {
        our_RhoConnectClient_getSourceProperty_caller = [[RhoConnectClient_getSourceProperty_caller alloc] init];
    }
    return our_RhoConnectClient_getSourceProperty_caller;
}

-(void) command_getSourceProperty:(RhoConnectClient_getSourceProperty_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem getSourceProperty:(NSString*)[params objectAtIndex:0] propertyName:(NSString*)[params objectAtIndex:1] methodResult:methodResult ];
}


+(void) getSourceProperty:(RhoConnectClient_getSourceProperty_caller_params*)caller_params {
    [[RhoConnectClient_getSourceProperty_caller getSharedInstance] command_getSourceProperty:caller_params];
}

+(void) getSourceProperty_in_thread:(RhoConnectClient_getSourceProperty_caller_params*)caller_params {
    [[RhoConnectClient_getSourceProperty_caller getSharedInstance] performSelectorInBackground:@selector(command_getSourceProperty:) withObject:caller_params];
}

+(void) getSourceProperty_in_UI_thread:(RhoConnectClient_getSourceProperty_caller_params*)caller_params {
    [[RhoConnectClient_getSourceProperty_caller getSharedInstance] performSelectorOnMainThread:@selector(command_getSourceProperty:) withObject:caller_params waitUntilDone:NO];
}


@end


rho::String js_RhoConnectClient_getSourceProperty_Obj(rho::json::CJSONArray& argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[2+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    int argc = argv.getSize();
    
    static RHO_API_PARAM rho_api_params[] = { {RHO_API_STRING, 0, "sourceName", 0, 0 }, {RHO_API_STRING, 0, "propertyName", 0, 0 } };

    
    BOOL is_factory_param[] = { NO, NO, NO };

    int i;

    // init
    for (i = 0; i < (2); i++) {
        params[i] = [CJSConverter getObjectiveCNULL];
    }

    // enumerate params
    for (int i = 0; i < (2); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByJSObject(argv.getItem(i).getString());
            }
            else {
                rho::json::CJSONEntry entry = argv.getItem(i);
                params[i] = [[CJSConverter convertFromJS:&entry rho_api_param:&(rho_api_params[i])] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(2)];
    for (i = 0 ; i < (2); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (2+1)) {
        rho::json::CJSONEntry callback = argv.getItem(2);
        if (callback.isString()) {
            rho::json::CJSONEntry entry = argv.getItem(i);
            callbackURL = [((NSString*)[CJSConverter convertFromJS:&callback]) retain];
        }
    }
    // check callback param
    if (argc >= (2+2)) {
        rho::json::CJSONEntry callback_param = argv.getItem(2+1);
        if (callback_param.isString()) {
            callbackParam = [((NSString*)[CJSConverter convertFromJS:&callback_param]) retain];
        }
    }
    

    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setJSCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [RhoConnectClient_getSourceProperty_caller getSourceProperty_in_thread:[RhoConnectClient_getSourceProperty_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [RhoConnectClient_getSourceProperty_caller getSourceProperty:[RhoConnectClient_getSourceProperty_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    rho::String resValue = "";
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [[methodResult toJSON] UTF8String];
    }
    return resValue;
}


rho::String js_s_RhoConnectClient_getSourceProperty(rho::json::CJSONArray& argv, const rho::String& strObjID) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return js_RhoConnectClient_getSourceProperty_Obj(argv, singleton);

}









