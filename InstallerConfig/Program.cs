using System;
using InstallerLib;
using CommandLine;
using System.Reflection;

namespace InstallerConfig
{
    public class InstallerConfigArguments
    {
        [Argument(ArgumentType.Required, HelpText = "Configuration file to (re)write", LongName = "ConfigFile", ShortName = "c")]
        public string configfile;
        [Argument(ArgumentType.AtMostOnce, HelpText = "Target configuration file name", LongName = "OutputFile", ShortName = "p")]
        public string outputfile;
    }

    public class InstallerConfig
    {
        [STAThread]
        public static int Main(string[] args)
        {
            int rc = 0;
            Console.WriteLine("InstallerConfig: dotNetInstaller configuration (re)writer ({0})", Assembly.GetExecutingAssembly().GetName().Version);
            Console.WriteLine();

            InstallerConfigArguments i_args = new InstallerConfigArguments();
            if (Parser.ParseArgumentsWithUsage(args, i_args))
            {
                try
                {
                    ConfigFile configFile = new ConfigFile();
                    configFile.Load(i_args.configfile);
                    configFile.SaveAs(string.IsNullOrEmpty(i_args.outputfile)
                        ? i_args.configfile
                        : i_args.outputfile);
                }
                catch (Exception ex)
                {
                    Console.Error.WriteLine("ERROR: {0}", ex.Message);
#if DEBUG
                    Console.Error.WriteLine(ex.StackTrace);
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
