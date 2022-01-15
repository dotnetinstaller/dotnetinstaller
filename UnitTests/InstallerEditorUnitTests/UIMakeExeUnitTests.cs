using System;

using NUnit.Framework;
using dotNetUnitTestsRunner;
using System.Diagnostics;
using TestStack.White;
using TestStack.White.Factory;
using TestStack.White.UIItems;
using TestStack.White.UIItems.WindowItems;
using TestStack.White.UIItems.WindowStripControls;
using TestStack.White.WindowsAPI;
using System.IO;
using InstallerLib;

namespace InstallerEditorUnitTests
{
    [TestFixture]
    public class UIMakeExeUnitTests : EnUsUnitTests
    {
        [Test]
        public void TestMakeExe()
        {
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            string configFileName = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFileName);
            configFile.SaveAs(configFileName);
            try
            {
                ProcessStartInfo pi = new ProcessStartInfo(InstallerEditorExeUtils.Executable, "\"" + configFileName + "\"");
                using (Application installerEditor = Application.Launch(pi))
                {
                    Window mainWindow = installerEditor.GetWindow(string.Format("Installer Editor - {0}", configFileName), InitializeOption.NoCache);
                    // create exe dialog
                    UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("File", "Create Exe...").Click();
                    Window createExeWindow = mainWindow.ModalWindow("Create Executable");
                    Console.WriteLine(dotNetInstallerExeUtils.Executable);
                    UIAutomation.Find<TextBox>(createExeWindow, "txtTemplateFile").BulkText = dotNetInstallerExeUtils.Executable;
                    UIAutomation.Find<Button>(createExeWindow, "btMake").Click();
                    // make opens a Save As dialog
                    string outputFilename = Path.Combine(Path.GetTempPath(), string.Format("{0}.exe", Guid.NewGuid()));

                    Window saveAsWindow = createExeWindow.ModalWindow("Save As");
                    TextBox filenameTextBox = saveAsWindow.Get<TextBox>("File name:");
                    filenameTextBox.BulkText = outputFilename;
                    saveAsWindow.KeyIn(KeyboardInput.SpecialKeys.RETURN);
                    saveAsWindow.WaitWhileBusy();
                    mainWindow.WaitWhileBusy();
                    Assert.IsTrue(File.Exists(outputFilename));
                    File.Delete(outputFilename);
                }
            }
            finally
            {
                File.Delete(configFileName);
            }
        }
    }
}
