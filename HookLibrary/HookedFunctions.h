#pragma once

#include <windows.h>


#define STATUS_PORT_NOT_SET        ((NTSTATUS)0xC0000353L)
#define STATUS_HANDLE_NOT_CLOSABLE ((NTSTATUS)0xC0000235L)

#ifndef _WIN64
#define NAKED __declspec(naked)
#else
#define NAKED
#endif

typedef struct _SAVE_DEBUG_REGISTERS {
	DWORD dwThreadId;
	DWORD_PTR Dr0;
	DWORD_PTR Dr1;
	DWORD_PTR Dr2;
	DWORD_PTR Dr3;
	DWORD_PTR Dr6;
	DWORD_PTR Dr7;
} SAVE_DEBUG_REGISTERS;

//DbgBreakPoint

NTSTATUS NTAPI HookedNtSetInformationThread(HANDLE ThreadHandle, THREADINFOCLASS ThreadInformationClass, PVOID ThreadInformation, ULONG ThreadInformationLength);
NTSTATUS NTAPI HookedNtQuerySystemInformation(SYSTEM_INFORMATION_CLASS SystemInformationClass, PVOID SystemInformation, ULONG SystemInformationLength, PULONG ReturnLength);
NTSTATUS NTAPI HookedNtQueryInformationProcess(HANDLE ProcessHandle, PROCESSINFOCLASS ProcessInformationClass, PVOID ProcessInformation, ULONG ProcessInformationLength, PULONG ReturnLength);
NTSTATUS NTAPI HookedNtQueryObject(HANDLE Handle, OBJECT_INFORMATION_CLASS ObjectInformationClass, PVOID ObjectInformation, ULONG ObjectInformationLength, PULONG ReturnLength);
NTSTATUS NTAPI HookedNtYieldExecution();
NTSTATUS NTAPI HookedNtGetContextThread(HANDLE ThreadHandle, PCONTEXT ThreadContext);
NTSTATUS NTAPI HookedNtSetContextThread(HANDLE ThreadHandle, PCONTEXT ThreadContext);
NTSTATUS NTAPI HookedNtContinue(PCONTEXT ThreadContext, BOOLEAN RaiseAlert);
NTSTATUS NTAPI HookedNtSetInformationProcess(HANDLE ProcessHandle, PROCESSINFOCLASS ProcessInformationClass, PVOID ProcessInformation, ULONG ProcessInformationLength);
NTSTATUS NTAPI HookedNtClose(HANDLE Handle);
NTSTATUS NTAPI HookedNtSetDebugFilterState(ULONG ComponentId, ULONG Level, BOOLEAN State);
NTSTATUS NTAPI HookedNtUserBuildHwndList(HDESK hdesk, HWND hwndNext, BOOL fEnumChildren, DWORD idThread, UINT cHwndMax, HWND *phwndFirst, PUINT pcHwndNeeded);

BOOL WINAPI HookedBlockInput(BOOL fBlockIt);
DWORD WINAPI HookedGetTickCount(void);
DWORD WINAPI HookedOutputDebugStringA(LPCSTR lpOutputString);
VOID NTAPI HookedKiUserExceptionDispatcher();//(PEXCEPTION_RECORD pExcptRec, PCONTEXT ContextFrame);

HWND NTAPI HookedNtUserFindWindowEx(HWND hWndParent, HWND hWndChildAfter, PUNICODE_STRING lpszClass, PUNICODE_STRING lpszWindow, DWORD dwType);
