#include "StdAfx.h"
#include "OpenFileComponent.h"
#include "InstallConfiguration.h"
#include "InstallerLog.h"
#include "InstallerSession.h"

OpenFileComponent::OpenFileComponent()
	: Component(openfile)
{
}

void OpenFileComponent::Exec()
{
	DVLib::ShellCmd(file);
}

DWORD OpenFileComponent::GetExitCode() const
{
	return ERROR_SUCCESS;
}

bool OpenFileComponent::IsExecuting() const
{
	return false;
}

void OpenFileComponent::Load(TiXmlElement * node)
{
	file = InstallerSession::MakePath(node->AttributeW("file"));
	Component::Load(node);
	LOG(L"Loaded 'openfile' component '" << file << L"'");
}
