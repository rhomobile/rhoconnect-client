var displayflag = false;
var displayflag1 = false;
var callbackCalled = false;
var product_record_count = 0;
var customer_record_count = 0;
var loginCallback_paramsValue = [{ "error_code" : "" , "error_message" : "" }];
var searchCallback_paramsValue = [{ "status" : "" , "search_params" : "" }];
var myString=""; // for displaying sync parameter values and results
//var syncCallback_paramsValue = [in_progress { "in_progress" : "" , "error_message" : "" }];

var sync_server_url='http://localhost:9292/application';
//var Product = ORM.AddModel('Product'); 

describe("Rhoconnect Client module Test Starts Here", function() {
	beforeEach(function() {
					displayflag = false;
					displayflag1 = false;
					callbackCalled = false;
					product_record_count = 0;
					customer_record_count = 0;
					loginCallback_paramsValue.error_code="";
					loginCallback_paramsValue.error_message="";
					searchCallback_paramsValue.status="";
					searchCallback_paramsValue.search_params="";
					myString="";
					dispCurrentProcess(myString);
					//Rho.RhoConnectClient.pollInterval=0; // to avoid any unexpeced ocurance of sync 
					// reset values
		});
		
	afterEach(function() {
				displayflag = false;
				displayflag1 = false;
				callbackCalled = false;
				product_record_count = 0;
				customer_record_count = 0;
				loginCallback_paramsValue.error_code="";
				loginCallback_paramsValue.error_message="";
				searchCallback_paramsValue.status="";
				searchCallback_paramsValue.search_params="";
				myString="";
				Rho.RhoConnectClient.pollInterval=0; // to avoid any unexpeced ocurance of sync 
						//logre lated code
    });
	
	
	it("VT295-053 | pollInterval property default value test | 60", function() {
	      runs(function() {
	           expect(Rho.RhoConnectClient.pollInterval).toEqual(60);
	       });
	});
	
	it("VT295-005 | login to incorrect syncserver url | errorcode non zero", function() {
		Rho.RhoConnectClient.logout();  //make sure that client is logged out
		Rho.RhoConnectClient.syncServer = sync_server_url+'hello'; //incorrect syncserver url
		 runs(function () {
	            Rho.RhoConnectClient.login('testclient','testclient',callbackFunction);
	       });
		 
		 waitsFor(function () {
	            return callbackCalled;
	        },
	        "Timeout",
	        10000
	    );
     
	      runs(function() {
	           expect(Rho.RhoConnectClient.isLoggedIn()).toEqual(false);
	           expect(callbackCalled).toEqual(true);
	           expect(loginCallback_paramsValue.error_code).not.toEqual('0');
	           expect(loginCallback_paramsValue.error_message).not.toEqual("");
	       });
	});
	
	
	 it("VT295-001 | login to syncserver url with controller action URL Callback | errorcode 0", function() {
		Rho.RhoConnectClient.syncServer = sync_server_url;
		runs(function () {
            Rho.RhoConnectClient.login('testclient','testclient','../app/Settings/controller_login_callback');
       });
	 
		waitsFor(function () {
            return callbackCalled;
        },
        "Timeout",
        10000
      );
      runs(function() {
           expect(Rho.RhoConnectClient.isLoggedIn()).toEqual(true);
           expect(callbackCalled).toEqual(true);
       });
	}); 
	

	it("VT295-002 | login to syncserver url with Anonymous callback function | errorcode 0", function() {
		Rho.RhoConnectClient.logout();  //make sure that client is logged out
		Rho.RhoConnectClient.syncServer = sync_server_url;
		runs(function () {
            Rho.RhoConnectClient.login('testclient','testclient',function(result){
            	   callbackFunction(result);
            	});
       });
	 
		waitsFor(function () {
            return callbackCalled;
        },
        "Timeout",
        6000
    );
 
      runs(function() {
           expect(Rho.RhoConnectClient.isLoggedIn()).toEqual(true);
           expect(callbackCalled).toEqual(true);
           expect(loginCallback_paramsValue.error_code).toEqual('0');
           expect(loginCallback_paramsValue.error_message).toEqual("");
       });
	});

	it("VT295-003 | login to syncserver url with function  callback | errorcode 0", function() {
			Rho.RhoConnectClient.logout();  //make sure that client is logged out
			Rho.RhoConnectClient.syncServer = sync_server_url;
			 runs(function () {
		            Rho.RhoConnectClient.login('testclient','testclient',callbackFunction);
		       });
			 
			 waitsFor(function () {
		            return callbackCalled;
		        },
		        "Timeout",
		        6000
		    );
	     
		      runs(function() {
		           expect(Rho.RhoConnectClient.isLoggedIn()).toEqual(true);
		           expect(callbackCalled).toEqual(true);
		           expect(loginCallback_paramsValue.error_code).toEqual('0');
		           expect(loginCallback_paramsValue.error_message).toEqual("");
		       });
		});
		
		
		it("VT295-004 | Get sync server url value | sync_server_url", function() {
			Rho.RhoConnectClient.syncServer = sync_server_url;
		      runs(function() {
		           expect(Rho.RhoConnectClient.syncServer).toEqual(sync_server_url);
		       });
		});
		
		it("VT295-007 | Call isLoggedIn() when client is  logged in to server | true", function() {
		    runs(function() {
		           expect(Rho.RhoConnectClient.isLoggedIn()).toEqual(true);
		       });
		});
		
		it("VT295-008 | Get username when user is logged in | string", function() {     
			 runs(function() {
		           expect(Rho.RhoConnectClient.userName).toEqual('testclient');
		       });
		});
		
		it("VT295-011 | set notification for specific source model | Notification callback should fire", function() {  
			dbreset();
			Rho.RhoConnectClient.setNotification('Product', sync_notify_callback);
			 runs(function () {
		            Rho.RhoConnectClient.doSync();
		            setTimeout(function() {
						displayflag = true;
					}, 15000);
		       });
			 
			  waitsFor(function() {
					return displayflag;
				}, "wait", 16000);
			
			 
			 runs(function() {
		    	  expect(callbackCalled).toEqual(true);
		    	  expect(product_record_count).toBeGreaterThan(0);
		    	  expect(customer_record_count).toBeGreaterThan(0);
		    	  dispCurrentProcess(myString);
		       });
		});
		
		
		it("VT295-012 | Check persistency of notification callback when set for specific source model | Notification callback should not fire", function() {  
			Rho.RhoConnectClient.setNotification('Product', sync_notify_callback);
			 runs(function () {
		            Rho.RhoConnectClient.doSync();
		            setTimeout(function() {
						displayflag = true;
					}, 15000);
		       });
			 
			  waitsFor(function() {
					return displayflag;
				}, "wait", 16000);
			  
			  runs(function () {
				    callbackCalled = false;  //setting callback to false again for checking persistency
		            Rho.RhoConnectClient.doSync();
		            setTimeout(function() {
						displayflag = true;
					}, 15000);
		       });
			 
			  waitsFor(function() {
					return displayflag;
				}, "wait", 16000);
			
			 
			 runs(function() {
		    	  expect(callbackCalled).toEqual(true);
		       });
		});
		
		
		it("VT295-013 | clear notification for specific source model | callback should not fire", function() {  
			Rho.RhoConnectClient.setNotification('Product', sync_notify_callback);
			Rho.RhoConnectClient.clearNotification('Product');
			 runs(function () {
		            Rho.RhoConnectClient.doSync();
		            setTimeout(function() {
						displayflag = true;
					}, 15000);
		       });
			 
			  waitsFor(function() {
					return displayflag;
				}, "wait", 16000);
			
			 
			 runs(function() {
		    	  expect(callbackCalled).toEqual(false);
		    	  expect(myString).toEqual('');
		    	  //alert(myString);
		       });
		});
		
		
		it("VT295-014 | set notification for all sources with  controller action URL callback | callback should get fire", function() {  
			dbreset();
			Rho.RhoConnectClient.setNotification('*', '/app/Settings/controller_syncnotify_callback');
			 runs(function () {
		            Rho.RhoConnectClient.doSync();
		            setTimeout(function() {
						displayflag = true;
					}, 15000);
		       });
			 
			  waitsFor(function() {
				   dispCurrentProcess(myString);
					return displayflag;
				}, "wait", 16000);
			
			  runs(function() {
		    	   modelrecordtest();
		    	   setTimeout(function() {
						displayflag1 = true;
					}, 5000);
		      	 
		       });
			  
		       waitsFor(function() {
					return displayflag1;
				}, "wait", 6000);
			 
			 runs(function() {
		    	  expect(callbackCalled).toEqual(true);
		    	  expect(product_record_count).toBeGreaterThan(0);
		    	  expect(customer_record_count).toBeGreaterThan(0);
		       });
		});
		
		
		it("VT295-015 | clear notification for all sources  | callback should not fire", function() {  
			Rho.RhoConnectClient.setNotification('*', sync_notify_callback);
			Rho.RhoConnectClient.clearNotification('*');
			 runs(function () {
		            Rho.RhoConnectClient.doSync();
		            setTimeout(function() {
						displayflag = true;
					}, 10000);
		       });
			 
			  waitsFor(function() {
					return displayflag;
				}, "wait", 11000);
			
			 
			 runs(function() {
		    	  expect(callbackCalled).toEqual(false);
		    	  expect(myString).toEqual('');
		       });
		});
		
		
		it("VT295-016 | Check persistency of notification callback when set for all sources  | callback should fire each time", function() {  
			Rho.RhoConnectClient.setNotification('*', sync_notify_callback);
			 runs(function () {
		            Rho.RhoConnectClient.doSync();
		            setTimeout(function() {
						displayflag = true;
					}, 10000);
		       });
			 
			  waitsFor(function() {
					return displayflag;
				}, "wait", 11000);
			  
			  runs(function () {
				   callbackCalled = false;  //for checking persistency
		            Rho.RhoConnectClient.doSync();
		            setTimeout(function() {
						displayflag = true;
					}, 10000);
		       });
			 
			  waitsFor(function() {
					return displayflag;
				}, "wait", 11000);
			
			 
			 runs(function() {
		    	  expect(callbackCalled).toEqual(false);
		    	  expect(myString).toEqual('');
		       });
		});
		
		
		it("VT295-017 | set notification with with Anonymous callback function | callback should get fire", function() {  
			dbreset();
			Rho.RhoConnectClient.setNotification('*', function(args) {
				sync_notify_callback(args);
			});
			 runs(function () {
		            Rho.RhoConnectClient.doSync();
		            setTimeout(function() {
						displayflag = true;
					}, 15000);
		       });
			 
			  waitsFor(function() {
		    	    dispCurrentProcess(myString);
					return displayflag;
				}, "wait", 16000);
			
			  runs(function() {
		    	   modelrecordtest();
		    	   setTimeout(function() {
						displayflag1 = true;
					}, 5000);
		      	 
		       });
			  
		       waitsFor(function() {
					return displayflag1;
				}, "wait", 6000);
			 
			 runs(function() {
		    	  expect(callbackCalled).toEqual(true);
		    	  expect(product_record_count).toBeGreaterThan(0);
		    	  expect(customer_record_count).toBeGreaterThan(0);
		       });
		});
		
		
		it("VT295-018 | set notification with with function callback. | callback should get fire", function() {  
			dbreset();
			Rho.RhoConnectClient.setNotification('*', sync_notify_callback);
			 runs(function () {
		            Rho.RhoConnectClient.doSync();
		            setTimeout(function() {
						displayflag = true;
					}, 15000);
		       });
			 
			  waitsFor(function() {
		    	    dispCurrentProcess(myString);
					return displayflag;
				}, "wait", 16000);
			
			  runs(function() {
		    	   modelrecordtest();
		    	   setTimeout(function() {
						displayflag1 = true;
					}, 5000);
		      	 
		       });
			  
		       waitsFor(function() {
					return displayflag1;
				}, "wait", 6000);
			 
			 runs(function() {
		    	  expect(callbackCalled).toEqual(true);
		    	  expect(product_record_count).toBeGreaterThan(0);
		    	  expect(customer_record_count).toBeGreaterThan(0);
		    	  //alert(myString);
		       });
		});
		
		
		it("VT295-023 | doSync() with syncOnlyChangedSources set to True | only changed source will get sync", function() {  
			dbreset();
			Rho.RhoConnectClient.setNotification('*', sync_notify_callback);
			create_product_record(1,"VT295-023");
			 runs(function () {
		            Rho.RhoConnectClient.doSync(false,'',true);
		            setTimeout(function() {
						displayflag = true;
					}, 15000);
		       });
			 
			  waitsFor(function() {
				  dispCurrentProcess(myString);
					return displayflag;
				}, "wait", 16000);
			
			  runs(function() {
		    	   modelrecordtest();
		    	   setTimeout(function() {
						displayflag1 = true;
					}, 5000);
		      	 
		       });
			  
		       waitsFor(function() {
					return displayflag1;
				}, "wait", 6000);
			 
			 runs(function() {
		    	  expect(callbackCalled).toEqual(true);
		    	  expect(product_record_count).toBeGreaterThan(0);
		    	  expect(customer_record_count).toEqual(0);
		    	  //alert(myString);
		       });
		});
		
		
		it("VT295-024 | doSync() with syncOnlyChangedSources set to False | all source will get sync", function() {  
			dbreset();
			Rho.RhoConnectClient.setNotification('*', sync_notify_callback);
			create_product_record(1,"VT295-024");
			 runs(function () {
		            Rho.RhoConnectClient.doSync(false,'',false);
		            setTimeout(function() {
						displayflag = true;
					}, 15000);
		       });
			 
			  waitsFor(function() {
				   dispCurrentProcess(myString);
					return displayflag;
				}, "wait", 16000);
			
			  runs(function() {
		    	   modelrecordtest();
		    	   setTimeout(function() {
						displayflag1 = true;
					}, 5000);
		      	 
		       });
			  
		       waitsFor(function() {
					return displayflag1;
				}, "wait", 6000);
			 
			 runs(function() {
		    	  expect(callbackCalled).toEqual(true);
		    	  expect(product_record_count).toBeGreaterThan(0);
		    	  expect(customer_record_count).toBeGreaterThan(0);
		    	  //alert(myString);
		       });
		});
	
		
		
		it("VT295-028 | doSync () method with all param is empty | Exception should be thrown", function() {  
			 var Exception_Message = "";
			 runs(function () {
			 try
			  {
		            Rho.RhoConnectClient.doSync("","","");
			  }
			 catch(ex)
			  {
			     Exception_Message = ex.message;	
			  }
		      });
             
			 expect(Exception_Message).toMatch("argument error exception");
	
		}); 
		
		
		
		it("VT295-029 | getLastSyncObjectCount method after resetting the DB | Number of server records", function() {  
			dbreset();
			 runs(function () {
		            Rho.RhoConnectClient.doSync();
		            setTimeout(function() {
						displayflag = true;
					}, 15000);
		       });
			 
			  waitsFor(function() {
					return displayflag;
				}, "wait", 16000);
			 
			 runs(function() {
		    	  expect(Rho.RhoConnectClient.getLastSyncObjectCount('Product')).toBeGreaterThan(0);
		    	  expect(Rho.RhoConnectClient.getLastSyncObjectCount('Customer')).toBeGreaterThan(0);
		    	  //alert(myString);
		       });
		});
		
		
		it("VT295-030 | getLastSyncObjectCount method after creating records | 2 ", function() {  
			create_product_record(2,"VT295-030");
			create_customer_record(2,"VT295-030");
			 runs(function () {
		            Rho.RhoConnectClient.doSync();
		            setTimeout(function() {
						displayflag = true;
					}, 15000);
		       });
			 
			  waitsFor(function() {
					return displayflag;
				}, "wait", 16000);
			 
			 runs(function() {
		    	  expect(Rho.RhoConnectClient.getLastSyncObjectCount('Product')).toEqual(2);
		    	  expect(Rho.RhoConnectClient.getLastSyncObjectCount('Customer')).toEqual(2);
		    	  //alert(myString);
		       });
		});
		
		it("VT295-031 | getLastSyncObjectCount method after updating records | 2 ", function() {  
			update_product_record("VT295-030","VT295-031");
			update_customer_record("VT295-030","VT295-031");
			 runs(function () {
		            Rho.RhoConnectClient.doSync();
		            setTimeout(function() {
						displayflag = true;
					}, 15000);
		       });
			 
			  waitsFor(function() {
					return displayflag;
				}, "wait", 16000);
			 
			 runs(function() {
		    	  expect(Rho.RhoConnectClient.getLastSyncObjectCount('Product')).toEqual(2);
		    	  expect(Rho.RhoConnectClient.getLastSyncObjectCount('Customer')).toEqual(2);
		    	  //alert(myString);
		       });
		});
		
		
		it("VT295-032 | getLastSyncObjectCount method after deleting records | 2 ", function() {  
			delete_product_record("VT295-031");
			delete_customer_record("VT295-031");
			 runs(function () {
		            Rho.RhoConnectClient.doSync();
		            setTimeout(function() {
						displayflag = true;
					}, 15000);
		       });
			 
			  waitsFor(function() {
					return displayflag;
				}, "wait", 16000);
			 
			 runs(function() {
		    	  expect(Rho.RhoConnectClient.getLastSyncObjectCount('Product')).toEqual(2);
		    	  expect(Rho.RhoConnectClient.getLastSyncObjectCount('Customer')).toEqual(2);
		    	  //alert(myString);
		       });
		});
		
		
		it("VT295-033 | getLastSyncObjectCount method without parameter | Exception should be thrown", function() {  
			 var Exception_Message = "";
			 runs(function () {
			 try
			  {
				  Rho.RhoConnectClient.getLastSyncObjectCount();
			  }
			 catch(ex)
			  {
			     Exception_Message = ex.message;	
			  }
		      });
            
			 expect(Exception_Message).toMatch("argument error exception");
	
		});
		
		it("VT295-034 | isSyncing() method when sync is in progress | true ", function() {  
			 runs(function () {
		            Rho.RhoConnectClient.doSync();
		       });
			 
			 runs(function() {
		    	  expect(Rho.RhoConnectClient.isSyncing()).toEqual(true);
		       });
		});
		
		it("VT295-035 | isSyncing() method when sync is not in progress | False ", function() {  
			 setTimeout(function() {
					displayflag = true;
				}, 15000);
			 waitsFor(function() {
					return displayflag;
				}, "wait", 16000);
			 runs(function() {
		    	  expect(Rho.RhoConnectClient.isSyncing()).toEqual(false);
		       });
		});
		
		it("VT295-036 | stopSync() method | Number of server records", function() {  
			dbreset();
			 runs(function () {
		            Rho.RhoConnectClient.doSync();
		            Rho.RhoConnectClient.stopSync();
		       });
			 
			 runs(function() {
		    	   modelrecordtest();
		    	   setTimeout(function() {
						displayflag1 = true;
					}, 5000);
		      	 
		       });
			  
		       waitsFor(function() {
					return displayflag1;
				}, "wait", 6000);
			 
			 runs(function() {
		    	  expect(product_record_count).toEqual(0);
		    	  expect(customer_record_count).toEqual(0);
		       });
		});
		
		
		it("VT295-037 | Sync the sources after calling stopSync() method.", function() {  
			dbreset();
			 runs(function () {
		            Rho.RhoConnectClient.doSync();
		            Rho.RhoConnectClient.stopSync();
		            Rho.RhoConnectClient.doSync();
		            setTimeout(function() {
						displayflag = true;
					}, 15000);
		       });
			 
			  waitsFor(function() {
					return displayflag;
				}, "wait", 16000);
			 
			 runs(function() {
		    	   modelrecordtest();
		    	   setTimeout(function() {
						displayflag1 = true;
					}, 5000);
		       });
			 
		       waitsFor(function() {
					return displayflag1;
				}, "wait", 6000);
			 
			 runs(function() {
		    	  expect(product_record_count).toBeGreaterThan(0);
		    	  expect(customer_record_count).toBeGreaterThan(0);
		       });
		});
		
		it("VT295-040 | doSyncSource method with empty parameters | Exception should be thrown", function() {  
			 var Exception_Message = "";
			 runs(function () {
			 try
			  {
				  Rho.RhoConnectClient.doSyncSource();
			  }
			 catch(ex)
			  {
			    Exception_Message =	ex.message;	
			  }
		      });
           
			 expect(Exception_Message).toMatch("argument error exception");
	
		});

		
		// search() method related spec and make sure that more than 5 records (VT295-041) exist at backend server.
		
		it("VT295-041 | search method for all sources with controller action URL Callback | Callback should fire and model should populate ", function() {  
			dbreset();
			 runs(function () {
				 Rho.RhoConnectClient.search( { sourceNames : ['Product'], from : 'search', searchParams : { sku : 'VT295-041'}, offset : 0 }, '/app/Settings/controller_search_callback');
				 });
			  waitsFor(function() {
					return callbackCalled;
				}, "timeout", 10000);
			  
			  runs(function () {
				    callbackCalled =false; // setting false again here since will get true in search block
				    Rho.RhoConnectClient.search( { sourceNames : ['Customer'], from :'search', searchParams : { first :'VT295-041'}, offset : 0 }, '/app/Settings/controller_search_callback');
					 });
			    waitsFor(function() {
						return callbackCalled;
					}, "timeout", 10000);
			    
			  runs(function() {
		    	   modelrecordtest();
		    	   setTimeout(function() {
						displayflag1 = true;
					}, 5000);
		      	 
		       });
			  
		       waitsFor(function() {
					return displayflag1;
				}, "wait", 6000);
			 
			 runs(function() {
				  expect(callbackCalled).toEqual(true);
		    	  expect(product_record_count).toBeGreaterThan(0);
		    	  expect(customer_record_count).toBeGreaterThan(0);
		       });
		});
		
		
		it("VT295-042 | search method for all sources with with Anonymous callback function | Callback should fire and model should populate", function() {  
			dbreset();
			 runs(function () {
				 Rho.RhoConnectClient.search( { sourceNames : ['Product'], from : 'search', searchParams : { sku : 'VT295-041'}, offset : 0 }, function(result){
					 search_callback(result); });
				 });
			  waitsFor(function() {
					return callbackCalled;
				}, "timeout", 10000);
			  
			  runs(function () {
				    callbackCalled =false; // setting false again here since will get true in search block
					 Rho.RhoConnectClient.search( { sourceNames : ['Customer'], from : 'search', searchParams : { sku : 'VT295-041'}, offset : 0 }, function(result){
						 search_callback(result); });
					 });
			    waitsFor(function() {
						return callbackCalled;
					}, "timeout", 10000);
			  
			  runs(function() {
		    	   modelrecordtest();
		    	   setTimeout(function() {
						displayflag1 = true;
					}, 5000);
		      	 
		       });
		       waitsFor(function() {
					return displayflag1;
				}, "wait", 6000);
			 
			 runs(function() {
		    	  expect(callbackCalled).toEqual(true);
		    	  expect(product_record_count).toBeGreaterThan(0);
		    	  expect(customer_record_count).toBeGreaterThan(0);
		    	  expect(searchCallback_paramsValue.status).toMatch('complete');
		    	  expect(searchCallback_paramsValue.search_params).not.toBeNull();
		       });
		});
		
		
		it("VT295-043 | search method for all sources with with function callback | Callback should fire and model should populate", function() {  
			dbreset();
			 runs(function () {
				 Rho.RhoConnectClient.search( { sourceNames : ['Product'], from : 'search', searchParams : { sku : 'VT295-041'}, offset : 0 }, search_callback );
				 });
			  waitsFor(function() {
					return callbackCalled;
				}, "timeout", 10000);
			  
			  runs(function () {
				    callbackCalled =false; // setting false again here since will get true in search block
					 Rho.RhoConnectClient.search( { sourceNames : ['Customer'], from : 'search', searchParams : { sku : 'VT295-041'}, offset : 0 }, search_callback);
					 });
			    waitsFor(function() {
						return callbackCalled;
					}, "timeout", 10000);
			  
			  runs(function() {
		    	   modelrecordtest();
		    	   setTimeout(function() {
						displayflag1 = true;
					}, 5000);
		      	 
		       });
		       waitsFor(function() {
					return displayflag1;
				}, "wait", 6000);
			 
			 runs(function() {
		    	  expect(callbackCalled).toEqual(true);
		    	  expect(product_record_count).toBeGreaterThan(0);
		    	  expect(customer_record_count).toBeGreaterThan(0);
		    	  expect(searchCallback_paramsValue.status).toMatch('complete');
		    	  expect(searchCallback_paramsValue.search_params).not.toBeNull();
		       });
		});
		
		
		it("VT295-045 | Search method when :from parameter is set to non default source adapter method | Callback should fire and model should populate", function() {  
			dbreset();
			 runs(function () {
				 Rho.RhoConnectClient.search( { sourceNames : ['Product'], from : 'user_product_search', searchParams : { sku : 'VT295-041'}, offset : 0 }, search_callback );
				 });
			  waitsFor(function() {
					return callbackCalled;
				}, "timeout", 10000);
			  	  
			  runs(function() {
		    	   modelrecordtest();
		    	   setTimeout(function() {
						displayflag1 = true;
					}, 5000);
		      	 
		       });
		       waitsFor(function() {
					return displayflag1;
				}, "wait", 6000);
			 
			 runs(function() {
		    	  expect(callbackCalled).toEqual(true);
		    	  expect(product_record_count).toBeGreaterThan(0);
		    	  expect(customer_record_count).toEqual(0);
		    	  expect(searchCallback_paramsValue.status).toMatch('complete');
		    	  expect(searchCallback_paramsValue.search_params).not.toBeNull();
		       });
		});
		
		it("VT295-046 | search method if backend server has more records than max_results  ", function() {  
			dbreset();
			 runs(function () {
				 Rho.RhoConnectClient.search( { sourceNames : ['Product'], from : 'search', searchParams : { sku : 'VT295-041'}, offset : 0, maxResults : 5 }, search_callback );
				 });
			  waitsFor(function() {
					return callbackCalled;
				}, "timeout", 10000);
			  	  
			  runs(function() {
		    	   modelrecordtest();
		    	   setTimeout(function() {
						displayflag1 = true;
					}, 5000);
		      	 
		       });
		       waitsFor(function() {
					return displayflag1;
				}, "wait", 6000);
			 
			 runs(function() {
		    	  expect(callbackCalled).toEqual(true);
		    	  expect(product_record_count).toEqual(5);
		    	  expect(searchCallback_paramsValue.status).toMatch('complete');
		    	  expect(searchCallback_paramsValue.search_params).not.toBeNull();
		       });
		});
		
		it("VT295-047 | search method if sync_changes set to true", function() {  
			dbreset();
			 runs(function () {
				 create_product_record(1,"VT295-047");
				 Rho.RhoConnectClient.search( { sourceNames : ['Product'], from : 'search', searchParams : { sku : 'VT295-041'}, offset : 0, maxResults : 5, syncChanges : true }, search_callback );
				 });
			  waitsFor(function() {
					return callbackCalled;
				}, "timeout", 10000);
			  	  
			  runs(function() {
		    	   modelrecordtest();
		    	   setTimeout(function() {
						displayflag1 = true;
					}, 5000);
		      	 
		       });
		       waitsFor(function() {
					return displayflag1;
				}, "wait", 6000);
			 
			 runs(function() {
		    	  expect(callbackCalled).toEqual(true);
		    	  expect(product_record_count).toEqual(5);
		    	  expect(searchCallback_paramsValue.status).toMatch('complete');
		    	  expect(searchCallback_paramsValue.search_params).not.toBeNull();
		    	  expect(Rho.ORM.haveLocalChanges).toEqual(false);
		       });
		});
		
		it("VT295-048 | search method if sync_changes set to false", function() {  
			dbreset();
			 runs(function () {
				 create_product_record(1,"VT295-047");
				 Rho.RhoConnectClient.search( { sourceNames : ['Product'], from : 'search', searchParams : { sku : 'VT295-041'}, offset : 0, maxResults : 5, syncChanges : false }, search_callback );
				 });
			  waitsFor(function() {
					return callbackCalled;
				}, "timeout", 10000);
			  	  
			  runs(function() {
		    	   modelrecordtest();
		    	   setTimeout(function() {
						displayflag1 = true;
					}, 5000);
		      	 
		       });
		       waitsFor(function() {
					return displayflag1;
				}, "wait", 6000);
			 
			 runs(function() {
		    	  expect(callbackCalled).toEqual(true);
		    	  expect(product_record_count).toEqual(5);
		    	  expect(searchCallback_paramsValue.status).toMatch('complete');
		    	  expect(searchCallback_paramsValue.search_params).not.toBeNull();
		    	  expect(Rho.ORM.haveLocalChanges).toEqual(true);
		       });
		});
		
		
		it("VT295-049 | search method with no parameters | Exception should be thrown", function() {  
			 var Exception_Message = "";
			 runs(function () {
			 try
			  {
				  Rho.RhoConnectClient.search();
			  }
			 catch(ex)
			  {
			    Exception_Message =	ex.message;	
			  }
		      });
          
			 expect(Exception_Message).toMatch("argument error exception");
	
		});
		
		it("VT295-054 | pollInterval property when set to 30 seconds | call back should fire after each 30 seconds ", function() {  
			Rho.RhoConnectClient.pollInterval= 30;
			Rho.RhoConnectClient.setNotification('*', sync_notify_callback);
			runs(function () {
	            setTimeout(function() {
					displayflag = true;
				}, 30000);
	        });
		   waitsFor(function() {
				return displayflag;
			}, "wait", 31000);
		   
		   runs(function() {
		    	  expect(callbackCalled).toEqual(true);
		    	  callbackCalled=false;
		       });
			runs(function () {
	            setTimeout(function() {
					displayflag = true;
				}, 30000);
	        });
		   waitsFor(function() {
				return displayflag;
			}, "wait", 31000);
		   
			 runs(function() {
		    	  expect(callbackCalled).toEqual(true);
		       });
		});
		
		
		it("VT295-055 | pollInterval property when set to 0 seconds | call back should not get fire  ", function() {  
			Rho.RhoConnectClient.pollInterval=0;
			Rho.RhoConnectClient.setNotification('*', sync_notify_callback);
			runs(function () {
	            setTimeout(function() {
					displayflag = true;
				}, 60000);
	        });
		   waitsFor(function() {
				return displayflag;
			}, "wait", 61000);
			 runs(function() {
		    	  expect(callbackCalled).toEqual(false);
		       });
		});
			
		it("VT295-056 | Check sync method when pollInterval property  set to 0 seconds | call back should get fire  ", function() {  
			dbreset();
			Rho.RhoConnectClient.pollInterval=0;
			Rho.RhoConnectClient.setNotification('*', sync_notify_callback);
				runs(function () {
		            Rho.RhoConnectClient.doSync();
		            setTimeout(function() {
						displayflag = true;
					}, 15000);
		       });
		 
			  waitsFor(function() {
					return displayflag;
				}, "wait", 16000);
		  
			  runs(function() {
		    	   modelrecordtest();
		    	   setTimeout(function() {
						displayflag1 = true;
					}, 5000);
		      	 
		       });
		       waitsFor(function() {
					return displayflag1;
				}, "wait", 6000);
			 
			 runs(function() {
		    	  expect(callbackCalled).toEqual(true);
		    	  expect(product_record_count).toBeGreaterThan(0);
		    	  expect(customer_record_count).toBeGreaterThan(0);
		       });

		});
		
		
		it("VT295-057 | pageSize property default value test | 2000", function() {
		      runs(function() {
		           expect(Rho.RhoConnectClient.pageSize).toEqual(2000);
		       });
		});
		
		it("VT295-059 | pageSize property when set to 0 | no record in models  ", function() {  
			dbreset();
			Rho.RhoConnectClient.pageSize=0;
			Rho.RhoConnectClient.setNotification('*', sync_notify_callback);
			 runs(function () {
		            Rho.RhoConnectClient.doSync();
		            setTimeout(function() {
						displayflag = true;
					}, 15000);
		       });
			 
			  waitsFor(function() {
					return displayflag;
				}, "wait", 16000);
			  
			  runs(function() {
		    	   modelrecordtest();
		    	   setTimeout(function() {
						displayflag1 = true;
					}, 5000);
		      	 
		       });
		       waitsFor(function() {
					return displayflag1;
				}, "wait", 6000);
			 
			 runs(function() {
		    	  expect(callbackCalled).toEqual(true);
		    	  expect(product_record_count).toEqual(0);
		    	  expect(customer_record_count).toEqual(0);
		       });

		});
		
		
		it("VT295-070 | set username [read only] property  | Exception should be thrown", function() {  
			 var Exception_Message = "";
			 runs(function () {
			 try
			  {
				  Rho.RhoConnectClient.userName ="Hello"
			  }
			 catch(ex)
			  {
			     Exception_Message =ex.message;	
			  }
		      });
         
			 expect(Exception_Message).toMatch("exception");
	
		});
		
		
		it("VT295-006 | Call isLoggedIn() when client is not logged in to server | false", function() {
			Rho.RhoConnectClient.logout();  //make sure that client is logged out	     
		    runs(function() {
		           expect(Rho.RhoConnectClient.isLoggedIn()).toEqual(false);
		       });
		});
	

		it("VT295-009 | Get username when user is logged out | string", function() {  
		    runs(function() {
		           expect(Rho.RhoConnectClient.userName).toEqual('testclient');
		       });
		});
	
		it("VT295-010 | Check logout functionality | Server Error", function() {  
			Rho.RhoConnectClient.setNotification('*', sync_notify_callback);
			Rho.RhoConnectClient.logout();
			Rho.RhoConnectClient.doSync();
		    runs(function() {
		    	//res['error_code'].to_i.should == ::Rho::RhoError::ERR_CLIENTISNOTLOGGEDIN
		    	   expect(myString).toMatch('error client is not logged in');
		       });
		});  

	});
	


 
