using System;
using InstallerLib;
using CommandLine;
using System.Reflection;

namespace InstallerLinker
{
    public class InstallerLinker
    {
        [STAThread]
        public static int Main(string[] args)
        {
            int rc = 0;

            Console.WriteLine("InstallerLinker: dotNetInstaller Packager ({0})", Assembly.GetExecutingAssembly().GetName().Version);
            Console.WriteLine();

            InstallerLinkerArguments i_args = new InstallerLinkerArguments();
            if (Parser.ParseArgumentsWithUsage(args, i_args))
            {
                try
                {
                    InstallerLib.InstallerLinker.CreateInstaller(i_args);
                }
                catch (Exception ex)
                {
                    i_args.WriteError(string.Format("ERROR: {0}", ex.Message));
#if DEBUG
                    i_args.WriteError(ex.StackTrace);
#endif
                    rc = -2;
                }
            }
            else
            {
                rc = -1;
            }

            return rc;
        }
    }
}
