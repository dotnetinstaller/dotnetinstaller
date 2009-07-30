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
	std::wstring command = TEXT("msiexec /I ");
	command.append(L"\"");
	command += (DVLib::isguid(package) ? package : DVLib::DirectoryCombine(DVLib::GetCurrentDirectoryW(), package));
	command.append(L"\"");

	switch(InstallUILevelSetting::Instance->GetUILevel())
	{
	case InstallUILevelSilent:
		if (! cmdparameters_silent.empty()) 
		{
			command.append(L" ");
			command.append(cmdparameters_silent);
		}
		else if (! cmdparameters_basic.empty()) 
		{
			command.append(L" ");
			command.append(cmdparameters_basic);
		}
		break;
	case InstallUILevelBasic:
		if (! cmdparameters_basic.empty()) 
		{
			command.append(L" ");
			command.append(cmdparameters_basic);
		}
		else if (! cmdparameters_silent.empty()) 
		{
			command.append(L" ");
			command.append(cmdparameters_silent);
		}
		break;
	default:
		if (! cmdparameters.empty())
		{
			command.append(L" ");
			command.append(cmdparameters);
		}
		break;
	}
	
	std::map<std::wstring, std::wstring>::iterator cmdline = InstallerSession::Instance->AdditionalCmdLineArgs.find(description);
    if (cmdline != InstallerSession::Instance->AdditionalCmdLineArgs.end())
    {
		command += TEXT(" ");
		command += cmdline->second.c_str();
		LOG(L"-- Additional component arguments: " << cmdline->second);
    }

	return command;
}

void MsiComponent::Exec()
{
	std::wstring command = GetCommandLine();
    LOG(L"Executing: " << command);
	DVLib::DetachCmd(command, &m_process_info);
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
