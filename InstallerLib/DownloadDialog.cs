using System.Xml;
using System.ComponentModel;
using System.ComponentModel.Design;
using System.Drawing.Design;

namespace InstallerLib
{
    /// <summary>
    /// A download dialog that contains one or more download files.
    /// </summary>
    [XmlChild(typeof(Download))]
    public class DownloadDialog : XmlClass
    {
        public DownloadDialog()
            : this("COMPONENT_NAME")
        {

        }

        public DownloadDialog(string p_ComponentName)
        {
            Template.Template_downloaddialog tpl = Template.CurrentTemplate.downloaddialog(p_ComponentName);

            m_buttoncancel_caption = tpl.buttoncancel_caption;
            m_buttonstart_caption = tpl.buttonstart_caption;
            m_dialog_caption = tpl.dialog_caption;
            m_dialog_message = tpl.dialog_message;
            m_dialog_message_downloading = tpl.dialog_message_downloading;
            m_dialog_message_copying = tpl.dialog_message_copying;
            m_dialog_message_connecting = tpl.dialog_message_connecting;
            m_dialog_message_sendingrequest = tpl.dialog_message_sendingrequest;
        }

        #region Attributes
        private string m_dialog_caption;
        [Description("Caption of the download dialog.")]
        public string dialog_caption
        {
            get { return m_dialog_caption; }
            set { m_dialog_caption = value; }
        }

        private string m_dialog_message;
        [Description("Initial message that appears in the download dialog before the user presses the 'Start' button.")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string dialog_message
        {
            get { return m_dialog_message; }
            set { m_dialog_message = value; }
        }

        private bool m_autostartdownload = true;
        [Description("Set to 'true' to start the download without user interaction, 'false' to require the user to press the 'Start' button.")]
        [Required]
        public bool autostartdownload
        {
            get { return m_autostartdownload; }
            set { m_autostartdownload = value; }
        }

        private string m_dialog_message_connecting;
        [Description("Message that appears in the download dialog when the download process initiates a connection to a remote host.")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string dialog_message_connecting
        {
            get { return m_dialog_message_connecting; }
            set { m_dialog_message_connecting = value; }
        }

        private string m_dialog_message_sendingrequest;
        [Description("Message that appears in the download dialog when the download process sends an HTTP request to a remote host.")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string dialog_message_sendingrequest
        {
            get { return m_dialog_message_sendingrequest; }
            set { m_dialog_message_sendingrequest = value; }
        }

        private string m_dialog_message_downloading;
        [Description("Message that appears in the download dialog when the download process starts.")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string dialog_message_downloading
        {
            get { return m_dialog_message_downloading; }
            set { m_dialog_message_downloading = value; }
        }

        private string m_dialog_message_copying;
        [Description("Message that appears in the download dialog when a local copy process starts.")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string dialog_message_copying
        {
            get { return m_dialog_message_copying; }
            set { m_dialog_message_copying = value; }
        }

        private string m_buttonstart_caption;
        [Description("Caption of the 'Start' button.")]
        public string buttonstart_caption
        {
            get { return m_buttonstart_caption; }
            set { m_buttonstart_caption = value; }
        }

        private string m_buttoncancel_caption;
        [Description("Caption of the 'Cancel' button.")]
        public string buttoncancel_caption
        {
            get { return m_buttoncancel_caption; }
            set { m_buttoncancel_caption = value; }
        }
        #endregion

        #region XmlClass Members

        public override string XmlTag
        {
            get { return "downloaddialog"; }
        }

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("dialog_caption", m_dialog_caption);
            e.XmlWriter.WriteAttributeString("dialog_message", m_dialog_message);
            e.XmlWriter.WriteAttributeString("dialog_message_downloading", m_dialog_message_downloading);
            e.XmlWriter.WriteAttributeString("dialog_message_copying", m_dialog_message_copying);
            e.XmlWriter.WriteAttributeString("dialog_message_connecting", m_dialog_message_connecting);
            e.XmlWriter.WriteAttributeString("dialog_message_sendingrequest", m_dialog_message_sendingrequest);
            e.XmlWriter.WriteAttributeString("autostartdownload", m_autostartdownload.ToString());
            e.XmlWriter.WriteAttributeString("buttonstart_caption", m_buttonstart_caption);
            e.XmlWriter.WriteAttributeString("buttoncancel_caption", m_buttoncancel_caption);
            base.OnXmlWriteTag(e);
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            ReadAttributeValue(e, "autostartdownload", ref m_autostartdownload);
            ReadAttributeValue(e, "buttoncancel_caption", ref m_buttoncancel_caption);
            ReadAttributeValue(e, "buttonstart_caption", ref m_buttonstart_caption);
            ReadAttributeValue(e, "dialog_caption", ref m_dialog_caption);
            ReadAttributeValue(e, "dialog_message", ref m_dialog_message);
            ReadAttributeValue(e, "dialog_message_downloading", ref m_dialog_message_downloading);
            ReadAttributeValue(e, "dialog_message_copying", ref m_dialog_message_copying);
            ReadAttributeValue(e, "dialog_message_connecting", ref m_dialog_message_connecting);
            ReadAttributeValue(e, "dialog_message_sendingrequest", ref m_dialog_message_sendingrequest);
            base.OnXmlReadTag(e);
        }

        #endregion

        public static DownloadDialog CreateFromXml(XmlElement element)
        {
            DownloadDialog result = new DownloadDialog();
            result.FromXml(element);
            return result;
        }
    }
}
