using System;

namespace InstallerEditor
{
    /// <summary>
    /// A collection of elements of type FileAttribute
    /// </summary>
    public class FileAttributeCollection : System.Collections.CollectionBase
    {
        /// <summary>
        /// Initializes a new empty instance of the FileAttributeCollection class.
        /// </summary>
        public FileAttributeCollection()
        {
            // empty
        }

        /// <summary>
        /// Initializes a new instance of the FileAttributeCollection class, containing elements
        /// copied from an array.
        /// </summary>
        /// <param name="items">
        /// The array whose elements are to be added to the new FileAttributeCollection.
        /// </param>
        public FileAttributeCollection(FileAttribute[] items)
        {
            this.AddRange(items);
        }

        /// <summary>
        /// Initializes a new instance of the FileAttributeCollection class, containing elements
        /// copied from another instance of FileAttributeCollection
        /// </summary>
        /// <param name="items">
        /// The FileAttributeCollection whose elements are to be added to the new FileAttributeCollection.
        /// </param>
        public FileAttributeCollection(FileAttributeCollection items)
        {
            this.AddRange(items);
        }

        /// <summary>
        /// Adds the elements of an array to the end of this FileAttributeCollection.
        /// </summary>
        /// <param name="items">
        /// The array whose elements are to be added to the end of this FileAttributeCollection.
        /// </param>
        public virtual void AddRange(FileAttribute[] items)
        {
            foreach (FileAttribute item in items)
            {
                this.List.Add(item);
            }
        }

        /// <summary>
        /// Adds the elements of another FileAttributeCollection to the end of this FileAttributeCollection.
        /// </summary>
        /// <param name="items">
        /// The FileAttributeCollection whose elements are to be added to the end of this FileAttributeCollection.
        /// </param>
        public virtual void AddRange(FileAttributeCollection items)
        {
            foreach (FileAttribute item in items)
            {
                this.List.Add(item);
            }
        }

        /// <summary>
        /// Adds an instance of type FileAttribute to the end of this FileAttributeCollection.
        /// </summary>
        /// <param name="value">
        /// The FileAttribute to be added to the end of this FileAttributeCollection.
        /// </param>
        public virtual void Add(FileAttribute value)
        {
            this.List.Add(value);
        }

        /// <summary>
        /// Determines whether a specfic FileAttribute value is in this FileAttributeCollection.
        /// </summary>
        /// <param name="value">
        /// The FileAttribute value to locate in this FileAttributeCollection.
        /// </param>
        /// <returns>
        /// true if value is found in this FileAttributeCollection;
        /// false otherwise.
        /// </returns>
        public virtual bool Contains(FileAttribute value)
        {
            return this.List.Contains(value);
        }

        /// <summary>
        /// Return the zero-based index of the first occurrence of a specific value
        /// in this FileAttributeCollection
        /// </summary>
        /// <param name="value">
        /// The FileAttribute value to locate in the FileAttributeCollection.
        /// </param>
        /// <returns>
        /// The zero-based index of the first occurrence of the _ELEMENT value if found;
        /// -1 otherwise.
        /// </returns>
        public virtual int IndexOf(FileAttribute value)
        {
            return this.List.IndexOf(value);
        }

        /// <summary>
        /// Inserts an element into the FileAttributeCollection at the specified index
        /// </summary>
        /// <param name="index">
        /// The index at which the FileAttribute is to be inserted.
        /// </param>
        /// <param name="value">
        /// The FileAttribute to insert.
        /// </param>
        public virtual void Insert(int index, FileAttribute value)
        {
            this.List.Insert(index, value);
        }

        /// <summary>
        /// Gets or sets the FileAttribute at the given index in this FileAttributeCollection.
        /// </summary>
        public virtual FileAttribute this[int index]
        {
            get
            {
                return (FileAttribute)this.List[index];
            }
            set
            {
                this.List[index] = value;
            }
        }

        /// <summary>
        /// Removes the first occurrence of a specific FileAttribute from this FileAttributeCollection.
        /// </summary>
        /// <param name="value">
        /// The FileAttribute value to remove from this FileAttributeCollection.
        /// </param>
        public virtual void Remove(FileAttribute value)
        {
            this.List.Remove(value);
        }

        /// <summary>
        /// Type-specific enumeration class, used by FileAttributeCollection.GetEnumerator.
        /// </summary>
        public class Enumerator : System.Collections.IEnumerator
        {
            private System.Collections.IEnumerator wrapped;

            public Enumerator(FileAttributeCollection collection)
            {
                this.wrapped = ((System.Collections.CollectionBase)collection).GetEnumerator();
            }

            public FileAttribute Current
            {
                get
                {
                    return (FileAttribute)(this.wrapped.Current);
                }
            }

            object System.Collections.IEnumerator.Current
            {
                get
                {
                    return (FileAttribute)(this.wrapped.Current);
                }
            }

            public bool MoveNext()
            {
                return this.wrapped.MoveNext();
            }

            public void Reset()
            {
                this.wrapped.Reset();
            }
        }

        /// <summary>
        /// Returns an enumerator that can iterate through the elements of this FileAttributeCollection.
        /// </summary>
        /// <returns>
        /// An object that implements System.Collections.IEnumerator.
        /// </returns>        
        public new virtual FileAttributeCollection.Enumerator GetEnumerator()
        {
            return new FileAttributeCollection.Enumerator(this);
        }
    }

}
