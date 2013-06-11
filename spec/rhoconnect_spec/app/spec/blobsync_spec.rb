#
#  blobsync_spec.rb
#  rhodes
#
#  Copyright (C) 2008 Rhomobile, Inc. All rights reserved.
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
#require 'spec/spec_helper'
require 'rho/rho'
#require 'fileutils'
require 'sync_server'

def getBlobTest
    return BlobTest_s if $spec_settings[:schema_model]
    
    BlobTest
end

def getBlobTest_str
    return 'BlobTest_s' if $spec_settings[:schema_model]
    
    'BlobTest'
end

describe "BlobSync_test" do

  before(:all)  do
    Rho::RhoConnectClient.threadedMode = false
  
    ::Rhom::Rhom.database_full_reset_and_logout

	Rho::RhoConnectClient.syncServer = "http://#{SYNC_SERVER_HOST}:#{SYNC_SERVER_PORT}"    
  end
  
  before(:each) do  
    res =  Rho::RhoConnectClient.login('login_name', '', "/app/Settings/login_callback")
    res['error_code'].to_i.should == ::Rho::RhoError::ERR_NONE

    Rho::RhoConnectClient.isLoggedIn.should == true
    Rho::RhoConfig.bulksync_state = '1'  
  end

  def copy_file(src, dst_dir)
if !defined?(RHO_WP7)  
    content = File.binread(src)  
else
    content = File.read(src)  
end    
    File.open(File.join( dst_dir, File.basename(src) ), "wb"){|f| f.write(content) }
  end
  
  it "should create new BlobTest" do
    file_name = File.join(Rho::RhoApplication::get_model_path('app',getBlobTest_str()), 'test.png')
    copy_file(file_name, Rho::RhoApplication::get_blob_folder() )
    file_name = File.join(Rho::RhoApplication::get_blob_folder(), 'test.png')
if !defined?(RHO_WP7)   
    file_size = File.size(file_name)
end    
    file_content = File.read(file_name)
    
    item = getBlobTest.new
    item.name = 'BlobTestItem'
    item.image_uri = file_name
    item.save
    getBlobTest.sync( "/app/Settings/sync_notify")
    sleep(2) #wait till sync server update data

    res =  getBlobTest.sync( "/app/Settings/sync_notify")
    res['status'].should == 'ok'
    res['error_code'].to_i.should == ::Rho::RhoError::ERR_NONE

    items = getBlobTest.find(:all ) #, :conditions => {:name => 'BlobTestItem'})
    items.should_not == nil
    items.length.should == 1
    
    items[0].image_uri.should_not == file_name
    new_file_name = File.join(Rho::RhoApplication::get_blob_path(items[0].image_uri))
if !defined?(RHO_WP7)    
    File.size(new_file_name).should == file_size
end    
    content_new = File.read(new_file_name)
    content_new.should == file_content
    
  end

  it "should modify BlobTest" do
    item = getBlobTest.find(:first)
    item.should_not == nil
    saved_obj = item.object

    file_name = File.join(Rho::RhoApplication::get_model_path('app',getBlobTest_str()), 'test2.png')
    copy_file(file_name, Rho::RhoApplication::get_blob_folder() )
    file_name = File.join(Rho::RhoApplication::get_blob_folder(), 'test2.png')
    
#    file_size = File.size(file_name)
#    file_content = File.read(file_name)
    
    old_file = item.image_uri
    item.image_uri = file_name
    item.save
    File.exists?(old_file).should == false
    
    getBlobTest.sync( "/app/Settings/sync_notify")
    sleep(2) #wait till sync server update data

    res =  getBlobTest.sync( "/app/Settings/sync_notify")
    res['status'].should == 'ok'
    res['error_code'].to_i.should == ::Rho::RhoError::ERR_NONE
    
    item2 = getBlobTest.find(saved_obj)
    item2.should_not be_nil
    
    item2.image_uri.should == file_name
#    new_file_name = File.join(Rho::RhoApplication::get_blob_path(item2.image_uri))
#    File.size(new_file_name).should == file_size
#    content_new = File.read(new_file_name)
#    content_new.should == file_content
    
  end
end
