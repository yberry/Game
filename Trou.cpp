#include "stdafx.h"
#include "Trou.h"


Trou::Trou() :
taupe(false)
{
}

void Trou::draw(CHAR_INFO* buffer, COORD bufferSize, int x, int y, char lettre) {
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


Trou::~Trou()
{
}
