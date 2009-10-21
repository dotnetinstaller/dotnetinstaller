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
	std::wstring l_command = InstallUILevelSetting::Instance->GetCommand(
		command, command_basic, command_silent);

	std::map<std::wstring, std::wstring>::iterator cmdline = InstallerSession::Instance->AdditionalCmdLineArgs.find(description);
    if (cmdline != InstallerSession::Instance->AdditionalCmdLineArgs.end())
    {
		l_command += TEXT(" ");
		l_command += cmdline->second.c_str();
		LOG(L"-- Additional component arguments: " << cmdline->second);
    }

	l_command = InstallerSession::Instance->ExpandUserVariables(l_command);

	LOG(L"Executing: " << l_command);
	DVLib::RunCmd(l_command, & m_process_info);
};

void CmdComponent::Load(TiXmlElement * node)
{
	command = XML_ATTRIBUTE(node->Attribute("command"));
    command_silent = XML_ATTRIBUTE(node->Attribute("command_silent"));
	command_basic = XML_ATTRIBUTE(node->Attribute("command_basic"));	
	returncodes_reboot = XML_ATTRIBUTE(node->Attribute("returncodes_reboot"));
	returncodes_failure = XML_ATTRIBUTE(node->Attribute("returncodes_failure"));
	Component::Load(node);
	LOG(L"Loaded 'cmd' component '" << description << L"'");
}

void CmdComponent::Wait(DWORD tt)
{
	ProcessComponent::Wait(tt);

	DWORD exitcode = ProcessComponent::GetProcessExitCode();

	CHECK_BOOL(! IsReturnCodeFailure(exitcode) || IsReturnCodeReboot(exitcode),
		L"Error executing '" << description << "': " << DVLib::FormatMessage(L"0x%x", exitcode));
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
		else if (return_code == return_code_s)
		{
			return true;
		}
	}

	return false;
}

bool CmdComponent::IsReturnCodeFailure(DWORD return_code) const
{
	if (! returncodes_failure.empty())
	{
		return IsReturnCode(return_code, returncodes_failure);
	}
	else
	{
		return (ERROR_SUCCESS != return_code);
	}
}

bool CmdComponent::IsReturnCodeReboot(DWORD return_code) const
{
	if (IsReturnCode(return_code, returncodes_reboot))
		return true;

	return false;
}

bool CmdComponent::IsRebootRequired() const
{
	return IsReturnCodeReboot(
		ProcessComponent::GetProcessExitCode());
}
