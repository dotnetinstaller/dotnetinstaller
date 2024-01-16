using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using Vestris.ResourceLib;
using System.IO;
using CabLib;
using System.Runtime.InteropServices;
using System.ComponentModel;
using System.Xml;

namespace InstallerLib
{
    /// <summary>
    /// An installer linker.
    /// </summary>
    public static class InstallerLinker
    {
        public static void CreateInstaller(InstallerLinkerArguments args)
        {
            args.Validate();

            args.WriteLine(string.Format("Creating \"{0}\" from \"{1}\"", args.output, args.template));
            File.Copy(args.template, args.output, true);
            File.SetAttributes(args.output, FileAttributes.Normal);

            string configFilename = args.config;

            #region Version Information

            ConfigFile configfile = new ConfigFile();
            configfile.Load(configFilename);

            // \todo: check XML with XSD, warn if nodes are being dropped

            // filter the configuration
            string configTemp = null;
            if (!string.IsNullOrEmpty(args.processorArchitecture))
            {
                int configurationCount = configfile.ConfigurationCount;
                int componentCount = configfile.ComponentCount;
                args.WriteLine(string.Format("Applying processor architecture filter \"{0}\"", args.processorArchitecture));
                ProcessorArchitectureFilter filter = new ProcessorArchitectureFilter(args.processorArchitecture);
                XmlDocument filteredXml = configfile.GetXml(filter);
                configTemp = configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString());
                filteredXml.Save(configTemp);
                configfile.LoadXml(filteredXml);
                args.WriteLine(string.Format(" configurations: {0} => {1}", configurationCount, configfile.ConfigurationCount));
                args.WriteLine(string.Format(" components: {0} => {1}", componentCount, configfile.ComponentCount));
            }

            args.WriteLine(string.Format("Updating binary attributes in \"{0}\"", args.output));
            VersionResource rc = new VersionResource();
            rc.LoadFrom(args.output);

            // version information
            StringFileInfo stringFileInfo = (StringFileInfo)rc["StringFileInfo"];
            if (!string.IsNullOrEmpty(configfile.productversion))
            {
                rc.ProductVersion = configfile.productversion;
                stringFileInfo["ProductVersion"] = configfile.productversion;
            }

            if (!string.IsNullOrEmpty(configfile.fileversion))
            {
                rc.FileVersion = configfile.fileversion;
                stringFileInfo["FileVersion"] = configfile.fileversion;
            }

            foreach (FileAttribute attr in configfile.fileattributes)
            {
                args.WriteLine(string.Format(" {0}: {1}", attr.name, attr.value));
                stringFileInfo[attr.name] = attr.value;
            }

            rc.Language = ResourceUtil.NEUTRALLANGID;
            rc.SaveTo(args.output);

            #endregion

            #region Optional Icon
            // optional icon
            if (!string.IsNullOrEmpty(args.icon))
            {
                args.WriteLine(string.Format("Embedding icon \"{0}\"", args.icon));
                IconFile iconFile = new IconFile(args.icon);
                List<string> iconSizes = new List<string>();
                foreach (IconFileIcon icon in iconFile.Icons)
                    iconSizes.Add(icon.ToString());
                args.WriteLine(string.Format(" {0}", string.Join(", ", iconSizes.ToArray())));
                IconDirectoryResource iconDirectory = new IconDirectoryResource(iconFile);
                iconDirectory.Name = new ResourceId(128);
                iconDirectory.Language = ResourceUtil.NEUTRALLANGID;
                iconDirectory.SaveTo(args.output);
            }
            #endregion

            #region Manifest
            if (!string.IsNullOrEmpty(args.manifest))
            {
                args.WriteLine(string.Format("Embedding manifest \"{0}\"", args.manifest));
                ManifestResource manifest = new ManifestResource();
                manifest.Manifest.Load(args.manifest);
                manifest.SaveTo(args.output);
            }
            #endregion

            string supportdir = string.IsNullOrEmpty(args.apppath)
                ? Environment.CurrentDirectory
                : args.apppath;

            string templatepath = Path.GetDirectoryName(Path.GetFullPath(args.template));

