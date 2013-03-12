#include "IRhoConnectClient.h"

namespace rho {


	class RhoConnectClientSingletonImpl : public IRhoConnectClient
	{
		virtual ~IRhoConnectClientSingleton(){}
		
		virtual void GetUserName(rho::apiGenerator::CMethodResult& oResult);
		virtual void OnSyncCreateError( const rho::StringW& srcName,  const rho::Vector<rho::StringW>& objects,  const rho::StringW& action, rho::apiGenerator::CMethodResult& oResult);
		virtual void PushChanges( const rho::StringW& srcName, rho::apiGenerator::CMethodResult& oResult) = 0;
		virtual void OnSyncUpdateError( const rho::StringW& srcName,  const rho::Vector<rho::StringW>& objects,  const rho::StringW& action,  const rho::StringW& rollbackData, rho::apiGenerator::CMethodResult& oResult) = 0;
		virtual void OnSyncDeleteError( const rho::StringW& srcName,  const rho::Vector<rho::StringW>& objects,  const rho::StringW& action, rho::apiGenerator::CMethodResult& oResult) = 0;
		virtual void Search( const rho::Hashtable<rho::StringW, rho::StringW>& args, rho::apiGenerator::CMethodResult& oResult) = 0;
		virtual void DoSync( bool showStatusPopup,  const rho::StringW& queryParams,  bool syncOnlyChangedSources, rho::apiGenerator::CMethodResult& oResult) = 0;
		virtual void DoSyncSource( int64 sourceId,  bool showStatusPopup,  const rho::StringW& queryParams, rho::apiGenerator::CMethodResult& oResult) = 0;
		virtual void DoSearch( const rho::Vector<rho::StringW>& arSources,  const rho::StringW& from,  const rho::StringW& params,  bool syncChanges,  int64 nProgressStep,  const rho::StringW& callback,  const rho::StringW& callbackParams, rho::apiGenerator::CMethodResult& oResult) = 0;
		virtual void Login( const rho::StringW& login,  const rho::StringW& password,  const rho::StringW& callback, rho::apiGenerator::CMethodResult& oResult) = 0;
		virtual void LoggedIn(rho::apiGenerator::CMethodResult& oResult) = 0;
		virtual void Logout(rho::apiGenerator::CMethodResult& oResult) = 0;
		virtual void StopSync(rho::apiGenerator::CMethodResult& oResult) = 0;
		virtual void SetNotification( int64 sourceId,  const rho::StringW& url,  const rho::StringW& params, rho::apiGenerator::CMethodResult& oResult) = 0;
		virtual void ClearNotification( int64 sourceId, rho::apiGenerator::CMethodResult& oResult) = 0;
		virtual void SetPollInterval( int64 interval, rho::apiGenerator::CMethodResult& oResult) = 0;
		virtual void GetPollInterval(rho::apiGenerator::CMethodResult& oResult) = 0;
		virtual void SetSyncServer( const rho::StringW& syncServer, rho::apiGenerator::CMethodResult& oResult) = 0;
		virtual void GetSourceAttributes( const rho::StringW& partition,  int64 sourceId, rho::apiGenerator::CMethodResult& oResult) = 0;
		virtual void SetObjectNotifyUrl( const rho::StringW& url, rho::apiGenerator::CMethodResult& oResult) = 0;
		virtual void AddObjectNotify( int64 sourceId,  const rho::StringW& object, rho::apiGenerator::CMethodResult& oResult) = 0;
		virtual void CleanObjectNotify(rho::apiGenerator::CMethodResult& oResult) = 0;
		virtual void GetLastSyncObjectCount( int64 sourceId, rho::apiGenerator::CMethodResult& oResult) = 0;
		virtual void GetPageSize(rho::apiGenerator::CMethodResult& oResult) = 0;
		virtual void SetPageSize( int64 pageSize, rho::apiGenerator::CMethodResult& oResult) = 0;
		virtual void SetThreadedMode( bool threadedModeEnabled, rho::apiGenerator::CMethodResult& oResult) = 0;
		virtual void EnableStatusPopup( bool statusPopupEnabled, rho::apiGenerator::CMethodResult& oResult) = 0;
		virtual void SetSourceProperty( int64 sourceId,  const rho::StringW& propertyName,  const rho::StringW& propertyValue, rho::apiGenerator::CMethodResult& oResult) = 0;
		virtual void GetSourceProperty( int64 sourceId,  const rho::StringW& propertyName, rho::apiGenerator::CMethodResult& oResult) = 0;
		virtual void SetSslVerifyPeer( bool verifyPeer, rho::apiGenerator::CMethodResult& oResult) = 0;
		virtual void IsSyncing(rho::apiGenerator::CMethodResult& oResult) = 0;
		virtual void RegisterPush(rho::apiGenerator::CMethodResult& oResult) = 0;
		
		
		virtual void addCommandToQueue(rho::common::IRhoRunnable* pFunctor) = 0;
		virtual void callCommandInThread(rho::common::IRhoRunnable* pFunctor) = 0;
		
	};
	
extern "C" void Init_RhoConnectClient_API();


}
