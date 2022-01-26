#include "StdAfx.h"
#include "XmlAttribute.h"
#include "Configuration.h"
#include "InstallerLog.h"
#include "InstallerSession.h"
#include "InstallConfiguration.h"
#include "MsiComponent.h"
#include "MsuComponent.h"
#include "MspComponent.h"
#include "CmdComponent.h"
#include "ExeComponent.h"
#include "OpenFileComponent.h"
#include "ControlLabel.h"
#include "ControlCheckBox.h"
#include "ControlEdit.h"
#include "ControlBrowse.h"
#include "ControlLicense.h"
#include "ControlHyperlink.h"
#include "ControlImage.h"

InstallConfiguration::InstallConfiguration()
: Configuration(configuration_install),
must_reboot_required(false),
prompt_for_optional_components(false),
auto_close_if_installed(false),
auto_close_on_error(false),
reload_on_error(true),
dialog_show_installed(false),
dialog_show_uninstalled(false),
dialog_show_required(false),
auto_start(false),
auto_continue_on_reboot(false),
wait_for_complete_command(true),
show_progress_dialog(true),
show_cab_dialog(true),
disable_wow64_fs_redirection(false),
cab_path_autodelete(false),
administrator_required(false)
{

}

void InstallConfiguration::Load(tinyxml2::XMLElement * node)
{
    CHECK_BOOL(node != NULL,
        L"Expected 'configuration' node");

    CHECK_BOOL(0 == strcmp(node->Value(), "configuration"),
        L"Expected 'configuration' node, got '" << DVLib::string2wstring(node->Value()) << L"'");

    Configuration::Load(node);

    // defines where to extract files and auto-delete options
    cab_path = node->Attribute("cab_path");
    InstallerSession::Instance->cabpath = cab_path.GetValue();
    cab_path_autodelete = XmlAttribute(node->Attribute("cab_path_autodelete")).GetBoolValue(true);
    // positions within the dialog
    dialog_position.FromString(DVLib::UTF8string2wstring(node->Attribute("dialog_position")));
    dialog_components_list_position.FromString(DVLib::UTF8string2wstring(node->Attribute("dialog_components_list_position")));
    dialog_message_position.FromString(DVLib::UTF8string2wstring(node->Attribute("dialog_message_position")));
    dialog_bitmap_position.FromString(DVLib::UTF8string2wstring(node->Attribute("dialog_bitmap_position")));
    dialog_otherinfo_link_position.FromString(DVLib::UTF8string2wstring(node->Attribute("dialog_otherinfo_link_position")));
    dialog_osinfo_position.FromString(DVLib::UTF8string2wstring(node->Attribute("dialog_osinfo_position")));
    dialog_install_button_position.FromString(DVLib::UTF8string2wstring(node->Attribute("dialog_install_button_position")));
    dialog_cancel_button_position.FromString(DVLib::UTF8string2wstring(node->Attribute("dialog_cancel_button_position")));
    dialog_skip_button_position.FromString(DVLib::UTF8string2wstring(node->Attribute("dialog_skip_button_position")));
    // other dialog options
    dialog_default_button = node->Attribute("dialog_default_button");
    cancel_caption = node->Attribute("cancel_caption");
    dialog_bitmap = node->Attribute("dialog_bitmap");
    dialog_caption = node->Attribute("dialog_caption");
    dialog_message = node->Attribute("dialog_message");
    dialog_message_uninstall = node->Attribute("dialog_message_uninstall");
    skip_caption = node->Attribute("skip_caption");
    install_caption = node->Attribute("install_caption");
    uninstall_caption = node->Attribute("uninstall_caption");
    status_installed = node->Attribute("status_installed");
    status_notinstalled = node->Attribute("status_notinstalled");
    failed_exec_command_continue = node->Attribute("failed_exec_command_continue");
    installation_completed = node->Attribute("installation_completed");
    uninstallation_completed = node->Attribute("uninstallation_completed");
    installation_none = node->Attribute("installation_none");
    uninstallation_none = node->Attribute("uninstallation_none");
    reboot_required = node->Attribute("reboot_required");
    must_reboot_required = XmlAttribute(node->Attribute("must_reboot_required")).GetBoolValue(false);
    installing_component_wait = node->Attribute("installing_component_wait");
    uninstalling_component_wait = node->Attribute("uninstalling_component_wait");
    dialog_otherinfo_caption = node->Attribute("dialog_otherinfo_caption");
    dialog_otherinfo_link = node->Attribute("dialog_otherinfo_link");
    // completion commands
    complete_command = node->Attribute("complete_command");
    complete_command_basic = node->Attribute("complete_command_basic");
    complete_command_silent = node->Attribute("complete_command_silent");
    wait_for_complete_command = XmlAttribute(node->Attribute("wait_for_complete_command")).GetBoolValue(true);
    prompt_for_optional_components = XmlAttribute(node->Attribute("prompt_for_optional_components")).GetBoolValue(true);
    auto_close_if_installed = XmlAttribute(node->Attribute("auto_close_if_installed")).GetBoolValue(true);
    auto_close_on_error = XmlAttribute(node->Attribute("auto_close_on_error")).GetBoolValue(false);
    reload_on_error = XmlAttribute(node->Attribute("reload_on_error")).GetBoolValue(true);
    dialog_show_installed = XmlAttribute(node->Attribute("dialog_show_installed")).GetBoolValue(true);
    dialog_show_uninstalled = XmlAttribute(node->Attribute("dialog_show_uninstalled")).GetBoolValue(true);
    dialog_show_required = XmlAttribute(node->Attribute("dialog_show_required")).GetBoolValue(true);
    // message and caption to show during CAB extraction
    cab_dialog_caption = node->Attribute("cab_dialog_caption");
    cab_dialog_message = node->Attribute("cab_dialog_message");
    cab_cancelled_message = node->Attribute("cab_cancelled_message");
    // auto start
    auto_start = XmlAttribute(node->Attribute("auto_start")).GetBoolValue(false);
    // auto start on reboot
    auto_continue_on_reboot = XmlAttribute(node->Attribute("auto_continue_on_reboot")).GetBoolValue(false);
    // additional reboot cmd
    reboot_cmd = node->Attribute("reboot_cmd");
    // progress options
    show_progress_dialog = XmlAttribute(node->Attribute("show_progress_dialog")).GetBoolValue(true);
    show_cab_dialog = XmlAttribute(node->Attribute("show_cab_dialog")).GetBoolValue(true);
    disable_wow64_fs_redirection = XmlAttribute(node->Attribute("disable_wow64_fs_redirection")).GetBoolValue(false);
    // administrator required
    administrator_required = XmlAttribute(node->Attribute("administrator_required")).GetBoolValue(false);
    administrator_required_message = node->Attribute("administrator_required_message");
    // components
    for ( tinyxml2::XMLNode* child = node->FirstChildElement("component"); child; child = child->NextSiblingElement("component") )
    {
        tinyxml2::XMLElement * node_component = child->ToElement();
        if (node_component == NULL)
            continue;

        std::wstring component_type = DVLib::UTF8string2wstring(node_component->Attribute("type"));

        shared_any<Component *, close_delete> component;
        if (component_type == L"msi") component = shared_any<Component *, close_delete>(new MsiComponent());
        else if (component_type == L"msu") component = shared_any<Component *, close_delete>(new MsuComponent());
        else if (component_type == L"msp") component = shared_any<Component *, close_delete>(new MspComponent());
        else if (component_type == L"cmd") component = shared_any<Component *, close_delete>(new CmdComponent());
        else if (component_type == L"exe") component = shared_any<Component *, close_delete>(new ExeComponent());
        else if (component_type == L"openfile") component = shared_any<Component *, close_delete>(new OpenFileComponent());
        else 
        {
            THROW_EX(L"Unsupported component type: " << component_type);
        }

        component->Load(node_component);
        components.add(component);
    }

    // controls
    for ( tinyxml2::XMLNode* child = node->FirstChildElement("control"); child; child = child->NextSiblingElement("control") )
    {
        tinyxml2::XMLElement * node_control = child->ToElement();
        if (node_control == NULL)
            continue;

        std::wstring control_type = DVLib::UTF8string2wstring(node_control->Attribute("type"));

        shared_any<Control *, close_delete> control;
        if (control_type == L"label") reset(control, new ControlLabel());
        else if (control_type == L"checkbox") reset(control, new ControlCheckBox());
        else if (control_type == L"edit") reset(control, new ControlEdit());
        else if (control_type == L"browse") reset(control, new ControlBrowse());
        else if (control_type == L"license") reset(control, new ControlLicense());
        else if (control_type == L"hyperlink") reset(control, new ControlHyperlink());
        else if (control_type == L"image") reset(control, new ControlImage());
        else 
        {
            THROW_EX(L"Unsupported control type: " << control_type);
        }

        control->Load(node_control);
        controls.push_back(control);
    }

    LOG(L"Loaded " << components.size() << L" component(s) from configuration type=" << type 
        << L" (lcid_filter=" << lcid_filter
        << L", os_filter=" << os_filter
        << L", os_filter_min=" << DVLib::os2wstring(os_filter_min)
        << L", os_filter_max=" << DVLib::os2wstring(os_filter_max)
        << L", os_type_filter=" << os_type_filter
        << L", processor_architecture_filter=" << processor_architecture_filter
        << L")");
}

Components InstallConfiguration::GetSupportedComponents(DVLib::LcidType lcidtype, InstallSequence sequence) const
{
    return components.GetSupportedComponents(lcidtype, sequence);
}

ComponentPtr InstallConfiguration::GetComponentPtr(Component * pc) const
{
    return components.GetComponentPtr(pc);
}

std::wstring InstallConfiguration::GetString(int indent) const
{
    std::wstringstream ss;
    for(int i = 0; i < indent; i++) ss << L" ";
    ss << L"Install" << Configuration::GetString() << std::endl;
    ss << components.GetString(indent + 1) << std::endl;
    return ss.str();
}
