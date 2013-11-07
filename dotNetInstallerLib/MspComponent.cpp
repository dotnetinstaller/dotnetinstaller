#include "StdAfx.h"
#include "XmlAttribute.h"
#include "MspComponent.h"
#include "InstallUILevel.h"
#include "InstallerLog.h"
#include "InstallConfiguration.h"
#include "InstallerSession.h"

MspComponent::MspComponent()
	: ProcessComponent(component_type_msp)
{

}

std::wstring MspComponent::GetCommandLine() const
{
	std::wstring l_command = L"msiexec";
	std::wstring l_cmdparameters;

	switch(InstallerSession::Instance->sequence)
	{
	case SequenceInstall:
		// patch
		l_command += L" /p ";
		l_command += DVLib::GetQuotedPathOrGuid(patch.GetValue());
		// apply a patch to an administrative package
		if (! package.GetValue().empty())
		{
			l_command += L" /a ";
			l_command += DVLib::GetQuotedPathOrGuid(package.GetValue());
		}
		// command-line parameters		
		l_cmdparameters = InstallUILevelSetting::Instance->GetCommand(
			cmdparameters, cmdparameters_basic, cmdparameters_silent);
		// REINSTALL
		if (! reinstall.GetValue().empty()) 
		{
			l_cmdparameters += L" REINSTALL=";
			l_cmdparameters += reinstall.GetValue();
		}
		// REINSTALLMODE
		if (! reinstallmode.GetValue().empty())
		{
			l_cmdparameters += L" REINSTALLMODE=";
			l_cmdparameters += reinstallmode.GetValue();
		}
		break;
	case SequenceUninstall:
		// command-line parameters
		l_cmdparameters = InstallUILevelSetting::Instance->GetCommand(
			uninstall_cmdparameters, uninstall_cmdparameters_basic, uninstall_cmdparameters_silent);
		// command
		l_command += L" /uninstall ";
		// patch
		l_command.append(DVLib::GetQuotedPathOrGuid(uninstall_patch.GetValue().empty() ?
			patch : uninstall_patch));
		// msi affected
		if (! uninstall_package.GetValue().empty())
		{
			l_command += L" /package ";
			l_command.append(DVLib::GetQuotedPathOrGuid(uninstall_package));
		}
		break;
	default:
		THROW_EX(L"Unsupported install sequence: " << InstallerSession::Instance->sequence << L".");
	}

	if (! l_cmdparameters.empty())
	{
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

void MspComponent::Exec()
{
	std::wstring command = GetCommandLine();
    LOG(L"Executing: " << command);
	ProcessComponent::ExecCmd(command, DVLib::CemCreateProcess, disable_wow64_fs_redirection);
}

void MspComponent::Load(TiXmlElement * node)
{
	patch = node->Attribute("patch");
	package = node->Attribute("package");
	cmdparameters = node->Attribute("cmdparameters");
	cmdparameters_silent = node->Attribute("cmdparameters_silent");
	cmdparameters_basic = node->Attribute("cmdparameters_basic");
	uninstall_patch = node->Attribute("uninstall_patch");
	uninstall_package = node->Attribute("uninstall_package");
	uninstall_cmdparameters = node->Attribute("uninstall_cmdparameters");
	uninstall_cmdparameters_silent = node->Attribute("uninstall_cmdparameters_silent");
	uninstall_cmdparameters_basic = node->Attribute("uninstall_cmdparameters_basic");
    disable_wow64_fs_redirection = XmlAttribute(node->Attribute("disable_wow64_fs_redirection")).GetBoolValue(false);
	Component::Load(node);
}

void MspComponent::Wait(DWORD tt)
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

bool MspComponent::IsRebootRequired() const
{
	return Component::IsRebootRequired() || 
		(GetProcessExitCode() == ERROR_SUCCESS_REBOOT_REQUIRED);
}
