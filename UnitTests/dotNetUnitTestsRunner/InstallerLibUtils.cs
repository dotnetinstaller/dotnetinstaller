using System;
using System.Web;
using System.IO;
using System.Reflection;
using NUnit.Framework;

namespace dotNetUnitTestsRunner
{
    public class InstallerLibUtils
    {
        private static string _location = null;

        public static string TemplatesLocation
        {
            get
            {
                string result = Path.Combine(Location, "templates");
                Assert.IsTrue(Directory.Exists(result));
                return result;
            }
        }

        public static string Location
        {
            get
            {
                if (string.IsNullOrEmpty(_location))
                {
                    // locate dotnetinstaller.exe
                    Uri uri = new Uri(Assembly.GetExecutingAssembly().CodeBase);
                    _location = Path.GetFullPath(Path.Combine(Path.GetDirectoryName(HttpUtility.UrlDecode(uri.AbsolutePath)),
                        @"..\..\..\..\..\InstallerLib\"));
                }
                return _location;
            }
        }
    }
}
