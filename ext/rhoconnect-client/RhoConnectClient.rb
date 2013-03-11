#------------------------------------------------------------------------
# (The MIT License)
# 
# Copyright (c) 2008-2011 Rhomobile, Inc.
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
# 
# http://rhomobile.com
#------------------------------------------------------------------------

#require 'time'
=begin
require 'rho/render'
require 'rho/rhoapplication'
require 'rhom'
require 'rhofsconnector'
require 'rho/rhoerror'
require 'rhom/rhom_source'
=end


module Rho

class RhoConnectClient

    def self.get_user_name
        Rho::RhoConfig.rho_sync_user        
    end
    
    def self.on_sync_create_error( src_name, objects, action )
        raise ArgumentError, 'on_sync_create_error src_name should be string' unless src_name.is_a?(String)
        
        Object.const_get(src_name).on_sync_create_error(objects, action)
    end

    def self.push_changes( src_name )
        raise ArgumentError, 'push_changes src_name should be string' unless src_name.is_a?(String)
        
        Object.const_get(src_name).push_changes()
    end

    def self.on_sync_update_error( src_name, objects, action, rollback_data = nil )
        raise ArgumentError, 'on_sync_update_error src_name should be string' unless src_name.is_a?(String)
    
        Object.const_get(src_name).on_sync_update_error(objects, action, rollback_data)
    end

    def self.on_sync_delete_error( src_name, objects, action )
        raise ArgumentError, 'on_sync_delete_error src_name should be string' unless src_name.is_a?(String)
    
        Object.const_get(src_name).on_sync_delete_error(objects, action)
    end

	def self.getSourceNameById( sourceId )
		puts "getSourceNameById: #{sourceId}"
		if -1 == sourceId
			puts "sourceId is -1, return special value '*'"
			return '*'
		else
			Rho::RhoConfig::sources.values.each do |src|
				puts "source: #{src.inspect}"
				if src['source_id'] == sourceId
					puts "source found, returning name: #{src['name']}"
					return src['name']
				end
			end
		end

		puts "source with id: #{sourceId} not found"
		nil
	end



#	vvv DEPRECATED vvv


	def self.set_threaded_mode( threaded )
		RhoConnectClient.threadedMode = threaded
	end

	def self.set_ssl_verify_peer( verify )
		RhoConnectClient.sslVerifyPeer = verify
	end

	def self.set_pollinterval( interval )
		ret = RhoConnectClient.pollInterval
		RhoConnectClient.pollInterval = interval
		ret
	end

	def self.get_pollinterval()
		RhoConnectClient.pollInterval
	end

	def self.set_syncserver(url)
		RhoConnectClient.syncServer = url
	end

	def self.set_pagesize(size)
		RhoConnectClient.pageSize = size
	end

	def self.get_pagesize
		RhoConnectClient.pageSize
	end

	def self.enable_status_popup(enable)
		RhoConnectClient.showStatusPopup = enable
	end

	def self.dosync_source(source,show_status_popup=0,query_params="")
		src = source
		if source.is_a?(Integer) then
			src = RhoConnectClient.getSourceNameById(source)
		end
		RhoConnectClient.doSyncSource(src,show_status_popup!=0,query_params)
	end

	def self.set_notification(source,callback,callback_param)
		RhoConnectClient.setNotification( RhoConnectClient.getSourceNameById(source), callback, callback_param )
	end

	def self.clear_notification(source)
		RhoConnectClient.clearNotification( RhoConnectClient.getSourceNameById(source) )
	end

	def self.add_objectnotify(source,object)
		RhoConnectClient.addObjectNotify( RhoConnectClient.getSourceNameById(source), object )
	end

	def self.get_lastsync_objectcount(source)
		RhoConnectClient.getLastSyncObjectCount( RhoConnectClient.getSourceNameById( source ) )
	end

	def self.set_source_property(source,propertyName,propertyValue)
		RhoConnectClient.setSourceProperty( RhoConnectClient.getSourceNameById(source), propertyName, propertyValue )
	end

	def self.get_source_property(source,propertyName)
		RhoConnectClient.getSourceProperty( RhoConnectClient.getSourceNameById(source), propertyName )
	end

	def self.logged_in
		RhoConnectClient.loggedIn?()? 1 : 0
	end

	def self.is_syncing
		RhoConnectClient.syncing?()? 1 : 0
	end

	def self.set_objectnotify_url(url)
		RhoConnectClient.setObjectNotification(url)
	end
end

end
