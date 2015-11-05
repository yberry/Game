#include "stdafx.h"
#include "GameManager.h"
#include <string>

using namespace std;

GameManager::GameManager() :
oManager(),
joueur(),
_time()
{
	_time.start();
	srand((unsigned int)time(NULL));
}


GameManager::~GameManager()
{
}

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
}

void GameManager::gameLoop()
{
	while (!GetAsyncKeyState(VK_ESCAPE)) {
		oManager.read();

		map.updateTaupe();
		if (_time.getElapsedSeconds() >= freq_score) {
			temps--;
			score++;
			if (temps == 0) {
				return;
			}
			_time.start();
		}
		COORD clic = joueur.jouer();
		if (clic.X != -1 && clic.Y != -1) {
			if (map.hit(clic)) {
				temps += 3;
				/*if (temps > 10) {
					temps = 10;
				}*/
			}
		}
		showScore((CHAR_INFO *)oManager.buffer, oManager.dwBufferSize);
		map.draw((CHAR_INFO *)oManager.buffer, oManager.dwBufferSize);

		oManager.draw();
	}
}

void GameManager::showScore(CHAR_INFO *buffer, COORD dwBufferSize) {
	string tmp = to_string(temps);
	if (temps < 10) {
		tmp[1] = tmp[0];
		tmp[0] = '0';
	}

	int j, k;



	for (unsigned int i(0); i < 2; i++) {
		//Réinitialisation
		for (j = 0; j < 7; j++) {
			for (k = 0; k < 7; k++) {
				(buffer + 8 * i + j + k * dwBufferSize.X)->Char.AsciiChar = ' ';
			}
		}

		//Pour les deux chiffres du temps
		switch (tmp[i]) {
		case '0':
			for (j = 0; j < 3; j++) {
				switch (j) {
				case 0:
					for (k = 2; k < 5; k++) {
						(buffer + 8 * i + k)->Char.AsciiChar = '#';
						(buffer + 8 * i + k + 6 * dwBufferSize.X)->Char.AsciiChar = '#';
					}
					break;

				case 1:
					for (k = 0; k < 2; k++) {
						(buffer + 8 * i + 1 + 4 * k + dwBufferSize.X)->Char.AsciiChar = '#';
						(buffer + 8 * i + 1 + 4 * k + 5 * dwBufferSize.X)->Char.AsciiChar = '#';
					}
					break;

				case 2:
					for (k = 2; k < 5; k++) {
						(buffer + 8 * i + k * dwBufferSize.X)->Char.AsciiChar = '#';
						(buffer + 8 * i + 6 + k * dwBufferSize.X)->Char.AsciiChar = '#';
					}
					break;
				}
			}
			break;

		case '1':
			for (j = 0; j < 7; j++) {
				(buffer + 8 * i + 3 + j * dwBufferSize.X)->Char.AsciiChar = '#';
				(buffer + 8 * i + j + 6 * dwBufferSize.X)->Char.AsciiChar = '#';
			}
			(buffer + 8 * i + 2 + dwBufferSize.X)->Char.AsciiChar = '#';
			(buffer + 8 * i + 1 + 2 * dwBufferSize.X)->Char.AsciiChar = '#';
			break;

		case '2':
			for (j = 0; j < 3; j++) {
				for (k = 1; k < 6; k++) {
					(buffer + 8 * i + k + j * 3 * dwBufferSize.X)->Char.AsciiChar = '#';
				}
			}

			for (j = 1; j < 7; j++) {
				switch (j) {
				case 1:
				case 4:
				case 5:
				case 6:
					(buffer + 8 * i + j * dwBufferSize.X)->Char.AsciiChar = '#';
					break;
				}
			}

			for (j = 1; j < 7; j++) {
				switch (j) {
				case 1:
				case 2:
				case 6:
					(buffer + 8 * i + 6 + j * dwBufferSize.X)->Char.AsciiChar = '#';
					break;
				}
			}
			break;

		case '3':
			for (j = 0; j < 3; j++) {
				for (k = 1; k < 6; k++) {
					(buffer + 8 * i + k + j * 3 * dwBufferSize.X)->Char.AsciiChar = '#';
				}
			}

			for (j = 0; j < 2; j++) {
				(buffer + 8 * i + (4 * j + 1) * dwBufferSize.X)->Char.AsciiChar = '#';
			}

			for (j = 1; j < 6; j++) {
				if (j != 3) {
					(buffer + 8 * i + 6 + j * dwBufferSize.X)->Char.AsciiChar = '#';
				}
			}
			break;

		case '4':
			for (j = 0; j < 5; j++) {
				(buffer + 8 * i + j * dwBufferSize.X)->Char.AsciiChar = '#';
			}

			for (j = 1; j < 7; j++) {
				(buffer + 8 * i + 5 + j * dwBufferSize.X)->Char.AsciiChar = '#';
			}

			for (j = 0; j < 7; j++) {
				(buffer + 8 * i + j + 4 * dwBufferSize.X)->Char.AsciiChar = '#';
			}
			break;

		case '5':
			for (j = 0; j < 3; j++) {
				for (k = 1; k < 6; k++) {
					(buffer + 8 * i + k + j * 3 * dwBufferSize.X)->Char.AsciiChar = '#';
				}
			}

			for (j = 0; j < 6; j++) {
				if (j != 4) {
					(buffer + 8 * i + j * dwBufferSize.X)->Char.AsciiChar = '#';
				}
			}

			for (j = 0; j < 6; j++) {
				switch (j) {
				case 0:
				case 4:
				case 5:
					(buffer + 8 * i + 6 + j * dwBufferSize.X)->Char.AsciiChar = '#';
					break;
				}
			}
			break;

		case '6':
			for (j = 0; j < 3; j++) {
				for (k = 1; k < 6; k++) {
					(buffer + 8 * i + k + j * 3 * dwBufferSize.X)->Char.AsciiChar = '#';
				}
			}

			for (j = 1; j < 6; j++) {
				(buffer + 8 * i + j * dwBufferSize.X)->Char.AsciiChar = '#';
			}

			for (j = 1; j < 6; j++) {
				switch (j) {
				case 1:
				case 4:
				case 5:
					(buffer + 8 * i + 6 + j * dwBufferSize.X)->Char.AsciiChar = '#';
					break;
				}
			}
			break;

		case '7':
			for (j = 0; j < 7; j++) {
				(buffer + 8 * i + j)->Char.AsciiChar = '#';
			}
			(buffer + 8 * i + dwBufferSize.X)->Char.AsciiChar = '#';

			for (j = 0; j < 3; j++) {
				(buffer + 8 * i + 3 + j + (3 - j) * dwBufferSize.X)->Char.AsciiChar = '#';
			}

			for (j = 0; j < 3; j++) {
				(buffer + 8 * i + 2 + (4 + j) * dwBufferSize.X)->Char.AsciiChar = '#';
			}
			break;

		case '8':
			for (j = 0; j < 3; j++) {
				for (k = 1; k < 6; k++) {
					(buffer + 8 * i + k + j * 3 * dwBufferSize.X)->Char.AsciiChar = '#';
				}
			}

			for (j = 1; j < 6; j++) {
				if (j != 3) {
					for (k = 0; k < 2; k++) {
						(buffer + 8 * i + k * 6 + j * dwBufferSize.X)->Char.AsciiChar = '#';
					}
				}
			}

			break;

		case '9':
			for (j = 0; j < 3; j++) {
				for (k = 1; k < 6; k++) {
					(buffer + 8 * i + k + j * 3 * dwBufferSize.X)->Char.AsciiChar = '#';
				}
			}

			for (j = 1; j < 6; j++) {
				(buffer + 8 * i + 6 + j * dwBufferSize.X)->Char.AsciiChar = '#';
			}

			for (j = 1; j < 6; j++) {
				switch (j) {
				case 1:
				case 2:
				case 5:
					(buffer + 8 * i + j * dwBufferSize.X)->Char.AsciiChar = '#';
					break;
				}
			}
			break;

		}
	}
}
