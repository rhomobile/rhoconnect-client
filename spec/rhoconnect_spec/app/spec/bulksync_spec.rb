#
#  bulksync_spec.rb
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
require 'sync_server'

describe "BulkSync_test" do

  before(:all)  do
    SyncEngine.set_threaded_mode(false)
  
    ::Rhom::Rhom.database_full_reset_and_logout
    
	SyncEngine.set_syncserver("http://#{SYNC_SERVER_HOST}:#{SYNC_SERVER_PORT}")

    Rho::RhoConfig.bulksync_state='0'

    Rho::RHO.load_all_sources()
    @save_sync_types = ::Rho::RHO.get_user_db().select_from_table('sources','name, sync_type')

    ::Rho::RHO.get_user_db().update_into_table('sources',{'sync_type'=>'none'})
    ::Rho::RHO.get_user_db().update_into_table('sources',{'sync_type'=>'incremental'}, {'name'=>'Product'})
  end

  after(:all)  do
    @save_sync_types.each do |src|
        ::Rho::RHO.get_user_db().update_into_table('sources',{'sync_type'=>src['sync_type']}, {'name'=>src['name']})
    end
    Rho::RhoConfig.bulksync_state='1'
  end

  it "should login" do
    res =  SyncEngine.login("te st", "test", "/app/Settings/login_callback")
    res['error_code'].to_i.should == ::Rho::RhoError::ERR_NONE
    
    SyncEngine.logged_in.should == 1
  end
	
  def do_bulk_sync
	towait = 15
	puts "Waiting #{towait} secs for next bulk data"
	sleep(towait)
	Rho::RhoConfig.bulksync_state='0'
	res =  SyncEngine.dosync
	res['status'].should == 'complete'
	res['error_code'].to_i.should == ::Rho::RhoError::ERR_NONE
	Rho::RhoConfig.bulksync_state.should=='1'
  end

  it "should bulk sync" do
    SyncEngine.logged_in.should == 1

	do_bulk_sync
	  
    items = Product.find(:all)
    items.should_not be_nil
    items.length().should_not == 0
  end

  it "should bulk sync with create" do
	  
    SyncEngine.logged_in.should == 1
    ::Rhom::Rhom.database_full_reset_and_logout
    
    res =  SyncEngine.login("te st", "test", "/app/Settings/login_callback")
    res['error_code'].to_i.should == ::Rho::RhoError::ERR_NONE
    SyncEngine.logged_in.should == 1

    Rho::RhoConfig.bulksync_state='1'
    res =  SyncEngine.dosync
    res['status'].should == 'complete'
    res['error_code'].to_i.should == ::Rho::RhoError::ERR_NONE

    item1 = Product.create({'name'=>'PhoneSpec', 'sku'=>22})  
    
	do_bulk_sync
    
    items = Product.find(:all)
	puts "items = #{items.inspect}"
    items.should_not be_nil
    items.length().should_not == 0
    
    item2 = Product.find(item1.object)
    item2.should be_nil

    items2 = Product.find(:all, :conditions=>{:name=>'PhoneSpec'} )
	puts "items2 = #{items2.inspect}"
    items2.should_not be_nil
    items2.length().should_not == 0

    bFound22 = false
    items2.each do |item|
        bFound22 = item.sku == '22' if !bFound22
        
        item.sku = '44'
        item.save
    end    
    bFound22.should == true

	  do_bulk_sync

    items2 = Product.find(:all, :conditions=>{:name=>'PhoneSpec'} )
	puts "items2 = #{items2.inspect}"
    items2.should_not be_nil
    items2.length().should_not == 0

    items2.each do |item|
        item.sku.should == '44'
        
        item.destroy
    end
	  
	  do_bulk_sync
	  
    items2 = Product.find(:all, :conditions=>{:name=>'PhoneSpec'} )
    items2.should_not be_nil
    items2.length().should == 0

end

  def is_source_present(src)
	  result = ::Rho::RHO.get_user_db().select_from_table('sources','name',{'name'=>src})
	  return (result != nil) && (result.length() > 0)
  end

  it "should do selective bulk sync" do
	  
	  
	  res =  SyncEngine.login("te st", "test", "/app/Settings/login_callback")
	  res['error_code'].to_i.should == ::Rho::RhoError::ERR_NONE
	  SyncEngine.logged_in.should == 1
	  
	  ::Rho::RHO.get_user_db().update_into_table('sources',{'sync_type'=>'incremental'}, {'name'=>'Customer'})
	  ::Rho::RHO.get_user_db().update_into_table('sources',{'sync_type'=>'incremental'}, {'name'=>'Product'})
	  
	  do_bulk_sync
	  
	  is_source_present('Product').should == true
	  is_source_present('Customer').should == true
	  
	  products = Product.find(:all)
	  products.should_not be_nil
	  products.length().should_not == 0
	  
	  customers = Customer.find(:all)
	  customers.should_not be_nil
	  customers.length().should_not == 0
	  
	  ::Rho::RHO.get_user_db().update_into_table('sources',{'sync_type'=>'none'}, {'name'=>'Product'})
	  
	  do_bulk_sync

	  is_source_present('Product').should == true
	  is_source_present('Customer').should == true
	  
	  products = Product.find(:all)
	  puts "products = #{products.inspect}"
	  products.length().should == 0
	  
	  customers = Customer.find(:all)
	  customers.should_not be_nil
	  customers.length().should_not == 0
  end

  it "should logout" do
    SyncEngine.logout()
  
    SyncEngine.logged_in.should == 0
  end

end
