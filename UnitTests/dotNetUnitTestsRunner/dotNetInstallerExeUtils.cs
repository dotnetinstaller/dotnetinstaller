using System;
using System.Collections.Generic;
using System.Text;
using System.Web;
using System.IO;
using System.Reflection;
using NUnit.Framework;
using System.Diagnostics;
using System.Configuration;

namespace dotNetUnitTestsRunner
{
    public class dotNetInstallerExeUtils
    {
        public class RunOptions
        {
            public string configFile;
            public bool log = true;
            public string logfile = DefaultLogFile;
            public bool quiet = true;
            public bool reboot = false;
            public bool uninstall = false;
            public string args;

            public RunOptions()
            {
            
            }

            public RunOptions(string file)
            {
                configFile = file;
            }

            public static string DefaultLogFile
            {
                get
                {
                    return Path.Combine(Path.GetTempPath(), "dotNetInstallerUnitTests.log");
                }
            }

            public string CommandLineArgs
            {
                get
                {
                    string result = string.Empty;
                    if (! string.IsNullOrEmpty(configFile))
                    {
                        result += string.Format("/ConfigFile \"{0}\"", configFile);
                    }

                    if (quiet) result += " /q";
                    if (reboot) result += " /reboot";
                    if (log)
                    {
                        result += " /Log";
                        if (!string.IsNullOrEmpty(logfile))
                        {
                            Console.WriteLine("Log: {0}", (logfile));
                            result += string.Format(" /LogFile \"{0}\"", logfile);
                        }
                    }

                    if (uninstall) result += " /x";

                    if (!string.IsNullOrEmpty(args))
                    {
                        result += " ";
                        result += args;
                    }

                    return result;
                }
            }
        }

#if DEBUG
        const string configuration = "Debug";
#else
        const string configuration = "Release";
#endif

        public static string Executable
        {
            get
            {
                string executable = ConfigurationManager.AppSettings["executable"];
                if (string.IsNullOrEmpty(executable))
                {
                    throw new Exception("Missing executable in .config");
                }
                Assert.IsTrue(File.Exists(executable));
                return executable;
            }
        }

        public static string Location
        {
            get
            {
                return Path.GetDirectoryName(Executable);
            }
        }

        public static int Run(string configFile)
        {
            RunOptions options = new RunOptions(configFile);
            return Run(options);
        }

        public static int Run(RunOptions options)
        {
            Process p = Detach(options);
            p.WaitForExit();
            return p.ExitCode;
        }

        public static Process Detach(RunOptions options)
        {
            Console.WriteLine("dotNetInstaller: {0}", Executable);
            return Detach(Executable, options.CommandLineArgs);
        }

        public static int Run(string filename, string args)
        {
            Process p = Detach(filename, args);
            p.WaitForExit();
            return p.ExitCode;
        }

        private static Process Detach(string filename, string args)
        {
            Process p = new Process();
            p.StartInfo.WorkingDirectory = Path.GetDirectoryName(filename);
            p.StartInfo.FileName = filename;
            p.StartInfo.Arguments = args;
            p.StartInfo.WindowStyle = ProcessWindowStyle.Normal;
            p.Start();
            return p;
        }
    }
}
