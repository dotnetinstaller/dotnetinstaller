#----------------------------------------------------------------------------
#
# Descriptions:
#   Generic Make File Header for EDK
#
# Copyright:
#   Copyright (C) Microsoft Corp. 1993-1999.  All Rights Reserved.
#
#----------------------------------------------------------------------------


#*********************************************
# Check Component Name
#*********************************************

!ifndef COMP
!     ERROR Component name (COMP) has not been defined.
!endif


#*********************************************
# Parameter Defaults
#*********************************************

!ifndef BKOFFICE
BKOFFICE=c:\BkOffice
!endif

!if [DIR $(BKOFFICE) >NUL] != 0
!   ERROR Cannot find project root at $(BKOFFICE), set BKOFFICE variable
!endif

!ifndef INCLUDE
!   ERROR INCLUDE variable is empty; must include at least system include directory
!endif

!ifndef LIB
!   ERROR LIB variable is empty; must include at least system lib directory
!endif

!ifndef BLDTYPE
BLDTYPE=DBG
!endif

!ifndef CALL
CALL=C
!endif

!ifndef PACK
PACK=YES
!endif

!ifndef OUTERR
OUTERR=NO
!endif

!ifndef WARNING_LEVEL
WARNING_LEVEL=3
!endif

OSTARG=NTx86
OSTAG=WIN32
WINTAG=32
CPUTARG=IX86


#*********************************************
# Tools
#*********************************************

MAKEEXE = nmake
IMPLIB  = implib
CC      = cl
LIBU    = lib
LINK    = link
RC      = rc
MC      = mc
HC      = hc


#*********************************************
#
# Directories
#
# DIRINC   - project level include
# DIRBIN   - project level executables
# DIRLIB   - project level libraries
# DIRMAKE  - project makefiles
#
# DIRSRC   - component source directory
# DIRH     - component headers
# DIRRES   - component resources
# DIRBLD   - component build directory
# DIRPCHSRC- Pre-compiled header source directory
# DIRPCH   - Pre-compiled header output directory
#
#*********************************************

# Project directories
DIRINC=$(BKOFFICE)\include
DIRLIB=$(BKOFFICE)\lib
DIRBIN=$(BKOFFICE)\bin
DIRMAKE=$(BKOFFICE)\include

# Component directories
DIRBLD=.
DIRSRC=.
DIRH=.;$(DIRBLD)
DIRRES=.

# Pre-compiled header directories
DIRPCHSRC=$(BKOFFICE)\Samples\Exchange\Tools\PreCompH
DIRPCH=$(BKOFFICE)\Samples\Exchange\Tools\PreCompH

#*********************************************
# Paths
#*********************************************

PATH    = $(DIRBIN);$(PATH)
LIB     = $(DIRLIB);$(LIB)
INCLUDE = $(DIRH);$(DIRINC);$(INCLUDE)


#*********************************************
# Output Redirection
#*********************************************

!if "$(OUTERR)" == "NO"
ERRFILE=
OSYM=
!else
ERRFILE=$(DIRBLD)\$(COMP).err
OSYM= >>
!endif


#*********************************************
# Basic Compile Flags
#*********************************************

# CL is for all C and C++ files
CL= -I. -c -G3s -MT -W$(WARNING_LEVEL) -WX -J -Zp -Fo$(DIRBLD)^\ -nologo $(CL)

# NT/CPU specific flags
CL= -DWIN32 -D_X86_ $(CL)

# CFLAGS is for C files
#CFLAGS=$(CFLAGS)

# CPPFLAGS is for C++ files
#CPPFLAGS=$(CPPFLAGS)

# LFLAGS is for linking
LFLAGS=/NOD /NOLOGO -machine:$(CPUTARG) -out:$@ $(LFLAGS)

# DLLFLAGS is for linking DLLs
DLLFLAGS=$(LFLAGS) -dll -def:$(@B).def -map:$(DIRBLD)\$(COMP).map $(DLLFLAGS)

# LIBFLAGS is for building libraries
LIBFLAGS=-nologo -machine:$(CPUTARG) -out:$@ $(LIBFLAGS)

# RFLAGS is for Windows resources
RFLAGS=/r -I$(DIRRES) -fo$@ $(RFLAGS)

# MFLAGS is for the message compiler
MFLAGS=-v -s -h $(DIRBLD) -r $(DIRBLD) -x $(DIRBLD) $(MFLAGS)

# MRFLAGS is for the resource compiler when used after the message compiler
MRFLAGS=-l 409 -r -x -i$(DIRBLD) $(MRFLAGS)

