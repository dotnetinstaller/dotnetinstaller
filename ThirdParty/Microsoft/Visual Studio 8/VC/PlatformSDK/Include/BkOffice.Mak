#----------------------------------------------------------------------------
#
# Description:
#   Make File Header for BackOffice Software Development Kit
#
# Copyright:
#   Copyright (C) Microsoft Corp. 1986-1999. All Rights Reserved.
#
#----------------------------------------------------------------------------

!ifndef BASEMAKE_INCLUDED       # Prevent multiple inclusions
BASEMAKE_INCLUDED = 1


#*********************************************
#
# Parameter Checking and Defaults
#
#*********************************************
!ifndef Proj
!     ERROR Component name (Proj) has not been defined.
!endif

!ifndef INCLUDE
!   ERROR INCLUDE variable is empty; must include at least system include directory
!endif

!ifndef LIB
!   ERROR LIB variable is empty; must include at least system lib directory
!endif

!if defined(clean)
$(Proj): Clean
!else
$(Proj): All
!endif

!if defined(nodebug)
BLDTYPE=Retail
!endif

!if "$(BLDTYPE)" == "Retail" | "$(BLDTYPE)" == "RETAIL" | "$(BLDTYPE)" == "retail" | "$(BLDTYPE)" == "RTL" | "$(BLDTYPE)" == "rtl"
BLDTYPE1=Retail
!else if "$(BLDTYPE)" == "Profile" | "$(BLDTYPE)" == "PROFILE" | "$(BLDTYPE)" == "profile"
BLDTYPE1=Profile
!else if "$(BLDTYPE)" == "Debug" | "$(BLDTYPE)" == "DEBUG" | "$(BLDTYPE)" == "debug" | "$(BLDTYPE)" == "DBG" | "$(BLDTYPE)" == "dbg"
BLDTYPE1=Debug
!else ifndef BLDTYPE
BLDTYPE1=Debug
!else
!   ERROR BLDTYPE must be either Retail, Profile or Debug.
!endif   

!if "$(BLDTYPE1)" == "Retail"
nodebug=1
!endif

!ifndef PLATFORM
PLATFORM=Win32
!endif   

!ifndef CALL
CALL=C
!endif

!ifndef PACK
PACK=YES
!endif

# Default to logging to stdout.

!ifndef LOG
LOG=NO
!endif

!ifndef WARNING_LEVEL
WARNING_LEVEL=3
!endif

!ifndef CPU
CPU=i386
!ifndef PROCESSOR_ARCHITECTURE
#!ERROR CPU and PROCESSOR_ARCHITECTURE variables are empty; at least one must be defined
!endif
CPU=$(PROCESSOR_ARCHITECTURE)
!if "$(CPU)"=="x86" | "$(CPU)"=="X86"
CPU = i386
!endif
!endif

!ifndef APPVER
APPVER=5.0
!endif

!ifndef USE_EXCHANGE
!include <Win32.Mak>

!endif

# Save build args for any recursive nmakes 
BLDARGS= BLDTYPE=$(BLDTYPE) PLATFORM=$(PLATFORM) LOG=$(LOG) CPU=$(CPU) 

#*********************************************
#
# Paths
#
#*********************************************

!ifndef BKOFFICE
!ifdef PROJROOT
BKOFFICE=$(PROJROOT)\        # must add trailing backslash
!else
BKOFFICE=\BkOffice\          # assume a reasonable default
!endif
!endif

!ifdef MAKEDIRS
MkDest=
!include $(MAKEDIRS)
!else
ResDir=.
ObjDir=.\$(PLATFORM)\$(BLDTYPE1)
IncDir=$(BKOFFICE)Include
LibDir=$(BKOFFICE)Lib

!if "$(APPVER)" == "5.01"
INCLUDE=$(INCLUDE);$(ObjDir);$(IncDir);
!ELSE
INCLUDE=$(ObjDir);$(IncDir);$(INCLUDE);
!ENDIF
LIB=$(LibDir);$(LIB);

# Win95 doesn't support "&" on command line
MkDest=@for %d in ("$(PLATFORM)" "$(ObjDir)") do $(COMSPEC) /c if not exist %d md %d

