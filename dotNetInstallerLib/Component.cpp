#include "StdAfx.h"
#include "Component.h"
#include "InstalledCheck.h"
#include "InstalledCheckRegistry.h"
#include "InstalledCheckFile.h"
#include "InstalledCheckOperator.h"
#include "InstalledCheckProduct.h"
#include "EmbedFile.h"

Component::Component(component_type t)
	: type(t)
    , mustreboot(false)
    , must_reboot_required(false)
    , allow_continue_on_error(true)
    , cancelled(false)
    , required(true)
    , selected(true)
	, downloadconfiguration(NULL)
{

}

Component::~Component(void)
{
}

bool Component::IsInstalled() const
{
	if (installedchecks.size() == 0)
		return false;

	bool installed = true;
	
    for (size_t j = 0; j < installedchecks.size(); j++)
	{
		installed &= installedchecks[j]->IsInstalled();
	}

	return installed;
}

void Component::Load(TiXmlElement * node)
{
	description = DVLib::UTF8string2wstring(node->Attribute("description"));
	status_installed = DVLib::UTF8string2wstring(node->Attribute("status_installed"));
	os_filter_greater = DVLib::UTF8string2wstring(node->Attribute("os_filter_greater"));
	os_filter_smaller = DVLib::UTF8string2wstring(node->Attribute("os_filter_smaller"));
	os_filter_lcid = DVLib::UTF8string2wstring(node->Attribute("os_filter_lcid"));
	installcompletemessage = DVLib::UTF8string2wstring(node->Attribute("installcompletemessage"));
	mustreboot = DVLib::wstring2bool(DVLib::UTF8string2wstring(node->Attribute("mustreboot")), false);
    reboot_required = DVLib::UTF8string2wstring(node->Attribute("reboot_required"));
	must_reboot_required = DVLib::wstring2bool(DVLib::UTF8string2wstring(node->Attribute("must_reboot_required")), false);
    allow_continue_on_error = DVLib::wstring2bool(DVLib::UTF8string2wstring(node->Attribute("allow_continue_on_error")), true);
    failed_exec_command_continue = DVLib::UTF8string2wstring(node->Attribute("failed_exec_command_continue"));
	required = DVLib::wstring2bool(DVLib::UTF8string2wstring(node->Attribute("required")), true);
	processor_architecture_filter = DVLib::UTF8string2wstring(node->Attribute("processor_architecture_filter"));	
	// install checks, embed files, etc.
	TiXmlNode * child = NULL;
	while( (child = node->IterateChildren(child)) != NULL )
	{
		TiXmlElement * child_element = child->ToElement();
		
		if (child_element == NULL)
			continue;
		
		if (strcmp(child_element->Value(), "installedcheck") == 0)
		{
			InstalledCheckPtr installedcheck;
			std::wstring installedcheck_type = DVLib::UTF8string2wstring(child_element->Attribute("type"));
			if (installedcheck_type == L"check_registry_value")
			{
				installedcheck = InstalledCheckPtr(new InstalledCheckRegistry());
			}
			else if (installedcheck_type == L"check_file")
			{
				installedcheck = InstalledCheckPtr(new InstalledCheckFile());
			}
			else if (installedcheck_type == L"check_product")
			{
				installedcheck = InstalledCheckPtr(new InstalledCheckProduct());
			}
			else
			{
				THROW_EX(L"Invalid installed check type '" << installedcheck_type << L"'");
			}

			installedcheck->Load(child_element);
			installedchecks.push_back(installedcheck);
		}
		else if (strcmp(child_element->Value(), "installedcheckoperator") == 0)
		{
			InstalledCheckPtr installedcheckoperator(new InstalledCheckOperator());
			installedcheckoperator->Load(child_element);
			installedchecks.push_back(installedcheckoperator);
		}
		else if (strcmp(child_element->Value(), "embedfile") == 0)
		{
			EmbedFilePtr embedfile(new EmbedFile());
			embedfile->Load(child_element);
			embedfiles.push_back(embedfile);			
		}
		else if (strcmp(child_element->Value(), "downloaddialog") == 0)
		{
			DownloadGroupConfigurationPtr newdownloadconfiguration(new DownloadGroupConfiguration());
			newdownloadconfiguration->Load(child_element);
			downloadconfiguration = newdownloadconfiguration;
		}
		else
		{
			THROW_EX(L"Unexpected node '" << child_element->Value() << L"'");
		}
	}
}

void Component::Wait(DWORD tt)
{
	// \todo: change active wait to a semaphore
	while(IsExecuting())
	{
		Sleep(tt);
	}
}

bool Component::IsSupported(DVLib::LcidType lcidtype) const
{
	return DVLib::IsOperatingSystemLCID(lcidtype, os_filter_lcid) &&
		DVLib::IsProcessorArchitecture(DVLib::GetProcessorArchitecture(), processor_architecture_filter) &&
		DVLib::IsInOperatingSystemInRange(DVLib::GetOperatingSystemVersion(), os_filter_greater, os_filter_smaller);
}
