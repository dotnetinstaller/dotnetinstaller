#include "StdAfx.h"
#include "GuidUtil.h"
#include "ExceptionMacros.h"
#include "StringUtil.h"
#include "ErrorUtil.h"

std::string DVLib::GenerateGUIDStringA()
{
    GUID pguid;	
    CHECK_HR(CoCreateGuid(& pguid), _T("::CoCreateGuid"));
    return guid2string(pguid);
}

std::wstring DVLib::GenerateGUIDStringW()
{
    GUID pguid;	
    CHECK_HR(CoCreateGuid(& pguid), _T("::CoCreateGuid"));
    return guid2wstring(pguid);
}

std::wstring DVLib::guid2wstring(REFGUID rguid)
{
    std::wstring progid;
    progid.resize(39);
    int len = 0;

    CHECK_WIN32_BOOL(0 != (len = ::StringFromGUID2(rguid, static_cast<LPOLESTR>(
        & * progid.begin()), progid.size())),  _T("::StringFromGUID2"));

    progid.resize(len - 1);
    return progid;
}

IID DVLib::string2guid(const std::wstring& guid)
{
    IID iid = { 0 };

    CHECK_HR(::IIDFromString(const_cast<LPOLESTR>(makeguid(guid).c_str()), & iid),
        L"Error in ::IIDFromString('" << guid << L"')");

    return iid;
}

bool DVLib::isguid(const std::wstring& guid)
{
    IID iid = { 0 };
    HRESULT hr;

    switch(hr = ::IIDFromString(const_cast<LPOLESTR>(makeguid(guid).c_str()), & iid))
    {
    case E_INVALIDARG:
    case CO_E_IIDSTRING:
        return false;
    case S_OK:
        return true;
    default:
        CHECK_HR(hr, L"Error in ::IIDFromString('" << guid << L"')");
    }

    return false;
}

bool DVLib::isguid(const std::string& guid)
{
    return isguid(DVLib::string2wstring(guid));
}

IID DVLib::string2guid(const std::string& guid)
{
    return string2guid(DVLib::string2wstring(guid));
}

std::string DVLib::guid2string(REFGUID rguid)
{
    return wstring2string(guid2wstring(rguid));
}

std::wstring DVLib::makeguid(const std::wstring& guid)
{
    std::wstring result;
    if (! guid.empty() && guid[0] != L'{')
        result += L"{";
    result += guid;
    if (! guid.empty() && guid[guid.length() - 1] != L'}') 
        result += L"}";
    return result;
}

std::string DVLib::makeguid(const std::string& guid)
{
    return wstring2string(makeguid(string2wstring(guid)));
}