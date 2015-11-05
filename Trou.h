#pragma once

#include <Windows.h>
#include "Timer.h"

enum TaupeStates
{
	HIDDEN,
	BAD_OUT,
	BAD_ANGRY,
	NICE_OUT,
	NICE_SAD
};

class Trou
{
private:
	/*
	Attribut m_taupe
	Définit l'état de la taupe du trou :
	0 = cachée
	1 = taupe sortie
	2 = taupe en colère
	3 = taupe gentille sortie
	4 = taupe gentille triste
	*/
	TaupeStates _taupe_state;

	/*
	Attribut _animation_timer
	Permet de mesurer le défilement du temps pour animer la taupe.
	*/
	Timer _animation_timer;

	/*
	Attribut m_x
	Numéro de la colonne sur laquelle se situe le coin haut gauche du trou
	*/
	int m_x;

	/*
	Attribut m_y
	Numéro de la ligne sur laquelle se situe le coin haut gauche du trou
	*/
	int m_y;

	/*
	Attribut de classe largeur
	Définit la largeur d'un trou
	*/
	static int largeur;

	/*
	Attribut de classe largeur
	Définit la hauteur d'un trou
	*/
	static int hauteur;

public:
	/*
	Constructeur Trou
	x et y sont les coordonnées du coin haut gauche du trou
	*/
	Trou(int x, int y);

	/*
	Méthode draw
	Permet d'afficher le trou à l'écran en utilisant un certain caractère
	*/
	void draw(CHAR_INFO* buffer, COORD bufferSize, char lettre);

	/*
	Méthode getTaupe
	Permet de savoir si la taupe est sortie de sa tanière ou non
	*/
	bool isOccupied() const { return (!_taupe_state == HIDDEN); }

	/*
	Méthode spawnTaupe
	Permet de faire apparaître une taupe dans le trou
	*/
	void spawnTaupe();

	/*
	Méthode hideTaupe
	Permet de faire rentrer la taupe dans le trou
	*/
	void hideTaupe() { _taupe_state = HIDDEN; }

	/*
	Méthode getX
	Permet de connaître la colonne du coin haut gauche du trou
	*/
	int getX() const { return this->m_x; }

	/*
	Méthode getY
	Permet de connaître la ligne du coin haut gauche du trou
	*/
	int getY() const { return this->m_y; }

	/*
	Méthode hit
	Permet de savoir si on a cliqué sur une taupe
	*/
	int hit(COORD clic);

	/*
	Méthode de classe getLargeur
	Permet de connaître la largeur d'un trou
	*/
	static int getLargeur() { return largeur; }

	/*
	Méthode de classe getHauteur
	Permet de connaître la hauteur d'un trou
	*/
	static int getHauteur() { return hauteur; }

	/*
	Destructeur
	*/
	~Trou();
};

