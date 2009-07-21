using System;
using System.ComponentModel;

namespace InstallerLib
{
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
        [Description("Specifies the path to search, if the application cannot find the specified path then the component must be installed. This attribute can contain path constants. (REQUIRED)")]
        public string path
        {
            get { return m_path; }
            set { m_path = value; }
        }

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("path", m_path);
            base.OnXmlWriteTag(e);
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            ReadAttributeValue(e, "path", ref m_path);
            base.OnXmlReadTag(e);
        }
    }
}
