#pragma once

#include <Windows.h>

class Trou
{
private:
	/*
	Attribut m_taupe
	Définit si la taupe est sortie de sa tanière ou non
	*/
	bool m_taupe;

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
	void draw(CHAR_INFO* buffer, COORD bufferSize, char lettre) const;

	/*
	Méthode getTaupe
	Permet de savoir si la taupe est sortie de sa tanière ou non
	*/
	bool getTaupe() const { return this->m_taupe; }

	/*
	Méthode setTaupe
	Permet de configurer la sortie de la taupe
	*/
	void setTaupe(bool taupe) { this->m_taupe = taupe; }

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
	bool hit(COORD clic);

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

