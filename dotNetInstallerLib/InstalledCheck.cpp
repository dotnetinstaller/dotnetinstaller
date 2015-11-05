#include "StdAfx.h"
#include "InstalledCheck.h"
#include "InstalledCheckRegistry.h"
#include "InstalledCheckFile.h"
#include "InstalledCheckDirectory.h"
#include "InstalledCheckProduct.h"

InstalledCheck::InstalledCheck()
{

}

InstalledCheck::~InstalledCheck()
{

}

InstalledCheckPtr InstalledCheck::Create(const std::wstring& installedcheck_type)
{
    if (installedcheck_type == L"check_registry_value")
    {
        return InstalledCheckPtr(new InstalledCheckRegistry());
    }
    else if (installedcheck_type == L"check_file")
    {
        return InstalledCheckPtr(new InstalledCheckFile());
    }
    else if (installedcheck_type == L"check_directory")
    {
        return InstalledCheckPtr(new InstalledCheckDirectory());
    }
    else if (installedcheck_type == L"check_product")
    {
        return InstalledCheckPtr(new InstalledCheckProduct());
    }
    else
    {
        THROW_EX(L"Invalid installed check type '" << installedcheck_type << L"'");
    }
}
