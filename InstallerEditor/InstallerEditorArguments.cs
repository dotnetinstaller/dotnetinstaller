using System;
using System.Collections.Generic;
using System.Text;
using CommandLine;
using System.IO;

namespace InstallerEditor
{
    /// <summary>
    /// Editor arguments
    /// </summary>
    public class InstallerEditorArguments
    {
        [DefaultArgument(ArgumentType.AtMostOnce, HelpText = "Configuration file to open")]
        public string configfile;
    }
}
