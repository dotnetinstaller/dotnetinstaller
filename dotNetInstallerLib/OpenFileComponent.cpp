#include "StdAfx.h"
#include "XmlAttribute.h"
#include "OpenFileComponent.h"
#include "InstallConfiguration.h"
#include "InstallerLog.h"
#include "InstallerSession.h"
#include "Wow64NativeFS.h"

OpenFileComponent::OpenFileComponent()
	: Component(component_type_openfile)
	, m_rc(0)
{
}

void OpenFileComponent::Exec()
{
	std::wstring l_file = file;
	l_file = InstallerSession::Instance->ExpandUserVariables(l_file);
	LOG(L"Opening: " << l_file);
	if (disable_wow64_fs_redirection)
	{
		auto_any<Wow64NativeFS *, close_delete> wow64_native_fs(new Wow64NativeFS());
		DVLib::ShellCmd(l_file, & m_rc); 
	}
	else
	{
		DVLib::ShellCmd(l_file, & m_rc);
	}
}

bool OpenFileComponent::IsExecuting() const
{
	return false;
}

void OpenFileComponent::Load(TiXmlElement * node)
{
	file = node->Attribute("file");
    disable_wow64_fs_redirection = XmlAttribute(node->Attribute("disable_wow64_fs_redirection")).GetBoolValue(false);
	Component::Load(node);
}

int OpenFileComponent::GetExitCode() const
{
	return m_rc;
}
