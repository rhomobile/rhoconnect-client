class Product < Rhoconnect::Model::Base
  def initialize(source) 
    super(source)
    $key = "id"
  end
 
  def login
    # TODO: Login to your data source here if necessary
  end
 
  def query(params=nil)
    # TODO: Query your backend data source and assign the records 
    # to a nested hash structure called @result. For example:
    @result = { 
      "1"=>{"name"=>"Acme1", "industry"=>"Electronics1"},
      "2"=>{"name"=>"Best1", "industry"=>"Software1"},
      "3"=>{"name"=>"Acme2", "industry"=>"Electronics2"},
      "4"=>{"name"=>"Best2", "industry"=>"Software2"},
      "5"=>{"name"=>"Acme3", "industry"=>"Electronics3"},
      "6"=>{"name"=>"Best3", "industry"=>"Software3"},
      "7"=>{"name"=>"Acme4", "industry"=>"Electronics4"},
      "8"=>{"name"=>"Best4", "industry"=>"Software4"},
      "9"=>{"name"=>"Acme5", "industry"=>"Electronics5"},
      "10"=>{"name"=>"Best5", "industry"=>"Software5"}
    }
    #raise Rhoconnect::Model::Exception.new("Please provide some code to read records from the backend data source")
  end

  def create(create_hash)
    puts "#{create_hash.inspect}"
    value = Store.get_value($key)
    if(value)
      value = value.to_i + 1
    else
      value = 11
    end
    Store.put_value($key, value)

    if create_hash['name'] == "Acme6"
      raise Rhoconnect::Model::Exception.new("Error creating record.")
    end

    value

    # TODO: Create a new record in your backend data source
    #raise "Please provide some code to create a single record in the backend data source using the create_hash"
  end
 
  def update(update_hash)
    puts "#{update_hash.inspect}"
    raise Rhoconnect::Model::Exception.new("Error updating record.")
    # TODO: Update an existing record in your backend data source
    #raise "Please provide some code to update a single record in the backend data source using the update_hash"
  end
 
  def delete(delete_hash)
    puts "#{delete_hash.inspect}"
    raise Rhoconnect::Model::Exception.new("Error deleting record.")
    # TODO: write some code here if applicable
    # be sure to have a hash key and value for "object"
    # for now, we'll say that its OK to not have a delete operation
    # raise "Please provide some code to delete a single object in the backend application using the object_id"
  end
 
  def logoff
    # TODO: Logout from the data source if necessary
  end

  def store_blob(object,field_name,blob)
    # TODO: Handle post requests for blobs here.
    # make sure you store the blob object somewhere permanently
    raise "Please provide some code to handle blobs if you are using them."
  end
end