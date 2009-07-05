#include "StdAfx.h"
#include "GuidUtil.h"
#include "ExceptionMacros.h"
#include "StringUtil.h"
#include "ErrorUtil.h"

std::string DVLib::GenerateGUIDStringA()
{
	GUID pguid;	
	CHECK_HR(CoCreateGuid(& pguid), _T("::CoCreateGuid"));
	return StringFromGUID2A(pguid);
}

std::wstring DVLib::GenerateGUIDStringW()
{
	GUID pguid;	
	CHECK_HR(CoCreateGuid(& pguid), _T("::CoCreateGuid"));
	return StringFromGUID2W(pguid);
}

std::wstring DVLib::StringFromGUID2W(REFGUID rguid)
{
    std::wstring progid;
	progid.resize(39);
	int len = 0;

	CHECK_WIN32_BOOL(0 != (len = ::StringFromGUID2(rguid, static_cast<LPOLESTR>(
		& * progid.begin()), progid.size())),  _T("::StringFromCLSID"));

	progid.resize(len - 1);
    return progid;
}

std::string DVLib::StringFromGUID2A(REFGUID rguid)
{
    return wstring2string(StringFromGUID2W(rguid));
}
