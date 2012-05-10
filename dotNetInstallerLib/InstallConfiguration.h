#pragma once

#include "WidgetPosition.h"
#include "Configuration.h"
#include "Components.h"
#include "Control.h"
#include "InstallSequence.h"

class InstallConfiguration : public Configuration
{
public:
	// dialog options
	XmlAttribute dialog_default_button;
	XmlAttribute dialog_caption;
	XmlAttribute dialog_message;
	XmlAttribute dialog_message_uninstall;
	XmlAttribute dialog_bitmap;
	XmlAttribute skip_caption;
	XmlAttribute install_caption;
	XmlAttribute uninstall_caption;
	XmlAttribute cancel_caption;
	XmlAttribute status_installed;
	XmlAttribute status_notinstalled;
	XmlAttribute failed_exec_command_continue;
	XmlAttribute installation_none;
	XmlAttribute uninstallation_none;
	XmlAttribute installation_completed;
	XmlAttribute uninstallation_completed;
    bool must_reboot_required;
	XmlAttribute reboot_required;
	XmlAttribute installing_component_wait;
	XmlAttribute uninstalling_component_wait;
	// link properties
	XmlAttribute dialog_otherinfo_caption;
	XmlAttribute dialog_otherinfo_link;
	// complete command (executed when all components are installed correctly)
	XmlAttribute complete_command;
	// complete command on silent install
	XmlAttribute complete_command_silent;
	// complete command on a basic UI install
	XmlAttribute complete_command_basic;
	// wow64 fs redirection
	bool disable_wow64_fs_redirection; 
	// wait for the complete command to finish
	bool wait_for_complete_command;

	// hide the window while waiting for the complete command to finish
	bool hide_when_complete_command;

	// if true auto close the dialog (display installation_completed or installation_none message 
	// and execute the complete_command) if all the components are already installed
	bool auto_close_if_installed;
    // if true, auto-close on error when the user chooses not to continue
    bool auto_close_on_error;
	// if true, reload on error
	bool reload_on_error;
    // if false, don't display installed components during install
    bool dialog_show_installed;
    // if false, don't display uninstalled components during uninstall
    bool dialog_show_uninstalled;
    // ff false, don't display required components
    bool dialog_show_required;
    // message and caption to show during CAB extraction
    XmlAttribute cab_dialog_message;
    XmlAttribute cab_dialog_caption;
    XmlAttribute cab_cancelled_message;
    XmlAttribute cab_path;
    bool cab_path_autodelete;
	// auto-start installation
    bool auto_start;
	// auto-start installation on a reboot
	bool auto_continue_on_reboot;
	// additional reboot command
	XmlAttribute reboot_cmd;
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
	std::vector<ControlPtr> controls;
	// progress options
	bool show_progress_dialog;
	bool show_cab_dialog;
	// administrator required
	bool administrator_required;
	XmlAttribute administrator_required_message;
public:
	InstallConfiguration();
	virtual void Load(TiXmlElement * node);
	// returns components that match current platform and processor architecture
	Components GetSupportedComponents(DVLib::LcidType lcidtype, InstallSequence sequence) const;
	ComponentPtr GetComponentPtr(Component * pc) const;
	std::wstring GetString(int indent = 0) const;
};

typedef shared_any<InstallConfiguration *, close_delete> InstallConfigurationPtr;
