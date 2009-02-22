using System;

namespace InstallerLib
{
    /// <summary>
    /// A collection of elements of type InstalledCheckOperator
    /// </summary>
    public class InstalledCheckOperatorCollection : System.Collections.CollectionBase
    {
        /// <summary>
        /// Initializes a new empty instance of the InstalledCheckOperatorCollection class.
        /// </summary>
        public InstalledCheckOperatorCollection()
        {
            // empty
        }

        /// <summary>
        /// Initializes a new instance of the InstalledCheckOperatorCollection class, containing elements
        /// copied from an array.
        /// </summary>
        /// <param name="items">
        /// The array whose elements are to be added to the new InstalledCheckOperatorCollection.
        /// </param>
        public InstalledCheckOperatorCollection(InstalledCheckOperator[] items)
        {
            this.AddRange(items);
        }

        /// <summary>
        /// Initializes a new instance of the InstalledCheckOperatorCollection class, containing elements
        /// copied from another instance of InstalledCheckOperatorCollection
        /// </summary>
        /// <param name="items">
        /// The InstalledCheckOperatorCollection whose elements are to be added to the new InstalledCheckOperatorCollection.
        /// </param>
        public InstalledCheckOperatorCollection(InstalledCheckOperatorCollection items)
        {
            this.AddRange(items);
        }

        /// <summary>
        /// Adds the elements of an array to the end of this InstalledCheckOperatorCollection.
        /// </summary>
        /// <param name="items">
        /// The array whose elements are to be added to the end of this InstalledCheckOperatorCollection.
        /// </param>
        public virtual void AddRange(InstalledCheckOperator[] items)
        {
            foreach (InstalledCheckOperator item in items)
            {
                this.List.Add(item);
            }
        }

        /// <summary>
        /// Adds the elements of another InstalledCheckOperatorCollection to the end of this InstalledCheckOperatorCollection.
        /// </summary>
        /// <param name="items">
        /// The InstalledCheckOperatorCollection whose elements are to be added to the end of this InstalledCheckOperatorCollection.
        /// </param>
        public virtual void AddRange(InstalledCheckOperatorCollection items)
        {
            foreach (InstalledCheckOperator item in items)
            {
                this.List.Add(item);
            }
        }

        /// <summary>
        /// Adds an instance of type InstalledCheckOperator to the end of this InstalledCheckOperatorCollection.
        /// </summary>
        /// <param name="value">
        /// The InstalledCheckOperator to be added to the end of this InstalledCheckOperatorCollection.
        /// </param>
        public virtual void Add(InstalledCheckOperator value)
        {
            this.List.Add(value);
        }

        /// <summary>
        /// Determines whether a specfic InstalledCheckOperator value is in this InstalledCheckOperatorCollection.
        /// </summary>
        /// <param name="value">
        /// The InstalledCheckOperator value to locate in this InstalledCheckOperatorCollection.
        /// </param>
        /// <returns>
        /// true if value is found in this InstalledCheckOperatorCollection;
        /// false otherwise.
        /// </returns>
        public virtual bool Contains(InstalledCheckOperator value)
        {
            return this.List.Contains(value);
        }

        /// <summary>
        /// Return the zero-based index of the first occurrence of a specific value
        /// in this InstalledCheckOperatorCollection
        /// </summary>
        /// <param name="value">
        /// The InstalledCheckOperator value to locate in the InstalledCheckOperatorCollection.
        /// </param>
        /// <returns>
        /// The zero-based index of the first occurrence of the _ELEMENT value if found;
        /// -1 otherwise.
        /// </returns>
        public virtual int IndexOf(InstalledCheckOperator value)
        {
            return this.List.IndexOf(value);
        }

        /// <summary>
        /// Inserts an element into the InstalledCheckOperatorCollection at the specified index
        /// </summary>
        /// <param name="index">
        /// The index at which the InstalledCheckOperator is to be inserted.
        /// </param>
        /// <param name="value">
        /// The InstalledCheckOperator to insert.
        /// </param>
        public virtual void Insert(int index, InstalledCheckOperator value)
        {
            this.List.Insert(index, value);
        }

        /// <summary>
        /// Gets or sets the InstalledCheckOperator at the given index in this InstalledCheckOperatorCollection.
        /// </summary>
        public virtual InstalledCheckOperator this[int index]
        {
            get
            {
                return (InstalledCheckOperator)this.List[index];
            }
            set
            {
                this.List[index] = value;
            }
        }

        /// <summary>
        /// Removes the first occurrence of a specific InstalledCheckOperator from this InstalledCheckOperatorCollection.
        /// </summary>
        /// <param name="value">
        /// The InstalledCheckOperator value to remove from this InstalledCheckOperatorCollection.
        /// </param>
        public virtual void Remove(InstalledCheckOperator value)
        {
            this.List.Remove(value);
        }

        /// <summary>
        /// Type-specific enumeration class, used by InstalledCheckOperatorCollection.GetEnumerator.
        /// </summary>
        public class Enumerator : System.Collections.IEnumerator
        {
            private System.Collections.IEnumerator wrapped;

            public Enumerator(InstalledCheckOperatorCollection collection)
            {
                this.wrapped = ((System.Collections.CollectionBase)collection).GetEnumerator();
            }

            public InstalledCheckOperator Current
            {
                get
                {
                    return (InstalledCheckOperator)(this.wrapped.Current);
                }
            }

            object System.Collections.IEnumerator.Current
            {
                get
                {
                    return (InstalledCheckOperator)(this.wrapped.Current);
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
        /// Returns an enumerator that can iterate through the elements of this InstalledCheckOperatorCollection.
        /// </summary>
        /// <returns>
        /// An object that implements System.Collections.IEnumerator.
        /// </returns>        
        public new virtual InstalledCheckOperatorCollection.Enumerator GetEnumerator()
        {
            return new InstalledCheckOperatorCollection.Enumerator(this);
        }
    }

}
