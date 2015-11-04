#pragma once

#include <Windows.h>

#define SCREEN_WIDTH 200
#define SCREEN_HEIGHT 80

class OutputManager
{
private :
	HANDLE hOutput;
	COORD dwBufferCoord;
	SMALL_RECT rcRegion;
	

public:
	COORD dwBufferSize;
	CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

	OutputManager();
	~OutputManager();

	void init();
	void read();
	void draw();
};

