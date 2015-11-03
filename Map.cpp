#include "stdafx.h"
#include "Map.h"

using namespace std;

/*
Constructeur de Map
*/
Map::Map()
{
}

/*
Méthode estDisponible
Permet de savoir si une place pour un trou avec le coin haut gauche dont les coordonnées sont x et y est disponible
*/
bool Map::estDisponible(int x, int y) const {
	int largeur = Trou::getLargeur();
	int hauteur = Trou::getHauteur();
	//à compléter
	return true;
}

/*
Méthode ajouterTrou
Permet de créer un trou et de l'ajouter dans la liste
*/
void Map::ajouterTrou(int x, int y) {
	this->map.push_back(new Trou(x, y));
}

/*
Méthode draw
Permet de dessiner tous les trous contenus dans la liste
*/
void Map::draw(CHAR_INFO* buffer, COORD dwBufferSize) const {
	for (unsigned int i(0); i < this->map.size(); i++) {
		this->map[i]->draw(buffer, dwBufferSize, 'O');
	}
}

/*
Destructeur
*/
Map::~Map()
{
	for (unsigned int i(0); i < this->map.size(); i++) {
		delete map[i];
	}
}
