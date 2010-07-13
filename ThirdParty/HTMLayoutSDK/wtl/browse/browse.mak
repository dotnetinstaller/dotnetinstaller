# Microsoft Developer Studio Generated NMAKE File, Based on browse.dsp
!IF "$(CFG)" == ""
CFG=browse - Win32 Debug
!MESSAGE No configuration specified. Defaulting to browse - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "browse - Win32 Release" && "$(CFG)" != "browse - Win32 Debug" && "$(CFG)" != "browse - Win32 ReleaseRetail"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "browse.mak" CFG="browse - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "browse - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "browse - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "browse - Win32 ReleaseRetail" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "browse - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release

!IF "$(RECURSE)" == "0" 

ALL : "..\..\bin\browse.exe"

!ELSE 

ALL : "HTMLayout - Win32 Release" "..\..\bin\browse.exe"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"HTMLayout - Win32 ReleaseCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\behavior_accesskeys.obj"
	-@erase "$(INTDIR)\behavior_actions.obj"
	-@erase "$(INTDIR)\behavior_clock.obj"
	-@erase "$(INTDIR)\behavior_collapsible_by_icon.obj"
	-@erase "$(INTDIR)\behavior_command.obj"
	-@erase "$(INTDIR)\behavior_editable_select.obj"
	-@erase "$(INTDIR)\behavior_expandable_list.obj"
	-@erase "$(INTDIR)\behavior_form.obj"
	-@erase "$(INTDIR)\behavior_grid.obj"
	-@erase "$(INTDIR)\behavior_path.obj"
	-@erase "$(INTDIR)\behavior_popup.obj"
	-@erase "$(INTDIR)\behavior_scroller.obj"
	-@erase "$(INTDIR)\behavior_select_buddy.obj"
	-@erase "$(INTDIR)\behavior_select_checkmark.obj"
	-@erase "$(INTDIR)\behavior_shellicon.obj"
	-@erase "$(INTDIR)\behavior_splitter.obj"
	-@erase "$(INTDIR)\behavior_tabs.obj"
	-@erase "$(INTDIR)\behavior_virtual_grid.obj"
	-@erase "$(INTDIR)\browse.obj"
	-@erase "$(INTDIR)\browse.pch"
	-@erase "$(INTDIR)\browse.res"
	-@erase "$(INTDIR)\data_source_behavior.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "..\..\bin\browse.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /GX /O1 /I "..\..\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "STRICT" /Fp"$(INTDIR)\browse.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\browse.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\browse.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=../../lib/HTMLayout.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\browse.pdb" /machine:I386 /out:"../../bin/browse.exe" 
LINK32_OBJS= \
	"$(INTDIR)\browse.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\behavior_accesskeys.obj" \
	"$(INTDIR)\behavior_actions.obj" \
	"$(INTDIR)\behavior_clock.obj" \
	"$(INTDIR)\behavior_collapsible_by_icon.obj" \
	"$(INTDIR)\behavior_command.obj" \
	"$(INTDIR)\behavior_editable_select.obj" \
	"$(INTDIR)\behavior_expandable_list.obj" \
	"$(INTDIR)\behavior_form.obj" \
	"$(INTDIR)\behavior_grid.obj" \
	"$(INTDIR)\behavior_path.obj" \
	"$(INTDIR)\behavior_popup.obj" \
	"$(INTDIR)\behavior_scroller.obj" \
	"$(INTDIR)\behavior_select_buddy.obj" \
	"$(INTDIR)\behavior_select_checkmark.obj" \
	"$(INTDIR)\behavior_shellicon.obj" \
	"$(INTDIR)\behavior_splitter.obj" \
	"$(INTDIR)\behavior_tabs.obj" \
	"$(INTDIR)\behavior_virtual_grid.obj" \
	"$(INTDIR)\data_source_behavior.obj" \
	"$(INTDIR)\browse.res" \
	"..\..\lib\HTMLayout.lib"

"..\..\bin\browse.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "browse - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "..\..\bin\browse.exe" "$(OUTDIR)\browse.bsc"

