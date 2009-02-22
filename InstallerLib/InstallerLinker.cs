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

            System.IO.File.Copy(args.template, args.output, true);
            System.IO.File.SetAttributes(args.output, System.IO.FileAttributes.Normal);

            ResourceUpdate.UpdateResourceWithFile(args.output, "RES_BANNER", "CUSTOM", 0, args.banner);
            ResourceUpdate.UpdateResourceWithFile(args.output, "RES_CONFIGURATION", "CUSTOM", 0, args.config);

            ConfigFile configfile = new ConfigFile();
            configfile.Load(args.config);

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
                stringFileInfo[attr.name] = attr.data;
            }

            rc.SaveTo(args.output);

            if (args.embed)
            {
                CabLib.Compress cab = new CabLib.Compress();

                string supportdir = string.IsNullOrEmpty(args.apppath)
                    ? Path.GetDirectoryName(Path.GetFullPath(args.config))
                    : args.apppath;

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
                        files.Add(new string[] { fullpath, relativepath });
                    }
                }

                string cabname = Path.Combine(Path.GetDirectoryName(args.output), "Setup.cab");
                cab.CompressFileList(files, cabname, true, 0);

                ResourceUpdate.UpdateResourceWithFile(args.output, "RES_CAB", "CUSTOM", 0, cabname);
                File.Delete(cabname);
            }
        }
    }
}
