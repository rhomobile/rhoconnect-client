describe "SyncEngine_test" do
	before(:all)  do
		SyncEngine.set_threaded_mode(false)
	end
	
	after(:all)  do
	end
	
	after (:each) do
		SyncEngine.set_ssl_verify_peer(true)
	end
	
	it "should not connect to self signed SSL with enabled peer check" do
		SyncEngine.set_syncserver('https://nagios.rhomobile.com/application')
		SyncEngine.set_ssl_verify_peer(true)
		res =  SyncEngine.login('test', 'test', "/app/Settings/login_callback")
		code = res['error_code'].to_i
		have_error = (code == ::Rho::RhoError::ERR_NETWORK) || (code == ::Rho::RhoError::ERR_REMOTESERVER )
		have_error.should == true
	end
	
	it "should connect and get error from non-rhoconnect SSL server with disabled peer check" do
		SyncEngine.set_syncserver('https://nagios.rhomobile.com/application')
		SyncEngine.set_ssl_verify_peer(false)
		res =  SyncEngine.login('test', 'test', "/app/Settings/login_callback")
		res['error_code'].to_i.should == ::Rho::RhoError::ERR_UNATHORIZED
	end
end