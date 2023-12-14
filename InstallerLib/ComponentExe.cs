using System.ComponentModel;

namespace InstallerLib
{
    public enum ResponseFileFormat
    {
        none,
        text,
        ini
    }

    [Description(
      "<para>" +
        "A component of type <literal>exe</literal> executes a packaged setup executable with an optional response file. " +
        "A reponse file may be in either <newTerm>text</newTerm> or <newTerm>ini</newTerm> format and allows the installer " +
        "to perform path or user-defined property replacements." +
      "</para>" +
      "<para>" +
        "For example, you may want to supply <literal>#CABPATH</literal> and a user-defined destination " +
        "<literal>[INSTALLLOCATION]</literal> within a setup.ini response file similar to this one." +
        "<code langauge=\"ini\">" +
          "<![CDATA[" +
"[Options]\r\n" +
"SourcePath=#CABPATH\r\n" +
"TargetPath=[INSTALLLOCATION]\r\n" +
          "]]>" +
        "</code>" +
        "dotNetInstaller will process this file defined by <newTerm>responsefile_source</newTerm> before running the setup executable " +
        "and write its output to <newTerm>responsefile_target</newTerm>." +
        "<code langauge=\"ini\">" +
          "<![CDATA[\r\n" +
"[Options]\r\n" +
"SourcePath=C:\\temp\\cabs\r\n" +
"TargetPath=C:\\Program Files\\MySampleSetup\r\n" +
          "]]>" +
        "</code>" +
        "You can supply the value of <newTerm>responsefile_target</newTerm> in <newTerm>exeparameters</newTerm>." +
      "</para>")]
    [DocumentationSection("Response File Formats",
         "<para>" +
          "<tableDefinition>" +
           "<definedTerm>none</definedTerm>" +
           "<definition>" +
             "Do not process response file, copy." +
            "</definition>" +
            "<definedTerm>text</definedTerm>" +
            "<definition>" +
             "The response file is text in ANSI format." +
            "</definition>" +
            "<definedTerm>ini</definedTerm>" +
            "<definition>" +
             "The response file is an ANSI .ini file. Only ini values are processed for variables." +
            "</definition>" +
          "</tableDefinition>" +
        "</para>")]
    public class ComponentExe : Component
    {
        public ComponentExe()
            : base("exe", "setup.exe")
        {
            m_executable = "setup.exe";
        }

        #region Commands

        private string m_executable;
        [Description("Executable to run when installing this component.")]
        [Category("Install")]
        [Required]
        public string executable
        {
            get { return m_executable; }
            set { m_executable = value; }
        }

        private string m_executable_silent;
        [Description("Executable to run on silent install. Defaults to 'executable' when blank.")]
        [Category("Install")]
        public string executable_silent
        {
            get { return m_executable_silent; }
            set { m_executable_silent = value; }
        }

        private string m_executable_basic;
        [Description("Executable to run on basic UI install. Defaults to 'executable' when blank.")]
        [Category("Install")]
        public string executable_basic
        {
            get { return m_executable_basic; }
            set { m_executable_basic = value; }
        }

        private string m_uninstall_executable;
        [Description("Executable to run when uninstalling this component.")]
        [Category("Uninstall")]
        public string uninstall_executable
        {
            get { return m_uninstall_executable; }
            set { m_uninstall_executable = value; }
        }

        private string m_uninstall_executable_silent;
        [Description("Executable to run on silent uninstall. Defaults to 'uninstall_executable' when blank.")]
        [Category("Uninstall")]
        public string uninstall_executable_silent
        {
            get { return m_uninstall_executable_silent; }
            set { m_uninstall_executable_silent = value; }
        }

        private string m_uninstall_executable_basic;
        [Description("Executable to run on basic UI uninstall. Defaults to 'uninstall_executable' when blank.")]
        [Category("Uninstall")]
        public string uninstall_executable_basic
        {
            get { return m_uninstall_executable_basic; }
            set { m_uninstall_executable_basic = value; }
        }

