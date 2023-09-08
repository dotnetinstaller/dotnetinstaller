using System.ComponentModel;

namespace InstallerLib
{
    /// <summary>
    /// Install check comparison types
    /// </summary>
    public enum installcheckregistry_comparison
    {
        match,
        version,
        version_eq,
        version_lt,
        version_le,
        version_gt,
        version_ge,
        exists,
        key_exists,
        value_exists,
        contains
    }

    /// <summary>
    /// InstalledCheck of type "check_registry_value".
    /// </summary>
    public class InstalledCheckRegistry : InstalledCheck
    {
        public InstalledCheckRegistry()
            : base("check_registry_value")
        {
            m_path = "SOFTWARE\\MyCompany\\MyApplication\\1.0.1.0";
            m_comparison = installcheckregistry_comparison.match;
            m_fieldname = "Installed";
            m_fieldtype = installcheck_registrytype.REG_DWORD;
            m_fieldvalue = "1";
            m_rootkey = installcheck_rootkey.HKEY_LOCAL_MACHINE;
            m_wowoption = installcheck_wowoption.NONE;
        }

        private string m_path;
        [Description("Registry path to search for the value specified under 'rootkey'.")]
        public string path
        {
            get { return m_path; }
            set { m_path = value; }
        }

        private string m_fieldname;
        [Description("Registry field name in the specified path under 'rootkey\\path'. Specify a blank field name for the default field.")]
        public string fieldname
        {
            get { return m_fieldname; }
            set { m_fieldname = value; }
        }

        private string m_fieldvalue;
        [Description("Registry value used to check if the component is installed. This value is converted based on the value type specified.")]
        public string fieldvalue
        {
            get { return m_fieldvalue; }
            set { m_fieldvalue = value; }
        }

        private bool m_defaultvalue = false;
        [Description("Default check value for comparison operators other than 'exists' when the registry key doesn't exist.")]
        [Required]
        public bool defaultvalue
        {
            get { return m_defaultvalue; }
            set { m_defaultvalue = value; }
        }

        private installcheck_registrytype m_fieldtype;
        [Description("Type of the registry field, can be 'REG_DWORD' (for numeric value), 'REG_SZ' (for string value) or 'REG_MULTI_SZ' (for multi line strings).")]
        [Required]
        public installcheck_registrytype fieldtype
        {
            get { return m_fieldtype; }
            set { m_fieldtype = value; }
        }

        private installcheckregistry_comparison m_comparison;
        [Description("Comparison mode; one of 'match', 'version', 'exists', etc.")]
        [Required]
        public installcheckregistry_comparison comparison
        {
            get { return m_comparison; }
            set { m_comparison = value; }
        }

        private installcheck_rootkey m_rootkey;
        [Description("Root key, from which to begin the registry search from.")]
        [Required]
        public installcheck_rootkey rootkey
        {
            get { return m_rootkey; }
            set { m_rootkey = value; }
        }

        private installcheck_wowoption m_wowoption;
        [Description("Alternate registry view options. WOW64_64 and WOW64_32 maps to KEY_WOW64_64KEY (64 bit registry view for both 32 bit and 64 bit applications) and KEY_WOW64_32KEY (32 bit registry view for both 32 bit and 64 bit applications) respectively. NONE defaults to 32 bit registry view for 32 bit applications and to 64 bit registry view for 64 bit applications.")]
        [Required]
        public installcheck_wowoption wowoption
        {
            get { return m_wowoption; }
            set { m_wowoption = value; }
        }

        protected override void OnXmlWriteTag(XmlWriterEventArgs e)
        {
            e.XmlWriter.WriteAttributeString("path", m_path);
            e.XmlWriter.WriteAttributeString("fieldname", m_fieldname);
            e.XmlWriter.WriteAttributeString("fieldvalue", m_fieldvalue);
            e.XmlWriter.WriteAttributeString("defaultvalue", m_defaultvalue.ToString());
            e.XmlWriter.WriteAttributeString("fieldtype", m_fieldtype.ToString());
            e.XmlWriter.WriteAttributeString("comparison", m_comparison.ToString());
            e.XmlWriter.WriteAttributeString("rootkey", m_rootkey.ToString());
            e.XmlWriter.WriteAttributeString("wowoption", m_wowoption.ToString());
            base.OnXmlWriteTag(e);
        }

        protected override void OnXmlReadTag(XmlElementEventArgs e)
        {
            ReadAttributeValue(e, "path", ref m_path);
            ReadAttributeValue(e, "fieldname", ref m_fieldname);
            ReadAttributeValue(e, "fieldvalue", ref m_fieldvalue);
            ReadAttributeValue(e, "defaultvalue", ref m_defaultvalue);
            ReadAttributeValue(e, "fieldtype", ref m_fieldtype);
            ReadAttributeValue(e, "comparison", ref m_comparison);
            ReadAttributeValue(e, "rootkey", ref m_rootkey);
            ReadAttributeValue(e, "wowoption", ref m_wowoption);
            base.OnXmlReadTag(e);
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
