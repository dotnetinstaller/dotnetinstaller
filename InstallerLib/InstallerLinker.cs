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

            args.WriteLine(string.Format("Embedding banner \"{0}\"", args.banner));
            ResourceUpdate.UpdateResourceWithFile(args.output, "RES_BANNER", "CUSTOM", 0, args.banner);
            
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

            if (args.embed)
            {
                CabLib.Compress cab = new CabLib.Compress();

                string supportdir = string.IsNullOrEmpty(args.apppath)
                    ? Path.GetDirectoryName(Path.GetFullPath(args.config))
                    : args.apppath;

                args.WriteLine(string.Format("Compressing files from \"{0}\"", supportdir));

                ArrayList files = new ArrayList();
                foreach (Configuration c in configfile.Configurations)
                {
                    IList<string> c_files = c.GetFiles();
                    foreach (string file in c_files)
                    {
                        string fullpath = file.Replace(@"#APPPATH", supportdir)
                            .Replace(@"#TEMPPATH", supportdir)
                            .Replace(@"#CABPATH", supportdir);
                        string relativepath = file.Replace(@"#APPPATH", string.Empty)
                            .Replace(@"#TEMPPATH", string.Empty)
                            .Replace(@"#CABPATH", string.Empty)
                            .TrimStart(@"\/".ToCharArray());
                        
                        args.WriteLine(string.Format(" {0}", relativepath));
                        files.Add(new string[] { fullpath, relativepath });
                    }
                }

                if (args.embedFiles != null)
                {
                    foreach (string filename in args.embedFiles)
                    {
                        args.WriteLine(string.Format(" {0}", filename));
                        string fullpath = Path.Combine(args.apppath, filename);
                        files.Add(new string[] { fullpath, filename });
                    }
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
