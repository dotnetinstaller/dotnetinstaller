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
            : this("COMPONENT_NAME")
        {
        }

        public ComponentCmd(string p_ComponentName)
            : base("cmd", p_ComponentName)
        {
            m_command = "cmd.exe /C \"#APPPATH\\mysetup.exe\"";
        }

        private string m_command;
        [Description("Specifies the command to execute when installing this component. Can contain \" char and path constant (see Help->Path Constant). (REQUIRED)")]
        public string command
        {
            get { return m_command; }
            set { m_command = value; }
        }

        private string m_command_silent;
        [Description("Specifies the command to execute on silent install. Defaults to command when blank. (OPTIONAL)")]
        public string command_silent
        {
            get { return m_command_silent; }
            set { m_command_silent = value; }
        }

        private string m_command_basic;
        [Description("Specifies the command to execute on basic UI install. Defaults to command when blank. (OPTIONAL)")]
        public string command_basic
        {
            get { return m_command_basic; }
            set { m_command_basic = value; }
        }

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("command", m_command);
            e.XmlWriter.WriteAttributeString("command_silent", m_command_silent);
            e.XmlWriter.WriteAttributeString("command_basic", m_command_basic);
            base.OnXmlWriteTag(e);
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            ReadAttributeValue(e, "command", ref m_command);
            ReadAttributeValue(e, "command_silent", ref m_command_silent);
            ReadAttributeValue(e, "command_basic", ref m_command_silent);
            base.OnXmlReadTag(e);
        }
    }
}
