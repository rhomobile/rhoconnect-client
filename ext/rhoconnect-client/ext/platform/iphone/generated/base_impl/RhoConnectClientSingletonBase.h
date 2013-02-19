

#import "IRhoConnectClient.h"

@interface RhoConnectClientSingletonBase : NSObject {
    NSString* mDefaultID;
}

-(id)init;

-(NSString*) getDefaultID;
-(void) setDefaultID:(NSString*)defaultID;

-(void)dealloc;

@end