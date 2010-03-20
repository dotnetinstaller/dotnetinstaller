using System;
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
        [Description("Specifies the file to search, if the application cannot find the specified file then the component must be installed. This attribute can contain path constant (see Help->Path Constant). (REQUIRED)")]
        public string filename
        {
            get { return m_filename; }
            set { m_filename = value; }
        }

        private string m_fileversion;
        [Description("The version of the file, can be used to perform version check based on comparison attribute. If empty the application check only for the presence of the file. (OPTIONAL)")]
        public string fileversion
        {
            get { return m_fileversion; }
            set { m_fileversion = value; }
        }

        private installcheckfile_comparison m_comparison;
        [Description("Comparison mode, can be 'match', 'version', 'exists', etc. (REQUIRED)")]
        public installcheckfile_comparison comparison
        {
            get { return m_comparison; }
            set { m_comparison = value; }
        }

        private bool m_defaultvalue = false;
        [Description("The default check value for comparison operators other than 'exists' when the file doesn't exist. (REQUIRED)")]
        public bool defaultvalue
        {
            get { return m_defaultvalue; }
            set { m_defaultvalue = value; }
        }

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("filename", m_filename);
            e.XmlWriter.WriteAttributeString("fileversion", m_fileversion);
            e.XmlWriter.WriteAttributeString("comparison", m_comparison.ToString());
            e.XmlWriter.WriteAttributeString("defaultvalue", m_defaultvalue.ToString());
            base.OnXmlWriteTag(e);
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            ReadAttributeValue(e, "filename", ref m_filename);
            ReadAttributeValue(e, "fileversion", ref m_fileversion);
            ReadAttributeValue(e, "comparison", ref m_comparison);
            ReadAttributeValue(e, "defaultvalue", ref m_defaultvalue);
            base.OnXmlReadTag(e);
        }
    }
}
