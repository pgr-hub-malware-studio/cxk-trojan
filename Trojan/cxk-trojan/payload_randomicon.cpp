#include "payloads.h"

DWORD WINAPI payload_randomicon(LPVOID argument)
{
	int ScreenWidth = GetSystemMetrics(SM_CXSCREEN);
	int ScreenHeight = GetSystemMetrics(SM_CYSCREEN);

	HDC hdc = GetDC((HWND)0);
	HICON Icons[] = { LoadIcon(NULL, IDI_INFORMATION), LoadIcon(NULL, IDI_WARNING), LoadIcon(NULL, IDI_ERROR) };

	while(1)
	{
		DrawIcon(hdc, rand() % ScreenWidth, rand() % ScreenHeight, Icons[rand() % 3]);
	}

	return 0;
}
