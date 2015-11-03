#include "stdafx.h"
#include "Trou.h"

int Trou::largeur = 5;
int Trou::hauteur = 4;

Trou::Trou(int x, int y) :
m_x(x),
m_y(y),
m_taupe(false)
{
}

void Trou::draw(CHAR_INFO* buffer, COORD bufferSize, char lettre) const {
	(buffer + ((m_x + 1)*bufferSize.X + m_y))->Char.AsciiChar = lettre;
	(buffer + ((m_x + 2)*bufferSize.X + m_y))->Char.AsciiChar = lettre;
	(buffer + ((m_x + 1)*bufferSize.X + m_y + 4))->Char.AsciiChar = lettre;
	(buffer + ((m_x + 2)*bufferSize.X + m_y + 4))->Char.AsciiChar = lettre;
	(buffer + (m_x*bufferSize.X + m_y + 1))->Char.AsciiChar = lettre;
	(buffer + (m_x*bufferSize.X + m_y + 2))->Char.AsciiChar = lettre;
	(buffer + (m_x*bufferSize.X + m_y + 3))->Char.AsciiChar = lettre;
	(buffer + ((m_x + 3)*bufferSize.X + m_y + 1))->Char.AsciiChar = lettre;
	(buffer + ((m_x + 3)*bufferSize.X + m_y + 2))->Char.AsciiChar = lettre;
	(buffer + ((m_x + 3)*bufferSize.X + m_y + 3))->Char.AsciiChar = lettre;
}


Trou::~Trou()
{
}
