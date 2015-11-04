#pragma once

#include "Map.h"
#include "OutputManager.h"
#include "Joueur.h"

class GameManager
{
private:
	/*
	Attribut oManager
	Gère l'affichage
	*/
	OutputManager oManager;

	/*
	Attribut map
	Permet de gérer la liste des trous et les taupes
	*/
	Map map;

	/*
	Attribut joueur
	Permet de calculer le score et de gérer les clics de souris
	*/
	Joueur joueur;

public:
	/*
	Constructeur
	*/
	GameManager();
	
	/*
	Méthode init
	Permet de créer les trous
	*/
	void init();

	/*
	Méthode gameLoop
	Gère le jeu
	*/
	void gameLoop();

	/*
	Destructeur
	*/
	~GameManager();
};
