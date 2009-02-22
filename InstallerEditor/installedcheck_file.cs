using System;
using System.ComponentModel;

namespace InstallerEditor
{
	/// <summary>
	/// installedcheck of type check_registry_value
	/// </summary>
	public class installedcheck_file : installedcheck
	{
		public installedcheck_file():base("check_file")
		{
			m_filename = "#SYSTEMPATH\\my_dll.dll";
			m_comparison = installcheck_comparison.version;
			m_fileversion = "2.1.0.0";
		}

		private string m_filename;
		[Description("Specifies the file to search, if the application cannot find the specified file then the component must be installed. This attribute can contain path constant (see Help->Path Constant). (REQUIRED)")]
		public string filename
		{
			get{return m_filename;}
			set{m_filename = value;}
		}

		private string m_fileversion;
		[Description("The version of the file, can be used to perform version check based on comparison attribute. If empty the application check only for the presence of the file. (OPTIONAL)")]
		public string fileversion
		{
			get{return m_fileversion;}
			set{m_fileversion = value;}
		}

		private installcheck_comparison m_comparison;
		[Description("Comparison mode, can be 'match' to check if the exact version of the file is present or 'version' to compare if a version equal or greater is present. (REQUIRED)")]
		public installcheck_comparison comparison
		{
			get{return m_comparison;}
			set{m_comparison = value;}
		}


		protected override void OnXmlWriteTaginstalledcheck(XmlWriterEventArgs e)
		{
			base.OnXmlWriteTaginstalledcheck (e);

			e.XmlWriter.WriteAttributeString("filename",m_filename);
			e.XmlWriter.WriteAttributeString("fileversion",m_fileversion);
			e.XmlWriter.WriteAttributeString("comparison",m_comparison.ToString());
		}


		protected override void OnXmlReadTaginstalledcheck(XmlElementEventArgs e)
		{
			base.OnXmlReadTaginstalledcheck (e);

			if (e.XmlElement.Attributes["filename"] != null)
				m_filename = e.XmlElement.Attributes["filename"].InnerText;

			if (e.XmlElement.Attributes["fileversion"] != null)
				m_fileversion = e.XmlElement.Attributes["fileversion"].InnerText;

			if (e.XmlElement.Attributes["comparison"] != null)
				m_comparison = (installcheck_comparison)Enum.Parse(typeof(installcheck_comparison),e.XmlElement.Attributes["comparison"].InnerText,true);
		}
	}
}
