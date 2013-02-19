
#import "IRhoConnectClient.h"

@interface RhoConnectClientFactoryBase : NSObject<IRhoConnectClientFactory> {
    NSMutableDictionary* mRhoConnectClientInstances;
    id<IRhoConnectClientSingleton> mRhoConnectClientSingleton;
}

-(id)init;

-(id<IRhoConnectClientSingleton>) getRhoConnectClientSingleton;
-(id<IRhoConnectClient>) getRhoConnectClientByID:(NSString*)ID;

-(void) destroyObjectByID:(NSString*)ID;

-(id<IRhoConnectClient>)createRhoConnectClientByID:(NSString*)ID;

-(void)dealloc;

@end