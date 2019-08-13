; Allows projects to target Windows 2000 and XP
; https://stackoverflow.com/questions/2484511/can-i-use-visual-studio-2010s-c-compiler-with-visual-studio-2008s-c-runtim
; https://stackoverflow.com/questions/19516796/visual-studio-2012-win32-project-targeting-windows-2000/53548116#53548116
; https://social.msdn.microsoft.com/Forums/vstudio/de-DE/30eb0b9e-a905-4be3-ac33-3376766c4500/dll-mit-vs2010-fr-win2000-kompilieren
; https://tedwvc.wordpress.com/2010/11/07/how-to-get-visual-c-2010-mfc-applications-to-run-on-windows-2000/
; http://sharpsetup.eu/documentation/html/003ab441-765b-4eb6-80bd-33ab3aa8c3db.htm
; https://autohotkey.com/board/topic/65431-remove-kb816542-dependency-on-windows-2000/
; https://gist.github.com/xyzzy-17-638/2354412
; https://blog.csdn.net/muy/article/details/51072311
.model flat

.data
__imp__EncodePointer@4 dd dummy
__imp__DecodePointer@4 dd dummy
EXTERNDEF __imp__EncodePointer@4 : DWORD
EXTERNDEF __imp__DecodePointer@4 : DWORD

.code
dummy proc
mov eax, [esp+4]
ret 4
dummy endp

end