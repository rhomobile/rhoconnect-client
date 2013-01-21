
if "%RHO_PLATFORM%" == "android" (

cd rhoconnect-client\platform\android
rake --trace

)

if "%RHO_PLATFORM%" == "iphone" (

cd rhoconnect-client\platform\phone
rake --trace

)

if "%RHO_PLATFORM%" == "bb" (

cd rhoconnect-client\platform\bb
rake --trace

)

