using System;
using System.Collections.Generic;
using System.Xml;

namespace InstallerDocLib
{
    public class DocAttributeCollection : SortedList<String, DocAttribute>
    {
        public XmlDocument GetXml()
        {
            XmlDocument doc = new XmlDocument();
            XmlNode tableDefinition = doc.AppendChild(doc.CreateNode(XmlNodeType.Element, "tableDefinition", string.Empty));
            foreach (KeyValuePair<String, DocAttribute> attr in this)
            {
                XmlNode attrDefinedTerm = tableDefinition.AppendChild(doc.CreateNode(XmlNodeType.Element, "definedTerm", string.Empty));
                attrDefinedTerm.InnerText = attr.Value.Name;

                XmlNode attrDefinition = tableDefinition.AppendChild(doc.CreateNode(XmlNodeType.Element, "definition", string.Empty));
                attrDefinition.InnerText = attr.Value.Description;
            }
            return doc;
        }
    }
}
