using System;
using System.Collections.Generic;
using System.Web;
using System.IO;
using System.Reflection;
using NUnit.Framework;
using System.Diagnostics;
using InstallerLib;

namespace dotNetUnitTestsRunner
{
    public class InstallerLinkerExeUtils
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
                string result = Path.Combine(Location, "InstallerLinker.exe");
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
                        string.Format(@"..\..\..\..\..\InstallerLinker\bin\{0}\net40\", configuration)));
                }

                return _location;
            }
        }

        public static int Run(string filename, string args)
        {
            Console.WriteLine("{0} {1}", filename, args);
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
            p.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
            p.Start();
            return p;
        }

        public static int CreateInstaller(InstallerLinkerArguments args)
        {
            List<String> cmd = new List<string>();
            cmd.Add(string.Format("/Configuration:\"{0}\"", args.config));
            cmd.Add(string.Format("/Template:\"{0}\"", dotNetInstallerExeUtils.Executable));
            cmd.Add(string.Format("/Output:\"{0}\"", args.output));
            if (!string.IsNullOrEmpty(args.apppath))
            {
                cmd.Add(string.Format("/AppPath:\"{0}\"", args.apppath.TrimEnd("\\".ToCharArray())));
            }
            if (args.verbose) cmd.Add("/Verbose+");
            if (args.embed) cmd.Add("/Embed+");
            if (args.embedFiles != null)
            {
                foreach (string file in args.embedFiles)
                    cmd.Add(string.Format("/EmbedFile:\"{0}\"", file));
            }
            if (args.embedFolders != null)
            {
                foreach (string folder in args.embedFolders)
                    cmd.Add(string.Format("/EmbedFolder:\"{0}\"", folder));
            }
            if (args.htmlFiles != null)
            {
                foreach (string folder in args.htmlFiles)
                    cmd.Add(string.Format("/EmbedHtml:\"{0}\"", folder));
            }
            return Run(InstallerLinkerExeUtils.Executable, string.Join(" ", cmd.ToArray()));
        }
    }
}
