#include "pch.h"
#include <string.h>

#include "NoInput.h"
#include <minwindef.h>
#include <Windows.h>


EXPORT void CALL GetDllInfo(PLUGIN_INFO* PluginInfo)
{
	PluginInfo->Version = 0x0101; // 0x0100
	PluginInfo->Type = PLUGIN_TYPE_CONTROLLER;
	wsprintfA(PluginInfo->Name, PLUGIN_NAME); // wsprintf will not work because this confuses the preprocessor
}

EXPORT void CALL DllAbout(HWND hParent)
{
	MessageBox(hParent, L"No input\nby Aurumaker72", L"", MB_ICONINFORMATION | MB_OK);
}

