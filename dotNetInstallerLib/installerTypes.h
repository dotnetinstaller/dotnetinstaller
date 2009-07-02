#pragma once
#include "Component.h"
#include "InstallUILevel.h"

//in tutti i percorsi viene sostituito #APPPATH con il percorso dell'applicazione corrente, #SYSTEMPATH con la directory System del computer e #WINDOWSPATH con la directory di installazione di Windows, #TEMPPATH con la directory temporanea
//in all the paths we replace the string constant #APPPATH with the current path of the application and #SYSTEMPATH with the system directory of the computer, #TEMPPATH with the temp directory

#define c_APPPATH TEXT("#APPPATH")
#define c_SYSTEMPATH TEXT("#SYSTEMPATH")
#define c_WINDOWSPATH TEXT("#WINDOWSPATH")
#define c_SYSTEMWINDOWSPATH TEXT("#SYSTEMWINDOWSPATH")
#define c_TEMPPATH TEXT("#TEMPPATH")
#define c_CABPATH TEXT("#CABPATH")
#define c_GUID TEXT("#GUID")
#define c_PID TEXT("#PID")

// top-level configuration settings
struct configSetting
{
	InstallUILevel ui_level;
};