!ELSE 

ALL : "HTMLayout - Win32 Debug" "..\..\bin\browse.exe" "$(OUTDIR)\browse.bsc"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"HTMLayout - Win32 DebugCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\behavior_accesskeys.obj"
	-@erase "$(INTDIR)\behavior_accesskeys.sbr"
	-@erase "$(INTDIR)\behavior_actions.obj"
	-@erase "$(INTDIR)\behavior_actions.sbr"
	-@erase "$(INTDIR)\behavior_clock.obj"
	-@erase "$(INTDIR)\behavior_clock.sbr"
	-@erase "$(INTDIR)\behavior_collapsible_by_icon.obj"
	-@erase "$(INTDIR)\behavior_collapsible_by_icon.sbr"
	-@erase "$(INTDIR)\behavior_command.obj"
	-@erase "$(INTDIR)\behavior_command.sbr"
	-@erase "$(INTDIR)\behavior_editable_select.obj"
	-@erase "$(INTDIR)\behavior_editable_select.sbr"
	-@erase "$(INTDIR)\behavior_expandable_list.obj"
	-@erase "$(INTDIR)\behavior_expandable_list.sbr"
	-@erase "$(INTDIR)\behavior_form.obj"
	-@erase "$(INTDIR)\behavior_form.sbr"
	-@erase "$(INTDIR)\behavior_grid.obj"
	-@erase "$(INTDIR)\behavior_grid.sbr"
	-@erase "$(INTDIR)\behavior_path.obj"
	-@erase "$(INTDIR)\behavior_path.sbr"
	-@erase "$(INTDIR)\behavior_popup.obj"
	-@erase "$(INTDIR)\behavior_popup.sbr"
	-@erase "$(INTDIR)\behavior_scroller.obj"
	-@erase "$(INTDIR)\behavior_scroller.sbr"
	-@erase "$(INTDIR)\behavior_select_checkmark.obj"
	-@erase "$(INTDIR)\behavior_select_checkmark.sbr"
	-@erase "$(INTDIR)\behavior_shellicon.obj"
	-@erase "$(INTDIR)\behavior_shellicon.sbr"
	-@erase "$(INTDIR)\behavior_splitter.obj"
	-@erase "$(INTDIR)\behavior_splitter.sbr"
	-@erase "$(INTDIR)\behavior_tabs.obj"
	-@erase "$(INTDIR)\behavior_tabs.sbr"
	-@erase "$(INTDIR)\behavior_virtual_grid.obj"
	-@erase "$(INTDIR)\behavior_virtual_grid.sbr"
	-@erase "$(INTDIR)\browse.obj"
	-@erase "$(INTDIR)\browse.pch"
	-@erase "$(INTDIR)\browse.res"
	-@erase "$(INTDIR)\browse.sbr"
	-@erase "$(INTDIR)\data_source_behavior.obj"
	-@erase "$(INTDIR)\data_source_behavior.sbr"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\stdafx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\browse.bsc"
	-@erase "$(OUTDIR)\browse.map"
	-@erase "$(OUTDIR)\browse.pdb"
	-@erase "..\..\bin\browse.exe"
	-@erase "..\..\bin\browse.ilk"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /I "..\..\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "STRICT" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\browse.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\browse.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\browse.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\browse.sbr" \
	"$(INTDIR)\stdafx.sbr" \
	"$(INTDIR)\behavior_accesskeys.sbr" \
	"$(INTDIR)\behavior_actions.sbr" \
	"$(INTDIR)\behavior_clock.sbr" \
	"$(INTDIR)\behavior_collapsible_by_icon.sbr" \
	"$(INTDIR)\behavior_command.sbr" \
	"$(INTDIR)\behavior_editable_select.sbr" \
	"$(INTDIR)\behavior_expandable_list.sbr" \
	"$(INTDIR)\behavior_form.sbr" \
	"$(INTDIR)\behavior_grid.sbr" \
	"$(INTDIR)\behavior_path.sbr" \
	"$(INTDIR)\behavior_popup.sbr" \
	"$(INTDIR)\behavior_scroller.sbr" \
	"$(INTDIR)\behavior_select_checkmark.sbr" \
	"$(INTDIR)\behavior_shellicon.sbr" \
	"$(INTDIR)\behavior_splitter.sbr" \
	"$(INTDIR)\behavior_tabs.sbr" \
	"$(INTDIR)\behavior_virtual_grid.sbr" \
	"$(INTDIR)\data_source_behavior.sbr"

