using System;
using System.Xml;
using System.Collections.Generic;

namespace InstallerLib
{
    /// <summary>
    /// A collection of elements of type FileAttribute.
    /// </summary>
    public class FileAttributeCollection : List<FileAttribute>
    {
        public void ToXml(XmlWriter p_Writer)
        {
            if (Count == 0)
                return;

            p_Writer.WriteStartElement("fileattributes");
            foreach (FileAttribute a in this)
            {
                a.ToXml(p_Writer, null);
            }
            p_Writer.WriteEndElement();
        }

        public void FromXml(XmlElement root)
        {
            foreach (XmlNode child in root.ChildNodes)
            {
                switch (child.LocalName)
                {
                    case "fileattribute":
                        FileAttribute l_FileAttribute = new FileAttribute();
                        l_FileAttribute.FromXml((XmlElement)child);
                        Add(l_FileAttribute);
                        break;
                    default:
                        throw new Exception(string.Format("Unexpected node: {0}", child.LocalName));
                }
            }
        }
    }
}