        private ResponseFileFormat m_responsefile_format = ResponseFileFormat.none;
        [Description("Response file format. Ini and text response files are pre-processed.")]
        [Category("Response File")]
        public ResponseFileFormat responsefile_format
        {
            get { return m_responsefile_format; }
            set { m_responsefile_format = value; }
        }

        private string m_responsefile_source;
        [Description("Optional response file source (the response file extracted by the bootstrapper).")]
        [Category("Install")]
        public string responsefile_source
        {
            get { return m_responsefile_source; }
            set { m_responsefile_source = value; }
        }

        private string m_responsefile_target;
        [Description("Optional response file target (the processed response file created by the bootstrapper).")]
        [Category("Install")]
        public string responsefile_target
        {
            get { return m_responsefile_target; }
            set { m_responsefile_target = value; }
        }

        private string m_uninstall_responsefile_source;
        [Description("Optional response file source (the response file extracted by the bootstrapper) for uninstallation.")]
        [Category("Uninstall")]
        public string uninstall_responsefile_source
        {
            get { return m_uninstall_responsefile_source; }
            set { m_uninstall_responsefile_source = value; }
        }

        private string m_uninstall_responsefile_target;
        [Description("Optional response file target (the processed response file created by the bootstrapper) for uninstallation.")]
        [Category("Uninstall")]
        public string uninstall_responsefile_target
        {
            get { return m_uninstall_responsefile_target; }
            set { m_uninstall_responsefile_target = value; }
        }

        private bool m_disable_wow64_fs_redirection = false;
        [Description("Indicates whether to disable wow64 file system redirection on x64 systems. Setting this option to 'true' forces the application to execute in native x64 environment.")]
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

        private string m_exeparameters;
        [Description("Optional command line parameters for the executable setup.")]
        [Category("Install")]
        public string exeparameters
        {
            get { return m_exeparameters; }
            set { m_exeparameters = value; }
        }

        private string m_exeparameters_basic;
        [Description("Optional command line parameters for the executable setup in basic UI mode.")]
        [Category("Install")]
        public string exeparameters_basic
        {
            get { return m_exeparameters_basic; }
            set { m_exeparameters_basic = value; }
        }

        private string m_exeparameters_silent;
        [Description("Optional command line parameters for the executable setup in silent UI mode.")]
        [Category("Install")]
        public string exeparameters_silent
        {
            get { return m_exeparameters_silent; }
            set { m_exeparameters_silent = value; }
        }

        private string m_uninstall_exeparameters;
        [Description("Optional command line parameters for the executable setup on uninstall.")]
        [Category("Uninstall")]
        public string uninstall_exeparameters
        {
            get { return m_uninstall_exeparameters; }
            set { m_uninstall_exeparameters = value; }
        }

        private string m_uninstall_exeparameters_basic;
        [Description("Optional command line parameters for the executable setup in basic UI mode on uninstall.")]
        [Category("Uninstall")]
        public string uninstall_exeparameters_basic
        {
            get { return m_uninstall_exeparameters_basic; }
            set { m_uninstall_exeparameters_basic = value; }
        }

        private string m_uninstall_exeparameters_silent;
        [Description("Optional command line parameters for the executable setup in silent UI mode on uninstall.")]
        [Category("Uninstall")]
        public string uninstall_exeparameters_silent
        {
            get { return m_uninstall_exeparameters_silent; }
            set { m_uninstall_exeparameters_silent = value; }
        }

        private string m_install_directory;
        [Description(
              "Optional directory created by the bootstrapper before processing the response file and executing the " +
              "component command. When specified, the directory is created on installation when it doesn't exist. " +
              "This supports typical packaged setup programs that require the destination folder to exist prior to installation.")]
        [Category("Install")]
        public string install_directory
        {
            get { return m_install_directory; }
            set { m_install_directory = value; }
        }

