using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;

namespace InstallerLib
{
    public class EmbedFilePair
    {
        private string _fullpath;
        private string _relativepath;

        public string fullpath
        {
            get { return _fullpath; }
        }

        public string relativepath
        {
            get { return _relativepath; }
        }

        public EmbedFilePair(string fullpath, string relativepath)
        {
            _fullpath = fullpath;
            _relativepath = relativepath;
        }

        public override bool Equals(object obj)
        {
            if (obj is EmbedFilePair)
            {
                EmbedFilePair pair = obj as EmbedFilePair;
                return pair._fullpath == _fullpath && pair._relativepath == _relativepath;
            }

            return base.Equals(obj);
        }
    }

    /// <summary>
    /// A collection of elements of type EmbedFile.
    /// </summary>
    public class EmbedFileCollection : IList<EmbedFilePair>, ICollection<EmbedFilePair>, IEnumerable<EmbedFilePair>
    {
        private List<EmbedFilePair> _files = new List<EmbedFilePair>();
        private string _supportdir;

        public EmbedFileCollection(string supportdir)
        {
            _supportdir = supportdir;
        }

        /// <summary>
        /// Add a file with a relative path.
        /// </summary>
        /// <param name="sourcefilepath">full path</param>
        /// <param name="targetfilepath">relative path</param>
        public void Add(string sourcefilepath, string targetfilepath)
        {
            string fullpath = sourcefilepath
                .Replace(@"#APPPATH", _supportdir)
                .Replace(@"#TEMPPATH", _supportdir)
                .Replace(@"#CABPATH", _supportdir);
            string relativepath = string.IsNullOrEmpty(targetfilepath)
                ? Path.GetFileName(sourcefilepath) : targetfilepath;
            relativepath = relativepath.Replace(@"#APPPATH", string.Empty)
                .Replace(@"#TEMPPATH", string.Empty)
                .Replace(@"#CABPATH", string.Empty)
                .TrimStart(@"\/".ToCharArray());

            Add(new EmbedFilePair(fullpath, relativepath));
        }

        /// <summary>
        /// Add an entire directory.
        /// </summary>
        /// <param name="folder">directory to add</param>
        public void AddDirectory(string folder)
        {
            AddDirectory(folder, string.Empty);
        }

        /// <summary>
        /// Add an entire directory.
        /// </summary>
        /// <param name="folder">directory to add</param>
        /// <param name="targetfolderpath">a relative directory under which target is extracted</param>
        public void AddDirectory(string folder, string targetfolderpath)
        {
            if (string.IsNullOrEmpty(folder))
            {
                throw new Exception("Missing folder");
            }

            string directory = Path.GetDirectoryName(folder);
            string flags = Path.GetFileName(folder);
            if (!(flags.Contains("?") || flags.Contains("*")))
            {
                directory = folder;
                flags = "*.*";
            }

            if ((File.GetAttributes(directory) & FileAttributes.Hidden) == FileAttributes.Hidden)
                return;

            directory = directory.TrimEnd(Path.DirectorySeparatorChar);

            string[] folderfiles = Directory.GetFiles(directory, flags, SearchOption.AllDirectories);
            foreach (string folderfile in folderfiles)
            {
                string relativefolderfile = folderfile.Substring(directory.Length + 1)
                    .Trim(Path.DirectorySeparatorChar);

                if (!string.IsNullOrEmpty(targetfolderpath))
                {
                    relativefolderfile = targetfolderpath.Trim(Path.DirectorySeparatorChar) +
                       Path.DirectorySeparatorChar + relativefolderfile;
                }

                string folderfilefullpath = Path.GetFullPath(folderfile);

                if ((File.GetAttributes(folderfilefullpath) & FileAttributes.Hidden) == FileAttributes.Hidden)
                    continue;

                Add(new EmbedFilePair(folderfilefullpath, relativefolderfile));
            }
        }

        /// <summary>
        /// Checks file attributes and warns the user if any are read-only.
        /// </summary>
        /// <param name="args"></param>
        public void CheckFileAttributes(InstallerLinkerArguments args)
        {
            foreach (EmbedFilePair file in _files)
            {
                if ((File.GetAttributes(file.fullpath) & FileAttributes.ReadOnly) == FileAttributes.ReadOnly)
                {
                    args.WriteLine(string.Format("Embedded file '{0}' is and will be extracted read-only.", file.fullpath));
                }
            }
        }

