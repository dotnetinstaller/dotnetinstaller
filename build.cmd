@echo off
setlocal ENABLEEXTENSIONS ENABLEDELAYEDEXPANSION
pushd %~dp0

if "%~1"=="" ( 
 call :Usage
 goto :EOF
)

REM find the latest Visual Studio installation with MSBuild using vswhere, which is installed with Visual Studio 2017 version 15.2 and later
set msbuild=
set vswhere="%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
if exist %vswhere% for /f "usebackq delims=" %%i in (`%vswhere% -latest -products * -requires Microsoft.Component.MSBuild -find MSBuild\**\Bin\MSBuild.exe`) do set msbuild="%%i"
if not defined msbuild (
    ECHO Error: MSBuild was not found. Visual Studio 2017 version 15.2 or later is required.
    goto :EOF
)

echo Found msbuild at %msbuild%

REM set RestoreUseSkipNonexistentTargets=false so running "nuget.exe restore dni.sln" returns a successful exit code (0).
REM Otherwise, the following errors occur:
REM .\Samples\PackagedSetup\Simple\Simple.vdproj(1,1): error MSB4025: The project file could not be loaded. Data at the root level is invalid. Line 1, position 1. [dni.proj]
REM EXEC : warning : Error reading msbuild project information, ensure that your input solution or project file is valid. NETCore and UAP projects will be skipped, only packages.config files will be restored. [dni.proj]
REM dni.proj(130,5): error MSB3073: The command "ThirdParty\NuGet\NuGet.exe restore Dni.sln" exited with code -1.
set RestoreUseSkipNonexistentTargets=false

%msbuild% dni.proj /t:%* /l:FileLogger,Microsoft.Build.Engine;logfile="dni_%1.log"

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
