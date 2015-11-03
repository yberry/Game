#pragma once

#include <vector>
#include "Trou.h"

class Map
{
private:
	std::vector<Trou*> map;

public:
	Map();
	bool estDisponible(int x, int y) const;
	void ajouterTrou(int x, int y);
	void draw(CHAR_INFO* buffer, COORD dwBufferSize) const;
	~Map();
};

