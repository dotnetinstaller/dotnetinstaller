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
    public class EmbedFolder : XmlClassImpl
    {
        public EmbedFolder()
            : this("EmbedFolder")
        {

        }

        [Browsable(false)]
        public string Name
        {
            get
            {
                return Path.GetFileName(sourcefolderpath);
            }
        }

        public EmbedFolder(string path)
        {
            m_sourcefolderpath = path;
        }

        public EmbedFolder(string sourcepath, string targetpath)
        {
            m_sourcefolderpath = sourcepath;
            m_targetfolderpath = targetpath;
        }

        private string m_sourcefolderpath;
        [Description("The complete or relative path where the file is located. Can contains path constants (see Help->Path Constant). (REQUIRED)")]
        public string sourcefolderpath
        {
            get
            {
                return m_sourcefolderpath;
            }
            set
            {
                m_sourcefolderpath = value;
                OnSourceFilePathChanged(EventArgs.Empty);
            }
        }

        private string m_targetfolderpath;
        [Description("The relative path under #CABPATH where the file is going to be extracted. (REQUIRED)")]
        public string targetfolderpath
        {
            get
            {
                return m_targetfolderpath;
            }
            set
            {
                m_targetfolderpath = value;
            }
        }

        #region IXmlClass Members

        public override string XmlTag
        {
            get { return "embedfolder"; }
        }

        #endregion

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("sourcefolderpath", m_sourcefolderpath);
            e.XmlWriter.WriteAttributeString("targetfolderpath", m_targetfolderpath);
            base.OnXmlWriteTag(e);
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            ReadAttributeValue(e, "sourcefolderpath", ref m_sourcefolderpath);
            ReadAttributeValue(e, "targetfolderpath", ref m_targetfolderpath);
            base.OnXmlReadTag(e);
        }

        protected virtual void OnSourceFilePathChanged(EventArgs e)
        {
            if (SourceFilePathChanged != null)
            {
                SourceFilePathChanged(this, e);
            }
        }

        public static EmbedFolder CreateFromXml(XmlElement element)
        {
            EmbedFolder result = new EmbedFolder();
            result.FromXml(element);
            return result;
        }

        public event EventHandler SourceFilePathChanged;

        public override EmbedFileCollection GetFiles(string supportfiles)
        {
            EmbedFileCollection fileCollection = base.GetFiles(supportfiles);
            fileCollection.AddDirectory(sourcefolderpath, targetfolderpath);
            return fileCollection;
        }
    }
}
