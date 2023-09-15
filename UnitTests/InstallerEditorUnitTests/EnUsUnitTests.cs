using NUnit.Framework;
using System.Threading;
using System.Globalization;
using System;
using TestStack.White.UIItems.WindowItems;
using TestStack.White.UIItems;
using System.IO;
using TestStack.White;
using System.Linq;

namespace InstallerEditorUnitTests
{
    public class EnUsUnitTests
    {
        private CultureInfo mUICulture;
        private CultureInfo mCulture;
        private readonly string dotNetInstallerLogFilePath = Path.Combine(Path.GetTempPath(), "dotNetInstallerLog.txt");
        private readonly string installerLinkerLogFilePath = Path.Combine(Path.GetTempPath(), "InstallerLinker.txt");

        [OneTimeSetUp]
        public virtual void OneTimeSetUp()
        {
            mUICulture = Thread.CurrentThread.CurrentUICulture;
            mCulture = Thread.CurrentThread.CurrentCulture;
            Thread.CurrentThread.CurrentUICulture = CultureInfo.CreateSpecificCulture("en-US");
            Thread.CurrentThread.CurrentCulture = CultureInfo.CreateSpecificCulture("en-US");
        }

        [SetUp]
        public void SetUp()
        {
            if (File.Exists(dotNetInstallerLogFilePath))
            {
                File.Delete(dotNetInstallerLogFilePath);
            }

            if (File.Exists(installerLinkerLogFilePath))
            {
                File.Delete(installerLinkerLogFilePath);
            }
        }

        [TearDown]
        public void TearDown()
        {
            if (File.Exists(dotNetInstallerLogFilePath))
            {
                TestContext.AddTestAttachment(dotNetInstallerLogFilePath);
                File.Delete(dotNetInstallerLogFilePath);
            }

            if (File.Exists(installerLinkerLogFilePath))
            {
                TestContext.AddTestAttachment(installerLinkerLogFilePath);
                File.Delete(installerLinkerLogFilePath);
            }
        }

        [OneTimeTearDown]
        public virtual void OneTimeTearDown()
        {
            Thread.CurrentThread.CurrentUICulture = mUICulture;
            Thread.CurrentThread.CurrentCulture = mCulture;
        }

        protected static bool WaitForFileToExist(string filePath)
        {
            return WaitForFileToExist(filePath, TimeSpan.FromSeconds(30));
        }

        protected static bool WaitForFileToExist(string filePath, TimeSpan timeout)
        {
            DateTime startTime = DateTime.Now;

            while (DateTime.Now - startTime < timeout)
            {
                if (File.Exists(filePath))
                {
                    return true;
                }

                Thread.Sleep(100);
            }

            return false;
        }

        protected static void GetErrorMessageFromErrorDialogOnFailure(Window window, Action action)
        {
            try
            {
                action();
            }
            catch
            {
                try
                {
                    // try to get error message from Error dialog
                    Window errorDialog = window.ModalWindows().SingleOrDefault(x => x.Id == "ErrorDialog");
                    if (errorDialog == null)
                    {
                        Console.WriteLine("Could not find error dialog.");
                    }
                    else
                    {
                        Label errorMessageLabel = errorDialog.Get<Label>("lblErrorMessage");
                        string errorMessage = errorMessageLabel.Text;

                        // TODO: get and include exception details
                        Console.WriteLine($"Error dialog message: {errorMessage}");
                    }
                }
                catch (Exception ex2)
                {
                    // do not swallow previous exception
                    Console.WriteLine(ex2);
                }

                throw;
            }
        }

        protected static void ScreenshotOnFailure(Action action)
        {
            try
            {
                action();
            }
            catch
            {
                try
                {
                    TakeScreenshot();
                }
                catch (Exception ex2)
                {
                    // do not swallow previous exception
                    Console.WriteLine(ex2);
                }

                throw;
            }
        }

        protected static void TakeScreenshot()
        {
            TakeScreenshotWithSuffix(string.Empty);
        }

        protected static void TakeScreenshot(string id)
        {
            TakeScreenshotWithSuffix($"-{id}");
        }

        private static void TakeScreenshotWithSuffix(string suffix)
        {
            string pngFilePath = Path.Combine(
                TestContext.CurrentContext.WorkDirectory,
                $"{TestContext.CurrentContext.Test.FullName}-{TestContext.CurrentContext.Test.ID}{suffix}.png");
            Desktop.TakeScreenshot(pngFilePath, System.Drawing.Imaging.ImageFormat.Png);
            Console.WriteLine($"Saved screenshot to \"{pngFilePath}\".");
            TestContext.AddTestAttachment(pngFilePath);
        }
    }
}
