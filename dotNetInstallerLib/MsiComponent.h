#pragma once
#include "ProcessComponent.h"

class MsiComponent : public ProcessComponent
{
public:
    MsiComponent();
public:
	XmlAttribute package;
	XmlAttribute cmdparameters; // es. "/qn REBOOT=ReallySuppress"
    XmlAttribute cmdparameters_silent;
	XmlAttribute cmdparameters_basic;
	XmlAttribute uninstall_package;
	XmlAttribute uninstall_cmdparameters;
    XmlAttribute uninstall_cmdparameters_silent;
	XmlAttribute uninstall_cmdparameters_basic;
	std::wstring GetCommandLine() const;
	// wow64 fs redirection
	bool disable_wow64_fs_redirection; 
	void Exec();
	void Wait(DWORD tt = INFINITE);
	void Load(TiXmlElement * node);
	bool IsRebootRequired() const;
};

typedef shared_any<MsiComponent *, close_delete> MsiComponentPtr;
