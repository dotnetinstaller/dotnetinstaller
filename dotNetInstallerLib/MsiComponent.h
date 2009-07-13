#pragma once
#include "ProcessComponent.h"

class MsiComponent : public ProcessComponent
{
public:
    MsiComponent();
public:
	std::wstring package;
	std::wstring cmdparameters; // es. "/qn REBOOT=ReallySuppress"
    std::wstring cmdparameters_silent;
	std::wstring cmdparameters_basic;
	void Exec();
	void Load(TiXmlElement * node);
};

