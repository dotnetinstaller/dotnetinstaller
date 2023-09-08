using CommandLine;

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
