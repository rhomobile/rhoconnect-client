
#import "RhoConnectClientFactoryBase.h"
#import "RhoConnectClient.h"
#import "RhoConnectClientSingleton.h"

@implementation RhoConnectClientFactoryBase

-(id)init {
    self = [super init];
    mRhoConnectClientInstances = [NSMutableDictionary dictionary];
    mRhoConnectClientSingleton = nil;
    return self;
}

-(id<IRhoConnectClient>) getRhoConnectClientByID:(NSString*)ID {
    RhoConnectClient* obj = [mRhoConnectClientInstances objectForKey:ID];
    if (obj == nil) {
        obj = [self createRhoConnectClientByID:ID];
        [mRhoConnectClientInstances setObject:obj forKey:ID];
    }
    return obj;
}

-(void) destroyObjectByID:(NSString*)ID {
    RhoConnectClient* obj = [mRhoConnectClientInstances objectForKey:ID];
    if (obj != nil) {
        [mRhoConnectClientInstances removeObjectForKey:ID];
    }
}


-(id<IRhoConnectClient>)createRhoConnectClientByID:(NSString*)ID {
    RhoConnectClient* obj = [[RhoConnectClient alloc] init];
    [obj setProperty:@"ID" propertyValue:ID];
    return obj;
}


-(id<IRhoConnectClientSingleton>) getRhoConnectClientSingleton {
    if (mRhoConnectClientSingleton == nil) {
        mRhoConnectClientSingleton = [[RhoConnectClientSingleton alloc] init];
    }
    return mRhoConnectClientSingleton;
}

-(void)dealloc {
    [mRhoConnectClientInstances release];
    [super dealloc];
}


@end