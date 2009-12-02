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
            using (FileStream binaryStream = new FileStream(input, FileMode.Open, FileAccess.Read))
            {
                GenericResource resource = new GenericResource(resourceType, resourceName, resourceLanguage);
                resource.Data = new byte[binaryStream.Length];
                binaryStream.Read(resource.Data, 0, (int) binaryStream.Length);
                binaryStream.Close();
                resource.SaveTo(output);
            }
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
