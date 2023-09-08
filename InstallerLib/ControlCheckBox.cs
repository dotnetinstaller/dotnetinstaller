using System.ComponentModel;

namespace InstallerLib
{
    public class ControlCheckBox : ControlText
    {
        public ControlCheckBox()
            : base(ControlType.checkbox)
        {

        }

        private bool m_checked = false;
        [Description("Default check state of the checkbox.")]
        [Category("Checkbox")]
        [Required]
        public bool Checked
        {
            get { return m_checked; }
            set { m_checked = value; }
        }

        private string m_id = string.Empty;
        [Description("Control identity used to fetch user-defined value.")]
        [Category("Checkbox")]
        [Required]
        public string Id
        {
            get { return m_id; }
            set { m_id = value; }
        }

        private string m_checked_value = "1";
        [Description("Value used when the checkbox is checked.")]
        [Category("Checkbox")]
        public string CheckedValue
        {
            get { return m_checked_value; }
            set { m_checked_value = value; }
        }

        private string m_unchecked_value = "0";
        [Description("Value used when the checkbox is unchecked.")]
        [Category("Checkbox")]
        public string UncheckedValue
        {
            get { return m_unchecked_value; }
            set { m_unchecked_value = value; }
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            ReadAttributeValue(e, "id", ref m_id);
            ReadAttributeValue(e, "checked", ref m_checked);
            ReadAttributeValue(e, "checked_value", ref m_checked_value);
            ReadAttributeValue(e, "unchecked_value", ref m_unchecked_value);
            base.OnXmlReadTag(e);
        }

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            base.OnXmlWriteTag(e);
            e.XmlWriter.WriteAttributeString("checked", m_checked.ToString());
            e.XmlWriter.WriteAttributeString("checked_value", m_checked_value.ToString());
            e.XmlWriter.WriteAttributeString("unchecked_value", m_unchecked_value.ToString());
            e.XmlWriter.WriteAttributeString("id", m_id);
        }
    }
}
