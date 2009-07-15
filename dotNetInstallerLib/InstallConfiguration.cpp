#include "StdAfx.h"
#include "Configuration.h"
#include "InstallerLog.h"
#include "InstallerSession.h"
#include "InstallConfiguration.h"
#include "MsiComponent.h"
#include "CmdComponent.h"
#include "OpenFileComponent.h"

InstallConfiguration::InstallConfiguration()
	: Configuration(configuration_install)
    , must_reboot_required(false)
    , auto_close_if_installed(false)
	, auto_close_optional(true)
    , auto_close_on_error(false)
    , dialog_show_installed(false)
    , dialog_show_required(false)
    , allow_continue_on_error(true)
    , log_enabled(false)
{

}

void InstallConfiguration::AddComponent(const ComponentPtr& c)
{
    components_map.insert(std::make_pair(c->description, c));
    components.push_back(c);
}

void InstallConfiguration::Load(TiXmlElement * node)
{
	CHECK_BOOL(node != NULL,
		L"Expected 'configuration' node");

	CHECK_BOOL(0 == strcmp(node->Value(), "configuration"),
		L"Expected 'configuration' node, got '" << DVLib::string2wstring(node->Value()) << L"'");

	Configuration::Load(node);

    // auto-enabled log options
    log_enabled = DVLib::wstring2bool(node->AttributeW("log_enabled"), false);
    log_file = node->AttributeW("log_file");
    // defines where to extract files and auto-delete options
    cab_path = node->AttributeW("cab_path");
	InstallerSession::s_sessioncabpath = cab_path;
    cab_path_autodelete = DVLib::wstring2bool(node->AttributeW("cab_path_autodelete"), true);
    // positions within the dialog
    dialog_position.FromString(node->AttributeW("dialog_position"));
    dialog_components_list_position.FromString(node->AttributeW("dialog_components_list_position"));
    dialog_message_position.FromString(node->AttributeW("dialog_message_position"));
    dialog_bitmap_position.FromString(node->AttributeW("dialog_bitmap_position"));
    dialog_otherinfo_link_position.FromString(node->AttributeW("dialog_otherinfo_link_position"));
    dialog_osinfo_position.FromString(node->AttributeW("dialog_osinfo_position"));
    dialog_install_button_position.FromString(node->AttributeW("dialog_install_button_position"));
    dialog_cancel_button_position.FromString(node->AttributeW("dialog_cancel_button_position"));
    dialog_skip_button_position.FromString(node->AttributeW("dialog_skip_button_position"));
    // other dialog options
	cancel_caption = node->AttributeW("cancel_caption");
	dialog_bitmap = InstallerSession::MakePath(node->AttributeW("dialog_bitmap"));
	dialog_caption = node->AttributeW("dialog_caption");
	dialog_message = node->AttributeW("dialog_message");
	skip_caption = node->AttributeW("skip_caption");
	install_caption = node->AttributeW("install_caption");
	status_installed = node->AttributeW("status_installed");
	status_notinstalled = node->AttributeW("status_notinstalled");
	failed_exec_command_continue = node->AttributeW("failed_exec_command_continue");
	installation_completed = node->AttributeW("installation_completed");
	installation_none = node->AttributeW("installation_none");
	reboot_required = node->AttributeW("reboot_required");
    must_reboot_required = DVLib::wstring2bool(node->AttributeW("must_reboot_required"), false);
	installing_component_wait = node->AttributeW("installing_component_wait");
	dialog_otherinfo_caption = node->AttributeW("dialog_otherinfo_caption");
	dialog_otherinfo_link = InstallerSession::MakePath(node->AttributeW("dialog_otherinfo_link"));
	// completion commands
	complete_command = InstallerSession::MakePath(node->AttributeW("complete_command"));
	complete_command_silent = InstallerSession::MakePath(node->AttributeW("complete_command_silent"));
	auto_close_if_installed = DVLib::wstring2bool(node->AttributeW("auto_close_if_installed"), true);
	auto_close_optional = DVLib::wstring2bool(node->AttributeW("auto_close_optional"), true);
    auto_close_on_error = DVLib::wstring2bool(node->AttributeW("auto_close_on_error"), false);
    allow_continue_on_error = DVLib::wstring2bool(node->AttributeW("allow_continue_on_error"), true);
    dialog_show_installed = DVLib::wstring2bool(node->AttributeW("dialog_show_installed"), true);
    dialog_show_required = DVLib::wstring2bool(node->AttributeW("dialog_show_required"), true);
	// os filters
	os_filter_greater = node->AttributeW("os_filter_greater");
	os_filter_smaller = node->AttributeW("os_filter_smaller");
	// processor architecture filter
	processor_architecture_filter = node->AttributeW("processor_architecture_filter");
    // message and caption to show during CAB extraction
    cab_dialog_caption = node->AttributeW("cab_dialog_caption");
    cab_dialog_message = node->AttributeW("cab_dialog_message");
    cab_cancelled_message = node->AttributeW("cab_cancelled_message");
	// components
	TiXmlNode * child = NULL;
	while ( (child = node->IterateChildren("component", child)) != NULL)
	{
		TiXmlElement * node_component = child->ToElement();
		if (node_component == NULL)
			continue;

		std::wstring component_type = node_component->AttributeW("type");

		shared_any<Component *, close_delete> component;
		if (component_type == L"msi") component = shared_any<Component *, close_delete>(new MsiComponent());
		else if (component_type == L"cmd") component = shared_any<Component *, close_delete>(new CmdComponent());
		else if (component_type == L"openfile") component = shared_any<Component *, close_delete>(new OpenFileComponent());
		else 
		{
			THROW_EX(L"Unsupported component type: " << component_type);
		}

		component->Load(node_component);
		AddComponent(component);
	}

	LOG(L"Loaded " << components.size() << L" components from configuration type=" << type 
		<< L", lcid=" << lcid
		<< L", os_filter_greater=" << os_filter_greater
		<< L", os_filter_smaller=" << os_filter_smaller
		<< L", processor_architecture_filter=" << processor_architecture_filter);
}

bool InstallConfiguration::HasComponent(const std::wstring& description) const 
{ 
	return components_map.find(description) != components_map.end(); 
}

bool InstallConfiguration::IsSupported(DVLib::LcidType lcidtype) const
{
	return Configuration::IsSupported(lcidtype) &&
		// \todo: support processor architecture and os range in reference configuration, move to base
		DVLib::IsProcessorArchitecture(DVLib::GetProcessorArchitecture(), processor_architecture_filter) &&
		DVLib::IsInOperatingSystemInRange(DVLib::GetOperatingSystemVersion(), os_filter_greater, os_filter_smaller);
}
