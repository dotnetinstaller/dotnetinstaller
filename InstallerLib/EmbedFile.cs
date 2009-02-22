using System;
using System.Xml;
using System.ComponentModel;
using System.IO;

namespace InstallerLib
{
    /// <summary>
    /// An embedded file.
    /// </summary>
    [XmlNoChildren]
    public class EmbedFile : XmlClassImpl
    {
        public EmbedFile()
            : this("EmbedFile")
        {

        }

        [Browsable(false)]
        public string Name
        {
            get
            {
                return Path.GetFileName(sourcefilepath);
            }
        }

        public EmbedFile(string path)
        {
            m_sourcefilepath = path;
        }

        public EmbedFile(string sourcepath, string targetpath)
        {
            m_sourcefilepath = sourcepath;
            m_targetfilepath = targetpath;
        }

        private string m_sourcefilepath;
        [Description("The complete path where the file is located. Is recommended to use the APPPATH path: '#APPPATH\\Setup.msi'. Can contains path constants (see Help->Path Constant). (REQUIRED)")]
        public string sourcefilepath
        {
            get
            {
                return m_sourcefilepath;
            }
            set
            {
                m_sourcefilepath = value;
                OnSourceFilePathChanged(EventArgs.Empty);
            }
        }

        private string m_targetfilepath;
        [Description("The relative path under #CABPATH where the file is going to be extracted. (REQUIRED)")]
        public string targetfilepath
        {
            get
            {
                return m_targetfilepath;
            }
            set
            {
                m_targetfilepath = value;
            }
        }

        #region IXmlClass Members

        public override string XmlTag
        {
            get { return "embedfile"; }
        }

        #endregion

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("sourcefilepath", m_sourcefilepath);
            e.XmlWriter.WriteAttributeString("targetfilepath", m_targetfilepath);
            base.OnXmlWriteTag(e);
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            if (e.XmlElement.Attributes["sourcefilepath"] != null)
                m_sourcefilepath = e.XmlElement.Attributes["sourcefilepath"].InnerText;

            if (e.XmlElement.Attributes["targetfilepath"] != null)
                m_targetfilepath = e.XmlElement.Attributes["targetfilepath"].InnerText;

            base.OnXmlReadTag(e);
        }

        protected virtual void OnSourceFilePathChanged(EventArgs e)
        {
            if (SourceFilePathChanged != null)
            {
                SourceFilePathChanged(this, e);
            }
        }

        public static EmbedFile CreateFromXml(XmlElement element)
        {
            EmbedFile result = new EmbedFile();
            result.FromXml(element);
            return result;
        }

        public event EventHandler SourceFilePathChanged;
    }
}
