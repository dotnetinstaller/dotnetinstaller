using System;
using System.Xml;
using System.ComponentModel;
using System.Collections.Generic;
using System.IO;

namespace InstallerLib
{
    /// <summary>
    /// A base component.
    /// </summary>
    [XmlChild(typeof(InstalledCheck))]
    [XmlChild(typeof(InstalledCheckOperator))]
    [XmlChild(typeof(DownloadDialog), Max = 1)]
    [XmlChild(typeof(EmbedFile))]
    public abstract class Component : XmlClassImpl
    {
        public Component(string p_type)
            : this(p_type, "COMPONENT_NAME")
        {

        }

        public Component(string p_type, string p_ComponentName)
        {
            m_type = p_type;

            m_mustreboot = false;
            m_required = true;
            m_os_filter_greater = "";
            m_os_filter_lcid = "";
            m_os_filter_smaller = "";

            Template.Template_component tpl = Template.CurrentTemplate.component(p_ComponentName);

            m_description = tpl.description;
            m_installcompletemessage = tpl.installcompletemessage;
        }

        #region Attributi
        private string m_type; //can be cmd or msi or openfile
        [Description("The type of the component; can be 'cmd' for executing generic command line installation or 'msi' for installing Windows Installer MSI package or 'openfile' to open a file. (REQUIRED)")]
        public string type
        {
            get { return m_type; }
        }

        private string m_os_filter_greater;
        [Description("A filter to install this component only on all operating system id greater than the id specified (see Help->Operating System Table). For example to install a component only in Windows 2000 or later write '44'. (OPTIONAL)")]
        public string os_filter_greater
        {
            get { return m_os_filter_greater; }
            set { m_os_filter_greater = value; }
        }

        private string m_os_filter_smaller;
        [Description("A filter to install this component only on all operating system id smaller than the id specified (see operating system table). For example to install a component preceding Windows 2000 write '45'. (OPTIONAL)")]
        public string os_filter_smaller
        {
            get { return m_os_filter_smaller; }
            set { m_os_filter_smaller = value; }
        }

        private string m_os_filter_lcid;
        [Description("A filter to install this component only on all operating system language equals or not equals than the LCID specified (see Help->LCID table). Separate multiple LCID with comma (',') and use not symbol ('!') for NOT logic (es. '1044,1033,!1038' ). You can also filter all the configuration element. (OPTIONAL)")]
        public string os_filter_lcid
        {
            get { return m_os_filter_lcid; }
            set { m_os_filter_lcid = value; }
        }

        private string m_installcompletemessage; //se vuoto non viene visualizzato nessun messagio al termine del download
        [Description("The message used when a component is successfully installed. To disable this message leave this property empty. (OPTIONAL)")]
        public string installcompletemessage
        {
            get { return m_installcompletemessage; }
            set { m_installcompletemessage = value; }
        }

        private bool m_mustreboot;
        [Description("Indicates if ask to reboot after this component is installed successfully (True/False). Normally if the system must be restarted is automatically the component that tells this setup (with special return code) to stop and restart the system, but in special circumstances (for example in Windows 98) we must force a reboot to install correctly some components (for example the .NET Framework). (REQUIRED)")]
        public bool mustreboot
        {
            get { return m_mustreboot; }
            set { m_mustreboot = value; }
        }

        private bool m_required;
        [Description("Indicates whether the component is required for a successful installation. (REQUIRED)")]
        public bool required
        {
            get { return m_required; }
            set { m_required = value; }
        }

        private string m_description;
        [Description("Description of this component. This value is used also in some message to replace the %s string. (REQUIRED)")]
        public string description
        {
            get { return m_description; }
            set { m_description = value; OnDescriptionChanged(); }
        }

        //		private string m_installmessage;
        //		[Description("The message used to confirm the installation of this component. (REQUIRED)")]
        //		public string installmessage
        //		{
        //			get{return m_installmessage;}
        //			set{m_installmessage = value;}
        //		}

        private string m_note;
        [Description("Note, not used by the setup. (OPTIONAL)")]
        public string note
        {
            get { return m_note; }
            set { m_note = value; }
        }

