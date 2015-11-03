#include "stdafx.h"
#include "Map.h"

using namespace std;

Map::Map()
{
}

bool Map::estDisponible(int x, int y) const {
	int largeur = Trou::getLargeur();
	int hauteur = Trou::getHauteur();
	//à compléter
	return true;
}

void Map::ajouterTrou(int x, int y) {
	this->map.push_back(new Trou(x, y));
}

void Map::draw(CHAR_INFO* buffer, COORD dwBufferSize) const {
	for (unsigned int i(0); i < this->map.size(); i++) {
		this->map[i]->draw(buffer, dwBufferSize, 'O');
	}
}

Map::~Map()
{
	for (unsigned int i(0); i < this->map.size(); i++) {
		delete map[i];
	}
}
