#include "stdafx.h"
#include "GameManager.h"


GameManager::GameManager():oManager()
{
	
}


GameManager::~GameManager()
{
}

void GameManager::init()
{
	oManager.init();

	map.ajouterTrou(20, 50);
	map.ajouterTrou(20, 100);
	map.ajouterTrou(40, 40);
	map.ajouterTrou(40, 75);
	map.ajouterTrou(40, 110);
	map.ajouterTrou(60, 50);
	map.ajouterTrou(60, 100);
}

void GameManager::gameLoop()
{
	while (!GetAsyncKeyState(VK_ESCAPE)) {
		oManager.read();
		
		map.updateTaupe();
		map.draw((CHAR_INFO *)oManager.buffer, oManager.dwBufferSize);

		oManager.draw();
	}
}
