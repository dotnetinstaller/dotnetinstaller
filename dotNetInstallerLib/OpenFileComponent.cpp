#include "StdAfx.h"
#include "OpenFileComponent.h"

OpenFileComponent::OpenFileComponent()
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

