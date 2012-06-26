#
# Copyright 1997 - 1999 Microsoft Corporation.  All rights reserved.
#
# Include SdkBld.Mak to build each of the entries in a list.
#  The steps are to change dir into the directory, 
#  echo the current location, run nmake recursively, 
#  and change dir back to the original directory level.  
#
# MAKEFLAGS is an NMAKE macro that has the NMAKE options.
#
# makeopts has the command line, see sdkpropbldk.mak to change the standard options
#
# The SDKPROJ macro (above) is defined solely for the purpose of echoing
#  the current directory location to the screen.  It is defined recursively 
#  by appending the current directory name onto the end of the existing
#  string.
#
#  Note, there must not be a space between the last comment and the
#   "@IF EXIST $(@D)\makefile <<nmaketmp.bat" line below.
#
    @IF EXIST $(@D)\makefile <<nmaketmp.bat
    @cd $(@D)
    @if NOT "%CD%"== ""  echo *** %CD% *** $(MAKE) -nologo $(makeopts) /$(MAKEFLAGS) 
    @if "%CD%" == ""  echo *** $(SDKPROJ)\$(@D) *** $(MAKE) -nologo $(makeopts) /$(MAKEFLAGS)
    @$(MAKE) -nologo /$(MAKEFLAGS) $(makeopts)
    @cd ..
<<

#
# End SdkBld.Mak
#
