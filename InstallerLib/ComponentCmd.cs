using System;
using System.ComponentModel;

namespace InstallerLib
{
    /// <summary>
    /// A component of type "cmd" that executes a command.
    /// </summary>
    public class ComponentCmd : Component
    {
        public ComponentCmd()
            : base("cmd", "command1")
        {
            m_command = "cmd.exe /C \"#APPPATH\\mysetup.exe\"";
        }

        #region Commands

        private string m_command;
        [Description("Specifies the command to execute when installing this component. Can contain \" char and path constant (see Help->Path Constant). (REQUIRED)")]
        [Category("Install")]
        public string command
        {
            get { return m_command; }
            set { m_command = value; }
        }

        private string m_command_silent;
        [Description("Specifies the command to execute on silent install. Defaults to command when blank. (OPTIONAL)")]
        [Category("Install")]
        public string command_silent
        {
            get { return m_command_silent; }
            set { m_command_silent = value; }
        }

        private string m_command_basic;
        [Description("Specifies the command to execute on basic UI install. Defaults to command when blank. (OPTIONAL)")]
        [Category("Install")]
        public string command_basic
        {
            get { return m_command_basic; }
            set { m_command_basic = value; }
        }

        private string m_uninstall_command;
        [Description("Specifies the command to execute when uninstalling this component.")]
        [Category("Uninstall")]
        public string uninstall_command
        {
            get { return m_uninstall_command; }
            set { m_uninstall_command = value; }
        }

        private string m_uninstall_command_silent;
        [Description("Specifies the command to execute on silent uninstall. Defaults to uninstall_command when blank.")]
        [Category("Uninstall")]
        public string uninstall_command_silent
        {
            get { return m_uninstall_command_silent; }
            set { m_uninstall_command_silent = value; }
        }

        private string m_uninstall_command_basic;
        [Description("Specifies the command to execute on basic UI uninstall. Defaults to uninstall_command when blank.")]
        [Category("Uninstall")]
        public string uninstall_command_basic
        {
            get { return m_uninstall_command_basic; }
            set { m_uninstall_command_basic = value; }
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

        #endregion

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("command", m_command);
            e.XmlWriter.WriteAttributeString("command_silent", m_command_silent);
            e.XmlWriter.WriteAttributeString("command_basic", m_command_basic);
            e.XmlWriter.WriteAttributeString("uninstall_command", m_uninstall_command);
            e.XmlWriter.WriteAttributeString("uninstall_command_silent", m_uninstall_command_silent);
            e.XmlWriter.WriteAttributeString("uninstall_command_basic", m_uninstall_command_basic);
            e.XmlWriter.WriteAttributeString("returncodes_success", m_returncodes_success);
            e.XmlWriter.WriteAttributeString("returncodes_reboot", m_returncodes_reboot);
            base.OnXmlWriteTag(e);
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            ReadAttributeValue(e, "command", ref m_command);
            ReadAttributeValue(e, "command_silent", ref m_command_silent);
            ReadAttributeValue(e, "command_basic", ref m_command_basic);
            ReadAttributeValue(e, "uninstall_command", ref m_uninstall_command);
            ReadAttributeValue(e, "uninstall_command_silent", ref m_uninstall_command_silent);
            ReadAttributeValue(e, "uninstall_command_basic", ref m_uninstall_command_basic);
            ReadAttributeValue(e, "returncodes_success", ref m_returncodes_success);
            ReadAttributeValue(e, "returncodes_reboot", ref m_returncodes_reboot);
            base.OnXmlReadTag(e);
        }
    }
}
