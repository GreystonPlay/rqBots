#include <Windows.h>
#include "cheat.h"
#include <cstdint>
#include <string>
#include <fstream>
#include <iostream>
#pragma comment(lib, "user32")

using namespace std;


WNDPROC oWndProc;
HWND hGame{ FindWindow(0, "Royal Quest") };
int mainOffset = 0x7E9368;
int CurrentWID{ };
int old_protect{ };
DWORD PlayerPosX{ DeRef(DeRef((DWORD)GetModuleHandle(0) + mainOffset) + 0x4) + 0x23C };
DWORD PlayerPosY{ DeRef(DeRef((DWORD)GetModuleHandle(0) + mainOffset) + 0x4) + 0x240 };
DWORD PlayerHealth{ DeRef(DeRef((DWORD)GetModuleHandle(0) + mainOffset) + 0x4) + 0x204 };
DWORD MouseCord{ DeRef(DeRef((DWORD)GetModuleHandle(0) + mainOffset) + 0x4) + 0x208 };
DWORD MouseEvent{ DeRef(DeRef((DWORD)GetModuleHandle(0) + mainOffset) + 0x4) + 0x20C };
DWORD accIdptr{ ((DWORD)GetModuleHandle(0)) + 0x7EB7D4 };
DWORD WordlID{ ((DWORD)GetModuleHandle(0)) + 0x6A2284 };
DWORD AdrSpeed{ ((DWORD)GetModuleHandle(0) + 0xAD14C) };
BOOL BotStatus{ 1 }, SpeedHack{ 0 }, savePos{ 0 };
float MCord{ 10 };
float MEvent{ 5 };
// 40-49 991346588; 1387840084 204.1203766 124.2634048
float gCordX = 0.0f;
float gCordY = 0.0f;



DWORD WINAPI GameThread(LPVOID lParam)
{
	for (;; Sleep(200))
		
	{
		accIdfunc();

		ifstream file("D:\\Programm\\Microsoft Visual Studio\\source\\repos\\Royal Quest\\rqBots\\rqSpec.txt");
		file >>gCordX>>gCordY>>BotStatus;
		
		if (GetAsyncKeyState(VK_END) & 1) {
			SetWindowLong(hGame, GWLP_WNDPROC, (LONG)(UINT_PTR)oWndProc);
			FreeLibraryAndExitThread(GetModuleHandleA("Project5"), 0);
			MessageBox(0, "Close Message", "Delete DLL", MB_OK);
		}
		if (savePos == 1) {
			memRead(PlayerPosX, &gCordX, 4);
			memRead(PlayerPosY, &gCordY, 4);
		}
		if (SpeedHack == 1) {
			int actSpeed = 3246604332;
			memWrite(AdrSpeed, &actSpeed, 4);
		}
		else if (SpeedHack == 0) {
			int actSpeed = 3246604316;
			memWrite(AdrSpeed, &actSpeed, 4);
		}
		
		if (BotStatus == 1)
		{

			memRead(WordlID, &CurrentWID, 4);
			int CurrentHP{};
			memRead(PlayerHealth, &CurrentHP, 4);

			// Башня 
			if (CurrentWID == 1058262330) {
				Sleep(100);
				float CordX = -7.430754662f;
				float CordY = 8.960902214f;
				memWrite(PlayerPosX, &CordX, 4);
				memWrite(PlayerPosY, &CordY, 4);
				memWrite(MouseCord, &MCord, 4);
				memWrite(MouseEvent, &MEvent, 4);
				CallWindowProcA(oWndProc, hGame, WM_MOUSEMOVE, 0, MAKELONG(343, 424));
				CallWindowProcA(oWndProc, hGame, WM_LBUTTONDOWN, 0, MAKELONG(343, 424));
				CallWindowProcA(oWndProc, hGame, WM_LBUTTONUP, 0, MAKELONG(343, 424));
				CallWindowProcA(oWndProc, hGame, WM_MOUSEMOVE, 0, MAKELONG(335, 331));
				CallWindowProcA(oWndProc, hGame, WM_LBUTTONDOWN, 0, MAKELONG(335, 331));
				CallWindowProcA(oWndProc, hGame, WM_LBUTTONUP, 0, MAKELONG(335, 331));
			}
			// Мельница
			if (CurrentWID == 1046081534) {
				int CordX = 3232235520;
				int CordY = 3228565504;
				memWrite(PlayerPosX, &CordX, 4);
				memWrite(PlayerPosY, &CordY, 4);
				memWrite(MouseCord, &MCord, 4);
				memWrite(MouseEvent, &MEvent, 4);
				Sleep(100);
				CallWindowProcA(oWndProc, hGame, WM_MOUSEMOVE, 0, MAKELONG(319, 232));
				CallWindowProcA(oWndProc, hGame, WM_LBUTTONDOWN, 0, MAKELONG(319, 232));
				CallWindowProcA(oWndProc, hGame, WM_LBUTTONUP, 0, MAKELONG(319, 232));
			}
			// Подвал с мельницы
			if (CurrentWID == (int)3194391926) {
				int CordX = 3246391296;
				int CordY = 1065353216;
				memWrite(PlayerPosX, &CordX, 4);
				memWrite(PlayerPosY, &CordY, 4);
				memWrite(MouseCord, &MCord, 4);
				memWrite(MouseEvent, &MEvent, 4);
			}
			// ПвП 20+
			if (CurrentWID == 1012096358) {
				memWrite(PlayerPosX, &gCordX, 4);
				memWrite(PlayerPosY, &gCordY, 4);
				memWrite(MouseCord, &MCord, 4);
				memWrite(MouseEvent, &MEvent, 4);
			}
			if (CurrentHP == 0)
			{
				Sleep(4000);
				CallWindowProcA(oWndProc, hGame, WM_MOUSEMOVE, 0, MAKELONG(414, 427));
				CallWindowProcA(oWndProc, hGame, WM_LBUTTONDOWN, 0, MAKELONG(414, 427));
				CallWindowProcA(oWndProc, hGame, WM_LBUTTONUP, 0, MAKELONG(414, 427));
				Sleep(1000);
				CallWindowProcA(oWndProc, hGame, WM_MOUSEMOVE, 0, MAKELONG(493, 431));
				CallWindowProcA(oWndProc, hGame, WM_LBUTTONDOWN, 0, MAKELONG(493, 431));
				CallWindowProcA(oWndProc, hGame, WM_LBUTTONUP, 0, MAKELONG(493, 431));
				Sleep(200);
				CallWindowProcA(oWndProc, hGame, WM_MOUSEMOVE, 0, MAKELONG(346, 213));
				CallWindowProcA(oWndProc, hGame, WM_LBUTTONDOWN, 0, MAKELONG(346, 213));
				CallWindowProcA(oWndProc, hGame, WM_LBUTTONUP, 0, MAKELONG(346, 213));
			}
		}

		else if (BotStatus == 0)
		{

		}
	}

}

