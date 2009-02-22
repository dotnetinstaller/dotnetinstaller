using System;
using System.ComponentModel;

namespace InstallerEditor
{
	/// <summary>
	/// Tag component of type openfile
	/// </summary>
	public class ComponentOpenFile : Component
	{
		public ComponentOpenFile():base("openfile")
		{
		}

		private string m_file;
		[Description("Specifies the file to open when installing this component. Can contain \" char and path constant (see Help->Path Constant). Can be for example a internet link. (REQUIRED)")]
		public string file
		{
			get{return m_file;}
			set{m_file = value;}
		}

		protected override void OnXmlWriteTagcomponent(XmlWriterEventArgs e)
		{
			base.OnXmlWriteTagcomponent (e);

			e.XmlWriter.WriteAttributeString("file",m_file);
		}


		protected override void OnXmlReadTagcomponent(XmlElementEventArgs e)
		{
			base.OnXmlReadTagcomponent (e);

			if (e.XmlElement.Attributes["file"] != null)
				m_file = e.XmlElement.Attributes["file"].InnerText;
		}

	}
}
