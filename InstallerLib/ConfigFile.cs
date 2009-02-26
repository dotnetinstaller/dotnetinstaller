using System;
using System.ComponentModel;
using System.Xml;
using System.Collections.Specialized;

namespace InstallerLib
{
    /// <summary>
    /// A configuration file.
    /// </summary>
    [XmlChild(typeof(WebConfiguration))]
    [XmlChild(typeof(SetupConfiguration))]
    public class ConfigFile : XmlClassImpl
    {
        public ConfigFile()
        {
        }

        private string m_filename = null;
        public string filename
        {
            get { return m_filename; }
            set { m_filename = value; }
        }

        private bool m_silent_install = false;
        [Description("If true, run the install silently (without end-user input)")]
        [Category("Installation Runtime")]
        public bool silent_install
        {
            get { return m_silent_install; }
            set { m_silent_install = value; }
        }

        private string m_fileversion;
        [Description("Four-part binary file version, eg. 1.2.3.4")]
        [Category("File Attributes")]
        public string fileversion
        {
            get { return m_fileversion; }
            set { m_fileversion = value; }
        }

        private string m_productversion;
        [Description("Four-part binary product version, eg. 1.2.3.4")]
        [Category("File Attributes")]
        public string productversion
        {
            get { return m_productversion; }
            set { m_productversion = value; }
        }

        private FileAttributeCollection m_fileattributes = new FileAttributeCollection();
        [Description("attributes")]
        [Category("File Attributes")]
        public FileAttributeCollection fileattributes
        {
            get { return m_fileattributes; }
            set { m_fileattributes = value; }
        }

        public void Save()
        {
            if (m_filename == null)
                throw new Exception("Invalid save filename");

            SaveAs(m_filename);
        }

        public void SaveAs(string p_FileName)
        {
            XmlTextWriter l_XmlWriter = new XmlTextWriter(p_FileName, System.Text.Encoding.UTF8);
            l_XmlWriter.Formatting = Formatting.Indented;
            try
            {
                l_XmlWriter.WriteStartDocument();
                ToXml(l_XmlWriter);
            }
            finally
            {
                l_XmlWriter.Close();
            }
            m_filename = p_FileName;
        }

        public override string XmlTag
        {
            get { return "configurations"; }
        }

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            // silent install
            e.XmlWriter.WriteAttributeString("silent_install", m_silent_install.ToString());
            // version information
            e.XmlWriter.WriteAttributeString("fileversion", m_fileversion);
            e.XmlWriter.WriteAttributeString("productversion", m_productversion);
            // tag schema
            e.XmlWriter.WriteStartElement("schema");
            e.XmlWriter.WriteAttributeString("version", m_CurrentSchemaVersion.ToString());
            e.XmlWriter.WriteEndElement();
            fileattributes.ToXml(e.XmlWriter);
            base.OnXmlWriteTag(e);
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            // silent install
            if (e.XmlElement.Attributes["silent_install"] != null)
                m_silent_install = bool.Parse(e.XmlElement.Attributes["silent_install"].InnerText);

            // version information
            if (e.XmlElement.Attributes["fileversion"] != null)
                m_fileversion = e.XmlElement.Attributes["fileversion"].InnerText;
            if (e.XmlElement.Attributes["productversion"] != null)
                m_productversion = e.XmlElement.Attributes["productversion"].InnerText;

            base.OnXmlReadTag(e);
        }

        protected override bool OnXmlChild(XmlElement child)
        {
            bool processed = false;
            switch (child.LocalName)
            {
                case "schema":
                    // ignore schema, currently schemas are backwards compatible
                    processed = true;
                    break;
                case "fileattributes":
                    fileattributes.FromXml(child);
                    processed = true;
                    break;
                case "configurations":
                    FromXml(child);
                    processed = true;
                    break;
                default:
                    break;
            }
            return processed;
        }

        public void Create(string p_FileName)
        {
            m_filename = p_FileName;
        }

        public void Load(string p_FileName)
        {
            XmlDocument l_XmlElement = new XmlDocument();
            l_XmlElement.Load(p_FileName);
            XmlNode l_Configurations = l_XmlElement.SelectSingleNode("//configurations");
            base.FromXml((XmlElement)l_Configurations);
            m_filename = p_FileName;
        }

        private static int m_CurrentSchemaVersion = 1;

        /// <summary>
        /// Returns true is the specified filename match the current schema version.
        /// </summary>
        /// <returns></returns>
        public bool IsCurrentSchemaVersion(string p_FileName, out string p_CheckDesription)
        {
            XmlDocument l_XmlElement = new XmlDocument();
            l_XmlElement.Load(p_FileName);

            XmlNode l_SchemaNode = l_XmlElement.SelectSingleNode("//configurations/schema");

            if (l_SchemaNode == null || l_SchemaNode.Attributes["version"] == null)
            {
                p_CheckDesription = "Node //configurations/schema or attribute version not found";
                return false;
            }
            else
            {
                try
                {
                    int l_Version = int.Parse(l_SchemaNode.Attributes["version"].InnerText);
                    if (l_Version < m_CurrentSchemaVersion)
                    {
                        p_CheckDesription = "Version is smaller than editor schema version";
                        return false;
                    }
                    else if (l_Version > m_CurrentSchemaVersion)
                    {
                        p_CheckDesription = "Version is grater than editor schema version";
                        return false;
                    }
                    else
                    {
                        p_CheckDesription = "Version Checked";
                        return true;
                    }
                }
                catch (Exception err)
                {
                    p_CheckDesription = "Failed to parse version: " + err.Message;
                    return false;
                }
            }
        }
    }
}
