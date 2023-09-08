using System;
using System.Web;
using System.IO;
using System.Reflection;
using NUnit.Framework;
using System.Diagnostics;
using System.Threading;

namespace dotNetUnitTestsRunner
{
    public class InstallerEditorExeUtils
    {
        public class RunResult
        {
            public int ExitCode = -1;
            public string WindowTitle = string.Empty;
        }

        public class RunOptions
        {
            public string args;

            public RunOptions()
            {

            }

            public string CommandLineArgs
            {
                get
                {
                    string result = string.Empty;

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

        private static string _location = null;

        public static string Executable
        {
            get
            {
                string result = Path.Combine(Location, "InstallerEditor.exe");
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
                        string.Format(@"..\..\..\..\..\InstallerEditor\bin\{0}\net40", configuration)));
                }

                return _location;
            }
        }

        public static Process Detach(RunOptions options)
        {
            Console.WriteLine("InstallerEditor: {0}", Executable);
            return Detach(Executable, options.CommandLineArgs);
        }

        public static RunResult Run(RunOptions options)
        {
            RunResult result = new RunResult();
            using (Process p = Detach(options))
            {
                Thread.Sleep(2000);
                p.WaitForInputIdle();
                result.WindowTitle = p.MainWindowTitle;
                p.CloseMainWindow();
                p.WaitForExit();
                result.ExitCode = p.ExitCode;
            }
            return result;
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
