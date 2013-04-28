#
#  blob_bulksync_spec.rb
#  rhodes
#
#  Copyright (C) 2012 Rhomobile, Inc. All rights reserved.
#
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

require 'rho/rho'
require 'sync_server'

describe "BlobBulkSync_test" do

  before(:all)  do
    SyncEngine.set_threaded_mode(false)
  
    ::Rhom::Rhom.database_full_reset_and_logout
    
	SyncEngine.set_syncserver("http://#{SYNC_SERVER_HOST}:#{SYNC_SERVER_PORT}")
	  
	Rho::RhoConfig.bulksync_state='1'
  end
	
  after(:all)  do
	Rho::RhoConfig.bulksync_state='1'
	sleep(2)
  end

  
  it "should login" do

    login_name = System.get_property('platform') + System.get_property('device_name')    
    res =  SyncEngine.login('login_name', '', "/app/Settings/login_callback")
    res['error_code'].to_i.should == ::Rho::RhoError::ERR_NONE
    
    SyncEngine.logged_in.should == 1
    
    Rho::RhoConfig.bulksync_state='1'

  end

  def copy_file(src, dst_dir)
if !defined?(RHO_WP7)  
    content = File.binread(src)  
else
    content = File.read(src)  
end    
    File.open(File.join( dst_dir, File.basename(src) ), "wb"){|f| f.write(content) }
  end

  def createBlob(model,dir,filename)
	  SyncEngine.logged_in.should == 1
	  
	  file_name = File.join(Rho::RhoApplication::get_model_path('app',dir),filename)
	  copy_file(file_name, Rho::RhoApplication::get_blob_folder() )
	  file_name = File.join(Rho::RhoApplication::get_blob_folder(), filename)
	  File.exists?(file_name).should == true
	  if !defined?(RHO_WP7)   
		file_size = File.size(file_name)
	  end    
	  file_content = File.read(file_name)
							
	  item = model.new
	  item.name = 'BlobTestItem'
	  item.image_uri = file_name
	  item.save
							
	  File.exists?(file_name).should == true
						
	  res =  model.sync( "/app/Settings/sync_notify")
	  res['status'].should == 'ok'
	  res['error_code'].to_i.should == ::Rho::RhoError::ERR_NONE
						
	  if (File.exists?(file_name))
		File.delete(file_name)
	  end
	  File.exists?(file_name).should == false
							
	  return file_size,file_content

  end
							
  propBagSize = 0
  propBagContent = nil
  fixedSchemaSize = 0
  fixedSchemaContent = nil

  it "should create property bag blob" do
	propBagSize, propBagContent = createBlob(BlobBulkTest,'BlobBulkTest','blob_bulk_test.png')
  end

  it "should create fixed schema blob" do
	fixedSchemaSize, fixedSchemaContent = createBlob(BlobBulkTest_s,'BlobBulkTest_s','blob_bulk_test_s.png')
  end
							
  def checkBlob(model,size,content,old_filename)
	items = model.find(:all, :conditions => { :name => old_filename} )
	items.should_not == nil
	items.length.should == 1
	puts "items = #{items.inspect}"
							
	items[0].image_uri.should_not == old_filename
	new_file_name = File.join(Rho::RhoApplication::get_blob_path(items[0].image_uri))
	File.exists?(new_file_name).should == true
	if !defined?(RHO_WP7)    
	  File.size(new_file_name).should == size
	end    
	content_new = File.read(new_file_name)
	content_new.should == content
  end

  it "should bulk sync blobs" do
	Rho::RhoConfig.bulksync_state='0'
	res =  SyncEngine.dosync
							
	res['status'].should == 'complete'
	res['error_code'].to_i.should == ::Rho::RhoError::ERR_NONE
							
	checkBlob(BlobBulkTest,propBagSize,propBagContent,'blob_bulk_test.png')
	checkBlob(BlobBulkTest_s,fixedSchemaSize,fixedSchemaContent,'blob_bulk_test_s.png')
  end
							
  def deleteBlob(model)
	SyncEngine.logged_in.should == 1
							
	model.delete_all
	Rho::RhoConfig.bulksync_state='1'
	model.sync("/app/Settings/SyncNotify")
							
	items = model.find(:all)
	items.should_not == nil
	items.length.should == 0
  end

  it "should create objects after bulk sync" do
    propBagItem = BlobBulkTest.new
    propBagItem.name = "test"
    propBagItem.should_not be_nil

    schemaItem = BlobBulkTest_s.new
    schemaItem.name = "test"
    schemaItem.should_not be_nil
  end

it "should export database after blob bulk sync" do
	Rhom::Rhom.database_full_reset
	login_name = System.get_property('platform') + System.get_property('device_name')
	res =  SyncEngine.login('login_name', '', "/app/Settings/login_callback")
	res['error_code'].to_i.should == ::Rho::RhoError::ERR_NONE
	SyncEngine.logged_in.should == 1
	
	sleep(15)
	
	Rho::RhoConfig.bulksync_state='0'
	res =  SyncEngine.dosync
	
	res['status'].should == 'complete'
	res['error_code'].to_i.should == ::Rho::RhoError::ERR_NONE
	
	items = BlobBulkTest.find(:all)
	items.size.should_not == 0
	pbSize = items.size
	items.each do |item|
		path = File.join(Rho::RhoApplication::get_blob_path(item.image_uri))
		puts "item = #{item.inspect}, path = #{path}"
		File.exists?(path).should == true
	end
	items = BlobBulkTest_s.find(:all)
	items.size.should_not == 0
	shSize = items.size
	items.each do |item|
		path = File.join(Rho::RhoApplication::get_blob_path(item.image_uri))
		puts "item = #{item.inspect}, path = #{path}"
		File.exists?(path).should == true
	end
	
	exportPath = ::Rhom::Rhom.database_export('user')
	exportPath.should_not be_nil
	File.exists?(exportPath).should == true
	File.size(exportPath).should_not == 0
	
	Rhom::Rhom.database_full_reset
	
	items = BlobBulkTest_s.find(:all)
	puts "BlobBulkTest_s = #{items}"
	items.size.should == 0
	
	items = BlobBulkTest.find(:all)
	puts "BlobBulkTest = #{items}"
	items.size.should == 0
	
	::Rhom::Rhom.database_import('user',exportPath).should == true
	
	items = BlobBulkTest_s.find(:all)
	items.size.should == shSize
	items.each do |item|
		path = File.join(Rho::RhoApplication::get_blob_path(item.image_uri))
		puts "item = #{item.inspect}, path = #{path}"
		File.exists?(path).should == true
	end
	
	items = BlobBulkTest.find(:all)
	items.size.should == pbSize
	items.each do |item|
		path = File.join(Rho::RhoApplication::get_blob_path(item.image_uri))
		puts "item = #{item.inspect}, path = #{path}"
		File.exists?(path).should == true
	end
	
	File.delete(exportPath)
	File.exists?(exportPath).should == false
end

  it "should logout" do
    SyncEngine.logout()
  
    SyncEngine.logged_in.should == 0
  end
end
