
#ifndef _NOINPUT_H_INCLUDED__
#define _NOINPUT_H_INCLUDED__

#if defined(__cplusplus)
extern "C" {
#endif


#define PLUGIN_NAME "No Input"

#define PLUGIN_TYPE_CONTROLLER		4

#define PLUGIN_NONE					1
#define PLUGIN_MEMPAK				2
#define PLUGIN_RUMBLE_PAK			3
#define PLUGIN_TANSFER_PAK			4
#define PLUGIN_RAW					5


#define EXPORT						__declspec(dllexport)
#define CALL						_cdecl

	typedef struct {
		WORD Version;  
		WORD Type;     
		char Name[100];
		BOOL Reserved1;
		BOOL Reserved2;
	} PLUGIN_INFO;

	typedef struct {
		BOOL Present;
		BOOL RawData;
		int  Plugin;
	} CONTROL;

	typedef union {
		DWORD Value;
		struct {
			unsigned R_DPAD : 1;
			unsigned L_DPAD : 1;
			unsigned D_DPAD : 1;
			unsigned U_DPAD : 1;
			unsigned START_BUTTON : 1;
			unsigned Z_TRIG : 1;
			unsigned B_BUTTON : 1;
			unsigned A_BUTTON : 1;

			unsigned R_CBUTTON : 1;
			unsigned L_CBUTTON : 1;
			unsigned D_CBUTTON : 1;
			unsigned U_CBUTTON : 1;
			unsigned R_TRIG : 1;
			unsigned L_TRIG : 1;
			unsigned Reserved1 : 1;
			unsigned Reserved2 : 1;

			signed   Y_AXIS : 8;

			signed   X_AXIS : 8;
		};
	} BUTTONS;

	typedef struct {
		HWND hMainWindow;
		HINSTANCE hinst;

		BOOL MemoryBswaped;
						
		BYTE* HEADER;	
		CONTROL* Controls;
						
	} CONTROL_INFO;

	EXPORT void CALL CloseDLL(void);
	EXPORT void CALL ControllerCommand(int Control, BYTE* Command);
	EXPORT void CALL DllAbout(HWND hParent);
	EXPORT void CALL DllConfig(HWND hParent);
	EXPORT void CALL DllTest(HWND hParent);
	EXPORT void CALL GetDllInfo(PLUGIN_INFO* PluginInfo);
	EXPORT void CALL GetKeys(int Control, BUTTONS* Keys);
	EXPORT void CALL InitiateControllers(CONTROL_INFO ControlInfo);
	EXPORT void CALL ReadController(int Control, BYTE* Command);
	EXPORT void CALL RomClosed(void);
	EXPORT void CALL RomOpen(void);
	EXPORT void CALL WM_KeyDown(WPARAM wParam, LPARAM lParam);
	EXPORT void CALL WM_KeyUp(WPARAM wParam, LPARAM lParam);


#if defined(__cplusplus)
}
#endif
#endif