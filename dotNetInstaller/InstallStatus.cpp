#include "StdAfx.h"
#include "InstallStatus.h"

InstallStatusPtr InstallStatus::CreateStatus(const std::wstring& status)
{
    InstallStatusPtr param(new InstallStatus());
    param->status = status;
    return param;
}