#*********************************************
# Pre-compiled header macros
# NOPCH     - Define this to disable use and creation of precompiled headers.
# PCHUSE    - The default pre-compiled header for .C source files.
# PCUSECPP  - The default pre-compiled header for .CPP source files.
#
# PCHCR1    - To create the PCH file most .C sources depend upon.   (edk.h)
# PCHUSE1   - To use the PCH file most .C sources depend upon.      (edk.h)
# PCHCR2    - To create the PCH file most .CPP sources depend upon. (edk.h)
# PCHUSE2   - To use the PCH file most .CPP sources depend upon.    (edk.h)
# PCHCR3    - To create MFC PCH.                                 (edkafx.h)
# PCHUSE3   - To use MFC PCH.                                    (edkafx.h)
# PCHCR4    - To create the UNICODE PCH file for .C sources.        (edk.h)
# PCHUSE4   - To use the UNICODE PCH file for .C sources.           (edk.h)
#*********************************************

!ifndef NOPCH
# We are using precompiled headers.

PCHCR1  =  /Fp$(DIRPCH)\edk.pch    /Yc"edk.h"    -Fo$(DIRPCH)\ /Yd
PCHUSE1 =  /Fp$(DIRPCH)\edk.pch    /Yu"edk.h"
PCHCR2  =  /Fp$(DIRPCH)\edkx.pch   /Yc"edk.h"    -Fo$(DIRPCH)\ /Yd
PCHUSE2 =  /Fp$(DIRPCH)\edkx.pch   /Yu"edk.h"
PCHCR3  =  /Fp$(DIRPCH)\edkafx.pch /Yc"edkafx.h" -Fo$(DIRPCH)\ /Yd
PCHUSE3 =  /Fp$(DIRPCH)\edkafx.pch /Yu"edkafx.h"
PCHCR4  =  /Fp$(DIRPCH)\edku.pch   /Yc"edk.h"    -Fo$(DIRPCH)\ /Yd
PCHUSE4 =  /Fp$(DIRPCH)\edku.pch   /Yu"edk.h"

# Overide this to change the default pre-compiled header.
# You can also blank this if not using pre-compiled headers.
!ifndef PCHUSE
PCHUSE=$(PCHUSE1)
!endif
!ifndef PCHUSECPP
PCHUSECPP=$(PCHUSE2)
!endif

PCHOBJ1 = $(DIRPCH)\edk.obj
PCHOBJ2 = $(DIRPCH)\edkx.obj
PCHOBJ3 = $(DIRPCH)\edkafx.obj
PCHOBJ4 = $(DIRPCH)\edku.obj

!else
# NOT using precompiled headers.
!include "nopch.inc"
!endif

#*********************************************
# Calling convention Flag
#*********************************************

# Pascal Calling convention
!if "$(CALL)"=="PASCAL"
CL=-Gc $(CL)
!endif


#*********************************************
# Function Packaging Flag
#*********************************************

# Function packaging flag
!if "$(PACK)" == "YES"
CL=-Gy $(CL)
!endif


#*********************************************
# Optimization Flags
#*********************************************

!if "$(BLDTYPE)"=="SHP"
CL=-Ob1 -Og -Os $(CL)
!endif

!if "$(BLDTYPE)"=="DBG"
CL=-Od -Z7 $(CL)
!endif

!if "$(BLDTYPE)"=="TST"
CL=-Ob1 -Og -Os $(CL)
!endif


#*********************************************
# Build Type Flags
#*********************************************

!if "$(BLDTYPE)"=="SHP"
CL=-DSHIP $(CL)
LFLAGS=-debug:none -nodefaultlib:libc $(LFLAGS)
!endif

!if "$(BLDTYPE)"=="DBG"
CL=-DDEBUG -DTEST $(CL) 
LFLAGS=-debug:full -debugtype:cv -nodefaultlib:libc -incremental:no -pdb:none $(LFLAGS) 
!endif

!if "$(BLDTYPE)"=="TST"
CL=-DTEST $(CL)
LFLAGS=-debug:none  -nodefaultlib:libc $(LFLAGS)
!endif


#*********************************************
# Default Libraries
#*********************************************

# C Libraries 
CLIBS =  libcmt.lib \
         oldnames.lib

# NT Libraries
NTLIBS = kernel32.lib \
         user32.lib   \
         shell32.lib  \
         gdi32.lib    \
         ole32.lib    \
         uuid.lib     \
         winspool.lib \
         comdlg32.lib \
         advapi32.lib \
         netapi32.lib \
         imagehlp.lib \
         wsock32.lib  \
         rpcdce4.lib  \
         rpcndr.lib   \
         rpcns4.lib   \
         rpcrt4.lib
        
# MAPI Libraries
MAPILIBS = MAPI32.LIB

# Library List
# Components should either add to this list with a line like:
#      LIBLIST = $(LIBLIST) mylibs
# or, if they don't need all the default libs, (e.g. if don't need MAPI):
#      LIBLIST = $(CLIBS) $(NTLIBS) mylibs
LIBLIST = $(LIBLIST) $(CLIBS) $(NTLIBS) $(MAPILIBS)

# Objects
# This is just a default setting, expect most make files to 
# overide this (i.e. if they have more than one object or their
# one object is not named $(COMP).obj
!ifndef OBJLIST
OBJLIST=$(DIRBLD)\$(@B).OBJ
!endif


#*********************************************
# Inference Rules
#*********************************************

