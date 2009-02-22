using System;
using System.Xml;
using System.ComponentModel;
using System.ComponentModel.Design;

namespace InstallerLib
{
    /// <summary>
    /// A WebConfiguration.
    /// </summary>
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
            e.XmlWriter.WriteStartElement("configfile");
            e.XmlWriter.WriteAttributeString("filename", m_referencefile);
            e.XmlWriter.WriteEndElement();
            base.OnXmlWriteTag(e);
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            XmlElement l_ConfigFile = (XmlElement)e.XmlElement.SelectSingleNode("configfile");
            if (l_ConfigFile != null)
            {
                if (l_ConfigFile.Attributes["filename"] != null)
                    m_referencefile = l_ConfigFile.Attributes["filename"].InnerText;
            }

            base.OnXmlReadTag(e);
        }

        private string m_referencefile; // tag: configfile/@filename;
        [Description("The configuration file where the application can find the configuration. Usually this is the destination directory of the downloaded component. Can contains path constant (see Help->Path Constant). (REQUIRED)")]
        public string referencefile
        {
            get { return m_referencefile; }
            set { m_referencefile = value; }
        }
    }
}
