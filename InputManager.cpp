/*
Fichier InputManager.cpp
Ce fichier contient le code des méthodes de la classe InputManager.
Auteurs : François Rivoire et Yanis Berry
*/


#include "stdafx.h"
#include "InputManager.h"


InputManager::InputManager(HANDLE hInput, int nbInputs) :_hInput(hInput), _nbDetectedInputs(0)
{
	_input_records.resize(nbInputs);
}


InputManager::~InputManager()
{
	_input_records.clear();
}

void InputManager::update()
{
	_nbDetectedInputs = 0;
	ReadConsoleInput(_hInput, &_input_records[0], _input_records.size(), &_nbDetectedInputs);
}

COORD InputManager::getMousePos()
{
	COORD errMousePos;
	errMousePos.X = errMousePos.Y = -1;

	if (_input_records[0].EventType != MOUSE_EVENT)
		return errMousePos;

	return _input_records[0].Event.MouseEvent.dwMousePosition;
}

int InputManager::isMouseLeftButtonPressed()
{
	if (_input_records[0].EventType != MOUSE_EVENT)
		return -1;

	if (_input_records[0].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		return 1;

	return 0;
}
