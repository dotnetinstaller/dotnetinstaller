using System.ComponentModel;

namespace InstallerLib
{
    [Description("A component of type 'openfile' launches a file or document using a Windows shell extension.")]
    public class ComponentOpenFile : Component
    {
        public ComponentOpenFile()
            : base("openfile", "file1")
        {
            supports_uninstall = false;
        }

        #region File

        private string m_file;
        [Description("File to open when installing or uninstalling this component. May be a file with an association or an internet URL.")]
        [Category("Open File")]
        [Required]
        public string file
        {
            get { return m_file; }
            set { m_file = value; }
        }

        private bool m_disable_wow64_fs_redirection = false;
        [Description("Indicates whether to disable wow64 file system redirection on x64 systems. Setting this option to 'true' allows the file to be opened in the native x64 application.")]
        [Category("Runtime")]
        [Required]
        public bool disable_wow64_fs_redirection
        {
            get { return m_disable_wow64_fs_redirection; }
            set { m_disable_wow64_fs_redirection = value; }
        }

        #endregion

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("file", m_file);
            e.XmlWriter.WriteAttributeString("disable_wow64_fs_redirection", m_disable_wow64_fs_redirection.ToString());
            base.OnXmlWriteTag(e);
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            ReadAttributeValue(e, "file", ref m_file);
            ReadAttributeValue(e, "disable_wow64_fs_redirection", ref m_disable_wow64_fs_redirection);
            base.OnXmlReadTag(e);
        }
    }
}
