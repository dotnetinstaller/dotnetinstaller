TBD
===

Features
--------

* [#114](https://github.com/dotnetinstaller/dotnetinstaller/issues/114) - Added support for operating system product type filters - [@icnocop](https://github.com/icnocop).
* [#153](https://github.com/dotnetinstaller/dotnetinstaller/issues/153) - Added support for sub-directory installed check comparison using semantic versioning - [@icnocop](https://github.com/icnocop).
* [#156](https://github.com/dotnetinstaller/dotnetinstaller/pull/156) - Building and distributing 64-bit version of CabLib.dll for reference by 64-bit processes - [@icnocop](https://github.com/icnocop).

3.2.115 (1/15/2022)
===================

Features
--------

* [#146](https://github.com/dotnetinstaller/dotnetinstaller/pull/146) - Added support for specific Windows 10 versions, Windows 11, Windows Server 2019, and Windows Server 2022 - [@icnocop](https://github.com/icnocop).
* [#144](https://github.com/dotnetinstaller/dotnetinstaller/issues/144) - Fix: OSinfo not displaying correctly if server 2016 or 2019 - [@icnocop](https://github.com/icnocop).

3.1.415 (4/15/2021)
===================

Features
--------

* [#141](https://github.com/dotnetinstaller/dotnetinstaller/pull/141) - Added support for `v[version]` format for version numbers (with a leading `v` or `V`);  e.g. `v3.1.415` - [@mariusbancila](https://github.com/mariusbancila).

3.0.814 (8/14/2019)
===================

Features
--------

* [#130](https://github.com/dotnetinstaller/dotnetinstaller/issues/130) - Added backwards compatibility support for Windows XP - [@icnocop](https://github.com/icnocop).

3.0.812 (8/12/2019)
===================

Features
--------

* [#124](https://github.com/dotnetinstaller/dotnetinstaller/issues/124) - Added ability to disable WOW64 file system redirection on x64 systems when checking if a file is installed - [@icnocop](https://github.com/icnocop).
* [#109](https://github.com/dotnetinstaller/dotnetinstaller/issues/109) - Migrated code to Visual Studio 2015 and .NET 4.0 (Deprecated support for Windows 95, 98, ME, NT4, and 2000) - [@icnocop](https://github.com/icnocop).
* [#112](https://github.com/dotnetinstaller/dotnetinstaller/pull/112) - Removed throwing an exception when the installation process is closed or canceled by user at language selection stage - [@genI3](https://github.com/genI3).
* [#96](https://github.com/dotnetinstaller/dotnetinstaller/issues/96) - Added the ability to hide a component if it's already installed - [@icnocop](https://github.com/icnocop).

2.4 (9/9/2015)
==============

Features
--------

* [#46](https://github.com/dblock/dotnetinstaller/pull/46) - Added support for hiding the application window for ShellExecute execution method for command components - [@icnocop](https://github.com/icnocop).
* [#75](https://github.com/dblock/dotnetinstaller/issues/75) - Added the ability to set the current working directory for command components - [@icnocop](https://github.com/icnocop).
* [#84](https://github.com/dblock/dotnetinstaller/issues/84) - Added support for Windows Server 2008 R2 SP1 - [@FroggieFrog](https://github.com/FroggieFrog).
* [#86](https://github.com/dblock/dotnetinstaller/issues/86) - Added support for Windows 10 - [@icnocop](https://github.com/icnocop).

Bugs
----

* [#60](https://github.com/dblock/dotnetinstaller/issues/60) - Fix: Typo in Browse for Folder popup - [@romanws](https://github.com/romanws).
* [#71](https://github.com/dblock/dotnetinstaller/issues/71) - Fix: If reboot_required="" then the message box to prompt for a reboot should not be displayed - [@icnocop](https://github.com/icnocop).

Misc
--------

* Added a password unprotected strong key (dni.key) and signing InstallerLib.dll - [@icnocop](https://github.com/icnocop).

2.3 (1/6/2013)
==============

Features
--------

* [#40](https://github.com/dblock/dotnetinstaller/pull/40) - Added support for escape patterns for square brackets (`[\[]` for an open bracket and `[\]]` for a close bracket) - [@montrowe](https://github.com/montrowe).
* [#46](https://github.com/dblock/dotnetinstaller/pull/46) - Added support for hiding command based components' application window when run - [@icnocop](https://github.com/icnocop).
* [#24](https://github.com/dblock/dotnetinstaller/issues/24) - The temporary directory is automatically created if it doesn't already exist - [@icnocop](https://github.com/icnocop).
* [#54](https://github.com/dblock/dotnetinstaller/pull/54) - Option to run Cmd/Exe/MsuComponent via `ShellExecute`. This allows to properly request elevated privileges with UAC prompt if needed - [@baSSiLL](https://github.com/baSSiLL).
* [#56](https://github.com/dblock/dotnetinstaller/pull/56) - Support for Windows 8.1 / Server 2012 R2 - [@baSSiLL](https://github.com/baSSiLL).

Bugs
----

* [#41](https://github.com/dblock/dotnetinstaller/pull/41) - Fix: When an uninstall successfully completes, pop `uninstallcompletemessage` message box instead of `installcompletemessage` - [@montrowe](https://github.com/montrowe).
* [#18](https://github.com/dblock/dotnetinstaller/issues/18) - Installer should auto close when all checked components are installed - [@baSSiLL](https://github.com/baSSiLL).

Misc
--------

* Fix: restored support for Win95/98 - [@MikeGratsas](https://github.com/MikeGratsas).
* [#30](https://github.com/dblock/dotnetinstaller/pull/30): using mt.exe from ThirdParty instead of `%Program Files%`, added missing application compatibility sections to manifest files and updated to include Windows 8\2012, and added "Microsoft\Windows SDK v6.0" to ThirdParty and updated build.cmd to set the `PATH` and `VCINSTALLDIR` environment variables accordingly - [@icnocop](https://github.com/icnocop).
* [#45](https://github.com/dblock/dotnetinstaller/pull/45): always logging exit code of process-based components for management\development\troubleshooting purposes - [@icnocop](https://github.com/icnocop).

2.2 (8/24/2012)
===============

Features
--------

* [#8](https://github.com/dblock/dotnetinstaller/issues/8): Added `prompt_for_optional_components`, prompt for optional components when all required components are installed - [@dblock](https://github.com/dblock).
* Displaying processor architecture next to the operating system version in the log file - [@dblock](https://github.com/dblock).

Bugs
----

* [#12](https://github.com/dblock/dotnetinstaller/issues/12): Processor architecture filter matching for negated values (using `!`) is incorrect - [@dblock](https://github.com/dblock).
* [#14](https://github.com/dblock/dotnetinstaller/issues/14): htmlInstaller does not populate user-defined edit values - [@jennings](https://github.com/jennings).
* [#22](https://github.com/dblock/dotnetinstaller/pull/22): Add the ability to use radio buttons in htmlInstaller - [@jennings](https://github.com/jennings).

Misc
----

* Using MSBuild Community Tasks from the ThirdParty directory - [@icnocop](https://github.com/icnocop).

2.1 (5/28/2012)
===============

Features
--------

* First release from [Github](http://github.com/dblock/dotnetinstaller).
* [#10448](http://dotnetinstaller.codeplex.com/workitem/10448): Added Windows Server 8 support.

Bugs
----
* [#10280](http://dotnetinstaller.codeplex.com/workitem/10280): UI displayed briefly if auto_close_if_install set.
* [#10270](http://dotnetinstaller.codeplex.com/workitem/10270): Run key not deleted on restart.
* [#343238](http://dotnetinstaller.codeplex.com/discussions/343238), [#218777](http://dotnetinstaller.codeplex.com/discussions/218777): Fixed dotNetInstaller.exe crash when WaitForSingleObject returns nonsignaled member when Start() and End() were called quickly in succession causing pointers to be deleted while a dependent thread is still running

Misc
----
* Using Sandcastle and Sandcastle Help File Builder from ThirdParty directory
* Upgraded to Microsoft CRT v8.0.50727.6195

2.0 (9/27/2011)
===============

Features
--------

* [#8318](http://dotnetinstaller.codeplex.com/workitem/8318): Added support for hex values in `returncodes_success` and `returncodes_reboot`. To specify a hex number start it with 0x.
* [#7968](http://dotnetinstaller.codeplex.com/workitem/7968): Support elevation as a subsequent command within the bootstrapper. First UI shows un-elevated, but clicking install elevates.
* [#8005](http://dotnetinstaller.codeplex.com/workitem/8005): Added a new os_filter type 'greater than' (+) and 'less than' (-).
* [#6289](http://dotnetinstaller.codeplex.com/workitem/6289): Added a new setup bootstrapper, htmlInstaller, driven by an HTML-based UI engine.
* [#6618](http://dotnetinstaller.codeplex.com/workitem/6618): Added `#STARTPATH`, `#STARTEXE` and `#STARTFILENAME` substitution variables.
* [#6955](http://dotnetinstaller.codeplex.com/workitem/6955): Added `#OSLANGID` substitution variable, operating system language ID.
* [#6620](http://dotnetinstaller.codeplex.com/workitem/6620): Added `#OSLOCALE` substitution variable, operating system ISO language and region (eg. `en-US`).
* [#6956](http://dotnetinstaller.codeplex.com/workitem/6956): `#LANGID` and `#LANGUAGE` are always set to the value in the currently executing configuration. `#LANGUAGE` may be empty, while `#LANGID` will to the operating system value.
* [#6604](http://dotnetinstaller.codeplex.com/workitem/6604): InstallerEditor no longer needs a configuration file to link a bootstrapper and the configuration does not need to be saved before creating an exe.
* [#6798](http://dotnetinstaller.codeplex.com/workitem/6798): InstallerEditor will display file names when embed files are missing during linking.
* [#4884](http://dotnetinstaller.codeplex.com/workitem/4884): InstallerEditor will notice that a configuration file has changed on disk and offer to reload it.
* [#6786](http://dotnetinstaller.codeplex.com/workitem/6786): Bootstrapper will return a 3010 exit code when a reboot was required.
* [#6786](http://dotnetinstaller.codeplex.com/workitem/6786): Added `/noreboot` to the bootstrapper to suppress actual reboot when required. Bootstrapper will simply return a 3010 exit code in this case.
* [#7004](http://dotnetinstaller.codeplex.com/workitem/7004): The user-defined browse control will always return paths without the trailing backslash except for drive paths (eg. `C:\`).
* [#6730](http://dotnetinstaller.codeplex.com/workitem/6730): InstallerEditor displays a `*` next to field names that are required and displays an error if the user tries to delete the value.
* [#7148](http://dotnetinstaller.codeplex.com/workitem/7148): Added support for Windows 2008 SP2 and Windows 7 SP1.
* [#7252](http://dotnetinstaller.codeplex.com/workitem/7252): Enabled Visual Styles: modified default manifests with a dependency on `Microsoft.Windows.Common-Controls 6.0`.
* [#7382](http://dotnetinstaller.codeplex.com/workitem/7382], [#9000](http://dotnetinstaller.codeplex.com/workitem/9000): Added `disable_wow64_fs_redirection` at setup configuration and component level to run native x64 Windows applications and installation packages(cmd, regedit, msi, msp, etc) from dotNetInstaller.
* [#7916](http://dotnetinstaller.codeplex.com/workitem/7916): Added MUI support with `MuiUser` (preferred language set for the user) and `MuiSystem` (preferred language set for the system) options in configuration `lcidtype`.
* [#8277](http://dotnetinstaller.codeplex.com/workitem/8277): Language selector dialog in dotNetInstaller will automatically select the operating system language if available.
* [#8256](http://dotnetinstaller.codeplex.com/workitem/8256): Added `/noRunOnReboot` to the bootstrapper to suppress actually writing the RunOnRebootregistry key.
* [#272583](http://dotnetinstaller.codeplex.com/discussions/272583): Added support for Windows 8.

Misc
----

* [#7575](http://dotnetinstaller.codeplex.com/workitem/7575): Upgraded to SandCastle 1.9.3.0 documentation builder.
* [#7672](http://dotnetinstaller.codeplex.com/workitem/7672): Outputing running nunit test case name to console.
* [#7673](http://dotnetinstaller.codeplex.com/workitem/7673): Checked in *.*proj files with TFS bindings and add associated vspscc files.
* [#7151](http://dotnetinstaller.codeplex.com/workitem/7151): InstallerEditor example links in component wizard use `example.com` instead of `yourwebsite.com`, which is a real site.
* [#8081](http://dotnetinstaller.codeplex.com/workitem/8081): Dni.sln build fails if a Sample Configuration.xml file is read-only.
* [#8084](http://dotnetinstaller.codeplex.com/workitem/8084): Moved commands in build.cmd to dni.proj.
* [#8126](http://dotnetinstaller.codeplex.com/workitem/8126): Added and using NUnit binaries in ThirdParty instead of what is installed in "Program Files".
* [#8696](http://dotnetinstaller.codeplex.com/workitem/8696): Upgraded to Wix 3.5 and using binaries in ThirdParty instead of what is installed in "Program Files".

Bugs
----

* [#8143](http://dotnetinstaller.codeplex.com/workitem/8143): Full UI not displayed after reboot.
* [#7493](http://dotnetinstaller.codeplex.com/workitem/7493): Windows Defender blocks DNI upon restart. See [#7968](http://dotnetinstaller.codeplex.com/workitem/7968].
* [#6758](http://dotnetinstaller.codeplex.com/workitem/6758): MSI components with paths equal to a length of a GUID fail to install.
* [#6816](http://dotnetinstaller.codeplex.com/workitem/6816): 0x8007064a: MsiEnumProducts - The configuration data for this product is corrupt.
* [#6352](http://dotnetinstaller.codeplex.com/workitem/6352): 0x80070645: MSIGetProductInfo - This action is only valid for products that are currently installed.
* [#6788](http://dotnetinstaller.codeplex.com/workitem/6788): Splash screen broken in basic UI mode.
* [#6805](http://dotnetinstaller.codeplex.com/workitem/6805): A component with no installed checks is not installed if `/x` is specified on the command line.
* [#7155](http://dotnetinstaller.codeplex.com/workitem/7155): `ProductVersion` is not automatically written to the `OSVERSIONINFO` string table when available.
* [#7224](http://dotnetinstaller.codeplex.com/workitem/7224): License file for `ControlLicense` user-defined controls is left in `%TEMP%\GUID` after installation.
* [#7567](http://dotnetinstaller.codeplex.com/workitem/7567): If InstallerEditor is closed minimized it will not correctly restore its position and will not appear on the screen when restarted.
* [#7565](http://dotnetinstaller.codeplex.com/workitem/7565): Dni does not automatically change into uninstall mode if an optional component is not installed.
* [#7565](http://dotnetinstaller.codeplex.com/workitem/7557): Dni will incorrectly display installation_completed message if auto_close_if_installed=true and not all components installed successfully.
* [#7578](http://dotnetinstaller.codeplex.com/workitem/7578): Updated documentation to indicate that an elevated command prompt is required to build the project in the development environment.
* [#7601](http://dotnetinstaller.codeplex.com/workitem/7601): Complete command may not execute with optional components.
* [#8203](http://dotnetinstaller.codeplex.com/workitem/8203): dotNetInstaller may hang with the component installing or extracting progress bar.
* [#8697](http://dotnetinstaller.codeplex.com/workitem/8697): `status_not_installed` doesn't show when defined at the component level.

1.10 (7/12/2010)
================

Features
--------

* Added support for executable components with an optional response file and installationdirectory.
* Added `has_value_disabled` option to user-defined controls.
* `Install`, `Cancel` and `Skip` buttons now disabled during install/uninstall.
* Added `dialog_default_button` that specifies the default button for the main dialog (one of cancel, install or skip).
* Added `File -&gt; Recent Files` menu to Installer Editor that lists the last 10 configuration files opened.
* InstallerEditor window will remember its size, position and the size of the configuration tree and attribute comments.
* InstallerEditor Make Exe window remembers all its contents.
* Added `os_filter` that behaves like `lcid_filter` for operating system IDs.
* Replaced `os_filter_greater` and `os_filter_smaller` with `os_filter_min` and `os_filter_max` that include boundaries and use literals instead of numbers.
* Added `show_progress_dialog` at setup configuration and component level, controls whether to show the component install progress dialog.
* Added `show_cab_dialog` at setup configuration and component level, controls whether to show the CAB extraction progress dialog.
* Added user-defined image control.
* Holding the keyboard Control key and double-clicking on a bootstrapper component will install it, regardless of whether the component is selected or not.
* Holding the keyboard Shift key and double-clicking on a bootstrapper component will toggle it's selected state, regardless of whether the component is required or not.
* Unicows.dll embedding is now optional. Specify `/Mslu+` on the InstallerLinker command line if you plan to run your setup on Windows 95 and 98 platforms.
* Replaced components' `selected` by `selected_install` and `selected_uninstall`.
* Replaced components' `required` by `required_install` and `required_uninstall`.
* Added `/ProcessorArchitecture:list` to InstallerLinker to link an installer targeting a specific platform architecture.
* Removed configuration-level `allow_continue_on_error` that confused component logic.
* Added `default_allow_continue_on_error` to components. Sets the default value of the selection when `allow_continue_on_error` is set to True. In UI mode, sets the default dialog selection for the prompt. In silent mode allows to continue on failure.
* Added `reload_on_error` to setup configuration. Controls whether to reload the components list after a component error has occurred. Unlike previous versions, default is set to True.
* Allowing empty `failed_exec_command_continue` messages. When both the configuration-level and component-level messages are empty, the user is not prompted with a question to continue and the value of `default_continue_on_error` is used to make the decision to continue or abort.

Misc
----

* Added application compatibility entries for Windows Vista and Windows 7 in the default dotNetInstaller.exe.manifest.

Bugs
----

* Bug: user-defined controls that contain a hyperlink, such as license agreement, may render as overlapped black text behind link.
* Bug: `mustreboot` component option is broken.
* Bug: Windows XP 64-bit incorrectly identified as Windows 2003 Server R2.

1.9 (4/5/2010)
==============

Features
--------

* Added support for Windows Installer Patches (MSP) with an "msp" component type.
* Added `#UILEVEL` variable, current installer UI level, one of "full", "silent" or "basic".
* Added `#LANGUAGE` and `#LANGID` variables, current configuration language and locale id.
* Added `uninstall_display_name` to all components, optional component display name during uninstall.
* Added `uninstall_package` to `msi` components, optional package to use during uninstall.
* Added `uninstallation_none`, `uninstallation_completed` and `uninstalling_component_wait` to setup configurations.
* Added support for multiple registry paths in `@[registry path]` substitutions. Separate multiple paths with a `|` character.
* A default value is no longer required in registry substitutions, assumed blank.
* Added optional installed checks for user-defined controls. The check must evaluate to `True` for the control to be displayed, enabled or both, depending on the value of the new `check` option.
* Added `defaultvalue` options to `registry`, `file` and `product` installed checks. The default value is used when the bootstrapper does not find the registry key or file, ie. it cannot decide whether the component is installed based on the specifics of the check (eg. version comparison with a value that doesn't exist is not meaningful).
* Added `selected` option to components to select or de-select a component by default.
* Added `key_exists` and `value_exists` operators to registry installed checks. The `value_exists` operator allows one to check whether the default registry key value is set.

Misc
----

* `/DisplayCab` truncates the files list for each cub at two items; rest is shown as a summary.
* Failures to read or write embedded resources, including CABs, CAB directory, banner and manifest, reports the file name affected by the error.
* Documented uninstall strategy for MSIs by remembering the product GUID in registry under the "Install and Uninstall Sequences" section.
* Substantially improved peformance linking large bootstrappers with many embedded files and components.
* Implemented work-around for "not enough storage space" system error while embedding large CABs.

Bugs
----

* MSI components ignore `uninstall_cmdparameters`, `uninstall_cmdparameters_silent` and `uninstall_cmdparameters_basic`.
* MSU components don't property handle reboots with standard 3010 exit code.
* Extracting files from large embedded CABs with many files may not extract all files.
* Uninstall doesn't remove components and process configurations in reverse order.
* Progress status and labels encode &amp; characters as key access indicators instead of rendering them as is.
* CMD components don't property reload `command_basic` and `uninstall_command_basic` in InstallerEditor.
* InstallerEditor "Save" menu is not re-enabled after "Save As".
* Registry install checks with the `exists` operator for a blank field value fail with a "The system cannot find the file specified." error.

1.8 (1/20/2010)
===============

Features
--------

* Added support for uninstall sequences with new command-line `/i` and `/x` switches, `supports_install`, `supports_uninstall`
global options in configurations, components and controls. Added extended uninstall parameters in `cmd` and `msi` components.
* Added user-defined form controls and input for labels, checkboxes, edit boxes, hyperlinks and file/directory browse controls.
* Added user-defined splash screen embedded with the InstallerLinker `/Splash` option and an optional `/nosplash` switch to dotNetInstaller.
* dotNetInstaller: Added `/controlArgs "control id":"value"` to dotNetInstaller.exe command line to override initial control values.
* Added `returncodes_reboot` to `cmd` components that specify which return code(s) should be treated as a required reboot.
* Added `returncodes_success` to `cmd` components that specify a list of comma-separated return code(s) that should be treated as success. Specify "all" to create a component that doesn't fail based on its return code and specify `!value` to treat all return codes except a single value as success.
* Added splash and manifest input to InstallerEditor's Make Exe dialog.
* Added support for a license agreement checkbox user-defined control.
* Added `dialog_message_copying` that displays instead of `dialog_message_downloading` when the file is copied from `sourcepath`.
* The `dialog_message_downloading` and `dialog_message_copying` replace `dialog_message` in download dialogs depending on whether a download or a local copy is required.
* Added component `id` and renamed `description` to `display_name`.
* ComponentArgs now accepts `*`, `id` or `display_name`, cumulative in this order.
* Added `clear_cache` to download components. When true, attempts to clear the local internet cache entry for the url to download.
* Cabbing now embeds files that belong in components in separate resource streams, extracting only those files that are necessary for installation of a particular component. Embedded files outside of components continue to always be extracted.
* Changed default of `/EmbedResourceSize &lt;size in bytes&gt;` from 32MB to 128MB.
* CAB extraction uses the memory-mapped resource streams and no longer writes temporary files to extract embedded components. This significantly reduces disk space and memory requirements and improves extraction speed.
* InstallerEditor now accepts a configuration file on the command-line and opens it. You can also pass /? for command-line usage and success/failure return codes are documented.
* InstallerEditor: added "Edit" menu with identical contents as the right click popup on the currently selected configuration node.

Bugs
----

* Bug: error creating temporary directory on Windows 95/98/ME.
* Bug: combining #PATH variables produces inconsistent backslash count for different path types, which causes component execution failure on Windows 95/98/ME.
* Bug: component lcid filters broken.
* Bug: product installed checks may produce Error in ::IIDFromString: The parameter is incorrect.
* Bug: adjusting X or Y coordinates of UI widgets doesn't preserve widget's width or height.
* Bug: embedfolder nested within a component broken.
* Bug: download dialog will no longer appear when neither download nor copy is not required.
* Bug: file and registry (DWORD and REG_SZ) version checks `version_lt`, `version_gt`, `version_le` and `version_ge` are broken: their results are inverted; if you have been using these checks, review the documentation and adjust the check conditions.
* Bug: InstallerEditor's Make Exe dialog is closed when the user presses Cancel when prompted for a target .exe file name.

Misc
----

* Added 3rd party licensing information to documentation.

1.7 (9/30/2009)
===============

Features
--------

* Added OS filter identifiers for Windows Vista SP2, Windows Server 2003 R2, Windows Server 2008 R2 and Windows 7.
* Extended registry search REG_MULTI_SZ semantics. You can now specify a comma-delimited list of values to `match` exactly all values, `contains` to match a subset of values and you can no longer specify a broken `version` match.
* Added support for nested reference configurations. Each downloaded configuration file is checked for more reference configurations. There's a nested depth limit of 10 to avoid circular references.
* Added `/DisplayCab` command line option to dotNetInstaller.exe that displays the embedded CAB file contents when available.
* Added `/DisplayConfig` command line option to dotNetInstaller.exe that displays configurations and components.
* Added support for relative paths in MSI components by resolving paths before execution.
* Added `version_lt`, `version_le`, `version_gt`, `version_ge` and `version_eq` functions to installed check file and registry operators.
* Added support for `os_filter_smaller`, `os_filter_greater` and `processor_architecture_filter` in web configurations.
* Added a product installed check that queries the MSI system database for a product by it's product id or upgrade code and is capable of comparing product properties, such as VersionString.
* Added an "msu" component type, similar to "msi" for Windows Update (.msu) packages.
* InstallerEditor and InstallerLinker no longer require elevation on Windows Vista and Windows Server 2008.
* Unicows.dll is embedded and is no longer required for Windows 95 and 98 installers. You can now distribute a single packaged setup for Windows 95 and 98 platforms.
* Added `/ConfigFile &lt;path\configuration.xml&gt;` option to the bootstrapper to specify an alternate configuration file.
* dotNetInstaller process exit code is now 0 on success, process exit code is now shell execute return code on an open file component failure, MSI return code on an MSI component failure, process exit code on a non-zero cmd component return, -2 on cancel from main dialog or download and -1 on any other error. Check `%ERRORLEVEL%` in batch scripts.
* Added a directory exists installed check.
* Added `dialog_message_connecting` and `dialog_message_sendingrequest` to download progress.
* Added `/?` or `/help` to the bootstrapper that shows the command line syntax and options.
* Moved `log_enabled` and `log_file` options to the configuration top level from individual install configurations.
* Added expansion of registry variables to configuration nodes in the format of `@[KEY:OPTION\PATH\VALUE]` (eg. @[HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\CommonFilesDir]).
* Added expansion of environment variables to configuration nodes (eg. %TEMP%).
* All nodes in the configuration file, except boolean and strongly typed enumerations, accept path (eg. #TEMPPATH), environment (eg. %TEMP%) and registry (eg. @[HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\CommonFilesDir]) variables.
* Added an optional user language selection dialog to the bootstrapper. Users can pick amongst the languages available instead of choosing their locale or the one of the operating system.
* Msi packages can now be GUIDs of installed products, in the {GUID} format. These will not be resolved as a path.
* Added `/Manifest &lt;manifest file&gt;` to the installer linker to specify a replacement manifest. This enables building bootstrappers that don't elevate on Windows Vista, Server and Windows 7.
* Added `/EmbedResourceSize &lt;size in bytes&gt;` to installer linker to specify the max size of each embedded resource. Defaults to 32Mb.
* Added `auto_start` setup configuration parameter that defines whether to automatically start installation in full UI mode.
* Added `auto_continue_on_reboot` setup configuration parameter that defines whether to auto-start installation after a reboot was forced during the installation.
* Added `reboot_cmd` setup configuration parameter that defines additional command-line parameters to include in the reboot command-line.
* Added `wait_for_complete_command` that defines whether to detach the complete command or to execute it synchronously and wait for the program to finish. Default is true.

Bugs
----

* Bug: wrong error when missing configuration.xml (invalid schema version vs. missing configuration.xml).
* Bug: reference (web) configurations broken in the editor.
* Bug: wrong semantics of `auto_close_if_installed`. The bootstrapper will now close after any successful installation session when this option is set.
* Bug: silent install failures pop up error dialogs that don't auto-close.
* Bug: EmbedFolder components broken when configuration is (re)saved with InstallerEditor.

Misc
----

* Refactored the dotNetInstaller bootstrapper into a dotNetInstallerLib C++ library and a GUI driver.
* Extended unit test coverage across C# and C++ installer and support tools libraries.

1.6 (6/29/2009)
===============

* First release off (CodePlex](http://www.codeplex.com/dotnetinstaller].
* New MSI installer. You can use the installer or a binary distribution package.
* New, largely rewritten, CHM documentation.
* Changed behavior of file embedding to explicit: disabled automatic embedding of files from `msi`, `download` and `openfile` components, set `/Embed` to `True` by default.
* Added an `EmbedFolder` configuration component to embed directories and subdirectories with an optional wildcard and configurable destination.
* Added parity between `EmbedFolder` and `EmbedFile` components which can be now specified in both the configuration and on the command line.
* InstallerLinker: embedded files that cannot be found are reported as errors with their full paths.
* InstallerLinker: Changed default value of `/AppPath`, now defaults to the current directory and not to the location of the configuration.xml.
* dotNetInstaller: embedded CABs are now segmented into 32-megabyte chunks. This reduces the minimum required memory for installers containing embedded CABs to about 48Mb, reduces paging and improves performance during extraction of large embedded CABs. Added editor and linker support for Windows Vista/XP 64.
* Added OS filter identifiers for Windows Server 2008.
* Added `InstalledCheckOperator` of 'And', 'Or' and 'Not' types that combine results from one or more `InstalledCheck` and `InstalledCheckOperator` elements.
* dotNetInstaller: Added `/componentArgs "component description":"parameters"` to dotNetInstaller.exe command line. This enables passing additional parameters to specific components declared in configuration.xml.
* InstallerEditor: added support for configuration file XML comments and a text box where the developer can edit a comment, saved as an xml comment above the selected node.
* InstallerEditor: configuration tree now supports deletion of nodes with the keyboard Delete key and will popup the Add menu with the Insert key.
* InstallerEditor: components can be dragged and dropped between nodes.
* InstallerEditor: the About box can be closed with the Escape key.
* InstallerEditor: added Expand All, Collapse All, Move, Move Up and Move Down context menu items.
* InstallerEditor: Shift+Up and Shift+Down arrows move components up and down.
* InstallerEditor: added support for multiline properties for most non-caption or button messages.
* InstallerEditor: added shortcuts to open a configuration file (Ctrl+O), create a new configuration file (Ctrl+N), save the current configuration (Ctrl+S), generate an exe (F10), exit (Alt+F4) and refresh (F5).
* InstallerEditor: user no longer prompted for a configuration file name on New.
* InstallerEditor: the New and Open menu items are always enabled.
* InstallerEditor: added a status strip that reports general information, including Save or Load.
* InstallerEditor: closing a configuration no longer prompts to save changes when there were no changes made.
* InstallerEditor: writes schema and generator version information to configuration.xml.
* Added `allow_continue_on_error` globally and per-component: when false user is no longer prompted to continue on error, instead the user is informed of the failure and installation aborts. Combine this option with `auto_close_on_error` to get predictable failure behavior as bootstrapper will close after an element of setup failed. Note that in order for a component to allow continuing on error both the global and the component setting must be set to True.
* DotNetInstaller: warns and offers the user to abort if configuration was not generated with a matching version of InstallerEditor.
* DotNetInstaller: merged functionality of the Advanced component selector into the main window, removed the Advanced button.
* Added `dialog_show_required`: when false, required components are hidden.
* Added `dialog_show_installed`: when false, installed components are hidden.
* Added `must_reboot_required`: globally and per-component. Setting this option to true will prevent users from continuing when a reboot is required.
* Added `failed_exec_command_continue` per-component extending the global setting that defines the message to show when a component fails to install.
* Added optional `reboot_required`: a message that can be configured per component, extending the global setting.
* Added `auto_close_on_error`: changes behavior on component error, now optionally closing the bootstrapper.
* Added a set of options that enable resizing of the main installer dialog elements: `dialog_position`, `dialog_components_list_position`, `dialog_message_position`, `dialog_bitmap_position`, `dialog_otherinfo_link_position`, `dialog_osinfo_position`, `dialog_install_button_position`, `dialog_cancel_button_position` and `dialog_skip_button_position`. Supports resizing coordinates selectively.
* Added `configuration_no_match_message` that displays as error when no configuration matching operating system, locale or processor architecture filters has been found. Removed unused `os_filter_not_match_message` and `processor_architecture_filter_not_match_message`.
* Added `#SYSTEMWINDOWSPATH` constant resolved to system Windows directory in paths.
* Added `#PID` constant resolved to process ID in paths.
* Added `embed` option to msi, openfile and download (sub)components to disable automatic file embedding.
* Added `lcidtype` option to the configuration file that can be set to the method to use to obtain the current LCID used to match a configuration. Now supports user.exe (KB181604), system and user methods.
* Expanded `status_installed` and `status_notinstalled` per-component.
* Download dialog `autostartdownload` default value is changed to `true`.
* Added `sourcepath` to support mixed-mode physical media distribution scenarios where frequently required components are embedded and other components downloaded.
* dotNetInstaller process exit code is now 0 on success, MSI return code on an MSI component failure, process exit code on a non-zero cmd component return, -2 on cancel from main dialog and -1 on any other error. Check `%ERRORLEVEL%` in batch scripts.
* Silent install support was extended to a full UI, basic UI and no UI mode, silent install no longer pops up progress dialogs, while basic UI install does without requiring user interaction. All UI modes are enabled via configuration and can be overriden from command line with /q (silent), /qb (basic UI) and /nq (full UI).
* Hidden folders and files are no longer embedded.
* Added `installation_none`, displayed instead of `installation_complete` when no components were required.
* Bug: cancel has no effect on the download dialog before download starts.
* Bug: download dialog will no longer appear when download is not required.
* Bug: command-line parameters are not preserved on reboot.
* Bug: /ComponentArgs cannot contain a colon.
* Bug: errors in command line arguments aren't reported.
* Bug: dotNetInstaller doesn't report invalid command-line parameters.

1.5 (10/25/2008)
================

* Added support for installing 64-bit applications, including WOW support for component installed checks, processor architecture restrictions per installation and/or component, etc.
* Added support for silent installs; silent mode can be declared either in the configuration XML or from the command line.
* Added command_silent to the component of type "command" and cmdparameters_silent to the component of type "msi" that optionally replace command and cmdparameters parameters in a silent install.
* Added an "alwaysdownload" configuration XML attribute to the download element; if this value is false, the file will not be download if it already exists locally (this enables using the same configuration XML for both online and offline installs).
* Modified configuration-level OS filter matching to be included as part of the configuration filter checks (previously, the program would exit if an unmatched configuration-level OS filter was encounter).
* Updated configuration element processing so that all valid configuration blocks (matching both OS and LCID filters) will be executed (previously, only the first matching block was executed).
* Added environment variable processing support to component commands where the component type is "cmd" or "msi".
* Modified complete_command handling so that dotNetInstaller will wait for Command_Complete to finish executing.
* Added complete_command_silent to allow overriding complete_command on silent install.
* Added OS filter identifiers for Windows XP SP3, Windows Server 2003 SP1, Windows Server 2003 SP2, and Windows Vista SP1.
* Added optional configuration-level and component-level OS filter matching system architecture (x86, x64, etc). See "processor_architecture_filter". This filter restricts the entire boostrapper from running on non-supported processors and enables installationof different dependencies on different processor architectures.
* Added CABing, embedding of support files using [Elmue's CAB library](http://www.codeproject.com/KB/files/CABCompressExtract.aspx) and a PackagedSetup sample.
* Added an "Embed File" component, child of "configuration" and "component", to embed support files when /Embed is specified.
* Added /ExtractCab command line option to dotNetInstaller.exe that extracts the embedded CAB file and its contents in the current directory.
* Added InstallerLinker.exe with command line options /e (Embed) and /a (AppPath) and /v (Verbose) for using in build processes.
* Added /EmbedFile and /EmbedFolder command line options to InstallerLinker to embed individual files and folder structures.
* Added support for embedding an icon that can replace the default setup icon.
* Added "cab_dialog_message", "cab_cancelled_message", "cab_dialog_caption", "cab_path" and "cab_path_autodelete" options.
* Temporary files (eg. downloaded files) will be deleted upon completion of dotNetInstaller.
* Added /Log command-line option and "log_enabled" configuration file parameter that enables logging for dotNetInstaller and all MSI components executed.
* Added /LogFile &lt;path\filename&gt; command-line option and a log_file configuration file parameter to specify the resulting full path to the log filename for the dotNetInstaller itself.
* Added application version and operating system header to the log output as well as a timestamp in front of every log entry.
* Added #CABPATH variable that can be used in path settings.
* Added #GUID variable that represents a unique GUID across a single instance of dotNetInstaller.
* Added an MSBuild script that centrally versions, builds and packages dotNetInstaller into target/Debug|Release, including a sample.
* Added a combined Visual Studio solution, dni.sln with automatic versioning (reqiures [MSBuild Community Tasks](http://msbuildtasks.tigris.org/); the major and minor version number can be incremented in dni.proj, the build number is the latest SVN revision and the release number is a timestamp.
* Added features to specify additional binary information, including copyright or company name, specifically "file_version" and "product_version" configuration attributes, as well as free-formed string attributes, using [ResourceLib](http://www.codeproject.com/KB/library/ResourceLib.aspx).
* Added a component "required" option; a required component cannot be de-selected in the Advanced tab and complete_command is only executed when all reqiured components have been installed.
* Added /CompleteCommandArgs "value" to dotNetInstaller.exe to pass additional parameters to "complete_command" and "complete_command_silent".
* Added horizontal scrollbars in component lists that can't fit all the text in.


1.3.3.0 (3/19/2007)
===================

* dotNetInstaller can now recognize Windows Vista (Thanks to Rennie Petersen)
* Included .NET 2 components on the InstallerEditor templates (Thanks to Rennie Petersen)
* Added OS filter functionality. You can now specify on which OS your setup will be running.
* In the complete_command you can now use environment variables (e.g. %Temp%)
* A template for german language is available in the InstallerEditor\templates\ folder (Thanks to Rainer Halanek for the translation)
* Converted the projects to Visual Studio 2005 format.
* InstallerEditor runs now on top of .NET Framework 2.0.
* For a registry search the root key is now selectable. (Thanks to Steve)
* For a registry search you can check if a registry field for a registry key exists. (Thanks to Steve)
* For a registry search you can check if a registry value contains a string. (Thanks to James Muchmore)
* For a registry search you can now check multiline string values (REG_MULTI_SZ). (Thanks to James Muchmore)
* Removed the old "Component Wizard" command of the InstallerEditor, now replaced by the wizard that read from the template file (components.xml)
* Added to subversion a "Samples" folder with the structure of the SupportFiles folder and one sample application

1.2.2.0 (8/3/2004)
==================

* New article section: Samples.
* Changed the timeout of the download to 20 seconds.
* Fixed a bug when loading configuration file from the resources, used by the "Build Exe" features.
* Added Win2000 Sp4 at "Component Wizard" list.
* Added Win2000 Sp3 as requirements for Jet 4 Sp8.
* Changed the samples with the service pack 4 of Win 2000 and used the auto download features with the Web Setup Sample.
* Updated Sample directory in the zip file.
* Fixed a bug when reading and writing unicode strings using RegQueryValueEx and RegSetValueEx (used for the autorun fetures and registry features)
* Changed utility function FileExistsCustom using GetFileAttributes. This seems to be the best way to check if a file exist.
* Added a new Component Wizard to InstallerEditor (Component Wizard 2) with the Italian version of the Components and an easier customization. The wizard use a resource file (components.xml) to populate the available components so you can add you custom component using this file. This change has no impact on the final configuration file.
* Added NT4 Sp6 High Encryption, NT4 Sp6 Standard Encryption and MDAC 2.8 Italian to the directory of SupportFiles.
* The configuration XML structure is the same as the previous release, you can use the same configuration files.

1.2.0.0 (6/24/2004)
===================

* New article sections: "Multilanguage features", "1.1.0.2 to 1.2.0.0 changes of XML file", "Deploy dotNetInstaller" and "System Requirements Notes".
* Improved dotNetInstaller userinterface for a better interaction and a more customizable setup for advanced users.
* Changed structure of XML configuration file for new features, you can use the Installer Editor to update your old configuration files.
* Before using the TEMP directory check if the directory exist and if not exist try to create it (see GetTempPath function on MSDN help).
* Added a progress bar control when installing components, thanks to Peter Mares for (a new progress bar for all occassions](http://www.codeproject.com/miscctrl/kcbusyprogress.asp].
* Now the editor can use a list of template files to customize the language of the intstaller.
* Added a customizable link at the bottom of the main dialog, thanks to Franz Wong for [Simple Hyperlink Static Control](http://www.codeguru.com/Cpp/controls/staticctrl/article.php/c5801/).
* Added full UTF-8 support fot the configuration file, the editor and the installer.
* Now dotNetInstaller is compiled using UNICODE for full compatibility with non English language. For Win 9x and ME now you must distribuite with dotNetInstaller.exe the Microsoft Layer for Unicode, unicows.dll.
* Now I use TinyXml to parse XML file for best compatibility on UTF-8 and XML standards.
* Added enum for Windows Xp Sp2 (winXPsp2 = 82).
* Added "/log" command line parameters for dotNetInstaller to enable a basic log file during installation.
* Now using auto_close_if_installed attribute and complete_command you can close automatically dotNetInstaller when all the components are installed and execute an optional commands.
* Updated the structure of the SupportFiles directory and added MDAC 2.8, Jet4 Sp8.
* Removed Y2K Update for Windows 98 in the list of requirements components.
* Improved InstallerEditor and added wizard for MDAC 2.8, Internet Explorer 6Sp1, Jet 4 Sp8 and NT4 Sp6a.
* Changed some steps of the tutorials to add unicows.dll and to zip the web setup.
* Fixed command line parameters for MDAC installation quiet mode.
* Changed the tutorials for "How to create a Web Setup to install .NET Framework and your msi setup".

1.1.0.2 (1/6/2004)
==================

* Removed SourceCode control from the projects.

1.1.0.2 (1/2/2004)
==================

* Added ability to download required components from the web.
* Added #TEMPPATH path variable.
* Editor to create and modify XML configuration file.
* Many changes to the XML structure, old files are not compatible.
* Fixed a bug on the function that reads the operating system LCID.

1.0.8.0 (11/5/2003)
===================

* Added #WINDOWSPATH path constant.

1.0.7.0 (9/28/2003)
===================

* Bug fixed on MDAC and JET components configuration file (registry check to REG_SZ and language support for JET).

1.0.7.0 (9/27/2003)
===================

* First public release.

