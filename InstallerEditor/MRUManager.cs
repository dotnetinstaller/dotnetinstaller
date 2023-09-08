using System;

using System.Windows.Forms;
using System.Collections.Generic;
using Microsoft.Win32;
using System.IO;
using System.Text;
using System.Runtime.InteropServices;

// MRI list manager.
//
// Written by: Alex Farber
//
// alexm@cmt.co.il

/*******************************************************************************

Using:

1) Add menu item Recent Files (or any name you want) to main application menu.
   This item is used by MRUManager as popup menu for MRU list.

2) Implement IMRUClient inteface in the form class:

public class Form1 : System.Windows.Forms.Form, IMRUClient
{
     public void OpenMRUFile(string fileName)
     {
         // open file here
     }
 
     // ...    
}

3) Add MRUManager member to the form class and initialize it:

     private MRUManager mruManager;

     private void Form1_Load(object sender, System.EventArgs e)
     {
         mruManager = new MRUManager();
         mruManager.Initialize(
             this,                              // owner form
             mnuFileMRU,                        // Recent Files menu item
             "Software\\MyCompany\\MyProgram"); // Registry path to keep MRU list

        // Optional. Call these functions to change default values:

        mruManager.CurrentDir = ".....";           // default is current directory
        mruManager.MaxMRULength = ...;             // default is 10
        mruMamager.MaxDisplayNameLength = ...;     // default is 40
     }

     NOTES:
     - If Registry path is, for example, "Software\MyCompany\MyProgram",
       MRU list is kept in
       HKEY_CURRENT_USER\Software\MyCompany\MyProgram\MRU Registry entry.

     - CurrentDir is used to show file names in the menu. If file is in
       this directory, only file name is shown.

4) Call MRUManager Add and Remove functions when necessary:

       mruManager.Add(fileName);          // when file is successfully opened

       mruManager.Remove(fileName);       // when Open File operation failed

*******************************************************************************/

// Implementation details:
//
// MRUManager loads MRU list from Registry in Initialize function.
// List is saved in Registry when owner form is closed.
//
// MRU list in the menu is updated when parent menu is poped-up.
//
// Owner form OpenMRUFile function is called when user selects file
// from MRU list.


/// <summary>
/// Interface which should be implemented by owner form
/// to use MRUManager.
/// </summary>
public interface IMRUClient
{
    void OpenMRUFile(string fileName);
}

/// <summary>
/// MRU manager - manages Most Recently Used Files list
/// for Windows Form application.
/// </summary>
public class MRUManager : IEnumerable<String>
{
    #region Members

    private Form ownerForm;                 // owner form

    private MenuItem menuItemMRU;           // Recent Files menu item
    private MenuItem menuItemParent;        // Recent Files menu item parent

    private string registryPath;            // Registry path to keep MRU list

    private int maxNumberOfFiles = 10;      // maximum number of files in MRU list

    private int maxDisplayLength = 40;      // maximum length of file name for display

    private string currentDirectory;        // current directory

    private List<String> mruList;              // MRU list (file names)

    private const string regEntryName = "file";  // entry name to keep MRU (file0, file1...)


    #endregion

    #region Windows API

    // BOOL PathCompactPathEx(          
    //    LPTSTR pszOut,
    //    LPCTSTR pszSrc,
    //    UINT cchMax,
    //    DWORD dwFlags
    //    );

    [DllImport("shlwapi.dll", CharSet = CharSet.Auto)]
    private static extern bool PathCompactPathEx(
        StringBuilder pszOut,
        string pszPath,
        int cchMax,
        int reserved);

    #endregion

    #region Constructor

    public MRUManager()
    {
        mruList = new List<string>();
    }

    #endregion

    #region Public Properties

    /// <summary>
    /// Maximum length of displayed file name in menu (default is 40).
    /// 
    /// Set this property to change default value (optional).
    /// </summary>
    public int MaxDisplayNameLength
    {
        set
        {
            maxDisplayLength = value;

            if (maxDisplayLength < 10)
                maxDisplayLength = 10;
        }

        get
        {
            return maxDisplayLength;
        }
    }

