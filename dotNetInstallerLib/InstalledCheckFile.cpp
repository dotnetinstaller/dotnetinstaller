#include "StdAfx.h"
#include "InstalledCheckFile.h"
#include "InstallerLog.h"

InstalledCheckFile::InstalledCheckFile()
{
}

void InstalledCheckFile::Load(TiXmlElement * l_Node, InstallerSetting& p_Setting)
{
    ApplicationLog.Write(TEXT("----Reading CHECKFILE installed check: "), l_Node->AttributeW("filename").data());
    filename = p_Setting.ValidatePath(l_Node->AttributeW("filename").data());
    fileversion = l_Node->AttributeW("fileversion").data();
    comparison = l_Node->AttributeW("comparison").data();
}

bool InstalledCheckFile::IsInstalled()
{
	try
	{
		if (DVLib::FileExists(filename))
		{
			CString l_FileVersion = DVLib::GetFileVersionString(filename);

			if (fileversion.GetLength() > 0)
			{
				if (comparison == TEXT("exists"))
				{
					return DVLib::FileExists(filename);
				}
				else if (comparison == TEXT("match"))
				{
					return (l_FileVersion == fileversion);
				}
				else if (comparison == TEXT("version"))
				{
					//se la versione è uguale o maggiore
					return (DVLib::stringVersionCompare(l_FileVersion, fileversion) >= 0);
				}
				else
				{
					throw std::exception("Invalid comparison type; expected match, version, or exists.");
				}
			}
			else
			{
				return true;
			}
		}
		else
			return false;
	}
	catch(...)
	{
		return false;
	}
}
