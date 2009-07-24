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
    public class SetupConfiguration : Configuration
    {
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
            m_installation_completed = tpl.installation_completed;
            m_installation_none = tpl.installation_none;
            m_installing_component_wait = tpl.installing_component_wait;
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
        [Description("Main message of the main dialog. (REQUIRED)")]
        [Category("Main Dialog")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string dialog_message
        {
            get { return m_dialog_message; }
            set { m_dialog_message = value; }
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
        [Category("Component")]
        public string status_installed
        {
            get { return m_status_installed; }
            set { m_status_installed = value; }
        }

        private string m_status_notinstalled;
        [Description("The string used for indicating a not installed component. (OPTIONAL)")]
        [Category("Component")]
        public string status_notinstalled
        {
            get { return m_status_notinstalled; }
            set { m_status_notinstalled = value; }
        }

        private string m_failed_exec_command_continue;
        [Description("The message used when a component cannot be installed and ask if the application can continue with others components (Yes/No message). Must contain one '%s' string where the application put the description of the component. (REQUIRED)")]
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

        private string m_installation_completed;
        [Description("Installation completed message. (REQUIRED)")]
        [Category("Messages")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string installation_completed
        {
            get { return m_installation_completed; }
            set { m_installation_completed = value; }
        }

        private string m_installing_component_wait;
        [Description("The message used when installing a component. Must contain one '%s' string where the application put the description of the component. (REQUIRED)")]
        [Category("Component")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string installing_component_wait
        {
            get { return m_installing_component_wait; }
            set { m_installing_component_wait = value; }
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
        [Category("Component")]
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
        [Description("If true, show installed components. Installed components are greyed out and automatically de-selected.")]
        [Category("Main Dialog")]
        public bool dialog_show_installed
        {
            get { return m_dialog_show_installed; }
            set { m_dialog_show_installed = value; }
        }

        private bool m_dialog_show_required = true;
        [Description("If true, show required components. Required components are greyed out and automatically selected when not installed.")]
        [Category("Main Dialog")]
        public bool dialog_show_required
        {
            get { return m_dialog_show_required; }
            set { m_dialog_show_required = value; }
        }

        private string m_complete_command;
        [Description("Complete command (executed when all components are installed correctly), can be any executable, document or web page valid for ShellExecute API. Usually is a readme file, a web page or a startup file. If empty no command is executed. (OPTIONAL)")]
        public string complete_command
        {
            get { return m_complete_command; }
            set { m_complete_command = value; }
        }

        private string m_complete_command_silent;
        [Description("Silent complete command (executed when all components are installed correctly on a silent install), can be any executable, document or web page valid for ShellExecute API. Usually is a readme file, a web page or a startup file. If empty no command is executed. (OPTIONAL)")]
        public string complete_command_silent
        {
            get { return m_complete_command_silent; }
            set { m_complete_command_silent = value; }
        }

        private string m_complete_command_basic;
        [Description("Basic UI complete command (executed when all components are installed correctly on a basic UI install), can be any executable, document or web page valid for ShellExecute API. Usually is a readme file, a web page or a startup file. If empty no command is executed. (OPTIONAL)")]
        public string complete_command_basic
        {
            get { return m_complete_command_basic; }
            set { m_complete_command_basic = value; }
        }

        private bool m_auto_close_if_installed = true;
        [Description("If true auto close the dialog (display installation_completed message and execute the complete_command) if all the components are already installed. (REQUIRED)")]
        public bool auto_close_if_installed
        {
            get { return m_auto_close_if_installed; }
            set { m_auto_close_if_installed = value; }
        }

        private bool m_auto_close_on_error = false;
        [Description("If true auto close the dialog when a component fails to install and the user chooses not to continue. If false, the component conditions will be re-evaluated and the updated list of components will be shown. (REQUIRED)")]
        public bool auto_close_on_error
        {
            get { return m_auto_close_on_error; }
            set { m_auto_close_on_error = value; }
        }

        private bool m_allow_continue_on_error = true;
        [Description("If true prompt the user to continue on error, otherwise an error is simply reported. Make sure to adjust failed_exec_command_continue if set to false.")]
        public bool allow_continue_on_error
        {
            get { return m_allow_continue_on_error; }
            set { m_allow_continue_on_error = value; }
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

        #endregion

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("dialog_caption", m_dialog_caption);
            e.XmlWriter.WriteAttributeString("dialog_message", m_dialog_message);
            e.XmlWriter.WriteAttributeString("dialog_bitmap", m_dialog_bitmap);
            e.XmlWriter.WriteAttributeString("skip_caption", m_skip_caption);
            e.XmlWriter.WriteAttributeString("install_caption", m_install_caption);
            e.XmlWriter.WriteAttributeString("cancel_caption", m_cancel_caption);
            //e.XmlWriter.WriteAttributeString("reinstallflag_caption",m_reinstallflag_caption);
            e.XmlWriter.WriteAttributeString("status_installed", m_status_installed);
            e.XmlWriter.WriteAttributeString("status_notinstalled", m_status_notinstalled);
            e.XmlWriter.WriteAttributeString("failed_exec_command_continue", m_failed_exec_command_continue);
            e.XmlWriter.WriteAttributeString("installation_completed", m_installation_completed);
            e.XmlWriter.WriteAttributeString("installation_none", m_installation_none);
            // e.XmlWriter.WriteAttributeString("dialog_install_next",m_dialog_install_next);
            // e.XmlWriter.WriteAttributeString("dialog_install_skip",m_dialog_install_skip);
            e.XmlWriter.WriteAttributeString("installing_component_wait", m_installing_component_wait);
            e.XmlWriter.WriteAttributeString("reboot_required", m_reboot_required);
            e.XmlWriter.WriteAttributeString("must_reboot_required", m_must_reboot_required.ToString());

            e.XmlWriter.WriteAttributeString("dialog_otherinfo_caption", m_dialog_otherinfo_caption);
            e.XmlWriter.WriteAttributeString("dialog_otherinfo_link", m_dialog_otherinfo_link);

            e.XmlWriter.WriteAttributeString("complete_command", m_complete_command);
            e.XmlWriter.WriteAttributeString("complete_command_silent", m_complete_command_silent);
            e.XmlWriter.WriteAttributeString("complete_command_basic", m_complete_command_basic);
            e.XmlWriter.WriteAttributeString("auto_close_if_installed", m_auto_close_if_installed.ToString());
            e.XmlWriter.WriteAttributeString("auto_close_on_error", m_auto_close_on_error.ToString());
            e.XmlWriter.WriteAttributeString("allow_continue_on_error", m_allow_continue_on_error.ToString());
            e.XmlWriter.WriteAttributeString("dialog_show_installed", m_dialog_show_installed.ToString());
            e.XmlWriter.WriteAttributeString("dialog_show_required", m_dialog_show_required.ToString());

            // message and caption to show during CAB extraction
            e.XmlWriter.WriteAttributeString("cab_dialog_message", m_cab_dialog_message);
            e.XmlWriter.WriteAttributeString("cab_cancelled_message", m_cab_cancelled_message);
            e.XmlWriter.WriteAttributeString("cab_dialog_caption", m_cab_dialog_caption);

            // CAB path
            e.XmlWriter.WriteAttributeString("cab_path", m_cab_path);
            e.XmlWriter.WriteAttributeString("cab_path_autodelete", m_cab_path_autodelete.ToString());

            // dialog, message and button positions
            e.XmlWriter.WriteAttributeString("dialog_position", XmlRectangle.ToString(m_dialog_position));
            e.XmlWriter.WriteAttributeString("dialog_components_list_position", XmlRectangle.ToString(m_dialog_components_list_position));
            e.XmlWriter.WriteAttributeString("dialog_message_position", XmlRectangle.ToString(m_dialog_message_position));
            e.XmlWriter.WriteAttributeString("dialog_bitmap_position", XmlRectangle.ToString(m_dialog_bitmap_position));
            e.XmlWriter.WriteAttributeString("dialog_otherinfo_link_position", XmlRectangle.ToString(m_dialog_otherinfo_link_position));
            e.XmlWriter.WriteAttributeString("dialog_osinfo_position", XmlRectangle.ToString(m_dialog_osinfo_position));
            e.XmlWriter.WriteAttributeString("dialog_install_button_position", XmlRectangle.ToString(m_dialog_install_button_position));
            e.XmlWriter.WriteAttributeString("dialog_cancel_button_position", XmlRectangle.ToString(m_dialog_cancel_button_position));
            e.XmlWriter.WriteAttributeString("dialog_skip_button_position", XmlRectangle.ToString(m_dialog_skip_button_position));

            base.OnXmlWriteTag(e);
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            ReadAttributeValue(e, "cancel_caption", ref m_cancel_caption);
            ReadAttributeValue(e, "dialog_bitmap", ref m_dialog_bitmap);
            ReadAttributeValue(e, "dialog_caption", ref m_dialog_caption);
            ReadAttributeValue(e, "dialog_message", ref m_dialog_message);
            ReadAttributeValue(e, "failed_exec_command_continue", ref m_failed_exec_command_continue);
            ReadAttributeValue(e, "skip_caption", ref m_skip_caption);
            ReadAttributeValue(e, "install_caption", ref m_install_caption);
            ReadAttributeValue(e, "installation_completed", ref m_installation_completed);
            ReadAttributeValue(e, "installation_none", ref m_installation_none);
            ReadAttributeValue(e, "installing_component_wait", ref m_installing_component_wait);
            ReadAttributeValue(e, "reboot_required", ref m_reboot_required);
            ReadAttributeValue(e, "must_reboot_required", ref m_must_reboot_required);
            ReadAttributeValue(e, "status_installed", ref m_status_installed);
            ReadAttributeValue(e, "status_notinstalled", ref m_status_notinstalled);
            ReadAttributeValue(e, "dialog_otherinfo_caption", ref m_dialog_otherinfo_caption);
            ReadAttributeValue(e, "dialog_otherinfo_link", ref m_dialog_otherinfo_link);
            ReadAttributeValue(e, "complete_command", ref m_complete_command);
            ReadAttributeValue(e, "complete_command_silent", ref m_complete_command_silent);
            ReadAttributeValue(e, "complete_command_basic", ref m_complete_command_basic);
            ReadAttributeValue(e, "auto_close_if_installed", ref m_auto_close_if_installed);
            ReadAttributeValue(e, "auto_close_on_error", ref m_auto_close_on_error);
            ReadAttributeValue(e, "allow_continue_on_error", ref m_allow_continue_on_error);
            ReadAttributeValue(e, "dialog_show_installed", ref m_dialog_show_installed);
            ReadAttributeValue(e, "dialog_show_required", ref m_dialog_show_required);
            // message and caption to show during CAB extraction
            ReadAttributeValue(e, "cab_dialog_message", ref m_cab_dialog_message);
            ReadAttributeValue(e, "cab_cancelled_message", ref m_cab_cancelled_message);
            ReadAttributeValue(e, "cab_dialog_caption", ref m_cab_dialog_caption);
            // CAB path
            ReadAttributeValue(e, "cab_path", ref m_cab_path);
            ReadAttributeValue(e, "cab_path_autodelete", ref m_cab_path_autodelete);
            // dialog, message and button positions
            ReadAttributeValue(e, "dialog_position", ref m_dialog_position);
            ReadAttributeValue(e, "dialog_components_list_position", ref m_dialog_components_list_position);
            ReadAttributeValue(e, "dialog_message_position", ref m_dialog_message_position);
            ReadAttributeValue(e, "dialog_bitmap_position", ref m_dialog_bitmap_position);
            ReadAttributeValue(e, "dialog_otherinfo_link_position", ref m_dialog_otherinfo_link_position);
            ReadAttributeValue(e, "dialog_osinfo_position", ref m_dialog_osinfo_position);
            ReadAttributeValue(e, "dialog_install_button_position", ref m_dialog_install_button_position);
            ReadAttributeValue(e, "dialog_cancel_button_position", ref m_dialog_cancel_button_position);
            ReadAttributeValue(e, "dialog_skip_button_position", ref m_dialog_skip_button_position);
            base.OnXmlReadTag(e);
        }
    }
}
