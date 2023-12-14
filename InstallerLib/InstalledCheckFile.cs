using System.ComponentModel;

namespace InstallerLib
{
    /// <summary>
    /// Install check comparison types
    /// </summary>
    public enum installcheckfile_comparison
    {
        match,
        version,
        version_eq,
        version_lt,
        version_le,
        version_gt,
        version_ge,
        exists
    }

    /// <summary>
    /// InstalledCheck of type "check_file".
    /// </summary>
    public class InstalledCheckFile : InstalledCheck
    {
        public InstalledCheckFile()
            : base("check_file")
        {
            m_filename = "#SYSTEMPATH\\my_dll.dll";
            m_comparison = installcheckfile_comparison.version;
            m_fileversion = "2.1.0.0";
        }

        private string m_filename;
        [Description("File to search. If the application cannot find the specified file then the component must be installed.")]
        [Required]
        public string filename
        {
            get { return m_filename; }
            set { m_filename = value; }
        }

        private string m_fileversion;
        [Description("Optional version of the file. Can be used to perform version check based on comparison attribute. If empty the application check only for the presence of the file.")]
        public string fileversion
        {
            get { return m_fileversion; }
            set { m_fileversion = value; }
        }

        private installcheckfile_comparison m_comparison;
        [Description("Comparison mode, can be 'match', 'version', 'exists', etc.")]
        [Required]
        public installcheckfile_comparison comparison
        {
            get { return m_comparison; }
            set { m_comparison = value; }
        }

        private bool m_defaultvalue = false;
        [Description("Default check value for comparison operators other than 'exists' when the file doesn't exist.")]
        [Required]
        public bool defaultvalue
        {
            get { return m_defaultvalue; }
            set { m_defaultvalue = value; }
        }

        private bool m_disable_wow64_fs_redirection = false;
        [Description("Indicates whether to disable wow64 file system redirection on x64 systems. Setting this option to 'true' forces the check to execute in the native x64 environment.")]
        [Required]
        public bool disable_wow64_fs_redirection
        {
            get { return m_disable_wow64_fs_redirection; }
            set { m_disable_wow64_fs_redirection = value; }
        }

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("filename", m_filename);
            e.XmlWriter.WriteAttributeString("fileversion", m_fileversion);
            e.XmlWriter.WriteAttributeString("comparison", m_comparison.ToString());
            e.XmlWriter.WriteAttributeString("defaultvalue", m_defaultvalue.ToString());
            e.XmlWriter.WriteAttributeString("disable_wow64_fs_redirection", m_disable_wow64_fs_redirection.ToString());
            base.OnXmlWriteTag(e);
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            ReadAttributeValue(e, "filename", ref m_filename);
            ReadAttributeValue(e, "fileversion", ref m_fileversion);
            ReadAttributeValue(e, "comparison", ref m_comparison);
            ReadAttributeValue(e, "defaultvalue", ref m_defaultvalue);
            ReadAttributeValue(e, "disable_wow64_fs_redirection", ref m_disable_wow64_fs_redirection);
            base.OnXmlReadTag(e);
        }
    }
}
