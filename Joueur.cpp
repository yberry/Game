#include "stdafx.h"
#include "Joueur.h"
#include "Utils.h"
#include <time.h>

/*
Constructeur
*/
Joueur::Joueur() :
timer_marteau(),
souris(1),
frappe(false)
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
		frappe = true;
		timer_marteau.start();
		//Sinon on renvoie les coordonnées
		return souris.getMousePos();
	}
	return{ -1, -1 };
}

void Joueur::draw(CHAR_INFO* buffer, COORD bufferSize)
{
	COORD pos = souris.getMousePos();
	
	if (pos.X - 1 < 0)
		pos.X = 1;
	else if (pos.X + 6 > bufferSize.X - 1)
		pos.X = bufferSize.X - 6 - 1;

	if (pos.Y - 4 < 0)
		pos.Y = 4;
	else if (pos.Y > bufferSize.Y - 1)
		pos.Y = bufferSize.Y - 1;

	if (frappe)
	{
		drawChar(buffer, bufferSize, '_', pos.X + 2, pos.Y - 1);
		drawChar(buffer, bufferSize, '_', pos.X + 3, pos.Y - 1);
		drawChar(buffer, bufferSize, '_', pos.X + 4, pos.Y - 1);		

		drawBackground(buffer, bufferSize, BACKGROUND_INTENSITY, pos.X, pos.Y - 1);
		drawBackground(buffer, bufferSize, BACKGROUND_INTENSITY, pos.X, pos.Y);
		

		if (timer_marteau.getElapsedSeconds() >= freq_marteau)
			frappe = false;
	}
	else
	{
		drawChar(buffer, bufferSize, '|', pos.X + 4, pos.Y - 2);
		drawChar(buffer, bufferSize, '|', pos.X + 4, pos.Y - 1 );

		drawBackground(buffer, bufferSize, BACKGROUND_INTENSITY, pos.X + 3, pos.Y - 3);
		drawBackground(buffer, bufferSize, BACKGROUND_INTENSITY, pos.X + 4, pos.Y - 3);
		drawBackground(buffer, bufferSize, BACKGROUND_INTENSITY, pos.X + 5, pos.Y - 3);
	}
}

/*
Destructeur
*/
Joueur::~Joueur()
{
}
