// pogodbo.h
//
// Pogo Data Base reading/writing interfaces for overrides only

#pragma warning(push)

#pragma warning(disable: 4200)     // allow 0 sized array in struct/union
#pragma warning(disable: 4201)     // Allow nameless struct/union


#include <stddef.h>
typedef int BOOL;
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;
typedef unsigned __int64 QWORD;


// REVIEW: May want to typedef DWORD PGDSYMID;

#if !defined(POGODB_DLL_BUILD)

#define POGODLL __declspec(dllimport)

#else

#define POGODLL

#endif

#define POGODLLAPI(type) POGODLL type __stdcall

// Pogo database operating modes.

typedef enum {
    POGODB_TOOL_READ, // for Pogo profile data tools
    POGODB_TOOL_WRITE,
    POGODB_COMPILER_READ, // VC++ compiler
    POGODB_COMPILER_WRITE,
    POGODB_OVERRIDE_READ, // for non-Pogo override info tools
    POGODB_OVERRIDE_WRITE,
    POGODB_LINKER_READ,   // VC++ linker
    POGODB_LINKER_WRITE
} POGODB_MODE;


// Enumeration of profile streams (must be in sync with names in pogodb.cpp)
// Don't forget to add per-module streams to PogoDbOpenStream and
// PogoDbSetModule.

typedef enum {
    PGDS_HEADER = 0,
    PGDS_HISTORY,
    PGDS_OBJECT_INFO,
    PGDS_LINK_INFO,
    PGDS_SYMBOL_TABLE,
    PGDS_PROBE_ID,
    PGDS_ENTRY,
    PGDS_MODULE,
    PGDS_FUNCTIONS,
    PGDS_PROBE_INFO,
    PGDS_PROBE_DATA,
    PGDS_VALUE_DATA,
    PGDS_MDS_DATA,
    PGDS_FLOW_GRAPH,
    PGDS_CALL_GRAPH,
    PGDS_BRANCH_INFO,
    PGDS_OVERRIDE_INFO,
    PGDS_FUNC_HASH,
    PGDS_TOB_DATA,
    PGDS_VCALL_TABLE,
    PGDS_MAX
} POGODB_STREAM;

// Enumeration of error codes.

typedef enum {
    PGDE_OK = 0,
    PGDE_ERROR, // generic error
    PGDE_NOT_FOUND, // file not found
    PGDE_PDB_ERROR, // PDB error not explicitly handled
    PGDE_SIGNATURE_MISMATCH,
    PGDE_VERSION_MISMATCH,
    PGDE_READ_ONLY,
    PGDE_LTCG_MISMATCH,   // PGD is LTCG and compile isn't or vice-versa
    PGDE_OUT_OF_MEMORY,
    PGDE_BAD_PARAMETER,
    PGDE_NO_DATA, // no data of the requested type
    PGDE_PGD_NOT_OPEN,
    PGDE_MODULE_NOT_OPEN,
    PGDE_FUNCTION_NOT_OPEN,
    PGDE_MISSING_STREAM,
    PGDE_INVALID_STREAM = PGDE_MISSING_STREAM + PGDS_MAX,
    PGDE_REPLACE_ERROR = PGDE_INVALID_STREAM + PGDS_MAX,
    PGDE_WRITE_ERROR = PGDE_REPLACE_ERROR + PGDS_MAX,
    PGDE_APPEND_ERROR = PGDE_WRITE_ERROR + PGDS_MAX,
    PGDE_STREAM_NOT_OPEN = PGDE_APPEND_ERROR + PGDS_MAX,
    PGDE_MAX = PGDE_STREAM_NOT_OPEN + PGDS_MAX
} POGODB_ERROR;

// Pogo Symtab Flags (PSF)
#define PSF_LOCAL            0x80000000

typedef struct tagPGDHEADER PGDHEADER, *PPGDHEADER;
typedef struct tagPGDMODULERECORD PGDMODULERECORD, *PPGDMODULERECORD;
typedef struct tagPGDFUNCRECORD PGDFUNCRECORD, *PPGDFUNCRECORD;

struct tagPGDFUNCOVERRIDE {
    DWORD fOptOt:1;               // 1 => -Ot, 0 => -Os
    DWORD fUnused:31;
    DWORD mask; // valid fields
};
typedef struct tagPGDFUNCOVERRIDE PGDFUNCOVERRIDE, *PPGDFUNCOVERRIDE;

#define PFO_OPTOT 0x00000001


extern POGODLLAPI(POGODB_ERROR) PogoDbGetLastError(void);
extern POGODLLAPI(const char *) PogoDbGetErrorText(POGODB_ERROR error);
extern POGODLLAPI(BOOL) PogoDbGenerateModuleName(LPCWSTR pdbName, LPCWSTR OBJName, __out_ecount(bufLen) LPWSTR moduleName, size_t bufLen);

extern POGODLLAPI(BOOL) PogoDbOpen(LPCWSTR name, POGODB_MODE mode, BOOL fLTCG);
extern POGODLLAPI(PPGDHEADER) PogoDbReadHeader(void);
extern POGODLLAPI(BOOL) PogoDbCreateGlobalStreams();
extern POGODLLAPI(BOOL) PogoDbReadGlobalStreams(void);
extern POGODLLAPI(BOOL) PogoDbClose(void);

extern POGODLLAPI(BOOL) PogoDbSetModule(LPCWSTR moduleName);
extern POGODLLAPI(PPGDMODULERECORD) PogoDbReadModule(PPGDMODULERECORD pMod);
extern POGODLLAPI(BOOL) PogoDbOpenModule(PPGDMODULERECORD pMod);
extern POGODLLAPI(LPCTSTR) PogoDbGetModuleName(void);
extern POGODLLAPI(void) PogoDbCloseModule(void);

extern POGODLLAPI(BOOL) PogoDbSetFunction(char *funcName, DWORD symFlags);
extern POGODLLAPI(PPGDFUNCRECORD) PogoDbReadFunction(PPGDFUNCRECORD pFunc);
extern POGODLLAPI(BOOL) PogoDbOpenFunction(PPGDFUNCRECORD pFunc);
extern POGODLLAPI(const char *) PogoDbGetFunctionName(void);
extern POGODLLAPI(BOOL) PogoDbReadFunctionOverride(PPGDFUNCOVERRIDE pOverride);
extern POGODLLAPI(BOOL) PogoDbWriteFunctionOverride(PPGDFUNCOVERRIDE pOverride);
extern POGODLLAPI(void) PogoDbCloseFunction(void);

#pragma warning(pop)
