This is a packaged setup sample. It was compiled with InstallerEditor using the following command line.

	InstallerLinker.exe /Output:Setup.exe /Banner:banner.bmp /Template:dotNetInstaller.exe /Configuration:Configuration.xml /Embed+

The output is a single Setup.exe that contains the embedded banner.bmp, configuration file and Simple.msi installer. It will create a temporary folder in %TEMP% (eg. C:\Users\user\AppData\Local\Temp\{4C7F1544-6B17-49BA-9EC6-325DCB07FD81}) and extract all contents into it. The folder will be deleted when setup terminates. This installer also automatically creates a setup.log in the same temporary folder and a Simple.msi.log for the execution of the MSI.
