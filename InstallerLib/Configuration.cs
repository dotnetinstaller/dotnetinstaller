using System;
using System.Xml;
using System.ComponentModel;
using System.Collections.Generic;

namespace InstallerLib
{
    /// <summary>
    /// A configuration.
    /// </summary>
    public abstract class Configuration : XmlClassImpl
    {
        public Configuration(string p_type)
        {
            m_type = p_type;
        }

        #region Configuration Prop
        private string m_lcid = string.Empty;
        [Description("A filter to install this configuration only on all operating system language equals or not equals than the LCID specified (see Help->LCID Table). Separate multiple LCID with comma (',') and use not symbol ('!') for NOT logic (es. '1044,1033,!1038' ). You can also filter a specified component. (OPTIONAL)")]
        public string lcid
        {
            get { return m_lcid; }
            set { m_lcid = value; OnLCIDChanged(); }
        }

        private string m_type;
        [Description("Type of the configuration. Can be 'install' or 'reference'. (REQUIRED)")]
        public string type
        {
            get { return m_type; }
        }

        #endregion

        public override string ToString()
        {
            return m_type + ":" + m_lcid;
        }

        protected void OnLCIDChanged()
        {
            if (LCIDChanged != null)
                LCIDChanged(this, EventArgs.Empty);
        }

        public event EventHandler LCIDChanged;

        #region IXmlClass Members

        public override string XmlTag
        {
            get { return "configuration"; }
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            if (ReadAttributeValue(e, "lcid", ref m_lcid)) OnLCIDChanged();
        }

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("type", m_type);
            e.XmlWriter.WriteAttributeString("lcid", m_lcid);
            base.OnXmlWriteTag(e);
        }

        public static Configuration CreateFromXml(XmlElement element)
        {
            Configuration l_Config;
            XmlAttribute xmltypeAttribute = element.Attributes["type"];
            if (xmltypeAttribute == null)
            {
                throw new Exception(string.Format("Missing configuration type at \"{0}\".", element.Name));
            }

            string xmltype = xmltypeAttribute.InnerText;
            switch (xmltype)
            {
                case "install":
                    l_Config = new SetupConfiguration();
                    break;
                case "reference":
                    l_Config = new WebConfiguration();
                    break;
                default:
                    throw new Exception(string.Format("Invalid configuration type: {0}", xmltype));
            }
            
            l_Config.FromXml(element);
            return l_Config;
        }

        #endregion
    }
}
