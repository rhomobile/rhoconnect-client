var sync_server_url = "http://"+SYNC_SERVER_HOST+":"+SYNC_SERVER_PORT;

describe("Rhoconnect Client module Test Starts Here", function() {

	var defaultPollInterval = Rho.RhoConnectClient.pollInterval;

	beforeEach(function() {
					
		});
		
	afterEach(function() {
				
    });
	
	   it("VT295-060 | sslVerifyPeer property when set to true when client has no SSL certificate | It should fail to connect and error code 1 should return", function() {
		     //Rho.RhoConnectClient.syncServer = 'https://nagios.rhomobile.com';
		});
		
	    it("VT295-061 | sslVerifyPeer property when set to false | It should fail to authorize and error code 9 should be returned", function() {
		     //Rho.RhoConnectClient.syncServer = 'https://nagios.rhomobile.com';
	
		});
		
		 it("VT295-062 | sslVerifyPeer property when set to true when client has SSL certificate | login should be successful(error code 0)", function() {
		     //Rho.RhoConnectClient.syncServer = 'https://nagios.rhomobile.com';
	
		});
	


	});