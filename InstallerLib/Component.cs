using System;
using System.Xml;
using System.ComponentModel;
using System.ComponentModel.Design;
using System.Collections.Generic;
using System.Drawing.Design;

namespace InstallerLib
{
    /// <summary>
    /// A base component.
    /// </summary>
    [XmlChild(typeof(InstalledCheck))]
    [XmlChild(typeof(InstalledCheckOperator))]
    [XmlChild(typeof(DownloadDialog), Max = 1)]
    [XmlChild(typeof(EmbedFile))]
    [XmlChild(typeof(EmbedFolder))]
    public abstract class Component : XmlClass
    {
        public Component(string type, string name)
        {
            m_type = type;
            Template.Template_component tpl = Template.CurrentTemplate.component(name);
            m_display_name = tpl.display_name;
        }

        #region Attributes

        private string m_type;
        [Description("Type of the component; can be 'cmd' for executing generic command line installation or 'msi' for installing Windows Installer MSI package or 'openfile' to open a file.")]
        [Category("Component")]
        [Required]
        public string type
        {
            get { return m_type; }
        }

        private string m_os_filter;
        [Description("Filter to install this component only on all operating systems equal or not equal to the id value(s) specified. Separate multiple operating system ids with comma (',') and use not symbol ('!') for NOT logic (es. '44,!45' ).")]
        [Category("Operating System")]
        public string os_filter
        {
            get { return m_os_filter; }
            set { m_os_filter = value; }
        }

        private OperatingSystem m_os_filter_min;
        [Description("Filter to install this component only on all operating systems greater or equal to the id value specified. For example to install a component only in Windows Server 2003 or later use 'winServer2003'.")]
        [Category("Operating System")]
        public OperatingSystem os_filter_min
        {
            get { return m_os_filter_min; }
            set { m_os_filter_min = value; }
        }

        private OperatingSystem m_os_filter_max;
        [Description("Filter to install this component only on all operating systems smaller or equal to the id value specified. For example to install a component preceding Windows Server 2003 use 'winXPMax'.")]
        [Category("Operating System")]
        public OperatingSystem os_filter_max
        {
            get { return m_os_filter_max; }
            set { m_os_filter_max = value; }
        }

        private string m_os_type_filter;
        [Description("Filter to install this component only on all operating system product types equal or not equal to the value(s) specified. Separate multiple operating system types with a comma (',') and use the not symbol ('!') for NOT logic (ex. '!workstation,!server' ).")]
        [Category("Operating System")]
        public string os_type_filter
        {
            get { return m_os_type_filter; }
            set { m_os_type_filter = value; }
        }

        private string m_os_filter_lcid;
        [Description("Filter to install this component only on all operating system languages equal or not equal to the LCID specified. Separate multiple LCID with comma (',') and use not symbol ('!') for NOT logic (eg. '1044,1033,!1038' ).")]
        [Category("Operating System")]
        public string os_filter_lcid
        {
            get { return m_os_filter_lcid; }
            set { m_os_filter_lcid = value; }
        }

