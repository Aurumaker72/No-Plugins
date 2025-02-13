#pragma once

#include <Windows.h>

#if defined(__cplusplus)
extern "C" {
#endif

#ifdef _M_X64
#define PLUGIN_ARCH "-x64"
#else
#define PLUGIN_ARCH "-x86"
#endif
#define PLUGIN_NAME "No Input" PLUGIN_ARCH

#define PLUGIN_TYPE_RSP 1
#define PLUGIN_TYPE_GFX 2
#define PLUGIN_TYPE_AUDIO 3
#define PLUGIN_TYPE_CONTROLLER 4

#define PLUGIN_NONE 1
#define PLUGIN_MEMPAK 2
#define PLUGIN_RUMBLE_PAK 3
#define PLUGIN_TANSFER_PAK 4
#define PLUGIN_RAW 5

#define EXPORT __declspec(dllexport)
#define CALL _cdecl

typedef struct {
  WORD Version;
  WORD Type;
  char Name[100];
  BOOL Reserved1;
  BOOL Reserved2;
} PLUGIN_INFO;

using CONTROL = struct
{
    BOOL Present;
    BOOL RawData;
    int Plugin;
};

typedef struct {
  HWND hWnd;       /* Render window */
  HWND hStatusBar; /* if render window does not have a status bar then this is
                      NULL */

  BOOL MemoryBswaped; // If this is set to TRUE, then the memory has been pre
                      //   bswap on a dword (32 bits) boundry
                      //	eg. the first 8 bytes are stored like this:
                      //        4 3 2 1   8 7 6 5

  BYTE *HEADER; // This is the rom header (first 40h bytes of the rom
                // This will be in the same memory format as the rest of the
                // memory.
  BYTE *RDRAM;
  BYTE *DMEM;
  BYTE *IMEM;

  DWORD *MI_INTR_REG;

  DWORD *DPC_START_REG;
  DWORD *DPC_END_REG;
  DWORD *DPC_CURRENT_REG;
  DWORD *DPC_STATUS_REG;
  DWORD *DPC_CLOCK_REG;
  DWORD *DPC_BUFBUSY_REG;
  DWORD *DPC_PIPEBUSY_REG;
  DWORD *DPC_TMEM_REG;

  DWORD *VI_STATUS_REG;
  DWORD *VI_ORIGIN_REG;
  DWORD *VI_WIDTH_REG;
  DWORD *VI_INTR_REG;
  DWORD *VI_V_CURRENT_LINE_REG;
  DWORD *VI_TIMING_REG;
  DWORD *VI_V_SYNC_REG;
  DWORD *VI_H_SYNC_REG;
  DWORD *VI_LEAP_REG;
  DWORD *VI_H_START_REG;
  DWORD *VI_V_START_REG;
  DWORD *VI_V_BURST_REG;
  DWORD *VI_X_SCALE_REG;
  DWORD *VI_Y_SCALE_REG;

  void (*CheckInterrupts)(void);
} GFX_INFO;

  
  using BUTTONS = union {
    DWORD Value;

    struct
    {
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

      signed X_AXIS : 8;

      signed Y_AXIS : 8;
    };
  };


EXPORT void CALL DllAbout(HWND hParent);
EXPORT void CALL GetDllInfo(PLUGIN_INFO *PluginInfo);
EXPORT void CALL InitiateControllers(HWND hMainWindow, CONTROL Controls[4]);
EXPORT void CALL GetKeys(int Control, BUTTONS* Keys);
  
#if defined(__cplusplus)
}
#endif