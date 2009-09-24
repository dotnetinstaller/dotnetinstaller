using System;
using System.Runtime.InteropServices;
using Vestris.ResourceLib;
using System.IO;

namespace InstallerLib
{
    /// <summary>
    /// Kernel32 interop for resource functions
    /// </summary>
    public abstract class ResourceUpdate
    {
        internal static void WriteFile(
            string output,
            ResourceId resourceType,
            ResourceId resourceName,
            UInt16 resourceLanguage, 
            string input)
        {
            byte[] buffer;
            using (FileStream binaryStream = new FileStream(input, FileMode.Open, FileAccess.Read))
            {
                buffer = new byte[binaryStream.Length];
                binaryStream.Read(buffer, 0, (int)binaryStream.Length);
                binaryStream.Close();
            }

            Write(output, resourceType, resourceName, resourceLanguage, buffer);
        }

        internal static void Write(
            string output,
            ResourceId resourceType,
            ResourceId resourceName,
            UInt16 resourceLanguage,
            byte[] buffer)
        {
            GenericResource resource = new GenericResource(resourceType, resourceName, resourceLanguage);
            resource.Data = buffer;
            resource.SaveTo(output);
        }
    }
}