# C Targets
{$(DIRSRC)\}.c{$(DIRBLD)\}.obj:
!if "$(OUTERR)"=="YES"
    @echo $(CC) $(CL) $(PCHUSE) $(CFLAGS) $< $(OSYM) $(ERRFILE)
!endif
    $(CC) $(CL) $(PCHUSE) $(CFLAGS) $< $(OSYM) $(ERRFILE)

# C++ Targets
{$(DIRSRC)\}.cpp{$(DIRBLD)\}.obj:
!if "$(OUTERR)"=="YES"
    @echo $(CC) $(CL) $(PCHUSECPP) $(CPPFLAGS) $< $(OSYM) $(ERRFILE)
!endif
    $(CC) $(CL) $(PCHUSECPP) $(CPPFLAGS) $< $(OSYM) $(ERRFILE)

# Resource Targets from .RC files
{$(DIRRES)\}.rc{$(DIRBLD)\}.res:
!if "$(OUTERR)"=="YES"
    @echo $(RC) $(RFLAGS) $(DIRRES)\$(@B).rc $(OSYM) $(ERRFILE)
!endif
    $(RC) $(RFLAGS) $(DIRRES)\$(@B).rc $(OSYM) $(ERRFILE)

# Resource Targets from .MC files
.SUFFIXES: .mc
{$(DIRSRC)\}.mc{$(DIRBLD)\}.res:
!if "$(OUTERR)"=="YES"
    @echo $(MC) $(MFLAGS) $< $(OSYM) $(ERRFILE)
!endif
    $(MC) $(MFLAGS) $< $(OSYM) $(ERRFILE)
!if "$(OUTERR)"=="YES"
    @echo $(RC) $(MRFLAGS) -fo$(DIRBLD)\$(@B).res $(DIRBLD)\$(@B).rc $(OSYM) $(ERRFILE)
!endif
    $(RC) $(MRFLAGS) -fo$(DIRBLD)\$(@B).res $(DIRBLD)\$(@B).rc $(OSYM) $(ERRFILE)
!if "$(OUTERR)"=="YES"
    @echo del $(DIRBLD)\$(@B).rc $(OSYM) $(ERRFILE)
!endif
        del $(DIRBLD)\$(@B).rc $(OSYM) $(ERRFILE)

# Import Libraries
{$(DIRSRC)\}.def{$(DIRBLD)\}.lib:
!if "$(OUTERR)"=="YES"
    @echo $(IMPLIB) -DEF:$(@B).DEF -OUT:$@ $(OSYM) $(ERRFILE)
!endif
    @echo $(IMPLIB) -DEF:$(@B).DEF -OUT:$@ $(OSYM) $(ERRFILE)
    xcopy $@ $(DIRLIB) $(OSYM) $(ERRFILE)

# Static Libraries
{$(DIRBLD)\}.obj{$(DIRBLD)\}.lib:
!if "$(OUTERR)"=="YES"
    @echo $(LIBU) $(LIBFLAGS) $** $(OSYM) $(ERRFILE)
!endif
    $(LIBU) $(LIBFLAGS) $** $(OSYM) $(ERRFILE)
    xcopy $@ $(DIRLIB) $(OSYM) $(ERRFILE)

# DLLs
{$(DIRBLD)\}.obj{$(DIRBLD)\}.dll:
    @echo $** > $(DIRBLD)\objfiles.lst
    @echo $(LIBLIST) > $(DIRBLD)\libfiles.lst
!if "$(OUTERR)"=="YES"
    @echo   $(LINK) $(DLLFLAGS) @$(DIRBLD)\objfiles.lst @$(DIRBLD)\libfiles.lst $(OSYM) $(ERRFILE)
!endif
    $(LINK) $(DLLFLAGS) @$(DIRBLD)\objfiles.lst @$(DIRBLD)\libfiles.lst $(OSYM) $(ERRFILE)
!if "$(OUTERR)"=="YES"
    @echo xcopy $(DIRBLD)\$(@B).lib $(DIRLIB) $(OSYM) $(ERRFILE)
!endif
    -xcopy $(DIRBLD)\$(@B).lib $(DIRLIB) $(OSYM) $(ERRFILE)

# EXEs
{$(DIRBLD)\}.obj{$(DIRBLD)\}.exe:
    @echo $(OBJLIST) > $(DIRBLD)\objfiles.lst
    @echo $(LIBLIST) > $(DIRBLD)\libfiles.lst
!if "$(OUTERR)"=="YES"
    @echo   $(LINK) $(LFLAGS) @$(DIRBLD)\objfiles.lst @$(DIRBLD)\libfiles.lst $(OSYM) $(ERRFILE)
!endif
    $(LINK) $(LFLAGS) @$(DIRBLD)\objfiles.lst @$(DIRBLD)\libfiles.lst $(OSYM) $(ERRFILE)


#*********************************************
# Define the post-include file
#*********************************************

#ifndef POSTINCL
POSTINCL=$(BKOFFICE)\Include\postmake.inc
#endif
