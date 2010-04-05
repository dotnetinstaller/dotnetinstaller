#pragma once
#include "ProcessComponent.h"
#include "ResponseFile.h"

class ExeComponent : public ProcessComponent
{
public:
    ExeComponent();
public:
	// response file
	XmlAttribute responsefile_format;
	// install
	XmlAttribute executable;
    XmlAttribute executable_silent;
	XmlAttribute executable_basic;
	XmlAttribute responsefile_source;
	XmlAttribute responsefile_target;
	XmlAttribute exeparameters;
	XmlAttribute exeparameters_basic;
	XmlAttribute exeparameters_silent;
	// uninstall
	XmlAttribute uninstall_executable;
    XmlAttribute uninstall_executable_silent;
	XmlAttribute uninstall_executable_basic;
	XmlAttribute uninstall_responsefile_source;
	XmlAttribute uninstall_responsefile_target;
	XmlAttribute uninstall_exeparameters;
	XmlAttribute uninstall_exeparameters_basic;
	XmlAttribute uninstall_exeparameters_silent;
	// return codes
	XmlAttribute returncodes_success;
	XmlAttribute returncodes_reboot;
	void Exec();
	void Load(TiXmlElement * node);
	void Wait(DWORD tt = 1000);
	bool IsRebootRequired() const;
private:
	// functions that indicate whether a return code falls into a certain category
	virtual bool IsReturnCodeReboot(DWORD exitcode) const;
	static bool IsReturnCode(DWORD return_code, const std::wstring& possible_values);
};

typedef shared_any<ExeComponent *, close_delete> ExeComponentPtr;
