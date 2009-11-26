using System;
using System.Reflection;
using System.Collections.Generic;

namespace InstallerLib
{
    /// <summary>
    /// A configuration template
    /// </summary>
    public class Template
    {
        private static Template m_CurrentTemplate = null;
        private static List<Template> m_EmbeddedTemplates = null;

        static Template()
        {
            foreach (Template template in EmbeddedTemplates)
            {
                if (m_CurrentTemplate == null || template.Name == "English")
                    m_CurrentTemplate = template;
            }
        }

        public static List<Template> EmbeddedTemplates
        {
            get
            {
                if (m_EmbeddedTemplates == null)
                {
                    m_EmbeddedTemplates = GetEmbeddedTemplates();
                }
                return m_EmbeddedTemplates;
            }
        }

        private static List<Template> GetEmbeddedTemplates()
        {
            List<Template> templates = new List<Template>();
            string[] names = Assembly.GetExecutingAssembly().GetManifestResourceNames();
            foreach (string name in names)
            {
                if (name.StartsWith("InstallerLib.templates."))
                {
                    Template template = new Template(Assembly.GetExecutingAssembly().GetManifestResourceStream(name));
                    templates.Add(template);
                }
            }
            return templates;
        }

        public static Template CurrentTemplate
        {
            get { return m_CurrentTemplate; }
            set { m_CurrentTemplate = value; }
        }

        private System.Xml.XmlDocument m_Document = new System.Xml.XmlDocument();
        private System.Xml.XmlNode m_editortemplate_Node;
        private string m_Name;

        public Template(System.IO.Stream stream)
            : this(stream, "Untitled")
        {
            if (m_editortemplate_Node.Attributes["name"] != null)
            {
                m_Name = m_editortemplate_Node.Attributes["name"].InnerText;
            }
        }

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
            public string uninstall_caption
            {
                get { return m_tpl.GetAttribute("setupconfiguration/@uninstall_caption").Replace(c_APPLICATION_NAME, m_ApplicationName); }
            }
            public string installation_completed
            {
                get { return m_tpl.GetAttribute("setupconfiguration/@installation_completed").Replace(c_APPLICATION_NAME, m_ApplicationName); }
            }
            public string installation_none
            {
                get { return m_tpl.GetAttribute("setupconfiguration/@installation_none").Replace(c_APPLICATION_NAME, m_ApplicationName); }
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

            // message and caption to show during CAB extraction
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

            // path to use during CAB extraction
            public string cab_path
            {
                get { return m_tpl.GetAttribute("setupconfiguration/@cab_path"); }
            }

            public bool cab_path_autodelete
            {
                get { return bool.Parse(m_tpl.GetAttribute("setupconfiguration/@cab_path_autodelete")); }
            }
        }

        public class Template_component
        {
            private const string c_COMPONENT_NAME = "##COMPONENT_NAME";

            private Template m_tpl;
            private string m_component_name;

            public Template_component(Template template, string componentName)
            {
                m_tpl = template;
                m_component_name = componentName;
            }

            public string display_name
            {
                get { return m_tpl.GetAttribute("component/@display_name").Replace(c_COMPONENT_NAME, m_component_name); }
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
            public string dialog_message_copying
            {
                get { return m_tpl.GetAttribute("downloaddialog/@dialog_message_copying").Replace(c_COMPONENT_NAME, m_ComponentName); }
            }
            public string dialog_message_connecting
            {
                get { return m_tpl.GetAttribute("downloaddialog/@dialog_message_connecting").Replace(c_COMPONENT_NAME, m_ComponentName); }
            }
            public string dialog_message_sendingrequest
            {
                get { return m_tpl.GetAttribute("downloaddialog/@dialog_message_sendingrequest").Replace(c_COMPONENT_NAME, m_ComponentName); }
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