//		describe("VT295-017 | set notification with with Anonymous callback function | callback should get fire", function() {
//			dbreset();
//			Rho.RhoConnectClient.setNotification('*', function(args) {
//				sync_notify_callback(args);
//			});
//			
//			it("Call Sync using Do Sync Check Callback", function() {  
//			 runs(function () {
//		            Rho.RhoConnectClient.doSync();
//		            setTimeout(function() {
//						displayflag = true;
//					}, 15000);
//		       });
//			 
//			  waitsFor(function() {
//					return displayflag;
//				}, "wait", 16000);
//			  
//			 runs(function() {
//		    	  expect(callbackCalled).toEqual(true);
//		    	  //alert(myString);
//		       });
//			});
//			
//			it("Product Record Test", function() {
//			  runs(function() {
//		    	   modelrecordtest();
//		    	   setTimeout(function() {
//						displayflag1 = true;
//					}, 5000);
//
//		       });
//			  
//		       waitsFor(function() {
//					return displayflag1;
//				}, "wait", 6000);
//			 
//			 runs(function() {
//		    	  expect(product_record_count).toBeGreaterThan(0);
//		       });
//		});
//			it("Customer Record Test", function() {
//		    	  expect(customer_record_count).toBeGreaterThan(0);
//
//		    });
//
//});


