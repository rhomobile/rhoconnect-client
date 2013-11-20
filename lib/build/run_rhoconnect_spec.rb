require 'fileutils'
require File.join($rho_root,'lib','build','jake.rb')
require File.join($rho_root,'lib','build','rhoconnect_helper.rb')

def run_rhoconnect_spec(platform,appname,flags)
	test_appname = "testapp"
	puts "run_spec_app(#{platform},#{appname})"

	rhobuildyml = File.join($rho_root,'rhobuild.yml')
	$app_path = File.expand_path(File.join(File.dirname(__FILE__),'..','..','spec',appname))
	puts "app path: #{$app_path}"

	$app_config = Jake.config(File.open(File.join($app_path, "build.yml")))
	config = Jake.config(File.open(rhobuildyml,'r'))

	source_path = File.expand_path(File.join($app_path,'..','server'))
	$tmp_path = File.join(File.dirname(__FILE__),'..','..','tmp')

	cleanup_apps

	FileUtils.mkdir_p File.expand_path($tmp_path)
	server_path = File.expand_path(File.join($tmp_path,'testapp'))

	$rhoconnect_bin = "#{$rhoconnect_root}/bin/rhoconnect"
	puts "$rhoconnect_bin: #{$rhoconnect_bin}"

	RhoconnectHelper.set_rhoconnect_bin $rhoconnect_root
	puts "rhoconnect_bin: #{RhoconnectHelper.rhoconnect_bin}"

	RhoconnectHelper.set_rc_out File.open( File.join($app_path, "rhoconnect.log" ), "w")
	RhoconnectHelper.set_redis_out File.open( File.join($app_path, "redis.log" ), "w")
	RhoconnectHelper.set_resque_out File.open( File.join($app_path, "resque.log" ), "w")
	RhoconnectHelper.set_rc_push_out File.open( File.join($app_path, "rc_push.log" ), "w")
	RhoconnectHelper.set_enable_push(false)
	RhoconnectHelper.set_enable_rails(false)
  pong = `redis-cli ping`
	RhoconnectHelper.set_enable_redis(!(pong =~ /PONG/)) # Do not touch redis if it's running

	RhoconnectHelper.stop_rhoconnect_stack

  @mutex  = Mutex.new
  # @signal = ConditionVariable.new
  @server, @addr, @port = Jake.run_local_server(8081)
	@server.mount_proc('/', nil) do |req, res|
	  res.status = 200
    @mutex.synchronize do
      # puts " query_string: #{req.query_string}"
      # puts " Body: #{req.body}"
      @file_name =  req.query_string.split("=")[1]
      xml_file = File.expand_path(File.join(File.dirname(__FILE__), '..', '..', @file_name))
      File.open(xml_file, "w") { |f| f << req.body }
      puts "Test results are saved in #{@file_name}"
      # @signal.signal
    end
	end
	trap(:INT) { @server.shutdown }

  puts "Generating app ..."
  # Generate app, set rhoconnect gem path to its sources, but do not run bundler
	res = RhoconnectHelper.generate_app($tmp_path, test_appname, false)

  target_gemfile = File.join(server_path, 'Gemfile')
	puts "Patching Gemfile with aws-s3 ..."
	File.open(target_gemfile, 'a') {|f| f.puts "gem 'aws-s3', '>= 0.6.3'" }
	puts "Patching Gemfile with sqlite3 ..."
	File.open(target_gemfile, 'a') {|f| f.puts "gem 'sqlite3', '>= 1.3.3'" }
	puts "Bundle install ..."
	Kernel.system("bundle","install",:chdir => server_path)

	puts "Adding source files ..."
	FileUtils.cp_r ["#{source_path}/sources","#{source_path}/settings"], server_path

	puts "Cleanup rhoconnect data ..."
	FileUtils.rm_r(File.join(server_path,"data")) if File.directory?(File.join(server_path,"data"))

	RhoconnectHelper.start_rhoconnect_stack(server_path,true)

  generateRuby = flags && flags[:ruby]==true
  generateJS = flags && flags[:js]==true

  if generateRuby then
    File.open(File.join($app_path, 'app', 'sync_server.rb'), 'w') do |f|
  		f.puts "SYNC_SERVER_HOST = '#{RhoconnectHelper.host}'"
   		f.puts "SYNC_SERVER_PORT = #{RhoconnectHelper.port}"
    end
    File.open(File.join($app_path, 'app', 'local_server.rb'), 'w') do |f|
 			f.puts "SPEC_LOCAL_SERVER_HOST = '#{@addr}'"
 			f.puts "SPEC_LOCAL_SERVER_PORT = #{@port}"
    end
  end

  if generateJS then
    File.open(File.join($app_path, 'public', 'app', 'sync_server.js'), 'w') do |f|
      f.puts "var SYNC_SERVER_HOST = '#{RhoconnectHelper.host}';"
      f.puts "var SYNC_SERVER_PORT = #{RhoconnectHelper.port};"
    end
    File.open(File.join($app_path, 'public', 'app', 'local_server.js'), 'w') do |f|
			f.puts "var SPEC_LOCAL_SERVER_HOST = '#{@addr}';"
 			f.puts "var SPEC_LOCAL_SERVER_PORT = #{@port};"
    end
  end

	puts "Running specs ..."
	chdir $rho_root
	Rake::Task.tasks.each { |t| t.reenable }
	# run_specs = $device ? "run:#{platform}:#{$device}:spec" : "run:#{platform}:spec"
  uninstall_app = false
	Rake::Task["run:#{platform}:#{$device}:spec"].invoke(uninstall_app)

rescue SystemExit => e
  # FIXME: iphone rake task throws SystemExit exception. Swallow it!
  # puts "Got exception: #{e}"
rescue Exception => e
  puts e.message
  puts e.backtrace.join("\n")
ensure
  # @mutex.synchronize do
  #   @signal.wait(@mutex, 30) # wait timeout
  #   puts "Processed #{@file_name}"
  # end
	RhoconnectHelper.stop_rhoconnect_stack
	cleanup_apps
  Rake::Task["stop:#{platform}:#{$device}"].invoke
  # TODO:
  # `killall iphonesim_43 2> /dev/null` if platform == 'iphone'
	puts "run_spec_app(#{platform},#{appname}) done"
end

def cleanup_apps
	puts "cleanup"
	FileUtils.rm_r File.expand_path($tmp_path) if File.directory?($tmp_path)
end
