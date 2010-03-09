using System;
using System.ComponentModel;
using System.IO;
using System.Collections.Generic;

namespace InstallerLib
{
    /// <summary>
    /// A component of type "msp" that executes a Windows Installer patch/patch.
    /// </summary>
    public class ComponentMsp : Component
    {
        public ComponentMsp()
            : base("msp", "mypatch.msp")
        {
            m_patch = "#APPPATH\\mypatch.msp";
            supports_uninstall = true;
        }

        private string m_patch;
        [Description("Specifies a full or a relative path to the msp patch patch.")]
        [Category("Msp")]
        public string patch
        {
            get { return m_patch; }
            set { m_patch = value; }
        }

        private string m_package;
        [Description("Specifies a full or a relative path to the administrative installation package.")]
        [Category("Msp")]
        public string package
        {
            get { return m_package; }
            set { m_package = value; }
        }

        private string m_cmdparameters;
        [Description("Optional command line parameters for the msiexec program.")]
        [Category("Msp")]
        public string cmdparameters
        {
            get { return m_cmdparameters; }
            set { m_cmdparameters = value; }
        }

        private string m_cmdparameters_basic = "/qb-";
        [Description("Optional command line parameters for the msiexec program when running in basic UI mode.")]
        [Category("Msp")]
        public string cmdparameters_basic
        {
            get { return m_cmdparameters_basic; }
            set { m_cmdparameters_basic = value; }
        }

        private string m_cmdparameters_silent = "/qn";
        [Description("Optional command line parameters for the msiexec program when running in silent UI mode.")]
        [Category("Msp")]
        public string cmdparameters_silent
        {
            get { return m_cmdparameters_silent; }
            set { m_cmdparameters_silent = value; }
        }

        private string m_uninstall_patch;
        [Description("Specifies the uninstall patch or patch code GUID.")]
        [Category("Msp")]
        public string uninstall_patch
        {
            get { return m_uninstall_patch; }
            set { uninstall_patch = value; }
        }

        private string m_uninstall_package;
        [Description("Specifies a full or a relative path to the product for which the patch is uninstall or an existing product GUID.")]
        [Category("Msp")]
        public string uninstall_package
        {
            get { return m_uninstall_package; }
            set { m_uninstall_package = value; }
        }

        private string m_uninstall_cmdparameters = "/qb-";
        [Description("Optional command line parameters for the msiexec program on uninstall. May contain quotes. See MSDN for the command line you can use with Windows Installer.")]
        [Category("Msp")]
        public string uninstall_cmdparameters
        {
            get { return m_uninstall_cmdparameters; }
            set { m_uninstall_cmdparameters = value; }
        }

        private string m_uninstall_cmdparameters_basic = "/qb-";
        [Description("Optional command line parameters for the msiexec program on uninstall when running in basic UI mode.")]
        [Category("Msp")]
        public string uninstall_cmdparameters_basic
        {
            get { return m_uninstall_cmdparameters_basic; }
            set { m_uninstall_cmdparameters_basic = value; }
        }

        private string m_uninstall_cmdparameters_silent = "/qn";
        [Description("Optional command line parameters for the msiexec program on uninstall when running in silent UI mode.")]
        [Category("Msp")]
        public string uninstall_cmdparameters_silent
        {
            get { return m_uninstall_cmdparameters_silent; }
            set { m_uninstall_cmdparameters_silent = value; }
        }

        private string m_reinstall = "ALL";
        [Description("Optional value for the REINSTALL property. Without REINSTALL, only the local cached copy of the MSI database is patchd.")]
        [Category("Msp")]
        public string reinstall
        {
            get { return m_reinstall; }
            set { m_reinstall = value; }
        }

        private string m_reinstallmode = "omus";
        [Description("Optional value for the REINSTALLMODE property. Without REINSTALLMODE, only the local cached copy of the MSI database is patchd.")]
        [Category("Msp")]
        public string reinstallmode
        {
            get { return m_reinstallmode; }
            set { m_reinstallmode = value; }
        }

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("patch", m_patch);
            e.XmlWriter.WriteAttributeString("package", m_package);
            e.XmlWriter.WriteAttributeString("cmdparameters", m_cmdparameters);
            e.XmlWriter.WriteAttributeString("cmdparameters_silent", m_cmdparameters_silent);
            e.XmlWriter.WriteAttributeString("cmdparameters_basic", m_cmdparameters_basic);
            e.XmlWriter.WriteAttributeString("uninstall_package", m_uninstall_package);
            e.XmlWriter.WriteAttributeString("uninstall_patch", m_uninstall_patch);
            e.XmlWriter.WriteAttributeString("uninstall_cmdparameters", m_uninstall_cmdparameters);
            e.XmlWriter.WriteAttributeString("uninstall_cmdparameters_silent", m_uninstall_cmdparameters_silent);
            e.XmlWriter.WriteAttributeString("uninstall_cmdparameters_basic", m_uninstall_cmdparameters_basic);
            e.XmlWriter.WriteAttributeString("reinstall", m_reinstall);
            e.XmlWriter.WriteAttributeString("reinstallmode", m_reinstallmode);
            base.OnXmlWriteTag(e);
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            ReadAttributeValue(e, "patch", ref m_patch);
            ReadAttributeValue(e, "package", ref m_package);
            ReadAttributeValue(e, "cmdparameters", ref m_cmdparameters);
            ReadAttributeValue(e, "cmdparameters_silent", ref m_cmdparameters_silent);
            ReadAttributeValue(e, "cmdparameters_basic", ref m_cmdparameters_basic);
            ReadAttributeValue(e, "uninstall_package", ref m_uninstall_package);
            ReadAttributeValue(e, "uninstall_patch", ref m_uninstall_patch);
            ReadAttributeValue(e, "uninstall_cmdparameters", ref m_uninstall_cmdparameters);
            ReadAttributeValue(e, "uninstall_cmdparameters_silent", ref m_uninstall_cmdparameters_silent);
            ReadAttributeValue(e, "uninstall_cmdparameters_basic", ref m_uninstall_cmdparameters_basic);
            ReadAttributeValue(e, "reinstall", ref m_reinstall);
            ReadAttributeValue(e, "reinstallmode", ref m_reinstallmode);
            base.OnXmlReadTag(e);
        }
    }
}