        /// <summary>
        /// Check whether all embedded files exist.
        /// </summary>
        /// <param name="args"></param>
        public void CheckFilesExist(InstallerLinkerArguments args)
        {
            int filesMissing = 0;
            foreach (EmbedFilePair file in _files)
            {
                args.WriteLine(string.Format(" {0} ({1})", file.fullpath, file.relativepath));
                if (!File.Exists(file.fullpath))
                {
                    args.WriteError(string.Format("Embedded file '{0}' does not exist", file.fullpath));
                    filesMissing++;
                }
            }

            if (filesMissing > 0)
            {
                throw new Exception(string.Format("Missing {0} embedded file(s)",
                    filesMissing));
            }
        }

        /// <summary>
        /// Add a unique file pair.
        /// </summary>
        /// <param name="pair">file pair</param>
        /// <returns>true if added a unique file pair</returns>
        public bool Add(EmbedFilePair pair)
        {
            foreach (EmbedFilePair existingPair in _files)
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
        public void AddRange(IEnumerable<EmbedFilePair> range)
        {
            foreach (EmbedFilePair pair in range)
            {
                Add(pair);
            }
        }

        /// <summary>
        /// Add a range of file pairs.
        /// </summary>
        /// <param name="range">a range of file pairs</param>
        public void AddRange(EmbedFileCollection range)
        {
            foreach (EmbedFilePair pair in range._files)
            {
                Add(pair);
            }
        }

        /// <summary>
        /// Get an array list of file pairs for embedding.
        /// </summary>
        /// <returns>an array list of file pairs</returns>
        public ArrayList GetFilePairs()
        {
            ArrayList files = new ArrayList();
            foreach (EmbedFilePair file in _files)
            {
                files.Add(new string[] { file.fullpath, file.relativepath });
            }

            return files;
        }

        #region IEnumerable<EmbedFilePair> Members

        public IEnumerator<EmbedFilePair> GetEnumerator()
        {
            throw new Exception("The method or operation is not implemented.");
        }

        #endregion

        #region IEnumerable Members

        IEnumerator IEnumerable.GetEnumerator()
        {
            return _files.GetEnumerator();
        }

        #endregion

        #region IList<EmbedFilePair> Members

        public int IndexOf(EmbedFilePair item)
        {
            throw new Exception("The method or operation is not implemented.");
        }

        public void Insert(int index, EmbedFilePair item)
        {
            throw new Exception("The method or operation is not implemented.");
        }

        public void RemoveAt(int index)
        {
            throw new Exception("The method or operation is not implemented.");
        }

        public EmbedFilePair this[int index]
        {
            get
            {
                throw new Exception("The method or operation is not implemented.");
            }
            set
            {
                throw new Exception("The method or operation is not implemented.");
            }
        }

        #endregion

        #region ICollection<EmbedFilePair> Members

        void ICollection<EmbedFilePair>.Add(EmbedFilePair item)
        {
            throw new Exception("The method or operation is not implemented.");
        }

        public void Clear()
        {
            throw new Exception("The method or operation is not implemented.");
        }

        public bool Contains(EmbedFilePair item)
        {
            throw new Exception("The method or operation is not implemented.");
        }

        public void CopyTo(EmbedFilePair[] array, int arrayIndex)
        {
            throw new Exception("The method or operation is not implemented.");
        }

        public bool IsReadOnly
        {
            get { throw new Exception("The method or operation is not implemented."); }
        }

        public bool Remove(EmbedFilePair item)
        {
            throw new Exception("The method or operation is not implemented.");
        }

        #endregion

        #region ICollection<EmbedFilePair> Members

        void ICollection<EmbedFilePair>.Clear()
        {
            _files.Clear();
        }

        bool ICollection<EmbedFilePair>.Contains(EmbedFilePair item)
        {
            return _files.Contains(item);
        }

        void ICollection<EmbedFilePair>.CopyTo(EmbedFilePair[] array, int arrayIndex)
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

        int ICollection<EmbedFilePair>.Count
        {
            get { return _files.Count;  }
        }

        bool ICollection<EmbedFilePair>.IsReadOnly
        {
            get { return false; }
        }

        bool ICollection<EmbedFilePair>.Remove(EmbedFilePair item)
        {
            return _files.Remove(item);
        }

        #endregion

        #region IEnumerable<EmbedFilePair> Members

        IEnumerator<EmbedFilePair> IEnumerable<EmbedFilePair>.GetEnumerator()
        {
            return _files.GetEnumerator();
        }

        #endregion
    }
}
