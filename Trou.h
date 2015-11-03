#pragma once

#include <Windows.h>

class Trou
{
private:
	bool taupe;

public:
	Trou();
	void draw(CHAR_INFO* buffer, COORD bufferSize, int x, int y, char lettre);
	bool getTaupe() const { return this->taupe; }
	void setTaupe(bool the_taupe) { this->taupe = the_taupe; }
	~Trou();
};

