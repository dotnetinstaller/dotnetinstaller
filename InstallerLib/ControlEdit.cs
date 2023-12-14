using System.ComponentModel;

namespace InstallerLib
{
    public class ControlEdit : ControlText
    {
        public ControlEdit()
            : base(ControlType.edit)
        {

        }

        private string m_id = string.Empty;
        [Description("Control identity used to fetch user-defined value.")]
        [Category("Edit")]
        [Required]
        public string Id
        {
            get { return m_id; }
            set { m_id = value; }
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            ReadAttributeValue(e, "id", ref m_id);
            base.OnXmlReadTag(e);
        }

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            base.OnXmlWriteTag(e);
            e.XmlWriter.WriteAttributeString("id", m_id);
        }
    }
}
