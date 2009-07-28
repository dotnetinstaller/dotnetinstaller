#pragma once

#include "DownloadDialog.h"
#include "EmbedFile.h"
#include "InstalledCheck.h"

enum component_type
{
	undefined = 0, 
	cmd, // shell command
	msi, // windows installer setup
	msu, // windows update
	openfile // ShellExecute call to open a file
};

class Component
{
public:
    Component(component_type t);
    virtual ~Component();
public:
	// component type: cmd, msi, openfile
	component_type type;
	// component description
	std::wstring description;
	// component status when installed
	std::wstring status_installed;
	// component status when not installed
	std::wstring status_notinstalled;
	// filtro che indica il minimo sistema operativo in cui lanciare il componente (estremo escluso)
	std::wstring os_filter_greater;
	// filtro che indica il massimo sistema operativo in cui lanciare il componente (estremo escluso)
	std::wstring os_filter_smaller;
	// filtro che indica il filtro per lingua del sistema operativo (es. Italy = 1040, English - United Kingdom = 2057, English - United States = 1033)
	std::wstring os_filter_lcid;
	// testo da visualizzare a fine installazione (se vuoto non visualizza niente)
	std::wstring installcompletemessage;
	// true per forzare il reboot al termine dell'installazione altrimenti false
	bool mustreboot;
    // message for a reboot after this component
    std::wstring reboot_required;
    // true to force a reboot when required
    bool must_reboot_required;
    // message to display on error
    std::wstring failed_exec_command_continue;
    // allow to continue setup on error
    bool allow_continue_on_error;
	// filter for processor architecture
	std::wstring processor_architecture_filter;
    // cancelled by user
    bool cancelled;
    // true if component is required for final command to execute
    bool required;
	// classi per gestire la verifica se il componente è installato o no
	std::vector<InstalledCheckPtr> installedchecks;
	// informazioni sull'eventuale download dei componenti (fa riferimento al nodo downloaddialog all'interno di Component, se non è presente non viene scaricato nessun componente)
	DownloadDialogPtr downloaddialog;
	// embedded files
	std::vector< EmbedFilePtr > embedfiles;
	// funzione virtuale specifica per il tipo di componente
	virtual void Exec() = 0;
	virtual void Wait(DWORD tt = 1000);
	virtual bool IsRebootRequired() const { return mustreboot; }
	virtual bool IsExecuting() const = 0;
	virtual bool IsInstalled() const;
	// indica se il componente verrà eseguito o no
	bool selected;
	// load a component from an xml node
	virtual void Load(TiXmlElement * node);
	// returns true if this component is supported on this operating system/lcid
	virtual bool IsSupported(DVLib::LcidType lcidtype) const;
	virtual int GetExitCode() const = 0;
};

typedef shared_any<Component *, close_delete> ComponentPtr;
