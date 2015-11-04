/*
Fichier InputManager.cpp
Ce fichier contient le code des méthodes de la classe InputManager.
Auteurs : François Rivoire et Yanis Berry
*/


#include "stdafx.h"
#include "InputManager.h"


InputManager::InputManager(int nbInputs) : _nbDetectedInputs(0)
{
	//Allocation du tableau de récupération des inputs :
	_hInput = (HANDLE)GetStdHandle(STD_INPUT_HANDLE);
	_input_records.resize(nbInputs);
}

InputManager::~InputManager()
{
	_input_records.clear();
}

void InputManager::update()
{
	_nbDetectedInputs = 0;

	//Récupération des inputs -> mise à jour de _input_records et _nbDetectedInputs
	ReadConsoleInput(_hInput, &_input_records[0], _input_records.size(), &_nbDetectedInputs);
}

COORD InputManager::getMousePos()
{
	COORD errMousePos;
	errMousePos.X = errMousePos.Y = -1;

	//Si le premier input détecté n'est pas un input de souris, on a un erreur.
	if (_input_records[0].EventType != MOUSE_EVENT)
		return errMousePos;

	return _input_records[0].Event.MouseEvent.dwMousePosition;
}

int InputManager::isMouseLeftButtonPressed()
{
	//Si le premier input détecté n'est pas un input de souris, on a un erreur.
	if (_input_records[0].EventType != MOUSE_EVENT)
		return -1;

	//Si le boutton gauche est enfoncé, on renvoie 1
	if (_input_records[0].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		return 1;

	//Sinon 0
	return 0;
}
