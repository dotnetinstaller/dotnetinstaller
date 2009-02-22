using System;
using System.Xml;
using System.ComponentModel;

namespace InstallerLib
{
	/// <summary>
	/// Gestione del tag downloaddialog
	/// </summary>
	public class DownloadDialog : IXmlClass
	{
		public DownloadDialog():this("COMPONENT_NAME")
		{
		}
		public DownloadDialog(string p_ComponentName)
		{
			Template.Template_downloaddialog tpl = Template.CurrentTemplate.downloaddialog(p_ComponentName);

			m_buttoncancel_caption = tpl.buttoncancel_caption;
			m_buttonstart_caption = tpl.buttonstart_caption;
			m_dialog_caption = tpl.dialog_caption;
			m_dialog_message = tpl.dialog_message;
			m_dialog_message_downloading = tpl.dialog_message_downloading;

//			if (LanguageUI.Language == SupportedLanguage.Italian)
//			{
//				m_buttoncancel_caption = "Annulla";
//				m_buttonstart_caption = "Avanti";
//				m_dialog_caption = p_ComponentName + " - Download Componenti";
//				m_dialog_message = "Premi 'Avanti' per scaricare i componenti necessari all'installazione di " + p_ComponentName + ".";
//				m_dialog_message_downloading = "Download in corso. Attendere...";
//			}
//			else //english
//			{
//				m_buttoncancel_caption = "Cancel";
//				m_buttonstart_caption = "Start";
//				m_dialog_caption = p_ComponentName + " - Download Components";
//				m_dialog_message = "Press 'Start' to download the required components for installing " + p_ComponentName + ".";
//				m_dialog_message_downloading = "Download in progress. Wait...";
//			}
		}

		#region Attributes
		private string m_dialog_caption;
		[Description("The caption of the download dialog. (REQUIRED)")]
		public string dialog_caption
		{
			get{return m_dialog_caption;}
			set{m_dialog_caption = value;}
		}

		private string m_dialog_message;
		[Description("The initial message that appears in the download dialog before the user press the 'Start' button. (REQUIRED)")]
		public string dialog_message
		{
			get{return m_dialog_message;}
			set{m_dialog_message = value;}
		}

		private bool m_autostartdownload;
		[Description("True to start the download without user interaction, False to let the user press the 'Start' button. (REQUIRED)")]
		public bool autostartdownload
		{
			get{return m_autostartdownload;}
			set{m_autostartdownload = value;}
		}

		private string m_dialog_message_downloading;
		[Description("The message that appears in the download dialog when the download process start. (REQUIRED)")]
		public string dialog_message_downloading
		{
			get{return m_dialog_message_downloading;}
			set{m_dialog_message_downloading = value;}
		}

		private string m_buttonstart_caption;
		[Description("Caption of the 'Start' button. (REQUIRED)")]
		public string buttonstart_caption
		{
			get{return m_buttonstart_caption;}
			set{m_buttonstart_caption = value;}
		}

		private string m_buttoncancel_caption;
		[Description("Caption of the 'Cancel' button. (REQUIRED)")]
		public string buttoncancel_caption
		{
			get{return m_buttoncancel_caption;}
			set{m_buttoncancel_caption = value;}
		}
		#endregion

		#region IXmlClass Members

		public void ToXml(XmlWriter p_Writer)
		{
			p_Writer.WriteStartElement("downloaddialog");

				OnXmlWriteTagDownloaddialog(new XmlWriterEventArgs(p_Writer));

				p_Writer.WriteStartElement("downloads");
				foreach (Download d in Downloads)
					d.ToXml(p_Writer);
				p_Writer.WriteEndElement();

			p_Writer.WriteEndElement();
		}

		public void FromXml(XmlElement p_Element)
		{
			OnXmlReadTagDownloaddialog(new XmlElementEventArgs(p_Element));

			XmlNode l_Node = p_Element.SelectSingleNode("downloads");
			if (l_Node!=null)
			{
				XmlNodeList l_List = l_Node.SelectNodes("download");
				foreach (XmlElement l in l_List)
				{
					Download d = new Download();
					d.FromXml(l);
					Downloads.Add(d);
				}
			}
		}
		#endregion


		protected virtual void OnXmlWriteTagDownloaddialog(XmlWriterEventArgs e)
		{
			e.XmlWriter.WriteAttributeString("dialog_caption",m_dialog_caption);
			e.XmlWriter.WriteAttributeString("dialog_message",m_dialog_message);
			e.XmlWriter.WriteAttributeString("dialog_message_downloading",m_dialog_message_downloading);
			e.XmlWriter.WriteAttributeString("autostartdownload",m_autostartdownload.ToString());
			e.XmlWriter.WriteAttributeString("buttonstart_caption",m_buttonstart_caption);
			e.XmlWriter.WriteAttributeString("buttoncancel_caption",m_buttoncancel_caption);
		}
		protected virtual void OnXmlReadTagDownloaddialog(XmlElementEventArgs e)
		{
			if (e.XmlElement.Attributes["autostartdownload"] != null &&
				e.XmlElement.Attributes["autostartdownload"].InnerText != null &&
				e.XmlElement.Attributes["autostartdownload"].InnerText.Length > 0)
				m_autostartdownload = bool.Parse(e.XmlElement.Attributes["autostartdownload"].InnerText);

			if (e.XmlElement.Attributes["buttoncancel_caption"] != null)
				m_buttoncancel_caption = e.XmlElement.Attributes["buttoncancel_caption"].InnerText;

			if (e.XmlElement.Attributes["buttonstart_caption"] != null)
				m_buttonstart_caption = e.XmlElement.Attributes["buttonstart_caption"].InnerText;

			if (e.XmlElement.Attributes["dialog_caption"] != null)
				m_dialog_caption = e.XmlElement.Attributes["dialog_caption"].InnerText;

			if (e.XmlElement.Attributes["dialog_message"] != null)
				m_dialog_message = e.XmlElement.Attributes["dialog_message"].InnerText;

			if (e.XmlElement.Attributes["dialog_message_downloading"] != null)
				m_dialog_message_downloading = e.XmlElement.Attributes["dialog_message_downloading"].InnerText;
		}

		private DownloadCollection m_Downloads = new DownloadCollection();
		[System.ComponentModel.Browsable(false)]
		public DownloadCollection Downloads
		{
			get{return m_Downloads;}
			set{m_Downloads = value;}
		}
	}
}
