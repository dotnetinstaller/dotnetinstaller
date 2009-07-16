using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;
using System.Drawing;

namespace InstallerLib
{
    /// <summary>
    /// An xml entity that can be stored.
    /// </summary>
    public interface IXmlClass
    {
        /// <summary>
        /// Component comment
        /// </summary>
        string Comment { get; set; }
        /// <summary>
        /// Name of the xml tag
        /// </summary>
        string XmlTag { get; }
        /// <summary>
        /// Write xml
        /// </summary>
        /// <param name="p_Writer"></param>
        void ToXml(XmlWriter p_Writer);
        /// <summary>
        /// Read xml
        /// </summary>
        /// <param name="p_Element"></param>
        void FromXml(XmlElement p_Element);
        /// <summary>
        /// Get an array of physical files to embed
        /// </summary>
        /// <returns></returns>
        EmbedFileCollection GetFiles(string supportdir);
        /// <summary>
        /// Children
        /// </summary>
        IXmlClassCollection<IXmlClass> Children { get; set; }
    }

    /// <summary>
    /// An xml entity that can be stored.
    /// </summary>
    public abstract class XmlClassImpl : IXmlClass
    {
        public XmlClassImpl()
        {
            m_children = new IXmlClassCollection<IXmlClass>(this);
        }

        private string _comment = string.Empty;

        [System.ComponentModel.Browsable(false)]
        public abstract string XmlTag { get; }

        [System.ComponentModel.Browsable(false)]
        public string Comment
        {
            get { return _comment; }
            set { _comment = value; }
        }

        public void ToXml(XmlWriter p_Writer)
        {
            // write header
            if (!string.IsNullOrEmpty(Comment))
            {
                p_Writer.WriteComment(Comment);
            }
            // write tag
            p_Writer.WriteStartElement(XmlTag);
            OnXmlWriteTag(new XmlWriterEventArgs(p_Writer));
            // write children
            Children.ToXml(p_Writer);
            // close tag
            p_Writer.WriteEndElement();
        }

        public void FromXml(XmlElement p_Element)
        {
            // read comment
            if (p_Element.PreviousSibling != null && p_Element.PreviousSibling.NodeType == XmlNodeType.Comment)
            {
                Comment = p_Element.PreviousSibling.InnerText;
            }

            OnXmlReadTag(new XmlElementEventArgs(p_Element));
            foreach (XmlNode child in p_Element.ChildNodes)
            {
                if (child.NodeType == XmlNodeType.Element)
                {
                    if (!OnXmlChild((XmlElement)child))
                    {
                        // other types of nested nodes
                        switch (child.LocalName)
                        {
                            case "embedfiles":
                            case "components":
                            case "downloads":
                                FromXml((XmlElement)child);
                                break;
                            default:
                                Children.Add(CreateFromXml((XmlElement)child));
                                break;
                        }
                    }
                }
            }
        }

        /// <summary>
        /// Process a child
        /// </summary>
        /// <param name="child">child node</param>
        /// <returns>true if the child has been processed, false otherwise</returns>
        protected virtual bool OnXmlChild(XmlElement child)
        {
            return false;
        }

        private IXmlClass CreateFromXml(XmlElement node)
        {
            switch (node.LocalName)
            {
                case "configuration":
                    return Configuration.CreateFromXml(node);
                case "component":
                    return Component.CreateFromXml(node);
                case "installedcheck":
                    return InstalledCheck.CreateFromXml(node);
                case "installedcheckoperator":
                    return InstalledCheckOperator.CreateFromXml(node);
                case "download":
                    return Download.CreateFromXml(node);
                case "downloaddialog":
                    return DownloadDialog.CreateFromXml(node);
                case "embedfile":
                    return EmbedFile.CreateFromXml(node);
                default:
                    throw new Exception(string.Format("Unsupported node: {0}", node.LocalName));
            }
        }

        private IXmlClassCollection<IXmlClass> m_children = null;
        [System.ComponentModel.Browsable(false)]
        public IXmlClassCollection<IXmlClass> Children
        {
            get { return m_children; }
            set { m_children = value; }
        }

