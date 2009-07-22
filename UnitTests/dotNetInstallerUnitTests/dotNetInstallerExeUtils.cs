using System;
using System.Collections.Generic;
using System.Text;
using System.Web;
using System.IO;
using System.Reflection;
using NUnit.Framework;
using System.Diagnostics;

namespace dotNetInstallerUnitTests
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

        public static int Run(string configFile)
        {
            string logfile = Path.Combine(Path.GetTempPath(), "dotNetInstallerUnitTests.log");
            Console.WriteLine("dotNetInstaller: {0}", Executable);
            Console.WriteLine("Log: {0}", logfile);
            Process p = new Process();
            p.StartInfo.FileName = Executable;
            p.StartInfo.Arguments = string.Format("/ConfigFile \"{0}\" /q /Log /LogFile \"{1}\"", configFile, logfile);
            p.StartInfo.WindowStyle = ProcessWindowStyle.Normal;
            p.Start();
            p.WaitForExit();
            return p.ExitCode;
        }
    }
}
