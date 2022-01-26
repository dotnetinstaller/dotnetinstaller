#pragma once

#include "DownloadDialog.h"
#include "EmbedFile.h"
#include "EmbedFolder.h"
#include "InstalledCheck.h"
#include <tinyxml2.h>

enum component_type
{
	component_type_undefined = 0, 
	component_type_cmd, // shell command
	component_type_msi, // windows installer setup
	component_type_msu, // windows update
	component_type_msp, // windows installer patch
	component_type_openfile, // ShellExecute call to open a file
	component_type_exe, // executable component
};

class Component
{
public:
    Component(component_type t);
    virtual ~Component();
public:
	// component display name
	XmlAttribute display_name;
	// component type: cmd, msi, openfile
	component_type type;
	// component id
	XmlAttribute id;
	// component uninstall display name
	XmlAttribute uninstall_display_name;
	// component status when installed
	XmlAttribute status_installed;
	// component status when not installed
	XmlAttribute status_notinstalled;
	// operating system filter
	XmlAttribute os_filter;
	// operating system filter range
	DVLib::OperatingSystem os_filter_min;
	DVLib::OperatingSystem os_filter_max;
	// operating system product type filter
	XmlAttribute os_type_filter;
	// filtro che indica il filtro per lingua del sistema operativo (es. Italy = 1040, English - United Kingdom = 2057, English - United States = 1033)
	XmlAttribute os_filter_lcid;
	// testo da visualizzare a fine installazione (se vuoto non visualizza niente)
	XmlAttribute installcompletemessage;
	// successful uninstall message
	XmlAttribute uninstallcompletemessage;
	// true per forzare il reboot al termine dell'installazione altrimenti false
	bool mustreboot;
    // message for a reboot after this component
    XmlAttribute reboot_required;
    // true to force a reboot when required
    bool must_reboot_required;
    // message to display on error
    XmlAttribute failed_exec_command_continue;
    // allow to continue setup on error
    bool allow_continue_on_error;
	// default value of continue on error
	bool default_continue_on_error;
	// filter for processor architecture
	XmlAttribute processor_architecture_filter;
    // cancelled by user
    bool cancelled;
    // true if component is required
    bool required_install;
	bool required_uninstall;
	// true if component is selected
    bool selected_install;
    bool selected_uninstall;
    // manages the verification of whether the component is installed or not
	std::vector<InstalledCheckPtr> installedchecks;
    // the nested download dialog within a Component
	DownloadDialogPtr downloaddialog;
	// handle to main window of installator for use in calls to ShellExecute and similar
	HWND main_window;
	// embedded files
	std::vector< EmbedFilePtr > embedfiles;
	// embedded folders
	std::vector< EmbedFolderPtr > embedfolders;
	// supports install
	bool supports_install;
	// supports uninstall
	bool supports_uninstall;
	// dialog options
	bool show_progress_dialog;
	bool show_cab_dialog;
    bool hide_component_if_installed;
	// virtual functions specific for the type of component
	virtual void Exec() = 0;
	virtual void Wait(DWORD tt = INFINITE);
	virtual bool IsRebootRequired() const;
	virtual bool IsExecuting() const = 0;
	virtual bool IsInstalled() const;
	// load a component from an xml node
	virtual void Load(tinyxml2::XMLElement * node);
	// returns true if this component is supported on this operating system/lcid
	virtual bool IsSupported(LCID lcid) const;
	virtual bool IsRequired() const;
	virtual int GetExitCode() const = 0;
	virtual std::wstring GetString(int indent = 0) const;
	std::wstring GetAdditionalCmd() const;
	std::wstring GetDisplayName() const;
	// component state
	bool checked;
	bool disabled;
	bool installed;
	std::wstring description;
};

typedef shared_any<Component *, close_delete> ComponentPtr;
