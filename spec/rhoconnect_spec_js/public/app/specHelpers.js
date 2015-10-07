var callbackFunction = function(args) {
  processArgs(args);
  if((args.status && args.status == 'complete') || !args.status) {
    callbackCalled = true;
  }; 
};

var okCallbackFunction = function(args) {
  processArgs(args);
  if((args.status && args.status == 'ok') || !args.status) {
    callbackCalled = true;
  };
};

var processArgs = function(args) {
  if(args.error_code) {
    loginCallback_paramsValue.error_code = args.error_code.toString();
  }
  if(args.error_message) {
    loginCallback_paramsValue.error_message = args.error_message.toString();
  }
};

var createProducts = function(count, data) {
  for(var i = 0; i < count; i++) {
    Product.create({brand: data + '-brand', name: data + '-name'});
  }
};

var createCustomers = function(count, data) {
  for(var i = 0; i < count; i++) {
    Customer.create({first: data + '-first', last: data + '-last'});
  }
};

var buildErrorMessage = function(data) {
  return [
    {"version": 3},
    {"token": ""},
    {"count": 0},
    {"progress_count": 0},
    {"total_count": 0},
    {"source-error": data}
  ]
}
var ormSpecHelper = {
find: function(){
    var args = Array.prototype.slice.call(arguments);
    if(args[0].fixed_schema){
      return args[0];
    }
    else{
      if (args[2] == undefined)
        args[2] = "";
      if (args[3] == undefined)
        args[3] = [];
      if (args[4] == undefined)
        args[4] = {};
      if (args[5] == undefined)
        args[5] = [];
      if(args[1]!="all" && args[1]!="first" && args[1]!="count")
        return args[0].findObjectsPropertyBagByCondArray(args[1],args[2],args[3],args[4],args[5])[0];
      return args[0].findObjectsPropertyBagByCondArray(args[1],args[2],args[3],args[4],args[5]);
    }
  }
};