    /// <summary>
    /// Maximum length of MRU list (default is 10).
    /// 
    /// Set this property to change default value (optional).
    /// </summary>
    public int MaxMRULength
    {
        set
        {
            maxNumberOfFiles = value;

            if (maxNumberOfFiles < 1)
                maxNumberOfFiles = 1;

            if (mruList.Count > maxNumberOfFiles)
                mruList.RemoveRange(maxNumberOfFiles - 1, mruList.Count - maxNumberOfFiles);
        }

        get
        {
            return maxNumberOfFiles;
        }
    }

    /// <summary>
    /// Set current directory.
    /// 
    /// Default value is program current directory which is set when
    /// Initialize function is called.
    /// 
    /// Set this property to change default value (optional)
    /// after call to Initialize.
    /// </summary>
    public string CurrentDir
    {
        set
        {
            currentDirectory = value;
        }

        get
        {
            return currentDirectory;
        }
    }

    #endregion

    #region Public Functions

    /// <summary>
    /// Initialization. Call this function in form Load handler.
    /// </summary>
    /// <param name="owner">Owner form</param>
    /// <param name="mruItem">Recent Files menu item</param>
    /// <param name="regPath">Registry Path to keep MRU list</param>
    public void Initialize(Form owner, MenuItem mruItem, string regPath)
    {
        // keep reference to owner form
        ownerForm = owner;

        // check if owner form implements IMRUClient interface
        if (!(owner is IMRUClient))
        {
            throw new Exception(
                "MRUManager: Owner form doesn't implement IMRUClient interface");
        }

        // keep reference to MRU menu item
        menuItemMRU = mruItem;
        if (menuItemMRU != null)
        {
            try
            {
                menuItemParent = (MenuItem)menuItemMRU.Parent;
            }
            catch
            {

            }
        }

        // keep Registry path adding MRU key to it
        registryPath = regPath;

        // keep current directory in the time of initialization
        currentDirectory = Directory.GetCurrentDirectory();

        // subscribe to MRU parent Popup event
        if (menuItemParent != null)
        {
            menuItemParent.Popup += new EventHandler(this.OnMRUParentPopup);
        }

        // subscribe to owner form Closing event
        ownerForm.Closing += new System.ComponentModel.CancelEventHandler(OnOwnerClosing);

        // load MRU list from Registry
        LoadMRU();
    }

    /// <summary>
    /// Add file name to MRU list.
    /// Call this function when file is opened successfully.
    /// If file already exists in the list, it is moved to the first place.
    /// </summary>
    /// <param name="file">File Name</param>
    public void Add(string file)
    {
        Remove(file);

        // if array has maximum length, remove last element
        if (mruList.Count == maxNumberOfFiles)
            mruList.RemoveAt(maxNumberOfFiles - 1);

        // add new file name to the start of array
        mruList.Insert(0, file);
    }

    public void Clear()
    {
        mruList.Clear();
    }

    public void AddRange(IEnumerable<String> files)
    {
        foreach (String file in files)
        {
            Add(file);
        }
    }

    /// <summary>
    /// Remove file name from MRU list.
    /// Call this function when File - Open operation failed.
    /// </summary>
    /// <param name="file">File Name</param>
    public void Remove(string file)
    {
        int i = 0;

        IEnumerator<String> myEnumerator = mruList.GetEnumerator();

        while (myEnumerator.MoveNext())
        {
            if (myEnumerator.Current == file)
            {
                mruList.RemoveAt(i);
                return;
            }

            i++;
        }
    }

    #endregion

    #region Event Handlers

