
#import "RhoConnectClientSingleton.h"


@implementation RhoConnectClientSingleton



-(void) getUserName:(id<IMethodResult>)methodResult {

}

-(void) getPollInterval:(id<IMethodResult>)methodResult {

}

-(void) setPollInterval:(int)value {

}

-(void) getSyncServer:(id<IMethodResult>)methodResult {

}

-(void) setSyncServer:(NSString*)value {

}

-(void) getPageSize:(id<IMethodResult>)methodResult {

}

-(void) setPageSize:(int)value {

}

-(void) getThreadedMode:(id<IMethodResult>)methodResult {

}

-(void) setThreadedMode:(BOOL)value {

}

-(void) getShowStatusPopup:(id<IMethodResult>)methodResult {

}

-(void) setShowStatusPopup:(BOOL)value {

}

-(void) getSslVerifyPeer:(id<IMethodResult>)methodResult {

}

-(void) setSslVerifyPeer:(BOOL)value {

}

-(void) loggedIn:(id<IMethodResult>)methodResult {

}

-(void) syncing:(id<IMethodResult>)methodResult {

}

-(void) onSyncCreateError:(NSString*)srcName objects:(NSArray*)objects action:(NSString*)action {

}

-(void) pushChanges:(NSString*)srcName {

}

-(void) onSyncUpdateError:(NSString*)srcName objects:(NSArray*)objects action:(NSString*)action rollbackData:(NSString*)rollbackData {

}

-(void) onSyncDeleteError:(NSString*)srcName objects:(NSArray*)objects action:(NSString*)action {

}

-(void) search:(NSDictionary*)args methodResult:(id<IMethodResult>)methodResult {

}

-(void) doSync:(BOOL)showStatusPopup queryParams:(NSString*)queryParams syncOnlyChangedSources:(BOOL)syncOnlyChangedSources methodResult:(id<IMethodResult>)methodResult {

}

-(void) doSyncSource:(NSString*)sourceName showStatusPopup:(BOOL)showStatusPopup queryParams:(NSString*)queryParams methodResult:(id<IMethodResult>)methodResult {

}

-(void) login:(NSString*)login password:(NSString*)password methodResult:(id<IMethodResult>)methodResult {

}

-(void) logout {

}

-(void) stopSync {

}

-(void) setNotification:(NSString*)sourceName methodResult:(id<IMethodResult>)methodResult {

}

-(void) clearNotification:(NSString*)sourceName {

}

-(void) setObjectNotification:(id<IMethodResult>)methodResult {

}

-(void) addObjectNotify:(NSString*)sourceName object:(NSString*)object {

}

-(void) cleanObjectNotify {

}

-(void) getLastSyncObjectCount:(NSString*)sourceName methodResult:(id<IMethodResult>)methodResult {

}

-(void) setSourceProperty:(NSString*)sourceName propertyName:(NSString*)propertyName propertyValue:(NSString*)propertyValue {

}

-(void) getSourceProperty:(NSString*)sourceName propertyName:(NSString*)propertyName methodResult:(id<IMethodResult>)methodResult {

}




@end