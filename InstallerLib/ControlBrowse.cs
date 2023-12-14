using System.ComponentModel;

namespace InstallerLib
{
    public class ControlBrowse : ControlText
    {
        public ControlBrowse()
            : base(ControlType.browse)
        {

        }

        private string m_id = string.Empty;
        [Description("Control identity used to fetch user-selected value.")]
        [Category("Browse")]
        [Required]
        public string Id
        {
            get { return m_id; }
            set { m_id = value; }
        }

        private string m_filter = "All Files (*.*)|*.*";
        [Description("Browse filter.")]
        [Category("Browse")]
        [Required]
        public string Filter
        {
            get { return m_filter; }
            set { m_filter = value; }
        }

        private string m_button_text = string.Empty;
        [Description("Browse button text.")]
        [Category("Browse")]
        public string ButtonText
        {
            get { return m_button_text; }
            set { m_button_text = value; }
        }

        private bool m_folders_only = true;
        [Description("Browse folders only (no files).")]
        [Category("Browse")]
        [Required]
        public bool FoldersOnly
        {
            get { return m_folders_only; }
            set { m_folders_only = value; }
        }

        private bool m_must_exist = false;
        [Description("Selected file or folder must exist.")]
        [Category("Browse")]
        [Required]
        public bool MustExist
        {
            get { return m_must_exist; }
            set { m_must_exist = value; }
        }

        private bool m_allow_edit = true;
        [Description("Allows user to type in the editbox.")]
        [Category("Browse")]
        [Required]
        public bool AllowEdit
        {
            get { return m_allow_edit; }
            set { m_allow_edit = value; }
        }

        private bool m_hide_readonly = false;
        [Description("Hide read-only folders and files.")]
        [Category("Browse")]
        [Required]
        public bool HideReadOnly
        {
            get { return m_hide_readonly; }
            set { m_hide_readonly = value; }
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            ReadAttributeValue(e, "id", ref m_id);
            ReadAttributeValue(e, "hide_readonly", ref m_hide_readonly);
            ReadAttributeValue(e, "must_exist", ref m_must_exist);
            ReadAttributeValue(e, "folders_only", ref m_folders_only);
            ReadAttributeValue(e, "button_text", ref m_button_text);
            ReadAttributeValue(e, "filter", ref m_filter);
            ReadAttributeValue(e, "allow_edit", ref m_allow_edit);
            base.OnXmlReadTag(e);
        }

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            base.OnXmlWriteTag(e);
            e.XmlWriter.WriteAttributeString("id", m_id);
            e.XmlWriter.WriteAttributeString("hide_readonly", m_hide_readonly.ToString());
            e.XmlWriter.WriteAttributeString("must_exist", m_must_exist.ToString());
            e.XmlWriter.WriteAttributeString("folders_only", m_folders_only.ToString());
            e.XmlWriter.WriteAttributeString("button_text", m_button_text);
            e.XmlWriter.WriteAttributeString("allow_edit", m_allow_edit.ToString());
            e.XmlWriter.WriteAttributeString("filter", m_filter);
        }
    }
}
