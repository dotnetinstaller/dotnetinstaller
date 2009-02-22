using System;
using System.Xml;
using System.ComponentModel;
using System.IO;

namespace InstallerLib
{
    /// <summary>
    /// A single file download.
    /// </summary>
    [XmlNoChildren]
    public class Download : XmlClassImpl
    {
        public Download()
            : this("APP_TEMP_DOWNLOADPATH")
        {
        }

        public Download(string p_DownloadPath)
        {
            m_componentname = "New Component";
            m_sourceurl = "http://www.yourwebsite.com/SetupX/Setup.exe";
            m_destinationpath = "#TEMPPATH\\" + p_DownloadPath;
            m_destinationfilename = "";
            m_alwaysdownload = true;
        }

        private string m_componentname;
        [Description("The description of the file to download. (REQUIRED)")]
        public string componentname
        {
            get { return m_componentname; }
            set { m_componentname = value; OnComponentNameChanged(EventArgs.Empty); }
        }

        private string m_sourceurl;
        [Description("The complete source path of the file to download. For example 'http://www.yourwebsite.com/SetupX/Setup.exe' . Must be URL with http:// or ftp:// protocol (REQUIRED)")]
        public string sourceurl
        {
            get { return m_sourceurl; }
            set { m_sourceurl = value; }
        }

        private string m_destinationpath;
        [Description("The complete destination path where the application copy the sourceurl file. Is recommended to use the TEMP path for destination like this: '#TEMPPATH\\APPLICATION_NAME' . Can contains path constant (see Help->Path Constant). (REQUIRED)")]
        public string destinationpath
        {
            get { return m_destinationpath; }
            set { m_destinationpath = value; }
        }

        private string m_destinationfilename;
        [Description("New name of the downloaded file. Leave this value empty to use the same filename of the original filename. (OPTIONAL)")]
        public string destinationfilename
        {
            get { return m_destinationfilename; }
            set { m_destinationfilename = value; }
        }

        // Matthew Sheets - 2007-08-28: added flag to bypass download if the file already exists locally
        private bool m_alwaysdownload;
        [Description("If true, always download the file; if false, only download if the file does not exist locally.")]
        public bool alwaysdownload
        {
            get { return m_alwaysdownload; }
            set { m_alwaysdownload = value; }
        }

        #region IXmlClass Members

        public override string XmlTag
        {
            get { return "download"; }
        }

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("componentname", m_componentname);
            e.XmlWriter.WriteAttributeString("sourceurl", m_sourceurl);
            e.XmlWriter.WriteAttributeString("destinationpath", m_destinationpath);
            e.XmlWriter.WriteAttributeString("destinationfilename", m_destinationfilename);
            e.XmlWriter.WriteAttributeString("alwaysdownload", m_alwaysdownload.ToString());
            base.OnXmlWriteTag(e);
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            if (e.XmlElement.Attributes["componentname"] != null)
                m_componentname = e.XmlElement.Attributes["componentname"].InnerText;

            if (e.XmlElement.Attributes["destinationfilename"] != null)
                m_destinationfilename = e.XmlElement.Attributes["destinationfilename"].InnerText;

            if (e.XmlElement.Attributes["destinationpath"] != null)
                m_destinationpath = e.XmlElement.Attributes["destinationpath"].InnerText;

            if (e.XmlElement.Attributes["sourceurl"] != null)
                m_sourceurl = e.XmlElement.Attributes["sourceurl"].InnerText;

            if (e.XmlElement.Attributes["alwaysdownload"] != null)
                m_alwaysdownload = bool.Parse(e.XmlElement.Attributes["alwaysdownload"].InnerText);

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

        public override EmbedFileCollection GetFiles()
        {
            EmbedFileCollection files = base.GetFiles();
            string filename = Path.Combine(destinationpath, destinationfilename);
            files.Add(new EmbedFile(filename));
            return files;
        }
    }
}
