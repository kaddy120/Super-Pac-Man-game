#pragma once
#include "fruit.h"
#include "Door.h"
#include "Sprite.h"
#include "Door.h"
#include "Key.h"
#include <vector>
#include <iostream>
#include "CircleSprite.h"

//#include <memory>
using std::vector;

class GameMap
{
public:
	GameMap();
	std::vector<Sprite> GetWalls() const;
	vector<CircleSprite> GetTurningPoinints() const;

private:
	std::vector<std::vector<std::string> > Maize;
	void Map();
	std::vector<Sprite> Walls;
	std::vector<Door> Door;
	std::vector<Fruit> Fruite;
	std::vector<Key> Keys;
	vector<CircleSprite> TurningPoints;
};

