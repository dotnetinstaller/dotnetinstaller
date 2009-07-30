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
	std::wstring GetCommandLine() const;
	void Exec();
	void Wait(DWORD tt = 1000);
	void Load(TiXmlElement * node);
	bool IsRebootRequired() const;
};

typedef shared_any<MsiComponent *, close_delete> MsiComponentPtr;
