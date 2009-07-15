using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using Vestris.ResourceLib;
using System.IO;

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
                ResourceUpdate.UpdateResourceWithFile(args.output, "RES_BANNER", "CUSTOM", 0, args.banner);
            }

            args.WriteLine(string.Format("Embedding configuration \"{0}\"", args.config));
            ResourceUpdate.UpdateResourceWithFile(args.output, "RES_CONFIGURATION", "CUSTOM", 0, args.config);

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
                args.WriteLine(string.Format(" {0}: {1}", attr.name, attr.data));
                stringFileInfo[attr.name] = attr.data;
            }

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
                GroupIconResource groupIconResource = iconFile.ConvertToGroupIconResource();
                groupIconResource.Language = (ushort)ResourceUtil.NEUTRALLANGID;
                groupIconResource.Name = "128";
                groupIconResource.SaveTo(args.output);
            }

            if (args.embed)
            {
                CabLib.Compress cab = new CabLib.Compress();

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
                string cabname = Path.Combine(Path.GetDirectoryName(args.output), "Setup.cab");
                args.WriteLine(string.Format("Writing \"{0}\"", cabname));
                cab.CompressFileList(files, cabname, true, 0);

                args.WriteLine(string.Format("Embedding CAB directory", cabname));
                StringBuilder fileslist = new StringBuilder();
                fileslist.AppendLine(string.Format("Total embedded CAB size: {0}", EmbedFileCollection.FormatBytes(new FileInfo(cabname).Length)));
                fileslist.AppendLine();
                fileslist.Append(String.Join("\r\n", c_files.GetFileValuesWithSize()));
                byte[] fileslist_b = Encoding.Unicode.GetBytes(fileslist.ToString());
                ResourceUpdate.UpdateResource(args.output, "RES_CAB_LIST", "CUSTOM", fileslist_b, 0);

                args.WriteLine(string.Format("Embedding \"{0}\"", cabname));
                ResourceUpdate.UpdateResourceWithFile(args.output, "RES_CAB", "BINARY", 0, cabname, 32 * 1024 * 1024, args);
                File.Delete(cabname);
            }

            args.WriteLine(string.Format("Successfully created \"{0}\"", args.output));
        }
    }
}
