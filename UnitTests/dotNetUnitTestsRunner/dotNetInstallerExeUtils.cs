using System;
using System.Collections.Generic;
using System.Text;
using System.Web;
using System.IO;
using System.Reflection;
using NUnit.Framework;
using System.Diagnostics;

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

            public string Args
            {
                get
                {
                    string args = string.Format("/ConfigFile \"{0}\"", configFile);
                    if (quiet) args += " /q";
                    if (reboot) args += " /reboot";
                    if (log)
                    {
                        args += " /Log";
                        if (!string.IsNullOrEmpty(logfile))
                        {
                            Console.WriteLine("Log: {0}", (logfile));
                            args += string.Format(" /LogFile \"{0}\"", logfile);
                        }
                    }
                    return args;
                }
            }
        }

#if DEBUG
        const string configuration = "Debug";
#else
        const string configuration = "Release";
#endif

        private static string _location = null;

        public static string Executable
        {
            get
            {
                string result = Path.Combine(Location, "dotNetInstaller.exe");
                Assert.IsTrue(File.Exists(result));
                return result;
            }
        }

        public static string Location
        {
            get
            {
                if (string.IsNullOrEmpty(_location))
                {
                    // locate dotnetinstaller.exe
                    Uri uri = new Uri(Assembly.GetExecutingAssembly().CodeBase);
                    _location = Path.GetFullPath(Path.Combine(Path.GetDirectoryName(HttpUtility.UrlDecode(uri.AbsolutePath)),
                        string.Format(@"..\..\..\..\dotNetInstaller\{0}\", configuration)));
                }

                return _location;
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
            return Detach(Executable, options.Args);
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
