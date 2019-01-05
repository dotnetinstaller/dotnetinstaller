// -------------------------------------------------------
// CabLib by ElmüSoft
// www.netcult.ch/elmue
// -------------------------------------------------------


#pragma once

#include <gcroot.h>
#include "Cabinet/Compress.hpp"

using namespace System;
using namespace System::IO;
using namespace System::Threading;
using namespace System::Collections;

namespace CabLib
{
    public ref class Compress
    {
    public:
        enum class eCompress : Int32
        {
            NONE  = Cabinet::CCompress::E_ComprNONE,  // store files in CAB without compression
            MSZIP = Cabinet::CCompress::E_ComprMSZIP, // MSZIP compression
            LZX   = Cabinet::CCompress::E_ComprLZX    // highest LZX compression
            // Quantum is not implemented in Cabinet.dll
        };

        ref struct kCurStatus
        {
            UInt32 u32_TypeStatus;          // statusFile or statusFolder or statusCabinet
            UInt32 u32_TotCompressedSize;   // Total bytes which have been written to CAB file
            UInt32 u32_TotUncompressedSize; // Total bytes which have been written to CAB file
            UInt32 cb1;                     // for details see: "Cabinet Doku.doc"
            UInt32 cb2;                     // for details see: "Cabinet Doku.doc"
            UInt32 u32_FolderPercent;       // valid for statusFolder: 0% =start of compression, 100% =ready

            ~kCurStatus() {}       // Destructor is required!
        };

        Compress();
        void AbortOperation();
        static void EnumFiles(ArrayList^ i_FileList, String^ s_Path, String^ s_Filter, bool b_Subfolders);

        void SetTempDirectory(String^ s_TempDir);
        void SetEncryptionKey(String^ s_Password);
        void SwitchCompression(eCompress e_Compress);
        void SetEncryptionKey(array<Byte>^ u8_Key);
        void CompressFileList(ArrayList^ i_FileList, String^ s_CabFile, bool b_UtcTime, bool b_EncodeUtf, Int32 s32_SplitSize);
        void CompressFolder  (String^ s_Folder, String^ s_CabFile, String^ s_Filter, bool b_UtcTime, bool b_EncodeUtf, Int32 s32_SplitSize);
        
        static String^ Sprintf(String^ s_Format, array<Object^>^ o_Values);
        
        delegate int delUpdateStatus(kCurStatus^ k_CurStatus);
        delegate int delFilePlaced(String^ s_File, Int32 s32_FileSize, bool bContinuation);

        // With this event you can display the progress of compression in your GUI
        event delUpdateStatus^ evUpdateStatus;
        // With this event you can display in your GUI the file which was added to the CAB
        event delFilePlaced^   evFilePlaced;

    private:
        static void    RecursiveEnumFiles(ArrayList^ i_FileList, String^ s_Path, String^ s_Filter, bool b_Subfolders);
        static String^ TerminatePath(String^ s_Path);

        Cabinet::CCompress* mi_Compress;
        eCompress           me_Compress;
        array<Byte>^        mu8_Key;
        String^             ms_TempDir;
    
        // These functions are called only from cCallbackBridge. They should not be visible from outside the Assembly.
        // cCallbackBridge cannot fire events of another class -> Error C3918
    internal:
        int FireUpdateStatus(kCurStatus^ k_Status)
        {
            // The check for event == null is not required in CLI
            return evUpdateStatus(k_Status);
        }
        int FireFilePlaced(String^ s_File, Int32 s32_FileSize, bool bContinuation)
        {
            // The check for event == null is not required in CLI
            return evFilePlaced(s_File, s32_FileSize, bContinuation);
        }
    };
};

// A bridge class to pass native callbacks to managed code.
// This class MUST be exactly like this!!!! Microsoft did not provide an easier way!
// It is impossible to pass a managed function pointer to native C++ code.
// This could be done using Marshal::StructureToPtr() but this will function only for the first time.
// When the framework moved the delegate in memory to another location the callbacks will fail.
// The !!ONLY!! reliable way to pass delegates to native code is via Pinning using a GCHandle.
// But this is incompatible with native code. 
// Native code cannot call a pinned pointer as if it was a real function pointer.
namespace CabLib
{
    class cCompressBridge
    {
    private:
        Cabinet::CCompress::kCallbacks   mk_Callbacks;
        Cabinet::CCompress*              mi_Compress;
        gcroot<Compress^>                mi_Instance;

    public:

        // All these members must be copied HERE because stupid framewok does not allow to access
        // members of the owning Compress class!
        // The events can not be fired from within the callbacks of the bridge class
        cCompressBridge(gcroot<Compress^> i_Instance)
        {
            mi_Instance = i_Instance;

            mk_Callbacks.f_FilePlaced     = OnFilePlaced;
            mk_Callbacks.f_UpdateStatus   = OnUpdateStatus;
            mk_Callbacks.f_GetNextCabinet = OnGetNextCabinet;
        }

        Cabinet::CCompress::kCallbacks* GetCallbacks()
        {
            return &mk_Callbacks;
        }

        // The folling callbacks are called directly from native C++ code:
        static BOOL OnGetNextCabinet(PCCAB pccab, ULONG cbPrevCab, char* s8_CabNameFormatter, void* p_Param);
        static int  OnFilePlaced(PCCAB pccab, WCHAR* u16_File, int s32_FileSize, BOOL fContinuation, void* p_Param);
        static int  OnUpdateStatus(UINT typeStatus, Cabinet::CCompress::kCurStatus *pk_CurStatus, void*p_Param);
    };
};