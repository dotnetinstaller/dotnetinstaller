using System;
using System.Reflection;
using InstallerLib;
using System.Xml;
using System.IO;

namespace InstallerDocLib
{
    public class DocLibGenerator
    {
        private string m_path;

        public DocLibGenerator(string path)
        {
            m_path = path;
        }

        public void Generate()
        {
            Assembly lib = Assembly.GetAssembly(typeof(ConfigFile));
            Type[] types = lib.GetTypes();
            foreach (Type type in types)
            {
                if (typeof(XmlClass).IsAssignableFrom(type) && !type.IsAbstract)
                {
                    // Console.WriteLine("Processing {0}", type.Name);
                    GenerateType(type);
                }
            }
        }

        private void GenerateType(Type type)
        {
            ConceptualTopic topic = new ConceptualTopic(type);
            string filename = Path.Combine(m_path, type.Name + ".aml");
            Console.WriteLine(" {0}: {1}", type.Name, filename);
            XmlDocument doc = topic.GetXml();
            doc.Save(filename);
        }
    }
}
