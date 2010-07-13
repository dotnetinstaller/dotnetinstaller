# Microsoft Developer Studio Generated NMAKE File, Based on win32.dsp
!IF "$(CFG)" == ""
CFG=win32 - Win32 Debug
!MESSAGE No configuration specified. Defaulting to win32 - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "win32 - Win32 Release" && "$(CFG)" != "win32 - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "win32.mak" CFG="win32 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "win32 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "win32 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "win32 - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release

ALL : "..\bin\win32.exe"


CLEAN :
	-@erase "$(INTDIR)\behavior_command.obj"
	-@erase "$(INTDIR)\behavior_hyperlink.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\win32.obj"
	-@erase "$(INTDIR)\win32.pch"
	-@erase "$(INTDIR)\win32.res"
	-@erase "..\bin\win32.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /ML /W3 /GX /O2 /I "../include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\win32.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
RSC_PROJ=/l 0x1009 /fo"$(INTDIR)\win32.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\win32.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=../lib/HTMLayout.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\win32.pdb" /machine:I386 /out:"../bin/win32.exe" 
LINK32_OBJS= \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\win32.obj" \
	"$(INTDIR)\behavior_command.obj" \
	"$(INTDIR)\behavior_hyperlink.obj" \
	"$(INTDIR)\win32.res"

"..\bin\win32.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "win32 - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "..\bin\win32.exe"


CLEAN :
	-@erase "$(INTDIR)\behavior_command.obj"
	-@erase "$(INTDIR)\behavior_hyperlink.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\win32.obj"
	-@erase "$(INTDIR)\win32.pch"
	-@erase "$(INTDIR)\win32.res"
	-@erase "$(OUTDIR)\win32.pdb"
	-@erase "..\bin\win32.exe"
	-@erase "..\bin\win32.ilk"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /I "../include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\win32.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

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
RSC_PROJ=/l 0x1009 /fo"$(INTDIR)\win32.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\win32.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=../lib/HTMLayout.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\win32.pdb" /debug /machine:I386 /out:"../bin/win32.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\win32.obj" \
	"$(INTDIR)\behavior_command.obj" \
	"$(INTDIR)\behavior_hyperlink.obj" \
	"$(INTDIR)\win32.res"

"..\bin\win32.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("win32.dep")
!INCLUDE "win32.dep"
!ELSE 
!MESSAGE Warning: cannot find "win32.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "win32 - Win32 Release" || "$(CFG)" == "win32 - Win32 Debug"
SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "win32 - Win32 Release"

CPP_SWITCHES=/nologo /ML /W3 /GX /O2 /I "../include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\win32.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\win32.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "win32 - Win32 Debug"

CPP_SWITCHES=/nologo /MLd /W3 /Gm /GX /ZI /Od /I "../include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\win32.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\win32.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\win32.cpp

"$(INTDIR)\win32.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\win32.pch"


SOURCE=.\win32.rc

"$(INTDIR)\win32.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=..\include\behaviors\behavior_command.cpp

"$(INTDIR)\behavior_command.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\win32.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\include\behaviors\behavior_hyperlink.cpp

"$(INTDIR)\behavior_hyperlink.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\win32.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)



!ENDIF 

