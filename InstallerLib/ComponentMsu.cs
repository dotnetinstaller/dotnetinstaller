using System.ComponentModel;

namespace InstallerLib
{
    [Description("A component of type 'msu' that executes a Windows Update package using the 'wusa.exe' command.")]
    public class ComponentMsu : Component
    {
        public ComponentMsu()
            : base("msu", "mysetup.msu")
        {
            m_package = "#APPPATH\\mysetup.msu";
            os_filter_min = OperatingSystem.winVista;
        }

        private string m_package;
        [Description("Path to the Windows update package to install.")]
        [Required]
        public string package
        {
            get { return m_package; }
            set { m_package = value; }
        }

        private string m_cmdparameters = "/norestart";
        [Description("Command-line parameters for the 'wusa.exe' program (eg. '/norestart'). See MSDN for the command line you can use with 'wusa.exe'.")]
        public string cmdparameters
        {
            get { return m_cmdparameters; }
            set { m_cmdparameters = value; }
        }

        private string m_cmdparameters_basic = "/quiet /norestart";
        [Description("Command-line parameters for the 'wusa.exe' program when running a basic UI mode (eg. '/quiet /norestart'). Defaults to 'cmdparameters' if blank. See MSDN for the command line you can use with 'wusa.exe'.")]
        public string cmdparameters_basic
        {
            get { return m_cmdparameters_basic; }
            set { m_cmdparameters_basic = value; }
        }

        private string m_cmdparameters_silent = "/quiet /norestart";
        [Description("Specifies the command line parameters for the 'wusa.exe' program when running a silent install (eg. '/quiet /norestart'). Defaults to 'cmdparameters' if blank. See MSDN for the command line you can use with 'wusa.exe'.")]
        public string cmdparameters_silent
        {
            get { return m_cmdparameters_silent; }
            set { m_cmdparameters_silent = value; }
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

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("package", m_package);
            e.XmlWriter.WriteAttributeString("cmdparameters", m_cmdparameters);
            e.XmlWriter.WriteAttributeString("cmdparameters_silent", m_cmdparameters_silent);
            e.XmlWriter.WriteAttributeString("cmdparameters_basic", m_cmdparameters_basic);
            e.XmlWriter.WriteAttributeString("disable_wow64_fs_redirection", m_disable_wow64_fs_redirection.ToString());
            e.XmlWriter.WriteAttributeString("execution_method", m_execution_method.ToString());
            base.OnXmlWriteTag(e);
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            ReadAttributeValue(e, "package", ref m_package);
            ReadAttributeValue(e, "cmdparameters", ref m_cmdparameters);
            ReadAttributeValue(e, "cmdparameters_silent", ref m_cmdparameters_silent);
            ReadAttributeValue(e, "cmdparameters_basic", ref m_cmdparameters_basic);
            ReadAttributeValue(e, "disable_wow64_fs_redirection", ref m_disable_wow64_fs_redirection);
            ReadAttributeValue(e, "execution_method", ref m_execution_method);
            base.OnXmlReadTag(e);
        }
    }
}
