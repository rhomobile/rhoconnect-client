require 'mspec'
require 'local_server'

class SpecRunner < MSpecScript
  def initialize
    config[:files] = []
	  @results_path = File.join( Rho::RhoApplication.get_base_app_path(), 'test_results.xml' )
	  # for android path is  /data/data/com.rhomobile.rhoconnect_spec/rhodata/apps/test_results.xml

    @@formatter = JUnitRhoLogFormatter.new( @results_path )
    @@formatter.register

    @@resulter = JasmineLikeFormatter.new()
    @@resulter.register

	  # turn on exception backtrace
	  MSpec.backtrace = true

	  config[:files] << [ "spec/syncengine_spec", [ {:schema_model=>true }, {:schema_model=>false } ] ]
		unless Rho::System.platform == "WINDOWS" || Rho::System.platform == "WINDOWS_DESKTOP"
  	  config[:files] << [ "spec/blobsync_spec", [ {:schema_model=>true }, {:schema_model=>false } ] ]
  	  config[:files] << "spec/bulksync_spec"
  	  config[:files] << "spec/blob_bulksync_spec"
    end
    config[:files] << "spec/ssl_spec"
  end

  def run
    MSpec.register_files config[:files]
    MSpec.process
    exit_code = MSpec.exit_code

    postProps = Hash.new
    postProps['url'] = "http://#{SPEC_LOCAL_SERVER_HOST}:#{SPEC_LOCAL_SERVER_PORT}?filename=#{File.basename(@results_path)}"
    contents = File.read(@results_path)
    postProps['body'] = contents
    res = Rho::Network.post(postProps)
    puts "Post #{File.basename(@results_path)} to local server. Status: #{res['status']}"

    Rho::Log.info("***Terminated","APP")

    exit_code
  end

end
