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
require 'rho/render'
require 'rho/rhoapplication'
require 'rhom'
require 'rhofsconnector'
require 'rho/rhoerror'
require 'rhom/rhom_source'

module SyncEngine
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
    
    def self.search(args)
        searchParams = ""

        searchParams += '&offset=' + Rho::RhoSupport.url_encode(args[:offset]) if args[:offset]
        searchParams += '&max_results=' + Rho::RhoSupport.url_encode(args[:max_results]) if args[:max_results]

        callbackParams = args[:callback_param] ? args[:callback_param] : ""

        if args[:search_params]
            args[:search_params].each do |key,value|
              searchParams += '&' + "search[#{Rho::RhoSupport.url_encode(key)}]" + '=' + Rho::RhoSupport.url_encode(value)
              callbackParams += '&' + "search_params[#{Rho::RhoSupport.url_encode(key)}]" + '=' + Rho::RhoSupport.url_encode(value)
            end  
        end

        SyncEngine.dosearch( args[:source_names], args[:from] ? args[:from] : 'search',
            searchParams, args[:sync_changes] ? args[:sync_changes] : false, args[:progress_step] ? args[:progress_step] : -1,
            args[:callback], callbackParams )
    end
end
