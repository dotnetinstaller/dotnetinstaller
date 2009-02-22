using System;
using System.ComponentModel;
using System.ComponentModel.Design;
using System.Xml;

namespace InstallerEditor
{
	/// <summary>
	/// node:configuration, type=install
	/// </summary>
	public class SetupConfiguration : Configuration
	{
		public SetupConfiguration():this("APPLICATION_NAME")
		{
		}
		public SetupConfiguration(string p_ApplicationName):base("install")
		{
			m_dialog_bitmap = "#APPPATH\\banner.bmp";


			Template.Template_setupconfiguration tpl = Template.CurrentTemplate.setupConfiguration(p_ApplicationName);

			m_cancel_caption = tpl.cancel_caption;
			m_dialog_caption = tpl.dialog_caption;
			m_dialog_message = tpl.dialog_message;
			m_failed_exec_command_continue = tpl.failed_exec_command_continue;
            m_skip_caption = tpl.skip_caption;
			m_install_caption = tpl.install_caption;
			m_installation_completed = tpl.installation_completed;
			m_installing_component_wait = tpl.installing_component_wait;
			m_reboot_required = tpl.reboot_required;
			m_status_installed = tpl.status_installed;
			m_status_notinstalled = tpl.status_notinstalled;

			m_advanced_caption = tpl.advanced_caption;
			m_dialog_selector_caption = tpl.dialog_selector_caption;
			m_dialog_selector_message = tpl.dialog_selector_message;
			m_dialog_selector_ok = tpl.dialog_selector_ok;
			m_dialog_selector_cancel = tpl.dialog_selector_cancel;
      // Matthias Jentsch - 2007-02-06: read OS filter message from template
      m_os_filter_not_match_message = tpl.os_filter_not_match_message;

            // Jason Biegel - 2008-04-22: read processor architecture filter message from template
            m_processor_architecture_filter_not_match_message = tpl.processor_architecture_filter_not_match_message;

//			if (LanguageUI.Language == SupportedLanguage.Italian)
//			{
//				m_cancel_caption = "Chiudi";
//				m_dialog_caption = p_ApplicationName + " Installer";
//				m_dialog_install_next = "Avanti";
//				m_dialog_install_skip = "Annulla";
//				m_dialog_message = "Per installare " + p_ApplicationName + " e' necessario aggiornare questi componenti:";
//				m_failed_exec_command_continue = "Impossibile installare %s. Continuare l'installazione?";
//				m_install_caption = "Installa";
//				m_installation_completed = "Installazione di " + p_ApplicationName + " completata !";
//				m_installing_component_wait = "Installazione di %s in corso. Attendere, l'operazione potrebbe richiedere alcuni minuti ...";
//				m_reboot_required = "Per completare l'installazione e' necessario riavviare il computer. Riavviare ora?";
//				//m_reinstallflag_caption = "Reinstalla tutti i componenti";
//				m_status_installed = " (Installato)";
//				m_status_notinstalled = "";
//
//				m_advanced_caption = "Avanzate";
//				m_dialog_selector_caption = "Selezione Componenti";
//				m_dialog_selector_message = "Seleziona i componenti da installare.";
//				m_dialog_selector_ok = "OK";
//				m_dialog_selector_cancel = "Annulla";
//			}
//			else //english
//			{
//				m_cancel_caption = "Close";
//				m_dialog_caption = p_ApplicationName + " Installer";
//				m_dialog_install_next = "Next";
//				m_dialog_install_skip = "Cancel";
//				m_dialog_message = "In order to install " + p_ApplicationName + " you must first upgrade this components:";
//				m_failed_exec_command_continue = "Failed to install %s. Continue with others components?";
//				m_install_caption = "Install";
//				m_installation_completed = p_ApplicationName + " installed successfully !";
//				m_installing_component_wait = "Installing %s . Wait, this operation could take some time ...";
//				m_reboot_required = "To continue the installation you must restart your computer. Restart now?";
//				//m_reinstallflag_caption = "Reinstall all components";
//				m_status_installed = " (Installed)";
//				m_status_notinstalled = "";
//
//				m_advanced_caption = "Advanced";
//				m_dialog_selector_caption = "Components List";
//				m_dialog_selector_message = "Select the components to install.";
//				m_dialog_selector_ok = "OK";
//				m_dialog_selector_cancel = "Cancel";
//			}
		}

