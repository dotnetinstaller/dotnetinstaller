#pragma once
#include "ProcessComponent.h"

class CmdComponent : public ProcessComponent
{
public:
    CmdComponent();
public:
	XmlAttribute command;
    XmlAttribute command_silent;
	XmlAttribute command_basic;
	XmlAttribute uninstall_command;
    XmlAttribute uninstall_command_silent;
	XmlAttribute uninstall_command_basic;
	// working directory
	XmlAttribute working_directory;
	// hide window
	bool hide_window;
	// wow64 fs redirection
	bool disable_wow64_fs_redirection; 
	DVLib::CommandExecutionMethod execution_method;
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

typedef shared_any<CmdComponent *, close_delete> CmdComponentPtr;
