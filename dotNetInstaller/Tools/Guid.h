#pragma once

namespace DVLib
{
    inline CString StringFromGUID2(REFGUID rguid)
	{
        WCHAR progid[39];
        int len = 0;

		if(0 == (len = ::StringFromGUID2(rguid, (LPOLESTR) & progid, sizeof(progid) - 1)))
            throw TEXT("StringFromGUID2 failed");

        progid[len - 1] = 0;
        return CString(progid);
	}

    inline CString GenerateGUIDString()
	{
		GUID pguid;
		
        if (FAILED(::CoCreateGuid(& pguid)))
            throw TEXT("CoCreateGuid failed");

        return StringFromGUID2(pguid);
	}
}