		#region Attributes
		private string m_dialog_caption;
		private string m_dialog_message;
		private string m_dialog_bitmap;
        private string m_skip_caption;
		private string m_install_caption;
		private string m_cancel_caption;
		private string m_status_installed;
		private string m_status_notinstalled;
		private string m_failed_exec_command_continue;
		private string m_installation_completed;
		private string m_installing_component_wait;
		private string m_reboot_required;

		private string m_advanced_caption;
		private string m_dialog_selector_caption;
		private string m_dialog_selector_message;
		private string m_dialog_selector_ok;
		private string m_dialog_selector_cancel;

		private string m_dialog_otherinfo_caption;
		private string m_dialog_otherinfo_link;

		private string m_complete_command;
		private bool m_auto_close_if_installed = true;

		/* Matthias Jentsch - 2006-03-06: added filter for minimal OS version */
		private string m_os_filter_greater;
		/* Matthias Jentsch - 2006-03-06: added filter for maximal OS version */
		private string m_os_filter_smaller;
		/* Matthias Jentsch - 2006-03-06: added message for not matching the OS filter */
		private string m_os_filter_not_match_message;
		
		/* Jason Biegel - 2008-04-22: added filter for processor architecture */
		private string m_processor_architecture_filter;
        
        /* Jason Biegel - 2008-04-22: added message for not matching the processor architecture filter */
        
        private string m_processor_architecture_filter_not_match_message;
		
		[Description("Main dialog title. (REQUIRED)")]
		[Category("Main Dialog")]
		public string dialog_caption
		{
			get{return m_dialog_caption;}
			set{m_dialog_caption = value;}
		}
		[Description("Main message of the main dialog. (REQUIRED)")]
		[Category("Main Dialog")]
		public string dialog_message
		{
			get{return m_dialog_message;}
			set{m_dialog_message = value;}
		}
		[Description("Bitmap file used in the left panel of the main dialog. If this file doesn't exist or this attribute is empty the application load the bitmap from the .exe resource. Can contains path constant (see Help->Path Constant). (OPTIONAL)")]
		[Category("Main Dialog")]
		public string dialog_bitmap
		{
			get{return m_dialog_bitmap;}
			set{m_dialog_bitmap = value;}
		}
        [Description("Caption of the Skip button. (REQUIRED)")]
        [Category("Main Dialog")]
        public string skip_caption
        {
            get { return m_skip_caption; }
            set { m_skip_caption = value; }
        }
        [Description("Caption of the Install button. (REQUIRED)")]
		[Category("Main Dialog")]
		public string install_caption
		{
			get{return m_install_caption;}
			set{m_install_caption = value;}
		}
		[Description("Caption of the Cancel button. (REQUIRED)")]
		[Category("Main Dialog")]
		public string cancel_caption
		{
			get{return m_cancel_caption;}
			set{m_cancel_caption = value;}
		}
		[Description("The string used for indicating an installed component. (OPTIONAL)")]
		[Category("Component")]
		public string status_installed
		{
			get{return m_status_installed;}
			set{m_status_installed = value;}
		}
		[Description("The string used for indicating a not installed component. (OPTIONAL)")]
		[Category("Component")]
		public string status_notinstalled
		{
			get{return m_status_notinstalled;}
			set{m_status_notinstalled = value;}
		}
		[Description("The message used when a component cannot be installed and ask if the application can continue with others components (Yes/No message). Must contain one '%s' string where the application put the description of the component. (REQUIRED)")]
		[Category("Messages")]
		public string failed_exec_command_continue
		{
			get{return m_failed_exec_command_continue;}
			set{m_failed_exec_command_continue = value;}
		}
		[Description("Installation completed message. (REQUIRED)")]
		[Category("Messages")]
		public string installation_completed
		{
			get{return m_installation_completed;}
			set{m_installation_completed = value;}
		}
//		[Description("Caption for the next button. (REQUIRED)")]
//		public string dialog_install_next
//		{
//			get{return m_dialog_install_next;}
//			set{m_dialog_install_next = value;}
//		}
//		[Description("Caption for the skip button. (REQUIRED)")]
//		public string dialog_install_skip
//		{
//			get{return m_dialog_install_skip;}
//			set{m_dialog_install_skip = value;}
//		}
		[Description("The message used when installing a component. Must contain one '%s' string where the application put the description of the component. (REQUIRED)")]
		[Category("Component")]
		public string installing_component_wait
		{
			get{return m_installing_component_wait;}
			set{m_installing_component_wait = value;}
		}
		[Description("The message used when the application need to restart and ask if restart now (with a Yes/No message). (REQUIRED)")]
		[Category("Messages")]
		public string reboot_required
		{
			get{return m_reboot_required;}
			set{m_reboot_required = value;}
		}

