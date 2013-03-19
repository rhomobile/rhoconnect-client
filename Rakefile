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
require 'yaml'

puts 'RUBY VERSION: ' + RUBY_VERSION.to_s

if RUBY_VERSION.to_s > "1.9.0"
  require 'psych'
end


cfgfilename = File.join(File.dirname(__FILE__),'config.yml')

$rho_root = nil
$rhoconnect_use_redis = true

chdir File.dirname(__FILE__)

if File.file?(cfgfilename)
  config = YAML::load_file(cfgfilename)
  $rho_root = config["rhodes"]
  $rhoconnect_root = config["rhoconnect"]
  $rho_root = File.expand_path($rho_root) if $rho_root
  $rhoconnect_root = File.expand_path($rhoconnect_root) if $rhoconnect_root
end

unless $rho_root
  $rho_root = `get-rhodes-info --rhodes-path`.chomp
end

puts "$rho_root is #{$rho_root}"

require File.join($rho_root,'lib','build','jake.rb')

load File.join($rho_root,'Rakefile')

#$app_basedir = pwd
#$curr_project = "rhowebkit"

chdir File.dirname(__FILE__)

dirs = [
	 "./ext",
	 "./lib",
	 "./platform",
	 "./rhoconnect-client"
]

files = ["README.md",
         "CHANGELOG",
		 "CREDITS",
		 "LICENSE"
		]


namespace "gem" do

  task :clean => "gem:build:config" do
    puts "Clean gem build files"
    rm_rf Dir.glob("./tmp/Manifest*.txt")
    rm_rf Dir.glob("rhoconnect-client*.gem")
    rm_rf Dir.glob("tmp/bin")

    rm_rf File.join($neon_ext_wm_dir, "tmp/bin")

    startdir = File.dirname(__FILE__)
    buildstab = File.join(startdir, 'buildstab')
  end

	namespace "build" do
		task :config  do
			puts "Configure build"
		end
	end


  task :make_gem => "gem:build:config"  do
    puts "Removing old gem"
    rm_rf Dir.glob("rhoelements*.gem")
    puts "Copying Rakefile"

    out = ""
    puts "Building manifest"

    chdir File.dirname(__FILE__)

    dirs.uniq!
    dirs.each_with_index do |extdir, i|
      next unless File.exists?(extdir)
      Dir.chdir(extdir)

      Dir.glob("**/{*,.*}") do |fname|
        # TODO: create exclusion list
        if File.file? fname
            out << extdir + "/" + fname + "\n"

            if fname.end_with?("build")
                script = File.read(fname)
                res = script.gsub(/\r\n?/, '\n')
                File.open(fname, "wb"){ |f| f.write(res) }

            end
        end
      end

      Dir.chdir(File.dirname(__FILE__))
    end

    files.uniq!
    files.each do |f|
      out << f.to_s + "\n"
    end

    mkdir_p './tmp'
    File.open("./tmp/Manifest.txt", 'w') {|f| f.write(out)}

    puts "Loading gemspec"
    require 'rubygems'
    spec = Gem::Specification.load('rhoconnect-client.gemspec')

    puts "Building gem"
    gemfile = Gem::Builder.new(spec).build

  end
end

namespace "run" do
  namespace "android" do
    task :rhoconnect_spec => "rhoconnect_spec:emulator"


    namespace "rhoconnect_spec" do
      task :device do
	require File.dirname(__FILE__) + "/lib/build/run_rhoconnect_spec.rb"

        $device_flag = '-d'
        run_rhoconnect_spec('android')
        unless $dont_exit_on_failure
          exit 1 if $total.to_i==0
          exit $failed.to_i
        end
      end

      task :emulator do
	require File.dirname(__FILE__) + "/lib/build/run_rhoconnect_spec.rb"

        $device_flag = '-e'
        run_rhoconnect_spec('android')
        unless $dont_exit_on_failure
          exit 1 if $total.to_i==0
          exit $failed.to_i
        end
      end
    end

  end

  namespace "iphone" do
    task :rhoconnect_spec do
      run_rhoconnect_spec('iphone')
    end
  end

  namespace "wm" do
    task :rhoconnect_spec do
      run_rhoconnect_spec('wm')
      exit 1 if $total.to_i==0
      exit $failed.to_i
    end
  end

  namespace "win32" do
    task :rhoconnect_spec do
      run_rhoconnect_spec('win32')
      exit 1 if $total.to_i==0
      exit $failed.to_i
    end
  end
end
