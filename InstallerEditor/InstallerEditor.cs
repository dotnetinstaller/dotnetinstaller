using System;
using System.Windows.Forms;
using CommandLine;
using System.Runtime.InteropServices;
using System.IO;

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

        public void Validate()
        {
            if (!File.Exists(template))
                throw new FileNotFoundException(template);

            if (!File.Exists(banner))
                throw new FileNotFoundException(banner);

            if (!File.Exists(config))
                throw new FileNotFoundException(config);
        }
    }
}
