using System;
using System.Xml;
using System.ComponentModel;
using System.Collections.Generic;
using System.IO;

namespace InstallerLib
{
    /// <summary>
    /// An embedded file.
    /// </summary>
    [XmlNoChildren]
    public class EmbedFolder : XmlClass
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
        [Description("Complete path where the folder is located.")]
        [Required]
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
        [Description("Relative path under #CABPATH where the folder is going to be extracted.")]
        [Required]
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

        #region XmlClass Members

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

        public override Dictionary<string, EmbedFileCollection> GetFiles(string id, string supportdir)
        {
            Dictionary<string, EmbedFileCollection> files = base.GetFiles(id, supportdir);

            string normalizedId = EmbedFileCollection.GetNormalizedId(id);
            EmbedFileCollection coll = null;
            if (!files.TryGetValue(normalizedId, out coll))
            {
                coll = new EmbedFileCollection(supportdir);
                files.Add(normalizedId, coll);
            }

            coll.AddDirectory(sourcefolderpath, targetfolderpath);
            return files;
        }
    }
}