!endif

#*********************************************
#
# Tools
#
#*********************************************

# Check to see if Cole Porter is used

!ifndef SUBSTITUTE_CC
!ifdef COLE_64
SUBSTITUTE_CC = Port64
!endif
!endif

!ifndef CC_NAME
!if "$(SUBSTITUTE_CC)" != ""
CC_NAME = "$(SUBSTITUTE_CC)"
LINK_NAME = Rem no Link under Cole
!else
CC_NAME   = Cl
LINK_NAME = Link
!endif
!endif

MAKEEXE = NMake
IMPLIB  = Lib
CC      = $(CC_NAME)
LIBU    = Lib
LINK    = $(LINK_NAME)
RC      = Rc
MC      = Mc
MIDL    = Midl
HC      = Start /Wait Hcrtf


#*********************************************
#
# Flags
#
#*********************************************

# CL is for all C and C++ files
#   -WX     Warnings as errors
#   -J      char becomes unsigned char
#   
CL=$(cflags) -c -w -J -Fo$@ /nologo $(CL)

# LFLAGS is for all links
LFLAGS=-NOLOGO /NODEFAULTLIB:LIBC -machine:$(CPU) -out:$@ -INCREMENTAL:NO $(LFLAGS)


# DLLFLAGS is for linking DLLs
DLLFLAGS=-DLL -map:"$(ObjDir)\$(@B).Map" $(DLLFLAGS)

# LIBFLAGS is for making libraries
LIBFLAGS=-NOLOGO -MACHINE:$(CPU) -out:"$@" $(LIBFLAGS) 

# RFLAGS is for Windows resources
RFLAGS= -I$(ResDir) -fo$@ -DWIN32 $(noansi) -r -D_WIN32 $(RFLAGS) 

# MFLAGS is for the message compiler
MFLAGS=-v -c -s -h "$(ObjDir)" -r "$(ObjDir)" -x "$(ObjDir)" $(MFLAGS)

# MRFLAGS is for the resource compiler when used after the message compiler
MRFLAGS=-l 409 -r -x -i"$(ObjDir)" $(MRFLAGS)

# HFLAGS is for the help compiler 
HFLAGS=-xn

#---------------------------------------------
# Calling convention Flag
#---------------------------------------------

!if "$(CALL)"=="PASCAL"
CL=-Gc $(CL)
!endif

#---------------------------------------------
# Function Packaging Flag
#---------------------------------------------

!if "$(PACK)" == "YES"
CL=-Gy $(CL)
cDefines=-Gy $(cDefines)
!endif

#---------------------------------------------
# Output Redirection
#---------------------------------------------
!if "$(LOG)" == "NO"
LogCmd=
!else
LogCmd= >> "$(ObjDir)\$(Proj).Out"
!endif 

#---------------------------------------------
# select specific library based on target type
#---------------------------------------------
!if "$(BLDTYPE1)"=="Retail"
DbgLibFlag =
!else
DbgLibFlag = d
!endif

!if defined(unicode)
UnicodeLibFlag = u
!else
UnicodeLibFlag =
!endif

#---------------------------------------------
# Optimization Flags
#---------------------------------------------
!if "$(BLDTYPE1)" == "Retail"
CL=-O2 $(CL)
!else if "$(BLDTYPE1)" == "Profile"
CL=-Od -Z7 -Gh $(CL)
!else
CL=-Od -Z7 $(CL)
!endif

#---------------------------------------------
# PLATFORM specific Flags
#---------------------------------------------
!if "$(CPU)" == "I386"
CL = $(CL) -D_X86_=1
scall  = -Gz
lflags   = $(lflags) -align:0x1000
!endif

!if "$(CPU)" == "ALPHA"
CL = $(CL) -D_ALPHA_=1
scall  =
!endif

#---------------------------------------------
# Windows version
#---------------------------------------------
!if "$(APPVER)" == "4.0"
CL = $(CL) -DWINVER=0x0400
rflags=$(rflags) -DWINVER=0x0400
!endif

#---------------------------------------------
# Additional MFC Flags
#---------------------------------------------

