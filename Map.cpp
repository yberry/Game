#include "stdafx.h"
#include "Map.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

/*
Constructeur de Map
*/
Map::Map() :_timer(), _nbMaxTaupes(3)
{
	_timer.start();
	srand((unsigned int)(time(NULL)));
}

/*
Méthode estDisponible
Permet de savoir si une place pour un trou avec le coin haut gauche dont les coordonnées sont x et y est disponible
*/
bool Map::estDisponible(int x, int y) const {
	int largeur = Trou::getLargeur();
	int hauteur = Trou::getHauteur();

	for (unsigned int i(0); i < this->map.size(); i++) {
		int _x = this->map[i]->getX();
		int _y = this->map[i]->getY();

		if (abs(x - _x) < hauteur && abs(y - _y) < largeur) {
			return false;
		}
	}

	return true;
}

/*
Méthode ajouterTrou
Permet de créer un trou et de l'ajouter dans la liste
*/
void Map::ajouterTrou(int x, int y) {
	if (this->estDisponible(x, y)) {
		this->map.push_back(new Trou(x, y));
	}
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

	for (unsigned int i = 0; i < _spawnedTaupes.size(); i++)
	{
		if (_hideTimers[i].getElapsedSeconds() >= _hideDelay)
		{
			map[_spawnedTaupes[i]]->setTaupe(false);
			_spawnedTaupes.erase(_spawnedTaupes.begin() + i);
			_hideTimers.erase(_hideTimers.begin() + i);
		}
	}


	if (_timer.getElapsedSeconds() < _spawnFreq)
		return;
	
	_timer.start();	
	_spawnFreq = 1.0f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (3.0f - 1.0f)));

	if (_spawnedTaupes.size() < _nbMaxTaupes)
	{
		int num = 0;
		
		do
		{
			num = rand() % this->map.size();
		} while (this->map[num]->getTaupe());
		
		this->map[num]->setTaupe(true);
		_spawnedTaupes.push_back(num);
		_hideTimers.push_back(Timer());
		_hideTimers[_hideTimers.size() - 1].start();
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
