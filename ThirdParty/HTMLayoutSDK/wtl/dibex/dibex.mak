# Microsoft Developer Studio Generated NMAKE File, Based on dibex.dsp
!IF "$(CFG)" == ""
CFG=dibex - Win32 Debug
!MESSAGE No configuration specified. Defaulting to dibex - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "dibex - Win32 Release" && "$(CFG)" != "dibex - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "dibex.mak" CFG="dibex - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "dibex - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "dibex - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "dibex - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release

!IF "$(RECURSE)" == "0" 

ALL : "..\..\bin\dibex.exe"

!ELSE 

ALL : "HTMLayout - Win32 Release" "..\..\bin\dibex.exe"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"HTMLayout - Win32 ReleaseCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\aboutdlg.obj"
	-@erase "$(INTDIR)\dibex.obj"
	-@erase "$(INTDIR)\dibex.pch"
	-@erase "$(INTDIR)\dibex.res"
	-@erase "$(INTDIR)\dibexview.obj"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "..\..\bin\dibex.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /GX /O2 /I "..\..\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "STRICT" /Fp"$(INTDIR)\dibex.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
RSC_PROJ=/l 0x1009 /fo"$(INTDIR)\dibex.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\dibex.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ../../lib/htmlayout.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\dibex.pdb" /machine:I386 /out:"../../bin/dibex.exe" 
LINK32_OBJS= \
	"$(INTDIR)\aboutdlg.obj" \
	"$(INTDIR)\dibex.obj" \
	"$(INTDIR)\dibexview.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\dibex.res" \
	"..\..\lib\HTMLayout.lib"

"..\..\bin\dibex.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "dibex - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug

!IF "$(RECURSE)" == "0" 

ALL : "..\..\bin\dibex.exe"

!ELSE 

ALL : "HTMLayout - Win32 Debug" "..\..\bin\dibex.exe"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"HTMLayout - Win32 DebugCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\aboutdlg.obj"
	-@erase "$(INTDIR)\dibex.obj"
	-@erase "$(INTDIR)\dibex.pch"
	-@erase "$(INTDIR)\dibex.res"
	-@erase "$(INTDIR)\dibexview.obj"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\dibex.pdb"
	-@erase "..\..\bin\dibex.exe"
	-@erase "..\..\bin\dibex.ilk"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /I "..\..\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "STRICT" /Fp"$(INTDIR)\dibex.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

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
RSC_PROJ=/l 0x1009 /fo"$(INTDIR)\dibex.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\dibex.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ../../lib/htmlayout.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\dibex.pdb" /debug /machine:I386 /out:"../../bin/dibex.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\aboutdlg.obj" \
	"$(INTDIR)\dibex.obj" \
	"$(INTDIR)\dibexview.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\dibex.res" \
	"..\..\..\hsmile.v3\Debug\htmlayout.lib"

"..\..\bin\dibex.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("dibex.dep")
!INCLUDE "dibex.dep"
!ELSE 
!MESSAGE Warning: cannot find "dibex.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "dibex - Win32 Release" || "$(CFG)" == "dibex - Win32 Debug"
SOURCE=.\aboutdlg.cpp

"$(INTDIR)\aboutdlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\dibex.pch"


SOURCE=.\dibex.cpp

"$(INTDIR)\dibex.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\dibex.pch"


SOURCE=.\dibex.rc

"$(INTDIR)\dibex.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\dibexview.cpp

"$(INTDIR)\dibexview.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\dibex.pch"


SOURCE=.\mainfrm.cpp

"$(INTDIR)\mainfrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\dibex.pch"


SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "dibex - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /I "..\..\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "STRICT" /Fp"$(INTDIR)\dibex.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\dibex.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "dibex - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /I "..\..\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "STRICT" /Fp"$(INTDIR)\dibex.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\dibex.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

!IF  "$(CFG)" == "dibex - Win32 Release"

"HTMLayout - Win32 Release" : 
   cd "\layout\hsmile.v3\HTMLayout"
   $(MAKE) /$(MAKEFLAGS) /F .\HTMLayout.mak CFG="HTMLayout - Win32 Release" 
   cd "..\..\HTMLAYOUTSDK\WTL\dibex"

"HTMLayout - Win32 ReleaseCLEAN" : 
   cd "\layout\hsmile.v3\HTMLayout"
   $(MAKE) /$(MAKEFLAGS) /F .\HTMLayout.mak CFG="HTMLayout - Win32 Release" RECURSE=1 CLEAN 
   cd "..\..\HTMLAYOUTSDK\WTL\dibex"

!ELSEIF  "$(CFG)" == "dibex - Win32 Debug"

"HTMLayout - Win32 Debug" : 
   cd "\layout\hsmile.v3\HTMLayout"
   $(MAKE) /$(MAKEFLAGS) /F .\HTMLayout.mak CFG="HTMLayout - Win32 Debug" 
   cd "..\..\HTMLAYOUTSDK\WTL\dibex"

"HTMLayout - Win32 DebugCLEAN" : 
   cd "\layout\hsmile.v3\HTMLayout"
   $(MAKE) /$(MAKEFLAGS) /F .\HTMLayout.mak CFG="HTMLayout - Win32 Debug" RECURSE=1 CLEAN 
   cd "..\..\HTMLAYOUTSDK\WTL\dibex"

!ENDIF 


!ENDIF 

