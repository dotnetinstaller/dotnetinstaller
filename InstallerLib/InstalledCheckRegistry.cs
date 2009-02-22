using System;
using System.Xml;
using System.ComponentModel;

namespace InstallerLib
{
	/// <summary>
	/// InstalledCheck of type check_registry_value
	/// </summary>
	public class InstalledCheckRegistry : InstalledCheck
	{
		public InstalledCheckRegistry():base("check_registry_value")
		{
			m_path = "SOFTWARE\\MyCompany\\MyApplication\\1.0.1.0";
			m_comparison = installcheck_comparison.match;
			m_fieldname = "Installed";
			m_fieldtype = installcheck_registrytype.REG_DWORD;
			m_fieldvalue = "1";
		    m_rootkey = installcheck_rootkey.HKEY_LOCAL_MACHINE;
            m_wowoption = installcheck_wowoption.NONE;
		}

		private string m_path;
		[Description("Specifies the registry path to search for the registry value specified, must be a path under HKEY_LOCAL_MACHINE like 'SOFTWARE\\MyCompany'. (REQUIRED)")]
		public string path
		{
			get{return m_path;}
			set{m_path = value;}
		}

		private string m_fieldname;
		[Description("The registry field name in the specified path, for example 'Installed'. (REQUIRED)")]
		public string fieldname
		{
			get{return m_fieldname;}
			set{m_fieldname = value;}
		}

		private string m_fieldvalue;
		[Description("The registry value used to check if the component is installed, this value is converted based on the value type specified. (REQUIRED)")]
		public string fieldvalue
		{
			get{return m_fieldvalue;}
			set{m_fieldvalue = value;}
		}

		private installcheck_registrytype m_fieldtype;
		[Description("Specifies the type of the registry field, can be 'REG_DWORD' (for numeric value) or 'REG_SZ' (for string value) or 'REG_MULTI_SZ' (for multi line strings). (REQUIRED)")]
		public installcheck_registrytype fieldtype
		{
			get{return m_fieldtype;}
			set{m_fieldtype = value;}
		}

		private installcheck_comparison m_comparison;
		[Description("Comparison mode; can be 'match' to check if the exact value is present in the registry or 'version' to compare the registry version with the specified version and return true if the registry version is equal or greater then the version specified. (REQUIRED)")]
		public installcheck_comparison comparison
		{
			get{return m_comparison;}
			set{m_comparison = value;}
		}

		private installcheck_rootkey m_rootkey;
        [Description("Root key, from which to begin the registry search from. (REQUIRED)")]
		public installcheck_rootkey rootkey
		{
			get{return m_rootkey;}
			set{m_rootkey = value;}
		}

        private installcheck_wowoption m_wowoption;
        [Description("Alternate registry view options. WOW64_64 and WOW64_32 maps to KEY_WOW64_64KEY (64 bit registry view for both 32 bit and 64 bit applications) and KEY_WOW64_32KEY (32 bit registry view for both 32 bit and 64 bit applications) respectively. NONE defaults to 32 bit registry view for 32 bit applications and to 64 bit registry view for 64 bit applications.")]
        public installcheck_wowoption wowoption
        {
            get { return m_wowoption; }
            set { m_wowoption = value; }
        }
		
		protected override void OnXmlWriteTagInstalledCheck(XmlWriterEventArgs e)
		{
			base.OnXmlWriteTagInstalledCheck (e);

			e.XmlWriter.WriteAttributeString("path",m_path);
			e.XmlWriter.WriteAttributeString("fieldname",m_fieldname);
			e.XmlWriter.WriteAttributeString("fieldvalue",m_fieldvalue);
			e.XmlWriter.WriteAttributeString("fieldtype",m_fieldtype.ToString());
			e.XmlWriter.WriteAttributeString("comparison",m_comparison.ToString());
            e.XmlWriter.WriteAttributeString("rootkey", m_rootkey.ToString());
            e.XmlWriter.WriteAttributeString("wowoption", m_wowoption.ToString());
		}


		protected override void OnXmlReadTagInstalledCheck(XmlElementEventArgs e)
		{
			base.OnXmlReadTagInstalledCheck (e);

			if (e.XmlElement.Attributes["path"] != null)
				m_path = e.XmlElement.Attributes["path"].InnerText;

			if (e.XmlElement.Attributes["fieldname"] != null)
				m_fieldname = e.XmlElement.Attributes["fieldname"].InnerText;

			if (e.XmlElement.Attributes["fieldvalue"] != null)
				m_fieldvalue = e.XmlElement.Attributes["fieldvalue"].InnerText;

			if (e.XmlElement.Attributes["fieldtype"] != null)
				m_fieldtype = (installcheck_registrytype)Enum.Parse(typeof(installcheck_registrytype),e.XmlElement.Attributes["fieldtype"].InnerText, true);

			if (e.XmlElement.Attributes["comparison"] != null)
				m_comparison = (installcheck_comparison)Enum.Parse(typeof(installcheck_comparison),e.XmlElement.Attributes["comparison"].InnerText, true);
 
 			if (e.XmlElement.Attributes["rootkey"] != null)
				m_rootkey = (installcheck_rootkey)Enum.Parse(typeof(installcheck_rootkey),e.XmlElement.Attributes["rootkey"].InnerText, true);

            if (e.XmlElement.Attributes["wowoption"] != null)
                m_wowoption = (installcheck_wowoption)Enum.Parse(typeof(installcheck_wowoption), e.XmlElement.Attributes["wowoption"].InnerText, true);
		}
	}

	public enum installcheck_registrytype
	{
		REG_DWORD,
		REG_SZ,
		REG_MULTI_SZ
	}
	
	public enum installcheck_rootkey
	{
	  HKEY_CLASSES_ROOT,
	  HKEY_CURRENT_USER,
	  HKEY_LOCAL_MACHINE, // default
	  HKEY_USERS,
	  HKEY_CURRENT_CONFIG
	}
    
    // Alternate registry view options
    public enum installcheck_wowoption
    {
        NONE,
        WOW64_64,
        WOW64_32
    }
}
