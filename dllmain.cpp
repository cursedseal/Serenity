// dllmain.cpp : Defines the entry point for the DLL application.
#include "SDK.h"

HINSTANCE UnHook_Instance;
void InitialThread(void);

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	DisableThreadLibraryCalls(hModule);
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		if (AllocConsole())
		{
			freopen_s((FILE**)stdin, "CONIN$", "r", stdin);
			freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
			freopen_s((FILE**)stdout, "CONOUT$", "w", stderr);
		}

		SetConsoleTitleA("cheatName"); // cheatName
		UnHook_Instance = hModule;
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)InitialThread, 0, 0, 0);
	}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}