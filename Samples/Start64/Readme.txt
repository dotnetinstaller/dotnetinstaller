This example demonstrates usage of disable_wow64_fs_redirection parameter on x64 systems.

Tasks:

1 - start native (64-bit) notepad

2 - start 32-bit notepad

3 - execute native (64-bit) regedit /s test.reg
  The output goes to HKEY_LOCAL_MACHINE\SOFTWARE\dotNetInstaller\Test node

4 - execute 32-bit regedit /s test.reg
  The output goes to HKEY_LOCAL_MACHINE\SOFTWARE\Wow6432Node\dotNetInstaller\Test node

5 - execute command using native (64-bit) cmd
  The cmd starts native (64-bit) notepad

6 - execute command using 32-bit cmd
  The cmd starts 32-bit notepad

7 - open text file from native (64-bit) environment
  The 64-bit notepad is started

8 - open text file from 32-bit environment
  The 32-bit notepad is started


On x86 systems disable_wow64_fs_redirection parameter is ignored.
