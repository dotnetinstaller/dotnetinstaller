dotNetInstaller Setup Bootstrapper
==================================

![dotNetInstaller](https://github.com/dotnetinstaller/dotnetinstaller/raw/master/Documentation/Images/Logo.gif)

dotNetInstaller is a widely used, general-purpose setup bootstrapper for Microsoft Windows XP, 2003, Vista, 2008, 7, 8, 2012, 8.1, 10, 2016, 2019, 2022, and 11.

Build Status
------------

[![Build status](https://github.com/dotnetinstaller/dotnetinstaller/actions/workflows/build.yml/badge.svg?branch=master&event=push)](https://github.com/dotnetinstaller/dotnetinstaller/actions/workflows/build.yml)

Essentials
----------

* [Need Help? Google Group](http://groups.google.com/group/dotnetinstaller)
* Download Version 3.2.115
  [[installer](https://github.com/dotnetinstaller/dotnetinstaller/releases/download/3.2.115/dotNetInstaller.3.2.115.0.msi)]
  [[zip](https://github.com/dotnetinstaller/dotnetinstaller/releases/download/3.2.115/dotNetInstaller.3.2.115.0.zip)]
* [Older Versions](https://github.com/dotnetinstaller/dotnetinstaller/releases).

Bootstrapper
------------

dotNetInstaller enables the developer to define the application prerequisites and install the correct version(s) of these components in a predictable order based on the processor architecture, user operating system type and language, allow the user to download these components from the web, install these components directly from a single packaged setup, local media or both. dotNetInstaller is very feature rich and runs on all known Windows operating systems with a very tiny footprint. 

A boostrapper doesn't replace tools like InstallShield, Wise, Visual Studio Setup and Deployment Project or Wix. The goal is to create an application to help users with installing the correct prerequisites. Most real world applications need to install several components to work properly, including Windows Service Packs, Internet Explorer, MDAC or .NET Framework. This kind of applications are most commonly known as bootstrappers. dotNetInstaller is such a bootstrapper.

Getting Started
---------------

1. Download and install dotNetInstaller.
2. Launch InstallerEditor.exe and create a configuration file.
3. Add configurations, components and installed checks. Edit messages and various options.
4. Deploy your installer. This may involve linking a single executable package or copying support files onto fixed media.

dotNetInstaller ships with a CHM help file with a detailed Getting Started section and a complete configuration reference. If you have trouble viewing the help file content, Right Click on it and choose *Unblock* in Properties.

Bootstrapper Scenarios
----------------------

A bootstrapper enables additional scenarios not supported by the installer alone. 

* Distribute a single, compressed, executable packaged setup with all pre-requisites. 
* Distribute multiple installers that compose a large and complex application in a single package and enforce a well-defined installation workflow and dependencies. 
* Package frequently required components or components with a small footprint, and download less frequently used or larger ones only when necessary. 
* Provide additional parameters to existing package technologies, eg. automatically enabling logging in MSI installers. 
* Support workflow that includes a reboot in the middle of an installation between interdependent components. 
* Support web-based scenarios that include on-demand downloading the latest versions of the installed software and prerequisites. 
* Uninstall applications composed of several packages in a single sequence. 

dotNetInstaller Components
--------------------------

This project consists of the following elements: 

* *dotNetInstaller* and *htmlInstaller*: main bootstrapper applications, written in C++. This is the raw setup which presents a GUI in front of the user that displays which components to install depending on which components are already installed on the operating system. The bootstrapper is statically linked with the CRT and has no prerequisites. 
* *InstallerEditor*: an application for editing configuration files and bootstrapper resources, written in C# for the .NET Framework 4.0. The editor is also capable of importing older versions of dotNetInstaller configuration files and converting them into the current/newer format. 
* *InstallerLinker*: a command-line bootstrapper linker that can be used in a build process, written in C# for the .NET Framework 4.0. 
Several samples and dependency templates that can be reused as-is and that demonstrate sometimes complex checks which verify whether, for example, MDAC or .NET framework are already installed. 

Project History
---------------

This project began as a [CodeProject article](http://www.codeproject.com/KB/install/dotNetInstaller.aspx) and was maintained on the [DevAge website](http://www.devage.com/) and [SourceForge](https://sourceforge.net/projects/dotnetinstaller) by [Davide Icardi](https://github.com/davideicardi). It continued its journey through CodePlex and is now officially maintained on [Github](https://github.com/dotnetinstaller/dotnetinstaller).

License and Copyright
---------------------

Copyright (c) 2009-2012 Davide Icardi, Daniel Doubrovkine and Contributors.

This project is licensed under the [MIT License](https://github.com/dotnetinstaller/dotnetinstaller/blob/master/LICENSE).

