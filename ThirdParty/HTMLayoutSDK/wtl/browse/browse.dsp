# Microsoft Developer Studio Project File - Name="browse" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=browse - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "browse.mak".
!MESSAGE 
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

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "browse - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /Zi /O1 /Op /Ob2 /I "." /I "..\..\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "STRICT" /FD /c
# SUBTRACT CPP /Fr /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386 /out:"../../bin/browse.exe" /libpath:"..\..\lib"
# SUBTRACT LINK32 /profile /pdb:none /map /debug

!ELSEIF  "$(CFG)" == "browse - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "STRICT" /FR /YX"stdafx.h behavior_aux.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ../../lib/htmlayout.lib /nologo /subsystem:windows /map /debug /machine:I386 /out:"../../bin/browse.exe" /pdbtype:sept /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "browse - Win32 ReleaseRetail"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "browse___Win32_ReleaseRetail"
# PROP BASE Intermediate_Dir "browse___Win32_ReleaseRetail"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "ReleaseRetail"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /O1 /I "..\..\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "STRICT" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O1 /I "..\..\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "STRICT" /D "FLICKER_FREE_COMCTL" /FR /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 ../../lib/HTMLayout.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386 /out:"../../bin/browse.exe"
# ADD LINK32 ../../lib/HTMLayout.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386 /out:"../../binr/browse.exe" /libpath:"..\..\lib"
# SUBTRACT LINK32 /profile

!ENDIF 

# Begin Target

# Name "browse - Win32 Release"
# Name "browse - Win32 Debug"
# Name "browse - Win32 ReleaseRetail"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\browse.cpp
# End Source File
# Begin Source File

SOURCE=.\browse.rc
# End Source File
# Begin Source File

SOURCE=.\stdafx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\aboutdlg.h
# End Source File
# Begin Source File

SOURCE="..\..\include\aux-cvt.h"
# End Source File
# Begin Source File

SOURCE="..\..\include\aux-slice.h"
# End Source File
# Begin Source File

SOURCE=..\..\include\behaviors\behavior_aux.h
# End Source File
# Begin Source File

SOURCE=..\..\include\htmlayout.h
# End Source File
# Begin Source File

SOURCE=..\..\include\htmlayout_aux.h
# End Source File
# Begin Source File

SOURCE=..\..\include\htmlayout_behavior.h
# End Source File
# Begin Source File

SOURCE=..\..\include\htmlayout_behavior.hpp
# End Source File
# Begin Source File

SOURCE=..\..\include\htmlayout_canvas.hpp
# End Source File
# Begin Source File

SOURCE=..\..\include\htmlayout_controls.hpp
# End Source File
# Begin Source File

SOURCE=..\..\include\htmlayout_dialog.hpp
# End Source File
# Begin Source File

SOURCE=..\..\include\htmlayout_dom.h
# End Source File
# Begin Source File

SOURCE=..\..\include\htmlayout_dom.hpp
# End Source File
# Begin Source File

SOURCE=..\..\include\htmlayout_graphin.h
# End Source File
# Begin Source File

SOURCE=..\..\include\htmlayout_notifications.hpp
# End Source File
# Begin Source File

SOURCE=..\..\include\htmlayout_queue.h
# End Source File
# Begin Source File

SOURCE=..\..\include\htmlayout_value.hpp
# End Source File
# Begin Source File

SOURCE=..\..\include\htmlayout_x.h
# End Source File
# Begin Source File

SOURCE=.\HtmlBar.h
# End Source File
# Begin Source File

SOURCE=..\..\include\htmlite.h
# End Source File
# Begin Source File

SOURCE=.\htmlview.h
# End Source File
# Begin Source File

SOURCE=..\..\include\htmprint.h
# End Source File
# Begin Source File

SOURCE=.\mainfrm.h
# End Source File
# Begin Source File

SOURCE=..\..\include\behaviors\notifications.h
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=.\stdafx.h
# End Source File
# Begin Source File

SOURCE=..\..\include\value.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wtl_htmlayout.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wtl_htmlayouthost.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wtl_htmlayoutvalues.h
# End Source File
# Begin Source File

