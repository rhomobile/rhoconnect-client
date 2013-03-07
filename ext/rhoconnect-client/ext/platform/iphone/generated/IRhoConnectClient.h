
#import <Foundation/Foundation.h>

#import "api_generator/iphone/IMethodResult.h"








@protocol IRhoConnectClient <NSObject>





// NOTE: if you want to hold methodResult(for periodically call callback for example) you should release it buself when you stop using it !

@end


@protocol IRhoConnectClientSingleton <NSObject>




/* getter for "userName" property */
-(void) getUserName:(id<IMethodResult>)methodResult;

/* getter for "pollInterval" property */
-(void) getPollInterval:(id<IMethodResult>)methodResult;

/* setter for "pollInterval" property */
-(void) setPollInterval:(int)value;

/* getter for "syncServer" property */
-(void) getSyncServer:(id<IMethodResult>)methodResult;

/* setter for "syncServer" property */
-(void) setSyncServer:(NSString*)value;

/* getter for "pageSize" property */
-(void) getPageSize:(id<IMethodResult>)methodResult;

/* setter for "pageSize" property */
-(void) setPageSize:(int)value;

/* getter for "threadedMode" property */
-(void) getThreadedMode:(id<IMethodResult>)methodResult;

/* setter for "threadedMode" property */
-(void) setThreadedMode:(BOOL)value;

/* getter for "showStatusPopup" property */
-(void) getShowStatusPopup:(id<IMethodResult>)methodResult;

/* setter for "showStatusPopup" property */
-(void) setShowStatusPopup:(BOOL)value;

/* getter for "sslVerifyPeer" property */
-(void) getSslVerifyPeer:(id<IMethodResult>)methodResult;

/* setter for "sslVerifyPeer" property */
-(void) setSslVerifyPeer:(BOOL)value;

/* This is documentation */
-(void) loggedIn:(id<IMethodResult>)methodResult;

/* This is documentation */
-(void) syncing:(id<IMethodResult>)methodResult;

/* This is documentation */
-(void) search:(NSDictionary*)args methodResult:(id<IMethodResult>)methodResult;

/* This is documentation */
-(void) doSync:(BOOL)showStatusPopup queryParams:(NSString*)queryParams syncOnlyChangedSources:(BOOL)syncOnlyChangedSources methodResult:(id<IMethodResult>)methodResult;

/* This is documentation */
-(void) doSyncSource:(NSString*)sourceName showStatusPopup:(BOOL)showStatusPopup queryParams:(NSString*)queryParams methodResult:(id<IMethodResult>)methodResult;

/* This is documentation */
-(void) login:(NSString*)login password:(NSString*)password methodResult:(id<IMethodResult>)methodResult;

/* This is documentation */
-(void) logout;

/* This is documentation */
-(void) stopSync;

/* This is documentation */
-(void) setNotification:(NSString*)sourceName methodResult:(id<IMethodResult>)methodResult;

/* This is documentation */
-(void) clearNotification:(NSString*)sourceName;

/* This is documentation */
-(void) setObjectNotification:(id<IMethodResult>)methodResult;

/* This is documentation */
-(void) addObjectNotify:(NSString*)sourceName object:(NSString*)object;

/* This is documentation */
-(void) cleanObjectNotify;

/* This is documentation */
-(void) getLastSyncObjectCount:(NSString*)sourceName methodResult:(id<IMethodResult>)methodResult;

-(void) setSourceProperty:(NSString*)sourceName propertyName:(NSString*)propertyName propertyValue:(NSString*)propertyValue;

-(void) getSourceProperty:(NSString*)sourceName propertyName:(NSString*)propertyName methodResult:(id<IMethodResult>)methodResult;


@end


@protocol IRhoConnectClientFactory <NSObject>
-(id<IRhoConnectClientSingleton>) getRhoConnectClientSingleton;
-(id<IRhoConnectClient>) getRhoConnectClientByID:(NSString*)ID;
-(void) destroyObjectByID:(NSString*)ID;
@end


@interface RhoConnectClientFactorySingleton : NSObject {
}
+(id<IRhoConnectClientFactory>) getRhoConnectClientFactoryInstance;
@end


