using System;

namespace InstallerEditor
{
	/// <summary>
	/// A collection of elements of type installedcheck
	/// </summary>
	public class installedcheckCollection: System.Collections.CollectionBase
	{
		/// <summary>
		/// Initializes a new empty instance of the installedcheckCollection class.
		/// </summary>
		public installedcheckCollection()
		{
			// empty
		}

		/// <summary>
		/// Initializes a new instance of the installedcheckCollection class, containing elements
		/// copied from an array.
		/// </summary>
		/// <param name="items">
		/// The array whose elements are to be added to the new installedcheckCollection.
		/// </param>
		public installedcheckCollection(installedcheck[] items)
		{
			this.AddRange(items);
		}

		/// <summary>
		/// Initializes a new instance of the installedcheckCollection class, containing elements
		/// copied from another instance of installedcheckCollection
		/// </summary>
		/// <param name="items">
		/// The installedcheckCollection whose elements are to be added to the new installedcheckCollection.
		/// </param>
		public installedcheckCollection(installedcheckCollection items)
		{
			this.AddRange(items);
		}

		/// <summary>
		/// Adds the elements of an array to the end of this installedcheckCollection.
		/// </summary>
		/// <param name="items">
		/// The array whose elements are to be added to the end of this installedcheckCollection.
		/// </param>
		public virtual void AddRange(installedcheck[] items)
		{
			foreach (installedcheck item in items)
			{
				this.List.Add(item);
			}
		}

		/// <summary>
		/// Adds the elements of another installedcheckCollection to the end of this installedcheckCollection.
		/// </summary>
		/// <param name="items">
		/// The installedcheckCollection whose elements are to be added to the end of this installedcheckCollection.
		/// </param>
		public virtual void AddRange(installedcheckCollection items)
		{
			foreach (installedcheck item in items)
			{
				this.List.Add(item);
			}
		}

		/// <summary>
		/// Adds an instance of type installedcheck to the end of this installedcheckCollection.
		/// </summary>
		/// <param name="value">
		/// The installedcheck to be added to the end of this installedcheckCollection.
		/// </param>
		public virtual void Add(installedcheck value)
		{
			this.List.Add(value);
		}

		/// <summary>
		/// Determines whether a specfic installedcheck value is in this installedcheckCollection.
		/// </summary>
		/// <param name="value">
		/// The installedcheck value to locate in this installedcheckCollection.
		/// </param>
		/// <returns>
		/// true if value is found in this installedcheckCollection;
		/// false otherwise.
		/// </returns>
		public virtual bool Contains(installedcheck value)
		{
			return this.List.Contains(value);
		}

		/// <summary>
		/// Return the zero-based index of the first occurrence of a specific value
		/// in this installedcheckCollection
		/// </summary>
		/// <param name="value">
		/// The installedcheck value to locate in the installedcheckCollection.
		/// </param>
		/// <returns>
		/// The zero-based index of the first occurrence of the _ELEMENT value if found;
		/// -1 otherwise.
		/// </returns>
		public virtual int IndexOf(installedcheck value)
		{
			return this.List.IndexOf(value);
		}

		/// <summary>
		/// Inserts an element into the installedcheckCollection at the specified index
		/// </summary>
		/// <param name="index">
		/// The index at which the installedcheck is to be inserted.
		/// </param>
		/// <param name="value">
		/// The installedcheck to insert.
		/// </param>
		public virtual void Insert(int index, installedcheck value)
		{
			this.List.Insert(index, value);
		}

		/// <summary>
		/// Gets or sets the installedcheck at the given index in this installedcheckCollection.
		/// </summary>
		public virtual installedcheck this[int index]
		{
			get
			{
				return (installedcheck) this.List[index];
			}
			set
			{
				this.List[index] = value;
			}
		}

		/// <summary>
		/// Removes the first occurrence of a specific installedcheck from this installedcheckCollection.
		/// </summary>
		/// <param name="value">
		/// The installedcheck value to remove from this installedcheckCollection.
		/// </param>
		public virtual void Remove(installedcheck value)
		{
			this.List.Remove(value);
		}

		/// <summary>
		/// Type-specific enumeration class, used by installedcheckCollection.GetEnumerator.
		/// </summary>
		public class Enumerator: System.Collections.IEnumerator
		{
			private System.Collections.IEnumerator wrapped;

			public Enumerator(installedcheckCollection collection)
			{
				this.wrapped = ((System.Collections.CollectionBase)collection).GetEnumerator();
			}

			public installedcheck Current
			{
				get
				{
					return (installedcheck) (this.wrapped.Current);
				}
			}

			object System.Collections.IEnumerator.Current
			{
				get
				{
					return (installedcheck) (this.wrapped.Current);
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
		/// Returns an enumerator that can iterate through the elements of this installedcheckCollection.
		/// </summary>
		/// <returns>
		/// An object that implements System.Collections.IEnumerator.
		/// </returns>        
		public new virtual installedcheckCollection.Enumerator GetEnumerator()
		{
			return new installedcheckCollection.Enumerator(this);
		}
	}

}
