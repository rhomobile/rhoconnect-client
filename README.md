rhoconnect-client
=================

This repo contains code for any rhoconnect clients

##Building gem

By default, Rhodes folder is located in your installed gems. If you want to override this, specify Rhodes location in config.yml.

Build gem using "rake gem:make_gem".

##Running specs

Use "rake run:android:rhoconnect_spec", "rake run:iphone:rhoconnect_spec" or "rake run:win32:rhoconnect_spec" to run specs on respective platform.

##Creating Rhodes application that uses Rhoconnect client

By default "rhoconnect-client" extension in included in newly generated Rhodes application. You can also specify it in "extensions" section of build.yml file for your application.