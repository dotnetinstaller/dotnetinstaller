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

void MsiComponent::Exec()
{
	std::wstring l_command = TEXT("msiexec /I ");
	l_command.append(L"\"");
	l_command += DVLib::DirectoryCombine(DVLib::GetCurrentDirectoryW(), package);
	l_command.append(L"\"");

	switch(InstallUILevelSetting::Instance->GetUILevel())
	{
	case InstallUILevelSilent:
		if (! cmdparameters_silent.empty()) 
		{
			l_command.append(L" ");
			l_command.append(cmdparameters_silent);
		}
		else if (! cmdparameters_basic.empty()) 
		{
			l_command.append(L" ");
			l_command.append(cmdparameters_basic);
		}
		break;
	case InstallUILevelBasic:
		if (! cmdparameters_basic.empty()) 
		{
			l_command.append(L" ");
			l_command.append(cmdparameters_basic);
		}
		else if (! cmdparameters_silent.empty()) 
		{
			l_command.append(L" ");
			l_command.append(cmdparameters_silent);
		}
		break;
	default:
		if (! cmdparameters.empty())
		{
			l_command.append(L" ");
			l_command.append(cmdparameters);
		}
		break;
	}
	
	std::map<std::wstring, std::wstring>::iterator cmdline = InstallerSession::Instance->AdditionalCmdLineArgs.find(description);
    if (cmdline != InstallerSession::Instance->AdditionalCmdLineArgs.end())
    {
		l_command += TEXT(" ");
		l_command += cmdline->second.c_str();
		LOG(L"-- Additional component arguments: " << cmdline->second);
    }

    LOG(L"Executing: " << l_command);
	DVLib::DetachCmd(l_command, &m_process_info);
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
