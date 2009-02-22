Here you can find 2 samples:

-StandaloneSetup: This is a standard setup that you can look if you want to distribuite you setup with a CD-Rom, Intranet Network, DVD, ...
 			Use dotNetInstaller.exe to run the setup sample.

-WebSetup: This is a web setup that download the required components from a web site (In this case www.devage.com/SampleApp).
	To run this sample you must then replace in the configuration.xml file 
 	and in the SampleAppWebSetup.zip/configuration.xml file www.devage.com with a custom web server (for example www.yourserver.com).
	Then zip again SampleAppWebSetup and copy all the files in a Web Server.
	Download from a client machine SampleAppWebSetup (that can also be an Self-Extracting zip file) and run dotNetInstaller.exe inside the archive.