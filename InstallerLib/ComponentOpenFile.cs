using System;
using System.ComponentModel;
using System.Collections.Generic;

namespace InstallerLib
{
    /// <summary>
    /// A component of type "openfile" that launches a document.
    /// </summary>
    public class ComponentOpenFile : Component
    {
        public ComponentOpenFile()
            : base("openfile")
        {
        }

        private string m_file;
        [Description("Specifies the file to open when installing this component. Can contain \" char and path constant (see Help->Path Constant). Can be for example a internet link. (REQUIRED)")]
        public string file
        {
            get { return m_file; }
            set { m_file = value; }
        }

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
