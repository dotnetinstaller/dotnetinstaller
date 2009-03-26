#pragma once

class InstalledCheck;
class InstalledCheckOperator;

#include "DownloadDialogSupport.h"

enum component_type
{
	cmd, //shell command
	msi, //windows installer setup
	openfile //ShellExecute call to open a file
};

class Component
{
public:
    Component();
    virtual ~Component();
public:
    // dialog where to post messages to
    CDialog * m_pDialog;
	// component type: cmd, msi, openfile
	component_type type;
	// component description
	CString description;
	// component status when installed
	CString status_installed;
	// component status when not installed
	CString status_notinstalled;
	// filtro che indica il minimo sistema operativo in cui lanciare il componente (estremo escluso)
	CString os_filter_greater;
	// filtro che indica il massimo sistema operativo in cui lanciare il componente (estremo escluso)
	CString os_filter_smaller;
	// filtro che indica il filtro per lingua del sistema operativo (es. Italy = 1040, English - United Kingdom = 2057, English - United States = 1033)
	CString os_filter_lcid;
	// testo da visualizzare a fine installazione (se vuoto non visualizza niente)
	CString installcompletemessage;
	// true per forzare il reboot al termine dell'installazione altrimenti false
	bool mustreboot;
    // message for a reboot after this component
    CString reboot_required;
    // true to force a reboot when required
    bool must_reboot_required;
    // message to display on error
    CString failed_exec_command_continue;
    // allow to continue setup on error
    bool allow_continue_on_error;
	// filter for processor architecture
	CString processor_architecture_filter;
    // cancelled by user
    bool cancelled;
    // true if component is required for final command to execute
    bool required;
	// classi per gestire la verifica se il componente è installato o no
	std::vector<InstalledCheck*> installedchecks;
	// informazioni sull'eventuale download dei componenti (fa riferimento al nodo downloaddialog all'interno di Component, se non è presente non viene scaricato nessun componente)
	DVLib::DownloadGroupConfiguration DownloadDialogConfiguration;
	// indica se il componente contiene o meno dei componenti da scaricare (in pratica dice se il nodo downloaddialog è presente o no)
	bool ContainsDownloadComponent;
	// scarica gli eventuali componenti necesari e restituisce true se il download ha avuto successo
	bool DownloadComponents(CWnd * p_Parent);
	// funzione virtuale specifica per il tipo di componente
	virtual bool Exec() = 0;
	virtual DWORD GetExitCode() = 0;
	virtual bool IsExecuting() = 0;
	virtual void Init(CDialog * pDialog = NULL);
	bool IsInstalled();
	// indica se il componente verrà eseguito o no
	bool selected;
};