"$(OUTDIR)\browse.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ../../lib/htmlayout.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\browse.pdb" /map:"$(INTDIR)\browse.map" /debug /machine:I386 /out:"../../bin/browse.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\browse.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\behavior_accesskeys.obj" \
	"$(INTDIR)\behavior_actions.obj" \
	"$(INTDIR)\behavior_clock.obj" \
	"$(INTDIR)\behavior_collapsible_by_icon.obj" \
	"$(INTDIR)\behavior_command.obj" \
	"$(INTDIR)\behavior_editable_select.obj" \
	"$(INTDIR)\behavior_expandable_list.obj" \
	"$(INTDIR)\behavior_form.obj" \
	"$(INTDIR)\behavior_grid.obj" \
	"$(INTDIR)\behavior_path.obj" \
	"$(INTDIR)\behavior_popup.obj" \
	"$(INTDIR)\behavior_scroller.obj" \
	"$(INTDIR)\behavior_select_checkmark.obj" \
	"$(INTDIR)\behavior_shellicon.obj" \
	"$(INTDIR)\behavior_splitter.obj" \
	"$(INTDIR)\behavior_tabs.obj" \
	"$(INTDIR)\behavior_virtual_grid.obj" \
	"$(INTDIR)\data_source_behavior.obj" \
	"$(INTDIR)\browse.res" \
	"..\..\..\hsmile.v3\Debug\htmlayout.lib"

"..\..\bin\browse.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "browse - Win32 ReleaseRetail"

OUTDIR=.\Release
INTDIR=.\ReleaseRetail
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "..\..\binr\browse.exe" "$(OUTDIR)\browse.bsc"

!ELSE 

