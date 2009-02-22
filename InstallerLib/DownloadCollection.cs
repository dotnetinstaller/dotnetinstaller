using System;

namespace InstallerLib
{
	/// <summary>
	/// A collection of elements of type Download
	/// </summary>
	public class DownloadCollection: System.Collections.CollectionBase
	{
		/// <summary>
		/// Initializes a new empty instance of the DownloadCollection class.
		/// </summary>
		public DownloadCollection()
		{
			// empty
		}

		/// <summary>
		/// Initializes a new instance of the DownloadCollection class, containing elements
		/// copied from an array.
		/// </summary>
		/// <param name="items">
		/// The array whose elements are to be added to the new DownloadCollection.
		/// </param>
		public DownloadCollection(Download[] items)
		{
			this.AddRange(items);
		}

		/// <summary>
		/// Initializes a new instance of the DownloadCollection class, containing elements
		/// copied from another instance of DownloadCollection
		/// </summary>
		/// <param name="items">
		/// The DownloadCollection whose elements are to be added to the new DownloadCollection.
		/// </param>
		public DownloadCollection(DownloadCollection items)
		{
			this.AddRange(items);
		}

		/// <summary>
		/// Adds the elements of an array to the end of this DownloadCollection.
		/// </summary>
		/// <param name="items">
		/// The array whose elements are to be added to the end of this DownloadCollection.
		/// </param>
		public virtual void AddRange(Download[] items)
		{
			foreach (Download item in items)
			{
				this.List.Add(item);
			}
		}

		/// <summary>
		/// Adds the elements of another DownloadCollection to the end of this DownloadCollection.
		/// </summary>
		/// <param name="items">
		/// The DownloadCollection whose elements are to be added to the end of this DownloadCollection.
		/// </param>
		public virtual void AddRange(DownloadCollection items)
		{
			foreach (Download item in items)
			{
				this.List.Add(item);
			}
		}

		/// <summary>
		/// Adds an instance of type Download to the end of this DownloadCollection.
		/// </summary>
		/// <param name="value">
		/// The Download to be added to the end of this DownloadCollection.
		/// </param>
		public virtual void Add(Download value)
		{
			this.List.Add(value);
		}

		/// <summary>
		/// Determines whether a specfic Download value is in this DownloadCollection.
		/// </summary>
		/// <param name="value">
		/// The Download value to locate in this DownloadCollection.
		/// </param>
		/// <returns>
		/// true if value is found in this DownloadCollection;
		/// false otherwise.
		/// </returns>
		public virtual bool Contains(Download value)
		{
			return this.List.Contains(value);
		}

		/// <summary>
		/// Return the zero-based index of the first occurrence of a specific value
		/// in this DownloadCollection
		/// </summary>
		/// <param name="value">
		/// The Download value to locate in the DownloadCollection.
		/// </param>
		/// <returns>
		/// The zero-based index of the first occurrence of the _ELEMENT value if found;
		/// -1 otherwise.
		/// </returns>
		public virtual int IndexOf(Download value)
		{
			return this.List.IndexOf(value);
		}

		/// <summary>
		/// Inserts an element into the DownloadCollection at the specified index
		/// </summary>
		/// <param name="index">
		/// The index at which the Download is to be inserted.
		/// </param>
		/// <param name="value">
		/// The Download to insert.
		/// </param>
		public virtual void Insert(int index, Download value)
		{
			this.List.Insert(index, value);
		}

		/// <summary>
		/// Gets or sets the Download at the given index in this DownloadCollection.
		/// </summary>
		public virtual Download this[int index]
		{
			get
			{
				return (Download) this.List[index];
			}
			set
			{
				this.List[index] = value;
			}
		}

		/// <summary>
		/// Removes the first occurrence of a specific Download from this DownloadCollection.
		/// </summary>
		/// <param name="value">
		/// The Download value to remove from this DownloadCollection.
		/// </param>
		public virtual void Remove(Download value)
		{
			this.List.Remove(value);
		}

		/// <summary>
		/// Type-specific enumeration class, used by DownloadCollection.GetEnumerator.
		/// </summary>
		public class Enumerator: System.Collections.IEnumerator
		{
			private System.Collections.IEnumerator wrapped;

			public Enumerator(DownloadCollection collection)
			{
				this.wrapped = ((System.Collections.CollectionBase)collection).GetEnumerator();
			}

			public Download Current
			{
				get
				{
					return (Download) (this.wrapped.Current);
				}
			}

			object System.Collections.IEnumerator.Current
			{
				get
				{
					return (Download) (this.wrapped.Current);
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
		/// Returns an enumerator that can iterate through the elements of this DownloadCollection.
		/// </summary>
		/// <returns>
		/// An object that implements System.Collections.IEnumerator.
		/// </returns>        
		public new virtual DownloadCollection.Enumerator GetEnumerator()
		{
			return new DownloadCollection.Enumerator(this);
		}
	}

}
