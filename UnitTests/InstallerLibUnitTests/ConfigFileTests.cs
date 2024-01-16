using System;
using System.Collections.Generic;
using NUnit.Framework;
using InstallerLib;
using System.Reflection;
using System.Drawing;
using System.Xml;
using System.IO;

namespace InstallerLibUnitTests
{
    [TestFixture]
    public class ConfigFileTests
    {
        private Type[] GetNestedTypes(Type type)
        {
            List<Type> result = new List<Type>();
            Type[] alltypes = type.Assembly.GetTypes();
            foreach (Type atype in alltypes)
            {
                if (atype.IsSubclassOf(type))
                {
                    result.Add(atype);
                }
            }
            return result.ToArray();
        }

        private void GenerateChildren(XmlClass parent)
        {
            GenerateChildren(parent, 0);
        }

        private XmlClass GenerateClass(Type implementsType)
        {
            XmlClass xmlclazz = (XmlClass)Activator.CreateInstance(implementsType);
            PropertyInfo[] pis = implementsType.GetProperties();
            foreach (PropertyInfo pi in pis)
            {
                object[] das = pi.GetCustomAttributes(typeof(System.ComponentModel.DescriptionAttribute), true);
                if (das != null)
                {
                    foreach (System.ComponentModel.DescriptionAttribute da in das)
                    {
                        if (pi.CanWrite)
                        {
                            if (pi.PropertyType.Equals(typeof(bool)))
                                pi.SetValue(xmlclazz, !(bool)pi.GetValue(xmlclazz, null), null);
                            else if (pi.PropertyType.Equals(typeof(string)))
                                pi.SetValue(xmlclazz, Guid.NewGuid().ToString(), null);
                            else if (pi.PropertyType.Equals(typeof(Int32)))
                                pi.SetValue(xmlclazz, 42, null);
                            else if (pi.PropertyType.Equals(typeof(Guid)))
                                pi.SetValue(xmlclazz, Guid.NewGuid(), null);
                            else if (pi.PropertyType.Equals(typeof(Rectangle)))
                                pi.SetValue(xmlclazz, new Rectangle(1, 2, 3, 4), null);
                            else if (pi.PropertyType.Equals(typeof(installcheckregistry_comparison)))
                                pi.SetValue(xmlclazz, installcheckregistry_comparison.version_gt, null);
                            else if (pi.PropertyType.Equals(typeof(installcheckfile_comparison)))
                                pi.SetValue(xmlclazz, installcheckfile_comparison.version_gt, null);
                            else if (pi.PropertyType.Equals(typeof(installcheckdirectory_comparison)))
                                pi.SetValue(xmlclazz, installcheckdirectory_comparison.exists, null);
                            else if (pi.PropertyType.Equals(typeof(installcheckproduct_comparison)))
                                pi.SetValue(xmlclazz, installcheckproduct_comparison.version_gt, null);
                            else if (pi.PropertyType.Equals(typeof(installcheck_wowoption)))
                                pi.SetValue(xmlclazz, installcheck_wowoption.WOW64_64, null);
                            else if (pi.PropertyType.Equals(typeof(installcheck_rootkey)))
                                pi.SetValue(xmlclazz, installcheck_rootkey.HKEY_CURRENT_CONFIG, null);
                            else if (pi.PropertyType.Equals(typeof(installcheck_registrytype)))
                                pi.SetValue(xmlclazz, installcheck_registrytype.REG_MULTI_SZ, null);
                            else if (pi.PropertyType.Equals(typeof(InstalledCheckProductType)))
                                pi.SetValue(xmlclazz, InstalledCheckProductType.upgradecode, null);
                            else if (pi.PropertyType.Equals(typeof(InstalledCheckOperatorType)))
                                pi.SetValue(xmlclazz, InstalledCheckOperatorType.Or, null);
                            else if (pi.PropertyType.Equals(typeof(ControlCheckType)))
                                pi.SetValue(xmlclazz, ControlCheckType.display, null);
                            else if (pi.PropertyType.Equals(typeof(ResponseFileFormat)))
                                pi.SetValue(xmlclazz, ResponseFileFormat.none, null);
                            else if (pi.PropertyType.Equals(typeof(SetupConfiguration.DefaultButton)))
                                pi.SetValue(xmlclazz, SetupConfiguration.DefaultButton.skip, null);
                            else if (pi.PropertyType.Equals(typeof(InstallerLib.OperatingSystem)))
                                pi.SetValue(xmlclazz, InstallerLib.OperatingSystem.winServer2003, null);
                            else if (pi.PropertyType.Equals(typeof(InstallerLib.CommandExecutionMethod)))
                                pi.SetValue(xmlclazz, InstallerLib.CommandExecutionMethod.CreateProcess, null);
                            else
                            {
                                Assert.Fail(string.Format("Value change required for type: {0}", pi.PropertyType));
                            }
                        }
                    }
                }
            }
            return xmlclazz;
        }

