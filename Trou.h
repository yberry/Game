#pragma once

#include <Windows.h>

class Trou
{
private:
	bool m_taupe;
	int m_x;
	int m_y;
	static int largeur;
	static int hauteur;

public:
	Trou(int x, int y);
	void draw(CHAR_INFO* buffer, COORD bufferSize, char lettre) const;
	bool getTaupe() const { return this->m_taupe; }
	void setTaupe(bool taupe) { this->m_taupe = taupe; }
	static int getLargeur() { return largeur; }
	static int getHauteur() { return hauteur; }
	~Trou();
};

