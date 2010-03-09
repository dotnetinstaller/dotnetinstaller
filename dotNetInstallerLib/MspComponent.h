#pragma once
#include "ProcessComponent.h"

class MspComponent : public ProcessComponent
{
public:
    MspComponent();
public:
	XmlAttribute patch;
	XmlAttribute package;
	XmlAttribute cmdparameters;
    XmlAttribute cmdparameters_silent;
	XmlAttribute cmdparameters_basic;
	XmlAttribute uninstall_patch;
	XmlAttribute uninstall_package;
	XmlAttribute uninstall_cmdparameters;
    XmlAttribute uninstall_cmdparameters_silent;
	XmlAttribute uninstall_cmdparameters_basic;
	XmlAttribute reinstall;
	XmlAttribute reinstallmode;
	std::wstring GetCommandLine() const;
	void Exec();
	void Wait(DWORD tt = 1000);
	void Load(TiXmlElement * node);
	bool IsRebootRequired() const;
};

typedef shared_any<MspComponent *, close_delete> MspComponentPtr;
