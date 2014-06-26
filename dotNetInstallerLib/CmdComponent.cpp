#include "StdAfx.h"
#include "XmlAttribute.h"
#include "CmdComponent.h"
#include "InstallUILevel.h"
#include "InstallerLog.h"
#include "InstallConfiguration.h"
#include "InstallerSession.h"

CmdComponent::CmdComponent()
	: ProcessComponent(component_type_cmd),
	  execution_method(DVLib::CemCreateProcess)
{
}

void CmdComponent::Exec()
{
	std::wstring l_command;
	
	switch(InstallerSession::Instance->sequence)
	{
	case SequenceInstall:
		l_command = InstallUILevelSetting::Instance->GetCommand(
			command, command_basic, command_silent);
		break;
	case SequenceUninstall:
		l_command = InstallUILevelSetting::Instance->GetCommand(
			uninstall_command, uninstall_command_basic, uninstall_command_silent);
		break;
	default:
		THROW_EX(L"Unsupported install sequence: " << InstallerSession::Instance->sequence << L".");
	}
	
	std::wstring additional_cmd = GetAdditionalCmd();
	if (! additional_cmd.empty())
    {
		l_command.append(L" ");
		l_command.append(additional_cmd);
    }

	l_command = InstallerSession::Instance->ExpandUserVariables(l_command);

	LOG(L"Executing: " << l_command);

	ProcessComponent::ExecCmd(l_command, execution_method, disable_wow64_fs_redirection, hide_window);
};

void CmdComponent::Load(TiXmlElement * node)
{
	command = node->Attribute("command");
    command_silent = node->Attribute("command_silent");
	command_basic = node->Attribute("command_basic");	
	uninstall_command = node->Attribute("uninstall_command");
    uninstall_command_silent = node->Attribute("uninstall_command_silent");
	uninstall_command_basic = node->Attribute("uninstall_command_basic");	
	returncodes_success = node->Attribute("returncodes_success");
	returncodes_reboot = node->Attribute("returncodes_reboot");
	hide_window = XmlAttribute(node->Attribute("hide_window")).GetBoolValue(false);
    disable_wow64_fs_redirection = XmlAttribute(node->Attribute("disable_wow64_fs_redirection")).GetBoolValue(false);
	execution_method = DVLib::wstring2cem(XmlAttribute(node->Attribute("execution_method")).GetValue());
	Component::Load(node);
}

void CmdComponent::Wait(DWORD tt)
{
	ProcessComponent::Wait(tt);

	DWORD exitcode = ProcessComponent::GetProcessExitCode();
	
	LOG(L"Component '" << id << "' return code " << exitcode 
		<< DVLib::FormatMessage(L" (0x%x).", exitcode));

	// check for reboot
	if (! returncodes_reboot.empty() && IsReturnCode(exitcode, returncodes_reboot))
	{
		LOG(L"Component '" << id << "' return code " << exitcode 
			<< DVLib::FormatMessage(L" (0x%x)", exitcode)
			<< L", defined as reboot required in '" << returncodes_reboot << L"'.");
		return;
	}

	// check for explicit success, where defined
	if (returncodes_success.empty())
	{
		CHECK_BOOL(ERROR_SUCCESS == exitcode,
			L"Error executing '" << id << "' (" << GetDisplayName() << L"): " << exitcode <<
			DVLib::FormatMessage(L" (0x%x)", exitcode));
	}
	else
	{
		CHECK_BOOL(IsReturnCode(exitcode, returncodes_success),
			L"Error executing component '" << id << "' (" << GetDisplayName() << L"), return code "
			<< exitcode << DVLib::FormatMessage(L" (0x%x)", exitcode)
			<< L" is not in '" << returncodes_success << L"'");

		LOG(L"Component '" << id << "' (" << GetDisplayName() << L") return code " << exitcode 
			<< DVLib::FormatMessage(L" (0x%x)", exitcode)
			<< L", defined as success in '" << returncodes_success << L"'.");
	}
}

bool CmdComponent::IsReturnCode(DWORD return_code, const std::wstring& possible_values)
{
	std::vector<std::wstring> return_codes_vector = DVLib::split(possible_values, L",");
	for each(std::wstring return_code_s in return_codes_vector)
	{
		if (return_code_s.empty())
			continue;

		BOOL negative_test = false;

		if (return_code_s[0] == L'!')
		{
			negative_test = true;
			return_code_s = return_code_s.substr(1, return_code_s.length() - 1);
		}

		if (return_code_s == L"none")
		{
			return false;
		}
		else if (return_code_s == L"all")
		{
			return true;
		}
		else
		{
			// Convert return code string to unsigned long (dec and hex numbers supported by setting radix to 0)
			DWORD return_code_l = DVLib::wstring2ulong(return_code_s, 0);

			if (!negative_test && (return_code_l == return_code))
			{
				return true;
			}

			if (negative_test && (return_code_l != return_code))
			{
				return true;
			}
		}
	}

	return false;
}

bool CmdComponent::IsReturnCodeReboot(DWORD return_code) const
{
	if (IsReturnCode(return_code, returncodes_reboot))
		return true;

	return false;
}

bool CmdComponent::IsRebootRequired() const
{
	return Component::IsRebootRequired() || IsReturnCodeReboot(
		ProcessComponent::GetProcessExitCode());
}
