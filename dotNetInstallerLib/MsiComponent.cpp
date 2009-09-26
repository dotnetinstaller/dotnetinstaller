#include "StdAfx.h"
#include "XmlAttribute.h"
#include "MsiComponent.h"
#include "InstallUILevel.h"
#include "InstallerLog.h"
#include "InstallConfiguration.h"
#include "InstallerSession.h"

MsiComponent::MsiComponent()
	: ProcessComponent(msi)
{

}

std::wstring MsiComponent::GetCommandLine() const
{
	std::wstring l_command = L"msiexec /I ";
	l_command.append(L"\"");
	l_command += (DVLib::isguid(package) ? package : DVLib::DirectoryCombine(DVLib::GetCurrentDirectoryW(), package));
	l_command.append(L"\"");

	std::wstring l_cmdparameters = InstallUILevelSetting::Instance->GetCommand(
		cmdparameters, cmdparameters_basic, cmdparameters_silent);
	
	if (! l_cmdparameters.empty())
	{
		LOG(L"-- Additional command-line parameters: " << l_cmdparameters);
		l_command.append(L" ");
		l_command.append(l_cmdparameters);
	}
	
	std::map<std::wstring, std::wstring>::iterator cmdline = InstallerSession::Instance->AdditionalCmdLineArgs.find(description);
    if (cmdline != InstallerSession::Instance->AdditionalCmdLineArgs.end())
    {
		LOG(L"-- Additional component arguments: " << cmdline->second);
		l_command.append(L" ");
		l_command.append(cmdline->second);
    }

	return l_command;
}

void MsiComponent::Exec()
{
	std::wstring command = GetCommandLine();
    LOG(L"Executing: " << command);
	DVLib::RunCmd(command, &m_process_info);
}

void MsiComponent::Load(TiXmlElement * node)
{
	package = XML_ATTRIBUTE(node->Attribute("package"));
	cmdparameters = XML_ATTRIBUTE(node->Attribute("cmdparameters"));
	cmdparameters_silent = XML_ATTRIBUTE(node->Attribute("cmdparameters_silent"));
	cmdparameters_basic = XML_ATTRIBUTE(node->Attribute("cmdparameters_basic"));
	Component::Load(node);
	LOG(L"Loaded 'msi' component '" << package << L"'");
}

void MsiComponent::Wait(DWORD tt)
{
	ProcessComponent::Wait(tt);

	DWORD exitcode = ProcessComponent::GetProcessExitCode();

	// a non-zero error code represents failure
	CHECK_BOOL(exitcode == ERROR_SUCCESS || exitcode == ERROR_SUCCESS_REBOOT_REQUIRED,
		L"Error executing '" << description << "': " << DVLib::FormatMessage(L"0x%x", exitcode));
}

bool MsiComponent::IsRebootRequired() const
{
	return ProcessComponent::IsRebootRequired() 
		|| (GetProcessExitCode() == ERROR_SUCCESS_REBOOT_REQUIRED);
}
