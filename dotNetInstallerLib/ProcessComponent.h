#pragma once
#include "Component.h"

class ProcessComponent : public Component
{
public:
    ProcessComponent();
public:
	PROCESS_INFORMATION m_process_info;
	DWORD GetExitCode() const;
	bool IsExecuting() const;
	void Init();
};

