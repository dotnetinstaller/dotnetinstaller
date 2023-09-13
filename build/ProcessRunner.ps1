Function Run-Process {
    [CmdletBinding()]  
    Param(  
        [ValidateNotNullOrEmpty()]  
        [Parameter(Mandatory=$True)]
        [Alias("FilePath")] 
        [string]$fileName,  

        [ValidateNotNullOrEmpty()]  
        [Parameter(Mandatory=$True)]
        [Alias("ArgumentList")] 
        [string]$arguments  
    )  
      
    Begin  
        {Write-Verbose "$($MyInvocation.MyCommand.Name):: Function started"}  
          
    Process  
    {  
        Write-Verbose "$($MyInvocation.MyCommand.Name):: Processing: $fileName $arguments"  
            
        $processInfo = New-Object System.Diagnostics.ProcessStartInfo 
        $processInfo.FileName = "$fileName" 
        $processInfo.RedirectStandardError = $true 
        $processInfo.RedirectStandardOutput = $true 
        $processInfo.UseShellExecute = $false 
        $processInfo.Arguments = $arguments 
        $process = New-Object System.Diagnostics.Process 
        $process.StartInfo = $processInfo 
        $process.Start() | Out-Null 
        $stdout = $process.StandardOutput.ReadToEnd()
        $stderr = $process.StandardError.ReadToEnd()
        $process.WaitForExit() 
        Write-Host $stdout 
        Write-Host $stderr 
        $exitCode = $process.ExitCode  

        Write-Verbose "$($MyInvocation.MyCommand.Name):: Finished Processing: $fileName $arguments"  

        return $exitCode 
    }  
          
    End  
        {Write-Verbose "$($MyInvocation.MyCommand.Name):: Function ended"}  
}