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
#include "InstallerLog.h"

Component::Component(component_type t)
: type(t),
mustreboot(false),
must_reboot_required(false),
allow_continue_on_error(true),
default_continue_on_error(false),
cancelled(false),
required_install(true),
required_uninstall(true),
selected_install(true),
selected_uninstall(true),
checked(true),
disabled(false),
supports_install(true),
supports_uninstall(false),
os_filter_min(DVLib::winNone),
os_filter_max(DVLib::winNone),
show_progress_dialog(true),
show_cab_dialog(true),
installed(false),
hide_component_if_installed(false),
main_window(NULL)
{

}

Component::~Component(void)
{
}

bool Component::IsRequired() const
{
    if (required_install && InstallerSession::Instance->sequence == SequenceInstall)
        return true;
    else if (required_uninstall && InstallerSession::Instance->sequence == SequenceUninstall)
        return true;
    else 
        return false;
}

bool Component::IsInstalled() const
{
    if (installedchecks.size() == 0)
    {
        switch(InstallerSession::Instance->sequence)
        {
        case SequenceUninstall:
            return true;
        case SequenceInstall:
            return false;
        default:
            THROW_EX(L"Unsupported install sequence: " << InstallerSession::Instance->sequence);
        }
    }

    bool installed = true;

    for (size_t j = 0; j < installedchecks.size(); j++)
    {
        installed &= installedchecks[j]->IsInstalled();
    }

    return installed;
}

void Component::Load(tinyxml2::XMLElement * node)
{
    id = node->Attribute("id");
    display_name = node->Attribute("display_name");
    uninstall_display_name = node->Attribute("uninstall_display_name");
    if (id.empty()) id = display_name;
    status_installed = node->Attribute("status_installed");
    status_notinstalled = node->Attribute("status_notinstalled");
    os_filter = node->Attribute("os_filter");
    os_filter_min = DVLib::oscode2os(XmlAttribute(node->Attribute("os_filter_min")).GetValue());
    os_filter_max = DVLib::oscode2os(XmlAttribute(node->Attribute("os_filter_max")).GetValue());
    os_type_filter = node->Attribute("os_type_filter");
    os_filter_lcid = node->Attribute("os_filter_lcid");
    installcompletemessage = node->Attribute("installcompletemessage");
    uninstallcompletemessage = node->Attribute("uninstallcompletemessage");
    mustreboot = XmlAttribute(node->Attribute("mustreboot")).GetBoolValue(false);
    reboot_required = node->Attribute("reboot_required");
    must_reboot_required = XmlAttribute(node->Attribute("must_reboot_required")).GetBoolValue(false);
    allow_continue_on_error = XmlAttribute(node->Attribute("allow_continue_on_error")).GetBoolValue(true);
    default_continue_on_error = XmlAttribute(node->Attribute("default_continue_on_error")).GetBoolValue(false);
    failed_exec_command_continue = node->Attribute("failed_exec_command_continue");
    required_install = XmlAttribute(node->Attribute("required_install")).GetBoolValue(true);
    required_uninstall = XmlAttribute(node->Attribute("required_uninstall")).GetBoolValue(true);
    selected_install = XmlAttribute(node->Attribute("selected_install")).GetBoolValue(true);
    selected_uninstall = XmlAttribute(node->Attribute("selected_uninstall")).GetBoolValue(true);
    processor_architecture_filter = node->Attribute("processor_architecture_filter");
    supports_install = XmlAttribute(node->Attribute("supports_install")).GetBoolValue(true);
    supports_uninstall = XmlAttribute(node->Attribute("supports_uninstall")).GetBoolValue(false);
    // progress options
    show_progress_dialog = XmlAttribute(node->Attribute("show_progress_dialog")).GetBoolValue(true);
    show_cab_dialog = XmlAttribute(node->Attribute("show_cab_dialog")).GetBoolValue(true);
    hide_component_if_installed = XmlAttribute(node->Attribute("hide_component_if_installed")).GetBoolValue(false);
    // install checks, embed files, etc.
    for (tinyxml2::XMLNode* child = node->FirstChildElement(); child; child = child->NextSibling())
    {
        tinyxml2::XMLElement * child_element = child->ToElement();

        if (child_element == NULL)
            continue;

        std::wstring type = DVLib::UTF8string2wstring(child_element->Value());

        if (type == L"installedcheck")
        {
            std::wstring installedcheck_type = DVLib::UTF8string2wstring(child_element->Attribute("type"));
            InstalledCheckPtr installedcheck(InstalledCheck::Create(installedcheck_type));
            installedcheck->Load(child_element);
            installedchecks.push_back(installedcheck);
        }
        else if (type == L"installedcheckoperator")
        {
            InstalledCheckPtr installedcheckoperator(new InstalledCheckOperator());
            installedcheckoperator->Load(child_element);
            installedchecks.push_back(installedcheckoperator);
        }
        else if (type == L"embedfile")
        {
            EmbedFilePtr embedfile(new EmbedFile());
            embedfile->Load(child_element);
            embedfiles.push_back(embedfile);			
        }
        else if (type == L"embedfolder")
        {
            EmbedFolderPtr embedfolder(new EmbedFolder());
            embedfolder->Load(child_element);
            embedfolders.push_back(embedfolder);			
        }
        else if (type == L"downloaddialog")
        {
            auto_any<DownloadDialog *, close_delete> newdownloaddialog(new DownloadDialog(id));
            newdownloaddialog->Load(child_element);
            downloaddialog = newdownloaddialog;
        }
        else
        {
            THROW_EX(L"Unexpected node '" << type << L"'");
        }
    }

    LOG(L"Loaded " << GetString());
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
        DVLib::IsInOperatingSystemInRange(DVLib::GetOperatingSystemVersion(), os_filter, os_filter_min, os_filter_max) &&
        DVLib::IsOperatingSystemProductType(DVLib::GetOperatingSystemProductType(), os_type_filter);
}

