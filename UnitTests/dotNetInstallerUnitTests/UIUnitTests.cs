// -----------------------------------------------------------------------
// <copyright file="UIUnitTests.cs" company="DevAge, Vestris Inc. &amp; Contributors">
//   Copyright (c) DevAge, Vestris Inc. &amp; Contributors.
// </copyright>
// -----------------------------------------------------------------------

namespace dotNetInstallerUnitTests
{
    using System;
    using System.Diagnostics;
    using System.IO;
    using dotNetUnitTestsRunner;
    using InstallerLib;
    using NUnit.Framework;
    using TestStack.White;
    using TestStack.White.Factory;
    using TestStack.White.UIItems;
    using TestStack.White.UIItems.Finders;
    using TestStack.White.UIItems.ListBoxItems;
    using TestStack.White.UIItems.WindowItems;

    /// <summary>
    /// UI unit tests
    /// </summary>
    [TestFixture]
    public class UIUnitTests : UnitTestsBase
    {
        /// <summary>
        /// Asserts that hiding a component if it's already installed during the install sequence hides the component.
        /// </summary>
        [Test]
        public void HideComponentIfInstalled_WithComponentAlreadyInstalledDuringInstallSequence_HidesComponent()
        {
            string dotNetInstallerExeFilePath = dotNetInstallerExeUtils.Executable;

            bool usingHtmlInstaller = dotNetInstallerExeFilePath.EndsWith("htmlInstaller.exe");

            // create configuration file
            ConfigFile configFile = new ConfigFile();

            // add a setup configuration
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);

            // add a component that is hidden if it's already installed
            ComponentCmd componentAlreadyInstalled = new ComponentCmd();
            componentAlreadyInstalled.hide_component_if_installed = true;
            setupConfiguration.Children.Add(componentAlreadyInstalled);

            // make the component appear to be already installed
            InstalledCheckFile existsCheck = new InstalledCheckFile();
            existsCheck.filename = dotNetInstallerExeUtils.Executable;
            existsCheck.comparison = installcheckfile_comparison.exists;
            componentAlreadyInstalled.Children.Add(existsCheck);

            // add another component that is not already installed
            ComponentCmd componentNotInstalled = new ComponentCmd();
            setupConfiguration.Children.Add(componentNotInstalled);

            // save the configuration file
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            configFile.SaveAs(configFilename);

            // execute dotNetInstaller
            string arguments = string.Format("/ConfigFile {0}", configFilename);
            using (Application dotNetInstaller = Application.Launch(new ProcessStartInfo(dotNetInstallerExeFilePath, arguments)))
            {
                // get the main install window
                Window mainWindow = dotNetInstaller.GetWindow("APPLICATION_NAME Installer", InitializeOption.NoCache);

                if (usingHtmlInstaller)
                {
                    // get all the checkboxes in the window
                    IUIItem[] checkBoxes = mainWindow.GetMultiple(SearchCriteria.ByControlType(System.Windows.Automation.ControlType.CheckBox));

                    // assert that there's only one checkbox
                    Assert.AreEqual(1, checkBoxes.Length);
                    Assert.AreEqual("command1 ", checkBoxes[0].Name);
                }
                else
                {
                    // using dotNetInstaller
                    // get the components list box
                    ListBox componentsList = mainWindow.Get<ListBox>();

                    // assert that only one component is in the list
                    Assert.AreEqual(1, componentsList.Items.Count);
                    Assert.AreEqual("command1 ", componentsList.Items[0].Name);
                }
            }
        }
    }
}
