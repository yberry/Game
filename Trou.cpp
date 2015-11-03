#include "stdafx.h"
#include "Trou.h"

//Définition de la largeur d'un trou
int Trou::largeur = 5;

//Définition de la hauteur d'un trou
int Trou::hauteur = 4;

/*
Constructeur du trou
Les coordonnées du coin haut gauche sont données et la taupe est par défaut sous terre
*/
Trou::Trou(int x, int y) :
m_x(x),
m_y(y),
m_taupe(false)
{
}

/*
Méthode pour dessiner un trou
*/
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

/*
Destructeur
*/
Trou::~Trou()
{
}
