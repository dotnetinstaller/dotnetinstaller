using System;
using System.Xml;
using System.ComponentModel;

namespace InstallerLib
{
    /// <summary>
    /// Installed check operator types
    /// </summary>
    public enum InstalledCheckOperatorType
    {
        And,
        Or,
        Not
    };

    /// <summary>
    /// An installed check operator that can combine multiple checks.
    /// </summary>
    [XmlChild(typeof(InstalledCheck))]
    [XmlChild(typeof(InstalledCheckOperator))]
    public class InstalledCheckOperator : XmlClass
    {
        public InstalledCheckOperator()
        {

        }

        public InstalledCheckOperator(InstalledCheckOperatorType type)
        {
            m_type = type;
        }

        private InstalledCheckOperatorType m_type = InstalledCheckOperatorType.And;
        [Description("Type of the check operator. (REQUIRED)")]
        public InstalledCheckOperatorType type
        {
            get { return m_type; }
            set { m_type = value; OnDescriptionChanged(); }
        }

        private string m_description = "Installed Check Operator";
        [Description("Description of the check operator. (REQUIRED)")]
        public string description
        {
            get { return m_description; }
            set { m_description = value; OnDescriptionChanged(); }
        }

        #region XmlClass Members

        public override string XmlTag
        {
            get { return "installedcheckoperator"; }
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            ReadAttributeValue(e, "type", ref m_type);
            ReadAttributeValue(e, "description", ref m_description);
            base.OnXmlReadTag(e);
        }

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("type", m_type.ToString());
            e.XmlWriter.WriteAttributeString("description", m_description.ToString());
            base.OnXmlWriteTag(e);
        }

        public static InstalledCheckOperator CreateFromXml(XmlElement element)
        {
            InstalledCheckOperator result = new InstalledCheckOperator();
            result.FromXml(element);
            return result;
        }

        #endregion

        #region Events

        public event EventHandler DescriptionChanged;

        protected void OnDescriptionChanged()
        {
            if (DescriptionChanged != null)
            {
                DescriptionChanged(this, EventArgs.Empty);
            }
        }

        #endregion
    }
}

