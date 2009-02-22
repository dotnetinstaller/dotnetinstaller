using System;

namespace InstallerEditor
{
	/// <summary>
	/// Summary description for AppUtility.
	/// </summary>
	public class AppUtility
	{
		public static void ShowError(System.Windows.Forms.IWin32Window p_Owner, Exception err)
		{
			SourceLibrary.Windows.Forms.ErrorDialog.Show(p_Owner,err,"Installer Editor");
		}
	}
}
