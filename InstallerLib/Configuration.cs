using System;
using System.Xml;
using System.ComponentModel;
using System.Collections.Generic;

namespace InstallerLib
{
    /// <summary>
    /// A configuration.
    /// </summary>
    public abstract class Configuration : XmlClass
    {
        public Configuration(string p_type)
        {
            m_type = p_type;
        }

        #region Configuration Properties

        private string m_os_filter;
        [Description("A filter to install this configuration only on all operating system equal or not equal the value(s) specified. Separate multiple operating system ids with comma (',') and use not symbol ('!') for NOT logic (eg. '44,!45' ).")]
        [Category("Operating System")]
        public string os_filter
        {
            get { return m_os_filter; }
            set { m_os_filter = value; }
        }

        // filter for minimal OS version
        private string m_os_filter_greater;
        [Category("Filters")]
        [Description("A filter to run this setup only on all operating system id greater than the id specified (see Help->Operating System Table). For example to run this setup only in Windows 2000 or later write '44'. (OPTIONAL)")]
        public string os_filter_greater
        {
            get { return m_os_filter_greater; }
            set { m_os_filter_greater = value; }
        }

        // filter for maximal OS version
        private string m_os_filter_smaller;
        [Category("Filters")]
        [Description("A filter to run this setup only on all operating system id smaller than the id specified (see operating system table). For example to run this setup preceding Windows 2000 write '45'. (OPTIONAL)")]
        public string os_filter_smaller
        {
            get { return m_os_filter_smaller; }
            set { m_os_filter_smaller = value; }
        }

        // filter for processor architecture
        private string m_processor_architecture_filter;
        [Description("Type of processor architecture (x86, mips, alpha, ppc, shx, arm, ia64, alpha64, msil, x64, ia32onwin64). Separate by commas, can use the NOT sign ('!') to exclude. (eg. 'x86,x64' or '!x86'). (OPTIONAL)")]
        [Category("Filters")]
        public string processor_architecture_filter
        {
            get { return m_processor_architecture_filter; }
            set { m_processor_architecture_filter = value; }
        }

        private string m_lcid_filter = string.Empty;
        [Description("A filter to install this configuration only on all operating system language equals or not equals than the LCID specified (see Help->LCID Table). Separate multiple LCID with comma (',') and use not symbol ('!') for NOT logic (eg. '1044,1033,!1038' ). You can also filter a specified component. (OPTIONAL)")]
        [Category("Language")]
        public string lcid_filter
        {
            get { return m_lcid_filter; }
            set { m_lcid_filter = value; OnLCIDChanged(); }
        }

        private string m_language = string.Empty;
        [Description("An optional string that appears in the language selector for this configuration.")]
        [Category("Language")]
        public string language
        {
            get { return m_language; }
            set { m_language = value; }
        }

        private string m_language_id = "";
        [Description("The actual language ID chosen by the language dialog selector.")]
        [Category("Language")]
        public string language_id
        {
            get { return m_language_id; }
            set { m_language_id = value; }
        }

        private string m_type;
        [Description("Type of the configuration. Can be 'install' or 'reference'. (REQUIRED)")]
        public string type
        {
            get { return m_type; }
        }

        private bool m_supports_install = true;
        [Description("If true configuration supports install mode.")]
        [Category("Runtime")]
        public bool supports_install
        {
            get { return m_supports_install; }
            set { m_supports_install = value; }
        }

        private bool m_supports_uninstall = true;
        [Description("If true configuration supports uninstall mode.")]
        [Category("Runtime")]
        public bool supports_uninstall
        {
            get { return m_supports_uninstall; }
            set { m_supports_uninstall = value; }
        }

        #endregion

        public override string ToString()
        {
            return m_type + ":" + m_lcid_filter;
        }

        protected void OnLCIDChanged()
        {
            if (LCIDChanged != null)
                LCIDChanged(this, EventArgs.Empty);
        }

        public event EventHandler LCIDChanged;

        #region XmlClass Members

        public override string XmlTag
        {
            get { return "configuration"; }
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            if (ReadAttributeValue(e, "lcid", ref m_lcid_filter) || ReadAttributeValue(e, "lcid_filter", ref m_lcid_filter))
                OnLCIDChanged();
            ReadAttributeValue(e, "language", ref m_language);
            ReadAttributeValue(e, "language_id", ref m_language_id);
            ReadAttributeValue(e, "os_filter", ref m_os_filter);
            ReadAttributeValue(e, "os_filter_greater", ref m_os_filter_greater);
            ReadAttributeValue(e, "os_filter_smaller", ref m_os_filter_smaller);
            ReadAttributeValue(e, "processor_architecture_filter", ref m_processor_architecture_filter);
            ReadAttributeValue(e, "supports_install", ref m_supports_install);
            ReadAttributeValue(e, "supports_uninstall", ref m_supports_uninstall);
        }

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("type", m_type);
            e.XmlWriter.WriteAttributeString("lcid_filter", m_lcid_filter);
            e.XmlWriter.WriteAttributeString("language_id", m_language_id);
            e.XmlWriter.WriteAttributeString("language", m_language);
            e.XmlWriter.WriteAttributeString("os_filter", m_os_filter);
            e.XmlWriter.WriteAttributeString("os_filter_greater", m_os_filter_greater);
            e.XmlWriter.WriteAttributeString("os_filter_smaller", m_os_filter_smaller);
            e.XmlWriter.WriteAttributeString("processor_architecture_filter", m_processor_architecture_filter);
            e.XmlWriter.WriteAttributeString("supports_install", m_supports_install.ToString());
            e.XmlWriter.WriteAttributeString("supports_uninstall", m_supports_uninstall.ToString());
            base.OnXmlWriteTag(e);
        }

        public static Configuration CreateFromXml(XmlElement element)
        {
            Configuration l_Config;
            XmlAttribute xmltypeAttribute = element.Attributes["type"];
            if (xmltypeAttribute == null)
            {
                throw new Exception(string.Format("Missing configuration type at \"{0}\".", element.Name));
            }

            string xmltype = xmltypeAttribute.InnerText;
            switch (xmltype)
            {
                case "install":
                    l_Config = new SetupConfiguration();
                    break;
                case "reference":
                    l_Config = new WebConfiguration();
                    break;
                default:
                    throw new Exception(string.Format("Invalid configuration type: {0}", xmltype));
            }
            
            l_Config.FromXml(element);
            return l_Config;
        }

        #endregion
    }
}
