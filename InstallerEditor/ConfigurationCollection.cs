using System;

namespace InstallerEditor
{
	/// <summary>
	/// A collection of elements of type Configuration
	/// </summary>
	public class ConfigurationCollection: System.Collections.CollectionBase
	{
		/// <summary>
		/// Initializes a new empty instance of the ConfigurationCollection class.
		/// </summary>
		public ConfigurationCollection()
		{
			// empty
		}

		/// <summary>
		/// Initializes a new instance of the ConfigurationCollection class, containing elements
		/// copied from an array.
		/// </summary>
		/// <param name="items">
		/// The array whose elements are to be added to the new ConfigurationCollection.
		/// </param>
		public ConfigurationCollection(Configuration[] items)
		{
			this.AddRange(items);
		}

		/// <summary>
		/// Initializes a new instance of the ConfigurationCollection class, containing elements
		/// copied from another instance of ConfigurationCollection
		/// </summary>
		/// <param name="items">
		/// The ConfigurationCollection whose elements are to be added to the new ConfigurationCollection.
		/// </param>
		public ConfigurationCollection(ConfigurationCollection items)
		{
			this.AddRange(items);
		}

		/// <summary>
		/// Adds the elements of an array to the end of this ConfigurationCollection.
		/// </summary>
		/// <param name="items">
		/// The array whose elements are to be added to the end of this ConfigurationCollection.
		/// </param>
		public virtual void AddRange(Configuration[] items)
		{
			foreach (Configuration item in items)
			{
				this.List.Add(item);
			}
		}

		/// <summary>
		/// Adds the elements of another ConfigurationCollection to the end of this ConfigurationCollection.
		/// </summary>
		/// <param name="items">
		/// The ConfigurationCollection whose elements are to be added to the end of this ConfigurationCollection.
		/// </param>
		public virtual void AddRange(ConfigurationCollection items)
		{
			foreach (Configuration item in items)
			{
				this.List.Add(item);
			}
		}

		/// <summary>
		/// Adds an instance of type Configuration to the end of this ConfigurationCollection.
		/// </summary>
		/// <param name="value">
		/// The Configuration to be added to the end of this ConfigurationCollection.
		/// </param>
		public virtual void Add(Configuration value)
		{
			this.List.Add(value);
		}

		/// <summary>
		/// Determines whether a specfic Configuration value is in this ConfigurationCollection.
		/// </summary>
		/// <param name="value">
		/// The Configuration value to locate in this ConfigurationCollection.
		/// </param>
		/// <returns>
		/// true if value is found in this ConfigurationCollection;
		/// false otherwise.
		/// </returns>
		public virtual bool Contains(Configuration value)
		{
			return this.List.Contains(value);
		}

		/// <summary>
		/// Return the zero-based index of the first occurrence of a specific value
		/// in this ConfigurationCollection
		/// </summary>
		/// <param name="value">
		/// The Configuration value to locate in the ConfigurationCollection.
		/// </param>
		/// <returns>
		/// The zero-based index of the first occurrence of the _ELEMENT value if found;
		/// -1 otherwise.
		/// </returns>
		public virtual int IndexOf(Configuration value)
		{
			return this.List.IndexOf(value);
		}

		/// <summary>
		/// Inserts an element into the ConfigurationCollection at the specified index
		/// </summary>
		/// <param name="index">
		/// The index at which the Configuration is to be inserted.
		/// </param>
		/// <param name="value">
		/// The Configuration to insert.
		/// </param>
		public virtual void Insert(int index, Configuration value)
		{
			this.List.Insert(index, value);
		}

		/// <summary>
		/// Gets or sets the Configuration at the given index in this ConfigurationCollection.
		/// </summary>
		public virtual Configuration this[int index]
		{
			get
			{
				return (Configuration) this.List[index];
			}
			set
			{
				this.List[index] = value;
			}
		}

		/// <summary>
		/// Removes the first occurrence of a specific Configuration from this ConfigurationCollection.
		/// </summary>
		/// <param name="value">
		/// The Configuration value to remove from this ConfigurationCollection.
		/// </param>
		public virtual void Remove(Configuration value)
		{
			this.List.Remove(value);
		}

		/// <summary>
		/// Type-specific enumeration class, used by ConfigurationCollection.GetEnumerator.
		/// </summary>
		public class Enumerator: System.Collections.IEnumerator
		{
			private System.Collections.IEnumerator wrapped;

			public Enumerator(ConfigurationCollection collection)
			{
				this.wrapped = ((System.Collections.CollectionBase)collection).GetEnumerator();
			}

			public Configuration Current
			{
				get
				{
					return (Configuration) (this.wrapped.Current);
				}
			}

			object System.Collections.IEnumerator.Current
			{
				get
				{
					return (Configuration) (this.wrapped.Current);
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
		/// Returns an enumerator that can iterate through the elements of this ConfigurationCollection.
		/// </summary>
		/// <returns>
		/// An object that implements System.Collections.IEnumerator.
		/// </returns>        
		public new virtual ConfigurationCollection.Enumerator GetEnumerator()
		{
			return new ConfigurationCollection.Enumerator(this);
		}
	}

}
