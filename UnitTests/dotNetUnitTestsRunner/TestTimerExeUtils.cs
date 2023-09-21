using System;
using System.Web;
using System.IO;
using System.Reflection;
using NUnit.Framework;
using System.Diagnostics;

namespace dotNetUnitTestsRunner
{
    public class TestTimerExeUtils
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
                string result = Path.Combine(Location, "TestTimer.exe");
                Assert.IsTrue(File.Exists(result), string.Format("Missing {0}", result));
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
                        string.Format(@"..\..\..\..\TestTimer\bin\{0}\net20\", configuration)));
                }

                return _location;
            }
        }

        public static int Run()
        {
            Process p = Detach();
            p.WaitForExit();
            return p.ExitCode;
        }

        private static Process Detach()
        {
            return Detach(string.Empty);
        }

        private static Process Detach(string args)
        {
            Process p = new Process();
            p.StartInfo.WorkingDirectory = Location;
            p.StartInfo.FileName = Executable;
            p.StartInfo.Arguments = args;
            p.StartInfo.WindowStyle = ProcessWindowStyle.Normal;
            p.Start();
            return p;
        }
    }
}