        public virtual EmbedFileCollection GetFiles(string supportdir)
        {
            EmbedFileCollection c_files = new EmbedFileCollection(supportdir);
            foreach (IXmlClass c in Children)
            {
                c_files.AddRange(c.GetFiles(supportdir));
            }
            return c_files;
        }

        protected virtual void OnXmlWriteTag(XmlWriterEventArgs e)
        {
        }

        protected virtual void OnXmlReadTag(XmlElementEventArgs e)
        {
        }

        #region Attribute Values

        public bool ReadAttributeValue(XmlElementEventArgs e, string value, ref string propertyName)
        {
            XmlAttribute xmlattrib = e.XmlElement.Attributes[value];
            if (xmlattrib != null)
            {
                propertyName = xmlattrib.InnerText;
                return true;
            }
            else
            {
                return false;
            }
        }

        public bool ReadAttributeValue<T>(XmlElementEventArgs e, string value, ref T propertyName)            
        {
            XmlAttribute xmlattrib = e.XmlElement.Attributes[value];
            if (xmlattrib != null && !string.IsNullOrEmpty(xmlattrib.InnerText))
            {
                propertyName = (T) Enum.Parse(typeof(T), xmlattrib.InnerText);
                return true;
            }
            else
            {
                return false;
            }
        }

        public bool ReadAttributeValue(XmlElementEventArgs e, string value, ref Rectangle propertyName)
        {
            XmlAttribute xmlattrib = e.XmlElement.Attributes[value];
            if (xmlattrib != null && ! string.IsNullOrEmpty(xmlattrib.InnerText))
            {
                propertyName = XmlRectangle.FromString(xmlattrib.InnerText);
                return true;
            }
            else
            {
                return false;
            }
        }

        public bool ReadAttributeValue(XmlElementEventArgs e, string value, ref Guid propertyName)
        {
            XmlAttribute xmlattrib = e.XmlElement.Attributes[value];
            if (xmlattrib != null && !string.IsNullOrEmpty(xmlattrib.InnerText))
            {
                propertyName = new Guid(xmlattrib.InnerText);
                return true;
            }
            else
            {
                return false;
            }
        }

        public bool ReadAttributeValue(XmlElementEventArgs e, string value, ref bool propertyName)
        {
            XmlAttribute xmlattrib = e.XmlElement.Attributes[value];
            if (xmlattrib != null && !string.IsNullOrEmpty(xmlattrib.InnerText))
            {
                return bool.TryParse(xmlattrib.InnerText, out propertyName);
            }
            else
            {
                return false;
            }
        }

        #endregion
    }

