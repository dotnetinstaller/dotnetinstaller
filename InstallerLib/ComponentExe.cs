using System;
using System.ComponentModel;

namespace InstallerLib
{
    public enum ResponseFileFormat
    {
        none,
        text,
        ini
    }

    /// <summary>
    /// A component of type "exe" that runs an executable installer with a response file.
    /// </summary>
    public class ComponentExe : Component
    {
        public ComponentExe()
            : base("exe", "setup.exe")
        {
            m_executable = "setup.exe";
        }

        #region Commands

        private string m_executable;
        [Description("Specifies the executable to run when installing this component.")]
        [Category("Install")]
        public string executable
        {
            get { return m_executable; }
            set { m_executable = value; }
        }

        private string m_executable_silent;
        [Description("Specifies the executable to run on silent install. Defaults to executable when blank.")]
        [Category("Install")]
        public string executable_silent
        {
            get { return m_executable_silent; }
            set { m_executable_silent = value; }
        }

        private string m_executable_basic;
        [Description("Specifies the executable to run on basic UI install. Defaults to executable when blank.")]
        [Category("Install")]
        public string executable_basic
        {
            get { return m_executable_basic; }
            set { m_executable_basic = value; }
        }

        private string m_uninstall_executable;
        [Description("Specifies the executable to run when uninstalling this component.")]
        [Category("Uninstall")]
        public string uninstall_executable
        {
            get { return m_uninstall_executable; }
            set { m_uninstall_executable = value; }
        }

        private string m_uninstall_executable_silent;
        [Description("Specifies the executable to run on silent uninstall. Defaults to uninstall_executable when blank.")]
        [Category("Uninstall")]
        public string uninstall_executable_silent
        {
            get { return m_uninstall_executable_silent; }
            set { m_uninstall_executable_silent = value; }
        }

        private string m_uninstall_executable_basic;
        [Description("Specifies the executable to run on basic UI uninstall. Defaults to uninstall_executable when blank.")]
        [Category("Uninstall")]
        public string uninstall_executable_basic
        {
            get { return m_uninstall_executable_basic; }
            set { m_uninstall_executable_basic = value; }
        }

        private ResponseFileFormat m_responsefile_format = ResponseFileFormat.none;
        [Description("Specifies response file format. Ini and text response files are processed.")]
        [Category("Response File")]
        public ResponseFileFormat responsefile_format
        {
            get { return m_responsefile_format; }
            set { m_responsefile_format = value; }
        }

        private string m_responsefile_source;
        [Description("Specifies an optional response file source.")]
        [Category("Install")]
        public string responsefile_source
        {
            get { return m_responsefile_source; }
            set { m_responsefile_source = value; }
        }

        private string m_responsefile_target;
        [Description("Specifies an optional response file output.")]
        [Category("Install")]
        public string responsefile_target
        {
            get { return m_responsefile_target; }
            set { m_responsefile_target = value; }
        }

        private string m_uninstall_responsefile_source;
        [Description("Specifies an optional response file for uninstallation.")]
        [Category("Uninstall")]
        public string uninstall_responsefile_source
        {
            get { return m_uninstall_responsefile_source; }
            set { m_uninstall_responsefile_source = value; }
        }

        private string m_uninstall_responsefile_target;
        [Description("Specifies an optional response file output for uninstallation.")]
        [Category("Uninstall")]
        public string uninstall_responsefile_target
        {
            get { return m_uninstall_responsefile_target; }
            set { m_uninstall_responsefile_target = value; }
        }

        #endregion

        #region Return Codes

        private string m_returncodes_success;
        [Description("Comma-separated return codes that indicate success. By default a return value of 0 indicates success.")]
        [Category("Return Codes")]
        public string returncodes_success
        {
            get { return m_returncodes_success; }
            set { m_returncodes_success = value; }
        }

        private string m_returncodes_reboot;
        [Description("Comma-separated error codes that indicate that a reboot is requred.")]
        [Category("Return Codes")]
        public string returncodes_reboot
        {
            get { return m_returncodes_reboot; }
            set { m_returncodes_reboot = value; }
        }

        private string m_exeparameters;
        [Description("Optional command line parameters for the executable setup.")]
        [Category("Install")]
        public string exeparameters
        {
            get { return m_exeparameters; }
            set { m_exeparameters = value; }
        }

        private string m_exeparameters_basic;
        [Description("Optional command line parameters for the executable setup in basic UI mode.")]
        [Category("Install")]
        public string exeparameters_basic
        {
            get { return m_exeparameters_basic; }
            set { m_exeparameters_basic = value; }
        }

        private string m_exeparameters_silent;
        [Description("Optional command line parameters for the executable setup in silent UI mode.")]
        [Category("Install")]
        public string exeparameters_silent
        {
            get { return m_exeparameters_silent; }
            set { m_exeparameters_silent = value; }
        }

