using System;
using System.Xml;
using System.ComponentModel;

namespace InstallerLib
{
    /// <summary>
    /// Install check comparison types
    /// </summary>
    public enum installcheck_comparison
    {
        match,
        version,
        version_eq,
        version_lt,
        version_le,
        version_gt,
        version_ge,
        exists,
        contains
    }

    /// <summary>
    /// An installed check.
    /// </summary>
    [XmlNoChildren]
    public abstract class InstalledCheck : XmlClass
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

        #region XmlClass Members

        public override string XmlTag
        {
            get { return "installedcheck"; }
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            if (ReadAttributeValue(e, "description", ref m_description)) OnDescriptionChanged();
        }

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("type", m_type);
            e.XmlWriter.WriteAttributeString("description", m_description);
            base.OnXmlWriteTag(e);
        }

        #endregion

        public static InstalledCheck CreateFromXml(XmlElement element)
        {
            if (element.Attributes["type"] == null)
                throw new Exception("Missing installcheck type");

            InstalledCheck l_check;
            if (element.Attributes["type"].InnerText == "check_file")
                l_check = new InstalledCheckFile();
            else if (element.Attributes["type"].InnerText == "check_directory")
                l_check = new InstalledCheckDirectory();
            else if (element.Attributes["type"].InnerText == "check_registry_value")
                l_check = new InstalledCheckRegistry();
            else if (element.Attributes["type"].InnerText == "check_product")
                l_check = new InstalledCheckProduct();
            else
                throw new Exception(string.Format(
                    "Invalid installcheck type: {0}", element.Attributes["type"].InnerText));

            l_check.FromXml(element);
            return l_check;
        }
    }
}

