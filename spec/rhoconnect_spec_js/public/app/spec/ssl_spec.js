
describe("Rhoconnect Client: SSL Settings", function() {
  var defaultSyncServer = Rho.RhoConnectClient.syncServer;

  beforeEach(function(){
    Rho.RhoConnectClient.syncServer = defaultSyncServer;
    Rho.ORM.clear();
    var db = new Rho.Database.SQLite3(Rho.Application.databaseFilePath('user'), 'user');
    db.execute("DELETE FROM SOURCES");
    db.execute("DELETE FROM CLIENT_INFO");
    db.execute("DELETE FROM OBJECT_VALUES");
  });

  it(" | should not connect to self-signed SSL with enabled peer check | network error", function(){
    Rho.RhoConnectClient.syncServer = 'https://nagios.rhomobile.com';
    Rho.RhoConnectClient.sslVerifyPeer = true;
    var errorCode = null;
    var callbackCalled = false;

    runs(function(){
      Rho.RhoConnectClient.login('test','test', function(result){
        errorCode = parseInt(result.error_code);
        callbackCalled = true;
      });
    });

    waitsFor(function(){
      return callbackCalled;
    },"Waiting for callback.", 5000);

    runs(function(){
      expect(errorCode).toEqual(1);
    });

  });

  it(" | should connect to self-signed SSL with disabled peer check | fail to authorize", function(){
    Rho.RhoConnectClient.syncServer = 'https://nagios.rhomobile.com';
    Rho.RhoConnectClient.sslVerifyPeer = false;
    var errorCode = null;
    var callbackCalled = false;

    runs(function(){
      Rho.RhoConnectClient.login('test','test', function(result){
        errorCode = parseInt(result.error_code);
        callbackCalled = true;
      });
    });

    waitsFor(function(){
      return callbackCalled;
    },"Waiting for callback.", 10000);

    runs(function(){
      expect(errorCode).toEqual(9);
    });

  });

  xit(" | should connect to trusted SSL server | login successfully", function(){

  });

});