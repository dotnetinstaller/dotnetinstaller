using System;
using System.Xml;
using System.ComponentModel;
using System.ComponentModel.Design;

namespace InstallerLib
{
	/// <summary>
	/// Summary description for WebConfiguration.
	/// </summary>
	public class WebConfiguration : Configuration
	{
		public WebConfiguration():this("APPLICATION_NAME")
		{
		}

		public WebConfiguration(string p_ApplicationName):base("reference")
		{
			m_referencefile = "#TEMPPATH\\" + p_ApplicationName + "\\configuration.xml";
		}

		protected override void OnXmlWriteTagConfiguration(XmlWriterEventArgs e)
		{
			base.OnXmlWriteTagConfiguration (e);
			m_DownloadDialog.ToXml(e.XmlWriter);

			e.XmlWriter.WriteStartElement("configfile");
			e.XmlWriter.WriteAttributeString("filename",m_referencefile);
			e.XmlWriter.WriteEndElement();
		}
		protected override void OnXmlReadTagConfiguration(XmlElementEventArgs e)
		{
			base.OnXmlReadTagConfiguration (e);

			XmlElement l_downloaddialog = (XmlElement)e.XmlElement.SelectSingleNode("downloaddialog");
			if (l_downloaddialog!=null)
				m_DownloadDialog.FromXml(l_downloaddialog);


			XmlElement l_ConfigFile = (XmlElement)e.XmlElement.SelectSingleNode("configfile");
			if (l_ConfigFile != null)
			{
				if (l_ConfigFile.Attributes["filename"]!=null)
					m_referencefile = l_ConfigFile.Attributes["filename"].InnerText;
			}
		}

		private string m_referencefile; // tag: configfile/@filename;
		[Description("The configuration file where the application can find the configuration. Usually this is the destination directory of the downloaded component. Can contains path constant (see Help->Path Constant). (REQUIRED)")]
		public string referencefile
		{
			get{return m_referencefile;}
			set{m_referencefile = value;}
		}

		private DownloadDialog m_DownloadDialog = new DownloadDialog();
		[Browsable(false)]
		public DownloadDialog DownloadDialog
		{
			get{return m_DownloadDialog;}
			set{m_DownloadDialog = value;}
		}
	}
}
