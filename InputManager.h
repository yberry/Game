/*
Fichier InputManager.h
Ce fichier définit la classe InputManager
Auteurs : François Rivoire et Yanis Berry
*/

//////////////////////////////
/*
Classe InputManager
Cette classe permet de gérer les inputs utilisateurs dans une application console Windows.
Remarque : Cette classe s'appuie sur l'API standard de Windows pour les consoles.
*/
#pragma once

#include <vector>
#include <Windows.h>

class InputManager
{
private :
	/*
	Attribut _hInput
	Cet attribut définit la sortie dont on analyse les inputs.
	*/
	HANDLE _hInput;

	/*
	Attribut _input_records
	Cet attribut permet de stocker les inputs à un instant donné.
	*/
	std::vector<INPUT_RECORD> _input_records;

	/*
	Attribut _nbDetectedInputs
	Cet attribut permet de récupérer le nombre d'inputs détectés à un instant donné.
	*/
	DWORD _nbDetectedInputs;

public:
	/*
	Argument nbInputs : Définit le nombre d'inputs que l'on peut gérer à un instant donné.
	*/
	InputManager(HANDLE hInput, int nbInputs);
	~InputManager();

	/*
	Méthode update
	Permet de mettre à jour les structures de données pour récupérer les derniers inputs utilisateur.
	Remarque : à appeler avant d'analyser les inputs.
	*/
	void update();	

	/*
	Méthode getMousePos
	Permet de récupérer la position de la souris dans le système de coordonnées de la grille de la console.
	Remarque : Renvoie (-1, -1) en cas d'erreur (souris non détectée).
	*/
	COORD getMousePos();

	/*
	Méthode isMouseLeftButtonPressed
	Permet de déterminer si le bouton gauche de la souris est enfoncé.
	Renvoie -1 en cas d'erreur, 0 si le bouton n'est pas appuyé, 1 s'il l'est.
	*/
	int isMouseLeftButtonPressed();
};

