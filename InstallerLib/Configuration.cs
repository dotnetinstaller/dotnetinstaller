using System;
using System.Xml;
using System.ComponentModel;
using System.Collections.Generic;

namespace InstallerLib
{
    /// <summary>
    /// tag: configuration
    /// </summary>
    public abstract class Configuration : IXmlClass
    {
        public Configuration(string p_type)
        {
            m_type = p_type;

            m_lcid = "";
        }

        #region Configuration Prop
        private string m_lcid;
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

        public void ToXml(XmlWriter p_Writer)
        {
            p_Writer.WriteStartElement("configuration");
            p_Writer.WriteAttributeString("type", m_type);
            p_Writer.WriteAttributeString("lcid", m_lcid);

            OnXmlWriteTagConfiguration(new XmlWriterEventArgs(p_Writer));

            p_Writer.WriteEndElement();
        }

        public void FromXml(XmlElement p_Element)
        {
            if (p_Element.Attributes["type"] == null ||
                p_Element.Attributes["type"].InnerText != m_type)
                throw new ApplicationException("Invalid type");
            if (p_Element.Attributes["lcid"] != null)
                lcid = p_Element.Attributes["lcid"].InnerText;

            OnXmlReadTagConfiguration(new XmlElementEventArgs(p_Element));
        }
        #endregion

        protected virtual void OnXmlWriteTagConfiguration(XmlWriterEventArgs e)
        {
        }

        protected virtual void OnXmlReadTagConfiguration(XmlElementEventArgs e)
        {
        }

        public virtual EmbedFileCollection GetFiles()
        {
            return new EmbedFileCollection();
        }
    }
}
