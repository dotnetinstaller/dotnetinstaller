using System;
using System.Xml;
using System.ComponentModel;

namespace InstallerLib
{
    /// <summary>
    /// Tag InstalledCheck
    /// </summary>
    public class InstalledCheck
    {
        public InstalledCheck(string p_type)
        {
            m_type = p_type;
        }

        #region Attributes

        private string m_type; //can be check_registry_value or check_file
        [Description("Type of the check, can be 'check_registry_value' to check for a specific value in the registry or 'check_file' to check for a specific file. (REQUIRED)")]
        public string type
        {
            get { return m_type; }
        }

        private string m_description = "Installed Check";
        [Description("Description of the check. (REQUIRED)")]
        public string description
        {
            get { return m_description; }
            set { m_description = value; OnDescriptionChanged(); }
        }

        #endregion

        protected void OnDescriptionChanged()
        {
            if (DescriptionChanged != null)
            {
                DescriptionChanged(this, EventArgs.Empty);
            }
        }

        public event EventHandler DescriptionChanged;

        #region IXmlClass Members

        public void ToXml(XmlWriter p_Writer)
        {
            p_Writer.WriteStartElement("installedcheck");
            p_Writer.WriteAttributeString("type", m_type);
            p_Writer.WriteAttributeString("description", m_description);
            OnXmlWriteTagInstalledCheck(new XmlWriterEventArgs(p_Writer));
            p_Writer.WriteEndElement();
        }

        public void FromXml(XmlElement p_Element)
        {
            if (p_Element.Attributes["type"] == null ||
                p_Element.Attributes["type"].InnerText != m_type)
                throw new ApplicationException("Invalid type");

            if (p_Element.Attributes["description"] != null)
            {
                description = p_Element.Attributes["description"].InnerText;
            }

            OnXmlReadTagInstalledCheck(new XmlElementEventArgs(p_Element));
        }
        #endregion

        protected virtual void OnXmlWriteTagInstalledCheck(XmlWriterEventArgs e)
        {
        }
        protected virtual void OnXmlReadTagInstalledCheck(XmlElementEventArgs e)
        {
        }

    }

    public enum installcheck_comparison
    {
        match,
        version,
        exists,
        contains
    }
}

