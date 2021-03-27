#include "pch.h"
#include "NoInput.h"
#define PLUGIN_NAME "No Input"

BOOL emurunning;

void CALL GetDllInfo(PLUGIN_INFO* PluginInfo)
{
	PluginInfo->Version = 0x0101; // 0x0100 will not work. it triggers a check for old plugins which breaks this one sometimes :/
								  // this is a new plugin so yeah
	PluginInfo->Type = PLUGIN_TYPE_CONTROLLER;
	wsprintfA(PluginInfo->Name, PLUGIN_NAME); // wsprintf will not work because this confuses the preprocessor and expands to wsprintfw
}
//EXPORT void CALL DllConfig(HWND hParent)
//{
//	if (emurunning) {
//		MessageBox(hParent, L"No config... yet.", L"", MB_OK | MB_TOPMOST | MB_TASKMODAL);
//	}
//}

EXPORT void CALL DllAbout(HWND hParent)
{
	MessageBox(hParent, L"No input\nBy Aurumaker72", L"", MB_OK | MB_TOPMOST | MB_TASKMODAL);
}


//EXPORT void CALL RomClosed(void) {
//	emurunning = FALSE;
//}
//EXPORT void CALL RomOpen(void) {
//	emurunning = TRUE;
//}

