
# -*- encoding: utf-8 -*-

Gem::Specification.new do |s|
	s.name = 'rhoconnect-client'
	s.version = File.read('version').chomp

	s.required_rubygems_version = Gem::Requirement.new(">= 0") if s.respond_to? :required_rubygems_version=
	s.authors = ["Rhomobile Dev Team"]
	s.date = Time.now
	s.description = %q{RhoConnect client extension}
	s.email = %q{rhomobile@googlegroups.com}
	s.extra_rdoc_files = ["README.md", "LICENSE"]
	files = Array.new
	IO.read("./tmp/Manifest.txt").each_line {|x| files << x.chomp}
	s.files =  files
	s.homepage = %q{http://www.rhomobile.com}
	s.rdoc_options = ["--inline-source", "--charset=UTF-8"]
	s.require_paths = ["lib"]
	s.rubyforge_project = %q{rhoconnect-client}
	s.extensions << './ext/extconf-chmod.rb'
	s.summary = %q{RhoConnect client in the form of a Rhodes/RhoElements native extension.}
end

