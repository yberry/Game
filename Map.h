#pragma once

#include <vector>
#include "Trou.h"

class Map
{
private:
	/*
	Attribut map
	Permet de stocker les trous créés
	*/
	std::vector<Trou*> map;

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
	Destructeur
	*/
	~Map();
};