!ifdef Use_MFC
CL= $(CL) /GX /DSTRICT /DWIN32 /D_WINDOWS /D_MBCS /D_WINDLL 
CL= $(CL) /D_USRDLL -D_AFX_NO_BSTR_SUPPORT /D_AFXDLL

RFLAGS = $(RFLAGS) /DSTRICT /DWIN32 /D_WINDOWS /D_MBCS /D_WINDLL /D_USRDLL -D_AFX_NO_BSTR_SUPPORT /D_AFXDLL

!if "$(BLDTYPE1)"=="Debug"
CL= $(CL) /D_DEBUG
RFLAGS = $(RFLAGS) /D_DEBUG
!endif # BLDTYPE == Debug

!ifdef crtdll                                 # Use DLL CRT? (which is multithreaded)
crtflags = -MD$(DbgLibFlag) $(crtflags)
!elseif defined(crtst) && !defined(crtflags)  # use Single Threaded CRT?
crtflags = -ML$(DbgLibFlag) $(crtflags)
!elseif defined(crtmt)                        # use Multithreaded CRT?
crtflags = -MT$(DbgLibFlag) $(crtflags)
!else                                         # default to crtdll
crtflags = -MD$(DbgLibFlag) $(crtflags)
!endif                                        # ifdef crtdll/else crtst/crtmt/else

!endif

#---------------------------------------------
# Build Type Flags  (Retail/Debug)
#---------------------------------------------

!if "$(BLDTYPE1)"=="Retail"
CL=-DSHIP $(CL)
LFLAGS = $(LFLAGS) -RELEASE
!else if "$(BLDTYPE1)"=="Profile"
CL=-DDEBUG -DTEST -DPROFILE $(CL)
LFLAGS = $(LFLAGS) -DEBUG:mapped,partial -DEBUGTYPE:coff -PROFILE
libs = $(libs) CAP.Lib
!else 
CL=-DDEBUG -DTEST $(CL) 
LFLAGS = $(LFLAGS) -debug:full -debugtype:cv
!endif


#---------------------------------------------
# Determine CRT Flags
#---------------------------------------------

!ifdef crtdll                                 # Use DLL CRT? (which is multithreaded)
crtflags = -MD$(DbgLibFlag) $(crtflags)
!elseif defined(crtst) && !defined(crtflags)  # use Single Threaded CRT?
crtflags = -ML$(DbgLibFlag) $(crtflags)
!elseif defined(crtmt)                        # use Multithreaded CRT?
crtflags = -MT$(DbgLibFlag) $(crtflags)
!else                                         # default to crtdll
crtflags = -MD$(DbgLibFlag) $(crtflags)
!endif                                        # ifdef crtdll/else crtst/crtmt/else

#---------------------------------------------
# Determine app type Flags (console, gui, or DLL)
#---------------------------------------------

!if defined(unicode)
crtflags=-D UNICODE -D _UNICODE $(crtflags)
!endif #unicode

!if defined(console)                          # console app
!if !defined(unicode)
linkflags=$(linkflags) -subsystem:console -entry:mainCRTStartup
!else
linkflags=$(linkflags) -subsystem:console -entry:wmainCRTStartup
!endif #unicode
!elseif !defined(dll)                         # not a dll, default to gui app
!if !defined(unicode)
linkflags=$(linkflags) -subsystem:windows -entry:WinMainCRTStartup
!else
linkflags=$(linkflags) -subsystem:windows -entry:wWinMainCRTStartup
!endif #unicode
!endif                                        # ifdef console/else

#*********************************************
#
# Libraries
#
#*********************************************

#---------------------------------------------
# Back Office SDK specific
#---------------------------------------------
!ifdef USE_SNA
libs=$(libs) fmistr32.Lib ihvLink.Lib snacli.Lib wappc32.Lib wcpic32.Lib
libs=$(libs) wincsv32.Lib winrui32.Lib winsli32.Lib
!endif # USE_SNA

!ifdef USE_SQL
libs=$(libs) ntwdbLib.Lib
!endif # USE_SQL

