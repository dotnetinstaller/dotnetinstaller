#include "StdAfx.h"
#include "MsuComponent.h"
#include "InstallUILevel.h"
#include "InstallerLog.h"
#include "InstallConfiguration.h"
#include "InstallerSession.h"

MsuComponent::MsuComponent()
	: ProcessComponent(msu)
{

}

void MsuComponent::Exec()
{
	std::wstring l_command = TEXT("wusa.exe ");
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

void MsuComponent::Load(TiXmlElement * node)
{
	package = InstallerSession::MakePath(DVLib::UTF8string2wstring(node->Attribute("package")));
	cmdparameters = InstallerSession::MakePath(DVLib::UTF8string2wstring(node->Attribute("cmdparameters")));
	cmdparameters_silent = InstallerSession::MakePath(DVLib::UTF8string2wstring(node->Attribute("cmdparameters_silent")));
	cmdparameters_basic = InstallerSession::MakePath(DVLib::UTF8string2wstring(node->Attribute("cmdparameters_basic")));
	Component::Load(node);
	LOG(L"Loaded 'msu' component '" << package << L"'");
}
