using System.ComponentModel;
using System.ComponentModel.Design;
using System.Drawing;
using System.Drawing.Design;

namespace InstallerLib
{
    /// <summary>
    /// An install configuration.
    /// </summary>
    [XmlChild(typeof(EmbedFile))]
    [XmlChild(typeof(EmbedFolder))]
    [XmlChild(typeof(Component))]
    [XmlChild(typeof(Control))]
    public class SetupConfiguration : Configuration
    {
        private string m_application_name;

        public enum DefaultButton
        {
            cancel,
            install,
            skip
        }

        public SetupConfiguration()
            : this("APPLICATION_NAME")
        {

        }

        public SetupConfiguration(string p_ApplicationName)
            : base("install")
        {
            m_dialog_bitmap = "#APPPATH\\banner.bmp";
            m_application_name = p_ApplicationName;

            Template.Template_setupconfiguration tpl = Template.CurrentTemplate.setupConfiguration(p_ApplicationName);

            m_cancel_caption = tpl.cancel_caption;
            m_dialog_caption = tpl.dialog_caption;
            m_dialog_message = tpl.dialog_message;
            m_failed_exec_command_continue = tpl.failed_exec_command_continue;
            m_skip_caption = tpl.skip_caption;
            m_install_caption = tpl.install_caption;
            m_uninstall_caption = tpl.uninstall_caption;
            m_installation_completed = tpl.installation_completed;
            m_uninstallation_completed = tpl.uninstallation_completed;
            m_installation_none = tpl.installation_none;
            m_uninstallation_none = tpl.uninstallation_none;
            m_installing_component_wait = tpl.installing_component_wait;
            m_uninstalling_component_wait = tpl.uninstalling_component_wait;
            m_reboot_required = tpl.reboot_required;
            m_status_installed = tpl.status_installed;
            m_status_notinstalled = tpl.status_notinstalled;

            // message and caption to show during CAB extraction
            m_cab_dialog_message = tpl.cab_dialog_message;
            m_cab_cancelled_message = tpl.cab_cancelled_message;
            m_cab_dialog_caption = tpl.cab_dialog_caption;
            m_cab_path = tpl.cab_path;
            m_cab_path_autodelete = tpl.cab_path_autodelete;

            m_administrator_required_message = tpl.administrator_required_message;
        }

        #region Attributes

        private DefaultButton m_dialog_default_button = DefaultButton.cancel;
        [Description("Default button.")]
        [Category("Main Dialog")]
        [Required]
        public DefaultButton dialog_default_button
        {
            get { return m_dialog_default_button; }
            set { m_dialog_default_button = value; }
        }

        private Rectangle m_dialog_position;
        [Description("Position of the main dialog. By default the dialog appears in the center of the screen.")]
        [Category("Main Dialog Layout")]
        public Rectangle dialog_position
        {
            get { return m_dialog_position; }
            set { m_dialog_position = value; }
        }

        private Rectangle m_dialog_components_list_position;
        [Description("Position of the components list within the main dialog.")]
        [Category("Main Dialog Layout")]
        public Rectangle dialog_components_list_position
        {
            get { return m_dialog_components_list_position; }
            set { m_dialog_components_list_position = value; }
        }

        private string m_dialog_caption;
        [Description("Main dialog title.")]
        [Category("Main Dialog")]
        public string dialog_caption
        {
            get { return m_dialog_caption; }
            set { m_dialog_caption = value; }
        }