        private void GenerateChildren(XmlClass parent, int level)
        {
            if (level >= 5)
                return;

            object[] childAttributes = parent.GetType().GetCustomAttributes(typeof(XmlChild), true);
            if (childAttributes != null)
            {
                foreach (object childAttribute in childAttributes)
                {
                    if (childAttribute is XmlNoChildren)
                        continue;

                    XmlChild xmlchild = (XmlChild)childAttribute;

                    if (level < 2)
                    {
                        Console.WriteLine("{0}{1}", new string(' ', level), xmlchild.Type.Name);
                    }
                    else
                    {
                        Console.Write(".");
                    }

                    List<Type> implementsTypes = new List<Type>();
                    implementsTypes.Add(xmlchild.Type);
                    implementsTypes.AddRange(GetNestedTypes(xmlchild.Type));

                    foreach (Type implementsType in implementsTypes)
                    {
                        if (implementsType.IsAbstract)
                            continue;

                        for (int i = 0; i < Math.Min(3, xmlchild.Max); i++)
                        {
                            XmlClass xmlclazz = GenerateClass(implementsType);
                            parent.Children.Add(xmlclazz);
                            GenerateChildren(xmlclazz, level + 1);
                        }
                    }
                }
            }
        }

        [Test]
        public void TestConfigReadWrite()
        {
            // generate a configuration with as many changed values as possible, write/read and compare
            // ensures that all fields are property read and written to/from configuration files
            string configFilenameOriginal = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            string configFilenameLoaded = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            // original file
            ConfigFile configFileOriginal = new ConfigFile();
            GenerateChildren(configFileOriginal);
            Console.WriteLine("Writing '{0}'", configFilenameOriginal);
            configFileOriginal.SaveAs(configFilenameOriginal);
            // loaded file
            ConfigFile configFileLoaded = new ConfigFile();
            configFileLoaded.Load(configFilenameOriginal);
            Console.WriteLine("Writing '{0}'", configFilenameLoaded);
            configFileLoaded.SaveAs(configFilenameLoaded);
            // compare 
            XmlDocument originalXml = new XmlDocument();
            originalXml.Load(configFilenameOriginal);
            XmlDocument loadedXml = new XmlDocument();
            loadedXml.Load(configFilenameLoaded);
            // compare contents
            Assert.AreEqual(originalXml.OuterXml, loadedXml.OuterXml);
            // delete files on success, otherwise keep for diff
            File.Delete(configFilenameOriginal);
            File.Delete(configFilenameLoaded);
        }

        [Test]
        public void TestLoadClear()
        {
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            ComponentCmd cmd = new ComponentCmd();
            setupConfiguration.Children.Add(cmd);
            setupConfiguration.Children.Add(cmd);
            configFile.Children.Add(setupConfiguration);
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            configFile.SaveAs(configFilename);
            int previousConfigurationCount = configFile.ConfigurationCount;
            XmlDocument xmlConfigFile = new XmlDocument();
            xmlConfigFile.Load(configFilename);
            configFile.LoadXml(xmlConfigFile);
            Assert.AreEqual(previousConfigurationCount, configFile.ConfigurationCount);
            File.Delete(configFilename);
        }
    }
}
