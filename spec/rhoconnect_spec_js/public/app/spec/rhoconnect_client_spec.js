describe("Rhoconnect Client", function() {
	var rcContext = {};

	it("VT295-053 | pollInterval property default value test | 60", function() {
		Rho.RhoConnectClient.pollInterval = rcContext.defaultPollInterval;
		runs(function() {
			expect(Rho.RhoConnectClient.pollInterval).toEqual(60);
		});
	});

	it("VT295-005 | login to incorrect syncserver url | errorcode non zero", function() {
		Rho.RhoConnectClient.logout();  
		Rho.RhoConnectClient.syncServer = rcContext.syncServerUrl + '/foo';
		runs(function() {
			Rho.RhoConnectClient.login('testclient','testclient',rcContext.callbackFunction);
		});

		waitsFor(function() {
			return rcContext.callbackCalled;
		}, "Timeout", 10000);
     
		runs(function() {
			expect(Rho.RhoConnectClient.isLoggedIn()).toEqual(false);
			expect(rcContext.callbackCalled).toEqual(true);
			expect(rcContext.loginCallback_paramsValue.error_code).not.toEqual('0');
			expect(rcContext.loginCallback_paramsValue.error_message).not.toEqual("");
		});
	});
	
	
	//  it("VT295-001 | login to syncserver url with controller action URL Callback | errorcode 0", function() {
	// 	Rho.RhoConnectClient.syncServer = syncServerUrl;
	// 	runs(function () {
 //            Rho.RhoConnectClient.login('testclient','testclient','../app/Settings/controller_login_callback');
 //       });
	 
	// 	waitsFor(function () {
 //            return callbackCalled;
 //        },
 //        "Timeout",
 //        10000
 //      );
 //      runs(function() {
 //           expect(Rho.RhoConnectClient.isLoggedIn()).toEqual(true);
 //           expect(callbackCalled).toEqual(true);
 //       });
	// }); 
	

	// it("VT295-002 | login to syncserver url with Anonymous callback function | errorcode 0", function() {
	// 	Rho.RhoConnectClient.logout();  //make sure that client is logged out
	// 	Rho.RhoConnectClient.syncServer = syncServerUrl;
	// 	runs(function () {
 //            Rho.RhoConnectClient.login('testclient','testclient',function(result){
 //            	   callbackFunction(result);
 //            	});
 //       });
	 
	// 	waitsFor(function () {
 //            return callbackCalled;
 //        },
 //        "Timeout",
 //        6000
 //    );
 
 //      runs(function() {
 //           expect(Rho.RhoConnectClient.isLoggedIn()).toEqual(true);
 //           expect(callbackCalled).toEqual(true);
 //           expect(loginCallback_paramsValue.error_code).toEqual('0');
 //           expect(loginCallback_paramsValue.error_message).toEqual("");
 //       });
	// });

	// it("VT295-003 | login to syncserver url with function  callback | errorcode 0", function() {
	// 		Rho.RhoConnectClient.logout();  //make sure that client is logged out
	// 		Rho.RhoConnectClient.syncServer = syncServerUrl;
	// 		 runs(function () {
	// 	            Rho.RhoConnectClient.login('testclient','testclient',callbackFunction);
	// 	       });
			 
	// 		 waitsFor(function () {
	// 	            return callbackCalled;
	// 	        },
	// 	        "Timeout",
	// 	        6000
	// 	    );
	     
	// 	      runs(function() {
	// 	           expect(Rho.RhoConnectClient.isLoggedIn()).toEqual(true);
	// 	           expect(callbackCalled).toEqual(true);
	// 	           expect(loginCallback_paramsValue.error_code).toEqual('0');
	// 	           expect(loginCallback_paramsValue.error_message).toEqual("");
	// 	       });
	// 	});
		
		
	// 	it("VT295-004 | Get sync server url value | syncServerUrl", function() {
	// 		Rho.RhoConnectClient.syncServer = syncServerUrl;
	// 	      runs(function() {
	// 	           expect(Rho.RhoConnectClient.syncServer).toEqual(syncServerUrl);
	// 	       });
	// 	});
		
	// 	it("VT295-007 | Call isLoggedIn() when client is  logged in to server | true", function() {
	// 	    runs(function() {
	// 	           expect(Rho.RhoConnectClient.isLoggedIn()).toEqual(true);
	// 	       });
	// 	});
		
	// 	it("VT295-008 | Get username when user is logged in | string", function() {     
	// 		 runs(function() {
	// 	           expect(Rho.RhoConnectClient.userName).toEqual('testclient');
	// 	       });
	// 	});
		
	// 	it("VT295-011 | set notification for specific source model | Notification callback should fire", function() {
	// 		Rho.RhoConnectClient.setNotification('Product', sync_notify_callback);
	// 		 runs(function () {
	// 	            Rho.RhoConnectClient.doSync();
	// 	            setTimeout(function() {
	// 					displayflag = true;
	// 				}, 15000);
	// 	       });
			 
	// 		  waitsFor(function() {
	// 				return displayflag;
	// 			}, "wait", 16000);
			
			 
	// 		 runs(function() {
	// 	    	  expect(callbackCalled).toEqual(true);
	// 	    	  expect(product_record_count).toBeGreaterThan(0);
	// 	    	  expect(customer_record_count).toBeGreaterThan(0);
	// 	       });
	// 	});
		
		
	// 	it("VT295-012 | Check persistency of notification callback when set for specific source model | Notification callback should not fire", function() {  
	// 		Rho.RhoConnectClient.setNotification('Product', sync_notify_callback);
	// 		 runs(function () {
	// 	            Rho.RhoConnectClient.doSync();
	// 	            setTimeout(function() {
	// 					displayflag = true;
	// 				}, 15000);
	// 	       });
			 
	// 		  waitsFor(function() {
	// 				return displayflag;
	// 			}, "wait", 16000);
			  
	// 		  runs(function () {
	// 			    callbackCalled = false;  //setting callback to false again for checking persistency
	// 	            Rho.RhoConnectClient.doSync();
	// 	            setTimeout(function() {
	// 					displayflag1 = true;
	// 				}, 15000);
	// 	       });
			 
	// 		  waitsFor(function() {
	// 				return displayflag1;
	// 			}, "wait", 16000);
			
			 
	// 		 runs(function() {
	// 	    	  expect(callbackCalled).toEqual(true);
	// 	       });
	// 	});
		
		
	// 	it("VT295-013 | clear notification for specific source model | callback should not fire", function() {  
	// 		Rho.RhoConnectClient.setNotification('Product', sync_notify_callback);
	// 		Rho.RhoConnectClient.clearNotification('Product');
	// 		 runs(function () {
	// 	            Rho.RhoConnectClient.doSync();
	// 	            setTimeout(function() {
	// 					displayflag = true;
	// 				}, 15000);
	// 	       });
			 
	// 		  waitsFor(function() {
	// 				return displayflag;
	// 			}, "wait", 16000);
			
			 
	// 		 runs(function() {
	// 	    	  expect(callbackCalled).toEqual(false);
	// 	    	  expect(myString).toEqual('');
	// 	    	  //alert(myString);
	// 	       });
	// 	});
		
		
	it("VT295-014 | set notification for all sources with  controller action URL callback | callback should be called", function() {

		var myCallback = function(){
	  	rcContext.callbackCalled = true;
	  }
		Rho.RhoConnectClient.setNotification('*', myCallback);
		runs(function () {
			Rho.RhoConnectClient.login('testclient','testclient',function(){
	     	Rho.RhoConnectClient.doSync();
	    });

	    setTimeout(function(){
	    	rcContext.callbackCalled = false;
	    }, 10000);
		});

		waitsFor(function() {
			return rcContext.callbackCalled;
		}, "Callback was not yet called.", 10000);

		 
		runs(function() {
			expect(rcContext.callbackCalled).toEqual(true);
			expect(rcContext.Product.find('all').length).toBeGreaterThan(0);
		});
	});
		
		
		// it("VT295-015 | clear notification for all sources  | callback should not fire", function() {  
		// 	Rho.RhoConnectClient.setNotification('*', sync_notify_callback);
		// 	Rho.RhoConnectClient.clearNotification('*');
		// 	 runs(function () {
		//             Rho.RhoConnectClient.doSync();
		//             setTimeout(function() {
		// 				displayflag = true;
		// 			}, 10000);
		//        });
			 
		// 	  waitsFor(function() {
		// 			return displayflag;
		// 		}, "wait", 11000);
			
			 
		// 	 runs(function() {
		//     	  expect(callbackCalled).toEqual(false);
		//     	  expect(myString).toEqual('');
		//        });
		// });
		
		
		// it("VT295-016 | Check persistency of notification callback when set for all sources  | callback should fire each time", function() {  
		// 	Rho.RhoConnectClient.setNotification('*', sync_notify_callback);
		// 	 runs(function () {
		//             Rho.RhoConnectClient.doSync();
		//             setTimeout(function() {
		// 				displayflag = true;
		// 			}, 10000);
		//        });
			 
		// 	  waitsFor(function() {
		// 			return displayflag;
		// 		}, "wait", 11000);
			  
		// 	  runs(function () {
		// 		   callbackCalled = false;  //for checking persistency
		//             Rho.RhoConnectClient.doSync();
		//             setTimeout(function() {
		// 				displayflag1 = true;
		// 			}, 10000);
		//        });
			 
		// 	  waitsFor(function() {
		// 			return displayflag1;
		// 		}, "wait", 11000);
			
			 
		// 	 runs(function() {
		//     	  expect(callbackCalled).toEqual(true);
		//     	  expect(myString).not.toEqual('');
		//        });
		// });
		
		
		// it("VT295-017 | set notification with with Anonymous callback function | callback should get fire", function() {
		// 	Rho.RhoConnectClient.setNotification('*', function(args) {
		// 		sync_notify_callback(args);
		// 	});
		// 	 runs(function () {
		//             Rho.RhoConnectClient.doSync();
		//             setTimeout(function() {
		// 				displayflag = true;
		// 			}, 15000);
		//        });
			 
		// 	  waitsFor(function() {
		// 		    dispCurrentProcess(myString);
		// 			return displayflag;
		// 		}, "wait", 16000);
			
		// 	  runs(function() {
		//     	   modelrecordtest();
		//     	   setTimeout(function() {
		// 				displayflag1 = true;
		// 			}, 5000);
		      	 
		//        });
			  
		//        waitsFor(function() {
		// 			return displayflag1;
		// 		}, "wait", 6000);
			 
		// 	 runs(function() {
		//     	  expect(callbackCalled).toEqual(true);
		//     	  expect(product_record_count).toBeGreaterThan(0);
		//     	  expect(customer_record_count).toBeGreaterThan(0);
		//     	  //alert(myString);
		//        });
		// });
		
		
		// it("VT295-018 | set notification with with function callback. | callback should get fire", function() {
		// 	Rho.RhoConnectClient.setNotification('*', sync_notify_callback);
		// 	 runs(function () {
		//             Rho.RhoConnectClient.doSync();
		//             setTimeout(function() {
		// 				displayflag = true;
		// 			}, 15000);
		//        });
			 
		// 	  waitsFor(function() {
		// 		    dispCurrentProcess(myString);
		// 			return displayflag;
		// 		}, "wait", 16000);
			
		// 	  runs(function() {
		//     	   modelrecordtest();
		//     	   setTimeout(function() {
		// 				displayflag1 = true;
		// 			}, 5000);
		      	 
		//        });
			  
		//        waitsFor(function() {
		// 			return displayflag1;
		// 		}, "wait", 6000);
			 
		// 	 runs(function() {
		//     	  expect(callbackCalled).toEqual(true);
		//     	  expect(product_record_count).toBeGreaterThan(0);
		//     	  expect(customer_record_count).toBeGreaterThan(0);
		//     	  //alert(myString);
		//        });
		// });
		
		// it("VT295-019 | dosync method when record is inserted | Created records should get reflected at  backend server ", function() {  
		// 	//This can be reflected by query method, if the record isn't in the backend then it won't show up in query
		// });
		
		// it("VT295-020 | dosync method when record is updated | Updated records should get reflected at  backend server ", function() {  
		// 	//This can be reflected by query method, if the record isn't in the backend then it won't show up in query
		// });
		
	 //    it("VT295-021 | dosync method when record is deleted | Deleted records should get removed from  backend server ", function() {  
		// 	//This can be reflected by query method, if the record isn't in the backend then it won't show up in query
		// });
				
		
		// it("VT295-023 | doSync() with syncOnlyChangedSources set to True | only changed source will get sync", function() {
		// 	Rho.RhoConnectClient.setNotification('*', sync_notify_callback);
		// 	create_product_record(1,"VT295-023");
		// 	 runs(function () {
		//             Rho.RhoConnectClient.doSync(false,'',true);
		//             setTimeout(function() {
		// 				displayflag = true;
		// 			}, 15000);
		//        });
			 
		// 	  waitsFor(function() {
		// 			return displayflag;
		// 		}, "wait", 16000);
			
		// 	  runs(function() {
		//     	   modelrecordtest();
		//     	   setTimeout(function() {
		// 				displayflag1 = true;
		// 			}, 5000);
		      	 
		//        });
			  
		//        waitsFor(function() {
		// 			return displayflag1;
		// 		}, "wait", 6000);
			 
		// 	 runs(function() {
		//     	  expect(callbackCalled).toEqual(true);
		//     	  expect(product_record_count).toBeGreaterThan(0);
		//     	  expect(customer_record_count).toEqual(0);
		//     	  //alert(myString);
		//        });
		// });
		
		
		// it("VT295-024 | doSync() with syncOnlyChangedSources set to False | all source will get sync", function() {
		// 	Rho.RhoConnectClient.setNotification('*', sync_notify_callback);
		// 	create_product_record(1,"VT295-024");
		// 	 runs(function () {
		//             Rho.RhoConnectClient.doSync(false,'',false);
		//             setTimeout(function() {
		// 				displayflag = true;
		// 			}, 15000);
		//        });
			 
		// 	  waitsFor(function() {
		// 			return displayflag;
		// 		}, "wait", 16000);
			
		// 	  runs(function() {
		//     	   modelrecordtest();
		//     	   setTimeout(function() {
		// 				displayflag1 = true;
		// 			}, 5000);
		      	 
		//        });
			  
		//        waitsFor(function() {
		// 			return displayflag1;
		// 		}, "wait", 6000);
			 
		// 	 runs(function() {
		//     	  expect(callbackCalled).toEqual(true);
		//     	  expect(product_record_count).toBeGreaterThan(0);
		//     	  expect(customer_record_count).toBeGreaterThan(0);
		//     	  //alert(myString);
		//        });
		// });
	
	 //    it("VT295-027 | doSync () method with queryParams | Parameter should pass to rhoconnect server inside query method.", function() {  
		// 	//This can be automated, just have the adapter return data based on existence of parameters.
		// });
		
		// it("VT295-028 | doSync () method with all param is empty | Exception should be thrown", function() {  
		// 	 var Exception_Message = "";
		// 	 runs(function () {
		// 	 try
		// 	  {
		//             Rho.RhoConnectClient.doSync("","","");
		// 	  }
		// 	 catch(ex)
		// 	  {
		// 	     Exception_Message = ex.message;	
		// 	  }
		//       });
             
		// 	 expect(Exception_Message).toMatch("argument error exception");
	
		// }); 
		
		
		
		// it("VT295-029 | getLastSyncObjectCount method after resetting the DB | Number of server records", function() {
		// 	 runs(function () {
		//             Rho.RhoConnectClient.doSync();
		//             setTimeout(function() {
		// 				displayflag = true;
		// 			}, 15000);
		//        });
			 
		// 	  waitsFor(function() {
		// 			return displayflag;
		// 		}, "wait", 16000);
			 
		// 	 runs(function() {
		//     	  expect(Rho.RhoConnectClient.getLastSyncObjectCount('Product')).toBeGreaterThan(0);
		//     	  expect(Rho.RhoConnectClient.getLastSyncObjectCount('Customer')).toBeGreaterThan(0);
		//     	  //alert(myString);
		//        });
		// });
		
		
		// it("VT295-030 | getLastSyncObjectCount method after creating records | 2 ", function() {  
		// 	create_product_record(2,"VT295-030");
		// 	create_customer_record(2,"VT295-030");
		// 	 runs(function () {
		//             Rho.RhoConnectClient.doSync();
		//             setTimeout(function() {
		// 				displayflag = true;
		// 			}, 15000);
		//        });
			 
		// 	  waitsFor(function() {
		// 			return displayflag;
		// 		}, "wait", 16000);
			 
		// 	 runs(function() {
		//     	  expect(Rho.RhoConnectClient.getLastSyncObjectCount('Product')).toEqual(2);
		//     	  expect(Rho.RhoConnectClient.getLastSyncObjectCount('Customer')).toEqual(2);
		//     	  //alert(myString);
		//        });
		// });
		
		// it("VT295-031 | getLastSyncObjectCount method after updating records | 2 ", function() {  
		// 	update_product_record("VT295-030","VT295-031");
		// 	update_customer_record("VT295-030","VT295-031");
		// 	 runs(function () {
		//             Rho.RhoConnectClient.doSync();
		//             setTimeout(function() {
		// 				displayflag = true;
		// 			}, 15000);
		//        });
			 
		// 	  waitsFor(function() {
		// 			return displayflag;
		// 		}, "wait", 16000);
			 
		// 	 runs(function() {
		//     	  expect(Rho.RhoConnectClient.getLastSyncObjectCount('Product')).toEqual(2);
		//     	  expect(Rho.RhoConnectClient.getLastSyncObjectCount('Customer')).toEqual(2);
		//     	  //alert(myString);
		//        });
		// });
		
		
		// it("VT295-032 | getLastSyncObjectCount method after deleting records | 2 ", function() {  
		// 	delete_product_record("VT295-031");
		// 	delete_customer_record("VT295-031");
		// 	 runs(function () {
		//             Rho.RhoConnectClient.doSync();
		//             setTimeout(function() {
		// 				displayflag = true;
		// 			}, 15000);
		//        });
			 
		// 	  waitsFor(function() {
		// 			return displayflag;
		// 		}, "wait", 16000);
			 
		// 	 runs(function() {
		//     	  expect(Rho.RhoConnectClient.getLastSyncObjectCount('Product')).toEqual(2);
		//     	  expect(Rho.RhoConnectClient.getLastSyncObjectCount('Customer')).toEqual(2);
		//     	  //alert(myString);
		//        });
		// });
		
		
		// it("VT295-033 | getLastSyncObjectCount method without parameter | Exception should be thrown", function() {  
		// 	 var Exception_Message = "";
		// 	 runs(function () {
		// 	 try
		// 	  {
		// 		  Rho.RhoConnectClient.getLastSyncObjectCount();
		// 	  }
		// 	 catch(ex)
		// 	  {
		// 	     Exception_Message = ex.message;	
		// 	  }
		//       });
            
		// 	 expect(Exception_Message).toMatch("argument error exception");
	
		// });
		
		// it("VT295-034 | isSyncing() method when sync is in progress | true ", function() {  
		// 	 runs(function () {
		//             Rho.RhoConnectClient.doSync();
		//        });
			 
		// 	 runs(function() {
		//     	  expect(Rho.RhoConnectClient.isSyncing()).toEqual(true);
		//        });
		// });
		
		// it("VT295-035 | isSyncing() method when sync is not in progress | False ", function() {  
		// 	 setTimeout(function() {
		// 			displayflag = true;
		// 		}, 15000);
		// 	 waitsFor(function() {
		// 			return displayflag;
		// 		}, "wait", 16000);
		// 	 runs(function() {
		//     	  expect(Rho.RhoConnectClient.isSyncing()).toEqual(false);
		//        });
		// });
		
		// it("VT295-036 | stopSync() method | Number of server records", function() {
		// 	 runs(function () {
		//             Rho.RhoConnectClient.doSync();
		//             Rho.RhoConnectClient.stopSync();
		//        });
			 
		// 	 runs(function() {
		//     	   modelrecordtest();
		//     	   setTimeout(function() {
		// 				displayflag1 = true;
		// 			}, 5000);
		      	 
		//        });
			  
		//        waitsFor(function() {
		// 			return displayflag1;
		// 		}, "wait", 6000);
			 
		// 	 runs(function() {
		//     	  expect(product_record_count).toEqual(0);
		//     	  expect(customer_record_count).toEqual(0);
		//        });
		// });
		
		
		// it("VT295-037 | Sync the sources after calling stopSync() method.", function() {
		// 	 runs(function () {
		//             Rho.RhoConnectClient.doSync();
		//             Rho.RhoConnectClient.stopSync();
		//             Rho.RhoConnectClient.doSync();
		//             setTimeout(function() {
		// 				displayflag = true;
		// 			}, 15000);
		//        });
			 
		// 	  waitsFor(function() {
		// 			return displayflag;
		// 		}, "wait", 16000);
			 
		// 	 runs(function() {
		//     	   modelrecordtest();
		//     	   setTimeout(function() {
		// 				displayflag1 = true;
		// 			}, 5000);
		//        });
			 
		//        waitsFor(function() {
		// 			return displayflag1;
		// 		}, "wait", 6000);
			 
		// 	 runs(function() {
		//     	  expect(product_record_count).toBeGreaterThan(0);
		//     	  expect(customer_record_count).toBeGreaterThan(0);
		//        });
		// });
		
		// it("VT295-040 | doSyncSource method with empty parameters | Exception should be thrown", function() {  
		// 	 var Exception_Message = "";
		// 	 runs(function () {
		// 	 try
		// 	  {
		// 		  Rho.RhoConnectClient.doSyncSource();
		// 	  }
		// 	 catch(ex)
		// 	  {
		// 	    Exception_Message =	ex.message;	
		// 	  }
		//       });
           
		// 	 expect(Exception_Message).toMatch("argument error exception");
	
		// });

		
		// // search() method related spec and make sure that more than 5 records (VT295-041) exist at backend server.
		
		// it("VT295-041 | search method for all sources with controller action URL Callback | Callback should fire and model should populate ", function() {
		// 	 runs(function () {
		// 		 Rho.RhoConnectClient.search( { sourceNames : ['Product'], from : 'search', searchParams : { sku : 'VT295-041'}, offset : 0 }, '/app/Settings/controller_search_callback');
		// 		 });
		// 	  waitsFor(function() {
		// 			return callbackCalled;
		// 		}, "timeout", 10000);
			  
		// 	  runs(function () {
		// 		    callbackCalled =false; // setting false again here since will get true in search block
		// 		    Rho.RhoConnectClient.search( { sourceNames : ['Customer'], from :'search', searchParams : { first :'VT295-041'}, offset : 0 }, '/app/Settings/controller_search_callback');
		// 			 });
		// 	    waitsFor(function() {
		// 				return callbackCalled;
		// 			}, "timeout", 10000);
			    
		// 	  runs(function() {
		//     	   modelrecordtest();
		//     	   setTimeout(function() {
		// 				displayflag1 = true;
		// 			}, 5000);
		      	 
		//        });
			  
		//        waitsFor(function() {
		// 			return displayflag1;
		// 		}, "wait", 6000);
			 
		// 	 runs(function() {
		// 		  expect(callbackCalled).toEqual(true);
		//     	  expect(product_record_count).toBeGreaterThan(0);
		//     	  expect(customer_record_count).toBeGreaterThan(0);
		//        });
		// });
		
		
		// it("VT295-042 | search method for all sources with with Anonymous callback function | Callback should fire and model should populate", function() {
		// 	 runs(function () {
		// 		 Rho.RhoConnectClient.search( { sourceNames : ['Product'], from : 'search', searchParams : { sku : 'VT295-041'}, offset : 0 }, function(result){
		// 			 search_callback(result); });
		// 		 });
		// 	  waitsFor(function() {
		// 			return callbackCalled;
		// 		}, "timeout", 10000);
			  
		// 	  runs(function () {
		// 		    callbackCalled =false; // setting false again here since will get true in search block
		// 			 Rho.RhoConnectClient.search( { sourceNames : ['Customer'], from : 'search', searchParams : { sku : 'VT295-041'}, offset : 0 }, function(result){
		// 				 search_callback(result); });
		// 			 });
		// 	    waitsFor(function() {
		// 				return callbackCalled;
		// 			}, "timeout", 10000);
			  
		// 	  runs(function() {
		//     	   modelrecordtest();
		//     	   setTimeout(function() {
		// 				displayflag1 = true;
		// 			}, 5000);
		      	 
		//        });
		//        waitsFor(function() {
		// 			return displayflag1;
		// 		}, "wait", 6000);
			 
		// 	 runs(function() {
		//     	  expect(callbackCalled).toEqual(true);
		//     	  expect(product_record_count).toBeGreaterThan(0);
		//     	  expect(customer_record_count).toBeGreaterThan(0);
		//     	  expect(searchCallback_paramsValue.status).toMatch('complete');
		//     	  expect(searchCallback_paramsValue.search_params).not.toBeNull();
		//        });
		// });
		
		
		// it("VT295-043 | search method for all sources with with function callback | Callback should fire and model should populate", function() {
		// 	 runs(function () {
		// 		 Rho.RhoConnectClient.search( { sourceNames : ['Product'], from : 'search', searchParams : { sku : 'VT295-041'}, offset : 0 }, search_callback );
		// 		 });
		// 	  waitsFor(function() {
		// 			return callbackCalled;
		// 		}, "timeout", 10000);
			  
		// 	  runs(function () {
		// 		    callbackCalled =false; // setting false again here since will get true in search block
		// 			 Rho.RhoConnectClient.search( { sourceNames : ['Customer'], from : 'search', searchParams : { sku : 'VT295-041'}, offset : 0 }, search_callback);
		// 			 });
		// 	    waitsFor(function() {
		// 				return callbackCalled;
		// 			}, "timeout", 10000);
			  
		// 	  runs(function() {
		//     	   modelrecordtest();
		//     	   setTimeout(function() {
		// 				displayflag1 = true;
		// 			}, 5000);
		      	 
		//        });
		//        waitsFor(function() {
		// 			return displayflag1;
		// 		}, "wait", 6000);
			 
		// 	 runs(function() {
		//     	  expect(callbackCalled).toEqual(true);
		//     	  expect(product_record_count).toBeGreaterThan(0);
		//     	  expect(customer_record_count).toBeGreaterThan(0);
		//     	  expect(searchCallback_paramsValue.status).toMatch('complete');
		//     	  expect(searchCallback_paramsValue.search_params).not.toBeNull();
		//        });
		// });
		
		
		// it("VT295-045 | Search method when :from parameter is set to non default source adapter method | Callback should fire and model should populate", function() {
		// 	 runs(function () {
		// 		 Rho.RhoConnectClient.search( { sourceNames : ['Product'], from : 'user_product_search', searchParams : { sku : 'VT295-041'}, offset : 0 }, search_callback );
		// 		 });
		// 	  waitsFor(function() {
		// 			return callbackCalled;
		// 		}, "timeout", 10000);
			  	  
		// 	  runs(function() {
		//     	   modelrecordtest();
		//     	   setTimeout(function() {
		// 				displayflag1 = true;
		// 			}, 5000);
		      	 
		//        });
		//        waitsFor(function() {
		// 			return displayflag1;
		// 		}, "wait", 6000);
			 
		// 	 runs(function() {
		//     	  expect(callbackCalled).toEqual(true);
		//     	  expect(product_record_count).toBeGreaterThan(0);
		//     	  expect(customer_record_count).toEqual(0);
		//     	  expect(searchCallback_paramsValue.status).toMatch('complete');
		//     	  expect(searchCallback_paramsValue.search_params).not.toBeNull();
		//        });
		// });
		
		// it("VT295-046 | search method if backend server has more records than max_results  ", function() {
		// 	 runs(function () {
		// 		 Rho.RhoConnectClient.search( { sourceNames : ['Product'], from : 'search', searchParams : { sku : 'VT295-041'}, offset : 0, maxResults : 5 }, search_callback );
		// 		 });
		// 	  waitsFor(function() {
		// 			return callbackCalled;
		// 		}, "timeout", 10000);
			  	  
		// 	  runs(function() {
		//     	   modelrecordtest();
		//     	   setTimeout(function() {
		// 				displayflag1 = true;
		// 			}, 5000);
		      	 
		//        });
		//        waitsFor(function() {
		// 			return displayflag1;
		// 		}, "wait", 6000);
			 
		// 	 runs(function() {
		//     	  expect(callbackCalled).toEqual(true);
		//     	  expect(product_record_count).toEqual(5);
		//     	  expect(searchCallback_paramsValue.status).toMatch('complete');
		//     	  expect(searchCallback_paramsValue.search_params).not.toBeNull();
		//        });
		// });
		
		// it("VT295-047 | search method if sync_changes set to true", function() {
		// 	 runs(function () {
		// 		 create_product_record(1,"VT295-047");
		// 		 Rho.RhoConnectClient.search( { sourceNames : ['Product'], from : 'search', searchParams : { sku : 'VT295-041'}, offset : 0, maxResults : 5, syncChanges : true }, search_callback );
		// 		 });
		// 	  waitsFor(function() {
		// 			return callbackCalled;
		// 		}, "timeout", 10000);
			  	  
		// 	  runs(function() {
		//     	   modelrecordtest();
		//     	   setTimeout(function() {
		// 				displayflag1 = true;
		// 			}, 5000);
		      	 
		//        });
		//        waitsFor(function() {
		// 			return displayflag1;
		// 		}, "wait", 6000);
			 
		// 	 runs(function() {
		//     	  expect(callbackCalled).toEqual(true);
		//     	  expect(product_record_count).toEqual(5);
		//     	  expect(searchCallback_paramsValue.status).toMatch('complete');
		//     	  expect(searchCallback_paramsValue.search_params).not.toBeNull();
		//     	  expect(Rho.ORM.haveLocalChanges).toEqual(false);
		//        });
		// });
		
		// it("VT295-048 | search method if sync_changes set to false", function() {
		// 	 runs(function () {
		// 		 create_product_record(1,"VT295-047");
		// 		 Rho.RhoConnectClient.search( { sourceNames : ['Product'], from : 'search', searchParams : { sku : 'VT295-041'}, offset : 0, maxResults : 5, syncChanges : false }, search_callback );
		// 		 });
		// 	  waitsFor(function() {
		// 			return callbackCalled;
		// 		}, "timeout", 10000);
			  	  
		// 	  runs(function() {
		//     	   modelrecordtest();
		//     	   setTimeout(function() {
		// 				displayflag1 = true;
		// 			}, 5000);
		      	 
		//        });
		//        waitsFor(function() {
		// 			return displayflag1;
		// 		}, "wait", 6000);
			 
		// 	 runs(function() {
		//     	  expect(callbackCalled).toEqual(true);
		//     	  expect(product_record_count).toEqual(5);
		//     	  expect(searchCallback_paramsValue.status).toMatch('complete');
		//     	  expect(searchCallback_paramsValue.search_params).not.toBeNull();
		//     	  expect(Rho.ORM.haveLocalChanges).toEqual(true);
		//        });
		// });
		
		
		// it("VT295-049 | search method with no parameters | Exception should be thrown", function() {  
		// 	 var Exception_Message = "";
		// 	 runs(function () {
		// 	 try
		// 	  {
		// 		  Rho.RhoConnectClient.search();
		// 	  }
		// 	 catch(ex)
		// 	  {
		// 	    Exception_Message =	ex.message;	
		// 	  }
		//       });
          
		// 	 expect(Exception_Message).toMatch("argument error exception");
	
		// });
		
		// it("VT295-054 | pollInterval property when set to 30 seconds | call back should fire after each 30 seconds ", function() {  
		// 	Rho.RhoConnectClient.setNotification('*', sync_notify_callback);
		// 	Rho.RhoConnectClient.pollInterval= 30;
		// 	runs(function () {
	 //            setTimeout(function() {
		// 			displayflag = true;
		// 		}, 32000);
	 //        });
		//    waitsFor(function() {
		// 		return displayflag;
		// 	}, "wait", 33000);
		   
		//    runs(function() {
		//     	  expect(callbackCalled).toEqual(true);
		//     	  callbackCalled=false;
		//        });
		// 	runs(function () {
	 //            setTimeout(function() {
	 //            	displayflag1 = true;
		// 		}, 32000);
	 //        });
		//    waitsFor(function() {
		// 		return displayflag1;
		// 	}, "wait", 33000);
		   
		// 	 runs(function() {
		//     	  expect(callbackCalled).toEqual(true);
		//        });
		// });
		
		
		// it("VT295-055 | pollInterval property when set to 0 seconds | call back should not get fire  ", function() {  
		// 	Rho.RhoConnectClient.pollInterval=0;
		// 	Rho.RhoConnectClient.setNotification('*', sync_notify_callback);
		// 	runs(function () {
	 //            setTimeout(function() {
		// 			displayflag = true;
		// 		}, 60000);
	 //        });
		//    waitsFor(function() {
		// 		return displayflag;
		// 	}, "wait", 62000);
		// 	 runs(function() {
		//     	  expect(callbackCalled).toEqual(false);
		//        });
		// });
			
		// it("VT295-056 | Check sync method when pollInterval property  set to 0 seconds | call back should get fire  ", function() {
		// 	Rho.RhoConnectClient.pollInterval=0;
		// 	Rho.RhoConnectClient.setNotification('*', sync_notify_callback);
		// 		runs(function () {
		//             Rho.RhoConnectClient.doSync();
		//             setTimeout(function() {
		// 				displayflag = true;
		// 			}, 15000);
		//        });
		 
		// 	  waitsFor(function() {
		// 			return displayflag;
		// 		}, "wait", 16000);
		  
		// 	  runs(function() {
		//     	   modelrecordtest();
		//     	   setTimeout(function() {
		// 				displayflag1 = true;
		// 			}, 5000);
		      	 
		//        });
		//        waitsFor(function() {
		// 			return displayflag1;
		// 		}, "wait", 6000);
			 
		// 	 runs(function() {
		//     	  expect(callbackCalled).toEqual(true);
		//     	  expect(product_record_count).toBeGreaterThan(0);
		//     	  expect(customer_record_count).toBeGreaterThan(0);
		//        });

		// });
		
		
		// it("VT295-057 | pageSize property default value test | 2000", function() {
		//       runs(function() {
		//            expect(Rho.RhoConnectClient.pageSize).toEqual(2000);
		//        });
		// });
		
		
		// it("VT295-058 | pageSize property when set to 10 | cumulative_count should be reported to 10 (except of last one) when sync status is in_progress state", function() {
		//      //This can be done automatically, just have sync callback verify cumulative_count value.
		// });
		
		// it("VT295-059 | pageSize property when set to 0 | no record in models  ", function() {
		// 	Rho.RhoConnectClient.pageSize=0;
		// 	Rho.RhoConnectClient.setNotification('*', sync_notify_callback);
		// 	 runs(function () {
		//             Rho.RhoConnectClient.doSync();
		//             setTimeout(function() {
		// 				displayflag = true;
		// 			}, 15000);
		//        });
			 
		// 	  waitsFor(function() {
		// 			return displayflag;
		// 		}, "wait", 16000);
			  
		// 	  runs(function() {
		//     	   modelrecordtest();
		//     	   setTimeout(function() {
		// 				displayflag1 = true;
		// 			}, 5000);
		      	 
		//        });
		//        waitsFor(function() {
		// 			return displayflag1;
		// 		}, "wait", 6000);
			 
		// 	 runs(function() {
		//     	  expect(callbackCalled).toEqual(true);
		//     	  expect(product_record_count).toEqual(0);
		//     	  expect(customer_record_count).toEqual(0);
		//        });

		// });
		
		// it("VT295-060 | sslVerifyPeer property when set to true | It should connect to SSL certified rhoconnect  server successfully.", function() {
		//      //Rho.RhoConnectClient.syncServer = 'https://nagios.rhomobile.com';
		// });
		
	 //    it("VT295-061 | sslVerifyPeer property when set to false | It should not connect to SSL certified rhoconnect server", function() {
		//      //Rho.RhoConnectClient.syncServer = 'https://nagios.rhomobile.com';
	
		// });
		
	 //    it("VT295-063 | setObjectNotify() with controller action URL Callback | object notification callback should be invoked.", function() {
		   
	
		// });
		
		// it("VT295-064 | setObjectNotify() with no changes in source objects | object notification callback should not invoked.", function() {
		     
	
		// });
		
		// it("VT295-065 | setObjectNotify() with Anonymous callback function. | object notification callback should be invoked.", function() {
		     
	
		// });
		
		// it("VT295-066 | setObjectNotify() with function callback. | object notification callback should be invoked.", function() {
		     
	
		// });
		
		// it("VT295-067 | setObjectNotify() without calling addObjectNotify() method. | object notification callback should not get invoked.", function() {
		     
	
		// });
		
	 //    it("VT295-068 | cleanObjectNotify()method. | object notification callback should not invoke since it has been cleared.", function() {
		     
	
		// });
		
		// it("VT295-069 | addObjectNotify() method without any parameter. | argument error exception should be thrown.", function() {
		     
	
		// });
		
		
		// it("VT295-070 | set username [read only] property  | Exception should be thrown", function() {  
		// 	 var Exception_Message = "";
		// 	 runs(function () {
		// 	 try
		// 	  {
		// 		  Rho.RhoConnectClient.userName ="Hello"
		// 	  }
		// 	 catch(ex)
		// 	  {
		// 	     Exception_Message =ex.message;	
		// 	  }
		//       });
         
		// 	 expect(Exception_Message).toMatch("exception");
	
		// });
		
		// it("VT295-073 | bulk sync using resque worker  | Both of the rhom model should get populated with server data", function() {  
			 
			 
	
		// });
		
		// it("VT295-074 | should handle update updated object while sync error  | changed_values table record ? ", function() {  
			 
			 
	
		// });
		
	    
		// it("VT295-075 | should handle update updated full_update object while sync | changed_values table record ? ", function() {  
			 
			 
	
		// });
		
		
	 //    it("VT295-076 | should handle deleted object while error sync | changed_values table record ? ", function() {  
			 
			 
	
		// });

		// //don't know much about this test
	 //    it("VT295-077 | should create new Product with Customers | changed_values table record ? ", function() {  
			 
			 
	
		// });
		
		// it("VT295-078 | login with different user | should reset database ", function() {  
			 
			 
	
		// });
		
		// it("VT295-079 | should process create-error : delete | created records during error should get deleted from db ", function() {  
			 
			 
	
		// });
		
		// it("VT295-080 | should process create-error : recreate | created records during error should get recreated in db finally ", function() {  
			 
			 
	
		// });
		
		// it("VT295-081 | should process retry update-error | ? ", function() {  
			 
			 
	
		// });
		
		// it("VT295-082 | should process retry update-error full_update model | ? ", function() {  
			 
			 
	
		// });
		
		// it("VT295-083 | should rollback update-error | ? ", function() {  
			 
			 
	
		// });
		
		// it("VT295-084 | should process delete-error | ? ", function() {  
			 
			 
	
		// });
		
		// it("VT295-085 | should process source-error | ? ", function() {  
			 
			 
	
		// });
		
		// it("VT295-086 | should process search-error | ? ", function() {  
			 
			 
	
		// });
		
		// it("VT295-087 | should NOT push pending created objects | ? ", function() {  
			 
			 
	
		// });
		
		// it("VT295-088 | should push when pending created objects | ? ", function() {  
			 
			 
	
		// });
		
		// it("VT295-089 | should NOT push when children pending created objects | ? ", function() {  
			 
			 
	
		// });
		
		// it("VT295-090 | should handle update created object while sync error | ? ", function() {  
			 
			 
	
		// });
		
		// it("VT295-091 | should handle update created object while sync error | ? ", function() {  
			 
			 
	
		// });
		
		// it("VT295-092 | should process error sync | ? ", function() {  
			 
			 
	
		// });
		
		
		// // logout related test
		// it("VT295-006 | Call isLoggedIn() when client is not logged in to server | false", function() {
		// 	Rho.RhoConnectClient.logout();  //make sure that client is logged out	     
		//     runs(function() {
		//            expect(Rho.RhoConnectClient.isLoggedIn()).toEqual(false);
		//        });
		// });
	

		// it("VT295-009 | Get username when user is logged out | string", function() {  
		//     runs(function() {
		//            expect(Rho.RhoConnectClient.userName).toEqual('testclient');
		//        });
		// });
	
		// it("VT295-010 | Check logout functionality | Server Error", function() {  
		// 	Rho.RhoConnectClient.setNotification('*', sync_notify_callback);
		// 	Rho.RhoConnectClient.logout();
		// 	Rho.RhoConnectClient.doSync();
		//     runs(function() {
		//     	   expect(callbackCalled).toEqual(true);
				   
		//        });
		// });  

	sharedBehaviorForRhoconnectClient(rcContext);
});
