using System;
using System.ComponentModel;
using System.ComponentModel.Design;
using System.Xml;
using System.Collections.Generic;

namespace InstallerLib
{
    /// <summary>
    /// An install configuration.
    /// </summary>
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
            m_installing_component_wait = tpl.installing_component_wait;
            m_reboot_required = tpl.reboot_required;
            m_status_installed = tpl.status_installed;
            m_status_notinstalled = tpl.status_notinstalled;

            m_advanced_caption = tpl.advanced_caption;
            m_dialog_selector_caption = tpl.dialog_selector_caption;
            m_dialog_selector_message = tpl.dialog_selector_message;
            m_dialog_selector_ok = tpl.dialog_selector_ok;
            m_dialog_selector_cancel = tpl.dialog_selector_cancel;
            // Matthias Jentsch - 2007-02-06: read OS filter message from template
            m_os_filter_not_match_message = tpl.os_filter_not_match_message;

            // Jason Biegel - 2008-04-22: read processor architecture filter message from template
            m_processor_architecture_filter_not_match_message = tpl.processor_architecture_filter_not_match_message;

            // Daniel Doubrovkine - 2008-06-06: added message and caption to show during CAB extraction
            m_cab_dialog_message = tpl.cab_dialog_message; m_cab_cancelled_message = tpl.cab_cancelled_message;
            m_cab_dialog_caption = tpl.cab_dialog_caption;
            m_cab_path = tpl.cab_path;
            m_cab_path_autodelete = tpl.cab_path_autodelete;