        private string m_dialog_message;
        [Description("Main message of the main dialog during install.")]
        [Category("Main Dialog")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string dialog_message
        {
            get { return m_dialog_message; }
            set { m_dialog_message = value; }
        }

        private string m_dialog_message_uninstall;
        [Description("Main message of the main dialog during uninstall.")]
        [Category("Main Dialog")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string dialog_message_uninstall
        {
            get { return m_dialog_message_uninstall; }
            set { m_dialog_message_uninstall = value; }
        }

        private Rectangle m_dialog_message_position;
        [Description("Position of the main dialog message.")]
        [Category("Main Dialog Layout")]
        public Rectangle dialog_message_position
        {
            get { return m_dialog_message_position; }
            set { m_dialog_message_position = value; }
        }

        private string m_dialog_bitmap;
        [Description("Bitmap file used in the left panel of the main dialog.")]
        [Category("Main Dialog")]
        public string dialog_bitmap
        {
            get { return m_dialog_bitmap; }
            set { m_dialog_bitmap = value; }
        }

        private Rectangle m_dialog_bitmap_position;
        [Description("Position of the main dialog bitmap.")]
        [Category("Main Dialog Layout")]
        public Rectangle dialog_bitmap_position
        {
            get { return m_dialog_bitmap_position; }
            set { m_dialog_bitmap_position = value; }
        }

        private string m_skip_caption;
        [Description("Caption of the Skip button.")]
        [Category("Main Dialog")]
        public string skip_caption
        {
            get { return m_skip_caption; }
            set { m_skip_caption = value; }
        }

        private string m_install_caption;
        [Description("Caption of the Install button.")]
        [Category("Main Dialog")]
        public string install_caption
        {
            get { return m_install_caption; }
            set { m_install_caption = value; }
        }

        private string m_uninstall_caption;
        [Description("Caption of the Uninstall button.")]
        [Category("Main Dialog")]
        public string uninstall_caption
        {
            get { return m_uninstall_caption; }
            set { m_uninstall_caption = value; }
        }

        private string m_cancel_caption;
        [Description("Caption of the Cancel button.")]
        [Category("Main Dialog")]
        public string cancel_caption
        {
            get { return m_cancel_caption; }
            set { m_cancel_caption = value; }
        }

        private string m_status_installed;
        [Description("String used for indicating an installed component.")]
        [Category("Components")]
        public string status_installed
        {
            get { return m_status_installed; }
            set { m_status_installed = value; }
        }

        private string m_status_notinstalled;
        [Description("String used for indicating a component that has not been installed.")]
        [Category("Components")]
        public string status_notinstalled
        {
            get { return m_status_notinstalled; }
            set { m_status_notinstalled = value; }
        }

        private string m_failed_exec_command_continue;
        [Description("Message to display when a component failed to install. The user is then asked whether installation can continue using this message. May contain one '%s' replaced by the description of the component.")]
        [Category("Messages")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string failed_exec_command_continue
        {
            get { return m_failed_exec_command_continue; }
            set { m_failed_exec_command_continue = value; }
        }

        private string m_installation_none;
        [Description("Message to display when there're no components to install.")]
        [Category("Messages")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string installation_none
        {
            get { return m_installation_none; }
            set { m_installation_none = value; }
        }

        private string m_uninstallation_none;
        [Description("Message to display when there're no components to uninstall.")]
        [Category("Messages")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string uninstallation_none
        {
            get { return m_uninstallation_none; }
            set { m_uninstallation_none = value; }
        }

        private string m_installation_completed;
        [Description("Message to display when installation is complete.")]
        [Category("Messages")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string installation_completed
        {
            get { return m_installation_completed; }
            set { m_installation_completed = value; }
        }

        private string m_uninstallation_completed;
        [Description("Message to display when uninstallation is complete.")]
        [Category("Messages")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string uninstallation_completed
        {
            get { return m_uninstallation_completed; }
            set { m_uninstallation_completed = value; }
        }

        private string m_installing_component_wait;
        [Description("Message displayed when installing a component. Must contain one '%s' which will be replaced by the component description.")]
        [Category("Components")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string installing_component_wait
        {
            get { return m_installing_component_wait; }
            set { m_installing_component_wait = value; }
        }

        private string m_uninstalling_component_wait;
        [Description("Message displayed when uninstalling a component. Must contain one '%s' which will be replaced by the component description.")]
        [Category("Components")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string uninstalling_component_wait
        {
            get { return m_uninstalling_component_wait; }
            set { m_uninstalling_component_wait = value; }
        }

        private string m_reboot_required;
        [Description("Message used when a component signaled the installer that it requires a reboot.")]
        [Category("Messages")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string reboot_required
        {
            get { return m_reboot_required; }
            set { m_reboot_required = value; }
        }

        private bool m_must_reboot_required = false;
        [Description("Global setting for reboot behavior. When 'true', installation won't continue after any component required a reboot.")]
        [Category("Components")]
        [Required]
        public bool must_reboot_required
        {
            get { return m_must_reboot_required; }
            set { m_must_reboot_required = value; }
        }

        private string m_dialog_otherinfo_caption;
        [Description("Caption of the link at the bottom of the main dialog that open the link specified in the 'dialog_otherinfo_link' attribute. The link is hidden if this value is blank.")]
        [Category("Main Dialog")]
        public string dialog_otherinfo_caption
        {
            get { return m_dialog_otherinfo_caption; }
            set { m_dialog_otherinfo_caption = value; }
        }

        private string m_dialog_otherinfo_link;
        [Description("Command to execute when the user click on the link at the bottom of the main installation dialog. Can be any valid command that can be used with ShellExecute API. A value for 'dialog_otherinfo_caption' is also required when this value is specified.")]
        [Category("Main Dialog")]
        public string dialog_otherinfo_link
        {
            get { return m_dialog_otherinfo_link; }
            set { m_dialog_otherinfo_link = value; }
        }

        private Rectangle m_dialog_otherinfo_link_position;
        [Description("Position of the link at the bottom of the main dialog that open the link specified in the value of 'dialog_otherinfo_link'.")]
        [Category("Main Dialog Layout")]
        public Rectangle dialog_otherinfo_link_position
        {
            get { return m_dialog_otherinfo_link_position; }
            set { m_dialog_otherinfo_link_position = value; }
        }

        private bool m_dialog_show_installed = true;
        [Description("Show installed components during install. Installed components are greyed out and automatically de-selected.")]
        [Category("Main Dialog")]
        [Required]
        public bool dialog_show_installed
        {
            get { return m_dialog_show_installed; }
            set { m_dialog_show_installed = value; }
        }

        private bool m_dialog_show_uninstalled = true;
        [Description("Show uninstalled components during uninstall. Uninstalled components are greyed out and automatically de-selected.")]
        [Category("Main Dialog")]
        [Required]
        public bool dialog_show_uninstalled
        {
            get { return m_dialog_show_uninstalled; }
            set { m_dialog_show_uninstalled = value; }
        }

        private bool m_dialog_show_required = true;
        [Description("Show required components. Required components are greyed out and automatically selected when not installed.")]
        [Category("Main Dialog")]
        [Required]
        public bool dialog_show_required
        {
            get { return m_dialog_show_required; }
            set { m_dialog_show_required = value; }
        }

        private bool m_wait_for_complete_command = true;
        [Description("Wait for the 'complete_command' to finish. Set to 'false' to detach the complete command and terminate the bootstrapper.")]
        [Category("Runtime")]
        [Required]
        public bool wait_for_complete_command
        {
            get { return m_wait_for_complete_command; }
            set { m_wait_for_complete_command = value; }
        }

        private string m_complete_command;
        [Description("Command executed when all components are installed correctly. Can be any executable, document or web page valid for ShellExecute API. Usually is a readme file, a web page or a startup file.")]
        [Category("Runtime")]
        public string complete_command
        {
            get { return m_complete_command; }
            set { m_complete_command = value; }
        }

        private string m_complete_command_silent;
        [Description("Command executed when all components are installed correctly during a silent install. Can be any executable, document or web page valid for ShellExecute API. Usually is a readme file, a web page or a startup file.")]
        [Category("Runtime")]
        public string complete_command_silent
        {
            get { return m_complete_command_silent; }
            set { m_complete_command_silent = value; }
        }

        private string m_complete_command_basic;
        [Description("Command executed when all components are installed correctly during a basic UI install. Can be any executable, document or web page valid for ShellExecute API. Usually is a readme file, a web page or a startup file.")]
        [Category("Runtime")]
        public string complete_command_basic
        {
            get { return m_complete_command_basic; }
            set { m_complete_command_basic = value; }
        }

        private bool m_prompt_for_optional_components = false;
        [Description("Prompt for optional components when all required components are installed, instead of switching to uninstall.")]
        [Category("Runtime")]
        [Required]
        public bool prompt_for_optional_components
        {
            get { return m_prompt_for_optional_components; }
            set { m_prompt_for_optional_components = value; }
        }

        private bool m_auto_close_if_installed = true;
        [Description("Auto-close the dialog (display 'installation_completed' message and execute the 'complete_command') if all the components are already installed.")]
        [Category("Runtime")]
        [Required]
        public bool auto_close_if_installed
        {
            get { return m_auto_close_if_installed; }
            set { m_auto_close_if_installed = value; }
        }

        private bool m_auto_close_on_error = false;
        [Description("Auto-close the dialog when a component fails to install and the user chooses not to continue with other components. If 'false' the component conditions will be re-evaluated and the updated list of components will be shown.")]
        [Category("Runtime")]
        [Required]
        public bool auto_close_on_error
        {
            get { return m_auto_close_on_error; }
            set { m_auto_close_on_error = value; }
        }

        private bool m_reload_on_error = true;
        [Description("Reload the components list on error, re-evaluating installed checks.")]
        [Category("Runtime")]
        [Required]
        public bool reload_on_error
        {
            get { return m_reload_on_error; }
            set { m_reload_on_error = value; }
        }

        private string m_cab_dialog_message;
        [Description("CAB dialog message, this dialog shows when extracting an embedded CAB file.")]
        [Category("Self-Extracting CAB")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string cab_dialog_message
        {
            get { return m_cab_dialog_message; }
            set { m_cab_dialog_message = value; }
        }

        private string m_cab_cancelled_message;
        [Description("CAB cancelled message, this error shows if extraction operation has been aborted.")]
        [Category("Self-Extracting CAB")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string cab_cancelled_message
        {
            get { return m_cab_cancelled_message; }
            set { m_cab_cancelled_message = value; }
        }

        private string m_cab_dialog_caption;
        [Description("CAB dialog caption, this dialog shows when extracting an embedded CAB file.")]
        [Category("Self-Extracting CAB")]
        public string cab_dialog_caption
        {
            get { return m_cab_dialog_caption; }
            set { m_cab_dialog_caption = value; }
        }

        // path to use during CAB extraction
        private string m_cab_path;
        [Description("CAB path used when extracting an embedded CAB file.")]
        [DefaultValue("#TEMPPATH/#GUID")]
        [Category("Self-Extracting CAB")]
        public string cab_path
        {
            get { return m_cab_path; }
            set { m_cab_path = value; }
        }

        private bool m_cab_path_autodelete = true;
        [Description("Auto-delete CAB path and all its subfolders upon installer completion.")]
        [Category("Self-Extracting CAB")]
        public bool cab_path_autodelete
        {
            get { return m_cab_path_autodelete; }
            set { m_cab_path_autodelete = value; }
        }

        private Rectangle m_dialog_osinfo_position;
        [Description("Position of the main dialog operating system information.")]
        [Category("Main Dialog Layout")]
        public Rectangle dialog_osinfo_position
        {
            get { return m_dialog_osinfo_position; }
            set { m_dialog_osinfo_position = value; }
        }

        private Rectangle m_dialog_install_button_position;
        [Description("Position of the main dialog 'Install' button.")]
        [Category("Main Dialog Layout")]
        public Rectangle dialog_install_button_position
        {
            get { return m_dialog_install_button_position; }
            set { m_dialog_install_button_position = value; }
        }

        private Rectangle m_dialog_cancel_button_position;
        [Description("Position of the main dialog 'Cancel' button.")]
        [Category("Main Dialog Layout")]
        public Rectangle dialog_cancel_button_position
        {
            get { return m_dialog_cancel_button_position; }
            set { m_dialog_cancel_button_position = value; }
        }

        private Rectangle m_dialog_skip_button_position;
        [Description("Position of the main dialog 'Skip' button.")]
        [Category("Main Dialog Layout")]
        public Rectangle dialog_skip_button_position
        {
            get { return m_dialog_skip_button_position; }
            set { m_dialog_skip_button_position = value; }
        }

        private bool m_auto_start = false;
        [Description("Auto-start the installation of this setup configuration.")]
        [Category("Runtime")]
        [Required]
        public bool auto_start
        {
            get { return m_auto_start; }
            set { m_auto_start = value; }
        }

        private bool m_auto_continue_on_reboot = false;
        [Description("Auto-start the installation of this setup configuration after a required reboot.")]
        [Category("Runtime")]
        [Required]
        public bool auto_continue_on_reboot
        {
            get { return m_auto_continue_on_reboot; }
            set { m_auto_continue_on_reboot = value; }
        }

        private string m_reboot_cmd;
        [Description("Additional command-line options to include in the command after a required reboot.")]
        [Category("Runtime")]
        public string reboot_cmd
        {
            get { return m_reboot_cmd; }
            set { m_reboot_cmd = value; }
        }

        private bool m_show_progress_dialog = true;
        [Description("Show progress dialogs.")]
        [Category("Runtime")]
        [Required]
        public bool show_progress_dialog
        {
            get { return m_show_progress_dialog; }
            set { m_show_progress_dialog = value; }
        }

        private bool m_show_cab_dialog = true;
        [Description("Show CAB extraction dialogs.")]
        [Category("Self-Extracting CAB")]
        [Required]
        public bool show_cab_dialog
        {
            get { return m_show_cab_dialog; }
            set { m_show_cab_dialog = value; }
        }

        private bool m_disable_wow64_fs_redirection = false;
        [Description("Indicates whether to disable wow64 file system redirection on x64 systems. Setting this option to 'true' forces the command to execute in the native x64 environment.")]
        [Category("Runtime")]
        [Required]
        public bool disable_wow64_fs_redirection
        {
            get { return m_disable_wow64_fs_redirection; }
            set { m_disable_wow64_fs_redirection = value; }
        }

        private bool m_administrator_required = false;
        [Description("Indicates whether this installation can only be run by an administrator.")]
        [Category("Runtime")]
        [Required]
        public bool administrator_required
        {
            get { return m_administrator_required; }
            set { m_administrator_required = value; }
        }

        private string m_administrator_required_message;
        [Description("Message to display when installation is being run without administration permissions.")]
        [Category("Messages")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string administrator_required_message
        {
            get { return m_administrator_required_message; }
            set { m_administrator_required_message = value; }
        }
        #endregion

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("dialog_caption", m_dialog_caption);
            e.XmlWriter.WriteAttributeString("dialog_message", m_dialog_message);
            e.XmlWriter.WriteAttributeString("dialog_message_uninstall", m_dialog_message_uninstall);
            e.XmlWriter.WriteAttributeString("dialog_bitmap", m_dialog_bitmap);
            e.XmlWriter.WriteAttributeString("skip_caption", m_skip_caption);
            e.XmlWriter.WriteAttributeString("install_caption", m_install_caption);
            e.XmlWriter.WriteAttributeString("uninstall_caption", m_uninstall_caption);
            e.XmlWriter.WriteAttributeString("cancel_caption", m_cancel_caption);
            //e.XmlWriter.WriteAttributeString("reinstallflag_caption",m_reinstallflag_caption);
            e.XmlWriter.WriteAttributeString("status_installed", m_status_installed);
            e.XmlWriter.WriteAttributeString("status_notinstalled", m_status_notinstalled);
            e.XmlWriter.WriteAttributeString("failed_exec_command_continue", m_failed_exec_command_continue);
            e.XmlWriter.WriteAttributeString("installation_completed", m_installation_completed);
            e.XmlWriter.WriteAttributeString("uninstallation_completed", m_uninstallation_completed);
            e.XmlWriter.WriteAttributeString("installation_none", m_installation_none);
            e.XmlWriter.WriteAttributeString("uninstallation_none", m_uninstallation_none);
            // e.XmlWriter.WriteAttributeString("dialog_install_next",m_dialog_install_next);
            // e.XmlWriter.WriteAttributeString("dialog_install_skip",m_dialog_install_skip);
            e.XmlWriter.WriteAttributeString("installing_component_wait", m_installing_component_wait);
            e.XmlWriter.WriteAttributeString("uninstalling_component_wait", m_uninstalling_component_wait);
            e.XmlWriter.WriteAttributeString("reboot_required", m_reboot_required);
            e.XmlWriter.WriteAttributeString("must_reboot_required", m_must_reboot_required.ToString());

            e.XmlWriter.WriteAttributeString("dialog_otherinfo_caption", m_dialog_otherinfo_caption);
            e.XmlWriter.WriteAttributeString("dialog_otherinfo_link", m_dialog_otherinfo_link);

            e.XmlWriter.WriteAttributeString("complete_command", m_complete_command);
            e.XmlWriter.WriteAttributeString("complete_command_silent", m_complete_command_silent);
            e.XmlWriter.WriteAttributeString("complete_command_basic", m_complete_command_basic);
            e.XmlWriter.WriteAttributeString("wait_for_complete_command", m_wait_for_complete_command.ToString());

            e.XmlWriter.WriteAttributeString("prompt_for_optional_components", m_prompt_for_optional_components.ToString());
            e.XmlWriter.WriteAttributeString("auto_close_if_installed", m_auto_close_if_installed.ToString());
            e.XmlWriter.WriteAttributeString("auto_close_on_error", m_auto_close_on_error.ToString());
            e.XmlWriter.WriteAttributeString("reload_on_error", m_reload_on_error.ToString());
            e.XmlWriter.WriteAttributeString("dialog_show_installed", m_dialog_show_installed.ToString());
            e.XmlWriter.WriteAttributeString("dialog_show_uninstalled", m_dialog_show_uninstalled.ToString());
            e.XmlWriter.WriteAttributeString("dialog_show_required", m_dialog_show_required.ToString());

            // message and caption to show during CAB extraction
            e.XmlWriter.WriteAttributeString("cab_dialog_message", m_cab_dialog_message);
            e.XmlWriter.WriteAttributeString("cab_cancelled_message", m_cab_cancelled_message);
            e.XmlWriter.WriteAttributeString("cab_dialog_caption", m_cab_dialog_caption);

            // CAB path
            e.XmlWriter.WriteAttributeString("cab_path", m_cab_path);
            e.XmlWriter.WriteAttributeString("cab_path_autodelete", m_cab_path_autodelete.ToString());

            // dialog, message and button positions
            e.XmlWriter.WriteAttributeString("dialog_default_button", m_dialog_default_button.ToString());
            e.XmlWriter.WriteAttributeString("dialog_position", XmlRectangle.ToString(m_dialog_position));
            e.XmlWriter.WriteAttributeString("dialog_components_list_position", XmlRectangle.ToString(m_dialog_components_list_position));
            e.XmlWriter.WriteAttributeString("dialog_message_position", XmlRectangle.ToString(m_dialog_message_position));
            e.XmlWriter.WriteAttributeString("dialog_bitmap_position", XmlRectangle.ToString(m_dialog_bitmap_position));
            e.XmlWriter.WriteAttributeString("dialog_otherinfo_link_position", XmlRectangle.ToString(m_dialog_otherinfo_link_position));
            e.XmlWriter.WriteAttributeString("dialog_osinfo_position", XmlRectangle.ToString(m_dialog_osinfo_position));
            e.XmlWriter.WriteAttributeString("dialog_install_button_position", XmlRectangle.ToString(m_dialog_install_button_position));
            e.XmlWriter.WriteAttributeString("dialog_cancel_button_position", XmlRectangle.ToString(m_dialog_cancel_button_position));
            e.XmlWriter.WriteAttributeString("dialog_skip_button_position", XmlRectangle.ToString(m_dialog_skip_button_position));
            // auto start
            e.XmlWriter.WriteAttributeString("auto_start", m_auto_start.ToString());
            // auto start on reboot
            e.XmlWriter.WriteAttributeString("auto_continue_on_reboot", m_auto_continue_on_reboot.ToString());
            // additional reboot command
            e.XmlWriter.WriteAttributeString("reboot_cmd", m_reboot_cmd);
            // dialog options
            e.XmlWriter.WriteAttributeString("show_progress_dialog", m_show_progress_dialog.ToString());
            e.XmlWriter.WriteAttributeString("show_cab_dialog", m_show_cab_dialog.ToString());
            e.XmlWriter.WriteAttributeString("disable_wow64_fs_redirection", m_disable_wow64_fs_redirection.ToString());
            // administrator required
            e.XmlWriter.WriteAttributeString("administrator_required", m_administrator_required.ToString());
            e.XmlWriter.WriteAttributeString("administrator_required_message", m_administrator_required_message);
            base.OnXmlWriteTag(e);
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            ReadAttributeValue(e, "cancel_caption", ref m_cancel_caption);
            ReadAttributeValue(e, "dialog_bitmap", ref m_dialog_bitmap);
            ReadAttributeValue(e, "dialog_caption", ref m_dialog_caption);
            ReadAttributeValue(e, "dialog_message", ref m_dialog_message);
            ReadAttributeValue(e, "dialog_message_uninstall", ref m_dialog_message_uninstall);
            ReadAttributeValue(e, "failed_exec_command_continue", ref m_failed_exec_command_continue);
            ReadAttributeValue(e, "skip_caption", ref m_skip_caption);
            ReadAttributeValue(e, "install_caption", ref m_install_caption);
            ReadAttributeValue(e, "uninstall_caption", ref m_uninstall_caption);
            ReadAttributeValue(e, "installation_completed", ref m_installation_completed);
            if (!ReadAttributeValue(e, "uninstallation_completed", ref m_uninstallation_completed))
                m_uninstallation_completed = m_installation_completed;
            ReadAttributeValue(e, "installation_none", ref m_installation_none);
            ReadAttributeValue(e, "uninstallation_none", ref m_uninstallation_none);
            ReadAttributeValue(e, "installing_component_wait", ref m_installing_component_wait);
            if (!ReadAttributeValue(e, "uninstalling_component_wait", ref m_uninstalling_component_wait))
                m_uninstalling_component_wait = m_installing_component_wait;
            ReadAttributeValue(e, "reboot_required", ref m_reboot_required);
            ReadAttributeValue(e, "must_reboot_required", ref m_must_reboot_required);
            ReadAttributeValue(e, "status_installed", ref m_status_installed);
            ReadAttributeValue(e, "status_notinstalled", ref m_status_notinstalled);
            ReadAttributeValue(e, "dialog_otherinfo_caption", ref m_dialog_otherinfo_caption);
            ReadAttributeValue(e, "dialog_otherinfo_link", ref m_dialog_otherinfo_link);
            ReadAttributeValue(e, "complete_command", ref m_complete_command);
            ReadAttributeValue(e, "complete_command_silent", ref m_complete_command_silent);
            ReadAttributeValue(e, "complete_command_basic", ref m_complete_command_basic);
            ReadAttributeValue(e, "wait_for_complete_command", ref m_wait_for_complete_command);
            ReadAttributeValue(e, "prompt_for_optional_components", ref m_prompt_for_optional_components);
            ReadAttributeValue(e, "auto_close_if_installed", ref m_auto_close_if_installed);
            ReadAttributeValue(e, "auto_close_on_error", ref m_auto_close_on_error);
            ReadAttributeValue(e, "reload_on_error", ref m_reload_on_error);
            ReadAttributeValue(e, "dialog_show_installed", ref m_dialog_show_installed);
            ReadAttributeValue(e, "dialog_show_uninstalled", ref m_dialog_show_uninstalled);
            ReadAttributeValue(e, "dialog_show_required", ref m_dialog_show_required);
            // message and caption to show during CAB extraction
            ReadAttributeValue(e, "cab_dialog_message", ref m_cab_dialog_message);
            ReadAttributeValue(e, "cab_cancelled_message", ref m_cab_cancelled_message);
            ReadAttributeValue(e, "cab_dialog_caption", ref m_cab_dialog_caption);
            // CAB path
            ReadAttributeValue(e, "cab_path", ref m_cab_path);
            ReadAttributeValue(e, "cab_path_autodelete", ref m_cab_path_autodelete);
            // dialog, message and button positions
            ReadAttributeValue(e, "dialog_default_button", ref m_dialog_default_button);
            ReadAttributeValue(e, "dialog_position", ref m_dialog_position);
            ReadAttributeValue(e, "dialog_components_list_position", ref m_dialog_components_list_position);
            ReadAttributeValue(e, "dialog_message_position", ref m_dialog_message_position);
            ReadAttributeValue(e, "dialog_bitmap_position", ref m_dialog_bitmap_position);
            ReadAttributeValue(e, "dialog_otherinfo_link_position", ref m_dialog_otherinfo_link_position);
            ReadAttributeValue(e, "dialog_osinfo_position", ref m_dialog_osinfo_position);
            ReadAttributeValue(e, "dialog_install_button_position", ref m_dialog_install_button_position);
            ReadAttributeValue(e, "dialog_cancel_button_position", ref m_dialog_cancel_button_position);
            ReadAttributeValue(e, "dialog_skip_button_position", ref m_dialog_skip_button_position);
            // auto start
            ReadAttributeValue(e, "auto_start", ref m_auto_start);
            // auto start on reboot
            ReadAttributeValue(e, "auto_continue_on_reboot", ref m_auto_continue_on_reboot);
            // additional reboot command
            ReadAttributeValue(e, "reboot_cmd", ref m_reboot_cmd);
            // dialog options
            ReadAttributeValue(e, "show_progress_dialog", ref m_show_progress_dialog);
            ReadAttributeValue(e, "show_cab_dialog", ref m_show_cab_dialog);
            ReadAttributeValue(e, "disable_wow64_fs_redirection", ref m_disable_wow64_fs_redirection);
            // administrator required
            ReadAttributeValue(e, "administrator_required", ref m_administrator_required);
            if (!ReadAttributeValue(e, "administrator_required_message", ref m_administrator_required_message))
            {
                // When upgrading set default message
                Template.Template_setupconfiguration tpl = Template.CurrentTemplate.setupConfiguration(m_application_name);
                m_administrator_required_message = tpl.administrator_required_message;
            }
            base.OnXmlReadTag(e);
        }
    }
}
