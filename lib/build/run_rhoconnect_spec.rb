require 'fileutils'

require File.join($rho_root,'lib','build','jake.rb')

	def reset_rhoconnect_server(host,port)
		require 'rest_client'
		require 'json'

		begin
			platform = platform
			exact_url = "http://#{host}:#{port}"
			puts "going to reset server: #{exact_url}"
			# login to the server
			unless @bulk_srv_token
				@bulk_srv_token = RestClient.post("#{exact_url}/rc/v1/system/login", { :login => "rhoadmin", :password => "" }.to_json, :content_type => :json)
			end
			RestClient.post("#{exact_url}/rc/v1/system/reset", {:api_token => @bulk_srv_token}.to_json, :content_type => :json)
			puts "reset OK"
			rescue Exception => e
			puts "reset_spec_server failed: #{e}"
		end
	end

	require 'socket'

        def execute_rhoconnect(out,*args)
		cmd = ""

		if RUBY_PLATFORM =~ /(win|w)32$/
			cmd = "ruby #{$rhoconnect_bin}"
		else
			cmd = "#{$rhoconnect_bin}"
		end

		args.each do |arg|
			cmd = "#{cmd} #{arg}"
		end

		puts cmd
		Kernel.system(cmd,:chdir => $tmp_path, :out => out)
        end

	def run_rhoconnect_spec(platform)
		appname = "rhoconnect_spec"
		test_appname = "testapp"

		puts "run_spec_app(#{platform},#{appname})"

		host = Jake.localip
		port = 9292
		server_pid = nil
		resque_pid = nil

		rhobuildyml = File.join($rho_root,'rhobuild.yml')
		$app_path = File.expand_path(File.join(File.dirname(__FILE__),'..','..','spec',appname))
		puts "app path: #{$app_path}"

		$app_config = Jake.config(File.open(File.join($app_path, "build.yml")))
		config = Jake.config(File.open(rhobuildyml,'r'))

		source_path = File.expand_path(File.join($app_path,'server'))
		$tmp_path = File.join(File.dirname(__FILE__),'..','..','tmp')
		FileUtils.mkdir_p File.expand_path($tmp_path)
		server_path = File.expand_path(File.join($tmp_path,'testapp'))

                $rhoconnect_bin = "#{$rhoconnect_root}/bin/rhoconnect"
		puts "$rhoconnect_bin: #{$rhoconnect_bin}"

		rc_out = File.open( File.join($app_path, "rhoconnect.log" ), "w")
		redis_out = File.open( File.join($app_path, "redis.log" ), "w")
		resque_out = File.open( File.join($app_path, "resque.log" ), "w")
		
		puts "generate app"
		res = execute_rhoconnect(rc_out,"app",test_appname)

		puts "patching Gemfile with correct rhoconnect path"
		target_gemfile = File.join(server_path, 'Gemfile')
		file = File.read(target_gemfile)
		file.gsub!(/(gem 'rhoconnect'*.*)/, "gem 'rhoconnect', :path => '#{$rhoconnect_root}'")
		File.open(target_gemfile, 'w') {|f| f.write file}

		puts "patching Gemfile with aws-s3"
		Kernel.system("echo \"gem 'aws-s3', '>= 0.6.3'\" >> Gemfile", :chdir => server_path, :out => rc_out)

		puts "patching Gemfile with sqlite3"
		Kernel.system("echo \"gem 'sqlite3', '>= 1.3.3'\" >> Gemfile", :chdir => server_path, :out => rc_out)

		puts "bundle install"
		Kernel.system("bundle","install",:chdir => server_path)

		puts "adding source files"
		FileUtils.cp_r ["#{source_path}/sources","#{source_path}/settings"], server_path

		puts "stop resque"
		Process.kill('INT', resque_pid) if resque_pid
		sleep(10)

		puts "stop rhoconnect"
		execute_rhoconnect(rc_out,"stop")
		sleep(10)

		puts "stop redis"
		execute_rhoconnect(redis_out,"redis-stop")
		sleep(10)


		puts "cleanup rhoconnect data"
		FileUtils.rm_r(File.join(server_path,"data")) if File.directory?(File.join(server_path,"data"))

		puts "run redis"
		execute_rhoconnect(redis_out,"redis-startbg")

		sleep(10)
		puts "run rhoconnect"
		server_pid = execute_rhoconnect(rc_out,"startbg")

		sleep(10)

		puts "reset rhoconnect"
		reset_rhoconnect_server(host,port)
		sleep(10)

		puts "run resque"
		resque_pid = Kernel.spawn({ "QUEUE" => "*" }, "rake","resque:work",:chdir => server_path, :out => resque_out )
		sleep(10)

		puts "set server parameters, resque_pid = #{resque_pid}, pid = #{server_pid}. setting address = #{host.inspect}, port = #{port}"

		File.open(File.join($app_path, 'app', 'sync_server.rb'), 'w') do |f|
			f.puts "SYNC_SERVER_HOST = '#{host}'"
			f.puts "SYNC_SERVER_PORT = #{port}"
		end

		puts "run specs"
		chdir $rho_root
		Rake::Task.tasks.each { |t| t.reenable }
		Rake::Task['run:' + platform + ':spec'].invoke

	ensure
		puts "stop resque"
		Process.kill('INT', resque_pid) if resque_pid
		sleep(5)

		puts "stop rhoconnect"
		execute_rhoconnect(rc_out,"stop")
		sleep(5)

		puts "stop redis"
		execute_rhoconnect(redis_out,"redis-stop")
		sleep(5)

		puts "cleanup"
		FileUtils.rm_r File.expand_path($tmp_path)

		puts "run_spec_app(#{platform},#{appname}) done"
	end
