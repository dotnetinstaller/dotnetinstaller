using System;
using System.Collections;
using System.Collections.Generic;

namespace InstallerLib
{
    /// <summary>
    /// A collection of elements of type EmbedFile.
    /// </summary>
    public class EmbedFileCollection : List<EmbedFile>
    {
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
