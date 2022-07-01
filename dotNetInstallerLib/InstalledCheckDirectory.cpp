#include "StdAfx.h"
#include "XmlAttribute.h"
#include "InstalledCheckDirectory.h"
#include "InstallerLog.h"
#include "InstallConfiguration.h"
#include "InstallerSession.h"

InstalledCheckDirectory::InstalledCheckDirectory()
{
}

void InstalledCheckDirectory::Load(tinyxml2::XMLElement * node)
{
    path = InstallerSession::Instance->ExpandVariables(DVLib::UTF8string2wstring(node->Attribute("path")));
    comparison = DVLib::UTF8string2wstring(node->Attribute("comparison"));
    version = node->Attribute("version");
    LOG(L"Loaded 'directory' installed check '" << path << L"'");
}

bool InstalledCheckDirectory::IsInstalled() const
{
    if (comparison == TEXT("exists"))
    {
        return DVLib::DirectoryExists(path);
    }

    // version comparison on sub directories
    if (!DVLib::DirectoryExists(path))
    {
        LOG(L"*** Directory not found: " << path);
        return false;
    }

    // enumerate sub directories
    std::list<std::wstring> directoryNames = DVLib::GetDirectories(path);
    if (directoryNames.size() <= 0)
    {
        LOG(L"*** No sub-directories found: " << path);
        return false;
    }

    return DVLib::CompareVersion(comparison, directoryNames, version);
}
