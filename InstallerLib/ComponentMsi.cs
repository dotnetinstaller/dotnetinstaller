using System.ComponentModel;

namespace InstallerLib
{
    [Description("A component of type 'msi' executes a Windows Installer package using the 'msiexec.exe' command.")]
    public class ComponentMsi : Component
    {
        public ComponentMsi()
            : base("msi", "mysetup.msi")
        {
            m_package = "#APPPATH\\mysetup.msi";
            supports_uninstall = true;
        }

        private string m_package;
        [Description("Path to the msi package or an existing product GUID. Package GUIDs enable scenarios of reinstalling a previously cached MSI.")]
        [Category("Msi")]
        [Required]
        public string package
        {
            get { return m_package; }
            set { m_package = value; }
        }

        private string m_cmdparameters;
        [Description("Optional command-line parameters for the msiexec.exe program. May contain quotes. See MSDN for the command line you can use with Windows Installer.")]
        [Category("Msi")]
        public string cmdparameters
        {
            get { return m_cmdparameters; }
            set { m_cmdparameters = value; }
        }

        private string m_cmdparameters_basic = "/qb-";
        [Description("Optional command-line parameters for the msiexec program when running in basic UI mode.")]
        [Category("Msi")]
        public string cmdparameters_basic
        {
            get { return m_cmdparameters_basic; }
            set { m_cmdparameters_basic = value; }
        }

        private string m_cmdparameters_silent = "/qn";
        [Description("Optional command-line parameters for the msiexec program when running in silent UI mode.")]
        [Category("Msi")]
        public string cmdparameters_silent
        {
            get { return m_cmdparameters_silent; }
            set { m_cmdparameters_silent = value; }
        }

        private string m_uninstall_package;
        [Description("Path to the msi package or an existing product GUID for uninstall.")]
        [Category("Msi")]
        public string uninstall_package
        {
            get { return m_uninstall_package; }
            set { m_uninstall_package = value; }
        }

        private string m_uninstall_cmdparameters = "/qb-";
        [Description("Optional command-line parameters for the msiexec program on uninstall. May contain quotes and other special characters. See MSDN for the command line you can use with Windows Installer.")]
        [Category("Msi")]
        public string uninstall_cmdparameters
        {
            get { return m_uninstall_cmdparameters; }
            set { m_uninstall_cmdparameters = value; }
        }

        private string m_uninstall_cmdparameters_basic = "/qb-";
        [Description("Optional command line parameters for the msiexec program on uninstall when running in basic UI mode.")]
        [Category("Msi")]
        public string uninstall_cmdparameters_basic
        {
            get { return m_uninstall_cmdparameters_basic; }
            set { m_uninstall_cmdparameters_basic = value; }
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

        private string m_uninstall_cmdparameters_silent = "/qn";
        [Description("Optional command line parameters for the msiexec program on uninstall when running in silent UI mode.")]
        [Category("Msi")]
        public string uninstall_cmdparameters_silent
        {
            get { return m_uninstall_cmdparameters_silent; }
            set { m_uninstall_cmdparameters_silent = value; }
        }

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("package", m_package);
            e.XmlWriter.WriteAttributeString("cmdparameters", m_cmdparameters);
            e.XmlWriter.WriteAttributeString("cmdparameters_silent", m_cmdparameters_silent);
            e.XmlWriter.WriteAttributeString("cmdparameters_basic", m_cmdparameters_basic);
            e.XmlWriter.WriteAttributeString("uninstall_package", m_uninstall_package);
            e.XmlWriter.WriteAttributeString("uninstall_cmdparameters", m_uninstall_cmdparameters);
            e.XmlWriter.WriteAttributeString("uninstall_cmdparameters_silent", m_uninstall_cmdparameters_silent);
            e.XmlWriter.WriteAttributeString("uninstall_cmdparameters_basic", m_uninstall_cmdparameters_basic);
            e.XmlWriter.WriteAttributeString("disable_wow64_fs_redirection", m_disable_wow64_fs_redirection.ToString());
            base.OnXmlWriteTag(e);
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            ReadAttributeValue(e, "package", ref m_package);
            ReadAttributeValue(e, "cmdparameters", ref m_cmdparameters);
            ReadAttributeValue(e, "cmdparameters_silent", ref m_cmdparameters_silent);
            ReadAttributeValue(e, "cmdparameters_basic", ref m_cmdparameters_basic);
            ReadAttributeValue(e, "uninstall_package", ref m_uninstall_package);
            ReadAttributeValue(e, "uninstall_cmdparameters", ref m_uninstall_cmdparameters);
            ReadAttributeValue(e, "uninstall_cmdparameters_silent", ref m_uninstall_cmdparameters_silent);
            ReadAttributeValue(e, "uninstall_cmdparameters_basic", ref m_uninstall_cmdparameters_basic);
            ReadAttributeValue(e, "disable_wow64_fs_redirection", ref m_disable_wow64_fs_redirection);
            base.OnXmlReadTag(e);
        }
    }
}
