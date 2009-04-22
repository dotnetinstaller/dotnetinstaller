#pragma once

#include "DownloadComponent.h"

class DownloadGroupConfiguration
{
public:
	//caption della finestra di download
	CString Caption;
	//messaggio visualizzato nella finestra di download prima che il download cominci (o perchè l'utente preme il tasto Start o perchè è impostato autodownload)
	CString HelpMessage;
	//messaggio visualizzato nella finestra di download quando il download è in corso
	CString HelpMessageDownloading;
	//Testo del bottone di start
	CString ButtonStartCaption;
	//Testo del bottone di Cancel
	CString ButtonCancelCaption;
	//Elenco componenti da scaricare
	DownloadComponentInfoVector Components;
	//Indica se iniziare automaticamente il download appena la finestra viene aperta
	bool AutoStartDownload;
	DownloadGroupConfiguration();
	bool Run(CWnd * p_Parent);
};
