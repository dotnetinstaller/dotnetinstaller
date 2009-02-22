#pragma once
#include "ProcessComponent.h"

class MsiComponent : public ProcessComponent
{
public:
    MsiComponent();
public:
	CString package;
	CString cmdparameters; // es. "/qn REBOOT=ReallySuppress"
    CString cmdparameters_silent;
	bool Exec();
};

