using System;

namespace InstallerEditor
{
	/// <summary>
	/// A collection of elements of type Component
	/// </summary>
	public class ComponentCollection: System.Collections.CollectionBase
	{
		/// <summary>
		/// Initializes a new empty instance of the ComponentCollection class.
		/// </summary>
		public ComponentCollection()
		{
			// empty
		}

		/// <summary>
		/// Initializes a new instance of the ComponentCollection class, containing elements
		/// copied from an array.
		/// </summary>
		/// <param name="items">
		/// The array whose elements are to be added to the new ComponentCollection.
		/// </param>
		public ComponentCollection(Component[] items)
		{
			this.AddRange(items);
		}

		/// <summary>
		/// Initializes a new instance of the ComponentCollection class, containing elements
		/// copied from another instance of ComponentCollection
		/// </summary>
		/// <param name="items">
		/// The ComponentCollection whose elements are to be added to the new ComponentCollection.
		/// </param>
		public ComponentCollection(ComponentCollection items)
		{
			this.AddRange(items);
		}

		/// <summary>
		/// Adds the elements of an array to the end of this ComponentCollection.
		/// </summary>
		/// <param name="items">
		/// The array whose elements are to be added to the end of this ComponentCollection.
		/// </param>
		public virtual void AddRange(Component[] items)
		{
			foreach (Component item in items)
			{
				this.List.Add(item);
			}
		}

		/// <summary>
		/// Adds the elements of another ComponentCollection to the end of this ComponentCollection.
		/// </summary>
		/// <param name="items">
		/// The ComponentCollection whose elements are to be added to the end of this ComponentCollection.
		/// </param>
		public virtual void AddRange(ComponentCollection items)
		{
			foreach (Component item in items)
			{
				this.List.Add(item);
			}
		}

		/// <summary>
		/// Adds an instance of type Component to the end of this ComponentCollection.
		/// </summary>
		/// <param name="value">
		/// The Component to be added to the end of this ComponentCollection.
		/// </param>
		public virtual void Add(Component value)
		{
			this.List.Add(value);
		}

		/// <summary>
		/// Determines whether a specfic Component value is in this ComponentCollection.
		/// </summary>
		/// <param name="value">
		/// The Component value to locate in this ComponentCollection.
		/// </param>
		/// <returns>
		/// true if value is found in this ComponentCollection;
		/// false otherwise.
		/// </returns>
		public virtual bool Contains(Component value)
		{
			return this.List.Contains(value);
		}

		/// <summary>
		/// Return the zero-based index of the first occurrence of a specific value
		/// in this ComponentCollection
		/// </summary>
		/// <param name="value">
		/// The Component value to locate in the ComponentCollection.
		/// </param>
		/// <returns>
		/// The zero-based index of the first occurrence of the _ELEMENT value if found;
		/// -1 otherwise.
		/// </returns>
		public virtual int IndexOf(Component value)
		{
			return this.List.IndexOf(value);
		}

		/// <summary>
		/// Inserts an element into the ComponentCollection at the specified index
		/// </summary>
		/// <param name="index">
		/// The index at which the Component is to be inserted.
		/// </param>
		/// <param name="value">
		/// The Component to insert.
		/// </param>
		public virtual void Insert(int index, Component value)
		{
			this.List.Insert(index, value);
		}

		/// <summary>
		/// Gets or sets the Component at the given index in this ComponentCollection.
		/// </summary>
		public virtual Component this[int index]
		{
			get
			{
				return (Component) this.List[index];
			}
			set
			{
				this.List[index] = value;
			}
		}

		/// <summary>
		/// Removes the first occurrence of a specific Component from this ComponentCollection.
		/// </summary>
		/// <param name="value">
		/// The Component value to remove from this ComponentCollection.
		/// </param>
		public virtual void Remove(Component value)
		{
			this.List.Remove(value);
		}

		/// <summary>
		/// Type-specific enumeration class, used by ComponentCollection.GetEnumerator.
		/// </summary>
		public class Enumerator: System.Collections.IEnumerator
		{
			private System.Collections.IEnumerator wrapped;

			public Enumerator(ComponentCollection collection)
			{
				this.wrapped = ((System.Collections.CollectionBase)collection).GetEnumerator();
			}

			public Component Current
			{
				get
				{
					return (Component) (this.wrapped.Current);
				}
			}

			object System.Collections.IEnumerator.Current
			{
				get
				{
					return (Component) (this.wrapped.Current);
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
		/// Returns an enumerator that can iterate through the elements of this ComponentCollection.
		/// </summary>
		/// <returns>
		/// An object that implements System.Collections.IEnumerator.
		/// </returns>        
		public new virtual ComponentCollection.Enumerator GetEnumerator()
		{
			return new ComponentCollection.Enumerator(this);
		}
	}

}
