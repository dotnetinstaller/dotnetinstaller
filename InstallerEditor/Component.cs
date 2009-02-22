using System;
using System.Xml;
using System.ComponentModel;
using System.Collections.Generic;
using System.IO;

namespace InstallerEditor
{
    /// <summary>
    /// Summary description for Configuration.
    /// </summary>
    public abstract class Component : IXmlClass
    {
        public Component(string p_type)
            : this(p_type, "COMPONENT_NAME")
        {
        }
        public Component(string p_type, string p_ComponentName)
        {
            m_type = p_type;

            m_mustreboot = false;
            m_os_filter_greater = "";
            m_os_filter_lcid = "";
            m_os_filter_smaller = "";

            Template.Template_component tpl = Template.CurrentTemplate.component(p_ComponentName);

            m_description = tpl.description;
            m_installcompletemessage = tpl.installcompletemessage;

            //			if (LanguageUI.Language == SupportedLanguage.Italian)
            //			{
            //				m_description = p_ComponentName;
            //				m_installcompletemessage = "";
            //				m_installmessage = "Premi avanti per installare " + p_ComponentName;
            //			}
            //			else //english
            //			{
            //				m_description = p_ComponentName;
            //				m_installcompletemessage = "";
            //				m_installmessage = "Click Next to install " + p_ComponentName;
            //			}
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

        public void ToXml(XmlWriter p_Writer)
        {
            p_Writer.WriteStartElement("component");
            OnXmlWriteTagcomponent(new XmlWriterEventArgs(p_Writer));

            if (m_DownloadDialog != null)
            {
                m_DownloadDialog.ToXml(p_Writer);
            }

            foreach (installedcheck i in installchecks)
            {
                i.ToXml(p_Writer);
            }

            p_Writer.WriteEndElement();
        }

        public void FromXml(XmlElement p_Element)
        {
            if (p_Element.Attributes["type"] == null ||
                p_Element.Attributes["type"].InnerText != m_type)
                throw new ApplicationException("Invalid type");

            OnXmlReadTagcomponent(new XmlElementEventArgs(p_Element));

            XmlElement l_ElementDownloadDialog = (XmlElement)p_Element.SelectSingleNode("downloaddialog");
            if (l_ElementDownloadDialog != null)
            {
                DownloadDialog l_dialog = new DownloadDialog();
                l_dialog.FromXml(l_ElementDownloadDialog);
                m_DownloadDialog = l_dialog;
            }

            XmlNodeList l_List = p_Element.SelectNodes("installedcheck");
            foreach (XmlElement l_XmlCheck in l_List)
            {
                if (l_XmlCheck.Attributes["type"] != null)
                {
                    installedcheck l_check;
                    if (l_XmlCheck.Attributes["type"].InnerText == "check_file")
                        l_check = new installedcheck_file();
                    else if (l_XmlCheck.Attributes["type"].InnerText == "check_registry_value")
                        l_check = new installedcheck_registry();
                    else
                        throw new ApplicationException("Invalid type");

                    l_check.FromXml(l_XmlCheck);

                    installchecks.Add(l_check);
                }
            }
        }
        #endregion

        protected virtual void OnXmlWriteTagcomponent(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("os_filter_greater", m_os_filter_greater);
            e.XmlWriter.WriteAttributeString("os_filter_smaller", m_os_filter_smaller);
            e.XmlWriter.WriteAttributeString("os_filter_lcid", m_os_filter_lcid);
            e.XmlWriter.WriteAttributeString("type", m_type);
            e.XmlWriter.WriteAttributeString("installcompletemessage", m_installcompletemessage);
            e.XmlWriter.WriteAttributeString("mustreboot", m_mustreboot.ToString());
            e.XmlWriter.WriteAttributeString("description", m_description);
            //e.XmlWriter.WriteAttributeString("installmessage",m_installmessage);
            e.XmlWriter.WriteAttributeString("note", m_note);
            // Jason Biegel - 2008-04-28: new attributes added
            e.XmlWriter.WriteAttributeString("processor_architecture_filter", m_processor_architecture_filter);

        }
        protected virtual void OnXmlReadTagcomponent(XmlElementEventArgs e)
        {
            if (e.XmlElement.Attributes["description"] != null)
                m_description = e.XmlElement.Attributes["description"].InnerText;

            if (e.XmlElement.Attributes["installcompletemessage"] != null)
                m_installcompletemessage = e.XmlElement.Attributes["installcompletemessage"].InnerText;

            //			if (e.XmlElement.Attributes["installmessage"]!=null)
            //				m_installmessage = e.XmlElement.Attributes["installmessage"].InnerText;

            if (e.XmlElement.Attributes["mustreboot"] != null)
                m_mustreboot = bool.Parse(e.XmlElement.Attributes["mustreboot"].InnerText);

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
        }

        private installedcheckCollection m_installchecks = new installedcheckCollection();
        [System.ComponentModel.Browsable(false)]
        public installedcheckCollection installchecks
        {
            get { return m_installchecks; }
            set { m_installchecks = value; }
        }

        private DownloadDialog m_DownloadDialog = null; //di default non è presente
        [System.ComponentModel.Browsable(false)]
        public DownloadDialog DownloadDialog
        {
            get { return m_DownloadDialog; }
            set { m_DownloadDialog = value; }
        }

        public static Component CreateComponentFromXml(XmlElement element)
        {
            Component l_Comp;
            if (element.Attributes["type"].InnerText == "msi")
                l_Comp = new ComponentMsi();
            else if (element.Attributes["type"].InnerText == "cmd")
                l_Comp = new ComponentCmd();
            else if (element.Attributes["type"].InnerText == "openfile")
                l_Comp = new ComponentOpenFile();
            else
                throw new ApplicationException("Invalid type");

            l_Comp.FromXml(element);

            return l_Comp;
        }

        public virtual IList<string> GetFiles()
        {
            List<string> files = new List<string>();
            if (m_DownloadDialog != null)
            {
                foreach (Download dl in m_DownloadDialog.Downloads)
                {
                    string filename = Path.Combine(dl.destinationpath, dl.destinationfilename);
                    if (!files.Contains(filename)) files.Add(filename);
                }
            }
            return files;
        }
    }
}
