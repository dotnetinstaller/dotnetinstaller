#pragma once
#include "Component.h"

class ProcessComponent : public Component
{
public:
    ProcessComponent(component_type t);
public:
	PROCESS_INFORMATION m_process_info;
	bool IsExecuting() const;
	DWORD GetProcessExitCode() const;
	void Wait(DWORD tt = 1000);
	int GetExitCode() const;
};

