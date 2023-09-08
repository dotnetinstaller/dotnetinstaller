using System.Xml;
using System.ComponentModel;

namespace InstallerLib
{
    /// <summary>
    /// A WebConfiguration.
    /// </summary>
    [XmlChild(typeof(DownloadDialog), Max = 1)]
    public class WebConfiguration : Configuration
    {
        public WebConfiguration()
            : this("APPLICATION_NAME")
        {

        }

        public WebConfiguration(string p_ApplicationName)
            : base("reference")
        {
            m_referencefile = "#TEMPPATH\\" + p_ApplicationName + "\\configuration.xml";
        }

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            base.OnXmlWriteTag(e);
            e.XmlWriter.WriteStartElement("configfile");
            e.XmlWriter.WriteAttributeString("filename", m_referencefile);
            e.XmlWriter.WriteEndElement();
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            base.OnXmlReadTag(e);
        }

        protected override bool OnXmlChild(XmlElement child)
        {
            bool processed = false;
            switch (child.LocalName)
            {
                case "configfile":
                    m_referencefile = child.Attributes["filename"].InnerText;
                    processed = true;
                    break;
                default:
                    break;
            }
            return processed;
        }

        private string m_referencefile;
        [Description("The configuration file where the application can find the configuration. Usually this is the destination directory of the downloaded component.")]
        [Required]
        public string referencefile
        {
            get { return m_referencefile; }
            set { m_referencefile = value; }
        }
    }
}
