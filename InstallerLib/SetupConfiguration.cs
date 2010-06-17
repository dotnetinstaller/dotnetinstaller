using System;
using System.ComponentModel;
using System.ComponentModel.Design;
using System.Xml;
using System.Collections.Generic;
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
        }

        #region Attributes

        private DefaultButton m_dialog_default_button = DefaultButton.cancel;
        [Description("Default button.")]
        [Category("Main Dialog")]
        public DefaultButton dialog_default_button
        {
            get { return m_dialog_default_button; }
            set { m_dialog_default_button = value; }
        }

        private Rectangle m_dialog_position;
        [Description("Position of the main dialog. (OPTIONAL)")]
        [Category("Main Dialog Layout")]
        public Rectangle dialog_position
        {
            get { return m_dialog_position; }
            set { m_dialog_position = value; }
        }

        private Rectangle m_dialog_components_list_position;
        [Description("Position of the components list within the main dialog. (OPTIONAL)")]
        [Category("Main Dialog Layout")]
        public Rectangle dialog_components_list_position
        {
            get { return m_dialog_components_list_position; }
            set { m_dialog_components_list_position = value; }
        }

        private string m_dialog_caption;
        [Description("Main dialog title. (REQUIRED)")]
        [Category("Main Dialog")]
        public string dialog_caption
        {
            get { return m_dialog_caption; }
            set { m_dialog_caption = value; }
        }

        private string m_dialog_message;
        [Description("Main message of the main dialog during install. (REQUIRED)")]
        [Category("Main Dialog")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string dialog_message
        {
            get { return m_dialog_message; }
            set { m_dialog_message = value; }
        }

        private string m_dialog_message_uninstall;
        [Description("Main message of the main dialog during uninstall. (REQUIRED)")]
        [Category("Main Dialog")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string dialog_message_uninstall
        {
            get { return m_dialog_message_uninstall; }
            set { m_dialog_message_uninstall = value; }
        }

        private Rectangle m_dialog_message_position;
        [Description("Position of the main dialog message. (OPTIONAL)")]
        [Category("Main Dialog Layout")]
        public Rectangle dialog_message_position
        {
            get { return m_dialog_message_position; }
            set { m_dialog_message_position = value; }
        }

        private string m_dialog_bitmap;
        [Description("Bitmap file used in the left panel of the main dialog. If this file doesn't exist or this attribute is empty the application load the bitmap from the .exe resource. Can contains path constant (see Help->Path Constant). (OPTIONAL)")]
        [Category("Main Dialog")]
        public string dialog_bitmap
        {
            get { return m_dialog_bitmap; }
            set { m_dialog_bitmap = value; }
        }

        private Rectangle m_dialog_bitmap_position;
        [Description("Position of the main dialog bitmap. (OPTIONAL)")]
        [Category("Main Dialog Layout")]
        public Rectangle dialog_bitmap_position
        {
            get { return m_dialog_bitmap_position; }
            set { m_dialog_bitmap_position = value; }
        }

        private string m_skip_caption;
        [Description("Caption of the Skip button. (REQUIRED)")]
        [Category("Main Dialog")]
        public string skip_caption
        {
            get { return m_skip_caption; }
            set { m_skip_caption = value; }
        }

        private string m_install_caption;
        [Description("Caption of the Install button. (REQUIRED)")]
        [Category("Main Dialog")]
        public string install_caption
        {
            get { return m_install_caption; }
            set { m_install_caption = value; }
        }

        private string m_uninstall_caption;
        [Description("Caption of the Uninstall button. (REQUIRED)")]
        [Category("Main Dialog")]
        public string uninstall_caption
        {
            get { return m_uninstall_caption; }
            set { m_uninstall_caption = value; }
        }

        private string m_cancel_caption;
        [Description("Caption of the Cancel button. (REQUIRED)")]
        [Category("Main Dialog")]
        public string cancel_caption
        {
            get { return m_cancel_caption; }
            set { m_cancel_caption = value; }
        }

        private string m_status_installed;
        [Description("The string used for indicating an installed component. (OPTIONAL)")]
        [Category("Components")]
        public string status_installed
        {
            get { return m_status_installed; }
            set { m_status_installed = value; }
        }

        private string m_status_notinstalled;
        [Description("The string used for indicating a not installed component. (OPTIONAL)")]
        [Category("Components")]
        public string status_notinstalled
        {
            get { return m_status_notinstalled; }
            set { m_status_notinstalled = value; }
        }

        private string m_failed_exec_command_continue;
        [Description("The message to display when a component failed to install. The user is then asked whether installation can continue using this message. May contain one '%s' replaced by the description of the component. (OPTIONAL)")]
        [Category("Messages")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string failed_exec_command_continue
        {
            get { return m_failed_exec_command_continue; }
            set { m_failed_exec_command_continue = value; }
        }

        private string m_installation_none;
        [Description("No pre-requisite components required message. (REQUIRED)")]
        [Category("Messages")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string installation_none
        {
            get { return m_installation_none; }
            set { m_installation_none = value; }
        }

        private string m_uninstallation_none;
        [Description("Nothing to uninstall message.")]
        [Category("Messages")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string uninstallation_none
        {
            get { return m_uninstallation_none; }
            set { m_uninstallation_none = value; }
        }

        private string m_installation_completed;
        [Description("Installation completed message. (REQUIRED)")]
        [Category("Messages")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string installation_completed
        {
            get { return m_installation_completed; }
            set { m_installation_completed = value; }
        }

        private string m_uninstallation_completed;
        [Description("Uninstallation completed message.")]
        [Category("Messages")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string uninstallation_completed
        {
            get { return m_uninstallation_completed; }
            set { m_uninstallation_completed = value; }
        }

        private string m_installing_component_wait;
        [Description("The message used when installing a component. Must contain one '%s' string where the application put the description of the component. (REQUIRED)")]
        [Category("Components")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string installing_component_wait
        {
            get { return m_installing_component_wait; }
            set { m_installing_component_wait = value; }
        }

        private string m_uninstalling_component_wait;
        [Description("The message used when uninstalling a component. Must contain one '%s' string where the application put the description of the component.")]
        [Category("Components")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string uninstalling_component_wait
        {
            get { return m_uninstalling_component_wait; }
            set { m_uninstalling_component_wait = value; }
        }

        private string m_reboot_required;
        [Description("The message used when a component signaled the installer that it requires a reboot. (REQUIRED)")]
        [Category("Messages")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string reboot_required
        {
            get { return m_reboot_required; }
            set { m_reboot_required = value; }
        }

        private bool m_must_reboot_required = false;
        [Description("Global setting for reboot behavior. When true, installation won't continue after any component required a reboot. (REQUIRED)")]
        [Category("Components")]
        public bool must_reboot_required
        {
            get { return m_must_reboot_required; }
            set { m_must_reboot_required = value; }
        }

        private string m_dialog_otherinfo_caption;
        [Description("Caption of the link at the bottom of the main dialog that open the link specified in the dialog_otherinfo_link attribute. If empty the link is hidden. (OPTIONAL)")]
        [Category("Main Dialog")]
        public string dialog_otherinfo_caption
        {
            get { return m_dialog_otherinfo_caption; }
            set { m_dialog_otherinfo_caption = value; }
        }

        private string m_dialog_otherinfo_link;
        [Description("Command to execute when the user click on the link at the bottom of the main installation dialog. Can be any valid command that can be used with ShellExecute API. Must be defined the dialog_otherinfo_caption attribute. Can contains path constant (see Help->Path Constant). (OPTIONAL)")]
        [Category("Main Dialog")]
        public string dialog_otherinfo_link
        {
            get { return m_dialog_otherinfo_link; }
            set { m_dialog_otherinfo_link = value; }
        }

        private Rectangle m_dialog_otherinfo_link_position;
        [Description("Position of the link at the bottom of the main dialog that open the link specified in the dialog_otherinfo_link attribute. (OPTIONAL)")]
        [Category("Main Dialog Layout")]
        public Rectangle dialog_otherinfo_link_position
        {
            get { return m_dialog_otherinfo_link_position; }
            set { m_dialog_otherinfo_link_position = value; }
        }

        private bool m_dialog_show_installed = true;
        [Description("If true, show installed components during install. Installed components are greyed out and automatically de-selected.")]
        [Category("Main Dialog")]
        public bool dialog_show_installed
        {
            get { return m_dialog_show_installed; }
            set { m_dialog_show_installed = value; }
        }

        private bool m_dialog_show_uninstalled = true;
        [Description("If true, show uninstalled components during uninstall. Uninstalled components are greyed out and automatically de-selected.")]
        [Category("Main Dialog")]
        public bool dialog_show_uninstalled
        {
            get { return m_dialog_show_uninstalled; }
            set { m_dialog_show_uninstalled = value; }
        }

        private bool m_dialog_show_required = true;
        [Description("If true, show required components. Required components are greyed out and automatically selected when not installed.")]
        [Category("Main Dialog")]
        public bool dialog_show_required
        {
            get { return m_dialog_show_required; }
            set { m_dialog_show_required = value; }
        }

        private bool m_wait_for_complete_command = true;
        [Description("Wait for the complete_command to finish. Set to false to detach the complete command.")]
        [Category("Runtime")]
        public bool wait_for_complete_command
        {
            get { return m_wait_for_complete_command; }
            set { m_wait_for_complete_command = value; }
        }

        private string m_complete_command;
        [Description("Complete command (executed when all components are installed correctly), can be any executable, document or web page valid for ShellExecute API. Usually is a readme file, a web page or a startup file. If empty no command is executed. (OPTIONAL)")]
        [Category("Runtime")]
        public string complete_command
        {
            get { return m_complete_command; }
            set { m_complete_command = value; }
        }

        private string m_complete_command_silent;
        [Description("Silent complete command (executed when all components are installed correctly on a silent install), can be any executable, document or web page valid for ShellExecute API. Usually is a readme file, a web page or a startup file. If empty no command is executed. (OPTIONAL)")]
        [Category("Runtime")]
        public string complete_command_silent
        {
            get { return m_complete_command_silent; }
            set { m_complete_command_silent = value; }
        }

        private string m_complete_command_basic;
        [Description("Basic UI complete command (executed when all components are installed correctly on a basic UI install), can be any executable, document or web page valid for ShellExecute API. Usually is a readme file, a web page or a startup file. If empty no command is executed. (OPTIONAL)")]
        [Category("Runtime")]
        public string complete_command_basic
        {
            get { return m_complete_command_basic; }
            set { m_complete_command_basic = value; }
        }

        private bool m_auto_close_if_installed = true;
        [Description("If true auto close the dialog (display installation_completed message and execute the complete_command) if all the components are already installed. (REQUIRED)")]
        [Category("Runtime")]
        public bool auto_close_if_installed
        {
            get { return m_auto_close_if_installed; }
            set { m_auto_close_if_installed = value; }
        }

        private bool m_auto_close_on_error = false;
        [Description("If true auto close the dialog when a component fails to install and the user chooses not to continue. If false, the component conditions will be re-evaluated and the updated list of components will be shown. (REQUIRED)")]
        [Category("Runtime")]
        public bool auto_close_on_error
        {
            get { return m_auto_close_on_error; }
            set { m_auto_close_on_error = value; }
        }

        private bool m_reload_on_error = true;
        [Description("Reload the components list on error, re-evaluating installed checks.")]
        [Category("Runtime")]
        public bool reload_on_error
        {
            get { return m_reload_on_error; }
            set { m_reload_on_error = value; }
        }

        // message and caption to show during CAB extraction
        private string m_cab_dialog_message;
        [Description("CAB dialog message, this dialog shows when extracting an embedded CAB file")]
        [Category("Self-Extracting CAB")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string cab_dialog_message
        {
            get { return m_cab_dialog_message; }
            set { m_cab_dialog_message = value; }
        }

        private string m_cab_cancelled_message;
        [Description("CAB cancelled message, this error shows if extraction operation has been aborted")]
        [Category("Self-Extracting CAB")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string cab_cancelled_message
        {
            get { return m_cab_cancelled_message; }
            set { m_cab_cancelled_message = value; }
        }

        private string m_cab_dialog_caption;
        [Description("CAB dialog caption, this dialog shows when extracting an embedded CAB file")]
        [Category("Self-Extracting CAB")]
        public string cab_dialog_caption
        {
            get { return m_cab_dialog_caption; }
            set { m_cab_dialog_caption = value; }
        }

        // path to use during CAB extraction
        private string m_cab_path;
        [Description("CAB path used when extracting an embedded CAB file")]
        [DefaultValue("#TEMPPATH/#GUID")]
        [Category("Self-Extracting CAB")]
        public string cab_path
        {
            get { return m_cab_path; }
            set { m_cab_path = value; }
        }

        private bool m_cab_path_autodelete = true;
        [Description("Auto-Delete CAB path and all its subfolders upon installer completion")]
        [Category("Self-Extracting CAB")]
        public bool cab_path_autodelete
        {
            get { return m_cab_path_autodelete; }
            set { m_cab_path_autodelete = value; }
        }

        private Rectangle m_dialog_osinfo_position;
        [Description("Position of the main dialog osinfo. (OPTIONAL)")]
        [Category("Main Dialog Layout")]
        public Rectangle dialog_osinfo_position
        {
            get { return m_dialog_osinfo_position; }
            set { m_dialog_osinfo_position = value; }
        }

        private Rectangle m_dialog_install_button_position;
        [Description("Position of the main dialog Install button. (OPTIONAL)")]
        [Category("Main Dialog Layout")]
        public Rectangle dialog_install_button_position
        {
            get { return m_dialog_install_button_position; }
            set { m_dialog_install_button_position = value; }
        }

        private Rectangle m_dialog_cancel_button_position;
        [Description("Position of the main dialog Cancel button. (OPTIONAL)")]
        [Category("Main Dialog Layout")]
        public Rectangle dialog_cancel_button_position
        {
            get { return m_dialog_cancel_button_position; }
            set { m_dialog_cancel_button_position = value; }
        }

        private Rectangle m_dialog_skip_button_position;
        [Description("Position of the main dialog Skip button. (OPTIONAL)")]
        [Category("Main Dialog Layout")]
        public Rectangle dialog_skip_button_position
        {
            get { return m_dialog_skip_button_position; }
            set { m_dialog_skip_button_position = value; }
        }

        private bool m_auto_start = false;
        [Description("If true auto start the installation of this setup configuration.")]
        [Category("Runtime")]
        public bool auto_start
        {
            get { return m_auto_start; }
            set { m_auto_start = value; }
        }

        private bool m_auto_continue_on_reboot = false;
        [Description("If true auto start the installation of this setup configuration after a required reboot.")]
        [Category("Runtime")]
        public bool auto_continue_on_reboot
        {
            get { return m_auto_continue_on_reboot; }
            set { m_auto_continue_on_reboot = value; }
        }

        private string m_reboot_cmd;
        [Description("Additional command line options to include in the command line after a required reboot.")]
        [Category("Runtime")]
        public string reboot_cmd
        {
            get { return m_reboot_cmd; }
            set { m_reboot_cmd = value; }
        }

        private bool m_show_progress_dialog = true;
        [Description("Show progress dialogs.")]
        [Category("Runtime")]
        public bool show_progress_dialog
        {
            get { return m_show_progress_dialog; }
            set { m_show_progress_dialog = value; }
        }

        private bool m_show_cab_dialog = true;
        [Description("Show CAB extraction dialogs.")]
        [Category("Self-Extracting CAB")]
        public bool show_cab_dialog
        {
            get { return m_show_cab_dialog; }
            set { m_show_cab_dialog = value; }
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
            if (! ReadAttributeValue(e, "uninstallation_completed", ref m_uninstallation_completed))
                m_uninstallation_completed = m_installation_completed;
            ReadAttributeValue(e, "installation_none", ref m_installation_none);
            ReadAttributeValue(e, "uninstallation_none", ref m_uninstallation_none);
            ReadAttributeValue(e, "installing_component_wait", ref m_installing_component_wait);
            if (! ReadAttributeValue(e, "uninstalling_component_wait", ref m_uninstalling_component_wait))
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
            base.OnXmlReadTag(e);
        }
    }
}
