// Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include "GameManager.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	GameManager gManager = GameManager();
	
	gManager.init();
	gManager.gameLoop();
	
	return 0;
}















/*buffer[5][10].Char.AsciiChar = 'H';
buffer[5][10].Attributes = 0x0E;
buffer[5][11].Char.AsciiChar = 'i';
buffer[5][11].Attributes = 0x0B;
buffer[5][12].Char.AsciiChar = '!';
buffer[5][12].Attributes = 0x0A;
*/
