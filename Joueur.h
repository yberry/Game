#pragma once

#include "Timer.h"
#include "InputManager.h"

class Joueur
{
private:
	/*
	Attribut timer_marteau
	Permet de limiter la cadence de frappe du marteau
	*/
	Timer timer_marteau;

	/*
	Attribut souris
	Permet de recevoir les clics de souris
	*/
	InputManager souris;

	/*
	Attribut freq_marteau
	Permet de régler le temps d'inactivité du marteau
	*/
	float freq_marteau = 0.5f;

	bool frappe;
	
public:
	/*
	Constructeur
	*/
	Joueur();

	/*
	Méthode jouer
	Permet de récupérer les coordonnées du clic
	*/
	COORD jouer();

	/*
	Méthode draw
	Permet de dessiner le marteau du joueur
	*/
	void draw(CHAR_INFO* buffer, COORD bufferSize);

	/*
	Destructeur
	*/
	~Joueur();
};

