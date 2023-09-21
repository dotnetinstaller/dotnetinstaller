using System;
using System.Collections.Generic;
using System.Xml;
using System.Drawing;
using System.ComponentModel;

namespace InstallerLib
{
    /// <summary>
    /// An xml entity that can be stored.
    /// </summary>
    public abstract class XmlClass : ICustomTypeDescriptor
    {
        public XmlClass()
        {
            m_children = new XmlClassCollection(this);
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

        internal void Clear()
        {
            _comment = string.Empty;
            m_children.Clear();
        }

        internal void ToXml(XmlWriter p_Writer, XmlFilter filter)
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
            Children.ToXml(p_Writer, filter);
            // close tag
            p_Writer.WriteEndElement();
        }

        internal void FromXml(XmlElement p_Element)
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

        private XmlClass CreateFromXml(XmlElement node)
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
                case "embedfolder":
                    return EmbedFolder.CreateFromXml(node);
                case "control":
                    return Control.CreateFromXml(node);
                default:
                    throw new Exception(string.Format("Unsupported node: {0}", node.LocalName));
            }
        }

        private XmlClassCollection m_children = null;
        [System.ComponentModel.Browsable(false)]
        public XmlClassCollection Children
        {
            get { return m_children; }
            set { m_children = value; }
        }

        public virtual Dictionary<String, EmbedFileCollection> GetFiles(string parentid, string supportdir)
        {
            Dictionary<String, EmbedFileCollection> c_files = new Dictionary<String, EmbedFileCollection>();
            foreach (XmlClass c in Children)
            {
                using (Dictionary<String, EmbedFileCollection>.Enumerator enumerator = c.GetFiles(parentid, supportdir).GetEnumerator())
                {
                    while (enumerator.MoveNext())
                    {
                        EmbedFileCollection coll = null;
                        if (!c_files.TryGetValue(enumerator.Current.Key, out coll))
                        {
                            coll = new EmbedFileCollection(supportdir);
                            c_files.Add(enumerator.Current.Key, coll);
                        }

                        coll.AddRange(enumerator.Current.Value);
                    }
                }
            }
            return c_files;
        }

        public virtual ResourceFileCollection GetResources(string supportdir)
        {
            ResourceFileCollection c_files = new ResourceFileCollection(supportdir);
            foreach (XmlClass c in Children)
            {
                c_files.AddRange(c.GetResources(supportdir));
            }
            return c_files;
        }

        protected virtual void OnXmlWriteTag(XmlWriterEventArgs e)
        {
        }

        protected virtual void OnXmlReadTag(XmlElementEventArgs e)
        {
        }

        /// <summary>
        /// Total count of nodes of a given type.
        /// </summary>
        /// <typeparam name="T">Node type.</typeparam>
        /// <returns>Total count.</returns>
        public int GetCount<T>()
            where T : XmlClass
        {
            int total = 0;

            foreach (XmlClass xmlclazz in Children)
            {
                if (xmlclazz is T)
                    total++;

                total += xmlclazz.GetCount<T>();
            }

            return total;
        }

        #region Attribute Values

        protected bool ReadAttributeValue(XmlElementEventArgs e, string value, ref string propertyName)
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

        protected bool ReadAttributeValue<T>(XmlElementEventArgs e, string value, ref T propertyName)
        {
            XmlAttribute xmlattrib = e.XmlElement.Attributes[value];
            if (xmlattrib != null && !string.IsNullOrEmpty(xmlattrib.InnerText))
            {
                propertyName = (T)Enum.Parse(typeof(T), xmlattrib.InnerText);
                return true;
            }
            else
            {
                return false;
            }
        }

        protected bool ReadAttributeValue(XmlElementEventArgs e, string value, ref Rectangle propertyName)
        {
            XmlAttribute xmlattrib = e.XmlElement.Attributes[value];
            if (xmlattrib != null && !string.IsNullOrEmpty(xmlattrib.InnerText))
            {
                propertyName = XmlRectangle.FromString(xmlattrib.InnerText);
                return true;
            }
            else
            {
                return false;
            }
        }

        protected bool ReadAttributeValue(XmlElementEventArgs e, string value, ref Guid propertyName)
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

        protected bool ReadAttributeValue(XmlElementEventArgs e, string value, ref bool propertyName)
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

        protected bool ReadAttributeValue(XmlElementEventArgs e, string value, ref int propertyName)
        {
            XmlAttribute xmlattrib = e.XmlElement.Attributes[value];
            if (xmlattrib != null && !string.IsNullOrEmpty(xmlattrib.InnerText))
            {
                return int.TryParse(xmlattrib.InnerText, out propertyName);
            }
            else
            {
                return false;
            }
        }

        #endregion

        #region ICustomTypeDescriptor Members

        public AttributeCollection GetAttributes()
        {
            return TypeDescriptor.GetAttributes(this, true);
        }

        public string GetClassName()
        {
            return TypeDescriptor.GetClassName(this, true);
        }

        public string GetComponentName()
        {
            return TypeDescriptor.GetComponentName(this, true);
        }

        public TypeConverter GetConverter()
        {
            return TypeDescriptor.GetConverter(this, true);
        }

        public EventDescriptor GetDefaultEvent()
        {
            return TypeDescriptor.GetDefaultEvent(this, true);
        }

        public PropertyDescriptor GetDefaultProperty()
        {
            return TypeDescriptor.GetDefaultProperty(this, true);
        }

        public object GetEditor(Type editorBaseType)
        {
            return TypeDescriptor.GetEditor(this, editorBaseType, true);
        }

        public EventDescriptorCollection GetEvents(Attribute[] attributes)
        {
            return TypeDescriptor.GetEvents(this, attributes, true);
        }

        public EventDescriptorCollection GetEvents()
        {
            return TypeDescriptor.GetEvents(this, true);
        }

        public PropertyDescriptorCollection GetProperties(Attribute[] attributes)
        {
            PropertyDescriptorCollection coll = new PropertyDescriptorCollection(null);
            PropertyDescriptorCollection baseProperties = TypeDescriptor.GetProperties(this, attributes, true);
            foreach (PropertyDescriptor pd in baseProperties)
            {
                coll.Add(pd.Attributes.Contains(Required.Yes)
                    ? new RequiredPropertyDescriptor(pd)
                    : pd);
            }

            return coll;
        }

        public PropertyDescriptorCollection GetProperties()
        {
            PropertyDescriptorCollection coll = new PropertyDescriptorCollection(null);
            PropertyDescriptorCollection baseProperties = TypeDescriptor.GetProperties(this, true);
            foreach (PropertyDescriptor pd in baseProperties)
            {
                coll.Add(pd.Attributes.Contains(Required.Yes)
                    ? new RequiredPropertyDescriptor(pd)
                    : pd);
            }

            return coll;
        }

        public object GetPropertyOwner(PropertyDescriptor pd)
        {
            return this;
        }

        #endregion
    }

    /// <summary>
    /// A collection of elements of type XmlClass
    /// </summary>
    public class XmlClassCollection : List<XmlClass>
    {
        XmlClass _parent = null;

        /// <summary>
        /// Initializes a new empty instance of the XmlClassCollection class.
        /// </summary>
        public XmlClassCollection(XmlClass parent)
        {
            _parent = parent;
        }

        public bool CanAdd(Type value)
        {
            Exception reason = null;
            return CanAdd(value, out reason);
        }

        public bool CanAdd(XmlClass value)
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
        /// Adds an instance of type XmlClass to the end of this XmlClassCollection.
        /// </summary>
        /// <param name="value">
        /// The XmlClass to be added to the end of this XmlClassCollection.
        /// </param>
        public new void Add(XmlClass value)
        {
            Exception reason = null;
            if (!CanAdd(value.GetType(), out reason))
                throw reason;
            base.Add(value);
        }

        /// <summary>
        /// Type-specific enumeration class, used by XmlClassCollection.GetEnumerator.
        /// </summary>
        public class TypeEnumerator : System.Collections.IEnumerator
        {
            private System.Collections.IEnumerator wrapped;
            private Type type;

            public TypeEnumerator(Type t, XmlClassCollection collection)
            {
                this.type = t;
                this.wrapped = collection.GetEnumerator();
            }

            internal XmlClass Current
            {
                get
                {
                    return (XmlClass)this.wrapped.Current;
                }
            }

            object System.Collections.IEnumerator.Current
            {
                get
                {
                    return (XmlClass)this.wrapped.Current;
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
        /// Returns an enumerator that can iterate through specific type of elements of this XmlClassCollection.
        /// </summary>
        /// <returns>
        /// An object that implements System.Collections.IEnumerator.
        /// </returns>        
        public virtual XmlClassCollection.TypeEnumerator GetEnumerator(Type t)
        {
            return new XmlClassCollection.TypeEnumerator(t, this);
        }

        public int GetCount(Type t)
        {
            int result = 0;
            TypeEnumerator typeEnumerator = GetEnumerator(t);
            while (typeEnumerator.MoveNext())
                result++;
            return result;
        }

        public virtual void ToXml(XmlWriter p_Writer, XmlFilter filter)
        {
            foreach (XmlClass c in this)
            {
                if (filter != null && !filter.IsSupported(c))
                    continue;

                c.ToXml(p_Writer, filter);
            }
        }
    }

    /// <summary>
    /// An attribute thast identifies child types that can be added to the XmlClass object
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
