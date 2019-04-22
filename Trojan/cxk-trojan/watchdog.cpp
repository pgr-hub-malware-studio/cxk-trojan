#include "watchdog.h"

DWORD WINAPI WatchDog_Thread(LPVOID Argument)
{
	int process_count = 0;

	while (1)
	{
		char CurrentFilename[MAX_PATH];
		GetProcessImageFileName(GetCurrentProcess(), CurrentFilename, MAX_PATH);

		HANDLE ProcessSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		if (ProcessSnapshot == INVALID_HANDLE_VALUE)
			return 0;

		PROCESSENTRY32 pe;
		pe.dwSize = sizeof(PROCESSENTRY32);
		if(!Process32First(ProcessSnapshot, &pe))
			return 0;

		int process_current = 0;
		do
		{
			HANDLE TargetHandle = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, pe.th32ProcessID);
			if (TargetHandle == 0)
				continue;

			char TargetFilename[MAX_PATH];
			GetProcessImageFileName(TargetHandle, TargetFilename, MAX_PATH);

			if (strcmp(TargetFilename, CurrentFilename) == 0)
				process_current++;
				
			CloseHandle(TargetHandle);
		} while (Process32Next(ProcessSnapshot, &pe));

		CloseHandle(ProcessSnapshot);
		
		if (process_current < process_count)
		{
			Artillery_Fire();
			return 0;
		}

		process_count = process_current;

		Sleep(50);
	}
	return 0;
}
