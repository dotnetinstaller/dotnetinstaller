using System;
using System.Xml;
using System.ComponentModel;

namespace InstallerLib
{
    public enum InstalledCheckOperatorType
    {
        And,
        Or,
        Not
    };

    /// <summary>
    /// An installed check operator that can combine multiple checks.
    /// </summary>
    public class InstalledCheckOperator
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

        private InstalledCheckCollection m_installedchecks = new InstalledCheckCollection();
        [System.ComponentModel.Browsable(false)]
        public InstalledCheckCollection installedchecks
        {
            get { return m_installedchecks; }
            set { m_installedchecks = value; }
        }

        private InstalledCheckOperatorCollection m_installedcheckoperators = new InstalledCheckOperatorCollection();
        [System.ComponentModel.Browsable(false)]
        public InstalledCheckOperatorCollection installedcheckoperators
        {
            get { return m_installedcheckoperators; }
            set { m_installedcheckoperators = value; }
        }

        #region IXmlClass Members

        public void ToXml(XmlWriter p_Writer)
        {
            p_Writer.WriteStartElement("installedcheckoperator");
            p_Writer.WriteAttributeString("type", m_type.ToString());
            p_Writer.WriteAttributeString("description", m_description.ToString());

            foreach (InstalledCheck i in installedchecks)
            {
                i.ToXml(p_Writer);
            }

            foreach (InstalledCheckOperator op in installedcheckoperators)
            {
                op.ToXml(p_Writer);
            }

            p_Writer.WriteEndElement();
        }

        public void FromXml(XmlElement p_Element)
        {
            if (p_Element.Attributes["type"] != null)
            {
                m_type = (InstalledCheckOperatorType)Enum.Parse(
                    typeof(InstalledCheckOperatorType), p_Element.Attributes["type"].InnerText);
            }

            if (p_Element.Attributes["description"] != null)
            {
                m_description = p_Element.Attributes["description"].InnerText;
            }

            XmlNodeList l_InstalledChecksList = p_Element.SelectNodes("installedcheck");
            foreach (XmlElement l in l_InstalledChecksList)
            {
                if (l.Attributes["type"] != null)
                {
                    InstalledCheck l_check = null;
                    if (l.Attributes["type"].InnerText == "check_file")
                        l_check = new InstalledCheckFile();
                    else if (l.Attributes["type"].InnerText == "check_registry_value")
                        l_check = new InstalledCheckRegistry();
                    else
                        throw new ApplicationException("Invalid type");

                    l_check.FromXml(l);
                    installedchecks.Add(l_check);
                }
            }

            XmlNodeList l_InstalledCheckOperatorsList = p_Element.SelectNodes("installedcheckoperator");
            foreach (XmlElement l in l_InstalledCheckOperatorsList)
            {
                InstalledCheckOperator op = new InstalledCheckOperator();
                op.FromXml(l);
                installedcheckoperators.Add(op);
            }
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

