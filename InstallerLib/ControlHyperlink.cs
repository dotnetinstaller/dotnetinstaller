using System;
using System.Collections.Generic;
using System.Text;
using System.ComponentModel;
using System.ComponentModel.Design;
using System.Drawing.Design;

namespace InstallerLib
{
    public class ControlHyperlink : ControlText
    {
        public ControlHyperlink()
            : base(ControlType.hyperlink)
        {

        }

        private string m_uri = "http://dotnetinstaller.codeplex.com";
        [Description("An url or a local file.")]
        [Category("Hyperlink")]
        public string Uri
        {
            get { return m_uri; }
            set { m_uri = value; }
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            ReadAttributeValue(e, "uri", ref m_uri);
            base.OnXmlReadTag(e);
        }

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            base.OnXmlWriteTag(e);
            e.XmlWriter.WriteAttributeString("uri", m_uri);
        }
    }
}
