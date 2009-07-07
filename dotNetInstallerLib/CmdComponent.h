#pragma once
#include "ProcessComponent.h"

class cmd_component : public ProcessComponent
{
public:
    cmd_component();
public:
	std::wstring command;
    std::wstring command_silent;
	std::wstring command_basic;
	void Exec();
};
