using System.ComponentModel;

namespace InstallerLib
{
    public class InstalledCheckWmi : InstalledCheck
    {
        public InstalledCheckWmi()
            : base("check_wmi")
        {
        }

        private string m_query;
        [Description("The WMI Query Language (WQL) statement to execute.")]
        public string query
        {
            get { return m_query; }
            set { m_query = value; }
        }

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("query", m_query);
            base.OnXmlWriteTag(e);
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            ReadAttributeValue(e, "query", ref m_query);
            base.OnXmlReadTag(e);
        }
    }
}
