#include "StdAfx.h"
#include "XmlAttribute.h"
#include "ExeComponent.h"
#include "InstallUILevel.h"
#include "InstallerLog.h"
#include "InstallConfiguration.h"
#include "InstallerSession.h"
#include "ResponseFileIni.h"
#include "ResponseFileText.h"
#include "ResponseFileNone.h"

ExeComponent::ExeComponent()
	: ProcessComponent(component_type_exe)
{

}

void ExeComponent::Exec()
{
	std::wstring l_command;
	std::wstring l_exeparameters;
	std::wstring l_responsefile_source;
	std::wstring l_responsefile_target;
	std::wstring l_responsefile_processed;
	
	// make executable executable
	switch(InstallerSession::Instance->sequence)
	{
	case SequenceInstall:
		l_command = InstallUILevelSetting::Instance->GetCommand(
			executable, executable_basic, executable_silent);
		l_exeparameters = InstallUILevelSetting::Instance->GetCommand(
			exeparameters, exeparameters_basic, exeparameters_silent);
		l_responsefile_source = responsefile_source;
		l_responsefile_target = responsefile_target;
		break;
	case SequenceUninstall:
		l_command = InstallUILevelSetting::Instance->GetCommand(
			uninstall_executable, uninstall_executable_basic, uninstall_executable_silent);
		l_exeparameters = InstallUILevelSetting::Instance->GetCommand(
			uninstall_exeparameters, uninstall_exeparameters_basic, uninstall_exeparameters_silent);
		l_responsefile_source = uninstall_responsefile_source;
		l_responsefile_target = uninstall_responsefile_target;
		break;
	default:
		THROW_EX(L"Unsupported install sequence: " << InstallerSession::Instance->sequence << L".");
	}

	LOG(L"-- Executable: " << l_command);

	// install_dir
	std::wstring installdir = InstallerSession::Instance->ExpandUserVariables(install_directory.GetValue());
	if (InstallerSession::Instance->sequence == SequenceInstall && ! installdir.empty())
	{
		bool installdir_exists = DVLib::DirectoryExists(installdir);
		if (! installdir_exists)
		{
			LOG(L"-- Creating install_directory directory '" << installdir << L"'");
			DVLib::DirectoryCreate(installdir);
		}
		else
		{
			LOG(L"-- Directory '" << installdir << L"' exists");
		}
	}

	// response file
	if (! l_responsefile_source.empty() && ! l_responsefile_target.empty()) 
	{
		LOG(L"-- Response file source: " << l_responsefile_source << L" (" << responsefile_format << L")");
		LOG(L"-- Response file target: " << l_responsefile_target);
		ResponseFilePtr r;
		ResponseFileFormat l_responsefile_format = ResponseFile::string2responsefileformat(responsefile_format);
		switch(l_responsefile_format)
		{
		case ResponseFileFormatNone:
			reset(r, new ResponseFileNone(l_responsefile_source, l_responsefile_target));
			break;
		case ResponseFileFormatIni:
			reset(r, new ResponseFileIni(l_responsefile_source, l_responsefile_target));
			break;
		case ResponseFileFormatText:
			reset(r, new ResponseFileText(l_responsefile_source, l_responsefile_target));
			break;
		default:
			THROW_EX(L"Unsupported response file format: " << responsefile_format); 
		}

		r->Exec();
	}

	if (! l_exeparameters.empty())
	{
		LOG(L"-- Additional command-line parameters: " << l_exeparameters);
		l_command.append(L" ");
		l_command.append(l_exeparameters);
	}

	std::wstring additional_cmd = GetAdditionalCmd();
	if (! additional_cmd.empty())
    {
		l_command.append(L" ");
		l_command.append(additional_cmd);
    }

	l_command = InstallerSession::Instance->ExpandUserVariables(l_command);

	LOG(L"Executing: " << l_command);

	CHECK_BOOL(! l_command.empty(), L"Component command is empty");

	DVLib::RunCmd(l_command, & m_process_info);
};

void ExeComponent::Load(TiXmlElement * node)
{
	executable = node->Attribute("executable");
    executable_silent = node->Attribute("executable_silent");
	executable_basic = node->Attribute("executable_basic");	
	install_directory = node->Attribute("install_directory");
	responsefile_source = node->Attribute("responsefile_source");
	responsefile_target = node->Attribute("responsefile_target");
	responsefile_format = node->Attribute("responsefile_format");
	exeparameters = node->Attribute("exeparameters");
	exeparameters_silent = node->Attribute("exeparameters_silent");
	exeparameters_basic = node->Attribute("exeparameters_basic");
	uninstall_responsefile_source = node->Attribute("uninstall_responsefile_source");
	uninstall_responsefile_target = node->Attribute("uninstall_responsefile_target");
	uninstall_executable = node->Attribute("uninstall_executable");
    uninstall_executable_silent = node->Attribute("uninstall_executable_silent");
	uninstall_executable_basic = node->Attribute("uninstall_executable_basic");	
	uninstall_exeparameters = node->Attribute("uninstall_exeparameters");
	uninstall_exeparameters_silent = node->Attribute("uninstall_exeparameters_silent");
	uninstall_exeparameters_basic = node->Attribute("uninstall_exeparameters_basic");
	returncodes_success = node->Attribute("returncodes_success");
	returncodes_reboot = node->Attribute("returncodes_reboot");
	Component::Load(node);
}

void ExeComponent::Wait(DWORD tt)
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
			L"Error executing '" << id << "' (" << GetDisplayName() << L"): " << DVLib::FormatMessage(L"0x%x", exitcode));
	}
}

bool ExeComponent::IsReturnCode(DWORD return_code, const std::wstring& possible_values)
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

bool ExeComponent::IsReturnCodeReboot(DWORD return_code) const
{
	if (IsReturnCode(return_code, returncodes_reboot))
		return true;

	return false;
}

bool ExeComponent::IsRebootRequired() const
{
	return IsReturnCodeReboot(
		ProcessComponent::GetProcessExitCode());
}
