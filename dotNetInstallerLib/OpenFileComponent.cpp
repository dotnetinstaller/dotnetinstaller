#include "StdAfx.h"
#include "XmlAttribute.h"
#include "OpenFileComponent.h"
#include "InstallConfiguration.h"
#include "InstallerLog.h"
#include "InstallerSession.h"

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
	DVLib::ShellCmd(l_file, & m_rc);
}

bool OpenFileComponent::IsExecuting() const
{
	return false;
}

void OpenFileComponent::Load(TiXmlElement * node)
{
	file = XML_ATTRIBUTE(node->Attribute("file"));
	Component::Load(node);
}

int OpenFileComponent::GetExitCode() const
{
	return m_rc;
}
