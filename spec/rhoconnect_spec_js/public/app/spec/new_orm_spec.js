	describe("ORM onSyncError, onUpdateError, onDeleteError testcases",function(){
		var model;
  		var object;
  		var SYNC_SERVER_HOST = "10.186.5.184";
  		var SYNC_SERVER_PORT = 9292;
  		var syncServerUrl = "http://"+SYNC_SERVER_HOST+":"+SYNC_SERVER_PORT;
  		Rho.RhoConnectClient.syncServer = syncServerUrl;

		function reset() {
			Rho.ORM.clear();
			var partitions = Rho.ORMHelper.getDbPartitions();
			$.each(partitions, function(index, db2) {
			  db2.executeSql("delete FROM SOURCES");
			  db2.executeSql("DELETE FROM OBJECT_VALUES");
			  db2.executeSql("DELETE FROM CHANGED_VALUES");
			  db2.executeSql("DELETE FROM CLIENT_INFO");
			});
		};

		var modelDef = function(model){
		    model.setModelProperty("name", "string", "");
		    model.setModelProperty("industry", "string", "");
		    model.enable("sync");
  		};

		beforeEach(function() {
		    reset();
		    model = Rho.ORM.addModel('Syncerror', modelDef);
		    model.deleteAll();
		    object = model.make({'key': 'value'});

		    var has_reset = false;
			var resetCallback = function() {
				has_reset =true;
			};
			runs(function() {
				var resetProps = {
					url: syncServerUrl + '/rc/v1/system/reset',
					headers: {'X-RhoConnect-API-TOKEN':'my-rhoconnect-token',
							  'Content-Type': 'application/x-www-form-urlencoded'
					}
				};
				Rho.Network.post(resetProps, resetCallback);
			});

			waitsFor(function() {
				return has_reset;
			}, "Timeout", 20000);
	  	});

		xit("should delete record from local database on create error during sync when onSyncCreateError called with delete option", function(){
			var on_sync_create_error_called = false;
			var callback3 = false;
			runs(function() {
				Rho.RhoConnectClient.logout();
				Rho.RhoConnectClient.login('testuser2','testuser2',function(){
					Rho.RhoConnectClient.clearNotification('*');
					Rho.RhoConnectClient.setNotification('*', function(args){
						if(args.status == 'complete') {
							callback3 = true;
						}
					});
					Rho.RhoConnectClient.doSync();
				});
			});

			waitsFor(function() {
				return callback3;
			}, "wait for initial sync to complete", 20000);

			runs(function() {
				model.createObject({"name":"Acme6", "industry":"Electronics6"});
				Rho.RhoConnectClient.clearNotification('*');
				Rho.RhoConnectClient.setNotification('*', function(args){
					if(args.status == 'error') {
						var createError = args['server_errors']['create-error'];
						var arr = Object.keys(createError);

				    	if (args['server_errors'] && args['server_errors']['create-error']){
							model.onSyncCreateError(arr,"delete");
							on_sync_create_error_called = true;
						}
					}
				});
				Rho.RhoConnectClient.doSync();
			});

			waitsFor(function(){
				return on_sync_create_error_called;
			},"Waiting on create error to be called",10000);

			runs(function(){
				data = ormSpecHelper.find(model,"all","name = ?",["Acme6"],{},['name','industry']);
				expect(data).toBe([]);
			});
		});

		xit("should recreate record in local database on create error during sync when onSyncCreateError called with recreate option", function(){
			var on_sync_create_error_called = false;
			var callback3 = false;
			runs(function() {
				Rho.RhoConnectClient.logout();
				Rho.RhoConnectClient.login('testuser2','testuser2',function(){
					Rho.RhoConnectClient.clearNotification('*');
					Rho.RhoConnectClient.setNotification('*', function(args){
						if(args.status == 'complete') {
							callback3 = true;
						}
					});
					Rho.RhoConnectClient.doSync();
				});
			});

			waitsFor(function() {
				return callback3;
			}, "wait for initial sync to complete", 20000);

			runs(function() {
				model.createObject({"name":"Acme6", "industry":"Electronics6"});
				Rho.RhoConnectClient.clearNotification('*');
				Rho.RhoConnectClient.setNotification('*', function(args){
					if(args.status == 'error') {
						var createError = args['server_errors']['create-error'];
						var arr = Object.keys(createError);

				    	if (args['server_errors'] && args['server_errors']['create-error']){
							model.onSyncCreateError(arr,"recreate");
							on_sync_create_error_called = true;
						}
					}
				});
				Rho.RhoConnectClient.doSync();
			});

			waitsFor(function(){
				return on_sync_create_error_called;
			},"Waiting on create error to be called",10000);

			runs(function(){
				data = ormSpecHelper.find(model,"all","name = ?",["Acme6"],{},['name','industry']);
				var dbUser = Rho.ORMHelper.dbConnection("user");
    			var dbchanged = dbUser.executeSql("SELECT * FROM CHANGED_VALUES WHERE object = "+ data[0]['object']);
    			expect(dbchanged[0].update_type).toEqual("create");
				expect(data[0]['name']).toBe("Acme6");
				expect(data[0]['industry']).toBe("Electronics6");
			});
		});

		xit("should retry to sync on update error during sync when onSyncUpdateError called with retry option", function(){
			var on_sync_update_error_called = false;
			var callback3 = false;
			runs(function() {
				Rho.RhoConnectClient.logout();
				Rho.RhoConnectClient.login('testuser2','testuser2',function(){
					Rho.RhoConnectClient.clearNotification('*');
					Rho.RhoConnectClient.setNotification('*', function(args){
						if(args.status == 'complete') {
							callback3 = true;
						}
					});
					Rho.RhoConnectClient.doSync();
				});
			});

			waitsFor(function() {
				return callback3;
			}, "wait for initial sync to complete", 20000);

			runs(function() {
				first_data = ormSpecHelper.find(model,"1");
				model.updateObject(first_data['object'], first_data, {"name": "BHAKTA1_1", "industry": "Electronics1"});

				Rho.RhoConnectClient.clearNotification('*');
				Rho.RhoConnectClient.setNotification('*', function(args){
					if(args.status == 'error') {
						var updateError = args['server_errors']['update-error'];
						var arr = Object.keys(updateError);
				    	if (args['server_errors'] && args['server_errors']['update-error']){
							model.onSyncUpdateError(arr[0],updateError[arr[0]]['attributes'],{},"retry");
							on_sync_update_error_called = true;
						}
					}
				});
				Rho.RhoConnectClient.doSync();
			});

			waitsFor(function(){
				return on_sync_update_error_called;
			},"Waiting on create error to be called",10000);

			runs(function(){
				data = ormSpecHelper.find(model,"1");
				var dbUser = Rho.ORMHelper.dbConnection("user");
    			var dbchanged = dbUser.executeSql("SELECT * FROM CHANGED_VALUES WHERE object = "+ data.object);
    			expect(dbchanged[0].update_type).toEqual("update");
    			expect(dbchanged[0].value).toEqual("BHAKTA1_1");
			});
		});

		xit("should rollback the update changes on update error during sync when onSyncUpdateError called with rollback option", function(){
			var on_sync_update_error_called = false;
			var callback3 = false;
			var first_data = undefined;
			runs(function() {
				Rho.RhoConnectClient.logout();
				Rho.RhoConnectClient.login('testuser2','testuser2',function(){
					Rho.RhoConnectClient.clearNotification('*');
					Rho.RhoConnectClient.setNotification('*', function(args){
						if(args.status == 'complete') {
							callback3 = true;
						}
					});
					Rho.RhoConnectClient.doSync();
				});
			});

			waitsFor(function() {
				return callback3;
			}, "wait for initial sync to complete", 20000);

			runs(function() {
				first_data = ormSpecHelper.find(model,"1");
				model.updateObject(first_data['object'], first_data, {"name": "BHAKTA1_1", "industry": "Electronics1"});

				Rho.RhoConnectClient.clearNotification('*');
				Rho.RhoConnectClient.setNotification('*', function(args){
					if(args.status == 'error') {
						var updateRollback = args['server_errors']['update-rollback'];
						var arr = Object.keys(updateRollback);
				    	if (args['server_errors'] && args['server_errors']['update-rollback']){
							model.onSyncUpdateError(arr[0],{},updateRollback[arr[0]]['attributes'],"rollback");
							on_sync_update_error_called = true;
						}
					}
				});
				Rho.RhoConnectClient.doSync();
			});

			waitsFor(function(){
				return on_sync_update_error_called;
			},"Waiting on create error to be called",10000);

			runs(function(){
				data = ormSpecHelper.find(model,"1");
				var dbUser = Rho.ORMHelper.dbConnection("user");
    			var dbchanged = dbUser.executeSql("SELECT * FROM CHANGED_VALUES WHERE object = "+ data.object);
    			expect(data.name).toEqual(first_data.name);
    			expect(data.industry).toEqual(first_data.industry);
			});
		});

		xit('should retry to delete data from server on delete error when onSyncDeleteError called with retry option', function(){
			var on_sync_delete_error_called = false;
			var callback3 = false;
			var first_data = undefined;
			runs(function() {
				Rho.RhoConnectClient.logout();
				Rho.RhoConnectClient.login('testuser2','testuser2',function(){
					Rho.RhoConnectClient.clearNotification('*');
					Rho.RhoConnectClient.setNotification('*', function(args){
						if(args.status == 'complete') {
							callback3 = true;
						}
					});
					Rho.RhoConnectClient.doSync();
				});
			});

			waitsFor(function() {
				return callback3;
			}, "wait for initial sync to complete", 20000);

			runs(function() {
				second_data = ormSpecHelper.find(model,"2");
				model.deleteObject(second_data.object);

				Rho.RhoConnectClient.clearNotification('*');
				Rho.RhoConnectClient.setNotification('*', function(args){
					if(args.status == 'error') {
						var deleteError = args['server_errors']['delete-error'];
						var arr = Object.keys(deleteError);
				    	if (args['server_errors'] && args['server_errors']['delete-error']){
							model.onSyncDeleteError(arr[0],deleteError[arr[0]]['attributes'],"retry");
							on_sync_delete_error_called = true;
						}
					}
				});
				Rho.RhoConnectClient.doSync();
			});

			waitsFor(function(){
				return on_sync_delete_error_called;
			},"Waiting on create error to be called",10000);

			runs(function(){
				var dbUser = Rho.ORMHelper.dbConnection("user");
    			var dbchanged = dbUser.executeSql("SELECT * FROM CHANGED_VALUES WHERE object = "+ 2);
    			expect(dbchanged[0].update_type).toEqual("delete");
    			expect(dbchanged[1].update_type).toEqual("delete");
			});
		});

		it('should trigger sync when pushchanges gets called',function(){
			var sync_after_create_completed = false;
			var before_sync_entry = undefined;
			var callback3 = false;

			runs(function() {
				Rho.RhoConnectClient.logout();
				Rho.RhoConnectClient.login('testuser2','testuser2',function(){
					Rho.RhoConnectClient.clearNotification('*');
					Rho.RhoConnectClient.setNotification('*', function(args){
						if(args.status == 'complete') {
							callback3 = true;
						}
					});
					Rho.RhoConnectClient.doSync();
				});
			});

			waitsFor(function() {
				return callback3;
			}, "wait for initial sync to complete", 20000);

			runs(function() {
				Rho.RhoConnectClient.clearNotification('*');
				Rho.RhoConnectClient.setNotification('*', function(args){
					if(args.status == 'complete') {
						sync_after_create_completed = true;
					}
				});
				model.pushChanges();
				Rho.RhoConnectClient.doSync();
			});

			waitsFor(function(){
				return sync_after_create_completed;
			},"Waiting to finish sync after create",10000);

			runs(function(){

			});
		});

	});



