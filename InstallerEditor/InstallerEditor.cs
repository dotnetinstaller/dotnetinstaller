using System;
using System.Windows.Forms;
using CommandLine;
using System.Runtime.InteropServices;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using InstallerLib;

namespace InstallerEditor
{
    class InstallerEditor
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        public static void Main(string[] args)
        {
            Application.Run(new MainForm());
        }
    }
}