            // Daniel Doubrovkine - 2008-06-24: added auto-enabled logging options
            m_log_enabled = tpl.log_enabled;
            m_log_file = tpl.log_file;
        }

        #region Attributes

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
        public string dialog_message
        {
            get { return m_dialog_message; }
            set { m_dialog_message = value; }
        }

        private string m_dialog_bitmap;
        [Description("Bitmap file used in the left panel of the main dialog. If this file doesn't exist or this attribute is empty the application load the bitmap from the .exe resource. Can contains path constant (see Help->Path Constant). (OPTIONAL)")]
        [Category("Main Dialog")]
        public string dialog_bitmap
        {
            get { return m_dialog_bitmap; }
            set { m_dialog_bitmap = value; }
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
        public string failed_exec_command_continue
        {
            get { return m_failed_exec_command_continue; }
            set { m_failed_exec_command_continue = value; }
        }

        private string m_installation_completed;
        [Description("Installation completed message. (REQUIRED)")]
        [Category("Messages")]
        public string installation_completed
        {
            get { return m_installation_completed; }
            set { m_installation_completed = value; }
        }

        private string m_installing_component_wait;
        [Description("The message used when installing a component. Must contain one '%s' string where the application put the description of the component. (REQUIRED)")]
        [Category("Component")]
        public string installing_component_wait
        {
            get { return m_installing_component_wait; }
            set { m_installing_component_wait = value; }
        }

        private string m_reboot_required;
        [Description("The message used when the application need to restart and ask if restart now (with a Yes/No message). (REQUIRED)")]
        [Category("Messages")]
        public string reboot_required
        {
            get { return m_reboot_required; }
            set { m_reboot_required = value; }
        }

        private string m_advanced_caption;
        [Description("Caption of the Advanced button. Used to show the 'Component Selector' dialog with the complete list of components available to install. If empty the button Advanced is not available. (OPTIONAL)")]
        [Category("Main Dialog")]
        public string advanced_caption
        {
            get { return m_advanced_caption; }
            set { m_advanced_caption = value; }
        }

        private string m_dialog_selector_caption;
        [Description("Component Selector dialog title, this dialog shows the complete list of components available to install. (REQUIRED)")]
        [Category("Component Selector Dialog")]
        public string dialog_selector_caption
        {
            get { return m_dialog_selector_caption; }
            set { m_dialog_selector_caption = value; }
        }

        private string m_dialog_selector_message;
        [Description("Component Selector dialog description, this dialog shows the complete list of components available to install. (REQUIRED)")]
        [Category("Component Selector Dialog")]
        public string dialog_selector_message
        {
            get { return m_dialog_selector_message; }
            set { m_dialog_selector_message = value; }
        }

        private string m_dialog_selector_ok;
        [Description("Component Selector dialog OK caption button. (REQUIRED)")]
        [Category("Component Selector Dialog")]
        public string dialog_selector_ok
        {
            get { return m_dialog_selector_ok; }
            set { m_dialog_selector_ok = value; }
        }

        private string m_dialog_selector_cancel;
        [Description("Component Selector dialog Cancel caption button. (REQUIRED)")]
        [Category("Component Selector Dialog")]
        public string dialog_selector_cancel
        {
            get { return m_dialog_selector_cancel; }
            set { m_dialog_selector_cancel = value; }
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

        private bool m_auto_close_if_installed = true;
        [Description("If true auto close the dialog (display installation_completed message and execute the complete_command) if all the components are already installed. (REQUIRED)")]
        public bool auto_close_if_installed
        {
            get { return m_auto_close_if_installed; }
            set { m_auto_close_if_installed = value; }
        }

        /* Matthias Jentsch - 2006-03-06: added filter for minimal OS version */
        private string m_os_filter_greater;
        [Description("A filter to run this setup only on all operating system id greater than the id specified (see Help->Operating System Table). For example to run this setup only in Windows 2000 or later write '44'. (OPTIONAL)")]
        public string os_filter_greater
        {
            get { return m_os_filter_greater; }
            set { m_os_filter_greater = value; }
        }

        /* Matthias Jentsch - 2006-03-06: added filter for maximal OS version */
        private string m_os_filter_smaller;
        [Description("A filter to run this setup only on all operating system id smaller than the id specified (see operating system table). For example to run this setup preceding Windows 2000 write '45'. (OPTIONAL)")]
        public string os_filter_smaller
        {
            get { return m_os_filter_smaller; }
            set { m_os_filter_smaller = value; }
        }

        /* Matthias Jentsch - 2006-03-06: added message for not matching the OS filter */
        private string m_os_filter_not_match_message;
        [Description("A error message for the case that the operating system does not match the operating system filter (see os_filter_greater and os_filter_smaller). (OPTIONAL)")]
        [Category("Messages")]
        public string os_filter_not_match_message
        {
            get { return m_os_filter_not_match_message; }
            set { m_os_filter_not_match_message = value; }
        }

        /* Jason Biegel - 2008-04-22: added filter for processor architecture */
        private string m_processor_architecture_filter;
        [Description("Type of processor architecture (x86, mips, alpha, ppc, shx, arm, ia64, alpha64, msil, x64, ia32onwin64). Separate by commas, can use the NOT sign ('!') to exclude. (es. 'x86,x64' or '!x86'). (OPTIONAL)")]
        public string processor_architecture_filter
        {
            get { return m_processor_architecture_filter; }
            set { m_processor_architecture_filter = value; }
        }

        /* Jason Biegel - 2008-04-22: added message for not matching the processor architecture filter */
        private string m_processor_architecture_filter_not_match_message;
        [Description("An error message for the case that the processor architecture does not match the filter (see processor_architecture_filter). (OPTIONAL)")]
        [Category("Messages")]
        public string processor_architecture_filter_not_match_message
        {
            get { return m_processor_architecture_filter_not_match_message; }
            set { m_processor_architecture_filter_not_match_message = value; }
        }

        /* Daniel Doubrovkine - 2008-06-06: added message and caption to show during CAB extraction */
        private string m_cab_dialog_message;
        [Description("CAB dialog message, this dialog shows when extracting an embedded CAB file")]
        [Category("Self-Extracting CAB")]
        public string cab_dialog_message
        {
            get { return m_cab_dialog_message; }
            set { m_cab_dialog_message = value; }
        }

        private string m_cab_cancelled_message;
        [Description("CAB cancelled message, this error shows if extraction operation has been aborted")]
        [Category("Self-Extracting CAB")]
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

        /* Daniel Doubrovkine - 2008-06-06: added path to use during CAB extraction */
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


        /* Daniel Doubrovkine - 2008-06-24: added auto-enabled logging options */
        private bool m_log_enabled;
        [Description("Always enable logging; you can also enable logging with /Log on the dotNetInstaller commandline")]
        [DefaultValue(false)]
        [Category("Logging")]
        public bool log_enabled
        {
            get { return m_log_enabled; }
            set { m_log_enabled = value; }
        }

        private string m_log_file;
        [Description("Log filename used for the dotNetInstaller log; msi package logs are named after the msi package and a .log extension")]
        [DefaultValue("#TEMPPATH\\dotNetInstallerLog.txt")]
        [Category("Logging")]
        public string log_file
        {
            get { return m_log_file; }
            set { m_log_file = value; }
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
            // e.XmlWriter.WriteAttributeString("dialog_install_next",m_dialog_install_next);
            // e.XmlWriter.WriteAttributeString("dialog_install_skip",m_dialog_install_skip);
            e.XmlWriter.WriteAttributeString("installing_component_wait", m_installing_component_wait);
            e.XmlWriter.WriteAttributeString("reboot_required", m_reboot_required);

            e.XmlWriter.WriteAttributeString("advanced_caption", m_advanced_caption);
            e.XmlWriter.WriteAttributeString("dialog_selector_cancel", m_dialog_selector_cancel);
            e.XmlWriter.WriteAttributeString("dialog_selector_caption", m_dialog_selector_caption);
            e.XmlWriter.WriteAttributeString("dialog_selector_message", m_dialog_selector_message);
            e.XmlWriter.WriteAttributeString("dialog_selector_ok", m_dialog_selector_ok);

            e.XmlWriter.WriteAttributeString("dialog_otherinfo_caption", m_dialog_otherinfo_caption);
            e.XmlWriter.WriteAttributeString("dialog_otherinfo_link", m_dialog_otherinfo_link);

            e.XmlWriter.WriteAttributeString("complete_command", m_complete_command);
            e.XmlWriter.WriteAttributeString("complete_command_silent", m_complete_command_silent);
            e.XmlWriter.WriteAttributeString("auto_close_if_installed", m_auto_close_if_installed.ToString());

            // Matthias Jentsch - 2006-03-06: new attributes added
            e.XmlWriter.WriteAttributeString("os_filter_greater", m_os_filter_greater);
            e.XmlWriter.WriteAttributeString("os_filter_smaller", m_os_filter_smaller);
            e.XmlWriter.WriteAttributeString("os_filter_not_match_message", m_os_filter_not_match_message);

            // Jason Biegel - 2008-04-22: new attributes added
            e.XmlWriter.WriteAttributeString("processor_architecture_filter", m_processor_architecture_filter);
            e.XmlWriter.WriteAttributeString("processor_architecture_filter_not_match_message", m_processor_architecture_filter_not_match_message);

            // Daniel Doubrovkine - 2008-06-06: added message and caption to show during CAB extraction
            e.XmlWriter.WriteAttributeString("cab_dialog_message", m_cab_dialog_message);
            e.XmlWriter.WriteAttributeString("cab_cancelled_message", m_cab_cancelled_message);
            e.XmlWriter.WriteAttributeString("cab_dialog_caption", m_cab_dialog_caption);

            // Daniel Doubrovkine - 2008-06-12: added CAB path
            e.XmlWriter.WriteAttributeString("cab_path", m_cab_path);
            e.XmlWriter.WriteAttributeString("cab_path_autodelete", m_cab_path_autodelete.ToString());

            // Daniel Doubrovkine - 2008-06-24: added auto-enabled logging
            e.XmlWriter.WriteAttributeString("log_enabled", m_log_enabled.ToString());
            e.XmlWriter.WriteAttributeString("log_file", m_log_file);
            base.OnXmlWriteTag(e);
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            if (e.XmlElement.Attributes["cancel_caption"] != null)
                m_cancel_caption = e.XmlElement.Attributes["cancel_caption"].InnerText;

            if (e.XmlElement.Attributes["dialog_bitmap"] != null)
                m_dialog_bitmap = e.XmlElement.Attributes["dialog_bitmap"].InnerText;

            if (e.XmlElement.Attributes["dialog_caption"] != null)
                m_dialog_caption = e.XmlElement.Attributes["dialog_caption"].InnerText;

            //			if (e.XmlElement.Attributes["dialog_install_next"] != null)
            //				m_dialog_install_next = e.XmlElement.Attributes["dialog_install_next"].InnerText;
            //
            //			if (e.XmlElement.Attributes["dialog_install_skip"] != null)
            //				m_dialog_install_skip = e.XmlElement.Attributes["dialog_install_skip"].InnerText;

            if (e.XmlElement.Attributes["dialog_message"] != null)
                m_dialog_message = e.XmlElement.Attributes["dialog_message"].InnerText;

            if (e.XmlElement.Attributes["failed_exec_command_continue"] != null)
                m_failed_exec_command_continue = e.XmlElement.Attributes["failed_exec_command_continue"].InnerText;

            if (e.XmlElement.Attributes["skip_caption"] != null)
                m_skip_caption = e.XmlElement.Attributes["skip_caption"].InnerText;

            if (e.XmlElement.Attributes["install_caption"] != null)
                m_install_caption = e.XmlElement.Attributes["install_caption"].InnerText;

            if (e.XmlElement.Attributes["installation_completed"] != null)
                m_installation_completed = e.XmlElement.Attributes["installation_completed"].InnerText;

            if (e.XmlElement.Attributes["installing_component_wait"] != null)
                m_installing_component_wait = e.XmlElement.Attributes["installing_component_wait"].InnerText;

            if (e.XmlElement.Attributes["reboot_required"] != null)
                m_reboot_required = e.XmlElement.Attributes["reboot_required"].InnerText;

            //			if (e.XmlElement.Attributes["reinstallflag_caption"] != null)
            //				m_reinstallflag_caption = e.XmlElement.Attributes["reinstallflag_caption"].InnerText;

            if (e.XmlElement.Attributes["status_installed"] != null)
                m_status_installed = e.XmlElement.Attributes["status_installed"].InnerText;

            if (e.XmlElement.Attributes["status_notinstalled"] != null)
                m_status_notinstalled = e.XmlElement.Attributes["status_notinstalled"].InnerText;


            if (e.XmlElement.Attributes["advanced_caption"] != null)
                m_advanced_caption = e.XmlElement.Attributes["advanced_caption"].InnerText;

            if (e.XmlElement.Attributes["dialog_selector_cancel"] != null)
                m_dialog_selector_cancel = e.XmlElement.Attributes["dialog_selector_cancel"].InnerText;

            if (e.XmlElement.Attributes["dialog_selector_caption"] != null)
                m_dialog_selector_caption = e.XmlElement.Attributes["dialog_selector_caption"].InnerText;

            if (e.XmlElement.Attributes["dialog_selector_message"] != null)
                m_dialog_selector_message = e.XmlElement.Attributes["dialog_selector_message"].InnerText;

            if (e.XmlElement.Attributes["dialog_selector_ok"] != null)
                m_dialog_selector_ok = e.XmlElement.Attributes["dialog_selector_ok"].InnerText;


            if (e.XmlElement.Attributes["dialog_otherinfo_caption"] != null)
                m_dialog_otherinfo_caption = e.XmlElement.Attributes["dialog_otherinfo_caption"].InnerText;

            if (e.XmlElement.Attributes["dialog_otherinfo_link"] != null)
                m_dialog_otherinfo_link = e.XmlElement.Attributes["dialog_otherinfo_link"].InnerText;


            if (e.XmlElement.Attributes["complete_command"] != null)
                m_complete_command = e.XmlElement.Attributes["complete_command"].InnerText;

            if (e.XmlElement.Attributes["complete_command_silent"] != null)
                m_complete_command_silent = e.XmlElement.Attributes["complete_command_silent"].InnerText;

            if (e.XmlElement.Attributes["auto_close_if_installed"] != null)
                m_auto_close_if_installed = bool.Parse(e.XmlElement.Attributes["auto_close_if_installed"].InnerText);

            // Matthias Jentsch - 2006-03-06: new attributes added
            if (e.XmlElement.Attributes["os_filter_greater"] != null)
                m_os_filter_greater = e.XmlElement.Attributes["os_filter_greater"].InnerText;
            if (e.XmlElement.Attributes["os_filter_smaller"] != null)
                m_os_filter_smaller = e.XmlElement.Attributes["os_filter_smaller"].InnerText;
            if (e.XmlElement.Attributes["os_filter_not_match_message"] != null)
                m_os_filter_not_match_message = e.XmlElement.Attributes["os_filter_not_match_message"].InnerText;

            // Jason Biegel - 2008-04-22: new attributes added
            if (e.XmlElement.Attributes["processor_architecture_filter"] != null)
                m_processor_architecture_filter = e.XmlElement.Attributes["processor_architecture_filter"].InnerText;

            // Daniel Doubrovkine - 2008-06-06: added message and caption to show during CAB extraction
            if (e.XmlElement.Attributes["cab_dialog_message"] != null)
                m_cab_dialog_message = e.XmlElement.Attributes["cab_dialog_message"].InnerText;

            if (e.XmlElement.Attributes["cab_cancelled_message"] != null)
                m_cab_cancelled_message = e.XmlElement.Attributes["cab_cancelled_message"].InnerText;

            if (e.XmlElement.Attributes["cab_dialog_caption"] != null)
                m_cab_dialog_caption = e.XmlElement.Attributes["cab_dialog_caption"].InnerText;

            // Daniel Doubrovkine - 2008-06-12: added CAB path
            if (e.XmlElement.Attributes["cab_path"] != null)
                m_cab_path = e.XmlElement.Attributes["cab_path"].InnerText;

            if (e.XmlElement.Attributes["cab_path_autodelete"] != null)
                cab_path_autodelete = bool.Parse(e.XmlElement.Attributes["cab_path_autodelete"].InnerText);

            // Daniel Doubrovkine - 2008-06-24: added auto-enable logging
            if (e.XmlElement.Attributes["log_enabled"] != null)
                m_log_enabled = bool.Parse(e.XmlElement.Attributes["log_enabled"].InnerText);

            if (e.XmlElement.Attributes["log_file"] != null)
                m_log_file = e.XmlElement.Attributes["log_file"].InnerText;

            base.OnXmlReadTag(e);
        }
    }
}