std::wstring Component::GetString(int indent) const
{
    std::wstringstream ss;
    for (int i = 0; i < indent; i++) ss << L" ";
    ss << id << L", display_name='" << GetDisplayName() << L"'";
    if (! os_filter_lcid.empty())
        ss << L", lang=" << os_filter_lcid;
    if (! processor_architecture_filter.empty()) 
        ss << L", pa=" << processor_architecture_filter;
    if (! os_filter.empty())
        ss << L", os=" << os_filter;
    if (os_filter_min != DVLib::winNone)
        ss << L", os_filter_min=" << DVLib::os2wstring(os_filter_min);
    if (os_filter_max != DVLib::winNone)
        ss << L", os_filter_max=" << DVLib::os2wstring(os_filter_max);
    if (!os_type_filter.empty())
        ss << L", os_type=" << os_type_filter;
    return ss.str();
}

bool Component::IsRebootRequired() const
{
    return mustreboot;
}

std::wstring Component::GetAdditionalCmd() const
{
    std::wstring cmd;
    std::wstring cmds[] = { L"*", id, GetDisplayName() };

    for (int i = 0; i < ARRAYSIZE(cmds); i++)
    {
        std::map<std::wstring, std::wstring>::iterator cmd_iter = InstallerSession::Instance->AdditionalCmdLineArgs.find(cmds[i]);
        if (cmd_iter != InstallerSession::Instance->AdditionalCmdLineArgs.end())
        {
            cmd.append(L" ");
            cmd.append(cmd_iter->second);
            LOG(L"-- Additional component '" << id << L"' argument (" << cmds[i] << L"): " << cmd_iter->second);
        }
    }

    if (! cmd.empty())
    {
        LOG(L"-- Additional component '" << id << L"' arguments: " << cmd);
    }

    return cmd;
}

std::wstring Component::GetDisplayName() const
{
    switch(InstallerSession::Instance->sequence)
    {
    case SequenceInstall:
        return display_name;
    case SequenceUninstall:
        return uninstall_display_name.empty() ? display_name : uninstall_display_name;
    default:
        THROW_EX(L"Unsupported install sequence: " << InstallerSession::Instance->sequence << L".");
    }
}
