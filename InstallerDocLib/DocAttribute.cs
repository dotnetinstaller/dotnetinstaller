using System;
using System.Reflection;
using System.ComponentModel;
using InstallerLib;

namespace InstallerDocLib
{
    public class DocAttribute
    {
        private PropertyInfo m_pi;
        private DescriptionAttribute m_description;
        private bool m_required = false;
        private bool m_documentable = false;

        public DocAttribute(PropertyInfo pi)
        {
            m_pi = pi;

            Read();
        }

        private void Read()
        {
            if (!m_pi.CanRead)
                return;

            if (!m_pi.CanWrite)
                return;

            object[] attributes = m_pi.GetCustomAttributes(true);
            if (attributes == null)
                return;

            m_documentable = true;
            foreach (Attribute attribute in attributes)
            {
                if (attribute is DescriptionAttribute)
                {
                    m_description = attribute as DescriptionAttribute;
                }
                else if (attribute is BrowsableAttribute)
                {
                    m_documentable = (attribute as BrowsableAttribute).Browsable;
                }
                else if (attribute is Required)
                {
                    m_required = (attribute as Required).IsRequired;
                }
            }
        }

        public bool IsDocumentable
        {
            get
            {
                return m_documentable;
            }
        }

        public string Description
        {
            get
            {
                return m_description == null ? string.Empty : m_description.Description;
            }
        }

        public string Name
        {
            get
            {
                string name = m_pi.Name.ToLower();
                if (IsRequired) name += " *";
                return name;
            }
        }

        public bool IsRequired
        {
            get
            {
                return m_required;
            }
        }
    }
}
