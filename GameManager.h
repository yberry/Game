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
	Permet de gérer les clics de souris
	*/
	Joueur joueur;

	/*
	Attribut temps
	Temps restant avant la fin de la partie
	*/
	int temps = 10;

	/*
	Attribut score
	Temps total passé par le joueur à taper les taupes
	*/
	int score = 0;

	/*
	Attribut _time
	Timer servant à faire s'écouler les secondes
	*/
	Timer _time;

	/*
	Attribut freq_score
	Règle la fréquence du timer
	*/
	float freq_score = 1;

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
	Méthode showScore
	Permet d'afficher le temps restant du jeu à partir d'un point de coordonnées {x, y} donné
	*/
	void showTime(CHAR_INFO *buffer, COORD dwBufferSize, int x, int y) const;

	/*
	Méthode endGame
	Permet d'effacer la map et d'afficher le score en fin de partie
	*/
	void endGame(CHAR_INFO *buffer, COORD dwBufferSize) const;

	/*
	Destructeur
	*/
	~GameManager();
};
