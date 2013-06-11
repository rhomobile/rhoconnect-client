describe "RhoConnectClient_test" do
	before(:all)  do
		Rho::RhoConnectClient.threadedMode = false
	end
	
	it "should not connect to self signed SSL with enabled peer check" do
		Rho::RhoConnectClient.syncServer = 'https://nagios.rhomobile.com'
		Rho::RhoConnectClient.sslVerifyPeer = true
		res =  Rho::RhoConnectClient.login('test', 'test', "/app/Settings/login_callback")
		code = res['error_code'].to_i
		have_error = (code == ::Rho::RhoError::ERR_NETWORK) || (code == ::Rho::RhoError::ERR_REMOTESERVER )
		have_error.should == true
	end
	
	it "should connect and get error from non-rhoconnect SSL server with disabled peer check" do
		Rho::RhoConnectClient.syncServer = 'https://nagios.rhomobile.com'
		Rho::RhoConnectClient.sslVerifyPeer = false
		res =  Rho::RhoConnectClient.login('test', 'test', "/app/Settings/login_callback")
		res['error_code'].to_i.should == ::Rho::RhoError::ERR_UNATHORIZED
	end
end