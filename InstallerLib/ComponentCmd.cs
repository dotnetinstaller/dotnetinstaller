using System.ComponentModel;

namespace InstallerLib
{
    [Description("A component of type 'cmd' executes a user-defined command.")]
    public class ComponentCmd : Component
    {
        public ComponentCmd()
            : base("cmd", "command1")
        {
            m_command = "cmd.exe /C \"#APPPATH\\mysetup.exe\"";
        }

        #region Commands

        private string m_command;
        [Description("Command to execute when installing this component. Use 'cmd.exe' to execute typical commands (eg. 'cmd.exe /C copy x.txt y.txt').")]
        [Category("Install")]
        [Required]
        public string command
        {
            get { return m_command; }
            set { m_command = value; }
        }

        private string m_command_silent;
        [Description("Command to execute during silent install. Defaults to 'command' when blank.")]
        [Category("Install")]
        public string command_silent
        {
            get { return m_command_silent; }
            set { m_command_silent = value; }
        }

        private string m_command_basic;
        [Description("Command to execute during basic UI install. Defaults to 'command' when blank.")]
        [Category("Install")]
        public string command_basic
        {
            get { return m_command_basic; }
            set { m_command_basic = value; }
        }

        private string m_uninstall_command;
        [Description("Command to execute when uninstalling this component.")]
        [Category("Uninstall")]
        public string uninstall_command
        {
            get { return m_uninstall_command; }
            set { m_uninstall_command = value; }
        }

        private string m_uninstall_command_silent;
        [Description("Command to execute on silent uninstall. Defaults to 'uninstall_command' when blank.")]
        [Category("Uninstall")]
        public string uninstall_command_silent
        {
            get { return m_uninstall_command_silent; }
            set { m_uninstall_command_silent = value; }
        }

        private string m_uninstall_command_basic;
        [Description("Command to execute on basic UI uninstall. Defaults to 'uninstall_command' when blank.")]
        [Category("Uninstall")]
        public string uninstall_command_basic
        {
            get { return m_uninstall_command_basic; }
            set { m_uninstall_command_basic = value; }
        }

        private string m_working_directory;
        [Description("The working directory for the process. Defaults to the current working directory of the bootstrapper.")]
        [Category("Runtime")]
        public string working_directory
        {
            get { return m_working_directory; }
            set { m_working_directory = value; }
        }

        private bool m_hide_window = false;
        [Description("Indicates whether to hide the application window from being displayed when run.")]
        [Category("Runtime")]
        [Required]
        public bool hide_window
        {
            get { return m_hide_window; }
            set { m_hide_window = value; }
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

        private CommandExecutionMethod m_execution_method = CommandExecutionMethod.CreateProcess;
        [Description("Function used to execute command. Use ShellExecute if command requires elevated privileges. Otherwise, use CreateProcess.")]
        [Category("Runtime")]
        [Required]
        public CommandExecutionMethod execution_method
        {
            get { return m_execution_method; }
            set { m_execution_method = value; }
        }

        #endregion

        #region Return Codes

        private string m_returncodes_success;
        [Description("Comma-separated return codes that indicate success. By default a return value of 0 indicates success. To specify a hex value prefix it with '0x'. Specify 'all' to create a component that doesn't fail based on its return code and specify !value to treat all return codes except a single value as success.")]
        [Category("Return Codes")]
        public string returncodes_success
        {
            get { return m_returncodes_success; }
            set { m_returncodes_success = value; }
        }

        private string m_returncodes_reboot;
        [Description("Comma-separated return codes that indicate that a reboot is requred. To specify a hex value prefix it with '0x'.")]
        [Category("Return Codes")]
        public string returncodes_reboot
        {
            get { return m_returncodes_reboot; }
            set { m_returncodes_reboot = value; }
        }

        #endregion

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("command", m_command);
            e.XmlWriter.WriteAttributeString("command_silent", m_command_silent);
            e.XmlWriter.WriteAttributeString("command_basic", m_command_basic);
            e.XmlWriter.WriteAttributeString("uninstall_command", m_uninstall_command);
            e.XmlWriter.WriteAttributeString("uninstall_command_silent", m_uninstall_command_silent);
            e.XmlWriter.WriteAttributeString("uninstall_command_basic", m_uninstall_command_basic);
            e.XmlWriter.WriteAttributeString("working_directory", m_working_directory);
            e.XmlWriter.WriteAttributeString("returncodes_success", m_returncodes_success);
            e.XmlWriter.WriteAttributeString("returncodes_reboot", m_returncodes_reboot);
            e.XmlWriter.WriteAttributeString("hide_window", m_hide_window.ToString());
            e.XmlWriter.WriteAttributeString("disable_wow64_fs_redirection", m_disable_wow64_fs_redirection.ToString());
            e.XmlWriter.WriteAttributeString("execution_method", m_execution_method.ToString());
            base.OnXmlWriteTag(e);
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            ReadAttributeValue(e, "command", ref m_command);
            ReadAttributeValue(e, "command_silent", ref m_command_silent);
            ReadAttributeValue(e, "command_basic", ref m_command_basic);
            ReadAttributeValue(e, "uninstall_command", ref m_uninstall_command);
            ReadAttributeValue(e, "uninstall_command_silent", ref m_uninstall_command_silent);
            ReadAttributeValue(e, "uninstall_command_basic", ref m_uninstall_command_basic);
            ReadAttributeValue(e, "working_directory", ref m_working_directory);
            ReadAttributeValue(e, "returncodes_success", ref m_returncodes_success);
            ReadAttributeValue(e, "returncodes_reboot", ref m_returncodes_reboot);
            ReadAttributeValue(e, "hide_window", ref m_hide_window);
            ReadAttributeValue(e, "disable_wow64_fs_redirection", ref m_disable_wow64_fs_redirection);
            ReadAttributeValue(e, "execution_method", ref m_execution_method);
            base.OnXmlReadTag(e);
        }
    }
}