		[Description("Caption of the Advanced button. Used to show the 'Component Selector' dialog with the complete list of components available to install. If empty the button Advanced is not available. (OPTIONAL)")]
		[Category("Main Dialog")]
		public string advanced_caption
		{
			get{return m_advanced_caption;}
			set{m_advanced_caption = value;}
		}
		[Description("Component Selector dialog title, this dialog shows the complete list of components available to install. (REQUIRED)")]
		[Category("Component Selector Dialog")]
		public string dialog_selector_caption
		{
			get{return m_dialog_selector_caption;}
			set{m_dialog_selector_caption = value;}
		}
		[Description("Component Selector dialog description, this dialog shows the complete list of components available to install. (REQUIRED)")]
		[Category("Component Selector Dialog")]
		public string dialog_selector_message
		{
			get{return m_dialog_selector_message;}
			set{m_dialog_selector_message = value;}
		}
		[Description("Component Selector dialog OK caption button. (REQUIRED)")]
		[Category("Component Selector Dialog")]
		public string dialog_selector_ok
		{
			get{return m_dialog_selector_ok;}
			set{m_dialog_selector_ok = value;}
		}
		[Description("Component Selector dialog Cancel caption button. (REQUIRED)")]
		[Category("Component Selector Dialog")]
		public string dialog_selector_cancel
		{
			get{return m_dialog_selector_cancel;}
			set{m_dialog_selector_cancel = value;}
		}

		[Description("Caption of the link at the bottom of the main dialog that open the link specified in the dialog_otherinfo_link attribute. If empty the link is hidden. (OPTIONAL)")]
		[Category("Main Dialog")]
		public string dialog_otherinfo_caption
		{
			get{return m_dialog_otherinfo_caption;}
			set{m_dialog_otherinfo_caption = value;}
		}
		[Description("Command to execute when the user click on the link at the bottom of the main installation dialog. Can be any valid command that can be used with ShellExecute API. Must be defined the dialog_otherinfo_caption attribute. Can contains path constant (see Help->Path Constant). (OPTIONAL)")]
		[Category("Main Dialog")]
		public string dialog_otherinfo_link
		{
			get{return m_dialog_otherinfo_link;}
			set{m_dialog_otherinfo_link = value;}
		}