!ifdef USE_ODS
libs=$(libs) opends60.Lib
!endif # USE_ODS

!ifdef USE_DTC
libs=$(libs) XOleHlp.Lib
!endif # USE_ODS

!ifdef USE_ODBC
libs=$(libs) odbc32.Lib odbccp32.Lib
!endif # USE_ODS

!if defined(USE_MSM) || defined(USE_SMS)
libs=$(libs) smsapi.Lib objectty.Lib
!endif # USE_MSM || USE_SMS

!ifdef USE_NETMON
libs=$(libs) bhmon.Lib bhsupp.Lib filter.Lib friendly.Lib
libs=$(libs) hexedit.Lib  nal.Lib nmapi.Lib
libs=$(libs) parser.Lib slbs.Lib toolbar.Lib
!endif # USE_NETMON

!ifdef USE_EXCHANGE
!  ifndef Building_ExchSDK
libs="ExchSDK$(DbgLibFlag).Lib" $(libs)
!  endif # Building_ExchSDK

# Note: when using MFC for Exchange Admin
# extension dlls they must be statically linked to MFC.

libs=$(libs) Mapi32.Lib Uuid.Lib

!if "$(WARNING_LEVEL)" != "4"
CL= $(CL) -WX
!endif

DLLFLAGS = $(DLLFLAGS) -def:$(@B).def
!endif # USE_EXCHANGE

#---------------------------------------------
# Determine CRT Libraries
#---------------------------------------------
libc = libc$(DbgLibFlag).Lib oldnames.Lib
libcmt = libcmt$(DbgLibFlag).Lib oldnames.Lib
libcdll = msvcrt$(DbgLibFlag).Lib oldnames.Lib

!ifdef crtdll                                 # Use DLL CRT?
libcrt=$(libcdll)
!elseif defined(crtst) && !defined(crtflags)  # use Single Threaded CRT?
libcrt=$(libc)
!elseif defined(crtmt)                        # use Multithreaded CRT?
libcrt=$(libcmt)
!else                                         # default to crtdll
libcrt=$(libcdll)
!endif                                        # endif crtdll/else crtst/crtmt/else

#---------------------------------------------
# Determine app type libraries (console, gui, or DLL)
#---------------------------------------------

!ifdef dll                                    # is this a DLL?
linklibs=$(libs) kernel32.Lib advapi32.Lib user32.Lib gdi32.Lib comctl32.Lib comdlg32.Lib ole32.Lib winspool.Lib version.Lib
!elseif defined(console)                      # not a DLL, perhaps a console app
linklibs=$(libs) kernel32.Lib advapi32.Lib user32.Lib ole32.Lib version.Lib
!else                                         # default to gui app
linklibs=$(libs) kernel32.Lib $(optlibs) advapi32.Lib user32.Lib gdi32.Lib comdlg32.Lib ole32.Lib winspool.Lib version.Lib
!endif                                        # ifdef dll/else console/else

#LinkLibs = $(LibList) $(linklibs) $(libcrt)
# do not specify CRT libs if using MFC, let MFC fix this up in the default libs
!ifdef Use_MFC
LinkLibs = $(LibList) $(linklibs)
!else
LinkLibs = $(LibList) $(linklibs) $(libcrt)
!endif

#if necessary, force MSVCRT to be included in lib list
!ifdef Use_MSCRT
LinkLibs = $(LinkLibs) $(libcrt)
!endif

!if "$(BLDTYPE1)" == "Profile"
LinkLibs = $(LinkLibs) cap.Lib
!endif

#---------------------------------------------
# Additional MFC Libraries
#---------------------------------------------
# Note that linking order is important when using MFC!

!ifdef Use_MFC
!if !defined(nodebug)
linklibs = mfco42$(UnicodeLibFlag)$(DbgLibFlag).Lib $(linklibs)
!endif
linklibs = mfcs42$(UnicodeLibFlag)$(DbgLibFlag).Lib mfc42$(UnicodeLibFlag)$(DbgLibFlag).Lib $(linklibs)
!endif