            // create a temporary directory for CABs
            string cabtemp = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString());
            Directory.CreateDirectory(cabtemp);
            args.WriteLine(string.Format("Writing CABs to \"{0}\"", cabtemp));

            try
            {
                #region Prepare CABs

                long totalSize = 0;
                List<String> allFilesList = new List<string>();

                // embedded files
                if (args.embed)
                {
                    args.WriteLine(string.Format("Compressing files in \"{0}\"", supportdir));
                    Dictionary<string, EmbedFileCollection> all_files = configfile.GetFiles(string.Empty, supportdir);
                    // ensure at least one for additional command-line parameters
                    if (all_files.Count == 0) all_files.Add(string.Empty, new EmbedFileCollection(supportdir));
                    using (Dictionary<string, EmbedFileCollection>.Enumerator enumerator = all_files.GetEnumerator())
                    {
                        while (enumerator.MoveNext())
                        {
                            EmbedFileCollection c_files = enumerator.Current.Value;

                            // add additional command-line files to the root CAB
                            if (string.IsNullOrEmpty(enumerator.Current.Key))
                            {
                                if (args.embedFiles != null)
                                {
                                    foreach (string filename in args.embedFiles)
                                    {
                                        string fullpath = Path.Combine(args.apppath, filename);
                                        c_files.Add(new EmbedFilePair(fullpath, filename));
                                    }
                                }

                                if (args.embedFolders != null)
                                {
                                    foreach (string folder in args.embedFolders)
                                    {
                                        c_files.AddDirectory(folder);
                                    }
                                }
                            }

                            if (c_files.Count == 0)
                                continue;

                            c_files.CheckFilesExist(args);
                            c_files.CheckFileAttributes(args);

                            ArrayList files = c_files.GetFilePairs();

                            // compress new CABs
                            string cabname = string.IsNullOrEmpty(enumerator.Current.Key)
                                ? Path.Combine(cabtemp, "SETUP_%d.CAB")
                                : Path.Combine(cabtemp, string.Format("SETUP_{0}_%d.CAB", enumerator.Current.Key));

                            Compress cab = new Compress();
                            long currentSize = 0;
                            cab.evFilePlaced += delegate(string s_File, int s32_FileSize, bool bContinuation)
                            {
                                if (!bContinuation)
                                {
                                    totalSize += s32_FileSize;
                                    currentSize += s32_FileSize;
                                    args.WriteLine(String.Format(" {0} - {1}", s_File, EmbedFileCollection.FormatBytes(s32_FileSize)));
                                }

                                return 0;
                            };
                            cab.CompressFileList(files, cabname, true, true, args.embedResourceSize);

                            StringBuilder fileslist = new StringBuilder();
                            fileslist.AppendLine(string.Format("{0} CAB size: {1}",
                                string.IsNullOrEmpty(enumerator.Current.Key) ? "*" : enumerator.Current.Key,
                                EmbedFileCollection.FormatBytes(currentSize)));

                            fileslist.Append(" " + String.Join("\r\n ", c_files.GetFileValuesWithSize(2)));
                            allFilesList.Add(fileslist.ToString());
                        }
                    }
                }
                #endregion

                #region Resources
                // embed resources

                IntPtr h = ResourceUpdate.BeginUpdateResource(args.output, false);

                if (h == IntPtr.Zero)
                {
                    throw new Win32Exception(Marshal.GetLastWin32Error());
                }

                if (!string.IsNullOrEmpty(args.banner))
                {
                    args.WriteLine(string.Format("Embedding banner \"{0}\"", args.banner));
                    ResourceUpdate.WriteFile(h, new ResourceId("CUSTOM"), new ResourceId("RES_BANNER"),
                        ResourceUtil.NEUTRALLANGID, args.banner);
                }

                if (!string.IsNullOrEmpty(args.splash))
                {
                    args.WriteLine(string.Format("Embedding splash screen \"{0}\"", args.splash));
                    ResourceUpdate.WriteFile(h, new ResourceId("CUSTOM"), new ResourceId("RES_SPLASH"),
                        ResourceUtil.NEUTRALLANGID, args.splash);
                }

                args.WriteLine(string.Format("Embedding configuration \"{0}\"", configFilename));
                ResourceUpdate.WriteFile(h, new ResourceId("CUSTOM"), new ResourceId("RES_CONFIGURATION"),
                    ResourceUtil.NEUTRALLANGID, configFilename);

                #region Embed Resources

                EmbedFileCollection html_files = new EmbedFileCollection(args.apppath);

                if (args.htmlFiles != null)
                {
                    foreach (string filename in args.htmlFiles)
                    {
                        string fullpath = Path.GetFullPath(filename);
                        if (Directory.Exists(fullpath))
                        {
                            html_files.AddDirectory(fullpath);
                        }
                        else
                        {
                            html_files.Add(new EmbedFilePair(fullpath, Path.GetFileName(filename)));
                        }
                    }
                }

                using (IEnumerator<EmbedFilePair> html_files_enumerator = html_files.GetEnumerator())
                {
                    while (html_files_enumerator.MoveNext())
                    {
                        EmbedFilePair pair = html_files_enumerator.Current;
                        String id = "";
                        for (int i = 0; i < pair.relativepath.Length; i++)
                        {
                            id += Char.IsLetterOrDigit(pair.relativepath[i]) ? pair.relativepath[i] : '_';
                        }

                        args.WriteLine(string.Format("Embedding HTML resource \"{0}\": {1}", id, pair.fullpath));
                        ResourceUpdate.WriteFile(h, new ResourceId("HTM"), new ResourceId(id.ToUpper()),
                            ResourceUtil.NEUTRALLANGID, pair.fullpath);
                    }
                }

                #endregion

                #region Embed CABs

                if (args.embed)
                {
                    args.WriteLine("Embedding CABs");
                    foreach (string cabfile in Directory.GetFiles(cabtemp))
                    {
                        args.WriteLine(string.Format(" {0} - {1}", Path.GetFileName(cabfile),
                            EmbedFileCollection.FormatBytes(new FileInfo(cabfile).Length)));

                        ResourceUpdate.WriteFile(h, new ResourceId("RES_CAB"), new ResourceId(Path.GetFileName(cabfile)),
                            ResourceUtil.NEUTRALLANGID, cabfile);
                    }

                    // cab directory

                    args.WriteLine("Embedding CAB directory");
                    StringBuilder filesDirectory = new StringBuilder();
                    filesDirectory.AppendLine(string.Format("Total CAB size: {0}\r\n", EmbedFileCollection.FormatBytes(totalSize)));
                    filesDirectory.AppendLine(string.Join("\r\n\r\n", allFilesList.ToArray()));
                    byte[] filesDirectory_b = Encoding.Unicode.GetBytes(filesDirectory.ToString());
                    ResourceUpdate.Write(h, new ResourceId("CUSTOM"), new ResourceId("RES_CAB_LIST"),
                        ResourceUtil.NEUTRALLANGID, filesDirectory_b);
                }

                #endregion

                // resource files
                ResourceFileCollection resources = configfile.GetResources(supportdir);
                foreach (ResourceFilePair r_pair in resources)
                {
                    args.WriteLine(string.Format("Embedding resource \"{0}\": {1}", r_pair.id, r_pair.path));
                    ResourceUpdate.WriteFile(h, new ResourceId("CUSTOM"), new ResourceId(r_pair.id),
                        ResourceUtil.NEUTRALLANGID, r_pair.path);
                }

                args.WriteLine(string.Format("Writing {0}", EmbedFileCollection.FormatBytes(totalSize)));

                if (!ResourceUpdate.EndUpdateResource(h, false))
                    throw new Win32Exception(Marshal.GetLastWin32Error());

                #endregion
            }
            finally
            {
                if (Directory.Exists(cabtemp))
                {
                    args.WriteLine(string.Format("Cleaning up \"{0}\"", cabtemp));
                    Directory.Delete(cabtemp, true);
                }

                if (!string.IsNullOrEmpty(configTemp))
                {
                    args.WriteLine(string.Format("Cleaning up \"{0}\"", configTemp));
                    File.Delete(configTemp);
                }
            }

            args.WriteLine(string.Format("Successfully created \"{0}\" ({1})",
                args.output, EmbedFileCollection.FormatBytes(new FileInfo(args.output).Length)));
        }
    }
}
