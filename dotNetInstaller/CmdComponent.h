#pragma once
#include "ProcessComponent.h"

class cmd_component : public ProcessComponent
{
public:
    cmd_component();
public:
	CString command;
    CString command_silent;
	bool Exec();
};
