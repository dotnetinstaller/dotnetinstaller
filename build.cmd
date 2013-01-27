@echo off
setlocal ENABLEEXTENSIONS ENABLEDELAYEDEXPANSION
pushd %~dp0

if "%~1"=="" ( 
 call :Usage
 goto :EOF
)

PATH ;%~dp0ThirdParty\Microsoft\Windows SDK v6.0\VC\Bin;%~dp0ThirdParty\Microsoft\Visual Studio 8\VC\bin;%PATH%
SET VCINSTALLDIR=%~dp0ThirdParty\Microsoft\Windows SDK v6.0\VC
SET INCLUDE=%~dp0ThirdParty\Microsoft\Visual Studio 8\VC\atlmfc\include;%~dp0ThirdParty\Microsoft\Visual Studio 8\VC\include;%~dp0ThirdParty\Microsoft\Visual Studio 8\VC\PlatformSDK\Include;%INCLUDE%
SET LIB=%~dp0\ThirdParty\Microsoft\Visual Studio 8\VC\PlatformSDK\Lib;%~dp0ThirdParty\Microsoft\Visual Studio 8\VC\lib;%~dp0ThirdParty\Microsoft\Visual Studio 8\VC\atlmfc\lib;%LIB%

%SystemRoot%\Microsoft.NET\Framework\v2.0.50727\msbuild.exe dni.proj /t:%* /l:FileLogger,Microsoft.Build.Engine;logfile="dni_%1.log"

popd
endlocal
goto :EOF

:Usage
echo  Syntax:
echo.
echo   build [target] /p:Configuration=[Debug (default),Release]
echo.
echo  Target:
echo.
echo   all : build everything
echo.
echo  Examples:
echo.
echo   build all
echo   build all /p:Configuration=Release
goto :EOF
