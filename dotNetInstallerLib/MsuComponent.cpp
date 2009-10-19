#include "StdAfx.h"
#include "XmlAttribute.h"
#include "MsuComponent.h"
#include "InstallUILevel.h"
#include "InstallerLog.h"
#include "InstallConfiguration.h"
#include "InstallerSession.h"

MsuComponent::MsuComponent()
	: ProcessComponent(component_type_msu)
{

}

void MsuComponent::Exec()
{
	std::wstring l_command = L"wusa.exe ";
	l_command.append(L"\"");
	l_command += DVLib::DirectoryCombine(DVLib::GetCurrentDirectoryW(), package);
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

	l_command = InstallerSession::Instance->ExpandUserVariables(l_command);

    LOG(L"Executing: " << l_command);
	DVLib::RunCmd(l_command, &m_process_info);
}

void MsuComponent::Load(TiXmlElement * node)
{
	package = XML_ATTRIBUTE(node->Attribute("package"));
	cmdparameters = XML_ATTRIBUTE(node->Attribute("cmdparameters"));
	cmdparameters_silent = XML_ATTRIBUTE(node->Attribute("cmdparameters_silent"));
	cmdparameters_basic = XML_ATTRIBUTE(node->Attribute("cmdparameters_basic"));
	Component::Load(node);
	LOG(L"Loaded 'msu' component '" << package << L"'");
}

void MsuComponent::Wait(DWORD tt)
{
	ProcessComponent::Wait(tt);

	CHECK_WIN32_DWORD(ProcessComponent::GetProcessExitCode(),
		L"Error executing '" << description << "'");
}
