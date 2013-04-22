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
*------------------------------------------------------------------------*/

#pragma once

#include "ISyncProtocol.h"
#include "net/URI.h"
#include "common/StringConverter.h"
#include "common/Tokenizer.h"
#include "common/RhoFilePath.h"
#include "json/JSONIterator.h"

namespace rho {
namespace sync {

struct CSyncProtocol_3 : public ISyncProtocol
{
    String m_strContentType;
    String m_strClientIDHeader;

    CSyncProtocol_3()
    {
        m_strContentType = "application/json";
        m_strClientIDHeader = "";
    }

    const String& getClientIDHeader() const { return m_strClientIDHeader; }
    const String& getContentType() const { return m_strContentType; }
    virtual int getVersion() const { return 3; }

    String getLoginUrl()
    {
        return RHOCONF().getPath("syncserver") + "clientlogin";
    }

    String getLoginBody( const String& name, const String& password)
    {
        return "{\"login\":" + json::CJSONEntry::quoteValue(name) + ",\"password\":" + json::CJSONEntry::quoteValue(password) + ",\"remember_me\":1}";
    }

    const char* getClientCreateMethod()
    {
        return "GET";
    }

    String getClientCreateUrl()
    {
        return RHOCONF().getPath("syncserver") + "clientcreate";
    }

    String getClientRegisterUrl(const String& /*strClientID*/)
    {
        return RHOCONF().getPath("syncserver") + "clientregister";
    }

    String getClientRegisterBody( const String& strClientID, const String& strPin, int nPort, const String& strType, const String& strPhoneID, const String& strDevicePushType)
    {
        return "{\"client_id\":" + json::CJSONEntry::quoteValue(strClientID) + 
            ",\"device_pin\":" + json::CJSONEntry::quoteValue(strPin) +
            ( strPhoneID.length() > 0 ? ",\"phone_id\":" + json::CJSONEntry::quoteValue(strPhoneID) : "") +
            ",\"device_port\":" + json::CJSONEntry::quoteValue(common::convertToStringA(nPort)) +
            ",\"device_type\":" + json::CJSONEntry::quoteValue(strType) +
            ((strDevicePushType.length() > 0) ? (",\"device_push_type\":" + json::CJSONEntry::quoteValue(strDevicePushType)) : String("")) +
            "}";
    }

	String getClientAnsRegisterBody( const String& strClientID, const String& strPin, int nPort, const String& strType, const String& strPhoneID )
    {
        return "{\"client_id\":" + json::CJSONEntry::quoteValue(strClientID) + 
            ",\"device_pin\":" + json::CJSONEntry::quoteValue(strPin) +
            ( strPhoneID.length() > 0 ? ",\"phone_id\":" + json::CJSONEntry::quoteValue(strPhoneID) : "") +
            ",\"device_port\":" + json::CJSONEntry::quoteValue(common::convertToStringA(nPort)) +
            ",\"device_type\":" + json::CJSONEntry::quoteValue(strType) + 
			",\"device_push_type\":\"rhoconnect_push\"}";
    }

    const char* getClientResetMethod()
    {
        return "GET";
    }

    String getClientResetUrl(const String& strClientID)
    {
        String strUrl = RHOCONF().getPath("syncserver") + "clientreset?client_id=" + strClientID;
        String strSources = RHOCONF().getString("reset_models");
        rho::common::CTokenizer tokenizer(strSources, ",");
        while(tokenizer.hasMoreTokens()) {
            String source_name = tokenizer.nextToken();
            if(source_name.length() > 0) {
                strUrl += "&sources[][name]=";
                strUrl += source_name;
            }
        } 
        return strUrl;
    }

    String getClientResetBody() 
    {
        return "";
    }

    String getClientChangesUrl(const String& /*strSrcName*/)
    {
        String strUrl = RHOCONF().getPath("syncserver");
        return strUrl.substr(0,strUrl.length()-1);
    }

    String getServerQueryUrl(const String& strSrcName, const String& strClientID, int nPageSize)
    {
        String strServerUrl = RHOCONF().getPath("syncserver");
        String strUrl = strServerUrl.substr(0,strServerUrl.length()-1);

        strUrl += "?client_id=" + strClientID 
            + "&p_size=" + common::convertToStringA(nPageSize) + "&version=" + common::convertToStringA(getVersion());
        
        if ( strSrcName.length() > 0 )
            strUrl += "&source_name=" + strSrcName;

        return strUrl;
    }

    const char* getServerSearchMethod() 
    {
        return "GET";
    }

    String getServerSearchUrl(const String& strClientID, int nPageSize, const String& strFrom, const Vector<String>& sources, const Hashtable<String, String>& source_tokens)
    {
        String strUrl = RHOCONF().getPath("syncserver") + strFrom + "?client_id=" + strClientID + "&p_size="
             + common::convertToStringA(nPageSize) + "&version=" + common::convertToStringA(getVersion());

        String strSources;
        for ( int i = 0; i < (int)sources.size(); ++i ) 
        {
            strSources += "&sources[][name]=" + sources[i];
            String strToken = source_tokens.get(sources[i]);
            if(strToken.size() > 0) {
                strSources += "&sources[][token]=" + strToken; 
            }
        }

        return strUrl + strSources;
    }

    String getServerSearchBody(int nPageSize, const Vector<String>& sources, const Hashtable<String, String>& source_tokens)
    {
        return "";
    }

    const char* getServerBulkDataMethod()
    {
        return "GET";
    }

    String getServerBulkDataUrl(const String& strClientID, const String& strPartition, const Vector<String>& sources)
    {
        String strUrl = RHOCONF().getPath("syncserver") + "bulk_data";
        String strParams = "?client_id=" + strClientID + "&partition=" + strPartition + "&sources=";  
        for ( int i = 0; i < (int)sources.size(); ++i ) {
            strParams += net::URI::urlEncode(sources[i]);
            if ( i < (int)sources.size()-1 ) {
                strParams += ",";
            }
        }
        return strUrl + strParams;
    }

    String getServerBulkDataBody(const String& strPartition, const Vector<String>& sources)
    {
        return "";
    }
};

}
}
