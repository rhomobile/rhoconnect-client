describe "RhoConnectClient_test" do
	before(:all)  do
		Rho::RhoConnectClient.sslVerifyPeer = true
		Rho::RhoConnectClient.threadedMode = false
	end
	
	it "should not connect to self signed SSL with enabled peer check" do
		Rho::RhoConnectClient.syncServer = 'https://ssl-test.rhohub.com'
		Rho::RhoConnectClient.sslVerifyPeer = true
		res =  Rho::RhoConnectClient.login('test', 'test', "/app/Settings/login_callback")
		res['error_code'].to_i.should == ::Rho::RhoError::ERR_NETWORK
	end
	
	it "should connect and get error from non-rhoconnect SSL server with disabled peer check" do
		Rho::RhoConnectClient.syncServer = 'https://ssl-test.rhohub.com'
		Rho::RhoConnectClient.sslVerifyPeer = false
		res =  Rho::RhoConnectClient.login('test', 'test', "/app/Settings/login_callback")
		res['error_code'].to_i.should == ::Rho::RhoError::ERR_NONE
	end

	it "should connect to trusted SSL server" do
		# TODO: implement
	end
end