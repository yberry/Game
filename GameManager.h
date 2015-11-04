#pragma once
#include <Windows.h>
#include "Map.h"
#include "OutputManager.h"

class GameManager
{
private :
	OutputManager oManager;
	Map map;

public:
	GameManager();
	~GameManager();

	void init();
	void gameLoop();
};

