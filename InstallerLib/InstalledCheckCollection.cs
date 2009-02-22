using System;

namespace InstallerLib
{
	/// <summary>
	/// A collection of elements of type InstalledCheck
	/// </summary>
	public class InstalledCheckCollection: System.Collections.CollectionBase
	{
		/// <summary>
		/// Initializes a new empty instance of the InstalledCheckCollection class.
		/// </summary>
		public InstalledCheckCollection()
		{
			// empty
		}

		/// <summary>
		/// Initializes a new instance of the InstalledCheckCollection class, containing elements
		/// copied from an array.
		/// </summary>
		/// <param name="items">
		/// The array whose elements are to be added to the new InstalledCheckCollection.
		/// </param>
		public InstalledCheckCollection(InstalledCheck[] items)
		{
			this.AddRange(items);
		}

		/// <summary>
		/// Initializes a new instance of the InstalledCheckCollection class, containing elements
		/// copied from another instance of InstalledCheckCollection
		/// </summary>
		/// <param name="items">
		/// The InstalledCheckCollection whose elements are to be added to the new InstalledCheckCollection.
		/// </param>
		public InstalledCheckCollection(InstalledCheckCollection items)
		{
			this.AddRange(items);
		}

		/// <summary>
		/// Adds the elements of an array to the end of this InstalledCheckCollection.
		/// </summary>
		/// <param name="items">
		/// The array whose elements are to be added to the end of this InstalledCheckCollection.
		/// </param>
		public virtual void AddRange(InstalledCheck[] items)
		{
			foreach (InstalledCheck item in items)
			{
				this.List.Add(item);
			}
		}

		/// <summary>
		/// Adds the elements of another InstalledCheckCollection to the end of this InstalledCheckCollection.
		/// </summary>
		/// <param name="items">
		/// The InstalledCheckCollection whose elements are to be added to the end of this InstalledCheckCollection.
		/// </param>
		public virtual void AddRange(InstalledCheckCollection items)
		{
			foreach (InstalledCheck item in items)
			{
				this.List.Add(item);
			}
		}

		/// <summary>
		/// Adds an instance of type InstalledCheck to the end of this InstalledCheckCollection.
		/// </summary>
		/// <param name="value">
		/// The InstalledCheck to be added to the end of this InstalledCheckCollection.
		/// </param>
		public virtual void Add(InstalledCheck value)
		{
			this.List.Add(value);
		}

		/// <summary>
		/// Determines whether a specfic InstalledCheck value is in this InstalledCheckCollection.
		/// </summary>
		/// <param name="value">
		/// The InstalledCheck value to locate in this InstalledCheckCollection.
		/// </param>
		/// <returns>
		/// true if value is found in this InstalledCheckCollection;
		/// false otherwise.
		/// </returns>
		public virtual bool Contains(InstalledCheck value)
		{
			return this.List.Contains(value);
		}

		/// <summary>
		/// Return the zero-based index of the first occurrence of a specific value
		/// in this InstalledCheckCollection
		/// </summary>
		/// <param name="value">
		/// The InstalledCheck value to locate in the InstalledCheckCollection.
		/// </param>
		/// <returns>
		/// The zero-based index of the first occurrence of the _ELEMENT value if found;
		/// -1 otherwise.
		/// </returns>
		public virtual int IndexOf(InstalledCheck value)
		{
			return this.List.IndexOf(value);
		}

		/// <summary>
		/// Inserts an element into the InstalledCheckCollection at the specified index
		/// </summary>
		/// <param name="index">
		/// The index at which the InstalledCheck is to be inserted.
		/// </param>
		/// <param name="value">
		/// The InstalledCheck to insert.
		/// </param>
		public virtual void Insert(int index, InstalledCheck value)
		{
			this.List.Insert(index, value);
		}

		/// <summary>
		/// Gets or sets the InstalledCheck at the given index in this InstalledCheckCollection.
		/// </summary>
		public virtual InstalledCheck this[int index]
		{
			get
			{
				return (InstalledCheck) this.List[index];
			}
			set
			{
				this.List[index] = value;
			}
		}

		/// <summary>
		/// Removes the first occurrence of a specific InstalledCheck from this InstalledCheckCollection.
		/// </summary>
		/// <param name="value">
		/// The InstalledCheck value to remove from this InstalledCheckCollection.
		/// </param>
		public virtual void Remove(InstalledCheck value)
		{
			this.List.Remove(value);
		}

		/// <summary>
		/// Type-specific enumeration class, used by InstalledCheckCollection.GetEnumerator.
		/// </summary>
		public class Enumerator: System.Collections.IEnumerator
		{
			private System.Collections.IEnumerator wrapped;

			public Enumerator(InstalledCheckCollection collection)
			{
				this.wrapped = ((System.Collections.CollectionBase)collection).GetEnumerator();
			}

			public InstalledCheck Current
			{
				get
				{
					return (InstalledCheck) (this.wrapped.Current);
				}
			}

			object System.Collections.IEnumerator.Current
			{
				get
				{
					return (InstalledCheck) (this.wrapped.Current);
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
		/// Returns an enumerator that can iterate through the elements of this InstalledCheckCollection.
		/// </summary>
		/// <returns>
		/// An object that implements System.Collections.IEnumerator.
		/// </returns>        
		public new virtual InstalledCheckCollection.Enumerator GetEnumerator()
		{
			return new InstalledCheckCollection.Enumerator(this);
		}
	}

}