		[Description("Complete command (executed when all components are installed correctly), can be any executable, document or web page valid for ShellExecute API. Usually is a readme file, a web page or a startup file. If empty no command is executed. (OPTIONAL)")]
		public string complete_command
		{
			get{return m_complete_command;}
			set{m_complete_command = value;}
		}
		[Description("If true auto close the dialog (display installation_completed message and execute the complete_command) if all the components are already installed. (REQUIRED)")]
		public bool auto_close_if_installed
		{
			get{return m_auto_close_if_installed;}
			set{m_auto_close_if_installed = value;}
		}

        /* Matthias Jentsch - 2006-03-06: added filter for minimal OS version */
        [Description("A filter to run this setup only on all operating system id greater than the id specified (see Help->Operating System Table). For example to run this setup only in Windows 2000 or later write '44'. (OPTIONAL)")]
		public string os_filter_greater
		{
			get{return m_os_filter_greater;}
			set{m_os_filter_greater = value;}
		}

        /* Matthias Jentsch - 2006-03-06: added filter for maximal OS version */
        [Description("A filter to run this setup only on all operating system id smaller than the id specified (see operating system table). For example to run this setup preceding Windows 2000 write '45'. (OPTIONAL)")]
		public string os_filter_smaller
		{
			get{return m_os_filter_smaller;}
			set{m_os_filter_smaller = value;}
		}

        /* Matthias Jentsch - 2006-03-06: added message for not matching the OS filter */
        [Description("A error message for the case that the operating system does not match the operating system filter (see os_filter_greater and os_filter_smaller). (OPTIONAL)")]
		[Category("Messages")]
		public string os_filter_not_match_message
		{
			get{return m_os_filter_not_match_message;}
			set{m_os_filter_not_match_message = value;}
		}

        /*Jason Biegel - 2008-04-22: added filter for processor architecture */
        [Description("Type of processor architecture (x86, mips, alpha, ppc, shx, arm, ia64, alpha64, msil, x64, ia32onwin64). Separate by commas, can use the NOT sign ('!') to exclude. (es. 'x86,x64' or '!x86'). (OPTIONAL)")]
        public string processor_architecture_filter
        {
            get { return m_processor_architecture_filter; }
            set { m_processor_architecture_filter = value; }
        }

        /* Jason Biegel - 2008-04-22: added message for not matching the processor architecture filter */
        [Description("An error message for the case that the processor architecture does not match the filter (see processor_architecture_filter). (OPTIONAL)")]
        [Category("Messages")]
        public string processor_architecture_filter_not_match_message
        {
            get { return m_processor_architecture_filter_not_match_message; }
            set { m_processor_architecture_filter_not_match_message = value; }
        }
		#endregion

