// gethwnd.cpp: определяет точку входа для консольного приложения.
//

#include "windows.h"

#define BUFLEN		100

int main()
{
	HWND h = GetConsoleWindow();
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CHAR strbuf[BUFLEN];
	size_t buflength = BUFLEN * sizeof(TCHAR);

	wsprintfA(strbuf, "%d\n", h);
	/*--StringCchPrintf - this function use stdlib
	if (FAILED(::StringCchPrintf(strbuf, buflength, TEXT("%d"), h)))
		ExitProcess(1);*/

	size_t strlen = lstrlenA(strbuf);
	
	/*if (FAILED(StringCchLength(strbuf, buflength, &strlen)))
		ExitProcess(2);*/
	
	DWORD chw = 0;
	//WriteConsole(hStdout, strbuf, strlen, &chw, NULL);
	WriteFile(hStdout, strbuf, strlen, &chw, NULL);
	
	ExitProcess(0);
}
