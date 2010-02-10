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
            GenericResource resource = new GenericResource(resourceType, resourceName, resourceLanguage);
            
            try
            {
                using (FileStream binaryStream = new FileStream(input, FileMode.Open, FileAccess.Read))
                {
                    resource.Data = new byte[binaryStream.Length];
                    binaryStream.Read(resource.Data, 0, (int)binaryStream.Length);
                }
            }
            catch (Exception ex)
            {
                throw new Exception(string.Format("Error reading {0}: {1}", input, ex.Message),
                    ex);
            }

            try
            {
                resource.SaveTo(output);
            }
            catch (Exception ex)
            {
                throw new Exception(string.Format("Error writing {0}: {1}", output, ex.Message),
                    ex);
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
            try
            {
                resource.SaveTo(output);
            }
            catch (Exception ex)
            {
                throw new Exception(string.Format("Error writing {0}: {1}", output, ex.Message),
                    ex);
            }
        }
    }
}
