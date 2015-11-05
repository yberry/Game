#include "stdafx.h"
#include "Trou.h"
#include "Utils.h"

//Définition de la largeur d'un trou
int Trou::largeur = 7;

//Définition de la hauteur d'un trou
int Trou::hauteur = 4;

/*
Constructeur du trou
Les coordonnées du coin haut gauche sont données et la taupe est par défaut sous terre
*/
Trou::Trou(int x, int y) :
m_x(x),
m_y(y),
_taupe_state(HIDDEN),
_animation_timer()
{
}



/*
Méthode pour dessiner un trou avec le buffer de la console
*/
void Trou::draw(CHAR_INFO* buffer, COORD bufferSize, char lettre) {
	//Pour chaque colonne
	for (int i(0); i < largeur; i++) {
		//Et pour chaque ligne
		for (int j(0); j < hauteur; j++) {
			//Sauf les coins
			if ((i != 0 && i != largeur - 1) || (j != 0 && j != hauteur - 1)) {
				//On ajoute le caractère dans le buffer
				(buffer + ((m_y + j)*bufferSize.X + m_x + i))->Char.AsciiChar = lettre;
				(buffer + ((m_y + j)*bufferSize.X + m_x + i))->Attributes = BACKGROUND_RED + BACKGROUND_GREEN;
			}
		}
	}

	switch (_taupe_state)
	{
		case(BAD_OUT) :					

			if (_animation_timer.getElapsedSeconds() < 0.15)
			{
				drawChar(buffer, bufferSize, '~', m_x + 1, m_y + 2);
				drawChar(buffer, bufferSize, '~', m_x + 2, m_y + 2);
				drawChar(buffer, bufferSize, '~', m_x + 3, m_y + 2);
				drawChar(buffer, bufferSize, '~', m_x + 4, m_y + 2);
				drawChar(buffer, bufferSize, '~', m_x + 5, m_y + 2);
				drawChar(buffer, bufferSize, '~', m_x + 1, m_y + 1);
				drawChar(buffer, bufferSize, '~', m_x + 2, m_y + 1);
				drawChar(buffer, bufferSize, '~', m_x + 3, m_y + 1);
				drawChar(buffer, bufferSize, '~', m_x + 4, m_y + 1);
				drawChar(buffer, bufferSize, '~', m_x + 5, m_y + 1);
			}
			else
			{
				drawChar(buffer, bufferSize, '/', m_x + 1, m_y + 1);
				drawChar(buffer, bufferSize, 'è', m_x + 2, m_y + 1);
				drawChar(buffer, bufferSize, ' ', m_x + 3, m_y + 1);
				drawChar(buffer, bufferSize, 'é', m_x + 4, m_y + 1);
				drawChar(buffer, bufferSize, '\\', m_x + 5, m_y + 1);
				drawChar(buffer, bufferSize, '(', m_x + 1, m_y + 2);
				drawChar(buffer, bufferSize, ' ', m_x + 2, m_y + 2);
				drawChar(buffer, bufferSize, '-', m_x + 3, m_y + 2);
				drawChar(buffer, bufferSize, ' ', m_x + 4, m_y + 2);
				drawChar(buffer, bufferSize, ')', m_x + 5, m_y + 2);
			}

			break;

		case(BAD_ANGRY): 		
			drawChar(buffer, bufferSize, ' ', m_x + 1, m_y + 1);
			drawChar(buffer, bufferSize, '>', m_x + 2, m_y + 1);
			drawChar(buffer, bufferSize, ' ', m_x + 3, m_y + 1);
			drawChar(buffer, bufferSize, '<', m_x + 4, m_y + 1);
			drawChar(buffer, bufferSize, ' ', m_x + 5, m_y + 1);
			drawChar(buffer, bufferSize, ' ', m_x + 1, m_y + 2);
			drawChar(buffer, bufferSize, ' ', m_x + 2, m_y + 2);
			drawChar(buffer, bufferSize, 'O', m_x + 3, m_y + 2);
			drawChar(buffer, bufferSize, ' ', m_x + 4, m_y + 2);
			drawChar(buffer, bufferSize, ' ', m_x + 5, m_y + 2);

			if (_animation_timer.getElapsedSeconds() >= 0.5)
				_taupe_state = HIDDEN;
			
			break;

		case(NICE_OUT):
			if (_animation_timer.getElapsedSeconds() < 0.15)
			{
				drawChar(buffer, bufferSize, '~', m_x + 1, m_y + 2);
				drawChar(buffer, bufferSize, '~', m_x + 2, m_y + 2);
				drawChar(buffer, bufferSize, '~', m_x + 3, m_y + 2);
				drawChar(buffer, bufferSize, '~', m_x + 4, m_y + 2);
				drawChar(buffer, bufferSize, '~', m_x + 5, m_y + 2);
				drawChar(buffer, bufferSize, '~', m_x + 1, m_y + 1);
				drawChar(buffer, bufferSize, '~', m_x + 2, m_y + 1);
				drawChar(buffer, bufferSize, '~', m_x + 3, m_y + 1);
				drawChar(buffer, bufferSize, '~', m_x + 4, m_y + 1);
				drawChar(buffer, bufferSize, '~', m_x + 5, m_y + 1);
			}
			else
			{
				drawChar(buffer, bufferSize, ' ', m_x + 1, m_y + 1);
				drawChar(buffer, bufferSize, '^', m_x + 2, m_y + 1);
				drawChar(buffer, bufferSize, ' ', m_x + 3, m_y + 1);
				drawChar(buffer, bufferSize, '^', m_x + 4, m_y + 1);
				drawChar(buffer, bufferSize, ' ', m_x + 5, m_y + 1);
				drawChar(buffer, bufferSize, '(', m_x + 1, m_y + 2);
				drawChar(buffer, bufferSize, ' ', m_x + 2, m_y + 2);
				drawChar(buffer, bufferSize, '-', m_x + 3, m_y + 2);
				drawChar(buffer, bufferSize, ' ', m_x + 4, m_y + 2);
				drawChar(buffer, bufferSize, ')', m_x + 5, m_y + 2);
			}

			break;

		case(NICE_SAD) :
			drawChar(buffer, bufferSize, '/', m_x + 1, m_y + 1);
			drawChar(buffer, bufferSize, 'x', m_x + 2, m_y + 1);
			drawChar(buffer, bufferSize, ' ', m_x + 3, m_y + 1);
			drawChar(buffer, bufferSize, 'x', m_x + 4, m_y + 1);
			drawChar(buffer, bufferSize, '\\', m_x + 5, m_y + 1);
			drawChar(buffer, bufferSize, ' ', m_x + 1, m_y + 2);
			drawChar(buffer, bufferSize, ')', m_x + 2, m_y + 2);
			drawChar(buffer, bufferSize, '~', m_x + 3, m_y + 2);
			drawChar(buffer, bufferSize, '(', m_x + 4, m_y + 2);
			drawChar(buffer, bufferSize, ' ', m_x + 5, m_y + 2);

			if (_animation_timer.getElapsedSeconds() >= 0.5)
				_taupe_state = HIDDEN;

			break;
	}
}

/*
Méthode qui permet de savoir si on a cliqué sur une taupe
*/
int Trou::hit(COORD clic) {
	//S'il n'y a pas de taupe
	if (_taupe_state == HIDDEN || _taupe_state == BAD_ANGRY || _taupe_state == NICE_SAD)
		return 0;

	//Si l'on clique dans le trou
	if (m_x < clic.X && clic.X < (m_x + largeur - 1) && m_y < clic.Y && clic.Y < (m_y + hauteur - 1)) {
		if (_taupe_state == BAD_OUT)
		{
			_taupe_state = BAD_ANGRY;
			_animation_timer.start();

			return 1;
		}
		else //[implicit =>]if (_taupe_state == NICE_OUT)
		{
			_taupe_state = NICE_SAD;
			_animation_timer.start();

			return -1;
		}
	}
	else {
		return 0;
	}
}

void Trou::spawnTaupe()
{
	_animation_timer.start();

	int isNice = rand() % 5 + 1;
	if (isNice == 1)
		_taupe_state = NICE_OUT;
	else
		_taupe_state = BAD_OUT;
}

/*
Destructeur
*/
Trou::~Trou()
{
}
