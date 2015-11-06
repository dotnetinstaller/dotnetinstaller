#include "StdAfx.h"
#include "InstalledCheckDirectory.h"
#include "InstallerLog.h"
#include "InstallConfiguration.h"
#include "InstallerSession.h"

InstalledCheckDirectory::InstalledCheckDirectory()
{
}

void InstalledCheckDirectory::Load(TiXmlElement * node)
{
    path = InstallerSession::Instance->ExpandVariables(DVLib::UTF8string2wstring(node->Attribute("path")));
    LOG(L"Loaded 'directory' installed check '" << path << L"'");
}

bool InstalledCheckDirectory::IsInstalled() const
{
    return DVLib::DirectoryExists(path);
}
