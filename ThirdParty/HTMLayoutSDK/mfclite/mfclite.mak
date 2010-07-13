# Microsoft Developer Studio Generated NMAKE File, Based on mfclite.dsp
!IF "$(CFG)" == ""
CFG=mfclite - Win32 Debug
!MESSAGE No configuration specified. Defaulting to mfclite - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "mfclite - Win32 Release" && "$(CFG)" != "mfclite - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "mfclite.mak" CFG="mfclite - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "mfclite - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "mfclite - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "mfclite - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release

!IF "$(RECURSE)" == "0" 

ALL : "..\bin\mfclite.exe"

!ELSE 

ALL : "HTMLayout - Win32 Release" "..\bin\mfclite.exe"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"HTMLayout - Win32 ReleaseCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\mfclite.obj"
	-@erase "$(INTDIR)\mfclite.pch"
	-@erase "$(INTDIR)\mfclite.res"
	-@erase "$(INTDIR)\mfcliteDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "..\bin\mfclite.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /GX /O2 /I "..\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\mfclite.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\mfclite.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mfclite.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\mfclite.pdb" /machine:I386 /out:"../bin/mfclite.exe" /libpath:"..\lib" 
LINK32_OBJS= \
	"$(INTDIR)\mfclite.obj" \
	"$(INTDIR)\mfcliteDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\mfclite.res" \
	"..\lib\HTMLayout.lib"

"..\bin\mfclite.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "mfclite - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug

!IF "$(RECURSE)" == "0" 

ALL : "..\bin\mfclite.exe"

!ELSE 

ALL : "HTMLayout - Win32 Debug" "..\bin\mfclite.exe"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"HTMLayout - Win32 DebugCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\mfclite.obj"
	-@erase "$(INTDIR)\mfclite.pch"
	-@erase "$(INTDIR)\mfclite.res"
	-@erase "$(INTDIR)\mfcliteDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\mfclite.pdb"
	-@erase "..\bin\mfclite.exe"
	-@erase "..\bin\mfclite.ilk"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /I "..\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\mfclite.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\mfclite.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mfclite.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=htmlayout.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\mfclite.pdb" /debug /machine:I386 /out:"../bin/mfclite.exe" /pdbtype:sept /libpath:"..\lib" 
LINK32_OBJS= \
	"$(INTDIR)\mfclite.obj" \
	"$(INTDIR)\mfcliteDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\mfclite.res" \
	"..\..\hsmile.v3\Debug\htmlayout.lib"

"..\bin\mfclite.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("mfclite.dep")
!INCLUDE "mfclite.dep"
!ELSE 
!MESSAGE Warning: cannot find "mfclite.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "mfclite - Win32 Release" || "$(CFG)" == "mfclite - Win32 Debug"
SOURCE=.\mfclite.cpp

"$(INTDIR)\mfclite.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mfclite.pch"


SOURCE=.\mfclite.rc

"$(INTDIR)\mfclite.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\mfcliteDlg.cpp

"$(INTDIR)\mfcliteDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mfclite.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "mfclite - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /I "..\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\mfclite.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\mfclite.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "mfclite - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /I "..\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\mfclite.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\mfclite.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

!IF  "$(CFG)" == "mfclite - Win32 Release"

"HTMLayout - Win32 Release" : 
   cd "\layout\hsmile.v3\HTMLayout"
   $(MAKE) /$(MAKEFLAGS) /F .\HTMLayout.mak CFG="HTMLayout - Win32 Release" 
   cd "..\..\htmlayoutsdk\mfclite"

"HTMLayout - Win32 ReleaseCLEAN" : 
   cd "\layout\hsmile.v3\HTMLayout"
   $(MAKE) /$(MAKEFLAGS) /F .\HTMLayout.mak CFG="HTMLayout - Win32 Release" RECURSE=1 CLEAN 
   cd "..\..\htmlayoutsdk\mfclite"

!ELSEIF  "$(CFG)" == "mfclite - Win32 Debug"

"HTMLayout - Win32 Debug" : 
   cd "\layout\hsmile.v3\HTMLayout"
   $(MAKE) /$(MAKEFLAGS) /F .\HTMLayout.mak CFG="HTMLayout - Win32 Debug" 
   cd "..\..\htmlayoutsdk\mfclite"

"HTMLayout - Win32 DebugCLEAN" : 
   cd "\layout\hsmile.v3\HTMLayout"
   $(MAKE) /$(MAKEFLAGS) /F .\HTMLayout.mak CFG="HTMLayout - Win32 Debug" RECURSE=1 CLEAN 
   cd "..\..\htmlayoutsdk\mfclite"

!ENDIF 


!ENDIF 

