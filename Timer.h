#pragma once

#include <Windows.h>

class Timer
{
private:
	LARGE_INTEGER lastUpdateTime;
	LONGLONG freq;

public:
	Timer();
	~Timer();



	void start();
	float getElapsedSeconds(bool restart = false);
	unsigned long getElapsedMs(bool restart = false);
};

