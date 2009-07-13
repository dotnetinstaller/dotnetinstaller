#pragma once
#include "Component.h"

class ProcessComponent : public Component
{
public:
    ProcessComponent(component_type t);
public:
	PROCESS_INFORMATION m_process_info;
	DWORD GetExitCode() const;
	bool IsExecuting() const;
	DWORD Wait() const;
};

