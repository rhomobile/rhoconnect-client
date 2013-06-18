var sync_server_url = "http://"+SYNC_SERVER_HOST+":"+SYNC_SERVER_PORT;


describe("Rhoconnect Client module Test Starts Here", function() {

	beforeEach(function() {
			//Rho.RhoConnectClient.syncServer = setSyncSever to valid one
			Rho.ORM.clear();
			var db = new Rho.Database.SQLite3(Rho.Application.databaseFilePath('user'), 'user');
			db.execute("DELETE FROM SOURCES");
			db.execute("DELETE FROM CLIENT_INFO");
			db.execute("DELETE FROM OBJECT_VALUES");
			
			BlobTest = Rho.ORM.addModel( function(model){
			model.modelName("BlobTest");
			model.enable("sync");
			});
			
			// how to declare properties of blob type and other type
		});
		
	afterEach(function() {
			
    });
	
	
		it("VT295-108 | Create blob and do sync   | image uri property of particular blob file should get changed after sync", function() {  
			    file_name = Rho.RhoApplication.get_model_path('app',getBlobTest_str())+'test.png';
				copy_file(file_name, Rho::RhoApplication::get_blob_folder() )  // need to find equivalent function in javascript
				file_name = Rho.RhoApplication.get_blob_folder()+'test.png';
				file_content = File.read(file_name)
				
				//creates a blob record 
				var item = BlobTest.new();  
				item.name = 'BlobTestItem'
				item.image_uri = file_name
				item.save
				
				
				BlobTest.sync( "/app/Settings/sync_notify")
				sleep(2) #wait till sync server update data

				res =  BlobTest.sync( "/app/Settings/sync_notify")
				res['status'].should == 'ok'
				res['error_code'].to_i.should == ::Rho::RhoError::ERR_NONE

				items = BlobTest.find(:all ) #, :conditions => {:name => 'BlobTestItem'})
				items.should_not == nil
				items.length.should == 1
				
				items[0].image_uri.should_not == file_name
				new_file_name = File.join(Rho::RhoApplication::get_blob_path(items[0].image_uri))
  
				content_new = File.read(new_file_name)
				content_new.should == file_content
			
	
		});
		
		it("VT295-109 | Modify existing blob and sync  | image uri property of particular blob file should get changed after sync", function() {  
			 
			
	
		});
		
		it("VT295-110 | Delete the blob and sync  | Deleted blob object should not exist in db device folder", function() {  
			 
			
	
		});
		
});