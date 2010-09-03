using System;
using System.ComponentModel;
using System.Collections.Generic;

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

        #endregion

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("file", m_file);
            base.OnXmlWriteTag(e);
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            ReadAttributeValue(e, "file", ref m_file);
            base.OnXmlReadTag(e);
        }
    }
}
