using System;
using System.ComponentModel;
using System.IO;
using System.Collections.Generic;

namespace InstallerEditor
{
    /// <summary>
    /// Tag component of type msi
    /// </summary>
    public class ComponentMsi : Component
    {
        public ComponentMsi()
            : base("msi")
        {
            m_package = "#APPPATH\\mysetup.msi";
        }

        private string m_package;
        [Description("Specifies the path to the msi package to execute when installing this component. Can contain path constant (see Help->Path Constant). (REQUIRED)")]
        public string package
        {
            get { return m_package; }
            set { m_package = value; }
        }

        private string m_cmdparameters;
        [Description("Specifies the command line parameters for the msiexec program. Can contain \" char and path constant (see Help->Path Constant). See MSDN for the command line you can use with Windows Installer. (OPTIONAL)")]
        public string cmdparameters
        {
            get { return m_cmdparameters; }
            set { m_cmdparameters = value; }
        }

        private string m_cmdparameters_silent;
        [Description("Specifies the command line parameters for the msiexec program when running a silent install. Defaults to cmdparameters if blank. Can contain \" char and path constant (see Help->Path Constant). See MSDN for the command line you can use with Windows Installer. (OPTIONAL)")]
        public string cmdparameters_silent
        {
            get { return m_cmdparameters_silent; }
            set { m_cmdparameters_silent = value; }
        }

        protected override void OnXmlWriteTagcomponent(XmlWriterEventArgs e)
        {
            base.OnXmlWriteTagcomponent(e);

            e.XmlWriter.WriteAttributeString("package", m_package);
            e.XmlWriter.WriteAttributeString("cmdparameters", m_cmdparameters);
            e.XmlWriter.WriteAttributeString("cmdparameters_silent", m_cmdparameters_silent);
        }

        protected override void OnXmlReadTagcomponent(XmlElementEventArgs e)
        {
            base.OnXmlReadTagcomponent(e);

            if (e.XmlElement.Attributes["package"] != null)
                m_package = e.XmlElement.Attributes["package"].InnerText;

            if (e.XmlElement.Attributes["cmdparameters"] != null)
                m_cmdparameters = e.XmlElement.Attributes["cmdparameters"].InnerText;

            if (e.XmlElement.Attributes["cmdparameters_silent"] != null)
                m_cmdparameters_silent = e.XmlElement.Attributes["cmdparameters_silent"].InnerText;
        }

        public override IList<string> GetFiles()
        {
            IList<string> files = base.GetFiles();
            if (!files.Contains(package))
            {
                files.Add(package);
            }
            return files;
        }
    }
}
