using System;
using System.ComponentModel;
using System.Xml;
using System.Collections.Specialized;

namespace InstallerEditor
{
    /// <summary>
    /// Summary description for ConfigFile.
    /// </summary>
    public class ConfigFile
    {
        public ConfigFile()
        {
        }

        private string m_FileName = null;
        public string FileName
        {
            get { return m_FileName; }
            set { m_FileName = value; }
        }

        /* Matthew Sheets - 2007-09-20: added flag for silent install */
        private bool m_silent_install = false;
        [Description("If true, run the install silently (without end-user input)")]
        [Category("Installation Runtime")]
        public bool silent_install
        {
            get { return m_silent_install; }
            set { m_silent_install = value; }
        }

        /* Daniel Doubrovkine - 2008-06-27: added version information */
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
            if (m_FileName == null)
                throw new ApplicationException("Invalid save filename");

            SaveAs(m_FileName);
        }

        public void SaveAs(string p_FileName)
        {
            XmlTextWriter l_XmlWriter = new XmlTextWriter(p_FileName, System.Text.Encoding.UTF8);
            try
            {
                l_XmlWriter.Formatting = Formatting.Indented;
                l_XmlWriter.WriteStartDocument();

                l_XmlWriter.WriteStartElement("configurations");

                /* Matthew Sheets - 2007-08-10: added flag for silent install */
                l_XmlWriter.WriteAttributeString("silent_install", m_silent_install.ToString());

                /* Daniel Doubrovkine - 2008-06-27: added version information */
                l_XmlWriter.WriteAttributeString("fileversion", m_fileversion);
                l_XmlWriter.WriteAttributeString("productversion", m_productversion);

                //tag schema
                l_XmlWriter.WriteStartElement("schema");
                l_XmlWriter.WriteAttributeString("version", m_CurrentSchemaVersion.ToString());
                l_XmlWriter.WriteEndElement();

                l_XmlWriter.WriteStartElement("fileattributes");
                foreach (FileAttribute a in fileattributes)
                {
                    a.ToXml(l_XmlWriter);
                }
                l_XmlWriter.WriteEndElement();

                foreach (Configuration c in Configurations)
                {
                    c.ToXml(l_XmlWriter);
                }

                l_XmlWriter.WriteEndElement();

                m_FileName = p_FileName;
            }
            finally
            {
                l_XmlWriter.Close();
            }
        }

        public void Create(string p_FileName)
        {
            m_FileName = p_FileName;
        }

        public void Load(string p_FileName)
        {
            XmlDocument l_XmlElement = new XmlDocument();
            l_XmlElement.Load(p_FileName);

            XmlNode l_Configurations = l_XmlElement.SelectSingleNode("//configurations");

            /* Matthew Sheets - 2007-09-20: added flag for silent install */
            if (l_Configurations.Attributes["silent_install"] != null)
                m_silent_install = bool.Parse(l_Configurations.Attributes["silent_install"].InnerText);

            /* Daniel Doubrovkine - 2008-06-27: added version information */
            if (l_Configurations.Attributes["fileversion"] != null)
                m_fileversion = l_Configurations.Attributes["fileversion"].InnerText;
            if (l_Configurations.Attributes["productversion"] != null)
                m_productversion = l_Configurations.Attributes["productversion"].InnerText;

            XmlNodeList l_FileAttributesList = l_XmlElement.SelectNodes("//fileattributes/fileattribute");
            foreach (XmlElement l_Element in l_FileAttributesList)
            {
                FileAttribute l_FileAttribute = new FileAttribute();
                l_FileAttribute.FromXml(l_Element);
                fileattributes.Add(l_FileAttribute);
            }

            XmlNodeList l_List = l_XmlElement.SelectNodes("//configurations/configuration");
            foreach (XmlElement l_Element in l_List)
            {
                string l_Type = l_Element.Attributes["type"].InnerText.ToLower();
                Configuration l_Config;
                if (l_Type == "install")
                    l_Config = new SetupConfiguration();
                else if (l_Type == "reference")
                    l_Config = new WebConfiguration();
                else
                    throw new ApplicationException("Invalid type");

                l_Config.FromXml(l_Element);

                Configurations.Add(l_Config);
            }

            m_FileName = p_FileName;
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

        private ConfigurationCollection m_Configurations = new ConfigurationCollection();

        [System.ComponentModel.Browsable(false)]
        public ConfigurationCollection Configurations
        {
            get { return m_Configurations; }
            set { m_Configurations = value; }
        }
    }

    public interface IXmlClass
    {
        void ToXml(XmlWriter p_Writer);
        void FromXml(XmlElement p_Element);
    }

    public class XmlWriterEventArgs : EventArgs
    {
        public XmlWriterEventArgs(XmlWriter p_Writer)
        {
            m_Writer = p_Writer;
        }
        private XmlWriter m_Writer;
        public XmlWriter XmlWriter
        {
            get { return m_Writer; }
        }
    }

    public delegate void XmlWriterEventHandler(object sender, XmlWriterEventArgs e);

    public class XmlElementEventArgs : EventArgs
    {
        public XmlElementEventArgs(XmlElement p_XmlElement)
        {
            m_XmlElement = p_XmlElement;
        }
        private XmlElement m_XmlElement;
        public XmlElement XmlElement
        {
            get { return m_XmlElement; }
        }
    }

    public delegate void XmlElementEventHandler(object sender, XmlElementEventArgs e);

    public class ConfigFileEventArgs : EventArgs
    {
        public ConfigFileEventArgs(ConfigFile p_Config)
        {
            m_ConfigFile = p_Config;
        }

        private ConfigFile m_ConfigFile;
        public ConfigFile ConfigFile
        {
            get { return m_ConfigFile; }
            set { m_ConfigFile = value; }
        }
    }

    public delegate void ConfigFileEventHandler(object sender, ConfigFileEventArgs e);

    public class ConfigFileFileEventArgs : ConfigFileEventArgs
    {
		public ConfigFileFileEventArgs(string p_FileName, ConfigFile p_Config):base(p_Config)
        {
            m_FileName = p_FileName;
        }

        private string m_FileName;
        public string FileName
        {
            get { return m_FileName; }
            set { m_FileName = value; }
        }
    }

    public delegate void ConfigFileFileEventHandler(object sender, ConfigFileFileEventArgs e);

    public class ConfigFileXmlWriterEventArgs : ConfigFileFileEventArgs
    {
		public ConfigFileXmlWriterEventArgs(XmlWriter p_XmlWriter, string p_FileName, ConfigFile p_Config):base(p_FileName, p_Config)
        {
            m_XmlWriter = p_XmlWriter;
        }

        private XmlWriter m_XmlWriter;
        public XmlWriter XmlWriter
        {
            get { return m_XmlWriter; }
            set { m_XmlWriter = value; }
        }
    }

    public delegate void ConfigFileXmlWriterEventHandler(object sender, ConfigFileXmlWriterEventArgs e);

    public class ConfigFileXmlElementEventArgs : ConfigFileFileEventArgs
    {
		public ConfigFileXmlElementEventArgs(XmlElement p_XmlElement, string p_FileName, ConfigFile p_Config):base(p_FileName, p_Config)
        {
            m_XmlElement = p_XmlElement;
        }

        private XmlElement m_XmlElement;
        public XmlElement XmlElement
        {
            get { return m_XmlElement; }
            set { m_XmlElement = value; }
        }
    }

    public delegate void ConfigFileXmlElementEventHandler(object sender, ConfigFileXmlElementEventArgs e);

}
