@echo off
setlocal ENABLEEXTENSIONS ENABLEDELAYEDEXPANSION
pushd %~dp0

if "%~1"=="" ( 
 call :Usage
 goto :EOF
)

set ProgramFilesDir=%ProgramFiles%
if NOT "%ProgramFiles(x86)%"=="" set ProgramFilesDir=%ProgramFiles(x86)%

set VisualStudioCmd=%ProgramFilesDir%\Microsoft Visual Studio 8.0\VC\vcvarsall.bat
if EXIST "%VisualStudioCmd%" call "%VisualStudioCmd%"

for /D %%n in ( "%ProgramFilesDir%\NUnit*" ) do (
 set NUnitDir=%%~n
)

if EXIST "%NUnitDir%\bin" set NUnitBinDir=%NUnitDir%\bin
if EXIST "%NUnitDir%\bin\net-2.0" set NUnitBinDir=%NUnitDir%\bin\net-2.0

if NOT EXIST "%NUnitBinDir%" echo Missing NUnit, expected in %NUnitDir%
if NOT EXIST "%NUnitBinDir%" exit /b -1

set FrameworkVersion=v2.0.50727
set FrameworkDir=%SystemRoot%\Microsoft.NET\Framework

PATH=%FrameworkDir%\%FrameworkVersion%;%NUnitDir%;%PATH%
msbuild.exe dni.proj /t:%*

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
