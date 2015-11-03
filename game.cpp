// Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#define WIN32_LEAN_AND_MEAN
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#include <iostream>

using namespace std;

void trou(CHAR_INFO* buffer, COORD bufferSize, int x, int y, CHAR lettre) {
	(buffer + ((x + 1)*bufferSize.X + y))->Char.AsciiChar = lettre;
	(buffer + ((x + 2)*bufferSize.X + y))->Char.AsciiChar = lettre;
	(buffer + ((x + 1)*bufferSize.X + y + 4))->Char.AsciiChar = lettre;
	(buffer + ((x + 2)*bufferSize.X + y + 4))->Char.AsciiChar = lettre;
	(buffer + (x*bufferSize.X + y + 1))->Char.AsciiChar = lettre;
	(buffer + (x*bufferSize.X + y + 2))->Char.AsciiChar = lettre;
	(buffer + (x*bufferSize.X + y + 3))->Char.AsciiChar = lettre;
	(buffer + ((x + 3)*bufferSize.X + y + 1))->Char.AsciiChar = lettre;
	(buffer + ((x + 3)*bufferSize.X + y + 2))->Char.AsciiChar = lettre;
	(buffer + ((x + 3)*bufferSize.X + y + 3))->Char.AsciiChar = lettre;
}

int _tmain(int argc, _TCHAR* argv[])
{
	HANDLE hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

	COORD dwBufferSize = { SCREEN_WIDTH, SCREEN_HEIGHT };

	SetConsoleScreenBufferSize(hOutput, dwBufferSize);

	//Maximiser la taille de la fenêtre
	HWND hwnd = GetForegroundWindow();
	ShowWindow(hwnd, SW_MAXIMIZE);

	COORD dwBufferCoord = { 0, 0 };
	SMALL_RECT rcRegion = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };

	CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

	while (!GetAsyncKeyState(VK_ESCAPE)) {

		ReadConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
			dwBufferCoord, &rcRegion);

		/*buffer[5][10].Char.AsciiChar = 'H';
		buffer[5][10].Attributes = 0x0E;
		buffer[5][11].Char.AsciiChar = 'i';
		buffer[5][11].Attributes = 0x0B;
		buffer[5][12].Char.AsciiChar = '!';
		buffer[5][12].Attributes = 0x0A;*/

		trou((CHAR_INFO *)buffer, dwBufferSize, 2, 50, 'O');
		trou((CHAR_INFO *)buffer, dwBufferSize, 2, 60, 'O');
		trou((CHAR_INFO *)buffer, dwBufferSize, 2, 50, 'O');
		trou((CHAR_INFO *)buffer, dwBufferSize, 2, 60, 'O');
		trou((CHAR_INFO *)buffer, dwBufferSize, 2, 50, 'O');
		trou((CHAR_INFO *)buffer, dwBufferSize, 2, 60, 'O');
		trou((CHAR_INFO *)buffer, dwBufferSize, 2, 50, 'O');
		trou((CHAR_INFO *)buffer, dwBufferSize, 2, 60, 'O');

		WriteConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
			dwBufferCoord, &rcRegion);

	}
	return 0;
}

