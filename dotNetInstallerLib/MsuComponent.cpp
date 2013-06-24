#include "StdAfx.h"
#include "XmlAttribute.h"
#include "MsuComponent.h"
#include "InstallUILevel.h"
#include "InstallerLog.h"
#include "InstallConfiguration.h"
#include "InstallerSession.h"
#include "Wow64NativeFS.h"

MsuComponent::MsuComponent()
	: ProcessComponent(component_type_msu)
{

}

void MsuComponent::Exec()
{
	std::wstring l_command = L"wusa.exe ";

	switch(InstallerSession::Instance->sequence)
	{
	case SequenceInstall:
		break;
	default:
		THROW_EX(L"Unsupported install sequence: " << InstallerSession::Instance->sequence << L".");
	}

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
	
	std::wstring additional_cmd = GetAdditionalCmd();
	if (! additional_cmd.empty())
    {
		l_command.append(L" ");
		l_command.append(additional_cmd);
    }

	l_command = InstallerSession::Instance->ExpandUserVariables(l_command);

    LOG(L"Executing: " << l_command);

	if (disable_wow64_fs_redirection)
	{
		auto_any<Wow64NativeFS *, close_delete> wow64_native_fs(new Wow64NativeFS());
		DVLib::RunCmd(l_command, & m_process_info);
	}
	else
	{
		DVLib::RunCmd(l_command, & m_process_info);
	}
}

void MsuComponent::Load(TiXmlElement * node)
{
	package = node->Attribute("package");
	cmdparameters = node->Attribute("cmdparameters");
	cmdparameters_silent = node->Attribute("cmdparameters_silent");
	cmdparameters_basic = node->Attribute("cmdparameters_basic");
    disable_wow64_fs_redirection = XmlAttribute(node->Attribute("disable_wow64_fs_redirection")).GetBoolValue(false);
	Component::Load(node);
}

void MsuComponent::Wait(DWORD tt)
{
	ProcessComponent::Wait(tt);

	DWORD exitcode = ProcessComponent::GetProcessExitCode();

	LOG(L"Component '" << id << "' return code " << exitcode 
		<< DVLib::FormatMessage(L" (0x%x).", exitcode));

	// a non-zero error code represents failure
	CHECK_BOOL(exitcode == ERROR_SUCCESS || exitcode == ERROR_SUCCESS_REBOOT_REQUIRED,
		L"Error executing '" << id << "' (" << GetDisplayName() << L"): " 
		<< exitcode << DVLib::FormatMessage(L" (0x%x)", exitcode));
}

bool MsuComponent::IsRebootRequired() const
{
	return Component::IsRebootRequired() || 
		(GetProcessExitCode() == ERROR_SUCCESS_REBOOT_REQUIRED);
}
