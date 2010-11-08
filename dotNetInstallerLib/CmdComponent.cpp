#include "StdAfx.h"
#include "XmlAttribute.h"
#include "CmdComponent.h"
#include "InstallUILevel.h"
#include "InstallerLog.h"
#include "InstallConfiguration.h"
#include "InstallerSession.h"

CmdComponent::CmdComponent()
	: ProcessComponent(component_type_cmd)
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
	DVLib::RunCmd(l_command, & m_process_info);
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
	Component::Load(node);
}

void CmdComponent::Wait(DWORD tt)
{
	ProcessComponent::Wait(tt);

	DWORD exitcode = ProcessComponent::GetProcessExitCode();
	
	// check for reboot
	if (! returncodes_reboot.empty() && IsReturnCode(exitcode, returncodes_reboot))
	{
		LOG(L"Component '" << id << "' return code '" << exitcode 
			<< L", defined as reboot required in '" << returncodes_reboot << L".");
		return;
	}

	// check for explicit success, where defined
	if (returncodes_success.empty())
	{
		CHECK_BOOL(ERROR_SUCCESS == exitcode,
			L"Error executing '" << id << "' (" << GetDisplayName() << L"): " << DVLib::FormatMessage(L"0x%x", exitcode));
	}
	else
	{
		CHECK_BOOL(IsReturnCode(exitcode, returncodes_success),
			L"Error executing component '" << id << "' (" << GetDisplayName() << L"), return code is not in '" << returncodes_success 
			<< L"': " << DVLib::FormatMessage(L"0x%x", exitcode));

		LOG(L"Component '" << id << "' (" << GetDisplayName() << L") return code " << exitcode 
			<< L", defined as success in '" << returncodes_success << L"'.");
	}
}

bool CmdComponent::IsReturnCode(DWORD return_code, const std::wstring& possible_values)
{
	std::wstring return_code_s = DVLib::towstring(return_code);
	std::vector<std::wstring> return_codes_vector = DVLib::split(possible_values, L",");
	for each(const std::wstring& return_code in return_codes_vector)
	{
		if (return_code.empty())
			continue;
		
		if (return_code[0] == L'!')
		{
			std::wstring return_code_value = return_code.substr(1, return_code.length() - 1);
			return return_code_value != return_code_s;
		}
		else if (return_code == L"none")
		{
			return false;
		}
		else if (return_code == L"all")
		{
			return true;
		}
		else if (return_code == return_code_s)
		{
			return true;
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
