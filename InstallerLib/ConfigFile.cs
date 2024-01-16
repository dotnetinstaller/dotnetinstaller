using System;
using System.ComponentModel;
using System.Xml;
using System.Drawing.Design;
using System.ComponentModel.Design;
using System.IO;
using System.Text;

namespace InstallerLib
{
    public enum InstallUILevel
    {
        /// <summary>
        /// Full install, all UI.
        /// </summary>
        full,
        /// <summary>
        /// Basic UI.
        /// </summary>
        basic,
        /// <summary>
        /// Silent, no UI.
        /// </summary>
        silent
    }

    /// <summary>
    /// A configuration file.
    /// </summary>
    [XmlChild(typeof(WebConfiguration))]
    [XmlChild(typeof(SetupConfiguration))]
    public class ConfigFile : XmlClass
    {
        public ConfigFile()
        {
        }

        private string m_filename = null;
        [Browsable(false)]
        public string filename
        {
            get { return m_filename; }
            set { m_filename = value; }
        }

        private InstallUILevel m_ui_level = InstallUILevel.full;
        [Description("Install-time UI level. Default to 'silent' or 'basic' UI installation.")]
        [Category("UI")]
        [Required]
        public InstallUILevel ui_level
        {
            get { return m_ui_level; }
            set { m_ui_level = value; }
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

        // message for not matching the OS filter
        private string m_configuration_no_match_message;
        [Description("An error message for the case that the operating system, processor architecture or LCID does not match the operating system filter of any configuration.")]
        [Category("Messages")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        public string configuration_no_match_message
        {
            get { return m_configuration_no_match_message; }
            set { m_configuration_no_match_message = value; }
        }

        private FileAttributeCollection m_fileattributes = new FileAttributeCollection();
        [Description("attributes")]
        [Category("File Attributes")]
        public FileAttributeCollection fileattributes
        {
            get { return m_fileattributes; }
            set { m_fileattributes = value; }
        }

        private LcidType m_lcidtype = LcidType.UserExe;
        [Description(@"Method for obtainng the current user or system locale.")]
        [Category("Locale")]
        [Required]
        public LcidType lcidtype
        {
            get { return m_lcidtype; }
            set { m_lcidtype = value; }
        }

        // show languange selector
        private bool m_show_language_selector = false;
        [Description("Show a language selector instead of automatically choosing the language based on the operating system's and user locale.")]
        [DefaultValue(false)]
        [Category("Locale")]
        [Required]
        public bool show_language_selector
        {
            get { return m_show_language_selector; }
            set { m_show_language_selector = value; }
        }

        private string m_language_selector_title = "";
        [Description("Optional text that appears above the list of supported locales.")]
        [Category("Locale")]
        public string language_selector_title
        {
            get { return m_language_selector_title; }
            set { m_language_selector_title = value; }
        }

        private string m_language_selector_ok = "OK";
        [Description("Text of the 'OK' button in the language selector.")]
        [Category("Locale")]
        public string language_selector_ok
        {
            get { return m_language_selector_ok; }
            set { m_language_selector_ok = value; }
        }

        private string m_language_selector_cancel = "Cancel";
        [Description("Text of the 'Cancel' button in the language selector.")]
        [Category("Locale")]
        public string language_selector_cancel
        {
            get { return m_language_selector_cancel; }
            set { m_language_selector_cancel = value; }
        }

        // auto-enabled logging options
        private bool m_log_enabled = false;
        [Description("Always enable logging. You can also enable logging at runtime by specifying '/Log /LogFile <file>' on the dotNetInstaller command-line.")]
        [DefaultValue(false)]
        [Category("Logging")]
        [Required]
        public bool log_enabled
        {
            get { return m_log_enabled; }
            set { m_log_enabled = value; }
        }

        private string m_log_file = @"#TEMPPATH\dotNetInstallerLog.txt";
        [Description("Path to the log file.")]
        [DefaultValue("#TEMPPATH\\dotNetInstallerLog.txt")]
        [Category("Logging")]
        public string log_file
        {
            get { return m_log_file; }
            set { m_log_file = value; }
        }

        private Editor m_editor = new Editor();
        [Description(@"Editor information.")]
        [Category("Configuration File")]
        public Editor editor
        {
            get { return m_editor; }
        }

        public void Save()
        {
            if (string.IsNullOrEmpty(m_filename))
            {
                throw new Exception("Missing filename");
            }

            SaveAs(m_filename);
        }

        /// <summary>
        /// Save the xml to a file.
        /// </summary>
        /// <param name="p_FileName">target filename</param>
        public void SaveAs(string p_FileName)
        {
            WriteTo(p_FileName);
            m_filename = p_FileName;
        }

        /// <summary>
        /// Write configuration to a file.
        /// </summary>
        /// <param name="p_FileName">target filename</param>
        public void WriteTo(string p_FileName)
        {
            GetXml(null).Save(p_FileName);
        }

        /// <summary>
        /// Raw configuration xml.
        /// </summary>
        [Browsable(false)]
        public XmlDocument GetXml(XmlFilter filter)
        {
            MemoryStream ms = new MemoryStream();
            XmlTextWriter l_XmlWriter = new XmlTextWriter(ms, Encoding.UTF8);
            l_XmlWriter.Formatting = Formatting.Indented;
            l_XmlWriter.WriteStartDocument();
            ToXml(l_XmlWriter, filter);
            XmlDocument xmldoc = new XmlDocument();
            l_XmlWriter.Flush();
            ms.Position = 0;
            xmldoc.Load(ms);
            return xmldoc;
        }

        public override string XmlTag
        {
            get { return "configurations"; }
        }

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            // lcid type
            e.XmlWriter.WriteAttributeString("lcid_type", m_lcidtype.ToString());
            e.XmlWriter.WriteAttributeString("show_language_selector", m_show_language_selector.ToString());
            e.XmlWriter.WriteAttributeString("language_selector_title", m_language_selector_title);
            e.XmlWriter.WriteAttributeString("language_selector_ok", m_language_selector_ok);
            e.XmlWriter.WriteAttributeString("language_selector_cancel", m_language_selector_cancel);
            // processor and os filter architecture messages
            e.XmlWriter.WriteAttributeString("configuration_no_match_message", m_configuration_no_match_message);
            // silent install
            e.XmlWriter.WriteAttributeString("ui_level", m_ui_level.ToString());
            // version information
            e.XmlWriter.WriteAttributeString("fileversion", m_fileversion);
            e.XmlWriter.WriteAttributeString("productversion", m_productversion);
            // auto-enabled logging
            e.XmlWriter.WriteAttributeString("log_enabled", m_log_enabled.ToString());
            e.XmlWriter.WriteAttributeString("log_file", m_log_file);
            // tag schema
            editor.ToXml(e.XmlWriter, null);
            // file attributes
            fileattributes.ToXml(e.XmlWriter);
            base.OnXmlWriteTag(e);
        }

        private void OnXmlReadTagLegacy(XmlElementEventArgs e)
        {
            // [legacy] auto-enable logging (convert from 1.6 and older)
            XmlNodeList configurations = e.XmlElement.SelectNodes("//configuration[@type='install']");
            foreach (XmlNode configuration in configurations)
            {
                XmlElementEventArgs configurationArgs = new XmlElementEventArgs((XmlElement)configuration);

                string log_file = string.Empty;
                if (ReadAttributeValue(configurationArgs, "log_file", ref log_file))
                    m_log_file = log_file;

                bool log_enabled = false;
                if (ReadAttributeValue(configurationArgs, "log_enabled", ref log_enabled))
                    m_log_enabled = log_enabled;

                break;
            }
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            // lcid type
            ReadAttributeValue(e, "lcid_type", ref m_lcidtype);
            ReadAttributeValue(e, "show_language_selector", ref m_show_language_selector);
            ReadAttributeValue(e, "language_selector_title", ref m_language_selector_title);
            ReadAttributeValue(e, "language_selector_ok", ref m_language_selector_ok);
            ReadAttributeValue(e, "language_selector_cancel", ref m_language_selector_cancel);
            // processor and os filter architecture messages
            ReadAttributeValue(e, "configuration_no_match_message", ref m_configuration_no_match_message);
            // logging
            ReadAttributeValue(e, "log_enabled", ref m_log_enabled);
            ReadAttributeValue(e, "log_file", ref m_log_file);
            // legacy
            OnXmlReadTagLegacy(e);
            // ui level
            ReadAttributeValue<InstallUILevel>(e, "ui_level", ref m_ui_level);
            // backwards compatibility: silent_install
            bool silentInstall = false;
            if (ReadAttributeValue(e, "silent_install", ref silentInstall) && silentInstall)
            {
                m_ui_level = InstallUILevel.silent;
            }
            // version information
            ReadAttributeValue(e, "fileversion", ref m_fileversion);
            ReadAttributeValue(e, "productversion", ref m_productversion);
            base.OnXmlReadTag(e);
        }

        protected override bool OnXmlChild(XmlElement child)
        {
            bool processed = false;
            switch (child.LocalName)
            {
                case "schema":
                    m_editor = Editor.CreateFromXml(child);
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
            LoadXml(l_XmlElement);
            m_filename = p_FileName;
        }

        public void LoadXml(string xml)
        {
            XmlDocument l_XmlElement = new XmlDocument();
            l_XmlElement.LoadXml(xml);
            LoadXml(l_XmlElement);
        }

        public void LoadXml(XmlDocument xml)
        {
            XmlElement configurations = (XmlElement)xml.SelectSingleNode("//configurations");
            if (configurations == null) throw new Exception("Invalid configuration xml.");
            Clear();
            base.FromXml(configurations);
        }

        /// <summary>
        /// Number of nested components.
        /// </summary>
        [Browsable(false)]
        public int ConfigurationCount
        {
            get
            {
                return GetCount<Configuration>();
            }
        }

        /// <summary>
        /// Number of nested components.
        /// </summary>
        [Browsable(false)]
        public int ComponentCount
        {
            get
            {
                return GetCount<Component>();
            }
        }
    }
}
