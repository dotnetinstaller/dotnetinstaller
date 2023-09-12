using NUnit.Framework;
using System.Threading;
using System.Globalization;
using System;
using TestStack.White.UIItems.WindowItems;
using TestStack.White.UIItems.Finders;
using TestStack.White.UIItems;
using System.IO;
using TestStack.White;

namespace InstallerEditorUnitTests
{
    public class EnUsUnitTests
    {
        CultureInfo mUICulture;
        CultureInfo mCulture;

        [OneTimeSetUp]
        public virtual void SetUp()
        {
            mUICulture = Thread.CurrentThread.CurrentUICulture;
            mCulture = Thread.CurrentThread.CurrentCulture;
            Thread.CurrentThread.CurrentUICulture = CultureInfo.CreateSpecificCulture("en-US");
            Thread.CurrentThread.CurrentCulture = CultureInfo.CreateSpecificCulture("en-US");
        }

        [OneTimeTearDown]
        public virtual void TearDown()
        {
            Thread.CurrentThread.CurrentUICulture = mUICulture;
            Thread.CurrentThread.CurrentCulture = mCulture;
        }

        protected static bool FileExistsWithin5Seconds(string filePath)
        {
            DateTime startTime = DateTime.Now;
            TimeSpan timeout = TimeSpan.FromSeconds(5);

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
                    Window errorDialog = window.ModalWindow(SearchCriteria.ByAutomationId("ErrorDialog"));
                    Label errorMessageLabel = errorDialog.Get<Label>("lblErrorMessage");
                    string errorMessage = errorMessageLabel.Text;

                    // TODO: get and include exception details
                    Console.WriteLine(errorMessage);
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
                    // take a screenshot
                    string pngFilePath = Path.Combine(TestContext.CurrentContext.WorkDirectory, $"{TestContext.CurrentContext.Test.FullName}-{TestContext.CurrentContext.Test.ID}.png");
                    Desktop.TakeScreenshot(pngFilePath, System.Drawing.Imaging.ImageFormat.Png);
                    Console.WriteLine($"Saved screenshot to \"{pngFilePath}\".");
                    TestContext.AddTestAttachment(pngFilePath);
                }
                catch (Exception ex2)
                {
                    // do not swallow previous exception
                    Console.WriteLine(ex2);
                }

                throw;
            }
        }
    }
}