ALL : "HTMLayout - Win32 ReleaseRetail" "..\..\binr\browse.exe" "$(OUTDIR)\browse.bsc"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"HTMLayout - Win32 ReleaseRetailCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\behavior_accesskeys.obj"
	-@erase "$(INTDIR)\behavior_accesskeys.sbr"
	-@erase "$(INTDIR)\behavior_actions.obj"
	-@erase "$(INTDIR)\behavior_actions.sbr"
	-@erase "$(INTDIR)\behavior_clock.obj"
	-@erase "$(INTDIR)\behavior_clock.sbr"
	-@erase "$(INTDIR)\behavior_collapsible_by_icon.obj"
	-@erase "$(INTDIR)\behavior_collapsible_by_icon.sbr"
	-@erase "$(INTDIR)\behavior_command.obj"
	-@erase "$(INTDIR)\behavior_command.sbr"
	-@erase "$(INTDIR)\behavior_editable_select.obj"
	-@erase "$(INTDIR)\behavior_editable_select.sbr"
	-@erase "$(INTDIR)\behavior_expandable_list.obj"
	-@erase "$(INTDIR)\behavior_expandable_list.sbr"
	-@erase "$(INTDIR)\behavior_form.obj"
	-@erase "$(INTDIR)\behavior_form.sbr"
	-@erase "$(INTDIR)\behavior_grid.obj"
	-@erase "$(INTDIR)\behavior_grid.sbr"
	-@erase "$(INTDIR)\behavior_path.obj"
	-@erase "$(INTDIR)\behavior_path.sbr"
	-@erase "$(INTDIR)\behavior_popup.obj"
	-@erase "$(INTDIR)\behavior_popup.sbr"
	-@erase "$(INTDIR)\behavior_scroller.obj"
	-@erase "$(INTDIR)\behavior_scroller.sbr"
	-@erase "$(INTDIR)\behavior_select_buddy.obj"
	-@erase "$(INTDIR)\behavior_select_buddy.sbr"
	-@erase "$(INTDIR)\behavior_select_checkmark.obj"
	-@erase "$(INTDIR)\behavior_select_checkmark.sbr"
	-@erase "$(INTDIR)\behavior_shellicon.obj"
	-@erase "$(INTDIR)\behavior_shellicon.sbr"
	-@erase "$(INTDIR)\behavior_splitter.obj"
	-@erase "$(INTDIR)\behavior_splitter.sbr"
	-@erase "$(INTDIR)\behavior_tabs.obj"
	-@erase "$(INTDIR)\behavior_tabs.sbr"
	-@erase "$(INTDIR)\behavior_virtual_grid.obj"
	-@erase "$(INTDIR)\behavior_virtual_grid.sbr"
	-@erase "$(INTDIR)\browse.obj"
	-@erase "$(INTDIR)\browse.pch"
	-@erase "$(INTDIR)\browse.res"
	-@erase "$(INTDIR)\browse.sbr"
	-@erase "$(INTDIR)\data_source_behavior.obj"
	-@erase "$(INTDIR)\data_source_behavior.sbr"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\stdafx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\browse.bsc"
	-@erase "..\..\binr\browse.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /GX /O1 /I "..\..\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "STRICT" /D "FLICKER_FREE_COMCTL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\browse.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\browse.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\browse.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\browse.sbr" \
	"$(INTDIR)\stdafx.sbr" \
	"$(INTDIR)\behavior_accesskeys.sbr" \
	"$(INTDIR)\behavior_actions.sbr" \
	"$(INTDIR)\behavior_clock.sbr" \
	"$(INTDIR)\behavior_collapsible_by_icon.sbr" \
	"$(INTDIR)\behavior_command.sbr" \
	"$(INTDIR)\behavior_editable_select.sbr" \
	"$(INTDIR)\behavior_expandable_list.sbr" \
	"$(INTDIR)\behavior_form.sbr" \
	"$(INTDIR)\behavior_grid.sbr" \
	"$(INTDIR)\behavior_path.sbr" \
	"$(INTDIR)\behavior_popup.sbr" \
	"$(INTDIR)\behavior_scroller.sbr" \
	"$(INTDIR)\behavior_select_buddy.sbr" \
	"$(INTDIR)\behavior_select_checkmark.sbr" \
	"$(INTDIR)\behavior_shellicon.sbr" \
	"$(INTDIR)\behavior_splitter.sbr" \
	"$(INTDIR)\behavior_tabs.sbr" \
	"$(INTDIR)\behavior_virtual_grid.sbr" \
	"$(INTDIR)\data_source_behavior.sbr"

"$(OUTDIR)\browse.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=../../lib/HTMLayout.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\browse.pdb" /machine:I386 /out:"../../binr/browse.exe" 
LINK32_OBJS= \
	"$(INTDIR)\browse.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\behavior_accesskeys.obj" \
	"$(INTDIR)\behavior_actions.obj" \
	"$(INTDIR)\behavior_clock.obj" \
	"$(INTDIR)\behavior_collapsible_by_icon.obj" \
	"$(INTDIR)\behavior_command.obj" \
	"$(INTDIR)\behavior_editable_select.obj" \
	"$(INTDIR)\behavior_expandable_list.obj" \
	"$(INTDIR)\behavior_form.obj" \
	"$(INTDIR)\behavior_grid.obj" \
	"$(INTDIR)\behavior_path.obj" \
	"$(INTDIR)\behavior_popup.obj" \
	"$(INTDIR)\behavior_scroller.obj" \
	"$(INTDIR)\behavior_select_buddy.obj" \
	"$(INTDIR)\behavior_select_checkmark.obj" \
	"$(INTDIR)\behavior_shellicon.obj" \
	"$(INTDIR)\behavior_splitter.obj" \
	"$(INTDIR)\behavior_tabs.obj" \
	"$(INTDIR)\behavior_virtual_grid.obj" \
	"$(INTDIR)\data_source_behavior.obj" \
	"$(INTDIR)\browse.res" \
	"..\..\lib\HTMLayout.lib"

