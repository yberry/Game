#include "stdafx.h"
#include "GameManager.h"

GameManager::GameManager() :
oManager(),
joueur()
{

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
		COORD clic = joueur.jouer();
		if (clic.X != -1 && clic.Y != -1) {
			bool verif = map.hit(clic);
		}
		map.draw((CHAR_INFO *)oManager.buffer, oManager.dwBufferSize);

		oManager.draw();
	}
}
