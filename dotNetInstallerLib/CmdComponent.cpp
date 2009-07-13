#include "StdAfx.h"
#include "CmdComponent.h"
#include "InstallUILevel.h"
#include "InstallerLog.h"
#include "InstallConfiguration.h"
#include "InstallerSession.h"

CmdComponent::CmdComponent()
	: ProcessComponent(cmd)
{

}

void CmdComponent::Exec()
{
	std::wstring l_command = command;
	switch(CurrentInstallUILevel.GetUILevel())
	{
	case InstallUILevelSilent:
		if (! command_silent.empty()) l_command = command_silent;
		else if (! command_basic.empty()) l_command = command_basic;
		break;
	case InstallUILevelBasic:
		if (! command_basic.empty()) l_command = command_basic;
		else if (! command_silent.empty()) l_command = command_silent;
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
	DVLib::DetachCmd(l_command, & m_process_info);
};

void CmdComponent::Load(TiXmlElement * node)
{
	command = InstallerSession::MakePath(node->AttributeW("command"));
    command_silent = InstallerSession::MakePath(node->AttributeW("command_silent"));
	command_basic = InstallerSession::MakePath(node->AttributeW("command_basic"));	
	Component::Load(node);
	LOG(L"Loaded 'cmd' component '" << description << L"'");
}
