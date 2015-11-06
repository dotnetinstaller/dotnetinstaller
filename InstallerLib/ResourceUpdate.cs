using System;
using System.Runtime.InteropServices;
using Vestris.ResourceLib;
using System.IO;
using System.ComponentModel;

namespace InstallerLib
{
    /// <summary>
    /// Kernel32 interop for resource functions
    /// </summary>
    public abstract class ResourceUpdate
    {
        /// <summary>
        /// Returns a handle to either a language-neutral portable executable file (LN file) or a 
        /// language-specific resource file (.mui file) that can be used by the UpdateResource function 
        /// to add, delete, or replace resources in a binary module.
        /// </summary>
        /// <param name="pFileName">Pointer to a null-terminated string that specifies the binary file in which to update resources.</param>
        /// <param name="bDeleteExistingResources">Specifies whether to delete the pFileName parameter's existing resources.</param>
        /// <returns>If the function succeeds, the return value is a handle that can be used by the UpdateResource and EndUpdateResource functions.</returns>
        [DllImport("kernel32.dll", EntryPoint = "BeginUpdateResourceW", SetLastError = true, CharSet = CharSet.Unicode, ExactSpelling = true, CallingConvention = CallingConvention.StdCall)]
        internal static extern IntPtr BeginUpdateResource(string pFileName, bool bDeleteExistingResources);

        /// <summary>
        /// Adds, deletes, or replaces a resource in a portable executable (PE) file. 
        /// There are some restrictions on resource updates in files that contain Resource Configuration (RC Config) data: 
        /// language-neutral (LN) files and language-specific resource (.mui) files.
        /// </summary>
        /// <param name="hUpdate">A module handle returned by the BeginUpdateResource function, referencing the file to be updated.</param>
        /// <param name="lpType">Pointer to a null-terminated string specifying the resource type to be updated.</param>
        /// <param name="lpName">Pointer to a null-terminated string specifying the name of the resource to be updated.</param>
        /// <param name="wLanguage">Specifies the language identifier of the resource to be updated.</param>
        /// <param name="lpData">Pointer to the resource data to be inserted into the file indicated by hUpdate.</param>
        /// <param name="cbData">Specifies the size, in bytes, of the resource data at lpData.</param>
        /// <returns>Returns TRUE if successful or FALSE otherwise.</returns>
        [DllImport("kernel32.dll", EntryPoint = "UpdateResourceW", SetLastError = true, CharSet = CharSet.Unicode, ExactSpelling = true, CallingConvention = CallingConvention.StdCall)]
        internal static extern bool UpdateResource(IntPtr hUpdate, IntPtr lpType, IntPtr lpName, UInt16 wLanguage, byte[] lpData, UInt32 cbData);

        /// <summary>
        /// Commits or discards changes made prior to a call to UpdateResource.
        /// </summary>
        /// <param name="hUpdate">A module handle returned by the BeginUpdateResource function, and used by UpdateResource, referencing the file to be updated.</param>
        /// <param name="fDiscard">Specifies whether to write the resource updates to the file. If this parameter is TRUE, no changes are made. If it is FALSE, the changes are made: the resource updates will take effect.</param>
        /// <returns>Returns TRUE if the function succeeds; FALSE otherwise.</returns>
        [DllImport("kernel32.dll", EntryPoint = "EndUpdateResourceW", SetLastError = true, CharSet = CharSet.Unicode, ExactSpelling = true, CallingConvention = CallingConvention.StdCall)]
        internal static extern bool EndUpdateResource(IntPtr hUpdate, bool fDiscard);

        internal static void WriteFile(
            IntPtr h,
            ResourceId resourceType,
            ResourceId resourceName,
            UInt16 resourceLanguage,
            string input)
        {
            using (FileStream binaryStream = new FileStream(input, FileMode.Open, FileAccess.Read))
            {
                byte[] data = null;

                try
                {
                    data = new byte[binaryStream.Length];
                    binaryStream.Read(data, 0, (int)binaryStream.Length);
                }
                catch (Exception ex)
                {
                    throw new Exception(string.Format("Error reading {0}: {1}", input, ex.Message),
                        ex);
                }

                Write(h, resourceType, resourceName, resourceLanguage, data);
            }
        }

        internal static void Write(
            IntPtr h,
            ResourceId resourceType,
            ResourceId resourceName,
            UInt16 resourceLanguage,
            byte[] buffer)
        {
            try
            {
                if (!UpdateResource(h, resourceType.Id, resourceName.Id, resourceLanguage, buffer, (uint)buffer.Length))
                    throw new Win32Exception(Marshal.GetLastWin32Error());
            }
            catch (Exception ex)
            {
                throw new Exception(string.Format("Error writing {0}: {1}", resourceName, ex.Message),
                    ex);
            }
        }
    }
}
