#----------------------------------------------------------------------------
#
# Descriptions:
#   Generic Make File Postfix for EDK Environment
#
# Copyright:
#   Copyright (C) Microsoft Corp. 1993-1999.  All Rights Reserved.
#
#----------------------------------------------------------------------------

!ifndef PRIVATE_CLEAN
clean:
!else
generic_clean:
!endif
    del $(DIRBLD)\*.obj \
        $(DIRBLD)\*.err \
        $(DIRBLD)\*.lib \
        $(DIRBLD)\*.exe \
        $(DIRBLD)\*.dll \
        $(DIRBLD)\*.map \
        $(DIRBLD)\*.res \
        $(DIRBLD)\*.pch \
        $(DIRBLD)\*.exp

cleanall: clean
    del $(DIRPCH)\*.obj \
        $(DIRPCH)\*.pch

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# Disable precompiled headers if NOPCH is defined.
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

!ifdef NOPCH
!include "nopch.inc"
!endif

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# Pre-compiled header default #1 used in most .C EDK sources.
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

$(DIRPCH)\edk.obj: $(DIRPCHSRC)\edk.c
!if "$(OUTERR)"=="YES"
    @echo $(CC) $(CL) $(PCHCR1) $(CFLAGS) $(DIRPCHSRC)\edk.c $(OSYM) $(ERRFILE)
!endif
    $(CC) $(CL) $(PCHCR1) $(CFLAGS) $(DIRPCHSRC)\edk.c $(OSYM) $(ERRFILE)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# Pre-compiled header default #2 used in most .CPP EDK sources.
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

$(DIRPCH)\edkx.obj: $(DIRPCHSRC)\edkx.cpp
!if "$(OUTERR)"=="YES"
    @echo $(CC) $(CL) $(PCHCR2) $(CFLAGS) $(DIRPCHSRC)\edkx.cpp $(OSYM) $(ERRFILE)
!endif
    $(CC) $(CL) $(PCHCR2) $(CFLAGS) $(DIRPCHSRC)\edkx.cpp $(OSYM) $(ERRFILE)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# Pre-compiled header default #3 used for .CPP and MFC applications.
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

$(DIRPCH)\edkafx.obj: $(DIRPCHSRC)\edkafx.cpp
!if "$(OUTERR)"=="YES"
    @echo $(CC) $(CL) $(PCHCR3) $(CPPFLAGS) $(DIRPCHSRC)\edkafx.cpp $(OSYM) $(ERRFILE)
!endif
    $(CC) $(CL) $(PCHCR3) $(CPPFLAGS) $(DIRPCHSRC)\edkafx.cpp $(OSYM) $(ERRFILE)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# Pre-compiled header default #4 used in UNICODE .C EDK sources.
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

$(DIRPCH)\edku.obj: $(DIRPCHSRC)\edku.c
!if "$(OUTERR)"=="YES"
    @echo $(CC) $(CL) $(PCHCR4) $(CFLAGS) $(DIRPCHSRC)\edku.c $(OSYM) $(ERRFILE)
!endif
    $(CC) $(CL) $(PCHCR4) $(CFLAGS) $(DIRPCHSRC)\edku.c $(OSYM) $(ERRFILE)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
