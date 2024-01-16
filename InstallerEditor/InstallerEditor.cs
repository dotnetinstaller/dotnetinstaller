using System;
using System.Windows.Forms;
using CommandLine;
using System.Text;
using System.Reflection;

namespace InstallerEditor
{
    class InstallerEditor
    {
        private static InstallerEditorArguments _cmdargs = new InstallerEditorArguments();

        /// <summary>
        /// Command-line arguments.
        /// </summary>
        public static InstallerEditorArguments CmdArgs
        {
            get
            {
                return _cmdargs;
            }
        }

        private static void ReportError(string message)
        {
            throw new Exception(message);
        }

        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        public static int Main(string[] args)
        {
            try
            {
                if (Parser.ParseHelp(args))
                {
                    StringBuilder sb = new StringBuilder();
                    sb.AppendLine(string.Format("InstallerEditor: dotNetInstaller Configuration Editor ({0})",
                        Assembly.GetExecutingAssembly().GetName().Version));
                    sb.AppendLine();
                    sb.AppendLine(Parser.ArgumentsUsage(typeof(InstallerEditorArguments)));
                    MessageBox.Show(sb.ToString(), "Installer Editor Help", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    return 2;
                }

                if (Parser.ParseArguments(args, _cmdargs, new ErrorReporter(ReportError)))
                {
                    Application.Run(new MainForm());
                }

                return Environment.ExitCode;
            }
            catch (Exception ex)
            {
                AppUtility.ShowError(null, ex);
                return -1;
            }
        }
    }
}
