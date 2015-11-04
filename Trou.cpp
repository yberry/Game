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
	//Pour chaque colonne
	for (int i(0); i < largeur; i++) {
		//Et pour chaque ligne
		for (int j(0); j < hauteur; j++) {
			//Sauf les coins
			if ((i != 0 && i != largeur - 1) || (j != 0 && j != hauteur - 1)) {
				//On ajoute le caractère dans le buffer
				(buffer + ((m_y + j)*bufferSize.X + m_x + i))->Char.AsciiChar = lettre;
			}
		}
	}

	//Pour chaque colonne à l'intérieur du trou
	for (int i(1); i < largeur - 1; i++) {
		//Et pour chaque ligne à l'intérieur du trou
		for (int j(1); j < hauteur - 1; j++) {
			//On remplit avec un autre caractère ou on l'enlève selon la présence de la taupe
			(buffer + ((m_y + j)*bufferSize.X + m_x + i))->Char.AsciiChar = (this->m_taupe ? 'X' : ' ');
		}
	}
}

/*
Méthode qui permet de savoir si on a cliqué sur une taupe
*/
bool Trou::hit(COORD clic) {
	//S'il n'y a pas de taupe
	if (!this->m_taupe)
		return false;

	//S'il y a une taupe et que l'on clique dans le trou
	if (m_x < clic.X && clic.X < (m_x + largeur - 1) && m_y < clic.Y && clic.Y < (m_y + hauteur - 1)) {
		this->m_taupe = false;
		return true;
	} else {
		return false;
	}
}

/*
Destructeur
*/
Trou::~Trou()
{
}
