#pragma once

class Component;

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
	CString installation_completed;
	CString reboot_required;
	CString installing_component_wait;
	//Link properties
	CString dialog_otherinfo_caption;
	CString dialog_otherinfo_link;

	//Complete command (executed when all components are installed correctly), can be any executable, document or web page valid for ShellExecute API. Usually is a readme file, a web page or a startup file. If empty no command is executed. (OPTIONAL)
	CString complete_command;
	// Daniel Doubrovkine - 2008-09-28: added complete command on silent install
	CString complete_command_silent;
	//If true auto close the dialog (display installation_completed message and execute the complete_command) if all the components are already installed. (REQUIRED)
	bool auto_close_if_installed;
    // If false, don't display installed components
    bool dialog_show_installed;
    // If false, don't display required components
    bool dialog_show_required;
	// Daniel Doubrovkine - 2008-12-30: allow user to continue on error
	bool allow_continue_on_error;
	/* Matthias Jentsch - 2006-03-06: added filter for minimum operating system version */
	CString os_filter_greater;
	/* Matthias Jentsch - 2006-03-06: added filter for maximum operating system version */
	CString os_filter_smaller;
	/* Matthias Jentsch - 2006-03-06: message if the current operating system does not match the operating system filter */
	CString os_filter_not_match_message;

	/* Jason Biegel - 2008-04-23: added filter for processor architecture */
	CString processor_architecture_filter;
	/* Jason Biegel - 2008-04-23: added message for not matching the processor architecture filter */
	CString processor_architecture_filter_not_match_message;

    /* Daniel Doubrovkine - 2008-06-06: added message and caption to show during CAB extraction */
    CString cab_dialog_message;
    CString cab_dialog_caption;
    CString cab_cancelled_message;
    CString cab_path;
    bool cab_path_autodelete;

    /* Daniel Doubrovkine - 2008-06-24: added auto-enabled log */
    bool log_enabled;
    CString log_file;

	void ExecuteCompleteCode() const;
    CString ValidatePath(LPCTSTR p_Path);

    // components
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

