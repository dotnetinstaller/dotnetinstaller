using System;
using System.IO;
using NUnit.Framework;
using System.Diagnostics;
using System.Configuration;
using Microsoft.Win32;

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
            public bool autostart = false;
            public bool uninstall = false;
            public string args;
            public bool noreboot = true;
            public bool noRunOnReboot = false;

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
                    if (!string.IsNullOrEmpty(configFile))
                    {
                        result += string.Format("/ConfigFile \"{0}\"", configFile);
                    }

                    if (quiet) result += " /q";
                    if (reboot) result += " /reboot";
                    if (autostart) result += " /autostart";
                    if (noreboot) result += " /noreboot";
                    if (noRunOnReboot) result += " /noRunOnReboot";
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
                Assert.IsTrue(File.Exists(executable), string.Format("Executable '{0}' doesn't exist.", executable));
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
            return Run(options, new TimeSpan(-1));
        }

        /// <summary>
        /// Runs the installer and waits till its exit for a specified timeout.
        /// </summary>
        /// <param name="options">Run options.</param>
        /// <param name="timeout">Timeout. Negative values mean "no timeout".</param>
        /// <returns>Exit code of the installer process.</returns>
        /// <exception cref="TimeoutException">
        /// Timeout exceeded while waiting for the installer process to exit.
        /// </exception>
        public static int Run(RunOptions options, TimeSpan timeout)
        {
            Process p = Detach(options);
            if (timeout < TimeSpan.Zero)
            {
                p.WaitForExit();
            }
            else
            {
                if (!p.WaitForExit((int)timeout.TotalMilliseconds))
                {
                    p.Kill();
                    p.WaitForExit();
                    throw new TimeoutException();
                }
            }
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

        public static void DisableRunOnReboot()
        {
            using (RegistryKey key = Registry.LocalMachine.OpenSubKey(@"SOFTWARE\Microsoft\Windows\CurrentVersion\Run", true))
            {
                key.DeleteValue(Path.GetFileName(Executable), false);
            }
        }
    }
}
