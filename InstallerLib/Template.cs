using System;

namespace InstallerLib
{
    public class Template
    {
        private static Template m_DefaultTemplate;
        private static Template m_CurrentTemplate;

        static Template()
        {
            m_DefaultTemplate = new Template(System.Reflection.Assembly.GetExecutingAssembly().GetManifestResourceStream(
                "InstallerLib.templates.english_template.xml"), "Default (English)");
            m_CurrentTemplate = m_DefaultTemplate;
        }

        public static Template DefaultTemplate
        {
            get { return m_DefaultTemplate; }
        }

        public static Template CurrentTemplate
        {
            get { return m_CurrentTemplate; }
            set { m_CurrentTemplate = value; }
        }

        private System.Xml.XmlDocument m_Document = new System.Xml.XmlDocument();
        private System.Xml.XmlNode m_editortemplate_Node;
        private string m_Name;
        public Template(System.IO.Stream stream, string pName)
        {
            m_Document.Load(stream);
            m_editortemplate_Node = m_Document.SelectSingleNode("//editortemplate");
            if (m_editortemplate_Node == null)
            {
                throw new Exception("Invalid template file");
            }

            m_Name = pName;
        }

        public string Name
        {
            get { return m_Name; }
        }

        public string GetAttribute(string xPathQuery)
        {
            System.Xml.XmlNode node = m_editortemplate_Node.SelectSingleNode(xPathQuery);
            if (node == null)
                return "!!!! ERROR - Attribute " + xPathQuery + " not found in template file!!!!!";

            return node.InnerText;
        }

        public class Template_setupconfiguration
        {
            private const string c_APPLICATION_NAME = "##APPLICATION_NAME";

            private Template m_tpl;
            private string m_ApplicationName;
            public Template_setupconfiguration(Template template, string applicationName)
            {
                m_tpl = template;
                m_ApplicationName = applicationName;
            }
            public string cancel_caption
            {
                get { return m_tpl.GetAttribute("setupconfiguration/@cancel_caption").Replace(c_APPLICATION_NAME, m_ApplicationName); }
            }
            public string dialog_caption
            {
                get { return m_tpl.GetAttribute("setupconfiguration/@dialog_caption").Replace(c_APPLICATION_NAME, m_ApplicationName); }
            }
            public string dialog_message
            {
                get { return m_tpl.GetAttribute("setupconfiguration/@dialog_message").Replace(c_APPLICATION_NAME, m_ApplicationName); }
            }
            public string failed_exec_command_continue
            {
                get { return m_tpl.GetAttribute("setupconfiguration/@failed_exec_command_continue").Replace(c_APPLICATION_NAME, m_ApplicationName); }
            }
            public string skip_caption
            {
                get { return m_tpl.GetAttribute("setupconfiguration/@skip_caption").Replace(c_APPLICATION_NAME, m_ApplicationName); }
            }
            public string install_caption
            {
                get { return m_tpl.GetAttribute("setupconfiguration/@install_caption").Replace(c_APPLICATION_NAME, m_ApplicationName); }
            }
            public string installation_completed
            {
                get { return m_tpl.GetAttribute("setupconfiguration/@installation_completed").Replace(c_APPLICATION_NAME, m_ApplicationName); }
            }
            public string installing_component_wait
            {
                get { return m_tpl.GetAttribute("setupconfiguration/@installing_component_wait").Replace(c_APPLICATION_NAME, m_ApplicationName); }
            }
            public string reboot_required
            {
                get { return m_tpl.GetAttribute("setupconfiguration/@reboot_required").Replace(c_APPLICATION_NAME, m_ApplicationName); }
            }
            public string status_installed
            {
                get { return m_tpl.GetAttribute("setupconfiguration/@status_installed").Replace(c_APPLICATION_NAME, m_ApplicationName); }
            }
            public string status_notinstalled
            {
                get { return m_tpl.GetAttribute("setupconfiguration/@status_notinstalled").Replace(c_APPLICATION_NAME, m_ApplicationName); }
            }
            public string advanced_caption
            {
                get { return m_tpl.GetAttribute("setupconfiguration/@advanced_caption").Replace(c_APPLICATION_NAME, m_ApplicationName); }
            }
            public string dialog_selector_caption
            {
                get { return m_tpl.GetAttribute("setupconfiguration/@dialog_selector_caption").Replace(c_APPLICATION_NAME, m_ApplicationName); }
            }
            public string dialog_selector_message
            {
                get { return m_tpl.GetAttribute("setupconfiguration/@dialog_selector_message").Replace(c_APPLICATION_NAME, m_ApplicationName); }
            }
            public string dialog_selector_ok
            {
                get { return m_tpl.GetAttribute("setupconfiguration/@dialog_selector_ok").Replace(c_APPLICATION_NAME, m_ApplicationName); }
            }
            public string dialog_selector_cancel
            {
                get { return m_tpl.GetAttribute("setupconfiguration/@dialog_selector_cancel").Replace(c_APPLICATION_NAME, m_ApplicationName); }
            }
            // Matthias Jentsch - 2007-02-06 added OS filter message to templates
            public string os_filter_not_match_message
            {
                get { return m_tpl.GetAttribute("setupconfiguration/@os_filter_not_match_message").Replace(c_APPLICATION_NAME, m_ApplicationName); }
            }

