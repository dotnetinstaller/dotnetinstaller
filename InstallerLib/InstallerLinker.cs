using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using Vestris.ResourceLib;
using System.IO;

namespace InstallerLib
{
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

            args.WriteLine(string.Format("Updating binary attributes in \"{0}\"", args.output));
            VersionResource rc = new VersionResource();
            rc.LoadFrom(args.output);

            /* Daniel Doubrovkine - 2008-06-27: added version information */
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

            /* Daniel Doubrovkine - 2008-09-28: added icon */
            if (!string.IsNullOrEmpty(args.icon))
            {
                args.WriteLine(string.Format("Embedding icon \"{0}\"", args.icon));
                IconFile iconFile = new IconFile(args.icon);
                List<string> iconSizes = new List<string>();
                foreach (IconFileIcon icon in iconFile.Icons)
                    iconSizes.Add(icon.ToString());
                args.WriteLine(string.Format(" {0}", string.Join(", ", iconSizes.ToArray())));
                GroupIconResource groupIconResource = iconFile.ConvertToGroupIconResource();
                groupIconResource.Language = (ushort) ResourceUtil.NEUTRALLANGID;
                groupIconResource.Name = "128";
                groupIconResource.SaveTo(args.output);
            }

            if (args.embed)
            {
                CabLib.Compress cab = new CabLib.Compress();

                string supportdir = string.IsNullOrEmpty(args.apppath)
                    ? Path.GetDirectoryName(Path.GetFullPath(args.config))
                    : args.apppath;

                args.WriteLine(string.Format("Compressing files from \"{0}\"", supportdir));

                EmbedFileCollection c_files = configfile.GetFiles();
                if (args.embedFiles != null)
                {
                    foreach (string filename in args.embedFiles)
                    {
                        string fullpath = Path.Combine(args.apppath, filename);
                        c_files.Add(new EmbedFile(fullpath, filename));
                    }
                }

                if (args.embedFolders != null)
                {
                    foreach (string folder in args.embedFolders)
                    {
                        string directory = Path.GetDirectoryName(folder);
                        string flags = Path.GetFileName(folder);
                        if (!(flags.Contains("?") || flags.Contains("*")))
                        {
                            directory = folder;
                            flags = "*.*";
                        }

                        directory = directory.TrimEnd("\\".ToCharArray());
                        
                        string[] folderfiles = Directory.GetFiles(directory, flags, SearchOption.AllDirectories);
                        foreach (string folderfile in folderfiles)
                        {
                            string relativefolderfile = folderfile.Substring(directory.Length + 1);
                            c_files.Add(new EmbedFile(Path.GetFullPath(folderfile), relativefolderfile));
                        }
                    }
                }

                ArrayList files = c_files.GetFilePairs(supportdir);
                foreach (string[] filepair in files)
                {
                    args.WriteLine(string.Format(" {0} ({1})", filepair[1], filepair[0]));
                }

                string cabname = Path.Combine(Path.GetDirectoryName(args.output), "Setup.cab");
                args.WriteLine(string.Format("Writing \"{0}\"", cabname));
                cab.CompressFileList(files, cabname, true, 0);

                args.WriteLine(string.Format("Embedding \"{0}\"", cabname));
                ResourceUpdate.UpdateResourceWithFile(args.output, "RES_CAB", "CUSTOM", 0, cabname);
                File.Delete(cabname);
            }

            args.WriteLine(string.Format("Successfully created \"{0}\"", args.output));
        }
    }
}