        /* Jason Biegel - 2008-04-28: added message for not matching the processor architecture filter */
        private string m_processor_architecture_filter;
        [Description("Type of processor architecture (x86, mips, alpha, ppc, shx, arm, ia64, alpha64, msil, x64, ia32onwin64). Seperate by commas, can use the NOT sign ('!') to exclude. (es. 'x86,x64' or '!x86'). (OPTIONAL)")]
        public string processor_architecture_filter
        {
            get { return m_processor_architecture_filter; }
            set { m_processor_architecture_filter = value; }
        }

        #endregion

        protected void OnDescriptionChanged()
        {
            if (DescriptionChanged != null)
                DescriptionChanged(this, EventArgs.Empty);
        }

        public event EventHandler DescriptionChanged;

        #region IXmlClass Members

        public override string XmlTag
        {
            get { return "component"; }
        }

        #endregion

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("os_filter_greater", m_os_filter_greater);
            e.XmlWriter.WriteAttributeString("os_filter_smaller", m_os_filter_smaller);
            e.XmlWriter.WriteAttributeString("os_filter_lcid", m_os_filter_lcid);
            e.XmlWriter.WriteAttributeString("type", m_type);
            e.XmlWriter.WriteAttributeString("installcompletemessage", m_installcompletemessage);
            e.XmlWriter.WriteAttributeString("mustreboot", m_mustreboot.ToString());
            e.XmlWriter.WriteAttributeString("required", m_required.ToString());
            e.XmlWriter.WriteAttributeString("description", m_description);
            //e.XmlWriter.WriteAttributeString("installmessage",m_installmessage);
            e.XmlWriter.WriteAttributeString("note", m_note);
            // Jason Biegel - 2008-04-28: new attributes added
            e.XmlWriter.WriteAttributeString("processor_architecture_filter", m_processor_architecture_filter);
            base.OnXmlWriteTag(e);
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            if (e.XmlElement.Attributes["description"] != null)
                m_description = e.XmlElement.Attributes["description"].InnerText;

            if (e.XmlElement.Attributes["installcompletemessage"] != null)
                m_installcompletemessage = e.XmlElement.Attributes["installcompletemessage"].InnerText;

            //			if (e.XmlElement.Attributes["installmessage"]!=null)
            //				m_installmessage = e.XmlElement.Attributes["installmessage"].InnerText;

            if (e.XmlElement.Attributes["mustreboot"] != null)
                m_mustreboot = bool.Parse(e.XmlElement.Attributes["mustreboot"].InnerText);

            if (e.XmlElement.Attributes["required"] != null)
                m_required = bool.Parse(e.XmlElement.Attributes["required"].InnerText);

            if (e.XmlElement.Attributes["os_filter_greater"] != null)
                m_os_filter_greater = e.XmlElement.Attributes["os_filter_greater"].InnerText;

            if (e.XmlElement.Attributes["os_filter_lcid"] != null)
                m_os_filter_lcid = e.XmlElement.Attributes["os_filter_lcid"].InnerText;

            if (e.XmlElement.Attributes["os_filter_smaller"] != null)
                m_os_filter_smaller = e.XmlElement.Attributes["os_filter_smaller"].InnerText;

            if (e.XmlElement.Attributes["note"] != null)
                m_note = e.XmlElement.Attributes["note"].InnerText;

            //			if (e.XmlElement.Attributes["type"]!=null)
            //				m_type = e.XmlElement.Attributes["type"].InnerText;

            // Jason Biegel - 2008-04-22: new attributes added
            if (e.XmlElement.Attributes["processor_architecture_filter"] != null)
                m_processor_architecture_filter = e.XmlElement.Attributes["processor_architecture_filter"].InnerText;

            base.OnXmlReadTag(e);
        }

        public static Component CreateFromXml(XmlElement element)
        {
            Component l_Comp;
            string xmltype = element.Attributes["type"].InnerText;
            if (xmltype == "msi")
                l_Comp = new ComponentMsi();
            else if (xmltype == "cmd")
                l_Comp = new ComponentCmd();
            else if (xmltype == "openfile")
                l_Comp = new ComponentOpenFile();
            else
                throw new Exception(string.Format("Invalid type: {0}", xmltype));

            l_Comp.FromXml(element);

            return l_Comp;
        }
    }
}
