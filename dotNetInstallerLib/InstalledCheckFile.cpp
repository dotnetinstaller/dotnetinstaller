#include "StdAfx.h"
#include "XmlAttribute.h"
#include "InstalledCheckFile.h"
#include "InstallerLog.h"
#include "InstallConfiguration.h"
#include "InstallerSession.h"
#include "Wow64NativeFS.h"

InstalledCheckFile::InstalledCheckFile()
    : disableWow64FsRedirection(false)
{
}

void InstalledCheckFile::Load(tinyxml2::XMLElement * node)
{
    filename = node->Attribute("filename");
    fileversion = node->Attribute("fileversion");
    comparison = DVLib::UTF8string2wstring(node->Attribute("comparison"));
    defaultvalue = node->Attribute("defaultvalue");
    disableWow64FsRedirection = XmlAttribute(node->Attribute("disable_wow64_fs_redirection")).GetBoolValue(false);
    LOG(L"Loaded 'file' installed check '" << filename << L"'");
}

bool InstalledCheckFile::IsInstalled() const
{
    LOG(L"Checking file: " << filename);

    if (disableWow64FsRedirection)
    {
        auto_any<Wow64NativeFS *, close_delete> wow64_native_fs(new Wow64NativeFS());
        return IsInstalledInternal();
    }
    else
    {
        return IsInstalledInternal();
    }
}

bool InstalledCheckFile::IsInstalledInternal() const
{
    if (comparison == TEXT("exists"))
    {
        return DVLib::FileExists(filename);
    }

    bool default_result = defaultvalue.GetBoolValue(false);

    if (DVLib::FileExists(filename))
    {
        if (!fileversion.empty())
        {
            std::wstring fileversion_current = DVLib::GetFileVersion(filename);
            LOG(L"File version: " << filename << L" - " << fileversion_current);
            if (comparison == TEXT("match"))
                return (fileversion == fileversion_current);
            else if (comparison == TEXT("version"))
                return (DVLib::CompareVersion(fileversion_current, fileversion) >= 0);
            else if (comparison == TEXT("version_eq"))
                return (DVLib::CompareVersion(fileversion_current, fileversion) == 0);
            else if (comparison == TEXT("version_gt"))
                return (DVLib::CompareVersion(fileversion_current, fileversion) > 0);
            else if (comparison == TEXT("version_ge"))
                return (DVLib::CompareVersion(fileversion_current, fileversion) >= 0);
            else if (comparison == TEXT("version_lt"))
                return (DVLib::CompareVersion(fileversion_current, fileversion) < 0);
            else if (comparison == TEXT("version_le"))
                return (DVLib::CompareVersion(fileversion_current, fileversion) <= 0);
            else
            {
                THROW_EX(L"Invalid comparison type \"" << comparison << L"\"");
            }
        }
        else
        {
            LOG(L"*** File version not found: " << filename << L", default value: " << (default_result ? L"true" : L"false"));
        }
    }
    else
    {
        LOG(L"*** File not found: " << filename << L", default value: " << (default_result ? L"true" : L"false"));
    }

    return default_result;
}