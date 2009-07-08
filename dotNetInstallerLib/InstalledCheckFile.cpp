#include "StdAfx.h"
#include "InstalledCheckFile.h"
#include "InstallerLog.h"

InstalledCheckFile::InstalledCheckFile()
{
}

void InstalledCheckFile::Load(TiXmlElement * node, InstallerSetting& setting)
{
    LOG(L"----Reading CHECKFILE installed check: " << node->AttributeW("filename"));
    filename = setting.ValidatePath(node->AttributeW("filename"));
    fileversion = node->AttributeW("fileversion");
    comparison = node->AttributeW("comparison");
}

bool InstalledCheckFile::IsInstalled() const
{
	if (DVLib::FileExists(filename))
	{
		if (! fileversion.empty())
		{
			if (comparison == TEXT("exists"))
			{
				return DVLib::FileExists(filename);
			}
			else if (comparison == TEXT("match"))
			{
				return (DVLib::GetFileVersion(filename) == fileversion);
			}
			else if (comparison == TEXT("version"))
			{
				return (DVLib::CompareVersion(DVLib::GetFileVersion(filename), fileversion) >= 0);
			}
			else
			{
				THROW_EX(L"Invalid comparison type \"" << comparison << L"\"");
			}
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}
