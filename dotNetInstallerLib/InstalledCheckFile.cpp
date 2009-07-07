#include "StdAfx.h"
#include "InstalledCheckFile.h"
#include "InstallerLog.h"

InstalledCheckFile::InstalledCheckFile()
{
}

void InstalledCheckFile::Load(TiXmlElement * node, InstallerSetting& setting)
{
    ApplicationLog.Write(TEXT("----Reading CHECKFILE installed check: "), node->AttributeW("filename").data());
    filename = setting.ValidatePath(node->AttributeW("filename").data());
    fileversion = node->AttributeW("fileversion").data();
    comparison = node->AttributeW("comparison").data();
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