        #endregion

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("executable", m_executable);
            e.XmlWriter.WriteAttributeString("executable_silent", m_executable_silent);
            e.XmlWriter.WriteAttributeString("executable_basic", m_executable_basic);
            e.XmlWriter.WriteAttributeString("install_directory", m_install_directory);
            e.XmlWriter.WriteAttributeString("responsefile_source", m_responsefile_source);
            e.XmlWriter.WriteAttributeString("responsefile_target", m_responsefile_target);
            e.XmlWriter.WriteAttributeString("responsefile_format", m_responsefile_format.ToString());
            e.XmlWriter.WriteAttributeString("uninstall_executable", m_uninstall_executable);
            e.XmlWriter.WriteAttributeString("uninstall_executable_silent", m_uninstall_executable_silent);
            e.XmlWriter.WriteAttributeString("uninstall_executable_basic", m_uninstall_executable_basic);
            e.XmlWriter.WriteAttributeString("uninstall_responsefile_source", m_uninstall_responsefile_source);
            e.XmlWriter.WriteAttributeString("uninstall_responsefile_target", m_uninstall_responsefile_target);
            e.XmlWriter.WriteAttributeString("returncodes_success", m_returncodes_success);
            e.XmlWriter.WriteAttributeString("returncodes_reboot", m_returncodes_reboot);
            e.XmlWriter.WriteAttributeString("exeparameters", m_exeparameters);
            e.XmlWriter.WriteAttributeString("exeparameters_basic", m_exeparameters_basic);
            e.XmlWriter.WriteAttributeString("exeparameters_silent", m_exeparameters_silent);
            e.XmlWriter.WriteAttributeString("uninstall_exeparameters", m_uninstall_exeparameters);
            e.XmlWriter.WriteAttributeString("uninstall_exeparameters_basic", m_uninstall_exeparameters_basic);
            e.XmlWriter.WriteAttributeString("uninstall_exeparameters_silent", m_uninstall_exeparameters_silent);
            e.XmlWriter.WriteAttributeString("disable_wow64_fs_redirection", m_disable_wow64_fs_redirection.ToString());
            e.XmlWriter.WriteAttributeString("execution_method", m_execution_method.ToString());
            base.OnXmlWriteTag(e);
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            ReadAttributeValue(e, "executable", ref m_executable);
            ReadAttributeValue(e, "executable_silent", ref m_executable_silent);
            ReadAttributeValue(e, "executable_basic", ref m_executable_basic);
            ReadAttributeValue(e, "install_directory", ref m_install_directory);
            ReadAttributeValue(e, "responsefile_source", ref m_responsefile_source);
            ReadAttributeValue(e, "responsefile_target", ref m_responsefile_target);
            ReadAttributeValue(e, "responsefile_format", ref m_responsefile_format);
            ReadAttributeValue(e, "uninstall_executable", ref m_uninstall_executable);
            ReadAttributeValue(e, "uninstall_executable_silent", ref m_uninstall_executable_silent);
            ReadAttributeValue(e, "uninstall_executable_basic", ref m_uninstall_executable_basic);
            ReadAttributeValue(e, "uninstall_responsefile_source", ref m_uninstall_responsefile_source);
            ReadAttributeValue(e, "uninstall_responsefile_target", ref m_uninstall_responsefile_target);
            ReadAttributeValue(e, "returncodes_success", ref m_returncodes_success);
            ReadAttributeValue(e, "returncodes_reboot", ref m_returncodes_reboot);
            ReadAttributeValue(e, "exeparameters", ref m_exeparameters);
            ReadAttributeValue(e, "exeparameters_basic", ref m_exeparameters_basic);
            ReadAttributeValue(e, "exeparameters_silent", ref m_exeparameters_silent);
            ReadAttributeValue(e, "uninstall_exeparameters", ref m_uninstall_exeparameters);
            ReadAttributeValue(e, "uninstall_exeparameters_basic", ref m_uninstall_exeparameters_basic);
            ReadAttributeValue(e, "uninstall_exeparameters_silent", ref m_uninstall_exeparameters_silent);
            ReadAttributeValue(e, "disable_wow64_fs_redirection", ref m_disable_wow64_fs_redirection);
            ReadAttributeValue(e, "execution_method", ref m_execution_method);
            base.OnXmlReadTag(e);
        }
    }
}
