using System;
using CommandLine;
using System.Reflection;
using System.IO;

namespace InstallerDocLib
{
    class InstallerDocLib
    {
        [STAThread]
        public static int Main(string[] args)
        {
            int rc = 0;

            Console.WriteLine("InstallerDocLib: InstallerLib Documenter ({0})", Assembly.GetExecutingAssembly().GetName().Version);
            Console.WriteLine();

            InstallerDocLibArguments i_args = new InstallerDocLibArguments();
            if (Parser.ParseArgumentsWithUsage(args, i_args))
            {
                try
                {
                    if (!Directory.Exists(i_args.output))
                    {
                        Console.WriteLine("Creating {0}", i_args.output);
                        Directory.CreateDirectory(i_args.output);
                    }

                    Console.WriteLine("Generating reference in {0}", i_args.output);
                    DocLibGenerator generator = new DocLibGenerator(i_args.output);
                    generator.Generate();
                }
                catch (Exception ex)
                {
                    Console.WriteLine(string.Format("ERROR: {0}", ex.Message));
#if DEBUG
                    Console.WriteLine(ex.StackTrace);
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
