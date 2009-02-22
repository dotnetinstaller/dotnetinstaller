using System;
using System.Runtime.InteropServices;

namespace InstallerLib
{
    public class ResourceUpdate
    {
        [DllImport("KERNEL32.DLL",
             EntryPoint = "BeginUpdateResourceW",
             SetLastError = true,
             CharSet = CharSet.Unicode,
             ExactSpelling = true,
             CallingConvention = CallingConvention.StdCall)]
        private static extern IntPtr BeginUpdateResource(
            string pFileName,             // executable file name
            bool bDeleteExistingResources  // deletion option
            );


        [DllImport("KERNEL32.DLL",
             EntryPoint = "UpdateResourceW",
             SetLastError = true,
             CharSet = CharSet.Unicode,
             ExactSpelling = true,
             CallingConvention = CallingConvention.StdCall)]
        private static extern bool UpdateResource(
            IntPtr hUpdate, // update-file handle
            string lpType, // resource type (l'API è molto strana perchè puo prendere ho una stringa o un intero, vedi MAKEINTRESOURCE)
            string lpName, // resource name
            UInt16 wLanguage, // language identifier
            byte[] lpData,  // resource data
            UInt32 cbData    // length of resource data
            );


        [DllImport("KERNEL32.DLL",
             EntryPoint = "EndUpdateResourceW",
             SetLastError = true,
             CharSet = CharSet.Unicode,
             ExactSpelling = true,
             CallingConvention = CallingConvention.StdCall)]
        private static extern bool EndUpdateResource(
            IntPtr hUpdate, // update-file handle
            bool fDiscard   // write option 
            );


        public ResourceUpdate()
        {
        }

        public static void UpdateResourceWithFile(string p_BinFileName, string p_ResourceName, string p_ResourceType, UInt16 p_ResourceLanguage, string p_UpdateSource)
        {
            byte[] l_bmpBuffer;
            using (System.IO.FileStream l_ImageStream = new System.IO.FileStream(p_UpdateSource, System.IO.FileMode.Open, System.IO.FileAccess.Read))
            {
                l_bmpBuffer = new byte[l_ImageStream.Length];
                l_ImageStream.Read(l_bmpBuffer, 0, (int)l_ImageStream.Length);
                l_ImageStream.Close();
            }

            UpdateResource(p_BinFileName, p_ResourceName, p_ResourceType, l_bmpBuffer, p_ResourceLanguage);
        }

        public static void UpdateResource(string p_BinFileName, string p_ResourceName, string p_ResourceType, byte[] p_Buffer, UInt16 p_ResourceLanguage)
        {
            // Open the file to which you want to add the dialog box resource. 
            IntPtr hUpdateRes = BeginUpdateResource(p_BinFileName, false);
            if (hUpdateRes == IntPtr.Zero)
                throw new ApplicationException("Could not open file for writing.");

            bool l_retVal;

            // Add the dialog box resource to the update list. 
            l_retVal = UpdateResource(hUpdateRes,       // update resource handle 
                p_ResourceType,                   //  resource type
                p_ResourceName,                  // resource name box name 
                p_ResourceLanguage,  // neutral language, equivalente a MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL)
                p_Buffer,                   // ptr to resource info 
                (UInt32)p_Buffer.Length); // size of resource info. 

            if (l_retVal == false)
                throw new ApplicationException("Could not add resource.");

            // Write changes to FOOT.EXE and then close it. 
            l_retVal = EndUpdateResource(hUpdateRes, false);
            if (l_retVal == false)
                throw new ApplicationException("Could not write changes to file.");
        }
    }
}
