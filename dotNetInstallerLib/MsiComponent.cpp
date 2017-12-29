#include "StdAfx.h"
#include "XmlAttribute.h"
#include "MsiComponent.h"
#include "InstallUILevel.h"
#include "InstallerLog.h"
#include "InstallConfiguration.h"
#include "InstallerSession.h"

MsiComponent::MsiComponent()
: ProcessComponent(component_type_msi),
disable_wow64_fs_redirection(false)
{

}

std::wstring MsiComponent::GetCommandLine() const
{
    std::wstring l_command = L"msiexec";
    std::wstring l_package;
    std::wstring l_cmdparameters;	

    switch(InstallerSession::Instance->sequence)
    {
    case SequenceInstall:
        l_package = package.GetValue();
        l_cmdparameters = InstallUILevelSetting::Instance->GetCommand(
            cmdparameters, cmdparameters_basic, cmdparameters_silent);
        l_command += L" /i"; 
        break;
    case SequenceUninstall:
        l_package = uninstall_package.empty() 
            ? package.GetValue()
            : uninstall_package.GetValue();
        l_cmdparameters = InstallUILevelSetting::Instance->GetCommand(
            uninstall_cmdparameters, uninstall_cmdparameters_basic, uninstall_cmdparameters_silent);
        l_command += L" /x"; 
        break;
    default:
        THROW_EX(L"Unsupported install sequence: " << InstallerSession::Instance->sequence << L".");
    }

    l_command.append(L" ");
    l_command.append(DVLib::GetQuotedPathOrGuid(l_package));

    LOG(L"-- Package: " << l_package);

    if (! l_cmdparameters.empty())
    {
        LOG(L"-- Additional command-line parameters: " << l_cmdparameters);
        l_command.append(L" ");
        l_command.append(l_cmdparameters);
    }

    std::wstring additional_cmd = GetAdditionalCmd();
    if (! additional_cmd.empty())
    {
        l_command.append(L" ");
        l_command.append(additional_cmd);
    }

    l_command = InstallerSession::Instance->ExpandUserVariables(l_command);

    return l_command;
}

void MsiComponent::Exec()
{
    std::wstring command = GetCommandLine();
    LOG(L"Executing: " << command);
    ProcessComponent::ExecCmd(command, DVLib::CemCreateProcess, disable_wow64_fs_redirection);
}

void MsiComponent::Load(tinyxml2::XMLElement * node)
{
    package = node->Attribute("package");
    cmdparameters = node->Attribute("cmdparameters");
    cmdparameters_silent = node->Attribute("cmdparameters_silent");
    cmdparameters_basic = node->Attribute("cmdparameters_basic");
    uninstall_package = node->Attribute("uninstall_package");
    uninstall_cmdparameters = node->Attribute("uninstall_cmdparameters");
    uninstall_cmdparameters_silent = node->Attribute("uninstall_cmdparameters_silent");
    uninstall_cmdparameters_basic = node->Attribute("uninstall_cmdparameters_basic");
    disable_wow64_fs_redirection = XmlAttribute(node->Attribute("disable_wow64_fs_redirection")).GetBoolValue(false);
    Component::Load(node);
}

void MsiComponent::Wait(DWORD tt)
{
    ProcessComponent::Wait(tt);

    DWORD exitcode = ProcessComponent::GetProcessExitCode();

    LOG(L"Component '" << id << "' return code " << exitcode 
        << DVLib::FormatMessage(L" (0x%x).", exitcode));

    // a non-zero error code represents failure
    CHECK_BOOL(exitcode == ERROR_SUCCESS || exitcode == ERROR_SUCCESS_REBOOT_REQUIRED,
        L"Error executing '" << id << "' (" << GetDisplayName() << L"): " 
        << exitcode << DVLib::FormatMessage(L" (0x%x)", exitcode));
}

bool MsiComponent::IsRebootRequired() const
{
    return Component::IsRebootRequired() 
        || (GetProcessExitCode() == ERROR_SUCCESS_REBOOT_REQUIRED);
}
