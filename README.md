rhoconnect-client
=================

This repo contains code for Rhodes 'rhoconnect-client' extension and any standalone Rhoconnect clients. For more info on Rhoconnect clients refer to:
  http://docs.rhomobile.com/rhodes/synchronization
  http://docs.rhomobile.com/rhoconnect/client

##Building gem

To use latest code from github repo you will need to build and install rhoconnect-client gem.

First you will need to set up paths to the Rhodes and Rhoconnect folders. To do this, copy 'config.yml.sample' to 'config.yml' and edit it with the path to your rhodes and rhoconnect workspaces.

To build gem run 'rake gem:make_gem' command from repo root. Gem file will be created in the same folder. Install it using 'gem install ./rhoconnect-client-<version>.gem'

##Creating Rhodes application that uses Rhoconnect client

Rhodes application needs to use 'rhoconnect-client' extension to utilize API for data synchronization. By default "rhoconnect-client" extension in included in newly generated Rhodes application. You can also specify it in "extensions" section of build.yml file for your application.

For documetation how to create Rhodes applications please refer to
  http://docs.rhomobile.com/rhodes/generator

API is documented here:
  http://docs.rhomobile.com/rhodes/synchronization
  
##Creating native applications that uses Rhoconnect client.

This repo contains rhoconnect-client library that can be used by your native application for iOS or Android. For documentation on how to use clients for native applications please refer to
  http://docs.rhomobile.com/rhoconnect/client

##Running specs

Copy `config.yml.sample` to `config.yml` and edit it with the path to your rhodes and rhoconnect workspaces.
Use the following tasks to run specs on respective platform:

Ruby:
* rake run:android:rhoconnect_spec
* rake run:iphone:rhoconnect_spec
* rake run:win32:rhoconnect_spec

JavaScript
* rake run:android:rhoconnect_spec_js
* rake run:iphone:rhoconnect_spec_js
* rake run:win32:rhoconnect_spec_js

Local Rhoconnect server will be launched and pack of tests will be performed.