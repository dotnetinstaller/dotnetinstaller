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

bool OpenFileComponent::IsExecuting() const
{
	return false;
}

void OpenFileComponent::Load(TiXmlElement * node)
{
	file = InstallerSession::MakePath(DVLib::UTF8string2wstring(node->Attribute("file")));
	Component::Load(node);
	LOG(L"Loaded 'openfile' component '" << file << L"'");
}
