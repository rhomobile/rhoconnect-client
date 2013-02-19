
#import "IRhoConnectClient.h"
#import "RhoConnectClientFactoryBase.h"

static RhoConnectClientFactoryBase* ourRhoConnectClientFactory = nil;

@implementation RhoConnectClientFactorySingleton

+(id<IRhoConnectClientFactory>) getRhoConnectClientFactoryInstance {
    if (ourRhoConnectClientFactory == nil) {
        ourRhoConnectClientFactory = [[RhoConnectClientFactoryBase alloc] init];
    }
    return ourRhoConnectClientFactory;
}

@end