            // Jason Biegel - 2008-04-22 added processor architecture message to templates
            public string processor_architecture_filter_not_match_message
            {
                get { return m_tpl.GetAttribute("setupconfiguration/@processor_architecture_filter_not_match_message").Replace(c_APPLICATION_NAME, m_ApplicationName); }
            }

            // Daniel Doubrovkine - 2008-06-06: added message and caption to show during CAB extraction
            public string cab_dialog_message
            {
                get { return m_tpl.GetAttribute("setupconfiguration/@cab_dialog_message").Replace(c_APPLICATION_NAME, m_ApplicationName); }
            }

            public string cab_cancelled_message
            {
                get { return m_tpl.GetAttribute("setupconfiguration/@cab_cancelled_message").Replace(c_APPLICATION_NAME, m_ApplicationName); }
            }

            public string cab_dialog_caption
            {
                get { return m_tpl.GetAttribute("setupconfiguration/@cab_dialog_caption").Replace(c_APPLICATION_NAME, m_ApplicationName); }
            }

            // Daniel Doubrovkine - 2008-06-06: added path to use during CAB extraction
            public string cab_path
            {
                get { return m_tpl.GetAttribute("setupconfiguration/@cab_path"); }
            }

            public bool cab_path_autodelete
            {
                get { return bool.Parse(m_tpl.GetAttribute("setupconfiguration/@cab_path_autodelete")); }
            }

            // Daniel Doubrovkine - 2008-06-24: added auto-enabled log
            public bool log_enabled
            {
                get { return bool.Parse(m_tpl.GetAttribute("setupconfiguration/@log_enabled")); }
            }

            public string log_file
            {
                get { return m_tpl.GetAttribute("setupconfiguration/@log_file"); }
            }
        }

        public class Template_component
        {
            private const string c_COMPONENT_NAME = "##COMPONENT_NAME";

            private Template m_tpl;
            private string m_ComponentName;
            public Template_component(Template template, string componentName)
            {
                m_tpl = template;
                m_ComponentName = componentName;
            }
            public string description
            {
                get { return m_tpl.GetAttribute("component/@description").Replace(c_COMPONENT_NAME, m_ComponentName); }
            }
            public string installcompletemessage
            {
                get { return m_tpl.GetAttribute("component/@installcompletemessage").Replace(c_COMPONENT_NAME, m_ComponentName); }
            }
        }

        public class Template_downloaddialog
        {
            private const string c_COMPONENT_NAME = "##COMPONENT_NAME";

            private Template m_tpl;
            private string m_ComponentName;
            public Template_downloaddialog(Template template, string componentName)
            {
                m_tpl = template;
                m_ComponentName = componentName;
            }
            public string buttoncancel_caption
            {
                get { return m_tpl.GetAttribute("downloaddialog/@buttoncancel_caption").Replace(c_COMPONENT_NAME, m_ComponentName); }
            }
            public string buttonstart_caption
            {
                get { return m_tpl.GetAttribute("downloaddialog/@buttonstart_caption").Replace(c_COMPONENT_NAME, m_ComponentName); }
            }
            public string dialog_caption
            {
                get { return m_tpl.GetAttribute("downloaddialog/@dialog_caption").Replace(c_COMPONENT_NAME, m_ComponentName); }
            }
            public string dialog_message
            {
                get { return m_tpl.GetAttribute("downloaddialog/@dialog_message").Replace(c_COMPONENT_NAME, m_ComponentName); }
            }
            public string dialog_message_downloading
            {
                get { return m_tpl.GetAttribute("downloaddialog/@dialog_message_downloading").Replace(c_COMPONENT_NAME, m_ComponentName); }
            }
        }

        public Template_setupconfiguration setupConfiguration(string applicationName)
        {
            return new Template_setupconfiguration(this, applicationName);
        }
        public Template_component component(string componentName)
        {
            return new Template_component(this, componentName);
        }
        public Template_downloaddialog downloaddialog(string componentName)
        {
            return new Template_downloaddialog(this, componentName);
        }
    }
}