        private string m_installcompletemessage;
        [Description("Message used after a component is successfully installed. To disable this message leave this property empty.")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        [Category("Install")]
        public string installcompletemessage
        {
            get { return m_installcompletemessage; }
            set { m_installcompletemessage = value; }
        }

        private string m_uninstallcompletemessage;
        [Description("Message used after a component is been successfully uninstalled.")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        [Category("Uninstall")]
        public string uninstallcompletemessage
        {
            get { return m_uninstallcompletemessage; }
            set { m_uninstallcompletemessage = value; }
        }

        private bool m_mustreboot = false;
        [Description("Indicates whether to reboot automatically after this component is installed or uninstalled successfully. Normally if the system must be restarted, the component tells this setup (with special return code) to stop and restart the system. Setting this option to 'true' forces a reboot without prompting.")]
        [Category("Runtime")]
        [Required]
        public bool mustreboot
        {
            get { return m_mustreboot; }
            set { m_mustreboot = value; }
        }

        private string m_failed_exec_command_continue;
        [Description("Message to display after a component failed to install. The user is then asked whether installation can continue using this message. May contain one '%s' replaced by the description of the component.")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        [Category("Runtime")]
        public string failed_exec_command_continue
        {
            get { return m_failed_exec_command_continue; }
            set { m_failed_exec_command_continue = value; }
        }

        private string m_reboot_required;
        [Description("Message used when this component signaled the installer that it requires a reboot.")]
        [Editor(typeof(MultilineStringEditor), typeof(UITypeEditor))]
        [Category("Runtime")]
        public string reboot_required
        {
            get { return m_reboot_required; }
            set { m_reboot_required = value; }
        }

        private bool m_must_reboot_required = false;
        [Description("Component setting for reboot behavior. When 'true', installation won't continue after this component required a reboot.")]
        [Category("Runtime")]
        [Required]
        public bool must_reboot_required
        {
            get { return m_must_reboot_required; }
            set { m_must_reboot_required = value; }
        }

        private bool m_allow_continue_on_error = true;
        [Description("Set to 'true' to prompt the user to continue when a component fails to install.")]
        [Category("Runtime")]
        [Required]
        public bool allow_continue_on_error
        {
            get { return m_allow_continue_on_error; }
            set { m_allow_continue_on_error = value; }
        }

        private bool m_default_continue_on_error = false;
        [Description("The default value of whether to continue when a component fails to install.")]
        [Category("Runtime")]
        [Required]
        public bool default_continue_on_error
        {
            get { return m_default_continue_on_error; }
            set { m_default_continue_on_error = value; }
        }

        private string m_id;
        [Description("Component identity. This value should be unique.")]
        [Category("Component")]
        [Required]
        public string id
        {
            get { return m_id; }
            set { m_id = value; OnDisplayChanged(); }
        }

        private string m_display_name;
        [Description("Component display name. This value is used in some message to replace the '%s' string.")]
        [Category("Component")]
        [Required]
        public string display_name
        {
            get { return m_display_name; }
            set { m_display_name = value; OnDisplayChanged(); }
        }

        private string m_uninstall_display_name;
        [Description("Optional display name of this component during uninstall. Defaults to 'display_name' when blank.")]
        [Category("Component")]
        public string uninstall_display_name
        {
            get { return m_uninstall_display_name; }
            set { m_uninstall_display_name = value; OnDisplayChanged(); }
        }

        private bool m_required_install = true;
        [Description("Indicates whether the component is required for a successful installation.")]
        [Category("Component")]
        [Required]
        public bool required_install
        {
            get { return m_required_install; }
            set { m_required_install = value; }
        }

        private bool m_required_uninstall = true;
        [Description("Indicates whether the component is required for a successful uninstallation.")]
        [Category("Component")]
        [Required]
        public bool required_uninstall
        {
            get { return m_required_uninstall; }
            set { m_required_uninstall = value; }
        }

        private bool m_selected_install = true;
        [Description("Indicates whether the component is selected by default during install.")]
        [Category("Component")]
        [Required]
        public bool selected_install
        {
            get { return m_selected_install; }
            set { m_selected_install = value; }
        }

        private bool m_selected_uninstall = true;
        [Description("Indicates whether the component is selected by default during uninstall.")]
        [Category("Component")]
        [Required]
        public bool selected_uninstall
        {
            get { return m_selected_uninstall; }
            set { m_selected_uninstall = value; }
        }

        private string m_note;
        [Description("Store any additional free-formed information in this field, not used by the setup.")]
        [Category("Component")]
        public string note
        {
            get { return m_note; }
            set { m_note = value; }
        }

        // message for not matching the processor architecture filter
        private string m_processor_architecture_filter;
        [Description("Type of processor architecture (x86, mips, alpha, ppc, shx, arm, ia64, alpha64, msil, x64, ia32onwin64). Separate by commas, can use the NOT sign ('!') to exclude values. (eg. 'x86,x64' or '!x86').")]
        [Category("Filters")]
        public string processor_architecture_filter
        {
            get { return m_processor_architecture_filter; }
            set { m_processor_architecture_filter = value; }
        }

        private string m_status_installed;
        [Description("String used to indicate that this component is installed.")]
        [Category("Component")]
        public string status_installed
        {
            get { return m_status_installed; }
            set { m_status_installed = value; }
        }

        private string m_status_notinstalled;
        [Description("String used to indicate that this component is not installed.")]
        [Category("Component")]
        public string status_notinstalled
        {
            get { return m_status_notinstalled; }
            set { m_status_notinstalled = value; }
        }

        private bool m_supports_install = true;
        [Description("Indicates whether the component supports the install sequence.")]
        [Category("Install")]
        [Required]
        public bool supports_install
        {
            get { return m_supports_install; }
            set { m_supports_install = value; }
        }

        private bool m_supports_uninstall = false;
        [Description("Indicates whether the component supports the uninstall sequence.")]
        [Category("Uninstall")]
        [Required]
        public bool supports_uninstall
        {
            get { return m_supports_uninstall; }
            set { m_supports_uninstall = value; }
        }

        private bool m_show_progress_dialog = true;
        [Description("Set to 'true' to show the progress dialogs.")]
        [Category("Component")]
        [Required]
        public bool show_progress_dialog
        {
            get { return m_show_progress_dialog; }
            set { m_show_progress_dialog = value; }
        }

        private bool m_show_cab_dialog = true;
        [Description("Set to 'true' to show the CAB extraction dialogs.")]
        [Category("Component")]
        [Required]
        public bool show_cab_dialog
        {
            get { return m_show_cab_dialog; }
            set { m_show_cab_dialog = value; }
        }

        private bool m_hide_component_if_installed = false;
        [Description("Indicates whether the component is hidden if it's already installed. "
            + "The default value is 'false' so the component is displayed even if it's already installed.")]
        [Category("Component")]
        public bool hide_component_if_installed
        {
            get { return m_hide_component_if_installed; }
            set { m_hide_component_if_installed = value; }
        }

        #endregion

        #region Events

        protected void OnDisplayChanged()
        {
            if (DisplayChanged != null)
            {
                DisplayChanged(this, EventArgs.Empty);
            }
        }

        public event EventHandler DisplayChanged;

        #endregion

        #region XmlClass Members

        public override string XmlTag
        {
            get { return "component"; }
        }

        #endregion

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("id", string.IsNullOrEmpty(m_id) ? m_display_name : m_id);
            e.XmlWriter.WriteAttributeString("display_name", m_display_name);
            e.XmlWriter.WriteAttributeString("uninstall_display_name", m_uninstall_display_name);
            e.XmlWriter.WriteAttributeString("os_filter", m_os_filter);
            e.XmlWriter.WriteAttributeString("os_filter_min", (m_os_filter_min == OperatingSystem.winNone
                ? "" : Enum.GetName(typeof(OperatingSystem), m_os_filter_min)));
            e.XmlWriter.WriteAttributeString("os_filter_max", (m_os_filter_max == OperatingSystem.winNone
                ? "" : Enum.GetName(typeof(OperatingSystem), m_os_filter_max)));
            e.XmlWriter.WriteAttributeString("os_type_filter", m_os_type_filter);
            e.XmlWriter.WriteAttributeString("os_filter_lcid", m_os_filter_lcid);
            e.XmlWriter.WriteAttributeString("type", m_type);
            e.XmlWriter.WriteAttributeString("installcompletemessage", m_installcompletemessage);
            e.XmlWriter.WriteAttributeString("uninstallcompletemessage", m_uninstallcompletemessage);
            e.XmlWriter.WriteAttributeString("mustreboot", m_mustreboot.ToString());
            e.XmlWriter.WriteAttributeString("reboot_required", m_reboot_required);
            e.XmlWriter.WriteAttributeString("must_reboot_required", m_must_reboot_required.ToString());
            e.XmlWriter.WriteAttributeString("failed_exec_command_continue", m_failed_exec_command_continue);
            e.XmlWriter.WriteAttributeString("allow_continue_on_error", m_allow_continue_on_error.ToString());
            e.XmlWriter.WriteAttributeString("default_continue_on_error", m_default_continue_on_error.ToString());
            e.XmlWriter.WriteAttributeString("required_install", m_required_install.ToString());
            e.XmlWriter.WriteAttributeString("required_uninstall", m_required_uninstall.ToString());
            e.XmlWriter.WriteAttributeString("selected_install", m_selected_install.ToString());
            e.XmlWriter.WriteAttributeString("selected_uninstall", m_selected_uninstall.ToString());
            e.XmlWriter.WriteAttributeString("note", m_note);
            e.XmlWriter.WriteAttributeString("processor_architecture_filter", m_processor_architecture_filter);
            e.XmlWriter.WriteAttributeString("status_installed", m_status_installed);
            e.XmlWriter.WriteAttributeString("status_notinstalled", m_status_notinstalled);
            e.XmlWriter.WriteAttributeString("supports_install", m_supports_install.ToString());
            e.XmlWriter.WriteAttributeString("supports_uninstall", m_supports_uninstall.ToString());
            // dialog options
            e.XmlWriter.WriteAttributeString("show_progress_dialog", m_show_progress_dialog.ToString());
            e.XmlWriter.WriteAttributeString("show_cab_dialog", m_show_cab_dialog.ToString());
            e.XmlWriter.WriteAttributeString("hide_component_if_installed", m_hide_component_if_installed.ToString());
            base.OnXmlWriteTag(e);
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            // backwards compatible description < 1.8
            ReadAttributeValue(e, "description", ref m_display_name);
            ReadAttributeValue(e, "display_name", ref m_display_name);
            ReadAttributeValue(e, "uninstall_display_name", ref m_uninstall_display_name);
            ReadAttributeValue(e, "id", ref m_id);
            if (string.IsNullOrEmpty(m_id)) m_id = m_display_name;
            ReadAttributeValue(e, "installcompletemessage", ref m_installcompletemessage);
            ReadAttributeValue(e, "uninstallcompletemessage", ref m_uninstallcompletemessage);
            ReadAttributeValue(e, "mustreboot", ref m_mustreboot);
            ReadAttributeValue(e, "reboot_required", ref m_reboot_required);
            ReadAttributeValue(e, "must_reboot_required", ref m_must_reboot_required);
            ReadAttributeValue(e, "failed_exec_command_continue", ref m_failed_exec_command_continue);
            ReadAttributeValue(e, "allow_continue_on_error", ref m_allow_continue_on_error);
            ReadAttributeValue(e, "default_continue_on_error", ref m_default_continue_on_error);
            // required -> required_install and required_uninstall
            if (!ReadAttributeValue(e, "required_install", ref m_required_install))
                ReadAttributeValue(e, "required", ref m_required_install);
            if (!ReadAttributeValue(e, "required_uninstall", ref m_required_uninstall))
                m_required_uninstall = m_required_install;
            // selected -> selected_install & selected_uninstall
            if (!ReadAttributeValue(e, "selected_install", ref m_selected_install))
                ReadAttributeValue(e, "selected", ref m_selected_install);
            if (!ReadAttributeValue(e, "selected_uninstall", ref m_selected_uninstall))
                m_selected_uninstall = m_selected_install;
            // filters
            ReadAttributeValue(e, "os_filter", ref m_os_filter);
            ReadAttributeValue(e, "os_type_filter", ref m_os_type_filter);
            ReadAttributeValue(e, "os_filter_lcid", ref m_os_filter_lcid);
            string os_filter_greater = string.Empty;
            if (ReadAttributeValue(e, "os_filter_greater", ref os_filter_greater) && !String.IsNullOrEmpty(os_filter_greater))
                m_os_filter_min = (OperatingSystem)(int.Parse(os_filter_greater) + 1);
            string os_filter_smaller = string.Empty;
            if (ReadAttributeValue(e, "os_filter_smaller", ref os_filter_smaller) && !String.IsNullOrEmpty(os_filter_smaller))
                m_os_filter_max = (OperatingSystem)(int.Parse(os_filter_smaller) - 1);
            ReadAttributeValue(e, "os_filter_min", ref m_os_filter_min);
            ReadAttributeValue(e, "os_filter_max", ref m_os_filter_max);
            ReadAttributeValue(e, "note", ref m_note);
            ReadAttributeValue(e, "processor_architecture_filter", ref m_processor_architecture_filter);
            ReadAttributeValue(e, "status_installed", ref m_status_installed);
            ReadAttributeValue(e, "status_notinstalled", ref m_status_notinstalled);
            ReadAttributeValue(e, "supports_install", ref m_supports_install);
            ReadAttributeValue(e, "supports_uninstall", ref m_supports_uninstall);
            // dialog options
            ReadAttributeValue(e, "show_progress_dialog", ref m_show_progress_dialog);
            ReadAttributeValue(e, "show_cab_dialog", ref m_show_cab_dialog);
            ReadAttributeValue(e, "hide_component_if_installed", ref m_hide_component_if_installed);
            base.OnXmlReadTag(e);
        }

        public static Component CreateFromXml(XmlElement element)
        {
            Component l_Comp;
            string xmltype = element.Attributes["type"].InnerText;
            if (xmltype == "msi")
                l_Comp = new ComponentMsi();
            else if (xmltype == "msu")
                l_Comp = new ComponentMsu();
            else if (xmltype == "msp")
                l_Comp = new ComponentMsp();
            else if (xmltype == "cmd")
                l_Comp = new ComponentCmd();
            else if (xmltype == "openfile")
                l_Comp = new ComponentOpenFile();
            else if (xmltype == "exe")
                l_Comp = new ComponentExe();
            else
                throw new Exception(string.Format("Invalid type: {0}", xmltype));

            l_Comp.FromXml(element);

            return l_Comp;
        }

        /// <summary>
        /// Return files to embed for this component.
        /// </summary>
        /// <param name="parentid"></param>
        /// <param name="supportdir"></param>
        /// <returns></returns>
        public override Dictionary<string, EmbedFileCollection> GetFiles(string parentid, string supportdir)
        {
            return base.GetFiles(id, supportdir);
        }
    }
}
