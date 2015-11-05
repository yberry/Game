#include "stdafx.h"
#include "GameManager.h"
#include <time.h>
#include <string>
#include <iostream>

using namespace std;

/*
Constructeur
*/
GameManager::GameManager() :
oManager(),
joueur(),
_time()
{
	_time.start();
}

/*
Destructeur
*/
GameManager::~GameManager()
{
}

/*
Méthode qui sert à créer les trous
*/
void GameManager::init()
{
	oManager.init();

	map.ajouterTrou(50, 20);
	map.ajouterTrou(100, 20);
	map.ajouterTrou(40, 40);
	map.ajouterTrou(75, 40);
	map.ajouterTrou(110, 40);
	map.ajouterTrou(50, 60);
	map.ajouterTrou(100, 60);

	srand((unsigned int)(time(NULL)));
}

/*
Méthode générale qui gère la boucle du jeu : gère le temps, le score, l'affichage et la fin du jeu
*/
void GameManager::gameLoop()
{
	//Le temps n'est pas écoulé au début
	bool ecoule(false);

	//Rien n'a été cliqué
	int hit_result(0);

	//Tant que le joueur n'a pas appuyé sur ECHAP
	while (!GetAsyncKeyState(VK_ESCAPE)) {

		//Si le temps n'est pas écoulé
		if (!ecoule) {

			oManager.read();
			//On actualise la statut des taupes
			map.updateTaupe();

			//Au bout d'une seconde
			if (_time.getElapsedSeconds() >= freq_score) {
				//On enlève 1 seconde
				temps--;
				//Et on ajoute un point au score
				score++;
				//Si le temps atteint 0, on arrête tout
				if (temps == 0) {
					ecoule = true;
				}
				//On relance 1 seconde
				_time.start();
			}

			//Lorsque le joueur clique, on récupère les coordonnées
			COORD clic = joueur.jouer();
			//Si le clic est bien dans la fenêtre
			if (clic.X != -1 && clic.Y != -1) {
				//On récupère le résultat du clic
				hit_result = map.hit(clic);
				//Si on a touché une taupe méchante
				if (hit_result == 1) {
					//On récupère 2 secondes 
					temps += 2;
					//On ne peut pas dépasser 10 secondes
					if (temps > 10) {
						temps = 10;
					}
				}
				//Si on a touché une taupe gentille
				else if (hit_result == -1)
				{
					//On perd 2 secondes
					temps -= 2;
					//Si on atteint directement 0 seconde, on arrête tout
					if (temps < 0) {
						temps = 0;
						ecoule = true;
					}
				}
			}
			//On affiche le temps restant
			showTime((CHAR_INFO *)oManager.buffer, oManager.dwBufferSize, 130, 40);
			//On affiche les trous
			map.draw((CHAR_INFO *)oManager.buffer, oManager.dwBufferSize);
			//On affiche le marteau
			joueur.draw((CHAR_INFO *)oManager.buffer, oManager.dwBufferSize);
		}
		//Si le temps est écoulé
		else {
			//On affiche le score final
			endGame((CHAR_INFO *)oManager.buffer, oManager.dwBufferSize);
		}
		//Affichage général
		oManager.draw();
	}
}