    /// <summary>
    /// A collection of elements of type IXmlClass
    /// </summary>
    public class IXmlClassCollection<T> : System.Collections.Generic.List<T>
        where T : IXmlClass
    {
        IXmlClass _parent = null;

        /// <summary>
        /// Initializes a new empty instance of the IXmlClassCollection class.
        /// </summary>
        public IXmlClassCollection(IXmlClass parent)
        {
            _parent = parent;
        }

        public bool CanAdd(Type value)
        {
            Exception reason = null;
            return CanAdd(value, out reason);
        }

        public bool CanAdd(IXmlClass value)
        {
            return CanAdd(value.GetType());
        }

        public bool CanAdd(Type value, out Exception reason)
        {
            object[] xmlchildrenallowed = _parent.GetType().GetCustomAttributes(typeof(XmlChild), true);
            if (xmlchildrenallowed == null || xmlchildrenallowed.Length == 0)
            {
                reason = new Exception(string.Format("Type {0} is missing XmlChild attribute(s)",
                    _parent.GetType().Name));
                return false;
            }

            foreach (XmlChild childtype in xmlchildrenallowed)
            {
                if (childtype is XmlNoChildren)
                {
                    reason = new Exception(string.Format("{0} cannot be nested under {1}, {1} doesn't allow children",
                        value.Name, _parent.GetType().Name));
                    return false;
                }

                if (value.IsSubclassOf(childtype.Type) || value == childtype.Type)
                {
                    // count how many items of this type are currently in the collection
                    int count = GetCount(value);
                    if (count >= childtype.Max)
                    {
                        reason = new Exception(string.Format("{0} cannot be nested under {1}, maximum numer of {2} reached",
                            value.Name, _parent.GetType().Name, count));
                        return false;
                    }

                    reason = null;
                    return true;
                }
            }

            reason = new Exception(string.Format("{0} cannot be nested under {1}",
                value.Name, _parent.GetType().Name));

            return false;
        }

        /// <summary>
        /// Adds an instance of type IXmlClass to the end of this IXmlClassCollection.
        /// </summary>
        /// <param name="value">
        /// The IXmlClass to be added to the end of this IXmlClassCollection.
        /// </param>
        public new void Add(T value)
        {
            Exception reason = null;
            if (!CanAdd(value.GetType(), out reason))
                throw reason;
            base.Add(value);
        }

        /// <summary>
        /// Type-specific enumeration class, used by IXmlClassCollection.GetEnumerator.
        /// </summary>
        public class TypeEnumerator : System.Collections.IEnumerator
        {
            private System.Collections.IEnumerator wrapped;
            private Type type;

            public TypeEnumerator(Type t, IXmlClassCollection<T> collection)
            {
                this.type = t;
                this.wrapped = collection.GetEnumerator();
            }

            public IXmlClass Current
            {
                get
                {
                    return (IXmlClass)this.wrapped.Current;
                }
            }

            object System.Collections.IEnumerator.Current
            {
                get
                {
                    return (IXmlClass)this.wrapped.Current;
                }
            }

            public bool MoveNext()
            {
                while (this.wrapped.MoveNext())
                {
                    if (this.wrapped.Current.GetType().IsSubclassOf(type) || this.wrapped.Current.GetType() == type)
                    {
                        return true;
                    }
                }

                return false;
            }

            public void Reset()
            {
                this.wrapped.Reset();
            }
        }

        /// <summary>
        /// Returns an enumerator that can iterate through specific type of elements of this IXmlClassCollection.
        /// </summary>
        /// <returns>
        /// An object that implements System.Collections.IEnumerator.
        /// </returns>        
        public virtual IXmlClassCollection<T>.TypeEnumerator GetEnumerator(Type t)
        {
            return new IXmlClassCollection<T>.TypeEnumerator(t, this);
        }

        public int GetCount(Type t)
        {
            int result = 0;
            TypeEnumerator typeEnumerator = GetEnumerator(t);
            while (typeEnumerator.MoveNext())
                result++;
            return result;
        }

        public virtual void ToXml(XmlWriter p_Writer)
        {
            foreach (IXmlClass c in this)
            {
                c.ToXml(p_Writer);
            }
        }
    }

    /// <summary>
    /// An attribute thast identifies child types that can be added to the IXmlClass object
    /// </summary>
    [AttributeUsage(AttributeTargets.Class, Inherited = true, AllowMultiple = true)]
    public class XmlChild : Attribute
    {
        public Type Type = null;
        public int Max = Int16.MaxValue;

        public XmlChild(Type value)
        {
            Type = value;
        }
    }

    [AttributeUsage(AttributeTargets.Class, AllowMultiple = false)]
    public class XmlNoChildren : XmlChild
    {
        public XmlNoChildren()
            : base(null)
        {

        }
    }

    public class XmlWriterEventArgs : EventArgs
    {
        public XmlWriterEventArgs(XmlWriter p_Writer)
        {
            m_Writer = p_Writer;
        }
        private XmlWriter m_Writer;
        public XmlWriter XmlWriter
        {
            get { return m_Writer; }
        }
    }

    public delegate void XmlWriterEventHandler(object sender, XmlWriterEventArgs e);

    public class XmlElementEventArgs : EventArgs
    {
        public XmlElementEventArgs(XmlElement p_XmlElement)
        {
            m_XmlElement = p_XmlElement;
        }
        private XmlElement m_XmlElement;
        public XmlElement XmlElement
        {
            get { return m_XmlElement; }
        }
    }

    public delegate void XmlElementEventHandler(object sender, XmlElementEventArgs e);
}
