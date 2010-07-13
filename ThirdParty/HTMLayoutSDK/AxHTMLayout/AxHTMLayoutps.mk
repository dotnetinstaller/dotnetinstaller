
AxHTMLayoutps.dll: dlldata.obj AxHTMLayout_p.obj AxHTMLayout_i.obj
	link /dll /out:AxHTMLayoutps.dll /def:AxHTMLayoutps.def /entry:DllMain dlldata.obj AxHTMLayout_p.obj AxHTMLayout_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del AxHTMLayoutps.dll
	@del AxHTMLayoutps.lib
	@del AxHTMLayoutps.exp
	@del dlldata.obj
	@del AxHTMLayout_p.obj
	@del AxHTMLayout_i.obj
