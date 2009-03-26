using System;
using System.ComponentModel;
using System.IO;
using System.Collections.Generic;

namespace InstallerLib
{
    /// <summary>
    /// A component of type "msi" that executes a Windows Installer package.
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

        private bool m_embed = true;
        [Description("Automatically embed MSI package when building a packaged setup.")]
        public bool embed
        {
            get { return m_embed; }
            set { m_embed = value; }
        }

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("package", m_package);
            e.XmlWriter.WriteAttributeString("cmdparameters", m_cmdparameters);
            e.XmlWriter.WriteAttributeString("cmdparameters_silent", m_cmdparameters_silent);
            e.XmlWriter.WriteAttributeString("embed", m_embed.ToString());
            base.OnXmlWriteTag(e);
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            ReadAttributeValue(e, "package", ref m_package);
            ReadAttributeValue(e, "cmdparameters", ref m_cmdparameters);
            ReadAttributeValue(e, "cmdparameters_silent", ref m_cmdparameters_silent);
            ReadAttributeValue(e, "embed", ref m_embed);
            base.OnXmlReadTag(e);
        }

        public override EmbedFileCollection GetFiles()
        {
            EmbedFileCollection files = base.GetFiles();
            if (embed) files.Add(new EmbedFile(package));
            return files;
        }
    }
}