        private string m_uninstall_exeparameters;
        [Description("Optional command line parameters for the executable setup on uninstall.")]
        [Category("Uninstall")]
        public string uninstall_exeparameters
        {
            get { return m_uninstall_exeparameters; }
            set { m_uninstall_exeparameters = value; }
        }

        private string m_uninstall_exeparameters_basic;
        [Description("Optional command line parameters for the executable setup in basic UI mode on uninstall.")]
        [Category("Uninstall")]
        public string uninstall_exeparameters_basic
        {
            get { return m_uninstall_exeparameters_basic; }
            set { m_uninstall_exeparameters_basic = value; }
        }

        private string m_uninstall_exeparameters_silent;
        [Description("Optional command line parameters for the executable setup in silent UI mode on uninstall.")]
        [Category("Uninstall")]
        public string uninstall_exeparameters_silent
        {
            get { return m_uninstall_exeparameters_silent; }
            set { m_uninstall_exeparameters_silent = value; }
        }

        #endregion

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("executable", m_executable);
            e.XmlWriter.WriteAttributeString("executable_silent", m_executable_silent);
            e.XmlWriter.WriteAttributeString("executable_basic", m_executable_basic);
            e.XmlWriter.WriteAttributeString("responsefile_source", m_responsefile_source);
            e.XmlWriter.WriteAttributeString("responsefile_target", m_responsefile_target);
            e.XmlWriter.WriteAttributeString("responsefile_format", m_responsefile_format.ToString());
            e.XmlWriter.WriteAttributeString("uninstall_executable", m_uninstall_executable);
            e.XmlWriter.WriteAttributeString("uninstall_executable_silent", m_uninstall_executable_silent);
            e.XmlWriter.WriteAttributeString("uninstall_executable_basic", m_uninstall_executable_basic);
            e.XmlWriter.WriteAttributeString("uninstall_responsefile_source", m_uninstall_responsefile_source);
            e.XmlWriter.WriteAttributeString("uninstall_responsefile_target", m_uninstall_responsefile_target);
            e.XmlWriter.WriteAttributeString("returncodes_success", m_returncodes_success);
            e.XmlWriter.WriteAttributeString("returncodes_reboot", m_returncodes_reboot);
            e.XmlWriter.WriteAttributeString("exeparameters", m_exeparameters);
            e.XmlWriter.WriteAttributeString("exeparameters_basic", m_exeparameters_basic);
            e.XmlWriter.WriteAttributeString("exeparameters_silent", m_exeparameters_silent);
            e.XmlWriter.WriteAttributeString("uninstall_exeparameters", m_uninstall_exeparameters);
            e.XmlWriter.WriteAttributeString("uninstall_exeparameters_basic", m_uninstall_exeparameters_basic);
            e.XmlWriter.WriteAttributeString("uninstall_exeparameters_silent", m_uninstall_exeparameters_silent);
            base.OnXmlWriteTag(e);
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            ReadAttributeValue(e, "executable", ref m_executable);
            ReadAttributeValue(e, "executable_silent", ref m_executable_silent);
            ReadAttributeValue(e, "executable_basic", ref m_executable_basic);
            ReadAttributeValue(e, "responsefile_source", ref m_responsefile_source);
            ReadAttributeValue(e, "responsefile_target", ref m_responsefile_target);
            ReadAttributeValue(e, "responsefile_format", ref m_responsefile_format);
            ReadAttributeValue(e, "uninstall_executable", ref m_uninstall_executable);
            ReadAttributeValue(e, "uninstall_executable_silent", ref m_uninstall_executable_silent);
            ReadAttributeValue(e, "uninstall_executable_basic", ref m_uninstall_executable_basic);
            ReadAttributeValue(e, "uninstall_responsefile_source", ref m_uninstall_responsefile_source);
            ReadAttributeValue(e, "uninstall_responsefile_target", ref m_uninstall_responsefile_target);
            ReadAttributeValue(e, "returncodes_success", ref m_returncodes_success);
            ReadAttributeValue(e, "returncodes_reboot", ref m_returncodes_reboot);
            ReadAttributeValue(e, "exeparameters", ref m_exeparameters);
            ReadAttributeValue(e, "exeparameters_basic", ref m_exeparameters_basic);
            ReadAttributeValue(e, "exeparameters_silent", ref m_exeparameters_silent);
            ReadAttributeValue(e, "uninstall_exeparameters", ref m_uninstall_exeparameters);
            ReadAttributeValue(e, "uninstall_exeparameters_basic", ref m_uninstall_exeparameters_basic);
            ReadAttributeValue(e, "uninstall_exeparameters_silent", ref m_uninstall_exeparameters_silent);
            base.OnXmlReadTag(e);
        }
    }
}
