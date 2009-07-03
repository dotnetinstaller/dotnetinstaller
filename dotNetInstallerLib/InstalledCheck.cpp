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

InstalledCheck * InstalledCheck::LoadFromXml(TiXmlElement *l_Node, InstallerSetting &p_Setting)
{
    CString l_installedcheck_type = l_Node->AttributeW("type").data();
	InstalledCheck * l_new_installedcheck = NULL;
	if(l_installedcheck_type == "check_registry_value")
	{
		InstalledCheckRegistry * l_new_check_registry_value = new InstalledCheckRegistry();
        l_new_check_registry_value->Load(l_Node, p_Setting);
		l_new_installedcheck = l_new_check_registry_value;
	}
	else if(l_installedcheck_type == "check_file")
	{
		InstalledCheckFile * l_new_check_file = new InstalledCheckFile();
        l_new_check_file->Load(l_Node, p_Setting);
		l_new_installedcheck = l_new_check_file;
	}
	else
	{
		throw std::exception("Invalid configuration file, installed check type not supported");
	}

    return l_new_installedcheck;
}