#*********************************************
#
# Inference Rules
#
#*********************************************
.SUFFIXES: .c .Cpp .Cxx .Obj .Def .Lib .Dll .Exe .Idl .h .Mc .Rc .Res .Exp .Bin .Hpj .Ini .Pdb .Trg .Ocx .Tlb .Res .Srl .Odl

# C Targets
.c{$(ObjDir)\}.Obj:
    $(MkDest)
!if "$(LOG)"=="YES"
    @echo $(CC) $(CL) $(crtflags) $(cDefines) $< $(LogCmd)
!endif
    $(CC) $(CL) $(crtflags) $(cDefines) $< $(LogCmd)

# C++ Targets
.cpp{$(ObjDir)\}.Obj:
    $(MkDest)
!if "$(LOG)"=="YES"
    @echo $(CC) $(CL) $(crtflags) $(cDefines) $< $(LogCmd)
!endif
    $(CC) $(CL) $(crtflags) $(cDefines) $< $(LogCmd)

# C++ Targets
.cxx{$(ObjDir)\}.obj:
    $(MkDest)
!if "$(LOG)"=="YES"
    @echo $(CC) $(CL) $(crtflags) $(cDefines) $< $(LogCmd)
!endif
    $(CC) $(CL) $(crtflags) $(cDefines) $< $(LogCmd)

# Resource Targets from .RC files
{$(ResDir)\}.Rc{$(ObjDir)\}.Res:
    $(MkDest)
!if "$(LOG)"=="YES"
    @echo $(RC) $(RFLAGS) $(ResDir)\$(@B).rc $(LogCmd)
!endif
    $(RC) $(RFLAGS) $(ResDir)\$(@B).rc $(LogCmd)

# Resource Targets from .MC files
.Mc{$(ObjDir)\}.Res:
    $(MkDest)
!if "$(LOG)"=="YES"
    @echo $(MC) $(MFLAGS) $< $(LogCmd)
!endif
    $(MC) $(MFLAGS) $< $(LogCmd)
!if "$(LOG)"=="YES"
    @echo $(RC) $(MRFLAGS) -fo$@ "$(ObjDir)\$(@B).rc" $(LogCmd)
!endif
    $(RC) $(MRFLAGS) -fo$@ "$(ObjDir)\$(@B).rc" $(LogCmd)

# Import Libraries
.Def{$(ObjDir)\}.Lib:
!if "$(LOG)"=="YES"
    @echo $(IMPLIB) -NOLOGO -MACHINE:$(CPU) -DEF:$(@B).DEF -OUT:$@ $(LogCmd)
!endif
    $(IMPLIB) -NOLOGO -MACHINE:$(CPU) -DEF:$(@B).DEF -OUT:$@ $(LogCmd)
    set copycmd=/Y
    xcopy "$@" "$(LibDir)\" $(LogCmd)

.Def{$(ObjDir)\}.Exp:
!if "$(LOG)"=="YES"
    @echo $(IMPLIB) -NOLOGO -MACHINE:$(CPU) -DEF:$(@B).DEF -OUT:"$(@R).Lib" $(LogCmd)
!endif
    $(IMPLIB) -NOLOGO -MACHINE:$(CPU) -DEF:$(@B).DEF -OUT:"$(@R).Lib" $(LogCmd)

# Static Libraries
{$(ObjDir)\}.Obj{$(ObjDir)\}.Lib:
!if "$(LOG)"=="YES"
    @echo $(LIBU) $(LIBFLAGS)  $** $(LogCmd)
!endif
    $(LIBU) $(LIBFLAGS) $** $(LogCmd)
!ifdef USE_EXCHANGE
!if "$(LOG)"=="YES"
    @echo xcopy "$(@R).Lib" "$(LibDir)" $(LogCmd)
!endif
    set copycmd=/Y
    -xcopy "$(@R).Lib" "$(LibDir)\" $(LogCmd)
!endif # USE_EXCHANGE

# DLLs
{$(ObjDir)\}.Obj{$(ObjDir)\}.Dll:
    @echo $** > "$(ObjDir)\objfiles.lst"
    @echo $(LinkLibs) > "$(ObjDir)\libfiles.lst"
