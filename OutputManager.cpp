#include "stdafx.h"
#include "OutputManager.h"


OutputManager::OutputManager()
{
	hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);
	dwBufferSize = { SCREEN_WIDTH, SCREEN_HEIGHT };

	dwBufferCoord = { 0, 0 };
	rcRegion = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };
}


OutputManager::~OutputManager()
{
}

void OutputManager::init()
{
	SetConsoleScreenBufferSize(hOutput, dwBufferSize);

	//Maximiser la taille de la fenêtre
	HWND hwnd = GetForegroundWindow();
	ShowWindow(hwnd, SW_MAXIMIZE);
}

void OutputManager::read()
{
	ReadConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
		dwBufferCoord, &rcRegion);
}

void OutputManager::draw()
{
	WriteConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
		dwBufferCoord, &rcRegion);
}
