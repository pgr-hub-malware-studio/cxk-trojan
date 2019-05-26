#pragma once
#include <Windows.h>
#include <TlHelp32.h>
#include <Psapi.h>

#include "payloads.h"

#define RUN_AS_WATCHDOG_IDENTIFICATION "watchdog"

DWORD WINAPI WatchDog_Thread(LPVOID Argument);
void Artillery_Fire();