UINT_PTR DeRef(UINT_PTR _uiptrPointer) {
	UINT_PTR uiptrRet;
	DWORD oProtect = NULL;
	VirtualProtect((LPVOID)_uiptrPointer, 100, PAGE_EXECUTE_READWRITE, &oProtect);
	if (!::ReadProcessMemory(GetCurrentProcess(), reinterpret_cast<LPVOID>(_uiptrPointer), &uiptrRet, sizeof(uiptrRet), NULL)) { return 0UL; }
	VirtualProtect((LPVOID)_uiptrPointer, 100, oProtect, &oProtect);
	return uiptrRet;
}

LRESULT APIENTRY WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_KEYUP:
	{
		switch (wParam)
		{
		case VK_NUMPAD1:
		{
			BotStatus = 1;
			break;
		}
		case VK_NUMPAD2:
		{
			BotStatus = 0;
			break;
		}

		case VK_NUMPAD4: {
			SpeedHack = 1;
			break;
		}
		case VK_NUMPAD5: {
			SpeedHack = 0;
			break;
		}
		case VK_NUMPAD3: {
			savePos = 1;
			break;
		}
		case VK_NUMPAD6: {
			savePos = 0;
			break;
		}

		}
	}
	}
	return CallWindowProcA(oWndProc, hwnd, uMsg, wParam, lParam);
}

void memRead(DWORD address, void* buffer, DWORD size) {
	DWORD oProtect{};
	VirtualProtect((void*)address, size, PAGE_EXECUTE_READWRITE, &oProtect);
	ReadProcessMemory(GetCurrentProcess(), (void*)address, buffer, size, 0);
	VirtualProtect((void*)address, size, oProtect, &oProtect);
}

void memWrite(DWORD address, void* buffer, DWORD size) {
	DWORD oProtect{};
	VirtualProtect((void*)address, size, PAGE_EXECUTE_READWRITE, &oProtect);
	WriteProcessMemory(GetCurrentProcess(), (void*)address, buffer, size, 0);
	VirtualProtect((void*)address, size, oProtect, &oProtect);
}

BOOL WINAPI DllMain(HINSTANCE hModule, DWORD dwAttached, LPVOID lpvReserved)
{
	if (dwAttached == DLL_PROCESS_ATTACH) {
		CreateThread(NULL, 0, &GameThread, NULL, 0, NULL);
		oWndProc = (WNDPROC)(UINT_PTR)SetWindowLong(hGame, GWLP_WNDPROC, (LONG)(UINT_PTR)WndProc);
	}
	return 1;
}

void accIdfunc()
{
	int idcur = 0;
	memRead(accIdptr, &idcur, 4);

	switch (idcur)
	{
		// Granas
	case 3156366: SetWindowText(hGame, "gstone3@mail.ru");
		break;
	case 3156368: SetWindowText(hGame, "gstone4@mail.ru");
		break;
	case 3156371: SetWindowText(hGame, "gstone6@mail.ru");
		break;
	case 3156372: SetWindowText(hGame, "gstone7@mail.ru");
		break;
	case 3156373: SetWindowText(hGame, "gstone8@mail.ru");
		break;
	case 3156374: SetWindowText(hGame, "gstone9@mail.ru");
		break;
	case 3156376: SetWindowText(hGame, "gstone10@mail.ru");
		break;
	case 3186928: SetWindowText(hGame, "gstone11@mail.ru");
		break;
	case 3186929: SetWindowText(hGame, "gstone12@mail.ru");
		break;
	case 3186930: SetWindowText(hGame, "gstone13@mail.ru");
		break;
	case 3186932: SetWindowText(hGame, "gstone15@mail.ru");
		break;
	default: SetWindowText(hGame, "Роял Квест");
		break;
	}
}