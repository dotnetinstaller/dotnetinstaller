# Enable -Verbose option
[CmdletBinding()]

# Set a flag to force verbose as a default
$VerbosePreference ='Continue' # equiv to -verbose

.\..\ProcessRunner.ps1

$exitCode = Run-Process -FilePath "reg.exe" -ArgumentList "import "".\build\TeamViewer\TeamViewer_Settings.reg"""
if ($exitCode -ne 0)
{  
    throw "Command failed with exit code $exitCode."  
}  

# Install TeamViewer
$exitCode = Run-Process -FilePath "choco.exe" -ArgumentList "install teamviewer -y"
if ($exitCode -ne 0)
{  
    throw "Command failed with exit code $exitCode."  
}  

Start-Process -FilePath "${env:ProgramFiles(x86)}\TeamViewer\TeamViewer.exe"

# get User ID
$key = 'HKLM:\SOFTWARE\WOW6432Node\TeamViewer'

while (!(Get-ItemProperty -Path $key -Name "ClientID" -ErrorAction SilentlyContinue))
{
    start-sleep -seconds 5
}

$clientId = (Get-ItemProperty -Path $key -Name "ClientID").ClientID

Write-Host "TeamViewer connection details:" -ForegroundColor Yellow
Write-Host "  Partner ID: $clientId" -ForegroundColor Gray