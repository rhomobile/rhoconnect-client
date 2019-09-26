require 'fileutils'
include FileUtils

#Hack for linux (we should have a writable dirs in the gem subdirs)
chmod_R 0777, File.dirname(__FILE__) + "/.."

#This is the hack, we make all the things to make it look like an extension has compiled

File.open('Makefile', 'w') { |f| f.write "all:\n\ninstall:\n\n" }
File.open('make', 'w') do |f|
  f.write '#!/bin/sh'
  f.chmod f.stat.mode | 0111
end
File.open('rhodes_postinstallhack' + '.so', 'w') { |f| f.chmod 0777}
File.open('rhodes_postinstallhack' + '.dll', 'w') { |f| f.chmod 0777}
File.open('nmake.bat', 'w') { |f| f.write "ECHO \"Done\""
	f.chmod 0777}
