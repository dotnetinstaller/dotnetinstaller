#pragma once
#include "Component.h"

class ProcessComponent : public Component
{
public:
    ProcessComponent();
public:
	//Informations on the executing process
	PROCESS_INFORMATION m_process_info;
	DWORD GetExitCode();
	bool IsExecuting();
	void Init();
};

