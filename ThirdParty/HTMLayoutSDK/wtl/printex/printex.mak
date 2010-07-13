# Microsoft Developer Studio Generated NMAKE File, Based on printex.dsp
!IF "$(CFG)" == ""
CFG=printex - Win32 Debug
!MESSAGE No configuration specified. Defaulting to printex - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "printex - Win32 Release" && "$(CFG)" != "printex - Win32 Debug" && "$(CFG)" != "printex - Win32 ReleaseRetail"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "printex.mak" CFG="printex - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "printex - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "printex - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "printex - Win32 ReleaseRetail" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "printex - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release

!IF "$(RECURSE)" == "0" 

ALL : "..\..\bin\printex.exe"

!ELSE 

ALL : "HTMLayout - Win32 Release" "..\..\bin\printex.exe"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"HTMLayout - Win32 ReleaseCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\printex.obj"
	-@erase "$(INTDIR)\printex.pch"
	-@erase "$(INTDIR)\printex.res"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "..\..\bin\printex.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /GX /O2 /I "..\..\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "STRICT" /Fp"$(INTDIR)\printex.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\printex.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\printex.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=../../lib/htmlayout.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\printex.pdb" /machine:I386 /out:"../../bin/printex.exe" 
LINK32_OBJS= \
	"$(INTDIR)\printex.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\printex.res" \
	"..\..\lib\HTMLayout.lib"

"..\..\bin\printex.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "printex - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug

!IF "$(RECURSE)" == "0" 

ALL : "..\..\bin\printex.exe"

!ELSE 

ALL : "HTMLayout - Win32 Debug" "..\..\bin\printex.exe"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"HTMLayout - Win32 DebugCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\printex.obj"
	-@erase "$(INTDIR)\printex.pch"
	-@erase "$(INTDIR)\printex.res"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\printex.pdb"
	-@erase "..\..\bin\printex.exe"
	-@erase "..\..\bin\printex.ilk"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /I "..\..\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "STRICT" /Fp"$(INTDIR)\printex.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\printex.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\printex.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=../../lib/htmlayout.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\printex.pdb" /debug /machine:I386 /out:"../../bin/printex.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\printex.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\printex.res" \
	"..\..\..\hsmile.v3\Debug\htmlayout.lib"

"..\..\bin\printex.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "printex - Win32 ReleaseRetail"

OUTDIR=.\printex___Win32_ReleaseRetail
INTDIR=.\printex___Win32_ReleaseRetail

!IF "$(RECURSE)" == "0" 

ALL : "..\..\binr\printex.exe"

!ELSE 

ALL : "HTMLayout - Win32 ReleaseRetail" "..\..\binr\printex.exe"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"HTMLayout - Win32 ReleaseRetailCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\printex.obj"
	-@erase "$(INTDIR)\printex.pch"
	-@erase "$(INTDIR)\printex.res"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "..\..\binr\printex.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /GX /O2 /I "..\..\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "STRICT" /D "_ATL_MIN_CRT" /Fp"$(INTDIR)\printex.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\printex.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\printex.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=../../lib/htmlayout.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\printex.pdb" /machine:I386 /out:"../../binr/printex.exe" 
LINK32_OBJS= \
	"$(INTDIR)\printex.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\printex.res" \
	"..\..\lib\HTMLayout.lib"

"..\..\binr\printex.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("printex.dep")
!INCLUDE "printex.dep"
!ELSE 
!MESSAGE Warning: cannot find "printex.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "printex - Win32 Release" || "$(CFG)" == "printex - Win32 Debug" || "$(CFG)" == "printex - Win32 ReleaseRetail"
SOURCE=.\printex.cpp

"$(INTDIR)\printex.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\printex.pch"


SOURCE=.\printex.rc

"$(INTDIR)\printex.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "printex - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /I "..\..\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "STRICT" /Fp"$(INTDIR)\printex.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\printex.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "printex - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /I "..\..\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "STRICT" /Fp"$(INTDIR)\printex.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\printex.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "printex - Win32 ReleaseRetail"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /I "..\..\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "STRICT" /D "_ATL_MIN_CRT" /Fp"$(INTDIR)\printex.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\printex.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

!IF  "$(CFG)" == "printex - Win32 Release"

"HTMLayout - Win32 Release" : 
   cd "\layout\hsmile.v3\HTMLayout"
   $(MAKE) /$(MAKEFLAGS) /F .\HTMLayout.mak CFG="HTMLayout - Win32 Release" 
   cd "..\..\htmlayoutsdk\wtl\printex"

"HTMLayout - Win32 ReleaseCLEAN" : 
   cd "\layout\hsmile.v3\HTMLayout"
   $(MAKE) /$(MAKEFLAGS) /F .\HTMLayout.mak CFG="HTMLayout - Win32 Release" RECURSE=1 CLEAN 
   cd "..\..\htmlayoutsdk\wtl\printex"

!ELSEIF  "$(CFG)" == "printex - Win32 Debug"

"HTMLayout - Win32 Debug" : 
   cd "\layout\hsmile.v3\HTMLayout"
   $(MAKE) /$(MAKEFLAGS) /F .\HTMLayout.mak CFG="HTMLayout - Win32 Debug" 
   cd "..\..\htmlayoutsdk\wtl\printex"

"HTMLayout - Win32 DebugCLEAN" : 
   cd "\layout\hsmile.v3\HTMLayout"
   $(MAKE) /$(MAKEFLAGS) /F .\HTMLayout.mak CFG="HTMLayout - Win32 Debug" RECURSE=1 CLEAN 
   cd "..\..\htmlayoutsdk\wtl\printex"

!ELSEIF  "$(CFG)" == "printex - Win32 ReleaseRetail"

"HTMLayout - Win32 ReleaseRetail" : 
   cd "\layout\hsmile.v3\HTMLayout"
   $(MAKE) /$(MAKEFLAGS) /F .\HTMLayout.mak CFG="HTMLayout - Win32 ReleaseRetail" 
   cd "..\..\htmlayoutsdk\wtl\printex"

"HTMLayout - Win32 ReleaseRetailCLEAN" : 
   cd "\layout\hsmile.v3\HTMLayout"
   $(MAKE) /$(MAKEFLAGS) /F .\HTMLayout.mak CFG="HTMLayout - Win32 ReleaseRetail" RECURSE=1 CLEAN 
   cd "..\..\htmlayoutsdk\wtl\printex"

!ENDIF 


!ENDIF 

