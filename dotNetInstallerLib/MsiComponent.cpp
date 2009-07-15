#include "StdAfx.h"
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

	switch(CurrentInstallUILevel.GetUILevel())
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
	
	std::map<std::wstring, std::wstring>::iterator cmdline = InstallerSession::s_AdditionalCmdLineArgs.find(description);
    if (cmdline != InstallerSession::s_AdditionalCmdLineArgs.end())
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
	package = InstallerSession::MakePath(node->AttributeW("package"));
	cmdparameters = InstallerSession::MakePath(node->AttributeW("cmdparameters"));
	cmdparameters_silent = InstallerSession::MakePath(node->AttributeW("cmdparameters_silent"));
	cmdparameters_basic = InstallerSession::MakePath(node->AttributeW("cmdparameters_basic"));
	Component::Load(node);
	LOG(L"Loaded 'msi' component '" << package << L"'");
}
