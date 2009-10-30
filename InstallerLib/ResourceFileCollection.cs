using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;

namespace InstallerLib
{
    /// <summary>
    /// A pair of source->target file for embedding.
    /// </summary>
    public class ResourceFilePair
    {
        private string _path;
        private string _id;

        public string path
        {
            get { return _path; }
        }

        public string id
        {
            get { return _id; }
        }

        public ResourceFilePair(string id, string path)
        {
            _id = id;
            _path = path;
        }

        public override bool Equals(object obj)
        {
            if (obj is ResourceFilePair)
            {
                ResourceFilePair pair = obj as ResourceFilePair;
                return pair._id == _id;
            }

            return base.Equals(obj);
        }

        public override int GetHashCode()
        {
            return base.GetHashCode();
        }
    }

    /// <summary>
    /// A collection of elements of type ResourceFile.
    /// </summary>
    public class ResourceFileCollection : IList<ResourceFilePair>, ICollection<ResourceFilePair>, IEnumerable<ResourceFilePair>
    {
        private List<ResourceFilePair> _files = new List<ResourceFilePair>();
        private string _supportdir;

        public ResourceFileCollection(string supportdir)
        {
            _supportdir = supportdir;
        }

        /// <summary>
        /// Add a file with an id and a relative path.
        /// </summary>
        /// <param name="id">resource id</param>
        /// <param name="path">path</param>
        public void Add(string id, string path)
        {
            string fullpath = path
                .Replace(@"#APPPATH", _supportdir)
                .Replace(@"#TEMPPATH", _supportdir)
                .Replace(@"#CABPATH", _supportdir);
            Add(new ResourceFilePair(id, fullpath));
        }

        /// <summary>
        /// Check whether all embedded files exist.
        /// </summary>
        /// <param name="args"></param>
        public void CheckFilesExist(InstallerLinkerArguments args)
        {
            int filesMissing = 0;
            foreach (ResourceFilePair file in _files)
            {
                args.WriteLine(string.Format(" {0} ({1})", file.id, file.path));
                if (!File.Exists(file.path))
                {
                    args.WriteError(string.Format("Resource file '{0}' does not exist", file.path));
                    filesMissing++;
                }
            }

            if (filesMissing > 0)
            {
                throw new Exception(string.Format("Missing {0} resource file(s)",
                    filesMissing));
            }
        }

        /// <summary>
        /// Add a unique file pair.
        /// </summary>
        /// <param name="pair">file pair</param>
        /// <returns>true if added a unique file pair</returns>
        public bool Add(ResourceFilePair pair)
        {
            foreach (ResourceFilePair existingPair in _files)
            {
                if (existingPair.Equals(pair))
                    return false;
            }

            _files.Add(pair);
            return true;
        }

        /// <summary>
        /// Add a range of file pairs.
        /// </summary>
        /// <param name="range">a range of file pairs</param>
        public void AddRange(IEnumerable<ResourceFilePair> range)
        {
            foreach (ResourceFilePair pair in range)
            {
                Add(pair);
            }
        }

        /// <summary>
        /// Add a range of file pairs.
        /// </summary>
        /// <param name="range">a range of file pairs</param>
        public void AddRange(ResourceFileCollection range)
        {
            foreach (ResourceFilePair pair in range._files)
            {
                Add(pair);
            }
        }

        #region IEnumerable<ResourceFilePair> Members

        public IEnumerator<ResourceFilePair> GetEnumerator()
        {
            return _files.GetEnumerator();
        }

        #endregion

        #region IEnumerable Members

        IEnumerator IEnumerable.GetEnumerator()
        {
            return _files.GetEnumerator();
        }

        #endregion

        #region IList<ResourceFilePair> Members

        public int IndexOf(ResourceFilePair item)
        {
            return _files.IndexOf(item);
        }

        public void Insert(int index, ResourceFilePair item)
        {
            _files.Insert(index, item);
        }

        public void RemoveAt(int index)
        {
            _files.RemoveAt(index);
        }

        public ResourceFilePair this[int index]
        {
            get
            {
                return _files[index];
            }
            set
            {
                _files[index] = value;
            }
        }

        #endregion

        #region ICollection<ResourceFilePair> Members

        void ICollection<ResourceFilePair>.Add(ResourceFilePair item)
        {
            throw new Exception("The method or operation is not implemented.");
        }

        public void Clear()
        {
            throw new Exception("The method or operation is not implemented.");
        }

        public bool Contains(ResourceFilePair item)
        {
            throw new Exception("The method or operation is not implemented.");
        }

        public void CopyTo(ResourceFilePair[] array, int arrayIndex)
        {
            throw new Exception("The method or operation is not implemented.");
        }

        public bool IsReadOnly
        {
            get { throw new Exception("The method or operation is not implemented."); }
        }

        public bool Remove(ResourceFilePair item)
        {
            throw new Exception("The method or operation is not implemented.");
        }

        #endregion

        #region ICollection<ResourceFilePair> Members

        void ICollection<ResourceFilePair>.Clear()
        {
            _files.Clear();
        }

        bool ICollection<ResourceFilePair>.Contains(ResourceFilePair item)
        {
            return _files.Contains(item);
        }

        void ICollection<ResourceFilePair>.CopyTo(ResourceFilePair[] array, int arrayIndex)
        {
            _files.CopyTo(array, arrayIndex);
        }

        public int Count
        {
            get
            {
                return _files.Count;
            }
        }

        int ICollection<ResourceFilePair>.Count
        {
            get { return _files.Count; }
        }

        bool ICollection<ResourceFilePair>.IsReadOnly
        {
            get { return false; }
        }

        bool ICollection<ResourceFilePair>.Remove(ResourceFilePair item)
        {
            return _files.Remove(item);
        }

        #endregion

        #region IEnumerable<ResourceFilePair> Members

        IEnumerator<ResourceFilePair> IEnumerable<ResourceFilePair>.GetEnumerator()
        {
            return _files.GetEnumerator();
        }

        #endregion
    }
}
