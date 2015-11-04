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
Méthode pour dessiner un trou avec le buffer de la console
*/
void Trou::draw(CHAR_INFO* buffer, COORD bufferSize, char lettre) const {
	//Pour chaque ligne
	for (int i(0); i < hauteur; i++) {
		//Et pour chaque colonne
		for (int j(0); j < largeur; j++) {
			//Sauf les coins
			if ((i != 0 && i != hauteur - 1) || (j != 0 && j != largeur - 1)) {
				//On ajoute la lettre dans le buffer
				(buffer + ((m_x + i)*bufferSize.X + m_y + j))->Char.AsciiChar = lettre;
			}
		}
	}

	//Pour chaque ligne à l'intérieur du trou
	for (int i(1); i < hauteur - 1; i++) {
		//Et pour chaque colonne à l'intérieur du trou
		for (int j(1); j < largeur - 1; j++) {
			//On remplit avec un autre caractère ou on l'enlève selon la présence de la taupe
			(buffer + ((m_x + i)*bufferSize.X + m_y + j))->Char.AsciiChar = (this->m_taupe ? 'X' : ' ');
		}
	}
}

/*
Destructeur
*/
Trou::~Trou()
{
}
