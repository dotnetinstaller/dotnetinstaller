using System;
using System.ComponentModel;

namespace InstallerLib
{
	/// <summary>
	/// Tag component of type cmd
	/// </summary>
	public class ComponentCmd : Component
	{
		public ComponentCmd():this("COMPONENT_NAME")
		{
		}
		public ComponentCmd(string p_ComponentName):base("cmd", p_ComponentName)
		{
			m_command = "\"#APPPATH\\mysetup.exe\" -q\"";
		}


		private string m_command;
		[Description("Specifies the command to execute when installing this component. Can contain \" char and path constant (see Help->Path Constant). (REQUIRED)")]
		public string command
		{
			get{return m_command;}
			set{m_command = value;}
		}

        private string m_command_silent;
        [Description("Specifies the command to execute on silent install. Defaults to command when blank. (OPTIONAL)")]
        public string command_silent
        {
            get { return m_command_silent; }
            set { m_command_silent = value; }
        }

		protected override void OnXmlWriteTagcomponent(XmlWriterEventArgs e)
		{
			base.OnXmlWriteTagcomponent (e);

			e.XmlWriter.WriteAttributeString("command",m_command);
		}


		protected override void OnXmlReadTagcomponent(XmlElementEventArgs e)
		{
			base.OnXmlReadTagcomponent (e);

			if (e.XmlElement.Attributes["command"] != null)
				m_command = e.XmlElement.Attributes["command"].InnerText;
            if (e.XmlElement.Attributes["command_silent"] != null)
                m_command_silent = e.XmlElement.Attributes["command_silent"].InnerText;
        }

	}
}
