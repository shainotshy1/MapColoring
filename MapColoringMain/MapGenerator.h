#pragma once
#include "MapShape.h"
#include <vector>

class MapShape; // predeclare

class MapGenerator
{
public:
	void generate(std::vector<MapShape*>&, int);
};

