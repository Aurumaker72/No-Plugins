#include "Main.h"

EXPORT void CALL GetDllInfo(PLUGIN_INFO *PluginInfo) {
  PluginInfo->Version = 0x100;
  PluginInfo->Type = PLUGIN_TYPE_CONTROLLER;
  wsprintfA(PluginInfo->Name, PLUGIN_NAME);
}

EXPORT void CALL DllAbout(HWND hParent) {
  MessageBox(hParent, L"No input plugin.", L"", MB_ICONINFORMATION | MB_OK);
}

EXPORT void CALL InitiateControllers(HWND hMainWindow, CONTROL Controls[4])
{
	for (size_t i = 0; i < 4; i++)
	{
		Controls[i].Present = false;
		Controls[i].Plugin = 1;
		Controls[i].RawData = false;
	}

	Controls[0].Present = true;
}
