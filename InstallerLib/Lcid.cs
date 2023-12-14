namespace InstallerLib
{
    /// <summary>
    /// Type of LCID
    /// </summary>
    public enum LcidType
    {
        UserExe, // System32\user.exe lcid
        System, // GetSystemDefaultLCID
        User, // GetUserDefaultLCID
        MuiSystem, // GetSystemDefaultUILanguage
        MuiUser, // GetUserDefaultUILanguage
    }
}
