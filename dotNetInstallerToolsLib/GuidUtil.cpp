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
		& * progid.begin()), progid.size())),  _T("::StringFromCLSID"));

	progid.resize(len - 1);
    return progid;
}

IID DVLib::string2guid(const std::wstring& guid)
{
	IID iid = { 0 };

	CHECK_HR(::IIDFromString(const_cast<LPOLESTR>(guid.c_str()), & iid),
        _T("Error in ::IIDFromString"));

    return iid;
}

IID DVLib::string2guid(const std::string& guid)
{
	return string2guid(DVLib::string2wstring(guid));
}

std::string DVLib::guid2string(REFGUID rguid)
{
    return wstring2string(guid2wstring(rguid));
}
