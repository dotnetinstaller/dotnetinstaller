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

        private bool m_embed = true;
        [Description("Automatically embed file when building a packaged setup.")]
        public bool embed
        {
            get { return m_embed; }
            set { m_embed = value; }
        }

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("file", m_file);
            e.XmlWriter.WriteAttributeString("embed", m_embed.ToString());
            base.OnXmlWriteTag(e);
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            if (e.XmlElement.Attributes["file"] != null)
                m_file = e.XmlElement.Attributes["file"].InnerText;

            if (e.XmlElement.Attributes["embed"] != null)
                m_embed = bool.Parse(e.XmlElement.Attributes["embed"].InnerText);

            base.OnXmlReadTag(e);
        }

        public override EmbedFileCollection GetFiles()
        {
            EmbedFileCollection files = base.GetFiles();
            if (embed) files.Add(new EmbedFile(m_file));
            return files;
        }
    }
}
