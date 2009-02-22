using System;
using System.Xml;
using System.ComponentModel;
using System.Collections.Generic;
using System.IO;

namespace InstallerLib
{
    /// <summary>
    /// Summary description for FileAttribute.
    /// </summary>
    public class FileAttribute : IXmlClass
    {
        public FileAttribute()
        {
        }

        #region Attributes
        private string m_name;
        [Description("The name of the file attribute (REQUIRED)")]
        public string name
        {
            get { return m_name; }
            set { m_name = value; }
        }

        private string m_value = null;
        [Description("The value of the file attribute (OPTIONAL)")]
        public string value
        {
            get { return m_value; }
            set { m_value = value; }
        }

        public string data
        {
            get
            {
                return (m_value != null) 
                    ? string.Format("{0}\0", m_value.Trim('\0')) 
                    : null;
            }
        }

        #endregion

        #region IXmlClass Members

        public void ToXml(XmlWriter p_Writer)
        {
            p_Writer.WriteStartElement("fileattribute");
            OnXmlWriteTagcomponent(new XmlWriterEventArgs(p_Writer));
            p_Writer.WriteEndElement();
        }

        public void FromXml(XmlElement p_Element)
        {
            OnXmlReadTagcomponent(new XmlElementEventArgs(p_Element));
        }

        #endregion

        protected virtual void OnXmlWriteTagcomponent(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("name", m_name);
            if (m_value != null) e.XmlWriter.WriteAttributeString("value", m_value);
        }

        protected virtual void OnXmlReadTagcomponent(XmlElementEventArgs e)
        {
            if (e.XmlElement.Attributes["name"] != null)
                m_name = e.XmlElement.Attributes["name"].InnerText;

            if (e.XmlElement.Attributes["value"] != null)
                m_value = e.XmlElement.Attributes["value"].InnerText;
        }

        public override string ToString()
        {
            return m_name;
        }
    }
}
