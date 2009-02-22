// stdafx.h : file di inclusione per file di inclusione del sistema standard
// o file di inclusione specifici del progetto utilizzati di frequente,
// ma modificati di rado.

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN		// Escludere dalle intestazioni Windows gli elementi utilizzati di rado.
#endif

// Modificare le seguenti definizioni se è necessario creare una piattaforma prima di quelle specificate di seguito.
// Fare riferimento a MSDN per le ultime informazioni sui valori corrispondenti per le differenti piattaforme.
#ifndef WINVER				// È consentito l'utilizzo di funzionalità specifiche per Windows 95 e Windows NT 4 o versioni successive.
#define WINVER 0x0400		// Cambiare il valore immettendo quello corretto per Windows 98, Windows 2000 o versione successiva.
#endif

#ifndef _WIN32_WINNT		// È consentito l'utilizzo di funzionalità specifiche per Windows NT 4 o versioni successive.
#define _WIN32_WINNT 0x0400		// Cambiare il valore immettendo quello corretto per Windows 98, Windows 2000 o versione successiva.
#endif						

#ifndef _WIN32_WINDOWS		// È consentito l'utilizzo di funzionalità specifiche per Windows 98 o versioni successive.
#define _WIN32_WINDOWS 0x0410 // Cambiare il valore immettendo quello corretto per Windows Millennium Edition o versione successiva.
#endif

#ifndef _WIN32_IE			// È consentito l'utilizzo di funzionalità specifiche per IE 4.0 o versioni successive.
#define _WIN32_IE 0x0400	// Cambiare il valore immettendo quello corretto per Internet Explorer 5.0 o versione successiva.
#endif

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// alcuni costruttori CString saranno espliciti.

// disattiva l'operazione delle classi MFC che consiste nel nascondere alcuni comuni messaggi di avviso che vengono spesso ignorati.
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // componenti MFC di base e standard
#include <afxext.h>         // estensioni MFC
#include <afxdisp.h>        // classi di automazione MFC

#include <afxdtctl.h>		// Supporto MFC per controlli comuni di Internet Explorer 4
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// Supporto MFC per controlli comuni di Windows
#endif // _AFX_NO_AFXCMN_SUPPORT

