using System.Xml;
using NUnit.Framework;
using InstallerLib;

namespace InstallerLibUnitTests
{
    [TestFixture]
    public class XmlFilterUnitTests
    {
        class TestProcessorArchitectureFilter_TestData
        {
            public string Filter;
            public int ExpectedConfigs;
            public int ExpectedComponents;

            public TestProcessorArchitectureFilter_TestData(
                string filter, int expectedConfigs, int expectedComponents)
            {
                Filter = filter;
                ExpectedConfigs = expectedConfigs;
                ExpectedComponents = expectedComponents;
            }
        }

        [Test]
        public void TestProcessorArchitectureFilter()
        {
            // configurations
            SetupConfiguration nofilterConfiguration = new SetupConfiguration();
            SetupConfiguration x86Configuration = new SetupConfiguration();
            x86Configuration.processor_architecture_filter = "x86";
            SetupConfiguration x64Configuration = new SetupConfiguration();
            x64Configuration.processor_architecture_filter = "x64";
            SetupConfiguration mipsConfiguration = new SetupConfiguration();
            mipsConfiguration.processor_architecture_filter = "mips";
            // components
            ComponentCmd nofilterComponent = new ComponentCmd();
            ComponentCmd x86Component = new ComponentCmd();
            x86Component.processor_architecture_filter = "x86";
            ComponentCmd x64Component = new ComponentCmd();
            x64Component.processor_architecture_filter = "x64";
            ComponentCmd mipsComponent = new ComponentCmd();
            mipsComponent.processor_architecture_filter = "mips";
            // make a tree
            nofilterConfiguration.Children.Add(nofilterComponent);
            nofilterConfiguration.Children.Add(x86Component);
            nofilterConfiguration.Children.Add(x64Component);
            nofilterConfiguration.Children.Add(mipsComponent);
            x86Configuration.Children.Add(nofilterComponent);
            x86Configuration.Children.Add(x86Component);
            x86Configuration.Children.Add(x64Component);
            x86Configuration.Children.Add(mipsComponent);
            x64Configuration.Children.Add(nofilterComponent);
            x64Configuration.Children.Add(x86Component);
            x64Configuration.Children.Add(x64Component);
            x64Configuration.Children.Add(mipsComponent);
            mipsConfiguration.Children.Add(nofilterComponent);
            mipsConfiguration.Children.Add(x86Component);
            mipsConfiguration.Children.Add(x64Component);
            mipsConfiguration.Children.Add(mipsComponent);
            // configfile
            ConfigFile configFile = new ConfigFile();
            configFile.Children.Add(nofilterConfiguration);
            configFile.Children.Add(x86Configuration);
            configFile.Children.Add(x64Configuration);
            configFile.Children.Add(mipsConfiguration);

            // Console.WriteLine("Total : {0}x{1}", configFile.ConfigurationCount, configFile.ComponentCount);

            TestProcessorArchitectureFilter_TestData[] testdata = 
            {
                new TestProcessorArchitectureFilter_TestData("", 4, 16),
                new TestProcessorArchitectureFilter_TestData("x86", 2, 4),
                new TestProcessorArchitectureFilter_TestData("x64", 2, 4),
                new TestProcessorArchitectureFilter_TestData("mips", 2, 4),
                new TestProcessorArchitectureFilter_TestData("sparc", 1, 1),
                new TestProcessorArchitectureFilter_TestData("x86,x64", 3, 9),
                new TestProcessorArchitectureFilter_TestData("alpha,x64", 2, 4),
            };

            foreach (TestProcessorArchitectureFilter_TestData test in testdata)
            {
                ProcessorArchitectureFilter filter = new ProcessorArchitectureFilter(test.Filter);
                XmlDocument filteredXml = configFile.GetXml(filter);
                ConfigFile filteredConfigFile = new ConfigFile();
                filteredConfigFile.LoadXml(filteredXml);
                //Console.WriteLine("{0} - {1}x{2}", test.Filter,
                //    filteredConfigFile.ConfigurationCount, filteredConfigFile.ComponentCount);
                Assert.AreEqual(test.ExpectedConfigs, filteredConfigFile.ConfigurationCount);
                Assert.AreEqual(test.ExpectedComponents, filteredConfigFile.ComponentCount);
            }
        }
    }
}
