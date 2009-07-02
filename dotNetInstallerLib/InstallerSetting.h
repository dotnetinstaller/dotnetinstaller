#pragma once

class Component;

#include "WidgetPosition.h"

class InstallerSetting
{
public:
    InstallerSetting();
public:
	CString dialog_caption;
	CString dialog_message;
	CString dialog_bitmap;
	CString skip_caption;
	CString install_caption;
	CString cancel_caption;
	CString status_installed;
	CString status_notinstalled;
	CString failed_exec_command_continue;
	CString installation_none;
	CString installation_completed;
    bool must_reboot_required;
	CString reboot_required;
	CString installing_component_wait;
	// link properties
	CString dialog_otherinfo_caption;
	CString dialog_otherinfo_link;
	// complete command (executed when all components are installed correctly)
	CString complete_command;
	// complete command on silent install
	CString complete_command_silent;
	// complete command on a basic UI install
	CString complete_command_basic;
	// if true auto close the dialog (display installation_completed or installation_none message 
	// and execute the complete_command) if all the components are already installed
	bool auto_close_if_installed;
    // if true, auto-close on error when the user chooses not to continue
    bool auto_close_on_error;
    // if false, don't display installed components
    bool dialog_show_installed;
    // ff false, don't display required components
    bool dialog_show_required;
	// allow user to continue on error
	bool allow_continue_on_error;
	// filter for minimum operating system version
	CString os_filter_greater;
	// filter for maximum operating system version
	CString os_filter_smaller;
	// filter for processor architecture
	CString processor_architecture_filter;
    // message and caption to show during CAB extraction
    CString cab_dialog_message;
    CString cab_dialog_caption;
    CString cab_cancelled_message;
    CString cab_path;
    bool cab_path_autodelete;
    // auto-enabled log
    bool log_enabled;
    CString log_file;
    CString ValidatePath(LPCTSTR p_Path);
    // dialog elements position
    WidgetPosition dialog_position;
    WidgetPosition dialog_components_list_position;
    WidgetPosition dialog_message_position;
    WidgetPosition dialog_bitmap_position;
    WidgetPosition dialog_otherinfo_link_position;
    WidgetPosition dialog_osinfo_position;
    WidgetPosition dialog_install_button_position;
    WidgetPosition dialog_cancel_button_position;
    WidgetPosition dialog_skip_button_position;
private:
    // a description-component map
    std::map<std::wstring, Component *> components_map;
    // an ordered list of components
    std::vector<Component *> components;
public:
    // use these functions to add/clear components
    void AddComponent(Component *);
    void ClearComponents();
    bool HasComponent(const std::wstring& description) const { return components_map.find(description) != components_map.end(); }
    std::vector<Component *>& GetComponents() { return components; }
};

