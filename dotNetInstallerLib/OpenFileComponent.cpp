#include "StdAfx.h"
#include "OpenFileComponent.h"

OpenFileComponent::OpenFileComponent()
{
}

bool OpenFileComponent::Exec()
{
	return DVLib::ShellExecuteDefault(file);
}

DWORD OpenFileComponent::GetExitCode()
{
	return ERROR_SUCCESS;
}

bool OpenFileComponent::IsExecuting()
{
	return false;
}

