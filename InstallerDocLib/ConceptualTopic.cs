using System;
using System.Text;
using System.ComponentModel;
using System.Xml;
using System.Reflection;
using InstallerLib;

namespace InstallerDocLib
{
    public class ConceptualTopic
    {
        private Type m_type;
        private DocAttributeCollection m_attributes = null;

        public ConceptualTopic(Type type)
        {
            m_type = type;
        }

        public DocAttributeCollection Attributes
        {
            get
            {
                if (m_attributes == null)
                {
                    DocAttributeCollection attributes = new DocAttributeCollection();
                    PropertyInfo[] properties = m_type.GetProperties();

                    foreach (PropertyInfo pi in properties)
                    {
                        DocAttribute attribute = new DocAttribute(pi);
                        if (attribute.IsDocumentable)
                        {
                            attributes.Add(attribute.Name, attribute);
                        }
                    }

                    m_attributes = attributes;
                }

                return m_attributes;
            }
        }

        public string Description
        {
            get
            {
                object[] descrs = m_type.GetCustomAttributes(typeof(DescriptionAttribute), false);
                string description = (descrs != null && descrs.Length == 1)
                    ? (descrs[0] as DescriptionAttribute).Description
                    : string.Empty;
                return description;
            }
        }

        public XmlDocument GetXml()
        {
            XmlDocument doc = new XmlDocument();
            StringBuilder sb = new StringBuilder();
            sb.Append(
                "<?xml version='1.0' encoding='utf-8' ?>" +
                 "<topic id='" + m_type.FullName.ToLower() + "' revisionNumber='1'>" +
                  "<developerConceptualDocument xmlns='http://ddue.schemas.microsoft.com/authoring/2003/5' xmlns:xlink='http://www.w3.org/1999/xlink'>" +
                   "<introduction><para>" + Description + "</para></introduction>");

            DocumentationSection reference = new DocumentationSection("Reference", "<para>" + Attributes.GetXml().OuterXml + "</para>");
            sb.Append(reference.GetXml());

            object[] sections = m_type.GetCustomAttributes(typeof(DocumentationSection), true);
            if (sections != null)
            {
                foreach (DocumentationSection section in sections)
                {
                    sb.Append(section.GetXml());
                }
            }

            sb.Append(
                   "<relatedTopics>" +
                    "<codeEntityReference qualifyHint=\"true\">T:" + m_type.FullName + "</codeEntityReference>" +
                   "</relatedTopics>" +
                  "</developerConceptualDocument>" +
                 "</topic>");

            doc.LoadXml(sb.ToString());
            return doc;
        }
    }
}
