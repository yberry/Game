#include "stdafx.h"
#include "Timer.h"

#include <windows.h>

Timer::Timer()
{
	QueryPerformanceCounter(&lastUpdateTime);
	LARGE_INTEGER li_freq;
	QueryPerformanceFrequency(&li_freq);
	freq = li_freq.QuadPart;
	freq /= 1000;
}

Timer::~Timer()
{
}


void Timer::start()
{
	QueryPerformanceCounter(&lastUpdateTime);
}

float Timer::getElapsedSeconds(bool restart)
{
	LARGE_INTEGER timeNow;
	QueryPerformanceCounter(&timeNow);
	LONGLONG elapsedLong = timeNow.QuadPart - lastUpdateTime.QuadPart;

	float elapsed = (float)((float)elapsedLong / (float)freq);
	elapsed /= 1000.0f;

	if (restart)
		lastUpdateTime = timeNow;

	return elapsed;
}

unsigned long Timer::getElapsedMs(bool restart)
{
	LARGE_INTEGER timeNow;
	QueryPerformanceCounter(&timeNow);
	LONGLONG elapsedLong = timeNow.QuadPart - lastUpdateTime.QuadPart;

	unsigned long elapsed = (unsigned long)((float)elapsedLong / (float)freq);

	if (restart)
		lastUpdateTime = timeNow;

	return elapsed;
}
