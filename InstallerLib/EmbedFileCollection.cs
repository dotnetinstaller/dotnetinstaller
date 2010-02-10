using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;

namespace InstallerLib
{
    /// <summary>
    /// A pair of source->target file for embedding.
    /// </summary>
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

        public override int GetHashCode()
        {
            return base.GetHashCode();
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
        /// <param name="sourcefilepath">directory to add</param>
        /// <param name="targetfolderpath">a relative directory under which target is extracted</param>
        public void AddDirectory(string sourcefilepath, string targetfolderpath)
        {
            if (string.IsNullOrEmpty(sourcefilepath))
            {
                throw new Exception("Missing folder");
            }

            string fullpath = sourcefilepath
                .Replace(@"#APPPATH", _supportdir)
                .Replace(@"#TEMPPATH", _supportdir)
                .Replace(@"#CABPATH", _supportdir);
            string relativepath = string.IsNullOrEmpty(targetfolderpath)
                ? Path.GetFileName(sourcefilepath) : targetfolderpath;
            relativepath = relativepath.Replace(@"#APPPATH", string.Empty)
                .Replace(@"#TEMPPATH", string.Empty)
                .Replace(@"#CABPATH", string.Empty)
                .TrimStart(@"\/".ToCharArray());

            string directory = Path.GetDirectoryName(fullpath);
            string flags = Path.GetFileName(fullpath);
            if (!(flags.Contains("?") || flags.Contains("*")))
            {
                directory = fullpath;
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

        /// <summary>
        /// Returns a normalized id acceptable for resources.
        /// </summary>
        /// <param name="id"></param>
        /// <returns></returns>
        public static string GetNormalizedId(string id)
        {
            string result = string.Empty;
            for (int i = 0; i < id.Length; i++)
            {
                result += Char.IsLetterOrDigit(id[i])
                    ? Char.ToUpper(id[i])
                    : '_';
            }
            return result;
        }

        #region IEnumerable<EmbedFilePair> Members

        public IEnumerator<EmbedFilePair> GetEnumerator()
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

        #region IList<EmbedFilePair> Members

        public int IndexOf(EmbedFilePair item)
        {
            return _files.IndexOf(item);
        }

        public void Insert(int index, EmbedFilePair item)
        {
            _files.Insert(index, item);
        }

        public void RemoveAt(int index)
        {
            _files.RemoveAt(index);
        }

        public EmbedFilePair this[int index]
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

        public static string FormatBytes(long bytes)
        {
	        if (bytes == 1) // bytes
                return String.Format("{0} byte", bytes);
	        else if (bytes < 1024) // bytes
                return String.Format("{0} bytes", bytes);
	        else if (bytes < 1048576) // Kb
                return String.Format("{0:F1}KB", (double)bytes / 1024);
	        else if (bytes < 1073741824) // Mb
                return String.Format("{0:F1}MB", (double)bytes / 1048576);
	        else if (bytes < 1099511627776 ) // GB
                return String.Format("{0:F1}GB", (double)bytes / 1073741824);
	        else
                return String.Format("{0} bytes", bytes);
        }

        public string[] GetFileValuesWithSize(int cut)
        {
            List<string> values = new List<string>();
            foreach (EmbedFilePair pair in this)
            {
                if (cut > 0 && values.Count >= cut)
                {
                    int remaining = (Count - cut);
                    values.Add(string.Format("+ {0} more file(s) ...", remaining));
                    break;
                }

                values.Add(string.Format("{0} - {1}", pair.relativepath,
                    FormatBytes(new FileInfo(pair.fullpath).Length)));
            }
            return values.ToArray();
        }

        public string[] GetFileValues()
        {
            List<string> values = new List<string>();
            foreach (EmbedFilePair pair in this)
            {
                values.Add(pair.relativepath);
            }
            return values.ToArray();
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
            get { return _files.Count; }
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
