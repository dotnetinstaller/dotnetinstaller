using System;

namespace InstallerLib
{
    public class DocumentationSection : Attribute
    {
        private string m_content;
        private string m_title;

        public DocumentationSection(string title, string content)
        {
            m_title = title;
            m_content = content;
        }

        public string Content
        {
            get
            {
                return m_content;
            }
        }

        public string Title
        {
            get
            {
                return m_title;
            }
        }

        public string GetXml()
        {
            return string.Format("<section address=\"{0}\">" +
                "<title>{1}</title>" +
                 "<content>" +
                  "{2}" +
                 "</content>" +
                "</section>", Guid.NewGuid().ToString(), Title, Content);
        }

    }
}
