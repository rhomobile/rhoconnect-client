#import "IRhoConnectClient.h"
//#import "api_generator/common/ruby_helpers.h"

#import "ruby/ext/rho/rhoruby.h"
#import "api_generator/iphone/CMethodResult.h"
#import "api_generator/iphone/CRubyConverter.h"

extern VALUE getRuby_RhoConnectClient_Module();



@interface RhoConnectClient_RubyValueFactory : NSObject<IMethodResult_RubyObjectFactory> {
}

- (VALUE) makeRubyValue:(NSObject*)obj;
+ (RhoConnectClient_RubyValueFactory*) getSharedInstance;

@end

static RhoConnectClient_RubyValueFactory* our_RhoConnectClient_RubyValueFactory = nil;

@implementation RhoConnectClient_RubyValueFactory

- (VALUE) makeRubyValue:(NSObject*)obj {
    VALUE v = rho_ruby_get_NIL();
    if ([obj isKindOfClass:[NSString class]]) {
        // single objects id
        NSString* strRes = (NSString*)obj;
        v = rho_ruby_create_object_with_id( getRuby_RhoConnectClient_Module(), [strRes UTF8String] );
    }
    else if ([obj isKindOfClass:[NSArray class]]) {
        // list of IDs
        v = rho_ruby_create_array();
        NSArray* arrRes = (NSArray*)obj;
        int i;
        for (i = 0; i < [arrRes count]; i++) {
            NSString* strItem = (NSString*)[arrRes objectAtIndex:i];
            VALUE vItem = rho_ruby_create_object_with_id( getRuby_RhoConnectClient_Module(), [strItem UTF8String] );
            rho_ruby_add_to_array(v, vItem);
        }
    }
    return v;
}

+ (RhoConnectClient_RubyValueFactory*) getSharedInstance {
    if (our_RhoConnectClient_RubyValueFactory == nil) {
        our_RhoConnectClient_RubyValueFactory = [[RhoConnectClient_RubyValueFactory alloc] init];
    }
    return our_RhoConnectClient_RubyValueFactory;
}

@end


id<IRhoConnectClient> RhoConnectClient_makeInstanceByRubyObject(VALUE obj) {
    const char* szID = rho_ruby_get_object_id( obj );
    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    return [factory getRhoConnectClientByID:[NSString stringWithUTF8String:szID]];
}