		protected override void OnXmlWriteTagConfiguration(XmlWriterEventArgs e)
		{
			base.OnXmlWriteTagConfiguration (e);
			
			e.XmlWriter.WriteAttributeString("dialog_caption",m_dialog_caption);
			e.XmlWriter.WriteAttributeString("dialog_message",m_dialog_message);
			e.XmlWriter.WriteAttributeString("dialog_bitmap",m_dialog_bitmap);
            e.XmlWriter.WriteAttributeString("skip_caption",m_skip_caption);
			e.XmlWriter.WriteAttributeString("install_caption",m_install_caption);
			e.XmlWriter.WriteAttributeString("cancel_caption",m_cancel_caption);
			//e.XmlWriter.WriteAttributeString("reinstallflag_caption",m_reinstallflag_caption);
			e.XmlWriter.WriteAttributeString("status_installed",m_status_installed);
			e.XmlWriter.WriteAttributeString("status_notinstalled",m_status_notinstalled);
			e.XmlWriter.WriteAttributeString("failed_exec_command_continue",m_failed_exec_command_continue);
			e.XmlWriter.WriteAttributeString("installation_completed",m_installation_completed);
//			e.XmlWriter.WriteAttributeString("dialog_install_next",m_dialog_install_next);
//			e.XmlWriter.WriteAttributeString("dialog_install_skip",m_dialog_install_skip);
			e.XmlWriter.WriteAttributeString("installing_component_wait",m_installing_component_wait);
			e.XmlWriter.WriteAttributeString("reboot_required",m_reboot_required);

			e.XmlWriter.WriteAttributeString("advanced_caption",m_advanced_caption);
			e.XmlWriter.WriteAttributeString("dialog_selector_cancel",m_dialog_selector_cancel);
			e.XmlWriter.WriteAttributeString("dialog_selector_caption",m_dialog_selector_caption);
			e.XmlWriter.WriteAttributeString("dialog_selector_message",m_dialog_selector_message);
			e.XmlWriter.WriteAttributeString("dialog_selector_ok",m_dialog_selector_ok);

			e.XmlWriter.WriteAttributeString("dialog_otherinfo_caption",m_dialog_otherinfo_caption);
			e.XmlWriter.WriteAttributeString("dialog_otherinfo_link",m_dialog_otherinfo_link);

			e.XmlWriter.WriteAttributeString("complete_command",m_complete_command);
			e.XmlWriter.WriteAttributeString("auto_close_if_installed",m_auto_close_if_installed.ToString());

			// Matthias Jentsch - 2006-03-06: new attributes added
			e.XmlWriter.WriteAttributeString("os_filter_greater", m_os_filter_greater);
			e.XmlWriter.WriteAttributeString("os_filter_smaller", m_os_filter_smaller);
			e.XmlWriter.WriteAttributeString("os_filter_not_match_message", m_os_filter_not_match_message);
			
            // Jason Biegel - 2008-04-22: new attributes added
            e.XmlWriter.WriteAttributeString("processor_architecture_filter", m_processor_architecture_filter);
            e.XmlWriter.WriteAttributeString("processor_architecture_filter_not_match_message", m_processor_architecture_filter_not_match_message);

			e.XmlWriter.WriteStartElement("components");
			foreach(Component c in Components)
			{
				c.ToXml(e.XmlWriter);
			}
			e.XmlWriter.WriteEndElement();
		}

