require 'rhom'

class Syncerror

    include Rhom::PropertyBag

    enable :sync
    #set :partition, :application
    set :sync_priority, 100  #sync engine should reorder sources

end