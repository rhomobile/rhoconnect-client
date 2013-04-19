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
#include "common/StringConverter.h"
#include "common/RhoFilePath.h"
#include "json/JSONIterator.h"
#include "common/Tokenizer.h"

#include <iostream>

namespace rho {
namespace sync {

struct CSyncProtocol_4 : public ISyncProtocol
{
    String m_strContentType;
    String m_strClientIDHeader;
    String m_strAppNamespace;
    String m_strClientNamespace;
    String m_strSANamespace;

    CSyncProtocol_4()
    {
        m_strContentType = "application/json";
        m_strAppNamespace = "rc/v1/app/";
        m_strClientNamespace = "rc/v1/clients/";
        m_strSANamespace = "app/v1/";
        m_strClientIDHeader = "X-RhoConnect-CLIENT-ID";
    }

    const String& getAppNamespaceUrl()
    {
        return m_strAppNamespace;
    }

    const String& getClientNamespaceUrl()
    {
        return m_strClientNamespace;
    }

    const String& getSANamespaceUrl()
    {
        return m_strSANamespace;
    }

    const String& getClientIDHeader() const { return m_strClientIDHeader; }
    const String& getContentType() const { return m_strContentType; }
    virtual int getVersion() const { return 3; }

    String getLoginUrl()
    {
        return RHOCONF().getPath("syncserver") + getAppNamespaceUrl() + "login";
    }

    String getLoginBody( const String& name, const String& password)
    {
        return "{\"login\":" + json::CJSONEntry::quoteValue(name) + ",\"password\":" + json::CJSONEntry::quoteValue(password) + ",\"remember_me\":1}";
    }

    const char* getClientCreateMethod()
    {
        return "POST";
    }

    String getClientCreateUrl()
    {
        String strUrl = RHOCONF().getPath("syncserver") + getClientNamespaceUrl();
        return strUrl.substr(0, strUrl.length() - 1);
    }

    String getClientRegisterUrl(const String& strClientID)
    {
        return RHOCONF().getPath("syncserver") + getClientNamespaceUrl() + strClientID + "/register";
    }

    String getClientRegisterBody( const String& /*strClientID*/, const String& strPin, int nPort, const String& strType, const String& strPhoneID, const String& strDevicePushType)
    {
        return "{\"device_pin\":" + json::CJSONEntry::quoteValue(strPin) +
            ( strPhoneID.length() > 0 ? ",\"phone_id\":" + json::CJSONEntry::quoteValue(strPhoneID) : "") +
            ",\"device_port\":" + json::CJSONEntry::quoteValue(common::convertToStringA(nPort)) +
            ",\"device_type\":" + json::CJSONEntry::quoteValue(strType) +
            ((strDevicePushType.length() > 0) ? (",\"device_push_type\":" + json::CJSONEntry::quoteValue(strDevicePushType)) : String("")) +
            "}";
    }

	String getClientAnsRegisterBody( const String& /*strClientID*/, const String& strPin, int nPort, const String& strType, const String& strPhoneID )
    {
        return "{\"device_pin\":" + json::CJSONEntry::quoteValue(strPin) +
            ( strPhoneID.length() > 0 ? ",\"phone_id\":" + json::CJSONEntry::quoteValue(strPhoneID) : "") +
            ",\"device_port\":" + json::CJSONEntry::quoteValue(common::convertToStringA(nPort)) +
            ",\"device_type\":" + json::CJSONEntry::quoteValue(strType) + 
			",\"device_push_type\":\"rhoconnect_push\"}";
    }

    const char* getClientResetMethod()
    {
        return "POST";
    }

    String getClientResetUrl(const String& strClientID)
    {
        return RHOCONF().getPath("syncserver") + getClientNamespaceUrl() + strClientID + "/reset";
    }

    String getClientResetBody()
    {
        String strBody;
        String strSources = RHOCONF().getString("reset_models");
        rho::common::CTokenizer tokenizer(strSources, ",");
        String strJSONSources;
        while(tokenizer.hasMoreTokens()) {
            String source_name = tokenizer.nextToken();
            if(source_name.length() > 0) {
                strJSONSources += "{\"name\":";
                strJSONSources += json::CJSONEntry::quoteValue(source_name);
                strJSONSources += "}";
            }
        } 
        if(strJSONSources.size()) {
            strBody += "{\"sources\":[";
            strBody += strJSONSources;
            strBody += "]}";
        }
        return strBody;
    }

    String getClientChangesUrl(const String& strSrcName)
    {
        return RHOCONF().getPath("syncserver") + getSANamespaceUrl() + strSrcName;
    }

    String getServerQueryUrl(const String& strSrcName, const String& strClientID, int nPageSize)
    {
        String strUrl = RHOCONF().getPath("syncserver") + getSANamespaceUrl() + strSrcName;
        strUrl += "?p_size=" + common::convertToStringA(nPageSize) + "&version=" + common::convertToStringA(getVersion());
        return strUrl;
    }

    const char* getServerSearchMethod()
    {
        return "POST";
    }

    String getServerSearchUrl(const String& strClientID, int nPageSize, const String& strFrom, const Vector<String>& sources, const Hashtable<String, String>& source_tokens)
    {
        return RHOCONF().getPath("syncserver") + getAppNamespaceUrl() + strFrom +
            "?p_size=" + common::convertToStringA(nPageSize) + "&version=" + common::convertToStringA(getVersion());
    }

    String getServerSearchBody(int nPageSize, const Vector<String>& sources, const Hashtable<String, String>& source_tokens )
    {
        String strJSONSources;
        for (int i = 0; i < (int)sources.size(); ++i )
        {
            strJSONSources += "{\"name\":";
            strJSONSources += json::CJSONEntry::quoteValue(sources[i]);
            String strToken = source_tokens.get(sources[i]);
            if(strToken.length() > 0) {
                strJSONSources += ",\"token\":";
                strJSONSources += json::CJSONEntry::quoteValue(strToken);
            }
            strJSONSources += "}";
        }
        
        String strBody;
        if(strJSONSources.length() > 0) {
            strBody += "\"sources\":[";
            strBody += strJSONSources;
            strBody += "]";
        }

        if(strBody.size() > 0)
            strBody = String("{") + strBody + "}";

        return strBody;
    }

    const char* getServerBulkDataMethod() 
    {
        return "POST";
    }

    String getServerBulkDataUrl(const String& strClientID, const String& strPartition, const Vector<String>& sources)
    {
        return RHOCONF().getPath("syncserver") + getAppNamespaceUrl() + "bulk_data";
    }

    String getServerBulkDataBody(const String& strPartition, const Vector<String>& sources)
    {
        String strBody = "{\"partition\":";
        strBody += json::CJSONEntry::quoteValue(strPartition);
        strBody += ",\"sources\":";
        strBody += json::CJSONEntry::toJSON(sources);
        strBody += "}";
    
        return strBody;
    }
};

}
}