		protected override void OnXmlReadTagConfiguration(XmlElementEventArgs e)
		{
			base.OnXmlReadTagConfiguration (e);

			if (e.XmlElement.Attributes["cancel_caption"] != null)
				m_cancel_caption = e.XmlElement.Attributes["cancel_caption"].InnerText;

			if (e.XmlElement.Attributes["dialog_bitmap"] != null)
				m_dialog_bitmap = e.XmlElement.Attributes["dialog_bitmap"].InnerText;

			if (e.XmlElement.Attributes["dialog_caption"] != null)
				m_dialog_caption = e.XmlElement.Attributes["dialog_caption"].InnerText;

//			if (e.XmlElement.Attributes["dialog_install_next"] != null)
//				m_dialog_install_next = e.XmlElement.Attributes["dialog_install_next"].InnerText;
//
//			if (e.XmlElement.Attributes["dialog_install_skip"] != null)
//				m_dialog_install_skip = e.XmlElement.Attributes["dialog_install_skip"].InnerText;

			if (e.XmlElement.Attributes["dialog_message"] != null)
				m_dialog_message = e.XmlElement.Attributes["dialog_message"].InnerText;

			if (e.XmlElement.Attributes["failed_exec_command_continue"] != null)
				m_failed_exec_command_continue = e.XmlElement.Attributes["failed_exec_command_continue"].InnerText;

            if (e.XmlElement.Attributes["skip_caption"] != null)
                m_skip_caption = e.XmlElement.Attributes["skip_caption"].InnerText;

            if (e.XmlElement.Attributes["install_caption"] != null)
				m_install_caption = e.XmlElement.Attributes["install_caption"].InnerText;

			if (e.XmlElement.Attributes["installation_completed"] != null)
				m_installation_completed = e.XmlElement.Attributes["installation_completed"].InnerText;

			if (e.XmlElement.Attributes["installing_component_wait"] != null)
				m_installing_component_wait = e.XmlElement.Attributes["installing_component_wait"].InnerText;

			if (e.XmlElement.Attributes["reboot_required"] != null)
				m_reboot_required = e.XmlElement.Attributes["reboot_required"].InnerText;

//			if (e.XmlElement.Attributes["reinstallflag_caption"] != null)
//				m_reinstallflag_caption = e.XmlElement.Attributes["reinstallflag_caption"].InnerText;

			if (e.XmlElement.Attributes["status_installed"] != null)
				m_status_installed = e.XmlElement.Attributes["status_installed"].InnerText;

			if (e.XmlElement.Attributes["status_notinstalled"] != null)
				m_status_notinstalled = e.XmlElement.Attributes["status_notinstalled"].InnerText;


			if (e.XmlElement.Attributes["advanced_caption"] != null)
				m_advanced_caption = e.XmlElement.Attributes["advanced_caption"].InnerText;

			if (e.XmlElement.Attributes["dialog_selector_cancel"] != null)
				m_dialog_selector_cancel = e.XmlElement.Attributes["dialog_selector_cancel"].InnerText;

			if (e.XmlElement.Attributes["dialog_selector_caption"] != null)
				m_dialog_selector_caption = e.XmlElement.Attributes["dialog_selector_caption"].InnerText;

			if (e.XmlElement.Attributes["dialog_selector_message"] != null)
				m_dialog_selector_message = e.XmlElement.Attributes["dialog_selector_message"].InnerText;

			if (e.XmlElement.Attributes["dialog_selector_ok"] != null)
				m_dialog_selector_ok = e.XmlElement.Attributes["dialog_selector_ok"].InnerText;


			if (e.XmlElement.Attributes["dialog_otherinfo_caption"] != null)
				m_dialog_otherinfo_caption = e.XmlElement.Attributes["dialog_otherinfo_caption"].InnerText;

			if (e.XmlElement.Attributes["dialog_otherinfo_link"] != null)
				m_dialog_otherinfo_link = e.XmlElement.Attributes["dialog_otherinfo_link"].InnerText;


			if (e.XmlElement.Attributes["complete_command"] != null)
				m_complete_command = e.XmlElement.Attributes["complete_command"].InnerText;

			if (e.XmlElement.Attributes["auto_close_if_installed"] != null)
				m_auto_close_if_installed = bool.Parse(e.XmlElement.Attributes["auto_close_if_installed"].InnerText);

            // Matthias Jentsch - 2006-03-06: new attributes added
            if (e.XmlElement.Attributes["os_filter_greater"] != null)
				m_os_filter_greater = e.XmlElement.Attributes["os_filter_greater"].InnerText;
			if (e.XmlElement.Attributes["os_filter_smaller"] != null)
				m_os_filter_smaller = e.XmlElement.Attributes["os_filter_smaller"].InnerText;
			if (e.XmlElement.Attributes["os_filter_not_match_message"] != null)
				m_os_filter_not_match_message = e.XmlElement.Attributes["os_filter_not_match_message"].InnerText;
			
            // Jason Biegel - 2008-04-22: new attributes added
            if (e.XmlElement.Attributes["processor_architecture_filter"] != null)
                m_processor_architecture_filter = e.XmlElement.Attributes["processor_architecture_filter"].InnerText;
			
			XmlNodeList l_List = e.XmlElement.SelectNodes("components/component");
			foreach (XmlElement l_XmlComp in l_List)
			{
				if (l_XmlComp.Attributes["type"] != null)
				{
					Component l_Comp = Component.CreateComponentFromXml(l_XmlComp);

					Components.Add(l_Comp);
				}
				else
					throw new ApplicationException("Type cannot be null");
			}
		}


		private ComponentCollection m_Components = new ComponentCollection();
		public ComponentCollection Components
		{
			get{return m_Components;}
			set{m_Components = value;}
		}
	}
}
