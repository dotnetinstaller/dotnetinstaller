#pragma once
#include "Component.h"

class OpenFileComponent : public Component
{
public:
    OpenFileComponent();
public:
	CString file; //file to open. Can be a web link or a standard file
	bool Exec();
	DWORD GetExitCode();
	bool IsExecuting();
};

