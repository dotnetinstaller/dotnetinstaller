#include "StdAfx.h"
#include "InstalledCheckFile.h"

InstalledCheckFile::InstalledCheckFile()
{
}

void InstalledCheckFile::Load(TiXmlElement * l_Node, InstallerSetting& p_Setting)
{
    ApplicationLog.Write(TEXT("----Reading CHECKFILE installed check: "), l_Node->AttributeT("filename").data());
    filename = p_Setting.ValidatePath(l_Node->AttributeT("filename").data());
    fileversion = l_Node->AttributeT("fileversion").data();
    comparison = l_Node->AttributeT("comparison").data();
}

bool InstalledCheckFile::IsInstalled()
{
	try
	{
		if (DVLib::FileExistsCustom(filename))
		{
			CString l_FileVersion = DVLib::GetFileVersionString(filename);

			if (fileversion.GetLength() > 0)
			{
				if (comparison == TEXT("exists"))
				{
					return DVLib::FileExistsCustom(filename);
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
					DniSilentMessageBox(TEXT("Invalid comparison type; expected match, version, or exists."), MB_OK|MB_ICONSTOP);
					return false;
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