    /// <summary>
    /// Update MRU list when MRU menu item parent is opened
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    private void OnMRUParentPopup(object sender, EventArgs e)
    {
        // remove all childs
        if (menuItemMRU.IsParent)
        {
            menuItemMRU.MenuItems.Clear();
        }

        // Disable menu item if MRU list is empty
        if (mruList.Count == 0)
        {
            menuItemMRU.Enabled = false;
            return;
        }

        // enable menu item and add child items
        menuItemMRU.Enabled = true;

        MenuItem item;

        IEnumerator<String> myEnumerator = mruList.GetEnumerator();

        while (myEnumerator.MoveNext())
        {
            item = new MenuItem(GetDisplayName((string)myEnumerator.Current));

            // subscribe to item's Click event
            item.Click += new EventHandler(this.OnMRUClicked);

            menuItemMRU.MenuItems.Add(item);
        }
    }

    /// <summary>
    /// MRU menu item is clicked - call owner's OpenMRUFile function
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    private void OnMRUClicked(object sender, EventArgs e)
    {
        string s;

        // cast sender object to MenuItem
        MenuItem item = (MenuItem)sender;

        if (item != null)
        {
            // Get file name from list using item index
            s = mruList[item.Index];

            // call owner's OpenMRUFile function
            if (s.Length > 0)
            {
                ((IMRUClient)ownerForm).OpenMRUFile(s);
            }
        }
    }

    /// <summary>
    /// Save MRU list in Registry when owner form is closing
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    private void OnOwnerClosing(object sender, System.ComponentModel.CancelEventArgs e)
    {
        int i, n;

        RegistryKey key = Registry.CurrentUser.CreateSubKey(registryPath);

        if (key != null)
        {
            n = mruList.Count;

            for (i = 0; i < maxNumberOfFiles; i++)
            {
                key.DeleteValue(regEntryName + i.ToString(), false);
            }

            for (i = 0; i < n; i++)
            {
                key.SetValue(regEntryName + i.ToString(), mruList[i]);
            }
        }
    }


    #endregion

    #region Private Functions

    /// <summary>
    /// Load MRU list from Registry.
    /// Called from Initialize.
    /// </summary>
    private void LoadMRU()
    {
        string sKey, s;

        mruList.Clear();

        RegistryKey key = Registry.CurrentUser.OpenSubKey(registryPath);

        if (key != null)
        {
            for (int i = 0; i < maxNumberOfFiles; i++)
            {
                sKey = regEntryName + i.ToString();

                s = (string)key.GetValue(sKey, "");

                if (s.Length == 0)
                    break;

                mruList.Add(s);
            }
        }
    }

    /// <summary>
    /// Get display file name from full name.
    /// </summary>
    /// <param name="fullName">Full file name</param>
    /// <returns>Short display name</returns>
    private string GetDisplayName(string fullName)
    {
        // if file is in current directory, show only file name
        FileInfo fileInfo = new FileInfo(fullName);

        if (fileInfo.DirectoryName == currentDirectory)
            return GetShortDisplayName(fileInfo.Name, maxDisplayLength);

        return GetShortDisplayName(fullName, maxDisplayLength);
    }

    /// <summary>
    /// Truncate a path to fit within a certain number of characters 
    /// by replacing path components with ellipses.
    /// 
    /// This solution is provided by CodeProject and GotDotNet C# expert
    /// Richard Deeming.
    /// 
    /// </summary>
    /// <param name="longName">Long file name</param>
    /// <param name="maxLen">Maximum length</param>
    /// <returns>Truncated file name</returns>
    private string GetShortDisplayName(string longName, int maxLen)
    {
        StringBuilder pszOut = new StringBuilder(maxLen + maxLen + 2);  // for safety

        if (PathCompactPathEx(pszOut, longName, maxLen, 0))
        {
            return pszOut.ToString();
        }
        else
        {
            return longName;
        }
    }

    #endregion


    #region IEnumerable<string> Members

    public IEnumerator<string> GetEnumerator()
    {
        return mruList.GetEnumerator();
    }

    #endregion

    #region IEnumerable Members

    System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
    {
        return mruList.GetEnumerator();
    }

    #endregion
}
