#include "stdafx.h"
#include "Joueur.h"
#include <time.h>

/*
Constructeur
*/
Joueur::Joueur() :
timer_marteau(),
souris(1)
{
	//Initialisation du timer du marteau
	timer_marteau.start();
	srand((unsigned int)time(NULL));
}

/*
Méthode qui permet de récupérer les coordonnées du clic
*/
COORD Joueur::jouer() {
	souris.update();

	//Si le bouton gauche de la souris est cliqué
	if (souris.isMouseLeftButtonPressed() == 1) {
		//Si le clic a eu lieu pendant la latence du marteau, on renvoie -1
		if (timer_marteau.getElapsedSeconds() < freq_marteau) {
			return{ -1, -1 };
		}
		timer_marteau.start();
		//Sinon on renvoie les coordonnées
		return souris.getMousePos();
	}
	return{ -1, -1 };
}

/*
Destructeur
*/
Joueur::~Joueur()
{
}
