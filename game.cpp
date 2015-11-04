// Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define WIN32_LEAN_AND_MEAN
#define SCREEN_WIDTH 200
#define SCREEN_HEIGHT 80
#include <iostream>
#include "Map.h"

using namespace std;

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

	Map map;

	map.ajouterTrou(5, 50);
	map.ajouterTrou(5, 60);
	map.ajouterTrou(15, 45);
	map.ajouterTrou(15, 55);
	map.ajouterTrou(15, 65);
	map.ajouterTrou(25, 50);
	map.ajouterTrou(25, 60);

	while (!GetAsyncKeyState(VK_ESCAPE)) {

		ReadConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
			dwBufferCoord, &rcRegion);		

		map.updateTaupe();
		map.draw((CHAR_INFO *)buffer, dwBufferSize);

		WriteConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
			dwBufferCoord, &rcRegion);

	}
	return 0;
}









/*buffer[5][10].Char.AsciiChar = 'H';
buffer[5][10].Attributes = 0x0E;
buffer[5][11].Char.AsciiChar = 'i';
buffer[5][11].Attributes = 0x0B;
buffer[5][12].Char.AsciiChar = '!';
buffer[5][12].Attributes = 0x0A;
*/