"..\..\binr\browse.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("browse.dep")
!INCLUDE "browse.dep"
!ELSE 
!MESSAGE Warning: cannot find "browse.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "browse - Win32 Release" || "$(CFG)" == "browse - Win32 Debug" || "$(CFG)" == "browse - Win32 ReleaseRetail"
SOURCE=.\browse.cpp

!IF  "$(CFG)" == "browse - Win32 Release"


"$(INTDIR)\browse.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"


!ELSEIF  "$(CFG)" == "browse - Win32 Debug"


"$(INTDIR)\browse.obj"	"$(INTDIR)\browse.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"


!ELSEIF  "$(CFG)" == "browse - Win32 ReleaseRetail"


"$(INTDIR)\browse.obj"	"$(INTDIR)\browse.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"


!ENDIF 

SOURCE=.\browse.rc

"$(INTDIR)\browse.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "browse - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O1 /I "..\..\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "STRICT" /Fp"$(INTDIR)\browse.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\browse.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "browse - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /I "..\..\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "STRICT" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\browse.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.sbr"	"$(INTDIR)\browse.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "browse - Win32 ReleaseRetail"

CPP_SWITCHES=/nologo /MT /W3 /GX /O1 /I "..\..\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "STRICT" /D "FLICKER_FREE_COMCTL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\browse.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.sbr"	"$(INTDIR)\browse.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=..\..\include\behaviors\behavior_accesskeys.cpp

!IF  "$(CFG)" == "browse - Win32 Release"


"$(INTDIR)\behavior_accesskeys.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 Debug"


"$(INTDIR)\behavior_accesskeys.obj"	"$(INTDIR)\behavior_accesskeys.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 ReleaseRetail"


"$(INTDIR)\behavior_accesskeys.obj"	"$(INTDIR)\behavior_accesskeys.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\include\behaviors\behavior_actions.cpp

!IF  "$(CFG)" == "browse - Win32 Release"


"$(INTDIR)\behavior_actions.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 Debug"


"$(INTDIR)\behavior_actions.obj"	"$(INTDIR)\behavior_actions.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 ReleaseRetail"


"$(INTDIR)\behavior_actions.obj"	"$(INTDIR)\behavior_actions.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\include\behaviors\behavior_clock.cpp

!IF  "$(CFG)" == "browse - Win32 Release"


"$(INTDIR)\behavior_clock.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 Debug"


"$(INTDIR)\behavior_clock.obj"	"$(INTDIR)\behavior_clock.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 ReleaseRetail"


"$(INTDIR)\behavior_clock.obj"	"$(INTDIR)\behavior_clock.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\include\behaviors\behavior_collapsible_by_icon.cpp

!IF  "$(CFG)" == "browse - Win32 Release"


"$(INTDIR)\behavior_collapsible_by_icon.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 Debug"


"$(INTDIR)\behavior_collapsible_by_icon.obj"	"$(INTDIR)\behavior_collapsible_by_icon.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 ReleaseRetail"


"$(INTDIR)\behavior_collapsible_by_icon.obj"	"$(INTDIR)\behavior_collapsible_by_icon.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\include\behaviors\behavior_command.cpp

!IF  "$(CFG)" == "browse - Win32 Release"


"$(INTDIR)\behavior_command.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 Debug"


"$(INTDIR)\behavior_command.obj"	"$(INTDIR)\behavior_command.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 ReleaseRetail"


"$(INTDIR)\behavior_command.obj"	"$(INTDIR)\behavior_command.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\include\behaviors\behavior_editable_select.cpp

!IF  "$(CFG)" == "browse - Win32 Release"


"$(INTDIR)\behavior_editable_select.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 Debug"


