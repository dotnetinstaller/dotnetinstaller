#include "StdAfx.h"
#include "InstalledCheck.h"
#include "InstalledCheckFile.h"
#include "InstalledCheckRegistry.h"

InstalledCheck::InstalledCheck(void)
{

}

InstalledCheck::~InstalledCheck(void)
{

}

InstalledCheck * InstalledCheck::LoadFromXml(TiXmlElement *node, InstallerSetting &setting)
{
    std::wstring installedcheck_type = node->AttributeW("type").data();
	InstalledCheck * new_installedcheck = NULL;
	if (installedcheck_type == L"check_registry_value")
	{
		InstalledCheckRegistry * new_check_registry_value = new InstalledCheckRegistry();
        new_check_registry_value->Load(node, setting);
		new_installedcheck = new_check_registry_value;
	}
	else if (installedcheck_type == L"check_file")
	{
		InstalledCheckFile * new_check_file = new InstalledCheckFile();
        new_check_file->Load(node, setting);
		new_installedcheck = new_check_file;
	}
	else
	{
		THROW_EX(L"Invalid configuration file, installed check type \"" << installedcheck_type << L"\" not supported");
	}

    return new_installedcheck;
}
