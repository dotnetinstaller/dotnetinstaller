using System;
using System.Xml;
using System.ComponentModel;
using System.Reflection;

namespace InstallerLib
{
    /// <summary>
    /// An editor for a configuration file.
    /// </summary>
    public class Editor : XmlClass
    {
        public Editor()
        {
        }

        public Editor(XmlElement element)
        {
            FromXml(element);
        }

        public static Editor CreateFromXml(XmlElement element)
        {
            return new Editor(element);
        }

        #region Attributes

        [Description("Current editor version.")]
        private Version m_current_version = Assembly.GetExecutingAssembly().GetName().Version;
        public string current_version
        {
            get { return m_current_version.ToString(); }
        }

        [Description("Loaded editor version.")]
        private string m_loaded_version = "unknown";
        public string loaded_version
        {
            get { return m_loaded_version; }
        }

        [Description("Current editor version.")]
        private string m_generator = "dotNetInstaller InstallerEditor";
        public string generator
        {
            get { return m_generator; }
        }

        #endregion

        #region XmlClass Members

        public override string XmlTag
        {
            get { return "schema"; }
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            ReadAttributeValue(e, "version", ref m_loaded_version);
            ReadAttributeValue(e, "generator", ref m_generator);
        }

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("version", m_current_version.ToString());
            e.XmlWriter.WriteAttributeString("generator", m_generator.ToString());
            base.OnXmlWriteTag(e);
        }

        #endregion

        public override string ToString()
        {
            return string.Format("{0} {1}", m_generator, m_loaded_version);
        }

        /// <summary>
        /// Returns true if the loaded file version matches the current editor version.
        /// </summary>
        /// <returns>true/false</returns>
        public bool IsCurrent()
        {
            return m_loaded_version == m_current_version.ToString();
        }
    }
}
