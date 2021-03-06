#include "stdafx.h"
#include "Map.h"
#include <stdlib.h>

using namespace std;

/*
Constructeur de Map
*/
Map::Map() :_spawnTimer(), _nbMaxTaupes(4)
{
	_spawnTimer.start();	
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

		if (abs(x - _x) < largeur && abs(y - _y) < hauteur) {
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
		this->map[i]->draw(buffer, dwBufferSize, '-');
	}
}

/*
Méthode updateTaupe
Permet de gérer la disparition et l'appartion des taupes.
*/
void Map::updateTaupe() {

	///////////////////HIDE MECHANIC :

	vector<list<SpawnedTaupeInfo>::iterator> iterators_to_erase;	//Contiendra les éléments à supprimer sur la liste des taupes présentes.

	//Pour toutes les taupes présentes :
	for (list<SpawnedTaupeInfo>::iterator it = _spawnedTaupesInfo.begin(); it != _spawnedTaupesInfo.end(); ++it)
	{
		//Si il est temps pour la taupe de rentrer dans son trou :
		if (it->timer.getElapsedSeconds() >= _hideDelay)
		{
			map[it->indice]->hideTaupe();	
			iterators_to_erase.push_back(it);
		}
	}

	//Suppression des infos des taupes qui viennent de se cacher :
	for (unsigned int i = 0; i < iterators_to_erase.size(); i++)
		_spawnedTaupesInfo.erase(iterators_to_erase[i]);

	///////////////////SPAWN MECHANIC :

	//Si on doit encore attendre avant de spawner une taupe, on sort de la fonction
	if (_spawnTimer.getElapsedSeconds() < _spawnFreq)
		return;

	//On relance le timer et on détermine un nouveau délaiu avant le porchain spawn
	_spawnTimer.start();
	_spawnFreq = 0.5f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (2.5f - 0.5f)));

	//Si on a pas atteint le maximum de taupes
	if (_spawnedTaupesInfo.size() < _nbMaxTaupes)
	{
		int num = 0;

		//On trouve un trou libre
		do
		{
			num = rand() % this->map.size();
		} while (this->map[num]->isOccupied());

		//On fait spawner la taupe :
		this->map[num]->spawnTaupe();
		SpawnedTaupeInfo taupeInfo = { num, Timer() };
		taupeInfo.timer.start();
		_spawnedTaupesInfo.push_back(taupeInfo);
	}
}

/*
Méthode qui permet de vérifier le clic sur une taupe
*/
int Map::hit(COORD clic) {
	int hit_result = 0;
	//Pour chaque trou
	for (unsigned int i(0); i < this->map.size(); i++) {
		//On vérifie le clic
		hit_result = this->map[i]->hit(clic);
		if (hit_result != 0) {
			//Si on touche, on enlève la taupe de la liste
			for (list <SpawnedTaupeInfo>::iterator it = _spawnedTaupesInfo.begin(); it != _spawnedTaupesInfo.end(); ++it)
			{
				if (it->indice == i)
				{
					_spawnedTaupesInfo.erase(it);
					break;
				}									
			}
			return hit_result;
		}
	}

	return 0;
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
