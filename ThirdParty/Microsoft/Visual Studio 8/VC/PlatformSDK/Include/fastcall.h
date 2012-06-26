#ifdef WIN32
#if defined(FASTCALL_IN_STORE)
#define __FORCENONFASTCALL __stdcall //-Gz used in xmake1.mak
#else
#define __FORCENONFASTCALL
#endif
#endif

#ifdef WIN16
#if defined(FASTCALL_IN_STORE)
#define __FORCENONFASTCALL __cdecl // -Gd overrides -Gc in xmake1.mak
#else
#define __FORCENONFASTCALL
#endif
#endif

#ifdef MAC
#if defined(FASTCALL_IN_STORE)
#define __FORCENONFASTCALL __stdcall //-Gz used in xmake1.mak
#else
#define __FORCENONFASTCALL
#endif
#endif

