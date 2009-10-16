#pragma once

#include "WidgetPosition.h"
#include "Configuration.h"
#include "Components.h"

class InstallConfiguration : public Configuration
{
public:
	// dialog options
	std::wstring dialog_caption;
	std::wstring dialog_message;
	std::wstring dialog_bitmap;
	std::wstring skip_caption;
	std::wstring install_caption;
	std::wstring cancel_caption;
	std::wstring status_installed;
	std::wstring status_notinstalled;
	std::wstring failed_exec_command_continue;
	std::wstring installation_none;
	std::wstring installation_completed;
    bool must_reboot_required;
	std::wstring reboot_required;
	std::wstring installing_component_wait;
	// link properties
	std::wstring dialog_otherinfo_caption;
	std::wstring dialog_otherinfo_link;
	// complete command (executed when all components are installed correctly)
	std::wstring complete_command;
	// complete command on silent install
	std::wstring complete_command_silent;
	// complete command on a basic UI install
	std::wstring complete_command_basic;
	// wait for the complete command to finish
	bool wait_for_complete_command;
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
    // message and caption to show during CAB extraction
    std::wstring cab_dialog_message;
    std::wstring cab_dialog_caption;
    std::wstring cab_cancelled_message;
    std::wstring cab_path;
    bool cab_path_autodelete;
	// auto-start installation
    bool auto_start;
	// auto-start installation on a reboot
	bool auto_continue_on_reboot;
	// additional reboot command
	std::wstring reboot_cmd;
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
	Components components;
public:
	InstallConfiguration();
	virtual void Load(TiXmlElement * node);
	// returns components that match current platform and processor architecture
	Components GetSupportedComponents(DVLib::LcidType lcidtype) const;
	std::wstring GetString(int indent = 0) const;
};

typedef shared_any<InstallConfiguration *, close_delete> InstallConfigurationPtr;
