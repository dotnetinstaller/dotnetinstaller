using NUnit.Framework;
using System.Threading;
using System.Globalization;

namespace InstallerEditorUnitTests
{
    public class EnUsUnitTests
    {
        CultureInfo mUICulture;
        CultureInfo mCulture;

        [TestFixtureSetUp]
        public virtual void SetUp()
        {
            mUICulture = Thread.CurrentThread.CurrentUICulture;
            mCulture = Thread.CurrentThread.CurrentCulture;
            Thread.CurrentThread.CurrentUICulture = CultureInfo.CreateSpecificCulture("en-US");
            Thread.CurrentThread.CurrentCulture = CultureInfo.CreateSpecificCulture("en-US");
        }

        [TestFixtureTearDown]
        public virtual void TearDown()
        {
            Thread.CurrentThread.CurrentUICulture = mUICulture;
            Thread.CurrentThread.CurrentCulture = mCulture;
        }
    }
}