/*
Méthode qui gère l'affichage du temps
*/
void GameManager::showTime(CHAR_INFO *buffer, COORD dwBufferSize, int x, int y) const {
	string tmp = to_string(temps);
	//Si le temps est inférieur à 10 on met un 0 devant
	if (temps < 10) {
		tmp[1] = tmp[0];
		tmp[0] = '0';
	}

	int j, k;

	//Pour les deux chiffres
	for (int i(0); i < 2; i++) {
		//Réinitialisation de l'affichage
		for (j = 0; j < 7; j++) {
			for (k = 0; k < 7; k++) {
				(buffer + x + 8 * i + j + (k + y) * dwBufferSize.X)->Char.AsciiChar = ' ';
			}
		}

		//Changement de design selon chaque chiffre
		switch (tmp[i]) {
		case '0':
			for (j = 0; j < 3; j++) {
				switch (j) {
				case 0:
					for (k = 2; k < 5; k++) {
						(buffer + x + 8 * i + k + y * dwBufferSize.X)->Char.AsciiChar = '#';
						(buffer + x + 8 * i + k + (6 + y) * dwBufferSize.X)->Char.AsciiChar = '#';
					}
					break;

				case 1:
					for (k = 0; k < 2; k++) {
						(buffer + x + 8 * i + 1 + 4 * k + (1 + y) * dwBufferSize.X)->Char.AsciiChar = '#';
						(buffer + x + 8 * i + 1 + 4 * k + (5 + y) * dwBufferSize.X)->Char.AsciiChar = '#';
					}
					break;

				case 2:
					for (k = 2; k < 5; k++) {
						(buffer + x + 8 * i + (k + y) * dwBufferSize.X)->Char.AsciiChar = '#';
						(buffer + x + 8 * i + 6 + (k + y) * dwBufferSize.X)->Char.AsciiChar = '#';
					}
					break;
				}
			}
			break;

		case '1':
			for (j = 0; j < 7; j++) {
				(buffer + x + 8 * i + 3 + (j + y) * dwBufferSize.X)->Char.AsciiChar = '#';
				(buffer + x + 8 * i + j + (6 + y) * dwBufferSize.X)->Char.AsciiChar = '#';
			}
			(buffer + x + 8 * i + 2 + (1 + y) * dwBufferSize.X)->Char.AsciiChar = '#';
			(buffer + x + 8 * i + 1 + (2 + y) * dwBufferSize.X)->Char.AsciiChar = '#';
			break;

		case '2':
			for (j = 0; j < 3; j++) {
				for (k = 1; k < 6; k++) {
					(buffer + x + 8 * i + k + (j * 3 + y) * dwBufferSize.X)->Char.AsciiChar = '#';
				}
			}

			for (j = 1; j < 7; j++) {
				switch (j) {
				case 1:
				case 4:
				case 5:
				case 6:
					(buffer + x + 8 * i + (j + y) * dwBufferSize.X)->Char.AsciiChar = '#';
					break;
				}
			}

			for (j = 1; j < 7; j++) {
				switch (j) {
				case 1:
				case 2:
				case 6:
					(buffer + x + 8 * i + 6 + (j + y) * dwBufferSize.X)->Char.AsciiChar = '#';
					break;
				}
			}
			break;

		case '3':
			for (j = 0; j < 3; j++) {
				for (k = 1; k < 6; k++) {
					(buffer + x + 8 * i + k + (j * 3 + y) * dwBufferSize.X)->Char.AsciiChar = '#';
				}
			}

			for (j = 0; j < 2; j++) {
				(buffer + x + 8 * i + (4 * j + 1 + y) * dwBufferSize.X)->Char.AsciiChar = '#';
			}

			for (j = 1; j < 6; j++) {
				if (j != 3) {
					(buffer + x + 8 * i + 6 + (j + y) * dwBufferSize.X)->Char.AsciiChar = '#';
				}
			}
			break;

		case '4':
			for (j = 0; j < 5; j++) {
				(buffer + x + 8 * i + (j + y) * dwBufferSize.X)->Char.AsciiChar = '#';
			}

			for (j = 1; j < 7; j++) {
				(buffer + x + 8 * i + 5 + (j + y) * dwBufferSize.X)->Char.AsciiChar = '#';
			}

			for (j = 0; j < 7; j++) {
				(buffer + x + 8 * i + j + (4 + y) * dwBufferSize.X)->Char.AsciiChar = '#';
			}
			break;

		case '5':
			for (j = 0; j < 3; j++) {
				for (k = 1; k < 6; k++) {
					(buffer + x + 8 * i + k + (j * 3 + y) * dwBufferSize.X)->Char.AsciiChar = '#';
				}
			}

			for (j = 0; j < 6; j++) {
				if (j != 4) {
					(buffer + x + 8 * i + (j + y) * dwBufferSize.X)->Char.AsciiChar = '#';
				}
			}

			for (j = 0; j < 6; j++) {
				switch (j) {
				case 0:
				case 4:
				case 5:
					(buffer + x + 8 * i + 6 + (j + y) * dwBufferSize.X)->Char.AsciiChar = '#';
					break;
				}
			}
			break;

		case '6':
			for (j = 0; j < 3; j++) {
				for (k = 1; k < 6; k++) {
					(buffer + x + 8 * i + k + (j * 3 + y) * dwBufferSize.X)->Char.AsciiChar = '#';
				}
			}

			for (j = 1; j < 6; j++) {
				(buffer + x + 8 * i + (j + y) * dwBufferSize.X)->Char.AsciiChar = '#';
			}

			for (j = 1; j < 6; j++) {
				switch (j) {
				case 1:
				case 4:
				case 5:
					(buffer + x + 8 * i + 6 + (j + y) * dwBufferSize.X)->Char.AsciiChar = '#';
					break;
				}
			}
			break;

		case '7':
			for (j = 0; j < 7; j++) {
				(buffer + x + 8 * i + j + y * dwBufferSize.X)->Char.AsciiChar = '#';
			}
			(buffer + x + 8 * i + (1 + y) * dwBufferSize.X)->Char.AsciiChar = '#';

			for (j = 0; j < 3; j++) {
				(buffer + x + 8 * i + 3 + j + (3 - j + y) * dwBufferSize.X)->Char.AsciiChar = '#';
			}

			for (j = 0; j < 3; j++) {
				(buffer + x + 8 * i + 2 + (4 + j + y) * dwBufferSize.X)->Char.AsciiChar = '#';
			}
			break;

		case '8':
			for (j = 0; j < 3; j++) {
				for (k = 1; k < 6; k++) {
					(buffer + x + 8 * i + k + (j * 3 + y) * dwBufferSize.X)->Char.AsciiChar = '#';
				}
			}

			for (j = 1; j < 6; j++) {
				if (j != 3) {
					for (k = 0; k < 2; k++) {
						(buffer + x + 8 * i + k * 6 + (j + y) * dwBufferSize.X)->Char.AsciiChar = '#';
					}
				}
			}

			break;

		case '9':
			for (j = 0; j < 3; j++) {
				for (k = 1; k < 6; k++) {
					(buffer + x + 8 * i + k + (j * 3 + y) * dwBufferSize.X)->Char.AsciiChar = '#';
				}
			}

			for (j = 1; j < 6; j++) {
				(buffer + x + 8 * i + 6 + (j + y) * dwBufferSize.X)->Char.AsciiChar = '#';
			}

			for (j = 1; j < 6; j++) {
				switch (j) {
				case 1:
				case 2:
				case 5:
					(buffer + x + 8 * i + (j + y) * dwBufferSize.X)->Char.AsciiChar = '#';
					break;
				}
			}
			break;

		}
	}
}

/*
Méthode qui efface l'affichage et révèle le score du joueur
*/
void GameManager::endGame(CHAR_INFO *buffer, COORD dwBufferSize) const {
	for (int i(0); i < dwBufferSize.X; i++) {
		for (int j(0); j < dwBufferSize.Y; j++) {
			(buffer + i + j * dwBufferSize.X)->Char.AsciiChar = ' ';
		}
	}
	string message = "Vous avez tenu " + to_string(score) + " secondes !";
	for (unsigned int j(0); j < message.length(); j++) {
		(buffer + j)->Char.AsciiChar = message[j];
	}
}
