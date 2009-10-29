using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using Vestris.ResourceLib;
using System.IO;
using CabLib;

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
            System.IO.File.Copy(args.template, args.output, true);
            System.IO.File.SetAttributes(args.output, System.IO.FileAttributes.Normal);

            if (!string.IsNullOrEmpty(args.banner))
            {
                args.WriteLine(string.Format("Embedding banner \"{0}\"", args.banner));
                ResourceUpdate.WriteFile(args.output, new ResourceId("CUSTOM"), new ResourceId("RES_BANNER"), 0, args.banner);
            }

            if (!string.IsNullOrEmpty(args.splash))
            {
                args.WriteLine(string.Format("Embedding splash screen \"{0}\"", args.splash));
                ResourceUpdate.WriteFile(args.output, new ResourceId("CUSTOM"), new ResourceId("RES_SPLASH"), 0, args.splash);
            }

            args.WriteLine(string.Format("Embedding configuration \"{0}\"", args.config));
            ResourceUpdate.WriteFile(args.output, new ResourceId("CUSTOM"), new ResourceId("RES_CONFIGURATION"), 0, args.config);

            ConfigFile configfile = new ConfigFile();
            configfile.Load(args.config);

            // \todo: check XML with XSD, warn if nodes are being dropped
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
                rc.FileVersion = configfile.fileversion;

            foreach (FileAttribute attr in configfile.fileattributes)
            {
                args.WriteLine(string.Format(" {0}: {1}", attr.name, attr.value));
                stringFileInfo[attr.name] = attr.value;
            }

            rc.Language = ResourceUtil.NEUTRALLANGID;
            rc.SaveTo(args.output);

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

            if (args.embed)
            {
                string supportdir = string.IsNullOrEmpty(args.apppath)
                    ? Environment.CurrentDirectory
                    : args.apppath;

                args.WriteLine(string.Format("Compressing files from \"{0}\"", supportdir));

                EmbedFileCollection c_files = configfile.GetFiles(supportdir);
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

                c_files.CheckFilesExist(args);
                c_files.CheckFileAttributes(args);

                ArrayList files = c_files.GetFilePairs();

                // create a temporary directory for CABs
                string cabtemp = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString());
                Directory.CreateDirectory(cabtemp);
                args.WriteLine(string.Format("Writing CABs to \"{0}\"", cabtemp));

                // compress new CABs
                string cabname = Path.Combine(cabtemp, "SETUP_%d.CAB");
                Compress cab = new Compress();
                long totalSize = 0;
                cab.evFilePlaced += delegate(string s_File, int s32_FileSize, bool bContinuation)
                {
                    if (! bContinuation)
                    {
                        totalSize += s32_FileSize;
                        args.WriteLine(String.Format(" {0} - {1}", s_File, EmbedFileCollection.FormatBytes(s32_FileSize)));
                    }

                    return 0;
                };
                cab.CompressFileList(files, cabname, true, true, args.embedResourceSize);
                
                // embed new CABs
                args.WriteLine("Embedding CABs");
                foreach (string cabfile in Directory.GetFiles(cabtemp))
                {
                    args.WriteLine(string.Format(" {0} - {1}", Path.GetFileName(cabfile),
                        Path.GetFileNameWithoutExtension(cabfile)));
                    ResourceUpdate.WriteFile(args.output, new ResourceId("RES_CAB"),
                        new ResourceId(Path.GetFileNameWithoutExtension(cabfile).ToUpper()),
                        ResourceUtil.NEUTRALLANGID, cabfile);
                }

                args.WriteLine("Embedding CAB directory");
                StringBuilder fileslist = new StringBuilder();
                fileslist.AppendLine(string.Format("Total embedded CAB size: {0}",
                    EmbedFileCollection.FormatBytes(totalSize)));
                fileslist.AppendLine();
                fileslist.Append(String.Join("\r\n", c_files.GetFileValuesWithSize()));
                byte[] fileslist_b = Encoding.Unicode.GetBytes(fileslist.ToString());
                ResourceUpdate.Write(args.output, new ResourceId("CUSTOM"), new ResourceId("RES_CAB_LIST"),
                    ResourceUtil.NEUTRALLANGID, fileslist_b);

                args.WriteLine(string.Format("Cleaning up \"{0}\"", cabtemp));
                Directory.Delete(cabtemp, true);
            }

            if (! string.IsNullOrEmpty(args.manifest))
            {
                args.WriteLine(string.Format("Embedding manifest \"{0}\"", args.manifest));
                ManifestResource manifest = new ManifestResource();
                manifest.Manifest.Load(args.manifest);
                manifest.SaveTo(args.output);
            }

            args.WriteLine(string.Format("Successfully created \"{0}\"", args.output));
        }
    }
}
