using System.ComponentModel;

namespace InstallerLib
{
    /// <summary>
    /// Install check comparison types
    /// </summary>
    public enum installcheckdirectory_comparison
    {
        exists,
        version,
        version_eq,
        version_lt,
        version_le,
        version_gt,
        version_ge,
        semver,
        semver_eq,
        semver_lt,
        semver_le,
        semver_gt,
        semver_ge,
    }

    /// <summary>
    /// InstalledCheck of type "check_directory".
    /// </summary>
    public class InstalledCheckDirectory : InstalledCheck
    {
        public InstalledCheckDirectory()
            : base("check_directory")
        {
        }

        private string m_path;
        [Description("Path to search. If the application cannot find the specified path then the component must be installed.")]
        [Required]
        public string path
        {
            get { return m_path; }
            set { m_path = value; }
        }

        private installcheckdirectory_comparison m_comparison;
        [Description("Comparison mode, can be 'exists', 'version', 'semver', etc.")]
        [Required]
        [DefaultValue(installcheckdirectory_comparison.exists)]
        public installcheckdirectory_comparison comparison
        {
            get { return m_comparison; }
            set { m_comparison = value; }
        }

        private string m_version;
        [Description("Optional version used to perform a version check based on the comparison attribute.")]
        public string version
        {
            get { return m_version; }
            set { m_version = value; }
        }

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("path", m_path);
            e.XmlWriter.WriteAttributeString("comparison", m_comparison.ToString());
            e.XmlWriter.WriteAttributeString("version", m_version);
            base.OnXmlWriteTag(e);
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            ReadAttributeValue(e, "path", ref m_path);
            ReadAttributeValue(e, "comparison", ref m_comparison);
            ReadAttributeValue(e, "version", ref m_version);
            base.OnXmlReadTag(e);
        }
    }
}
