#include "StdAfx.h"
#include "Component.h"
#include "InstalledCheck.h"
#include "InstalledCheckRegistry.h"
#include "InstalledCheckFile.h"
#include "InstalledCheckOperator.h"
#include "EmbedFile.h"

Component::Component(component_type t)
	: type(t)
    , mustreboot(false)
    , must_reboot_required(false)
    , allow_continue_on_error(true)
    , cancelled(false)
    , required(true)
    , download(false)
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
	description = node->AttributeW("description");
	status_installed = node->AttributeW("status_installed");
	os_filter_greater = node->AttributeW("os_filter_greater");
	os_filter_smaller = node->AttributeW("os_filter_smaller");
	os_filter_lcid = node->AttributeW("os_filter_lcid");
	installcompletemessage = node->AttributeW("installcompletemessage");
	mustreboot = DVLib::string2bool(node->Attribute("mustreboot"), false);
    reboot_required = node->AttributeW("reboot_required");
	must_reboot_required = DVLib::string2bool(node->Attribute("must_reboot_required"), false);
    allow_continue_on_error = DVLib::string2bool(node->Attribute("allow_continue_on_error"), true);
    failed_exec_command_continue = node->AttributeW("failed_exec_command_continue");
	required = DVLib::string2bool(node->Attribute("required"), true);
	processor_architecture_filter = node->AttributeW("processor_architecture_filter");	
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
			std::wstring installedcheck_type = child_element->AttributeW("type");
			if (installedcheck_type == L"check_registry_value")
			{
				installedcheck = InstalledCheckPtr(new InstalledCheckRegistry());
			}
			else if (installedcheck_type == L"check_file")
			{
				installedcheck = InstalledCheckPtr(new InstalledCheckFile());
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