SOURCE=..\..\include\wtl_value.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\browse.exe.manifest
# End Source File
# Begin Source File

SOURCE=.\res\browse.ico
# End Source File
# Begin Source File

SOURCE=.\res\empty.htm
# End Source File
# Begin Source File

SOURCE=.\res\open.png
# End Source File
# Begin Source File

SOURCE=.\res\toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\toolbar.htm
# End Source File
# End Group
# Begin Group "Behaviors"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\include\behaviors\behavior_accesskeys.cpp
# End Source File
# Begin Source File

SOURCE=..\..\include\behaviors\behavior_actions.cpp
# End Source File
# Begin Source File

SOURCE=..\..\include\behaviors\behavior_chart.cpp
# End Source File
# Begin Source File

SOURCE=..\..\include\behaviors\behavior_clock.cpp
# End Source File
# Begin Source File

SOURCE=..\..\include\behaviors\behavior_clock_graphin.cpp
# End Source File
# Begin Source File

SOURCE=..\..\include\behaviors\behavior_collapsible_by_icon.cpp
# End Source File
# Begin Source File

SOURCE=..\..\include\behaviors\behavior_command.cpp
# End Source File
# Begin Source File

SOURCE=..\..\include\behaviors\behavior_editable_select.cpp
# End Source File
# Begin Source File

SOURCE=..\..\include\behaviors\behavior_expandable_list.cpp
# End Source File
# Begin Source File

SOURCE=..\..\include\behaviors\behavior_font_size.cpp
# End Source File
# Begin Source File

SOURCE=..\..\include\behaviors\behavior_form.cpp
# End Source File
# Begin Source File

SOURCE=..\..\include\behaviors\behavior_grid.cpp
# End Source File
# Begin Source File

SOURCE=..\..\include\behaviors\behavior_gripper.cpp
# End Source File
# Begin Source File

SOURCE=..\..\include\behaviors\behavior_hover.cpp
# End Source File
# Begin Source File

SOURCE=..\..\include\behaviors\behavior_hyperlink.cpp
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=..\..\include\behaviors\behavior_lb_dialog.cpp
# End Source File
# Begin Source File

SOURCE=..\..\include\behaviors\behavior_path.cpp
# End Source File
# Begin Source File

SOURCE=..\..\include\behaviors\behavior_popup.cpp
# End Source File
# Begin Source File

SOURCE=..\..\include\behaviors\behavior_rtc_current_objects.cpp
# End Source File
# Begin Source File

SOURCE=..\..\include\behaviors\behavior_scroller.cpp
# End Source File
# Begin Source File

SOURCE=..\..\include\behaviors\behavior_select_buddy.cpp

!IF  "$(CFG)" == "browse - Win32 Release"

!ELSEIF  "$(CFG)" == "browse - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "browse - Win32 ReleaseRetail"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\include\behaviors\behavior_select_checkmark.cpp
# End Source File
# Begin Source File

SOURCE=..\..\include\behaviors\behavior_shellicon.cpp
# End Source File
# Begin Source File

SOURCE=..\..\include\behaviors\behavior_sizer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\include\behaviors\behavior_splitter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\include\behaviors\behavior_tabs.cpp
# End Source File
# Begin Source File

SOURCE=..\..\include\behaviors\behavior_virtual_grid.cpp
# End Source File
# Begin Source File

SOURCE=..\..\include\behaviors\data_source_behavior.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\res\back.png
# End Source File
# Begin Source File

SOURCE=.\res\debug.png
# End Source File
# Begin Source File

SOURCE=.\res\forward.png
# End Source File
# Begin Source File

SOURCE=.\res\html1.htm
# End Source File
# Begin Source File

SOURCE=.\res\input1.htm
# End Source File
# Begin Source File

SOURCE=.\res\new_win.png
# End Source File
# Begin Source File

SOURCE=".\res\note-icon.png"
# End Source File
# Begin Source File

SOURCE=.\res\recent.png
# End Source File
# Begin Source File

SOURCE=.\res\refresh.png
# End Source File
# Begin Source File

SOURCE=".\res\std-menu.css"
# End Source File
# Begin Source File

SOURCE=.\res\view_source.png
# End Source File
# End Target
# End Project