@interface rb_RhoConnectClient_getUserName_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(rb_RhoConnectClient_getUserName_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_RhoConnectClient_getUserName_caller_params

@synthesize params,item,methodResult;

+(rb_RhoConnectClient_getUserName_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_RhoConnectClient_getUserName_caller_params* par = [[rb_RhoConnectClient_getUserName_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface rb_RhoConnectClient_getUserName_caller : NSObject {

}
+(rb_RhoConnectClient_getUserName_caller*) getSharedInstance;
+(void) getUserName:(rb_RhoConnectClient_getUserName_caller_params*)caller_params;
+(void) getUserName_in_thread:(rb_RhoConnectClient_getUserName_caller_params*)caller_params;
+(void) getUserName_in_UI_thread:(rb_RhoConnectClient_getUserName_caller_params*)caller_params;

@end

static rb_RhoConnectClient_getUserName_caller* our_RhoConnectClient_getUserName_caller = nil;

@implementation rb_RhoConnectClient_getUserName_caller

+(rb_RhoConnectClient_getUserName_caller*) getSharedInstance {
    if (our_RhoConnectClient_getUserName_caller == nil) {
        our_RhoConnectClient_getUserName_caller = [[rb_RhoConnectClient_getUserName_caller alloc] init];
    }
    return our_RhoConnectClient_getUserName_caller;
}

-(void) command_getUserName:(rb_RhoConnectClient_getUserName_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem getUserName:methodResult ];
}

+(void) getUserName:(rb_RhoConnectClient_getUserName_caller_params*)caller_params {
    [[rb_RhoConnectClient_getUserName_caller getSharedInstance] command_getUserName:caller_params];
}

+(void) getUserName_in_thread:(rb_RhoConnectClient_getUserName_caller_params*)caller_params {
    [[rb_RhoConnectClient_getUserName_caller getSharedInstance] performSelectorInBackground:@selector(command_getUserName:) withObject:caller_params];
}

+(void) getUserName_in_UI_thread:(rb_RhoConnectClient_getUserName_caller_params*)caller_params {
    [[rb_RhoConnectClient_getUserName_caller getSharedInstance] performSelectorOnMainThread:@selector(command_getUserName:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_RhoConnectClient_getUserName_Obj(int argc, VALUE *argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[0+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    
    BOOL is_factory_param[] = { NO };

    int i;

    // init
    for (i = 0; i < (0); i++) {
        params[i] = [NSNull null];
    }

    // enumerate params
    for (int i = 0; i < (0); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(0)];
    for (i = 0 ; i < (0); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (0+1)) {
        VALUE callback = argv[0];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
    }
    // check callback param
    if (argc >= (0+2)) {
        VALUE callback_param = argv[0+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setRubyCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_RhoConnectClient_getUserName_caller getUserName_in_thread:[rb_RhoConnectClient_getUserName_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_RhoConnectClient_getUserName_caller getUserName:[rb_RhoConnectClient_getUserName_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_s_RhoConnectClient_getUserName(int argc, VALUE *argv) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return rb_RhoConnectClient_getUserName_Obj(argc, argv, singleton);

}







@interface rb_RhoConnectClient_getPollInterval_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(rb_RhoConnectClient_getPollInterval_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_RhoConnectClient_getPollInterval_caller_params

@synthesize params,item,methodResult;

+(rb_RhoConnectClient_getPollInterval_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_RhoConnectClient_getPollInterval_caller_params* par = [[rb_RhoConnectClient_getPollInterval_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface rb_RhoConnectClient_getPollInterval_caller : NSObject {

}
+(rb_RhoConnectClient_getPollInterval_caller*) getSharedInstance;
+(void) getPollInterval:(rb_RhoConnectClient_getPollInterval_caller_params*)caller_params;
+(void) getPollInterval_in_thread:(rb_RhoConnectClient_getPollInterval_caller_params*)caller_params;
+(void) getPollInterval_in_UI_thread:(rb_RhoConnectClient_getPollInterval_caller_params*)caller_params;

@end

static rb_RhoConnectClient_getPollInterval_caller* our_RhoConnectClient_getPollInterval_caller = nil;

@implementation rb_RhoConnectClient_getPollInterval_caller

+(rb_RhoConnectClient_getPollInterval_caller*) getSharedInstance {
    if (our_RhoConnectClient_getPollInterval_caller == nil) {
        our_RhoConnectClient_getPollInterval_caller = [[rb_RhoConnectClient_getPollInterval_caller alloc] init];
    }
    return our_RhoConnectClient_getPollInterval_caller;
}

-(void) command_getPollInterval:(rb_RhoConnectClient_getPollInterval_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem getPollInterval:methodResult ];
}

+(void) getPollInterval:(rb_RhoConnectClient_getPollInterval_caller_params*)caller_params {
    [[rb_RhoConnectClient_getPollInterval_caller getSharedInstance] command_getPollInterval:caller_params];
}

+(void) getPollInterval_in_thread:(rb_RhoConnectClient_getPollInterval_caller_params*)caller_params {
    [[rb_RhoConnectClient_getPollInterval_caller getSharedInstance] performSelectorInBackground:@selector(command_getPollInterval:) withObject:caller_params];
}

+(void) getPollInterval_in_UI_thread:(rb_RhoConnectClient_getPollInterval_caller_params*)caller_params {
    [[rb_RhoConnectClient_getPollInterval_caller getSharedInstance] performSelectorOnMainThread:@selector(command_getPollInterval:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_RhoConnectClient_getPollInterval_Obj(int argc, VALUE *argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[0+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    
    BOOL is_factory_param[] = { NO };

    int i;

    // init
    for (i = 0; i < (0); i++) {
        params[i] = [NSNull null];
    }

    // enumerate params
    for (int i = 0; i < (0); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(0)];
    for (i = 0 ; i < (0); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (0+1)) {
        VALUE callback = argv[0];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
    }
    // check callback param
    if (argc >= (0+2)) {
        VALUE callback_param = argv[0+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setRubyCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_RhoConnectClient_getPollInterval_caller getPollInterval_in_thread:[rb_RhoConnectClient_getPollInterval_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_RhoConnectClient_getPollInterval_caller getPollInterval:[rb_RhoConnectClient_getPollInterval_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_s_RhoConnectClient_getPollInterval(int argc, VALUE *argv) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return rb_RhoConnectClient_getPollInterval_Obj(argc, argv, singleton);

}







@interface rb_RhoConnectClient_setPollInterval_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(rb_RhoConnectClient_setPollInterval_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_RhoConnectClient_setPollInterval_caller_params

@synthesize params,item,methodResult;

+(rb_RhoConnectClient_setPollInterval_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_RhoConnectClient_setPollInterval_caller_params* par = [[rb_RhoConnectClient_setPollInterval_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface rb_RhoConnectClient_setPollInterval_caller : NSObject {

}
+(rb_RhoConnectClient_setPollInterval_caller*) getSharedInstance;
+(void) setPollInterval:(rb_RhoConnectClient_setPollInterval_caller_params*)caller_params;
+(void) setPollInterval_in_thread:(rb_RhoConnectClient_setPollInterval_caller_params*)caller_params;
+(void) setPollInterval_in_UI_thread:(rb_RhoConnectClient_setPollInterval_caller_params*)caller_params;

@end

static rb_RhoConnectClient_setPollInterval_caller* our_RhoConnectClient_setPollInterval_caller = nil;

@implementation rb_RhoConnectClient_setPollInterval_caller

+(rb_RhoConnectClient_setPollInterval_caller*) getSharedInstance {
    if (our_RhoConnectClient_setPollInterval_caller == nil) {
        our_RhoConnectClient_setPollInterval_caller = [[rb_RhoConnectClient_setPollInterval_caller alloc] init];
    }
    return our_RhoConnectClient_setPollInterval_caller;
}

-(void) command_setPollInterval:(rb_RhoConnectClient_setPollInterval_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem setPollInterval:(int)[((NSNumber*)[params objectAtIndex:0]) intValue] ];
}

+(void) setPollInterval:(rb_RhoConnectClient_setPollInterval_caller_params*)caller_params {
    [[rb_RhoConnectClient_setPollInterval_caller getSharedInstance] command_setPollInterval:caller_params];
}

+(void) setPollInterval_in_thread:(rb_RhoConnectClient_setPollInterval_caller_params*)caller_params {
    [[rb_RhoConnectClient_setPollInterval_caller getSharedInstance] performSelectorInBackground:@selector(command_setPollInterval:) withObject:caller_params];
}

+(void) setPollInterval_in_UI_thread:(rb_RhoConnectClient_setPollInterval_caller_params*)caller_params {
    [[rb_RhoConnectClient_setPollInterval_caller getSharedInstance] performSelectorOnMainThread:@selector(command_setPollInterval:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_RhoConnectClient_setPollInterval_Obj(int argc, VALUE *argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[1+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    
    BOOL is_factory_param[] = { NO, NO };

    int i;

    // init
    for (i = 0; i < (1); i++) {
        params[i] = [NSNull null];
    }

    // enumerate params
    for (int i = 0; i < (1); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(1)];
    for (i = 0 ; i < (1); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (1+1)) {
        VALUE callback = argv[1];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
    }
    // check callback param
    if (argc >= (1+2)) {
        VALUE callback_param = argv[1+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setRubyCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_RhoConnectClient_setPollInterval_caller setPollInterval_in_thread:[rb_RhoConnectClient_setPollInterval_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_RhoConnectClient_setPollInterval_caller setPollInterval:[rb_RhoConnectClient_setPollInterval_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_s_RhoConnectClient_setPollInterval(int argc, VALUE *argv) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return rb_RhoConnectClient_setPollInterval_Obj(argc, argv, singleton);

}







@interface rb_RhoConnectClient_getSyncServer_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(rb_RhoConnectClient_getSyncServer_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_RhoConnectClient_getSyncServer_caller_params

@synthesize params,item,methodResult;

+(rb_RhoConnectClient_getSyncServer_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_RhoConnectClient_getSyncServer_caller_params* par = [[rb_RhoConnectClient_getSyncServer_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface rb_RhoConnectClient_getSyncServer_caller : NSObject {

}
+(rb_RhoConnectClient_getSyncServer_caller*) getSharedInstance;
+(void) getSyncServer:(rb_RhoConnectClient_getSyncServer_caller_params*)caller_params;
+(void) getSyncServer_in_thread:(rb_RhoConnectClient_getSyncServer_caller_params*)caller_params;
+(void) getSyncServer_in_UI_thread:(rb_RhoConnectClient_getSyncServer_caller_params*)caller_params;

@end

static rb_RhoConnectClient_getSyncServer_caller* our_RhoConnectClient_getSyncServer_caller = nil;

@implementation rb_RhoConnectClient_getSyncServer_caller

+(rb_RhoConnectClient_getSyncServer_caller*) getSharedInstance {
    if (our_RhoConnectClient_getSyncServer_caller == nil) {
        our_RhoConnectClient_getSyncServer_caller = [[rb_RhoConnectClient_getSyncServer_caller alloc] init];
    }
    return our_RhoConnectClient_getSyncServer_caller;
}

-(void) command_getSyncServer:(rb_RhoConnectClient_getSyncServer_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem getSyncServer:methodResult ];
}

+(void) getSyncServer:(rb_RhoConnectClient_getSyncServer_caller_params*)caller_params {
    [[rb_RhoConnectClient_getSyncServer_caller getSharedInstance] command_getSyncServer:caller_params];
}

+(void) getSyncServer_in_thread:(rb_RhoConnectClient_getSyncServer_caller_params*)caller_params {
    [[rb_RhoConnectClient_getSyncServer_caller getSharedInstance] performSelectorInBackground:@selector(command_getSyncServer:) withObject:caller_params];
}

+(void) getSyncServer_in_UI_thread:(rb_RhoConnectClient_getSyncServer_caller_params*)caller_params {
    [[rb_RhoConnectClient_getSyncServer_caller getSharedInstance] performSelectorOnMainThread:@selector(command_getSyncServer:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_RhoConnectClient_getSyncServer_Obj(int argc, VALUE *argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[0+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    
    BOOL is_factory_param[] = { NO };

    int i;

    // init
    for (i = 0; i < (0); i++) {
        params[i] = [NSNull null];
    }

    // enumerate params
    for (int i = 0; i < (0); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(0)];
    for (i = 0 ; i < (0); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (0+1)) {
        VALUE callback = argv[0];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
    }
    // check callback param
    if (argc >= (0+2)) {
        VALUE callback_param = argv[0+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setRubyCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_RhoConnectClient_getSyncServer_caller getSyncServer_in_thread:[rb_RhoConnectClient_getSyncServer_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_RhoConnectClient_getSyncServer_caller getSyncServer:[rb_RhoConnectClient_getSyncServer_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_s_RhoConnectClient_getSyncServer(int argc, VALUE *argv) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return rb_RhoConnectClient_getSyncServer_Obj(argc, argv, singleton);

}







@interface rb_RhoConnectClient_setSyncServer_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(rb_RhoConnectClient_setSyncServer_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_RhoConnectClient_setSyncServer_caller_params

@synthesize params,item,methodResult;

+(rb_RhoConnectClient_setSyncServer_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_RhoConnectClient_setSyncServer_caller_params* par = [[rb_RhoConnectClient_setSyncServer_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface rb_RhoConnectClient_setSyncServer_caller : NSObject {

}
+(rb_RhoConnectClient_setSyncServer_caller*) getSharedInstance;
+(void) setSyncServer:(rb_RhoConnectClient_setSyncServer_caller_params*)caller_params;
+(void) setSyncServer_in_thread:(rb_RhoConnectClient_setSyncServer_caller_params*)caller_params;
+(void) setSyncServer_in_UI_thread:(rb_RhoConnectClient_setSyncServer_caller_params*)caller_params;

@end

static rb_RhoConnectClient_setSyncServer_caller* our_RhoConnectClient_setSyncServer_caller = nil;

@implementation rb_RhoConnectClient_setSyncServer_caller

+(rb_RhoConnectClient_setSyncServer_caller*) getSharedInstance {
    if (our_RhoConnectClient_setSyncServer_caller == nil) {
        our_RhoConnectClient_setSyncServer_caller = [[rb_RhoConnectClient_setSyncServer_caller alloc] init];
    }
    return our_RhoConnectClient_setSyncServer_caller;
}

-(void) command_setSyncServer:(rb_RhoConnectClient_setSyncServer_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem setSyncServer:(NSString*)[params objectAtIndex:0] ];
}

+(void) setSyncServer:(rb_RhoConnectClient_setSyncServer_caller_params*)caller_params {
    [[rb_RhoConnectClient_setSyncServer_caller getSharedInstance] command_setSyncServer:caller_params];
}

+(void) setSyncServer_in_thread:(rb_RhoConnectClient_setSyncServer_caller_params*)caller_params {
    [[rb_RhoConnectClient_setSyncServer_caller getSharedInstance] performSelectorInBackground:@selector(command_setSyncServer:) withObject:caller_params];
}

+(void) setSyncServer_in_UI_thread:(rb_RhoConnectClient_setSyncServer_caller_params*)caller_params {
    [[rb_RhoConnectClient_setSyncServer_caller getSharedInstance] performSelectorOnMainThread:@selector(command_setSyncServer:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_RhoConnectClient_setSyncServer_Obj(int argc, VALUE *argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[1+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    
    BOOL is_factory_param[] = { NO, NO };

    int i;

    // init
    for (i = 0; i < (1); i++) {
        params[i] = [NSNull null];
    }

    // enumerate params
    for (int i = 0; i < (1); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(1)];
    for (i = 0 ; i < (1); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (1+1)) {
        VALUE callback = argv[1];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
    }
    // check callback param
    if (argc >= (1+2)) {
        VALUE callback_param = argv[1+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setRubyCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_RhoConnectClient_setSyncServer_caller setSyncServer_in_thread:[rb_RhoConnectClient_setSyncServer_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_RhoConnectClient_setSyncServer_caller setSyncServer:[rb_RhoConnectClient_setSyncServer_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_s_RhoConnectClient_setSyncServer(int argc, VALUE *argv) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return rb_RhoConnectClient_setSyncServer_Obj(argc, argv, singleton);

}







@interface rb_RhoConnectClient_getPageSize_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(rb_RhoConnectClient_getPageSize_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_RhoConnectClient_getPageSize_caller_params

@synthesize params,item,methodResult;

+(rb_RhoConnectClient_getPageSize_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_RhoConnectClient_getPageSize_caller_params* par = [[rb_RhoConnectClient_getPageSize_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface rb_RhoConnectClient_getPageSize_caller : NSObject {

}
+(rb_RhoConnectClient_getPageSize_caller*) getSharedInstance;
+(void) getPageSize:(rb_RhoConnectClient_getPageSize_caller_params*)caller_params;
+(void) getPageSize_in_thread:(rb_RhoConnectClient_getPageSize_caller_params*)caller_params;
+(void) getPageSize_in_UI_thread:(rb_RhoConnectClient_getPageSize_caller_params*)caller_params;

@end

static rb_RhoConnectClient_getPageSize_caller* our_RhoConnectClient_getPageSize_caller = nil;

@implementation rb_RhoConnectClient_getPageSize_caller

+(rb_RhoConnectClient_getPageSize_caller*) getSharedInstance {
    if (our_RhoConnectClient_getPageSize_caller == nil) {
        our_RhoConnectClient_getPageSize_caller = [[rb_RhoConnectClient_getPageSize_caller alloc] init];
    }
    return our_RhoConnectClient_getPageSize_caller;
}

-(void) command_getPageSize:(rb_RhoConnectClient_getPageSize_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem getPageSize:methodResult ];
}

+(void) getPageSize:(rb_RhoConnectClient_getPageSize_caller_params*)caller_params {
    [[rb_RhoConnectClient_getPageSize_caller getSharedInstance] command_getPageSize:caller_params];
}

+(void) getPageSize_in_thread:(rb_RhoConnectClient_getPageSize_caller_params*)caller_params {
    [[rb_RhoConnectClient_getPageSize_caller getSharedInstance] performSelectorInBackground:@selector(command_getPageSize:) withObject:caller_params];
}

+(void) getPageSize_in_UI_thread:(rb_RhoConnectClient_getPageSize_caller_params*)caller_params {
    [[rb_RhoConnectClient_getPageSize_caller getSharedInstance] performSelectorOnMainThread:@selector(command_getPageSize:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_RhoConnectClient_getPageSize_Obj(int argc, VALUE *argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[0+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    
    BOOL is_factory_param[] = { NO };

    int i;

    // init
    for (i = 0; i < (0); i++) {
        params[i] = [NSNull null];
    }

    // enumerate params
    for (int i = 0; i < (0); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(0)];
    for (i = 0 ; i < (0); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (0+1)) {
        VALUE callback = argv[0];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
    }
    // check callback param
    if (argc >= (0+2)) {
        VALUE callback_param = argv[0+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setRubyCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_RhoConnectClient_getPageSize_caller getPageSize_in_thread:[rb_RhoConnectClient_getPageSize_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_RhoConnectClient_getPageSize_caller getPageSize:[rb_RhoConnectClient_getPageSize_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_s_RhoConnectClient_getPageSize(int argc, VALUE *argv) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return rb_RhoConnectClient_getPageSize_Obj(argc, argv, singleton);

}







@interface rb_RhoConnectClient_setPageSize_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(rb_RhoConnectClient_setPageSize_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_RhoConnectClient_setPageSize_caller_params

@synthesize params,item,methodResult;

+(rb_RhoConnectClient_setPageSize_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_RhoConnectClient_setPageSize_caller_params* par = [[rb_RhoConnectClient_setPageSize_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface rb_RhoConnectClient_setPageSize_caller : NSObject {

}
+(rb_RhoConnectClient_setPageSize_caller*) getSharedInstance;
+(void) setPageSize:(rb_RhoConnectClient_setPageSize_caller_params*)caller_params;
+(void) setPageSize_in_thread:(rb_RhoConnectClient_setPageSize_caller_params*)caller_params;
+(void) setPageSize_in_UI_thread:(rb_RhoConnectClient_setPageSize_caller_params*)caller_params;

@end

static rb_RhoConnectClient_setPageSize_caller* our_RhoConnectClient_setPageSize_caller = nil;

@implementation rb_RhoConnectClient_setPageSize_caller

+(rb_RhoConnectClient_setPageSize_caller*) getSharedInstance {
    if (our_RhoConnectClient_setPageSize_caller == nil) {
        our_RhoConnectClient_setPageSize_caller = [[rb_RhoConnectClient_setPageSize_caller alloc] init];
    }
    return our_RhoConnectClient_setPageSize_caller;
}

-(void) command_setPageSize:(rb_RhoConnectClient_setPageSize_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem setPageSize:(int)[((NSNumber*)[params objectAtIndex:0]) intValue] ];
}

+(void) setPageSize:(rb_RhoConnectClient_setPageSize_caller_params*)caller_params {
    [[rb_RhoConnectClient_setPageSize_caller getSharedInstance] command_setPageSize:caller_params];
}

+(void) setPageSize_in_thread:(rb_RhoConnectClient_setPageSize_caller_params*)caller_params {
    [[rb_RhoConnectClient_setPageSize_caller getSharedInstance] performSelectorInBackground:@selector(command_setPageSize:) withObject:caller_params];
}

+(void) setPageSize_in_UI_thread:(rb_RhoConnectClient_setPageSize_caller_params*)caller_params {
    [[rb_RhoConnectClient_setPageSize_caller getSharedInstance] performSelectorOnMainThread:@selector(command_setPageSize:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_RhoConnectClient_setPageSize_Obj(int argc, VALUE *argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[1+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    
    BOOL is_factory_param[] = { NO, NO };

    int i;

    // init
    for (i = 0; i < (1); i++) {
        params[i] = [NSNull null];
    }

    // enumerate params
    for (int i = 0; i < (1); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(1)];
    for (i = 0 ; i < (1); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (1+1)) {
        VALUE callback = argv[1];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
    }
    // check callback param
    if (argc >= (1+2)) {
        VALUE callback_param = argv[1+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setRubyCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_RhoConnectClient_setPageSize_caller setPageSize_in_thread:[rb_RhoConnectClient_setPageSize_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_RhoConnectClient_setPageSize_caller setPageSize:[rb_RhoConnectClient_setPageSize_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_s_RhoConnectClient_setPageSize(int argc, VALUE *argv) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return rb_RhoConnectClient_setPageSize_Obj(argc, argv, singleton);

}







@interface rb_RhoConnectClient_getThreadedMode_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(rb_RhoConnectClient_getThreadedMode_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_RhoConnectClient_getThreadedMode_caller_params

@synthesize params,item,methodResult;

+(rb_RhoConnectClient_getThreadedMode_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_RhoConnectClient_getThreadedMode_caller_params* par = [[rb_RhoConnectClient_getThreadedMode_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface rb_RhoConnectClient_getThreadedMode_caller : NSObject {

}
+(rb_RhoConnectClient_getThreadedMode_caller*) getSharedInstance;
+(void) getThreadedMode:(rb_RhoConnectClient_getThreadedMode_caller_params*)caller_params;
+(void) getThreadedMode_in_thread:(rb_RhoConnectClient_getThreadedMode_caller_params*)caller_params;
+(void) getThreadedMode_in_UI_thread:(rb_RhoConnectClient_getThreadedMode_caller_params*)caller_params;

@end

static rb_RhoConnectClient_getThreadedMode_caller* our_RhoConnectClient_getThreadedMode_caller = nil;

@implementation rb_RhoConnectClient_getThreadedMode_caller

+(rb_RhoConnectClient_getThreadedMode_caller*) getSharedInstance {
    if (our_RhoConnectClient_getThreadedMode_caller == nil) {
        our_RhoConnectClient_getThreadedMode_caller = [[rb_RhoConnectClient_getThreadedMode_caller alloc] init];
    }
    return our_RhoConnectClient_getThreadedMode_caller;
}

-(void) command_getThreadedMode:(rb_RhoConnectClient_getThreadedMode_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem getThreadedMode:methodResult ];
}

+(void) getThreadedMode:(rb_RhoConnectClient_getThreadedMode_caller_params*)caller_params {
    [[rb_RhoConnectClient_getThreadedMode_caller getSharedInstance] command_getThreadedMode:caller_params];
}

+(void) getThreadedMode_in_thread:(rb_RhoConnectClient_getThreadedMode_caller_params*)caller_params {
    [[rb_RhoConnectClient_getThreadedMode_caller getSharedInstance] performSelectorInBackground:@selector(command_getThreadedMode:) withObject:caller_params];
}

+(void) getThreadedMode_in_UI_thread:(rb_RhoConnectClient_getThreadedMode_caller_params*)caller_params {
    [[rb_RhoConnectClient_getThreadedMode_caller getSharedInstance] performSelectorOnMainThread:@selector(command_getThreadedMode:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_RhoConnectClient_getThreadedMode_Obj(int argc, VALUE *argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[0+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    
    BOOL is_factory_param[] = { NO };

    int i;

    // init
    for (i = 0; i < (0); i++) {
        params[i] = [NSNull null];
    }

    // enumerate params
    for (int i = 0; i < (0); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(0)];
    for (i = 0 ; i < (0); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (0+1)) {
        VALUE callback = argv[0];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
    }
    // check callback param
    if (argc >= (0+2)) {
        VALUE callback_param = argv[0+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setRubyCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_RhoConnectClient_getThreadedMode_caller getThreadedMode_in_thread:[rb_RhoConnectClient_getThreadedMode_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_RhoConnectClient_getThreadedMode_caller getThreadedMode:[rb_RhoConnectClient_getThreadedMode_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_s_RhoConnectClient_getThreadedMode(int argc, VALUE *argv) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return rb_RhoConnectClient_getThreadedMode_Obj(argc, argv, singleton);

}







@interface rb_RhoConnectClient_setThreadedMode_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(rb_RhoConnectClient_setThreadedMode_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_RhoConnectClient_setThreadedMode_caller_params

@synthesize params,item,methodResult;

+(rb_RhoConnectClient_setThreadedMode_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_RhoConnectClient_setThreadedMode_caller_params* par = [[rb_RhoConnectClient_setThreadedMode_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface rb_RhoConnectClient_setThreadedMode_caller : NSObject {

}
+(rb_RhoConnectClient_setThreadedMode_caller*) getSharedInstance;
+(void) setThreadedMode:(rb_RhoConnectClient_setThreadedMode_caller_params*)caller_params;
+(void) setThreadedMode_in_thread:(rb_RhoConnectClient_setThreadedMode_caller_params*)caller_params;
+(void) setThreadedMode_in_UI_thread:(rb_RhoConnectClient_setThreadedMode_caller_params*)caller_params;

@end

static rb_RhoConnectClient_setThreadedMode_caller* our_RhoConnectClient_setThreadedMode_caller = nil;

@implementation rb_RhoConnectClient_setThreadedMode_caller

+(rb_RhoConnectClient_setThreadedMode_caller*) getSharedInstance {
    if (our_RhoConnectClient_setThreadedMode_caller == nil) {
        our_RhoConnectClient_setThreadedMode_caller = [[rb_RhoConnectClient_setThreadedMode_caller alloc] init];
    }
    return our_RhoConnectClient_setThreadedMode_caller;
}

-(void) command_setThreadedMode:(rb_RhoConnectClient_setThreadedMode_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem setThreadedMode:(BOOL)[((NSNumber*)[params objectAtIndex:0]) boolValue] ];
}

+(void) setThreadedMode:(rb_RhoConnectClient_setThreadedMode_caller_params*)caller_params {
    [[rb_RhoConnectClient_setThreadedMode_caller getSharedInstance] command_setThreadedMode:caller_params];
}

+(void) setThreadedMode_in_thread:(rb_RhoConnectClient_setThreadedMode_caller_params*)caller_params {
    [[rb_RhoConnectClient_setThreadedMode_caller getSharedInstance] performSelectorInBackground:@selector(command_setThreadedMode:) withObject:caller_params];
}

+(void) setThreadedMode_in_UI_thread:(rb_RhoConnectClient_setThreadedMode_caller_params*)caller_params {
    [[rb_RhoConnectClient_setThreadedMode_caller getSharedInstance] performSelectorOnMainThread:@selector(command_setThreadedMode:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_RhoConnectClient_setThreadedMode_Obj(int argc, VALUE *argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[1+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    
    BOOL is_factory_param[] = { NO, NO };

    int i;

    // init
    for (i = 0; i < (1); i++) {
        params[i] = [NSNull null];
    }

    // enumerate params
    for (int i = 0; i < (1); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(1)];
    for (i = 0 ; i < (1); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (1+1)) {
        VALUE callback = argv[1];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
    }
    // check callback param
    if (argc >= (1+2)) {
        VALUE callback_param = argv[1+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setRubyCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_RhoConnectClient_setThreadedMode_caller setThreadedMode_in_thread:[rb_RhoConnectClient_setThreadedMode_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_RhoConnectClient_setThreadedMode_caller setThreadedMode:[rb_RhoConnectClient_setThreadedMode_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_s_RhoConnectClient_setThreadedMode(int argc, VALUE *argv) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return rb_RhoConnectClient_setThreadedMode_Obj(argc, argv, singleton);

}







@interface rb_RhoConnectClient_getShowStatusPopup_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(rb_RhoConnectClient_getShowStatusPopup_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_RhoConnectClient_getShowStatusPopup_caller_params

@synthesize params,item,methodResult;

+(rb_RhoConnectClient_getShowStatusPopup_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_RhoConnectClient_getShowStatusPopup_caller_params* par = [[rb_RhoConnectClient_getShowStatusPopup_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface rb_RhoConnectClient_getShowStatusPopup_caller : NSObject {

}
+(rb_RhoConnectClient_getShowStatusPopup_caller*) getSharedInstance;
+(void) getShowStatusPopup:(rb_RhoConnectClient_getShowStatusPopup_caller_params*)caller_params;
+(void) getShowStatusPopup_in_thread:(rb_RhoConnectClient_getShowStatusPopup_caller_params*)caller_params;
+(void) getShowStatusPopup_in_UI_thread:(rb_RhoConnectClient_getShowStatusPopup_caller_params*)caller_params;

@end

static rb_RhoConnectClient_getShowStatusPopup_caller* our_RhoConnectClient_getShowStatusPopup_caller = nil;

@implementation rb_RhoConnectClient_getShowStatusPopup_caller

+(rb_RhoConnectClient_getShowStatusPopup_caller*) getSharedInstance {
    if (our_RhoConnectClient_getShowStatusPopup_caller == nil) {
        our_RhoConnectClient_getShowStatusPopup_caller = [[rb_RhoConnectClient_getShowStatusPopup_caller alloc] init];
    }
    return our_RhoConnectClient_getShowStatusPopup_caller;
}

-(void) command_getShowStatusPopup:(rb_RhoConnectClient_getShowStatusPopup_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem getShowStatusPopup:methodResult ];
}

+(void) getShowStatusPopup:(rb_RhoConnectClient_getShowStatusPopup_caller_params*)caller_params {
    [[rb_RhoConnectClient_getShowStatusPopup_caller getSharedInstance] command_getShowStatusPopup:caller_params];
}

+(void) getShowStatusPopup_in_thread:(rb_RhoConnectClient_getShowStatusPopup_caller_params*)caller_params {
    [[rb_RhoConnectClient_getShowStatusPopup_caller getSharedInstance] performSelectorInBackground:@selector(command_getShowStatusPopup:) withObject:caller_params];
}

+(void) getShowStatusPopup_in_UI_thread:(rb_RhoConnectClient_getShowStatusPopup_caller_params*)caller_params {
    [[rb_RhoConnectClient_getShowStatusPopup_caller getSharedInstance] performSelectorOnMainThread:@selector(command_getShowStatusPopup:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_RhoConnectClient_getShowStatusPopup_Obj(int argc, VALUE *argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[0+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    
    BOOL is_factory_param[] = { NO };

    int i;

    // init
    for (i = 0; i < (0); i++) {
        params[i] = [NSNull null];
    }

    // enumerate params
    for (int i = 0; i < (0); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(0)];
    for (i = 0 ; i < (0); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (0+1)) {
        VALUE callback = argv[0];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
    }
    // check callback param
    if (argc >= (0+2)) {
        VALUE callback_param = argv[0+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setRubyCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_RhoConnectClient_getShowStatusPopup_caller getShowStatusPopup_in_thread:[rb_RhoConnectClient_getShowStatusPopup_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_RhoConnectClient_getShowStatusPopup_caller getShowStatusPopup:[rb_RhoConnectClient_getShowStatusPopup_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_s_RhoConnectClient_getShowStatusPopup(int argc, VALUE *argv) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return rb_RhoConnectClient_getShowStatusPopup_Obj(argc, argv, singleton);

}







@interface rb_RhoConnectClient_setShowStatusPopup_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(rb_RhoConnectClient_setShowStatusPopup_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_RhoConnectClient_setShowStatusPopup_caller_params

@synthesize params,item,methodResult;

+(rb_RhoConnectClient_setShowStatusPopup_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_RhoConnectClient_setShowStatusPopup_caller_params* par = [[rb_RhoConnectClient_setShowStatusPopup_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface rb_RhoConnectClient_setShowStatusPopup_caller : NSObject {

}
+(rb_RhoConnectClient_setShowStatusPopup_caller*) getSharedInstance;
+(void) setShowStatusPopup:(rb_RhoConnectClient_setShowStatusPopup_caller_params*)caller_params;
+(void) setShowStatusPopup_in_thread:(rb_RhoConnectClient_setShowStatusPopup_caller_params*)caller_params;
+(void) setShowStatusPopup_in_UI_thread:(rb_RhoConnectClient_setShowStatusPopup_caller_params*)caller_params;

@end

static rb_RhoConnectClient_setShowStatusPopup_caller* our_RhoConnectClient_setShowStatusPopup_caller = nil;

@implementation rb_RhoConnectClient_setShowStatusPopup_caller

+(rb_RhoConnectClient_setShowStatusPopup_caller*) getSharedInstance {
    if (our_RhoConnectClient_setShowStatusPopup_caller == nil) {
        our_RhoConnectClient_setShowStatusPopup_caller = [[rb_RhoConnectClient_setShowStatusPopup_caller alloc] init];
    }
    return our_RhoConnectClient_setShowStatusPopup_caller;
}

-(void) command_setShowStatusPopup:(rb_RhoConnectClient_setShowStatusPopup_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem setShowStatusPopup:(BOOL)[((NSNumber*)[params objectAtIndex:0]) boolValue] ];
}

+(void) setShowStatusPopup:(rb_RhoConnectClient_setShowStatusPopup_caller_params*)caller_params {
    [[rb_RhoConnectClient_setShowStatusPopup_caller getSharedInstance] command_setShowStatusPopup:caller_params];
}

+(void) setShowStatusPopup_in_thread:(rb_RhoConnectClient_setShowStatusPopup_caller_params*)caller_params {
    [[rb_RhoConnectClient_setShowStatusPopup_caller getSharedInstance] performSelectorInBackground:@selector(command_setShowStatusPopup:) withObject:caller_params];
}

+(void) setShowStatusPopup_in_UI_thread:(rb_RhoConnectClient_setShowStatusPopup_caller_params*)caller_params {
    [[rb_RhoConnectClient_setShowStatusPopup_caller getSharedInstance] performSelectorOnMainThread:@selector(command_setShowStatusPopup:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_RhoConnectClient_setShowStatusPopup_Obj(int argc, VALUE *argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[1+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    
    BOOL is_factory_param[] = { NO, NO };

    int i;

    // init
    for (i = 0; i < (1); i++) {
        params[i] = [NSNull null];
    }

    // enumerate params
    for (int i = 0; i < (1); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(1)];
    for (i = 0 ; i < (1); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (1+1)) {
        VALUE callback = argv[1];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
    }
    // check callback param
    if (argc >= (1+2)) {
        VALUE callback_param = argv[1+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setRubyCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_RhoConnectClient_setShowStatusPopup_caller setShowStatusPopup_in_thread:[rb_RhoConnectClient_setShowStatusPopup_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_RhoConnectClient_setShowStatusPopup_caller setShowStatusPopup:[rb_RhoConnectClient_setShowStatusPopup_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_s_RhoConnectClient_setShowStatusPopup(int argc, VALUE *argv) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return rb_RhoConnectClient_setShowStatusPopup_Obj(argc, argv, singleton);

}







@interface rb_RhoConnectClient_getSslVerifyPeer_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(rb_RhoConnectClient_getSslVerifyPeer_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_RhoConnectClient_getSslVerifyPeer_caller_params

@synthesize params,item,methodResult;

+(rb_RhoConnectClient_getSslVerifyPeer_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_RhoConnectClient_getSslVerifyPeer_caller_params* par = [[rb_RhoConnectClient_getSslVerifyPeer_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface rb_RhoConnectClient_getSslVerifyPeer_caller : NSObject {

}
+(rb_RhoConnectClient_getSslVerifyPeer_caller*) getSharedInstance;
+(void) getSslVerifyPeer:(rb_RhoConnectClient_getSslVerifyPeer_caller_params*)caller_params;
+(void) getSslVerifyPeer_in_thread:(rb_RhoConnectClient_getSslVerifyPeer_caller_params*)caller_params;
+(void) getSslVerifyPeer_in_UI_thread:(rb_RhoConnectClient_getSslVerifyPeer_caller_params*)caller_params;

@end

static rb_RhoConnectClient_getSslVerifyPeer_caller* our_RhoConnectClient_getSslVerifyPeer_caller = nil;

@implementation rb_RhoConnectClient_getSslVerifyPeer_caller

+(rb_RhoConnectClient_getSslVerifyPeer_caller*) getSharedInstance {
    if (our_RhoConnectClient_getSslVerifyPeer_caller == nil) {
        our_RhoConnectClient_getSslVerifyPeer_caller = [[rb_RhoConnectClient_getSslVerifyPeer_caller alloc] init];
    }
    return our_RhoConnectClient_getSslVerifyPeer_caller;
}

-(void) command_getSslVerifyPeer:(rb_RhoConnectClient_getSslVerifyPeer_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem getSslVerifyPeer:methodResult ];
}

+(void) getSslVerifyPeer:(rb_RhoConnectClient_getSslVerifyPeer_caller_params*)caller_params {
    [[rb_RhoConnectClient_getSslVerifyPeer_caller getSharedInstance] command_getSslVerifyPeer:caller_params];
}

+(void) getSslVerifyPeer_in_thread:(rb_RhoConnectClient_getSslVerifyPeer_caller_params*)caller_params {
    [[rb_RhoConnectClient_getSslVerifyPeer_caller getSharedInstance] performSelectorInBackground:@selector(command_getSslVerifyPeer:) withObject:caller_params];
}

+(void) getSslVerifyPeer_in_UI_thread:(rb_RhoConnectClient_getSslVerifyPeer_caller_params*)caller_params {
    [[rb_RhoConnectClient_getSslVerifyPeer_caller getSharedInstance] performSelectorOnMainThread:@selector(command_getSslVerifyPeer:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_RhoConnectClient_getSslVerifyPeer_Obj(int argc, VALUE *argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[0+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    
    BOOL is_factory_param[] = { NO };

    int i;

    // init
    for (i = 0; i < (0); i++) {
        params[i] = [NSNull null];
    }

    // enumerate params
    for (int i = 0; i < (0); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(0)];
    for (i = 0 ; i < (0); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (0+1)) {
        VALUE callback = argv[0];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
    }
    // check callback param
    if (argc >= (0+2)) {
        VALUE callback_param = argv[0+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setRubyCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_RhoConnectClient_getSslVerifyPeer_caller getSslVerifyPeer_in_thread:[rb_RhoConnectClient_getSslVerifyPeer_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_RhoConnectClient_getSslVerifyPeer_caller getSslVerifyPeer:[rb_RhoConnectClient_getSslVerifyPeer_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_s_RhoConnectClient_getSslVerifyPeer(int argc, VALUE *argv) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return rb_RhoConnectClient_getSslVerifyPeer_Obj(argc, argv, singleton);

}







@interface rb_RhoConnectClient_setSslVerifyPeer_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(rb_RhoConnectClient_setSslVerifyPeer_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_RhoConnectClient_setSslVerifyPeer_caller_params

@synthesize params,item,methodResult;

+(rb_RhoConnectClient_setSslVerifyPeer_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_RhoConnectClient_setSslVerifyPeer_caller_params* par = [[rb_RhoConnectClient_setSslVerifyPeer_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface rb_RhoConnectClient_setSslVerifyPeer_caller : NSObject {

}
+(rb_RhoConnectClient_setSslVerifyPeer_caller*) getSharedInstance;
+(void) setSslVerifyPeer:(rb_RhoConnectClient_setSslVerifyPeer_caller_params*)caller_params;
+(void) setSslVerifyPeer_in_thread:(rb_RhoConnectClient_setSslVerifyPeer_caller_params*)caller_params;
+(void) setSslVerifyPeer_in_UI_thread:(rb_RhoConnectClient_setSslVerifyPeer_caller_params*)caller_params;

@end

static rb_RhoConnectClient_setSslVerifyPeer_caller* our_RhoConnectClient_setSslVerifyPeer_caller = nil;

@implementation rb_RhoConnectClient_setSslVerifyPeer_caller

+(rb_RhoConnectClient_setSslVerifyPeer_caller*) getSharedInstance {
    if (our_RhoConnectClient_setSslVerifyPeer_caller == nil) {
        our_RhoConnectClient_setSslVerifyPeer_caller = [[rb_RhoConnectClient_setSslVerifyPeer_caller alloc] init];
    }
    return our_RhoConnectClient_setSslVerifyPeer_caller;
}

-(void) command_setSslVerifyPeer:(rb_RhoConnectClient_setSslVerifyPeer_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem setSslVerifyPeer:(BOOL)[((NSNumber*)[params objectAtIndex:0]) boolValue] ];
}

+(void) setSslVerifyPeer:(rb_RhoConnectClient_setSslVerifyPeer_caller_params*)caller_params {
    [[rb_RhoConnectClient_setSslVerifyPeer_caller getSharedInstance] command_setSslVerifyPeer:caller_params];
}

+(void) setSslVerifyPeer_in_thread:(rb_RhoConnectClient_setSslVerifyPeer_caller_params*)caller_params {
    [[rb_RhoConnectClient_setSslVerifyPeer_caller getSharedInstance] performSelectorInBackground:@selector(command_setSslVerifyPeer:) withObject:caller_params];
}

+(void) setSslVerifyPeer_in_UI_thread:(rb_RhoConnectClient_setSslVerifyPeer_caller_params*)caller_params {
    [[rb_RhoConnectClient_setSslVerifyPeer_caller getSharedInstance] performSelectorOnMainThread:@selector(command_setSslVerifyPeer:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_RhoConnectClient_setSslVerifyPeer_Obj(int argc, VALUE *argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[1+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    
    BOOL is_factory_param[] = { NO, NO };

    int i;

    // init
    for (i = 0; i < (1); i++) {
        params[i] = [NSNull null];
    }

    // enumerate params
    for (int i = 0; i < (1); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(1)];
    for (i = 0 ; i < (1); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (1+1)) {
        VALUE callback = argv[1];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
    }
    // check callback param
    if (argc >= (1+2)) {
        VALUE callback_param = argv[1+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setRubyCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_RhoConnectClient_setSslVerifyPeer_caller setSslVerifyPeer_in_thread:[rb_RhoConnectClient_setSslVerifyPeer_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_RhoConnectClient_setSslVerifyPeer_caller setSslVerifyPeer:[rb_RhoConnectClient_setSslVerifyPeer_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_s_RhoConnectClient_setSslVerifyPeer(int argc, VALUE *argv) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return rb_RhoConnectClient_setSslVerifyPeer_Obj(argc, argv, singleton);

}







@interface rb_RhoConnectClient_loggedIn_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(rb_RhoConnectClient_loggedIn_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_RhoConnectClient_loggedIn_caller_params

@synthesize params,item,methodResult;

+(rb_RhoConnectClient_loggedIn_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_RhoConnectClient_loggedIn_caller_params* par = [[rb_RhoConnectClient_loggedIn_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface rb_RhoConnectClient_loggedIn_caller : NSObject {

}
+(rb_RhoConnectClient_loggedIn_caller*) getSharedInstance;
+(void) loggedIn:(rb_RhoConnectClient_loggedIn_caller_params*)caller_params;
+(void) loggedIn_in_thread:(rb_RhoConnectClient_loggedIn_caller_params*)caller_params;
+(void) loggedIn_in_UI_thread:(rb_RhoConnectClient_loggedIn_caller_params*)caller_params;

@end

static rb_RhoConnectClient_loggedIn_caller* our_RhoConnectClient_loggedIn_caller = nil;

@implementation rb_RhoConnectClient_loggedIn_caller

+(rb_RhoConnectClient_loggedIn_caller*) getSharedInstance {
    if (our_RhoConnectClient_loggedIn_caller == nil) {
        our_RhoConnectClient_loggedIn_caller = [[rb_RhoConnectClient_loggedIn_caller alloc] init];
    }
    return our_RhoConnectClient_loggedIn_caller;
}

-(void) command_loggedIn:(rb_RhoConnectClient_loggedIn_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem loggedIn:methodResult ];
}

+(void) loggedIn:(rb_RhoConnectClient_loggedIn_caller_params*)caller_params {
    [[rb_RhoConnectClient_loggedIn_caller getSharedInstance] command_loggedIn:caller_params];
}

+(void) loggedIn_in_thread:(rb_RhoConnectClient_loggedIn_caller_params*)caller_params {
    [[rb_RhoConnectClient_loggedIn_caller getSharedInstance] performSelectorInBackground:@selector(command_loggedIn:) withObject:caller_params];
}

+(void) loggedIn_in_UI_thread:(rb_RhoConnectClient_loggedIn_caller_params*)caller_params {
    [[rb_RhoConnectClient_loggedIn_caller getSharedInstance] performSelectorOnMainThread:@selector(command_loggedIn:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_RhoConnectClient_loggedIn_Obj(int argc, VALUE *argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[0+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    
    BOOL is_factory_param[] = { NO };

    int i;

    // init
    for (i = 0; i < (0); i++) {
        params[i] = [NSNull null];
    }

    // enumerate params
    for (int i = 0; i < (0); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(0)];
    for (i = 0 ; i < (0); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (0+1)) {
        VALUE callback = argv[0];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
    }
    // check callback param
    if (argc >= (0+2)) {
        VALUE callback_param = argv[0+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setRubyCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_RhoConnectClient_loggedIn_caller loggedIn_in_thread:[rb_RhoConnectClient_loggedIn_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_RhoConnectClient_loggedIn_caller loggedIn:[rb_RhoConnectClient_loggedIn_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_s_RhoConnectClient_loggedIn(int argc, VALUE *argv) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return rb_RhoConnectClient_loggedIn_Obj(argc, argv, singleton);

}







@interface rb_RhoConnectClient_syncing_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(rb_RhoConnectClient_syncing_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_RhoConnectClient_syncing_caller_params

@synthesize params,item,methodResult;

+(rb_RhoConnectClient_syncing_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_RhoConnectClient_syncing_caller_params* par = [[rb_RhoConnectClient_syncing_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface rb_RhoConnectClient_syncing_caller : NSObject {

}
+(rb_RhoConnectClient_syncing_caller*) getSharedInstance;
+(void) syncing:(rb_RhoConnectClient_syncing_caller_params*)caller_params;
+(void) syncing_in_thread:(rb_RhoConnectClient_syncing_caller_params*)caller_params;
+(void) syncing_in_UI_thread:(rb_RhoConnectClient_syncing_caller_params*)caller_params;

@end

static rb_RhoConnectClient_syncing_caller* our_RhoConnectClient_syncing_caller = nil;

@implementation rb_RhoConnectClient_syncing_caller

+(rb_RhoConnectClient_syncing_caller*) getSharedInstance {
    if (our_RhoConnectClient_syncing_caller == nil) {
        our_RhoConnectClient_syncing_caller = [[rb_RhoConnectClient_syncing_caller alloc] init];
    }
    return our_RhoConnectClient_syncing_caller;
}

-(void) command_syncing:(rb_RhoConnectClient_syncing_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem syncing:methodResult ];
}

+(void) syncing:(rb_RhoConnectClient_syncing_caller_params*)caller_params {
    [[rb_RhoConnectClient_syncing_caller getSharedInstance] command_syncing:caller_params];
}

+(void) syncing_in_thread:(rb_RhoConnectClient_syncing_caller_params*)caller_params {
    [[rb_RhoConnectClient_syncing_caller getSharedInstance] performSelectorInBackground:@selector(command_syncing:) withObject:caller_params];
}

+(void) syncing_in_UI_thread:(rb_RhoConnectClient_syncing_caller_params*)caller_params {
    [[rb_RhoConnectClient_syncing_caller getSharedInstance] performSelectorOnMainThread:@selector(command_syncing:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_RhoConnectClient_syncing_Obj(int argc, VALUE *argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[0+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    
    BOOL is_factory_param[] = { NO };

    int i;

    // init
    for (i = 0; i < (0); i++) {
        params[i] = [NSNull null];
    }

    // enumerate params
    for (int i = 0; i < (0); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(0)];
    for (i = 0 ; i < (0); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (0+1)) {
        VALUE callback = argv[0];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
    }
    // check callback param
    if (argc >= (0+2)) {
        VALUE callback_param = argv[0+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setRubyCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_RhoConnectClient_syncing_caller syncing_in_thread:[rb_RhoConnectClient_syncing_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_RhoConnectClient_syncing_caller syncing:[rb_RhoConnectClient_syncing_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_s_RhoConnectClient_syncing(int argc, VALUE *argv) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return rb_RhoConnectClient_syncing_Obj(argc, argv, singleton);

}







@interface rb_RhoConnectClient_onSyncCreateError_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(rb_RhoConnectClient_onSyncCreateError_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_RhoConnectClient_onSyncCreateError_caller_params

@synthesize params,item,methodResult;

+(rb_RhoConnectClient_onSyncCreateError_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_RhoConnectClient_onSyncCreateError_caller_params* par = [[rb_RhoConnectClient_onSyncCreateError_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface rb_RhoConnectClient_onSyncCreateError_caller : NSObject {

}
+(rb_RhoConnectClient_onSyncCreateError_caller*) getSharedInstance;
+(void) onSyncCreateError:(rb_RhoConnectClient_onSyncCreateError_caller_params*)caller_params;
+(void) onSyncCreateError_in_thread:(rb_RhoConnectClient_onSyncCreateError_caller_params*)caller_params;
+(void) onSyncCreateError_in_UI_thread:(rb_RhoConnectClient_onSyncCreateError_caller_params*)caller_params;

@end

static rb_RhoConnectClient_onSyncCreateError_caller* our_RhoConnectClient_onSyncCreateError_caller = nil;

@implementation rb_RhoConnectClient_onSyncCreateError_caller

+(rb_RhoConnectClient_onSyncCreateError_caller*) getSharedInstance {
    if (our_RhoConnectClient_onSyncCreateError_caller == nil) {
        our_RhoConnectClient_onSyncCreateError_caller = [[rb_RhoConnectClient_onSyncCreateError_caller alloc] init];
    }
    return our_RhoConnectClient_onSyncCreateError_caller;
}

-(void) command_onSyncCreateError:(rb_RhoConnectClient_onSyncCreateError_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem onSyncCreateError:(NSString*)[params objectAtIndex:0] objects:(NSArray*)[params objectAtIndex:1] action:(NSString*)[params objectAtIndex:2] ];
}

+(void) onSyncCreateError:(rb_RhoConnectClient_onSyncCreateError_caller_params*)caller_params {
    [[rb_RhoConnectClient_onSyncCreateError_caller getSharedInstance] command_onSyncCreateError:caller_params];
}

+(void) onSyncCreateError_in_thread:(rb_RhoConnectClient_onSyncCreateError_caller_params*)caller_params {
    [[rb_RhoConnectClient_onSyncCreateError_caller getSharedInstance] performSelectorInBackground:@selector(command_onSyncCreateError:) withObject:caller_params];
}

+(void) onSyncCreateError_in_UI_thread:(rb_RhoConnectClient_onSyncCreateError_caller_params*)caller_params {
    [[rb_RhoConnectClient_onSyncCreateError_caller getSharedInstance] performSelectorOnMainThread:@selector(command_onSyncCreateError:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_RhoConnectClient_onSyncCreateError_Obj(int argc, VALUE *argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[3+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    
    BOOL is_factory_param[] = { NO, NO, NO, NO };

    int i;

    // init
    for (i = 0; i < (3); i++) {
        params[i] = [NSNull null];
    }

    // enumerate params
    for (int i = 0; i < (3); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(3)];
    for (i = 0 ; i < (3); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (3+1)) {
        VALUE callback = argv[3];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
    }
    // check callback param
    if (argc >= (3+2)) {
        VALUE callback_param = argv[3+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setRubyCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_RhoConnectClient_onSyncCreateError_caller onSyncCreateError_in_thread:[rb_RhoConnectClient_onSyncCreateError_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_RhoConnectClient_onSyncCreateError_caller onSyncCreateError:[rb_RhoConnectClient_onSyncCreateError_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_s_RhoConnectClient_onSyncCreateError(int argc, VALUE *argv) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return rb_RhoConnectClient_onSyncCreateError_Obj(argc, argv, singleton);

}







@interface rb_RhoConnectClient_pushChanges_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(rb_RhoConnectClient_pushChanges_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_RhoConnectClient_pushChanges_caller_params

@synthesize params,item,methodResult;

+(rb_RhoConnectClient_pushChanges_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_RhoConnectClient_pushChanges_caller_params* par = [[rb_RhoConnectClient_pushChanges_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface rb_RhoConnectClient_pushChanges_caller : NSObject {

}
+(rb_RhoConnectClient_pushChanges_caller*) getSharedInstance;
+(void) pushChanges:(rb_RhoConnectClient_pushChanges_caller_params*)caller_params;
+(void) pushChanges_in_thread:(rb_RhoConnectClient_pushChanges_caller_params*)caller_params;
+(void) pushChanges_in_UI_thread:(rb_RhoConnectClient_pushChanges_caller_params*)caller_params;

@end

static rb_RhoConnectClient_pushChanges_caller* our_RhoConnectClient_pushChanges_caller = nil;

@implementation rb_RhoConnectClient_pushChanges_caller

+(rb_RhoConnectClient_pushChanges_caller*) getSharedInstance {
    if (our_RhoConnectClient_pushChanges_caller == nil) {
        our_RhoConnectClient_pushChanges_caller = [[rb_RhoConnectClient_pushChanges_caller alloc] init];
    }
    return our_RhoConnectClient_pushChanges_caller;
}

-(void) command_pushChanges:(rb_RhoConnectClient_pushChanges_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem pushChanges:(NSString*)[params objectAtIndex:0] ];
}

+(void) pushChanges:(rb_RhoConnectClient_pushChanges_caller_params*)caller_params {
    [[rb_RhoConnectClient_pushChanges_caller getSharedInstance] command_pushChanges:caller_params];
}

+(void) pushChanges_in_thread:(rb_RhoConnectClient_pushChanges_caller_params*)caller_params {
    [[rb_RhoConnectClient_pushChanges_caller getSharedInstance] performSelectorInBackground:@selector(command_pushChanges:) withObject:caller_params];
}

+(void) pushChanges_in_UI_thread:(rb_RhoConnectClient_pushChanges_caller_params*)caller_params {
    [[rb_RhoConnectClient_pushChanges_caller getSharedInstance] performSelectorOnMainThread:@selector(command_pushChanges:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_RhoConnectClient_pushChanges_Obj(int argc, VALUE *argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[1+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    
    BOOL is_factory_param[] = { NO, NO };

    int i;

    // init
    for (i = 0; i < (1); i++) {
        params[i] = [NSNull null];
    }

    // enumerate params
    for (int i = 0; i < (1); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(1)];
    for (i = 0 ; i < (1); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (1+1)) {
        VALUE callback = argv[1];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
    }
    // check callback param
    if (argc >= (1+2)) {
        VALUE callback_param = argv[1+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setRubyCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_RhoConnectClient_pushChanges_caller pushChanges_in_thread:[rb_RhoConnectClient_pushChanges_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_RhoConnectClient_pushChanges_caller pushChanges:[rb_RhoConnectClient_pushChanges_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_s_RhoConnectClient_pushChanges(int argc, VALUE *argv) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return rb_RhoConnectClient_pushChanges_Obj(argc, argv, singleton);

}







@interface rb_RhoConnectClient_onSyncUpdateError_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(rb_RhoConnectClient_onSyncUpdateError_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_RhoConnectClient_onSyncUpdateError_caller_params

@synthesize params,item,methodResult;

+(rb_RhoConnectClient_onSyncUpdateError_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_RhoConnectClient_onSyncUpdateError_caller_params* par = [[rb_RhoConnectClient_onSyncUpdateError_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface rb_RhoConnectClient_onSyncUpdateError_caller : NSObject {

}
+(rb_RhoConnectClient_onSyncUpdateError_caller*) getSharedInstance;
+(void) onSyncUpdateError:(rb_RhoConnectClient_onSyncUpdateError_caller_params*)caller_params;
+(void) onSyncUpdateError_in_thread:(rb_RhoConnectClient_onSyncUpdateError_caller_params*)caller_params;
+(void) onSyncUpdateError_in_UI_thread:(rb_RhoConnectClient_onSyncUpdateError_caller_params*)caller_params;

@end

static rb_RhoConnectClient_onSyncUpdateError_caller* our_RhoConnectClient_onSyncUpdateError_caller = nil;

@implementation rb_RhoConnectClient_onSyncUpdateError_caller

+(rb_RhoConnectClient_onSyncUpdateError_caller*) getSharedInstance {
    if (our_RhoConnectClient_onSyncUpdateError_caller == nil) {
        our_RhoConnectClient_onSyncUpdateError_caller = [[rb_RhoConnectClient_onSyncUpdateError_caller alloc] init];
    }
    return our_RhoConnectClient_onSyncUpdateError_caller;
}

-(void) command_onSyncUpdateError:(rb_RhoConnectClient_onSyncUpdateError_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem onSyncUpdateError:(NSString*)[params objectAtIndex:0] objects:(NSArray*)[params objectAtIndex:1] action:(NSString*)[params objectAtIndex:2] rollbackData:(NSString*)[params objectAtIndex:3] ];
}

+(void) onSyncUpdateError:(rb_RhoConnectClient_onSyncUpdateError_caller_params*)caller_params {
    [[rb_RhoConnectClient_onSyncUpdateError_caller getSharedInstance] command_onSyncUpdateError:caller_params];
}

+(void) onSyncUpdateError_in_thread:(rb_RhoConnectClient_onSyncUpdateError_caller_params*)caller_params {
    [[rb_RhoConnectClient_onSyncUpdateError_caller getSharedInstance] performSelectorInBackground:@selector(command_onSyncUpdateError:) withObject:caller_params];
}

+(void) onSyncUpdateError_in_UI_thread:(rb_RhoConnectClient_onSyncUpdateError_caller_params*)caller_params {
    [[rb_RhoConnectClient_onSyncUpdateError_caller getSharedInstance] performSelectorOnMainThread:@selector(command_onSyncUpdateError:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_RhoConnectClient_onSyncUpdateError_Obj(int argc, VALUE *argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[4+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    
    BOOL is_factory_param[] = { NO, NO, NO, NO, NO };

    int i;

    // init
    for (i = 0; i < (4); i++) {
        params[i] = [NSNull null];
    }

    // enumerate params
    for (int i = 0; i < (4); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(4)];
    for (i = 0 ; i < (4); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (4+1)) {
        VALUE callback = argv[4];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
    }
    // check callback param
    if (argc >= (4+2)) {
        VALUE callback_param = argv[4+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setRubyCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_RhoConnectClient_onSyncUpdateError_caller onSyncUpdateError_in_thread:[rb_RhoConnectClient_onSyncUpdateError_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_RhoConnectClient_onSyncUpdateError_caller onSyncUpdateError:[rb_RhoConnectClient_onSyncUpdateError_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_s_RhoConnectClient_onSyncUpdateError(int argc, VALUE *argv) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return rb_RhoConnectClient_onSyncUpdateError_Obj(argc, argv, singleton);

}







@interface rb_RhoConnectClient_onSyncDeleteError_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(rb_RhoConnectClient_onSyncDeleteError_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_RhoConnectClient_onSyncDeleteError_caller_params

@synthesize params,item,methodResult;

+(rb_RhoConnectClient_onSyncDeleteError_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_RhoConnectClient_onSyncDeleteError_caller_params* par = [[rb_RhoConnectClient_onSyncDeleteError_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface rb_RhoConnectClient_onSyncDeleteError_caller : NSObject {

}
+(rb_RhoConnectClient_onSyncDeleteError_caller*) getSharedInstance;
+(void) onSyncDeleteError:(rb_RhoConnectClient_onSyncDeleteError_caller_params*)caller_params;
+(void) onSyncDeleteError_in_thread:(rb_RhoConnectClient_onSyncDeleteError_caller_params*)caller_params;
+(void) onSyncDeleteError_in_UI_thread:(rb_RhoConnectClient_onSyncDeleteError_caller_params*)caller_params;

@end

static rb_RhoConnectClient_onSyncDeleteError_caller* our_RhoConnectClient_onSyncDeleteError_caller = nil;

@implementation rb_RhoConnectClient_onSyncDeleteError_caller

+(rb_RhoConnectClient_onSyncDeleteError_caller*) getSharedInstance {
    if (our_RhoConnectClient_onSyncDeleteError_caller == nil) {
        our_RhoConnectClient_onSyncDeleteError_caller = [[rb_RhoConnectClient_onSyncDeleteError_caller alloc] init];
    }
    return our_RhoConnectClient_onSyncDeleteError_caller;
}

-(void) command_onSyncDeleteError:(rb_RhoConnectClient_onSyncDeleteError_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem onSyncDeleteError:(NSString*)[params objectAtIndex:0] objects:(NSArray*)[params objectAtIndex:1] action:(NSString*)[params objectAtIndex:2] ];
}

+(void) onSyncDeleteError:(rb_RhoConnectClient_onSyncDeleteError_caller_params*)caller_params {
    [[rb_RhoConnectClient_onSyncDeleteError_caller getSharedInstance] command_onSyncDeleteError:caller_params];
}

+(void) onSyncDeleteError_in_thread:(rb_RhoConnectClient_onSyncDeleteError_caller_params*)caller_params {
    [[rb_RhoConnectClient_onSyncDeleteError_caller getSharedInstance] performSelectorInBackground:@selector(command_onSyncDeleteError:) withObject:caller_params];
}

+(void) onSyncDeleteError_in_UI_thread:(rb_RhoConnectClient_onSyncDeleteError_caller_params*)caller_params {
    [[rb_RhoConnectClient_onSyncDeleteError_caller getSharedInstance] performSelectorOnMainThread:@selector(command_onSyncDeleteError:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_RhoConnectClient_onSyncDeleteError_Obj(int argc, VALUE *argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[3+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    
    BOOL is_factory_param[] = { NO, NO, NO, NO };

    int i;

    // init
    for (i = 0; i < (3); i++) {
        params[i] = [NSNull null];
    }

    // enumerate params
    for (int i = 0; i < (3); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(3)];
    for (i = 0 ; i < (3); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (3+1)) {
        VALUE callback = argv[3];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
    }
    // check callback param
    if (argc >= (3+2)) {
        VALUE callback_param = argv[3+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setRubyCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_RhoConnectClient_onSyncDeleteError_caller onSyncDeleteError_in_thread:[rb_RhoConnectClient_onSyncDeleteError_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_RhoConnectClient_onSyncDeleteError_caller onSyncDeleteError:[rb_RhoConnectClient_onSyncDeleteError_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_s_RhoConnectClient_onSyncDeleteError(int argc, VALUE *argv) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return rb_RhoConnectClient_onSyncDeleteError_Obj(argc, argv, singleton);

}







@interface rb_RhoConnectClient_search_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(rb_RhoConnectClient_search_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_RhoConnectClient_search_caller_params

@synthesize params,item,methodResult;

+(rb_RhoConnectClient_search_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_RhoConnectClient_search_caller_params* par = [[rb_RhoConnectClient_search_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface rb_RhoConnectClient_search_caller : NSObject {

}
+(rb_RhoConnectClient_search_caller*) getSharedInstance;
+(void) search:(rb_RhoConnectClient_search_caller_params*)caller_params;
+(void) search_in_thread:(rb_RhoConnectClient_search_caller_params*)caller_params;
+(void) search_in_UI_thread:(rb_RhoConnectClient_search_caller_params*)caller_params;

@end

static rb_RhoConnectClient_search_caller* our_RhoConnectClient_search_caller = nil;

@implementation rb_RhoConnectClient_search_caller

+(rb_RhoConnectClient_search_caller*) getSharedInstance {
    if (our_RhoConnectClient_search_caller == nil) {
        our_RhoConnectClient_search_caller = [[rb_RhoConnectClient_search_caller alloc] init];
    }
    return our_RhoConnectClient_search_caller;
}

-(void) command_search:(rb_RhoConnectClient_search_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem search:(NSDictionary*)[params objectAtIndex:0] methodResult:methodResult ];
}

+(void) search:(rb_RhoConnectClient_search_caller_params*)caller_params {
    [[rb_RhoConnectClient_search_caller getSharedInstance] command_search:caller_params];
}

+(void) search_in_thread:(rb_RhoConnectClient_search_caller_params*)caller_params {
    [[rb_RhoConnectClient_search_caller getSharedInstance] performSelectorInBackground:@selector(command_search:) withObject:caller_params];
}

+(void) search_in_UI_thread:(rb_RhoConnectClient_search_caller_params*)caller_params {
    [[rb_RhoConnectClient_search_caller getSharedInstance] performSelectorOnMainThread:@selector(command_search:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_RhoConnectClient_search_Obj(int argc, VALUE *argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[1+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    
    BOOL is_factory_param[] = { NO, NO };

    int i;

    // init
    for (i = 0; i < (1); i++) {
        params[i] = [NSNull null];
    }

    // enumerate params
    for (int i = 0; i < (1); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(1)];
    for (i = 0 ; i < (1); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (1+1)) {
        VALUE callback = argv[1];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
    }
    // check callback param
    if (argc >= (1+2)) {
        VALUE callback_param = argv[1+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setRubyCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_RhoConnectClient_search_caller search_in_thread:[rb_RhoConnectClient_search_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_RhoConnectClient_search_caller search:[rb_RhoConnectClient_search_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_s_RhoConnectClient_search(int argc, VALUE *argv) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return rb_RhoConnectClient_search_Obj(argc, argv, singleton);

}







@interface rb_RhoConnectClient_doSync_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(rb_RhoConnectClient_doSync_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_RhoConnectClient_doSync_caller_params

@synthesize params,item,methodResult;

+(rb_RhoConnectClient_doSync_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_RhoConnectClient_doSync_caller_params* par = [[rb_RhoConnectClient_doSync_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface rb_RhoConnectClient_doSync_caller : NSObject {

}
+(rb_RhoConnectClient_doSync_caller*) getSharedInstance;
+(void) doSync:(rb_RhoConnectClient_doSync_caller_params*)caller_params;
+(void) doSync_in_thread:(rb_RhoConnectClient_doSync_caller_params*)caller_params;
+(void) doSync_in_UI_thread:(rb_RhoConnectClient_doSync_caller_params*)caller_params;

@end

static rb_RhoConnectClient_doSync_caller* our_RhoConnectClient_doSync_caller = nil;

@implementation rb_RhoConnectClient_doSync_caller

+(rb_RhoConnectClient_doSync_caller*) getSharedInstance {
    if (our_RhoConnectClient_doSync_caller == nil) {
        our_RhoConnectClient_doSync_caller = [[rb_RhoConnectClient_doSync_caller alloc] init];
    }
    return our_RhoConnectClient_doSync_caller;
}

-(void) command_doSync:(rb_RhoConnectClient_doSync_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem doSync:(BOOL)[((NSNumber*)[params objectAtIndex:0]) boolValue] queryParams:(NSString*)[params objectAtIndex:1] syncOnlyChangedSources:(BOOL)[((NSNumber*)[params objectAtIndex:2]) boolValue] methodResult:methodResult ];
}

+(void) doSync:(rb_RhoConnectClient_doSync_caller_params*)caller_params {
    [[rb_RhoConnectClient_doSync_caller getSharedInstance] command_doSync:caller_params];
}

+(void) doSync_in_thread:(rb_RhoConnectClient_doSync_caller_params*)caller_params {
    [[rb_RhoConnectClient_doSync_caller getSharedInstance] performSelectorInBackground:@selector(command_doSync:) withObject:caller_params];
}

+(void) doSync_in_UI_thread:(rb_RhoConnectClient_doSync_caller_params*)caller_params {
    [[rb_RhoConnectClient_doSync_caller getSharedInstance] performSelectorOnMainThread:@selector(command_doSync:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_RhoConnectClient_doSync_Obj(int argc, VALUE *argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[3+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    
    BOOL is_factory_param[] = { NO, NO, NO, NO };

    int i;

    // init
    for (i = 0; i < (3); i++) {
        params[i] = [NSNull null];
    }

    // enumerate params
    for (int i = 0; i < (3); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(3)];
    for (i = 0 ; i < (3); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (3+1)) {
        VALUE callback = argv[3];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
    }
    // check callback param
    if (argc >= (3+2)) {
        VALUE callback_param = argv[3+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setRubyCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_RhoConnectClient_doSync_caller doSync_in_thread:[rb_RhoConnectClient_doSync_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_RhoConnectClient_doSync_caller doSync:[rb_RhoConnectClient_doSync_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_s_RhoConnectClient_doSync(int argc, VALUE *argv) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return rb_RhoConnectClient_doSync_Obj(argc, argv, singleton);

}







@interface rb_RhoConnectClient_doSyncSource_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(rb_RhoConnectClient_doSyncSource_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_RhoConnectClient_doSyncSource_caller_params

@synthesize params,item,methodResult;

+(rb_RhoConnectClient_doSyncSource_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_RhoConnectClient_doSyncSource_caller_params* par = [[rb_RhoConnectClient_doSyncSource_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface rb_RhoConnectClient_doSyncSource_caller : NSObject {

}
+(rb_RhoConnectClient_doSyncSource_caller*) getSharedInstance;
+(void) doSyncSource:(rb_RhoConnectClient_doSyncSource_caller_params*)caller_params;
+(void) doSyncSource_in_thread:(rb_RhoConnectClient_doSyncSource_caller_params*)caller_params;
+(void) doSyncSource_in_UI_thread:(rb_RhoConnectClient_doSyncSource_caller_params*)caller_params;

@end

static rb_RhoConnectClient_doSyncSource_caller* our_RhoConnectClient_doSyncSource_caller = nil;

@implementation rb_RhoConnectClient_doSyncSource_caller

+(rb_RhoConnectClient_doSyncSource_caller*) getSharedInstance {
    if (our_RhoConnectClient_doSyncSource_caller == nil) {
        our_RhoConnectClient_doSyncSource_caller = [[rb_RhoConnectClient_doSyncSource_caller alloc] init];
    }
    return our_RhoConnectClient_doSyncSource_caller;
}

-(void) command_doSyncSource:(rb_RhoConnectClient_doSyncSource_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem doSyncSource:(NSString*)[params objectAtIndex:0] showStatusPopup:(BOOL)[((NSNumber*)[params objectAtIndex:1]) boolValue] queryParams:(NSString*)[params objectAtIndex:2] methodResult:methodResult ];
}

+(void) doSyncSource:(rb_RhoConnectClient_doSyncSource_caller_params*)caller_params {
    [[rb_RhoConnectClient_doSyncSource_caller getSharedInstance] command_doSyncSource:caller_params];
}

+(void) doSyncSource_in_thread:(rb_RhoConnectClient_doSyncSource_caller_params*)caller_params {
    [[rb_RhoConnectClient_doSyncSource_caller getSharedInstance] performSelectorInBackground:@selector(command_doSyncSource:) withObject:caller_params];
}

+(void) doSyncSource_in_UI_thread:(rb_RhoConnectClient_doSyncSource_caller_params*)caller_params {
    [[rb_RhoConnectClient_doSyncSource_caller getSharedInstance] performSelectorOnMainThread:@selector(command_doSyncSource:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_RhoConnectClient_doSyncSource_Obj(int argc, VALUE *argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[3+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    
    BOOL is_factory_param[] = { NO, NO, NO, NO };

    int i;

    // init
    for (i = 0; i < (3); i++) {
        params[i] = [NSNull null];
    }

    // enumerate params
    for (int i = 0; i < (3); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(3)];
    for (i = 0 ; i < (3); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (3+1)) {
        VALUE callback = argv[3];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
    }
    // check callback param
    if (argc >= (3+2)) {
        VALUE callback_param = argv[3+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setRubyCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_RhoConnectClient_doSyncSource_caller doSyncSource_in_thread:[rb_RhoConnectClient_doSyncSource_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_RhoConnectClient_doSyncSource_caller doSyncSource:[rb_RhoConnectClient_doSyncSource_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_s_RhoConnectClient_doSyncSource(int argc, VALUE *argv) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return rb_RhoConnectClient_doSyncSource_Obj(argc, argv, singleton);

}







@interface rb_RhoConnectClient_login_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(rb_RhoConnectClient_login_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_RhoConnectClient_login_caller_params

@synthesize params,item,methodResult;

+(rb_RhoConnectClient_login_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_RhoConnectClient_login_caller_params* par = [[rb_RhoConnectClient_login_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface rb_RhoConnectClient_login_caller : NSObject {

}
+(rb_RhoConnectClient_login_caller*) getSharedInstance;
+(void) login:(rb_RhoConnectClient_login_caller_params*)caller_params;
+(void) login_in_thread:(rb_RhoConnectClient_login_caller_params*)caller_params;
+(void) login_in_UI_thread:(rb_RhoConnectClient_login_caller_params*)caller_params;

@end

static rb_RhoConnectClient_login_caller* our_RhoConnectClient_login_caller = nil;

@implementation rb_RhoConnectClient_login_caller

+(rb_RhoConnectClient_login_caller*) getSharedInstance {
    if (our_RhoConnectClient_login_caller == nil) {
        our_RhoConnectClient_login_caller = [[rb_RhoConnectClient_login_caller alloc] init];
    }
    return our_RhoConnectClient_login_caller;
}

-(void) command_login:(rb_RhoConnectClient_login_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem login:(NSString*)[params objectAtIndex:0] password:(NSString*)[params objectAtIndex:1] methodResult:methodResult ];
}

+(void) login:(rb_RhoConnectClient_login_caller_params*)caller_params {
    [[rb_RhoConnectClient_login_caller getSharedInstance] command_login:caller_params];
}

+(void) login_in_thread:(rb_RhoConnectClient_login_caller_params*)caller_params {
    [[rb_RhoConnectClient_login_caller getSharedInstance] performSelectorInBackground:@selector(command_login:) withObject:caller_params];
}

+(void) login_in_UI_thread:(rb_RhoConnectClient_login_caller_params*)caller_params {
    [[rb_RhoConnectClient_login_caller getSharedInstance] performSelectorOnMainThread:@selector(command_login:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_RhoConnectClient_login_Obj(int argc, VALUE *argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[2+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    
    BOOL is_factory_param[] = { NO, NO, NO };

    int i;

    // init
    for (i = 0; i < (2); i++) {
        params[i] = [NSNull null];
    }

    // enumerate params
    for (int i = 0; i < (2); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(2)];
    for (i = 0 ; i < (2); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (2+1)) {
        VALUE callback = argv[2];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
    }
    // check callback param
    if (argc >= (2+2)) {
        VALUE callback_param = argv[2+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setRubyCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_RhoConnectClient_login_caller login_in_thread:[rb_RhoConnectClient_login_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_RhoConnectClient_login_caller login:[rb_RhoConnectClient_login_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_s_RhoConnectClient_login(int argc, VALUE *argv) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return rb_RhoConnectClient_login_Obj(argc, argv, singleton);

}







@interface rb_RhoConnectClient_logout_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(rb_RhoConnectClient_logout_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_RhoConnectClient_logout_caller_params

@synthesize params,item,methodResult;

+(rb_RhoConnectClient_logout_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_RhoConnectClient_logout_caller_params* par = [[rb_RhoConnectClient_logout_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface rb_RhoConnectClient_logout_caller : NSObject {

}
+(rb_RhoConnectClient_logout_caller*) getSharedInstance;
+(void) logout:(rb_RhoConnectClient_logout_caller_params*)caller_params;
+(void) logout_in_thread:(rb_RhoConnectClient_logout_caller_params*)caller_params;
+(void) logout_in_UI_thread:(rb_RhoConnectClient_logout_caller_params*)caller_params;

@end

static rb_RhoConnectClient_logout_caller* our_RhoConnectClient_logout_caller = nil;

@implementation rb_RhoConnectClient_logout_caller

+(rb_RhoConnectClient_logout_caller*) getSharedInstance {
    if (our_RhoConnectClient_logout_caller == nil) {
        our_RhoConnectClient_logout_caller = [[rb_RhoConnectClient_logout_caller alloc] init];
    }
    return our_RhoConnectClient_logout_caller;
}

-(void) command_logout:(rb_RhoConnectClient_logout_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem logout];
}

+(void) logout:(rb_RhoConnectClient_logout_caller_params*)caller_params {
    [[rb_RhoConnectClient_logout_caller getSharedInstance] command_logout:caller_params];
}

+(void) logout_in_thread:(rb_RhoConnectClient_logout_caller_params*)caller_params {
    [[rb_RhoConnectClient_logout_caller getSharedInstance] performSelectorInBackground:@selector(command_logout:) withObject:caller_params];
}

+(void) logout_in_UI_thread:(rb_RhoConnectClient_logout_caller_params*)caller_params {
    [[rb_RhoConnectClient_logout_caller getSharedInstance] performSelectorOnMainThread:@selector(command_logout:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_RhoConnectClient_logout_Obj(int argc, VALUE *argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[0+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    
    BOOL is_factory_param[] = { NO };

    int i;

    // init
    for (i = 0; i < (0); i++) {
        params[i] = [NSNull null];
    }

    // enumerate params
    for (int i = 0; i < (0); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(0)];
    for (i = 0 ; i < (0); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (0+1)) {
        VALUE callback = argv[0];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
    }
    // check callback param
    if (argc >= (0+2)) {
        VALUE callback_param = argv[0+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setRubyCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_RhoConnectClient_logout_caller logout_in_thread:[rb_RhoConnectClient_logout_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_RhoConnectClient_logout_caller logout:[rb_RhoConnectClient_logout_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_s_RhoConnectClient_logout(int argc, VALUE *argv) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return rb_RhoConnectClient_logout_Obj(argc, argv, singleton);

}







@interface rb_RhoConnectClient_stopSync_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(rb_RhoConnectClient_stopSync_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_RhoConnectClient_stopSync_caller_params

@synthesize params,item,methodResult;

+(rb_RhoConnectClient_stopSync_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_RhoConnectClient_stopSync_caller_params* par = [[rb_RhoConnectClient_stopSync_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface rb_RhoConnectClient_stopSync_caller : NSObject {

}
+(rb_RhoConnectClient_stopSync_caller*) getSharedInstance;
+(void) stopSync:(rb_RhoConnectClient_stopSync_caller_params*)caller_params;
+(void) stopSync_in_thread:(rb_RhoConnectClient_stopSync_caller_params*)caller_params;
+(void) stopSync_in_UI_thread:(rb_RhoConnectClient_stopSync_caller_params*)caller_params;

@end

static rb_RhoConnectClient_stopSync_caller* our_RhoConnectClient_stopSync_caller = nil;

@implementation rb_RhoConnectClient_stopSync_caller

+(rb_RhoConnectClient_stopSync_caller*) getSharedInstance {
    if (our_RhoConnectClient_stopSync_caller == nil) {
        our_RhoConnectClient_stopSync_caller = [[rb_RhoConnectClient_stopSync_caller alloc] init];
    }
    return our_RhoConnectClient_stopSync_caller;
}

-(void) command_stopSync:(rb_RhoConnectClient_stopSync_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem stopSync];
}

+(void) stopSync:(rb_RhoConnectClient_stopSync_caller_params*)caller_params {
    [[rb_RhoConnectClient_stopSync_caller getSharedInstance] command_stopSync:caller_params];
}

+(void) stopSync_in_thread:(rb_RhoConnectClient_stopSync_caller_params*)caller_params {
    [[rb_RhoConnectClient_stopSync_caller getSharedInstance] performSelectorInBackground:@selector(command_stopSync:) withObject:caller_params];
}

+(void) stopSync_in_UI_thread:(rb_RhoConnectClient_stopSync_caller_params*)caller_params {
    [[rb_RhoConnectClient_stopSync_caller getSharedInstance] performSelectorOnMainThread:@selector(command_stopSync:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_RhoConnectClient_stopSync_Obj(int argc, VALUE *argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[0+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    
    BOOL is_factory_param[] = { NO };

    int i;

    // init
    for (i = 0; i < (0); i++) {
        params[i] = [NSNull null];
    }

    // enumerate params
    for (int i = 0; i < (0); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(0)];
    for (i = 0 ; i < (0); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (0+1)) {
        VALUE callback = argv[0];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
    }
    // check callback param
    if (argc >= (0+2)) {
        VALUE callback_param = argv[0+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setRubyCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_RhoConnectClient_stopSync_caller stopSync_in_thread:[rb_RhoConnectClient_stopSync_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_RhoConnectClient_stopSync_caller stopSync:[rb_RhoConnectClient_stopSync_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_s_RhoConnectClient_stopSync(int argc, VALUE *argv) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return rb_RhoConnectClient_stopSync_Obj(argc, argv, singleton);

}







@interface rb_RhoConnectClient_setNotification_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(rb_RhoConnectClient_setNotification_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_RhoConnectClient_setNotification_caller_params

@synthesize params,item,methodResult;

+(rb_RhoConnectClient_setNotification_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_RhoConnectClient_setNotification_caller_params* par = [[rb_RhoConnectClient_setNotification_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface rb_RhoConnectClient_setNotification_caller : NSObject {

}
+(rb_RhoConnectClient_setNotification_caller*) getSharedInstance;
+(void) setNotification:(rb_RhoConnectClient_setNotification_caller_params*)caller_params;
+(void) setNotification_in_thread:(rb_RhoConnectClient_setNotification_caller_params*)caller_params;
+(void) setNotification_in_UI_thread:(rb_RhoConnectClient_setNotification_caller_params*)caller_params;

@end

static rb_RhoConnectClient_setNotification_caller* our_RhoConnectClient_setNotification_caller = nil;

@implementation rb_RhoConnectClient_setNotification_caller

+(rb_RhoConnectClient_setNotification_caller*) getSharedInstance {
    if (our_RhoConnectClient_setNotification_caller == nil) {
        our_RhoConnectClient_setNotification_caller = [[rb_RhoConnectClient_setNotification_caller alloc] init];
    }
    return our_RhoConnectClient_setNotification_caller;
}

-(void) command_setNotification:(rb_RhoConnectClient_setNotification_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem setNotification:(NSString*)[params objectAtIndex:0] methodResult:methodResult ];
}

+(void) setNotification:(rb_RhoConnectClient_setNotification_caller_params*)caller_params {
    [[rb_RhoConnectClient_setNotification_caller getSharedInstance] command_setNotification:caller_params];
}

+(void) setNotification_in_thread:(rb_RhoConnectClient_setNotification_caller_params*)caller_params {
    [[rb_RhoConnectClient_setNotification_caller getSharedInstance] performSelectorInBackground:@selector(command_setNotification:) withObject:caller_params];
}

+(void) setNotification_in_UI_thread:(rb_RhoConnectClient_setNotification_caller_params*)caller_params {
    [[rb_RhoConnectClient_setNotification_caller getSharedInstance] performSelectorOnMainThread:@selector(command_setNotification:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_RhoConnectClient_setNotification_Obj(int argc, VALUE *argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[1+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    
    BOOL is_factory_param[] = { NO, NO };

    int i;

    // init
    for (i = 0; i < (1); i++) {
        params[i] = [NSNull null];
    }

    // enumerate params
    for (int i = 0; i < (1); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(1)];
    for (i = 0 ; i < (1); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (1+1)) {
        VALUE callback = argv[1];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
    }
    // check callback param
    if (argc >= (1+2)) {
        VALUE callback_param = argv[1+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setRubyCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_RhoConnectClient_setNotification_caller setNotification_in_thread:[rb_RhoConnectClient_setNotification_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_RhoConnectClient_setNotification_caller setNotification:[rb_RhoConnectClient_setNotification_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_s_RhoConnectClient_setNotification(int argc, VALUE *argv) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return rb_RhoConnectClient_setNotification_Obj(argc, argv, singleton);

}







@interface rb_RhoConnectClient_clearNotification_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(rb_RhoConnectClient_clearNotification_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_RhoConnectClient_clearNotification_caller_params

@synthesize params,item,methodResult;

+(rb_RhoConnectClient_clearNotification_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_RhoConnectClient_clearNotification_caller_params* par = [[rb_RhoConnectClient_clearNotification_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface rb_RhoConnectClient_clearNotification_caller : NSObject {

}
+(rb_RhoConnectClient_clearNotification_caller*) getSharedInstance;
+(void) clearNotification:(rb_RhoConnectClient_clearNotification_caller_params*)caller_params;
+(void) clearNotification_in_thread:(rb_RhoConnectClient_clearNotification_caller_params*)caller_params;
+(void) clearNotification_in_UI_thread:(rb_RhoConnectClient_clearNotification_caller_params*)caller_params;

@end

static rb_RhoConnectClient_clearNotification_caller* our_RhoConnectClient_clearNotification_caller = nil;

@implementation rb_RhoConnectClient_clearNotification_caller

+(rb_RhoConnectClient_clearNotification_caller*) getSharedInstance {
    if (our_RhoConnectClient_clearNotification_caller == nil) {
        our_RhoConnectClient_clearNotification_caller = [[rb_RhoConnectClient_clearNotification_caller alloc] init];
    }
    return our_RhoConnectClient_clearNotification_caller;
}

-(void) command_clearNotification:(rb_RhoConnectClient_clearNotification_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem clearNotification:(NSString*)[params objectAtIndex:0] ];
}

+(void) clearNotification:(rb_RhoConnectClient_clearNotification_caller_params*)caller_params {
    [[rb_RhoConnectClient_clearNotification_caller getSharedInstance] command_clearNotification:caller_params];
}

+(void) clearNotification_in_thread:(rb_RhoConnectClient_clearNotification_caller_params*)caller_params {
    [[rb_RhoConnectClient_clearNotification_caller getSharedInstance] performSelectorInBackground:@selector(command_clearNotification:) withObject:caller_params];
}

+(void) clearNotification_in_UI_thread:(rb_RhoConnectClient_clearNotification_caller_params*)caller_params {
    [[rb_RhoConnectClient_clearNotification_caller getSharedInstance] performSelectorOnMainThread:@selector(command_clearNotification:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_RhoConnectClient_clearNotification_Obj(int argc, VALUE *argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[1+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    
    BOOL is_factory_param[] = { NO, NO };

    int i;

    // init
    for (i = 0; i < (1); i++) {
        params[i] = [NSNull null];
    }

    // enumerate params
    for (int i = 0; i < (1); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(1)];
    for (i = 0 ; i < (1); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (1+1)) {
        VALUE callback = argv[1];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
    }
    // check callback param
    if (argc >= (1+2)) {
        VALUE callback_param = argv[1+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setRubyCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_RhoConnectClient_clearNotification_caller clearNotification_in_thread:[rb_RhoConnectClient_clearNotification_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_RhoConnectClient_clearNotification_caller clearNotification:[rb_RhoConnectClient_clearNotification_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_s_RhoConnectClient_clearNotification(int argc, VALUE *argv) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return rb_RhoConnectClient_clearNotification_Obj(argc, argv, singleton);

}







@interface rb_RhoConnectClient_setObjectNotification_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(rb_RhoConnectClient_setObjectNotification_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_RhoConnectClient_setObjectNotification_caller_params

@synthesize params,item,methodResult;

+(rb_RhoConnectClient_setObjectNotification_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_RhoConnectClient_setObjectNotification_caller_params* par = [[rb_RhoConnectClient_setObjectNotification_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface rb_RhoConnectClient_setObjectNotification_caller : NSObject {

}
+(rb_RhoConnectClient_setObjectNotification_caller*) getSharedInstance;
+(void) setObjectNotification:(rb_RhoConnectClient_setObjectNotification_caller_params*)caller_params;
+(void) setObjectNotification_in_thread:(rb_RhoConnectClient_setObjectNotification_caller_params*)caller_params;
+(void) setObjectNotification_in_UI_thread:(rb_RhoConnectClient_setObjectNotification_caller_params*)caller_params;

@end

static rb_RhoConnectClient_setObjectNotification_caller* our_RhoConnectClient_setObjectNotification_caller = nil;

@implementation rb_RhoConnectClient_setObjectNotification_caller

+(rb_RhoConnectClient_setObjectNotification_caller*) getSharedInstance {
    if (our_RhoConnectClient_setObjectNotification_caller == nil) {
        our_RhoConnectClient_setObjectNotification_caller = [[rb_RhoConnectClient_setObjectNotification_caller alloc] init];
    }
    return our_RhoConnectClient_setObjectNotification_caller;
}

-(void) command_setObjectNotification:(rb_RhoConnectClient_setObjectNotification_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem setObjectNotification:methodResult ];
}

+(void) setObjectNotification:(rb_RhoConnectClient_setObjectNotification_caller_params*)caller_params {
    [[rb_RhoConnectClient_setObjectNotification_caller getSharedInstance] command_setObjectNotification:caller_params];
}

+(void) setObjectNotification_in_thread:(rb_RhoConnectClient_setObjectNotification_caller_params*)caller_params {
    [[rb_RhoConnectClient_setObjectNotification_caller getSharedInstance] performSelectorInBackground:@selector(command_setObjectNotification:) withObject:caller_params];
}

+(void) setObjectNotification_in_UI_thread:(rb_RhoConnectClient_setObjectNotification_caller_params*)caller_params {
    [[rb_RhoConnectClient_setObjectNotification_caller getSharedInstance] performSelectorOnMainThread:@selector(command_setObjectNotification:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_RhoConnectClient_setObjectNotification_Obj(int argc, VALUE *argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[0+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    
    BOOL is_factory_param[] = { NO };

    int i;

    // init
    for (i = 0; i < (0); i++) {
        params[i] = [NSNull null];
    }

    // enumerate params
    for (int i = 0; i < (0); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(0)];
    for (i = 0 ; i < (0); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (0+1)) {
        VALUE callback = argv[0];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
    }
    // check callback param
    if (argc >= (0+2)) {
        VALUE callback_param = argv[0+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setRubyCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_RhoConnectClient_setObjectNotification_caller setObjectNotification_in_thread:[rb_RhoConnectClient_setObjectNotification_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_RhoConnectClient_setObjectNotification_caller setObjectNotification:[rb_RhoConnectClient_setObjectNotification_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_s_RhoConnectClient_setObjectNotification(int argc, VALUE *argv) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return rb_RhoConnectClient_setObjectNotification_Obj(argc, argv, singleton);

}







@interface rb_RhoConnectClient_addObjectNotify_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(rb_RhoConnectClient_addObjectNotify_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_RhoConnectClient_addObjectNotify_caller_params

@synthesize params,item,methodResult;

+(rb_RhoConnectClient_addObjectNotify_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_RhoConnectClient_addObjectNotify_caller_params* par = [[rb_RhoConnectClient_addObjectNotify_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface rb_RhoConnectClient_addObjectNotify_caller : NSObject {

}
+(rb_RhoConnectClient_addObjectNotify_caller*) getSharedInstance;
+(void) addObjectNotify:(rb_RhoConnectClient_addObjectNotify_caller_params*)caller_params;
+(void) addObjectNotify_in_thread:(rb_RhoConnectClient_addObjectNotify_caller_params*)caller_params;
+(void) addObjectNotify_in_UI_thread:(rb_RhoConnectClient_addObjectNotify_caller_params*)caller_params;

@end

static rb_RhoConnectClient_addObjectNotify_caller* our_RhoConnectClient_addObjectNotify_caller = nil;

@implementation rb_RhoConnectClient_addObjectNotify_caller

+(rb_RhoConnectClient_addObjectNotify_caller*) getSharedInstance {
    if (our_RhoConnectClient_addObjectNotify_caller == nil) {
        our_RhoConnectClient_addObjectNotify_caller = [[rb_RhoConnectClient_addObjectNotify_caller alloc] init];
    }
    return our_RhoConnectClient_addObjectNotify_caller;
}

-(void) command_addObjectNotify:(rb_RhoConnectClient_addObjectNotify_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem addObjectNotify:(NSString*)[params objectAtIndex:0] object:(NSString*)[params objectAtIndex:1] ];
}

+(void) addObjectNotify:(rb_RhoConnectClient_addObjectNotify_caller_params*)caller_params {
    [[rb_RhoConnectClient_addObjectNotify_caller getSharedInstance] command_addObjectNotify:caller_params];
}

+(void) addObjectNotify_in_thread:(rb_RhoConnectClient_addObjectNotify_caller_params*)caller_params {
    [[rb_RhoConnectClient_addObjectNotify_caller getSharedInstance] performSelectorInBackground:@selector(command_addObjectNotify:) withObject:caller_params];
}

+(void) addObjectNotify_in_UI_thread:(rb_RhoConnectClient_addObjectNotify_caller_params*)caller_params {
    [[rb_RhoConnectClient_addObjectNotify_caller getSharedInstance] performSelectorOnMainThread:@selector(command_addObjectNotify:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_RhoConnectClient_addObjectNotify_Obj(int argc, VALUE *argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[2+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    
    BOOL is_factory_param[] = { NO, NO, NO };

    int i;

    // init
    for (i = 0; i < (2); i++) {
        params[i] = [NSNull null];
    }

    // enumerate params
    for (int i = 0; i < (2); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(2)];
    for (i = 0 ; i < (2); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (2+1)) {
        VALUE callback = argv[2];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
    }
    // check callback param
    if (argc >= (2+2)) {
        VALUE callback_param = argv[2+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setRubyCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_RhoConnectClient_addObjectNotify_caller addObjectNotify_in_thread:[rb_RhoConnectClient_addObjectNotify_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_RhoConnectClient_addObjectNotify_caller addObjectNotify:[rb_RhoConnectClient_addObjectNotify_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_s_RhoConnectClient_addObjectNotify(int argc, VALUE *argv) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return rb_RhoConnectClient_addObjectNotify_Obj(argc, argv, singleton);

}







@interface rb_RhoConnectClient_cleanObjectNotify_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(rb_RhoConnectClient_cleanObjectNotify_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_RhoConnectClient_cleanObjectNotify_caller_params

@synthesize params,item,methodResult;

+(rb_RhoConnectClient_cleanObjectNotify_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_RhoConnectClient_cleanObjectNotify_caller_params* par = [[rb_RhoConnectClient_cleanObjectNotify_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface rb_RhoConnectClient_cleanObjectNotify_caller : NSObject {

}
+(rb_RhoConnectClient_cleanObjectNotify_caller*) getSharedInstance;
+(void) cleanObjectNotify:(rb_RhoConnectClient_cleanObjectNotify_caller_params*)caller_params;
+(void) cleanObjectNotify_in_thread:(rb_RhoConnectClient_cleanObjectNotify_caller_params*)caller_params;
+(void) cleanObjectNotify_in_UI_thread:(rb_RhoConnectClient_cleanObjectNotify_caller_params*)caller_params;

@end

static rb_RhoConnectClient_cleanObjectNotify_caller* our_RhoConnectClient_cleanObjectNotify_caller = nil;

@implementation rb_RhoConnectClient_cleanObjectNotify_caller

+(rb_RhoConnectClient_cleanObjectNotify_caller*) getSharedInstance {
    if (our_RhoConnectClient_cleanObjectNotify_caller == nil) {
        our_RhoConnectClient_cleanObjectNotify_caller = [[rb_RhoConnectClient_cleanObjectNotify_caller alloc] init];
    }
    return our_RhoConnectClient_cleanObjectNotify_caller;
}

-(void) command_cleanObjectNotify:(rb_RhoConnectClient_cleanObjectNotify_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem cleanObjectNotify];
}

+(void) cleanObjectNotify:(rb_RhoConnectClient_cleanObjectNotify_caller_params*)caller_params {
    [[rb_RhoConnectClient_cleanObjectNotify_caller getSharedInstance] command_cleanObjectNotify:caller_params];
}

+(void) cleanObjectNotify_in_thread:(rb_RhoConnectClient_cleanObjectNotify_caller_params*)caller_params {
    [[rb_RhoConnectClient_cleanObjectNotify_caller getSharedInstance] performSelectorInBackground:@selector(command_cleanObjectNotify:) withObject:caller_params];
}

+(void) cleanObjectNotify_in_UI_thread:(rb_RhoConnectClient_cleanObjectNotify_caller_params*)caller_params {
    [[rb_RhoConnectClient_cleanObjectNotify_caller getSharedInstance] performSelectorOnMainThread:@selector(command_cleanObjectNotify:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_RhoConnectClient_cleanObjectNotify_Obj(int argc, VALUE *argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[0+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    
    BOOL is_factory_param[] = { NO };

    int i;

    // init
    for (i = 0; i < (0); i++) {
        params[i] = [NSNull null];
    }

    // enumerate params
    for (int i = 0; i < (0); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(0)];
    for (i = 0 ; i < (0); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (0+1)) {
        VALUE callback = argv[0];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
    }
    // check callback param
    if (argc >= (0+2)) {
        VALUE callback_param = argv[0+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setRubyCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_RhoConnectClient_cleanObjectNotify_caller cleanObjectNotify_in_thread:[rb_RhoConnectClient_cleanObjectNotify_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_RhoConnectClient_cleanObjectNotify_caller cleanObjectNotify:[rb_RhoConnectClient_cleanObjectNotify_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_s_RhoConnectClient_cleanObjectNotify(int argc, VALUE *argv) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return rb_RhoConnectClient_cleanObjectNotify_Obj(argc, argv, singleton);

}







@interface rb_RhoConnectClient_getLastSyncObjectCount_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(rb_RhoConnectClient_getLastSyncObjectCount_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_RhoConnectClient_getLastSyncObjectCount_caller_params

@synthesize params,item,methodResult;

+(rb_RhoConnectClient_getLastSyncObjectCount_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_RhoConnectClient_getLastSyncObjectCount_caller_params* par = [[rb_RhoConnectClient_getLastSyncObjectCount_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface rb_RhoConnectClient_getLastSyncObjectCount_caller : NSObject {

}
+(rb_RhoConnectClient_getLastSyncObjectCount_caller*) getSharedInstance;
+(void) getLastSyncObjectCount:(rb_RhoConnectClient_getLastSyncObjectCount_caller_params*)caller_params;
+(void) getLastSyncObjectCount_in_thread:(rb_RhoConnectClient_getLastSyncObjectCount_caller_params*)caller_params;
+(void) getLastSyncObjectCount_in_UI_thread:(rb_RhoConnectClient_getLastSyncObjectCount_caller_params*)caller_params;

@end

static rb_RhoConnectClient_getLastSyncObjectCount_caller* our_RhoConnectClient_getLastSyncObjectCount_caller = nil;

@implementation rb_RhoConnectClient_getLastSyncObjectCount_caller

+(rb_RhoConnectClient_getLastSyncObjectCount_caller*) getSharedInstance {
    if (our_RhoConnectClient_getLastSyncObjectCount_caller == nil) {
        our_RhoConnectClient_getLastSyncObjectCount_caller = [[rb_RhoConnectClient_getLastSyncObjectCount_caller alloc] init];
    }
    return our_RhoConnectClient_getLastSyncObjectCount_caller;
}

-(void) command_getLastSyncObjectCount:(rb_RhoConnectClient_getLastSyncObjectCount_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem getLastSyncObjectCount:(NSString*)[params objectAtIndex:0] methodResult:methodResult ];
}

+(void) getLastSyncObjectCount:(rb_RhoConnectClient_getLastSyncObjectCount_caller_params*)caller_params {
    [[rb_RhoConnectClient_getLastSyncObjectCount_caller getSharedInstance] command_getLastSyncObjectCount:caller_params];
}

+(void) getLastSyncObjectCount_in_thread:(rb_RhoConnectClient_getLastSyncObjectCount_caller_params*)caller_params {
    [[rb_RhoConnectClient_getLastSyncObjectCount_caller getSharedInstance] performSelectorInBackground:@selector(command_getLastSyncObjectCount:) withObject:caller_params];
}

+(void) getLastSyncObjectCount_in_UI_thread:(rb_RhoConnectClient_getLastSyncObjectCount_caller_params*)caller_params {
    [[rb_RhoConnectClient_getLastSyncObjectCount_caller getSharedInstance] performSelectorOnMainThread:@selector(command_getLastSyncObjectCount:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_RhoConnectClient_getLastSyncObjectCount_Obj(int argc, VALUE *argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[1+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    
    BOOL is_factory_param[] = { NO, NO };

    int i;

    // init
    for (i = 0; i < (1); i++) {
        params[i] = [NSNull null];
    }

    // enumerate params
    for (int i = 0; i < (1); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(1)];
    for (i = 0 ; i < (1); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (1+1)) {
        VALUE callback = argv[1];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
    }
    // check callback param
    if (argc >= (1+2)) {
        VALUE callback_param = argv[1+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setRubyCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_RhoConnectClient_getLastSyncObjectCount_caller getLastSyncObjectCount_in_thread:[rb_RhoConnectClient_getLastSyncObjectCount_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_RhoConnectClient_getLastSyncObjectCount_caller getLastSyncObjectCount:[rb_RhoConnectClient_getLastSyncObjectCount_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_s_RhoConnectClient_getLastSyncObjectCount(int argc, VALUE *argv) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return rb_RhoConnectClient_getLastSyncObjectCount_Obj(argc, argv, singleton);

}







@interface rb_RhoConnectClient_setSourceProperty_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(rb_RhoConnectClient_setSourceProperty_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_RhoConnectClient_setSourceProperty_caller_params

@synthesize params,item,methodResult;

+(rb_RhoConnectClient_setSourceProperty_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_RhoConnectClient_setSourceProperty_caller_params* par = [[rb_RhoConnectClient_setSourceProperty_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface rb_RhoConnectClient_setSourceProperty_caller : NSObject {

}
+(rb_RhoConnectClient_setSourceProperty_caller*) getSharedInstance;
+(void) setSourceProperty:(rb_RhoConnectClient_setSourceProperty_caller_params*)caller_params;
+(void) setSourceProperty_in_thread:(rb_RhoConnectClient_setSourceProperty_caller_params*)caller_params;
+(void) setSourceProperty_in_UI_thread:(rb_RhoConnectClient_setSourceProperty_caller_params*)caller_params;

@end

static rb_RhoConnectClient_setSourceProperty_caller* our_RhoConnectClient_setSourceProperty_caller = nil;

@implementation rb_RhoConnectClient_setSourceProperty_caller

+(rb_RhoConnectClient_setSourceProperty_caller*) getSharedInstance {
    if (our_RhoConnectClient_setSourceProperty_caller == nil) {
        our_RhoConnectClient_setSourceProperty_caller = [[rb_RhoConnectClient_setSourceProperty_caller alloc] init];
    }
    return our_RhoConnectClient_setSourceProperty_caller;
}

-(void) command_setSourceProperty:(rb_RhoConnectClient_setSourceProperty_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem setSourceProperty:(NSString*)[params objectAtIndex:0] propertyName:(NSString*)[params objectAtIndex:1] propertyValue:(NSString*)[params objectAtIndex:2] ];
}

+(void) setSourceProperty:(rb_RhoConnectClient_setSourceProperty_caller_params*)caller_params {
    [[rb_RhoConnectClient_setSourceProperty_caller getSharedInstance] command_setSourceProperty:caller_params];
}

+(void) setSourceProperty_in_thread:(rb_RhoConnectClient_setSourceProperty_caller_params*)caller_params {
    [[rb_RhoConnectClient_setSourceProperty_caller getSharedInstance] performSelectorInBackground:@selector(command_setSourceProperty:) withObject:caller_params];
}

+(void) setSourceProperty_in_UI_thread:(rb_RhoConnectClient_setSourceProperty_caller_params*)caller_params {
    [[rb_RhoConnectClient_setSourceProperty_caller getSharedInstance] performSelectorOnMainThread:@selector(command_setSourceProperty:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_RhoConnectClient_setSourceProperty_Obj(int argc, VALUE *argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[3+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    
    BOOL is_factory_param[] = { NO, NO, NO, NO };

    int i;

    // init
    for (i = 0; i < (3); i++) {
        params[i] = [NSNull null];
    }

    // enumerate params
    for (int i = 0; i < (3); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(3)];
    for (i = 0 ; i < (3); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (3+1)) {
        VALUE callback = argv[3];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
    }
    // check callback param
    if (argc >= (3+2)) {
        VALUE callback_param = argv[3+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setRubyCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_RhoConnectClient_setSourceProperty_caller setSourceProperty_in_thread:[rb_RhoConnectClient_setSourceProperty_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_RhoConnectClient_setSourceProperty_caller setSourceProperty:[rb_RhoConnectClient_setSourceProperty_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_s_RhoConnectClient_setSourceProperty(int argc, VALUE *argv) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return rb_RhoConnectClient_setSourceProperty_Obj(argc, argv, singleton);

}







@interface rb_RhoConnectClient_getSourceProperty_caller_params : NSObject

@property (assign) NSArray* params;
@property (assign) id<IRhoConnectClientSingleton> item;
@property (assign) CMethodResult* methodResult;

+(rb_RhoConnectClient_getSourceProperty_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult;

@end

@implementation rb_RhoConnectClient_getSourceProperty_caller_params

@synthesize params,item,methodResult;

+(rb_RhoConnectClient_getSourceProperty_caller_params*) makeParams:(NSArray*)_params _item:(id<IRhoConnectClientSingleton>)_item _methodResult:(CMethodResult*)_methodResult {
    rb_RhoConnectClient_getSourceProperty_caller_params* par = [[rb_RhoConnectClient_getSourceProperty_caller_params alloc] init];
    par.params = _params;
    par.item = _item;
    par.methodResult = _methodResult;
    return par;
}

@end


@interface rb_RhoConnectClient_getSourceProperty_caller : NSObject {

}
+(rb_RhoConnectClient_getSourceProperty_caller*) getSharedInstance;
+(void) getSourceProperty:(rb_RhoConnectClient_getSourceProperty_caller_params*)caller_params;
+(void) getSourceProperty_in_thread:(rb_RhoConnectClient_getSourceProperty_caller_params*)caller_params;
+(void) getSourceProperty_in_UI_thread:(rb_RhoConnectClient_getSourceProperty_caller_params*)caller_params;

@end

static rb_RhoConnectClient_getSourceProperty_caller* our_RhoConnectClient_getSourceProperty_caller = nil;

@implementation rb_RhoConnectClient_getSourceProperty_caller

+(rb_RhoConnectClient_getSourceProperty_caller*) getSharedInstance {
    if (our_RhoConnectClient_getSourceProperty_caller == nil) {
        our_RhoConnectClient_getSourceProperty_caller = [[rb_RhoConnectClient_getSourceProperty_caller alloc] init];
    }
    return our_RhoConnectClient_getSourceProperty_caller;
}

-(void) command_getSourceProperty:(rb_RhoConnectClient_getSourceProperty_caller_params*)caller_params {
    NSArray* params = caller_params.params;
    id<IRhoConnectClientSingleton> objItem = caller_params.item;
    CMethodResult* methodResult = caller_params.methodResult;

    
    [objItem getSourceProperty:(NSString*)[params objectAtIndex:0] propertyName:(NSString*)[params objectAtIndex:1] methodResult:methodResult ];
}

+(void) getSourceProperty:(rb_RhoConnectClient_getSourceProperty_caller_params*)caller_params {
    [[rb_RhoConnectClient_getSourceProperty_caller getSharedInstance] command_getSourceProperty:caller_params];
}

+(void) getSourceProperty_in_thread:(rb_RhoConnectClient_getSourceProperty_caller_params*)caller_params {
    [[rb_RhoConnectClient_getSourceProperty_caller getSharedInstance] performSelectorInBackground:@selector(command_getSourceProperty:) withObject:caller_params];
}

+(void) getSourceProperty_in_UI_thread:(rb_RhoConnectClient_getSourceProperty_caller_params*)caller_params {
    [[rb_RhoConnectClient_getSourceProperty_caller getSharedInstance] performSelectorOnMainThread:@selector(command_getSourceProperty:) withObject:caller_params waitUntilDone:NO];
}


@end


VALUE rb_RhoConnectClient_getSourceProperty_Obj(int argc, VALUE *argv, id<IRhoConnectClientSingleton>objItem) {

    CMethodResult* methodResult = [[CMethodResult alloc] init];

    NSObject* params[2+1];
    NSString* callbackURL = nil;
    NSString* callbackParam = nil;
    BOOL method_return_result = YES;
    
    BOOL is_factory_param[] = { NO, NO, NO };

    int i;

    // init
    for (i = 0; i < (2); i++) {
        params[i] = [NSNull null];
    }

    // enumerate params
    for (int i = 0; i < (2); i++) {
        if (argc > i) {
            // we have a [i] param !
            if (is_factory_param[i]) {
                params[i] = RhoConnectClient_makeInstanceByRubyObject(argv[i]);
            }
            else {
                params[i] = [[CRubyConverter convertFromRuby:argv[i]] retain];
            }
        }
    }

    NSMutableArray* params_array = [NSMutableArray arrayWithCapacity:(2)];
    for (i = 0 ; i < (2); i++) {
        [params_array addObject:params[i]];
    }

    
    // check callback
    if (argc >= (2+1)) {
        VALUE callback = argv[2];
        if (rho_ruby_is_string(callback)) {
            callbackURL = [((NSString*)[CRubyConverter convertFromRuby:callback]) retain];
        }
    }
    // check callback param
    if (argc >= (2+2)) {
        VALUE callback_param = argv[2+1];
        if (rho_ruby_is_string(callback_param)) {
            callbackParam = [((NSString*)[CRubyConverter convertFromRuby:callback_param]) retain];
        }
    }
    

    
    


    if (callbackURL != nil) {
        // we have callback - method should not call setResult if method execute from current thread - only later or in UI or separated threads !!!
        [methodResult setRubyCallback:callbackURL];
        if (callbackParam != nil) {
            [methodResult setCallbackParam:callbackParam];
        }
        
        [rb_RhoConnectClient_getSourceProperty_caller getSourceProperty_in_thread:[rb_RhoConnectClient_getSourceProperty_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    else {
        // we do not have callback
        
        [rb_RhoConnectClient_getSourceProperty_caller getSourceProperty:[rb_RhoConnectClient_getSourceProperty_caller_params makeParams:params_array _item:objItem _methodResult:methodResult]];
        
    }
    VALUE resValue = rho_ruby_get_NIL();
    if ((callbackURL == nil) && (method_return_result)) {
        resValue = [methodResult toRuby];
    }
    return resValue;
}


VALUE rb_s_RhoConnectClient_getSourceProperty(int argc, VALUE *argv) {

    id<IRhoConnectClientFactory> factory = [RhoConnectClientFactorySingleton getRhoConnectClientFactoryInstance];
    id<IRhoConnectClientSingleton> singleton = [factory getRhoConnectClientSingleton];
    return rb_RhoConnectClient_getSourceProperty_Obj(argc, argv, singleton);

}