!if "$(LOG)"=="YES"
    @echo   $(LINK) $(LFLAGS) $(DLLFLAGS) $(linkflags) "@$(ObjDir)\objfiles.lst" "@$(ObjDir)\libfiles.lst" $(LogCmd)
!endif
    $(LINK) $(LFLAGS) $(DLLFLAGS) $(linkflags) "@$(ObjDir)\objfiles.lst" "@$(ObjDir)\libfiles.lst" $(LogCmd)
!ifdef USE_EXCHANGE
!if "$(LOG)"=="YES"
    @echo xcopy "$(@R).Lib" "$(LibDir)" $(LogCmd)
!endif
    set copycmd=/Y
    -xcopy "$(@R).Lib" "$(LibDir)\" $(LogCmd)
!endif # USE_EXCHANGE

# OCXs
{$(ObjDir)\}.obj{$(ObjDir)\}.Ocx:
    @echo $** > "$(ObjDir)\objfiles.lst"
    @echo $(LinkLibs) > "$(ObjDir)\libfiles.lst"
!if "$(LOG)"=="YES"
    @echo   $(LINK) $(LFLAGS) $(DLLFLAGS) $(linkflags) "@$(ObjDir)\objfiles.lst" "@$(ObjDir)\libfiles.lst" $(LogCmd)
!endif
    $(LINK) $(LFLAGS) $(DLLFLAGS) $(linkflags) "@$(ObjDir)\objfiles.lst" "@$(ObjDir)\libfiles.lst" $(LogCmd)
!ifdef USE_EXCHANGE
!if "$(LOG)"=="YES"
    @echo xcopy "$(@R).Lib" "$(LibDir)" $(LogCmd)
!endif
    set copycmd=/Y
    -xcopy "$(@R).Lib" "$(LibDir)\" $(LogCmd)
!endif # USE_EXCHANGE

# BINs
{$(ObjDir)\}.Obj{$(ObjDir)\}.Bin:
    @echo $(LinkLibs) > "$(ObjDir)\libfiles.lst"
!if "$(LOG)"=="YES"
    @echo $(LINK) $(LFLAGS) $(linkflags) $** "@$(ObjDir)\libfiles.lst" $(LogCmd)
!endif
    $(LINK) $(LFLAGS) $(linkflags) $** "@$(ObjDir)\libfiles.lst" $(LogCmd)

# EXEs
{$(ObjDir)\}.Obj{$(ObjDir)\}.Exe:
    @echo $** > "$(ObjDir)\objfiles.lst"
    @echo $(LinkLibs) > "$(ObjDir)\libfiles.lst"
!if "$(LOG)"=="YES"
    @echo $(LINK) $(LFLAGS) $(linkflags) "@$(ObjDir)\objfiles.lst" "@$(ObjDir)\libfiles.lst" $(LogCmd)
!endif
    $(LINK) $(LFLAGS) $(linkflags) "@$(ObjDir)\objfiles.lst" "@$(ObjDir)\libfiles.lst" $(LogCmd)

# Helpfiles
.Hpj{$(ObjDir)\}.Hlp:
    $(MkDest)
!if "$(LOG)"=="YES"
    @echo  $(HC) $(HFLAGS) $(@B).Hpj
!endif
    $(HC) $(HFLAGS) $(@B).Hpj
!if "$(LOG)"=="YES"
    @echo   xcopy "$(@F)" "$(ObjDir)"
!endif
    set copycmd=/Y
    -xcopy "$(@F)" "$(ObjDir)" $(LogCmd)

# TRGs
{$(ObjDir)\}.Exe{$(ObjDir)\}.Trg:
	$(MkDest)
!if "$(LOG)"=="YES"
     @echo $? /RegServer "$(ObjDir)\regsvr32.Trg" $(LogCmd)
!endif
     @-$? /RegServer $(LogCmd)
     echo regsvr32 exec. time > "$(ObjDir)\regsvr32.Trg" $(LogCmd)

{$(ObjDir)\}.Dll{$(ObjDir)\}.Trg:
	$(MkDest)
!if "$(LOG)"=="YES"
     @echo regsvr32 /s $? regsvr32.trg 
