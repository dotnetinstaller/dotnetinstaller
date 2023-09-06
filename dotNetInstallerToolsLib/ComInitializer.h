#pragma once
#include "stdafx.h"
#include "StringUtil.h"
#include "ErrorUtil.h"
#include "ExceptionMacros.h"
#include <comdef.h>

class ComInitializer
{
public:
    ComInitializer()
    {
        // initialize COM
        CHECK_HR(::CoInitializeEx(0, COINIT_APARTMENTTHREADED),
            L"Failed to initialize COM library.");
    }

    ~ComInitializer()
    {
        ::CoUninitialize();
    }
};

