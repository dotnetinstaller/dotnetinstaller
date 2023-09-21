using System;
using System.Xml;
using System.ComponentModel;

namespace InstallerLib
{
    /// <summary>
    /// A single file download.
    /// </summary>
    [XmlNoChildren]
    public class Download : XmlClass
    {
        public Download()
            : this("APP_TEMP_DOWNLOADPATH")
        {
        }

        public Download(string p_DownloadPath)
        {
            m_componentname = "Download File";
            m_sourceurl = "http://www.example.com/Setup/Setup.exe";
            m_destinationpath = "#TEMPPATH\\" + p_DownloadPath;
            m_destinationfilename = "";
        }

        private string m_componentname;
        [Description("Description of the file to download.")]
        [Required]
        public string componentname
        {
            get { return m_componentname; }
            set { m_componentname = value; OnComponentNameChanged(EventArgs.Empty); }
        }

        private string m_sourceurl;
        [Description("Complete source path of the file to download. For example 'http://www.example.com/SetupX/Setup.exe'. Must be URL with http:// or ftp:// protocol.")]
        [Required]
        public string sourceurl
        {
            get { return m_sourceurl; }
            set { m_sourceurl = value; }
        }

        private string m_sourcepath;
        [Description("Local source path of the file. This optional location is checked for whether the file exists before attempting a web-based download.")]
        public string sourcepath
        {
            get { return m_sourcepath; }
            set { m_sourcepath = value; }
        }

        private string m_destinationpath;
        [Description("Complete destination path where the application downloads the file. Using #TEMPPATH is recommended.")]
        [Required]
        public string destinationpath
        {
            get { return m_destinationpath; }
            set { m_destinationpath = value; }
        }

        private string m_destinationfilename;
        [Description("The destination filename or blank to keep the original filename.")]
        public string destinationfilename
        {
            get { return m_destinationfilename; }
            set { m_destinationfilename = value; }
        }

        // bypass download if the file already exists locally
        private bool m_alwaysdownload = true;
        [Description("If true, always download the file; if false, only download if the file does not exist locally.")]
        [Required]
        public bool alwaysdownload
        {
            get { return m_alwaysdownload; }
            set { m_alwaysdownload = value; }
        }

        // clear cache
        private bool m_clear_cache = false;
        [Description("If true, attempt to clear the download cache before downloading the file.")]
        [Required]
        public bool clear_cache
        {
            get { return m_clear_cache; }
            set { m_clear_cache = value; }
        }

        #region XmlClass Members

        public override string XmlTag
        {
            get { return "download"; }
        }

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("componentname", m_componentname);
            e.XmlWriter.WriteAttributeString("sourceurl", m_sourceurl);
            e.XmlWriter.WriteAttributeString("sourcepath", m_sourcepath);
            e.XmlWriter.WriteAttributeString("destinationpath", m_destinationpath);
            e.XmlWriter.WriteAttributeString("destinationfilename", m_destinationfilename);
            e.XmlWriter.WriteAttributeString("alwaysdownload", m_alwaysdownload.ToString());
            e.XmlWriter.WriteAttributeString("clear_cache", m_clear_cache.ToString());
            base.OnXmlWriteTag(e);
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            ReadAttributeValue(e, "componentname", ref m_componentname);
            ReadAttributeValue(e, "destinationfilename", ref m_destinationfilename);
            ReadAttributeValue(e, "destinationpath", ref m_destinationpath);
            ReadAttributeValue(e, "sourceurl", ref m_sourceurl);
            ReadAttributeValue(e, "sourcepath", ref m_sourcepath);
            ReadAttributeValue(e, "alwaysdownload", ref m_alwaysdownload);
            ReadAttributeValue(e, "clear_cache", ref m_clear_cache);
            base.OnXmlReadTag(e);
        }

        #endregion

        protected virtual void OnComponentNameChanged(EventArgs e)
        {
            if (ComponentNameChanged != null)
                ComponentNameChanged(this, e);
        }

        public static Download CreateFromXml(XmlElement element)
        {
            Download result = new Download();
            result.FromXml(element);
            return result;
        }

        public event EventHandler ComponentNameChanged;
    }
}
