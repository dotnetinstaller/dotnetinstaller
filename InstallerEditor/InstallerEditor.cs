using System;
using System.Windows.Forms;
using CommandLine;
using System.Runtime.InteropServices;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using Vestris.ResourceLib;

namespace InstallerEditor
{
    class InstallerEditor
    {
        [DllImport("kernel32.dll", SetLastError = true)]
        private static extern bool AttachConsole(int dwProcessId);

        const int ATTACH_PARENT_PROCESS = -1;

        [DllImport("kernel32.dll", SetLastError = true)]
        private static extern bool FreeConsole();

        [DllImport("kernel32.dll", SetLastError = true)]
        static extern bool AllocConsole();

        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        public static int Main(string[] args)
        {
            int rc = 0;

            if (args.Length == 0)
            {
                Application.Run(new MainForm());
            }
            else
            {
                // attach the default console, enables output from Console.Write for a Win Forms application
                if (!AttachConsole(ATTACH_PARENT_PROCESS))
                {
                    AllocConsole();
                }

                InstallerArgs i_args = new InstallerArgs();
                if (Parser.ParseArgumentsWithUsage(args, i_args))
                {
                    try
                    {
                        CreateInstaller(i_args);
                    }
                    catch (Exception ex)
                    {
                        Console.WriteLine("ERROR: {0}", ex.Message);
                        FreeConsole();
                        rc = -2;
                    }
                }
                else
                {
                    rc = -1;
                }

                FreeConsole();
            }

            return rc;
        }

        public static void CreateInstaller(InstallerArgs args)
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

    public class InstallerArgs
    {
        [Argument(ArgumentType.Required, HelpText = "Generated installer file", LongName = "Output", ShortName = "o")]
        public string output;
        [Argument(ArgumentType.Required, HelpText = "Template installer executable", LongName = "Template", ShortName = "t")]
        public string template;
        [Argument(ArgumentType.Required, HelpText = "Picture for the banner", LongName = "Banner", ShortName = "b")]
        public string banner;
        [Argument(ArgumentType.Required, HelpText = "XML configuration file", LongName = "Configuration", ShortName = "c")]
        public string config;
        [Argument(ArgumentType.AtMostOnce, HelpText = "Embed support files", LongName = "Embed", ShortName = "e")]
        public bool embed;
        [Argument(ArgumentType.AtMostOnce, HelpText = "Location of support files for embedding", LongName = "AppPath", ShortName = "a")]
        public string apppath;

        public void Validate()
        {
            if (!File.Exists(template))
                throw new FileNotFoundException(template);

            if (!File.Exists(banner))
                throw new FileNotFoundException(banner);

            if (!File.Exists(config))
                throw new FileNotFoundException(config);

            if (!string.IsNullOrEmpty(apppath) && !Directory.Exists(apppath))
                throw new DirectoryNotFoundException(apppath);
        }
    }
}
