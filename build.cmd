@echo off
setlocal ENABLEEXTENSIONS ENABLEDELAYEDEXPANSION
pushd %~dp0

if "%~1"=="" ( 
 call :Usage
 goto :EOF
)

set VisualStudioCmd=%ProgramFiles%\Microsoft Visual Studio 8.0\VC\vcvarsall.bat
if EXIST "%VisualStudioCmd%" ( 
 call "%VisualStudioCmd%"
)

set SvnDir=%ProgramFiles%\svn
if NOT EXIST "%SvnDir%" set SvnDir=%ProgramFiles%\Subversion
if NOT EXIST "%SvnDir%" (
 echo Missing SubVersion, expected in %SvnDir%
 exit /b -1
)

for /D %%n in ( "%ProgramFiles%\NUnit*" ) do (
 set NUnitDir=%%~n
)

if NOT EXIST "%NUnitDir%" (
 echo Missing NUnit, expected in %NUnitDir%
 exit /b -1
)

set FrameworkVersion=v2.0.50727
set FrameworkDir=%SystemRoot%\Microsoft.NET\Framework

PATH=%FrameworkDir%\%FrameworkVersion%;%NUnitDir%;%SvnDir%;%DoxygenDir%;%PATH%
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
