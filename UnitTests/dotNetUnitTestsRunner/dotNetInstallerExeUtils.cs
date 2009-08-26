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
                        string.Format("..\\..\\..\\..\\dotNetInstaller\\{0}\\", configuration)));
                }

                return _location;
            }
        }

        public static string DefaultLogFile
        {
            get
            {
                return Path.Combine(Path.GetTempPath(), "dotNetInstallerUnitTests.log");
            }
        }

        public static int Run(string configFile)
        {
            return Run(configFile, true, DefaultLogFile);
        }

        public static int Run(string configFile, bool log, string logfile)
        {
            Console.WriteLine("dotNetInstaller: {0}", Executable);
            if (! string.IsNullOrEmpty(logfile))
                Console.WriteLine("Log: {0}", (logfile));
            Process p = new Process();
            string args = string.Format("/ConfigFile \"{0}\" /q", configFile);
            if (log) args += " /Log";
            if (!string.IsNullOrEmpty(logfile)) args += string.Format(" /LogFile \"{0}\"", logfile);
            return Run(Executable, args);
        }

        public static int Run(string filename, string args)
        {
            Process p = new Process();
            p.StartInfo.WorkingDirectory = Path.GetDirectoryName(filename);
            p.StartInfo.FileName = filename;
            p.StartInfo.Arguments = args;
            p.StartInfo.WindowStyle = ProcessWindowStyle.Normal;
            p.Start();
            p.WaitForExit();
            return p.ExitCode;
        }
    }
}
