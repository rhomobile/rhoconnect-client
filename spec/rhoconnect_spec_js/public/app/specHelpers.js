function isAndroidPlatform() {
    return ["ANDROID"] == (Rho.System.platform);
}

function isApplePlatform() {
    return ["APPLE"] == (Rho.System.platform);
}

function isWindowsMobilePlatform() {
    return "WINDOWS" == Rho.System.platform;
}

function isWindowsDesktopPlatform() {
    return "WINDOWS_DESKTOP" == Rho.System.platform;
}

function isAnyWindowsFamilyPlatform() {
    return ["WINDOWS", "WINDOWS_DESKTOP", "WP8"].indexOf(Rho.System.platform) != -1;
}

function isWindowsMobileOrWindowsDesktopPlatform() {
    return ["WINDOWS", "WINDOWS_DESKTOP"].indexOf(Rho.System.platform) != -1;
}

function isAnyButWindowsFamilyPlatform() {
    return !isAnyWindowsFamilyPlatform();
}

function isAnyButAppleAndWindowsMobilePlatform() {
    return ["APPLE", "WINDOWS"].indexOf(Rho.System.platform) == -1;
}

function isWindowsMobileOrAndroidPlatform() {
    return ["WINDOWS", "ANDROID"].indexOf(Rho.System.platform) != -1;
}

function isAnyButApplePlatform() {
    return ["APPLE"] != (Rho.System.platform);
}

function isAndroidOrApplePlatform() {
    return ["ANDROID", "APPLE"].indexOf(Rho.System.platform) != -1;
}

//TNV Code For RhoConnect Client

var callbackFunction = function ( args ) {
            //expect(args.error_code).toEqual('0');
	        loginCallback_paramsValue.error_code = args.error_code.toString();
	        loginCallback_paramsValue.error_message = args.error_message.toString();
            callbackCalled = true;
       };
       
var modelrecordtest = function (){
	$.get('/app/Settings/recordtest').success(function(data){showResult(data)});
    //alert("after before recordtest"+record_count);
	//var products = Product.find('all'); for js model
	//products.length();
};


function showResult(data) {
	//alert(data);
    var abc = $.parseJSON(data);
    product_record_count = parseInt(abc["product_count"]);
    customer_record_count = parseInt(abc["customer_count"]);
    //alert(record_count);
}

var dbreset = function(){
	$.get('/app/Settings/do_dbreset');
};

var create_product_record = function(count,data){
	$.get('/app/Settings/create_product_record?loopcount='+count+'&data='+data);
};

var create_customer_record = function(count,data){
	$.get('/app/Settings/create_customer_record?loopcount='+count+'&data='+data);
};

var update_product_record = function(existing_data,updating_data){
	$.get('/app/Settings/update_product_record?existing_data='+existing_data+'&updating_data='+updating_data);
};

var update_customer_record = function(existing_data,updating_data){
	$.get('/app/Settings/update_customer_record?existing_data='+existing_data+'&updating_data='+updating_data);
};

var delete_product_record = function(deleting_data){
	$.get('/app/Settings/delete_product_record?deleting_data='+deleting_data);
};

var delete_customer_record = function(deleting_data){
	$.get('/app/Settings/delete_customer_record?deleting_data='+deleting_data);
};



var sync_notify_callback= function ( args ) {
callbackCalled = true; //for result whether callback is fired or not?	
var status = args.status ? args.status : "" ;
var source_id = args.source_id ? args.source_id : "" ;
var source_name = args.source_name ? args.source_name : "" ;
var sync_type = args.sync_type ? args.sync_type : "" ;
var total_count = args.total_count ? args.total_count : "" ;
var processed_count = args.processed_count ? args.processed_count : "" ;
var cumulative_count = args.cumulative_count ? args.cumulative_count : "" ;

if(status == "in_progress")
{
  myString = myString.toString()+"----------In Progress-------------<br/>";
  myString = myString.toString()+"source_id:"+source_id+"source_name:"+source_name+"sync_type:"+sync_type+"status:"+status+"<br/>";    
  myString = myString.toString()+"total_count:"+total_count+"processed_count:"+processed_count+"cumulative_count:"+cumulative_count+"<br/>"; 
  myString = myString.toString()+"----------In Progress-------------<br/>";  
}
else if(status == "ok")
{
       myString = myString.toString()+"----------OK-------------<br/>";
       myString = myString.toString()+"source_id:"+source_id+"source_name:"+source_name+"sync_type:"+sync_type+"status:"+status+"<br/>";    
       myString = myString.toString()+"total_count:"+total_count+"processed_count:"+processed_count+"cumulative_count:"+cumulative_count+"<br/>"; 
       myString = myString.toString()+"----------OK-------------<br/>" ;
}
else if(status == "complete")
{
 myString = myString.toString()+"source_id:"+source_id+"source_name:"+source_name+"sync_type:"+sync_type+"status:"+status+"<br/>"; 
 //WebView.navigate Rho::RhoConfig.start_path if @params['sync_type'] != 'bulk'
}
else if(status == "error")
{
  myString = myString.toString()+"----------server error:"+args.server_errors+"-------------<br/>" 
  myString = myString.toString()+"----------error code:"+args.error_code+"-------------<br/>" 
  myString = myString.toString()+"----------error message:"+args.error_message+"-------------<br/>" 
 }
};


function showControllerResults(returnval) 
{
	if(returnval=="yes")
	callbackCalled = true;
	else
	callbackCalled = false;
}

var search_callback = function(args){
	searchCallback_paramsValue.status=args.status;
	searchCallback_paramsValue.search_params=args.search_params;
	callbackCalled = true;
};




