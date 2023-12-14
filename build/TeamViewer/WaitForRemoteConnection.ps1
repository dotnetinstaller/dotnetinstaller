# Enable -Verbose option
[CmdletBinding()]

# Set a flag to force verbose as a default
$VerbosePreference ='Continue' # equiv to -verbose

$path = "$($env:USERPROFILE)\Desktop\Delete me to continue build.txt"
# create "lock" file.
Set-Content -Path $path -Value ''    
Write-Warning "Build paused. To resume it, open a remote session to delete 'Delete me to continue build.txt' file on Desktop."

# Start process so it pops up to indicate that we're waiting for a remote connection
Start-Process -FilePath "${env:ProgramFiles(x86)}\TeamViewer\TeamViewer.exe"

# wait until "lock" file is deleted by user.
while(Test-Path $path) {
    Start-Sleep -Seconds 1
}
Write-Host "Build lock file has been deleted. Resuming build."