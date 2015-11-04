#include "stdafx.h"
#include "Map.h"
#include <stdlib.h>
#include <time.h>

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

//WIP
void Map::updateTaupe() {
	srand(time(NULL));
	int spawn = rand() % 20 + 1;
	if (spawn == 2) {
		int size = (int) this->map.size();
		int num = rand() % size;
		Trou* trou = this->map[num];
		while (trou->getTaupe()) {
			num = rand() % size;
			trou = this->map[num];
		}
		trou->setTaupe(true);

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
