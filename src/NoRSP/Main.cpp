#include "Main.h"

EXPORT void CALL GetDllInfo(PLUGIN_INFO *PluginInfo) {
  PluginInfo->Version = 0x100;
  PluginInfo->Type = PLUGIN_TYPE_RSP;
  wsprintfA(PluginInfo->Name, PLUGIN_NAME);
}

EXPORT void CALL DllAbout(HWND hParent) {
  MessageBox(hParent, L"No RSP plugin.", L"", MB_ICONINFORMATION | MB_OK);
}
