using System;
using System.Collections;

namespace InstallerLib
{
	/// <summary>
	/// A collection of elements of type EmbedFile
	/// </summary>
	public class EmbedFileCollection : System.Collections.CollectionBase
	{
		public EmbedFileCollection()
		{

		}

		/// <summary>
		/// Initializes a new instance of the EmbedFileCollection class, containing elements
		/// copied from an array.
		/// </summary>
		/// <param name="items">
		/// The array whose elements are to be added to the new EmbedFileCollection.
		/// </param>
		public EmbedFileCollection(EmbedFile[] items)
		{
			this.AddRange(items);
		}

		/// <summary>
		/// Initializes a new instance of the EmbedFileCollection class, containing elements
		/// copied from another instance of EmbedFileCollection
		/// </summary>
		/// <param name="items">
		/// The EmbedFileCollection whose elements are to be added to the new EmbedFileCollection.
		/// </param>
		public EmbedFileCollection(EmbedFileCollection items)
		{
			this.AddRange(items);
		}

		/// <summary>
		/// Adds the elements of an array to the end of this EmbedFileCollection.
		/// </summary>
		/// <param name="items">
		/// The array whose elements are to be added to the end of this EmbedFileCollection.
		/// </param>
		public virtual void AddRange(EmbedFile[] items)
		{
			foreach (EmbedFile item in items)
			{
				this.List.Add(item);
			}
		}

		/// <summary>
		/// Adds the elements of another EmbedFileCollection to the end of this EmbedFileCollection.
		/// </summary>
		/// <param name="items">
		/// The EmbedFileCollection whose elements are to be added to the end of this EmbedFileCollection.
		/// </param>
		public virtual void AddRange(EmbedFileCollection items)
		{
			foreach (EmbedFile item in items)
			{
				this.List.Add(item);
			}
		}

		/// <summary>
		/// Adds an instance of type EmbedFile to the end of this EmbedFileCollection.
		/// </summary>
		/// <param name="value">
		/// The EmbedFile to be added to the end of this EmbedFileCollection.
		/// </param>
		public virtual void Add(EmbedFile value)
		{
			this.List.Add(value);
		}

		/// <summary>
		/// Determines whether a specfic EmbedFile value is in this EmbedFileCollection.
		/// </summary>
		/// <param name="value">
		/// The EmbedFile value to locate in this EmbedFileCollection.
		/// </param>
		/// <returns>
		/// true if value is found in this EmbedFileCollection;
		/// false otherwise.
		/// </returns>
		public virtual bool Contains(EmbedFile value)
		{
			return this.List.Contains(value);
		}

		/// <summary>
		/// Return the zero-based index of the first occurrence of a specific value
		/// in this EmbedFileCollection
		/// </summary>
		/// <param name="value">
		/// The EmbedFile value to locate in the EmbedFileCollection.
		/// </param>
		/// <returns>
		/// The zero-based index of the first occurrence of the _ELEMENT value if found;
		/// -1 otherwise.
		/// </returns>
		public virtual int IndexOf(EmbedFile value)
		{
			return this.List.IndexOf(value);
		}

		/// <summary>
		/// Inserts an element into the EmbedFileCollection at the specified index
		/// </summary>
		/// <param name="index">
		/// The index at which the EmbedFile is to be inserted.
		/// </param>
		/// <param name="value">
		/// The EmbedFile to insert.
		/// </param>
		public virtual void Insert(int index, EmbedFile value)
		{
			this.List.Insert(index, value);
		}

		/// <summary>
		/// Gets or sets the EmbedFile at the given index in this EmbedFileCollection.
		/// </summary>
		public virtual EmbedFile this[int index]
		{
			get
			{
				return (EmbedFile) this.List[index];
			}
			set
			{
				this.List[index] = value;
			}
		}

		/// <summary>
		/// Removes the first occurrence of a specific EmbedFile from this EmbedFileCollection.
		/// </summary>
		/// <param name="value">
		/// The EmbedFile value to remove from this EmbedFileCollection.
		/// </param>
		public virtual void Remove(EmbedFile value)
		{
			this.List.Remove(value);
		}

		/// <summary>
		/// Type-specific enumeration class, used by EmbedFileCollection.GetEnumerator.
		/// </summary>
		public class Enumerator: System.Collections.IEnumerator
		{
			private System.Collections.IEnumerator wrapped;

			public Enumerator(EmbedFileCollection collection)
			{
				this.wrapped = ((System.Collections.CollectionBase)collection).GetEnumerator();
			}

			public EmbedFile Current
			{
				get
				{
					return (EmbedFile) (this.wrapped.Current);
				}
			}

			object System.Collections.IEnumerator.Current
			{
				get
				{
					return (EmbedFile) (this.wrapped.Current);
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
		/// Returns an enumerator that can iterate through the elements of this EmbedFileCollection.
		/// </summary>
		/// <returns>
		/// An object that implements System.Collections.IEnumerator.
		/// </returns>        
		public new virtual EmbedFileCollection.Enumerator GetEnumerator()
		{
			return new EmbedFileCollection.Enumerator(this);
		}

        public ArrayList GetFilePairs(string supportdir)
        {
            ArrayList files = new ArrayList();
            foreach (EmbedFile file in this)
            {
                string fullpath = file.sourcefilepath.Replace(@"#APPPATH", supportdir)
                    .Replace(@"#TEMPPATH", supportdir)
                    .Replace(@"#CABPATH", supportdir);
                string relativepath = string.IsNullOrEmpty(file.targetfilepath)
                    ? file.sourcefilepath : file.targetfilepath;
                relativepath = relativepath.Replace(@"#APPPATH", string.Empty)
                    .Replace(@"#TEMPPATH", string.Empty)
                    .Replace(@"#CABPATH", string.Empty)
                    .TrimStart(@"\/".ToCharArray());

                bool dupe = false;
                foreach (string[] filepair in files)
                {
                    if (filepair[0] == fullpath && filepair[1] == relativepath)
                    {
                        dupe = true;
                        break;
                    }
                }

                if (!dupe)
                {
                    files.Add(new string[] { fullpath, relativepath });
                }
            }

            return files;
        }
	}

}
