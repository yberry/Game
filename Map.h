#pragma once

#include <vector>
#include <list>
#include "Trou.h"
#include "Timer.h"

struct SpawnedTaupeInfo
{
	unsigned int indice;
	Timer timer;
};

class Map
{
private:
	/*
	Attribut map
	Permet de stocker les trous créés
	*/
	std::vector<Trou*> map;
	std::list<SpawnedTaupeInfo> _spawnedTaupesInfo;
	float _spawnFreq = 2;
	float _hideDelay = 1.5;
	Timer _spawnTimer;
	float _nbMaxTaupes;

public:
	/*
	Constructeur de Map
	*/
	Map();

	/*
	Méthode estDisponible
	Permet de savoir si une place pour un trou avec le coin haut gauche dont les coordonnées sont x et y est disponible
	*/
	bool estDisponible(int x, int y) const;

	/*
	Méthode ajouterTrou
	Permet de créer un trou et de l'ajouter dans la liste
	*/
	void ajouterTrou(int x, int y);

	/*
	Méthode draw
	Permet de dessiner tous les trous contenus dans la liste
	*/
	void draw(CHAR_INFO* buffer, COORD dwBufferSize) const;

	/*
	Méthode updateTaupe
	Permet de gérer la disparition et l'appartion des taupes.
	*/
	void updateTaupe();

	/*
	Méthode hit
	Permet de vérifier le clic sur une taupe
	*/
	bool hit(COORD clic);

	/*
	Destructeur
	*/
	~Map();
};
