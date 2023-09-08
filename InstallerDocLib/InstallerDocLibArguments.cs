using System;
using CommandLine;
using System.IO;

namespace InstallerDocLib
{
    /// <summary>
    /// Linker arguments
    /// </summary>
    public class InstallerDocLibArguments
    {
        [Argument(ArgumentType.AtMostOnce, HelpText = "Location of output .aml files", LongName = "Output", ShortName = "o")]
        public string output;

        public void Validate()
        {
            // output
            if (string.IsNullOrEmpty(output))
                throw new ArgumentNullException("output");
            output = Path.GetFullPath(output);
        }
    }
}
