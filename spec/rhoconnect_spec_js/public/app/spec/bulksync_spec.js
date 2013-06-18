var sync_server_url = "http://"+SYNC_SERVER_HOST+":"+SYNC_SERVER_PORT;


describe("Rhoconnect Client module Test Starts Here", function() {

	var defaultPollInterval = Rho.RhoConnectClient.pollInterval;

	beforeEach(function() {
					
		});
		
	afterEach(function() {
			
    });
	
		//bulk sync test
		
	    it("VT295-095 | bulk sync functionality test  | Both of the orm model should get populated with server data.", function() {  
			 
			 
	
		});
		
		it("VT295-096 | Check bulk_status parameter in sync notification call back during bulk sync  | All state(start,download,change_db,ok,and complete)should be reported inside notification callback", function() {  
			 
			 
	
		});
		
		it("VT295-097 | Check current bulk sync partition  | current bulk sync partition should be reported in @params['partition']", function() {  
			 
			 
	
		});
		
		it("VT295-098 | bulk sync with record created in db  | Created record will be replaced with the latest set from the backend server.", function() {  
			 
			 
	
		});
		
		it("VT295-099 | Check bulksync_state after bulk sync  | it should set to 1 after successful bulk sync", function() {  
			 
			 
	
		});
		
		it("VT295-100 | Select none of the model for bulk sync | None of the orm model should get populated with server data.", function() {  
			 
			 //update_into_table() method
	
		});
		
		it("VT295-101 | Select only one model(product model) for bulk sync | Only Product model should get populated with server data", function() {  
			 
			 //update_into_table() method
	
		});
		
		it("VT295-102 | Select both model for bulk sync | Both of the orm model should get populated with server data", function() {  
			 
			 //update_into_table() method
	
		});
		
		it("VT295-103 | update_into_table( ) method with empty sources | It should throw an API syntax error", function() {  
			 
			 //update_into_table() method
	
		});
		
});		
		