"$(INTDIR)\behavior_editable_select.obj"	"$(INTDIR)\behavior_editable_select.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 ReleaseRetail"


"$(INTDIR)\behavior_editable_select.obj"	"$(INTDIR)\behavior_editable_select.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\include\behaviors\behavior_expandable_list.cpp

!IF  "$(CFG)" == "browse - Win32 Release"


"$(INTDIR)\behavior_expandable_list.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 Debug"


"$(INTDIR)\behavior_expandable_list.obj"	"$(INTDIR)\behavior_expandable_list.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 ReleaseRetail"


"$(INTDIR)\behavior_expandable_list.obj"	"$(INTDIR)\behavior_expandable_list.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\include\behaviors\behavior_form.cpp

!IF  "$(CFG)" == "browse - Win32 Release"


"$(INTDIR)\behavior_form.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 Debug"


"$(INTDIR)\behavior_form.obj"	"$(INTDIR)\behavior_form.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 ReleaseRetail"


"$(INTDIR)\behavior_form.obj"	"$(INTDIR)\behavior_form.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\include\behaviors\behavior_grid.cpp

!IF  "$(CFG)" == "browse - Win32 Release"


"$(INTDIR)\behavior_grid.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 Debug"


"$(INTDIR)\behavior_grid.obj"	"$(INTDIR)\behavior_grid.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 ReleaseRetail"


"$(INTDIR)\behavior_grid.obj"	"$(INTDIR)\behavior_grid.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\include\behaviors\behavior_hyperlink.cpp
SOURCE=..\..\include\behaviors\behavior_path.cpp

!IF  "$(CFG)" == "browse - Win32 Release"


"$(INTDIR)\behavior_path.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 Debug"


"$(INTDIR)\behavior_path.obj"	"$(INTDIR)\behavior_path.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 ReleaseRetail"


"$(INTDIR)\behavior_path.obj"	"$(INTDIR)\behavior_path.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\include\behaviors\behavior_popup.cpp

!IF  "$(CFG)" == "browse - Win32 Release"


"$(INTDIR)\behavior_popup.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 Debug"


"$(INTDIR)\behavior_popup.obj"	"$(INTDIR)\behavior_popup.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 ReleaseRetail"


"$(INTDIR)\behavior_popup.obj"	"$(INTDIR)\behavior_popup.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\include\behaviors\behavior_scroller.cpp

!IF  "$(CFG)" == "browse - Win32 Release"


"$(INTDIR)\behavior_scroller.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 Debug"


"$(INTDIR)\behavior_scroller.obj"	"$(INTDIR)\behavior_scroller.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 ReleaseRetail"


"$(INTDIR)\behavior_scroller.obj"	"$(INTDIR)\behavior_scroller.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\include\behaviors\behavior_select_buddy.cpp

!IF  "$(CFG)" == "browse - Win32 Release"


"$(INTDIR)\behavior_select_buddy.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 Debug"

!ELSEIF  "$(CFG)" == "browse - Win32 ReleaseRetail"


"$(INTDIR)\behavior_select_buddy.obj"	"$(INTDIR)\behavior_select_buddy.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\include\behaviors\behavior_select_checkmark.cpp

!IF  "$(CFG)" == "browse - Win32 Release"


"$(INTDIR)\behavior_select_checkmark.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 Debug"


"$(INTDIR)\behavior_select_checkmark.obj"	"$(INTDIR)\behavior_select_checkmark.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 ReleaseRetail"


"$(INTDIR)\behavior_select_checkmark.obj"	"$(INTDIR)\behavior_select_checkmark.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\include\behaviors\behavior_shellicon.cpp

!IF  "$(CFG)" == "browse - Win32 Release"


"$(INTDIR)\behavior_shellicon.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 Debug"


"$(INTDIR)\behavior_shellicon.obj"	"$(INTDIR)\behavior_shellicon.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 ReleaseRetail"


"$(INTDIR)\behavior_shellicon.obj"	"$(INTDIR)\behavior_shellicon.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\include\behaviors\behavior_splitter.cpp

