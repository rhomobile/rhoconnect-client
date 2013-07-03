var loginCallback_paramsValue = [{ "error_code" : "" , "error_message" : "" }],
		searchCallback_paramsValue = [{ "status" : "" , "search_params" : "" }],
		syncServerUrl = "http://"+SYNC_SERVER_HOST+":"+SYNC_SERVER_PORT,
		defaultPollInterval = Rho.RhoConnectClient.pollInterval,
		defaultSyncServer = Rho.RhoConnectClient.syncServer,
		callbackCalled = false,
		Product = null,
		Customer = null;

describe("Rhoconnect Client", function() {
  beforeEach(function() {
    callbackCalled = false;
    Rho.RhoConnectClient.syncServer = syncServerUrl;
    Rho.RhoConnectClient.pollInterval = defaultPollInterval;
    loginCallback_paramsValue.error_code = "";
    loginCallback_paramsValue.error_message = "";
    Rho.ORM.clear();
    var db = new Rho.Database.SQLite3(Rho.Application.databaseFilePath('user'), 'user');
    db.execute("DELETE FROM SOURCES");
    db.execute("DELETE FROM CLIENT_INFO");
    db.execute("DELETE FROM OBJECT_VALUES");
    Product = Rho.ORM.addModel( function(model){
      model.modelName("Product");
      model.enable("sync");
    });
    Customer = Rho.ORM.addModel( function(model){
			model.modelName("Customer");
			model.property("address", "string");
			model.property("created_at", "string");
			model.property("city", "string");
			model.property("email", "string");
			model.property("last", "string");
			model.property("updated_at", "string");
			model.property("lat", "string");
			model.property("long", "string");
			model.property("phone", "string");
			model.property("state", "string");
			model.property("zip", "string");
			model.enable("sync");
		});
  });

	it("VT295-053 | pollInterval property default value test | 60", function() {
		Rho.RhoConnectClient.pollInterval = defaultPollInterval;
		runs(function() {
			expect(Rho.RhoConnectClient.pollInterval).toEqual(60);
		});
	});

	it("VT295-005 | login to incorrect syncserver url | errorcode non zero", function() {
		Rho.RhoConnectClient.syncServer = syncServerUrl + '/foo';
		runs(function() {
			Rho.RhoConnectClient.login('testclient','testclient',callbackFunction);
		});

		waitsFor(function() {
			return callbackCalled;
		}, "wait", 6000);

		runs(function() {
			expect(Rho.RhoConnectClient.isLoggedIn()).toEqual(false);
			expect(callbackCalled).toEqual(true);
			expect(loginCallback_paramsValue.error_code).not.toEqual('0');
			expect(loginCallback_paramsValue.error_message).not.toEqual("");
		});
	});

	it("VT295-002 | login to syncserver url with anonymous callback function | errorcode 0", function() {
		runs(function() {
			Rho.RhoConnectClient.login('testclient','testclient',function(result){
				callbackFunction(result);
			});
		});

		waitsFor(function() {
			return callbackCalled;
		}, "Timeout", 6000);

		runs(function() {
			expect(Rho.RhoConnectClient.isLoggedIn()).toEqual(true);
			expect(callbackCalled).toEqual(true);
			expect(loginCallback_paramsValue.error_code).toEqual('0');
			expect(loginCallback_paramsValue.error_message).toEqual("");
		});
	});

	it("VT295-003 | login to syncserver url with function callback | errorcode 0", function() {
		runs(function() {
			Rho.RhoConnectClient.login('testclient','testclient',callbackFunction);
		});

		waitsFor(function() {
			return callbackCalled;
		}, "Timeout", 6000);

		runs(function() {
			expect(Rho.RhoConnectClient.isLoggedIn()).toEqual(true);
			expect(callbackCalled).toEqual(true);
			expect(loginCallback_paramsValue.error_code).toEqual('0');
			expect(loginCallback_paramsValue.error_message).toEqual("");
		});
	});

	it("VT295-004 | Get sync server url value | syncServerUrl", function() {
		Rho.RhoConnectClient.syncServer = syncServerUrl;
		runs(function() {
			expect(Rho.RhoConnectClient.syncServer).toEqual(syncServerUrl);
		});
	});

	it("VT295-007 | Call isLoggedIn() when client is logged in to server | true", function() {
		runs(function() {
			Rho.RhoConnectClient.login('testclient','testclient',callbackFunction);
		});

		waitsFor(function() {
			return callbackCalled;
		}, "wait", 6000);

		runs(function() {
			expect(Rho.RhoConnectClient.isLoggedIn()).toEqual(true);
		});
	});

	it("VT295-008 | Get username when user is logged in | string", function() {
		runs(function() {
			Rho.RhoConnectClient.login('testclient','testclient',callbackFunction);
		});

		waitsFor(function() {
			return callbackCalled;
		}, "wait", 6000);

		runs(function() {
			expect(Rho.RhoConnectClient.userName).toEqual('testclient');
		});
	});

	it("VT295-011 | sets notification for specific source model | callback should fire", function() {
		runs(function() {
			Rho.RhoConnectClient.login('testclient','testclient',function(){
				Rho.RhoConnectClient.setNotification('Product', callbackFunction);
				Rho.RhoConnectClient.doSync();
			});
		});

		waitsFor(function() {
			return callbackCalled;
		}, "wait", 6000);

		runs(function() {
			expect(callbackCalled).toEqual(true);
			expect(Product.count()).toBeGreaterThan(0);
		});
	});

	it("VT295-012 | don't persist notification for for specific source model | callback should not fire", function() {
		var clearedNotify = false;
		var callbackCount = 0;
		runs(function() {
			Rho.RhoConnectClient.login('testclient','testclient',function(){
				Rho.RhoConnectClient.setNotification('Product', function(){ callbackCount++; });
				Rho.RhoConnectClient.doSync();
			});
		});

		waitsFor(function() {
			return callbackCount === 1;
		}, "wait", 6000);

		runs(function() {
			expect(callbackCount).toEqual(1);
		});

		runs(function() {
			Rho.RhoConnectClient.doSync();
			setTimeout(function() {
				clearedNotify = true;
			}, 5000);
		});

		waitsFor(function() {
			return clearedNotify;
		}, "wait", 6000);

		runs(function() {
			expect(callbackCount).toEqual(1);
		});
	});

	it("VT295-013 | clears notification for specific model | callback should not fire", function() {
		var clearedNotify = false;
		runs(function() {
			Rho.RhoConnectClient.login('testclient','testclient',function(){
				Rho.RhoConnectClient.setNotification('Product', callbackFunction);
				Rho.RhoConnectClient.clearNotification('Product');
				Rho.RhoConnectClient.doSync();
			});
			setTimeout(function() {
				clearedNotify = true;
			}, 5000);
		});

		waitsFor(function() {
			return clearedNotify && !callbackCalled;
		}, "wait", 6000);

		runs(function() {
			expect(callbackCalled).toEqual(false);
		});
	});

	it("VT295-014 | sets notification for all sources | callback should be called", function() {
  	runs(function() {
  		Rho.RhoConnectClient.login('testclient','testclient',function(){
  			Rho.RhoConnectClient.setNotification('*', callbackFunction);
  			Rho.RhoConnectClient.doSync();
  		});
  	});

		waitsFor(function() {
			return callbackCalled;
		}, "wait", 6000);

		runs(function() {
			expect(callbackCalled).toEqual(true);
			expect(Product.count()).toBeGreaterThan(0);
		});
	});

	it("VT295-015 | clear notification for all sources | callback should not be called", function() {
		var clearedNotify = false;
		runs(function() {
			Rho.RhoConnectClient.login('testclient','testclient',function(){
				Rho.RhoConnectClient.setNotification('*', callbackFunction);
				Rho.RhoConnectClient.clearNotification('*');
				Rho.RhoConnectClient.doSync();
			});
			setTimeout(function() {
				clearedNotify = true;
			}, 5000);
		});

		waitsFor(function() {
			return clearedNotify;
		}, "wait", 6000);

		runs(function() {
			expect(callbackCalled).toEqual(false);
		});
	});

	it("VT295-016 | set notification callback is set for all sources | callback should be called each time", function() {
		var callCount = 0;
		runs(function() {
			Rho.RhoConnectClient.login('testclient','testclient',function(){
				Rho.RhoConnectClient.setNotification('*', function(args) { callCount++; });
				Rho.RhoConnectClient.doSync();
			});
		});

		waitsFor(function() {
			return callCount === 1;
		}, "wait", 6000);

		runs(function() {
			expect(callCount).toEqual(1);
			Rho.RhoConnectClient.doSync();
		});

		waitsFor(function() {
			return callCount === 2;
		}, "wait", 6000);

		runs(function() {
			expect(callCount).toEqual(2);
		});
	});

	it("VT295-017 | set notification with with anonymous callback function | callback should be called", function() {
		runs(function() {
			Rho.RhoConnectClient.login('testclient','testclient',function(){
				Rho.RhoConnectClient.setNotification('*', function(args){
					callbackCalled = true;
				});
				Rho.RhoConnectClient.doSync();
			});
		});

		waitsFor(function() {
			return callbackCalled;
		}, "wait", 6000);

		runs(function() {
			expect(callbackCalled).toEqual(true);
			expect(Product.count()).toBeGreaterThan(0);
		});
	});

	it("VT295-019 | doSync method when record is inserted | new record displays in backend server ", function() {
		var expectedCount = 0,
				callback1 = false,
				callback2 = false,
				callback3 = false,
				testName = new Date().getTime().toString();

		// Sync first time
		Rho.RhoConnectClient.login('testuser','testuser',function(){
			Rho.RhoConnectClient.setNotification('*', function(args){ callback1 = true; });
			Rho.RhoConnectClient.doSync();
		});

		waitsFor(function() {
			//alert('inside callback1');
			return callback1;
		}, "wait 1", 6000);

		runs(function() {
			expectedCount = Product.count();
			Product.create({name: testName});
			Rho.RhoConnectClient.clearNotification('*');
			Rho.RhoConnectClient.setNotification('*', function(args){ callback2 = true; });
			Rho.RhoConnectClient.doSync();
		});

		waitsFor(function() {
			return callback2;
		}, "wait 2", 6000);

		runs(function() {
			Rho.RhoConnectClient.logout();
			Rho.RhoConnectClient.login('testuser2','testuser2',function(){
				Rho.RhoConnectClient.clearNotification('*');
				Rho.RhoConnectClient.setNotification('*', function(args){ callback3 = true; });
				Rho.RhoConnectClient.doSync();
			});
		});

		waitsFor(function() {
			return callback3;
		}, "wait 3", 6000);

		runs(function() {
			expect(Product.count()).toEqual(expectedCount + 1);
			expect(
				Product.find('all',{conditions: {name: testName}}).length
			).toEqual(1);
		});
	});

	it("VT295-020 | doSync method when record is updated | updated record displays in backend server", function() {
		var callback1 = false,
				callback2 = false,
				callback3 = false,
				testName = new Date().getTime().toString();

		// Sync first time
		Rho.RhoConnectClient.login('testuser','testuser',function(){
			Rho.RhoConnectClient.setNotification('*', function(args){ callback1 = true; });
			Rho.RhoConnectClient.doSync();
		});

		waitsFor(function() {
			return callback1;
		}, "wait 1", 6000);

		runs(function() {
			var p = Product.find('first');
			p.set('name', testName);
			p.save();
			Rho.RhoConnectClient.clearNotification('*');
			Rho.RhoConnectClient.setNotification('*', function(args){ callback2 = true; });
			Rho.RhoConnectClient.doSync();
		});

		waitsFor(function() {
			return callback2;
		}, "wait 2", 6000);

		runs(function() {
			Rho.RhoConnectClient.logout();
			Rho.RhoConnectClient.login('testuser2','testuser2',function(){
				Rho.RhoConnectClient.clearNotification('*');
				Rho.RhoConnectClient.setNotification('*', function(args){ callback3 = true; });
				Rho.RhoConnectClient.doSync();
			});
		});

		waitsFor(function() {
			return callback3;
		}, "wait 3", 6000);

		runs(function() {
			var products = Product.find('all',{conditions: {name: testName}});
			expect(products.length).toEqual(1);
			expect(products[0].get('name')).toEqual(testName);
		});
	});

	it("VT295-021 | doSync method when record is deleted | deleted record is removed from backend server", function() {
		var expectedCount = 0,
				callback1 = false,
				callback2 = false,
				callback3 = false,
				deletedName = null;

		// Sync first time
		Rho.RhoConnectClient.login('testuser','testuser',function(){
			Rho.RhoConnectClient.setNotification('*', function(args){ callback1 = true; });
			Rho.RhoConnectClient.doSync();
		});

		waitsFor(function() {
			return callback1;
		}, "wait 1", 6000);

		runs(function() {
			expectedCount = Product.count();
			var deleted = Product.find('first');
			deletedName = deleted.get('name');
			deleted.destroy();
			Rho.RhoConnectClient.clearNotification('*');
			Rho.RhoConnectClient.setNotification('*', function(args){ callback2 = true; });
			Rho.RhoConnectClient.doSync();
		});

		waitsFor(function() {
			return callback2;
		}, "wait 2", 6000);

		runs(function() {
			Rho.RhoConnectClient.logout();
			Rho.RhoConnectClient.login('testuser2','testuser2',function(){
				Rho.RhoConnectClient.clearNotification('*');
				Rho.RhoConnectClient.setNotification('*', function(args){ callback3 = true; });
				Rho.RhoConnectClient.doSync();
			});
		});

		waitsFor(function() {
			return callback3;
		}, "wait 3", 6000);

		runs(function() {
			expect(Product.count()).toEqual(expectedCount - 1);
			var products = Product.find('all',{conditions: {name: deletedName}});
			expect(products.length).toEqual(0);
		});
	});

	it("VT295-023 | doSync with syncOnlyChangedSources set true | only changed source should sync", function() {
		var callCount = 0,
				timeoutCalled = false;

		var singleCallback = function(args) {
			callCount++;
		};

		// Sync first time
		runs(function() {
			Rho.RhoConnectClient.login('testuser','testuser',function(){
				Rho.RhoConnectClient.setNotification('*', callbackFunction);
				Rho.RhoConnectClient.doSync();
			});
		});

		waitsFor(function() {
			return callbackCalled;
		}, "wait", 6000);


		runs(function() {
			Product.create({brand: 'Apple', name: 'test-iphone', price: '$1'});
			Rho.RhoConnectClient.login('testuser','testuser',function(){
				Rho.RhoConnectClient.setNotification('*', singleCallback);
				Rho.RhoConnectClient.doSync(false,'',true);
			});
			setTimeout(function(){
				timeoutCalled = true;
			}, 5000);
		});

		waitsFor(function() {
			return timeoutCalled;
		}, "wait", 6000);

		runs(function() {
			expect(callbackCalled).toEqual(true);
			expect(callCount).toEqual(4); // 2 Product, 1 customer, 1 complete
			expect(Product.count()).toBeGreaterThan(0);
			expect(Customer.count()).toEqual(0);
		});
	});


	it("VT295-024 | doSync with syncOnlyChangedSources set to false | all sources should sync", function() {
		var callCount = 0,
				timeoutCalled = false;

		var singleCallback = function(args) {
			callCount++;
		};

		// Sync first time
		runs(function() {
			Rho.RhoConnectClient.login('testuser','testuser',function(){
				Rho.RhoConnectClient.setNotification('*', callbackFunction);
				Rho.RhoConnectClient.doSync();
			});
		});

		waitsFor(function() {
			return callbackCalled;
		}, "wait", 6000);

		runs(function() {
			createProducts(1, 'VT295-024');
			Rho.RhoConnectClient.login('testuser','testuser',function(){
				Rho.RhoConnectClient.setNotification('*', singleCallback);
				Rho.RhoConnectClient.doSync(false,'',false);
			});
			setTimeout(function(){
				timeoutCalled = true;
			}, 5000);
		});

		waitsFor(function() {
			return timeoutCalled;
		}, "wait", 6000);

		runs(function() {
			expect(callbackCalled).toEqual(true);
			expect(callCount).toEqual(5); // 2 Product, 2 customer, 1 complete
			expect(Product.count()).toBeGreaterThan(0);
			expect(Customer.count()).toBeGreaterThan(0);
		});
	});

	 //    it("VT295-027 | doSync () method with queryParams | Parameter should pass to rhoconnect server inside query method.", function() {
		// 	//This can be automated, just have the adapter return data based on existence of parameters.

	it("VT295-029 | getLastSyncObjectCount after sync | count of records", function() {
		runs(function() {
			Rho.RhoConnectClient.login('testclient','testclient',function(){
				Rho.RhoConnectClient.setNotification('*', callbackFunction);
				Rho.RhoConnectClient.doSync();
			});
		});

		waitsFor(function() {
			return callbackCalled;
		}, "wait", 6000);

		runs(function() {
			var expectedProduct = Product.count();
			var expectedCustomer = Customer.count();
			expect(Rho.RhoConnectClient.getLastSyncObjectCount('Product')).toEqual(expectedProduct);
			expect(Rho.RhoConnectClient.getLastSyncObjectCount('Customer')).toEqual(expectedCustomer);
		});
	});

	it("VT295-034 | isSyncing() method when sync is in progress | true ", function() {
		var myCallback = function(args) {
			expect(Rho.RhoConnectClient.isSyncing()).toEqual(true);
			callbackCalled = true;
		};

		runs(function() {
			Rho.RhoConnectClient.login('testuser','testuser',function(){
				Rho.RhoConnectClient.setNotification('*', callbackFunction);
				Rho.RhoConnectClient.doSync();
			});
		});

		waitsFor(function() {
			return callbackCalled;
		}, "wait", 6000);
	});

	it("VT295-035 | isSyncing() method when sync is not in progress | false ", function() {
		runs(function() {
			expect(Rho.RhoConnectClient.isSyncing()).toEqual(false);
		});
	});

	it("VT295-036 | stopSync() method | zero records", function() {
		var timeoutCalled = false;
		runs(function() {
			Rho.RhoConnectClient.login('testclient','testclient',function(){
				Rho.RhoConnectClient.setNotification('*', callbackFunction);
				Rho.RhoConnectClient.doSync();
				Rho.RhoConnectClient.stopSync();
			});
			setTimeout(function(){
				timeoutCalled = true;
			}, 5000);
		});

		waitsFor(function() {
			return timeoutCalled && !callbackCalled;
		}, "wait", 6000);

		runs(function() {
			expect(Product.count()).toEqual(0);
			expect(Customer.count()).toEqual(0);
		});
	});


	// it("VT295-037 | stopSync() followed by doSync() | records should be synchronized", function() {
	// 	var timeoutCalled = false;
	// 	runs(function() {
	// 		Rho.RhoConnectClient.login('testclient','testclient',function(){
	// 			Rho.RhoConnectClient.setNotification('*', callbackFunction);
	// 			Rho.RhoConnectClient.doSync();
	// 			Rho.RhoConnectClient.stopSync();
	// 		});
	// 		setTimeout(function(){
	// 			timeoutCalled = true;
	// 		}, 5000);
	// 	});

	// 	waitsFor(function() {
	// 		return timeoutCalled && !callbackCalled;
	// 	}, "wait", 6000);

	// 	runs(function() {
	// 		Rho.RhoConnectClient.setNotification('*', callbackFunction);
	// 		Rho.RhoConnectClient.doSync();
	// 	});

	// 	runs(function() {
	// 		expect(Product.count()).toBeGreaterThan(0);
	// 		expect(Customer.count()).toBeGreaterThan(0);
	// 	});
	// });

	it("VT295-038 | doSyncSource method for product model | only product model should sync", function() {
		runs(function() {
			Rho.RhoConnectClient.login('testclient','testclient',function(){
				Rho.RhoConnectClient.setNotification('*', callbackFunction);
				Rho.RhoConnectClient.doSyncSource('Product');
			});
		});

		waitsFor(function() {
			return callbackCalled;
		}, "wait", 6000);

		runs(function(){
			expect(Product.count()).toBeGreaterThan(0);
			expect(Customer.count()).toEqual(0);
		});
	});

	it("VT295-040 | doSyncSource() method with empty parameters | callback should not be called", function() {
		var timeoutCalled = false;
		runs(function() {
			Rho.RhoConnectClient.login('testclient','testclient',function(){
				Rho.RhoConnectClient.setNotification('*', callbackFunction);
				Rho.RhoConnectClient.doSyncSource();
				setTimeout(function(){
					timeoutCalled = true;
				}, 5000);
			});
		});

		waitsFor(function() {
			return !callbackCalled && timeoutCalled;
		}, "wait", 6000);

		runs(function(){
			expect(Product.count()).toEqual(0);
			expect(Customer.count()).toEqual(0);
		});
	});

    //  it("VT295-044 | set notification for specific source model and call doSyncSource() method | Notification call back should get fire and all sync status should be reported", function() {
    //   //should report all sync status [in progress,ok and complete]
    // });

	it("VT295-054 | pollInterval when set to 5 seconds | callback should fire after 5 seconds ", function() {
		var callback1 = false,
				callback2 = false,
				timeoutCalled = false;

		runs(function() {
			Rho.RhoConnectClient.login('testclient','testclient',function(){
				Rho.RhoConnectClient.setNotification('*', function(){ callback1 = true; });
				Rho.RhoConnectClient.pollInterval = 5;
				Rho.RhoConnectClient.doSync();
			});
		});

		waitsFor(function() {
			return callback1;
		}, "wait 1", 10000);

		runs(function() {
			Rho.RhoConnectClient.setNotification('*', callbackFunction);
			setTimeout(function(){
				timeoutCalled = true;
			}, 5000);
		});

		waitsFor(function() {
			return timeoutCalled;
		}, "wait 2", 6000);

		runs(function() {
			expect(callbackCalled).toBe(true);
			expect(Product.count()).toBeGreaterThan(0);
			expect(Customer.count()).toBeGreaterThan(0);
		});
	});


		// it("VT295-055 | pollInterval property when set to 0 seconds | call back should not get fire  ", function() {
		// 	Rho.RhoConnectClient.pollInterval=0;
		// 	Rho.RhoConnectClient.setNotification('*', sync_notify_callback);
		// 	runs(function() {
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
		// 		runs(function() {
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
		// 	 runs(function() {
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

    // it("VT295-062 | Sync the record data when device comes back into network | Sync should be successful.", function() {
    //      // it should be manual
    //  });
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
		// 	 runs(function() {
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

	// it("VT295-071 | Record Sync stress Test  | All created records should get reflected at server side", function() {

 //       //memory leak test - Should be possible to run this as a script on a device every night or something

 //    });

 //    it("VT295-072 | Reset Sync stress Test   |  sync should be successful after 8 hours", function() {

 //       //memory leak test - Should be possible to run this as a script on a device every night or something.

 //     });

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


	it("VT295-006 | Call isLoggedIn() when client is not logged in to server | false", function() {
		Rho.RhoConnectClient.logout();
		runs(function() {
			expect(Rho.RhoConnectClient.isLoggedIn()).toEqual(false);
		});
	});

	it("VT295-009 | Get username when user is logged out | string", function() {
		runs(function() {
			Rho.RhoConnectClient.login('testclient','testclient',function(){
				Rho.RhoConnectClient.setNotification('*', callbackFunction);
				Rho.RhoConnectClient.doSync();
			});
		});

		waitsFor(function() {
			return callbackCalled;
		}, "wait", 6000);

		runs(function() {
			Rho.RhoConnectClient.logout();
			expect(Rho.RhoConnectClient.userName).toEqual('testclient');
		});
	});
});