!endif
     @-regsvr32 /s $? $(LogCmd)
     echo regsvr32 exec. time > "$(ObjDir)\regsvr32.Trg"

# .Hs
.Idl{$(ObjDir)\}.H:
    $(MkDest)
!if "$(LOG)"=="YES"
     @echo $(MIDL) /Oicf /out "$(ObjDir)" $** $(LogCmd)
!endif
     $(MIDL) /Oicf /out "$(ObjDir)" $** $(LogCmd)

# .Tlbs
.Odl{$(ObjDir)\}.Tlb:
	$(MkDest)
!if "$(LOG)"=="YES"
    @echo $(MIDL) /nologo /out "$(ObjDir)" $** $(LogCmd)
!endif
    $(MIDL) /nologo /out "$(ObjDir)" $** $(LogCmd)


#*********************************************
#
# Make Targets
#
#*********************************************

#---------------------------------------------
# List Output Files
#---------------------------------------------
ListDir:
    dir "$(ObjDir)"

#---------------------------------------------
# Display Output Listing File
#---------------------------------------------
!ifndef ERRVIEW
ERRVIEW=start notepad.Exe
!endif

ListOut:
    $(ERRVIEW) "$(ObjDir)\$(Proj).out"

#---------------------------------------------
# Delete Output Listing File
#---------------------------------------------
DelOut:
    del "$(ObjDir)\$(Proj).out"

#---------------------------------------------
# Clean Output Directories
#---------------------------------------------
clean:
 $(MkDest)
!if "$(OS)" == "Windows_NT"
 -del /q "$(ObjDir)\*.Obj" \
         "$(ObjDir)\*.out" \
         "$(ObjDir)\*.h"   \
         "$(ObjDir)\*.dbg" \
         "$(ObjDir)\*.Lib" \
         "$(ObjDir)\*.Exe" \
         "$(ObjDir)\*.Dll" \
         "$(ObjDir)\*.Map" \
         "$(ObjDir)\*.Res" \
         "$(ObjDir)\*.rc"  \
         "$(ObjDir)\*.bin" \
         "$(ObjDir)\*.lst" \
         "$(ObjDir)\*.blt" \
         "$(ObjDir)\*.hlp" \
         "$(ObjDir)\*.trg" \
         "$(ObjDir)\*.srl" \
         "$(ObjDir)\*.ini" \
         "$(ObjDir)\*.tlb" \
         "$(ObjDir)\*.pdb" \
         "$(ObjDir)\*.exp" >NUL 2>NUL
!else  # Win95 doesn't support "2>" on command line, multiple files on a Del command, or /q
 -erase  "$(ObjDir)\*.Obj" >NUL
 -erase  "$(ObjDir)\*.out" >NUL
 -erase  "$(ObjDir)\*.h"   >NUL
 -erase  "$(ObjDir)\*.dbg" >NUL
 -erase  "$(ObjDir)\*.Lib" >NUL
 -erase  "$(ObjDir)\*.Exe" >NUL
 -erase  "$(ObjDir)\*.Dll" >NUL
 -erase  "$(ObjDir)\*.Map" >NUL
 -erase  "$(ObjDir)\*.Res" >NUL
 -erase  "$(ObjDir)\*.rc"  >NUL
 -erase  "$(ObjDir)\*.bin" >NUL
 -erase  "$(ObjDir)\*.lst" >NUL
 -erase  "$(ObjDir)\*.blt" >NUL
 -erase  "$(ObjDir)\*.hlp" >NUL
 -erase  "$(ObjDir)\*.trg" >NUL
 -erase  "$(ObjDir)\*.srl" >NUL
 -erase  "$(ObjDir)\*.ini" >NUL
 -erase  "$(ObjDir)\*.pdb" >NUL
 -erase  "$(ObjDir)\*.exp" >NUL
 -erase  "$(ObjDir)\*.tlb" >NUL
 -erase  "$(ObjDir)\*.c"   >NUL
 -erase  "$(ObjDir)\*.trg" >NUL
!endif  # OS == Windows_NT
!endif      # BASEMAKE_INCLUDED
