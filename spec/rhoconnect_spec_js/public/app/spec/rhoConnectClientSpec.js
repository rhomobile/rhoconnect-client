function log(message) {
    var LOGCAT = "SPEC_RCClient";
    Rho.Log.info(message, LOGCAT);
}

describe("<RhoConnectClient specs>", function(){
         
    it("Sets sync server", function() {         
         var SYNC_SERVER_URL = "http://"+SYNC_SERVER_HOST+":"+SYNC_SERVER_PORT;
       
         Rho.RhoConnectClient.syncServer=SYNC_SERVER_URL;         
         expect(Rho.RhoConnectClient.syncServer).toEqual(SYNC_SERVER_URL);
    });

    it("Logins in non-threaded mode", function() {
       Rho.RhoConnectClient.threadedMode=false;
       
       var res = Rho.RhoConnectClient.login('test','test','');
       
       expect(res.error_code).toEqual('0');

       expect(Rho.RhoConnectClient.isLoggedIn()).toEqual(true);
 
       Rho.RhoConnectClient.logout();

       Rho.RhoConnectClient.threadedMode=true;
    });
         
    it("Logins", function() {       
       expect(Rho.RhoConnectClient.isLoggedIn()).toEqual(false);
       
       var callbackCalled = false;
       
       var cnt = 0;
       
       var callbackFunction = function ( args ) {
            expect(args.error_code).toEqual('0');
            callbackCalled = true;
       };
       
       runs(function () {
            Rho.RhoConnectClient.login('test','test',callbackFunction);
       });
       
       waitsFor(
          function () {
                return callbackCalled;
          },
          "Timeout",
          5000
        );
       
       runs(function() {
            expect(Rho.RhoConnectClient.isLoggedIn()).toEqual(true);
        });
    });
         
    it("Syncs", function() {
       var callbackCalled = false;

       var callbackFunction = function ( args ) {
            expect(args.status).toEqual('complete');       
            callbackCalled = true;
       };

       Rho.RhoConnectClient.setNotification('*',callbackFunction);
       Rho.RhoConnectClient.doSync();
       
       waitsFor(
            function () {
                return callbackCalled;
            },
            "Timeout",
            10000
        );
       
       runs(function() {
            Rho.RhoConnectClient.clearNotification('*');
        });
    });
         
    it("Sets notification", function() {
    });

    it("Sets object notification", function() {
    });
         
    
         
         
    it("Logouts", function() {
       Rho.RhoConnectClient.logout();
    });

});