!IF  "$(CFG)" == "browse - Win32 Release"


"$(INTDIR)\behavior_splitter.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 Debug"


"$(INTDIR)\behavior_splitter.obj"	"$(INTDIR)\behavior_splitter.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 ReleaseRetail"


"$(INTDIR)\behavior_splitter.obj"	"$(INTDIR)\behavior_splitter.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\include\behaviors\behavior_tabs.cpp

!IF  "$(CFG)" == "browse - Win32 Release"


"$(INTDIR)\behavior_tabs.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 Debug"


"$(INTDIR)\behavior_tabs.obj"	"$(INTDIR)\behavior_tabs.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 ReleaseRetail"


"$(INTDIR)\behavior_tabs.obj"	"$(INTDIR)\behavior_tabs.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\include\behaviors\behavior_virtual_grid.cpp

!IF  "$(CFG)" == "browse - Win32 Release"


"$(INTDIR)\behavior_virtual_grid.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 Debug"


"$(INTDIR)\behavior_virtual_grid.obj"	"$(INTDIR)\behavior_virtual_grid.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 ReleaseRetail"


"$(INTDIR)\behavior_virtual_grid.obj"	"$(INTDIR)\behavior_virtual_grid.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\include\behaviors\data_source_behavior.cpp

!IF  "$(CFG)" == "browse - Win32 Release"


"$(INTDIR)\data_source_behavior.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 Debug"


"$(INTDIR)\data_source_behavior.obj"	"$(INTDIR)\data_source_behavior.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "browse - Win32 ReleaseRetail"


"$(INTDIR)\data_source_behavior.obj"	"$(INTDIR)\data_source_behavior.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\browse.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

!IF  "$(CFG)" == "browse - Win32 Release"

"HTMLayout - Win32 Release" : 
   cd "\layout\hsmile.v3\HTMLayout"
   $(MAKE) /$(MAKEFLAGS) /F .\HTMLayout.mak CFG="HTMLayout - Win32 Release" 
   cd "..\..\HTMLayoutSDK\wtl\browse"

"HTMLayout - Win32 ReleaseCLEAN" : 
   cd "\layout\hsmile.v3\HTMLayout"
   $(MAKE) /$(MAKEFLAGS) /F .\HTMLayout.mak CFG="HTMLayout - Win32 Release" RECURSE=1 CLEAN 
   cd "..\..\HTMLayoutSDK\wtl\browse"

!ELSEIF  "$(CFG)" == "browse - Win32 Debug"

"HTMLayout - Win32 Debug" : 
   cd "\layout\hsmile.v3\HTMLayout"
   $(MAKE) /$(MAKEFLAGS) /F .\HTMLayout.mak CFG="HTMLayout - Win32 Debug" 
   cd "..\..\HTMLayoutSDK\wtl\browse"

"HTMLayout - Win32 DebugCLEAN" : 
   cd "\layout\hsmile.v3\HTMLayout"
   $(MAKE) /$(MAKEFLAGS) /F .\HTMLayout.mak CFG="HTMLayout - Win32 Debug" RECURSE=1 CLEAN 
   cd "..\..\HTMLayoutSDK\wtl\browse"

!ELSEIF  "$(CFG)" == "browse - Win32 ReleaseRetail"

"HTMLayout - Win32 ReleaseRetail" : 
   cd "\layout\hsmile.v3\HTMLayout"
   $(MAKE) /$(MAKEFLAGS) /F .\HTMLayout.mak CFG="HTMLayout - Win32 ReleaseRetail" 
   cd "..\..\HTMLayoutSDK\wtl\browse"

"HTMLayout - Win32 ReleaseRetailCLEAN" : 
   cd "\layout\hsmile.v3\HTMLayout"
   $(MAKE) /$(MAKEFLAGS) /F .\HTMLayout.mak CFG="HTMLayout - Win32 ReleaseRetail" RECURSE=1 CLEAN 
   cd "..\..\HTMLayoutSDK\wtl\browse"

!ENDIF 


!ENDIF 

