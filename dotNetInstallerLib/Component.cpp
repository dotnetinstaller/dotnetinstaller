#include "StdAfx.h"
#include "InstallerSession.h"
#include "XmlAttribute.h"
#include "Component.h"
#include "InstalledCheck.h"
#include "InstalledCheckRegistry.h"
#include "InstalledCheckFile.h"
#include "InstalledCheckDirectory.h"
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
	, supports_install(true)
	, supports_uninstall(false)
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
	description = XML_ATTRIBUTE(node->Attribute("description"));
	status_installed = XML_ATTRIBUTE(node->Attribute("status_installed"));
	os_filter_greater = XML_ATTRIBUTE(node->Attribute("os_filter_greater"));
	os_filter_smaller = XML_ATTRIBUTE(node->Attribute("os_filter_smaller"));
	os_filter_lcid = XML_ATTRIBUTE(node->Attribute("os_filter_lcid"));
	installcompletemessage = XML_ATTRIBUTE(node->Attribute("installcompletemessage"));
	uninstallcompletemessage = XML_ATTRIBUTE(node->Attribute("uninstallcompletemessage"));
	mustreboot = DVLib::wstring2bool(XML_ATTRIBUTE(node->Attribute("mustreboot")), false);
    reboot_required = XML_ATTRIBUTE(node->Attribute("reboot_required"));
	must_reboot_required = DVLib::wstring2bool(XML_ATTRIBUTE(node->Attribute("must_reboot_required")), false);
    allow_continue_on_error = DVLib::wstring2bool(XML_ATTRIBUTE(node->Attribute("allow_continue_on_error")), true);
    failed_exec_command_continue = XML_ATTRIBUTE(node->Attribute("failed_exec_command_continue"));
	required = DVLib::wstring2bool(XML_ATTRIBUTE(node->Attribute("required")), true);
	processor_architecture_filter = XML_ATTRIBUTE(node->Attribute("processor_architecture_filter"));		
	supports_install = DVLib::wstring2bool(XML_ATTRIBUTE(node->Attribute("supports_install")), true);
	supports_uninstall = DVLib::wstring2bool(XML_ATTRIBUTE(node->Attribute("supports_uninstall")), false);
	// install checks, embed files, etc.
	TiXmlNode * child = NULL;
	while( (child = node->IterateChildren(child)) != NULL )
	{
		TiXmlElement * child_element = child->ToElement();
		
		if (child_element == NULL)
			continue;
		
		if (strcmp(child_element->Value(), "installedcheck") == 0)
		{
			std::wstring installedcheck_type = DVLib::UTF8string2wstring(child_element->Attribute("type"));
			InstalledCheckPtr installedcheck(InstalledCheck::Create(installedcheck_type));
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
			auto_any<DownloadDialog *, close_delete> newdownloaddialog(new DownloadDialog());
			newdownloaddialog->Load(child_element);
			downloaddialog = newdownloaddialog;
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

bool Component::IsSupported(LCID lcid) const
{
	return DVLib::IsOperatingSystemLCIDValue(lcid, os_filter_lcid) &&
		DVLib::IsProcessorArchitecture(DVLib::GetProcessorArchitecture(), processor_architecture_filter) &&
		DVLib::IsInOperatingSystemInRange(DVLib::GetOperatingSystemVersion(), os_filter_greater, os_filter_smaller);
}

std::wstring Component::GetString(int indent) const
{
	std::wstringstream ss;
	for (int i = 0; i < indent; i++) ss << L" ";
	ss << description;
	if (! os_filter_lcid.empty())
		ss << L", lang=" << os_filter_lcid;
	if (! processor_architecture_filter.empty()) 
		ss << L", pa=" << processor_architecture_filter;
	if (! os_filter_greater.empty() || ! os_filter_smaller.empty())
		ss << L", os=" << os_filter_greater << L"/" << os_filter_smaller;
	return ss.str();
}

bool Component::IsRebootRequired() const
{
	return mustreboot;
}
