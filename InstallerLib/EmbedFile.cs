using System;
using System.Xml;
using System.ComponentModel;
using System.IO;
using System.Collections.Generic;

namespace InstallerLib
{
    /// <summary>
    /// An embedded file.
    /// </summary>
    [XmlNoChildren]
    public class EmbedFile : XmlClass
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
        [Description("Complete path where the file is located (eg. '#APPPATH\\Setup.msi').")]
        [Required]
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
        [Description("Relative path under #CABPATH where the file is going to be extracted.")]
        [Required]
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

        #region XmlClass Members

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
            ReadAttributeValue(e, "sourcefilepath", ref m_sourcefilepath);
            ReadAttributeValue(e, "targetfilepath", ref m_targetfilepath);
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

        public override Dictionary<string, EmbedFileCollection> GetFiles(string id, string supportdir)
        {
            Dictionary<string, EmbedFileCollection> files = base.GetFiles(id, supportdir);

            string normalizedId = EmbedFileCollection.GetNormalizedId(id);
            EmbedFileCollection coll = null;
            if (! files.TryGetValue(normalizedId, out coll))
            {
                coll = new EmbedFileCollection(supportdir);
                files.Add(normalizedId, coll);
            }

            coll.Add(sourcefilepath, targetfilepath);
            return files;
        }
    }
}
