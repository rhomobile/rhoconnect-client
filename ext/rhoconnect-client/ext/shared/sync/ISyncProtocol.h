/*------------------------------------------------------------------------
* (The MIT License)
* 
* Copyright (c) 2008-2011 Rhomobile, Inc.
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
* 
* http://rhomobile.com

* Copyright (c) 2011-2016 Symbol Technologies, Inc.
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
* 
* http://symbol.com
*------------------------------------------------------------------------*/

#pragma once

#include "common/RhoStd.h"

namespace rho {
namespace sync {

struct ISyncProtocol
{
	virtual ~ISyncProtocol() {}
	
    virtual const String& getClientIDHeader() const = 0;
    virtual const String& getContentType() const = 0;
    virtual int getVersion() const = 0;

    virtual String getLoginUrl() = 0;
    virtual String getLoginBody( const String& name, const String& password)=0;
    
    virtual const char* getClientCreateMethod() = 0;
    virtual String getClientCreateUrl() = 0;

    virtual String getClientRegisterUrl(const String& strClientID) = 0;
	virtual String getClientRegisterBody(const String& strClientID, const String& strPin, int nPort, const String& strType, const String& strPhoneID, const String& strDevicePushType = "", const String& strAppId = "", const String& strAppVersion = "") = 0;
	virtual String getClientAnsRegisterBody(const String& strClientID, const String& strPin, int nPort, const String& strType, const String& strPhoneID ) = 0;

    virtual const char* getClientResetMethod() = 0;
	virtual String getClientResetUrl(const String& strClientID) = 0;
    virtual String getClientResetBody() = 0;

    virtual String getClientChangesUrl(const String& srcName) = 0;
    virtual String getServerQueryUrl(const String& strSrcName, const String& strClientID, int nPageSize )=0;

    virtual const char* getServerSearchMethod() = 0;
    virtual String getServerSearchUrl(const String& strClientID, int nPageSize, const String& strFrom, const Vector<String>& sources, const Hashtable<String, String>& source_tokens) = 0;
    virtual String getServerSearchBody(int nPageSize, const Vector<String>& sources, const Hashtable<String, String>& source_tokens )=0;

    virtual const char* getServerBulkDataMethod() = 0;
    virtual String getServerBulkDataUrl(const String& strClientID, const String& strPartition, const Vector<String>& sources) = 0;
    virtual String getServerBulkDataBody(const String& strPartition, const Vector<String>& sources) = 0;
};

}
}
